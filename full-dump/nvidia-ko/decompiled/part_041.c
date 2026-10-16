// ===== 00478dc0 clPcieReadDword_IMPL =====

ulong clPcieReadDword_IMPL
                (long param_1,undefined4 param_2,undefined1 param_3,byte param_4,byte param_5,
                uint param_6)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar3 = sysGetOs_IMPL(g_pSys);
  if ((ulong)param_6 + 4 < 0x1001) {
    if (param_4 < 0x20) {
      if (7 < param_5) {
LAB_00478f50:
        nvAssertFailedNoLog("func < PCI_MAX_FUNCTIONS","src/kernel/platform/chipset/chipset_pcie.c",
                            0xc48);
        goto LAB_00478f70;
      }
      if (*(char *)(param_1 + 0x48) == '\0') goto LAB_00478eef;
    }
    else {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc47);
      if (7 < param_5) goto LAB_00478f50;
LAB_00478f70:
      if ((*(char *)(param_1 + 0x48) == '\0') || (0x1000 < (ulong)param_6 + 4)) goto LAB_00478eef;
    }
    lVar4 = osPciInitHandle(param_2,param_3,param_4,param_5,0,0);
    if ((lVar4 != 0) && (cVar2 = osTestPcieExtendedConfigAccess(lVar4,param_6), cVar2 != '\0')) {
      uVar5 = osPciReadDword(lVar4,param_6);
      return uVar5;
    }
    if (*(char *)(lVar3 + 0x4d) == '\0') {
      lVar3 = objClPcieMapEnhCfgSpace(param_1,param_2,param_3,param_4,param_5);
      if (lVar3 != 0) {
        uVar1 = *(uint *)(lVar3 + (ulong)(param_6 & 0xfffffffc));
        objClPcieUnmapEnhCfgSpace_isra_0();
        return (ulong)uVar1;
      }
    }
    else {
      nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)",
                          "src/kernel/platform/chipset/chipset_pcie.c",0xc58);
    }
  }
  else {
    nvAssertFailedNoLog("offset + sizeof(value) <= 0x1000",
                        "src/kernel/platform/chipset/chipset_pcie.c",0xc46);
    if (0x1f < param_4) {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc47);
    }
    if (7 < param_5) goto LAB_00478f50;
LAB_00478eef:
    nvAssertFailedNoLog("clPcieReadDword() failed!","src/kernel/platform/chipset/chipset_pcie.c",
                        0xc4d);
  }
  return 0;
}


// ===== 00479000 objClSetPortPcieEnhancedCapsOffsets.part.0 =====

undefined8 objClSetPortPcieEnhancedCapsOffsets_part_0(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0x100;
  do {
    uVar1 = clPcieReadDword_IMPL
                      (param_1,*param_2,*(undefined1 *)(param_2 + 1),
                       *(undefined1 *)((long)param_2 + 5),*(undefined1 *)((long)param_2 + 6),uVar3);
    uVar2 = uVar1 & 0xffff;
    if (uVar2 == 0xd) {
      param_2[10] = uVar3;
    }
    else if (uVar2 < 0xe) {
      if (uVar2 == 1) {
        param_2[7] = uVar3;
      }
      else if (uVar2 == 2) {
        param_2[8] = uVar3;
      }
    }
    else if (uVar2 == 0x1e) {
      param_2[9] = uVar3;
    }
    uVar3 = uVar1 >> 0x14;
  } while (uVar3 != 0);
  return 0;
}


// ===== 004790a0 objClSetPortCapsOffsets.isra.0 =====

void objClSetPortCapsOffsets_isra_0(long param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iVar1 = clSetPortPcieCapOffset_IMPL(param_1,*(undefined8 *)(param_2 + 8),param_2 + 0x18);
  if (iVar1 == 0) {
    if ((*(char *)(param_1 + 0x48) != '\0') && (*(char *)(param_2 + 7) != '\0')) {
      objClSetPortPcieEnhancedCapsOffsets_part_0(param_1,param_2);
      return;
    }
    uVar4 = 0x687;
    uVar3 = 0x40;
    pcVar2 = "objClSetPortPcieEnhancedCapsOffsets(pCl, pPort)";
  }
  else {
    uVar4 = 0x684;
    uVar3 = 0xffff;
    pcVar2 = "clSetPortPcieCapOffset(pCl, pPort->addr.handle, &pPort->PCIECapPtr)";
  }
  nvCheckOkFailedNoLog(1,uVar3,pcVar2,"src/kernel/platform/chipset/chipset_pcie.c",uVar4);
  return;
}


// ===== 00479130 objClInitGpuPortData.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 objClInitGpuPortData_part_0(long param_1,long param_2)

{
  undefined8 uVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  short sVar10;
  bool bVar11;
  byte local_4a;
  undefined1 local_49;
  undefined1 local_48;
  byte local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined2 local_44;
  short local_42;
  undefined2 local_40;
  short local_3e;
  undefined4 local_3c [3];
  
  if (*(char *)(param_1 + 0x880) == '\0') {
    nvAssertFailedNoLog("gpuIsDBDFValid(pGpu)","src/kernel/platform/chipset/chipset_pcie.c",0x4b4);
  }
  uVar9 = *(ulong *)(param_1 + 0x878);
  uVar5 = (undefined4)(uVar9 >> 0x20);
  lVar8 = clFindP2PBrdg_IMPL(param_2,uVar9 >> 0x20,uVar9 >> 8 & 0xff,&local_4a,&local_49,&local_48,
                             &local_44,&local_42);
  if (lVar8 == 0) {
    lVar8 = *(long *)(g_pSys + 0x238);
    *(undefined8 *)(param_1 + 0x1d60) = 0;
    *(undefined8 *)(param_1 + 0x1d58) = 0x100000000000000;
    *(undefined4 *)(param_1 + 0x1d84) = 0xffffffff;
    iVar6 = (**(code **)(param_1 + 0x168))(param_1);
    if (iVar6 != 4) {
      if (lVar8 == 0) {
        return 0;
      }
      if (*(char *)(lVar8 + 0x49) == '\0') {
        return 0;
      }
    }
  }
  else {
    *(long *)(param_1 + 0x1d60) = lVar8;
    *(byte *)(param_1 + 0x1d5c) = local_4a;
    *(undefined4 *)(param_1 + 0x1d58) = uVar5;
    *(undefined1 *)(param_1 + 0x1d5d) = local_49;
    *(undefined1 *)(param_1 + 0x1d5f) = 1;
    *(undefined1 *)(param_1 + 0x1d5e) = local_48;
    *(uint *)(param_1 + 0x1d84) = CONCAT22(local_44,local_42);
    objClSetPortCapsOffsets_isra_0(param_2,param_1 + 0x1d58);
  }
  uVar7 = 0;
  uVar9 = uVar9 >> 8 & 0xffffffff;
  do {
    lVar8 = clFindP2PBrdg_IMPL(param_2,uVar5,uVar9 & 0xff,&local_47,&local_46,&local_45);
    if (lVar8 == 0) {
      *(undefined4 *)(param_1 + 0x1db4) = 0xffffffff;
      goto LAB_00479298;
    }
    iVar6 = clSetPortPcieCapOffset_IMPL(param_2,lVar8,local_3c);
    bVar2 = local_47;
    uVar9 = (ulong)local_47;
    if (iVar6 == 0) {
      uVar7 = osPciReadDword(lVar8,local_3c[0]);
    }
  } while ((uVar7 & 0xf00000) != 0x400000);
  local_4a = bVar2;
  local_44 = local_40;
  local_42 = local_3e;
  *(undefined4 *)(param_1 + 0x1d88) = uVar5;
  *(undefined1 *)(param_1 + 0x1d8d) = local_46;
  *(byte *)(param_1 + 0x1d8c) = bVar2;
  *(undefined1 *)(param_1 + 0x1d8e) = local_45;
  *(undefined1 *)(param_1 + 0x1d8f) = 1;
  *(long *)(param_1 + 0x1d90) = lVar8;
  *(uint *)(param_1 + 0x1db4) = CONCAT22(local_40,local_3e);
  local_49 = local_46;
  local_48 = local_45;
  objClSetPortCapsOffsets_isra_0(param_2,param_1 + 0x1d88);
LAB_00479298:
  iVar6 = (**(code **)(param_1 + 0x168))(param_1);
  if (iVar6 == 3) {
    bVar11 = false;
    if (*(char *)(param_1 + 0x1d5f) != '\0') {
      lVar8 = clFindP2PBrdg_IMPL(param_2,*(ulong *)(param_1 + 0x878) >> 0x20,
                                 *(ulong *)(param_1 + 0x878) >> 8 & 0xff,&local_40,&local_40,
                                 &local_40,&local_3e,local_3c);
      if ((lVar8 == 0) || (local_3e != 0x10de)) goto LAB_00479300;
      bVar11 = (ushort)local_3c[0] == 0x1b3;
    }
  }
  else {
LAB_00479300:
    bVar11 = false;
  }
  *(bool *)(param_1 + 0x477) = bVar11;
  iVar6 = (**(code **)(param_1 + 0x168))(param_1);
  if (iVar6 == 3) {
    bVar11 = false;
    if (*(char *)(param_1 + 0x1d5f) != '\0') {
      lVar8 = clFindP2PBrdg_IMPL(param_2,*(ulong *)(param_1 + 0x878) >> 0x20,
                                 *(ulong *)(param_1 + 0x878) >> 8 & 0xff,&local_40,&local_40,
                                 &local_40,&local_3e,local_3c);
      if ((lVar8 == 0) || (local_3e != 0x10de)) goto LAB_00479378;
      bVar11 = (ushort)local_3c[0] >> 4 == 0x5b;
    }
  }
  else {
LAB_00479378:
    bVar11 = false;
  }
  *(bool *)(param_1 + 0x478) = bVar11;
  uVar1 = *(undefined8 *)(param_1 + 0x878);
  lVar8 = clFindBrdgUpstreamPort_IMPL
                    (param_1,param_2,0,&local_4a,&local_49,&local_48,&local_44,&local_42,0);
  if (lVar8 == 0) {
    if ((*(char *)(param_1 + 0x477) != '\0') || (*(char *)(param_1 + 0x478) != '\0')) {
      *(undefined4 *)(param_1 + 0x1e14) = 0xffffffff;
      return 0;
    }
  }
  else {
    *(long *)(param_1 + 0x1df0) = lVar8;
    *(int *)(param_1 + 0x1de8) = (int)((ulong)uVar1 >> 0x20);
    *(byte *)(param_1 + 0x1dec) = local_4a;
    *(undefined1 *)(param_1 + 0x1def) = 1;
    *(undefined1 *)(param_1 + 0x1ded) = local_49;
    *(undefined1 *)(param_1 + 0x1dee) = local_48;
    *(uint *)(param_1 + 0x1e14) = CONCAT22(local_44,local_42);
    objClSetPortCapsOffsets_isra_0(param_2,param_1 + 0x1de8);
  }
  uVar1 = *(undefined8 *)(param_1 + 0x878);
  lVar8 = clFindBrdgUpstreamPort_IMPL
                    (param_1,param_2,1,&local_4a,&local_49,&local_48,&local_44,&local_42,0);
  if (lVar8 == 0) {
    if (*(char *)(param_1 + 0x477) != '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x478) != '\0') {
      return 0;
    }
    *(undefined8 *)(param_1 + 0x1dc0) = *(undefined8 *)(param_1 + 0x1d60);
    *(undefined8 *)(param_1 + 0x1db8) = *(undefined8 *)(param_1 + 0x1d58);
    *(undefined4 *)(param_1 + 0x1de4) = *(undefined4 *)(param_1 + 0x1d84);
    *(undefined8 *)(param_1 + 0x1dd0) = *(undefined8 *)(param_1 + 0x1d70);
    *(undefined8 *)(param_1 + 0x1dd8) = *(undefined8 *)(param_1 + 0x1d78);
  }
  else {
    *(long *)(param_1 + 0x1dc0) = lVar8;
    *(int *)(param_1 + 0x1db8) = (int)((ulong)uVar1 >> 0x20);
    *(byte *)(param_1 + 0x1dbc) = local_4a;
    *(undefined1 *)(param_1 + 0x1dbf) = 1;
    *(undefined1 *)(param_1 + 0x1dbd) = local_49;
    *(undefined1 *)(param_1 + 0x1dbe) = local_48;
    *(uint *)(param_1 + 0x1de4) = CONCAT22(local_44,local_42);
    objClSetPortCapsOffsets_isra_0(param_2,param_1 + 0x1db8);
  }
  objClSetPcieHWBC(param_1,param_2);
  cVar3 = *(char *)(param_1 + 0x1d8f);
  if ((cVar3 == '\0') || (*(char *)(param_1 + 0x1d5f) == '\0')) {
    if (*(char *)(param_1 + 0x479) == '\0') goto LAB_0047958e;
    if (*(char *)(param_1 + 0x1d5f) != '\0') goto LAB_004794ff;
    if (*(char *)(param_1 + 0x47d) != '\0') {
      return 1;
    }
LAB_00479794:
    if (cVar3 == '\0') {
      return 1;
    }
    sVar4 = *(short *)(param_1 + 0x1db6);
    sVar10 = *(short *)(param_1 + 0x1db4);
  }
  else {
    if ((((*(int *)(param_1 + 0x1d88) == *(int *)(param_1 + 0x1d58)) &&
         (*(char *)(param_1 + 0x1d8c) == *(char *)(param_1 + 0x1d5c))) &&
        (*(char *)(param_1 + 0x1d8d) == *(char *)(param_1 + 0x1d5d))) &&
       (*(char *)(param_1 + 0x1d8e) == *(char *)(param_1 + 0x1d5e))) {
      if (*(char *)(param_1 + 0x479) != '\0') goto LAB_004794ff;
      if (*(char *)(param_1 + 0x47d) != '\0') {
        return 1;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x479) = 1;
LAB_004794ff:
      iVar6 = (**(code **)(param_1 + 0x168))(param_1);
      if (((iVar6 != 3) || (*(char *)(param_1 + 0x1d5f) == '\0')) ||
         (*(int *)(param_1 + 0x1d70) == 0)) {
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x56d,"objClInitGpuPortData",4,
                     "NVRM: Error reading pcie link control status of upstream port\n");
        *(undefined2 *)(param_1 + 0x47c) = 0x101;
        return 1;
      }
      uVar9 = osPciReadDword(*(undefined8 *)(param_1 + 0x1d60),*(int *)(param_1 + 0x1d70) + 0xc);
      if ((uVar9 & 0x400) == 0) {
        *(undefined1 *)(param_1 + 0x47c) = 1;
      }
      if ((uVar9 & 0x800) == 0) {
        *(undefined1 *)(param_1 + 0x47d) = 1;
        return 1;
      }
LAB_0047958e:
      if (*(char *)(param_1 + 0x47d) != '\0') {
        return 1;
      }
      if (*(char *)(param_1 + 0x1d5f) == '\0') {
        cVar3 = *(char *)(param_1 + 0x1d8f);
        goto LAB_00479794;
      }
    }
    sVar4 = *(short *)(param_1 + 0x1d86);
    sVar10 = *(short *)(param_1 + 0x1d84);
  }
  if (sVar4 == -0x7f7a) {
    if (sVar10 == -0x2ec8) {
      if (*(char *)(param_2 + 0x5e) != '\0') {
        return 1;
      }
    }
    else if (sVar10 != -0x2ec6) {
      return 1;
    }
    *(undefined1 *)(param_1 + 0x47e) = 1;
  }
  return 1;
}


// ===== 004798a0 clPcieReadPortConfigReg_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
clPcieReadPortConfigReg_IMPL
          (long param_1,long param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (**(code **)(param_1 + 0x168))();
  if (iVar2 != 3) {
    return 0xffff;
  }
  if (*(char *)((long)param_3 + 7) == '\0') {
    return 0xffff;
  }
  if (param_4 - 0x100 < 0x2d) {
    if (param_3[6] == 0) {
      return 0xffff;
    }
    uVar3 = osPciReadDword(*(undefined8 *)(param_3 + 2),(param_4 - 0x100) + param_3[6]);
    *param_5 = uVar3;
    return 0;
  }
  uVar3 = param_4 - 0x200;
  if (uVar3 < 0x35) {
    if (*(char *)(param_2 + 0x48) == '\0') {
      return 0xffff;
    }
    iVar2 = param_3[7];
  }
  else {
    uVar3 = param_4 - 0x300;
    if (uVar3 < 0x1d) {
      if (*(char *)(param_2 + 0x48) == '\0') {
        return 0xffff;
      }
      iVar2 = param_3[8];
    }
    else {
      uVar3 = param_4 - 0x400;
      if (0xc < uVar3) {
        uVar3 = param_4 - 0x500;
        if (8 < uVar3) {
          if (0x40 < (ulong)param_4 + 4) {
            return 0xffff;
          }
          uVar3 = osPciReadDword(*(undefined8 *)(param_3 + 2),(ulong)param_4);
          *param_5 = uVar3;
          return 0;
        }
        if (*(char *)(param_2 + 0x48) == '\0') {
          return 0xffff;
        }
        iVar2 = param_3[10];
        if (iVar2 == 0) {
          return 0xffff;
        }
        if (param_4 == 0x506) {
LAB_004799c5:
          uVar1 = clPcieReadWord_IMPL(param_2,*param_3,*(undefined1 *)(param_3 + 1),
                                      *(undefined1 *)((long)param_3 + 5),
                                      *(undefined1 *)((long)param_3 + 6),uVar3 + iVar2);
          *param_5 = (uint)uVar1;
          return 0;
        }
        if (param_4 < 0x507) {
          if (param_4 != 0x500) {
            if (param_4 != 0x504) {
              return 0;
            }
            goto LAB_004799c5;
          }
        }
        else if (param_4 != 0x508) {
          return 0;
        }
        goto LAB_0047994e;
      }
      if (*(char *)(param_2 + 0x48) == '\0') {
        return 0xffff;
      }
      iVar2 = param_3[9];
    }
  }
  if (iVar2 == 0) {
    return 0xffff;
  }
LAB_0047994e:
  uVar3 = clPcieReadDword_IMPL
                    (param_2,*param_3,*(undefined1 *)(param_3 + 1),
                     *(undefined1 *)((long)param_3 + 5),*(undefined1 *)((long)param_3 + 6),
                     uVar3 + iVar2);
  *param_5 = uVar3;
  return 0;
}


// ===== 00479a50 _objClAdjustTcVcMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _objClAdjustTcVcMap(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_2c [3];
  
  iVar1 = (**(code **)(param_1 + 0x168))();
  if ((((iVar1 == 3) && (*(char *)((long)param_3 + 7) != '\0')) &&
      (*(char *)(param_2 + 0x48) != '\0')) && (param_3[8] != 0)) {
    uVar2 = clPcieReadDword_IMPL(param_2);
    iVar1 = (**(code **)(param_1 + 0x178))(param_1,0x114,local_2c);
    if (iVar1 == 0) {
      uVar3 = local_2c[0] >> 1 & 0x7f;
      uVar4 = uVar2 >> 1 & uVar3;
      if (uVar3 != uVar4) {
        uVar4 = uVar4 * 2;
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x356,"_objClAdjustTcVcMap",1,
                     "NVRM: NVPCIE: TC/VC map is inconsistent (Port %04x:%02x:%02x.%1x 0x%02x, GPU 0x%02x)!\n"
                     ,*param_3,*(undefined1 *)(param_3 + 1),*(undefined1 *)((long)param_3 + 5),
                     *(undefined1 *)((long)param_3 + 6),uVar2 & 0xfe | 1,local_2c[0] & 0xfe | 1);
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x35c,"_objClAdjustTcVcMap",1,
                     "NVRM: NVPCIE: Fixing TC/VC map to common subset 0x%02x.\n",uVar4 | 1);
        local_2c[0] = local_2c[0] & 0xffffff01 | uVar4;
        (**(code **)(param_1 + 0x170))(param_1,0x114);
      }
      return;
    }
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x34e,"_objClAdjustTcVcMap",4,
                 "NVRM: Cannot read NV_XVE_VCCAP_CTRL0\n");
    return;
  }
  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x342,"_objClAdjustTcVcMap",1,
               "NVRM: NVPCIE: Can not read VC resource control 0 on port %04x:%02x:%02x.%1x (bug 1048498).\n"
               ,*param_3,*(undefined1 *)(param_3 + 1),*(undefined1 *)((long)param_3 + 5),
               *(undefined1 *)((long)param_3 + 6));
  return;
}


// ===== 00479c30 clPcieReadL1SsCapability_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 clPcieReadL1SsCapability_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0xffff;
  }
  portMemSet(param_3,0,0x10);
  iVar1 = (**(code **)(param_1 + 0x168))(param_1);
  if ((((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
      (*(char *)(param_2 + 0x48) != '\0')) && (*(int *)(param_1 + 0x1dac) != 0)) {
    uVar2 = clPcieReadDword_IMPL
                      (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c),
                       *(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e));
    *param_3 = uVar2;
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1dac) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1dac) + 4);
      param_3[1] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1dac) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1dac) + 8);
      param_3[2] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       (*(char *)(param_2 + 0x48) != '\0')) {
      if (*(int *)(param_1 + 0x1dac) == 0) {
        return 0;
      }
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1dac) + 0xc);
      param_3[3] = uVar2;
    }
    return 0;
  }
  return 0xffff;
}


// ===== 00479e10 clPcieReadAerCapability_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 clPcieReadAerCapability_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0xffff;
  }
  portMemSet(param_3,0,0x38);
  iVar1 = (**(code **)(param_1 + 0x168))(param_1);
  if ((((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
      (*(char *)(param_2 + 0x48) != '\0')) && (*(int *)(param_1 + 0x1da4) != 0)) {
    uVar2 = clPcieReadDword_IMPL
                      (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c),
                       *(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e));
    *param_3 = uVar2;
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 4);
      param_3[1] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 8);
      param_3[2] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if ((((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
        (*(char *)(param_2 + 0x48) != '\0')) && (*(int *)(param_1 + 0x1da4) != 0)) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0xc);
      param_3[3] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x10);
      param_3[4] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x14);
      param_3[5] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if ((((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
        (*(char *)(param_2 + 0x48) != '\0')) && (*(int *)(param_1 + 0x1da4) != 0)) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x18);
      param_3[6] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x1c);
      param_3[7] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x20);
      param_3[8] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if ((((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
        (*(char *)(param_2 + 0x48) != '\0')) && (*(int *)(param_1 + 0x1da4) != 0)) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x24);
      param_3[9] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x28);
      param_3[10] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       ((*(char *)(param_2 + 0x48) != '\0' && (*(int *)(param_1 + 0x1da4) != 0)))) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x2c);
      param_3[0xb] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if ((((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
        (*(char *)(param_2 + 0x48) != '\0')) && (*(int *)(param_1 + 0x1da4) != 0)) {
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x30);
      param_3[0xc] = uVar2;
    }
    iVar1 = (**(code **)(param_1 + 0x168))(param_1);
    if (((iVar1 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
       (*(char *)(param_2 + 0x48) != '\0')) {
      if (*(int *)(param_1 + 0x1da4) == 0) {
        return 0;
      }
      uVar2 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),
                         *(int *)(param_1 + 0x1da4) + 0x34);
      param_3[0xd] = uVar2;
    }
    return 0;
  }
  return 0xffff;
}


// ===== 0047a380 clPcieWriteWord_IMPL =====

void clPcieWriteWord_IMPL
               (long param_1,undefined4 param_2,undefined1 param_3,byte param_4,byte param_5,
               ulong param_6,undefined2 param_7)

{
  char cVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  
  lVar2 = sysGetOs_IMPL(g_pSys);
  uVar3 = (param_6 & 0xffffffff) + 2;
  if (uVar3 < 0x1001) {
    if (param_4 < 0x20) {
      if (7 < param_5) {
LAB_0047a500:
        nvAssertFailedNoLog("func < PCI_MAX_FUNCTIONS","src/kernel/platform/chipset/chipset_pcie.c",
                            0xc74);
        goto LAB_0047a520;
      }
      if (*(char *)(param_1 + 0x48) == '\0') goto LAB_0047a4af;
    }
    else {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc73);
      if (7 < param_5) goto LAB_0047a500;
LAB_0047a520:
      if ((*(char *)(param_1 + 0x48) == '\0') || (0x1000 < uVar3)) goto LAB_0047a4af;
    }
    lVar4 = osPciInitHandle(param_2,param_3,param_4,param_5,0,0);
    if ((lVar4 != 0) &&
       (cVar1 = osTestPcieExtendedConfigAccess(lVar4,param_6 & 0xffffffff), cVar1 != '\0')) {
      osPciWriteWord(lVar4,param_6 & 0xffffffff,param_7);
      return;
    }
    if (*(char *)(lVar2 + 0x4d) == '\0') {
      lVar2 = objClPcieMapEnhCfgSpace(param_1,param_2,param_3,param_4,param_5);
      if (lVar2 == 0) {
        return;
      }
      *(undefined2 *)(lVar2 + (param_6 >> 1 & 0x7fffffff) * 2) = param_7;
      objClPcieUnmapEnhCfgSpace_isra_0(lVar2);
      return;
    }
    uVar5 = 0xc85;
    pcVar6 = "!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)";
  }
  else {
    nvAssertFailedNoLog("offset + sizeof(value) <= 0x1000",
                        "src/kernel/platform/chipset/chipset_pcie.c",0xc72);
    if (0x1f < param_4) {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc73);
    }
    if (7 < param_5) goto LAB_0047a500;
LAB_0047a4af:
    uVar5 = 0xc79;
    pcVar6 = "clPcieWriteWord() failed!";
  }
  nvAssertFailedNoLog(pcVar6,"src/kernel/platform/chipset/chipset_pcie.c",uVar5);
  return;
}


// ===== 0047a5c0 clPcieWriteDword_IMPL =====

void clPcieWriteDword_IMPL
               (long param_1,undefined4 param_2,undefined1 param_3,byte param_4,byte param_5,
               ulong param_6,undefined4 param_7)

{
  char cVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  
  lVar2 = sysGetOs_IMPL(g_pSys);
  uVar3 = (param_6 & 0xffffffff) + 4;
  if (uVar3 < 0x1001) {
    if (param_4 < 0x20) {
      if (7 < param_5) {
LAB_0047a740:
        nvAssertFailedNoLog("func < PCI_MAX_FUNCTIONS","src/kernel/platform/chipset/chipset_pcie.c",
                            0xca0);
        goto LAB_0047a760;
      }
      if (*(char *)(param_1 + 0x48) == '\0') goto LAB_0047a6ef;
    }
    else {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc9f);
      if (7 < param_5) goto LAB_0047a740;
LAB_0047a760:
      if ((*(char *)(param_1 + 0x48) == '\0') || (0x1000 < uVar3)) goto LAB_0047a6ef;
    }
    lVar4 = osPciInitHandle(param_2,param_3,param_4,param_5,0,0);
    if ((lVar4 != 0) &&
       (cVar1 = osTestPcieExtendedConfigAccess(lVar4,param_6 & 0xffffffff), cVar1 != '\0')) {
      osPciWriteDword(lVar4,param_6 & 0xffffffff,param_7);
      return;
    }
    if (*(char *)(lVar2 + 0x4d) == '\0') {
      lVar2 = objClPcieMapEnhCfgSpace(param_1,param_2,param_3,param_4,param_5);
      if (lVar2 == 0) {
        return;
      }
      *(undefined4 *)(lVar2 + (param_6 >> 2 & 0x3fffffff) * 4) = param_7;
      objClPcieUnmapEnhCfgSpace_isra_0(lVar2);
      return;
    }
    uVar5 = 0xcb1;
    pcVar6 = "!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)";
  }
  else {
    nvAssertFailedNoLog("offset + sizeof(value) <= 0x1000",
                        "src/kernel/platform/chipset/chipset_pcie.c",0xc9e);
    if (0x1f < param_4) {
      nvAssertFailedNoLog("device < PCI_MAX_DEVICES","src/kernel/platform/chipset/chipset_pcie.c",
                          0xc9f);
    }
    if (7 < param_5) goto LAB_0047a740;
LAB_0047a6ef:
    uVar5 = 0xca5;
    pcVar6 = "clPcieWriteDword() failed!";
  }
  nvAssertFailedNoLog(pcVar6,"src/kernel/platform/chipset/chipset_pcie.c",uVar5);
  return;
}


// ===== 0047a800 Broadcom_HT2100_setupFunc =====

undefined8 Broadcom_HT2100_setupFunc(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x58) = 1;
  return 0;
}


// ===== 0047a810 Intel_RP25XX_setupFunc =====

undefined8 Intel_RP25XX_setupFunc(long param_1,long param_2)

{
  if ((*(char *)(param_2 + 0x48) != '\0') &&
     (*(undefined4 *)(param_1 + 0x1da4) = 0x1c0, *(char *)(param_1 + 0x479) == '\0')) {
    *(undefined4 *)(param_1 + 0x1d74) = 0x1c0;
  }
  return 0;
}


// ===== 0047a840 Intel_RP81XX_setupFunc =====

undefined8 Intel_RP81XX_setupFunc(undefined8 param_1,long param_2)

{
  *(undefined2 *)(param_2 + 0x59) = 0x101;
  return 0;
}


// ===== 0047a850 Intel_RP3C0X_setupFunc =====

undefined8 Intel_RP3C0X_setupFunc(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x5d) = 1;
  return 0;
}


// ===== 0047a860 Intel_RP0C0X_setupFunc =====

undefined8 Intel_RP0C0X_setupFunc(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x5d) = 1;
  return 0;
}


// ===== 0047a870 Intel_RP2F0X_setupFunc =====

short Intel_RP2F0X_setupFunc(long param_1,long param_2)

{
  undefined8 *puVar1;
  long lVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  short local_3c;
  ushort local_3a;
  int local_38;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  
  lVar2 = g_pSys;
  lVar6 = *(long *)(g_pSys + 0x238);
  iVar4 = osNv_cpuid(1,0,&local_38,local_34,local_30,local_2c);
  if (iVar4 == 0) {
    *(undefined1 *)(param_2 + 0x5d) = 1;
    sVar3 = -(ushort)(param_1 == 0);
  }
  else {
    *(undefined1 *)(param_2 + 0x5d) = 1;
    if (param_1 != 0) {
      if (((lVar6 == 0) || (*(char *)(lVar6 + 0x4a) == '\0')) && (local_38 == 0x306f2)) {
        lVar6 = osPciInitHandle(*(undefined4 *)(param_1 + 0x87c),0x7f,0x1e,3,&local_3c,&local_3a);
        if (((lVar6 == 0) || (local_3c != -0x7f7a)) ||
           (((local_3a & 0xfff0) != 0x2fc0 || (*(char *)(param_2 + 0x48) == '\0')))) {
          for (puVar1 = *(undefined8 **)(param_2 + 0xe8); puVar1 != (undefined8 *)0x0;
              puVar1 = (undefined8 *)*puVar1) {
            if (((*(short *)((long)puVar1 + 0x12) == -0x7f7a) &&
                ((*(ushort *)(puVar1 + 2) & 0xfff0) == 0x2fc0)) &&
               (*(char *)(param_2 + 0x48) != '\0')) {
              uVar7 = *(undefined1 *)((long)puVar1 + 0x21);
              uVar8 = *(undefined1 *)(puVar1 + 4);
              uVar9 = *(undefined1 *)((long)puVar1 + 0x22);
              goto LAB_0047a999;
            }
          }
        }
        else {
          uVar9 = 3;
          uVar7 = 0x1e;
          uVar8 = 0x7f;
LAB_0047a999:
          uVar5 = clPcieReadDword_IMPL(param_2,0,uVar8,uVar7,uVar9,0x94);
          if ((uVar5 & 0x20000000) == 0) {
            *(undefined1 *)(lVar2 + 0x6e) = 1;
            return 0;
          }
        }
      }
      return 0;
    }
    sVar3 = -1;
  }
  return sVar3;
}


// ===== 0047aa00 Intel_Broadwell_setupFunc =====

undefined8 Intel_Broadwell_setupFunc(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x4f) = 1;
  if (*(short *)(param_2 + 0xa8) == 0x1604) {
    _Set_ASPM_L0S_L1(param_2,1,1);
    *(undefined2 *)(param_2 + 0x53) = 0x101;
    return 0;
  }
  if (*(short *)(param_2 + 0xa8) != 0x1614) {
    return 0;
  }
  _Set_ASPM_L0S_L1(param_2,0,0);
  return 0;
}


// ===== 0047aa70 Intel_Skylake_setupFunc =====

undefined8 Intel_Skylake_setupFunc(undefined8 param_1,long param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_2 + 0xa8);
  *(undefined1 *)(param_2 + 0x4f) = 1;
  *(undefined1 *)(param_2 + 0x5d) = 1;
  if (uVar1 == 0x191f) {
LAB_0047aac6:
    _Set_ASPM_L0S_L1(param_2,1,0);
    return 0;
  }
  if (uVar1 < 0x1920) {
    if (uVar1 != 0x1904) {
      if (uVar1 != 0x1910) {
        return 0;
      }
      goto LAB_0047aac6;
    }
  }
  else if (uVar1 != 0x5910) {
    return 0;
  }
  _Set_ASPM_L0S_L1(param_2,1,1);
  *(undefined1 *)(param_2 + 0x54) = 1;
  return 0;
}


// ===== 0047aaf0 Intel_Skylake_U_Pch_setupFunc =====

undefined8 Intel_Skylake_U_Pch_setupFunc(long param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x4f) = 1;
  _Set_ASPM_L0S_L1(param_2,1,1);
  *(undefined2 *)(param_1 + 0x47e) = 0x101;
  *(undefined1 *)(param_2 + 0x5d) = 1;
  return 0;
}


// ===== 0047ab30 Intel_Skylake_H_Pch_setupFunc =====

undefined8 Intel_Skylake_H_Pch_setupFunc(long param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x4f) = 1;
  _Set_ASPM_L0S_L1(param_2,1,0);
  *(undefined1 *)(param_1 + 0x47e) = 1;
  *(undefined1 *)(param_2 + 0x5d) = 1;
  return 0;
}


// ===== 0047ab70 Intel_Kabylake_Y_setupFunc =====

undefined8 Intel_Kabylake_Y_setupFunc(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x4f) = 1;
  _Set_ASPM_L0S_L1(param_2,1,1);
  *(undefined1 *)(param_2 + 0x54) = 1;
  *(undefined1 *)(param_2 + 0x5d) = 1;
  return 0;
}


// ===== 0047abb0 AMD_RP1483_setupFunc =====

undefined8 AMD_RP1483_setupFunc(undefined8 param_1,undefined8 param_2)

{
  _Set_ASPM_L0S_L1(param_2,1,0);
  return 0;
}


// ===== 0047abd0 AMD_RP1480_setupFunc =====

undefined8 AMD_RP1480_setupFunc(undefined8 param_1,undefined8 param_2)

{
  _Set_ASPM_L0S_L1(param_2,1,0);
  return 0;
}


// ===== 0047abf0 AMD_RP1630_setupFunc =====

undefined8 AMD_RP1630_setupFunc(undefined8 param_1,undefined8 param_2)

{
  _Set_ASPM_L0S_L1(param_2,1,0);
  return 0;
}


// ===== 0047ac10 Qualcomm_Snapdragon8cx_RP_setupFunc =====

undefined8 Qualcomm_Snapdragon8cx_RP_setupFunc(void)

{
  return 0;
}


// ===== 0047ac20 gpuIsMultiGpuBoard =====

undefined8 gpuIsMultiGpuBoard(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x476) != '\0') {
    return 1;
  }
  uVar1 = gpuDevIdIsMultiGpuBoard
                    (*(undefined2 *)(param_1 + 0x7f6),*(uint *)(param_1 + 0x7fc) & 0xffff,
                     *(uint *)(param_1 + 0x7fc) >> 0x10);
  return uVar1;
}


// ===== 0047ac60 clInsertPcieConfigSpaceBase_IMPL =====

undefined8
clInsertPcieConfigSpaceBase_IMPL
          (long param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)portMemAllocNonPaged(0x18);
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = param_2;
    *(undefined1 *)((long)puVar1 + 0xc) = param_4;
    *(undefined1 *)((long)puVar1 + 0xd) = param_5;
    *(undefined4 *)(puVar1 + 1) = param_3;
    puVar1[2] = *(undefined8 *)(param_1 + 0xc0);
    *(undefined8 **)(param_1 + 0xc0) = puVar1;
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x10d3,
                 "clInsertPcieConfigSpaceBase_IMPL",1,
                 "NVRM: PCIe Config BaseAddress 0x%llx Domain %x startBusNumber %x endBusNumber %x\n"
                 ,*puVar1,*(undefined4 *)(puVar1 + 1),*(undefined1 *)((long)puVar1 + 0xc),
                 *(undefined1 *)((long)puVar1 + 0xd));
    return 0;
  }
  return 0x1a;
}


// ===== 0047ad20 storePcieGetConfigSpaceBaseFromMcfgTable =====

undefined8 storePcieGetConfigSpaceBaseFromMcfgTable(long param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  undefined8 local_48;
  ushort local_40;
  byte local_3e;
  byte local_3d;
  
  if (param_3 < 0x2d) {
    return 0;
  }
  uVar4 = 0x2c;
LAB_0047ad7d:
  do {
    if ((param_3 - 0x2c & 0xfffffff0) + 0x2c == uVar4) {
      return 0;
    }
    portMemCopy(&local_48,0x10,(ulong)uVar4 + param_2,0x10);
    bVar3 = local_3d;
    if (local_3d <= local_3e) {
      bVar3 = 0xff;
    }
    if (*(char *)(param_1 + 0x48) != '\0') {
      for (puVar1 = *(undefined8 **)(param_1 + 0xc0); puVar1 != (undefined8 *)0x0;
          puVar1 = (undefined8 *)puVar1[2]) {
        if (*(uint *)(puVar1 + 1) == (uint)local_40) {
          if ((local_3e == *(byte *)((long)puVar1 + 0xc)) &&
             (*(byte *)((long)puVar1 + 0xd) == bVar3)) goto LAB_0047ad74;
          uVar4 = uVar4 + 0x10;
          *(byte *)((long)puVar1 + 0xc) = local_3e;
          *(byte *)((long)puVar1 + 0xd) = bVar3;
          *puVar1 = local_48;
          if (param_3 <= uVar4) {
            return 0;
          }
          goto LAB_0047ad7d;
        }
      }
    }
    iVar2 = clInsertPcieConfigSpaceBase_IMPL(param_1,local_48);
    if (iVar2 != 0) {
      return 0x1a;
    }
LAB_0047ad74:
    uVar4 = uVar4 + 0x10;
    if (param_3 <= uVar4) {
      return 0;
    }
  } while( true );
}


// ===== 0047ae40 clStorePcieConfigSpaceBaseFromMcfg_IMPL =====

int clStorePcieConfigSpaceBaseFromMcfg_IMPL(long param_1)

{
  ulong uVar1;
  long lVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  ushort *puVar9;
  int *piVar10;
  char *pcVar11;
  char *pcVar12;
  ulong uVar13;
  ulong uVar14;
  bool bVar15;
  long local_78;
  long *local_70;
  long *local_68;
  long local_58;
  long local_50;
  int *local_48;
  undefined8 local_40;
  
  lVar7 = sysGetOs_IMPL(g_pSys);
  local_58 = 0;
  local_50 = 0;
  local_48 = (int *)0x0;
  if (*(char *)(lVar7 + 0x4d) != '\0') {
    nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)",
                        "src/kernel/platform/chipset/chipset_pcie.c",0x1063);
    return 0x40;
  }
  if (*(char *)(param_1 + 0x9f) == '\0') {
    return 0x25;
  }
  uVar13 = 0;
  local_40 = (ulong)local_40._4_4_ << 0x20;
  iVar5 = osInitGetAcpiTable();
  if (iVar5 == 0) {
    uVar6 = osGetAcpiTable(0x4746434d,0,0,&local_40);
    uVar1 = local_40;
    uVar13 = (ulong)uVar6;
    if (uVar6 == 0) {
LAB_0047b118:
      iVar5 = storePcieGetConfigSpaceBaseFromMcfgTable(param_1,local_48,uVar13);
      portMemFree(local_48);
      return iVar5;
    }
    uVar13 = local_40 & 0xffffffff;
    if ((int)local_40 == 0) goto LAB_0047b118;
    local_48 = (int *)portMemAllocNonPaged(uVar13);
    if (local_48 != (int *)0x0) {
      iVar5 = osGetAcpiTable(0x4746434d,&local_48,uVar1 & 0xffffffff,&local_40);
      if (iVar5 == 0) goto LAB_0047b118;
      uVar13 = 0;
      portMemFree(local_48);
    }
  }
  lVar2 = g_pSys;
  lVar8 = sysGetOs_IMPL(g_pSys);
  local_40 = local_40 & 0xffffffff00000000;
  cVar3 = *(char *)(lVar8 + 0x4a);
  if (*(char *)(lVar2 + 0x67) == '\0') {
    iVar5 = 0xffff;
LAB_0047af01:
    local_68 = &local_58;
    local_70 = &local_50;
    puVar9 = (ushort *)osMapKernelSpace(0x40e,0x400,cVar3 == '\0',3);
    if (puVar9 != (ushort *)0x0) {
      local_40 = CONCAT44(local_40._4_4_,(uint)*puVar9 << 4);
      osUnmapKernelSpace(puVar9,0x400);
      cVar3 = scanForRsdtXsdtTables_isra_0
                        (*(undefined1 *)(lVar8 + 0x4a),local_40 & 0xffffffff,0x400,local_68,local_70
                        );
      if (cVar3 == '\x01') goto LAB_0047b010;
    }
    local_40 = CONCAT44(local_40._4_4_,0xe0000);
    cVar3 = scanForRsdtXsdtTables_isra_0
                      (*(undefined1 *)(lVar8 + 0x4a),0xe0000,0x20000,local_68,local_70);
    if ((cVar3 != '\x01') && (iVar5 != 0)) {
      iVar5 = 0xffff;
      goto joined_r0x0047b090;
    }
  }
  else {
    iVar5 = osGetAcpiRsdpFromUefi(&local_40);
    if (iVar5 != 0) goto joined_r0x0047b090;
    cVar4 = scanForRsdtXsdtTables_isra_0(*(undefined1 *)(lVar8 + 0x4a),local_40 & 0xffffffff,0x24);
    iVar5 = 0;
    if (cVar4 != '\x01') goto LAB_0047af01;
  }
LAB_0047b010:
  lVar2 = local_58;
  local_40 = 0;
  if (local_50 != 0 || local_58 != 0) {
    if (local_58 == 0) {
      local_68._0_4_ = 0x54445358;
      local_78 = 8;
      lVar8 = local_50;
    }
    else {
      local_68._0_4_ = 0x54445352;
      local_78 = 4;
      lVar8 = local_58;
    }
    bVar15 = *(char *)(lVar7 + 0x4a) == '\0';
    piVar10 = (int *)osMapKernelSpace(lVar8,8,bVar15,3);
    if (piVar10 != (int *)0x0) {
      if (*piVar10 == (int)local_68) {
        uVar6 = piVar10[1];
        osUnmapKernelSpace(piVar10,8);
        uVar1 = (ulong)uVar6;
        pcVar11 = (char *)osMapKernelSpace(lVar8,uVar1,bVar15,3);
        if (pcVar11 != (char *)0x0) {
          if (uVar6 == 0) {
LAB_0047b3ed:
            osUnmapKernelSpace(pcVar11,uVar1);
          }
          else {
            cVar3 = '\0';
            pcVar12 = pcVar11;
            do {
              cVar3 = cVar3 + *pcVar12;
              pcVar12 = pcVar12 + 1;
            } while (pcVar12 != pcVar11 + uVar1);
            if (cVar3 == '\0') {
              if (uVar1 < 0x25) goto LAB_0047b3ed;
              uVar14 = local_78 + 0x24;
LAB_0047b25e:
              if (lVar2 == 0) {
                portMemCopy(&local_40,8,pcVar11 + (uVar14 - local_78),8);
              }
              else {
                local_40 = (ulong)*(uint *)(pcVar11 + (uVar14 - local_78));
              }
              piVar10 = (int *)osMapKernelSpace(local_40,8,bVar15,3);
              if (piVar10 != (int *)0x0) {
                if (*piVar10 != 0x4746434d) {
                  osUnmapKernelSpace(piVar10,8);
                  goto LAB_0047b252;
                }
                osUnmapKernelSpace(pcVar11,uVar1);
                osUnmapKernelSpace(piVar10,8);
                uVar1 = local_40;
                if (local_40 == 0) goto LAB_0047b083;
                bVar15 = *(char *)(lVar7 + 0x4a) == '\0';
                local_48 = (int *)osMapKernelSpace(local_40,8,bVar15,3);
                if (local_48 == (int *)0x0) {
                  return 0x59;
                }
                iVar5 = 0x25;
                if (*local_48 == 0x4746434d) {
                  uVar6 = local_48[1];
                  uVar13 = (ulong)uVar6;
                  osUnmapKernelSpace(local_48,8);
                  local_48 = (int *)osMapKernelSpace(uVar1,uVar13,bVar15,3);
                  if (local_48 == (int *)0x0) {
                    return 0x59;
                  }
                  if (uVar13 != 0) {
                    cVar3 = '\0';
                    piVar10 = local_48;
                    do {
                      cVar3 = cVar3 + (char)*piVar10;
                      piVar10 = (int *)((long)piVar10 + 1);
                    } while (piVar10 != (int *)(uVar13 + (long)local_48));
                    iVar5 = 0x25;
                    if (cVar3 != '\0') goto LAB_0047b099;
                  }
                  iVar5 = storePcieGetConfigSpaceBaseFromMcfgTable(param_1,local_48,uVar6);
                  goto joined_r0x0047b090;
                }
                goto LAB_0047b099;
              }
LAB_0047b252:
              if (uVar14 < uVar1) goto code_r0x0047b25b;
              osUnmapKernelSpace(pcVar11,uVar1);
            }
            else {
              nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0xfa8,"ScanForTable",4,
                           "NVRM: Checksum mismatch\n");
              osUnmapKernelSpace(pcVar11,uVar1);
            }
          }
        }
      }
      else {
        osUnmapKernelSpace(piVar10,0);
      }
    }
  }
LAB_0047b083:
  iVar5 = 0x1a;
joined_r0x0047b090:
  if (local_48 == (int *)0x0) {
    return iVar5;
  }
LAB_0047b099:
  osUnmapKernelSpace(local_48,uVar13);
  return iVar5;
code_r0x0047b25b:
  uVar14 = uVar14 + local_78;
  goto LAB_0047b25e;
}


// ===== 0047b400 clUpdatePcieConfig_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void clUpdatePcieConfig_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  undefined8 *puVar13;
  ulong *puVar14;
  ulong uVar15;
  byte bVar16;
  uint uVar17;
  ulong uVar18;
  int *piVar19;
  uint local_4c;
  ushort local_3e;
  uint local_3c [3];
  
  lVar1 = *(long *)(g_pSys + 0x210);
  lVar2 = *(long *)(param_1 + 7000);
  iVar8 = (**(code **)(param_1 + 0x168))();
  if (1 < iVar8 - 3U) {
    return;
  }
  clInitMappingPciBusDevice_IMPL(param_1,param_2);
  uVar15 = *(ulong *)(param_1 + 0x878);
  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x3d3,"clUpdatePcieConfig_IMPL",1,
               "NVRM: GPU Domain %X Bus %X Device %X Func %X\n",uVar15 >> 0x20,uVar15 >> 8 & 0xff,
               uVar15 & 0xff,0);
  uVar15 = *(ulong *)(param_1 + 0x878);
  lVar9 = osPciInitHandle(uVar15 >> 0x20,uVar15 >> 8 & 0xff,uVar15 & 0xff,0,&local_3e,local_3c);
  if (lVar9 == 0) {
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0xdfa,"objClGpuIs3DController",4,
                 "NVRM: GPU Config Space not accessible \n");
    return;
  }
  sVar6 = osPciReadWord(lVar9,10);
  if (sVar6 == 0x302) {
    *(undefined1 *)(param_1 + 0x44a) = 1;
  }
  if (*(char *)(param_1 + 0x4912) == '\0') {
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x1118,
                 "objClLoadPcieVirtualP2PApproval",1,"NVRM: Skipping non-pass-through GPU%u\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  else {
    uVar15 = *(ulong *)(param_1 + 0x878);
    uVar10 = osPciInitHandle(uVar15 >> 0x20,uVar15 >> 8 & 0xff,uVar15 & 0xff,0,0,0);
    uVar7 = osPciReadByte(uVar10,0x34);
    uVar15 = (ulong)uVar7;
    if ((char)uVar7 == '\0') {
LAB_0047be15:
      nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x1136,
                   "objClLoadPcieVirtualP2PApproval",1,
                   "NVRM: No virtual P2P approval capability found in GPU%u\'s capability list\n",
                   *(undefined4 *)(param_1 + 0x7a4));
    }
    else {
      local_4c = 0;
      do {
        uVar18 = uVar15 & 0xff;
        uVar11 = osPciReadDword(uVar10,uVar18);
        uVar7 = (uint)uVar11;
        uVar15 = uVar11 >> 8 & 0xffffff;
        cVar5 = (char)uVar15;
        if ((char)uVar11 == '\t') {
          local_4c = uVar7 >> 0x18;
          uVar7 = osPciReadDword(uVar10,(int)uVar18 + 4);
          local_4c = local_4c | (uVar7 & 0xffff) << 8;
          uVar15 = uVar11 >> 8 & 0xff;
        }
        if (cVar5 == '\0') {
          if (local_4c != 0x503250) goto LAB_0047be15;
          break;
        }
      } while (local_4c != 0x503250);
      uVar17 = uVar7 >> 0x10 & 7;
      if (uVar17 == 0) {
        *(undefined1 *)(param_1 + 0x7e8) = 1;
        uVar7 = uVar7 >> 0x13 & 0xf;
        *(char *)(param_1 + 0x7e9) = (char)uVar7;
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x114b,
                     "objClLoadPcieVirtualP2PApproval",1,
                     "NVRM: Hypervisor has assigned GPU%u to peer clique %u\n",
                     *(undefined4 *)(param_1 + 0x7a4),uVar7);
      }
      else {
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x1141,
                     "objClLoadPcieVirtualP2PApproval",3,
                     "NVRM: Unable to handle virtual P2P approval capability version %u on GPU%u\n",
                     uVar17,*(undefined4 *)(param_1 + 0x7a4));
      }
    }
  }
  if (*(char *)(param_1 + 0x4912) == '\0') {
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x115e,
                 "objClLoadPcieVirtualConfigBits",1,"NVRM: Skipping non-pass-through GPU%u\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  else {
    uVar15 = *(ulong *)(param_1 + 0x878);
    uVar10 = osPciInitHandle(uVar15 >> 0x20,uVar15 >> 8 & 0xff,uVar15 & 0xff,0,0,0);
    uVar7 = osPciReadByte(uVar10,0x34);
    uVar15 = (ulong)uVar7;
    if ((char)uVar7 != '\0') {
      local_4c = 0;
      do {
        uVar18 = uVar15 & 0xff;
        uVar11 = osPciReadDword(uVar10,uVar18);
        uVar7 = (uint)uVar11;
        uVar15 = uVar11 >> 8 & 0xffffff;
        cVar5 = (char)uVar15;
        if ((char)uVar11 == '\t') {
          local_4c = uVar7 >> 0x18;
          uVar7 = osPciReadDword(uVar10,(int)uVar18 + 4);
          local_4c = local_4c | (uVar7 & 0xffff) << 8;
          uVar15 = uVar11 >> 8 & 0xff;
        }
        if (cVar5 == '\0') {
          if (local_4c != 0x535442) goto LAB_0047b700;
          break;
        }
      } while (local_4c != 0x535442);
      *(short *)(param_1 + 0x7ea) = (short)(uVar7 >> 0x10);
      nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x117d,
                   "objClLoadPcieVirtualConfigBits",1,
                   "NVRM: Hypervisor has specified config bits %u for GPU%u\n",uVar7 >> 0x10,
                   *(undefined4 *)(param_1 + 0x7a4));
    }
  }
LAB_0047b700:
  if (*(char *)(param_1 + 0x4912) != '\0') {
    *(undefined1 *)(param_2 + 0x59) = 1;
  }
  lVar9 = g_pSys;
  if (*(int *)(g_pSys + 0x118) == 6) {
    if (*(int *)(g_pSys + 0x11c) == 0x6a) {
      if (*(char *)(g_pSys + 0x128) == '\x06') goto LAB_0047bcab;
    }
    else if (*(int *)(g_pSys + 0x11c) == 0x8f) {
LAB_0047bcab:
      *(undefined1 *)(param_2 + 0x6d) = 1;
    }
  }
  else if (*(int *)(g_pSys + 0x118) == 0x19) {
    if (*(int *)(g_pSys + 0x11c) == 1) {
      if (*(char *)(g_pSys + 0x128) == '\x01') goto LAB_0047bcab;
    }
    else if (*(int *)(g_pSys + 0x11c) == 0x11) goto LAB_0047bcab;
  }
  lVar12 = sysGetOs_IMPL(lVar9);
  uVar10 = *(undefined8 *)(param_1 + 7000);
  lVar9 = *(long *)(lVar9 + 0x210);
  iVar8 = clStoreBusTopologyCache_IMPL(param_1,param_2,*(undefined4 *)(param_1 + 0x87c));
  if (iVar8 != 0) goto LAB_0047b9f0;
  cVar5 = *(char *)(lVar9 + 0x4b);
  if (*(char *)(param_2 + 0xbc) == '\0') {
    if (cVar5 == '\0') {
      lVar9 = gpuGetGspStaticInfo(param_1);
      if (lVar9 == 0) {
        nvAssertFailedNoLog("pSCI != NULL","src/kernel/platform/chipset/chipset_pcie.c",0x1243);
      }
      else if (*(char *)(lVar9 + 0x5fe) != '\0') {
        *(undefined1 *)(param_2 + 0x5d) = 1;
      }
      cVar5 = hypervisorIsVgxHyper_IMPL();
      if (cVar5 != '\0') {
        *(undefined1 *)(param_2 + 0x59) = 1;
      }
      iVar8 = clFindFHBAndGetChipsetInfoIndex_IMPL(param_2,&local_3e);
      if (iVar8 == 0) {
        *(undefined4 *)(param_2 + 0xb4) = (&DAT_0059eec4)[(ulong)local_3e * 6];
        if (((code *)(&PTR_Intel_25XX_setupFunc_0059eed0)[(ulong)local_3e * 3] != (code *)0x0) &&
           (iVar8 = (*(code *)(&PTR_Intel_25XX_setupFunc_0059eed0)[(ulong)local_3e * 3])(param_2),
           iVar8 != 0)) {
          nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x12d,"objClInitPcieChipset",4,
                       "NVRM: *** Chipset Setup Function Error!\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x132,"objClInitPcieChipset",3,
                     "NVRM: *** Chipset has no definition! (vendor ID 0x%04x, device ID 0x%04x)\n",
                     *(undefined2 *)(param_2 + 0xaa),*(undefined2 *)(param_2 + 0xa8));
      }
      if (*(char *)(lVar12 + 0x4d) == '\0') {
        if ((((*(char *)(param_2 + 0x48) == '\0') || (*(char *)(param_2 + 0x5f) == '\0')) &&
            (*(char *)(*(long *)(param_1 + 0x1b48) + 0x4f) == '\0')) &&
           (iVar8 = clStorePcieConfigSpaceBaseFromMcfg_IMPL(param_2), iVar8 == 0)) {
          *(undefined1 *)(param_2 + 0x48) = 1;
        }
      }
      else {
        *(undefined1 *)(param_2 + 0x5f) = 1;
        *(undefined1 *)(param_2 + 0x48) = 1;
      }
      iVar8 = osReadRegistryDword(param_1,"AslmCfg",local_3c);
      if (iVar8 == 0) {
        if ((local_3c[0] & 3) == 0) {
          *(undefined1 *)(param_2 + 0x4a) = 0;
        }
        else if ((local_3c[0] & 3) == 1) {
          *(undefined1 *)(param_2 + 0x4a) = 1;
        }
        uVar7 = local_3c[0] >> 4 & 3;
        if (uVar7 == 0) {
          *(undefined1 *)(param_2 + 0x4c) = 0;
        }
        else if (uVar7 == 1) {
          *(undefined1 *)(param_2 + 0x4c) = 1;
        }
        uVar7 = local_3c[0] >> 8 & 3;
        if (uVar7 == 0) {
          *(undefined1 *)(param_2 + 0x4b) = 0;
        }
        else if (uVar7 == 1) {
          *(undefined1 *)(param_2 + 0x4b) = 1;
        }
        uVar7 = local_3c[0] >> 10 & 3;
        if (uVar7 == 0) {
          *(undefined1 *)(param_2 + 0x4d) = 0;
        }
        else if (uVar7 == 1) {
          *(undefined1 *)(param_2 + 0x4d) = 1;
        }
      }
      *(undefined1 *)(param_2 + 0xbc) = 1;
      if ((*(char *)(param_2 + 0x48) != '\0') &&
         (iVar8 = clPcieReadDword_IMPL
                            (param_2,*(undefined4 *)(param_2 + 0x98),*(undefined1 *)(param_2 + 0x9c)
                             ,*(undefined1 *)(param_2 + 0x9d),*(undefined1 *)(param_2 + 0x9e),0),
         iVar8 != CONCAT22(*(undefined2 *)(param_2 + 0xa8),*(undefined2 *)(param_2 + 0xaa)))) {
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x17b,"objClInitPcieChipset",4,
                     "NVRM: *** PCI-E config space not consistent with PCI config space, FHB vendor ID and device ID not equal!\n"
                    );
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x17d,"objClInitPcieChipset",4,
                     "NVRM: *** Setting PCI-E config space inaccessible!\n");
        *(undefined1 *)(param_2 + 0x48) = 0;
        lVar9 = *(long *)(param_2 + 0xc0);
        while (lVar9 != 0) {
          lVar3 = *(long *)(lVar9 + 0x10);
          portMemFree(lVar9);
          lVar9 = lVar3;
        }
        *(undefined8 *)(param_2 + 0xc0) = 0;
      }
    }
    else {
LAB_0047b789:
      nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x186,"objClInitPcieChipset",1,
                   "NVRM: Skipping PCI Express host bridge initialization\n");
    }
  }
  else if (cVar5 != '\0') goto LAB_0047b789;
  if ((*(char *)(param_1 + 0x1d5f) == '\0') &&
     (cVar5 = objClInitGpuPortData_part_0(param_1,param_2), cVar5 == '\0')) {
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x18d,"objClInitPcieChipset",4,
                 "NVRM: *** Unable to get PCI port handles\n");
  }
  else {
    if (*(char *)(lVar12 + 0x4d) == '\0') {
      lVar9 = sysGetOs_IMPL(g_pSys);
      if (*(char *)(lVar9 + 0x4d) == '\0') {
        if ((((*(char *)(param_2 + 0x48) != '\0') && (*(long *)(param_1 + 0x1ae8) == 0)) &&
            (*(char *)(param_1 + 0x880) != '\0')) &&
           (puVar14 = *(ulong **)(param_2 + 0xc0), puVar14 != (ulong *)0x0)) {
          uVar4 = *(undefined8 *)(param_1 + 0x878);
          do {
            if ((((int)((ulong)uVar4 >> 0x20) == (int)puVar14[1]) &&
                (bVar16 = (byte)((ulong)uVar4 >> 8), *(byte *)((long)puVar14 + 0xc) <= bVar16)) &&
               (bVar16 <= *(byte *)((long)puVar14 + 0xd))) {
              if (*puVar14 != 0) {
                lVar9 = osMapKernelSpace((ulong)(((uint)((ulong)uVar4 >> 8) & 0xff) << 0x14 |
                                                ((uint)uVar4 & 0xff) << 0xf) | *puVar14,0x1000,1);
                *(long *)(param_1 + 0x1ae8) = lVar9;
                if (lVar9 == 0) {
                  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x665,
                               "objClGpuMapEnhCfgSpace",4,
                               "NVRM: unable to map GPU\'s PCI-E configuration space.\n");
                }
              }
              break;
            }
            puVar14 = (ulong *)puVar14[2];
          } while (puVar14 != (ulong *)0x0);
        }
      }
      else {
        nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)"
                            ,"src/kernel/platform/chipset/chipset_pcie.c",0x64a);
      }
      lVar9 = sysGetOs_IMPL(g_pSys);
      if (*(char *)(lVar9 + 0x4d) == '\0') {
        if (((*(char *)(param_2 + 0x48) != '\0') && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
           ((*(long *)(param_1 + 0x1d98) == 0 &&
            (puVar14 = *(ulong **)(param_2 + 0xc0), puVar14 != (ulong *)0x0)))) {
          bVar16 = *(byte *)(param_1 + 0x1d8c);
          do {
            if (((*(int *)(param_1 + 0x1d88) == (int)puVar14[1]) &&
                (*(byte *)((long)puVar14 + 0xc) <= bVar16)) &&
               (bVar16 <= *(byte *)((long)puVar14 + 0xd))) {
              if (*puVar14 != 0) {
                lVar9 = osMapKernelSpace((ulong)((uint)*(byte *)(param_1 + 0x1d8d) << 0xf |
                                                 (uint)bVar16 << 0x14 |
                                                (uint)*(byte *)(param_1 + 0x1d8e) << 0xc) | *puVar14
                                         ,0x1000,1);
                if (lVar9 == 0) {
                  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x622,
                               "objClGpuMapRootPort",4,
                               "NVRM: NVPCIE: unable to map root port PCIE config space.\n");
                }
                else {
                  *(long *)(param_1 + 0x1d98) = lVar9;
                }
              }
              break;
            }
            puVar14 = (ulong *)puVar14[2];
          } while (puVar14 != (ulong *)0x0);
        }
      }
      else {
        nvAssertFailedNoLog("!pOS->getProperty(pOS, PDB_PROP_OS_DOES_NOT_ALLOW_DIRECT_PCIE_MAPPINGS)"
                            ,"src/kernel/platform/chipset/chipset_pcie.c",0x60a);
      }
    }
    uVar15 = 0;
    piVar19 = *(int **)(param_2 + 0x88);
    if (piVar19 != (int *)0x0) {
      iVar8 = *(int *)(param_1 + 0x1d58);
      bVar16 = *(byte *)(param_1 + 0x1d5c);
      do {
        while (((iVar8 != piVar19[6] || (bVar16 < *(byte *)(piVar19 + 7))) ||
               (*(byte *)((long)piVar19 + 0x1d) < bVar16))) {
          piVar19 = *(int **)(piVar19 + 8);
          if (piVar19 == (int *)0x0) goto LAB_0047b8b0;
        }
        if ((*piVar19 == 3) &&
           (plxPex8747GetFirmwareInfo(param_2,param_1,piVar19), *(char *)(param_1 + 0x476) == '\0'))
        {
          *(char *)(param_1 + 0x476) = (char)piVar19[0x12];
        }
        puVar13 = (undefined8 *)portMemAllocNonPaged(0x10);
        if (puVar13 == (undefined8 *)0x0) {
          nvAssertOkFailedNoLog
                    (0x1a,"addHwbcToList(pGpu, pHWBC)","src/kernel/platform/chipset/chipset_pcie.c",
                     0x1b0);
          goto LAB_0047b9f0;
        }
        portMemSet(puVar13,0,0x10);
        *puVar13 = piVar19;
        lVar9 = *(long *)(param_1 + 0x1d50);
        if (*(long *)(param_1 + 0x1d50) == 0) {
          *(undefined8 **)(param_1 + 0x1d50) = puVar13;
        }
        else {
          do {
            lVar12 = lVar9;
            lVar9 = *(long *)(lVar12 + 8);
          } while (lVar9 != 0);
          *(undefined8 **)(lVar12 + 8) = puVar13;
        }
        piVar19 = *(int **)(piVar19 + 10);
      } while (piVar19 != (int *)0x0);
    }
LAB_0047b8b0:
    if (rootPortInfo == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = 0;
      sVar6 = rootPortInfo;
      do {
        if ((*(short *)(param_1 + 0x1db6) == sVar6) &&
           (*(short *)(param_1 + 0x1db4) == (&DAT_0059eae2)[uVar11 * 8])) break;
        uVar11 = (ulong)((int)uVar11 + 1);
        sVar6 = (&rootPortInfo)[uVar11 * 8];
      } while (sVar6 != 0);
    }
    if (((code *)(&PTR_Broadcom_HT2100_setupFunc_0059eae8)[uVar11 * 2] != (code *)0x0) &&
       (iVar8 = (*(code *)(&PTR_Broadcom_HT2100_setupFunc_0059eae8)[uVar11 * 2])(param_1,param_2),
       iVar8 != 0)) {
      nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x1bf,"objClInitPcieChipset",4,
                   "NVRM: *** Root Port Setup Function Error\n");
    }
    if (upstreamPortInfo != 0) {
      sVar6 = upstreamPortInfo;
      do {
        if ((*(short *)(param_1 + 0x1d86) == sVar6) &&
           (*(short *)(param_1 + 0x1d84) == *(short *)(&DAT_0059ea42 + uVar15 * 0x10))) break;
        uVar15 = (ulong)((int)uVar15 + 1);
        sVar6 = (&upstreamPortInfo)[uVar15 * 8];
      } while (sVar6 != 0);
    }
    if (((code *)(&PTR_Intel_Skylake_setupFunc_0059ea48)[uVar15 * 2] != (code *)0x0) &&
       (iVar8 = (*(code *)(&PTR_Intel_Skylake_setupFunc_0059ea48)[uVar15 * 2])(param_1,param_2),
       iVar8 != 0)) {
      nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x1d0,"objClInitPcieChipset",4,
                   "NVRM: Upstream port Setup Function Error\n");
    }
    if ((*(char *)(param_2 + 0x48) != '\0') && (*(char *)(param_1 + 0x1d8f) != '\0')) {
      iVar8 = clPcieReadDword_IMPL
                        (param_2,*(undefined4 *)(param_1 + 0x1d88),*(undefined1 *)(param_1 + 0x1d8c)
                         ,*(undefined1 *)(param_1 + 0x1d8d),*(undefined1 *)(param_1 + 0x1d8e),0);
      if (iVar8 != CONCAT22(*(undefined2 *)(param_1 + 0x1db4),*(undefined2 *)(param_1 + 0x1db6))) {
        nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x1e0,"objClInitPcieChipset",4,
                     "NVRM: *** PCI-E config space not consistent with PCI config space, root port vendor ID and device ID not equal!\n"
                    );
        *(undefined1 *)(param_2 + 0x48) = 0;
        lVar9 = *(long *)(param_2 + 0xc0);
        while (lVar9 != 0) {
          lVar12 = *(long *)(lVar9 + 0x10);
          portMemFree(lVar9);
          lVar9 = lVar12;
        }
        *(undefined8 *)(param_2 + 0xc0) = 0;
      }
    }
    *(undefined1 *)(param_2 + 99) = 0;
    if ((((*(char *)(param_1 + 0x1d8f) != '\0') &&
         (iVar8 = (**(code **)(param_1 + 0x168))(param_1), iVar8 == 3)) &&
        (*(char *)(param_1 + 0x1d8f) != '\0')) && (*(int *)(param_1 + 0x1da0) != 0)) {
      uVar7 = osPciReadDword(*(undefined8 *)(param_1 + 0x1d90),*(int *)(param_1 + 0x1da0) + 0x24);
      iVar8 = (**(code **)(param_1 + 0x168))(param_1);
      if (((iVar8 == 3) && (*(char *)(param_1 + 0x1d8f) != '\0')) &&
         ((*(int *)(param_1 + 0x1da0) != 0 &&
          ((uVar15 = osPciReadDword(*(undefined8 *)(param_1 + 0x1d90),
                                    *(int *)(param_1 + 0x1da0) + 0x28), (uVar7 & 0x800) != 0 &&
           ((uVar15 & 0x400) != 0)))))) {
        iVar8 = clCheckUpstreamLtrSupport_IMPL(param_1,param_2,local_3c);
        if ((iVar8 == 0) && ((char)local_3c[0] == '\x01')) {
          *(undefined1 *)(param_2 + 99) = 1;
        }
        else {
          nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x205,"objClInitPcieChipset",1,
                       "NVRM: LTR capability not supported.\n");
        }
      }
    }
    kbifCacheChipsetL1SubstatesEnable_IMPL(param_1,uVar10);
  }
LAB_0047b9f0:
  local_3c[0] = 0;
  iVar8 = kbifGetPciePowerControlValue_IMPL(param_1,lVar2,local_3c);
  if (iVar8 == 0) {
    *(undefined1 *)(lVar2 + 0x23e4) = 1;
    *(uint *)(lVar2 + 0x23e0) = local_3c[0];
  }
  else {
    *(undefined1 *)(lVar2 + 0x23e4) = 0;
    *(undefined4 *)(lVar2 + 0x23e0) = 0;
    nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x225,
                 "_objClIsPciePowerControlPresent",1,
                 "NVRM: None of the PCIe Power Control for ASPM override are available\n");
  }
  kbifInitPcieDeviceControlStatus_IMPL(param_1,lVar2);
  (**(code **)(lVar2 + 0x178))(param_1,lVar2);
  (**(code **)(lVar2 + 400))(param_1,lVar2);
  (**(code **)(lVar2 + 0x268))(param_1,lVar2);
  (**(code **)(lVar2 + 0x278))(param_1,lVar2);
  if ((*(char *)(lVar1 + 0x4b) == '\0') &&
     ((*(char *)(param_1 + 0x476) != '\0' ||
      (cVar5 = gpuDevIdIsMultiGpuBoard
                         (*(undefined2 *)(param_1 + 0x7f6),*(uint *)(param_1 + 0x7fc) & 0xffff,
                          *(uint *)(param_1 + 0x7fc) >> 0x10), cVar5 != '\0')))) {
    gpumgrUpdateBoardId_IMPL(param_1);
    *(undefined1 *)(param_1 + 0x452) = 1;
  }
  cVar5 = clIsL1SupportedForUpstreamPort_IMPL(param_1,param_2);
  *(bool *)(param_2 + 0x55) = cVar5 != '\0';
  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x42a,"clUpdatePcieConfig_IMPL",1,
               "NVRM: Chipset %X Domain %X Bus %X Device %X Func %X PCIE PTR %X\n",
               *(undefined4 *)(param_2 + 0xb4),*(undefined4 *)(param_1 + 0x1d58),
               *(undefined1 *)(param_1 + 0x1d5c),*(undefined1 *)(param_1 + 0x1d5d),
               *(undefined1 *)(param_1 + 0x1d5e),*(undefined4 *)(param_1 + 0x1d70));
  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x432,"clUpdatePcieConfig_IMPL",1,
               "NVRM: Chipset %X Root Port Domain %X Bus %X Device %X Func %X PCIE PTR %X\n",
               *(undefined4 *)(param_2 + 0xb4),*(undefined4 *)(param_1 + 0x1d88),
               *(undefined1 *)(param_1 + 0x1d8c),*(undefined1 *)(param_1 + 0x1d8d),
               *(undefined1 *)(param_1 + 0x1d8e),*(undefined4 *)(param_1 + 0x1da0));
  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x439,"clUpdatePcieConfig_IMPL",1,
               "NVRM: Chipset %X Board Upstream Port Domain %X Bus %X Device %X Func %X PCIE PTR %X\n"
               ,*(undefined4 *)(param_2 + 0xb4),*(undefined4 *)(param_1 + 0x1db8),
               *(undefined1 *)(param_1 + 0x1dbc),*(undefined1 *)(param_1 + 0x1dbd),
               *(undefined1 *)(param_1 + 0x1dbe),*(undefined4 *)(param_1 + 0x1dd0));
  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x440,"clUpdatePcieConfig_IMPL",1,
               "NVRM: Chipset %X Board Downstream Port Domain %X Bus %X Device %X Func %X PCIE PTR %X\n"
               ,*(undefined4 *)(param_2 + 0xb4),*(undefined4 *)(param_1 + 0x1de8),
               *(undefined1 *)(param_1 + 0x1dec),*(undefined1 *)(param_1 + 0x1ded),
               *(undefined1 *)(param_1 + 0x1dee),*(undefined4 *)(param_1 + 0x1e00));
  nvDbg_Printf("src/kernel/platform/chipset/chipset_pcie.c",0x448,"clUpdatePcieConfig_IMPL",1,
               "NVRM: FHB Domain %X Bus %X Device %X Func %X VendorID %X DeviceID %X\n",
               *(undefined4 *)(param_2 + 0x98),*(undefined1 *)(param_2 + 0x9c),
               *(undefined1 *)(param_2 + 0x9d),*(undefined1 *)(param_2 + 0x9e),
               *(undefined2 *)(param_2 + 0xaa),*(undefined2 *)(param_2 + 0xa8));
  if ((*(char *)(param_1 + 0x46c) != '\0') &&
     (_objClAdjustTcVcMap(param_1,param_2,param_1 + 0x1d88), *(char *)(param_1 + 0x479) != '\0')) {
    _objClAdjustTcVcMap(param_1,param_2,param_1 + 0x1d58);
    return;
  }
  return;
}


// ===== 0047c790 clInitPcie_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 clInitPcie_IMPL(long param_1,undefined8 param_2)

{
  int iVar1;
  
  if (*(long *)(param_1 + 7000) == 0) {
    return 0x56;
  }
  iVar1 = (**(code **)(param_1 + 0x168))();
  if (iVar1 - 3U < 2) {
    clUpdatePcieConfig_IMPL(param_1,param_2);
    return 0;
  }
  return 0x56;
}


// ===== 0047c7f0 clFindPcieConfigSpaceBase_IMPL =====

undefined8 clFindPcieConfigSpaceBase_IMPL(long param_1,int param_2,byte param_3)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xc0);
  while( true ) {
    if (puVar1 == (undefined8 *)0x0) {
      return 0;
    }
    if (((*(int *)(puVar1 + 1) == param_2) && (*(byte *)((long)puVar1 + 0xc) <= param_3)) &&
       (param_3 <= *(byte *)((long)puVar1 + 0xd))) break;
    puVar1 = (undefined8 *)puVar1[2];
  }
  return *puVar1;
}


// ===== 0047c840 clFreePcieConfigSpaceBase_IMPL =====

void clFreePcieConfigSpaceBase_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xc0);
  while (lVar2 != 0) {
    lVar1 = *(long *)(lVar2 + 0x10);
    portMemFree(lVar2);
    lVar2 = lVar1;
  }
  *(undefined8 *)(param_1 + 0xc0) = 0;
  return;
}


// ===== 0047c890 clPcieGetRootGenSpeed_IMPL =====

undefined8 clPcieGetRootGenSpeed_IMPL(long param_1,undefined8 param_2,byte *param_3)

{
  byte bVar1;
  
  *param_3 = 0;
  if (*(long *)(param_1 + 0x1d90) != 0) {
    bVar1 = osPciReadDword(*(long *)(param_1 + 0x1d90),*(int *)(param_1 + 0x1da0) + 0xc);
    *param_3 = bVar1 & 0xf;
    return 0;
  }
  return 0xffff;
}


// ===== 0047c8e0 pciPbiAcquireMutex =====

undefined4 pciPbiAcquireMutex(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_2 + 0x10;
  if (param_2 == 0) {
    iVar3 = 0xc4;
  }
  iVar1 = osPciReadDword(param_1,iVar3);
  uVar2 = 0x17;
  if (iVar1 == 0) {
    osPciWriteDword(param_1,iVar3,0x15);
    iVar3 = osPciReadDword(param_1,iVar3);
    uVar2 = 0x17;
    if (iVar3 == 0x15) {
      uVar2 = 0;
    }
  }
  return uVar2;
}


// ===== 0047c940 pciPbiSendCommandWait =====

undefined8
pciPbiSendCommandWait
          (undefined8 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (param_2 == 0) {
    osPciWriteDword(param_1,0xbc,param_4);
    osPciWriteDword(param_1,0xb8,param_3);
    sVar1 = osPciReadWord(param_1,2);
    psVar6 = (short *)(ampere_devid_2 + 2);
    sVar2 = 0x2080;
    do {
      if (sVar2 == sVar1) goto LAB_0047c97d;
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    iVar9 = 100;
  }
  else {
    osPciWriteDword(param_1,param_2 + 8,param_4);
    osPciWriteDword(param_1,param_2 + 4,param_3);
LAB_0047c97d:
    iVar9 = 0x514;
  }
  iVar8 = 0;
  while( true ) {
    iVar7 = param_2 + 4;
    if (param_2 == 0) {
      iVar7 = 0xb8;
    }
    uVar3 = osPciReadDword(param_1,iVar7);
    if (((-1 < (int)uVar3) && (uVar3 = uVar3 & 0xff, uVar3 != 0)) && (1 < uVar3 - 2)) break;
    iVar8 = iVar8 + 1;
    osDelay(1);
    if (iVar8 == iVar9) {
      return 0x65;
    }
  }
  if (uVar3 != 6) {
    if (6 < uVar3) {
      uVar5 = 0xffff;
      if (uVar3 == 7) {
        uVar5 = 0x24;
      }
      return uVar5;
    }
    if (uVar3 != 1) {
      uVar5 = 0xffff;
      if (uVar3 == 5) {
        uVar5 = 0x24;
      }
      return uVar5;
    }
  }
  iVar9 = param_2 + 0xc;
  if (param_2 == 0) {
    iVar9 = 0xc0;
  }
  uVar4 = osPciReadDword(param_1,iVar9);
  *param_5 = uVar4;
  return 0;
}


// ===== 0047cad0 pciPbiCheck =====

undefined8 pciPbiCheck(undefined8 param_1,int param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    cVar1 = osPciReadByte(param_1,0xb4);
    if ((cVar1 == '\t') && (cVar1 = osPciReadByte(param_1,0xb6), cVar1 == '\x14')) {
      param_2 = 0xb7;
      goto LAB_0047cb2c;
    }
  }
  else {
    cVar1 = osPciReadByte();
    if ((cVar1 == '\t') && (cVar1 = osPciReadByte(param_1,param_2 + 2), cVar1 == '\x14')) {
      param_2 = param_2 + 3;
LAB_0047cb2c:
      cVar1 = osPciReadByte(param_1,param_2);
      uVar2 = 0;
      if (cVar1 != '\x01') {
        uVar2 = 0x56;
      }
      return uVar2;
    }
  }
  return 0x56;
}


// ===== 0047cb70 pciPbiReleaseMutex =====

void pciPbiReleaseMutex(undefined8 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 0x10;
  if (param_2 == 0) {
    iVar2 = 0xc4;
  }
  iVar1 = osPciReadDword(param_1,iVar2);
  if (iVar1 != 0x15) {
    nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x81,"pciPbiReleaseMutex",4,
                 "NVRM: Attempted to release PBI mutex that does not match client ID\n");
    nvAssertFailedNoLog(&DAT_00d8aa66,"src/kernel/platform/chipset/pci_pbi.c",0x83);
    return;
  }
  osPciWriteDword(param_1,iVar2,0);
  return;
}


// ===== 0047cbf0 pciPbiReadUuid =====

int pciPbiReadUuid(long param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 local_4c;
  byte local_4b;
  undefined1 local_48 [24];
  
  if ((param_2 == 0) || (param_1 == 0)) {
    return 0x1f;
  }
  iVar2 = 0x34;
  while( true ) {
    bVar1 = osPciReadByte(param_1,iVar2);
    uVar3 = (uint)bVar1;
    if (uVar3 == 0) break;
    iVar2 = pciPbiCheck(param_1,uVar3);
    if (iVar2 == 0) break;
    iVar2 = uVar3 + 1;
  }
  iVar2 = pciPbiCheck(param_1,uVar3);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x115,"pciPbiReadUuid",1,
                 "NVRM: Device does not support PBI\n");
    return 0x56;
  }
  iVar2 = pciPbiAcquireMutex(param_1,uVar3);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x11c,"pciPbiReadUuid",4,
                 "NVRM: Could not acquire pciPbi mutex\n");
    return 0x17;
  }
  iVar2 = pciPbiSendCommandWait(param_1,uVar3,0x80100000,0,&local_4c);
  if (iVar2 == 0) {
    puVar5 = local_48;
    uVar4 = 0;
    if ((local_4b & 8) != 0) {
      do {
        iVar2 = pciPbiSendCommandWait(param_1,uVar3,uVar4 | 0x8b100000,0x80,puVar5);
        if (iVar2 != 0) {
          nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x143,"pciPbiReadUuid",4,
                       "NVRM: Failure reading GID\n");
          goto LAB_0047ccff;
        }
        uVar4 = uVar4 + 0x10000;
        puVar5 = puVar5 + 4;
      } while (uVar4 != 0x40000);
      portMemCopy(param_2,0x10,local_48,0x10);
      goto LAB_0047ccff;
    }
    nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x134,"pciPbiReadUuid",1,
                 "NVRM: Device does not support PBI Execute Routine\n");
  }
  else {
    nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",299,"pciPbiReadUuid",1,
                 "NVRM: Device did not respond to PBI GET_CAPABILITIES\n");
  }
  iVar2 = 0x56;
LAB_0047ccff:
  pciPbiReleaseMutex(param_1,uVar3);
  return iVar2;
}


// ===== 0047ce50 pciPbiGetFeature =====

int pciPbiGetFeature(long param_1,long param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 == 0) || (param_1 == 0)) {
    return 0x1f;
  }
  iVar2 = 0x34;
  while( true ) {
    bVar1 = osPciReadByte(param_1,iVar2);
    uVar3 = (uint)bVar1;
    if (uVar3 == 0) break;
    iVar2 = pciPbiCheck(param_1,uVar3);
    if (iVar2 == 0) break;
    iVar2 = uVar3 + 1;
  }
  iVar2 = pciPbiCheck(param_1,uVar3);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x161,"pciPbiGetFeature",1,
                 "NVRM: Device does not support PBI\n");
    return 0x56;
  }
  iVar2 = pciPbiAcquireMutex(param_1,uVar3);
  if (iVar2 == 0) {
    iVar2 = pciPbiSendCommandWait(param_1,uVar3,0x8b100000,0x81,param_2);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x173,"pciPbiGetFeature",1,
                   "NVRM: Device did not provide PBI GET FEATURE, %0x\n");
    }
    pciPbiReleaseMutex(param_1,uVar3);
    return iVar2;
  }
  nvDbg_Printf("src/kernel/platform/chipset/pci_pbi.c",0x168,"pciPbiGetFeature",4,
               "NVRM: Could not acquire pciPbi mutex\n");
  return 0x17;
}


// ===== 0047cfd0 RmInitCpuInfo =====

undefined1  [16] RmInitCpuInfo(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char *pcVar2;
  byte bVar3;
  long lVar4;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 in_RAX;
  ulong uVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  char *pcVar14;
  char *pcVar15;
  uint uVar16;
  bool bVar17;
  byte bVar18;
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined8 uStack_c0;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  undefined1 local_7c [4];
  undefined1 local_78 [4];
  undefined1 local_74 [4];
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  uint local_4c;
  ushort local_48;
  ushort local_46;
  ushort local_44;
  byte local_42;
  byte local_41;
  byte local_40;
  byte local_3f;
  uint local_3c;
  
  lVar4 = g_pSys;
  bVar18 = 0;
  if (*(char *)(g_pSys + 0xb0) != '\0') {
    auVar19._8_8_ = param_3;
    auVar19._0_8_ = in_RAX;
    return auVar19;
  }
  lVar1 = g_pSys + 0xe4;
  *(undefined8 *)(g_pSys + 0xb4) = 0;
  pcVar2 = (char *)(lVar4 + 0xe4);
  *(undefined8 *)(lVar4 + 0xc0) = 0;
  *(undefined8 *)(lVar4 + 200) = 0;
  *(undefined8 *)(lVar4 + 0x120) = 0;
  portMemSet(lVar1,0,0x34);
  portMemSet(&local_5c,0,0x24);
  iVar7 = osNv_cpuid(0,0,&local_8c,&local_5c,&local_54,&local_58);
  if (iVar7 != 0) {
    osNv_cpuid(1,0,&local_8c,&local_88,&local_84,&local_80);
    uVar12 = local_8c >> 8 & 0xf;
    local_46 = (ushort)(local_8c >> 0x14) & 0xff;
    local_42 = (byte)local_8c >> 4;
    local_48 = (ushort)uVar12;
    bVar3 = (byte)(local_8c >> 0x10);
    local_41 = bVar3 & 0xf;
    if (local_48 == 0xf) {
      local_44 = local_46 + 0xf;
LAB_0047d3de:
      local_40 = local_42 + bVar3 * '\x10';
    }
    else {
      local_44 = local_48;
      local_40 = local_42;
      if ((0x8040UL >> uVar12 & 1) != 0) goto LAB_0047d3de;
    }
    local_3f = (byte)local_8c & 0xf;
    local_50 = local_80;
    local_3c = local_88 * 8 & 0x700 | local_88 & 0x1f;
    if ((local_80 & 0x800000) != 0) {
      *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 1;
    }
    if ((local_80 & 0x8000) != 0) {
      *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x800;
    }
    if ((local_80 & 0x80000) != 0) {
      *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x1000;
    }
    if (((local_80 & 0x2000000) != 0) &&
       (*(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x10, (local_80 & 0x1000000) != 0)) {
      uVar10 = osNv_rdcr4();
      if ((uVar10 & 0x200) == 0) {
        if ((((local_84 & 0x8000000) != 0) && (uVar10 = osNv_rdcr4(), (uVar10 & 0x40000) != 0)) &&
           (uVar10 = osNv_rdxcr0(), (uVar10 & 6) != 0)) goto LAB_0047d69d;
      }
      else {
        if (((local_84 & 0x8000000) == 0) || (uVar10 = osNv_rdcr4(), (uVar10 & 0x40000) == 0)) {
          bVar17 = false;
        }
        else {
          uVar10 = osNv_rdxcr0();
          bVar17 = (uVar10 & 6) != 0;
        }
        uVar12 = *(uint *)(lVar4 + 0xb8) | 10;
        if ((local_50 & 0x4000000) == 0) {
          uVar12 = *(uint *)(lVar4 + 0xb8) | 2;
        }
        *(uint *)(lVar4 + 0xb8) = uVar12;
        if ((local_84 & 1) != 0) {
          *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x4000;
        }
        if ((local_84 & 0x80000) != 0) {
          *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x20000;
        }
        if ((local_84 & 0x100000) != 0) {
          *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x40000;
        }
        if (bVar17) {
LAB_0047d69d:
          if ((local_84 & 0x10000000) != 0) {
            *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x80000;
          }
        }
      }
    }
    iVar7 = osNv_cpuid(7,0,&local_8c,&local_88,&local_84,&local_80);
    if ((iVar7 != 0) && ((local_88 & 0x200) != 0)) {
      *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x100000;
    }
    if ((local_50 & 0x10) != 0) {
      uVar9 = osGetCpuFrequency();
      *(undefined4 *)(lVar4 + 0xc0) = uVar9;
    }
    iVar7 = osNv_cpuid(0x80000000,0,&local_8c,&local_88,&local_84,&local_80);
    if (((iVar7 != 0) && (0x80000000 < local_8c)) &&
       (iVar7 = osNv_cpuid(0x80000001,0,&local_8c,&local_88,&local_84,&local_80), iVar7 != 0)) {
      local_4c = local_80;
      if (local_3c == 0) {
        local_3c = local_88 & 0xfff;
      }
    }
    *(undefined1 *)(lVar4 + 0x114) = 0;
    iVar7 = osNv_cpuid(0x80000000,0,&local_6c,&local_68,&local_64,&local_60);
    if ((iVar7 != 0) && (0x80000003 < local_6c)) {
      iVar7 = -0x7ffffffe;
      do {
        osNv_cpuid();
        iVar7 = iVar7 + 1;
      } while (iVar7 != -0x7ffffffb);
      pcVar13 = pcVar2;
      if (*(char *)(lVar4 + 0xe4) == ' ') {
        do {
          pcVar13 = pcVar13 + 1;
          pcVar15 = pcVar2;
        } while (*pcVar13 == ' ');
        do {
          pcVar14 = pcVar13 + (ulong)bVar18 * -2 + 1;
          *pcVar15 = *pcVar13;
          pcVar13 = pcVar14;
          pcVar15 = pcVar15 + (ulong)bVar18 * -2 + 1;
        } while (*pcVar14 != '\0');
      }
    }
    if (local_5c == 0x756e6547) {
      if ((local_58 != 0x49656e69) || (local_54 != 0x6c65746e)) goto LAB_0047d28f;
      if (local_48 == 5) {
        *(uint *)(lVar4 + 0xb4) = (local_42 == 4) + 1;
      }
      else if (local_48 == 6) {
        if (local_40 == 0xf) {
          iVar7 = 0x10;
        }
        else if (local_40 < 0x10) {
          if (local_40 == 5) {
            iVar7 = 5;
          }
          else if (local_40 < 6) {
            iVar7 = 3;
            if (local_40 != 1) {
              iVar7 = (uint)(local_40 != 3) * 4 + 4;
            }
          }
          else {
            iVar7 = 6;
            if (local_40 != 6) {
              iVar7 = (local_40 != 7) + 7;
            }
          }
        }
        else if (local_40 == 0x1c) {
          iVar7 = 0x13;
        }
        else if (local_40 < 0x1d) {
          iVar7 = 0x11;
          if ((local_40 != 0x16) && (iVar7 = 8, local_40 == 0x17)) {
            iVar7 = 0x12;
          }
        }
        else {
          iVar7 = 8;
          if (local_40 == 0x8f) {
            iVar7 = 0x14;
          }
        }
        *(int *)(lVar4 + 0xb4) = iVar7;
        if (6 < local_42) {
          *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x8000;
          goto LAB_0047dbed;
        }
      }
      else if (local_48 == 0xf) {
        *(undefined4 *)(lVar4 + 0xb4) = 9;
        if (local_42 < 2) {
          *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x100;
        }
LAB_0047dbed:
        iVar7 = osNv_cpuid(0x17,0,local_7c,local_78,local_74,&local_70);
        if (iVar7 != 0) {
          *(uint *)(lVar4 + 0x124) = local_70 >> 0x12 & 7;
        }
      }
      iVar7 = osNv_cpuid(0,0,&local_6c,&local_68,&local_64,&local_60);
      if ((iVar7 != 0) && (local_6c - 4 < 0x7ffffffc)) {
        iVar7 = 0;
        do {
          osNv_cpuid(4,iVar7,&local_6c,&local_68,&local_64,&local_60);
          if (iVar7 == 0) {
            *(uint *)(lVar4 + 0x120) = (local_6c >> 0x1a) + 1;
          }
          if ((local_6c & 0x1d) == 1) {
            iVar11 = (local_68 & 0xfff) + 1;
            *(int *)(lVar4 + 0xcc) = iVar11;
            uVar12 = ((local_68 >> 0x16) + 1) * iVar11 * (local_64 + 1) *
                     ((local_68 >> 0xc & 0x3ff) + 1) >> 10;
            if ((local_6c & 0xe0) == 0x20) {
              *(uint *)(lVar4 + 0xc4) = uVar12;
            }
            else if (*(uint *)(lVar4 + 200) < uVar12) {
              *(uint *)(lVar4 + 200) = uVar12;
            }
          }
          else if ((local_6c & 0x1f) == 0) break;
          iVar7 = iVar7 + 1;
        } while (iVar7 != 0x14);
      }
    }
    else if (((local_5c == 0x68747541) && (local_58 == 0x69746e65)) && (local_54 == 0x444d4163)) {
      local_6c = 0;
      local_68 = 0;
      local_64 = 0;
      local_60 = 0;
      if (local_48 == 5) {
        if (local_42 < 6) {
          *(undefined4 *)(lVar4 + 0xb4) = 0x30;
        }
        else if (local_42 < 8) {
          *(undefined4 *)(lVar4 + 0xb4) = 0x31;
        }
        else if (local_42 == 8) {
          *(undefined4 *)(lVar4 + 0xb4) = 0x32;
        }
        else if (local_42 == 9) {
          *(undefined4 *)(lVar4 + 0xb4) = 0x33;
        }
      }
      else if (local_48 == 6) {
        *(undefined4 *)(lVar4 + 0xb4) = 0x34;
      }
      else if (local_48 == 0xf) {
        osNv_cpuid(1,0,&local_6c,&local_68,&local_64,&local_60);
        uVar12 = (uint)((ushort)(local_6c >> 0x10) & 0xff0);
        uVar16 = local_6c >> 8 & 0xf | uVar12;
        local_48 = (ushort)uVar16;
        local_42 = (byte)(local_6c >> 0xc) & 0xf0 | (byte)(local_6c >> 4) & 0xf;
        uVar6 = local_48 & 0xff0;
        if (uVar6 == 0x20) {
          *(undefined4 *)(lVar4 + 0xb4) = 0x37;
        }
        else if (uVar6 < 0x21) {
          *(uint *)(lVar4 + 0xb4) = 0x36 - (uint)(uVar12 == 0);
        }
        else {
          if ((0x30 < (ushort)(uVar6 - 0x80)) ||
             ((0x1000100000001U >> ((ulong)(uVar6 - 0x80) & 0x3f) & 1) == 0)) {
            nvDbg_Printf("src/kernel/platform/cpu.c",0x59d,"cpuidInfoAMD",2,
                         "NVRM: Unrecognized AMD processor 0x%x in cpuidInfoAMD. Assuming new Ryzen\n"
                         ,uVar16);
          }
          *(undefined4 *)(lVar4 + 0xb4) = 0x38;
        }
      }
      if ((int)local_4c < 0) {
        *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 4;
      }
      if ((local_4c & 0x40000000) != 0) {
        *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x200;
      }
      if ((local_4c & 0x400000) != 0) {
        *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x410;
      }
      iVar7 = osNv_cpuid(0x80000000,0,&local_6c,&local_68,&local_64,&local_60);
      uVar12 = local_6c;
      if ((iVar7 != 0) && (0x80000005 < local_6c)) {
        iVar7 = osNv_cpuid(0x80000005,0,&local_6c,&local_68,&local_64,&local_60);
        if (iVar7 != 0) {
          *(uint *)(lVar4 + 0xcc) = local_64 & 0xff;
          *(uint *)(lVar4 + 0xc4) = local_64 >> 0x18;
        }
        iVar7 = osNv_cpuid(0x80000006,0,&local_6c,&local_68,&local_64,&local_60);
        if (iVar7 != 0) {
          *(uint *)(lVar4 + 200) = local_64 >> 0x10;
        }
        if (((0x8000001e < uVar12) &&
            (iVar7 = osNv_cpuid(0x8000001f,0,&local_6c,&local_68,&local_64,&local_60), iVar7 != 0))
           && ((local_6c & 2) != 0)) {
          *(undefined1 *)(lVar4 + 0x129) = 1;
          *(uint *)(lVar4 + 300) = local_64;
        }
      }
    }
    else {
LAB_0047d28f:
      if (*(char *)(lVar4 + 0xe4) == '\0') {
        portMemCopy(pcVar2,0xc,&local_5c,0xc);
      }
    }
    *(uint *)(lVar4 + 0x118) = (uint)local_44;
    *(byte *)(lVar4 + 0x128) = local_3f;
    *(uint *)(lVar4 + 0x11c) = (uint)local_40;
    *(ulong *)(lVar4 + 0xb8) = CONCAT44(local_3c,*(undefined4 *)(lVar4 + 0xb8)) & 0xfffffffffffff9fa
    ;
  }
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  uStack_c0 = 0x47d2ff;
  uVar8 = osGetCpuCount();
  uVar16 = uVar8;
  uVar12 = uVar8;
  if (local_5c != 0x756e6547) {
    if (((local_5c == 0x68747541) && (local_58 == 0x69746e65)) && (local_54 == 0x444d4163)) {
      uStack_c0 = 0x47d603;
      osNv_cpuid(1,0,&local_6c,&local_68,&local_64,&local_60);
      if (((local_60 & 0x10000000) != 0) && (uVar16 = local_68 >> 0x10 & 0xff, uVar16 < uVar8)) {
        uVar16 = uVar8;
      }
    }
    goto LAB_0047d336;
  }
  if ((local_58 != 0x49656e69) || (local_54 != 0x6c65746e)) goto LAB_0047d336;
  osNv_cpuid(0,0,&local_6c,&local_68,&local_64,&local_60);
  if (local_6c < 0xb) {
    uStack_c0 = 0x47d4ab;
    osNv_cpuid(1,0,&local_6c,&local_68,&local_64,&local_60);
    if ((local_60 & 0x10000000) == 0) goto LAB_0047d336;
LAB_0047da31:
    uStack_c0 = 0x47da55;
    osNv_cpuid(0,0,&local_6c,&local_68,&local_64,&local_60);
    if (3 < local_6c) {
      osNv_cpuid(4,0,&local_6c,&local_68,&local_64,&local_60);
      uVar12 = (local_6c >> 0x1a) + 1;
      uStack_c0 = 0x47dac2;
      osNv_cpuid(1,0,&local_6c,&local_68,&local_64,&local_60);
      if (uVar8 <= uVar12) {
        uVar12 = uVar8;
      }
      uVar16 = local_68 >> 0x10 & 0xff;
      if (uVar16 < uVar8) {
        uVar16 = uVar8;
      }
    }
  }
  else {
    osNv_cpuid(0xb,0,&local_6c,&local_68,&local_64,&local_60);
    uVar5 = local_68;
    uStack_c0 = 0x47d97b;
    osNv_cpuid(1,0,&local_6c,&local_68,&local_64,&local_60);
    if ((local_60 & 0x10000000) == 0) goto LAB_0047d336;
    if (uVar5 == 0) goto LAB_0047da31;
    osNv_cpuid(0xb,0,&local_6c,&local_68,&local_64,&local_60);
    uVar12 = local_68 & 0xffff;
    uStack_c0 = 0x47d9de;
    osNv_cpuid(0xb,1,&local_6c,&local_68,&local_64,&local_60);
    uVar12 = (local_68 & 0xffff) / uVar12;
    if (uVar8 < uVar12) {
      uVar12 = uVar8;
    }
    uVar16 = local_68 & 0xffff;
    if ((local_68 & 0xffff) <= uVar8) {
      uVar16 = uVar8;
    }
  }
  if (uVar12 == 0) {
    uVar12 = 1;
  }
  *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) | 0x10000;
LAB_0047d336:
  uVar10 = (ulong)uVar8;
  nvDbg_Printf("src/kernel/platform/cpu.c",0x3ac,"getCpuCounts",1,
               "NVRM: RmInitCpuCounts: physical 0x%x logical 0x%x\n");
  if ((((local_5c == 0x68747541) && (local_58 == 0x69746e65)) && (local_54 == 0x444d4163)) &&
     (local_44 == 0x17)) {
    uVar10 = 1;
    uVar12 = uVar16 >> 1;
    if (uVar16 < 4) {
      uVar12 = 1;
    }
  }
  *(uint *)(lVar4 + 0xd8) = uVar12;
  *(uint *)(lVar4 + 0xdc) = uVar8;
  *(uint *)(lVar4 + 0xe0) = uVar16;
  *(undefined8 *)(lVar4 + 0xd0) = 0x1000;
  *(undefined1 *)(lVar4 + 0xb0) = 1;
  auVar20._8_8_ = uStack_c0;
  auVar20._0_8_ = uVar10;
  return auVar20;
}


// ===== 0047de10 Nvidia_BR04_ShiftAliasingRegisters =====

undefined8 Nvidia_BR04_ShiftAliasingRegisters(undefined8 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar5 = osMapKernelSpace(param_1,0x1000,1,3);
  if (lVar5 == 0) {
    return 0xffff;
  }
  gpumgrGetGpuAttachInfo(0,&local_40);
  local_3c[0] = 0;
  uVar2 = *(uint *)(lVar5 + 0x18) >> 8 & 0xff;
  uVar7 = *(uint *)(lVar5 + 0x18) >> 0x10 & 0xff;
  do {
    do {
      lVar6 = gpumgrGetNextGpu(local_40,local_3c);
      if (lVar6 == 0) {
        local_3c[0] = 0;
        while( true ) {
          lVar6 = gpumgrGetNextGpu(local_40,local_3c);
          if (lVar6 == 0) break;
          if ((*(byte *)(lVar6 + 0x879) <= uVar7) && (uVar2 <= *(byte *)(lVar6 + 0x879))) {
            iVar8 = 0;
            while( true ) {
              iVar1 = iVar8 * 0x4000 + 0x18018;
              uVar3 = regRead032(lVar6 + 0x3a18,0,0,iVar1,0);
              uVar4 = regRead032(lVar6 + 0x3a18,0,0,iVar1);
              if (((uVar3 >> 8 & 0xff) != uVar2) || ((uVar4 >> 0x10 & 0xff) != uVar7)) {
                iVar8 = iVar8 * 0x4000 + 0x18000;
                *(int *)(lVar5 + 0x604) = iVar8;
                *(uint *)(lVar5 + 0x600) = iVar8 + *(int *)(lVar6 + 0x848) | 0x380;
                osDelay(1);
                goto LAB_0047dfcf;
              }
              if (iVar8 == 1) break;
              iVar8 = 1;
            }
          }
        }
LAB_0047dfcf:
        osUnmapKernelSpace(lVar5,0x1000);
        return 0;
      }
    } while ((*(byte *)(lVar6 + 0x879) < uVar2) || (uVar7 < *(byte *)(lVar6 + 0x879)));
    iVar8 = 0x18000;
    while( true ) {
      uVar3 = regRead032(lVar6 + 0x3a18,0,0,iVar8,0);
      if (uVar3 >> 0x14 != 0x5b) {
        *(int *)(lVar5 + 0x604) = iVar8;
        *(uint *)(lVar5 + 0x600) = *(int *)(lVar6 + 0x848) + iVar8 | 0x380;
        osDelay(1);
        local_3c[0] = 0;
        goto LAB_0047dfcf;
      }
      if (iVar8 != 0x18000) break;
      iVar8 = 0x1c000;
    }
  } while( true );
}


// ===== 0047e040 Nvidia_BR04_GetBar0.part.0 =====

ulong Nvidia_BR04_GetBar0_part_0(long param_1,long param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  long lVar12;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar6 = *(long *)(param_2 + 0x40);
  if (lVar6 == 0) {
LAB_0047e0b7:
    gpumgrGetGpuAttachInfo(0,&local_40);
    local_3c[0] = 0;
    while (lVar6 = gpumgrGetNextGpu(local_40,local_3c), lVar6 != 0) {
      bVar1 = (byte)((ulong)*(undefined8 *)(lVar6 + 0x878) >> 8);
      if (*(byte *)(param_2 + 0x1c) <= bVar1) {
        lVar10 = lVar6 + 0x3a18;
        lVar12 = 0x18000;
        if (bVar1 <= *(byte *)(param_2 + 0x1d)) {
          while( true ) {
            iVar5 = (int)lVar12;
            uVar3 = regRead032(lVar10,0,0,lVar12,0);
            if ((uVar3 >> 0x14 == 0x5b) &&
               (cVar2 = regRead032(lVar10,0,0,iVar5 + 0x18,0), *(char *)(param_2 + 0xc) == cVar2)) {
              uVar3 = regRead032(lVar10,0,0,iVar5 + 0x600,0);
              regWrite032(lVar10,0,0,iVar5 + 0x600,uVar3 & 0xffffff00 | 0x280,0);
              lVar6 = *(long *)(lVar6 + 0x848);
              *(long *)(param_2 + 0x40) = lVar6;
              return lVar12 + lVar6;
            }
            if (iVar5 != 0x18000) break;
            lVar12 = 0x1c000;
          }
        }
      }
    }
    local_3c[0] = 0;
    while (lVar6 = gpumgrGetNextGpu(local_40,local_3c), lVar6 != 0) {
      bVar1 = (byte)((ulong)*(undefined8 *)(lVar6 + 0x878) >> 8);
      if ((*(byte *)(param_2 + 0x1c) <= bVar1) && (bVar1 <= *(byte *)(param_2 + 0x1d))) {
        lVar10 = lVar6 + 0x3a18;
        iVar11 = 0;
        iVar5 = 6;
        while( true ) {
          while( true ) {
            uVar9 = (ulong)(uint)(iVar5 << 0xe);
            uVar3 = regRead032(lVar10,0,0,uVar9,0);
            if (uVar3 >> 0x14 != 0x5b) break;
            iVar4 = iVar11 * 0x4000;
            cVar2 = regRead032(lVar10,0,0,iVar4 + 0x18018,0);
            if (*(char *)(param_2 + 0xc) == cVar2) {
              uVar3 = regRead032(lVar10,0,0,iVar4 + 0x18600,0);
              regWrite032(lVar10,0,0,iVar4 + 0x18600,uVar3 & 0xffffff00 | 0x280,0);
              lVar6 = *(long *)(lVar6 + 0x848);
              *(long *)(param_2 + 0x40) = lVar6;
              return uVar9 + lVar6;
            }
            iVar4 = Nvidia_BR04_ShiftAliasingRegisters(*(long *)(lVar6 + 0x848) + uVar9);
            if (iVar4 != 0) {
              nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/platform/hwbc.c",0x510);
            }
          }
          if (iVar11 == 1) break;
          iVar11 = 1;
          iVar5 = 7;
        }
      }
    }
    uVar3 = osPciReadDword(*(undefined8 *)(param_2 + 0x10),0x10);
    uVar3 = uVar3 & 0xfffff000;
    if (uVar3 == 0) {
      if (((*(char *)(param_1 + 0x48) == '\0') || (*(long *)(param_1 + 0xc0) == 0)) ||
         (uVar9 = clFindPcieConfigSpaceBase_IMPL
                            (param_1,*(undefined4 *)(param_2 + 8),*(undefined1 *)(param_2 + 0xc)),
         0xfffffffe < uVar9 - 1)) goto LAB_0047e370;
      if (param_3 == -1) {
        uVar7 = (ulong)*(byte *)(param_2 + 0xc) << 0x14;
      }
      else {
        uVar7 = (ulong)(param_3 << 0xf | (*(byte *)(param_2 + 0xc) + 1) * 0x100000);
      }
      uVar9 = uVar9 | uVar7;
      iVar5 = Nvidia_BR04_ShiftAliasingRegisters(uVar9);
      if (iVar5 == 0) {
        return uVar9;
      }
      uVar8 = 0x54b;
    }
    else {
      uVar9 = (ulong)uVar3;
      if (param_3 != -1) {
        uVar9 = (ulong)(uint)((param_3 + 4) * 0x800) + (ulong)uVar3;
      }
      iVar5 = Nvidia_BR04_ShiftAliasingRegisters(uVar9);
      uVar8 = 0x529;
      if (iVar5 == 0) {
        return uVar9;
      }
    }
    nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/platform/hwbc.c",uVar8);
  }
  else {
    lVar10 = 0x18000;
    while( true ) {
      uVar9 = lVar6 + lVar10;
      lVar6 = osMapKernelSpace(uVar9,0x1000,1,3);
      if (lVar6 == 0) break;
      if (*(char *)(param_2 + 0xc) == (char)*(undefined4 *)(lVar6 + 0x18)) {
        osUnmapKernelSpace(lVar6,0x1000);
        if (param_3 == -1) {
          return uVar9;
        }
        return (uint)((param_3 + 4) * 0x800) + uVar9;
      }
      osUnmapKernelSpace(lVar6,0x1000);
      if (lVar10 != 0x18000) goto LAB_0047e0b7;
      lVar6 = *(long *)(param_2 + 0x40);
      lVar10 = 0x1c000;
    }
LAB_0047e370:
    uVar9 = 0;
  }
  return uVar9;
}


// ===== 0047e450 Plx_Pex8747_GetBar0.isra.0 =====

int Plx_Pex8747_GetBar0_isra_0(int *param_1)

{
  int iVar1;
  
  if (((param_1 == (int *)0x0) || (*param_1 != 3)) || (*(char *)((long)param_1 + 0xf) == '\0')) {
    nvDbg_Printf("src/kernel/platform/hwbc.c",0x801,"Plx_Pex8747_GetBar0",4,
                 "NVRM: Not a PLX PEX8747!\n");
    iVar1 = 0;
  }
  else {
    iVar1 = osPciReadDword(*(undefined8 *)(param_1 + 4),0x10);
    if (0xfffffffd < iVar1 - 1U) {
      nvDbg_Printf("src/kernel/platform/hwbc.c",0x813,"Plx_Pex8747_GetBar0",4,
                   "NVRM: Device has no BAR0!\n");
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ===== 0047e4e0 Plx_Pex8747_setupFunc.part.0.isra.0 =====

undefined8 Plx_Pex8747_setupFunc_part_0_isra_0(int *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = Plx_Pex8747_GetBar0_isra_0();
  if (lVar1 != 0) {
    lVar1 = osMapKernelSpace(lVar1,0x12000,1,3);
    if (lVar1 != 0) {
      if ((*(uint *)(lVar1 + 0x78) & 0xf0000) == 0x10000) {
        *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 0xffff;
        *(uint *)(lVar1 + 0x220) = *(uint *)(lVar1 + 0x220) | 0x10000;
        if (((param_1 == (int *)0x0) || (*param_1 != 3)) || (*(char *)((long)param_1 + 0xf) == '\0')
           ) {
          nvDbg_Printf("src/kernel/platform/hwbc.c",0x828,"Plx_Pex8747_ChangeUpstreamBusSpeed",4,
                       "NVRM: Not a PLX PEX8747!\n");
        }
        else {
          lVar2 = Plx_Pex8747_GetBar0_isra_0(param_1);
          if (lVar2 != 0) {
            lVar2 = osMapKernelSpace(lVar2,0x1000,1,3);
            if (lVar2 != 0) {
              if ((*(uint *)(lVar2 + 0x78) & 0xf0000) == 0x30000) {
                osUnmapKernelSpace(lVar2,0x1000);
                nvDbg_Printf("src/kernel/platform/hwbc.c",0x846,"Plx_Pex8747_ChangeUpstreamBusSpeed"
                             ,1,"NVRM: Already at Gen%u speed.  No need to transition.\n",3);
              }
              else {
                *(uint *)(lVar2 + 0x98) = *(uint *)(lVar2 + 0x98) & 0xfffffff0 | 3;
                *(uint *)(lVar2 + 0xf70) = *(uint *)(lVar2 + 0xf70) | 0x20000000;
                *(uint *)(lVar2 + 0x78) = *(uint *)(lVar2 + 0x78) | 0x20;
                osDelay(1);
                *(uint *)(lVar2 + 0xf70) = *(uint *)(lVar2 + 0xf70) & 0xdfffffff;
                if ((*(uint *)(lVar2 + 0x78) & 0xf0000) == 0x30000) {
                  osUnmapKernelSpace(lVar2,0x1000);
                }
                else {
                  osUnmapKernelSpace(lVar2,0x1000);
                  nvDbg_Printf("src/kernel/platform/hwbc.c",0x87b,
                               "Plx_Pex8747_ChangeUpstreamBusSpeed",4,
                               "NVRM: Failed to train to Gen%u speed.\n",3);
                }
              }
            }
          }
        }
      }
      if ((*(uint *)(lVar1 + 0x8074) & 0x800) != 0) {
        *(uint *)(lVar1 + 0x8078) = *(uint *)(lVar1 + 0x8078) | 2;
      }
      if ((*(uint *)(lVar1 + 0x9074) & 0x800) != 0) {
        *(uint *)(lVar1 + 0x9078) = *(uint *)(lVar1 + 0x9078) | 2;
      }
      if ((*(uint *)(lVar1 + 0x10074) & 0x800) != 0) {
        *(uint *)(lVar1 + 0x10078) = *(uint *)(lVar1 + 0x10078) | 2;
      }
      if ((*(uint *)(lVar1 + 0x11074) & 0x800) != 0) {
        *(uint *)(lVar1 + 0x11078) = *(uint *)(lVar1 + 0x11078) | 2;
      }
      osUnmapKernelSpace(lVar1,0x12000);
      return 0;
    }
  }
  return 0xffff;
}


// ===== 0047e750 objClFreeBr03Bar0.isra.0 =====

void objClFreeBr03Bar0_isra_0(long param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  
  if ((*param_2 != 1) || (*(char *)((long)param_2 + 0xf) == '\0')) {
    return;
  }
  cVar1 = osPciReadByte(*(undefined8 *)(param_2 + 4),8);
  if (cVar1 != -0x5f) {
    uVar2 = osPciReadDword(*(undefined8 *)(param_2 + 4),0x10);
    uVar2 = uVar2 & 0xfffff000;
    if (uVar2 != 0) goto LAB_0047e793;
  }
  if (*(char *)(param_1 + 0x48) == '\0') {
    return;
  }
  if (*(long *)(param_1 + 0xc0) == 0) {
    return;
  }
  lVar3 = clFindPcieConfigSpaceBase_IMPL(param_1,param_2[2],(char)param_2[3]);
  if (0xfffffffe < lVar3 - 1U) {
    return;
  }
  uVar2 = (uint)*(byte *)(param_2 + 3) << 0x14 | (uint)lVar3;
LAB_0047e793:
  lVar3 = osMapKernelSpace(uVar2,0x1000,1,3);
  if (lVar3 == 0) {
    return;
  }
  if ((*(uint *)(lVar3 + 0x600) & 1) != 0) {
    *(undefined4 *)(lVar3 + 0x600) = 0;
  }
  osUnmapKernelSpace(lVar3,0x1000);
  return;
}


// ===== 0047e830 objClResumeBridgeHWBC.isra.0 =====

undefined8 objClResumeBridgeHWBC_isra_0(int *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  do {
    if (*param_1 == 3) {
      if (*(char *)((long)param_1 + 0xf) == '\0') {
        return 0x1f;
      }
      iVar1 = Plx_Pex8747_setupFunc_part_0_isra_0(param_1);
      if (iVar1 != 0) {
        return 0xffff;
      }
    }
    if ((*(long *)(param_1 + 8) != 0) && (uVar2 = objClResumeBridgeHWBC_isra_0(), (int)uVar2 != 0))
    {
      return uVar2;
    }
    param_1 = *(int **)(param_1 + 10);
    if (param_1 == (int *)0x0) {
      return 0;
    }
  } while( true );
}


// ===== 0047e8b0 plxPex8747GetFirmwareInfo =====

void plxPex8747GetFirmwareInfo(void)

{
  return;
}


// ===== 0047e8c0 objClSetPcieHWBC =====

undefined8 objClSetPcieHWBC(long param_1,long param_2)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  undefined1 uVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  int *piVar10;
  long lVar11;
  uint *puVar12;
  long lVar13;
  int *piVar14;
  uint *puVar15;
  uint *puVar16;
  byte bVar17;
  short sVar18;
  byte bVar19;
  uint uVar20;
  ushort *puVar21;
  ushort *extraout_RDX;
  ushort *extraout_RDX_00;
  long *plVar22;
  uint uVar23;
  long *plVar24;
  ulong uVar25;
  undefined8 uVar26;
  long lVar27;
  char *pcVar28;
  int *piVar29;
  ulong uVar30;
  long *plVar31;
  int *piVar32;
  long *plVar33;
  bool bVar34;
  short *psVar35;
  short local_90;
  undefined1 local_8e [2];
  short local_8c;
  ushort local_8a;
  short local_88;
  undefined1 local_86 [2];
  undefined4 local_84;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  long local_68 [7];
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x1d5f) == '\0') {
      return 0;
    }
    if (*(short *)(param_1 + 0x1d86) == 0x10de || *(short *)(param_1 + 0x1d86) == 0x10b5) {
      if (*(ushort *)(param_1 + 0x1d84) == 0x1b3) {
        *(undefined1 *)(param_1 + 0x47a) = 1;
      }
      else if (*(ushort *)(param_1 + 0x1d84) >> 4 == 0x5b) {
        *(undefined1 *)(param_1 + 0x47b) = 1;
      }
      local_70 = *(long *)(param_1 + 0x1d60);
      uVar30 = *(ulong *)(param_1 + 0x1d58);
      plVar22 = (long *)(param_2 + 0x88);
      plVar31 = plVar22;
      if (*(int **)(param_2 + 0x88) == (int *)0x0) {
        piVar32 = (int *)0x0;
      }
      else {
        local_78._0_4_ = (int)uVar30;
        local_78._4_1_ = (byte)(uVar30 >> 0x20);
        piVar29 = *(int **)(param_2 + 0x88);
        piVar10 = (int *)0x0;
        do {
          while (((piVar32 = piVar29, piVar32[6] == (int)local_78 &&
                  (*(byte *)(piVar32 + 7) <= local_78._4_1_)) &&
                 (local_78._4_1_ <= *(byte *)((long)piVar32 + 0x1d)))) {
            if (*piVar32 == 1) {
              *(undefined1 *)(param_1 + 0x47a) = 1;
            }
            else if (*piVar32 == 2) {
              *(undefined1 *)(param_1 + 0x47b) = 1;
            }
            piVar29 = *(int **)(*plVar31 + 0x28);
            plVar31 = (long *)(*plVar31 + 0x28);
            piVar10 = piVar32;
            if (piVar29 == (int *)0x0) goto LAB_0047e9d0;
          }
          plVar31 = (long *)(piVar32 + 8);
          piVar14 = piVar32 + 8;
          piVar29 = *(int **)piVar14;
          piVar32 = piVar10;
        } while (*(int **)piVar14 != (int *)0x0);
      }
LAB_0047e9d0:
      piVar29 = (int *)0x0;
      local_78 = uVar30;
LAB_0047ea60:
      uVar30 = local_78;
      iVar7 = (int)local_78;
      cVar5 = local_78._4_1_;
      piVar10 = piVar29;
      if (((piVar32 == (int *)0x0) || (piVar32[6] != (int)local_78)) ||
         ((char)piVar32[7] != local_78._4_1_)) {
        if (local_78._7_1_ != '\0') {
          uVar26 = *(undefined8 *)(param_1 + 0x848);
          lVar9 = osPciInitHandle(local_78 & 0xffffffff,local_78._4_1_,local_78._5_1_,local_78._6_1_
                                  ,&local_8c,&local_8a);
          if (lVar9 != 0) {
            if (local_8c == 0x10b5) {
              if (local_8a == 0x8747) {
                piVar10 = (int *)portMemAllocNonPaged(0x58);
                if (piVar10 != (int *)0x0) {
                  portMemSet(piVar10,0,0x58);
                  piVar10[2] = iVar7;
                  *piVar10 = 3;
                  psVar35 = &local_8c;
                  lVar9 = clFindP2PBrdg_IMPL(param_2,uVar30 & 0xffffffff,cVar5,piVar10 + 3,
                                             (long)piVar10 + 0xd,(long)piVar10 + 0xe,psVar35,
                                             &local_8a);
                  *(long *)(piVar10 + 4) = lVar9;
                  if (lVar9 == 0) {
                    nvAssertFailedNoLog("pHWBC->ctrlDev.handle","src/kernel/platform/hwbc.c",0xf3,
                                        psVar35);
                  }
                  if ((local_8c != 0x10b5) || (local_8a != 0x8747)) {
                    nvAssertFailedNoLog("vendorID == PCI_VENDOR_ID_PLX && deviceID == PLX_DEVICE_ID_PEX8747"
                                        ,"src/kernel/platform/hwbc.c",0xf4);
                  }
                  sVar6 = osPciReadWord(*(undefined8 *)(piVar10 + 4),10);
                  if (sVar6 != 0x604) {
                    nvAssertFailedNoLog("osPciReadWord(pHWBC->ctrlDev.handle, PCI_COMMON_CLASS_SUBCLASS) == PCI_COMMON_CLASS_SUBBASECLASS_P2P"
                                        ,"src/kernel/platform/hwbc.c",0xf6);
                  }
                  cVar3 = osPciReadByte(*(undefined8 *)(piVar10 + 4),0x19);
                  if (cVar3 != cVar5) {
                    nvAssertFailedNoLog("osPciReadByte(pHWBC->ctrlDev.handle, PCI_TYPE_1_SECONDARY_BUS_NUMBER) == port.bus"
                                        ,"src/kernel/platform/hwbc.c",0xf9);
                  }
                  *(undefined1 *)((long)piVar10 + 0xf) = 1;
                  piVar10[6] = iVar7;
                  *(char *)(piVar10 + 7) = cVar5;
                  uVar4 = osPciReadByte(*(undefined8 *)(piVar10 + 4),0x1a);
                  *(int **)(piVar10 + 10) = piVar29;
                  *(undefined1 *)((long)piVar10 + 0x1d) = uVar4;
                  *(undefined1 *)(piVar10 + 0x12) = 0;
                  iVar7 = gpuGenerate32BitId(piVar10[2],(char)piVar10[3],
                                             *(byte *)((long)piVar10 + 0xd) |
                                             *(byte *)((long)piVar10 + 0xe));
                  piVar10[1] = iVar7;
                  goto LAB_0047ec19;
                }
                nvAssertFailedNoLog("(pHWBC != NULL)","src/kernel/platform/hwbc.c",0xe5);
                piVar10 = piVar29;
              }
            }
            else if (local_8c == 0x10de) {
              if (local_8a == 0x1b3) {
                piVar10 = (int *)portMemAllocNonPaged(0x58);
                if (piVar10 != (int *)0x0) {
                  portMemSet(piVar10,0,0x58);
                  piVar10[2] = iVar7;
                  *piVar10 = 1;
                  puVar21 = &local_8a;
                  lVar9 = clFindP2PBrdg_IMPL(param_2,uVar30 & 0xffffffff,cVar5,piVar10 + 3,
                                             (long)piVar10 + 0xd,(long)piVar10 + 0xe,&local_8c);
                  *(long *)(piVar10 + 4) = lVar9;
                  if (lVar9 == 0) {
                    nvAssertFailedNoLog("pHWBC->ctrlDev.handle","src/kernel/platform/hwbc.c",0x123);
                    puVar21 = extraout_RDX_00;
                  }
                  if ((local_8c != 0x10de) || (local_8a != 0x1b3)) {
                    nvAssertFailedNoLog("vendorID == PCI_VENDOR_ID_NVIDIA && deviceID == NV_BR03_XVU_DEV_ID_DEVICE_ID_BR03"
                                        ,"src/kernel/platform/hwbc.c",0x124);
                    puVar21 = extraout_RDX;
                  }
                  sVar6 = osPciReadWord(*(undefined8 *)(piVar10 + 4),10,puVar21);
                  if (sVar6 != 0x604) {
                    nvAssertFailedNoLog("osPciReadWord(pHWBC->ctrlDev.handle, PCI_COMMON_CLASS_SUBCLASS) == PCI_COMMON_CLASS_SUBBASECLASS_P2P"
                                        ,"src/kernel/platform/hwbc.c",0x125);
                  }
                  cVar3 = osPciReadByte(*(undefined8 *)(piVar10 + 4),0x19);
                  if (cVar3 != cVar5) {
                    nvAssertFailedNoLog("osPciReadByte(pHWBC->ctrlDev.handle, PCI_TYPE_1_SECONDARY_BUS_NUMBER) == port.bus"
                                        ,"src/kernel/platform/hwbc.c",0x126);
                  }
                  *(undefined1 *)((long)piVar10 + 0xf) = 1;
                  piVar10[6] = iVar7;
                  *(char *)(piVar10 + 7) = cVar5;
                  uVar4 = osPciReadByte(*(undefined8 *)(piVar10 + 4),0x1a);
                  *(int **)(piVar10 + 10) = piVar29;
                  *(undefined1 *)((long)piVar10 + 0x1d) = uVar4;
                  *(undefined8 *)(piVar10 + 0x10) = uVar26;
                  iVar7 = gpuGenerate32BitId(piVar10[2],(char)piVar10[3],
                                             *(byte *)((long)piVar10 + 0xd) |
                                             *(byte *)((long)piVar10 + 0xe));
                  piVar10[1] = iVar7;
                  if (*(char *)(param_2 + 0x49) != '\0') goto LAB_0047ec19;
                  local_84 = 1;
                  local_80 = 0;
                  if (((*piVar10 != 1) || (*(long *)(piVar10 + 4) == 0)) ||
                     (*(char *)((long)piVar10 + 0xf) == '\0')) goto LAB_0047ec19;
                  cVar5 = osPciReadByte(*(long *)(piVar10 + 4),8);
                  if (cVar5 == -0x5f) {
LAB_0047eeea:
                    if (((*(char *)(param_2 + 0x48) == '\0') || (*(long *)(param_2 + 0xc0) == 0)) ||
                       (lVar9 = clFindPcieConfigSpaceBase_IMPL(param_2,piVar10[2],(char)piVar10[3]),
                       0xfffffffe < lVar9 - 1U)) goto LAB_0047ec19;
                    uVar20 = (uint)*(byte *)(piVar10 + 3) << 0x14 | (uint)lVar9;
                  }
                  else {
                    uVar20 = osPciReadDword(*(undefined8 *)(piVar10 + 4),0x10);
                    uVar20 = uVar20 & 0xfffff000;
                    if (uVar20 == 0) goto LAB_0047eeea;
                  }
                  uVar30 = *(ulong *)(piVar10 + 0x10);
                  if ((uVar30 != 0) && (uVar30 >> 0x20 == 0)) {
                    lVar9 = osMapKernelSpace(uVar20,0x1000,1,3);
                    if (lVar9 != 0) {
                      if ((*(uint *)(lVar9 + 0x600) & 1) == 0) {
                        uVar20 = (int)uVar30 + 0x4fc000;
                        *(uint *)(lVar9 + 0x600) = uVar20 & 0xffffc000 | 1;
                        osUnmapKernelSpace(lVar9,0x1000);
                        if (uVar20 != 0) goto LAB_0047ef4c;
                      }
                      else {
                        osUnmapKernelSpace(lVar9,0x1000);
                      }
                    }
                    goto LAB_0047ec19;
                  }
LAB_0047ef4c:
                  lVar9 = osMapKernelSpace(uVar20,0x3000,1,3);
                  if (lVar9 == 0) goto LAB_0047ec19;
                  if (*(int *)(lVar9 + 0x340) == 0) {
                    bVar17 = 0;
                    lVar13 = 0;
                    bVar1 = 3;
                    do {
                      lVar11 = osPciInitHandle(piVar10[6],(char)piVar10[7],lVar13,0,&local_88,
                                               local_86);
                      if (lVar11 != 0) {
                        uVar20 = osPciReadDword(lVar11,0x70);
                        *(uint *)((long)&local_80 + lVar13 * 4) = uVar20 >> 0x14 & 0x3f;
                        uVar4 = osPciReadByte(lVar11,0x19);
                        local_88 = -1;
                        lVar11 = osPciInitHandle(piVar10[6],uVar4,0,0,&local_88,local_86);
                        if (lVar11 == 0) {
LAB_0047f01f:
                          bVar1 = bVar1 - 1;
                        }
                        else if (local_88 == 0x10de) {
                          bVar17 = bVar17 + 1;
                          *(undefined1 *)((long)&local_84 + lVar13 + 1) = 1;
                        }
                        else if (0xfffd < (ushort)(local_88 - 1U)) goto LAB_0047f01f;
                      }
                      if (lVar13 == 1) goto code_r0x0047f030;
                      lVar13 = 1;
                    } while( true );
                  }
                  pcVar28 = "NVRM: *** BR03 registers has already been programmed!\n";
                  uVar26 = 0x2c5;
LAB_0047fd0d:
                  nvDbg_Printf("src/kernel/platform/hwbc.c",uVar26,"objClSetupBR03",3,pcVar28);
                  goto LAB_0047f174;
                }
                nvAssertFailedNoLog("(pHWBC != NULL)","src/kernel/platform/hwbc.c",0x116);
                piVar10 = piVar29;
              }
              else if (local_8a >> 4 == 0x5b) {
                piVar10 = (int *)portMemAllocNonPaged(0x58);
                if (piVar10 != (int *)0x0) {
                  portMemSet(piVar10,0,0x58);
                  piVar10[2] = iVar7;
                  *piVar10 = 2;
                  lVar9 = clFindP2PBrdg_IMPL(param_2,uVar30 & 0xffffffff,cVar5,piVar10 + 3,
                                             (long)piVar10 + 0xd,(long)piVar10 + 0xe,&local_8c,
                                             &local_8a);
                  *(long *)(piVar10 + 4) = lVar9;
                  if (lVar9 == 0) {
                    nvAssertFailedNoLog("pHWBC->ctrlDev.handle","src/kernel/platform/hwbc.c",0x14c);
                  }
                  if ((local_8c != 0x10de) || (0xf < (ushort)(local_8a - 0x5b0))) {
                    nvAssertFailedNoLog("vendorID == PCI_VENDOR_ID_NVIDIA && deviceID >= NV_BR04_XVU_DEV_ID_DEVICE_ID_BR04_0 && deviceID <= NV_BR04_XVU_DEV_ID_DEVICE_ID_BR04_15"
                                        ,"src/kernel/platform/hwbc.c",0x14d);
                  }
                  sVar6 = osPciReadWord(*(undefined8 *)(piVar10 + 4),10);
                  if (sVar6 != 0x604) {
                    nvAssertFailedNoLog("osPciReadWord(pHWBC->ctrlDev.handle, PCI_COMMON_CLASS_SUBCLASS) == PCI_COMMON_CLASS_SUBBASECLASS_P2P"
                                        ,"src/kernel/platform/hwbc.c",0x150);
                  }
                  cVar3 = osPciReadByte(*(undefined8 *)(piVar10 + 4),0x19);
                  if (cVar3 != cVar5) {
                    nvAssertFailedNoLog("osPciReadByte(pHWBC->ctrlDev.handle, PCI_TYPE_1_SECONDARY_BUS_NUMBER) == port.bus"
                                        ,"src/kernel/platform/hwbc.c",0x153);
                  }
                  *(undefined1 *)((long)piVar10 + 0xf) = 1;
                  piVar10[6] = iVar7;
                  *(char *)(piVar10 + 7) = cVar5;
                  uVar4 = osPciReadByte(*(undefined8 *)(piVar10 + 4),0x1a);
                  *(int **)(piVar10 + 10) = piVar29;
                  *(undefined1 *)((long)piVar10 + 0x1d) = uVar4;
                  *(undefined1 *)(piVar10 + 0x12) = 0;
                  iVar7 = gpuGenerate32BitId(piVar10[2],(char)piVar10[3],
                                             *(byte *)((long)piVar10 + 0xd) |
                                             *(byte *)((long)piVar10 + 0xe));
                  piVar10[1] = iVar7;
                  *(int *)(param_2 + 0x90) = *(int *)(param_2 + 0x90) + 1;
                  goto LAB_0047ec19;
                }
                nvAssertFailedNoLog("(pHWBC != NULL)","src/kernel/platform/hwbc.c",0x13e);
                piVar10 = piVar29;
              }
              else {
                osPciInitHandle(uVar30 & 0xffffffff,cVar5,0,0,&local_8c,&local_8a);
              }
            }
          }
        }
      }
      else if (piVar29 != (int *)0x0) {
        *(int **)(piVar29 + 0xc) = piVar32;
      }
LAB_0047ec66:
      *plVar31 = (long)piVar10;
      local_70 = *(undefined8 *)(param_1 + 0x1d60);
      local_78 = *(undefined8 *)(param_1 + 0x1d58);
      piVar32 = *(int **)(param_2 + 0x88);
      do {
        if (piVar32 == (int *)0x0) {
          return 1;
        }
        while (((piVar32[6] == (int)local_78 && (*(byte *)(piVar32 + 7) <= local_78._4_1_)) &&
               (local_78._4_1_ <= *(byte *)((long)piVar32 + 0x1d)))) {
          if (*piVar32 == 2) {
            local_68[0] = 0;
            local_68[1] = 0;
            local_68[2] = 0;
            local_68[3] = 0;
            if (((*(long *)(piVar32 + 4) != 0) && (*(char *)((long)piVar32 + 0xf) != '\0')) &&
               ((lVar9 = Nvidia_BR04_GetBar0_part_0(param_2,piVar32,0xffffffff), lVar9 != 0 &&
                (puVar12 = (uint *)osMapKernelSpace(lVar9,0x1000,1,3), puVar12 != (uint *)0x0)))) {
              plVar31 = local_68;
              uVar30 = 0;
              do {
                plVar31[uVar30] = 0;
                if (((*piVar32 != 2) || (*(char *)((long)piVar32 + 0xf) == '\0')) ||
                   (lVar9 = Nvidia_BR04_GetBar0_part_0(param_2,piVar32,uVar30 & 0xffffffff),
                   lVar9 == 0)) {
LAB_0047f478:
                  if ((int)uVar30 != 0) {
                    uVar30 = (ulong)((int)uVar30 - 1);
                    do {
                      if (plVar31[uVar30] != 0) {
                        osUnmapKernelSpace(plVar31[uVar30],0x800);
                      }
                      uVar30 = uVar30 - 1;
                    } while ((int)uVar30 != -1);
                  }
                  osUnmapKernelSpace(puVar12,0x1000);
                  goto LAB_0047ecfb;
                }
                lVar9 = osMapKernelSpace(lVar9,0x800,1,3);
                plVar31[uVar30] = lVar9;
                if (lVar9 == 0) goto LAB_0047f478;
                uVar30 = uVar30 + 1;
              } while (uVar30 != 4);
              if ((puVar12[2] & 0xf0) == 0xa0) {
                uVar20 = puVar12[2] & 0xf;
                if (uVar20 == 1) {
                  nvDbg_Printf("src/kernel/platform/hwbc.c",0x61e,"Nvidia_BR04_setupFunc",1,
                               "NVRM: *** Set clock trims for BR04 A01.\n");
                  puVar12[0x341] = 0x10d4a0e8;
                  puVar12[0x342] = 0x12639cc8;
                  puVar12[0x343] = 0x107418e7;
                  puVar12[0x344] = 0x10c424c5;
                  puVar12[0x345] = 0x10953128;
                  puVar12[0x346] = 0x129;
                }
                else if ((uVar20 == 3) &&
                        (uVar20 = puVar12[0x2ad] & 0xfffffff0 | 8, puVar12[0x2ad] != uVar20)) {
                  puVar12[0x2ad] = uVar20;
                }
              }
              nvDbg_Printf("src/kernel/platform/hwbc.c",0x63e,"Nvidia_BR04_setupFunc",1,
                           "NVRM: *** Enabling BR04 Gen2 features.\n");
              uVar20 = puVar12[0x81] | 2;
              if (puVar12[0x81] != uVar20) {
                puVar12[0x81] = uVar20;
              }
              plVar33 = local_68 + 4;
              plVar24 = plVar31;
              do {
                lVar9 = *plVar24;
                uVar20 = *(uint *)(lVar9 + 0x90) & 0xfffffff0 | 2;
                if (*(uint *)(lVar9 + 0x90) != uVar20) {
                  *(uint *)(lVar9 + 0x90) = uVar20;
                  *(uint *)(lVar9 + 0x46c) = *(uint *)(lVar9 + 0x46c) | 2;
                }
                plVar24 = plVar24 + 1;
              } while (plVar24 != plVar33);
              osDelay(1);
              uVar20 = puVar12[899];
              if ((puVar12[0x2c2] >> 0x10 == 0x737) || (puVar12[0x2c2] >> 0x10 == 0x535)) {
                uVar8 = uVar20 & 0xff0fffff | 0x700000;
              }
              else {
                uVar8 = uVar20 & 0xff0fffff | 0xa00000;
              }
              if (uVar20 != uVar8) {
                puVar12[899] = uVar8;
              }
              uVar20 = puVar12[0x2ac];
              lVar9 = 0;
              do {
                while (((*(uint *)(plVar31[lVar9] + 0x18) != 0xffffffff &&
                        (lVar13 = osPciInitHandle(piVar32[6],
                                                  *(uint *)(plVar31[lVar9] + 0x18) >> 8 & 0xff,0,0,
                                                  &local_84,&local_80), lVar13 != 0)) &&
                       ((short)local_84 == 0x10de))) {
                  if (lVar9 == 2) {
                    uVar20 = uVar20 | 0x40000000;
                    lVar9 = 3;
                  }
                  else {
                    if (lVar9 == 3) {
                      uVar20 = uVar20 | 0x80000000;
                      goto LAB_0047f852;
                    }
                    if (lVar9 == 1) {
                      uVar20 = uVar20 | 0x20000000;
                      lVar9 = 2;
                    }
                    else {
                      uVar20 = uVar20 | 0x10000000;
                      lVar9 = 1;
                    }
                  }
                }
                lVar9 = lVar9 + 1;
              } while (lVar9 != 4);
LAB_0047f852:
              puVar12[0x2ac] = uVar20;
              uVar20 = puVar12[0x311] | 4;
              if (puVar12[0x311] != uVar20) {
                puVar12[0x311] = uVar20;
              }
              nvDbg_Printf("src/kernel/platform/hwbc.c",0x6b3,"Nvidia_BR04_setupFunc",1,
                           "NVRM: *** Setup BR04 upstream link speed.\n");
              if ((puVar12[0x311] & 0xf000) == 0x2000) {
                if ((puVar12[0x1c] & 0xf0000) == 0x20000) {
                  nvDbg_Printf("src/kernel/platform/hwbc.c",0x713,"Nvidia_BR04_setupFunc",1,
                               "NVRM: Already in Gen2 speed.  No need to transition.\n");
                  goto LAB_0047f9b1;
                }
                puVar12[0x24] = puVar12[0x24] & 0xfffffff0 | 2;
                bVar34 = (puVar12[0x1a] & 1) != 0;
                if (bVar34) {
                  puVar12[0x1a] = puVar12[0x1a] & 0xfffffffe;
                }
                uVar20 = puVar12[0x311];
                puVar12[0x311] = uVar20 & 0xfffff00f | 0x220;
                puVar12[0x311] = uVar20 & 0xfffff00f | 0x221;
                osDelay(1);
                if (((short)*puVar12 == 0x10de) && ((*puVar12 >> 0x10 | 0xf) == 0x5bf)) {
                  if ((puVar12[0x1c] & 0xf0000) == 0x20000) {
                    nvDbg_Printf("src/kernel/platform/hwbc.c",0x703,"Nvidia_BR04_setupFunc",1,
                                 "NVRM: Verified we are at Gen2 speed.\n");
                  }
                  else {
                    nvDbg_Printf("src/kernel/platform/hwbc.c",0x707,"Nvidia_BR04_setupFunc",4,
                                 "NVRM: Failed to train to Gen2 speed.\n");
                  }
                  if (bVar34) {
                    puVar12[0x1a] = puVar12[0x1a] | 1;
                  }
                  goto LAB_0047f9b1;
                }
                nvDbg_Printf("src/kernel/platform/hwbc.c",0x6f4,"Nvidia_BR04_setupFunc",4,
                             "NVRM: *** BR04 has fallen off the bus after we tried to train it to Gen2!\n"
                            );
              }
              else {
                nvDbg_Printf("src/kernel/platform/hwbc.c",0x719,"Nvidia_BR04_setupFunc",1,
                             "NVRM: *** Gen2 not supported by other side of link.\n");
LAB_0047f9b1:
                if ((puVar12[0x1c] & 3) != 0) {
                  puVar12[0x1c] = puVar12[0x1c] & 0xfffffffc;
                }
                uVar20 = puVar12[0x38b] | 0x700000;
                if (puVar12[0x38b] != uVar20) {
                  puVar12[0x38b] = uVar20;
                }
                uVar20 = puVar12[0x3c6] & 0xff8fffff | 0x400000;
                if (puVar12[0x3c6] != uVar20) {
                  puVar12[0x3c6] = uVar20;
                }
                if ((puVar12[0x300] & 0x1ff80000) != 0x1f480000) {
                  puVar12[0x300] = puVar12[0x300] & 0xe007ffff | 0x1f480000;
                  plVar24 = plVar31;
                  do {
                    lVar9 = *plVar24;
                    plVar24 = plVar24 + 1;
                    *(uint *)(lVar9 + 0x404) = *(uint *)(lVar9 + 0x404) & 0xfffffc00 | 0x3e9;
                    *(uint *)(lVar9 + 0x494) = *(uint *)(lVar9 + 0x494) & 0xfffff003 | 0xfa4;
                  } while (plVar24 != plVar33);
                }
                if (((puVar12[2] & 0xf0) == 0xa0) && (plVar24 = plVar31, (puVar12[2] & 0xf) == 3)) {
                  do {
                    uVar20 = *(uint *)(*plVar24 + 0x70);
                    uVar8 = uVar20 | 3;
                    if (uVar20 != uVar8) {
                      *(uint *)(*plVar24 + 0x70) = uVar8;
                    }
                    plVar24 = plVar24 + 1;
                  } while (plVar24 != plVar33);
                }
                if (puVar12[0xd8] == 0) {
                  if ((puVar12[0x260] & 1) != 0) {
                    puVar12[0x265] = 0xf0f0f0f0;
                    puVar12[0x264] = 0;
                  }
                  nvDbg_Printf("src/kernel/platform/hwbc.c",0x7a3,"Nvidia_BR04_setupFunc",1,
                               "NVRM: *** Setup BR04 registers.\n");
                  uVar20 = 0;
                  plVar24 = plVar31;
                  do {
                    uVar20 = (uVar20 + 1) - (uint)((*(uint *)(*plVar24 + 0x70) & 0x20000000) == 0);
                    plVar24 = plVar24 + 1;
                  } while (plVar24 != plVar33);
                  uVar8 = 0xf4;
                  uVar30 = (ulong)(~-(uint)(uVar20 < 3) & 0x6c);
                  do {
                    uVar20 = uVar8 - 0x18;
                    lVar9 = uVar30 * 2;
                    do {
                      lVar13 = 0;
                      uVar23 = uVar20;
                      do {
                        uVar25 = (ulong)uVar23;
                        lVar11 = lVar13 + lVar9;
                        uVar23 = uVar23 + 1;
                        lVar27 = lVar13 + lVar9;
                        lVar13 = lVar13 + 0x48;
                        puVar12[uVar25] =
                             (*(ushort *)(PortCreditsData_3 + lVar11) & 0x1ff) << 7 |
                             *(ushort *)(PortCreditsHeader_2 + lVar27) & 0x7f;
                      } while (lVar13 != 0xd8);
                      uVar20 = uVar20 + 4;
                      lVar9 = lVar9 + 2;
                    } while (uVar8 != uVar20);
                    uVar8 = uVar8 + 0x18;
                    uVar30 = uVar30 + 6;
                  } while (uVar8 != 0x184);
                  puVar12[0xd8] = 1;
                  puVar12[0x16c] = 0x666666;
                  puVar12[0x300] = puVar12[0x300] | 0x60000000;
                  plVar24 = plVar31;
                  do {
                    lVar9 = *plVar24;
                    plVar24 = plVar24 + 1;
                    *(uint *)(lVar9 + 0x400) = *(uint *)(lVar9 + 0x400) | 0x30000000;
                  } while (plVar24 != plVar33);
                }
                else if ((char)puVar12[0xd8] == '\0') {
                  puVar15 = puVar12 + 0x13c;
                  do {
                    *puVar15 = 0;
                    puVar16 = puVar15 + 4;
                    puVar15[1] = 0;
                    puVar15[2] = 0;
                    puVar15 = puVar16;
                  } while (puVar12 + 0x14c != puVar16);
                  puVar12[0xd8] = 1;
                  if ((char)puVar12[0xd8] == '\0') {
                    nvDbg_Printf("src/kernel/platform/hwbc.c",0x789,"Nvidia_BR04_setupFunc",4,
                                 "NVRM: *** BR04 WAR for bug 779279 is not working!\n");
                  }
                }
                else {
                  nvDbg_Printf("src/kernel/platform/hwbc.c",0x790,"Nvidia_BR04_setupFunc",3,
                               "NVRM: *** BR04 registers have already been programmed.\n");
                }
              }
              osUnmapKernelSpace(puVar12,0x1000);
              do {
                lVar9 = *plVar31;
                plVar31 = plVar31 + 1;
                osUnmapKernelSpace(lVar9,0x800);
              } while (plVar33 != plVar31);
            }
          }
          else if ((*piVar32 == 3) && (*(char *)((long)piVar32 + 0xf) != '\0')) {
            Plx_Pex8747_setupFunc_part_0_isra_0(piVar32);
          }
LAB_0047ecfb:
          piVar32 = *(int **)(*plVar22 + 0x28);
          plVar22 = (long *)(*plVar22 + 0x28);
          if (piVar32 == (int *)0x0) {
            return 1;
          }
        }
        plVar22 = (long *)(piVar32 + 8);
        piVar32 = *(int **)(piVar32 + 8);
      } while( true );
    }
  }
  return 0;
code_r0x0047f030:
  if (bVar17 == 0) {
    nvAssertFailedNoLog("total","src/kernel/platform/hwbc.c",0x2e3);
  }
  if (bVar1 == 2) {
    piVar14 = (int *)(lVar9 + 0x350);
    do {
      if (*piVar14 != 0) {
        pcVar28 = "NVRM: *** BR03 registers has already been programmed (one device workaround)!\n";
        uVar26 = 0x2ee;
        goto LAB_0047fd0d;
      }
      piVar14 = piVar14 + 1;
    } while (piVar14 != (int *)(lVar9 + 0x40c));
  }
  plVar33 = local_68;
  iVar7 = 0xc0;
  plVar24 = plVar33;
  do {
    lVar13 = 0;
    do {
      *(undefined4 *)((long)plVar24 + lVar13 * 4) =
           *(undefined4 *)(lVar9 + (ulong)(uint)(iVar7 + (int)lVar13) * 4);
      lVar13 = lVar13 + 1;
    } while (lVar13 != 3);
    iVar7 = iVar7 + 4;
    plVar24 = (long *)((long)plVar24 + 0xc);
  } while (iVar7 != 0xd0);
  nvDbg_Printf("src/kernel/platform/hwbc.c",0x303,"objClSetupBR03");
  lVar13 = 0;
  uVar20 = (uint)bVar17;
  do {
    if (*(char *)((long)&local_84 + lVar13) != '\0') {
      lVar11 = 0;
      bVar17 = 0;
      uVar8 = ((int)lVar13 + 3U & 3) * 0xc + 0xd4;
      do {
        if ((int)lVar13 != (int)lVar11) {
          if (*(char *)((long)&local_84 + lVar11) != '\0') {
            lVar27 = 0;
            puVar12 = (uint *)(lVar9 + (ulong)uVar8 * 4);
            do {
              uVar2 = *(undefined4 *)((long)plVar33 + lVar27 * 4);
              sVar6 = ((ushort)uVar2 & 0xff) - (ushort)bVar1;
              if (lVar27 == 1) {
                sVar6 = sVar6 + 1;
                bVar19 = 0;
                iVar7 = 0;
              }
              else {
                sVar18 = ((ushort)((uint)uVar2 >> 0x10) & 0xfff) + (ushort)bVar1 * -8;
                iVar7 = (int)sVar18;
                bVar19 = (byte)((ushort)sVar18 >> 0xf);
              }
              if ((sVar6 < 0) || (bVar19 != 0)) {
                nvAssertFailedNoLog("theader >= 0 && tdata >= 0","src/kernel/platform/hwbc.c",0x321)
                ;
              }
              lVar27 = lVar27 + 1;
              *puVar12 = (iVar7 / (int)uVar20 + (uint)((int)(uint)bVar17 < iVar7 % (int)uVar20) &
                         0xfff) << 0x10 |
                         (uint)((int)(uint)bVar17 < (int)sVar6 % (int)uVar20) +
                         (int)sVar6 / (int)uVar20 & 0xff;
              puVar12 = puVar12 + 1;
            } while (lVar27 != 3);
            bVar17 = bVar17 + 1;
          }
          uVar8 = uVar8 + 4;
        }
        lVar11 = lVar11 + 1;
      } while (lVar11 != 4);
    }
    lVar13 = lVar13 + 1;
    plVar33 = (long *)((long)plVar33 + 0xc);
  } while (lVar13 != 4);
  *(undefined4 *)(lVar9 + 0x340) = 1;
  *(undefined4 *)(lVar9 + 0x500) = 0x2040406;
  *(uint *)(lVar9 + 0xb00) = *(uint *)(lVar9 + 0xb00) | 0x60000000;
  *(uint *)(lVar9 + 0x1b00) = *(uint *)(lVar9 + 0x1b00) | 0x60000000;
  *(uint *)(lVar9 + 0x2b00) = *(uint *)(lVar9 + 0x2b00) | 0x60000000;
  if (((int)local_80 == 8) && (local_80._4_4_ == 8)) {
    *(uint *)(lVar9 + 0x1b00) = *(uint *)(lVar9 + 0x1b00) & 0xfffffc01 | 0x32;
    *(uint *)(lVar9 + 0x2b00) = *(uint *)(lVar9 + 0x2b00) & 0xfffffc01 | 0x30;
  }
LAB_0047f174:
  osUnmapKernelSpace(lVar9,0x3000);
  objClFreeBr03Bar0_isra_0(param_2,piVar10);
LAB_0047ec19:
  if (piVar29 != (int *)0x0) {
    *(int **)(piVar29 + 0xc) = piVar10;
  }
  if (*piVar10 == 1) {
    *(undefined1 *)(param_1 + 0x47a) = 1;
  }
  else if (*piVar10 == 2) {
    *(undefined1 *)(param_1 + 0x47b) = 1;
  }
  local_78 = CONCAT44(local_78._4_4_,piVar10[2]);
  local_70 = clFindP2PBrdg_IMPL(param_2,piVar10[2],(char)piVar10[3],(long)&local_78 + 4,
                                (long)&local_78 + 5,(long)&local_78 + 6,&local_90,local_8e);
  if ((local_70 == 0) || ((piVar29 = piVar10, local_90 != 0x10de && (local_90 != 0x10b5))))
  goto LAB_0047ec66;
  goto LAB_0047ea60;
}


// ===== 00480130 clResumeBridge_IMPL =====

undefined8 clResumeBridge_IMPL(long param_1)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  bool bVar5;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c [3];
  
  if (*(long *)(param_1 + 0x88) == 0) {
    return 0;
  }
  uVar4 = 0;
  bVar5 = true;
  local_2c[0] = 0;
  gpumgrGetGpuAttachInfo(local_34,&local_30);
  while( true ) {
    lVar2 = gpumgrGetNextGpu(local_30,local_2c);
    if (lVar2 == 0) {
      if (!bVar5) {
        return 0;
      }
      uVar3 = objClResumeBridgeHWBC_isra_0(*(undefined8 *)(param_1 + 0x88));
      return uVar3;
    }
    if (!bVar5) break;
    if (*(char *)(lVar2 + 0x444) == '\0') {
      cVar1 = gpuIsGpuFullPower_IMPL(lVar2);
      bVar5 = cVar1 == '\0';
    }
    else {
      uVar4 = uVar4 + 1;
      bVar5 = uVar4 < 2;
    }
  }
  return 0;
}


// ===== 00480200 getNbsiValue =====

undefined8
getNbsiValue(long param_1,uint param_2,short param_3,byte param_4,undefined4 *param_5,long param_6,
            uint *param_7,undefined4 *param_8)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  byte bVar10;
  ushort *puVar11;
  uint uVar12;
  uint *puVar13;
  int *piVar14;
  byte *pbVar15;
  int iVar16;
  undefined2 local_56;
  uint local_54;
  undefined8 local_50 [4];
  
  lVar7 = getNbsiObject();
  if (param_8 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pErrorCode","src/kernel/platform/nbsi/nbsi_getv.c",0x112);
  }
  if (param_7 == (uint *)0x0) {
    nvAssertFailedNoLog("pRetSize","src/kernel/platform/nbsi/nbsi_getv.c",0x113);
  }
  if ((*param_7 != 0) && (param_6 == 0)) {
    nvAssertFailedNoLog("!(*pRetSize != 0 && pRetBuf == NULL)",
                        "src/kernel/platform/nbsi/nbsi_getv.c",0x114);
  }
  *param_8 = 0xffffffff;
  if (param_1 == 0) {
    return 0xffff;
  }
  if (0x1f < *(uint *)(param_1 + 0x7a4)) {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_getv.c",0x121,"getNbsiValue",4,
                 "NVRM: Invalid gpu index %d. Aborting nbsi get value.\n");
    return 0xffff;
  }
  lVar7 = *(long *)(lVar7 + 0x80 + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (lVar7 == 0) {
    return 0x56;
  }
  if (*(short *)(lVar7 + 8) != 0x4452) {
    return 0;
  }
  uVar8 = 0;
  puVar11 = (ushort *)(lVar7 + 0x24);
  if (*(uint *)(lVar7 + 0x20) == 0) {
    return 0;
  }
  while ((*puVar11 != param_2 || (*(uint *)(puVar11 + 1) == 0xffffffff))) {
    uVar6 = (int)uVar8 + 1;
    uVar8 = (ulong)uVar6;
    puVar11 = puVar11 + 3;
    if (uVar6 == *(uint *)(lVar7 + 0x20)) {
      return 0;
    }
  }
  uVar9 = 0;
  puVar13 = (uint *)((ulong)*(uint *)(puVar11 + 1) + 0x26 + uVar8 * 6 + lVar7);
  if (*puVar13 == 0) {
    return 0;
  }
  sVar1 = (short)puVar13[1];
  psVar5 = (short *)((long)puVar13 + 10);
  while (sVar1 != param_3) {
    uVar6 = (int)uVar9 + 1;
    uVar9 = (ulong)uVar6;
    if (uVar6 == *puVar13) {
      return 0;
    }
    sVar1 = *psVar5;
    psVar5 = psVar5 + 3;
  }
  piVar14 = (int *)((long)puVar13 +
                   (ulong)*(uint *)((long)puVar13 + uVar9 * 6 + 6) + (uVar9 * 3 + 3) * 2);
  pbVar15 = (byte *)(piVar14 + 1);
  if (((param_4 != 0) && (local_50[0] = 0, param_4 != 1)) && (local_50[1] = 0, param_4 != 2)) {
    local_50[2] = 0;
  }
  iVar3 = *piVar14;
  for (iVar16 = 0; iVar16 != iVar3; iVar16 = iVar16 + 1) {
    bVar10 = *pbVar15;
    uVar6 = (uint)*(ushort *)(pbVar15 + 1) << 4 | (uint)(bVar10 >> 4);
    if (param_4 != 0) {
      lVar7 = 0;
      do {
        if ((param_5[lVar7] == uVar6) && (local_50[lVar7] = pbVar15, param_4 - 1 == (int)lVar7)) {
          iVar3 = iVar16 + 1;
          goto LAB_004803c0;
        }
        lVar7 = lVar7 + 1;
      } while ((byte)lVar7 < param_4);
    }
    bVar10 = bVar10 & 0xf;
    if (bVar10 == 3) {
      lVar7 = 0xb;
    }
    else if (bVar10 < 4) {
      lVar7 = 5;
      if (bVar10 != 1) {
        lVar7 = (ulong)(bVar10 == 2) * 3 + 4;
      }
    }
    else if (bVar10 == 4) {
      lVar7 = (ulong)pbVar15[3] + 4;
    }
    else {
      if (bVar10 != 5) {
        nvDbg_Printf("src/kernel/platform/nbsi/nbsi_getv.c",0x19c,"getNbsiValue",4,
                     "NVRM: Invalid NBSI table entry (1).\n");
        nvDbg_Printf("src/kernel/platform/nbsi/nbsi_getv.c",0x19e,"getNbsiValue",4,
                     "NVRM: Mod/Path/El=%x/%x/%x n/hash/typ=%d/%x/%d.\n",param_2,param_3,*param_5,
                     iVar16,uVar6,*pbVar15 & 0xf);
        return 0xffff;
      }
      lVar7 = (ulong)*(ushort *)(pbVar15 + 3) + 5;
    }
    pbVar15 = pbVar15 + lVar7;
  }
  if (param_4 == 0) {
    return 0;
  }
LAB_004803c0:
  param_4 = param_4 - 1;
  uVar8 = (ulong)param_4;
  pbVar15 = (byte *)local_50[uVar8];
  while (pbVar15 == (byte *)0x0) {
    param_4 = param_4 - 1;
    if (param_4 == 0xff) {
      return 0;
    }
    uVar8 = (ulong)param_4;
    pbVar15 = (byte *)local_50[uVar8];
  }
  uVar4 = param_5[uVar8];
  local_56 = 0;
  if ((*param_7 != 0) && (param_6 == 0)) {
    nvAssertFailedNoLog("!(*pRetSize != 0 && pRetBuf == NULL)",
                        "src/kernel/platform/nbsi/nbsi_getv.c",0x59);
  }
  *param_8 = 0xfffffffe;
  bVar10 = *pbVar15 & 0xf;
  if (bVar10 == 3) {
    if (7 < *param_7) {
      portMemCopy(param_6,8,pbVar15 + 3,8);
      *param_8 = 0;
    }
    uVar6 = 8;
    goto LAB_0048046b;
  }
  if (3 < bVar10) {
    if (bVar10 == 4) {
      uVar8 = (ulong)pbVar15[3];
      uVar6 = (uint)pbVar15[3];
      uVar12 = uVar6;
      if (*param_7 < uVar6) goto LAB_004806c0;
      portMemCopy(param_6,uVar8,pbVar15 + 4,uVar8);
      *param_8 = 0;
      if ((ulong)*param_7 < uVar8 + 2) goto LAB_0048046b;
    }
    else {
      if (bVar10 != 5) {
        *param_8 = 0xffffffff;
        nvDbg_Printf("src/kernel/platform/nbsi/nbsi_getv.c",0xc0,"rtnNbsiElement",4,
                     "NVRM: Invalid NBSI table entry (2)\n");
        nvDbg_Printf("src/kernel/platform/nbsi/nbsi_getv.c",0xc2,"rtnNbsiElement",4,
                     "NVRM: Mod/Path/Elem=%x/%x/%x, ndx=%d, type = %d.\n",param_2,param_3,uVar4,
                     iVar3,*pbVar15 & 0xf);
        return 0xffff;
      }
      uVar2 = *(ushort *)(pbVar15 + 3);
      uVar8 = (ulong)uVar2;
      uVar6 = (uint)uVar2;
      uVar12 = (uint)uVar2;
      if (*param_7 < uVar6) {
LAB_004806c0:
        *param_7 = uVar12 + 2;
        *param_8 = 0xfffffffe;
        return 0;
      }
      portMemCopy(param_6,uVar8,pbVar15 + 5,uVar8);
      *param_8 = 0;
      if ((ulong)*param_7 <= uVar8 + 2) goto LAB_0048046b;
    }
    uVar6 = (uint)uVar8;
    portMemCopy(param_6 + uVar8,local_56,&local_56,local_56);
    goto LAB_0048046b;
  }
  if (bVar10 == 1) {
    if (3 < *param_7) {
      local_54 = (uint)*(ushort *)(pbVar15 + 3);
LAB_004807db:
      puVar13 = &local_54;
LAB_004807a7:
      portMemCopy(param_6,4,puVar13,4);
      *param_8 = 0;
    }
  }
  else if (bVar10 == 2) {
    puVar13 = (uint *)(pbVar15 + 3);
    if (3 < *param_7) goto LAB_004807a7;
  }
  else if (3 < *param_7) {
    local_54 = (uint)pbVar15[3];
    goto LAB_004807db;
  }
  uVar6 = 4;
LAB_0048046b:
  *param_7 = uVar6;
  return 0;
}


// ===== 00480820 checkUidMatch =====

undefined8
checkUidMatch(long param_1,long param_2,undefined4 param_3,undefined2 param_4,undefined1 param_5,
             uint *param_6)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  byte bVar8;
  ushort uVar9;
  uint uVar10;
  undefined8 uVar11;
  short sVar12;
  short sVar13;
  char cVar14;
  undefined8 uVar15;
  bool bVar16;
  short local_40;
  short local_3c;
  
  uVar4 = *(uint *)(param_1 + 0x7fc);
  lVar7 = *(long *)(g_pSys + 0x210);
  uVar5 = *(uint *)(param_1 + 0x7f4);
  uVar6 = *(uint *)(param_1 + 0x800);
  uVar2 = *(ushort *)(lVar7 + 0x3da);
  bVar1 = *(byte *)(lVar7 + 0x3db);
  uVar10 = *(uint *)(lVar7 + 0x3d8) & 0xfffff;
  if (param_6 != (uint *)0x0) {
    *param_6 = 0;
  }
  cVar14 = (char)uVar6;
  sVar13 = (short)uVar4;
  sVar12 = (short)uVar5;
  if (param_2 == 0) {
    uVar10 = *(uint *)(lVar7 + 0x3d8) & 0xfffff;
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x235,"checkUidMatch",1,
                 "NVRM: NBSI current driver version: %d.%d.1%d.%d\n",*(byte *)(lVar7 + 0x3db) >> 4,
                 (char)(*(ushort *)(lVar7 + 0x3da) >> 4),(ulong)uVar10 / 10000,
                 (*(uint *)(lVar7 + 0x3d8) & 0xfffff) + (uVar10 / 10000) * -10000);
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x23c,"checkUidMatch",1,
                 "NVRM: NBSI Gpu%d ID info: svid=%x, ssid=%x, cvid=%x, cdid=%x, crev=%x\n",param_3,
                 sVar13,uVar4 >> 0x10,sVar12,uVar5 >> 0x10,uVar6 & 0xff);
    return 0;
  }
  local_3c = (short)(uVar5 >> 0x10);
  local_40 = (short)(uVar4 >> 0x10);
  if (*(short *)(param_2 + 0xe) != 0x100) {
    if (0xf < *(byte *)(param_2 + 0x1c)) {
      bVar1 = *(byte *)(param_2 + 0x1c);
    }
    bVar8 = *(byte *)(param_2 + 0x1b) >> 4;
    uVar9 = (*(byte *)(param_2 + 0x1c) & 0xf) << 4 | (ushort)bVar8;
    if ((*(byte *)(param_2 + 0x1c) & 0xf) == 0 && bVar8 == 0) {
      uVar9 = uVar2 >> 4;
    }
    uVar4 = *(uint3 *)(param_2 + 0x19) & 0xfffff;
    if ((*(uint3 *)(param_2 + 0x19) & 0xfffff) == 0) {
      uVar4 = uVar10;
    }
    uVar10 = uVar4;
    if (((*(byte *)(lVar7 + 0x3db) >> 4 != bVar1 >> 4) ||
        ((*(ushort *)(lVar7 + 0x3da) >> 4 & 0xff) != (uVar9 & 0xff))) ||
       (uVar10 < (*(uint *)(lVar7 + 0x3d8) & 0xfffff))) {
      uVar11 = 0;
      uVar10 = 0;
      uVar15 = 0;
      goto LAB_0048092c;
    }
    if (param_6 != (uint *)0x0) {
      *param_6 = uVar10;
    }
    sVar3 = *(short *)(param_2 + 0x14);
    if (*(short *)(param_2 + 0x10) == 0) {
      if (sVar13 != 0) goto LAB_00480a2e;
LAB_00480be2:
      if (sVar12 == sVar3) goto LAB_00480bf1;
LAB_00480a3d:
      uVar15 = 0;
      uVar11 = 0;
    }
    else {
      if (*(short *)(param_2 + 0x10) == sVar13) {
        if (((*(short *)(param_2 + 0x12) != local_40) || (*(short *)(param_2 + 0x12) == 0)) ||
           ((sVar3 != sVar12 || (sVar3 == 0)))) goto LAB_00480be2;
        if (((*(short *)(param_2 + 0x16) == local_3c) && (*(short *)(param_2 + 0x16) != 0)) &&
           ((*(char *)(param_2 + 0x18) == cVar14 && (*(char *)(param_2 + 0x18) != '\0')))) {
          uVar11 = 5;
          uVar15 = 5;
          goto LAB_0048092c;
        }
LAB_00480bf1:
        if (*(short *)(param_2 + 0x16) != local_3c) {
LAB_00480bff:
          uVar11 = 1;
          uVar15 = 1;
          goto LAB_0048092c;
        }
        if (*(char *)(param_2 + 0x18) == cVar14) {
          uVar11 = 4;
          uVar15 = 4;
          goto LAB_0048092c;
        }
      }
      else {
LAB_00480a2e:
        if (sVar12 != sVar3) goto LAB_00480a3d;
        if (local_3c != *(short *)(param_2 + 0x16)) goto LAB_00480bff;
      }
      bVar16 = cVar14 == *(char *)(param_2 + 0x18);
      uVar11 = 2;
      if (bVar16) {
        uVar11 = 3;
      }
      uVar15 = 2;
      if (bVar16) {
        uVar15 = 3;
      }
    }
    goto LAB_0048092c;
  }
  if (*(byte *)(param_2 + 0x1b) != 0) {
    uVar10 = (uint)*(byte *)(param_2 + 0x1c) + (uint)*(byte *)(param_2 + 0x1b) * 100;
  }
  sVar3 = *(short *)(param_2 + 0x14);
  if (*(short *)(param_2 + 0x10) == 0) {
    if (sVar13 != 0) goto LAB_004809ac;
LAB_00480bc0:
    uVar11 = 0;
    uVar15 = 0;
    if (sVar12 != sVar3) goto LAB_0048092c;
LAB_00480aa0:
    uVar11 = 1;
    uVar15 = 1;
    if (*(short *)(param_2 + 0x16) != local_3c) goto LAB_0048092c;
    if (*(char *)(param_2 + 0x18) == cVar14) {
      uVar11 = 4;
      uVar15 = 4;
      goto LAB_0048092c;
    }
  }
  else {
    if (*(short *)(param_2 + 0x10) == sVar13) {
      if ((((*(short *)(param_2 + 0x12) == 0) || (*(short *)(param_2 + 0x12) != local_40)) ||
          (sVar3 == 0)) || (sVar3 != sVar12)) goto LAB_00480bc0;
      if (((*(short *)(param_2 + 0x16) != 0) && (*(short *)(param_2 + 0x16) == local_3c)) &&
         ((*(char *)(param_2 + 0x18) == cVar14 && (*(char *)(param_2 + 0x18) != '\0')))) {
        uVar11 = 5;
        uVar15 = 5;
        goto LAB_0048092c;
      }
      goto LAB_00480aa0;
    }
LAB_004809ac:
    uVar11 = 0;
    uVar15 = 0;
    if (sVar12 != sVar3) goto LAB_0048092c;
    uVar11 = 1;
    uVar15 = 1;
    if (local_3c != *(short *)(param_2 + 0x16)) goto LAB_0048092c;
  }
  bVar16 = cVar14 == *(char *)(param_2 + 0x18);
  uVar11 = 2;
  if (bVar16) {
    uVar11 = 3;
  }
  uVar15 = 2;
  if (bVar16) {
    uVar15 = 3;
  }
LAB_0048092c:
  nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x2d2,"checkUidMatch",1,
               "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d object match score/ver = (%x/%d)\n",param_3,param_4
               ,param_5,uVar11,uVar10);
  return uVar15;
}


// ===== 00480cf0 getTableDataUsingAllObjectCall.constprop.0 =====

undefined8
getTableDataUsingAllObjectCall_constprop_0
          (undefined8 param_1,undefined4 param_2,uint *param_3,long param_4,uint param_5,
          uint param_6,uint *param_7)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint local_3c [3];
  
  uVar4 = *param_7;
  local_3c[0] = 0;
  if (param_5 < uVar4) {
    nvAssertFailedNoLog("!(*sizeToRead > outBufferSz)","src/kernel/platform/nbsi/nbsi_init.c",0x877)
    ;
    uVar4 = *param_7;
    if (param_5 < uVar4) {
      return 0xffff;
    }
  }
  *param_7 = 0;
  while( true ) {
    if (uVar4 == 0) {
      return 0;
    }
    *param_3 = param_6 >> 0xc;
    uVar3 = osCallACPI_DSM(param_1,param_2,0x203,param_3,local_3c);
    if ((int)uVar3 != 0) break;
    uVar1 = *param_7;
    uVar2 = param_6 & 0xfff;
    local_3c[0] = 0x1000 - uVar2;
    if (uVar2 + uVar4 < 0x1001) {
      local_3c[0] = uVar4;
    }
    if (param_5 < local_3c[0] + uVar1) {
      nvAssertFailedNoLog("(*sizeToRead+rtnSize)<=outBufferSz",
                          "src/kernel/platform/nbsi/nbsi_init.c",0x89d);
      uVar1 = *param_7;
    }
    portMemCopy((ulong)uVar1 + param_4,local_3c[0],(ulong)uVar2 + (long)param_3,local_3c[0]);
    *param_7 = *param_7 + local_3c[0];
    param_6 = param_6 + local_3c[0];
    uVar4 = uVar4 - local_3c[0];
  }
  return uVar3;
}


// ===== 00480e50 nbsiObjTypeCallUefi.constprop.0 =====

int nbsiObjTypeCallUefi_constprop_0
              (undefined8 param_1,undefined8 param_2,int param_3,byte param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 local_3c;
  undefined6 local_36;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 local_2c;
  char local_2a;
  undefined1 uStack_29;
  
  local_36 = 0x475f4953424e;
  local_3c = 0x1000;
  uStack_30 = 0x4f4c;
  uStack_2e = 0x5f42;
  local_2c = 0x3030;
  local_2a = 0x30;
  uStack_29 = 0;
  if (0xf < param_4) {
    nvAssertFailedNoLog("curGlob < 16","src/kernel/platform/nbsi/nbsi_init.c",0x6db);
    return 0x1f;
  }
  iVar1 = 0x56;
  if (param_3 == 0x4f50) {
    local_2c = 0x504f;
    local_2a = (-(param_4 < 10) & 0xf9U) + 0x37 + param_4;
    iVar1 = osGetUefiVariable(&local_36,NV_GUID_UEFI_VARIABLE,param_1,&local_3c);
    if (iVar1 == 0) {
      portMemCopy(param_2,local_3c,param_1,local_3c);
      *param_5 = local_3c;
      return 0;
    }
  }
  return iVar1;
}


// ===== 00480f50 nbsiObjTypeCallAcpi.constprop.0 =====

undefined8
nbsiObjTypeCallAcpi_constprop_0
          (undefined8 param_1,undefined4 param_2,uint *param_3,long param_4,uint param_5,int param_6
          ,byte param_7,uint *param_8)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  ushort local_3a [5];
  
  local_3a[0] = 0x1000;
  if (param_7 < 0x10) {
    uVar4 = *param_8;
    *param_8 = 0;
    if (uVar4 == 0) {
      uVar3 = 0;
    }
    else {
      uVar1 = 0;
      do {
        *param_3 = uVar1 >> 0xc & 0xfff | param_6 << 0x10 | (uint)param_7 << 0xc;
        uVar3 = osCallACPI_DSM(param_1,param_2,0x202,param_3,local_3a);
        if (local_3a[0] == 0) {
          return 0xffff;
        }
        if ((int)uVar3 != 0) {
          return uVar3;
        }
        if ((local_3a[0] == 4) && (*param_3 + 0x7fffffff < 5)) {
          return 0xffff;
        }
        uVar1 = *param_8;
        uVar2 = uVar4;
        if (local_3a[0] <= (ushort)uVar4) {
          uVar2 = (uint)local_3a[0];
        }
        uVar5 = uVar2 & 0xffff;
        if (param_5 < uVar1 + uVar5) {
          nvAssertFailedNoLog("(*sizeToRead+rtnSize)<=outBufferSz",
                              "src/kernel/platform/nbsi/nbsi_init.c",0x6aa);
          uVar1 = *param_8;
        }
        portMemCopy((ulong)uVar1 + param_4,uVar2 & 0xffff,param_3,uVar2 & 0xffff);
        uVar1 = *param_8 + uVar5;
        *param_8 = uVar1;
        uVar4 = uVar4 - uVar5;
      } while (uVar4 != 0);
      uVar3 = 0;
    }
  }
  else {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x68c,"nbsiObjTypeCallAcpi",2,
                 "NVRM: curGlob bits do not fit in 15:12. Returning early\n");
    uVar3 = 0x1f;
  }
  return uVar3;
}


// ===== 00481120 testNbsiTable.isra.0 =====

int testNbsiTable_isra_0
              (long *param_1,short param_2,ulong param_3,undefined4 param_4,undefined2 param_5,
              uint param_6,byte param_7,byte param_8,char param_9)

{
  short sVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("pNbsiGenObj","src/kernel/platform/nbsi/nbsi_init.c",0x1a0);
    if (param_6 != 0) {
      return 0xffff;
    }
LAB_004814c0:
    nvAssertFailedNoLog("allocSize","src/kernel/platform/nbsi/nbsi_init.c",0x1a1);
    return 0xffff;
  }
  if (param_6 == 0) goto LAB_004814c0;
  iVar4 = 0;
  uVar5 = param_3 & 0xffffffff;
  uVar2 = *(uint *)((long)param_1 + 10);
  if (uVar2 < 0x10) {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x1aa,"testNbsiTable",2,
                 "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d table size 0x%x < min 0x%x\n",param_4,param_5,
                 param_3,uVar2,0x10);
    uVar2 = *(uint *)((long)param_1 + 10);
    iVar4 = 0xffff;
  }
  if (uVar2 < 0x40001) {
    if ((param_7 & param_6 < uVar2) == 0) goto LAB_0048118f;
LAB_004811f8:
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x1be,"testNbsiTable",2,
                 "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d table size 0x%x > alloc 0x%x\n",param_4,param_5,
                 uVar5,uVar2,param_6);
    sVar1 = (short)param_1[1];
    if (sVar1 != 0x4452) goto joined_r0x00481243;
    uVar2 = *(uint *)(param_1 + 4);
    if (9 < uVar2) goto LAB_00481440;
    iVar4 = 0xffff;
    if (param_2 == 0x4452) {
      return 0xffff;
    }
LAB_004811a3:
    if (param_9 == '\0') goto LAB_004811b1;
  }
  else {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x1b4,"testNbsiTable",2,
                 "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d tbl size 0x%x > max 0x%x\n",param_4,param_5,uVar5
                 ,uVar2,0x40000);
    uVar2 = *(uint *)((long)param_1 + 10);
    iVar4 = 0xffff;
    if ((param_7 & param_6 < uVar2) != 0) goto LAB_004811f8;
LAB_0048118f:
    sVar1 = (short)param_1[1];
    if ((sVar1 != 0x4452) || (uVar2 = *(uint *)(param_1 + 4), uVar2 < 10)) {
      if (param_2 == sVar1) goto LAB_004811b1;
      goto LAB_004811a3;
    }
LAB_00481440:
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x1c9,"testNbsiTable",2,
                 "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d numModules %d > max %d\n",param_4,param_5,uVar5,
                 uVar2,9);
    sVar1 = (short)param_1[1];
joined_r0x00481243:
    if (param_2 == sVar1) {
      return 0xffff;
    }
    if (param_9 == '\0') {
      return 0xffff;
    }
    iVar4 = 0xffff;
  }
  nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x1d5,"testNbsiTable",2,
               "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d wantedGlobType = %04x != returned globtype = %04x\n"
               ,param_4,param_5,uVar5,param_2,sVar1);
  if (param_2 != 0x5049) {
    return 0xffff;
  }
  if ((short)param_1[1] != 0x4950) {
    return 0xffff;
  }
LAB_004811b1:
  if ((iVar4 == 0) && ((param_8 & 1) != 0)) {
    lVar3 = fnv1Hash64(param_1 + 1,*(int *)((long)param_1 + 10) + -8);
    iVar4 = 0;
    if (lVar3 != *param_1) {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xa3,"testObjectHash",2,
                   "NVRM: NBSI tbl computed hash %llx != hash %llx\n",lVar3,*param_1);
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x1f0,"testNbsiTable",2,
                   "NVRM: NBSI Gpu%d TLoc=%d/globType=%x bad hash\n",param_4,param_5,
                   (short)param_1[1]);
      iVar4 = 0x25;
    }
  }
  return iVar4;
}


// ===== 004814e0 testNbsiDir.isra.0 =====

undefined8 testNbsiDir_isra_0(undefined4 param_1,byte *param_2,uint param_3,ulong param_4)

{
  byte bVar1;
  uint uVar2;
  
  if (param_2 == (byte *)0x0) {
    nvAssertFailedNoLog("pNbsiDir","src/kernel/platform/nbsi/nbsi_init.c",0x149,param_4,param_3,
                        param_1);
    nvAssertFailedNoLog("pNbsiDir","src/kernel/platform/nbsi/nbsi_init.c",0x109);
    param_4 = param_4 & 0xffffffff;
  }
  if (*(int *)param_2 == 0x4e425349) {
    bVar1 = param_2[9];
    if (1 < bVar1) goto LAB_004815f8;
    uVar2 = param_2[8] + 10 + (uint)param_2[8];
    if (uVar2 <= param_3) {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x160,"testNbsiDir",1,
                   "NVRM: nbsi dir (new fmt) entries=%x, source=%x\n",param_2[8],param_4 & 0xffff);
      return 0;
    }
  }
  else {
    bVar1 = param_2[1];
    if (1 < bVar1) {
LAB_004815f8:
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x121,"getNbsiDirSize",2,
                   "NVRM: GPU%d, source %d, NBSI dir ver %d > max ver %d.\n",param_1,
                   param_4 & 0xffff,bVar1,1);
      return 0xffff;
    }
    uVar2 = *param_2 + 2 + (uint)*param_2;
    if (uVar2 <= param_3) {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x166,"testNbsiDir",1,
                   "NVRM: nbsi dir (old fmt) entries=%x, source=%x\n",*param_2,param_4 & 0xffff);
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x158,"testNbsiDir",2,
               "NVRM: GPU%d, source %d, Size of NBSI dir %x > alloc mem %x.\n",param_1,
               param_4 & 0xffff,uVar2,param_3);
  return 0xffff;
}


// ===== 004816a0 getNbsiObjByType =====

/* WARNING: Type propagation algorithm not settling */

int getNbsiObjByType(long param_1,short param_2,ushort *param_3,byte *param_4,uint param_5,
                    long param_6,uint *param_7,uint *param_8,int *param_9,uint param_10,int param_11
                    )

{
  byte *pbVar1;
  short sVar2;
  short *psVar3;
  uint uVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  long lVar14;
  byte *pbVar15;
  byte *pbVar16;
  ulong uVar17;
  long lVar18;
  uint uVar19;
  bool bVar20;
  byte bVar21;
  char *pcVar22;
  byte bVar23;
  byte bVar24;
  undefined8 uVar25;
  uint uVar26;
  short sVar27;
  ushort uVar28;
  uint uVar29;
  uint uVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  undefined1 auVar34 [16];
  uint *puVar35;
  uint local_f0;
  uint local_ec;
  uint local_e4;
  byte *local_e0;
  uint local_d8;
  uint local_d0;
  uint local_cc;
  ulong local_c0;
  byte local_b5;
  int local_b4;
  uint local_a4;
  uint local_5c;
  uint local_58;
  uint local_54;
  byte *local_50;
  undefined8 local_48;
  undefined4 local_40;
  
  local_48 = 0x10000800020001;
  lVar18 = *(long *)(g_pSys + 0x210);
  local_50 = (byte *)0x0;
  local_40 = 0x20;
  if (param_3 == (ushort *)0x0) {
    nvAssertFailedNoLog("pWantedGlobSource","src/kernel/platform/nbsi/nbsi_init.c",0xb0c);
  }
  if (param_4 == (byte *)0x0) {
    nvAssertFailedNoLog("pWantedGlobIdx","src/kernel/platform/nbsi/nbsi_init.c",0xb0d);
  }
  if (param_8 == (uint *)0x0) {
    nvAssertFailedNoLog("pTotalObjSize","src/kernel/platform/nbsi/nbsi_init.c",0xb0e);
  }
  if (param_9 == (int *)0x0) {
    nvAssertFailedNoLog("pRtnGlobStatus","src/kernel/platform/nbsi/nbsi_init.c",0xb0f);
  }
  if ((*param_7 != 0) && (param_6 == 0)) {
    nvAssertFailedNoLog("!(*pRtnObjSize != 0 && pRtnObj == NULL)",
                        "src/kernel/platform/nbsi/nbsi_init.c",0xb10);
  }
  if (param_1 == 0) {
    return 0xffff;
  }
  cVar5 = rmcfg_IsT234DorBetter(param_1);
  if (cVar5 != '\0') {
    return 0x56;
  }
  uVar19 = *(uint *)(param_1 + 0x7a4);
  if (0x1f < uVar19) {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xb1f,"getNbsiObjByType",2,
                 "NVRM: Invalid gpu index %d. Aborting NBSI get object.\n",uVar19);
    return 0xffff;
  }
  if (param_2 == -3) {
    local_54 = CONCAT22(local_54._2_2_,(short)*param_7);
    uVar10 = osCallACPI_DSM(param_1,param_10,param_5,param_6,&local_54);
    *param_7 = local_54 & 0xffff;
    *param_3 = uVar10;
    return 0;
  }
  bVar31 = param_10 == 3;
  bVar32 = param_10 == 0;
  bVar20 = bVar31 || bVar32;
  if (param_2 == 0x4452) {
    if (!bVar31 && !bVar32) goto LAB_004817de;
    if (param_3 == (ushort *)0x0) {
      nvAssertFailedNoLog("pWantedGlobSource","src/kernel/platform/nbsi/nbsi_init.c",0x531);
    }
    if (param_4 == (byte *)0x0) {
      nvAssertFailedNoLog("pWantedGlobIdx","src/kernel/platform/nbsi/nbsi_init.c",0x532);
    }
  }
  else {
    if (*param_4 == 1) {
      *param_4 = 0;
    }
    if (!bVar31 && !bVar32) goto LAB_004817de;
    if (param_3 == (ushort *)0x0) {
      nvAssertFailedNoLog("pWantedGlobSource","src/kernel/platform/nbsi/nbsi_init.c",0x531);
    }
  }
  if ((*param_7 != 0) && (param_6 == 0)) {
    nvAssertFailedNoLog("!(*pRtnObjSize != 0 && pRtnObj == NULL)",
                        "src/kernel/platform/nbsi/nbsi_init.c",0x534);
  }
  if (param_8 == (uint *)0x0) {
    nvAssertFailedNoLog("pTotalObjSize","src/kernel/platform/nbsi/nbsi_init.c",0x535);
  }
  if (param_9 == (int *)0x0) {
    nvAssertFailedNoLog("globTypeRtnStatus","src/kernel/platform/nbsi/nbsi_init.c",0x536);
  }
  lVar14 = *(long *)(g_pSys + 0x210);
  if (param_3 == (ushort *)0x0) {
    nvAssertFailedNoLog("pWantedGlobSource","src/kernel/platform/nbsi/nbsi_init.c",0x4b3);
  }
  if (param_4 == (byte *)0x0) {
    nvAssertFailedNoLog("pWantedGlobIndex","src/kernel/platform/nbsi/nbsi_init.c",0x4b4);
  }
  pbVar15 = *(byte **)(lVar14 + 0x1d8 + (ulong)uVar19 * 8);
  if ((pbVar15 != (byte *)0x0) && (*pbVar15 != 0)) {
    uVar17 = 0;
    do {
      psVar3 = *(short **)(pbVar15 + uVar17 * 8 + 8);
      if ((param_2 == *psVar3) && (lVar14 = *(long *)(psVar3 + 8), lVar14 != 0)) {
        uVar10 = *param_3;
        if ((psVar3[1] == uVar10) && (*(byte *)(psVar3 + 2) == *param_4)) {
          uVar19 = *(uint *)(lVar14 + 10);
          if (psVar3[1] == 0) {
            *param_3 = psVar3[3];
            bVar6 = *(byte *)(*(long *)(pbVar15 + (uVar17 & 0xffffffff) * 8 + 8) + 8);
          }
          else {
            bVar6 = *(byte *)(*(long *)(pbVar15 + (uVar17 & 0xffffffff) * 8 + 8) + 4);
          }
LAB_004823b2:
          *param_4 = bVar6;
          *param_8 = uVar19;
          if (uVar19 < param_5) {
            return 0x37;
          }
          iVar13 = -2;
          if (uVar19 - param_5 <= *param_7) {
            *param_7 = uVar19 - param_5;
            iVar13 = 0;
          }
          *param_9 = iVar13;
          uVar19 = *param_7;
          if (uVar19 == 0) {
            return 0;
          }
          portMemCopy(param_6,uVar19,lVar14 + (ulong)param_5,uVar19);
          return 0;
        }
        if ((uVar10 == psVar3[3]) && (*(byte *)(psVar3 + 4) == *param_4)) {
          uVar19 = *(uint *)(lVar14 + 10);
          *param_3 = uVar10;
          bVar6 = *(byte *)(*(long *)(pbVar15 + (uVar17 & 0xffffffff) * 8 + 8) + 8);
          goto LAB_004823b2;
        }
      }
      uVar17 = uVar17 + 1;
    } while (*pbVar15 != uVar17);
  }
  bVar20 = true;
LAB_004817de:
  local_c0 = (ulong)uVar19;
  lVar18 = lVar18 + local_c0 * 2;
  uVar28 = *(ushort *)(lVar18 + 0x98) | 0x11;
  *(ushort *)(lVar18 + 0x98) = uVar28;
  uVar10 = *param_3;
  if (uVar10 == 0) {
    uVar10 = 0x10;
    if ((param_10 < 0xe) && (uVar10 = 0x10, (0x2009UL >> ((ulong)(byte)param_10 & 0x3f) & 1) != 0))
    {
      uVar10 = uVar28;
    }
  }
  else if (param_10 < 0xe) {
    if ((0x2009UL >> ((ulong)(byte)param_10 & 0x3f) & 1) == 0) {
      uVar28 = 0xffff;
    }
    uVar10 = uVar10 & uVar28;
  }
  bVar31 = param_2 == 0x4452;
  local_b4 = 0;
  uVar28 = 1;
  local_a4 = 0xffff;
  sVar27 = 0;
  *param_9 = -1;
  do {
    uVar28 = uVar28 & uVar10;
    if (uVar28 == 0) {
      uVar17 = (ulong)(ushort)(sVar27 + 1);
LAB_004818a8:
      uVar28 = *(ushort *)((long)&local_48 + uVar17 * 2);
    }
    else {
      local_50 = (byte *)0x0;
      if ((uVar28 & 1) != 0) {
        local_54 = 0;
        osReadRegistryStringBase(param_1,"RMemNBSItable",0,&local_54);
        if (local_54 == 0) {
LAB_00481de0:
          local_a4 = 0xffff;
        }
        else {
          if (0x40000 < local_54) {
            nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x59a,"getNbsiDirFromRegistry",3,
                         "NVRM: Emulated NBSI table too big. 0x%x > than 0x%x!\n",local_54,0x40000);
            goto LAB_00481de0;
          }
          local_50 = (byte *)portMemAllocNonPaged(local_54);
          if (local_50 == (byte *)0x0) {
            nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x5a4,"getNbsiDirFromRegistry",3,
                         "NVRM: Can\'t allocate 0x%x mem for emulated NBSI table.\n",local_54);
            local_a4 = 0x51;
          }
          else {
            local_a4 = osReadRegistryBinary(param_1,"RMemNBSItable",local_50,&local_54);
            local_e0 = local_50;
            uVar12 = local_54;
            if (local_a4 == 0) {
              local_a4 = local_54;
              if ((uVar28 & 0x30) != 0) {
                uVar17 = (ulong)(ushort)(sVar27 + 1U);
                if (*(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2) != 0) {
                  local_a4 = 0x1f;
LAB_00482917:
                  portMemFree(local_50);
                  goto LAB_004818a8;
                }
                bVar32 = true;
                goto LAB_0048351a;
              }
              local_54 = 0;
              bVar6 = *param_4;
              if (local_50 == (byte *)0x0) {
                nvAssertFailedNoLog("pNbsiDir","src/kernel/platform/nbsi/nbsi_init.c",0x318);
              }
              iVar13 = testNbsiDir_isra_0(uVar19,local_e0,uVar12,uVar28);
              if (iVar13 != 0) {
                sVar2 = *(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1) * 2);
joined_r0x0048223d:
                if (sVar2 != 0) {
                  portMemFree(local_50);
LAB_00482250:
                  uVar17 = (ulong)(ushort)(sVar27 + 1);
                  local_a4 = 0xffff;
                  goto LAB_004818a8;
                }
                local_a4 = 0xffff;
LAB_00482c76:
                if (*param_9 != -6) {
                  *param_9 = -3;
                }
                goto LAB_00482a54;
              }
              if (param_2 == -2) {
                if (bVar20) {
                  *param_4 = 0;
                  *param_8 = uVar12;
                  if (uVar12 < param_5) goto LAB_00482dac;
                  bVar32 = true;
                  bVar20 = false;
                }
                else {
                  *param_8 = uVar12;
                  local_a4 = uVar12;
joined_r0x004829fa:
                  if (local_a4 < param_5) goto LAB_00482dac;
                  bVar32 = true;
                }
LAB_00482a10:
                local_a4 = local_a4 - param_5;
              }
              else {
                if (local_e0 == (byte *)0x0) {
                  nvAssertFailedNoLog("pNbsiDir","src/kernel/platform/nbsi/nbsi_init.c",0xc9);
                }
                if (*(int *)local_e0 == 0x4e425349) {
                  bVar24 = local_e0[8];
                  pbVar15 = local_e0 + 10;
                }
                else {
                  bVar24 = *local_e0;
                  pbVar15 = local_e0 + 2;
                }
                if (bVar24 == 0) {
LAB_004828ff:
                  uVar17 = (ulong)(ushort)(sVar27 + 1U);
                  local_a4 = 0;
                  if (*(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2) != 0)
                  goto LAB_00482917;
                  local_a4 = 0;
                  goto LAB_00482c76;
                }
                pbVar16 = pbVar15 + (ulong)bVar24 * 2;
                bVar21 = 0;
                do {
                  sVar2 = *(short *)pbVar15;
                  pbVar15 = pbVar15 + 2;
                  bVar21 = bVar21 + (param_2 == sVar2);
                } while (pbVar16 != pbVar15);
                if (bVar21 == 0) goto LAB_004828ff;
                if (*(int *)local_e0 == 0x4e425349) {
                  bVar7 = local_e0[9];
                  uVar26 = local_e0[8] + 10 + (uint)local_e0[8];
                }
                else {
                  bVar7 = local_e0[1];
                  uVar26 = *local_e0 + 2 + (uint)*local_e0;
                }
                if (1 < bVar7) {
                  nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x121,"getNbsiDirSize",2,
                               "NVRM: GPU%d, source %d, NBSI dir ver %d > max ver %d.\n",uVar19,
                               uVar28,bVar7,1);
                  sVar2 = *(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1) * 2);
                  goto joined_r0x0048223d;
                }
                pbVar15 = local_e0 + uVar26;
                bVar32 = bVar6 == 0;
                bVar23 = 1;
                bVar9 = 0;
                uVar26 = 0;
                local_ec = 0;
                local_ec._0_1_ = 0;
                local_e4 = 0;
                bVar7 = 0;
                local_e0 = (byte *)0x0;
                if (bVar24 != 0) {
                  do {
                    if (bVar21 <= bVar9) break;
                    bVar23 = bVar23 & param_11 != 1;
                    iVar13 = testNbsiTable_isra_0
                                       (pbVar15,param_2,uVar26,uVar19,uVar28,uVar12,1,bVar23,0);
                    if (iVar13 != 0) {
                      if (iVar13 == 0x25) {
                        uVar17 = (ulong)(ushort)(sVar27 + 1U);
                        *param_9 = -6;
                        if (*(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2) != 0) {
                          local_a4 = 0x25;
                          goto LAB_00482917;
                        }
                        bVar32 = true;
                        local_a4 = 0x25;
                        goto LAB_00482c08;
                      }
                      uVar17 = (ulong)(ushort)(sVar27 + 1);
                      if (*(short *)((long)&local_48 + uVar17 * 2) != 0) {
                        local_a4 = 0xffff;
                        goto LAB_00482917;
                      }
                      bVar32 = true;
                      local_a4 = 0xffff;
                      goto LAB_00482c08;
                    }
                    if ((param_2 == *(short *)(pbVar15 + 8)) &&
                       ((bVar9 = bVar9 + 1, bVar6 == bVar9 || (bVar32)))) {
                      local_b5 = (byte)uVar26;
                      if ((*(short *)(pbVar15 + 8) != 0x4452) || (!bVar32)) {
                        if (((local_e0 != (byte *)0x0) && (bVar32)) && (bVar31)) goto LAB_00481c9e;
                        local_a4 = *(uint *)(pbVar15 + 10);
                        if (bVar20) {
                          bVar20 = false;
                          bVar32 = true;
                          local_e0 = pbVar15;
                          goto joined_r0x00482868;
                        }
                        bVar32 = true;
                        bVar20 = false;
                        local_e0 = pbVar15;
                        goto LAB_004828c6;
                      }
                      bVar8 = checkUidMatch(param_1,pbVar15,uVar19,uVar28,uVar26 & 0xff,&local_54);
                      if ((bVar8 != 0) &&
                         ((bVar7 < bVar8 || ((bVar8 == bVar7 && (local_e4 < local_54)))))) {
                        local_e4 = local_54;
                        local_ec = uVar26 & 0xff;
                        local_e0 = pbVar15;
                        bVar7 = bVar8;
                      }
                    }
                    uVar26 = uVar26 + 1;
                    pbVar15 = pbVar15 + *(uint *)(pbVar15 + 10);
                  } while (bVar24 != uVar26);
                }
                if (((local_e0 == (byte *)0x0) || (!bVar32)) || (!bVar31)) goto LAB_004828ff;
LAB_00481c9e:
                nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x3ab,"extractNBSIObjFromDir",1,
                             "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d best fit (score/ver = (%x/%d))\n",
                             uVar19,uVar28,(byte)local_ec,bVar7,local_e4);
                local_a4 = *(uint *)(local_e0 + 10);
                if (!bVar20) {
                  *param_8 = local_a4;
                  goto joined_r0x004829fa;
                }
                local_b5 = (byte)local_ec;
                bVar20 = false;
                bVar6 = *param_4;
                bVar32 = true;
                uVar10 = *param_3;
                lVar18 = *(long *)(g_pSys + 0x210);
LAB_0048289b:
                pbVar15 = *(byte **)(lVar18 + 0x1d8 + local_c0 * 8);
                if ((pbVar15 == (byte *)0x0) || (bVar24 = *pbVar15, pbVar15[1] <= bVar24)) {
LAB_004828c6:
                  *param_8 = local_a4;
                  if (local_a4 < param_5) {
                    if (bVar20) goto LAB_00482ca9;
joined_r0x00482da6:
                    if (!bVar32) {
                      return 0x37;
                    }
LAB_00482dac:
                    portMemFree(local_50);
                    return 0x37;
                  }
                  goto LAB_00482a10;
                }
                lVar18 = portMemAllocNonPaged(0x18);
                *(long *)(pbVar15 + (ulong)bVar24 * 8 + 8) = lVar18;
                if (lVar18 == 0) {
                  uVar19 = 0x18;
                  uVar25 = 0x431;
LAB_00483450:
                  nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",uVar25,"addNbsiCacheEntry",3,
                               "NVRM: Unable to alloc 0x%x mem for NBSI cache entry\n",uVar19);
                  goto LAB_004828c6;
                }
                uVar25 = portMemAllocNonPaged(local_a4);
                *(undefined8 *)(lVar18 + 0x10) = uVar25;
                if (*(long *)(*(long *)(pbVar15 + (ulong)bVar24 * 8 + 8) + 0x10) == 0) {
                  uVar25 = 0x43c;
                  uVar19 = local_a4;
                  goto LAB_00483450;
                }
                portMemCopy(*(long *)(*(long *)(pbVar15 + (ulong)bVar24 * 8 + 8) + 0x10),local_a4,
                            local_e0,local_a4);
                **(undefined2 **)(pbVar15 + (ulong)bVar24 * 8 + 8) = *(undefined2 *)(local_e0 + 8);
                *(ushort *)(*(long *)(pbVar15 + (ulong)bVar24 * 8 + 8) + 2) = uVar10;
                *(byte *)(*(long *)(pbVar15 + (ulong)bVar24 * 8 + 8) + 4) = bVar6;
                *(ushort *)(*(long *)(pbVar15 + (ulong)bVar24 * 8 + 8) + 6) = uVar28;
                *(byte *)(*(long *)(pbVar15 + (ulong)bVar24 * 8 + 8) + 8) = local_b5;
                *pbVar15 = bVar24 + 1;
                *param_8 = local_a4;
                if (local_a4 < param_5) {
                  if (bVar20) {
                    portMemFree(local_e0);
                  }
                  goto joined_r0x00482da6;
                }
                local_a4 = local_a4 - param_5;
              }
              iVar13 = -2;
              if (local_a4 <= *param_7) {
                *param_7 = local_a4;
                iVar13 = 0;
              }
              *param_9 = iVar13;
              uVar19 = *param_7;
              if (uVar19 == 0) {
                local_a4 = 0;
                if (bVar20) goto LAB_00482cae;
              }
              else {
                portMemCopy(param_6,uVar19,local_e0 + param_5,uVar19);
                if (!bVar20) {
                  if (!bVar32) {
                    return 0;
                  }
                  portMemFree(local_50);
                  return 0;
                }
                local_a4 = 0;
LAB_00482cae:
                portMemFree(local_e0);
              }
              goto LAB_00482a47;
            }
            nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x5b1,"getNbsiDirFromRegistry",3,
                         "NVRM: Unable to read emulated NBSI table from reg.\n");
            portMemFree(&local_50);
          }
        }
LAB_00481d56:
        uVar17 = (ulong)(ushort)(sVar27 + 1U);
        *(ushort *)(lVar18 + 0x98) = *(ushort *)(lVar18 + 0x98) & ~uVar28;
        if (*(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2) == 0) {
          *param_9 = -3;
          return local_a4;
        }
        goto LAB_004818a8;
      }
      if ((uVar28 & 10) != 0) {
LAB_00481d50:
        local_a4 = 0x56;
        goto LAB_00481d56;
      }
      bVar32 = false;
      if ((uVar28 & 0x10) != 0) {
        local_58 = 0x202;
        local_5c = param_10;
        local_54 = 0x203;
        local_a4 = getDsmGetObjectSubfunction(param_1,&local_5c,&local_58,&local_54);
        local_b4 = 0;
        if (local_a4 == 0) {
          local_a4 = testIfDsmSubFunctionEnabled(param_1,local_5c,0);
          if (local_a4 == 0) {
            iVar13 = testIfDsmSubFunctionEnabled(param_1,local_5c,local_58);
            iVar11 = testIfDsmSubFunctionEnabled(param_1,local_5c,local_54);
            local_b4 = 0;
            if (iVar13 != 0 && iVar11 != 0) goto LAB_00481d50;
            bVar33 = false;
            if (iVar13 != 0 || iVar11 != 0) {
              if (iVar13 != 0) {
                if (iVar11 != 0) {
                  if (uVar28 != 0x10) goto LAB_00481eb2;
                  if (*(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1) * 2) == 0) {
                    if (*param_9 != -6) {
                      *param_9 = -3;
                      return 0xffff;
                    }
                    return 0xffff;
                  }
                  goto LAB_00482250;
                }
                local_b4 = 2;
                goto joined_r0x00481eac;
              }
              if (uVar28 == 0x10) {
                local_b4 = 1;
                bVar33 = true;
                goto LAB_00481903;
              }
              uVar17 = (ulong)(ushort)(sVar27 + 1);
              if (*(short *)((long)&local_48 + uVar17 * 2) == 0) goto LAB_0048351a;
              local_b4 = 1;
              goto LAB_00481ec9;
            }
            local_b4 = 3;
joined_r0x00481eac:
            if (uVar28 != 0x10) goto LAB_00481eb2;
            goto LAB_00481903;
          }
          local_b4 = 0;
        }
        goto LAB_00481d56;
      }
      if ((uVar28 & 0x20) == 0) goto LAB_00481de0;
      if ((uVar28 - 0x10 & 0xffef) != 0) {
LAB_00481eb2:
        uVar17 = (ulong)(ushort)(sVar27 + 1);
        if (*(short *)((long)&local_48 + uVar17 * 2) != 0) {
LAB_00481ec9:
          local_a4 = 0x1f;
          goto LAB_004818a8;
        }
LAB_0048351a:
        local_a4 = 0x1f;
LAB_00482c08:
        if (*param_9 != -6) {
          *param_9 = -3;
        }
LAB_00482a47:
        if (!bVar32) {
          return local_a4;
        }
LAB_00482a54:
        portMemFree(local_50);
        return local_a4;
      }
      bVar33 = true;
LAB_00481903:
      bVar6 = *param_4;
      lVar14 = portMemAllocNonPaged(0x1000);
      if (lVar14 == 0) {
        nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xa65,"_extractNBSIObjFromACPIDir",3,
                     "NVRM: Unable to allocate 0x%x bytes for ACPI parm memory.\n",0x1000);
LAB_0048297a:
        uVar17 = (ulong)(ushort)(sVar27 + 1U);
        if (*(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2) != 0) {
          local_a4 = 0x51;
          goto LAB_004818a8;
        }
        local_a4 = 0x51;
        goto LAB_00482c08;
      }
      pbVar15 = (byte *)portMemAllocNonPaged(0x1000);
      if (pbVar15 == (byte *)0x0) {
        nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xa70,"_extractNBSIObjFromACPIDir",3,
                     "NVRM: Unable to allocate 0x%x bytes for ACPI parm memory.\n",0x1000);
        portMemFree(lVar14);
        goto LAB_0048297a;
      }
      if (!bVar33) {
        if (local_b4 == 3) {
          if (param_2 != -2) goto LAB_00482545;
        }
        else if (local_b4 != 2) goto LAB_0048195f;
LAB_00481f5a:
        puVar35 = &local_58;
        local_54 = 0;
        local_58 = 0xc;
        uVar12 = getTableDataUsingAllObjectCall_constprop_0
                           (param_1,param_10,lVar14,pbVar15,0x1000,0,puVar35);
        if (uVar12 != 0) goto LAB_00482f3e;
        if (*(int *)pbVar15 == 0x4e425349) {
          bVar24 = pbVar15[9];
          uVar26 = pbVar15[8] + 10 + (uint)pbVar15[8];
        }
        else {
          bVar24 = pbVar15[1];
          uVar26 = *pbVar15 + 2 + (uint)*pbVar15;
        }
        if (1 < bVar24) {
          nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x121,"getNbsiDirSize",2,
                       "NVRM: GPU%d, source %d, NBSI dir ver %d > max ver %d.\n",uVar19,2,bVar24,1);
          portMemFree(lVar14);
          portMemFree(pbVar15);
LAB_00482be8:
          local_a4 = 0xffff;
LAB_00482bee:
          uVar17 = (ulong)(ushort)(sVar27 + 1);
          sVar2 = *(short *)((long)&local_48 + uVar17 * 2);
joined_r0x00482acc:
          if (sVar2 != 0) goto LAB_004818a8;
          goto LAB_00482c08;
        }
        local_58 = uVar26;
        uVar12 = getTableDataUsingAllObjectCall_constprop_0
                           (param_1,param_10,lVar14,pbVar15,0x1000,0);
        if (uVar12 != 0) goto LAB_00482f3e;
        iVar13 = testNbsiDir_isra_0(uVar19,pbVar15,uVar26,2);
        if (iVar13 != 0) {
LAB_00482bd3:
          portMemFree(lVar14);
          portMemFree(pbVar15);
          goto LAB_00482be8;
        }
        if (*(int *)pbVar15 == 0x4e425349) {
          bVar24 = pbVar15[8];
          pbVar16 = pbVar15 + 10;
        }
        else {
          bVar24 = *pbVar15;
          pbVar16 = pbVar15 + 2;
        }
        bVar21 = bVar24;
        if (param_2 != -2) {
          if (bVar24 != 0) {
            bVar21 = 0;
            pbVar1 = pbVar16 + (ulong)bVar24 * 2;
            do {
              sVar2 = *(short *)pbVar16;
              pbVar16 = pbVar16 + 2;
              bVar21 = bVar21 + (param_2 == sVar2);
            } while (pbVar16 != pbVar1);
            goto LAB_00482082;
          }
LAB_00483524:
          portMemFree(lVar14);
          portMemFree(pbVar15);
          local_a4 = 0;
          goto LAB_00482bee;
        }
LAB_00482082:
        if (bVar21 == 0) goto LAB_00483524;
        bVar33 = bVar6 == 0;
        uVar29 = 0;
        local_f0 = 0;
        bVar23 = 0;
        local_d0 = 0;
        bVar7 = 0;
        local_b5 = 0;
        local_ec = 0;
        uVar4 = 0;
        uVar30 = uVar26;
        while( true ) {
          local_cc = uVar29 & 0xff;
          if ((uVar29 == bVar24) || (bVar21 <= local_b5)) break;
          local_58 = 0x5a;
          uVar12 = getTableDataUsingAllObjectCall_constprop_0
                             (param_1,param_10,lVar14,pbVar15,0x1000,uVar30,puVar35);
          if (uVar12 != 0) {
            bVar33 = false;
            goto LAB_0048358b;
          }
          iVar13 = testNbsiTable_isra_0(pbVar15,param_2,uVar29,uVar19,2,0x1000,0,0,0);
          if (iVar13 != 0) {
            portMemFree(lVar14);
LAB_00482a8f:
            portMemFree(pbVar15);
            local_a4 = iVar13;
            goto LAB_00482aa6;
          }
          local_a4 = *(uint *)(pbVar15 + 10);
          if (param_2 == -2) {
            local_ec = local_ec + local_a4;
          }
          else if ((param_2 == *(short *)(pbVar15 + 8)) &&
                  ((local_b5 = local_b5 + 1, bVar6 == local_b5 || (bVar33)))) {
            bVar9 = (char)uVar29 + 1;
            local_cc = (uint)bVar9;
            if ((*(short *)(pbVar15 + 8) != 0x4452) || (!bVar33)) {
              if (((local_d0 == 0) || (!bVar33)) || (!bVar31)) goto LAB_004832d0;
              goto LAB_0048327c;
            }
            bVar9 = checkUidMatch(param_1,pbVar15,uVar19,2,bVar9);
            local_a4 = *(uint *)(pbVar15 + 10);
            if ((bVar9 != 0) && ((bVar7 < bVar9 || ((bVar9 == bVar7 && (uVar4 < local_54)))))) {
              local_f0 = uVar30;
              local_d0 = local_a4;
              uVar4 = local_54;
              bVar7 = bVar9;
              bVar23 = local_b5;
            }
          }
          uVar30 = uVar30 + local_a4;
          uVar29 = uVar29 + 1;
        }
        if (local_d0 != 0) {
          if ((bVar33) && (local_b5 = bVar23, bVar31)) {
LAB_0048327c:
            nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x9b7,"getTableUsingAllObjectCall",1
                         ,"NVRM: NBSI Gpu%d Tloc=%d/Glob=%d best fit (score/ver = (%x/%d))\n",uVar19
                         ,2,local_b5,bVar7,uVar4);
            local_a4 = local_d0;
            uVar30 = local_f0;
            goto LAB_004832d0;
          }
          if (param_2 == -2) {
            local_a4 = uVar26 + local_ec;
            uVar12 = 0;
            if (local_a4 != 0) {
              local_b5 = 0;
              local_cc = 0;
              uVar30 = 0;
              goto LAB_004832d0;
            }
          }
          else {
            uVar12 = 0;
          }
LAB_00482f3e:
          local_a4 = uVar12;
          portMemFree(lVar14);
          portMemFree(pbVar15);
LAB_00482aa6:
          if (local_a4 != 0x25) goto LAB_00482bee;
          uVar17 = (ulong)(ushort)(sVar27 + 1U);
          *param_9 = -6;
          sVar2 = *(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2);
          goto joined_r0x00482acc;
        }
        uVar12 = 0;
        bVar33 = true;
LAB_0048358b:
        if (((param_2 != -2) || (local_a4 = local_ec + uVar26, local_a4 == 0)) || (!bVar33))
        goto LAB_00482f3e;
        local_b5 = 0;
        local_cc = 0;
        uVar30 = 0;
LAB_004832d0:
        auVar34 = portMemAllocNonPaged(local_a4);
        local_e0 = auVar34._0_8_;
        if (local_e0 == (byte *)0x0) {
          pcVar22 = "getTableUsingAllObjectCall";
          uVar25 = 0x9d0;
LAB_00482bc5:
          nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",uVar25,pcVar22,3,
                       "NVRM: Can\'t alloc 0x%x bytes for ACPI NBSI table.\n",local_a4);
          goto LAB_00482bd3;
        }
        local_58 = local_a4;
        uVar12 = getTableDataUsingAllObjectCall_constprop_0
                           (param_1,param_10,lVar14,local_e0,local_a4,uVar30,puVar35,auVar34._8_8_);
        if (uVar12 != 0) {
LAB_0048336e:
          portMemFree(local_e0);
          goto LAB_00482f3e;
        }
        if (param_2 != -2) {
          uVar25 = 2;
LAB_00482803:
          uVar12 = testNbsiTable_isra_0
                             (local_e0,param_2,local_cc,uVar19,uVar25,local_a4,1,param_11 != 1,1);
          if (uVar12 != 0) goto LAB_0048336e;
          local_a4 = *(uint *)(local_e0 + 10);
          portMemFree(lVar14);
          portMemFree(pbVar15);
          if (bVar20) {
            bVar20 = true;
joined_r0x00482868:
            if ((param_2 != 0x4452) && (local_b5 == 1)) {
              *param_4 = 0;
            }
            bVar6 = *param_4;
            uVar10 = *param_3;
            lVar18 = *(long *)(g_pSys + 0x210);
            goto LAB_0048289b;
          }
LAB_004830da:
          bVar20 = true;
          goto LAB_004828c6;
        }
        portMemFree(lVar14,0xfffe,(char)local_cc,puVar35);
        portMemFree(pbVar15);
        if (bVar20) {
          if ((char)local_cc == '\x01') {
            *param_4 = 0;
            bVar20 = true;
            goto LAB_004828c6;
          }
          goto LAB_004830da;
        }
        bVar20 = true;
        *param_8 = local_a4;
        if (param_5 <= local_a4) goto LAB_00482a10;
LAB_00482ca9:
        local_a4 = 0x37;
        goto LAB_00482cae;
      }
      if (param_2 != -2) {
LAB_00482545:
        local_54 = 0;
        local_a4 = 0;
        bVar21 = 0;
        bVar24 = 0;
        local_d8 = 0;
        local_b5 = bVar6;
        if (uVar28 == 0x10) goto LAB_00482719;
LAB_004825b5:
        local_58 = 0x5a;
        uVar12 = nbsiObjTypeCallUefi_constprop_0(lVar14,pbVar15,param_2,local_b5,&local_58);
        do {
          if (uVar12 != 0) {
            if ((!bVar31 || bVar6 != 0) || (local_a4 == 0)) goto LAB_00482f3e;
LAB_00482653:
            nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x7ff,"getTableUsingObjTypeCall",1,
                         "NVRM: NBSI Gpu%d Tloc=%d/Glob=%d best fit (score/ver = (%x/%d))\n",uVar19,
                         1,bVar21,bVar24,local_d8);
            local_b5 = bVar21;
LAB_00482760:
            local_e0 = (byte *)portMemAllocNonPaged(local_a4);
            if (local_e0 == (byte *)0x0) {
              pcVar22 = "getTableUsingObjTypeCall";
              uVar25 = 0x80d;
              goto LAB_00482bc5;
            }
            local_58 = local_a4;
            if (uVar28 == 0x10) {
              uVar12 = nbsiObjTypeCallAcpi_constprop_0
                                 (param_1,param_10,lVar14,local_e0,local_a4,param_2,local_b5,
                                  &local_58);
            }
            else {
              uVar12 = nbsiObjTypeCallUefi_constprop_0(lVar14,local_e0,param_2,local_b5,&local_58);
            }
            local_cc = (uint)local_b5;
            if (uVar12 == 0) {
              uVar25 = 1;
              goto LAB_00482803;
            }
            portMemFree(local_e0);
            goto LAB_00482f3e;
          }
          iVar13 = testNbsiTable_isra_0(pbVar15,param_2,local_b5,uVar19,1,0x1000,0,0,1);
          if (iVar13 != 0) {
            portMemFree(lVar14);
            goto LAB_00482a8f;
          }
          if (bVar6 != 0 || param_2 != 0x4452) {
            if ((bVar31 && bVar6 == 0) && (local_a4 != 0)) goto LAB_00482653;
            local_a4 = *(uint *)(pbVar15 + 10);
            goto LAB_00482760;
          }
          bVar7 = checkUidMatch(param_1,pbVar15,uVar19,1,local_b5,&local_54);
          if ((bVar7 != 0) && ((bVar24 < bVar7 || ((bVar7 == bVar24 && (local_d8 < local_54)))))) {
            local_d8 = local_54;
            local_a4 = *(uint *)(pbVar15 + 10);
            bVar24 = bVar7;
            bVar21 = local_b5;
          }
          local_b5 = local_b5 + 1;
          if (uVar28 != 0x10) goto LAB_004825b5;
LAB_00482719:
          local_58 = 0x5a;
          uVar12 = nbsiObjTypeCallAcpi_constprop_0
                             (param_1,param_10,lVar14,pbVar15,0x1000,param_2,local_b5);
        } while( true );
      }
      if ((uVar28 == 0x10) && (local_b4 - 2U < 2)) goto LAB_00481f5a;
LAB_0048195f:
      portMemFree(lVar14);
      portMemFree(pbVar15);
      if (*(short *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2) == 0) {
        local_a4 = 0x1d;
        goto LAB_00482c08;
      }
      local_a4 = 0x1d;
      uVar28 = *(ushort *)((long)&local_48 + (ulong)(ushort)(sVar27 + 1U) * 2);
    }
    sVar27 = sVar27 + 1;
    if (uVar28 == 0) {
      return local_a4;
    }
  } while( true );
}


// ===== 00483820 initNbsiTable =====

/* WARNING: Type propagation algorithm not settling */

undefined8 initNbsiTable(long param_1)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  short *psVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  undefined2 *puVar10;
  byte *pbVar11;
  ulong uVar12;
  undefined1 local_47;
  ushort local_46;
  int local_44 [2];
  undefined1 local_3c [12];
  
  if (param_1 == 0) {
    return 0xffff;
  }
  uVar3 = *(uint *)(param_1 + 0x7a4);
  if (0x1f < uVar3) {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xc72,"initNbsiTable",3,
                 "NVRM: Invalid gpu index %d. Aborting NBSI init.\n",uVar3);
    return 0xffff;
  }
  uVar12 = (ulong)uVar3;
  lVar4 = *(long *)(g_pSys + 0x210);
  if (*(long *)(lVar4 + 0xd8 + uVar12 * 8) != 0) {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xc78,"initNbsiTable",2,
                 "NVRM: NBSI table already initialized for GPU index %d. Aborting NBSI init.\n",
                 uVar3);
    return 0x10006;
  }
  nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xc7c,"initNbsiTable",1,
               "NVRM: Initializing NBSI tables for gpu %d\n",uVar3);
  lVar5 = *(long *)(g_pSys + 0x210);
  if (*(long *)(lVar5 + 0x1d8 + uVar12 * 8) != 0) {
    nvAssertFailedNoLog("pNbsiObj->pTblCache[idx] == NULL","src/kernel/platform/nbsi/nbsi_init.c",
                        0x3db);
  }
  puVar10 = (undefined2 *)portMemAllocNonPaged(0x30);
  *(undefined2 **)(lVar5 + 0x1d8 + uVar12 * 8) = puVar10;
  if (puVar10 == (undefined2 *)0x0) {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0x3e2,"allocNbsiCache",3,
                 "NVRM: Unable to allocate 0x%x memory for NBSI cache.\n",0x30);
    return 0x51;
  }
  *(undefined8 *)(puVar10 + 4) = 0;
  *puVar10 = 0x500;
  *(undefined8 *)(puVar10 + 8) = 0;
  *(undefined8 *)(puVar10 + 0xc) = 0;
  *(undefined8 *)(puVar10 + 0x10) = 0;
  *(undefined8 *)(puVar10 + 0x14) = 0;
  lVar5 = g_pSys;
  *(undefined4 *)(lVar4 + 0x3d8) = 0;
  lVar5 = *(long *)(lVar5 + 0x210);
  local_3c[0] = 0;
  *(undefined1 *)(lVar5 + 0x58) = 1;
  *(undefined1 *)(lVar5 + 0x6a) = 0;
  *(undefined4 *)(lVar5 + 0x8c) = 0;
  uVar8 = fnv32buf(lVar5 + 0x6a,0,0x811c9dc5);
  *(uint *)(lVar5 + 0x5c) = (uVar8 >> 0x14 ^ uVar8) & 0xfffff;
  uVar7 = fnv1Hash16(local_3c,0);
  *(undefined2 *)(lVar5 + 0x68) = uVar7;
  checkUidMatch(param_1,0,uVar3,0,0,0);
  local_46 = 0;
  local_44[1] = 0;
  local_47 = 0;
  iVar9 = getNbsiObjByType(param_1,0x4452,&local_46,&local_47,0,0,local_44 + 1,local_3c,local_44,3,0
                          );
  if (iVar9 == 0) {
LAB_004839e0:
    uVar2 = local_46;
    if (local_44[0] == -2) {
      pbVar11 = *(byte **)(*(long *)(g_pSys + 0x210) + 0x1d8 + uVar12 * 8);
      if ((pbVar11 != (byte *)0x0) && (*pbVar11 != 0)) {
        pbVar1 = pbVar11 + (ulong)*pbVar11 * 8;
        do {
          psVar6 = *(short **)(pbVar11 + 8);
          if ((*psVar6 == 0x4452) && (*(long *)(psVar6 + 8) != 0)) {
            if ((psVar6[1] == 0) && ((char)psVar6[2] == '\0')) {
              uVar2 = psVar6[3];
            }
            else if ((psVar6[3] != 0) || (uVar2 = 0, (char)psVar6[4] != '\0')) goto LAB_00483be0;
            *(long *)(lVar4 + 0xd8 + uVar12 * 8) = *(long *)(psVar6 + 8);
            goto LAB_004839ee;
          }
LAB_00483be0:
          pbVar11 = pbVar11 + 8;
        } while (pbVar11 != pbVar1);
      }
      goto LAB_00483b40;
    }
  }
  else {
    local_46 = 0;
    local_44[1] = 0;
    local_47 = 0;
    iVar9 = getNbsiObjByType(param_1,0x4452,&local_46,&local_47,0,0,local_44 + 1,local_3c,local_44,0
                             ,0);
    uVar2 = local_46;
    if (iVar9 == 0) goto LAB_004839e0;
  }
LAB_004839ee:
  if (uVar2 != 0) {
    if ((uVar2 & 1) != 0) {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xce8,"initNbsiTable",1,
                   "NVRM: Using NBSI driver object for gpu %d from registry.\n",uVar3);
      return 0;
    }
    if ((uVar2 & 2) != 0) {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xcee,"initNbsiTable",1,
                   "NVRM: Using NBSI driver object for gpu %d from VBIOS.\n",uVar3);
      return 0;
    }
    if ((uVar2 & 8) != 0) {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xcf4,"initNbsiTable",1,
                   "NVRM: Using NBSI driver object for gpu %d from SBIOS.\n",uVar3);
      return 0;
    }
    if ((uVar2 & 0x10) != 0) {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xcfa,"initNbsiTable",1,
                   "NVRM: Using NBSI driver object for gpu %d from ACPI table.\n",uVar3);
      return 0;
    }
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xd00,"initNbsiTable",1,
                 "NVRM: Using NBSI driver object for gpu %d from unknown source.\n",uVar3);
    return 0;
  }
LAB_00483b40:
  nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xce4,"initNbsiTable",1,
               "NVRM: No NBSI table for gpu %d found.\n",uVar3);
  return 0;
}


// ===== 00483d30 freeNbsiTable =====

void freeNbsiTable(long param_1)

{
  long lVar1;
  byte *pbVar2;
  byte *pbVar3;
  long lVar4;
  
  if (0x1f < *(uint *)(param_1 + 0x7a4)) {
    nvDbg_Printf("src/kernel/platform/nbsi/nbsi_init.c",0xd1c,"freeNbsiTable",3,
                 "NVRM: Invalid gpu index %d. Aborting free NBSI table.\n");
    return;
  }
  lVar1 = *(long *)(g_pSys + 0x210) + (ulong)*(uint *)(param_1 + 0x7a4) * 8;
  if (*(long *)(lVar1 + 0xd8) != 0) {
    *(undefined8 *)(lVar1 + 0xd8) = 0;
  }
  pbVar3 = *(byte **)(lVar1 + 0x1d8);
  if (pbVar3 != (byte *)0x0) {
    if (*pbVar3 != 0) {
      lVar4 = 0;
      do {
        portMemFree(*(undefined8 *)(*(long *)(pbVar3 + lVar4 * 8 + 8) + 0x10));
        *(undefined8 *)(*(long *)(pbVar3 + lVar4 * 8 + 8) + 0x10) = 0;
        portMemFree(*(undefined8 *)(pbVar3 + lVar4 * 8 + 8));
        pbVar2 = pbVar3 + lVar4 * 8 + 8;
        pbVar2[0] = 0;
        pbVar2[1] = 0;
        pbVar2[2] = 0;
        pbVar2[3] = 0;
        pbVar2[4] = 0;
        pbVar2[5] = 0;
        pbVar2[6] = 0;
        pbVar2[7] = 0;
        lVar4 = lVar4 + 1;
      } while ((byte)lVar4 < *pbVar3);
    }
    *pbVar3 = 0;
    portMemFree(*(undefined8 *)(lVar1 + 0x1d8));
    *(undefined8 *)(lVar1 + 0x1d8) = 0;
  }
  portMemFree(*(undefined8 *)(lVar1 + 0x2d8));
  *(undefined8 *)(lVar1 + 0x2d8) = 0;
  return;
}


// ===== 00483e80 initNbsiObject =====

void initNbsiObject(undefined1 *param_1)

{
  long lVar1;
  
  param_1[0x12] = 0;
  param_1[0x1d] = 0;
  param_1[0x28] = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined8 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 4) = 0x811c9dc5;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x380) = 0;
  *(undefined8 *)(param_1 + 8) = 0x811c9dc5811c9dc5;
  lVar1 = 0;
  do {
    *(undefined2 *)(param_1 + lVar1 * 2 + 0x40) = 0x3b;
    *(undefined8 *)(param_1 + lVar1 * 8 + 0x180) = 0;
    *(undefined8 *)(param_1 + lVar1 * 8 + 0x80) = 0;
    *(undefined8 *)(param_1 + lVar1 * 8 + 0x280) = 0;
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x20);
  return;
}


// ===== 00483f40 getNbsiObject =====

long getNbsiObject(void)

{
  return *(long *)(g_pSys + 0x210) + 0x58;
}


// ===== 00483f60 nbsiReadRegistryDword =====

undefined8 nbsiReadRegistryDword(long param_1,char *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  char *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined1 local_34 [12];
  
  puVar3 = (undefined1 *)getNbsiObject();
  if (param_2 == (char *)0x0) {
    nvAssertFailedNoLog("pRegParmStr != NULL","src/kernel/platform/nbsi/nbsi_osrg.c",0x55);
    return 0x1f;
  }
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pData != NULL","src/kernel/platform/nbsi/nbsi_osrg.c",0x56);
    uVar6 = 0x1f;
  }
  else {
    if ((param_1 == 0) || (puVar3 == (undefined1 *)0x0)) {
      return 0x31;
    }
    if (*(char *)(param_1 + 0x443) == '\0') {
      uVar2 = *(undefined2 *)(puVar3 + 0x10);
      uVar1 = *puVar3;
      pcVar5 = param_2;
      if (*param_2 == '\0') {
        uVar7 = 0;
      }
      else {
        do {
          pcVar4 = pcVar5;
          pcVar5 = pcVar4 + 1;
        } while (*pcVar5 != '\0');
        uVar7 = ((int)pcVar4 - (int)param_2) + 1U & 0xffff;
      }
      fnv1Hash20Array(param_2,uVar7,local_34);
      local_3c = 4;
      uVar6 = getNbsiValue(param_1,1,uVar2,uVar1,local_34,&local_40,&local_3c);
      if ((int)uVar6 == 0) {
        if (local_38 == 0) {
          *param_3 = local_40;
          return 0;
        }
        if (local_38 == -2) {
          nvAssertFailedNoLog("errorCode != NV2080_CTRL_BIOS_GET_NBSI_INCOMPLETE",
                              "src/kernel/platform/nbsi/nbsi_osrg.c",0x95,&local_38);
        }
        return 0xffff;
      }
    }
    else {
      nvDbg_Printf("src/kernel/platform/nbsi/nbsi_osrg.c",0x68,"nbsiReadRegistryDword",4,
                   "NVRM: osReadRegistryDword called in Sleep path can cause excessive delays!\n");
      nvAssertFailedNoLog(&DAT_00d8c454,"src/kernel/platform/nbsi/nbsi_osrg.c",0x6b);
      uVar6 = 0x3f;
    }
  }
  return uVar6;
}


// ===== 00484180 nbsiReadRegistryString =====

undefined8 nbsiReadRegistryString(long param_1,char *param_2,long param_3,int *param_4)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  char *pcVar5;
  undefined8 uVar6;
  uint uVar7;
  int local_4c;
  int local_48;
  undefined1 local_44 [20];
  
  puVar3 = (undefined1 *)getNbsiObject();
  if (param_2 == (char *)0x0) {
    nvAssertFailedNoLog("pRegParmStr != NULL","src/kernel/platform/nbsi/nbsi_osrg.c",0xc5);
  }
  else if (param_4 == (int *)0x0) {
    nvAssertFailedNoLog("pCbLen != NULL","src/kernel/platform/nbsi/nbsi_osrg.c",0xc6);
  }
  else {
    if ((*param_4 == 0) || (param_3 != 0)) {
      if ((param_1 == 0) || (puVar3 == (undefined1 *)0x0)) {
        return 0x31;
      }
      uVar2 = *(undefined2 *)(puVar3 + 0x10);
      uVar1 = *puVar3;
      pcVar5 = param_2;
      if (*param_2 == '\0') {
        uVar7 = 0;
      }
      else {
        do {
          pcVar4 = pcVar5;
          pcVar5 = pcVar4 + 1;
        } while (*pcVar5 != '\0');
        uVar7 = ((int)pcVar4 - (int)param_2) + 1U & 0xffff;
      }
      fnv1Hash20Array(param_2,uVar7,local_44);
      local_4c = *param_4;
      uVar6 = getNbsiValue(param_1,1,uVar2,uVar1,local_44,param_3,&local_4c);
      if ((int)uVar6 != 0) {
        return uVar6;
      }
      if (local_48 != 0) {
        if (local_48 == -2) {
          nvAssertFailedNoLog("errorCode != NV2080_CTRL_BIOS_GET_NBSI_INCOMPLETE",
                              "src/kernel/platform/nbsi/nbsi_osrg.c",0xed,&local_48);
        }
        return 0xffff;
      }
      *param_4 = local_4c;
      return 0;
    }
    nvAssertFailedNoLog("!(*pCbLen != 0 && pData == NULL)","src/kernel/platform/nbsi/nbsi_osrg.c",
                        199);
  }
  return 0x1f;
}


// ===== 00484330 _kp2pCapsCheckStatusOverridesForPcie =====

undefined8
_kp2pCapsCheckStatusOverridesForPcie
          (undefined4 param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined4 local_2c;
  
  local_2c = 0;
  do {
    lVar3 = gpumgrGetNextGpu(param_1,&local_2c);
    if (lVar3 == 0) {
      return 0;
    }
    lVar3 = *(long *)(lVar3 + 7000);
    uVar1 = *(uint *)(lVar3 + 0x3c0);
  } while (uVar1 == 0xffffffff);
  if ((uVar1 & 3) == 0) {
    *param_3 = 4;
    uVar1 = *(uint *)(lVar3 + 0x3c0);
  }
  else if ((uVar1 & 3) == 1) {
    *param_3 = 0;
    uVar1 = *(uint *)(lVar3 + 0x3c0);
  }
  uVar2 = uVar1 >> 4 & 3;
  if (uVar2 == 0) {
    *param_2 = 4;
    uVar1 = *(uint *)(lVar3 + 0x3c0);
  }
  else if (uVar2 == 1) {
    *param_2 = 0;
    uVar1 = *(uint *)(lVar3 + 0x3c0);
  }
  uVar1 = uVar1 >> 8 & 3;
  if (uVar1 == 0) {
    *param_4 = 4;
  }
  else if (uVar1 == 1) {
    *param_4 = 0;
  }
  return 1;
}


// ===== 00484430 p2pGetCapsStatus =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Type propagation algorithm not settling */

uint p2pGetCapsStatus(int param_1,byte *param_2,byte *param_3,undefined1 *param_4,
                     undefined4 *param_5)

{
  byte bVar1;
  ushort uVar2;
  code *pcVar3;
  char cVar4;
  byte bVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  byte bVar14;
  byte bVar15;
  bool bVar16;
  char local_98;
  char local_8c;
  char local_5d;
  byte local_5c;
  byte local_5b;
  undefined2 local_5a;
  undefined4 local_58;
  undefined4 local_54;
  int local_50 [8];
  
  lVar12 = g_pSys;
  local_58 = 0;
  if ((param_3 == (byte *)0x0 || param_5 == (undefined4 *)0x0) || param_2 == (byte *)0x0) {
    return 0x1f;
  }
  *param_2 = 5;
  *param_3 = 5;
  *param_4 = 5;
  *param_5 = 0;
  while (lVar10 = gpumgrGetNextGpu(param_1,&local_58), lVar10 != 0) {
    if ((*(long *)(lVar10 + 0x1bc0) == 0) ||
       (cVar4 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(lVar10), cVar4 == '\0')) {
      nvDbg_Printf("src/kernel/platform/p2p/p2p_caps.c",0x333,"p2pGetCapsStatus",2,
                   "NVRM: P2P is marked unsupported with MIG for GPU instance = 0x%x\n",local_58);
      return 0;
    }
  }
  local_58 = 0;
  local_50[0] = 0;
  lVar10 = gpumgrGetNextGpu(param_1,local_50);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pFirstGpu != NULL","src/kernel/platform/p2p/p2p_caps.c",0x11a);
  }
  else {
    lVar13 = *(long *)(lVar10 + 7000);
    if ((*(int *)(lVar13 + 0x3c4) == 0) || (*(int *)(lVar13 + 0x3c4) == 3)) {
      uVar9 = gpumgrGetSubDeviceCount(param_1);
      iVar7 = 0;
      if (1 < uVar9) {
        iVar7 = local_50[0];
      }
      do {
        local_50[0] = iVar7;
        lVar11 = gpumgrGetNextGpu(param_1,local_50);
        if (lVar11 == 0) {
          *param_3 = 0;
          *param_2 = 0;
          *param_5 = 5;
          *param_4 = 0;
          return 0;
        }
        cVar4 = (**(code **)(lVar13 + 0x330))(lVar10,lVar13,lVar11,*(code **)(lVar13 + 0x330));
        iVar7 = local_50[0];
      } while (cVar4 != '\0');
    }
    *param_3 = 5;
    *param_2 = 5;
  }
  local_54 = 0;
  lVar10 = gpumgrGetNextGpu(param_1,&local_54);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pFirstGpu != NULL","src/kernel/platform/p2p/p2p_caps.c",0xba);
  }
  else {
    if ((*(uint *)(*(long *)(lVar10 + 7000) + 0x3c4) & 0xfffffffd) == 0) {
      lVar13 = *(long *)(lVar10 + 0x1ce8);
      uVar9 = gpumgrGetSubDeviceCount(param_1);
      uVar6 = 0;
      if (1 < uVar9) {
        uVar6 = local_54;
      }
      local_54 = uVar6;
      lVar11 = gpumgrGetNextGpu(param_1,&local_54);
      if (lVar11 == 0) {
LAB_00484826:
        *param_3 = 0;
        *param_2 = 0;
        *param_5 = 3;
        *param_4 = 0;
        return 0;
      }
      if (lVar13 != 0) {
        do {
          iVar7 = (**(code **)(lVar13 + 0x230))(lVar10,lVar13,lVar11);
          if (iVar7 == 0) {
            uVar6 = 0;
            if ((*(char *)(lVar11 + 0x446) == '\0') && (*(char *)(lVar11 + 0x490e) == '\0')) {
              uVar6 = 5;
            }
            timeoutSet(lVar11 + 0x1af0,local_50,10000000,uVar6);
            while( true ) {
              iVar7 = timeoutCheck(lVar11 + 0x1af0,local_50,0xdf);
              iVar8 = knvlinkCheckTrainingIsComplete_IMPL(lVar10,lVar11,lVar13);
              if (iVar8 == 0) break;
              if (iVar7 == 0x65) {
                nvDbg_Printf("src/kernel/platform/p2p/p2p_caps.c",0xe8,
                             "_gpumgrGetP2PCapsStatusOverNvLink",4,
                             "NVRM: Links failed to train for the given gpu pairs!\n");
                (**(code **)(lVar13 + 0x238))(lVar10,lVar13,1);
                goto LAB_004845a5;
              }
            }
          }
          cVar4 = knvlinkIsNvlinkP2pSupported_IMPL(lVar10,lVar13,lVar11);
          if (cVar4 == '\0') goto LAB_0048459a;
          iVar7 = knvlinkTrainP2pLinksToActive_IMPL(lVar10,lVar11,lVar13);
          if (iVar7 != 0) {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/platform/p2p/p2p_caps.c",0xf7);
            goto LAB_0048459a;
          }
          lVar11 = gpumgrGetNextGpu(param_1,&local_54);
        } while (lVar11 != 0);
        goto LAB_00484826;
      }
    }
LAB_0048459a:
    *param_3 = 5;
    *param_2 = 5;
  }
LAB_004845a5:
  local_58 = 0;
  while (lVar10 = gpumgrGetNextGpu(param_1,&local_58), lVar10 != 0) {
    lVar13 = *(long *)(lVar10 + 0x1ce8);
    lVar11 = knvlinkGetDiscoveredLinkMask_IMPL(lVar10,lVar13);
    if ((((lVar13 != 0) && (lVar11 != 0)) &&
        (cVar4 = bitVectorTestAllCleared_IMPL(lVar11,0x40), cVar4 == '\0')) &&
       (((*(char *)(lVar12 + 0x6a) != '\0' ||
         (cVar4 = knvlinkIsNvswitchProxyPresent_IMPL(lVar10,lVar13), cVar4 != '\0')) ||
        (*(char *)(lVar10 + 0x4cc) == '\x01')))) {
      *param_3 = 5;
      *param_2 = 5;
      *param_4 = 5;
      return 0;
    }
  }
  local_50[0] = 0;
  lVar12 = gpumgrGetNextGpu(param_1,local_50);
  uVar9 = *(uint *)(*(long *)(lVar12 + 7000) + 0x3c4);
  if ((uVar9 & 0xfffffffd) == 0) {
    cVar4 = '\0';
    do {
      lVar10 = gpumgrGetNextGpu(param_1,local_50);
      if (lVar10 == 0) {
        if (cVar4 != '\0') {
          *param_3 = 0;
          *param_2 = 0;
          *param_5 = 4;
          *param_4 = 0;
          return uVar9 & 0xfffffffd;
        }
        break;
      }
      cVar4 = gpumgrCheckIndirectPeer_IMPL(lVar12,lVar10);
    } while (cVar4 != '\0');
  }
  *param_3 = 5;
  local_54 = 0;
  *param_2 = 5;
  local_5d = '\0';
  lVar12 = *(long *)(g_pSys + 0x208);
  local_50[0] = 0;
  lVar10 = *(long *)(g_pSys + 0x238);
  cVar4 = _kp2pCapsCheckStatusOverridesForPcie(param_1,param_2,param_3,&local_5c);
  bVar1 = 0;
  if ((cVar4 != '\0') ||
     ((lVar13 = gpumgrGetNextGpu(param_1,&local_54), *(char *)(lVar13 + 0x909) != '\0' &&
      (cVar4 = gpumgrGetPcieP2PCapsFromCache_IMPL(param_1,param_2,param_3), cVar4 != '\0'))))
  goto LAB_0048472c;
  if ((lVar10 == 0) ||
     ((*(char *)(lVar10 + 0x49) == '\0' ||
      (cVar4 = hypervisorPcieP2pDetection_IMPL(lVar10,param_1), cVar4 == '\0')))) {
    if (*(char *)(lVar12 + 0xbc) == '\0') {
      *param_3 = 5;
      *param_2 = 5;
      goto joined_r0x00484d1b;
    }
    local_54 = 0;
    iVar7 = -1;
    bVar1 = 1;
    local_98 = -1;
    local_8c = -1;
    lVar10 = 0;
    while (lVar13 = lVar10, cVar4 = local_98, lVar10 = gpumgrGetNextGpu(param_1), lVar10 != 0) {
      if (((*(char *)(lVar10 + 0x1d8f) != '\0') && (*(short *)(lVar10 + 0x1db6) == -0x7f7a)) &&
         ((uVar2 = *(ushort *)(lVar10 + 0x1db4), (ushort)(uVar2 + 0xcbf8) < 10 ||
          (((((ushort)(uVar2 + 0xc3fe) < 10 || ((ushort)(uVar2 - 0xe02) < 10)) ||
            ((ushort)((uVar2 & 0xbfff) + 0xd0ff) < 0xb)) || ((ushort)(uVar2 + 0xcbe0) < 2)))))) {
        if (iVar7 == -1) {
          local_8c = *(char *)(lVar10 + 0x1d8c);
          iVar7 = *(int *)(lVar10 + 0x1d88);
        }
        else if ((*(int *)(lVar10 + 0x1d88) != iVar7) || (*(char *)(lVar10 + 0x1d8c) != local_8c)) {
          *param_3 = 3;
          *param_2 = 3;
          goto joined_r0x00484977;
        }
      }
      if (lVar13 != 0) {
        if (((*(int *)(lVar13 + 0x808) != *(int *)(lVar10 + 0x808)) ||
            (*(int *)(lVar13 + 0x80c) != *(int *)(lVar10 + 0x80c))) ||
           (*(char *)(lVar13 + 0x485) != *(char *)(lVar10 + 0x485))) {
          *param_3 = 5;
          *param_2 = 5;
          goto joined_r0x00484977;
        }
        clFindCommonDownstreamBR_IMPL(lVar13,lVar10,lVar12,&local_5d);
        bVar16 = local_98 == -1;
        if (bVar16) {
          local_98 = local_5d;
        }
        bVar1 = bVar1 & (local_5d != -1 && (bVar16 || cVar4 == local_5d));
        lVar10 = lVar13;
      }
    }
    if (lVar13 == 0) {
      local_54 = 0;
      lVar13 = gpumgrGetNextGpu(param_1,&local_54);
    }
    iVar7 = 0;
    if (*(char *)(lVar13 + 0x909) != '\0') {
      local_50[0] = param_1;
      iVar7 = rmGpuGroupLockAcquire(0,2,2,0x20001,local_50);
      if (iVar7 == 0x10006) {
        local_50[0] = 0;
      }
      else if (iVar7 != 0) {
        local_50[0] = 0;
LAB_00484fa9:
        if (*param_3 == 0) {
          *param_3 = 5;
        }
        if (*param_2 == 0) {
          *param_2 = 5;
        }
        local_54 = 0;
        lVar12 = gpumgrGetNextGpu(param_1,&local_54);
        if (*(char *)(lVar12 + 0x909) == '\0') {
          return 0;
        }
        iVar7 = gpumgrStorePcieP2PCapsCache_IMPL(param_1,*param_2,*param_3);
        if (iVar7 != 0) {
          nvAssertOkFailedNoLog
                    (iVar7,
                     "gpumgrStorePcieP2PCapsCache(gpuMask, *pP2PWriteCapStatus, *pP2PReadCapStatus)"
                     ,"src/kernel/platform/p2p/p2p_caps.c",0x273);
          return 0;
        }
        return 0;
      }
    }
    local_54 = 0;
    bVar15 = 0;
    *param_2 = 0;
    *param_3 = 0;
    bVar14 = 0;
LAB_00484e6a:
    do {
      lVar12 = gpumgrGetNextGpu(param_1,&local_54);
      if (lVar12 == 0) {
        if (local_50[0] != 0) {
          rmGpuGroupLockRelease(local_50[0],0);
        }
        if (iVar7 == 0) goto LAB_00484980;
        goto LAB_00484fa9;
      }
      local_5a = 0;
      local_5b = bVar1;
      iVar7 = (**(code **)(lVar12 + 0x3b90))
                        (lVar12 + 0x3b58,*(undefined4 *)(lVar12 + 0x3b34),
                         *(undefined4 *)(lVar12 + 0x3b3c),0x20800ab8,&local_5b,3);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GET_PCIE_P2P_CAPS, &p2pCapsParams, sizeof(NV2080_CTRL_INTERNAL_GET_PCIE_P2P_CAPS_PARAMS))"
                   ,"src/kernel/platform/p2p/p2p_caps.c",0x233);
        if (local_50[0] != 0) {
          rmGpuGroupLockRelease(local_50[0],0);
        }
        goto LAB_00484fa9;
      }
      if (*(char *)(*(long *)(lVar12 + 7000) + 0x3aa) != '\0') {
        bVar14 = 2;
      }
      if (*(char *)(*(long *)(lVar12 + 7000) + 0x3a9) != '\0') {
        bVar15 = 2;
      }
      iVar7 = 0;
      if (*param_3 == 0) {
        bVar5 = (byte)local_5a;
        if ((byte)local_5a == 0) {
          bVar5 = bVar15;
        }
        *param_3 = bVar5;
        if (*param_2 != 0) {
          if (*param_3 != 0) break;
          goto LAB_00484e6a;
        }
      }
      else if (*param_2 != 0) break;
      if (local_5a._1_1_ == 0) {
        *param_2 = bVar14;
        bVar5 = bVar14;
        if (*param_3 == 0) goto LAB_00484e6a;
      }
      else {
        *param_2 = local_5a._1_1_;
        bVar5 = *param_3;
      }
    } while (bVar5 == 0);
joined_r0x00484977:
    if (local_50[0] != 0) {
      rmGpuGroupLockRelease(local_50[0],0);
    }
  }
  else {
    *param_3 = 0;
    *param_2 = 0;
joined_r0x00484d1b:
    if (local_50[0] != 0) {
      rmGpuGroupLockRelease(local_50[0],0);
    }
    bVar1 = 1;
  }
LAB_00484980:
  local_54 = 0;
  lVar12 = gpumgrGetNextGpu(param_1,&local_54);
  if ((*(char *)(lVar12 + 0x909) != '\0') &&
     (iVar7 = gpumgrStorePcieP2PCapsCache_IMPL(param_1,*param_2,*param_3), iVar7 != 0)) {
    nvAssertOkFailedNoLog
              (iVar7,"gpumgrStorePcieP2PCapsCache(gpuMask, *pP2PWriteCapStatus, *pP2PReadCapStatus)"
               ,"src/kernel/platform/p2p/p2p_caps.c",0x273);
  }
LAB_0048472c:
  local_5b = *param_3;
  local_5c = *param_2;
  if ((local_5c == 0) || (local_5b == 0)) {
    *param_5 = 1;
    local_54 = CONCAT31(local_54._1_3_,5);
    local_50[0] = 0;
    lVar12 = gpumgrGetNextGpu(param_1,local_50);
    if ((*(uint *)(*(long *)(lVar12 + 7000) + 0x3c4) < 2) &&
       (*(int *)(*(long *)(lVar12 + 7000) + 0x3c8) - 1U < 2)) {
      uVar9 = gpumgrGetSubDeviceCount(param_1);
      iVar7 = 0;
      if (1 < uVar9) {
        iVar7 = local_50[0];
      }
      do {
        local_50[0] = iVar7;
        lVar10 = gpumgrGetNextGpu(param_1,local_50);
        if (lVar10 == 0) {
          cVar4 = _kp2pCapsCheckStatusOverridesForPcie(param_1,&local_5c,&local_5b,&local_54);
          if (cVar4 == '\0') {
            if (((bVar1 == 0) && (*(int *)(g_pSys + 0xb4) != 0x38)) &&
               (*(int *)(g_pSys + 0xb4) != 0x14)) {
              nvDbg_Printf("src/kernel/platform/p2p/p2p_caps.c",0x298,
                           "_p2pCapsGetHostSystemStatusOverPcieBar1",1,
                           "NVRM: Unrecognized CPU. Read Cap is disabled\n");
              return 0;
            }
            bVar16 = local_5b != 0;
            local_5b = 0;
            if (bVar16 || local_5c != 0) {
              return 0;
            }
          }
          *param_2 = local_5c;
          *param_3 = local_5b;
          *param_4 = (undefined1)local_54;
          *param_5 = 2;
          return 0;
        }
        pcVar3 = *(code **)(*(long *)(&DAT_00001b90 + lVar12) + 0x358);
        cVar4 = (*pcVar3)(lVar12,*(long *)(&DAT_00001b90 + lVar12),lVar10,
                          *(undefined8 *)(&DAT_00001b90 + lVar10),pcVar3);
        iVar7 = local_50[0];
      } while (cVar4 != '\0');
    }
  }
  return 0;
}


// ===== 004850e0 subdeviceCtrlCmdGetP2pCaps_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGetP2pCaps_VF(long param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  ulong extraout_RDX;
  char *pcVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
  ulong uStack_60;
  
  lVar4 = resservGetTlsCallContext();
  puVar2 = *(undefined4 **)(lVar4 + 0x48);
  lVar4 = gpumgrGetGpuFromSubDeviceInst
                    (*(undefined4 *)(param_1 + 0x330),*(undefined4 *)(param_1 + 0x334));
  if ((*param_2 == '\0') && (0x20 < *(uint *)(param_2 + 4))) {
    nvCheckFailedNoLog(4,
                       "pParams->bAllCaps || (pParams->peerGpuCount <= NV0000_CTRL_SYSTEM_MAX_ATTACHED_GPUS)"
                       ,"src/kernel/platform/p2p/p2p_caps.c",0x3af);
    return 0x1f;
  }
  if (param_2[1] == '\0') {
    if (*(char *)(lVar4 + 0x4a4e) != '\0') {
      pcVar5 = (char *)portMemAllocNonPaged(0x688);
      if (pcVar5 == (char *)0x0) {
        nvCheckFailedNoLog(1,"pShimParams != NULL","src/kernel/platform/p2p/p2p_caps.c",0x3bb);
        return 0x51;
      }
      portMemCopy(pcVar5,0x688,param_2,0x688);
      if ((*pcVar5 == '\0') && (*(int *)(pcVar5 + 4) != 0)) {
        pcVar11 = pcVar5 + 0xc;
        uVar9 = 0;
        do {
          lVar6 = gpumgrGetGpuFromId(*(undefined4 *)(pcVar5 + (ulong)uVar9 * 0x34 + 8));
          if (lVar6 == 0) {
            nvCheckFailedNoLog(1,"pRemoteGpu != NULL","src/kernel/platform/p2p/p2p_caps.c",0x3c7);
            iVar3 = 0x1f;
            goto LAB_004851fb;
          }
          portMemCopy(pcVar11,0x10,lVar6 + 0x7c5,0x10);
          uVar9 = uVar9 + 1;
          pcVar11 = pcVar11 + 0x34;
        } while (uVar9 < *(uint *)(pcVar5 + 4));
      }
      pcVar5[1] = '\x01';
      uStack_60 = 0x485230;
      lVar6 = gpuGetRpc(lVar4);
      if (lVar6 == 0) {
        iVar3 = 0x1a;
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/platform/p2p/p2p_caps.c",0x3d3);
      }
      else {
        if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
          iVar3 = rpcDmaControl_wrapper(lVar4,lVar6,*puVar2,puVar2[1],puVar2[2],pcVar5,0x688);
        }
        else {
          iVar3 = (**(code **)(lVar4 + 0x3b90))(lVar4 + 0x3b58);
          uStack_60 = extraout_RDX;
        }
        if (iVar3 == 0) {
          if (*param_2 == '\0') {
            uVar9 = *(uint *)(param_2 + 4);
          }
          else {
            iVar1 = *(int *)(pcVar5 + 4);
            *(int *)(param_2 + 4) = iVar1;
            if (iVar1 == 0) goto LAB_004851fb;
            pcVar11 = pcVar5 + 0xc;
            uVar8 = 0;
            do {
              lVar4 = gpumgrGetGpuFromUuid(pcVar11,2,uStack_60);
              if (lVar4 == 0) {
                nvCheckFailedNoLog(1,"pRemoteGpu != NULL","src/kernel/platform/p2p/p2p_caps.c",0x3eb
                                  );
                iVar3 = 0x12;
                goto LAB_004851fb;
              }
              uStack_60 = (ulong)*(uint *)(lVar4 + 0x7ac);
              uVar10 = (int)uVar8 + 1;
              pcVar11 = pcVar11 + 0x34;
              *(uint *)(param_2 + uVar8 * 0x34 + 8) = *(uint *)(lVar4 + 0x7ac);
              uVar9 = *(uint *)(param_2 + 4);
              uVar8 = (ulong)uVar10;
            } while (uVar10 < uVar9);
          }
          if (uVar9 == 0) {
            iVar3 = 0;
          }
          else {
            pcVar11 = param_2 + 0x28;
            pcVar7 = pcVar5 + 0x28;
            uVar8 = 0;
            do {
              lVar4 = uVar8 * 0x34;
              *(undefined4 *)(param_2 + lVar4 + 0x1c) = *(undefined4 *)(pcVar5 + lVar4 + 0x1c);
              *(undefined4 *)(param_2 + lVar4 + 0x20) = *(undefined4 *)(pcVar5 + lVar4 + 0x20);
              *(undefined4 *)(param_2 + lVar4 + 0x24) = *(undefined4 *)(pcVar5 + lVar4 + 0x24);
              portMemCopy(pcVar11,9,pcVar7,9);
              *(undefined4 *)(param_2 + lVar4 + 0x34) = *(undefined4 *)(pcVar5 + lVar4 + 0x34);
              uVar9 = (int)uVar8 + 1;
              uVar8 = (ulong)uVar9;
              pcVar11 = pcVar11 + 0x34;
              pcVar7 = pcVar7 + 0x34;
            } while (uVar9 < *(uint *)(param_2 + 4));
          }
        }
      }
LAB_004851fb:
      portMemFree(pcVar5);
      return iVar3;
    }
  }
  else {
    nvCheckFailedNoLog(4,"(pParams->bUseUuid == NV_FALSE)","src/kernel/platform/p2p/p2p_caps.c",
                       0x3b3);
  }
  return 0x56;
}


// ===== 004854a0 pfmConstruct_IMPL =====

undefined8 pfmConstruct_IMPL(long param_1)

{
  initNbsiObject(param_1 + 0x58);
  return 0;
}


// ===== 004854c0 pfmUpdateAcpiIdMapping_IMPL =====

void pfmUpdateAcpiIdMapping_IMPL
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               uint param_6)

{
  long lVar1;
  
  lVar1 = (ulong)*(uint *)(param_2 + 0x7a4) * 0xc0 + (ulong)param_6 * 0xc;
  *(undefined4 *)(param_1 + 0x3e0 + lVar1) = param_3;
  *(undefined4 *)(param_1 + 0x3e4 + lVar1) = param_4;
  *(undefined4 *)(param_1 + 1000 + lVar1) = param_5;
  return;
}


// ===== 00485500 pfmFindAcpiId_IMPL =====

undefined4 pfmFindAcpiId_IMPL(long param_1,long param_2,int param_3)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x3e4 + (ulong)*(uint *)(param_2 + 0x7a4) * 0xc0);
  uVar2 = 0;
  do {
    if (*piVar3 == param_3) {
      return *(undefined4 *)
              (param_1 + 0x3e0 + (ulong)*(uint *)(param_2 + 0x7a4) * 0xc0 + uVar2 * 0xc);
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    piVar3 = piVar3 + 3;
  } while (uVar1 != 0x10);
  return 0;
}


// ===== 00485550 _pfmreqhndlrPmgrPmuPostLoadWorkItem =====

void _pfmreqhndlrPmgrPmuPostLoadWorkItem(void)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint local_24;
  undefined1 local_20 [4];
  undefined4 local_1c;
  
  lVar1 = *(long *)(g_pSys + 0x220);
  gpumgrGetGpuAttachInfo(local_20,&local_1c);
  local_24 = *(uint *)(lVar1 + 0x4c);
  if (local_24 < 4) {
    lVar3 = gpumgrGetNextGpu(local_1c,&local_24);
    if (lVar3 == 0) goto LAB_00485690;
  }
  else {
LAB_00485690:
    lVar3 = 0;
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/platform/platform_request_handler.c",0x3ab);
  }
  if (*(char *)(lVar1 + 0x6aa) != *(char *)(lVar1 + 0x6cb)) {
    iVar2 = pfmreqhndlrHandleEdppeakLimitUpdate_IMPL(lVar1,lVar3);
    if ((iVar2 != 0) && (iVar2 != 0x56)) {
      uVar4 = 0x3ba;
      pcVar5 = "Failed to apply the EDPpeak limit from system";
      goto LAB_00485665;
    }
  }
  if (*(char *)(lVar1 + 0x6ab) != *(char *)(lVar1 + 0x6cc)) {
    iVar2 = pfmreqhndlrHandleUserConfigurableTgpMode_IMPL(lVar1,lVar3);
    if ((iVar2 != 0) && (iVar2 != 0x56)) {
      uVar4 = 0x3cc;
      pcVar5 = "Failed to update user configurable TGP (Turbo) mode from system";
      goto LAB_00485665;
    }
  }
  if (*(char *)(lVar1 + 0x6d1) == '\0') {
    return;
  }
  iVar2 = pfmreqhndlrHandlePlatformEdppLimitUpdate_IMPL(lVar1,lVar3,*(undefined4 *)(lVar1 + 0x6b8));
  if ((iVar2 == 0) || (iVar2 == 0x56)) {
    *(undefined1 *)(lVar1 + 0x6d1) = 0;
    return;
  }
  uVar4 = 0x3dd;
  pcVar5 = "Failed to update platform EDPpeak limit";
LAB_00485665:
  nvAssertOkFailedNoLog(0,pcVar5,"src/kernel/platform/platform_request_handler.c",uVar4);
  return;
}


// ===== 004856b0 _pfmreqhndlrThermPmuPostInitWorkItem =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _pfmreqhndlrThermPmuPostInitWorkItem(void)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined1 local_39;
  int local_38;
  uint local_34;
  undefined1 local_30 [4];
  int local_2c [3];
  
  local_38 = 0;
  local_39 = 0;
  lVar1 = *(long *)(g_pSys + 0x220);
  gpumgrGetGpuAttachInfo(local_30,local_2c);
  local_34 = *(uint *)(lVar1 + 0x4c);
  if ((local_34 < 4) && (lVar3 = gpumgrGetNextGpu(local_2c[0],&local_34), lVar3 != 0)) {
    lVar4 = lVar3 + 0x3b58;
  }
  else {
    lVar3 = 0;
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/platform/platform_request_handler.c",0x32d);
    lVar4 = 0x3b58;
  }
  iVar2 = pfmreqhndlrGetPerfSensorCounterById_IMPL(lVar1,0xb,&local_38);
  if ((iVar2 != 0) || (local_38 << 8 == 0)) {
    return;
  }
  if (*(char *)(lVar1 + 0x6ca) != '\0') {
    local_2c[0] = local_38 << 8;
    iVar2 = (**(code **)(lVar3 + 0x3b90))
                      (lVar4,*(undefined4 *)(lVar3 + 0x3b34),*(undefined4 *)(lVar3 + 0x3b3c),
                       0x20800ad1,local_2c,4);
    if (iVar2 == 0) {
      *(undefined1 *)(lVar1 + 0x6ca) = 0;
    }
    else {
      nvAssertFailedNoLog("PRH failed to update thermal limit!",
                          "src/kernel/platform/platform_request_handler.c",0x357);
    }
  }
  if ((*(char *)(lVar1 + 0x6c9) == '\0') &&
     (iVar2 = pfmreqhndlrHandleCheckPM1Available_IMPL(lVar1,lVar3,&local_39), iVar2 == 0)) {
    pfmreqhndlrUpdatePerfCounter(lVar1,0x4a,local_39);
    return;
  }
  pfmreqhndlrUpdatePerfCounter(lVar1,0x4a,0);
  return;
}


// ===== 00485820 pfmreqhndlrConstruct_IMPL =====

undefined8 pfmreqhndlrConstruct_IMPL(void)

{
  nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0x38,"pfmreqhndlrConstruct_IMPL",1,
               "NVRM: \n");
  return 0;
}


// ===== 00485860 pfmreqhndlrInitGpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong pfmreqhndlrInitGpu(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  ulong uVar4;
  int local_24;
  int local_20;
  undefined4 local_1c;
  
  *(undefined4 *)(param_1 + 0x4c) = 4;
  *(undefined4 *)(param_1 + 0x910) = 0xff;
  local_24 = 0;
  gpumgrGetGpuAttachInfo(&local_20,&local_1c);
  if (local_20 - 1U < 4) {
    do {
      lVar3 = gpumgrGetNextGpu(local_1c,&local_24);
      if (lVar3 == 0) goto LAB_00485976;
      iVar1 = testIfDsmSubFunctionEnabled(lVar3,6,0);
      if (iVar1 == 0) {
        uVar2 = 6;
        goto LAB_004858d8;
      }
      iVar1 = testIfDsmSubFunctionEnabled(lVar3,10,0);
    } while (iVar1 != 0);
    uVar2 = 10;
LAB_004858d8:
    *(undefined4 *)(param_1 + 0x910) = uVar2;
    uVar4 = (**(code **)(lVar3 + 0x3b90))
                      (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                       *(undefined4 *)(lVar3 + 0x3b3c),0x20800a45,0,0);
    if ((int)uVar4 == 0) {
      *(int *)(param_1 + 0x4c) = local_24 + -1;
      return uVar4;
    }
    nvAssertOkFailedNoLog
              (uVar4 & 0xffffffff,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_PERF_PFM_REQ_HNDLR_DEPENDENCY_CHECK, NULL, 0)"
               ,"src/kernel/platform/platform_request_handler.c",0x74);
    uVar4 = uVar4 & 0xffffffff;
  }
  else {
    nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0x59,"pfmreqhndlrInitGpu",1,
                 "NVRM: PLATFORM_REQUEST_HANDLER: Cannot support %u GPUs yet\n");
LAB_00485976:
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 004859b0 pfmreqhndlrGetGpu =====

undefined8 pfmreqhndlrGetGpu(long param_1)

{
  undefined8 uVar1;
  uint local_24;
  undefined1 local_20 [4];
  undefined4 local_1c [3];
  
  gpumgrGetGpuAttachInfo(local_20,local_1c);
  local_24 = *(uint *)(param_1 + 0x4c);
  uVar1 = 0;
  if (local_24 < 4) {
    uVar1 = gpumgrGetNextGpu(local_1c[0],&local_24);
  }
  return uVar1;
}


// ===== 004859f0 pfmreqhndlrPcontrol_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong pfmreqhndlrPcontrol_IMPL(long param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  ulong local_70;
  uint local_68;
  uint local_64;
  uint local_60;
  int local_5c;
  undefined4 local_58;
  uint local_54;
  ulong local_50;
  uint *local_48;
  undefined2 local_40;
  undefined6 uStack_3e;
  
  local_68 = 0;
  if (param_1 == 0) {
    nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0xcc,"pfmreqhndlrPcontrol_IMPL",4,
                 "NVRM: PlatformRequestHandler pointer is NULL\n");
  }
  else {
    gpumgrGetGpuAttachInfo(&local_60,&local_58);
    local_64 = *(uint *)(param_1 + 0x4c);
    if ((local_64 < 4) && (lVar4 = gpumgrGetNextGpu(local_58,&local_64), lVar4 != 0)) {
      iVar5 = 0;
      local_50 = 0;
      local_58 = 0x1c;
      local_54 = (*(uint *)(param_1 + 0x6b4) & 0xff) << 8 |
                 (*(uint *)(param_1 + 0x90c) & 0xff) << 0x10;
      uStack_3e = 0;
      while( true ) {
        while( true ) {
          local_40 = 4;
          local_48 = &local_68;
          uVar1 = pfmreqhndlrCallACPI(lVar4,&local_58);
          if (uVar1 != 0) {
            local_70 = (ulong)uVar1;
            nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0xf9,
                         "pfmreqhndlrPcontrol_IMPL",4,"NVRM: ACPI call failed. Error : 0x%x\n");
            return local_70;
          }
          local_68 = (uint)local_50;
          if (((uint)local_50 & 0xf) != 1) break;
          local_60 = (uint)local_50 >> 8 & 0xff;
          local_5c = 0;
          iVar3 = (**(code **)(lVar4 + 0x3b90))
                            (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),
                             *(undefined4 *)(lVar4 + 0x3b3c),0x20800ad5,&local_60,8);
          local_68 = 0;
          if (iVar3 == 0) {
            iVar5 = local_5c;
          }
          local_54 = (*(uint *)(param_1 + 0x90c) & 0xff) << 0x10 | iVar5 << 0x18 | 1;
        }
        if (((uint)local_50 & 0xf) != 2) break;
        uVar2 = (uint)local_50 >> 8 & 0xff;
        local_60 = uVar2;
        (**(code **)(lVar4 + 0x3b90))
                  (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),*(undefined4 *)(lVar4 + 0x3b3c),
                   0x20800ad6,&local_60,4);
        uVar1 = *(uint *)(param_1 + 0x6b4);
        local_68 = 0;
        *(uint *)(param_1 + 0x6b4) = uVar2;
        local_54 = (uVar1 & 0xff) << 8 | (*(uint *)(param_1 + 0x90c) & 0xff) << 0x10 | 2;
      }
      if ((local_50 & 0xf) == 0) {
        local_70 = local_50 & 0xf;
        nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0x105,
                     "pfmreqhndlrPcontrol_IMPL",1,
                     "NVRM: No action is required in response to SBIOS event PCONTROL\n");
        return local_70;
      }
      nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0x15c,"pfmreqhndlrPcontrol_IMPL"
                   ,4,"NVRM: Received a wrong request type from SBIOS, which is not supported\n");
      return 0x56;
    }
    nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0xd4,"pfmreqhndlrPcontrol_IMPL",4,
                 "NVRM: Gpu pointer is NULL\n");
  }
  return 0x56;
}


// ===== 00485d40 pfmreqhndlrStateInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 pfmreqhndlrStateInit_IMPL(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  undefined1 uVar7;
  undefined8 local_40;
  undefined8 local_38;
  char local_30 [8];
  
  if (param_1 == 0) {
    nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0x18b,"pfmreqhndlrStateInit_IMPL",
                 4,"NVRM: PlatformRequestHandler pointer is NULL\n");
  }
  else {
    uVar4 = 0;
    if ((*(char *)(param_1 + 0x6c8) != '\0') || (uVar4 = pfmreqhndlrInitGpu(), (int)uVar4 != 0)) {
      return uVar4;
    }
    gpumgrGetGpuAttachInfo(&local_40,&local_38);
    if ((3 < *(uint *)(param_1 + 0x4c)) ||
       (lVar5 = gpumgrGetNextGpu(local_38 & 0xffffffff), lVar5 == 0)) {
      return 0x40;
    }
    *(undefined1 *)(param_1 + 0x904) = 0;
    *(undefined4 *)(param_1 + 0x6ca) = 1;
    local_40 = local_40 & 0xffffffffffff0000;
    if (*(int *)(param_1 + 0x910) != 0xff) {
      portMemSet(&local_38,0,8);
      local_40 = CONCAT62(local_40._2_6_,8);
      iVar2 = osCallACPI_DSM(lVar5,*(undefined4 *)(param_1 + 0x910),0,&local_38,&local_40);
      pcVar6 = (char *)&local_38;
      if (iVar2 == 0) {
        do {
          if (*pcVar6 != '\0') {
            *(undefined1 *)(param_1 + 0x48) = 1;
            lVar1 = lVar5 + 0x3b58;
            local_38 = CONCAT62(local_38._2_6_,1);
            iVar2 = (**(code **)(lVar5 + 0x3b90))
                              (lVar1,*(undefined4 *)(lVar5 + 0x3b34),*(undefined4 *)(lVar5 + 0x3b3c)
                               ,0x20800acb,&local_38,2);
            if (iVar2 == 0) {
              *(undefined1 *)(param_1 + 0x49) = 1;
              *(undefined1 *)(param_1 + 0x4a) = local_38._1_1_;
            }
            pfmreqhndlrInitSensors(param_1);
            *(undefined1 *)(param_1 + 0x6c8) = 1;
            local_38 = local_38 & 0xffffffffffff0000;
            iVar2 = (**(code **)(lVar5 + 0x3b90))
                              (lVar1,*(undefined4 *)(lVar5 + 0x3b34),*(undefined4 *)(lVar5 + 0x3b3c)
                               ,0x20800ace,&local_38,2);
            local_40 = 0;
            uVar7 = local_38._1_1_;
            if (iVar2 != 0) {
              uVar7 = 0;
            }
            *(undefined1 *)(param_1 + 0x6c9) = uVar7;
            iVar2 = (**(code **)(lVar5 + 0x3b90))
                              (lVar1,*(undefined4 *)(lVar5 + 0x3b34),*(undefined4 *)(lVar5 + 0x3b3c)
                               ,0x20800ad4,&local_40,8);
            uVar7 = 0;
            uVar3 = 0xff;
            if (iVar2 == 0) {
              uVar7 = (undefined1)local_40;
              uVar3 = local_40._4_4_;
            }
            *(undefined1 *)(param_1 + 0x908) = uVar7;
            *(undefined4 *)(param_1 + 0x90c) = uVar3;
            local_38 = 0;
            local_30[0] = '\0';
            local_30[1] = '\0';
            local_30[2] = '\0';
            local_30[3] = '\0';
            local_30[4] = '\0';
            local_30[5] = '\0';
            local_30[6] = '\0';
            local_30[7] = '\0';
            uVar4 = (**(code **)(lVar5 + 0x3b90))
                              (lVar1,*(undefined4 *)(lVar5 + 0x3b34),*(undefined4 *)(lVar5 + 0x3b3c)
                               ,0x20800acc,&local_38,0x10);
            if (((int)uVar4 == 0) && (*(int *)(param_1 + 0x6bc) == 0x200)) {
              local_38 = CONCAT71(local_38._1_7_,1);
              uVar4 = (**(code **)(lVar5 + 0x3b90))
                                (lVar1,*(undefined4 *)(lVar5 + 0x3b34),
                                 *(undefined4 *)(lVar5 + 0x3b3c),0x20800acd,&local_38,0x10);
              return uVar4;
            }
            return uVar4;
          }
          pcVar6 = pcVar6 + 1;
        } while (pcVar6 != local_30);
        nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0x2e2,
                     "_pfmreqhndlrSupportExists",1,
                     "NVRM: PRH : This system doesn\'t support any ACPI-GPS-subfunctions.\n");
      }
      else {
        nvDbg_Printf("src/kernel/platform/platform_request_handler.c",0x2cf,
                     "_pfmreqhndlrSupportExists",4,
                     "NVRM: GPS FUNC_SUPPORT is not supported on this Platform, Failing ACPI-GPS subfunction 0x%x.\n"
                     ,0);
      }
    }
  }
  return 0x56;
}


// ===== 004860c0 pfmreqhndlrStateDestroy_IMPL =====

void pfmreqhndlrStateDestroy_IMPL(long param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 0x6c8) = 0;
    return;
  }
  nvAssertFailedNoLog("pPlatformRequestHandler","src/kernel/platform/platform_request_handler.c",
                      0x221);
  uRam00000000000006c8 = 0;
  return;
}


// ===== 00486110 pfmreqhndlrStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 pfmreqhndlrStateLoad_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  undefined1 local_29;
  int local_28;
  uint local_24;
  undefined1 local_20 [4];
  int local_1c [3];
  
  local_29 = 0;
  local_28 = 0;
  if (param_1 == 0) {
    nvAssertFailedNoLog("pPlatformRequestHandler","src/kernel/platform/platform_request_handler.c",
                        0x233);
  }
  gpumgrGetGpuAttachInfo(local_20,local_1c);
  local_24 = *(uint *)(param_1 + 0x4c);
  if ((local_24 < 4) && (lVar2 = gpumgrGetNextGpu(local_1c[0],&local_24), lVar2 != 0)) {
    if ((((*(char *)(param_1 + 0x48) != '\0') && (*(int *)(param_1 + 0x6bc) != 0x200)) &&
        (iVar1 = pfmreqhndlrGetPerfSensorCounterById_IMPL(param_1,0xb,&local_28), iVar1 == 0)) &&
       (local_28 << 8 != 0)) {
      if (*(char *)(param_1 + 0x6ca) != '\0') {
        local_1c[0] = local_28 << 8;
        iVar1 = (**(code **)(lVar2 + 0x3b90))
                          (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),
                           *(undefined4 *)(lVar2 + 0x3b3c),0x20800ad1,local_1c,4);
        if (iVar1 == 0) {
          *(undefined1 *)(param_1 + 0x6ca) = 0;
        }
        else {
          nvAssertFailedNoLog("PRH failed to update thermal limit!",
                              "src/kernel/platform/platform_request_handler.c",0x25f);
        }
      }
      if (*(char *)(param_1 + 0x6c9) == '\0') {
        iVar1 = pfmreqhndlrHandleCheckPM1Available_IMPL(param_1,lVar2,&local_29);
        if (iVar1 == 0) {
          pfmreqhndlrUpdatePerfCounter(param_1,0x4a,local_29);
        }
      }
      else {
        pfmreqhndlrUpdatePerfCounter(param_1,0x4a,0);
      }
    }
    return 0;
  }
  return 0x40;
}


// ===== 004862d0 pfmreqhndlrStateUnload_IMPL =====

undefined8 pfmreqhndlrStateUnload_IMPL(void)

{
  return 0;
}


// ===== 004862e0 pfmreqhndlrStateSync_IMPL =====

ulong pfmreqhndlrStateSync_IMPL(undefined8 param_1,undefined8 param_2,byte *param_3)

{
  byte bVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  bVar1 = *param_3;
  if (bVar1 == 2) {
    uVar2 = pfmreqhndlrOperatingLimitUpdate_IMPL(param_1,*(undefined4 *)(param_3 + 8),0,0);
    return uVar2;
  }
  if (2 < bVar1) {
    if (bVar1 == 3) {
      uVar2 = pfmreqhndlrOperatingLimitUpdate_IMPL
                        (param_1,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc),1);
      return uVar2;
    }
    return 0x56;
  }
  if (bVar1 == 0) {
    uVar2 = osQueueWorkItem(param_2,_pfmreqhndlrPmgrPmuPostLoadWorkItem,0,0x58);
    uVar3 = 0x40c;
    if ((int)uVar2 != 0) goto LAB_0048636c;
  }
  else {
    uVar2 = osQueueWorkItem(param_2,_pfmreqhndlrThermPmuPostInitWorkItem,0,0x58);
    if ((int)uVar2 != 0) {
      uVar3 = 0x391;
LAB_0048636c:
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,"status","src/kernel/platform/platform_request_handler.c",uVar3)
      ;
      return uVar2 & 0xffffffff;
    }
  }
  return uVar2;
}


// ===== 004863b0 _handleCmdSystemPfmreqhndlrGetSupportedFunctions =====

undefined8
_handleCmdSystemPfmreqhndlrGetSupportedFunctions(long param_1,short param_2,uint *param_3)

{
  int iVar1;
  long lVar2;
  
  *param_3 = 0;
  if (param_2 != 0) {
    return 0x24;
  }
  lVar2 = pfmreqhndlrGetGpu();
  if (lVar2 != 0) {
    iVar1 = testIfDsmSubFunctionEnabled(lVar2,*(undefined4 *)(param_1 + 0x910),0);
    *param_3 = *param_3 | (uint)(iVar1 == 0);
    return 0;
  }
  return 0x40;
}


// ===== 00486420 _pfmreqhndlrUpdatePlatformPowerModeWorkItem =====

void _pfmreqhndlrUpdatePlatformPowerModeWorkItem(void)

{
  undefined1 uVar1;
  long lVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined8 local_38;
  ulong local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  lVar2 = *(long *)(g_pSys + 0x220);
  lVar7 = pfmreqhndlrGetGpu(lVar2);
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  if (lVar7 != 0) {
    cVar4 = gpuIsGpuFullPower_IMPL(lVar7);
    if ((((cVar4 != '\0') && (*(char *)(lVar7 + 0x44c) != '\0')) &&
        (*(char *)(lVar7 + 0x44f) == '\0')) &&
       (((*(char *)(lVar7 + 0x450) == '\0' && (*(char *)(lVar7 + 0x451) == '\0')) &&
        (*(char *)(lVar7 + 0x455) == '\0')))) {
      cVar4 = gpuCheckSysmemAccess_IMPL();
      if (cVar4 != '\0') {
        local_38 = 0x8000800000029;
        uVar5 = CONCAT31((int3)(local_30 >> 0x28),*(undefined1 *)(lVar2 + 0x6c7));
        uVar3 = (undefined4)local_28;
        local_28 = (ulong)CONCAT24((ushort)local_30,(undefined4)local_28) | 0x1000000000000;
        local_30 = CONCAT44(uVar5,(uint)(ushort)local_30) | 0x10000;
        local_20 = CONCAT44(uVar3,uVar5);
        local_3c = 8;
        iVar6 = osCallACPI_DSM(lVar7,*(undefined4 *)(*(long *)(g_pSys + 0x220) + 0x910),0x29,
                               (long)&local_28 + 4,&local_3c);
        if (iVar6 == 0) {
          local_3a = 0;
          uVar1 = *(undefined1 *)(lVar2 + 0x6c7);
          *(undefined1 *)(lVar2 + 0x6c6) = uVar1;
          local_3c = CONCAT11(*(undefined1 *)(lVar2 + 0x6c5),uVar1);
          gpuNotifySubDeviceEvent_IMPL
                    (lVar7,0x9e,&local_3c,3,CONCAT11(*(undefined1 *)(lVar2 + 0x6c5),uVar1),0);
        }
      }
    }
  }
  *(undefined1 *)(lVar2 + 0x6c7) = 0xff;
  *(undefined1 *)(lVar2 + 0x6c4) = 0;
  return;
}


// ===== 004865a0 pfmreqhndlrControl_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 pfmreqhndlrControl_IMPL(long param_1,short param_2,undefined2 param_3,undefined8 param_4)

{
  short *psVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  if ((param_1 != 0) &&
     (PTR__handleCmdSystemPfmreqhndlrGetSupportedFunctions_005a02c8 != (undefined *)0x0)) {
    psVar1 = &_PfmreqhndlrControlTable;
    pcVar3 = (code *)PTR__handleCmdSystemPfmreqhndlrGetSupportedFunctions_005a02c8;
    do {
      if (*psVar1 == param_2) {
        uVar2 = (*pcVar3)(param_1,param_3,param_4);
        return uVar2;
      }
      pcVar3 = *(code **)(psVar1 + 0xc);
      psVar1 = psVar1 + 8;
    } while (pcVar3 != (code *)0x0);
  }
  return 0x56;
}


// ===== 00486610 cliresCtrlCmdSystemPfmreqhndlrGetFrmData_IMPL =====

undefined8 cliresCtrlCmdSystemPfmreqhndlrGetFrmData_IMPL(undefined8 param_1,long param_2)

{
  byte bVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  
  lVar2 = *(long *)(g_pSys + 0x220);
  if (lVar2 != 0) {
    bVar1 = *(byte *)(lVar2 + 0x904);
    *(byte *)(param_2 + 0x200) = bVar1;
    uVar4 = bVar1 & 0x3f;
    uVar5 = (ulong)uVar4;
    uVar3 = (ulong)(0x40 - uVar4 & 0xff);
    portMemCopy(param_2,uVar3 * 8,lVar2 + 0x704 + uVar5 * 8,uVar3 * 8);
    if ((char)uVar4 != '\0') {
      portMemCopy(param_2 + uVar3 * 8,uVar5 * 8,lVar2 + 0x704,uVar5 * 8);
    }
    return 0;
  }
  return 0x56;
}


// ===== 004866f0 cliresCtrlCmdSystemPfmreqhndlrSetFrmData_IMPL =====

undefined8 cliresCtrlCmdSystemPfmreqhndlrSetFrmData_IMPL(undefined8 param_1,undefined8 *param_2)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(g_pSys + 0x220);
  if (lVar2 != 0) {
    bVar1 = *(byte *)(lVar2 + 0x904);
    lVar3 = (ulong)(bVar1 & 0x3f) + 0xe0;
    *(undefined8 *)(lVar2 + 4 + lVar3 * 8) = *param_2;
    *(byte *)(lVar2 + 0xb + lVar3 * 8) = bVar1;
    *(byte *)(lVar2 + 0x904) = bVar1 + 1;
    return 0;
  }
  return 0x56;
}


// ===== 00486740 pfmreqhndlrCallACPI =====

ulong pfmreqhndlrCallACPI(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined2 local_a;
  
  uVar1 = *param_2;
  lVar2 = *(long *)(g_pSys + 0x220);
  if (uVar1 == 0x2a) {
    if ((ushort)param_2[6] < 0x2c) {
      nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x3d1,"pfmreqhndlrCallACPI"
                   ,4,"NVRM: buffer to small to hold output.\n");
    }
    else {
      **(uint **)(param_2 + 4) = param_2[1];
      uVar3 = osCallACPI_DSM(param_1,*(undefined4 *)(lVar2 + 0x910),0x2a,
                             *(undefined8 *)(param_2 + 4),param_2 + 6);
      if ((int)uVar3 == 0) {
        return uVar3;
      }
      nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x3dd,"pfmreqhndlrCallACPI"
                   ,4,
                   "NVRM: Unable to retrieve PFM_REQ_HNDLR_PSHAREPARAMS. Possibly not supported/enabled by CPU/ACPI? rc = %x\n"
                   ,uVar3 & 0xffffffff);
    }
  }
  else {
    if (uVar1 < 0x2b) {
      if (uVar1 == 0x1c) {
        *(undefined2 *)(param_2 + 6) = 0;
        param_2[2] = param_2[1];
        local_a = 4;
        uVar3 = osCallACPI_DSM(param_1,*(undefined4 *)(lVar2 + 0x910),0x1c,param_2 + 2,&local_a);
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x3ad,
                     "pfmreqhndlrCallACPI",4,
                     "NVRM: Unable to retrieve PFM_REQ_HNDLR_PCONTROL. Possibly not supported/enabled by CPU/ACPI? rc = %x\n"
                     ,uVar3 & 0xffffffff);
        return 0x56;
      }
      if (uVar1 == 0x20) {
        *(undefined2 *)(param_2 + 6) = 0;
        param_2[2] = param_2[1];
        local_a = 4;
        uVar3 = osCallACPI_DSM(param_1,*(undefined4 *)(lVar2 + 0x910),0x20,param_2 + 2,&local_a);
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x3c3,
                     "pfmreqhndlrCallACPI",4,
                     "NVRM: Unable to retrieve PFM_REQ_HNDLR_PSHARESTATUS. Possibly not supported/enabled by CPU/ACPI? rc = %x\n"
                     ,uVar3 & 0xffffffff);
        return 0x56;
      }
      if (uVar1 == 0) {
        param_2[2] = 0;
        param_2[3] = 0;
        *(undefined2 *)(param_2 + 6) = 0;
        local_a = 8;
        uVar3 = osCallACPI_DSM(param_1,*(undefined4 *)(lVar2 + 0x910),0,param_2 + 2,&local_a);
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x397,
                     "pfmreqhndlrCallACPI",4,
                     "NVRM: Unable to retrieve PFM_REQ_HNDLR_SUPPORT. Possibly not supported/enabled by CPU/ACPI? rc = %x\n"
                     ,uVar3 & 0xffffffff);
        return 0x56;
      }
    }
    else {
      if (uVar1 == 0x2b) {
        uVar3 = osCallACPI_DSM(param_1,*(undefined4 *)(lVar2 + 0x910),0x2b,
                               *(undefined8 *)(param_2 + 4),param_2 + 6);
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x404,
                     "pfmreqhndlrCallACPI",4,
                     "NVRM: Unable to retrieve PFM_REQ_HNDLR_FUNC_SETEDPPLIMITINFO. Possibly not supported/enabled by ACPI? rc = %x\n"
                     ,uVar3 & 0xffffffff);
        return 0x56;
      }
      if (uVar1 == 0x2c) {
        param_2[2] = param_2[1];
        local_a = 4;
        uVar3 = osCallACPI_DSM(param_1,*(undefined4 *)(lVar2 + 0x910),0x2c,param_2 + 2,&local_a);
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x3f2,
                     "pfmreqhndlrCallACPI",4,
                     "NVRM: Unable to retrieve PFM_REQ_HNDLR_FUNC_GETEDPPLIMIT. Possibly not supported/enabled by ACPI? rc = %x\n"
                     ,uVar3 & 0xffffffff);
        return 0x56;
      }
    }
    nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x410,"pfmreqhndlrCallACPI",4
                 ,"NVRM: Unknown request %x\n",uVar1 & 0x1ff);
  }
  return 0x56;
}


// ===== 00486a50 cliresCtrlCmdSystemPfmreqhndlrCallAcpi_IMPL =====

undefined8 cliresCtrlCmdSystemPfmreqhndlrCallAcpi_IMPL(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  long local_28;
  ushort local_20;
  
  if (*(long *)(g_pSys + 0x220) == 0) {
    return 0x56;
  }
  lVar1 = pfmreqhndlrGetGpu();
  if (lVar1 != 0) {
    portMemSet(&local_38,0,0x20);
    local_38 = *param_2;
    local_28 = (long)param_2 + 0xc;
    local_20 = 0x480;
    uVar2 = pfmreqhndlrCallACPI(lVar1,&local_38);
    if ((int)uVar2 == 0) {
      if (local_20 == 0) {
        if (((int)local_38 - 0x1cU & 0xfffffffb) == 0) {
          *(undefined4 *)(param_2 + 1) = 4;
          *(undefined4 *)((long)param_2 + 0xc) = local_30;
        }
        else if ((int)local_38 == 0) {
          *(undefined4 *)(param_2 + 1) = 8;
          *(ulong *)((long)param_2 + 0xc) = CONCAT44(uStack_2c,local_30);
        }
        else {
          *(undefined4 *)(param_2 + 1) = 0;
        }
      }
      else {
        *(uint *)(param_2 + 1) = (uint)local_20;
      }
      return uVar2;
    }
  }
  return 0x56;
}


// ===== 00486b30 _pfmreqhndlrHandlePlatformSetEdppLimitInfoWorkItem =====

void _pfmreqhndlrHandlePlatformSetEdppLimitInfoWorkItem(void)

{
  long lVar1;
  char cVar2;
  long lVar3;
  undefined4 local_60 [4];
  undefined4 *local_50;
  undefined2 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  
  lVar1 = *(long *)(g_pSys + 0x220);
  lVar3 = pfmreqhndlrGetGpu(lVar1);
  if (lVar3 != 0) {
    cVar2 = gpuIsGpuFullPower_IMPL(lVar3);
    if ((((cVar2 != '\0') && (*(char *)(lVar3 + 0x44c) != '\0')) &&
        (*(char *)(lVar3 + 0x44f) == '\0')) &&
       (((*(char *)(lVar3 + 0x450) == '\0' && (*(char *)(lVar3 + 0x451) == '\0')) &&
        (*(char *)(lVar3 + 0x455) == '\0')))) {
      cVar2 = gpuCheckSysmemAccess_IMPL(lVar3);
      if (cVar2 != '\0') {
        portMemSet(local_60,0,0x20);
        portMemSet(&local_40,0,0x24);
        local_3c = *(undefined4 *)(lVar1 + 0x6b8);
        local_40 = 0x10000;
        local_50 = &local_40;
        if (*(int *)(lVar1 + 0x6d4) == 0) {
          local_30 = *(undefined8 *)(lVar1 + 0x6e8);
          local_28 = *(undefined8 *)(lVar1 + 0x6f0);
          local_38 = *(undefined8 *)(lVar1 + 0x6e0);
        }
        local_60[0] = 0x2b;
        local_48 = 0x24;
        pfmreqhndlrCallACPI(lVar3,local_60);
      }
    }
  }
  *(undefined1 *)(lVar1 + 0x6d0) = 0;
  return;
}


// ===== 00486c60 pfmreqhndlrUpdatePerfCounter =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 pfmreqhndlrUpdatePerfCounter(long param_1,uint param_2,undefined4 param_3)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  
  if (100 < param_2) {
    return 0x1f;
  }
  if (param_1 == 0) {
    nvAssertFailedNoLog("pPlatformRequestHandler",
                        "src/kernel/platform/platform_request_handler_ctrl.c",0x4fa);
  }
  else {
    lVar2 = pfmreqhndlrGetGpu();
    if (lVar2 != 0) {
      lVar2 = pfmreqhndlrGetGpu(param_1);
      param_1 = param_1 + (ulong)param_2 * 0x10;
      pcVar1 = *(code **)(*(long *)(lVar2 + 0x1b88) + 0x1a0);
      uVar3 = (*pcVar1)(lVar2,*(long *)(lVar2 + 0x1b88),pcVar1);
      if (*(char *)(param_1 + 0x5b) == '\0') {
        *(undefined4 *)(param_1 + 0x5c) = param_3;
      }
      *(int *)(param_1 + 0x60) = (int)(uVar3 / 1000000);
      *(undefined1 *)(param_1 + 0x5a) = 0;
      return 0;
    }
  }
  return 0x3f;
}


// ===== 00486d40 pfmreqhndlrSampleCounter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

uint pfmreqhndlrSampleCounter(long param_1,uint param_2,int param_3)

{
  code *pcVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_78;
  uint local_74;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  undefined4 local_2c;
  
  lVar3 = pfmreqhndlrGetGpu();
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pPlatformRequestHandler",
                        "src/kernel/platform/platform_request_handler_ctrl.c",0x521);
    return 0x3f;
  }
  if (param_3 == 0) {
    lVar4 = pfmreqhndlrGetGpu(param_1);
    pcVar1 = *(code **)(*(long *)(lVar4 + 0x1b88) + 0x1a0);
    uVar5 = (*pcVar1)(lVar4,*(long *)(lVar4 + 0x1b88),pcVar1);
    param_3 = (int)(uVar5 / 1000000);
  }
  lVar4 = (ulong)param_2 * 0x10 + param_1;
  if ((*(char *)(lVar4 + 0x58) != '\0') &&
     ((*(char *)(lVar4 + 0x5a) != '\0' ||
      (*(uint *)(lVar4 + 100) <= (uint)(param_3 - *(int *)(lVar4 + 0x60)))))) {
    if (param_2 == 0x4a) {
      if (*(char *)(param_1 + 0x6c9) == '\0') {
        local_54 = CONCAT62(local_54._2_6_,1);
        iVar8 = (**(code **)(lVar3 + 0x3b90))
                          (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                           *(undefined4 *)(lVar3 + 0x3b3c),0x20800ace,&local_54,2);
        if (iVar8 == 0) {
          if (*(char *)(param_1 + 0x4fb) == '\0') {
            *(uint *)(param_1 + 0x4fc) = (uint)local_54._1_1_;
          }
          *(int *)(param_1 + 0x500) = param_3;
          *(undefined1 *)(param_1 + 0x4fa) = 0;
          return 0;
        }
      }
    }
    else if (param_2 < 0x4b) {
      if (param_2 == 0x47) {
        if (*(char *)(param_1 + 0x4cb) == '\0') {
          *(undefined4 *)(param_1 + 0x4cc) = 1;
        }
        *(int *)(param_1 + 0x4d0) = param_3;
        *(undefined1 *)(param_1 + 0x4ca) = 0;
      }
      else if ((param_2 < 0x48) && ((param_2 - 0xb & 0xfffffff7) == 0)) {
        uVar6 = pfmreqhndlrGetGpu();
        bVar2 = false;
        local_70 = 0;
        iVar8 = 8;
        pcVar7 = (char *)(param_1 + 0x10b);
        local_54 = 0;
        local_74 = *(uint *)(param_1 + 0x6c0) | 2;
        local_4c = 0;
        local_44 = 0;
        local_3c = 0;
        local_34 = 0;
        local_2c = 0;
        local_78 = 0x2a;
        uVar9 = local_74;
        do {
          if (((uint)(param_3 - *(int *)(pcVar7 + 5)) < *(uint *)(pcVar7 + 9)) || (*pcVar7 != '\0'))
          {
            bVar2 = true;
            uVar9 = uVar9 & ~(1 << ((byte)iVar8 & 0x1f));
          }
          iVar8 = iVar8 + 1;
          pcVar7 = pcVar7 + 0x10;
        } while (iVar8 != 0x11);
        if ((bVar2) && (local_74 = uVar9, uVar9 == 0)) {
          return 0;
        }
        local_68 = &local_54;
        local_60 = 0x2c;
        iVar8 = pfmreqhndlrCallACPI(uVar6,&local_78);
        if (iVar8 != 0) {
          return 0x56;
        }
        if ((local_74 & 0x100) != 0) {
          if ((local_54 & 0x100) == 0) {
            if (*(char *)(param_1 + 0x10b) == '\0') {
              *(undefined1 *)(param_1 + 0x10a) = 1;
              goto LAB_00486f60;
            }
          }
          else if (*(char *)(param_1 + 0x10b) == '\0') {
            *(undefined4 *)(param_1 + 0x10c) = (undefined4)local_4c;
          }
          *(int *)(param_1 + 0x110) = param_3;
          *(undefined1 *)(param_1 + 0x10a) = 0;
        }
LAB_00486f60:
        if ((local_74 & 0x10000) == 0) {
          return 0;
        }
        if ((local_54 & 0x10000) == 0) {
          if (*(char *)(param_1 + 0x18b) == '\0') {
            *(undefined1 *)(param_1 + 0x18a) = 1;
            return (uint)local_54 & 0x10000;
          }
        }
        else if (*(char *)(param_1 + 0x18b) == '\0') {
          *(undefined4 *)(param_1 + 0x18c) = local_2c;
        }
        *(int *)(param_1 + 400) = param_3;
        *(undefined1 *)(param_1 + 0x18a) = 0;
        return 0;
      }
    }
    else if (param_2 == 0x61) {
      if (*(char *)(param_1 + 0x66b) == '\0') {
        *(uint *)(param_1 + 0x66c) = (uint)*(byte *)(param_1 + 0x908);
      }
      *(int *)(param_1 + 0x670) = param_3;
      *(undefined1 *)(param_1 + 0x66a) = 0;
    }
  }
  return 0x56;
}


// ===== 004870e0 pfmreqhndlrGetPerfSensorCounterById_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 pfmreqhndlrGetPerfSensorCounterById_IMPL(long param_1,ushort param_2,undefined4 *param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  int iVar3;
  
  uVar7 = g_pSys;
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("NULL != pCounterVal","src/kernel/platform/platform_request_handler_ctrl.c",
                        0x575);
    return 0x3d;
  }
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pPlatformRequestHandler",
                        "src/kernel/platform/platform_request_handler_ctrl.c",0x576);
    return 0x56;
  }
  *param_3 = 0;
  lVar5 = pfmreqhndlrGetGpu();
  if (lVar5 == 0) {
    return 0x56;
  }
  lVar5 = sysGetOs_IMPL(uVar7);
  if (lVar5 == 0) {
    return 0x56;
  }
  lVar5 = pfmreqhndlrGetGpu(param_1);
  pcVar1 = *(code **)(*(long *)(lVar5 + 0x1b88) + 0x1a0);
  uVar6 = (*pcVar1)(lVar5,*(long *)(lVar5 + 0x1b88),pcVar1);
  if (100 < param_2) {
    nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x589,
                 "pfmreqhndlrGetPerfSensorCounterById_IMPL",4,
                 "NVRM: Invalid counter Id specified = %d.\n",param_2);
    return 0x56;
  }
  lVar5 = (ulong)param_2 * 0x10 + param_1;
  if ((*(char *)(lVar5 + 0x58) == '\0') && (*(char *)(lVar5 + 0x59) == '\0')) {
    return 0x25;
  }
  lVar8 = (ulong)param_2 * 0x10 + param_1;
  if ((*(char *)(lVar8 + 0x59) != '\0') && (*(char *)(lVar8 + 0x5b) == '\0')) {
    iVar3 = (int)(uVar6 / 1000000);
    uVar2 = iVar3 - *(int *)(lVar8 + 0x60);
    if (-1 < (int)uVar2) {
      if (*(uint *)(param_1 + 0x54) < uVar2) {
        if (*(uint *)(lVar8 + 100) < uVar2) {
          if (*(int *)(param_1 + 0x6bc) == 0x200) {
            iVar4 = pfmreqhndlrSampleCounter(param_1,param_2);
            if ((iVar4 != 0x56) && (iVar4 != 0)) {
              nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x5a9,
                           "pfmreqhndlrGetPerfSensorCounterById_IMPL",4,
                           "NVRM: Sampling counter failed for counter id = %d.\n",param_2);
              return 0x3f;
            }
            uVar7 = 0;
          }
          else {
            pfmreqhndlrSampleCounter(param_1,param_2);
            uVar7 = 0x25;
          }
          if ((*(char *)(lVar8 + 0x59) == '\0') || (*(char *)(lVar8 + 0x5b) != '\0'))
          goto LAB_00487215;
        }
        else {
          uVar7 = 0x25;
        }
        uVar2 = iVar3 - *(int *)(lVar8 + 0x60);
        if ((int)uVar2 < 0) goto LAB_00487215;
      }
      else {
        uVar7 = 0x25;
      }
      if ((*(uint *)(param_1 + 0x54) < uVar2) && (*(uint *)(lVar8 + 100) < uVar2)) {
        return uVar7;
      }
      goto LAB_00487215;
    }
  }
  uVar7 = 0x25;
LAB_00487215:
  if (*(char *)(lVar5 + 0x5a) != '\0') {
    return uVar7;
  }
  *param_3 = *(undefined4 *)(lVar5 + 0x5c);
  return 0;
}


// ===== 004873c0 _pfmreqhndlrUpdateTgpuLimit =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _pfmreqhndlrUpdateTgpuLimit(long param_1,long param_2)

{
  ulong uVar1;
  uint local_20;
  int local_1c;
  
  uVar1 = pfmreqhndlrGetPerfSensorCounterById_IMPL(param_1,0xb,&local_20);
  if ((int)uVar1 == 0) {
    local_1c = local_20 << 8;
    if ((*(int *)(param_1 + 0x6bc) != 0x200) || ((local_20 & 0xffffff) != 0)) {
      uVar1 = (**(code **)(param_2 + 0x3b90))
                        (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                         *(undefined4 *)(param_2 + 0x3b3c),0x20800ad1,&local_1c,4);
    }
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,"PlatformRequestHandler failed to get target temp from SBIOS",
             "src/kernel/platform/platform_request_handler_ctrl.c",0x87b);
  return uVar1 & 0xffffffff;
}


// ===== 00487470 pfmreqhndlrOperatingLimitUpdate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong pfmreqhndlrOperatingLimitUpdate_IMPL(long param_1,uint param_2,ulong param_3,char param_4)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  
  uVar7 = param_3 & 0xffffffff;
  uVar4 = pfmreqhndlrGetGpu();
  if (param_2 < 9) {
    if (param_1 == 0) {
      uVar7 = 0x3f;
      nvAssertFailedNoLog("NULL != pPlatformRequestHandler",
                          "src/kernel/platform/platform_request_handler_ctrl.c",0x106);
    }
    else {
      if (param_4 == '\0') {
        lVar5 = pfmreqhndlrGetGpu(param_1);
        pcVar1 = *(code **)(*(long *)(lVar5 + 0x1b88) + 0x1a0);
        uVar7 = (*pcVar1)(lVar5,*(long *)(lVar5 + 0x1b88),pcVar1);
        lVar5 = (ulong)(param_2 + 0xb) * 0x10 + param_1;
        if (*(char *)(lVar5 + 0x5b) == '\0') {
          *(undefined1 *)(lVar5 + 0x5a) = 1;
          uVar3 = *(uint *)(param_1 + 0x54);
          if (*(uint *)(param_1 + 0x54) < *(uint *)(lVar5 + 100)) {
            uVar3 = *(uint *)(lVar5 + 100);
          }
          *(uint *)(lVar5 + 0x60) = ((int)(uVar7 / 1000000) - uVar3) + -1;
        }
      }
      else {
        if (param_2 == 0) {
          uVar3 = (uint)(param_3 >> 8) & 0xffffff;
          uVar6 = (uint)(uVar7 >> 7) & 1;
          if ((int)param_3 < 0) {
            uVar3 = uVar3 | 0xff000000;
          }
          uVar2 = -uVar6;
          if (-1 < (int)param_3) {
            uVar2 = uVar6;
          }
          uVar7 = (ulong)(uVar3 + uVar2);
        }
        uVar3 = pfmreqhndlrUpdatePerfCounter(param_1,param_2 + 0xb,uVar7);
        if (uVar3 != 0) {
          nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x11c,
                       "pfmreqhndlrOperatingLimitUpdate_IMPL",4,
                       "NVRM: Update perf counter failed.\n");
          return (ulong)uVar3;
        }
      }
      uVar3 = 1 << ((byte)param_2 & 0x1f);
      *(uint *)(param_1 + 0x700) = *(uint *)(param_1 + 0x700) | uVar3;
      if (*(char *)(param_1 + 0x6fc) == '\0') {
        uVar6 = osQueueWorkItem(uVar4,_pfmreqhndlrUpdateSystemParamLimitWorkItem,0,0x58);
        if (uVar6 == 0) {
          *(undefined1 *)(param_1 + 0x6fc) = 1;
        }
        else {
          if (uVar6 != 0x56) {
            return (ulong)uVar6;
          }
          *(uint *)(param_1 + 0x700) = *(uint *)(param_1 + 0x700) & ~uVar3;
          if (*(char *)(param_1 + 0x6fc) == '\0') {
            uVar4 = pfmreqhndlrGetGpu(param_1);
            if (param_2 != 0) {
              return 0x56;
            }
            uVar7 = _pfmreqhndlrUpdateTgpuLimit(param_1,uVar4);
            return uVar7;
          }
        }
      }
      uVar7 = 0x10005;
    }
  }
  else {
    uVar7 = 0x1f;
  }
  return uVar7;
}


// ===== 004876b0 _pfmreqhndlrUpdateSystemParamLimitWorkItem =====

void _pfmreqhndlrUpdateSystemParamLimitWorkItem(void)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  
  lVar1 = *(long *)(g_pSys + 0x220);
  uVar3 = *(uint *)(lVar1 + 0x700);
  if (uVar3 != 0) {
    if ((uVar3 & 1) != 0) {
      uVar2 = pfmreqhndlrGetGpu(lVar1);
      _pfmreqhndlrUpdateTgpuLimit(lVar1,uVar2);
    }
    while (uVar3 = uVar3 >> 1, uVar3 != 0) {
      while ((uVar3 & 1) != 0) {
        pfmreqhndlrGetGpu(lVar1);
        uVar3 = uVar3 >> 1;
        if (uVar3 == 0) goto LAB_004876f5;
      }
    }
  }
LAB_004876f5:
  *(undefined1 *)(lVar1 + 0x6fc) = 0;
  *(undefined4 *)(lVar1 + 0x700) = 0;
  return;
}


// ===== 00487730 cliresCtrlCmdSystemPfmreqhndlrCtrl_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresCtrlCmdSystemPfmreqhndlrCtrl_IMPL(undefined8 param_1,uint *param_2)

{
  long lVar1;
  code *pcVar2;
  short sVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  char cVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  uint local_4c;
  int local_48 [5];
  undefined2 uStack_34;
  short sStack_32;
  uint local_30;
  int iStack_2c;
  
  lVar1 = *(long *)(g_pSys + 0x220);
  if ((lVar1 != 0) && (lVar5 = pfmreqhndlrGetGpu(lVar1), lVar5 != 0)) {
    lVar6 = pfmreqhndlrGetGpu(lVar1);
    pcVar2 = *(code **)(*(long *)(lVar6 + 0x1b88) + 0x1a0);
    uVar7 = (*pcVar2)(lVar6,*(long *)(lVar6 + 0x1b88),pcVar2);
    uVar12 = *param_2;
    if (uVar12 == 0x2e) {
      if (*(char *)(lVar1 + 0x6c9) == '\0') {
        local_48[0] = CONCAT31(local_48[0]._1_3_,(char)param_2[1]);
        uVar8 = (**(code **)(lVar5 + 0x3b90))
                          (lVar5 + 0x3b58,*(undefined4 *)(lVar5 + 0x3b34),
                           *(undefined4 *)(lVar5 + 0x3b3c),0x20800acf,local_48,1);
        return uVar8;
      }
    }
    else {
      if (uVar12 < 0x2f) {
        if (uVar12 < 0xe) {
          if (3 < uVar12) {
            return 0x1f;
          }
          if (uVar12 == 2) {
            if ((ushort)((short)param_2[1] - 0xbU) < 9) {
              uVar12 = param_2[1] & 0xffff;
              iVar4 = pfmreqhndlrGetPerfSensorCounterById_IMPL(lVar1,uVar12,&local_4c);
              if (iVar4 == 0) {
                param_2[3] = local_4c;
                uVar12 = (*(char *)(lVar1 + 0x5b + (ulong)uVar12 * 0x10) == '\0') + 1;
              }
              else {
                param_2[3] = 0;
                uVar12 = (*(char *)(lVar1 + 0x58 + (ulong)uVar12 * 0x10) == '\0') + 3;
              }
              param_2[6] = uVar12;
              param_2[4] = 1;
              param_2[5] = 100;
              return 0;
            }
            return 0x1f;
          }
          if (uVar12 == 3) {
            sVar3 = (short)param_2[1];
            if (8 < (ushort)(sVar3 - 0xbU)) {
              return 0x1f;
            }
            uVar12 = param_2[2];
            uVar10 = (ulong)(param_2[1] & 0xffff);
            lVar6 = uVar10 * 0x10 + lVar1;
            iVar4 = (int)(uVar7 / 1000000);
            if (uVar12 == 0) {
              if (*(char *)(lVar6 + 0x5b) != '\0') {
                *(undefined2 *)(lVar1 + 0x5a + uVar10 * 0x10) = 1;
                uVar11 = *(uint *)(lVar6 + 100);
                if (*(uint *)(lVar6 + 100) <= *(uint *)(lVar1 + 0x54)) {
                  uVar11 = *(uint *)(lVar1 + 0x54);
                }
                *(uint *)(lVar6 + 0x60) = (iVar4 - uVar11) + -1;
              }
            }
            else {
              if (*(char *)(lVar6 + 0x5b) == '\0') {
                *(uint *)(lVar6 + 0x5c) = uVar12;
              }
              *(int *)(lVar6 + 0x60) = iVar4;
              *(undefined2 *)(lVar1 + 0x5a + uVar10 * 0x10) = 0x100;
            }
            if (sVar3 != 0xb) {
              return 0;
            }
            iVar4 = pfmreqhndlrGetPerfSensorCounterById_IMPL(lVar1,0xb,&local_4c);
            if (iVar4 != 0) {
              return 0;
            }
            local_48[0] = uVar12 << 8;
            uVar8 = (**(code **)(lVar5 + 0x3b90))
                              (lVar5 + 0x3b58,*(undefined4 *)(lVar5 + 0x3b34),
                               *(undefined4 *)(lVar5 + 0x3b3c),0x20800ad1,local_48,4);
            if ((int)uVar8 != 0) {
              return 0x56;
            }
            return uVar8;
          }
        }
        else {
          if (uVar12 == 0x1a) {
            uVar8 = pfmreqhndlrGetPerfSensorCounterById_IMPL(lVar1,(short)param_2[1],&local_4c);
            if ((int)uVar8 != 0) {
              param_2[3] = 0;
              param_2[4] = 0;
              return uVar8;
            }
            param_2[4] = 1;
            param_2[3] = local_4c;
            return uVar8;
          }
          if (uVar12 < 0x1b) {
            if (uVar12 - 0x16 < 2) {
              return 0x56;
            }
          }
          else {
            if (uVar12 < 0x1d) {
              return 0x56;
            }
            if (uVar12 - 0x26 < 8) {
              return 0x56;
            }
          }
        }
      }
      else if (uVar12 < 0x48) {
        if (0x45 < uVar12) {
          local_48[3] = 0;
          local_48[4] = 0;
          local_48[0] = 0x26;
          local_48[1] = 0x80008;
          local_48[2] = 0x10000;
          iStack_2c = 0;
          if (uVar12 == 0x47) {
            local_48[3] = param_2[1];
            local_48[0] = 0x27;
          }
          uStack_34 = 0;
          sStack_32 = 1;
          local_4c = CONCAT22(local_4c._2_2_,8);
          local_30 = local_48[3];
          uVar8 = osCallACPI_DSM(lVar5,*(undefined4 *)(*(long *)(g_pSys + 0x220) + 0x910),
                                 local_48[0],&uStack_34,&local_4c);
          if ((int)uVar8 == 0) {
            if (sStack_32 != 1) {
              return 0x25;
            }
            param_2[3] = local_30;
            return uVar8;
          }
          return 0x56;
        }
        if (uVar12 == 0x2f) {
          if (*(char *)(lVar1 + 0x6c9) != '\0') {
            param_2[3] = 0;
            return 0x56;
          }
          uVar8 = pfmreqhndlrGetPerfSensorCounterById_IMPL(lVar1,0x4a,&local_4c);
          if ((int)uVar8 != 0) {
            param_2[3] = 0;
            return uVar8;
          }
          param_2[3] = local_4c;
          return uVar8;
        }
        if (uVar12 - 0x44 < 2) {
          local_48[3] = 0;
          local_48[4] = 0;
          local_48[1] = 0xc000c;
          local_48[2] = 0x10000;
          if (uVar12 == 0x45) {
            local_48[3] = param_2[1];
            local_48[0] = 0x25;
            local_48[4] = local_48[3] * 2;
          }
          else {
            local_48[0] = 0x24;
          }
          local_4c = CONCAT22(local_4c._2_2_,0xc);
          uStack_34 = 0;
          sStack_32 = 1;
          local_30 = local_48[3];
          iStack_2c = local_48[4];
          uVar8 = osCallACPI_DSM(lVar5,*(undefined4 *)(*(long *)(g_pSys + 0x220) + 0x910),
                                 local_48[0],&uStack_34,&local_4c);
          if ((int)uVar8 == 0) {
            if (sStack_32 != 1) {
              return 0x25;
            }
            *(ulong *)(param_2 + 3) = CONCAT44(iStack_2c,local_30);
            return uVar8;
          }
          return 0x56;
        }
      }
      else {
        if (uVar12 == 0x48) {
          param_2[3] = (uint)*(byte *)(lVar1 + 0x6c6);
          param_2[4] = (uint)*(byte *)(lVar1 + 0x6c5);
          return 0;
        }
        if (uVar12 == 0x49) {
          if (*(byte *)(lVar1 + 0x6c5) == 0) {
            return 0x25;
          }
          cVar9 = (char)param_2[1];
          if (*(char *)(lVar1 + 0x6c6) == cVar9) {
            return 0;
          }
          if (cVar9 == -1) {
            return 0x25;
          }
          if ((*(byte *)(lVar1 + 0x6c5) >> (param_2[1] & 0x1f) & 1) == 0) {
            return 0x25;
          }
          if (*(char *)(lVar1 + 0x6c4) != '\0') {
            return 3;
          }
          *(char *)(lVar1 + 0x6c7) = cVar9;
          uVar8 = osQueueWorkItem(lVar5,_pfmreqhndlrUpdatePlatformPowerModeWorkItem,0,0x58);
          if ((int)uVar8 == 0) {
            *(undefined1 *)(lVar1 + 0x6c4) = 1;
            return uVar8;
          }
          return uVar8;
        }
      }
      nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x2ed,
                   "cliresCtrlCmdSystemPfmreqhndlrCtrl_IMPL",4,"NVRM: Unknown request %x\n");
    }
  }
  return 0x56;
}


// ===== 00487e30 _pfmreqhndlrUpdatePpmdLimit =====

ulong _pfmreqhndlrUpdatePpmdLimit(long param_1,undefined8 param_2,char param_3)

{
  ulong uVar1;
  undefined2 local_2f;
  undefined1 local_2d;
  uint local_2c [3];
  
  local_2c[0] = 0;
  local_2f = 0;
  local_2d = 0;
  uVar1 = pfmreqhndlrGetPerfSensorCounterById_IMPL(param_1,0x13,local_2c);
  if ((int)uVar1 == 0) {
    if ((*(char *)(param_1 + 0x188) != '\0') && (*(char *)(param_1 + 0x18a) == '\0')) {
      *(char *)(param_1 + 0x6c5) = (char)(local_2c[0] >> 8);
      if (param_3 != '\0') {
        *(char *)(param_1 + 0x6c6) = (char)local_2c[0];
      }
      local_2f = (undefined2)local_2c[0];
      local_2d = 1;
      gpuNotifySubDeviceEvent_IMPL(param_2,0x9e,&local_2f,3,local_2c[0] & 0xffff | 0x10000,0);
      uVar1 = uVar1 & 0xffffffff;
    }
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "PlatformRequestHandler failed to get platform power mode from SBIOS",
             "src/kernel/platform/platform_request_handler_ctrl.c",0x842);
  return uVar1 & 0xffffffff;
}


// ===== 00487f00 pfmreqhndlrHandleCheckPM1Available_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pfmreqhndlrHandleCheckPM1Available_IMPL(undefined8 param_1,long param_2,undefined1 *param_3)

{
  int iVar1;
  undefined2 local_1a;
  
  local_1a = 1;
  iVar1 = (**(code **)(param_2 + 0x3b90))
                    (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                     *(undefined4 *)(param_2 + 0x3b3c),0x20800ace,&local_1a,2);
  if (iVar1 == 0) {
    *param_3 = local_1a._1_1_;
  }
  return;
}


// ===== 00487f60 pfmreqhndlrHandleEdppeakLimitUpdate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int pfmreqhndlrHandleEdppeakLimitUpdate_IMPL(long param_1,long param_2,byte param_3)

{
  char cVar1;
  int iVar2;
  ulong local_30 [2];
  
  cVar1 = gpuIsGpuFullPower_IMPL(param_2);
  if (cVar1 != '\0') {
    local_30[0] = (ulong)param_3;
    iVar2 = (**(code **)(param_2 + 0x3b90))
                      (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                       *(undefined4 *)(param_2 + 0x3b3c),0x20800ad0,local_30,8);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x653,
                   "pfmreqhndlrHandleEdppeakLimitUpdate_IMPL",4,
                   "NVRM: Error updating EDPpeak Limit State: 0x%08x\n");
      return iVar2;
    }
    *(byte *)(param_1 + 0x6cb) = param_3;
  }
  return 0;
}


// ===== 00488020 pfmreqhndlrHandlePlatformEdppLimitUpdate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int pfmreqhndlrHandlePlatformEdppLimitUpdate_IMPL(undefined8 param_1,long param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint local_20;
  int local_1c;
  
  cVar1 = gpuIsGpuFullPower_IMPL(param_2);
  if (cVar1 != '\0') {
    local_20 = (uint)(param_3 != 0);
    local_1c = param_3;
    iVar2 = (**(code **)(param_2 + 0x3b90))
                      (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                       *(undefined4 *)(param_2 + 0x3b3c),0x20800ad0,&local_20,8);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x68b,
                   "pfmreqhndlrHandlePlatformEdppLimitUpdate_IMPL",4,
                   "NVRM: Error updating EDPpeak Limit State: 0x%08x\n");
      return iVar2;
    }
  }
  return 0;
}


// ===== 004880e0 pfmreqhndlrHandlePlatformGetEdppLimit_IMPL =====

ulong pfmreqhndlrHandlePlatformGetEdppLimit_IMPL
                (undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  ulong uVar1;
  undefined2 local_3a;
  undefined8 local_38;
  undefined4 local_30 [6];
  
  portMemSet(&local_38,0,0x20);
  local_30[0] = 0x10000;
  local_38 = 0x100000000002c;
  local_3a = 4;
  uVar1 = osCallACPI_DSM(param_2,*(undefined4 *)(*(long *)(g_pSys + 0x220) + 0x910),0x2c,local_30,
                         &local_3a);
  if ((int)uVar1 == 0) {
    *param_3 = local_30[0];
    return uVar1;
  }
  nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x3f2,"pfmreqhndlrCallACPI",4,
               "NVRM: Unable to retrieve PFM_REQ_HNDLR_FUNC_GETEDPPLIMIT. Possibly not supported/enabled by ACPI? rc = %x\n"
               ,uVar1 & 0xffffffff);
  nvDbg_Printf("src/kernel/platform/platform_request_handler_ctrl.c",0x6b2,
               "pfmreqhndlrHandlePlatformGetEdppLimit_IMPL",4,
               "NVRM: Error querying EDPpeak Limit from platform: 0x%08x\n",0x56);
  return 0x56;
}


// ===== 004881d0 pfmreqhndlrHandlePlatformSetEdppLimitInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 pfmreqhndlrHandlePlatformSetEdppLimitInfo_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  cVar1 = gpuIsGpuFullPower_IMPL(param_2);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0x6d4) = 0x11;
    uVar2 = 0;
    cVar1 = *(char *)(param_1 + 0x6d0);
  }
  else {
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    uVar2 = (**(code **)(param_2 + 0x3b90))
                      (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                       *(undefined4 *)(param_2 + 0x3b3c),0x20800afd,&local_30,0x18);
    uVar3 = 0x1f;
    if ((int)uVar2 == 0) {
      *(undefined4 *)(param_1 + 0x6f8) = 0;
      *(undefined8 *)(param_1 + 0x6e0) = local_30;
      *(undefined8 *)(param_1 + 0x6e8) = local_28;
      *(undefined8 *)(param_1 + 0x6f0) = local_20;
      uVar3 = 0;
    }
    *(undefined4 *)(param_1 + 0x6d4) = uVar3;
    cVar1 = *(char *)(param_1 + 0x6d0);
  }
  if ((cVar1 == '\0') &&
     (uVar2 = osQueueWorkItem(param_2,_pfmreqhndlrHandlePlatformSetEdppLimitInfoWorkItem,0,0x58),
     (int)uVar2 == 0)) {
    *(undefined1 *)(param_1 + 0x6d0) = 1;
    return uVar2;
  }
  return uVar2;
}


// ===== 004882e0 _pfmreqhndlrCallPshareStatus =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _pfmreqhndlrCallPshareStatus(long param_1,byte param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  char cVar8;
  uint *local_c0;
  undefined4 local_ac;
  undefined8 local_a8;
  uint local_a0;
  undefined8 local_98;
  undefined2 local_90;
  undefined8 local_88 [2];
  uint *local_78;
  undefined2 local_70;
  uint local_64 [9];
  undefined4 local_40;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pPlatformRequestHandler",
                        "src/kernel/platform/platform_request_handler_ctrl.c",0x92c);
    return 0x3f;
  }
  lVar4 = pfmreqhndlrGetGpu();
  local_a8 = 0x20;
  local_90 = 0;
  local_98 = 0;
  iVar2 = pfmreqhndlrCallACPI(lVar4,&local_a8);
  if (iVar2 != 0) {
    return 0x56;
  }
  *(byte *)(param_1 + 0x6a9) = (byte)local_a0 & 1;
  uVar7 = (local_a0 & 0x200000) >> 0x15;
  *(byte *)(param_1 + 0x6ab) = (byte)(local_a0 >> 0x16) & 1;
  *(char *)(param_1 + 0x6aa) = (char)uVar7;
  *(byte *)(param_1 + 0x6ac) = (byte)(local_a0 >> 0x14) & 1;
  iVar2 = 0;
  if ((local_a0 & 0x200000) == 0) {
    if (*(char *)(param_1 + 0x6cb) != '\0') goto LAB_00488440;
  }
  else if (*(char *)(param_1 + 0x6cb) == '\0') {
LAB_00488440:
    if (((param_2 == 0) &&
        (iVar3 = pfmreqhndlrHandleEdppeakLimitUpdate_IMPL(param_1,lVar4,uVar7), iVar3 != 0)) &&
       (iVar3 != 0x56)) {
      iVar2 = iVar3;
    }
  }
  if ((local_a0 & 0x2000000) == 0) {
    cVar8 = *(char *)(param_1 + 0x6ab);
    if (cVar8 != '\0') {
      if (*(char *)(param_1 + 0x6cc) == '\0') goto LAB_00488498;
      goto LAB_004883db;
    }
    if (*(char *)(param_1 + 0x6cc) == '\0') goto LAB_004883db;
LAB_00488498:
    if (param_2 == 0) goto LAB_0048877b;
LAB_004884a1:
    if ((*(char *)(param_1 + 0x6ac) == '\0') || (*(char *)(param_1 + 0x6cd) != '\0'))
    goto LAB_00488400;
  }
  else {
    local_64[0] = 0;
    iVar3 = pfmreqhndlrHandlePlatformGetEdppLimit_IMPL(param_1,lVar4,local_64);
    if ((iVar3 == 0) || (iVar3 == 0x56)) {
      *(uint *)(param_1 + 0x6b8) = local_64[0];
      iVar3 = iVar2;
    }
    iVar2 = iVar3;
    if (param_2 == 0) {
      iVar3 = pfmreqhndlrHandlePlatformEdppLimitUpdate_IMPL
                        (param_1,lVar4,*(undefined4 *)(param_1 + 0x6b8));
      cVar8 = *(char *)(param_1 + 0x6ab);
      if ((iVar3 == 0) || (iVar3 == 0x56)) {
        iVar3 = iVar2;
      }
      iVar2 = iVar3;
      if (cVar8 == '\0') {
        if (*(char *)(param_1 + 0x6cc) == '\0') goto LAB_00488400;
        cVar8 = '\0';
      }
      else if (*(char *)(param_1 + 0x6cc) != '\0') goto LAB_00488400;
LAB_0048877b:
      local_c0 = local_64;
      local_64[0] = CONCAT31(local_64[0]._1_3_,cVar8);
      iVar3 = (**(code **)(lVar4 + 0x3b90))
                        (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),
                         *(undefined4 *)(lVar4 + 0x3b3c),0x20800ad2,local_c0,1);
      if (iVar3 == 0) {
        *(char *)(param_1 + 0x6cc) = cVar8;
      }
      else if (iVar3 != 0x56) {
        iVar2 = iVar3;
      }
      goto LAB_00488400;
    }
    *(undefined1 *)(param_1 + 0x6d1) = 1;
    if (*(char *)(param_1 + 0x6ab) == '\0') {
      if (*(char *)(param_1 + 0x6cc) != '\0') goto LAB_004884a1;
    }
    else if (*(char *)(param_1 + 0x6cc) == '\0') goto LAB_004884a1;
LAB_004883db:
    if ((*(char *)(param_1 + 0x6ac) == '\0') ||
       ((*(char *)(param_1 + 0x6cd) != '\0' || ((param_2 & 1) == 0)))) goto LAB_00488400;
  }
  portMemSet(local_88,0,0x20);
  portMemSet(local_64,0,0x2c);
  local_88[0] = 0x80020000002a;
  local_70 = 0x2c;
  local_78 = local_64;
  iVar3 = pfmreqhndlrCallACPI(lVar4,local_88);
  if ((iVar3 == 0) && ((local_64[0] & 0x8000) != 0)) {
    *(undefined1 *)(param_1 + 0x6cd) = 1;
    *(undefined4 *)(param_1 + 0x6b0) = local_40;
    local_ac = local_40;
    (**(code **)(lVar4 + 0x3b90))
              (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),*(undefined4 *)(lVar4 + 0x3b3c),
               0x20800ad3,&local_ac,4);
  }
LAB_00488400:
  if (*(char *)(param_1 + 0x6a9) != '\0') {
    lVar5 = pfmreqhndlrGetGpu(param_1);
    pcVar1 = *(code **)(*(long *)(lVar5 + 0x1b88) + 0x1a0);
    uVar6 = (*pcVar1)(lVar5,*(long *)(lVar5 + 0x1b88),pcVar1);
    iVar3 = (int)(uVar6 / 1000000);
    if (*(char *)(param_1 + 0x10b) == '\0') {
      *(undefined1 *)(param_1 + 0x10a) = 1;
      uVar7 = *(uint *)(param_1 + 0x54);
      if (*(uint *)(param_1 + 0x54) < *(uint *)(param_1 + 0x114)) {
        uVar7 = *(uint *)(param_1 + 0x114);
      }
      *(uint *)(param_1 + 0x110) = (iVar3 - uVar7) + -1;
    }
    if (*(char *)(param_1 + 0x18b) == '\0') {
      *(undefined1 *)(param_1 + 0x18a) = 1;
      uVar7 = *(uint *)(param_1 + 0x54);
      if (*(uint *)(param_1 + 0x54) < *(uint *)(param_1 + 0x194)) {
        uVar7 = *(uint *)(param_1 + 0x194);
      }
      *(uint *)(param_1 + 400) = (iVar3 - uVar7) + -1;
    }
    iVar3 = _pfmreqhndlrUpdateTgpuLimit(param_1,lVar4);
    if ((iVar2 == 0) && (iVar3 != 0x56)) {
      iVar2 = iVar3;
    }
    if (((*(int *)(param_1 + 0x6bc) == 0x200) &&
        (iVar3 = _pfmreqhndlrUpdatePpmdLimit(param_1,lVar4,0), iVar2 == 0)) && (iVar3 != 0x56)) {
      iVar2 = iVar3;
    }
    *(undefined1 *)(param_1 + 0x6a9) = 0;
  }
  if (((local_a0 & 0x4000000) != 0) &&
     (iVar3 = pfmreqhndlrHandlePlatformSetEdppLimitInfo_IMPL(param_1,lVar4), iVar3 != 0)) {
    if (iVar3 != 0x56) {
      iVar2 = iVar3;
    }
    return iVar2;
  }
  return iVar2;
}


// ===== 00488830 pfmreqhndlrInitSensors =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 pfmreqhndlrInitSensors(long param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  uint *puVar8;
  int iVar9;
  bool bVar10;
  undefined8 local_48;
  uint local_3c;
  uint *local_38;
  undefined2 local_30;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pPlatformRequestHandler",
                        "src/kernel/platform/platform_request_handler_ctrl.c",0x454);
    return 0x3f;
  }
  lVar5 = pfmreqhndlrGetGpu();
  if (lVar5 == 0) {
    nvAssertFailedNoLog("NULL != pGpu","src/kernel/platform/platform_request_handler_ctrl.c",0x457);
    return 0x3f;
  }
  portMemSet(param_1 + 0x50,0,0x674);
  uVar3 = 0x200;
  if ((*(char *)(param_1 + 0x4a) == '\0') && (uVar3 = 0x200, *(int *)(param_1 + 0x910) != 6)) {
    uVar3 = 0x100;
  }
  *(undefined4 *)(param_1 + 0x6bc) = uVar3;
  lVar6 = pfmreqhndlrGetGpu(param_1);
  pcVar2 = *(code **)(*(long *)(lVar6 + 0x1b88) + 0x1a0);
  uVar7 = (*pcVar2)(lVar6,*(long *)(lVar6 + 0x1b88),pcVar2);
  *(undefined4 *)(param_1 + 0x54) = 0x14;
  *(undefined1 *)(param_1 + 0x6a8) = 0;
  portMemSet(&local_48,0,0x20);
  local_48 = 0;
  local_38 = (uint *)0x0;
  local_30 = 0;
  iVar4 = pfmreqhndlrCallACPI(lVar5,&local_48);
  iVar9 = (int)(uVar7 / 1000000);
  if (iVar4 == 0) {
    bVar10 = (~local_3c & 0x401) == 0;
    *(bool *)(param_1 + 0x6a8) = bVar10;
    if (!bVar10) goto LAB_00488918;
  }
  else if (*(char *)(param_1 + 0x6a8) == '\0') goto LAB_00488918;
  _pfmreqhndlrCallPshareStatus(param_1,1);
  puVar8 = (uint *)portMemAllocNonPaged(0x2c);
  if (puVar8 != (uint *)0x0) {
    portMemSet(puVar8,0,0x2c);
    portMemSet(&local_48,0,0x20);
    local_48 = 0x101010000002a;
    local_30 = 0x2c;
    local_38 = puVar8;
    iVar4 = pfmreqhndlrCallACPI(lVar5,&local_48);
    if (iVar4 == 0) {
      *(uint *)(param_1 + 0x50) = puVar8[1];
      uVar1 = *puVar8;
      *(undefined2 *)(param_1 + 0x1c8) = 1;
      *(undefined4 *)(param_1 + 0x1d4) = 0x14;
      *(uint *)(param_1 + 0x6c0) = uVar1 & 0x10100;
      if (*(char *)(param_1 + 0x1cb) == '\0') {
        *(uint *)(param_1 + 0x1cc) = uVar1 & 0x10100;
      }
      *(int *)(param_1 + 0x1d0) = iVar9;
      *(undefined1 *)(param_1 + 0x1ca) = 0;
      if ((*puVar8 & 0x100) != 0) {
        *(undefined2 *)(param_1 + 0x108) = 0x101;
        *(undefined4 *)(param_1 + 0x114) = 0x14;
        if (*(char *)(param_1 + 0x10b) == '\0') {
          *(undefined1 *)(param_1 + 0x10a) = 1;
          uVar1 = *(uint *)(param_1 + 0x54);
          if (*(uint *)(param_1 + 0x54) < 0x14) {
            uVar1 = 0x14;
          }
          *(uint *)(param_1 + 0x110) = (iVar9 - uVar1) + -1;
        }
        *(undefined2 *)(param_1 + 0x198) = 1;
        *(undefined4 *)(param_1 + 0x1a4) = 0x14;
        if (*(char *)(param_1 + 0x19b) == '\0') {
          *(undefined1 *)(param_1 + 0x19a) = 1;
          uVar1 = *(uint *)(param_1 + 0x54);
          if (*(uint *)(param_1 + 0x54) < 0x14) {
            uVar1 = 0x14;
          }
          *(uint *)(param_1 + 0x1a0) = (iVar9 - uVar1) + -1;
          *(uint *)(param_1 + 0x19c) = puVar8[2];
        }
        *(int *)(param_1 + 0x1a0) = iVar9;
        *(undefined1 *)(param_1 + 0x19a) = 0;
      }
      if ((*(int *)(param_1 + 0x6bc) == 0x200) && ((*puVar8 & 0x10000) != 0)) {
        *(undefined4 *)(param_1 + 0x6c4) = 0xffff0000;
        *(undefined2 *)(param_1 + 0x188) = 0x101;
        *(undefined4 *)(param_1 + 0x194) = 0x14;
        if (*(char *)(param_1 + 0x18b) == '\0') {
          *(undefined1 *)(param_1 + 0x18a) = 1;
          uVar1 = *(uint *)(param_1 + 0x54);
          if (*(uint *)(param_1 + 0x54) < 0x14) {
            uVar1 = 0x14;
          }
          *(uint *)(param_1 + 400) = (iVar9 - uVar1) + -1;
        }
        _pfmreqhndlrUpdatePpmdLimit(param_1,lVar5,1);
      }
    }
    portMemFree(puVar8);
  }
LAB_00488918:
  *(undefined2 *)(param_1 + 0x668) = 0x101;
  *(undefined4 *)(param_1 + 0x674) = 0x14;
  if (*(char *)(param_1 + 0x66b) == '\0') {
    *(undefined1 *)(param_1 + 0x66a) = 1;
    uVar1 = *(uint *)(param_1 + 0x54);
    if (*(uint *)(param_1 + 0x54) < 0x14) {
      uVar1 = 0x14;
    }
    *(uint *)(param_1 + 0x670) = (iVar9 - uVar1) + -1;
  }
  *(undefined2 *)(param_1 + 0x4f8) = 0x101;
  *(undefined4 *)(param_1 + 0x504) = 0x14;
  if (*(char *)(param_1 + 0x4fb) == '\0') {
    *(undefined1 *)(param_1 + 0x4fa) = 1;
    uVar1 = *(uint *)(param_1 + 0x54);
    if (*(uint *)(param_1 + 0x54) < 0x14) {
      uVar1 = 0x14;
    }
    *(uint *)(param_1 + 0x500) = (iVar9 - uVar1) + -1;
  }
  *(undefined2 *)(param_1 + 0x4c8) = 0x101;
  *(undefined4 *)(param_1 + 0x4d4) = 0x14;
  if (*(char *)(param_1 + 0x4cb) == '\0') {
    *(undefined1 *)(param_1 + 0x4ca) = 1;
    uVar1 = *(uint *)(param_1 + 0x54);
    if (*(uint *)(param_1 + 0x54) < 0x14) {
      uVar1 = 0x14;
    }
    *(uint *)(param_1 + 0x4d0) = (iVar9 - uVar1) + -1;
  }
  return 0;
}


// ===== 00488c90 pfmreqhndlrHandleStatusChangeEvent =====

ulong pfmreqhndlrHandleStatusChangeEvent(long param_1,undefined8 param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 local_38;
  uint local_2c;
  undefined8 local_28;
  undefined2 local_20;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pPlatformRequestHandler",
                        "src/kernel/platform/platform_request_handler_ctrl.c",0x5d8);
    return 0x3f;
  }
  iVar1 = _pfmreqhndlrCallPshareStatus(param_1,0);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"PshareStatus","src/kernel/platform/platform_request_handler_ctrl.c",0x5de);
  }
  if (*(int *)(param_1 + 0x6bc) == 0x200) {
    portMemSet(&local_38,0,0x20);
    local_38 = 0;
    local_28 = 0;
    local_20 = 0;
    iVar1 = pfmreqhndlrCallACPI(param_2,&local_38);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (0x56,"supported subfunction","src/kernel/platform/platform_request_handler_ctrl.c",
                 0x5ee);
      return 0x56;
    }
    if ((local_2c & 0x10000000) == 0) {
      return 0;
    }
  }
  uVar2 = pfmreqhndlrPcontrol_IMPL(param_1,0,1);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertFailedNoLog("Pcontrol command","src/kernel/platform/platform_request_handler_ctrl.c",0x5fd
                     );
  return uVar2 & 0xffffffff;
}


// ===== 00488de0 _handleCmdSystemPfmreqhndlrDataInitUsingSbiosAndAck =====

undefined8 _handleCmdSystemPfmreqhndlrDataInitUsingSbiosAndAck(long param_1,short param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_2 != 0) {
    return 0x24;
  }
  lVar2 = pfmreqhndlrGetGpu();
  if (((((lVar2 != 0) && (cVar1 = gpuIsGpuFullPower_IMPL(lVar2), cVar1 != '\0')) &&
       (*(char *)(lVar2 + 0x44c) != '\0')) &&
      ((*(char *)(lVar2 + 0x44f) == '\0' && (*(char *)(lVar2 + 0x450) == '\0')))) &&
     ((*(char *)(lVar2 + 0x451) == '\0' &&
      ((*(char *)(lVar2 + 0x455) == '\0' &&
       (cVar1 = gpuCheckSysmemAccess_IMPL(lVar2), cVar1 != '\0')))))) {
    if (*(char *)(param_1 + 0x48) == '\0') {
      return 0x56;
    }
    uVar3 = pfmreqhndlrHandleStatusChangeEvent(param_1,lVar2);
    return uVar3;
  }
  nvAssertFailedNoLog("FULL_GPU_SANITY_CHECK(pGpu)",
                      "src/kernel/platform/platform_request_handler_ctrl.c",0x768);
  return 0x40;
}


// ===== 00488ea0 pfmreqhndlrHandleUserConfigurableTgpMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void pfmreqhndlrHandleUserConfigurableTgpMode_IMPL(long param_1,long param_2,undefined1 param_3)

{
  int iVar1;
  undefined1 local_19;
  
  local_19 = param_3;
  iVar1 = (**(code **)(param_2 + 0x3b90))
                    (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                     *(undefined4 *)(param_2 + 0x3b3c),0x20800ad2,&local_19,1);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x6cc) = param_3;
  }
  return;
}


// ===== 00488f00 pfmreqhndlrGetPerfSensorCounters =====

undefined8 pfmreqhndlrGetPerfSensorCounters(long param_1,ushort param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  undefined4 local_3c [3];
  
  lVar1 = *(long *)(g_pSys + 0x220);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("NULL != pPlatformRequestHandler",
                        "src/kernel/platform/platform_request_handler_ctrl.c",0x9f7);
  }
  else {
    uVar3 = 0;
    if (*(uint *)(param_1 + 4) < 4) {
      do {
        *(undefined4 *)(param_1 + 0x14 + uVar3 * 4) = 0;
        uVar4 = 1 << ((byte)uVar3 & 0x1f);
        if ((((*(uint *)(param_1 + 0xc) & uVar4) != 0) &&
            ((~*(ushort *)
                (PerfSensorBlockMap +
                ((ulong)*(uint *)(param_1 + 4) * 0x20 + (uVar3 & 0xffffffff)) * 2) & param_2) == 0))
           && (iVar2 = pfmreqhndlrGetPerfSensorCounterById_IMPL
                                 (lVar1,*(ushort *)
                                         (PerfSensorBlockMap +
                                         ((ulong)*(uint *)(param_1 + 4) * 0x20 +
                                         (uVar3 & 0xffffffff)) * 2) & 0xfff,local_3c), iVar2 == 0))
        {
          *(undefined4 *)(param_1 + 0x14 + uVar3 * 4) = local_3c[0];
          *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | uVar4;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0x20);
      return 0;
    }
  }
  return 0x56;
}


// ===== 00489040 cliresCtrlCmdSystemGpsCtrl_IMPL =====

undefined8 cliresCtrlCmdSystemGpsCtrl_IMPL(void)

{
  return 0;
}


// ===== 00489050 cliresCtrlCmdSystemGpsGetFrmData_IMPL =====

undefined8 cliresCtrlCmdSystemGpsGetFrmData_IMPL(void)

{
  return 0;
}


// ===== 00489060 cliresCtrlCmdSystemGpsSetFrmData_IMPL =====

undefined8 cliresCtrlCmdSystemGpsSetFrmData_IMPL(void)

{
  return 0;
}


// ===== 00489070 cliresCtrlCmdSystemGpsCallAcpi_IMPL =====

undefined8 cliresCtrlCmdSystemGpsCallAcpi_IMPL(void)

{
  return 0;
}


// ===== 00489080 RmInitScalability =====

/* WARNING: Type propagation algorithm not settling */

void RmInitScalability(long param_1)

{
  long lVar1;
  byte bVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint *extraout_RDX;
  uint *extraout_RDX_00;
  uint *extraout_RDX_01;
  uint *extraout_RDX_02;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined1 local_4d;
  int local_4c;
  uint local_48;
  undefined1 local_44 [4];
  uint local_40;
  uint local_3c [5];
  
  local_4c = 0;
  if (*(char *)(param_1 + 0x909) == '\0') {
    if (*(char *)(param_1 + 0x908) == '\0') {
LAB_00489150:
      uVar10 = 0;
      if (*(char *)(param_1 + 0x45a) == '\0') goto LAB_004890e2;
    }
LAB_0048915c:
    uVar10 = 0x40;
  }
  else {
    cVar4 = rmGpuLockIsOwner();
    if ((cVar4 == '\0') &&
       (iVar11 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),3,0,0x8002,&local_4c),
       iVar11 != 0)) {
      nvAssertFailedNoLog("rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_ALL, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &gpuLockMask) == NV_OK"
                          ,"src/kernel/platform/sli/sli.c",0x11d);
      return;
    }
    if (*(char *)(param_1 + 0x908) == '\0') {
      if (*(char *)(param_1 + 0x909) == '\0') goto LAB_00489150;
    }
    else if (*(char *)(param_1 + 0x909) == '\0') goto LAB_0048915c;
    uVar10 = 0x40;
LAB_004890e2:
    lVar3 = g_pSys;
    gpumgrGetGpuAttachInfo(&local_48,local_44);
    if (1 < local_48) {
      lVar1 = *(long *)(param_1 + 0x1ce8);
      puVar9 = extraout_RDX;
      if (*(char *)(lVar3 + 0x6a) == '\0') {
        if (lVar1 != 0) {
          if (*(char *)(param_1 + 0x4cc) == '\x01') {
            if (*(char *)(lVar3 + 0x6b) == '\0') goto LAB_00489131;
LAB_004891dd:
            if (*(char *)(lVar1 + 0x2f0) == '\0') goto LAB_0048915c;
          }
          else {
            cVar4 = knvlinkIsNvswitchProxyPresent_IMPL(param_1,lVar1);
            puVar9 = extraout_RDX_01;
            if ((cVar4 != '\0') && (*(char *)(lVar3 + 0x6b) != '\0')) goto LAB_004891dd;
          }
          if (local_48 < 9) {
            if (local_48 < 2) {
LAB_0048949e:
              if (uVar10 == 0) {
                *(undefined4 *)(param_1 + 0x1b3c) = 0;
              }
              else {
                uVar10 = 0x40;
              }
              goto LAB_00489168;
            }
            goto LAB_00489200;
          }
          goto LAB_00489168;
        }
      }
      else if (*(char *)(lVar3 + 0x6b) != '\0') {
        if (lVar1 != 0) goto LAB_004891dd;
        goto LAB_0048915c;
      }
LAB_00489131:
      if (local_48 < 9) {
LAB_00489200:
        uVar13 = 2;
LAB_00489210:
        local_4d = 0;
        local_3c[1] = 0;
        local_3c[2] = 0;
        local_3c[3] = 0;
        local_3c[4] = 0;
        gpumgrGetGpuAttachInfo(&local_40,local_3c,puVar9);
        puVar9 = extraout_RDX_00;
        if (uVar13 <= local_40) {
          uVar6 = *(uint *)(param_1 + 0x7a4);
          iVar11 = 0;
          local_3c[0] = ~(1 << ((byte)uVar6 & 0x1f)) & local_3c[0];
          uVar5 = local_3c[0];
          if (local_3c[0] != 0) {
            for (; iVar7 = iVar11, (uVar5 & 1) == 0; uVar5 = uVar5 >> 1) {
              iVar11 = iVar11 + 1;
            }
            do {
              uVar5 = uVar5 >> 1;
              while( true ) {
                if (uVar5 == 0) {
                  bVar2 = (byte)iVar11;
                  uVar5 = (1 << ((bVar2 - 1) + (char)uVar13 & 0x1f)) - 1U & -(1 << (bVar2 & 0x1f));
                  uVar12 = uVar5 << (((char)(iVar7 - uVar13) + '\x02') - bVar2 & 0x1f);
                  puVar9 = (uint *)(ulong)(iVar7 - uVar13);
                  uVar8 = local_3c[0] & uVar5;
                  if (uVar5 == (local_3c[0] & uVar5)) goto LAB_00489316;
                  goto LAB_004892c3;
                }
                iVar7 = iVar7 + 1;
                if ((uVar5 & 1) != 0) break;
                do {
                  uVar8 = uVar5;
                  uVar5 = uVar8 >> 1;
                  iVar7 = iVar7 + 1;
                } while ((uVar5 & 1) == 0);
                uVar5 = uVar8 >> 2;
              }
            } while( true );
          }
          nvAssertFailedNoLog("firstBit != (NvU32)~0","src/kernel/platform/sli/sli.c",0x6f);
          nvAssertFailedNoLog("lastBit != (NvU32)~0","src/kernel/platform/sli/sli.c",0x70);
          puVar9 = extraout_RDX_02;
        }
        goto LAB_00489490;
      }
      goto LAB_00489168;
    }
    uVar10 = uVar10 | 1;
  }
  *(uint *)(param_1 + 0x1b3c) = uVar10;
LAB_00489168:
  nvDbg_Printf("src/kernel/platform/sli/sli.c",0x105,"RmRunSLISupportCheck",1,
               "NVRM: gpuSliStatus 0x%x\n",uVar10);
  if (local_4c == 0) {
    return;
  }
  rmGpuGroupLockRelease(local_4c,0);
  return;
LAB_004892c3:
  if (uVar12 != uVar5) {
    uVar8 = -uVar5 & uVar5;
    uVar5 = uVar5 + uVar8;
    for (uVar6 = (-uVar5 & uVar5) - uVar8; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1) {
    }
    uVar5 = uVar5 | uVar6 >> 1;
    if (uVar5 == 0) {
      nvAssertFailedNoLog(&DAT_00d8d323,"src/kernel/platform/sli/sli.c",0x8f);
      uVar6 = *(uint *)(param_1 + 0x7a4);
      uVar8 = 0;
      goto LAB_00489316;
    }
    while( true ) {
      uVar6 = *(uint *)(param_1 + 0x7a4);
      puVar9 = (uint *)(ulong)uVar8;
      uVar8 = local_3c[0] & uVar5;
      if (uVar5 != (local_3c[0] & uVar5)) break;
LAB_00489316:
      while( true ) {
        uVar5 = uVar8;
        uVar6 = uVar5 | 1 << (uVar6 & 0x1f);
        cVar4 = gpumgrAreGpusInitialized(uVar6);
        puVar9 = (uint *)(ulong)uVar6;
        if (cVar4 == '\0') goto LAB_004892c3;
        puVar9 = local_3c + 4;
        gpumgrDetectSliLinkFromGpus
                  (1,uVar13,(uint *)(ulong)uVar6,local_3c + 1,local_3c + 2,&local_4d,local_3c + 3);
        if (uVar12 == uVar5) goto LAB_00489490;
        uVar8 = -uVar5 & uVar5;
        uVar5 = uVar5 + uVar8;
        for (uVar6 = (-uVar5 & uVar5) - uVar8; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1) {
        }
        uVar5 = uVar5 | uVar6 >> 1;
        if (uVar5 != 0) break;
        nvAssertFailedNoLog(&DAT_00d8d323,"src/kernel/platform/sli/sli.c",0xa2);
        uVar6 = *(uint *)(param_1 + 0x7a4);
        uVar8 = uVar5;
      }
    }
    goto LAB_004892c3;
  }
LAB_00489490:
  uVar13 = uVar13 + 1;
  if (local_48 < uVar13) goto LAB_0048949e;
  goto LAB_00489210;
}


// ===== 00489530 gpuboostmgrDestroyGroup_IMPL =====

int gpuboostmgrDestroyGroup_IMPL(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long local_40 [2];
  
  local_40[0] = 0;
  if (*(int *)(param_1 + 0x50) == 0) {
    nvAssertFailedNoLog("pBoostMgr->groupCount > 0","src/kernel/power/gpu_boost_mgr.c",0xc3);
    return 0x16;
  }
  if (param_2 < 0x10) {
    lVar3 = (ulong)param_2 * 0x8c;
    lVar2 = 0;
    if (*(int *)(param_1 + lVar3 + 0x54) == 0) {
      nvAssertFailedNoLog("0 != pBoostMgr->pBoostGroups[boostGroupId].gpuCount",
                          "src/kernel/power/gpu_boost_mgr.c",0xc5);
      return 0x16;
    }
    while ((iVar1 = btreeSearch(*(undefined4 *)(param_1 + lVar3 + 0x5c + lVar2 * 4),local_40,
                                *(undefined8 *)(param_1 + 0x48)), iVar1 == 0 && (local_40[0] != 0)))
    {
      lVar2 = lVar2 + 1;
      btreeUnlink(local_40[0],param_1 + 0x48);
      portMemFree(local_40[0]);
      if (*(uint *)(param_1 + 0x54 + lVar3) <= (uint)lVar2) {
        portMemSet(param_1 + 0x54 + lVar3,0,0x8c);
        *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
        return 0;
      }
    }
    nvAssertFailedNoLog("((NV_OK == status) && (NULL != pGpuIdNode))",
                        "src/kernel/power/gpu_boost_mgr.c",0xcd);
  }
  else {
    iVar1 = 0x5b;
    nvAssertFailedNoLog("NV0000_SYNC_GPU_BOOST_MAX_GROUPS > boostGroupId",
                        "src/kernel/power/gpu_boost_mgr.c",0xc4);
  }
  return iVar1;
}


// ===== 004896b0 gpuboostmgrQueryGroups_IMPL =====

undefined8 gpuboostmgrQueryGroups_IMPL(long param_1,undefined4 *param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  
  iVar1 = 0;
  param_1 = param_1 + 0x5c;
  uVar2 = 0;
  do {
    uVar3 = uVar2;
    if (*(int *)(param_1 + -8) != 0) {
      uVar3 = (ulong)((int)uVar2 + 1);
      param_2[uVar2 * 0x23 + 1] = *(int *)(param_1 + -8);
      param_2[uVar2 * 0x23 + 0x22] = iVar1;
      portMemCopy(param_2 + uVar2 * 0x23 + 2,0x80,param_1,0x80);
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 0x8c;
    uVar2 = uVar3;
  } while (iVar1 != 0x10);
  *param_2 = (int)uVar3;
  return 0;
}


// ===== 00489730 gpuboostmgrCheckConfig_IMPL =====

undefined4 gpuboostmgrCheckConfig_IMPL(long param_1,uint *param_2)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  undefined8 local_60;
  long local_58;
  long local_50;
  long local_48;
  long local_40 [2];
  
  local_60 = 0;
  if (param_2 == (uint *)0x0) {
    nvAssertFailedNoLog("NULL != pBoostConfig","src/kernel/power/gpu_boost_mgr.c",0x116);
    return 0x1f;
  }
  if (0x1f < *param_2 - 1) {
    nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x11c,"gpuboostmgrCheckConfig_IMPL",4,
                 "NVRM: Invalid Gpu Count 0x%x\n");
    return 0x5b;
  }
  lVar5 = gpumgrGetGpuFromId(param_2[1]);
  if (lVar5 != 0) {
    lVar6 = gpumgrGetGpuGrpFromGpu(lVar5);
    uVar10 = *param_2;
    if (1 < uVar10) {
      lVar12 = 1;
      do {
        lVar7 = gpumgrGetGpuFromId(param_2[lVar12 + 1]);
        if (lVar7 == 0) {
          uVar8 = 0x286;
          goto LAB_00489a55;
        }
        lVar7 = gpumgrGetGpuGrpFromGpu(lVar7);
        uVar10 = *param_2;
        if (lVar6 != lVar7) {
          lVar6 = 0;
          if (uVar10 == 0) {
            return 0;
          }
          goto LAB_004897dc;
        }
        lVar12 = lVar12 + 1;
      } while ((uint)lVar12 < uVar10);
    }
    goto LAB_004898b0;
  }
  nvAssertFailedNoLog("NULL != pGpu","src/kernel/power/gpu_boost_mgr.c",0x274);
LAB_00489a70:
  uVar9 = 0x57;
  goto LAB_0048986e;
LAB_00489c4d:
  uVar10 = *param_2;
  lVar5 = lVar5 + 1;
  if (uVar10 <= (uint)lVar5) goto LAB_004898b0;
  goto LAB_004899f5;
  while (lVar6 = lVar6 + 1, (uint)lVar6 < *param_2) {
LAB_004897dc:
    lVar12 = gpumgrGetGpuFromId(param_2[lVar6 + 1]);
    if (lVar12 == 0) {
      uVar8 = 0x29e;
      goto LAB_00489a55;
    }
    if (*(char *)(lVar12 + 0x480) == '\0') {
      local_58 = 0;
      local_50 = 0;
      if (*(char *)(lVar5 + 0x909) != '\0') {
        uVar3 = *(uint *)(lVar5 + 0x7f4);
        lVar6 = gpuGetGspStaticInfo(lVar5);
        if ((*(char *)(lVar5 + 0x909) != '\0') && (*(char *)(lVar6 + 0x5f0) != '\0')) {
          portMemCopy(&local_50,8,lVar6 + 0x129,5);
          portMemCopy(&local_58,8,lVar6 + 0x124,5);
          uVar10 = *param_2;
          if (uVar10 < 2) goto LAB_004898b0;
          lVar5 = 1;
          sVar1 = *(short *)(lVar6 + 0x5f4);
          sVar2 = *(short *)(lVar6 + 0x5f8);
          goto LAB_004899f5;
        }
      }
      nvAssertFailedNoLog("NV_FALSE","src/kernel/power/gpu_boost_mgr.c",0x2c7);
      uVar9 = 0x56;
      goto LAB_00489838;
    }
  }
  uVar10 = *param_2;
LAB_004898b0:
  if (uVar10 != 0) {
    uVar11 = 0;
    do {
      if (param_2[uVar11 + 1] == 0xffffffff) {
        nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",299,"gpuboostmgrCheckConfig_IMPL",4,
                     "NVRM: Invalid GPU ID 0x%x at index 0x%x\n",0xffffffff,uVar11);
        return 0x1f;
      }
      lVar5 = gpumgrGetGpuFromId();
      if (lVar5 == 0) {
        nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x141,"gpuboostmgrCheckConfig_IMPL",4,
                     "NVRM: OBJGPU not constructed yet for ID 0x%x at index 0x%x\n",
                     param_2[uVar11 + 1],uVar11);
        return 0x1f;
      }
      iVar4 = btreeSearch(param_2[uVar11 + 1],&local_60,*(undefined8 *)(param_1 + 0x48));
      if (iVar4 == 0) {
        nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x14c,"gpuboostmgrCheckConfig_IMPL",4,
                     "NVRM: GPU with ID 0x%x already in use in another group\n",
                     param_2[(uVar11 & 0xffffffff) + 1]);
        return 0x1f;
      }
      uVar11 = uVar11 + 1;
    } while ((uint)uVar11 < *param_2);
  }
  return 0;
LAB_004899f5:
  local_48 = 0;
  local_40[0] = 0;
  lVar6 = gpumgrGetGpuFromId(param_2[lVar5 + 1]);
  if (lVar6 == 0) {
    uVar8 = 0x2d9;
LAB_00489a55:
    nvAssertFailedNoLog("NULL != pGpuItr","src/kernel/power/gpu_boost_mgr.c",uVar8);
    goto LAB_00489a70;
  }
  if (((*(char *)(lVar6 + 0x909) == '\0') ||
      (lVar12 = gpuGetGspStaticInfo(lVar6), *(char *)(lVar6 + 0x909) == '\0')) ||
     (*(char *)(lVar12 + 0x5f0) == '\0')) {
    nvAssertFailedNoLog("NV_FALSE","src/kernel/power/gpu_boost_mgr.c",0x2e6);
    uVar9 = 0x57;
  }
  else {
    portMemCopy(local_40,8,lVar12 + 0x129,5);
    portMemCopy(&local_48,8,lVar12 + 0x124,5);
    if (((uVar3 >> 0x10 == (uint)*(ushort *)(lVar6 + 0x7f6)) && (local_50 == local_40[0])) &&
       ((local_58 == local_48 &&
        ((sVar1 == *(short *)(lVar12 + 0x5f4) && (sVar2 == *(short *)(lVar12 + 0x5f8)))))))
    goto LAB_00489c4d;
    uVar9 = 0x54;
  }
LAB_00489838:
  nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x307,"_gpuboostmgrApplyPolicyFilters",4,
               "NVRM: GPUs not compatible to be put in the same group\n");
LAB_0048986e:
  nvAssertFailedNoLog("NV_OK == status","src/kernel/power/gpu_boost_mgr.c",0x123);
  return uVar9;
}


// ===== 00489c80 gpuboostmgrCreateGroup_IMPL =====

int gpuboostmgrCreateGroup_IMPL(long param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  long lVar5;
  long local_40 [2];
  ulong uVar4;
  
  local_40[0] = 0;
  if (0xf < *(uint *)(param_1 + 0x50)) {
    nvAssertFailedNoLog("pBoostMgr->groupCount < NV0000_SYNC_GPU_BOOST_MAX_GROUPS",
                        "src/kernel/power/gpu_boost_mgr.c",0x4c);
    return 0x1a;
  }
  iVar1 = gpuboostmgrCheckConfig_IMPL();
  piVar2 = (int *)(param_1 + 0x54);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x53,"gpuboostmgrCreateGroup_IMPL",4,
                 "NVRM: Invalid Boost Config. Failing Boost Group creation.\n");
    nvAssertFailedNoLog("NV_OK == status","src/kernel/power/gpu_boost_mgr.c",0x55);
    return iVar1;
  }
  uVar4 = 0;
  while (*piVar2 != 0) {
    uVar3 = (uint)uVar4 + 1;
    uVar4 = (ulong)uVar3;
    piVar2 = piVar2 + 0x23;
    if (uVar3 == 0x10) {
      nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x8d,"gpuboostmgrCreateGroup_IMPL",4,
                   "NVRM: Inconsistency in pBoostGroups state.\n");
      nvAssertFailedNoLog(&DAT_00d8d6e9,"src/kernel/power/gpu_boost_mgr.c",0x8f);
      return 0x40;
    }
  }
  if (*param_2 != 0) {
    lVar5 = 0;
    do {
      local_40[0] = portMemAllocNonPaged(0x38);
      if (local_40[0] == 0) {
        iVar1 = 0;
        nvAssertFailedNoLog("(pGpuIdNode != NULL)","src/kernel/power/gpu_boost_mgr.c",0x6d);
LAB_00489e0b:
        if (*param_2 != 0) {
          lVar5 = 0;
          do {
            btreeSearch(param_2[lVar5 + 1],local_40,*(undefined8 *)(param_1 + 0x48));
            if (local_40[0] != 0) {
              btreeUnlink(local_40[0],param_1 + 0x48);
              portMemFree(local_40[0]);
            }
            lVar5 = lVar5 + 1;
          } while ((uint)lVar5 < *param_2);
        }
        portMemSet(param_1 + 0x54 + uVar4 * 0x8c,0,0x8c);
        return iVar1;
      }
      portMemSet(local_40[0],0,0x38);
      *(ulong *)(local_40[0] + 8) = (ulong)param_2[lVar5 + 1];
      *(ulong *)(local_40[0] + 0x10) = (ulong)param_2[lVar5 + 1];
      iVar1 = btreeInsert();
      if (iVar1 != 0) {
        nvAssertFailedNoLog("NV_OK == status","src/kernel/power/gpu_boost_mgr.c",0x78);
        goto LAB_00489e0b;
      }
      *(uint *)(param_1 + uVar4 * 0x8c + 0x5c + lVar5 * 4) = param_2[lVar5 + 1];
      lVar5 = lVar5 + 1;
    } while ((uint)lVar5 < *param_2);
  }
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  *(uint *)(param_1 + 0x54 + uVar4 * 0x8c) = *param_2;
  *(char *)(param_1 + 0xdc + uVar4 * 0x8c) = (char)param_2[0x22];
  param_2[0x21] = (uint)uVar4;
  return 0;
}


// ===== 00489f90 gpuboostmgrConstruct_IMPL =====

undefined8 gpuboostmgrConstruct_IMPL(void)

{
  return 0;
}


// ===== 00489fa0 gpuboostmgrDestruct_IMPL =====

void gpuboostmgrDestruct_IMPL(long param_1)

{
  btreeDestroyNodes(*(undefined8 *)(param_1 + 0x48));
  portMemSet(param_1 + 0x54,0,0x8c0);
  *(undefined4 *)(param_1 + 0x50) = 0;
  return;
}


// ===== 00489fe0 gpuboostmgrIncrementRefCount_IMPL =====

ulong gpuboostmgrIncrementRefCount_IMPL(long param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  ulong uVar4;
  
  if ((uint)param_2 < 0x10) {
    lVar3 = (param_2 & 0xffffffff) * 0x8c + param_1;
    if (*(int *)(lVar3 + 0x54) != 0) {
      if (*(int *)(lVar3 + 0x58) == -1) {
        nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x1a0,"gpuboostmgrIncrementRefCount_IMPL",4,
                     "NVRM: Max limit reached for ref count on group 0x%x\n",param_2 & 0xffffffff);
        nvAssertFailedNoLog(&DAT_00d8d6e9,"src/kernel/power/gpu_boost_mgr.c",0x1a3);
        uVar4 = 0x1a;
      }
      else {
        iVar1 = *(int *)(lVar3 + 0x58) + 1;
        uVar4 = 0;
        *(int *)(lVar3 + 0x58) = iVar1;
        if (iVar1 == 1) {
          uVar2 = kperfGpuBoostSyncStateUpdate(param_1,param_2,1);
          uVar4 = uVar2 & 0xffffffff;
          if ((int)uVar2 != 0) {
            nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x1b1,
                         "gpuboostmgrIncrementRefCount_IMPL",4,
                         "NVRM: Could not activate Sync GPU Boost on group 0x%x. Status: 0x%08x\n",
                         param_2 & 0xffffffff,uVar2);
            *(int *)(lVar3 + 0x58) = *(int *)(lVar3 + 0x58) + -1;
            nvAssertFailedNoLog(&DAT_00d8d6e9,"src/kernel/power/gpu_boost_mgr.c",0x1b5);
            uVar4 = uVar2 & 0xffffffff;
          }
        }
      }
      return uVar4;
    }
  }
  nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x19a,"gpuboostmgrIncrementRefCount_IMPL",4,
               "NVRM: Invalid group ID 0x%x\n",param_2 & 0xffffffff);
  nvAssertFailedNoLog(&DAT_00d8d6e9,"src/kernel/power/gpu_boost_mgr.c",0x19b);
  return 0x2c;
}


// ===== 0048a150 gpuboostmgrDecrementRefCount_IMPL =====

ulong gpuboostmgrDecrementRefCount_IMPL(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  
  if ((uint)param_2 < 0x10) {
    lVar1 = (param_2 & 0xffffffff) * 0x8c + param_1;
    if (*(int *)(lVar1 + 0x54) != 0) {
      if (*(int *)(lVar1 + 0x58) == 0) {
        nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x1d7,"gpuboostmgrDecrementRefCount_IMPL",4,
                     "NVRM: Ref count on group 0x%x is already 0\n",param_2 & 0xffffffff);
        nvAssertFailedNoLog(&DAT_00d8d6e9,"src/kernel/power/gpu_boost_mgr.c",0x1d9);
        uVar4 = 0x3f;
      }
      else {
        iVar3 = *(int *)(lVar1 + 0x58) + -1;
        uVar4 = 0;
        *(int *)(lVar1 + 0x58) = iVar3;
        if (iVar3 == 0) {
          uVar2 = kperfGpuBoostSyncStateUpdate(param_1,param_2,0);
          uVar4 = uVar2 & 0xffffffff;
          if ((int)uVar2 != 0) {
            nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x1e7,
                         "gpuboostmgrDecrementRefCount_IMPL",4,
                         "NVRM: Could not deactivate Sync GPU Boost on group 0x%x. Status: 0x%08x\n"
                         ,param_2 & 0xffffffff,uVar2);
            nvAssertFailedNoLog(&DAT_00d8d6e9,"src/kernel/power/gpu_boost_mgr.c",0x1ea);
            uVar4 = uVar2 & 0xffffffff;
          }
        }
      }
      return uVar4;
    }
  }
  nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x1d1,"gpuboostmgrDecrementRefCount_IMPL",4,
               "NVRM: Invalid group ID 0x%x\n",param_2 & 0xffffffff);
  nvAssertFailedNoLog(&DAT_00d8d6e9,"src/kernel/power/gpu_boost_mgr.c",0x1d2);
  return 0x2c;
}


// ===== 0048a2a0 gpuboostmgrGpuItr_IMPL =====

undefined8 gpuboostmgrGpuItr_IMPL(long param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("NULL != pIndex","src/kernel/power/gpu_boost_mgr.c",0x209);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x54 + (ulong)param_2 * 0x8c);
    if (uVar1 == 0) {
      nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x20d,"gpuboostmgrGpuItr_IMPL",4,
                   "NVRM: Gpu Count is 0 for group ID: 0x%x\n",param_2);
    }
    else {
      uVar2 = *param_3;
      if (uVar1 != uVar2) {
        *param_3 = uVar2 + 1;
        uVar3 = gpumgrGetGpuFromId(*(undefined4 *)
                                    (param_1 + 0xc +
                                    ((ulong)uVar2 + 0x14 + (ulong)param_2 * 0x23) * 4));
        return uVar3;
      }
    }
  }
  return 0;
}


// ===== 0048a340 gpuboostmgrGetBoostGrpIdFromGpu_IMPL =====

undefined8 gpuboostmgrGetBoostGrpIdFromGpu_IMPL(long param_1,long param_2,uint *param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  uint local_3c;
  
  *param_3 = 0xffffffff;
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pGpu","src/kernel/power/gpu_boost_mgr.c",0x234);
    return 0x1f;
  }
  uVar4 = 0;
  local_3c = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
LAB_0048a38a:
    do {
      while (iVar1 = *(int *)((ulong)local_3c * 0x8c + param_1 + 0x54), iVar1 != 0) {
        iVar3 = (int)uVar4;
        if (iVar1 == iVar3) {
LAB_0048a3de:
          local_3c = local_3c + 1;
          if (local_3c < *(uint *)(param_1 + 0x50)) goto LAB_0048a38a;
          goto LAB_0048a3f3;
        }
        lVar2 = gpumgrGetGpuFromId(*(undefined4 *)
                                    (param_1 + 0xc + (uVar4 + 0x14 + (ulong)local_3c * 0x23) * 4));
        if (lVar2 == 0) {
          uVar4 = (ulong)(iVar3 + 1);
          goto LAB_0048a3de;
        }
        if (*(int *)(lVar2 + 0x7ac) == *(int *)(param_2 + 0x7ac)) {
          *param_3 = local_3c;
          return 0;
        }
        uVar4 = (ulong)(iVar3 + 1);
      }
      nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x20d,"gpuboostmgrGpuItr_IMPL",4,
                   "NVRM: Gpu Count is 0 for group ID: 0x%x\n",local_3c);
      local_3c = local_3c + 1;
    } while (local_3c < *(uint *)(param_1 + 0x50));
  }
LAB_0048a3f3:
  nvDbg_Printf("src/kernel/power/gpu_boost_mgr.c",0x243,"gpuboostmgrGetBoostGrpIdFromGpu_IMPL",1,
               "NVRM: No Boost Group found for the gpu with ID: 0x%08x\n",
               *(undefined4 *)(param_2 + 0x7ac));
  return 0x57;
}


// ===== 0048a4d0 gpuboostmgrIsBoostGrpActive_IMPL =====

undefined4 gpuboostmgrIsBoostGrpActive_IMPL(long param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 != 0xffffffff) &&
     (param_1 = param_1 + (ulong)param_2 * 0x8c, *(int *)(param_1 + 0x54) != 0)) {
    iVar1 = *(int *)(param_1 + 0x58);
    return CONCAT31((int3)((uint)iVar1 >> 8),iVar1 != 0);
  }
  return 0;
}


// ===== 0048a500 syncgpuboostConstruct_IMPL =====

ulong syncgpuboostConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  undefined4 *puVar1;
  ulong uVar2;
  
  puVar1 = *(undefined4 **)(param_3 + 0x40);
  if (puVar1 != (undefined4 *)0x0) {
    uVar2 = gpuboostmgrIncrementRefCount_IMPL(*(undefined8 *)(g_pSys + 0x248),*puVar1);
    if ((int)uVar2 == 0) {
      *(undefined4 *)(param_1 + 0xd8) = *puVar1;
    }
    else {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "gpuboostmgrIncrementRefCount(pBoostMgr, p0060Params->gpuBoostGroupId)",
                 "src/kernel/power/gpu_boost_mgr.c",0x31d);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertFailedNoLog("NULL != p0060Params","src/kernel/power/gpu_boost_mgr.c",0x31c);
  return 0x1f;
}


// ===== 0048a5a0 syncgpuboostDestruct_IMPL =====

void syncgpuboostDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  long local_20;
  
  uVar3 = 0;
  local_20 = 0;
  uVar1 = *(undefined8 *)(g_pSys + 0x248);
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0xb8);
  }
  resGetFreeParams_IMPL(uVar3,0,&local_20);
  iVar2 = gpuboostmgrDecrementRefCount_IMPL(uVar1,*(undefined4 *)(param_1 + 0xd8));
  if (iVar2 == 0) {
    *(undefined4 *)(local_20 + 0x30) = 0;
    return;
  }
  nvAssertFailedNoLog("NV_OK == rmStatus","src/kernel/power/gpu_boost_mgr.c",0x333);
  *(int *)(local_20 + 0x30) = iVar2;
  return;
}


// ===== 0048a640 serverResLock_Prologue.part.0 =====

int serverResLock_Prologue_part_0(long param_1,uint *param_2,uint param_3)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  uint local_54;
  undefined4 local_3c [3];
  
  uVar8 = *(uint *)(param_1 + 0x28);
  if ((uVar8 & 4) == 0) {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 == '\0') {
      iVar4 = rmGpuLocksGetOwnedMask();
      if (iVar4 == 0) {
        iVar4 = rmGpuLocksAcquire(0,0x200);
        if (iVar4 != 0) {
          return iVar4;
        }
        *param_2 = *param_2 | 4;
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 2;
        goto LAB_0048a709;
      }
      nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x173);
    }
    else {
      if ((*(byte *)(param_1 + 0x2c) & 0x40) != 0) {
LAB_0048a709:
        uVar8 = *(uint *)(param_1 + 0x28);
        goto LAB_0048a66d;
      }
      nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x168);
    }
LAB_0048a768:
    iVar4 = 0x2f;
  }
  else {
LAB_0048a66d:
    if ((uVar8 & 8) == 0) {
      return 0;
    }
    local_3c[0] = 0;
    if (*(long *)(param_1 + 0x10) == 0) {
      nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x189);
    }
    else {
      lVar5 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_1 + 0x10) + 8),
                                 __nvoc_class_def_GpuResource);
      if ((lVar5 != 0) ||
         (((lVar5 = resservGetTlsCallContext(), lVar5 != 0 && (*(long *)(lVar5 + 0x10) != 0)) &&
          (lVar5 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(lVar5 + 0x10) + 8),
                                      __nvoc_class_def_GpuResource), lVar5 != 0)))) {
        lVar5 = *(long *)(*(long *)(lVar5 + 0xd0) + 0xe0);
        uVar1 = *(undefined4 *)(lVar5 + 0x7a4);
        if ((*(uint *)(param_1 + 0x2c) & 4) == 0) {
          cVar2 = rmGpuGroupLockIsOwner(uVar1,1,local_3c);
          if (cVar2 == '\0') {
            local_54 = gpumgrGetGpuMask(lVar5);
            local_54 = param_3 | local_54;
            lVar5 = *(long *)(param_1 + 0x18);
            if (lVar5 != 0) {
              lVar6 = listHead_IMPL(lVar5 + 0x1a0);
              if (lVar6 != 0) {
                uVar8 = 0;
                do {
                  lVar7 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(lVar6 + 0x10) + 8),
                                             __nvoc_class_def_GpuResource);
                  if (lVar7 != 0) {
                    uVar3 = gpumgrGetGpuMask(*(undefined8 *)(*(long *)(lVar7 + 0xd0) + 0xe0));
                    uVar8 = uVar8 | uVar3;
                  }
                  lVar6 = listNext_IMPL(lVar5 + 0x1a0,lVar6);
                } while (lVar6 != 0);
                local_54 = local_54 | uVar8;
              }
            }
            *(uint *)(param_1 + 0x30) = local_54;
            iVar4 = rmGpuGroupLockAcquire(0,2,0,0x200,param_1 + 0x30);
            if (iVar4 != 0) {
              return iVar4;
            }
            *param_2 = *param_2 | 8;
            *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 4;
            return 0;
          }
          if ((*(byte *)(param_1 + 0x2c) & 0x40) != 0) {
            return 0;
          }
          nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x1be);
        }
        else {
          cVar2 = rmGpuGroupLockIsOwner(uVar1,1,local_3c);
          if (cVar2 != '\0') {
            return 0;
          }
          nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x1b4);
        }
        goto LAB_0048a768;
      }
      nvAssertFailedNoLog("Attempting to lock per-GPU lock for a non-GpuResource",
                          "src/kernel/rmapi/alloc_free.c",0x1a4);
    }
    iVar4 = 0x36;
  }
  return iVar4;
}


// ===== 0048a970 serverAllocClientHandleBase =====

undefined4 serverAllocClientHandleBase(long param_1,char param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xac);
  if (param_2 != '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0xa8);
  }
  return uVar1;
}


// ===== 0048a990 serverAllocApiCopyIn =====

int serverAllocApiCopyIn(long param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  bool bVar7;
  
  uVar2 = *(undefined8 *)(param_2 + 0x40);
  iVar1 = *(int *)(*(long *)(param_2 + 0x38) + 4);
  puVar5 = (undefined8 *)_portMemAllocatorAlloc(g_resServ._24_8_,0x28);
  iVar4 = 0x1a;
  if (puVar5 == (undefined8 *)0x0) goto LAB_0048aa47;
  portMemSet(puVar5,0,0x28);
  *(undefined8 *)(param_2 + 0x40) = 0;
  puVar5[4] = "serverAllocApiCopyIn";
  puVar5[1] = param_2 + 0x40;
  *puVar5 = uVar2;
  puVar5[2] = 0;
  *(undefined1 *)(puVar5 + 3) = 1;
  iVar3 = rmapiParamsCopyInit(puVar5,*(undefined4 *)(param_2 + 0xc));
  iVar4 = iVar3;
  if ((iVar3 == 0) &&
     ((bVar7 = iVar1 == 0, *(int *)(puVar5 + 2) == 0 ||
      (iVar4 = rmapiParamsAcquire(puVar5,bVar7), iVar4 == 0)))) {
    if (*(char *)(param_1 + 0x43) == '\0') {
      *(undefined8 *)(param_2 + 0x60) = 0;
      iVar4 = iVar3;
      goto LAB_0048aa47;
    }
    iVar4 = iVar3;
    if (*(long *)(param_2 + 0x60) == 0) goto LAB_0048aa47;
    lVar6 = _portMemAllocatorAlloc(g_resServ._24_8_,4);
    if (lVar6 == 0) {
      iVar4 = 0x1a;
    }
    else {
      iVar4 = rmapiParamsCopyIn("RightsRequested",lVar6,*(undefined8 *)(param_2 + 0x60),4,bVar7);
      portMemCopy(param_2 + 0x68,4,lVar6,4);
      _portMemAllocatorFree(g_resServ._24_8_,lVar6);
      if (iVar4 == 0) {
        *(long *)(param_2 + 0x60) = param_2 + 0x68;
        goto LAB_0048aa47;
      }
    }
  }
  _portMemAllocatorFree(g_resServ._24_8_,puVar5);
  puVar5 = (undefined8 *)0x0;
LAB_0048aa47:
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = puVar5;
  }
  return iVar4;
}


// ===== 0048ab40 serverAllocApiCopyOut =====

int serverAllocApiCopyOut(undefined8 param_1,int param_2,long param_3)

{
  if (*(int *)(param_3 + 0x10) != 0) {
    if (param_2 == 0) {
      param_2 = rmapiParamsRelease(param_3);
    }
    else {
      *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) | 4;
      rmapiParamsRelease(param_3);
    }
  }
  _portMemAllocatorFree(g_resServ._24_8_,param_3);
  return param_2;
}


// ===== 0048aba0 serverTopLock_Prologue =====

int serverTopLock_Prologue(undefined8 param_1,int param_2,long param_3,uint *param_4)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_3 + 0x28);
  if (((uVar1 & 0x10) != 0) && ((*(byte *)(param_3 + 0x2c) & 8) == 0)) {
    iVar4 = osAcquireRmSema(*(undefined8 *)(g_pSys + 0x160));
    if (iVar4 != 0) {
      return iVar4;
    }
    *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) | 8;
    *param_4 = *param_4 | 0x10;
    uVar1 = *(uint *)(param_3 + 0x28);
  }
  if ((uVar1 & 1) == 0) {
    iVar4 = 0;
    if ((*(byte *)(param_3 + 0x2c) & 1) == 0) {
      bVar2 = (param_2 == 0) * '\x02';
      if ((uVar1 & 0x80) != 0) {
        bVar2 = bVar2 | 4;
      }
      iVar4 = rmapiLockAcquire(bVar2,0x200);
      if (iVar4 == 0) {
        *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) | 1;
        *param_4 = *param_4 | 1;
        return 0;
      }
    }
    else {
      cVar3 = rmapiLockIsOwner();
      if (cVar3 == '\0') {
        nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x107);
        iVar4 = 0x2f;
      }
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}


// ===== 0048acb0 serverTopLock_Epilogue =====

void serverTopLock_Epilogue(undefined8 param_1,undefined8 param_2,long param_3,uint *param_4)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = g_pSys;
  uVar2 = *param_4;
  if ((uVar2 & 1) != 0) {
    rmapiLockRelease();
    *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) & 0xfffffffe;
    uVar2 = *param_4 & 0xfffffffe;
    *param_4 = uVar2;
  }
  if ((uVar2 & 0x10) == 0) {
    return;
  }
  osReleaseRmSema(*(undefined8 *)(lVar1 + 0x160),0);
  *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) & 0xfffffff7;
  *param_4 = *param_4 & 0xffffffef;
  return;
}


// ===== 0048ad30 serverResLock_Prologue =====

undefined8
serverResLock_Prologue
          (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  char cVar1;
  undefined8 uVar2;
  
  if ((*(byte *)(param_3 + 0x2c) & 2) == 0) {
    uVar2 = serverResLock_Prologue_part_0(param_3,param_4,param_5);
    return uVar2;
  }
  cVar1 = rmGpuLockIsOwner();
  if (cVar1 != '\0') {
    return 0;
  }
  nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x15c);
  return 0x2f;
}


// ===== 0048ad90 serverAllocEpilogue_WAR =====

int serverAllocEpilogue_WAR(undefined8 param_1,int param_2,char param_3,undefined4 *param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long local_20 [2];
  
  if ((param_3 != '\0') || (param_2 != 0x19)) {
    return param_2;
  }
  cVar2 = rmGpuLockIsOwner();
  if (cVar2 == '\0') {
    iVar3 = rmGpuLocksAcquire(0,0x200);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = clientGetResourceRef_IMPL(*(undefined8 *)(param_4 + 8),param_4[2],local_20);
    if (iVar3 == 0) {
      lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_20[0] + 8),__nvoc_class_def_DispChannel);
      bVar1 = true;
      if (lVar4 != 0) goto LAB_0048ae07;
    }
    iVar3 = 0x19;
  }
  else {
    iVar3 = clientGetResourceRef_IMPL(*(undefined8 *)(param_4 + 8),param_4[2],local_20);
    if (iVar3 != 0) {
      return 0x19;
    }
    lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_20[0] + 8),__nvoc_class_def_DispChannel);
    bVar1 = false;
    if (lVar4 == 0) {
      return 0x19;
    }
LAB_0048ae07:
    iVar3 = dispchnGrabChannel_IMPL
                      (lVar4,*param_4,param_4[1],param_4[2],param_4[3],
                       *(undefined8 *)(param_4 + 0x10));
    if (!bVar1) {
      return iVar3;
    }
  }
  rmGpuLocksRelease(0,0);
  return iVar3;
}


// ===== 0048aea0 serverAllocResourceUnderLock =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int serverAllocResourceUnderLock(long param_1,int *param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  uint uVar16;
  uint local_d8;
  undefined1 local_d4 [4];
  long local_d0;
  long local_c8;
  long local_c0;
  long local_b8;
  undefined8 local_b0;
  long local_a8;
  long *local_a0;
  long local_98 [13];
  
  iVar11 = *param_2;
  local_c8 = 0;
  plVar1 = *(long **)(param_2 + 8);
  local_d8 = 0;
  lVar2 = *(long *)(param_2 + 6);
  local_c0 = 0;
  if (*(char *)(param_1 + 0x14) == '\0') {
    return 0x55;
  }
  if (*(long *)(param_2 + 0xe) == 0) {
    return 0x1f;
  }
  local_d0 = RsResInfoByExternalClassId(param_2[3]);
  if (local_d0 == 0) {
    return 0x22;
  }
  iVar7 = rmapiFixupAllocParams(&local_d0,param_2);
  lVar4 = local_d0;
  if (iVar7 != 0) {
    nvAssertOkFailedNoLog
              (iVar7,"rmapiFixupAllocParams(&pResDesc, pRmAllocParams)",
               "src/kernel/rmapi/alloc_free.c",0x2d3);
    return iVar7;
  }
  uVar8 = (~*(uint *)(local_d0 + 0x24) & 1) << 2;
  *(uint *)(lVar2 + 0x28) = uVar8;
  *(uint *)(lVar2 + 0x28) = uVar8 | *(int *)(local_d0 + 0x24) * 2 & 8U;
  if ((*(byte *)(local_d0 + 0x25) & 7) == 0) {
    nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x27c,"_serverAllocValidatePrivilege",3,
                 "NVRM: external class 0x%08x is missing its privilege flag in RS_ENTRY\n",
                 param_2[3]);
    return 0x1b;
  }
  plVar3 = *(long **)(param_2 + 8);
  cVar6 = hypervisorIsVgxHyper_IMPL();
  if (cVar6 == '\0') {
    uVar8 = *(uint *)(lVar4 + 0x24);
    uVar16 = **(uint **)(param_2 + 0xe);
LAB_0048b059:
    if (((uVar8 & 0x200) != 0) && (uVar16 == 0)) {
      nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x298,"_serverAllocValidatePrivilege",2,
                   "NVRM: hClient: 0x%08x, externalClassId: 0x%08x: non-privileged context tried to allocate privileged object\n"
                   ,*param_2,param_2[3]);
      return 0x1b;
    }
    if (((uVar8 & 0x400) != 0) && (uVar16 < 2)) {
      nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x2a3,"_serverAllocValidatePrivilege",2,
                   "NVRM: hClient: 0x%08x, externalClassId: 0x%08x: non-privileged context tried to allocate kernel privileged object\n"
                   ,*param_2,param_2[3]);
      return 0x1b;
    }
  }
  else {
    uVar9 = (**(code **)(*plVar3 + 0x40))();
    cVar6 = (**(code **)(*plVar3 + 0x48))(plVar3,uVar9);
    uVar8 = *(uint *)(lVar4 + 0x24);
    uVar16 = **(uint **)(param_2 + 0xe);
    if (cVar6 == '\0') goto LAB_0048b059;
    if (uVar16 != 2) {
      if ((uVar8 & 0x100) != 0) goto LAB_0048b059;
      if (((uVar8 & 0x200) == 0) || (uVar16 == 0)) {
        nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x289,"_serverAllocValidatePrivilege",2,
                     "NVRM: hClient: 0x%08x, externalClassId: 0x%08x: CPU hypervisor does not have permission to allocate object\n"
                     ,*param_2,param_2[3]);
        return 0x1b;
      }
    }
  }
  *(undefined1 *)(lVar2 + 0x34) = 3;
  *(int *)(lVar2 + 0x38) = param_2[3];
  if (param_2[2] == iVar11) {
    if (**(int **)(local_d0 + 0x18) != 0) {
      return 0x36;
    }
    if (*(char *)(local_d0 + 0x15) != '\0') {
      nvAssertFailedNoLog("!pResDesc->bMultiInstance","src/kernel/rmapi/alloc_free.c",0x2e7);
    }
  }
  else {
    iVar7 = clientGetResourceRef_IMPL(plVar1,param_2[1],&local_c8);
    if (iVar7 != 0) {
      return iVar7;
    }
    *(long *)(lVar2 + 0x10) = local_c8;
  }
  if (((*(byte *)(local_d0 + 0x24) & 0x80) != 0) && ((*(byte *)(param_2 + 0xd) & 0x80) == 0)) {
    return 0x22;
  }
  gpuGetByRef(local_c8,0,&local_c0);
  if (local_c0 == 0) {
LAB_0048b10f:
    bVar5 = false;
    uVar8 = *(uint *)(lVar2 + 0x2c);
  }
  else if ((*(char *)(local_c0 + 0x909) == '\0') && (*(char *)(local_c0 + 0x90a) == '\0')) {
    uVar8 = *(uint *)(lVar2 + 0x2c);
    bVar5 = false;
  }
  else {
    if (((*(byte *)(local_d0 + 0x24) & 0x40) == 0) || ((*(byte *)(lVar2 + 0x28) & 4) == 0))
    goto LAB_0048b10f;
    nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x311,"serverAllocResourceUnderLock",1,
                 "NVRM: Overriding flags for alloc of class %04x\n",param_2[3]);
    uVar8 = *(uint *)(lVar2 + 0x2c);
    *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) | 8;
    bVar5 = false;
    if ((uVar8 & 0x40) == 0) {
      uVar8 = uVar8 | 0x40;
      bVar5 = true;
      *(uint *)(lVar2 + 0x2c) = uVar8;
    }
  }
  if ((uVar8 & 2) == 0) {
    iVar7 = serverResLock_Prologue_part_0(lVar2,&local_d8,0);
    if (iVar7 == 0) goto LAB_0048b13d;
  }
  else {
    cVar6 = rmGpuLockIsOwner();
    if (cVar6 == '\0') {
      nvAssertFailedNoLog(&DAT_00d8da4a,"src/kernel/rmapi/alloc_free.c",0x15c);
      iVar7 = 0x2f;
      goto LAB_0048b504;
    }
LAB_0048b13d:
    if (local_c8 == 0) {
LAB_0048b1c0:
      iVar7 = clientAssignResourceHandle_IMPL(plVar1,param_2 + 2);
      if (iVar7 == 0) {
        iVar7 = param_2[1];
        if (iVar7 == 0) {
          iVar7 = *param_2;
        }
        param_2[1] = iVar7;
        if (*(char *)(param_1 + 0x43) != '\0') {
          rsAccessMaskFromArray
                    (local_d4,*(undefined8 *)(local_d0 + 0x28),*(undefined8 *)(local_d0 + 0x30));
          *(undefined1 **)(param_2 + 0x1c) = local_d4;
        }
        iVar7 = clientAllocResource_IMPL(plVar1,g_resServ,param_2);
        if (((iVar7 == 0) && ((*(byte *)(param_2 + 0xd) & 0x40) == 0)) &&
           (iVar7 = 0, (*(uint *)(local_d0 + 0x24) & 0x50) != 0)) {
          lVar4 = *(long *)(param_2 + 10);
          local_b8 = 0;
          lVar13 = __nvoc_dynamicCast(*(undefined8 *)(lVar4 + 8),__nvoc_class_def_RmResource);
          uVar12 = 0;
          do {
            uVar8 = (int)uVar12 + 0x20;
            uVar14 = (ulong)uVar8;
            *(undefined8 *)((long)&local_a8 + uVar12) = 0;
            *(undefined8 *)((long)&local_a0 + uVar12) = 0;
            *(undefined8 *)((long)local_98 + uVar12) = 0;
            *(undefined8 *)((long)local_98 + uVar12 + 8) = 0;
            uVar12 = uVar14;
          } while (uVar8 < 0x60);
          *(undefined8 *)((long)&local_a8 + uVar14) = 0;
          *(undefined8 *)((long)&local_a0 + uVar14) = 0;
          local_b0 = 0;
          iVar7 = gpuGetByRef(lVar4,0,&local_b8);
          if ((iVar7 == 0) && (lVar13 != 0)) {
            if (((*(char *)(local_b8 + 0x908) != '\0') &&
                ((*(uint *)(local_d0 + 0x24) & 0x50) != 0x40)) ||
               ((*(char *)(local_b8 + 0x909) != '\0' ||
                (iVar7 = 0, *(char *)(local_b8 + 0x90a) != '\0')))) {
              local_98[2] = *(long *)(param_2 + 6);
              plVar3 = *(long **)(param_2 + 0xe);
              local_98[3] = *plVar3;
              local_98[4] = plVar3[1];
              local_98[5] = plVar3[2];
              local_98[6] = plVar3[3];
              local_a8 = param_1;
              local_a0 = plVar1;
              local_98[0] = lVar4;
              iVar7 = resservSwapTlsCallContext(&local_b0,&local_a8);
              if (iVar7 != 0) {
                nvAssertOkFailedNoLog
                          (iVar7,"resservSwapTlsCallContext(&pOldContext, &callContext)",
                           "src/kernel/rmapi/alloc_free.c",0x39b);
                goto LAB_0048b440;
              }
              lVar15 = gpuGetRpc(local_b8);
              if (lVar15 == 0) {
                nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/alloc_free.c",0x39d);
                iVar11 = resservRestoreTlsCallContext(local_b0);
                if (iVar11 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar11,"resservRestoreTlsCallContext(pOldContext)",
                             "src/kernel/rmapi/alloc_free.c",0x3a5);
                }
              }
              else {
                if ((*(char *)(local_b8 + 0x909) == '\0') && (*(char *)(local_b8 + 0x90a) == '\0'))
                {
                  iVar7 = (**(code **)(lVar15 + 0x348))
                                    (local_b8,lVar15,*param_2,param_2[1],param_2[2],param_2[3],
                                     *(undefined8 *)(param_2 + 0x10),0);
                }
                else {
                  iVar7 = (**(code **)(local_b8 + 0x3b60))(local_b8 + 0x3b58,*param_2);
                }
                iVar10 = resservRestoreTlsCallContext(local_b0);
                if (iVar10 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar10,"resservRestoreTlsCallContext(pOldContext)",
                             "src/kernel/rmapi/alloc_free.c",0x3a5);
                }
                if (iVar7 != 0) goto LAB_0048b440;
              }
              iVar7 = 0;
              *(undefined1 *)(lVar13 + 0xa4) = 1;
            }
          }
          else {
            iVar7 = 0x22;
LAB_0048b440:
            portMemSet(&local_a8,0,0x40);
            local_a8 = CONCAT44(param_2[2],iVar11);
            local_98[5] = *(long *)(param_2 + 0xe);
            local_98[1] = *(long *)(param_2 + 6);
            local_98[3] = lVar4;
            iVar11 = (**(code **)(*plVar1 + 0x50))(plVar1,g_resServ,&local_a8);
            if (iVar11 != 0) {
              nvAssertFailedNoLog("tmpStatus == NV_OK","src/kernel/rmapi/alloc_free.c",0x3ba);
            }
            param_2[10] = 0;
            param_2[0xb] = 0;
          }
        }
      }
    }
    else if ((local_c0 == 0) || (iVar7 = 0x62, *(char *)(local_c0 + 0x4a8) == '\0')) {
      if (*(char *)(local_d0 + 0x15) == '\0') {
        iVar10 = refFindChildOfType(local_c8,*(uint *)(*(long *)(local_d0 + 8) + 4) & 0xffffff,1,0);
        iVar7 = 99;
        if (iVar10 == 0) goto LAB_0048b4ba;
      }
      if (*(char *)(local_d0 + 0x16) != '\0') goto LAB_0048b1c0;
      iVar7 = **(int **)(local_d0 + 0x18);
      if (iVar7 != 0) {
        uVar12 = 0;
        do {
          if (*(int *)(local_c8 + 0x118) == iVar7) goto LAB_0048b1c0;
          uVar12 = (ulong)((int)uVar12 + 1);
          iVar7 = (*(int **)(local_d0 + 0x18))[uVar12];
        } while (iVar7 != 0);
      }
      iVar7 = 0x36;
    }
  }
LAB_0048b4ba:
  uVar8 = local_d8;
  if ((local_d8 & 8) != 0) {
    rmGpuGroupLockRelease(*(undefined4 *)(lVar2 + 0x30),0);
    *(uint *)(lVar2 + 0x2c) = *(uint *)(lVar2 + 0x2c) & 0xfffffffb;
  }
  if ((uVar8 & 4) != 0) {
    rmGpuLocksRelease(0,0);
    *(uint *)(lVar2 + 0x2c) = *(uint *)(lVar2 + 0x2c) & 0xfffffffd;
  }
LAB_0048b504:
  if (bVar5) {
    *(uint *)(lVar2 + 0x2c) = *(uint *)(lVar2 + 0x2c) & 0xffffffbf;
    return iVar7;
  }
  return iVar7;
}


// ===== 0048b8e0 serverFreeResourceRpcUnderLock =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

int serverFreeResourceRpcUnderLock(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  long *plVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  undefined1 local_79;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  undefined8 local_30;
  
  plVar2 = *(long **)(param_2 + 0x28);
  local_78 = 0;
  if (plVar2 == (long *)0x0) {
    nvAssertFailedNoLog("pResourceRef != NULL","src/kernel/rmapi/alloc_free.c",0x3d4);
    return 0x33;
  }
  lVar6 = __nvoc_dynamicCast(plVar2[1],__nvoc_class_def_RmResource);
  iVar5 = gpuGetByRef(plVar2,&local_79,&local_78);
  if (iVar5 != 0) {
    return 0;
  }
  iVar5 = 0;
  if ((((*(char *)(local_78 + 0x908) != '\0') || (*(char *)(local_78 + 0x909) != '\0')) ||
      (*(char *)(local_78 + 0x90a) != '\0')) && ((lVar6 != 0 && (*(char *)(lVar6 + 0xa4) != '\0'))))
  {
    lVar6 = gpuGetRpc();
    if (lVar6 == 0) {
      iVar5 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/alloc_free.c",0x3e2);
    }
    else if ((*(char *)(local_78 + 0x909) == '\0') && (*(char *)(local_78 + 0x90a) == '\0')) {
      iVar5 = (**(code **)(lVar6 + 0xf0))
                        (local_78,lVar6,*(undefined4 *)(*plVar2 + 0x48),
                         *(undefined4 *)(plVar2[3] + 0x10),(int)plVar2[2],*(code **)(lVar6 + 0xf0));
    }
    else {
      iVar5 = (**(code **)(local_78 + 0x3b70))(local_78 + 0x3b58);
    }
    if ((*(char *)(local_78 + 0x908) != '\0') && (*(int *)((long)plVar2 + 0x11c) == 0x83de)) {
      clientRefIter(&local_d8,*plVar2,0,&DAT_00e0ac20,0,1);
      local_70 = local_d8;
      local_68 = local_d0;
      local_60 = local_c8;
      local_58 = local_c0;
      local_50 = local_b8;
      local_48 = local_b0;
      local_40 = local_a8;
      local_38 = local_a0;
      local_30 = local_98;
      do {
        cVar4 = clientRefIterNext(local_50,&local_70);
        bVar3 = false;
        if (cVar4 == '\0') goto LAB_0048bb40;
        lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_Device);
      } while ((lVar6 == 0) ||
              ((*(char *)(local_78 + 0x4a4e) != '\0' &&
               (local_78 != *(long *)(*(long *)(lVar6 + 0x128) + 0xe0)))));
      bVar3 = true;
LAB_0048bb40:
      clientRefIter(&local_d8,*plVar2,0,0x4adc81,0,1);
      local_70 = local_d8;
      local_68 = local_d0;
      local_60 = local_c8;
      local_58 = local_c0;
      local_50 = local_b8;
      local_48 = local_b0;
      local_40 = local_a8;
      local_38 = local_a0;
      local_30 = local_98;
      while (cVar4 = clientRefIterNext(local_50,&local_70), cVar4 != '\0') {
        lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),
                                   __nvoc_class_def_KernelSMDebuggerSession);
        lVar7 = __nvoc_dynamicCast(plVar2[1],__nvoc_class_def_KernelSMDebuggerSession);
        if ((lVar6 != 0) && (lVar7 != lVar6)) {
          if (*(char *)(local_78 + 0x4a4e) == '\0') {
            return iVar5;
          }
          if (local_78 == *(long *)(*(long *)(lVar6 + 0x158) + 0xe0)) {
            return iVar5;
          }
        }
      }
      if (!bVar3) {
        lVar6 = gpuGetRpc(local_78);
        if (lVar6 == 0) {
          iVar5 = 0x1a;
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/alloc_free.c",0x40d);
        }
        else if (iVar5 == 0) {
          uVar1 = *(undefined4 *)(*plVar2 + 0x48);
          if ((*(char *)(local_78 + 0x909) == '\0') && (*(char *)(local_78 + 0x90a) == '\0')) {
            iVar5 = (**(code **)(lVar6 + 0xf0))
                              (local_78,lVar6,uVar1,0,uVar1,*(code **)(lVar6 + 0xf0));
          }
          else {
            iVar5 = (**(code **)(local_78 + 0x3b70))(local_78 + 0x3b58,uVar1,uVar1);
          }
        }
      }
    }
  }
  return iVar5;
}


// ===== 0048bd20 serverResLock_Epilogue =====

void serverResLock_Epilogue(undefined8 param_1,undefined8 param_2,long param_3,uint *param_4)

{
  uint uVar1;
  
  uVar1 = *param_4;
  if ((uVar1 & 8) != 0) {
    rmGpuGroupLockRelease(*(undefined4 *)(param_3 + 0x30),0);
    *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) & 0xfffffffb;
    uVar1 = *param_4 & 0xfffffff7;
    *param_4 = uVar1;
  }
  if ((uVar1 & 4) == 0) {
    return;
  }
  rmGpuLocksRelease(0,0);
  *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) & 0xfffffffd;
  *param_4 = *param_4 & 0xfffffffb;
  return;
}


// ===== 0048bd90 serverInitFreeParams_Recursive =====

undefined8
serverInitFreeParams_Recursive
          (undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined4 *param_4)

{
  portMemSet(param_4,0,0x40);
  *param_4 = param_1;
  param_4[1] = param_2;
  *(undefined8 *)(param_4 + 6) = param_3;
  return 0;
}


// ===== 0048bdd0 serverUpdateLockFlagsForFree =====

undefined8 serverUpdateLockFlagsForFree(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long local_20;
  
  lVar1 = *(long *)(param_2 + 0x18);
  local_20 = 0;
  lVar5 = *(long *)(*(long *)(param_2 + 0x28) + 0x110);
  uVar3 = (*(byte *)(lVar5 + 0x24) >> 1 & 1 ^ 1) << 2;
  *(uint *)(lVar1 + 0x28) = uVar3;
  *(uint *)(lVar1 + 0x28) = uVar3 | *(uint *)(lVar5 + 0x24) & 8;
  uVar2 = *(undefined8 *)(*(long *)(param_2 + 0x28) + 0x18);
  *(undefined8 *)(lVar1 + 0x10) = uVar2;
  iVar4 = gpuGetByRef(uVar2,0,&local_20);
  if ((((iVar4 == 0) &&
       (lVar5 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_2 + 0x28) + 8),
                                   __nvoc_class_def_RmResource), local_20 != 0)) &&
      ((*(char *)(local_20 + 0x909) != '\0' || (*(char *)(local_20 + 0x90a) != '\0')))) &&
     (((lVar5 != 0 && (*(char *)(lVar5 + 0xa4) != '\0')) && ((*(byte *)(lVar1 + 0x28) & 4) != 0))))
  {
    nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x451,"serverUpdateLockFlagsForFree",1,
                 "NVRM: Overriding flags for free of class %04x\n",
                 *(undefined4 *)(*(long *)(param_2 + 0x28) + 0x11c));
    *(ulong *)(lVar1 + 0x28) = *(ulong *)(lVar1 + 0x28) | 0x4000000008;
  }
  return 0;
}


// ===== 0048bee0 rmapiFreeResourcePrologue =====

undefined8 rmapiFreeResourcePrologue(long param_1)

{
  long lVar1;
  long lVar2;
  undefined1 local_21;
  undefined8 local_20 [2];
  
  lVar1 = *(long *)(param_1 + 0x28);
  local_20[0] = 0;
  if (lVar1 != 0) {
    gpuGetByRef(lVar1,&local_21,local_20);
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(lVar1 + 8),__nvoc_class_def_TimerApi);
    if (lVar2 != 0) {
      tmrapiDeregisterEvents_IMPL(lVar2);
    }
    CliDelObjectEvents(lVar1);
    return 0;
  }
  nvAssertFailedNoLog("pResourceRef","src/kernel/rmapi/alloc_free.c",0x467);
  return 0x33;
}


// ===== 0048bf70 rmapiAlloc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiAlloc(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0x10))();
    return uVar1;
  }
  return 0x56;
}


// ===== 0048bfb0 rmapiAllocWithHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiAllocWithHandle(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x56;
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0x10))();
  }
  return uVar1;
}


// ===== 0048bff0 rmapiAllocWithSecInfo =====

int rmapiAllocWithSecInfo
              (long param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,uint param_5,
              undefined4 *param_6,undefined4 param_7,uint param_8,undefined8 param_9,uint *param_10)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  uint local_a4;
  long alStack_a0 [4];
  uint local_80;
  uint local_7c;
  undefined8 *local_78;
  undefined4 *local_70;
  undefined4 local_68;
  undefined8 local_50;
  
  local_d8 = 0;
  local_d4 = 0;
  iVar2 = rmapiPrologue(param_1,&local_d8);
  if (iVar2 != 0) {
    return iVar2;
  }
  lVar5 = portMemAllocNonPaged(0x40);
  if (lVar5 == 0) {
    iVar2 = 0x51;
    goto LAB_0048c276;
  }
  if ((param_10[1] == 1) &&
     (iVar2 = serverAllocLookupSecondClient(param_5,param_6,&local_d4), iVar2 != 0))
  goto LAB_0048c276;
  portMemSet(lVar5,0,0x40);
  iVar2 = rmapiInitLockInfo(param_1,param_2,local_d4,lVar5);
  if (iVar2 != 0) goto LAB_0048c276;
  if ((*(char *)(param_1 + 0xdc) != '\0') && (cVar1 = rmapiLockIsOwner(), cVar1 == '\0')) {
    cVar1 = rmapiInRtd3PmPath();
    if (cVar1 == '\0') {
      nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x4dc,"rmapiAllocWithSecInfo",4,
                   "NVRM: NVRM: %s: RMAPI_GPU_LOCK_INTERNAL alloc requested without holding the RMAPI lock: client:0x%x parent:0x%x object:0x%x class:0x%x\n"
                   ,"rmapiAllocWithSecInfo",param_2,param_3,*param_4,param_5);
    }
    *(uint *)(lVar5 + 0x28) = *(uint *)(lVar5 + 0x28) | 1;
    *(uint *)(lVar5 + 0x2c) = *(uint *)(lVar5 + 0x2c) & 0xfffffffe;
  }
  uVar3 = (param_8 & 1) << 6;
  if (*param_10 < 2) {
    if ((param_10[1] == 1) &&
       ((*(char *)(param_1 + 0xda) != '\0' || (*(char *)(param_1 + 0xdc) != '\0'))))
    goto LAB_0048c2d0;
  }
  else if (param_10[1] == 1) {
    if (*(char *)(param_1 + 0xdc) == '\0') {
      if (*(char *)(param_1 + 0xda) == '\0') goto LAB_0048c0f7;
    }
    else {
      uVar3 = uVar3 | 0x20;
    }
LAB_0048c2d0:
    uVar3 = uVar3 | 0x80;
  }
LAB_0048c0f7:
  nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x4f8,"rmapiAllocWithSecInfo",1,
               "NVRM: client:0x%x parent:0x%x object:0x%x class:0x%x\n",param_2,param_3,*param_4,
               param_5);
  local_d0 = *(undefined8 *)param_10;
  local_c8 = *(undefined8 *)(param_10 + 2);
  local_c0 = *(undefined8 *)(param_10 + 4);
  local_b8 = *(undefined8 *)(param_10 + 6);
  uVar6 = 0;
  do {
    uVar4 = (int)uVar6 + 0x20;
    *(undefined8 *)((long)alStack_a0 + uVar6) = 0;
    *(undefined8 *)((long)alStack_a0 + uVar6 + 8) = 0;
    *(undefined8 *)((long)alStack_a0 + uVar6 + 0x10) = 0;
    *(undefined8 *)((long)alStack_a0 + uVar6 + 0x18) = 0;
    uVar6 = (ulong)uVar4;
  } while (uVar4 < 0x60);
  *(undefined8 *)((long)alStack_a0 + (ulong)uVar4) = 0;
  local_80 = param_8;
  local_a8 = *param_4;
  local_78 = &local_d0;
  local_68 = param_7;
  local_50 = param_9;
  local_b0 = param_2;
  local_ac = param_3;
  local_a4 = param_5;
  alStack_a0[1] = lVar5;
  local_7c = uVar3;
  local_70 = param_6;
  iVar2 = serverAllocResource(g_resServ,&local_b0);
  *param_4 = local_a8;
  if (iVar2 == 0) {
    if ((((param_5 < 2) || (param_5 == 0x41)) && (param_10[1] == 1)) &&
       (*(char *)(param_1 + 0xdc) != '\0')) {
      rmclientSetClientFlagsByHandle(*param_6,1);
    }
    nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x515,"rmapiAllocWithSecInfo",1,
                 "NVRM: allocation complete\n");
  }
  else {
    uVar7 = nvstatusToString(iVar2);
    nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x519,"rmapiAllocWithSecInfo",1,
                 "NVRM: allocation failed; status: %s (0x%08x)\n",uVar7,iVar2);
    nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x51b,"rmapiAllocWithSecInfo",1,
                 "NVRM: client:0x%x parent:0x%x object:0x%x class:0x%x\n",param_2,param_3,*param_4,
                 param_5);
  }
LAB_0048c276:
  portMemFree(lVar5);
  rmapiEpilogue(param_1,&local_d8);
  return iVar2;
}


// ===== 0048c480 resservClientFactory =====

int resservClientFactory(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  long local_20 [2];
  
  iVar1 = __nvoc_objCreate_RmClient(local_20,0,0,param_1,param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_20[0] == 0) {
    nvAssertFailedNoLog("pClient != NULL","src/kernel/rmapi/alloc_free.c",0x539);
    uVar2 = 0;
    if (local_20[0] == 0) goto LAB_0048c4b9;
  }
  uVar2 = *(undefined8 *)(local_20[0] + 0x100);
LAB_0048c4b9:
  *param_3 = uVar2;
  return 0;
}


// ===== 0048c500 resservResourceFactory =====

int resservResourceFactory(undefined8 param_1,long param_2,undefined4 *param_3,long *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined4 local_4c;
  undefined8 local_40 [2];
  
  local_40[0] = 0;
  lVar4 = RsResInfoByExternalClassId(param_3[3]);
  if (lVar4 == 0) {
    return 0x22;
  }
  lVar5 = *(long *)(*(long *)(param_2 + 0x10) + 0x18);
  if ((lVar5 == 0) || (lVar5 = *(long *)(lVar5 + 8), lVar5 == 0)) {
    if (*(int *)(lVar4 + 4) == 0xe0ac20) goto LAB_0048c64f;
LAB_0048c5a0:
    iVar2 = __nvoc_objCreateDynamic(local_40,0,*(undefined8 *)(lVar4 + 8),1,param_2,param_3);
    if (iVar2 != 0) {
      return iVar2;
    }
    lVar6 = __nvoc_dynamicCast(local_40[0],__nvoc_class_def_RsResource);
    if (lVar6 == 0) {
      return 0x1a;
    }
    local_4c = 0xffffffff;
    lVar5 = 0;
  }
  else {
    lVar5 = __nvoc_dynamicCast(lVar5,__nvoc_class_def_GpuResource);
    if (lVar5 == 0) {
      if (*(int *)(lVar4 + 4) != 0xe0ac20) goto LAB_0048c5a0;
LAB_0048c64f:
      if ((*(uint **)(param_3 + 0x10) == (uint *)0x0) || (0x1f < **(uint **)(param_3 + 0x10))) {
        return 0x1f;
      }
      uVar3 = gpumgrGetPrimaryForDevice();
      lVar5 = gpumgrGetGpu(uVar3);
      if (lVar5 == 0) {
        return 0x40;
      }
    }
    else {
      if (*(int *)(lVar4 + 4) == 0xe0ac20) goto LAB_0048c64f;
      lVar5 = *(long *)(*(long *)(lVar5 + 0xd0) + 0xe0);
      if (lVar5 == 0) goto LAB_0048c5a0;
    }
    cVar1 = gpuIsClassSupported_IMPL(lVar5,param_3[3]);
    if (cVar1 == '\0') {
      nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x575,"resservResourceFactory",1,
                   "NVRM: Skipping unsupported class 0x%x\n",param_3[3]);
      return 0x56;
    }
    local_4c = gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar5 + 0x7a4));
    iVar2 = __nvoc_objCreateDynamic(local_40,lVar5,*(undefined8 *)(lVar4 + 8),1,param_2,param_3);
    if (iVar2 != 0) {
LAB_0048c6f0:
      gpumgrSetCurrentGpuInstance(local_4c);
      return iVar2;
    }
    lVar6 = __nvoc_dynamicCast(local_40[0],__nvoc_class_def_RsResource);
    if (lVar6 == 0) {
      iVar2 = 0x1a;
      goto LAB_0048c6f0;
    }
  }
  iVar2 = *(int *)(lVar4 + 4);
  if ((iVar2 == 0x4b01b3) || (iVar2 == 0xe0ac20)) {
    lVar4 = __nvoc_dynamicCast(local_40[0],__nvoc_class_def_GpuResource);
    lVar5 = *(long *)(*(long *)(lVar4 + 0xd0) + 0xe0);
  }
  else if (iVar2 != 0x41f4f2) {
    *param_4 = lVar6;
    if (lVar5 == 0) {
      return 0;
    }
    goto LAB_0048c773;
  }
  if (lVar5 == 0) {
    *param_4 = lVar6;
    return 0;
  }
  if ((*(long *)(lVar5 + 0x1bc0) == 0) ||
     (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar5), cVar1 == '\0')) {
    rmapiControlCacheSetGpuAttrForObject(*param_3,param_3[2],lVar5);
    *param_4 = lVar6;
  }
  else {
    *param_4 = lVar6;
  }
LAB_0048c773:
  gpumgrSetCurrentGpuInstance(local_4c);
  return 0;
}


// ===== 0048c850 rmapiAllocWithSecInfoTls =====

undefined4
rmapiAllocWithSecInfoTls
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
          undefined4 param_5,undefined8 param_6,undefined4 param_7,undefined4 param_8,
          undefined8 param_9,undefined8 param_10)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiAllocWithSecInfo
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 0048c8f0 rmapiFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiFree(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0x20))();
    return uVar1;
  }
  return 0x56;
}


// ===== 0048c920 rmapiFreeWithSecInfo =====

ulong rmapiFreeWithSecInfo
                (long param_1,undefined4 param_2,uint param_3,ulong param_4,undefined8 param_5)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined4 local_bc;
  undefined4 local_b8;
  uint local_b4;
  undefined1 *local_a0;
  ulong local_98;
  undefined8 local_80;
  undefined1 local_78 [40];
  uint local_50;
  uint local_4c;
  
  uVar4 = (ulong)param_3;
  local_bc = 0;
  portMemSet(&local_b8,0,0x40);
  nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x5e9,"rmapiFreeWithSecInfo",1,
               "NVRM: Nv01Free: client:0x%x object:0x%x\n",param_2);
  uVar2 = rmapiPrologue(param_1,&local_bc);
  uVar5 = (ulong)uVar2;
  if (uVar2 == 0) {
    portMemSet(local_78,0,0x40,uVar4);
    uVar2 = rmapiInitLockInfo(param_1,param_2,0,local_78);
    uVar5 = (ulong)uVar2;
    if (uVar2 == 0) {
      if (*(char *)(param_1 + 0xdc) != '\0') {
        cVar1 = rmapiLockIsOwner();
        if (cVar1 == '\0') {
          cVar1 = rmapiInRtd3PmPath();
          if (cVar1 == '\0') {
            nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x5ff,"rmapiFreeWithSecInfo",4,
                         "NVRM: RMAPI_GPU_LOCK_INTERNAL free requested without holding the RMAPI lock\n"
                        );
          }
          local_50 = local_50 | 1;
          local_4c = local_4c & 0xfffffffe;
        }
      }
      local_a0 = local_78;
      local_b8 = param_2;
      local_b4 = param_3;
      local_98 = param_4 & 0xffffffff;
      local_80 = param_5;
      rmapiControlCacheFreeObjectEntry(param_2,param_3);
      uVar2 = serverFreeResourceTree(g_resServ,&local_b8);
      uVar5 = (ulong)uVar2;
      rmapiEpilogue(param_1,&local_bc);
      if (uVar2 == 0) {
        nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x615,"rmapiFreeWithSecInfo",1,
                     "NVRM: Nv01Free: free complete\n");
      }
      else {
        if (uVar2 == 0x10) {
          uVar3 = nvstatusToString(0x10);
          uVar6 = 0;
          nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x619,"rmapiFreeWithSecInfo",1,
                       "NVRM: Nv01Free: free failed; status: %s (0x%08x)\n",uVar3,0x10);
          uVar3 = 1;
        }
        else {
          uVar3 = nvstatusToString(uVar2);
          uVar4 = uVar5;
          nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x619,"rmapiFreeWithSecInfo",3,
                       "NVRM: Nv01Free: free failed; status: %s (0x%08x)\n",uVar3,uVar5);
          uVar6 = (undefined4)(uVar4 >> 0x20);
          uVar3 = 3;
        }
        nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x61c,"rmapiFreeWithSecInfo",uVar3,
                     "NVRM: Nv01Free:  client:0x%x object:0x%x\n",param_2,CONCAT44(uVar6,param_3));
      }
    }
    else {
      rmapiEpilogue(param_1,&local_bc);
    }
  }
  return uVar5;
}


// ===== 0048cbc0 rmapiFreeWithSecInfoTls =====

undefined4
rmapiFreeWithSecInfoTls
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiFreeWithSecInfo(param_1,param_2,param_3,param_4,param_5);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 0048cc40 rmapiDisableClients =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 rmapiDisableClients(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    uVar1 = (**(code **)(param_1 + 0x30))();
    return uVar1;
  }
  return 0x56;
}


// ===== 0048cc70 rmapiDisableClientsWithSecInfo =====

undefined8
rmapiDisableClientsWithSecInfo(long param_1,undefined4 *param_2,uint param_3,undefined8 param_4)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  lVar2 = g_pSys;
  nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x655,"rmapiDisableClientsWithSecInfo",1,
               "NVRM: numClients: %d\n",param_3);
  if ((*(char *)(param_1 + 0xdb) == '\0') &&
     (iVar3 = osAcquireRmSema(*(undefined8 *)(lVar2 + 0x160)), iVar3 != 0)) {
    return 0x2f;
  }
  bVar5 = *(char *)(param_1 + 0xda) != '\0';
  if (*(char *)(param_1 + 0xdc) != '\0') {
    bVar5 = bVar5 | 0x40;
  }
  if (param_3 != 0) {
    puVar4 = param_2;
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      rmapiControlCacheFreeClientEntry(uVar1);
    } while (param_2 + param_3 != puVar4);
  }
  serverMarkClientListDisabled(g_resServ,param_2,param_3,bVar5,param_4);
  if (*(char *)(param_1 + 0xdb) == '\0') {
    osReleaseRmSema(*(undefined8 *)(lVar2 + 0x160),0);
  }
  nvDbg_Printf("src/kernel/rmapi/alloc_free.c",0x668,"rmapiDisableClientsWithSecInfo",1,
               "NVRM: Disable clients complete\n");
  return 0;
}


// ===== 0048cde0 rmapiDisableClientsWithSecInfoTls =====

undefined4
rmapiDisableClientsWithSecInfoTls
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined1 local_a8 [144];
  
  threadStateInit(local_a8,0);
  uVar1 = rmapiDisableClientsWithSecInfo(param_1,param_2,param_3,param_4);
  threadStateFree(local_a8,0);
  return uVar1;
}


// ===== 0048ce50 serverRwApiLockIsOwner =====

void serverRwApiLockIsOwner(void)

{
  rmapiLockIsWriteOwner();
  return;
}


// ===== 0048ce60 serverAllocResourceLookupLockFlags =====

undefined8
serverAllocResourceLookupLockFlags(undefined8 param_1,int param_2,long param_3,uint *param_4)

{
  long lVar1;
  char cVar2;
  long lVar3;
  
  lVar1 = g_pSys;
  if (param_4 == (uint *)0x0) {
    nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/alloc_free.c",0x695);
    return 0x1f;
  }
  if (param_2 == 1) {
    lVar3 = RsResInfoByExternalClassId(*(undefined4 *)(param_3 + 0xc));
    if (lVar3 == 0) {
      return 0x22;
    }
    *param_4 = *(byte *)(lVar3 + 0x24) >> 5 & 1 ^ 1;
    if (((*(byte *)(lVar3 + 0x26) & 2) != 0) && (*(char *)(lVar1 + 0x83) != '\0')) {
      *param_4 = 0;
      return 0;
    }
    cVar2 = serverSupportsReadOnlyLock(g_resServ,1,1);
    if (cVar2 != '\0') {
      return 0;
    }
  }
  else if (param_2 != 2) {
    return 0x56;
  }
  *param_4 = 1;
  return 0;
}


// ===== 0048cf50 serverFreeResourceLookupLockFlags =====

undefined8
serverFreeResourceLookupLockFlags
          (undefined8 param_1,undefined8 param_2,long param_3,uint *param_4,char *param_5)

{
  long lVar1;
  char cVar2;
  
  lVar1 = g_pSys;
  if (param_4 == (uint *)0x0) {
    nvAssertFailedNoLog("pAccess != NULL","src/kernel/rmapi/alloc_free.c",0x6d0);
    return 0x1f;
  }
  cVar2 = serverSupportsReadOnlyLock(param_1,param_2,2);
  *param_4 = (uint)(cVar2 == '\0');
  cVar2 = *(char *)(lVar1 + 0x83);
  *param_5 = cVar2;
  if (((*(long *)(param_3 + 0x28) != 0) &&
      ((*(byte *)(*(long *)(*(long *)(param_3 + 0x28) + 0x110) + 0x26) & 2) != 0)) &&
     (cVar2 != '\0')) {
    *param_4 = 0;
  }
  return 0;
}


// ===== 0048d010 binapiConstruct_IMPL =====

undefined8 binapiConstruct_IMPL(void)

{
  return 0;
}


// ===== 0048d020 binapiprivConstruct_IMPL =====

undefined8 binapiprivConstruct_IMPL(void)

{
  return 0;
}


// ===== 0048d030 binapiControl_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */

ulong binapiControl_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 extraout_RDX;
  undefined1 auVar7 [16];
  int local_1c [3];
  
  local_1c[0] = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar3 = param_3[2];
  uVar4 = (ulong)uVar3;
  if ((uVar3 != 0) && (uVar4 = (ulong)(uVar3 & 0x3fff), (uVar3 & 0x3fff) != 0)) {
    if (lVar2 == 0) {
      return 0x1f;
    }
    if (*(char *)(lVar2 + 0x908) == '\0') {
      if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
        return 0;
      }
      uVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar2 + 0x7a4),0,0,0x8002,local_1c);
      if (uVar3 != 0) {
        uVar6 = 0x6a;
LAB_0048d195:
        nvAssertOkFailedNoLog
                  (uVar3,
                   "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                   ,"src/kernel/rmapi/binary_api.c",uVar6);
        return (ulong)uVar3;
      }
      auVar7 = (**(code **)(lVar2 + 0x3b90))
                         (lVar2 + 0x3b58,*param_3,param_3[1],param_3[2],*(undefined8 *)(param_3 + 4)
                          ,param_3[6]);
    }
    else {
      uVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar2 + 0x7a4),0,0,0x8002,local_1c);
      uVar6 = 0x54;
      if (uVar3 != 0) goto LAB_0048d195;
      lVar5 = gpuGetRpc(lVar2);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/binary_api.c",0x5a);
        auVar7._8_8_ = extraout_RDX;
        auVar7._0_8_ = 0x1a;
      }
      else {
        uVar1 = param_3[6];
        uVar6 = (**(code **)(lVar5 + 0x358))
                          (lVar2,lVar5,*param_3,param_3[1],param_3[2],*(undefined8 *)(param_3 + 4));
        auVar7._8_4_ = uVar1;
        auVar7._0_8_ = uVar6;
        auVar7._12_4_ = 0;
      }
    }
    uVar4 = auVar7._0_8_;
    if (local_1c[0] != 0) {
      rmGpuGroupLockRelease(local_1c[0],0,auVar7._8_8_);
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  return uVar4;
}


// ===== 0048d1e0 binapiprivControl_IMPL =====

ulong binapiprivControl_IMPL(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  uVar1 = *(uint *)(param_3 + 8);
  uVar2 = (ulong)uVar1;
  if ((uVar1 != 0) && (uVar2 = (ulong)(uVar1 & 0x3fff), (uVar1 & 0x3fff) != 0)) {
    if (*(int *)(param_3 + 0x38) != 0) {
      uVar3 = 0;
      if (param_1 != 0) {
        uVar3 = *(undefined8 *)(param_1 + 0x168);
      }
      uVar2 = binapiControl_IMPL(uVar3);
      return uVar2;
    }
    uVar2 = 0x1b;
  }
  return uVar2;
}


// ===== 0048d216 _unregisterOSInfo.isra.0.cold =====

void _unregisterOSInfo_isra_0_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0048d220 _unregisterOSInfo.isra.0 =====

void _unregisterOSInfo_isra_0(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar3 = multimapFindItem_IMPL
                    (g_osInfoList,param_2,*(undefined4 *)(*(long *)(param_1 + 0x100) + 0x48));
  if (lVar3 != 0) {
    multimapRemoveItem_IMPL(g_osInfoList,lVar3);
  }
  lVar3 = multimapFindSubmap_IMPL(g_osInfoList,param_2);
  if (lVar3 != 0) {
    iVar2 = mapCount_IMPL(lVar3);
    if (iVar2 == 0) {
      multimapRemoveSubmap_IMPL(g_osInfoList,lVar3);
      return;
    }
  }
  return;
}


// ===== 0048d2b0 _unregisterUserInfo.isra.0 =====

void _unregisterUserInfo_isra_0(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long local_10;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x88);
  }
  local_10 = param_1;
  iVar1 = serverGetShareRefCount(g_resServ,uVar2);
  if (iVar1 == 1) {
    listRemoveFirstByValue_IMPL(g_userInfoList,&local_10);
  }
  uVar2 = 0;
  if (local_10 != 0) {
    uVar2 = *(undefined8 *)(local_10 + 0x88);
  }
  serverFreeShare(g_resServ,uVar2);
  return;
}


// ===== 0048d320 _rmclientUserClientSecurityCheck.isra.0 =====

int _rmclientUserClientSecurityCheck_isra_0(long param_1,uint param_2,long param_3)

{
  int iVar1;
  long lVar2;
  
  if ((g_pSys == 0) || (*(char *)(g_pSys + 0x6f) == '\0')) {
    return 0;
  }
  if ((param_2 < 2) || (*(char *)(param_1 + 0x114) != '\0')) {
    if (param_3 != 0) {
      iVar1 = osValidateClientTokens(*(undefined8 *)(param_1 + 0x240),param_3);
      if (iVar1 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/rmapi/client.c",0x214,"_rmclientUserClientSecurityCheck",3,
                   "NVRM: Error validating client token. Status = 0x%08x\n");
      return iVar1;
    }
    lVar2 = osGetSecurityToken();
    if (lVar2 != 0) {
      iVar1 = osValidateClientTokens(*(undefined8 *)(param_1 + 0x240),lVar2);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/rmapi/client.c",0x214,"_rmclientUserClientSecurityCheck",3,
                     "NVRM: Error validating client token. Status = 0x%08x\n");
      }
      portMemFree(lVar2);
      return iVar1;
    }
    nvDbg_Printf("src/kernel/rmapi/client.c",0x207,"_rmclientUserClientSecurityCheck",3,
                 "NVRM: Cannot get the security token for the current user.\n");
    nvDbg_Printf("src/kernel/rmapi/client.c",0x209,"_rmclientUserClientSecurityCheck",3,
                 "NVRM: The user client cannot be validated\n");
  }
  else {
    nvDbg_Printf("src/kernel/rmapi/client.c",0x1f9,"_rmclientUserClientSecurityCheck",3,
                 "NVRM: Incorrect client handle used in the User export\n");
  }
  return 0x23;
}


// ===== 0048d4d0 rmclientConstruct_IMPL =====

int rmclientConstruct_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  char *pcVar13;
  long local_78;
  long local_70;
  long local_68;
  undefined8 local_60;
  long *local_58 [5];
  
  lVar8 = g_pSys;
  lVar12 = 0;
  if (param_1 != 0) {
    lVar12 = *(long *)(param_1 + 0x100);
  }
  puVar1 = *(undefined4 **)(param_3 + 0xe);
  local_70 = param_1;
  cVar3 = rmapiLockIsWriteOwner();
  if ((cVar3 == '\0') &&
     ((cVar3 = serverIsClientInternal(g_resServ,*(undefined4 *)(lVar12 + 0x48)), cVar3 == '\0' ||
      (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')))) {
    nvAssertFailedNoLog("rmapiLockIsWriteOwner() || (serverIsClientInternal(&g_resServ, pRsClient->hClient) && rmGpuLockIsOwner())"
                        ,"src/kernel/rmapi/client.c",0x49);
    return 0x2f;
  }
  lVar11 = local_70;
  *(bool *)(local_70 + 0x114) = param_3[3] == 1;
  *(undefined8 *)(local_70 + 0x248) = 0;
  *(undefined8 *)(local_70 + 0x240) = 0;
  *(undefined8 *)(local_70 + 400) = *(undefined8 *)(puVar1 + 4);
  *(undefined8 *)(local_70 + 0x254) = 0xffffffff00000000;
  *(undefined4 *)(local_70 + 0x110) = *puVar1;
  uVar4 = osGetCurrentProcess();
  lVar6 = local_70;
  *(undefined4 *)(lVar11 + 0x118) = uVar4;
  if (*(uint *)(local_70 + 0x110) < 2) {
    uVar9 = osGetPidInfo();
    *(undefined8 *)(lVar6 + 0x198) = uVar9;
  }
  osGetCurrentProcessName(local_70 + 0x1a0,100);
  *(undefined8 *)(local_70 + 0x230) = 0;
  *(undefined8 *)(local_70 + 0x238) = 0;
  cVar3 = hypervisorIsVgxHyper_IMPL();
  if ((cVar3 == '\0') ||
     (iVar5 = clientSetHandleGenerator_IMPL(lVar12,0xcaf40000,0x40000), iVar5 == 0)) {
    iVar5 = clientSetRestrictedRange_IMPL(lVar12,0xc9f00000,0x80000);
    if (iVar5 == 0) {
      cVar3 = rmGpuLockIsOwner();
      if (cVar3 == '\0') {
        iVar5 = rmGpuLocksAcquire(0,0x200);
        if (iVar5 != 0) {
          nvAssertFailedNoLog(&DAT_00d8e440,"src/kernel/rmapi/client.c",0xa4);
          bVar2 = false;
          goto LAB_0048d688;
        }
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      lVar11 = local_70;
      uVar9 = *(undefined8 *)(local_70 + 400);
      uVar4 = *(undefined4 *)(*(long *)(local_70 + 0x100) + 0x48);
      lVar6 = multimapFindItem_IMPL(g_osInfoList,uVar9,uVar4);
      if (lVar6 == 0) {
        lVar6 = multimapFindSubmap_IMPL(g_osInfoList,uVar9);
        if (((lVar6 != 0) || (lVar6 = multimapInsertSubmap_IMPL(g_osInfoList,uVar9), lVar6 != 0)) &&
           (plVar7 = (long *)multimapInsertItemNew_IMPL(g_osInfoList,uVar9,uVar4),
           plVar7 != (long *)0x0)) {
          osAllocatedRmClient(uVar9);
          *plVar7 = lVar11;
          lVar11 = *(long *)(puVar1 + 2);
          *(bool *)(local_70 + 0x250) = lVar11 != 0;
          if ((*(char *)(lVar8 + 0x6f) != '\0') &&
             ((**(uint **)(param_3 + 0xe) < 2 || (*(char *)(local_70 + 0x114) != '\0')))) {
            if (lVar11 == 0) {
              local_78 = osGetSecurityToken();
            }
            else {
              local_78 = *(long *)(puVar1 + 2);
            }
            lVar8 = osGetCurrentUidToken();
            local_68 = 0;
            uVar9 = listTail_IMPL(g_userInfoList);
            uVar10 = listHead_IMPL(g_userInfoList);
            listIterRange_IMPL(local_58,g_userInfoList,uVar10,uVar9);
            if (lVar8 == 0) {
              iVar5 = 0x1f;
LAB_0048d972:
              portMemFree(lVar8);
              if ((local_78 != 0) && (*(char *)(local_70 + 0x250) == '\0')) {
                portMemFree(local_78);
              }
              goto LAB_0048d688;
            }
            do {
              cVar3 = listIterNext_IMPL(local_58);
              if (cVar3 == '\0') {
                iVar5 = serverAllocShare(g_resServ,__nvoc_class_def_UserInfo,&local_60);
                if (iVar5 != 0) goto LAB_0048d972;
                local_68 = __nvoc_dynamicCast(local_60,__nvoc_class_def_UserInfo);
                *(long *)(local_68 + 0x98) = lVar8;
                lVar11 = listAppendValue_IMPL(g_userInfoList,&local_68);
                if (lVar11 != 0) goto LAB_0048d9d4;
                serverFreeShare(g_resServ,local_60);
                iVar5 = 0x1a;
                goto LAB_0048d972;
              }
              local_68 = *local_58[0];
              cVar3 = osUidTokensEqual(*(undefined8 *)(local_68 + 0x98),lVar8);
            } while (cVar3 == '\0');
            uVar9 = 0;
            if (local_68 != 0) {
              uVar9 = *(undefined8 *)(local_68 + 0x88);
            }
            serverRefShare(g_resServ,uVar9);
            portMemFree(lVar8);
LAB_0048d9d4:
            *(long *)(local_70 + 0x248) = local_68;
            *(long *)(local_70 + 0x240) = local_78;
          }
          lVar8 = listAppendValue_IMPL(g_clientListBehindGpusLock,&local_70);
          if (lVar8 != 0) {
            if (bVar2) {
              rmGpuLocksRelease(0,0);
            }
            if (*(undefined4 **)(param_3 + 0x10) != (undefined4 *)0x0) {
              **(undefined4 **)(param_3 + 0x10) = *param_3;
            }
            eventSystemInitEventQueue(local_70 + 0x208);
            nvDbg_Printf("src/kernel/rmapi/client.c",0xe7,"rmclientConstruct_IMPL",1,
                         "NVRM: New RM Client: hClient=0x%08x (%c), ProcID=%u, name=\'%s\'\n",
                         *(undefined4 *)(lVar12 + 0x48),
                         (-(*(int *)(lVar12 + 0x4c) == 0) & 10U) + 0x4b,
                         *(undefined4 *)(local_70 + 0x118),local_70 + 0x1a0);
            return 0;
          }
          iVar5 = 0x1a;
          goto LAB_0048d688;
        }
        iVar5 = 0x51;
      }
      else {
        iVar5 = 0x19;
      }
      nvAssertOkFailedNoLog
                (iVar5,"_registerOSInfo(pClient, pClient->pOSInfo)","src/kernel/rmapi/client.c",0xaa
                );
      goto LAB_0048d688;
    }
    pcVar13 = "NVRM: Failed to set host client restricted resource handle range. Status=%x\n";
    uVar9 = 0x9a;
  }
  else {
    pcVar13 = "NVRM: NVRM_RPC: Failed to set host client resource handle range %x\n";
    uVar9 = 0x8f;
  }
  bVar2 = false;
  nvDbg_Printf("src/kernel/rmapi/client.c",uVar9,"rmclientConstruct_IMPL",3,pcVar13,iVar5);
LAB_0048d688:
  if (*(long *)(local_70 + 0x248) != 0) {
    _unregisterUserInfo_isra_0(*(long *)(local_70 + 0x248));
    *(undefined8 *)(local_70 + 0x248) = 0;
  }
  if ((*(long *)(local_70 + 0x240) != 0) && (*(char *)(local_70 + 0x250) == '\0')) {
    portMemFree(*(long *)(local_70 + 0x240));
    *(undefined8 *)(local_70 + 0x240) = 0;
  }
  _unregisterOSInfo_isra_0(local_70,*(undefined8 *)(local_70 + 400));
  if (bVar2) {
    rmGpuLocksRelease(0,0);
  }
  osPutPidInfo(*(undefined8 *)(local_70 + 0x198));
  *(undefined8 *)(local_70 + 0x198) = 0;
  return iVar5;
}


// ===== 0048db53 rmclientDestruct_IMPL.cold =====

void rmclientDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0048db60 rmclientDestruct_IMPL =====

void rmclientDestruct_IMPL(long param_1)

{
  code *pcVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  long local_20 [2];
  
  local_20[0] = param_1;
  cVar3 = rmapiLockIsWriteOwner();
  if (cVar3 == '\0') {
    if (local_20[0] == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    cVar3 = serverIsClientInternal(g_resServ,*(undefined4 *)(*(long *)(local_20[0] + 0x100) + 0x48))
    ;
    if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
      nvAssertFailedNoLog("rmapiLockIsWriteOwner() || (serverIsClientInternal(&g_resServ, staticCast(pClient, RsClient)->hClient) && rmGpuLockIsOwner())"
                          ,"src/kernel/rmapi/client.c",0x117);
    }
  }
  nvDbg_Printf("src/kernel/rmapi/client.c",0x11b,"rmclientDestruct_IMPL",1,
               "NVRM:     type: client\n");
  CliUnregisterFromThirdPartyP2P(local_20[0]);
  osPutPidInfo(*(undefined8 *)(local_20[0] + 0x198));
  eventSystemClearEventQueue(local_20[0] + 0x208);
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    iVar4 = rmGpuLocksAcquire(0,0x200);
    if (iVar4 == 0) {
      bVar2 = true;
    }
    else {
      nvAssertFailedNoLog(&DAT_00d8e440,"src/kernel/rmapi/client.c",0x12f);
      bVar2 = false;
    }
  }
  else {
    bVar2 = false;
  }
  _unregisterOSInfo_isra_0(local_20[0],*(undefined8 *)(local_20[0] + 400));
  listRemoveFirstByValue_IMPL(g_clientListBehindGpusLock,local_20);
  if (*(long *)(local_20[0] + 0x248) != 0) {
    _unregisterUserInfo_isra_0();
    *(undefined8 *)(local_20[0] + 0x248) = 0;
  }
  if (*(long *)(local_20[0] + 0x240) != 0) {
    if (*(char *)(local_20[0] + 0x250) == '\0') {
      portMemFree();
    }
    *(undefined8 *)(local_20[0] + 0x240) = 0;
  }
  if (bVar2) {
    rmGpuLocksRelease(0,0);
    return;
  }
  return;
}


// ===== 0048dd10 rmclientInterMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rmclientInterMap_IMPL(undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined8 *puVar1;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  long local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  undefined1 local_30;
  undefined1 local_2f;
  
  puVar1 = *(undefined8 **)(param_4 + 0x50);
  portMemSet(&local_90,0,0x68);
  local_58 = *(undefined8 *)(param_4 + 0x10);
  local_50 = *(undefined8 *)(param_4 + 0x18);
  local_48 = *(undefined8 *)(param_4 + 0x20);
  local_40 = *(undefined4 *)(param_4 + 0x28);
  local_38 = param_4 + 0x30;
  local_78 = param_4 + 0x38;
  local_90 = *puVar1;
  local_88 = puVar1[1];
  local_80 = puVar1[2];
  local_68 = *(undefined4 *)(puVar1 + 3);
  local_64 = *(undefined4 *)((long)puVar1 + 0x1c);
  local_60 = *(undefined4 *)(puVar1 + 4);
  local_30 = *(undefined1 *)((long)puVar1 + 0x24);
  local_2f = *(undefined1 *)((long)puVar1 + 0x25);
  local_70 = param_3;
  (**(code **)(**(long **)(param_2 + 8) + 0x90))(*(long **)(param_2 + 8),&local_90);
  return;
}


// ===== 0048ddf0 rmclientInterUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void rmclientInterUnmap_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined1 local_30;
  
  puVar1 = *(undefined8 **)(param_3 + 0x40);
  portMemSet(&local_60,0,0x38);
  local_38 = *(undefined8 *)(param_3 + 0x28);
  local_58 = *(undefined4 *)(param_3 + 0x20);
  local_4c = *(undefined4 *)(param_3 + 0xc);
  local_48 = *(undefined8 *)(param_3 + 0x10);
  local_40 = *(undefined8 *)(param_3 + 0x18);
  local_60 = *puVar1;
  local_54 = *(undefined4 *)(puVar1 + 1);
  local_50 = *(undefined4 *)((long)puVar1 + 0xc);
  local_30 = *(undefined1 *)(puVar1 + 2);
  (**(code **)(**(long **)(param_2 + 8) + 0x98))(*(long **)(param_2 + 8),&local_60);
  return;
}


// ===== 0048de90 rmclientGetCachedPrivilege_IMPL =====

undefined4 rmclientGetCachedPrivilege_IMPL(long param_1)

{
  return *(undefined4 *)(param_1 + 0x110);
}


// ===== 0048dea0 rmclientIsAdmin_IMPL =====

bool rmclientIsAdmin_IMPL(long param_1,int param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    return *(char *)(param_1 + 0x114) == '\0';
  }
  return false;
}


// ===== 0048dec3 rmclientPostProcessPendingFreeList_IMPL.cold =====

void rmclientPostProcessPendingFreeList_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0048ded0 rmclientPostProcessPendingFreeList_IMPL =====

undefined8 rmclientPostProcessPendingFreeList_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x100);
  lVar5 = *(long *)(*(long *)(lVar1 + 0xd8) + 8);
  lVar3 = listHead_IMPL(lVar1 + 0xc0);
  while (lVar6 = lVar3, lVar5 != lVar3) {
    while (lVar3 = listNext_IMPL(lVar1 + 0xc0,lVar6), *(int *)(*(long *)(lVar6 + 0x110) + 0x20) == 1
          ) {
      clientUpdatePendingFreeList_IMPL(lVar1,lVar6,lVar6,1);
      lVar6 = lVar3;
      if (lVar5 == lVar3) goto LAB_0048df60;
    }
  }
LAB_0048df60:
  if (lVar5 == 0) {
    lVar5 = listTail_IMPL(lVar1 + 0xc0);
  }
  uVar4 = listHead_IMPL(lVar1 + 0xc0);
  do {
    lVar3 = lVar5;
    if (lVar3 == 0) goto LAB_0048dfa4;
    lVar5 = listPrev_IMPL(lVar1 + 0xc0,lVar3);
  } while (*(int *)(*(long *)(lVar3 + 0x110) + 0x20) != 1);
  uVar4 = listNext_IMPL(lVar1 + 0xc0,lVar3);
LAB_0048dfa4:
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = uVar4;
  }
  return 0;
}


// ===== 0048e000 rmclientSetClientFlagsByHandle =====

bool rmclientSetClientFlagsByHandle(undefined8 param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = serverutilGetClientUnderLock();
  if (lVar1 != 0) {
    *(uint *)(lVar1 + 0x188) = *(uint *)(lVar1 + 0x188) | param_2;
  }
  return lVar1 != 0;
}


// ===== 0048e030 rmclientGetSecurityTokenByHandle =====

undefined8 rmclientGetSecurityTokenByHandle(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = serverutilGetClientUnderLock();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x240);
  }
  return uVar2;
}


// ===== 0048e050 userinfoConstruct_IMPL =====

undefined8 userinfoConstruct_IMPL(void)

{
  return 0;
}


// ===== 0048e060 userinfoDestruct_IMPL =====

void userinfoDestruct_IMPL(long param_1)

{
  portMemFree(*(undefined8 *)(param_1 + 0x98));
  return;
}


// ===== 0048e070 rmclientValidate_IMPL =====

undefined8 rmclientValidate_IMPL(long param_1,uint *param_2)

{
  undefined8 uVar1;
  
  if ((*(char *)(g_pSys + 0x6f) != '\0') && (param_2 != (uint *)0x0)) {
    if ((*(char *)(g_pSys + 0x70) != '\0') && (*(long *)(param_2 + 4) != 0)) {
      uVar1 = 0x23;
      if (*(long *)(param_2 + 4) == *(long *)(param_1 + 400)) {
        uVar1 = 0;
      }
      return uVar1;
    }
    if (*param_2 < 2) {
      uVar1 = _rmclientUserClientSecurityCheck_isra_0(param_1,*param_2,*(undefined8 *)(param_2 + 2))
      ;
      return uVar1;
    }
  }
  return 0;
}


// ===== 0048e0d0 rmclientValidateLocks_IMPL =====

undefined8 rmclientValidateLocks_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  char cVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_3 + 0x18);
  lVar3 = portThreadGetCurrentThreadId();
  if (lVar1 != lVar3) {
    cVar2 = rmapiLockIsWriteOwner();
    if (cVar2 == '\0') {
      cVar2 = rmapiLockIsOwner();
      if (cVar2 == '\0') {
LAB_0048e132:
        nvAssertFailedNoLog(&DAT_00d8e440,"src/kernel/rmapi/client.c",0x33a);
        return 0x2f;
      }
      if (*(long *)(param_1 + 0x240) != 0) {
        cVar2 = serverIsClientInternal(param_2,*(undefined4 *)(param_3 + 0x10));
        if (cVar2 == '\0') goto LAB_0048e132;
      }
    }
  }
  return 0;
}


// ===== 0048e160 rmclientFreeResource_IMPL =====

undefined4 rmclientFreeResource_IMPL(long param_1,undefined8 param_2,long param_3)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  long local_30;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x100);
  }
  iVar3 = gpuGetByRef(*(undefined8 *)(param_3 + 0x28),0,&local_30);
  if (iVar3 != 0) {
    rmapiFreeResourcePrologue(param_3);
    cVar2 = rmapiInRtd3PmPath();
    if (cVar2 != '\0') {
      puVar1 = (uint *)(*(long *)(param_3 + 0x18) + 0x28);
      *puVar1 = *puVar1 | 1;
    }
    uVar4 = clientFreeResource_IMPL(uVar6,param_2,param_3);
    return uVar4;
  }
  uVar4 = gpumgrSetCurrentGpuInstance(*(undefined4 *)(local_30 + 0x7a4));
  rmapiFreeResourcePrologue(param_3);
  cVar2 = rmapiInRtd3PmPath();
  if (cVar2 != '\0') {
    puVar1 = (uint *)(*(long *)(param_3 + 0x18) + 0x28);
    *puVar1 = *puVar1 | 1;
  }
  uVar5 = clientFreeResource_IMPL(uVar6,param_2,param_3);
  gpumgrSetCurrentGpuInstance(uVar4);
  return uVar5;
}


// ===== 0048e250 rmclientIsCapableOrAdmin_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool rmclientIsCapableOrAdmin_IMPL(long *param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  undefined *puVar4;
  
  cVar1 = (**(code **)(*param_1 + 0xe0))(param_1,param_3);
  if (cVar1 == '\0') {
    if (param_2 == 4) {
      puVar4 = (undefined *)0xb4748b;
      goto LAB_0048e2ad;
    }
    if (param_2 < 5) {
      if (param_2 == 2) {
        puVar4 = (undefined *)0x36a941;
LAB_0048e2ad:
        lVar3 = serverutilFindChildRefByType
                          (*(undefined4 *)(param_1[0x20] + 0x48),
                           *(undefined4 *)(param_1[0x20] + 0x48),puVar4,1);
        return lVar3 != 0;
      }
      puVar4 = (undefined *)0x29e15c;
      if (param_2 == 3) goto LAB_0048e2ad;
    }
    else {
      puVar4 = &DAT_00dfbd08;
      if (param_2 == 0x200) goto LAB_0048e2ad;
    }
    nvAssertFailedNoLog(&DAT_00d8e440,"src/kernel/rmapi/client.c",0x38f);
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  return bVar2;
}


// ===== 0048e31f rmclientIsCapable_IMPL.cold =====

void rmclientIsCapable_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0048e330 rmclientIsCapable_IMPL =====

bool rmclientIsCapable_IMPL(long param_1,uint param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  long lVar3;
  undefined *puVar4;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (param_2 == 4) {
    puVar4 = (undefined *)0xb4748b;
  }
  else if (param_2 < 5) {
    if (param_2 == 2) {
      puVar4 = (undefined *)0x36a941;
    }
    else {
      puVar4 = (undefined *)0x29e15c;
      if (param_2 != 3) goto LAB_0048e385;
    }
  }
  else {
    puVar4 = &DAT_00dfbd08;
    if (param_2 != 0x200) {
LAB_0048e385:
      nvAssertFailedNoLog(&DAT_00d8e440,"src/kernel/rmapi/client.c",0x38f);
      return false;
    }
  }
  uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x100) + 0x48);
  lVar3 = serverutilFindChildRefByType(uVar1,uVar1,puVar4,1);
  return lVar3 != 0;
}


// ===== 0048e3c0 CliGetSystemP2pCaps_GSPCLIENT.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int CliGetSystemP2pCaps_GSPCLIENT_part_0
              (undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
              undefined4 *param_5,undefined1 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  undefined8 uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  long lVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined8 extraout_RDX;
  undefined4 *puVar14;
  ulong uVar15;
  uint uVar16;
  ulong uVar17;
  bool bVar18;
  undefined8 uStack_c0;
  int local_70;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  uVar17 = (ulong)param_2;
  puVar6 = (undefined4 *)portMemAllocNonPaged(0x688);
  if (puVar6 == (undefined4 *)0x0) {
    nvCheckFailedNoLog(1,"pGetParams != NULL","src/kernel/rmapi/client_resource.c",0xed5);
    return 0x51;
  }
  *param_4 = 0;
  *param_5 = 0;
  *param_3 = 0;
  puVar12 = param_6;
  do {
    *puVar12 = 5;
    puVar13 = puVar12 + 3;
    puVar12[1] = 5;
    puVar12[2] = 5;
    puVar12 = puVar13;
  } while (puVar13 != param_6 + 9);
  if (param_7 != (undefined4 *)0x0) {
    puVar14 = param_7;
    if ((param_2 * param_2 & 1) != 0) {
      puVar14 = param_7 + 1;
      *param_7 = 0xffffffff;
      if (puVar14 == param_7 + param_2 * param_2) goto LAB_0048e4b6;
    }
    do {
      *puVar14 = 0xffffffff;
      puVar9 = puVar14 + 2;
      puVar14[1] = 0xffffffff;
      puVar14 = puVar9;
    } while (puVar9 != param_7 + param_2 * param_2);
  }
LAB_0048e4b6:
  if (param_8 != (undefined4 *)0x0) {
    puVar14 = param_8;
    if ((param_2 * param_2 & 1) != 0) {
      puVar14 = param_8 + 1;
      *param_8 = 0xffffffff;
      if (puVar14 == param_8 + param_2 * param_2) goto LAB_0048e516;
    }
    do {
      *puVar14 = 0xffffffff;
      puVar9 = puVar14 + 2;
      puVar14[1] = 0xffffffff;
      puVar14 = puVar9;
    } while (puVar9 != param_8 + param_2 * param_2);
  }
LAB_0048e516:
  puVar6[1] = param_2;
  *(undefined2 *)puVar6 = 0x100;
  if (param_2 == 0) {
    iVar5 = 0;
  }
  else {
    puVar14 = puVar6 + 3;
    puVar9 = param_1;
    do {
      lVar7 = gpumgrGetGpuFromId(*puVar9);
      if (lVar7 == 0) {
        uVar11 = 0xeff;
        goto LAB_0048e581;
      }
      portMemCopy(puVar14,0x10,lVar7 + 0x7c5,0x10);
      puVar9 = puVar9 + 1;
      puVar14 = puVar14 + 0xd;
    } while (puVar9 != param_1 + uVar17);
    bVar18 = param_2 != 1;
    uVar15 = 0;
    uVar16 = 0;
    do {
      local_70 = 0;
      lVar7 = gpumgrGetGpuFromId(param_1[uVar15]);
      if (lVar7 == 0) {
        uVar11 = 0xf10;
LAB_0048e581:
        nvCheckFailedNoLog(1,"pGpu != NULL","src/kernel/rmapi/client_resource.c",uVar11);
        iVar5 = 0x1f;
        break;
      }
      cVar4 = rmGpuGroupLockIsOwner(*(undefined4 *)(lVar7 + 0x7a4),0,&local_70);
      if (cVar4 == '\0') {
        iVar5 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar7 + 0x7a4),0,0,0x8002,&local_70);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                     ,"src/kernel/rmapi/client_resource.c",0xf16);
          break;
        }
        bVar3 = true;
        uStack_c0 = 0x48e62d;
        lVar8 = gpuGetRpc(lVar7);
      }
      else {
        bVar3 = false;
        uStack_c0 = 0x48e713;
        lVar8 = gpuGetRpc(lVar7);
      }
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/client_resource.c",0xf21);
        if ((bVar3) && (local_70 != 0)) {
          rmGpuGroupLockRelease(local_70,0);
        }
        iVar5 = 0x1a;
        break;
      }
      if ((*(char *)(lVar7 + 0x909) == '\0') && (*(char *)(lVar7 + 0x90a) == '\0')) {
        iVar5 = rpcDmaControl_wrapper
                          (lVar7,lVar8,*(undefined4 *)(lVar7 + 0x3b34),
                           *(undefined4 *)(lVar7 + 0x3b3c),0x208001a0,puVar6,0x688);
      }
      else {
        iVar5 = (**(code **)(lVar7 + 0x3b90))
                          (lVar7 + 0x3b58,*(undefined4 *)(lVar7 + 0x3b34),
                           *(undefined4 *)(lVar7 + 0x3b3c),0x208001a0,puVar6,0x688);
        uStack_c0 = extraout_RDX;
      }
      if ((bVar3) && (local_70 != 0)) {
        rmGpuGroupLockRelease(local_70,0,uStack_c0);
      }
      if (iVar5 != 0) break;
      if (uVar15 == 0) {
        local_6c = *(undefined8 *)(puVar6 + (ulong)bVar18 * 0xd + 2);
        local_64 = *(undefined8 *)(puVar6 + (ulong)bVar18 * 0xd + 4);
        uVar11 = *(undefined8 *)(puVar6 + (ulong)bVar18 * 0xd + 6);
        uVar2 = *(undefined8 *)(puVar6 + (ulong)bVar18 * 0xd + 8);
        local_4c = *(undefined8 *)(puVar6 + (ulong)bVar18 * 0xd + 10);
        local_44 = *(undefined8 *)(puVar6 + (ulong)bVar18 * 0xd + 0xc);
        local_3c = puVar6[(ulong)bVar18 * 0xd + 0xe];
        local_5c._4_4_ = (undefined4)((ulong)uVar11 >> 0x20);
        *param_3 = local_5c._4_4_;
        if (param_2 < 3) {
          local_54._0_4_ = (undefined4)uVar2;
          *param_4 = (undefined4)local_54;
          local_54._4_4_ = (undefined4)((ulong)uVar2 >> 0x20);
          *param_5 = local_54._4_4_;
        }
        local_5c = uVar11;
        local_54 = uVar2;
        portMemCopy(param_6,9,&local_4c,9);
      }
      if (param_7 != (undefined4 *)0x0) {
        puVar9 = param_7 + uVar16;
        puVar14 = puVar6;
        do {
          puVar14 = puVar14 + 0xd;
          puVar10 = puVar9 + 1;
          *puVar9 = *puVar14;
          puVar9 = puVar10;
        } while (puVar10 != param_7 + uVar16 + uVar17);
      }
      if (param_8 != (undefined4 *)0x0) {
        puVar14 = puVar6 + 0xe;
        puVar9 = param_8 + uVar16;
        do {
          uVar1 = *puVar14;
          puVar10 = puVar9 + 1;
          puVar14 = puVar14 + 0xd;
          *puVar9 = uVar1;
          puVar9 = puVar10;
        } while (param_8 + uVar16 + uVar17 != puVar10);
      }
      uVar15 = uVar15 + 1;
      uVar16 = uVar16 + param_2;
    } while (uVar15 != uVar17);
  }
  portMemFree(puVar6);
  return iVar5;
}


// ===== 0048e9c0 configReadStructure =====

void configReadStructure(long param_1,uint *param_2,uint param_3,char *param_4)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  
  uVar7 = (uint)*param_4;
  if (*param_4 == '\0') {
    return;
  }
  pbVar9 = (byte *)(param_4 + 1);
  pbVar8 = pbVar9;
  uVar3 = uVar7;
  while( true ) {
    while ((byte)((char)uVar3 - 0x30U) < 10) {
      bVar2 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      uVar3 = (uint)bVar2;
    }
    uVar3 = (uint)*pbVar8;
    if (*pbVar8 == 0) break;
    pbVar8 = pbVar8 + 1;
  }
  puVar11 = (uint *)(param_1 + (ulong)param_3);
  do {
    iVar4 = 0;
    pbVar8 = pbVar9;
    iVar5 = iVar4;
    if ((byte)((char)uVar7 - 0x30U) < 10) {
      do {
        pbVar9 = pbVar8 + 1;
        iVar4 = (uVar7 - 0x30) + iVar4 * 10;
        bVar2 = *pbVar8;
        uVar7 = (uint)(char)bVar2;
        pbVar8 = pbVar9;
      } while ((byte)(bVar2 - 0x30) < 10);
      iVar5 = iVar4 + -1;
      if (iVar4 == 0) {
        iVar5 = 0;
      }
    }
    puVar1 = param_2 + (iVar5 + 1);
    cVar6 = (char)uVar7;
    puVar12 = puVar11;
    if (cVar6 == 's') {
      do {
        puVar11 = (uint *)((long)puVar12 + 1);
        bVar2 = (byte)*puVar12;
        uVar7 = (uint)bVar2;
        if ((char)bVar2 < '\0') {
          uVar7 = bVar2 | 0xffffff00;
        }
        puVar10 = param_2 + 1;
        *param_2 = uVar7;
        param_2 = puVar10;
        puVar12 = puVar11;
      } while (puVar1 != puVar10);
    }
    else {
      if ('s' < cVar6) {
        if (cVar6 == 'w') goto LAB_0048eb00;
LAB_0048ea5e:
        nvAssertFailedNoLog("!\"Bad pFormat argument\"","src/kernel/rmapi/client_resource.c",0x2eb);
        return;
      }
      if (cVar6 != 'b') {
        if (cVar6 != 'd') goto LAB_0048ea5e;
        do {
          uVar7 = *puVar11;
          puVar11 = puVar11 + 1;
          *param_2 = uVar7;
          while( true ) {
            param_2 = param_2 + 1;
            if (puVar1 == param_2) goto LAB_0048eaa6;
            if (cVar6 < 't') break;
LAB_0048eb00:
            uVar7 = *puVar11;
            puVar11 = (uint *)((long)puVar11 + 2);
            *param_2 = (uint)(ushort)uVar7;
          }
        } while (cVar6 != 'b');
      }
      do {
        uVar7 = *puVar11;
        puVar12 = param_2 + 1;
        puVar11 = (uint *)((long)puVar11 + 1);
        *param_2 = (uint)(byte)uVar7;
        param_2 = puVar12;
      } while (puVar12 != puVar1);
    }
LAB_0048eaa6:
    uVar7 = (uint)(char)*pbVar9;
    if (*pbVar9 == 0) {
      return;
    }
    pbVar9 = pbVar9 + 1;
    param_2 = puVar1;
  } while( true );
}


// ===== 0048eb50 cliresConstruct_IMPL =====

undefined8 cliresConstruct_IMPL(void)

{
  return 0;
}


// ===== 0048eb60 cliresDestruct_IMPL =====

void cliresDestruct_IMPL(void)

{
  return;
}


// ===== 0048eb70 cliresAccessCallback_IMPL =====

undefined8 cliresAccessCallback_IMPL(void)

{
  undefined8 uVar1;
  ushort in_CX;
  
  if ((in_CX & 0xfffd) != 1) {
    return 0;
  }
  uVar1 = osCheckAccess(in_CX);
  return uVar1;
}


// ===== 0048eb90 cliresShareCallback_IMPL.cold =====

void cliresShareCallback_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0048eba0 cliresShareCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresShareCallback_IMPL(long param_1,undefined8 param_2,long param_3,long param_4)

{
  ushort uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar6 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48),
                             __nvoc_class_def_RmClient);
  plVar7 = (long *)__nvoc_dynamicCast(param_2,__nvoc_class_def_RmClient);
  if (plVar7 == (long *)0x0) {
    uVar1 = *(ushort *)(param_4 + 8);
    if (uVar1 == 4) goto LAB_0048ec3a;
  }
  else {
    uVar3 = (**(code **)(*plVar7 + 0xd8))(plVar7);
    uVar1 = *(ushort *)(param_4 + 8);
    if (uVar1 == 4) {
      if (lVar6 != 0) {
        iVar4 = *(int *)(lVar6 + 0x118);
        if ((param_3 == 0) || (uVar3 < 2)) {
          iVar5 = (int)plVar7[0x23];
        }
        else {
          iVar5 = osGetCurrentProcess();
        }
        if (iVar5 == iVar4) {
          return 1;
        }
      }
      goto LAB_0048ec3a;
    }
    if (uVar1 < 5) {
      if (((uVar1 == 2) && (lVar6 != 0)) && (*(long *)(lVar6 + 0x240) != 0)) {
        if (uVar3 < 2) {
          if (plVar7[0x48] == 0) goto LAB_0048ec3a;
          iVar4 = osValidateClientTokens();
        }
        else {
          lVar9 = osGetSecurityToken();
          if (lVar9 == 0) {
            nvAssertFailedNoLog("Cannot get the security token for the current user",
                                "src/kernel/rmapi/client_resource.c",199);
            return 0;
          }
          iVar4 = osValidateClientTokens(*(undefined8 *)(lVar6 + 0x240),lVar9);
          portMemFree(lVar9);
        }
        if (iVar4 == 0) {
          return 1;
        }
      }
      goto LAB_0048ec3a;
    }
  }
  if (((ushort)(uVar1 - 5) < 2) && ((*(byte *)(param_4 + 10) & 2) != 0)) {
    return 1;
  }
LAB_0048ec3a:
  uVar8 = resShareCallback_IMPL(*(undefined8 *)(param_1 + 0xe0),param_2,param_3,param_4);
  return uVar8;
}


// ===== 0048ed80 cliresControl_Prologue_IMPL =====

void cliresControl_Prologue_IMPL(undefined8 param_1,undefined8 param_2,long param_3)

{
  serverDeserializeCtrlDown
            (param_2,*(undefined4 *)(param_3 + 8),param_3 + 0x10,param_3 + 0x18,param_3 + 0xc);
  return;
}


// ===== 0048eda0 cliresControl_Epilogue_IMPL =====

void cliresControl_Epilogue_IMPL(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  iVar1 = serverSerializeCtrlUp
                    (param_2,*(undefined4 *)(param_3 + 8),param_3 + 0x10,param_3 + 0x18,
                     param_3 + 0xc);
  if (iVar1 == 0) {
    serverFreeSerializeStructures(param_2,*(undefined8 *)(param_3 + 0x10));
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "serverSerializeCtrlUp(pCallContext, pParams->cmd, &pParams->pParams, &pParams->paramsSize, &pParams->flags)"
             ,"src/kernel/rmapi/client_resource.c",0x109);
  serverFreeSerializeStructures(param_2,*(undefined8 *)(param_3 + 0x10));
  return;
}


// ===== 0048ee10 CliGetSystemP2pCaps =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int CliGetSystemP2pCaps(undefined4 *param_1,uint param_2,uint *param_3,undefined4 *param_4,
                       undefined4 *param_5,char *param_6,long param_7,long param_8)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  undefined8 extraout_RDX;
  undefined8 uVar9;
  ulong uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  ulong uVar13;
  uint local_98;
  byte local_94;
  uint local_68;
  char local_3f;
  char local_3e;
  char local_3d;
  int local_3c [3];
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x164);
    return 0x2f;
  }
  if (0x1f < param_2 - 1) {
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x168,"CliGetSystemP2pCaps",3,
                 "NVRM: Invalid GPU count\n");
    return 0x1f;
  }
  *param_4 = 0;
  *param_5 = 0;
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if (param_6 != (char *)0x0) {
    pcVar5 = param_6;
    do {
      *pcVar5 = '\x05';
      pcVar6 = pcVar5 + 3;
      pcVar5[1] = '\x05';
      pcVar5[2] = '\x05';
      pcVar5 = pcVar6;
    } while (pcVar6 != param_6 + 9);
  }
  uVar10 = (ulong)param_2;
  uVar13 = 0;
  local_68 = 0;
  local_98 = 0;
  do {
    lVar7 = gpumgrGetGpuFromId(param_1[uVar13]);
    if (lVar7 == 0) {
      uVar9 = 0x182;
      uVar11 = param_1[uVar13];
      goto LAB_0048f0fc;
    }
    if (*(char *)(lVar7 + 0x45a) == '\0') {
      uVar11 = *(undefined4 *)(lVar7 + 0x7a4);
      puVar12 = param_1;
      uVar4 = local_68;
      do {
        lVar8 = gpumgrGetGpuFromId(*puVar12);
        if (lVar8 == 0) {
          uVar11 = *puVar12;
          uVar9 = 0x194;
          goto LAB_0048f0fc;
        }
        if (*(char *)(lVar8 + 0x45a) == '\0') {
          if (param_7 != 0) {
            uVar3 = (**(code **)(*(long *)(&DAT_00001b90 + lVar7) + 0x288))(lVar7);
            *(undefined4 *)(param_7 + (ulong)uVar4 * 4) = uVar3;
          }
          if (param_8 != 0) {
            uVar3 = (**(code **)(*(long *)(&DAT_00001b90 + lVar7) + 0x280))(lVar7);
            *(undefined4 *)(param_8 + (ulong)uVar4 * 4) = uVar3;
          }
        }
        puVar12 = puVar12 + 1;
        uVar4 = uVar4 + 1;
      } while (param_1 + uVar10 != puVar12);
      local_94 = (byte)uVar11;
      local_98 = local_98 | 1 << (local_94 & 0x1f);
    }
    uVar13 = uVar13 + 1;
    local_68 = local_68 + param_2;
  } while (uVar10 != uVar13);
  lVar7 = gpumgrGetGpuFromId(*param_1);
  if (lVar7 == 0) {
    uVar9 = 0x1b1;
    uVar11 = param_1[uVar10];
LAB_0048f0fc:
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",uVar9,"CliGetSystemP2pCaps",3,
                 "NVRM: GPU ID not found: 0x%x\n",uVar11);
    return 0x1f;
  }
  if (*(char *)(lVar7 + 0x45a) != '\0') {
    return 0x56;
  }
  iVar2 = p2pGetCapsStatus(local_98,&local_3f,&local_3e,&local_3d,local_3c);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (local_3c[0] == 3) {
    lVar8 = *(long *)(lVar7 + 0x1ce8);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pLocalKernelNvlink != NULL","src/kernel/rmapi/client_resource.c",0x1c7);
      return 0x40;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = (uint)(local_3d == '\0') << 4 | *param_3 | 0xb;
    }
    if (param_6 == (char *)0x0) {
      if (2 < param_2) {
        return 0;
      }
      (**(code **)(lVar8 + 0x1e8))(lVar7,lVar8,local_98,0,0,param_4);
      if (param_2 != 1) {
        return 0;
      }
      cVar1 = knvlinkIsP2pLoopbackSupported_IMPL(lVar7,lVar8,extraout_RDX,param_5);
      if (cVar1 == '\0') {
        return 0;
      }
    }
    else {
      param_6[2] = '\0';
      if (local_3d == '\0') {
        param_6[3] = '\0';
      }
      if (((2 < param_2) ||
          ((**(code **)(lVar8 + 0x1e8))(lVar7,lVar8,local_98,0,0,param_4,param_5), param_2 != 1)) ||
         (cVar1 = knvlinkIsP2pLoopbackSupported_IMPL(lVar7,lVar8,0x48ef78), cVar1 == '\0'))
      goto LAB_0048efbf;
    }
    if (param_3 != (uint *)0x0) {
      *param_3 = *param_3 | 0x20;
    }
    if (param_6 == (char *)0x0) {
      return 0;
    }
    param_6[5] = '\0';
    goto LAB_0048efbf;
  }
  if (1 < local_3c[0] - 1U) {
    if (local_3c[0] == 4) {
      lVar8 = *(long *)(lVar7 + 0x1ce8);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pLocalKernelNvlink != NULL","src/kernel/rmapi/client_resource.c",0x229)
        ;
        return 0x40;
      }
      if (param_3 != (uint *)0x0) {
        *param_3 = (uint)(local_3d == '\0') << 9 | *param_3 | 0x580;
      }
      if (param_6 != (char *)0x0) {
        if (local_3d == '\0') {
          param_6[3] = '\0';
        }
        param_6[2] = '\0';
      }
      (**(code **)(lVar8 + 0x1e8))(lVar7,lVar8,local_98,param_4,param_5,0,0);
    }
    else if (local_3c[0] == 5) {
      if (param_3 == (uint *)0x0) {
        if (param_6 == (char *)0x0) {
          return 0;
        }
        if (local_3d == '\0') {
          param_6[3] = '\0';
        }
        param_6[7] = '\0';
        if (param_2 != 1) goto LAB_0048efbf;
      }
      else {
        uVar4 = (uint)(local_3d == '\0') << 4 | (uint)(local_3e == '\0') * 2 |
                (uint)(local_3f == '\0') | *param_3;
        *param_3 = uVar4 | 0x1000;
        if (param_6 == (char *)0x0) {
          if (param_2 == 1) {
            *param_3 = uVar4 | 0x1020;
            return 0;
          }
          return 0;
        }
        if (local_3d == '\0') {
          param_6[3] = '\0';
          param_6[7] = '\0';
        }
        else {
          param_6[7] = '\0';
        }
        if (param_2 != 1) goto LAB_0048efbf;
        *param_3 = *param_3 | 0x20;
      }
      param_6[5] = '\0';
      goto LAB_0048efbf;
    }
    if (param_6 == (char *)0x0) {
      return 0;
    }
    goto LAB_0048efbf;
  }
  if (param_3 == (uint *)0x0) {
    if (param_6 == (char *)0x0) {
      return 0;
    }
    param_6[6] = '\0';
    if (local_3d == '\0') {
      param_6[3] = '\0';
    }
    if (local_3c[0] == 2) goto LAB_0048f4a9;
    param_6[4] = '\0';
    if (param_2 != 1) goto LAB_0048efbf;
  }
  else {
    uVar4 = (uint)(local_3e == '\0') * 2 | (uint)(local_3d == '\0') << 4 | (uint)(local_3f == '\0')
            | *param_3;
    if (local_3c[0] == 2) {
      *param_3 = uVar4 | 0x2040;
      if (param_6 == (char *)0x0) {
        return 0;
      }
      param_6[6] = '\0';
      if (local_3d == '\0') {
        param_6[3] = '\0';
      }
LAB_0048f4a9:
      param_6[8] = '\0';
      goto LAB_0048efbf;
    }
    *param_3 = uVar4 | 0x44;
    if (param_6 == (char *)0x0) {
      if (param_2 == 1) {
        *param_3 = uVar4 | 100;
        return 0;
      }
      return 0;
    }
    param_6[6] = '\0';
    if (local_3d == '\0') {
      param_6[3] = '\0';
      param_6[4] = '\0';
    }
    else {
      param_6[4] = '\0';
    }
    if (param_2 != 1) goto LAB_0048efbf;
    *param_3 = *param_3 | 0x20;
  }
  param_6[5] = '\0';
LAB_0048efbf:
  *param_6 = local_3e;
  param_6[1] = local_3f;
  if (*(char *)(lVar7 + 0x4a6) != '\0') {
    param_6[5] = '\x04';
    return 0;
  }
  return 0;
}


// ===== 0048f5f0 cliresCtrlCmdSystemGetFeatures_IMPL =====

undefined8 cliresCtrlCmdSystemGetFeatures_IMPL(undefined8 param_1,uint *param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  lVar1 = g_pSys;
  if (g_pSys != 0) {
    cVar2 = rmapiLockIsOwner();
    if (cVar2 == '\0') {
      nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x326);
      uVar5 = 0x2f;
    }
    else {
      cVar2 = osImexChannelIsSupported();
      uVar4 = 0;
      if (cVar2 != '\0') {
        iVar3 = osImexChannelCount();
        uVar4 = (uint)(iVar3 != 0) << 3;
      }
      if (*(char *)(lVar1 + 0x7e) != '\0') {
        uVar4 = uVar4 | 0x10;
      }
      *param_2 = uVar4;
      uVar5 = 0;
    }
    return uVar5;
  }
  nvAssertFailedNoLog("pSys != NULL","src/kernel/rmapi/client_resource.c",0x324);
  return 0x40;
}


// ===== 0048f6c0 cliresCtrlCmdSystemGetBuildVersionV2_IMPL =====

undefined8 cliresCtrlCmdSystemGetBuildVersionV2_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    portMemCopy(param_2,0x100,"595.71.05",10);
    portMemCopy(param_2 + 0x100,0x100,"rel/gpu_drv/r595/r596_25-250",0x1d);
    portMemCopy(param_2 + 0x300,0x100,"Private r596_25 rel/gpu_drv/r595/r596_25-250 unknown",0x35);
    portMemCopy(param_2 + 0x200,0x100,"r596_25",8);
    *(undefined8 *)(param_2 + 0x400) = 0x241a0ef00000000;
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x347);
  return 0x2f;
}


// ===== 0048f7a0 cliresCtrlCmdSystemExecuteAcpiMethod_IMPL =====

uint cliresCtrlCmdSystemExecuteAcpiMethod_IMPL(undefined8 param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  ushort uVar6;
  ushort local_3a [5];
  
  uVar2 = *param_2;
  lVar4 = gpumgrGetSomeGpu();
  if (lVar4 == 0) {
    return 0x3f;
  }
  local_3a[0] = (ushort)param_2[8];
  uVar1 = (ushort)param_2[4];
  if (((local_3a[0] == 0) || (*(long *)(param_2 + 2) == 0)) || (*(long *)(param_2 + 6) == 0)) {
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x385,
                 "cliresCtrlCmdSystemExecuteAcpiMethod_IMPL",3,
                 "NVRM: ERROR: NV0000_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: Parameter validation failed: outDataSize=%d  method = %ud\n"
                 ,local_3a[0],uVar2);
    return 0x1f;
  }
  uVar6 = local_3a[0];
  if (local_3a[0] < uVar1) {
    uVar6 = uVar1;
  }
  lVar5 = portMemAllocNonPaged(uVar6);
  if (lVar5 == 0) {
    uVar3 = 0x51;
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x391,
                 "cliresCtrlCmdSystemExecuteAcpiMethod_IMPL",3,
                 "NVRM: ERROR: NV0000_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: mem alloc failed\n");
    goto LAB_0048f88c;
  }
  if (uVar1 == 0) {
    if (uVar2 != 2) goto LAB_0048f837;
LAB_0048f938:
    uVar3 = osCallACPI_DSM(lVar4,7,1,lVar5,local_3a);
  }
  else {
    portMemCopy(lVar5,uVar1,*(undefined8 *)(param_2 + 2),uVar1);
    if (uVar2 == 2) goto LAB_0048f938;
LAB_0048f837:
    if (uVar2 < 3) {
      if (uVar2 == 0) {
        uVar3 = osCallACPI_DSM(lVar4,4,0x1a,lVar5,local_3a);
      }
      else {
        uVar3 = osCallACPI_DSM(lVar4,4,0x1b,lVar5,local_3a);
      }
    }
    else {
      if (uVar2 != 3) {
        uVar3 = 0x1f;
        nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x3c4,
                     "cliresCtrlCmdSystemExecuteAcpiMethod_IMPL",3,
                     "NVRM: ERROR: NV0000_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: Unrecognized Api Code: 0x%x\n"
                     ,uVar2);
        goto LAB_0048f88c;
      }
      uVar3 = osCallACPI_DSM(lVar4,7,4,lVar5,local_3a);
    }
  }
  if (uVar3 == 0) {
    if ((ushort)param_2[8] < local_3a[0]) {
      uVar3 = 2;
      nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x3e0,
                   "cliresCtrlCmdSystemExecuteAcpiMethod_IMPL",3,
                   "NVRM: ERROR: NV0000_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: output buffer is smaller then expected!\n"
                  );
    }
    else {
      *(ushort *)(param_2 + 8) = local_3a[0];
      portMemCopy(*(undefined8 *)(param_2 + 6),local_3a[0],lVar5,local_3a[0]);
    }
  }
  else {
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x3cf,
                 "cliresCtrlCmdSystemExecuteAcpiMethod_IMPL",1,
                 "NVRM: ERROR: NV0000_CTRL_CMD_SYSTEM_EXECUTE_ACPI_METHOD: Execution failed for method: 0x%x, status=0x%x\n"
                 ,uVar2,uVar3);
    param_2[5] = uVar3;
  }
LAB_0048f88c:
  portMemFree(lVar5);
  return uVar3;
}


// ===== 0048fa90 cliresCtrlCmdSystemGetCpuInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 cliresCtrlCmdSystemGetCpuInfo_IMPL(undefined8 param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  lVar3 = g_pSys;
  local_20 = 0;
  local_1c = 0;
  cVar1 = rmapiLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x40f);
    return 0x2f;
  }
  *param_2 = *(undefined4 *)(lVar3 + 0xb4);
  param_2[1] = *(undefined4 *)(lVar3 + 0xb8);
  param_2[2] = *(undefined4 *)(lVar3 + 0xc0);
  param_2[3] = *(undefined4 *)(lVar3 + 0xc4);
  param_2[4] = *(undefined4 *)(lVar3 + 200);
  param_2[5] = *(undefined4 *)(lVar3 + 0xcc);
  param_2[6] = *(undefined4 *)(lVar3 + 0xdc);
  param_2[7] = *(undefined4 *)(lVar3 + 0xd8);
  param_2[0x18] = *(undefined4 *)(lVar3 + 0x120);
  param_2[0x15] = *(undefined4 *)(lVar3 + 0x118);
  param_2[0x16] = *(undefined4 *)(lVar3 + 0x11c);
  *(undefined1 *)(param_2 + 0x17) = *(undefined1 *)(lVar3 + 0x128);
  *(undefined1 *)(param_2 + 0x19) = *(undefined1 *)(lVar3 + 0xa4);
  portMemCopy(param_2 + 8,0x34,lVar3 + 0xe4,0x34);
  param_2[0x1a] = 0;
  gpumgrGetGpuAttachInfo(0,&local_20);
  do {
    lVar3 = gpumgrGetNextGpu(local_20,&local_1c);
    if (lVar3 == 0) {
      return 0;
    }
    iVar2 = (**(code **)(lVar3 + 0x368))(lVar3);
    param_2[0x1a] = iVar2;
  } while (iVar2 == 0);
  return 0;
}


// ===== 0048fbf0 cliresCtrlCmdSystemGetChipsetInfo_IMPL =====

undefined8 cliresCtrlCmdSystemGetChipsetInfo_IMPL(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  
  lVar1 = *(long *)(g_pSys + 0x208);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    param_2[0x25] = 0;
    if (*(char *)(lVar1 + 0xcf) == '\0') {
      *param_2 = 0xffffffff;
      *(undefined2 *)(param_2 + 1) = 0xffff;
      *(undefined2 *)((long)param_2 + 6) = 0xffff;
      cVar2 = *(char *)(lVar1 + 0x9f);
    }
    else {
      *(undefined2 *)param_2 = *(undefined2 *)(lVar1 + 0xda);
      *(undefined2 *)((long)param_2 + 2) = *(undefined2 *)(lVar1 + 0xd8);
      *(undefined2 *)(param_2 + 1) = *(undefined2 *)(lVar1 + 0xde);
      *(undefined2 *)((long)param_2 + 6) = *(undefined2 *)(lVar1 + 0xdc);
      cVar2 = *(char *)(lVar1 + 0x9f);
    }
    if (cVar2 == '\0') {
      param_2[2] = 0xffffffff;
      *(undefined2 *)(param_2 + 3) = 0xffff;
      uVar3 = 0xffff;
    }
    else {
      *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 0xaa);
      *(undefined2 *)((long)param_2 + 10) = *(undefined2 *)(lVar1 + 0xa8);
      *(undefined2 *)(param_2 + 3) = *(undefined2 *)(lVar1 + 0xae);
      uVar3 = *(undefined2 *)(lVar1 + 0xac);
    }
    *(undefined2 *)((long)param_2 + 0xe) = uVar3;
    param_2[4] = *(undefined4 *)(lVar1 + 0xb8);
    csGetInfoStrings(lVar1,param_2 + 0x15,param_2 + 5,param_2 + 0x1d,param_2 + 0xd,0x20);
    uVar4 = param_2[0x25] & 0xfffffffe;
    if (*(char *)(lVar1 + 0x6b) != '\0') {
      uVar4 = param_2[0x25] | 1;
    }
    param_2[0x25] = uVar4 | 2;
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x441);
  return 0x2f;
}


// ===== 0048fd70 cliresCtrlCmdSystemGetLockTimes_IMPL =====

undefined8 cliresCtrlCmdSystemGetLockTimes_IMPL(undefined8 param_1,undefined8 param_2)

{
  if (*(char *)(g_pSys + 0x7d) != '\0') {
    rmapiLockGetTimes(param_2);
    rmGpuLockGetTimes(param_2);
    return 0;
  }
  return 0x56;
}


// ===== 0048fdc0 cliresCtrlCmdSystemGetClassList_IMPL =====

undefined8 cliresCtrlCmdSystemGetClassList_IMPL(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  ulong uVar4;
  uint local_ac;
  undefined4 *local_a8;
  uint local_9c;
  undefined4 auStack_98 [34];
  
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/rmapi/client_resource.c",0x4d7);
    return 0x2f;
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("pParams","src/kernel/rmapi/client_resource.c",0x4ae);
    return 0x1f;
  }
  RsResInfoGetResourceList(&local_a8,&local_ac);
  portMemSet(&local_9c,0,0x84);
  if (local_ac != 0) {
    puVar3 = local_a8 + (ulong)local_ac * 0xe;
    do {
      while ((**(int **)(local_a8 + 6) != 0x37a701 || ((*(int **)(local_a8 + 6))[1] != 0))) {
        local_a8 = local_a8 + 0xe;
        if (local_a8 == puVar3) goto LAB_0048fe88;
      }
      if (0x1f < local_9c) {
        nvAssertFailedNoLog("params.numClasses < NV0000_CTRL_SYSTEM_MAX_CLASSLIST_SIZE",
                            "src/kernel/rmapi/client_resource.c",0x4b9);
        return 0x40;
      }
      uVar1 = *local_a8;
      uVar4 = (ulong)local_9c;
      local_a8 = local_a8 + 0xe;
      local_9c = local_9c + 1;
      auStack_98[uVar4] = uVar1;
    } while (local_a8 != puVar3);
  }
LAB_0048fe88:
  portMemCopy(param_2,0x84,&local_9c,0x84);
  return 0;
}


// ===== 0048ff20 cliresCtrlCmdSystemNotifyEvent_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int cliresCtrlCmdSystemNotifyEvent_IMPL(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  int iVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c [3];
  
  uVar1 = *param_2;
  if (uVar1 == 1) {
    local_28 = 0;
    local_24 = 0;
    local_1c[0] = (uint)(param_2[1] == 0);
    local_20 = 0;
    gpumgrGetGpuAttachInfo(&local_20,&local_28);
    do {
      lVar4 = gpumgrGetNextGpu(local_28,&local_24);
      if (lVar4 == 0) {
        iVar5 = 0;
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
        gpumgrGetGpuAttachInfo(&local_20,&local_28);
        lVar4 = gpumgrGetNextGpu(local_28,&local_24);
        if (lVar4 == 0) {
          return 0;
        }
        do {
          lVar2 = *(long *)(lVar4 + 0x1c10);
          if ((lVar2 != 0) &&
             (iVar5 = (**(code **)(lVar2 + 0x170))(lVar4,lVar2,local_1c), iVar5 != 0)) {
            nvCheckOkFailedNoLog
                      (4,iVar5,"kperfPerfSetPowerstate(pGpu, pKernelPerf, &params)",
                       "src/kernel/rmapi/client_resource.c",0x52e);
          }
          lVar4 = gpumgrGetNextGpu(local_28,&local_24);
        } while (lVar4 != 0);
        return iVar5;
      }
      cVar3 = gpuIsGpuFullPower_IMPL(lVar4);
    } while (cVar3 != '\0');
    iVar5 = 0x11;
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x51a,"cliresCtrlCmdSystemNotifyEvent_IMPL",3,
                 "NVRM: NV0000_CTRL_SYSTEM_EVENT_TYPE_POWER_SOURCE called in power down state.\n");
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x51c,"cliresCtrlCmdSystemNotifyEvent_IMPL",3,
                 "NVRM:       Returning NV_ERR_GPU_NOT_FULL_POWER.\n");
  }
  else {
    iVar5 = 0x56;
    if (1 < uVar1) {
      iVar5 = (-(uint)(uVar1 - 2 < 3) & 0x37) + 0x1f;
    }
  }
  return iVar5;
}


// ===== 004900b0 cliresCtrlCmdSystemGetPlatformType_IMPL =====

undefined8 cliresCtrlCmdSystemGetPlatformType_IMPL(undefined8 param_1,uint *param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(g_pSys + 0x210);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    if (*(char *)(lVar1 + 0x4a) == '\0') {
      *param_2 = (uint)(*(char *)(lVar1 + 0x49) != '\0');
    }
    else {
      *param_2 = 2;
    }
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x550);
  return 0x2f;
}


// ===== 00490122 cliresCtrlCmdSystemDebugCtrlRmMsg_IMPL.cold =====

void cliresCtrlCmdSystemDebugCtrlRmMsg_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00490130 cliresCtrlCmdSystemDebugCtrlRmMsg_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 cliresCtrlCmdSystemDebugCtrlRmMsg_IMPL(long param_1,int *param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined4 uVar6;
  
  if (*param_2 == 0) {
    iVar3 = portStringLength(&RmMsg);
    portMemCopy(param_2 + 2,iVar3,&RmMsg,iVar3);
    param_2[1] = iVar3;
    return 0;
  }
  if (*param_2 == 1) {
    if (param_1 != 0) {
      plVar4 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48),
                                          __nvoc_class_def_RmClient);
      lVar5 = resservGetTlsCallContext();
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pCallContext != NULL","src/kernel/rmapi/client_resource.c",0x57e);
        uVar6 = 0x40;
      }
      else if (plVar4 == (long *)0x0) {
        nvAssertFailedNoLog("pRmClient != NULL","src/kernel/rmapi/client_resource.c",0x57f);
        uVar6 = 0x23;
      }
      else {
        cVar2 = (**(code **)(*plVar4 + 0xe0))(plVar4,*(undefined4 *)(lVar5 + 0x28));
        if (cVar2 == '\0') {
          nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x583,
                       "cliresCtrlCmdSystemDebugCtrlRmMsg_IMPL",3,
                       "NVRM: Non-privileged context issued privileged cmd\n");
          uVar6 = 0x1b;
        }
        else {
          portMemCopy(&RmMsg,0x200,param_2 + 2,0x200);
          uVar6 = 0;
        }
      }
      return uVar6;
    }
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  return 0x1f;
}


// ===== 004902a0 cliresCtrlCmdSystemGetRmInstanceId_IMPL =====

undefined8 cliresCtrlCmdSystemGetRmInstanceId_IMPL(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(g_pSys + 0x170);
  return 0;
}


// ===== 004902c0 cliresCtrlCmdGpuGetAttachedIds_IMPL =====

undefined8 cliresCtrlCmdGpuGetAttachedIds_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrGetAttachedGpuIds(param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x5b0);
  return 0x2f;
}


// ===== 00490320 cliresCtrlCmdGpuGetIdInfo_IMPL =====

undefined8 cliresCtrlCmdGpuGetIdInfo_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrGetGpuIdInfo(param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x5c2);
  return 0x2f;
}


// ===== 00490380 cliresCtrlCmdGpuGetIdInfoV2_IMPL =====

undefined8 cliresCtrlCmdGpuGetIdInfoV2_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrGetGpuIdInfoV2(param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x5ce);
  return 0x2f;
}


// ===== 004903e0 cliresCtrlCmdGpuGetInitStatus_IMPL =====

undefined8 cliresCtrlCmdGpuGetInitStatus_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrGetGpuInitStatus(param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x5e1);
  return 0x2f;
}


// ===== 00490440 cliresCtrlCmdGpuGetDeviceIds_IMPL =====

undefined8 cliresCtrlCmdGpuGetDeviceIds_IMPL(undefined8 param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrGetDeviceInstanceMask();
    *param_2 = uVar2;
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x5f4);
  return 0x2f;
}


// ===== 004904a0 cliresCtrlCmdGpuGetActiveDeviceIds_IMPL =====

undefined8 cliresCtrlCmdGpuGetActiveDeviceIds_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrCacheGetActiveDeviceIds_IMPL(param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x609);
  return 0x2f;
}


// ===== 00490500 cliresCtrlCmdGpuGetPciInfo_IMPL =====

int cliresCtrlCmdGpuGetPciInfo_IMPL(undefined8 param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 local_20 [16];
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x61f);
  }
  iVar2 = gpumgrGetProbedGpuDomainBusDevice(*param_2,local_20);
  if (iVar2 == 0) {
    param_2[1] = SUB84(local_20._0_8_,4);
    *(ushort *)((long)param_2 + 10) = (ushort)local_20._0_8_ & 0xff;
    *(ushort *)(param_2 + 2) = SUB82(local_20._0_8_,1) & 0xff;
  }
  return iVar2;
}


// ===== 00490580 cliresCtrlCmdGpuGetProbedIds_IMPL =====

undefined8 cliresCtrlCmdGpuGetProbedIds_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrGetProbedGpuIds(param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x63a);
  return 0x2f;
}


// ===== 004905e0 cliresCtrlCmdGpuAttachIds_IMPL =====

int cliresCtrlCmdGpuAttachIds_IMPL(undefined8 param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x66b);
    return 0x2f;
  }
  if (*param_2 == 0xffff) {
    iVar3 = 0;
    piVar4 = (int *)0x0;
  }
  else {
    iVar3 = 0x51;
    piVar4 = (int *)portMemAllocNonPaged(0x180);
    if ((piVar4 != (int *)0x0) && (iVar3 = gpumgrGetProbedGpuIds(piVar4), iVar3 == 0)) {
      piVar1 = param_2 + 0x20;
      do {
        piVar5 = piVar4;
        if (*param_2 == -1) break;
LAB_0049066d:
        if (*piVar5 == -1) goto LAB_00490674;
        if (*param_2 != *piVar5) goto code_r0x00490664;
        param_2 = param_2 + 1;
      } while (param_2 != piVar1);
    }
  }
LAB_0049067a:
  portMemFree(piVar4);
  return iVar3;
code_r0x00490664:
  piVar5 = piVar5 + 1;
  if (piVar5 == piVar4 + 0x20) {
LAB_00490674:
    iVar3 = 0x1f;
    goto LAB_0049067a;
  }
  goto LAB_0049066d;
}


// ===== 004906e0 cliresCtrlCmdGpuAsyncAttachId_IMPL =====

int cliresCtrlCmdGpuAsyncAttachId_IMPL(undefined8 param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x6a6);
    return 0x2f;
  }
  iVar3 = 0x51;
  piVar4 = (int *)portMemAllocNonPaged(0x180);
  if (piVar4 != (int *)0x0) {
    iVar3 = gpumgrGetProbedGpuIds(piVar4);
    if (iVar3 == 0) {
      piVar1 = piVar4 + 0x20;
      do {
        if (*piVar4 == -1) break;
        if (*param_2 == *piVar4) goto LAB_00490751;
        piVar4 = piVar4 + 1;
      } while (piVar4 != piVar1);
      iVar3 = 0x1f;
    }
  }
LAB_00490751:
  portMemFree();
  return iVar3;
}


// ===== 00490790 cliresCtrlCmdGpuWaitAttachId_IMPL =====

undefined8 cliresCtrlCmdGpuWaitAttachId_IMPL(void)

{
  return 0;
}


// ===== 004907a0 cliresCtrlCmdGpuDetachIds_IMPL =====

int cliresCtrlCmdGpuDetachIds_IMPL(undefined8 param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x6ef);
    return 0x2f;
  }
  if (*param_2 == 0xffff) {
    iVar3 = 0;
    lVar4 = 0;
  }
  else {
    iVar3 = 0x51;
    lVar4 = portMemAllocNonPaged(0x80);
    if ((lVar4 != 0) && (iVar3 = gpumgrGetAttachedGpuIds(lVar4), iVar3 == 0)) {
      uVar5 = 0;
      if (*param_2 != -1) {
        do {
          iVar1 = *(int *)(lVar4 + uVar5 * 4);
          if ((iVar1 == -1) || (iVar1 == *param_2)) {
            if (*(int *)(lVar4 + (uVar5 & 0xffffffff) * 4) == -1) {
              iVar3 = 0x1f;
            }
            goto LAB_004907fe;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 != 0x20);
        iVar3 = 0x1f;
      }
    }
  }
LAB_004907fe:
  portMemFree(lVar4);
  return iVar3;
}


// ===== 00490890 cliresCtrlCmdGsyncGetAttachedIds_IMPL =====

void cliresCtrlCmdGsyncGetAttachedIds_IMPL(undefined8 param_1,undefined8 param_2)

{
  gsyncGetAttachedIds(param_2);
  return;
}


// ===== 004908a0 cliresCtrlCmdGsyncGetIdInfo_IMPL =====

void cliresCtrlCmdGsyncGetIdInfo_IMPL(undefined8 param_1,undefined8 param_2)

{
  gsyncGetIdInfo(param_2);
  return;
}


// ===== 004908ac cliresCtrlCmdEventSetNotification_IMPL.cold =====

void cliresCtrlCmdEventSetNotification_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004908c0 cliresCtrlCmdEventSetNotification_IMPL =====

undefined8 cliresCtrlCmdEventSetNotification_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  code *pcVar4;
  long lVar5;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  uVar1 = *param_2;
  uVar2 = param_2[1];
  local_20 = 0;
  uVar3 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48);
  if (3 < uVar1) {
    return 0x1f;
  }
  lVar5 = serverutilGetClientUnderLock();
  if (lVar5 == 0) {
    return 0x23;
  }
  CliGetEventNotificationList(uVar3,uVar3,0,&local_20);
  if (local_20 != 0) {
    if (uVar2 != 0) {
      if (1 < uVar2 - 1) {
        return 0x1f;
      }
      if (*(int *)(lVar5 + 0x230 + (ulong)uVar1 * 4) != 0) {
        return 0x40;
      }
    }
    *(uint *)(lVar5 + 0x230 + (ulong)uVar1 * 4) = uVar2;
    return 0;
  }
  return 0x40;
}


// ===== 0049098e cliresCtrlCmdEventGetSystemEventData_IMPL.cold =====

void cliresCtrlCmdEventGetSystemEventData_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004909a0 cliresCtrlCmdEventGetSystemEventData_IMPL =====

undefined8 cliresCtrlCmdEventGetSystemEventData_IMPL(long param_1,undefined8 param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar2 = serverutilGetClientUnderLock
                    (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48));
  if (lVar2 != 0) {
    uVar3 = eventSystemDequeueEvent(lVar2 + 0x208,param_2);
    return uVar3;
  }
  return 0x23;
}


// ===== 004909f0 lookupPid =====

int lookupPid(int param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  int local_2c [3];
  
  plVar4 = (long *)serverutilGetFirstClientUnderLock();
  while( true ) {
    if (plVar4 == (long *)0x0) {
      return param_1;
    }
    lVar1 = *plVar4;
    lVar2 = *(long *)(lVar1 + 0x198);
    if (((lVar2 != 0) && (iVar3 = osFindNsPid(lVar2,local_2c), iVar3 == 0)) &&
       (local_2c[0] == param_1)) break;
    plVar4 = (long *)serverutilGetNextClientUnderLock(plVar4);
  }
  return *(int *)(lVar1 + 0x118);
}


// ===== 00490a80 cliresCtrlCmdGpuAcctGetProcAccountingInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresCtrlCmdGpuAcctGetProcAccountingInfo_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  
  uVar5 = *(undefined8 *)(g_pSys + 0x218);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x77b);
    return 0x2f;
  }
  lVar4 = gpumgrGetGpuFromId(*param_2);
  if (lVar4 == 0) {
    uVar5 = 0x1f;
  }
  else {
    if (param_2[2] == 0) {
      uVar3 = lookupPid(param_2[1]);
      param_2[1] = uVar3;
      cVar2 = *(char *)(lVar4 + 0x908);
    }
    else {
      cVar2 = *(char *)(lVar4 + 0x908);
    }
    if (cVar2 == '\0') {
      if (((*(char *)(lVar4 + 0x909) != '\0') && (*(char *)(lVar4 + 0x4a4e) != '\0')) &&
         (param_2[2] != 0)) {
        lVar6 = resservGetTlsCallContext();
        puVar1 = *(undefined4 **)(lVar6 + 0x48);
        uVar5 = (**(code **)(lVar4 + 0x3b90))
                          (lVar4 + 0x3b58,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                           puVar1[6]);
        return uVar5;
      }
      uVar5 = gpuacctGetProcAcctInfo_IMPL(uVar5,param_2);
      return uVar5;
    }
    lVar6 = resservGetTlsCallContext();
    puVar1 = *(undefined4 **)(*(long *)(lVar6 + 0x48) + 0x70);
    lVar6 = gpuGetRpc(lVar4);
    uVar5 = 0;
    if (lVar6 != 0) {
      uVar5 = (**(code **)(lVar6 + 0x288))(lVar4,lVar6,*puVar1,puVar1[1],puVar1[2],param_2,0x30);
    }
  }
  return uVar5;
}


// ===== 00490c10 cliresCtrlCmdGpuAcctSetAccountingState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresCtrlCmdGpuAcctSetAccountingState_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x7b4);
    return 0x2f;
  }
  lVar3 = gpumgrGetGpuFromId(*param_2);
  if (lVar3 != 0) {
    if (*(char *)(lVar3 + 0x908) != '\0') {
      lVar4 = resservGetTlsCallContext();
      puVar1 = *(undefined4 **)(*(long *)(lVar4 + 0x48) + 0x70);
      lVar4 = gpuGetRpc(lVar3);
      if (lVar4 == 0) {
        return 0;
      }
      uVar6 = (**(code **)(lVar4 + 0x288))(lVar3,lVar4,*puVar1,puVar1[1],puVar1[2],param_2,0xc);
      return uVar6;
    }
    uVar6 = *(undefined8 *)(g_pSys + 0x218);
    if (*(char *)(lVar3 + 0x909) != '\0') {
      lVar4 = resservGetTlsCallContext();
      puVar1 = *(undefined4 **)(lVar4 + 0x48);
      uVar5 = (**(code **)(lVar3 + 0x3b90))
                        (lVar3 + 0x3b58,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                         puVar1[6]);
      if ((int)uVar5 != 0) {
        return uVar5;
      }
    }
    if (param_2[2] == 0) {
      uVar6 = gpuacctEnableAccounting_IMPL(uVar6,*(undefined4 *)(lVar3 + 0x7a4),param_2);
      return uVar6;
    }
    if (param_2[2] == 1) {
      uVar6 = gpuacctDisableAccounting_IMPL(uVar6,*(undefined4 *)(lVar3 + 0x7a4),param_2);
      return uVar6;
    }
  }
  return 0x1f;
}


// ===== 00490da0 cliresCtrlCmdGpuAcctClearAccountingData_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresCtrlCmdGpuAcctClearAccountingData_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 *local_20 [2];
  
  uVar4 = *(undefined8 *)(g_pSys + 0x218);
  local_20[0] = param_2;
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x7ff);
    return 0x2f;
  }
  lVar3 = gpumgrGetGpuFromId(*local_20[0]);
  if (lVar3 == 0) {
    uVar4 = 0x1f;
  }
  else if (*(char *)(lVar3 + 0x908) == '\0') {
    if (((*(char *)(lVar3 + 0x909) == '\0') || (*(char *)(lVar3 + 0x4a4e) == '\0')) ||
       (local_20[0][1] == 0)) {
      uVar4 = gpuacctClearAccountingData_IMPL(uVar4,*(undefined4 *)(lVar3 + 0x7a4));
    }
    else {
      lVar5 = resservGetTlsCallContext();
      puVar1 = *(undefined4 **)(lVar5 + 0x48);
      uVar4 = (**(code **)(lVar3 + 0x3b90))
                        (lVar3 + 0x3b58,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                         puVar1[6]);
    }
  }
  else {
    lVar5 = resservGetTlsCallContext();
    puVar1 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
    lVar5 = gpuGetRpc(lVar3);
    uVar4 = 0;
    if (lVar5 != 0) {
      uVar4 = (**(code **)(lVar5 + 0x288))(lVar3,lVar5,*puVar1,puVar1[1],puVar1[2],local_20,8);
      return uVar4;
    }
  }
  return uVar4;
}


// ===== 00490f00 cliresCtrlCmdGpuAcctGetAccountingState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresCtrlCmdGpuAcctGetAccountingState_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar4 = *(undefined8 *)(g_pSys + 0x218);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x835);
    return 0x2f;
  }
  lVar3 = gpumgrGetGpuFromId(*param_2);
  if (lVar3 == 0) {
    uVar4 = 0x1f;
  }
  else {
    if (*(char *)(lVar3 + 0x908) == '\0') {
      if (((*(char *)(lVar3 + 0x909) != '\0') && (*(char *)(lVar3 + 0x4a4e) != '\0')) &&
         (param_2[1] != 0)) {
        lVar5 = resservGetTlsCallContext();
        puVar1 = *(undefined4 **)(lVar5 + 0x48);
        uVar4 = (**(code **)(lVar3 + 0x3b90))
                          (lVar3 + 0x3b58,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                           puVar1[6]);
        return uVar4;
      }
      uVar4 = gpuacctGetAccountingMode_IMPL(uVar4,*(undefined4 *)(lVar3 + 0x7a4),param_2);
      return uVar4;
    }
    lVar5 = resservGetTlsCallContext();
    puVar1 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
    lVar5 = gpuGetRpc(lVar3);
    uVar4 = 0;
    if (lVar5 != 0) {
      uVar4 = (**(code **)(lVar5 + 0x288))(lVar3,lVar5,*puVar1,puVar1[1],puVar1[2],param_2,0xc);
    }
  }
  return uVar4;
}


// ===== 00491060 cliresCtrlCmdGpuAcctGetAccountingPids_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresCtrlCmdGpuAcctGetAccountingPids_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar4 = *(undefined8 *)(g_pSys + 0x218);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x86b);
    return 0x2f;
  }
  lVar3 = gpumgrGetGpuFromId(*param_2);
  if (lVar3 == 0) {
    uVar4 = 0x1f;
  }
  else {
    if (*(char *)(lVar3 + 0x908) == '\0') {
      if (((*(char *)(lVar3 + 0x909) != '\0') && (*(char *)(lVar3 + 0x4a4e) != '\0')) &&
         (param_2[1] != 0)) {
        lVar5 = resservGetTlsCallContext();
        puVar1 = *(undefined4 **)(lVar5 + 0x48);
        uVar4 = (**(code **)(lVar3 + 0x3b90))
                          (lVar3 + 0x3b58,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                           puVar1[6]);
        return uVar4;
      }
      uVar4 = gpuacctGetAcctPids_IMPL(uVar4,param_2);
      return uVar4;
    }
    lVar5 = resservGetTlsCallContext();
    puVar1 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
    lVar5 = gpuGetRpc(lVar3);
    uVar4 = 0;
    if (lVar5 != 0) {
      uVar4 = (**(code **)(lVar5 + 0x288))(lVar3,lVar5,*puVar1,puVar1[1],puVar1[2],param_2,0x3e8c);
    }
  }
  return uVar4;
}


// ===== 004911c0 cliresCtrlCmdSystemPfmreqhndlrControl_IMPL =====

undefined8 cliresCtrlCmdSystemPfmreqhndlrControl_IMPL(undefined8 param_1,undefined2 *param_2)

{
  undefined8 uVar1;
  undefined4 local_1c [3];
  
  if (g_pSys == 0) {
    return 0x3f;
  }
  local_1c[0] = *(undefined4 *)(param_2 + 2);
  if (*(long *)(g_pSys + 0x220) != 0) {
    uVar1 = pfmreqhndlrControl_IMPL(*(long *)(g_pSys + 0x220),*param_2,param_2[1],local_1c);
    if ((int)uVar1 == 0) {
      *(undefined4 *)(param_2 + 2) = local_1c[0];
      return uVar1;
    }
    *(undefined4 *)(param_2 + 2) = 0x80000000;
    return uVar1;
  }
  return 0x3f;
}


// ===== 00491240 cliresCtrlCmdSystemPfmreqhndlrBatchControl_IMPL =====

undefined8 cliresCtrlCmdSystemPfmreqhndlrBatchControl_IMPL(undefined8 param_1,uint *param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  uint local_3c [3];
  
  local_3c[0] = 0;
  if (*param_2 < 0x11) {
    if (g_pSys == 0) {
      nvAssertFailedNoLog(&DAT_00d8eb44,"src/kernel/rmapi/client_resource.c",0x8d0);
    }
    else {
      lVar1 = *(long *)(g_pSys + 0x220);
      if (lVar1 != 0) {
        uVar5 = 0;
        if (*param_2 != 0) {
          uVar5 = 0;
          uVar4 = 0;
          do {
            local_3c[0] = param_2[uVar4 * 2 + 3];
            iVar2 = pfmreqhndlrControl_IMPL
                              (lVar1,(short)param_2[uVar4 * 2 + 2],
                               *(undefined2 *)((long)param_2 + uVar4 * 8 + 10),local_3c);
            uVar3 = 0x80000000;
            if (iVar2 == 0) {
              uVar5 = uVar5 + 1;
              uVar3 = local_3c[0];
            }
            param_2[uVar4 * 2 + 3] = uVar3;
            uVar3 = (int)uVar4 + 1;
            uVar4 = (ulong)uVar3;
          } while (uVar3 < *param_2);
        }
        param_2[1] = uVar5;
        return 0;
      }
      nvAssertFailedNoLog("pPlatformRequestHandler","src/kernel/rmapi/client_resource.c",0x8d7);
    }
  }
  return 0x3f;
}


// ===== 00491360 cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL =====

undefined4 cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL(undefined8 param_1,byte *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  char *pcVar7;
  byte *pbVar8;
  char cVar9;
  uint uVar10;
  ulong uVar11;
  uint uVar12;
  byte *pbVar13;
  undefined8 uVar14;
  char *pcVar15;
  uint uVar16;
  byte bVar17;
  int iVar18;
  undefined4 uVar19;
  undefined4 local_1a8;
  int local_1a4;
  undefined8 local_1a0;
  int local_198;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  int local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined4 local_158;
  undefined8 local_150;
  undefined8 local_148;
  int local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined4 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108 [27];
  
  if (param_2 == (byte *)0x0) {
    return 0x3f;
  }
  lVar5 = gpumgrGetGpuFromId(*(undefined4 *)(param_2 + 4));
  if (lVar5 == 0) {
    nvAssertFailedNoLog(&DAT_00d8eb61,"src/kernel/rmapi/client_resource.c",0xb5f);
    return 0x3f;
  }
  uVar3 = *(uint *)(param_2 + 0x10);
  if (uVar3 != 4) {
    if (uVar3 < 5) {
      if (uVar3 != 2) {
        if (uVar3 != 3) goto LAB_00491ca0;
        uVar3 = 0;
        local_190._5_3_ = (undefined3)((ulong)local_190 >> 0x28);
        local_190._0_5_ = 0;
        local_168 = 0;
        local_160 = 0;
        do {
          uVar11 = (ulong)uVar3;
          uVar3 = uVar3 + 0x20;
          *(undefined8 *)((long)&local_118 + uVar11) = 0;
          *(undefined8 *)((long)&local_110 + uVar11) = 0;
          *(undefined8 *)((long)local_108 + uVar11) = 0;
          *(undefined8 *)((long)local_108 + uVar11 + 8) = 0;
        } while (uVar3 < 0xe0);
        uVar19 = 0x51;
        local_1a0 = CONCAT62(local_1a0._2_6_,0xf5);
        lVar6 = portMemAllocNonPaged(0xf5);
        if (lVar6 != 0) {
          portMemSet(&local_190,0,5);
          bVar17 = param_2[0x4a];
          local_168 = local_168 & 0xfffffffffffffffc;
          local_190._0_5_ = CONCAT41(0x1c1005,bVar17);
          portMemCopy(lVar6,5,&local_190,5);
          portMemCopy(lVar6 + 5,0x10,&local_168,0x10);
          portMemCopy(lVar6 + 0x15,0xe0,&local_118,0xe0);
          iVar2 = osCallACPI_DSM(lVar5,9,2,lVar6,&local_1a0);
          if (iVar2 == 0) {
            if (0x14 < (ushort)local_1a0) {
              local_150 = 0;
              local_148 = 0;
              local_180 = 0;
              local_178 = 0;
              local_170 = 0;
              configReadStructure(lVar6,&local_180,0,&DAT_00d8eb66);
              iVar2 = local_170;
              if ((((param_2[0x4a] == (uint)local_180) && (local_180._4_4_ == 5)) &&
                  ((int)local_178 == 0x10)) &&
                 ((local_178._4_4_ == 0x1c && (local_170 * 0x1c + 0x15U <= (uint)(ushort)local_1a0))
                 )) {
                configReadStructure(lVar6,&local_150,5,&DAT_00d8eb69);
                if (iVar2 == 0) {
                  uVar19 = 0;
                }
                else {
                  iVar4 = (int)(short)local_150;
                  local_120 = 0;
                  local_128 = 0;
                  local_130 = 0;
                  local_138 = 0;
                  iVar18 = 0;
                  do {
                    configReadStructure(lVar6,&local_138,iVar18 * 0x1c + 0x15,&DAT_00d8eb6c);
                    param_2[0x2c] = 0x80;
                    param_2[0x2d] = 0x96;
                    param_2[0x2e] = 0x98;
                    param_2[0x2f] = 0;
                    param_2[0x30] = 0;
                    param_2[0x31] = 0;
                    param_2[0x32] = 0;
                    param_2[0x33] = 0;
                    *(int *)(param_2 + 0x14) = iVar4 * 0x7d;
                    param_2[0x49] = (byte)((uint)local_138 >> 9) & 1 ^ 1;
                    param_2[0x48] = (byte)(local_138 >> 8) & 1 ^ 1;
                    *(int *)(param_2 + 0x18) = (short)(local_138 >> 0x20) * 0x7d;
                    *(int *)(param_2 + 0x1c) = (short)local_130 * 0x7d;
                    *(int *)(param_2 + 0x20) = local_130._4_2_ * 0x7d;
                    if (bVar17 < 0x22) {
                      *(int *)(param_2 + 0x24) = local_168._2_2_ * 0x7d;
                      *(int *)(param_2 + 0x28) = (local_138._4_4_ >> 0x10) * 0x7d;
                    }
                    else if ((bVar17 != 0x22) &&
                            (*(int *)(param_2 + 0x34) = (int)local_128, bVar17 != 0x23)) {
                      *(undefined4 *)(param_2 + 0x44) = local_120;
                      *(int *)(param_2 + 0x3c) = (int)((ulong)local_128 >> 0x20);
                    }
                    iVar18 = iVar18 + 1;
                  } while (iVar18 != iVar2);
                  uVar19 = 0;
                }
                goto LAB_00491ece;
              }
            }
            uVar19 = 0x25;
          }
          else {
            uVar19 = 0x56;
            nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xbb3,
                         "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",3,
                         "NVRM: Unable to retrieve NVPCF dynamic data. Possibly not supported by SBIOSrc = %x\n"
                         ,iVar2);
          }
        }
LAB_00491ece:
        portMemFree(lVar6);
        return uVar19;
      }
      local_118 = CONCAT62(local_118._2_6_,4);
      iVar2 = osCallACPI_DSM(lVar5,9,0,param_2,&local_118);
      if (iVar2 == 0) {
        if (((*param_2 & 1) != 0) && ((short)local_118 == 4)) {
          return 0;
        }
        nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xb7a,
                     "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",3,
                     "NVRM:  NVPCF FUNC_GET_SUPPORTED is not supportedrc = %x\n",0);
        return 0x56;
      }
      pcVar15 = 
      "NVRM: Unable to retrieve NVPCF supported functions. Possibly not supported by SBIOS rc = %x\n"
      ;
      uVar14 = 0xb6f;
    }
    else {
      if (uVar3 == 5) {
        local_180 = CONCAT62(local_180._2_6_,0x8c);
        lVar6 = portMemAllocNonPaged(0x8c);
        if (lVar6 == 0) {
          uVar19 = 0x51;
          nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xc78,
                       "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                       "NVRM: ERROR: NVPCF0100_CTRL_CONFIG_DSM_2X_FUNC_GET_DC_SYSTEM_POWER_LIMITS_CASE: mem alloc failed\n"
                      );
        }
        else {
          iVar2 = osCallACPI_DSM(lVar5,9,8,lVar6,&local_180);
          if (iVar2 == 0) {
            configReadStructure(lVar6,&local_150,0,&DAT_00d8eb72);
            param_2[0x368] = 1;
            param_2[0x369] = 0;
            param_2[0x36a] = 0;
            param_2[0x36b] = 0;
            param_2[0x365] = (byte)(uint)local_150;
            param_2[0x364] = 0x1f < (uint)local_150;
            uVar19 = 0;
            if ((uint)local_150 == 0x10) {
              local_138 = local_138 & 0xffffffff;
              configReadStructure(lVar6,&local_138,0,&DAT_00d8eb87);
              iVar2 = local_138._4_4_;
              if (local_138._4_4_ == 4) {
                configReadStructure(lVar6,&local_138,0,&DAT_00d8eb75);
                uVar11 = local_130;
                if ((int)local_130 == 0x11) {
                  uVar3 = local_130._4_4_;
                  if (local_130._4_4_ - 1 < 8) {
                    pbVar8 = param_2 + 100;
                    iVar2 = local_130._4_4_ * 0x11 + local_138._4_4_;
                    pbVar13 = pbVar8;
                    iVar4 = local_138._4_4_;
                    do {
                      iVar18 = iVar4 + 0x11;
                      local_168 = 0;
                      local_160 = 0;
                      local_158 = 0;
                      configReadStructure(lVar6,&local_168,iVar4,&DAT_00d8ec21);
                      pbVar13[0x14] = 0;
                      pbVar13[0x15] = 0;
                      pbVar13[0x16] = 0;
                      pbVar13[0x17] = 0;
                      *pbVar13 = (byte)local_168;
                      *(undefined4 *)(pbVar13 + 4) = local_168._4_4_;
                      *(undefined4 *)(pbVar13 + 8) = (undefined4)local_160;
                      *(undefined4 *)(pbVar13 + 0xc) = local_160._4_4_;
                      *(undefined4 *)(pbVar13 + 0x10) = local_158;
                      pbVar13 = pbVar13 + 0x18;
                      iVar4 = iVar18;
                    } while (iVar2 != iVar18);
                    *(uint *)(param_2 + 0x60) = uVar3;
                    if (param_2[100] == 100) {
                      uVar12 = 1;
                      bVar17 = 100;
                      uVar10 = 0;
                      if (uVar3 != 1) {
                        do {
                          uVar16 = uVar12;
                          pbVar13 = pbVar8 + 0x18;
                          pbVar8 = pbVar8 + 0x18;
                          if (bVar17 <= *pbVar13) {
                            nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xcf1,
                                         "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                         "NVRM: limit[%d] has threshold not strictly smaller than limit[%d] \n"
                                         ,uVar16,uVar10);
                            nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xcf2,
                                         "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                         "NVRM: %d >= %d \n",param_2[(ulong)uVar16 * 0x18 + 100],
                                         bVar17);
                            goto LAB_0049220a;
                          }
                          uVar12 = uVar16 + 1;
                          bVar17 = *pbVar13;
                          uVar10 = uVar16;
                        } while (uVar3 != uVar16 + 1);
                      }
                      goto LAB_00491e6b;
                    }
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xce8,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: Invalid threshold for entry 0. Must be 100 percent \n");
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xce9,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: threshold = %d \n",param_2[100]);
                  }
                  else {
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xcc0,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: Invalid Entry Count.\n");
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xcc1,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: entryCount = %d\n",uVar3);
                  }
                }
                else {
                  nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xcb6,
                               "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                               "NVRM: Invalid Entry Size.\n");
                  nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xcb7,
                               "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                               "NVRM: entrySize = %d\n",uVar11 & 0xffffffff);
                }
              }
              else {
                nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xca5,
                             "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                             "NVRM: Invalid Header Size.\n");
                nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xca6,
                             "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                             "NVRM: headerSize = %d\n",iVar2);
              }
            }
            else {
              if ((uint)local_150 != 0x20) goto LAB_00491e6b;
              local_118 = local_118 & 0xffffffff;
              configReadStructure(lVar6,&local_118,0,&DAT_00d8eb87);
              iVar2 = local_118._4_4_;
              if (local_118._4_4_ == 4) {
                configReadStructure(lVar6,&local_118,0,&DAT_00d8eb75);
                if ((int)local_110 == 9) {
                  if (local_110._4_4_ - 1 < 8) {
                    pbVar8 = param_2 + 100;
                    iVar2 = local_110._4_4_ * 9 + local_118._4_4_;
                    pbVar13 = pbVar8;
                    iVar4 = local_118._4_4_;
                    do {
                      local_138 = 0;
                      iVar18 = iVar4 + 9;
                      local_130 = local_130 & 0xffffffff00000000;
                      configReadStructure(lVar6,&local_138,iVar4,&DAT_00d8ec65);
                      pbVar13[8] = 0;
                      pbVar13[9] = 0;
                      pbVar13[10] = 0;
                      pbVar13[0xb] = 0;
                      pbVar13[0xc] = 0;
                      pbVar13[0xd] = 0;
                      pbVar13[0xe] = 0;
                      pbVar13[0xf] = 0;
                      *pbVar13 = (byte)local_138;
                      pbVar13[0x10] = 0xff;
                      pbVar13[0x11] = 0xff;
                      pbVar13[0x12] = 0xff;
                      pbVar13[0x13] = 0xff;
                      *(int *)(pbVar13 + 4) = local_138._4_4_;
                      *(int *)(pbVar13 + 0x14) = (int)local_130;
                      pbVar13 = pbVar13 + 0x18;
                      iVar4 = iVar18;
                    } while (iVar18 != iVar2);
                    *(uint *)(param_2 + 0x60) = local_110._4_4_;
                    if (param_2[100] == 100) {
                      uVar3 = 1;
                      bVar17 = 100;
                      uVar12 = 0;
                      if (local_110._4_4_ != 1) {
                        do {
                          uVar10 = uVar3;
                          pbVar13 = pbVar8 + 0x18;
                          pbVar8 = pbVar8 + 0x18;
                          if (bVar17 <= *pbVar13) {
                            nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd51,
                                         "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                         "NVRM: limit[%d] has threshold not strictly smaller than limit[%d] \n"
                                         ,uVar10,uVar12);
                            nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd52,
                                         "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                         "NVRM: %d >= %d \n",param_2[(ulong)uVar10 * 0x18 + 100],
                                         bVar17);
                            goto LAB_0049220a;
                          }
                          uVar3 = uVar10 + 1;
                          bVar17 = *pbVar13;
                          uVar12 = uVar10;
                        } while (local_110._4_4_ != uVar10 + 1);
                      }
                      goto LAB_00491e6b;
                    }
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd48,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: Invalid threshold for entry 0. Must be 100 percent \n");
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd49,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: threshold = %d \n",param_2[100]);
                  }
                  else {
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd20,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: Invalid Entry Count.\n");
                    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd21,
                                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                                 "NVRM: entryCount = %d\n",local_110._4_4_);
                  }
                }
                else {
                  nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd16,
                               "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                               "NVRM: Invalid Entry Size.\n");
                  nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd17,
                               "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                               "NVRM: entrySize = %d \n",local_110 & 0xffffffff);
                }
              }
              else {
                nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd05,
                             "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                             "NVRM: Invalid Header Size.\n");
                nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd06,
                             "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",4,
                             "NVRM: headerSize = %d\n",iVar2);
              }
            }
LAB_0049220a:
            uVar19 = 0x40;
          }
          else {
            uVar19 = 0x56;
            nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xc82,
                         "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",1,
                         "NVRM: Unable to retrieve DC System power limits table data. Possibly not supported by SBIOS. rc = %x\n"
                         ,iVar2);
          }
        }
LAB_00491e6b:
        portMemFree(lVar6);
        return uVar19;
      }
      if (uVar3 != 6) {
LAB_00491ca0:
        nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xd82,
                     "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",1,
                     "NVRM: Inavlid NVPCF subFunc : 0x%x\n");
        return 0x56;
      }
      local_168 = CONCAT62(local_168._2_6_,7);
      local_150 = CONCAT53(local_150._3_5_,0x40310);
      local_138 = CONCAT44(local_138._4_4_,*(undefined4 *)(param_2 + 0x36c));
      portMemSet(&local_118,0,7);
      portMemCopy(&local_118,3,&local_150,3);
      portMemCopy((long)&local_118 + 3,4,&local_138,4);
      iVar2 = osCallACPI_DSM(lVar5,9,9,&local_118,&local_168);
      if (iVar2 == 0) {
        return 0;
      }
      pcVar15 = "NVRM: Unable to set CPU TDP Limit. Possibly not supported by SBIOSrc = %x\n";
      uVar14 = 0xd79;
    }
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",uVar14,
                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",3,pcVar15,iVar2);
    return 0x56;
  }
  uVar19 = 0x51;
  local_138 = CONCAT62(local_138._2_6_,0xff);
  pcVar15 = (char *)portMemAllocNonPaged(0xff);
  if (pcVar15 == (char *)0x0) goto LAB_00491c86;
  iVar2 = osCallACPI_DSM(lVar5,9,1,pcVar15,&local_138);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xc47,
                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",3,
                 "NVRM: Unable to retrieve NVPCF Static data. Possibly not supported by SBIOSrc = %x\n"
                 ,iVar2);
    goto LAB_00491c80;
  }
  if ((ushort)((ushort)local_138 - 2) < 0xfe) {
    cVar9 = '\0';
    pcVar7 = pcVar15;
    do {
      cVar9 = cVar9 + *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (pcVar15 + ((ushort)local_138 - 1) != pcVar7);
    if ((char)(cVar9 + pcVar15[(local_138 & 0xffff) - 1]) != '\0') goto LAB_00491e88;
    uVar1 = (ushort)local_138 - 1;
    local_138 = CONCAT62(local_138._2_6_,uVar1);
    if (2 < uVar1) {
      uVar3 = (uint)uVar1;
      local_1a0 = 0;
      local_198 = 0;
      configReadStructure(pcVar15,&local_1a0,0,&DAT_00d8eb6f);
      if ((((int)local_1a0 == 0x20) && (local_1a0._4_4_ == 3)) && (local_198 == 1)) {
        local_1a8 = 0;
        configReadStructure(pcVar15,&local_1a8,3,&DAT_00d8eb72);
        param_2[0x5c] = (byte)local_1a8 >> 4;
        param_2[0x5b] = (byte)local_1a8 & 0xf;
        if (uVar1 == 3) goto LAB_00491c80;
        uVar3 = uVar3 - 4;
        pcVar7 = pcVar15 + 4;
      }
      else {
        nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xabe,"_sysDeviceParseStaticTable_2x",4,
                     "NVRM: NVPCF: %s: Unsupported header\n");
        pcVar7 = pcVar15;
      }
      if (3 < uVar3) {
        local_190 = 0;
        local_188 = 0;
        configReadStructure(pcVar7,&local_190,0,&DAT_00d8eb75);
        uVar14 = local_190;
        iVar2 = (int)local_190;
        uVar19 = 0;
        if ((int)local_190 - 0x22U < 4) {
          if ((((local_190._4_4_ == 4) && ((int)local_188 == 5)) && (local_188._4_4_ != 0)) &&
             (local_188._4_4_ * 5 + 4U == uVar3)) {
            local_118 = 0;
            uVar12 = 4;
            do {
              portMemSet(&local_118,0,8);
              configReadStructure(pcVar7,&local_118,uVar12,&DAT_00d8eb78);
              if (((uint)local_118 & 0xf) == 1) {
                param_2[0x54] = 1;
                param_2[0x4e] = 1;
                param_2[0x4f] = 0;
                param_2[0x50] = 0;
                param_2[0x51] = 0xe8;
                param_2[0x56] = 0x66;
                param_2[0x57] = 0xe;
                param_2[0x58] = 0;
                param_2[0x59] = 0x10;
                param_2[0x5a] = local_118._4_1_ & 1;
              }
              else if (((uint)local_118 & 0xf) == 2) {
                param_2[0x4e] = 1;
                param_2[0x4f] = 0;
                param_2[0x50] = 0;
                param_2[0x51] = 0;
                param_2[0x54] = 0;
                param_2[0x56] = 0;
                param_2[0x57] = 0;
                param_2[0x58] = 0;
                param_2[0x59] = 0;
                param_2[0x5a] = 0;
              }
              uVar12 = uVar12 + 5;
            } while (uVar3 != uVar12);
            if (iVar2 == 0x25) {
              *(uint *)(param_2 + 0x370) = (uint)(((uint)local_118 & 0x1e) == 2);
            }
            param_2[0x4a] = (byte)uVar14;
            param_2[0x4c] = 100;
            param_2[0x4d] = 0;
            goto LAB_00491c86;
          }
        }
        else if (uVar3 != 4) {
          local_150 = 0;
          local_148 = 0;
          local_140 = 0;
          configReadStructure(pcVar7,&local_150,0,&DAT_00d8eb66);
          iVar2 = local_140;
          uVar14 = local_150;
          if (((((uint)local_150 - 0x20 < 2) && (local_150._4_4_ == 5)) &&
              (((int)local_148 == 2 && ((local_148._4_4_ == 0xf && (local_140 != 0)))))) &&
             (local_140 * 0xf + 7U == uVar3)) {
            local_1a4 = 0;
            configReadStructure(pcVar7,&local_1a4,5,&DAT_00d8eb7d);
            if (local_1a4 != 0) {
              *(short *)(param_2 + 0x4c) = (short)local_1a4;
              iVar4 = 0;
              do {
                local_118 = 0;
                local_110 = 0;
                local_108[0]._0_4_ = 0;
                configReadStructure(pcVar7,&local_118,iVar4 * 0xf + 7,"1b1w3d");
                if (((uint)local_118 & 0xf) == 1) {
                  param_2[0x54] = 1;
                  *(short *)(param_2 + 0x4e) = (short)(local_118 >> 0x20);
                  param_2[0x50] = (byte)local_110;
                  param_2[0x51] = (byte)(local_110 >> 8);
                  *(short *)(param_2 + 0x52) = (short)(local_110 >> 0x10);
                  *(uint *)(param_2 + 0x56) = local_110._4_4_;
                  param_2[0x5a] = (byte)(undefined4)local_108[0] & 1;
                }
                else if (((uint)local_118 & 0xf) == 2) {
                  param_2[0x4e] = 1;
                  param_2[0x4f] = 0;
                  param_2[0x50] = 0;
                  param_2[0x51] = 0;
                  param_2[0x54] = 0;
                  param_2[0x56] = 0;
                  param_2[0x57] = 0;
                  param_2[0x58] = 0;
                  param_2[0x59] = 0;
                  param_2[0x5a] = 0;
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 != iVar2);
              param_2[0x4a] = (byte)uVar14;
              goto LAB_00491c86;
            }
          }
        }
      }
    }
  }
  else {
LAB_00491e88:
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0xc51,
                 "cliresCtrlCmdSystemNVPCFGetPowerModeInfo_IMPL",3,
                 "NVRM: Config Static Data checksum failed\n");
  }
LAB_00491c80:
  uVar19 = 0x56;
LAB_00491c86:
  portMemFree(pcVar15);
  return uVar19;
}


// ===== 00492840 cliresCtrlCmdNvdGetDumpSize_IMPL =====

void cliresCtrlCmdNvdGetDumpSize_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined8 local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  local_28 = 0;
  local_20 = 1000000;
  uStack_1c = 0;
  rcdbDumpComponent_IMPL(*(undefined8 *)(g_pSys + 0x228),*param_2,&local_28,2,0);
  param_2[1] = uStack_1c;
  return;
}


// ===== 004928a0 cliresCtrlCmdNvdGetDump_IMPL =====

undefined8 cliresCtrlCmdNvdGetDump_IMPL(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = 0;
  local_20 = 0;
  if (*(uint *)((long)param_2 + 0xc) < 0xf4241) {
    local_20._4_4_ = 0;
    local_28 = *param_2;
    local_20._0_4_ = *(uint *)((long)param_2 + 0xc);
    uVar1 = rcdbDumpComponent_IMPL
                      (*(undefined8 *)(g_pSys + 0x228),*(undefined4 *)(param_2 + 1),&local_28,0,0);
    *(undefined4 *)((long)param_2 + 0xc) = local_20._4_4_;
    return uVar1;
  }
  nvAssertFailedNoLog("pDumpParams->size <= NV0000_CTRL_NVD_MAX_DUMP_SIZE",
                      "src/kernel/rmapi/client_resource.c",0xdbc);
  return 0x1f;
}


// ===== 00492930 cliresCtrlCmdNvdGetTimestamp_IMPL =====

undefined8 cliresCtrlCmdNvdGetTimestamp_IMPL(undefined8 param_1,long *param_2)

{
  byte bVar1;
  long lVar2;
  uint local_10;
  uint local_c;
  
  bVar1 = *(byte *)(param_2 + 1);
  if (bVar1 == 2) {
    lVar2 = rdtsc();
    *param_2 = lVar2;
  }
  else if (bVar1 < 3) {
    osGetSystemTime(&local_10,&local_c);
    *param_2 = (ulong)local_10 * 1000000 + (ulong)local_c;
  }
  else {
    if (bVar1 != 3) {
      return 0x1f;
    }
    osGetPerformanceCounter(param_2);
  }
  return 0;
}


// ===== 004929c0 cliresCtrlCmdNvdGetNvlogInfo_IMPL =====

undefined8 cliresCtrlCmdNvdGetNvlogInfo_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  uVar1 = *param_2;
  if (uVar1 < 0x800) {
    nvAssertFailedNoLog("pParams->component >= NV0000_CTRL_NVD_DUMP_COMPONENT_NVLOG",
                        "src/kernel/rmapi/client_resource.c",0xe15);
  }
  else {
    if (uVar1 < 0xb00) {
      uVar3 = 0x56;
      if (uVar1 - 0x800 < 2) {
        if (param_1 == 0) {
          nvlogRunFlushCbs();
        }
        else {
          local_20 = 0;
          local_1c[0] = 0;
          gpumgrGetGpuAttachInfo(0,&local_20);
          while( true ) {
            lVar2 = gpumgrGetNextGpu(local_20,local_1c);
            if (lVar2 == 0) break;
            if (*(char *)(lVar2 + 0x909) != '\0') {
              kgspDumpGspLogs_IMPL(*(undefined8 *)(lVar2 + 0x1ba8),1);
            }
          }
        }
        param_2[1] = NvLogLogger;
        portMemSet(param_2 + 0xb,0,0x3c00);
        portSyncMutexAcquire(DAT_0059c198);
        lVar2 = 1;
        do {
          if (*(long *)(&NvLogLogger + lVar2 * 2) != 0) {
            param_2[lVar2 + 10] = *(uint *)(*(long *)(&NvLogLogger + lVar2 * 2) + 0xc);
          }
          lVar2 = lVar2 + 1;
        } while (lVar2 != 0xf01);
        portSyncMutexRelease(DAT_0059c198);
        uVar3 = 0;
      }
      return uVar3;
    }
    nvAssertFailedNoLog("pParams->component < NV0000_CTRL_NVD_DUMP_COMPONENT_RESERVED",
                        "src/kernel/rmapi/client_resource.c",0xe16);
  }
  return 0x1f;
}


// ===== 00492b20 cliresCtrlCmdNvdGetNvlogBufferInfo_IMPL =====

int cliresCtrlCmdNvdGetNvlogBufferInfo_IMPL(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint local_1c [3];
  
  uVar1 = *param_2;
  if (uVar1 < 0x800) {
    nvAssertFailedNoLog("pParams->component >= NV0000_CTRL_NVD_DUMP_COMPONENT_NVLOG",
                        "src/kernel/rmapi/client_resource.c",0xe60);
    return 0x1f;
  }
  if (0xaff < uVar1) {
    nvAssertFailedNoLog("pParams->component < NV0000_CTRL_NVD_DUMP_COMPONENT_RESERVED",
                        "src/kernel/rmapi/client_resource.c",0xe61);
    return 0x1f;
  }
  if (1 < uVar1 - 0x800) {
    return 0x56;
  }
  portSyncMutexAcquire(DAT_0059c198);
  if (param_2[2] == 0) {
    iVar3 = 0x1f;
    uVar1 = param_2[1];
    if (0xeff < param_2[1]) goto LAB_00492bd3;
  }
  else {
    iVar3 = nvlogGetBufferHandleFromTag(param_2[2],local_1c);
    uVar1 = local_1c[0];
    if (iVar3 != 0) goto LAB_00492bd3;
  }
  local_1c[0] = uVar1;
  puVar2 = (&PTR__nvlogZeroBuffer_00594988)[local_1c[0]];
  if (puVar2 == (undefined *)0x0) {
    nvAssertFailedNoLog("pBuffer != NULL","src/kernel/rmapi/client_resource.c",0xe7b);
    iVar3 = 0x57;
  }
  else {
    nvlogPauseLoggingToBuffer((ulong)local_1c[0],param_2[4] & 1);
    param_2[2] = *(uint *)(puVar2 + 0xc);
    param_2[3] = *(uint *)(puVar2 + 8);
    param_2[4] = *(uint *)(puVar2 + 0x10);
    param_2[5] = *(uint *)(puVar2 + 0x14);
    iVar3 = 0;
    param_2[6] = *(uint *)(puVar2 + 0x1c);
  }
LAB_00492bd3:
  portSyncMutexRelease(DAT_0059c198);
  return iVar3;
}


// ===== 00492c80 cliresCtrlCmdNvdGetNvlog_IMPL =====

undefined4 cliresCtrlCmdNvdGetNvlog_IMPL(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = *param_2;
  if (uVar1 < 0x800) {
    nvAssertFailedNoLog("pParams->component >= NV0000_CTRL_NVD_DUMP_COMPONENT_NVLOG",
                        "src/kernel/rmapi/client_resource.c",0xe9e);
  }
  else {
    if (uVar1 < 0xb00) {
      uVar3 = 0x56;
      if (uVar1 - 0x800 < 2) {
        uVar1 = param_2[3];
        if (4000 < uVar1) {
          nvAssertFailedNoLog("pParams->size <= NV0000_CTRL_NVLOG_MAX_BLOCK_SIZE",
                              "src/kernel/rmapi/client_resource.c",0xea6);
          return 0x1f;
        }
        uVar2 = param_2[1];
        portSyncMutexAcquire(DAT_0059c198);
        nvlogPauseLoggingToBuffer(uVar2,1);
        uVar3 = nvlogExtractBufferChunk(uVar2,param_2[2],param_2 + 3,param_2 + 4);
        if (param_2[3] != uVar1) {
          nvlogPauseLoggingToBuffer(uVar2,0);
        }
        portSyncMutexRelease(DAT_0059c198);
      }
      return uVar3;
    }
    nvAssertFailedNoLog("pParams->component < NV0000_CTRL_NVD_DUMP_COMPONENT_RESERVED",
                        "src/kernel/rmapi/client_resource.c",0xe9f);
  }
  return 0x1f;
}


// ===== 00492db0 cliresCtrlCmdSystemGetP2pCaps_IMPL =====

undefined8 cliresCtrlCmdSystemGetP2pCaps_IMPL(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (0x1f < param_2[0x20] - 1) {
    return 0x1f;
  }
  lVar1 = gpumgrGetGpuFromId(*param_2);
  if (lVar1 == 0) {
    return 0x1f;
  }
  if ((*(char *)(lVar1 + 0x908) == '\0') || (*(char *)(lVar1 + 0x4a4e) == '\0')) {
    uVar2 = CliGetSystemP2pCaps(param_2);
  }
  else {
    if (0x1f < param_2[0x20] - 1) {
      return 0x1f;
    }
    uVar2 = CliGetSystemP2pCaps_GSPCLIENT_part_0
                      (param_2,param_2[0x20],param_2 + 0x21,param_2 + 0x22,param_2 + 0x23,
                       param_2 + 0x24,*(undefined8 *)(param_2 + 0x28),
                       *(undefined8 *)(param_2 + 0x2a));
  }
  return uVar2;
}


// ===== 00492e70 cliresCtrlCmdSystemGetP2pCapsV2_IMPL =====

undefined8 cliresCtrlCmdSystemGetP2pCapsV2_IMPL(undefined8 param_1,int *param_2)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  bool bVar4;
  
  if (param_2[0x20] == 2) {
    iVar3 = *param_2;
    bVar4 = param_2[1] == iVar3;
  }
  else {
    if (0x1f < param_2[0x20] - 1U) {
      return 0x1f;
    }
    iVar3 = *param_2;
    bVar4 = false;
  }
  lVar1 = gpumgrGetGpuFromId(iVar3);
  if (lVar1 != 0) {
    if ((*(char *)(lVar1 + 0x908) == '\0') || (*(char *)(lVar1 + 0x4a4e) == '\0')) {
      iVar3 = 1;
      if (!bVar4) {
        iVar3 = param_2[0x20];
      }
      uVar2 = CliGetSystemP2pCaps(param_2,iVar3);
      return uVar2;
    }
    if (param_2[0x20] - 1U < 0x20) {
      uVar2 = CliGetSystemP2pCaps_GSPCLIENT_part_0
                        (param_2,param_2[0x20],param_2 + 0x21,param_2 + 0x22,param_2 + 0x23,
                         param_2 + 0x24,param_2 + 0x27,param_2 + 0x427);
      return uVar2;
    }
  }
  return 0x1f;
}


// ===== 00492f80 cliresCtrlCmdSystemGetP2pCapsMatrix_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong cliresCtrlCmdSystemGetP2pCapsMatrix_IMPL
                (undefined8 param_1,uint *param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  undefined2 *puVar7;
  long lVar8;
  uint *puVar9;
  uint *puVar10;
  undefined8 uVar11;
  uint uVar12;
  uint *puVar13;
  bool bVar14;
  ulong uVar15;
  uint uVar16;
  uint *puVar17;
  undefined2 *puVar18;
  uint *local_80;
  ulong local_78;
  undefined8 local_48;
  undefined8 local_40;
  
  if ((7 < *param_2 - 1) || (8 < param_2[1])) {
    return 0x1f;
  }
  lVar5 = gpumgrGetGpuFromId();
  if (lVar5 != 0) {
    if ((*(char *)(lVar5 + 0x908) == '\0') || (*(char *)(lVar5 + 0x4a4e) == '\0')) {
      if (param_2[1] != 0) {
        local_80 = param_2 + 10;
      }
      else {
        local_80 = param_2 + 2;
      }
      bVar14 = param_2[1] == 0;
      if (*param_2 == 0) {
        return 0;
      }
      local_78 = 0;
      puVar10 = param_2 + 2;
      do {
        uVar15 = 0;
        if (bVar14) goto LAB_00493033;
LAB_00493029:
        if ((uint)uVar15 < param_2[1]) {
LAB_00493033:
          do {
            uVar16 = (uint)uVar15;
            lVar5 = uVar15 + 0x92 + local_78 * 8;
            uVar1 = local_80[uVar15];
            local_48 = CONCAT44(uVar1,*puVar10);
            uVar6 = CliGetSystemP2pCaps(&local_48,(*puVar10 != uVar1) + '\x01',
                                        param_2 + lVar5 + -0x80,param_2 + lVar5 + -0x40,
                                        param_2 + lVar5,0,0,0);
            if ((int)uVar6 != 0) {
              return uVar6;
            }
            if ((uVar16 != (uint)local_78) || (!bVar14)) {
              uVar1 = local_80[uVar15];
              local_40 = CONCAT44(*puVar10,uVar1);
              uVar6 = CliGetSystemP2pCaps(&local_40,(*puVar10 != uVar1) + '\x01',0,
                                          param_2 + lVar5 + 0x40,param_2 + lVar5 + 0x80,0,0,0);
              if ((int)uVar6 != 0) {
                return uVar6;
              }
              if (!bVar14) goto LAB_004931c0;
              lVar5 = uVar15 + (local_78 & 0xffffffff) * 8;
              lVar8 = (local_78 & 0xffffffff) + uVar15 * 8;
              param_2[lVar8 + 0x12] = param_2[lVar5 + 0x12];
              param_2[lVar8 + 0x52] = param_2[lVar5 + 0xd2];
              param_2[lVar8 + 0x92] = param_2[lVar5 + 0x112];
              param_2[lVar8 + 0xd2] = param_2[lVar5 + 0x52];
              param_2[lVar8 + 0x112] = param_2[lVar5 + 0x92];
            }
            uVar15 = (ulong)(uVar16 + 1);
            if ((uint)local_78 < uVar16 + 1) break;
          } while( true );
        }
        local_78 = local_78 + 1;
        puVar10 = puVar10 + 1;
        if (*param_2 <= (uint)local_78) {
          return 0;
        }
      } while( true );
    }
    if ((*param_2 - 1 < 8) && (param_2[1] < 9)) {
      puVar7 = (undefined2 *)portMemAllocNonPaged(0x688);
      if (puVar7 == (undefined2 *)0x0) {
        nvCheckFailedNoLog(1,"pGetParams != NULL","src/kernel/rmapi/client_resource.c",0xf7c);
        return 0x51;
      }
      uVar16 = 0;
      uVar1 = param_2[1];
      portMemSet(param_2 + 0x12,0,0x100);
      portMemSet(param_2 + 0x52,0,0x100);
      portMemSet(param_2 + 0x92,0,0x100);
      portMemSet(param_2 + 0xd2,0,0x100);
      portMemSet(param_2 + 0x112,0,0x100);
      *puVar7 = 0x100;
      if (uVar1 == 0) {
        for (; uVar4 = *param_2, uVar16 < uVar4; uVar16 = uVar16 + 1) {
          lVar5 = gpumgrGetGpuFromId(param_2[(ulong)uVar16 + 2]);
          if (lVar5 == 0) {
            nvCheckFailedNoLog(1,"pGpu != NULL","src/kernel/rmapi/client_resource.c",0xf93);
            goto LAB_0049331f;
          }
          param_4 = (uint *)&DAT_00000010;
          portMemCopy(puVar7 + (ulong)uVar16 * 0x1a + 6,0x10,lVar5 + 0x7c5);
        }
      }
      else {
        for (; uVar16 < param_2[1]; uVar16 = uVar16 + 1) {
          lVar5 = gpumgrGetGpuFromId(param_2[(ulong)uVar16 + 10]);
          if (lVar5 == 0) {
            nvCheckFailedNoLog(1,"pGpu != NULL","src/kernel/rmapi/client_resource.c",3999);
            goto LAB_0049331f;
          }
          param_4 = (uint *)&DAT_00000010;
          portMemCopy(puVar7 + (ulong)uVar16 * 0x1a + 6,0x10,lVar5 + 0x7c5);
        }
        uVar4 = *param_2;
      }
      uVar16 = 0;
      puVar10 = param_2;
      puVar17 = param_2;
      if (uVar4 != 0) {
        do {
          local_40 = local_40 & 0xffffffff00000000;
          if (uVar1 == 0) {
            uVar4 = uVar16 + 1;
          }
          else {
            uVar4 = param_2[1];
          }
          *(uint *)(puVar7 + 2) = uVar4;
          lVar5 = gpumgrGetGpuFromId(puVar10[2]);
          if (lVar5 == 0) {
            uVar11 = 0xfbd;
            goto LAB_004935fd;
          }
          cVar3 = rmGpuGroupLockIsOwner(*(undefined4 *)(lVar5 + 0x7a4),0,&local_40);
          if (cVar3 == '\0') {
            uVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar5 + 0x7a4),0,0,0x8002,&local_40);
            if (uVar4 != 0) {
              uVar11 = 0xfc3;
              goto LAB_00493692;
            }
            bVar14 = true;
          }
          else {
            bVar14 = false;
          }
          lVar8 = gpuGetRpc(lVar5);
          if (lVar8 == 0) {
            nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/client_resource.c",0xfce);
            if (bVar14) {
              if ((int)local_40 != 0) {
                rmGpuGroupLockRelease(local_40 & 0xffffffff,0);
              }
            }
            goto LAB_004935ee;
          }
          if ((*(char *)(lVar5 + 0x909) == '\0') && (*(char *)(lVar5 + 0x90a) == '\0')) {
            uVar4 = rpcDmaControl_wrapper
                              (lVar5,lVar8,*(undefined4 *)(lVar5 + 0x3b34),
                               *(undefined4 *)(lVar5 + 0x3b3c),0x208001a0,puVar7,0x688);
          }
          else {
            uVar4 = (**(code **)(lVar5 + 0x3b90))
                              (lVar5 + 0x3b58,*(undefined4 *)(lVar5 + 0x3b34),
                               *(undefined4 *)(lVar5 + 0x3b3c),0x208001a0,puVar7);
          }
          if ((bVar14) && ((int)local_40 != 0)) {
            rmGpuGroupLockRelease();
          }
          if (uVar4 != 0) goto LAB_00493324;
          if (*(int *)(puVar7 + 2) != 0) {
            puVar13 = (uint *)(puVar7 + 0xe);
            lVar5 = 0;
            puVar9 = puVar10;
            do {
              uVar4 = *puVar13;
              puVar17[lVar5 + 0x12] = uVar4;
              uVar2 = puVar13[1];
              puVar17[lVar5 + 0x52] = uVar2;
              uVar12 = puVar13[2];
              puVar17[lVar5 + 0x92] = uVar12;
              if (uVar1 == 0) {
                puVar9[0x12] = uVar4;
                puVar9[0xd2] = uVar2;
                puVar9[0x112] = uVar12;
              }
              lVar5 = lVar5 + 1;
              puVar13 = puVar13 + 0xd;
              puVar9 = puVar9 + 8;
            } while ((uint)lVar5 < *(uint *)(puVar7 + 2));
          }
          uVar16 = uVar16 + 1;
          param_4 = param_2;
          puVar10 = puVar10 + 1;
          puVar17 = puVar17 + 8;
        } while (uVar16 < *param_2);
      }
      portMemSet(puVar7,0,0x688);
      *puVar7 = 0x100;
      if (*param_2 != 0) {
        puVar18 = puVar7 + 6;
        lVar5 = 0;
        do {
          lVar8 = gpumgrGetGpuFromId(param_2[lVar5 + 2]);
          if (lVar8 == 0) {
            nvCheckFailedNoLog(1,"pGpu != NULL","src/kernel/rmapi/client_resource.c",0xffb);
            goto LAB_0049331f;
          }
          param_4 = (uint *)&DAT_00000010;
          portMemCopy(puVar18,0x10,lVar8 + 0x7c5);
          lVar5 = lVar5 + 1;
          puVar18 = puVar18 + 0x1a;
        } while ((uint)lVar5 < *param_2);
      }
      uVar16 = 0;
      do {
        if (uVar1 == 0) {
          if (*param_2 <= uVar16) {
LAB_00493966:
            uVar4 = 0;
            goto LAB_00493324;
          }
          local_40 = (ulong)local_40._4_4_ << 0x20;
          *(uint *)(puVar7 + 2) = uVar16 + 1;
          lVar5 = gpumgrGetGpuFromId(param_2[(ulong)uVar16 + 2]);
          puVar10 = param_4;
        }
        else {
          if (param_2[1] <= uVar16) goto LAB_00493966;
          local_40 = (ulong)local_40._4_4_ << 0x20;
          *(uint *)(puVar7 + 2) = *param_2;
          lVar5 = gpumgrGetGpuFromId(param_2[(ulong)uVar16 + 10]);
          puVar10 = param_4;
        }
        uVar15 = (ulong)uVar16;
        if (lVar5 == 0) {
          uVar11 = 0x1018;
LAB_004935fd:
          nvCheckFailedNoLog(1,"pGpu != NULL","src/kernel/rmapi/client_resource.c",uVar11);
LAB_0049331f:
          uVar4 = 0x1f;
          goto LAB_00493324;
        }
        cVar3 = rmGpuGroupLockIsOwner(*(undefined4 *)(lVar5 + 0x7a4),0,&local_40);
        if (cVar3 == '\0') {
          param_4 = (uint *)0x8002;
          uVar4 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar5 + 0x7a4),0,0,0x8002,&local_40);
          if (uVar4 != 0) {
            uVar11 = 0x101e;
LAB_00493692:
            nvAssertOkFailedNoLog
                      (uVar4,
                       "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_RPC, &gpuMaskRelease)"
                       ,"src/kernel/rmapi/client_resource.c",uVar11);
            goto LAB_00493324;
          }
          lVar8 = gpuGetRpc(lVar5);
          bVar14 = true;
          puVar10 = param_4;
          if (lVar8 != 0) goto LAB_0049374b;
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/client_resource.c",0x102a);
          if ((int)local_40 == 0) goto LAB_004935ee;
          uVar4 = 0x1a;
LAB_0049388f:
          rmGpuGroupLockRelease();
        }
        else {
          lVar8 = gpuGetRpc(lVar5);
          if (lVar8 == 0) {
            nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/client_resource.c",0x102a);
LAB_004935ee:
            uVar4 = 0x1a;
LAB_00493324:
            portMemFree(puVar7);
            return (ulong)uVar4;
          }
          bVar14 = false;
LAB_0049374b:
          param_4 = (uint *)(ulong)*(uint *)(lVar5 + 0x3b3c);
          if ((*(char *)(lVar5 + 0x909) == '\0') && (*(char *)(lVar5 + 0x90a) == '\0')) {
            uVar4 = rpcDmaControl_wrapper
                              (lVar5,lVar8,*(undefined4 *)(lVar5 + 0x3b34),param_4,0x208001a0,puVar7
                               ,0x688,puVar10);
          }
          else {
            param_4 = (uint *)0x208001a0;
            uVar4 = (**(code **)(lVar5 + 0x3b90))(lVar5 + 0x3b58);
          }
          if ((bVar14) && ((int)local_40 != 0)) goto LAB_0049388f;
        }
        if (uVar4 != 0) goto LAB_00493324;
        if (*(int *)(puVar7 + 2) != 0) {
          uVar4 = 0;
          if (uVar1 == 0) {
            uVar6 = 0;
            do {
              while (uVar16 != (uint)uVar6) {
                uVar12 = (uint)uVar6 + 1;
                lVar5 = uVar15 + uVar6 * 8;
                param_4 = (uint *)(uVar6 + uVar15 * 8);
                uVar4 = *(uint *)(puVar7 + uVar6 * 0x1a + 0x10);
                param_2[lVar5 + 0x52] = uVar4;
                uVar2 = *(uint *)(puVar7 + uVar6 * 0x1a + 0x12);
                param_2[lVar5 + 0x92] = uVar2;
                param_2[(long)((long)param_4 + 0xd2)] = uVar4;
                param_2[(long)((long)param_4 + 0x112)] = uVar2;
                uVar6 = (ulong)uVar12;
                if (*(uint *)(puVar7 + 2) <= uVar12) goto LAB_0049386f;
              }
              uVar6 = (ulong)(uVar16 + 1);
            } while (uVar16 + 1 < *(uint *)(puVar7 + 2));
          }
          else {
            do {
              uVar6 = (ulong)uVar4;
              uVar4 = uVar4 + 1;
              param_4 = (uint *)(uVar15 + uVar6 * 8);
              param_2[(long)((long)param_4 + 0xd2)] = *(uint *)(puVar7 + uVar6 * 0x1a + 0x10);
              param_2[(long)((long)param_4 + 0x112)] = *(uint *)(puVar7 + uVar6 * 0x1a + 0x12);
            } while (uVar4 < *(uint *)(puVar7 + 2));
          }
        }
LAB_0049386f:
        uVar16 = uVar16 + 1;
      } while( true );
    }
  }
  return 0x1f;
LAB_004931c0:
  uVar15 = (ulong)(uVar16 + 1);
  goto LAB_00493029;
}


// ===== 00493970 cliresCtrlCmdSystemGetVgxSystemInfo_IMPL =====

undefined8 cliresCtrlCmdSystemGetVgxSystemInfo_IMPL(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = gpumgrGetSomeGpu();
  if (lVar1 != 0) {
    lVar1 = gpuGetStaticInfo(lVar1);
    uVar2 = 0x56;
    if (lVar1 != 0) {
      portMemCopy(param_2,0x508,lVar1 + 0xa1e4,0x508);
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x3f;
}


// ===== 00493a00 cliresCtrlCmdSystemGetGpusPowerStatus_IMPL =====

undefined8 cliresCtrlCmdSystemGetGpusPowerStatus_IMPL(undefined8 param_1,byte *param_2)

{
  uint uVar1;
  byte bVar5;
  long lVar2;
  long lVar3;
  ulong uVar4;
  byte *pbVar6;
  byte bVar7;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_24 = 0;
  local_20 = 0;
  lVar3 = *(long *)(g_pSys + 0x1e0);
  local_1c = 0;
  portMemSet(param_2,0,0x41);
  bVar7 = 0;
  if (*(char *)(lVar3 + 0x1b20) != '\0') {
    lVar2 = 0;
    do {
      bVar7 = *(byte *)(lVar3 + 0x1b21 + lVar2);
      param_2[lVar2 + 0x21] = 1;
      param_2[lVar2 + 1] = bVar7;
      bVar7 = *(byte *)(lVar3 + 0x1b20);
      lVar2 = lVar2 + 1;
    } while ((uint)lVar2 < (uint)bVar7);
  }
  *param_2 = bVar7;
  gpumgrGetGpuAttachInfo(&local_24,&local_20);
LAB_00493ac0:
  lVar3 = gpumgrGetNextGpu(local_20,&local_1c);
  if (lVar3 == 0) {
    return 0;
  }
  bVar7 = *param_2;
  bVar5 = (byte)((ulong)*(undefined8 *)(lVar3 + 0x878) >> 8);
  uVar4 = 0;
  pbVar6 = param_2;
  if (bVar7 != 0) goto LAB_00493b0b;
  bVar7 = 1;
  goto LAB_00493b1c;
LAB_00493b0b:
  do {
    pbVar6 = pbVar6 + 1;
    if (*pbVar6 == bVar5) break;
    uVar1 = (int)uVar4 + 1;
    uVar4 = (ulong)uVar1;
  } while (uVar1 != bVar7);
  if (((uint)bVar7 == (uint)uVar4) && (bVar7 < 0x20)) {
    bVar7 = bVar7 + 1;
LAB_00493b1c:
    param_2[uVar4 + 1] = bVar5;
    param_2[uVar4 + 0x21] = 0;
    *param_2 = bVar7;
  }
  goto LAB_00493ac0;
}


// ===== 00493b4a cliresCtrlCmdSystemGetPrivilegedStatus_IMPL.cold =====

void cliresCtrlCmdSystemGetPrivilegedStatus_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00493b60 cliresCtrlCmdSystemGetPrivilegedStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 cliresCtrlCmdSystemGetPrivilegedStatus_IMPL(long param_1,byte *param_2)

{
  code *pcVar1;
  char cVar2;
  long *plVar3;
  long lVar4;
  byte bVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  plVar3 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48),
                                      __nvoc_class_def_RmClient);
  lVar4 = resservGetTlsCallContext();
  if (plVar3 != (long *)0x0) {
    bVar5 = 3;
    if (*(uint *)(lVar4 + 0x28) < 2) {
      bVar5 = *(uint *)(lVar4 + 0x28) != 0;
    }
    cVar2 = (**(code **)(*plVar3 + 0xe0))();
    if (cVar2 != '\0') {
      bVar5 = bVar5 | 4;
    }
    *param_2 = bVar5;
    return 0;
  }
  nvAssertFailedNoLog("pClient != NULL","src/kernel/rmapi/client_resource.c",0x11c0);
  return 0x23;
}


// ===== 00493c10 cliresCtrlCmdSystemGetFabricStatus_IMPL =====

undefined8 cliresCtrlCmdSystemGetFabricStatus_IMPL(undefined8 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 1;
  if ((*(char *)(g_pSys + 0x6b) != '\0') &&
     (iVar1 = 3 - (uint)(*(char *)(g_pSys + 0x6d) == '\0'), *(char *)(g_pSys + 0x6c) != '\0')) {
    iVar1 = 4;
  }
  *param_2 = iVar1;
  return 0;
}


// ===== 00493c50 cliresCtrlCmdGpuGetUuidInfo_IMPL =====

undefined8 cliresCtrlCmdGpuGetUuidInfo_IMPL(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = gpumgrGetGpuFromUuid(param_2,*(undefined4 *)(param_2 + 0x100));
  if (lVar2 != 0) {
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(lVar2 + 0x7ac);
    *(undefined4 *)(param_2 + 0x108) = *(undefined4 *)(lVar2 + 0x7b4);
    uVar1 = gpumgrGetSubDeviceInstanceFromGpu(lVar2);
    *(undefined4 *)(param_2 + 0x10c) = uVar1;
    return 0;
  }
  return 0x57;
}


// ===== 00493cc0 cliresCtrlCmdGpuGetUuidFromGpuId_IMPL =====

int cliresCtrlCmdGpuGetUuidFromGpuId_IMPL(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  uint local_24;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  local_24 = 0;
  iVar1 = gpumgrGetGpuUuidInfo(*param_2,local_20,&local_24,param_2[1]);
  if (iVar1 != 0) {
    lVar2 = gpumgrGetGpuFromId(*param_2);
    if (lVar2 == 0) {
      return 0x57;
    }
    iVar1 = gpuGetGidInfo_IMPL(lVar2,local_20,&local_24,param_2[1]);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x1224,
                   "cliresCtrlCmdGpuGetUuidFromGpuId_IMPL",3,
                   "NVRM: gpumgrGetGpuInfo: getting gpu GUID failed\n");
      return iVar1;
    }
  }
  if (local_24 < 0x101) {
    portMemCopy(param_2 + 2,local_24,local_20[0],local_24);
    param_2[0x42] = local_24;
  }
  portMemFree(local_20[0]);
  return 0;
}


// ===== 00493da0 cliresCtrlCmdGpuModifyGpuDrainState_IMPL =====

int cliresCtrlCmdGpuModifyGpuDrainState_IMPL(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  undefined1 uVar6;
  
  lVar2 = gpumgrGetGpuFromId(*param_2);
  if (param_2[1] == 1) {
    uVar4 = (uint)param_2[2] >> 1;
    bVar3 = (byte)uVar4 & 1;
    uVar5 = param_2[2] & 1;
    if ((uVar5 == 0) && ((uVar4 & 1) != 0)) {
      return 0x1f;
    }
    uVar6 = 1;
  }
  else {
    if (param_2[1] != 0) {
      return 0x1f;
    }
    bVar3 = 0;
    uVar5 = 0;
    uVar6 = 0;
  }
  iVar1 = gpumgrModifyGpuDrainState(*param_2,uVar6,uVar5,bVar3);
  if (((lVar2 != 0) && (iVar1 == 0)) && (*(long *)(lVar2 + 0x1ce8) != 0)) {
    *(undefined1 *)(*(long *)(lVar2 + 0x1ce8) + 0x2e6) = uVar6;
    iVar1 = knvlinkSyncLaneShutdownProps_IMPL(lVar2);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x1274,
                   "cliresCtrlCmdGpuModifyGpuDrainState_IMPL",3,
                   "NVRM: Failed to sync lane shutdown properties\n");
    }
  }
  return iVar1;
}


// ===== 00493e90 cliresCtrlCmdGpuQueryGpuDrainState_IMPL =====

void cliresCtrlCmdGpuQueryGpuDrainState_IMPL(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  char local_1a;
  char local_19 [9];
  
  iVar1 = gpumgrQueryGpuDrainState(*param_2,&local_1a,local_19);
  if (iVar1 == 0) {
    param_2[1] = (uint)(local_1a != '\0');
    param_2[2] = (uint)(local_19[0] != '\0');
  }
  return;
}


// ===== 00493ed1 cliresCtrlCmdSetSubProcessID_IMPL.cold =====

void cliresCtrlCmdSetSubProcessID_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00493ee0 cliresCtrlCmdSetSubProcessID_IMPL =====

undefined8 cliresCtrlCmdSetSubProcessID_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar2 = serverutilGetClientUnderLock
                    (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48));
  if (lVar2 != 0) {
    *(undefined4 *)(lVar2 + 0x11c) = *param_2;
    portStringCopy(lVar2 + 0x120,100,param_2 + 1,100);
    return 0;
  }
  return 0x23;
}


// ===== 00493f4b cliresCtrlCmdDisableSubProcessUserdIsolation_IMPL.cold =====

void cliresCtrlCmdDisableSubProcessUserdIsolation_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00493f60 cliresCtrlCmdDisableSubProcessUserdIsolation_IMPL =====

undefined8 cliresCtrlCmdDisableSubProcessUserdIsolation_IMPL(long param_1,undefined1 *param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar2 = serverutilGetClientUnderLock
                    (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48));
  if (lVar2 != 0) {
    *(undefined1 *)(lVar2 + 0x184) = *param_2;
    return 0;
  }
  return 0x23;
}


// ===== 00493fb0 cliresCtrlCmdSyncGpuBoostInfo_IMPL =====

undefined8 cliresCtrlCmdSyncGpuBoostInfo_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pParams","src/kernel/rmapi/client_resource.c",0x12d3);
    return 0x1f;
  }
  lVar1 = *(long *)(g_pSys + 0x248);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    *(bool *)param_2 = lVar1 != 0;
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x12d4);
  return 0x2f;
}


// ===== 00494050 cliresCtrlCmdSyncGpuBoostGroupCreate_IMPL =====

ulong cliresCtrlCmdSyncGpuBoostGroupCreate_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  char cVar2;
  ulong uVar3;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pParams","src/kernel/rmapi/client_resource.c",0x12f2);
    return 0x1f;
  }
  uVar1 = *(undefined8 *)(g_pSys + 0x248);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    *(undefined4 *)(param_2 + 0x84) = 0xffffffff;
    uVar3 = gpuboostmgrCreateGroup_IMPL(uVar1);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/rmapi/client_resource.c",0x12fa);
    return uVar3 & 0xffffffff;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x12f3);
  return 0x2f;
}


// ===== 00494110 cliresCtrlCmdSyncGpuBoostGroupDestroy_IMPL =====

ulong cliresCtrlCmdSyncGpuBoostGroupDestroy_IMPL(undefined8 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  char cVar2;
  ulong uVar3;
  
  if (param_2 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("NULL != pParams","src/kernel/rmapi/client_resource.c",0x130e);
    return 0x1f;
  }
  uVar1 = *(undefined8 *)(g_pSys + 0x248);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    uVar3 = gpuboostmgrDestroyGroup_IMPL(uVar1,*param_2);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/rmapi/client_resource.c",0x1313);
    return uVar3 & 0xffffffff;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x130f);
  return 0x2f;
}


// ===== 004941e0 cliresCtrlCmdSyncGpuBoostGroupInfo_IMPL =====

ulong cliresCtrlCmdSyncGpuBoostGroupInfo_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  char cVar2;
  ulong uVar3;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pParams","src/kernel/rmapi/client_resource.c",0x1326);
    return 0x1f;
  }
  uVar1 = *(undefined8 *)(g_pSys + 0x248);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    uVar3 = gpuboostmgrQueryGroups_IMPL(uVar1,param_2);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvAssertFailedNoLog("NV_OK == status","src/kernel/rmapi/client_resource.c",0x132a);
    return uVar3 & 0xffffffff;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource.c",0x1327);
  return 0x2f;
}


// ===== 004942a0 cliresCtrlCmdVgpuVfioNotifyRMStatus_IMPL =====

undefined4 cliresCtrlCmdVgpuVfioNotifyRMStatus_IMPL(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = osIsVgpuVfioPresent();
  if (iVar1 == 0) {
    osWakeRemoveVgpu(param_2[1],*param_2);
    return 0;
  }
  return 0x56;
}


// ===== 004942e0 cliresCtrlCmdVgpuGetVgpuVersion_IMPL =====

void cliresCtrlCmdVgpuGetVgpuVersion_IMPL(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uStack_20;
  
  *param_2 = 0x1c000100180001;
  nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x134d,"cliresCtrlCmdVgpuGetVgpuVersion_IMPL",1,
               "NVRM: User enforced vGPU version = (0x%x, 0x%x)\n",*(undefined4 *)(param_2 + 1),
               *(undefined4 *)((long)param_2 + 0xc));
  kvgpumgrGetHostVgpuVersion(param_2 + 1,(long)param_2 + 0xc,uStack_20);
  return;
}


// ===== 00494340 cliresCtrlCmdVgpuSetVgpuVersion_IMPL =====

void cliresCtrlCmdVgpuSetVgpuVersion_IMPL(undefined8 param_1,undefined4 *param_2)

{
  kvgpumgrSetHostVgpuVersion(*param_2,param_2[1]);
  return;
}


// ===== 00494350 cliresCtrlCmdClientGetAddrSpaceType_IMPL.cold =====

void cliresCtrlCmdClientGetAddrSpaceType_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494360 cliresCtrlCmdClientGetAddrSpaceType_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int cliresCtrlCmdClientGetAddrSpaceType_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long *plVar3;
  uint local_9c;
  undefined8 local_98;
  long local_90;
  undefined1 local_88 [8];
  undefined8 local_80;
  long local_78;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = serverGetClientUnderLock
                    (g_resServ,*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48)
                     ,&local_98);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"serverGetClientUnderLock(&g_resServ, hClient, &pRsClient)",
               "src/kernel/rmapi/client_resource.c",0x136f);
    return iVar2;
  }
  iVar2 = clientGetResourceRef_IMPL(local_98,*param_2,&local_90);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"clientGetResourceRef(pRsClient, pParams->hObject, &pResourceRef)",
               "src/kernel/rmapi/client_resource.c",0x1370);
    return iVar2;
  }
  portMemSet(local_88,0,0x70);
  local_80 = local_98;
  local_78 = local_90;
  plVar3 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_90 + 8),__nvoc_class_def_Memory);
  if (plVar3 == (long *)0x0) {
    plVar3 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_90 + 8),__nvoc_class_def_GpuResource);
    if (plVar3 == (long *)0x0) {
      return 0x31;
    }
    iVar2 = (**(code **)(*plVar3 + 0x1d8))
                      (plVar3,local_88,param_2[1],&local_9c,*(code **)(*plVar3 + 0x1d8));
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "gpuresGetMapAddrSpace(pGpuResource, &callContext, pParams->mapFlags, &memType)",
                 "src/kernel/rmapi/client_resource.c",0x1380);
      return iVar2;
    }
  }
  else {
    iVar2 = (**(code **)(*plVar3 + 0x1b8))
                      (plVar3,local_88,param_2[1],&local_9c,*(code **)(*plVar3 + 0x1b8));
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"memGetMapAddrSpace(pMemory, &callContext, pParams->mapFlags, &memType)",
                 "src/kernel/rmapi/client_resource.c",0x1379);
      return iVar2;
    }
  }
  if (local_9c == 4) {
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x139f,
                 "cliresCtrlCmdClientGetAddrSpaceType_IMPL",4,
                 "NVRM: VIRTUAL (0x%x) is not a valid NV0000_CTRL_CMD_CLIENT_GET_ADDR_SPACE_TYPE\n",
                 4);
    param_2[2] = 0;
  }
  else {
    if (local_9c < 5) {
      if (local_9c == 2) {
        param_2[2] = 2;
        return 0;
      }
      if (local_9c == 3) {
        param_2[2] = 3;
        return 0;
      }
      if (local_9c == 1) {
        param_2[2] = 1;
        return 0;
      }
    }
    else {
      if (local_9c == 6) {
        param_2[2] = 4;
        return 0;
      }
      if (local_9c == 7) {
        param_2[2] = 5;
        return 0;
      }
    }
    nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x13a6,
                 "cliresCtrlCmdClientGetAddrSpaceType_IMPL",4,
                 "NVRM: Cannot determine address space 0x%x\n");
    param_2[2] = 0;
  }
  return 0x1f;
}


// ===== 0049468a cliresCtrlCmdClientGetHandleInfo_IMPL.cold =====

void cliresCtrlCmdClientGetHandleInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004946a0 cliresCtrlCmdClientGetHandleInfo_IMPL =====

undefined8 cliresCtrlCmdClientGetHandleInfo_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  uVar2 = serverutilGetResourceRef
                    (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48),*param_2,
                     local_20);
  if ((int)uVar2 == 0) {
    if (param_2[1] == 1) {
      uVar3 = 0;
      if (*(long *)(local_20[0] + 0x18) != 0) {
        uVar3 = *(undefined4 *)(*(long *)(local_20[0] + 0x18) + 0x10);
      }
      param_2[2] = uVar3;
      return uVar2;
    }
    if (param_2[1] == 2) {
      *(ulong *)(param_2 + 2) = (ulong)*(uint *)(local_20[0] + 0x11c);
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 0049472c cliresCtrlCmdClientGetAccessRights_IMPL.cold =====

void cliresCtrlCmdClientGetAccessRights_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494740 cliresCtrlCmdClientGetAccessRights_IMPL =====

ulong cliresCtrlCmdClientGetAccessRights_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  ulong uVar3;
  undefined8 local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  uVar1 = **(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48);
  uVar3 = serverutilGetResourceRef(param_2[1],*param_2,&local_20);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  rsAccessUpdateRights(local_20,uVar1,0);
  rsAccessGetAvailableRights(local_20,uVar1,param_2 + 2);
  return uVar3 & 0xffffffff;
}


// ===== 004947b5 cliresCtrlCmdClientShareObject_IMPL.cold =====

void cliresCtrlCmdClientShareObject_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004947c0 cliresCtrlCmdClientShareObject_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int cliresCtrlCmdClientShareObject_IMPL(long param_1,undefined4 *param_2)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined1 *local_88;
  long *local_80;
  undefined8 local_78;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (*(ushort *)(param_2 + 3) < 8) {
    plVar1 = (long *)**(long **)(*(long *)(param_1 + 0xe0) + 0x48);
    iVar3 = clientGetResourceRef_IMPL(plVar1,*param_2,&local_a0);
    if (iVar3 == 0) {
      lVar5 = resservGetTlsCallContext();
      portMemSet(&local_88,0,0x70);
      local_88 = g_resServ;
      local_78 = local_a0;
      local_60 = *(undefined8 *)(lVar5 + 0x28);
      local_58 = *(undefined8 *)(lVar5 + 0x30);
      local_50 = *(undefined8 *)(lVar5 + 0x38);
      local_48 = *(undefined8 *)(lVar5 + 0x40);
      local_80 = plVar1;
      iVar3 = resservSwapTlsCallContext(&local_98,&local_88);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*plVar1 + 0x88))(plVar1,local_a0,param_2 + 1,&local_88);
        iVar4 = resservRestoreTlsCallContext(local_98);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,"resservRestoreTlsCallContext(pOldCallContext)",
                     "src/kernel/rmapi/client_resource.c",0x141b);
        }
        if ((((iVar3 == 0) && ((*(byte *)((long)param_2 + 0xe) & 1) == 0)) &&
            (*(short *)(param_2 + 3) == 3)) && (param_2[1] != (int)plVar1[9])) {
          iVar3 = serverGetClientUnderLock(g_resServ,param_2[1],&local_90);
          if (iVar3 == 0) {
            iVar3 = clientAddAccessBackRef_IMPL(local_90,local_a0);
          }
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar3,"resservSwapTlsCallContext(&pOldCallContext, &callContext)",
                   "src/kernel/rmapi/client_resource.c",0x1418);
      }
    }
    return iVar3;
  }
  return 0x1f;
}


// ===== 004949a6 cliresCtrlCmdClientSetInheritedSharePolicy_IMPL.cold =====

void cliresCtrlCmdClientSetInheritedSharePolicy_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004949b0 cliresCtrlCmdClientSetInheritedSharePolicy_IMPL =====

void cliresCtrlCmdClientSetInheritedSharePolicy_IMPL(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  undefined4 local_28;
  undefined8 local_24;
  undefined4 local_1c;
  
  portMemSet(&local_28,0,0x10);
  local_24 = *param_2;
  local_1c = *(undefined4 *)(param_2 + 1);
  if (param_1 != 0) {
    local_28 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0xe0) + 0x48) + 0x10);
    cliresCtrlCmdClientShareObject_IMPL(param_1,&local_28);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494a14 cliresCtrlCmdClientGetChildHandle_IMPL.cold =====

void cliresCtrlCmdClientGetChildHandle_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494a20 cliresCtrlCmdClientGetChildHandle_IMPL =====

void cliresCtrlCmdClientGetChildHandle_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 local_28;
  long local_20 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = serverutilGetResourceRef
                    (*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48),*param_2,
                     &local_28);
  if (iVar2 == 0) {
    iVar2 = refFindChildOfType(local_28,param_2[1],1,local_20);
    if (iVar2 == 0) {
      uVar3 = 0;
      if (local_20[0] != 0) {
        uVar3 = *(undefined4 *)(local_20[0] + 0x10);
      }
      param_2[2] = uVar3;
      return;
    }
  }
  return;
}


// ===== 00494a90 cliresCtrlCmdObjectsAreDuplicates_IMPL.cold =====

void cliresCtrlCmdObjectsAreDuplicates_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494aa0 cliresCtrlCmdObjectsAreDuplicates_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void cliresCtrlCmdObjectsAreDuplicates_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long local_20 [2];
  
  if (param_1 != 0) {
    iVar2 = clientGetResourceRef_IMPL
                      (**(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48),*param_2,local_20);
    if (iVar2 == 0) {
      (**(code **)(**(long **)(local_20[0] + 8) + 0x38))
                (*(long **)(local_20[0] + 8),param_2[1],param_2 + 2);
    }
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494af7 cliresCtrlCmdClientSubscribeToImexChannel_IMPL.cold =====

void cliresCtrlCmdClientSubscribeToImexChannel_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494b10 cliresCtrlCmdClientSubscribeToImexChannel_IMPL =====

undefined8 cliresCtrlCmdClientSubscribeToImexChannel_IMPL(long param_1,undefined8 *param_2)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar5 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48),
                             __nvoc_class_def_RmClient);
  cVar3 = osImexChannelIsSupported();
  if ((cVar3 != '\0') && (iVar4 = osImexChannelCount(), iVar4 != 0)) {
    iVar4 = osImexChannelGet(*param_2);
    if (iVar4 < 0) {
      return 0x1b;
    }
    iVar1 = *(int *)(lVar5 + 600);
    if (iVar1 == iVar4) {
      *(int *)(param_2 + 1) = iVar1;
    }
    else {
      if (iVar1 != -1) {
        return 99;
      }
      *(int *)(lVar5 + 600) = iVar4;
      *(int *)(param_2 + 1) = iVar4;
    }
    return 0;
  }
  return 0x56;
}


// ===== 00494bc0 cliresCtrlCmdGpuGetMemOpEnable_IMPL =====

undefined8 cliresCtrlCmdGpuGetMemOpEnable_IMPL(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = g_pSys;
  *param_2 = 0;
  if (*(char *)(lVar1 + 0x66) == '\0') {
    return 0;
  }
  nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x1498,"cliresCtrlCmdGpuGetMemOpEnable_IMPL",1,
               "NVRM: MemOpOverride enabled\n");
  *param_2 = 1;
  return 0;
}


// ===== 00494c21 cliresCtrlCmdGpuDisableNvlinkInit_IMPL.cold =====

void cliresCtrlCmdGpuDisableNvlinkInit_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00494c30 cliresCtrlCmdGpuDisableNvlinkInit_IMPL =====

undefined8 cliresCtrlCmdGpuDisableNvlinkInit_IMPL(long param_1,int *param_2)

{
  code *pcVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar3 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xe0) + 0x48),
                             __nvoc_class_def_RmClient);
  lVar4 = resservGetTlsCallContext();
  if (lVar3 != 0) {
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pCallContext != NULL","src/kernel/rmapi/client_resource.c",0x14ab);
      uVar5 = 0x40;
    }
    else {
      cVar2 = rmclientIsCapableOrAdmin_IMPL(lVar3,0x200,*(undefined4 *)(lVar4 + 0x28));
      if (cVar2 == '\0') {
        nvDbg_Printf("src/kernel/rmapi/client_resource.c",0x14b1,
                     "cliresCtrlCmdGpuDisableNvlinkInit_IMPL",3,
                     "NVRM: Non-privileged context issued privileged cmd\n");
        uVar5 = 0x1b;
      }
      else {
        if (*param_2 != -1) {
          uVar5 = gpumgrSetGpuInitDisabledNvlinks_IMPL
                            (*param_2,param_2[1],param_2 + 2,(char)param_2[6]);
          return uVar5;
        }
        uVar5 = 0x1f;
      }
    }
    return uVar5;
  }
  nvAssertFailedNoLog("NULL != pRmClient","src/kernel/rmapi/client_resource.c",0x14a9);
  return 0x23;
}


// ===== 00494d40 cliresCtrlCmdGpuSetNvlinkBwMode_IMPL =====

void cliresCtrlCmdGpuSetNvlinkBwMode_IMPL(undefined8 param_1,undefined1 *param_2)

{
  gpumgrSetGpuNvlinkBwMode_IMPL(*param_2);
  return;
}


// ===== 00494d50 cliresCtrlCmdGpuGetNvlinkBwMode_IMPL =====

undefined8 cliresCtrlCmdGpuGetNvlinkBwMode_IMPL(undefined8 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  uVar1 = gpumgrGetGpuNvlinkBwMode_IMPL();
  *param_2 = uVar1;
  uVar1 = gpumgrGetGpuNvlinkBwModeScope_IMPL();
  param_2[1] = uVar1;
  return 0;
}


// ===== 00494d80 cliresCtrlCmdNvdGetRcerrRpt_IMPL =====

int cliresCtrlCmdNvdGetRcerrRpt_IMPL(undefined8 param_1,ushort *param_2)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  ushort *puVar8;
  uint uVar9;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  long local_30 [2];
  
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  iVar3 = gpumgrGetGpuAttachInfo(&local_38,&local_3c);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"gpumgrGetGpuAttachInfo(&gpuAttachCount, &gpuMask)",
               "src/kernel/rmapi/client_resource.c",0x14e6);
    return iVar3;
  }
  lVar6 = gpumgrGetNextGpu(local_3c,&local_34);
  if (lVar6 == 0) {
    return 0x40;
  }
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[1] = ~*param_2;
  uVar4 = osGetCurrentProcess();
  *(undefined4 *)(param_2 + 0x10) = uVar4;
  iVar3 = krcCliresCtrlNvdGetRcerrRptCheckPermissions_KERNEL
                    (*(undefined8 *)(lVar6 + 0x1c18),param_1,param_2);
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar1 = *(undefined8 *)(g_pSys + 0x228);
  iVar3 = rcdbGetRcDiagRecBoundaries_IMPL
                    (uVar1,param_2 + 6,param_2 + 7,*(undefined4 *)(param_2 + 0xe),
                     *(undefined4 *)(param_2 + 0x10));
  if (iVar3 != 0) {
    return iVar3;
  }
  *(uint *)(param_2 + 10) = *(uint *)(param_2 + 10) | 4;
  iVar3 = rcdbGetRcDiagRec_IMPL
                    (uVar1,*param_2,local_30,*(undefined4 *)(param_2 + 0xe),
                     *(undefined4 *)(param_2 + 0x10));
  if (iVar3 != 0) {
    iVar2 = 0;
    if (iVar3 == 3) {
      iVar2 = 3;
    }
    return iVar2;
  }
  if (local_30[0] == 0) {
    return 0;
  }
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(local_30[0] + 4);
  param_2[1] = *(ushort *)(local_30[0] + 0x28);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(local_30[0] + 0x2c);
  param_2[8] = *(ushort *)(local_30[0] + 0x30);
  param_2[0xc] = *(ushort *)(local_30[0] + 0x38);
  uVar9 = *(uint *)(param_2 + 10) | *(uint *)(local_30[0] + 0x34);
  uVar5 = 0;
  *(uint *)(param_2 + 10) = uVar9;
  if (*(short *)(local_30[0] + 0x38) != 0) {
    do {
      uVar7 = (ulong)uVar5;
      uVar5 = uVar5 + 1;
      lVar6 = uVar7 * 0x10 + local_30[0];
      *(undefined4 *)(param_2 + uVar7 * 6 + 0x12) = *(undefined4 *)(lVar6 + 0x48);
      *(undefined4 *)(param_2 + uVar7 * 6 + 0x14) = *(undefined4 *)(lVar6 + 0x4c);
      *(undefined4 *)(param_2 + uVar7 * 6 + 0x16) = *(undefined4 *)(lVar6 + 0x50);
    } while (uVar5 < *(ushort *)(local_30[0] + 0x38));
    if (199 < uVar5) goto LAB_00494fe2;
  }
  puVar8 = param_2 + (ulong)uVar5 * 6 + 0x12;
  do {
    uVar5 = uVar5 + 1;
    puVar8[0] = 0;
    puVar8[1] = 0;
    puVar8[2] = 0;
    puVar8[3] = 0;
    puVar8[4] = 0;
    puVar8[5] = 0;
    puVar8 = puVar8 + 6;
  } while (uVar5 != 200);
LAB_00494fe2:
  *(uint *)(param_2 + 10) = uVar9 | 8;
  return 0;
}


// ===== 00494ff6 cliresCtrlCmdIdleChannels_IMPL.cold =====

void cliresCtrlCmdIdleChannels_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00495000 cliresCtrlCmdIdleChannels_IMPL =====

void cliresCtrlCmdIdleChannels_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = resservGetTlsCallContext();
  if (param_1 != 0) {
    RmIdleChannels(*(undefined4 *)(**(long **)(*(long *)(param_1 + 0xe0) + 0x48) + 0x48),*param_2,
                   param_2[1],param_2[2],*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6),
                   *(undefined8 *)(param_2 + 8),param_2[10],param_2[0xb],*(int *)(lVar2 + 0x2c) != 1
                  );
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00495070 cliresCtrlCmdSystemSyncExternalFabricMgmt_IMPL =====

undefined8 cliresCtrlCmdSystemSyncExternalFabricMgmt_IMPL(undefined8 param_1,undefined1 *param_2)

{
  *(undefined1 *)(g_pSys + 0x6b) = *param_2;
  return 0;
}


// ===== 00495090 cliresCtrlCmdSystemGetClientDatabaseInfo_IMPL =====

undefined8 cliresCtrlCmdSystemGetClientDatabaseInfo_IMPL(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = g_resServ._176_4_;
  *(undefined8 *)(param_2 + 2) = g_resServ._184_8_;
  return 0;
}


// ===== 004950b0 cliresCtrlCmdPushUcodeImage_IMPL =====

undefined8 cliresCtrlCmdPushUcodeImage_IMPL(void)

{
  return 0x56;
}


// ===== 004950c0 cliresCtrlCmdSystemRmctrlCacheModeCtrl_IMPL =====

undefined4 cliresCtrlCmdSystemRmctrlCacheModeCtrl_IMPL(undefined8 param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == 0) {
    iVar1 = rmapiControlCacheGetMode();
    param_2[1] = iVar1;
    return 0;
  }
  if (*param_2 == 1) {
    rmapiControlCacheSetMode(param_2[1]);
    return 0;
  }
  return 0x1f;
}


// ===== 00495120 cliresCtrlCmdSystemPfmreqhndlrGetPerfSensorCounters_IMPL =====

void cliresCtrlCmdSystemPfmreqhndlrGetPerfSensorCounters_IMPL(undefined8 param_1,undefined8 param_2)

{
  pfmreqhndlrGetPerfSensorCounters(param_2,0x1000);
  return;
}


// ===== 00495140 cliresCtrlCmdSystemPfmreqhndlrGetExtendedPerfSensorCounters_IMPL =====

void cliresCtrlCmdSystemPfmreqhndlrGetExtendedPerfSensorCounters_IMPL
               (undefined8 param_1,undefined8 param_2)

{
  pfmreqhndlrGetPerfSensorCounters(param_2,0);
  return;
}


// ===== 00495150 cliresCtrlCmdSystemGpsControl_IMPL =====

undefined8 cliresCtrlCmdSystemGpsControl_IMPL(void)

{
  return 0;
}


// ===== 00495160 cliresCtrlCmdSystemGpsBatchControl_IMPL =====

undefined8 cliresCtrlCmdSystemGpsBatchControl_IMPL(void)

{
  return 0;
}


// ===== 00495170 cliresCtrlCmdSystemGetPerfSensorCounters_IMPL =====

undefined8 cliresCtrlCmdSystemGetPerfSensorCounters_IMPL(void)

{
  return 0;
}


// ===== 00495180 cliresCtrlCmdSystemGetExtendedPerfSensorCounters_IMPL =====

undefined8 cliresCtrlCmdSystemGetExtendedPerfSensorCounters_IMPL(void)

{
  return 0;
}


// ===== 00495190 cliresCtrlCmdSystemGetVrrCookiePresent_IMPL =====

undefined8 cliresCtrlCmdSystemGetVrrCookiePresent_IMPL(undefined8 param_1,undefined8 param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined8 local_20 [2];
  
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20[0] = 0;
  gpumgrGetGpuAttachInfo(&local_2c,&local_28);
  uVar1 = gpumgrGetDefaultPrimaryGpu(local_28);
  lVar3 = gpumgrGetGpu(uVar1);
  if (lVar3 != 0) {
    iVar2 = getAcpiDsmObjectData(lVar3,local_20,&local_24,0xd,0x564b,0);
    *(bool *)param_2 = iVar2 == 2 && local_24 != 0;
    return 0;
  }
  return 0x3f;
}


// ===== 00495230 cliresCtrlCmdGpuGetVideoLinks_IMPL =====

undefined8 cliresCtrlCmdGpuGetVideoLinks_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    uVar2 = gpumgrGetSliLinks(param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/rmapi/client_resource_sli.c",0x32);
  return 0x2f;
}


// ===== 00495290 _rmControlDeferred =====

int _rmControlDeferred(undefined4 *param_1,long param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  bool bVar6;
  long local_68;
  uint local_60;
  undefined1 local_49;
  long local_48;
  undefined8 local_40 [2];
  
  if (0x80 < param_3) {
    nvDbg_Printf("src/kernel/rmapi/control.c",0x88,"_rmControlDeferred",3,
                 "NVRM: rmctrl param size (%d) larger than limit (%d).\n",param_3,0x80);
    return 0x1a;
  }
  iVar2 = serverGetClientUnderLock(g_resServ,*param_1,local_40);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = gpuGetByHandle(local_40[0],param_1[1],&local_49,&local_48);
  if (iVar2 != 0) {
    return iVar2;
  }
  *(undefined8 *)(param_1 + 0x16) = 0;
  *(long *)(param_1 + 8) = local_48;
  lVar1 = g_pSys;
  if (param_1[2] != 0x20800401) {
    return 3;
  }
  if ((*(byte *)(param_1 + 3) & 1) == 0) {
LAB_004954e0:
    iVar2 = 99;
  }
  else {
    LOCK();
    bVar6 = *(int *)(local_48 + 0x1e40) == 0;
    if (bVar6) {
      *(int *)(local_48 + 0x1e40) = 1;
    }
    UNLOCK();
    if (bVar6) {
      local_60 = 0;
      lVar5 = 0x1e40;
      lVar4 = 0x1e48;
      local_68 = 0;
    }
    else {
      LOCK();
      bVar6 = *(int *)(local_48 + 8000) == 0;
      if (bVar6) {
        *(int *)(local_48 + 8000) = 1;
      }
      UNLOCK();
      local_60 = (uint)bVar6;
      if (!bVar6) goto LAB_004954e0;
      local_68 = 0x100;
      lVar5 = 8000;
      lVar4 = 0x1f48;
    }
    portMemCopy(lVar4 + local_48,0x78,param_1,0x78);
    if ((param_3 != 0) && (param_2 != 0)) {
      local_68 = local_68 + 0x1ec0;
      portMemCopy(local_48 + local_68,(ulong)param_3,param_2);
      if (param_3 != 0x80) {
        portMemSet((ulong)param_3 + local_68 + local_48,0,0x80 - param_3);
      }
      *(long *)(local_48 + 0x1e58 + (ulong)local_60 * 0x100) = local_68 + local_48;
    }
    LOCK();
    *(undefined4 *)(local_48 + lVar5) = 2;
    UNLOCK();
    iVar3 = rmGpuLocksAcquire(1,0x200);
    iVar2 = 0;
    if (iVar3 == 0) {
      iVar2 = osCondAcquireRmSema(*(undefined8 *)(lVar1 + 0x160));
      if (iVar2 == 0) {
        osReleaseRmSema(*(undefined8 *)(lVar1 + 0x160),local_48);
      }
      rmGpuLocksRelease(0,local_48);
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ===== 00495540 rmControl_Deferred =====

int rmControl_Deferred(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined4 local_1f8 [2];
  undefined4 local_1f0;
  undefined1 *local_1e8;
  int local_1e0;
  undefined4 local_1dc;
  undefined8 local_1d8;
  undefined8 *local_1a0;
  undefined8 *local_198;
  undefined1 local_180 [128];
  undefined8 local_100 [30];
  
  local_238 = 0;
  local_230 = 0;
  local_228 = 0;
  local_220 = 0;
  local_218 = 0;
  local_210 = 0;
  local_208 = 0;
  local_200 = 0;
  uVar4 = 0;
  do {
    uVar2 = (int)uVar4 + 0x20;
    *(undefined8 *)((long)local_100 + uVar4) = 0;
    *(undefined8 *)((long)local_100 + uVar4 + 8) = 0;
    *(undefined8 *)((long)local_100 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)local_100 + uVar4 + 0x18) = 0;
    uVar4 = (ulong)uVar2;
  } while (uVar2 < 0xe0);
  *(undefined8 *)((long)local_100 + (ulong)uVar2) = 0;
  portMemCopy(local_1f8,0x78,param_1 + 2,0x78);
  local_1a0 = &local_238;
  local_198 = local_100;
  local_1dc = 0;
  local_1d8 = 0;
  local_210._0_4_ = 6;
  cVar1 = rmapiLockIsOwner();
  if (cVar1 == '\0') {
    local_210 = CONCAT44(local_210._4_4_,(undefined4)local_210) | 1;
  }
  else {
    local_210 = CONCAT44(1,(undefined4)local_210);
  }
  if ((local_1e8 != (undefined1 *)0x0) && (local_1e0 != 0)) {
    portMemSet(local_180,0,0x80);
    portMemCopy(local_180,local_1e0,local_1e8,local_1e0);
    local_1e8 = local_180;
  }
  portMemSet(param_1 + 0x20,0,0x80);
  LOCK();
  *param_1 = 0;
  UNLOCK();
  lVar5 = serverutilGetClientUnderLock(local_1f8[0]);
  if (lVar5 == 0) {
    iVar3 = 0x23;
  }
  else {
    iVar3 = serverControl(g_resServ,local_1f8);
    if (iVar3 == 0) {
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/rmapi/control.c",0x73,"rmControl_Deferred",2,
               "NVRM: deferred rmctrl %x failed %x!\n",local_1f0,iVar3);
  return iVar3;
}


// ===== 00495760 serverControlApiCopyIn =====

int serverControlApiCopyIn(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pCookie != NULL","src/kernel/rmapi/control.c",0xf8);
    return 0x1f;
  }
  uVar1 = *(undefined4 *)(param_2 + 0x18);
  uVar2 = *(undefined8 *)(param_2 + 0x10);
  *(char **)(param_3 + 0x38) = "serverControlApiCopyIn";
  *(undefined4 *)(param_3 + 0x28) = uVar1;
  *(long *)(param_3 + 0x20) = param_2 + 0x10;
  *(undefined8 *)(param_3 + 0x18) = uVar2;
  *(undefined1 *)(param_3 + 0x30) = 1;
  *(uint *)(param_3 + 0x2c) = -(uint)((*(uint *)(param_3 + 8) & 1) != 0) & 10;
  iVar3 = rmapiParamsAcquire(param_3 + 0x18,*(int *)(param_2 + 0x3c) == 0);
  if (iVar3 == 0) {
    *(undefined1 *)(param_3 + 0x10) = 1;
    iVar3 = embeddedParamCopyIn(param_3 + 0x48,param_2);
    if (iVar3 == 0) {
      *(undefined1 *)(param_3 + 0x40) = 1;
      return 0;
    }
    rmapiParamsRelease(param_3 + 0x18);
    *(undefined8 *)(param_2 + 0x10) = uVar2;
    *(undefined1 *)(param_3 + 0x10) = 0;
  }
  return iVar3;
}


// ===== 00495870 serverControlApiCopyOut =====

int serverControlApiCopyOut(undefined8 param_1,undefined4 *param_2,long param_3,int param_4)

{
  int iVar1;
  char cVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pCookie != NULL","src/kernel/rmapi/control.c",0x125);
    return 0x1f;
  }
  if (param_2 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pRmCtrlParams != NULL","src/kernel/rmapi/control.c",0x126);
    return 0x1f;
  }
  if ((*(uint *)(param_3 + 8) & 2) == 0) {
    uVar3 = *(undefined8 *)(param_3 + 0x18);
    cVar2 = *(char *)(param_3 + 0x10);
    if (param_4 == 0) goto LAB_00495950;
  }
  else {
    if (param_4 == 0) {
      rmapiControlCacheSet(*param_2,param_2[1],param_2[2],*(undefined8 *)(param_2 + 4),param_2[6]);
      uVar3 = *(undefined8 *)(param_3 + 0x18);
      cVar2 = *(char *)(param_3 + 0x10);
LAB_00495950:
      if (*(char *)(param_3 + 0x40) == '\0') {
        if (cVar2 == '\0') {
          return 0;
        }
        param_4 = rmapiParamsRelease(param_3 + 0x18);
      }
      else {
        param_4 = embeddedParamCopyOut(param_3 + 0x48,param_2);
        *(undefined1 *)(param_3 + 0x40) = 0;
        if (cVar2 == '\0') {
          return param_4;
        }
        iVar1 = rmapiParamsRelease(param_3 + 0x18);
        if (param_4 == 0) {
          param_4 = iVar1;
        }
      }
      goto LAB_00495923;
    }
    uVar3 = *(undefined8 *)(param_3 + 0x18);
    cVar2 = *(char *)(param_3 + 0x10);
  }
  if (((*(byte *)(param_3 + 5) & 8) == 0) || ((*(uint *)(param_3 + 8) & 4) != 0)) {
    *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) | 4;
    if (*(char *)(param_3 + 0x40) != '\0') {
      *(uint *)(param_3 + 0x5c) = *(uint *)(param_3 + 0x5c) | 4;
      *(uint *)(param_3 + 0x84) = *(uint *)(param_3 + 0x84) | 4;
      *(uint *)(param_3 + 0xac) = *(uint *)(param_3 + 0xac) | 4;
      *(uint *)(param_3 + 0xd4) = *(uint *)(param_3 + 0xd4) | 4;
      goto LAB_004958f9;
    }
  }
  else if (*(char *)(param_3 + 0x40) != '\0') {
LAB_004958f9:
    embeddedParamCopyOut(param_3 + 0x48,param_2);
    *(undefined1 *)(param_3 + 0x40) = 0;
  }
  if (cVar2 == '\0') {
    return param_4;
  }
  rmapiParamsRelease(param_3 + 0x18);
LAB_00495923:
  *(undefined8 *)(param_2 + 4) = uVar3;
  *(undefined1 *)(param_3 + 0x10) = 0;
  return param_4;
}


// ===== 00495a50 _rmapiRmControl =====

/* WARNING: Type propagation algorithm not settling */

int _rmapiRmControl(undefined4 param_1,undefined4 param_2,uint param_3,long param_4,uint param_5,
                   uint param_6,long param_7,uint *param_8)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  bool local_209;
  bool local_1fc;
  uint local_1ec;
  undefined4 local_1e8;
  uint local_1e4 [3];
  undefined8 local_1d8;
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  uint local_190;
  uint local_18c;
  long local_188;
  ulong local_180;
  long local_178;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 *local_140;
  undefined8 *local_138;
  bool local_130;
  undefined8 local_120;
  uint local_118 [2];
  undefined8 auStack_110 [28];
  
  lVar9 = g_pSys;
  uVar7 = 0;
  do {
    uVar4 = (int)uVar7 + 0x20;
    *(undefined8 *)((long)&local_120 + uVar7) = 0;
    *(undefined8 *)((long)local_118 + uVar7) = 0;
    *(undefined8 *)((long)auStack_110 + uVar7) = 0;
    *(undefined8 *)((long)auStack_110 + uVar7 + 8) = 0;
    uVar7 = (ulong)uVar4;
  } while (uVar4 < 0xe0);
  *(undefined8 *)((long)&local_120 + (ulong)uVar4) = 0;
  local_1d8 = 0;
  local_1d0 = 0;
  local_1c8 = 0;
  local_1c0 = 0;
  local_1b8 = 0;
  local_1b0 = 0;
  local_1a8 = 0;
  local_1a0 = 0;
  local_1ec = 0;
  local_1e8 = 0;
  local_1e4[0] = 0;
  if (param_3 == 0) {
    return 0;
  }
  if ((param_3 & 0x3fff) == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/rmapi/control.c",0x174,"_rmapiRmControl",1,
               "NVRM: rmControl: hClient 0x%x hObject 0x%x cmd 0x%x\n",param_1,param_2);
  nvDbg_Printf("src/kernel/rmapi/control.c",0x178,"_rmapiRmControl",1,
               "NVRM: rmControl: pUserParams 0x%p paramSize 0x%x\n",param_4,param_5);
  local_1fc = (bool)((byte)param_6 & 1);
  if (*(char *)(param_7 + 0xda) == '\0') {
    if ((param_6 & 2) == 0) {
      if (*(char *)(param_7 + 0xdc) == '\0') {
        bVar2 = false;
        local_209 = false;
        goto LAB_00495f7d;
      }
      if ((param_6 & 1) == 0) goto LAB_00495bf9;
LAB_00495e65:
      bVar1 = true;
      local_209 = local_1fc;
      bVar2 = true;
LAB_00495e86:
      cVar3 = rmapiRmControlCanBeRaisedIrql(param_3);
      if (cVar3 == '\0') {
        nvDbg_Printf("src/kernel/rmapi/control.c",0x18a,"_rmapiRmControl",3,
                     "NVRM: rmControl:  cmd 0x%x cannot be called at raised irq level\n",param_3);
        return 0x1f;
      }
      cVar3 = osIsRaisedIRQL();
      if (cVar3 == '\0') {
        nvDbg_Printf("src/kernel/rmapi/control.c",0x192,"_rmapiRmControl",3,
                     "NVRM: rmControl:  raised cmd 0x%x at normal irq level\n",param_3);
        return 0x1f;
      }
      if (bVar1) {
        local_1fc = true;
        goto LAB_0049606e;
      }
      lVar8 = serverutilGetClientUnderLock();
      if (lVar8 == 0) {
        return 0x23;
      }
      if (bVar2) {
        local_1fc = true;
        bVar1 = false;
        bVar2 = true;
        goto LAB_00495c2c;
      }
      local_1fc = true;
      bVar1 = false;
    }
    else {
      local_209 = *(char *)(param_7 + 0xdc) != '\0';
      bVar2 = local_209;
      if ((param_6 & 1) != 0) {
        bVar1 = true;
        goto LAB_00495e86;
      }
LAB_0049606e:
      if (bVar2) {
LAB_00495c04:
        param_6 = param_6 | 2;
        lVar8 = serverutilGetClientUnderLock(param_1);
        if (lVar8 == 0) {
          return 0x23;
        }
        bVar2 = true;
        bVar1 = true;
        goto LAB_00495c2c;
      }
      cVar3 = rmapiRmControlCanBeBypassLock(param_3);
      if (cVar3 == '\0') {
        nvDbg_Printf("src/kernel/rmapi/control.c",0x1a2,"_rmapiRmControl",3,
                     "NVRM: rmControl:  cmd 0x%x cannot bypass locks\n",param_3);
        return 0x1f;
      }
      lVar8 = serverutilGetClientUnderLock(param_1);
      if (lVar8 == 0) {
        return 0x23;
      }
      bVar1 = true;
      param_6 = param_6 | 2;
    }
    if (*param_8 < 2) {
      return 0x23;
    }
    bVar2 = false;
  }
  else if ((param_6 & 2) == 0) {
    if (*(char *)(param_7 + 0xdc) != '\0') {
      if ((param_6 & 1) != 0) goto LAB_00495e65;
LAB_00495bf9:
      local_209 = true;
      goto LAB_00495c04;
    }
    local_209 = true;
    bVar2 = true;
LAB_00495f7d:
    if ((param_6 & 1) != 0) {
      bVar1 = false;
      goto LAB_00495e86;
    }
    lVar8 = serverutilGetClientUnderLock(param_1,param_7,param_3);
    if (lVar8 == 0) {
      return 0x23;
    }
    bVar1 = false;
  }
  else {
    if ((param_6 & 1) != 0) goto LAB_00495e65;
    lVar8 = serverutilGetClientUnderLock(param_1,param_7,param_3);
    if (lVar8 == 0) {
      return 0x23;
    }
    local_209 = true;
    param_6 = param_6 | 2;
    bVar2 = true;
    bVar1 = true;
  }
LAB_00495c2c:
  iVar5 = rmapiutilGetControlInfo(param_3,&local_1ec,&local_1e8,local_1e4);
  if (((param_5 != 0) != (param_4 != 0)) || ((iVar5 == 0 && (local_1e4[0] != param_5)))) {
    nvDbg_Printf("src/kernel/rmapi/control.c",0x1c4,"_rmapiRmControl",1,
                 "NVRM: bad params: cmd:0x%x ptr %p size: 0x%x expect size: 0x%x\n",param_3,param_4,
                 param_5,local_1e4[0]);
    return 0x1f;
  }
  portMemSet(&local_198,0,0x78);
  local_180 = (ulong)param_5;
  local_160 = *(undefined8 *)param_8;
  local_178 = 0;
  local_168 = 0;
  local_158 = *(undefined8 *)(param_8 + 2);
  local_150 = *(undefined8 *)(param_8 + 4);
  local_148 = *(undefined8 *)(param_8 + 6);
  local_138 = &local_120;
  local_130 = local_209;
  if (*(char *)(param_7 + 0xda) != '\0') {
    local_1b0 = local_1b0 | 0x100000001;
  }
  local_120._4_4_ = local_1ec;
  local_198 = param_1;
  local_194 = param_2;
  local_190 = param_3;
  local_18c = param_6;
  local_188 = param_4;
  local_140 = &local_1d8;
  if (iVar5 == 0) {
    if ((local_1ec & 0x400) != 0) {
      local_118[0] = local_118[0] | 1;
    }
    if (bVar1) {
LAB_00495f14:
      local_1b0 = local_1b0 | 0x100000007;
      iVar5 = serverControl(g_resServ,&local_198);
      return iVar5;
    }
    if (local_1fc != false) {
LAB_004960d9:
      iVar5 = osCondAcquireRmSema(*(undefined8 *)(lVar9 + 0x160));
      if (iVar5 != 0) {
        iVar5 = _rmControlDeferred(&local_198,param_4,param_5);
        return iVar5;
      }
      iVar5 = rmGpuLocksAcquire(1,0x200);
      if (iVar5 == 0) {
        local_1b0 = local_1b0 | 0x200000007;
        iVar5 = serverControl(g_resServ,&local_198);
        cVar3 = osIsISR();
        lVar8 = 0;
        if (cVar3 != '\0') {
          lVar8 = local_178;
        }
        rmGpuLocksRelease(1,lVar8);
      }
      else {
        iVar5 = _rmControlDeferred(&local_198,param_4,param_5);
      }
      cVar3 = osIsISR();
      if ((cVar3 != '\0') && (local_178 == 0)) {
        nvAssertFailedNoLog("!osIsISR() || rmCtrlParams.pGpu","src/kernel/rmapi/control.c",0x21c);
      }
      cVar3 = osIsISR();
      lVar8 = 0;
      if (cVar3 != '\0') {
        lVar8 = local_178;
      }
      osReleaseRmSema(*(undefined8 *)(lVar9 + 0x160),lVar8);
      return iVar5;
    }
    cVar3 = rmapiControlIsCacheable(local_1ec,local_1e8,0);
    if (cVar3 != '\0') {
      *(uint *)(local_138 + 1) = *(uint *)(local_138 + 1) | 4;
      iVar5 = serverControlApiCopyIn(g_resServ,&local_198,local_138);
      if (iVar5 == 0) {
        uVar6 = rmapiControlCacheGet(param_1,param_2,param_3,local_188,param_5,param_8);
        iVar5 = serverControlApiCopyOut(g_resServ,&local_198,local_138,uVar6);
        if (iVar5 == 0) {
          return 0;
        }
      }
      portMemSet(local_138,0,0xe8);
      *(uint *)(local_138 + 1) = *(uint *)(local_138 + 1) | 2;
      if ((local_1ec & 0x400) != 0) {
        *(uint *)(local_138 + 1) = *(uint *)(local_138 + 1) | 1;
      }
    }
  }
  else {
    if (bVar1) goto LAB_00495f14;
    if (local_1fc != false) goto LAB_004960d9;
  }
  local_1e4[1] = 0;
  iVar5 = rmapiPrologue(param_7,local_1e4 + 1);
  if (iVar5 == 0) {
    if ((bVar2) && (lVar9 = resservGetTlsCallContext(), lVar9 != 0)) {
      local_1e4[2] = 0;
      if (((param_8[1] == 1) &&
          (iVar5 = serverControlLookupSecondClient(param_3,param_4,local_138,local_1e4 + 2),
          iVar5 != 0)) ||
         (iVar5 = rmapiInitLockInfo(param_7,param_1,local_1e4[2],&local_1d8), iVar5 != 0))
      goto LAB_004961dd;
      uVar4 = (uint)local_1b0;
      if (*(char *)(param_7 + 0xda) != '\0') {
        uVar4 = (uint)local_1b0 | 1;
      }
    }
    else {
      uVar4 = (uint)local_1b0;
    }
    local_1b0 = CONCAT44(local_1b0._4_4_,uVar4) | 0x10;
    iVar5 = serverControl(g_resServ,&local_198);
  }
LAB_004961dd:
  rmapiEpilogue(param_7,local_1e4 + 1);
  return iVar5;
}


// ===== 00496460 rmControlValidateClientPrivilegeAccess =====

uint rmControlValidateClientPrivilegeAccess
               (undefined4 param_1,undefined8 param_2,undefined8 param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  
  if ((param_4 & 4) == 0) {
    uVar1 = param_4 & 0x8c;
    if ((param_4 & 0x8c) != 0) {
      return 0;
    }
    if (*param_5 < 2) {
      nvDbg_Printf("src/kernel/rmapi/control.c",0x2bf,"rmControlValidateClientPrivilegeAccess",2,
                   "NVRM: hClient: 0x%08x, hObject 0x%08x, cmd 0x%08x: non-kernel client issued kernel-only cmd\n"
                   ,param_1,param_2,param_3);
      return 0x1b;
    }
  }
  else {
    uVar1 = 0;
    if (*param_5 == 0) {
      nvDbg_Printf("src/kernel/rmapi/control.c",0x2b3,"rmControlValidateClientPrivilegeAccess",2,
                   "NVRM: hClient: 0x%08x, hObject 0x%08x, cmd 0x%08x: non-privileged context issued privileged cmd\n"
                   ,param_1,param_2,param_3);
      return 0x1b;
    }
  }
  return uVar1;
}


// ===== 00496500 serverControl_ValidateCookie =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint serverControl_ValidateCookie(undefined4 *param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  
  lVar7 = resservGetTlsCallContext();
  if (lVar7 == 0) {
    nvDbg_Printf("src/kernel/rmapi/control.c",0x2d6,"serverControl_ValidateCookie",4,
                 "NVRM: Calling context is NULL!\n");
    return 0x3b;
  }
  if (g_resServ[0x43] == '\0') {
    if ((*(uint *)(param_2 + 4) & 0x20) != 0) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 4;
    }
  }
  else {
    puVar2 = *(undefined8 **)(param_1 + 0xc);
    if ((puVar2 != (undefined8 *)0x0) &&
       (uVar5 = rsAccessCheckRights(puVar2,*puVar2,param_2 + 0xc), uVar5 != 0)) {
      return uVar5;
    }
  }
  lVar1 = *(long *)(param_1 + 8);
  if (lVar1 != 0) {
    if ((*(char *)(lVar1 + 0x908) != '\0') && ((*(uint *)(param_2 + 4) & 0x40240) == 0x40)) {
      cVar3 = rmapiutilSkipErrorMessageForUnsupportedVgpuGuestControl(lVar1,param_1[2]);
      if (cVar3 == '\0') {
        nvDbg_Printf("src/kernel/rmapi/control.c",0x30c,"serverControl_ValidateCookie",4,
                     "NVRM: Unsupported ROUTE_TO_PHYSICAL control 0x%x was called on vGPU guest\n",
                     param_1[2]);
        return 0x56;
      }
      return 0x56;
    }
    uVar5 = (**(code **)(lVar1 + 0x2c8))();
    if (uVar5 != 0) {
      nvDbg_Printf("src/kernel/rmapi/control.c",0x318,"serverControl_ValidateCookie",3,
                   "NVRM: Control command 0x%x is not in allowlist\n",param_1[2]);
      return uVar5;
    }
  }
  if (((*(byte *)(param_2 + 4) & 0x80) != 0) && (*(char *)(param_1 + 0x1a) == '\0')) {
    return 0x56;
  }
  cVar3 = hypervisorIsVgxHyper_IMPL();
  if (cVar3 == '\0') {
    uVar5 = *(uint *)(param_2 + 4);
LAB_00496685:
    iVar6 = rmControlValidateClientPrivilegeAccess
                      (*param_1,param_1[1],param_1[2],uVar5,param_1 + 0xe);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (2,0x1b,
                 "rmControlValidateClientPrivilegeAccess(pRmCtrlParams->hClient, pRmCtrlParams->hObject, pRmCtrlParams->cmd, pRmCtrlExecuteCookie->ctrlFlags, &pRmCtrlParams->secInfo)"
                 ,"src/kernel/rmapi/control.c",0x33e);
      return 0x1b;
    }
    uVar5 = *(uint *)(param_2 + 4);
  }
  else {
    uVar4 = (**(code **)(**(long **)(lVar7 + 8) + 0x40))();
    cVar3 = (**(code **)(**(long **)(lVar7 + 8) + 0x48))(*(long **)(lVar7 + 8),uVar4);
    uVar5 = *(uint *)(param_2 + 4);
    if (((cVar3 == '\0') || (param_1[0xe] == 2)) || ((uVar5 & 8) != 0)) goto LAB_00496685;
    if (((uVar5 & 4) == 0) || (param_1[0xe] == 0)) {
      nvDbg_Printf("src/kernel/rmapi/control.c",0x335,"serverControl_ValidateCookie",2,
                   "NVRM: hClient: 0x%08x, hObject 0x%08x, cmd 0x%08x: non-privileged hypervisor context issued privileged cmd\n"
                   ,*param_1,param_1[1],param_1[2]);
      return 0x1b;
    }
  }
  if (((uVar5 & 2) == 0) && (*(long *)(param_1 + 8) != 0)) {
    cVar3 = gpuIsGpuFullPower_IMPL();
    lVar7 = *(long *)(param_1 + 8);
    if (cVar3 == '\0') {
      if (*(char *)(lVar7 + 0x444) != '\0') {
        if ((*(byte *)(param_2 + 5) & 0x10) == 0) goto LAB_0049688c;
        goto LAB_00496719;
      }
      if (*(char *)(lVar7 + 0x490a) == '\0') {
        return 0x11;
      }
      if (*(char *)(lVar7 + 0x44c) != '\0') {
        return 0x11;
      }
      if ((*(byte *)(param_2 + 5) & 0x10) == 0) {
LAB_0049688c:
        cVar3 = gpuCheckSysmemAccess_IMPL();
        if (cVar3 == '\0') {
          return 0x11;
        }
        lVar7 = *(long *)(param_1 + 8);
        goto LAB_00496714;
      }
    }
    else {
      if ((*(byte *)(param_2 + 5) & 0x10) == 0) goto LAB_0049688c;
LAB_00496714:
      if (lVar7 != 0) {
LAB_00496719:
        if ((*(char *)(lVar7 + 0x44c) != '\0') && (*(char *)(lVar7 + 0x450) == '\0'))
        goto LAB_00496730;
      }
    }
    uVar5 = 0xf;
  }
  else {
LAB_00496730:
    if (((*(byte *)(param_1 + 3) & 1) != 0) && (param_1[0xf] != 1)) {
      return 0x3b;
    }
    uVar5 = 0;
    if ((*(byte *)(param_2 + 6) & 0x10) != 0) {
      return -(uint)(*(char *)(g_pSys + 0x7e) == '\0') & 0x7e;
    }
  }
  return uVar5;
}


// ===== 004968b0 serverControlLookupLockFlags =====

undefined4
serverControlLookupLockFlags
          (undefined8 param_1,int param_2,long param_3,long param_4,undefined4 *param_5)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint local_2c [3];
  
  local_2c[0] = *(uint *)(param_4 + 4);
  if (local_2c[0] == 0) {
    iVar5 = rmapiutilGetControlInfo(*(undefined4 *)(param_3 + 8),local_2c,0);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/rmapi/control.c",0x375,"serverControlLookupLockFlags",1,
                   "NVRM: rmapiutilGetControlInfo(cmd=0x%x, out flags=0x%x, NULL) = status=0x%x\n",
                   *(undefined4 *)(param_3 + 8),local_2c[0]);
    }
    *(uint *)(param_4 + 4) = local_2c[0];
  }
  cVar4 = gpumgrAreAllGpusInOffloadMode();
  uVar6 = 0;
  if (cVar4 != '\0') {
    uVar6 = local_2c[0] >> 6 & 1;
  }
  if (param_5 == (undefined4 *)0x0) {
    return 0x1f;
  }
  *param_5 = 1;
  lVar3 = g_pSys;
  if (param_2 == 1) {
    if ((local_2c[0] & 0x400000) == 0) {
      cVar4 = serverSupportsReadOnlyLock(g_resServ,1,9);
      uVar7 = 0;
      if (cVar4 != '\0') {
        if ((local_2c[0] & 0x100) != 0) {
          *param_5 = 0;
        }
        if ((g_resServ[0x42] != '\0') && (uVar6 != 0)) {
          *param_5 = 0;
        }
        if (*(char *)(lVar3 + 0x7f) == '\0') {
          return 0;
        }
        if (*(int *)(param_3 + 8) != 0x20801342) {
          return 0;
        }
      }
      *param_5 = 1;
    }
    else {
      if ((local_2c[0] & 1) == 0) {
        nvAssertFailedNoLog("((controlFlags & RMCTRL_FLAGS_NO_GPUS_LOCK) != 0)",
                            "src/kernel/rmapi/control.c",0x397);
      }
      else {
        if ((local_2c[0] & 0x100) == 0) {
          puVar1 = (uint *)(*(long *)(param_3 + 0x58) + 0x28);
          *puVar1 = *puVar1 | 1;
          return 0;
        }
        nvAssertFailedNoLog("((controlFlags & RMCTRL_FLAGS_API_LOCK_READONLY) == 0)",
                            "src/kernel/rmapi/control.c",0x39b);
      }
      uVar7 = 0x2f;
    }
  }
  else {
    uVar7 = 0x56;
    if (param_2 == 2) {
      lVar3 = *(long *)(param_3 + 0x58);
      uVar2 = *(uint *)(lVar3 + 0x28);
      if ((((*(byte *)(lVar3 + 0x2c) & 2) != 0) || ((local_2c[0] & 1) != 0)) ||
         ((*(uint *)(param_3 + 0xc) & 3) != 0)) {
        *(uint *)(lVar3 + 0x28) = uVar2 & 0xfffffff7 | 4;
        return 0;
      }
      if (((local_2c[0] & 0x10) == 0) && ((g_resServ[0x42] == '\0' || (uVar6 == 0)))) {
        uVar7 = 0;
        *(uint *)(lVar3 + 0x28) = uVar2 & 0xfffffff3;
      }
      else {
        *(uint *)(lVar3 + 0x28) = uVar2 | 0xc;
        uVar7 = 0;
      }
    }
  }
  return uVar7;
}


// ===== 00496b20 serverControlLookupClientLockFlags =====

undefined8 serverControlLookupClientLockFlags(long param_1,undefined4 *param_2)

{
  char cVar1;
  
  if ((*(uint *)(param_1 + 4) & 0x200000) == 0) {
    *param_2 = 0;
    return 0;
  }
  *param_2 = 1;
  cVar1 = rmapiLockIsWriteOwner();
  if (cVar1 != '\0') {
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsWriteOwner()","src/kernel/rmapi/control.c",0x3f9);
  return 0x2f;
}


// ===== 00496b80 rmapiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] rmapiControl(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  
  if (*(char *)(param_1 + 0xd8) != '\0') {
    auVar1._0_8_ = (**(code **)(param_1 + 0x40))();
    auVar1._8_8_ = 0;
    return auVar1;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = 0x56;
  return auVar2;
}


// ===== 00496bc0 rmapiControlWithSecInfo =====

int rmapiControlWithSecInfo
              (undefined8 param_1,undefined4 param_2,ulong param_3,ulong param_4,undefined8 param_5,
              ulong param_6,undefined4 param_7)

{
  int iVar1;
  undefined8 uVar2;
  
  nvDbg_Printf("src/kernel/rmapi/control.c",0x422,"rmapiControlWithSecInfo",1,
               "NVRM: Nv04Control: hClient:0x%x hObject:0x%x cmd:0x%x params:%p paramSize:0x%x flags:0x%x\n"
               ,param_2,param_3,param_4,param_5,param_6,param_7);
  iVar1 = _rmapiRmControl(param_2,param_3 & 0xffffffff,param_4 & 0xffffffff,param_5,
                          param_6 & 0xffffffff,param_7);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/rmapi/control.c",0x42a,"rmapiControlWithSecInfo",1,
                 "NVRM: Nv04Control: control complete\n");
  }
  else {
    uVar2 = nvstatusToString(iVar1);
    nvDbg_Printf("src/kernel/rmapi/control.c",0x42e,"rmapiControlWithSecInfo",1,
                 "NVRM: Nv04Control: control failed; status: %s (0x%08x)\n",uVar2,iVar1);
    nvDbg_Printf("src/kernel/rmapi/control.c",0x431,"rmapiControlWithSecInfo",1,
                 "NVRM: Nv04Control:  hClient:0x%x hObject:0x%x cmd:0x%x params:%p paramSize:0x%x flags:0x%x\n"
                 ,param_2,param_3 & 0xffffffff,param_4 & 0xffffffff,param_5,param_6 & 0xffffffff,
                 param_7);
  }
  return iVar1;
}


// ===== 00496d00 _rmapiControlWithSecInfoTlsIRQL =====

undefined4
_rmapiControlWithSecInfoTlsIRQL
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 local_4b8 [144];
  undefined1 local_428 [1032];
  
  uVar2 = portMemAllocatorCreateOnExistingBlock(local_428,0x400);
  tlsIsrInit(uVar2);
  threadStateInit(local_4b8,0);
  uVar1 = rmapiControlWithSecInfo(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  threadStateFree(local_4b8,0);
  tlsIsrDestroy(uVar2);
  portMemAllocatorRelease(uVar2);
  return uVar1;
}


// ===== 00496dc0 rmapiControlWithSecInfoTls =====

undefined1  [16]
rmapiControlWithSecInfoTls
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8)

{
  char cVar1;
  undefined1 auVar2 [16];
  undefined1 local_c8 [152];
  
  cVar1 = portMemExSafeForNonPagedAlloc();
  if (cVar1 != '\0') {
    threadStateInit(local_c8,0);
    auVar2._0_4_ = rmapiControlWithSecInfo(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    auVar2._4_4_ = 0;
    threadStateFree(local_c8,0);
    auVar2._8_8_ = param_8;
    return auVar2;
  }
  auVar2 = _rmapiControlWithSecInfoTlsIRQL(param_1,param_2,param_3,param_4,param_5,param_6);
  return auVar2;
}


// ===== 00496ea0 _rmAllocForDeprecatedApi =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void _rmAllocForDeprecatedApi(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x68) + 0x10))(*(long *)(param_1 + 0x68));
  return;
}


// ===== 00496ed0 _rmControlForDeprecatedApi =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void _rmControlForDeprecatedApi(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x68) + 0x40))(*(long *)(param_1 + 0x68));
  return;
}


// ===== 00496f00 _rmFreeForDeprecatedApi =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void _rmFreeForDeprecatedApi(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x68) + 0x20))();
  return;
}


// ===== 00496f20 _rmMapMemoryForDeprecatedApi =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void _rmMapMemoryForDeprecatedApi(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x68) + 0x78))(*(long *)(param_1 + 0x68));
  return;
}


// ===== 00496f50 _rmAllocMemForDeprecatedApi =====

void _rmAllocMemForDeprecatedApi(undefined4 param_1)

{
  portMemAllocNonPaged(param_1);
  return;
}


// ===== 00496f60 _rmFreeMemForDeprecatedApi =====

void _rmFreeMemForDeprecatedApi(void)

{
  portMemFree();
  return;
}


// ===== 00496f70 RmCopyUserForDeprecatedApi =====

ulong RmCopyUserForDeprecatedApi
                (int param_1,int param_2,undefined8 param_3,ulong param_4,long *param_5,
                undefined1 param_6)

{
  ulong uVar1;
  long lVar2;
  
  if (param_1 == 1) {
    uVar1 = rmapiParamsCopyOut(0,*param_5,param_3,param_4,param_6);
  }
  else {
    if (param_1 != 2) {
      if (param_1 != 0) {
        return 0;
      }
      if (param_2 != 1) {
        uVar1 = rmapiParamsCopyIn(0,*param_5,param_3,param_4,param_6);
        return uVar1;
      }
      lVar2 = portMemAllocNonPaged(param_4 & 0xffffffff);
      *param_5 = lVar2;
      if (lVar2 == 0) {
        return 0x51;
      }
      uVar1 = rmapiParamsCopyIn(0,lVar2,param_3,param_4 & 0xffffffff,param_6);
      if ((int)uVar1 == 0) {
        return uVar1;
      }
      goto LAB_00496fdb;
    }
    uVar1 = 0;
  }
  if (param_2 != 1) {
    return uVar1;
  }
LAB_00496fdb:
  portMemFree(*param_5);
  *param_5 = 0;
  return uVar1 & 0xffffffff;
}


// ===== 00497060 _rmCopyUserForDeprecatedApi =====

void _rmCopyUserForDeprecatedApi
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined8 param_6)

{
  RmCopyUserForDeprecatedApi
            (param_2,param_3,param_4,param_5,param_6,*(undefined1 *)(param_1 + 0x61));
  return;
}


// ===== 00497080 rmapiInitDeprecatedContext =====

void rmapiInitDeprecatedContext(undefined8 *param_1,undefined8 *param_2,char param_3,char param_4)

{
  char cVar1;
  undefined8 uVar2;
  
  if (param_2 == (undefined8 *)0x0) {
    portMemSet(param_1 + 8,0,0x20);
    if (param_3 == '\0') {
      *(undefined4 *)(param_1 + 8) = 2;
    }
    else {
      cVar1 = osIsAdministrator();
      *(uint *)(param_1 + 8) = (uint)(cVar1 != '\0');
    }
  }
  else {
    param_1[8] = *param_2;
    param_1[9] = param_2[1];
    param_1[10] = param_2[2];
    param_1[0xb] = param_2[3];
  }
  *(undefined4 *)((long)param_1 + 0x44) = 1;
  *(char *)(param_1 + 0xc) = param_4;
  uVar2 = rmapiGetInterface((ulong)(param_4 != '\0') << 2);
  *(char *)((long)param_1 + 0x61) = param_3;
  param_1[0xd] = uVar2;
  *param_1 = _rmAllocForDeprecatedApi;
  param_1[1] = _rmControlForDeprecatedApi;
  param_1[2] = _rmFreeForDeprecatedApi;
  param_1[3] = _rmMapMemoryForDeprecatedApi;
  param_1[4] = _rmCopyUserForDeprecatedApi;
  param_1[5] = _rmAllocMemForDeprecatedApi;
  param_1[6] = _rmFreeMemForDeprecatedApi;
  return;
}


// ===== 00497170 embeddedParamCopyIn =====

int embeddedParamCopyIn(undefined8 *param_1,long param_2)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined8 *puVar7;
  int iVar8;
  undefined8 *local_48;
  int local_3c;
  
  if ((*(int *)(param_2 + 0x3c) == 1) || ((*(uint *)(param_2 + 0xc) & 4) != 0)) {
    return 0;
  }
  uVar4 = *(uint *)(param_2 + 8);
  puVar2 = *(uint **)(param_2 + 0x10);
  if (uVar4 == 0x20800610) {
    if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x28)) {
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_I2C_ACCESS_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x29b);
      return 0x1f;
    }
    param_1[4] = "embeddedParamCopyIn";
    param_1[1] = puVar2 + 4;
    uVar5 = *(undefined8 *)(puVar2 + 4);
    *(undefined4 *)((long)param_1 + 0x14) = 0;
    *param_1 = uVar5;
    uVar4 = puVar2[7];
    *(undefined1 *)(param_1 + 3) = 1;
    *(uint *)(param_1 + 2) = uVar4;
  }
  else if (uVar4 < 0x20800611) {
    if (uVar4 == 0x801401) {
      if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_HOST_GET_CAPS_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x161);
        return 0x1f;
      }
LAB_004974d2:
      param_1[4] = "embeddedParamCopyIn";
      param_1[1] = puVar2 + 2;
      uVar5 = *(undefined8 *)(puVar2 + 2);
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = *puVar2;
      *(undefined1 *)(param_1 + 3) = 1;
      *(uint *)(param_1 + 2) = uVar4;
      *(undefined4 *)((long)param_1 + 0x14) = 10;
    }
    else if (uVar4 < 0x801402) {
      if (uVar4 == 0x730120) {
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x28)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0073_CTRL_SYSTEM_EXECUTE_ACPI_METHOD_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x14c);
          return 0x1f;
        }
LAB_0049721e:
        param_1[4] = "embeddedParamCopyIn";
        param_1[1] = puVar2 + 2;
        uVar5 = *(undefined8 *)(puVar2 + 2);
        *(undefined4 *)((long)param_1 + 0x14) = 0;
        *param_1 = uVar5;
        uVar4 = puVar2[4];
        *(undefined1 *)(param_1 + 3) = 1;
        *(uint *)(param_1 + 2) = (uint)(ushort)uVar4;
        *(undefined4 *)((long)param_1 + 0x14) = 4;
        param_1[9] = "embeddedParamCopyIn";
        param_1[6] = puVar2 + 6;
        uVar5 = *(undefined8 *)(puVar2 + 6);
        *(undefined4 *)((long)param_1 + 0x3c) = 0;
        param_1[5] = uVar5;
        uVar4 = puVar2[8];
        *(undefined1 *)(param_1 + 8) = 1;
        *(uint *)(param_1 + 7) = (uint)(ushort)uVar4;
        *(undefined4 *)((long)param_1 + 0x3c) = 10;
LAB_004973f9:
        local_3c = 2;
        goto LAB_00497517;
      }
      if (uVar4 < 0x730121) {
        if (uVar4 == 0x602) {
          if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0000_CTRL_NVD_GET_DUMP_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x215);
            return 0x1f;
          }
LAB_00497577:
          param_1[4] = "embeddedParamCopyIn";
          param_1[1] = puVar2;
          uVar5 = *(undefined8 *)puVar2;
          *(undefined4 *)((long)param_1 + 0x14) = 0;
          *param_1 = uVar5;
          uVar4 = puVar2[3];
          *(undefined1 *)(param_1 + 3) = 1;
          *(uint *)(param_1 + 2) = uVar4;
          *(undefined4 *)((long)param_1 + 0x14) = 10;
          goto LAB_00497510;
        }
        if (uVar4 < 0x603) {
          if (uVar4 != 0x127) {
            if (uVar4 != 0x130) {
              return 0;
            }
            if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x28)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0000_CTRL_SYSTEM_EXECUTE_ACPI_METHOD_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x137);
              return 0x1f;
            }
            goto LAB_0049721e;
          }
          if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0xb0)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0000_CTRL_SYSTEM_GET_P2P_CAPS_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x24c);
            return 0x1f;
          }
          if (*(long *)(puVar2 + 0x28) == 0) {
            param_1[1] = puVar2 + 0x28;
            iVar8 = 0;
            bVar6 = true;
            param_1[4] = "embeddedParamCopyIn";
            uVar5 = *(undefined8 *)(puVar2 + 0x28);
          }
          else {
            uVar4 = puVar2[0x20];
            param_1[1] = puVar2 + 0x28;
            bVar6 = true;
            param_1[4] = "embeddedParamCopyIn";
            uVar5 = *(undefined8 *)(puVar2 + 0x28);
            uVar4 = uVar4 * uVar4;
            iVar8 = 0;
            if (uVar4 != 0) {
              iVar8 = uVar4 * 4;
              bVar6 = uVar4 >> 0x1e == 0;
            }
          }
          *(bool *)(param_1 + 3) = bVar6;
          *param_1 = uVar5;
          *(int *)(param_1 + 2) = iVar8;
          *(undefined4 *)((long)param_1 + 0x14) = 2;
          if (*(long *)(puVar2 + 0x2a) == 0) {
            param_1[9] = "embeddedParamCopyIn";
            iVar8 = 0;
            param_1[6] = puVar2 + 0x2a;
            uVar5 = *(undefined8 *)(puVar2 + 0x2a);
            bVar6 = true;
          }
          else {
            uVar4 = puVar2[0x20];
            param_1[9] = "embeddedParamCopyIn";
            param_1[6] = puVar2 + 0x2a;
            uVar5 = *(undefined8 *)(puVar2 + 0x2a);
            bVar6 = true;
            uVar4 = uVar4 * uVar4;
            iVar8 = 0;
            if (uVar4 != 0) {
              iVar8 = uVar4 * 4;
              bVar6 = uVar4 >> 0x1e == 0;
            }
          }
          param_1[5] = uVar5;
          *(int *)(param_1 + 7) = iVar8;
          *(bool *)(param_1 + 8) = bVar6;
          *(undefined4 *)((long)param_1 + 0x3c) = 2;
          goto LAB_004973f9;
        }
        if (uVar4 != 0x410110) {
          return 0;
        }
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0041_CTRL_GET_SURFACE_INFO_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x222);
          return 0x1f;
        }
      }
      else {
        if (uVar4 != 0x801104) {
          if (uVar4 < 0x801105) {
            if (uVar4 == 0x800201) {
              if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
                nvCheckFailedNoLog(3,
                                   "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_GPU_GET_CLASSLIST_PARAMS))"
                                   ,"src/kernel/rmapi/embedded_param_copy.c",0x27a);
                return 0x1f;
              }
              goto LAB_00497d20;
            }
            if (uVar4 != 0x801102) {
              return 0;
            }
            if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_GR_GET_CAPS_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x28e);
              return 0x1f;
            }
          }
          else {
            if (uVar4 != 0x801301) {
              return 0;
            }
            if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_FB_GET_CAPS_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x26d);
              return 0x1f;
            }
          }
          goto LAB_004974d2;
        }
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_GR_GET_INFO_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x193);
          return 0x1f;
        }
      }
LAB_004976a0:
      param_1[4] = "embeddedParamCopyIn";
      param_1[1] = puVar2 + 2;
      uVar5 = *(undefined8 *)(puVar2 + 2);
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = *puVar2;
      *(uint *)(param_1 + 2) = uVar4 * 8;
      *(bool *)(param_1 + 3) = uVar4 >> 0x1d == 0;
    }
    else if (uVar4 == 0x20800123) {
      if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_GET_ENGINES_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0xf5);
        return 0x1f;
      }
LAB_00497d20:
      param_1[4] = "embeddedParamCopyIn";
      param_1[1] = puVar2 + 2;
      uVar5 = *(undefined8 *)(puVar2 + 2);
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = *puVar2;
      *(uint *)(param_1 + 2) = uVar4 * 4;
      *(bool *)(param_1 + 3) = uVar4 >> 0x1e == 0;
    }
    else if (uVar4 < 0x20800124) {
      if (uVar4 == 0x80180f) {
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x40)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_DMA_UPDATE_PDE_2_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x2d6);
          return 0x1f;
        }
        param_1[4] = "embeddedParamCopyIn";
        param_1[1] = puVar2 + 0xc;
        uVar5 = *(undefined8 *)(puVar2 + 0xc);
        *(undefined1 *)(param_1 + 3) = 1;
        *param_1 = uVar5;
        param_1[2] = 0xa00000010;
      }
      else {
        if (uVar4 < 0x801810) {
          if (uVar4 != 0x801701) {
            if (uVar4 != 0x80170d) {
              return 0;
            }
            if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x18)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x125);
              return 0x1f;
            }
            param_1[4] = "embeddedParamCopyIn";
            param_1[1] = puVar2 + 2;
            uVar5 = *(undefined8 *)(puVar2 + 2);
            *(undefined4 *)((long)param_1 + 0x14) = 0;
            *param_1 = uVar5;
            uVar4 = *puVar2;
            *(undefined4 *)((long)param_1 + 0x14) = 4;
            param_1[9] = "embeddedParamCopyIn";
            *(bool *)(param_1 + 3) = uVar4 >> 0x1e == 0;
            *(uint *)(param_1 + 2) = uVar4 * 4;
            param_1[6] = puVar2 + 4;
            uVar5 = *(undefined8 *)(puVar2 + 4);
            *(undefined4 *)((long)param_1 + 0x3c) = 0;
            param_1[5] = uVar5;
            uVar4 = *puVar2;
            *(uint *)(param_1 + 7) = uVar4 * 4;
            *(bool *)(param_1 + 8) = uVar4 >> 0x1e == 0;
            goto LAB_004973f9;
          }
          if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_FIFO_GET_CAPS_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x19e);
            return 0x1f;
          }
          goto LAB_004974d2;
        }
        if (uVar4 != 0x20800122) {
          return 0;
        }
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x30)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_EXEC_REG_OPS_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x1fd);
          return 0x1f;
        }
        param_1[4] = "embeddedParamCopyIn";
        param_1[1] = puVar2 + 6;
        uVar5 = *(undefined8 *)(puVar2 + 6);
        *(undefined4 *)((long)param_1 + 0x14) = 0;
        *param_1 = uVar5;
        uVar4 = puVar2[5];
        *(uint *)(param_1 + 2) = uVar4 << 5;
        *(bool *)(param_1 + 3) = uVar4 >> 0x1b == 0;
      }
    }
    else if (uVar4 == 0x2080016e) {
      if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_INFO_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0xe8);
        return 0x1f;
      }
      param_1[4] = "embeddedParamCopyIn";
      param_1[1] = puVar2 + 2;
      uVar5 = *(undefined8 *)(puVar2 + 2);
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = *puVar2;
      *(undefined4 *)((long)param_1 + 0x14) = 2;
      *(uint *)(param_1 + 2) = uVar4 << 5;
      *(bool *)(param_1 + 3) = uVar4 >> 0x1b == 0;
    }
    else {
      if (uVar4 == 0x208001e8) {
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x20)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_RPC_GSP_TEST_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x2e5);
          return 0x1f;
        }
        param_1[4] = "embeddedParamCopyIn";
        param_1[1] = puVar2 + 6;
        uVar5 = *(undefined8 *)(puVar2 + 6);
      }
      else {
        if (uVar4 != 0x20800124) {
          return 0;
        }
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x284);
          return 0x1f;
        }
        param_1[4] = "embeddedParamCopyIn";
        param_1[1] = puVar2 + 2;
        uVar5 = *(undefined8 *)(puVar2 + 2);
      }
      *param_1 = uVar5;
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      uVar4 = puVar2[1];
      *(uint *)(param_1 + 2) = uVar4 * 4;
      *(bool *)(param_1 + 3) = uVar4 >> 0x1e == 0;
    }
  }
  else if (uVar4 == 0x402c0105) {
    if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x60)) {
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV402C_CTRL_I2C_TRANSACTION_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x1f2);
      return 0x1f;
    }
    uVar4 = puVar2[3];
    if (uVar4 == 6) {
LAB_00497f75:
      param_1[4] = "_i2cTransactionCopyIn";
      param_1[1] = puVar2 + 6;
      uVar5 = *(undefined8 *)(puVar2 + 6);
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = puVar2[5];
      *(undefined1 *)(param_1 + 3) = 1;
      *(uint *)(param_1 + 2) = uVar4;
      cVar1 = (char)puVar2[4];
joined_r0x00497fa9:
      if (cVar1 == '\x01') {
LAB_00497faf:
        *(undefined4 *)((long)param_1 + 0x14) = 4;
        goto LAB_00497510;
      }
    }
    else {
      if (uVar4 < 7) {
        if (uVar4 == 2) goto LAB_00497f75;
        if (uVar4 != 3) {
          return 0;
        }
        param_1[4] = "_i2cTransactionCopyIn";
        param_1[1] = puVar2 + 8;
        uVar5 = *(undefined8 *)(puVar2 + 8);
        *(undefined4 *)((long)param_1 + 0x14) = 0;
        *param_1 = uVar5;
        uVar4 = puVar2[7];
        *(undefined1 *)(param_1 + 3) = 1;
        *(uint *)(param_1 + 2) = uVar4;
        cVar1 = (char)puVar2[4];
        goto joined_r0x00497fa9;
      }
      if (uVar4 == 9) {
        param_1[4] = "_i2cTransactionCopyIn";
        param_1[1] = puVar2 + 10;
        uVar5 = *(undefined8 *)(puVar2 + 10);
        *(undefined4 *)((long)param_1 + 0x14) = 0;
        *param_1 = uVar5;
        uVar4 = puVar2[8];
        *(undefined1 *)(param_1 + 3) = 1;
        *(uint *)(param_1 + 2) = uVar4;
        if ((char)puVar2[4] != '\x01') goto LAB_00497c09;
        goto LAB_00497faf;
      }
      if (uVar4 != 10) {
        return 0;
      }
      param_1[4] = "_i2cTransactionCopyIn";
      param_1[1] = puVar2 + 6;
      uVar5 = *(undefined8 *)(puVar2 + 6);
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = puVar2[5];
      *(undefined1 *)(param_1 + 3) = 1;
      *(uint *)(param_1 + 2) = uVar4;
    }
LAB_00497c09:
    *(undefined4 *)((long)param_1 + 0x14) = 2;
  }
  else if (uVar4 < 0x402c0106) {
    if (uVar4 == 0x20802204) {
      if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x20)) {
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_RC_READ_VIRTUAL_MEM_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x2c9);
        return 0x1f;
      }
    }
    else {
      if (0x20802204 < uVar4) {
        if (uVar4 == 0x20802a01) {
          if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_CE_GET_CAPS_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x118);
            return 0x1f;
          }
          param_1[4] = "embeddedParamCopyIn";
          param_1[1] = puVar2 + 2;
          uVar5 = *(undefined8 *)(puVar2 + 2);
          *(undefined4 *)((long)param_1 + 0x14) = 0;
          *param_1 = uVar5;
          uVar4 = puVar2[1];
          *(undefined1 *)(param_1 + 3) = 1;
          *(uint *)(param_1 + 2) = uVar4;
          *(undefined4 *)((long)param_1 + 0x14) = 10;
        }
        else {
          if (uVar4 != 0x402c0102) {
            if (uVar4 != 0x20802402) {
              return 0;
            }
            if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_NVD_GET_DUMP_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x208);
              return 0x1f;
            }
            goto LAB_00497577;
          }
          if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x20)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV402C_CTRL_I2C_INDEXED_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x1e8);
            return 0x1f;
          }
          param_1[4] = "embeddedParamCopyIn";
          param_1[1] = puVar2 + 6;
          uVar5 = *(undefined8 *)(puVar2 + 6);
          *(undefined4 *)((long)param_1 + 0x14) = 0;
          *param_1 = uVar5;
          uVar4 = puVar2[4];
          *(undefined1 *)(param_1 + 3) = 1;
          *(uint *)(param_1 + 2) = uVar4;
        }
        goto LAB_00497510;
      }
      if (uVar4 != 0x20800806) {
        if (uVar4 < 0x20800807) {
          if (uVar4 != 0x20800802) {
            if (uVar4 != 0x20800803) {
              return 0;
            }
            if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x428)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_BIOS_GET_NBSI_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x179);
              return 0x1f;
            }
            param_1[4] = "embeddedParamCopyIn";
            param_1[1] = puVar2 + 0x106;
            uVar5 = *(undefined8 *)(puVar2 + 0x106);
            *(undefined4 *)((long)param_1 + 0x14) = 0;
            *param_1 = uVar5;
            uVar4 = puVar2[0x108];
            *(undefined1 *)(param_1 + 3) = 1;
            *(uint *)(param_1 + 2) = uVar4;
            *(undefined4 *)((long)param_1 + 0x14) = 10;
            goto LAB_00497510;
          }
          if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_BIOS_GET_INFO_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x16e);
            return 0x1f;
          }
        }
        else {
          if (uVar4 != 0x20801201) {
            return 0;
          }
          if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x20)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GR_GET_INFO_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x2a5);
            return 0x1f;
          }
        }
        goto LAB_004976a0;
      }
      if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x28)) {
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_BIOS_GET_NBSI_OBJ_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x186);
        return 0x1f;
      }
    }
    param_1[4] = "embeddedParamCopyIn";
    param_1[1] = puVar2 + 4;
    uVar5 = *(undefined8 *)(puVar2 + 4);
    *(undefined4 *)((long)param_1 + 0x14) = 0;
    *param_1 = uVar5;
    uVar4 = puVar2[6];
    *(undefined1 *)(param_1 + 3) = 1;
    *(uint *)(param_1 + 2) = uVar4;
    *(undefined4 *)((long)param_1 + 0x14) = 10;
  }
  else if (uVar4 == 0xa0830103) {
    if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVA083_CTRL_VIRTUAL_DISPLAY_GET_DEFAULT_EDID_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x22d);
      return 0x1f;
    }
    param_1[4] = "embeddedParamCopyIn";
    param_1[1] = puVar2;
    uVar5 = *(undefined8 *)puVar2;
    *(undefined4 *)((long)param_1 + 0x14) = 0;
    *param_1 = uVar5;
    uVar4 = puVar2[2];
    *(undefined1 *)(param_1 + 3) = 1;
    *(uint *)(param_1 + 2) = uVar4;
    *(undefined4 *)((long)param_1 + 0x14) = 10;
  }
  else if (uVar4 < 0xa0830104) {
    if (uVar4 == 0x83de0326) {
      if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0xe20)) {
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_ACCESS_MEMORY_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x1cf);
        return 0x1f;
      }
      param_1[4] = "embeddedParamCopyIn";
      param_1[1] = puVar2;
      uVar5 = *(undefined8 *)puVar2;
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = puVar2[2];
      *(undefined1 *)(param_1 + 3) = 1;
      *(uint *)(param_1 + 2) = uVar4;
      *(undefined4 *)((long)param_1 + 0x14) = 0x1a;
    }
    else if (uVar4 < 0x83de0327) {
      if (uVar4 == 0x83de0315) {
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x18)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_READ_MEMORY_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x1b6);
          return 0x1f;
        }
        param_1[4] = "embeddedParamCopyIn";
        param_1[1] = puVar2 + 4;
        uVar5 = *(undefined8 *)(puVar2 + 4);
        *(undefined4 *)((long)param_1 + 0x14) = 0;
        *param_1 = uVar5;
        uVar4 = puVar2[1];
        *(undefined1 *)(param_1 + 3) = 1;
        *(uint *)(param_1 + 2) = uVar4;
        *(undefined4 *)((long)param_1 + 0x14) = 0x1a;
      }
      else {
        if (uVar4 != 0x83de0316) {
          return 0;
        }
        if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x18)) {
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_WRITE_MEMORY_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x1c3);
          return 0x1f;
        }
        param_1[4] = "embeddedParamCopyIn";
        param_1[1] = puVar2 + 4;
        uVar5 = *(undefined8 *)(puVar2 + 4);
        *(undefined4 *)((long)param_1 + 0x14) = 0;
        *param_1 = uVar5;
        uVar4 = puVar2[1];
        *(undefined1 *)(param_1 + 3) = 1;
        *(uint *)(param_1 + 2) = uVar4;
        *(undefined4 *)((long)param_1 + 0x14) = 0x14;
      }
    }
    else {
      if (uVar4 != 0x83de0327) {
        return 0;
      }
      if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0xe20)) {
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_ACCESS_MEMORY_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x1dc);
        return 0x1f;
      }
      param_1[4] = "embeddedParamCopyIn";
      param_1[1] = puVar2;
      uVar5 = *(undefined8 *)puVar2;
      *(undefined4 *)((long)param_1 + 0x14) = 0;
      *param_1 = uVar5;
      uVar4 = puVar2[2];
      *(undefined1 *)(param_1 + 3) = 1;
      *(uint *)(param_1 + 2) = uVar4;
      *(undefined4 *)((long)param_1 + 0x14) = 0x14;
    }
  }
  else if (uVar4 == 0xb06f010c) {
    if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVB06F_CTRL_GET_ENGINE_CTX_DATA_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",700);
      return 0x1f;
    }
    param_1[4] = "embeddedParamCopyIn";
    param_1[1] = puVar2 + 2;
    uVar5 = *(undefined8 *)(puVar2 + 2);
    *(undefined4 *)((long)param_1 + 0x14) = 0;
    *param_1 = uVar5;
    uVar4 = puVar2[1];
    *(undefined1 *)(param_1 + 3) = 1;
    *(uint *)(param_1 + 2) = uVar4;
    *(undefined4 *)((long)param_1 + 0x14) = 0x12;
  }
  else if (uVar4 == 0xb06f010d) {
    if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVB06F_CTRL_MIGRATE_ENGINE_CTX_DATA_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x2b0);
      return 0x1f;
    }
    param_1[4] = "embeddedParamCopyIn";
    param_1[1] = puVar2 + 2;
    uVar5 = *(undefined8 *)(puVar2 + 2);
    *(undefined4 *)((long)param_1 + 0x14) = 0;
    *param_1 = uVar5;
    uVar4 = puVar2[1];
    *(undefined1 *)(param_1 + 3) = 1;
    *(uint *)(param_1 + 2) = uVar4;
    *(undefined4 *)((long)param_1 + 0x14) = 0x10;
  }
  else {
    if (uVar4 != 0xa0bc0101) {
      return 0;
    }
    if ((puVar2 == (uint *)0x0) || (*(int *)(param_2 + 0x18) != 0x20)) {
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVA0BC_CTRL_NVENC_SW_SESSION_UPDATE_INFO_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x1ab);
      return 0x1f;
    }
    param_1[4] = "embeddedParamCopyIn";
    param_1[1] = puVar2 + 6;
    uVar5 = *(undefined8 *)(puVar2 + 6);
    *(undefined4 *)((long)param_1 + 0x14) = 0;
    *param_1 = uVar5;
    uVar4 = puVar2[4];
    *(uint *)(param_1 + 2) = uVar4 << 4;
    *(bool *)(param_1 + 3) = uVar4 >> 0x1c == 0;
  }
LAB_00497510:
  local_3c = 1;
LAB_00497517:
  iVar8 = 0;
  puVar7 = param_1;
  do {
    iVar3 = rmapiParamsAcquire(puVar7,*(int *)(param_2 + 0x3c) != 1);
    if (iVar3 != 0) {
      local_48 = param_1;
      do {
        *(uint *)((long)local_48 + 0x14) = *(uint *)((long)local_48 + 0x14) | 4;
        rmapiParamsRelease(local_48);
        local_48 = local_48 + 5;
      } while (local_48 != (undefined8 *)((long)param_1 + (ulong)(-iVar8 & 0x28) + 0x28));
      return iVar3;
    }
    iVar8 = iVar8 + 1;
    puVar7 = puVar7 + 5;
  } while (local_3c != iVar8);
  return 0;
}


// ===== 004983b0 embeddedParamCopyOut =====

ulong embeddedParamCopyOut(undefined8 *param_1,long param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  
  if ((*(int *)(param_2 + 0x3c) == 1) || ((*(uint *)(param_2 + 0xc) & 4) != 0)) {
    return 0;
  }
  uVar2 = *(uint *)(param_2 + 8);
  puVar1 = *(undefined8 **)(param_2 + 0x10);
  if (uVar2 == 0x20800610) {
    if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x28)) {
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_I2C_ACCESS_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x442);
      return 0x1f;
    }
LAB_004986f9:
    uVar3 = rmapiParamsRelease(param_1);
    puVar1[2] = *param_1;
    return uVar3;
  }
  if (uVar2 < 0x20800611) {
    if (uVar2 == 0x801401) {
      if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049866d;
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_HOST_GET_CAPS_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x394);
    }
    else {
      if (uVar2 < 0x801402) {
        if (uVar2 == 0x730120) {
          if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x28)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0073_CTRL_SYSTEM_EXECUTE_ACPI_METHOD_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x366);
            return 0x1f;
          }
LAB_0049844b:
          uVar2 = rmapiParamsRelease(param_1);
          puVar1[1] = *param_1;
          uVar3 = rmapiParamsRelease(param_1 + 5);
          puVar1[3] = param_1[5];
          uVar3 = uVar3 & 0xffffffff;
          if (uVar2 != 0) {
            uVar3 = (ulong)uVar2;
          }
          return uVar3;
        }
        if (uVar2 < 0x730121) {
          if (uVar2 == 0x602) {
            if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0000_CTRL_NVD_GET_DUMP_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x3ef);
              return 0x1f;
            }
            goto LAB_0049875b;
          }
          if (uVar2 < 0x603) {
            if (uVar2 == 0x127) {
              if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0xb0)) {
                uVar2 = rmapiParamsRelease();
                puVar1[0x14] = *param_1;
                uVar3 = rmapiParamsRelease(param_1 + 5);
                uVar3 = uVar3 & 0xffffffff;
                if (uVar2 != 0) {
                  uVar3 = (ulong)uVar2;
                }
                puVar1[0x15] = param_1[5];
                return uVar3;
              }
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0000_CTRL_SYSTEM_GET_P2P_CAPS_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x413);
              return 0x1f;
            }
            if (uVar2 != 0x130) {
              return 0;
            }
            if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x28)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0000_CTRL_SYSTEM_EXECUTE_ACPI_METHOD_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x358);
              return 0x1f;
            }
            goto LAB_0049844b;
          }
          if (uVar2 != 0x410110) {
            return 0;
          }
          if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0041_CTRL_GET_SURFACE_INFO_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x3f7);
            return 0x1f;
          }
        }
        else if (uVar2 == 0x801104) {
          if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_GR_GET_INFO_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x3b9);
            return 0x1f;
          }
        }
        else if (uVar2 < 0x801105) {
          if (uVar2 == 0x800201) {
            if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_GPU_GET_CLASSLIST_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x42a);
              return 0x1f;
            }
          }
          else {
            if (uVar2 != 0x801102) {
              return 0;
            }
            if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
              nvCheckFailedNoLog(3,
                                 "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_GR_GET_CAPS_PARAMS))"
                                 ,"src/kernel/rmapi/embedded_param_copy.c",0x43a);
              return 0x1f;
            }
          }
        }
        else {
          if (uVar2 != 0x801301) {
            return 0;
          }
          if ((puVar1 == (undefined8 *)0x0) || (*(int *)(param_2 + 0x18) != 0x10)) {
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_FB_GET_CAPS_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x422);
            return 0x1f;
          }
        }
LAB_0049866d:
        uVar3 = rmapiParamsRelease(param_1);
        puVar1[1] = *param_1;
        return uVar3;
      }
      if (uVar2 == 0x20800123) {
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049866d;
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_GET_ENGINES_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x325);
      }
      else if (uVar2 < 0x20800124) {
        if (uVar2 == 0x80180f) {
          if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x40)) {
            uVar3 = rmapiParamsRelease();
            puVar1[6] = *param_1;
            return uVar3;
          }
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_DMA_UPDATE_PDE_2_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x46a);
        }
        else if (uVar2 < 0x801810) {
          if (uVar2 == 0x801701) {
            if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10))
            goto LAB_0049866d;
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_FIFO_GET_CAPS_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x3c1);
          }
          else {
            if (uVar2 != 0x80170d) {
              return 0;
            }
            if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x18)) {
              uVar2 = rmapiParamsRelease();
              puVar1[1] = *param_1;
              uVar3 = rmapiParamsRelease(param_1 + 5);
              uVar3 = uVar3 & 0xffffffff;
              if (uVar2 != 0) {
                uVar3 = (ulong)uVar2;
              }
              puVar1[2] = param_1[5];
              return uVar3;
            }
            nvCheckFailedNoLog(3,
                               "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV0080_CTRL_FIFO_GET_CHANNELLIST_PARAMS))"
                               ,"src/kernel/rmapi/embedded_param_copy.c",0x349);
          }
        }
        else {
          if (uVar2 != 0x20800122) {
            return 0;
          }
          if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x30)) {
LAB_004988aa:
            uVar3 = rmapiParamsRelease(param_1);
            puVar1[3] = *param_1;
            return uVar3;
          }
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_EXEC_REG_OPS_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x3df);
        }
      }
      else if (uVar2 == 0x2080016e) {
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049866d;
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_GET_NVENC_SW_SESSION_INFO_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x31d);
      }
      else if (uVar2 == 0x208001e8) {
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x20)) goto LAB_004988aa;
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_RPC_GSP_TEST_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x474);
      }
      else {
        if (uVar2 != 0x20800124) {
          return 0;
        }
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049866d;
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GPU_GET_ENGINE_CLASSLIST_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x432);
      }
    }
  }
  else if (uVar2 == 0x402c0105) {
    if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x60)) {
      uVar2 = *(uint *)((long)puVar1 + 0xc);
      if (uVar2 != 6) {
        if (uVar2 < 7) {
          if (uVar2 != 2) {
            if (uVar2 != 3) {
              return 0;
            }
            uVar3 = rmapiParamsRelease();
            puVar1[4] = *param_1;
            return uVar3;
          }
        }
        else {
          if (uVar2 == 9) {
            uVar3 = rmapiParamsRelease();
            puVar1[5] = *param_1;
            return uVar3;
          }
          if (uVar2 != 10) {
            return 0;
          }
        }
      }
      goto LAB_004988aa;
    }
    nvCheckFailedNoLog(3,
                       "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV402C_CTRL_I2C_TRANSACTION_PARAMS))"
                       ,"src/kernel/rmapi/embedded_param_copy.c",0x3d9);
  }
  else if (uVar2 < 0x402c0106) {
    if (uVar2 == 0x20802204) {
      if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x20)) goto LAB_004984ed;
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_RC_READ_VIRTUAL_MEM_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x462);
    }
    else if (uVar2 < 0x20802205) {
      if (uVar2 == 0x20800806) {
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x28)) {
          if (*(int *)(puVar1 + 3) == 0) {
            *(uint *)((long)param_1 + 0x14) = *(uint *)((long)param_1 + 0x14) | 4;
          }
          goto LAB_004986f9;
        }
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_BIOS_GET_NBSI_OBJ_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x3ac);
      }
      else if (uVar2 < 0x20800807) {
        if (uVar2 == 0x20800802) {
          if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10))
          goto LAB_0049866d;
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_BIOS_GET_INFO_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x39c);
        }
        else {
          if (uVar2 != 0x20800803) {
            return 0;
          }
          if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x428)) {
            uVar3 = rmapiParamsRelease();
            puVar1[0x83] = *param_1;
            return uVar3;
          }
          nvCheckFailedNoLog(3,
                             "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_BIOS_GET_NBSI_PARAMS))"
                             ,"src/kernel/rmapi/embedded_param_copy.c",0x3a4);
        }
      }
      else {
        if (uVar2 != 0x20801201) {
          return 0;
        }
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x20)) goto LAB_0049866d;
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_GR_GET_INFO_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x44a);
      }
    }
    else if (uVar2 == 0x20802a01) {
      if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049866d;
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_CE_GET_CAPS_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x341);
    }
    else if (uVar2 == 0x402c0102) {
      if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x20)) goto LAB_004988aa;
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV402C_CTRL_I2C_INDEXED_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x3d1);
    }
    else {
      if (uVar2 != 0x20802402) {
        return 0;
      }
      if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049875b;
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV2080_CTRL_NVD_GET_DUMP_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",999);
    }
  }
  else if (uVar2 == 0xa0830103) {
    if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) {
LAB_0049875b:
      uVar3 = rmapiParamsRelease(param_1);
      *puVar1 = *param_1;
      return uVar3;
    }
    nvCheckFailedNoLog(3,
                       "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVA083_CTRL_VIRTUAL_DISPLAY_GET_DEFAULT_EDID_PARAMS))"
                       ,"src/kernel/rmapi/embedded_param_copy.c",0x3ff);
  }
  else if (uVar2 < 0xa0830104) {
    if (uVar2 == 0x83de0326) {
      if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0xe20)) {
LAB_004986a6:
        uVar3 = rmapiParamsRelease(param_1);
        **(undefined8 **)(param_2 + 0x10) = *param_1;
        return uVar3;
      }
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_ACCESS_MEMORY_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",900);
    }
    else if (uVar2 < 0x83de0327) {
      if (uVar2 == 0x83de0315) {
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x18)) goto LAB_004984ed;
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_READ_MEMORY_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x374);
      }
      else {
        if (uVar2 != 0x83de0316) {
          return 0;
        }
        if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x18)) {
LAB_004984ed:
          uVar3 = rmapiParamsRelease(param_1);
          *(undefined8 *)(*(long *)(param_2 + 0x10) + 0x10) = *param_1;
          return uVar3;
        }
        nvCheckFailedNoLog(3,
                           "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_WRITE_MEMORY_PARAMS))"
                           ,"src/kernel/rmapi/embedded_param_copy.c",0x37c);
      }
    }
    else {
      if (uVar2 != 0x83de0327) {
        return 0;
      }
      if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0xe20)) goto LAB_004986a6;
      nvCheckFailedNoLog(3,
                         "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NV83DE_CTRL_DEBUG_ACCESS_MEMORY_PARAMS))"
                         ,"src/kernel/rmapi/embedded_param_copy.c",0x38c);
    }
  }
  else if (uVar2 == 0xb06f010c) {
    if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049866d;
    nvCheckFailedNoLog(3,
                       "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVB06F_CTRL_GET_ENGINE_CTX_DATA_PARAMS))"
                       ,"src/kernel/rmapi/embedded_param_copy.c",0x45a);
  }
  else if (uVar2 == 0xb06f010d) {
    if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x10)) goto LAB_0049866d;
    nvCheckFailedNoLog(3,
                       "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVB06F_CTRL_MIGRATE_ENGINE_CTX_DATA_PARAMS))"
                       ,"src/kernel/rmapi/embedded_param_copy.c",0x452);
  }
  else {
    if (uVar2 != 0xa0bc0101) {
      return 0;
    }
    if ((puVar1 != (undefined8 *)0x0) && (*(int *)(param_2 + 0x18) == 0x20)) goto LAB_004988aa;
    nvCheckFailedNoLog(3,
                       "(((pRmCtrlParams)->pParams != NULL) && ((pRmCtrlParams)->paramsSize) == sizeof(NVA0BC_CTRL_NVENC_SW_SESSION_UPDATE_INFO_PARAMS))"
                       ,"src/kernel/rmapi/embedded_param_copy.c",0x3c9);
  }
  return 0x1f;
}


// ===== 00499020 _nv04ControlWithSecInfo.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong _nv04ControlWithSecInfo_constprop_0(undefined4 *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  ulong uVar3;
  long lVar4;
  undefined1 local_88 [120];
  
  pcVar2 = (code *)RmDeprecatedGetControlHandler();
  if (pcVar2 != (code *)0x0) {
    rmapiInitDeprecatedContext(local_88,&stack0x00000008,0,0);
    uVar3 = (*pcVar2)(&stack0x00000008,local_88,param_1);
    param_1[7] = (int)uVar3;
    return uVar3;
  }
  lVar4 = rmapiGetInterface(0);
  uVar3 = (ulong)(uint)param_1[3];
  uVar1 = (**(code **)(lVar4 + 0x40))
                    (lVar4,*param_1,param_1[1],param_1[2],*(undefined8 *)(param_1 + 4),param_1[6],
                     uVar3,&stack0x00000008);
  param_1[7] = uVar1;
  return uVar3;
}


// ===== 004990b0 _nv04AllocWithAccess =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nv04AllocWithAccess(undefined4 *param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  uint local_48;
  uint local_44;
  
  lVar3 = rmapiGetInterface(0);
  portMemSet(&local_48,0,0x20);
  local_48 = 2;
  if (param_2 == '\x01') {
    cVar1 = osIsAdministrator();
    local_48 = (uint)(cVar1 != '\0');
  }
  local_44 = (uint)(param_2 != '\x01');
  uVar2 = (**(code **)(lVar3 + 0x10))
                    (lVar3,*param_1,param_1[1],param_1 + 2,param_1[3],*(undefined8 *)(param_1 + 4),
                     param_1[8],param_1[9] * 2 & 2,*(undefined8 *)(param_1 + 6),&local_48);
  param_1[10] = uVar2;
  return;
}


// ===== 00499150 _nv01Free =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nv01Free(undefined4 *param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  uint local_48;
  uint local_44;
  
  lVar3 = rmapiGetInterface(0);
  portMemSet(&local_48,0,0x20);
  local_48 = 2;
  if (param_2 == '\x01') {
    cVar1 = osIsAdministrator();
    local_48 = (uint)(cVar1 != '\0');
  }
  local_44 = (uint)(param_2 != '\x01');
  uVar2 = (**(code **)(lVar3 + 0x20))(lVar3,*param_1,param_1[2],0,&local_48);
  param_1[3] = uVar2;
  return;
}


// ===== 004991d0 _nv04Share =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nv04Share(undefined4 *param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  uint local_48;
  uint local_44;
  
  lVar3 = rmapiGetInterface(0);
  portMemSet(&local_48,0,0x20);
  local_48 = 2;
  if (param_2 == '\x01') {
    cVar1 = osIsAdministrator();
    local_48 = (uint)(cVar1 != '\0');
  }
  local_44 = (uint)(param_2 != '\x01');
  uVar2 = (**(code **)(lVar3 + 0x68))(lVar3,*param_1,param_1[1],param_1 + 2,&local_48);
  param_1[5] = uVar2;
  return;
}


// ===== 00499250 _nv04DupObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 _nv04DupObject(undefined4 *param_1,char param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  long lVar4;
  uint local_48;
  uint local_44;
  
  lVar4 = rmapiGetInterface(0);
  portMemSet(&local_48,0,0x20);
  local_48 = 2;
  if (param_2 == '\x01') {
    cVar2 = osIsAdministrator();
    local_48 = (uint)(cVar2 != '\0');
  }
  local_44 = (uint)(param_2 != '\x01');
  uVar1 = param_1[5];
  uVar3 = (**(code **)(lVar4 + 0x58))(lVar4,*param_1,param_1[1],param_1 + 2,param_1[3],param_1[4]);
  param_1[6] = uVar3;
  return uVar1;
}


// ===== 004992e0 _nv04UnmapMemory.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined1  [16] _nv04UnmapMemory_constprop_0(undefined4 *param_1,char param_2)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  char cVar3;
  undefined4 uVar4;
  long lVar5;
  undefined8 uVar6;
  uint local_48;
  uint local_44;
  
  lVar5 = rmapiGetInterface(0);
  portMemSet(&local_48,0,0x20);
  local_48 = 2;
  if (param_2 == '\x01') {
    cVar3 = osIsAdministrator();
    local_48 = (uint)(cVar3 != '\0');
  }
  local_44 = (uint)(param_2 != '\x01');
  pcVar1 = *(code **)(lVar5 + 0x90);
  uVar6 = osGetCurrentProcess();
  uVar4 = (*pcVar1)(lVar5,*param_1,param_1[1],param_1[2],*(undefined8 *)(param_1 + 4),param_1[7]);
  param_1[6] = uVar4;
  auVar2._8_8_ = &local_48;
  auVar2._0_8_ = uVar6;
  return auVar2;
}


// ===== 00499380 _nv04MapMemory.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _nv04MapMemory_constprop_0(undefined4 *param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  uint local_48;
  uint local_44;
  
  lVar3 = rmapiGetInterface(0);
  portMemSet(&local_48,0,0x20);
  local_48 = 2;
  if (param_2 == '\x01') {
    cVar1 = osIsAdministrator();
    local_48 = (uint)(cVar1 != '\0');
  }
  local_44 = (uint)(param_2 != '\x01');
  uVar2 = (**(code **)(lVar3 + 0x78))
                    (lVar3,*param_1,param_1[1],param_1[2],*(undefined8 *)(param_1 + 4),
                     *(undefined8 *)(param_1 + 6),param_1 + 8,param_1[0xb],&local_48);
  param_1[10] = uVar2;
  return;
}


// ===== 00499420 Nv01AllocMemoryKernel =====

void Nv01AllocMemoryKernel(undefined8 param_1)

{
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,0,0,0);
  RmDeprecatedAllocMemory(local_88,param_1);
  return;
}


// ===== 00499460 Nv01FreeKernel =====

void Nv01FreeKernel(undefined8 param_1)

{
  _nv01Free(param_1,0);
  return;
}


// ===== 00499470 Nv04AddVblankCallbackKernel =====

void Nv04AddVblankCallbackKernel(undefined8 param_1)

{
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,0,0,0);
  RmDeprecatedAddVblankCallback(local_88,param_1);
  return;
}


// ===== 004994b0 Nv04AllocWithAccessKernel =====

void Nv04AllocWithAccessKernel(undefined8 param_1)

{
  _nv04AllocWithAccess(param_1,0);
  return;
}


// ===== 004994c0 Nv04AllocContextDmaKernel =====

void Nv04AllocContextDmaKernel(undefined8 param_1)

{
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,0,0,0);
  RmDeprecatedAllocContextDma(local_88,param_1);
  return;
}


// ===== 00499500 Nv04BindContextDmaKernel =====

void Nv04BindContextDmaKernel(undefined8 param_1)

{
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,0,0,0);
  RmDeprecatedBindContextDma(local_88,param_1);
  return;
}


// ===== 00499540 Nv04ControlKernel =====

void Nv04ControlKernel(undefined8 param_1)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  portMemSet(&local_38,0,0x20);
  local_38 = 0x100000002;
  _nv04ControlWithSecInfo_constprop_0(param_1);
  return;
}


// ===== 004995b0 Nv04DupObjectKernel =====

void Nv04DupObjectKernel(undefined8 param_1)

{
  _nv04DupObject(param_1,0);
  return;
}


// ===== 004995c0 Nv04ShareKernel =====

void Nv04ShareKernel(undefined8 param_1)

{
  _nv04Share(param_1,0);
  return;
}


// ===== 004995d0 Nv04MapMemoryKernel =====

void Nv04MapMemoryKernel(undefined8 param_1)

{
  _nv04MapMemory_constprop_0(param_1,0);
  return;
}


// ===== 004995e0 Nv04MapMemoryDmaKernel =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void Nv04MapMemoryDmaKernel(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 local_38 [4];
  
  lVar2 = rmapiGetInterface(0);
  portMemSet(local_38,0,0x20);
  local_38[0] = 0x100000002;
  uVar1 = (**(code **)(lVar2 + 0xa0))(lVar2,param_1,local_38);
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  return;
}


// ===== 00499640 Nv04UnmapMemoryKernel =====

void Nv04UnmapMemoryKernel(undefined8 param_1)

{
  _nv04UnmapMemory_constprop_0(param_1,0);
  return;
}


// ===== 00499650 Nv04UnmapMemoryDmaKernel =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void Nv04UnmapMemoryDmaKernel(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 local_38 [4];
  
  lVar2 = rmapiGetInterface(0);
  portMemSet(local_38,0,0x20);
  local_38[0] = 0x100000002;
  uVar1 = (**(code **)(lVar2 + 0xb0))(lVar2,param_1,local_38);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  return;
}


// ===== 004996b0 Nv04VidHeapControlKernel =====

void Nv04VidHeapControlKernel(undefined8 param_1)

{
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,0,0,0);
  RmDeprecatedVidHeapControl(local_88,param_1);
  return;
}


// ===== 004996f0 Nv01AllocMemoryWithSecInfo =====

void Nv01AllocMemoryWithSecInfo(undefined8 param_1)

{
  undefined8 in_stack_00000008;
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,&stack0x00000008,in_stack_00000008._4_4_ != 1,0);
  RmDeprecatedAllocMemory(local_88,param_1);
  return;
}


// ===== 00499730 Nv01AllocObjectWithSecInfo =====

void Nv01AllocObjectWithSecInfo(undefined8 param_1)

{
  undefined8 in_stack_00000008;
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,&stack0x00000008,in_stack_00000008._4_4_ != 1,0);
  RmDeprecatedAllocObject(local_88,param_1);
  return;
}


// ===== 00499770 Nv04AllocWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void Nv04AllocWithSecInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = in_stack_00000008;
  local_30 = in_stack_00000010;
  local_28 = in_stack_00000018;
  local_20 = in_stack_00000020;
  lVar2 = rmapiGetInterface(0);
  uVar1 = (**(code **)(lVar2 + 0x10))
                    (lVar2,*param_1,param_1[1],param_1 + 2,param_1[3],*(undefined8 *)(param_1 + 4),
                     param_1[6],0,0,&local_38);
  param_1[7] = uVar1;
  return;
}


// ===== 004997e0 Nv04AllocWithAccessSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void Nv04AllocWithAccessSecInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = in_stack_00000008;
  local_30 = in_stack_00000010;
  local_28 = in_stack_00000018;
  local_20 = in_stack_00000020;
  lVar2 = rmapiGetInterface(0);
  uVar1 = (**(code **)(lVar2 + 0x10))
                    (lVar2,*param_1,param_1[1],param_1 + 2,param_1[3],*(undefined8 *)(param_1 + 4),
                     param_1[8],param_1[9] * 2 & 2,*(undefined8 *)(param_1 + 6),&local_38);
  param_1[10] = uVar1;
  return;
}


// ===== 00499860 Nv01FreeWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void Nv01FreeWithSecInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = in_stack_00000008;
  local_30 = in_stack_00000010;
  local_28 = in_stack_00000018;
  local_20 = in_stack_00000020;
  lVar2 = rmapiGetInterface(0);
  uVar1 = (**(code **)(lVar2 + 0x20))
                    (lVar2,*param_1,param_1[2],0,&local_38,*(code **)(lVar2 + 0x20));
  param_1[3] = uVar1;
  return;
}


// ===== 004998c0 Nv04ControlWithSecInfo =====

void Nv04ControlWithSecInfo(void)

{
  _nv04ControlWithSecInfo_constprop_0();
  return;
}


// ===== 004998d0 Nv04VidHeapControlWithSecInfo =====

void Nv04VidHeapControlWithSecInfo(undefined8 param_1)

{
  undefined8 in_stack_00000008;
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,&stack0x00000008,in_stack_00000008._4_4_ != 1,0);
  RmDeprecatedVidHeapControl(local_88,param_1);
  return;
}


// ===== 00499910 Nv04IdleChannelsWithSecInfo =====

void Nv04IdleChannelsWithSecInfo(undefined8 param_1)

{
  undefined8 in_stack_00000008;
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,&stack0x00000008,in_stack_00000008._4_4_ != 1,0);
  RmDeprecatedIdleChannels(local_88,param_1);
  return;
}


// ===== 00499950 Nv04MapMemoryWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void Nv04MapMemoryWithSecInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = in_stack_00000008;
  local_30 = in_stack_00000010;
  local_28 = in_stack_00000018;
  local_20 = in_stack_00000020;
  lVar2 = rmapiGetInterface(0);
  uVar1 = (**(code **)(lVar2 + 0x80))
                    (lVar2,*param_1,param_1[1],param_1[2],*(undefined8 *)(param_1 + 4),
                     *(undefined8 *)(param_1 + 6),param_1 + 8,param_1 + 0xb,&local_38);
  param_1[10] = uVar1;
  return;
}


// ===== 004999d0 Nv04UnmapMemoryWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

undefined1  [16] Nv04UnmapMemoryWithSecInfo(undefined4 *param_1)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined4 uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_48 = in_stack_00000008;
  local_40 = in_stack_00000010;
  local_38 = in_stack_00000018;
  local_30 = in_stack_00000020;
  lVar4 = rmapiGetInterface(0);
  pcVar1 = *(code **)(lVar4 + 0x90);
  uVar5 = osGetCurrentProcess();
  uVar3 = (*pcVar1)(lVar4,*param_1,param_1[1],param_1[2],*(undefined8 *)(param_1 + 4),param_1[7]);
  param_1[6] = uVar3;
  auVar2._8_8_ = &local_48;
  auVar2._0_8_ = uVar5;
  return auVar2;
}


// ===== 00499a50 Nv04I2CAccessWithSecInfo =====

void Nv04I2CAccessWithSecInfo(undefined8 param_1)

{
  undefined8 in_stack_00000008;
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,&stack0x00000008,in_stack_00000008._4_4_ != 1,0);
  RmDeprecatedI2CAccess(local_88,param_1);
  return;
}


// ===== 00499a90 Nv04AllocContextDmaWithSecInfo =====

void Nv04AllocContextDmaWithSecInfo(undefined8 param_1)

{
  undefined8 in_stack_00000008;
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,&stack0x00000008,in_stack_00000008._4_4_ != 1,0);
  RmDeprecatedAllocContextDma(local_88,param_1);
  return;
}


// ===== 00499ad0 Nv04BindContextDmaWithSecInfo =====

void Nv04BindContextDmaWithSecInfo(undefined8 param_1)

{
  undefined8 in_stack_00000008;
  undefined1 local_88 [120];
  
  rmapiInitDeprecatedContext(local_88,&stack0x00000008,in_stack_00000008._4_4_ != 1,0);
  RmDeprecatedBindContextDma(local_88,param_1);
  return;
}


// ===== 00499b10 Nv04MapMemoryDmaWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void Nv04MapMemoryDmaWithSecInfo(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = in_stack_00000008;
  local_30 = in_stack_00000010;
  local_28 = in_stack_00000018;
  local_20 = in_stack_00000020;
  lVar2 = rmapiGetInterface(0);
  uVar1 = (**(code **)(lVar2 + 0xa0))(lVar2,param_1,&local_38,*(code **)(lVar2 + 0xa0));
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  return;
}


// ===== 00499b70 Nv04UnmapMemoryDmaWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void Nv04UnmapMemoryDmaWithSecInfo(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = in_stack_00000008;
  local_30 = in_stack_00000010;
  local_28 = in_stack_00000018;
  local_20 = in_stack_00000020;
  lVar2 = rmapiGetInterface(0);
  uVar1 = (**(code **)(lVar2 + 0xb0))(lVar2,param_1,&local_38,*(code **)(lVar2 + 0xb0));
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  return;
}


// ===== 00499bd0 Nv04DupObjectWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined4 Nv04DupObjectWithSecInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = rmapiGetInterface(0);
  uVar1 = param_1[5];
  uVar2 = (**(code **)(lVar3 + 0x58))(lVar3,*param_1,param_1[1],param_1 + 2,param_1[3],param_1[4]);
  param_1[6] = uVar2;
  return uVar1;
}


// ===== 00499c40 Nv04ShareWithSecInfo =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void Nv04ShareWithSecInfo(undefined4 *param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  undefined8 in_stack_00000020;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = in_stack_00000008;
  local_30 = in_stack_00000010;
  local_28 = in_stack_00000018;
  local_20 = in_stack_00000020;
  lVar2 = rmapiGetInterface(0);
  uVar1 = (**(code **)(lVar2 + 0x68))
                    (lVar2,*param_1,param_1[1],param_1 + 2,&local_38,*(code **)(lVar2 + 0x68));
  param_1[5] = uVar1;
  return;
}


// ===== 00499ca0 _eventRpcForType =====

bool _eventRpcForType(undefined8 param_1,undefined8 param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  long local_10;
  
  iVar2 = serverutilGetResourceRef(param_1,param_2,&local_10);
  bVar1 = false;
  if (iVar2 == 0) {
    lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0x4b01b3);
    if (lVar3 == 0) {
      lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0xb12d7d);
      if (lVar3 == 0) {
        lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0x43d7c4);
        if (lVar3 == 0) {
          lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0x88441b);
          if (lVar3 == 0) {
            lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0xbd2ff3);
            if (lVar3 == 0) {
              lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0x41f4f2);
              if (lVar3 == 0) {
                lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0xb13ac4);
                if (lVar3 == 0) {
                  lVar3 = objDynamicCastById_IMPL(*(undefined8 *)(local_10 + 8),0x4adc81);
                  return lVar3 != 0;
                }
              }
            }
          }
        }
      }
    }
    bVar1 = true;
  }
  return bVar1;
}


// ===== 00499d90 eventapiDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void eventapiDestruct_IMPL(long param_1)

{
  long *plVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  long local_28;
  long local_20;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0xb8);
  }
  uVar2 = 0;
  resGetFreeParams_IMPL(uVar4,&local_28,&local_20);
  lVar3 = *(long *)(param_1 + 0xd8);
  if (lVar3 == 0) goto LAB_00499e25;
  plVar1 = *(long **)(lVar3 + 0x98);
  uVar2 = 0;
  if (plVar1 == (long *)0x0) {
LAB_00499e12:
    uVar4 = *(undefined8 *)(lVar3 + 0x88);
  }
  else {
    uVar2 = (**(code **)(*plVar1 + 0x30))
                      (plVar1,*(undefined4 *)(lVar3 + 0xa0),*(undefined4 *)(lVar3 + 0xa4),
                       *(undefined4 *)(*(long *)(local_28 + 8) + 0x48),
                       *(undefined4 *)(*(long *)(local_28 + 0x10) + 0x10));
    lVar3 = *(long *)(param_1 + 0xd8);
    uVar4 = 0;
    if (lVar3 != 0) goto LAB_00499e12;
  }
  serverFreeShare(g_resServ,uVar4);
LAB_00499e25:
  if (local_20 != 0) {
    *(undefined4 *)(local_20 + 0x30) = uVar2;
  }
  return;
}


// ===== 00499e3b notifyUnregisterEvent_IMPL.cold =====

void notifyUnregisterEvent_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00499e60 notifyUnregisterEvent_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int notifyUnregisterEvent_IMPL
              (long param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  long local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  plVar6 = (long *)(**(code **)(**(long **)(param_1 + 0x18) + 0x18))();
  if (*plVar6 == 0) {
    iVar5 = 0;
    goto LAB_00499ed8;
  }
  iVar4 = _eventRpcForType(param_2,param_3);
  iVar5 = 0;
  if (iVar4 == 0) goto LAB_00499ec7;
  lVar7 = CliGetGpuFromHandle(param_2,param_3,0);
  if (lVar7 == 0) {
    nvDbg_Printf("src/kernel/rmapi/event_api.c",0x12f,"notifyUnregisterEvent_IMPL",4,
                 "NVRM: RmFreeEvent could not set pGpu. hClient=0x%x, hObject=0x%x\n",param_2,
                 param_3);
LAB_0049a0a0:
    iVar5 = 0;
  }
  else {
    local_40[0] = 0;
    if ((*(char *)(lVar7 + 0x909) == '\0') && (*(char *)(lVar7 + 0x90a) == '\0')) {
LAB_00499f93:
      cVar3 = *(char *)(lVar7 + 0x4913);
      if (*(char *)(lVar7 + 0x908) == '\0') {
LAB_0049a100:
        if (cVar3 == '\0') goto LAB_0049a0a0;
LAB_0049a08d:
        if (*(char *)(*plVar6 + 0x1d) != '\0') goto LAB_0049a0a0;
      }
      else if (cVar3 != '\0') goto LAB_0049a08d;
LAB_00499fc0:
      lVar8 = gpuGetRpc(lVar7);
      if (lVar8 == 0) {
        iVar5 = 0x1a;
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/event_api.c",0x12a);
      }
      else if ((*(char *)(lVar7 + 0x909) == '\0') && (*(char *)(lVar7 + 0x90a) == '\0')) {
        iVar5 = (**(code **)(lVar8 + 0xf0))(lVar7,lVar8,param_4,param_4,param_5);
      }
      else {
        iVar5 = (**(code **)(lVar7 + 0x3b70))(lVar7 + 0x3b58,param_4,param_5);
      }
    }
    else {
      iVar5 = serverutilGetResourceRef(param_2,param_3,local_40);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "serverutilGetResourceRef(hNotifierClient, hNotifierResource, &pNotifierRef)",
                   "src/kernel/rmapi/event_api.c",0x112);
        return iVar5;
      }
      iVar5 = 0;
      if (*(char *)(lVar7 + 0x909) == '\0') {
        if (*(char *)(lVar7 + 0x90a) == '\0') goto LAB_00499f93;
        iVar4 = *(int *)(local_40[0] + 0x118);
        if (iVar4 != 0xb12d7d) {
          if (*(char *)(lVar7 + 0x908) != '\0') {
            if (*(char *)(lVar7 + 0x4913) == '\0') goto LAB_00499fc0;
            if (*(char *)(lVar7 + 0x90a) == '\0') goto LAB_0049a08d;
          }
          goto LAB_0049a0ed;
        }
      }
      else {
        iVar4 = *(int *)(local_40[0] + 0x118);
        if (iVar4 != 0xb12d7d) {
          if (*(char *)(lVar7 + 0x908) != '\0') {
            if ((*(char *)(lVar7 + 0x4913) != '\0') && (*(int *)(local_40[0] + 0x118) == 0x88441b))
            goto LAB_0049a08d;
            goto LAB_00499fc0;
          }
LAB_0049a0ed:
          if (iVar4 != 0x88441b) goto LAB_00499fc0;
          cVar3 = *(char *)(lVar7 + 0x4913);
          goto LAB_0049a100;
        }
      }
    }
  }
LAB_00499ec7:
  unregisterEventNotification(plVar6,param_4,param_3,param_5);
LAB_00499ed8:
  lVar7 = __nvoc_dynamicCast(param_1,__nvoc_class_def_GSyncApi);
  puVar9 = (undefined8 *)(lVar7 + 0x128);
  if (lVar7 != 0) {
    do {
      while (((piVar1 = (int *)*puVar9, piVar1 == (int *)0x0 || (*piVar1 != param_4)) ||
             (piVar1[1] != param_5))) {
        puVar9 = puVar9 + 1;
        if ((undefined8 *)(lVar7 + 0x170) == puVar9) {
          return iVar5;
        }
      }
      puVar10 = puVar9 + 1;
      unregisterEventNotification(puVar9,param_4,param_3,param_5);
      puVar9 = puVar10;
    } while ((undefined8 *)(lVar7 + 0x170) != puVar10);
  }
  return iVar5;
}


// ===== 0049a1b0 eventapiInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int eventapiInit_IMPL(long param_1,long param_2,int param_3,undefined4 param_4,undefined8 *param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  long local_50;
  long local_48;
  long local_40 [2];
  
  local_48 = 0;
  uVar1 = *(uint *)(*(long *)(param_2 + 0x10) + 0x11c);
  if (uVar1 < 0x7a) {
    if (uVar1 < 0x78) {
      return 0x22;
    }
  }
  else if (uVar1 != 0x7e) {
    return 0x22;
  }
  lVar2 = *(long *)(param_2 + 8);
  if ((*(int *)(*(long *)(param_2 + 8) + 0x48) == param_3) ||
     ((iVar3 = serverGetClientUnderLock(g_resServ,param_3,&local_50), iVar3 == 0 &&
      (iVar3 = 0x23, lVar2 = local_50, local_50 != 0)))) {
    local_50 = lVar2;
    iVar3 = clientGetResourceRef_IMPL(local_50,param_4,local_40);
    if ((iVar3 != 0) ||
       (plVar4 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_40[0] + 8),
                                            __nvoc_class_def_INotifier), plVar4 == (long *)0x0)) {
      return 0x31;
    }
    iVar3 = (**(code **)(*plVar4 + 0x38))
                      (plVar4,param_3,param_4,&local_48,*(code **)(*plVar4 + 0x38));
    if (iVar3 == 0) {
      uVar5 = (**(code **)(**(long **)(local_48 + 0x98) + 0x18))();
      *param_5 = uVar5;
      uVar5 = 0;
      if (local_48 != 0) {
        uVar5 = *(undefined8 *)(local_48 + 0x88);
      }
      serverRefShare(g_resServ,uVar5);
      *(int *)(param_1 + 0xe0) = param_3;
      *(undefined4 *)(param_1 + 0xe4) = param_4;
      *(long *)(param_1 + 0xd8) = local_48;
      *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10);
      return 0;
    }
  }
  return iVar3;
}


// ===== 0049a370 eventapiConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong eventapiConstruct_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  char *pcVar12;
  int iVar13;
  int local_70;
  undefined1 local_68 [8];
  undefined8 local_60;
  long local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  uint local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  
  piVar2 = *(int **)(param_3 + 0x40);
  lVar3 = *(long *)(param_2 + 8);
  iVar13 = *piVar2;
  lVar4 = *(long *)(param_2 + 0x10);
  if (iVar13 == 0) {
    iVar13 = *(int *)(lVar3 + 0x48);
  }
  bVar5 = **(uint **)(param_3 + 0x38) < 2;
  if ((*(int *)(lVar4 + 0x11c) == 0x78 || *(int *)(lVar4 + 0x11c) == 0x7e) && (bVar5)) {
    return 0x16;
  }
  local_70 = _eventRpcForType(iVar13,piVar2[1]);
  lVar10 = 0;
  if (local_70 != 0) {
    iVar7 = serverutilGetResourceRef(iVar13,piVar2[1],&local_50);
    if (iVar7 == 0) {
      lVar10 = *(long *)(CONCAT44(uStack_4c,local_50) + 0x18);
      local_70 = 0;
      if (lVar10 != 0) {
        local_70 = *(int *)(lVar10 + 0x10);
      }
      lVar10 = CliGetGpuFromContext(CONCAT44(uStack_4c,local_50),0);
      if (lVar10 == 0) {
        nvDbg_Printf("src/kernel/rmapi/event_api.c",0x6b,"eventapiConstruct_IMPL",4,
                     "NVRM: RmAllocEvent could not set pGpu. hClient=0x%x, hObject=0x%x\n",
                     *(undefined4 *)(lVar3 + 0x48),*(undefined4 *)(lVar4 + 0x10));
      }
    }
    else {
      local_70 = 0;
      lVar10 = 0;
    }
  }
  uVar6 = clientGetResourceRef_IMPL(lVar3,*(undefined4 *)(lVar3 + 0x48),local_68);
  uVar11 = 0x72;
  pcVar12 = "clientGetResourceRef(pRsClient, pRsClient->hClient, &pClientRef)";
  if (uVar6 != 0) {
LAB_0049a7c3:
    nvAssertOkFailedNoLog(uVar6,pcVar12,"src/kernel/rmapi/event_api.c",uVar11);
    return (ulong)uVar6;
  }
  uVar8 = eventapiInit_IMPL(param_1,param_2,iVar13,piVar2[1],&local_60);
  if ((int)uVar8 != 0) goto LAB_0049a585;
  if (lVar10 == 0) goto LAB_0049a5b0;
  local_58 = 0;
  if ((*(char *)(lVar10 + 0x909) == '\0') && (*(char *)(lVar10 + 0x90a) == '\0')) {
LAB_0049a690:
    cVar1 = *(char *)(lVar10 + 0x4913);
    if (*(char *)(lVar10 + 0x908) == '\0') {
LAB_0049a786:
      if (cVar1 != '\0') goto LAB_0049a6ae;
      iVar13 = *(int *)(lVar4 + 0x11c);
      uVar11 = 0;
      if ((iVar13 == 0x79) && (bVar5)) goto LAB_0049a730;
    }
    else {
      if (cVar1 != '\0') {
LAB_0049a6ae:
        uVar6 = piVar2[3];
        if ((uVar6 & 0x8000000) != 0) {
          iVar13 = *(int *)(lVar4 + 0x11c);
          if ((iVar13 == 0x79) && (bVar5)) goto LAB_0049a730;
          uVar11 = 0;
          goto LAB_0049a5cd;
        }
      }
LAB_0049a4d0:
      lVar9 = gpuGetRpc(lVar10);
      if (lVar9 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/rmapi/event_api.c",0xa2);
        if ((*(int *)(lVar4 + 0x11c) != 0x79) || (!bVar5)) {
          uVar8 = 0x1a;
          goto LAB_0049a585;
        }
LAB_0049a730:
        uVar8 = osUserHandleToKernelPtr
                          (*(undefined4 *)(lVar3 + 0x48),*(undefined8 *)(piVar2 + 4),piVar2 + 4);
        uVar11 = 1;
      }
      else {
        if ((*(char *)(lVar10 + 0x909) == '\0') && (*(char *)(lVar10 + 0x90a) == '\0')) {
          uVar8 = (**(code **)(lVar9 + 0x308))
                            (lVar10,lVar9,*(undefined4 *)(lVar3 + 0x48),
                             *(undefined4 *)(param_1 + 0xe0),local_70,
                             *(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(lVar4 + 0x10),
                             *(undefined4 *)(lVar4 + 0x11c),piVar2[3]);
        }
        else {
          uStack_4c = 0;
          uStack_40 = 0;
          local_3c = 0;
          local_44 = piVar2[3] | 0x4000000;
          local_50 = *(undefined4 *)(param_1 + 0xe0);
          uStack_48 = *(undefined4 *)(lVar4 + 0x11c);
          uVar8 = (**(code **)(lVar10 + 0x3b60))(lVar10 + 0x3b58);
        }
        if ((*(int *)(lVar4 + 0x11c) == 0x79) && (bVar5)) goto LAB_0049a730;
        uVar11 = 0;
      }
      if ((int)uVar8 != 0) goto LAB_0049a585;
      iVar13 = *(int *)(lVar4 + 0x11c);
    }
    uVar6 = piVar2[3];
  }
  else {
    uVar6 = serverutilGetResourceRef(iVar13,piVar2[1],&local_58);
    if (uVar6 != 0) {
      uVar11 = 0x8f;
      pcVar12 = 
      "serverutilGetResourceRef(hParentClient, pNv0050AllocParams->hSrcResource, &pSourceRef)";
      goto LAB_0049a7c3;
    }
    if (*(char *)(lVar10 + 0x909) == '\0') {
      if (*(char *)(lVar10 + 0x90a) == '\0') goto LAB_0049a690;
      iVar13 = *(int *)(local_58 + 0x118);
      if (iVar13 != 0xb12d7d) {
        if (*(char *)(lVar10 + 0x908) != '\0') {
          if (*(char *)(lVar10 + 0x4913) == '\0') goto LAB_0049a4d0;
          if (*(char *)(lVar10 + 0x90a) == '\0') goto LAB_0049a6ae;
        }
        goto LAB_0049a773;
      }
    }
    else {
      iVar13 = *(int *)(local_58 + 0x118);
      if (iVar13 != 0xb12d7d) {
        if (*(char *)(lVar10 + 0x908) == '\0') {
LAB_0049a773:
          if (iVar13 == 0x88441b) {
            cVar1 = *(char *)(lVar10 + 0x4913);
            goto LAB_0049a786;
          }
        }
        else if ((*(char *)(lVar10 + 0x4913) != '\0') && (*(int *)(local_58 + 0x118) == 0x88441b))
        goto LAB_0049a6ae;
        goto LAB_0049a4d0;
      }
    }
LAB_0049a5b0:
    iVar13 = *(int *)(lVar4 + 0x11c);
    if ((iVar13 == 0x79) && (bVar5)) goto LAB_0049a730;
    uVar6 = piVar2[3];
    uVar11 = 0;
  }
LAB_0049a5cd:
  uVar8 = registerEventNotification
                    (local_60,lVar3,*(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(lVar4 + 0x10),
                     uVar6,iVar13,*(undefined8 *)(piVar2 + 4),uVar11);
  if ((int)uVar8 == 0) {
    return uVar8;
  }
LAB_0049a585:
  eventapiDestruct_IMPL(param_1);
  return uVar8 & 0xffffffff;
}


// ===== 0049a855 notifyGetOrAllocNotifShare_IMPL.cold =====

void notifyGetOrAllocNotifShare_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049a860 notifyGetOrAllocNotifShare_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
notifyGetOrAllocNotifShare_IMPL(long param_1,undefined4 param_2,undefined4 param_3,long *param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_30;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  lVar3 = (**(code **)(**(long **)(param_1 + 0x18) + 0x28))();
  if (lVar3 == 0) {
    uVar2 = serverAllocShare(g_resServ,__nvoc_class_def_NotifShare,&local_30);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    lVar3 = __nvoc_dynamicCast(local_30,__nvoc_class_def_NotifShare);
    uVar2 = *(undefined8 *)(param_1 + 0x18);
    *(undefined4 *)(lVar3 + 0xa0) = param_2;
    *(undefined8 *)(lVar3 + 0x98) = uVar2;
    *(undefined4 *)(lVar3 + 0xa4) = param_3;
    pcVar1 = *(code **)(**(long **)(param_1 + 0x18) + 0x20);
    (*pcVar1)(*(long **)(param_1 + 0x18),lVar3,pcVar1);
  }
  if (param_4 != (long *)0x0) {
    *param_4 = lVar3;
  }
  return 0;
}


// ===== 0049a920 CliGetEventNotificationList =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int CliGetEventNotificationList
              (undefined4 param_1,undefined4 param_2,undefined8 *param_3,long *param_4)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  long local_38;
  undefined8 local_30 [2];
  
  *param_4 = 0;
  iVar1 = serverGetClientUnderLock(g_resServ,param_1,local_30);
  if (iVar1 == 0) {
    iVar1 = clientGetResourceRef_IMPL(local_30[0],param_2,&local_38);
    if (iVar1 == 0) {
      plVar2 = (long *)__nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_INotifier);
      if (plVar2 == (long *)0x0) {
        lVar3 = *param_4;
      }
      else {
        lVar3 = (**(code **)(*plVar2 + 0x18))(plVar2);
        *param_4 = lVar3;
      }
      if (lVar3 == 0) {
        iVar1 = 0x31;
      }
      else if (param_3 != (undefined8 *)0x0) {
        *param_3 = plVar2;
        return 0;
      }
    }
  }
  return iVar1;
}


// ===== 0049aa00 CliGetEventInfo =====

undefined8 CliGetEventInfo(undefined8 param_1,undefined4 param_2,undefined8 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long local_20;
  
  lVar2 = serverutilGetClientUnderLock();
  if (lVar2 != 0) {
    iVar1 = clientGetResourceRefByType_IMPL
                      (*(undefined8 *)(lVar2 + 0x100),param_2,0x854293,&local_20);
    if ((iVar1 == 0) && (*(long *)(local_20 + 8) != 0)) {
      uVar3 = __nvoc_dynamicCast(*(long *)(local_20 + 8),__nvoc_class_def_EventApi);
      *param_3 = uVar3;
      return 1;
    }
  }
  return 0;
}


// ===== 0049aa80 CliDelObjectEvents =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void CliDelObjectEvents(long param_1)

{
  undefined4 *puVar1;
  long *plVar2;
  long lVar3;
  
  if (param_1 == 0) {
    return;
  }
  plVar2 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_1 + 8),__nvoc_class_def_INotifier);
  if ((plVar2 != (long *)0x0) && (lVar3 = (**(code **)(*plVar2 + 0x28))(plVar2), lVar3 != 0)) {
    while (puVar1 = *(undefined4 **)(lVar3 + 0xa8), puVar1 != (undefined4 *)0x0) {
      (**(code **)(*plVar2 + 0x30))
                (plVar2,*(undefined4 *)(lVar3 + 0xa0),*(undefined4 *)(lVar3 + 0xa4),*puVar1,
                 puVar1[1],*(code **)(*plVar2 + 0x30));
    }
    *(undefined8 *)(lVar3 + 0x98) = 0;
    return;
  }
  return;
}


// ===== 0049ab30 eventSystemInitEventQueue =====

void eventSystemInitEventQueue(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1,uVar1,0xc);
  return;
}


// ===== 0049ab60 eventSystemEnqueueEvent =====

byte eventSystemEnqueueEvent(undefined8 param_1,uint param_2,ulong *param_3)

{
  long lVar1;
  uint local_14;
  ulong local_10;
  
  if ((param_2 == 2) || (param_2 < 3)) {
    local_10 = (ulong)(uint)*param_3;
  }
  else {
    if (param_2 != 3) {
      return 0x28;
    }
    local_10 = *param_3;
  }
  local_14 = param_2;
  lVar1 = listAppendValue_IMPL(param_1,&local_14);
  return -(lVar1 == 0) & 0x51;
}


// ===== 0049abc0 CliAddSystemEvent =====

void CliAddSystemEvent(uint param_1,long param_2,undefined1 *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  ulong uVar9;
  long local_40 [2];
  
  uVar9 = (ulong)param_1;
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  plVar4 = (long *)serverutilGetFirstClientUnderLock();
  do {
    while( true ) {
      if (plVar4 == (long *)0x0) {
        return;
      }
      lVar2 = *plVar4;
      lVar5 = 0;
      if (lVar2 != 0) {
        lVar5 = *(long *)(lVar2 + 0x100);
      }
      lVar1 = lVar2 + uVar9 * 4;
      if (*(int *)(lVar1 + 0x230) != 0) break;
LAB_0049ad30:
      plVar4 = (long *)serverutilGetNextClientUnderLock(plVar4);
    }
    iVar3 = clientGetResourceRef_IMPL
                      (*(undefined8 *)(lVar2 + 0x100),*(undefined4 *)(lVar5 + 0x48),local_40);
    if (iVar3 != 0) {
      uVar9 = (ulong)*(uint *)(lVar5 + 0x48);
      pcVar8 = "NVRM: Failed to look up resource reference handle: 0x%x\n";
      uVar7 = 0x249;
LAB_0049ae13:
      nvDbg_Printf("src/kernel/rmapi/event_api.c",uVar7,"CliAddSystemEvent",4,pcVar8,uVar9);
      return;
    }
    lVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_40[0] + 8),__nvoc_class_def_Notifier);
    if ((lVar5 == 0) ||
       (lVar5 = inotifyGetNotificationList_IMPL(*(undefined8 *)(lVar5 + 0x18)), lVar5 == 0))
    goto LAB_0049ad30;
    lVar2 = lVar2 + 0x208;
    do {
      while (*(uint *)(lVar5 + 0xc) != param_1) {
LAB_0049acb0:
        lVar5 = *(long *)(lVar5 + 0x40);
        if (lVar5 == 0) goto LAB_0049ad10;
      }
      if (param_2 == 0) {
        iVar3 = osNotifyEvent(0,lVar5,0,0);
        if (iVar3 != 0) {
LAB_0049ad79:
          nvDbg_Printf("src/kernel/rmapi/event_api.c",0x269,"CliAddSystemEvent",4,
                       "NVRM: failed to deliver event 0x%x",uVar9);
          goto LAB_0049acb0;
        }
      }
      else {
        iVar3 = eventSystemEnqueueEvent(lVar2,uVar9,param_2);
        if (iVar3 != 0) {
          pcVar8 = "NVRM: fails to add event=%d\n";
          uVar7 = 0x25f;
          goto LAB_0049ae13;
        }
        iVar3 = osNotifyEvent(0,lVar5,0,0);
        if (iVar3 != 0) {
          lVar6 = listTail_IMPL(lVar2);
          if (lVar6 != 0) {
            listRemove_IMPL(lVar2,lVar6);
          }
          goto LAB_0049ad79;
        }
      }
      if (param_3 == (undefined1 *)0x0) goto LAB_0049acb0;
      *param_3 = 1;
      lVar5 = *(long *)(lVar5 + 0x40);
    } while (lVar5 != 0);
LAB_0049ad10:
    if (*(int *)(lVar1 + 0x230) != 1) goto LAB_0049ad30;
    *(undefined4 *)(lVar1 + 0x230) = 0;
    plVar4 = (long *)serverutilGetNextClientUnderLock(plVar4);
  } while( true );
}


// ===== 0049ae50 eventSystemDequeueEvent =====

undefined8 eventSystemDequeueEvent(undefined8 param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)listHead_IMPL();
  if (puVar1 != (undefined8 *)0x0) {
    *param_2 = *puVar1;
    *(undefined4 *)(param_2 + 1) = *(undefined4 *)(puVar1 + 1);
    listRemove_IMPL(param_1,puVar1);
    return 0;
  }
  return 0x57;
}


// ===== 0049aea0 eventSystemClearEventQueue =====

void eventSystemClearEventQueue(void)

{
  listDestroy_IMPL();
  return;
}


// ===== 0049aeb0 _allocAndMapMemory.isra.0 =====

ulong _allocAndMapMemory_isra_0
                (long param_1,long *param_2,undefined8 param_3,undefined1 param_4,long *param_5,
                undefined8 *param_6,long *param_7,undefined8 *param_8,long param_9)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  
  if (param_1 != 0) {
    nvAssertFailedNoLog("pAddress == NvP64_NULL","src/kernel/rmapi/event_buffer.c",0x227);
    return 0x56;
  }
  if ((param_9 == 0) || (lVar1 = *(long *)(*(long *)(param_9 + 0x158) + 0xe0), lVar1 == 0)) {
    nvAssertFailedNoLog("pSubdevice != NULL && pGpu != NULL","src/kernel/rmapi/event_buffer.c",0x22c
                       );
    return 0x40;
  }
  uVar3 = memdescCreate(param_2,lVar1,param_3,0,1,1);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  lVar1 = *param_2;
  uVar3 = osAllocPagesInternal(lVar1);
  if ((int)uVar3 == 0) {
    *(undefined1 *)(lVar1 + 100) = 1;
    uVar2 = memdescMap(lVar1,0,param_3,1,3,param_5,param_6);
    lVar7 = *param_5;
    if (uVar2 != 0) {
      uVar6 = *param_6;
      uVar4 = *param_8;
      lVar5 = *param_7;
      goto LAB_0049af71;
    }
    portMemSet(lVar7,0,param_3);
    uVar3 = memdescMap(lVar1,0,param_3,param_4,1,param_7,param_8);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
  }
  else if (lVar1 == 0) {
    return uVar3;
  }
  uVar2 = (uint)uVar3;
  uVar6 = *param_6;
  lVar7 = *param_5;
  uVar4 = *param_8;
  lVar5 = *param_7;
LAB_0049af71:
  if (lVar5 != 0) {
    memdescUnmap(lVar1,param_4,lVar5,uVar4);
  }
  if (lVar7 != 0) {
    memdescUnmap(lVar1,1,lVar7,uVar6);
  }
  memdescFree(lVar1);
  memdescDestroy(lVar1);
  return (ulong)uVar2;
}


// ===== 0049b0b3 eventbufferDestruct_IMPL.cold =====

void eventbufferDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0049b0c0 eventbufferDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void eventbufferDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  bool bVar3;
  code *pcVar4;
  uint uVar5;
  long *plVar6;
  long lVar7;
  undefined1 local_30 [16];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar6 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),
                                      __nvoc_class_def_RmClient);
  if (plVar6 != (long *)0x0) {
    lVar7 = *(long *)(param_1 + 0x1a8);
    uVar5 = (**(code **)(*plVar6 + 0xd8))(plVar6);
    bVar3 = 1 < uVar5;
    resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0xb8),local_30,0);
    if (lVar7 != 0) {
      osDereferenceObjectCount(lVar7);
    }
    videoRemoveAllBindpoints(param_1);
    fecsRemoveAllBindpoints(param_1);
    gspTraceRemoveAllBindpoints(param_1);
    lVar7 = *(long *)(param_1 + 0xd8);
    if (lVar7 != 0) {
      uVar1 = *(undefined8 *)(param_1 + 0x100);
      lVar2 = *(long *)(param_1 + 0xf8);
      if (*(long *)(param_1 + 0x128) != 0) {
        memdescUnmap(lVar7,bVar3,*(long *)(param_1 + 0x128),*(undefined8 *)(param_1 + 0x130));
      }
      if (lVar2 != 0) {
        memdescUnmap(lVar7,1,lVar2,uVar1);
      }
      memdescFree(lVar7);
      memdescDestroy(lVar7);
    }
    lVar7 = *(long *)(param_1 + 0xe0);
    if (lVar7 != 0) {
      uVar1 = *(undefined8 *)(param_1 + 0x110);
      lVar2 = *(long *)(param_1 + 0x108);
      if (*(long *)(param_1 + 0x138) != 0) {
        memdescUnmap(lVar7,bVar3,*(long *)(param_1 + 0x138),*(undefined8 *)(param_1 + 0x140));
      }
      if (lVar2 != 0) {
        memdescUnmap(lVar7,1,lVar2,uVar1);
      }
      memdescFree(lVar7);
      memdescDestroy(lVar7);
    }
    lVar7 = *(long *)(param_1 + 0xe8);
    if (lVar7 != 0) {
      uVar1 = *(undefined8 *)(param_1 + 0x120);
      lVar2 = *(long *)(param_1 + 0x118);
      if (*(long *)(param_1 + 0x148) != 0) {
        memdescUnmap(lVar7,bVar3,*(long *)(param_1 + 0x148),*(undefined8 *)(param_1 + 0x150));
      }
      if (lVar2 != 0) {
        memdescUnmap(lVar7,1,lVar2,uVar1);
      }
      memdescFree(lVar7);
      memdescDestroy(lVar7);
    }
    if (*(int *)(param_1 + 0x1d0) == 0) {
      return;
    }
    lVar7 = rmapiGetInterface(4);
    (**(code **)(lVar7 + 0x18))
              (lVar7,*(undefined4 *)(param_1 + 0x1d0),*(undefined4 *)(param_1 + 0x1d0),
               *(code **)(lVar7 + 0x18));
    return;
  }
  nvAssertFailedNoLog("pRmClient != NULL","src/kernel/rmapi/event_buffer.c",0x1f1);
  return;
}


// ===== 0049b320 eventbufferConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong eventbufferConstruct_IMPL(long param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 *puVar2;
  bool bVar3;
  code *pcVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  long *plVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  undefined8 uVar15;
  ulong uVar16;
  undefined4 uVar17;
  bool bVar18;
  undefined4 local_8c;
  undefined4 local_88;
  uint local_84;
  long local_78;
  ulong local_60;
  long local_58;
  long local_50;
  long local_48;
  long local_40 [2];
  
  puVar2 = *(undefined8 **)(param_3 + 0x40);
  local_58 = 0;
  local_50 = 0;
  iVar1 = *(int *)((long)puVar2 + 0x3c);
  local_48 = 0;
  local_40[0] = 0;
  plVar11 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (plVar11 == (long *)0x0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/rmapi/event_buffer.c",0x50);
    return 0x23;
  }
  uVar7 = (**(code **)(*plVar11 + 0xd8))(plVar11);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[3] = 0;
  if (iVar1 == 0) {
    if (*(char *)(g_pSys + 0x72) == '\0') {
      nvAssertFailedNoLog("bSupported","src/kernel/rmapi/event_buffer.c",0x5c);
      return 0x56;
    }
LAB_0049b3d1:
    bVar5 = false;
  }
  else {
    if (*(int *)(puVar2 + 8) == 0) {
      nvAssertFailedNoLog("(pAllocParams->hRecordBuffer != 0)","src/kernel/rmapi/event_buffer.c",
                          0x60);
      return 0x1f;
    }
    if ((*(int *)(puVar2 + 4) != 0) != (*(int *)((long)puVar2 + 0x44) != 0)) {
      nvAssertFailedNoLog("((pAllocParams->vardataBufferSize == 0) ^ (pAllocParams->hVardataBuffer != 0))"
                          ,"src/kernel/rmapi/event_buffer.c",0x61);
      return 0x1f;
    }
    uVar12 = clientGetResourceRef_IMPL
                       (*(undefined8 *)(param_2 + 8),*(undefined4 *)((long)puVar2 + 0x3c),&local_50)
    ;
    if ((int)uVar12 != 0) {
      return uVar12;
    }
    uVar12 = clientGetResourceRef_IMPL
                       (*(undefined8 *)(param_2 + 8),*(undefined4 *)(puVar2 + 8),&local_48);
    if ((int)uVar12 != 0) {
      return uVar12;
    }
    iVar9 = *(int *)(local_48 + 0x11c);
    if (iVar9 != *(int *)(local_50 + 0x11c)) {
      return 0x1f;
    }
    if (*(int *)((long)puVar2 + 0x44) != 0) {
      uVar12 = clientGetResourceRef_IMPL
                         (*(undefined8 *)(param_2 + 8),*(int *)((long)puVar2 + 0x44),local_40);
      if ((int)uVar12 != 0) {
        return uVar12;
      }
      if (*(int *)(local_40[0] + 0x11c) != *(int *)(local_50 + 0x11c)) {
        return 0x1f;
      }
      iVar9 = *(int *)(local_48 + 0x11c);
    }
    if (iVar9 != 0x90ce) {
      if (*(int *)((long)puVar2 + 0x34) == 0) {
        nvDbg_Printf("src/kernel/rmapi/event_buffer.c",0x80,"eventbufferConstruct_IMPL",3,
                     "NVRM: hSubDevice must be provided.\n");
        return 0x1f;
      }
      goto LAB_0049b3d1;
    }
    bVar5 = true;
  }
  if (*(uint *)(puVar2 + 2) == 0) {
    return 0x1f;
  }
  uVar10 = *(uint *)((long)puVar2 + 0x14);
  if (uVar10 == 0) {
    return 0x1f;
  }
  uVar12 = (ulong)*(uint *)(puVar2 + 2) * (ulong)uVar10;
  uVar8 = (undefined4)uVar12;
  if ((int)(uVar12 >> 0x20) != 0) {
    return 0x1f;
  }
  if (uVar10 < *(uint *)((long)puVar2 + 0x24)) {
    return 0x1f;
  }
  if (*(uint *)(puVar2 + 4) < *(uint *)(puVar2 + 6)) {
    return 0x1f;
  }
  bVar3 = 1 < uVar7;
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  iVar9 = *(int *)((long)puVar2 + 0x34);
  *(int *)(param_1 + 0xf0) = iVar9;
  if (iVar9 == 0) {
    if (iVar1 != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
LAB_0049ba50:
    uVar10 = _allocAndMapMemory_isra_0
                       (*puVar2,param_1 + 0xd8,0x20,bVar3,param_1 + 0xf8,param_1 + 0x100,
                        param_1 + 0x128,param_1 + 0x130,local_58);
    if ((uVar10 != 0) ||
       (uVar10 = _allocAndMapMemory_isra_0
                           (puVar2[1],param_1 + 0xe0,uVar8,bVar3,param_1 + 0x108,param_1 + 0x110,
                            param_1 + 0x138,param_1 + 0x140,local_58), uVar10 != 0))
    goto LAB_0049ba35;
    eventBufferInitRecordBuffer
              (param_1 + 0x168,*(undefined8 *)(param_1 + 0xf8),*(undefined8 *)(param_1 + 0x108),
               *(undefined4 *)(puVar2 + 2),*(undefined4 *)((long)puVar2 + 0x14),uVar8,
               *(undefined4 *)((long)puVar2 + 0x24));
    iVar9 = *(int *)(puVar2 + 4);
    if (iVar9 == 0) goto LAB_0049b998;
LAB_0049bb20:
    uVar10 = _allocAndMapMemory_isra_0
                       (puVar2[3],param_1 + 0xe8,iVar9,bVar3,param_1 + 0x118,param_1 + 0x120,
                        param_1 + 0x148,param_1 + 0x150,local_58);
    if (uVar10 != 0) goto LAB_0049ba35;
    iVar9 = *(int *)(puVar2 + 4);
LAB_0049b984:
    local_78 = param_1 + 0x168;
    eventBufferInitVardataBuffer
              (local_78,*(undefined8 *)(param_1 + 0x118),iVar9,*(undefined4 *)(puVar2 + 6));
LAB_0049b998:
    local_78 = param_1 + 0x168;
    local_60 = puVar2[5];
    if (uVar7 < 2) {
      osUserHandleToKernelPtr(*(undefined4 *)(*(long *)(param_2 + 8) + 0x48),local_60,&local_60);
    }
    eventBufferInitNotificationHandle(local_78,local_60);
    eventBufferSetEnable(local_78,0);
    *puVar2 = *(undefined8 *)(param_1 + 0x128);
    puVar2[1] = *(undefined8 *)(param_1 + 0x138);
    puVar2[3] = *(undefined8 *)(param_1 + 0x148);
    return 0;
  }
  iVar9 = subdeviceGetByHandle_IMPL(*(undefined8 *)(param_2 + 8),iVar9,&local_58);
  if (iVar9 != 0) {
    return 0x33;
  }
  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(local_58 + 0x334);
  lVar13 = *(long *)(*(long *)(local_58 + 0x158) + 0xe0);
  if (bVar5) {
    if (iVar1 == 0) goto LAB_0049ba50;
    lVar14 = *(long *)(&DAT_00001b90 + lVar13);
    local_8c = 0;
    local_88 = 0;
    bVar18 = uVar7 < 2;
    local_84 = 0;
  }
  else {
    bVar18 = false;
    if (*(char *)(lVar13 + 0x908) != '\0') {
      bVar18 = *(char *)(lVar13 + 0x4913) == '\0';
    }
    if (uVar7 < 2) {
      uVar15 = rmapiGetInterface(4);
      uVar16 = rmapiutilAllocClientAndDeviceHandles
                         (uVar15,lVar13,param_1 + 0x1d0,param_1 + 0x1d4,param_1 + 0x1d8);
      if ((int)uVar16 != 0) {
        return uVar16;
      }
      local_88 = *(undefined4 *)(param_1 + 0x1d0);
      local_8c = *(undefined4 *)(param_1 + 0x1d4);
    }
    else {
      local_88 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
      local_8c = *(undefined4 *)
                  (*(long *)(*(long *)(*(long *)(local_58 + 0x140) + 0x48) + 0x18) + 0x10);
    }
    if (iVar1 == 0) goto LAB_0049ba50;
    local_84 = (uint)bVar18;
    bVar18 = (bool)(uVar7 < 2 | bVar18);
    lVar14 = *(long *)(&DAT_00001b90 + lVar13);
  }
  if ((lVar14 != 0) && (*(char *)(lVar14 + 0xad0c) != '\0')) {
    cVar6 = gpuIsCCDevToolsModeEnabled_IMPL(lVar13);
    local_84 = local_84 | (uint)(cVar6 != '\0') << 0x1a;
  }
  lVar13 = __nvoc_dynamicCast(*(undefined8 *)(local_50 + 8),__nvoc_class_def_Memory);
  *(long *)(param_1 + 0x1b8) = lVar13;
  if ((lVar13 != 0) &&
     (((bVar18 == false ||
       (cVar6 = memdescGetFlag(*(undefined8 *)(lVar13 + 0x118),0x100000000), cVar6 != '\0')) &&
      (0x1f < *(ulong *)(lVar13 + 0x100))))) {
    if (bVar5) {
      uVar10 = memCreateKernelMapping_IMPL(lVar13,3,1);
      if (uVar10 != 0) goto LAB_0049ba35;
      *(undefined8 *)(param_1 + 0xf8) = *(undefined8 *)(lVar13 + 0x138);
    }
    else {
      lVar14 = rmapiGetInterface(4);
      uVar17 = *(undefined4 *)(*(long *)(*(long *)(lVar13 + 0xb8) + 0x48) + 0x10);
      local_60 = CONCAT44(local_60._4_4_,uVar17);
      if (uVar7 < 2) {
        uVar10 = (**(code **)(lVar14 + 0x50))
                           (lVar14,local_88,local_8c,&local_60,
                            *(undefined4 *)(*(long *)(param_2 + 8) + 0x48),uVar17,0);
        if (uVar10 != 0) goto LAB_0049ba35;
        uVar17 = (undefined4)local_60;
      }
      uVar10 = (**(code **)(lVar14 + 0x70))
                         (lVar14,local_88,local_8c,uVar17,0,*(undefined8 *)(lVar13 + 0x100),
                          param_1 + 0xf8,local_84);
      if (uVar10 != 0) goto LAB_0049ba35;
    }
    lVar13 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Memory);
    *(long *)(param_1 + 0x1c0) = lVar13;
    if (((lVar13 != 0) &&
        ((bVar18 == false ||
         (cVar6 = memdescGetFlag(*(undefined8 *)(lVar13 + 0x118),0x100000000), cVar6 != '\0')))) &&
       ((uVar12 & 0xffffffff) <= *(ulong *)(lVar13 + 0x100))) {
      if (bVar5) {
        uVar10 = memCreateKernelMapping_IMPL(lVar13,3,1);
        *(undefined8 *)(param_1 + 0x108) = *(undefined8 *)(lVar13 + 0x138);
      }
      else {
        lVar14 = rmapiGetInterface(4);
        uVar17 = *(undefined4 *)(*(long *)(*(long *)(lVar13 + 0xb8) + 0x48) + 0x10);
        local_60 = CONCAT44(local_60._4_4_,uVar17);
        if ((uVar7 < 2) &&
           (uVar10 = (**(code **)(lVar14 + 0x50))
                               (lVar14,local_88,local_8c,&local_60,
                                *(undefined4 *)(*(long *)(param_2 + 8) + 0x48),uVar17,0),
           uVar10 != 0)) goto LAB_0049ba35;
        uVar10 = (**(code **)(lVar14 + 0x70))
                           (lVar14,local_88,local_8c,local_60 & 0xffffffff,0,
                            *(undefined8 *)(lVar13 + 0x100),param_1 + 0x108,local_84);
      }
      if (uVar10 != 0) goto LAB_0049ba35;
      if (*(int *)((long)puVar2 + 0x44) != 0) {
        lVar13 = __nvoc_dynamicCast(*(undefined8 *)(local_40[0] + 8),__nvoc_class_def_Memory);
        *(long *)(param_1 + 0x1c8) = lVar13;
        if ((lVar13 == 0) ||
           (((bVar18 != false &&
             (cVar6 = memdescGetFlag(*(undefined8 *)(lVar13 + 0x118),0x100000000), cVar6 == '\0'))
            || (*(ulong *)(lVar13 + 0x100) < (ulong)*(uint *)(puVar2 + 4))))) goto LAB_0049ba30;
        if (bVar5) {
          uVar10 = memCreateKernelMapping_IMPL(lVar13,3,1);
        }
        else {
          lVar14 = rmapiGetInterface(4);
          uVar17 = *(undefined4 *)(*(long *)(*(long *)(lVar13 + 0xb8) + 0x48) + 0x10);
          local_60 = CONCAT44(local_60._4_4_,uVar17);
          if ((uVar7 < 2) &&
             (uVar10 = (**(code **)(lVar14 + 0x50))
                                 (lVar14,local_88,local_8c,&local_60,
                                  *(undefined4 *)(*(long *)(param_2 + 8) + 0x48),uVar17,0),
             uVar10 != 0)) goto LAB_0049ba35;
          uVar10 = (**(code **)(lVar14 + 0x70))
                             (lVar14,local_88,local_8c,local_60 & 0xffffffff,0,
                              *(undefined8 *)(lVar13 + 0x100),param_1 + 0x108,local_84);
        }
        if (uVar10 != 0) goto LAB_0049ba35;
        *(undefined8 *)(param_1 + 0x118) = *(undefined8 *)(lVar13 + 0x138);
        refAddDependant(local_40[0],*(undefined8 *)(param_2 + 0x10));
      }
      refAddDependant(local_50,*(undefined8 *)(param_2 + 0x10));
      refAddDependant(local_48,*(undefined8 *)(param_2 + 0x10));
      eventBufferInitRecordBuffer
                (param_1 + 0x168,*(undefined8 *)(param_1 + 0xf8),*(undefined8 *)(param_1 + 0x108),
                 *(undefined4 *)(puVar2 + 2),*(undefined4 *)((long)puVar2 + 0x14),uVar8,
                 *(undefined4 *)((long)puVar2 + 0x24));
      iVar9 = *(int *)(puVar2 + 4);
      if (iVar9 == 0) goto LAB_0049b998;
      if (iVar1 == 0) goto LAB_0049bb20;
      goto LAB_0049b984;
    }
  }
LAB_0049ba30:
  uVar10 = 0x1f;
LAB_0049ba35:
  eventbufferDestruct_IMPL(param_1);
  return (ulong)uVar10;
}


// ===== 0049beb0 eventbuffertBufferCtrlCmdFlush_IMPL =====

undefined8 eventbuffertBufferCtrlCmdFlush_IMPL(void)

{
  long lVar1;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  local_20 = 0;
  local_1c[0] = 0;
  gpumgrGetGpuAttachInfo(0,&local_20);
  while( true ) {
    lVar1 = gpumgrGetNextGpu(local_20,local_1c);
    if (lVar1 == 0) break;
    nvEventBufferFecsCallback(lVar1,0);
    nvEventBufferVideoCallback(lVar1,0);
  }
  return 0;
}


// ===== 0049bf10 eventbuffertBufferCtrlCmdEnableEvent_IMPL =====

ulong eventbuffertBufferCtrlCmdEnableEvent_IMPL(long param_1,char *param_2)

{
  ulong uVar1;
  bool bVar2;
  undefined4 local_34;
  undefined1 local_30 [8];
  
  if (*(uint *)(param_2 + 4) < 4) {
    bVar2 = false;
    if (*param_2 != '\0') {
      bVar2 = *(char *)(param_1 + 0x1b0) == '\0';
    }
    eventBufferSetEnable(param_1 + 0x168,*param_2);
    if ((*(uint *)(param_2 + 4) & 2) == 0) {
      if ((*(uint *)(param_2 + 4) & 1) != 0) {
        eventBufferSetKeepNewest(param_1 + 0x168,0);
      }
    }
    else {
      eventBufferSetKeepNewest(param_1 + 0x168,1);
    }
    uVar1 = 0;
    if ((((bVar2) && (uVar1 = (ulong)*(uint *)(param_1 + 0xf0), *(uint *)(param_1 + 0xf0) != 0)) &&
        (uVar1 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0xf4),0,0,0x80000,&local_34),
        (int)uVar1 == 0)) &&
       (uVar1 = subdeviceGetByHandle_IMPL
                          (**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),
                           *(undefined4 *)(param_1 + 0xf0),local_30), (int)uVar1 == 0)) {
      rmGpuGroupLockRelease(local_34,0);
      uVar1 = uVar1 & 0xffffffff;
    }
    return uVar1;
  }
  return 0x1f;
}


// ===== 0049c040 eventbuffertBufferCtrlCmdUpdateGet_IMPL =====

undefined8 eventbuffertBufferCtrlCmdUpdateGet_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar1 = *param_2;
  lVar2 = *(long *)(param_1 + 0x118);
  uVar3 = eventBufferGetRecordBufferCount();
  if (uVar1 < uVar3) {
    uVar1 = param_2[1];
    if (lVar2 == 0) {
      if (uVar1 != 0) goto LAB_0049c0f0;
      eventBufferUpdateRecordBufferGet(param_1 + 0x168,*param_2);
    }
    else {
      uVar3 = eventBufferGetVardataBufferCount(param_1 + 0x168);
      if (uVar3 <= uVar1) goto LAB_0049c0f0;
      eventBufferUpdateRecordBufferGet(param_1 + 0x168,*param_2);
      eventBufferUpdateVardataBufferGet(param_1 + 0x168,param_2[1]);
    }
    *(undefined1 *)(param_1 + 0x15e) = 0;
    uVar4 = 0;
  }
  else {
LAB_0049c0f0:
    uVar4 = 0x1f;
  }
  return uVar4;
}


// ===== 0049c100 eventbuffertBufferCtrlCmdPostTelemetryEvent_IMPL =====

undefined8 eventbuffertBufferCtrlCmdPostTelemetryEvent_IMPL(void)

{
  return 0x56;
}


// ===== 0049c110 eventBufferAdd =====

undefined8
eventBufferAdd(long param_1,undefined8 param_2,undefined2 param_3,undefined1 *param_4,
              undefined8 *param_5)

{
  char cVar1;
  undefined8 uVar2;
  bool bVar3;
  
  if (*(char *)(param_1 + 0x1b0) != '\0') {
    if (*(uint *)(*(long *)(param_1 + 0x168) + 4) < *(uint *)(param_1 + 0x17c)) {
      eventBufferProducerAddEvent(param_1 + 0x168,param_3,0);
      bVar3 = false;
      if (*(char *)(param_1 + 0x15e) == '\0') {
        cVar1 = eventBufferIsNotifyThresholdMet(param_1 + 0x168);
        bVar3 = cVar1 != '\0';
      }
      *param_4 = bVar3;
      *param_5 = *(undefined8 *)(param_1 + 0x1a8);
      uVar2 = 0;
    }
    else {
      nvAssertFailedNoLog("pHeader->recordPut < pRBI->totalRecordCount",
                          "src/kernel/rmapi/event_buffer.c",0x2e8,param_2);
      uVar2 = 0x40;
    }
    return uVar2;
  }
  return 0x10006;
}


// ===== 0049c1e0 eventBufferIsEmpty =====

undefined8 eventBufferIsEmpty(long param_1)

{
  return CONCAT71((int7)((ulong)*(long *)(param_1 + 0x168) >> 8),
                  *(long *)(*(long *)(param_1 + 0x168) + 8) == 0);
}


// ===== 0049c200 eventGetEngineTypeFromSubNotifyIndex =====

undefined8 eventGetEngineTypeFromSubNotifyIndex(uint param_1,int *param_2)

{
  *param_2 = 0;
  if (param_1 == 0x7f) {
    *param_2 = 0x37;
  }
  else if (param_1 < 0x80) {
    if (param_1 == 0x19) {
      *param_2 = 0xb;
    }
    else if (param_1 < 0x1a) {
      if (param_1 == 0x12) {
        *param_2 = 0x21;
      }
      else if (param_1 < 0x13) {
        if (param_1 == 0xf) {
          *param_2 = 0x1e;
        }
        else if (param_1 < 0x10) {
          if (param_1 == 0xd) {
            *param_2 = 0x2b;
          }
          else if (param_1 == 0xe) {
            *param_2 = 0x1d;
          }
          else {
            if (param_1 != 0xc) goto LAB_0049c4c0;
            *param_2 = 1;
          }
        }
        else {
          *param_2 = (param_1 != 0x10) + 0x1f;
        }
      }
      else if (param_1 == 0x16) {
        *param_2 = 0x29;
      }
      else if (param_1 < 0x17) {
        if (param_1 == 0x14) {
          *param_2 = 0x23;
        }
        else {
          *param_2 = (param_1 == 0x15) + 0x22 + (uint)(param_1 == 0x15);
        }
      }
      else {
        *param_2 = (param_1 != 0x17) + 9;
      }
    }
    else if (param_1 == 0x20) {
      *param_2 = 0x12;
    }
    else if (param_1 < 0x21) {
      if (param_1 == 0x1d) {
        *param_2 = 0xf;
      }
      else if (param_1 < 0x1e) {
        if (param_1 == 0x1b) {
          *param_2 = 0xd;
        }
        else {
          *param_2 = (uint)(param_1 == 0x1c) * 2 + 0xc;
        }
      }
      else {
        *param_2 = (param_1 != 0x1e) + 0x10;
      }
    }
    else if (param_1 == 0x28) {
      *param_2 = 0x27;
    }
    else if (param_1 < 0x29) {
      if (param_1 == 0x26) {
        *param_2 = 0x25;
      }
      else if (param_1 == 0x27) {
        *param_2 = 0x26;
      }
      else {
        if (param_1 != 0x23) goto LAB_0049c4c0;
        *param_2 = 0x32;
      }
    }
    else if (param_1 == 0x73) {
      *param_2 = 0x31;
    }
    else {
      if (param_1 != 0x7e) {
LAB_0049c4c0:
        nvDbg_Printf("src/kernel/rmapi/event_notification.c",0x287,
                     "eventGetEngineTypeFromSubNotifyIndex",3,
                     "NVRM: notifier 0x%x doesn\'t use the fast non-stall interrupt path!\n",param_1
                    );
        nvAssertFailedNoLog(&DAT_00d9140e,"src/kernel/rmapi/event_notification.c",0x28a);
        return 0x56;
      }
      *param_2 = 0x36;
    }
  }
  else if (param_1 == 0x99) {
    *param_2 = 0x3e;
  }
  else if (param_1 < 0x9a) {
    if (param_1 == 0x92) {
      *param_2 = 2;
    }
    else if (param_1 < 0x93) {
      if (param_1 == 0x83) {
        *param_2 = 0x3b;
      }
      else if (param_1 < 0x84) {
        if (param_1 == 0x81) {
          *param_2 = 0x39;
        }
        else {
          *param_2 = (uint)(param_1 == 0x82) * 2 + 0x38;
        }
      }
      else if (param_1 == 0x84) {
        *param_2 = 0x3c;
      }
      else {
        if (param_1 != 0x85) goto LAB_0049c4c0;
        *param_2 = 0x3d;
      }
    }
    else if (param_1 == 0x96) {
      *param_2 = 6;
    }
    else if (param_1 < 0x97) {
      if (param_1 == 0x94) {
        *param_2 = 4;
      }
      else {
        *param_2 = (uint)(param_1 == 0x95) * 2 + 3;
      }
    }
    else {
      *param_2 = (param_1 != 0x97) + 7;
    }
  }
  else if (param_1 == 0xac) {
    *param_2 = 0x19;
  }
  else if (param_1 < 0xad) {
    if (param_1 == 0xa9) {
      *param_2 = 0x16;
    }
    else if (param_1 < 0xaa) {
      if (param_1 == 0xa7) {
        *param_2 = 0x14;
      }
      else if (param_1 == 0xa8) {
        *param_2 = 0x15;
      }
      else {
        if (param_1 != 0xa6) goto LAB_0049c4c0;
        *param_2 = 0x13;
      }
    }
    else {
      *param_2 = (param_1 != 0xaa) + 0x17;
    }
  }
  else if (param_1 == 0xaf) {
    *param_2 = 0x1c;
  }
  else if (param_1 < 0xb0) {
    *param_2 = (param_1 != 0xad) + 0x1a;
  }
  else if (param_1 == 0xb4) {
    *param_2 = 0x3f;
  }
  else {
    if (param_1 != 0xb7) goto LAB_0049c4c0;
    *param_2 = 0x28;
  }
  return 0;
}


// ===== 0049c710 _gpuEngineEventNotificationListNotify =====

int _gpuEngineEventNotificationListNotify(undefined8 param_1,undefined8 *param_2,int param_3)

{
  undefined8 *puVar1;
  int *piVar2;
  long *plVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  long lVar10;
  long lVar11;
  int iVar12;
  long *local_58 [5];
  
  portSyncSpinlockAcquire(*param_2);
  *(int *)(param_2 + 7) = *(int *)(param_2 + 7) + 1;
  listTail_IMPL(param_2 + 1);
  uVar7 = listHead_IMPL(param_2 + 1);
  listIterRange_IMPL(local_58,param_2 + 1,uVar7);
  puVar1 = param_2 + 4;
LAB_0049c770:
  cVar4 = listIterNext_IMPL(local_58);
  if (cVar4 != '\0') {
    do {
      if (param_3 != 0) {
        iVar6 = *(int *)(*local_58[0] + 4);
        while (iVar6 != param_3) {
          cVar4 = listIterNext_IMPL(local_58);
          if (cVar4 == '\0') goto LAB_0049c7db;
          iVar6 = *(int *)(*local_58[0] + 4);
        }
      }
      plVar3 = local_58[0];
      lVar10 = local_58[0][1];
      if ((((lVar10 != 0) && (*(char *)(lVar10 + 0x1c0) != '\0')) &&
          (*(long *)(lVar10 + 0x118) != 0)) && (*(char *)(*(long *)(lVar10 + 0x118) + 100) != '\0'))
      {
        lVar11 = memdescGetKernelMapping();
        if (lVar11 == 0) {
          nvDbg_Printf("src/kernel/rmapi/event_notification.c",0x13f,
                       "_gpuEngineEventNotificationListNotify",3,
                       "NVRM: Per-vGPU semaphore location mapping is NULL. Skipping the current node.\n"
                      );
          goto LAB_0049c770;
        }
        iVar6 = *(int *)(lVar11 + (ulong)(*(uint *)(lVar10 + 0x1bc) & 0xfffffffc));
        if (*(int *)(lVar10 + 0x1b8) == iVar6) goto LAB_0049c770;
        *(int *)(lVar10 + 0x1b8) = iVar6;
        if ((*(long *)(g_pSys + 0x238) != 0) &&
           (iVar6 = hypervisorInjectInterrupt_IMPL(*(long *)(g_pSys + 0x238),lVar10 + 0x1b8),
           iVar6 == 0)) goto LAB_0049c770;
      }
      LOCK();
      *(int *)((long)plVar3 + 0x34) = *(int *)((long)plVar3 + 0x34) + 1;
      UNLOCK();
      if ((char)plVar3[6] != '\0') goto LAB_0049c770;
      *(undefined1 *)(plVar3 + 6) = 1;
      listAppendExisting_IMPL(puVar1,plVar3);
      cVar4 = listIterNext_IMPL(local_58);
      if (cVar4 == '\0') break;
    } while( true );
  }
LAB_0049c7db:
  iVar6 = 0;
  puVar8 = (undefined8 *)listHead_IMPL(puVar1);
  puVar9 = (undefined8 *)listTail_IMPL(puVar1);
  portSyncSpinlockRelease(*param_2);
  for (; puVar8 != (undefined8 *)0x0; puVar8 = (undefined8 *)listNext_IMPL(puVar1,puVar8)) {
    piVar2 = (int *)((long)puVar8 + 0x34);
    do {
      iVar12 = *piVar2;
      if (iVar12 < 1) {
        if (iVar12 == 0) goto LAB_0049c84f;
        break;
      }
      LOCK();
      iVar5 = *piVar2;
      if (iVar12 == iVar5) {
        *piVar2 = 0;
      }
      UNLOCK();
    } while (iVar12 != iVar5);
    do {
      iVar5 = osNotifyEvent(param_1,*puVar8,0,0,0);
      if ((iVar5 != 0) &&
         (nvAssertOkFailedNoLog
                    (iVar5,"osNotifyEvent(pGpu, pIter->pEventNotify, 0, 0, NV_OK)",
                     "src/kernel/rmapi/event_notification.c"), iVar6 == 0)) {
        iVar6 = iVar5;
      }
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
LAB_0049c84f:
    if (puVar9 == puVar8) break;
  }
  portSyncSpinlockAcquire(*param_2);
  piVar2 = (int *)(param_2 + 7);
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    lVar10 = listHead_IMPL(puVar1);
    while (lVar10 != 0) {
      lVar11 = listNext_IMPL(puVar1,lVar10);
      if (*(int *)(lVar10 + 0x34) != 0) {
        nvAssertFailedNoLog("pIter->pendingNotifyCount == 0","src/kernel/rmapi/event_notification.c"
                            ,0x1b7);
      }
      *(undefined1 *)(lVar10 + 0x30) = 0;
      listRemoveIntrusive_IMPL(puVar1,lVar10);
      lVar10 = lVar11;
    }
  }
  portSyncSpinlockRelease(*param_2);
  return iVar6;
}


// ===== 0049ca20 _removeEventNotification.constprop.0 =====

undefined8
_removeEventNotification_constprop_0
          (undefined8 *param_1,int param_2,int param_3,char param_4,long param_5,undefined8 *param_6
          )

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)0x0) {
    if (((*piVar2 == param_2) && (piVar2[1] == param_3)) &&
       ((param_4 == '\0' || (*(long *)(piVar2 + 10) == param_5)))) {
      *param_1 = *(undefined8 *)(piVar2 + 0x10);
LAB_0049ca8b:
      if (*(long *)(piVar2 + 0xe) != 0) {
        if (*(long *)(piVar2 + 0xc) == 0) {
          nvAssertFailedNoLog("(nextEvent->pGpu != NULL)","src/kernel/rmapi/event_notification.c",
                              0x3f1);
          return 0x40;
        }
        tmrEventDestroy_IMPL(*(undefined8 *)(*(long *)(piVar2 + 0xc) + 0x1b88));
        piVar2[0xc] = 0;
        piVar2[0xd] = 0;
        piVar2[0xe] = 0;
        piVar2[0xf] = 0;
      }
      if ((char)piVar2[5] != '\0') {
        osDereferenceObjectCount(*(undefined8 *)(piVar2 + 10));
      }
      *param_6 = piVar2;
      return 0;
    }
    piVar1 = piVar2;
    for (piVar2 = *(int **)(piVar2 + 0x10); piVar2 != (int *)0x0; piVar2 = *(int **)(piVar2 + 0x10))
    {
      if (((param_2 == *piVar2) && (param_3 == piVar2[1])) &&
         ((param_4 == '\0' || (param_5 == *(long *)(piVar2 + 10))))) {
        *(undefined8 *)(piVar1 + 0x10) = *(undefined8 *)(piVar2 + 0x10);
        goto LAB_0049ca8b;
      }
      piVar1 = piVar2;
    }
  }
  return 0xffff;
}


// ===== 0049cb50 gpuEngineEventNotificationListDestroy =====

void gpuEngineEventNotificationListDestroy(undefined8 param_1,long *param_2)

{
  int iVar1;
  
  if (param_2 != (long *)0x0) {
    if ((int)param_2[7] != 0) {
      nvAssertFailedNoLog("pEventNotificationList->activeNotifyThreads == 0",
                          "src/kernel/rmapi/event_notification.c",0xa4);
    }
    iVar1 = listCount_IMPL(param_2 + 4);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("listCount(&pEventNotificationList->pendingEventNotifyList) == 0",
                          "src/kernel/rmapi/event_notification.c",0xa6);
    }
    listDestroyIntrusive_IMPL(param_2 + 4);
    iVar1 = listCount_IMPL(param_2 + 1);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("listCount(&pEventNotificationList->eventNotificationList) == 0",
                          "src/kernel/rmapi/event_notification.c",0xa9);
    }
    listDestroyIntrusive_IMPL(param_2 + 1);
    if (*param_2 != 0) {
      portSyncSpinlockDestroy();
    }
    portMemFree(param_2);
    return;
  }
  return;
}


// ===== 0049cc30 gpuEngineEventNotificationListCreate =====

undefined8 gpuEngineEventNotificationListCreate(undefined8 param_1,long *param_2)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  plVar2 = (long *)portMemAllocNonPaged(0x40);
  if (plVar2 != (long *)0x0) {
    portMemSet(plVar2,0,0x40);
    lVar3 = portSyncSpinlockCreate(uVar1);
    *plVar2 = lVar3;
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pEventNotificationList->pSpinlock != NULL",
                          "src/kernel/rmapi/event_notification.c",0x88);
      gpuEngineEventNotificationListDestroy(param_1,plVar2);
      uVar1 = 0x1a;
    }
    else {
      listInitIntrusive_IMPL(plVar2 + 1,0x10);
      listInitIntrusive_IMPL(plVar2 + 4,0x20);
      *(undefined4 *)(plVar2 + 7) = 0;
      uVar1 = 0;
      *param_2 = (long)plVar2;
    }
    return uVar1;
  }
  nvAssertFailedNoLog("pEventNotificationList != NULL","src/kernel/rmapi/event_notification.c",0x83)
  ;
  return 0x51;
}


// ===== 0049cd30 engineNonStallIntrNotify =====

undefined8 engineNonStallIntrNotify(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_2 < 0x54) {
    uVar1 = _gpuEngineEventNotificationListNotify
                      (param_1,*(undefined8 *)(param_1 + 0x500 + (ulong)param_2 * 8),0);
    return uVar1;
  }
  nvAssertFailedNoLog("rmEngineId < NV_ARRAY_ELEMENTS(pGpu->engineNonstallIntrEventNotifications)",
                      "src/kernel/rmapi/event_notification.c",0x1c6);
  return 0x1f;
}


// ===== 0049cd80 engineNonStallIntrNotifyEvent =====

undefined8 engineNonStallIntrNotifyEvent(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_2 < 0x54) {
    uVar1 = _gpuEngineEventNotificationListNotify
                      (param_1,*(undefined8 *)(param_1 + 0x500 + (ulong)param_2 * 8));
    return uVar1;
  }
  nvAssertFailedNoLog("rmEngineId < NV_ARRAY_ELEMENTS(pGpu->engineNonstallIntrEventNotifications)",
                      "src/kernel/rmapi/event_notification.c",0x1cf);
  return 0x1f;
}


// ===== 0049cdd0 registerEventNotification =====

int registerEventNotification
              (long *param_1,long param_2,undefined4 param_3,undefined4 param_4,uint param_5,
              undefined4 param_6,undefined8 param_7,undefined1 param_8)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  byte bVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  uint uVar13;
  bool bVar14;
  uint local_68;
  uint local_64;
  undefined8 local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  local_60 = 0;
  local_50 = 0;
  puVar9 = (undefined4 *)portMemAllocNonPaged(0x48);
  if (puVar9 == (undefined4 *)0x0) {
    iVar7 = 0x51;
    goto LAB_0049d0f5;
  }
  puVar9[4] = param_6;
  *puVar9 = uVar1;
  puVar9[1] = param_4;
  puVar9[2] = 0;
  bVar4 = (byte)(param_5 >> 0x18);
  *(byte *)((long)puVar9 + 0x15) = bVar4 >> 7;
  bVar14 = (param_5 & 0x20000000) != 0;
  *(undefined8 *)(puVar9 + 10) = param_7;
  uVar13 = param_5 >> 0x10 & 0xff;
  *(bool *)((long)puVar9 + 0x17) = bVar14;
  if (!bVar14) {
    uVar13 = 0;
  }
  puVar9[8] = 0;
  *(undefined8 *)(puVar9 + 0xc) = 0;
  puVar9[6] = uVar13;
  *(undefined8 *)(puVar9 + 0xe) = 0;
  *(byte *)(puVar9 + 7) = bVar4 >> 4 & 1 ^ 1;
  *(byte *)((long)puVar9 + 0x16) = bVar4 >> 2 & 1;
  puVar9[3] = param_5 & 0xffff;
  uVar13 = param_5 >> 0x1b & 1;
  *(char *)((long)puVar9 + 0x1d) = (char)uVar13;
  *(undefined1 *)(puVar9 + 5) = param_8;
  *(long *)(puVar9 + 0x10) = *param_1;
  *param_1 = (long)puVar9;
  if (uVar13 == 0) {
    return 0;
  }
  iVar7 = clientGetResourceRef_IMPL(param_2,param_3,&local_58);
  if ((iVar7 == 0) &&
     (lVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_58 + 8),__nvoc_class_def_Subdevice),
     lVar10 != 0)) {
    lVar11 = __nvoc_dynamicCast(*(undefined8 *)(local_58 + 8),__nvoc_class_def_Subdevice);
    lVar10 = *(long *)(*(long *)(lVar11 + 0x158) + 0xe0);
    iVar7 = eventGetEngineTypeFromSubNotifyIndex(param_5 & 0xffff,&local_68);
    if (iVar7 == 0) {
      if (((lVar10 == 0) || (*(long *)(lVar10 + 0x1bc0) == 0)) ||
         (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar10), uVar13 = local_68, cVar6 == '\0'))
      {
LAB_0049d000:
        if ((*(int *)(lVar11 + 0x680) == 0) ||
           (iVar7 = memGetByHandle_IMPL(**(undefined8 **)(*(long *)(lVar11 + 0x140) + 0x48),
                                        *(int *)(lVar11 + 0x680),&local_50), iVar7 == 0)) {
          lVar5 = local_50;
          lVar11 = *param_1;
          if (lVar11 == 0) {
            nvCheckFailedNoLog(4,"pEventNotify != NULL","src/kernel/rmapi/event_notification.c",0xe0
                              );
            goto LAB_0049d0d0;
          }
          puVar3 = *(undefined8 **)(lVar10 + 0x500 + (ulong)local_68 * 8);
          plVar12 = (long *)portMemAllocNonPaged(0x38);
          if (plVar12 != (long *)0x0) {
            portMemSet(plVar12,0,0x38);
            *plVar12 = lVar11;
            plVar12[1] = lVar5;
            while (portSyncSpinlockAcquire(*puVar3), *(int *)(puVar3 + 7) != 0) {
              portSyncSpinlockRelease(*puVar3);
              iVar7 = *(int *)(puVar3 + 7);
              while (iVar7 != 0) {
                osSpinLoop();
                iVar7 = *(int *)(puVar3 + 7);
              }
            }
            listPrependExisting_IMPL(puVar3 + 1,plVar12);
            portSyncSpinlockRelease(*puVar3);
            return 0;
          }
          nvCheckFailedNoLog(4,"pEngineEventNotification != NULL",
                             "src/kernel/rmapi/event_notification.c",0xe7);
          iVar7 = 0x51;
        }
      }
      else {
        uVar2 = *(undefined8 *)(lVar10 + 0x1bc0);
        local_64 = local_68;
        iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL
                          (lVar10,uVar2,*(undefined8 *)(*(long *)(lVar11 + 0x158) + 0xe8),&local_48)
        ;
        if (iVar7 == 0) {
          iVar7 = kmigmgrGetLocalToGlobalEngineType_IMPL
                            (lVar10,uVar2,local_48,local_40,uVar13,&local_64);
          if (iVar7 == 0) {
            local_68 = local_64;
            goto LAB_0049d000;
          }
          nvCheckOkFailedNoLog
                    (4,iVar7,
                     "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineId, &globalRmEngineId)"
                     ,"src/kernel/rmapi/event_notification.c",0x2d3);
        }
        else {
          nvCheckOkFailedNoLog
                    (4,iVar7,
                     "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pSubDevice), &ref)"
                     ,"src/kernel/rmapi/event_notification.c",0x2ce);
        }
      }
    }
    else {
      iVar7 = 0x56;
    }
  }
  else {
LAB_0049d0d0:
    iVar7 = 0x1f;
  }
  iVar8 = _removeEventNotification_constprop_0(param_1,uVar1,param_4,1,param_7,&local_60);
  if (iVar8 == 0) {
    portMemFree(local_60);
  }
LAB_0049d0f5:
  nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/rmapi/event_notification.c",0x2f8);
  return iVar7;
}


// ===== 0049d200 unregisterEventNotificationWithData =====

int unregisterEventNotificationWithData
              (undefined8 param_1,ulong param_2,undefined4 param_3,undefined4 param_4,
              undefined1 param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long **local_80;
  uint local_70;
  uint local_6c;
  long local_68;
  long local_60;
  long *local_58;
  undefined8 local_50;
  
  local_68 = 0;
  iVar5 = _removeEventNotification_constprop_0(param_1,param_2,param_4,param_5,param_6,&local_68);
  lVar3 = local_68;
  if (iVar5 == 0) {
    if (*(char *)(local_68 + 0x1d) == '\0') {
      portMemFree(local_68);
      return 0;
    }
    iVar5 = serverutilGetResourceRef(param_2 & 0xffffffff,param_3,&local_60);
    if ((iVar5 == 0) &&
       (lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_60 + 8),__nvoc_class_def_Subdevice),
       lVar6 != 0)) {
      lVar7 = __nvoc_dynamicCast(*(undefined8 *)(local_60 + 8),__nvoc_class_def_Subdevice);
      lVar6 = *(long *)(*(long *)(lVar7 + 0x158) + 0xe0);
      iVar5 = eventGetEngineTypeFromSubNotifyIndex(*(undefined4 *)(lVar3 + 0xc),&local_70);
      if (iVar5 == 0) {
        if ((lVar6 != 0) && (*(long *)(lVar6 + 0x1bc0) != 0)) {
          cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar6);
          if (cVar4 != '\0') {
            local_6c = local_70;
            uVar8 = *(undefined8 *)(lVar6 + 0x1bc0);
            iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL
                              (lVar6,uVar8,*(undefined8 *)(*(long *)(lVar7 + 0x158) + 0xe8),
                               &local_58);
            if (iVar5 == 0) {
              iVar5 = kmigmgrGetLocalToGlobalEngineType_IMPL
                                (lVar6,uVar8,local_58,local_50,local_70,&local_6c);
              local_70 = local_6c;
              if (iVar5 == 0) goto LAB_0049d327;
              nvCheckOkFailedNoLog
                        (4,iVar5,
                         "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineId, &globalRmEngineId)"
                         ,"src/kernel/rmapi/event_notification.c",0x3a9);
            }
            else {
              nvCheckOkFailedNoLog
                        (4,iVar5,
                         "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pSubDevice), &ref)"
                         ,"src/kernel/rmapi/event_notification.c",0x3a4);
            }
            portMemFree(lVar3);
            goto LAB_0049d372;
          }
        }
LAB_0049d327:
        local_80 = &local_58;
        puVar2 = *(undefined8 **)(lVar6 + 0x500 + (ulong)local_70 * 8);
        while (portSyncSpinlockAcquire(*puVar2), *(int *)(puVar2 + 7) != 0) {
          portSyncSpinlockRelease(*puVar2);
          iVar5 = *(int *)(puVar2 + 7);
          while (iVar5 != 0) {
            osSpinLoop();
            iVar5 = *(int *)(puVar2 + 7);
          }
        }
        puVar1 = puVar2 + 1;
        uVar8 = listTail_IMPL(puVar1);
        uVar9 = listHead_IMPL(puVar1);
        listIterRange_IMPL(local_80,puVar1,uVar9,uVar8);
        do {
          cVar4 = listIterNext_IMPL(local_80);
          if (cVar4 == '\0') {
            portSyncSpinlockRelease(*puVar2);
            nvAssertFailedNoLog("pEngineEventNotification != NULL",
                                "src/kernel/rmapi/event_notification.c",0x113);
            local_58 = (long *)0x0;
            goto LAB_0049d408;
          }
        } while (lVar3 != *local_58);
        listRemoveIntrusive_IMPL(puVar1,local_58);
        portSyncSpinlockRelease(*puVar2);
LAB_0049d408:
        portMemFree(local_58);
        portMemFree(lVar3);
        return 0;
      }
      iVar5 = 0x56;
      portMemFree(lVar3);
    }
    else {
      iVar5 = 0x1f;
      portMemFree(lVar3);
    }
  }
LAB_0049d372:
  nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/rmapi/event_notification.c",0x3b9);
  return iVar5;
}


// ===== 0049d520 unregisterEventNotification =====

void unregisterEventNotification(void)

{
  unregisterEventNotificationWithData();
  return;
}


// ===== 0049d530 notifyEvents =====

undefined4
notifyEvents(undefined8 param_1,long param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  nvDbg_Printf("src/kernel/rmapi/event_notification.c",0x410,"notifyEvents",1,
               "NVRM:   Method = 0x%x\n",param_4);
  nvDbg_Printf("src/kernel/rmapi/event_notification.c",0x411,"notifyEvents",1,
               "NVRM:   Data   = 0x%x\n",param_5);
  nvDbg_Printf("src/kernel/rmapi/event_notification.c",0x412,"notifyEvents",1,
               "NVRM:   Status = 0x%x\n",param_6);
  nvDbg_Printf("src/kernel/rmapi/event_notification.c",0x413,"notifyEvents",1,
               "NVRM:   Action = 0x%x\n",param_7);
  uVar3 = 0x28;
  if (param_7 == 1) {
    uVar3 = 0;
    for (; param_2 != 0; param_2 = *(long *)(param_2 + 0x40)) {
      if (*(char *)(param_2 + 0x17) == '\0') {
        iVar2 = *(int *)(param_2 + 0xc);
joined_r0x0049d634:
        if (iVar2 == param_3) {
          if (*(char *)(param_2 + 0x15) == '\0') {
            uVar3 = osNotifyEvent(param_1,param_2,param_4,param_5,param_6);
          }
          else {
            piVar1 = (int *)(param_2 + 0x20);
            *piVar1 = *piVar1 + 1;
            if (*piVar1 == 0) {
              uVar3 = osNotifyEvent(param_1,param_2,param_4,param_5,param_6);
              *(undefined4 *)(param_2 + 0x20) = 0;
            }
          }
        }
      }
      else {
        iVar2 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
        if (iVar2 == *(int *)(param_2 + 0x18)) {
          iVar2 = *(int *)(param_2 + 0xc);
          goto joined_r0x0049d634;
        }
      }
    }
  }
  return uVar3;
}


// ===== 0049d6b0 inotifyConstruct_IMPL =====

byte inotifyConstruct_IMPL(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_1,__nvoc_class_def_RsResource);
  return -(lVar1 == 0) & 0x31;
}


// ===== 0049d6d0 inotifyDestruct_IMPL =====

void inotifyDestruct_IMPL(void)

{
  return;
}


// ===== 0049d6e0 inotifyGetNotificationList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 inotifyGetNotificationList_IMPL(long *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)(**(code **)(*param_1 + 0x18))();
  uVar2 = 0;
  if (puVar1 != (undefined8 *)0x0) {
    uVar2 = *puVar1;
  }
  return uVar2;
}


// ===== 0049d700 notifyConstruct_IMPL =====

undefined8 notifyConstruct_IMPL(void)

{
  return 0;
}


// ===== 0049d707 notifyDestruct_IMPL.cold =====

void notifyDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


