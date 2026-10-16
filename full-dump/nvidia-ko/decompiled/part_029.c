// ===== 002da890 kbusSendSysmembar_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusSendSysmembar_IMPL(long param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return 0;
  }
  iVar1 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x3e0))();
  if (iVar1 != 0x65) {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 002da8e0 kbusSendSysmembarSingle_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusSendSysmembarSingle_KERNEL(long param_1)

{
  (**(code **)(param_1 + 0x3b90))
            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
             0x20800a70,0,0);
  return;
}


// ===== 002da910 kbusCommitBar2_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusCommitBar2_KERNEL(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  ulong uVar2;
  
  if ((((*(char *)(param_1 + 0x454) != '\0') && (*(char *)(param_1 + 0x4915) != '\0')) ||
      (*(char *)(param_2 + 0xad0c) != '\0')) || ((param_3 & 0x20) != 0)) {
    return 0;
  }
  uVar1 = kbusInitVirtualBar2_VBAR2();
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,"kbusInitVirtualBar2_HAL(pGpu, pKernelBus)","src/kernel/gpu/bus/kern_bus.c",
               0x1d5);
    return (ulong)uVar1;
  }
  uVar2 = (**(code **)(param_2 + 0x228))(param_1);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,"kbusSetupCpuPointerForBusFlush_HAL(pGpu, pKernelBus)",
             "src/kernel/gpu/bus/kern_bus.c",0x1d6);
  return uVar2 & 0xffffffff;
}


// ===== 002da9d0 kbusGetPciBarSize_IMPL =====

undefined8 kbusGetPciBarSize_IMPL(long param_1,uint param_2)

{
  if (param_2 < *(uint *)(param_1 + 0x55c)) {
    return *(undefined8 *)(param_1 + 0x5a0 + (ulong)param_2 * 8);
  }
  nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x1e1,"kbusGetPciBarSize_IMPL",4,
               "NVRM: bad index 0x%x\n",param_2);
  return 0;
}


// ===== 002daa30 kbusGetPciBarOffset_IMPL =====

undefined8 kbusGetPciBarOffset_IMPL(long param_1,uint param_2)

{
  if (param_2 < *(uint *)(param_1 + 0x55c)) {
    return *(undefined8 *)(param_1 + 0x560 + (ulong)param_2 * 8);
  }
  nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",499,"kbusGetPciBarOffset_IMPL",4,
               "NVRM: bad index 0x%x\n",param_2);
  return 0;
}


// ===== 002daa90 kbusDetermineBar1Force64KBMapping_IMPL =====

void kbusDetermineBar1Force64KBMapping_IMPL(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  int local_1c [3];
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar2 = gpuEngineGetGpu(uVar2);
  *(undefined1 *)(param_1 + 0xad03) = 1;
  iVar1 = osReadRegistryDword(uVar2,"RM64KBBAR1Mappings",local_1c);
  if (iVar1 == 0) {
    if (local_1c[0] == 0) {
      *(undefined1 *)(param_1 + 0xad03) = 0;
    }
  }
  else {
    if (*(uint *)(param_1 + 0x55c) < 2) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x1e1,"kbusGetPciBarSize_IMPL",4,
                   "NVRM: bad index 0x%x\n",1);
      return;
    }
    if (0x100 < (uint)(*(ulong *)(param_1 + 0x5a8) >> 0x14)) {
      *(undefined1 *)(param_1 + 0xad03) = 0;
    }
  }
  return;
}


// ===== 002dab50 kbusDetermineBar1ApertureLength_IMPL =====

void kbusDetermineBar1ApertureLength_IMPL(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint local_1c;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar3);
  if (param_2 == 0) {
    if (*(uint *)(param_1 + 0x55c) < 2) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x1e1,"kbusGetPciBarSize_IMPL",4,
                   "NVRM: bad index 0x%x\n",1);
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined8 *)(param_1 + 0x5a8);
    }
    *(undefined8 *)(param_1 + 0x620) = uVar3;
  }
  else {
    *(undefined8 *)(param_1 + 0x620 + (ulong)param_2 * 0x100) = *(undefined8 *)(lVar2 + 0x3a78);
  }
  iVar1 = osReadRegistryDword(lVar2,"RMBar1ApertureSizeMB",&local_1c);
  if ((iVar1 == 0) && (local_1c != 0)) {
    lVar2 = (ulong)param_2 * 0x100;
    if ((ulong)local_1c << 0x14 < *(ulong *)(param_1 + 0x620 + lVar2)) {
      *(ulong *)(param_1 + 0x620 + lVar2) = (ulong)local_1c << 0x14;
    }
  }
  return;
}


// ===== 002dac40 kbusInitBarsSize_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusInitBarsSize_KERNEL(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 *puVar5;
  uint local_e0 [4];
  undefined8 local_d0 [24];
  
  if (*(char *)(param_2 + 0x5e0) != '\0') {
    nvAssertFailedNoLog("! pKernelBus->bPciBarSizesValid","src/kernel/gpu/bus/kern_bus.c",599);
  }
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20801803,local_e0,200);
  if (iVar2 == 0) {
    if (local_e0[0] != 0) {
      puVar5 = local_d0;
      lVar3 = param_2;
      do {
        uVar1 = *puVar5;
        lVar4 = lVar3 + 8;
        puVar5 = puVar5 + 3;
        *(undefined8 *)(lVar3 + 0x5a0) = uVar1;
        lVar3 = lVar4;
      } while (lVar4 != param_2 + (ulong)local_e0[0] * 8);
    }
    *(undefined1 *)(param_2 + 0x5e0) = 1;
    return 0;
  }
  nvCheckOkFailedNoLog
            (4,iVar2,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_BUS_GET_PCI_BAR_INFO, &params, sizeof(params))"
             ,"src/kernel/gpu/bus/kern_bus.c",0x259);
  return iVar2;
}


// ===== 002dad70 kbusDestroyMailbox_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void kbusDestroyMailbox_IMPL(long param_1,long param_2,long param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  undefined8 local_4c;
  undefined8 local_44;
  undefined4 local_3c;
  
  cVar1 = (**(code **)(param_2 + 0x2e0))();
  bVar3 = true;
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*(long *)(&DAT_00001b90 + param_3) + 0x2e0))
                      (param_3,*(long *)(&DAT_00001b90 + param_3),param_1);
    bVar3 = cVar1 != '\0';
  }
  local_4c = 0;
  local_44 = 0;
  local_3c = 0;
  (**(code **)(param_2 + 0x268))(param_1,param_2,param_4,*(code **)(param_2 + 0x268));
  local_4c._0_5_ = CONCAT14(bVar3,param_4);
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a73,&local_4c,8);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/kern_bus.c",0x289);
  }
  local_44 = CONCAT44(1 << ((byte)param_4 & 0x1f),(undefined4)local_44);
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a88,&local_44,0xc);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/kern_bus.c",0x291);
  }
  return;
}


// ===== 002daed0 kbusCpuOffsetInBar2WindowGet_IMPL =====

long kbusCpuOffsetInBar2WindowGet_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_2 + 0x7c98);
  if (lVar2 != 0) {
    if (*(int *)(param_3 + 0x68) == 2) {
      lVar1 = memdescGetPhysAddr(param_3,1,0);
      lVar2 = lVar2 + lVar1;
    }
    else {
      lVar2 = 0;
      nvAssertFailedNoLog("ADDR_FBMEM == pMemDesc->_addressSpace","src/kernel/gpu/bus/kern_bus.c",
                          0x29d);
    }
    return lVar2;
  }
  nvAssertFailedNoLog("NULL != pKernelBus->virtualBar2[GPU_GFID_PF].pCpuMapping",
                      "src/kernel/gpu/bus/kern_bus.c",0x29c);
  return 0;
}


// ===== 002daf60 kbusGetVaLimitForBar2_FWCLIENT =====

long kbusGetVaLimitForBar2_FWCLIENT(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x4628);
  nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x2b6,"kbusGetVaLimitForBar2_FWCLIENT",1,
               "NVRM: va limit: 0x%llx\n",lVar1);
  if ((*(long *)(param_2 + 18000) != lVar1) && (*(long *)(param_2 + 18000) != 0)) {
    nvAssertFailedNoLog("pKernelBus->bar2[GPU_GFID_PF].vaLimit == 0 || pKernelBus->bar2[GPU_GFID_PF].vaLimit == limit"
                        ,"src/kernel/gpu/bus/kern_bus.c",700);
  }
  return lVar1;
}


// ===== 002dafe0 kbusGetVaLimitForBar2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusGetVaLimitForBar2_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  uint local_1c;
  
  iVar2 = vgpuGetCallingContextGfid(param_1,&local_1c);
  if (iVar2 == 0) {
    if ((*(char *)(param_1 + 0x908) == '\0') ||
       ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) {
      (**(code **)(param_2 + 0x1e0))(param_1,param_2,local_1c);
      lVar3 = (ulong)local_1c * 0xd8 + param_2;
      uVar4 = *(ulong *)(lVar3 + 0x4638);
      if (uVar4 <= *(ulong *)(lVar3 + 0x4630)) {
        uVar4 = *(ulong *)(lVar3 + 0x4628);
      }
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x2e9,"kbusGetVaLimitForBar2_IMPL",1,
                   "NVRM: va limit: 0x%llx\n",uVar4);
      uVar1 = *(ulong *)(param_2 + 18000 + (ulong)local_1c * 0xd8);
      if ((uVar1 != uVar4) && (uVar1 != 0)) {
        nvAssertFailedNoLog("pKernelBus->bar2[gfid].vaLimit == 0 || pKernelBus->bar2[gfid].vaLimit == limit"
                            ,"src/kernel/gpu/bus/kern_bus.c",0x2ee);
      }
      return uVar4;
    }
  }
  else {
    nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                        "src/kernel/gpu/bus/kern_bus.c",0x2ce);
  }
  return 0;
}


// ===== 002db100 kbusPatchBar1Pdb_GSPCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusPatchBar1Pdb_GSPCLIENT(long param_1,long param_2)

{
  long lVar1;
  char *pcVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  plVar6 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 0x630),__nvoc_class_def_OBJGVASPACE)
  ;
  lVar1 = *(long *)(param_1 + 0x1b98);
  local_70 = 0;
  plVar7 = (long *)gvaspaceGetGpuState_IMPL(plVar6,param_1);
  pcVar2 = *(char **)(*plVar7 + 8);
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  iVar4 = (uint)(byte)pcVar2[2] << ((pcVar2[1] - *pcVar2) + 1U & 0x1f);
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  lVar8 = gpuGetGspStaticInfo(param_1);
  iVar5 = memdescCreate(&local_70,param_1,iVar4,0x1000,1,2,*(undefined4 *)(lVar1 + 0x57c),0);
  if (iVar5 == 0) {
    memdescDescribe(local_70,2,*(undefined8 *)(lVar8 + 0x5e0),iVar4);
    memdescSetPageSize(local_70,*(undefined8 *)(*(long *)(param_2 + 0x630) + 0x50),0x1000);
    iVar5 = gvaspaceWalkUserCtxAcquire_IMPL(plVar6,param_1,0,&local_68);
    uVar3 = local_70;
    if (iVar5 == 0) {
      uVar9 = (**(code **)(**(long **)(param_2 + 0x630) + 0x58))();
      iVar5 = mmuWalkModifyLevelInstance(plVar7[1],pcVar2,uVar9,uVar3,iVar4,1,1,0);
      gvaspaceWalkUserCtxRelease_IMPL(plVar6,&local_68);
      if (iVar5 == 0) {
        (**(code **)(*plVar6 + 0x1b8))(plVar6,param_1,1);
        return 0;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar5,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, NULL, &userCtx)",
                 "src/kernel/gpu/bus/kern_bus.c",0x315);
    }
    nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x32a,"kbusPatchBar1Pdb_GSPCLIENT",4,
                 "NVRM: Failed to modify CPU-RM\'s BAR1 PDB to GSP-RM\'s BAR1 PDB.\n");
    memdescDestroy(local_70);
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar5,
               "memdescCreate(&pMemDesc, pGpu, rootSize, RM_PAGE_SIZE, NV_TRUE, ADDR_FBMEM, kgmmuGetPTEAttr(pKernelGmmu), MEMDESC_FLAGS_NONE)"
               ,"src/kernel/gpu/bus/kern_bus.c",0x30e);
  }
  return iVar5;
}


// ===== 002db340 kbusPatchBar2Pdb_GSPCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

int kbusPatchBar2Pdb_GSPCLIENT(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 local_68;
  ulong local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar6 = gpuGetGspStaticInfo();
  uVar1 = *(undefined8 *)(param_2 + 0x7ca8);
  puVar2 = *(undefined1 **)(*(long *)(param_2 + 0x46c0) + 8);
  iVar3 = memdescCreate(&local_68,param_1,*(undefined4 *)(param_2 + 0x46cc),0x1000,1,2,
                        *(undefined4 *)(param_2 + 0xad38),0);
  if (iVar3 == 0) {
    memdescDescribe(local_68,2,*(undefined8 *)(lVar6 + 0x5e8),*(undefined4 *)(param_2 + 0x46cc));
    *(undefined8 *)(param_2 + 0x7ca8) = local_68;
    if (*(char *)(param_2 + 0xad0c) == '\0') {
      uVar4 = regRead032(param_1 + 0x3a18,0,0,*(undefined4 *)(param_2 + 0x4618),0);
      lVar6 = regRead032(param_1 + 0x3a18,0,0,(int)*(undefined8 *)(param_2 + 0x4618) + 4,0);
      local_60 = lVar6 << 0x20 | (ulong)uVar4;
    }
    else {
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      local_58 = uVar1;
      iVar5 = memmgrMemRead_IMPL(*(undefined8 *)(param_1 + 0x1b78),&local_58,&local_60,puVar2[2],0);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "memmgrMemRead(pMemoryManager, &surf, &entryValue, pRootFmt->entrySize, TRANSFER_FLAGS_NONE)"
                   ,"src/kernel/gpu/bus/kern_bus.c",0x36d);
        return iVar5;
      }
    }
    lVar6 = gpuGetRpc(param_1);
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/kern_bus.c",0x37b);
    }
    else {
      (**(code **)(lVar6 + 0x490))(param_1,lVar6,1,local_60,*puVar2,*(code **)(lVar6 + 0x490));
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar3,
               "memdescCreate(&pMemDesc, pGpu, pKernelBus->bar2[GPU_GFID_PF].pageDirSize, RM_PAGE_SIZE, NV_TRUE, ADDR_FBMEM, pKernelBus->PDEBAR2Attr, MEMDESC_FLAGS_NONE)"
               ,"src/kernel/gpu/bus/kern_bus.c",0x357);
  }
  return iVar3;
}


// ===== 002db530 kbusGetDeviceCaps_IMPL =====

void kbusGetDeviceCaps_IMPL(long param_1,undefined8 param_2,long param_3,char param_4)

{
  long lVar1;
  undefined1 local_2b [2];
  byte local_29;
  
  lVar1 = *(long *)(g_pSys + 0x208);
  portMemSet(local_2b,0,3);
  if (*(char *)(lVar1 + 0x68) == '\0') {
    local_29 = local_29 | 0x40;
  }
  if ((*(short *)(lVar1 + 0xaa) == 0x10de) &&
     ((*(char *)(param_1 + 0x478) != '\0' || ((ushort)(*(short *)(lVar1 + 0xa8) - 0x800U) < 8)))) {
    local_29 = local_29 | 0x20;
  }
  if (param_4 == '\0') {
    portMemCopy(param_3,3,local_2b,3);
    return;
  }
  *(byte *)(param_3 + 2) =
       (local_29 | *(byte *)(param_3 + 2)) & 0x20 | *(byte *)(param_3 + 2) & 0xdf;
  return;
}


// ===== 002db610 kbusConvertBusMapFlagsToDmaFlags_IMPL =====

uint kbusConvertBusMapFlagsToDmaFlags_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 uVar5;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (param_3 & 0x40) << 9;
  if (*(int *)(param_2 + 0x74) == 0) {
    uVar3 = uVar3 | 0x10;
  }
  if ((param_3 & 4) != 0) {
    uVar3 = uVar3 | 0x4000;
  }
  if ((param_3 & 2) != 0) {
    uVar3 = uVar3 | 0x10000;
  }
  if ((param_3 & 8) == 0) {
    if ((param_3 & 0x10) != 0) {
      uVar3 = uVar3 | 2;
    }
  }
  else {
    if ((param_3 & 0x10) != 0) {
      nvAssertFailedNoLog("!((busMapFlags & BUS_MAP_FB_FLAGS_READ_ONLY) && (busMapFlags & BUS_MAP_FB_FLAGS_WRITE_ONLY))"
                          ,"src/kernel/gpu/bus/kern_bus.c",0x3d2);
      uVar4 = uVar3 | 1;
      uVar2 = (undefined1)uVar4;
      uVar1 = (undefined2)(uVar3 >> 0x10);
      uVar5 = (undefined1)(uVar3 >> 8);
      if ((param_3 & 0x400) != 0) {
        return CONCAT22(uVar1,CONCAT11(uVar5,uVar2)) | 0x100;
      }
      if ((param_3 & 0x800) == 0) {
        if ((param_3 & 0x1000) != 0) {
          return CONCAT22(uVar1,CONCAT11(uVar5,uVar2)) | 0x400;
        }
        if ((param_3 & 0x2000) != 0) {
          uVar4 = CONCAT22(uVar1,(short)uVar4) | 0x500;
        }
        return uVar4;
      }
      return CONCAT22(uVar1,CONCAT11(uVar5,uVar2)) | 0x200;
    }
    uVar3 = uVar3 | 1;
  }
  if ((param_3 & 0x400) != 0) {
    return uVar3 | 0x100;
  }
  if ((param_3 & 0x800) != 0) {
    return uVar3 | 0x200;
  }
  if ((param_3 & 0x1000) != 0) {
    return uVar3 | 0x400;
  }
  if ((param_3 & 0x2000) != 0) {
    uVar3 = uVar3 | 0x500;
  }
  return uVar3;
}


// ===== 002db710 kbusMapFbApertureSingle_IMPL =====

ulong kbusMapFbApertureSingle_IMPL(void)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined8 *in_R8;
  undefined8 *in_R9;
  undefined8 local_20;
  
  uVar1 = *in_R8;
  uVar2 = kbusMapFbAperture_GM107();
  if ((int)uVar2 == 0) {
    *in_R9 = local_20;
    *in_R8 = uVar1;
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,
             "kbusMapFbAperture_HAL(pGpu, pKernelBus, pMemDesc, mrangeMake(offset, *pLength), &memArea, flags | BUS_MAP_FB_FLAGS_UNMANAGED_MEM_AREA, pDevice)"
             ,"src/kernel/gpu/bus/kern_bus.c",0x40e);
  return uVar2 & 0xffffffff;
}


// ===== 002db7a0 kbusUnmapFbApertureSingle_IMPL =====

void kbusUnmapFbApertureSingle_IMPL(void)

{
  kbusUnmapFbAperture_GM107();
  return;
}


// ===== 002db7d0 kbusSendBusInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusSendBusInfo_IMPL(long param_1,undefined8 param_2,uint *param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_1bc;
  undefined8 local_1b8;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    memset(&local_1bc,0,0x1a4);
    local_1b8 = *(undefined8 *)param_3;
    local_1bc = 1;
    uVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20801823,&local_1bc,0x1a4);
    param_3[1] = local_1b8._4_4_;
  }
  else {
    lVar1 = gpuGetStaticInfo();
    if (lVar1 != 0) {
      param_3[1] = *(uint *)(lVar1 + 0x8f18 + (ulong)*param_3 * 8);
      return 0;
    }
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/bus/kern_bus.c",0x441);
    uVar2 = 0x40;
  }
  return uVar2;
}


// ===== 002db8b0 kbusGetNvlinkP2PPeerId_VGPU =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusGetNvlinkP2PPeerId_VGPU
              (long param_1,long param_2,undefined8 param_3,undefined8 param_4,uint *param_5,
              uint param_6)

{
  uint uVar1;
  int iVar2;
  
  if ((param_6 & 0x20) == 0) {
    uVar1 = (**(code **)(param_2 + 0x288))();
    *param_5 = uVar1;
  }
  else {
    uVar1 = (**(code **)(param_2 + 0x280))();
    *param_5 = uVar1;
  }
  iVar2 = 0;
  if (uVar1 == 0xffffffff) {
    uVar1 = kbusGetUnusedPeerId_GM107(param_1,param_2);
    *param_5 = uVar1;
    if (uVar1 == 0xffffffff) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus.c",0x486,"kbusGetNvlinkP2PPeerId_VGPU",3,
                   "NVRM: GPU%d: peerID not available for NVLink P2P\n",
                   *(undefined4 *)(param_1 + 0x7a4));
      iVar2 = 0xffff;
    }
    else {
      iVar2 = kbusReserveP2PPeerIds_GM200(param_1,param_2,1 << ((byte)uVar1 & 0x1f));
      if (iVar2 == 0) {
        *(char *)(param_2 + 0xaa34 + (ulong)*param_5) = (char)((param_6 & 0x20) >> 5);
        return 0;
      }
    }
  }
  return iVar2;
}


// ===== 002db9a0 kbusIsStaticBar1Enabled_IMPL =====

ulong kbusIsStaticBar1Enabled_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  uint local_1c [3];
  
  iVar1 = vgpuGetCallingContextGfid(param_1,local_1c);
  if (iVar1 == 0) {
    return (ulong)CONCAT41(local_1c[0],
                           *(char *)(param_2 + 0x6e8 + (ulong)local_1c[0] * 0x100) != '\0');
  }
  return 0;
}


// ===== 002db9e0 kbusIsGpuP2pAlive_IMPL =====

bool kbusIsGpuP2pAlive_IMPL(undefined8 param_1,long param_2)

{
  return *(int *)(param_2 + 0xacfc) != 0;
}


// ===== 002dba00 kbusGetVfBar0SizeBytes_IMPL =====

undefined8 kbusGetVfBar0SizeBytes_IMPL(void)

{
  return 0x1000000;
}


// ===== 002dba10 kbusUpdateRusdStatistics_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kbusUpdateRusdStatistics_IMPL(long param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint local_34;
  ulong local_30;
  
  lVar3 = *(long *)(&DAT_00001b90 + param_1);
  if (((lVar3 == 0) || (*(char *)(lVar3 + 0xad45) == '\0')) &&
     ((*(long *)(param_1 + 0x1bc0) == 0 ||
      (cVar1 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar1 == '\0')))) {
    plVar4 = (long *)(**(code **)(lVar3 + 0x4e8))(param_1,lVar3);
    if (plVar4 == (long *)0x0) {
      nvAssertFailedNoLog("pBar1VAS != NULL","src/kernel/gpu/bus/kern_bus.c",0x4e3);
      return 0x40;
    }
    lVar7 = (**(code **)(*plVar4 + 0x90))(plVar4);
    uVar5 = (**(code **)(*plVar4 + 0x60))(plVar4);
    uVar6 = (**(code **)(*plVar4 + 0x58))(plVar4);
    uVar9 = 0;
    if (uVar6 <= uVar5) {
      uVar9 = (int)((uVar5 + 1) - uVar6 >> 10);
    }
    if (lVar7 == 0) {
      uVar8 = 0;
    }
    else {
      local_30 = 0;
      (**(code **)(lVar7 + 0x20))(lVar7,uVar6,uVar5,0,0,0);
      uVar5 = local_30;
      iVar2 = vgpuGetCallingContextGfid(param_1,&local_34);
      if ((iVar2 == 0) && (*(char *)(lVar3 + 0x6e8 + (ulong)local_34 * 0x100) != '\0')) {
        local_34 = 0;
        iVar2 = vgpuGetCallingContextGfid(param_1,&local_34,&local_30,0x2dbae9);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/bus/kern_bus.c",
                     0x4f8);
        }
        *(ulong *)(lVar3 + 0x638 + (ulong)local_34 * 0x100) = local_30;
        lVar7 = gpushareddataWriteStart_INTERNAL(param_1,0x10);
        gpushareddataWriteFinish_INTERNAL(param_1,0x10);
        uVar8 = (undefined4)
                ((*(long *)(lVar7 + 0x20) +
                 local_30 + *(long *)(lVar3 + 0x708 + (ulong)local_34 * 0x100)) -
                 *(long *)(lVar7 + 0x18) >> 10);
      }
      else {
        uVar8 = (undefined4)(uVar5 >> 10);
      }
    }
  }
  else {
    uVar8 = 0;
    uVar9 = 0;
  }
  lVar3 = gpushareddataWriteStart_INTERNAL(param_1,0);
  *(undefined4 *)(lVar3 + 8) = uVar9;
  *(undefined4 *)(lVar3 + 0xc) = uVar8;
  gpushareddataWriteFinish_INTERNAL(param_1,0);
  return 0;
}


// ===== 002dbc70 kbusGetGpuFbPhysAddressForRdma_IMPL =====

undefined8
kbusGetGpuFbPhysAddressForRdma_IMPL(long param_1,long param_2,char param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  
  if (param_3 != '\0') {
    if (*(char *)(param_1 + 0x454) == '\0') {
      return 0x56;
    }
    if (*(int *)(param_2 + 0xad54) != 0) {
      *param_4 = *(undefined8 *)(param_2 + 0xad58);
      return 0;
    }
  }
  uVar1 = gpumgrGetGpuPhysFbAddr();
  *param_4 = uVar1;
  return 0;
}


// ===== 002dbcd0 kbusGetEffectiveAddressSpace_SOC =====

undefined8
kbusGetEffectiveAddressSpace_SOC
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_4 != (undefined4 *)0x0) {
    uVar1 = memdescGetAddressSpace(param_2);
    *param_4 = uVar1;
    return 0;
  }
  return 0;
}


// ===== 002dbd10 getBusInfos =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int getBusInfos(long param_1,uint *param_2,uint param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  byte bVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  char *pcVar11;
  undefined8 uVar12;
  uint *puVar13;
  uint *puVar14;
  
  lVar1 = *(long *)(param_1 + 7000);
  lVar2 = *(long *)(param_1 + 0x1bb8);
  lVar3 = *(long *)(param_1 + 0x1b98);
  puVar13 = param_2;
LAB_002dbd60:
  do {
    iVar7 = (**(code **)(param_1 + 0x2d0))(param_1,*puVar13);
    if (iVar7 != 0) {
      nvCheckOkFailedNoLog
                (1,iVar7,"gpuValidateBusInfoIndex_HAL(pGpu, pBusInfos[i].index)",
                 "src/kernel/gpu/bus/kern_bus_ctrl.c",0xdb);
      return iVar7;
    }
    uVar8 = *puVar13;
    if (0x1d < uVar8 - 0x14) {
      if (uVar8 == 0xe) {
        puVar13[1] = 2;
      }
      else if (uVar8 < 0xf) {
        if (uVar8 == 3) {
          cVar5 = gpuIsPciBusFamily_IMPL(param_1);
          if ((cVar5 == '\0') || (*(char *)(param_1 + 0x908) == '\0')) goto LAB_002dbefe;
          lVar10 = gpuGetStaticInfo(param_1);
          puVar13[1] = *(uint *)(lVar10 + 0xa788);
        }
        else if (uVar8 < 4) {
          if (uVar8 == 1) {
            puVar13[1] = *(uint *)(param_1 + 0x86c);
          }
          else {
            if (uVar8 != 2) goto LAB_002dbfba;
            cVar5 = rmcfg_IsTEGRA_TEGRA_NVDISP_GPUS(param_1);
            uVar8 = 2;
            if (cVar5 == '\0') {
              uVar8 = (uint)(*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0') * 2;
            }
            puVar13[1] = uVar8;
          }
        }
        else if (uVar8 == 0xc) {
          puVar13[1] = 0;
          if (*(char *)(param_1 + 0x45a) != '\0') goto LAB_002dc190;
          if ((lVar1 != 0) &&
             (uVar8 = kbifGetDmaCaps_IMPL(param_1,lVar1), (uVar8 & 0xffff0000) == 0x10000)) {
            puVar13[1] = puVar13[1] | 1;
          }
          bVar4 = *(byte *)(lVar2 + 0x1b8) & 2;
joined_r0x002dc16b:
          if (bVar4 != 0) {
            puVar13[1] = puVar13[1] | 4;
          }
        }
        else if (uVar8 == 0xd) {
          puVar13[1] = (uint)(*(ulong *)(lVar3 + 0x598) >> 0x14);
        }
        else {
          if (uVar8 != 0xb) goto LAB_002dbefe;
          puVar13[1] = 0;
          if (*(char *)(param_1 + 0x45a) == '\0') {
            if ((lVar1 != 0) && (sVar6 = kbifGetDmaCaps_IMPL(param_1,lVar1), sVar6 == 1)) {
              puVar13[1] = puVar13[1] | 1;
            }
            bVar4 = *(byte *)(lVar2 + 0x1b8) & 1;
            goto joined_r0x002dc16b;
          }
        }
      }
      else if (uVar8 < 0x32) {
        if (0x10 < uVar8) goto LAB_002dbdb7;
        if (uVar8 == 0xf) {
          cVar5 = gpuIsPciBusFamily_IMPL(param_1);
          if (cVar5 == '\0') {
            return 0x56;
          }
          puVar13[1] = (uint)*(byte *)(param_1 + 0x879);
        }
        else {
          cVar5 = gpuIsPciBusFamily_IMPL(param_1);
          if (cVar5 == '\0') {
            return 0x56;
          }
          puVar13[1] = (uint)*(byte *)(param_1 + 0x878);
        }
      }
      else if (uVar8 == 0x32) {
        puVar13[1] = (uint)((ulong)*(undefined8 *)(lVar3 + 0x598) >> 0x34);
      }
      else {
        if (uVar8 != 0x33) {
          puVar13[1] = 0;
          return 0x1f;
        }
        if (*(char *)(param_1 + 0x499) == '\0') {
          puVar13[1] = (uint)(*(char *)(param_1 + 0x49b) != '\0') * 2;
        }
        else {
LAB_002dc190:
          puVar13[1] = 1;
        }
      }
      goto LAB_002dbe4a;
    }
    uVar9 = 1L << ((byte)(uVar8 - 0x14) & 0x3f);
    if ((uVar9 & 0x2f0f0e1) != 0) {
      if (*(char *)(param_1 + 0x908) == '\0') {
        cVar5 = *(char *)(param_1 + 0x909);
joined_r0x002dbdb5:
        if (cVar5 == '\0') goto LAB_002dbdb7;
      }
LAB_002dbe30:
      iVar7 = kbusSendBusInfo_IMPL(param_1,*(undefined8 *)(&DAT_00001b90 + param_1),puVar13);
      if (iVar7 != 0) {
        uVar12 = 0x101;
        pcVar11 = "kbusSendBusInfo(pGpu, GPU_GET_KERNEL_BUS(pGpu), &pBusInfos[i])";
LAB_002dc0c4:
        nvCheckOkFailedNoLog(4,iVar7,pcVar11,"src/kernel/gpu/bus/kern_bus_ctrl.c",uVar12);
        return iVar7;
      }
LAB_002dbe4a:
      puVar13 = puVar13 + 2;
      if (puVar13 == param_2 + (ulong)param_3 * 2) {
        return 0;
      }
      goto LAB_002dbd60;
    }
    if ((uVar9 & 0xf0f10) != 0) {
      if (*(char *)(param_1 + 0x909) == '\0') goto LAB_002dbefe;
      goto LAB_002dbe30;
    }
    if ((uVar9 & 0x20000002) != 0) {
      cVar5 = *(char *)(param_1 + 0x908);
      goto joined_r0x002dbdb5;
    }
LAB_002dbdb7:
    uVar9 = 1L << ((char)uVar8 - 0x11U & 0x3f);
    if ((uVar9 & 0x1d7fffffb) != 0) {
LAB_002dbefe:
      cVar5 = gpuIsPciBusFamily_IMPL(param_1);
      if (cVar5 == '\0') {
        return 0x56;
      }
      iVar7 = kbifControlGetPCIEInfo_IMPL(param_1,lVar1,puVar13);
      if (iVar7 != 0) {
        uVar12 = 0x147;
        pcVar11 = "kbifControlGetPCIEInfo(pGpu, pKernelBif, &pBusInfos[i])";
        goto LAB_002dc0c4;
      }
      goto LAB_002dbe4a;
    }
    if ((uVar9 & 0x20000004) != 0) {
LAB_002dbfba:
      uVar8 = (**(code **)(param_1 + 0x168))(param_1);
      puVar13[1] = uVar8;
      goto LAB_002dbe4a;
    }
    puVar14 = puVar13 + 2;
    puVar13[1] = *(uint *)(param_1 + 0x87c);
    puVar13 = puVar14;
    if (puVar14 == param_2 + (ulong)param_3 * 2) {
      return 0;
    }
  } while( true );
}


// ===== 002dc1c0 deviceCtrlCmdHostGetCaps_IMPL =====

undefined8 deviceCtrlCmdHostGetCaps_IMPL(long param_1,int *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*param_2 == 3) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
    uVar2 = 0x3d;
    if (*(long *)(&DAT_00001b90 + lVar1) != 0) {
      kbusGetDeviceCaps_IMPL(lVar1,*(long *)(&DAT_00001b90 + lVar1),*(undefined8 *)(param_2 + 2),0);
      uVar2 = 0;
    }
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/bus/kern_bus_ctrl.c",0x65,"deviceCtrlCmdHostGetCaps_IMPL",4,
               "NVRM: size mismatch: client 0x%x rm 0x%x\n",*param_2,3);
  return 0x1f;
}


// ===== 002dc240 deviceCtrlCmdHostGetCapsV2_IMPL =====

undefined8 deviceCtrlCmdHostGetCapsV2_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (*(long *)(&DAT_00001b90 + lVar1) != 0) {
    kbusGetDeviceCaps_IMPL(lVar1,*(long *)(&DAT_00001b90 + lVar1),param_2,0);
    return 0;
  }
  return 0x3d;
}


// ===== 002dc280 deviceCtrlCmdHostGetCapsV2_SOC =====

undefined8 deviceCtrlCmdHostGetCapsV2_SOC(undefined8 param_1,undefined8 param_2)

{
  portMemSet(param_2,0,3);
  return 0;
}


// ===== 002dc2a0 subdeviceCtrlCmdBusGetPciInfo_IMPL =====

undefined8 subdeviceCtrlCmdBusGetPciInfo_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  char cVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar4 = gpuIsPciBusFamily_IMPL(lVar3);
  if (cVar4 != '\0') {
    uVar1 = *(uint *)(lVar3 + 0x7f4);
    *param_2 = uVar1;
    param_2[1] = *(uint *)(lVar3 + 0x7fc);
    uVar2 = *(uint *)(lVar3 + 0x800);
    param_2[3] = uVar1 >> 0x10;
    param_2[2] = uVar2;
    return 0;
  }
  return 0x56;
}


// ===== 002dc310 subdeviceCtrlCmdBusGetNvlinkPeerIdMask_IMPL =====

int subdeviceCtrlCmdBusGetNvlinkPeerIdMask_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int local_2c [3];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(&DAT_00001b90 + lVar1);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/bus/kern_bus_ctrl.c",0xbb);
    return 0x2f;
  }
  iVar4 = vgpuGetCallingContextGfid(lVar1,local_2c);
  if (iVar4 == 0) {
    if (local_2c[0] != 0) {
      portMemCopy(param_2,0x80,lVar2 + 0xa8f4,0x80);
      return 0;
    }
    iVar4 = 0x56;
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/bus/kern_bus_ctrl.c",
               0xbe);
  }
  return iVar4;
}


// ===== 002dc3f0 subdeviceCtrlCmdBusGetInfoV2_IMPL =====

undefined8 subdeviceCtrlCmdBusGetInfoV2_IMPL(long param_1,int *param_2)

{
  undefined8 uVar1;
  
  if (*param_2 - 1U < 0x34) {
    uVar1 = getBusInfos(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),param_2 + 1);
    return uVar1;
  }
  return 0x1f;
}


// ===== 002dc440 subdeviceCtrlCmdBusGetPciBarInfo_IMPL =====

undefined8 subdeviceCtrlCmdBusGetPciBarInfo_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  ulong uVar8;
  
  lVar1 = *(long *)(&DAT_00001b90 + *(long *)(*(long *)(param_1 + 0x158) + 0xe0));
  cVar2 = gpuIsPciBusFamily_IMPL();
  if (cVar2 == '\0') {
    return 0x56;
  }
  uVar7 = *(uint *)(lVar1 + 0x55c);
  *param_2 = uVar7;
  if (8 < uVar7) {
    nvAssertFailedNoLog("pBarInfoParams->pciBarCount <= NV2080_CTRL_BUS_MAX_PCI_BARS",
                        "src/kernel/gpu/bus/kern_bus_ctrl.c",0x236);
    uVar7 = *param_2;
  }
  uVar8 = 0;
  if (uVar7 != 0) {
    uVar8 = (ulong)uVar7;
    lVar3 = lVar1;
    puVar5 = param_2 + 2;
    do {
      *puVar5 = 0;
      lVar4 = lVar3 + 8;
      puVar5[1] = (uint)(*(ulong *)(lVar3 + 0x5a0) >> 0x14);
      *(undefined8 *)(puVar5 + 2) = *(undefined8 *)(lVar3 + 0x5a0);
      *(undefined8 *)(puVar5 + 4) = *(undefined8 *)(lVar3 + 0x560);
      lVar3 = lVar4;
      puVar5 = puVar5 + 6;
    } while (lVar4 != lVar1 + uVar8 * 8);
    if (uVar7 == 8) {
      return 0;
    }
  }
  puVar5 = param_2 + uVar8 * 6;
  do {
    puVar5[2] = 0;
    puVar5[3] = 0;
    puVar6 = puVar5 + 6;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar6[0] = 0;
    puVar6[1] = 0;
    puVar5 = puVar6;
  } while (puVar6 != param_2 + ((7 - uVar7) + uVar8) * 6 + 6);
  return 0;
}


// ===== 002dc590 subdeviceCtrlCmdBusSysmemAccess_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusSysmemAccess_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 7000);
  (**(code **)(lVar2 + 0x2c8))(lVar1,lVar2,*param_2);
  return;
}


// ===== 002dc5c0 subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_VF =====

undefined8 subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_VF(undefined8 param_1,long param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)(param_2 + 8);
  do {
    *puVar1 = 0;
    puVar2 = puVar1 + 8;
    *(undefined4 *)(puVar1 + 4) = 0;
    puVar1 = puVar2;
  } while (puVar2 != (undefined1 *)(param_2 + 0x70));
  return 0;
}


// ===== 002dc600 subdeviceCtrlCmdBusGetC2CInfo_VF =====

undefined8 subdeviceCtrlCmdBusGetC2CInfo_VF(long param_1,undefined1 *param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar1 != 0) {
    *param_2 = *(undefined1 *)(lVar1 + 0xa1c8);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(lVar1 + 0xa1cc);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar1 + 0xa1d4);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar1 + 0xa1d8);
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(lVar1 + 0xa1e0);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/bus/kern_bus_ctrl.c",0x283);
  return 0x40;
}


// ===== 002dc690 subdeviceCtrlCmdBusGetC2CLpwrStats_VF =====

undefined8 subdeviceCtrlCmdBusGetC2CLpwrStats_VF(void)

{
  return 0x56;
}


// ===== 002dc6a0 subdeviceCtrlCmdBusSetC2CLpwrStateVote_VF =====

undefined8 subdeviceCtrlCmdBusSetC2CLpwrStateVote_VF(void)

{
  return 0x56;
}


// ===== 002dc6b0 subdeviceCtrlCmdBusSetC2CIdleThreshold_VF =====

undefined8 subdeviceCtrlCmdBusSetC2CIdleThreshold_VF(void)

{
  return 0x56;
}


// ===== 002dc6c0 _kbusDestructVirtualBar2Heaps =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kbusDestructVirtualBar2Heaps(long param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = (ulong)param_2 * 0xb0 + param_1;
  if (*(undefined8 **)(lVar1 + 0x7c18) != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)(lVar1 + 0x7c18))();
    portMemFree(*(undefined8 *)(lVar1 + 0x7c18));
    *(undefined8 *)(lVar1 + 0x7c18) = 0;
  }
  param_1 = (ulong)param_2 * 0xb0 + param_1;
  if (*(undefined8 **)(param_1 + 0x7c10) != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)(param_1 + 0x7c10))();
    portMemFree(*(undefined8 *)(param_1 + 0x7c10));
    *(undefined8 *)(param_1 + 0x7c10) = 0;
  }
  return;
}


// ===== 002dc750 _freeRmApertureMap_VBAR2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _freeRmApertureMap_VBAR2
               (undefined8 param_1,long param_2,undefined8 *param_3,undefined4 param_4)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = *(long *)(param_2 + 0x7c10);
  listRemoveIntrusive_IMPL(param_2 + 0x7c40,param_3);
  if (*(long *)(param_2 + 0x7c98) != 0) {
    plVar2 = (long *)(**(code **)(lVar1 + 0x40))(lVar1,*param_3,0);
    if (plVar2 != (long *)0x0) {
      kbusUpdateRmAperture_GM107
                (param_1,param_2,param_3[2],*plVar2,(plVar2[1] + 1) - *plVar2,param_4);
    }
  }
  (**(code **)(lVar1 + 0x10))(lVar1,*param_3);
  memdescRemoveDestroyCallback(param_3[2],param_3 + 3);
  param_3[2] = 0;
  listPrependExisting_IMPL(param_2 + 0x7c28,param_3);
  return;
}


// ===== 002dc810 kbusFlushVirtualBar2_VBAR2.part.0 =====

void kbusFlushVirtualBar2_VBAR2_part_0(undefined8 param_1,long param_2,char param_3)

{
  int iVar1;
  long lVar2;
  
  iVar1 = listCount_IMPL(param_2 + 0x7c58);
  if (iVar1 != 0) {
    nvAssertFailedNoLog("listCount(&pKernelBus->virtualBar2[gfid].usedMapList) == 0",
                        "src/kernel/gpu/bus/kern_bus_vbar2.c",0x15a);
  }
  if (param_3 != '\0') {
    iVar1 = listCount_IMPL(param_2 + 0x7c40);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("!shutdown || (listCount(&pKernelBus->virtualBar2[gfid].cachedMapList) == 0)"
                          ,"src/kernel/gpu/bus/kern_bus_vbar2.c",0x15d);
    }
  }
  while( true ) {
    iVar1 = listCount_IMPL(param_2 + 0x7c40);
    if (iVar1 == 0) break;
    lVar2 = listHead_IMPL(param_2 + 0x7c40);
    if (*(long *)(lVar2 + 0x10) == 0) {
      nvAssertFailedNoLog("pMap->pMemDesc != NULL","src/kernel/gpu/bus/kern_bus_vbar2.c",0x164);
    }
    _freeRmApertureMap_VBAR2(param_1,param_2,lVar2,3);
  }
  return;
}


// ===== 002dc910 kbusConstructVirtualBar2CpuVisibleHeap_VBAR2 =====

undefined8 kbusConstructVirtualBar2CpuVisibleHeap_VBAR2(long param_1,int param_2)

{
  long lVar1;
  
  if ((param_2 == 0) && (*(long *)(param_1 + 0x7c10) == 0)) {
    lVar1 = portMemAllocNonPaged(0xd8);
    *(long *)(param_1 + 0x7c10) = lVar1;
    if (lVar1 != 0) {
      constructObjEHeap(lVar1,*(undefined8 *)(param_1 + 0x4620),*(long *)(param_1 + 0x4628) + 1,0,
                        400);
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",199,
                 "kbusConstructVirtualBar2CpuVisibleHeap_VBAR2",4,
                 "NVRM: Unable to alloc bar2 eheap!\n");
    return 0x51;
  }
  return 0;
}


// ===== 002dc9b0 kbusConstructVirtualBar2_VBAR2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusConstructVirtualBar2_VBAR2(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  
  if ((param_3 == 0) && (*(long *)(param_2 + 0x7c20) == 0)) {
    listInitIntrusive_IMPL(param_2 + 0x7c28,0x30);
    listInitIntrusive_IMPL(param_2 + 0x7c40,0x30);
    listInitIntrusive_IMPL(param_2 + 0x7c58,0x30);
    lVar5 = portMemAllocNonPaged(0x3200);
    *(long *)(param_2 + 0x7c20) = lVar5;
    if (lVar5 == 0) {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x65,"_kbusConstructVirtualBar2Lists",4,
                   "NVRM: Unable to alloc bar2 mapping list!\n");
      listDestroyIntrusive_IMPL(param_2 + 0x7c28);
      listDestroyIntrusive_IMPL(param_2 + 0x7c40);
      listDestroyIntrusive_IMPL(param_2 + 0x7c58);
      portMemFree(*(undefined8 *)(param_2 + 0x7c20));
      *(undefined8 *)(param_2 + 0x7c20) = 0;
      nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/kern_bus_vbar2.c",0x93);
      return 0x51;
    }
    portMemSet(lVar5,0,0x3200);
    lVar5 = 0;
    do {
      lVar4 = *(long *)(param_2 + 0x7c20) + lVar5;
      lVar5 = lVar5 + 0x40;
      listAppendExisting_IMPL(param_2 + 0x7c28,lVar4);
    } while (lVar5 != 0x3200);
  }
  iVar1 = kbusConstructVirtualBar2CpuVisibleHeap_VBAR2(param_2,(ulong)param_3);
  if (iVar1 == 0) {
    uVar3 = (**(code **)(param_2 + 0x210))(param_2,param_3);
    uVar2 = (uint)uVar3;
    if (uVar2 == 0) {
      lVar5 = (ulong)param_3 * 0xb0;
      *(undefined8 *)(param_2 + 0x7ca0 + lVar5) = 0x10100001000;
      *(undefined8 *)(param_2 + 0x7ca8 + lVar5) = 0;
      *(undefined8 *)(param_2 + 0x7cb0 + lVar5) = 0;
      *(undefined4 *)(param_2 + 0x7cb8 + lVar5) = 0;
      return uVar3;
    }
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,"kbusConstructVirtualBar2CpuInvisibleHeap_HAL(pKernelBus, gfid)",
               "src/kernel/gpu/bus/kern_bus_vbar2.c",0x43);
  }
  else {
    nvAssertOkFailedNoLog
              (0x51,"kbusConstructVirtualBar2CpuVisibleHeap_HAL(pKernelBus, gfid)",
               "src/kernel/gpu/bus/kern_bus_vbar2.c",0x40);
    uVar2 = 0x51;
  }
  _kbusDestructVirtualBar2Heaps(param_2,param_3);
  nvAssertFailedNoLog("NV_OK == status","src/kernel/gpu/bus/kern_bus_vbar2.c",0x98);
  return (ulong)uVar2;
}


// ===== 002dcbf0 kbusConstructVirtualBar2CpuInvisibleHeap_VBAR2 =====

undefined8 kbusConstructVirtualBar2CpuInvisibleHeap_VBAR2(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = (ulong)param_2 * 0xb0 + param_1;
  if ((*(long *)(lVar2 + 0x7c18) == 0) &&
     (param_1 = (ulong)param_2 * 0xd8 + param_1,
     *(ulong *)(param_1 + 0x4630) < *(ulong *)(param_1 + 0x4638))) {
    lVar1 = portMemAllocNonPaged(0xd8);
    *(long *)(lVar2 + 0x7c18) = lVar1;
    if (lVar1 != 0) {
      constructObjEHeap(lVar1,*(undefined8 *)(param_1 + 0x4630),*(long *)(param_1 + 0x4638) + 1,0,0)
      ;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0xf1,
                 "kbusConstructVirtualBar2CpuInvisibleHeap_VBAR2",4,
                 "NVRM: Unable to alloc hidden bar2 eheap!\n");
    return 0x51;
  }
  return 0;
}


// ===== 002dccb0 kbusDestructVirtualBar2_VBAR2 =====

ulong kbusDestructVirtualBar2_VBAR2(undefined8 param_1,long param_2,undefined1 param_3,uint param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = (ulong)param_4 * 0xb0;
  lVar1 = param_2 + 0x7c28 + lVar4;
  lVar2 = param_2 + 0x7c40 + lVar4;
  lVar3 = param_2 + 0x7c58 + lVar4;
  if (param_4 != 0) {
    listDestroyIntrusive_IMPL(lVar1);
    listDestroyIntrusive_IMPL(lVar2);
    listDestroyIntrusive_IMPL(lVar3);
    portMemFree(*(undefined8 *)(param_2 + lVar4 + 0x7c20));
    *(undefined8 *)(param_2 + lVar4 + 0x7c20) = 0;
    uVar5 = _kbusDestructVirtualBar2Heaps(param_2,param_4);
    return uVar5;
  }
  kbusFlushVirtualBar2_VBAR2_part_0(param_1,param_2,param_3);
  listDestroyIntrusive_IMPL(lVar1);
  listDestroyIntrusive_IMPL(lVar2);
  listDestroyIntrusive_IMPL(lVar3);
  portMemFree(*(undefined8 *)(param_2 + 0x7c20));
  *(undefined8 *)(param_2 + 0x7c20) = 0;
  _kbusDestructVirtualBar2Heaps(param_2,0);
  uVar5 = (ulong)*(uint *)(param_2 + 0x7cb4);
  nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x133,"kbusDestructVirtualBar2_VBAR2",1,
               "NVRM: MapCount: %d Bar2 Hits: %d Evictions: %d\n",*(undefined4 *)(param_2 + 0x7cb0),
               uVar5,*(undefined4 *)(param_2 + 0x7cb8));
  return uVar5;
}


// ===== 002dcdd0 kbusFlushVirtualBar2_VBAR2 =====

void kbusFlushVirtualBar2_VBAR2
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,int param_4)

{
  if (param_4 != 0) {
    return;
  }
  kbusFlushVirtualBar2_VBAR2_part_0(param_1,param_2,param_3);
  return;
}


// ===== 002dcdf0 kbusInitVirtualBar2_VBAR2 =====

int kbusInitVirtualBar2_VBAR2(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint local_2c;
  
  iVar3 = vgpuGetCallingContextGfid(param_1,&local_2c);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/bus/kern_bus_vbar2.c",
               0x180);
    return iVar3;
  }
  if (*(char *)(param_2 + 0xad0c) == '\0') {
    uVar4 = (ulong)local_2c;
    lVar1 = *(long *)(param_2 + 0x7c70 + uVar4 * 0xb0);
    if (lVar1 != 0) {
      iVar3 = memdescGetAddressSpace(lVar1);
      uVar2 = local_2c;
      if (iVar3 == 2) {
        uVar5 = memmgrMemDescBeginTransfer_IMPL(*(undefined8 *)(param_1 + 0x1b78),lVar1,8);
        *(undefined8 *)(param_2 + 0x7c78 + (ulong)uVar2 * 0xb0) = uVar5;
        if (*(long *)(param_2 + 0x7c78 + (ulong)local_2c * 0xb0) != 0) {
          return 0;
        }
        nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels",
                            "src/kernel/gpu/bus/kern_bus_vbar2.c",0x191);
        return 0x1a;
      }
      nvAssertFailedNoLog("pMemDesc == NULL","src/kernel/gpu/bus/kern_bus_vbar2.c",0x19c);
      uVar4 = (ulong)local_2c;
    }
    *(undefined8 *)(param_2 + 0x7c78 + uVar4 * 0xb0) = 0;
  }
  return 0;
}


// ===== 002dcf50 kbusPreInitVirtualBar2_VBAR2 =====

int kbusPreInitVirtualBar2_VBAR2(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  uint local_2c [3];
  
  iVar3 = vgpuGetCallingContextGfid(param_1,local_2c);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/bus/kern_bus_vbar2.c",
               0x1b9);
    return iVar3;
  }
  lVar1 = *(long *)(param_2 + 0x7c80 + (ulong)local_2c[0] * 0xb0);
  iVar3 = 0;
  if (((*(char *)(param_2 + 0xad0c) == '\0') && (lVar1 != 0)) &&
     (iVar4 = memdescGetAddressSpace(lVar1), uVar2 = local_2c[0], iVar4 == 2)) {
    uVar5 = memdescMapInternal(param_1,lVar1,0);
    *(undefined8 *)(param_2 + 0x7c88 + (ulong)uVar2 * 0xb0) = uVar5;
    if (*(long *)(param_2 + 0x7c88 + (ulong)local_2c[0] * 0xb0) == 0) {
      nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevelsForBootstrap",
                          "src/kernel/gpu/bus/kern_bus_vbar2.c",0x1c8);
      iVar3 = 0x1a;
    }
  }
  return iVar3;
}


// ===== 002dd080 kbusValidateBar2ApertureMapping_VBAR2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kbusValidateBar2ApertureMapping_VBAR2
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 local_30 [2];
  
  local_30[0] = param_4;
  if (((((param_1 == 0) || (*(char *)(param_1 + 0x44f) != '\0')) ||
       (*(char *)(param_1 + 0x450) != '\0')) ||
      ((*(char *)(param_1 + 0x451) != '\0' || (*(char *)(param_1 + 0x461) != '\0')))) &&
     (cVar1 = memdescGetFlag(param_3,0x40), cVar1 == '\0')) {
    (**(code **)(param_2 + 0x1d0))(param_1,param_2,param_3,local_30,0);
    uVar2 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,param_3,0);
    return uVar2;
  }
  return local_30[0];
}


// ===== 002dd150 kbusValidateBar2ApertureMapping_VBAR2_SRIOV =====

undefined8
kbusValidateBar2ApertureMapping_VBAR2_SRIOV
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_1 + 0x491e) == '\0')) {
    uVar1 = kbusValidateBar2ApertureMapping_VBAR2();
    return uVar1;
  }
  return param_4;
}


// ===== 002dd180 kbusBar2IsReady_VBAR2 =====

bool kbusBar2IsReady_VBAR2(undefined8 param_1,long param_2)

{
  return *(long *)(param_2 + 0x7c98) != 0;
}


// ===== 002dd190 kbusMapBar2Aperture_VBAR2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kbusMapBar2Aperture_VBAR2(long param_1,ulong param_2,long *param_3,uint param_4)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long *plVar11;
  long lVar12;
  ulong *puVar13;
  long lVar14;
  long local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  uint local_6c;
  ulong local_68;
  long local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if ((*(char *)(param_2 + 0xad0c) == '\0') ||
     (((cVar6 = gpuIsCCDevToolsModeEnabled_IMPL(), cVar6 != '\0' && ((param_4 & 0x400) != 0)) ||
      (cVar6 = memdescGetFlag(param_3,0x200000000000), cVar6 != '\0')))) {
    if ((((param_1 == 0) || (*(char *)(param_1 + 0x44f) != '\0')) ||
        (*(char *)(param_1 + 0x450) != '\0')) ||
       ((*(char *)(param_1 + 0x451) != '\0' || (*(char *)(param_1 + 0x461) != '\0')))) {
      memdescSetFlag(param_3,0x40,1);
      if ((ulong)param_3[6] < 0xffffffff) {
        uVar8 = portMemAllocNonPaged();
        return uVar8;
      }
    }
    else {
      iVar7 = memdescGetAddressSpace(param_3);
      if (((iVar7 == 1) && (*(char *)(param_1 + 0x499) != '\0')) &&
         (*(char *)(param_1 + 0x44d) == '\0')) {
        nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x3cd,"kbusMapBar2Aperture_VBAR2",4,
                     "NVRM: GPU %d: Warning: Reflected Mapping Found: MapType = BAR and AddressSpace = SYSMEM.\n"
                     ,*(undefined4 *)(param_1 + 0x7a4));
        nvAssertFailedNoLog(&DAT_00cfeb78,"src/kernel/gpu/bus/kern_bus_vbar2.c",0x3d0);
      }
      local_68 = 0;
      local_6c = 0;
      local_60 = 0;
      if (param_1 != *param_3) {
        nvAssertFailedNoLog("pMemDesc->pGpu == pGpu","src/kernel/gpu/bus/kern_bus_vbar2.c",0x221);
      }
      *(int *)(param_2 + 0x7cb0) = *(int *)(param_2 + 0x7cb0) + 1;
      if ((param_3[6] == 0) || (param_3[3] == 0)) {
        nvAssertFailedNoLog("(pMemDesc->Size != 0) && (pMemDesc->PageCount != 0)",
                            "src/kernel/gpu/bus/kern_bus_vbar2.c",0x22b);
      }
      else {
        if (*(long *)(param_2 + 0x7c10) == 0) {
          nvAssertFailedNoLog("pKernelBus->virtualBar2[GPU_GFID_PF].pVASpaceHeap != NULL",
                              "src/kernel/gpu/bus/kern_bus_vbar2.c",0x22d);
          return 0;
        }
        lVar1 = param_2 + 0x7c40;
        uVar9 = listTail_IMPL(lVar1);
        uVar10 = listHead_IMPL(lVar1);
        listIterRange_IMPL(&local_98,lVar1,uVar10,uVar9);
        local_58 = local_98;
        local_50 = local_90;
        local_48 = local_88;
        local_40 = local_80;
        while (cVar6 = listIterNext_IMPL(&local_58), lVar2 = local_58, cVar6 != '\0') {
          plVar11 = *(long **)(local_58 + 0x10);
          if (plVar11 == (long *)0x0) {
            nvAssertFailedNoLog("pMap->pMemDesc","src/kernel/gpu/bus/kern_bus_vbar2.c",0x237);
            plVar11 = *(long **)(lVar2 + 0x10);
          }
          if (param_3 == plVar11) {
            listRemoveIntrusive_IMPL(lVar1,lVar2);
            listPrependExisting_IMPL(param_2 + 0x7c58,lVar2);
            *(int *)(param_2 + 0x7cb4) = *(int *)(param_2 + 0x7cb4) + 1;
            return *(ulong *)(lVar2 + 8);
          }
        }
        lVar2 = param_2 + 0x7c28;
        iVar7 = listCount_IMPL(param_2 + 0x7c28);
        if ((iVar7 == 0) && (iVar7 = listCount_IMPL(lVar1), iVar7 == 0)) {
          nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x24d,"kbusMapBar2ApertureCached_VBAR2"
                       ,4,"NVRM: No free bar2 mapping struct left!\n");
        }
        else {
          if ((param_4 & 8) != 0) {
            local_6c = local_6c | 4;
          }
          uVar3 = *(uint *)(param_3 + 0x2c);
          lVar5 = *(long *)(param_2 + 0x7c10);
          local_60 = param_3[3] <<
                     ((uVar3 & 0xaaaaaaaa) != 0 | (0xffff < uVar3) << 4 |
                      ((uVar3 & 0xff00ff00) != 0) << 3 | ((uVar3 & 0xf0f0f0f0) != 0) << 2 |
                     ((uVar3 & 0xcccccccc) != 0) * '\x02');
          iVar7 = (**(code **)(lVar5 + 8))
                            (lVar5,0x6e76726d,&local_6c,&local_68,&local_60,
                             *(undefined4 *)(param_2 + 0x7ca0),*(undefined4 *)(param_2 + 0x7ca0),0,0
                             ,0);
          if (iVar7 != 0) {
            for (lVar12 = listTail_IMPL(lVar1); lVar12 != 0; lVar12 = listPrev_IMPL(lVar1,lVar12)) {
              lVar14 = *(long *)(lVar12 + 0x10);
              if (lVar14 == 0) {
                nvAssertFailedNoLog("pMap->pMemDesc != NULL","src/kernel/gpu/bus/kern_bus_vbar2.c",
                                    0x273);
                lVar14 = *(long *)(lVar12 + 0x10);
              }
              uVar3 = *(uint *)(lVar14 + 0x160);
              uVar4 = *(uint *)(param_3 + 0x2c);
              if ((ulong)(param_3[3] <<
                         ((0xffff < uVar4) << 4 | (uVar4 & 0xaaaaaaaa) != 0 |
                          ((uVar4 & 0xff00ff00) != 0) << 3 | ((uVar4 & 0xf0f0f0f0) != 0) << 2 |
                         ((uVar4 & 0xcccccccc) != 0) * '\x02')) <=
                  (ulong)(*(long *)(lVar14 + 0x18) <<
                         ((uVar3 & 0xaaaaaaaa) != 0 | (0xffff < uVar3) << 4 |
                          ((uVar3 & 0xff00ff00) != 0) << 3 | ((uVar3 & 0xf0f0f0f0) != 0) << 2 |
                         ((uVar3 & 0xcccccccc) != 0) * '\x02'))) {
                *(int *)(param_2 + 0x7cb8) = *(int *)(param_2 + 0x7cb8) + 1;
                _freeRmApertureMap_VBAR2(param_1,param_2,lVar12,3);
                goto LAB_002dd5fa;
              }
            }
            while (iVar7 = listCount_IMPL(lVar1), iVar7 != 0) {
              lVar12 = listHead_IMPL(lVar1);
              if (*(long *)(lVar12 + 0x10) == 0) {
                nvAssertFailedNoLog("pMap->pMemDesc != NULL","src/kernel/gpu/bus/kern_bus_vbar2.c",
                                    0x28b);
              }
              *(int *)(param_2 + 0x7cb8) = *(int *)(param_2 + 0x7cb8) + 1;
              _freeRmApertureMap_VBAR2(param_1,param_2,lVar12,3);
            }
LAB_002dd5fa:
            iVar7 = (**(code **)(lVar5 + 8))
                              (lVar5,0x6e76726d,&local_6c,&local_68,&local_60,
                               *(undefined4 *)(param_2 + 0x7ca0),*(undefined4 *)(param_2 + 0x7ca0),0
                               ,0,0);
            if (iVar7 != 0) {
              nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x29c,
                           "kbusMapBar2ApertureCached_VBAR2",4,
                           "NVRM: Not enough contiguous BAR2 VA space left allocSize %llx!\n",
                           local_60);
              return 0;
            }
          }
          iVar7 = listCount_IMPL(lVar2);
          if (iVar7 == 0) {
            *(int *)(param_2 + 0x7cb8) = *(int *)(param_2 + 0x7cb8) + 1;
            uVar9 = listTail_IMPL(lVar1);
            _freeRmApertureMap_VBAR2(param_1,param_2,uVar9,3);
          }
          puVar13 = (ulong *)listHead_IMPL(lVar2);
          listRemoveIntrusive_IMPL(lVar2,puVar13);
          if ((*(long *)(param_2 + 0x7c98) != 0) &&
             (iVar7 = kbusUpdateRmAperture_GM107
                                (param_1,param_2,param_3,local_68,
                                 (ulong)*(uint *)(param_3 + 0x2c) * param_3[3],1), iVar7 == 0)) {
            uVar3 = *(uint *)(param_3 + 0xc);
            lVar1 = *(long *)(param_2 + 0x7c98);
            *puVar13 = local_68;
            puVar13[1] = (local_68 & 0xffffffff) + (ulong)uVar3 + lVar1;
            puVar13[2] = (ulong)param_3;
            puVar13[3] = (ulong)_kbusReleaseRmAperture_wrapper;
            puVar13[4] = param_2;
            memdescAddDestroyCallback(param_3,puVar13 + 3);
            listPrependExisting_IMPL(param_2 + 0x7c58,puVar13);
            return puVar13[1];
          }
          (**(code **)(lVar5 + 0x10))(lVar5,local_68);
          listPrependExisting_IMPL(lVar2,puVar13);
        }
      }
    }
  }
  else {
    os_dump_stack();
    nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x3a8,"kbusMapBar2Aperture_VBAR2",4,
                 "NVRM: Cannot map/unmap CPR vidmem into/from BAR2\n");
  }
  return 0;
}


// ===== 002dd940 kbusBar2IsReady_VBAR2_SRIOV =====

bool kbusBar2IsReady_VBAR2_SRIOV(long param_1,long param_2)

{
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_1 + 0x491e) == '\0')) {
    return *(long *)(param_2 + 0x7c98) != 0;
  }
  return true;
}


// ===== 002dd980 kbusMapBar2Aperture_VBAR2_SRIOV =====

undefined8 kbusMapBar2Aperture_VBAR2_SRIOV(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_1 + 0x491e) == '\0')) {
    uVar1 = kbusMapBar2Aperture_VBAR2();
    return uVar1;
  }
  if (*(ulong *)(param_3 + 0x30) < 0xffffffff) {
    uVar1 = portMemAllocNonPaged();
    return uVar1;
  }
  return 0;
}


// ===== 002dd9d0 kbusUnmapBar2ApertureWithFlags_VBAR2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusUnmapBar2ApertureWithFlags_VBAR2
               (undefined8 param_1,long param_2,long param_3,undefined8 *param_4,ulong param_5)

{
  long lVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if ((*(char *)(param_2 + 0xad0c) != '\0') &&
     (((cVar2 = gpuIsCCDevToolsModeEnabled_IMPL(), cVar2 == '\0' || ((param_5 & 0x400) == 0)) &&
      (cVar2 = memdescGetFlag(param_3,0x200000000000), cVar2 == '\0')))) {
    nvAssertFailedNoLog(&DAT_00cfeb78,"src/kernel/gpu/bus/kern_bus_vbar2.c",0x430);
    nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x431,"kbusUnmapBar2ApertureWithFlags_VBAR2",
                 4,"NVRM: Cannot map/unmap CPR vidmem into/from BAR2\n");
    return;
  }
  cVar2 = memdescGetFlag(param_3,0x40);
  if (cVar2 != '\0') {
    portMemFree(*param_4);
    uVar3 = memdescGetAddressSpace(param_3);
    uVar3 = kbusGetFlushAperture_IMPL(param_2,uVar3);
    (**(code **)(param_2 + 0x500))(param_1,param_2,uVar3);
    memdescSetFlag(param_3,0x40,0);
    return;
  }
  uVar4 = listTail_IMPL(param_2 + 0x7c58);
  uVar5 = listHead_IMPL(param_2 + 0x7c58);
  listIterRange_IMPL(&local_78,param_2 + 0x7c58,uVar5,uVar4);
  local_58 = local_78;
  local_50 = local_70;
  local_48 = local_68;
  local_40 = local_60;
  do {
    cVar2 = listIterNext_IMPL(&local_58);
    lVar1 = local_58;
    if (cVar2 == '\0') {
      nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vbar2.c",0x30e,"kbusUnmapBar2ApertureCached_VBAR2",4
                   ,"NVRM: can\'t find mapping struct!\n");
      return;
    }
  } while (param_3 != *(long *)(local_58 + 0x10));
  listRemoveIntrusive_IMPL(param_2 + 0x7c58,local_58);
  listPrependExisting_IMPL(param_2 + 0x7c40,lVar1);
  if ((param_5 & 0x10) != 0) {
    _freeRmApertureMap_VBAR2(param_1,param_2,lVar1,5);
  }
  return;
}


// ===== 002ddbf0 kbusUnmapBar2ApertureWithFlags_VBAR2_SRIOV =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusUnmapBar2ApertureWithFlags_VBAR2_SRIOV
               (long param_1,long param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined4 uVar1;
  
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*(char *)(param_1 + 0x491e) == '\0')) {
    kbusUnmapBar2ApertureWithFlags_VBAR2();
    return;
  }
  portMemFree(*param_4);
  uVar1 = memdescGetAddressSpace(param_3);
  uVar1 = kbusGetFlushAperture_IMPL(param_2,uVar1);
  (**(code **)(param_2 + 0x500))(param_1,param_2,uVar1);
  return;
}


// ===== 002ddc70 kbusReleaseRmAperture_VBAR2 =====

void kbusReleaseRmAperture_VBAR2(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar2 = listTail_IMPL(param_2 + 0x7c40);
  uVar3 = listHead_IMPL(param_2 + 0x7c40);
  listIterRange_IMPL(&local_78,param_2 + 0x7c40,uVar3,uVar2);
  local_58 = local_78;
  local_50 = local_70;
  local_48 = local_68;
  local_40 = local_60;
  do {
    cVar1 = listIterNext_IMPL(&local_58);
    if (cVar1 == '\0') {
      return;
    }
  } while (*(long *)(local_58 + 0x10) != param_3);
  _freeRmApertureMap_VBAR2(param_1,param_2,local_58,3);
  return;
}


// ===== 002ddd40 _kbusReleaseRmAperture_wrapper =====

void _kbusReleaseRmAperture_wrapper(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 0x150);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  kbusReleaseRmAperture_VBAR2(uVar1,param_2,param_3);
  return;
}


// ===== 002ddd80 kbusMapCpuInvisibleBar2Aperture_VBAR2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusMapCpuInvisibleBar2Aperture_VBAR2
              (undefined8 param_1,long param_2,long param_3,undefined8 *param_4,undefined8 param_5,
              undefined4 param_6,uint param_7)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined4 local_44;
  undefined8 local_40 [2];
  
  lVar4 = (ulong)param_7 * 0xb0 + param_2;
  lVar1 = *(long *)(lVar4 + 0x7c18);
  local_44 = param_6;
  local_40[0] = param_5;
  iVar2 = (**(code **)(lVar1 + 8))
                    (lVar1,0x6e76726d,&local_44,param_4,local_40,*(undefined4 *)(lVar4 + 0x7ca0),
                     *(undefined4 *)(lVar4 + 0x7ca0),0,0,0);
  if (iVar2 == 0) {
    if (param_7 == 0) {
      iVar2 = kbusUpdateRmAperture_GM107
                        (param_1,param_2,param_3,*param_4,
                         (ulong)*(uint *)(param_3 + 0x160) * *(long *)(param_3 + 0x18),9);
    }
    else {
      if (*(long *)(lVar4 + 0x7c78) == 0) {
        lVar3 = memdescMapInternal(param_1,*(undefined8 *)(lVar4 + 0x7c70),0);
        *(long *)(lVar4 + 0x7c78) = lVar3;
        if (lVar3 == 0) {
          nvAssertFailedNoLog("pKernelBus->virtualBar2[gfid].pPageLevels",
                              "src/kernel/gpu/bus/kern_bus_vbar2.c",0x4ba);
          return 0x1a;
        }
      }
      lVar4 = (ulong)param_7 * 0xb0 + param_2;
      iVar2 = kbusUpdateRmAperture_GM107
                        (param_1,param_2,param_3,*param_4,
                         (ulong)*(uint *)(param_3 + 0x160) * *(long *)(param_3 + 0x18),9);
      if (*(long *)(lVar4 + 0x7c78) != 0) {
        memdescUnmapInternal(param_1,*(undefined8 *)(lVar4 + 0x7c70),0);
        *(undefined8 *)(lVar4 + 0x7c78) = 0;
      }
    }
    if (iVar2 != 0) {
      (**(code **)(lVar1 + 0x10))(lVar1,*param_4);
      *param_4 = 0;
    }
  }
  return iVar2;
}


// ===== 002ddf30 kbusUnmapCpuInvisibleBar2Aperture_VBAR2 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kbusUnmapCpuInvisibleBar2Aperture_VBAR2
               (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x7c18 + (ulong)param_5 * 0xb0);
  if (lVar1 != 0) {
    (**(code **)(lVar1 + 0x10))(lVar1,param_4);
    return;
  }
  return;
}


// ===== 002ddf70 kbusRewritePTEsForExistingMapping_VBAR2 =====

undefined8 kbusRewritePTEsForExistingMapping_VBAR2(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar2 = listTail_IMPL(param_2 + 0x7c58);
  uVar3 = listHead_IMPL(param_2 + 0x7c58);
  listIterRange_IMPL(&local_78,param_2 + 0x7c58,uVar3,uVar2);
  local_58 = local_78;
  local_50 = local_70;
  local_48 = local_68;
  local_40 = local_60;
  do {
    cVar1 = listIterNext_IMPL(&local_58);
    if (cVar1 == '\0') {
      return 0x38;
    }
  } while (local_58[2] != param_3);
  uVar2 = kbusUpdateRmAperture_GM107
                    (param_1,param_2,param_3,*local_58,*(undefined8 *)(param_3 + 0x30),0);
  return uVar2;
}


// ===== 002de040 kbusBar2BootStrapInPhysicalMode_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kbusBar2BootStrapInPhysicalMode_VF(long param_1,long param_2)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x4a4e) != '\0') && (*(char *)(param_2 + 0xad08) != '\0')) {
    iVar1 = (**(code **)(param_2 + 0x480))(param_1,param_2,0);
    if (iVar1 == 0) {
      iVar1 = kbusSetupBar2CpuAperture_GM107(param_1,param_2,0);
      if (iVar1 == 0) {
        *(undefined1 *)(param_2 + 0xad09) = 1;
      }
      else {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/kern_bus_vgpu.c",0x4b);
        (**(code **)(param_2 + 0x238))(param_1,param_2,0);
      }
      return iVar1;
    }
    nvDbg_Printf("src/kernel/gpu/bus/kern_bus_vgpu.c",0x41,"kbusBar2BootStrapInPhysicalMode_VF",4,
                 "NVRM: Unable to bind BAR2 to physical mode.\n");
    return iVar1;
  }
  return 0x56;
}


// ===== 002de140 kbusInitBarsSize_VF =====

undefined8 kbusInitBarsSize_VF(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_2 + 0x5e0) != '\0') {
    return 0;
  }
  uVar1 = kbusGetVfBar0SizeBytes_IMPL();
  *(undefined8 *)(param_2 + 0x5a0) = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x910);
  *(undefined8 *)(param_2 + 0x5b0) = 0x20;
  *(undefined8 *)(param_2 + 0x5a8) = uVar1;
  *(undefined1 *)(param_2 + 0x5e0) = 1;
  return 0;
}


// ===== 002de1a0 subdeviceCtrlCmdBusSetP2pMapping_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdBusSetP2pMapping_VF(long param_1,int *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = gpumgrGetGpuFromId(param_2[3]);
  lVar4 = resservGetTlsCallContext();
  local_48 = 0;
  local_40 = 0;
  puVar2 = *(undefined4 **)(lVar4 + 0x48);
  local_38 = 0;
  local_30 = 0;
  if (lVar3 == 0) {
    nvCheckFailedNoLog(4,"pRemoteGpu != NULL","src/kernel/gpu/bus/kern_bus_vgpu.c",0x7c);
    return 0x1f;
  }
  if (*(char *)((long)param_2 + 10) == '\0') {
    if (*param_2 == 0) {
      nvCheckFailedNoLog(4,
                         "pParams->connectionType != NV2080_CTRL_CMD_BUS_SET_P2P_MAPPING_CONNECTION_TYPE_INVALID"
                         ,"src/kernel/gpu/bus/kern_bus_vgpu.c",0x7e);
      return 0x1f;
    }
    portMemCopy(&local_48,0x20,param_2,0x20);
    portMemCopy(&local_38,0x10,lVar3 + 0x7c5,0x10);
    local_40._0_3_ = CONCAT12(1,(undefined2)local_40);
    lVar3 = gpuGetRpc(lVar1);
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/kern_bus_vgpu.c",0x8a);
      uVar5 = 0x1a;
    }
    else {
      if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
        uVar5 = rpcDmaControl_wrapper(lVar1,lVar3,*puVar2,puVar2[1],puVar2[2],&local_48,0x20);
        return uVar5;
      }
      uVar5 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
    }
  }
  else {
    nvCheckFailedNoLog(4,"pParams->bUseUuid == NV_FALSE","src/kernel/gpu/bus/kern_bus_vgpu.c",0x7d);
    uVar5 = 0x56;
  }
  return uVar5;
}


// ===== 002de390 subdeviceCtrlCmdBusUnsetP2pMapping_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdBusUnsetP2pMapping_VF(long param_1,int *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = gpumgrGetGpuFromId(param_2[3]);
  lVar4 = resservGetTlsCallContext();
  local_48 = 0;
  local_40 = 0;
  puVar2 = *(undefined4 **)(lVar4 + 0x48);
  local_38 = 0;
  local_30 = 0;
  if (lVar3 == 0) {
    nvCheckFailedNoLog(4,"pRemoteGpu != NULL","src/kernel/gpu/bus/kern_bus_vgpu.c",0xa3);
    return 0x1f;
  }
  if ((char)param_2[2] == '\0') {
    if (*param_2 == 0) {
      nvCheckFailedNoLog(4,
                         "pParams->connectionType != NV2080_CTRL_CMD_BUS_SET_P2P_MAPPING_CONNECTION_TYPE_INVALID"
                         ,"src/kernel/gpu/bus/kern_bus_vgpu.c",0xa5);
      return 0x1f;
    }
    portMemCopy(&local_48,0x20,param_2,0x20);
    portMemCopy(&local_38,0x10,lVar3 + 0x7c5,0x10);
    local_40 = CONCAT71(local_40._1_7_,1);
    lVar3 = gpuGetRpc(lVar1);
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/kern_bus_vgpu.c",0xb1);
      uVar5 = 0x1a;
    }
    else {
      if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
        uVar5 = rpcDmaControl_wrapper(lVar1,lVar3,*puVar2,puVar2[1],puVar2[2],&local_48,0x20);
        return uVar5;
      }
      uVar5 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
    }
  }
  else {
    nvCheckFailedNoLog(4,"pParams->bUseUuid == NV_FALSE","src/kernel/gpu/bus/kern_bus_vgpu.c",0xa4);
    uVar5 = 0x56;
  }
  return uVar5;
}


// ===== 002de580 RmP2PGetPagesUsingVidmemInfo.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int RmP2PGetPagesUsingVidmemInfo_isra_0
              (ulong param_1,ulong param_2,long param_3,char param_4,undefined8 param_5,
              long *param_6,long *param_7,long *param_8,uint *param_9,undefined1 *param_10,
              undefined8 param_11,undefined8 param_12,undefined8 param_13,long param_14,
              long param_15,long param_16,long param_17)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  ulong *puVar10;
  ulong uVar11;
  long lVar12;
  ulong *puVar13;
  ulong uVar14;
  ulong *puVar15;
  ulong uVar16;
  long *plVar17;
  ulong uVar18;
  ulong uVar19;
  uint uVar20;
  long *plVar21;
  ulong uVar22;
  long lVar23;
  ulong uVar24;
  bool bVar25;
  int local_a4;
  short local_90;
  undefined8 local_80;
  ulong local_78;
  long local_58;
  long local_50;
  ulong *local_48;
  ulong local_40;
  
  local_58 = 0;
  uVar2 = *(undefined8 *)(param_17 + 0x80);
  iVar7 = CliGetThirdPartyP2PMappingInfoFromKey(param_5,*(undefined4 *)(param_17 + 8),param_11);
  if (iVar7 == 0x57) {
    iVar7 = CliAddThirdPartyP2PMappingInfo
                      (param_5,*(undefined4 *)(param_17 + 8),param_11,param_12,param_13,&local_58);
  }
  lVar4 = local_58;
  if (iVar7 != 0) {
    return iVar7;
  }
  if (param_4 == '\0') {
    if (*(int *)(param_16 + 0x178) == 2) {
      lVar4 = *(long *)(param_14 + 0x1b70);
      cVar6 = memdescGetFlag(uVar2,0x4000000000000);
      if (cVar6 != '\0') {
        nvDbg_Printf("src/kernel/gpu/bus/p2p.c",0x29a,"RmThirdPartyP2PNVLinkGetPages",4,
                     "NVRM: RDMA is not supported for localized memory over coherent mappings\n");
        return 0x56;
      }
      uVar24 = memdescGetPageSize(uVar2,0);
      if (uVar24 < 0x10000) {
        return 0x40;
      }
      local_90 = (short)param_3;
      if (local_90 == 0) {
        param_2 = (param_1 - 1) + param_2;
        if (param_1 < param_2) {
          lVar9 = param_1 - param_3;
          uVar24 = 0;
          do {
            lVar23 = memdescGetPhysAddr(uVar2,0,param_3);
            if (param_7 != (long *)0x0 && param_8 != (long *)0x0) {
              *(undefined4 *)(*param_7 + uVar24 * 4) = 0;
              *(undefined4 *)(*param_8 + uVar24 * 4) = 0;
            }
            param_3 = param_3 + 0x10000;
            uVar20 = (int)uVar24 + 1;
            *(long *)(*param_6 + uVar24 * 8) = lVar23 + *(long *)(lVar4 + 0x478);
            uVar24 = (ulong)uVar20;
          } while ((ulong)(lVar9 + param_3) < param_2);
        }
        else {
          uVar20 = 0;
        }
        *param_9 = uVar20;
        *param_10 = 1;
        return 0;
      }
      nvAssertFailedNoLog("NV_IS_ALIGNED64(offset, NVRM_P2P_PAGESIZE_BIG_64K)",
                          "src/kernel/gpu/bus/p2p.c",0x2a8);
      return 0x1f;
    }
    if (param_14 == 0) {
LAB_002de8e3:
      nvAssertFailedNoLog("(pGpu != NULL)","src/kernel/gpu/bus/p2p.c",0x207);
      return 0x1f;
    }
    if (local_58 == 0) {
LAB_002df1c8:
      nvAssertFailedNoLog("(pMappingInfo != NULL)","src/kernel/gpu/bus/p2p.c",0x208);
      return 0x1f;
    }
    if (param_15 == 0) {
LAB_002df2f6:
      nvAssertFailedNoLog("(pSubDevice != NULL)","src/kernel/gpu/bus/p2p.c",0x209);
      return 0x1f;
    }
  }
  else {
    if (param_14 == 0) goto LAB_002de8e3;
    if (local_58 == 0) goto LAB_002df1c8;
    if (param_15 == 0) goto LAB_002df2f6;
    if (param_16 == 0) {
      nvAssertFailedNoLog("(pThirdPartyP2PInfo != NULL)","src/kernel/gpu/bus/p2p.c",0x20a);
      return 0x1f;
    }
  }
  if (param_9 == (uint *)0x0) {
    nvAssertFailedNoLog("(pEntries != NULL)","src/kernel/gpu/bus/p2p.c",0x20c);
  }
  else {
    if (param_10 != (undefined1 *)0x0) {
      iVar7 = kbusGetGpuFbPhysAddressForRdma_IMPL
                        (param_14,*(undefined8 *)(&DAT_00001b90 + param_14),param_4,&local_50);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,
                   "kbusGetGpuFbPhysAddressForRdma(pGpu, pKernelBus, bForcePcie, &physicalFbAddress)"
                   ,"src/kernel/gpu/bus/p2p.c",0x211);
        return iVar7;
      }
      nvDbg_Printf("src/kernel/gpu/bus/p2p.c",0x214,"RmThirdPartyP2PBAR1GetPages",1,
                   "NVRM: Requesting Bar1 mappings for address: 0x%llx, length: 0x%llx, BAR1 base: 0x%llx\n"
                   ,param_1,param_2,local_50);
      *param_9 = 0;
      *(undefined8 *)(lVar4 + 0x50) = 0;
      *(ulong *)(lVar4 + 0x48) = param_1;
      lVar9 = param_17 + 0x90;
      puVar10 = (ulong *)listHead_IMPL(lVar9);
joined_r0x002de6ce:
      if (param_2 == 0) {
        if ((param_7 != (long *)0x0) && (param_8 != (long *)0x0)) {
          portMemSet(*param_7,0,(ulong)*param_9 << 2);
          portMemSet(*param_8,0,(ulong)*param_9 << 2);
        }
        *param_10 = 0;
        return 0;
      }
      while (uVar24 = param_2, puVar10 != (ulong *)0x0) {
        uVar11 = *puVar10;
        if (param_1 < uVar11) {
          uVar24 = uVar11 - param_1;
          if (param_2 + param_1 <= uVar11) {
            uVar24 = param_2;
          }
          break;
        }
        if (param_1 < uVar11 + puVar10[1]) {
          if (puVar10[6] == 0) {
            nvAssertFailedNoLog("(pMemDesc != NULL)","src/kernel/gpu/bus/p2p.c",0x119);
            goto LAB_002def96;
          }
          nvDbg_Printf("src/kernel/gpu/bus/p2p.c",0x11b,"_reuseThirdPartyP2PMappingExtent",1,
                       "NVRM: Reuse allocation for address: 0x%llx\n",param_1);
          uVar11 = param_1 - *puVar10;
          local_78 = (*puVar10 + puVar10[1]) - param_1;
          if (param_2 < local_78) {
            local_78 = param_2;
          }
          *(int *)(puVar10 + 7) = (int)puVar10[7] + 1;
          uVar24 = uVar11 + local_78;
          puVar13 = puVar10;
          goto LAB_002dea26;
        }
        puVar10 = (ulong *)listNext_IMPL(lVar9);
      }
      lVar23 = *(long *)(param_14 + 0x1b78);
      cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_14 + 0x7a4));
      if ((cVar6 == '\0') && (cVar6 = rmGpuLockIsOwner(), cVar6 == '\0')) {
        iVar7 = rmDeviceGpuLocksAcquire(param_14,0,0x20001);
        if (iVar7 == 0) {
          iVar7 = (**(code **)(lVar23 + 0x218))
                            (param_14,lVar23,*(undefined8 *)(*(long *)(param_15 + 0x158) + 0xe8),
                             &local_48);
          rmDeviceGpuLocksRelease(param_14,0,0);
          goto joined_r0x002decd9;
        }
        nvAssertOkFailedNoLog
                  (iVar7,"rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_P2P)",
                   "src/kernel/gpu/bus/p2p.c",0x3f3);
        cVar6 = (char)iVar7;
LAB_002de792:
        if (cVar6 == '\0') goto LAB_002decdf;
        lVar23 = *(long *)(param_17 + 0x80);
        lVar3 = *(long *)(*(long *)(param_15 + 0x158) + 0xe8);
        cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_14 + 0x7a4));
        bVar25 = true;
        if (cVar6 == '\0') {
          cVar6 = rmGpuLockIsOwner();
          bVar25 = cVar6 != '\0';
        }
        nvDbg_Printf("src/kernel/gpu/bus/p2p.c",0xa3,"_createThirdPartyP2PMappingExtent",1,
                     "NVRM: New allocation for address: 0x%llx\n",param_1);
        if (lVar3 == 0) {
          nvAssertFailedNoLog("(pDevice != NULL)","src/kernel/gpu/bus/p2p.c",0xa5);
          iVar7 = 0x40;
          goto LAB_002dee24;
        }
        if (lVar23 == 0) {
          nvAssertFailedNoLog("(pMemDesc != NULL)","src/kernel/gpu/bus/p2p.c",0xaa);
LAB_002def96:
          iVar7 = 0x1f;
          goto LAB_002dee24;
        }
        if ((*(char *)(param_14 + 0x908) != '\0') &&
           (lVar12 = gpuGetStaticInfo(param_14), (*(byte *)(lVar12 + 0xa726) & 4) == 0)) {
          iVar7 = 0x56;
          goto LAB_002dee24;
        }
        uVar2 = *(undefined8 *)(&DAT_00001b90 + param_14);
        puVar13 = (ulong *)portMemAllocNonPaged(0x50);
        if (puVar13 == (ulong *)0x0) {
          iVar7 = 0x51;
LAB_002de8b0:
          nvAssertOkFailedNoLog
                    (iVar7,
                     "_constructMappingExtentInfo(address, offset, fbApertureMapLength, pMemDesc, ppExtentInfo)"
                     ,"src/kernel/gpu/bus/p2p.c",0xbb);
          goto LAB_002dee24;
        }
        uVar14 = uVar24 + 0xffff & 0xffffffffffff0000;
        iVar7 = memdescCreateSubMem(&local_48,lVar23,0,param_3,uVar14);
        if (iVar7 != 0) {
          memdescDestroy(puVar13[6]);
          portMemFree(puVar13);
          goto LAB_002de8b0;
        }
        portMemSet(puVar13,0,0x50);
        *puVar13 = param_1;
        puVar13[3] = 0;
        puVar13[1] = uVar14;
        *(undefined4 *)(puVar13 + 7) = 1;
        puVar13[6] = (ulong)local_48;
        if ((*(char *)(param_14 + 0x908) == '\0') || (*(char *)(param_14 + 0x491e) == '\0')) {
          if (bVar25) {
            iVar7 = kbusMapFbAperture_GM107
                              (param_14,uVar2,local_48,0,uVar14,&local_48,0x120,lVar3,0,uVar14);
LAB_002dec28:
            if (iVar7 == 0) goto LAB_002de9b3;
            nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/p2p.c",0xe0);
          }
          else {
            iVar7 = rmDeviceGpuLocksAcquire(param_14,0,0x20001);
            if (iVar7 == 0) {
              iVar7 = kbusMapFbAperture_GM107
                                (param_14,uVar2,puVar13[6],0,uVar14,&local_48,0x120,lVar3,0,uVar14);
              rmDeviceGpuLocksRelease(param_14,0,0);
              goto LAB_002dec28;
            }
            nvAssertOkFailedNoLog
                      (iVar7,
                       "rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_P2P)",
                       "src/kernel/gpu/bus/p2p.c",0xd0);
          }
          memdescDestroy(puVar13[6]);
          portMemFree(puVar13);
          goto LAB_002dee24;
        }
        local_48 = puVar13 + 4;
        local_40 = 1;
        puVar13[5] = uVar14;
LAB_002de9b3:
        puVar13[2] = (ulong)local_48;
        puVar13[3] = local_40;
        puVar15 = (ulong *)listHead_IMPL(lVar9);
        while (puVar15 != (ulong *)0x0) {
          if (param_1 < *puVar15) {
            listInsertExisting_IMPL(lVar9,puVar15,puVar13);
            goto LAB_002dea11;
          }
          puVar15 = (ulong *)listNext_IMPL(lVar9);
        }
        listAppendExisting_IMPL(lVar9);
LAB_002dea11:
        uVar11 = 0;
        *(long *)(param_15 + 0x348) = *(long *)(param_15 + 0x348) + uVar14;
        local_78 = uVar24;
LAB_002dea26:
        if (*(long *)(lVar4 + 0x58) == 0) {
          *(ulong **)(lVar4 + 0x58) = puVar13;
        }
        uVar14 = puVar13[3];
        uVar20 = *param_9;
        uVar19 = (ulong)uVar20;
        if (uVar14 != 0) {
          uVar22 = 0;
          uVar16 = 0;
          do {
            uVar18 = uVar16 + *(long *)(puVar13[2] + 8 + uVar22 * 0x10);
            if ((uVar16 <= uVar11) && (uVar11 + 1 <= uVar18)) {
              lVar23 = uVar11 - uVar16;
              if (uVar22 < uVar14) {
                plVar21 = (long *)(puVar13[2] + uVar22 * 0x10);
                goto LAB_002deaa0;
              }
              break;
            }
            uVar22 = uVar22 + 1;
            uVar16 = uVar18;
          } while (uVar22 != uVar14);
        }
        goto LAB_002deb33;
      }
      iVar7 = (**(code **)(lVar23 + 0x218))
                        (param_14,lVar23,*(undefined8 *)(*(long *)(param_15 + 0x158) + 0xe8),
                         &local_48);
joined_r0x002decd9:
      if (iVar7 == 0) {
        uVar11 = ((ulong)local_48 & 0xffffffff) * 0x400;
        if (*(ulong *)(param_15 + 0x348) <= uVar11) {
          cVar6 = uVar24 + 0x2400000 <= uVar11 - *(ulong *)(param_15 + 0x348);
          goto LAB_002de792;
        }
      }
LAB_002decdf:
      nvDbg_Printf("src/kernel/gpu/bus/p2p.c",0x240,"RmThirdPartyP2PBAR1GetPages",4,
                   "NVRM: no space for BAR1 mappings, length: 0x%llx \n",uVar24);
      iVar7 = 0x1a;
LAB_002dee24:
      bVar25 = true;
      lVar23 = *(long *)(*(long *)(param_15 + 0x158) + 0xe8);
      cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_14 + 0x7a4));
      if (cVar6 == '\0') {
        cVar6 = rmGpuLockIsOwner();
        bVar25 = cVar6 != '\0';
      }
      if (lVar23 == 0) {
        nvAssertFailedNoLog("(pDevice != NULL)","src/kernel/gpu/bus/p2p.c",0x14f);
        return iVar7;
      }
      local_a4 = 0;
      if (*(char *)(param_14 + 0x908) == '\0') {
        local_80 = *(undefined8 *)(&DAT_00001b90 + param_14);
        uVar24 = *(ulong *)(lVar4 + 0x50);
        lVar23 = *(long *)(lVar4 + 0x48);
      }
      else {
        lVar23 = gpuGetStaticInfo(param_14);
        if ((*(byte *)(lVar23 + 0xa726) & 4) == 0) {
          return iVar7;
        }
        local_80 = *(undefined8 *)(&DAT_00001b90 + param_14);
        uVar24 = *(ulong *)(lVar4 + 0x50);
        lVar23 = *(long *)(lVar4 + 0x48);
        if ((*(char *)(param_14 + 0x908) != '\0') && (*(char *)(param_14 + 0x491e) != '\0')) {
          plVar21 = *(long **)(lVar4 + 0x58);
          if (uVar24 == 0) goto LAB_002df03a;
          if (plVar21 == (long *)0x0) goto LAB_002df031;
          bVar25 = true;
          bVar5 = true;
          goto LAB_002def15;
        }
      }
      if (bVar25) {
        plVar21 = *(long **)(lVar4 + 0x58);
        if (plVar21 == (long *)0x0) goto LAB_002df031;
        if (uVar24 == 0) goto LAB_002df03a;
      }
      else {
        iVar8 = rmDeviceGpuLocksAcquire(param_14,0,0x20001);
        if (iVar8 != 0) {
          nvAssertOkFailedNoLog(iVar8,"status","src/kernel/gpu/bus/p2p.c",0x167);
          return iVar7;
        }
        plVar21 = *(long **)(lVar4 + 0x58);
        if ((uVar24 == 0) || (plVar21 == (long *)0x0)) goto LAB_002df2dc;
      }
      bVar5 = false;
LAB_002def15:
      do {
        plVar17 = (long *)listNext_IMPL(lVar9,plVar21);
        uVar11 = (plVar21[1] + *plVar21) - lVar23;
        if (uVar24 < uVar11) {
          uVar11 = uVar24;
        }
        lVar23 = lVar23 + uVar11;
        uVar24 = uVar24 - uVar11;
        plVar1 = plVar21 + 7;
        *(int *)plVar1 = (int)*plVar1 + -1;
        if ((int)*plVar1 == 0) {
          if (!bVar5) {
            local_a4 = kbusUnmapFbAperture_GM107
                                 (param_14,local_80,plVar21[6],plVar21[2],plVar21[3],0x20);
          }
          if (local_a4 != 0) {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/p2p.c",0x185);
          }
          listRemoveIntrusive_IMPL(lVar9,plVar21);
          *(long *)(param_15 + 0x348) = *(long *)(param_15 + 0x348) - plVar21[1];
          memdescDestroy(plVar21[6]);
          portMemFree(plVar21);
        }
      } while ((plVar17 != (long *)0x0) && (plVar21 = plVar17, uVar24 != 0));
      if (!bVar25) {
LAB_002df2dc:
        rmDeviceGpuLocksRelease(param_14,0,0);
      }
LAB_002df031:
      if (uVar24 != 0) {
        nvAssertFailedNoLog("length == 0","src/kernel/gpu/bus/p2p.c",0x193);
      }
LAB_002df03a:
      *(undefined8 *)(lVar4 + 0x58) = 0;
      *(undefined8 *)(lVar4 + 0x50) = 0;
      return iVar7;
    }
    nvAssertFailedNoLog("(pbMemCpuCacheable != NULL)","src/kernel/gpu/bus/p2p.c",0x20d);
  }
  return 0x1f;
LAB_002deaa0:
  uVar11 = (uVar11 - lVar23) + plVar21[1];
  uVar16 = *plVar21 + lVar23;
  uVar18 = plVar21[1] + *plVar21;
  if (uVar11 < uVar24) {
    if (uVar16 < uVar18) {
LAB_002deae0:
      do {
        lVar23 = local_50 + uVar16;
        uVar16 = uVar16 + 0x10000;
        *(long *)(*param_6 + uVar19 * 8) = lVar23;
        uVar19 = uVar19 + 1;
      } while (uVar16 < uVar18);
      if (uVar22 + 1 != uVar14) goto LAB_002deb04;
      goto LAB_002deb30;
    }
    if (uVar22 + 1 == uVar14) goto LAB_002deb30;
  }
  else {
    uVar18 = uVar18 + (uVar24 - uVar11);
    if (uVar16 < uVar18) goto LAB_002deae0;
    if (uVar22 + 1 == uVar14) goto LAB_002deb30;
LAB_002deb04:
    if (uVar24 <= uVar11) goto LAB_002deb30;
  }
  uVar22 = uVar22 + 1;
  plVar21 = plVar21 + 2;
  lVar23 = 0;
  goto LAB_002deaa0;
LAB_002deb30:
  uVar20 = (uint)uVar19;
LAB_002deb33:
  *param_9 = uVar20;
  *(long *)(lVar4 + 0x50) = *(long *)(lVar4 + 0x50) + local_78;
  param_3 = param_3 + local_78;
  param_1 = param_1 + local_78;
  param_2 = param_2 - local_78;
  goto joined_r0x002de6ce;
}


// ===== 002df460 RmP2PGetInfoWithoutToken =====

int RmP2PGetInfoWithoutToken
              (undefined8 param_1,long param_2,undefined8 param_3,long *param_4,undefined8 *param_5,
              undefined8 param_6)

{
  long lVar1;
  bool bVar2;
  bool bVar3;
  long lVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  undefined8 uVar8;
  long local_60;
  undefined1 local_58 [8];
  undefined8 local_50;
  undefined1 local_48 [8];
  undefined1 local_40 [16];
  
  uVar8 = 0;
  local_60 = 0;
  uVar6 = osGetCurrentProcess();
  bVar3 = false;
LAB_002df4b0:
  do {
    do {
      iVar7 = CliNextThirdPartyP2PInfoWithPid(param_6,uVar6,0,local_58,&local_60);
      lVar4 = local_60;
      if (iVar7 != 0) {
        if (bVar3) {
          iVar7 = 0;
        }
        return iVar7;
      }
    } while ((*(int *)(local_60 + 0x178) == 0) && ((*(byte *)(local_60 + 0x18c) & 1) == 0));
    if (param_2 != 0) goto LAB_002df520;
    iVar7 = CliGetThirdPartyP2PPlatformData(local_60,param_3);
  } while (iVar7 != 0);
  goto joined_r0x002df5e7;
LAB_002df520:
  local_50 = 0;
  lVar1 = *(long *)(*(long *)(*(long *)(local_60 + 0x180) + 0x158) + 0xe0);
  if ((lVar1 != 0) &&
     ((((cVar5 = gpuIsGpuFullPower_IMPL(lVar1), cVar5 != '\0' || (*(char *)(lVar1 + 0x444) != '\0'))
       && (cVar5 = gpuCheckSysmemAccess_IMPL(lVar1), cVar5 != '\0')) &&
      ((*(int *)(lVar4 + 0x178) != 0 || ((*(byte *)(lVar4 + 0x18c) & 1) != 0)))))) {
    bVar2 = false;
    while (iVar7 = thirdpartyp2pGetNextVASpaceInfo_IMPL(lVar4,&local_50), iVar7 == 0) {
      iVar7 = CliGetThirdPartyP2PVidmemInfoFromAddress(lVar4,param_1,param_2,local_40,local_48);
      if ((bVar2) && (iVar7 == 0)) goto LAB_002df4b0;
      bVar2 = (bool)(bVar2 | iVar7 == 0);
      uVar8 = local_50;
    }
    if (bVar2) {
      *param_5 = uVar8;
joined_r0x002df5e7:
      if (bVar3) {
        return 0xffff;
      }
      bVar3 = true;
      *param_4 = local_60;
    }
  }
  goto LAB_002df4b0;
}


// ===== 002df620 _rmP2PGetPages =====

int _rmP2PGetPages(long param_1,int param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
                  ,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,
                  long *param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  local_50 = 0;
  local_68 = param_6;
  local_60 = param_5;
  if ((short)param_3 == 0) {
    if ((short)param_4 == 0) {
      if (param_1 == 0) {
        iVar5 = RmP2PGetInfoWithoutToken(param_3,param_4,param_11,&local_58,&local_50,0);
      }
      else {
        iVar5 = CliGetThirdPartyP2PInfoFromToken(param_1,&local_58);
      }
      if (iVar5 != 0) {
        return iVar5;
      }
      if ((*(int *)(local_58 + 0x178) == 0) && ((*(byte *)(local_58 + 0x18c) & 1) == 0)) {
        iVar5 = 0x40;
      }
      else {
        lVar1 = *(long *)(local_58 + 0x180);
        lVar2 = *(long *)(*(long *)(lVar1 + 0x158) + 0xe0);
        if (lVar2 == 0) {
          iVar5 = 0x33;
        }
        else {
          cVar4 = gpuIsGpuFullPower_IMPL(lVar2);
          if ((cVar4 == '\0') && (*(char *)(lVar2 + 0x444) == '\0')) {
            iVar5 = 0x11;
          }
          else {
            cVar4 = gpuCheckSysmemAccess_IMPL(lVar2);
            if (cVar4 == '\0') {
              iVar5 = 0x11;
            }
            else if ((param_2 == 0) ||
                    (iVar5 = thirdpartyp2pGetVASpaceInfoFromToken_IMPL(local_58,param_2,&local_50),
                    iVar5 == 0)) {
              lVar3 = local_58;
              if (local_50 == 0) {
                iVar5 = 0x40;
              }
              else {
                iVar5 = CliGetThirdPartyP2PVidmemInfoFromAddress
                                  (local_58,param_3,param_4,local_40,&local_48);
                if ((iVar5 == 0) &&
                   (iVar5 = RmP2PGetPagesUsingVidmemInfo_isra_0
                                      (param_3,param_4,local_40[0],0,lVar3,&local_60,&local_68,
                                       &param_7,param_8,param_9,param_11,param_12,param_13,lVar2,
                                       lVar1,lVar3,local_48), iVar5 == 0)) {
                  if (param_10 != (long *)0x0) {
                    *param_10 = lVar2;
                  }
                  return 0;
                }
              }
            }
          }
        }
      }
      thirdpartyp2pDelMappingInfoByKey_IMPL(local_58,param_11);
      return iVar5;
    }
    nvAssertFailedNoLog("NV_IS_ALIGNED64(length, NVRM_P2P_PAGESIZE_BIG_64K)",
                        "src/kernel/gpu/bus/p2p.c",0x428);
  }
  else {
    nvAssertFailedNoLog("NV_IS_ALIGNED64(address, NVRM_P2P_PAGESIZE_BIG_64K)",
                        "src/kernel/gpu/bus/p2p.c",0x426);
  }
  return 0x1f;
}


// ===== 002df8ee RmP2PGetPagesPersistent.cold =====

void RmP2PGetPagesPersistent_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002df910 RmP2PGetPagesPersistent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int RmP2PGetPagesPersistent
              (undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,char param_7,undefined8 param_8,long param_9,
              long *param_10)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  long lVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  char *pcVar13;
  undefined8 uVar14;
  undefined4 local_b4;
  long local_b0;
  undefined8 local_90 [2];
  undefined4 local_7c;
  long local_78;
  undefined1 local_70 [8];
  undefined4 *local_68;
  long local_60;
  long local_58;
  undefined8 local_50;
  long local_48 [3];
  
  local_78 = 0;
  local_90[0] = param_4;
  if ((short)param_1 != 0) {
    nvAssertFailedNoLog("NV_IS_ALIGNED64(address, NVRM_P2P_PAGESIZE_BIG_64K)",
                        "src/kernel/gpu/bus/p2p.c",0x556);
    return 0x1f;
  }
  if ((short)param_2 != 0) {
    nvAssertFailedNoLog("NV_IS_ALIGNED64(length, NVRM_P2P_PAGESIZE_BIG_64K)",
                        "src/kernel/gpu/bus/p2p.c",0x558);
    return 0x1f;
  }
  cVar8 = gpuIsApmFeatureEnabled_IMPL(param_9);
  if (cVar8 != '\0') {
    return 0x56;
  }
  if (param_7 == '\0') {
    iVar9 = RmP2PGetInfoWithoutToken(param_1,param_2,0,&local_78,local_70,param_9);
    if (iVar9 != 0) {
      return iVar9;
    }
    if (param_9 != 0) goto LAB_002df9e5;
LAB_002dfa01:
    iVar9 = *(int *)(*(long *)(param_9 + 0x1b78) + 0xd2c);
    if (iVar9 == 0) {
      return 0x56;
    }
    local_b4 = *(undefined4 *)(*(long *)(param_9 + 0x1b78) + 0xd10);
    *param_10 = 0;
    iVar9 = serverutilGetResourceRef(local_b4,iVar9,&local_68);
    if (iVar9 != 0) {
      return iVar9;
    }
    local_b0 = 0;
  }
  else {
    if (*(char *)(param_9 + 0x454) == '\0') {
      return 0x56;
    }
    if (*(char *)(*(long *)(&DAT_00001b90 + param_9) + 0xad45) != '\0') {
      return 0x56;
    }
    if ((*(long *)(param_9 + 0x1bc0) != 0) &&
       (cVar8 = kmigmgrIsMIGEnabled_IMPL(param_9), cVar8 != '\0')) {
      return 0x56;
    }
    iVar9 = RmP2PGetInfoWithoutToken(param_1,param_2,0,&local_78,local_70,param_9);
    if (iVar9 != 0) {
      return iVar9;
    }
LAB_002df9e5:
    if ((*(long *)(param_9 + 0x1bc0) == 0) ||
       (cVar8 = kmigmgrIsMIGEnabled_IMPL(param_9), cVar8 == '\0')) goto LAB_002dfa01;
    uVar2 = *(undefined8 *)(param_9 + 0x1bc0);
    local_68 = (undefined4 *)0x0;
    iVar9 = CliGetThirdPartyP2PVidmemInfoFromAddress(local_78,param_1,param_2,&local_50,&local_68);
    uVar14 = 0x513;
    pcVar13 = 
    "CliGetThirdPartyP2PVidmemInfoFromAddress(pThirdPartyP2P, address, length, &offset, &pVidmemInfo)"
    ;
    if (iVar9 != 0) {
LAB_002dffa0:
      nvCheckOkFailedNoLog(4,iVar9,pcVar13,"src/kernel/gpu/bus/p2p.c",uVar14);
      return iVar9;
    }
    uVar1 = local_68[2];
    iVar9 = serverGetClientUnderLock(g_resServ,*local_68,&local_58,"src/kernel/gpu/bus/p2p.c",0x513)
    ;
    if (iVar9 != 0) {
      uVar14 = 0x519;
      pcVar13 = "serverGetClientUnderLock(&g_resServ, hClient, &pClient)";
      goto LAB_002dffa0;
    }
    iVar9 = memGetByHandle_IMPL(local_58,uVar1,&local_60);
    uVar14 = 0x51c;
    pcVar13 = "memGetByHandle(pClient, hMemory, &pMemory)";
    if (iVar9 != 0) goto LAB_002dffa0;
    iVar9 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (param_9,uVar2,*(undefined8 *)(local_60 + 0xe0),local_48,0x51c);
    uVar14 = 0x51f;
    pcVar13 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pMemory->pDevice, &ref)";
    if (iVar9 != 0) goto LAB_002dffa0;
    iVar9 = kmigmgrIncRefCount_IMPL(*(undefined8 *)(local_48[0] + 0x978));
    uVar14 = 0x524;
    pcVar13 = "kmigmgrIncRefCount(ref.pKernelMIGGpuInstance->pShare)";
    if (iVar9 != 0) goto LAB_002dffa0;
    local_b0 = local_48[0];
    *param_10 = local_48[0];
    if (*(int *)(local_48[0] + 0x9d0) == 0) {
      iVar9 = 0x56;
      goto LAB_002dfd0d;
    }
    local_b4 = *(undefined4 *)(local_48[0] + 0x9c0);
    iVar9 = serverutilGetResourceRef(local_b4,*(int *)(local_48[0] + 0x9d0),&local_68);
    if (iVar9 != 0) goto LAB_002dfd0d;
  }
  lVar11 = __nvoc_dynamicCast(*(undefined8 *)(local_68 + 2),__nvoc_class_def_ThirdPartyP2P);
  lVar6 = local_78;
  if ((param_7 == '\0') || (*(int *)(lVar11 + 0x178) != 1)) {
    lVar12 = rmapiGetInterface(4);
    local_60 = 0;
    local_58 = 0;
    local_48[0] = 0;
    local_7c = 0;
    iVar9 = CliGetThirdPartyP2PVidmemInfoFromAddress(lVar6,param_1,param_2,local_48,&local_60);
    lVar7 = local_48[0];
    if (iVar9 == 0) {
      iVar9 = CliGetThirdPartyP2PVidmemInfoFromId(lVar11,*(undefined8 *)(local_60 + 0x78),&local_58)
      ;
      if (iVar9 == 0) {
LAB_002dfc20:
        lVar6 = local_58;
        if (local_58 != 0) {
          iVar9 = RmP2PGetPagesUsingVidmemInfo_isra_0
                            (param_1,param_2,lVar7,param_7,lVar11,local_90,0,0,param_5,param_6,
                             param_8,0,0,param_9,*(undefined8 *)(lVar11 + 0x180),lVar11,local_58);
          if (iVar9 == 0) {
            *param_3 = lVar11;
            return 0;
          }
          thirdpartyp2pDelMappingInfoByKey_IMPL(lVar11,param_8);
          CliDelThirdPartyP2PVidmemInfoPersistent(lVar11,lVar6);
          goto LAB_002dfd03;
        }
      }
      else if (iVar9 == 0x57) {
        if (lVar11 == 0) {
RmP2PGetPagesPersistent_cold:
                    /* WARNING: Does not return */
          pcVar5 = (code *)invalidInstructionException();
          (*pcVar5)();
        }
        uVar2 = **(undefined8 **)(*(long *)(lVar11 + 0x110) + 0x48);
        lVar3 = *(long *)(*(long *)(lVar11 + 0x128) + 0xe8);
        lVar4 = *(long *)(*(long *)(lVar11 + 0x128) + 0xf0);
        if (lVar3 == 0) goto RmP2PGetPagesPersistent_cold;
        iVar9 = (**(code **)(lVar12 + 0x50))
                          (lVar12,local_b4,
                           *(undefined4 *)(*(long *)(*(long *)(lVar3 + 0x110) + 0x48) + 0x10),
                           &local_7c,*(undefined4 *)(lVar6 + 0x170),*(undefined4 *)(local_60 + 8),0)
        ;
        if (iVar9 == 0x36) {
          if (lVar4 == 0) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)invalidInstructionException();
            (*pcVar5)();
          }
          iVar9 = (**(code **)(lVar12 + 0x50))
                            (lVar12,local_b4,
                             *(undefined4 *)(*(long *)(*(long *)(lVar4 + 0x140) + 0x48) + 0x10),
                             &local_7c,*(undefined4 *)(lVar6 + 0x170),*(undefined4 *)(local_60 + 8))
          ;
        }
        if (iVar9 == 0) {
          iVar9 = memGetByHandleAndDevice_IMPL
                            (uVar2,local_7c,
                             *(undefined4 *)(*(long *)(*(long *)(lVar3 + 0x110) + 0x48) + 0x10),
                             &local_50);
          if (((iVar9 == 0) &&
              (iVar9 = CliAddThirdPartyP2PVidmemInfo
                                 (lVar11,local_7c,*(undefined8 *)(local_60 + 0x78),1,
                                  *(undefined8 *)(local_60 + 0x70),local_50), iVar9 == 0)) &&
             (iVar9 = CliGetThirdPartyP2PVidmemInfoFromId
                                (lVar11,*(undefined8 *)(local_60 + 0x78),&local_58), iVar9 == 0))
          goto LAB_002dfc20;
          (**(code **)(lVar12 + 0x18))(lVar12,local_b4,local_7c);
        }
      }
    }
    iVar9 = 0x40;
  }
  else {
    iVar9 = 0x56;
  }
LAB_002dfd03:
  if (local_b0 == 0) {
    return iVar9;
  }
LAB_002dfd0d:
  iVar10 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(local_b0 + 0x978));
  if (iVar10 != 0) {
    nvAssertOkFailedNoLog
              (iVar10,"kmigmgrDecRefCount(pKernelMIGGpuInstance->pShare)","src/kernel/gpu/bus/p2p.c"
               ,0x53a);
  }
  return iVar9;
}


// ===== 002e0040 RmP2PGetPagesWithoutCallbackRegistration =====

void RmP2PGetPagesWithoutCallbackRegistration(void)

{
  _rmP2PGetPages();
  return;
}


// ===== 002e0070 RmP2PGetGpuByAddress =====

int RmP2PGetGpuByAddress(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long local_38;
  undefined1 local_30 [16];
  
  local_38 = 0;
  iVar3 = RmP2PGetInfoWithoutToken(param_1,param_2,0,&local_38,local_30,0);
  if (iVar3 == 0) {
    lVar1 = *(long *)(*(long *)(*(long *)(local_38 + 0x180) + 0x158) + 0xe0);
    if (lVar1 != 0) {
      cVar2 = gpuIsGpuFullPower_IMPL(lVar1);
      if ((cVar2 != '\0') || (*(char *)(lVar1 + 0x444) != '\0')) {
        cVar2 = gpuCheckSysmemAccess_IMPL(lVar1);
        if (cVar2 != '\0') {
          *param_3 = lVar1;
          return 0;
        }
      }
      return 0x11;
    }
    iVar3 = 0x33;
  }
  return iVar3;
}


// ===== 002e0140 RmP2PRegisterCallback =====

void RmP2PRegisterCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  undefined8 local_58;
  undefined1 local_50 [8];
  long local_48;
  undefined1 local_40 [16];
  
  if (param_1 == 0) {
    iVar1 = RmP2PGetInfoWithoutToken(param_2,0,param_4,&local_58,local_50,0);
  }
  else {
    iVar1 = CliGetThirdPartyP2PInfoFromToken(param_1,&local_58);
  }
  if ((iVar1 == 0) &&
     (iVar1 = CliGetThirdPartyP2PVidmemInfoFromAddress(local_58,param_2,param_3,local_40,&local_48),
     iVar1 == 0)) {
    CliRegisterThirdPartyP2PMappingCallback
              (local_58,*(undefined4 *)(local_48 + 8),param_4,param_5,param_6);
    return;
  }
  return;
}


// ===== 002e01f0 RmP2PPutPagesPersistent =====

int RmP2PPutPagesPersistent(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x178) != 0) || (iVar1 = 0x40, (*(byte *)(param_1 + 0x18c) & 1) != 0)) {
    iVar1 = thirdpartyp2pDelPersistentMappingInfoByKey_IMPL();
    if (iVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/p2p.c",0x673);
    }
    if ((param_3 != 0) &&
       (iVar2 = kmigmgrDecRefCount_IMPL(*(undefined8 *)(param_3 + 0x978)), iVar2 != 0)) {
      nvAssertOkFailedNoLog
                (iVar2,"kmigmgrDecRefCount(pKernelMIGGpuInstance->pShare)",
                 "src/kernel/gpu/bus/p2p.c",0x53a);
    }
  }
  return iVar1;
}


// ===== 002e0290 RmP2PPutPages =====

ulong RmP2PPutPages(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  long local_20 [2];
  
  if (param_1 == 0) {
    uVar1 = RmP2PGetInfoWithoutToken(param_3,0,param_4,local_20,0,0);
  }
  else {
    uVar1 = CliGetThirdPartyP2PInfoFromToken(param_1,local_20);
  }
  if (((int)uVar1 == 0) &&
     ((*(int *)(local_20[0] + 0x178) != 0 ||
      (uVar1 = 0x40, (*(byte *)(local_20[0] + 0x18c) & 1) != 0)))) {
    uVar1 = thirdpartyp2pDelMappingInfoByKey_IMPL(local_20[0],param_4);
    if ((int)uVar1 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/p2p.c",0x69d);
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}


// ===== 002e0320 _p2papiReservePeerID =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _p2papiReservePeerID
              (long param_1,long param_2,long param_3,long param_4,int *param_5,long param_6,
              uint *param_7,uint *param_8,char param_9,char param_10)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  ulong uVar10;
  uint uVar11;
  undefined8 uVar12;
  ulong uVar13;
  
  uVar5 = *(uint *)(param_1 + 0x7a4);
  uVar6 = *(uint *)(param_3 + 0x7a4);
  if (param_9 == '\0') {
    if (*param_5 != param_5[1]) {
      uVar11 = (**(code **)(param_2 + 0x288))(param_1,param_2,param_3);
      *param_7 = uVar11;
      uVar7 = (**(code **)(param_4 + 0x288))(param_3,param_4,param_1);
      *param_8 = uVar7;
      uVar11 = *param_7;
joined_r0x002e0467:
      if (uVar11 != 0xffffffff) {
        uVar10 = (ulong)uVar11;
        if (uVar7 == 0xffffffff) goto LAB_002e03b7;
        goto LAB_002e04f2;
      }
      goto LAB_002e0470;
    }
    *param_8 = 0;
    *param_7 = 0;
    iVar8 = kbusReserveP2PPeerIds_GM200(param_1,param_2,1);
    uVar12 = 0x4f;
    if (iVar8 == 0) {
      uVar11 = *param_7;
      uVar7 = *param_8;
      goto joined_r0x002e0467;
    }
LAB_002e0756:
    pcVar9 = "kbusReserveP2PPeerIds_HAL(pLocalGpu, pLocalKernelBus, NVBIT(*peer1))";
LAB_002e0764:
    nvCheckOkFailedNoLog(4,iVar8,pcVar9,"src/kernel/gpu/bus/p2p_api.c",uVar12);
    return iVar8;
  }
  uVar11 = (**(code **)(param_2 + 0x280))(param_1,param_2,param_3);
  *param_7 = uVar11;
  uVar7 = (**(code **)(param_4 + 0x280))(param_3,param_4,param_1);
  *param_8 = uVar7;
  if (*param_7 == 0xffffffff) {
LAB_002e0470:
    if (uVar7 != 0xffffffff) {
LAB_002e03b7:
      nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x95,"_p2papiReservePeerID",4,
                   "NVRM: Unexpected state, either of the peer ID is invalid \n");
      return 0xffff;
    }
    uVar11 = kbusGetUnusedPeerId_GM107(param_1,param_2);
    *param_7 = uVar11;
    if (uVar11 == 0xffffffff) {
      nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x71,"_p2papiReservePeerID",4,
                   "NVRM: GPU%d: peerID not available for NVLink P2P\n",uVar5);
      return 0xffff;
    }
    iVar8 = kbusReserveP2PPeerIds_GM200(param_1,param_2,1 << ((byte)uVar11 & 0x1f));
    if (iVar8 != 0) {
      uVar12 = 0x78;
      goto LAB_002e0756;
    }
    if (*param_5 == param_5[1]) {
      if (param_9 == '\0') {
        nvAssertFailedNoLog("bEgmPeer","src/kernel/gpu/bus/p2p_api.c",0x7e);
        return 0x40;
      }
      *param_8 = *param_7;
    }
    else {
      uVar11 = kbusGetUnusedPeerId_GM107(param_3,param_4);
      *param_8 = uVar11;
      if (uVar11 == 0xffffffff) {
        nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x88,"_p2papiReservePeerID",4,
                     "NVRM: GPU%d: peerID not available for NVLink P2P\n",uVar6);
        return 0xffff;
      }
      iVar8 = kbusReserveP2PPeerIds_GM200(param_3,param_4,1 << ((byte)uVar11 & 0x1f));
      uVar12 = 0x8f;
      pcVar9 = "kbusReserveP2PPeerIds_HAL(pRemoteGpu, pRemoteKernelBus, NVBIT(*peer2))";
      if (iVar8 != 0) goto LAB_002e0764;
      if (param_9 == '\0') {
        uVar10 = (ulong)*param_7;
        goto LAB_002e04f2;
      }
    }
  }
  else if (uVar7 == 0xffffffff) goto LAB_002e03b7;
  nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x9d,"_p2papiReservePeerID",1,"NVRM: EGM peer\n");
  uVar10 = (ulong)*param_7;
LAB_002e04f2:
  uVar13 = (ulong)uVar5;
  lVar2 = param_2 + (ulong)uVar6 * 4;
  uVar11 = 1 << ((byte)uVar10 & 0x1f);
  if (((*(uint *)(lVar2 + 0xa8f4) & uVar11) == 0) ||
     ((*(uint *)(param_4 + 0xa8f4 + uVar13 * 4) & 1 << ((byte)*param_8 & 0x1f)) == 0)) {
    *(uint *)(lVar2 + 0xa8f4) = *(uint *)(lVar2 + 0xa8f4) | uVar11;
    lVar3 = param_4 + uVar13 * 4;
    puVar1 = (uint *)(lVar3 + 0xa8f4);
    *puVar1 = *puVar1 | 1 << ((byte)*param_8 & 0x1f);
    *(char *)(param_2 + 0xaa34 + (ulong)*param_7) = param_9;
    *(char *)(param_4 + 0xaa34 + (ulong)*param_8) = param_9;
    piVar4 = (int *)(param_2 + 0xa9f4 + (ulong)*param_7 * 4);
    *piVar4 = *piVar4 + 1;
    piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_8 * 4);
    *piVar4 = *piVar4 + 1;
    if (param_10 != '\0') {
      piVar4 = (int *)(param_2 + 0xaa14 + (ulong)*param_7 * 4);
      *piVar4 = *piVar4 + 1;
      piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_8 * 4);
      *piVar4 = *piVar4 + 1;
    }
    *(int *)(lVar2 + 0xa974) = *(int *)(lVar2 + 0xa974) + 1;
    piVar4 = (int *)(lVar3 + 0xa974);
    *piVar4 = *piVar4 + 1;
    nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0xe5,"_p2papiReservePeerID",1,
                 "NVRM: added NVLink P2P mapping between GPU%u (peer %u) and GPU%u (peer %u)\n",
                 uVar5,*param_7,uVar6,*param_8);
  }
  else {
    piVar4 = (int *)(param_2 + 0xa9f4 + uVar10 * 4);
    *piVar4 = *piVar4 + 1;
    piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_8 * 4);
    *piVar4 = *piVar4 + 1;
    *(int *)(lVar2 + 0xa974) = *(int *)(lVar2 + 0xa974) + 1;
    piVar4 = (int *)(param_4 + 0xa974 + uVar13 * 4);
    *piVar4 = *piVar4 + 1;
    if (param_10 != '\0') {
      piVar4 = (int *)(param_2 + 0xaa14 + (ulong)*param_7 * 4);
      *piVar4 = *piVar4 + 1;
      piVar4 = (int *)(param_4 + 0xa9f4 + (ulong)*param_8 * 4);
      *piVar4 = *piVar4 + 1;
    }
    nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0xbb,"_p2papiReservePeerID",1,
                 "NVRM: - P2P: Peer mapping is already in use for gpu instances %x and %x with peer id\'s %d and %d. Increasing the mapping refcounts for the peer IDs to %d and %d respectively.\n"
                 ,uVar5,uVar6,*param_7,(ulong)*param_8,
                 *(undefined4 *)(param_2 + 0xa9f4 + (ulong)*param_7 * 4),
                 *(undefined4 *)(param_4 + 0xa9f4 + (ulong)*param_8 * 4));
  }
  iVar8 = 1 << ((byte)*param_7 & 0x1f);
  if (param_9 == '\0') {
    param_5[2] = iVar8;
    param_5[3] = 1 << ((byte)*param_8 & 0x1f);
  }
  else {
    param_5[8] = iVar8;
    param_5[9] = 1 << ((byte)*param_8 & 0x1f);
  }
  *(uint *)(param_6 + 0x100) = *(uint *)(param_6 + 0x100) & 0xfffffff0 | 3;
  return 0;
}


// ===== 002e0802 p2papiConstruct_IMPL.cold =====

void p2papiConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e0820 p2papiConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int p2papiConstruct_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int *piVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  code *pcVar19;
  byte bVar20;
  char cVar21;
  int iVar22;
  int iVar23;
  long lVar24;
  long lVar25;
  undefined4 *puVar26;
  undefined8 uVar27;
  char *pcVar28;
  byte bVar29;
  uint uVar30;
  bool bVar31;
  byte local_288;
  undefined1 local_278 [280];
  uint local_160;
  uint local_15c;
  uint local_158;
  uint local_154;
  long local_150;
  long local_148;
  undefined1 local_140 [232];
  undefined8 local_58;
  long local_40;
  
  piVar12 = *(int **)(param_3 + 0x10);
  uVar1 = piVar12[7];
  lVar24 = rmapiGetInterface(4);
  uVar2 = piVar12[2];
  uVar3 = piVar12[3];
  uVar4 = piVar12[8];
  uVar5 = piVar12[9];
  lVar25 = __nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (lVar25 == 0) {
    return 0x1f;
  }
  lVar25 = *(long *)(lVar25 + 0x100);
  iVar22 = subdeviceGetByHandle_IMPL(lVar25,*piVar12,&local_150);
  if (iVar22 != 0) {
    return 0x1f;
  }
  iVar22 = subdeviceGetByHandle_IMPL(lVar25,piVar12[1],&local_148);
  if (iVar22 != 0) {
    return 0x1f;
  }
  uVar30 = piVar12[2];
  if ((uVar30 != 0) && ((uVar30 - 1 & uVar30) != 0)) {
    return 0x1f;
  }
  uVar6 = piVar12[3];
  if ((uVar6 != 0) && ((uVar6 - 1 & uVar6) != 0)) {
    return 0x1f;
  }
  uVar7 = piVar12[8];
  if ((uVar7 != 0) && ((uVar7 - 1 & uVar7) != 0)) {
    return 0x1f;
  }
  uVar8 = piVar12[9];
  if ((uVar8 != 0) && ((uVar8 - 1 & uVar8) != 0)) {
    return 0x1f;
  }
  if (*piVar12 == piVar12[1]) {
    if (uVar7 != uVar8) {
      return 0x1f;
    }
    if (uVar30 != uVar6) {
      return 0x1f;
    }
  }
  if ((local_150 == 0) ||
     (uVar9 = *(undefined4 *)(*(long *)(*(long *)(local_150 + 0x140) + 0x48) + 0x10), local_148 == 0
     )) {
LAB_002e0816:
                    /* WARNING: Does not return */
    pcVar19 = (code *)invalidInstructionException();
    (*pcVar19)();
  }
  uVar10 = *(undefined4 *)(*(long *)(*(long *)(local_148 + 0x140) + 0x48) + 0x10);
  lVar13 = *(long *)(*(long *)(local_150 + 0x158) + 0xe0);
  lVar14 = *(long *)(*(long *)(local_148 + 0x158) + 0xe0);
  if (*(long *)(local_150 + 0x338) == 0) goto LAB_002e0816;
  iVar22 = *(int *)(*(long *)(*(long *)(*(long *)(local_150 + 0x338) + 0x110) + 0x48) + 0x10);
  if (*(long *)(local_148 + 0x338) == 0) goto LAB_002e0816;
  iVar11 = *(int *)(*(long *)(*(long *)(*(long *)(local_148 + 0x338) + 0x110) + 0x48) + 0x10);
  cVar21 = gpuIsGpuFullPower_IMPL();
  if ((((cVar21 == '\0') && (*(char *)(lVar13 + 0x444) == '\0')) ||
      (cVar21 = gpuCheckSysmemAccess_IMPL(lVar13), cVar21 == '\0')) ||
     (((cVar21 = gpuIsGpuFullPower_IMPL(lVar14), cVar21 == '\0' &&
       (*(char *)(lVar14 + 0x444) == '\0')) ||
      (cVar21 = gpuCheckSysmemAccess_IMPL(lVar14), cVar21 == '\0')))) {
    return 0x11;
  }
  cVar21 = gpuIsApmFeatureEnabled_IMPL(lVar13);
  if (cVar21 != '\0') {
    return 0x56;
  }
  local_288 = (byte)uVar1;
  if (((uVar1 & 1) != 0) && (*(char *)(lVar13 + 0x45b) == '\0')) {
    return 0x1f;
  }
  lVar15 = *(long *)(&DAT_00001b90 + lVar13);
  lVar16 = *(long *)(&DAT_00001b90 + lVar14);
  lVar17 = *(long *)(lVar13 + 0x1ce8);
  lVar18 = *(long *)(lVar14 + 0x1ce8);
  puVar26 = (undefined4 *)portMemAllocNonPaged(0x209c);
  if (puVar26 == (undefined4 *)0x0) {
    return 0x51;
  }
  portMemSet(puVar26,0,0x209c);
  puVar26[0x20] = 2;
  *puVar26 = *(undefined4 *)(lVar13 + 0x7ac);
  puVar26[1] = *(undefined4 *)(lVar14 + 0x7ac);
  iVar23 = (**(code **)(lVar24 + 0x38))
                     (lVar24,*(undefined4 *)(lVar25 + 0x48),*(undefined4 *)(lVar25 + 0x48),299,
                      puVar26,0x209c);
  if (iVar23 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar23,
               "pRmApi->Control(pRmApi, pClient->hClient, pClient->hClient, NV0000_CTRL_CMD_SYSTEM_GET_P2P_CAPS_V2, pP2pCapsParams, sizeof(*pP2pCapsParams))"
               ,"src/kernel/gpu/bus/p2p_api.c",0x193);
    portMemFree(puVar26);
    return iVar23;
  }
  uVar30 = puVar26[0x21];
  portMemFree(puVar26);
  bVar29 = (byte)uVar30;
  bVar20 = (byte)(uVar30 >> 1);
  if ((uVar30 & 0x1000) == 0) {
    if ((uVar30 & 8) == 0) {
      if ((uVar30 & 0x2000) == 0) {
        if ((uVar30 & 4) == 0) {
          nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x1ae,"p2papiConstruct_IMPL",4,
                       "NVRM: Unknown connection type\n");
          return 0x56;
        }
        uVar30 = (uVar30 | uVar30 >> 1) & 1;
        bVar29 = (byte)uVar30;
        if (uVar30 != 0) {
          iVar23 = (**(code **)(lVar15 + 0x240))
                             (lVar13,lVar15,*(undefined8 *)(piVar12 + 4),piVar12[6]);
          uVar27 = 0x1bd;
          if (iVar23 == 0) {
            uVar30 = 1;
            iVar23 = (**(code **)(lVar16 + 0x240))
                               (lVar14,lVar16,*(undefined8 *)(piVar12 + 4),piVar12[6]);
            bVar31 = lVar17 != 0;
            if (iVar23 == 0) goto LAB_002e0bf0;
            uVar27 = 0x1c2;
          }
          pcVar28 = "status";
          goto LAB_002e14ec;
        }
        bVar31 = lVar17 != 0;
        uVar30 = 1;
      }
      else {
        bVar31 = lVar17 != 0;
        uVar30 = 2;
        bVar29 = (bVar29 | bVar20) & 1;
      }
      goto LAB_002e0bf0;
    }
    bVar29 = (bVar20 | bVar29) & 1;
    if (lVar17 == 0) {
      uVar30 = 3;
      bVar31 = false;
      goto LAB_002e0bf0;
    }
    if (lVar18 == 0) {
      uVar30 = 3;
      bVar31 = true;
      goto LAB_002e0bf0;
    }
    uVar30 = 3;
    *(undefined8 *)(piVar12 + 0x12) = *(undefined8 *)(lVar17 + 0x16a8);
    uVar27 = *(undefined8 *)(lVar18 + 0x16a8);
    bVar31 = true;
  }
  else {
    bVar31 = lVar17 != 0;
    uVar30 = 5;
    bVar29 = (bVar29 | bVar20) & 1;
LAB_002e0bf0:
    piVar12[0x12] = -1;
    piVar12[0x13] = -1;
    uVar27 = 0xffffffffffffffff;
  }
  local_160 = 0xffffffff;
  if (uVar2 != 0) {
    local_160 = (uint)((uVar2 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar2) << 4 |
                (uint)((uVar2 & 0xff00ff00) != 0) << 3 | (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2 |
                (uint)((uVar2 & 0xcccccccc) != 0) * 2;
  }
  *(undefined8 *)(piVar12 + 0x14) = uVar27;
  local_15c = 0xffffffff;
  if (uVar3 != 0) {
    local_15c = (uint)((uVar3 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar3) << 4 |
                (uint)((uVar3 & 0xff00ff00) != 0) << 3 | (uint)((uVar3 & 0xf0f0f0f0) != 0) << 2 |
                (uint)((uVar3 & 0xcccccccc) != 0) * 2;
  }
  local_158 = 0xffffffff;
  if (uVar4 != 0) {
    local_158 = (uint)((uVar4 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar4) << 4 |
                (uint)((uVar4 & 0xff00ff00) != 0) << 3 | (uint)((uVar4 & 0xf0f0f0f0) != 0) << 2 |
                (uint)((uVar4 & 0xcccccccc) != 0) * 2;
  }
  local_154 = 0xffffffff;
  if (uVar5 != 0) {
    local_154 = (uint)(0xffff < uVar5) << 4 | (uint)((uVar5 & 0xaaaaaaaa) != 0) |
                (uint)((uVar5 & 0xff00ff00) != 0) << 3 | (uint)((uVar5 & 0xf0f0f0f0) != 0) << 2 |
                (uint)((uVar5 & 0xcccccccc) != 0) * 2;
  }
  if (*(char *)(lVar13 + 0x908) == '\0') {
    if (bVar29 == 0) {
      nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x1fe,"p2papiConstruct_IMPL",4,
                   "NVRM: ERROR: P2P is Disabled, cannot create mappings\n");
      return 0x56;
    }
    if ((lVar18 != 0) && (bVar31)) {
      iVar23 = knvlinkTrainFabricLinksToActive_IMPL(lVar13,lVar17);
      if (iVar23 != 0) {
        uVar27 = 0x209;
        uVar9 = *(undefined4 *)(lVar13 + 0x7a4);
LAB_002e16ef:
        nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",uVar27,"p2papiConstruct_IMPL",4,
                     "NVRM: link training between GPU%u and SWITCH failed with status %x\n",uVar9,
                     iVar23);
        return iVar23;
      }
      iVar23 = knvlinkTrainFabricLinksToActive_IMPL(lVar14,lVar18);
      if (iVar23 != 0) {
        uVar27 = 0x212;
        uVar9 = *(undefined4 *)(lVar14 + 0x7a4);
        goto LAB_002e16ef;
      }
    }
  }
  cVar21 = rmcfg_IsGP100orBetter(lVar13);
  if (cVar21 == '\0') {
    clientRefOrderedIter(local_278,*(undefined8 *)(param_2 + 8),0,0x3982b7,1);
    memcpy(local_140,local_278,0x108);
    while (cVar21 = clientRefOrderedIterNext(local_58,local_140), cVar21 != '\0') {
      lVar24 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 8),__nvoc_class_def_P2PApi);
      if (lVar24 == 0) {
        return 0x33;
      }
      if (lVar24 != param_1) {
        if (((*(long *)(lVar24 + 0xd8) == lVar13) && (*(long *)(lVar24 + 0xe0) == lVar14)) ||
           ((*(long *)(lVar24 + 0xd8) == lVar14 && (*(long *)(lVar24 + 0xe0) == lVar13)))) {
          nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x22c,"p2papiConstruct_IMPL",1,
                       "NVRM: Mapping already exists between the two subdevices (0x%08x), (0x%08x). Multiple mappings not supported on pre-PASCAL GPUs\n"
                       ,uVar9,uVar10);
          return 0x1f;
        }
      }
    }
  }
  *(long *)(param_1 + 0xd8) = lVar13;
  *(long *)(param_1 + 0xe0) = lVar14;
  if ((uVar1 & 1) == 0) {
    *(uint *)(param_1 + 0x100) = uVar30;
    bVar31 = false;
    if (*(char *)(*(long *)(lVar13 + 0x1b78) + 0x454) != '\0') {
      bVar31 = *(char *)(*(long *)(lVar14 + 0x1b78) + 0x454) != '\0';
    }
  }
  else {
    *(uint *)(param_1 + 0x100) = uVar30 | 0x10;
    bVar31 = false;
    if ((*(char *)(*(long *)(lVar13 + 0x1b78) + 0x454) != '\0') &&
       (bVar31 = false, *(char *)(*(long *)(lVar14 + 0x1b78) + 0x454) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/bus/p2p_api.c",0x243,"p2papiConstruct_IMPL",1,
                   "NVRM: EGM P2P not setup because of SPA only P2P flag!\n");
      bVar31 = false;
    }
  }
  piVar12[0xe] = -1;
  piVar12[0xf] = -1;
  piVar12[10] = -1;
  piVar12[0xb] = -1;
  piVar12[0x10] = 0;
  piVar12[0x11] = 0;
  piVar12[0xc] = 0;
  piVar12[0xd] = 0;
  if ((*(char *)(lVar13 + 0x4a4e) == '\0') && (*(char *)(lVar13 + 0x908) != '\0')) {
LAB_002e0eb9:
    if ((*(char *)(lVar13 + 0x4913) != '\0') && (*(char *)(lVar13 + 0x4922) != '\0')) {
      iVar23 = _p2papiReservePeerID
                         (lVar13,lVar15,lVar14,lVar16,piVar12,param_1,&local_160,&local_15c,0,
                          local_288 & 1);
      uVar27 = 0x27b;
      pcVar28 = 
      "_p2papiReservePeerID(pLocalGpu, pLocalKernelBus, pRemoteGpu, pRemoteKernelBus, pNv503bAllocParams, pP2PApi, &peer1, &peer2, NV_FALSE, bSpaAccessOnly)"
      ;
      if (iVar23 != 0) {
LAB_002e15b9:
        nvCheckOkFailedNoLog(4,iVar23,pcVar28,"src/kernel/gpu/bus/p2p_api.c",uVar27);
        return iVar23;
      }
      if ((bVar31) &&
         (iVar23 = _p2papiReservePeerID
                             (lVar13,lVar15,lVar14,lVar16,piVar12,param_1,&local_158,&local_154,1,
                              local_288 & 1), iVar23 != 0)) {
        uVar27 = 0x281;
        pcVar28 = 
        "_p2papiReservePeerID(pLocalGpu, pLocalKernelBus, pRemoteGpu, pRemoteKernelBus, pNv503bAllocParams, pP2PApi, &egmPeer1, &egmPeer2, NV_TRUE, bSpaAccessOnly)"
        ;
        goto LAB_002e15b9;
      }
    }
  }
  else {
    iVar23 = (**(code **)(lVar15 + 0x270))
                       (lVar13,lVar15,lVar14,lVar16,&local_160,&local_15c,
                        *(undefined4 *)(param_1 + 0x100));
    uVar27 = 599;
    pcVar28 = 
    "kbusCreateP2PMapping_HAL(pLocalGpu, pLocalKernelBus, pRemoteGpu, pRemoteKernelBus, &peer1, &peer2, pP2PApi->attributes)"
    ;
    if (iVar23 != 0) goto LAB_002e15b9;
    if ((bVar31) &&
       (iVar23 = (**(code **)(lVar15 + 0x270))
                           (lVar13,lVar15,lVar14,lVar16,&local_158,&local_154,
                            *(uint *)(param_1 + 0x100) | 0x20), iVar23 != 0)) {
      uVar27 = 0x25d;
      pcVar28 = 
      "kbusCreateP2PMapping_HAL(pLocalGpu, pLocalKernelBus, pRemoteGpu, pRemoteKernelBus, &egmPeer1, &egmPeer2, pP2PApi->attributes | DRF_DEF(_P2PAPI, _ATTRIBUTES, _REMOTE_EGM, _YES))"
      ;
      goto LAB_002e15b9;
    }
    if ((uVar30 == 2) && (1 < *(uint *)(param_2 + 0x28))) {
      iVar23 = (**(code **)(lVar16 + 800))(lVar13,lVar14,lVar16,piVar12 + 10,piVar12 + 0xc);
      uVar27 = 0x267;
      pcVar28 = 
      "kbusGetBar1P2PDmaInfo_HAL(pLocalGpu, pRemoteGpu, pRemoteKernelBus, &pNv503bAllocParams->l2pBar1P2PDmaInfo.dma_address, &pNv503bAllocParams->l2pBar1P2PDmaInfo.dma_size)"
      ;
      if (iVar23 != 0) goto LAB_002e15b9;
      iVar23 = (**(code **)(lVar15 + 800))(lVar14,lVar13,lVar15,piVar12 + 0xe,piVar12 + 0x10);
      uVar27 = 0x26d;
      pcVar28 = 
      "kbusGetBar1P2PDmaInfo_HAL(pRemoteGpu, pLocalGpu, pLocalKernelBus, &pNv503bAllocParams->p2lBar1P2PDmaInfo.dma_address, &pNv503bAllocParams->p2lBar1P2PDmaInfo.dma_size)"
      ;
      if (iVar23 != 0) goto LAB_002e15b9;
    }
    if (*(char *)(lVar13 + 0x4a4e) == '\0') goto LAB_002e0eb9;
  }
  *(ulong *)(param_1 + 0xf8) = CONCAT44(local_154,local_158);
  *(ulong *)(param_1 + 0xf0) = CONCAT44(local_15c,local_160);
  *(undefined8 *)(param_1 + 0xe8) = 0;
  if ((*(char *)(lVar13 + 0x4a4e) == '\0') && (*(char *)(lVar13 + 0x908) != '\0')) {
    lVar24 = gpuGetRpc(lVar13);
    if (lVar24 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/bus/p2p_api.c",0x291);
    }
    else {
      if ((*(char *)(lVar13 + 0x909) == '\0') && (*(char *)(lVar13 + 0x90a) == '\0')) {
        iVar23 = (**(code **)(lVar24 + 0x348))
                           (lVar13,lVar24,*param_3,param_3[1],param_3[2],param_3[3],piVar12,lVar13);
      }
      else {
        iVar23 = (**(code **)(lVar13 + 0x3b60))(lVar13 + 0x3b58);
      }
      if (iVar23 != 0) {
        return iVar23;
      }
    }
  }
  if ((((*(char *)(lVar15 + 0xa830) != '\0') && (*(char *)(lVar15 + 0xa831) == '\0')) &&
      (*(char *)(lVar13 + 0x908) != '\0')) &&
     (iVar23 = (**(code **)(lVar15 + 0x3d0))(lVar13,lVar15,*(undefined4 *)(param_1 + 0xe8)),
     iVar23 != 0)) {
    nvCheckOkFailedNoLog
              (4,iVar23,"kbusSetupBindFla_HAL(pLocalGpu, pLocalKernelBus, pP2PApi->localGfid)",
               "src/kernel/gpu/bus/p2p_api.c",0x2a7);
    return iVar23;
  }
  if (((iVar22 != iVar11) && (*(char *)(lVar16 + 0xa830) != '\0')) &&
     (*(char *)(lVar16 + 0xa831) == '\0')) {
    if (*(char *)(lVar14 + 0x908) == '\0') {
      return 0;
    }
    iVar23 = (**(code **)(lVar16 + 0x3d0))(lVar14,lVar16,*(undefined4 *)(param_1 + 0xec));
    if (iVar23 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar23,"kbusSetupBindFla_HAL(pRemoteGpu, pRemoteKernelBus, pP2PApi->remoteGfid)",
                 "src/kernel/gpu/bus/p2p_api.c",0x2b5);
      return iVar23;
    }
  }
  if (local_150 == 0) {
                    /* WARNING: Does not return */
    pcVar19 = (code *)invalidInstructionException();
    (*pcVar19)();
  }
  iVar23 = refAddDependant(*(undefined8 *)(*(long *)(local_150 + 0x140) + 0x48),
                           *(undefined8 *)(param_2 + 0x10));
  if (iVar23 != 0) {
    nvAssertOkFailedNoLog
              (iVar23,"refAddDependant(RES_GET_REF(pSubDevice), pCallContext->pResourceRef)",
               "src/kernel/gpu/bus/p2p_api.c",699);
    return iVar23;
  }
  if (iVar22 != iVar11) {
    if (local_148 == 0) {
                    /* WARNING: Does not return */
      pcVar19 = (code *)invalidInstructionException();
      (*pcVar19)();
    }
    iVar23 = refAddDependant(*(undefined8 *)(*(long *)(local_148 + 0x140) + 0x48),
                             *(undefined8 *)(param_2 + 0x10));
    uVar27 = 0x2be;
    pcVar28 = "refAddDependant(RES_GET_REF(pPeerSubDevice), pCallContext->pResourceRef)";
    if (iVar23 != 0) {
LAB_002e14ec:
      nvAssertOkFailedNoLog(iVar23,pcVar28,"src/kernel/gpu/bus/p2p_api.c",uVar27);
      return iVar23;
    }
  }
  if (*(int *)(lVar15 + 0xacfc) == -1) {
    nvCheckFailedNoLog(4,"pLocalKernelBus->totalP2pObjectsAliveRefCount < NV_U32_MAX",
                       "src/kernel/gpu/bus/p2p_api.c",0x2c3);
  }
  else {
    if (*(int *)(lVar16 + 0xacfc) != -1) {
      *(int *)(lVar15 + 0xacfc) = *(int *)(lVar15 + 0xacfc) + 1;
      *(int *)(lVar16 + 0xacfc) = *(int *)(lVar16 + 0xacfc) + 1;
      return 0;
    }
    nvCheckFailedNoLog(4,"pRemoteKernelBus->totalP2pObjectsAliveRefCount < NV_U32_MAX",
                       "src/kernel/gpu/bus/p2p_api.c",0x2c4);
  }
  return 0x1a;
}


// ===== 002e19a0 p2papiDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void p2papiDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  ulong extraout_RDX;
  undefined8 uVar10;
  undefined1 local_50 [8];
  undefined4 *local_48;
  undefined1 local_40 [16];
  int iVar9;
  
  uVar10 = 0;
  if (param_1 != 0) {
    uVar10 = *(undefined8 *)(param_1 + 0xb8);
  }
  resGetFreeParams_IMPL(uVar10,local_50,&local_48);
  iVar5 = serverGetClientUnderLock(g_resServ,*local_48,local_40);
  if (iVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar5,"serverGetClientUnderLock(&g_resServ, hClient, &pClient)",
               "src/kernel/gpu/bus/p2p_api.c",0x2df);
    goto LAB_002e1b8b;
  }
  lVar1 = *(long *)(param_1 + 0xd8);
  if ((lVar1 == 0) || (lVar2 = *(long *)(param_1 + 0xe0), lVar2 == 0)) {
    return;
  }
  lVar3 = *(long *)(&DAT_00001b90 + lVar1);
  lVar4 = *(long *)(&DAT_00001b90 + lVar2);
  if (*(int *)(lVar3 + 0xacfc) == 0) {
    nvAssertFailedNoLog("pLocalKernelBus->totalP2pObjectsAliveRefCount > 0",
                        "src/kernel/gpu/bus/p2p_api.c",0x2eb);
    iVar9 = *(int *)(lVar4 + 0xacfc);
    if (iVar9 == 0) goto LAB_002e1c00;
    iVar6 = *(int *)(lVar3 + 0xacfc);
    if (iVar6 != 0) goto LAB_002e1a53;
LAB_002e1bda:
    uVar8 = iVar9 - 1;
    *(uint *)(lVar4 + 0xacfc) = uVar8;
  }
  else {
    if (*(int *)(lVar4 + 0xacfc) == 0) {
LAB_002e1c00:
      nvAssertFailedNoLog("pRemoteKernelBus->totalP2pObjectsAliveRefCount > 0",
                          "src/kernel/gpu/bus/p2p_api.c",0x2ec);
      iVar6 = *(int *)(lVar3 + 0xacfc);
      if (iVar6 != 0) goto LAB_002e1a53;
    }
    else {
      iVar6 = *(int *)(lVar3 + 0xacfc);
LAB_002e1a53:
      *(int *)(lVar3 + 0xacfc) = iVar6 + -1;
    }
    iVar9 = *(int *)(lVar4 + 0xacfc);
    uVar8 = 0;
    if (iVar9 != 0) goto LAB_002e1bda;
  }
  uVar7 = (ulong)uVar8;
  if ((*(char *)(lVar1 + 0x4a4e) != '\0') || (*(char *)(lVar1 + 0x908) == '\0')) {
    iVar5 = (**(code **)(lVar3 + 0x278))
                      (lVar1,lVar3,lVar2,lVar4,*(undefined4 *)(param_1 + 0xf0),
                       *(undefined4 *)(param_1 + 0xf4),*(undefined4 *)(param_1 + 0x100));
    if (iVar5 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "kbusRemoveP2PMapping_HAL(pLocalGpu, pLocalKernelBus, pRemoteGpu, pRemoteKernelBus, pP2PApi->peerId1, pP2PApi->peerId2, pP2PApi->attributes)"
                 ,"src/kernel/gpu/bus/p2p_api.c",0x2f6);
      goto LAB_002e1b8b;
    }
    uVar7 = extraout_RDX;
    if ((*(uint *)(param_1 + 0x100) & 0x10) == 0) {
      uVar7 = *(ulong *)(lVar1 + 0x1b78);
      if ((*(char *)(uVar7 + 0x454) == '\0') ||
         (uVar7 = *(ulong *)(lVar2 + 0x1b78), *(char *)(uVar7 + 0x454) == '\0')) {
        iVar5 = 0;
      }
      else {
        uVar7 = (ulong)(*(uint *)(param_1 + 0x100) | 0x20);
        iVar5 = (**(code **)(lVar3 + 0x278))
                          (lVar1,lVar3,lVar2,lVar4,*(undefined4 *)(param_1 + 0xf8),
                           *(undefined4 *)(param_1 + 0xfc));
      }
    }
  }
  *(undefined8 *)(param_1 + 0xd8) = 0;
  *(undefined8 *)(param_1 + 0xe0) = 0;
  (**(code **)(lVar3 + 0x248))(lVar1,lVar3,uVar7);
  (**(code **)(lVar4 + 0x248))(lVar2,lVar4);
LAB_002e1b8b:
  local_48[0xc] = iVar5;
  return;
}


// ===== 002e1ca0 _thirdpartyp2pDelMappingInfoByKey =====

int _thirdpartyp2pDelMappingInfoByKey(long param_1,long param_2,long *param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  bool bVar5;
  bool bVar6;
  long lVar7;
  char cVar8;
  char cVar9;
  int iVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long *plVar13;
  ulong uVar14;
  long lVar15;
  long extraout_RDX;
  long extraout_RDX_00;
  ulong uVar16;
  long *plVar17;
  long lVar18;
  long local_a8;
  int local_90;
  long local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long *local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("(pKey != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x321);
    return 0x1f;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar3 = *(undefined8 *)(&DAT_00001b90 + lVar2);
  cVar8 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4));
  if (cVar8 == '\0') {
    cVar9 = rmGpuLockIsOwner();
    local_a8 = *(long *)(param_1 + 0x180);
    cVar8 = *(char *)(lVar2 + 0x908);
    if (cVar9 != '\0') goto joined_r0x002e2003;
    if ((cVar8 == '\0') || (*(char *)(lVar2 + 0x491e) == '\0')) {
      iVar10 = rmDeviceGpuLocksAcquire(lVar2,0,0x20001);
      bVar5 = false;
      bVar6 = false;
      if (iVar10 != 0) {
        nvAssertOkFailedNoLog(iVar10,"status","src/kernel/gpu/bus/third_party_p2p.c",0x335);
        return iVar10;
      }
      goto LAB_002e1d39;
    }
  }
  else {
    local_a8 = *(long *)(param_1 + 0x180);
    cVar8 = *(char *)(lVar2 + 0x908);
joined_r0x002e2003:
    if ((cVar8 == '\0') || (*(char *)(lVar2 + 0x491e) == '\0')) {
      bVar5 = false;
      bVar6 = true;
      goto LAB_002e1d39;
    }
  }
  bVar5 = true;
  bVar6 = true;
LAB_002e1d39:
  uVar11 = mapFindLEQ_IMPL(param_1 + 0x9c8,0xffffffffffffffff);
  uVar12 = mapFindGEQ_IMPL(param_1 + 0x9c8,0);
  mapIterRange_IMPL(&local_88,param_1 + 0x9c8,uVar12,uVar11);
  local_58 = local_88;
  local_50 = local_80;
  local_48 = local_78;
  local_40 = local_70;
  do {
    do {
      cVar8 = mapIterNext_IMPL(&local_58);
      lVar7 = local_58;
      if (cVar8 == '\0') goto LAB_002e1dc1;
      iVar10 = btreeSearch(param_2,&local_60,*(undefined8 *)(local_58 + 0x88));
    } while (iVar10 != 0);
    lVar4 = *local_60;
    uVar16 = *(ulong *)(lVar4 + 0x50);
    if (*(long **)(lVar4 + 0x58) == (long *)0x0) {
LAB_002e1f2b:
      if (uVar16 != 0) {
        nvAssertFailedNoLog("length == 0","src/kernel/gpu/bus/third_party_p2p.c",0x36d);
      }
    }
    else if (uVar16 != 0) {
      lVar18 = *(long *)(lVar4 + 0x48);
      local_90 = 0;
      plVar17 = *(long **)(lVar4 + 0x58);
      do {
        plVar13 = (long *)listNext_IMPL(lVar7 + 0x90,plVar17);
        lVar15 = plVar17[1];
        uVar14 = (*plVar17 + lVar15) - lVar18;
        if (uVar16 < uVar14) {
          uVar14 = uVar16;
        }
        lVar18 = lVar18 + uVar14;
        uVar16 = uVar16 - uVar14;
        plVar1 = plVar17 + 7;
        *(int *)plVar1 = (int)*plVar1 + -1;
        if ((int)*plVar1 == 0) {
          nvDbg_Printf("src/kernel/gpu/bus/third_party_p2p.c",0x351,
                       "_thirdpartyp2pDelMappingInfoByKey",1,
                       "NVRM: Freeing P2P mapping for gpu VA: 0x%llx, length: 0x%llx\n");
          if (!bVar5) {
            local_90 = kbusUnmapFbAperture_GM107(lVar2,uVar3,plVar17[6],plVar17[2],plVar17[3],0x20);
            lVar15 = extraout_RDX;
          }
          if (local_90 != 0) {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/third_party_p2p.c",0x364);
            lVar15 = extraout_RDX_00;
          }
          listRemoveIntrusive_IMPL(lVar7 + 0x90,plVar17,lVar15);
          *(long *)(local_a8 + 0x348) = *(long *)(local_a8 + 0x348) - plVar17[1];
          memdescDestroy(plVar17[6]);
          portMemFree(plVar17);
        }
        if (plVar13 == (long *)0x0) goto LAB_002e1f2b;
        plVar17 = plVar13;
      } while (uVar16 != 0);
    }
    iVar10 = btreeUnlink(lVar4,lVar7 + 0x88);
    if (iVar10 == 0) {
      portMemFree(lVar4);
    }
  } while (param_3 == (long *)0x0);
  *param_3 = lVar7;
LAB_002e1dc1:
  if (!bVar6) {
    rmDeviceGpuLocksRelease(lVar2,0,0);
  }
  return 0;
}


// ===== 002e2160 thirdpartyp2pConstruct_IMPL =====

int thirdpartyp2pConstruct_IMPL(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  long lVar11;
  undefined8 local_40 [2];
  
  puVar3 = *(uint **)(param_3 + 0x40);
  uVar1 = *(uint *)(param_3 + 8);
  uVar2 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  lVar8 = *(long *)(*(long *)(param_2 + 0x10) + 0x18);
  uVar5 = osGetCurrentProcess();
  lVar8 = __nvoc_dynamicCast(*(undefined8 *)(lVar8 + 8),__nvoc_class_def_Subdevice);
  if ((lVar8 == 0) || (lVar11 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0), lVar11 == 0)) {
    return 0x36;
  }
  cVar4 = gpuIsApmFeatureEnabled_IMPL(lVar11);
  if (cVar4 == '\0') {
    cVar4 = gpuIsGpuFullPower_IMPL(lVar11);
    if (((cVar4 == '\0') && (*(char *)(lVar11 + 0x444) == '\0')) ||
       (cVar4 = gpuCheckSysmemAccess_IMPL(lVar11), cVar4 == '\0')) {
      return 0x11;
    }
    if (puVar3 != (uint *)0x0) {
      uVar6 = *puVar3 & 3;
      if (uVar6 == 1) {
        if (*(char *)(lVar11 + 0x454) != '\0') {
          return 0x1f;
        }
      }
      else {
        if (uVar6 != 2) {
          return (-(uint)(uVar6 == 0) & 0x37) + 0x1f;
        }
        if (*(char *)(lVar11 + 0x454) == '\0') {
          return 0x40;
        }
      }
      LOCK();
      UNLOCK();
      lVar11 = p2pTokenId + 1;
      p2pTokenId = p2pTokenId + 1;
      *(uint *)(param_1 + 0x178) = uVar6;
      *(long *)(param_1 + 400) = lVar11;
      *(long *)(param_1 + 0x180) = lVar8;
      *(ulong *)(param_1 + 0x170) = CONCAT44(uVar1,uVar2);
      *(undefined4 *)(param_1 + 0x188) = 0;
      *(undefined8 *)(param_1 + 0x9b8) = 0;
      *(undefined8 *)(param_1 + 0x9c0) = 0;
      *(undefined8 *)(param_1 + 0x9e0) = 0;
      *(ulong *)(param_1 + 0x140) = (ulong)uVar1;
      *(ulong *)(param_1 + 0x148) = (ulong)uVar1;
      *(long *)(param_1 + 0x138) = param_1;
      portMemSet(param_1 + 0x198,0,0x800);
      uVar9 = portMemAllocatorGetGlobalNonPaged();
      mapInit_IMPL(param_1 + 0x998,uVar9,0x10);
      mapInitIntrusive_IMPL(param_1 + 0x9c8,0x48);
      uVar10 = 0;
      do {
        if (*(int *)(param_1 + 0x198 + uVar10 * 8) == 0) {
          *(ulong *)(param_1 + 0x198 + (uVar10 & 0xffffffff) * 8) = CONCAT44(uVar2,uVar5);
          break;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 != 0x100);
      iVar7 = serverAllocShare(g_resServ,__nvoc_class_def_P2PTokenShare,local_40);
      if (iVar7 != 0) {
        return iVar7;
      }
      lVar8 = __nvoc_dynamicCast(local_40[0],__nvoc_class_def_P2PTokenShare);
      *(long *)(lVar8 + 0x98) = param_1;
      *(long *)(param_1 + 0x9d8) = lVar8;
      return 0;
    }
  }
  return 0x56;
}


// ===== 002e2410 CliGetThirdPartyP2PInfoFromToken =====

undefined8 CliGetThirdPartyP2PInfoFromToken(long param_1,long *param_2)

{
  char cVar1;
  long lVar2;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog("(ppThirdPartyP2P != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0xf2);
    return 0x1f;
  }
  serverutilShareIter(&local_78,0x3e3a6a);
  local_48 = local_78;
  local_40 = local_70;
  local_38 = local_68;
  local_30 = local_60;
  local_28 = local_58;
  local_20 = local_50;
  do {
    cVar1 = serverutilShareIterNext(&local_48);
    if (cVar1 == '\0') {
      return 0x57;
    }
    lVar2 = __nvoc_dynamicCast(local_20,__nvoc_class_def_P2PTokenShare);
  } while ((lVar2 == 0) || (*(long *)(*(long *)(lVar2 + 0x98) + 400) != param_1));
  *param_2 = *(long *)(lVar2 + 0x98);
  return 0;
}


// ===== 002e2500 CliGetThirdPartyP2PPlatformData =====

undefined8 CliGetThirdPartyP2PPlatformData(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 local_50 [8];
  long local_48 [5];
  
  param_1 = param_1 + 0x9c8;
  uVar2 = mapFindLEQ_IMPL(param_1,0xffffffffffffffff);
  uVar3 = mapFindGEQ_IMPL(param_1,0);
  mapIterRange_IMPL(local_48,param_1,uVar3,uVar2);
  do {
    cVar1 = mapIterNext_IMPL(local_48);
    if (cVar1 == '\0') {
      return 0x57;
    }
    uVar2 = btreeSearch(param_2,local_50,*(undefined8 *)(local_48[0] + 0x88));
  } while ((int)uVar2 != 0);
  return uVar2;
}


// ===== 002e2590 CliNextThirdPartyP2PInfoWithPid =====

undefined8
CliNextThirdPartyP2PInfoWithPid
          (undefined8 param_1,int param_2,int param_3,undefined8 *param_4,long *param_5)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  long lVar4;
  int *piVar5;
  undefined8 uVar6;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  serverutilShareIter(&local_88,0x3e3a6a);
  local_58 = local_88;
  local_50 = local_80;
  local_48 = local_78;
  local_40 = local_70;
  local_38 = local_68;
  local_30 = local_60;
LAB_002e25f0:
  do {
    cVar3 = serverutilShareIterNext(&local_58);
    while( true ) {
      if (cVar3 == '\0') {
        return 0x57;
      }
      lVar4 = __nvoc_dynamicCast(local_30,__nvoc_class_def_P2PTokenShare);
      if (lVar4 == 0) goto LAB_002e25f0;
      lVar4 = *(long *)(lVar4 + 0x98);
      if (*param_5 == 0) break;
      if (*(long *)(lVar4 + 400) != *(long *)(*param_5 + 400)) goto LAB_002e25f0;
      *param_4 = 0;
      *param_5 = 0;
      cVar3 = serverutilShareIterNext(&local_58);
    }
    piVar5 = (int *)(lVar4 + 0x198);
    do {
      if (param_2 == *piVar5) {
        if (param_3 == 0) {
LAB_002e26b2:
          uVar6 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(lVar4 + 0x110) + 0x48),
                                     __nvoc_class_def_RmClient);
          *param_4 = uVar6;
          *param_5 = lVar4;
          return 0;
        }
        iVar1 = piVar5[1];
        piVar2 = piVar5;
        while( true ) {
          if (param_3 == iVar1) goto LAB_002e26b2;
          piVar5 = piVar2 + 2;
          if (piVar5 == (int *)(lVar4 + 0x998)) goto LAB_002e25f0;
          if (param_2 != *piVar5) break;
          iVar1 = piVar2[3];
          piVar2 = piVar5;
        }
      }
      piVar5 = piVar5 + 2;
    } while (piVar5 != (int *)(lVar4 + 0x998));
  } while( true );
}


// ===== 002e26f1 CliAddThirdPartyP2PVASpace.cold =====

void CliAddThirdPartyP2PVASpace_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e2700 CliAddThirdPartyP2PVASpace =====

char CliAddThirdPartyP2PVASpace(long param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("(pVASpaceToken != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x164);
    return '\x1f';
  }
  lVar7 = param_1 + 0x998;
  lVar8 = 0xfe00;
  plVar2 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar1 = (undefined4)plVar2[2];
  lVar3 = *plVar2;
  portMemSet(&local_48,0,0x10);
  while( true ) {
    lVar6 = mapFind_IMPL(lVar7,lVar8);
    if (lVar6 == 0) break;
    lVar8 = lVar8 + 1;
    if (lVar8 == 0xff00) {
      return '\x1a';
    }
  }
  local_48 = CONCAT44(uVar1,*(undefined4 *)(lVar3 + 0x48));
  local_40 = param_2;
  local_3c = (int)lVar8;
  lVar6 = mapInsertValue_IMPL(lVar7,param_2,&local_48);
  if (lVar6 != 0) {
    if (param_2 != 0) {
      iVar5 = clientGetResourceRef_IMPL(lVar3,uVar1,&local_58);
      if (iVar5 == 0) {
        iVar5 = clientGetResourceRef_IMPL(lVar3,param_2,&local_50);
        if (iVar5 == 0) {
          refAddDependant(local_50,local_58);
        }
      }
    }
    *param_3 = (int)lVar8;
    return '\0';
  }
  lVar7 = mapFind_IMPL(lVar7,param_2);
  return (-(lVar7 == 0) & 0x38U) + 0x19;
}


// ===== 002e2880 CliDelThirdPartyP2PVASpace =====

undefined8 CliDelThirdPartyP2PVASpace(long param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = mapFind_IMPL(param_1 + 0x998,param_2);
  if (lVar1 != 0) {
    mapRemove_IMPL(param_1 + 0x998,lVar1);
    return 0;
  }
  return 0x57;
}


// ===== 002e28d0 thirdpartyp2pGetNextVASpaceInfo_IMPL =====

byte thirdpartyp2pGetNextVASpaceInfo_IMPL(long param_1,long *param_2)

{
  long lVar1;
  
  if (*param_2 == 0) {
    lVar1 = mapFindGEQ_IMPL(param_1 + 0x998);
  }
  else {
    lVar1 = mapNext_IMPL();
  }
  *param_2 = lVar1;
  return -(lVar1 == 0) & 0x57;
}


// ===== 002e2920 thirdpartyp2pGetVASpaceInfoFromToken_IMPL =====

undefined8 thirdpartyp2pGetVASpaceInfoFromToken_IMPL(long param_1,int param_2,long *param_3)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long local_48 [4];
  
  param_1 = param_1 + 0x998;
  uVar2 = mapFindLEQ_IMPL(param_1,0xffffffffffffffff);
  uVar3 = mapFindGEQ_IMPL(param_1,0);
  mapIterRange_IMPL(local_48,param_1,uVar3,uVar2);
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("(ppVASpaceInfo != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x1ca);
    return 0x1f;
  }
  do {
    cVar1 = mapIterNext_IMPL(local_48);
    if (cVar1 == '\0') {
      return 0x57;
    }
  } while (*(int *)(local_48[0] + 0xc) != param_2);
  *param_3 = local_48[0];
  return 0;
}


// ===== 002e29e2 CliAddThirdPartyP2PVidmemInfo.cold =====

void CliAddThirdPartyP2PVidmemInfo_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e29f0 CliAddThirdPartyP2PVidmemInfo =====

int CliAddThirdPartyP2PVidmemInfo
              (long param_1,undefined4 param_2,long param_3,long param_4,undefined8 param_5,
              long param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  long lVar6;
  
  if (param_6 == 0) {
    nvAssertFailedNoLog("(pMemory != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x1e7);
    return 0x1f;
  }
  puVar5 = (undefined4 *)portMemAllocNonPaged(0xa8);
  if (puVar5 != (undefined4 *)0x0) {
    portMemSet(puVar5,0,0xa8);
    listInitIntrusive_IMPL(puVar5 + 0x24,0x40);
    lVar6 = param_1 + 0x9c8;
    cVar3 = mapInsertExisting_IMPL(lVar6,param_2,puVar5);
    if (cVar3 == '\0') {
      lVar6 = mapFind_IMPL(lVar6,param_2);
      iVar4 = (-(uint)(lVar6 == 0) & 0x27) + 0x19;
    }
    else {
      *(long *)(puVar5 + 6) = param_3;
      *(undefined4 **)(puVar5 + 4) = puVar5;
      *(undefined8 *)(puVar5 + 0x1c) = param_5;
      *(long *)(puVar5 + 8) = param_3 + -1 + param_4;
      iVar4 = btreeInsert(puVar5 + 4,param_1 + 0x9e0);
      if (iVar4 == 0) {
        if (param_1 != 0) {
          *puVar5 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48);
          uVar1 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x110) + 0x48) + 0x10);
          puVar5[2] = param_2;
          puVar5[1] = uVar1;
          *(undefined8 *)(puVar5 + 0x20) = *(undefined8 *)(param_6 + 0x118);
          LOCK();
          UNLOCK();
          lVar6 = vidmemInfoId + 1;
          vidmemInfoId = vidmemInfoId + 1;
          *(long *)(puVar5 + 0x1e) = lVar6;
          return 0;
        }
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      mapRemoveIntrusive_IMPL(lVar6,puVar5);
    }
    portMemFree(puVar5);
    return iVar4;
  }
  return 0x51;
}


// ===== 002e2bf0 CliDelThirdPartyP2PVidmemInfoPersistent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void CliDelThirdPartyP2PVidmemInfoPersistent(long param_1,long param_2)

{
  long lVar1;
  long local_30 [2];
  
  lVar1 = rmapiGetInterface(4);
  local_30[0] = 0;
  if ((param_2 == 0) || (param_1 == 0)) {
    nvAssertFailedNoLog("(pVidmemInfo != NULL) && (pThirdPartyP2P != NULL)",
                        "src/kernel/gpu/bus/third_party_p2p.c",0x223);
  }
  btreeEnumStart(0,local_30,*(undefined8 *)(param_2 + 0x88));
  if (local_30[0] != 0) {
    return;
  }
  (**(code **)(lVar1 + 0x18))(lVar1,*(undefined4 *)(param_1 + 0x170),*(undefined4 *)(param_2 + 8));
  return;
}


// ===== 002e2ca0 CliDelThirdPartyP2PVidmemInfo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 CliDelThirdPartyP2PVidmemInfo(long param_1,undefined4 param_2)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = mapFind_IMPL(param_1 + 0x9c8,param_2);
  if (lVar5 != 0) {
    plVar1 = *(long **)(lVar5 + 0x88);
    while (plVar1 != (long *)0x0) {
      lVar2 = plVar1[1];
      pcVar3 = *(code **)(*plVar1 + 0x38);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(undefined8 *)(*plVar1 + 0x40));
      }
      iVar4 = _thirdpartyp2pDelMappingInfoByKey(param_1,lVar2,0);
      if (iVar4 != 0) {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/third_party_p2p.c",0x24a);
      }
      plVar1 = *(long **)(lVar5 + 0x88);
    }
    mapRemoveIntrusive_IMPL(param_1 + 0x9c8,lVar5);
    iVar4 = btreeUnlink(lVar5 + 0x10,param_1 + 0x9e0);
    if (iVar4 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/third_party_p2p.c",0x253);
    }
    portMemFree(lVar5);
    return 0;
  }
  return 0x57;
}


// ===== 002e2dc0 thirdpartyp2pDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void thirdpartyp2pDestruct_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined1 local_38 [8];
  long local_30 [2];
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x110),local_38,local_30);
  if (*(long *)(param_1 + 0x9d8) != 0) {
    serverFreeShare(g_resServ,*(undefined8 *)(*(long *)(param_1 + 0x9d8) + 0x88));
  }
  lVar1 = local_30[0];
  cVar2 = gpuIsGpuFullPower_IMPL(lVar4);
  if ((cVar2 == '\0') && (*(char *)(lVar4 + 0x444) == '\0')) {
    *(undefined4 *)(lVar1 + 0x30) = 0x11;
    iVar3 = *(int *)(local_30[0] + 0x30);
  }
  else {
    cVar2 = gpuCheckSysmemAccess_IMPL(lVar4);
    *(uint *)(lVar1 + 0x30) = -(uint)(cVar2 == '\0') & 0x11;
    iVar3 = *(int *)(local_30[0] + 0x30);
  }
  if (iVar3 != 0) {
    return;
  }
  mapDestroy_IMPL(param_1 + 0x998);
  iVar3 = 0;
  while (lVar4 = mapFindGEQ_IMPL(param_1 + 0x9c8,0), lVar4 != 0) {
    iVar3 = CliDelThirdPartyP2PVidmemInfo(param_1);
    if (iVar3 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/bus/third_party_p2p.c",0xd7);
    }
  }
  if (*(long *)(param_1 + 0x9e0) != 0) {
    nvAssertFailedNoLog("pThirdPartyP2P->pAddressRangeTree == NULL",
                        "src/kernel/gpu/bus/third_party_p2p.c",0xdf);
  }
  if (*(code **)(param_1 + 0x9b8) != (code *)0x0) {
    (**(code **)(param_1 + 0x9b8))(*(undefined8 *)(param_1 + 0x9c0));
  }
  *(int *)(local_30[0] + 0x30) = iVar3;
  return;
}


// ===== 002e2f20 CliGetThirdPartyP2PVidmemInfoFromAddress =====

undefined8
CliGetThirdPartyP2PVidmemInfoFromAddress
          (long param_1,long param_2,long param_3,long *param_4,long *param_5)

{
  long lVar1;
  undefined8 uVar2;
  long *local_20;
  
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("(pOffset != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x267);
  }
  else if (param_5 == (long *)0x0) {
    nvAssertFailedNoLog("(ppVidmemInfo != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x268);
  }
  else {
    uVar2 = btreeSearch(param_2,&local_20,*(undefined8 *)(param_1 + 0x9e0));
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    lVar1 = *local_20;
    if ((ulong)(param_2 + -1 + param_3) <= *(ulong *)(lVar1 + 0x20)) {
      *param_5 = lVar1;
      *param_4 = (param_2 - *(long *)(lVar1 + 0x18)) + *(long *)(lVar1 + 0x70);
      return uVar2;
    }
  }
  return 0x1f;
}


// ===== 002e3000 CliGetThirdPartyP2PVidmemInfoFromId =====

undefined8 CliGetThirdPartyP2PVidmemInfoFromId(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 *local_20 [2];
  
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("(ppVidmemInfo != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x28c);
    return 0x1f;
  }
  uVar1 = btreeSearch(param_2,local_20,*(undefined8 *)(param_1 + 0x9e0));
  if ((int)uVar1 == 0) {
    *param_3 = *local_20[0];
    return uVar1;
  }
  return uVar1;
}


// ===== 002e3070 CliRegisterThirdPartyP2PMappingCallback =====

undefined8
CliRegisterThirdPartyP2PMappingCallback
          (long param_1,undefined4 param_2,long param_3,long param_4,undefined8 param_5)

{
  long lVar1;
  undefined8 uVar2;
  long *local_30 [2];
  
  if (param_4 == 0) {
    nvAssertFailedNoLog("(pFreeCallback != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x2a5);
  }
  else {
    if (param_3 != 0) {
      lVar1 = mapFind_IMPL(param_1 + 0x9c8,param_2);
      if (lVar1 == 0) {
        return 0x57;
      }
      uVar2 = btreeSearch(param_3,local_30,*(undefined8 *)(lVar1 + 0x88));
      if ((int)uVar2 == 0) {
        lVar1 = *local_30[0];
        if (*(long *)(lVar1 + 0x38) == 0) {
          *(long *)(lVar1 + 0x38) = param_4;
          *(undefined8 *)(lVar1 + 0x40) = param_5;
          return uVar2;
        }
        nvAssertFailedNoLog("(pMappingInfo->pFreeCallback == NULL)",
                            "src/kernel/gpu/bus/third_party_p2p.c",0x2ae);
        return 0x40;
      }
      return uVar2;
    }
    nvAssertFailedNoLog("(pKey != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x2f4);
  }
  return 0x1f;
}


// ===== 002e31a0 CliAddThirdPartyP2PMappingInfo =====

ulong CliAddThirdPartyP2PMappingInfo
                (long param_1,undefined4 param_2,long param_3,undefined8 param_4,undefined8 param_5,
                long *param_6)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("(pKey != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x2c4);
  }
  else {
    if (param_6 != (long *)0x0) {
      lVar1 = mapFind_IMPL(param_1 + 0x9c8,param_2);
      if (lVar1 != 0) {
        lVar2 = portMemAllocNonPaged(0x60);
        if (lVar2 == 0) {
          uVar3 = 0x51;
        }
        else {
          portMemSet(lVar2,0,0x60);
          *(long *)(lVar2 + 8) = param_3;
          *(long *)(lVar2 + 0x10) = param_3;
          *(long *)lVar2 = lVar2;
          uVar3 = btreeInsert(lVar2,lVar1 + 0x88);
          if ((int)uVar3 == 0) {
            *(undefined8 *)(lVar2 + 0x38) = param_4;
            *(undefined8 *)(lVar2 + 0x40) = param_5;
            *param_6 = lVar2;
          }
          else {
            portMemFree(lVar2);
            uVar3 = uVar3 & 0xffffffff;
          }
        }
        return uVar3;
      }
      return 0x57;
    }
    nvAssertFailedNoLog("(ppMappingInfo != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x2c5);
  }
  return 0x1f;
}


// ===== 002e32e0 CliGetThirdPartyP2PMappingInfoFromKey =====

undefined8
CliGetThirdPartyP2PMappingInfoFromKey
          (long param_1,undefined4 param_2,long param_3,undefined8 *param_4)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *local_20;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("(pKey != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x2f4);
  }
  else {
    if (param_4 != (undefined8 *)0x0) {
      lVar1 = mapFind_IMPL(param_1 + 0x9c8,param_2);
      if (lVar1 == 0) {
        return 0x57;
      }
      uVar2 = btreeSearch(param_3,&local_20,*(undefined8 *)(lVar1 + 0x88));
      if ((int)uVar2 == 0) {
        *param_4 = *local_20;
        return uVar2;
      }
      return uVar2;
    }
    nvAssertFailedNoLog("(ppMappingInfo != NULL)","src/kernel/gpu/bus/third_party_p2p.c",0x2f5);
  }
  return 0x1f;
}


// ===== 002e33b0 thirdpartyp2pDelMappingInfoByKey_IMPL =====

void thirdpartyp2pDelMappingInfoByKey_IMPL(undefined8 param_1,undefined8 param_2)

{
  _thirdpartyp2pDelMappingInfoByKey(param_1,param_2,0);
  return;
}


// ===== 002e33c0 thirdpartyp2pDelPersistentMappingInfoByKey_IMPL =====

int thirdpartyp2pDelPersistentMappingInfoByKey_IMPL(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_10;
  
  local_10 = 0;
  iVar1 = _thirdpartyp2pDelMappingInfoByKey(param_1,param_2,&local_10);
  if (iVar1 == 0) {
    CliDelThirdPartyP2PVidmemInfoPersistent(param_1,local_10);
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"_thirdpartyp2pDelMappingInfoByKey(pThirdPartyP2P, pKey, &pVidmemInfo)",
             "src/kernel/gpu/bus/third_party_p2p.c",0x39d);
  return iVar1;
}


// ===== 002e3440 CliAddThirdPartyP2PClientPid =====

undefined8 CliAddThirdPartyP2PClientPid(long param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  ulong uVar4;
  long lVar5;
  int *piVar6;
  
  if (param_1 == 0) {
    return 0x31;
  }
  piVar6 = (int *)(param_1 + 0x198);
  piVar1 = (int *)(param_1 + 0x998);
  piVar2 = piVar6;
  do {
    while (param_2 == *piVar2) {
      if (param_3 == 0) {
        return 0;
      }
      do {
        piVar3 = piVar2;
        if (param_3 == piVar3[1]) {
          return 0;
        }
        piVar2 = piVar3 + 2;
        if (piVar2 == piVar1) goto LAB_002e34a0;
      } while (param_2 == *piVar2);
      piVar2 = piVar3 + 4;
      if (piVar2 == piVar1) goto LAB_002e34a0;
    }
    piVar2 = piVar2 + 2;
  } while (piVar2 != piVar1);
LAB_002e34a0:
  do {
    if (param_2 == *piVar6) {
      nvAssertFailedNoLog("!thirdpartyp2pIsValidClientPid(pThirdPartyP2P, pid, 0)",
                          "src/kernel/gpu/bus/third_party_p2p.c",0x3ba);
      return 99;
    }
    piVar6 = piVar6 + 2;
  } while (piVar6 != piVar1);
  uVar4 = 0;
  do {
    if (*(int *)(param_1 + 0x198 + uVar4 * 8) == 0) {
      lVar5 = (uVar4 & 0xffffffff) + 0x32;
      *(int *)(param_1 + 8 + lVar5 * 8) = param_2;
      *(int *)(param_1 + 0xc + lVar5 * 8) = param_3;
      return 0;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0x100);
  return 0x57;
}


// ===== 002e3540 CliDelThirdPartyP2PClientPid =====

undefined8 CliDelThirdPartyP2PClientPid(long param_1,undefined8 param_2,int param_3,int param_4)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_30 [2];
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x100);
  }
  iVar1 = clientGetResource_IMPL(uVar4,param_2,0x34d08b,local_30);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(local_30[0],__nvoc_class_def_ThirdPartyP2P);
    if (lVar2 != 0) {
      uVar3 = 0;
      do {
        if ((*(int *)(lVar2 + 0x198 + uVar3 * 8) == param_3) &&
           (*(int *)(lVar2 + 0x19c + uVar3 * 8) == param_4)) {
          *(undefined8 *)(lVar2 + 0x198 + (uVar3 & 0xffffffff) * 8) = 0;
          return 0;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 0x100);
    }
  }
  return 0x57;
}


// ===== 002e35f4 CliUnregisterFromThirdPartyP2P.cold =====

void CliUnregisterFromThirdPartyP2P_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e3600 CliUnregisterFromThirdPartyP2P =====

undefined8 CliUnregisterFromThirdPartyP2P(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  long local_28;
  undefined8 local_20;
  
  local_28 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x118);
    uVar2 = *(undefined4 *)(*(long *)(param_1 + 0x100) + 0x48);
    while( true ) {
      iVar4 = CliNextThirdPartyP2PInfoWithPid(0,uVar1,uVar2,&local_20,&local_28);
      if (iVar4 != 0) break;
      CliDelThirdPartyP2PClientPid(local_20,*(undefined4 *)(local_28 + 0x174),uVar1,uVar2);
    }
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 002e3680 shrp2pConstruct_IMPL =====

undefined8 shrp2pConstruct_IMPL(void)

{
  return 0;
}


// ===== 002e3690 shrp2pDestruct_IMPL =====

void shrp2pDestruct_IMPL(void)

{
  return;
}


// ===== 002e3695 CliUnregisterMemoryFromThirdPartyP2P.cold =====

void CliUnregisterMemoryFromThirdPartyP2P_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e36a0 CliUnregisterMemoryFromThirdPartyP2P =====

void CliUnregisterMemoryFromThirdPartyP2P(long param_1)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  char cVar5;
  long lVar6;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  long local_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  undefined8 local_20;
  
  if (param_1 != 0) {
    puVar2 = *(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48);
    uVar3 = *puVar2;
    uVar1 = *(undefined4 *)(puVar2 + 2);
    if (*(long *)(param_1 + 0xe0) != 0) {
      clientRefIter(&local_f8,uVar3,
                    *(undefined8 *)(*(long *)(*(long *)(param_1 + 0xe0) + 0x110) + 0x48),0x4b01b3,0,
                    1);
      local_a8 = local_f8;
      local_a0 = local_f0;
      local_98 = local_e8;
      local_90 = local_e0;
      local_88 = local_d8;
      local_80 = local_d0;
      local_78 = local_c8;
      local_70 = local_c0;
      local_68 = local_b8;
LAB_002e3780:
      do {
        cVar5 = clientRefIterNext(uVar3,&local_a8);
        if (cVar5 == '\0') {
          return;
        }
        clientRefIter(&local_f8,uVar3,local_70,0x34d08b,0,1);
        local_60 = local_f8;
        local_58 = local_f0;
        local_50 = local_e8;
        local_48 = local_e0;
        local_40 = local_d8;
        local_38 = local_d0;
        local_30 = local_c8;
        local_28 = local_c0;
        local_20 = local_b8;
        while (cVar5 = clientRefIterNext(uVar3,&local_60), cVar5 != '\0') {
          while (lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_28 + 8),
                                            __nvoc_class_def_ThirdPartyP2P), lVar6 != 0) {
            CliDelThirdPartyP2PVidmemInfo(lVar6,uVar1);
            cVar5 = clientRefIterNext(uVar3,&local_60);
            if (cVar5 == '\0') goto LAB_002e3780;
          }
        }
      } while( true );
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 002e3880 thirdpartyp2pCtrlCmdRegisterVaSpace_IMPL =====

undefined8 thirdpartyp2pCtrlCmdRegisterVaSpace_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  uint local_1c [3];
  
  if (*(long *)(*(long *)(param_1 + 0x128) + 0xe0) != 0) {
    uVar1 = CliAddThirdPartyP2PVASpace(param_1,*param_2,local_1c);
    if ((int)uVar1 == 0) {
      *(ulong *)(param_2 + 2) = (ulong)local_1c[0];
    }
    return uVar1;
  }
  return 0x36;
}


// ===== 002e38d0 thirdpartyp2pCtrlCmdUnregisterVaSpace_IMPL =====

undefined8 thirdpartyp2pCtrlCmdUnregisterVaSpace_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(*(long *)(param_1 + 0x128) + 0xe0) != 0) {
    uVar1 = CliDelThirdPartyP2PVASpace(param_1,*param_2);
    return uVar1;
  }
  return 0x36;
}


// ===== 002e38f6 thirdpartyp2pCtrlCmdRegisterVidmem_IMPL.cold =====

void thirdpartyp2pCtrlCmdRegisterVidmem_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e3900 thirdpartyp2pCtrlCmdRegisterVidmem_IMPL =====

undefined8 thirdpartyp2pCtrlCmdRegisterVidmem_IMPL(long param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long local_40 [2];
  
  if (param_1 == 0) {
    uVar6 = thirdpartyp2pCtrlCmdRegisterVidmem_IMPL_cold();
    return uVar6;
  }
  if (*(long *)(*(long *)(param_1 + 0x128) + 0xe0) == 0) {
    uVar6 = 0x36;
  }
  else {
    uVar1 = *(ulong *)(param_2 + 2);
    uVar2 = *(ulong *)(param_2 + 4);
    uVar3 = *(ulong *)(param_2 + 6);
    if (*(long *)(param_1 + 0x180) == 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)invalidInstructionException();
      (*pcVar4)();
    }
    uVar6 = memGetByHandleAndDevice_IMPL
                      (**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),*param_2,
                       *(undefined4 *)
                        (*(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x180) + 0x140) + 0x48) +
                                  0x18) + 0x10),local_40);
    if ((int)uVar6 == 0) {
      iVar5 = memdescGetAddressSpace(*(undefined8 *)(local_40[0] + 0x118));
      uVar6 = 0x56;
      if (iVar5 == 2) {
        if ((((uVar2 == 0) || (((short)uVar1 != 0 || (short)uVar2 != 0) || (short)uVar3 != 0)) ||
            (CARRY8(uVar1,uVar2))) ||
           ((CARRY8(uVar2,uVar3) ||
            (*(ulong *)(*(long *)(local_40[0] + 0x118) + 0x30) < uVar2 + uVar3)))) {
          return 0x1f;
        }
        uVar6 = CliAddThirdPartyP2PVidmemInfo(param_1,*param_2,uVar1,uVar2,uVar3);
      }
    }
  }
  return uVar6;
}


// ===== 002e3a70 thirdpartyp2pCtrlCmdUnregisterVidmem_IMPL =====

undefined8 thirdpartyp2pCtrlCmdUnregisterVidmem_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(*(long *)(param_1 + 0x128) + 0xe0) != 0) {
    uVar1 = CliDelThirdPartyP2PVidmemInfo(param_1,*param_2);
    return uVar1;
  }
  return 0x36;
}


// ===== 002e3aa0 thirdpartyp2pCtrlCmdRegisterPid_IMPL =====

undefined8 thirdpartyp2pCtrlCmdRegisterPid_IMPL(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = serverutilGetClientUnderLock(*param_2);
  if (lVar1 != 0) {
    uVar2 = CliAddThirdPartyP2PClientPid(param_1,*(undefined4 *)(lVar1 + 0x118),*param_2);
    return uVar2;
  }
  nvAssertFailedNoLog("pClient != NULL","src/kernel/gpu/bus/third_party_p2p_ctrl.c",0xb7);
  return 0x23;
}


// ===== 002e3b00 kccuGetBufSize_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kccuGetBufSize_GB100(long param_1,long param_2)

{
  int iVar1;
  int local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800ab2,local_1c,4);
  if (iVar1 == 0) {
    iVar1 = (local_1c[0] + -8) * 2;
    *(int *)(param_2 + 0x268) = local_1c[0] + 0xe;
    *(int *)(param_2 + 0x25c) = iVar1;
    *(int *)(param_2 + 0x260) = iVar1 + 0x15;
    *(int *)(param_2 + 0x264) = local_1c[0] + -8;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/ccu/arch/blackwell/kernel_ccu_gb100.c",0x3f,"kccuGetBufSize_GB100",4,
               "NVRM: CCU sample size retrieval failed with status: 0x%x\n");
  return iVar1;
}


// ===== 002e3bb0 kccuMigShrBufHandler_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kccuMigShrBufHandler_GH100(long param_1,long param_2,char param_3)

{
  int iVar1;
  ulong uVar2;
  undefined2 local_2a;
  
  nvDbg_Printf("src/kernel/gpu/ccu/arch/hopper/kernel_ccu_gh100.c",0x35,"kccuMigShrBufHandler_GH100"
               ,1,"NVRM: Create/delete CCU shared buffers for mig (migEnabled:%u)\n");
  if (param_3 == '\0') {
    if (*(char *)(param_2 + 600) != '\0') {
      local_2a = 0x100;
      iVar1 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ab4,&local_2a,2);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/gpu/ccu/arch/hopper/kernel_ccu_gh100.c",0x58,
                     "kccuMigShrBufHandler_GH100",4,
                     "NVRM: CCU mig memdesc unmap request failed with status: 0x%x\n",iVar1);
      }
      uVar2 = 1;
      do {
        if (*(long *)(param_2 + 0x178 + uVar2 * 8) != 0) {
          kccuShrBufIdxCleanup_IMPL(param_1,param_2,uVar2 & 0xffffffff);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 != 9);
      *(undefined1 *)(param_2 + 600) = 0;
      return iVar1;
    }
  }
  else if (*(char *)(param_2 + 600) == '\0') {
    iVar1 = kccuInitMigSharedBuffer_IMPL(param_1,param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
    *(undefined1 *)(param_2 + 600) = 1;
    kccuShrBufInfoToCcu_IMPL(param_1,param_2,1);
    return 0;
  }
  return 0;
}


// ===== 002e3d20 kccuGetBufSize_GH100 =====

undefined8 kccuGetBufSize_GH100(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x25c) = 0x401500004000;
  *(undefined8 *)(param_2 + 0x264) = 0x81600000800;
  return 0;
}


// ===== 002e3d50 _kccuAllocMemory =====

ulong _kccuAllocMemory(long param_1,long param_2,uint param_3,undefined4 param_4,uint param_5)

{
  long lVar1;
  char cVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  
  uVar7 = (ulong)param_3;
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x49,"_kccuAllocMemory",1,
               "NVRM: KernelCcu: Allocate memory for class members and shared buffer\n");
  cVar2 = *(char *)(param_1 + 0x908);
  uVar5 = portMemAllocNonPaged(0x38);
  lVar1 = param_2 + uVar7 * 0x10;
  *(undefined8 *)(lVar1 + 0x1c8) = uVar5;
  lVar6 = portMemAllocNonPaged(0x10);
  *(long *)(lVar1 + 0x1d0) = lVar6;
  if ((*(long *)(lVar1 + 0x1c8) == 0) || (lVar6 == 0)) {
    uVar9 = 0x51;
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x59,"_kccuAllocMemory",4,
                 "NVRM: CCU port mem alloc failed for(%u) with status: 0x%x\n",param_3,0x51);
  }
  else {
    portMemSet(*(long *)(lVar1 + 0x1c8),0,0x38);
    portMemSet(*(undefined8 *)(lVar1 + 0x1d0),0,0x10);
    uVar4 = memdescCreate(param_2 + 0x178 + uVar7 * 8,param_1,param_4,0,1,2 - (uint)(cVar2 == '\0'),
                          0);
    uVar9 = (ulong)uVar4;
    if (uVar4 == 0) {
      lVar6 = *(long *)(param_2 + 0x178 + uVar7 * 8);
      if (lVar6 == 0) {
        nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x6b,"_kccuAllocMemory",4,
                     "NVRM: CCU memdescCreate failed. memdesc for(%u) is NULL\n",param_3);
      }
      else {
        *(undefined4 *)(lVar6 + 0x9c) = 0x58;
        uVar7 = memdescAlloc(lVar6);
        uVar9 = uVar7 & 0xffffffff;
        if ((int)uVar7 == 0) {
          if (*(char *)(param_1 + 0x908) == '\0') {
            uVar4 = memdescMap(lVar6,0,param_4,1,3,*(long *)(lVar1 + 0x1d0),
                               *(long *)(lVar1 + 0x1d0) + 8);
            uVar9 = (ulong)uVar4;
            if (uVar4 == 0) {
              lVar8 = **(long **)(lVar1 + 0x1d0);
              goto LAB_002e3ec9;
            }
          }
          else {
            memdescSetPageSize(lVar6,0,0x1000);
            puVar3 = *(undefined8 **)(lVar1 + 0x1d0);
            uVar5 = memdescMapInternal(param_1,lVar6,0);
            *puVar3 = uVar5;
            lVar8 = **(long **)(lVar1 + 0x1d0);
            if (lVar8 != 0) {
LAB_002e3ec9:
              portMemSet(lVar8,0,param_4);
              **(undefined8 **)(lVar1 + 0x1c8) = **(undefined8 **)(lVar1 + 0x1d0);
              *(long *)(*(long *)(lVar1 + 0x1c8) + 0x28) = **(long **)(lVar1 + 0x1d0) + 8;
              *(ulong *)(*(long *)(lVar1 + 0x1c8) + 8) =
                   *(long *)(*(long *)(lVar1 + 0x1c8) + 0x28) + (ulong)param_5;
              *(long *)(*(long *)(lVar1 + 0x1c8) + 0x10) =
                   *(long *)(*(long *)(lVar1 + 0x1c8) + 8) + 8;
              *(long *)(*(long *)(lVar1 + 0x1c8) + 0x18) =
                   *(long *)(*(long *)(lVar1 + 0x1c8) + 0x10) + 4;
              *(long *)(*(long *)(lVar1 + 0x1c8) + 0x20) =
                   *(long *)(*(long *)(lVar1 + 0x1c8) + 0x18) + 1;
              *(uint *)(*(long *)(lVar1 + 0x1c8) + 0x30) = param_5;
              portMemSet(*(undefined8 *)(*(long *)(lVar1 + 0x1c8) + 0x28),0);
              **(undefined1 **)(*(long *)(lVar1 + 0x1c8) + 0x18) = 0xff;
              **(undefined1 **)(*(long *)(lVar1 + 0x1c8) + 0x20) = 0xff;
              return 0;
            }
            uVar9 = 0x1a;
          }
          nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x8b,"_kccuAllocMemory",4,
                       "NVRM: CCU memdescMap failed for(%u)with status: 0x%x\n",param_3,uVar9);
          memdescFree(lVar6);
          memdescDestroy(lVar6);
        }
        else {
          nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x73,"_kccuAllocMemory",4,
                       "NVRM: CCU memdescAlloc failed for(%u) with status: 0x%x\n",param_3,uVar7);
          memdescDestroy(lVar6);
        }
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",100,"_kccuAllocMemory",4,
                   "NVRM: CCU memdescCreate failed for(%u) with status: 0x%x\n",param_3,uVar9);
    }
  }
  portMemFree(*(undefined8 *)(lVar1 + 0x1c8));
  portMemFree(*(undefined8 *)(lVar1 + 0x1d0));
  return uVar9;
}


// ===== 002e4150 _kccuVgpuShrBufInfoToCcu =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int _kccuVgpuShrBufInfoToCcu
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,uint param_5,
              undefined1 param_6)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0x178 + (ulong)param_5 * 8);
  if (lVar3 != 0) {
    uVar2 = memdescGetPte(lVar3,1,0);
    lVar3 = gpuGetRpc(param_1);
    iVar1 = 0;
    if (lVar3 != 0) {
      iVar1 = (**(code **)(lVar3 + 0x4a8))
                        (param_1,lVar3,uVar2 >> 0xc,param_3,param_4,*(undefined4 *)(param_2 + 0x268)
                         ,param_6);
      if (iVar1 != 0) {
        nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x2d3,"_kccuVgpuShrBufInfoToCcu",4,
                     "NVRM: CCU vGPU memdesc map rpc request failed with status: 0x%x\n");
      }
    }
    return iVar1;
  }
  return 0;
}


// ===== 002e4230 kccuConstructEngine_IMPL =====

undefined8 kccuConstructEngine_IMPL(void)

{
  return 0;
}


// ===== 002e4240 kccuShrBufIdxCleanup_IMPL =====

void kccuShrBufIdxCleanup_IMPL(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  long lVar3;
  ulong uVar4;
  
  uVar4 = (ulong)param_3;
  uVar1 = *(undefined8 *)(param_2 + 0x178 + uVar4 * 8);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0xc5,"kccuShrBufIdxCleanup_IMPL",1,
               "NVRM: Shared buffer unmap & free for idx(%u).\n",uVar4);
  if (*(char *)(param_1 + 0x908) == '\0') {
    puVar2 = *(undefined8 **)(param_2 + 0x1d0 + uVar4 * 0x10);
    memdescUnmap(uVar1,1,*puVar2,puVar2[1]);
  }
  else {
    memdescUnmapInternal(param_1,uVar1,0);
    **(undefined8 **)(param_2 + 0x1d0 + uVar4 * 0x10) = 0;
  }
  memdescFree(uVar1);
  memdescDestroy(uVar1);
  lVar3 = uVar4 * 0x10 + param_2;
  portMemFree(*(undefined8 *)(lVar3 + 0x1c8));
  portMemFree(*(undefined8 *)(lVar3 + 0x1d0));
  *(undefined8 *)(lVar3 + 0x1c8) = 0;
  *(undefined8 *)(lVar3 + 0x1d0) = 0;
  *(undefined8 *)(param_2 + 0x178 + uVar4 * 8) = 0;
  return;
}


// ===== 002e4350 _kccuUnmapAndFreeMemory =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kccuUnmapAndFreeMemory(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined2 local_2a [5];
  
  local_2a[0] = 0;
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0xf0,"_kccuUnmapAndFreeMemory",1,
               "NVRM: KernelCcu: Unmap and free shared buffer\n");
  local_2a[0] = 0x101;
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800ab4,local_2a,2);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0xff,"_kccuUnmapAndFreeMemory",4,
                 "NVRM: CCU memdesc unmap request failed with status: 0x%x\n",iVar1);
  }
  uVar2 = 0;
  do {
    if (*(long *)(param_2 + 0x178 + uVar2 * 8) != 0) {
      kccuShrBufIdxCleanup_IMPL(param_1,param_2,uVar2 & 0xffffffff);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 9);
  return;
}


// ===== 002e4430 kccuShrBufInfoToCcu_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kccuShrBufInfoToCcu_IMPL(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar5;
  long lVar6;
  undefined8 *puVar7;
  long *plVar8;
  undefined8 local_c8 [19];
  ulong uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    uVar4 = (ulong)uVar1;
    *(undefined8 *)((long)local_c8 + uVar3) = 0;
    *(undefined8 *)((long)local_c8 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_c8 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_c8 + uVar3 + 0x18) = 0;
    uVar3 = uVar4;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_c8 + uVar4) = 0;
  *(undefined8 *)((long)local_c8 + uVar4 + 8) = 0;
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x121,"kccuShrBufInfoToCcu_IMPL",1,
               "NVRM: Send shared buffer info to phyRM/gsp to map.\n");
  if (param_3 < 9) {
    plVar8 = (long *)(param_2 + 0x178 + (ulong)param_3 * 8);
    puVar7 = local_c8 + (ulong)param_3 * 2;
LAB_002e44ec:
    lVar6 = *plVar8;
    while( true ) {
      if (lVar6 != 0) {
        while( true ) {
          uVar5 = memdescGetPhysAddr(lVar6,1,0);
          *puVar7 = uVar5;
          if (param_3 != 0) break;
          lVar6 = plVar8[1];
          param_3 = 1;
          local_c8[1] = CONCAT44(*(undefined4 *)(param_2 + 0x25c),*(undefined4 *)(param_2 + 0x260));
          if (lVar6 == 0) {
            plVar8 = plVar8 + 2;
            puVar7 = puVar7 + 4;
            param_3 = 2;
            goto LAB_002e44ec;
          }
          puVar7 = puVar7 + 2;
          plVar8 = plVar8 + 1;
        }
        puVar7[1] = CONCAT44(*(undefined4 *)(param_2 + 0x264),*(undefined4 *)(param_2 + 0x268));
      }
      param_3 = param_3 + 1;
      if (param_3 == 9) break;
      lVar6 = plVar8[1];
      plVar8 = plVar8 + 1;
      puVar7 = puVar7 + 2;
    }
  }
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800ab3,local_c8,0x90);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x141,"kccuShrBufInfoToCcu_IMPL",4,
                 "NVRM: CCU memdesc map request failed with status: 0x%x\n",iVar2);
  }
  return iVar2;
}


// ===== 002e4630 kccuInitMigSharedBuffer_IMPL =====

ulong kccuInitMigSharedBuffer_IMPL(undefined8 param_1,long param_2)

{
  ulong uVar1;
  int iVar2;
  
  iVar2 = 1;
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x176,"kccuInitMigSharedBuffer_IMPL",1,
               "NVRM: Init shared buffer for mig counters.\n");
  do {
    uVar1 = _kccuAllocMemory(param_1,param_2,iVar2,*(undefined4 *)(param_2 + 0x268),
                             *(undefined4 *)(param_2 + 0x264));
    if ((int)uVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x17e,"kccuInitMigSharedBuffer_IMPL",4,
                   "NVRM: CCU memory allocation failed for idx(%u) with status: 0x%x\n",iVar2,uVar1)
      ;
      _kccuUnmapAndFreeMemory(param_1,param_2);
      return uVar1 & 0xffffffff;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 9);
  return uVar1 & 0xffffffff;
}


// ===== 002e4710 kccuStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kccuStateLoad_IMPL(long param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x1a5,"kccuStateLoad_IMPL",1,
               "NVRM: KernelCcu: State load \n");
  uVar2 = (**(code **)(param_2 + 0x170))(param_1,param_2);
  if (uVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x158,"_kccuInitDevSharedBuffer",1,
                 "NVRM: Init shared buffer for device counters.\n",0);
    uVar2 = _kccuAllocMemory(param_1,param_2,0,*(undefined4 *)(param_2 + 0x260),
                             *(undefined4 *)(param_2 + 0x25c));
    if (uVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x15e,"_kccuInitDevSharedBuffer",4,
                   "NVRM: CCU memory allocation failed with status: 0x%x\n",uVar2);
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x1b3,"kccuStateLoad_IMPL",4,
                   "NVRM: Failed to init device shared buffer(status: %u) \n",uVar2);
      return (ulong)uVar2;
    }
    if (*(long *)(param_1 + 0x1bc0) != 0) {
      cVar1 = kmigmgrIsMIGEnabled_IMPL(param_1);
      if (cVar1 != '\0') {
        uVar2 = kccuInitMigSharedBuffer_IMPL(param_1,param_2);
        if (uVar2 != 0) {
          nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x1bd,"kccuStateLoad_IMPL",4,
                       "NVRM: Failed to init mig shared buffer(status: %u) \n",uVar2);
          goto LAB_002e484d;
        }
        *(undefined1 *)(param_2 + 600) = 1;
      }
    }
    uVar3 = kccuShrBufInfoToCcu_IMPL(param_1,param_2,0);
    return uVar3;
  }
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x1ab,"kccuStateLoad_IMPL",4,
               "NVRM: Failed to get the buffer size info(status: %u) \n",uVar2);
LAB_002e484d:
  return (ulong)uVar2;
}


// ===== 002e4900 kccuStateUnload_IMPL =====

undefined8 kccuStateUnload_IMPL(long param_1,long param_2)

{
  if (*(char *)(param_1 + 0x908) != '\0') {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x1e1,"kccuStateUnload_IMPL",1,
               "NVRM: KernelCcu: State unload \n");
  *(undefined1 *)(param_2 + 0x1c0) = 0;
  _kccuUnmapAndFreeMemory(param_1,param_2);
  *(undefined1 *)(param_2 + 600) = 0;
  return 0;
}


// ===== 002e4970 kccuMemDescGetForShrBufId_IMPL =====

undefined8
kccuMemDescGetForShrBufId_IMPL(undefined8 param_1,long param_2,uint param_3,undefined8 *param_4)

{
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x201,"kccuMemDescGetForShrBufId_IMPL",1,
               "NVRM: KernelCcu: Get memdesc for idx(%u) \n",param_3);
  if (param_3 < 9) {
    *param_4 = *(undefined8 *)(param_2 + 0x178 + (ulong)param_3 * 8);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x205,"kccuMemDescGetForShrBufId_IMPL",4,
               "NVRM: CCU memdesc get failed for input idx(%u). Invalid index.\n",param_3);
  return 0x1f;
}


// ===== 002e4a10 kccuCounterBlockSizeGet_IMPL =====

undefined4 kccuCounterBlockSizeGet_IMPL(undefined8 param_1,long param_2,char param_3)

{
  undefined4 *puVar1;
  
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x220,"kccuCounterBlockSizeGet_IMPL",1,
               "NVRM: KernelCcu: Get counter block size \n");
  puVar1 = (undefined4 *)(param_2 + 0x264);
  if (param_3 != '\0') {
    puVar1 = (undefined4 *)(param_2 + 0x25c);
  }
  return *puVar1;
}


// ===== 002e4a70 kccuStreamStateSet_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kccuStreamStateSet_IMPL(long param_1,long param_2,byte *param_3)

{
  byte bVar1;
  int iVar2;
  long *plVar3;
  char *pcVar4;
  byte local_29;
  
  local_29 = 0;
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x23e,"kccuStreamStateSet_IMPL",1,
               "NVRM: KernelCcu: Set ccu stream \n");
  if ((param_3 == (byte *)0x0) || (bVar1 = *param_3, 1 < bVar1)) {
    iVar2 = 0x1f;
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x243,"kccuStreamStateSet_IMPL",4,
                 "NVRM: KernelCcu: Invalid input params\n");
  }
  else if (bVar1 == *(byte *)(param_2 + 0x1c0)) {
    pcVar4 = "ENABLED";
    if (bVar1 == 0) {
      pcVar4 = "DISABLED";
    }
    iVar2 = 0;
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x249,"kccuStreamStateSet_IMPL",1,
                 "NVRM: KernelCcu: CCU stream state is already (%s)\n",pcVar4);
  }
  else {
    local_29 = bVar1;
    iVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800abd,&local_29,1);
    if (iVar2 == 0) {
      *(byte *)(param_2 + 0x1c0) = local_29;
      if (local_29 == 0) {
        plVar3 = (long *)(param_2 + 0x178);
        do {
          if (*plVar3 != 0) {
            portMemSet(**(undefined8 **)((-0x120 - param_2) + (long)plVar3 * 2),0,
                       *(undefined8 *)(*plVar3 + 0x30));
          }
          plVar3 = plVar3 + 1;
        } while (plVar3 != (long *)(param_2 + 0x1c0));
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x25b,"kccuStreamStateSet_IMPL",4,
                   "NVRM: CCU stream state set failed with status: 0x%x\n",iVar2);
    }
  }
  return iVar2;
}


// ===== 002e4c40 kccuStreamStateGet_IMPL =====

undefined1 kccuStreamStateGet_IMPL(undefined8 param_1,long param_2)

{
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x281,"kccuStreamStateGet_IMPL",1,
               "NVRM: KernelCcu: Get ccu stream \n");
  return *(undefined1 *)(param_2 + 0x1c0);
}


// ===== 002e4ca0 kccuMemDescGetForComputeInst_IMPL =====

undefined1  [16]
kccuMemDescGetForComputeInst_IMPL
          (undefined8 param_1,long param_2,ulong param_3,char param_4,long *param_5)

{
  long lVar1;
  undefined1 auVar2 [16];
  long *plVar3;
  undefined1 auVar4 [16];
  undefined8 uStack_10;
  
  plVar3 = (long *)(param_2 + 0x180);
  while( true ) {
    if (((*plVar3 != 0) &&
        (lVar1 = *(long *)((-0x128 - param_2) + (long)plVar3 * 2),
        **(char **)(lVar1 + 0x18) == (char)param_3)) && (**(char **)(lVar1 + 0x20) == param_4))
    break;
    plVar3 = plVar3 + 1;
    if (plVar3 == (long *)(param_2 + 0x1c0)) {
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x2af,"kccuMemDescGetForComputeInst_IMPL",4,
                   "NVRM: KernelCcu: memdesc get failed for input swizzId(%u), computeInst(%u)\n",
                   param_3 & 0xff,param_4);
      auVar4._8_8_ = uStack_10;
      auVar4._0_8_ = 0x1f;
      return auVar4;
    }
  }
  *param_5 = *plVar3;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_3;
  return auVar2 << 0x40;
}


// ===== 002e4d40 kccuDeInitVgpuMigSharedBuffer_IMPL =====

int kccuDeInitVgpuMigSharedBuffer_IMPL
              (undefined8 param_1,long param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  
  if (*(long *)(param_2 + 0x178 + (ulong)(param_4 + 1U) * 8) == 0) {
    return 0;
  }
  iVar1 = _kccuVgpuShrBufInfoToCcu();
  if (iVar1 == 0) {
    kccuShrBufIdxCleanup_IMPL(param_1,param_2,param_4 + 1U);
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"_kccuVgpuShrBufInfoToCcu(pGpu, pKernelCcu, swizzId, computeId, idx, NV_FALSE)",
             "src/kernel/gpu/ccu/kernel_ccu.c",0x2ee);
  return iVar1;
}


// ===== 002e4dc0 kccuInitVgpuMigSharedBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kccuInitVgpuMigSharedBuffer_IMPL(long param_1,long param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    return 0x56;
  }
  if ((*(long *)(param_1 + 0x1bc0) == 0) || (cVar1 = kmigmgrIsMIGEnabled_IMPL(), cVar1 == '\0')) {
    return 0x56;
  }
  uVar2 = (**(code **)(param_2 + 0x170))(param_1,param_2);
  if (uVar2 != 0) {
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x310,"kccuInitVgpuMigSharedBuffer_IMPL",4,
                 "NVRM: Failed to get the buffer size info(status: %u) \n",uVar2);
    return (ulong)uVar2;
  }
  uVar3 = _kccuAllocMemory(param_1,param_2,param_4 + 1,*(undefined4 *)(param_2 + 0x268),
                           *(undefined4 *)(param_2 + 0x264));
  if ((int)uVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu.c",0x318,"kccuInitVgpuMigSharedBuffer_IMPL",4,
                 "NVRM: vGPU memory allocation failed for idx(%u) with status: 0x%x\n",param_4 + 1,
                 uVar3);
    kccuShrBufIdxCleanup_IMPL(param_1,param_2,param_4 + 1);
    return uVar3 & 0xffffffff;
  }
  uVar3 = _kccuVgpuShrBufInfoToCcu(param_1,param_2,param_3,param_4,param_4 + 1,1);
  return uVar3;
}


// ===== 002e4f60 _kccuapiMemdescGet.isra.0 =====

undefined8
_kccuapiMemdescGet_isra_0(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  long local_48;
  long local_40;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1d20);
  uVar5 = *(undefined8 *)(lVar1 + 0x1bc0);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x4a,"_kccuapiMemdescGet",1,
               "NVRM: Kernel Ccu Api: Get memdesc info\n");
  if (lVar2 == 0) {
    return 0x31;
  }
  if (*(long *)(lVar1 + 0x1bc0) != 0) {
    cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar1);
    if (cVar3 != '\0') {
      iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar5,param_3,&local_48);
      if (iVar4 == 0) {
        if ((local_48 == 0) || (local_40 == 0)) {
          uVar5 = 0x3d;
        }
        else {
          uVar5 = kccuMemDescGetForComputeInst_IMPL
                            (lVar1,lVar2,*(undefined1 *)(local_48 + 0x968),
                             *(undefined1 *)(local_40 + 0xc0),param_4);
        }
      }
      else {
        cVar3 = rmclientIsCapable_IMPL(param_2,3);
        uVar5 = 0x1b;
        if (cVar3 != '\0') {
          uVar5 = kccuMemDescGetForShrBufId_IMPL(lVar1,lVar2,0,param_4);
        }
      }
      return uVar5;
    }
  }
  uVar5 = kccuMemDescGetForShrBufId_IMPL(lVar1,lVar2,0,param_4);
  return uVar5;
}


// ===== 002e50b0 kccuapiConstruct_IMPL =====

undefined8 kccuapiConstruct_IMPL(void)

{
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x2c,"kccuapiConstruct_IMPL",1,
               "NVRM: Kernel Ccu Api: Construct\n");
  return 0;
}


// ===== 002e50f0 kccuapiDestruct_IMPL =====

void kccuapiDestruct_IMPL(void)

{
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x37,"kccuapiDestruct_IMPL",1,
               "NVRM: Kernel Ccu Api: Destruct\n");
  return;
}


// ===== 002e5120 kccuapiMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kccuapiMap_IMPL(long param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  long *plVar5;
  undefined1 local_41;
  long local_40 [2];
  
  local_41 = 0;
  local_40[0] = 0;
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x7d,"kccuapiMap_IMPL",1,
               "NVRM: Kernel Ccu Api: memdesc map\n");
  uVar4 = *(undefined4 *)(param_4 + 0x10);
  uVar2 = (**(code **)(*plVar5 + 0xd8))(plVar5);
  iVar3 = rmapiValidateKernelMapping(uVar2,uVar4,&local_41);
  if (iVar3 == 0) {
    uVar4 = osGetCurrentProcess();
    *(undefined4 *)(param_4 + 0x48) = uVar4;
    iVar3 = _kccuapiMemdescGet_isra_0(*(undefined8 *)(param_1 + 0x128),plVar5,uVar1,local_40);
    if (iVar3 == 0) {
      if (local_40[0] == 0) {
        iVar3 = 0x31;
        nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x8e,"kccuapiMap_IMPL",4,
                     "NVRM: Shared buffer memdesc is NULL\n");
      }
      else {
        iVar3 = memdescMap(local_40[0],0,*(undefined8 *)(local_40[0] + 0x30),local_41,
                           *(undefined4 *)(*(long *)(param_4 + 0x50) + 0x20),param_4 + 0x18,
                           *(long *)(param_4 + 0x50) + 0x18);
        if (iVar3 != 0) {
          nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x9c,"kccuapiMap_IMPL",4,
                       "NVRM: kernelCcuApi shared buffer memdescMap failed with status: 0x%x\n",
                       iVar3);
        }
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar3,"_kccuapiMemdescGet(pKernelCcuApi, pClient, pDevice, &pMemDesc)",
                 "src/kernel/gpu/ccu/kernel_ccu_api.c",0x8a);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x84,"kccuapiMap_IMPL",4,
                 "NVRM: Kernel mapping validation failed with status: 0x%x\n",iVar3);
  }
  return iVar3;
}


// ===== 002e52f0 kccuapiUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kccuapiUnmap_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  long *plVar5;
  undefined1 local_41;
  long local_40 [2];
  
  local_41 = 0;
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8);
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  local_40[0] = 0;
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0xb1,"kccuapiUnmap_IMPL",1,
               "NVRM: Kernel Ccu Api: memdesc unmap\n");
  uVar1 = *(undefined4 *)(param_3 + 0x10);
  uVar3 = (**(code **)(*plVar5 + 0xd8))(plVar5);
  iVar4 = rmapiValidateKernelMapping(uVar3,uVar1,&local_41);
  if (iVar4 == 0) {
    iVar4 = _kccuapiMemdescGet_isra_0(*(undefined8 *)(param_1 + 0x128),plVar5,uVar2,local_40);
    if (iVar4 == 0) {
      if (local_40[0] == 0) {
        iVar4 = 0x31;
        nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0xc0,"kccuapiUnmap_IMPL",4,
                     "NVRM: Shared buffer memdesc is NULL\n");
      }
      else {
        memdescUnmap(local_40[0],local_41,*(undefined8 *)(param_3 + 0x18),
                     *(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18));
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar4,"_kccuapiMemdescGet(pKernelCcuApi, pClient, pDevice, &pMemDesc)",
                 "src/kernel/gpu/ccu/kernel_ccu_api.c",0xbc);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0xb8,"kccuapiUnmap_IMPL",4,
                 "NVRM: Kernel mapping validation failed with status: 0x%x\n",iVar4);
  }
  return iVar4;
}


// ===== 002e5460 kccuapiGetMapAddrSpace_IMPL =====

ulong kccuapiGetMapAddrSpace_IMPL(long param_1,long param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined4 local_44;
  long local_40 [2];
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8);
  local_44 = 0;
  local_40[0] = 0;
  uVar4 = __nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0xdb,"kccuapiGetMapAddrSpace_IMPL",1,
               "NVRM: Kernel Ccu Api: get memdesc address-space\n");
  uVar3 = _kccuapiMemdescGet_isra_0(*(undefined8 *)(param_1 + 0x128),uVar4,uVar1,local_40);
  if (uVar3 == 0) {
    if (local_40[0] == 0) {
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0xe1,"kccuapiGetMapAddrSpace_IMPL",4,
                   "NVRM: Shared buffer memdesc is NULL\n");
      uVar5 = 0x31;
    }
    else {
      uVar5 = rmapiGetEffectiveAddrSpace(uVar2,local_40[0],param_3,&local_44);
      if ((int)uVar5 == 0) {
        *param_4 = local_44;
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar5 & 0xffffffff,
                   "rmapiGetEffectiveAddrSpace(pGpu, pMemDesc, mapFlags, &addrSpace)",
                   "src/kernel/gpu/ccu/kernel_ccu_api.c",0xe5);
        uVar5 = uVar5 & 0xffffffff;
      }
    }
    return uVar5;
  }
  nvCheckOkFailedNoLog
            (4,uVar3,"_kccuapiMemdescGet(pKernelCcuApi, pClient, pDevice, &pMemDesc)",
             "src/kernel/gpu/ccu/kernel_ccu_api.c",0xdd);
  return (ulong)uVar3;
}


// ===== 002e55d0 kccuapiGetMemoryMappingDescriptor_IMPL =====

ulong kccuapiGetMemoryMappingDescriptor_IMPL(long param_1,long *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long local_30;
  
  local_30 = 0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8);
  uVar2 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0xf7,"kccuapiGetMemoryMappingDescriptor_IMPL",1
               ,"NVRM: Kernel Ccu Api: get memdesc\n");
  uVar3 = _kccuapiMemdescGet_isra_0(*(undefined8 *)(param_1 + 0x128),uVar2,uVar1,&local_30);
  if ((int)uVar3 == 0) {
    if (local_30 == 0) {
      nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0xfd,
                   "kccuapiGetMemoryMappingDescriptor_IMPL",4,
                   "NVRM: Shared buffer memdesc is NULL\n");
      uVar3 = 0x31;
    }
    else {
      *param_2 = local_30;
    }
    return uVar3;
  }
  nvCheckOkFailedNoLog
            (4,uVar3 & 0xffffffff,"_kccuapiMemdescGet(pKernelCcuApi, pClient, pDevice, &pMemDesc)",
             "src/kernel/gpu/ccu/kernel_ccu_api.c",0xf9);
  return uVar3 & 0xffffffff;
}


// ===== 002e56f0 kccuapiCtrlCmdSubscribe_IMPL =====

int kccuapiCtrlCmdSubscribe_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 uVar9;
  long local_50;
  long local_48;
  long local_40;
  
  local_50 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar9 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8);
  lVar2 = *(long *)(lVar1 + 0x1d20);
  uVar7 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc0);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x116,"kccuapiCtrlCmdSubscribe_IMPL",1,
               "NVRM: Kernel Ccu Api: CCU subscribe request\n");
  if (lVar2 == 0) {
    return 0x31;
  }
  if ((*(long *)(lVar1 + 0x1bc0) == 0) || (cVar4 = kmigmgrIsMIGEnabled_IMPL(lVar1), cVar4 == '\0'))
  {
    iVar5 = kccuMemDescGetForShrBufId_IMPL(lVar1,lVar2,0,&local_50);
    uVar9 = 0x11f;
    pcVar8 = "kccuMemDescGetForShrBufId(pGpu, pKernelCcu, CCU_DEV_SHRBUF_ID, &pMemDesc)";
    if (iVar5 != 0) goto LAB_002e5920;
    if (local_50 != 0) {
      uVar6 = kccuCounterBlockSizeGet_IMPL(lVar1,lVar2,1);
      *(undefined4 *)(param_2 + 1) = uVar6;
      *param_2 = *(undefined8 *)(local_50 + 0x30);
      return 0;
    }
  }
  else {
    iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar3,uVar9,&local_48);
    if (iVar5 == 0) {
      if ((local_48 == 0) || (local_40 == 0)) {
        return 0x3d;
      }
      iVar5 = kccuMemDescGetForComputeInst_IMPL
                        (lVar1,lVar2,*(undefined1 *)(local_48 + 0x968),
                         *(undefined1 *)(local_40 + 0xc0),&local_50);
      if (iVar5 != 0) {
        uVar9 = 0x145;
        pcVar8 = 
        "kccuMemDescGetForComputeInst(pGpu, pKernelCcu, ref.pKernelMIGGpuInstance->swizzId, ref.pMIGComputeInstance->id, &pMemDesc)"
        ;
LAB_002e5920:
        nvCheckOkFailedNoLog(4,iVar5,pcVar8,"src/kernel/gpu/ccu/kernel_ccu_api.c",uVar9);
        return iVar5;
      }
      uVar6 = kccuCounterBlockSizeGet_IMPL(lVar1,lVar2,0);
    }
    else {
      cVar4 = rmclientIsCapable_IMPL(uVar7,3);
      if (cVar4 == '\0') {
        return iVar5;
      }
      iVar5 = kccuMemDescGetForShrBufId_IMPL(lVar1,lVar2,0,&local_50);
      uVar9 = 0x139;
      pcVar8 = "kccuMemDescGetForShrBufId(pGpu, pKernelCcu, CCU_DEV_SHRBUF_ID, &pMemDesc)";
      if (iVar5 != 0) goto LAB_002e5920;
      uVar6 = kccuCounterBlockSizeGet_IMPL
                        (lVar1,lVar2,1,"src/kernel/gpu/ccu/kernel_ccu_api.c",0x139);
    }
    *(undefined4 *)(param_2 + 1) = uVar6;
    if (local_50 != 0) {
      *param_2 = *(undefined8 *)(local_50 + 0x30);
      return 0;
    }
  }
  return 0x51;
}


// ===== 002e5950 kccuapiCtrlCmdUnsubscribe_IMPL =====

undefined8 kccuapiCtrlCmdUnsubscribe_IMPL(void)

{
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x15a,"kccuapiCtrlCmdUnsubscribe_IMPL",1,
               "NVRM: Kernel Ccu Api: CCU unsubscribe request\n");
  return 0;
}


// ===== 002e5990 kccuapiCtrlCmdSetStreamState_IMPL =====

ulong kccuapiCtrlCmdSetStreamState_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1d20);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x169,"kccuapiCtrlCmdSetStreamState_IMPL",1,
               "NVRM: Kernel Ccu Api: CCU set stream state request\n");
  if (lVar2 != 0) {
    uVar3 = kccuStreamStateSet_IMPL(lVar1,lVar2,param_2);
    if ((int)uVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar3 & 0xffffffff,"kccuStreamStateSet(pGpu, pKernelCcu, pParams)",
                 "src/kernel/gpu/ccu/kernel_ccu_api.c",0x171);
      uVar3 = uVar3 & 0xffffffff;
    }
    return uVar3;
  }
  return 0x31;
}


// ===== 002e5a50 kccuapiCtrlCmdGetStreamState_IMPL =====

undefined8 kccuapiCtrlCmdGetStreamState_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  long lVar2;
  undefined1 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1d20);
  nvDbg_Printf("src/kernel/gpu/ccu/kernel_ccu_api.c",0x181,"kccuapiCtrlCmdGetStreamState_IMPL",1,
               "NVRM: Kernel Ccu Api: CCU get stream state request\n");
  if (lVar2 != 0) {
    uVar3 = kccuStreamStateGet_IMPL(lVar1,lVar2);
    *param_2 = uVar3;
    return 0;
  }
  return 0x31;
}


// ===== 002e5ad0 _ceGetAlgorithmPceIndex.isra.0 =====

void _ceGetAlgorithmPceIndex_isra_0
               (long param_1,long param_2,uint *param_3,char *param_4,byte *param_5)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  byte local_19;
  
  if (*param_4 != '\x01') {
    *param_3 = *param_3 + 3;
  }
  *param_4 = '\0';
  uVar2 = *(uint *)(param_2 + (ulong)*param_5 * 4);
  if ((uVar2 >> (*param_3 & 0x1f) & 1) != 0) {
    return;
  }
  if (uVar2 - 1 < 0xfffffffe) {
    uVar4 = 0;
    for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
      uVar4 = uVar4 + 1;
    }
    *param_3 = uVar4;
    if ((*(uint *)(param_2 + (ulong)*param_5 * 4) >> (uVar4 & 0x1f) & 1) != 0) {
      return;
    }
  }
  else {
    *param_3 = 0xffffffff;
  }
  lVar3 = *(long *)(param_1 + 0x1ce8);
  if (lVar3 == 0) {
    uVar2 = *(uint *)(param_2 + (ulong)*param_5 * 4);
  }
  else {
    portMemSet(&local_19,0,1);
    local_19 = *param_5;
    iVar5 = knvlinkExecGspRmRpc_IMPL(param_1,lVar3,0x20800a8c,&local_19,1);
    if (iVar5 == 0) {
      *param_5 = local_19;
      bVar1 = local_19;
    }
    else {
      nvAssertOkFailedNoLog(iVar5,"status","src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x1a7);
      bVar1 = *param_5;
    }
    uVar2 = *(uint *)(param_2 + (ulong)bVar1 * 4);
  }
  if (uVar2 - 1 < 0xfffffffe) {
    uVar4 = 0;
    for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
      uVar4 = uVar4 + 1;
    }
    *param_3 = uVar4;
    if ((*(uint *)(param_2 + (ulong)*param_5 * 4) >> (uVar4 & 0x1f) & 1) != 0) {
      return;
    }
  }
  else {
    *param_3 = 0xffffffff;
  }
  nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x1b2,"_ceGetAlgorithmPceIndex",4,
               "NVRM: No more available PCEs to assign!\n");
  nvAssertFailedNoLog(&DAT_00d01398,"src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x1b3);
  return;
}


// ===== 002e5c70 kceGetPce2lceConfigSize1_GA100 =====

undefined8 kceGetPce2lceConfigSize1_GA100(void)

{
  return 0x12;
}


// ===== 002e5c80 kceGetNvlinkAutoConfigCeValues_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kceGetNvlinkAutoConfigCeValues_GA100
          (long param_1,long param_2,long param_3,long param_4,undefined4 *param_5)

{
  undefined4 uVar1;
  char cVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  uint uVar15;
  int local_80;
  bool local_79;
  undefined4 *local_68;
  undefined8 *local_50;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c [3];
  
  lVar13 = *(long *)(param_1 + 0x1ce8);
  local_48 = 0;
  local_44 = 0;
  local_40 = 0xffff;
  uVar4 = (**(code **)(param_2 + 0x220))(param_2);
  uVar5 = (**(code **)(param_2 + 0x218))(param_2);
  puVar8 = (undefined8 *)portMemAllocNonPaged(0x134);
  if (puVar8 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pCurrentTopo != NULL","src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",
                        0x8d);
    return 0x51;
  }
  if ((param_4 == 0 || param_5 == (undefined4 *)0x0) || (param_3 == 0)) {
    local_50 = (undefined8 *)0x0;
    uVar6 = 0x1f;
    local_68 = (undefined4 *)0x0;
    goto LAB_002e5e76;
  }
  if ((lVar13 == 0) && (*(char *)(param_1 + 0x49a) != '\0')) {
    local_50 = (undefined8 *)0x0;
    uVar6 = 0x56;
    local_68 = (undefined4 *)0x0;
    goto LAB_002e5e76;
  }
  portMemSet(puVar8,0,0x134);
  local_68 = (undefined4 *)portMemAllocNonPaged(0x80);
  local_50 = (undefined8 *)portMemAllocNonPaged(0x10);
  local_3c[0] = 0;
  if ((local_68 == (undefined4 *)0x0) || (local_50 == (undefined8 *)0x0)) {
    uVar6 = 0x51;
    goto LAB_002e5e76;
  }
  puVar9 = local_68;
  do {
    *puVar9 = 0xf;
    puVar10 = puVar9 + 2;
    puVar9[1] = 0xf;
    puVar9 = puVar10;
  } while (local_68 + 0x20 != puVar10);
  *local_50 = 0xf0000000f;
  local_50[1] = 0xf0000000f;
  if (lVar13 == 0) {
    if (*(int *)(param_1 + 0x8fc) == 0) goto LAB_002e6240;
    gpumgrGetGpuAttachInfo(0,&local_48);
    *puVar8 = 0;
    uVar3 = 0;
    *(undefined4 *)(puVar8 + 2) = 0;
    *(undefined1 *)(puVar8 + 1) = 1;
  }
  else {
    uVar6 = knvlinkGetNumLinksToSystem_IMPL(param_1,lVar13);
    if (*(int *)(param_1 + 0x8fc) == 0) {
LAB_002e6240:
      uVar6 = 0x56;
      goto LAB_002e5e76;
    }
    gpumgrGetGpuAttachInfo(0,&local_48);
    local_79 = true;
    local_80 = 0;
    uVar15 = 0;
    while (lVar11 = gpumgrGetNextGpu(local_48,&local_44), lVar11 != 0) {
      uVar7 = knvlinkGetNumLinksToPeer_IMPL(param_1,lVar13,lVar11);
      if (uVar7 != 0) {
        local_80 = local_80 + 1;
        if (local_79 != false) {
          local_79 = uVar15 == 0 || uVar7 == uVar15;
        }
        if (uVar15 < uVar7) {
          uVar15 = uVar7;
        }
      }
    }
    *(uint *)((long)puVar8 + 4) = uVar15;
    *(undefined4 *)puVar8 = uVar6;
    *(int *)(puVar8 + 2) = local_80;
    *(bool *)(puVar8 + 1) = local_79;
    uVar3 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar13);
  }
  *(undefined1 *)((long)puVar8 + 0x14) = uVar3;
  cVar2 = (**(code **)(param_2 + 0x210))
                    (param_1,param_2,puVar8,nvLinkCeAutoConfigTable_GA100,1,&local_40,local_3c);
  if (cVar2 == '\0') {
    uVar6 = (**(code **)(param_2 + 0x228))(param_1,param_2,puVar8,local_68,local_50,local_3c);
  }
  else {
    if (uVar4 != 0) {
      uVar12 = 0;
      do {
        local_68[uVar12] =
             *(undefined4 *)
              (nvLinkCeAutoConfigTable_GA100 +
              ((uVar12 & 0xffffffff) + 4 + (ulong)local_40 * 0x35) * 4);
        uVar12 = uVar12 + 1;
      } while (uVar12 != uVar4);
    }
    if (uVar5 != 0) {
      uVar12 = 0;
      do {
        *(undefined4 *)((long)local_50 + uVar12 * 4) =
             *(undefined4 *)
              (nvLinkCeAutoConfigTable_GA100 +
              ((uVar12 & 0xffffffff) + 0x1c + (ulong)local_40 * 0x35) * 4);
        uVar12 = uVar12 + 1;
      } while (uVar5 != uVar12);
    }
    uVar6 = 0;
  }
  gpumgrGetSystemNvlinkTopo_IMPL(*(undefined8 *)(param_1 + 0x878),puVar8);
  cVar2 = (**(code **)(param_2 + 0x200))(param_1,param_2,puVar8,local_3c,&local_40);
  if (cVar2 != '\0') {
    if (uVar4 != 0) {
      lVar13 = 0;
      do {
        *(undefined4 *)((long)puVar8 + lVar13 + 0x9c) = *(undefined4 *)((long)local_68 + lVar13);
        lVar13 = lVar13 + 4;
      } while ((ulong)uVar4 << 2 != lVar13);
    }
    if (uVar5 != 0) {
      uVar12 = 0;
      do {
        *(undefined4 *)((long)puVar8 + uVar12 * 4 + 0x11c) =
             *(undefined4 *)((long)local_50 + uVar12 * 4);
        uVar12 = uVar12 + 1;
      } while (uVar5 != uVar12);
    }
    *(undefined4 *)((long)puVar8 + 300) = local_3c[0];
    if (local_40 != 0xffff) {
      *(uint *)(puVar8 + 0x26) = local_40;
      *(undefined4 *)puVar8 =
           *(undefined4 *)(nvLinkCeAutoConfigTable_GA100 + (ulong)local_40 * 0xd4);
      lVar13 = (ulong)local_40 * 0xd4;
      *(undefined4 *)((long)puVar8 + 4) =
           *(undefined4 *)(nvLinkCeAutoConfigTable_GA100 + lVar13 + 4);
      *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(nvLinkCeAutoConfigTable_GA100 + lVar13 + 8);
      *(undefined1 *)(puVar8 + 1) = nvLinkCeAutoConfigTable_GA100[lVar13 + 0xc];
      *(undefined1 *)((long)puVar8 + 0x14) = nvLinkCeAutoConfigTable_GA100[lVar13 + 0xd];
    }
    gpumgrUpdateSystemNvlinkTopo_IMPL(*(undefined8 *)(param_1 + 0x878),puVar8);
  }
  nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x121,
               "kceGetNvlinkAutoConfigCeValues_GA100",1,
               "NVRM: GPU%d : RM Configured Values for CE Config\n",*(undefined4 *)(param_1 + 0x7a4)
              );
  if (uVar4 != 0) {
    uVar12 = 0;
    do {
      uVar1 = *(undefined4 *)((long)puVar8 + uVar12 * 4 + 0x9c);
      uVar14 = uVar12 & 0xffffffff;
      *(undefined4 *)(param_3 + uVar12 * 4) = uVar1;
      uVar12 = uVar12 + 1;
      nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x127,
                   "kceGetNvlinkAutoConfigCeValues_GA100",1,"NVRM: PCE-LCE map: PCE %d LCE 0x%x\n",
                   uVar14,uVar1);
    } while (uVar12 != uVar4);
  }
  if (uVar5 != 0) {
    uVar12 = 0;
    do {
      uVar4 = *(uint *)((long)puVar8 + uVar12 * 4 + 0x11c);
      uVar14 = uVar12 & 0xffffffff;
      uVar15 = uVar4 & 0xf | 0x40000000;
      if (uVar4 == 0xf) {
        uVar15 = 0;
      }
      *(uint *)(param_4 + uVar12 * 4) = uVar15;
      uVar12 = uVar12 + 1;
      nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x139,
                   "kceGetNvlinkAutoConfigCeValues_GA100",1,"NVRM: GRCE Config: GRCE %d LCE 0x%x\n",
                   uVar14,uVar15);
    } while (uVar5 != uVar12);
  }
  *param_5 = *(undefined4 *)((long)puVar8 + 300);
  nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x13d,
               "kceGetNvlinkAutoConfigCeValues_GA100",1,"NVRM: exposeCeMask = 0x%x\n");
LAB_002e5e76:
  portMemFree(puVar8);
  portMemFree(local_68);
  portMemFree(local_50);
  return uVar6;
}


// ===== 002e62d0 kceIsCurrentMaxTopology_GA100 =====

undefined8
kceIsCurrentMaxTopology_GA100
          (undefined8 param_1,undefined8 param_2,long param_3,uint *param_4,int *param_5)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 300);
  if ((~*param_4 & uVar1) == 0) {
    return 1;
  }
  if (*param_5 != 0xffff) {
    *param_5 = *(int *)(param_3 + 0x130);
    uVar1 = *(uint *)(param_3 + 300);
  }
  *param_4 = uVar1;
  return 0;
}


// ===== 002e6310 kceGetMappings_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceGetMappings_GA100
          (long param_1,long param_2,long param_3,long param_4,uint *param_5,uint *param_6)

{
  long lVar1;
  uint *puVar2;
  uint *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  
  if (*(long *)(param_1 + 0x1ce8) == 0) {
    return 0;
  }
  cVar7 = knvlinkIsForcedConfig_IMPL();
  if (cVar7 != '\0') {
    return 0;
  }
  kceGetAvailableHubPceMask_IMPL(param_1,param_2,param_3);
  lVar1 = param_3 + 0x18;
  iVar8 = (**(code **)(param_2 + 0x270))
                    (param_1,param_2,lVar1,param_4,param_6,*(undefined4 *)(param_3 + 0x98));
  if (iVar8 == 0x56) {
    nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x1e8,"kceGetMappings_GA100",4,
                 "NVRM: No sysmem connections on this chip (PCIe or NVLink)!\n");
  }
  iVar8 = (**(code **)(param_2 + 0x278))(param_1,param_2,lVar1,param_4,param_6);
  if (iVar8 == 0x10006) {
    (**(code **)(param_2 + 0x288))(param_1,param_2,lVar1,param_4,param_6,2);
  }
  uVar13 = (**(code **)(param_2 + 0x298))(param_1,param_2);
  uVar11 = *(uint *)(param_3 + 0x98);
  *param_6 = *param_6 | uVar13;
  if (uVar11 != 0) {
    puVar2 = param_5 + 2;
    if (uVar11 == 0xffffffff) {
      uVar10 = 0x20f;
      pcVar12 = "pceIndex < NV2080_CTRL_MAX_PCES";
      goto LAB_002e6503;
    }
    do {
      while( true ) {
        uVar5 = 0;
        for (uVar9 = uVar11; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
          uVar5 = uVar5 + 1;
        }
        puVar3 = (uint *)(param_4 + (ulong)uVar5 * 4);
        uVar9 = *puVar3;
        if ((*param_6 >> (uVar9 & 0x1f) & 1) != 0) break;
        uVar9 = 0;
        for (uVar6 = uVar13; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
          uVar9 = uVar9 + 1;
        }
        if (0xfffffffd < uVar13 - 1) {
          uVar9 = 0xffffffff;
        }
        *puVar3 = uVar9;
        *param_5 = 0xf;
        bVar4 = (byte)uVar9 & 0x1f;
        uVar13 = uVar13 & (-2 << bVar4 | 0xfffffffeU >> 0x20 - bVar4);
LAB_002e654a:
        param_5 = param_5 + 1;
        if (puVar2 == param_5) {
          return 0;
        }
        bVar4 = (byte)uVar5 & 0x1f;
        uVar11 = uVar11 & (-2 << bVar4 | 0xfffffffeU >> 0x20 - bVar4);
        if (uVar11 == 0) goto LAB_002e64f0;
      }
      *param_5 = uVar9 & 0xf | 0x40000000;
      cVar7 = (**(code **)(param_2 + 0x2a0))(param_1,param_2,4);
      if ((cVar7 == '\0') && (*(char *)(param_2 + 0x2e1) != '\x01')) goto LAB_002e654a;
      param_5 = param_5 + 1;
      (**(code **)(param_2 + 0x2a8))(param_1,param_2,param_4,lVar1,uVar9,(ulong)uVar5);
      if (puVar2 == param_5) {
        return 0;
      }
      bVar4 = (byte)uVar5 & 0x1f;
      uVar11 = uVar11 & (-2 << bVar4 | 0xfffffffeU >> 0x20 - bVar4);
    } while (uVar11 != 0);
  }
LAB_002e64f0:
  uVar10 = 0x207;
  pcVar12 = "fbPceMask != 0";
LAB_002e6503:
  nvAssertFailedNoLog(pcVar12,"src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",uVar10);
  return 0;
}


// ===== 002e65d0 kceMapPceLceForSysmemLinks_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kceMapPceLceForSysmemLinks_GA100
              (long param_1,long param_2,long param_3,long param_4,uint *param_5,uint param_6)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  bool bVar15;
  uint local_4c;
  undefined1 local_42;
  byte local_41;
  int local_40;
  uint local_3c [3];
  
  lVar8 = *(long *)(param_1 + 0x1ce8);
  if (lVar8 == 0) {
    nvAssertFailedNoLog("pKernelNvlink != NULL","src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",
                        0x25c);
    return 0x56;
  }
  portMemSet(local_3c,0,4);
  iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,lVar8,0x20800aab,local_3c,4);
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x264,
                 "kceMapPceLceForSysmemLinks_GA100",4,
                 "NVRM: Unable to determine PCEs and LCEs for sysmem links\n");
    return iVar4;
  }
  uVar13 = (**(code **)(param_2 + 0x280))(param_1,param_2);
  if (local_3c[0] == 0) {
    *param_5 = *param_5 | uVar13;
    if (param_6 == 0) {
      return 0;
    }
    uVar5 = uVar13 - 1;
    iVar4 = 0;
    for (uVar12 = uVar13; (uVar12 & 1) == 0; uVar12 = uVar12 >> 1 | 0x80000000) {
      iVar4 = iVar4 + 1;
    }
    if (0xfffffffd < uVar5) {
      iVar4 = -1;
    }
    if (param_6 != 0xffffffff) goto LAB_002e66c8;
    uVar13 = uVar13 & uVar5;
    uVar5 = uVar13 - 1;
    *(int *)(param_4 + 0x3fffffffc) = iVar4;
    uVar12 = 0xfffffffe;
    param_6 = 0xfffffffe;
    if (0xfffffffd < uVar5) goto LAB_002e66e5;
    do {
      iVar4 = 0;
      for (uVar12 = uVar13; (uVar12 & 1) == 0; uVar12 = uVar12 >> 1 | 0x80000000) {
        iVar4 = iVar4 + 1;
      }
LAB_002e66c8:
      uVar12 = 0;
      for (uVar9 = param_6; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
        uVar12 = uVar12 + 1;
      }
      *(int *)(param_4 + (ulong)uVar12 * 4) = iVar4;
      uVar12 = param_6 & param_6 - 1;
      while( true ) {
        if (uVar12 == 0) {
          return 0;
        }
        uVar13 = uVar13 & uVar5;
        uVar5 = uVar13 - 1;
        param_6 = uVar12;
        if (uVar5 < 0xfffffffe) break;
LAB_002e66e5:
        uVar9 = 0;
        for (uVar6 = uVar12; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
          uVar9 = uVar9 + 1;
        }
        *(undefined4 *)(param_4 + (ulong)uVar9 * 4) = 0xffffffff;
        uVar12 = uVar12 & uVar12 - 1;
      }
    } while( true );
  }
  puVar7 = (uint *)portMemAllocNonPaged(0x24);
  if (puVar7 == (uint *)0x0) {
    nvAssertFailedNoLog("pParamsHshubId != NULL","src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",
                        0x286);
    return 0x51;
  }
  portMemSet(puVar7,0,0x24);
  *puVar7 = local_3c[0];
  iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,lVar8,0x20800a8a,puVar7,0x24);
  if (iVar4 == 0) {
    if (local_3c[0] != 0) {
      uVar5 = 0;
      uVar9 = 0;
      puVar14 = puVar7 + 1;
      uVar12 = local_3c[0];
      do {
        if ((uVar12 & 1) != 0) {
          local_41 = (byte)*puVar14;
          local_42 = 1;
          local_4c = 2;
          uVar11 = *(uint *)(param_3 + (ulong)local_41 * 4);
          uVar6 = uVar11 - 1;
          local_40 = 0;
          for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1 | 0x80000000) {
            local_40 = local_40 + 1;
          }
          if (0xfffffffd < uVar6) {
            local_40 = -1;
          }
          do {
            _ceGetAlgorithmPceIndex_isra_0(param_1,param_3,&local_40,&local_42,&local_41);
            uVar6 = 1 << ((byte)local_40 & 0x1f);
            uVar9 = uVar9 | uVar6;
            puVar1 = (uint *)(param_3 + (ulong)local_41 * 4);
            *puVar1 = *puVar1 & ~uVar6;
            bVar15 = local_4c != 1;
            local_4c = uVar12 & 1;
          } while (bVar15);
          uVar5 = uVar5 + 2;
          if (uVar12 >> 1 == 0) goto code_r0x002e684f;
        }
        uVar12 = uVar12 >> 1;
        puVar14 = (uint *)((long)puVar14 + 1);
      } while( true );
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x290,
                 "kceMapPceLceForSysmemLinks_GA100",4,
                 "NVRM: Unable to determine Hshub Id for sysmem links");
  }
LAB_002e6870:
  portMemFree(puVar7);
  return iVar4;
code_r0x002e684f:
  uVar5 = uVar5 >> 1;
  if (uVar5 != 0) {
    uVar12 = 0;
    if (uVar13 == 0) {
      do {
        uVar12 = uVar12 + 1;
      } while (uVar12 != uVar5);
    }
    else {
      uVar12 = 0;
      do {
        uVar6 = uVar9 - 1;
        uVar11 = 0;
        for (uVar10 = uVar9; (uVar10 & 1) == 0; uVar10 = uVar10 >> 1 | 0x80000000) {
          uVar11 = uVar11 + 1;
        }
        lVar8 = (ulong)uVar11 << 2;
        if (0xfffffffd < uVar6) {
          lVar8 = 0x3fffffffc;
        }
        uVar11 = uVar13 - 1;
        uVar10 = uVar13;
        if (uVar13 - 1 == 0xfffffffe) {
          *(undefined4 *)(param_4 + lVar8) = 0xffffffff;
          uVar9 = uVar9 & uVar6;
          uVar6 = uVar9 - 1;
          uVar10 = 0xfffffffe;
          if (uVar6 < 0xfffffffe) {
            uVar11 = 0;
            for (uVar3 = uVar9; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x80000000) {
              uVar11 = uVar11 + 1;
            }
            lVar8 = (ulong)uVar11 << 2;
            uVar11 = 0xfffffffd;
          }
          else {
            lVar8 = 0x3fffffffc;
            uVar11 = 0xfffffffd;
          }
        }
        while( true ) {
          uVar9 = uVar9 & uVar6;
          iVar2 = 0;
          for (uVar6 = uVar10; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
            iVar2 = iVar2 + 1;
          }
          *(int *)(param_4 + lVar8) = iVar2;
          uVar10 = uVar10 & uVar11;
          if (uVar10 == 0) break;
          uVar6 = uVar9 - 1;
          if (uVar6 < 0xfffffffe) {
            uVar11 = 0;
            for (uVar3 = uVar9; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x80000000) {
              uVar11 = uVar11 + 1;
            }
            lVar8 = (ulong)uVar11 << 2;
            uVar11 = uVar10 - 1;
          }
          else {
            lVar8 = 0x3fffffffc;
            uVar11 = uVar10 - 1;
          }
        }
        uVar12 = uVar12 + 1;
        *param_5 = *param_5 | uVar13;
      } while (uVar5 != uVar12);
    }
  }
  goto LAB_002e6870;
}


// ===== 002e6a70 kceGetSysmemSupportedLceMask_GA100 =====

undefined8 kceGetSysmemSupportedLceMask_GA100(void)

{
  return 0xc;
}


// ===== 002e6a80 kceMapPceLceForNvlinkPeers_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int kceMapPceLceForNvlinkPeers_GA100
              (long param_1,long param_2,long param_3,long param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  bool bVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  long lVar12;
  ulong uVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  long lVar17;
  uint uVar18;
  undefined1 local_46;
  byte local_45;
  int local_44;
  int local_40 [4];
  
  lVar5 = g_pSys;
  lVar3 = *(long *)(param_1 + 0x1ce8);
  local_46 = 0;
  local_40[1] = 0;
  if (lVar3 == 0) {
    return 0x10006;
  }
  puVar11 = (uint *)portMemAllocNonPaged(0x24);
  if (puVar11 == (uint *)0x0) {
    iVar7 = 0x51;
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x302);
  }
  else {
    uVar14 = (**(code **)(param_2 + 0x290))(param_1,param_2,0xffffffff);
    cVar6 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar3);
    if (cVar6 == '\0') {
      gpumgrGetGpuAttachInfo(0,local_40);
    }
    else {
      local_40[0] = 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
    }
    bVar4 = false;
LAB_002e6b71:
    while (lVar12 = gpumgrGetNextGpu(local_40[0],local_40 + 1), lVar12 != 0) {
      iVar7 = knvlinkGetNumLinksToPeer_IMPL(param_1,lVar3,lVar12);
      if (iVar7 != 0) {
        if (uVar14 == 0) {
          uVar14 = (**(code **)(param_2 + 0x290))(param_1,param_2,0);
        }
        iVar7 = 0;
        for (uVar8 = uVar14; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x80000000) {
          iVar7 = iVar7 + 1;
        }
        iVar15 = -1;
        if (uVar14 - 1 < 0xfffffffe) {
          iVar15 = iVar7;
        }
        uVar8 = 1 << ((byte)iVar15 & 0x1f);
        uVar14 = uVar14 & ~uVar8;
        uVar9 = knvlinkGetLinkMaskToPeer_IMPL(param_1,lVar3,lVar12);
        if (uVar9 != 0) {
          portMemSet(puVar11,0,0x24);
          *puVar11 = uVar9;
          iVar7 = knvlinkExecGspRmRpc_IMPL(param_1,lVar3,0x20800a8a,puVar11,0x24);
          if (iVar7 == 0) {
            uVar13 = 0xffffffff;
            puVar16 = puVar11 + 1;
            uVar18 = 0;
            do {
              if ((uVar9 & 1) != 0) {
                local_45 = (byte)*puVar16;
                if (local_45 != (byte)uVar13) {
                  uVar2 = *(uint *)(param_3 + (ulong)local_45 * 4);
                  local_46 = 1;
                  uVar10 = uVar2 - 1;
                  local_44 = 0;
                  for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
                    local_44 = local_44 + 1;
                  }
                  if (0xfffffffd < uVar10) {
                    local_44 = -1;
                  }
                }
                _ceGetAlgorithmPceIndex_isra_0(param_1,param_3,&local_44,&local_46,&local_45);
                uVar13 = (ulong)local_45;
                uVar10 = 1 << ((byte)local_44 & 0x1f);
                uVar18 = uVar18 | uVar10;
                puVar1 = (uint *)(param_3 + uVar13 * 4);
                *puVar1 = *puVar1 & ~uVar10;
                if (uVar9 >> 1 == 0) goto code_r0x002e6cce;
              }
              uVar9 = uVar9 >> 1;
              puVar16 = (uint *)((long)puVar16 + 1);
            } while( true );
          }
          nvAssertOkFailedNoLog
                    (iVar7,
                     "knvlinkExecGspRmRpc(pGpu, pKernelNvlink, NV2080_CTRL_CMD_INTERNAL_HSHUB_GET_HSHUB_ID_FOR_LINKS, pParams, sizeof(*pParams))"
                     ,"src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x344);
          goto LAB_002e6daf;
        }
        nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x33a,
                     "kceMapPceLceForNvlinkPeers_GA100",1,
                     "NVRM: GPU%d has nvlink disabled. Skip programming\n",
                     *(undefined4 *)(lVar12 + 0x7a4));
      }
    }
    iVar7 = 0x10006;
    if (bVar4) {
LAB_002e6dac:
      iVar7 = 0;
    }
LAB_002e6daf:
    portMemFree(puVar11);
  }
  return iVar7;
code_r0x002e6cce:
  lVar17 = 0;
  do {
    if ((uVar18 & 1) != 0) {
      *(int *)(param_4 + lVar17 * 4) = iVar15;
      nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x366,
                   "kceMapPceLceForNvlinkPeers_GA100",1,
                   "NVRM: GPU%d <-> GPU%d PCE Index: %d LCE Index: %d\n",
                   *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(lVar12 + 0x7a4),lVar17,iVar15);
      local_44 = (int)lVar17 + 1;
      if (uVar18 >> 1 == 0) break;
    }
    uVar18 = uVar18 >> 1;
    lVar17 = lVar17 + 1;
  } while( true );
  *param_5 = *param_5 | uVar8;
  if (*(char *)(lVar5 + 0x6b) != '\0') goto LAB_002e6dac;
  bVar4 = true;
  goto LAB_002e6b71;
}


// ===== 002e6e40 kceMapAsyncLceDefault_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceMapAsyncLceDefault_GA100
          (long param_1,long param_2,uint *param_3,long param_4,uint *param_5,int param_6)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  
  uVar5 = (**(code **)(param_2 + 0x290))(param_1,param_2,0xffffffff);
  uVar3 = uVar5 - 1;
  iVar6 = 0;
  for (; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
    iVar6 = iVar6 + 1;
  }
  iVar4 = -1;
  if (uVar3 < 0xfffffffe) {
    iVar4 = iVar6;
  }
  if (param_6 == 0) {
LAB_002e6f50:
    *param_5 = *param_5 | 1 << ((byte)iVar4 & 0x1f);
    return 0;
  }
  iVar6 = 0;
  uVar3 = 0;
  uVar5 = *param_3;
  do {
    bVar2 = 0;
    for (uVar1 = uVar5; (uVar1 & 1) == 0; uVar1 = uVar1 >> 1 | 0x80000000) {
      bVar2 = bVar2 + 1;
    }
    if (0xfffffffd < uVar5 - 1) {
      bVar2 = 0xff;
    }
    iVar6 = iVar6 + 1;
    uVar1 = 1 << (bVar2 & 0x1f);
    uVar3 = uVar3 | uVar1;
    uVar5 = uVar5 & ~uVar1;
  } while (iVar6 != param_6);
  *param_3 = uVar5;
  lVar7 = 0;
  do {
    if ((uVar3 & 1) != 0) {
      *(int *)(param_4 + lVar7 * 4) = iVar4;
      nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x3be,
                   "kceMapAsyncLceDefault_GA100",1,
                   "NVRM: GPU%d <-> GPU%d PCE Index: %d LCE Index: %d\n",
                   *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_1 + 0x7a4),lVar7,iVar4);
      if (uVar3 >> 1 == 0) goto LAB_002e6f50;
    }
    uVar3 = uVar3 >> 1;
    lVar7 = lVar7 + 1;
  } while( true );
}


// ===== 002e6f70 kceGetNvlinkPeerSupportedLceMask_GA100 =====

undefined8 kceGetNvlinkPeerSupportedLceMask_GA100(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x150;
  if (param_3 != -1) {
    uVar1 = 0x2a0;
  }
  return uVar1;
}


// ===== 002e6f90 kceGetGrceSupportedLceMask_GA100 =====

undefined8 kceGetGrceSupportedLceMask_GA100(void)

{
  return 3;
}


// ===== 002e6fa0 kceIsGenXorHigherSupported_GA100 =====

ulong kceIsGenXorHigherSupported_GA100(ulong param_1,undefined8 param_2,uint param_3)

{
  ulong uVar1;
  byte extraout_var;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  byte local_19;
  
  local_19 = 0;
  if ((*(char *)(param_1 + 0x4912) == '\0') ||
     (*(char *)(*(long *)(param_1 + 7000) + 0x3ad) == '\0')) {
    iVar2 = clPcieGetRootGenSpeed_IMPL(param_1,*(undefined8 *)(g_pSys + 0x208),&local_19);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x431,
                   "kceIsGenXorHigherSupported_GA100",4,
                   "NVRM: Could not get root gen speed - check for GPU gen speed!\n");
      regRead032(param_1 + 0x3a18,0,0,0x88088,0);
      local_19 = extraout_var & 0xf;
    }
    nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x436,
                 "kceIsGenXorHigherSupported_GA100",1,"NVRM: Gen Speed = %d\n",local_19);
    param_1 = CONCAT71((int7)(param_1 >> 8),param_3 <= local_19);
  }
  else {
    uVar1 = *(ulong *)(param_1 + 0x878);
    uVar4 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,0,0);
    uVar3 = osPciReadDword(uVar4,0xe8);
    uVar3 = uVar3 & 0xf;
    if (((uVar3 != 0) || (param_1 = 1, 4 < param_3)) &&
       (param_1 = CONCAT71((int7)(param_1 >> 8),param_3 <= uVar3), uVar3 != 0)) {
      nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x429,
                   "kceIsGenXorHigherSupported_GA100",1,
                   "NVRM: Root port speed from emulated config space = %d\n",uVar3);
    }
  }
  return param_1 & 0xffffffff;
}


// ===== 002e7110 kceApplyGen4orHigherMapping_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceApplyGen4orHigherMapping_GA100
               (long param_1,undefined8 param_2,long param_3,uint *param_4,int param_5,ulong param_6
               )

{
  uint *puVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  uint local_2c [3];
  
  if (param_5 != 3) {
    return;
  }
  portMemSet(local_2c,0,4);
  iVar5 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a8b,local_2c,4);
  if (iVar5 == 0) {
    if (local_2c[0] != 0) {
      puVar1 = param_4 + local_2c[0];
      do {
        uVar2 = *param_4;
        if (uVar2 != 0) {
          uVar6 = 0;
          for (uVar4 = uVar2; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1 | 0x80000000) {
            uVar6 = uVar6 + 1;
          }
          if (uVar2 == 0xffffffff) {
            uVar6 = 0xffffffff;
          }
          lVar7 = 0x3fffffffc;
          if (uVar2 != 0xffffffff) {
            lVar7 = (ulong)uVar6 << 2;
          }
          bVar3 = (byte)uVar6 & 0x1f;
          *(undefined4 *)(param_3 + lVar7) = 3;
          *param_4 = *param_4 & (-2 << bVar3 | 0xfffffffeU >> 0x20 - bVar3);
          *(undefined4 *)(param_3 + (param_6 & 0xffffffff) * 4) = 0xf;
          return;
        }
        param_4 = param_4 + 1;
      } while (puVar1 != param_4);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_HSHUB_GET_NUM_UNITS, &params, sizeof(params))"
               ,"src/kernel/gpu/ce/arch/ampere/kernel_ce_ga100.c",0x460);
  }
  return;
}


// ===== 002e7210 kceGetPce2lceConfigSize1_GA102 =====

undefined8 kceGetPce2lceConfigSize1_GA102(void)

{
  return 6;
}


// ===== 002e7220 kceMapPceLceForSysmemLinks_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kceMapPceLceForSysmemLinks_GA102
              (long param_1,long param_2,undefined8 param_3,long param_4,uint *param_5,uint param_6)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  char *pcVar9;
  int local_3c [3];
  
  lVar1 = *(long *)(param_1 + 0x1ce8);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelNvlink != NULL","src/kernel/gpu/ce/arch/ampere/kernel_ce_ga102.c",
                        0x5f);
    return 0x56;
  }
  portMemSet(local_3c,0,4);
  iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,lVar1,0x20800aab,local_3c,4);
  if (iVar4 == 0) {
    uVar5 = (**(code **)(param_2 + 0x280))(param_1,param_2);
    if (local_3c[0] == 0) {
      *param_5 = *param_5 | uVar5;
      if (param_6 == 0) {
        return 0;
      }
      uVar6 = uVar5 - 1;
      iVar4 = 0;
      for (uVar7 = uVar5; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x80000000) {
        iVar4 = iVar4 + 1;
      }
      if (0xfffffffd < uVar6) {
        iVar4 = -1;
      }
      if (param_6 != 0xffffffff) goto LAB_002e7300;
      uVar5 = uVar5 & uVar6;
      uVar6 = uVar5 - 1;
      *(int *)(param_4 + 0x3fffffffc) = iVar4;
      uVar7 = 0xfffffffe;
      param_6 = 0xfffffffe;
      if (0xfffffffd < uVar6) goto LAB_002e7318;
      do {
        iVar4 = 0;
        for (uVar7 = uVar5; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x80000000) {
          iVar4 = iVar4 + 1;
        }
LAB_002e7300:
        uVar7 = 0;
        for (uVar2 = param_6; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
          uVar7 = uVar7 + 1;
        }
        *(int *)(param_4 + (ulong)uVar7 * 4) = iVar4;
        uVar7 = param_6 & param_6 - 1;
        while( true ) {
          if (uVar7 == 0) {
            return 0;
          }
          uVar5 = uVar5 & uVar6;
          uVar6 = uVar5 - 1;
          param_6 = uVar7;
          if (uVar6 < 0xfffffffe) break;
LAB_002e7318:
          uVar2 = 0;
          for (uVar3 = uVar7; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x80000000) {
            uVar2 = uVar2 + 1;
          }
          *(undefined4 *)(param_4 + (ulong)uVar2 * 4) = 0xffffffff;
          uVar7 = uVar7 & uVar7 - 1;
        }
      } while( true );
    }
    pcVar9 = "NVRM: Sysmem over NVLink is not POR!\n";
    uVar8 = 0x84;
  }
  else {
    pcVar9 = "NVRM: Unable to determine PCEs and LCEs for sysmem links\n";
    uVar8 = 0x67;
  }
  nvDbg_Printf("src/kernel/gpu/ce/arch/ampere/kernel_ce_ga102.c",uVar8,
               "kceMapPceLceForSysmemLinks_GA102",4,pcVar9);
  return iVar4;
}


// ===== 002e73f0 kceGetSysmemSupportedLceMask_GA102 =====

undefined8 kceGetSysmemSupportedLceMask_GA102(void)

{
  return 0xc;
}


// ===== 002e7400 kceGetNvlinkPeerSupportedLceMask_GA102 =====

undefined8 kceGetNvlinkPeerSupportedLceMask_GA102(void)

{
  return 0x10;
}


// ===== 002e7410 kceGetGrceSupportedLceMask_GA102 =====

undefined8 kceGetGrceSupportedLceMask_GA102(void)

{
  return 3;
}


// ===== 002e7420 kceGetPce2lceConfigSize1_GB100 =====

undefined8 kceGetPce2lceConfigSize1_GB100(void)

{
  return 0x18;
}


// ===== 002e7430 kceGetGrceConfigSize1_GB100 =====

char kceGetGrceConfigSize1_GB100(long param_1)

{
  return (*(int *)(param_1 + 700) == 0) * '\x02';
}


// ===== 002e7450 kceSetShimInstance_GB100 =====

void kceSetShimInstance_GB100(undefined8 param_1,long param_2)

{
  *(uint *)(param_2 + 700) = *(uint *)(param_2 + 0x2b8) / 10;
  return;
}


// ===== 002e7480 kceGetNvlinkAutoConfigCeValues_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kceGetNvlinkAutoConfigCeValues_GB100
          (long param_1,long param_2,long param_3,long param_4,undefined4 *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  long lVar9;
  undefined4 local_3c [3];
  
  lVar4 = *(long *)(param_1 + 0x1ce8);
  uVar1 = (**(code **)(param_2 + 0x220))(param_2);
  uVar2 = (**(code **)(param_2 + 0x218))(param_2);
  if (*(int *)(param_1 + 0x8fc) == 0) {
    nvAssertFailedNoLog("gpuGetNumCEs(pGpu) != 0",
                        "src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x80);
    return 0x56;
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pPceLceMap != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",
                        0x82);
    return 0x1f;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("pGrceConfig != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",
                        0x83);
    return 0x1f;
  }
  if (param_5 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pExposedLceMask != NULL",
                        "src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x84);
    return 0x1f;
  }
  if ((lVar4 == 0) && (*(char *)(param_1 + 0x49a) != '\0')) {
    nvAssertFailedNoLog("!(pKernelNvlink == NULL && pGpu->getProperty(pGpu, PDB_PROP_GPU_SKIP_CE_MAPPINGS_NO_NVLINK))"
                        ,"src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x86);
    return 0x56;
  }
  lVar4 = portMemAllocNonPaged(0x134);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pCurrentTopo != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",
                        0x8a);
    return 0x51;
  }
  portMemSet(lVar4,0,0x134);
  puVar5 = (undefined4 *)portMemAllocNonPaged(0x80);
  puVar6 = (undefined8 *)portMemAllocNonPaged(0x10);
  local_3c[0] = 0;
  if (puVar5 == (undefined4 *)0x0) {
    nvAssertOkFailedNoLog
              (0x51,"pLocalPceLceMap != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",
               0x92);
  }
  else {
    puVar7 = puVar5;
    if (puVar6 != (undefined8 *)0x0) {
      do {
        *puVar7 = 0xf;
        puVar8 = puVar7 + 2;
        puVar7[1] = 0xf;
        puVar7 = puVar8;
      } while (puVar8 != puVar5 + 0x20);
      *puVar6 = 0xf0000000f;
      puVar6[1] = 0xf0000000f;
      uVar3 = (**(code **)(param_2 + 0x228))(param_1,param_2,lVar4,puVar5,puVar6,local_3c);
      *param_5 = local_3c[0];
      if (uVar1 != 0) {
        lVar9 = 0;
        do {
          *(undefined4 *)(param_3 + lVar9) = *(undefined4 *)((long)puVar5 + lVar9);
          lVar9 = lVar9 + 4;
        } while (lVar9 != (ulong)uVar1 << 2);
      }
      lVar9 = 0;
      if (uVar2 != 0) {
        do {
          *(undefined4 *)(param_4 + lVar9) = *(undefined4 *)((long)puVar6 + lVar9);
          lVar9 = lVar9 + 4;
        } while ((ulong)uVar2 << 2 != lVar9);
      }
      goto LAB_002e7651;
    }
    nvAssertOkFailedNoLog
              (0x51,"pLocalGrceConfig != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",
               0x93);
  }
  uVar3 = 0x51;
LAB_002e7651:
  portMemFree(lVar4);
  portMemFree(puVar5);
  portMemFree(puVar6);
  return uVar3;
}


// ===== 002e7790 kceSetDecompCeCap_GB100 =====

void kceSetDecompCeCap_GB100(undefined8 param_1,long param_2)

{
  if (param_2 != 0) {
    *(uint *)(param_2 + 0x2e4) = *(uint *)(param_2 + 0x2e4) | 0x40;
  }
  return;
}


// ===== 002e77a1 kceGetMappingsForMIGGpuInstance_GB100.cold =====

void kceGetMappingsForMIGGpuInstance_GB100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e77b0 kceGetMappingsForMIGGpuInstance_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceGetMappingsForMIGGpuInstance_GB100(long param_1,long param_2,ulong param_3,long param_4)

{
  long lVar1;
  byte bVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  uint local_74;
  uint local_60;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c [3];
  
  uVar13 = (**(code **)(param_2 + 0x268))();
  local_50 = 0;
  local_4c = 0;
  lVar6 = portMemAllocNonPaged(0x134);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pTopoParams != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",
                        0xf3);
    return 0x51;
  }
  uVar4 = (uint)param_3 - ((uint)((param_3 & 0xffffffff) >> 1) & 0x55555555);
  uVar4 = (uVar4 >> 2 & 0x33333333) + (uVar4 & 0x33333333);
  uVar12 = ((uVar4 >> 4) + uVar4 & 0xf0f0f0f) * 0x1010101 >> 0x18;
  portMemSet(lVar6,0,0x134);
  local_74 = 0xffffff;
  uVar4 = *(uint *)(param_1 + 0x8fc);
  if (uVar4 != 0) {
    uVar10 = 0;
    do {
      while (((uVar10 < 0x14 && (lVar1 = *(long *)(param_1 + 0x1c30 + uVar10 * 8), lVar1 != 0)) &&
             (*(char *)(lVar1 + 0x2d4) != '\0'))) {
        kceGetAvailableHubPceMask_IMPL(param_1,lVar1,lVar6);
        uVar8 = 0;
        puVar7 = (uint *)(lVar6 + 0x18);
        if (((int)(uint *)(lVar6 + 0x98) - (int)puVar7 & 4U) == 0) goto LAB_002e7900;
        uVar8 = *(uint *)(lVar6 + 0x18);
        for (puVar7 = (uint *)(lVar6 + 0x1c); (uint *)(lVar6 + 0x98) != puVar7; puVar7 = puVar7 + 2)
        {
LAB_002e7900:
          uVar8 = uVar8 | *puVar7 | puVar7[1];
        }
        uVar10 = uVar10 + 1;
        local_74 = local_74 & uVar8;
        if (uVar4 == uVar10) goto LAB_002e7928;
      }
      uVar10 = uVar10 + 1;
    } while (uVar4 != uVar10);
  }
LAB_002e7928:
  uVar13 = (uint)param_3 & uVar13;
  kceGetPceConfigForLceMIGGpuInstance_IMPL
            (param_1,param_2,uVar13 & 0x55555554,uVar12,&local_50,&local_48,&local_44,local_3c);
  kceGetPceConfigForLceMIGGpuInstance_IMPL
            (param_1,param_2,uVar13 & 0xaaaaaaa8,uVar12,&local_4c,&local_48,&local_40,local_3c);
  local_50 = local_50 & local_74;
  if (local_44 != 0) {
    local_60 = 0;
    uVar4 = 0;
    uVar13 = local_44;
    while( true ) {
      for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
        uVar4 = uVar4 + 1;
      }
      if (local_48 >> 1 <= local_60) break;
      if (local_3c[0] != 0) {
        if ((local_50 & 0x55555555) != 0) {
          uVar10 = (ulong)(local_50 & 0x55555555);
          uVar12 = 0;
LAB_002e7a00:
          do {
            uVar8 = 0;
            uVar5 = (uint)uVar10;
            for (uVar9 = uVar5; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
              uVar8 = uVar8 + 1;
            }
            uVar11 = (ulong)uVar8;
            do {
              uVar8 = (**(code **)(param_2 + 0x220))(param_2);
              if ((uint)uVar11 <= uVar8) {
                uVar12 = uVar12 + 1;
                uVar8 = ~(1 << ((byte)uVar11 & 0x1f));
                *(uint *)(param_4 + uVar11 * 4) = uVar4 % 10;
                local_50 = local_50 & uVar8;
                if (local_3c[0] <= uVar12) goto joined_r0x002e7a8c;
                uVar5 = uVar5 & uVar8;
                uVar10 = (ulong)uVar5;
                if (uVar5 == 0) {
                  uVar10 = (ulong)(local_50 & 0xaaaaaaaa);
                  if ((local_50 & 0xaaaaaaaa) == 0) goto joined_r0x002e7a8c;
                  goto LAB_002e7a00;
                }
                break;
              }
              uVar12 = uVar12 + 1;
              if (local_3c[0] <= uVar12) goto joined_r0x002e7a8c;
              uVar11 = uVar10;
            } while (uVar5 == 0xffffffff);
          } while( true );
        }
        uVar10 = (ulong)(local_50 & 0xaaaaaaaa);
        uVar12 = 0;
        if ((local_50 & 0xaaaaaaaa) != 0) goto LAB_002e7a00;
      }
joined_r0x002e7a8c:
      uVar13 = uVar13 >> 1;
      if (uVar13 == 0) break;
      local_60 = local_60 + 1;
      uVar4 = uVar4 + 1;
    }
  }
  local_4c = local_4c & local_74;
  if (local_40 != 0) {
    local_74 = 0;
    uVar10 = 0;
    uVar13 = local_40;
    while( true ) {
      for (; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1) {
        uVar10 = uVar10 + 1;
      }
      if (local_48 >> 1 <= local_74) break;
      if (local_3c[0] != 0) {
        uVar4 = 0;
        uVar12 = local_4c & 0x55555555;
        if (uVar12 != 0) {
          uVar8 = 0;
LAB_002e7b1f:
          do {
            uVar9 = 0;
            for (uVar5 = uVar12; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
              uVar9 = uVar9 + 1;
            }
            do {
              uVar5 = (**(code **)(param_2 + 0x220))(param_2);
              if (uVar9 <= uVar5) {
                bVar2 = (byte)uVar9 & 0x1f;
                uVar5 = -2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2;
                local_4c = local_4c & uVar5;
                *(int *)(param_4 + (ulong)uVar9 * 4) =
                     (int)uVar10 + (int)((uVar10 & 0xffffffff) / 10) * -10;
                uVar4 = uVar4 + 1;
                if ((local_3c[0] >> 1 <= uVar4) || (uVar8 = uVar8 + 1, local_3c[0] <= uVar8))
                goto LAB_002e7bb0;
                uVar12 = uVar12 & uVar5;
                if (uVar12 == 0) {
                  uVar12 = local_4c & 0xaaaaaaaa;
                  if (uVar12 == 0) goto LAB_002e7bb0;
                  goto LAB_002e7b1f;
                }
                break;
              }
              uVar8 = uVar8 + 1;
              if (local_3c[0] <= uVar8) goto LAB_002e7bb0;
              uVar9 = uVar12;
            } while (uVar12 == 0xffffffff);
          } while( true );
        }
        uVar12 = local_4c & 0xaaaaaaaa;
        uVar8 = 0;
        if (uVar12 != 0) goto LAB_002e7b1f;
      }
LAB_002e7bb0:
      if (0x13 < uVar10) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      (**(code **)(*(long *)(param_1 + 0x1c30 + uVar10 * 8) + 0x1a8))();
      uVar13 = uVar13 >> 1;
      if (uVar13 == 0) break;
      local_74 = local_74 + 1;
      uVar10 = uVar10 + 1;
    }
  }
  portMemFree(lVar6);
  return 0;
}


// ===== 002e7c89 kceMapPceLceForWorkSubmitLces_GB100.cold =====

void kceMapPceLceForWorkSubmitLces_GB100_cold(void)

{
  code *pcVar1;
  
  nvAssertFailedNoLog("pKCeLce != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",500);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e7cb0 kceMapPceLceForWorkSubmitLces_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceMapPceLceForWorkSubmitLces_GB100(long param_1,undefined8 param_2,uint *param_3,uint *param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  ulong uVar14;
  ulong uVar15;
  uint local_80;
  int local_7c;
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  uint local_44;
  uint local_40;
  undefined1 local_3c [12];
  
  cVar5 = gpuIsCCFeatureEnabled_IMPL();
  if (cVar5 != '\0') {
    kceGetPceConfigForLceType_IMPL
              (param_1,param_2,10,local_4c,local_48,&local_44,&local_40,local_3c);
    uVar6 = local_40 >> 1;
    if (uVar6 == 0) {
      local_80 = 1;
    }
    else {
      iVar2 = 0x1f;
      if (uVar6 != 0) {
        for (; uVar6 >> iVar2 == 0; iVar2 = iVar2 + -1) {
        }
      }
      local_80 = iVar2 + 2;
    }
    uVar6 = *(uint *)(param_1 + 0x8fc);
    if (uVar6 != 0) {
      uVar14 = 0;
      uVar11 = 0;
      do {
        while ((((0x13 < uVar14 || (lVar1 = *(long *)(param_1 + 0x1c30 + uVar14 * 8), lVar1 == 0))
                || (*(char *)(lVar1 + 0x2d4) == '\0')) ||
               (uVar12 = *(uint *)(lVar1 + 0x2c8), uVar12 == 0))) {
LAB_002e7d80:
          uVar14 = uVar14 + 1;
          uVar12 = uVar11;
          if (uVar6 == uVar14) goto LAB_002e7e20;
        }
        uVar9 = 0;
        for (uVar7 = uVar12; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x80000000) {
          uVar9 = uVar9 + 1;
        }
        lVar8 = (ulong)uVar9 << 2;
        if (uVar12 == 0xffffffff) {
          lVar8 = 0x3fffffffc;
        }
        uVar12 = *(uint *)((long)param_3 + lVar8) & local_44;
        if (0xfffffffd < uVar12 - 1) {
          (**(code **)(lVar1 + 0x220))(lVar1);
          goto LAB_002e7d80;
        }
        uVar9 = 0;
        for (; (uVar12 & 1) == 0; uVar12 = uVar12 >> 1 | 0x80000000) {
          uVar9 = uVar9 + 1;
        }
        uVar12 = (**(code **)(lVar1 + 0x220))(lVar1);
        if (uVar12 <= uVar9) goto LAB_002e7d80;
        uVar12 = *(uint *)(lVar1 + 700);
        if (*(uint *)(lVar1 + 700) <= uVar11) {
          uVar12 = uVar11;
        }
        uVar14 = uVar14 + 1;
        uVar11 = uVar12;
      } while (uVar6 != uVar14);
LAB_002e7e20:
      uVar6 = *(uint *)(param_1 + 0x8fc);
      if (uVar6 != 0) {
        uVar14 = 0;
        do {
          if (((uVar14 < 0x14) && (lVar1 = *(long *)(param_1 + 0x1c30 + uVar14 * 8), lVar1 != 0)) &&
             ((*(char *)(lVar1 + 0x2d4) != '\0' &&
              ((*(uint *)(lVar1 + 700) != 0 && (*(uint *)(lVar1 + 700) == uVar12)))))) {
            local_7c = 2;
            uVar10 = (ulong)uVar12;
            while( true ) {
              uVar9 = (**(code **)(lVar1 + 0x268))(param_1,lVar1,uVar10);
              uVar7 = ~*param_4 & local_40 & uVar9;
              uVar11 = uVar7 & 0xaaaaaaa0;
              if (((uVar7 & 0xaaaaaaa0) == 0) &&
                 (uVar9 = uVar7 - 1, uVar11 = uVar7, 0xfffffffd < uVar9)) break;
              uVar10 = (ulong)uVar9;
              uVar9 = 0;
              for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1 | 0x80000000) {
                uVar9 = uVar9 + 1;
              }
              if (local_80 <= uVar9) break;
              uVar11 = *(uint *)(lVar1 + 0x2c8);
              puVar13 = param_3;
              if (uVar11 != 0) {
                do {
                  if ((uVar11 & 1) != 0) {
                    if (*puVar13 != 0) {
                      uVar7 = *puVar13 & local_44;
                      if (uVar7 - 1 < 0xfffffffe) {
                        uVar4 = 0;
                        for (; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x80000000) {
                          uVar4 = uVar4 + 1;
                        }
                        uVar15 = 0x2e7f70;
                        uVar7 = (**(code **)(lVar1 + 0x220))(lVar1);
                        uVar10 = extraout_RDX_00;
                        if (uVar4 < uVar7) {
                          *puVar13 = *puVar13 & ~(1 << ((byte)uVar4 & 0x1f));
                          *(uint *)(*(long *)(lVar1 + 0x2c0) + (ulong)uVar4 * 4) = uVar9 % 10;
                          *param_4 = *param_4 | 1 << ((byte)uVar9 & 0x1f);
                          if ((0x13 < (int)uVar9) ||
                             (lVar8 = *(long *)(param_1 + 0x1c30 + (ulong)uVar9 * 8), lVar8 == 0)) {
                            nvAssertFailedNoLog("pKCeLce != NULL",
                                                "src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c"
                                                ,500);
                    /* WARNING: Does not return */
                            pcVar3 = (code *)invalidInstructionException();
                            (*pcVar3)();
                          }
                          puVar13 = (uint *)(lVar8 + 0x2e4);
                          *puVar13 = *puVar13 | 0x80;
                          uVar10 = uVar15;
                          nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x1f7,
                                       "kceMapPceLceForWorkSubmitLces_GB100",1,
                                       "NVRM: Work submit CE Mapping -- PCE Index: %d -> LCE Index: %d\n"
                                       ,uVar4,uVar9);
                          break;
                        }
                      }
                      else {
                        (**(code **)(lVar1 + 0x220))(lVar1);
                        uVar10 = extraout_RDX;
                      }
                    }
                    if (uVar11 >> 1 == 0) break;
                  }
                  uVar11 = uVar11 >> 1;
                  puVar13 = puVar13 + 1;
                } while( true );
              }
              if (local_7c == 1) break;
              local_7c = 1;
            }
          }
          uVar14 = uVar14 + 1;
        } while (uVar6 != uVar14);
      }
      return 0;
    }
  }
  return 0;
}


// ===== 002e8050 __pfx_kceMapPceLceForDecomp_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __pfx_kceMapPceLceForDecomp_GB100(long param_1,undefined8 param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  ulong extraout_RDX;
  ulong uVar10;
  ulong extraout_RDX_00;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  ulong uVar14;
  ulong uVar15;
  uint uStack_60;
  uint uStack_4c;
  undefined1 auStack_48 [4];
  uint uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [12];
  
  kceGetPceConfigForLceType_IMPL
            (param_1,param_2,2,&uStack_4c,auStack_48,&uStack_44,&uStack_40,auStack_3c);
  uVar6 = uStack_40 >> 1;
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  else {
    iVar5 = 0x1f;
    if (uVar6 != 0) {
      for (; uVar6 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    uVar6 = iVar5 + 2;
  }
  uVar2 = *(uint *)(param_1 + 0x8fc);
  if (uVar2 == 0) {
    return;
  }
  uVar9 = 0;
  uVar10 = extraout_RDX;
LAB_002e8111:
  do {
    if (((uVar9 < 0x14) && (lVar3 = *(long *)(param_1 + 0x1c30 + uVar9 * 8), lVar3 != 0)) &&
       (*(char *)(lVar3 + 0x2d4) != '\0')) {
      uVar7 = (**(code **)(lVar3 + 0x268))(param_1,lVar3,uVar10);
      uVar7 = ~*param_4 & uStack_40 & uVar7;
      uVar11 = uVar7 & 0xaaaaaaa0;
      if (((uVar7 & 0xaaaaaaa0) == 0) && (uVar11 = uVar7, 0xfffffffd < uVar7 - 1)) {
        return;
      }
      uVar7 = 0;
      for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1 | 0x80000000) {
        uVar7 = uVar7 + 1;
      }
      uVar10 = (ulong)uVar7;
      if (uVar6 <= uVar7) {
        return;
      }
      uVar11 = *(uint *)(lVar3 + 0x2c8);
      if (uVar11 != 0) {
        uStack_60 = 0;
        uVar10 = (ulong)(uVar7 % 10);
        puVar13 = param_3;
        do {
          if ((uVar11 & 1) != 0) {
            if (uStack_4c <= uStack_60) goto LAB_002e82e8;
            uVar12 = *puVar13 & uStack_44;
            if (uVar12 != 0) {
              uVar14 = 0;
              do {
                if ((uVar12 & 1) != 0) {
                  uVar15 = 0x2e8233;
                  uVar8 = (**(code **)(lVar3 + 0x220))(lVar3);
                  uVar10 = extraout_RDX_00;
                  if ((uint)uVar14 < uVar8) {
                    uStack_60 = uStack_60 + 1;
                    *(uint *)(*(long *)(lVar3 + 0x2c0) + uVar14 * 4) = uVar7 % 10;
                    *param_4 = *param_4 | 1 << ((byte)uVar7 & 0x1f);
                    *puVar13 = *puVar13 & ~(1 << ((byte)uVar14 & 0x1f));
                    if (((int)uVar7 < 0x14) &&
                       (lVar4 = *(long *)(param_1 + 0x1c30 + (ulong)uVar7 * 8), lVar4 != 0)) {
                      puVar1 = (uint *)(lVar4 + 0x2e4);
                      *puVar1 = *puVar1 | 0x40;
                    }
                    uVar10 = uVar15;
                    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x267,
                                 "kceMapPceLceForDecomp_GB100",1,
                                 "NVRM: Decomp CE Mapping -- PCE Index: %d -> LCE Index: %d\n",
                                 uVar14 & 0xffffffff,uVar7);
                  }
                  if (uVar12 >> 1 == 0) break;
                }
                uVar12 = uVar12 >> 1;
                uVar14 = uVar14 + 1;
              } while( true );
            }
            if (uVar11 >> 1 == 0) goto LAB_002e82e8;
          }
          uVar11 = uVar11 >> 1;
          puVar13 = puVar13 + 1;
        } while( true );
      }
    }
    uVar9 = uVar9 + 1;
    if (uVar9 == uVar2) {
      return;
    }
  } while( true );
LAB_002e82e8:
  uVar9 = uVar9 + 1;
  if (uVar9 == uVar2) {
    return;
  }
  goto LAB_002e8111;
}


// ===== 002e8060 kceMapPceLceForDecomp_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceMapPceLceForDecomp_GB100(long param_1,undefined8 param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  ulong extraout_RDX;
  ulong uVar10;
  ulong extraout_RDX_00;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  ulong uVar14;
  ulong uVar15;
  uint local_60;
  uint local_4c;
  undefined1 local_48 [4];
  uint local_44;
  uint local_40;
  undefined1 local_3c [12];
  
  kceGetPceConfigForLceType_IMPL(param_1,param_2,2,&local_4c,local_48,&local_44,&local_40,local_3c);
  uVar6 = local_40 >> 1;
  if (uVar6 == 0) {
    uVar6 = 1;
  }
  else {
    iVar5 = 0x1f;
    if (uVar6 != 0) {
      for (; uVar6 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    uVar6 = iVar5 + 2;
  }
  uVar2 = *(uint *)(param_1 + 0x8fc);
  if (uVar2 == 0) {
    return;
  }
  uVar9 = 0;
  uVar10 = extraout_RDX;
LAB_002e8111:
  do {
    if (((uVar9 < 0x14) && (lVar3 = *(long *)(param_1 + 0x1c30 + uVar9 * 8), lVar3 != 0)) &&
       (*(char *)(lVar3 + 0x2d4) != '\0')) {
      uVar7 = (**(code **)(lVar3 + 0x268))(param_1,lVar3,uVar10);
      uVar7 = ~*param_4 & local_40 & uVar7;
      uVar11 = uVar7 & 0xaaaaaaa0;
      if (((uVar7 & 0xaaaaaaa0) == 0) && (uVar11 = uVar7, 0xfffffffd < uVar7 - 1)) {
        return;
      }
      uVar7 = 0;
      for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1 | 0x80000000) {
        uVar7 = uVar7 + 1;
      }
      uVar10 = (ulong)uVar7;
      if (uVar6 <= uVar7) {
        return;
      }
      uVar11 = *(uint *)(lVar3 + 0x2c8);
      if (uVar11 != 0) {
        local_60 = 0;
        uVar10 = (ulong)(uVar7 % 10);
        puVar13 = param_3;
        do {
          if ((uVar11 & 1) != 0) {
            if (local_4c <= local_60) goto LAB_002e82e8;
            uVar12 = *puVar13 & local_44;
            if (uVar12 != 0) {
              uVar14 = 0;
              do {
                if ((uVar12 & 1) != 0) {
                  uVar15 = 0x2e8233;
                  uVar8 = (**(code **)(lVar3 + 0x220))(lVar3);
                  uVar10 = extraout_RDX_00;
                  if ((uint)uVar14 < uVar8) {
                    local_60 = local_60 + 1;
                    *(uint *)(*(long *)(lVar3 + 0x2c0) + uVar14 * 4) = uVar7 % 10;
                    *param_4 = *param_4 | 1 << ((byte)uVar7 & 0x1f);
                    *puVar13 = *puVar13 & ~(1 << ((byte)uVar14 & 0x1f));
                    if (((int)uVar7 < 0x14) &&
                       (lVar4 = *(long *)(param_1 + 0x1c30 + (ulong)uVar7 * 8), lVar4 != 0)) {
                      puVar1 = (uint *)(lVar4 + 0x2e4);
                      *puVar1 = *puVar1 | 0x40;
                    }
                    uVar10 = uVar15;
                    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x267,
                                 "kceMapPceLceForDecomp_GB100",1,
                                 "NVRM: Decomp CE Mapping -- PCE Index: %d -> LCE Index: %d\n",
                                 uVar14 & 0xffffffff,uVar7);
                  }
                  if (uVar12 >> 1 == 0) break;
                }
                uVar12 = uVar12 >> 1;
                uVar14 = uVar14 + 1;
              } while( true );
            }
            if (uVar11 >> 1 == 0) goto LAB_002e82e8;
          }
          uVar11 = uVar11 >> 1;
          puVar13 = puVar13 + 1;
        } while( true );
      }
    }
    uVar9 = uVar9 + 1;
    if (uVar9 == uVar2) {
      return;
    }
  } while( true );
LAB_002e82e8:
  uVar9 = uVar9 + 1;
  if (uVar9 == uVar2) {
    return;
  }
  goto LAB_002e8111;
}


// ===== 002e8320 kceMapPceLceForNvlinkPeers_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kceMapPceLceForNvlinkPeers_GB100
               (long param_1,long param_2,long param_3,undefined8 param_4,uint *param_5)

{
  uint *puVar1;
  undefined8 uVar2;
  long lVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  byte local_c0;
  uint local_b0;
  uint local_ac;
  byte local_a4;
  uint local_94;
  undefined4 local_7c;
  int local_78;
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  uint local_68;
  undefined1 local_64 [4];
  int local_60;
  undefined4 local_5c;
  byte local_58 [40];
  
  uVar2 = *(undefined8 *)(param_1 + 0x1ce8);
  local_7c = 0;
  (**(code **)(param_2 + 0x220))(param_2);
  kceGetPceConfigForLceType_IMPL(param_1,param_2,4,local_74,local_70,local_6c,&local_68,local_64);
  local_68 = local_68 >> 1;
  if (local_68 == 0) {
    local_b0 = 1;
  }
  else {
    iVar7 = 0x1f;
    if (local_68 != 0) {
      for (; local_68 >> iVar7 == 0; iVar7 = iVar7 + -1) {
      }
    }
    local_b0 = iVar7 + 2;
  }
  uVar9 = (**(code **)(param_2 + 0x290))(param_1,param_2,0xffffffff);
  uVar6 = kceGetLceMask_IMPL(param_1);
  uVar8 = *param_5;
  *(undefined4 *)(param_2 + 0x2dc) = 0;
  local_94 = ~uVar8 & uVar6 & uVar9;
  cVar5 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,uVar2);
  if (cVar5 == '\0') {
    gpumgrGetGpuAttachInfo(0,&local_78);
  }
  else {
    local_78 = 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
  }
  bVar4 = false;
LAB_002e8458:
  do {
    lVar10 = gpumgrGetNextGpu(local_78,&local_7c);
    if (lVar10 == 0) {
      return -(uint)!bVar4 & 0x10006;
    }
    iVar7 = knvlinkGetNumLinksToPeer_IMPL(param_1,uVar2,lVar10);
  } while (iVar7 == 0);
  if (local_94 == 0) {
    uVar8 = (**(code **)(param_2 + 0x290))(param_1,param_2,0);
    uVar9 = kceGetLceMask_IMPL(param_1);
    local_94 = ~*param_5 & uVar9 & uVar8;
  }
  if (local_94 - 1 < 0xfffffffe) {
    uVar8 = 0;
    for (uVar9 = local_94; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
      uVar8 = uVar8 + 1;
    }
    if (uVar8 < local_b0) {
      *(int *)(param_2 + 0x2dc) = *(int *)(param_2 + 0x2dc) + 1;
      uVar11 = knvlinkGetLinkMaskToPeer_IMPL(param_1,uVar2,lVar10);
      if (uVar11 != 0) {
        portMemSet(&local_5c,0,0x24);
        local_5c = (undefined4)uVar11;
        uVar9 = knvlinkExecGspRmRpc_IMPL(param_1,uVar2,0x20800a8a,&local_5c,0x24);
        if (uVar9 != 0) {
          nvAssertOkFailedNoLog
                    (uVar9,"status","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x346);
          return uVar9;
        }
        pbVar14 = local_58;
        local_ac = 0;
        do {
          if ((uVar11 & 1) != 0) {
            uVar9 = (uint)*pbVar14;
            uVar6 = *(uint *)(param_3 + (ulong)*pbVar14 * 4);
            if (uVar6 - 1 < 0xfffffffe) {
              uVar12 = 0;
              for (uVar13 = uVar6; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1 | 0x80000000) {
                uVar12 = uVar12 + 1;
              }
              if ((~*(uint *)(param_2 + 0x2d0) & uVar6 & 1 << ((byte)uVar12 & 0x1f)) == 0)
              goto LAB_002e85fb;
LAB_002e858c:
              uVar6 = (**(code **)(param_2 + 0x220))(param_2);
              if (uVar12 < uVar6) {
                uVar6 = 1 << ((byte)uVar12 & 0x1f);
                local_ac = local_ac | uVar6;
                puVar1 = (uint *)(param_3 + (ulong)uVar9 * 4);
                *puVar1 = *puVar1 & ~uVar6;
              }
            }
            else {
LAB_002e85fb:
              portMemSet(&local_60,0,4);
              iVar7 = (**(code **)(param_1 + 0x3b90))
                                (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                                 *(undefined4 *)(param_1 + 0x3b3c),0x20800a79,&local_60,4);
              if (iVar7 != 0) {
                nvAssertOkFailedNoLog
                          (iVar7,
                           "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_HSHUB_GET_MAX_HSHUBS_PER_SHIM, &maxHshubParams, sizeof(maxHshubParams))"
                           ,"src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x29b);
              }
              uVar9 = local_60 - 1;
              cVar5 = gpuIsCCFeatureEnabled_IMPL(param_1);
              uVar6 = *(uint *)(param_3 + (ulong)uVar9 * 4);
              if (cVar5 == '\0') {
                uVar13 = uVar6 - 1;
                uVar12 = 0;
                for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
                  uVar12 = uVar12 + 1;
                }
                if (0xfffffffd < uVar13) goto LAB_002e8679;
LAB_002e879b:
                uVar6 = (**(code **)(param_2 + 0x220))(param_2);
                if (uVar12 <= uVar6) goto LAB_002e858c;
              }
              else {
                uVar6 = ~*(uint *)(param_2 + 0x2d0) & uVar6;
                if (uVar6 - 1 < 0xfffffffe) {
                  uVar12 = 0;
                  for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
                    uVar12 = uVar12 + 1;
                  }
                  goto LAB_002e879b;
                }
LAB_002e8679:
                iVar7 = (**(code **)(param_2 + 0x220))(param_2);
                if (iVar7 == -1) {
                  (**(code **)(param_2 + 0x220))(param_2);
                  if (uVar11 >> 1 != 0) goto LAB_002e85d1;
                  goto LAB_002e86b0;
                }
              }
              nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x2b7,
                           "_ceGetAlgorithmPceIndex",1,"NVRM: No more available PCEs to assign!\n");
            }
            if (uVar11 >> 1 == 0) goto LAB_002e86b0;
          }
LAB_002e85d1:
          uVar11 = uVar11 >> 1;
          pbVar14 = pbVar14 + 1;
        } while( true );
      }
      nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x335,
                   "kceMapPceLceForNvlinkPeers_GB100",1,
                   "NVRM: GPU%d has nvlink disabled. Skip LCE-PCE mapping.\n",
                   *(undefined4 *)(lVar10 + 0x7a4));
      goto LAB_002e8458;
    }
  }
  else {
    uVar8 = 0xffffffff;
  }
  nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x329,
               "kceMapPceLceForNvlinkPeers_GB100",4,
               "NVRM: Invalid LCE Index Request. lceIndex = %d, maxLceCount = %d\n",uVar8,local_b0);
  return 0;
LAB_002e86b0:
  uVar11 = uVar11 >> 1;
  uVar9 = 0;
  if (local_ac == 0) goto LAB_002e8458;
  local_a4 = (byte)uVar8;
  uVar6 = 1 << (local_a4 & 0x1f);
  local_94 = local_94 & ~uVar6;
  uVar6 = uVar6 | *param_5;
  *param_5 = uVar6;
  if (local_94 - 1 < 0xfffffffe) {
    uVar12 = 0;
    for (uVar13 = local_94; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1 | 0x80000000) {
      uVar12 = uVar12 + 1;
    }
    if (*(char *)(param_2 + 0x2e2) != '\0') {
      if (local_b0 <= uVar12) goto LAB_002e8713;
      local_c0 = (byte)uVar12;
      uVar13 = 1 << (local_c0 & 0x1f);
      *param_5 = uVar6 | uVar13;
      local_94 = local_94 & ~uVar13;
    }
  }
  else {
    if (*(char *)(param_2 + 0x2e2) != '\0') {
      uVar12 = 0xffffffff;
LAB_002e8713:
      nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x396,
                   "kceMapPceLceForNvlinkPeers_GB100",4,
                   "NVRM: Invalid Second LCE Index Request. lceIndex = %d, maxLceCount = %d\n",
                   uVar12,local_b0);
      return 0;
    }
    local_94 = 0;
    uVar12 = 0xffffffff;
  }
  uVar6 = local_ac - (local_ac >> 1 & 0x55555555);
  uVar6 = (uVar6 & 0x33333333) + (uVar6 >> 2 & 0x33333333);
  while( true ) {
    for (; (local_ac & 1) == 0; local_ac = local_ac >> 1) {
      uVar11 = uVar11 + 1;
    }
    if ((*(char *)(param_2 + 0x2e2) == '\0') ||
       (uVar13 = uVar12, uVar9 <= ((uVar6 >> 4) + uVar6 & 0xf0f0f0f) * 0x1010101 >> 0x19)) {
      uVar13 = uVar8;
    }
    *(uint *)(*(long *)(param_2 + 0x2c0) + uVar11 * 4) = uVar13 % 10;
    if ((uVar13 < 0x14) && (lVar3 = *(long *)(param_1 + 0x1c30 + (ulong)uVar13 * 8), lVar3 != 0)) {
      *(uint *)(lVar3 + 0x2e4) = *(uint *)(lVar3 + 0x2e4) | 8;
      *(uint *)(lVar3 + 0x2d8) =
           *(uint *)(lVar3 + 0x2d8) | 1 << ((byte)*(undefined4 *)(lVar10 + 0x7a4) & 0x1f);
    }
    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x3b1,
                 "kceMapPceLceForNvlinkPeers_GB100",1,
                 "NVRM: Nvlink peer CE Mapping for GPU%d <-> GPU%d -- PCE Index: %d -> LCE Index: %d\n"
                 ,*(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(lVar10 + 0x7a4),
                 uVar11 & 0xffffffff,(ulong)uVar13);
    local_ac = local_ac >> 1;
    if (local_ac == 0) break;
    uVar11 = uVar11 + 1;
    uVar9 = uVar9 + 1;
  }
  bVar4 = true;
  goto LAB_002e8458;
}


// ===== 002e8a70 kceMapPceLceForGRCE_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceMapPceLceForGRCE_GB100
               (long param_1,undefined8 param_2,long param_3,undefined8 param_4,uint *param_5,
               uint *param_6)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint *puVar8;
  ulong uVar9;
  ulong uVar10;
  
  uVar1 = *(uint *)(param_1 + 0x8fc);
  if (uVar1 == 0) {
    return;
  }
  uVar6 = 0;
  uVar10 = 0;
  do {
    if ((((uVar10 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar10 * 8), lVar2 != 0)) &&
        (*(char *)(lVar2 + 0x2d4) != '\0')) && (*(int *)(lVar2 + 700) == 0)) {
      uVar5 = 0;
      for (uVar4 = *(uint *)(lVar2 + 0x2c8); (uVar4 & 1) == 0; uVar4 = uVar4 >> 1 | 0x80000000) {
        uVar5 = uVar5 + 1;
      }
      lVar7 = (ulong)uVar5 << 2;
      if (0xfffffffd < *(uint *)(lVar2 + 0x2c8) - 1) {
        lVar7 = 0x3fffffffc;
      }
      puVar8 = (uint *)(lVar7 + param_3);
      if ((*puVar8 & ~*(uint *)(lVar2 + 0x2d0)) == 0) {
        uVar5 = (**(code **)(lVar2 + 0x220))(lVar2);
        if (uVar5 != 0) {
          uVar9 = 0;
          do {
            if ((*(uint *)(lVar2 + 0x2d0) >> ((uint)uVar9 & 0x1f) & 1) == 0) {
              uVar4 = *(uint *)(*(long *)(lVar2 + 0x2c0) + uVar9 * 4);
              if (uVar4 != 0xf) {
                if ((uVar4 < 0x14) &&
                   (lVar2 = *(long *)(param_1 + 0x1c30 + (ulong)uVar4 * 8), lVar2 != 0)) {
                  puVar8 = (uint *)(lVar2 + 0x2e4);
                  *puVar8 = *puVar8 | 1;
                }
                nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x410,
                             "kceMapPceLceForGRCE_GB100",1,
                             "NVRM: GRCE is shared and mapped to LCE Index: %d.\n");
                *param_6 = uVar4 & 0xf | 0x40000000;
                uVar6 = uVar4;
                goto LAB_002e8b70;
              }
            }
            uVar9 = uVar9 + 1;
          } while (uVar5 != uVar9);
        }
        *param_6 = uVar6 & 0xf | 0x40000000;
      }
      else {
        *param_5 = *param_5 | 1;
        uVar6 = ~*(uint *)(lVar2 + 0x2d0) & *puVar8;
        if (0xfffffffd < uVar6 - 1) {
          nvAssertFailedNoLog("pceIndex < NV2080_CTRL_MAX_PCES",
                              "src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x3f3);
          return;
        }
        uVar5 = 0;
        for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
          uVar5 = uVar5 + 1;
        }
        uVar6 = (**(code **)(lVar2 + 0x220))(lVar2);
        if (uVar5 < uVar6) {
          *(undefined4 *)(*(long *)(lVar2 + 0x2c0) + (ulong)uVar5 * 4) = 0;
          bVar3 = (byte)uVar5 & 0x1f;
          *puVar8 = *puVar8 & (-2 << bVar3 | 0xfffffffeU >> 0x20 - bVar3);
          *param_6 = 0xf;
          nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x3fc,
                       "kceMapPceLceForGRCE_GB100",1,
                       "NVRM: GRCE is not shared and mapped to LCE Index: 0.\n");
        }
        uVar6 = 0;
      }
    }
LAB_002e8b70:
    uVar10 = uVar10 + 1;
    if (uVar1 == uVar10) {
      return;
    }
  } while( true );
}


// ===== 002e8cce kceMapPceLceForPCIe_GB100.cold =====

void kceMapPceLceForPCIe_GB100_cold(void)

{
  code *pcVar1;
  
  nvAssertFailedNoLog("pKCeLce != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x4bb);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e8cf0 kceMapPceLceForPCIe_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceMapPceLceForPCIe_GB100(long param_1,undefined8 param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  long lVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  uint uVar15;
  uint *puVar16;
  long local_90;
  uint local_60;
  uint local_5c;
  undefined1 local_58 [4];
  uint local_54;
  uint local_50;
  undefined1 local_4c [4];
  undefined8 local_48;
  undefined8 local_40 [2];
  
  puVar16 = &local_50;
  kceGetPceConfigForLceType_IMPL(param_1,param_2,1,&local_60,&local_5c,&local_54,puVar16,local_4c);
  uVar9 = local_50 >> 1;
  if (uVar9 == 0) {
    uVar9 = 1;
  }
  else {
    iVar4 = 0x1f;
    if (uVar9 != 0) {
      for (; uVar9 >> iVar4 == 0; iVar4 = iVar4 + -1) {
      }
    }
    uVar9 = iVar4 + 2;
  }
  if (local_5c == 1) {
    local_48 = CONCAT44(local_48._4_4_,1);
    local_40[0] = CONCAT44(local_40[0]._4_4_,6);
  }
  else {
    if (local_5c != 2) {
      nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x45f,
                   "kceMapPceLceForPCIe_GB100",4,"NVRM: Invalid number of LCEs for PCIe.!\n",puVar16
                  );
      return;
    }
    local_48 = 0x700000006;
    local_40[0] = 0x400000002;
  }
  uVar2 = *(uint *)(param_1 + 0x8fc);
  if (uVar2 == 0) {
    return;
  }
  uVar14 = 0;
  uVar12 = 0;
  do {
    if ((((uVar14 < 0x14) && (lVar3 = *(long *)(param_1 + 0x1c30 + uVar14 * 8), lVar3 != 0)) &&
        (*(char *)(lVar3 + 0x2d4) != '\0')) && (uVar15 = *(uint *)(lVar3 + 0x2c8), uVar15 != 0)) {
      uVar6 = 0;
      for (uVar13 = uVar15; (uVar13 & 1) == 0; uVar13 = uVar13 >> 1 | 0x80000000) {
        uVar6 = uVar6 + 1;
      }
      lVar10 = (ulong)uVar6 << 2;
      if (uVar15 == 0xffffffff) {
        lVar10 = 0x3fffffffc;
      }
      uVar15 = *(uint *)((long)param_3 + lVar10) & local_54;
      if (uVar15 - 1 < 0xfffffffe) {
        uVar6 = 0;
        for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1 | 0x80000000) {
          uVar6 = uVar6 + 1;
        }
        uVar15 = (**(code **)(lVar3 + 0x220))(lVar3);
        if ((uVar6 < uVar15) && (uVar12 < *(uint *)(lVar3 + 700))) {
          uVar12 = *(uint *)(lVar3 + 700);
        }
      }
      else {
        (**(code **)(lVar3 + 0x220))(lVar3);
      }
    }
    uVar14 = uVar14 + 1;
  } while (uVar14 != uVar2);
  uVar2 = *(uint *)(param_1 + 0x8fc);
  if (uVar2 != 0) {
    uVar14 = 0;
    do {
      if (((uVar14 < 0x14) && (lVar3 = *(long *)(param_1 + 0x1c30 + uVar14 * 8), lVar3 != 0)) &&
         ((*(char *)(lVar3 + 0x2d4) != '\0' &&
          ((*(uint *)(lVar3 + 700) == uVar12 && (local_5c != 0)))))) {
        local_90 = 0;
LAB_002e8f50:
        kceGetPceConfigForLceType_IMPL
                  (param_1,param_2,*(undefined4 *)((long)local_40 + local_90 * 4 + -8),&local_60,
                   local_58,&local_54,&local_50,local_4c);
        uVar15 = (**(code **)(lVar3 + 0x268))(param_1,lVar3);
        uVar15 = ~*param_4 & local_50 & uVar15;
        if (uVar15 - 1 < 0xfffffffe) {
          uVar6 = 0;
          for (; (uVar15 & 1) == 0; uVar15 = uVar15 >> 1 | 0x80000000) {
            uVar6 = uVar6 + 1;
          }
          if (uVar6 < uVar9) {
            uVar15 = 0;
LAB_002e9000:
            if ((uVar15 < local_60) && (uVar13 = *(uint *)(lVar3 + 0x2c8), uVar13 != 0)) {
              bVar8 = false;
              puVar16 = param_3;
              do {
                if ((uVar13 & 1) != 0) {
                  if (local_60 <= uVar15) goto LAB_002e9140;
                  if (*puVar16 != 0) {
                    uVar11 = *puVar16 & local_54;
                    if (uVar11 - 1 < 0xfffffffe) {
                      uVar7 = 0;
                      for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1 | 0x80000000) {
                        uVar7 = uVar7 + 1;
                      }
                      uVar11 = (**(code **)(lVar3 + 0x220))(lVar3);
                      if (uVar7 < uVar11) {
                        *puVar16 = *puVar16 & ~(1 << ((byte)uVar7 & 0x1f));
                        *(uint *)(*(long *)(lVar3 + 0x2c0) + (ulong)uVar7 * 4) = uVar6 % 10;
                        *param_4 = *param_4 | 1 << ((byte)uVar6 & 0x1f);
                        if ((0x13 < (int)uVar6) ||
                           (lVar10 = *(long *)(param_1 + 0x1c30 + (ulong)uVar6 * 8), lVar10 == 0)) {
                          nvAssertFailedNoLog("pKCeLce != NULL",
                                              "src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",
                                              0x4bb);
                    /* WARNING: Does not return */
                          pcVar5 = (code *)invalidInstructionException();
                          (*pcVar5)();
                        }
                        uVar15 = uVar15 + 1;
                        puVar1 = (uint *)(lVar10 + 0x2e4);
                        *puVar1 = *puVar1 | *(uint *)((long)local_40 + local_90 * 4);
                        nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x4be,
                                     "kceMapPceLceForPCIe_GB100",1,
                                     "NVRM: PCIe CE Mapping -- PCE Index: %d -> LCE Index: %d\n",
                                     (ulong)uVar7,uVar6);
                        bVar8 = true;
                        if (uVar13 >> 1 != 0) goto LAB_002e9064;
                        goto LAB_002e9140;
                      }
                    }
                    else {
                      (**(code **)(lVar3 + 0x220))(lVar3);
                    }
                  }
                  if (uVar13 >> 1 == 0) goto LAB_002e9140;
                }
LAB_002e9064:
                uVar13 = uVar13 >> 1;
                puVar16 = puVar16 + 1;
              } while( true );
            }
            goto LAB_002e9150;
          }
        }
      }
LAB_002e8ecf:
      uVar14 = uVar14 + 1;
    } while (uVar14 != uVar2);
  }
  return;
LAB_002e9140:
  if (!bVar8) goto LAB_002e9150;
  goto LAB_002e9000;
LAB_002e9150:
  local_90 = local_90 + 1;
  if (local_5c <= (uint)local_90) goto LAB_002e8ecf;
  goto LAB_002e8f50;
}


// ===== 002e91a0 kceMapPceLceForC2C_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined4
kceMapPceLceForC2C_GB100
          (long param_1,undefined8 param_2,uint *param_3,undefined8 param_4,uint *param_5)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  ulong uVar14;
  uint local_a8;
  uint local_a4;
  uint local_88;
  int local_60;
  int local_5c;
  undefined1 local_58 [4];
  uint local_54;
  uint local_50;
  uint local_4c;
  undefined8 local_48;
  uint local_40 [4];
  
  puVar12 = &local_4c;
  kceGetPceConfigForLceType_IMPL(param_1,param_2,5,&local_60,&local_5c,&local_54,&local_50);
  uVar5 = local_50 >> 1;
  if (uVar5 == 0) {
    local_a8 = 1;
  }
  else {
    iVar10 = 0x1f;
    if (uVar5 != 0) {
      for (; uVar5 >> iVar10 == 0; iVar10 = iVar10 + -1) {
      }
    }
    local_a8 = iVar10 + 2;
  }
  if (local_5c == 1) {
    local_48 = CONCAT44(local_48._4_4_,5);
    local_40[0] = 6;
  }
  else {
    if (local_5c != 2) {
      nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x515,
                   "kceMapPceLceForC2C_GB100",4,"NVRM: Invalid number of LCEs for C2C.!\n",puVar12);
      return 0x1a;
    }
    local_48 = 0x900000008;
    local_40[0] = 2;
    local_40[1] = 4;
  }
  uVar5 = *(uint *)(param_1 + 0x8fc);
  if (uVar5 != 0) {
    uVar11 = 0;
    uVar14 = 0;
LAB_002e928d:
    do {
      if ((((uVar14 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar14 * 8), lVar2 != 0)) &&
          (*(char *)(lVar2 + 0x2d4) != '\0')) && (uVar9 = *(uint *)(lVar2 + 0x2c8), uVar9 != 0)) {
        uVar8 = 0;
        for (uVar6 = uVar9; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
          uVar8 = uVar8 + 1;
        }
        lVar7 = (ulong)uVar8 << 2;
        if (uVar9 == 0xffffffff) {
          lVar7 = 0x3fffffffc;
        }
        uVar9 = *(uint *)((long)param_3 + lVar7) & local_54;
        if (uVar9 - 1 < 0xfffffffe) {
          uVar8 = 0;
          for (; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
            uVar8 = uVar8 + 1;
          }
          uVar9 = (**(code **)(lVar2 + 0x220))(lVar2);
          if (uVar8 < uVar9) {
            if (uVar11 < *(uint *)(lVar2 + 700)) {
              uVar11 = *(uint *)(lVar2 + 700);
            }
            uVar14 = uVar14 + 1;
            if (uVar14 == uVar5) break;
            goto LAB_002e928d;
          }
        }
        else {
          (**(code **)(lVar2 + 0x220))(lVar2);
        }
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 != uVar5);
    uVar5 = *(uint *)(param_1 + 0x8fc);
    if (uVar5 != 0) {
      local_a4 = 0;
      uVar14 = 0;
LAB_002e936d:
      do {
        if (((uVar14 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar14 * 8), lVar2 != 0)) &&
           ((*(char *)(lVar2 + 0x2d4) != '\0' &&
            ((*(uint *)(lVar2 + 700) == uVar11 && (local_5c != 0)))))) {
          uVar9 = local_5c + local_a4;
LAB_002e93c2:
          kceGetPceConfigForLceType_IMPL
                    (param_1,param_2,local_40[(ulong)local_a4 - 2],&local_60,local_58,&local_54,
                     &local_50,&local_4c);
          uVar6 = (**(code **)(lVar2 + 0x268))(param_1,lVar2);
          uVar6 = ~*param_5 & local_50 & uVar6;
          uVar8 = uVar6 & 0x55555550;
          if (((uVar6 & 0x55555550) != 0) || (uVar8 = uVar6, uVar6 - 1 < 0xfffffffe)) {
            uVar6 = 0;
            for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x80000000) {
              uVar6 = uVar6 + 1;
            }
            if (uVar6 < local_a8) {
              local_88 = *(uint *)(lVar2 + 0x2c8);
              if (local_88 != 0) {
                bVar4 = false;
                iVar10 = 0;
                puVar12 = param_3;
                do {
                  if ((local_88 & 1) != 0) {
                    uVar8 = *puVar12;
                    if (uVar8 != 0) {
                      if (local_60 == iVar10) goto LAB_002e9571;
                      if (local_4c != 0) {
                        uVar13 = 0;
                        while( true ) {
                          uVar8 = uVar8 & local_54;
                          if (0xfffffffd < uVar8 - 1) break;
                          uVar3 = 0;
                          for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x80000000) {
                            uVar3 = uVar3 + 1;
                          }
                          uVar8 = (**(code **)(lVar2 + 0x220))(lVar2);
                          if (uVar8 <= uVar3) goto LAB_002e9528;
                          iVar10 = iVar10 + 1;
                          *puVar12 = *puVar12 & ~(1 << ((byte)uVar3 & 0x1f));
                          *(uint *)(*(long *)(lVar2 + 0x2c0) + (ulong)uVar3 * 4) = uVar6 % 10;
                          *param_5 = *param_5 | 1 << ((byte)uVar6 & 0x1f);
                          if (((int)uVar6 < 0x14) &&
                             (lVar7 = *(long *)(param_1 + 0x1c30 + (ulong)uVar6 * 8), lVar7 != 0)) {
                            puVar1 = (uint *)(lVar7 + 0x2e4);
                            *puVar1 = *puVar1 | local_40[local_a4];
                          }
                          nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x577,
                                       "kceMapPceLceForC2C_GB100",1,
                                       "NVRM: C2C CE Mapping -- PCE Index: %d -> LCE Index: %d\n",
                                       (ulong)uVar3,uVar6);
                          if ((local_60 == iVar10) || (uVar13 = uVar13 + 1, local_4c <= uVar13)) {
                            bVar4 = true;
                            goto LAB_002e9528;
                          }
                          bVar4 = true;
                          uVar8 = *puVar12;
                        }
                        (**(code **)(lVar2 + 0x220))(lVar2);
                        if (local_88 >> 1 != 0) goto LAB_002e9530;
                        goto LAB_002e9571;
                      }
                    }
LAB_002e9528:
                    if (local_88 >> 1 == 0) goto LAB_002e9571;
                  }
LAB_002e9530:
                  local_88 = local_88 >> 1;
                  puVar12 = puVar12 + 1;
                } while( true );
              }
              goto LAB_002e96a2;
            }
          }
          goto LAB_002e944e;
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 != uVar5);
    }
  }
  return 0;
LAB_002e9571:
  if (!bVar4) {
LAB_002e96a2:
    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x58b,
                 "kceMapPceLceForC2C_GB100",4,
                 "NVRM: Unable to assign the required number of LCEs for C2C.\n");
    return 0x1a;
  }
  local_a4 = local_a4 + 1;
  if (local_a4 == uVar9) goto LAB_002e944e;
  goto LAB_002e93c2;
LAB_002e944e:
  uVar14 = uVar14 + 1;
  if (uVar14 == uVar5) {
    return 0;
  }
  goto LAB_002e936d;
}


// ===== 002e96f0 kceMapPceLceForScrub_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kceMapPceLceForScrub_GB100(long param_1,undefined8 param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  ulong uVar12;
  uint local_a4;
  uint local_70;
  undefined4 local_6c;
  undefined1 local_4c [4];
  undefined1 local_48 [4];
  uint local_44;
  uint local_40;
  uint local_3c [3];
  
  kceGetPceConfigForLceType_IMPL(param_1,param_2,3,local_4c,local_48,&local_44,&local_40,local_3c);
  uVar5 = local_40 >> 1;
  if (uVar5 == 0) {
    uVar5 = *(uint *)(param_1 + 0x8fc);
    local_a4 = 1;
  }
  else {
    iVar3 = 0x1f;
    if (uVar5 != 0) {
      for (; uVar5 >> iVar3 == 0; iVar3 = iVar3 + -1) {
      }
    }
    uVar5 = *(uint *)(param_1 + 0x8fc);
    local_a4 = iVar3 + 2;
  }
  if (uVar5 != 0) {
    uVar12 = 0;
    local_70 = 0;
    do {
      while ((((0x13 < uVar12 || (lVar2 = *(long *)(param_1 + 0x1c30 + uVar12 * 8), lVar2 == 0)) ||
              (*(char *)(lVar2 + 0x2d4) == '\0')) || (uVar9 = *(uint *)(lVar2 + 0x2c8), uVar9 == 0))
            ) {
LAB_002e97a0:
        uVar12 = uVar12 + 1;
        if (uVar12 == uVar5) goto LAB_002e9840;
      }
      uVar6 = 0;
      for (uVar8 = uVar9; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x80000000) {
        uVar6 = uVar6 + 1;
      }
      lVar7 = (ulong)uVar6 << 2;
      if (uVar9 == 0xffffffff) {
        lVar7 = 0x3fffffffc;
      }
      uVar9 = *(uint *)((long)param_3 + lVar7) & local_44;
      if (0xfffffffd < uVar9 - 1) {
        (**(code **)(lVar2 + 0x220))();
        goto LAB_002e97a0;
      }
      uVar6 = 0;
      for (; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
        uVar6 = uVar6 + 1;
      }
      uVar9 = (**(code **)(lVar2 + 0x220))();
      if (uVar9 <= uVar6) goto LAB_002e97a0;
      uVar9 = *(uint *)(lVar2 + 700);
      if (*(uint *)(lVar2 + 700) <= local_70) {
        uVar9 = local_70;
      }
      uVar12 = uVar12 + 1;
      local_70 = uVar9;
    } while (uVar12 != uVar5);
LAB_002e9840:
    uVar5 = *(uint *)(param_1 + 0x8fc);
    if (uVar5 != 0) {
      local_6c = 0x10006;
      uVar12 = 0;
LAB_002e987d:
      do {
        if (((uVar12 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar12 * 8), lVar2 != 0)) &&
           ((*(char *)(lVar2 + 0x2d4) != '\0' && (*(uint *)(lVar2 + 700) == local_70)))) {
          uVar6 = (**(code **)(lVar2 + 0x268))(param_1,lVar2);
          uVar6 = ~*param_4 & local_40 & uVar6;
          uVar9 = uVar6 & 0x55555550;
          if (((uVar6 & 0x55555550) == 0) && (uVar9 = uVar6, 0xfffffffd < uVar6 - 1)) {
            return local_6c;
          }
          uVar6 = 0;
          for (; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
            uVar6 = uVar6 + 1;
          }
          if (local_a4 <= uVar6) {
            return local_6c;
          }
          uVar9 = *(uint *)(lVar2 + 0x2c8);
          if (uVar9 != 0) {
            puVar10 = param_3;
            do {
              if ((uVar9 & 1) != 0) {
                uVar8 = *puVar10;
                if ((uVar8 != 0) && (local_3c[0] != 0)) {
                  uVar11 = 0;
                  while( true ) {
                    uVar8 = uVar8 & local_44;
                    if (uVar8 - 1 < 0xfffffffe) {
                      uVar4 = 0;
                      for (; (uVar8 & 1) == 0; uVar8 = uVar8 >> 1 | 0x80000000) {
                        uVar4 = uVar4 + 1;
                      }
                      uVar8 = (**(code **)(lVar2 + 0x220))(lVar2);
                      if (uVar4 < uVar8) {
                        *puVar10 = *puVar10 & ~(1 << ((byte)uVar4 & 0x1f));
                        *(uint *)(*(long *)(lVar2 + 0x2c0) + (ulong)uVar4 * 4) = uVar6 % 10;
                        *param_4 = *param_4 | 1 << ((byte)uVar6 & 0x1f);
                        if (((int)uVar6 < 0x14) &&
                           (lVar7 = *(long *)(param_1 + 0x1c30 + (ulong)uVar6 * 8), lVar7 != 0)) {
                          puVar1 = (uint *)(lVar7 + 0x2e4);
                          *puVar1 = *puVar1 | 0x20;
                        }
                        nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x61a,
                                     "kceMapPceLceForScrub_GB100",1,
                                     "NVRM: Scrub CE Mapping -- PCE Index: %d -> LCE Index: %d\n",
                                     uVar4,uVar6);
                        local_6c = 0;
                      }
                    }
                    uVar11 = uVar11 + 1;
                    if (local_3c[0] <= uVar11) break;
                    uVar8 = *puVar10;
                  }
                }
                if (uVar9 >> 1 == 0) goto LAB_002e9a8b;
              }
              uVar9 = uVar9 >> 1;
              puVar10 = puVar10 + 1;
            } while( true );
          }
        }
        uVar12 = uVar12 + 1;
        if (uVar12 == uVar5) {
          return local_6c;
        }
      } while( true );
    }
  }
  return 0x10006;
LAB_002e9a8b:
  uVar12 = uVar12 + 1;
  if (uVar12 == uVar5) {
    return local_6c;
  }
  goto LAB_002e987d;
}


// ===== 002e9af2 kceMapAsyncLceDefault_GB100.cold =====

void kceMapAsyncLceDefault_GB100_cold(void)

{
  code *pcVar1;
  
  nvAssertFailedNoLog("pKCeLce != NULL","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x680);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002e9b20 kceMapAsyncLceDefault_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceMapAsyncLceDefault_GB100
          (long param_1,undefined8 param_2,uint *param_3,undefined8 param_4,uint *param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  ulong uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  uint local_34;
  uint local_30;
  undefined1 local_2c [4];
  
  if ((*param_5 & 0x10) != 0) {
    return 0;
  }
  puVar7 = &local_30;
  kceGetPceConfigForLceType_IMPL(param_1,param_2,3,local_3c,local_38,&local_34,puVar7,local_2c);
  local_30 = local_30 >> 1;
  if (local_30 == 0) {
    uVar11 = 1;
  }
  else {
    iVar3 = 0x1f;
    if (local_30 != 0) {
      for (; local_30 >> iVar3 == 0; iVar3 = iVar3 + -1) {
      }
    }
    uVar11 = iVar3 + 2;
  }
  uVar1 = *(uint *)(param_1 + 0x8fc);
  if (uVar1 != 0) {
    uVar8 = 0;
    do {
      if (((uVar8 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar8 * 8), lVar2 != 0)) &&
         (*(char *)(lVar2 + 0x2d4) != '\0')) {
        uVar6 = (**(code **)(lVar2 + 0x268))(param_1,lVar2,uVar8,puVar7);
        uVar6 = ~*param_5 & uVar6 & 0x55555550;
        puVar7 = (uint *)(ulong)(uVar6 - 1);
        if (0xfffffffd < uVar6 - 1) {
          return 0;
        }
        uVar5 = 0;
        for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
          uVar5 = uVar5 + 1;
        }
        if (uVar11 <= uVar5) {
          return 0;
        }
        uVar6 = *(uint *)(lVar2 + 0x2c8);
        if (uVar6 != 0) {
          puVar7 = (uint *)(ulong)local_34;
          puVar9 = param_3;
          do {
            if ((uVar6 & 1) != 0) {
              uVar10 = local_34 & *puVar9;
              if (uVar10 != 0) {
                uVar11 = 0;
                for (; (uVar10 & 1) == 0; uVar10 = uVar10 >> 1 | 0x80000000) {
                  uVar11 = uVar11 + 1;
                }
                uVar8 = (ulong)uVar11;
                *(uint *)(*(long *)(lVar2 + 0x2c0) + uVar8 * 4) = uVar5 % 10;
                *param_5 = *param_5 | 1 << ((byte)uVar5 & 0x1f);
                *puVar9 = *puVar9 & ~(1 << ((byte)uVar11 & 0x1f));
                if ((uVar5 < 0x14) &&
                   (lVar2 = *(long *)(param_1 + 0x1c30 + (ulong)uVar5 * 8), lVar2 != 0)) {
                  puVar7 = (uint *)(lVar2 + 0x2e4);
                  *puVar7 = *puVar7 | 0x20;
                  nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x683,
                               "kceMapAsyncLceDefault_GB100",1,
                               "NVRM: Async LCE Mapping -- PCE Index: %d -> LCE Index: %d\n",uVar8,
                               uVar5);
                  return 0;
                }
                nvAssertFailedNoLog("pKCeLce != NULL",
                                    "src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x680,uVar8
                                    ,uVar8,uVar8);
                    /* WARNING: Does not return */
                pcVar4 = (code *)invalidInstructionException();
                (*pcVar4)();
              }
              if (uVar6 >> 1 == 0) break;
            }
            uVar6 = uVar6 >> 1;
            puVar9 = puVar9 + 1;
          } while( true );
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar1 != uVar8);
  }
  return 0;
}


// ===== 002e9d00 kceGetMappings_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceGetMappings_GB100
          (long param_1,undefined8 param_2,long param_3,long param_4,undefined8 param_5,
          undefined4 *param_6)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  long local_c0;
  uint local_b8 [34];
  
  lVar1 = *(long *)(param_1 + 0x1ce8);
  cVar3 = *(char *)(*(long *)(param_1 + 7000) + 0x3a8);
  iVar4 = kceFindShimOwner_IMPL(param_1,param_2,&local_c0);
  if (((iVar4 == 0) && (local_c0 != 0)) && (*(long *)(local_c0 + 0x2c0) != 0)) {
    if ((*(int *)(local_c0 + 700) == 0) || (*(char *)(local_c0 + 0x2cc) == '\0')) {
      puVar7 = local_b8;
      do {
        *puVar7 = 0;
        puVar8 = puVar7 + 2;
        puVar7[1] = 0;
        puVar7 = puVar8;
      } while (puVar8 != local_b8 + 0x20);
      uVar6 = *(uint *)(param_1 + 0x8fc);
      if (uVar6 != 0) {
        uVar11 = 0;
        do {
          while (((uVar11 < 0x14 && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar11 * 8), lVar2 != 0))
                 && (*(char *)(lVar2 + 0x2d4) != '\0'))) {
            kceGetAvailableHubPceMask_IMPL(param_1,lVar2,param_3);
            lVar9 = 0;
            do {
              uVar5 = *(uint *)(param_3 + 0x18 + lVar9 * 4);
              puVar7 = local_b8 + lVar9;
              *puVar7 = *puVar7 | uVar5;
              if (uVar5 != 0) {
                *(uint *)(lVar2 + 0x2c8) = *(uint *)(lVar2 + 0x2c8) | 1 << ((byte)lVar9 & 0x1f);
              }
              lVar9 = lVar9 + 1;
            } while (lVar9 != 0x20);
            if (*(long *)(lVar2 + 0x2c0) == 0) {
              return 0;
            }
            uVar10 = 0;
            while( true ) {
              uVar5 = (**(code **)(lVar2 + 0x220))(lVar2);
              if (uVar5 <= (uint)uVar10) break;
              *(undefined4 *)(*(long *)(lVar2 + 0x2c0) + uVar10 * 4) = 0xf;
              uVar10 = (ulong)((uint)uVar10 + 1);
            }
            *(undefined1 *)(lVar2 + 0x2cc) = 1;
            uVar11 = uVar11 + 1;
            if (uVar6 == uVar11) goto LAB_002e9f40;
          }
          uVar11 = uVar11 + 1;
        } while (uVar6 != uVar11);
LAB_002e9f40:
        uVar6 = *(uint *)(param_1 + 0x8fc);
        uVar11 = 0;
        if (uVar6 != 0) {
          do {
            if ((uVar11 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar11 * 8), lVar2 != 0)) {
              *(undefined4 *)(lVar2 + 0x2e4) = 0;
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 != uVar6);
        }
      }
      if ((*(char *)(param_1 + 0x4915) == '\0') || (cVar3 == '\0')) {
        (**(code **)(local_c0 + 600))(param_1,local_c0,local_b8,param_6);
      }
      else {
        (**(code **)(local_c0 + 0x238))(param_1,local_c0,local_b8,param_4,param_6);
      }
      (**(code **)(local_c0 + 0x250))(param_1,local_c0,local_b8,param_6);
      if ((lVar1 != 0) && (cVar3 = knvlinkIsForcedConfig_IMPL(param_1), cVar3 == '\0')) {
        (**(code **)(local_c0 + 0x278))(param_1,local_c0,local_b8,param_4,param_6);
      }
      (**(code **)(local_c0 + 0x248))(param_1,local_c0,local_b8,param_6);
      (**(code **)(local_c0 + 0x240))(param_1,local_c0,local_b8,param_6);
      cVar3 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if (cVar3 == '\0') {
        (**(code **)(local_c0 + 0x260))
                  (param_1,local_c0,local_b8,param_4,param_6,param_5,*(undefined4 *)(param_3 + 0x98)
                  );
      }
      (**(code **)(local_c0 + 0x288))(param_1,local_c0,local_b8,param_4,param_6,0);
      nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x75a,"kceGetMappings_GB100"
                   ,1,"NVRM: Assigned LCE mask = 0x%x.\n",*param_6);
    }
    uVar11 = 0;
    while( true ) {
      uVar6 = (**(code **)(local_c0 + 0x220))();
      if (uVar6 <= (uint)uVar11) break;
      *(undefined4 *)(param_4 + uVar11 * 4) =
           *(undefined4 *)(*(long *)(local_c0 + 0x2c0) + uVar11 * 4);
      uVar11 = (ulong)((uint)uVar11 + 1);
    }
  }
  return 0;
}


// ===== 002ea1a0 kceGetSysmemRWLCEs_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceGetSysmemRWLCEs_GB100
               (long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar1 = *(uint *)(param_1 + 0x8fc);
  if (uVar1 == 0) {
    return;
  }
  uVar7 = 0;
  do {
    while ((((0x13 < uVar7 || (lVar3 = *(long *)(param_1 + 0x1c30 + uVar7 * 8), lVar3 == 0)) ||
            (*(char *)(lVar3 + 0x2d4) == '\0')) || (uVar2 = *(uint *)(param_1 + 0x8fc), uVar2 == 0))
          ) {
      uVar7 = uVar7 + 1;
      if (uVar7 == uVar1) {
        return;
      }
    }
    uVar6 = 0;
    do {
      if (((uVar6 < 0x14) && (lVar4 = *(long *)(param_1 + 0x1c30 + uVar6 * 8), lVar4 != 0)) &&
         (*(int *)(lVar4 + 700) == *(int *)(lVar3 + 700))) {
        cVar5 = (**(code **)(lVar4 + 0x1b0))(param_1,lVar4);
        if (cVar5 != '\0') {
          nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x782,
                       "kceGetSysmemRWLCEs_GB100",1,"NVRM: LCE %d assigned for Sysmem Rd.\n",
                       *(undefined4 *)(lVar4 + 0x2b8));
          *param_3 = *(undefined4 *)(lVar4 + 0x2b8);
        }
        cVar5 = (**(code **)(lVar4 + 0x1b8))(param_1,lVar4);
        if (cVar5 != '\0') {
          nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x788,
                       "kceGetSysmemRWLCEs_GB100",1,"NVRM: LCE %d assigned for Sysmem Wr.\n",
                       *(undefined4 *)(lVar4 + 0x2b8));
          *param_4 = *(undefined4 *)(lVar4 + 0x2b8);
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 != uVar2);
    uVar7 = uVar7 + 1;
  } while (uVar7 != uVar1);
  return;
}


// ===== 002ea340 kceGetLceMaskForShimInstance_GB100 =====

uint kceGetLceMaskForShimInstance_GB100(undefined8 param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = (char)*(undefined4 *)(param_2 + 700);
  uVar2 = kceGetLceMask_IMPL();
  return uVar2 & (1 << ((cVar1 * '\x05' + '\x05') * '\x02' & 0x1fU)) - (1 << (cVar1 * '\n' & 0x1fU))
  ;
}


// ===== 002ea380 kceIsCeSysmemRead_GB100 =====

bool kceIsCeSysmemRead_GB100(undefined8 param_1,long param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(byte *)(param_2 + 0x2e4) & 2) != 0) {
    bVar1 = *(char *)(param_2 + 0x2d5) == '\0';
  }
  return bVar1;
}


// ===== 002ea3a0 kceIsCeSysmemWrite_GB100 =====

bool kceIsCeSysmemWrite_GB100(undefined8 param_1,long param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(byte *)(param_2 + 0x2e4) & 4) != 0) {
    bVar1 = *(char *)(param_2 + 0x2d5) == '\0';
  }
  return bVar1;
}


// ===== 002ea3c0 kceIsCeNvlinkP2P_GB100 =====

bool kceIsCeNvlinkP2P_GB100(undefined8 param_1,long param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(byte *)(param_2 + 0x2e4) & 8) != 0) {
    bVar1 = *(char *)(param_2 + 0x2d5) == '\0';
  }
  return bVar1;
}


// ===== 002ea3e0 kceIsCCWorkSubmitLce_GB100 =====

bool kceIsCCWorkSubmitLce_GB100(undefined8 param_1,long param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(byte *)(param_2 + 0x2e4) & 0x80) != 0) {
    bVar1 = *(char *)(param_2 + 0x2d5) == '\0';
  }
  return bVar1;
}


// ===== 002ea400 kceIsScrubLce_GB100 =====

bool kceIsScrubLce_GB100(undefined8 param_1,long param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((*(byte *)(param_2 + 0x2e4) & 0x20) != 0) {
    bVar1 = *(char *)(param_2 + 0x2d5) == '\0';
  }
  return bVar1;
}


// ===== 002ea420 kceAssignCeCaps_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceAssignCeCaps_GB100(long param_1,long param_2,byte *param_3)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_1 + 0x1ce8);
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    if (cVar2 != '\0') goto LAB_002ea454;
  }
  cVar2 = (**(code **)(param_2 + 0x1b0))(param_1,param_2);
  if (cVar2 != '\0') {
    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x80a,"kceAssignCeCaps_GB100",
                 1,"NVRM: LCE %d assigned for Sysmem Rd.\n",*(undefined4 *)(param_2 + 0x2b8));
    *param_3 = *param_3 | 4;
  }
  cVar2 = (**(code **)(param_2 + 0x1b8))(param_1,param_2);
  if (cVar2 != '\0') {
    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x810,"kceAssignCeCaps_GB100",
                 1,"NVRM: LCE %d assigned for Sysmem Wr.\n",*(undefined4 *)(param_2 + 0x2b8));
    *param_3 = *param_3 | 8;
  }
  cVar2 = (**(code **)(param_2 + 0x1d0))(param_1,param_2);
  if (cVar2 != '\0') {
    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x816,"kceAssignCeCaps_GB100",
                 1,"NVRM: LCE %d assigned for fast scrubbing.\n",*(undefined4 *)(param_2 + 0x2b8));
    param_3[1] = param_3[1] | 0x40;
  }
LAB_002ea454:
  if (lVar1 != 0) {
    cVar2 = (**(code **)(param_2 + 0x1c8))(param_1,param_2);
    if (cVar2 != '\0') {
      nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x81d,
                   "kceAssignCeCaps_GB100",1,"NVRM: LCE %d assigned for NVLINK.\n",
                   *(undefined4 *)(param_2 + 0x2b8));
      *param_3 = *param_3 | 0x10;
    }
  }
  cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if (cVar2 != '\0') {
    cVar2 = (**(code **)(param_2 + 0x1c0))(param_1,param_2);
    if (cVar2 != '\0') {
      nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb100.c",0x825,
                   "kceAssignCeCaps_GB100",1,"NVRM: LCE %d assigned for CC Work Submit.\n",
                   *(undefined4 *)(param_2 + 0x2b8));
      param_3[1] = param_3[1] | 0x10;
      return;
    }
  }
  return;
}


// ===== 002ea630 kceGetP2PCes_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kceGetP2PCes_GB100(undefined8 param_1,long param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint local_54;
  undefined4 local_3c [3];
  
  iVar4 = gpumgrGetSubDeviceCount(param_3);
  lVar2 = *(long *)(param_2 + 0x1ce8);
  if (lVar2 == 0) {
    return 0x10006;
  }
  local_54 = param_3;
  if (iVar4 != 1) {
    local_3c[0] = 0;
    do {
      lVar5 = gpumgrGetNextGpu(param_3,local_3c);
      if (lVar5 == 0) {
        local_54 = 0;
        goto LAB_002ea6a9;
      }
    } while (param_2 == lVar5);
    local_54 = 1 << ((byte)*(undefined4 *)(lVar5 + 0x7a4) & 0x1f);
  }
LAB_002ea6a9:
  uVar1 = *(uint *)(param_2 + 0x8fc);
  if (uVar1 != 0) {
    uVar7 = 0;
    do {
      while ((((0x13 < uVar7 || (lVar5 = *(long *)(param_2 + 0x1c30 + uVar7 * 8), lVar5 == 0)) ||
              (*(char *)(lVar5 + 0x2d5) != '\0')) ||
             ((cVar3 = (**(code **)(lVar5 + 0x1c8))(param_2,lVar5), cVar3 == '\0' ||
              ((cVar3 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_2,lVar2), cVar3 == '\0' &&
               ((*(uint *)(lVar5 + 0x2d8) & local_54) == 0))))))) {
        uVar7 = uVar7 + 1;
        if (uVar7 == uVar1) goto LAB_002ea748;
      }
      uVar7 = uVar7 + 1;
      *param_4 = *param_4 | 1 << ((byte)*(undefined4 *)(lVar5 + 0x2b8) & 0x1f);
    } while (uVar7 != uVar1);
  }
LAB_002ea748:
  if (*param_4 == 0) {
    uVar6 = kceGetP2PCes_GH100(param_1,param_2,param_3);
    return uVar6;
  }
  return 0;
}


// ===== 002ea7d0 kceGetPce2lceConfigSize1_GB10B =====

undefined8 kceGetPce2lceConfigSize1_GB10B(void)

{
  return 2;
}


// ===== 002ea7e0 kceMapAsyncLceDefault_GB10B =====

/* WARNING: Type propagation algorithm not settling */

undefined8
kceMapAsyncLceDefault_GB10B
          (long param_1,undefined8 param_2,uint *param_3,long param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_68;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40 [4];
  
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40[0] = 0;
  local_40[1] = 0;
  kceGetPceConfigForLceType_IMPL
            (param_1,param_2,1,&local_4c,&local_48,&local_44,local_40,local_40 + 1);
  uVar3 = local_40[0] >> 1;
  if (uVar3 == 0) {
    local_68 = 1;
  }
  else {
    iVar1 = 0x1f;
    if (uVar3 != 0) {
      for (; uVar3 >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    local_68 = iVar1 + 2;
  }
  if (local_44 >> 1 == 0) {
    uVar3 = 1;
  }
  else {
    iVar1 = 0x1f;
    if (local_44 >> 1 != 0) {
      for (; (local_44 >> 1) >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    uVar3 = iVar1 + 2;
  }
  if (local_48 != 0) {
    uVar4 = 0;
    do {
      if (0xfffffffd < local_40[0] - 1) {
        return 0;
      }
      uVar6 = 0;
      for (uVar7 = local_40[0]; (uVar7 & 1) == 0; uVar7 = uVar7 >> 1 | 0x80000000) {
        uVar6 = uVar6 + 1;
      }
      if (local_68 <= uVar6) {
        return 0;
      }
      if (local_4c != 0) {
        uVar7 = 0;
        do {
          if (0xfffffffd < local_44 - 1) break;
          uVar2 = 0;
          for (uVar5 = local_44; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
            uVar2 = uVar2 + 1;
          }
          if (uVar3 <= uVar2) break;
          uVar7 = uVar7 + 1;
          *(uint *)(param_4 + (ulong)uVar2 * 4) = uVar6;
          uVar5 = ~(1 << ((byte)uVar2 & 0x1f));
          *param_3 = *param_3 & uVar5;
          local_44 = local_44 & uVar5;
          nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb10b.c",0x7c,
                       "kceMapAsyncLceDefault_GB10B",1,"NVRM: GPU%d PCE Index: %d LCE Index: %d\n",
                       *(undefined4 *)(param_1 + 0x7a4),uVar2,uVar6);
        } while (uVar7 < local_4c);
      }
      uVar4 = uVar4 + 1;
      uVar6 = 1 << ((byte)uVar6 & 0x1f);
      local_40[0] = local_40[0] & ~uVar6;
      *param_5 = *param_5 | uVar6;
    } while (uVar4 < local_48);
  }
  return 0;
}


// ===== 002ea990 kceMapPceLceForGRCE_GB10B =====

/* WARNING: Type propagation algorithm not settling */

undefined1  [16]
kceMapPceLceForGRCE_GB10B
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint *param_4,undefined8 param_5
          ,uint *param_6)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  undefined1 auVar6 [16];
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24 [3];
  uint *puVar5;
  
  local_2c = 0;
  local_28 = 0;
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  kceGetPceConfigForLceType_IMPL(param_1,param_2,1,&local_2c,&local_28,local_24,local_24 + 1);
  uVar3 = (ulong)local_24[0];
  uVar4 = local_24[0] >> 1;
  puVar5 = (uint *)(ulong)uVar4;
  if (uVar4 == 0) {
    if (0xfffffffd < local_24[0] - 1) goto LAB_002eaa51;
  }
  else {
    if (local_24[0] - 1 == 0xfffffffe) goto LAB_002eaa51;
    iVar1 = 0x1f;
    if (uVar4 != 0) {
      for (; uVar4 >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    uVar4 = 0;
    for (uVar2 = local_24[0]; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
      uVar4 = uVar4 + 1;
    }
    uVar3 = (ulong)uVar4;
    puVar5 = (uint *)(ulong)(iVar1 + 2U);
    if (iVar1 + 2U <= uVar4) goto LAB_002eaa51;
    param_4 = param_4 + uVar3;
  }
  uVar4 = *param_4;
  uVar3 = (ulong)uVar4;
  if (uVar4 != 0xf) {
    *param_6 = uVar4 & 0xf | 0x40000000;
    uVar3 = (ulong)*param_4;
    nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb10b.c",0xbe,
                 "kceMapPceLceForGRCE_GB10B",1,
                 "NVRM: GRCE %d is shared and mapped to LCE Index: %d.\n",0);
    puVar5 = local_24 + 2;
  }
LAB_002eaa51:
  auVar6._8_8_ = puVar5;
  auVar6._0_8_ = uVar3;
  return auVar6;
}


// ===== 002eaa70 kceGetGrceConfigSize1_GB202 =====

long kceGetGrceConfigSize1_GB202(long param_1)

{
  return (ulong)(*(int *)(param_1 + 700) == 0) << 2;
}


// ===== 002eaa90 kceGetGrceSupportedLceMask_GB202 =====

uint kceGetGrceSupportedLceMask_GB202(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *(uint *)(param_1 + 0x8fc);
  uVar5 = 0;
  if (uVar1 != 0) {
    uVar4 = 0;
    uVar5 = 0;
    do {
      if (((uVar4 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar4 * 8), lVar2 != 0)) &&
         (*(int *)(lVar2 + 700) == *(int *)(param_2 + 700))) {
        uVar6 = *(uint *)(lVar2 + 0x2b8);
        cVar3 = ceIsCeGrce(param_1,uVar6 + 9);
        if (cVar3 == '\0') {
          uVar6 = 0;
        }
        uVar5 = uVar5 | uVar6;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != uVar1);
  }
  return uVar5;
}


// ===== 002eab50 kceMapAsyncLceDefault_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kceMapAsyncLceDefault_GB202(long param_1,long param_2,uint *param_3,long param_4,uint *param_5)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined1 local_44 [4];
  uint local_40 [4];
  
  local_40[0] = 2;
  local_40[1] = 4;
  kceGetPceConfigForLceType_IMPL(param_1,param_2,3,&local_54,&local_50,&local_4c);
  if (2 < local_50) {
    nvAssertFailedNoLog("numLces <= 2","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb202.c",0x90,
                        local_44);
    return 0x40;
  }
  if (local_50 != 0) {
    uVar7 = 0;
    uVar6 = local_48 & 0xfffffff0;
    do {
      uVar9 = 0;
      for (uVar3 = uVar6; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x80000000) {
        uVar9 = uVar9 + 1;
      }
      uVar8 = 0xffffffff;
      if (uVar6 - 1 < 0xfffffffe) {
        uVar8 = (ulong)uVar9;
      }
      if (local_54 != 0) {
        uVar9 = 0;
        bVar4 = false;
        do {
          while( true ) {
            if (local_4c - 1 < 0xfffffffe) break;
            (**(code **)(param_2 + 0x220))(param_2);
LAB_002eac08:
            uVar9 = uVar9 + 1;
            if (local_54 <= uVar9) goto LAB_002eacaa;
          }
          uVar3 = 0;
          for (uVar5 = local_4c; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
            uVar3 = uVar3 + 1;
          }
          uVar5 = (**(code **)(param_2 + 0x220))(param_2);
          if (uVar5 <= uVar3) goto LAB_002eac08;
          uVar9 = uVar9 + 1;
          uVar5 = ~(1 << ((byte)uVar3 & 0x1f));
          *param_3 = *param_3 & uVar5;
          local_4c = local_4c & uVar5;
          *(uint *)(param_4 + (ulong)uVar3 * 4) = (uint)uVar8;
          nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb202.c",0xac,
                       "kceMapAsyncLceDefault_GB202",1,
                       "NVRM: GPU%d <-> GPU%d PCE Index: %d LCE Index: %d\n",
                       *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_1 + 0x7a4),
                       (ulong)uVar3,uVar8);
          bVar4 = true;
        } while (uVar9 < local_54);
LAB_002eacaa:
        if (bVar4) {
          uVar9 = 1 << ((byte)uVar8 & 0x1f);
          uVar6 = uVar6 & ~uVar9;
          *param_5 = *param_5 | uVar9;
          if (((uint)uVar8 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar8 * 8), lVar2 != 0))
          {
            puVar1 = (uint *)(lVar2 + 0x2e4);
            *puVar1 = *puVar1 | local_40[uVar7];
          }
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < local_50);
  }
  return 0;
}


// ===== 002ead40 kceGetMappings_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kceGetMappings_GB202
          (undefined8 param_1,long param_2,long param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6)

{
  char cVar1;
  undefined4 uVar2;
  
  kceGetAvailableHubPceMask_IMPL();
  uVar2 = (**(code **)(param_2 + 0x288))(param_1,param_2,param_3 + 0x18,param_4,param_6,2);
  cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if (cVar1 == '\0') {
    (**(code **)(param_2 + 0x260))
              (param_1,param_2,param_3 + 0x18,param_4,param_6,param_5,
               *(undefined4 *)(param_3 + 0x98));
  }
  nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb202.c",0xe0,"kceGetMappings_GB202",1,
               "NVRM: status = 0x%x\n",uVar2);
  return uVar2;
}


// ===== 002eae20 kceMapPceLceForGRCE_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void kceMapPceLceForGRCE_GB202
               (undefined8 param_1,long param_2,undefined8 param_3,uint *param_4,undefined8 param_5,
               uint *param_6)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (**(code **)(param_2 + 0x220))(param_2,param_2,*(code **)(param_2 + 0x220));
  if (uVar2 == 0) {
    uVar3 = 0x40000000;
    uVar2 = 0;
  }
  else {
    puVar1 = param_4 + uVar2;
    do {
      uVar2 = *param_4;
      if ((uVar2 != 0xf) && ((0xaaaaaaa0U >> (uVar2 & 0x1f) & 1) != 0)) {
        uVar3 = uVar2 & 0xf | 0x40000000;
        goto LAB_002eae80;
      }
      param_4 = param_4 + 1;
    } while (puVar1 != param_4);
    uVar3 = 0x40000000;
    uVar2 = 0;
  }
LAB_002eae80:
  *param_6 = uVar3;
  nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb202.c",0x10d,
               "kceMapPceLceForGRCE_GB202",1,"NVRM: GRCE is shared and mapped to LCE Index: %d.\n",
               uVar2);
  return;
}


// ===== 002eaed0 kceGetPce2lceConfigSize1_GB202 =====

undefined8 kceGetPce2lceConfigSize1_GB202(void)

{
  return 4;
}


// ===== 002eaee0 kceGetGrceMaskReg_GB202 =====

int kceGetGrceMaskReg_GB202(long param_1,undefined8 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  long local_30 [2];
  
  iVar1 = gpuGetOneDeviceEntry_IMPL(param_1,0x13,0xffffffff,0,0xffffffff,local_30);
  if (iVar1 == 0) {
    if (param_3 == (uint *)0x0) {
      iVar1 = 0x1f;
      nvAssertFailedNoLog("(pGrceMask != NULL)","src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb202.c"
                          ,0x13a);
    }
    else {
      uVar2 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_30[0] + 0x10) + 0xd8,0);
      *param_3 = uVar2 & 0x3ff;
      iVar1 = 0;
    }
    return iVar1;
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "GET_DEVICE_ENTRY(pGpu, NV_PTOP_ZB_DEVICE_INFO_DEV_TYPE_ENUM_LCE, DEVICE_INFO_DIELET_INSTANCE_ANY, 0, DEVICE_INFO_DIE_LOCAL_INSTANCE_ID_ANY, &pEntry)"
             ,"src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb202.c",0x134);
  return iVar1;
}


// ===== 002eafa0 kceGetGrceConfigSize1_GB20B =====

bool kceGetGrceConfigSize1_GB20B(long param_1)

{
  return *(int *)(param_1 + 700) == 0;
}


// ===== 002eafc0 kceGetPce2lceConfigSize1_GB20B =====

undefined8 kceGetPce2lceConfigSize1_GB20B(void)

{
  return 2;
}


// ===== 002eafd0 kceMapPceLceForGRCE_GB20B =====

void kceMapPceLceForGRCE_GB20B(void)

{
  undefined4 *in_R9;
  
  *in_R9 = 0xf;
  nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb20b.c",0x5c,"kceMapPceLceForGRCE_GB20B"
               ,1,"NVRM: GRCE %d is not shared\n",0);
  return;
}


// ===== 002eb010 kceMapAsyncLceDefault_GB20B =====

undefined8
kceMapAsyncLceDefault_GB20B
          (long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4,uint *param_5)

{
  *param_4 = 1;
  *param_5 = *param_5 | 2;
  nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb20b.c",0x7b,
               "kceMapAsyncLceDefault_GB20B",1,"NVRM: GPU%d PCE Index: %d LCE Index: %d\n",
               *(undefined4 *)(param_1 + 0x7a4),0,1);
  param_4[1] = 0;
  *param_5 = *param_5 | 1;
  nvDbg_Printf("src/kernel/gpu/ce/arch/blackwell/kernel_ce_gb20b.c",0x82,
               "kceMapAsyncLceDefault_GB20B",1,"NVRM: GPU%d PCE Index: %d LCE Index: %d\n",
               *(undefined4 *)(param_1 + 0x7a4),1,0);
  return 0;
}


// ===== 002eb0b0 kceMapPceLceForCC.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceMapPceLceForCC_isra_0
               (undefined8 param_1,long param_2,uint *param_3,long param_4,uint *param_5)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  
  uVar3 = (**(code **)(param_2 + 0x298))();
  uVar3 = ~uVar3 & 0x3ff;
  uVar8 = uVar3 >> 1;
  puVar7 = param_3;
  if (uVar8 == 0) {
    *param_5 = *param_5 | uVar3;
    uVar8 = 0;
    uVar4 = 0;
    uVar9 = uVar4;
    if (0xfffffffd < -(uint)(uVar3 == 0)) {
      uVar3 = 0;
      goto LAB_002eb143;
    }
  }
  else {
    iVar1 = 0x1f;
    if (uVar8 != 0) {
      for (; uVar8 >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    *param_5 = *param_5 | uVar3;
    uVar8 = iVar1 + 1;
    uVar4 = 0;
    for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x80000000) {
      uVar4 = uVar4 + 1;
    }
    uVar9 = uVar4;
    if (uVar8 < uVar4) {
      uVar3 = 0;
      goto LAB_002eb143;
    }
  }
  do {
    *puVar7 = uVar4;
    uVar4 = uVar4 + 1;
    puVar7 = puVar7 + 1;
  } while (uVar4 <= uVar8);
  uVar3 = 1;
  if (uVar9 + 1 <= uVar8 + 1) {
    uVar3 = (uVar8 + 1) - uVar9;
  }
LAB_002eb143:
  uVar4 = (**(code **)(param_2 + 0x298))(param_1,param_2);
  *param_5 = *param_5 | uVar4;
  lVar10 = 0;
  do {
    if (uVar4 - 1 < 0xfffffffe) {
      uVar9 = 0;
      for (uVar5 = uVar4; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
        uVar9 = uVar9 + 1;
      }
      while (((uVar8 <= uVar9 || ((0x3ffU >> (uVar9 & 0x1f) & 1) == 0)) ||
             (uVar5 = (**(code **)(param_2 + 0x220))(param_2), uVar5 <= uVar3))) {
        lVar10 = lVar10 + 1;
        if (lVar10 == 2) {
          return;
        }
      }
      uVar6 = (ulong)uVar3;
      uVar3 = uVar3 + 1;
      param_3[uVar6] = uVar9;
      bVar2 = (byte)uVar9 & 0x1f;
      uVar4 = uVar4 & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
      *(undefined4 *)(param_4 + lVar10 * 4) = 0xf;
    }
    lVar10 = lVar10 + 1;
  } while (lVar10 != 2);
  return;
}


// ===== 002eb220 kceGetPce2lceConfigSize1_GH100 =====

undefined8 kceGetPce2lceConfigSize1_GH100(void)

{
  return 0x10;
}


// ===== 002eb240 kceGetAutoConfigTableEntry_GH100 =====

undefined8
kceGetAutoConfigTableEntry_GH100
          (long param_1,undefined8 param_2,int *param_3,int *param_4,int param_5,int *param_6,
          int *param_7)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x4915) == '\0') {
    return 0;
  }
  if (param_5 != 0) {
    iVar1 = 0;
    do {
      if ((((*param_4 == *param_3) && (param_4[1] == param_3[1])) &&
          ((char)param_4[3] == (char)param_3[2])) &&
         ((*(char *)((long)param_4 + 0xd) == (char)param_3[5] && (param_4[2] == param_3[4])))) {
        *param_6 = iVar1;
        *param_7 = param_4[0x34];
        return 1;
      }
      iVar1 = iVar1 + 1;
      param_4 = param_4 + 0x35;
    } while (param_5 != iVar1);
  }
  return 0;
}


// ===== 002eb2d0 kceMapPceLceForC2C_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceMapPceLceForC2C_GH100(long param_1,long param_2,long param_3,long param_4,uint *param_5)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  
  iVar6 = *(int *)(param_2 + 0x2dc);
  cVar3 = *(char *)(*(long *)(param_1 + 7000) + 0x3a8);
  cVar2 = gpuIsCCFeatureEnabled_IMPL();
  if (cVar2 == '\0') {
    if ((cVar3 == '\0') || (iVar6 != 0)) {
      return 0x10006;
    }
    if (*(long *)(param_1 + 0x1bc0) != 0) {
      cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
      if (cVar3 != '\0') goto LAB_002eb3e0;
    }
    *param_5 = *param_5 | 4;
    puVar5 = (uint *)(param_3 + 8);
    puVar7 = puVar5;
    do {
      iVar6 = 2;
      while( true ) {
        uVar4 = *puVar7;
        if (uVar4 - 1 < 0xfffffffe) {
          uVar1 = 0;
          for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1 | 0x80000000) {
            uVar1 = uVar1 + 1;
          }
          uVar4 = (**(code **)(param_2 + 0x220))(param_2);
          if (uVar1 < uVar4) {
            *puVar7 = *puVar7 & ~(1 << ((byte)uVar1 & 0x1f));
            *(undefined4 *)(param_4 + (ulong)uVar1 * 4) = 2;
          }
        }
        else {
          (**(code **)(param_2 + 0x220))(param_2);
        }
        if (iVar6 == 1) break;
        iVar6 = 1;
      }
      puVar7 = puVar7 + 1;
    } while (puVar7 != (uint *)(param_3 + 0x14));
    *param_5 = *param_5 | 0x10;
    do {
      iVar6 = 2;
      while( true ) {
        uVar4 = *puVar5;
        if (uVar4 - 1 < 0xfffffffe) {
          uVar1 = 0;
          for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1 | 0x80000000) {
            uVar1 = uVar1 + 1;
          }
          uVar4 = (**(code **)(param_2 + 0x220))(param_2);
          if (uVar1 < uVar4) {
            *puVar5 = *puVar5 & ~(1 << ((byte)uVar1 & 0x1f));
            *(undefined4 *)(param_4 + (ulong)uVar1 * 4) = 4;
          }
        }
        else {
          (**(code **)(param_2 + 0x220))(param_2);
        }
        if (iVar6 == 1) break;
        iVar6 = 1;
      }
      puVar5 = puVar5 + 1;
    } while (puVar5 != (uint *)(param_3 + 0x14));
  }
  else {
LAB_002eb3e0:
    *param_5 = *param_5 | 0xc;
    *(undefined8 *)(param_4 + 4) = 0x300000002;
  }
  return 0;
}


// ===== 002eb4b0 kceIsGenXorHigherSupported_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool kceIsGenXorHigherSupported_GH100(long param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  byte local_1d;
  undefined4 local_1c [3];
  
  local_1d = 0;
  local_1c[0] = 0;
  if (*(char *)(param_1 + 0x4912) == '\0') {
    iVar1 = clPcieGetRootGenSpeed_IMPL(param_1,*(undefined8 *)(g_pSys + 0x208),&local_1d);
    if (iVar1 == 0) {
      if (*(char *)(param_1 + 0x4912) == '\0') goto LAB_002eb511;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x1af,
                   "kceIsGenXorHigherSupported_GH100",4,
                   "NVRM: Could not get root gen speed - check for GPU gen speed!\n");
    }
  }
  iVar1 = (**(code **)(param_1 + 0x1b0))(param_1,0x70,local_1c);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x1b8,
                 "kceIsGenXorHigherSupported_GH100",4,
                 "NVRM: Unable to read NV_EP_PCFG_GPU_LINK_CONTROL_STATUS from config space.\n");
    return false;
  }
  local_1d = (byte)((uint)local_1c[0] >> 0x10) & 0xf;
LAB_002eb511:
  nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x1be,
               "kceIsGenXorHigherSupported_GH100",1,"NVRM: Gen Speed = %d\n",local_1d);
  return param_3 <= local_1d;
}


// ===== 002eb5f0 kceMapPceLceForGRCE_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceMapPceLceForGRCE_GH100
               (long param_1,long param_2,undefined8 param_3,long param_4,uint *param_5,
               uint *param_6)

{
  char cVar1;
  uint uVar2;
  bool bVar3;
  char cVar4;
  char cVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  long lVar10;
  bool bVar11;
  uint local_48 [6];
  
  local_48[0] = 0xc;
  local_48[1] = 0xe;
  lVar10 = *(long *)(param_1 + 7000);
  local_48[2] = 0xd;
  local_48[3] = 0xf;
  cVar4 = (**(code **)(param_2 + 0x2a0))(param_1,param_2,5);
  cVar1 = *(char *)(lVar10 + 0x3a8);
  iVar7 = *(int *)(param_2 + 0x2dc);
  cVar5 = gpuIsCCFeatureEnabled_IMPL(param_1);
  bVar11 = cVar4 == '\0';
  if ((cVar5 != '\0') || ((cVar1 != '\0' && (iVar7 == 0)))) {
    uVar8 = 3;
    iVar7 = 0;
    *param_5 = *param_5 | 3;
    puVar6 = local_48;
    do {
      if (*puVar6 != 0) {
        iVar7 = 0;
        for (uVar9 = uVar8; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
          iVar7 = iVar7 + 1;
        }
        if (0xfffffffd < uVar8 - 1) {
          iVar7 = -1;
        }
        *(int *)(param_4 + (ulong)*puVar6 * 4) = iVar7;
      }
      if ((puVar6[1] != 0) && (!bVar11)) {
        iVar7 = 0;
        for (uVar9 = uVar8; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1 | 0x80000000) {
          iVar7 = iVar7 + 1;
        }
        if (0xfffffffd < uVar8 - 1) {
          iVar7 = -1;
        }
        *(int *)(param_4 + (ulong)puVar6[1] * 4) = iVar7;
      }
      puVar6 = puVar6 + 2;
      uVar8 = uVar8 & ~(1 << ((byte)iVar7 & 0x1f));
    } while (puVar6 != local_48 + 4);
    return;
  }
  uVar9 = 0xc;
  uVar8 = 0;
  *param_5 = *param_5 | 0xc;
  puVar6 = local_48;
  do {
    if (*puVar6 != 0) {
      uVar8 = 0;
      for (uVar2 = uVar9; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
        uVar8 = uVar8 + 1;
      }
      if (0xfffffffd < uVar9 - 1) {
        uVar8 = 0xffffffff;
      }
      *(uint *)(param_4 + (ulong)*puVar6 * 4) = uVar8;
    }
    if ((puVar6[1] != 0) && (!bVar11)) {
      uVar8 = 0;
      for (uVar2 = uVar9; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
        uVar8 = uVar8 + 1;
      }
      if (0xfffffffd < uVar9 - 1) {
        uVar8 = 0xffffffff;
      }
      *(uint *)(param_4 + (ulong)puVar6[1] * 4) = uVar8;
    }
    puVar6 = puVar6 + 2;
    uVar9 = uVar9 & ~(1 << ((byte)uVar8 & 0x1f));
  } while (puVar6 != local_48 + 4);
  uVar9 = (**(code **)(param_2 + 0x298))(param_1);
  *param_5 = *param_5 | uVar9;
  lVar10 = 0;
  do {
    bVar3 = false;
    uVar2 = local_48[lVar10];
    if (uVar2 == 0) goto LAB_002eb7d1;
    do {
      if ((bVar3) && (bVar11)) break;
      puVar6 = (uint *)(param_4 + (ulong)uVar2 * 4);
      uVar8 = *puVar6;
      if ((*param_5 >> (uVar8 & 0x1f) & 1) == 0) {
        uVar8 = 0;
        for (uVar2 = uVar9; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1 | 0x80000000) {
          uVar8 = uVar8 + 1;
        }
        if (0xfffffffd < uVar9 - 1) {
          uVar8 = 0xffffffff;
        }
        *puVar6 = uVar8;
        *param_6 = 0xf;
      }
      else {
        *param_6 = uVar8 & 0xf | 0x40000000;
      }
      if (bVar3) break;
LAB_002eb7d1:
      bVar3 = true;
      uVar2 = local_48[(int)lVar10 + 1];
    } while (uVar2 != 0);
    param_6 = param_6 + 1;
    uVar9 = uVar9 & ~(1 << ((byte)uVar8 & 0x1f));
    if ((int)lVar10 == 2) {
      return;
    }
    lVar10 = 2;
  } while( true );
}


// ===== 002eb827 kceMapPceLceForNvlinkPeers_GH100.cold =====

void kceMapPceLceForNvlinkPeers_GH100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002eb830 __pfx_kceMapPceLceForNvlinkPeers_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

uint __pfx_kceMapPceLceForNvlinkPeers_GH100
               (long param_1,long param_2,long param_3,long param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  uint uVar5;
  bool bVar6;
  long lVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  long lVar16;
  undefined8 uVar17;
  byte *pbVar18;
  long lVar19;
  uint uVar20;
  uint uVar21;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  int aiStack_78 [8];
  byte abStack_58 [40];
  
  lVar7 = g_pSys;
  lVar3 = *(long *)(param_1 + 0x1ce8);
  aiStack_78[1] = 0;
  if (lVar3 == 0) {
    return 0x10006;
  }
  uVar21 = (**(code **)(param_2 + 0x290))(param_1,param_2,0xffffffff);
  *(undefined4 *)(param_2 + 0x2dc) = 0;
  cVar8 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar3);
  if (cVar8 == '\0') {
    gpumgrGetGpuAttachInfo(0,aiStack_78);
  }
  else {
    aiStack_78[0] = 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
  }
  bVar6 = false;
LAB_002eb8fb:
  while (lVar16 = gpumgrGetNextGpu(aiStack_78[0],aiStack_78 + 1), lVar16 != 0) {
    iVar9 = knvlinkGetNumLinksToPeer_IMPL(param_1,lVar3,lVar16);
    if (iVar9 != 0) {
      if (uVar21 == 0) {
        uVar21 = (**(code **)(param_2 + 0x290))(param_1,param_2,0);
      }
      if (uVar21 - 1 < 0xfffffffe) {
        uStack_98 = 0;
        for (uVar10 = uVar21; (uVar10 & 1) == 0; uVar10 = uVar10 >> 1 | 0x80000000) {
          uStack_98 = uStack_98 + 1;
        }
        if ((int)uStack_98 < 9) {
          uStack_9c = 1 << ((byte)uStack_98 & 0x1f);
          uVar21 = uVar21 & ~uStack_9c;
        }
        else {
          uStack_9c = 0;
        }
      }
      else {
        uStack_98 = 0xffffffff;
        uStack_9c = 0;
      }
      *(int *)(param_2 + 0x2dc) = *(int *)(param_2 + 0x2dc) + 1;
      uVar10 = knvlinkGetLinkMaskToPeer_IMPL(param_1,lVar3,lVar16);
      if (uVar10 != 0) {
        portMemSet(aiStack_78 + 7,0,0x24);
        aiStack_78[7] = uVar10;
        uVar11 = knvlinkExecGspRmRpc_IMPL(param_1,lVar3,0x20800a8a,aiStack_78 + 7,0x24);
        if (uVar11 != 0) {
          nvAssertOkFailedNoLog
                    (uVar11,"status","src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x2f8);
          return uVar11;
        }
        aiStack_78[2] = 0;
        aiStack_78[3] = 0;
        pbVar18 = abStack_58;
        aiStack_78[4] = 0;
        aiStack_78[5] = 0;
        aiStack_78[6] = 0;
        do {
          if ((uVar10 & 1) != 0) {
            if (4 < *pbVar18) {
              nvAssertFailedNoLog("hshubId < NV_CE_MAX_HSHUBS",
                                  "src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x307);
              return 0x40;
            }
            aiStack_78[(ulong)*pbVar18 + 2] = aiStack_78[(ulong)*pbVar18 + 2] + 1;
            if (uVar10 >> 1 == 0) goto LAB_002ebab8;
          }
          uVar10 = uVar10 >> 1;
          pbVar18 = pbVar18 + 1;
        } while( true );
      }
      nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x2ee,
                   "kceMapPceLceForNvlinkPeers_GH100",1,
                   "NVRM: GPU%d has nvlink disabled. Skip programming\n",
                   *(undefined4 *)(lVar16 + 0x7a4));
    }
  }
  goto LAB_002ebceb;
LAB_002ebab8:
  lVar19 = 0;
  uStack_94 = 0;
  do {
    if (aiStack_78[lVar19 + 2] != 0) {
      uVar20 = *(uint *)(param_3 + lVar19 * 4);
      uVar11 = uVar20 - 1;
      uVar12 = 0;
      for (; (uVar20 & 1) == 0; uVar20 = uVar20 >> 1 | 0x80000000) {
        uVar12 = uVar12 + 1;
      }
      uVar20 = 0xffffffff;
      if (uVar11 < 0xfffffffe) {
        uVar20 = uVar12;
      }
      uVar12 = aiStack_78[lVar19 + 2] - 3;
      uVar11 = uVar10 & 1;
      if (uVar12 < 4) {
        uVar11 = *(uint *)(CSWTCH_80 + (ulong)uVar12 * 4);
      }
      uVar12 = 0;
      do {
        uVar13 = (**(code **)(param_2 + 0x220))(param_2);
        if (uVar20 < uVar13) {
          uVar13 = *(uint *)(param_3 + lVar19 * 4);
          if ((uVar13 >> (uVar20 & 0x1f) & 1) == 0) {
            if (uVar13 - 1 < 0xfffffffe) {
              uVar20 = 0;
              for (uVar14 = uVar13; (uVar14 & 1) == 0; uVar14 = uVar14 >> 1 | 0x80000000) {
                uVar20 = uVar20 + 1;
              }
              if ((uVar13 >> (uVar20 & 0x1f) & 1) != 0) goto LAB_002ebb70;
            }
            else {
              uVar20 = 0xffffffff;
            }
            uVar14 = (uint)lVar19;
            uVar15 = uVar14 + 1;
            do {
              while (uVar15 == 5) {
                uVar15 = 2;
LAB_002ebc01:
                if (uVar14 == uVar15) goto LAB_002ebc2d;
              }
              uVar2 = *(uint *)(param_3 + (ulong)uVar15 * 4);
              if (0xfffffffd < uVar2 - 1) {
                uVar15 = uVar15 + 1;
                uVar20 = 0xffffffff;
                goto LAB_002ebc01;
              }
              uVar20 = 0;
              for (uVar5 = uVar2; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
                uVar20 = uVar20 + 1;
              }
              if ((uVar2 >> (uVar20 & 0x1f) & 1) != 0) {
                if (uVar14 != uVar15) goto LAB_002ebb70;
                break;
              }
              uVar15 = uVar15 + 1;
            } while (uVar14 != uVar15);
LAB_002ebc2d:
            nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x134,
                         "_ceGetAlgorithmPceIndex",4,"NVRM: No more available PCEs to assign!\n");
            nvAssertFailedNoLog(&DAT_00d027ed,"src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",
                                0x135);
            uVar13 = *(uint *)(param_3 + lVar19 * 4);
          }
        }
        else {
          uVar17 = (**(code **)(param_2 + 0x220))(param_2);
          nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x116,
                       "_ceGetAlgorithmPceIndex",4,
                       "NVRM: Invalid PCE request. pceIndex = %d pceCnt = %d\n",uVar20,uVar17);
          uVar13 = *(uint *)(param_3 + lVar19 * 4);
        }
LAB_002ebb70:
        uVar12 = uVar12 + 1;
        uVar14 = 1 << ((byte)uVar20 & 0x1f);
        uStack_94 = uStack_94 | uVar14;
        *(uint *)(param_3 + lVar19 * 4) = ~uVar14 & uVar13;
      } while (uVar12 != uVar11);
    }
    lVar19 = lVar19 + 1;
  } while (lVar19 != 5);
  if (uStack_94 != 0) {
    lVar19 = 0;
    do {
      if ((uStack_94 & 1) != 0) {
        *(uint *)(param_4 + lVar19 * 4) = uStack_98;
        nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x329,
                     "kceMapPceLceForNvlinkPeers_GH100",1,
                     "NVRM: GPU%d <-> GPU%d PCE Index: %d LCE Index: %d\n",
                     *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(lVar16 + 0x7a4),lVar19,
                     uStack_98);
        if (uStack_94 >> 1 == 0) goto LAB_002ebda6;
      }
      uStack_94 = uStack_94 >> 1;
      lVar19 = lVar19 + 1;
    } while( true );
  }
LAB_002ebcaa:
  if (0x13 < uStack_98) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  puVar1 = (uint *)(*(long *)(param_1 + 0x1c30 + (ulong)uStack_98 * 8) + 0x2d8);
  *puVar1 = *puVar1 | 1 << ((byte)*(undefined4 *)(lVar16 + 0x7a4) & 0x1f);
  if (*(char *)(lVar7 + 0x6b) != '\0') {
LAB_002ebceb:
    return -(uint)!bVar6 & 0x10006;
  }
  goto LAB_002eb8fb;
LAB_002ebda6:
  bVar6 = true;
  *param_5 = *param_5 | uStack_9c;
  goto LAB_002ebcaa;
}


// ===== 002eb840 kceMapPceLceForNvlinkPeers_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

uint kceMapPceLceForNvlinkPeers_GH100
               (long param_1,long param_2,long param_3,long param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  uint uVar5;
  bool bVar6;
  long lVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  long lVar16;
  undefined8 uVar17;
  byte *pbVar18;
  long lVar19;
  uint uVar20;
  uint uVar21;
  uint local_9c;
  uint local_98;
  uint local_94;
  int local_78 [8];
  byte local_58 [40];
  
  lVar7 = g_pSys;
  lVar3 = *(long *)(param_1 + 0x1ce8);
  local_78[1] = 0;
  if (lVar3 == 0) {
    return 0x10006;
  }
  uVar21 = (**(code **)(param_2 + 0x290))(param_1,param_2,0xffffffff);
  *(undefined4 *)(param_2 + 0x2dc) = 0;
  cVar8 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar3);
  if (cVar8 == '\0') {
    gpumgrGetGpuAttachInfo(0,local_78);
  }
  else {
    local_78[0] = 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
  }
  bVar6 = false;
LAB_002eb8fb:
  while (lVar16 = gpumgrGetNextGpu(local_78[0],local_78 + 1), lVar16 != 0) {
    iVar9 = knvlinkGetNumLinksToPeer_IMPL(param_1,lVar3,lVar16);
    if (iVar9 != 0) {
      if (uVar21 == 0) {
        uVar21 = (**(code **)(param_2 + 0x290))(param_1,param_2,0);
      }
      if (uVar21 - 1 < 0xfffffffe) {
        local_98 = 0;
        for (uVar10 = uVar21; (uVar10 & 1) == 0; uVar10 = uVar10 >> 1 | 0x80000000) {
          local_98 = local_98 + 1;
        }
        if ((int)local_98 < 9) {
          local_9c = 1 << ((byte)local_98 & 0x1f);
          uVar21 = uVar21 & ~local_9c;
        }
        else {
          local_9c = 0;
        }
      }
      else {
        local_98 = 0xffffffff;
        local_9c = 0;
      }
      *(int *)(param_2 + 0x2dc) = *(int *)(param_2 + 0x2dc) + 1;
      uVar10 = knvlinkGetLinkMaskToPeer_IMPL(param_1,lVar3,lVar16);
      if (uVar10 != 0) {
        portMemSet(local_78 + 7,0,0x24);
        local_78[7] = uVar10;
        uVar11 = knvlinkExecGspRmRpc_IMPL(param_1,lVar3,0x20800a8a,local_78 + 7,0x24);
        if (uVar11 != 0) {
          nvAssertOkFailedNoLog
                    (uVar11,"status","src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x2f8);
          return uVar11;
        }
        local_78[2] = 0;
        local_78[3] = 0;
        pbVar18 = local_58;
        local_78[4] = 0;
        local_78[5] = 0;
        local_78[6] = 0;
        do {
          if ((uVar10 & 1) != 0) {
            if (4 < *pbVar18) {
              nvAssertFailedNoLog("hshubId < NV_CE_MAX_HSHUBS",
                                  "src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x307);
              return 0x40;
            }
            local_78[(ulong)*pbVar18 + 2] = local_78[(ulong)*pbVar18 + 2] + 1;
            if (uVar10 >> 1 == 0) goto LAB_002ebab8;
          }
          uVar10 = uVar10 >> 1;
          pbVar18 = pbVar18 + 1;
        } while( true );
      }
      nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x2ee,
                   "kceMapPceLceForNvlinkPeers_GH100",1,
                   "NVRM: GPU%d has nvlink disabled. Skip programming\n",
                   *(undefined4 *)(lVar16 + 0x7a4));
    }
  }
  goto LAB_002ebceb;
LAB_002ebab8:
  lVar19 = 0;
  local_94 = 0;
  do {
    if (local_78[lVar19 + 2] != 0) {
      uVar20 = *(uint *)(param_3 + lVar19 * 4);
      uVar11 = uVar20 - 1;
      uVar12 = 0;
      for (; (uVar20 & 1) == 0; uVar20 = uVar20 >> 1 | 0x80000000) {
        uVar12 = uVar12 + 1;
      }
      uVar20 = 0xffffffff;
      if (uVar11 < 0xfffffffe) {
        uVar20 = uVar12;
      }
      uVar12 = local_78[lVar19 + 2] - 3;
      uVar11 = uVar10 & 1;
      if (uVar12 < 4) {
        uVar11 = *(uint *)(CSWTCH_80 + (ulong)uVar12 * 4);
      }
      uVar12 = 0;
      do {
        uVar13 = (**(code **)(param_2 + 0x220))(param_2);
        if (uVar20 < uVar13) {
          uVar13 = *(uint *)(param_3 + lVar19 * 4);
          if ((uVar13 >> (uVar20 & 0x1f) & 1) == 0) {
            if (uVar13 - 1 < 0xfffffffe) {
              uVar20 = 0;
              for (uVar14 = uVar13; (uVar14 & 1) == 0; uVar14 = uVar14 >> 1 | 0x80000000) {
                uVar20 = uVar20 + 1;
              }
              if ((uVar13 >> (uVar20 & 0x1f) & 1) != 0) goto LAB_002ebb70;
            }
            else {
              uVar20 = 0xffffffff;
            }
            uVar14 = (uint)lVar19;
            uVar15 = uVar14 + 1;
            do {
              while (uVar15 == 5) {
                uVar15 = 2;
LAB_002ebc01:
                if (uVar14 == uVar15) goto LAB_002ebc2d;
              }
              uVar2 = *(uint *)(param_3 + (ulong)uVar15 * 4);
              if (0xfffffffd < uVar2 - 1) {
                uVar15 = uVar15 + 1;
                uVar20 = 0xffffffff;
                goto LAB_002ebc01;
              }
              uVar20 = 0;
              for (uVar5 = uVar2; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1 | 0x80000000) {
                uVar20 = uVar20 + 1;
              }
              if ((uVar2 >> (uVar20 & 0x1f) & 1) != 0) {
                if (uVar14 != uVar15) goto LAB_002ebb70;
                break;
              }
              uVar15 = uVar15 + 1;
            } while (uVar14 != uVar15);
LAB_002ebc2d:
            nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x134,
                         "_ceGetAlgorithmPceIndex",4,"NVRM: No more available PCEs to assign!\n");
            nvAssertFailedNoLog(&DAT_00d027ed,"src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",
                                0x135);
            uVar13 = *(uint *)(param_3 + lVar19 * 4);
          }
        }
        else {
          uVar17 = (**(code **)(param_2 + 0x220))(param_2);
          nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x116,
                       "_ceGetAlgorithmPceIndex",4,
                       "NVRM: Invalid PCE request. pceIndex = %d pceCnt = %d\n",uVar20,uVar17);
          uVar13 = *(uint *)(param_3 + lVar19 * 4);
        }
LAB_002ebb70:
        uVar12 = uVar12 + 1;
        uVar14 = 1 << ((byte)uVar20 & 0x1f);
        local_94 = local_94 | uVar14;
        *(uint *)(param_3 + lVar19 * 4) = ~uVar14 & uVar13;
      } while (uVar12 != uVar11);
    }
    lVar19 = lVar19 + 1;
  } while (lVar19 != 5);
  if (local_94 != 0) {
    lVar19 = 0;
    do {
      if ((local_94 & 1) != 0) {
        *(uint *)(param_4 + lVar19 * 4) = local_98;
        nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x329,
                     "kceMapPceLceForNvlinkPeers_GH100",1,
                     "NVRM: GPU%d <-> GPU%d PCE Index: %d LCE Index: %d\n",
                     *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(lVar16 + 0x7a4),lVar19,
                     local_98);
        if (local_94 >> 1 == 0) goto LAB_002ebda6;
      }
      local_94 = local_94 >> 1;
      lVar19 = lVar19 + 1;
    } while( true );
  }
LAB_002ebcaa:
  if (0x13 < local_98) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  puVar1 = (uint *)(*(long *)(param_1 + 0x1c30 + (ulong)local_98 * 8) + 0x2d8);
  *puVar1 = *puVar1 | 1 << ((byte)*(undefined4 *)(lVar16 + 0x7a4) & 0x1f);
  if (*(char *)(lVar7 + 0x6b) != '\0') {
LAB_002ebceb:
    return -(uint)!bVar6 & 0x10006;
  }
  goto LAB_002eb8fb;
LAB_002ebda6:
  bVar6 = true;
  *param_5 = *param_5 | local_9c;
  goto LAB_002ebcaa;
}


// ===== 002ebe20 kceMapAsyncLceDefault_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8
kceMapAsyncLceDefault_GH100
          (long param_1,long param_2,long param_3,long param_4,uint *param_5,uint param_6)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_40;
  
  uVar6 = (**(code **)(param_2 + 0x290))(param_1,param_2,0xffffffff);
  if (uVar6 - 1 < 0xfffffffe) {
    iVar4 = 0;
    for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1 | 0x80000000) {
      iVar4 = iVar4 + 1;
    }
    local_40 = 0;
    if (iVar4 < 9) {
      local_40 = 1 << ((byte)iVar4 & 0x1f);
    }
  }
  else {
    local_40 = 0;
    iVar4 = -1;
  }
  if (param_6 != 0) {
    uVar6 = 0;
    uVar8 = 0;
    uVar7 = 1;
    do {
      while( true ) {
        uVar7 = uVar7 + ((uVar6 & 3) == 0);
        puVar1 = (uint *)(param_3 + (ulong)uVar7 * 4);
        uVar3 = *puVar1;
        if (uVar3 - 1 < 0xfffffffe) break;
        (**(code **)(param_2 + 0x220))(param_2);
LAB_002ebec0:
        uVar6 = uVar6 + 1;
        if (param_6 == uVar6) goto LAB_002ebf25;
      }
      uVar2 = 0;
      for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x80000000) {
        uVar2 = uVar2 + 1;
      }
      uVar3 = (**(code **)(param_2 + 0x220))(param_2);
      if (uVar3 <= uVar2) goto LAB_002ebec0;
      uVar6 = uVar6 + 1;
      uVar3 = 1 << ((byte)uVar2 & 0x1f);
      uVar8 = uVar8 | uVar3;
      *puVar1 = *puVar1 & ~uVar3;
    } while (param_6 != uVar6);
LAB_002ebf25:
    if (uVar8 != 0) {
      lVar5 = 0;
      do {
        if ((uVar8 & 1) != 0) {
          *(int *)(param_4 + lVar5 * 4) = iVar4;
          nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x38b,
                       "kceMapAsyncLceDefault_GH100",1,
                       "NVRM: GPU%d <-> GPU%d PCE Index: %d LCE Index: %d\n",
                       *(undefined4 *)(param_1 + 0x7a4),*(undefined4 *)(param_1 + 0x7a4),lVar5,iVar4
                      );
          if (uVar8 >> 1 == 0) break;
        }
        uVar8 = uVar8 >> 1;
        lVar5 = lVar5 + 1;
      } while( true );
    }
  }
  *param_5 = *param_5 | local_40;
  return 0;
}


// ===== 002ebfe0 kceGetMappings_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceGetMappings_GH100
          (long param_1,long param_2,undefined4 *param_3,long param_4,long param_5,
          undefined8 param_6)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  uint local_3c [3];
  
  lVar7 = *(long *)(param_1 + 0x1ce8);
  local_3c[0] = 0xffff;
  uVar3 = (**(code **)(param_2 + 0x220))(param_2);
  uVar4 = (**(code **)(param_2 + 0x218))(param_2);
  if ((*(char *)(param_1 + 0x4915) != '\0') && (*(char *)(param_1 + 0x4b0) == '\0')) {
    cVar2 = (**(code **)(param_2 + 0x210))
                      (param_1,param_2,param_3,nvLinkCeAutoConfigTable_GH100,0x28,local_3c,param_6);
    if (cVar2 != '\0') {
      if (uVar3 != 0) {
        lVar7 = 0;
        do {
          *(undefined4 *)(param_4 + lVar7) =
               *(undefined4 *)((ulong)local_3c[0] * 0xd4 + 0x59c3d0 + lVar7);
          lVar7 = lVar7 + 4;
        } while ((ulong)uVar3 << 2 != lVar7);
      }
      if (uVar4 != 0) {
        lVar7 = 0;
        do {
          *(undefined4 *)(param_5 + lVar7) =
               *(undefined4 *)((ulong)local_3c[0] * 0xd4 + 0x59c430 + lVar7);
          lVar7 = lVar7 + 4;
        } while ((ulong)uVar4 << 2 != lVar7);
      }
      lVar7 = (ulong)local_3c[0] * 0xd4;
      param_3[0x4c] = local_3c[0];
      *param_3 = *(undefined4 *)(nvLinkCeAutoConfigTable_GH100 + lVar7);
      param_3[1] = *(undefined4 *)(nvLinkCeAutoConfigTable_GH100 + lVar7 + 4);
      param_3[4] = *(undefined4 *)(nvLinkCeAutoConfigTable_GH100 + lVar7 + 8);
      *(undefined1 *)(param_3 + 2) = nvLinkCeAutoConfigTable_GH100[lVar7 + 0xc];
      *(undefined1 *)(param_3 + 5) = nvLinkCeAutoConfigTable_GH100[lVar7 + 0xd];
      return 0;
    }
  }
  cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if (cVar2 != '\0') {
    kceMapPceLceForCC_isra_0(param_1,param_2,param_4,param_5,param_6);
    return 0;
  }
  kceGetAvailableHubPceMask_IMPL(param_1,param_2,param_3);
  puVar1 = param_3 + 6;
  if ((lVar7 == 0) || (cVar2 = knvlinkIsForcedConfig_IMPL(param_1,lVar7), cVar2 != '\0')) {
    iVar6 = (**(code **)(param_2 + 0x238))(param_1,param_2,puVar1,param_4,param_6);
    (**(code **)(param_2 + 0x260))(param_1,param_2,puVar1,param_4,param_6,param_5,param_3[0x26]);
    iVar5 = 0x10006;
    if (iVar6 != 0x10006) goto LAB_002ec2e4;
  }
  else {
    iVar5 = (**(code **)(param_2 + 0x278))(param_1,param_2,puVar1,param_4,param_6);
    iVar6 = (**(code **)(param_2 + 0x238))(param_1,param_2,puVar1,param_4,param_6);
    (**(code **)(param_2 + 0x260))(param_1,param_2,puVar1,param_4,param_6,param_5,param_3[0x26]);
    if ((iVar5 == 0x10006) && (iVar6 == 0x10006)) {
      iVar6 = 0x10006;
    }
    else if ((iVar5 != 0x56) || (iVar6 != 0x56)) goto LAB_002ec2e4;
  }
  iVar5 = (**(code **)(param_2 + 0x288))(param_1,param_2,puVar1,param_4,param_6,0xc);
LAB_002ec2e4:
  nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x3fb,"kceGetMappings_GH100",1,
               "NVRM: status = %d, statusC2C = %d\n",iVar5,iVar6);
  return 0;
}


// ===== 002ec360 kceGetP2PCes_GH100 =====

int kceGetP2PCes_GH100(long param_1,long param_2,undefined4 param_3,uint *param_4)

{
  ulong uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  byte bVar8;
  uint uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  uint local_c0;
  undefined4 local_a4;
  int local_a0;
  uint local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  uint local_84;
  byte local_80 [32];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar3 = gpumgrGetSubDeviceCount(param_3);
  lVar16 = *(long *)(param_2 + 0x1ce8);
  if (lVar16 == 0) {
    return 0x10006;
  }
  cVar2 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_2,lVar16);
  *param_4 = 0;
  if (uVar3 == 1) {
    if (cVar2 == '\0') {
      *param_4 = 0x10;
      if (*(uint *)(param_2 + 0x8fc) < 5) {
        return 0;
      }
      uVar3 = 0x10;
      uVar9 = 4;
      do {
        bVar8 = (byte)uVar9;
        uVar9 = uVar9 + 1;
        uVar3 = uVar3 | 1 << (bVar8 & 0x1f);
        *param_4 = uVar3;
      } while (uVar9 < *(uint *)(param_2 + 0x8fc));
      return 0;
    }
  }
  else if (cVar2 == '\0') {
    if (2 < uVar3) {
      nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x45f,"kceGetP2PCes_GH100",1,
                   "NVRM: GPU %d invalid request for gpuCount %d\n",*(undefined4 *)(param_2 + 0x7a4)
                   ,uVar3);
      return 0x40;
    }
    local_a4 = 0;
    local_98 = 0;
    local_90 = 0;
    local_88 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    do {
      lVar7 = gpumgrGetNextGpu(param_3,&local_a4);
      if (lVar7 == 0) {
        nvAssertFailedNoLog("pRemoteGpu != NULL","src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",
                            0x480);
        return 0x40;
      }
    } while (param_2 == lVar7);
    local_a4 = *(undefined4 *)(lVar7 + 0x7a4);
    uVar3 = knvlinkGetLinkMaskToPeer_IMPL(param_2,lVar16,lVar7);
    portMemSet(&local_84,0,0x24);
    local_84 = uVar3;
    iVar4 = knvlinkExecGspRmRpc_IMPL(param_2,lVar16,0x20800a8a,&local_84,0x24);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog(iVar4,"status","src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x48c);
      return iVar4;
    }
    pbVar11 = local_80;
    uVar15 = 5;
    uVar9 = 0;
    if (uVar3 != 0) {
      while( true ) {
        for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
          pbVar11 = pbVar11 + 1;
        }
        bVar8 = *pbVar11;
        uVar5 = (uint)bVar8;
        if (4 < uVar5) {
          nvAssertFailedNoLog("hshubId < NV_CE_MAX_HSHUBS",
                              "src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x491);
          return 0x40;
        }
        uVar6 = *(int *)((long)&local_98 + (ulong)uVar5 * 4) + 1;
        *(uint *)((long)&local_98 + (ulong)uVar5 * 4) = uVar6;
        uVar1 = (ulong)bVar8;
        if (uVar6 <= uVar9) {
          uVar6 = uVar9;
          uVar1 = uVar15;
        }
        uVar3 = uVar3 >> 1;
        if (uVar3 == 0) break;
        pbVar11 = pbVar11 + 1;
        uVar15 = uVar1;
        uVar9 = uVar6;
      }
      if ((int)uVar1 != 5) {
        uVar3 = *(uint *)(param_2 + 0x8fc);
        uVar10 = local_a4;
        if (4 < uVar3) {
          uVar15 = 4;
          local_c0 = 0;
          do {
            if ((((uVar15 < 0x14) && (lVar7 = *(long *)(param_2 + 0x1c30 + uVar15 * 8), lVar7 != 0))
                && (*(int *)(lVar7 + 700) == *(int *)(param_1 + 700))) &&
               (*(char *)(lVar7 + 0x2d5) == '\0')) {
              if ((1 << ((byte)uVar10 & 0x1f) & *(uint *)(lVar7 + 0x2d8)) != 0) {
                (&local_60)[uVar1] = lVar7;
                goto LAB_002ec9cc;
              }
              if (*(uint *)(lVar7 + 0x2d8) == 0) {
                uVar9 = *(uint *)(lVar7 + 0x2b8);
                local_9c = 0;
                local_a0 = uVar9 + 0x2a;
                if (uVar9 < 10) {
                  local_a0 = uVar9 + 9;
                }
                iVar4 = knvlinkExecGspRmRpc_IMPL(param_2,lVar16,0x20802a02,&local_a0,8);
                if (iVar4 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar4,"status","src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x4c5)
                  ;
                  return iVar4;
                }
                uVar13 = 5;
                lVar14 = 0;
                uVar12 = 2;
                uVar9 = 0;
                do {
                  uVar5 = 0xf << ((char)uVar12 * '\x04' - 8U & 0x1f) & local_9c;
                  uVar5 = uVar5 - (uVar5 >> 1 & 0x55555555);
                  uVar5 = (uVar5 & 0x33333333) + (uVar5 >> 2 & 0x33333333);
                  uVar5 = ((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101 >> 0x18;
                  if ((uVar9 < uVar5) &&
                     ((local_c0 & 1 << ((byte)*(undefined4 *)(lVar7 + 0x2b8) & 0x1f)) == 0)) {
                    uVar13 = uVar12;
                    lVar14 = lVar7;
                    uVar9 = uVar5;
                  }
                  uVar5 = (int)uVar12 + 1;
                  uVar12 = (ulong)uVar5;
                } while (uVar5 != 5);
                uVar10 = local_a4;
                if ((uint)uVar13 < 5) {
                  (&local_60)[uVar13] = lVar14;
                  local_c0 = local_c0 | 1 << ((byte)*(undefined4 *)(lVar14 + 0x2b8) & 0x1f);
                }
              }
            }
            uVar15 = uVar15 + 1;
          } while (uVar3 != uVar15);
        }
        lVar7 = (&local_60)[uVar1];
        if (lVar7 == 0) {
          lVar16 = *(long *)(param_2 + 0x1c30 + uVar1 * 8);
          nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x4f1,"kceGetP2PCes_GH100",
                       1,"NVRM: GPU %d Assigning Peer %d to first available LCE %d\n",
                       *(undefined4 *)(param_2 + 0x7a4),uVar10,*(undefined4 *)(lVar16 + 0x2b8));
        }
        else {
LAB_002ec9cc:
          nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x4e4,"kceGetP2PCes_GH100",
                       1,"NVRM: GPU %d Assigning Peer %d to preferred LCE %d\n",
                       *(undefined4 *)(param_2 + 0x7a4),uVar10,*(undefined4 *)(lVar7 + 0x2b8));
          lVar16 = (&local_60)[uVar1];
        }
        *(int *)(lVar16 + 0x2d8) = 1 << ((byte)local_a4 & 0x1f);
        *param_4 = 1 << ((byte)*(undefined4 *)(lVar16 + 0x2b8) & 0x1f);
        return 0;
      }
    }
    return 0;
  }
  uVar3 = *(uint *)(param_2 + 0x8fc);
  if (4 < uVar3) {
    uVar9 = 0;
    lVar7 = 0;
    uVar15 = 4;
    do {
      if (((uVar15 < 0x14) && (lVar14 = *(long *)(param_2 + 0x1c30 + uVar15 * 8), lVar14 != 0)) &&
         ((*(int *)(lVar14 + 700) == *(int *)(param_1 + 700) && (*(char *)(lVar14 + 0x2d5) == '\0'))
         )) {
        uVar5 = *(uint *)(lVar14 + 0x2b8);
        uVar6 = uVar5 + 0x2a;
        if (uVar5 < 10) {
          uVar6 = uVar5 + 9;
        }
        local_60 = (ulong)uVar6;
        iVar4 = knvlinkExecGspRmRpc_IMPL(param_2,lVar16,0x20802a02,&local_60,8);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,"rmStatus","src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x43b);
          return iVar4;
        }
        uVar5 = local_60._4_4_ - (local_60._4_4_ >> 1 & 0x55555555);
        uVar5 = (uVar5 & 0x33333333) + (uVar5 >> 2 & 0x33333333);
        uVar5 = ((uVar5 >> 4) + uVar5 & 0xf0f0f0f) * 0x1010101 >> 0x18;
        if (uVar9 < uVar5) {
          lVar7 = lVar14;
          uVar9 = uVar5;
        }
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 != uVar3);
    if (lVar7 != 0) {
      if (*(int *)(lVar7 + 0x2d8) == 0) {
        *(undefined4 *)(lVar7 + 0x2d8) = 1;
      }
      nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x454,"kceGetP2PCes_GH100",1,
                   "NVRM: GPU %d Assigning Peer %d to LCE %d\n",*(undefined4 *)(param_2 + 0x7a4),0,
                   *(undefined4 *)(lVar7 + 0x2b8));
      *param_4 = 1 << ((byte)*(undefined4 *)(lVar7 + 0x2b8) & 0x1f);
    }
  }
  return 0;
}


// ===== 002ecb20 kceGetMappingsForMIGGpuInstance_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kceGetMappingsForMIGGpuInstance_GH100
                (undefined8 param_1,long param_2,uint param_3,long param_4)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c [3];
  
  uVar8 = (ulong)param_3;
  local_50 = 0;
  local_4c = 0;
  cVar2 = gpuIsCCFeatureEnabled_IMPL();
  if (cVar2 == '\0') {
    uVar3 = param_3 - (param_3 >> 1 & 0x55555555);
    uVar3 = (uVar3 >> 2 & 0x33333333) + (uVar3 & 0x33333333);
    uVar3 = ((uVar3 >> 4) + uVar3 & 0xf0f0f0f) * 0x1010101 >> 0x18;
    kceGetPceConfigForLceMIGGpuInstance_IMPL
              (param_1,param_2,param_3 & 0x55555554,uVar3,&local_50,&local_48,&local_44,local_3c);
    kceGetPceConfigForLceMIGGpuInstance_IMPL
              (param_1,param_2,param_3 & 0xaaaaaaa8,uVar3,&local_4c,&local_48,&local_40,local_3c);
    uVar9 = local_50 | local_4c;
    uVar3 = uVar9 - (uVar9 >> 1 & 0x55555555);
    uVar3 = (uVar3 & 0x33333333) + (uVar3 >> 2 & 0x33333333);
    if (local_48 < ((uVar3 >> 4) + uVar3 & 0xf0f0f0f) * 0x1010101 >> 0x18) {
      if (local_44 != 0) {
        iVar7 = 0;
        uVar3 = local_44;
joined_r0x002ecd09:
        for (; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1) {
          iVar7 = iVar7 + 1;
        }
        if (local_3c[0] != 0) {
          uVar9 = 0;
          do {
            while( true ) {
              uVar10 = 0;
              for (uVar4 = local_50; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1 | 0x80000000) {
                uVar10 = uVar10 + 1;
              }
              if (local_50 - 1 < 0xfffffffe) break;
              if (local_50 != 0) {
                uVar10 = 0xffffffff;
                break;
              }
LAB_002ecd30:
              uVar9 = uVar9 + 1;
              if (local_3c[0] <= uVar9) goto LAB_002ecd85;
            }
            uVar4 = (**(code **)(param_2 + 0x220))(param_2);
            if (uVar4 < uVar10) goto LAB_002ecd30;
            uVar9 = uVar9 + 1;
            local_50 = local_50 & ~(1 << ((byte)uVar10 & 0x1f));
            *(int *)(param_4 + (ulong)uVar10 * 4) = iVar7;
          } while (uVar9 < local_3c[0]);
        }
LAB_002ecd85:
        uVar3 = uVar3 >> 1;
        if (uVar3 != 0) {
          iVar7 = iVar7 + 1;
          goto joined_r0x002ecd09;
        }
      }
      uVar8 = (ulong)local_40;
      if (local_40 != 0) {
        iVar7 = 0;
        do {
          uVar3 = (uint)uVar8;
          while ((uVar8 & 1) == 0) {
            uVar8 = uVar8 >> 1;
            uVar3 = (uint)uVar8;
            iVar7 = iVar7 + 1;
          }
          if (local_3c[0] != 0) {
            uVar9 = 0;
            do {
              while( true ) {
                uVar10 = 0;
                for (uVar4 = local_4c; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1 | 0x80000000) {
                  uVar10 = uVar10 + 1;
                }
                if (local_4c - 1 < 0xfffffffe) break;
                if (local_4c != 0) {
                  uVar10 = 0xffffffff;
                  break;
                }
LAB_002ecdd4:
                uVar9 = uVar9 + 1;
                if (local_3c[0] <= uVar9) goto LAB_002ece24;
              }
              uVar4 = (**(code **)(param_2 + 0x220))(param_2);
              if (uVar4 < uVar10) goto LAB_002ecdd4;
              uVar9 = uVar9 + 1;
              local_4c = local_4c & ~(1 << ((byte)uVar10 & 0x1f));
              *(int *)(param_4 + (ulong)uVar10 * 4) = iVar7;
            } while (uVar9 < local_3c[0]);
          }
LAB_002ece24:
          uVar8 = (ulong)(uVar3 >> 1);
          if (uVar3 >> 1 == 0) {
            return 0;
          }
          iVar7 = iVar7 + 1;
        } while( true );
      }
    }
    else {
      iVar7 = 0;
      if (param_3 != 0) {
        do {
          uVar3 = (uint)uVar8;
          if ((uVar8 & 1) != 0) {
            do {
              uVar3 = 0;
              for (uVar10 = uVar9; (uVar10 & 1) == 0; uVar10 = uVar10 >> 1 | 0x80000000) {
                uVar3 = uVar3 + 1;
              }
              uVar6 = (ulong)uVar3;
              if (0xfffffffd < uVar9 - 1) {
                uVar6 = 0xffffffff;
              }
              uVar3 = (**(code **)(param_2 + 0x220))(param_2);
              if ((uint)uVar6 <= uVar3) {
                bVar1 = (byte)uVar6 & 0x1f;
                uVar9 = uVar9 & (-2 << bVar1 | 0xfffffffeU >> 0x20 - bVar1);
                *(int *)(param_4 + uVar6 * 4) = iVar7;
              }
              uVar3 = (uint)uVar8 >> 1;
              uVar8 = (ulong)uVar3;
              if (uVar3 == 0) {
                return 0;
              }
              iVar7 = iVar7 + 1;
            } while ((uVar3 & 1) != 0);
          }
          iVar7 = iVar7 + 1;
          uVar8 = (ulong)(uVar3 >> 1);
        } while( true );
      }
    }
  }
  else {
    local_3c[0] = 0;
    uVar8 = 0x51;
    lVar5 = portMemAllocNonPaged(8);
    if (lVar5 != 0) {
      uVar8 = 0;
      kceMapPceLceForCC_isra_0(param_1,param_2,param_4,lVar5,local_3c);
      portMemFree(lVar5);
    }
  }
  return uVar8;
}


// ===== 002ece50 kceIsSecureCe_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kceIsSecureCe_GH100(long param_1,long param_2)

{
  uint uVar1;
  int local_20;
  byte local_1b;
  
  if (*(char *)(param_2 + 0x2d5) == '\0') {
    portMemSet(&local_20,0,8);
    uVar1 = *(uint *)(param_2 + 0x2b8);
    local_20 = uVar1 + 0x2a;
    if (uVar1 < 10) {
      local_20 = uVar1 + 9;
    }
    uVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20802a07,&local_20,8);
    if (uVar1 == 0) {
      uVar1 = (int)(uint)local_1b >> 2 & 1;
    }
    else {
      nvAssertOkFailedNoLog
                (uVar1,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_CE_GET_PHYSICAL_CAPS, &physicalCaps, sizeof(physicalCaps))"
                 ,"src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x588);
    }
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/ce/arch/hopper/kernel_ce_gh100.c",0x580,"kceIsSecureCe_GH100",1,
               "NVRM: Skipping stubbed CE %d\n",*(undefined4 *)(param_2 + 0x2b8));
  return 0;
}


// ===== 002ecf40 kceStateLoad_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kceStateLoad_GP100(long param_1,long param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  undefined1 *extraout_RDX;
  undefined1 *puVar6;
  ulong uVar7;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [8];
  
  iVar2 = kceFindShimOwner_IMPL(param_1,param_2,local_30);
  if (iVar2 == 0) {
    if (*(char *)(param_1 + 0x908) == '\0') {
      if (*(char *)(param_2 + 0x2d4) == '\0') {
        cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
        goto joined_r0x002ed0e7;
      }
      goto LAB_002ecf88;
    }
  }
  else {
    *(undefined1 *)(param_2 + 0x2d4) = 1;
    if (*(char *)(param_1 + 0x908) == '\0') {
LAB_002ecf88:
      *(undefined1 *)(param_2 + 0x2cc) = 0;
      if ((param_3 & 1) == 0) {
        lVar5 = portMemAllocNonPaged(0x80);
        *(long *)(param_2 + 0x2c0) = lVar5;
        if (lVar5 == 0) {
          return 0x51;
        }
      }
      puVar6 = local_38;
      uVar3 = kceGetPceConfigForLceType_IMPL
                        (param_1,param_2,2,local_44,local_40,&local_3c,puVar6,local_34);
      if (uVar3 != 0) {
        nvAssertOkFailedNoLog
                  (uVar3,
                   "kceGetPceConfigForLceType(pGpu, pKCe, NV2080_CTRL_CE_LCE_TYPE_DECOMP, &numPcesPerLce, &numLces, &supportedPceMask, &supportedLceMask, &pcesPerHshub)"
                   ,"src/kernel/gpu/ce/arch/pascal/kernel_ce_gp100.c",0x3e);
        return (ulong)uVar3;
      }
      *(undefined4 *)(param_2 + 0x2c8) = 0;
      *(undefined4 *)(param_2 + 0x2d0) = local_3c;
      uVar3 = *(uint *)(param_1 + 0x8fc);
      if (uVar3 != 0) {
        uVar7 = 0;
        do {
          if ((((uVar7 < 0x14) && (lVar5 = *(long *)(param_1 + 0x1c30 + uVar7 * 8), lVar5 != 0)) &&
              (*(char *)(lVar5 + 0x2d4) != '\0')) &&
             (uVar4 = kceTopLevelPceLceMappingsUpdate_IMPL(param_1,lVar5,puVar6),
             puVar6 = extraout_RDX, uVar4 != 0)) {
            nvAssertOkFailedNoLog
                      (uVar4,"kceTopLevelPceLceMappingsUpdate(pGpu, pKCeIter)",
                       "src/kernel/gpu/ce/arch/pascal/kernel_ce_gp100.c",0x4d);
            return (ulong)uVar4;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 != uVar3);
      }
    }
  }
  cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
joined_r0x002ed0e7:
  if ((cVar1 == '\0') || (cVar1 = (**(code **)(param_2 + 0x1a0))(param_1,param_2), cVar1 == '\0')) {
    uVar7 = 0;
  }
  else if (*(int *)(param_2 + 0x2b8) + 0xfU < 0x23) {
    uVar7 = (**(code **)(*(long *)(param_1 + 0x1d18) + 0x1b8))();
    if ((int)uVar7 != 0) {
      nvAssertOkFailedNoLog
                (uVar7 & 0xffffffff,"confComputeDeriveSecrets(pCC, mcEngineIdx)",
                 "src/kernel/gpu/ce/arch/pascal/kernel_ce_gp100.c",0x5c);
      uVar7 = uVar7 & 0xffffffff;
    }
  }
  else {
    nvAssertFailedNoLog("mcEngineIdx <= MC_ENGINE_IDX_CE_MAX",
                        "src/kernel/gpu/ce/arch/pascal/kernel_ce_gp100.c",0x5a);
    uVar7 = 0x56;
  }
  return uVar7;
}


// ===== 002ed190 kceStateUnload_GP100 =====

undefined8 kceStateUnload_GP100(long param_1,long param_2,uint param_3)

{
  if ((((param_3 & 1) == 0) && (*(char *)(param_1 + 0x908) == '\0')) &&
     (*(char *)(param_2 + 0x2d4) != '\0')) {
    portMemFree(*(undefined8 *)(param_2 + 0x2c0));
    *(undefined8 *)(param_2 + 0x2c0) = 0;
    return 0;
  }
  return 0;
}


// ===== 002ed1e0 kceIsCeSysmemRead_GP100 =====

bool kceIsCeSysmemRead_GP100(long param_1,long param_2)

{
  int iVar1;
  int local_20;
  undefined1 local_1c [12];
  
  local_20 = *(int *)(param_1 + 0x8fc);
  iVar1 = kceGetCeFromNvlinkConfig_IMPL
                    (param_1,param_2,1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f),&local_20,
                     local_1c,0);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,
               "kceGetCeFromNvlinkConfig(pGpu, pKCe, gpuMask, &sysmemReadCE, &sysmemWriteCE, NULL)",
               "src/kernel/gpu/ce/arch/pascal/kernel_ce_gp100.c",0x89);
  }
  return *(int *)(param_2 + 0x2b8) == local_20;
}


// ===== 002ed250 kceIsCeSysmemWrite_GP100 =====

bool kceIsCeSysmemWrite_GP100(long param_1,long param_2)

{
  undefined1 local_20 [4];
  int local_1c [3];
  
  local_1c[0] = *(int *)(param_1 + 0x8fc);
  kceGetCeFromNvlinkConfig_IMPL
            (param_1,param_2,1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f),local_20,local_1c,
             0);
  return *(int *)(param_2 + 0x2b8) == local_1c[0];
}


// ===== 002ed2a0 kceIsCeNvlinkP2P_GP100 =====

undefined4 kceIsCeNvlinkP2P_GP100(long param_1,long param_2)

{
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  uint local_1c [3];
  
  local_1c[0] = 0;
  kceGetCeFromNvlinkConfig_IMPL
            (param_1,param_2,1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f),local_24,local_20,
             local_1c);
  return CONCAT31((int3)(*(uint *)(param_2 + 0x2b8) >> 8),
                  (local_1c[0] >> (*(uint *)(param_2 + 0x2b8) & 0x1f) & 1) != 0);
}


// ===== 002ed2f0 kceGetNvlinkMaxTopoForTable_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kceGetNvlinkMaxTopoForTable_GP100
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5,
          undefined4 *param_6)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c [3];
  
  local_48 = 0;
  local_44 = 0;
  lVar3 = portMemAllocNonPaged(0x134);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pCachedTopo != NULL","src/kernel/gpu/ce/arch/pascal/kernel_ce_gp100.c",0xeb
                       );
    return 0;
  }
  gpumgrGetSystemNvlinkTopo_IMPL(*(undefined8 *)(param_1 + 0x878),lVar3);
  cVar1 = (**(code **)(param_2 + 0x210))(param_1,param_2,lVar3,param_4,param_5,&local_48,local_3c);
  uVar2 = (**(code **)(param_2 + 0x210))
                    (param_1,param_2,param_3,param_4,param_5,&local_44,&local_40);
  if (cVar1 == '\0') {
LAB_002ed430:
    if ((char)uVar2 == '\0') goto LAB_002ed405;
    *param_6 = local_44;
  }
  else {
    if ((char)uVar2 == '\0') {
      if (cVar1 == '\0') goto LAB_002ed430;
    }
    else if ((~local_40 & local_3c[0]) == 0) {
      *param_6 = local_44;
      if (local_40 != local_3c[0]) {
        (**(code **)(param_2 + 0x208))(param_1,param_2,0x2ed357);
      }
      goto LAB_002ed3ff;
    }
    *param_6 = local_48;
  }
LAB_002ed3ff:
  uVar2 = 1;
LAB_002ed405:
  portMemFree(lVar3);
  return uVar2;
}


// ===== 002ed460 kceAssignCeCaps_GP100 =====

void kceAssignCeCaps_GP100(long param_1)

{
  if (*(long *)(param_1 + 0x1ce8) != 0) {
    kceGetNvlinkCaps_IMPL();
    return;
  }
  return;
}


// ===== 002ed480 kceGetNvlinkAutoConfigCeValues_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kceGetNvlinkAutoConfigCeValues_TU102
          (long param_1,long param_2,undefined4 *param_3,long param_4,undefined4 *param_5)

{
  undefined1 uVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  uint uVar11;
  undefined8 uVar12;
  int local_5c;
  bool local_51;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c [3];
  
  lVar10 = *(long *)(param_1 + 0x1ce8);
  local_44 = 0;
  local_40 = 0;
  local_3c[0] = 0;
  uVar6 = (**(code **)(param_2 + 0x220))(param_2);
  uVar3 = (**(code **)(param_2 + 0x218))(param_2);
  if ((param_4 == 0 || param_5 == (undefined4 *)0x0) || (param_3 == (undefined4 *)0x0)) {
    puVar7 = (undefined4 *)0x0;
    uVar12 = 0x1f;
  }
  else if (lVar10 == 0) {
    puVar7 = (undefined4 *)0x0;
    uVar12 = 0x56;
  }
  else {
    puVar7 = (undefined4 *)portMemAllocNonPaged(0x134);
    if (puVar7 == (undefined4 *)0x0) {
      nvAssertFailedNoLog("pCurrentTopo != NULL","src/kernel/gpu/ce/arch/turing/kernel_ce_tu102.c",
                          0x68);
      return 0x51;
    }
    uVar12 = 0x56;
    portMemSet(puVar7,0,0x134);
    uVar4 = knvlinkGetNumLinksToSystem_IMPL(param_1,lVar10);
    if (*(int *)(param_1 + 0x8fc) != 0) {
      gpumgrGetGpuAttachInfo(0,&local_44);
      local_51 = true;
      local_5c = 0;
      uVar11 = 0;
      while (lVar8 = gpumgrGetNextGpu(local_44,&local_40), lVar8 != 0) {
        uVar5 = knvlinkGetNumLinksToPeer_IMPL(param_1,lVar10,lVar8);
        if (uVar5 != 0) {
          local_5c = local_5c + 1;
          if (local_51 != false) {
            local_51 = uVar11 == 0 || uVar11 == uVar5;
          }
          if (uVar11 < uVar5) {
            uVar11 = uVar5;
          }
        }
      }
      puVar7[1] = uVar11;
      *puVar7 = uVar4;
      puVar7[4] = local_5c;
      *(bool *)(puVar7 + 2) = local_51;
      uVar1 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_1,lVar10);
      *(undefined1 *)(puVar7 + 5) = uVar1;
      cVar2 = (**(code **)(param_2 + 0x1f8))
                        (param_1,param_2,puVar7,&nvLinkCeAutoConfigTable_TU102,3,local_3c);
      if (cVar2 == '\0') {
        nvDbg_Printf("src/kernel/gpu/ce/arch/turing/kernel_ce_tu102.c",0x9e,
                     "kceGetNvlinkAutoConfigCeValues_TU102",1,
                     "NVRM: GPU%d : NVLINK config not found in PCE2LCE table - using default entry\n"
                     ,*(undefined4 *)(param_1 + 0x7a4));
        local_3c[0] = 0;
        uVar9 = 0;
      }
      else {
        uVar9 = (ulong)local_3c[0];
      }
      *puVar7 = (&nvLinkCeAutoConfigTable_TU102)[uVar9 * 0x35];
      lVar10 = (ulong)local_3c[0] * 0xd4;
      puVar7[1] = *(undefined4 *)(&DAT_0059e4e4 + lVar10);
      puVar7[4] = *(undefined4 *)(&DAT_0059e4e8 + lVar10);
      *(undefined *)(puVar7 + 2) = (&DAT_0059e4ec)[lVar10];
      *(undefined *)(puVar7 + 5) = (&DAT_0059e4ed)[lVar10];
      gpumgrUpdateSystemNvlinkTopo_IMPL(*(undefined8 *)(param_1 + 0x878),puVar7);
      if (uVar6 != 0) {
        lVar10 = 0;
        do {
          *(undefined4 *)((long)param_3 + lVar10) =
               *(undefined4 *)(&DAT_0059e4f0 + lVar10 + (ulong)local_3c[0] * 0xd4);
          lVar10 = lVar10 + 4;
        } while (lVar10 != (ulong)uVar6 << 2);
      }
      if (uVar3 != 0) {
        lVar10 = 0;
        do {
          uVar6 = *(uint *)(&DAT_0059e550 + lVar10 + (ulong)local_3c[0] * 0xd4) & 0xf | 0x40000000;
          if (*(uint *)(&DAT_0059e550 + lVar10 + (ulong)local_3c[0] * 0xd4) == 0xf) {
            uVar6 = 0;
          }
          *(uint *)(param_4 + lVar10) = uVar6;
          lVar10 = lVar10 + 4;
        } while (lVar10 != (ulong)uVar3 << 2);
      }
      lVar10 = (ulong)local_3c[0] * 0xd4;
      uVar12 = 0;
      uVar4 = *(undefined4 *)(&DAT_0059e5b0 + lVar10);
      *param_5 = uVar4;
      nvDbg_Printf("src/kernel/gpu/ce/arch/turing/kernel_ce_tu102.c",200,
                   "kceGetNvlinkAutoConfigCeValues_TU102",1,
                   "NVRM: GPU%d : RM Configured Values for CE Config : pceLceMap = 0x%01x%01x%01x%01x%01x%01x%01x%01x%01x, grceConfig = 0x%01x%01x, exposeCeMask = 0x%08x gpuMask = 0x%08x\n"
                   ,*(undefined4 *)(param_1 + 0x7a4),param_3[8],param_3[7],param_3[6],param_3[5],
                   param_3[4],param_3[3],param_3[2],param_3[1],*param_3,
                   *(undefined4 *)(&DAT_0059e554 + lVar10),*(undefined4 *)(&DAT_0059e550 + lVar10),
                   uVar4,local_44);
    }
  }
  portMemFree(puVar7);
  return uVar12;
}


// ===== 002ed870 kceGetGrceConfigSize1_TU102 =====

undefined8 kceGetGrceConfigSize1_TU102(void)

{
  return 2;
}


// ===== 002ed880 kceGetPce2lceConfigSize1_TU102 =====

undefined8 kceGetPce2lceConfigSize1_TU102(void)

{
  return 4;
}


// ===== 002ed8a0 kceGetP2PCes_GV100 =====

int kceGetP2PCes_GV100(long param_1,long param_2,undefined4 param_3,uint *param_4)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  long lVar14;
  long local_78;
  long local_70;
  long local_68;
  uint local_44;
  int local_40;
  uint local_3c;
  
  iVar5 = gpumgrGetSubDeviceCount(param_3);
  *param_4 = 0;
  if (iVar5 == 1) {
    *param_4 = 0x10;
    uVar6 = 0x10;
    uVar11 = 4;
    if (*(uint *)(param_2 + 0x8fc) < 5) {
      return 0;
    }
    do {
      bVar10 = (byte)uVar11;
      uVar11 = uVar11 + 1;
      uVar6 = uVar6 | 1 << (bVar10 & 0x1f);
      *param_4 = uVar6;
    } while (uVar11 < *(uint *)(param_2 + 0x8fc));
    return 0;
  }
  lVar1 = *(long *)(param_2 + 0x1ce8);
  local_44 = 0;
  if (lVar1 != 0) {
    cVar4 = knvlinkIsGpuConnectedToNvswitch_IMPL(param_2,lVar1);
    do {
      lVar9 = gpumgrGetNextGpu(param_3,&local_44);
      if (lVar9 == 0) {
        nvAssertFailedNoLog("pRemoteGpu != NULL","src/kernel/gpu/ce/arch/volta/kernel_ce_gv100.c",
                            0x49);
        return 0x40;
      }
    } while (param_2 == lVar9);
    local_44 = *(uint *)(lVar9 + 0x7a4);
    uVar6 = knvlinkGetNumLinksToPeer_IMPL(param_2,lVar1,lVar9);
    if (uVar6 != 0) {
      uVar11 = *(uint *)(param_2 + 0x8fc);
      if (4 < uVar11) {
        local_78 = 0;
        uVar13 = 4;
        local_70 = 0;
        uVar2 = 0;
        local_68 = 0;
LAB_002ed9c0:
        do {
          lVar9 = local_68;
          if ((((uVar13 < 0x14) && (lVar14 = *(long *)(param_2 + 0x1c30 + uVar13 * 8), lVar14 != 0))
              && (*(int *)(lVar14 + 700) == *(int *)(param_1 + 700))) &&
             (*(char *)(lVar14 + 0x2d5) == '\0')) {
            uVar7 = *(uint *)(lVar14 + 0x2b8);
            local_3c = 0;
            local_40 = uVar7 + 0x2a;
            if (uVar7 < 10) {
              local_40 = uVar7 + 9;
            }
            iVar5 = knvlinkExecGspRmRpc_IMPL(param_2,lVar1,0x20802a02,&local_40,8);
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,"rmStatus","src/kernel/gpu/ce/arch/volta/kernel_ce_gv100.c",0x6a);
              return iVar5;
            }
            uVar7 = local_3c - (local_3c >> 1 & 0x55555555);
            uVar12 = (uVar7 & 0x33333333) + (uVar7 >> 2 & 0x33333333);
            uVar7 = *(uint *)(lVar14 + 0x2d8);
            uVar8 = ((uVar12 >> 4) + uVar12 & 0xf0f0f0f) * 0x1010101 >> 0x18;
            lVar3 = local_78;
            uVar12 = uVar2;
            if ((uVar2 < uVar8) && (lVar3 = lVar14, uVar12 = uVar8, cVar4 == '\0')) {
              if (uVar7 == 0) {
                local_78 = lVar14;
                uVar2 = uVar8;
                if (uVar6 != uVar8) goto LAB_002edb9c;
LAB_002edab0:
                lVar9 = lVar14;
                if (local_68 != 0) {
                  lVar9 = local_68;
                }
              }
              else if ((uVar7 >> (local_44 & 0x1f) & 1) != 0) goto LAB_002edb09;
            }
            else {
              local_78 = lVar3;
              if ((uVar7 >> (local_44 & 0x1f) & 1) != 0) {
                if (cVar4 == '\0') goto LAB_002edb09;
                goto LAB_002edcdc;
              }
              uVar2 = uVar12;
              if (uVar7 == 0) {
                if (uVar6 == uVar8) goto LAB_002edab0;
LAB_002edb9c:
                if (uVar8 < uVar6) {
                  if (local_70 != 0) {
                    lVar14 = local_70;
                  }
                  uVar13 = uVar13 + 1;
                  local_70 = lVar14;
                  if (uVar13 == uVar11) break;
                  goto LAB_002ed9c0;
                }
              }
            }
          }
          local_68 = lVar9;
          uVar13 = uVar13 + 1;
        } while (uVar13 != uVar11);
        if (((local_68 == 0) || (lVar14 = local_68, cVar4 != '\0')) &&
           ((local_70 == 0 || (lVar14 = local_70, cVar4 != '\0')))) {
LAB_002edcdc:
          lVar14 = local_78;
          if (local_78 == 0) {
            return 0;
          }
        }
        if (*(int *)(lVar14 + 0x2d8) == 0) {
          *(int *)(lVar14 + 0x2d8) = 1 << ((byte)local_44 & 0x1f);
        }
LAB_002edb09:
        nvDbg_Printf("src/kernel/gpu/ce/arch/volta/kernel_ce_gv100.c",0xb2,"kceGetP2PCes_GV100",1,
                     "NVRM: GPU %d Assigning Peer %d to LCE %d\n",*(undefined4 *)(param_2 + 0x7a4),
                     local_44,*(undefined4 *)(lVar14 + 0x2b8));
        *param_4 = 1 << ((byte)*(undefined4 *)(lVar14 + 0x2b8) & 0x1f);
      }
      return 0;
    }
  }
  *param_4 = 8;
  nvDbg_Printf("src/kernel/gpu/ce/arch/volta/kernel_ce_gv100.c",0x56,"kceGetP2PCes_GV100",1,
               "NVRM: GPU %d Peer %d has no links (could be an indirect peer). Sysmem LCE assigned %d!\n"
               ,*(undefined4 *)(param_2 + 0x7a4),local_44,3);
  return 0;
}


// ===== 002edd10 kceGetSysmemRWLCEs_GV100 =====

void kceGetSysmemRWLCEs_GV100
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_3 = 2;
  *param_4 = 3;
  return;
}


// ===== 002edd40 kceGetAutoConfigTableEntry_GV100 =====

undefined8
kceGetAutoConfigTableEntry_GV100
          (undefined8 param_1,undefined8 param_2,int *param_3,int *param_4,int param_5,int *param_6,
          int *param_7)

{
  int iVar1;
  
  if (param_5 != 0) {
    iVar1 = 0;
    do {
      if ((((*param_4 == *param_3) && (param_4[1] == param_3[1])) &&
          ((char)param_4[3] == (char)param_3[2])) &&
         ((*(char *)((long)param_4 + 0xd) == (char)param_3[5] &&
          ((param_4[2] == param_3[4] || ((char)param_3[5] != '\0')))))) {
        *param_6 = iVar1;
        *param_7 = param_4[0x34];
        return 1;
      }
      iVar1 = iVar1 + 1;
      param_4 = param_4 + 0x35;
    } while (param_5 != iVar1);
  }
  return 0;
}


// ===== 002eddd0 kceClearAssignedNvlinkPeerMasks_GV100 =====

void kceClearAssignedNvlinkPeerMasks_GV100(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x8fc);
  if (4 < uVar1) {
    uVar3 = 4;
    do {
      if (((uVar3 < 0x14) && (lVar2 = *(long *)(param_1 + 0x1c30 + uVar3 * 8), lVar2 != 0)) &&
         (*(int *)(lVar2 + 700) == *(int *)(param_2 + 700))) {
        *(undefined4 *)(lVar2 + 0x2d8) = 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar1 != uVar3);
  }
  return;
}


// ===== 002ede30 spdmSendTestCommand.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmSendTestCommand_constprop_0
              (long param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined8 param_6,undefined8 param_7,char param_8)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar7;
  undefined1 local_1a0 [24];
  undefined8 local_188 [18];
  undefined8 local_f8;
  undefined8 local_f0 [7];
  undefined1 local_b8 [68];
  undefined1 local_74 [16];
  undefined1 local_64 [20];
  int local_50;
  ulong uVar6;
  
  lVar4 = rmapiGetInterface(4);
  lVar1 = *(long *)(param_1 + 0x1d10);
  uVar5 = 0;
  do {
    uVar2 = (int)uVar5 + 0x20;
    uVar6 = (ulong)uVar2;
    *(undefined8 *)((long)local_188 + uVar5) = 0;
    *(undefined8 *)((long)local_188 + uVar5 + 8) = 0;
    *(undefined8 *)((long)local_188 + uVar5 + 0x10) = 0;
    *(undefined8 *)((long)local_188 + uVar5 + 0x18) = 0;
    uVar5 = uVar6;
  } while (uVar2 < 0x80);
  *(undefined8 *)((long)local_188 + uVar6) = 0;
  *(undefined8 *)((long)local_188 + uVar6 + 8) = 0;
  uVar2 = 0;
  do {
    uVar5 = (ulong)uVar2;
    uVar2 = uVar2 + 0x20;
    *(undefined8 *)((long)&local_f8 + uVar5) = 0;
    *(undefined8 *)((long)local_f0 + uVar5) = 0;
    *(undefined8 *)((long)local_f0 + uVar5 + 8) = 0;
    *(undefined8 *)((long)local_f0 + uVar5 + 0x10) = 0;
  } while (uVar2 < 0xc0);
  iVar3 = (**(code **)(lVar4 + 0x38))(lVar4,*param_2,param_2[2],0xc56f010b,local_188,0x90);
  uVar7 = 0x82;
  if (iVar3 == 0) {
    if ((lVar1 == 0) || (*(char *)(lVar1 + 0x23c) == '\0')) {
      return 0x1f;
    }
    portMemCopy(local_f0,0x7c,local_188,0x7c);
    if (param_8 == '\0') {
      portMemCopy(local_b8,0xc,param_5,0xc);
      portMemCopy(local_74,0x10,param_3,0x10);
      portMemCopy(local_64,0x10,param_4,0x10);
    }
    else {
      portMemCopy(local_74,0x10,param_3,0x10);
    }
    local_f8._4_1_ = 6;
    local_f8._5_1_ = param_8;
    timeoutSet(param_1 + 0x1af0,local_1a0,0,0);
    iVar3 = (**(code **)(lVar1 + 0x1b0))(param_1,lVar1,&local_f8);
    if (iVar3 == 0) {
      if (local_50 != 0) {
        nvAssertOkFailedNoLog(local_50,"status","src/kernel/gpu/ce/kernel_ce.c",0xa0);
        return local_50;
      }
      if (param_8 == '\0') {
        return 0;
      }
      portMemCopy(param_6,param_7,local_74);
      portMemCopy(param_4,0x10,local_64,0x10);
      return 0;
    }
    uVar7 = 0x9b;
  }
  nvAssertOkFailedNoLog(iVar3,"status","src/kernel/gpu/ce/kernel_ce.c",uVar7);
  return iVar3;
}


// ===== 002ee100 kceRunFipsSelfTestEncrypt =====

int kceRunFipsSelfTestEncrypt(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 extraout_RDX;
  undefined8 uVar9;
  undefined8 local_1a0;
  undefined8 local_198;
  undefined8 local_190;
  undefined8 local_188;
  long local_180;
  undefined8 local_178;
  undefined8 local_16c;
  undefined4 local_164;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  ulong local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [9];
  undefined1 local_40;
  undefined1 local_3f;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar3 = 0;
  lVar1 = *(long *)(param_1 + 0x1b78);
  local_1a0 = 0;
  local_198 = 0;
  uVar7 = *(undefined8 *)(param_1 + 0x1bc0);
  local_190 = 0;
  local_188 = 0;
  local_180 = 0;
  local_178 = 0;
  local_120 = 0;
  local_118 = 0;
  local_110 = 0;
  do {
    uVar8 = (ulong)uVar3;
    uVar3 = uVar3 + 0x20;
    *(undefined8 *)((long)local_88 + uVar8) = 0;
    *(undefined8 *)((long)local_88 + uVar8 + 8) = 0;
    *(undefined8 *)((long)local_88 + uVar8 + 0x10) = 0;
    *(undefined8 *)((long)local_88 + uVar8 + 0x18) = 0;
  } while (uVar3 < 0x60);
  local_16c = 0;
  local_160 = 0xc04a4e91fabc712d;
  local_164 = 0;
  local_158 = 0x24ad5f9560aab245;
  local_150 = 0;
  local_148 = 0;
  local_140 = 0;
  local_138 = 0;
  local_130 = 0;
  local_128 = 0;
  cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("gpuIsCCFeatureEnabled(pGpu)","src/kernel/gpu/ce/kernel_ce.c",0x147);
    return 0x56;
  }
  cVar2 = gpuCheckEngineTable_IMPL(param_1,*(int *)(param_2 + 0x2b8) + 9);
  if ((cVar2 == '\0') || (cVar2 = ceIsCeGrce(param_1,*(int *)(param_2 + 0x2b8) + 9), cVar2 != '\0'))
  {
    return 0;
  }
  cVar2 = kmigmgrIsMIGSupported_IMPL(param_1,uVar7);
  if ((cVar2 != '\0') && (lVar6 = kmigmgrGetStaticInfo_IMPL(param_1,uVar7), lVar6 == 0)) {
    return 0x10005;
  }
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x157,"kceRunFipsSelfTestEncrypt",1,
               "NVRM: Running FIPS test for CE%u\n",*(undefined4 *)(param_2 + 0x2b8));
  local_118 = local_118 | 0x30;
  local_110 = CONCAT44(local_110._4_4_,*(undefined4 *)(param_2 + 0x2b8));
  if (lVar1 == 0) {
    uVar7 = gpuEngineGetGpu(0);
    lVar6 = 0;
  }
  else {
    uVar7 = gpuEngineGetGpu(*(undefined8 *)(lVar1 + 0x150));
    lVar6 = lVar1;
  }
  iVar4 = __nvoc_objCreate_CeUtils(&local_180,lVar6,0,uVar7,0,&local_120);
  if (iVar4 == 0) {
    lVar6 = *(long *)(local_180 + 0x50);
    iVar4 = ccslContextInitViaChannel_IMPL
                      (&local_178,*(undefined4 *)(lVar6 + 0xac),*(undefined4 *)(lVar6 + 0xc),
                       *(undefined4 *)(lVar6 + 8));
    if (iVar4 == 0) {
      iVar4 = memdescCreate(&local_1a0,param_1,0x10,0,1,2,1,0x80);
      if (iVar4 == 0) {
        iVar4 = memdescAlloc(local_1a0);
        if (iVar4 == 0) {
          iVar4 = memdescCreate(&local_198,param_1,0x10,0,1,1,1,0x200000000000);
          if (iVar4 == 0) {
            iVar4 = memdescAlloc(local_198);
            if (iVar4 == 0) {
              uVar7 = 0x200000000000;
              iVar4 = memdescCreate(&local_190,param_1,0x10,0,1,1,1);
              if (iVar4 == 0) {
                iVar4 = memdescAlloc(local_190);
                if (iVar4 == 0) {
                  uVar9 = 0x200000000000;
                  uVar7 = 1;
                  iVar4 = memdescCreate(&local_188,param_1,0xc,0,1,1);
                  if (iVar4 == 0) {
                    iVar4 = memdescAlloc(local_188,uVar9,extraout_RDX,uVar7);
                    if (iVar4 == 0) {
                      local_100 = 0;
                      local_108 = local_1a0;
                      local_f8 = 0;
                      local_c8 = local_190;
                      local_f0 = 0;
                      local_e0 = 0;
                      local_d8 = 0;
                      local_d0 = 0;
                      local_e8 = local_198;
                      local_c0 = 0;
                      local_b8 = 0;
                      local_b0 = 0;
                      local_a0 = 0;
                      local_98 = 0;
                      local_90 = 0;
                      local_a8 = local_188;
                      iVar4 = memmgrMemDescMemSet_IMPL(lVar1,local_198,0,0);
                      if (iVar4 == 0) {
                        iVar4 = memmgrMemDescMemSet_IMPL(lVar1,local_190,0,0);
                        if (iVar4 == 0) {
                          iVar4 = memmgrMemWrite_IMPL(lVar1,&local_108,&local_160,0x10,0);
                          if (iVar4 == 0) {
                            local_40 = 1;
                            local_38 = memdescGetPhysAddr(local_190,1,0);
                            local_30 = memdescGetPhysAddr(local_188,1,0);
                            local_88[2] = 0;
                            local_88[3] = 0;
                            local_88[1] = local_198;
                            local_88[4] = 0x10;
                            local_88[0] = local_1a0;
                            local_3f = 1;
                            iVar4 = ceutilsMemcopy_IMPL(local_180,local_88);
                            if (iVar4 == 0) {
                              iVar4 = spdmSendTestCommand_constprop_0
                                                (param_1,local_178,&local_160,&local_130,&local_16c,
                                                 &local_140,0x10,1);
                              if (iVar4 == 0) {
                                iVar4 = memmgrMemWrite_IMPL(lVar1,&local_e8,&local_140,0x10,0);
                                if (iVar4 == 0) {
                                  iVar4 = memmgrMemWrite_IMPL(lVar1,&local_c8,&local_130,0x10,0);
                                  if (iVar4 == 0) {
                                    iVar4 = memmgrMemDescMemSet_IMPL(lVar1,local_1a0,0,0);
                                    if (iVar4 == 0) {
                                      iVar4 = memmgrMemRead_IMPL(lVar1,&local_a8,&local_16c,0xc,0);
                                      if (iVar4 == 0) {
                                        local_88[2] = 0;
                                        local_88[3] = 0;
                                        local_88[1] = local_1a0;
                                        local_88[4] = 0x10;
                                        local_88[0] = local_198;
                                        local_3f = 0;
                                        iVar4 = ceutilsMemcopy_IMPL(local_180,local_88);
                                        if (iVar4 == 0) {
                                          iVar4 = memmgrMemRead_IMPL(lVar1,&local_108,&local_150,
                                                                     0x10,0);
                                          if (iVar4 == 0) {
                                            iVar5 = portMemCmp(&local_150,&local_160,0x10);
                                            if (iVar5 != 0) {
                                              nvAssertOkFailedNoLog
                                                        (0x40,
                                                  "portMemCmp(decryptedData, ceTestPlaintext, sizeof ceTestPlaintext) == 0"
                                                  ,"src/kernel/gpu/ce/kernel_ce.c",0x1a4);
                                              iVar4 = 0x40;
                                            }
                                          }
                                          else {
                                            nvAssertOkFailedNoLog
                                                      (iVar4,
                                                  "memmgrMemRead(pMemoryManager, &srcSurface, decryptedData, sizeof decryptedData, TRANSFER_FLAGS_NONE)"
                                                  ,"src/kernel/gpu/ce/kernel_ce.c",0x1a1);
                                          }
                                        }
                                        else {
                                          nvAssertOkFailedNoLog
                                                    (iVar4,"ceutilsMemcopy(pCeUtils, &params)",
                                                     "src/kernel/gpu/ce/kernel_ce.c",0x19f);
                                        }
                                      }
                                      else {
                                        nvAssertOkFailedNoLog
                                                  (iVar4,
                                                  "memmgrMemRead(pMemoryManager, &ivSurface, Ivl, sizeof Ivl, TRANSFER_FLAGS_NONE)"
                                                  ,"src/kernel/gpu/ce/kernel_ce.c",0x196);
                                      }
                                    }
                                    else {
                                      nvAssertOkFailedNoLog
                                                (iVar4,
                                                 "memmgrMemDescMemSet(pMemoryManager, pSrcMemDesc, 0, 0)"
                                                 ,"src/kernel/gpu/ce/kernel_ce.c",0x195);
                                    }
                                  }
                                  else {
                                    nvAssertOkFailedNoLog
                                              (iVar4,
                                               "memmgrMemWrite(pMemoryManager, &authSurface, dataAuth, sizeof dataAuth, TRANSFER_FLAGS_NONE)"
                                               ,"src/kernel/gpu/ce/kernel_ce.c",0x193);
                                  }
                                }
                                else {
                                  nvAssertOkFailedNoLog
                                            (iVar4,
                                             "memmgrMemWrite(pMemoryManager, &dstSurface, encryptedData, sizeof encryptedData, TRANSFER_FLAGS_NONE)"
                                             ,"src/kernel/gpu/ce/kernel_ce.c",0x191);
                                }
                              }
                              else {
                                nvAssertOkFailedNoLog
                                          (iVar4,
                                           "spdmSendTestCommand(pGpu, pCcslCtx, ceTestPlaintext, sizeof ceTestPlaintext, dataAuth, sizeof dataAuth, Ivl, sizeof Ivl, encryptedData, sizeof encryptedData, NV_TRUE)"
                                           ,"src/kernel/gpu/ce/kernel_ce.c",0x18d);
                              }
                            }
                            else {
                              nvAssertOkFailedNoLog
                                        (iVar4,"ceutilsMemcopy(pCeUtils, &params)",
                                         "src/kernel/gpu/ce/kernel_ce.c",0x18b);
                            }
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar4,
                                       "memmgrMemWrite(pMemoryManager, &srcSurface, ceTestPlaintext, sizeof ceTestPlaintext, TRANSFER_FLAGS_NONE)"
                                       ,"src/kernel/gpu/ce/kernel_ce.c",0x17e);
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar4,"memmgrMemDescMemSet(pMemoryManager, pAuthMemDesc, 0, 0)"
                                     ,"src/kernel/gpu/ce/kernel_ce.c",0x17d);
                        }
                      }
                      else {
                        nvAssertOkFailedNoLog
                                  (iVar4,"memmgrMemDescMemSet(pMemoryManager, pDstMemDesc, 0, 0)",
                                   "src/kernel/gpu/ce/kernel_ce.c",0x17c);
                      }
                    }
                    else {
                      nvAssertOkFailedNoLog
                                (iVar4,"memdescAlloc(pIvMemDesc)","src/kernel/gpu/ce/kernel_ce.c",
                                 0x174);
                    }
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar4,
                               "memdescCreate(&pIvMemDesc, pGpu, sizeof Ivl, 0, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_ALLOC_IN_UNPROTECTED_MEMORY)"
                               ,"src/kernel/gpu/ce/kernel_ce.c",0x172);
                  }
                }
                else {
                  nvAssertOkFailedNoLog
                            (iVar4,"memdescAlloc(pAuthMemDesc)","src/kernel/gpu/ce/kernel_ce.c",
                             0x170);
                }
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar4,
                           "memdescCreate(&pAuthMemDesc, pGpu, sizeof dataAuth, 0, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_ALLOC_IN_UNPROTECTED_MEMORY)"
                           ,"src/kernel/gpu/ce/kernel_ce.c",0x16e,uVar7);
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar4,"memdescAlloc(pDstMemDesc)","src/kernel/gpu/ce/kernel_ce.c",0x16c);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,
                       "memdescCreate(&pDstMemDesc, pGpu, sizeof encryptedData, 0, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_ALLOC_IN_UNPROTECTED_MEMORY)"
                       ,"src/kernel/gpu/ce/kernel_ce.c",0x16a);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar4,"memdescAlloc(pSrcMemDesc)","src/kernel/gpu/ce/kernel_ce.c",0x168);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "memdescCreate(&pSrcMemDesc, pGpu, sizeof ceTestPlaintext, 0, NV_TRUE, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_ALLOC_FLAGS_PROTECTED)"
                   ,"src/kernel/gpu/ce/kernel_ce.c",0x166);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,
                 "ccslContextInitViaChannel_HAL(&pCcslCtx, pCeUtils->pChannel->hClient, pCeUtils->pChannel->subdeviceId, pCeUtils->pChannel->channelId)"
                 ,"src/kernel/gpu/ce/kernel_ce.c",0x160);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,
               "objCreate(&pCeUtils, pMemoryManager, CeUtils, ENG_GET_GPU(pMemoryManager), NULL, &ceUtilsParams)"
               ,"src/kernel/gpu/ce/kernel_ce.c",0x15d);
  }
  ccslContextClear_IMPL(local_178);
  __nvoc_objDelete(local_180);
  memdescFree(local_1a0);
  memdescDestroy(local_1a0);
  memdescFree(local_198);
  memdescDestroy(local_198);
  memdescFree(local_190);
  memdescDestroy(local_190);
  memdescFree(local_188);
  memdescDestroy(local_188);
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1b3,"kceRunFipsSelfTestEncrypt",1,
               "NVRM: Test finished with status 0x%x\n",iVar4);
  return iVar4;
}


// ===== 002eeb70 kceRunFipsSelfTestDecrypt =====

int kceRunFipsSelfTestDecrypt(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 local_178;
  long local_170;
  undefined8 local_168;
  undefined8 local_15c;
  undefined4 local_154;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  ulong local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [9];
  undefined1 local_40;
  undefined1 local_3f;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar3 = 0;
  lVar1 = *(long *)(param_1 + 0x1b78);
  local_190 = 0;
  local_188 = 0;
  uVar6 = *(undefined8 *)(param_1 + 0x1bc0);
  local_180 = 0;
  local_178 = 0;
  local_170 = 0;
  local_168 = 0;
  local_120 = 0;
  local_118 = 0;
  local_110 = 0;
  do {
    uVar7 = (ulong)uVar3;
    uVar3 = uVar3 + 0x20;
    *(undefined8 *)((long)local_88 + uVar7) = 0;
    *(undefined8 *)((long)local_88 + uVar7 + 8) = 0;
    *(undefined8 *)((long)local_88 + uVar7 + 0x10) = 0;
    *(undefined8 *)((long)local_88 + uVar7 + 0x18) = 0;
  } while (uVar3 < 0x60);
  local_15c = 0;
  local_150 = 0xc04a4e91fabc712d;
  local_154 = 0;
  local_148 = 0x24ad5f9560aab245;
  local_140 = 0;
  local_138 = 0;
  local_130 = 0;
  local_128 = 0;
  cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if (cVar2 != '\0') {
    cVar2 = gpuCheckEngineTable_IMPL(param_1,*(int *)(param_2 + 0x2b8) + 9);
    if (((cVar2 == '\0') ||
        (cVar2 = ceIsCeGrce(param_1,*(int *)(param_2 + 0x2b8) + 9), cVar2 != '\0')) ||
       (cVar2 = kceIsDecompLce_STATIC_DISPATCH(param_1,*(undefined4 *)(param_2 + 0x2b8)),
       cVar2 != '\0')) {
      iVar4 = 0;
    }
    else {
      cVar2 = kmigmgrIsMIGSupported_IMPL(param_1,uVar6);
      if ((cVar2 == '\0') || (lVar5 = kmigmgrGetStaticInfo_IMPL(param_1,uVar6), lVar5 != 0)) {
        nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0xd8,"kceRunFipsSelfTestDecrypt",1,
                     "NVRM: Running FIPS test for CE%u\n",*(undefined4 *)(param_2 + 0x2b8));
        local_118 = local_118 | 0x30;
        local_110 = CONCAT44(local_110._4_4_,*(undefined4 *)(param_2 + 0x2b8));
        if (lVar1 == 0) {
          uVar6 = gpuEngineGetGpu(0);
          lVar5 = 0;
        }
        else {
          uVar6 = gpuEngineGetGpu(*(undefined8 *)(lVar1 + 0x150));
          lVar5 = lVar1;
        }
        iVar4 = __nvoc_objCreate_CeUtils(&local_170,lVar5,0,uVar6,0,&local_120);
        if (iVar4 == 0) {
          lVar5 = *(long *)(local_170 + 0x50);
          iVar4 = ccslContextInitViaChannel_IMPL
                            (&local_168,*(undefined4 *)(lVar5 + 0xac),*(undefined4 *)(lVar5 + 0xc),
                             *(undefined4 *)(lVar5 + 8));
          if (iVar4 == 0) {
            iVar4 = memdescCreate(&local_190,param_1,0x10,0,1,2,1);
            if (iVar4 == 0) {
              iVar4 = memdescAlloc(local_190);
              if (iVar4 == 0) {
                iVar4 = memdescCreate(&local_188,param_1,0x10,0,1,1,1,0x200000000000);
                if (iVar4 == 0) {
                  iVar4 = memdescAlloc(local_188);
                  if (iVar4 == 0) {
                    iVar4 = memdescCreate(&local_180,param_1,0x10,0,1,1,1,0x200000000000);
                    if (iVar4 == 0) {
                      iVar4 = memdescAlloc(local_180);
                      if (iVar4 == 0) {
                        uVar6 = 1;
                        iVar4 = memdescCreate(&local_178,param_1,0xc,0,1,1,1,0x200000000000);
                        if (iVar4 == 0) {
                          iVar4 = memdescAlloc(local_178,uVar6);
                          if (iVar4 == 0) {
                            local_100 = 0;
                            local_108 = local_190;
                            local_f8 = 0;
                            local_c8 = local_180;
                            local_f0 = 0;
                            local_e0 = 0;
                            local_d8 = 0;
                            local_d0 = 0;
                            local_e8 = local_188;
                            local_c0 = 0;
                            local_b8 = 0;
                            local_b0 = 0;
                            local_a0 = 0;
                            local_98 = 0;
                            local_90 = 0;
                            local_a8 = local_178;
                            iVar4 = memmgrMemDescMemSet_IMPL(lVar1,local_188,0,0);
                            if (iVar4 == 0) {
                              iVar4 = memmgrMemDescMemSet_IMPL(lVar1,local_180,0,0);
                              if (iVar4 == 0) {
                                iVar4 = memmgrMemWrite_IMPL(lVar1,&local_108,&local_150,0x10,0);
                                if (iVar4 == 0) {
                                  local_40 = 1;
                                  local_38 = memdescGetPhysAddr(local_180,1,0);
                                  local_30 = memdescGetPhysAddr(local_178,1,0);
                                  local_88[2] = 0;
                                  local_88[3] = 0;
                                  local_88[1] = local_188;
                                  local_88[4] = 0x10;
                                  local_88[0] = local_190;
                                  local_3f = 1;
                                  iVar4 = ceutilsMemcopy_IMPL(local_170,local_88);
                                  if (iVar4 == 0) {
                                    iVar4 = memmgrMemRead_IMPL(lVar1,&local_e8,&local_140,0x10,0);
                                    if (iVar4 == 0) {
                                      iVar4 = memmgrMemRead_IMPL(lVar1,&local_c8,&local_130,0x10,0);
                                      if (iVar4 == 0) {
                                        iVar4 = memmgrMemRead_IMPL(lVar1,&local_a8,&local_15c,0xc,0)
                                        ;
                                        if (iVar4 == 0) {
                                          iVar4 = spdmSendTestCommand_constprop_0
                                                            (param_1,local_168,&local_140,&local_130
                                                             ,&local_15c,0,0);
                                          if (iVar4 != 0) {
                                            nvAssertOkFailedNoLog
                                                      (iVar4,
                                                  "spdmSendTestCommand(pGpu, pCcslCtx, encryptedData, sizeof encryptedData, dataAuth, sizeof dataAuth, Ivl, sizeof Ivl, NULL, 0, NV_FALSE)"
                                                  ,"src/kernel/gpu/ce/kernel_ce.c",0x116);
                                          }
                                        }
                                        else {
                                          nvAssertOkFailedNoLog
                                                    (iVar4,
                                                  "memmgrMemRead(pMemoryManager, &ivSurface, Ivl, sizeof Ivl, TRANSFER_FLAGS_NONE)"
                                                  ,"src/kernel/gpu/ce/kernel_ce.c",0x113);
                                        }
                                      }
                                      else {
                                        nvAssertOkFailedNoLog
                                                  (iVar4,
                                                  "memmgrMemRead(pMemoryManager, &authSurface, dataAuth, sizeof dataAuth, TRANSFER_FLAGS_NONE)"
                                                  ,"src/kernel/gpu/ce/kernel_ce.c",0x110);
                                      }
                                    }
                                    else {
                                      nvAssertOkFailedNoLog
                                                (iVar4,
                                                 "memmgrMemRead(pMemoryManager, &dstSurface, encryptedData, sizeof encryptedData, TRANSFER_FLAGS_NONE)"
                                                 ,"src/kernel/gpu/ce/kernel_ce.c",0x10e);
                                    }
                                  }
                                  else {
                                    nvAssertOkFailedNoLog
                                              (iVar4,"ceutilsMemcopy(pCeUtils, &params)",
                                               "src/kernel/gpu/ce/kernel_ce.c",0x10c);
                                  }
                                }
                                else {
                                  nvAssertOkFailedNoLog
                                            (iVar4,
                                             "memmgrMemWrite(pMemoryManager, &srcSurface, ceTestPlaintext, sizeof ceTestPlaintext, TRANSFER_FLAGS_NONE)"
                                             ,"src/kernel/gpu/ce/kernel_ce.c",0xff);
                                }
                              }
                              else {
                                nvAssertOkFailedNoLog
                                          (iVar4,
                                           "memmgrMemDescMemSet(pMemoryManager, pAuthMemDesc, 0, 0)"
                                           ,"src/kernel/gpu/ce/kernel_ce.c",0xfe);
                              }
                            }
                            else {
                              nvAssertOkFailedNoLog
                                        (iVar4,
                                         "memmgrMemDescMemSet(pMemoryManager, pDstMemDesc, 0, 0)",
                                         "src/kernel/gpu/ce/kernel_ce.c",0xfd);
                            }
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar4,"memdescAlloc(pIvMemDesc)",
                                       "src/kernel/gpu/ce/kernel_ce.c",0xf5);
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar4,
                                     "memdescCreate(&pIvMemDesc, pGpu, CE_FIPS_SELF_TEST_IV_SIZE, 0, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_ALLOC_IN_UNPROTECTED_MEMORY)"
                                     ,"src/kernel/gpu/ce/kernel_ce.c",0xf3);
                        }
                      }
                      else {
                        nvAssertOkFailedNoLog
                                  (iVar4,"memdescAlloc(pAuthMemDesc)",
                                   "src/kernel/gpu/ce/kernel_ce.c",0xf1);
                      }
                    }
                    else {
                      nvAssertOkFailedNoLog
                                (iVar4,
                                 "memdescCreate(&pAuthMemDesc, pGpu, sizeof dataAuth, 0, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_ALLOC_IN_UNPROTECTED_MEMORY)"
                                 ,"src/kernel/gpu/ce/kernel_ce.c",0xef);
                    }
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar4,"memdescAlloc(pDstMemDesc)","src/kernel/gpu/ce/kernel_ce.c",
                               0xed);
                  }
                }
                else {
                  nvAssertOkFailedNoLog
                            (iVar4,
                             "memdescCreate(&pDstMemDesc, pGpu, sizeof encryptedData, 0, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_ALLOC_IN_UNPROTECTED_MEMORY)"
                             ,"src/kernel/gpu/ce/kernel_ce.c",0xeb);
                }
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar4,"memdescAlloc(pSrcMemDesc)","src/kernel/gpu/ce/kernel_ce.c",0xe9);
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar4,
                         "memdescCreate(&pSrcMemDesc, pGpu, sizeof ceTestPlaintext, 0, NV_TRUE, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_ALLOC_FLAGS_PROTECTED)"
                         ,"src/kernel/gpu/ce/kernel_ce.c",0xe7);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,
                       "ccslContextInitViaChannel_HAL(&pCcslCtx, pCeUtils->pChannel->hClient, pCeUtils->pChannel->subdeviceId, pCeUtils->pChannel->channelId)"
                       ,"src/kernel/gpu/ce/kernel_ce.c",0xe1);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar4,
                     "objCreate(&pCeUtils, pMemoryManager, CeUtils, ENG_GET_GPU(pMemoryManager), NULL, &ceUtilsParams)"
                     ,"src/kernel/gpu/ce/kernel_ce.c",0xde);
        }
        ccslContextClear_IMPL(local_168);
        __nvoc_objDelete(local_170);
        memdescFree(local_190);
        memdescDestroy(local_190);
        memdescFree(local_188);
        memdescDestroy(local_188);
        memdescFree(local_180);
        memdescDestroy(local_180);
        memdescFree(local_178);
        memdescDestroy(local_178);
        nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x125,"kceRunFipsSelfTestDecrypt",1,
                     "NVRM: Test finished with status 0x%x\n",iVar4);
      }
      else {
        iVar4 = 0x10005;
      }
    }
    return iVar4;
  }
  nvAssertFailedNoLog("gpuIsCCFeatureEnabled(pGpu)","src/kernel/gpu/ce/kernel_ce.c",199);
  return 0x56;
}


// ===== 002ef4b0 kceRunFipsSelfTest =====

void kceRunFipsSelfTest(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = kceRunFipsSelfTestDecrypt();
  if (iVar1 != 0) {
    return;
  }
  kceRunFipsSelfTestEncrypt(param_1,param_2);
  return;
}


// ===== 002ef4e0 kceConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kceConstructEngine_IMPL(long param_1,long param_2,byte param_3)

{
  int iVar1;
  int local_2c [3];
  
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x32,"kceConstructEngine_IMPL",1,
               "NVRM: KernelCE: thisPublicID = %d\n",param_3);
  *(uint *)(param_2 + 0x2b8) = (uint)param_3;
  *(undefined1 *)(param_2 + 0x2d4) = 0;
  *(undefined4 *)(param_2 + 700) = 0;
  (**(code **)(param_2 + 0x198))(param_1,param_2);
  *(undefined2 *)(param_2 + 0x2e0) = 1;
  *(undefined1 *)(param_2 + 0x2e2) = 0;
  *(undefined4 *)(param_2 + 0x2e4) = 0;
  local_2c[0] = 0;
  iVar1 = osReadRegistryDword(param_1,"RmCeEnableAutoConfig",local_2c);
  if (iVar1 == 0 && local_2c[0] == 0) {
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x42,"kceConstructEngine_IMPL",1,
                 "NVRM: Disable CE Auto PCE-LCE Config\n");
    *(undefined1 *)(param_2 + 0x2e0) = 0;
  }
  iVar1 = osReadRegistryDword(param_1,"RmCeUseGen4Mapping",local_2c);
  if ((iVar1 == 0) && (local_2c[0] == 1)) {
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x49,"kceConstructEngine_IMPL",1,
                 "NVRM: GEN4 mapping will use a HSHUB PCE (if available) for PCIe!\n");
    *(undefined1 *)(param_2 + 0x2e1) = 1;
  }
  if ((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x908) != '\0')) {
    *(int *)(param_1 + 0x8fc) = *(int *)(param_1 + 0x8fc) + 1;
  }
  return 0;
}


// ===== 002ef640 kceIsPresent_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 kceIsPresent_IMPL(long param_1,long param_2)

{
  undefined1 uVar1;
  
  uVar1 = (**(code **)(param_1 + 200))(param_1,*(uint *)(param_2 + 0x2b8) | 0x793ceb00);
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x5c,"kceIsPresent_IMPL",1,
               "NVRM: KCE %d / %d: present=%d\n",*(undefined4 *)(param_2 + 0x2b8),
               *(int *)(param_1 + 0x8fc) + -1 + (uint)(*(int *)(param_1 + 0x8fc) == 0),uVar1);
  return uVar1;
}


// ===== 002ef6c0 kceStateInitLocked_IMPL =====

ulong kceStateInitLocked_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  cVar1 = gpuIsCCFeatureEnabled_IMPL();
  if (((cVar1 == '\0') || (*(char *)(param_1 + 0x446) != '\0')) ||
     (*(char *)(param_1 + 0x490e) != '\0')) {
    *(undefined1 *)(param_2 + 0x2e8) = 0;
  }
  else if (*(char *)(param_2 + 0x2e8) != '\0') {
    uVar2 = gpuGetKernelFifoShared_IMPL(param_1);
    uVar3 = kfifoAddSchedulingHandler_IMPL(param_1,uVar2,kceRunFipsSelfTest,param_2,0,0);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,
               "kfifoAddSchedulingHandler(pGpu, GPU_GET_KERNEL_FIFO(pGpu), kceRunFipsSelfTest, pKCe, NULL, NULL)"
               ,"src/kernel/gpu/ce/kernel_ce.c",0x1d6);
    return uVar3 & 0xffffffff;
  }
  return 0;
}


// ===== 002ef760 kceStateDestroy_IMPL =====

void kceStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_2 + 0x2e8) == '\0') {
    return;
  }
  uVar1 = gpuGetKernelFifoShared_IMPL();
  kfifoRemoveSchedulingHandler_IMPL(param_1,uVar1,kceRunFipsSelfTest,param_2,0,0);
  return;
}


// ===== 002ef7b0 kceGetNvlinkCaps_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kceGetNvlinkCaps_IMPL(undefined8 param_1,long param_2,byte *param_3)

{
  char cVar1;
  
  cVar1 = (**(code **)(param_2 + 0x1b0))();
  if (cVar1 != '\0') {
    *param_3 = *param_3 | 4;
  }
  cVar1 = (**(code **)(param_2 + 0x1b8))(param_1,param_2);
  if (cVar1 != '\0') {
    *param_3 = *param_3 | 8;
  }
  cVar1 = (**(code **)(param_2 + 0x1c8))(param_1,param_2);
  if (cVar1 != '\0') {
    *param_3 = *param_3 | 0x10;
  }
  cVar1 = (**(code **)(param_2 + 0x1d0))(param_1,param_2);
  if (cVar1 != '\0') {
    param_3[1] = param_3[1] | 0x40;
  }
  cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if (cVar1 != '\0') {
    cVar1 = (**(code **)(param_2 + 0x1c0))(param_1,param_2);
    if (cVar1 != '\0') {
      param_3[1] = param_3[1] | 0x10;
    }
  }
  return;
}


// ===== 002ef870 kceGetDeviceCaps_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kceGetDeviceCaps_IMPL(long param_1,long param_2,undefined4 param_3,byte *param_4)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  int local_40;
  undefined1 local_3c [12];
  
  if (*(char *)(param_2 + 0x2d5) == '\0') {
    lVar2 = *(long *)(param_1 + 0x1ce8);
    if (lVar2 != 0) {
      cVar3 = knvlinkIsForcedConfig_IMPL(param_1,lVar2);
      if (cVar3 == '\0') {
        cVar3 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(param_1,*(undefined8 *)(param_1 + 0x1bc0));
        if (cVar3 != '\0') {
          knvlinkCoreGetRemoteDeviceInfo_IMPL(param_1,lVar2);
        }
      }
    }
    portMemSet(param_4,0,2);
    portMemSet(&local_40,0,8);
    uVar1 = *(uint *)(param_2 + 0x2b8);
    local_40 = uVar1 + 0x2a;
    if (uVar1 < 10) {
      local_40 = uVar1 + 9;
    }
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x231,"kceGetDeviceCaps_IMPL",1,
                 "NVRM: Querying caps for LCE(%d)\n");
    iVar4 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20802a07,&local_40,8);
    if (iVar4 == 0) {
      portMemCopy(param_4,2,local_3c,2);
      (**(code **)(param_2 + 0x1d8))(param_1,param_2,param_4);
      uVar5 = gpuGetNv2080EngineType_IMPL(param_3);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1ec,"printCaps",1,
                   "NVRM: LCE%d caps (engineType = %d (%d))\n",*(undefined4 *)(param_2 + 0x2b8),
                   uVar5,param_3);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f0,"printCaps",1,"NVRM: _CE_GRCE:%d\n",
                   *param_4 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f1,"printCaps",1,"NVRM: _CE_SHARED:%d\n",
                   (int)(uint)*param_4 >> 1 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f2,"printCaps",1,"NVRM: _CE_SYSMEM_READ:%d\n",
                   (int)(uint)*param_4 >> 2 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",499,"printCaps",1,"NVRM: _CE_SYSMEM_WRITE:%d\n",
                   (int)(uint)*param_4 >> 3 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",500,"printCaps",1,"NVRM: _CE_NVLINK_P2P:%d\n",
                   (int)(uint)*param_4 >> 4 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f5,"printCaps",1,"NVRM: _CE_SYSMEM:%d\n",
                   (int)(uint)*param_4 >> 5 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f6,"printCaps",1,"NVRM: _CE_P2P:%d\n",
                   (int)(uint)*param_4 >> 6 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f7,"printCaps",1,
                   "NVRM: _CE_BL_SIZE_GT_64K_SUPPORTED:%d\n",*param_4 >> 7);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f8,"printCaps",1,
                   "NVRM: _CE_SUPPORTS_NONPIPELINED_BL:%d\n",param_4[1] & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1f9,"printCaps",1,
                   "NVRM: _CE_SUPPORTS_PIPELINED_BL:%d\n",(int)(uint)param_4[1] >> 1 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1fa,"printCaps",1,"NVRM: _CE_CC_SECURE:%d\n",
                   (int)(uint)param_4[1] >> 2 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1fb,"printCaps",1,
                   "NVRM: _CE_CC_WORK_SUBMIT:%d\n",(int)(uint)param_4[1] >> 4 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1fc,"printCaps",1,
                   "NVRM: _CE_DECOMP_SUPPORTED:%d\n",(int)(uint)param_4[1] >> 3 & 1);
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x1fd,"printCaps",1,"NVRM: _CE_SCRUB:%d\n",
                   (int)(uint)param_4[1] >> 6 & 1);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_CE_GET_PHYSICAL_CAPS, &physicalCaps, sizeof(physicalCaps))"
                 ,"src/kernel/gpu/ce/kernel_ce.c",0x234);
    }
    return iVar4;
  }
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x21b,"kceGetDeviceCaps_IMPL",1,
               "NVRM: Skipping stubbed CE %d\n",*(undefined4 *)(param_2 + 0x2b8));
  return 0x56;
}


// ===== 002efd40 kceGetCeFromNvlinkConfig_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kceGetCeFromNvlinkConfig_IMPL
                (undefined8 param_1,long param_2,undefined4 param_3,undefined8 param_4,
                undefined8 param_5,long param_6)

{
  ulong uVar1;
  ulong local_68 [7];
  
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  gpumgrGetSubDeviceCount(param_3);
  uVar1 = nvlinkCtrlCmdBusGetNvlinkCaps(param_1,local_68);
  if ((int)uVar1 == 0) {
    if ((local_68[0] & 1) != 0) {
      if ((local_68[0] & 4) != 0) {
        (**(code **)(param_2 + 0x1e8))(param_1,param_2,param_4,param_5,*(code **)(param_2 + 0x1e8));
        uVar1 = uVar1 & 0xffffffff;
      }
      if ((((byte)local_68[0] & 2) != 0) && (param_6 != 0)) {
        uVar1 = (**(code **)(param_2 + 0x1e0))(param_2,param_1,param_3,param_6);
      }
    }
    return uVar1;
  }
  nvAssertOkFailedNoLog(uVar1 & 0xffffffff,"rmStatus","src/kernel/gpu/ce/kernel_ce.c",0x264);
  return uVar1 & 0xffffffff;
}


// ===== 002efe50 kceUpdateClassDB_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kceUpdateClassDB_KERNEL(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  uint local_3c [3];
  
  local_3c[0] = 0;
  uVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20802a06,local_3c,4);
  if (uVar2 != 0) {
    nvAssertOkFailedNoLog(uVar2,"status","src/kernel/gpu/ce/kernel_ce.c",0x284);
    return (ulong)uVar2;
  }
  uVar2 = *(uint *)(param_1 + 0x8fc);
  if (uVar2 != 0) {
    uVar3 = 0;
    do {
      while ((0x13 < uVar3 || (lVar1 = *(long *)(param_1 + 0x1c30 + uVar3 * 8), lVar1 == 0))) {
LAB_002eff09:
        uVar3 = uVar3 + 1;
        if (uVar2 == uVar3) goto LAB_002eff88;
      }
      uVar4 = uVar3 & 0xffffffff;
      uVar5 = (uint)uVar3 | 0x793ceb00;
      if ((local_3c[0] >> ((uint)uVar3 & 0x1f) & 1) != 0) {
        nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x28d,"kceUpdateClassDB_KERNEL",1,
                     "NVRM: Stubbing KCE %d\n",uVar4);
        *(undefined1 *)(lVar1 + 0x2d5) = 1;
        gpuDeleteClassFromClassDBByEngTag_IMPL(param_1,uVar5);
        goto LAB_002eff09;
      }
      uVar3 = uVar3 + 1;
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x295,"kceUpdateClassDB_KERNEL",1,
                   "NVRM: Unstubbing KCE %d\n",uVar4);
      *(undefined1 *)(lVar1 + 0x2d5) = 0;
      gpuAddClassToClassDBByEngTag_IMPL(param_1,uVar5);
    } while (uVar2 != uVar3);
  }
LAB_002eff88:
  uVar3 = gpuUpdateEngineTable_IMPL(param_1);
  if ((int)uVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar3 & 0xffffffff,"gpuUpdateEngineTable(pGpu)","src/kernel/gpu/ce/kernel_ce.c",
               0x29c);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 002f0000 kceRegisterIntrService_IMPL =====

void kceRegisterIntrService_IMPL(undefined8 param_1,long param_2,long param_3)

{
  param_3 = param_3 + (ulong)(ushort)(*(short *)(param_2 + 0x2b8) + 0xf) * 0x18;
  if (*(long *)(param_3 + 8) == 0) {
    *(undefined1 *)(param_3 + 0x10) = 0;
    *(undefined8 *)(param_3 + 8) = *(undefined8 *)(param_2 + 0x170);
    return;
  }
  nvAssertFailedNoLog("pRecords[engineIdx].pNotificationService == NULL",
                      "src/kernel/gpu/ce/kernel_ce.c",0x2ae);
  *(undefined1 *)(param_3 + 0x10) = 0;
  *(undefined8 *)(param_3 + 8) = *(undefined8 *)(param_2 + 0x170);
  return;
}


// ===== 002f0080 kceServiceNotificationInterrupt_IMPL =====

undefined8 kceServiceNotificationInterrupt_IMPL(undefined8 param_1,long param_2,long param_3)

{
  if (param_3 == 0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/ce/kernel_ce.c",0x2c3);
    return 0x1f;
  }
  if ((uint)*(ushort *)(param_3 + 8) == *(int *)(param_2 + 0x2b8) + 0xfU) {
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x2c6,"kceServiceNotificationInterrupt_IMPL",1,
                 "NVRM: for CE%d\n");
    engineNonStallIntrNotify(param_1,*(int *)(param_2 + 0x2b8) + 9);
    return 0;
  }
  nvAssertFailedNoLog("pParams->engineIdx == MC_ENGINE_IDX_CE(pKCe->publicID)",
                      "src/kernel/gpu/ce/kernel_ce.c",0x2c4);
  return 0xffff;
}


// ===== 002f0160 kceTopLevelPceLceMappingsUpdate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kceTopLevelPceLceMappingsUpdate_IMPL(long param_1,long param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  char cVar7;
  long local_180;
  undefined4 local_16c;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_154;
  undefined8 auStack_14c [30];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar2 = 0;
  auStack_14c[0xb] = 0;
  auStack_14c[0xc] = 0;
  auStack_14c[0xd] = 0;
  auStack_14c[0xe] = 0;
  do {
    uVar4 = (ulong)uVar2;
    uVar2 = uVar2 + 0x20;
    *(undefined8 *)((long)&local_154 + uVar4) = 0;
    *(undefined8 *)((long)auStack_14c + uVar4) = 0;
    *(undefined8 *)((long)auStack_14c + uVar4 + 8) = 0;
    *(undefined8 *)((long)auStack_14c + uVar4 + 0x10) = 0;
  } while (uVar2 < 0x60);
  local_168 = 0;
  puVar1 = auStack_14c + 0xf;
  local_160 = 0;
  local_16c = 0;
  iVar3 = kceUpdateClassDB_KERNEL(param_1,param_2);
  puVar5 = &local_154;
  if (iVar3 == 0) {
    do {
      *(undefined4 *)puVar5 = 0xf;
      puVar6 = puVar5 + 1;
      *(undefined4 *)((long)puVar5 + 4) = 0xf;
      puVar5 = puVar6;
    } while (puVar1 != puVar6);
    cVar7 = *(char *)(param_2 + 0x2e0);
    local_168 = 0xf0000000f;
    local_160 = 0xf0000000f;
    if ((cVar7 == '\0') &&
       ((*(char *)(param_1 + 0x446) != '\0' || (*(char *)(param_1 + 0x490e) != '\0')))) {
      cePauseCeUtilsScheduling(param_1);
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 0;
      uVar2 = 0;
      do {
        uVar4 = (ulong)uVar2;
        uVar2 = uVar2 + 0x20;
        *(undefined8 *)((long)puVar1 + uVar4) = 0;
        *(undefined8 *)((long)auStack_14c + uVar4 + 0x80) = 0;
        *(undefined8 *)((long)auStack_14c + uVar4 + 0x88) = 0;
        *(undefined8 *)((long)auStack_14c + uVar4 + 0x90) = 0;
      } while (uVar2 < 0x80);
    }
    else {
      iVar3 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,&local_154,&local_168,&local_16c);
      if (iVar3 == 0x56) {
        nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x2f5,"kceTopLevelPceLceMappingsUpdate_IMPL",1,
                     "NVRM: CE AutoConfig is not supported. Skipping PCE2LCE update\n");
        cePauseCeUtilsScheduling(param_1);
        local_58 = 0;
        local_50 = 0;
        local_48 = 0;
        local_40 = 0;
        uVar2 = 0;
        do {
          uVar4 = (ulong)uVar2;
          uVar2 = uVar2 + 0x20;
          *(undefined8 *)((long)puVar1 + uVar4) = 0;
          *(undefined8 *)((long)auStack_14c + uVar4 + 0x80) = 0;
          *(undefined8 *)((long)auStack_14c + uVar4 + 0x88) = 0;
          *(undefined8 *)((long)auStack_14c + uVar4 + 0x90) = 0;
        } while (uVar2 < 0x80);
        cVar7 = '\0';
      }
      else {
        if (iVar3 != 0) {
          nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x2fe,"kceTopLevelPceLceMappingsUpdate_IMPL",
                       4,"NVRM: Failed to get auto-config PCE-LCE mappings. Return\n");
          return iVar3;
        }
        cePauseCeUtilsScheduling(param_1);
        local_58 = 0;
        local_50 = 0;
        local_48 = 0;
        local_40 = 0;
        uVar2 = 0;
        do {
          uVar4 = (ulong)uVar2;
          uVar2 = uVar2 + 0x20;
          *(undefined8 *)((long)puVar1 + uVar4) = 0;
          *(undefined8 *)((long)auStack_14c + uVar4 + 0x80) = 0;
          *(undefined8 *)((long)auStack_14c + uVar4 + 0x88) = 0;
          *(undefined8 *)((long)auStack_14c + uVar4 + 0x90) = 0;
        } while (uVar2 < 0x80);
        if (cVar7 != '\0') {
          portMemCopy(puVar1,0x80,&local_154,0x80);
          portMemCopy((long)&local_58 + 4,0x10,&local_168,0x10);
        }
      }
    }
    local_180 = param_1 + 0x3b58;
    local_40 = CONCAT71(local_40._1_7_,cVar7);
    local_48 = CONCAT44(local_16c,(undefined4)local_48);
    iVar3 = rmapiControlCacheFreeForControl(*(undefined4 *)(param_1 + 0x7a4),0x20802a02);
    if (iVar3 == 0) {
      local_40 = CONCAT44(*(undefined4 *)(param_2 + 700),(undefined4)local_40);
      iVar3 = (**(code **)(param_1 + 0x3b90))
                        (local_180,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20802a0d,puVar1,0x9c);
      if (iVar3 == 0) {
        iVar3 = kceUpdateClassDB_KERNEL(param_1,param_2);
        ceResumeCeUtilsScheduling(param_1);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x337,"kceTopLevelPceLceMappingsUpdate_IMPL",4,
                     "NVRM: Failed to update PCE-LCE mappings. Return\n");
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,
                 "rmapiControlCacheFreeForControl(gpuGetInstance(pGpu), NV2080_CTRL_CMD_CE_GET_CE_PCE_MASK)"
                 ,"src/kernel/gpu/ce/kernel_ce.c",0x328);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,"kceUpdateClassDB_HAL(pGpu, pKCe)","src/kernel/gpu/ce/kernel_ce.c",0x2df);
  }
  return iVar3;
}


// ===== 002f05b0 kceGetFaultMethodBufferSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kceGetFaultMethodBufferSize_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  ulong uVar2;
  undefined4 local_1c [3];
  
  local_1c[0] = 0;
  if (*(char *)(param_1 + 0x4913) == '\0') {
    uVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20802a08,local_1c,4);
    if ((int)uVar2 == 0) {
      *param_2 = local_1c[0];
    }
    else {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_CE_GET_FAULT_METHOD_BUFFER_SIZE, &params, sizeof(params))"
                 ,"src/kernel/gpu/ce/kernel_ce.c",0x359);
      uVar2 = uVar2 & 0xffffffff;
    }
  }
  else {
    lVar1 = gpuGetStaticInfo();
    if (lVar1 != 0) {
      *param_2 = *(undefined4 *)(lVar1 + 0xa8c0);
      return 0;
    }
    nvAssertFailedNoLog(&DAT_00d03e99,"src/kernel/gpu/ce/kernel_ce.c",0x352);
    uVar2 = 0x40;
  }
  return uVar2;
}


// ===== 002f0680 kceGetAvailableHubPceMask_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kceGetAvailableHubPceMask_IMPL(long param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_a0 [4];
  undefined4 auStack_80 [24];
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      uVar1 = (int)uVar3 + 0x20;
      *(undefined8 *)((long)local_a0 + uVar3) = 0;
      *(undefined8 *)((long)local_a0 + uVar3 + 8) = 0;
      *(undefined8 *)((long)local_a0 + uVar3 + 0x10) = 0;
      *(undefined8 *)((long)auStack_80 + (uVar3 - 8)) = 0;
      uVar3 = (ulong)uVar1;
    } while (uVar1 < 0x80);
    *(undefined4 *)((long)local_a0 + (ulong)uVar1) = 0;
    local_1c = *(undefined4 *)(param_2 + 700);
    iVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20802a0e,local_a0,0x88);
    if (iVar2 == 0) {
      portMemCopy(param_3 + 0x18,0x80,local_a0,0x80);
      *(undefined4 *)(param_3 + 0x98) = local_20;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_CE_GET_HUB_PCE_MASK_V2, &params, sizeof(params))"
                 ,"src/kernel/gpu/ce/kernel_ce.c",0x37a);
    }
    return iVar2;
  }
  nvAssertFailedNoLog("pTopoParams != NULL","src/kernel/gpu/ce/kernel_ce.c",0x373);
  return 0x1f;
}


// ===== 002f07b0 kceFindFirstInstance_IMPL =====

undefined8 kceFindFirstInstance_IMPL(long param_1,long *param_2)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 0x8fc) != 0) {
    do {
      if ((uVar2 < 0x14) && (lVar1 = *(long *)(param_1 + 0x1c30 + uVar2 * 8), lVar1 != 0)) {
        *param_2 = lVar1;
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != *(uint *)(param_1 + 0x8fc));
  }
  return 0x1a;
}


// ===== 002f07f0 kceFindShimOwner_IMPL =====

undefined8 kceFindShimOwner_IMPL(long param_1,long param_2,long *param_3)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 0x8fc) != 0) {
    do {
      if ((((uVar2 < 0x14) && (lVar1 = *(long *)(param_1 + 0x1c30 + uVar2 * 8), lVar1 != 0)) &&
          (*(int *)(lVar1 + 700) == *(int *)(param_2 + 700))) && (*(char *)(lVar1 + 0x2d4) != '\0'))
      {
        *param_3 = lVar1;
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != *(uint *)(param_1 + 0x8fc));
  }
  return 0x1a;
}


// ===== 002f0860 kceGetLceMask_IMPL =====

uint kceGetLceMask_IMPL(long param_1)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = 0;
  uVar2 = 0;
  do {
    if (*(long *)(param_1 + 0x1c30 + lVar1 * 8) != 0) {
      uVar2 = uVar2 | 1 << ((uint)lVar1 & 0x1f);
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x14);
  return uVar2;
}


// ===== 002f08a0 kceApplyMIGMappings_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kceApplyMIGMappings_IMPL(long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_a0 [16];
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar3 = 0;
  do {
    uVar1 = (int)uVar3 + 0x20;
    *(undefined8 *)((long)local_a0 + uVar3) = 0;
    *(undefined8 *)((long)local_a0 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_a0 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_a0 + uVar3 + 0x18) = 0;
    uVar3 = (ulong)uVar1;
  } while (uVar1 < 0x80);
  *(undefined8 *)((long)local_a0 + (ulong)uVar1) = 0;
  local_20 = param_4;
  portMemCopy(local_a0,0x80,param_3,0x80);
  local_1c = *(undefined4 *)(param_2 + 700);
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20802a14,local_a0,0x88);
  if (iVar2 == 0) {
    kceUpdateClassDB_KERNEL(param_1,param_2);
    return 1;
  }
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce.c",0x3fa,"kceApplyMIGMappings_IMPL",4,
               "NVRM: Failed to update PCE-LCE mappings for LCE 0x%x. Return\n",param_4);
  return 0;
}


// ===== 002f09d0 kceGetPceConfigForLceType_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kceGetPceConfigForLceType_IMPL
                (long param_1,undefined8 param_2,int param_3,undefined4 *param_4,undefined4 *param_5
                ,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  int iVar1;
  ulong uVar2;
  undefined8 local_5c;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  if (param_4 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pNumPcesPerLce != NULL","src/kernel/gpu/ce/kernel_ce.c",0x421);
  }
  else if (param_5 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pNumLces != NULL","src/kernel/gpu/ce/kernel_ce.c",0x422);
  }
  else if (param_6 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pSupportedPceMask != NULL","src/kernel/gpu/ce/kernel_ce.c",0x423);
  }
  else if (param_7 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pSupportedLceMask != NULL","src/kernel/gpu/ce/kernel_ce.c",0x424);
  }
  else {
    if (param_8 != (undefined4 *)0x0) {
      portMemSet(&local_54,0,0x1c);
      local_54 = param_3;
      if (param_3 - 6U < 2) {
        local_5c = 4;
        iVar1 = kbifControlGetPCIEInfo_IMPL(param_1,*(undefined8 *)(param_1 + 7000),&local_5c);
        local_50 = 0xffffffff;
        if (iVar1 == 0) {
          local_50 = ceEncodeLceTypeMetadataForPcie(param_1,local_5c._4_4_);
        }
      }
      uVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20802a0f,&local_54,0x1c);
      if ((int)uVar2 == 0) {
        *param_4 = local_4c;
        *param_5 = local_48;
        *param_6 = local_44;
        *param_7 = local_40;
        *param_8 = local_3c;
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar2 & 0xffffffff,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_CE_GET_PCE_CONFIG_FOR_LCE_TYPE, &pceConfigParams, sizeof(pceConfigParams))"
                   ,"src/kernel/gpu/ce/kernel_ce.c",0x43e);
        uVar2 = uVar2 & 0xffffffff;
      }
      return uVar2;
    }
    nvAssertFailedNoLog("pPcesPerHshub != NULL","src/kernel/gpu/ce/kernel_ce.c",0x425);
  }
  return 0x1f;
}


// ===== 002f0bf0 kceGetPceConfigForLceMIGGpuInstance_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kceGetPceConfigForLceMIGGpuInstance_IMPL
                (long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 *param_8)

{
  ulong uVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_5 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pPceAvailableMask != NULL","src/kernel/gpu/ce/kernel_ce.c",0x46c);
  }
  else if (param_7 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pLceAvailableMask != NULL","src/kernel/gpu/ce/kernel_ce.c",0x46d);
  }
  else if (param_8 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pNumMinPcesPerLce != NULL","src/kernel/gpu/ce/kernel_ce.c",0x46e);
  }
  else {
    if (param_6 != (undefined4 *)0x0) {
      portMemSet(&local_40,0,0x18);
      local_40 = param_3;
      local_3c = param_4;
      uVar1 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20802a13,&local_40,0x18);
      if ((int)uVar1 == 0) {
        *param_5 = local_38;
        *param_6 = local_34;
        *param_7 = local_30;
        *param_8 = local_2c;
        return uVar1;
      }
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_CE_GET_PCE_CONFIG_FOR_LCE_MIG_GPU_INSTANCE, &pceConfigParams, sizeof(pceConfigParams))"
                 ,"src/kernel/gpu/ce/kernel_ce.c",0x476);
      return uVar1 & 0xffffffff;
    }
    nvAssertFailedNoLog("pNumLcesToMap != NULL","src/kernel/gpu/ce/kernel_ce.c",0x46f);
  }
  return 0x1f;
}


// ===== 002f0d90 kceIsDecompLce_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1 kceIsDecompLce_IMPL(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 local_20;
  
  local_20 = 0;
  lVar2 = resservGetTlsCallContext();
  local_20 = CONCAT44(local_20._4_4_,param_2);
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,**(undefined4 **)(lVar2 + 0x48),
                     (*(undefined4 **)(lVar2 + 0x48))[1],0x20802a12,&local_20,8);
  if (iVar1 != 0) {
    local_20._4_1_ = 0;
  }
  return local_20._4_1_;
}


// ===== 002f0e00 kceIsDecompLce_VF =====

byte kceIsDecompLce_VF(undefined8 param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    return *(byte *)(lVar1 + 0x8ce5 + (param_2 & 0xffffffff) * 8) >> 3 & 1;
  }
  nvAssertFailedNoLog(&DAT_00d03e99,"src/kernel/gpu/ce/kernel_ce.c",0x4c1);
  return 0x40;
}


// ===== 002f0e60 kceGetEngineDescFromAllocParams =====

/* WARNING: Type propagation algorithm not settling */

uint kceGetEngineDescFromAllocParams(long param_1,uint param_2,int *param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  int local_54;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar4 = resservGetTlsCallContext();
  iVar3 = refFindAncestorOfType(*(undefined8 *)(lVar4 + 0x10),&DAT_00e0ac20,&local_50);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,
               "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)",
               "src/kernel/gpu/ce/kernel_ce_context.c",0x44);
    return 0xb33b1500;
  }
  uVar5 = __nvoc_dynamicCast(*(undefined8 *)(local_50 + 8),__nvoc_class_def_Device);
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("pAllocParams","src/kernel/gpu/ce/kernel_ce_context.c",0x4b);
  }
  if (param_2 != 0xc6b5) {
    if (param_2 < 0xc6b6) {
      if (param_2 != 0xc1b5) {
        if (param_2 < 0xc1b6) {
          uVar6 = param_2 - 0xb0b5 & 0xffffefff;
        }
        else {
          uVar6 = param_2 - 0xc3b5 & 0xfffffdff;
        }
joined_r0x002f0f5b:
        if (uVar6 != 0) {
          return 0xb33b1500;
        }
      }
    }
    else if (param_2 != 0xc9b5) {
      if (param_2 < 0xc9b6) {
        uVar6 = param_2 - 0xc7b5 & 0xfffffeff;
        goto joined_r0x002f0f5b;
      }
      if (param_2 != 0xcab5) {
        return 0xb33b1500;
      }
    }
  }
  if (*param_3 == 0) {
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_context.c",0x78,"kceGetEngineDescFromAllocParams",1,
                 "NVRM: Version = 0, using engineType (=%d) as CE instance\n",param_3[1]);
    uVar7 = (ulong)(uint)param_3[1];
    iVar8 = param_3[1] + 9;
    local_54 = iVar8;
    if ((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) goto LAB_002f1059;
  }
  else {
    uVar6 = 0;
    if (*param_3 != 1) {
      nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_context.c",0xa1,"kceGetEngineDescFromAllocParams",4,
                   "NVRM: Unknown version = %d\n");
      return 0xb33b1500;
    }
    while( true ) {
      uVar7 = (ulong)uVar6;
      iVar3 = gpuGetRmEngineType_IMPL(param_3[1]);
      iVar8 = uVar6 + 9;
      if (iVar8 == iVar3) break;
      uVar6 = uVar6 + 1;
      if (uVar6 == 0x14) {
        nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_context.c",0x92,"kceGetEngineDescFromAllocParams",
                     4,"NVRM: Unknown engine type %d requested\n",param_3[1]);
        return 0xb33b1500;
      }
    }
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_context.c",0x98,"kceGetEngineDescFromAllocParams",1,
                 "NVRM: Version = 1, using engineType=%d\n",param_3[1]);
    local_54 = iVar8;
    if ((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) goto LAB_002f1074;
LAB_002f1059:
    local_54 = iVar8;
    cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
    if (cVar2 != '\0') {
      uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
      iVar3 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar1,uVar5,&local_48);
      if (((iVar3 != 0) ||
          (cVar2 = kmigmgrIsLocalEngineInInstance_IMPL(param_1,uVar1,iVar8,local_48,local_40),
          cVar2 == '\0')) ||
         (iVar3 = kmigmgrGetLocalToGlobalEngineType_IMPL
                            (param_1,uVar1,local_48,local_40,iVar8,&local_54), iVar3 != 0))
      goto LAB_002f1140;
    }
    uVar7 = (ulong)(local_54 - 9);
  }
  if ((uint)uVar7 < 0x14) {
LAB_002f1074:
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_context.c",0xb3,"kceGetEngineDescFromAllocParams",1,
                 "NVRM: Class %d, CE%d\n",param_2,uVar7);
    if (*(long *)(param_1 + 0x1c30 + uVar7 * 8) == 0) {
      nvAssertFailedNoLog("GPU_GET_KCE(pGpu, engineIndex)","src/kernel/gpu/ce/kernel_ce_context.c",
                          0xb5);
      return 0xb33b1500;
    }
    return (uint)uVar7 | 0x793ceb00;
  }
LAB_002f1140:
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_context.c",0xb9,"kceGetEngineDescFromAllocParams",4,
               "NVRM: Failed to determine CE number\n");
  return 0xb33b1500;
}


// ===== 002f1210 kcectxConstruct_IMPL =====

undefined8 kcectxConstruct_IMPL(void)

{
  return 0;
}


// ===== 002f1220 kcectxDestruct_IMPL =====

void kcectxDestruct_IMPL(void)

{
  return;
}


// ===== 002f1230 clearCePceCacheAndForwardCtrlToGsp.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong clearCePceCacheAndForwardCtrlToGsp_isra_0(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  lVar3 = resservGetTlsCallContext();
  puVar2 = *(undefined4 **)(lVar3 + 0x48);
  uVar4 = rmapiControlCacheFreeForControl(*(undefined4 *)(lVar1 + 0x7a4),0x20802a02);
  if ((int)uVar4 != 0) {
    nvAssertOkFailedNoLog
              (uVar4 & 0xffffffff,
               "rmapiControlCacheFreeForControl(gpuGetInstance(pGpu), NV2080_CTRL_CMD_CE_GET_CE_PCE_MASK)"
               ,"src/kernel/gpu/ce/kernel_ce_ctrl.c",0xc4);
    return uVar4 & 0xffffffff;
  }
  if (*(char *)(lVar1 + 0x909) == '\0') {
    return uVar4;
  }
  uVar4 = (**(code **)(lVar1 + 0x3b90))
                    (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                     puVar2[6]);
  return uVar4;
}


// ===== 002f12e0 subdeviceCtrlCmdCeGetCaps_IMPL =====

ulong subdeviceCtrlCmdCeGetCaps_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  int local_3c;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/ce/kernel_ce_ctrl.c",0x39);
    return 0x2f;
  }
  if (param_2[1] != 2) {
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_ctrl.c",0x3e,"subdeviceCtrlCmdCeGetCaps_IMPL",4,
                 "NVRM: size mismatch: client 0x%x rm 0x%x\n",param_2[1],2);
    return 0x1f;
  }
  iVar6 = gpuGetRmEngineType_IMPL(*param_2);
  uVar8 = (ulong)(iVar6 - 9U);
  if (iVar6 - 9U < 0x14) {
    uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
    local_3c = iVar6;
    if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
      cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
      if (cVar5 != '\0') {
        uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
        uVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar4,uVar2,&local_38);
        if (uVar7 != 0) goto LAB_002f137e;
        cVar5 = kmigmgrIsLocalEngineInInstance_IMPL(lVar1,uVar4,iVar6,local_38,local_30);
        uVar7 = 0x1f;
        if ((cVar5 == '\0') ||
           (uVar7 = kmigmgrGetLocalToGlobalEngineType_IMPL
                              (lVar1,uVar4,local_38,local_30,iVar6,&local_3c), uVar7 != 0))
        goto LAB_002f137e;
      }
      uVar8 = (ulong)(local_3c - 9U);
      uVar7 = 0x1f;
      if (0x13 < local_3c - 9U) {
LAB_002f137e:
        nvAssertOkFailedNoLog
                  (uVar7,
                   "ceIndexFromType(pGpu, GPU_RES_GET_DEVICE(pSubdevice), rmEngineType, &ceNumber)",
                   "src/kernel/gpu/ce/kernel_ce_ctrl.c",0x4a);
        return (ulong)uVar7;
      }
    }
    lVar3 = *(long *)(lVar1 + 0x1c30 + uVar8 * 8);
    if (lVar3 != 0) {
      uVar8 = kceGetDeviceCaps_IMPL(lVar1,lVar3,iVar6,*(undefined8 *)(param_2 + 2));
      return uVar8;
    }
  }
  return 0x56;
}


// ===== 002f14e0 subdeviceCtrlCmdCeGetCapsV2_VF =====

undefined8 subdeviceCtrlCmdCeGetCapsV2_VF(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar3 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/ce/kernel_ce_ctrl.c",0x7f);
    return 0x40;
  }
  uVar1 = *param_2;
  uVar5 = (ulong)uVar1;
  uVar2 = uVar1 - 0x40;
  if (0x13 < uVar2) {
    uVar2 = uVar1 - 9;
    if ((9 < uVar1 - 0x34) && (9 < uVar2)) {
      return 0x56;
    }
    if (0x12 < uVar1) goto LAB_002f1525;
  }
  uVar5 = (ulong)(uVar2 + 0x2a);
  if (uVar2 < 10) {
    uVar5 = (ulong)(uVar2 + 9);
  }
LAB_002f1525:
  lVar4 = 0;
  if ((*(ulong *)(lVar3 + 0xa768) >> (uVar5 & 0x3f) & 1) == 0) {
    portMemSet(param_2 + 1,0,2);
  }
  else {
    do {
      if (*(int *)(lVar3 + 0x8ce0 + lVar4 * 8) == (int)uVar5) {
        portMemCopy(param_2 + 1,2,lVar3 + 0x8ce4 + lVar4 * 8,2);
        return 0;
      }
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0x40);
  }
  return 0x56;
}


// ===== 002f15e0 subdeviceCtrlCmdCeGetCaps_VF =====

int subdeviceCtrlCmdCeGetCaps_VF(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c [3];
  
  local_20 = *param_2;
  local_1c[0] = 0;
  iVar1 = subdeviceCtrlCmdCeGetCapsV2_VF(param_1,&local_20);
  if (iVar1 != 0) {
    return iVar1;
  }
  portMemCopy(*(undefined8 *)(param_2 + 2),2,local_1c,2);
  return 0;
}


// ===== 002f1640 subdeviceCtrlCmdCeGetAllCaps_VF =====

undefined8 subdeviceCtrlCmdCeGetAllCaps_VF(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar2 != 0) {
    lVar3 = lVar2 + 0xa140;
    lVar1 = param_2 + 0x40;
    *(undefined8 *)(param_2 + 0x80) = *(undefined8 *)(lVar2 + 0xa1c0);
    do {
      portMemCopy(param_2,2,lVar3,2);
      param_2 = param_2 + 2;
      lVar3 = lVar3 + 2;
    } while (param_2 != lVar1);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/ce/kernel_ce_ctrl.c",0xac);
  return 0x40;
}


// ===== 002f16f0 subdeviceCtrlCmdCeUpdatePceLceMappings_KERNEL =====

ulong subdeviceCtrlCmdCeUpdatePceLceMappings_KERNEL(long param_1)

{
  ulong uVar1;
  
  uVar1 = clearCePceCacheAndForwardCtrlToGsp_isra_0(*(undefined8 *)(param_1 + 0x158));
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,"clearCePceCacheAndForwardCtrlToGsp(pSubdevice)",
             "src/kernel/gpu/ce/kernel_ce_ctrl.c",0xdb);
  return uVar1 & 0xffffffff;
}


// ===== 002f1740 subdeviceCtrlCmdCeUpdatePceLceMappingsV2_KERNEL =====

ulong subdeviceCtrlCmdCeUpdatePceLceMappingsV2_KERNEL(long param_1)

{
  ulong uVar1;
  
  uVar1 = clearCePceCacheAndForwardCtrlToGsp_isra_0(*(undefined8 *)(param_1 + 0x158));
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,"clearCePceCacheAndForwardCtrlToGsp(pSubdevice)",
             "src/kernel/gpu/ce/kernel_ce_ctrl.c",0xe7);
  return uVar1 & 0xffffffff;
}


// ===== 002f17a0 ceIsCeGrce =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool ceIsCeGrce(long param_1,int param_2)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  long lVar9;
  undefined8 *puVar10;
  bool bVar11;
  uint local_bc;
  undefined8 local_b8;
  uint local_ac;
  int local_a8 [2];
  undefined8 auStack_a0 [15];
  ulong uVar8;
  
  uVar7 = 0;
  do {
    uVar4 = (int)uVar7 + 0x20;
    uVar8 = (ulong)uVar4;
    *(undefined8 *)((long)&local_b8 + uVar7) = 0;
    *(undefined8 *)(&stack0xffffffffffffff50 + uVar7) = 0;
    *(undefined8 *)((long)auStack_a0 + (uVar7 - 8)) = 0;
    *(undefined8 *)((long)auStack_a0 + uVar7) = 0;
    uVar7 = uVar8;
  } while (uVar4 < 0x80);
  *(undefined8 *)((long)&local_b8 + uVar8) = 0;
  *(undefined8 *)(&stack0xffffffffffffff50 + uVar8) = 0;
  lVar9 = gpuGetKernelFifoShared_IMPL(param_1);
  cVar3 = rmcfg_IsT234DorBetter(param_1);
  if (cVar3 == '\0') {
    bVar11 = false;
    if (param_2 - 9U < 0x14) {
      local_bc = 0;
      if (((*(char *)(param_1 + 0x908) == '\0') && (lVar2 = *(long *)(param_1 + 0x1c30), lVar2 != 0)
          ) && (iVar5 = (**(code **)(lVar2 + 0x2b0))(param_1,lVar2,&local_bc), iVar5 == 0)) {
        bVar11 = (local_bc >> (param_2 - 9U & 0x1f) & 1) != 0;
      }
      else {
        local_b8._0_4_ = gpuGetNv2080EngineType_IMPL(param_2);
        local_ac = 0;
        iVar5 = (**(code **)(lVar9 + 0x268))(param_1,lVar9,&local_b8);
        if (iVar5 != 0) {
          iVar5 = gpuUpdateEngineTable_IMPL(param_1);
          if (iVar5 != 0) {
            nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_shared.c",99,"ceIsCeGrce",4,
                         "NVRM: Could not update the engine db. This is fatal\n");
            return false;
          }
          if (0x20 < *(uint *)(param_1 + 0x1e18)) {
            nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_shared.c",0x6c,"ceIsCeGrce",4,
                         "NVRM: PartnerList space too small. This is fatal\n");
            return false;
          }
          lVar9 = 0;
          if (*(uint *)(param_1 + 0x1e18) != 0) {
            do {
              uVar4 = local_ac;
              if (*(int *)(*(long *)(param_1 + 0x1e20) + lVar9 * 4) != param_2) {
                local_ac = local_ac + 1;
                uVar6 = gpuGetNv2080EngineType_IMPL();
                *(undefined4 *)((long)auStack_a0 + (ulong)uVar4 * 4 + -8) = uVar6;
              }
              lVar9 = lVar9 + 1;
            } while ((uint)lVar9 < *(uint *)(param_1 + 0x1e18));
          }
        }
        if (local_ac != 0) {
          puVar10 = &local_b8;
          puVar1 = (undefined8 *)((long)puVar10 + (ulong)local_ac * 4);
          do {
            if (*(int *)(puVar10 + 2) - 1U < 8) {
              return true;
            }
            puVar10 = (undefined8 *)((long)puVar10 + 4);
          } while (puVar1 != puVar10);
        }
      }
    }
    else {
      nvAssertFailedNoLog("RM_ENGINE_TYPE_IS_COPY(rmCeEngineType)",
                          "src/kernel/gpu/ce/kernel_ce_shared.c",0x2e);
    }
  }
  else {
    bVar11 = false;
  }
  return bVar11;
}


// ===== 002f1a40 subdeviceCtrlCmdCeGetCapsV2_IMPL =====

ulong subdeviceCtrlCmdCeGetCapsV2_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  int local_3c;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  iVar6 = gpuGetRmEngineType_IMPL(*param_2);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/ce/kernel_ce_shared.c",0xfd);
    return 0x2f;
  }
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_shared.c",0xff,"subdeviceCtrlCmdCeGetCapsV2_IMPL",1,
               "NVRM: NV2080_CTRL_CE_GET_CAPS_V2 ceEngineType = %d\n",*param_2);
  uVar8 = (ulong)(iVar6 - 9U);
  if (iVar6 - 9U < 0x14) {
    uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
    local_3c = iVar6;
    if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
      cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
      if (cVar5 != '\0') {
        uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
        uVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar4,uVar2,&local_38);
        if (uVar7 != 0) goto LAB_002f1b03;
        cVar5 = kmigmgrIsLocalEngineInInstance_IMPL(lVar1,uVar4,iVar6,local_38,local_30);
        uVar7 = 0x1f;
        if ((cVar5 == '\0') ||
           (uVar7 = kmigmgrGetLocalToGlobalEngineType_IMPL
                              (lVar1,uVar4,local_38,local_30,iVar6,&local_3c), uVar7 != 0))
        goto LAB_002f1b03;
      }
      uVar8 = (ulong)(local_3c - 9U);
      uVar7 = 0x1f;
      if (0x13 < local_3c - 9U) {
LAB_002f1b03:
        nvAssertOkFailedNoLog
                  (uVar7,
                   "ceIndexFromType(pGpu, GPU_RES_GET_DEVICE(pSubdevice), rmEngineType, &ceNumber)",
                   "src/kernel/gpu/ce/kernel_ce_shared.c",0x106);
        return (ulong)uVar7;
      }
    }
    lVar3 = *(long *)(lVar1 + 0x1c30 + uVar8 * 8);
    if (lVar3 != 0) {
      uVar8 = kceGetDeviceCaps_IMPL(lVar1,lVar3,iVar6,param_2 + 1);
      return uVar8;
    }
    nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_shared.c",0x111,"subdeviceCtrlCmdCeGetCapsV2_IMPL",1,
                 "NVRM: Skipping stubbed CE %d\n");
  }
  return 0x56;
}


// ===== 002f1c30 subdeviceCtrlCmdCeGetAllCaps_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdCeGetAllCaps_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  int iVar13;
  int local_4c;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  lVar4 = *(long *)(lVar2 + 0x1ce8);
  plVar5 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar7 = plVar5[2];
  uVar1 = *(undefined4 *)(*plVar5 + 0x48);
  if (((lVar4 != 0) && (cVar8 = knvlinkIsForcedConfig_IMPL(lVar2,lVar4), cVar8 == '\0')) &&
     (cVar8 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(lVar2,*(undefined8 *)(lVar2 + 0x1bc0)),
     cVar8 != '\0')) {
    knvlinkCoreGetRemoteDeviceInfo_IMPL(lVar2,lVar4);
  }
  portMemSet(param_2,0,0x88);
  uVar12 = 0;
  iVar9 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58,uVar1,(int)lVar7,0x20802a0b,param_2,0x88);
  if (iVar9 == 0) {
    do {
      while( true ) {
        iVar13 = (int)uVar12 + 9;
        local_4c = iVar13;
        if (*(long *)(lVar2 + 0x1bc0) != 0) break;
        uVar11 = uVar12 & 0xffffffff;
LAB_002f1cf2:
        if ((((uint)uVar11 < 0x14) && (lVar4 = *(long *)(lVar2 + 0x1c30 + uVar11 * 8), lVar4 != 0))
           && (*(char *)(lVar4 + 0x2d5) == '\0')) {
          *(ulong *)(param_2 + 0x80) = *(ulong *)(param_2 + 0x80) | 1L << ((byte)uVar12 & 0x3f);
          (**(code **)(lVar4 + 0x1d8))(lVar2,lVar4,param_2 + uVar12 * 2);
        }
LAB_002f1d33:
        uVar12 = uVar12 + 1;
        if (uVar12 == 0x14) {
          return 0;
        }
      }
      cVar8 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2);
      if (cVar8 == '\0') {
LAB_002f1cec:
        uVar11 = (ulong)(local_4c - 9);
        goto LAB_002f1cf2;
      }
      uVar6 = *(undefined8 *)(lVar2 + 0x1bc0);
      iVar10 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar2,uVar6,uVar3,&local_48);
      if ((iVar10 != 0) ||
         (cVar8 = kmigmgrIsLocalEngineInInstance_IMPL(lVar2,uVar6,iVar13,local_48,local_40),
         cVar8 == '\0')) goto LAB_002f1d33;
      iVar13 = kmigmgrGetLocalToGlobalEngineType_IMPL
                         (lVar2,uVar6,local_48,local_40,iVar13,&local_4c);
      if (iVar13 == 0) goto LAB_002f1cec;
      uVar12 = uVar12 + 1;
    } while (uVar12 != 0x14);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar9,
               "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_CE_GET_ALL_PHYSICAL_CAPS, pCeCapsParams, sizeof(*pCeCapsParams))"
               ,"src/kernel/gpu/ce/kernel_ce_shared.c",0x13b);
  }
  return iVar9;
}


// ===== 002f1e30 cePauseCeUtilsScheduling =====

void cePauseCeUtilsScheduling(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x4a0);
  if (lVar1 != 0) {
    ceutilsPauseSubmission_IMPL(lVar1,1);
    return;
  }
  return;
}


// ===== 002f1e60 ceResumeCeUtilsScheduling =====

void ceResumeCeUtilsScheduling(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  if (*(long *)(lVar1 + 0x4a0) == 0) {
    return;
  }
  cVar2 = ceutilsUsesPreferredCe_IMPL(*(long *)(lVar1 + 0x4a0));
  if (cVar2 == '\0') {
    memmgrDestroyCeUtils_IMPL(lVar1);
    iVar3 = memmgrInitCeUtils_IMPL(*(undefined8 *)(param_1 + 0x1b78),0,1);
    if (iVar3 == 0) {
      return;
    }
    nvAssertOkFailedNoLog
              (iVar3,"memmgrInitCeUtils(GPU_GET_MEMORY_MANAGER(pGpu), NV_FALSE, NV_TRUE)",
               "src/kernel/gpu/ce/kernel_ce_shared.c",0x167);
    return;
  }
  ceutilsResumeSubmission_IMPL(*(undefined8 *)(lVar1 + 0x4a0));
  return;
}


// ===== 002f1f00 ceEncodeLceTypeMetadataForPcie =====

uint ceEncodeLceTypeMetadataForPcie(undefined8 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (param_2 & 0xf) - 1;
  if (uVar1 < 6) {
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/ce/kernel_ce_shared.c",0x193,"ceEncodeLceTypeMetadataForPcie",4,
               "NVRM: ceEncodeLceTypeMetadataForPcie unknown\n");
  return 0xffffffff;
}


// ===== 002f1f50 confComputeGetEngineIdFromKeySpace_GB100 =====

ulong confComputeGetEngineIdFromKeySpace_GB100(undefined8 param_1,int param_2)

{
  ulong uVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_2 != 1) {
    if (param_2 - 10U < 8) {
      return (ulong)(param_2 + 0xb);
    }
    uVar1 = confComputeGetEngineIdFromKeySpace_GH100();
    return uVar1;
  }
  return 0x31;
}


// ===== 002f1f90 confComputeDeriveSecrets_GB100 =====

undefined8 confComputeDeriveSecrets_GB100(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  if (*(char *)(lVar1 + 0x909) != '\0') {
    if (param_2 < 0x19) {
      if (param_2 < 0x11) {
LAB_002f1fda:
        uVar2 = confComputeDeriveSecrets_GH100(param_1,param_2);
        return uVar2;
      }
    }
    else if (7 < param_2 - 0x1b) goto LAB_002f1fda;
  }
  return 0;
}


// ===== 002f1ff0 confComputeGetKeySpaceFromKChannel_GB100 =====

undefined8
confComputeGetKeySpaceFromKChannel_GB100(undefined8 param_1,long param_2,undefined2 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(param_2 + 0x42c);
  if (uVar1 == 0x19) {
    *param_3 = 0xe;
    return 0;
  }
  if (uVar1 < 0x1a) {
    if (uVar1 == 0x17) {
      *param_3 = 0xc;
      return 0;
    }
    if (uVar1 == 0x18) {
      *param_3 = 0xd;
      return 0;
    }
    if (uVar1 == 0x15) {
      *param_3 = 10;
      return 0;
    }
    if (uVar1 == 0x16) {
      *param_3 = 0xb;
      return 0;
    }
  }
  else {
    if (uVar1 == 0x1b) {
      *param_3 = 0x10;
      return 0;
    }
    if (uVar1 == 0x1c) {
      *param_3 = 0x11;
      return 0;
    }
    if (uVar1 == 0x1a) {
      *param_3 = 0xf;
      return 0;
    }
  }
  uVar2 = confComputeGetKeySpaceFromKChannel_GH100();
  return uVar2;
}


// ===== 002f20c0 confComputeIsGpuCcCapable_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 confComputeIsGpuCcCapable_GB100(undefined8 param_1,long param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(param_2 + 0x240))();
  if (cVar1 == '\0') {
    return 1;
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_gb100.c",0xca,
               "confComputeIsGpuCcCapable_GB100",4,
               "NVRM: Cannot boot Confidential Compute as debug board is not supported.\n");
  return 0;
}


// ===== 002f2110 confComputeRotationNotifHandler_GB100 =====

undefined1  [16]
confComputeRotationNotifHandler_GB100
          (undefined8 param_1,undefined8 param_2,ulong param_3,undefined8 param_4,long param_5,
          undefined8 param_6,undefined1 param_7)

{
  undefined1 auVar1 [16];
  undefined8 extraout_RDX;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  if (*(int *)(param_5 + 0x42c) - 9U < 0x14) {
    auVar1._8_8_ = 0;
    auVar1._0_8_ = param_3;
    return auVar1 << 0x40;
  }
  auVar2._0_8_ = confComputeRotationNotifHandler_GH100();
  if ((int)auVar2._0_8_ == 0) {
    auVar2[8] = param_7;
    auVar2._9_7_ = 0;
    return auVar2;
  }
  nvAssertOkFailedNoLog
            (auVar2._0_8_ & 0xffffffff,
             "confComputeRotationNotifHandler_GH100(pGpu, pConfCompute, pRmApi, hClient, pKernelChannel, bCheckKeyRotation, bSet)"
             ,"src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_gb100.c",0xe3);
  auVar3._0_8_ = auVar2._0_8_ & 0xffffffff;
  auVar3._8_8_ = extraout_RDX;
  return auVar3;
}


// ===== 002f2180 confComputeUpdatePerChannelSecrets_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong confComputeUpdatePerChannelSecrets_GB100(long param_1,long param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  if (param_2 != 0) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_gb100.c",0xf0,
                 "confComputeUpdatePerChannelSecrets_GB100",1,
                 "NVRM: Updating secrets for channel.\n");
    uVar2 = (**(code **)(param_2 + 0x218))(uVar1,param_2,param_2 + 0x454);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "kchannelDeriveAndRetrieveKmb_HAL(pGpu, pKernelChannel, &(pKernelChannel->clientKmb))"
                 ,"src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_gb100.c",0xf3);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertFailedNoLog("pKernelChannel != NULL",
                      "src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_gb100.c",0xee);
  return 0x1f;
}


// ===== 002f2260 confComputeEnableKeyRotationSupport_GB100 =====

undefined8 confComputeEnableKeyRotationSupport_GB100(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = confComputeEnableKeyRotationSupport_GH100();
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"confComputeEnableKeyRotationSupport_GH100(pGpu, pConfCompute)",
               "src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_key_rotation_gb100.c",0x25);
  }
  *(uint *)(param_2 + 0x304) = *(uint *)(param_2 + 0x304) & 0xfffffbff;
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_key_rotation_gb100.c",0x29,
               "confComputeEnableKeyRotationSupport_GB100",1,
               "NVRM: Disabling key rotation for kernel keys.\n");
  return 0;
}


// ===== 002f22e0 confComputeGetLceKeyIdFromKChannel_GB100 =====

undefined8
confComputeGetLceKeyIdFromKChannel_GB100
          (undefined8 param_1,undefined8 param_2,int param_3,undefined2 *param_4)

{
  if (param_4 == (undefined2 *)0x0) {
    nvAssertFailedNoLog("pKeyId != NULL",
                        "src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_keystore_gb100.c",
                        0x33);
    return 0x3b;
  }
  if ((param_3 != 0) && (param_3 != 3)) {
    *param_4 = 3;
    return 0;
  }
  *param_4 = 2;
  return 0;
}


// ===== 002f2340 confComputeKeyStoreDeriveViaChannel_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 confComputeKeyStoreDeriveViaChannel_GB100(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *pcVar5;
  short sVar6;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar3 = 0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if (*(int *)(param_2 + 0x42c) != 0x31) {
    if ((0x13 < *(int *)(param_2 + 0x42c) - 9U) ||
       (iVar2 = (**(code **)(param_1 + 0x1b0))(param_1,&local_48), iVar2 != 0)) {
      return 0x3b;
    }
    pcVar4 = "update_key1";
    pcVar5 = (char *)(param_2 + 0x460);
    sVar6 = 2;
    while( true ) {
      uVar3 = portStringLength(pcVar4);
      cVar1 = libspdm_hkdf_sha256_expand(&local_48,0x20,pcVar4,uVar3,pcVar5,0x20);
      if (cVar1 == '\0') break;
      pcVar4 = pcVar5 + 8;
      while (*pcVar5 == '\0') {
        pcVar5 = pcVar5 + 1;
        if (pcVar5 == pcVar4) {
          nvDbg_Printf("src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_keystore_gb100.c",
                       0x87,"confComputeKeyStoreDeriveViaChannel_GB100",4,
                       "NVRM: Newly derived key is all zeros.\n");
          goto LAB_002f2444;
        }
      }
      if (sVar6 == 3) {
        return 0;
      }
      pcVar5 = (char *)(param_2 + 0x498);
      sVar6 = 3;
      pcVar4 = "update_key2";
    }
    portMemSet(pcVar5,0,0x20);
LAB_002f2444:
    uVar3 = 0x71;
  }
  return uVar3;
}


// ===== 002f24d0 confComputeKeyStoreRetrieveViaChannel_GB100 =====

undefined8
confComputeKeyStoreRetrieveViaChannel_GB100
          (undefined8 param_1,long param_2,uint param_3,uint param_4,long param_5)

{
  bool bVar1;
  undefined8 uVar2;
  
  if (3 < param_4) {
    return 0x1f;
  }
  if (*(int *)(param_2 + 0x42c) != 0x31) {
    uVar2 = 0x3b;
    if (*(int *)(param_2 + 0x42c) - 9U < 0x14) {
      if (param_4 == 1) {
        if (param_3 != 3) {
          nvAssertFailedNoLog("rotateOperation == ROTATE_IV_ALL_VALID",
                              "src/kernel/gpu/conf_compute/arch/blackwell/conf_compute_keystore_gb100.c"
                              ,0xc0);
        }
        *(undefined4 *)(param_2 + 0x454) = 0;
        *(undefined8 *)(param_2 + 0x458) = 0;
        *(undefined8 *)(param_2 + 0x480) = 0;
        *(undefined8 *)(param_2 + 0x488) = 0;
        *(undefined8 *)(param_2 + 0x490) = 0;
        *(undefined4 *)(param_2 + 0x4c0) = 0;
        *(undefined8 *)(param_2 + 0x4b8) = 0;
        return 0;
      }
      bVar1 = param_4 - 2 < 2;
      if ((param_3 == 0 || param_3 == 3) && (bVar1)) {
        *(long *)(param_5 + 4) = *(long *)(param_5 + 4) + 1;
      }
      if (((param_3 & 0xfffffffd) == 1) && (bVar1)) {
        *(long *)(param_5 + 0x3c) = *(long *)(param_5 + 0x3c) + 1;
        *(undefined1 *)(param_5 + 0x78) = 0;
      }
      uVar2 = 0;
    }
    return uVar2;
  }
  uVar2 = confComputeKeyStoreRetrieveViaChannel_GH100();
  return uVar2;
}


// ===== 002f25e0 confComputeGetCurrentKeySeed_GB100 =====

long confComputeGetCurrentKeySeed_GB100(long param_1)

{
  return param_1 + 0xa60;
}


// ===== 002f25f0 confComputeDeriveInitialKeySeed_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte confComputeDeriveInitialKeySeed_GB100(long param_1)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = (**(code **)(param_1 + 0x290))();
  uVar3 = portStringLength("ce_channel");
  cVar1 = libspdm_hkdf_sha256_expand(param_1 + 0xa38,0x20,"ce_channel",uVar3,uVar2,0x20);
  return -(cVar1 == '\0') & 0x71;
}


// ===== 002f2650 confComputeGetAndUpdateCurrentKeySeed_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 confComputeGetAndUpdateCurrentKeySeed_GB100(long param_1,undefined8 param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  portMemCopy(param_2,0x20,param_1 + 0xa60,0x20);
  portMemSet(param_1 + 0xa60,0,0x20);
  uVar2 = (**(code **)(param_1 + 0x290))(param_1);
  uVar3 = portStringLength("update_keyseeed");
  cVar1 = libspdm_hkdf_sha256_expand(param_2,0x20,"update_keyseeed",uVar3,uVar2,0x20);
  if (cVar1 != '\0') {
    return 0;
  }
  portMemSet(param_2,0,0x20);
  return 0x71;
}


// ===== 002f2710 confComputeIsDebugModeEnabled_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint confComputeIsDebugModeEnabled_GH100(long param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(param_1 + 0x438))();
  uVar2 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x74c,0);
  return ~uVar2 & 1;
}


// ===== 002f2750 confComputeIsGpuCcCapable_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint confComputeIsGpuCcCapable_GH100(long param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  iVar1 = (**(code **)(param_1 + 0x438))();
  uVar2 = (**(code **)(param_2 + 0x240))(param_1,param_2);
  if ((char)uVar2 == '\0') {
    uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x4e04,0);
    if ((uVar3 & 1) != 0) {
      uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x4e08,0);
      if ((uVar3 & 1) != 0) {
        uVar2 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x4e0c,0);
        uVar2 = ~uVar2 & 1;
      }
    }
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x4d,
               "confComputeIsGpuCcCapable_GH100",4,
               "NVRM: Cannot boot Confidential Compute as debug board is not supported.\n");
  return 0;
}


// ===== 002f2840 confComputeDeriveSecretsForCEKeySpace_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int confComputeDeriveSecretsForCEKeySpace_GH100(long param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 local_84;
  undefined8 uStack_7c;
  undefined8 local_74;
  undefined1 local_68 [12];
  undefined1 local_5c [4];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar5 = 0;
  if (param_1 != 0) {
    uVar5 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar3 = gpuEngineGetGpu(uVar5);
  local_58 = 0;
  local_50 = 0;
  uVar1 = 0;
  local_48 = 0;
  local_40 = 0;
  do {
    uVar4 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)&local_84 + uVar4) = 0;
    *(undefined8 *)((long)&uStack_7c + uVar4) = 0;
    *(undefined8 *)((long)&local_74 + uVar4) = 0;
    *(undefined8 *)(&stack0xffffffffffffff94 + uVar4) = 0;
  } while (uVar1 < 0x40);
  local_84._0_4_ = gpuGetNv2080EngineType_IMPL(param_2);
  iVar2 = (**(code **)(lVar3 + 0x3b90))
                    (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),*(undefined4 *)(lVar3 + 0x3b3c),
                     0x20800ae2,&local_84,0x4c);
  if (iVar2 == 0) {
    uVar1 = param_3 << 0x10;
    iVar2 = (**(code **)(param_1 + 0x298))(param_1,uVar1);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(param_1 + 0x298))(param_1,uVar1 | 1);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(param_1 + 0x298))(param_1,uVar1 | 2);
        if (iVar2 == 0) {
          iVar2 = (**(code **)(param_1 + 0x298))(param_1,uVar1 | 3);
          if (iVar2 == 0) {
            (**(code **)(param_1 + 0x260))(param_1,uVar1,(long)&local_84 + 4);
            (**(code **)(param_1 + 0x260))(param_1,uVar1 | 1,&local_74);
            (**(code **)(param_1 + 0x260))(param_1,uVar1 | 2,local_68);
            (**(code **)(param_1 + 0x260))(param_1,uVar1 | 3,local_5c);
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar2,
                       "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(ccKeyspaceLCEIndex, CC_LKEYID_LCE_D2H_KERN))"
                       ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x88);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(ccKeyspaceLCEIndex, CC_LKEYID_LCE_H2D_KERN))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x86);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(ccKeyspaceLCEIndex, CC_LKEYID_LCE_D2H_USER))"
                   ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x84);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,
                 "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(ccKeyspaceLCEIndex, CC_LKEYID_LCE_H2D_USER))"
                 ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x82);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_CONF_COMPUTE_DERIVE_LCE_KEYS, &params, sizeof(params))"
               ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x7b);
  }
  return iVar2;
}


// ===== 002f2aa0 confComputeDeriveSecrets_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong confComputeDeriveSecrets_GH100(long param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  undefined4 local_1c;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar4);
  if (*(char *)(lVar2 + 0x909) != '\0') {
    if (param_2 == 0x16) {
      (**(code **)(param_1 + 0x1a0))(param_1,0xe,7);
    }
    else if (param_2 < 0x17) {
      if (param_2 == 0x13) {
        (**(code **)(param_1 + 0x1a0))(param_1,0xb,4);
      }
      else if (param_2 < 0x14) {
        if (param_2 == 0x11) {
          (**(code **)(param_1 + 0x1a0))(param_1,9,2);
        }
        else {
          if (param_2 != 0x12) {
            return 0x1f;
          }
          (**(code **)(param_1 + 0x1a0))(param_1,10,3);
        }
      }
      else if (param_2 == 0x14) {
        (**(code **)(param_1 + 0x1a0))(param_1,0xc,5);
      }
      else {
        (**(code **)(param_1 + 0x1a0))(param_1,0xd,6);
      }
    }
    else {
      if (param_2 == 0x2f) {
        local_3c = 0;
        local_1c = 0;
        local_34 = 0;
        local_2c = 0;
        local_24 = 0;
        local_40 = 0x26;
        uVar1 = (**(code **)(lVar2 + 0x3b90))
                          (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),
                           *(undefined4 *)(lVar2 + 0x3b3c),0x20800ae1,&local_40,0x28);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_CONF_COMPUTE_DERIVE_SWL_KEYS, &params, sizeof(params))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xc2);
          return (ulong)uVar1;
        }
        (**(code **)(param_1 + 0x260))(param_1,0x10000,(long)&local_34 + 4);
        (**(code **)(param_1 + 0x260))(param_1,0x10002,&local_3c);
        (**(code **)(param_1 + 0x260))(param_1,0x10004,&local_24);
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,0x10000);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_SEC2, CC_LKEYID_CPU_SEC2_DATA_USER))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xd5);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,0x10001);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_SEC2, CC_LKEYID_CPU_SEC2_HMAC_USER))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xd7);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,0x10002);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_SEC2, CC_LKEYID_CPU_SEC2_DATA_KERN))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xd9);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,0x10003);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_SEC2, CC_LKEYID_CPU_SEC2_HMAC_KERN))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xdb);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,0x10004);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_SEC2, CC_LKEYID_CPU_SEC2_DATA_SCRUBBER))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xdd);
          return (ulong)uVar1;
        }
        uVar3 = (**(code **)(param_1 + 0x298))(param_1,0x10005);
        if ((int)uVar3 != 0) {
          nvAssertOkFailedNoLog
                    (uVar3 & 0xffffffff,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_SEC2, CC_LKEYID_CPU_SEC2_HMAC_SCRUBBER))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xdf);
          return uVar3 & 0xffffffff;
        }
        return uVar3;
      }
      if (0x2f < param_2) {
        if (param_2 != 0x32) {
          return 0x1f;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,1);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_GSP_CPU_LOCKED_RPC))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xae);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,0);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_CPU_GSP_LOCKED_RPC))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xb0);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,3);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_GSP_CPU_DMA))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xb2);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,2);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_CPU_GSP_DMA))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xb4);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,5);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_GSP_CPU_REPLAYABLE_FAULT))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xb6);
          return (ulong)uVar1;
        }
        uVar1 = (**(code **)(param_1 + 0x298))(param_1,7);
        if (uVar1 != 0) {
          nvAssertOkFailedNoLog
                    (uVar1,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_GSP_CPU_NON_REPLAYABLE_FAULT))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xb8);
          return (ulong)uVar1;
        }
        uVar3 = (**(code **)(param_1 + 0x298))(param_1,10);
        if ((int)uVar3 != 0) {
          nvAssertOkFailedNoLog
                    (uVar3 & 0xffffffff,
                     "confComputeKeyStoreDeriveKey_HAL(pConfCompute, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_CPU_GSP_NVLE_P2P_WRAPPING))"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0xba);
          return uVar3 & 0xffffffff;
        }
        return uVar3;
      }
      if (param_2 == 0x17) {
        (**(code **)(param_1 + 0x1a0))(param_1,0xf,8);
      }
      else {
        if (param_2 != 0x18) {
          return 0x1f;
        }
        (**(code **)(param_1 + 0x1a0))(param_1,0x10,9);
      }
    }
  }
  return 0;
}


// ===== 002f3080 confComputeGetEngineIdFromKeySpace_GH100 =====

int confComputeGetEngineIdFromKeySpace_GH100(undefined8 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 != 0) {
    if (param_2 != 1) {
      if (param_2 - 2U < 8) {
        iVar1 = param_2 + 9;
      }
      return iVar1;
    }
    iVar1 = 0x31;
  }
  return iVar1;
}


// ===== 002f30b0 confComputeGlobalKeyIsKernelPriv_GH100 =====

undefined4 confComputeGlobalKeyIsKernelPriv_GH100(undefined8 param_1,uint param_2)

{
  uint uVar1;
  undefined3 uVar2;
  uint uVar3;
  
  uVar3 = param_2 >> 0x10;
  if (uVar3 == 0) {
    return 1;
  }
  uVar1 = (param_2 & 0xffff) - 2;
  uVar2 = (undefined3)(uVar1 >> 8);
  if (uVar3 != 1) {
    if (uVar3 - 2 < 8) {
      return CONCAT31(uVar2,uVar1 < 2);
    }
    nvAssertFailedNoLog("(keySpace >= CC_KEYSPACE_LCE0) && (keySpace <= CC_KEYSPACE_LCE7)",
                        "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x169);
    return CONCAT31(uVar2,uVar1 < 2);
  }
  return CONCAT31(uVar2,uVar1 < 4);
}


// ===== 002f3120 confComputeGlobalKeyIsUvmKey_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 confComputeGlobalKeyIsUvmKey_GH100(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if ((param_2 >> 0x10 != 0) && ((param_2 >> 0x10 != 1 || (1 < (param_2 & 0xffff) - 4)))) {
    uVar1 = (**(code **)(param_1 + 0x200))();
    return uVar1;
  }
  return 0;
}


// ===== 002f3150 confComputeRotationNotifHandler_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
confComputeRotationNotifHandler_GH100
          (undefined8 param_1,long param_2,long param_3,undefined4 param_4,long param_5,
          undefined1 *param_6,char param_7)

{
  int iVar1;
  undefined4 local_44;
  undefined1 local_40 [4];
  int local_3c [3];
  
  if (param_7 == '\0') {
    iVar1 = confComputeUpdateFreedChannelStats_IMPL(param_1,param_2,param_5);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"confComputeUpdateFreedChannelStats(pGpu, pConfCompute, pKernelChannel)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1a7);
    }
    iVar1 = (**(code **)(param_2 + 0x210))(param_1,param_2,param_5,&local_44,local_40);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,
                 "confComputeGetKeyPairByChannel(pGpu, pConfCompute, pKernelChannel, &h2dKey, &d2hKey)"
                 ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1aa);
    }
    iVar1 = confComputeGetKeyRotationStatus_IMPL(param_2,local_44,local_3c);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &state)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1ab);
    }
    if ((local_3c[0] == 1) || (local_3c[0] == 6)) {
      *param_6 = 1;
    }
    iVar1 = (**(code **)(param_5 + 0x210))(param_1,param_5,0,0);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"kchannelSetEncryptionStatsBuffer_HAL(pGpu, pKernelChannel, NULL, NV_FALSE)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1b2);
    }
    (**(code **)(param_3 + 0x18))(param_3,param_4,*(undefined4 *)(param_5 + 0x4d0));
    iVar1 = (**(code **)(param_5 + 0x220))(param_1,param_5,0);
    if (iVar1 == 0) {
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar1,"kchannelSetKeyRotationNotifier_HAL(pGpu, pKernelChannel, NV_FALSE)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1b4);
  }
  else {
    iVar1 = (**(code **)(param_5 + 0x220))(param_1,param_5,1);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"kchannelSetKeyRotationNotifier_HAL(pGpu, pKernelChannel, NV_TRUE)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1a2);
    }
  }
  return 0;
}


// ===== 002f3360 confComputeUpdateSecrets_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int confComputeUpdateSecrets_GH100(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined4 local_80;
  uint local_7c;
  long local_78;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined4 local_54;
  undefined1 local_50 [40];
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar5 = gpuEngineGetGpu(uVar6);
  local_6c = 0;
  local_64 = 0;
  local_5c = 0;
  local_54 = 0;
  if (param_2 >> 0x10 == 0) {
    nvAssertFailedNoLog("CC_GKEYID_GET_KEYSPACE(globalKeyId) != CC_KEYSPACE_GSP",
                        "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1c2);
  }
  confComputeGetKeyPairByKey_IMPL(param_1,param_2,&local_80,&local_7c);
  local_6c = CONCAT44(local_6c._4_4_,local_80);
  iVar3 = (**(code **)(lVar5 + 0x3b90))
                    (lVar5 + 0x3b58,*(undefined4 *)(lVar5 + 0x3b34),*(undefined4 *)(lVar5 + 0x3b3c),
                     0x20800ae5,&local_6c,0x1c);
  if (iVar3 == 0) {
    iVar3 = (**(code **)(param_1 + 0x268))(param_1,local_80);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(param_1 + 0x268))(param_1,local_7c);
      if (iVar3 == 0) {
        (**(code **)(param_1 + 0x260))(param_1,local_80,(long)&local_6c + 4);
        uVar1 = local_7c >> 0x10;
        if ((1 < uVar1) && (uVar2 = (**(code **)(param_1 + 0x1f8))(param_1), uVar1 <= uVar2)) {
          (**(code **)(param_1 + 0x260))(param_1,local_7c,&local_5c);
        }
        iVar3 = confComputeInitChannelIterForKey_IMPL(lVar5,param_1,local_80,local_50);
        if (iVar3 == 0) {
          while (iVar4 = confComputeGetNextChannelForKey_IMPL
                                   (lVar5,param_1,local_50,local_80,&local_78), iVar4 == 0) {
            iVar4 = (**(code **)(param_1 + 400))(param_1,local_78,3,0,local_78 + 0x454);
            if (iVar4 != 0) {
              nvAssertOkFailedNoLog
                        (iVar4,
                         "confComputeKeyStoreRetrieveViaChannel( pConfCompute, pKernelChannel, ROTATE_IV_ALL_VALID, CHANNEL_IV_OPERATION_NONE, &pKernelChannel->clientKmb)"
                         ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1e3);
              return iVar4;
            }
            uVar1 = local_7c >> 0x10;
            *(undefined4 *)(local_78 + 0x454) = 0;
            if ((uVar1 < 2) || (uVar2 = (**(code **)(param_1 + 0x1f8))(param_1), uVar2 < uVar1)) {
              *(undefined8 *)(local_78 + 0x48c) = 0;
              *(undefined8 *)(local_78 + 0x494) = 0;
              *(undefined8 *)(local_78 + 0x49c) = 0;
            }
            else {
              *(undefined4 *)(local_78 + 0x48c) = 0;
            }
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,"confComputeInitChannelIterForKey(pGpu, pConfCompute, h2dKey, &iterator)"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1df);
        }
        return iVar3;
      }
      nvAssertOkFailedNoLog
                (iVar3,"confComputeKeyStoreUpdateKey_HAL(pConfCompute, d2hKey)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1d0);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,"confComputeKeyStoreUpdateKey_HAL(pConfCompute, h2dKey)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1cf);
    }
    return iVar3;
  }
  nvAssertOkFailedNoLog
            (iVar3,
             "pRmApi->Control( pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_CONF_COMPUTE_ROTATE_KEYS, &params, sizeof(NV2080_CTRL_INTERNAL_CONF_COMPUTE_ROTATE_KEYS_PARAMS))"
             ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x1c7);
  return iVar3;
}


// ===== 002f36a0 confComputeTestPlatformSupport_GH100 =====

undefined8 confComputeTestPlatformSupport_GH100(long param_1,long param_2)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x7f6);
  if (((((ushort)(sVar1 + 0xdcc0U) < 0x40) ||
       ((ushort)(sVar1 + 0xd6c0U) < 0x40 || (ushort)(sVar1 + 0xce40U) < 0x40)) || (sVar1 == 0x31a1))
     && (*(char *)(param_2 + 0x2a8) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_gh100.c",0x208,
                 "confComputeTestPlatformSupport_GH100",4,
                 "NVRM: CC is not supported on self-hosted platforms\n");
    return 0x56;
  }
  return 0;
}


// ===== 002f3730 keyRotationTimeoutCallback =====

ulong keyRotationTimeoutCallback(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (*(undefined4 **)(param_3 + 8) == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pEvent->pUserData != NULL",
                        "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                        0x17d);
    return 0x40;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x1d18);
  confComputeGetKeyPairByKey_IMPL(uVar1,**(undefined4 **)(param_3 + 8),&local_20,&local_1c);
  uVar2 = confComputeSetKeyRotationStatus_IMPL(uVar1,local_20,3);
  if (uVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x181,
                 "keyRotationTimeoutCallback",1,"NVRM: Hit timeout on key 0x%x, triggering KR\n",
                 local_20);
    uVar3 = confComputePerformKeyRotation_IMPL(param_1,uVar1,local_20,local_1c,1);
    return uVar3;
  }
  nvAssertOkFailedNoLog
            (uVar2,
             "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_FAILED_TIMEOUT)"
             ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x180);
  return (ulong)uVar2;
}


// ===== 002f3820 triggerKeyRotationByKeyPair =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int triggerKeyRotationByKeyPair(long param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  long local_b0;
  long local_a8;
  long local_a0;
  int local_7c;
  uint local_78;
  undefined1 local_74 [4];
  uint local_70;
  uint local_6c;
  ulong local_68;
  ulong local_60 [6];
  
  iVar4 = confComputeGetKeyRotationStatus_IMPL(param_2,param_3,&local_7c);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &state)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0xe7);
    return iVar4;
  }
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,&local_78);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0xea);
    return iVar4;
  }
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_4,local_74);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0xeb);
    return iVar4;
  }
  if (local_7c - 3U < 2) {
    return 0;
  }
  if (local_7c == 5) {
    return 0x40;
  }
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  local_68 = 0;
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,&local_70);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x198);
LAB_002f3d69:
    nvAssertOkFailedNoLog
              (iVar4,"calculateEncryptionStatsByKeyPair(pGpu, pConfCompute, h2dKey, d2hKey)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0xfe);
    return iVar4;
  }
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_4,&local_6c);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x199);
    goto LAB_002f3d69;
  }
  iVar4 = confComputeInitChannelIterForKey_IMPL(param_1,param_2,param_3,local_60);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeInitChannelIterForKey(pGpu, pConfCompute, h2dKey, &iter)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x19b);
    goto LAB_002f3d69;
  }
  local_b0 = 0;
  local_a8 = 0;
  local_a0 = 0;
  lVar11 = 0;
  while (iVar4 = confComputeGetNextChannelForKey_IMPL(param_1,param_2,local_60,param_3,&local_68),
        iVar4 == 0) {
    if (*(long *)(local_68 + 0x4d8) != 0) {
      plVar1 = *(long **)(local_68 + 0x4e0);
      if (plVar1 == (long *)0x0) {
        iVar4 = 0x40;
        nvAssertFailedNoLog("pEncStats != NULL",
                            "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c"
                            ,0x1a5);
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x1a6,"calculateEncryptionStatsByKeyPair",4,
                     "NVRM: Failed to get stats for channel 0x%08x RM engineId = 0x%x\n",
                     *(int *)(local_68 + 0x2b0) << 0x18 | *(uint *)(local_68 + 0x2b4),
                     *(undefined4 *)(local_68 + 0x42c));
        goto LAB_002f3d69;
      }
      lVar11 = lVar11 + *plVar1;
      local_a8 = local_a8 + plVar1[3];
      local_a0 = local_a0 + plVar1[2];
      local_b0 = local_b0 + plVar1[1];
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1b1
                   ,"calculateEncryptionStatsByKeyPair",0,
                   "NVRM: Encryption stats for channel 0x%08x with h2dKey 0x%x\n",
                   *(int *)(local_68 + 0x2b0) << 0x18 | *(uint *)(local_68 + 0x2b4),param_3);
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1b5
                   ,"calculateEncryptionStatsByKeyPair",0,
                   "NVRM: Total h2d bytes encrypted  = 0x%llx\n",plVar1[2]);
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1b6
                   ,"calculateEncryptionStatsByKeyPair",0,
                   "NVRM: Total d2h bytes encrypted  = 0x%llx\n",plVar1[3]);
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1b7
                   ,"calculateEncryptionStatsByKeyPair",0,"NVRM: Total h2d encrypt ops  = 0x%llx\n",
                   *plVar1);
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1b8
                   ,"calculateEncryptionStatsByKeyPair",0,"NVRM: Total d2h encrypt ops  = 0x%llx\n",
                   plVar1[1]);
    }
  }
  lVar9 = (ulong)local_70 * 0x10 + param_2;
  lVar7 = (ulong)local_6c * 0x10 + param_2;
  local_a8 = local_a8 + *(long *)(lVar7 + 0xc48);
  lVar2 = *(long *)(lVar7 + 0xc50);
  *(long *)(lVar9 + 800) = lVar11 + *(long *)(lVar9 + 0xc50);
  *(long *)(lVar9 + 0x318) = local_a0 + *(long *)(lVar9 + 0xc48);
  *(long *)(lVar7 + 0x318) = local_a8;
  *(long *)(lVar7 + 800) = local_b0 + lVar2;
  if (local_a8 != 0 || *(long *)(lVar9 + 0x318) != 0) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1c9,
                 "calculateEncryptionStatsByKeyPair",0,
                 "NVRM: Aggregate stats for h2dKey 0x%x and d2hKey 0x%x\n",param_3,param_4);
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1ca,
                 "calculateEncryptionStatsByKeyPair",0,"NVRM: Total h2d bytes encrypted  = 0x%llx\n"
                 ,*(undefined8 *)(param_2 + 0x318 + (ulong)local_70 * 0x10));
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1cb,
                 "calculateEncryptionStatsByKeyPair",0,"NVRM: Total d2h bytes encrypted  = 0x%llx\n"
                 ,*(undefined8 *)(param_2 + 0x318 + (ulong)local_6c * 0x10));
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1cc,
                 "calculateEncryptionStatsByKeyPair",0,"NVRM: Total h2d encrypt ops  = 0x%llx\n",
                 *(undefined8 *)(param_2 + 800 + (ulong)local_70 * 0x10));
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1cd,
                 "calculateEncryptionStatsByKeyPair",0,"NVRM: Total d2h encrypt ops  = 0x%llx\n",
                 *(undefined8 *)(param_2 + 800 + (ulong)local_6c * 0x10));
  }
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,&local_68);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1dc);
  }
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_4,local_60);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1dd);
  }
  cVar3 = confComputeIsUpperThresholdCrossed_IMPL
                    (param_2,param_2 + 0x318 + (local_68 & 0xffffffff) * 0x10);
  if ((cVar3 != '\0') ||
     (cVar3 = confComputeIsUpperThresholdCrossed_IMPL
                        (param_2,param_2 + 0x318 + (local_60[0] & 0xffffffff) * 0x10), cVar3 != '\0'
     )) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x102,
                 "triggerKeyRotationByKeyPair",4,"NVRM: Crossed UPPER threshold for key = 0x%x\n",
                 param_3);
    iVar4 = confComputeSetKeyRotationStatus_IMPL(param_2,param_3,4);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_FAILED_THRESHOLD)"
                 ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x103)
      ;
      return iVar4;
    }
    iVar4 = confComputePerformKeyRotation_IMPL(param_1,param_2,param_3,param_4,1);
    if (iVar4 == 0) {
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar4,"confComputePerformKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey, NV_TRUE)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x104);
    return iVar4;
  }
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,&local_68);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1ec);
  }
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_4,local_60);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x1ed);
  }
  cVar3 = confComputeIsLowerThresholdCrossed_IMPL
                    (param_2,param_2 + 0x318 + (local_68 & 0xffffffff) * 0x10);
  if ((cVar3 == '\0') &&
     (cVar3 = confComputeIsLowerThresholdCrossed_IMPL
                        (param_2,param_2 + 0x318 + (local_60[0] & 0xffffffff) * 0x10), cVar3 == '\0'
     )) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x108,
               "triggerKeyRotationByKeyPair",1,"NVRM: Crossed LOWER threshold for key = 0x%x\n",
               param_3);
  if (local_7c == 0) {
    iVar4 = confComputeSetKeyRotationStatus_IMPL(param_2,param_3,1);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_PENDING)"
                 ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x10b)
      ;
      return iVar4;
    }
    cVar3 = (**(code **)(param_2 + 0x208))(param_2,param_3);
    if (cVar3 == '\0') {
      uVar8 = *(undefined8 *)(param_1 + 0x1b88);
      if (*(long *)(param_2 + 0x1368 + (ulong)local_78 * 0x10) == 0) {
        puVar6 = (undefined4 *)portMemAllocNonPaged(4);
        if (puVar6 == (undefined4 *)0x0) {
          return 0x51;
        }
        *puVar6 = param_3;
        iVar4 = tmrEventCreate_IMPL(uVar8,param_2 + 0x1368 + (ulong)local_78 * 0x10,
                                    keyRotationTimeoutCallback,puVar6,0);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,
                     "tmrEventCreate(pTmr, &pConfCompute->keyRotationTimeoutInfo[h2dIndex].pTimer, keyRotationTimeoutCallback, (void*)pH2DKey, TMR_FLAGS_NONE)"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x121);
          return iVar4;
        }
      }
      cVar3 = confComputeIsUvmKeyRotationPending_IMPL(param_1,param_2);
      if (cVar3 == '\0') {
        iVar4 = tmrEventScheduleRel_IMPL
                          (uVar8,*(undefined8 *)(param_2 + 0x1368 + (ulong)local_78 * 0x10),
                           (ulong)*(uint *)(param_2 + 0x1c50) * 1000000000);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,
                     "tmrEventScheduleRelSec(pTmr, pConfCompute->keyRotationTimeoutInfo[h2dIndex].pTimer, pConfCompute->keyRotationTimeout)"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     300);
          return iVar4;
        }
      }
      else {
        iVar4 = confComputeStopKeyRotationTimer_IMPL(param_1,param_2,param_3);
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,"confComputeStopKeyRotationTimer(pGpu, pConfCompute, h2dKey)",
                     "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x127);
          return iVar4;
        }
      }
    }
    else {
      iVar4 = 1;
      do {
        (**(code **)(param_2 + 0x220))(param_1,param_2,iVar4,0,&local_68,0);
        iVar5 = confComputeGetKeyRotationStatus_IMPL(param_2,local_68 & 0xffffffff,local_60);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "confComputeGetKeyRotationStatus(pConfCompute, userH2DKey, &userKRStatus)",
                     "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x13d);
          return iVar5;
        }
        if ((int)local_60[0] == 1) {
          nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                       0x140,"triggerKeyRotationByKeyPair",1,
                       "NVRM: User key rotation pending on key 0x%x\n");
          iVar5 = confComputeStopKeyRotationTimer_IMPL(param_1,param_2,local_68 & 0xffffffff);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,"confComputeStopKeyRotationTimer(pGpu, pConfCompute, userH2DKey)",
                       "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                       0x141);
            return iVar5;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 10);
    }
    local_60[0] = 0;
    local_60[1] = 0;
    local_60[2] = 0;
    local_60[3] = 0;
    local_60[4] = 0;
    local_68 = 0;
    iVar4 = confComputeInitChannelIterForKey_IMPL(param_1,param_2,param_3,local_60);
    uVar8 = 0x150;
    if (iVar4 != 0) goto LAB_002f43e0;
    while (iVar4 = confComputeGetNextChannelForKey_IMPL(param_1,param_2,local_60,param_3,&local_68),
          iVar4 == 0) {
      iVar4 = kchannelUpdateNotifierMem_IMPL
                        (local_68,2,*(undefined4 *)(param_2 + 0x1a88 + (ulong)local_78 * 4),0,1);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "kchannelUpdateNotifierMem(pKernelChannel, NV_CHANNELGPFIFO_NOTIFICATION_TYPE_KEY_ROTATION_STATUS, pConfCompute->keyRotationCount[h2dIndex], 0, (NvU32)KEY_ROTATION_STATUS_PENDING)"
                   ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                   0x153);
        return iVar4;
      }
      if (local_68 == 0) {
        uVar10 = 0xffffffff;
      }
      else {
        uVar10 = *(int *)(local_68 + 0x2b0) << 0x18 | *(uint *)(local_68 + 0x2b4);
      }
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x155
                   ,"triggerKeyRotationByKeyPair",1,
                   "NVRM: channel 0x%08x has pending key rotation, writing notifier with val 0x%x\n"
                   ,uVar10,1);
      kchannelNotifyEvent_IMPL
                (local_68,9,*(undefined4 *)(param_2 + 0x1a88 + (ulong)local_78 * 4),1,0,0);
    }
  }
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  local_60[4] = 0;
  local_68 = 0;
  iVar4 = confComputeInitChannelIterForKey_IMPL(param_1,param_2,param_3,local_60);
  if (iVar4 == 0) {
    iVar4 = confComputeGetNextChannelForKey_IMPL(param_1,param_2,local_60,param_3,&local_68);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = confComputePerformKeyRotation_IMPL(param_1,param_2,param_3,param_4,1);
    if (iVar4 == 0) {
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar4,"confComputePerformKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey, NV_TRUE)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x16c);
    return iVar4;
  }
  uVar8 = 0x169;
LAB_002f43e0:
  nvAssertOkFailedNoLog
            (iVar4,"confComputeInitChannelIterForKey(pGpu, pConfCompute, h2dKey, &iter)",
             "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",uVar8);
  return iVar4;
}


// ===== 002f44e0 confComputeEnableKeyRotationSupport_GH100 =====

undefined8 confComputeEnableKeyRotationSupport_GH100(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint local_2c [3];
  
  if ((*(char *)(param_2 + 0x2a8) != '\0') && (*(char *)(param_2 + 0x2a9) != '\0')) {
    *(undefined1 *)(param_2 + 0x2b0) = 1;
    iVar3 = osReadRegistryDword(param_1,"RmKeyRotationThresholdDelta",local_2c);
    if (iVar3 == 0) {
      if (local_2c[0] == 0) {
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x224,"initKeyRotationRegistryOverrides",4,
                     "NVRM: Illegal value for RmKeyRotationThresholdDelta.\n");
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x225,"initKeyRotationRegistryOverrides",4,
                     "NVRM: Cancelling override of threshold delta.\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x229,"initKeyRotationRegistryOverrides",1,
                     "NVRM: Setting key rotation threshold delta to %u.\n");
        *(ulong *)(param_2 + 0x1c58) = (ulong)local_2c[0];
        iVar3 = confComputeSetKeyRotationThreshold_IMPL(param_2,*(undefined8 *)(param_2 + 0x310));
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "confComputeSetKeyRotationThreshold(pConfCompute, pConfCompute->attackerAdvantage)"
                     ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x22b);
        }
      }
    }
    else {
      iVar3 = osReadRegistryDword(param_1,"RmKeyRotationLowerThreshold",local_2c);
      uVar1 = local_2c[0];
      if (iVar3 == 0) {
        iVar3 = osReadRegistryDword(param_1,"RmKeyRotationUpperThreshold",local_2c);
        uVar2 = local_2c[0];
        if (iVar3 == 0) {
          if (uVar1 < local_2c[0]) {
            nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c"
                         ,0x238,"initKeyRotationRegistryOverrides",1,
                         "NVRM: Setting key rotation lower threshold to %u and upper threshold to %u.\n"
                         ,uVar1,local_2c[0]);
            *(ulong *)(param_2 + 0x1c60) = (ulong)uVar2;
            *(ulong *)(param_2 + 0x1c68) = (ulong)uVar1;
          }
          else {
            nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c"
                         ,0x23f,"initKeyRotationRegistryOverrides",4,
                         "NVRM: RmKeyRotationUpperThreshold must be greater than RmKeyRotationLowerThreshold.\n"
                        );
            nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c"
                         ,0x240,"initKeyRotationRegistryOverrides",4,
                         "NVRM: Cancelling override of upper and lower key rotation thresholds.\n");
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                       0x245,"initKeyRotationRegistryOverrides",4,
                       "NVRM: RmKeyRotationUpperThreshold must be set if RmKeyRotationLowerThreshold is set.\n"
                      );
          nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                       0x246,"initKeyRotationRegistryOverrides",4,
                       "NVRM: Cancelling override of upper and lower key rotation thresholds.\n");
        }
      }
    }
    iVar3 = osReadRegistryDword(param_1,"RmKeyRotationTimeout",local_2c);
    if (iVar3 == 0) {
      if (local_2c[0] < 2) {
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x255,"initKeyRotationRegistryOverrides",4,
                     "NVRM: Key rotation user-mode timeout must be greater than or equal to %u.\n",2
                    );
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x256,"initKeyRotationRegistryOverrides",4,
                     "NVRM: Cancelling override of user-mode timeout.\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x250,"initKeyRotationRegistryOverrides",1,
                     "NVRM: Setting key rotation user-mode timeout to %u seconds.\n");
        *(uint *)(param_2 + 0x1c50) = local_2c[0];
      }
    }
    iVar3 = osReadRegistryDword(param_1,"RmConfComputeKeyRotation",local_2c);
    if (iVar3 == 0) {
      if ((local_2c[0] & 1) == 0) {
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x264,"initKeyRotationRegistryOverrides",1,
                     "NVRM: Confidential Compute key rotation disabled via regkey override.\n");
        *(undefined2 *)(param_2 + 0x2b0) = 0;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                     0x25e,"initKeyRotationRegistryOverrides",1,
                     "NVRM: Confidential Compute key rotation enabled via regkey override.\n");
        *(undefined1 *)(param_2 + 0x2b1) = 1;
        *(uint *)(param_2 + 0x304) = local_2c[0];
      }
    }
    else if (*(char *)(param_2 + 0x2ae) == '\0') {
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x26d
                   ,"initKeyRotationRegistryOverrides",1,
                   "NVRM: Confidential Compute key rotation is enabled.\n");
      *(undefined1 *)(param_2 + 0x2b1) = 1;
      *(undefined4 *)(param_2 + 0x304) = 0x1fffff;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x273
                   ,"initKeyRotationRegistryOverrides",1,
                   "NVRM: Confidential Compute key rotation is disabled.\n");
      *(undefined1 *)(param_2 + 0x2b1) = 0;
    }
    return 0;
  }
  return 0;
}


// ===== 002f4920 confComputeEnableInternalKeyRotationSupport_GH100 =====

undefined8 confComputeEnableInternalKeyRotationSupport_GH100(undefined8 param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  uint local_c;
  
  *(undefined8 *)(param_2 + 0x308) = 0x5a827999f;
  if ((*(char *)(param_2 + 0x2a8) == '\0') || (*(char *)(param_2 + 0x2a9) == '\0')) {
    if (*(char *)(param_2 + 0x2b2) != '\0') {
      return 0;
    }
    *(undefined8 *)(param_2 + 0x308) = 0;
    return 0;
  }
  *(undefined1 *)(param_2 + 0x2b2) = 1;
  local_c = 0;
  if (*(char *)(param_2 + 0x2ae) != '\0') {
    pcVar6 = "NVRM: RM internal key rotation not supported for protected PCIe!\n";
    uVar4 = 1;
    uVar5 = 0x285;
LAB_002f49ab:
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",uVar5,
                 "initInternalKeyRotationRegistryOverrides",uVar4,pcVar6);
    *(undefined1 *)(param_2 + 0x2b2) = 0;
    goto LAB_002f49c5;
  }
  iVar3 = osReadRegistryDword(param_1,"RmConfComputeKeyRotation",&local_c);
  if (iVar3 == 0) {
    if ((local_c & 0x1000) == 0) {
      pcVar6 = "NVRM: Disabling RM internal keys for Key Rotation by regkey override!\n";
      uVar4 = 4;
      uVar5 = 0x291;
      goto LAB_002f49ab;
    }
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x28c,
                 "initInternalKeyRotationRegistryOverrides",4,
                 "NVRM: Enabling RM internal keys for Key Rotation by regkey override!\n");
    *(undefined1 *)(param_2 + 0x2b2) = 1;
  }
  else if (*(char *)(param_2 + 0x2b2) == '\0') goto LAB_002f49c5;
  iVar3 = osReadRegistryDword(param_1,"RmKeyRotationInternalThreshold",&local_c);
  uVar1 = local_c;
  if (iVar3 == 0) {
    if (0x7fffffe < local_c) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x2a1
                   ,"initInternalKeyRotationRegistryOverrides",1,
                   "NVRM: Setting internal key rotation threshold to %u.\n");
      *(ulong *)(param_2 + 0x308) = (ulong)uVar1;
      goto LAB_002f4b1c;
    }
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0x29c,
                 "initInternalKeyRotationRegistryOverrides",4,
                 "NVRM: RmKeyRotationInternalThreshold must be higher than minimum of %u!\n",
                 0x7ffffff);
    cVar2 = *(char *)(param_2 + 0x2b2);
  }
  else {
LAB_002f4b1c:
    cVar2 = *(char *)(param_2 + 0x2b2);
  }
  if (cVar2 != '\0') {
    return 0;
  }
LAB_002f49c5:
  *(undefined8 *)(param_2 + 0x308) = 0;
  return 0;
}


// ===== 002f4b50 confComputeEnableKeyRotationCallback_GH100 =====

undefined8
confComputeEnableKeyRotationCallback_GH100(undefined8 param_1,undefined8 param_2,char param_3)

{
  if (param_3 != '\0') {
    osSchedule1HzCallback(param_1,confComputeKeyRotationCallback,0,1);
    return 0;
  }
  osRemove1HzCallback(param_1,confComputeKeyRotationCallback,0);
  return 0;
}


// ===== 002f4b90 confComputeGetKeyPairForKeySpace_GH100 =====

void confComputeGetKeyPairForKeySpace_GH100
               (undefined8 param_1,undefined8 param_2,int param_3,char param_4,uint *param_5,
               uint *param_6)

{
  if (param_5 != (uint *)0x0) {
    *param_5 = -(uint)(param_4 != '\0') & 2 | param_3 << 0x10;
  }
  if (param_6 != (uint *)0x0) {
    *param_6 = param_3 << 0x10 | (-(uint)(param_4 == '\0') & 0xfffffffe) + 3;
  }
  return;
}


// ===== 002f4bc0 confComputeTriggerKeyRotation_GH100 =====

int confComputeTriggerKeyRotation_GH100(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_44;
  
  iVar2 = 1;
  local_44 = 0;
  do {
    uVar3 = *(uint *)(param_2 + 0x304);
    if ((1 << ((byte)iVar2 & 0x1f) & uVar3) == 0) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",0xba,
                   "confComputeTriggerKeyRotation_GH100",0,
                   "NVRM: Skipping keyspace = %d since mask = 0x%x\n",iVar2,uVar3);
    }
    else {
      if ((uVar3 & 0x400) != 0) {
        uVar3 = iVar2 << 0x10 | 2;
        iVar1 = triggerKeyRotationByKeyPair(param_1,param_2,uVar3,iVar2 << 0x10 | 3);
        if (iVar1 == 0) {
          uVar3 = *(uint *)(param_2 + 0x304);
        }
        else {
          nvAssertFailedNoLog("tempStatus == NV_OK",
                              "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c"
                              ,199);
          nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                       200,"confComputeTriggerKeyRotation_GH100",4,
                       "NVRM: Failed to calculate encryption statistics for H2D key 0x%x with status 0x%x\n"
                       ,uVar3,iVar1);
          uVar3 = *(uint *)(param_2 + 0x304);
          local_44 = iVar1;
        }
      }
      if ((uVar3 & 0x800) != 0) {
        uVar3 = iVar2 << 0x10;
        iVar1 = triggerKeyRotationByKeyPair(param_1,param_2,uVar3,uVar3 | 1);
        if (iVar1 != 0) {
          nvAssertFailedNoLog("tempStatus == NV_OK",
                              "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c"
                              ,0xd4);
          nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_key_rotation_gh100.c",
                       0xd5,"confComputeTriggerKeyRotation_GH100",4,
                       "NVRM: Failed to calculate encryption statistics for H2D key 0x%x with status 0x%x\n"
                       ,uVar3,iVar1);
          local_44 = iVar1;
        }
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 10);
  return local_44;
}


// ===== 002f4d90 getChannelCounter.isra.0 =====

undefined8 getChannelCounter_isra_0(long param_1,uint param_2)

{
  int iVar1;
  
  param_1 = param_1 + (ulong)param_2 * 0x44;
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 == 1) {
    return *(undefined8 *)(param_1 + 4);
  }
  if (iVar1 != 2) {
    if (iVar1 != 0) {
      nvAssertFailedNoLog("NV_FALSE",
                          "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",
                          0x2e1);
      return 0;
    }
    return 0;
  }
  return *(undefined8 *)(param_1 + 0x18);
}


// ===== 002f4e00 incrementChannelCounter =====

void incrementChannelCounter(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  param_2 = param_2 & 0xffffffff;
  lVar3 = *(long *)(param_1 + 0xa58);
  lVar1 = lVar3 + param_2 * 0x44;
  iVar2 = *(int *)(lVar1 + 0x40);
  if (iVar2 == 1) {
    *(long *)(lVar3 + 4 + param_2 * 0x44) = *(long *)(lVar1 + 4) + 1;
    return;
  }
  if (iVar2 == 2) {
    *(long *)(lVar3 + 0x18 + param_2 * 0x44) = *(long *)(lVar1 + 0x18) + 1;
    return;
  }
  if (iVar2 == 0) {
    return;
  }
  nvAssertFailedNoLog("NV_FALSE",
                      "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x2e1)
  ;
  lVar1 = *(long *)(param_1 + 0xa58);
  iVar2 = *(int *)(lVar1 + 0x40 + param_2 * 0x44);
  if (iVar2 != 1) {
    if (iVar2 == 2) {
      *(undefined8 *)(lVar1 + 0x18 + param_2 * 0x44) = 1;
    }
    return;
  }
  *(undefined8 *)(lVar1 + 4 + param_2 * 0x44) = 1;
  return;
}


// ===== 002f4f00 confComputeKeyStoreInit_GH100 =====

undefined8 confComputeKeyStoreInit_GH100(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x4d,
               "confComputeKeyStoreInit_GH100",1,"NVRM: Initializing keystore.\n");
  lVar1 = portMemAllocNonPaged(0x1e48);
  *(long *)(param_1 + 0xa58) = lVar1;
  if (lVar1 != 0) {
    portMemSet(lVar1,0,0x1e48);
    lVar1 = *(long *)(param_1 + 0xa58);
    puVar3 = (undefined4 *)(lVar1 + 0x40);
    do {
      *puVar3 = 0;
      puVar2 = puVar3 + 0x22;
      puVar3[0x11] = 0;
      puVar3 = puVar2;
    } while (puVar2 != (undefined4 *)(lVar1 + 0x370));
    *(undefined4 *)(lVar1 + 0x370) = 1;
    *(undefined4 *)(lVar1 + 0x3b4) = 2;
    *(undefined4 *)(lVar1 + 0x3f8) = 1;
    *(undefined4 *)(lVar1 + 0x43c) = 2;
    *(undefined4 *)(lVar1 + 0x480) = 1;
    *(undefined4 *)(lVar1 + 0x4c4) = 2;
    puVar3 = (undefined4 *)(lVar1 + 0x508);
    do {
      *puVar3 = 1;
      puVar2 = puVar3 + 0x22;
      puVar3[0x11] = 1;
      puVar3 = puVar2;
    } while (puVar2 != (undefined4 *)(lVar1 + 0x1e88));
    return 0;
  }
  return 0x51;
}


// ===== 002f5030 confComputeKeyStoreDeinit_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void confComputeKeyStoreDeinit_GH100(long param_1)

{
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x76,
               "confComputeKeyStoreDeinit_GH100",1,"NVRM: Deinitializing keystore.\n");
  if (*(long *)(param_1 + 0xa58) != 0) {
    portMemSet(*(long *)(param_1 + 0xa58),0,0x1e48);
    (**(code **)(param_1 + 0x2a0))(param_1);
    portMemFree(*(undefined8 *)(param_1 + 0xa58));
    *(undefined8 *)(param_1 + 0xa58) = 0;
  }
  return;
}


// ===== 002f50b0 confComputeKeyStoreGetExportMasterKey_GH100 =====

long confComputeKeyStoreGetExportMasterKey_GH100(long param_1)

{
  return param_1 + 0xa38;
}


// ===== 002f50c0 confComputeKeyStoreDeriveKey_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int confComputeKeyStoreDeriveKey_GH100(long param_1,ulong param_2)

{
  long lVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  int *piVar7;
  char *pcVar8;
  ulong uVar9;
  long lVar10;
  uint uVar11;
  uint local_3c [3];
  
  sVar2 = (short)param_2;
  lVar1 = *(long *)(param_1 + 0xa58);
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,local_3c);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, globalKeyId, &slotIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x93);
    return iVar4;
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x94,
               "confComputeKeyStoreDeriveKey_GH100",1,"NVRM: Deriving key for global key ID %x.\n",
               param_2 & 0xffffffff);
  uVar5 = (uint)param_2;
  if (uVar5 - 0x10001 < 5) {
    if ((0x15UL >> ((ulong)(uVar5 - 0x10001) & 0x3f) & 1) == 0) {
      lVar1 = lVar1 + 0xc;
    }
    else {
      lVar1 = lVar1 + 0x20;
    }
    lVar10 = lVar1 + (ulong)local_3c[0] * 0x44;
    uVar9 = (ulong)(uVar5 - 1 & 0xffff);
    uVar6 = portStringLength(*(undefined8 *)(CSWTCH_114 + uVar9 * 8));
    pcVar8 = *(char **)(CSWTCH_114 + uVar9 * 8);
    goto LAB_002f5180;
  }
  lVar10 = lVar1 + 0xc + (ulong)local_3c[0] * 0x44;
  uVar11 = uVar5 >> 0x10;
  if (uVar11 == 0) {
    if (sVar2 == 1) {
      uVar6 = portStringLength("gsp_cpu_locked_rpc");
      pcVar8 = "gsp_cpu_locked_rpc";
      goto LAB_002f5180;
    }
    if (sVar2 == 0) {
      uVar6 = portStringLength("cpu_gsp_locked_rpc");
      pcVar8 = "cpu_gsp_locked_rpc";
      goto LAB_002f5180;
    }
    if ((ushort)(uVar5 - 2) < 9) {
      uVar9 = (ulong)(uVar5 - 2 & 0xffff);
      uVar6 = portStringLength(*(undefined8 *)(CSWTCH_133 + uVar9 * 8));
      pcVar8 = *(char **)(CSWTCH_133 + uVar9 * 8);
      goto LAB_002f5180;
    }
  }
  else {
    if (uVar11 != 1) {
      if (uVar11 == 2) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce00_h2d_user");
          pcVar8 = "Lce00_h2d_user";
        }
        else if ((ushort)(uVar5 - 1) < 5) {
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_115 + uVar9 * 8));
          pcVar8 = *(char **)(CSWTCH_115 + uVar9 * 8);
        }
        else {
LAB_002f5520:
          uVar6 = portStringLength(0);
          pcVar8 = (char *)0x0;
        }
      }
      else if (uVar11 == 3) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce01_h2d_user");
          pcVar8 = "Lce01_h2d_user";
        }
        else {
          if (4 < (ushort)(uVar5 - 1)) goto LAB_002f5520;
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_116 + uVar9 * 8));
          pcVar8 = *(char **)(CSWTCH_116 + uVar9 * 8);
        }
      }
      else if (uVar11 == 4) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce02_h2d_user");
          pcVar8 = "Lce02_h2d_user";
        }
        else {
          if (4 < (ushort)(uVar5 - 1)) goto LAB_002f5520;
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_99 + uVar9 * 8));
          pcVar8 = *(char **)(CSWTCH_99 + uVar9 * 8);
        }
      }
      else if (uVar11 == 5) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce03_h2d_user");
          pcVar8 = "Lce03_h2d_user";
        }
        else {
          if (4 < (ushort)(uVar5 - 1)) goto LAB_002f5520;
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_100 + uVar9 * 8));
          pcVar8 = *(char **)(CSWTCH_100 + uVar9 * 8);
        }
      }
      else if (uVar11 == 6) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce04_h2d_user");
          pcVar8 = "Lce04_h2d_user";
        }
        else if ((ushort)(uVar5 - 1) < 5) {
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_119 + uVar9 * 8));
          pcVar8 = *(char **)(CSWTCH_119 + uVar9 * 8);
        }
        else {
          uVar6 = portStringLength(0);
          pcVar8 = "Lce04_h2d_user";
          if (sVar2 != 0) {
            pcVar8 = (char *)0x0;
          }
        }
      }
      else if (uVar11 == 7) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce05_h2d_user");
          pcVar8 = "Lce05_h2d_user";
        }
        else {
          if ((ushort)(uVar5 - 1) < 5) {
            uVar6 = portStringLength(*(undefined8 *)(CSWTCH_120 + (ulong)(uVar5 - 1 & 0xffff) * 8));
          }
          else {
            uVar6 = portStringLength(0);
          }
LAB_002f56d4:
          if (sVar2 == 0) {
            uVar11 = 7;
            pcVar8 = "Lce05_h2d_user";
          }
          else if ((ushort)(uVar5 - 1) < 5) {
            uVar11 = 7;
            pcVar8 = *(char **)(CSWTCH_120 + (ulong)(uVar5 - 1 & 0xffff) * 8);
          }
          else {
            uVar11 = 7;
            pcVar8 = (char *)0x0;
          }
        }
      }
      else if (uVar11 == 8) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce06_h2d_user");
LAB_002f57c7:
          if (sVar2 == 0) {
            uVar11 = 8;
            pcVar8 = "Lce06_h2d_user";
          }
          else {
            uVar11 = 8;
            pcVar8 = (char *)0x0;
            if ((ushort)(uVar5 - 1) < 5) {
              uVar9 = (ulong)(uVar5 - 1 & 0xffff);
              goto LAB_002f5754;
            }
          }
        }
        else {
          if (4 < (ushort)(uVar5 - 1)) {
LAB_002f58d5:
            uVar6 = portStringLength(0);
            if (uVar11 != 8) {
LAB_002f5877:
              if (sVar2 == 0) {
                uVar11 = 10;
                goto LAB_002f597b;
              }
              if ((ushort)(uVar5 - 1) < 5) {
                uVar11 = 10;
                pcVar8 = *(char **)(CSWTCH_105 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              }
              else {
                uVar11 = 10;
                pcVar8 = (char *)0x0;
              }
              goto LAB_002f54c0;
            }
            goto LAB_002f57c7;
          }
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_103 + uVar9 * 8));
LAB_002f5754:
          pcVar8 = *(char **)(CSWTCH_103 + uVar9 * 8);
          uVar11 = 8;
        }
      }
      else if (uVar11 == 9) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce07_h2d_user");
          pcVar8 = "Lce07_h2d_user";
        }
        else {
          if ((ushort)(uVar5 - 1) < 5) {
            uVar6 = portStringLength(*(undefined8 *)(CSWTCH_104 + (ulong)(uVar5 - 1 & 0xffff) * 8));
          }
          else {
            uVar6 = portStringLength(0);
          }
LAB_002f581e:
          if (sVar2 == 0) {
            uVar11 = 9;
            pcVar8 = "Lce07_h2d_user";
          }
          else if ((ushort)(uVar5 - 1) < 5) {
            uVar11 = 9;
            pcVar8 = *(char **)(CSWTCH_104 + (ulong)(uVar5 - 1 & 0xffff) * 8);
          }
          else {
            uVar11 = 9;
LAB_002f5a15:
            pcVar8 = (char *)0x0;
          }
        }
      }
      else if (uVar11 == 10) {
        if (sVar2 != 0) {
          if (4 < (ushort)(uVar5 - 1)) goto LAB_002f58d5;
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_105 + (ulong)(uVar5 - 1 & 0xffff) * 8));
          goto LAB_002f5877;
        }
        uVar6 = portStringLength("Lce10_h2d_user");
LAB_002f597b:
        pcVar8 = "Lce10_h2d_user";
      }
      else if (uVar11 == 0xb) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce11_h2d_user");
        }
        else if ((ushort)(uVar5 - 1) < 5) {
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_106 + (ulong)(uVar5 - 1 & 0xffff) * 8));
        }
        else {
          uVar6 = portStringLength(0);
        }
LAB_002f5935:
        pcVar8 = "Lce11_h2d_user";
        if (sVar2 != 0) {
          pcVar8 = (char *)0x0;
          if ((ushort)(uVar5 - 1) < 5) {
            pcVar8 = *(char **)(CSWTCH_106 + (ulong)(uVar5 - 1 & 0xffff) * 8);
          }
        }
      }
      else if (uVar11 == 0xc) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce12_h2d_user");
        }
        else if ((ushort)(uVar5 - 1) < 5) {
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_107 + (ulong)(uVar5 - 1 & 0xffff) * 8));
        }
        else {
          uVar6 = portStringLength(0);
        }
LAB_002f599e:
        pcVar8 = "Lce12_h2d_user";
        if (sVar2 != 0) {
          pcVar8 = (char *)0x0;
          if ((ushort)(uVar5 - 1) < 5) {
            pcVar8 = *(char **)(CSWTCH_107 + (ulong)(uVar5 - 1 & 0xffff) * 8);
          }
        }
      }
      else if (uVar11 == 0xd) {
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce13_h2d_user");
LAB_002f5a69:
          pcVar8 = "Lce13_h2d_user";
          if (sVar2 == 0) goto LAB_002f54c0;
        }
        else {
          if (4 < (ushort)(uVar5 - 1)) {
            uVar6 = portStringLength(0);
            goto LAB_002f5a69;
          }
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_108 + (ulong)(uVar5 - 1 & 0xffff) * 8));
        }
        if ((ushort)(uVar5 - 1) < 5) {
          uVar11 = 0xd;
          pcVar8 = *(char **)(CSWTCH_108 + (ulong)(uVar5 - 1 & 0xffff) * 8);
        }
        else {
          uVar11 = 0xd;
          pcVar8 = (char *)0x0;
        }
      }
      else {
        if (uVar11 != 0xe) {
          if (uVar11 == 0xf) {
            if (sVar2 == 0) {
              uVar6 = portStringLength("Lce15_h2d_user");
            }
            else if ((ushort)(uVar5 - 1) < 5) {
              uVar6 = portStringLength(*(undefined8 *)(CSWTCH_110 + (ulong)(uVar5 - 1 & 0xffff) * 8)
                                      );
            }
            else {
              uVar6 = portStringLength(0);
            }
LAB_002f5b3f:
            pcVar8 = "Lce15_h2d_user";
            if (sVar2 != 0) {
              pcVar8 = (char *)0x0;
              if ((ushort)(uVar5 - 1) < 5) {
                pcVar8 = *(char **)(CSWTCH_110 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              }
            }
          }
          else if (uVar11 == 0x10) {
            if (sVar2 == 0) {
              uVar6 = portStringLength("Lce16_h2d_user");
              pcVar8 = "Lce16_h2d_user";
            }
            else {
              if ((ushort)(uVar5 - 1) < 5) {
                uVar6 = portStringLength(*(undefined8 *)
                                          (CSWTCH_111 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar6 = portStringLength(0);
              }
LAB_002f5c72:
              if (sVar2 == 0) {
                pcVar8 = "Lce16_h2d_user";
              }
              else {
                if (4 < (ushort)(uVar5 - 1)) goto LAB_002f5a15;
                pcVar8 = *(char **)(CSWTCH_111 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              }
            }
          }
          else {
            if (uVar11 == 0x11) {
              if (sVar2 == 0) {
                uVar6 = portStringLength("Lce17_h2d_user");
              }
              else if ((ushort)(uVar5 - 1) < 5) {
                uVar6 = portStringLength(*(undefined8 *)
                                          (CSWTCH_112 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar6 = portStringLength(0);
              }
            }
            else {
              uVar6 = portStringLength(0);
              if (uVar11 == 7) goto LAB_002f56d4;
              if (uVar11 == 8) goto LAB_002f57c7;
              if (uVar11 == 9) goto LAB_002f581e;
              if (uVar11 == 10) goto LAB_002f597b;
              if (uVar11 == 0xb) goto LAB_002f5935;
              if (uVar11 == 0xc) goto LAB_002f599e;
              if (uVar11 == 0xd) goto LAB_002f5a69;
              if (uVar11 == 0xe) goto LAB_002f5b85;
              if (uVar11 == 0xf) goto LAB_002f5b3f;
              if (uVar11 == 0x10) goto LAB_002f5c72;
              if (uVar11 != 0x11) {
                cVar3 = libspdm_hkdf_sha256_expand(param_1 + 0xa38,0x20,0,uVar6,lVar10,0x20);
                goto joined_r0x002f54d9;
              }
            }
            pcVar8 = "Lce17_h2d_user";
            if (sVar2 != 0) {
              if (4 < (ushort)(uVar5 - 1)) goto LAB_002f5a15;
              pcVar8 = *(char **)(CSWTCH_112 + (ulong)(uVar5 - 1 & 0xffff) * 8);
            }
          }
          goto LAB_002f54c0;
        }
        if (sVar2 == 0) {
          uVar6 = portStringLength("Lce14_h2d_user");
LAB_002f5b85:
          pcVar8 = "Lce14_h2d_user";
          if (sVar2 == 0) goto LAB_002f54c0;
        }
        else {
          if (4 < (ushort)(uVar5 - 1)) {
            uVar6 = portStringLength(0);
            goto LAB_002f5b85;
          }
          uVar6 = portStringLength(*(undefined8 *)(CSWTCH_109 + (ulong)(uVar5 - 1 & 0xffff) * 8));
        }
        if ((ushort)(uVar5 - 1) < 5) {
          uVar11 = 0xe;
          pcVar8 = *(char **)(CSWTCH_109 + (ulong)(uVar5 - 1 & 0xffff) * 8);
        }
        else {
          uVar11 = 0xe;
          pcVar8 = (char *)0x0;
        }
      }
LAB_002f54c0:
      cVar3 = libspdm_hkdf_sha256_expand(param_1 + 0xa38,0x20,pcVar8,uVar6,lVar10,0x20);
joined_r0x002f54d9:
      if (cVar3 != '\0') {
        uVar5 = (**(code **)(param_1 + 0x1f8))(param_1);
        if (uVar5 < uVar11) {
          return 0;
        }
        piVar7 = (int *)(lVar1 + 0xc + (ulong)local_3c[0] * 0x44);
        do {
          if (*piVar7 != 0) {
            return 0;
          }
          piVar7 = piVar7 + 1;
        } while ((int *)(lVar1 + 0x2c + (ulong)local_3c[0] * 0x44) != piVar7);
      }
      return 0x71;
    }
    if (sVar2 == 0) {
      uVar6 = portStringLength("cpu_sec2_data_user");
      pcVar8 = "cpu_sec2_data_user";
      goto LAB_002f5180;
    }
  }
  uVar6 = portStringLength(0);
  pcVar8 = (char *)0x0;
LAB_002f5180:
  cVar3 = libspdm_hkdf_sha256_expand(param_1 + 0xa38,0x20,pcVar8,uVar6,lVar10,0x20);
  iVar4 = 0;
  if (cVar3 == '\0') {
    iVar4 = 0x71;
  }
  return iVar4;
}


// ===== 002f5de0 confComputeKeyStoreDepositIvMask_GH100 =====

void confComputeKeyStoreDepositIvMask_GH100(long param_1,ulong param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  uint local_2c [3];
  
  lVar1 = *(long *)(param_1 + 0xa58);
  iVar2 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,local_2c);
  if (iVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0xcc,
                 "confComputeKeyStoreDepositIvMask_GH100",1,
                 "NVRM: Depositing IV mask for global key ID %x.\n",param_2 & 0xffffffff);
    portMemCopy(lVar1 + 0x2c + (ulong)local_2c[0] * 0x44,0xc,param_3,0xc);
    return;
  }
  nvAssertFailedNoLog("confComputeGetKeySlotFromGlobalKeyId(pConfCompute, globalKeyId, &slotNumber) == NV_OK"
                      ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0xcb)
  ;
  return;
}


// ===== 002f5e90 confComputeKeyStoreClearExportMasterKey_GH100 =====

void confComputeKeyStoreClearExportMasterKey_GH100(long param_1)

{
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0xd6,
               "confComputeKeyStoreClearExportMasterKey_GH100",1,
               "NVRM: Clearing the Export Master Key.\n");
  portMemSet(param_1 + 0xa38,0,0x20);
  return;
}


// ===== 002f5ee0 confComputeKeyStoreRetrieveViaKeyId_GH100 =====

int confComputeKeyStoreRetrieveViaKeyId_GH100
              (long param_1,undefined8 param_2,int param_3,char param_4,undefined8 *param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  bool bVar7;
  uint local_3c [3];
  
  lVar2 = *(long *)(param_1 + 0xa58);
  iVar3 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,local_3c);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, globalKeyId, &slotNumber)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x123);
    return iVar3;
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x124,
               "confComputeKeyStoreRetrieveViaKeyId_GH100",1,
               "NVRM: Retrieving KMB from slot number = %d and type is %d.\n",(ulong)local_3c[0],
               *(undefined4 *)(lVar2 + 0x40 + (ulong)local_3c[0] * 0x44));
  if ((local_3c[0] & 1) != 0) {
    local_3c[0] = local_3c[0] - 1;
  }
  bVar7 = param_3 == 3;
  if (param_4 == '\0') {
    if (param_3 == 0 || bVar7) {
      portMemCopy((long)param_5 + 0xc,0x20,lVar2 + 0xc + (ulong)local_3c[0] * 0x44,0x20);
      portMemCopy((long)param_5 + 0x2c,0xc,lVar2 + 0x2c + (ulong)local_3c[0] * 0x44,0xc);
      if (param_3 != 3) {
        return 0;
      }
    }
    else if ((param_3 != 1) && (param_3 != 2)) {
      return 0;
    }
    uVar6 = (ulong)(local_3c[0] + 1);
    uVar1 = *(uint *)(lVar2 + 0x40 + uVar6 * 0x44);
    if (uVar1 < 2) {
      portMemCopy((long)param_5 + 0x44,0x20,lVar2 + 0xc + uVar6 * 0x44,0x20);
      portMemCopy((long)param_5 + 100,0xc,lVar2 + 0x2c + (ulong)(local_3c[0] + 1) * 0x44,0xc);
      goto LAB_002f60a6;
    }
    if (uVar1 != 2) {
      return 0;
    }
    portMemCopy(param_5 + 0xb,0x20,lVar2 + 0x20 + uVar6 * 0x44,0x20);
LAB_002f6022:
    *(undefined1 *)(param_5 + 0xf) = 1;
    iVar3 = 0;
  }
  else {
    if (param_3 == 0 || bVar7) {
      lVar4 = getChannelCounter_isra_0(*(undefined8 *)(param_1 + 0xa58),local_3c[0],bVar7,0x2f5f11);
      if (lVar4 != -1) {
        if (param_3 != 3) {
          incrementChannelCounter(param_1,local_3c[0]);
          puVar5 = (undefined8 *)((ulong)local_3c[0] * 0x44 + lVar2);
          *param_5 = *puVar5;
          param_5[1] = puVar5[1];
          param_5[2] = puVar5[2];
          param_5[3] = puVar5[3];
          param_5[4] = puVar5[4];
          param_5[5] = puVar5[5];
          param_5[6] = puVar5[6];
          return 0;
        }
        lVar4 = getChannelCounter_isra_0(*(undefined8 *)(param_1 + 0xa58),local_3c[0] + 1);
        if (lVar4 != -1) {
          incrementChannelCounter(param_1,local_3c[0]);
          puVar5 = (undefined8 *)((ulong)local_3c[0] * 0x44 + lVar2);
          *param_5 = *puVar5;
          param_5[1] = puVar5[1];
          param_5[2] = puVar5[2];
          param_5[3] = puVar5[3];
          param_5[4] = puVar5[4];
          param_5[5] = puVar5[5];
          param_5[6] = puVar5[6];
          goto LAB_002f5fb2;
        }
      }
    }
    else {
      if (1 < param_3 - 1U) {
        return 0;
      }
      lVar4 = getChannelCounter_isra_0
                        (*(undefined8 *)(param_1 + 0xa58),local_3c[0] + 1,bVar7,0x2f5f11);
      if (lVar4 != -1) {
LAB_002f5fb2:
        incrementChannelCounter(param_1,local_3c[0] + 1);
        puVar5 = (undefined8 *)((ulong)(local_3c[0] + 1) * 0x44 + lVar2);
        if (*(uint *)(puVar5 + 8) < 2) {
          param_5[7] = *puVar5;
          param_5[8] = puVar5[1];
          param_5[9] = puVar5[2];
          param_5[10] = puVar5[3];
          param_5[0xb] = puVar5[4];
          param_5[0xc] = puVar5[5];
          param_5[0xd] = puVar5[6];
LAB_002f60a6:
          *(undefined1 *)(param_5 + 0xf) = 0;
          return 0;
        }
        if (*(uint *)(puVar5 + 8) != 2) {
          return 0;
        }
        param_5[7] = *puVar5;
        param_5[8] = puVar5[1];
        param_5[9] = puVar5[2];
        param_5[10] = puVar5[3];
        param_5[0xb] = puVar5[4];
        param_5[0xc] = puVar5[5];
        param_5[0xd] = puVar5[6];
        param_5[0xe] = puVar5[7];
        goto LAB_002f6022;
      }
    }
    iVar3 = 0x1a;
  }
  return iVar3;
}


// ===== 002f62d0 confComputeKeyStoreRetrieveViaChannel_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
confComputeKeyStoreRetrieveViaChannel_GH100
          (long param_1,long param_2,int param_3,uint param_4,undefined8 param_5)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  bool bVar4;
  uint uVar5;
  undefined4 local_3c;
  
  uVar3 = 0x1f;
  if (param_4 < 4) {
    uVar5 = *(uint *)(param_2 + 0x42c);
    if (8 < uVar5) {
      if (uVar5 < 0x1d) {
        iVar2 = (**(code **)(param_1 + 0x1e8))(param_1,param_2,(long)&local_3c + 2);
        if ((iVar2 == 0) &&
           (iVar2 = (**(code **)(param_1 + 0x1f0))(param_1,param_2,param_3,&local_3c),
           uVar5 = local_3c, iVar2 == 0)) goto LAB_002f6354;
      }
      else if (uVar5 == 0x31) {
        cVar1 = kchannelCheckIsUserMode_IMPL(param_2);
        if (cVar1 == '\0') {
          cVar1 = kchannelCheckIsKernel_IMPL(param_2);
          if (cVar1 == '\0') {
            return 0x3b;
          }
          if ((param_3 == 0) || (param_3 == 3)) {
            if (*(char *)(param_2 + 0x4f9) == '\0') {
              local_3c = CONCAT22(local_3c._2_2_,2);
              uVar5 = 0x10002;
            }
            else {
              local_3c = CONCAT22(local_3c._2_2_,4);
              uVar5 = 0x10004;
            }
          }
          else if (*(char *)(param_2 + 0x4f9) == '\0') {
            local_3c = CONCAT22(local_3c._2_2_,3);
            uVar5 = 0x10003;
          }
          else {
            local_3c = CONCAT22(local_3c._2_2_,5);
            uVar5 = 0x10005;
          }
        }
        else {
          bVar4 = param_3 != 0 && param_3 != 3;
          local_3c = CONCAT22(local_3c._2_2_,(ushort)bVar4);
          uVar5 = bVar4 | 0x10000;
        }
LAB_002f6354:
        uVar3 = confComputeKeyStoreRetrieveViaKeyId_GH100
                          (param_1,uVar5,param_3,param_4 & 0xfd,param_5);
        return uVar3;
      }
      return 0x3b;
    }
    uVar3 = 0x3b;
  }
  return uVar3;
}


// ===== 002f6470 confComputeKeyStoreUpdateKey_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int confComputeKeyStoreUpdateKey_GH100(long param_1,ulong param_2)

{
  long lVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined8 uVar7;
  char *pcVar8;
  ulong uVar9;
  uint uVar10;
  long lVar11;
  uint local_5c;
  undefined1 local_58 [40];
  
  sVar2 = (short)param_2;
  iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,&local_5c);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, globalKeyId, &slotIndex)",
               "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x195);
    return iVar4;
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x196,
               "confComputeKeyStoreUpdateKey_GH100",1,"NVRM: Updating key with global key ID %x.\n",
               param_2 & 0xffffffff);
  uVar5 = (uint)param_2;
  lVar1 = *(long *)(param_1 + 0xa58);
  if (uVar5 - 0x10001 < 5) {
    lVar11 = lVar1 + 0x20;
    if ((0x15UL >> ((ulong)(uVar5 - 0x10001) & 0x3f) & 1) == 0) {
      lVar11 = lVar1 + 0xc;
    }
    lVar11 = lVar11 + (ulong)local_5c * 0x44;
    cVar3 = libspdm_sha256_hash_all(lVar11,0x20,local_58);
    if (cVar3 == '\0') {
      return 0x71;
    }
    uVar9 = (ulong)(uVar5 - 1 & 0xffff);
    uVar7 = portStringLength(*(undefined8 *)(CSWTCH_114 + uVar9 * 8));
    pcVar8 = *(char **)(CSWTCH_114 + uVar9 * 8);
    goto LAB_002f65a0;
  }
  lVar11 = lVar1 + 0xc + (ulong)local_5c * 0x44;
  cVar3 = libspdm_sha256_hash_all(lVar11,0x20,local_58);
  if (cVar3 == '\0') {
    return 0x71;
  }
  uVar10 = uVar5 >> 0x10;
  if (uVar10 == 0) {
    if (sVar2 == 1) {
      uVar7 = portStringLength("gsp_cpu_locked_rpc");
      pcVar8 = "gsp_cpu_locked_rpc";
      goto LAB_002f65a0;
    }
    if (sVar2 == 0) {
      uVar7 = portStringLength("cpu_gsp_locked_rpc");
      pcVar8 = "cpu_gsp_locked_rpc";
      goto LAB_002f65a0;
    }
    if ((ushort)(uVar5 - 2) < 9) {
      uVar9 = (ulong)(uVar5 - 2 & 0xffff);
      uVar7 = portStringLength(*(undefined8 *)(CSWTCH_133 + uVar9 * 8));
      pcVar8 = *(char **)(CSWTCH_133 + uVar9 * 8);
      goto LAB_002f65a0;
    }
  }
  else {
    if (uVar10 != 1) {
      if (uVar10 == 2) {
        if (sVar2 == 0) {
          uVar7 = portStringLength("Lce00_h2d_user");
          pcVar8 = "Lce00_h2d_user";
          goto LAB_002f66e0;
        }
        if ((ushort)(uVar5 - 1) < 5) {
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar7 = portStringLength(*(undefined8 *)(CSWTCH_115 + uVar9 * 8));
          pcVar8 = *(char **)(CSWTCH_115 + uVar9 * 8);
          goto LAB_002f66e0;
        }
      }
      else {
        if (uVar10 != 3) {
          if (uVar10 == 4) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce02_h2d_user");
              pcVar8 = "Lce02_h2d_user";
            }
            else {
              if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_99 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
              if (sVar2 == 0) {
                pcVar8 = "Lce02_h2d_user";
              }
              else {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_99 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
            }
            goto LAB_002f66e0;
          }
          if (uVar10 == 5) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce03_h2d_user");
              pcVar8 = "Lce03_h2d_user";
            }
            else {
              if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_100 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
              pcVar8 = "Lce03_h2d_user";
              if (sVar2 != 0) {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_100 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
            }
            goto LAB_002f66e0;
          }
          if (uVar10 == 6) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce04_h2d_user");
              pcVar8 = "Lce04_h2d_user";
            }
            else {
              if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_119 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
              pcVar8 = "Lce04_h2d_user";
              if (sVar2 != 0) {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_119 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
            }
            goto LAB_002f66e0;
          }
          if (uVar10 == 7) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce05_h2d_user");
              pcVar8 = "Lce05_h2d_user";
            }
            else {
              if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_120 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
              pcVar8 = "Lce05_h2d_user";
              if (sVar2 != 0) {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_120 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
            }
            goto LAB_002f66e0;
          }
          if (uVar10 == 8) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce06_h2d_user");
            }
            else if ((ushort)(uVar5 - 1) < 5) {
              uVar7 = portStringLength(*(undefined8 *)(CSWTCH_103 + (ulong)(uVar5 - 1 & 0xffff) * 8)
                                      );
            }
            else {
              uVar7 = portStringLength(0);
            }
            pcVar8 = "Lce06_h2d_user";
            if (sVar2 != 0) {
              pcVar8 = (char *)0x0;
              if ((ushort)(uVar5 - 1) < 5) {
                pcVar8 = *(char **)(CSWTCH_103 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              }
            }
            goto LAB_002f66e0;
          }
          if (uVar10 == 9) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce07_h2d_user");
            }
            else if ((ushort)(uVar5 - 1) < 5) {
              uVar7 = portStringLength(*(undefined8 *)(CSWTCH_104 + (ulong)(uVar5 - 1 & 0xffff) * 8)
                                      );
            }
            else {
              uVar7 = portStringLength(0);
            }
LAB_002f6cc6:
            pcVar8 = "Lce07_h2d_user";
            if (sVar2 != 0) {
              pcVar8 = (char *)0x0;
              if ((ushort)(uVar5 - 1) < 5) {
                pcVar8 = *(char **)(CSWTCH_104 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              }
            }
            goto LAB_002f66e0;
          }
          if (uVar10 == 10) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce10_h2d_user");
            }
            else if ((ushort)(uVar5 - 1) < 5) {
              uVar7 = portStringLength(*(undefined8 *)(CSWTCH_105 + (ulong)(uVar5 - 1 & 0xffff) * 8)
                                      );
            }
            else {
              uVar7 = portStringLength(0);
            }
LAB_002f66b8:
            pcVar8 = "Lce10_h2d_user";
            if (sVar2 != 0) {
              pcVar8 = (char *)0x0;
              if ((ushort)(uVar5 - 1) < 5) {
                pcVar8 = *(char **)(CSWTCH_105 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              }
            }
            goto LAB_002f66e0;
          }
          if (uVar10 == 0xb) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce11_h2d_user");
            }
            else if ((ushort)(uVar5 - 1) < 5) {
              uVar7 = portStringLength(*(undefined8 *)(CSWTCH_106 + (ulong)(uVar5 - 1 & 0xffff) * 8)
                                      );
            }
            else {
              uVar7 = portStringLength(0);
            }
LAB_002f6dc4:
            pcVar8 = "Lce11_h2d_user";
            if (sVar2 == 0) goto LAB_002f66e0;
            if ((ushort)(uVar5 - 1) < 5) {
              pcVar8 = *(char **)(CSWTCH_106 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              goto LAB_002f66e0;
            }
          }
          else if (uVar10 == 0xc) {
            if (sVar2 == 0) {
              uVar7 = portStringLength("Lce12_h2d_user");
            }
            else if ((ushort)(uVar5 - 1) < 5) {
              uVar7 = portStringLength(*(undefined8 *)(CSWTCH_107 + (ulong)(uVar5 - 1 & 0xffff) * 8)
                                      );
            }
            else {
              uVar7 = portStringLength(0);
            }
LAB_002f6e73:
            pcVar8 = "Lce12_h2d_user";
            if (sVar2 == 0) goto LAB_002f66e0;
            if ((ushort)(uVar5 - 1) < 5) {
              pcVar8 = *(char **)(CSWTCH_107 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              goto LAB_002f66e0;
            }
          }
          else {
            if (uVar10 == 0xd) {
              if (sVar2 == 0) {
                uVar7 = portStringLength("Lce13_h2d_user");
              }
              else if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_108 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
LAB_002f6f1a:
              pcVar8 = "Lce13_h2d_user";
              if (sVar2 != 0) {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_108 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
              goto LAB_002f66e0;
            }
            if (uVar10 == 0xe) {
              if (sVar2 == 0) {
                uVar7 = portStringLength("Lce14_h2d_user");
              }
              else if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_109 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
LAB_002f6f8f:
              pcVar8 = "Lce14_h2d_user";
              if (sVar2 != 0) {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_109 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
              goto LAB_002f66e0;
            }
            if (uVar10 == 0xf) {
              if (sVar2 == 0) {
                uVar7 = portStringLength("Lce15_h2d_user");
              }
              else if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_110 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
LAB_002f7091:
              pcVar8 = "Lce15_h2d_user";
              if (sVar2 != 0) {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_110 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
              goto LAB_002f66e0;
            }
            if (uVar10 == 0x10) {
              if (sVar2 == 0) {
                uVar7 = portStringLength("Lce16_h2d_user");
              }
              else if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_111 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
LAB_002f70e8:
              pcVar8 = "Lce16_h2d_user";
              if (sVar2 != 0) {
                pcVar8 = (char *)0x0;
                if ((ushort)(uVar5 - 1) < 5) {
                  pcVar8 = *(char **)(CSWTCH_111 + (ulong)(uVar5 - 1 & 0xffff) * 8);
                }
              }
              goto LAB_002f66e0;
            }
            if (uVar10 == 0x11) {
              if (sVar2 == 0) {
                uVar7 = portStringLength("Lce17_h2d_user");
              }
              else if ((ushort)(uVar5 - 1) < 5) {
                uVar7 = portStringLength(*(undefined8 *)
                                          (CSWTCH_112 + (ulong)(uVar5 - 1 & 0xffff) * 8));
              }
              else {
                uVar7 = portStringLength(0);
              }
            }
            else {
              uVar7 = portStringLength(0);
              if (uVar10 == 9) goto LAB_002f6cc6;
              if (uVar10 == 10) goto LAB_002f66b8;
              if (uVar10 == 0xb) goto LAB_002f6dc4;
              if (uVar10 == 0xc) goto LAB_002f6e73;
              if (uVar10 == 0xd) goto LAB_002f6f1a;
              if (uVar10 == 0xe) goto LAB_002f6f8f;
              if (uVar10 == 0xf) goto LAB_002f7091;
              if (uVar10 == 0x10) goto LAB_002f70e8;
              pcVar8 = (char *)0x0;
              if (uVar10 != 0x11) goto LAB_002f66e0;
            }
            pcVar8 = "Lce17_h2d_user";
            if (sVar2 == 0) goto LAB_002f66e0;
            if ((ushort)(uVar5 - 1) < 5) {
              pcVar8 = *(char **)(CSWTCH_112 + (ulong)(uVar5 - 1 & 0xffff) * 8);
              goto LAB_002f66e0;
            }
          }
          pcVar8 = (char *)0x0;
          goto LAB_002f66e0;
        }
        if (sVar2 == 0) {
          uVar7 = portStringLength("Lce01_h2d_user");
          pcVar8 = "Lce01_h2d_user";
          goto LAB_002f66e0;
        }
        if ((ushort)(uVar5 - 1) < 5) {
          uVar9 = (ulong)(uVar5 - 1 & 0xffff);
          uVar7 = portStringLength(*(undefined8 *)(CSWTCH_116 + uVar9 * 8));
          pcVar8 = *(char **)(CSWTCH_116 + uVar9 * 8);
          goto LAB_002f66e0;
        }
      }
      uVar7 = portStringLength(0);
      pcVar8 = (char *)0x0;
LAB_002f66e0:
      cVar3 = libspdm_hkdf_sha256_expand(local_58,0x20,pcVar8,uVar7,lVar11,0x20);
      if (cVar3 == '\0') {
        return 0x71;
      }
      portMemSet(local_58,0,0x20);
      uVar5 = (**(code **)(param_1 + 0x1f8))(param_1);
      if (uVar10 <= uVar5) {
        piVar6 = (int *)(lVar1 + 0xc + (ulong)local_5c * 0x44);
        do {
          if (*piVar6 != 0) {
            return 0;
          }
          piVar6 = piVar6 + 1;
        } while ((int *)(lVar1 + 0x2c + (ulong)local_5c * 0x44) != piVar6);
        return 0x71;
      }
      return 0;
    }
    if (sVar2 == 0) {
      uVar7 = portStringLength("cpu_sec2_data_user");
      pcVar8 = "cpu_sec2_data_user";
      goto LAB_002f65a0;
    }
  }
  uVar7 = portStringLength(0);
  pcVar8 = (char *)0x0;
LAB_002f65a0:
  cVar3 = libspdm_hkdf_sha256_expand(local_58,0x20,pcVar8,uVar7,lVar11,0x20);
  if (cVar3 == '\0') {
    return 0x71;
  }
  portMemSet(local_58,0,0x20);
  return 0;
}


// ===== 002f7280 confComputeGetKeyPairByChannel_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int confComputeGetKeyPairByChannel_GH100
              (undefined8 param_1,long param_2,long param_3,undefined4 *param_4,undefined4 *param_5)

{
  char cVar1;
  short sVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined2 local_2e;
  short local_2c;
  short local_2a;
  
  local_2e = 0;
  local_2c = 0;
  local_2a = 0;
  if (*(int *)(param_3 + 0x42c) != 0x31) {
    iVar3 = (**(code **)(param_2 + 0x1e8))(param_2,param_3,&local_2e);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (1,
                 "confComputeGetKeySpaceFromKChannel_HAL(pConfCompute, pKernelChannel, &keySpace) != NV_OK"
                 ,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x1eb);
      return 1;
    }
    iVar3 = (**(code **)(param_2 + 0x1f0))(param_2,param_3,0,&local_2c);
    uVar4 = 0x1ed;
    pcVar5 = 
    "confComputeGetLceKeyIdFromKChannel_HAL(pConfCompute, pKernelChannel, ROTATE_IV_ENCRYPT, &lh2dKeyId)"
    ;
    if (iVar3 == 0) {
      iVar3 = (**(code **)(param_2 + 0x1f0))(param_2,param_3,1,&local_2a);
      if (iVar3 == 0) goto LAB_002f7341;
      uVar4 = 0x1ef;
      pcVar5 = 
      "confComputeGetLceKeyIdFromKChannel_HAL(pConfCompute, pKernelChannel, ROTATE_IV_DECRYPT, &ld2hKeyId)"
      ;
    }
    nvAssertOkFailedNoLog
              (iVar3,pcVar5,"src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",
               uVar4);
    return iVar3;
  }
  local_2e = 1;
  cVar1 = kchannelCheckIsUserMode_IMPL(param_3);
  sVar2 = 0;
  if (cVar1 == '\0') {
    cVar1 = kchannelCheckIsKernel_IMPL(param_3);
    if (cVar1 == '\0') {
      nvAssertOkFailedNoLog
                (0xffff,"getKeyIdSec2(pKernelChannel, ROTATE_IV_ENCRYPT, &lh2dKeyId)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x1e6);
      return 0xffff;
    }
    sVar2 = (-(ushort)(*(char *)(param_3 + 0x4f9) == '\0') & 0xfffe) + 4;
  }
  local_2c = sVar2;
  cVar1 = kchannelCheckIsUserMode_IMPL(param_3);
  if (cVar1 == '\0') {
    cVar1 = kchannelCheckIsKernel_IMPL(param_3);
    if (cVar1 == '\0') {
      nvAssertOkFailedNoLog
                (0xffff,"getKeyIdSec2(pKernelChannel, ROTATE_IV_HMAC, &ld2hKeyId)",
                 "src/kernel/gpu/conf_compute/arch/hopper/conf_compute_keystore_gh100.c",0x1e7);
      return 0xffff;
    }
    local_2a = (-(ushort)(*(char *)(param_3 + 0x4f9) == '\0') & 0xfffe) + 5;
  }
  else {
    local_2a = 1;
  }
LAB_002f7341:
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = CONCAT22(local_2e,local_2c);
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = CONCAT22(local_2e,local_2a);
  }
  return 0;
}


// ===== 002f74c0 confComputeKeyStoreIsValidGlobalKeyId_GH100 =====

bool confComputeKeyStoreIsValidGlobalKeyId_GH100(undefined8 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 >> 0x10;
  if (uVar1 == 0) {
    if ((ushort)param_2 < 2) {
      return true;
    }
    if ((ushort)(param_2 - 2) < 9) {
      return *(long *)(CSWTCH_133 + (ulong)(param_2 - 2 & 0xffff) * 8) != 0;
    }
  }
  else if (((((((uVar1 == 1) || (uVar1 == 2)) || (uVar1 == 3)) || ((uVar1 == 4 || (uVar1 == 5)))) ||
            ((uVar1 == 6 || ((uVar1 == 7 || (uVar1 == 8)))))) || (uVar1 == 9)) ||
          ((((uVar1 == 10 || (uVar1 == 0xb)) || (uVar1 == 0xc)) ||
           (((uVar1 == 0xd || (uVar1 == 0xe)) ||
            ((uVar1 == 0xf || ((uVar1 == 0x10 || (uVar1 == 0x11)))))))))) {
    return (ushort)param_2 < 6;
  }
  return false;
}


// ===== 002f7560 confComputeGetLceKeyIdFromKChannel_GH100 =====

undefined8
confComputeGetLceKeyIdFromKChannel_GH100
          (undefined8 param_1,undefined8 param_2,int param_3,ushort *param_4)

{
  char cVar1;
  
  cVar1 = kchannelCheckIsUserMode_IMPL(param_2);
  if (cVar1 == '\0') {
    cVar1 = kchannelCheckIsKernel_IMPL(param_2);
    if (cVar1 == '\0') {
      return 0xffff;
    }
    *param_4 = 3 - (param_3 == 0 || param_3 == 3);
  }
  else {
    *param_4 = (ushort)(param_3 != 0 && param_3 != 3);
  }
  return 0;
}


// ===== 002f75e0 confComputeGetKeySpaceFromKChannel_GH100 =====

undefined8
confComputeGetKeySpaceFromKChannel_GH100(undefined8 param_1,long param_2,undefined2 *param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x42c);
  if (uVar1 == 0xf) {
    *param_3 = 6;
    return 0;
  }
  if (uVar1 < 0x10) {
    if (uVar1 == 0xd) {
      *param_3 = 4;
      return 0;
    }
    if (uVar1 == 0xe) {
      *param_3 = 5;
      return 0;
    }
    if (uVar1 == 0xb) {
      *param_3 = 2;
      return 0;
    }
    if (uVar1 == 0xc) {
      *param_3 = 3;
      return 0;
    }
  }
  else {
    if (uVar1 == 0x11) {
      *param_3 = 8;
      return 0;
    }
    if (uVar1 == 0x12) {
      *param_3 = 9;
      return 0;
    }
    if (uVar1 == 0x10) {
      *param_3 = 7;
      return 0;
    }
  }
  return 0xffff;
}


// ===== 002f76c0 writeKmbToContext =====

void writeKmbToContext(long param_1,undefined4 *param_2,ulong param_3)

{
  undefined4 uVar1;
  long lVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  
  if ((9UL >> (param_3 & 0x3f) & 1) != 0) {
    lVar2 = 0;
    do {
      uVar1 = *(undefined4 *)((long)param_2 + lVar2 + 0xc);
      *(char *)(param_1 + 0x51 + lVar2) = (char)((uint)uVar1 >> 8);
      *(char *)(param_1 + 0x50 + lVar2) = (char)uVar1;
      *(char *)(param_1 + 0x53 + lVar2) = (char)((uint)uVar1 >> 0x18);
      *(char *)(param_1 + 0x52 + lVar2) = (char)((uint)uVar1 >> 0x10);
      lVar2 = lVar2 + 4;
    } while (lVar2 != 0x20);
    puVar4 = (undefined1 *)(param_1 + 0x70);
    puVar5 = param_2;
    do {
      uVar1 = *puVar5;
      puVar3 = puVar4 + 4;
      puVar4[1] = (char)((uint)uVar1 >> 8);
      *puVar4 = (char)uVar1;
      puVar4[3] = (char)((uint)uVar1 >> 0x18);
      puVar4[2] = (char)((uint)uVar1 >> 0x10);
      uVar1 = puVar5[0xb];
      puVar4[0xd] = (char)((uint)uVar1 >> 8);
      puVar4[0xc] = (char)uVar1;
      puVar4[0xf] = (char)((uint)uVar1 >> 0x18);
      puVar4[0xe] = (char)((uint)uVar1 >> 0x10);
      puVar4 = puVar3;
      puVar5 = puVar5 + 1;
    } while ((undefined1 *)(param_1 + 0x7c) != puVar3);
    if ((int)param_3 != 3) {
      return;
    }
  }
  lVar2 = 0;
  if (*(char *)(param_2 + 0x1e) != '\0') {
    do {
      uVar1 = *(undefined4 *)((long)param_2 + lVar2 + 0x58);
      *(char *)(param_1 + 0x11 + lVar2) = (char)((uint)uVar1 >> 8);
      *(char *)(param_1 + 0x10 + lVar2) = (char)uVar1;
      *(char *)(param_1 + 0x13 + lVar2) = (char)((uint)uVar1 >> 0x18);
      *(char *)(param_1 + 0x12 + lVar2) = (char)((uint)uVar1 >> 0x10);
      lVar2 = lVar2 + 4;
    } while (lVar2 != 0x20);
    lVar2 = 0;
    do {
      uVar1 = *(undefined4 *)((long)param_2 + lVar2 + 0x38);
      *(char *)(param_1 + 0x31 + lVar2) = (char)((uint)uVar1 >> 8);
      *(char *)(param_1 + 0x30 + lVar2) = (char)uVar1;
      *(char *)(param_1 + 0x33 + lVar2) = (char)((uint)uVar1 >> 0x18);
      *(char *)(param_1 + 0x32 + lVar2) = (char)((uint)uVar1 >> 0x10);
      lVar2 = lVar2 + 4;
    } while (lVar2 != 0x20);
    return;
  }
  do {
    uVar1 = *(undefined4 *)((long)param_2 + lVar2 + 0x44);
    *(char *)(param_1 + 0x11 + lVar2) = (char)((uint)uVar1 >> 8);
    *(char *)(param_1 + 0x10 + lVar2) = (char)uVar1;
    *(char *)(param_1 + 0x13 + lVar2) = (char)((uint)uVar1 >> 0x18);
    *(char *)(param_1 + 0x12 + lVar2) = (char)((uint)uVar1 >> 0x10);
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)((ulong)*(uint *)(param_1 + 0xd0) * 0x2c + *(long *)(param_1 + 200) + lVar2) =
           *(undefined4 *)((long)param_2 + lVar2 + 0x44);
    }
    lVar2 = lVar2 + 4;
  } while (lVar2 != 0x20);
  lVar2 = 0;
  puVar4 = (undefined1 *)(param_1 + 0x30);
  do {
    uVar1 = *(undefined4 *)((long)param_2 + lVar2 + 100);
    puVar4[0xd] = (char)((uint)uVar1 >> 8);
    puVar4[0xc] = (char)uVar1;
    puVar4[0xf] = (char)((uint)uVar1 >> 0x18);
    puVar4[0xe] = (char)((uint)uVar1 >> 0x10);
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)
       (lVar2 + 0x20 + (ulong)*(uint *)(param_1 + 0xd0) * 0x2c + *(long *)(param_1 + 200)) =
           *(undefined4 *)((long)param_2 + lVar2 + 100);
    }
    uVar1 = *(undefined4 *)((long)param_2 + lVar2 + 0x38);
    lVar2 = lVar2 + 4;
    puVar4[1] = (char)((uint)uVar1 >> 8);
    *puVar4 = (char)uVar1;
    puVar4[3] = (char)((uint)uVar1 >> 0x18);
    puVar4[2] = (char)((uint)uVar1 >> 0x10);
    puVar4 = puVar4 + 4;
  } while (lVar2 != 0xc);
  return;
}


// ===== 002f78f0 ccslUpdateViaKeyId =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ccslUpdateViaKeyId(long param_1,long param_2,int param_3)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_ac;
  int local_a8;
  undefined1 local_a4 [132];
  
  iVar2 = 0x56;
  local_ac = 0;
  local_a8 = 0;
  if (*(char *)(*(long *)(g_pSys + 0x1e0) + 0x3f15d) != '\0') {
    if (((param_2 == 0) || (param_1 == 0)) ||
       (cVar1 = (**(code **)(param_1 + 0x270))(param_1,param_3), cVar1 == '\0')) {
      return 0x1f;
    }
    confComputeGetKeyPairByKey_IMPL(param_1,param_3,&local_a8,&local_ac);
    bVar3 = local_a8 != param_3;
    iVar2 = (**(code **)(param_1 + 0x198))(param_1,param_3,bVar3,1,local_a4);
    if (iVar2 == 0) {
      writeKmbToContext(param_2,local_a4,bVar3);
      portMemSet(local_a4,0,0x7c);
      return 0;
    }
  }
  return iVar2;
}


// ===== 002f7a20 ccslRotationChecksDecrypt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 ccslRotationChecksDecrypt(long param_1,long param_2,ulong param_3)

{
  long *plVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(long *)(param_2 + 0xc0) != 0)) {
    param_3 = param_3 & 0xffffffff;
    cVar3 = (**(code **)(param_1 + 0x270))(param_1,*(undefined4 *)(param_2 + 0xa0));
    if (((cVar3 == '\0') ||
        (lVar2 = *(long *)(param_2 + 0xc0),
        *(long *)(lVar2 + 0x18) + param_3 < *(ulong *)(lVar2 + 0x18))) ||
       (*(long *)(lVar2 + 8) + 1U < *(ulong *)(lVar2 + 8))) {
      uVar4 = 0x1f;
    }
    else {
      *(long *)(lVar2 + 0x18) = *(long *)(lVar2 + 0x18) + param_3;
      plVar1 = (long *)(*(long *)(param_2 + 0xc0) + 8);
      *plVar1 = *plVar1 + 1;
      cVar3 = confComputeIsGivenThresholdCrossed_IMPL
                        (*(undefined8 *)(param_2 + 0xc0),*(undefined8 *)(param_1 + 0x308),0);
      uVar4 = 0;
      if (cVar3 != '\0') {
        nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x118,"ccslRotationChecksDecrypt",1,
                     "NVRM: Triggering key rotation for global key id 0x%x\n",
                     *(undefined4 *)(param_2 + 0xa0));
        nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x119,"ccslRotationChecksDecrypt",1,
                     "NVRM: Total bytes encrypted 0x%llx total encrypt ops 0x%llx\n",
                     *(long *)(*(long *)(param_2 + 0xc0) + 0x18) - param_3,
                     *(long *)(*(long *)(param_2 + 0xc0) + 8) + -1);
        uVar4 = (**(code **)(param_1 + 0x268))(param_1,*(undefined4 *)(param_2 + 0xa0));
        if ((int)uVar4 == 0) {
          uVar4 = ccslUpdateViaKeyId(param_1,param_2,*(undefined4 *)(param_2 + 0xa0),0x2f7b05);
          if ((int)uVar4 == 0) {
            *(ulong *)(*(long *)(param_2 + 0xc0) + 0x18) = param_3;
            *(undefined8 *)(*(long *)(param_2 + 0xc0) + 8) = 1;
          }
        }
      }
    }
    return uVar4;
  }
  return 0x1f;
}


// ===== 002f7bc0 getMessageCounterAndLimit.isra.0 =====

ulong getMessageCounterAndLimit_isra_0(int param_1,ulong *param_2,undefined8 *param_3)

{
  ulong uVar1;
  
  if (param_1 == 0) {
    uVar1 = *param_2;
    *param_3 = 0xffffffff;
    return (ulong)(uint)uVar1;
  }
  if (param_1 != 1) {
    return 0;
  }
  uVar1 = *param_2;
  *param_3 = 0xffffffffffffffff;
  return uVar1;
}


// ===== 002f7bf0 ccslIncrementCounter_IMPL =====

undefined8 ccslIncrementCounter_IMPL(long param_1,uint *param_2,ulong param_3)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0x1f;
  }
  uVar1 = *param_2;
  if (*(int *)(param_1 + 0xc) != 0) {
    if (*(int *)(param_1 + 0xc) == 1) {
      if (CARRY8((ulong)uVar1,param_3)) {
        nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x159,"ccslIncrementCounter_IMPL",4,
                     "NVRM: CCSL Error! IV overflow detected!\n");
        return 0x1a;
      }
      *(ulong *)param_2 = *(long *)param_2 + param_3;
    }
    return 0;
  }
  if (0xffffffff < param_3) {
    return 0x1f;
  }
  if (0xffffffff - param_3 < (ulong)uVar1) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x14b,"ccslIncrementCounter_IMPL",4,
                 "NVRM: CCSL Error! IV overflow detected!\n");
    return 0x1a;
  }
  *param_2 = uVar1 + (int)param_3;
  return 0;
}


// ===== 002f7cb0 ccslContextInitViaChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong ccslContextInitViaChannel_IMPL
                (long *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 local_d8;
  undefined8 local_d0;
  long local_c8 [19];
  
  local_d8 = 0;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x1a7,"ccslContextInitViaChannel_IMPL",1,
               "NVRM: Initializing CCSL context via channel.\n");
  if (*(char *)(lVar1 + 0x3f15d) == '\0') {
    return 0x56;
  }
  if (param_1 == (long *)0x0) {
    return 0x1f;
  }
  iVar3 = serverGetClientUnderLock(g_resServ,param_2,&local_d0);
  if (iVar3 != 0) {
    return 0x21;
  }
  iVar3 = CliGetKernelChannel(local_d0,param_4,local_c8);
  if (iVar3 != 0) {
    return 0x21;
  }
  lVar1 = *(long *)(*(long *)(local_c8[0] + 0x158) + 0xe0);
  if (lVar1 == 0) {
    return 0x21;
  }
  iVar3 = serverGetClientUnderLock(g_resServ,param_2,&local_d0);
  if (iVar3 != 0) {
    return 0x21;
  }
  iVar3 = CliGetKernelChannel(local_d0,param_4,local_c8);
  if (iVar3 != 0) {
    return 0x21;
  }
  if (local_c8[0] == 0) {
    return 0x21;
  }
  puVar5 = (undefined4 *)portMemAllocNonPaged(0xd8);
  if (puVar5 == (undefined4 *)0x0) {
    return 0x51;
  }
  *param_1 = (long)puVar5;
  puVar5[3] = 0;
  *(undefined8 *)(puVar5 + 0x2a) = 0;
  *(undefined8 *)(puVar5 + 0x32) = 0;
  cVar2 = libspdm_aead_gcm_prealloc(puVar5 + 0x2a);
  if (cVar2 == '\0') {
    uVar9 = *(undefined8 *)(puVar5 + 0x32);
    uVar4 = 0x51;
  }
  else {
    lVar6 = portMemAllocNonPaged(0x2c0);
    *(long *)(puVar5 + 0x32) = lVar6;
    if (lVar6 == 0) {
      uVar4 = 0x51;
      uVar9 = 0;
    }
    else {
      *puVar5 = param_2;
      puVar5[1] = param_3;
      puVar5[2] = param_4;
      lVar8 = lVar1 + 0x3b58;
      if (*(char *)(lVar1 + 0x909) != '\0') {
        cVar2 = rmGpuLockIsOwner(lVar6);
        if (cVar2 == '\0') {
          lVar8 = rmapiGetInterface(1);
        }
        else {
          lVar8 = rmapiGetInterface(4);
        }
      }
      portMemSet(local_c8,0,0x90);
      uVar4 = (**(code **)(lVar8 + 0x38))(lVar8,param_2,param_4,0xc56f010b,local_c8,0x90);
      uVar9 = 0x1f0;
      if (uVar4 == 0) {
        puVar5[0x34] = 0;
        writeKmbToContext(puVar5,local_c8,3);
        uVar4 = memdescCreate(&local_d8,lVar1,0x20,8,1,1);
        if (uVar4 == 0) {
          uVar4 = memdescAlloc(local_d8);
          if (uVar4 == 0) {
            uVar7 = (**(code **)(local_c8[0] + 0x210))(lVar1,local_c8[0],local_d8,1);
            uVar4 = (uint)uVar7;
            if (uVar4 == 0) {
              uVar9 = *(undefined8 *)(local_c8[0] + 0x4e0);
              *(undefined8 *)(puVar5 + 0x28) = 0x12000000120000;
              *(undefined8 *)(puVar5 + 0x2c) = 0;
              *(undefined8 *)(puVar5 + 0x30) = uVar9;
              *(undefined8 *)(puVar5 + 0x2e) = local_d8;
              return uVar7;
            }
            nvCheckOkFailedNoLog
                      (4,uVar7 & 0xffffffff,"status","src/kernel/gpu/conf_compute/ccsl.c",0x1fe);
            memdescFree(local_d8);
          }
          else {
            nvCheckOkFailedNoLog(4,uVar4,"status","src/kernel/gpu/conf_compute/ccsl.c",0x1fb);
          }
          memdescDestroy(local_d8);
          uVar9 = *(undefined8 *)(puVar5 + 0x32);
          goto LAB_002f7e33;
        }
        uVar9 = 0x1f8;
      }
      nvCheckOkFailedNoLog(4,uVar4,"status","src/kernel/gpu/conf_compute/ccsl.c",uVar9);
      uVar9 = *(undefined8 *)(puVar5 + 0x32);
    }
  }
LAB_002f7e33:
  portMemFree(uVar9);
  if (*(long *)(puVar5 + 0x2a) != 0) {
    libspdm_aead_free();
  }
  portMemFree(puVar5);
  return (ulong)uVar4;
}


// ===== 002f8140 ccslContextInitViaKeyId_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ccslContextInitViaKeyId_KERNEL(long param_1,long *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined1 local_a4 [124];
  
  lVar3 = *(long *)(g_pSys + 0x1e0);
  nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x225,"ccslContextInitViaKeyId_KERNEL",1,
               "NVRM: Initializing CCSL context via global key ID.\n");
  if (*(char *)(lVar3 + 0x3f15d) == '\0') {
    return 0x56;
  }
  if ((((param_2 != (long *)0x0) && (param_1 != 0)) &&
      (cVar1 = (**(code **)(param_1 + 0x270))(param_1,param_3), cVar1 != '\0')) &&
     (param_3 >> 0x10 == 0)) {
    lVar3 = portMemAllocNonPaged(0xd8);
    if (lVar3 != 0) {
      *param_2 = lVar3;
      portMemSet(lVar3,0,0xd8);
      cVar1 = libspdm_aead_gcm_prealloc(lVar3 + 0xa8);
      if (cVar1 != '\0') {
        lVar4 = portMemAllocNonPaged(0x20);
        *(long *)(lVar3 + 0xc0) = lVar4;
        if (lVar4 != 0) {
          portMemSet(lVar4,0,0x20);
          iVar2 = (**(code **)(param_1 + 0x198))(param_1,param_3,3,1,local_a4);
          if (iVar2 == 0) {
            *(undefined4 *)(lVar3 + 0xc) = 1;
            writeKmbToContext(lVar3,local_a4,3);
            confComputeGetKeyPairByKey_IMPL(param_1,param_3,lVar3 + 0xa4,lVar3 + 0xa0);
            *(long *)(lVar3 + 0xb0) = param_1;
            return 0;
          }
          portMemFree(*(undefined8 *)(lVar3 + 0xc0));
          if (*(long *)(lVar3 + 0xa8) != 0) {
            libspdm_aead_free();
          }
          portMemFree(lVar3);
          return iVar2;
        }
      }
      portMemFree(lVar3);
    }
    return 0x51;
  }
  return 0x1f;
}


// ===== 002f8350 ccslContextClear_IMPL =====

void ccslContextClear_IMPL(long param_1)

{
  long lVar1;
  
  nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x275,"ccslContextClear_IMPL",1,
               "NVRM: Clearing the CCSL context.\n");
  if (param_1 != 0) {
    portMemFree(*(undefined8 *)(param_1 + 200));
    if (*(int *)(param_1 + 0xc) == 0) {
      lVar1 = *(long *)(param_1 + 0xa8);
    }
    else {
      portMemFree(*(undefined8 *)(param_1 + 0xc0));
      lVar1 = *(long *)(param_1 + 0xa8);
    }
    if (lVar1 != 0) {
      libspdm_aead_free();
    }
    memdescFree(*(undefined8 *)(param_1 + 0xb8));
    memdescDestroy(*(undefined8 *)(param_1 + 0xb8));
    portMemFree(param_1);
    return;
  }
  return;
}


// ===== 002f8400 ccslContextUpdate_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ccslContextUpdate_KERNEL(undefined4 *param_1)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 local_b0;
  long local_a8 [18];
  
  nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x291,"ccslContextUpdate_KERNEL",1,
               "NVRM: Updating the CCSL context.\n");
  if ((param_1 == (undefined4 *)0x0) || (param_1[3] != 0)) {
    return 0x1f;
  }
  uVar1 = param_1[2];
  iVar4 = serverGetClientUnderLock(g_resServ,*param_1,&local_b0);
  if (iVar4 == 0) {
    iVar4 = CliGetKernelChannel(local_b0,uVar1,local_a8);
    if ((iVar4 == 0) && (lVar2 = *(long *)(*(long *)(local_a8[0] + 0x158) + 0xe0), lVar2 != 0)) {
      lVar5 = lVar2 + 0x3b58;
      if (*(char *)(lVar2 + 0x909) != '\0') {
        cVar3 = rmGpuLockIsOwner();
        if (cVar3 == '\0') {
          lVar5 = rmapiGetInterface(1);
        }
        else {
          lVar5 = rmapiGetInterface(4);
        }
      }
      portMemSet(local_a8,0,0x90);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,*param_1,param_1[2],0xc56f010b,local_a8,0x90);
      if (iVar4 == 0) {
        param_1[0x34] = param_1[0x34] + 1 & 0xf;
        writeKmbToContext(param_1,local_a8,3);
      }
      portMemSet(local_a8,0,0x90);
      return iVar4;
    }
  }
  return 0x21;
}


// ===== 002f85c0 ccslRotateIv_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ccslRotateIv_IMPL(undefined4 *param_1,byte param_2)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 uStack_ac;
  uint local_a8;
  undefined1 local_a4 [56];
  undefined1 local_6c [76];
  
  if (((1 < param_2) || (param_1 == (undefined4 *)0x0)) || (param_1[3] != 0)) {
    return 0x1f;
  }
  portMemSet(&local_a8,0,0x80);
  local_a8 = (uint)param_2;
  uVar1 = param_1[2];
  iVar3 = serverGetClientUnderLock(g_resServ,*param_1,&local_b8);
  if (((iVar3 == 0) && (iVar3 = CliGetKernelChannel(local_b8,uVar1,&local_b0), iVar3 == 0)) &&
     (lVar2 = *(long *)(*(long *)(CONCAT44(uStack_ac,local_b0) + 0x158) + 0xe0), lVar2 != 0)) {
    local_b0 = 0;
    lVar5 = lVar2 + 0x3b58;
    if (*(char *)(lVar2 + 0x909) != '\0') {
      iVar3 = rmGpuGroupLockAcquire(*(undefined4 *)(lVar2 + 0x7a4),0,1,0x8002,&local_b0);
      if (iVar3 != 0) {
        if (iVar3 == 99) {
          return 99;
        }
        uVar4 = nvstatusToString(iVar3);
        nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x30a,"ccslRotateIv_IMPL",1,
                     "NVRM: Converting %s to NV_ERR_GENERIC.\n",uVar4);
        return 0xffff;
      }
      lVar5 = rmapiGetInterface(4);
    }
    iVar3 = (**(code **)(lVar5 + 0x38))(lVar5,*param_1,param_1[2],0xc56f010c,&local_a8,0x80);
    if (iVar3 == 0) {
      if (*(char *)(lVar2 + 0x909) != '\0') {
        rmGpuGroupLockRelease(local_b0,0);
      }
      if (param_2 != 1) {
        portMemCopy(param_1 + 0x1c,0xc,local_a4,0xc);
        return 0;
      }
      portMemCopy(param_1 + 0xc,0xc,local_6c,0xc);
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar3,
               "pRmApi->Control(pRmApi, pCtx->hClient, pCtx->hChannel, NVC56F_CTRL_ROTATE_SECURE_CHANNEL_IV, &rotateIvParams, sizeof(rotateIvParams))"
               ,"src/kernel/gpu/conf_compute/ccsl.c",0x314);
    if (*(char *)(lVar2 + 0x909) == '\0') {
      return iVar3;
    }
    rmGpuGroupLockRelease(local_b0,0);
    return iVar3;
  }
  return 0x21;
}


// ===== 002f8880 ccslEncryptWithIv_IMPL =====

short ccslEncryptWithIv_IMPL
                (long param_1,uint param_2,undefined8 param_3,long param_4,undefined8 param_5,
                undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  char cVar1;
  short sVar2;
  long lVar3;
  ulong local_20;
  byte local_14 [12];
  
  if (param_1 != 0) {
    local_20 = (ulong)param_2;
    sVar2 = 0x1f;
    local_14[0] = 0;
    local_14[1] = 0;
    local_14[2] = 0;
    local_14[3] = 0;
    local_14[4] = 0;
    local_14[5] = 0;
    local_14[6] = 0;
    local_14[7] = 0;
    local_14[8] = 0;
    local_14[9] = 0;
    local_14[10] = 0;
    local_14[0xb] = 0;
    if (*(char *)(param_4 + 0xc) == '\x01') {
      *(undefined1 *)(param_4 + 0xc) = 0;
      lVar3 = 0;
      do {
        local_14[lVar3] = *(byte *)(param_4 + lVar3) ^ *(byte *)(param_1 + 0x7c + lVar3);
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0xc);
      cVar1 = libspdm_aead_aes_gcm_encrypt_prealloc
                        (*(undefined8 *)(param_1 + 0xa8),param_1 + 0x50,0x20,local_14,0xc,param_5,
                         param_6,param_3,local_20,param_8,0x10,param_7,&local_20);
      sVar2 = -(ushort)(cVar1 == '\0');
    }
    return sVar2;
  }
  return 0x1f;
}


// ===== 002f8950 __pfx_ccslEncrypt_KERNEL =====

undefined8
__pfx_ccslEncrypt_KERNEL
          (long param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5,
          undefined8 param_6,undefined8 param_7)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uStack_40;
  byte abStack_34 [20];
  
  if (param_1 == 0) {
    return 0x1f;
  }
  uVar3 = 0x1f;
  abStack_34[0] = 0;
  abStack_34[1] = 0;
  abStack_34[2] = 0;
  abStack_34[3] = 0;
  abStack_34[4] = 0;
  abStack_34[5] = 0;
  abStack_34[6] = 0;
  abStack_34[7] = 0;
  abStack_34[8] = 0;
  abStack_34[9] = 0;
  abStack_34[10] = 0;
  abStack_34[0xb] = 0;
  if (param_2 != 0) {
    uStack_40 = (ulong)param_2;
    iVar2 = ccslIncrementCounter_IMPL(param_1,param_1 + 0x70,1);
    if (iVar2 != 0) {
      return 0x1a;
    }
    lVar4 = 0;
    do {
      abStack_34[lVar4] = *(byte *)(param_1 + 0x70 + lVar4) ^ *(byte *)(param_1 + 0x7c + lVar4);
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0xc);
    cVar1 = libspdm_aead_aes_gcm_encrypt_prealloc
                      (*(undefined8 *)(param_1 + 0xa8),param_1 + 0x50,0x20,abStack_34,0xc,param_4,
                       param_5,param_3,(ulong)param_2,param_7,0x10,param_6,&uStack_40);
    uVar3 = 0xffff;
    if (cVar1 != '\0') {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 002f8960 ccslEncrypt_KERNEL =====

undefined8
ccslEncrypt_KERNEL(long param_1,uint param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_40;
  byte local_34 [20];
  
  if (param_1 == 0) {
    return 0x1f;
  }
  uVar3 = 0x1f;
  local_34[0] = 0;
  local_34[1] = 0;
  local_34[2] = 0;
  local_34[3] = 0;
  local_34[4] = 0;
  local_34[5] = 0;
  local_34[6] = 0;
  local_34[7] = 0;
  local_34[8] = 0;
  local_34[9] = 0;
  local_34[10] = 0;
  local_34[0xb] = 0;
  if (param_2 != 0) {
    local_40 = (ulong)param_2;
    iVar2 = ccslIncrementCounter_IMPL(param_1,param_1 + 0x70,1);
    if (iVar2 != 0) {
      return 0x1a;
    }
    lVar4 = 0;
    do {
      local_34[lVar4] = *(byte *)(param_1 + 0x70 + lVar4) ^ *(byte *)(param_1 + 0x7c + lVar4);
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0xc);
    cVar1 = libspdm_aead_aes_gcm_encrypt_prealloc
                      (*(undefined8 *)(param_1 + 0xa8),param_1 + 0x50,0x20,local_34,0xc,param_4,
                       param_5,param_3,(ulong)param_2,param_7,0x10,param_6,&local_40);
    uVar3 = 0xffff;
    if (cVar1 != '\0') {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ===== 002f8a90 ccslEncryptWithRotationChecks_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
ccslEncryptWithRotationChecks_KERNEL
          (long param_1,uint param_2,undefined8 param_3,undefined8 param_4,undefined4 param_5,
          undefined8 param_6)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  if (((param_1 != 0) && (lVar1 = *(long *)(param_1 + 0xb0), lVar1 != 0)) &&
     (*(long *)(param_1 + 0xc0) != 0)) {
    uVar5 = (ulong)param_2;
    cVar3 = (**(code **)(lVar1 + 0x270))(lVar1,*(undefined4 *)(param_1 + 0xa4));
    if (((cVar3 != '\0') && (puVar2 = *(ulong **)(param_1 + 0xc0), puVar2[2] <= puVar2[2] + uVar5))
       && (*puVar2 <= *puVar2 + 1)) {
      puVar2[2] = puVar2[2] + uVar5;
      **(long **)(param_1 + 0xc0) = **(long **)(param_1 + 0xc0) + 1;
      cVar3 = confComputeIsGivenThresholdCrossed_IMPL
                        (*(undefined8 *)(param_1 + 0xc0),*(undefined8 *)(lVar1 + 0x308),1);
      if (cVar3 != '\0') {
        nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0xdf,"ccslRotationChecksEncrypt",1,
                     "NVRM: Triggering key rotation for global key id 0x%x\n",
                     *(undefined4 *)(param_1 + 0xa4));
        nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0xe0,"ccslRotationChecksEncrypt",1,
                     "NVRM: Total bytes encrypted 0x%llx total encrypt ops 0x%llx\n",
                     (*(long **)(param_1 + 0xc0))[2] - uVar5,**(long **)(param_1 + 0xc0) + -1);
        uVar4 = (**(code **)(lVar1 + 0x268))(lVar1,*(undefined4 *)(param_1 + 0xa4));
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        uVar4 = ccslUpdateViaKeyId(lVar1,param_1,*(undefined4 *)(param_1 + 0xa4),0x2f8bfd);
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        *(ulong *)(*(long *)(param_1 + 0xc0) + 0x10) = uVar5;
        **(undefined8 **)(param_1 + 0xc0) = 1;
      }
      uVar4 = ccslEncrypt_KERNEL(param_1,param_2,param_3,param_4,param_5,param_6);
      return uVar4;
    }
  }
  return 0x1f;
}


// ===== 002f8cc0 ccslDecrypt_KERNEL =====

byte ccslDecrypt_KERNEL(long param_1,uint param_2,undefined8 param_3,long param_4,uint param_5,
                       long param_6,int param_7,undefined8 param_8,undefined8 param_9)

{
  char cVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  ulong local_30;
  byte local_24 [20];
  
  if (param_1 == 0) {
    return 0x1f;
  }
  uVar4 = (ulong)param_2;
  local_24[0] = 0;
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  local_24[4] = 0;
  local_24[5] = 0;
  local_24[6] = 0;
  local_24[7] = 0;
  local_24[8] = 0;
  local_24[9] = 0;
  local_24[10] = 0;
  local_24[0xb] = 0;
  if ((param_2 != 0) && ((param_6 == 0 || (param_7 != 0)))) {
    if ((*(int *)(param_1 + 0xc) == 0) && (param_5 != 0xffffffff)) {
      lVar6 = (ulong)(param_5 & 0xf) * 0x2c + *(long *)(param_1 + 200);
      lVar5 = lVar6 + 0x20;
    }
    else {
      lVar6 = param_1 + 0x10;
      lVar5 = param_1 + 0x3c;
    }
    lVar3 = 0;
    local_30 = uVar4;
    if (param_4 == 0) {
      iVar2 = ccslIncrementCounter_IMPL(param_1,param_1 + 0x30,1);
      if (iVar2 != 0) {
        return 0x1a;
      }
      lVar3 = 0;
      do {
        local_24[lVar3] = *(byte *)(param_1 + 0x30 + lVar3) ^ *(byte *)(lVar5 + lVar3);
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0xc);
    }
    else {
      do {
        local_24[lVar3] = *(byte *)(param_4 + lVar3) ^ *(byte *)(lVar5 + lVar3);
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0xc);
    }
    cVar1 = libspdm_aead_aes_gcm_decrypt_prealloc
                      (*(undefined8 *)(param_1 + 0xa8),lVar6,0x20,local_24,0xc,param_6,param_7,
                       param_3,uVar4,param_9,0x10,param_8,&local_30);
    return -(cVar1 == '\0') & 0x25;
  }
  return 0x1f;
}


// ===== 002f8e60 ccslDecryptWithRotationChecks_KERNEL =====

undefined8
ccslDecryptWithRotationChecks_KERNEL
          (long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 uVar1;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0xb0) != 0)) {
    uVar1 = ccslRotationChecksDecrypt(*(long *)(param_1 + 0xb0),param_1,param_2);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    uVar1 = ccslDecrypt_KERNEL(param_1,param_2,param_3,param_4,0xffffffff,param_5,param_6,param_7,
                               param_8);
    return uVar1;
  }
  return 0x1f;
}


// ===== 002f8f10 ccslSign_IMPL =====

undefined8 ccslSign_IMPL(long param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  long lVar4;
  byte bVar5;
  undefined8 uVar6;
  
  if (((param_1 == 0) || (param_2 == 0)) || (*(int *)(param_1 + 0xc) != 0)) {
    uVar6 = 0x1f;
  }
  else {
    pcVar1 = (char *)(param_1 + 0x30);
    pcVar3 = pcVar1;
    do {
      if (*pcVar3 != -1) {
        bVar5 = 1;
        pcVar3 = pcVar1;
        do {
          *pcVar3 = *pcVar3 + bVar5;
          cVar2 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          bVar5 = bVar5 & cVar2 == '\0';
        } while (pcVar3 != (char *)(param_1 + 0x48));
        lVar4 = libspdm_hmac_sha256_new();
        if (lVar4 != 0) {
          cVar2 = libspdm_hmac_sha256_set_key(lVar4,param_1 + 0x10,0x20);
          if (cVar2 != '\0') {
            cVar2 = libspdm_hmac_sha256_update(lVar4,param_3,param_2);
            if (cVar2 != '\0') {
              cVar2 = libspdm_hmac_sha256_update(lVar4,pcVar1,0x20);
              if (cVar2 != '\0') {
                cVar2 = libspdm_hmac_sha256_final(lVar4,param_4);
                if (cVar2 != '\0') {
                  libspdm_hmac_sha256_free(lVar4);
                  return 0;
                }
              }
            }
          }
          libspdm_hmac_sha256_free(lVar4);
        }
        return 0xffff;
      }
      pcVar3 = pcVar3 + 1;
    } while (pcVar3 != (char *)(param_1 + 0x48));
    uVar6 = 0x1a;
    nvDbg_Printf("src/kernel/gpu/conf_compute/ccsl.c",0x435,"ccslIncrementCounter192",4,
                 "NVRM: CCSL Error! IV overflow detected!\n");
  }
  return uVar6;
}


// ===== 002f90b0 ccslQueryMessagePool_IMPL =====

undefined8 ccslQueryMessagePool_IMPL(long param_1,char param_2,long *param_3)

{
  long lVar1;
  long local_10;
  
  if (param_1 == 0) {
    return 0x1f;
  }
  if (param_2 == '\0') {
    lVar1 = getMessageCounterAndLimit_isra_0
                      (*(undefined4 *)(param_1 + 0xc),param_1 + 0x70,&local_10);
  }
  else {
    if (param_2 != '\x01') {
      return 0x1f;
    }
    lVar1 = getMessageCounterAndLimit_isra_0
                      (*(undefined4 *)(param_1 + 0xc),param_1 + 0x30,&local_10);
  }
  *param_3 = local_10 - lVar1;
  return 0;
}


// ===== 002f9120 ccslIncrementIv_IMPL =====

int ccslIncrementIv_IMPL(long param_1,char param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  
  if (param_1 == 0) {
    return 0x1f;
  }
  if (param_2 == '\0') {
    lVar2 = param_1 + 0x70;
  }
  else {
    if (param_2 != '\x01') {
      return 0x1f;
    }
    lVar2 = param_1 + 0x30;
  }
  iVar1 = ccslIncrementCounter_IMPL(param_1,lVar2);
  if ((iVar1 == 0) && (param_4 != 0)) {
    portMemCopy(param_4,0xc,lVar2,0xc);
    *(bool *)(param_4 + 0xc) = param_2 == '\0';
  }
  return iVar1;
}


// ===== 002f91b0 ccslLogEncryption_IMPL =====

undefined8 ccslLogEncryption_IMPL(long param_1,char param_2,uint param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  long local_10;
  
  if (param_1 == 0) {
    return 0x1f;
  }
  uVar4 = (ulong)param_3;
  if (param_2 == '\0') {
    lVar2 = getMessageCounterAndLimit_isra_0
                      (*(undefined4 *)(param_1 + 0xc),param_1 + 0x70,&local_10);
    if (local_10 == lVar2) {
      return 0x1a;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      **(long **)(param_1 + 0xc0) = **(long **)(param_1 + 0xc0) + 1;
      plVar1 = (long *)(*(long *)(param_1 + 0xc0) + 0x10);
      *plVar1 = *plVar1 + (uVar4 & 0xffffffff);
      return 0;
    }
  }
  else {
    if (param_2 != '\x01') {
      return 0x1f;
    }
    lVar2 = getMessageCounterAndLimit_isra_0
                      (*(undefined4 *)(param_1 + 0xc),param_1 + 0x30,&local_10);
    if (lVar2 == local_10) {
      return 0x1a;
    }
    if (*(int *)(param_1 + 0xc) == 0) {
      plVar1 = (long *)(*(long *)(param_1 + 0xc0) + 8);
      *plVar1 = *plVar1 + 1;
      plVar1 = (long *)(*(long *)(param_1 + 0xc0) + 0x18);
      *plVar1 = *plVar1 + (uVar4 & 0xffffffff);
      return 0;
    }
  }
  if (*(int *)(param_1 + 0xa0) != 5) {
    return 0;
  }
  uVar3 = ccslRotationChecksDecrypt(*(undefined8 *)(param_1 + 0xb0),param_1,uVar4 & 0xffffffff);
  return uVar3;
}


// ===== 002f92a0 _confComputeDeinitSessionKeys.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _confComputeDeinitSessionKeys_part_0(long param_1)

{
  nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x1a1,"_confComputeDeinitSessionKeys",1,
               "NVRM: Tearing down CC Keys.\n");
  (**(code **)(param_1 + 0x280))(param_1);
  ccslContextClear_IMPL(*(undefined8 *)(param_1 + 0x2c0));
  ccslContextClear_IMPL(*(undefined8 *)(param_1 + 0x2c8));
  ccslContextClear_IMPL(*(undefined8 *)(param_1 + 0x2d8));
  ccslContextClear_IMPL(*(undefined8 *)(param_1 + 0x2d0));
  ccslContextClear_IMPL(*(undefined8 *)(param_1 + 0x2e8));
  *(undefined8 *)(param_1 + 0x2c0) = 0;
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  *(undefined8 *)(param_1 + 0x2d0) = 0;
  *(undefined8 *)(param_1 + 0x2e0) = 0;
  *(undefined8 *)(param_1 + 0x2e8) = 0;
  return;
}


// ===== 002f9380 confComputeConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong confComputeConstructEngine_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  ulong uVar9;
  uint local_40;
  uint local_3c [3];
  
  lVar2 = g_pSys;
  local_40 = 0;
  *(undefined8 *)(param_2 + 0x2f8) = 0;
  *(undefined4 *)(param_2 + 0x300) = 0;
  portMemSet(param_2 + 0x2b8,0,2);
  *(undefined4 *)(param_2 + 0x2b4) = 0;
  *(undefined8 *)(param_2 + 0x2c0) = 0;
  *(undefined8 *)(param_2 + 0x2c8) = 0;
  *(undefined8 *)(param_2 + 0x2d8) = 0;
  *(undefined8 *)(param_2 + 0x2d0) = 0;
  *(undefined8 *)(param_2 + 0x2e0) = 0;
  *(undefined8 *)(param_2 + 0x2e8) = 0;
  cVar3 = (**(code **)(param_1 + 0x3a0))(param_1);
  if (cVar3 != '\0') {
    *(undefined1 *)(param_1 + 1099) = 0;
    *(undefined8 *)(param_1 + 0x4924) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x492c) = 0xfffffeefffffffff;
  }
  cVar3 = (**(code **)(param_1 + 0x390))(param_1);
  if (cVar3 == '\0') {
    cVar3 = (**(code **)(param_1 + 0x3a0))(param_1);
    if (cVar3 == '\0') goto LAB_002f948a;
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x6c,"confComputeConstructEngine_IMPL"
                 ,1,"NVRM: Enabling protected PCIe in secure PRI\n");
    *(uint *)(param_2 + 0x2b4) = *(uint *)(param_2 + 0x2b4) | 8;
    *(undefined1 *)(param_2 + 0x2a8) = 1;
    *(undefined1 *)(param_2 + 0x2ae) = 1;
    cVar3 = (**(code **)(param_1 + 0x398))(param_1);
    if (cVar3 != '\0') goto LAB_002f9858;
LAB_002f94a1:
    cVar3 = (**(code **)(param_1 + 0x3b0))(param_1);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x66,"confComputeConstructEngine_IMPL"
                 ,1,"NVRM: CC mode is enabled by HW\n");
    *(undefined1 *)(param_2 + 0x2a8) = 1;
LAB_002f948a:
    cVar3 = (**(code **)(param_1 + 0x398))(param_1);
    if (cVar3 == '\0') goto LAB_002f94a1;
LAB_002f9858:
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x75,"confComputeConstructEngine_IMPL"
                 ,1,"NVRM: CC Devtools mode is enabled by HW\n");
    *(undefined1 *)(param_2 + 0x2ab) = 1;
    cVar3 = (**(code **)(param_1 + 0x3b0))(param_1);
  }
  if (cVar3 != '\0') {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x7c,"confComputeConstructEngine_IMPL"
                 ,1,"NVRM: Enabling NVlink encryption with multi GPU mode. \n");
    *(undefined1 *)(param_2 + 0x2a8) = 1;
    *(undefined1 *)(param_2 + 0x2af) = 1;
  }
  local_3c[0] = 0;
  lVar1 = *(long *)(param_1 + 0x1d10);
  cVar3 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
  if ((cVar3 != '\0') && (lVar1 == 0)) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0xe8,
                 "_confComputeInitRegistryOverrides",4,
                 "NVRM: Spdm object is not created when SPDM supported !!.\n");
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x85,"confComputeConstructEngine_IMPL"
                 ,4,"NVRM: Unexpected failure in confComputeConstructEngine! Status:0x%x\n",0x57);
    return 0x57;
  }
  iVar5 = osReadRegistryDword(param_1,"RmConfidentialCompute",local_3c);
  if ((iVar5 == 0) && ((local_3c[0] & 1) != 0)) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0xef,
                 "_confComputeInitRegistryOverrides",1,
                 "NVRM: Confidential Compute enabled via regkey override.\n");
    *(uint *)(param_2 + 0x2b4) = *(uint *)(param_2 + 0x2b4) | 1;
    *(undefined1 *)(param_2 + 0x2a8) = 1;
    if ((local_3c[0] & 4) == 0) {
      *(undefined1 *)(param_2 + 0x2ad) = 0;
    }
    if ((local_3c[0] & 2) != 0) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0xfa,
                   "_confComputeInitRegistryOverrides",1,
                   "NVRM: Confidential Compute dev mode enabled via regkey override.\n");
      *(uint *)(param_2 + 0x2b4) = *(uint *)(param_2 + 0x2b4) | 4;
      *(undefined1 *)(param_2 + 0x2ab) = 1;
    }
  }
  iVar5 = osReadRegistryDword(param_1,"RmCCMultiGpuNvle",local_3c);
  if ((iVar5 == 0) && (local_3c[0] == 1)) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x103,
                 "_confComputeInitRegistryOverrides",4,
                 "NVRM: Enabling NVlink encryption via regkey override. \n");
    *(uint *)(param_2 + 0x2b4) = *(uint *)(param_2 + 0x2b4) | 0x10;
    *(undefined1 *)(param_2 + 0x2a8) = 1;
    *(undefined1 *)(param_2 + 0x2af) = 1;
LAB_002f9698:
    if (cVar3 == '\0') {
      osReadRegistryDword(param_1,"RmConfComputeSpdmPolicy",local_3c);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x111,
                   "_confComputeInitRegistryOverrides",1,"NVRM: SPDM is enabled by default.\n");
      *(undefined1 *)(lVar1 + 0x218) = 1;
      iVar5 = osReadRegistryDword(param_1,"RmConfComputeSpdmPolicy",local_3c);
      if (iVar5 == 0) {
        if ((local_3c[0] & 1) == 0) {
          nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x122,
                       "_confComputeInitRegistryOverrides",1,
                       "NVRM: Confidential Compute SPDM disabled via regkey override.\n");
          *(undefined1 *)(lVar1 + 0x218) = 0;
          cVar3 = *(char *)(param_1 + 0x4910);
        }
        else {
          nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x11c,
                       "_confComputeInitRegistryOverrides",1,
                       "NVRM: Confidential Compute SPDM enabled via regkey override.\n");
          *(undefined1 *)(lVar1 + 0x218) = 1;
          cVar3 = *(char *)(param_1 + 0x4910);
        }
      }
      else {
        cVar3 = *(char *)(param_1 + 0x4910);
      }
      if (cVar3 != '\0') {
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x12d,
                     "_confComputeInitRegistryOverrides",1,
                     "NVRM: Confidential Compute SPDM disabled on Fmodel.\n");
        *(undefined1 *)(lVar1 + 0x218) = 0;
      }
    }
    if (*(char *)(param_2 + 0x2a8) == '\0') goto LAB_002f9539;
    iVar5 = osReadRegistryDword(param_1,"RmGspOwnedFaultBuffersEnable",local_3c);
    if (iVar5 == 0) {
      uVar4 = (undefined1)local_3c[0];
    }
    else {
      uVar4 = *(char *)(param_1 + 0x909) != '\0';
    }
    *(undefined1 *)(param_1 + 0x4a78) = uVar4;
    if (*(char *)(lVar2 + 0xa4) != '\0') goto LAB_002f977e;
  }
  else {
    if (*(char *)(param_2 + 0x2a8) != '\0') goto LAB_002f9698;
LAB_002f9539:
    if (*(char *)(lVar2 + 0xa4) == '\0') goto LAB_002f9547;
LAB_002f977e:
    cVar3 = (**(code **)(param_1 + 0x390))(param_1);
    if ((cVar3 == '\0') && (cVar3 = (**(code **)(param_1 + 0x3a0))(param_1), cVar3 == '\0')) {
      if (*(char *)(param_1 + 0x4ae) == '\0') {
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x92,
                     "confComputeConstructEngine_IMPL",4,
                     "NVRM: GPU does not support confidential compute.\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x8e,
                     "confComputeConstructEngine_IMPL",4,
                     "NVRM: GPU confidential compute capability is not enabled.\n");
      }
      nvAssertFailedNoLog(&DAT_00d08688,"src/kernel/gpu/conf_compute/conf_compute.c",0x95);
      return 0x3f;
    }
  }
  if (*(char *)(param_2 + 0x2a8) != '\0') {
    iVar5 = osReadRegistryDword(param_1,"RmConfidentialCompute",&local_40);
    if (((iVar5 != 0) || ((local_40 & 1) == 0)) && (*(char *)(lVar2 + 0xa4) == '\0')) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0xa1,
                   "confComputeConstructEngine_IMPL",4,
                   "NVRM: CPU does not support confidential compute.\n");
      nvAssertFailedNoLog(&DAT_00d08688,"src/kernel/gpu/conf_compute/conf_compute.c",0xa2);
      *(undefined1 *)(param_2 + 0x2a8) = 0;
      return 0x38;
    }
    cVar3 = (**(code **)(param_2 + 0x248))(param_1,param_2);
    if (cVar3 == '\0') {
      nvCheckFailedNoLog(4,"confComputeIsGpuCcCapable_HAL(pGpu, pConfCompute)",
                         "src/kernel/gpu/conf_compute/conf_compute.c",0xa8);
      return 0x38;
    }
    if (*(char *)(param_1 + 0x4af) == '\0') {
      if (*(char *)(param_1 + 0x4ae) == '\0') {
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0xba,
                     "confComputeConstructEngine_IMPL",4,
                     "NVRM: GPU does not support confidential compute.\n");
        nvAssertFailedNoLog(&DAT_00d08688,"src/kernel/gpu/conf_compute/conf_compute.c",0xbb);
        return 0x38;
      }
      *(undefined1 *)(param_2 + 0x2a9) = 1;
      *(undefined1 *)(param_1 + 0x4b5) = 1;
    }
    else {
      *(undefined1 *)(param_2 + 0x2aa) = 1;
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0xaf,
                   "confComputeConstructEngine_IMPL",1,
                   "NVRM: Confidential Compute devtools mode DISABLED in APM.\n");
      *(undefined1 *)(param_2 + 0x2ab) = 0;
    }
  }
LAB_002f9547:
  *(undefined8 *)(param_2 + 0x310) = 0x3c;
  *(undefined8 *)(param_2 + 0x1c58) = 1000000000;
  *(undefined4 *)(param_2 + 0x1c50) = 5;
  uVar6 = confComputeSetKeyRotationThreshold_IMPL(param_2,0x3c);
  if (uVar6 == 0) {
    puVar7 = (undefined4 *)(param_2 + 0xa80);
    do {
      *puVar7 = 0;
      *(undefined8 *)(param_2 * -3 + -0x1698 + (long)puVar7 * 4) = 0;
      puVar8 = puVar7 + 1;
      puVar7[0x402] = 0;
      puVar7 = puVar8;
    } while ((undefined4 *)(param_2 + 0xc48) != puVar8);
    portMemSet(param_2 + 0x318,0,0x720);
    portMemSet((undefined4 *)(param_2 + 0xc48),0,0x720);
    *(undefined4 *)(param_2 + 0x304) = 0;
    uVar6 = (**(code **)(param_2 + 0x230))(param_1,param_2);
    if (uVar6 == 0) {
      uVar9 = (**(code **)(param_2 + 0x238))(param_1,param_2);
      if ((int)uVar9 != 0) {
        nvAssertOkFailedNoLog
                  (uVar9 & 0xffffffff,
                   "confComputeEnableInternalKeyRotationSupport_HAL(pGpu, pConfCompute)",
                   "src/kernel/gpu/conf_compute/conf_compute.c",0xd0);
        uVar9 = uVar9 & 0xffffffff;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar6,"confComputeEnableKeyRotationSupport_HAL(pGpu, pConfCompute)",
                 "src/kernel/gpu/conf_compute/conf_compute.c",0xcf);
      uVar9 = (ulong)uVar6;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar6,
               "confComputeSetKeyRotationThreshold(pConfCompute, pConfCompute->attackerAdvantage)",
               "src/kernel/gpu/conf_compute/conf_compute.c",0xc3);
    uVar9 = (ulong)uVar6;
  }
  return uVar9;
}


// ===== 002f9cc0 confComputeDeriveSessionKeys_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong confComputeDeriveSessionKeys_KERNEL(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (*(char *)(param_2 + 0x2a8) == '\0') {
    return 0;
  }
  lVar1 = *(long *)(param_1 + 0x1d10);
  uVar3 = (**(code **)(param_2 + 0x278))(param_2);
  if ((int)uVar3 == 0) {
    if (lVar1 == 0) {
      return uVar3;
    }
    if (*(char *)(lVar1 + 0x218) == '\0') {
      return uVar3;
    }
    if (*(char *)(param_1 + 0x909) == '\0') {
      return uVar3;
    }
    uVar5 = (**(code **)(param_2 + 0x288))(param_2);
    uVar3 = spdmRetrieveExportSecret_IMPL(param_1,lVar1,0x20,uVar5);
    if ((int)uVar3 == 0) {
      uVar3 = (**(code **)(param_2 + 0x1b8))(param_2,0x32);
      uVar5 = 0x16b;
      pcVar4 = "confComputeDeriveSecrets_HAL(pConfCompute, MC_ENGINE_IDX_GSP)";
      if ((int)uVar3 == 0) {
        uVar3 = (**(code **)(param_2 + 0x1a8))(param_2);
        uVar5 = 0x171;
        pcVar4 = "confComputeDeriveInitialKeySeed_HAL(pConfCompute)";
        if ((int)uVar3 == 0) {
          uVar2 = ccslContextInitViaKeyId_KERNEL(param_2,param_2 + 0x2c0,0);
          if (uVar2 != 0) {
            nvAssertOkFailedNoLog
                      (uVar2,
                       "ccslContextInitViaKeyId(pConfCompute, &pConfCompute->pRpcCcslCtx, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_CPU_GSP_LOCKED_RPC))"
                       ,"src/kernel/gpu/conf_compute/conf_compute.c",0x176);
            return (ulong)uVar2;
          }
          uVar2 = ccslContextInitViaKeyId_KERNEL(param_2,param_2 + 0x2c8,2);
          if (uVar2 != 0) {
            nvAssertOkFailedNoLog
                      (uVar2,
                       "ccslContextInitViaKeyId(pConfCompute, &pConfCompute->pDmaCcslCtx, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_CPU_GSP_DMA))"
                       ,"src/kernel/gpu/conf_compute/conf_compute.c",0x17a);
            return (ulong)uVar2;
          }
          uVar2 = ccslContextInitViaKeyId_KERNEL(param_2,param_2 + 0x2d8,5);
          if (uVar2 != 0) {
            nvAssertOkFailedNoLog
                      (uVar2,
                       "ccslContextInitViaKeyId(pConfCompute, &pConfCompute->pReplayableFaultCcslCtx, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_GSP_CPU_REPLAYABLE_FAULT))"
                       ,"src/kernel/gpu/conf_compute/conf_compute.c",0x17e);
            return (ulong)uVar2;
          }
          uVar2 = ccslContextInitViaKeyId_KERNEL(param_2,param_2 + 0x2d0,7);
          if (uVar2 == 0) {
            uVar3 = ccslContextInitViaKeyId_KERNEL(param_2,param_2 + 0x2e8,10);
            if ((int)uVar3 == 0) {
              return uVar3;
            }
            nvAssertOkFailedNoLog
                      (uVar3 & 0xffffffff,
                       "ccslContextInitViaKeyId(pConfCompute, &pConfCompute->pNvleP2pWrappingCcslCtx, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_CPU_GSP_NVLE_P2P_WRAPPING))"
                       ,"src/kernel/gpu/conf_compute/conf_compute.c",0x187);
            return uVar3 & 0xffffffff;
          }
          nvAssertOkFailedNoLog
                    (uVar2,
                     "ccslContextInitViaKeyId(pConfCompute, &pConfCompute->pNonReplayableFaultCcslCtx, CC_GKEYID_GEN(CC_KEYSPACE_GSP, CC_LKEYID_GSP_CPU_NON_REPLAYABLE_FAULT))"
                     ,"src/kernel/gpu/conf_compute/conf_compute.c",0x182);
          return (ulong)uVar2;
        }
      }
    }
    else {
      uVar5 = 0x164;
      pcVar4 = 
      "spdmRetrieveExportSecret(pGpu, pSpdm, CC_EXPORT_MASTER_KEY_SIZE_BYTES, confComputeKeyStoreGetExportMasterKey(pConfCompute))"
      ;
    }
  }
  else {
    uVar5 = 0x15d;
    pcVar4 = "confComputeKeyStoreInit_HAL(pConfCompute)";
  }
  nvCheckOkFailedNoLog
            (4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/conf_compute/conf_compute.c",uVar5);
  return uVar3 & 0xffffffff;
}


// ===== 002f9f50 confComputeStatePostLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int confComputeStatePostLoad_IMPL(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800af3,param_2 + 0x2b8,2);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_CONF_COMPUTE_GET_STATIC_INFO, &pConfCompute->ccStaticInfo, sizeof(pConfCompute->ccStaticInfo))"
               ,"src/kernel/gpu/conf_compute/conf_compute.c",0x1c6);
    return iVar1;
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    iVar1 = (**(code **)(param_2 + 600))(param_1,param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = 0;
  if ((*(char *)(param_2 + 0x2b0) != '\0') && (*(char *)(param_2 + 0x2b1) != '\0')) {
    iVar1 = (**(code **)(param_2 + 0x228))(param_1,param_2,1);
    if (iVar1 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar1,"confComputeEnableKeyRotationCallback_HAL(pGpu, pConfCompute, NV_TRUE)",
                 "src/kernel/gpu/conf_compute/conf_compute.c",0x1d9);
    }
  }
  return iVar1;
}


// ===== 002fa070 confComputeStatePreUnload_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int confComputeStatePreUnload_KERNEL(long param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  int iVar3;
  long *plVar4;
  
  if ((*(char *)(param_2 + 0x2b0) == '\0') || (*(char *)(param_2 + 0x2b1) == '\0')) {
    iVar3 = 0;
  }
  else {
    plVar4 = (long *)(param_2 + 0x1368);
    uVar2 = *(undefined8 *)(param_1 + 0x1b88);
    do {
      if (*plVar4 != 0) {
        tmrEventCancel_IMPL(uVar2);
        portMemFree(*(undefined8 *)(*plVar4 + 8));
        tmrEventDestroy_IMPL(uVar2,*plVar4);
        *plVar4 = 0;
      }
      plVar4 = plVar4 + 2;
    } while (plVar4 != (long *)(param_2 + 0x1a88));
    iVar3 = (**(code **)(param_2 + 0x228))(param_1,param_2,0);
    if (iVar3 == 0) {
      cVar1 = *(char *)(param_1 + 0x909);
      goto joined_r0x002fa152;
    }
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x205,
                 "confComputeStatePreUnload_KERNEL",4,"NVRM: Failed to disable key rotation 0x%x\n",
                 iVar3);
  }
  cVar1 = *(char *)(param_1 + 0x909);
joined_r0x002fa152:
  if ((cVar1 == '\0') && (*(char *)(param_2 + 0x2a8) != '\0')) {
    _confComputeDeinitSessionKeys_part_0(param_2);
    return iVar3;
  }
  return iVar3;
}


// ===== 002fa1b0 confComputeAcceptClientRequest_IMPL =====

undefined1 confComputeAcceptClientRequest_IMPL(undefined8 param_1,long param_2)

{
  undefined1 uVar1;
  
  uVar1 = 1;
  if (*(char *)(param_2 + 0x2ad) != '\0') {
    uVar1 = *(undefined1 *)(*(long *)(g_pSys + 0x1e0) + 0x3f160);
  }
  return uVar1;
}


// ===== 002fa1e0 confComputeStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int confComputeStateInitLocked_IMPL(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800af3,param_2 + 0x2b8,2);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x236,
                 "confComputeStateInitLocked_IMPL",1,"NVRM: BAR1 Trusted: 0x%x PCIE Trusted: 0x%x\n"
                 ,*(undefined1 *)(param_2 + 0x2b8),*(undefined1 *)(param_2 + 0x2b9));
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_CONF_COMPUTE_GET_STATIC_INFO, &pConfCompute->ccStaticInfo, sizeof(pConfCompute->ccStaticInfo))"
             ,"src/kernel/gpu/conf_compute/conf_compute.c",0x22f);
  return iVar1;
}


// ===== 002fa290 confComputeInitChannelIterForKey_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int confComputeInitChannelIterForKey_IMPL
              (undefined8 param_1,long param_2,ulong param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_3c [3];
  
  lVar2 = gpuGetKernelFifoShared_IMPL();
  iVar1 = (**(code **)(param_2 + 0x1e0))(param_2,param_3 >> 0x10 & 0xffff);
  if (iVar1 == 0) {
    iVar1 = 0x1f;
    nvAssertFailedNoLog("engineId != RM_ENGINE_TYPE_NULL",
                        "src/kernel/gpu/conf_compute/conf_compute.c",0x250);
  }
  else {
    iVar1 = (**(code **)(lVar2 + 0x218))(param_1,lVar2,2,iVar1,3,local_3c);
    if (iVar1 == 0) {
      kfifoGetChannelIterator_IMPL(param_1,lVar2,param_4,local_3c[0]);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,
                 "kfifoEngineInfoXlate(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, engineId, ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
                 ,"src/kernel/gpu/conf_compute/conf_compute.c",0x253);
    }
  }
  return iVar1;
}


// ===== 002fa360 confComputeGetNextChannelForKey_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
confComputeGetNextChannelForKey_IMPL
          (undefined8 param_1,long param_2,long param_3,undefined4 param_4,long *param_5)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long local_40 [2];
  
  if (param_5 == (long *)0x0) {
    nvAssertFailedNoLog("ppKernelChannel != NULL","src/kernel/gpu/conf_compute/conf_compute.c",0x26c
                       );
    return 0x1f;
  }
  *param_5 = 0;
  uVar5 = gpuGetKernelFifoShared_IMPL();
  cVar1 = (**(code **)(param_2 + 0x200))(param_2,param_4);
  cVar2 = (**(code **)(param_2 + 0x208))(param_2,param_4);
  local_40[0] = 0;
  do {
    do {
      iVar4 = kfifoGetNextKernelChannel_IMPL(param_1,uVar5,param_3,local_40);
      if (iVar4 != 0) {
        return 0x57;
      }
    } while (((*(int *)(param_3 + 0xc) != *(int *)(local_40[0] + 0x2b0)) ||
             (*(char *)(local_40[0] + 0x4f8) == '\0')) ||
            (cVar3 = kchannelCheckIsKernel_IMPL(), cVar3 != cVar1));
    if (cVar1 == '\0') {
      *param_5 = local_40[0];
      lVar6 = local_40[0];
    }
    else {
      if (cVar2 == '\0') {
        if (*(char *)(local_40[0] + 0x4f9) != '\0') goto LAB_002fa435;
      }
      else if (*(char *)(local_40[0] + 0x4f9) == '\0') {
LAB_002fa435:
        *param_5 = local_40[0];
        return 0;
      }
      lVar6 = *param_5;
    }
    if (lVar6 != 0) {
      return 0;
    }
  } while( true );
}


// ===== 002fa4e0 confComputeSetErrorState_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void confComputeSetErrorState_KERNEL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined1 local_29 [9];
  
  local_29[0] = 0;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x2ac,"confComputeSetErrorState_KERNEL",
               4,"NVRM: ConfCompute: Fatal error hit!\n");
  *(undefined1 *)(param_2 + 0x2f0) = 0;
  *(undefined1 *)(lVar1 + 0x3f160) = 0;
  *(undefined1 *)(lVar1 + 0x3f163) = 1;
  iVar3 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800ae7,local_29,1);
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",700,"confComputeSetErrorState_KERNEL",
                 4,"NVRM: ConfCompute: Failed setting GPU state to not ready!\n");
  }
  cVar2 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
  if (cVar2 != '\0') {
    iVar3 = spdmContextDeinit_IMPL(param_1,*(undefined8 *)(param_1 + 0x1d10),1);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute.c",0x2c7,
                   "confComputeSetErrorState_KERNEL",4,
                   "NVRM: ConfCompute: Failed tearing down SPDM!: 0x%x!\n",iVar3);
    }
  }
  if (*(char *)(param_2 + 0x2a8) == '\0') {
    return;
  }
  _confComputeDeinitSessionKeys_part_0(param_2);
  return;
}


// ===== 002fa640 confComputeDestruct_KERNEL =====

void confComputeDestruct_KERNEL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x150);
  }
  gpuEngineGetGpu(uVar1);
  if (*(char *)(param_1 + 0x2a8) == '\0') {
    return;
  }
  _confComputeDeinitSessionKeys_part_0(param_1);
  return;
}


// ===== 002fa690 confComputeGetKeySlotFromGlobalKeyId_IMPL =====

undefined8 confComputeGetKeySlotFromGlobalKeyId_IMPL(undefined8 param_1,uint param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pSlot != NULL","src/kernel/gpu/conf_compute/conf_compute.c",0x2f5);
    return 0x1f;
  }
  uVar1 = 0xffff;
  iVar2 = 0;
  do {
    while( true ) {
      if ((ushort)((short)(param_2 >> 0x10) - 1U) == uVar1) goto LAB_002fa6c2;
      if (uVar1 < 0x11) break;
      iVar2 = iVar2 + 0xc;
      uVar1 = 0;
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 6;
  } while (uVar1 != 0x11);
LAB_002fa6c2:
  uVar3 = (param_2 & 0xffff) + iVar2;
  if (uVar3 < 0x72) {
    *param_3 = uVar3;
    return 0;
  }
  return 0x1f;
}


// ===== 002fa720 confComputeApiConstruct_IMPL =====

undefined8 confComputeApiConstruct_IMPL(long param_1)

{
  *(long *)(param_1 + 0xd8) = *(long *)(g_pSys + 0x1e0) + 0x3f15c;
  return 0;
}


// ===== 002fa750 confComputeApiDestruct_IMPL =====

void confComputeApiDestruct_IMPL(void)

{
  return;
}


// ===== 002fa760 confComputeApiCtrlCmdSystemGetCapabilities_IMPL =====

/* WARNING: Type propagation algorithm not settling */

undefined8 confComputeApiCtrlCmdSystemGetCapabilities_IMPL(long param_1,undefined1 *param_2)

{
  char *pcVar1;
  long lVar2;
  char cVar3;
  undefined1 uVar4;
  uint local_30 [4];
  
  lVar2 = g_pSys;
  local_30[0] = 0;
  local_30[1] = 0;
  pcVar1 = *(char **)(param_1 + 0xd8);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
LAB_002fa870:
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/conf_compute/conf_compute_api.c",0x51);
    return 0x2f;
  }
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') goto LAB_002fa870;
  *param_2 = 0;
  if (*(char *)(lVar2 + 0xa4) != '\0') {
    *param_2 = 1;
    if (*(char *)(lVar2 + 0xa5) == '\0') {
      if (*(char *)(lVar2 + 0xa7) == '\0') {
        if (*(char *)(lVar2 + 0xa8) != '\0') {
          *param_2 = 2;
        }
      }
      else {
        *param_2 = 4;
      }
    }
    else {
      *param_2 = 3;
    }
  }
  *(undefined4 *)(param_2 + 1) = 0;
  param_2[5] = 0;
  if (*pcVar1 == '\0') {
    uVar4 = 0;
    if (pcVar1[1] == '\0') goto LAB_002fa818;
    uVar4 = 2;
  }
  else {
    uVar4 = 1;
  }
  param_2[1] = uVar4;
  uVar4 = 0;
  if (pcVar1[2] != '\0') {
    if (*pcVar1 == '\0') {
      uVar4 = 0;
      if (pcVar1[1] == '\0') goto LAB_002fa818;
      param_2[3] = 2;
    }
    else {
      param_2[3] = 1;
    }
    uVar4 = 2;
  }
LAB_002fa818:
  param_2[2] = uVar4;
  if (pcVar1[3] != '\0') {
    param_2[4] = 1;
    param_2[2] = 1;
  }
  gpumgrGetGpuAttachInfo(local_30,local_30 + 1);
  if (pcVar1[5] == '\0') {
    if ((pcVar1[6] != '\0') && (1 < local_30[0])) {
      param_2[5] = 2;
    }
  }
  else {
    param_2[3] = 0;
    param_2[5] = 1;
  }
  return 0;
}


// ===== 002fa900 confComputeApiCtrlCmdSystemGetGpusState_IMPL =====

undefined8 confComputeApiCtrlCmdSystemGetGpusState_IMPL(long param_1,undefined1 *param_2)

{
  char cVar1;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    cVar1 = rmGpuLockIsOwner();
    if (cVar1 != '\0') {
      *param_2 = *(undefined1 *)(*(long *)(param_1 + 0xd8) + 4);
      return 0;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/conf_compute/conf_compute_api.c",0xa2);
  return 0x2f;
}


// ===== 002fa970 confComputeApiCtrlCmdSystemSetGpusState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong confComputeApiCtrlCmdSystemSetGpusState_IMPL(long param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  char local_31;
  undefined4 local_30;
  undefined4 local_2c [3];
  
  local_2c[0] = 0;
  local_31 = '\0';
  cVar1 = rmapiLockIsOwner();
  if ((cVar1 == '\0') || (cVar1 = rmGpuLockIsOwner(), cVar1 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/conf_compute/conf_compute_api.c",0xb7);
    return 0x2f;
  }
  lVar4 = *(long *)(param_1 + 0xd8);
  if (*(char *)(lVar4 + 7) != '\0') {
    return 0x1f;
  }
  local_31 = *param_2;
  if ((*(char *)(lVar4 + 4) != '\0') && (local_31 == '\0')) {
    *(undefined1 *)(lVar4 + 7) = 1;
    *(undefined1 *)(*(long *)(param_1 + 0xd8) + 4) = 0;
    local_31 = *param_2;
  }
  gpumgrGetGpuAttachInfo(0,&local_30);
  do {
    lVar4 = gpumgrGetNextGpu(local_30,local_2c);
    if (lVar4 == 0) {
      *(char *)(*(long *)(param_1 + 0xd8) + 4) = *param_2;
      return 0;
    }
    if (((*(long *)(lVar4 + 0x1ce8) != 0) && (*(char *)(*(long *)(lVar4 + 0x1ce8) + 0x2f3) != '\0'))
       && (uVar2 = knvlinkSetupNvleRemapTables_IMPL(lVar4), uVar2 != 0)) {
      nvCheckOkFailedNoLog
                (4,uVar2,"knvlinkSetupNvleRemapTables(pGpu, pKernelNvlink)",
                 "src/kernel/gpu/conf_compute/conf_compute_api.c",0xcd);
      return (ulong)uVar2;
    }
    if (*(char *)(lVar4 + 0x908) != '\0') {
      return 0x56;
    }
    uVar3 = (**(code **)(lVar4 + 0x3b90))
                      (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),
                       *(undefined4 *)(lVar4 + 0x3b3c),0x20800ae7,&local_31,1);
  } while ((int)uVar3 == 0);
  return uVar3;
}


// ===== 002fab36 confComputeApiCtrlCmdGpuGetVidmemSize_IMPL.cold =====

void confComputeApiCtrlCmdGpuGetVidmemSize_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002fab40 confComputeApiCtrlCmdGpuGetVidmemSize_IMPL =====

ulong confComputeApiCtrlCmdGpuGetVidmemSize_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  long local_48;
  long local_40;
  ulong local_38;
  ulong local_30 [2];
  
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30[0] = 0;
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 != '\0') && (cVar3 = rmGpuLockIsOwner(), cVar3 != '\0')) {
    if (param_1 == 0) {
      uVar6 = confComputeApiCtrlCmdGpuGetVidmemSize_IMPL_cold();
      return uVar6;
    }
    uVar4 = subdeviceGetByHandle_IMPL
                      (**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),*param_2,&local_48);
    if (uVar4 == 0) {
      lVar1 = *(long *)(*(long *)(local_48 + 0x158) + 0xe0);
      lVar2 = *(long *)(lVar1 + 0x1bc0);
      lVar7 = *(long *)(*(long *)(lVar1 + 0x1b78) + 0x478);
      if ((lVar2 != 0) && (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar3 != '\0')) {
        uVar5 = kmigmgrGetMemoryPartitionHeapFromDevice_IMPL
                          (lVar1,lVar2,*(undefined8 *)(*(long *)(local_48 + 0x158) + 0xe8),&local_40
                          );
        if (uVar5 != 0) {
          nvCheckOkFailedNoLog
                    (1,uVar5,
                     "kmigmgrGetMemoryPartitionHeapFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pSubdevice), &pMemoryPartitionHeap)"
                     ,"src/kernel/gpu/conf_compute/conf_compute_api.c",0x102);
          return (ulong)uVar5;
        }
        if (local_40 != 0) {
          lVar7 = local_40;
        }
      }
      pmaGetTotalProtectedMemory(*(undefined8 *)(lVar7 + 0x128),&local_38);
      pmaGetTotalUnprotectedMemory(*(undefined8 *)(lVar7 + 0x128),local_30);
      *(ulong *)(param_2 + 2) = local_38 >> 10;
      *(ulong *)(param_2 + 4) = local_30[0] >> 10;
    }
    else {
      nvCheckOkFailedNoLog
                (1,uVar4,
                 "subdeviceGetByHandle(RES_GET_CLIENT(pConfComputeApi), pParams->hSubDevice, &pSubdevice)"
                 ,"src/kernel/gpu/conf_compute/conf_compute_api.c",0xf4);
    }
    return (ulong)uVar4;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/conf_compute/conf_compute_api.c",0xf2);
  return 0x2f;
}


// ===== 002fad20 confComputeApiCtrlCmdGpuSetVidmemSize_IMPL =====

undefined8 confComputeApiCtrlCmdGpuSetVidmemSize_IMPL(void)

{
  char cVar1;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    cVar1 = rmGpuLockIsOwner();
    if (cVar1 != '\0') {
      return 0;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/conf_compute/conf_compute_api.c",0x11e);
  return 0x2f;
}


// ===== 002fad5f confComputeApiCtrlCmdGetGpuCertificate_IMPL.cold =====

void confComputeApiCtrlCmdGetGpuCertificate_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002fad70 confComputeApiCtrlCmdGetGpuCertificate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong confComputeApiCtrlCmdGetGpuCertificate_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  ulong uVar6;
  long local_20;
  
  local_20 = 0;
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/conf_compute/conf_compute_api.c",0x130);
    return 0x2f;
  }
  if (param_1 == 0) {
    uVar6 = confComputeApiCtrlCmdGetGpuCertificate_IMPL_cold();
    return uVar6;
  }
  uVar5 = subdeviceGetByHandle_IMPL
                    (**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),*param_2,&local_20);
  if (uVar5 == 0) {
    lVar1 = *(long *)(*(long *)(local_20 + 0x158) + 0xe0);
    lVar2 = *(long *)(lVar1 + 0x1d18);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar1 + 0x1d10);
      cVar4 = (**(code **)(lVar2 + 0x1d8))(lVar1,lVar2);
      if ((cVar4 != '\0') && (*(char *)(lVar3 + 0x218) != '\0')) {
        param_2[0x401] = 0x1000;
        param_2[0x902] = 0x1400;
        uVar6 = (**(code **)(lVar3 + 0x178))
                          (lVar1,lVar3,param_2 + 1,param_2 + 0x401,param_2 + 0x402,param_2 + 0x902);
        if ((int)uVar6 == 0) {
          return uVar6;
        }
        (**(code **)(lVar2 + 0x180))(lVar1,lVar2,*(code **)(lVar2 + 0x180));
        return uVar6 & 0xffffffff;
      }
    }
    uVar6 = 0x57;
  }
  else {
    nvCheckOkFailedNoLog
              (1,uVar5,
               "subdeviceGetByHandle(RES_GET_CLIENT(pConfComputeApi), pParams->hSubDevice, &pSubdevice)"
               ,"src/kernel/gpu/conf_compute/conf_compute_api.c",0x132);
    uVar6 = (ulong)uVar5;
  }
  return uVar6;
}


// ===== 002faf00 confComputeApiCtrlCmdGetGpuAttestationReport_IMPL.cold =====

void confComputeApiCtrlCmdGetGpuAttestationReport_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002faf10 confComputeApiCtrlCmdGetGpuAttestationReport_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong confComputeApiCtrlCmdGetGpuAttestationReport_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  ulong uVar6;
  long local_20;
  
  local_20 = 0;
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/conf_compute/conf_compute_api.c",0x160);
    return 0x2f;
  }
  if (param_1 == 0) {
    uVar6 = confComputeApiCtrlCmdGetGpuAttestationReport_IMPL_cold();
    return uVar6;
  }
  uVar5 = subdeviceGetByHandle_IMPL
                    (**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),*param_2,&local_20);
  if (uVar5 == 0) {
    lVar1 = *(long *)(*(long *)(local_20 + 0x158) + 0xe0);
    lVar2 = *(long *)(lVar1 + 0x1d18);
    if (lVar2 != 0) {
      lVar3 = *(long *)(lVar1 + 0x1d10);
      cVar4 = (**(code **)(lVar2 + 0x1d8))(lVar1,lVar2);
      if ((cVar4 != '\0') && (*(char *)(lVar3 + 0x218) != '\0')) {
        param_2[0x809] = 0x2000;
        param_2[0xc0b] = 0x1000;
        uVar6 = (**(code **)(lVar3 + 0x180))
                          (lVar1,lVar3,param_2 + 1,param_2 + 9,param_2 + 0x809,param_2 + 0x80a,
                           (long)param_2 + 0x2029);
        if ((int)uVar6 == 0) {
          return uVar6;
        }
        (**(code **)(lVar2 + 0x180))(lVar1,lVar2,*(code **)(lVar2 + 0x180),param_2 + 0xc0b);
        return uVar6 & 0xffffffff;
      }
    }
    uVar6 = 0x57;
  }
  else {
    nvCheckOkFailedNoLog
              (1,uVar5,
               "subdeviceGetByHandle(RES_GET_CLIENT(pConfComputeApi), pParams->hSubDevice, &pSubdevice)"
               ,"src/kernel/gpu/conf_compute/conf_compute_api.c",0x162);
    uVar6 = (ulong)uVar5;
  }
  return uVar6;
}


// ===== 002fb0b0 confComputeApiCtrlCmdGpuGetNumSecureChannels_IMPL.cold =====

void confComputeApiCtrlCmdGpuGetNumSecureChannels_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002fb0c0 confComputeApiCtrlCmdGpuGetNumSecureChannels_IMPL =====

ulong confComputeApiCtrlCmdGpuGetNumSecureChannels_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long local_20;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    cVar1 = rmGpuLockIsOwner();
    if (cVar1 != '\0') {
      if (param_1 != 0) {
        uVar2 = subdeviceGetByHandle_IMPL
                          (**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),*param_2,&local_20);
        if (uVar2 == 0) {
          lVar3 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(local_20 + 0x158) + 0xe0));
          param_2[1] = *(undefined4 *)(lVar3 + 0x4a8);
          param_2[2] = *(undefined4 *)(lVar3 + 0x4ac);
        }
        else {
          nvCheckOkFailedNoLog
                    (1,uVar2,
                     "subdeviceGetByHandle(RES_GET_CLIENT(pConfComputeApi), pParams->hSubDevice, &pSubdevice)"
                     ,"src/kernel/gpu/conf_compute/conf_compute_api.c",0x193);
        }
        return (ulong)uVar2;
      }
      uVar4 = confComputeApiCtrlCmdGpuGetNumSecureChannels_IMPL_cold();
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/conf_compute/conf_compute_api.c",0x191);
  return 0x2f;
}


// ===== 002fb1b0 confComputeApiCtrlCmdSystemGetSecurityPolicy_IMPL =====

undefined8 confComputeApiCtrlCmdSystemGetSecurityPolicy_IMPL(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(g_pSys + 0x1e0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      *param_2 = *(undefined8 *)(lVar1 + 0x3f168);
      return 0;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/conf_compute/conf_compute_api.c",0x1aa);
  return 0x2f;
}


// ===== 002fb220 confComputeApiCtrlCmdSystemSetSecurityPolicy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong confComputeApiCtrlCmdSystemSetSecurityPolicy_IMPL(long param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  undefined4 local_38;
  undefined4 local_34;
  long local_30 [2];
  
  local_34 = 0;
  local_30[0] = 0;
  lVar1 = *(long *)(g_pSys + 0x1e0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/conf_compute/conf_compute_api.c",0x1c1);
    return 0x2f;
  }
  if (*(char *)(*(long *)(param_1 + 0xd8) + 4) == '\0') {
    local_30[0] = *param_2;
    uVar5 = 0x1f;
    if (local_30[0] - 0x32U < 0x10) {
      gpumgrGetGpuAttachInfo(0,&local_38);
      do {
        lVar6 = gpumgrGetNextGpu(local_38,&local_34);
        if (lVar6 == 0) {
          *(long *)(lVar1 + 0x3f168) = *param_2;
          return 0;
        }
        uVar2 = *(undefined8 *)(lVar6 + 0x1d18);
        uVar5 = (**(code **)(lVar6 + 0x3b90))
                          (lVar6 + 0x3b58,*(undefined4 *)(lVar6 + 0x3b34),
                           *(undefined4 *)(lVar6 + 0x3b3c),0x20800ae8,local_30,8);
        if ((int)uVar5 != 0) {
          return uVar5;
        }
        uVar4 = confComputeSetKeyRotationThreshold_IMPL(uVar2,*param_2);
      } while (uVar4 == 0);
      nvAssertOkFailedNoLog
                (uVar4,
                 "confComputeSetKeyRotationThreshold(pConfCompute, pParams->attackerAdvantage)",
                 "src/kernel/gpu/conf_compute/conf_compute_api.c",0x1de);
      uVar5 = (ulong)uVar4;
    }
  }
  else {
    nvCheckFailedNoLog(1,"pConfComputeApi->pCcCaps->bAcceptClientRequest == NV_FALSE",
                       "src/kernel/gpu/conf_compute/conf_compute_api.c",0x1c4);
    uVar5 = 0x40;
  }
  return uVar5;
}


// ===== 002fb3a4 confComputeApiCtrlCmdGpuGetKeyRotationState_IMPL.cold =====

void confComputeApiCtrlCmdGpuGetKeyRotationState_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 002fb3b0 confComputeApiCtrlCmdGpuGetKeyRotationState_IMPL =====

ulong confComputeApiCtrlCmdGpuGetKeyRotationState_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long local_20;
  
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/conf_compute/conf_compute_api.c",500);
    return 0x2f;
  }
  if (param_1 == 0) {
    uVar3 = confComputeApiCtrlCmdGpuGetKeyRotationState_IMPL_cold();
    return uVar3;
  }
  uVar3 = subdeviceGetByHandle_IMPL
                    (**(undefined8 **)(*(long *)(param_1 + 0xb8) + 0x48),*param_2,&local_20);
  if ((int)uVar3 != 0) {
    nvCheckOkFailedNoLog
              (1,uVar3 & 0xffffffff,
               "subdeviceGetByHandle(RES_GET_CLIENT(pConfComputeApi), pParams->hSubDevice, &pSubdevice)"
               ,"src/kernel/gpu/conf_compute/conf_compute_api.c",0x1f6);
    return uVar3 & 0xffffffff;
  }
  lVar1 = *(long *)(*(long *)(*(long *)(local_20 + 0x158) + 0xe0) + 0x1d18);
  if (((lVar1 != 0) && (*(char *)(lVar1 + 0x2b0) != '\0')) && (*(char *)(lVar1 + 0x2b1) != '\0')) {
    uVar5 = *(uint *)(lVar1 + 0x304) & 0x800;
    uVar6 = *(uint *)(lVar1 + 0x304) & 0x400;
    uVar7 = uVar5 >> 0xb;
    uVar4 = uVar6 >> 10;
    if ((uVar4 != 0) && (uVar7 != 0)) {
      param_2[1] = 3;
      return uVar3;
    }
    if ((uVar5 == 0) && ((char)uVar4 != '\0')) {
      param_2[1] = 1;
      return uVar3;
    }
    if ((uVar6 == 0) && (uVar7 != 0)) {
      param_2[1] = 2;
      return uVar3;
    }
  }
  param_2[1] = 0;
  return uVar3;
}


// ===== 002fb520 confComputeKeyRotationCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void confComputeKeyRotationCallback(long param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(long *)(param_1 + 0x1d18) + 0x218))();
  if (iVar1 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x2f,
               "confComputeKeyRotationCallback",4,
               "NVRM: Key rotation callback failed with status 0x%x\n",iVar1);
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",
                      0x30);
  return;
}


// ===== 002fb590 confComputeSetKeyRotationStatus_IMPL =====

ulong confComputeSetKeyRotationStatus_IMPL(long param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  ulong uVar2;
  uint local_30;
  uint local_2c [3];
  
  if ((param_2 & 1) == 0) {
    uVar1 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,&local_30);
    param_2 = param_2 & 0xffff0000 | (param_2 & 0xffff) + 1;
  }
  else {
    uVar1 = confComputeGetKeySlotFromGlobalKeyId_IMPL
                      (param_1,(param_2 & 0xffff) - 1 | param_2 & 0xffff0000,&local_30);
  }
  if (uVar1 == 0) {
    uVar2 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,local_2c);
    if ((int)uVar2 == 0) {
      *(undefined4 *)(param_1 + 0xa80 + (ulong)local_30 * 4) = param_3;
      *(undefined4 *)(param_1 + 0xa80 + (ulong)local_2c[0] * 4) = param_3;
    }
    else {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)",
                 "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x18c);
      uVar2 = uVar2 & 0xffffffff;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
             "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x18b);
  return (ulong)uVar1;
}


// ===== 002fb680 confComputeGetKeyRotationStatus_IMPL =====

ulong confComputeGetKeyRotationStatus_IMPL(long param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint local_30;
  uint local_2c [3];
  
  if ((param_2 & 1) == 0) {
    uVar2 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,&local_30);
    param_2 = param_2 & 0xffff0000 | (param_2 & 0xffff) + 1;
  }
  else {
    uVar2 = confComputeGetKeySlotFromGlobalKeyId_IMPL
                      (param_1,(param_2 & 0xffff) - 1 | param_2 & 0xffff0000,&local_30);
  }
  if (uVar2 == 0) {
    uVar3 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_1,param_2,local_2c);
    if ((int)uVar3 == 0) {
      iVar1 = *(int *)(param_1 + 0xa80 + (ulong)local_30 * 4);
      if (iVar1 == *(int *)(param_1 + 0xa80 + (ulong)local_2c[0] * 4)) {
        *param_3 = iVar1;
      }
      else {
        nvAssertFailedNoLog("pConfCompute->keyRotationState[h2dIndex] == pConfCompute->keyRotationState[d2hIndex]"
                            ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x1a5);
        uVar3 = 0x40;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,
                 "confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)",
                 "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x1a4);
      uVar3 = uVar3 & 0xffffffff;
    }
    return uVar3;
  }
  nvAssertOkFailedNoLog
            (uVar2,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
             "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x1a3);
  return (ulong)uVar2;
}


// ===== 002fb7a0 confComputeGetKeyPairByKey_IMPL =====

void confComputeGetKeyPairByKey_IMPL(undefined8 param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  
  if ((param_2 & 1) == 0) {
    uVar1 = (param_2 & 0xffff) + 1 | param_2 & 0xffff0000;
  }
  else {
    uVar1 = param_2;
    param_2 = (param_2 & 0xffff) - 1 | param_2 & 0xffff0000;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = param_2;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar1;
  }
  return;
}


// ===== 002fb7e0 confComputeUpdateFreedChannelStats_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong confComputeUpdateFreedChannelStats_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long *plVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  
  if (*(long *)(param_3 + 0x4d8) == 0) {
    return 0;
  }
  plVar2 = *(long **)(param_3 + 0x4e0);
  if (plVar2 == (long *)0x0) {
    return 0;
  }
  uVar3 = (**(code **)(param_2 + 0x210))();
  uVar4 = 0x1ef;
  pcVar6 = 
  "confComputeGetKeyPairByChannel_HAL(pGpu, pConfCompute, pKernelChannel, &h2dKey, &d2hKey)";
  if ((int)uVar3 == 0) {
    uVar3 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,local_28,&local_20,0x1ef);
    uVar4 = 0x1f0;
    pcVar6 = "confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)";
    if ((int)uVar3 == 0) {
      uVar3 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,local_24,&local_1c,0x1f0);
      if ((int)uVar3 == 0) {
        lVar5 = (ulong)local_20 * 0x10 + param_2;
        plVar1 = (long *)(lVar5 + 0xc48);
        *plVar1 = *plVar1 + plVar2[2];
        plVar1 = (long *)(lVar5 + 0xc50);
        *plVar1 = *plVar1 + *plVar2;
        param_2 = param_2 + (ulong)local_1c * 0x10;
        plVar1 = (long *)(param_2 + 0xc48);
        *plVar1 = *plVar1 + plVar2[3];
        plVar1 = (long *)(param_2 + 0xc50);
        *plVar1 = *plVar1 + plVar2[1];
        return uVar3;
      }
      uVar4 = 0x1f1;
      pcVar6 = "confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)";
    }
  }
  nvAssertOkFailedNoLog
            (uVar3 & 0xffffffff,pcVar6,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",
             uVar4);
  return uVar3 & 0xffffffff;
}


// ===== 002fb910 confComputeSetKeyRotationThreshold_IMPL =====

undefined1  [16] confComputeSetKeyRotationThreshold_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 extraout_RDX;
  undefined1 auVar2 [16];
  
  if (param_2 - 0x32U < 0x10) {
    lVar1 = *(long *)(keyRotationUpperThreshold_5 + (param_2 - 0x32U) * 8);
    *(long *)(param_1 + 0x1c60) = lVar1;
    *(long *)(param_1 + 0x1c68) = lVar1 - *(long *)(param_1 + 0x1c58);
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x221,
                 "confComputeSetKeyRotationThreshold_IMPL",1,
                 "NVRM: Setting key rotation attacker advantage to %llu.\n",param_2);
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x222,
                 "confComputeSetKeyRotationThreshold_IMPL",1,
                 "NVRM: Key rotation lower threshold is %llu and upper threshold is %llu.\n",
                 *(undefined8 *)(param_1 + 0x1c68),*(undefined8 *)(param_1 + 0x1c60));
    return ZEXT816(0x2fb977) << 0x40;
  }
  nvAssertFailedNoLog("(attackerAdvantage >= offset) && (attackerAdvantage <= (offset + NV_ARRAY_ELEMENTS(keyRotationUpperThreshold) - 1))"
                      ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x219);
  auVar2._8_8_ = extraout_RDX;
  auVar2._0_8_ = 0x1f;
  return auVar2;
}


// ===== 002fb9e0 confComputeGetKeyRotationThreshold_IMPL =====

void confComputeGetKeyRotationThreshold_IMPL(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  *param_2 = *(undefined8 *)(param_1 + 0x1c68);
  *param_3 = *(undefined8 *)(param_1 + 0x1c60);
  return;
}


// ===== 002fba00 confComputeIsUpperThresholdCrossed_IMPL =====

undefined8 confComputeIsUpperThresholdCrossed_IMPL(long param_1,ulong *param_2)

{
  ulong uVar1;
  
  uVar1 = (*param_2 >> 4) + param_2[1];
  return CONCAT71((int7)(uVar1 >> 8),*(ulong *)(param_1 + 0x1c60) < uVar1);
}


// ===== 002fba20 confComputeIsLowerThresholdCrossed_IMPL =====

undefined8 confComputeIsLowerThresholdCrossed_IMPL(long param_1,ulong *param_2)

{
  ulong uVar1;
  
  uVar1 = (*param_2 >> 4) + param_2[1];
  return CONCAT71((int7)(uVar1 >> 8),*(ulong *)(param_1 + 0x1c68) < uVar1);
}


// ===== 002fba40 confComputeIsGivenThresholdCrossed_IMPL =====

uint confComputeIsGivenThresholdCrossed_IMPL(long *param_1,ulong param_2,undefined4 param_3)

{
  ulong uVar1;
  undefined3 uVar2;
  
  uVar2 = (undefined3)((uint)param_3 >> 8);
  if ((char)param_3 != '\0') {
    uVar1 = ((ulong)param_1[2] >> 4) + *param_1;
    return (uint)CONCAT71((int7)(uVar1 >> 8),param_2 < uVar1) & CONCAT31(uVar2,param_2 != 0);
  }
  uVar1 = ((ulong)param_1[3] >> 4) + param_1[1];
  return (uint)CONCAT71((int7)(uVar1 >> 8),param_2 < uVar1) & CONCAT31(uVar2,param_2 != 0);
}


// ===== 002fba90 confComputeStopKeyRotationTimer_IMPL =====

ulong confComputeStopKeyRotationTimer_IMPL(long param_1,long param_2,undefined4 param_3)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  uint local_38;
  int local_34;
  undefined8 local_30 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b88);
  uVar3 = confComputeGetKeyRotationStatus_IMPL(param_2,param_3,&local_34);
  if (uVar3 != 0) {
    nvAssertOkFailedNoLog
              (uVar3,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &status)",
               "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x262);
    return (ulong)uVar3;
  }
  if (local_34 == 6) {
    nvCheckFailedNoLog(4,"status != KEY_ROTATION_STATUS_PENDING_TIMER_SUSPENDED",
                       "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x264);
    uVar5 = 0;
  }
  else {
    if (local_34 != 1) {
      nvAssertFailedNoLog("status == KEY_ROTATION_STATUS_PENDING",
                          "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x267);
      return 0x40;
    }
    uVar3 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,&local_38);
    if (uVar3 == 0) {
      if (*(long *)((ulong)local_38 * 0x10 + 0x1368 + param_2) == 0) {
        nvAssertFailedNoLog("(pConfCompute->keyRotationTimeoutInfo[h2dKeyIndex].pTimer != NULL)",
                            "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x269);
        return 0x40;
      }
      cVar2 = tmrEventOnList_IMPL(uVar1);
      if (cVar2 == '\0') {
        lVar4 = (ulong)*(uint *)(param_2 + 0x1c50) * 1000000000;
        *(long *)((ulong)local_38 * 0x10 + 0x1370 + param_2) = lVar4;
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x278,
                     "confComputeStopKeyRotationTimer_IMPL",1,
                     "NVRM: Timeout timer never started on key 0x%x. leave it as is at %lldns\n",
                     param_3,lVar4);
      }
      else {
        uVar3 = tmrEventTimeUntilNextCallback_IMPL
                          (uVar1,*(undefined8 *)((ulong)local_38 * 0x10 + 0x1368 + param_2),local_30
                          );
        if (uVar3 != 0) {
          nvAssertOkFailedNoLog
                    (uVar3,
                     "tmrEventTimeUntilNextCallback(pTmr, pConfCompute->keyRotationTimeoutInfo[h2dKeyIndex].pTimer, &timeNs)"
                     ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x26d);
          return (ulong)uVar3;
        }
        *(undefined8 *)(param_2 + 0x1370 + (ulong)local_38 * 0x10) = local_30[0];
        tmrEventCancel_IMPL(uVar1,*(undefined8 *)(param_2 + 0x1368 + (ulong)local_38 * 0x10));
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x271,
                     "confComputeStopKeyRotationTimer_IMPL",1,
                     "NVRM: Stopped key rotation timeout timer for key 0x%x with time left = %lldns\n"
                     ,param_3,*(undefined8 *)((ulong)local_38 * 0x10 + 0x1370 + param_2));
      }
      uVar5 = confComputeSetKeyRotationStatus_IMPL(param_2,param_3,6);
      if ((int)uVar5 != 0) {
        nvAssertOkFailedNoLog
                  (uVar5 & 0xffffffff,
                   "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_PENDING_TIMER_SUSPENDED)"
                   ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x27b);
        uVar5 = uVar5 & 0xffffffff;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar3,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dKeyIndex)",
                 "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x268);
      uVar5 = (ulong)uVar3;
    }
  }
  return uVar5;
}


// ===== 002fbd40 confComputeStartKeyRotationTimer_IMPL =====

int confComputeStartKeyRotationTimer_IMPL(long param_1,long param_2,undefined4 param_3)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  uint local_30;
  int local_2c;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b88);
  iVar2 = confComputeGetKeyRotationStatus_IMPL(param_2,param_3,&local_2c);
  if (iVar2 == 0) {
    if (local_2c == 6) {
      iVar2 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,&local_30);
      if (iVar2 == 0) {
        lVar3 = (ulong)local_30 * 0x10 + param_2;
        iVar2 = tmrEventScheduleRel_IMPL
                          (uVar1,*(undefined8 *)(lVar3 + 0x1368),
                           (*(ulong *)(lVar3 + 0x1370) / 1000000000) * 1000000000);
        if (iVar2 == 0) {
          iVar2 = confComputeSetKeyRotationStatus_IMPL(param_2,param_3,1);
          if (iVar2 == 0) {
            nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x298,
                         "confComputeStartKeyRotationTimer_IMPL",1,
                         "NVRM: Started key rotation timeout timer for key 0x%x with rel time left = %lldns\n"
                         ,param_3,*(undefined8 *)((ulong)local_30 * 0x10 + 0x1370 + param_2));
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar2,
                       "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_PENDING)"
                       ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x297);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "tmrEventScheduleRelSec(pTmr, pConfCompute->keyRotationTimeoutInfo[h2dKeyIndex].pTimer, pConfCompute->keyRotationTimeoutInfo[h2dKeyIndex].timeLeftNs/(1000 * 1000 * 1000))"
                     ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x294);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar2,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dKeyIndex)",
                   "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x293);
      }
    }
    else {
      iVar2 = 0x40;
      nvAssertFailedNoLog("status == KEY_ROTATION_STATUS_PENDING_TIMER_SUSPENDED",
                          "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x292);
    }
    return iVar2;
  }
  nvAssertOkFailedNoLog
            (iVar2,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &status)",
             "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x291);
  return iVar2;
}


// ===== 002fbf00 confComputeIsUvmKeyRotationPending_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 confComputeIsUvmKeyRotationPending_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_34;
  undefined1 local_30 [4];
  int local_2c [3];
  
  iVar2 = 1;
  while( true ) {
    (**(code **)(param_2 + 0x220))(param_1,param_2,iVar2,1,&local_34,local_30);
    iVar1 = confComputeGetKeyRotationStatus_IMPL(param_2,local_34,local_2c);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"confComputeGetKeyRotationStatus(pConfCompute, kernH2DKey, &kernKRStatus)",
                 "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x2b3);
    }
    if (local_2c[0] == 1) break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 0x12) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x2ba,
                   "confComputeIsUvmKeyRotationPending_IMPL",1,
                   "NVRM: no kernel key rotation pending\n");
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x2b6,
               "confComputeIsUvmKeyRotationPending_IMPL",1,
               "NVRM: Key rotation pending on h2d kern key  = 0x%x\n",local_34);
  return 1;
}


// ===== 002fc000 performKeyRotationByKeyPair =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int performKeyRotationByKeyPair
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  uint local_78;
  uint local_74;
  undefined4 local_70;
  int local_6c;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  iVar4 = (**(code **)(param_2 + 0x1c8))(param_2,param_3);
  if (iVar4 == 0) {
    iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,&local_78);
    if (iVar4 == 0) {
      iVar4 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_4,&local_74);
      if (iVar4 == 0) {
        iVar4 = confComputeInitChannelIterForKey_IMPL(param_1,param_2,param_3,&local_60);
        if (iVar4 == 0) {
          piVar1 = (int *)(param_2 + 0x1a88 + (ulong)local_78 * 4);
          *piVar1 = *piVar1 + 1;
          piVar1 = (int *)(param_2 + 0x1a88 + (ulong)local_74 * 4);
          *piVar1 = *piVar1 + 1;
          while (iVar4 = confComputeGetNextChannelForKey_IMPL
                                   (param_1,param_2,&local_60,param_3,&local_68), iVar4 == 0) {
            cVar3 = kchannelIsDisabledForKeyRotation(param_1,local_68);
            if (cVar3 == '\0') {
              lVar6 = *(long *)(local_68 + 0x4e0);
            }
            else {
              iVar4 = kchannelUpdateNotifierMem_IMPL
                                (local_68,2,*(int *)(param_2 + 0x1a88 + (ulong)local_78 * 4) + -1,0,
                                 0);
              if (iVar4 != 0) {
                nvAssertOkFailedNoLog
                          (iVar4,
                           "kchannelUpdateNotifierMem(pKernelChannel, NV_CHANNELGPFIFO_NOTIFICATION_TYPE_KEY_ROTATION_STATUS, pConfCompute->keyRotationCount[h2dIndex] - 1, 0, (NvU32)KEY_ROTATION_STATUS_IDLE)"
                           ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xac);
              }
              iVar4 = kchannelUpdateNotifierMem_IMPL
                                (local_68,2,*(undefined4 *)(param_2 + 0x1a88 + (ulong)local_78 * 4),
                                 0,0);
              if (iVar4 != 0) {
                nvAssertOkFailedNoLog
                          (iVar4,
                           "kchannelUpdateNotifierMem(pKernelChannel, NV_CHANNELGPFIFO_NOTIFICATION_TYPE_KEY_ROTATION_STATUS, pConfCompute->keyRotationCount[h2dIndex], 0, (NvU32)KEY_ROTATION_STATUS_IDLE)"
                           ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xaf);
              }
              kchannelNotifyEvent_IMPL
                        (local_68,9,*(undefined4 *)(param_2 + 0x1a88 + (ulong)local_78 * 4),0,0,0);
              if (local_68 == 0) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)invalidInstructionException();
                (*pcVar2)();
              }
              nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xb6,
                           "performKeyRotationByKeyPair",0,
                           "NVRM: channel 0x%08x (hChannel 0x%x) was disabled for key rotation, writing notifier with KEY_ROTATION_STATUS_IDLE\n"
                           ,*(int *)(local_68 + 0x2b0) << 0x18 | *(uint *)(local_68 + 0x2b4),
                           *(undefined4 *)(*(long *)(*(long *)(local_68 + 0x140) + 0x48) + 0x10));
              kchannelDisableForKeyRotation(param_1,local_68,0);
              kchannelEnableAfterKeyRotation(param_1,local_68,0);
              lVar6 = *(long *)(local_68 + 0x4e0);
            }
            if (lVar6 != 0) {
              portMemSet(lVar6,0,0x20);
            }
          }
          lVar7 = (ulong)local_78 * 0x10;
          lVar6 = (ulong)local_74 * 0x10;
          *(undefined8 *)(param_2 + 0x318 + lVar7) = 0;
          *(undefined8 *)(param_2 + 800 + lVar7) = 0;
          *(undefined8 *)(param_2 + 0x318 + lVar6) = 0;
          *(undefined8 *)(param_2 + 800 + lVar6) = 0;
          *(undefined8 *)(param_2 + 0xc48 + lVar7) = 0;
          *(undefined8 *)(param_2 + 0xc50 + lVar7) = 0;
          *(undefined8 *)(param_2 + 0xc48 + lVar6) = 0;
          *(undefined8 *)(param_2 + 0xc50 + lVar6) = 0;
          iVar4 = confComputeSetKeyRotationStatus_IMPL(param_2,param_3,0);
          if (iVar4 == 0) {
            cVar3 = (**(code **)(param_2 + 0x208))(param_2,param_3);
            if ((cVar3 != '\0') &&
               (cVar3 = confComputeIsUvmKeyRotationPending_IMPL(param_1,param_2), cVar3 == '\0')) {
              nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xe0,
                           "performKeyRotationByKeyPair",1,
                           "NVRM: No kernel key rotation pending,restarting suspended user key rotation timers\n"
                          );
              iVar8 = 1;
              do {
                (**(code **)(param_2 + 0x220))(param_1,param_2,iVar8,0,&local_70,0);
                iVar5 = confComputeGetKeyRotationStatus_IMPL(param_2,local_70,&local_6c);
                if (iVar5 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar5,
                             "confComputeGetKeyRotationStatus(pConfCompute, userH2DKey, &userKRStatus)"
                             ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xeb);
                  return iVar5;
                }
                if (local_6c == 6) {
                  nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xee,
                               "performKeyRotationByKeyPair",1,
                               "NVRM: Restarting timeout timer for user key 0x%x\n");
                  iVar5 = confComputeStartKeyRotationTimer_IMPL(param_1,param_2,local_70);
                  if (iVar5 != 0) {
                    nvAssertOkFailedNoLog
                              (iVar5,
                               "confComputeStartKeyRotationTimer(pGpu, pConfCompute, userH2DKey)",
                               "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xef);
                    return iVar5;
                  }
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 != 0x12);
            }
            nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xf5,
                         "performKeyRotationByKeyPair",1,
                         "NVRM: Key rotation successful for key IDs 0x%x and 0x%x.\n",param_3,
                         param_4);
            nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xf6,
                         "performKeyRotationByKeyPair",1,
                         "NVRM: This keypair has been rotated %u times.\n",
                         *(undefined4 *)(param_2 + 0x1a88 + (ulong)local_78 * 4));
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,
                       "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_IDLE)"
                       ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xd1);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar4,"confComputeInitChannelIterForKey(pGpu, pConfCompute, h2dKey, &iter)",
                     "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xa3);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, d2hKey, &d2hIndex)",
                   "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xa2);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
                 "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0xa1);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,"confComputeUpdateSecrets_HAL(pConfCompute, h2dKey)",
               "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x9e);
  }
  return iVar4;
}


// ===== 002fc550 performKeyRotation_WORKITEM =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void performKeyRotation_WORKITEM(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  int local_7c;
  uint local_74;
  long local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar7 = gpumgrGetGpu();
  iVar6 = param_2[2];
  uVar1 = *param_2;
  local_70 = 0;
  local_60 = 0;
  uVar2 = param_2[1];
  local_58 = 0;
  lVar3 = *(long *)(lVar7 + 0x1d18);
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_68 = 0;
  if ((iVar6 == 1) || (iVar6 == 6)) {
    local_7c = performKeyRotationByKeyPair(lVar7,lVar3,uVar1,uVar2);
    if (local_7c == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x4d,
                 "performKeyRotation_WORKITEM",4,
                 "NVRM: Failed to perform key rotation with status = 0x%x for h2dKey = 0x%x\n",
                 local_7c,uVar1);
    iVar6 = confComputeSetKeyRotationStatus_IMPL(lVar3,uVar1,5);
    uVar8 = 0x4e;
joined_r0x002fc7da:
    if (iVar6 == 0) goto LAB_002fc603;
  }
  else {
    if (1 < iVar6 - 3U) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x85,
                   "performKeyRotation_WORKITEM",4,"NVRM: Unexpected key rotation status 0x%x\n");
      local_7c = 0x40;
      goto LAB_002fc603;
    }
    iVar6 = confComputeGetKeySlotFromGlobalKeyId_IMPL(lVar3,uVar1,&local_74);
    if (iVar6 != 0) {
      nvAssertFailedNoLog("confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex) == NV_OK"
                          ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x57);
      return;
    }
    iVar6 = confComputeInitChannelIterForKey_IMPL(lVar7,lVar3,uVar1,&local_60);
    if (iVar6 != 0) {
      nvAssertFailedNoLog("confComputeInitChannelIterForKey(pGpu, pConfCompute, h2dKey, &iter) == NV_OK"
                          ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x5a);
      return;
    }
    while (iVar6 = confComputeGetNextChannelForKey_IMPL(lVar7,lVar3,&local_60,uVar1,&local_70),
          iVar6 == 0) {
      cVar5 = kchannelIsDisabledForKeyRotation(lVar7,local_70);
      if (cVar5 == '\0') {
        iVar6 = kchannelUpdateNotifierMem_IMPL
                          (local_70,2,*(undefined4 *)(lVar3 + 0x1a88 + (ulong)local_74 * 4),0,
                           param_2[2]);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,
                     "kchannelUpdateNotifierMem(pKernelChannel, NV_CHANNELGPFIFO_NOTIFICATION_TYPE_KEY_ROTATION_STATUS, pConfCompute->keyRotationCount[h2dIndex], 0, (NvU32)pWorkItemInfo->status)"
                     ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x5f);
        }
        if (local_70 == 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x62,
                     "performKeyRotation_WORKITEM",1,
                     "NVRM: channel 0x%08x (hChannel 0x%x) was NOT disabled for key rotation, writing notifier with val 0x%x\n"
                     ,*(int *)(local_70 + 0x2b0) << 0x18 | *(uint *)(local_70 + 0x2b4),
                     *(undefined4 *)(*(long *)(*(long *)(local_70 + 0x140) + 0x48) + 0x10),
                     param_2[2]);
        kchannelNotifyEvent_IMPL
                  (local_70,9,*(undefined4 *)(lVar3 + 0x1a88 + (ulong)local_74 * 4),
                   *(undefined2 *)(param_2 + 2),0,0);
      }
    }
    local_68 = CONCAT44(uVar1,(undefined4)local_68);
    local_7c = (**(code **)(lVar7 + 0x3b90))
                         (lVar7 + 0x3b58,*(undefined4 *)(lVar7 + 0x3b34),
                          *(undefined4 *)(lVar7 + 0x3b3c),0x20800ae6,&local_68,8);
    if (local_7c != 0) {
      nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x74,
                   "performKeyRotation_WORKITEM",4,
                   "NVRM: Control call to RC non-idle channels failed with status 0x%x, can\'t perform key rotation for h2dKey = 0x%x\n"
                   ,local_7c,uVar1);
      iVar6 = confComputeSetKeyRotationStatus_IMPL(lVar3,uVar1,5);
      uVar8 = 0x76;
      goto joined_r0x002fc7da;
    }
    local_7c = performKeyRotationByKeyPair(lVar7,lVar3,uVar1,uVar2);
    if (local_7c == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x7e,
                 "performKeyRotation_WORKITEM",4,
                 "NVRM: Failed to perform key rotation with status = 0x%x for h2dKey = 0x%x\n",
                 local_7c,uVar1);
    iVar6 = confComputeSetKeyRotationStatus_IMPL(lVar3,uVar1,5);
    if (iVar6 == 0) goto LAB_002fc603;
    uVar8 = 0x7f;
  }
  nvAssertOkFailedNoLog
            (iVar6,
             "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_FAILED_ROTATION)"
             ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",uVar8);
LAB_002fc603:
  nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x8c,
               "performKeyRotation_WORKITEM",4,"NVRM: KR fialed with status 0x%x\n",local_7c);
  return;
}


// ===== 002fc960 confComputePerformKeyRotation_IMPL =====

int confComputePerformKeyRotation_IMPL
              (long param_1,long param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_40;
  uint local_3c [3];
  
  iVar2 = confComputeGetKeyRotationStatus_IMPL(param_2,param_3,&local_40);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &krStatus)",
               "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x144);
    return iVar2;
  }
  if (local_40 == 2) {
    nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x147,
                 "confComputePerformKeyRotation_IMPL",4,
                 "NVRM: Key rotation is already scheduled for key 0x%x\n",param_3);
    return 0;
  }
  puVar3 = (undefined4 *)portMemAllocNonPaged(0xc);
  if (puVar3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pWorkItemInfo != NULL",
                        "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x14d);
    return 0x51;
  }
  *puVar3 = param_3;
  puVar3[2] = local_40;
  puVar3[1] = param_4;
  iVar2 = confComputeSetKeyRotationStatus_IMPL(param_2,param_3,2);
  if (iVar2 == 0) {
    if (local_40 != 3) {
      uVar1 = *(undefined8 *)(param_1 + 0x1b88);
      iVar2 = confComputeGetKeySlotFromGlobalKeyId_IMPL(param_2,param_3,local_3c);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"confComputeGetKeySlotFromGlobalKeyId(pConfCompute, h2dKey, &h2dIndex)",
                   "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x158);
        goto LAB_002fcb4a;
      }
      if (*(long *)(param_2 + 0x1368 + (ulong)local_3c[0] * 0x10) != 0) {
        tmrEventCancel_IMPL(uVar1);
      }
    }
    if (param_5 == '\0') {
      performKeyRotation_WORKITEM(*(undefined4 *)(param_1 + 0x7a4),puVar3);
      portMemFree(puVar3);
      return 0;
    }
    iVar2 = osQueueWorkItem(param_1,performKeyRotation_WORKITEM,puVar3,0x58);
    if (iVar2 == 0) {
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar2,
               "osQueueWorkItem(pGpu, performKeyRotation_WORKITEM, (void *)pWorkItemInfo, (OsQueueWorkItemFlags){ .bLockSema = NV_TRUE, .apiLock = WORKITEM_FLAGS_API_LOCK_READ_WRITE, .bLockGpus = NV_TRUE})"
               ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x162);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,
               "confComputeSetKeyRotationStatus(pConfCompute, h2dKey, KEY_ROTATION_STATUS_IN_PROGRESS)"
               ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x151);
  }
LAB_002fcb4a:
  portMemFree(puVar3);
  return iVar2;
}


// ===== 002fcbb0 confComputeCheckAndPerformKeyRotation_IMPL =====

/* WARNING: Type propagation algorithm not settling */

int confComputeCheckAndPerformKeyRotation_IMPL
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int local_6c;
  long local_68 [7];
  
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[0] = 0;
  iVar3 = confComputeGetKeyRotationStatus_IMPL(param_2,param_3,&local_6c);
  if (iVar3 == 0) {
    if ((local_6c == 1) || (local_6c == 6)) {
      iVar3 = confComputeInitChannelIterForKey_IMPL(param_1,param_2,param_3,local_68 + 1);
      if (iVar3 == 0) {
        do {
          iVar3 = confComputeGetNextChannelForKey_IMPL
                            (param_1,param_2,local_68 + 1,param_3,local_68);
          if (iVar3 != 0) {
            nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x129,
                         "confComputeCheckAndPerformKeyRotation_IMPL",1,
                         "NVRM: scheduling KR for h2d key = 0x%x\n",param_3);
            iVar3 = confComputePerformKeyRotation_IMPL(param_1,param_2,param_3,param_4,0);
            if (iVar3 == 0) {
              return 0;
            }
            nvAssertOkFailedNoLog
                      (iVar3,
                       "confComputePerformKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey, NV_FALSE)"
                       ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x12a);
            return iVar3;
          }
          cVar2 = kchannelIsDisabledForKeyRotation(param_1,local_68[0]);
        } while (cVar2 != '\0');
        if (local_68[0] == 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)invalidInstructionException();
          (*pcVar1)();
        }
        nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x11c,
                     "confComputeCheckAndPerformKeyRotation_IMPL",0,
                     "NVRM: channel 0x%08x (hChannel 0x%x) was NOT disabled for key rotation, can\'t start KR yet\n"
                     ,*(int *)(local_68[0] + 0x2b0) << 0x18 | *(uint *)(local_68[0] + 0x2b4),
                     *(undefined4 *)(*(long *)(*(long *)(local_68[0] + 0x140) + 0x48) + 0x10));
        iVar3 = 0;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar3,"confComputeInitChannelIterForKey(pGpu, pConfCompute, h2dKey, &iter)",
                   "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x116);
      }
    }
    else {
      iVar3 = 0x40;
      nvAssertFailedNoLog("(state == KEY_ROTATION_STATUS_PENDING) || (state == KEY_ROTATION_STATUS_PENDING_TIMER_SUSPENDED)"
                          ,"src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x111);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &state)",
               "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x110);
  }
  return iVar3;
}


// ===== 002fcdd0 confComputeForceKeyRotation_IMPL =====

int confComputeForceKeyRotation_IMPL
              (undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  int local_2c;
  
  lVar3 = resservGetTlsCallContext();
  if (1 < *(uint *)(lVar3 + 0x28)) {
    if (((*(char *)(param_2 + 0x2b0) == '\0') || (*(char *)(param_2 + 0x2b1) == '\0')) ||
       (uVar1 = 1 << ((byte)((uint)param_3 >> 0x10) & 0x1f) | 0x400,
       uVar1 != (*(uint *)(param_2 + 0x304) & uVar1))) {
      iVar2 = 0x56;
    }
    else {
      iVar2 = confComputeGetKeyRotationStatus_IMPL(param_2,param_3,&local_2c);
      if (iVar2 == 0) {
        if (local_2c == 2) {
          nvDbg_Printf("src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x2e8,
                       "confComputeForceKeyRotation_IMPL",1,
                       "NVRM: Key rotation is already scheduled for key 0x%x\n",param_3);
        }
        else {
          iVar2 = performKeyRotationByKeyPair(param_1,param_2,param_3,param_4);
          if (iVar2 != 0) {
            nvAssertOkFailedNoLog
                      (iVar2,"performKeyRotationByKeyPair(pGpu, pConfCompute, h2dKey, d2hKey)",
                       "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x2eb);
          }
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar2,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &krStatus)",
                   "src/kernel/gpu/conf_compute/conf_compute_key_rotation.c",0x2e5);
      }
    }
    return iVar2;
  }
  return 0x1b;
}


// ===== 002fcf30 dbgbufConstruct_IMPL =====

undefined8 dbgbufConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar2 = nvdAllocDebugBuffer_IMPL
                    (lVar1,*(undefined8 *)(lVar1 + 0x1ce0),
                     *(undefined4 *)(*(long *)(param_3 + 0x40) + 4),*(long *)(param_3 + 0x40),
                     local_20);
  if ((int)uVar2 == 0) {
    *(undefined8 *)(param_1 + 0x138) = local_20[0];
    return uVar2;
  }
  nvDbg_Printf("src/kernel/gpu/dbgbuffer.c",0x2e,"dbgbufConstruct_IMPL",4,
               "NVRM: DebugBuffer object could not be allocated.\n");
  return 0x1a;
}


// ===== 002fcfc0 dbgbufDestruct_IMPL =====

void dbgbufDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 local_38 [8];
  long local_30 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar2 = *(undefined8 *)(lVar1 + 0x1ce0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x110),local_38,local_30);
  iVar3 = nvdFreeDebugBuffer_IMPL(lVar1,uVar2,*(undefined8 *)(param_1 + 0x138));
  if (iVar3 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/dbgbuffer.c",0x46);
  }
  *(int *)(local_30[0] + 0x30) = iVar3;
  return;
}


// ===== 002fd050 dbgbufMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void dbgbufMap_IMPL(long param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  undefined1 local_29 [9];
  
  plVar4 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  uVar3 = *(undefined4 *)(param_4 + 0x10);
  uVar1 = (**(code **)(*plVar4 + 0xd8))(plVar4);
  iVar2 = rmapiValidateKernelMapping(uVar1,uVar3,local_29);
  if (iVar2 == 0) {
    uVar3 = osGetCurrentProcess();
    *(undefined4 *)(param_4 + 0x48) = uVar3;
    memdescMap(*(long *)(param_1 + 0x138),0,*(undefined8 *)(*(long *)(param_1 + 0x138) + 0x30),
               local_29[0],*(undefined4 *)(*(long *)(param_4 + 0x50) + 0x20),param_4 + 0x18,
               *(long *)(param_4 + 0x50) + 0x18);
  }
  return;
}


// ===== 002fd0e0 dbgbufUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong dbgbufUnmap_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long *plVar3;
  ulong uVar4;
  undefined1 local_29 [9];
  
  plVar3 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  uVar1 = *(undefined4 *)(param_3 + 0x10);
  uVar2 = (**(code **)(*plVar3 + 0xd8))(plVar3);
  uVar4 = rmapiValidateKernelMapping(uVar2,uVar1,local_29);
  if ((int)uVar4 == 0) {
    memdescUnmap(*(undefined8 *)(param_1 + 0x138),local_29[0],*(undefined8 *)(param_3 + 0x18),
                 *(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18));
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}


// ===== 002fd160 dbgbufGetMapAddrSpace_IMPL =====

ulong dbgbufGetMapAddrSpace_IMPL
                (long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  ulong uVar1;
  undefined4 local_1c [3];
  
  if (*(long *)(param_1 + 0x138) != 0) {
    uVar1 = rmapiGetEffectiveAddrSpace
                      (*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0),*(long *)(param_1 + 0x138)
                       ,param_3,local_1c);
    if ((int)uVar1 == 0) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = local_1c[0];
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,
                 "rmapiGetEffectiveAddrSpace(pGpu, pMemDesc, mapFlags, &addrSpace)",
                 "src/kernel/gpu/dbgbuffer.c",0x94);
      uVar1 = uVar1 & 0xffffffff;
    }
    return uVar1;
  }
  return 0x31;
}


// ===== 002fd1f0 dbgbufGetMemoryMappingDescriptor_IMPL =====

undefined8 dbgbufGetMemoryMappingDescriptor_IMPL(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x138);
  return 0;
}


// ===== 002fd210 dceclientConstructEngine_IMPL =====

undefined8 dceclientConstructEngine_IMPL(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client.c",0x22,"dceclientConstructEngine_IMPL",1,
               "NVRM: dceclientConstructEngine_IMPL Called\n");
  if (*(char *)(param_1 + 0x90a) != '\0') {
    uVar1 = dceclientInitRpcInfra_IMPL(param_1,param_2);
    return uVar1;
  }
  return 0x56;
}


// ===== 002fd270 dceclientDestruct_IMPL =====

void dceclientDestruct_IMPL(undefined8 param_1)

{
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client.c",0x32,"dceclientDestruct_IMPL",1,
               "NVRM: dceclientDestruct_IMPL Called\n");
  dceclientDeinitRpcInfra_IMPL(param_1);
  return;
}


// ===== 002fd2c0 dceclientStateLoad_IMPL =====

undefined8 dceclientStateLoad_IMPL(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  
  if ((param_3 & 4) == 0) {
    return 0;
  }
  uVar1 = dceclientInitRpcInfra_IMPL();
  return uVar1;
}


// ===== 002fd2e0 dceclientStateUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong dceclientStateUnload_IMPL(long param_1,undefined8 param_2,uint param_3)

{
  ulong uVar1;
  undefined1 local_30 [4];
  int local_2c;
  
  nvDbg_Printf("src/kernel/gpu/dce_client/dce_client.c",0x51,"dceclientStateUnload_IMPL",1,
               "NVRM: dceclientStateUnload_IMPL Called\n");
  uVar1 = (ulong)(param_3 & 4);
  if ((param_3 & 4) != 0) {
    portMemSet(local_30,0,8);
    local_30[0] = 1;
    local_2c = (-(uint)((param_3 & 0x10) == 0) & 0xfffffffc) + 7;
    uVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800ae9,local_30,8);
    if ((int)uVar1 == 0) {
      dceclientDeinitRpcInfra_IMPL(param_2);
      return uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}


