// ===== 0033a700 kfifoRunlistAllocBuffers_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoRunlistAllocBuffers_IMPL
              (undefined8 param_1,long param_2,undefined4 param_3,int param_4,undefined4 param_5,
              ulong param_6,undefined4 param_7,undefined8 param_8,long *param_9)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  int iVar5;
  long *plVar6;
  int local_5c;
  undefined4 local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  local_50 = 0;
  local_48 = 0;
  local_5c = kfifoGetRunlistBufInfo_IMPL(param_1,param_2,param_4,param_7,&local_50,&local_48);
  uVar1 = local_48;
  uVar3 = local_50;
  if (local_5c != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0xa7b,"kfifoRunlistAllocBuffers_IMPL",4,
                 "NVRM: failed to get runlist buffer info 0x%08x\n",local_5c);
LAB_0033a8a0:
    plVar6 = param_9 + 2;
    do {
      if (*param_9 != 0) {
        memdescFree();
        memdescDestroy(*param_9);
        *param_9 = 0;
      }
      param_9 = param_9 + 1;
    } while (param_9 != plVar6);
    return local_5c;
  }
  plVar6 = param_9;
LAB_0033a775:
  *plVar6 = 0;
  local_5c = memdescCreate(plVar6,param_1,uVar3,uVar1,1,param_3,param_5,param_6);
  if (local_5c == 0) {
    if ((param_6 & 0x1000000000) == 0) {
LAB_0033a81d:
      *(undefined4 *)(*plVar6 + 0x9c) = 0x86;
      local_5c = memdescAlloc(*plVar6);
      if (local_5c != 0) {
        uVar3 = 0xab4;
        pcVar4 = "NVRM: Runlist buffer mem alloc failed 0x%08x\n";
        iVar5 = local_5c;
        goto LAB_0033a8f6;
      }
      plVar6 = plVar6 + 1;
      if (plVar6 == param_9 + 2) {
        return 0;
      }
      goto LAB_0033a775;
    }
    local_40[0] = 0;
    local_5c = (**(code **)(param_2 + 0x218))(param_1,param_2,3,param_4,2,&local_54);
    if (local_5c == 0) {
      local_5c = ctxBufPoolGetGlobalPool(param_1,1,local_54,local_40);
      if (local_5c == 0) {
        local_5c = memdescSetCtxBufPool(*plVar6,local_40[0]);
        if (local_5c == 0) goto LAB_0033a81d;
        pcVar4 = "NVRM: Failed to set ctx buf pool for runlistId 0x%x\n";
        uVar3 = 0xaa9;
        iVar5 = param_4;
        goto LAB_0033a8f6;
      }
      uVar2 = gpuGetNv2080EngineType_IMPL(local_54);
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0xaa0,"kfifoRunlistAllocBuffers_IMPL",4,
                   "NVRM: Failed to get ctx buf pool for engine type 0x%x (0x%x)\n",uVar2,local_54);
      goto LAB_0033a8a0;
    }
    pcVar4 = "NVRM: Failed to translate runlistId 0x%x to NV2080 engine type\n";
    uVar3 = 0xa98;
    iVar5 = param_4;
  }
  else {
    uVar3 = 0xa89;
    pcVar4 = "NVRM: Runlist buffer memdesc create failed 0x%08x\n";
    iVar5 = local_5c;
  }
LAB_0033a8f6:
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",uVar3,"kfifoRunlistAllocBuffers_IMPL",4,pcVar4,
               iVar5);
  goto LAB_0033a8a0;
}


// ===== 0033a9c0 kfifoGetMaxSubcontextFromGr_KERNEL =====

undefined4 kfifoGetMaxSubcontextFromGr_KERNEL(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x1bc8);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsManager != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xad3);
  }
  else if (*(char *)(lVar1 + 0x438) == '\0') {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                        ,"src/kernel/gpu/fifo/kernel_fifo.c",0xad4);
  }
  else {
    if (*(long *)(lVar1 + 0x430) != 0) {
      return *(undefined4 *)(*(long *)(lVar1 + 0x430) + 0x164);
    }
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                        ,"src/kernel/gpu/fifo/kernel_fifo.c",0xad5);
  }
  return 0;
}


// ===== 0033aa60 kfifoGetDeviceCaps_IMPL =====

void kfifoGetDeviceCaps_IMPL(long param_1,long param_2,byte *param_3,char param_4)

{
  byte bVar1;
  byte local_2a;
  byte local_29;
  
  portMemSet(&local_2a,0,2);
  bVar1 = local_2a | 2;
  local_2a = local_2a | 6;
  if (*(char *)(param_1 + 0x491c) != '\0') {
    local_2a = bVar1;
  }
  if (((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) &&
     (*(char *)(param_1 + 0x4a20) == '\0')) {
    local_2a = local_2a | 0x80;
  }
  if (*(char *)(param_2 + 0x4b9) != '\0') {
    local_2a = local_2a | 0x40;
  }
  if (*(char *)(param_2 + 0x4ba) != '\0') {
    local_29 = local_29 | 1;
  }
  if (*(char *)(param_2 + 0x4b3) != '\0') {
    local_29 = local_29 | 0x20;
  }
  if (*(char *)(param_2 + 0x4b8) != '\0') {
    local_29 = local_29 | 0x40;
  }
  if (param_4 != '\0') {
    *param_3 = *param_3 & (local_2a | 0xf9);
    param_3[1] = local_29 & 0x70 | (local_29 | 0xfe) & param_3[1];
    return;
  }
  portMemCopy(param_3,2,&local_2a,2);
  return;
}


// ===== 0033ab70 kfifoGetUserdBar1MapStartOffset_VF =====

undefined8 kfifoGetUserdBar1MapStartOffset_VF(void)

{
  return 0;
}


// ===== 0033ab80 kfifoAddSchedulingHandler_IMPL =====

undefined8
kfifoAddSchedulingHandler_IMPL
          (undefined8 param_1,long param_2,long param_3,long param_4,long param_5,long param_6)

{
  bool bVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  long local_68;
  long local_60;
  undefined1 local_58;
  long local_50;
  long local_48;
  undefined1 local_40;
  
  if (param_3 == 0 && param_5 == 0) {
    return 0x10006;
  }
  if (param_3 == 0) {
    if (param_5 != 0) {
      plVar2 = (long *)listHead_IMPL(param_2 + 0x480);
      bVar1 = false;
      if (plVar2 != (long *)0x0) goto LAB_0033ac90;
LAB_0033ad03:
      local_40 = 0;
      local_50 = param_5;
      local_48 = param_6;
      lVar3 = listPrependValue_IMPL(param_2 + 0x480,&local_50);
      if (lVar3 == 0) {
        nvAssertFailedNoLog("listPrependValue(&pKernelFifo->preSchedulingDisableHandlerList, &preEntry)"
                            ,"src/kernel/gpu/fifo/kernel_fifo.c",0xba8);
        goto LAB_0033ad88;
      }
    }
LAB_0033ad28:
    uVar4 = 0;
  }
  else {
    lVar3 = param_2 + 0x458;
    plVar2 = (long *)listHead_IMPL(lVar3);
    while (plVar2 != (long *)0x0) {
      if ((*plVar2 == param_3) && (plVar2[1] == param_4)) {
        if (param_5 == 0) {
          return 0x10006;
        }
        plVar2 = (long *)listHead_IMPL(param_2 + 0x480);
        bVar1 = true;
        if (plVar2 != (long *)0x0) goto LAB_0033ac90;
        goto LAB_0033ac27;
      }
      plVar2 = (long *)listNext_IMPL(lVar3);
    }
    if (param_5 == 0) {
      local_58 = 0;
      local_68 = param_3;
      local_60 = param_4;
      lVar3 = listPrependValue_IMPL(lVar3,&local_68);
      if (lVar3 != 0) goto LAB_0033ad28;
    }
    else {
      plVar2 = (long *)listHead_IMPL(param_2 + 0x480);
      bVar1 = false;
      if (plVar2 != (long *)0x0) {
LAB_0033ac90:
        do {
          if ((*plVar2 == param_5) && (plVar2[1] == param_6)) {
            if (param_3 == 0) {
              return 0x10006;
            }
            if (bVar1) {
              return 0x10006;
            }
            goto LAB_0033ac27;
          }
          plVar2 = (long *)listNext_IMPL(param_2 + 0x480);
        } while (plVar2 != (long *)0x0);
        if (param_3 == 0) {
          if (bVar1) {
            return 0x10006;
          }
          goto LAB_0033ad03;
        }
        if (bVar1) {
LAB_0033ac27:
          nvAssertFailedNoLog("!(bPostHandlerAlreadyPresent ^ bPreHandlerAlreadyPresent)",
                              "src/kernel/gpu/fifo/kernel_fifo.c",0xb8f);
          return 0x40;
        }
      }
      local_58 = 0;
      local_68 = param_3;
      local_60 = param_4;
      lVar3 = listPrependValue_IMPL(param_2 + 0x458,&local_68);
      if (lVar3 != 0) goto LAB_0033ad03;
    }
    nvAssertFailedNoLog("listPrependValue(&pKernelFifo->postSchedulingEnableHandlerList, &postEntry)"
                        ,"src/kernel/gpu/fifo/kernel_fifo.c",0xb9e);
LAB_0033ad88:
    uVar4 = 0x51;
  }
  return uVar4;
}


// ===== 0033adf0 kfifoRemoveSchedulingHandler_IMPL =====

void kfifoRemoveSchedulingHandler_IMPL
               (undefined8 param_1,long param_2,long param_3,long param_4,long param_5,long param_6)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  
  lVar1 = param_2 + 0x458;
  plVar2 = (long *)listHead_IMPL(lVar1);
  while (plVar3 = plVar2, plVar3 != (long *)0x0) {
    while ((plVar2 = (long *)listNext_IMPL(lVar1,plVar3), *plVar3 == param_3 &&
           (plVar3[1] == param_4))) {
      listRemove_IMPL(lVar1,plVar3);
      plVar3 = plVar2;
      if (plVar2 == (long *)0x0) goto LAB_0033ae84;
    }
  }
LAB_0033ae84:
  param_2 = param_2 + 0x480;
  plVar2 = (long *)listHead_IMPL(param_2);
  do {
    plVar3 = plVar2;
    if (plVar2 == (long *)0x0) {
      return;
    }
    while ((plVar2 = (long *)listNext_IMPL(param_2,plVar3), *plVar3 == param_5 &&
           (plVar3[1] == param_6))) {
      listRemove_IMPL(param_2,plVar3);
      plVar3 = plVar2;
      if (plVar2 == (long *)0x0) {
        return;
      }
    }
  } while( true );
}


// ===== 0033aef0 kfifoTriggerPostSchedulingEnableCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoTriggerPostSchedulingEnableCallback_IMPL(undefined8 param_1,long param_2)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined8 *puVar6;
  
  bVar2 = true;
  while (puVar6 = (undefined8 *)listHead_IMPL(param_2 + 0x458), puVar6 != (undefined8 *)0x0) {
    bVar4 = false;
    bVar3 = false;
    do {
      pcVar1 = (code *)*puVar6;
      if (pcVar1 == (code *)0x0) {
        nvAssertFailedNoLog("pEntry->pCallback != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xc07);
        return 0x40;
      }
      if (bVar2) {
        *(undefined1 *)(puVar6 + 2) = 0;
        iVar5 = (*pcVar1)(param_1,puVar6[1]);
        if (iVar5 == 0x10005) goto LAB_0033af9d;
LAB_0033af50:
        if (iVar5 != 0) {
          nvAssertFailedNoLog(&DAT_00d20ee3,"src/kernel/gpu/fifo/kernel_fifo.c",0xc26);
          return iVar5;
        }
        *(undefined1 *)(puVar6 + 2) = 1;
        bVar3 = true;
      }
      else if (*(char *)(puVar6 + 2) == '\0') {
        iVar5 = (*pcVar1)(param_1,puVar6[1]);
        if (iVar5 != 0x10005) goto LAB_0033af50;
LAB_0033af9d:
        bVar4 = true;
      }
      puVar6 = (undefined8 *)listNext_IMPL(param_2 + 0x458,puVar6);
    } while (puVar6 != (undefined8 *)0x0);
    if (!bVar3) break;
    bVar2 = false;
    if (!bVar4) {
      return 0;
    }
  }
  nvAssertFailedNoLog("bMadeProgress || status != NV_OK","src/kernel/gpu/fifo/kernel_fifo.c",0xc2c);
  return 0x40;
}


// ===== 0033b040 kfifoTriggerPreSchedulingDisableCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoTriggerPreSchedulingDisableCallback_IMPL(undefined8 param_1,long param_2)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined8 *puVar6;
  
  bVar2 = true;
  while (puVar6 = (undefined8 *)listHead_IMPL(param_2 + 0x480), puVar6 != (undefined8 *)0x0) {
    bVar4 = false;
    bVar3 = false;
    do {
      pcVar1 = (code *)*puVar6;
      if (pcVar1 == (code *)0x0) {
        nvAssertFailedNoLog("pEntry->pCallback != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xc52);
        return 0x40;
      }
      if (bVar2) {
        *(undefined1 *)(puVar6 + 2) = 0;
        iVar5 = (*pcVar1)(param_1,puVar6[1]);
        if (iVar5 == 0x10005) goto LAB_0033b0ed;
LAB_0033b0a0:
        if (iVar5 != 0) {
          nvAssertFailedNoLog(&DAT_00d20ee3,"src/kernel/gpu/fifo/kernel_fifo.c",0xc71);
          return iVar5;
        }
        *(undefined1 *)(puVar6 + 2) = 1;
        bVar3 = true;
      }
      else if (*(char *)(puVar6 + 2) == '\0') {
        iVar5 = (*pcVar1)(param_1,puVar6[1]);
        if (iVar5 != 0x10005) goto LAB_0033b0a0;
LAB_0033b0ed:
        bVar4 = true;
      }
      puVar6 = (undefined8 *)listNext_IMPL(param_2 + 0x480,puVar6);
    } while (puVar6 != (undefined8 *)0x0);
    if (!bVar3) break;
    bVar2 = false;
    if (!bVar4) {
      return 0;
    }
  }
  nvAssertFailedNoLog("bMadeProgress || status != NV_OK","src/kernel/gpu/fifo/kernel_fifo.c",0xc77);
  return 0x40;
}


// ===== 0033b190 kfifoGetVChIdForSChId_FWCLIENT =====

ulong kfifoGetVChIdForSChId_FWCLIENT
                (undefined8 param_1,undefined8 param_2,uint param_3,int param_4,uint param_5,
                uint *param_6)

{
  uint uVar1;
  ulong uVar2;
  long local_10;
  
  local_10 = 0;
  if (param_6 == (uint *)0x0) {
    nvAssertFailedNoLog("pVChid != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xc8f);
  }
  else {
    *param_6 = param_3;
    if (param_4 == 0) {
      nvCheckFailedNoLog(1,"IS_GFID_VF(gfid)","src/kernel/gpu/fifo/kernel_fifo.c",0xc92);
      return 0;
    }
    uVar2 = vgpuGetCallingContextKernelHostVgpuDevice(param_1,&local_10);
    if ((int)uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2 & 0xffffffff,
                 "vgpuGetCallingContextKernelHostVgpuDevice(pGpu, &pKernelHostVgpuDevice)",
                 "src/kernel/gpu/fifo/kernel_fifo.c",0xc93);
      return uVar2 & 0xffffffff;
    }
    if (*(int *)(local_10 + 0x18) == param_4) {
      if (param_5 < 0x54) {
        uVar1 = *(uint *)(local_10 + 0x2c + (ulong)param_5 * 4);
        if (uVar1 != 0) {
          if (param_3 < uVar1) {
            nvAssertFailedNoLog("sChId >= pKernelHostVgpuDevice->chidOffset[engineId]",
                                "src/kernel/gpu/fifo/kernel_fifo.c",0xc99);
            return 0x1f;
          }
          *param_6 = param_3 - uVar1;
          return uVar2;
        }
        nvAssertFailedNoLog("pKernelHostVgpuDevice->chidOffset[engineId] != 0",
                            "src/kernel/gpu/fifo/kernel_fifo.c",0xc97);
      }
      else {
        nvAssertFailedNoLog("engineId < (NV_ARRAY_ELEMENTS(pKernelHostVgpuDevice->chidOffset))",
                            "src/kernel/gpu/fifo/kernel_fifo.c",0xc95);
      }
      return 0x40;
    }
    nvAssertFailedNoLog("pKernelHostVgpuDevice->gfid == gfid","src/kernel/gpu/fifo/kernel_fifo.c",
                        0xc94);
  }
  return 0x1f;
}


// ===== 0033b310 kfifoGetEngineListForRunlist_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGetEngineListForRunlist_IMPL
              (undefined8 param_1,long param_2,int param_3,long param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 local_40;
  int local_3c [3];
  
  iVar2 = (**(code **)(param_2 + 0x240))();
  if (param_4 == 0) {
    nvCheckFailedNoLog(4,"pOutEngineIds != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xce8);
  }
  else {
    if (param_5 != (uint *)0x0) {
      *param_5 = 0;
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0xcec,"kfifoGetEngineListForRunlist_IMPL",1,
                   "NVRM: Engine list for runlistId 0x%x:\n",param_3);
      if (iVar2 == 0) {
        return 0;
      }
      iVar5 = 0;
LAB_0033b3be:
      do {
        iVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,0xf,iVar5,3,local_3c);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, ENGINE_INFO_TYPE_RUNLIST, &thisRunlistId)"
                     ,"src/kernel/gpu/fifo/kernel_fifo.c",0xcf3);
LAB_0033b4ba:
          if (*param_5 == 0) {
            return iVar3;
          }
          portMemSet(param_4,0,(ulong)*param_5 * 4);
          *param_5 = 0;
          return iVar3;
        }
        if (local_3c[0] == param_3) {
          iVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,0xf,iVar5,2,&local_40);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,
                       "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&rmEngineType)"
                       ,"src/kernel/gpu/fifo/kernel_fifo.c",0xcfb);
            goto LAB_0033b4ba;
          }
          uVar1 = *param_5;
          iVar5 = iVar5 + 1;
          *param_5 = uVar1 + 1;
          *(undefined4 *)(param_4 + (ulong)uVar1 * 4) = local_40;
          uVar4 = (**(code **)(param_2 + 0x248))(param_2,2);
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0xd03,"kfifoGetEngineListForRunlist_IMPL"
                       ,1,"NVRM: Engine name: %s\n",uVar4);
          if (iVar5 == iVar2) {
            return 0;
          }
          goto LAB_0033b3be;
        }
        iVar5 = iVar5 + 1;
        if (iVar5 == iVar2) {
          return 0;
        }
      } while( true );
    }
    nvCheckFailedNoLog(4,"pNumEngines != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xce9);
  }
  return 0x1f;
}


// ===== 0033b580 kfifoSetChidOffset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoSetChidOffset_IMPL
              (undefined8 param_1,long param_2,undefined4 *param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,long param_7,long param_8,undefined8 param_9,
              undefined4 param_10,undefined8 param_11)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint local_3c [3];
  
  uVar1 = (**(code **)(param_2 + 0x240))();
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pChidMgr != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xcb8);
  }
  else {
    if (param_7 != 0) {
      puVar3 = (uint *)portMemAllocNonPaged((ulong)uVar1 << 2);
      if (puVar3 == (uint *)0x0) {
        nvAssertFailedNoLog("(pEngineIds != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0xcbc);
        iVar2 = 0x51;
      }
      else {
        portMemSet(puVar3,0,(ulong)uVar1 << 2);
        iVar2 = kfifoGetEngineListForRunlist_IMPL(param_1,param_2,*param_3,puVar3,local_3c);
        if (iVar2 == 0) {
          puVar5 = puVar3;
          if (local_3c[0] != 0) {
            do {
              if (0x52 < *puVar5 - 1) {
                nvAssertFailedNoLog("NV2080_ENGINE_TYPE_IS_VALID(pEngineIds[i])",
                                    "src/kernel/gpu/fifo/kernel_fifo.c",0xcc3);
                iVar2 = 0x40;
                goto LAB_0033b67f;
              }
              *(undefined4 *)(param_7 + (ulong)*puVar5 * 4) = param_4;
              puVar4 = puVar5 + 1;
              *(undefined4 *)(param_8 + (ulong)*puVar5 * 4) = param_5;
              puVar5 = puVar4;
            } while (puVar3 + local_3c[0] != puVar4);
          }
          iVar2 = (**(code **)(param_2 + 0x2d0))
                            (param_1,param_2,param_3,param_4,param_5,param_6,param_9,param_10,
                             param_11);
          if (iVar2 != 0) {
            nvAssertOkFailedNoLog
                      (iVar2,
                       "kfifoProgramChIdTable_HAL(pGpu, pKernelFifo, pChidMgr, offset, numChannels, gfid, pMigDevice, engineFifoListNumEntries, pEngineFifoList)"
                       ,"src/kernel/gpu/fifo/kernel_fifo.c",0xcc8);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "kfifoGetEngineListForRunlist(pGpu, pKernelFifo, pChidMgr->runlistId, pEngineIds, &numEngines)"
                     ,"src/kernel/gpu/fifo/kernel_fifo.c",0xcbf);
        }
LAB_0033b67f:
        portMemFree(puVar3);
      }
      return iVar2;
    }
    nvAssertFailedNoLog("pChidOffset != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xcb9);
  }
  return 0x1f;
}


// ===== 0033b7a0 kfifoChidMgrReserveSystemChids_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int kfifoChidMgrReserveSystemChids_IMPL
              (long param_1,long param_2,long param_3,uint param_4,undefined4 param_5,uint param_6,
              undefined8 param_7,undefined8 param_8,undefined8 param_9,undefined8 param_10,
              undefined4 param_11,undefined8 param_12)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined4 local_4c [2];
  uint local_44;
  ulong local_40 [2];
  
  iVar2 = 0x56;
  if (*(char *)(param_1 + 0x908) == '\0') {
    local_4c[0] = param_5;
    lVar4 = portMemAllocNonPaged(0x18);
    if (lVar4 != 0) {
      portMemSet(lVar4,0,0x18);
      local_40[0] = (ulong)param_4;
      iVar2 = (**(code **)(*(long *)(param_3 + 0x10) + 8))
                        (*(long *)(param_3 + 0x10),0x6669666f,local_4c,&param_8,local_40,1,1,0,lVar4
                         ,_kfifoUserdOwnerComparator);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x45d,"kfifoChidMgrReserveSystemChids_IMPL"
                     ,4,"NVRM: Failed to reserve channel IDs. Status = 0x%x\n",iVar2);
        portMemFree(lVar4);
        return iVar2;
      }
      uVar7 = (ulong)param_6;
      lVar5 = (**(code **)(*(long *)(param_3 + 0x10) + 0x40))
                        (*(long *)(param_3 + 0x10),CONCAT44(param_8._4_4_,(undefined4)param_8),0);
      if (lVar5 == 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x46f,"kfifoChidMgrReserveSystemChids_IMPL"
                     ,4,"NVRM: Could not fetch block from eheap\n");
        iVar2 = 0;
      }
      else {
        *(long *)(lVar5 + 0x80) = lVar4;
        iVar2 = kfifoSetChidOffset_IMPL
                          (param_1,param_2,param_3,(undefined4)param_8,param_4,param_6,param_7,
                           param_9,param_10,param_11,param_12);
        if (iVar2 == 0) {
          lVar5 = *(long *)(param_3 + 0x18);
          uVar6 = portMemAllocNonPaged(0xd8);
          *(undefined8 *)(uVar7 * 8 + lVar5) = uVar6;
          lVar5 = *(long *)(*(long *)(param_3 + 0x18) + uVar7 * 8);
          if (lVar5 != 0) {
            portMemSet(lVar5,0,0xd8);
            constructObjEHeap(*(undefined8 *)(*(long *)(param_3 + 0x18) + uVar7 * 8),
                              CONCAT44(param_8._4_4_,(undefined4)param_8),
                              (ulong)param_4 + CONCAT44(param_8._4_4_,(undefined4)param_8),0,0);
            (**(code **)(param_2 + 0x2a0))(param_2,&local_44,0);
            lVar4 = *(long *)(*(long *)(param_3 + 0x18) + uVar7 * 8);
            pcVar1 = *(code **)(lVar4 + 0x60);
            (*pcVar1)(lVar4,0,0x1000 / (ulong)local_44,pcVar1);
            return 0;
          }
          iVar2 = 0x51;
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x484,
                       "kfifoChidMgrReserveSystemChids_IMPL",4,
                       "NVRM: Error allocating memory for virtual channel ID heap\n");
        }
        else {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x47b,
                       "kfifoChidMgrReserveSystemChids_IMPL",4,
                       "NVRM: Failed to program the CHID table\n");
        }
      }
      portMemFree(*(undefined8 *)(*(long *)(param_3 + 0x18) + uVar7 * 8));
      iVar3 = kfifoSetChidOffset_IMPL
                        (param_1,param_2,param_3,0,0,param_6,param_7,param_9,param_10,param_11,
                         param_12);
      if (iVar3 != 0) {
        nvAssertFailedNoLog("kfifoSetChidOffset(pGpu, pKernelFifo, pChidMgr, 0, 0, gfid, pChidOffset, pChannelCount, pMigDevice, engineFifoListNumEntries, pEngineFifoList) == NV_OK"
                            ,"src/kernel/gpu/fifo/kernel_fifo.c",0x49d);
      }
      iVar3 = (**(code **)(*(long *)(param_3 + 0x10) + 0x10))
                        (*(long *)(param_3 + 0x10),CONCAT44(param_8._4_4_,(undefined4)param_8));
      if (iVar3 != 0) {
        nvAssertFailedNoLog("pChidMgr->pGlobalChIDHeap->eheapFree(pChidMgr->pGlobalChIDHeap, offset) == NV_OK"
                            ,"src/kernel/gpu/fifo/kernel_fifo.c",0x4a0);
      }
      portMemFree(lVar4);
      return iVar2;
    }
    iVar2 = 0x51;
    nvAssertFailedNoLog("(pIsolationID != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0x449);
  }
  return iVar2;
}


// ===== 0033bb30 kfifoChidMgrFreeSystemChids_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoChidMgrFreeSystemChids_IMPL
              (long param_1,undefined8 param_2,long param_3,uint param_4,undefined8 param_5,
              undefined8 param_6,undefined8 param_7,undefined4 param_8,undefined8 param_9)

{
  long lVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  undefined4 local_40;
  undefined4 uStack_3c;
  
  iVar2 = 0x56;
  if (*(char *)(param_1 + 0x908) == '\0') {
    uVar4 = (ulong)param_4;
    lVar1 = *(long *)(*(long *)(param_3 + 0x18) + uVar4 * 8);
    if (lVar1 == 0) {
      iVar2 = 0x40;
      nvAssertFailedNoLog("pChidMgr->ppVirtualChIDHeap[gfid] != NULL",
                          "src/kernel/gpu/fifo/kernel_fifo.c",0x4bd);
    }
    else {
      (**(code **)(lVar1 + 0x38))(lVar1,&local_40);
      iVar2 = _kfifoChidMgrFreeIsolationId_isra_0(*(undefined8 *)(param_3 + 0x10),local_40);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*(long *)(param_3 + 0x10) + 0x10))
                          (*(long *)(param_3 + 0x10),CONCAT44(uStack_3c,local_40));
        if (iVar2 != 0) {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x4d1,"kfifoChidMgrFreeSystemChids_IMPL",
                       4,"NVRM: Failed to free channel IDs. Status = 0x%x\n",iVar2);
        }
        iVar3 = kfifoSetChidOffset_IMPL
                          (param_1,param_2,param_3,0,0,param_4,param_5,param_6,param_7,param_8,
                           param_9);
        if (iVar3 != 0) {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x4e1,"kfifoChidMgrFreeSystemChids_IMPL",
                       4,"NVRM: Failed to program the CHID table\n");
          return iVar3;
        }
        (*(code *)**(undefined8 **)(*(long *)(param_3 + 0x18) + uVar4 * 8))();
        portMemFree(*(undefined8 *)(*(long *)(param_3 + 0x18) + uVar4 * 8));
        *(undefined8 *)(*(long *)(param_3 + 0x18) + uVar4 * 8) = 0;
      }
      else {
        iVar2 = 0x57;
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x4c7,"kfifoChidMgrFreeSystemChids_IMPL",4,
                     "NVRM: Failed to free IsolationId. Status = 0x%x\n",0x57);
      }
    }
  }
  return iVar2;
}


// ===== 0033bd30 kfifoGetAllocatedChannelMask_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kfifoGetAllocatedChannelMask_IMPL
          (undefined8 param_1,long param_2,uint param_3,long param_4,ulong param_5)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  
  if (param_4 == 0) {
    nvAssertFailedNoLog("pBitMask != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xd25);
  }
  portMemSet(param_4,0,param_5);
  if ((param_5 & 3) == 0) {
    if (*(char *)(param_2 + 0x4b0) == '\0') {
      if (param_3 != 0) {
        return 0x5b;
      }
    }
    else {
      uVar2 = (**(code **)(param_2 + 0x250))(param_1,param_2);
      if (uVar2 <= param_3) {
        return 0x5b;
      }
    }
    puVar3 = (undefined4 *)kfifoGetChidMgr_IMPL(param_1,param_2,param_3);
    if (puVar3 != (undefined4 *)0x0) {
      uVar2 = puVar3[8];
      if (uVar2 == 0) {
        uVar2 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar3);
        if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar2)) {
          uVar2 = *(uint *)(param_2 + 0x4c0);
        }
        puVar3[8] = uVar2;
        *(undefined1 *)(param_2 + 0x4bc) = 0;
        uVar2 = puVar3[8];
        if (param_5 < uVar2 + 7 >> 3) {
          return 2;
        }
        if (uVar2 == 0) {
          return 0;
        }
      }
      else if (param_5 < uVar2 + 7 >> 3) {
        return 2;
      }
      uVar6 = 0;
      do {
        lVar4 = kfifoChidMgrGetKernelChannel_IMPL(param_1,param_2,puVar3,uVar6);
        if (lVar4 != 0) {
          puVar1 = (uint *)(param_4 + (uVar6 >> 5) * 4);
          *puVar1 = *puVar1 | 1 << ((byte)uVar6 & 0x1f);
        }
        uVar5 = (int)uVar6 + 1;
        uVar6 = (ulong)uVar5;
      } while (uVar2 != uVar5);
    }
    return 0;
  }
  nvAssertFailedNoLog("bitMaskSize % sizeof(NvU32) == 0","src/kernel/gpu/fifo/kernel_fifo.c",0xd28);
  return 0x1f;
}


// ===== 0033bf00 kfifoGetChannelClassId_IMPL =====

uint kfifoGetChannelClassId_IMPL(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_38;
  undefined1 local_34 [8];
  int local_2c;
  
  iVar2 = gpuGetClassList_IMPL(param_1,&local_38,0,0xf3e15500);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("NV_OK == gpuGetClassList(pGpu, &numClasses, NULL, ENG_KERNEL_FIFO)",
                        "src/kernel/gpu/fifo/kernel_fifo.c",0xd72);
    return 0;
  }
  if (local_38 == 0) {
    nvAssertFailedNoLog("numClasses > 0","src/kernel/gpu/fifo/kernel_fifo.c",0xd73);
    return 0;
  }
  lVar3 = portMemAllocNonPaged((ulong)local_38 << 2);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("(pClassList != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0xd75);
    return 0;
  }
  iVar2 = gpuGetClassList_IMPL(param_1,&local_38,lVar3,0xf3e15500);
  if ((iVar2 == 0) && (local_38 != 0)) {
    lVar4 = 0;
    uVar6 = 0;
    uVar5 = uVar6;
    do {
      iVar2 = *(int *)(lVar3 + lVar4 * 4);
      if (((iVar2 != 0xc572) && (CliGetChannelClassInfo(iVar2,local_34), local_2c == 1)) &&
         (uVar1 = *(uint *)(lVar3 + lVar4 * 4), bVar7 = uVar6 < uVar1, uVar6 = uVar5, bVar7)) {
        uVar6 = uVar1;
        uVar5 = uVar1;
      }
      lVar4 = lVar4 + 1;
    } while ((uint)lVar4 < local_38);
    if (uVar6 != 0) goto LAB_0033bfb6;
  }
  uVar6 = 0;
  nvAssertFailedNoLog("class","src/kernel/gpu/fifo/kernel_fifo.c",0xd86);
LAB_0033bfb6:
  portMemFree(lVar3);
  return uVar6;
}


// ===== 0033c070 kfifoGetMaxSecureChannels_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGetMaxSecureChannels_KERNEL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 local_20;
  
  local_20 = 0;
  cVar1 = gpuIsCCFeatureEnabled_IMPL();
  if ((cVar1 != '\0') &&
     (iVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ad8,&local_20,8), iVar2 != 0)) {
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_FIFO_GET_NUM_SECURE_CHANNELS, &numSecureChannelsParams, sizeof(numSecureChannelsParams))"
               ,"src/kernel/gpu/fifo/kernel_fifo.c",0xe0a);
    return iVar2;
  }
  *(undefined8 *)(param_2 + 0x4a8) = local_20;
  return 0;
}


// ===== 0033c110 kfifoIsMmuFaultEngineIdPbdma_IMPL =====

undefined8 kfifoIsMmuFaultEngineIdPbdma_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_2 + 0x3d8) != 0) {
    uVar1 = bitVectorTest_IMPL(param_2 + 0x388,0x200);
    return uVar1;
  }
  nvAssertFailedNoLog("pEngineInfo != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xe2b);
  return 0;
}


// ===== 0033c150 kfifoGetPbdmaIdFromMmuFaultId_IMPL =====

undefined8
kfifoGetPbdmaIdFromMmuFaultId_IMPL(undefined8 param_1,long param_2,int param_3,int *param_4)

{
  int iVar1;
  
  if (*(long *)(param_2 + 0x3d8) == 0) {
    if (*(char *)(param_2 + 0x4b6) != '\0') {
      nvAssertFailedNoLog("pEngineInfo != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xe45);
      return 0x40;
    }
  }
  else if (*(char *)(param_2 + 0x4b6) != '\0') {
    iVar1 = bitVectorCountTrailingZeros_IMPL(param_2 + 0x388,0x200);
    *param_4 = param_3 - iVar1;
    return 0;
  }
  nvAssertFailedNoLog("pKernelFifo->bIsPbdmaMmuEngineIdContiguous",
                      "src/kernel/gpu/fifo/kernel_fifo.c",0xe44);
  return 0x56;
}


// ===== 0033c1f0 kfifoGetEngineTypeFromPbdmaFaultId_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGetEngineTypeFromPbdmaFaultId_IMPL(long param_1,long param_2,uint param_3,int *param_4)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined4 local_38;
  int local_34;
  uint *local_30;
  
  lVar5 = 0;
  if (*(long *)(param_2 + 0x3d8) != 0) {
    lVar5 = param_2 + 0x380;
  }
  if (*(char *)(param_2 + 0x4b6) == '\0') {
    local_38 = 0;
    iVar3 = (**(code **)(param_2 + 0x318))(param_1,param_2,2,1,&local_30,&local_38);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "kfifoGetEnginePbdmaFaultIds_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)RM_ENGINE_TYPE_GR0, &pPbdmaFaultIds, &numPbdma)"
                 ,"src/kernel/gpu/fifo/kernel_fifo.c",0xe6f);
      return iVar3;
    }
    uVar1 = *local_30;
    iVar3 = (**(code **)(param_2 + 0x1e8))(param_1,param_2,0);
    if ((uVar1 <= param_3) && (param_3 < iVar3 + uVar1)) {
      if ((param_1 != 0) &&
         ((*(long *)(param_1 + 0x1bc0) != 0 &&
          (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar2 != '\0')))) {
        iVar3 = kgrmgrGetGrIdxForVeid_IMPL
                          (param_1,*(undefined8 *)(param_1 + 0x1bc8),param_3 - uVar1,&local_34);
        if (iVar3 == 0) {
          *param_4 = local_34 + 1;
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar3,"kgrmgrGetGrIdxForVeid(pGpu, pKernelGraphicsManager, subctxId, &grIdx)",
                   "src/kernel/gpu/fifo/kernel_fifo.c",0xe80);
        return iVar3;
      }
      *param_4 = 1;
      return 0;
    }
  }
  if (*(uint *)(lVar5 + 0x50) != 0) {
    lVar4 = *(long *)(lVar5 + 0x58);
    lVar5 = (ulong)*(uint *)(lVar5 + 0x50) * 0x60 + lVar4;
    do {
      if ((*(int *)(lVar4 + 0x4c) != 0) &&
         ((param_3 == *(uint *)(lVar4 + 0x44) ||
          ((*(int *)(lVar4 + 0x4c) != 1 && (*(uint *)(lVar4 + 0x48) == param_3)))))) {
        *param_4 = *(int *)(lVar4 + 8);
        return 0;
      }
      lVar4 = lVar4 + 0x60;
    } while (lVar5 != lVar4);
  }
  *param_4 = 0;
  return 0x57;
}


// ===== 0033c3d0 kfifoGenerateWorkSubmitToken_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoGenerateWorkSubmitToken_IMPL(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x228))();
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "kfifoGenerateWorkSubmitTokenHal_HAL(pGpu, pKernelFifo, pKernelChannel, pGeneratedToken, bUsedForHost)"
             ,"src/kernel/gpu/fifo/kernel_fifo.c",0xea6);
  return uVar1 & 0xffffffff;
}


// ===== 0033c420 kfifoPrintFaultingPbdmaEngineName_IMPL =====

char * kfifoPrintFaultingPbdmaEngineName_IMPL(undefined8 param_1,long param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  int local_7c;
  char *local_78 [4];
  char *local_58;
  char *local_50;
  char *local_48;
  char *local_40;
  char *local_38;
  char *local_30;
  
  local_78[0] = "_PBDMA0";
  local_78[1] = "_PBDMA1";
  lVar3 = 0;
  if (*(long *)(param_2 + 0x3d8) != 0) {
    lVar3 = param_2 + 0x380;
  }
  if (*(char *)(param_2 + 0x4b6) == '\0') {
    iVar2 = kfifoGetEngineTypeFromPbdmaFaultId_IMPL();
    if (iVar2 != 0) {
      nvAssertFailedNoLog("kfifoGetEngineTypeFromPbdmaFaultId(pGpu, pKernelFifo, pbdmaFaultId, &rmEngineType) == NV_OK"
                          ,"src/kernel/gpu/fifo/kernel_fifo.c",0xec7);
      return "UNKNOWN";
    }
    if (local_7c - 1U < 8) {
      local_78[2] = "GR_HOST0";
      local_78[3] = "GR_HOST1";
      local_58 = "GR_HOST2";
      local_50 = "GR_HOST3";
      local_48 = "GR_HOST4";
      local_40 = "GR_HOST5";
      local_38 = "GR_HOST6";
      local_30 = "GR_HOST7";
      pcVar1 = local_78[(ulong)(local_7c - 1U) + 2];
      lVar3 = portStringLength(pcVar1);
      portStringCopy(faultingEngineName_0,0x40,pcVar1,lVar3 + 1);
      return faultingEngineName_0;
    }
  }
  if (*(uint *)(lVar3 + 0x50) != 0) {
    lVar4 = 0;
    lVar5 = *(long *)(lVar3 + 0x58);
    do {
      if (*(int *)(lVar5 + 0x4c) != 0) {
        if (*(int *)(lVar5 + 0x44) == param_3) {
          lVar6 = 0;
LAB_0033c569:
          lVar5 = portStringLength(lVar5 + 0x50);
          portStringCopy(faultingEngineName_0,0x40,lVar4 + *(long *)(lVar3 + 0x58) + 0x50,lVar5 + 1)
          ;
          pcVar1 = local_78[lVar6];
          lVar3 = portStringLength(pcVar1);
          portStringCat(faultingEngineName_0,0x40,pcVar1,lVar3 + 1);
          return faultingEngineName_0;
        }
        if ((*(int *)(lVar5 + 0x4c) != 1) && (*(int *)(lVar5 + 0x48) == param_3)) {
          lVar6 = 1;
          goto LAB_0033c569;
        }
      }
      lVar4 = lVar4 + 0x60;
      lVar5 = lVar5 + 0x60;
    } while ((ulong)*(uint *)(lVar3 + 0x50) * 0x60 != lVar4);
  }
  return "UNKNOWN";
}


// ===== 0033c600 kfifoKernelChannelFromInfo_IMPL =====

undefined8
kfifoKernelChannelFromInfo_IMPL(undefined8 param_1,undefined8 param_2,int param_3,int param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == -1) {
    nvAssertFailedNoLog("channelInfo.chid != INVALID_CHID","src/kernel/gpu/fifo/kernel_fifo.c",0xf10
                       );
  }
  else if (param_4 == -1) {
    nvAssertFailedNoLog("channelInfo.tsgInfo.runlistId != INVALID_RUNLIST_ID",
                        "src/kernel/gpu/fifo/kernel_fifo.c",0xf11);
  }
  else {
    lVar1 = kfifoGetChidMgr_IMPL(param_1,param_2,param_4);
    if (lVar1 != 0) {
      uVar2 = kfifoChidMgrGetKernelChannel_IMPL(param_1,param_2,lVar1,param_3);
      return uVar2;
    }
    nvAssertFailedNoLog("pChidMgr != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0xf14);
  }
  return 0;
}


// ===== 0033c6b0 deviceCtrlCmdFifoGetChannelList_IMPL =====

undefined8 deviceCtrlCmdFifoGetChannelList_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long local_40 [2];
  
  if (*param_2 != 0) {
    lVar6 = 0;
    lVar1 = *(long *)(param_2 + 2);
    lVar2 = *(long *)(param_2 + 4);
    lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
    do {
      iVar4 = CliGetKernelChannel(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                                  *(undefined4 *)(lVar1 + lVar6 * 4),local_40);
      uVar5 = 0xffffffff;
      if (iVar4 == 0) {
        uVar5 = *(uint *)(local_40[0] + 0x2b4);
        if ((lVar3 != 0) && (*(char *)(lVar3 + 0x490f) != '\0')) {
          uVar5 = uVar5 | *(int *)(local_40[0] + 0x2b0) << 0x10;
        }
      }
      *(uint *)(lVar2 + lVar6 * 4) = uVar5;
      lVar6 = lVar6 + 1;
    } while ((uint)lVar6 < *param_2);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x42,"deviceCtrlCmdFifoGetChannelList_IMPL",
               4,"NVRM: Invalid Params for command NV0080_CTRL_CMD_FIFO_GET_CHANNELLIST\n");
  return 0x1f;
}


// ===== 0033c7b0 deviceCtrlCmdFifoIdleChannels_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceCtrlCmdFifoIdleChannels_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar5 = resservGetTlsCallContext();
  if (0x1000 < *param_2) {
    return 0x1f;
  }
  puVar2 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
  cVar3 = rmGpuLockIsOwner();
  if (cVar3 == '\0') {
    uVar4 = rmGpuLocksAcquire(0,0x80003);
    uVar6 = (ulong)uVar4;
    if (uVar4 == 0) {
      if (*(char *)(lVar1 + 0x909) == '\0') {
        uVar4 = 0x56;
      }
      else {
        uVar4 = (**(code **)(lVar1 + 0x3b90))
                          (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                           puVar2[6]);
      }
      rmGpuLocksRelease(0,0);
      uVar6 = (ulong)uVar4;
    }
  }
  else {
    uVar6 = 0x56;
    if (*(char *)(lVar1 + 0x909) != '\0') {
      uVar6 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar6;
    }
  }
  return uVar6;
}


// ===== 0033c900 subdeviceCtrlCmdGetPhysicalChannelCount_IMPL =====

undefined8 subdeviceCtrlCmdGetPhysicalChannelCount_IMPL(long param_1,uint *param_2)

{
  undefined8 uVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = gpuGetKernelFifoShared_IMPL(uVar1);
  param_2[0] = 0xffffffff;
  param_2[1] = 0;
  if (*(int *)(lVar5 + 0x370) != 0) {
    uVar6 = 0;
    lVar7 = 0;
    do {
      while (*(long *)(*(long *)(lVar5 + 0x368) + lVar7 * 8) != 0) {
        uVar4 = kfifoChidMgrGetNumChannels_IMPL(uVar1,lVar5);
        if (uVar4 != 0) {
          uVar8 = 0;
          do {
            lVar2 = *(long *)(*(long *)(lVar5 + 0x368) + lVar7 * 8);
            cVar3 = nvBitFieldTest(*(undefined8 *)(lVar2 + 0x28),*(undefined4 *)(lVar2 + 0x30),uVar8
                                  );
            uVar6 = (uVar6 + 1) - (uint)(cVar3 == '\0');
            uVar8 = uVar8 + 1;
          } while (uVar4 != uVar8);
        }
        uVar8 = *param_2;
        if (uVar4 < *param_2) {
          uVar8 = uVar4;
        }
        *param_2 = uVar8;
        uVar4 = param_2[1];
        if (param_2[1] < uVar6) {
          uVar4 = uVar6;
        }
        lVar7 = lVar7 + 1;
        param_2[1] = uVar4;
        if (*(uint *)(lVar5 + 0x370) <= (uint)lVar7) {
          return 0;
        }
      }
      lVar7 = lVar7 + 1;
    } while ((uint)lVar7 < *(uint *)(lVar5 + 0x370));
  }
  return 0;
}


// ===== 0033ca30 subdeviceCtrlCmdFifoGetInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdFifoGetInfo_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  char *pcVar10;
  undefined4 local_4c;
  undefined1 local_48 [4];
  int local_44;
  ulong local_40 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar6 = gpuGetKernelFifoShared_IMPL(lVar1);
  lVar2 = *(long *)(lVar1 + 0x1b78);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0xdd);
    uVar7 = 0x2f;
  }
  else {
    uVar4 = *param_2;
    uVar7 = (ulong)uVar4;
    if (uVar4 < 0x101) {
      if (uVar4 != 0) {
        lVar9 = 0;
        do {
          uVar4 = param_2[lVar9 * 2 + 1];
          if (uVar4 == 5) {
            uVar7 = (**(code **)(lVar6 + 0x180))(lVar6);
            if (uVar7 >> 0x20 != 0) {
              nvAssertFailedNoLog("(NvU64_HI32(timeslice) == 0)",
                                  "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x117);
              goto LAB_0033ccb0;
            }
          }
          else if (uVar4 < 6) {
            if (uVar4 == 2) {
              uVar7 = (**(code **)(lVar6 + 0x208))(lVar6);
            }
            else if (uVar4 < 3) {
              if (uVar4 == 0) {
                uVar7 = (ulong)*(uint *)(lVar2 + 0x498);
              }
              else {
                uVar7 = kfifoGetMaxChannelGroupsInSystem_IMPL(lVar1,lVar6);
              }
            }
            else if (uVar4 == 3) {
              uVar7 = (**(code **)(lVar6 + 0x1e8))(lVar1,lVar6,0);
            }
            else {
              uVar4 = vgpuGetCallingContextGfid(lVar1,&local_44);
              if (uVar4 != 0) {
                uVar8 = 0x105;
                pcVar10 = "vgpuGetCallingContextGfid(pGpu, &gfid)";
                goto LAB_0033cd81;
              }
              cVar3 = hypervisorIsVgxHyper_IMPL();
              if ((cVar3 == '\0') || (local_44 != 0)) {
                return 0x3f;
              }
              uVar7 = (**(code **)(lVar6 + 0x298))(lVar1,lVar6,local_40,local_48);
              if ((int)uVar7 != 0) {
                return uVar7;
              }
              uVar7 = local_40[0] >> 0xc;
            }
          }
          else if (uVar4 == 8) {
            uVar5 = gpuGetRmEngineType_IMPL(param_2[0x201]);
            uVar4 = (**(code **)(lVar6 + 0x218))(lVar1,lVar6,2,uVar5,3,&local_4c);
            if (uVar4 != 0) {
              uVar8 = 0x11f;
LAB_0033cd73:
              pcVar10 = 
              "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, gpuGetRmEngineType(pFifoInfoParams->engineType), ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
              ;
LAB_0033cd81:
              nvAssertOkFailedNoLog(uVar4,pcVar10,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",uVar8);
              return (ulong)uVar4;
            }
            uVar8 = kfifoGetChidMgr_IMPL(lVar1,lVar6,local_4c);
            uVar7 = kfifoChidMgrGetNumChannels_IMPL(lVar1,lVar6,uVar8);
          }
          else if (uVar4 < 9) {
            if (uVar4 == 6) {
              uVar7 = kfifoGetChannelGroupsInUse_IMPL(lVar1,lVar6);
            }
            else {
              uVar7 = (ulong)*(byte *)(lVar6 + 0x4b0);
            }
          }
          else if (uVar4 == 9) {
            uVar5 = gpuGetRmEngineType_IMPL(param_2[0x201]);
            uVar4 = (**(code **)(lVar6 + 0x218))(lVar1,lVar6,2,uVar5,3,&local_4c);
            if (uVar4 != 0) {
              uVar8 = 0x129;
              goto LAB_0033cd73;
            }
            uVar7 = kfifoGetRunlistChannelGroupsInUse_IMPL(lVar1,lVar6,local_4c);
          }
          else {
            if (uVar4 != 10) {
              return 0x1f;
            }
            uVar7 = (**(code **)(lVar6 + 0x1f8))(lVar1,lVar6);
          }
          param_2[lVar9 * 2 + 2] = (uint)uVar7;
          lVar9 = lVar9 + 1;
        } while ((uint)lVar9 < *param_2);
        uVar7 = 0;
      }
    }
    else {
LAB_0033ccb0:
      uVar7 = 0x3a;
    }
  }
  return uVar7;
}


// ===== 0033cdd0 subdeviceCtrlCmdFifoGetAllocatedChannels_IMPL =====

ulong subdeviceCtrlCmdFifoGetAllocatedChannels_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  uVar1 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  uVar2 = kfifoGetAllocatedChannelMask_IMPL
                    (*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),uVar1,*param_2,param_2 + 1,
                     0x200);
  if (((int)uVar2 != 2) && ((int)uVar2 != 0x1f)) {
    return uVar2;
  }
  nvAssertOkFailedNoLog(uVar2 & 0xffffffff,"status","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x15c);
  return 0x56;
}


// ===== 0033ce60 subdeviceCtrlCmdFifoGetUserdLocation_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdFifoGetUserdLocation_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  int local_20;
  int local_1c;
  
  lVar2 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  cVar1 = rmapiLockIsOwner();
  if ((cVar1 == '\0') || (cVar1 = rmGpuLockIsOwner(), cVar1 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x177);
    return 0x2f;
  }
  uVar3 = (**(code **)(lVar2 + 0x2a8))(lVar2,&local_20,&local_1c);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  if (local_20 == 2) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    if (local_20 != 1) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x18c,
                   "subdeviceCtrlCmdFifoGetUserdLocation_IMPL",4,
                   "NVRM: Invalid userdAperture value = 0x%08x\n");
      return 0x40;
    }
  }
  *param_2 = uVar4;
  if (local_1c != 0) {
    if (local_1c == 1) {
      param_2[1] = 1;
      return uVar3;
    }
    if (local_1c != 2) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x19f,
                   "subdeviceCtrlCmdFifoGetUserdLocation_IMPL",4,
                   "NVRM: Invalid userdAttribute value = 0x%08x\n");
      return 0x40;
    }
    param_2[1] = 2;
    return uVar3;
  }
  param_2[1] = 0;
  return 0;
}


// ===== 0033cfc0 subdeviceCtrlCmdFifoGetChannelMemInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdFifoGetChannelMemInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  undefined1 *puVar10;
  long local_b0;
  long local_a8;
  undefined1 local_a0 [24];
  undefined1 local_88 [24];
  undefined1 local_70 [48];
  int local_40;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  puVar3 = *(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
  uVar4 = *puVar3;
  uVar1 = *(undefined4 *)(puVar3[3] + 0x10);
  lVar8 = gpuGetKernelFifoShared_IMPL(uVar2);
  local_a8 = 0;
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x1bf);
    return 0x2f;
  }
  iVar6 = CliGetKernelChannelWithDevice(uVar4,uVar1,*param_2,&local_b0);
  if (iVar6 != 0) {
    return 0x21;
  }
  portMemSet(local_a0,0,0x68);
  iVar6 = (**(code **)(lVar8 + 0x1c0))(uVar2,lVar8,local_b0,1,&local_a8);
  if (iVar6 != 0) {
    return iVar6;
  }
  kfifoFillMemInfo_IMPL(lVar8,local_a8,local_a0);
  local_a8 = 0;
  iVar6 = (**(code **)(lVar8 + 0x1c0))(uVar2,lVar8,local_b0,0,&local_a8);
  if (iVar6 != 0) {
    return iVar6;
  }
  kfifoFillMemInfo_IMPL(lVar8,local_a8,local_88);
  uVar7 = (**(code **)(lVar8 + 0x200))(uVar2,lVar8);
  if (uVar7 < 3) {
    if (uVar7 == 0) goto LAB_0033d1aa;
  }
  else {
    nvAssertFailedNoLog("(runqueues <= NV2080_CTRL_FIFO_GET_CHANNEL_MEM_INFO_MAX_COUNT)",
                        "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x1e6);
  }
  puVar10 = local_70;
  lVar9 = 0;
  do {
    local_a8 = *(long *)(lVar9 * 0x10 +
                         *(long *)(*(long *)(*(long *)(local_b0 + 0x2b8) + 0x138) + 0x160) + 8);
    if (local_a8 != 0) {
      kfifoFillMemInfo_IMPL(lVar8,local_a8,puVar10);
      local_40 = local_40 + 1;
    }
    lVar9 = lVar9 + 1;
    puVar10 = puVar10 + 0x18;
  } while ((uint)lVar9 < uVar7);
LAB_0033d1aa:
  portMemCopy(param_2 + 2,0x68,local_a0,0x68);
  return 0;
}


// ===== 0033d200 subdeviceCtrlCmdFifoUpdateChannelInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int subdeviceCtrlCmdFifoUpdateChannelInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined4 local_44;
  undefined8 local_40;
  long local_38 [2];
  
  lVar6 = resservGetTlsCallContext();
  local_44 = 0;
  puVar2 = *(undefined4 **)(lVar6 + 0x48);
  lVar6 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_38[0] = 0;
  local_38[1] = 0;
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  if ((*(char *)((long)puVar2 + 0x69) == '\0') && (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("pRmCtrlParams->bDeferredApi || rmGpuLockIsOwner()",
                        "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x218);
    return 0x2f;
  }
  iVar4 = serverGetClientUnderLock(g_resServ,*param_2,&local_40);
  uVar8 = 0x21b;
  pcVar7 = "serverGetClientUnderLock(&g_resServ, pChannelInfo->hClient, &pChannelClient)";
  if (iVar4 == 0) {
    iVar4 = CliGetKernelChannel(local_40,param_2[1],local_38,
                                "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x21b);
    if (iVar4 == 0) {
      if (local_38[0] == 0) {
        nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x224)
        ;
        iVar4 = 0x21;
      }
      else {
        iVar4 = 0x1f;
        if (param_2[2] != 0) {
          if ((*(char *)(local_38[0] + 0x398) == '\0') || (*(char *)(lVar6 + 0x909) == '\0')) {
            return 0x56;
          }
          iVar4 = (**(code **)(lVar6 + 0x3b90))
                            (lVar6 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                             puVar2[6]);
          if (iVar4 == 0) {
            (**(code **)(local_38[0] + 0x1d0))(lVar6);
            iVar4 = (**(code **)(local_38[0] + 0x1c8))
                              (lVar6,local_38[0],uVar1,param_2[2],*(undefined8 *)(param_2 + 6),
                               local_38 + 1,&local_44);
            if (iVar4 != 0) {
              if (local_38[0] == 0) {
                uVar5 = 0xffffffff;
              }
              else {
                uVar5 = *(int *)(local_38[0] + 0x2b0) << 0x18 | *(uint *)(local_38[0] + 0x2b4);
              }
              nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x246,
                           "subdeviceCtrlCmdFifoUpdateChannelInfo_IMPL",4,
                           "NVRM: kchannelCreateUserdMemDesc_HALfailed for hClient 0x%x and channel 0x%08x status 0x%x\n"
                           ,uVar1,uVar5,iVar4);
            }
          }
        }
      }
      return iVar4;
    }
    uVar8 = 0x220;
    pcVar7 = "CliGetKernelChannel(pChannelClient, pChannelInfo->hChannel, &pKernelChannel)";
  }
  nvCheckOkFailedNoLog(1,iVar4,pcVar7,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",uVar8);
  return iVar4;
}


// ===== 0033d480 diagapiCtrlCmdFifoGetChannelState_IMPL =====

int diagapiCtrlCmdFifoGetChannelState_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 local_38;
  undefined8 local_30 [2];
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  iVar3 = serverGetClientUnderLock(g_resServ,param_2[1],&local_38);
  if (iVar3 == 0) {
    iVar3 = CliGetKernelChannel(local_38,*param_2,local_30);
    if (iVar3 == 0) {
      iVar3 = kchannelGetChannelPhysicalState_KERNEL(uVar1,local_30[0],param_2);
      if (iVar3 == 0) {
        uVar2 = kchannelIsCpuMapped(uVar1,local_30[0]);
        *(undefined1 *)((long)param_2 + 0xb) = uVar2;
        uVar2 = kchannelIsRunlistSet(uVar1,local_30[0]);
        *(undefined1 *)((long)param_2 + 0xd) = uVar2;
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "kchannelGetChannelPhysicalState(pGpu, pKernelChannel, pChannelStateParams)",
                   "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x266);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "CliGetKernelChannel(pChannelClient, pChannelStateParams->hChannel, &pKernelChannel)"
                 ,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x264);
    }
    return iVar3;
  }
  nvCheckOkFailedNoLog
            (1,iVar3,
             "serverGetClientUnderLock(&g_resServ, pChannelStateParams->hClient, &pChannelClient)",
             "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x260);
  return iVar3;
}


// ===== 0033d5a0 deviceCtrlCmdFifoGetCaps_IMPL =====

undefined8 deviceCtrlCmdFifoGetCaps_IMPL(long param_1,int *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar1 = *(undefined8 *)(param_2 + 2);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*param_2 == 2) {
        lVar4 = gpuGetKernelFifoShared_IMPL(uVar2);
        if (lVar4 != 0) {
          lVar4 = gpuGetKernelFifoShared_IMPL(uVar2);
          uVar5 = 0x3d;
          if (lVar4 != 0) {
            kfifoGetDeviceCaps_IMPL(uVar2,lVar4,uVar1,0);
            uVar5 = 0;
          }
          return uVar5;
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x2a2,"deviceCtrlCmdFifoGetCaps_IMPL",
                     4,"NVRM: size mismatch: client 0x%x rm 0x%x\n",*param_2,2);
      }
      return 0x1f;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x29d);
  return 0x2f;
}


// ===== 0033d6a0 deviceCtrlCmdFifoGetCapsV2_IMPL =====

undefined8 deviceCtrlCmdFifoGetCapsV2_IMPL(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      lVar3 = gpuGetKernelFifoShared_IMPL(uVar1);
      if (lVar3 == 0) {
        uVar4 = 0x1f;
      }
      else {
        lVar3 = gpuGetKernelFifoShared_IMPL(uVar1);
        uVar4 = 0x3d;
        if (lVar3 != 0) {
          kfifoGetDeviceCaps_IMPL(uVar1,lVar3,param_2,0);
          uVar4 = 0;
        }
      }
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/fifo/kernel_fifo_ctrl.c",700);
  return 0x2f;
}


// ===== 0033d740 subdeviceCtrlCmdFifoDisableChannels_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdFifoDisableChannels_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = resservGetTlsCallContext();
  if ((*(long *)(param_2 + 0x10) != 0) && (*(uint *)(lVar3 + 0x28) < 2)) {
    return 0x1b;
  }
  if ((*(char *)(lVar1 + 0x908) == '\0') && (*(char *)(lVar1 + 0x909) == '\0')) {
    uVar4 = 0x56;
  }
  else {
    puVar2 = *(undefined4 **)(lVar3 + 0x48);
    lVar3 = gpuGetRpc(lVar1);
    if (lVar3 != 0) {
      if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
        uVar4 = rpcDmaControl_wrapper
                          (lVar1,lVar3,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                           puVar2[6]);
        return uVar4;
      }
      uVar4 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
      return uVar4;
    }
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x2db);
    uVar4 = 0x1a;
  }
  return uVar4;
}


// ===== 0033d880 subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_IMPL(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = gpuGetKernelFifoShared_IMPL(uVar1);
  lVar5 = resservGetTlsCallContext();
  if (*param_2 < 0x41) {
    uVar2 = *(undefined8 *)(lVar5 + 0x48);
    lVar5 = portMemAllocNonPaged(0x218);
    if (lVar5 == 0) {
      uVar3 = 0x51;
      nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x307);
    }
    else {
      portMemSet(lVar5,0,0x218);
      uVar7 = 0;
      if (*param_2 != 0) {
        lVar6 = 0;
        do {
          *(uint *)(lVar5 + 0x18 + lVar6 * 4) = param_2[lVar6 + 1];
          *(uint *)(lVar5 + 0x118 + lVar6 * 4) = param_2[lVar6 + 0x41];
          uVar7 = *param_2;
          lVar6 = lVar6 + 1;
        } while ((uint)lVar6 < uVar7);
      }
      *(uint *)(lVar5 + 4) = uVar7;
      uVar3 = (**(code **)(lVar4 + 0x2d8))(uVar1,lVar4,uVar2,(char)param_2[0x81],0,lVar5);
      portMemFree(lVar5);
    }
    return uVar3;
  }
  nvCheckFailedNoLog(1,
                     "pDisableChannelParams->numChannels <= NV_ARRAY_ELEMENTS(pDisableChannelParams->hChannelList)"
                     ,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x2ff);
  return 0x1f;
}


// ===== 0033d9e0 subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_IMPL(long param_1,uint *param_2)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = gpuGetKernelFifoShared_IMPL(uVar1);
  lVar5 = resservGetTlsCallContext();
  if (*param_2 < 0x41) {
    puVar2 = *(undefined4 **)(lVar5 + 0x48);
    lVar5 = portMemAllocNonPaged(0x218);
    if (lVar5 == 0) {
      uVar3 = 0x51;
      nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x32f);
    }
    else {
      portMemSet(lVar5,0,0x218);
      uVar7 = 0;
      if (*param_2 != 0) {
        lVar6 = 0;
        do {
          *(undefined4 *)(lVar5 + 0x18 + lVar6 * 4) = *puVar2;
          *(uint *)(lVar5 + 0x118 + lVar6 * 4) = param_2[lVar6 + 1];
          uVar7 = *param_2;
          lVar6 = lVar6 + 1;
        } while ((uint)lVar6 < uVar7);
      }
      *(uint *)(lVar5 + 4) = uVar7;
      uVar3 = (**(code **)(lVar4 + 0x2d8))(uVar1,lVar4,puVar2,(char)param_2[0x41],1,lVar5);
      portMemFree(lVar5);
    }
  }
  else {
    nvCheckFailedNoLog(1,
                       "pDisableChannelParams->numChannels <= NV_ARRAY_ELEMENTS(pDisableChannelParams->hChannelList)"
                       ,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x329);
    uVar3 = 0x1f;
  }
  return uVar3;
}


// ===== 0033db40 subdeviceCtrlCmdFifoRotateKeys_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdFifoRotateKeys_IMPL(long param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  
  lVar3 = resservGetTlsCallContext();
  puVar1 = *(undefined4 **)(lVar3 + 0x48);
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = gpuGetKernelFifoShared_IMPL(lVar3);
  if (*param_2 < 0x41) {
    uVar7 = (**(code **)(lVar3 + 0x3b90))
                      (lVar3 + 0x3b58,*puVar1,puVar1[1],0x20800b07,*(undefined8 *)(puVar1 + 4),
                       puVar1[6]);
    if ((int)uVar7 == 0) {
      lVar5 = portMemAllocNonPaged(0x218);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x369);
        uVar7 = 0x51;
      }
      else {
        portMemSet(lVar5,0,0x218);
        uVar2 = 0;
        if (*param_2 != 0) {
          lVar6 = 0;
          do {
            *(uint *)(lVar5 + 0x18 + lVar6 * 4) = param_2[lVar6 + 1];
            *(uint *)(lVar5 + 0x118 + lVar6 * 4) = param_2[lVar6 + 0x41];
            uVar2 = *param_2;
            lVar6 = lVar6 + 1;
          } while ((uint)lVar6 < uVar2);
        }
        *(uint *)(lVar5 + 4) = uVar2;
        uVar2 = (**(code **)(lVar4 + 0x2d8))(lVar3,lVar4,puVar1,(char)param_2[0x81],1,lVar5);
        portMemFree(lVar5);
        uVar7 = (ulong)uVar2;
      }
    }
  }
  else {
    nvCheckFailedNoLog(1,
                       "pRotateKeyParams->numChannels <= NV_ARRAY_ELEMENTS(pRotateKeyParams->hChannelList)"
                       ,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x354);
    uVar7 = 0x1f;
  }
  return uVar7;
}


// ===== 0033dd00 subdeviceCtrlCmdFifoGetDeviceInfoTable_VF =====

undefined8 subdeviceCtrlCmdFifoGetDeviceInfoTable_VF(long param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x387);
    return 0x40;
  }
  if (*param_2 < 0x100) {
    lVar4 = (ulong)(*param_2 >> 5) * 0xc8c;
    lVar1 = lVar3 + lVar4;
    uVar2 = *(uint *)(lVar1 + 0x410);
    param_2[1] = uVar2;
    if (uVar2 < 0x21) {
      *(undefined1 *)(param_2 + 2) = *(undefined1 *)(lVar1 + 0x414);
      portMemCopy(param_2 + 3,(ulong)uVar2 * 100,lVar3 + 0x418 + lVar4,(ulong)uVar2 * 100);
      return 0;
    }
  }
  return 0x1f;
}


// ===== 0033ddc0 deviceCtrlCmdFifoGetLatencyBufferSize_VF =====

undefined8 deviceCtrlCmdFifoGetLatencyBufferSize_VF(long param_1,int *param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  int *piVar4;
  
  lVar2 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0));
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x3a9);
    return 0x40;
  }
  piVar4 = (int *)(lVar2 + 0x88f0);
  uVar3 = 0;
  do {
    if (*param_2 == *piVar4) {
      param_2[1] = *(int *)(lVar2 + 0x88f4 + uVar3 * 0xc);
      param_2[2] = *(int *)(lVar2 + 0x88f8 + uVar3 * 0xc);
      return 0;
    }
    uVar1 = (int)uVar3 + 1;
    uVar3 = (ulong)uVar1;
    piVar4 = piVar4 + 3;
  } while (uVar1 != 0x34);
  nvAssertFailedNoLog("i < NV2080_ENGINE_TYPE_LAST_v1C_09","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",
                      0x3b5);
  return 0x1f;
}


// ===== 0033de80 deviceCtrlCmdFifoGetEngineContextProperties_VF =====

undefined8 deviceCtrlCmdFifoGetEngineContextProperties_VF(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = gpuGetStaticInfo(lVar3);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x3c5);
    return 0x40;
  }
  if (*(char *)(lVar3 + 0x4a23) != '\0') {
    param_2[1] = 0;
    param_2[2] = 0;
    if ((0x200f901UL >> (ulong)(*param_2 & 0x1f) & 1) != 0) {
      lVar3 = (ulong)(*param_2 & 0x1f) + 0x16f2;
      param_2[2] = *(uint *)(lVar2 + 0xc + lVar3 * 8);
      uVar1 = *(uint *)(lVar2 + 0x10 + lVar3 * 8);
      if (uVar1 < 0x1000) {
        uVar1 = 0x1000;
      }
      param_2[1] = uVar1;
      return 0;
    }
  }
  return 0x56;
}


// ===== 0033df40 subdeviceCtrlCmdFifoQueryChannelUniqueId_IMPL =====

int subdeviceCtrlCmdFifoQueryChannelUniqueId_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_38;
  long local_30 [2];
  
  local_38 = 0;
  local_30[0] = 0;
  if (0x7f < *(int *)(param_2 + 0x400) - 1U) {
    nvCheckFailedNoLog(1,
                       "(pGetChannelUidParams->numChannels > 0 && pGetChannelUidParams->numChannels <= NV2080_CTRL_CMD_FIFO_MAX_CHANNELS_PER_TSG)"
                       ,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x3f8);
    return 0x3b;
  }
  lVar5 = 0;
  do {
    iVar1 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(param_2 + lVar5 * 4),&local_38);
    if (iVar1 != 0) {
      uVar4 = 0x3ff;
      pcVar3 = "serverGetClientUnderLock(&g_resServ, pGetChannelUidParams->hClients[i], &pRsClient)"
      ;
LAB_0033e014:
      nvCheckOkFailedNoLog(1,iVar1,pcVar3,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",uVar4);
      return iVar1;
    }
    iVar1 = clientGetResourceRefByType_IMPL
                      (local_38,*(undefined4 *)(param_2 + 0x200 + lVar5 * 4),0x5d8d70,local_30);
    if (iVar1 != 0) {
      uVar4 = 0x402;
      pcVar3 = 
      "clientGetResourceRefByType(pRsClient, pGetChannelUidParams->hChannels[i], classId(KernelChannel), &pResourceRef)"
      ;
      goto LAB_0033e014;
    }
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_KernelChannel);
    *(undefined4 *)(param_2 + 0x404 + lVar5 * 4) = *(undefined4 *)(lVar2 + 0x414);
    lVar5 = lVar5 + 1;
    if (*(uint *)(param_2 + 0x400) <= (uint)lVar5) {
      return 0;
    }
  } while( true );
}


// ===== 0033e080 subdeviceCtrlCmdFifoGetChannelGroupUniqueIdInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int subdeviceCtrlCmdFifoGetChannelGroupUniqueIdInfo_IMPL(long param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  long *plVar6;
  undefined8 local_38;
  long local_30 [2];
  
  local_38 = 0;
  local_30[0] = 0;
  iVar1 = serverGetClientUnderLock(g_resServ,*param_2,&local_38);
  if (iVar1 != 0) {
    nvCheckOkFailedNoLog
              (1,iVar1,"serverGetClientUnderLock(&g_resServ, pGetCidGrpParams->hClient, &pRsClient)"
               ,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x419);
    return iVar1;
  }
  iVar1 = clientGetResourceRefByType_IMPL(local_38,param_2[1],0x2b5b80);
  if (iVar1 != 0) {
    iVar1 = clientGetResourceRefByType_IMPL(local_38,param_2[1],0x5d8d70,local_30);
    if (iVar1 == 0) {
      lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_KernelChannel);
      *(undefined8 *)(param_2 + 2) = 0x100000000;
      param_2[4] = *(undefined4 *)(lVar3 + 0x414);
      param_2[0x104] = *(undefined4 *)(lVar3 + 0x40c);
      param_2[0x84] = *(undefined4 *)(*(long *)(lVar3 + 0x2a0) + 0x70);
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar1,
                 "clientGetResourceRefByType(pRsClient, pGetCidGrpParams->hChannelOrTsg, classId(KernelChannel), &pResourceRef)"
                 ,"src/kernel/gpu/fifo/kernel_fifo_ctrl.c",0x422);
    }
    return iVar1;
  }
  lVar3 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  uVar2 = (**(code **)(lVar3 + 0x208))(lVar3);
  lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_KernelChannelGroupApi
                            );
  uVar4 = 0;
  plVar6 = (long *)**(long **)(*(long *)(lVar3 + 0x138) + 0x140);
  param_2[2] = *(undefined4 *)(*(long *)(lVar3 + 0x138) + 500);
  uVar5 = uVar4;
  if ((uVar2 != 0) && (uVar5 = 0, plVar6 != (long *)0x0)) {
    do {
      lVar3 = *plVar6;
      if (lVar3 != 0) {
        param_2[(ulong)uVar4 + 4] = *(undefined4 *)(lVar3 + 0x414);
        param_2[(ulong)uVar4 + 0x104] = *(undefined4 *)(lVar3 + 0x40c);
        param_2[(ulong)uVar4 + 0x84] = *(undefined4 *)(*(long *)(lVar3 + 0x2a0) + 0x70);
        uVar4 = uVar4 + 1;
      }
      plVar6 = (long *)plVar6[1];
      uVar5 = uVar4;
    } while ((plVar6 != (long *)0x0) && (uVar4 < uVar2));
  }
  param_2[3] = uVar5;
  return 0;
}


// ===== 0033e2a0 kfifoConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  char *pcVar5;
  int local_1c;
  
  *(undefined1 *)(param_2 + 0x4bc) = 0;
  iVar1 = osReadRegistryDword(param_1,"RmNumFifos",param_2 + 0x4c0);
  if (iVar1 == 0) {
    *(undefined1 *)(param_2 + 0x4bc) = 1;
  }
  *(undefined1 *)(param_2 + 0x4bb) = 0;
  if (*(char *)(param_2 + 0x4b1) != '\0') {
    iVar1 = osReadRegistryDword(param_1,"RMDebugOverridePerRunlistChannelRam",&local_1c);
    if (iVar1 == 0) {
      pcVar5 = "Enabling";
      if (local_1c == 0) {
        pcVar5 = "Disabling";
      }
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_init.c",0x93,
                   "_kfifoPreConstructRegistryOverrides",1,"NVRM: %s per runlist channel RAM\n",
                   pcVar5);
      *(undefined1 *)(param_2 + 0x4bb) = 1;
      *(bool *)(param_2 + 0x4b0) = local_1c != 0;
    }
  }
  iVar1 = osReadRegistryDword(param_1,"RMSupportUserdMapDma",&local_1c);
  if ((iVar1 == 0) && (local_1c != 0)) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_init.c",0x9d,"_kfifoPreConstructRegistryOverrides"
                 ,4,"NVRM: Enabling MapMemoryDma of USERD\n");
    *(undefined1 *)(param_2 + 0x4ba) = 1;
  }
  portMemSet(param_2 + 0x380,0,0x60);
  portMemSet(param_2 + 0x3e0,0,0x70);
  puVar2 = (undefined8 *)(param_2 + 0x4f8);
  do {
    *puVar2 = 0;
    puVar3 = puVar2 + 2;
    puVar2[1] = 0;
    puVar2 = puVar3;
  } while (puVar3 != (undefined8 *)(param_2 + 0x798));
  *(undefined8 *)(param_2 + 0x4d8) = 0;
  *(undefined8 *)(param_2 + 0x798) = 0;
  iVar1 = (**(code **)(param_2 + 0x168))(param_1,param_2);
  if (iVar1 == 0) {
    uVar4 = portMemAllocatorGetGlobalNonPaged();
    listInit_IMPL(param_2 + 0x458,uVar4,0x18);
    uVar4 = portMemAllocatorGetGlobalNonPaged();
    listInit_IMPL(param_2 + 0x480,uVar4,0x18);
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"kfifoConstructHal_HAL(pGpu, pKernelFifo)",
             "src/kernel/gpu/fifo/kernel_fifo_init.c",0x3d);
  return iVar1;
}


// ===== 0033e4b0 kfifoStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoStateLoad_IMPL(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  undefined1 local_9;
  
  if ((((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) ||
      ((param_3 & 1) == 0)) &&
     ((uVar2 = 0, *(char *)(param_1 + 0x909) == '\0' ||
      (uVar2 = (ulong)(param_3 & 4), (param_3 & 4) == 0)))) {
    return uVar2;
  }
  local_9 = 0;
  lVar1 = gpuGetRpc();
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_fifo_init.c",0x57);
    uVar2 = 0x1a;
  }
  else {
    if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
      uVar2 = rpcDmaControl_wrapper
                        (param_1,lVar1,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ac3,&local_9,1);
    }
    else {
      uVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ac3,&local_9,1);
    }
    if ((int)uVar2 == 0) {
      return uVar2;
    }
  }
  nvCheckOkFailedNoLog(4,uVar2 & 0xffffffff,"status","src/kernel/gpu/fifo/kernel_fifo_init.c",0x5b);
  return uVar2 & 0xffffffff;
}


// ===== 0033e5c0 kfifoStateUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoStateUnload_IMPL(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  undefined1 local_9;
  
  if ((((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) ||
      ((param_3 & 1) == 0)) &&
     ((uVar2 = 0, *(char *)(param_1 + 0x909) == '\0' ||
      (uVar2 = (ulong)(param_3 & 4), (param_3 & 4) == 0)))) {
    return uVar2;
  }
  local_9 = 1;
  lVar1 = gpuGetRpc();
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_fifo_init.c",0x71);
    uVar2 = 0x1a;
  }
  else {
    if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
      uVar2 = rpcDmaControl_wrapper
                        (param_1,lVar1,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ac3,&local_9,1);
    }
    else {
      uVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ac3,&local_9,1);
    }
    if ((int)uVar2 == 0) {
      return uVar2;
    }
  }
  nvCheckOkFailedNoLog(4,uVar2 & 0xffffffff,"status","src/kernel/gpu/fifo/kernel_fifo_init.c",0x75);
  return uVar2 & 0xffffffff;
}


// ===== 0033e6d0 kfifoDestruct_IMPL =====

void kfifoDestruct_IMPL(long param_1)

{
  listDestroy_IMPL(param_1 + 0x458);
  listDestroy_IMPL(param_1 + 0x480);
  if (*(long *)(param_1 + 0x7a0) != 0) {
    portSyncSpinlockDestroy();
    *(undefined8 *)(param_1 + 0x7a0) = 0;
  }
  portMemFree(*(undefined8 *)(param_1 + 0x3d8));
  *(undefined8 *)(param_1 + 0x3d8) = 0;
  return;
}


// ===== 0033e740 kfifoStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoStateInitLocked_IMPL(long param_1,long param_2)

{
  char cVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  char *pcVar6;
  
  lVar2 = *(long *)(param_1 + 0x1c18);
  if ((*(char *)(param_2 + 0x4b1) != '\0') && (*(char *)(param_2 + 0x4bb) == '\0')) {
    if (*(char *)(param_1 + 0x4913) == '\0') {
      if (*(char *)(param_1 + 0x491d) != '\0') {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_init.c",0xdb,"kfifoStateInitLocked_IMPL",1,
                     "NVRM: Enabling per runlist channel RAM on host RM\n");
        *(undefined1 *)(param_2 + 0x4b0) = 1;
      }
    }
    else {
      lVar5 = gpuGetStaticInfo();
      pcVar6 = "Enabling";
      cVar1 = *(char *)(lVar5 + 0xa7a0);
      *(char *)(param_2 + 0x4b0) = cVar1;
      if (cVar1 == '\0') {
        pcVar6 = "Disabling";
      }
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo_init.c",0xd4,"kfifoStateInitLocked_IMPL",1,
                   "NVRM: %s per runlist channel RAM in guest RM\n",pcVar6);
    }
  }
  uVar3 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
  if (uVar3 == 0) {
    uVar3 = kfifoChidMgrConstruct_IMPL(param_1,param_2);
    if (uVar3 == 0) {
      if (lVar2 != 0) {
        krcInitRegistryOverridesDelayed_IMPL(param_1,lVar2);
      }
      uVar4 = kfifoGetMaxSecureChannels_KERNEL(param_1,param_2);
      if ((int)uVar4 != 0) {
        nvAssertOkFailedNoLog
                  (uVar4 & 0xffffffff,"kfifoGetMaxSecureChannels(pGpu, pKernelFifo)",
                   "src/kernel/gpu/fifo/kernel_fifo_init.c",0xeb);
        uVar4 = uVar4 & 0xffffffff;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar3,"kfifoChidMgrConstruct(pGpu, pKernelFifo)",
                 "src/kernel/gpu/fifo/kernel_fifo_init.c",0xe3);
      uVar4 = (ulong)uVar3;
    }
    return uVar4;
  }
  nvAssertOkFailedNoLog
            (uVar3,"kfifoConstructUsermodeMemdescs_HAL(pGpu, pKernelFifo)",
             "src/kernel/gpu/fifo/kernel_fifo_init.c",0xe1);
  return (ulong)uVar3;
}


// ===== 0033e8f0 kfifoStateDestroy_IMPL =====

void kfifoStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  long local_60;
  long local_58;
  undefined1 local_50 [48];
  
  kfifoGetChannelIterator_IMPL(param_1,param_2,local_50,0xffffffff);
  while( true ) {
    iVar1 = kfifoGetNextKernelChannel_IMPL(param_1,param_2,local_50,&local_60);
    if (iVar1 != 0) break;
    uVar2 = *(int *)(local_60 + 0x42c) - 1;
    if (uVar2 < 8) {
      local_58 = 0;
      iVar1 = kchangrpGetEngineContextMemDesc_IMPL
                        (param_1,*(undefined8 *)(*(long *)(local_60 + 0x2b8) + 0x138),&local_58);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,
                   "kchangrpGetEngineContextMemDesc(pGpu, pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup, &grCtxBufferMemDesc)"
                   ,"src/kernel/gpu/fifo/kernel_fifo_init.c",0x109);
      }
      if (local_58 != 0) {
        memdescFree();
        uVar2 = uVar2 | 0xd334df00;
        memdescDestroy(local_58);
        iVar1 = kchannelUnmapEngineCtxBuf_IMPL(param_1,local_60,uVar2);
        if (iVar1 != 0) {
          nvAssertOkFailedNoLog
                    (iVar1,"kchannelUnmapEngineCtxBuf(pGpu, pKernelChannel, ENG_GR(grIdx))",
                     "src/kernel/gpu/fifo/kernel_fifo_init.c",0x114);
        }
        iVar1 = kchannelSetEngineContextMemDesc_IMPL(param_1,local_60,uVar2,0);
        if (iVar1 != 0) {
          nvAssertOkFailedNoLog
                    (iVar1,
                     "kchannelSetEngineContextMemDesc(pGpu, pKernelChannel, ENG_GR(grIdx), NULL)",
                     "src/kernel/gpu/fifo/kernel_fifo_init.c",0x116);
        }
      }
    }
  }
  iVar1 = kfifoTriggerPreSchedulingDisableCallback_IMPL(param_1,param_2);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"kfifoTriggerPreSchedulingDisableCallback(pGpu, pKernelFifo)",
               "src/kernel/gpu/fifo/kernel_fifo_init.c",0x120);
  }
  kfifoChidMgrDestruct_IMPL(param_2);
  memdescDestroy(*(undefined8 *)(param_2 + 0x4f0));
  memdescDestroy(*(undefined8 *)(param_2 + 0x4e0));
  memdescDestroy(*(undefined8 *)(param_2 + 0x4e8));
  return;
}


// ===== 0033ea8e RmIdleChannels.cold =====

void RmIdleChannels_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0033eaa0 RmIdleChannels =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int RmIdleChannels(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined8 param_5
                  ,undefined8 param_6,undefined8 param_7,uint param_8,undefined4 param_9,
                  undefined1 param_10)

{
  bool bVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  undefined4 local_174;
  undefined4 local_170;
  int local_16c [4];
  uint local_15c;
  int *local_158;
  undefined4 *local_150;
  undefined4 *local_148;
  undefined8 local_140;
  long local_138;
  undefined8 local_130;
  int **local_128;
  int local_120;
  uint local_11c;
  undefined1 local_118;
  char *local_110;
  undefined8 local_108;
  undefined4 **local_100;
  int local_f8;
  uint local_f4;
  undefined1 local_f0;
  char *local_e8;
  undefined8 local_e0;
  undefined4 **local_d8;
  int local_d0;
  uint local_cc;
  undefined1 local_c8;
  char *local_c0;
  uint auStack_b8 [2];
  undefined8 auStack_b0 [16];
  
  uVar4 = 0;
  local_158 = (int *)0x0;
  local_150 = (undefined4 *)0x0;
  local_148 = (undefined4 *)0x0;
  do {
    uVar13 = (ulong)uVar4;
    uVar4 = uVar4 + 0x20;
    *(undefined8 *)((long)auStack_b8 + uVar13) = 0;
    *(undefined8 *)((long)auStack_b0 + uVar13) = 0;
    *(undefined8 *)((long)auStack_b0 + uVar13 + 8) = 0;
    *(undefined8 *)((long)auStack_b0 + uVar13 + 0x10) = 0;
  } while (uVar4 < 0x80);
  local_15c = 0;
  local_174 = param_3;
  local_170 = param_2;
  local_16c[0] = param_1;
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_idle_channels.c",0x4f,"RmIdleChannels",1,
               "NVRM: hChannel: 0x%x, numChannels: %u\n",param_3,param_4);
  uVar4 = param_8 >> 4 & 0xf;
  if (uVar4 != 0) {
    if (uVar4 != 1) {
      return 0x29;
    }
    local_150 = &local_170;
    local_158 = local_16c;
    local_148 = &local_174;
    param_4 = 1;
LAB_0033ebb8:
    lVar12 = 0;
    iVar5 = *local_158;
    if (iVar5 == local_16c[0]) {
      do {
        iVar5 = serverGetClientUnderLock(g_resServ,iVar5,&local_140);
        if ((iVar5 != 0) ||
           (iVar5 = gpuresGetByDeviceOrSubdeviceHandle_IMPL
                              (local_140,*(undefined4 *)((long)local_150 + lVar12),&local_138),
           iVar5 != 0)) goto LAB_0033ec9a;
        lVar7 = *(long *)(*(long *)(local_138 + 0xd0) + 0xe0);
        lVar8 = *(long *)(*(long *)(local_138 + 0xd0) + 0xe8);
        if (lVar8 == 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        *(undefined4 *)((long)local_150 + lVar12) =
             *(undefined4 *)(*(long *)(*(long *)(lVar8 + 0x110) + 0x48) + 0x10);
        uVar13 = (ulong)*(uint *)(lVar7 + 0x7a4);
        lVar12 = lVar12 + 4;
        auStack_b8[uVar13] = auStack_b8[uVar13] + 1;
        uVar4 = gpumgrGetGrpMaskFromGpuInst(uVar13);
        local_15c = local_15c | uVar4;
        if ((ulong)param_4 << 2 == lVar12) {
          cVar3 = rmGpuGroupLockIsOwner(0,2,&local_15c);
          bVar1 = false;
          if (cVar3 == '\0') {
            iVar5 = rmGpuGroupLockAcquire(0,2,0,0x80003,&local_15c);
            bVar1 = true;
            if (iVar5 != 0) {
              nvDbg_Printf("src/kernel/gpu/fifo/kernel_idle_channels.c",0xba,"RmIdleChannels",4,
                           "NVRM: Failed to acquire Device lock, error 0x%x\n",iVar5);
              goto LAB_0033ec9a;
            }
          }
          uVar13 = 0;
          goto LAB_0033eeee;
        }
        iVar5 = *(int *)((long)local_158 + lVar12);
      } while (iVar5 == local_16c[0]);
    }
    iVar5 = 0x1b;
    goto LAB_0033ec9a;
  }
  if (param_4 == 0) {
    return 0;
  }
  local_128 = &local_158;
  iVar14 = param_4 * 4;
  bVar1 = param_4 >> 0x1e == 0;
  local_110 = "RmIdleChannels";
  local_11c = 0;
  local_130 = param_5;
  local_120 = iVar14;
  local_118 = bVar1;
  iVar5 = rmapiParamsAcquire(&local_130,param_10);
  if (iVar5 == 0) {
    local_100 = &local_150;
    local_e8 = "RmIdleChannels";
    local_f4 = 0;
    local_108 = param_6;
    local_f8 = iVar14;
    local_f0 = bVar1;
    iVar5 = rmapiParamsAcquire(&local_108,param_10);
    if (iVar5 == 0) {
      local_d8 = &local_148;
      local_c0 = "RmIdleChannels";
      local_cc = 0;
      local_e0 = param_7;
      local_d0 = iVar14;
      local_c8 = bVar1;
      iVar5 = rmapiParamsAcquire(&local_e0,param_10);
      if (iVar5 == 0) goto LAB_0033ebb8;
    }
  }
  goto LAB_0033eca3;
LAB_0033eeee:
  do {
    uVar4 = auStack_b8[uVar13];
    if (uVar4 != 0) {
      uVar9 = (ulong)uVar4;
      uVar6 = gpumgrGetGpu(uVar13 & 0xffffffff);
      gpuGetKernelFifoShared_IMPL(uVar6);
      lVar12 = portMemAllocNonPaged(uVar9 * 4);
      lVar7 = portMemAllocNonPaged(uVar9 * 4);
      lVar8 = portMemAllocNonPaged(uVar9 * 4);
      if (((lVar12 == 0) || (lVar7 == 0)) || (lVar8 == 0)) {
        iVar5 = 0x51;
        nvCheckFailedNoLog(4,
                           "((pPerGpuClients != NULL) && (pPerGpuDevices != NULL) && (pPerGpuChannels != NULL))"
                           ,"src/kernel/gpu/fifo/kernel_idle_channels.c",0xd7);
        goto LAB_0033f111;
      }
      uVar11 = 0;
      lVar10 = 0;
      do {
        iVar5 = serverGetClientUnderLock
                          (g_resServ,*(undefined4 *)((long)local_158 + lVar10),&local_140);
        if (((iVar5 == 0) &&
            (iVar5 = gpuresGetByDeviceOrSubdeviceHandle_IMPL
                               (local_140,*(undefined4 *)((long)local_150 + lVar10),&local_138),
            iVar5 == 0)) &&
           ((int)uVar13 == *(int *)(*(long *)(*(long *)(local_138 + 0xd0) + 0xe0) + 0x7a4))) {
          uVar9 = (ulong)uVar11;
          uVar11 = uVar11 + 1;
          *(undefined4 *)(lVar12 + uVar9 * 4) = *(undefined4 *)((long)local_158 + lVar10);
          *(undefined4 *)(lVar7 + uVar9 * 4) = *(undefined4 *)((long)local_150 + lVar10);
          *(undefined4 *)(lVar8 + uVar9 * 4) = *(undefined4 *)((long)local_148 + lVar10);
        }
      } while ((lVar10 != (ulong)(param_4 - 1) * 4) && (lVar10 = lVar10 + 4, uVar11 < uVar4));
      lVar10 = gpuGetRpc(uVar6);
      if (lVar10 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_idle_channels.c",0x2c);
        iVar5 = 0x1a;
        portMemFree(lVar12);
        portMemFree(lVar7);
        portMemFree(lVar8);
        goto LAB_0033f111;
      }
      iVar5 = (**(code **)(lVar10 + 0x3a0))(uVar6,lVar10,lVar12,lVar7,lVar8,uVar4,param_8,param_9);
      portMemFree(lVar12);
      portMemFree(lVar7);
      portMemFree(lVar8);
      if (iVar5 != 0) goto LAB_0033f111;
    }
    uVar13 = uVar13 + 1;
  } while (uVar13 != 0x20);
  iVar5 = 0;
LAB_0033f111:
  if (bVar1) {
    rmGpuGroupLockRelease(local_15c,0);
  }
LAB_0033ec9a:
  if ((param_8 & 0xf0) != 0) goto LAB_0033ecfd;
LAB_0033eca3:
  if (local_158 != (int *)0x0) {
    local_11c = local_11c | 4;
    rmapiParamsRelease(&local_130);
  }
  if (local_150 != (undefined4 *)0x0) {
    local_f4 = local_f4 | 4;
    rmapiParamsRelease(&local_108);
  }
  if (local_148 != (undefined4 *)0x0) {
    local_cc = local_cc | 4;
    rmapiParamsRelease(&local_e0);
  }
LAB_0033ecfd:
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_idle_channels.c",0x123,"RmIdleChannels",1,
               "NVRM: DONE. hChannel: 0x%x, numChannels: %u, rmStatus: 0x%x\n",local_174,param_4,
               iVar5);
  return iVar5;
}


// ===== 0033f1e5 usrmodeConstruct_IMPL.cold =====

void usrmodeConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0033f1f0 usrmodeConstruct_IMPL =====

int usrmodeConstruct_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  long lVar2;
  ushort *puVar3;
  code *pcVar4;
  ushort uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar8 = *(long *)(param_1 + 0x210);
  lVar2 = *(long *)(lVar8 + 0xf0);
  lVar7 = gpuGetKernelFifoShared_IMPL(lVar2);
  if (*(long *)(param_3 + 0x58) != 0) {
    lVar8 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                               __nvoc_class_def_UserModeApi);
    *(undefined1 *)(param_1 + 0x221) = *(undefined1 *)(lVar8 + 0x221);
    *(undefined1 *)(param_1 + 0x220) = *(undefined1 *)(lVar8 + 0x220);
    return 0;
  }
  puVar3 = *(ushort **)(param_3 + 0x40);
  uVar10 = *(undefined8 *)(lVar7 + 0x4f0);
  if ((*(uint *)(*(long *)(param_2 + 0x10) + 0x11c) < 0xc661) || (puVar3 == (ushort *)0x0)) {
    *(undefined2 *)(param_1 + 0x220) = 0;
  }
  else {
    uVar5 = *puVar3;
    cVar1 = *(char *)((long)puVar3 + 1);
    if (cVar1 != '\0') {
      if ((char)uVar5 == '\0') {
        nvCheckFailedNoLog(4,"!bPrivMapping || bBar1Mapping","src/kernel/gpu/fifo/usermode_api.c",
                           0x43);
        return 0x3b;
      }
      if ((cVar1 != '\0') && (*(uint *)(param_2 + 0x28) < 2)) {
        nvCheckFailedNoLog(4,
                           "!bPrivMapping || pCallContext->secInfo.privLevel >= RS_PRIV_LEVEL_KERNEL"
                           ,"src/kernel/gpu/fifo/usermode_api.c",0x47);
        return 0x1b;
      }
    }
    *(ushort *)(param_1 + 0x220) = *puVar3 << 8 | *puVar3 >> 8;
    if ((((*(long *)(&DAT_00001b90 + lVar2) == 0) ||
         (*(char *)(*(long *)(&DAT_00001b90 + lVar2) + 0xad45) == '\0')) &&
        (*(char *)(lVar2 + 1099) == '\0')) && ((char)uVar5 != '\0')) {
      if (cVar1 == '\0') {
        uVar10 = *(undefined8 *)(lVar7 + 0x4e0);
        uVar9 = 0x3e;
      }
      else {
        uVar10 = *(undefined8 *)(lVar7 + 0x4e8);
        uVar9 = 0x3e;
      }
      goto LAB_0033f316;
    }
  }
  uVar9 = 0x3f;
LAB_0033f316:
  iVar6 = memConstructCommon_IMPL(lVar8,uVar9,0,uVar10,0,0,0,0,0,0,0,0);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "memConstructCommon(pMemory, memClassId, 0, pMemDesc, 0, NULL, 0, 0, 0, 0, NVOS32_MEM_TAG_NONE, NULL)"
               ,"src/kernel/gpu/fifo/usermode_api.c",100);
    return iVar6;
  }
  memdescAddRef(uVar10);
  return 0;
}


// ===== 0033f410 usrmodeCanCopy_IMPL =====

undefined8 usrmodeCanCopy_IMPL(void)

{
  return 1;
}


// ===== 0033f41a usrmodeGetMemInterMapParams_IMPL.cold =====

void usrmodeGetMemInterMapParams_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0033f430 usrmodeGetMemInterMapParams_IMPL =====

ulong usrmodeGetMemInterMapParams_IMPL(long param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  lVar3 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(lVar1 + 0xf0));
  uVar4 = memGetMemInterMapParams_IMPL(lVar1,param_2);
  if ((int)uVar4 == 0) {
    if (*(char *)(param_1 + 0x221) == '\0') {
      nvCheckFailedNoLog(4,"pUserModeApi->bInternalMmio","src/kernel/gpu/fifo/usermode_api.c",0x81);
      uVar4 = 0x3b;
    }
    else {
      uVar5 = *(undefined8 *)(lVar3 + 0x4e8);
      if (*(char *)(param_1 + 0x220) == '\0') {
        uVar5 = *(undefined8 *)(lVar3 + 0x4e0);
      }
      *(undefined8 *)(param_2 + 0x20) = uVar5;
    }
    return uVar4;
  }
  nvCheckOkFailedNoLog
            (4,uVar4 & 0xffffffff,"memGetMemInterMapParams_IMPL(pMemory, pParams)",
             "src/kernel/gpu/fifo/usermode_api.c",0x7f);
  return uVar4 & 0xffffffff;
}


// ===== 0033f510 uvmchanrtnrDestruct_IMPL =====

void uvmchanrtnrDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  uVar3 = gpuGetKernelFifoShared_IMPL(uVar1);
  lVar5 = *(long *)(param_1 + 0x138);
  if (*(char *)(lVar5 + 100) != '\0') {
    memdescFree();
    lVar5 = *(long *)(param_1 + 0x138);
  }
  memdescDestroy(lVar5);
  uVar4 = kfifoGetChidMgr_IMPL(uVar1,uVar3,*(undefined4 *)(param_1 + 0x144));
  iVar2 = kfifoChidMgrReleaseChid_IMPL(uVar1,uVar3,uVar4,*(undefined4 *)(param_1 + 0x140));
  if (iVar2 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar2,"kfifoChidMgrReleaseChid(pGpu, pKernelFifo, pChidMgr, pUvmChannelRetainer->chId)"
             ,"src/kernel/gpu/fifo/uvm_channel_retainer.c",0x71);
  return;
}


// ===== 0033f5d0 uvmchanrtnrIsAllocationAllowed_IMPL =====

bool uvmchanrtnrIsAllocationAllowed_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int local_c;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/uvm_channel_retainer.c",0x89);
    return false;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (*(char *)(lVar1 + 0x491d) != '\0') {
    iVar2 = vgpuGetCallingContextGfid(lVar1,&local_c);
    if (iVar2 != 0) {
      nvAssertFailedNoLog("vgpuGetCallingContextGfid(pGpu, &gfid) == NV_OK",
                          "src/kernel/gpu/fifo/uvm_channel_retainer.c",0x8e);
      return false;
    }
    if (local_c != 0) {
      iVar2 = kchannelGetGfid_IMPL(param_3);
      return local_c == iVar2;
    }
  }
  return true;
}


// ===== 0033f670 uvmchanrtnrConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int uvmchanrtnrConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 local_48;
  long local_40 [2];
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar6 = gpuGetKernelFifoShared_IMPL(uVar1);
  puVar2 = *(undefined4 **)(param_3 + 0x40);
  local_40[0] = 0;
  iVar4 = serverGetClientUnderLock(g_resServ,*puVar2,&local_48);
  if (iVar4 == 0) {
    iVar4 = CliGetKernelChannel(local_48,puVar2[1],local_40);
    if (iVar4 == 0) {
      cVar3 = uvmchanrtnrIsAllocationAllowed_IMPL(param_1,param_2,local_40[0]);
      if (cVar3 == '\0') {
        iVar4 = 0x1b;
        nvDbg_Printf("src/kernel/gpu/fifo/uvm_channel_retainer.c",0x3f,"uvmchanrtnrConstruct_IMPL",4
                     ,"NVRM: class Id %d can only be allocated by internal kernel clients\n",
                     *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x11c));
      }
      else {
        uVar7 = kfifoGetChidMgr_IMPL(uVar1,lVar6,*(undefined4 *)(local_40[0] + 0x2b0));
        iVar4 = kfifoChidMgrRetainChid_IMPL(uVar1,lVar6,uVar7,*(undefined4 *)(local_40[0] + 0x2b4));
        if (iVar4 == 0) {
          *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(local_40[0] + 0x2b4);
          *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(local_40[0] + 0x2b0);
          iVar4 = (**(code **)(lVar6 + 0x1c0))(uVar1,lVar6,local_40[0],1,param_1 + 0x138);
          if (iVar4 == 0) {
            lVar6 = *(long *)(param_1 + 0x138);
            if (*(char *)(lVar6 + 100) != '\0') {
              *(char *)(lVar6 + 100) = *(char *)(lVar6 + 100) + '\x01';
              lVar6 = *(long *)(param_1 + 0x138);
            }
            memdescAddRef(lVar6);
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar4,
                       "kfifoChannelGetFifoContextMemDesc_HAL(pGpu, pKernelFifo, pKernelChannel, FIFO_CTX_INST_BLOCK, &pUvmChannelRetainer->pInstMemDesc)"
                       ,"src/kernel/gpu/fifo/uvm_channel_retainer.c",0x4c);
            iVar5 = kfifoChidMgrReleaseChid_IMPL
                              (uVar1,lVar6,uVar7,*(undefined4 *)(local_40[0] + 0x2b4));
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,
                         "kfifoChidMgrReleaseChid(pGpu, pKernelFifo, pChidMgr, pKernelChannel->ChID)"
                         ,"src/kernel/gpu/fifo/uvm_channel_retainer.c",0x5b);
            }
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar4,
                     "kfifoChidMgrRetainChid(pGpu, pKernelFifo, pChidMgr, pKernelChannel->ChID)",
                     "src/kernel/gpu/fifo/uvm_channel_retainer.c",0x47);
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,
                 "CliGetKernelChannel(pChannelClient, pUvmChannelRetainerParams->hChannel, &pKernelChannel)"
                 ,"src/kernel/gpu/fifo/uvm_channel_retainer.c",0x3b);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,
               "serverGetClientUnderLock(&g_resServ, pUvmChannelRetainerParams->hClient, &pChannelClient)"
               ,"src/kernel/gpu/fifo/uvm_channel_retainer.c",0x38);
  }
  return iVar4;
}


// ===== 0033f8d0 _kfspWaitBootCond_GB100 =====

bool _kfspWaitBootCond_GB100(long param_1)

{
  int iVar1;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x200bc,0);
  return iVar1 == 0xff;
}


// ===== 0033f900 kfspConstructHal_GB100 =====

void kfspConstructHal_GB100(long param_1,long param_2)

{
  ioaprtInit(param_2 + 0x2d0,*(undefined8 *)(param_1 + 0x1a18),0x8f1e00,0x200);
  return;
}


// ===== 0033f930 kfspWaitForSecureBoot_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspWaitForSecureBoot_GB100(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined1 local_50 [32];
  
  uVar8 = *(int *)(param_1 + 0x1b08) * 4000000;
  if (uVar8 <= *(uint *)(param_1 + 0x1af4)) {
    uVar8 = *(uint *)(param_1 + 0x1af4);
  }
  timeoutSet(param_1 + 0x1af0,local_50,uVar8,8);
  iVar1 = timeoutCondWait(param_1 + 0x1af0,local_50,_kfspWaitBootCond_GB100,0,0x5f);
  if (iVar1 != 0) {
    iVar7 = (**(code **)(param_1 + 0x100))(param_1);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,"gpuMarkDeviceForReset(pGpu)",
                 "src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",99);
    }
    uVar2 = regRead032(param_1 + 0x3a18,0,0,0x8f032c,0);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x8f0328,0);
    uVar4 = regRead032(param_1 + 0x3a18,0,0,0x8f0324,0);
    uVar5 = regRead032(param_1 + 0x3a18,0,0,0x8f0320,0);
    uVar6 = regRead032(param_1 + 0x3a18,0,0,0x200bc,0);
    nvErrorLog_va(param_1,0x8f,
                  "Error status 0x%x while polling for FSP boot complete, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x"
                  ,iVar1,uVar6,uVar5,uVar4,uVar3,uVar2);
    (**(code **)(param_2 + 0x200))(param_1,param_2);
  }
  iVar7 = regRead032(param_1 + 0x3a18,0,0,0x8f033c,0);
  if (iVar7 == 0) {
    uVar2 = regRead032(param_1 + 0x3a18,0,0,0x8f033c,0);
    nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x72,
                 "kfspWaitForSecureBoot_GB100",1,
                 "NVRM: FSP fuse error check has passed. Status = 0x%08x.\n",uVar2);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x77,
                 "kfspWaitForSecureBoot_GB100",4,
                 "NVRM: ****************************************** FSP Fuse Check Failure ************************************************\n"
                );
    uVar2 = regRead032(param_1 + 0x3a18,0,0,0x8f033c,0);
    nvErrorLog_va(param_1,0x8f,"FSP fuse error check has failed. Status = 0x%x.",uVar2);
    uVar2 = regRead032(param_1 + 0x3a18,0,0,0x8f033c,0);
    nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x7b,
                 "kfspWaitForSecureBoot_GB100",4,
                 "NVRM: ** FSP fuse error check has failed. Status = 0x%x.                                                               **\n"
                 ,uVar2);
    nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x7e,
                 "kfspWaitForSecureBoot_GB100",4,
                 "NVRM: ******************************************************************************************************************\n"
                );
    if (*(char *)(param_2 + 0x248) != '\0') {
      iVar1 = 0x7f;
    }
  }
  return iVar1;
}


// ===== 0033fc00 kfspCheckForClockBoostCapability_GB100 =====

void kfspCheckForClockBoostCapability_GB100(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined1 local_19 [9];
  
  *(undefined1 *)(param_2 + 0x2c8) = 0;
  local_19[0] = 0x20;
  iVar1 = kfspSendAndReadMessage_IMPL(param_1,param_2,local_19,1,0x16,0,0);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x9a,
                 "kfspCheckForClockBoostCapability_GB100",2,"NVRM: FSP has clock boost capability\n"
                );
    *(undefined1 *)(param_2 + 0x2c8) = 1;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x9f,
               "kfspCheckForClockBoostCapability_GB100",4,
               "NVRM: FSP doesn\'t have clock boost capability\n");
  return;
}


// ===== 0033fca0 kfspDumpDebugState_GB100 =====

void kfspDumpDebugState_GB100(long param_1)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined4 local_d8 [48];
  
  lVar1 = param_1 + 0x3a18;
  uVar3 = regRead032(lVar1,0,0,0x8f0334,0);
  if ((uVar3 & 0xfff) != 0) {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xbb,
                 "kfspDumpDebugState_GB100",4,"NVRM: FSP microcode v%u.%u\n",(uVar3 & 0xfff) >> 8,
                 uVar3 & 0xff);
  }
  uVar2 = *(ulong *)(param_1 + 0x878);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xc0,"kfspDumpDebugState_GB100",
               4,"NVRM: GPU %04x:%02x:%02x\n",uVar2 >> 0x20,uVar2 >> 8 & 0xff,uVar2 & 0xff);
  uVar4 = regRead032(lVar1,0,0,0x8f0320,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xc3,"kfspDumpDebugState_GB100",
               4,"NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(0) = 0x%x\n",uVar4);
  uVar4 = regRead032(lVar1,0,0,0x8f0324,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xc5,"kfspDumpDebugState_GB100",
               4,"NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(1) = 0x%x\n",uVar4);
  uVar4 = regRead032(lVar1,0,0,0x8f0328,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",199,"kfspDumpDebugState_GB100",4
               ,"NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(2) = 0x%x\n",uVar4);
  uVar4 = regRead032(lVar1,0,0,0x8f032c,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xc9,"kfspDumpDebugState_GB100",
               4,"NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(3) = 0x%x\n",uVar4);
  uVar4 = regRead032(lVar1,0,0,0x110040,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xcc,"kfspDumpDebugState_GB100",
               4,"NVRM: NV_PGSP_FALCON_MAILBOX0 = 0x%x\n",uVar4);
  uVar4 = regRead032(lVar1,0,0,0x110044,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xce,"kfspDumpDebugState_GB100",
               4,"NVRM: NV_PGSP_FALCON_MAILBOX1 = 0x%x\n",uVar4);
  iVar6 = 0;
  do {
    uVar5 = regRead032(lVar1,0,0,iVar6 * 4 + 0x110804,0);
    iVar7 = iVar6 + 1;
    nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xd2,
                 "kfspDumpDebugState_GB100",4,"NVRM: NV_PGSP_MAILBOX(%d) = 0x%x\n",iVar6,uVar5);
    iVar6 = iVar7;
  } while (iVar7 != 4);
  lVar8 = 0;
  do {
    regWrite032(lVar1,0,0,0x8aa374,(int)lVar8 + 0x50,0);
    uVar4 = regRead032(lVar1,0,0,0x8aa378,0);
    local_d8[lVar8] = uVar4;
    lVar8 = lVar8 + 1;
  } while (lVar8 != 0x30);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0xf1,"_kfspPrintCms2Log_GB100",4
               ,"NVRM: CMS2 Log:\n");
  nvDbgDumpBufferBytes(local_d8,0xc0);
  return;
}


// ===== 0033ffa0 kfspSendClockBoostRpc_GB100 =====

void kfspSendClockBoostRpc_GB100(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  undefined1 local_9;
  
  local_9 = param_3;
  kfspSendAndReadMessage_IMPL(param_1,param_2,&local_9,1,0x20,0,0);
  return;
}


// ===== 0033ffd0 kfspSendPacket_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void kfspSendPacket_GB100(long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 local_30 [32];
  
  if (*(char *)(param_2 + 0x24e) == '\0') {
    kfspSendPacket_GH100();
    return;
  }
  timeoutSet(param_1 + 0x1af0,local_30,0,0);
  (**(code **)(param_1 + 0x260))(param_1,param_2 + 0x2d0,2,local_30,param_3,param_4);
  return;
}


// ===== 00340050 kfspReadPacket_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfspReadPacket_GB100
                (long param_1,long param_2,undefined8 param_3,undefined4 param_4,undefined4 *param_5
                )

{
  ulong uVar1;
  undefined4 local_1c [3];
  
  if (param_5 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pBytesRead != NULL","src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",
                        0x133);
    return 0x3d;
  }
  if (*(char *)(param_2 + 0x24e) != '\0') {
    local_1c[0] = param_4;
    uVar1 = (**(code **)(param_1 + 0x268))(param_1,param_2 + 0x2d0,2,param_3,local_1c);
    if ((int)uVar1 == 0) {
      *param_5 = local_1c[0];
      return uVar1;
    }
    nvCheckOkFailedNoLog
              (4,uVar1 & 0xffffffff,
               "gpuMnocMboxRecv_HAL(pGpu, &pKernelFsp->mboxAperture, KERNEL_FSP_MBOX_PORT, pPacket, &recvSize)"
               ,"src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x138);
    return uVar1 & 0xffffffff;
  }
  uVar1 = kfspReadPacket_GH100();
  return uVar1;
}


// ===== 00340110 kfspCanSendPacket_GB100 =====

undefined8 kfspCanSendPacket_GB100(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_2 + 0x24e) != '\0') {
    return 1;
  }
  uVar1 = kfspCanSendPacket_GH100();
  return uVar1;
}


// ===== 00340130 kfspIsResponseAvailable_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfspIsResponseAvailable_GB100(long param_1,long param_2)

{
  if (*(char *)(param_2 + 0x24e) != '\0') {
    (**(code **)(param_1 + 0x270))(param_1,param_2 + 0x2d0,2);
    return;
  }
  kfspIsResponseAvailable_GH100();
  return;
}


// ===== 00340160 kfspGetMaxSendPacketSize_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfspGetMaxSendPacketSize_GB100(long param_1,long param_2)

{
  if (*(char *)(param_2 + 0x24e) != '\0') {
    (**(code **)(param_1 + 0x2a0))();
    return;
  }
  kfspGetMaxSendPacketSize_GH100();
  return;
}


// ===== 00340190 kfspGetMaxRecvPacketSize_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfspGetMaxRecvPacketSize_GB100(long param_1,long param_2)

{
  if (*(char *)(param_2 + 0x24e) != '\0') {
    (**(code **)(param_1 + 0x2a0))();
    return;
  }
  kfspGetMaxRecvPacketSize_GH100();
  return;
}


// ===== 003401c0 kfspFrtsSysmemLocationClear_GB100 =====

void kfspFrtsSysmemLocationClear_GB100(long param_1)

{
  int iVar1;
  long local_20 [2];
  
  iVar1 = gpuGetOneDeviceEntry_IMPL(param_1,0x33,0xffffffff,0,0xffffffff,local_20);
  if (iVar1 == 0) {
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x4fc,0,0);
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x4f8,0,0);
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x4f4,0,0);
    return;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",400);
  return;
}


// ===== 00340280 kfspFrtsSysmemLocationProgram_GB100 =====

undefined8 kfspFrtsSysmemLocationProgram_GB100(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(long *)(param_2 + 0x250) != 0) {
    uVar1 = memdescGetPhysAddr(*(long *)(param_2 + 0x250),1,0);
    regWrite032(param_1 + 0x3a18,0,0,0x14f4,uVar1 & 0xffffffff,0);
    regWrite032(param_1 + 0x3a18,0,0,0x14f8,uVar1 >> 0x20,0);
    regWrite032(param_1 + 0x3a18,0,0,0x14fc,
                (uint)(*(ulong *)(*(long *)(param_2 + 0x250) + 0x30) >> 0xc) & 0xffff | 0x10000,0);
    return 0;
  }
  nvAssertFailedNoLog("pKernelFsp->pSysmemFrtsMemdesc != NULL",
                      "src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb100.c",0x1a3);
  return 0x40;
}


// ===== 00340370 _kfspWaitBootCond_GB202 =====

bool _kfspWaitBootCond_GB202(long param_1)

{
  int iVar1;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0xad00bc,0);
  return iVar1 == 0xff;
}


// ===== 003403a0 kfspWaitForSecureBoot_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspWaitForSecureBoot_GB202(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined1 local_50 [32];
  
  uVar8 = *(int *)(param_1 + 0x1b08) * 5000000;
  if (uVar8 <= *(uint *)(param_1 + 0x1af4)) {
    uVar8 = *(uint *)(param_1 + 0x1af4);
  }
  timeoutSet(param_1 + 0x1af0,local_50,uVar8,0xc);
  iVar1 = timeoutCondWait(param_1 + 0x1af0,local_50,_kfspWaitBootCond_GB202,0,0x50);
  if (iVar1 != 0) {
    iVar2 = (**(code **)(param_1 + 0x100))(param_1);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"gpuMarkDeviceForReset(pGpu)",
                 "src/kernel/gpu/fsp/arch/blackwell/kern_fsp_gb202.c",0x54);
    }
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x8f032c,0);
    uVar4 = regRead032(param_1 + 0x3a18,0,0,0x8f0328,0);
    uVar5 = regRead032(param_1 + 0x3a18,0,0,0x8f0324,0);
    uVar6 = regRead032(param_1 + 0x3a18,0,0,0x8f0320,0);
    uVar7 = regRead032(param_1 + 0x3a18,0,0,0xad00bc,0);
    nvErrorLog_va(param_1,0x8f,
                  "Error status 0x%x while polling for FSP boot complete, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x"
                  ,iVar1,uVar7,uVar6,uVar5,uVar4,uVar3);
    (**(code **)(param_2 + 0x200))(param_1,param_2);
  }
  return iVar1;
}


// ===== 00340540 _kfspWaitBootCond_GH100 =====

bool _kfspWaitBootCond_GH100(long param_1)

{
  int iVar1;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x200bc,0);
  return iVar1 == 0xff;
}


// ===== 00340570 _kfspIsGspTargetMaskReleased =====

bool _kfspIsGspTargetMaskReleased(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = gpuGetDeviceMapping_IMPL(param_1,0,0);
  uVar1 = osDevReadReg032(param_1,uVar2,&DAT_001100f4);
  return uVar1 != 0 && (uVar1 & 0xffffff00) != 0xbadf4100;
}


// ===== 003405b0 kfspGetMaxSendPacketSize_GH100 =====

undefined8 kfspGetMaxSendPacketSize_GH100(void)

{
  return 0x400;
}


// ===== 003405c0 kfspGetMaxRecvPacketSize_GH100 =====

undefined8 kfspGetMaxRecvPacketSize_GH100(void)

{
  return 0x400;
}


// ===== 003405d0 kfspIsResponseAvailable_GH100 =====

bool kfspIsResponseAvailable_GH100(long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x8f2c80,0);
  iVar2 = regRead032(param_1 + 0x3a18,0,0,0x8f2c84,0);
  return iVar1 != iVar2;
}


// ===== 00340620 kfspCanSendPacket_GH100 =====

uint kfspCanSendPacket_GH100(long param_1)

{
  undefined7 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  param_1 = param_1 + 0x3a18;
  iVar2 = regRead032(param_1,0,0,0x8f2c00,0);
  iVar3 = regRead032(param_1,0,0,0x8f2c04,0);
  iVar4 = regRead032(param_1,0,0,0x8f2c80,0);
  uVar5 = regRead032(param_1,0,0,0x8f2c84,0);
  uVar1 = (undefined7)((ulong)uVar5 >> 8);
  return (uint)CONCAT71(uVar1,iVar2 == iVar3) & (uint)CONCAT71(uVar1,iVar4 == (int)uVar5);
}


// ===== 003406b0 kfspNvdmToSeid_GH100 =====

bool kfspNvdmToSeid_GH100(undefined8 param_1,undefined8 param_2,char param_3)

{
  return param_3 == '\x17';
}


// ===== 003406c0 kfspCreateMctpHeader_GH100 =====

uint kfspCreateMctpHeader_GH100
               (undefined8 param_1,undefined8 param_2,int param_3,uint param_4,byte param_5,
               uint param_6)

{
  return (param_6 & 3) << 0x1c | (uint)param_5 << 0x10 | param_3 << 0x1f | (param_4 & 1) << 0x1e;
}


// ===== 003406f0 kfspCreateNvdmHeader_GH100 =====

uint kfspCreateNvdmHeader_GH100(undefined8 param_1,undefined8 param_2,int param_3)

{
  return param_3 << 0x18 | 0x10de7e;
}


// ===== 00340700 kfspGetPacketInfo_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kfspGetPacketInfo_GH100
          (undefined8 param_1,long param_2,uint *param_3,undefined8 param_4,undefined4 *param_5,
          byte *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar1 = *param_3;
  if (((uVar1 & 0x40000000) != 0) || (uVar3 = 0, -1 < (int)uVar1)) {
    if (((uVar1 >> 0x1f ^ 1) & uVar1 >> 0x1e) != 0) {
      *param_5 = 2;
      uVar2 = 0;
      goto LAB_00340750;
    }
    if ((uVar1 >> 0x1f & uVar1 >> 0x1e) == 0) {
      *param_5 = 1;
      uVar2 = 0;
      goto LAB_00340750;
    }
    uVar3 = 3;
  }
  *param_5 = uVar3;
  uVar2 = (**(code **)(param_2 + 0x1e8))();
LAB_00340750:
  *param_6 = (byte)(uVar1 >> 0x18) & 7;
  return uVar2;
}


// ===== 003407a0 kfspValidateMctpPayloadHeader_GH100 =====

undefined8
kfspValidateMctpPayloadHeader_GH100(undefined8 param_1,undefined8 param_2,long param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if ((char)(uVar1 & 0x7f) == '~') {
    if ((short)(uVar1 >> 8) == 0x10de) {
      if (7 < param_4) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x1c4,
                   "kfspValidateMctpPayloadHeader_GH100",4,
                   "NVRM: Packet doesn\'t contain NVDM type in payload header\n");
    }
    else {
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x1bd,
                   "kfspValidateMctpPayloadHeader_GH100",4,
                   "NVRM: Invalid PCI Vendor Id 0x%0x, expecting 0x10de (Nvidia)\n",
                   uVar1 >> 8 & 0xffff);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x1b5,
                 "kfspValidateMctpPayloadHeader_GH100",4,
                 "NVRM: Invalid MCTP Message type 0x%0x, expecting 0x7e (Vendor Defined PCI)\n",
                 uVar1 & 0x7f);
  }
  return 0x25;
}


// ===== 00340860 kfspProcessNvdmMessage_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kfspProcessNvdmMessage_GH100(undefined8 param_1,long param_2,char *param_3)

{
  undefined8 uVar1;
  
  if ((*param_3 != '\x15') && (*param_3 != '\x18')) {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x1ea,
                 "kfspProcessNvdmMessage_GH100",4,
                 "NVRM: Unknown or unsupported NVDM type received: 0x%0x\n");
    return 0x56;
  }
  uVar1 = (**(code **)(param_2 + 0x1f8))();
  return uVar1;
}


// ===== 003408c0 kfspProcessCommandResponse_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspProcessCommandResponse_GH100(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  
  if (param_4 < 0xd) {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x20c,
                 "kfspProcessCommandResponse_GH100",4,
                 "NVRM: Expected FSP command response, but packet is not big enough for payload. Size: 0x%0x\n"
                 ,param_4);
    return 0x25;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x211,
               "kfspProcessCommandResponse_GH100",1,
               "NVRM: Received FSP command response. Task ID: 0x%0x Command type: 0x%0x Error code: 0x%0x\n"
               ,*(undefined4 *)(param_3 + 1),*(undefined4 *)(param_3 + 5),
               *(undefined4 *)(param_3 + 9));
  iVar1 = (**(code **)(param_2 + 0x208))(param_1,param_2,*(undefined4 *)(param_3 + 9));
  if (iVar1 != 0) {
    if ((iVar1 != 0x57) && (iVar1 != 0x1f)) {
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x21b,
                   "kfspProcessCommandResponse_GH100",4,
                   "NVRM: FSP response reported error. Task ID: 0x%0x Command type: 0x%0x Error code: 0x%0x\n"
                   ,*(undefined4 *)(param_3 + 1),*(undefined4 *)(param_3 + 5),
                   *(undefined4 *)(param_3 + 9));
      (**(code **)(param_2 + 0x200))(param_1,param_2);
      return iVar1;
    }
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x217,
               "kfspProcessCommandResponse_GH100",1,
               "NVRM: Last command was processed by FSP successfully!\n");
  return 0;
}


// ===== 00340a40 kfspSendPacket_GH100 =====

undefined8 kfspSendPacket_GH100(long param_1,undefined8 param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  uint local_4c;
  uint local_3c [3];
  
  uVar4 = 0x1a;
  iVar3 = kfspPollForCanSend_IMPL();
  if (iVar3 == 0) {
    param_1 = param_1 + 0x3a18;
    uVar4 = 0;
    regWrite032(param_1,0,0,0x8f2ac0,0x1000000,0);
    local_3c[0] = regRead032(param_1,0,0,0x8f2ac0,0);
    iVar3 = (local_3c[0] >> 8 & 0xff) * 0x40 + (local_3c[0] >> 2 & 0x3f);
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x270,"_kfspWriteToEmem_GH100",1,
                 "NVRM: About to send data to FSP, ememcOff=0x%x, size=0x%x\n",iVar3,param_4);
    local_4c = param_4 >> 2;
    if (local_4c != 0) {
      puVar5 = param_3;
      do {
        uVar2 = *puVar5;
        puVar5 = puVar5 + 1;
        regWrite032(param_1,0,0,0x8f2ac4,uVar2,0);
      } while (puVar5 != (undefined4 *)((ulong)(local_4c * 4) + (long)param_3));
    }
    if ((param_4 & 3) != 0) {
      local_3c[0] = 0;
      portMemCopy(local_3c,4,(long)param_3 + (ulong)(param_4 & 0xfffffffc),param_4 & 3);
      regWrite032(param_1,0,0,0x8f2ac4,local_3c[0],0);
      local_4c = local_4c + 1;
    }
    local_3c[0] = regRead032(param_1,0,0,0x8f2ac0,0);
    iVar1 = (local_3c[0] >> 8 & 0xff) * 0x40 + (local_3c[0] >> 2 & 0x3f);
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x287,"_kfspWriteToEmem_GH100",1,
                 "NVRM: After sending data, ememcOff = 0x%x\n",iVar1);
    if (iVar1 - iVar3 != local_4c) {
      nvAssertFailedNoLog("(ememOffsetEnd - ememOffsetStart) == wordsWritten",
                          "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x289);
    }
    regWrite032(param_1,0,0,0x8f2c04,(param_4 + 3 & 0xfffffffc) - 4,0);
    regWrite032(param_1,0,0,0x8f2c00,0,0);
  }
  return uVar4;
}


// ===== 00340c70 kfspReadPacket_GH100 =====

undefined8
kfspReadPacket_GH100(long param_1,undefined8 param_2,undefined4 *param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  param_1 = param_1 + 0x3a18;
  iVar2 = regRead032(param_1,0,0,0x8f2c80,0);
  iVar3 = regRead032(param_1,0,0,0x8f2c84,0);
  uVar4 = iVar3 - iVar2;
  if ((uVar4 < 0xfffffffc) && (uVar1 = uVar4 + 4, uVar1 <= param_4)) {
    regWrite032(param_1,0,0,0x8f2ac0,0x2000000,0);
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x2e9,"kfspReadPacket_GH100",1,
                 "NVRM: About to read data from FSP, ememcOff=0, size=0x%x\n",uVar1);
    if ((uVar4 & 3) != 0) {
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x2ec,"kfspReadPacket_GH100",3,
                   "NVRM: Size=0x%x is not DWORD-aligned, data will be truncated!\n",uVar1);
    }
    puVar7 = param_3;
    do {
      puVar8 = puVar7 + 1;
      uVar5 = regRead032(param_1,0,0,0x8f2ac4,0);
      *puVar7 = uVar5;
      puVar7 = puVar8;
    } while ((undefined4 *)((ulong)((uVar1 >> 2) * 4) + (long)param_3) != puVar8);
    *param_5 = uVar1;
    uVar4 = regRead032(param_1,0,0,0x8f2ac0,0);
    uVar4 = (uVar4 >> 8 & 0xff) * 0x40 + (uVar4 >> 2 & 0x3f);
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x2fa,"kfspReadPacket_GH100",1,
                 "NVRM: After reading data, ememcOff = 0x%x\n",uVar4);
    regWrite032(param_1,0,0,0x8f2c84,iVar2,0);
    regWrite032(param_1,0,0,0x8f2c80,iVar2,0);
    uVar6 = 0;
    if (uVar4 != uVar1 >> 2) {
      nvAssertFailedNoLog("(ememOffsetEnd) == (packetSize / sizeof(NvU32))",
                          "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x2ff);
      uVar6 = 0x40;
    }
    return uVar6;
  }
  nvAssertFailedNoLog("(packetSize >= sizeof(NvU32)) && (packetSize <= maxPacketSize)",
                      "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x2de);
  return 0x25;
}


// ===== 00340eb0 kfspWaitForSecureBoot_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspWaitForSecureBoot_GH100(long param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined1 local_40 [24];
  
  uVar8 = *(int *)(param_1 + 0x1b08) * 4000000;
  if (uVar8 <= *(uint *)(param_1 + 0x1af4)) {
    uVar8 = *(uint *)(param_1 + 0x1af4);
  }
  timeoutSet(param_1 + 0x1af0,local_40,uVar8,8);
  iVar1 = timeoutCondWait(param_1 + 0x1af0,local_40,_kfspWaitBootCond_GH100,0,0x325);
  if (iVar1 != 0) {
    iVar2 = (**(code **)(param_1 + 0x100))(param_1);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"gpuMarkDeviceForReset(pGpu)",
                 "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x329);
    }
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x8f032c,0);
    uVar4 = regRead032(param_1 + 0x3a18,0,0,0x8f0328,0);
    uVar5 = regRead032(param_1 + 0x3a18,0,0,0x8f0324,0);
    uVar6 = regRead032(param_1 + 0x3a18,0,0,0x8f0320,0);
    uVar7 = regRead032(param_1 + 0x3a18,0,0,0x200bc,0);
    nvErrorLog_va(param_1,0x8f,
                  "Error status 0x%x while polling for FSP boot complete, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x"
                  ,iVar1,uVar7,uVar6,uVar5,uVar4,uVar3);
  }
  return iVar1;
}


// ===== 00341030 kfspWaitForGspTargetMaskReleased_GH100 =====

void kfspWaitForGspTargetMaskReleased_GH100(long param_1)

{
  timeoutCondWait(param_1 + 0x1af0,0,_kfspIsGspTargetMaskReleased,0,0x46f);
  return;
}


// ===== 00341060 kfspDumpDebugState_GH100 =====

void kfspDumpDebugState_GH100(long param_1)

{
  ulong uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x8f0334,0);
  if ((uVar2 & 0xfff) != 0) {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x495,"kfspDumpDebugState_GH100",
                 4,"NVRM: FSP microcode v%u.%u\n",(uVar2 & 0xfff) >> 8,uVar2 & 0xff);
  }
  uVar1 = *(ulong *)(param_1 + 0x878);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x49a,"kfspDumpDebugState_GH100",4,
               "NVRM: GPU %04x:%02x:%02x\n",uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff);
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x8f0320,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x49e,"kfspDumpDebugState_GH100",4,
               "NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(0) = 0x%x\n",uVar3);
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x8f0324,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4a0,"kfspDumpDebugState_GH100",4,
               "NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(1) = 0x%x\n",uVar3);
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x8f0328,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4a2,"kfspDumpDebugState_GH100",4,
               "NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(2) = 0x%x\n",uVar3);
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x8f032c,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4a4,"kfspDumpDebugState_GH100",4,
               "NVRM: NV_PFSP_FALCON_COMMON_SCRATCH_GROUP_2(3) = 0x%x\n",uVar3);
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x110040,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4a7,"kfspDumpDebugState_GH100",4,
               "NVRM: NV_PGSP_FALCON_MAILBOX0 = 0x%x\n",uVar3);
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x110044,0);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4a9,"kfspDumpDebugState_GH100",4,
               "NVRM: NV_PGSP_FALCON_MAILBOX1 = 0x%x\n",uVar3);
  return;
}


// ===== 003412b0 kfspGspFmcIsEnforced_GH100 =====

undefined8 kfspGspFmcIsEnforced_GH100(void)

{
  return 1;
}


// ===== 003412c0 kfspPrepareBootCommands_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspPrepareBootCommands_GH100(long param_1,long param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  undefined8 uVar15;
  int local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  local_5c = 0;
  iVar4 = *(int *)(param_1 + 0x4b34);
  local_58 = 0;
  cVar1 = *(char *)(param_1 + 0x4ba);
  local_50 = 0;
  iVar3 = (**(code **)(param_2 + 0x1c0))();
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x51f,
                 "kfspPrepareBootCommands_GH100",4,"NVRM: FSP secure boot partition timed out.\n");
    goto LAB_003413c5;
  }
  if (*(char *)(param_1 + 0x446) == '\0') {
    if (*(char *)(param_1 + 0x490e) != '\0') goto LAB_00341399;
    if (*(char *)(param_2 + 0x50) == '\0') {
      cVar2 = (**(code **)(param_2 + 0x1a0))(param_1,param_2);
      if ((cVar2 == '\0') || (*(char *)(param_2 + 0x24d) == '\0')) goto LAB_00341440;
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4ed,
                   "kfspSafeToSendBootCommands",4,
                   "NVRM: Chain-of-trust (GSP-FMC) cannot be disabled on silicon.\n");
    }
    else {
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4e0,
                   "kfspSafeToSendBootCommands",4,
                   "NVRM: RM cannot boot with FSP missing on silicon.\n");
    }
    iVar3 = 0x56;
  }
  else {
    if (*(char *)(param_2 + 0x50) == '\0') {
LAB_00341440:
      if ((*(char *)(param_2 + 0x24b) == '\0') ||
         ((*(char *)(param_2 + 0x24c) == '\0' || (*(char *)(param_2 + 0x24d) == '\0')))) {
        if (*(char *)(param_1 + 0x444) == '\0') {
          if (*(char *)(param_1 + 0x909) == '\0') {
            (**(code **)(param_2 + 0x238))(param_1,param_2);
          }
          *(undefined1 *)(param_2 + 0x2c9) = 0;
          iVar3 = osReadRegistryDword(param_1,"RmBootGspRmWithBoostClocks",&local_5c);
          if (iVar3 == 0 && local_5c == 0) {
            *(undefined1 *)(param_2 + 0x2c9) = 1;
          }
          if (*(char *)(param_2 + 0x2c8) != '\0') {
LAB_003414bc:
            cVar2 = *(char *)(param_2 + 0x2c9);
            uVar7 = (**(code **)(param_2 + 0x240))(param_1,param_2);
            iVar3 = (int)uVar7;
            if (iVar3 != 0) {
              nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x54e,
                           "kfspPrepareBootCommands_GH100",4,
                           "NVRM: Clock boost feature cmd %d via FSP failed with error 0x%x\n",
                           cVar2 == '\0',uVar7);
              goto LAB_003413c5;
            }
          }
          if (*(char *)(param_1 + 0x444) == '\0') {
            lVar8 = portMemAllocNonPaged(0x35c);
            *(long *)(param_2 + 0x270) = lVar8;
            if (lVar8 == 0) {
              iVar3 = 0x51;
              nvCheckOkFailedNoLog
                        (4,0x51,"(pKernelFsp->pCotPayload == NULL) ? NV_ERR_NO_MEMORY : NV_OK",
                         "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x557);
              goto LAB_003413c5;
            }
            portMemSet(lVar8,0,0x35c);
          }
        }
        else if (*(char *)(param_2 + 0x2c8) != '\0') goto LAB_003414bc;
        **(undefined2 **)(param_2 + 0x270) = (short)*(undefined4 *)(param_2 + 0x280);
        *(undefined2 *)(*(long *)(param_2 + 0x270) + 2) = 0x35c;
        if (*(char *)(param_2 + 0x24b) == '\0') {
          lVar8 = *(long *)(param_2 + 0x250);
          if (lVar8 == 0) {
LAB_00341550:
            iVar3 = memdescCreate(param_2 + 0x250,param_1,0x100000,0,1,1,0,0x200000000000);
            if (iVar3 != 0) {
              nvAssertFailedNoLog("status == NV_OK",
                                  "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x570);
              goto LAB_003413c5;
            }
            *(undefined4 *)(*(long *)(param_2 + 0x250) + 0x9c) = 0x29;
            iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x250));
            if (iVar3 != 0) {
              nvAssertFailedNoLog("status == NV_OK",
                                  "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x574);
              goto LAB_003413c5;
            }
            lVar8 = *(long *)(param_2 + 0x250);
          }
          else if (cVar1 == '\0') {
            nvAssertFailedNoLog("pKernelFsp->pSysmemFrtsMemdesc == NULL",
                                "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x56d);
            goto LAB_00341550;
          }
          iVar3 = memdescMap(lVar8,0,0x100000,1,3,&local_58);
          if (iVar3 != 0) {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",
                                0x57a);
            goto LAB_003413c5;
          }
          portMemSet(local_58,0,0x100000);
          memdescSetKernelMapping(*(undefined8 *)(param_2 + 0x250),local_58);
          memdescSetKernelMappingPriv(*(undefined8 *)(param_2 + 0x250),local_50);
          lVar8 = *(long *)(param_2 + 0x270);
          uVar7 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x250),1,0);
          *(undefined8 *)(lVar8 + 0xc) = uVar7;
          *(undefined4 *)(*(long *)(param_2 + 0x270) + 0x14) = 0x100000;
          iVar3 = (**(code **)(param_2 + 0x228))(param_1,param_2);
          if (iVar3 != 0) {
            nvAssertOkFailedNoLog
                      (iVar3,"kfspFrtsSysmemLocationProgram_HAL(pGpu, pKernelFsp)",
                       "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x584);
            goto LAB_003413c5;
          }
        }
        if (iVar4 == 4 || *(char *)(param_2 + 0x24c) != '\0') {
          *(undefined8 *)(*(long *)(param_2 + 0x270) + 0x18) = 0;
          *(undefined4 *)(*(long *)(param_2 + 0x270) + 0x20) = 0;
          if (iVar4 == 4) {
            return 0;
          }
        }
        else {
          uVar5 = (**(code **)(*(long *)(param_1 + 0x1b78) + 0x3b8))(param_1);
          uVar14 = (ulong)uVar5;
          iVar4 = kpmuReservedMemorySizeGet_IMPL(*(undefined8 *)(param_1 + 0x1c28));
          if (iVar4 != 0) {
            lVar8 = (**(code **)(param_2 + 0x210))(param_1,param_2);
            uVar5 = kpmuReservedMemorySizeGet_IMPL(*(undefined8 *)(param_1 + 0x1c28));
            uVar14 = (ulong)uVar5 + lVar8 + uVar14;
          }
          if (*(long *)(param_1 + 0x1ba8) != 0) {
            lVar8 = kgspGetWprEndMargin_IMPL(param_1);
            uVar14 = uVar14 + lVar8;
          }
          *(ulong *)(*(long *)(param_2 + 0x270) + 0x18) = uVar14 + 0x1ffff & 0xfffffffffffe0000;
          *(undefined4 *)(*(long *)(param_2 + 0x270) + 0x20) = 0x100000;
        }
        *(undefined8 *)(*(long *)(param_2 + 0x270) + 4) = 0xffffffffffffffff;
        *(undefined8 *)(*(long *)(param_2 + 0x270) + 0x354) = 0xffffffffffffffff;
        if (*(char *)(param_2 + 0x24d) != '\0') {
          return 0;
        }
        lVar8 = *(long *)(param_2 + 0x270);
        lVar12 = *(long *)(param_1 + 0x1d18);
        local_48 = 0;
        local_40[0] = 0;
        lVar9 = *(long *)(param_1 + 0x1ba8);
        cVar1 = *(char *)(param_1 + 0x4ba);
        if (lVar12 == 0) {
          nvAssertFailedNoLog("pCC != NULL","src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x33f)
          ;
        }
        if (*(char *)(param_2 + 0x24a) == '\0') {
LAB_00341d38:
          iVar3 = 0x57;
          nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x3fe,"kfspSetupGspImages",
                       4,"NVRM: Cannot find correct ucode archive for booting!\n");
          memdescDestroy(*(undefined8 *)(param_2 + 0x260));
        }
        else {
          nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x343,
                       "kfspGetGspUcodeArchive",2,"NVRM: Loading GSP-RM image using FSP.\n");
          cVar2 = (**(code **)(lVar9 + 0x800))(param_1,lVar9);
          if (cVar2 == '\0') {
            if ((lVar12 == 0) || (*(char *)(lVar12 + 0x2a9) == '\0')) {
              lVar12 = (**(code **)(lVar9 + 0x868))(lVar9);
            }
            else {
              lVar12 = (**(code **)(lVar9 + 0x870))(lVar9);
            }
          }
          else {
            if ((lVar12 != 0) && (*(char *)(lVar12 + 0x2a9) != '\0')) goto LAB_00341d38;
            lVar12 = (**(code **)(lVar9 + 0x860))(lVar9);
          }
          if (lVar12 == 0) goto LAB_00341d38;
          lVar9 = bindataArchiveGetStorage(lVar12,0x23);
          lVar10 = bindataArchiveGetStorage(lVar12,0x17);
          lVar11 = bindataArchiveGetStorage(lVar12,0x38);
          lVar12 = bindataArchiveGetStorage(lVar12,0x33);
          if ((((lVar9 == 0) || (lVar10 == 0)) || (lVar11 == 0)) || (lVar12 == 0)) {
            iVar3 = 0x56;
            memdescDestroy(*(undefined8 *)(param_2 + 0x260));
          }
          else {
            iVar4 = bindataGetBufferSize(lVar9);
            lVar13 = *(long *)(param_2 + 0x260);
            uVar5 = iVar4 + 0xfffU & 0xfffff000;
            if (lVar13 == 0) {
LAB_00341922:
              uVar15 = 0;
              iVar3 = memdescCreate(param_2 + 0x260,param_1,uVar5,0,1,1,0,0x200000000000);
              uVar7 = 0x417;
              if (iVar3 == 0) {
                *(undefined4 *)(*(long *)(param_2 + 0x260) + 0x9c) = 0x28;
                iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x260),uVar15,0x417);
                if (iVar3 == 0) {
                  lVar13 = *(long *)(param_2 + 0x260);
                  goto LAB_00341994;
                }
                uVar7 = 0x41b;
              }
            }
            else {
              if (cVar1 == '\0') {
                nvAssertFailedNoLog("pKernelFsp->pGspFmcMemdesc == NULL",
                                    "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x414);
                goto LAB_00341922;
              }
LAB_00341994:
              iVar3 = memdescMap(lVar13,0,uVar5,1,3,&local_48,local_40);
              uVar7 = 0x41f;
              if (iVar3 == 0) {
                portMemSet(local_48,0,uVar5);
                iVar3 = bindataWriteToBuffer(lVar9,local_48,iVar4);
                uVar7 = 0x424;
                if (iVar3 == 0) {
                  memdescUnmap(*(undefined8 *)(param_2 + 0x260),1,local_48,local_40[0]);
                  uVar7 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x260),1,0);
                  *(undefined8 *)(lVar8 + 4) = uVar7;
                  iVar3 = bindataWriteToBuffer(lVar10,lVar8 + 0x24,0x30);
                  uVar7 = 0x42c;
                  if (iVar3 == 0) {
                    iVar4 = bindataGetBufferSize(lVar11);
                    if (iVar4 != *(int *)(param_2 + 0x278)) {
                      nvAssertFailedNoLog("bindataGetBufferSize(pGspImageSignature) == pKernelFsp->cotPayloadSignatureSize"
                                          ,"src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x42e);
                      memdescDestroy(*(undefined8 *)(param_2 + 0x260));
                      *(undefined8 *)(param_2 + 0x260) = 0;
                      return 0;
                    }
                    uVar5 = bindataGetBufferSize(lVar11);
                    if (0x180 < uVar5) {
                      nvAssertFailedNoLog("bindataGetBufferSize(pGspImageSignature) <= sizeof(pCotPayload->signature)"
                                          ,"src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x42f);
                      memdescDestroy(*(undefined8 *)(param_2 + 0x260));
                      *(undefined8 *)(param_2 + 0x260) = 0;
                      return 0;
                    }
                    uVar6 = bindataGetBufferSize(lVar11);
                    iVar3 = bindataWriteToBuffer(lVar11,lVar8 + 0x1d4,uVar6);
                    uVar7 = 0x431;
                    if (iVar3 == 0) {
                      iVar4 = bindataGetBufferSize(lVar12);
                      if (iVar4 != *(int *)(param_2 + 0x27c)) {
                        nvAssertFailedNoLog("bindataGetBufferSize(pGspImagePublicKey) == pKernelFsp->cotPayloadPublicKeySize"
                                            ,"src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x433
                                           );
                        memdescDestroy(*(undefined8 *)(param_2 + 0x260));
                        *(undefined8 *)(param_2 + 0x260) = 0;
                        return 0;
                      }
                      uVar5 = bindataGetBufferSize(lVar12);
                      if (0x180 < uVar5) {
                        nvAssertFailedNoLog("bindataGetBufferSize(pGspImagePublicKey) <= sizeof(pCotPayload->publicKey)"
                                            ,"src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x434
                                           );
                        memdescDestroy(*(undefined8 *)(param_2 + 0x260));
                        *(undefined8 *)(param_2 + 0x260) = 0;
                        return 0;
                      }
                      uVar6 = bindataGetBufferSize(lVar12);
                      iVar3 = bindataWriteToBuffer(lVar12,lVar8 + 0x54,uVar6);
                      if (iVar3 == 0) {
                        if (*(long *)(param_1 + 0x1d18) == 0) {
                          nvAssertFailedNoLog("pCC != NULL",
                                              "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",
                                              0x3c6);
                        }
                        if (*(char *)(param_2 + 0x24a) == '\0') {
                          return 0;
                        }
                        lVar12 = *(long *)(param_1 + 0x1ba8);
                        if (*(long *)(lVar12 + 0xab8) == 0) {
                          nvAssertFailedNoLog("pKernelGsp->pGspFmcArgumentsCached != NULL",
                                              "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",
                                              0x3cd);
                        }
                        else {
                          iVar4 = memdescGetAddressSpace(*(undefined8 *)(lVar12 + 0xab0));
                          if (iVar4 == 1) {
                            uVar7 = memdescGetPhysAddr(*(undefined8 *)(lVar12 + 0xab0),1,0);
                            *(undefined8 *)(lVar8 + 0x354) = uVar7;
                            return 0;
                          }
                          nvAssertFailedNoLog("memdescGetAddressSpace(pKernelGsp->pGspFmcArgumentsDescriptor) == ADDR_SYSMEM"
                                              ,"src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",
                                              0x3ce);
                        }
                        iVar3 = 0x40;
                        nvAssertFailedNoLog("status == NV_OK",
                                            "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x43a)
                        ;
                        memdescDestroy(*(undefined8 *)(param_2 + 0x260));
                        goto LAB_00341caa;
                      }
                      uVar7 = 0x436;
                    }
                  }
                }
              }
            }
            nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",
                                uVar7);
            memdescDestroy(*(undefined8 *)(param_2 + 0x260));
          }
        }
LAB_00341caa:
        *(undefined8 *)(param_2 + 0x260) = 0;
        nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x5db,
                     "kfspPrepareBootCommands_GH100",4,"NVRM: Ucode image preparation failed!\n");
        goto LAB_003413c5;
      }
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4f5,
                   "kfspSafeToSendBootCommands",3,"NVRM: Chain-of-trust is disabled via regkey\n");
      *(undefined1 *)(param_2 + 0x249) = 1;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x4e4,
                   "kfspSafeToSendBootCommands",3,
                   "NVRM: Secure boot is disabled due to missing FSP.\n");
    }
LAB_00341399:
    iVar3 = 0x10006;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x527,
               "kfspPrepareBootCommands_GH100",4,"NVRM: FSP secure boot GSP prechecks failed.\n");
LAB_003413c5:
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x5e4,
               "kfspPrepareBootCommands_GH100",4,
               "NVRM: Preparing FSP boot cmds failed. RM cannot boot.\n");
  kfspCleanupBootState_IMPL(param_1,param_2);
  return iVar3;
}


// ===== 00341f90 kfspSendBootCommands_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspSendBootCommands_GH100(undefined8 param_1,long param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (*(long *)(param_2 + 0x270) == 0) {
    nvAssertFailedNoLog("pKernelFsp->pCotPayload != NULL",
                        "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x60a);
    return 0x40;
  }
  iVar2 = kfspSendAndReadMessage_IMPL();
  if (iVar2 == 0) {
    *(undefined1 *)(param_2 + 0x249) = 1;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x613,"kfspSendBootCommands_GH100",
               4,"NVRM: Sent following content to FSP: \n");
  puVar1 = *(undefined2 **)(param_2 + 0x270);
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x614,"kfspSendBootCommands_GH100",
               4,"NVRM: version=0x%x, size=0x%x, gspFmcSysmemOffset=0x%llx\n",*puVar1,puVar1[1],
               *(undefined8 *)(puVar1 + 2));
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x617,"kfspSendBootCommands_GH100",
               4,"NVRM: frtsSysmemOffset=0x%llx, frtsSysmemSize=0x%x\n",
               *(undefined8 *)(*(long *)(param_2 + 0x270) + 0xc),
               *(undefined4 *)(*(long *)(param_2 + 0x270) + 0x14));
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x619,"kfspSendBootCommands_GH100",
               4,"NVRM: frtsVidmemOffset=0x%llx, frtsVidmemSize=0x%x\n",
               *(undefined8 *)(*(long *)(param_2 + 0x270) + 0x18),
               *(undefined4 *)(*(long *)(param_2 + 0x270) + 0x20));
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x61b,"kfspSendBootCommands_GH100",
               4,"NVRM: gspBootArgsSysmemOffset=0x%llx\n",
               *(undefined8 *)(*(long *)(param_2 + 0x270) + 0x354));
  nvDbg_Printf("src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x631,"kfspSendBootCommands_GH100",
               4,"NVRM: FSP boot cmds failed. RM cannot boot.\n");
  (**(code **)(param_2 + 0x200))(param_1,param_2);
  kfspCleanupBootState_IMPL(param_1,param_2);
  return iVar2;
}


// ===== 00342180 kfspPrepareAndSendBootCommands_GH100 =====

ulong kfspPrepareAndSendBootCommands_GH100(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = kfspPrepareBootCommands_GH100();
  if (uVar1 != 0) {
    uVar2 = (ulong)uVar1;
    if (uVar1 == 0x10006) {
      uVar2 = 0;
    }
    return uVar2;
  }
  uVar2 = kfspSendBootCommands_GH100(param_1,param_2);
  return uVar2;
}


// ===== 003421c0 kfspErrorCode2NvStatusMap_GH100 =====

undefined8 kfspErrorCode2NvStatusMap_GH100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0x9f) {
    uVar1 = 0x57;
  }
  else if (param_3 < 0xa0) {
    uVar1 = 0;
    if (param_3 != 0) {
      uVar1 = 0xffff;
      if (param_3 == 0x9e) {
        uVar1 = 0x25;
      }
      return uVar1;
    }
  }
  else {
    uVar1 = 0x25;
    if (param_3 != 0xa1) {
      uVar1 = 0xffff;
      if (param_3 == 0x1e3) {
        uVar1 = 0x1f;
      }
      return uVar1;
    }
  }
  return uVar1;
}


// ===== 00342220 kfspGetExtraReservedMemorySize_GH100 =====

undefined8 kfspGetExtraReservedMemorySize_GH100(void)

{
  return 0x1000;
}


// ===== 00342230 kfspRequiresBug3957833WAR_GH100 =====

undefined4 kfspRequiresBug3957833WAR_GH100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x8f0334,0);
  return CONCAT31((int3)((uVar1 & 0xfff) >> 8),(uVar1 & 0xfff) < 0x44c);
}


// ===== 00342260 kfspFrtsSysmemLocationProgram_GH100 =====

undefined8 kfspFrtsSysmemLocationProgram_GH100(long param_1,long param_2)

{
  ulong uVar1;
  
  if (*(long *)(param_2 + 0x250) != 0) {
    uVar1 = memdescGetPhysAddr(*(long *)(param_2 + 0x250),1,0);
    regWrite032(param_1 + 0x3a18,0,0,0x14f4,uVar1 & 0xffffffff,0);
    regWrite032(param_1 + 0x3a18,0,0,0x14f8,uVar1 >> 0x20,0);
    regWrite032(param_1 + 0x3a18,0,0,0x14fc,
                (uint)(*(ulong *)(*(long *)(param_2 + 0x250) + 0x30) >> 0xc) & 0xffff | 0x10000,0);
    return 0;
  }
  nvAssertOkFailedNoLog
            (0x40,"(pKernelFsp->pSysmemFrtsMemdesc != NULL)",
             "src/kernel/gpu/fsp/arch/hopper/kern_fsp_gh100.c",0x694);
  return 0x40;
}


// ===== 00342350 kfspFrtsSysmemLocationClear_GH100 =====

void kfspFrtsSysmemLocationClear_GH100(long param_1)

{
  param_1 = param_1 + 0x3a18;
  regWrite032(param_1,0,0,0x14fc,0,0);
  regWrite032(param_1,0,0,0x14f8,0,0);
  regWrite032(param_1,0,0,0x14f4,0,0);
  return;
}


// ===== 003423b0 _kfspWaitForCanSend =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kfspWaitForCanSend(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x180))();
  return;
}


// ===== 003423c0 kfspWaitForResponse =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspWaitForResponse(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  
  do {
    cVar1 = (**(code **)(param_2 + 0x188))(param_1,param_2);
    if (cVar1 != '\0') {
      return 0;
    }
    osSpinLoop();
    iVar2 = timeoutCheck(param_1 + 0x1af0,param_2 + 0x290,0x1d2);
  } while (iVar2 == 0);
  if ((iVar2 == 0x65) && (cVar1 = (**(code **)(param_2 + 0x188))(param_1,param_2), cVar1 != '\0')) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x1a9,"kfspWaitForResponse",4,
               "NVRM: FSP command timed out\n");
  return iVar2;
}


// ===== 00342490 kfspSendMessage =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspSendMessage(undefined8 param_1,long param_2,long param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  ulong uVar8;
  uint uVar9;
  
  uVar4 = (**(code **)(param_2 + 400))();
  uVar1 = param_4 + 8;
  if (uVar4 < param_4 + 8) {
    uVar1 = uVar4;
  }
  puVar7 = (undefined4 *)portMemAllocNonPaged(uVar1);
  if (puVar7 == (undefined4 *)0x0) {
    nvCheckFailedNoLog(4,"pBuffer != NULL","src/kernel/gpu/fsp/kern_fsp.c",0x203);
    iVar6 = 0x51;
  }
  else {
    uVar9 = uVar1 - 8;
    portMemSet(puVar7,0,uVar1);
    uVar3 = (**(code **)(param_2 + 0x1c8))(param_1,param_2,param_5 & 0xff);
    uVar5 = (**(code **)(param_2 + 0x1d0))(param_1,param_2,1,param_4 <= uVar9,uVar3,0);
    *puVar7 = uVar5;
    uVar5 = (**(code **)(param_2 + 0x1d8))(param_1,param_2,param_5);
    uVar1 = uVar9;
    if (param_4 <= uVar9) {
      uVar1 = param_4;
    }
    uVar8 = (ulong)uVar1;
    puVar7[1] = uVar5;
    portMemCopy(puVar7 + 2,uVar9,param_3,uVar8);
    iVar6 = (**(code **)(param_2 + 0x170))(param_1,param_2,puVar7,uVar1 + 8);
    if (((iVar6 == 0) && (uVar9 < param_4)) && (param_4 = param_4 - uVar1, param_4 != 0)) {
      uVar9 = 0;
      uVar1 = uVar4 - 4;
      do {
        uVar2 = param_4;
        if (uVar1 <= param_4) {
          uVar2 = uVar1;
        }
        uVar9 = uVar9 + 1;
        uVar5 = (**(code **)(param_2 + 0x1d0))(param_1,param_2,0,param_4 <= uVar1,uVar3,uVar9 & 3);
        *puVar7 = uVar5;
        portMemCopy(puVar7 + 1,uVar4 - 4,uVar8 + param_3,uVar2);
        iVar6 = (**(code **)(param_2 + 0x170))(param_1,param_2,puVar7,uVar2 + 4);
        if (iVar6 != 0) break;
        uVar8 = (ulong)((int)uVar8 + uVar2);
        param_4 = param_4 - uVar2;
      } while (param_4 != 0);
    }
    portMemFree(puVar7);
  }
  return iVar6;
}


// ===== 003426e0 kfspReadMessage =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspReadMessage(long param_1,long param_2,long param_3,uint param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_41;
  int local_40;
  int local_3c [3];
  
  local_40 = 0;
  cVar1 = (**(code **)(param_2 + 0x188))();
  if (cVar1 == '\0') {
    nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x25d,"kfspReadMessage",3,
                 "NVRM: Tried to read FSP response but none is available\n");
    return 0;
  }
  uVar2 = (**(code **)(param_2 + 0x198))(param_1,param_2);
  lVar4 = portMemAllocNonPaged(uVar2);
  if (lVar4 == 0) {
    nvCheckFailedNoLog(4,"pPacketBuffer != NULL","src/kernel/gpu/fsp/kern_fsp.c",0x263);
    iVar3 = 0x51;
  }
  else {
    if (local_40 - 2U < 2) {
      uVar7 = 0;
      if (param_3 == 0) {
LAB_00342881:
        param_3 = lVar4 + 7;
      }
    }
    else {
      uVar6 = 0;
      do {
        timeoutSet(param_1 + 0x1af0,param_2 + 0x290,0,8);
        iVar3 = kfspWaitForResponse(param_1,param_2);
        if (iVar3 != 0) goto LAB_003428ca;
        iVar3 = (**(code **)(param_2 + 0x178))(param_1,param_2,lVar4,uVar2,local_3c);
        if (iVar3 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar3,
                     "kfspReadPacket_HAL(pGpu, pKernelFsp, pPacketBuffer, recvBufferSize, &packetSize)"
                     ,"src/kernel/gpu/fsp/kern_fsp.c",0x273);
          goto LAB_003428ca;
        }
        iVar3 = (**(code **)(param_2 + 0x1e0))
                          (param_1,param_2,lVar4,local_3c[0],&local_40,&local_41);
        if (iVar3 != 0) goto LAB_003428ca;
        if ((local_40 == 0) || (local_40 == 3)) {
          iVar3 = local_3c[0] + -7;
          if (param_3 != 0) {
            lVar5 = 7;
            goto LAB_00342813;
          }
          if (local_40 == 3) {
            uVar7 = iVar3 + uVar6;
            goto LAB_00342881;
          }
LAB_003429b0:
          nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x28b,"kfspReadMessage",4,
                       "NVRM: No buffer provided when receiving multi-packet message. Buffer needed to reconstruct message\n"
                      );
LAB_00342990:
          iVar3 = 0x1a;
          goto LAB_003428ca;
        }
        if (param_3 == 0) goto LAB_003429b0;
        iVar3 = local_3c[0] + -4;
        lVar5 = 4;
LAB_00342813:
        uVar7 = iVar3 + uVar6;
        if (param_4 < uVar7) {
          nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x294,"kfspReadMessage",4,
                       "NVRM: Buffer provided for message payload too small. Payload size: 0x%x Buffer size: 0x%x\n"
                       ,uVar7,param_4);
          goto LAB_00342990;
        }
        portMemCopy((ulong)uVar6 + param_3,param_4 - uVar6,lVar5 + lVar4,iVar3);
        uVar6 = uVar7;
      } while (1 < local_40 - 2U);
    }
    iVar3 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,param_3,uVar7);
LAB_003428ca:
    portMemFree(lVar4);
  }
  return iVar3;
}


// ===== 003429f0 kfspProcessAsyncResponseCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfspProcessAsyncResponseCallback(void)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = gpumgrGetGpu();
  lVar1 = *(long *)(lVar3 + 0x1d08);
  uVar2 = kfspReadMessage(lVar3,lVar1,*(undefined8 *)(lVar1 + 0x2b8),*(undefined4 *)(lVar1 + 0x2c0))
  ;
  if (*(char *)(lVar1 + 0x285) != '\0') {
    if (*(code **)(lVar1 + 0x2a8) != (code *)0x0) {
      (**(code **)(lVar1 + 0x2a8))(uVar2,*(undefined8 *)(lVar1 + 0x2b0));
    }
    *(undefined1 *)(lVar1 + 0x285) = 0;
    *(undefined8 *)(lVar1 + 0x2a8) = 0;
    *(undefined8 *)(lVar1 + 0x2b0) = 0;
    *(undefined8 *)(lVar1 + 0x2b8) = 0;
    *(undefined4 *)(lVar1 + 0x2c0) = 0;
  }
  return;
}


// ===== 00342a80 kfspPollForAsyncResponse =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfspPollForAsyncResponse(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  lVar1 = *(long *)(param_1 + 0x1d08);
  if (*(char *)(lVar1 + 0x285) == '\0') {
    return 0;
  }
  iVar3 = timeoutCheck(param_1 + 0x1af0,lVar1 + 0x290,0x1d2);
  cVar2 = (**(code **)(lVar1 + 0x188))(param_1,lVar1);
  if (cVar2 == '\0') {
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x34d,"kfspPollForAsyncResponse",4,
                   "NVRM: FSP async command timed out\n");
      cVar2 = *(char *)(lVar1 + 0x285);
      goto joined_r0x00342c5f;
    }
    iVar3 = tmrEventScheduleRel_IMPL(param_2,param_3,50000000);
    if (iVar3 == 0) {
      return 0;
    }
    pcVar5 = "NVRM: Failed to reschedule callback, status=%x\n";
    uVar4 = 0x355;
  }
  else {
    iVar3 = osQueueWorkItem(param_1,kfspProcessAsyncResponseCallback,0,0x88);
    if (iVar3 == 0) {
      return 0;
    }
    pcVar5 = "NVRM: Failed to schedule work item, status=%x\n";
    uVar4 = 0x343;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",uVar4,"kfspPollForAsyncResponse",4,pcVar5,iVar3);
  cVar2 = *(char *)(lVar1 + 0x285);
joined_r0x00342c5f:
  if (cVar2 == '\0') {
    return iVar3;
  }
  if (*(code **)(lVar1 + 0x2a8) != (code *)0x0) {
    (**(code **)(lVar1 + 0x2a8))(iVar3,*(undefined8 *)(lVar1 + 0x2b0));
  }
  *(undefined1 *)(lVar1 + 0x285) = 0;
  *(undefined8 *)(lVar1 + 0x2a8) = 0;
  *(undefined8 *)(lVar1 + 0x2b0) = 0;
  *(undefined8 *)(lVar1 + 0x2b8) = 0;
  *(undefined4 *)(lVar1 + 0x2c0) = 0;
  return iVar3;
}


// ===== 00342c70 kfspConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfspConstructEngine_IMPL(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  undefined8 uVar4;
  uint local_1c;
  
  local_1c = 0;
  iVar1 = osReadRegistryDword(param_1,"RmDisableFsp",&local_1c);
  if ((((iVar1 == 0) && (local_1c == 1)) && (*(char *)(param_1 + 0x446) != '\0')) ||
     ((*(char *)(param_1 + 0x4910) != '\0' || (*(char *)(param_1 + 0x4911) != '\0')))) {
    nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x7f,"kfspInitRegistryOverrides",3,
                 "NVRM: FSP disabled due to regkey override.\n");
    *(undefined1 *)(param_2 + 0x50) = 1;
  }
  iVar1 = osReadRegistryDword(param_1,"RmDisableCotCmd",&local_1c);
  if (iVar1 == 0) {
    if ((local_1c & 3) != 0) {
      *(undefined1 *)(param_2 + 0x24b) = 1;
    }
    if ((local_1c & 0xc) != 0) {
      *(undefined1 *)(param_2 + 0x24c) = 1;
    }
    if ((local_1c & 0x30) != 0) {
      *(undefined1 *)(param_2 + 0x24d) = 1;
    }
  }
  if (((*(char *)(param_1 + 1099) != '\0') || (*(char *)(param_1 + 0x44d) != '\0')) ||
     (*(char *)(param_1 + 0x4921) != '\0')) {
    *(undefined1 *)(param_2 + 0x24c) = 1;
  }
  iVar1 = osReadRegistryDword(param_1,"RmDisableFspFuseErrorCheck",&local_1c);
  if ((iVar1 == 0) && (local_1c == 1)) {
    nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0xa1,"kfspInitRegistryOverrides",4,
                 "NVRM: FSP\'s fuse error detection status check during boot is disabled using the regkey.\n"
                );
    *(undefined1 *)(param_2 + 0x248) = 0;
  }
  iVar1 = osReadRegistryDword(param_1,"RmFspUseMnoc",&local_1c);
  if (iVar1 == 0) {
    if ((local_1c & 1) != 0) {
      nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0xaa,"kfspInitRegistryOverrides",4,
                   "NVRM: CPU will use MNOC mailbox to communicate with FSP\n");
      *(undefined1 *)(param_2 + 0x24e) = 1;
    }
    if ((local_1c & 2) != 0) {
      nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0xaf,"kfspInitRegistryOverrides",4,
                   "NVRM: GSP will use MNOC MCTP to communicate with FSP\n");
      *(undefined1 *)(param_2 + 0x24f) = 1;
    }
  }
  if (*(char *)(param_2 + 0x50) != '\0') {
    nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x57,"kfspConstructEngine_IMPL",3,
                 "NVRM: KernelFsp is disabled\n");
    return 0x57;
  }
  *(undefined1 *)(param_2 + 0x285) = 0;
  *(undefined8 *)(param_2 + 0x2a8) = 0;
  *(undefined8 *)(param_2 + 0x2b0) = 0;
  *(undefined8 *)(param_2 + 0x2b8) = 0;
  *(undefined4 *)(param_2 + 0x2c0) = 0;
  uVar2 = tmrEventCreate_IMPL(*(undefined8 *)(param_1 + 0x1b88),param_2 + 0x288,
                              kfspPollForAsyncResponse,0,0);
  uVar4 = 0x5e;
  pcVar3 = 
  "tmrEventCreate(pTmr, &(pKernelFsp->pPollEvent), kfspPollForAsyncResponse, NULL, TMR_FLAGS_NONE)";
  if ((int)uVar2 == 0) {
    uVar2 = (**(code **)(param_2 + 0x168))
                      (param_1,param_2,
                       "tmrEventCreate(pTmr, &(pKernelFsp->pPollEvent), kfspPollForAsyncResponse, NULL, TMR_FLAGS_NONE)"
                       ,"src/kernel/gpu/fsp/kern_fsp.c",0x5e);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    uVar4 = 99;
    pcVar3 = "kfspConstructHal_HAL(pGpu, pKernelFsp)";
  }
  nvCheckOkFailedNoLog(4,uVar2 & 0xffffffff,pcVar3,"src/kernel/gpu/fsp/kern_fsp.c",uVar4);
  return uVar2 & 0xffffffff;
}


// ===== 00342f90 kfspReleaseProxyImage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfspReleaseProxyImage_IMPL(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 0x4ba) == '\0') {
    uVar3 = 1;
    if (*(long *)(param_2 + 0x250) == 0) goto LAB_0034309a;
    (**(code **)(param_2 + 0x230))(param_1,param_2);
    uVar1 = memdescGetKernelMappingPriv(*(undefined8 *)(param_2 + 0x250));
    uVar2 = memdescGetKernelMapping(*(undefined8 *)(param_2 + 0x250));
    memdescUnmap(*(undefined8 *)(param_2 + 0x250),1,uVar2,uVar1);
  }
  else {
    if (*(long *)(param_2 + 0x250) == 0) {
      uVar3 = param_3 & 1 ^ 1;
LAB_0034309a:
      if (*(char *)(param_1 + 0x459) != '\0') {
        if (*(int *)(param_1 + 0x4b34) == 1) {
          return;
        }
        if (uVar3 == 0) {
          return;
        }
      }
      goto LAB_0034302f;
    }
    (**(code **)(param_2 + 0x230))();
    uVar1 = memdescGetKernelMappingPriv(*(undefined8 *)(param_2 + 0x250));
    uVar2 = memdescGetKernelMapping(*(undefined8 *)(param_2 + 0x250));
    memdescUnmap(*(undefined8 *)(param_2 + 0x250),1,uVar2,uVar1);
    if ((param_3 & 1) != 0) {
      if (*(char *)(param_1 + 0x459) != '\0') {
        return;
      }
      goto LAB_0034302f;
    }
  }
  memdescFree(*(undefined8 *)(param_2 + 0x250));
  memdescDestroy(*(undefined8 *)(param_2 + 0x250));
  *(undefined8 *)(param_2 + 0x250) = 0;
  if ((*(char *)(param_1 + 0x459) != '\0') && (*(int *)(param_1 + 0x4b34) == 1)) {
    return;
  }
LAB_0034302f:
  if (*(long *)(param_2 + 0x260) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x260));
    *(undefined8 *)(param_2 + 0x260) = 0;
  }
  if (*(long *)(param_2 + 0x268) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x268));
    *(undefined8 *)(param_2 + 0x268) = 0;
  }
  return;
}


// ===== 00343170 kfspCleanupBootState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfspCleanupBootState_IMPL(long param_1,long param_2)

{
  int iVar1;
  
  tmrEventDestroy_IMPL(*(undefined8 *)(param_1 + 0x1b88),*(undefined8 *)(param_2 + 0x288));
  portMemFree(*(undefined8 *)(param_2 + 0x270));
  *(undefined8 *)(param_2 + 0x270) = 0;
  kfspReleaseProxyImage_IMPL(param_1,param_2,0);
  if (*(char *)(param_2 + 0x2c8) != '\0') {
    iVar1 = (**(code **)(param_2 + 0x240))(param_1,param_2,0);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x112,"kfspCleanupBootState_IMPL",4,
                   "NVRM: Clock boost disbalement via FSP failed with error 0x%x\n",iVar1);
      return;
    }
  }
  return;
}


// ===== 00343210 kfspStateUnload_IMPL =====

undefined8 kfspStateUnload_IMPL(void)

{
  kfspReleaseProxyImage_IMPL();
  return 0;
}


// ===== 00343230 kfspStateDestroy_IMPL =====

void kfspStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  kfspCleanupBootState_IMPL();
  if (*(long *)(param_2 + 600) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 600));
    *(undefined8 *)(param_2 + 600) = 0;
  }
  return;
}


// ===== 00343280 kfspPollForCanSend_IMPL =====

int kfspPollForCanSend_IMPL(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_30 [24];
  
  timeoutSet(param_1 + 0x1af0,local_30,0,8);
  iVar1 = timeoutCondWait(param_1 + 0x1af0,local_30,_kfspWaitForCanSend,param_2,0x16c);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x16f,"kfspPollForCanSend_IMPL",4,
               "NVRM: Timed out waiting for FSP queues to be empty.\n");
  return iVar1;
}


// ===== 00343320 kfspSendAndReadMessage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfspSendAndReadMessage_IMPL
               (long param_1,long param_2,undefined8 param_3,undefined4 param_4,ulong param_5,
               undefined8 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  
  uVar3 = param_5;
  if (*(char *)(param_2 + 0x285) != '\0') {
    iVar1 = kfspWaitForResponse();
    uVar3 = param_5 & 0xffffffff;
    if (iVar1 == 0) {
      uVar2 = kfspReadMessage(param_1,param_2,*(undefined8 *)(param_2 + 0x2b8),
                              *(undefined4 *)(param_2 + 0x2c0));
      uVar3 = param_5 & 0xffffffff;
      if (*(char *)(param_2 + 0x285) == '\0') goto LAB_00343352;
      if (*(code **)(param_2 + 0x2a8) != (code *)0x0) {
        (**(code **)(param_2 + 0x2a8))(uVar2,*(undefined8 *)(param_2 + 0x2b0));
      }
    }
    else {
      if (*(char *)(param_2 + 0x285) == '\0') goto LAB_00343352;
      if (*(code **)(param_2 + 0x2a8) != (code *)0x0) {
        (**(code **)(param_2 + 0x2a8))(iVar1,*(undefined8 *)(param_2 + 0x2b0));
      }
    }
    uVar3 = param_5 & 0xffffffff;
    *(undefined1 *)(param_2 + 0x285) = 0;
    *(undefined8 *)(param_2 + 0x2a8) = 0;
    *(undefined8 *)(param_2 + 0x2b0) = 0;
    *(undefined8 *)(param_2 + 0x2b8) = 0;
    *(undefined4 *)(param_2 + 0x2c0) = 0;
  }
LAB_00343352:
  iVar1 = kfspSendMessage(param_1,param_2,param_3,param_4,uVar3);
  if (iVar1 == 0) {
    timeoutSet(param_1 + 0x1af0,param_2 + 0x290,0,8);
    iVar1 = kfspWaitForResponse(param_1,param_2);
    if (iVar1 == 0) {
      kfspReadMessage(param_1,param_2,param_6,param_7);
      return;
    }
  }
  return;
}


// ===== 003434b0 kfspSendAndReadMessageAsync_IMPL =====

int kfspSendAndReadMessageAsync_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined8 in_R9;
  undefined4 in_stack_00000008;
  undefined8 in_stack_00000010;
  undefined8 in_stack_00000018;
  
  if (*(char *)(param_2 + 0x285) != '\0') {
    return 3;
  }
  iVar1 = kfspSendMessage();
  if (iVar1 == 0) {
    if (*(char *)(param_2 + 0x285) == '\0') {
      iVar1 = tmrEventScheduleRel_IMPL
                        (*(undefined8 *)(param_1 + 0x1b88),*(undefined8 *)(param_2 + 0x288),50000000
                        );
      if (iVar1 == 0) {
        *(undefined8 *)(param_2 + 0x2b8) = in_R9;
        *(undefined8 *)(param_2 + 0x2a8) = in_stack_00000010;
        *(undefined8 *)(param_2 + 0x2b0) = in_stack_00000018;
        *(undefined4 *)(param_2 + 0x2c0) = in_stack_00000008;
        timeoutSet(param_1 + 0x1af0,param_2 + 0x290,0,8);
        *(undefined1 *)(param_2 + 0x285) = 1;
        return 0;
      }
    }
    else {
      iVar1 = 0x17;
    }
    nvDbg_Printf("src/kernel/gpu/fsp/kern_fsp.c",0x315,"kfspSendAndReadMessageAsync_IMPL",4,
                 "NVRM: FSP queuing failed, status=%x\n",iVar1);
    return iVar1;
  }
  return iVar1;
}


// ===== 003435f0 gpuGetNextInEngineOrderList =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuGetNextInEngineOrderList(long param_1,uint *param_2,uint *param_3)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  long lVar4;
  int *piVar5;
  byte bVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int local_3c [3];
  
  uVar10 = param_2[2];
  lVar4 = (**(code **)(param_1 + 0x228))(param_1,local_3c);
  uVar10 = uVar10 & 0xc;
  if ((char)param_2[3] == '\0') {
    uVar8 = local_3c[0] - 1;
    *(undefined1 *)(param_2 + 3) = 1;
    if (uVar10 == 0) {
      uVar8 = 0;
    }
    bVar3 = true;
    *param_2 = uVar8;
  }
  else {
    uVar8 = *param_2;
    bVar3 = false;
  }
  bVar2 = false;
  do {
    if ((local_3c[0] <= (int)uVar8) || ((int)uVar8 < 0)) {
      return 0;
    }
    piVar1 = (int *)(lVar4 + (ulong)uVar8 * 8);
    if ((param_2[2] == (piVar1[1] & param_2[2])) && (*(uint *)(param_1 + 0x890) != 0)) {
      piVar5 = *(int **)(param_1 + 0x888);
      piVar7 = piVar5 + (ulong)*(uint *)(param_1 + 0x890) * 4;
      do {
        if (*piVar1 == *piVar5) {
          if (bVar2 || bVar3) {
            if (uVar10 == 0) {
              bVar6 = 1;
              uVar9 = 0;
            }
            else {
              uVar9 = piVar5[1] - 1;
              bVar6 = (byte)((uint)-piVar5[1] >> 0x1f);
            }
            param_2[1] = uVar9;
          }
          else {
            uVar9 = param_2[1];
            bVar6 = (byte)~(byte)(uVar9 >> 0x18) >> 7;
          }
          if (((int)uVar9 < piVar5[1]) && (bVar6 != 0)) {
            *param_3 = *piVar1 << 8 | uVar9;
            param_2[1] = param_2[1] + (-(uint)(uVar10 != 0) | 1);
            return 1;
          }
          break;
        }
        piVar5 = piVar5 + 4;
      } while (piVar7 != piVar5);
    }
    uVar8 = uVar8 + (-(uint)(uVar10 != 0) | 1);
    bVar2 = true;
    *param_2 = uVar8;
  } while( true );
}


// ===== 00343740 _gpuSetResetRequiredState =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gpuSetResetRequiredState(long param_1,byte param_2)

{
  int iVar1;
  byte local_29 [9];
  
  iVar1 = (**(code **)(param_1 + 0x110))(param_1,local_29);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_1 + 0xe8))(param_1,param_2);
    if ((iVar1 == 0) && (local_29[0] != param_2)) {
      (**(code **)(param_1 + 0xf8))(param_1,param_2);
    }
  }
  return;
}


// ===== 003437b0 _gpuSetDrainAndResetState =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong _gpuSetDrainAndResetState(long param_1,byte param_2)

{
  ulong uVar1;
  byte local_19;
  
  uVar1 = (**(code **)(param_1 + 0x138))(param_1,&local_19);
  if ((int)uVar1 == 0) {
    uVar1 = (**(code **)(param_1 + 0x118))(param_1,param_2);
    if (((int)uVar1 == 0) && (local_19 != param_2)) {
      (**(code **)(param_1 + 0x140))(param_1,0,*(code **)(param_1 + 0x140));
      uVar1 = uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}


// ===== 00343820 gpuXlateHalImplToArchImpl =====

void gpuXlateHalImplToArchImpl(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == 0x32) {
    *param_2 = 400;
    *param_3 = 2;
    return;
  }
  if (param_1 < 0x33) {
    if (param_1 == 0x24) {
      *param_2 = 0x150;
      *param_3 = 0xb;
      return;
    }
    if (param_1 < 0x25) {
      if (param_1 == 0x1e) {
        *param_2 = 0x130;
        *param_3 = 2;
        return;
      }
      if (0x1e < param_1) {
        if (param_1 == 0x21) {
          *param_2 = 0x130;
          *param_3 = 7;
          return;
        }
        if (0x21 < param_1) {
          if (param_1 != 0x22) {
            *param_2 = 0x140;
            *param_3 = 0;
            return;
          }
          *param_2 = 0x130;
          *param_3 = 8;
          return;
        }
        if (param_1 != 0x1f) {
          *param_2 = 0x130;
          *param_3 = 6;
          return;
        }
        *param_2 = 0x130;
        *param_3 = 4;
        return;
      }
      if (param_1 == 0x1b) {
        *param_2 = 0x120;
        *param_3 = 4;
        return;
      }
      if (0x1b < param_1) {
        if (param_1 != 0x1c) {
          *param_2 = 0x130;
          *param_3 = 0;
          return;
        }
        *param_2 = 0x120;
        *param_3 = 6;
        return;
      }
      if (param_1 == 0x19) {
        *param_2 = 0x110;
        *param_3 = 8;
        return;
      }
      if (param_1 == 0x1a) {
        *param_2 = 0x120;
        *param_3 = 0;
        return;
      }
      if (param_1 == 0x18) {
        *param_2 = 0x110;
        *param_3 = 7;
        return;
      }
    }
    else {
      if (param_1 == 0x2b) {
        *param_2 = 0x170;
        *param_3 = 2;
        return;
      }
      if (param_1 < 0x2c) {
        if (param_1 == 0x28) {
          *param_2 = 0x160;
          *param_3 = 8;
          return;
        }
        if (0x28 < param_1) {
          if (param_1 != 0x29) {
            *param_2 = 0x170;
            *param_3 = 0;
            return;
          }
          *param_2 = 0x160;
          *param_3 = 7;
          return;
        }
        if (param_1 == 0x26) {
          *param_2 = 0x160;
          *param_3 = 4;
          return;
        }
        if (param_1 != 0x27) {
          *param_2 = 0x160;
          *param_3 = 2;
          return;
        }
        *param_2 = 0x160;
        *param_3 = 6;
        return;
      }
      if (param_1 == 0x2e) {
        *param_2 = 0x170;
        *param_3 = 6;
        return;
      }
      if (param_1 < 0x2f) {
        if (param_1 != 0x2c) {
          *param_2 = 0x170;
          *param_3 = 4;
          return;
        }
        *param_2 = 0x170;
        *param_3 = 3;
        return;
      }
      if (param_1 == 0x2f) {
        *param_2 = 0x170;
        *param_3 = 7;
        return;
      }
      if (param_1 == 0x31) {
        *param_2 = 0x170;
        *param_3 = 0xf;
        return;
      }
    }
  }
  else {
    if (param_1 == 0x3f) {
      *param_2 = 0x1b0;
      *param_3 = 5;
      return;
    }
    if (param_1 < 0x40) {
      if (param_1 == 0x39) {
        *param_2 = 0x1a0;
        *param_3 = 2;
        return;
      }
      if (0x39 < param_1) {
        if (param_1 == 0x3c) {
          *param_2 = 0x1a0;
          *param_3 = 4;
          return;
        }
        if (0x3c < param_1) {
          if (param_1 != 0x3d) {
            *param_2 = 0x1b0;
            *param_3 = 3;
            return;
          }
          *param_2 = 0x1b0;
          *param_3 = 2;
          return;
        }
        if (param_1 != 0x3a) {
          *param_2 = 0x1a0;
          *param_3 = 3;
          return;
        }
        *param_2 = 0x1a0;
        *param_3 = 0xb;
        return;
      }
      if (param_1 == 0x36) {
        *param_2 = 400;
        *param_3 = 7;
        return;
      }
      if (param_1 < 0x37) {
        if (param_1 == 0x34) {
          *param_2 = 400;
          *param_3 = 4;
          return;
        }
        if (param_1 != 0x35) {
          *param_2 = 400;
          *param_3 = 3;
          return;
        }
        *param_2 = 400;
        *param_3 = 6;
        return;
      }
      if (param_1 != 0x37) {
        *param_2 = 0x1a0;
        *param_3 = 0;
        return;
      }
      *param_2 = 0x180;
      *param_3 = 0;
      return;
    }
    if (param_1 == 0x47) {
      *param_2 = 0xe0000021;
      *param_3 = 0;
      return;
    }
    if (param_1 < 0x48) {
      if (param_1 == 0x43) {
        *param_2 = 0x1b0;
        *param_3 = 0xc;
        return;
      }
      if (param_1 < 0x44) {
        if (param_1 == 0x41) {
          *param_2 = 0x1b0;
          *param_3 = 7;
          return;
        }
        if (param_1 != 0x42) {
          *param_2 = 0x1b0;
          *param_3 = 6;
          return;
        }
        *param_2 = 0x1b0;
        *param_3 = 0xb;
        return;
      }
      if (param_1 == 0x45) {
        *param_2 = 0xe0000040;
        *param_3 = 0;
        return;
      }
      if (param_1 == 0x46) {
        *param_2 = 0xe0000013;
        *param_3 = 0;
        return;
      }
    }
    else {
      if (param_1 == 0x4e) {
        *param_2 = 0xe0000023;
        *param_3 = 5;
        return;
      }
      if (param_1 < 0x4f) {
        if (param_1 == 0x48) {
          *param_2 = 0xe0000018;
          *param_3 = 0;
          return;
        }
        if (param_1 == 0x49) {
          *param_2 = 0xe0000019;
          *param_3 = 0;
          return;
        }
      }
      else {
        if (param_1 == 0x4f) {
          *param_2 = 0xe0000026;
          *param_3 = 5;
          return;
        }
        if (param_1 == 0x50) {
          *param_2 = 0x1f0;
          *param_3 = 0;
          return;
        }
      }
    }
  }
  *param_2 = 0;
  *param_3 = 0;
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x12a6,"gpuXlateHalImplToArchImpl",4,"NVRM: Invalid halimpl\n"
              );
  return;
}


// ===== 00343d60 _gpuRmApiAllocWithHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gpuRmApiAllocWithHandle
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6)

{
  long lVar1;
  
  do {
    lVar1 = rmapiGetInterface(4);
  } while (*(code **)(lVar1 + 8) == _gpuRmApiAllocWithHandle);
  (**(code **)(lVar1 + 8))(lVar1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00343dc5 _gpuRmApiControl.cold =====

void _gpuRmApiControl_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00343dd0 _gpuRmApiControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _gpuRmApiControl(long param_1,int param_2,int param_3,undefined4 param_4,undefined8 param_5,
                    int param_6)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined1 *local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 *local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  int *local_d8;
  int local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  int local_98;
  long local_90;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined1 local_48;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  local_168 = 0;
  local_160 = 0;
  local_158 = 0;
  local_150 = 0;
  local_148 = 0;
  local_140 = 0;
  local_138 = 0;
  local_130 = 0;
  local_128 = 0;
  if ((*(char *)(lVar1 + 0x909) != '\0') || (*(char *)(lVar1 + 0x90a) != '\0')) {
    nvAssertFailedNoLog("!IS_FW_CLIENT(pGpu)","src/kernel/gpu/gpu.c",0x2f8);
    return 0x40;
  }
  if (((*(char *)(lVar1 + 0x908) == '\0') && (*(int *)(lVar1 + 0x3b34) == param_2)) &&
     (*(int *)(lVar1 + 0x3b3c) == param_3)) {
    if ((*(long *)(lVar1 + 0x3b48) == 0) || (*(long *)(lVar1 + 0x3b50) == 0)) {
      nvAssertFailedNoLog("pGpu->pCachedSubdevice && pGpu->pCachedRsClient","src/kernel/gpu/gpu.c",
                          0x307);
      return 0x40;
    }
    puVar7 = (undefined8 *)objGetExportedMethodDef_IMPL(*(long *)(lVar1 + 0x3b48),param_4);
    if (puVar7 == (undefined8 *)0x0) {
      iVar4 = 0x56;
      nvAssertFailedNoLog("pEntry != NULL","src/kernel/gpu/gpu.c",0x30c);
    }
    else if (*(int *)((long)puVar7 + 0x14) == param_6) {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x30f,"_gpuRmApiControl",1,
                   "NVRM: GPU Internal RM control 0x%08x on gpuInst:%x hClient:0x%08x hSubdevice:0x%08x\n"
                   ,param_4,*(undefined4 *)(lVar1 + 0x7a4),param_2,param_3);
      portMemSet(&local_b0,0,0x78);
      local_48 = 1;
      local_78 = 0x100000002;
      local_58 = &local_160;
      local_a4 = 2;
      local_138 = CONCAT44(local_138._4_4_,6);
      local_b0 = param_2;
      local_ac = param_3;
      local_a8 = param_4;
      local_a0 = param_5;
      local_98 = param_6;
      local_90 = lVar1;
      portMemSet(&local_120,0,0x70);
      if (*(long *)(lVar1 + 0x3b48) == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      local_120 = g_resServ;
      local_110 = *(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x3b48) + 0x140) + 0x48);
      local_118 = *(undefined8 *)(lVar1 + 0x3b50);
      local_f8 = local_78;
      local_f0 = local_70;
      local_e8 = local_68;
      local_e0 = local_60;
      local_d8 = &local_b0;
      local_100 = local_58;
      iVar4 = resservSwapTlsCallContext(&local_168,&local_120);
      if (iVar4 == 0) {
        if (*(int *)((long)puVar7 + 0x14) == 0) {
          iVar4 = (*(code *)*puVar7)(*(undefined8 *)(lVar1 + 0x3b48));
        }
        else {
          iVar4 = (*(code *)*puVar7)(*(undefined8 *)(lVar1 + 0x3b48),param_5);
        }
        iVar5 = resservRestoreTlsCallContext(local_168);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,"resservRestoreTlsCallContext(oldCtx)","src/kernel/gpu/gpu.c",0x334);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,"resservSwapTlsCallContext(&oldCtx, &callCtx)","src/kernel/gpu/gpu.c",0x329
                  );
      }
    }
    else {
      iVar4 = 0x3a;
      nvAssertFailedNoLog("pEntry->paramSize == paramsSize","src/kernel/gpu/gpu.c",0x30e);
    }
  }
  else {
    lVar6 = rmapiGetInterface(4);
    cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
    if (cVar3 == '\0') {
      iVar4 = 0x2f;
      nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)","src/kernel/gpu/gpu.c",0x339);
    }
    else {
      if (*(code **)(lVar6 + 0x38) != _gpuRmApiControl) {
        iVar4 = (**(code **)(lVar6 + 0x38))(lVar6,param_2,param_3,param_4,param_5,param_6);
        return iVar4;
      }
      iVar4 = _gpuRmApiControl();
    }
  }
  return iVar4;
}


// ===== 003442a0 gpuCreateObject =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuCreateObject(long param_1,int param_2,uint param_3,long *param_4)

{
  uint uVar1;
  int *piVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  int *piVar6;
  int *piVar7;
  long local_48;
  undefined1 local_40 [24];
  
  local_48 = 0;
  if (*(uint *)(param_1 + 0x890) != 0) {
    piVar7 = *(int **)(param_1 + 0x888);
    piVar6 = piVar7 + (ulong)*(uint *)(param_1 + 0x890) * 4;
    piVar2 = piVar7;
    do {
      if (param_2 == *piVar2) {
        if ((uint)piVar2[1] <= param_3) {
          return 0;
        }
        while (param_2 != *piVar7) {
          piVar7 = piVar7 + 4;
          if (piVar7 == piVar6) {
            nvAssertOkFailedNoLog
                      (0x40,"_gpuChildNvocClassInfoGet(pGpu, classId, &pClassInfo)",
                       "src/kernel/gpu/gpu.c",0x5b5);
            return 0x40;
          }
        }
        uVar3 = __nvoc_objCreateDynamic(&local_48,param_1,*(undefined8 *)(piVar7 + 2),0);
        if ((int)uVar3 == 0) {
          if (local_48 == 0) {
            nvAssertFailedNoLog("pConcreteChild != NULL","src/kernel/gpu/gpu.c",0x5bf);
            return 0x40;
          }
          lVar4 = objDynamicCastById_IMPL(local_48,param_2);
          *param_4 = lVar4;
          if (lVar4 == 0) {
            nvAssertOkFailedNoLog(0x40,"(*ppChildPtr != NULL)","src/kernel/gpu/gpu.c",0x5c6);
            __nvoc_objDelete(local_48);
            *param_4 = 0;
            return 0x40;
          }
          plVar5 = (long *)__nvoc_dynamicCast(lVar4,__nvoc_class_def_OBJENGSTATE);
          if (plVar5 == (long *)0x0) {
            __nvoc_objDelete(local_48);
            *param_4 = 0;
            return 0x40;
          }
          param_3 = param_2 << 8 | param_3;
          uVar1 = engstateConstructBase_IMPL(plVar5,param_1,param_3);
          if (uVar1 == 0) {
            engstateLogStateTransitionPre_IMPL(plVar5,1,local_40);
            uVar1 = (**(code **)(*plVar5 + 0x30))(param_1,plVar5,param_3);
            engstateLogStateTransitionPost_IMPL(plVar5,1,local_40);
            if ((char)plVar5[9] != '\0') {
              __nvoc_objDelete(local_48);
              *param_4 = 0;
              return 0;
            }
            if (uVar1 == 0) {
              return 0;
            }
          }
          else {
            nvCheckFailedNoLog(1,"status == NV_OK","src/kernel/gpu/gpu.c",0x5d4);
          }
          __nvoc_objDelete(local_48);
          *param_4 = 0;
          uVar3 = (ulong)uVar1;
          if (uVar1 == 0x56) {
            uVar3 = 0;
          }
        }
        return uVar3;
      }
      piVar2 = piVar2 + 4;
    } while (piVar2 != piVar6);
  }
  return 0;
}


// ===== 00344530 __pfx_gpuDestroyMissingEngine =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __pfx_gpuDestroyMissingEngine(long param_1,long *param_2)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = fullyDeriveWrapper(param_2);
  (**(code **)(*param_2 + 0x38))(param_1);
  __nvoc_objDelete(lVar1);
  uVar2 = 0;
  do {
    if (*(long *)(param_1 + 7000 + uVar2 * 8) == lVar1) {
      *(undefined8 *)(param_1 + 7000 + (uVar2 & 0xffffffff) * 8) = 0;
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x3f);
  return;
}


// ===== 00344540 gpuDestroyMissingEngine =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuDestroyMissingEngine(long param_1,long *param_2)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = fullyDeriveWrapper(param_2);
  (**(code **)(*param_2 + 0x38))(param_1);
  __nvoc_objDelete(lVar1);
  uVar2 = 0;
  do {
    if (*(long *)(param_1 + 7000 + uVar2 * 8) == lVar1) {
      *(undefined8 *)(param_1 + 7000 + (uVar2 & 0xffffffff) * 8) = 0;
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0x3f);
  return;
}


// ===== 003445b0 _gpuSetDisconnectedPropertiesWorker =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void _gpuSetDisconnectedPropertiesWorker(void)

{
  long lVar1;
  
  lVar1 = gpumgrGetGpu();
  (**(code **)(lVar1 + 0x140))(lVar1,0,*(code **)(lVar1 + 0x140));
  return;
}


// ===== 003445d0 _gpuRefreshRecoveryActionInLock =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long _gpuRefreshRecoveryActionInLock(undefined8 param_1,char *param_2)

{
  uint uVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  char cVar7;
  uint uVar8;
  char local_2a;
  char local_29;
  
  lVar2 = g_pSys;
  cVar7 = '\0';
  lVar4 = gpumgrGetGpu();
  if (param_2 != (char *)0x0) {
    cVar7 = *param_2;
  }
  lVar5 = lVar4;
  if (lVar4 != 0) {
    if ((*(char *)(lVar2 + 0x86) == '\0') && (*(char *)(lVar4 + 0x4b8) == '\0')) {
      lVar5 = (**(code **)(lVar4 + 0x110))(lVar4,&local_2a);
      if ((*(char *)(lVar4 + 0x44c) == '\0') || (((int)lVar5 == 0 && (local_2a != '\0')))) {
        uVar8 = 1;
      }
      else {
        cVar3 = '\0';
        if (*(long *)(lVar2 + 0x260) != 0) {
          cVar3 = fabricIsMemAllocDisabled_IMPL();
        }
        lVar5 = (**(code **)(lVar4 + 0x138))(lVar4,&local_29);
        if ((((int)lVar5 != 0) || (uVar8 = 4, local_29 == '\0')) &&
           (uVar8 = 3, *(char *)(lVar4 + 0x4b7) == '\0')) {
          uVar8 = -(uint)(cVar3 != '\0') & 5;
        }
      }
    }
    else {
      uVar8 = 2;
    }
    uVar1 = *(uint *)(lVar4 + 0x4d0);
    if ((uVar1 != uVar8) && (*(uint *)(lVar4 + 0x4d0) = uVar8, uVar1 != 0xff)) {
      lVar5 = gpuNotifySubDeviceEvent_IMPL(lVar4,0xc0,0,0,0,uVar8);
      if (cVar7 == '\0') {
        lVar2 = *(long *)(CSWTCH_446 + (ulong)uVar8 * 8);
        if (uVar1 < 6) {
          pcVar6 = *(char **)(CSWTCH_446 + (ulong)uVar1 * 8);
        }
        else {
          nvAssertFailedNoLog("Unknown recovery action!","src/kernel/gpu/gpu.c",0x1be4);
          pcVar6 = "Unknown";
        }
        nvErrorLog_va(lVar4,0x9a,"GPU recovery action changed from 0x%x (%s) to 0x%x (%s)",uVar1,
                      pcVar6,uVar8);
        return lVar2;
      }
    }
  }
  return lVar5;
}


// ===== 00344780 gpuGetEngstate_IMPL.part.0 =====

undefined8 gpuGetEngstate_IMPL_part_0(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = gpumgrGetParentGPU();
  if ((param_1 != lVar1) && (lVar1 = param_1, *(char *)(param_1 + 0x481) == '\0')) {
    lVar1 = gpumgrGetParentGPU(param_1);
  }
  uVar2 = 0;
  if (*(long *)(lVar1 + 0x1cd0) != 0) {
    lVar1 = gpumgrGetParentGPU(param_1);
    if ((param_1 != lVar1) && (*(char *)(param_1 + 0x481) == '\0')) {
      param_1 = gpumgrGetParentGPU(param_1);
    }
    uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x1cd0) + 0x158);
  }
  return uVar2;
}


// ===== 00344800 _gpuRmApiFree =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gpuRmApiFree(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  
  do {
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
    if (pcVar2 != _gpuRmApiFree) break;
    lVar1 = rmapiGetInterface(4);
    pcVar2 = *(code **)(lVar1 + 0x18);
  } while (pcVar2 == _gpuRmApiFree);
  (*pcVar2)(lVar1,param_2,param_3);
  return;
}


// ===== 00344920 _gpuFreeInternalObjects =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gpuFreeInternalObjects(long param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  code *pcVar4;
  
  if (*(int *)(param_1 + 0x3b40) != 0) {
    lVar3 = rmapiGetInterface(4);
    uVar1 = *(undefined4 *)(param_1 + 0x3b40);
    pcVar4 = *(code **)(lVar3 + 0x18);
    if (pcVar4 == _gpuRmApiFree) {
      lVar3 = rmapiGetInterface(4);
      pcVar4 = *(code **)(lVar3 + 0x18);
      if (pcVar4 == _gpuRmApiFree) {
        lVar3 = rmapiGetInterface(4);
        pcVar4 = *(code **)(lVar3 + 0x18);
        if (pcVar4 == _gpuRmApiFree) {
          lVar3 = rmapiGetInterface(4);
          if (*(code **)(lVar3 + 0x18) == _gpuRmApiFree) {
            _gpuRmApiFree(lVar3,uVar1);
          }
          else {
            (**(code **)(lVar3 + 0x18))(lVar3,uVar1,uVar1);
          }
          goto LAB_00344939;
        }
      }
    }
    (*pcVar4)(lVar3,uVar1,uVar1);
  }
LAB_00344939:
  if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
    uVar2 = rmapiGetInterface(4);
    rmapiutilFreeClientAndDeviceHandles(uVar2,param_1 + 0x3b34,param_1 + 0x3b38,param_1 + 0x3b3c);
    return;
  }
  rmapiControlCacheFreeObjectEntry
            (*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c));
  rmapiControlCacheFreeObjectEntry
            (*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b38));
  return;
}


// ===== 00344a5c _gpuDetectNvswitchSupport.cold =====

void _gpuDetectNvswitchSupport_cold(void)

{
  code *pcVar1;
  
  nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00344a80 _gpuDetectNvswitchSupport =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gpuDetectNvswitchSupport(long param_1)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined8 local_10;
  
  *(undefined2 *)(param_1 + 0x4a4c) = 0x100;
  iVar1 = *(int *)(param_1 + 0x4a48);
  *(undefined1 *)(param_1 + 0x4cc) = 0;
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(long *)(param_1 + 0x1ce8) == 0) goto LAB_00344b46;
    local_10 = 0;
    if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
      iVar4 = _gpuRmApiControl();
    }
    else {
      iVar4 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20802609,&local_10,8);
    }
    if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 0x4c8) = (undefined4)local_10;
      *(char *)(param_1 + 0x4cc) = local_10._4_1_;
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_PMGR_GET_MODULE_INFO, &moduleInfoParams, sizeof(moduleInfoParams))"
                 ,"src/kernel/gpu/gpu.c",0xe6);
      local_10._4_1_ = *(char *)(param_1 + 0x4cc);
    }
  }
  else {
    if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) == 0) {
      nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    local_10._4_1_ =
         *(char *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x26048) !=
         '\0';
    *(char *)(param_1 + 0x4cc) = local_10._4_1_;
  }
  if (local_10._4_1_ == '\x01') {
    *(undefined2 *)(param_1 + 0x4a4c) = 0xa05;
  }
LAB_00344b46:
  if (iVar1 != 0) {
    *(char *)(param_1 + 0x4a4c) = (char)iVar1;
    cVar3 = (char)((uint)iVar1 >> 8);
    if (cVar3 == '\0') {
      cVar3 = '\x01';
    }
    *(char *)(param_1 + 0x4a4d) = cVar3;
    if ((char)iVar1 != '\0') {
      *(undefined1 *)(param_1 + 0x4cc) = 1;
    }
  }
  return;
}


// ===== 00344c10 gpuGenerate32BitId =====

uint gpuGenerate32BitId(uint param_1,undefined1 param_2,undefined1 param_3)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = param_1 << 0x10 | (uint)CONCAT11(param_2,param_3);
  if (param_1 >> 0x10 == 0) {
    return uVar2;
  }
  cVar1 = hypervisorIsType_IMPL(2);
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("hypervisorIsType(OS_HYPERVISOR_HYPERV)","src/kernel/gpu/gpu.c",0x129);
  }
  return uVar2;
}


// ===== 00344c80 gpuChangeComputeModeRefCount_IMPL =====

void gpuChangeComputeModeRefCount_IMPL(long param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (param_2 == 10) {
    iVar2 = *(int *)(param_1 + 0x1b20);
    if (iVar2 < 0) {
      nvAssertFailedNoLog("pGpu->computeModeRefCount >= 0","src/kernel/gpu/gpu.c",0x13a);
      iVar2 = *(int *)(param_1 + 0x1b20);
    }
    *(int *)(param_1 + 0x1b20) = iVar2 + 1;
    if (iVar2 + 1 != 1) {
      return;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x7ac);
    pcVar4 = "NVRM: GPU (ID: 0x%x): new mode: COMPUTE\n";
    uVar3 = 0x13f;
    goto LAB_00344d48;
  }
  if (param_2 != 0xb) {
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x159,"gpuChangeComputeModeRefCount_IMPL",4,
                 "NVRM: Bad command: 0x%x\n",param_2);
    nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x15a);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x1b20) + -1;
  *(int *)(param_1 + 0x1b20) = iVar2;
  if (iVar2 < 0) {
    nvAssertFailedNoLog("pGpu->computeModeRefCount >= 0","src/kernel/gpu/gpu.c",0x148);
    iVar2 = *(int *)(param_1 + 0x1b20);
    if (-1 < iVar2) goto LAB_00344cae;
    *(undefined4 *)(param_1 + 0x1b20) = 0;
  }
  else {
LAB_00344cae:
    if (iVar2 != 0) {
      return;
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x7ac);
  pcVar4 = "NVRM: GPU (ID: 0x%x): new mode: GRAPHICS\n";
  uVar3 = 0x151;
LAB_00344d48:
  nvDbg_Printf("src/kernel/gpu/gpu.c",uVar3,"gpuChangeComputeModeRefCount_IMPL",1,pcVar4,uVar1);
  timeoutInitializeGpuDefault(param_1 + 0x1af0,param_1);
  return;
}


// ===== 00344e10 gpuConstruct_IMPL =====

undefined8
gpuConstruct_IMPL(long param_1,undefined4 param_2,undefined4 param_3,long param_4,undefined8 param_5
                 )

{
  undefined8 uVar1;
  long lVar2;
  
  *(undefined8 *)(param_1 + 0x4d8) = param_5;
  *(undefined4 *)(param_1 + 0x7a4) = param_2;
  *(undefined4 *)(param_1 + 0x7b0) = param_3;
  *(undefined4 *)(param_1 + 0x7ac) = param_3;
  *(undefined1 *)(param_1 + 0x7e1) = 0;
  if (param_4 != 0) {
    portMemCopy(param_1 + 0x7c5,0x10,param_4,0x10);
    *(undefined1 *)(param_1 + 0x7c4) = 1;
  }
  osInitOSHwInfo(param_1);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1 + 0x49e8,uVar1,0x10);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  listInit_IMPL(param_1 + 0x49b8,uVar1,0x10);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  multimapInit_IMPL(param_1 + 0x4948,uVar1,0x28,0x28,0x10);
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  multimapInit_IMPL(param_1 + 0x4980,uVar1,0x30,0x30,0x10);
  *(undefined4 *)(param_1 + 0x7f0) = 0x10;
  *(undefined8 *)(param_1 + 0x4a58) = 0;
  *(undefined4 *)(param_1 + 0x4a60) = 0xffffffff;
  *(undefined8 *)(param_1 + 0x4a68) = 0;
  *(undefined4 *)(param_1 + 0x4a70) = 0xffffffff;
  lVar2 = portMemAllocNonPaged(0x90);
  *(long *)(param_1 + 0x4a10) = lVar2;
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pGpu->pDpcThreadState != NULL","src/kernel/gpu/gpu.c",0x299);
  }
  else {
    uVar1 = portMemAllocatorGetGlobalNonPaged();
    lVar2 = portSyncSpinlockCreate(uVar1);
    *(long *)(param_1 + 0x3c50) = lVar2;
    if (lVar2 != 0) {
      return 0;
    }
    portMemFree(*(undefined8 *)(param_1 + 0x4a10));
    *(undefined8 *)(param_1 + 0x4a10) = 0;
  }
  return 0x51;
}


// ===== 00344fa0 gpuBindHalLegacy_IMPL =====

int gpuBindHalLegacy_IMPL(long param_1,int param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(g_pSys + 600);
  *(int *)(param_1 + 0x8e8) = param_2;
  if (param_4 != 0) {
    param_2 = param_4;
  }
  *(int *)(param_1 + 0x8ec) = (int)param_3;
  iVar1 = halmgrGetHalForGpu_IMPL(uVar2,param_2,param_3,param_1 + 0x4f0);
  if (iVar1 == 0) {
    uVar2 = halmgrGetHal_IMPL(uVar2,*(undefined4 *)(param_1 + 0x4f0));
    *(undefined8 *)(param_1 + 0x1b50) = uVar2;
  }
  return iVar1;
}


// ===== 00345010 gpuIsPciBusFamily_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint gpuIsPciBusFamily_IMPL(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(param_1 + 0x168))();
  uVar1 = (int)uVar2 - 3;
  return CONCAT31((int3)(uVar1 >> 8),uVar1 < 2) |
         (uint)CONCAT71((int7)((ulong)uVar2 >> 8),(int)uVar2 == 1);
}


// ===== 00345040 gpuGetEngstateNoShare_IMPL =====

undefined8 gpuGetEngstateNoShare_IMPL(long param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = param_2 >> 8;
  if (uVar1 == 0x899e48) {
    uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1bb8),__nvoc_class_def_OBJENGSTATE);
    return uVar2;
  }
  if (uVar1 < 0x899e49) {
    if (uVar1 == 0x3827ff) {
      uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1b60),__nvoc_class_def_OBJENGSTATE);
      return uVar2;
    }
    if (uVar1 < 0x382800) {
      if (uVar1 == 0x261ee8) {
        uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1d10),__nvoc_class_def_OBJENGSTATE);
        return uVar2;
      }
      if (uVar1 < 0x261ee9) {
        if (uVar1 == 0x22ad47) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1b78),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 < 0x22ad48) {
          if (uVar1 == 0x1c1bf) {
            uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1bc0),
                                       __nvoc_class_def_OBJENGSTATE);
            return uVar2;
          }
          if (uVar1 == 0x20fd5a) {
            uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1cf8),
                                       __nvoc_class_def_OBJENGSTATE);
            return uVar2;
          }
        }
        else if (uVar1 == 0x242aca) {
          uVar2 = 0;
          if ((byte)param_2 < 0x14) {
            uVar2 = *(undefined8 *)(param_1 + 0x1c30 + (ulong)(param_2 & 0xff) * 8);
          }
          goto LAB_00345285;
        }
      }
      else {
        if (uVar1 == 0x2f36c9) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1ba0),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0x311d4e) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1ba8),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0x29362f) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1b98),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
      }
    }
    else {
      if (uVar1 == 0x61649c) {
        uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1bb0),__nvoc_class_def_OBJENGSTATE);
        return uVar2;
      }
      if (uVar1 < 0x61649d) {
        if (uVar1 == 0x5ca633) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1b68),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 < 0x5ca634) {
          if (uVar1 == 0x4888db) {
            uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1c18),
                                       __nvoc_class_def_OBJENGSTATE);
            return uVar2;
          }
          if (uVar1 == 0x55952e) {
            uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1b80),
                                       __nvoc_class_def_OBJENGSTATE);
            return uVar2;
          }
        }
        else if (uVar1 == 0x5d5b68) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1d20),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
      }
      else {
        if (uVar1 == 0x7faff1) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1b70),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0x87fb96) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1d08),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0x7e80a2) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1ce0),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
      }
    }
  }
  else {
    if (uVar1 == 0xc8c00f) {
      uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1cf0),__nvoc_class_def_OBJENGSTATE);
      return uVar2;
    }
    if (uVar1 < 0xc8c010) {
      if (uVar1 == 0xa9fc13) {
        uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1d48),__nvoc_class_def_OBJENGSTATE);
        return uVar2;
      }
      if (uVar1 < 0xa9fc14) {
        if (uVar1 == 0x9798cc) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1d18),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 < 0x9798cd) {
          if (uVar1 == 0x927969) {
            uVar2 = 0;
            if ((param_2 & 0xfc) == 0) {
              uVar2 = *(undefined8 *)(param_1 + 0x1d28 + (ulong)(param_2 & 0xff) * 8);
            }
            goto LAB_00345285;
          }
          if (uVar1 == 0x95a6f5) {
            uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1d00),
                                       __nvoc_class_def_OBJENGSTATE);
            return uVar2;
          }
        }
        else if (uVar1 == 0x9ddede) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1b88),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
      }
      else {
        if (uVar1 == 0xc06e44) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1c20),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0xc53a57) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1c10),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0xab9d7d) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1c28),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
      }
    }
    else {
      if (uVar1 == 0xdbe523) {
        uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 7000),__nvoc_class_def_OBJENGSTATE);
        return uVar2;
      }
      if (uVar1 < 0xdbe524) {
        if (uVar1 == 0xd22179) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1bc8),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0xd2ac57) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(&DAT_00001b90 + param_1),
                                     __nvoc_class_def_OBJENGSTATE);
          return uVar2;
        }
        if (uVar1 == 0xce6818) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1ce8),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
      }
      else {
        if (uVar1 == 0xf3e155) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1cd0),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0xf9a17d) {
          uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x1cd8),__nvoc_class_def_OBJENGSTATE)
          ;
          return uVar2;
        }
        if (uVar1 == 0xea3fa9) {
          uVar2 = 0;
          if ((param_2 & 0xf8) == 0) {
            uVar2 = *(undefined8 *)(param_1 + 0x1bd0 + (ulong)(param_2 & 0xff) * 8);
          }
LAB_00345285:
          uVar2 = __nvoc_dynamicCast(uVar2,__nvoc_class_def_OBJENGSTATE);
          return uVar2;
        }
      }
    }
  }
  return 0;
}


// ===== 00345540 _gpuEngineTransitionFailureStore.isra.0 =====

void _gpuEngineTransitionFailureStore_isra_0
               (long param_1,uint *param_2,ulong param_3,uint param_4,long param_5,uint *param_6,
               int param_7)

{
  uint *puVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long local_40 [2];
  
  param_3 = param_3 & 0xffffffff;
  *param_2 = param_4 >> 8;
  if ((param_5 == 0) || (iVar3 = osGetPerformanceCounter(local_40), iVar3 != 0)) {
    uVar5 = 0xffffffffffffffff;
  }
  else {
    uVar5 = (ulong)(local_40[0] - param_5) / 1000;
  }
  lVar6 = 0;
  *(ulong *)(param_2 + 2) = uVar5;
  puVar1 = param_6 + (param_7 + 1);
  do {
    lVar2 = lVar6;
    if (*param_6 >> 8 == 0xf3e155) {
      lVar4 = gpumgrGetParentGPU(param_1);
      if ((param_1 != lVar4) && (lVar4 = param_1, *(char *)(param_1 + 0x481) == '\0')) {
        lVar4 = gpumgrGetParentGPU(param_1);
      }
      if (*(long *)(lVar4 + 0x1cd0) != 0) {
        lVar4 = gpumgrGetParentGPU(param_1);
        if ((param_1 == lVar4) || (lVar4 = param_1, *(char *)(param_1 + 0x481) != '\0')) {
          lVar4 = *(long *)(*(long *)(lVar4 + 0x1cd0) + 0x158);
        }
        else {
          lVar4 = gpumgrGetParentGPU(param_1);
          lVar4 = *(long *)(*(long *)(lVar4 + 0x1cd0) + 0x158);
        }
        goto LAB_003455c6;
      }
    }
    else {
      lVar4 = gpuGetEngstateNoShare_IMPL();
LAB_003455c6:
      if (((lVar4 != 0) && (lVar2 = lVar4, lVar6 != 0)) &&
         (lVar2 = lVar6,
         *(uint *)(lVar6 + 100 + param_3 * 0xc) < *(uint *)(lVar4 + 100 + param_3 * 0xc))) {
        lVar2 = lVar4;
      }
    }
    lVar6 = lVar2;
    param_6 = param_6 + 1;
    if (param_6 == puVar1) {
      param_2[4] = *(uint *)(lVar6 + 100 + param_3 * 0xc);
      param_2[5] = *(uint *)(lVar6 + 0x4c) >> 8;
      return;
    }
  } while( true );
}


// ===== 003456d0 gpuGetEngstate_IMPL =====

void gpuGetEngstate_IMPL(undefined8 param_1,uint param_2)

{
  if (param_2 >> 8 != 0xf3e155) {
    gpuGetEngstateNoShare_IMPL();
    return;
  }
  gpuGetEngstate_IMPL_part_0();
  return;
}


// ===== 003456f0 gpuGetKernelFifoShared_IMPL =====

undefined8 gpuGetKernelFifoShared_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = gpumgrGetParentGPU();
  if ((param_1 != lVar1) && (*(char *)(param_1 + 0x481) == '\0')) {
    lVar1 = gpumgrGetParentGPU(param_1);
    return *(undefined8 *)(lVar1 + 0x1cd0);
  }
  return *(undefined8 *)(param_1 + 0x1cd0);
}


// ===== 00345740 gpuGetNextChildOfTypeUnsafe_IMPL =====

long gpuGetNextChildOfTypeUnsafe_IMPL(long param_1,uint *param_2,undefined4 param_3)

{
  ulong uVar1;
  long lVar2;
  uint uVar3;
  
  uVar1 = (ulong)*param_2;
  if (0x3e < *param_2) {
    return 0;
  }
  do {
    while( true ) {
      uVar3 = (int)uVar1 + 1;
      *param_2 = uVar3;
      lVar2 = *(long *)(param_1 + 7000 + uVar1 * 8);
      if (lVar2 != 0) break;
      uVar1 = (ulong)uVar3;
      if (0x3e < uVar3) {
        return 0;
      }
    }
    lVar2 = objDynamicCastById_IMPL(lVar2,param_3);
    if (lVar2 != 0) {
      return lVar2;
    }
    uVar1 = (ulong)*param_2;
  } while (*param_2 < 0x3f);
  return 0;
}


// ===== 003457b0 gpuDestruct_IMPL =====

void gpuDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long *plVar5;
  undefined8 *puVar6;
  undefined4 local_34;
  undefined8 local_30;
  
  cVar3 = hypervisorIsVgxHyper_IMPL();
  if ((cVar3 != '\0') || (*(char *)(param_1 + 0x497) != '\0')) {
    uVar1 = *(undefined8 *)(g_pSys + 0x218);
    local_34 = *(undefined4 *)(param_1 + 0x7ac);
    *(undefined1 *)(param_1 + 0x497) = 0;
    local_30 = 0x100000000;
    iVar4 = gpuacctDisableAccounting_IMPL(uVar1,*(undefined4 *)(param_1 + 0x7a4),&local_34);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x60f,"gpuDestruct_IMPL",4,
                   "NVRM: gpuDisableAccounting failed with error %d on GPU ID %d\n",iVar4,
                   *(undefined4 *)(param_1 + 0x7ac));
    }
  }
  rmapiReportInternalLeakedDevices(1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f));
  if (*(char *)(param_1 + 0x908) != '\0') {
    vgpuDestructObject(param_1);
  }
  plVar5 = (long *)(param_1 + 0x1d48);
  do {
    if (*plVar5 != 0) {
      __nvoc_objDelete();
      *plVar5 = 0;
    }
    plVar5 = plVar5 + -1;
  } while (plVar5 != (long *)(param_1 + 0x1b50));
  if (*(long *)(param_1 + 0x8a8) != 0) {
    portMemFree();
    portMemFree(*(undefined8 *)(param_1 + 0x8b0));
    portMemFree(*(undefined8 *)(param_1 + 0x8b8));
    portMemFree(*(undefined8 *)(param_1 + 0x8c0));
    portMemFree(*(undefined8 *)(param_1 + 0x898));
    *(undefined8 *)(param_1 + 0x8a8) = 0;
    *(undefined8 *)(param_1 + 0x8b0) = 0;
    *(undefined8 *)(param_1 + 0x8b8) = 0;
    *(undefined8 *)(param_1 + 0x8c0) = 0;
    *(undefined8 *)(param_1 + 0x898) = 0;
  }
  puVar6 = (undefined8 *)(param_1 + 0x500);
  portMemFree(*(undefined8 *)(param_1 + 0x3b28));
  *(undefined8 *)(param_1 + 0x3b28) = 0;
  *(undefined4 *)(param_1 + 0x3b30) = 0;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    gpuEngineEventNotificationListDestroy(param_1,uVar1);
  } while (puVar6 != (undefined8 *)(param_1 + 0x7a0));
  if (*(long *)(param_1 + 0x1e20) != 0) {
    *(undefined4 *)(param_1 + 0x1e18) = 0;
    portMemFree();
    *(undefined8 *)(param_1 + 0x1e20) = 0;
    *(undefined1 *)(param_1 + 0x1e28) = 0;
  }
  gpuDestroyClassDB_IMPL(param_1);
  osDestroyOSHwInfo(param_1);
  lVar2 = *(long *)(param_1 + 0x1d50);
  while (lVar2 != 0) {
    *(undefined8 *)(param_1 + 0x1d50) = *(undefined8 *)(lVar2 + 8);
    portMemFree();
    lVar2 = *(long *)(param_1 + 0x1d50);
  }
  regAccessDestruct(param_1 + 0x3a18);
  if (*(int *)(param_1 + 0x3700) != 0) {
    nvAssertFailedNoLog("pGpu->numConstructedFalcons == 0","src/kernel/gpu/gpu.c",0x641);
  }
  portMemFree(*(undefined8 *)(param_1 + 0x3a40));
  *(undefined8 *)(param_1 + 0x3a40) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0x3a48));
  *(undefined8 *)(param_1 + 0x3a48) = 0;
  *(undefined4 *)(param_1 + 0x3a50) = 0;
  if (*(int *)(param_1 + 0x3c48) != 0) {
    nvAssertFailedNoLog("pGpu->numSubdeviceBackReferences == 0","src/kernel/gpu/gpu.c",0x64b);
  }
  portMemFree(*(undefined8 *)(param_1 + 0x3c40));
  *(undefined8 *)(param_1 + 0x3c40) = 0;
  *(undefined8 *)(param_1 + 0x3c48) = 0;
  portSyncSpinlockDestroy(*(undefined8 *)(param_1 + 0x3c50));
  *(undefined8 *)(param_1 + 0x3c50) = 0;
  multimapDestroy_IMPL(param_1 + 0x4948);
  multimapDestroy_IMPL(param_1 + 0x4980);
  portMemFree(*(undefined8 *)(param_1 + 0x4a10));
  return;
}


// ===== 00345b40 gpuEngineGetGpu =====

undefined8 gpuEngineGetGpu(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  do {
    param_1 = *(long *)(param_1 + 0x10);
    if (param_1 == 0) {
      return 0;
    }
    lVar2 = fullyDeriveWrapper(param_1);
    uVar3 = 0;
    if (lVar2 != 0) {
      uVar3 = fullyDeriveWrapper(param_1);
    }
    iVar1 = __nvoc_objGetClassId(uVar3);
  } while (iVar1 != 0x7ef3cb);
  uVar3 = fullyDeriveWrapper(param_1);
  return uVar3;
}


// ===== 00345ba0 gpuIsGridDisplaylessClassSupported_IMPL =====

bool gpuIsGridDisplaylessClassSupported_IMPL(long param_1)

{
  char cVar1;
  
  if (*(long *)(param_1 + 0x1b80) != 0) {
    return false;
  }
  cVar1 = osIsGridSupported();
  return cVar1 != '\0';
}


// ===== 00345bd0 gpuStateInit_IMPL =====

int gpuStateInit_IMPL(long param_1)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  uint *puVar5;
  int local_50 [8];
  
  *(undefined4 *)(param_1 + 0x7bc) = 0xffffffff;
  cVar2 = rmGpuLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/gpu.c",0x90a);
    return 0x2f;
  }
  if (*(uint *)(param_1 + 0x8c8) != 0) {
    puVar5 = *(uint **)(param_1 + 0x8a8);
    puVar1 = puVar5 + *(uint *)(param_1 + 0x8c8);
    do {
      if (*puVar5 >> 8 == 0xf3e155) {
        lVar4 = gpumgrGetParentGPU();
        if ((param_1 != lVar4) && (lVar4 = param_1, *(char *)(param_1 + 0x481) == '\0')) {
          lVar4 = gpumgrGetParentGPU(param_1);
        }
        if (*(long *)(lVar4 + 0x1cd0) != 0) {
          lVar4 = gpumgrGetParentGPU(param_1);
          if ((param_1 != lVar4) && (lVar4 = param_1, *(char *)(param_1 + 0x481) == '\0')) {
            lVar4 = gpumgrGetParentGPU(param_1);
          }
          lVar4 = *(long *)(*(long *)(lVar4 + 0x1cd0) + 0x158);
          goto LAB_00345c38;
        }
      }
      else {
        lVar4 = gpuGetEngstateNoShare_IMPL(param_1);
LAB_00345c38:
        if (lVar4 != 0) {
          engstateLogStateTransitionPre_IMPL(lVar4,3,local_50);
          iVar3 = engstateStateInit_IMPL(param_1,lVar4);
          engstateLogStateTransitionPost_IMPL(lVar4,3,local_50);
          if ((iVar3 != 0) && (iVar3 != 0x56)) {
            return iVar3;
          }
        }
      }
      puVar5 = puVar5 + 1;
    } while (puVar1 != puVar5);
  }
  cVar2 = hypervisorIsVgxHyper_IMPL();
  if (cVar2 != '\0') {
    cVar2 = rmcfg_IsdADA(param_1);
    if (cVar2 != '\0') {
      local_50[0] = 1;
      iVar3 = osReadRegistryDword(param_1,"RMBug3007008EmulateVfMmuTlbInvalidate",local_50);
      if (iVar3 != 0 || local_50[0] != 0) goto LAB_00345d05;
    }
    *(undefined1 *)(param_1 + 0x463) = 0;
  }
LAB_00345d05:
  *(undefined1 *)(param_1 + 0x445) = 1;
  return 0;
}


// ===== 00345dd0 gpuDisableAccounting_IMPL =====

void gpuDisableAccounting_IMPL(long param_1,char param_2)

{
  undefined8 uVar1;
  undefined4 local_14;
  undefined8 local_10;
  
  local_14 = *(undefined4 *)(param_1 + 0x7ac);
  local_10 = 0x100000000;
  uVar1 = *(undefined8 *)(g_pSys + 0x218);
  if (param_2 != '\0') {
    *(undefined1 *)(param_1 + 0x497) = 0;
  }
  gpuacctDisableAccounting_IMPL(uVar1,*(undefined4 *)(param_1 + 0x7a4),&local_14);
  return;
}


// ===== 00345e30 gpuStateDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 gpuStateDestroy_IMPL(long param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  uint *puVar6;
  undefined1 local_40 [24];
  
  rmapiControlCacheFreeAllCacheForGpu(*(undefined4 *)(param_1 + 0x7a4));
  videoRemoveAllBindpointsForGpu(param_1);
  if (*(uint *)(param_1 + 0x8c8) != 0) {
    puVar6 = *(uint **)(param_1 + 0x8b0);
    puVar1 = puVar6 + *(uint *)(param_1 + 0x8c8);
    do {
      if (*puVar6 >> 8 == 0xf3e155) {
        plVar3 = (long *)gpuGetEngstate_IMPL_part_0();
      }
      else {
        plVar3 = (long *)gpuGetEngstateNoShare_IMPL(param_1);
      }
      if (plVar3 != (long *)0x0) {
        engstateLogStateTransitionPre_IMPL(plVar3,10,local_40);
        (**(code **)(*plVar3 + 0x90))(param_1,plVar3);
        engstateLogStateTransitionPost_IMPL(plVar3,10,local_40);
      }
      puVar6 = puVar6 + 1;
    } while (puVar6 != puVar1);
  }
  *(undefined1 *)(param_1 + 0x445) = 0;
  uVar2 = 0;
  if (*(char *)(param_1 + 0x909) != '\0') {
    uVar2 = kgspUnloadRm_IMPL(param_1,*(undefined8 *)(param_1 + 0x1ba8),0,0);
  }
  _gpuFreeInternalObjects(param_1);
  puVar5 = (undefined8 *)(param_1 + 0x3708);
  do {
    puVar4 = puVar5 + 1;
    __nvoc_objDelete(*puVar5);
    *puVar5 = 0;
    puVar5 = puVar4;
  } while (puVar4 != (undefined8 *)(param_1 + 0x3940));
  *(undefined4 *)(param_1 + 0x3940) = 0;
  puVar5 = (undefined8 *)(param_1 + 0x3948);
  do {
    puVar4 = puVar5 + 1;
    __nvoc_objDelete(*puVar5);
    *puVar5 = 0;
    puVar5 = puVar4;
  } while (puVar4 != (undefined8 *)(param_1 + 0x39f8));
  *(undefined4 *)(param_1 + 0x39f8) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0x3c58));
  *(undefined8 *)(param_1 + 0x3c58) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0x3a00));
  *(undefined8 *)(param_1 + 0x3a00) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0x3a08));
  *(undefined1 *)(param_1 + 0x4919) = 0;
  *(undefined8 *)(param_1 + 0x3a08) = 0;
  *(undefined4 *)(param_1 + 0x3a10) = 0;
  (**(code **)(param_1 + 0x380))(param_1);
  return uVar2;
}


// ===== 00346020 gpuIsImplementation_IMPL =====

undefined4 gpuIsImplementation_IMPL(long param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int local_20;
  int local_1c [3];
  
  gpuXlateHalImplToArchImpl(param_2,&local_20,local_1c);
  uVar1 = 0;
  if (local_20 == *(int *)(param_1 + 0x808)) {
    uVar1 = CONCAT31((int3)((uint)*(int *)(param_1 + 0x80c) >> 8),
                     local_1c[0] == *(int *)(param_1 + 0x80c));
  }
  return uVar1;
}


// ===== 00346060 gpuInitOptimusSettings_IMPL =====

undefined8 gpuInitOptimusSettings_IMPL(long param_1)

{
  int iVar1;
  undefined2 local_12;
  undefined4 local_10;
  uint local_c;
  
  if (*(char *)(param_1 + 0x485) == '\0') {
    return 0;
  }
  iVar1 = osReadRegistryDword(param_1,"RMD3Feature",&local_c);
  if ((iVar1 == 0) && ((local_c & 3) == 2)) {
    *(undefined1 *)(param_1 + 0x4a9) = 0;
  }
  else {
    local_12 = 4;
    local_10 = 6;
    iVar1 = osCallACPI_DSM(param_1,4,0x1a,&local_10,&local_12);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x1070,"gpuInitOptimusSettings_IMPL",2,
                   "NVRM: SBIOS did not acknowledge cfg space owner change\n");
      return 0;
    }
  }
  return 0;
}


// ===== 00346110 gpuDeinitOptimusSettings_IMPL =====

undefined8 gpuDeinitOptimusSettings_IMPL(long param_1)

{
  int iVar1;
  undefined2 local_e;
  undefined4 local_c;
  
  if ((*(char *)(param_1 + 0x485) != '\0') && (*(char *)(param_1 + 0x4a9) != '\0')) {
    local_e = 4;
    local_c = 4;
    iVar1 = osCallACPI_DSM(param_1,4,0x1a,&local_c,&local_e);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x109e,"gpuDeinitOptimusSettings_IMPL",1,
                   "NVRM: SBIOS did not acknowledge cfg space owner change\n");
    }
    return 0;
  }
  return 0;
}


// ===== 003461a0 gpuIsGpuFullPower_IMPL =====

bool gpuIsGpuFullPower_IMPL(long param_1)

{
  bool bVar1;
  
  bVar1 = false;
  if (*(char *)(param_1 + 0x441) == '\0') {
    bVar1 = *(char *)(param_1 + 0x442) == '\0';
  }
  return bVar1;
}


// ===== 003461c0 gpuIsGpuFullPowerForPmResume_IMPL =====

bool gpuIsGpuFullPowerForPmResume_IMPL(long param_1)

{
  if (*(char *)(param_1 + 0x444) != '\0') {
    return true;
  }
  if (*(char *)(param_1 + 0x441) != '\0') {
    return false;
  }
  return *(char *)(param_1 + 0x442) == '\0';
}


// ===== 00346200 gpuIsImplementationOrBetter_IMPL =====

bool gpuIsImplementationOrBetter_IMPL(long param_1,uint param_2)

{
  uint uVar1;
  undefined1 local_20 [3];
  char local_1d;
  undefined1 local_1c [4];
  
  gpuXlateHalImplToArchImpl(param_2,local_20,local_1c);
  if (local_1d != *(char *)(param_1 + 0x80b)) {
    return false;
  }
  uVar1 = *(uint *)(param_1 + 0x4f0);
  if (0x50 < uVar1) {
    nvAssertFailedNoLog("chipImpl < HAL_IMPL_MAXIMUM","src/kernel/gpu/gpu.c",0x12c3);
  }
  return param_2 <= uVar1;
}


// ===== 00346280 gpuConstructEngineTable_IMPL =====

int gpuConstructEngineTable_IMPL(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  *(undefined1 *)(param_1 + 0x1e28) = 0;
  lVar3 = portMemAllocNonPaged(0xe4);
  *(long *)(param_1 + 0x1e20) = lVar3;
  if (lVar3 == 0) {
    iVar2 = 0x51;
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x1363,"gpuConstructEngineTable_IMPL",4,
                 "NVRM: gpuConstructEngineTable: Could not allocate engine DB\n");
  }
  else {
    puVar4 = (undefined8 *)(param_1 + 0x500);
    *(undefined4 *)(param_1 + 0x1e18) = 0;
    puVar5 = puVar4;
    do {
      iVar2 = gpuEngineEventNotificationListCreate(param_1,puVar5);
      if (iVar2 != 0) {
        do {
          uVar1 = *puVar4;
          puVar4 = puVar4 + 1;
          gpuEngineEventNotificationListDestroy(param_1,uVar1);
        } while (puVar4 != (undefined8 *)(param_1 + 0x7a0));
        if (*(long *)(param_1 + 0x1e20) == 0) {
          return iVar2;
        }
        *(undefined4 *)(param_1 + 0x1e18) = 0;
        portMemFree();
        *(undefined8 *)(param_1 + 0x1e20) = 0;
        *(undefined1 *)(param_1 + 0x1e28) = 0;
        return iVar2;
      }
      puVar5 = puVar5 + 1;
      iVar2 = 0;
    } while (puVar5 != (undefined8 *)(param_1 + 0x7a0));
  }
  return iVar2;
}


// ===== 003463c0 gpuUpdateEngineTable_IMPL =====

undefined8 gpuUpdateEngineTable_IMPL(long param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  int local_1c;
  
  local_1c = 0;
  if (*(long *)(param_1 + 0x1e20) != 0) {
    if (*(char *)(param_1 + 0x1e28) == '\0') {
      pcVar3 = "\x01";
      *(undefined4 *)(param_1 + 0x1e18) = 0;
      do {
        if (pcVar3[0xc] != '\0') {
          iVar2 = gpuGetClassList_IMPL
                            (param_1,&local_1c,0,*(int *)(pcVar3 + 4) << 8 | *(uint *)(pcVar3 + 8));
          if ((iVar2 == 0) && (local_1c != 0)) {
            uVar1 = *(uint *)(param_1 + 0x1e18);
            *(uint *)(param_1 + 0x1e18) = uVar1 + 1;
            *(undefined4 *)(*(long *)(param_1 + 0x1e20) + (ulong)uVar1 * 4) = *(undefined4 *)pcVar3;
          }
        }
        pcVar3 = pcVar3 + 0x10;
      } while (pcVar3 != "NVRM: Failed to initialize pGpu IO aperture for devIdx %d.\n");
      *(undefined1 *)(param_1 + 0x1e28) = 1;
    }
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x1385,"gpuUpdateEngineTable_IMPL",4,
               "NVRM: gpuUpdateEngineTable: EngineDB has not been created yet\n");
  return 0x40;
}


// ===== 003464b0 gpuCheckEngineTable_IMPL =====

undefined8 gpuCheckEngineTable_IMPL(long param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  
  if ((*(char *)(param_1 + 0x490f) == '\0') && (*(char *)(param_1 + 0x1e28) == '\0')) {
    nvAssertFailedNoLog("pGpu->engineDB.bValid","src/kernel/gpu/gpu.c",0x13c1);
    return 0;
  }
  if (param_2 < 0x54) {
    if (*(uint *)(param_1 + 0x1e18) != 0) {
      puVar2 = *(uint **)(param_1 + 0x1e20);
      puVar1 = puVar2 + *(uint *)(param_1 + 0x1e18);
      do {
        if (*puVar2 == param_2) {
          return 1;
        }
        puVar2 = puVar2 + 1;
      } while (puVar2 != puVar1);
    }
  }
  else {
    nvAssertFailedNoLog("engType < RM_ENGINE_TYPE_LAST","src/kernel/gpu/gpu.c",0x13c4);
  }
  return 0;
}


// ===== 00346560 gpuXlateClientEngineIdToEngDesc_IMPL =====

undefined8 gpuXlateClientEngineIdToEngDesc_IMPL(undefined8 param_1,int param_2,uint *param_3)

{
  ulong uVar1;
  
  uVar1 = 0;
  do {
    if ((&rmClientEngineTable)[uVar1 * 4] == param_2) {
      *param_3 = (&DAT_00d26ea4)[(uVar1 & 0xffffffff) * 4] << 8 |
                 (&DAT_00d26ea8)[(uVar1 & 0xffffffff) * 4];
      return 0;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0x39);
  return 0x1f;
}


// ===== 003465c0 gpuXlateEngDescToClientEngineId_IMPL =====

undefined8 gpuXlateEngDescToClientEngineId_IMPL(undefined8 param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  ulong uVar2;
  int *piVar3;
  
  uVar2 = 0;
  piVar3 = &DAT_00d26ea4;
  do {
    if ((*piVar3 << 8 | piVar3[1]) == param_2) {
      *param_3 = (&rmClientEngineTable)[uVar2 * 4];
      return 0;
    }
    uVar1 = (int)uVar2 + 1;
    uVar2 = (ulong)uVar1;
    piVar3 = piVar3 + 4;
  } while (uVar1 != 0x39);
  return 0x1f;
}


// ===== 00346620 gpuGetGidInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuGetGidInfo_IMPL(long param_1,long *param_2,undefined4 *param_3,uint param_4)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 local_48 [24];
  
  if ((param_4 & 4) != 0) {
    return 0x29;
  }
  if (*(char *)(param_1 + 0x7c4) == '\0') {
    uVar1 = (**(code **)(param_1 + 0x1d8))(param_1,local_48,0x10);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    portMemCopy(param_1 + 0x7c5,0x10,local_48,0x10);
    *(undefined1 *)(param_1 + 0x7c4) = 1;
  }
  else {
    portMemCopy(local_48,0x10,param_1 + 0x7c5,0x10);
  }
  if (param_2 == (long *)0x0) {
    return 0;
  }
  if ((param_4 & 3) == 2) {
    lVar2 = portMemAllocNonPaged(0x10);
    *param_2 = lVar2;
    if (lVar2 != 0) {
      portMemCopy(lVar2,0x10,local_48,0x10);
      *param_3 = 0x10;
      return 0;
    }
    uVar1 = 0x51;
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      uVar1 = transformGidToUserFriendlyString(local_48,0x10,param_2,param_3,param_4,0);
      return uVar1;
    }
    nvAssertFailedNoLog("pGidStrlen != NULL","src/kernel/gpu/gpu.c",0x1444);
    uVar1 = 0x1f;
  }
  return uVar1;
}


// ===== 003467a0 gpuGetUgidInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuGetUgidInfo_IMPL(long param_1,long *param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  undefined1 local_38 [24];
  
  if ((param_4 & 4) == 0) {
    iVar1 = (**(code **)(param_1 + 0x1e0))(param_1,local_38,0x10);
    if ((iVar1 == 0) && (param_2 != (long *)0x0)) {
      if ((param_4 & 3) == 2) {
        lVar2 = portMemAllocNonPaged(0x10);
        *param_2 = lVar2;
        if (lVar2 == 0) {
          iVar1 = 0x51;
        }
        else {
          portMemCopy(lVar2,0x10,local_38,0x10);
          *param_3 = 0x10;
        }
      }
      else if (param_3 == (undefined4 *)0x0) {
        nvAssertFailedNoLog("pGidStrlen != NULL","src/kernel/gpu/gpu.c",0x147d);
        iVar1 = 0x1f;
      }
      else {
        iVar1 = transformGidToUserFriendlyString(local_38,0x10,param_2,param_3,param_4,3);
      }
    }
    return iVar1;
  }
  return 0x29;
}


// ===== 003468a0 gpuSetDisconnectedProperties_IMPL =====

void gpuSetDisconnectedProperties_IMPL(long param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x455) = 1;
  *(undefined1 *)(param_1 + 0x44c) = 0;
  *(undefined1 *)(param_1 + 0x443) = 0;
  *(undefined1 *)(param_1 + 0x490d) = 0;
  *(undefined2 *)(param_1 + 0x441) = 0;
  *(undefined4 *)(param_1 + 0x4b34) = 0;
  iVar1 = osQueueWorkItem(param_1,_gpuSetDisconnectedPropertiesWorker,0,0x82);
  if (iVar1 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "osQueueWorkItem(pGpu, _gpuSetDisconnectedPropertiesWorker, NULL, (OsQueueWorkItemFlags){ .bFallbackToDpc = NV_TRUE, .bLockGpuGroupDevice = NV_TRUE})"
             ,"src/kernel/gpu/gpu.c",0x14a4);
  return;
}


// ===== 00346910 gpuGetSparseTextureComputeMode_IMPL =====

undefined8 gpuGetSparseTextureComputeMode_IMPL(long param_1,int *param_2,int *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  int local_c;
  
  if (param_1 == 0) {
    return 0x1f;
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x909) == '\0') goto LAB_00346937;
    cVar1 = *(char *)(param_1 + 0x49f);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x49f);
  }
  if (cVar1 == '\0') {
    return 0x56;
  }
LAB_00346937:
  if ((param_3 == (int *)0x0 || param_4 == (int *)0x0) || (param_2 == (int *)0x0)) {
    return 0x1f;
  }
  if (*(char *)(param_1 + 0x466) == '\0') {
    return 0x56;
  }
  iVar2 = 2 - (uint)(*(char *)(param_1 + 0x4a0) == '\0');
  *param_2 = iVar2;
  *param_3 = iVar2;
  iVar2 = *(int *)(param_1 + 0x493c);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      *param_3 = 1;
    }
    else if (iVar2 == 2) {
      *param_3 = 2;
    }
  }
  *param_4 = *param_2;
  uVar3 = osReadRegistryDword(param_1,"RMOptimizeComputeOrSparseTex",&local_c);
  if ((int)uVar3 == 0) {
    if (local_c != 1) {
      if (local_c == 2) {
        *param_4 = 2;
      }
      return uVar3;
    }
    *param_4 = 1;
    return uVar3;
  }
  return 0;
}


// ===== 00346a30 gpuSetSparseTextureComputeMode_IMPL =====

undefined8 gpuSetSparseTextureComputeMode_IMPL(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    if ((((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) &&
        (*(char *)(param_1 + 0x49f) == '\0')) || (*(char *)(param_1 + 0x466) == '\0')) {
      return 0x56;
    }
    if (param_2 < 3) {
      uVar1 = osWriteRegistryDword(param_1,"RMOptimizeComputeOrSparseTex",param_2);
      return uVar1;
    }
  }
  return 0x1f;
}


// ===== 00346aa0 gpuBuildGenericKernelFalconList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuBuildGenericKernelFalconList_IMPL(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  uint *puVar5;
  long lVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulong uVar11;
  ulong local_78 [3];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
LAB_00346c90:
    puVar5 = (uint *)portMemAllocNonPaged(0x504);
    if (puVar5 == (uint *)0x0) {
      nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gpu.c",0x1593);
      return 0x51;
    }
    portMemSet(puVar5,0,0x504);
    if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
      iVar3 = _gpuRmApiControl();
    }
    else {
      iVar3 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x208001b0,puVar5,0x504);
    }
    if (iVar3 == 0) {
      if (0x47 < *puVar5) {
        nvAssertOkFailedNoLog
                  (2,
                   "pParams->numConstructedFalcons <= NV_ARRAY_ELEMENTS(pGpu->genericKernelFalcons)"
                   ,"src/kernel/gpu/gpu.c",0x15a0);
        portMemFree(puVar5);
        goto LAB_00346c14;
      }
      bVar2 = true;
      if (*puVar5 == 0) {
        *(undefined4 *)(param_1 + 0x3940) = 0;
        goto LAB_00346be2;
      }
      goto LAB_00346b08;
    }
    nvAssertOkFailedNoLog
              (iVar3,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_GPU_GET_CONSTRUCTED_FALCON_INFO, pParams, sizeof(*pParams))"
               ,"src/kernel/gpu/gpu.c",0x1599);
    portMemFree(puVar5);
  }
  else {
    lVar1 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
    lVar6 = lVar1 + 0x1d0;
    puVar5 = (uint *)(lVar1 + 0x1f3a0);
    if (lVar1 == 0) {
      nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
      if (*(char *)(param_1 + 0x908) == '\0') goto LAB_00346c90;
      puVar5 = (uint *)0x1f1d0;
      nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gpu.c",0x158d);
      lVar6 = 0;
    }
    if (*(uint *)(lVar6 + 0x1f1d0) < 0x48) {
      bVar2 = false;
      iVar3 = 0;
      if (*(uint *)(lVar6 + 0x1f1d0) == 0) goto LAB_00346c49;
LAB_00346b08:
      uVar11 = 0;
      uVar7 = 0;
      do {
        while( true ) {
          uVar10 = (uint)uVar11;
          uVar4 = (ulong)uVar7;
          local_78[0] = 0;
          local_78[1] = 0;
          local_78[2] = 0;
          local_60 = 0;
          local_58 = 0;
          local_50 = 0;
          local_48 = 0;
          local_40 = 0;
          if ((puVar5[uVar4 * 5 + 1] == 0x28c40800) && (*(long *)(param_1 + 0x1ba0) != 0)) break;
          local_60 = CONCAT44(puVar5[uVar4 * 5 + 2],puVar5[uVar4 * 5 + 1]);
          local_58 = *(undefined8 *)(puVar5 + uVar4 * 5 + 3);
          local_78[0] = (ulong)puVar5[uVar4 * 5 + 5];
          iVar3 = __nvoc_objCreate_GenericKernelFalcon
                            (param_1 + 0x3708 + uVar11 * 8,param_1,0,param_1,local_78);
          if (iVar3 != 0) {
            nvDbg_Printf("src/kernel/gpu/gpu.c",0x15be,"gpuBuildGenericKernelFalconList_IMPL",4,
                         "NVRM: Failed to create a GenericKernelFalcon object with engdesc %u\n",
                         local_60 & 0xffffffff);
            if (bVar2) {
              portMemFree(puVar5);
            }
            goto LAB_00346c1a;
          }
          uVar10 = uVar10 + 1;
          uVar11 = (ulong)uVar10;
          uVar7 = uVar7 + 1;
          if (*puVar5 <= uVar7) goto LAB_00346bd4;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *puVar5);
LAB_00346bd4:
      *(uint *)(param_1 + 0x3940) = uVar10;
      if (!bVar2) {
        return 0;
      }
LAB_00346be2:
      portMemFree(puVar5);
      return 0;
    }
    nvAssertOkFailedNoLog
              (2,"pParams->numConstructedFalcons <= NV_ARRAY_ELEMENTS(pGpu->genericKernelFalcons)",
               "src/kernel/gpu/gpu.c",0x15a0);
LAB_00346c14:
    iVar3 = 2;
  }
LAB_00346c1a:
  puVar8 = (undefined8 *)(param_1 + 0x3708);
  do {
    puVar9 = puVar8 + 1;
    __nvoc_objDelete(*puVar8);
    *puVar8 = 0;
    puVar8 = puVar9;
  } while (puVar9 != (undefined8 *)(param_1 + 0x3940));
LAB_00346c49:
  *(undefined4 *)(param_1 + 0x3940) = 0;
  return iVar3;
}


// ===== 00346e10 gpuBuildKernelVideoEngineList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuBuildKernelVideoEngineList_IMPL(long param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 local_3c [3];
  
  if (*(char *)(param_1 + 0x908) == '\0') {
LAB_00346fc0:
    local_3c[0] = 0x80000;
    osReadRegistryDword(param_1,"RmVideoEventTrace",local_3c);
    if (*(char *)(param_1 + 0x908) != '\0') {
      nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gpu.c",0x15ed);
      return 0x40;
    }
  }
  else {
    if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) == 0) {
      nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
      goto LAB_00346fc0;
    }
    local_3c[0] = 0x80000;
    puVar7 = (uint *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x1f3a0);
    osReadRegistryDword(param_1,"RmVideoEventTrace",local_3c);
    if (*(char *)(param_1 + 0x908) != '\0') goto LAB_00346e80;
  }
  puVar7 = (uint *)portMemAllocNonPaged(0x504);
  if (puVar7 == (uint *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gpu.c",0x15f3);
    return 0x51;
  }
  portMemSet(puVar7,0,0x504);
  if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
    iVar2 = _gpuRmApiControl();
  }
  else {
    iVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x208001b0,puVar7,0x504);
  }
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_GPU_GET_CONSTRUCTED_FALCON_INFO, pParams, sizeof(*pParams))"
               ,"src/kernel/gpu/gpu.c",0x15f7);
    if (*(char *)(param_1 + 0x908) == '\0') {
      portMemFree(puVar7);
    }
LAB_00346f4f:
    puVar5 = (undefined8 *)(param_1 + 0x3948);
    do {
      puVar6 = puVar5 + 1;
      __nvoc_objDelete(*puVar5);
      *puVar5 = 0;
      puVar5 = puVar6;
    } while ((undefined8 *)(param_1 + 0x39f8) != puVar6);
    *(undefined4 *)(param_1 + 0x39f8) = 0;
    return iVar2;
  }
LAB_00346e80:
  uVar4 = 0;
  if (*puVar7 != 0) {
    uVar4 = 0;
    uVar8 = 0;
    do {
      uVar1 = puVar7[(ulong)uVar8 * 5 + 1] >> 8;
      if (((uVar1 == 0x8f99e1 || uVar1 == 0xdd7bab) || uVar1 == 0x2b3a54) || (uVar1 == 0xe97b6c)) {
        if (0x15 < uVar4) {
          nvAssertFailedNoLog("numKernelVideoEngines < NV_ARRAY_ELEMENTS(pGpu->kernelVideoEngines)",
                              "src/kernel/gpu/gpu.c",0x1608);
          if (*(char *)(param_1 + 0x908) == '\0') {
            portMemFree(puVar7);
          }
          iVar2 = 0x40;
          goto LAB_00346f4f;
        }
        iVar2 = __nvoc_objCreate_KernelVideoEngine
                          (param_1 + (ulong)(uVar4 + 0x729) * 8,param_1,0,param_1);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "objCreate(&pGpu->kernelVideoEngines[numKernelVideoEngines], pGpu, KernelVideoEngine, pGpu, physEngDesc)"
                     ,"src/kernel/gpu/gpu.c",0x160b);
          if (*(char *)(param_1 + 0x908) == '\0') {
            portMemFree(puVar7);
          }
          goto LAB_00346f4f;
        }
        uVar3 = (ulong)uVar4;
        uVar4 = uVar4 + 1;
        *(undefined4 *)(*(long *)(param_1 + 0x3948 + uVar3 * 8) + 0x78) = local_3c[0];
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < *puVar7);
  }
  *(uint *)(param_1 + 0x39f8) = uVar4;
  if (*(char *)(param_1 + 0x908) == '\0') {
    portMemFree(puVar7);
  }
  return 0;
}


// ===== 00347160 gpuInitVideoLogging_IMPL =====

int gpuInitVideoLogging_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x39f8) == 0) {
    return 0;
  }
  lVar2 = 0;
  do {
    if (*(long *)(param_1 + 0x3948 + lVar2 * 8) != 0) {
      iVar1 = kvidengInitLogging_KERNEL(param_1);
      if (iVar1 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar1,"kvidengInitLogging(pGpu, pGpu->kernelVideoEngines[i])",
                   "src/kernel/gpu/gpu.c",0x1629);
        return iVar1;
      }
    }
    lVar2 = lVar2 + 1;
  } while ((uint)lVar2 < *(uint *)(param_1 + 0x39f8));
  return 0;
}


// ===== 003471ec gpuGetGenericKernelFalconForEngine_IMPL.cold =====

void gpuGetGenericKernelFalconForEngine_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00347200 gpuGetGenericKernelFalconForEngine_IMPL =====

long gpuGetGenericKernelFalconForEngine_IMPL(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  
  lVar1 = param_1 + (ulong)*(uint *)(param_1 + 0x3940) * 8;
  if (*(uint *)(param_1 + 0x3940) != 0) {
    do {
      lVar2 = *(long *)(param_1 + 0x3708);
      if (lVar2 == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      if (*(int *)(*(long *)(lVar2 + 0x6a0) + 0x634) == param_2) {
        return lVar2;
      }
      param_1 = param_1 + 8;
    } while (param_1 != lVar1);
  }
  return 0;
}


// ===== 00347260 gpuRegisterGenericKernelFalconIntrService_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuRegisterGenericKernelFalconIntrService_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  
  if (*(int *)(param_1 + 0x3940) != 0) {
    lVar3 = 0;
    do {
      lVar1 = *(long *)(param_1 + 0x3708 + lVar3 * 8);
      if ((lVar1 != 0) && (plVar2 = *(long **)(lVar1 + 0x6a8), plVar2 != (long *)0x0)) {
        (**(code **)(*plVar2 + 0x18))(param_1,plVar2,param_2);
      }
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < *(uint *)(param_1 + 0x3940));
    return;
  }
  return;
}


// ===== 003472e0 gpuGetGfidState_IMPL =====

undefined8 gpuGetGfidState_IMPL(long param_1,uint param_2,uint *param_3)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x491d) == '\0') {
    return 0;
  }
  if ((param_3 == (uint *)0x0) || (*(long *)(param_1 + 0x3a68) == 0)) {
    uVar1 = 0x1e;
  }
  else {
    uVar1 = 0x5b;
    if (param_2 <= *(uint *)(param_1 + 0x3a60)) {
      *param_3 = (uint)*(byte *)(*(long *)(param_1 + 0x3a68) + (ulong)param_2);
      return 0;
    }
  }
  return uVar1;
}


// ===== 00347330 gpuSetGfidUsage_IMPL =====

void gpuSetGfidUsage_IMPL(long param_1,uint param_2,char param_3)

{
  if (*(long *)(param_1 + 0x3a68) != 0) {
    *(bool *)(*(long *)(param_1 + 0x3a68) + (ulong)param_2) = param_3 == '\x01';
    return;
  }
  nvAssertFailedNoLog("pGpu->sriovState.pAllocatedGfids != NULL","src/kernel/gpu/gpu.c",0x16a6);
  return;
}


// ===== 00347370 gpuInitDispIpHal_IMPL =====

undefined8 gpuInitDispIpHal_IMPL(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  short local_2a;
  
  if (param_1 == 0) {
    lVar5 = 0;
    uVar6 = 0;
    lVar2 = 0x12;
  }
  else {
    lVar5 = *(long *)(param_1 + 0x88);
    uVar6 = *(undefined8 *)(param_1 + 0x80);
    lVar2 = lVar5 + 0x12;
  }
  lVar1 = *(long *)(param_1 + 0x1b80);
  if (param_2 == 0xffffffff) {
    __nvoc_init_halspec_DispIpHal(lVar2,0);
  }
  else {
    if (param_2 == 0x3010000) {
      param_2 = 0x3000000;
      __nvoc_init_halspec_DispIpHal(lVar2,0x3000000);
    }
    else {
      __nvoc_init_halspec_DispIpHal(lVar2,param_2 & 0xffff0000);
      if (param_2 < 0x10000) goto LAB_003473ee;
    }
    __nvoc_init_halspec_DispIpHal(&local_2a,0);
    if (*(short *)(lVar5 + 0x12) == local_2a) {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x1739,"gpuInitDispIpHal_IMPL",4,
                   "NVRM: Invalid dispIpHal.__nvoc_HalVarIdx %d for Disp IP Vertion 0x%08x\n",
                   *(short *)(lVar5 + 0x12),param_2);
      nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x173c);
      return 0x40;
    }
  }
LAB_003473ee:
  __nvoc_init_funcTable_KernelDisplay(lVar1,lVar5,uVar6);
  __nvoc_init_dataField_KernelDisplay(lVar1,lVar5,uVar6);
  __nvoc_init_funcTable_DisplayInstanceMemory(*(undefined8 *)(lVar1 + 0x280),lVar5);
  __nvoc_init_dataField_DisplayInstanceMemory(*(undefined8 *)(lVar1 + 0x280),lVar5);
  puVar3 = (undefined8 *)(lVar1 + 0x288);
  do {
    puVar4 = puVar3 + 1;
    __nvoc_init_funcTable_KernelHead(*puVar3,lVar5,uVar6);
    __nvoc_init_dataField_KernelHead(*puVar3,lVar5,uVar6);
    puVar3 = puVar4;
  } while (puVar4 != (undefined8 *)(lVar1 + 0x2c8));
  return 0;
}


// ===== 00347500 gpuIsCCFeatureEnabled_IMPL =====

undefined1 gpuIsCCFeatureEnabled_IMPL(long param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (*(long *)(param_1 + 0x1d18) != 0) {
    uVar1 = *(undefined1 *)(*(long *)(param_1 + 0x1d18) + 0x2a9);
  }
  return uVar1;
}


// ===== 00347520 gpuIsApmFeatureEnabled_IMPL =====

undefined1 gpuIsApmFeatureEnabled_IMPL(long param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (*(long *)(param_1 + 0x1d18) != 0) {
    uVar1 = *(undefined1 *)(*(long *)(param_1 + 0x1d18) + 0x2aa);
  }
  return uVar1;
}


// ===== 00347540 gpuIsCCorApmFeatureEnabled_IMPL =====

bool gpuIsCCorApmFeatureEnabled_IMPL(long param_1)

{
  long lVar1;
  bool bVar2;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  bVar2 = false;
  if ((lVar1 != 0) && (bVar2 = true, *(char *)(lVar1 + 0x2a9) == '\0')) {
    return *(char *)(lVar1 + 0x2aa) != '\0';
  }
  return bVar2;
}


// ===== 00347580 gpuIsCCDevToolsModeEnabled_IMPL =====

undefined1 gpuIsCCDevToolsModeEnabled_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x2a9) != '\0')) {
    return *(undefined1 *)(lVar1 + 0x2ab);
  }
  return 0;
}


// ===== 003475b0 gpuIsCCMultiGpuNvleModeEnabled_IMPL =====

undefined1 gpuIsCCMultiGpuNvleModeEnabled_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x2a9) != '\0')) {
    return *(undefined1 *)(lVar1 + 0x2af);
  }
  return 0;
}


// ===== 003475e0 gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL =====

undefined1 gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x2a9) != '\0')) {
    return *(undefined1 *)(lVar1 + 0x2ae);
  }
  return 0;
}


// ===== 00347610 gpuInitChipInfo_IMPL =====

void gpuInitChipInfo_IMPL(long param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)(param_1 + 0x828) = 0;
  uVar2 = *(uint *)(param_1 + 0x8e8);
  *(uint *)(param_1 + 0x818) = uVar2 >> 0x14 & 0xf;
  *(uint *)(param_1 + 0x81c) = (uVar2 >> 3 & 0x20 | uVar2 >> 0x18 & 0x1f) << 4;
  *(uint *)(param_1 + 0x824) = uVar2 & 0xf;
  uVar1 = *(uint *)(param_1 + 0x8ec);
  *(uint *)(param_1 + 0x820) = uVar2 >> 4 & 0xf;
  uVar2 = uVar1 >> 0x14;
  *(uint *)(param_1 + 0x834) = uVar1 >> 0x10 & 0xf;
  *(uint *)(param_1 + 0x82c) = uVar2 & 0xf;
  *(uint *)(param_1 + 0x830) = uVar2 & 0x3f0;
  *(uint *)(param_1 + 0x838) = uVar1 >> 0xc & 0xf;
  *(uint *)(param_1 + 0x83c) = uVar1 >> 8 & 0xf;
  *(uint *)(param_1 + 0x80c) = uVar2 & 0xf;
  *(uint *)(param_1 + 0x808) = uVar2 & 0x3f0;
  *(uint *)(param_1 + 0x814) = uVar2 & 0x3ff;
  return;
}


// ===== 003476d0 gpuGetDmaEndAddress_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long gpuGetDmaEndAddress_IMPL(long param_1)

{
  byte bVar1;
  
  bVar1 = (**(code **)(*(long *)(param_1 + 0x4d8) + 0x68))();
  return (1L << (bVar1 & 0x3f)) + -1;
}


// ===== 00347700 gpuGetStaticInfo =====

long gpuGetStaticInfo(long param_1)

{
  if (*(char *)(param_1 + 0x908) == '\0') {
    return 0;
  }
  if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) != 0) {
    return *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x1d0;
  }
  nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
  return 0;
}


// ===== 00347770 gpuGetGspStaticInfo =====

long gpuGetGspStaticInfo(long param_1)

{
  if (*(char *)(param_1 + 0x90a) != '\0') {
    return 0;
  }
  if (*(long *)(param_1 + 0x1ba8) != 0) {
    return *(long *)(param_1 + 0x1ba8) + 0x69f70;
  }
  nvAssertFailedNoLog("GPU_GET_KERNEL_GSP(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17f8);
  return 0;
}


// ===== 003477d0 gpuGetVgpuRpc =====

undefined8 gpuGetVgpuRpc(long param_1)

{
  if (*(char *)(param_1 + 0x908) == '\0') {
    return 0;
  }
  if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) != 0) {
    return *(undefined8 *)
            (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x26158);
  }
  nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x1810);
  return 0;
}


// ===== 00347840 gpuGetRpc =====

undefined8 gpuGetRpc(long param_1)

{
  if (*(char *)(param_1 + 0x908) != '\0') {
    if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) == 0) {
      nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x1810);
      return 0;
    }
    return *(undefined8 *)
            (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x26158);
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    if (*(char *)(param_1 + 0x90a) == '\0') {
      return 0;
    }
  }
  else if (*(char *)(param_1 + 0x90a) == '\0') {
    if (*(long *)(param_1 + 0x1ba8) == 0) {
      nvAssertFailedNoLog("GPU_GET_KERNEL_GSP(pGpu) != NULL","src/kernel/gpu/gpu.c",0x1805);
      return 0;
    }
    return *(undefined8 *)(*(long *)(param_1 + 0x1ba8) + 0xa38);
  }
  if (*(long *)(param_1 + 0x1bb0) != 0) {
    return *(undefined8 *)(*(long *)(param_1 + 0x1bb0) + 0x168);
  }
  nvAssertFailedNoLog("GPU_GET_DCECLIENTRM(pGpu) != NULL","src/kernel/gpu/gpu.c",0x1800);
  return 0;
}


// ===== 00347940 gpuStateUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

uint gpuStateUnload_IMPL(long param_1,uint param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 extraout_RDX_03;
  undefined8 extraout_RDX_04;
  undefined8 extraout_RDX_05;
  undefined8 extraout_RDX_06;
  undefined8 extraout_RDX_07;
  undefined8 uVar9;
  undefined8 extraout_RDX_08;
  undefined8 extraout_RDX_09;
  undefined8 extraout_RDX_10;
  ulong uVar10;
  ulong uVar11;
  undefined1 auVar12 [16];
  uint local_100;
  undefined4 local_f0;
  undefined1 local_ec [4];
  undefined8 local_e8;
  undefined8 local_e0;
  undefined4 local_d8 [6];
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 auStack_b8 [3];
  undefined8 auStack_a0 [4];
  undefined4 auStack_80 [20];
  
  local_e8 = 0;
  iVar3 = osGetPerformanceCounter(&local_e8);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog(iVar3,"osGetPerformanceCounter(&startTimens)","src/kernel/gpu/gpu.c");
  }
  *(undefined1 *)(param_1 + 0x4917) = 1;
  local_e0 = 0;
  iVar3 = osGetPerformanceCounter(&local_e0);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog(iVar3,"osGetPerformanceCounter(&startTimens)","src/kernel/gpu/gpu.c");
  }
  rmapiControlCacheFreeNonPersistentCacheForGpu(*(undefined4 *)(param_1 + 0x7a4));
  cVar2 = hypervisorIsVgxHyper_IMPL();
  if (cVar2 == '\0') {
    gpuFabricProbeStop(*(undefined8 *)(param_1 + 0x4c0));
  }
  portMemFree(*(undefined8 *)(param_1 + 0x3c60));
  uVar5 = *(uint *)(param_1 + 0x8c8);
  *(undefined8 *)(param_1 + 0x3c60) = 0;
  uVar9 = extraout_RDX;
  if (uVar5 != 0) {
    lVar8 = *(long *)(param_1 + 0x8c0);
    uVar10 = 0;
    do {
      uVar4 = *(uint *)(lVar8 + uVar10 * 4);
      if (uVar4 >> 8 == 0xf3e155) {
        auVar12 = gpuGetEngstate_IMPL_part_0(param_1);
      }
      else {
        auVar12 = gpuGetEngstateNoShare_IMPL(param_1,uVar4);
      }
      uVar9 = auVar12._8_8_;
      plVar7 = auVar12._0_8_;
      if (plVar7 != (long *)0x0) {
        engstateLogStateTransitionPre_IMPL(plVar7,7,local_d8);
        iVar3 = (**(code **)(*plVar7 + 0x78))(param_1,plVar7,param_2);
        engstateLogStateTransitionPost_IMPL(plVar7,7,local_d8);
        uVar9 = extraout_RDX_00;
        if ((iVar3 != 0) && (iVar3 != 0x56)) {
          nvDbg_Printf("src/kernel/gpu/gpu.c",0xe69,"gpuStatePreUnload",4,
                       "NVRM: Failed to pre unload engine with descriptor index: 0x%x and descriptor: 0x%x\n"
                       ,uVar10 & 0xffffffff);
          uVar9 = extraout_RDX_02;
          if (*(char *)(param_1 + 0x4910) == '\0') {
            nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0xe6e);
            uVar9 = extraout_RDX_10;
          }
          if (*(int *)(param_1 + 0x4b08) == 0) {
            *(undefined4 *)(param_1 + 0x4b08) = 0x1a;
            *(int *)(param_1 + 0x4b0c) = iVar3;
            _gpuEngineTransitionFailureStore_isra_0
                      (param_1,param_1 + 0x4b10,7,*(undefined4 *)((long)plVar7 + 0x4c),local_e0,
                       lVar8,uVar10);
            uVar9 = extraout_RDX_03;
          }
        }
        lVar1 = *(long *)(param_1 + 0x1c20);
        if (lVar1 != 0) {
          bitVectorSetAll_IMPL(&local_c0,0xb4);
          intrServiceStallListAllGpusCond_IMPL(param_1,lVar1,&local_c0);
          uVar9 = extraout_RDX_01;
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar5 != uVar10);
  }
  if ((param_2 & 0x41) == 0) {
    rmapiReportLeakedDevices(1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f));
    uVar9 = extraout_RDX_06;
LAB_00347cf3:
    lVar8 = 0;
    if (*(int *)(param_1 + 0x39f8) != 0) {
      do {
        if (*(long *)(param_1 + 0x3948 + lVar8 * 8) != 0) {
          kvidengFreeLogging_KERNEL(param_1);
          uVar9 = extraout_RDX_07;
        }
        lVar8 = lVar8 + 1;
      } while ((uint)lVar8 < *(uint *)(param_1 + 0x39f8));
    }
  }
  else if ((*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') || ((param_2 & 1) == 0))
  goto LAB_00347cf3;
  local_100 = *(uint *)(param_1 + 0x8c8);
  uVar10 = (ulong)local_100;
  if (local_100 != 0) {
    lVar8 = *(long *)(param_1 + 0x8c0);
    uVar11 = 0;
    local_100 = 0;
    do {
      uVar5 = *(uint *)(lVar8 + uVar11 * 4);
      if (uVar5 >> 8 == 0xf3e155) {
        auVar12 = gpuGetEngstate_IMPL_part_0(param_1);
      }
      else {
        auVar12 = gpuGetEngstateNoShare_IMPL(param_1,uVar5,uVar9);
      }
      uVar9 = auVar12._8_8_;
      plVar7 = auVar12._0_8_;
      if (plVar7 != (long *)0x0) {
        engstateLogStateTransitionPre_IMPL(plVar7,8,local_d8);
        uVar4 = (**(code **)(*plVar7 + 0x80))(param_1,plVar7,param_2);
        engstateLogStateTransitionPost_IMPL(plVar7,8,local_d8);
        uVar9 = extraout_RDX_04;
        if ((uVar4 != 0) && (uVar4 != 0x56)) {
          nvDbg_Printf("src/kernel/gpu/gpu.c",0xefb,"gpuStateUnload_IMPL",4,
                       "NVRM: Failed to unload engine with descriptor index: 0x%x and descriptor: 0x%x\n"
                       ,uVar11 & 0xffffffff,uVar5);
          uVar9 = 0x347c5d;
          if ((*(char *)(param_1 + 0x4910) == '\0') &&
             (nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0xf00),
             uVar9 = extraout_RDX_09, (param_2 & 1) != 0)) {
            auVar12 = objDynamicCastById_IMPL(plVar7,0x174e21);
            uVar9 = auVar12._8_8_;
            if (auVar12._0_8_ != 0) {
              local_100 = uVar4;
            }
          }
          if (*(int *)(param_1 + 0x4b08) == 0) {
            *(uint *)(param_1 + 0x4b0c) = uVar4;
            *(undefined4 *)(param_1 + 0x4b08) = 0x1c;
            _gpuEngineTransitionFailureStore_isra_0
                      (param_1,param_1 + 0x4b10,8,*(undefined4 *)((long)plVar7 + 0x4c),local_e8,
                       lVar8,uVar11);
            uVar9 = extraout_RDX_08;
          }
        }
        lVar1 = *(long *)(param_1 + 0x1c20);
        if (lVar1 != 0) {
          bitVectorSetAll_IMPL(&local_c0,0xb4);
          intrServiceStallListAllGpusCond_IMPL(param_1,lVar1,&local_c0);
          uVar9 = extraout_RDX_05;
        }
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 != uVar10);
  }
  if (((*(char *)(param_1 + 0x4913) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) &&
     ((param_2 & 1) != 0)) {
    lVar8 = gpuGetRpc(param_1);
    if ((lVar8 != 0) &&
       (uVar5 = (**(code **)(lVar8 + 0x120))(param_1,lVar8,*(code **)(lVar8 + 0x120)), uVar5 != 0))
    {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0xf2a,"gpuStateUnload_IMPL",4,
                   "NVRM: RPC to save host hibernation data failed, status 0x%x\n",uVar5);
      if (*(int *)(param_1 + 0x4b08) != 0) {
        return uVar5;
      }
      *(undefined4 *)(param_1 + 0x4b08) = 0x1d;
      *(uint *)(param_1 + 0x4b0c) = uVar5;
      return uVar5;
    }
    if (*(char *)(param_1 + 0x4a4e) != '\0') {
      vgpuGspTeardownBuffers(param_1);
    }
  }
  lVar8 = *(long *)(param_1 + 0x8c0);
  local_e0 = 0;
  uVar5 = *(uint *)(param_1 + 0x8c8);
  iVar3 = osGetPerformanceCounter(&local_e0);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog(iVar3,"osGetPerformanceCounter(&startTimens)","src/kernel/gpu/gpu.c");
  }
  if (uVar5 != 0) {
    uVar10 = 0;
    do {
      uVar4 = *(uint *)(lVar8 + uVar10 * 4);
      if (uVar4 >> 8 == 0xf3e155) {
        plVar7 = (long *)gpuGetEngstate_IMPL_part_0(param_1);
      }
      else {
        plVar7 = (long *)gpuGetEngstateNoShare_IMPL(param_1,uVar4);
      }
      if (plVar7 != (long *)0x0) {
        engstateLogStateTransitionPre_IMPL(plVar7,9,local_d8);
        iVar3 = (**(code **)(*plVar7 + 0x88))(param_1,plVar7,param_2);
        engstateLogStateTransitionPost_IMPL(plVar7,9,local_d8);
        if ((iVar3 != 0) && (iVar3 != 0x56)) {
          nvDbg_Printf("src/kernel/gpu/gpu.c",0xf99,"gpuStatePostUnload",4,
                       "NVRM: Failed to post unload engine with descriptor index: 0x%x and descriptor: 0x%x\n"
                       ,uVar10 & 0xffffffff);
          if (*(char *)(param_1 + 0x4910) == '\0') {
            nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0xf9e);
          }
          if (*(int *)(param_1 + 0x4b08) == 0) {
            *(undefined4 *)(param_1 + 0x4b08) = 0x1e;
            *(int *)(param_1 + 0x4b0c) = iVar3;
            _gpuEngineTransitionFailureStore_isra_0
                      (param_1,param_1 + 0x4b10,9,*(undefined4 *)((long)plVar7 + 0x4c),local_e0,
                       lVar8,uVar10);
          }
        }
        lVar1 = *(long *)(param_1 + 0x1c20);
        if (lVar1 != 0) {
          bitVectorSetAll_IMPL(&local_c0,0xb4);
          intrServiceStallListAllGpusCond_IMPL(param_1,lVar1,&local_c0);
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 != uVar5);
  }
  if ((*(char *)(param_1 + 0x4a4e) != '\0') && (*(char *)(param_1 + 0x909) != '\0')) {
    iVar3 = gpumgrGetGpuAttachInfo(local_ec,&local_f0);
    if (iVar3 == 0) {
      local_d8[0] = 0;
      while (lVar8 = gpumgrGetNextGpu(local_f0,local_d8), lVar8 != 0) {
        uVar10 = 0;
        do {
          uVar5 = (int)uVar10 + 0x20;
          uVar11 = (ulong)uVar5;
          *(undefined8 *)((long)auStack_b8 + uVar10) = 0;
          *(undefined8 *)((long)auStack_b8 + uVar10 + 8) = 0;
          *(undefined8 *)((long)auStack_a0 + (uVar10 - 8)) = 0;
          *(undefined8 *)((long)auStack_a0 + uVar10) = 0;
          uVar10 = uVar11;
        } while (uVar5 < 0x60);
        *(undefined8 *)((long)auStack_b8 + uVar11) = 0;
        *(undefined8 *)((long)auStack_b8 + uVar11 + 8) = 0;
        *(undefined8 *)((long)auStack_a0 + (uVar11 - 8)) = 0;
        *(undefined4 *)((long)auStack_a0 + uVar11) = 0;
        if (*(char *)(lVar8 + 0x4918) != '\0') {
          local_bc = *(undefined4 *)(param_1 + 0x7ac);
          local_c0 = 1;
          if (*(code **)(lVar8 + 0x3b90) == _gpuRmApiControl) {
            iVar6 = _gpuRmApiControl();
          }
          else {
            iVar6 = (**(code **)(lVar8 + 0x3b90))
                              (lVar8 + 0x3b58,*(undefined4 *)(lVar8 + 0x3b34),
                               *(undefined4 *)(lVar8 + 0x3b3c),0x20800ab6,&local_c0,0x84);
          }
          if ((iVar6 != 0) &&
             (nvCheckOkFailedNoLog
                        (4,iVar6,
                         "pPeerRmApi->Control(pPeerRmApi, pPeerGpu->hInternalClient, pPeerGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_REMOVE_P2P_CAPS, &removeP2PCapsParams, sizeof(removeP2PCapsParams))"
                         ,"src/kernel/gpu/gpu.c",0xcb6), iVar3 == 0)) {
            iVar3 = iVar6;
          }
        }
      }
      if (iVar3 == 0) goto LAB_00347fe0;
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar3,"gpumgrGetGpuAttachInfo(&gpuCount, &attachMask)","src/kernel/gpu/gpu.c",
                 0xca6);
    }
    nvAssertOkFailedNoLog(iVar3,"_gpuRemoveP2pCapsFromPeerGpus(pGpu)","src/kernel/gpu/gpu.c");
  }
LAB_00347fe0:
  if ((param_2 & 1) == 0) {
    (**(code **)(param_1 + 0x2b0))(param_1);
  }
  (**(code **)(param_1 + 0x250))(param_1);
  *(undefined2 *)(param_1 + 0x4917) = 0;
  if ((local_100 != 0) && (*(int *)(param_1 + 0x4b08) == 0)) {
    *(undefined4 *)(param_1 + 0x4b08) = 0x1d;
    *(uint *)(param_1 + 0x4b0c) = local_100;
  }
  return local_100;
}


// ===== 003483c0 gpuCheckSysmemAccess_IMPL =====

undefined8 gpuCheckSysmemAccess_IMPL(void)

{
  return 1;
}


// ===== 003483d0 gpuGetCeFaultMethodBufferSize_KERNEL =====

undefined8 gpuGetCeFaultMethodBufferSize_KERNEL(long param_1,int *param_2)

{
  int iVar1;
  int local_c;
  
  local_c = *(int *)(param_1 + 0x900);
  if ((local_c != 0) || (iVar1 = kceGetFaultMethodBufferSize_IMPL(param_1,&local_c), iVar1 == 0)) {
    *param_2 = local_c;
  }
  return 0;
}


// ===== 00348420 gpuSetGC6SBIOSCapabilities_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuSetGC6SBIOSCapabilities_IMPL(long param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0x226e) = 0;
  if ((*(char *)(param_1 + 0x2218) != '\0') && (*(int *)(param_1 + 0x2264) == 0)) {
    iVar1 = (**(code **)(param_1 + 0x2c0))();
    if (iVar1 == 0) {
      iVar2 = 0;
      if ((*(uint *)(param_1 + 0x2268) & 1) != 0) {
        *(undefined1 *)(param_1 + 0x226e) = 1;
        iVar2 = iVar1;
        if ((*(short *)(param_1 + 0x226c) != 0x103) && (*(short *)(param_1 + 0x226c) != 0x200)) {
          nvDbg_Printf("src/kernel/gpu/gpu.c",0x187a,"gpuSetGC6SBIOSCapabilities_IMPL",4,
                       "NVRM: Unsupported JT revision ID. GC6 is being disabled. Update the board EC PIC FW. On Windows, update the SBIOS GC6 AML as well.\n"
                      );
          *(undefined1 *)(param_1 + 0x226e) = 0;
        }
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x1867,"gpuSetGC6SBIOSCapabilities_IMPL",4,
                   "NVRM: Unsupported JT revision ID. GC6 is being disabled.\n");
      iVar2 = iVar1;
    }
    return iVar2;
  }
  return 0x56;
}


// ===== 00348510 gpuSimEscapeWrite =====

undefined8 gpuSimEscapeWrite(long param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  undefined8 uVar1;
  
  if (4 < param_4) {
    nvAssertFailedNoLog("Size <= (sizeof Value)","src/kernel/gpu/gpu.c",0x188c);
    return 0x1f;
  }
  if (*(char *)(param_1 + 0x4a26) == '\0') {
    uVar1 = osSimEscapeWrite();
    return uVar1;
  }
  return 0x56;
}


// ===== 00348570 gpuSimEscapeRead =====

undefined8
gpuSimEscapeRead(long param_1,undefined8 param_2,undefined4 param_3,uint param_4,undefined4 *param_5
                )

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  if (param_4 < 5) {
    uVar1 = 0x56;
    local_c = 0;
    uVar2 = 0;
    if (*(char *)(param_1 + 0x4a26) == '\0') {
      uVar1 = osSimEscapeRead(param_1,param_2,param_3,param_4,&local_c);
      uVar2 = local_c;
    }
    *param_5 = uVar2;
    return uVar1;
  }
  nvAssertFailedNoLog("Size <= (sizeof *Value)","src/kernel/gpu/gpu.c",0x189c);
  return 0x1f;
}


// ===== 003485f0 gpuGetLitterValues_KERNEL =====

undefined4 gpuGetLitterValues_KERNEL(long param_1,int param_2)

{
  long lVar1;
  ulong uVar2;
  
  if (*(char *)(*(long *)(param_1 + 0x1bc8) + 0x438) == '\0') {
    nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                        ,"src/kernel/gpu/gpu.c",0x1922);
  }
  else {
    lVar1 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x430);
    uVar2 = 0;
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pGrInfo != NULL","src/kernel/gpu/gpu.c",0x1924);
    }
    else {
      do {
        if (*(int *)(lVar1 + uVar2 * 8) == param_2) {
          return *(undefined4 *)(lVar1 + 4 + (uVar2 & 0xffffffff) * 8);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 != 0x3b);
    }
  }
  return 0;
}


// ===== 00348670 gpuGetChipDetails_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuGetChipDetails_IMPL(long param_1,uint *param_2)

{
  int iVar1;
  undefined1 local_58 [4];
  undefined1 local_54 [52];
  
  iVar1 = (**(code **)(param_1 + 0x1f0))(param_1,local_58);
  if (iVar1 == 0) {
    *param_2 = (uint)*(ushort *)(param_1 + 0x7f6);
    portStringCopy(param_2 + 1,4,local_54,9);
    param_2[2] = *(uint *)(param_1 + 0x834);
    param_2[3] = *(uint *)(param_1 + 0x838);
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"gpuGetSkuInfo_HAL(pGpu, &biosGetSKUInfoParams)","src/kernel/gpu/gpu.c",0x1936);
  return iVar1;
}


// ===== 00348710 gpuIsAmpereErrorContainmentXidEnabled_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuIsAmpereErrorContainmentXidEnabled_KERNEL(long param_1)

{
  (**(code **)(param_1 + 0x350))();
  return;
}


// ===== 00348720 gpuCheckEngineWithOrderList_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuCheckEngineWithOrderList_KERNEL(long param_1,uint param_2,char param_3)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  undefined7 uVar10;
  ulong uVar9;
  undefined1 auVar11 [16];
  byte local_42;
  byte local_41;
  undefined8 local_40;
  undefined4 local_38;
  uint local_34;
  byte bStack_2e;
  undefined4 local_2c;
  
  uVar7 = 0;
  _local_34 = 0;
  local_2c = 0;
  local_40 = 0;
  local_38 = 0;
  if (*(char *)(param_1 + 0x908) == '\0') {
    uVar9 = 0;
    if (*(char *)(param_1 + 0x90a) != '\0') goto LAB_0034889e;
    lVar5 = *(long *)(param_1 + 0x1ba8);
    if (lVar5 == 0) {
      nvAssertFailedNoLog("GPU_GET_KERNEL_GSP(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17f8);
      uVar9 = 0;
      goto LAB_0034889e;
    }
    local_40 = *(undefined8 *)(lVar5 + 0x6a49c);
    local_38 = *(undefined4 *)(lVar5 + 0x6a4a4);
  }
  else {
    if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) == 0) {
      nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
      return 0;
    }
    local_40 = *(undefined8 *)
                (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0xa938);
  }
  iVar3 = gpuGetRmEngineTypeCapMask_IMPL(&local_40,3,&local_34);
  if (iVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar3,
               "gpuGetRmEngineTypeCapMask(nv2080EngineCaps, NVGPU_ENGINE_CAPS_MASK_ARRAY_MAX, rmEngineCaps)"
               ,"src/kernel/gpu/gpu.c",0x19f5);
    return 0;
  }
  uVar8 = param_2 >> 8;
  if (uVar8 == 0x9a25e4) {
    return 0;
  }
  uVar10 = (undefined7)(uVar7 >> 8);
  cVar2 = (char)param_2;
  if (uVar8 < 0x9a25e5) {
    if (uVar8 == 0x55952e) {
      if (*(char *)(param_1 + 0x909) != '\0') {
        return 1;
      }
      uVar9 = CONCAT71(uVar10,*(char *)(param_1 + 0x90a) != '\0');
      goto LAB_0034889e;
    }
    if (uVar8 < 0x55952f) {
      if (uVar8 == 0x2b3a54) {
        uVar9 = CONCAT71(uVar10,((&local_34)[(param_2 & 0xff) + 0x36 >> 5] &
                                1 << (cVar2 + 0x36U & 0x1f)) != 0);
        goto LAB_0034889e;
      }
      if (uVar8 < 0x2b3a55) {
        if (uVar8 == 0x28c408) {
          uVar9 = (ulong)(bStack_2e >> 1 & 1);
          goto LAB_0034889e;
        }
      }
      else {
        if (uVar8 == 0x3827ff) {
          return 1;
        }
        if (uVar8 == 0x4c57c4) {
          return 1;
        }
        if (uVar8 == 0x2b424b) {
          return 1;
        }
      }
    }
    else {
      if (uVar8 == 0x899e48) {
        return 1;
      }
      if (uVar8 < 0x899e49) {
        if (uVar8 == 0x5ca633) {
          return 1;
        }
        if (uVar8 == 0x793ceb) {
          local_41 = 0;
          if (*(char *)(param_1 + 0x908) != '\0') {
            uVar8 = (param_2 & 0xff) + 9;
            local_41 = ((&local_34)[uVar8 >> 5] & 1 << (cVar2 + 9U & 0x1f)) != 0;
            auVar11 = (**(code **)(*(long *)(param_1 + 0x1bc0) + 0x168))(param_1);
            uVar6 = auVar11._8_8_;
            uVar9 = (ulong)uVar8;
            uVar7 = uVar6;
            if (uVar9 <= uVar6) {
              uVar7 = uVar9;
            }
            if (((auVar11._0_8_ <= uVar7) && (uVar9 <= uVar6)) &&
               (iVar3 = (**(code **)(param_1 + 0x418))(param_1,param_2,&local_41), iVar3 != 0)) {
              nvCheckFailedNoLog(1,
                                 "gpuRequireGrCePresence_HAL(pGpu, engDesc, &isEnginePresent) == NV_OK"
                                 ,"src/kernel/gpu/gpu.c",0x1a32);
            }
            uVar9 = (ulong)local_41;
            goto LAB_0034889e;
          }
          lVar5 = gpumgrGetParentGPU(param_1);
          if ((param_1 != lVar5) && (lVar5 = param_1, *(char *)(param_1 + 0x481) == '\0')) {
            lVar5 = gpumgrGetParentGPU(param_1);
          }
          lVar5 = *(long *)(lVar5 + 0x1cd0);
          if (lVar5 == 0) {
            nvAssertFailedNoLog("pKernelFifo != NULL","src/kernel/gpu/gpu.c",0x1a21);
            uVar9 = 0;
            goto LAB_0034889e;
          }
          iVar3 = (**(code **)(lVar5 + 0x2c0))(param_1,lVar5,param_2,&local_42);
          uVar9 = 0;
          if (iVar3 != 0) goto LAB_0034889e;
          goto LAB_00348ad8;
        }
      }
      else {
        if (uVar8 == 0x8dd911) {
          return 1;
        }
        if (uVar8 == 0x8f99e1) {
          uVar9 = CONCAT71(uVar10,((&local_34)[(param_2 & 0xff) + 0x1d >> 5] &
                                  1 << (cVar2 + 0x1dU & 0x1f)) != 0);
          goto LAB_0034889e;
        }
      }
    }
  }
  else {
    if (uVar8 == 0xd334df) {
      if (param_2 == 0xd334df00) {
        return 1;
      }
      lVar5 = gpumgrGetParentGPU(param_1);
      uVar9 = uVar7;
      if ((param_1 != lVar5) && (lVar5 = param_1, *(char *)(param_1 + 0x481) == '\0')) {
        lVar5 = gpumgrGetParentGPU(param_1);
        uVar9 = uVar7;
      }
      lVar5 = *(long *)(lVar5 + 0x1cd0);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pKernelFifo != NULL","src/kernel/gpu/gpu.c",0x1a53);
        return 0;
      }
      iVar3 = (**(code **)(lVar5 + 0x2c0))(param_1,lVar5,param_2,&local_42);
      if (iVar3 != 0) {
        return 0;
      }
LAB_00348ad8:
      uVar9 = CONCAT71((int7)(uVar9 >> 8),local_42 != 0);
      goto LAB_0034889e;
    }
    if (uVar8 < 0xd334e0) {
      if (uVar8 == 0xb33b15) {
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x1a5c,"gpuCheckEngineWithOrderList_KERNEL",4,
                     "NVRM: Query for ENG_INVALID considered erroneous: %d\n",param_2);
        uVar9 = 1;
        goto LAB_0034889e;
      }
      if (uVar8 < 0xb33b16) {
        if (uVar8 == 0x9ddede) {
          return 1;
        }
        if (uVar8 == 0xb02365) {
          return 1;
        }
        if (uVar8 == 0x9aad0e) {
          return 1;
        }
      }
      else {
        if (uVar8 == 0xcc4c31) {
          return 1;
        }
        if (uVar8 < 0xcc4c32) {
          if (uVar8 == 0xbcadd3) {
            return 0;
          }
          if (uVar8 == 0xc06e44) {
            return 1;
          }
        }
        else {
          if (uVar8 == 0xd1755e) {
            return 0;
          }
          if (uVar8 == 0xd1c956) {
            return 1;
          }
        }
      }
    }
    else {
      if (uVar8 == 0xdd7bab) {
        uVar9 = CONCAT71(uVar10,((&local_34)[(param_2 & 0xff) + 0x3e >> 5] &
                                1 << (cVar2 + 0x3eU & 0x1f)) != 0);
        goto LAB_0034889e;
      }
      if (uVar8 < 0xdd7bac) {
        if (uVar8 == 0xdb32a1) {
          return 0;
        }
        if (0xdb32a0 < uVar8) {
          if (uVar8 == 0xdbe523) {
            return 1;
          }
          if (uVar8 == 0xdd19be) {
            return 1;
          }
        }
      }
      else {
        if (uVar8 == 0xe97b6c) {
          uVar9 = CONCAT71(uVar10,((&local_34)[(param_2 & 0xff) + 0x25 >> 5] &
                                  1 << (cVar2 + 0x25U & 0x1f)) != 0);
          goto LAB_0034889e;
        }
        if (uVar8 == 0xf3d722) {
          return 0;
        }
      }
    }
  }
  uVar9 = 0;
  if (param_3 != '\0') {
    if (*(uint *)(param_1 + 0x8c8) != 0) {
      puVar4 = *(uint **)(param_1 + 0x8a8);
      puVar1 = puVar4 + *(uint *)(param_1 + 0x8c8);
      do {
        if (param_2 == *puVar4) {
          return 1;
        }
        puVar4 = puVar4 + 1;
      } while (puVar4 != puVar1);
    }
    local_42 = 0;
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x1a6d,"gpuCheckEngineWithOrderList_KERNEL",4,
                 "NVRM: Unable to check engine ID: 0x%x\n",param_2);
    uVar9 = (ulong)local_42;
    if (local_42 == 0) {
      nvAssertFailedNoLog("bSupported","src/kernel/gpu/gpu.c",0x1a6f);
      uVar9 = (ulong)local_42;
    }
  }
LAB_0034889e:
  return uVar9 & 0xffffffff;
}


// ===== 00348dc0 gpuDeleteEngineOnPreInit_IMPL =====

undefined4 gpuDeleteEngineOnPreInit_IMPL(long param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
  uVar1 = *(uint *)(param_1 + 0x8c8);
  if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
    if ((*(char *)(param_1 + 0x908) != '\0') &&
       (cVar2 = gpuCheckEngineWithOrderList_KERNEL(param_1,param_2,0), cVar2 != '\0'))
    goto LAB_00348ed0;
LAB_00348e07:
    gpuDeleteClassFromClassDBByEngTag_IMPL(param_1,param_2);
    if (uVar1 == 0) goto LAB_00348f08;
    cVar2 = '\0';
  }
  else {
    cVar2 = gpuCheckEngineWithOrderList_KERNEL(param_1,param_2,0);
    if (cVar2 == '\0') goto LAB_00348e07;
LAB_00348ed0:
    if (uVar1 == 0) {
      return 0;
    }
  }
  piVar4 = *(int **)(param_1 + 0x8b8);
  piVar5 = piVar4 + uVar1;
  do {
    if (param_2 == *piVar4) {
      *piVar4 = -0x4cc4eb00;
    }
    piVar4 = piVar4 + 1;
  } while (piVar4 != piVar5);
  piVar4 = *(int **)(param_1 + 0x8c0);
  piVar5 = piVar4 + uVar1;
  do {
    if (param_2 == *piVar4) {
      *piVar4 = -0x4cc4eb00;
    }
    piVar4 = piVar4 + 1;
  } while (piVar4 != piVar5);
  piVar4 = *(int **)(param_1 + 0x8a8);
  piVar5 = piVar4 + uVar1;
  do {
    if (param_2 == *piVar4) {
      *piVar4 = -0x4cc4eb00;
    }
    piVar4 = piVar4 + 1;
  } while (piVar4 != piVar5);
  piVar5 = *(int **)(param_1 + 0x8b0);
  piVar4 = piVar5 + uVar1;
  do {
    if (param_2 == *piVar5) {
      *piVar5 = -0x4cc4eb00;
    }
    piVar5 = piVar5 + 1;
  } while (piVar4 != piVar5);
  if (cVar2 != '\0') {
    return 0;
  }
LAB_00348f08:
  iVar3 = gpuUpdateEngineTable_IMPL(param_1);
  uVar6 = 0;
  if (iVar3 != 0) {
    uVar6 = 0x40;
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x850,"gpuDeleteEngineOnPreInit_IMPL",4,
                 "NVRM: Update engine table operation failed!\n");
  }
  return uVar6;
}


// ===== 00348f70 __pfx_gpuStatePreInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int __pfx_gpuStatePreInit_IMPL(long param_1)

{
  long lVar1;
  uint *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  long lVar13;
  uint *puVar14;
  ulong uVar15;
  uint uVar16;
  uint uStack_54;
  undefined1 auStack_50 [32];
  
  iVar6 = (**(code **)(param_1 + 0xb8))();
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog(iVar6,"gpuInitBranding(pGpu)","src/kernel/gpu/gpu.c",0x86f);
    return iVar6;
  }
  (**(code **)(param_1 + 0xc0))(param_1);
  (**(code **)(param_1 + 0x360))(param_1);
  cVar4 = rmGpuLockIsOwner();
  lVar8 = g_pSys;
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/gpu.c",0x880);
    return 0x2f;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    if (*(char *)(param_1 + 0x90a) == '\0') {
      lVar13 = *(long *)(param_1 + 0x1ba8);
      if (lVar13 != 0) {
        uVar5 = *(undefined4 *)(lVar13 + 0x6a570);
        *(undefined4 *)(param_1 + 0x3b34) = uVar5;
        *(undefined4 *)(param_1 + 0x3b38) = *(undefined4 *)(lVar13 + 0x6a574);
        *(undefined4 *)(param_1 + 0x3b3c) = *(undefined4 *)(lVar13 + 0x6a578);
        goto LAB_003490f4;
      }
      nvAssertFailedNoLog("GPU_GET_KERNEL_GSP(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17f8);
    }
    iVar6 = 0x40;
    nvAssertFailedNoLog("pGSCI != NULL","src/kernel/gpu/gpu.c",0x3d8);
    goto LAB_00349822;
  }
  if (*(char *)(param_1 + 0x90a) == '\0') {
    uVar12 = rmapiGetInterface(4);
    iVar6 = rmapiutilAllocClientAndDeviceHandles
                      (uVar12,param_1,param_1 + 0x3b34,param_1 + 0x3b38,param_1 + 0x3b3c);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "rmapiutilAllocClientAndDeviceHandles( pRmApi, pGpu, &pGpu->hInternalClient, &pGpu->hInternalDevice, &pGpu->hInternalSubdevice)"
                 ,"src/kernel/gpu/gpu.c",999);
      goto LAB_00349822;
    }
    iVar6 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(param_1 + 0x3b34),param_1 + 0x3b50);
    if (iVar6 == 0) {
      iVar6 = subdeviceGetByHandle_IMPL
                        (*(undefined8 *)(param_1 + 0x3b50),*(undefined4 *)(param_1 + 0x3b3c),
                         param_1 + 0x3b48);
      if (iVar6 == 0) {
        uVar5 = *(undefined4 *)(param_1 + 0x3b34);
        goto LAB_003490f4;
      }
      nvAssertOkFailedNoLog
                (iVar6,
                 "subdeviceGetByHandle(pGpu->pCachedRsClient, pGpu->hInternalSubdevice, &pGpu->pCachedSubdevice)"
                 ,"src/kernel/gpu/gpu.c",0x3ec);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar6,
                 "serverGetClientUnderLock(&g_resServ, pGpu->hInternalClient, &pGpu->pCachedRsClient)"
                 ,"src/kernel/gpu/gpu.c",0x3ea);
    }
LAB_0034981a:
    _gpuFreeInternalObjects(param_1);
LAB_00349822:
    nvAssertOkFailedNoLog(iVar6,"_gpuAllocateInternalObjects(pGpu)","src/kernel/gpu/gpu.c",0x882);
    return iVar6;
  }
  if (*(long *)(param_1 + 0x1bb0) == 0) {
    nvAssertFailedNoLog("GPU_GET_DCECLIENTRM(pGpu) != NULL","src/kernel/gpu/gpu.c",0x3c7);
    uVar5 = 0xc1e00000;
  }
  else {
    uVar5 = *(undefined4 *)(*(long *)(param_1 + 0x1bb0) + 0x178);
  }
  *(undefined4 *)(param_1 + 0x3b34) = uVar5;
  *(undefined8 *)(param_1 + 0x3b38) = 0xabcd2080abcd0080;
LAB_003490f4:
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x3f0,"_gpuAllocateInternalObjects",1,
               "NVRM: GPU-%d allocated hInternalClient=0x%08x\n",*(undefined4 *)(param_1 + 0x7a4),
               uVar5);
  if ((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x90a) != '\0')) {
    rmapiControlCacheSetGpuAttrForObject
              (*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),param_1);
    rmapiControlCacheSetGpuAttrForObject
              (*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b38),param_1);
  }
  if (*(char *)(lVar8 + 0x7e) == '\0') {
    *(undefined4 *)(param_1 + 0x3b40) = 0;
  }
  else {
    lVar8 = rmapiGetInterface(4);
    if (*(code **)(lVar8 + 8) == _gpuRmApiAllocWithHandle) {
      iVar6 = _gpuRmApiAllocWithHandle(lVar8,0,0,0,0,param_1 + 0x3b40,4);
    }
    else {
      iVar6 = (**(code **)(lVar8 + 8))(lVar8,0,0,0,0,param_1 + 0x3b40,4);
    }
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &pGpu->hInternalLockStressClient, sizeof(pGpu->hInternalLockStressClient))"
                 ,"src/kernel/gpu/gpu.c",0x405);
      goto LAB_0034981a;
    }
  }
  lVar8 = portMemAllocNonPaged(0x58);
  *(long *)(param_1 + 0x3c58) = lVar8;
  if (lVar8 == 0) {
    iVar6 = 0x51;
    nvAssertFailedNoLog("pGpu->pChipInfo != NULL","src/kernel/gpu/gpu.c",0x382);
LAB_00349882:
    nvAssertOkFailedNoLog(iVar6,"_gpuInitChipInfo(pGpu)","src/kernel/gpu/gpu.c",0x883);
    return iVar6;
  }
  portMemSet(lVar8,0,0x58);
  if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
    iVar6 = _gpuRmApiControl();
  }
  else {
    iVar6 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a36,
                       *(undefined8 *)(param_1 + 0x3c58),0x58);
  }
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_GET_CHIP_INFO, pGpu->pChipInfo, paramSize)"
               ,"src/kernel/gpu/gpu.c",0x386);
    portMemFree(*(undefined8 *)(param_1 + 0x3c58));
    *(undefined8 *)(param_1 + 0x3c58) = 0;
    goto LAB_00349882;
  }
  puVar3 = *(undefined1 **)(param_1 + 0x3c58);
  *(undefined1 *)(param_1 + 0x840) = *puVar3;
  *(undefined4 *)(param_1 + 0x7f4) = *(undefined4 *)(puVar3 + 0xc);
  *(undefined4 *)(param_1 + 0x7fc) = *(undefined4 *)(puVar3 + 0x10);
  *(undefined4 *)(param_1 + 0x800) = *(undefined4 *)(puVar3 + 0x14);
  iVar6 = gpuConstructUserRegisterAccessMap_IMPL(param_1);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,"gpuConstructUserRegisterAccessMap(pGpu)","src/kernel/gpu/gpu.c",0x884);
    return iVar6;
  }
  iVar6 = gpuBuildGenericKernelFalconList_IMPL(param_1);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,"gpuBuildGenericKernelFalconList(pGpu)","src/kernel/gpu/gpu.c",0x885);
    return iVar6;
  }
  iVar6 = gpuBuildKernelVideoEngineList_IMPL(param_1);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog(iVar6,"gpuBuildKernelVideoEngineList(pGpu)","src/kernel/gpu/gpu.c",0x887);
    return iVar6;
  }
  if (*(char *)(param_1 + 0x467) != '\0') {
    cVar4 = (**(code **)(param_1 + 0x370))(param_1);
    *(char *)(param_1 + 0x467) = cVar4;
    if (cVar4 == '\0') {
      *(undefined1 *)(param_1 + 0x46b) = 0;
    }
    iVar6 = kvgpumgrMigTimeslicingModeEnabled(param_1);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,"kvgpumgrMigTimeslicingModeEnabled(pGpu)","src/kernel/gpu/gpu.c",0x892);
      return iVar6;
    }
  }
  if (*(uint *)(param_1 + 0x8c8) == 0) {
    iVar6 = 0;
  }
  else {
    puVar14 = *(uint **)(param_1 + 0x8a8);
    puVar2 = puVar14 + *(uint *)(param_1 + 0x8c8);
    iVar6 = 0;
    do {
      uVar15 = (ulong)*puVar14;
      uVar16 = *puVar14 >> 8;
      if (uVar16 != 0xb33b15) {
        if (uVar16 == 0xf3e155) {
          plVar10 = (long *)gpuGetEngstate_IMPL_part_0(param_1);
        }
        else {
          plVar10 = (long *)gpuGetEngstateNoShare_IMPL(param_1,uVar15);
        }
        if (plVar10 != (long *)0x0) {
          if (((char)plVar10[9] == '\0') &&
             (cVar4 = (**(code **)(*plVar10 + 0x98))(param_1), cVar4 != '\0')) goto LAB_00349339;
          gpuDestroyMissingEngine(param_1,plVar10);
        }
        uVar9 = uVar15 & 0xff;
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x6fc,"gpuRemoveMissingEngines",1,
                     "NVRM: engine 0x%06x:%d is missing, removing\n",uVar16);
        iVar6 = gpuDeleteEngineOnPreInit_IMPL(param_1,uVar15);
        if (iVar6 != 0) {
          iVar6 = 0x40;
          nvAssertFailedNoLog("rmStatus == NV_OK || !\"Error while trying to remove missing engine\""
                              ,"src/kernel/gpu/gpu.c",0x701,uVar9);
        }
      }
LAB_00349339:
      puVar14 = puVar14 + 1;
    } while (puVar2 != puVar14);
  }
  if (*(int *)(param_1 + 0x8a0) != 0) {
    lVar8 = 0;
    do {
      while( true ) {
        lVar13 = *(long *)(param_1 + 0x898) + lVar8 * 8;
        uVar16 = *(uint *)(lVar13 + 4) >> 8;
        if ((*(uint *)(lVar13 + 4) != 0x7ef3cb00) && (uVar16 != 0xb33b15)) break;
LAB_003493c0:
        lVar8 = lVar8 + 1;
        if (*(uint *)(param_1 + 0x8a0) <= (uint)lVar8) goto LAB_003494b0;
      }
      if (uVar16 == 0xf3e155) {
        lVar11 = gpuGetEngstate_IMPL_part_0(param_1);
      }
      else {
        lVar11 = gpuGetEngstateNoShare_IMPL();
      }
      if (lVar11 != 0) goto LAB_003493c0;
      if ((((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) &&
          (*(char *)(param_1 + 0x908) == '\0')) ||
         (cVar4 = gpuCheckEngineWithOrderList_KERNEL(param_1,*(undefined4 *)(lVar13 + 4),0),
         cVar4 == '\0')) {
        iVar7 = gpuDeleteClassFromClassDBByEngTag_IMPL(param_1,*(undefined4 *)(lVar13 + 4));
        if (iVar7 == 0) goto LAB_003493c0;
        nvAssertOkFailedNoLog
                  (iVar7,"gpuDeleteClassFromClassDBByEngTag(pGpu, pCurDesc->engDesc)",
                   "src/kernel/gpu/gpu.c",0x72b);
        goto LAB_00349457;
      }
      lVar8 = lVar8 + 1;
    } while ((uint)lVar8 < *(uint *)(param_1 + 0x8a0));
  }
LAB_003494b0:
  iVar7 = gpuUpdateEngineTable_IMPL(param_1);
  if (iVar7 == 0) {
    iVar7 = 0;
    if (iVar6 == 0) goto LAB_003494c9;
  }
  else {
    nvAssertOkFailedNoLog(0x40,"gpuUpdateEngineTable(pGpu)","src/kernel/gpu/gpu.c",0x730);
  }
  iVar7 = 0x40;
LAB_00349457:
  nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/gpu.c",0x896);
LAB_003494c9:
  *(undefined1 *)(param_1 + 0x4919) = 1;
  if (*(uint *)(param_1 + 0x8c8) != 0) {
    puVar14 = *(uint **)(param_1 + 0x8a8);
    puVar2 = puVar14 + *(uint *)(param_1 + 0x8c8);
    do {
      while( true ) {
        uVar16 = *puVar14;
        if (uVar16 >> 8 == 0xf3e155) {
          lVar8 = gpuGetEngstate_IMPL_part_0(param_1);
        }
        else {
          lVar8 = gpuGetEngstateNoShare_IMPL(param_1,uVar16);
        }
        if (lVar8 != 0) break;
LAB_003494f9:
        puVar14 = puVar14 + 1;
        if (puVar14 == puVar2) goto LAB_00349630;
      }
      engstateLogStateTransitionPre_IMPL(lVar8,2,auStack_50);
      iVar7 = engstateStatePreInit_IMPL(param_1,lVar8);
      engstateLogStateTransitionPost_IMPL(lVar8,2,auStack_50);
      if (iVar7 != 0x56) {
        if (iVar7 == 0) goto LAB_003494f9;
        break;
      }
      if (uVar16 == 0x55952e00) {
        iVar6 = gpuGetClassList_IMPL(param_1,&uStack_54,0,0x55952e00);
        if (iVar6 == 0) {
          lVar13 = portMemAllocNonPaged((ulong)uStack_54 << 2);
          if (((lVar13 != 0) &&
              (iVar6 = gpuGetClassList_IMPL(param_1,&uStack_54,lVar13,0x55952e00), iVar6 == 0)) &&
             (uStack_54 != 0)) {
            lVar11 = 0;
            do {
              lVar1 = lVar11 * 4;
              lVar11 = lVar11 + 1;
              gpuDeleteClassFromClassDBByClassId_IMPL(param_1,*(undefined4 *)(lVar13 + lVar1));
            } while ((uint)lVar11 < uStack_54);
          }
          portMemFree(lVar13);
        }
      }
      else if (uVar16 == 0xa576e200) {
        uVar12 = engstateGetName_IMPL(lVar8);
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x8ca,"gpuStatePreInit_IMPL",3,
                     "NVRM: engine removal in PreInit with NV_ERR_NOT_SUPPORTED is deprecated (%s)\n"
                     ,uVar12);
      }
      else if (uVar16 == 0xe163900) {
        uVar12 = engstateGetName_IMPL(lVar8);
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x8c5,"gpuStatePreInit_IMPL",3,
                     "NVRM: engine removal in PreInit with NV_ERR_NOT_SUPPORTED is deprecated (%s)\n"
                     ,uVar12);
      }
      else {
        uVar12 = engstateGetName_IMPL(lVar8);
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x8cf,"gpuStatePreInit_IMPL",4,
                     "NVRM: disallowing NV_ERR_NOT_SUPPORTED PreInit removal of untracked engine (%s)\n"
                     ,uVar12);
        nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x8d3);
      }
      gpuDestroyMissingEngine(param_1,lVar8);
      iVar7 = gpuDeleteEngineOnPreInit_IMPL(param_1,uVar16);
      if (iVar7 == 0) goto LAB_003494f9;
      iVar7 = 0x40;
      puVar14 = puVar14 + 1;
      nvAssertFailedNoLog("rmStatus == NV_OK || !\"Error while trying to remove missing engine\"",
                          "src/kernel/gpu/gpu.c",0x8dc);
    } while (puVar14 != puVar2);
  }
LAB_00349630:
  if ((*(long *)(param_1 + 0x1b80) != 0) || (cVar4 = osIsGridSupported(param_1), cVar4 == '\0')) {
    gpuDeleteClassFromClassDBByClassId_IMPL(param_1,0xa083);
  }
  if (*(char *)(param_1 + 0x908) != '\0') {
    gpuDeleteClassFromClassDBByClassId_IMPL(param_1,0xde);
  }
  (**(code **)(param_1 + 0x378))(param_1);
  return iVar7;
}


// ===== 00348f80 gpuStatePreInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int gpuStatePreInit_IMPL(long param_1)

{
  long lVar1;
  uint *puVar2;
  undefined1 *puVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  long lVar13;
  uint *puVar14;
  ulong uVar15;
  uint uVar16;
  uint local_54;
  undefined1 local_50 [32];
  
  iVar6 = (**(code **)(param_1 + 0xb8))();
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog(iVar6,"gpuInitBranding(pGpu)","src/kernel/gpu/gpu.c",0x86f);
    return iVar6;
  }
  (**(code **)(param_1 + 0xc0))(param_1);
  (**(code **)(param_1 + 0x360))(param_1);
  cVar4 = rmGpuLockIsOwner();
  lVar8 = g_pSys;
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmGpuLockIsOwner()","src/kernel/gpu/gpu.c",0x880);
    return 0x2f;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    if (*(char *)(param_1 + 0x90a) == '\0') {
      lVar13 = *(long *)(param_1 + 0x1ba8);
      if (lVar13 != 0) {
        uVar5 = *(undefined4 *)(lVar13 + 0x6a570);
        *(undefined4 *)(param_1 + 0x3b34) = uVar5;
        *(undefined4 *)(param_1 + 0x3b38) = *(undefined4 *)(lVar13 + 0x6a574);
        *(undefined4 *)(param_1 + 0x3b3c) = *(undefined4 *)(lVar13 + 0x6a578);
        goto LAB_003490f4;
      }
      nvAssertFailedNoLog("GPU_GET_KERNEL_GSP(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17f8);
    }
    iVar6 = 0x40;
    nvAssertFailedNoLog("pGSCI != NULL","src/kernel/gpu/gpu.c",0x3d8);
    goto LAB_00349822;
  }
  if (*(char *)(param_1 + 0x90a) == '\0') {
    uVar12 = rmapiGetInterface(4);
    iVar6 = rmapiutilAllocClientAndDeviceHandles
                      (uVar12,param_1,param_1 + 0x3b34,param_1 + 0x3b38,param_1 + 0x3b3c);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "rmapiutilAllocClientAndDeviceHandles( pRmApi, pGpu, &pGpu->hInternalClient, &pGpu->hInternalDevice, &pGpu->hInternalSubdevice)"
                 ,"src/kernel/gpu/gpu.c",999);
      goto LAB_00349822;
    }
    iVar6 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(param_1 + 0x3b34),param_1 + 0x3b50);
    if (iVar6 == 0) {
      iVar6 = subdeviceGetByHandle_IMPL
                        (*(undefined8 *)(param_1 + 0x3b50),*(undefined4 *)(param_1 + 0x3b3c),
                         param_1 + 0x3b48);
      if (iVar6 == 0) {
        uVar5 = *(undefined4 *)(param_1 + 0x3b34);
        goto LAB_003490f4;
      }
      nvAssertOkFailedNoLog
                (iVar6,
                 "subdeviceGetByHandle(pGpu->pCachedRsClient, pGpu->hInternalSubdevice, &pGpu->pCachedSubdevice)"
                 ,"src/kernel/gpu/gpu.c",0x3ec);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar6,
                 "serverGetClientUnderLock(&g_resServ, pGpu->hInternalClient, &pGpu->pCachedRsClient)"
                 ,"src/kernel/gpu/gpu.c",0x3ea);
    }
LAB_0034981a:
    _gpuFreeInternalObjects(param_1);
LAB_00349822:
    nvAssertOkFailedNoLog(iVar6,"_gpuAllocateInternalObjects(pGpu)","src/kernel/gpu/gpu.c",0x882);
    return iVar6;
  }
  if (*(long *)(param_1 + 0x1bb0) == 0) {
    nvAssertFailedNoLog("GPU_GET_DCECLIENTRM(pGpu) != NULL","src/kernel/gpu/gpu.c",0x3c7);
    uVar5 = 0xc1e00000;
  }
  else {
    uVar5 = *(undefined4 *)(*(long *)(param_1 + 0x1bb0) + 0x178);
  }
  *(undefined4 *)(param_1 + 0x3b34) = uVar5;
  *(undefined8 *)(param_1 + 0x3b38) = 0xabcd2080abcd0080;
LAB_003490f4:
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x3f0,"_gpuAllocateInternalObjects",1,
               "NVRM: GPU-%d allocated hInternalClient=0x%08x\n",*(undefined4 *)(param_1 + 0x7a4),
               uVar5);
  if ((*(char *)(param_1 + 0x909) != '\0') || (*(char *)(param_1 + 0x90a) != '\0')) {
    rmapiControlCacheSetGpuAttrForObject
              (*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),param_1);
    rmapiControlCacheSetGpuAttrForObject
              (*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b38),param_1);
  }
  if (*(char *)(lVar8 + 0x7e) == '\0') {
    *(undefined4 *)(param_1 + 0x3b40) = 0;
  }
  else {
    lVar8 = rmapiGetInterface(4);
    if (*(code **)(lVar8 + 8) == _gpuRmApiAllocWithHandle) {
      iVar6 = _gpuRmApiAllocWithHandle(lVar8,0,0,0,0,param_1 + 0x3b40,4);
    }
    else {
      iVar6 = (**(code **)(lVar8 + 8))(lVar8,0,0,0,0,param_1 + 0x3b40,4);
    }
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &pGpu->hInternalLockStressClient, sizeof(pGpu->hInternalLockStressClient))"
                 ,"src/kernel/gpu/gpu.c",0x405);
      goto LAB_0034981a;
    }
  }
  lVar8 = portMemAllocNonPaged(0x58);
  *(long *)(param_1 + 0x3c58) = lVar8;
  if (lVar8 == 0) {
    iVar6 = 0x51;
    nvAssertFailedNoLog("pGpu->pChipInfo != NULL","src/kernel/gpu/gpu.c",0x382);
LAB_00349882:
    nvAssertOkFailedNoLog(iVar6,"_gpuInitChipInfo(pGpu)","src/kernel/gpu/gpu.c",0x883);
    return iVar6;
  }
  portMemSet(lVar8,0,0x58);
  if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
    iVar6 = _gpuRmApiControl();
  }
  else {
    iVar6 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a36,
                       *(undefined8 *)(param_1 + 0x3c58),0x58);
  }
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_GET_CHIP_INFO, pGpu->pChipInfo, paramSize)"
               ,"src/kernel/gpu/gpu.c",0x386);
    portMemFree(*(undefined8 *)(param_1 + 0x3c58));
    *(undefined8 *)(param_1 + 0x3c58) = 0;
    goto LAB_00349882;
  }
  puVar3 = *(undefined1 **)(param_1 + 0x3c58);
  *(undefined1 *)(param_1 + 0x840) = *puVar3;
  *(undefined4 *)(param_1 + 0x7f4) = *(undefined4 *)(puVar3 + 0xc);
  *(undefined4 *)(param_1 + 0x7fc) = *(undefined4 *)(puVar3 + 0x10);
  *(undefined4 *)(param_1 + 0x800) = *(undefined4 *)(puVar3 + 0x14);
  iVar6 = gpuConstructUserRegisterAccessMap_IMPL(param_1);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,"gpuConstructUserRegisterAccessMap(pGpu)","src/kernel/gpu/gpu.c",0x884);
    return iVar6;
  }
  iVar6 = gpuBuildGenericKernelFalconList_IMPL(param_1);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,"gpuBuildGenericKernelFalconList(pGpu)","src/kernel/gpu/gpu.c",0x885);
    return iVar6;
  }
  iVar6 = gpuBuildKernelVideoEngineList_IMPL(param_1);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog(iVar6,"gpuBuildKernelVideoEngineList(pGpu)","src/kernel/gpu/gpu.c",0x887);
    return iVar6;
  }
  if (*(char *)(param_1 + 0x467) != '\0') {
    cVar4 = (**(code **)(param_1 + 0x370))(param_1);
    *(char *)(param_1 + 0x467) = cVar4;
    if (cVar4 == '\0') {
      *(undefined1 *)(param_1 + 0x46b) = 0;
    }
    iVar6 = kvgpumgrMigTimeslicingModeEnabled(param_1);
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,"kvgpumgrMigTimeslicingModeEnabled(pGpu)","src/kernel/gpu/gpu.c",0x892);
      return iVar6;
    }
  }
  if (*(uint *)(param_1 + 0x8c8) == 0) {
    iVar6 = 0;
  }
  else {
    puVar14 = *(uint **)(param_1 + 0x8a8);
    puVar2 = puVar14 + *(uint *)(param_1 + 0x8c8);
    iVar6 = 0;
    do {
      uVar15 = (ulong)*puVar14;
      uVar16 = *puVar14 >> 8;
      if (uVar16 != 0xb33b15) {
        if (uVar16 == 0xf3e155) {
          plVar10 = (long *)gpuGetEngstate_IMPL_part_0(param_1);
        }
        else {
          plVar10 = (long *)gpuGetEngstateNoShare_IMPL(param_1,uVar15);
        }
        if (plVar10 != (long *)0x0) {
          if (((char)plVar10[9] == '\0') &&
             (cVar4 = (**(code **)(*plVar10 + 0x98))(param_1), cVar4 != '\0')) goto LAB_00349339;
          gpuDestroyMissingEngine(param_1,plVar10);
        }
        uVar9 = uVar15 & 0xff;
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x6fc,"gpuRemoveMissingEngines",1,
                     "NVRM: engine 0x%06x:%d is missing, removing\n",uVar16);
        iVar6 = gpuDeleteEngineOnPreInit_IMPL(param_1,uVar15);
        if (iVar6 != 0) {
          iVar6 = 0x40;
          nvAssertFailedNoLog("rmStatus == NV_OK || !\"Error while trying to remove missing engine\""
                              ,"src/kernel/gpu/gpu.c",0x701,uVar9);
        }
      }
LAB_00349339:
      puVar14 = puVar14 + 1;
    } while (puVar2 != puVar14);
  }
  if (*(int *)(param_1 + 0x8a0) != 0) {
    lVar8 = 0;
    do {
      while( true ) {
        lVar13 = *(long *)(param_1 + 0x898) + lVar8 * 8;
        uVar16 = *(uint *)(lVar13 + 4) >> 8;
        if ((*(uint *)(lVar13 + 4) != 0x7ef3cb00) && (uVar16 != 0xb33b15)) break;
LAB_003493c0:
        lVar8 = lVar8 + 1;
        if (*(uint *)(param_1 + 0x8a0) <= (uint)lVar8) goto LAB_003494b0;
      }
      if (uVar16 == 0xf3e155) {
        lVar11 = gpuGetEngstate_IMPL_part_0(param_1);
      }
      else {
        lVar11 = gpuGetEngstateNoShare_IMPL();
      }
      if (lVar11 != 0) goto LAB_003493c0;
      if ((((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) &&
          (*(char *)(param_1 + 0x908) == '\0')) ||
         (cVar4 = gpuCheckEngineWithOrderList_KERNEL(param_1,*(undefined4 *)(lVar13 + 4),0),
         cVar4 == '\0')) {
        iVar7 = gpuDeleteClassFromClassDBByEngTag_IMPL(param_1,*(undefined4 *)(lVar13 + 4));
        if (iVar7 == 0) goto LAB_003493c0;
        nvAssertOkFailedNoLog
                  (iVar7,"gpuDeleteClassFromClassDBByEngTag(pGpu, pCurDesc->engDesc)",
                   "src/kernel/gpu/gpu.c",0x72b);
        goto LAB_00349457;
      }
      lVar8 = lVar8 + 1;
    } while ((uint)lVar8 < *(uint *)(param_1 + 0x8a0));
  }
LAB_003494b0:
  iVar7 = gpuUpdateEngineTable_IMPL(param_1);
  if (iVar7 == 0) {
    iVar7 = 0;
    if (iVar6 == 0) goto LAB_003494c9;
  }
  else {
    nvAssertOkFailedNoLog(0x40,"gpuUpdateEngineTable(pGpu)","src/kernel/gpu/gpu.c",0x730);
  }
  iVar7 = 0x40;
LAB_00349457:
  nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/gpu.c",0x896);
LAB_003494c9:
  *(undefined1 *)(param_1 + 0x4919) = 1;
  if (*(uint *)(param_1 + 0x8c8) != 0) {
    puVar14 = *(uint **)(param_1 + 0x8a8);
    puVar2 = puVar14 + *(uint *)(param_1 + 0x8c8);
    do {
      while( true ) {
        uVar16 = *puVar14;
        if (uVar16 >> 8 == 0xf3e155) {
          lVar8 = gpuGetEngstate_IMPL_part_0(param_1);
        }
        else {
          lVar8 = gpuGetEngstateNoShare_IMPL(param_1,uVar16);
        }
        if (lVar8 != 0) break;
LAB_003494f9:
        puVar14 = puVar14 + 1;
        if (puVar14 == puVar2) goto LAB_00349630;
      }
      engstateLogStateTransitionPre_IMPL(lVar8,2,local_50);
      iVar7 = engstateStatePreInit_IMPL(param_1,lVar8);
      engstateLogStateTransitionPost_IMPL(lVar8,2,local_50);
      if (iVar7 != 0x56) {
        if (iVar7 == 0) goto LAB_003494f9;
        break;
      }
      if (uVar16 == 0x55952e00) {
        iVar6 = gpuGetClassList_IMPL(param_1,&local_54,0,0x55952e00);
        if (iVar6 == 0) {
          lVar13 = portMemAllocNonPaged((ulong)local_54 << 2);
          if (((lVar13 != 0) &&
              (iVar6 = gpuGetClassList_IMPL(param_1,&local_54,lVar13,0x55952e00), iVar6 == 0)) &&
             (local_54 != 0)) {
            lVar11 = 0;
            do {
              lVar1 = lVar11 * 4;
              lVar11 = lVar11 + 1;
              gpuDeleteClassFromClassDBByClassId_IMPL(param_1,*(undefined4 *)(lVar13 + lVar1));
            } while ((uint)lVar11 < local_54);
          }
          portMemFree(lVar13);
        }
      }
      else if (uVar16 == 0xa576e200) {
        uVar12 = engstateGetName_IMPL(lVar8);
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x8ca,"gpuStatePreInit_IMPL",3,
                     "NVRM: engine removal in PreInit with NV_ERR_NOT_SUPPORTED is deprecated (%s)\n"
                     ,uVar12);
      }
      else if (uVar16 == 0xe163900) {
        uVar12 = engstateGetName_IMPL(lVar8);
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x8c5,"gpuStatePreInit_IMPL",3,
                     "NVRM: engine removal in PreInit with NV_ERR_NOT_SUPPORTED is deprecated (%s)\n"
                     ,uVar12);
      }
      else {
        uVar12 = engstateGetName_IMPL(lVar8);
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x8cf,"gpuStatePreInit_IMPL",4,
                     "NVRM: disallowing NV_ERR_NOT_SUPPORTED PreInit removal of untracked engine (%s)\n"
                     ,uVar12);
        nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x8d3);
      }
      gpuDestroyMissingEngine(param_1,lVar8);
      iVar7 = gpuDeleteEngineOnPreInit_IMPL(param_1,uVar16);
      if (iVar7 == 0) goto LAB_003494f9;
      iVar7 = 0x40;
      puVar14 = puVar14 + 1;
      nvAssertFailedNoLog("rmStatus == NV_OK || !\"Error while trying to remove missing engine\"",
                          "src/kernel/gpu/gpu.c",0x8dc);
    } while (puVar14 != puVar2);
  }
LAB_00349630:
  if ((*(long *)(param_1 + 0x1b80) != 0) || (cVar4 = osIsGridSupported(param_1), cVar4 == '\0')) {
    gpuDeleteClassFromClassDBByClassId_IMPL(param_1,0xa083);
  }
  if (*(char *)(param_1 + 0x908) != '\0') {
    gpuDeleteClassFromClassDBByClassId_IMPL(param_1,0xde);
  }
  (**(code **)(param_1 + 0x378))(param_1);
  return iVar7;
}


// ===== 00349b50 gpuCheckEngine_KERNEL =====

void gpuCheckEngine_KERNEL(undefined8 param_1,undefined8 param_2)

{
  gpuCheckEngineWithOrderList_KERNEL(param_1,param_2,1);
  return;
}


// ===== 00349b60 _gpuGetSchedulerPolicyGr =====

undefined4 _gpuGetSchedulerPolicyGr(long param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint local_1c [3];
  
  local_1c[0] = 0;
  cVar1 = hypervisorIsVgxHyper_IMPL();
  if (cVar1 == '\0') {
    return 0;
  }
  if (((((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
       (cVar1 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar1 == '\0')) ||
      ((cVar1 = hypervisorIsVgxHyper_IMPL(), cVar1 == '\0' &&
       ((*(char *)(param_1 + 0x4a4e) == '\0' || (*(char *)(param_1 + 0x908) != '\0')))))) ||
     (cVar1 = rmcfg_IsGB20XorBetter(param_1), cVar1 != '\0')) {
    iVar2 = osReadRegistryDword(param_1,"RmPVMRL",local_1c);
    if (iVar2 != 0) {
      return 1;
    }
    if ((local_1c[0] & 1) == 0) {
      return 1;
    }
    uVar3 = local_1c[0] >> 4 & 0xf;
    if (uVar3 == 0) {
      return 2;
    }
    if (uVar3 != 1) {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x1a99,"_gpuGetSchedulerPolicyGr",1,
                   "NVRM: Invalid scheduling policy %u specified by PVMRL regkey 0x%08x for GR\n",
                   uVar3,local_1c[0]);
      return 0;
    }
  }
  return 3;
}


// ===== 00349c90 _gpuGetSchedulerPolicyNvenc =====

char _gpuGetSchedulerPolicyNvenc(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  uint local_1c [3];
  
  local_1c[0] = 0;
  cVar1 = hypervisorIsVgxHyper_IMPL();
  if ((cVar1 != '\0') && (iVar2 = osReadRegistryDword(param_1,"RmNvencPVMRL",local_1c), iVar2 == 0))
  {
    if ((local_1c[0] & 1) == 0) {
      return '\0';
    }
    return ((local_1c[0] & 0x10) != 0) + '\x02';
  }
  return '\0';
}


// ===== 00349cf0 gpuGetSchedulerPolicy_IMPL =====

undefined8 gpuGetSchedulerPolicy_IMPL(undefined8 param_1,int param_2)

{
  undefined8 uVar1;
  
  if (param_2 - 1U < 8) {
    uVar1 = _gpuGetSchedulerPolicyGr();
    return uVar1;
  }
  if (3 < param_2 - 0x25U) {
    return 0;
  }
  uVar1 = _gpuGetSchedulerPolicyNvenc();
  return uVar1;
}


// ===== 00349d20 gpuApplySchedulerPolicy_IMPL =====

void gpuApplySchedulerPolicy_IMPL(long param_1)

{
  ulong uVar1;
  char cVar2;
  int iVar3;
  undefined1 uVar4;
  undefined *puVar5;
  char *pcVar6;
  
  uVar1 = *(ulong *)(param_1 + 0x878);
  uVar4 = (undefined1)(uVar1 >> 8);
  iVar3 = _gpuGetSchedulerPolicyGr();
  if (iVar3 - 1U < 3) {
    puVar5 = *(undefined **)(CSWTCH_436 + (ulong)(iVar3 - 1U) * 8);
    pcVar6 = "ENABLED";
  }
  else {
    puVar5 = &DAT_00d25ee1;
    pcVar6 = "DISABLED";
  }
  cVar2 = hypervisorIsVgxHyper_IMPL();
  if (cVar2 == '\0') {
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x1b0f,"gpuApplySchedulerPolicy_IMPL",1,
                 "NVRM: GPU at %04x:%02x:%02x.0 has software scheduler %s with policy %s on GR\n",
                 uVar1 >> 0x20,uVar4,uVar1 & 0xff,pcVar6,puVar5);
  }
  else {
    nv_printf(0xffffffff,
              "NVRM: GPU at %04x:%02x:%02x.0 has software scheduler %s with policy %s on GR\n",
              (int)(uVar1 >> 0x20),uVar4,uVar1 & 0xff,pcVar6,puVar5);
  }
  cVar2 = hypervisorIsVgxHyper_IMPL();
  if (cVar2 != '\0') {
    *(undefined1 *)(param_1 + 0x475) = 1;
  }
  return;
}


// ===== 00349e40 gpuPostConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int gpuPostConstruct_IMPL(long param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  ulong uVar15;
  ulong uVar16;
  int iVar17;
  ulong *puVar18;
  ulong *local_90;
  undefined4 local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  undefined8 local_78;
  undefined4 local_70;
  undefined1 local_6c;
  ulong local_68 [2];
  ulong local_58;
  uint uStack_54;
  long local_50;
  long local_48;
  long local_40;
  
  gpumgrAddDeviceInstanceToGpus(1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f));
  iVar6 = regAccessConstruct(param_1 + 0x3a18,param_1);
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x174,"gpuPostConstruct_IMPL",4,
                 "NVRM: Failed to construct IO Apertures for attached devices \n");
    return iVar6;
  }
  if (*(char *)(param_1 + 0x908) != '\0') {
    uVar8 = regRead032(param_1 + 0x3a18,0,0,4,0);
    *(bool *)(param_1 + 0x4913) = (uVar8 & 0x30000) == 0x20000;
  }
  uVar7 = (**(code **)(param_1 + 0x1f8))(param_1);
  *(undefined4 *)(param_1 + 0x1b44) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x3a64) = uVar7;
  gpuInitChipInfo_IMPL(param_1);
  uVar4 = (**(code **)(param_1 + 0xd0))();
  *(undefined1 *)(param_1 + 0x4b2) = uVar4;
  gpuInitRegistryOverrides_KERNEL(param_1);
  gpuInitInstLocOverrides_IMPL(param_1);
  lVar11 = g_pSys;
  uVar10 = sysGetOs_IMPL(g_pSys);
  if ((*(char *)(param_1 + 0x7a0) == '\0') && (*(char *)(param_1 + 0x45a) == '\0')) {
    lVar11 = *(long *)(lVar11 + 0x238);
    if ((lVar11 != 0) && (*(char *)(lVar11 + 0x49) == '\0')) {
      hypervisorDetection_IMPL(lVar11,uVar10);
    }
    gpumgrGetGpuAttachInfo(0,local_68);
    local_58 = (ulong)uStack_54 << 0x20;
    uVar8 = regRead032(param_1 + 0x3a18,0,0,4,0);
    cVar5 = '\0';
    if ((uVar8 & 0x30000) == 0x20000) {
      if (*(char *)(param_1 + 0x4913) == '\0') {
        nvAssertFailedNoLog("pGpu->bIsVirtualWithSriov","src/kernel/gpu/gpu.c",0x10f0);
      }
      *(undefined1 *)(param_1 + 0x4a20) = 1;
      cVar5 = '\x01';
    }
    *(char *)(*(long *)(g_pSys + 0x210) + 0x4b) = cVar5;
    if ((*(char *)(param_1 + 0x491d) == '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
      *(undefined1 *)(param_1 + 0x491e) = 0;
    }
    if ((((*(char *)(param_1 + 0x490e) == '\0') && (lVar11 != 0)) &&
        (*(char *)(lVar11 + 0x49) != '\0')) && (*(char *)(lVar11 + 0x4a) != '\0')) {
      uVar16 = *(ulong *)(param_1 + 0x878);
      uVar4 = (undefined1)(uVar16 >> 8);
      lVar11 = osPciInitHandle(uVar16 >> 0x20,uVar4,uVar16 & 0xff,0,0,0);
      *(bool *)(*(long *)(g_pSys + 0x210) + 0x4b) = lVar11 != 0;
      if (((lVar11 != 0) &&
          (*(long *)(param_1 + 0x4f8) = lVar11, *(char *)(param_1 + 0x4913) == '\0')) &&
         (*(char *)(param_1 + 0x908) == '\0')) {
        uVar8 = osPciReadDword(lVar11,0x14);
        if ((uVar8 & 6) == 4) {
          *(undefined1 *)(param_1 + 0x4909) = 1;
          nvDbg_Printf("src/kernel/gpu/gpu.c",0x1305,"gpuSetupVirtualGuestOwnedHW",1,
                       "NVRM: VT-d is using a 64bit BAR1.\n");
        }
        else {
          iVar6 = osPciReadDword(lVar11,0x18);
          if (iVar6 == 0) {
            nvDbg_Printf("src/kernel/gpu/gpu.c",0x12ff,"gpuSetupVirtualGuestOwnedHW",1,
                         "NVRM: VT-d still keeps BAR2 at 0x1C.\n");
          }
          else {
            *(undefined1 *)(param_1 + 0x4908) = 1;
            nvDbg_Printf("src/kernel/gpu/gpu.c",0x12fb,"gpuSetupVirtualGuestOwnedHW",1,
                         "NVRM: VT-d moved BAR2 to 0x18.\n");
          }
        }
        *(undefined1 *)(param_1 + 0x4912) = 1;
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x130a,"gpuSetupVirtualGuestOwnedHW",1,
                     "NVRM: GPU at domain: %d bus: %d, device: %d is virtual (HW passthrough mode).\n"
                     ,uVar16 >> 0x20,uVar4,uVar16 & 0xff);
      }
    }
    if (*(char *)(param_1 + 0x4912) != '\0') {
      while (lVar11 = gpumgrGetNextGpu(local_68[0] & 0xffffffff,&stack0xffffffffffffffa8),
            lVar11 != 0) {
        if (*(char *)(lVar11 + 0x908) != '\0') {
          nvDbg_Printf("src/kernel/gpu/gpu.c",0x110b,"gpuDetermineVirtualMode",4,
                       "NVRM: vGPU and Passthrough not supported simultaneously on the same VM.\n");
          *(undefined1 *)(param_1 + 0x4912) = 0;
          return 0x56;
        }
      }
    }
    if (cVar5 != *(char *)(param_1 + 0x908)) {
      nvAssertFailedNoLog("pGpu->isVirtual == bIsVirtual","src/kernel/gpu/gpu.c",0x1114);
      return 0x40;
    }
  }
  local_90 = local_68;
  uVar4 = (**(code **)(param_1 + 0x3c0))(param_1);
  *(undefined1 *)(param_1 + 0x490) = uVar4;
  if ((*(long *)(param_1 + 0x4f8) == 0) && (*(char *)(param_1 + 0x7a0) == '\0')) {
    uVar16 = *(ulong *)(param_1 + 0x878);
    uVar10 = osPciInitHandle(uVar16 >> 0x20,uVar16 >> 8 & 0xff,uVar16 & 0xff,0,0,0);
    *(undefined8 *)(param_1 + 0x4f8) = uVar10;
  }
  uVar7 = (**(code **)(param_1 + 0x1f8))(param_1);
  *(undefined4 *)(param_1 + 0x3a64) = uVar7;
  uVar10 = (**(code **)(param_1 + 0x230))(param_1,param_1 + 0x890);
  *(undefined8 *)(param_1 + 0x888) = uVar10;
  local_68[0] = 0x200000001;
  local_68[1] = 0x800000004;
  local_58 = param_1 + 0x8a8;
  local_50 = param_1 + 0x8b8;
  local_48 = param_1 + 0x8c0;
  local_40 = param_1 + 0x8b0;
  puVar18 = local_90;
  iVar6 = 0;
  do {
    local_70 = (undefined4)*puVar18;
    local_78 = 0;
    uVar16 = 0;
    local_6c = 0;
    while( true ) {
      cVar5 = gpuGetNextInEngineOrderList(param_1,&local_78,&local_88);
      iVar17 = (int)uVar16;
      if (cVar5 == '\0') break;
      uVar16 = (ulong)(iVar17 + 1);
    }
    if ((iVar6 != 0) && (iVar17 != iVar6)) {
      iVar6 = 0x40;
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x476,"_gpuCreateEngineOrderList",4,
                   "NVRM: Sizes of all engine order lists do not match!\n");
      nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x478);
      goto LAB_0034abe6;
    }
    puVar18 = (ulong *)((long)puVar18 + 4);
    iVar6 = iVar17;
  } while (&stack0xffffffffffffffa8 != puVar18);
  *(int *)(param_1 + 0x8c8) = iVar17;
  lVar11 = 0;
  do {
    plVar1 = (long *)(&stack0xffffffffffffffa8)[lVar11];
    lVar12 = portMemAllocNonPaged(uVar16 * 4);
    *plVar1 = lVar12;
    if (lVar12 == 0) {
      nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x48a);
      goto LAB_0034abe0;
    }
    local_78 = 0;
    uVar8 = 0;
    local_6c = 0;
    local_70 = *(undefined4 *)((long)local_90 + lVar11 * 4);
    while (cVar5 = gpuGetNextInEngineOrderList(param_1,&local_78,&local_88), cVar5 != '\0') {
      uVar15 = (ulong)uVar8;
      uVar8 = uVar8 + 1;
      *(undefined4 *)(*plVar1 + uVar15 * 4) = local_88;
    }
    lVar11 = lVar11 + 1;
  } while (lVar11 != 4);
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  uVar10 = (**(code **)(param_1 + 0x238))(param_1,&local_80);
  puVar13 = (undefined4 *)gpuGetGenericClassList_IMPL(param_1,&local_84);
  lVar11 = (**(code **)(param_1 + 0x240))(param_1,&local_7c);
  uVar8 = local_7c + local_84 + local_80;
  puVar14 = (undefined4 *)portMemAllocNonPaged((ulong)uVar8 << 3);
  *(undefined4 **)(param_1 + 0x898) = puVar14;
  if (puVar14 == (undefined4 *)0x0) {
LAB_0034abe0:
    iVar6 = 0x51;
LAB_0034abe6:
    portMemFree(*(undefined8 *)(param_1 + 0x8a8));
    *(undefined8 *)(param_1 + 0x8a8) = 0;
    portMemFree(*(undefined8 *)(param_1 + 0x8b0));
    *(undefined8 *)(param_1 + 0x8b0) = 0;
    portMemFree(*(undefined8 *)(param_1 + 0x8b8));
    *(undefined8 *)(param_1 + 0x8b8) = 0;
    portMemFree(*(undefined8 *)(param_1 + 0x8c0));
    *(undefined8 *)(param_1 + 0x8c0) = 0;
    return iVar6;
  }
  uVar16 = (ulong)local_84;
  if (local_84 != 0) {
    uVar7 = *puVar13;
    puVar14[1] = 0x7ef3cb00;
    *puVar14 = uVar7;
    if (local_84 < 2) {
      uVar16 = 1;
    }
    else {
      uVar15 = 1;
      do {
        uVar9 = (int)uVar15 + 1;
        uVar16 = (ulong)uVar9;
        puVar14 = (undefined4 *)(*(long *)(param_1 + 0x898) + uVar15 * 8);
        uVar7 = puVar13[uVar15];
        puVar14[1] = 0x7ef3cb00;
        *puVar14 = uVar7;
        uVar15 = uVar16;
      } while (uVar9 < local_84);
    }
  }
  if (local_7c != 0) {
    lVar12 = 0;
    uVar15 = uVar16;
    do {
      uVar16 = (ulong)((int)uVar15 + 1);
      puVar13 = (undefined4 *)(*(long *)(param_1 + 0x898) + uVar15 * 8);
      uVar7 = *(undefined4 *)(lVar11 + lVar12 * 4);
      lVar12 = lVar12 + 1;
      puVar13[1] = 0x7ef3cb00;
      *puVar13 = uVar7;
      uVar15 = uVar16;
    } while ((uint)lVar12 < local_7c);
  }
  if (local_80 != 0) {
    portMemCopy(*(long *)(param_1 + 0x898) + uVar16 * 8,(ulong)local_80 * 8,uVar10,
                (ulong)local_80 * 8);
  }
  *(uint *)(param_1 + 0x8a0) = uVar8;
  gpuBuildClassDB_IMPL(param_1);
  *(undefined8 *)(param_1 + 0x1b20) = 0;
  timeoutInitializeGpuDefault(param_1 + 0x1af0,param_1);
  *(undefined1 *)(param_1 + 0x490b) = 1;
  cVar5 = hypervisorIsVgxHyper_IMPL();
  if ((cVar5 != '\0') || (*(char *)(param_1 + 0x908) != '\0')) {
    vgpuInitRegistryOverWrite(param_1);
  }
  cVar5 = hypervisorIsVgxHyper_IMPL();
  if (cVar5 != '\0') {
    *(undefined1 *)(param_1 + 0x4a3) = 1;
  }
  gpuApplySchedulerPolicy_IMPL(param_1);
  iVar6 = gpuCreateObject(param_1,"bilities/gpu4/mig/gi9/ci7/access",0,param_1 + 7000);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x9ddede,0,param_1 + 0x1b88);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x87fb96,0,param_1 + 0x1d08);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x261ee8,0,param_1 + 0x1d10);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x9798cc,0,param_1 + 0x1d18);
  if (iVar6 != 0) {
    return iVar6;
  }
  (**(code **)(param_1 + 0x1d0))(param_1);
  lVar11 = rmapiGetInterface(5);
  uVar16 = 0;
  do {
    uVar8 = (int)uVar16 + 0x20;
    uVar15 = (ulong)uVar8;
    uVar10 = *(undefined8 *)(lVar11 + 8 + uVar16);
    uVar2 = *(undefined8 *)(lVar11 + 0x10 + uVar16);
    uVar3 = *(undefined8 *)(lVar11 + 0x18 + uVar16);
    *(undefined8 *)(param_1 + 0x3b58 + uVar16) = *(undefined8 *)(lVar11 + uVar16);
    *(undefined8 *)(param_1 + 0x3b60 + uVar16) = uVar10;
    *(undefined8 *)(param_1 + 0x3b68 + uVar16) = uVar2;
    *(undefined8 *)(param_1 + 0x3b70 + uVar16) = uVar3;
    uVar16 = uVar15;
  } while (uVar8 < 0xe0);
  *(undefined8 *)(param_1 + 0x3b58 + uVar15) = *(undefined8 *)(lVar11 + uVar15);
  *(long *)(param_1 + 0x3c38) = param_1;
  portMemSet(param_1 + 0x3c10,0,0x20);
  *(undefined1 *)(param_1 + 0x3c34) = 1;
  *(undefined8 *)(param_1 + 0x3c10) = 0x100000002;
  *(undefined4 *)(param_1 + 0x3c30) = 0x1010101;
  *(code **)(param_1 + 0x3b90) = _gpuRmApiControl;
  *(code **)(param_1 + 0x3b60) = _gpuRmApiAllocWithHandle;
  *(code **)(param_1 + 0x3b70) = _gpuRmApiFree;
  iVar6 = gpuConstructEngineTable_IMPL(param_1);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuUpdateEngineTable_IMPL(param_1);
  if (iVar6 != 0) {
    return 0x40;
  }
  iVar6 = gpuCreateObject(param_1,0x3827ff,0,param_1 + 0x1b60);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x5ca633,0,param_1 + 0x1b68);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x7faff1,0,param_1 + 0x1b70);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x22ad47,0,param_1 + 0x1b78);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,&DAT_0055952e,0,param_1 + 0x1b80);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,"ault Id         : %d\n",0,&DAT_00001b90 + param_1);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x29362f,0,param_1 + 0x1b98);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x2f36c9,0,param_1 + 0x1ba0);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x311d4e,0,param_1 + 0x1ba8);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x61649c,0,param_1 + 0x1bb0);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x899e48,0,param_1 + 0x1bb8);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x1c1bf,0,param_1 + 0x1bc0);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,
                          "el(pChannelClient, pChannelStateParams->hChannel, &pKernelChannel)",0,
                          param_1 + 0x1bc8);
  if (iVar6 != 0) {
    return iVar6;
  }
  lVar11 = param_1 + 0x1bd0;
  lVar12 = 0;
  do {
    iVar6 = gpuCreateObject(param_1,&DAT_00ea3fa9,lVar12,lVar11);
    if (iVar6 != 0) {
      return iVar6;
    }
    lVar12 = lVar12 + 1;
    lVar11 = lVar11 + 8;
  } while (lVar12 != 8);
  iVar6 = gpuCreateObject(param_1,0xc53a57,0,param_1 + 0x1c10);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x4888db,0,param_1 + 0x1c18);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0xc06e44,0,param_1 + 0x1c20);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0xab9d7d,0,param_1 + 0x1c28);
  if (iVar6 != 0) {
    return iVar6;
  }
  lVar11 = param_1 + 0x1c30;
  lVar12 = 0;
  do {
    iVar6 = gpuCreateObject(param_1,0x242aca,lVar12,lVar11);
    if (iVar6 != 0) {
      return iVar6;
    }
    lVar12 = lVar12 + 1;
    lVar11 = lVar11 + 8;
  } while (lVar12 != 0x14);
  iVar6 = gpuCreateObject(param_1,&DAT_00f3e155,0,param_1 + 0x1cd0);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0xf9a17d,0,param_1 + 0x1cd8);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x7e80a2,0,param_1 + 0x1ce0);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0xce6818,0,param_1 + 0x1ce8);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0xc8c00f,0,param_1 + 0x1cf0);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x20fd5a,0,param_1 + 0x1cf8);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x95a6f5,0,param_1 + 0x1d00);
  if (iVar6 != 0) {
    return iVar6;
  }
  iVar6 = gpuCreateObject(param_1,0x5d5b68,0,param_1 + 0x1d20);
  if (iVar6 != 0) {
    return iVar6;
  }
  lVar11 = param_1 + 0x1d28;
  lVar12 = 0;
  do {
    iVar6 = gpuCreateObject(param_1,0x927969,lVar12,lVar11);
    if (iVar6 != 0) {
      return iVar6;
    }
    lVar12 = lVar12 + 1;
    lVar11 = lVar11 + 8;
  } while (lVar12 != 4);
  iVar6 = gpuCreateObject(param_1,0xa9fc13,0,param_1 + 0x1d48);
  if (iVar6 != 0) {
    return iVar6;
  }
  (**(code **)(param_1 + 0x300))(param_1);
  if (*(char *)(param_1 + 0x490e) == '\0') {
LAB_0034ab17:
    if (*(char *)(param_1 + 0x908) == '\0') goto LAB_0034ab24;
  }
  else if (*(char *)(param_1 + 0x908) == '\0') {
    (**(code **)(param_1 + 0x360))(param_1);
    goto LAB_0034ab17;
  }
  if ((*(char *)(param_1 + 0x4a4e) != '\0') && (*(char *)(param_1 + 0x4913) != '\0')) {
    lVar11 = *(long *)(&DAT_00001b90 + param_1);
    if (*(int *)(param_2 + 0x50) == 0) {
      *(undefined1 *)(lVar11 + 0xad08) = 0;
    }
    else if ((*(char *)(lVar11 + 0xad08) != '\0') &&
            (iVar6 = (**(code **)(lVar11 + 0x470))(param_1), iVar6 != 0)) {
      nvAssertOkFailedNoLog
                (iVar6,"kbusBar2BootStrapInPhysicalMode_HAL(pGpu, pKernelBus)",
                 "src/kernel/gpu/gpu.c",0x229);
      return iVar6;
    }
  }
  iVar6 = vgpuCreateObject(param_1);
  if (iVar6 != 0) {
    if (iVar6 == 0x6a) {
      nvErrorLog_va(param_1,0x4e,"Guest driver is incompatible with host driver");
      return 0x6a;
    }
    return iVar6;
  }
LAB_0034ab24:
  if (*(long *)(g_pSys + 0x208) != 0) {
    clInitPropertiesFromRegistry_IMPL(param_1);
  }
  gpuDumpCallbackRegister_IMPL(param_1);
  *(undefined4 *)(param_1 + 0x3b24) = 0;
  *(undefined4 *)(param_1 + 0x4d0) = 0xff;
  (**(code **)(param_1 + 0x140))(param_1,1);
  if (*(long *)(param_1 + 0x1d18) != 0) {
    iVar6 = (**(code **)(*(long *)(param_1 + 0x1d18) + 0x250))(param_1);
    if (iVar6 != 0) {
      nvCheckFailedNoLog(4,"confComputeTestPlatformSupport_HAL(pGpu, pCC) == NV_OK",
                         "src/kernel/gpu/gpu.c",0x263);
      return 0x40;
    }
    return 0;
  }
  return 0;
}


// ===== 0034ae70 gpuMarkDeviceForReset_IMPL =====

void gpuMarkDeviceForReset_IMPL(undefined8 param_1)

{
  _gpuSetResetRequiredState(param_1,1);
  return;
}


// ===== 0034ae80 gpuUnmarkDeviceForReset_IMPL =====

void gpuUnmarkDeviceForReset_IMPL(undefined8 param_1)

{
  _gpuSetResetRequiredState(param_1,0);
  return;
}


// ===== 0034ae90 gpuIsDeviceMarkedForReset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuIsDeviceMarkedForReset_IMPL(long param_1)

{
  (**(code **)(param_1 + 0xf0))();
  return;
}


// ===== 0034aea0 gpuMarkDeviceForDrainAndReset_IMPL =====

void gpuMarkDeviceForDrainAndReset_IMPL(undefined8 param_1)

{
  _gpuSetDrainAndResetState(param_1,1);
  return;
}


// ===== 0034aeb0 gpuUnmarkDeviceForDrainAndReset_IMPL =====

void gpuUnmarkDeviceForDrainAndReset_IMPL(undefined8 param_1)

{
  _gpuSetDrainAndResetState(param_1,0);
  return;
}


// ===== 0034aec0 gpuIsDeviceMarkedForDrainAndReset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuIsDeviceMarkedForDrainAndReset_IMPL(long param_1)

{
  (**(code **)(param_1 + 0x120))();
  return;
}


// ===== 0034aed0 gpuGetRecoveryAction_IMPL =====

undefined1  [16] gpuGetRecoveryAction_IMPL(long param_1,undefined4 *param_2)

{
  undefined1 auVar1 [16];
  char *pcVar2;
  uint uVar3;
  undefined8 uStack_20;
  
  uVar3 = *(uint *)(param_1 + 0x4d0);
  if (uVar3 < 6) {
    pcVar2 = *(char **)(CSWTCH_446 + (ulong)uVar3 * 8);
  }
  else {
    uStack_20 = 0x34af58;
    nvAssertFailedNoLog("Unknown recovery action!","src/kernel/gpu/gpu.c",0x1be4);
    uVar3 = *(uint *)(param_1 + 0x4d0);
    pcVar2 = "Unknown";
  }
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x1bf8,"gpuGetRecoveryAction_IMPL",1,
               "NVRM: GetRecoveryAction: 0x%x (%s)\n",uVar3);
  *param_2 = *(undefined4 *)(param_1 + 0x4d0);
  auVar1._8_8_ = uStack_20;
  auVar1._0_8_ = pcVar2;
  return auVar1;
}


// ===== 0034af70 gpuRefreshRecoveryAction_KERNEL =====

void gpuRefreshRecoveryAction_KERNEL(long param_1,char param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_9;
  
  local_9 = *(undefined1 *)(param_1 + 0x4b9);
  if (param_2 != '\0') {
    _gpuRefreshRecoveryActionInLock(*(undefined4 *)(param_1 + 0x7a4),&local_9);
    return;
  }
  puVar2 = (undefined1 *)portMemAllocNonPaged(1);
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = local_9;
    iVar1 = osQueueWorkItem(param_1,_gpuRefreshRecoveryActionInLock,puVar2,0x40);
    if (iVar1 == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c8a,"gpuRefreshRecoveryAction_KERNEL",4,
                 "NVRM: Failed to queue recovery action work item: 0x%x\n",iVar1);
    portMemFree(puVar2);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c7e,"gpuRefreshRecoveryAction_KERNEL",4,
               "NVRM: Failed to allocate memory for recovery action params\n");
  return;
}


// ===== 0034b047 gpuStateLoad_IMPL.cold =====

void gpuStateLoad_IMPL_cold(void)

{
  code *pcVar1;
  
  nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0034b070 gpuStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

int gpuStateLoad_IMPL(long param_1,uint param_2)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  long *plVar8;
  uint *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  long lVar12;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  char *pcVar13;
  byte bVar14;
  ulong uVar15;
  uint *puVar16;
  undefined8 uVar17;
  int local_fc;
  long local_f0;
  undefined4 local_e0;
  undefined1 local_dc [4];
  int local_d8;
  int local_d4;
  undefined8 local_d0;
  ulong local_c8;
  uint local_c0 [2];
  undefined8 auStack_b8 [3];
  undefined4 auStack_a0 [28];
  
  local_d0 = 0;
  iVar4 = osGetPerformanceCounter(&local_d0);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"osGetPerformanceCounter(&startTimens)","src/kernel/gpu/gpu.c",0x9bf);
  }
  *(undefined8 *)(param_1 + 0x3a30) = 0;
  _gpuDetectNvswitchSupport(param_1);
  if ((((*(char *)(param_1 + 0x4913) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) &&
      ((param_2 & 1) != 0)) && (iVar4 = vgpuReinitializeRpcInfraOnStateLoad(param_1), iVar4 != 0)) {
    pcVar13 = "NVRM: Failed to re-init RPC infrastructure on resume, status 0x%x\n";
    uVar17 = 0x9d4;
LAB_0034b6d1:
    nvDbg_Printf("src/kernel/gpu/gpu.c",uVar17,"gpuStateLoad_IMPL",4,pcVar13,iVar4);
    if (*(int *)(param_1 + 0x4b08) != 0) {
      return iVar4;
    }
    *(int *)(param_1 + 0x4b0c) = iVar4;
    *(undefined4 *)(param_1 + 0x4b08) = 0x13;
    return iVar4;
  }
  iVar4 = (**(code **)(param_1 + 0x248))(param_1);
  if (iVar4 != 0) {
    pcVar13 = "NVRM: Error initializing SRIOV: 0x%0x\n";
    uVar17 = 0x9e2;
    goto LAB_0034b6d1;
  }
  if ((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) {
    if ((param_2 & 1) == 0) goto LAB_0034b1bc;
  }
  else if ((param_2 & 1) == 0) {
LAB_0034b1bc:
    iVar4 = (**(code **)(param_1 + 0x2a8))(param_1);
    if (iVar4 != 0) {
      if (*(int *)(param_1 + 0x4b08) != 0) {
        return iVar4;
      }
      *(undefined4 *)(param_1 + 0x4b08) = 0x13;
      *(int *)(param_1 + 0x4b0c) = iVar4;
      return iVar4;
    }
  }
  else {
    lVar7 = gpuGetRpc(param_1);
    if ((lVar7 != 0) &&
       (iVar4 = (**(code **)(lVar7 + 0x3b8))(param_1,lVar7,*(code **)(lVar7 + 0x3b8)), iVar4 != 0))
    {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x9ee,"gpuStateLoad_IMPL",4,
                   "NVRM: RPC to restore host hibernation data failed, status 0x%x\n",iVar4);
      if (*(int *)(param_1 + 0x4b08) != 0) {
        return iVar4;
      }
      *(undefined4 *)(param_1 + 0x4b08) = 0x13;
      *(int *)(param_1 + 0x4b0c) = iVar4;
      return iVar4;
    }
  }
  lVar7 = *(long *)(param_1 + 0x8b8);
  local_c8 = 0;
  uVar5 = *(uint *)(param_1 + 0x8c8);
  iVar4 = osGetPerformanceCounter(&local_c8);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"osGetPerformanceCounter(&startTimens)","src/kernel/gpu/gpu.c",0x971);
  }
  if (uVar5 != 0) {
    uVar15 = 0;
    do {
      if (*(uint *)(lVar7 + uVar15 * 4) >> 8 == 0xf3e155) {
        plVar8 = (long *)gpuGetEngstate_IMPL_part_0();
      }
      else {
        plVar8 = (long *)gpuGetEngstateNoShare_IMPL(param_1);
      }
      if (plVar8 != (long *)0x0) {
        engstateLogStateTransitionPre_IMPL(plVar8,4,local_c0);
        local_fc = (**(code **)(*plVar8 + 0x60))(param_1,plVar8,param_2);
        engstateLogStateTransitionPost_IMPL(plVar8,4,local_c0);
        if ((local_fc == 0x56) || (local_fc == 0)) {
          rmGpuLocksRelease(0,0);
          local_fc = rmGpuLocksAcquire(0,0x400001);
          if (local_fc == 0) goto LAB_0034b2bd;
          iVar4 = *(int *)(param_1 + 0x4b08);
        }
        else {
          if (*(int *)(param_1 + 0x4b08) != 0) {
            return local_fc;
          }
          *(undefined4 *)(param_1 + 0x4b08) = 0x10;
          *(int *)(param_1 + 0x4b0c) = local_fc;
          _gpuEngineTransitionFailureStore_isra_0
                    (param_1,param_1 + 0x4b10,4,*(undefined4 *)((long)plVar8 + 0x4c),local_c8,lVar7,
                     uVar15);
          iVar4 = *(int *)(param_1 + 0x4b08);
        }
        if (iVar4 != 0) {
          return local_fc;
        }
        *(undefined4 *)(param_1 + 0x4b08) = 0x11;
        goto LAB_0034b738;
      }
LAB_0034b2bd:
      uVar15 = uVar15 + 1;
    } while (uVar5 != uVar15);
  }
  if ((param_2 & 1) == 0) {
    local_f0 = *(long *)(param_1 + 0x8b8);
    uVar5 = *(uint *)(param_1 + 0x8c8);
    bVar14 = 1;
    *(undefined1 *)(param_1 + 0x4916) = 1;
    if (uVar5 != 0) goto LAB_0034b38a;
LAB_0034b490:
    iVar4 = gpuInitVideoLogging_IMPL(param_1);
    if (iVar4 != 0) {
      nvCheckFailedNoLog(4,"gpuInitVideoLogging(pGpu) == NV_OK","src/kernel/gpu/gpu.c",0xa75);
    }
  }
  else {
    if (*(char *)(param_1 + 0x4a4e) != '\0') {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0xa15,"gpuStateLoad_IMPL",1,
                   "NVRM: RPC: Allocate vGPU GSP buffers to FB_MEM\n");
      vgpuGspTeardownBuffers(param_1);
      iVar4 = vgpuGspSetupBuffers(param_1);
      if (iVar4 != 0) {
        nvDbg_Printf("src/kernel/gpu/gpu.c",0xa1a,"gpuStateLoad_IMPL",4,
                     "NVRM: RPC buffers setup failed: 0x%x\n",iVar4);
        iVar6 = *(int *)(param_1 + 0x4b08);
        goto joined_r0x0034bed5;
      }
    }
    local_f0 = *(long *)(param_1 + 0x8b8);
    uVar5 = *(uint *)(param_1 + 0x8c8);
    *(undefined1 *)(param_1 + 0x4916) = 1;
    if (uVar5 != 0) {
LAB_0034b38a:
      lVar7 = 0;
      do {
        if (*(uint *)(local_f0 + lVar7 * 4) >> 8 == 0xf3e155) {
          plVar8 = (long *)gpuGetEngstate_IMPL_part_0();
        }
        else {
          plVar8 = (long *)gpuGetEngstateNoShare_IMPL(param_1);
        }
        if (plVar8 != (long *)0x0) {
          engstateLogStateTransitionPre_IMPL(plVar8,5,local_c0);
          local_fc = (**(code **)(*plVar8 + 0x68))(param_1,plVar8,param_2);
          engstateLogStateTransitionPost_IMPL(plVar8,5,local_c0);
          if (local_fc == 0x1e) {
            uVar17 = engstateGetName_IMPL(plVar8);
            nvDbg_Printf("src/kernel/gpu/gpu.c",0xa42,"gpuStateLoad_IMPL",4,
                         "NVRM: NV_ERR_INVALID_ADDRESS is no longer supported in StateLoad (%s)\n",
                         uVar17);
          }
          else if ((local_fc == 0x56) || (local_fc == 0)) {
            rmGpuLocksRelease(0,0);
            local_fc = rmGpuLocksAcquire(0,0x400001);
            if (local_fc == 0) goto LAB_0034b426;
            iVar4 = *(int *)(param_1 + 0x4b08);
            goto LAB_0034b7dd;
          }
          if (*(int *)(param_1 + 0x4b08) != 0) {
            return local_fc;
          }
          *(undefined4 *)(param_1 + 0x4b08) = 0x12;
          *(int *)(param_1 + 0x4b0c) = local_fc;
          _gpuEngineTransitionFailureStore_isra_0
                    (param_1,param_1 + 0x4b10,5,*(undefined4 *)((long)plVar8 + 0x4c),local_d0,
                     local_f0,lVar7);
          iVar4 = *(int *)(param_1 + 0x4b08);
          goto LAB_0034b7dd;
        }
LAB_0034b426:
        lVar7 = lVar7 + 1;
      } while ((uint)lVar7 < uVar5);
    }
    bVar14 = (byte)param_2 & 1 ^ 1;
    if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0' || bVar14 != 0) goto LAB_0034b490;
    bVar14 = 0;
  }
  *(undefined8 *)(param_1 + 0x3b10) = 0;
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x90a) == '\0') {
      if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
        local_fc = _gpuRmApiControl();
      }
      else {
        local_fc = (**(code **)(param_1 + 0x3b90))
                             (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                              *(undefined4 *)(param_1 + 0x3b3c),0x2080017e,local_c0,8);
      }
      if (local_fc != 0x56) {
        if (local_fc != 0) {
          nvDbg_Printf("src/kernel/gpu/gpu.c",0xa7b,"gpuStateLoad_IMPL",4,
                       "NVRM: Error initializing VMMU info: 0x%0x\n",0);
          iVar4 = *(int *)(param_1 + 0x4b08);
LAB_0034b7dd:
          if (iVar4 != 0) {
            return local_fc;
          }
          *(undefined4 *)(param_1 + 0x4b08) = 0x13;
          goto LAB_0034b738;
        }
        *(ulong *)(param_1 + 0x3b10) = CONCAT44(local_c0[1],local_c0[0]);
      }
    }
    else if (*(char *)(param_1 + 0x4913) != '\0') goto LAB_0034b05f;
  }
  else if (*(char *)(param_1 + 0x4913) != '\0') {
    if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) == 0) {
      nvAssertFailedNoLog("GPU_GET_VGPU(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17ec);
LAB_0034b05f:
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    *(undefined8 *)(param_1 + 0x3b10) =
         *(undefined8 *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0xa988);
  }
  local_c8 = 0;
  iVar4 = osGetPerformanceCounter(&local_c8);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"osGetPerformanceCounter(&startTimens)","src/kernel/gpu/gpu.c",0xda4);
  }
  uVar5 = *(uint *)(param_1 + 0x8c8);
  if (uVar5 != 0) {
    lVar7 = *(long *)(param_1 + 0x8b8);
    uVar15 = 0;
    do {
      if (*(uint *)(lVar7 + uVar15 * 4) >> 8 == 0xf3e155) {
        plVar8 = (long *)gpuGetEngstate_IMPL_part_0();
      }
      else {
        plVar8 = (long *)gpuGetEngstateNoShare_IMPL(param_1);
      }
      if (plVar8 != (long *)0x0) {
        engstateLogStateTransitionPre_IMPL(plVar8,6,local_c0);
        local_fc = (**(code **)(*plVar8 + 0x70))(param_1,plVar8,param_2);
        engstateLogStateTransitionPost_IMPL(plVar8,6,local_c0);
        if ((local_fc != 0x56) && (local_fc != 0)) {
          if (*(int *)(param_1 + 0x4b08) != 0) {
            return local_fc;
          }
          *(undefined4 *)(param_1 + 0x4b08) = 0x15;
          *(int *)(param_1 + 0x4b0c) = local_fc;
          _gpuEngineTransitionFailureStore_isra_0
                    (param_1,param_1 + 0x4b10,6,*(undefined4 *)((long)plVar8 + 0x4c),local_c8,lVar7,
                     uVar15);
          iVar4 = *(int *)(param_1 + 0x4b08);
          goto LAB_0034bd58;
        }
        rmGpuLocksRelease(0,0);
        local_fc = rmGpuLocksAcquire(0,0x400001);
        if (local_fc != 0) {
          iVar4 = *(int *)(param_1 + 0x4b08);
          goto LAB_0034bd58;
        }
      }
      uVar15 = uVar15 + 1;
    } while (uVar5 != uVar15);
  }
  cVar2 = hypervisorIsVgxHyper_IMPL();
  if (cVar2 == '\0') {
LAB_0034b974:
    if ((*(char *)(param_1 + 0x4a4e) == '\0') || (*(char *)(param_1 + 0x909) == '\0')) {
LAB_0034baad:
      if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
        lVar7 = portMemAllocNonPaged(0x88);
        *(long *)(param_1 + 0x3c60) = lVar7;
        if (lVar7 != 0) {
          portMemSet(lVar7,0,0x88);
          if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
            iVar4 = _gpuRmApiControl();
          }
          else {
            iVar4 = (**(code **)(param_1 + 0x3b90))
                              (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                               *(undefined4 *)(param_1 + 0x3b3c),0x2080013f,
                               *(undefined8 *)(param_1 + 0x3c60),0x88);
          }
          if (iVar4 != 0) {
            portMemFree(*(undefined8 *)(param_1 + 0x3c60));
            *(undefined8 *)(param_1 + 0x3c60) = 0;
          }
        }
      }
      cVar2 = hypervisorIsVgxHyper_IMPL();
      if ((cVar2 == '\0') && (iVar4 = gpuFabricProbeStart(param_1,param_1 + 0x4c0), iVar4 != 0)) {
        nvAssertFailedNoLog("gpuFabricProbeStart(pGpu, &pGpu->pGpuFabricProbeInfoKernel) == NV_OK",
                            "src/kernel/gpu/gpu.c",0xe0c);
      }
      else {
        cVar2 = (**(code **)(param_1 + 0x358))(param_1);
        if (cVar2 != '\0') {
          if (*(char *)(param_1 + 0x4b8) == '\0') {
            *(undefined1 *)(param_1 + 0x4b8) = 1;
            gpuRefreshRecoveryAction_KERNEL(param_1,0);
          }
          *(undefined1 *)(param_1 + 0x4a7c) = 0;
        }
      }
      if ((*(char *)(param_1 + 0x444) != '\0') && (*(char *)(param_1 + 0x4a51) != '\0')) {
        local_c0[0] = 0;
        iVar4 = 1;
        gpumgrGetGpuAttachInfo(&local_d4,&local_c8);
        while (lVar7 = gpumgrGetNextGpu(local_c8 & 0xffffffff,local_c0), lVar7 != 0) {
          if (*(char *)(lVar7 + 0x441) == '\0') {
            iVar4 = iVar4 + (uint)(*(char *)(lVar7 + 0x442) == '\0');
          }
        }
        if (local_d4 == iVar4) {
          RmInitScalability(param_1);
        }
      }
      cVar2 = hypervisorIsVgxHyper_IMPL();
      uVar15 = extraout_RDX;
      if (((cVar2 != '\0') && (*(char *)(param_1 + 0x497) == '\0')) &&
         ((*(long *)(param_1 + 0x1bc0) == 0 ||
          (cVar2 = kmigmgrIsMIGEnabled_IMPL(param_1), uVar15 = extraout_RDX_00, cVar2 == '\0')))) {
        local_c0[0] = *(uint *)(param_1 + 0x7ac);
        local_c0[1] = 0;
        auStack_b8[0]._0_4_ = 0;
        iVar4 = gpuacctEnableAccounting_IMPL
                          (*(undefined8 *)(g_pSys + 0x218),*(undefined4 *)(param_1 + 0x7a4),local_c0
                          );
        uVar15 = extraout_RDX_01;
        if (iVar4 != 0) {
          uVar15 = (ulong)*(uint *)(param_1 + 0x7ac);
          nvDbg_Printf("src/kernel/gpu/gpu.c",0xaa7,"gpuStateLoad_IMPL",4,
                       "NVRM: gpuEnableAccounting failed with error %d on GPU ID %d\n",iVar4);
        }
      }
      *(undefined1 *)(param_1 + 0x4916) = 0;
      *(undefined1 *)(param_1 + 0x4918) = 1;
      if ((((*(long *)(param_1 + 0x1bc0) != 0) &&
           (cVar2 = kmigmgrIsMIGEnabled_IMPL(param_1,*(long *)(param_1 + 0x1bc0),uVar15),
           cVar2 != '\0')) || (bVar14 == 0)) ||
         (iVar4 = memmgrCheckZeroPmaUsage_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b78)),
         iVar4 == 0)) {
        (**(code **)(param_1 + 1000))(param_1);
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar4,"memmgrCheckZeroPmaUsage(pGpu, pMemoryManager)","src/kernel/gpu/gpu.c",0xac4)
      ;
      iVar6 = *(int *)(param_1 + 0x4b08);
joined_r0x0034bed5:
      if (iVar6 != 0) {
        return iVar4;
      }
      *(undefined4 *)(param_1 + 0x4b08) = 0x13;
      *(int *)(param_1 + 0x4b0c) = iVar4;
      return iVar4;
    }
    puVar9 = (uint *)portMemAllocNonPaged(0x504);
    if (puVar9 == (uint *)0x0) {
      nvCheckFailedNoLog(4,"pSetP2PCapsParams != NULL","src/kernel/gpu/gpu.c",0xcd5);
    }
    else {
      puVar10 = (undefined4 *)portMemAllocNonPaged(0x80);
      if (puVar10 == (undefined4 *)0x0) {
        nvCheckFailedNoLog(4,"peerGpuIds != NULL","src/kernel/gpu/gpu.c",0xcdb);
        portMemFree(puVar9);
        portMemFree(0);
        portMemFree(0);
      }
      else {
        puVar11 = (undefined4 *)portMemAllocNonPaged(0x80);
        if (puVar11 != (undefined4 *)0x0) {
          local_fc = gpumgrGetGpuAttachInfo(local_dc,&local_e0);
          if (local_fc == 0) {
            local_d8 = 0;
LAB_0034ba0f:
            do {
              lVar7 = gpumgrGetNextGpu(local_e0,&local_d8);
              if (lVar7 == 0) {
                portMemFree(puVar9);
                portMemFree(puVar10);
                portMemFree(puVar11);
                local_fc = kvgpumgrSendAllVgpuTypesToGsp(param_1);
                if (local_fc == 0) goto LAB_0034baad;
                uVar17 = 0xdee;
                pcVar13 = "kvgpumgrSendAllVgpuTypesToGsp(pGpu)";
                goto LAB_0034bd3f;
              }
              if (*(char *)(lVar7 + 0x4918) == '\0') {
                if (param_1 != lVar7) goto LAB_0034ba0f;
                portMemSet(puVar9,0,0x504);
LAB_0034ba53:
                local_c0[0] = 0;
                uVar15 = 0;
                while( true ) {
                  lVar12 = gpumgrGetNextGpu(local_e0,local_c0);
                  if (lVar12 == 0) break;
                  if ((*(char *)(lVar12 + 0x4918) != '\0') || (param_1 == lVar12)) {
                    puVar10[uVar15] = *(undefined4 *)(lVar12 + 0x7ac);
                    puVar11[uVar15] = *(undefined4 *)(lVar12 + 0x7a4);
                    uVar15 = (ulong)((uint)uVar15 + 1);
                  }
                }
                *puVar9 = (uint)uVar15;
              }
              else {
                portMemSet(puVar9,0,0x504);
                if (param_1 == lVar7) goto LAB_0034ba53;
                *puVar9 = 1;
                *puVar10 = *(undefined4 *)(param_1 + 0x7ac);
                *puVar11 = *(undefined4 *)(param_1 + 0x7a4);
                uVar15 = (ulong)*puVar9;
              }
              if ((int)uVar15 != 0) {
                puVar16 = puVar9 + 3;
                uVar15 = 0;
                do {
                  local_c0[1] = puVar10[uVar15];
                  puVar9[(uVar15 & 0xffffffff) * 10 + 1] = local_c0[1];
                  puVar9[(uVar15 & 0xffffffff) * 10 + 2] = puVar11[uVar15];
                  local_c0[0] = *(uint *)(lVar7 + 0x7ac);
                  local_fc = CliGetSystemP2pCaps(local_c0,(local_c0[1] != local_c0[0]) + '\x01',
                                                 puVar16,puVar16 + 1,puVar16 + 2,puVar16 + 3,
                                                 puVar16 + 6,puVar16 + 7);
                  if (local_fc != 0) {
                    uVar17 = 0xd1b;
                    pcVar13 = 
                    "CliGetSystemP2pCaps((NvU32[]) { pGpu->gpuId, pPeerInfo->gpuId }, (pGpu->gpuId == pPeerInfo->gpuId) ? 1 : 2, &pPeerInfo->p2pCaps, &pPeerInfo->p2pOptimalReadCEs, &pPeerInfo->p2pOptimalWriteCEs, pPeerInfo->p2pCapsStatus, &pPeerInfo->busPeerId, &pPeerInfo->busEgmPeerId)"
                    ;
                    goto LAB_0034c158;
                  }
                  uVar15 = uVar15 + 1;
                  puVar16 = puVar16 + 10;
                } while ((uint)uVar15 < *puVar9);
              }
              if (*(code **)(lVar7 + 0x3b90) == _gpuRmApiControl) {
                local_fc = _gpuRmApiControl();
              }
              else {
                local_fc = (**(code **)(lVar7 + 0x3b90))
                                     (lVar7 + 0x3b58,*(undefined4 *)(lVar7 + 0x3b34),
                                      *(undefined4 *)(lVar7 + 0x3b3c),0x20800ab5,puVar9,0x504);
              }
              if (local_fc != 0) goto code_r0x0034c38a;
            } while( true );
          }
          nvCheckOkFailedNoLog
                    (4,local_fc,"gpumgrGetGpuAttachInfo(&gpuCount, &attachMask)",
                     "src/kernel/gpu/gpu.c",0xce5);
          portMemFree(puVar9);
          portMemFree(puVar10);
          portMemFree(puVar11);
          goto LAB_0034c317;
        }
        nvCheckFailedNoLog(4,"peerGpuInstances != NULL","src/kernel/gpu/gpu.c",0xce1);
        portMemFree(puVar9);
        portMemFree(puVar10);
        portMemFree(0);
      }
    }
    local_fc = 0x51;
    goto LAB_0034c317;
  }
  local_c0[0] = local_c0[0] & 0xffffff00;
  uVar3 = kvgpumgrIsHeterogeneousVgpuTypeSupported();
  local_c0[0] = CONCAT31(local_c0[0]._1_3_,uVar3);
  if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
    local_fc = _gpuRmApiControl();
  }
  else {
    local_fc = (**(code **)(param_1 + 0x3b90))
                         (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                          *(undefined4 *)(param_1 + 0x3b3c),0x2080400b,local_c0,1);
  }
  if (local_fc == 0) goto LAB_0034b974;
  nvCheckOkFailedNoLog
            (4,local_fc,
             "pPeerRmApi->Control(pPeerRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_SET_VGPU_MGR_CONFIG, &params, sizeof(params))"
             ,"src/kernel/gpu/gpu.c",0xd75);
  uVar17 = 0xde1;
  pcVar13 = "_gpuSetVgpuMgrConfig(pGpu)";
LAB_0034bd3f:
  nvCheckOkFailedNoLog(4,local_fc,pcVar13,"src/kernel/gpu/gpu.c",uVar17);
  iVar4 = *(int *)(param_1 + 0x4b08);
  goto LAB_0034bd58;
code_r0x0034c200:
  if (param_1 == lVar7) {
LAB_0034c209:
    local_d4 = 0;
    while (lVar12 = gpumgrGetNextGpu(local_e0,&local_d4), lVar12 != 0) {
      if ((*(char *)(lVar12 + 0x4918) != '\0') || (param_1 == lVar12)) {
        local_c0[(ulong)local_c0[0] + 1] = *(uint *)(lVar12 + 0x7ac);
        local_c0[0] = local_c0[0] + 1;
      }
    }
LAB_0034c275:
    if (*(code **)(lVar7 + 0x3b90) == _gpuRmApiControl) {
      iVar6 = _gpuRmApiControl();
    }
    else {
      iVar6 = (**(code **)(lVar7 + 0x3b90))
                        (lVar7 + 0x3b58,*(undefined4 *)(lVar7 + 0x3b34),
                         *(undefined4 *)(lVar7 + 0x3b3c),0x20800ab6,local_c0,0x84);
    }
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "pPeerRmApi->Control(pPeerRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_REMOVE_P2P_CAPS, &removeP2PCapsParams, sizeof(removeP2PCapsParams))"
                 ,"src/kernel/gpu/gpu.c",0xd56);
    }
  }
  goto LAB_0034c183;
code_r0x0034c38a:
  uVar17 = 0xd27;
  pcVar13 = 
  "pPeerRmApi->Control(pPeerRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_SET_P2P_CAPS, pSetP2PCapsParams, sizeof(*pSetP2PCapsParams))"
  ;
LAB_0034c158:
  nvCheckOkFailedNoLog(4,local_fc,pcVar13,"src/kernel/gpu/gpu.c",uVar17);
  iVar4 = local_d8;
  local_d8 = 0;
LAB_0034c183:
  lVar7 = gpumgrGetNextGpu(local_e0,&local_d8);
  if ((lVar7 != 0) && (iVar4 != local_d8)) {
    uVar15 = 0;
    do {
      uVar5 = (int)uVar15 + 0x20;
      *(undefined8 *)((long)local_c0 + uVar15) = 0;
      *(undefined8 *)((long)auStack_b8 + uVar15) = 0;
      *(undefined8 *)((long)auStack_b8 + uVar15 + 8) = 0;
      *(undefined8 *)((long)auStack_a0 + (uVar15 - 8)) = 0;
      uVar15 = (ulong)uVar5;
    } while (uVar5 < 0x80);
    *(undefined4 *)((long)local_c0 + (ulong)uVar5) = 0;
    if (*(char *)(lVar7 + 0x4918) == '\0') goto code_r0x0034c200;
    if (param_1 == lVar7) goto LAB_0034c209;
    local_c0[1] = *(uint *)(param_1 + 0x7ac);
    local_c0[0] = 1;
    goto LAB_0034c275;
  }
  portMemFree(puVar9);
  portMemFree(puVar10);
  portMemFree(puVar11);
LAB_0034c317:
  nvCheckOkFailedNoLog
            (4,local_fc,"_gpuPropagateP2PCapsToAllGpus(pGpu)","src/kernel/gpu/gpu.c",0xde9);
  iVar4 = *(int *)(param_1 + 0x4b08);
LAB_0034bd58:
  if (iVar4 != 0) {
    return local_fc;
  }
  *(undefined4 *)(param_1 + 0x4b08) = 0x16;
LAB_0034b738:
  *(int *)(param_1 + 0x4b0c) = local_fc;
  return local_fc;
}


// ===== 0034c4b0 gpuSetRecoveryDrainP2P_KERNEL =====

void gpuSetRecoveryDrainP2P_KERNEL(long param_1,char param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if ((*(char *)(param_1 + 0x4b7) != '\0') == (param_2 != '\0')) {
    return;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x4b9);
  *(char *)(param_1 + 0x4b7) = param_2;
  puVar3 = (undefined1 *)portMemAllocNonPaged(1);
  if (puVar3 != (undefined1 *)0x0) {
    *puVar3 = uVar1;
    iVar2 = osQueueWorkItem(param_1,_gpuRefreshRecoveryActionInLock,puVar3,0x40);
    if (iVar2 == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c8a,"gpuRefreshRecoveryAction_KERNEL",4,
                 "NVRM: Failed to queue recovery action work item: 0x%x\n",iVar2);
    portMemFree(puVar3);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c7e,"gpuRefreshRecoveryAction_KERNEL",4,
               "NVRM: Failed to allocate memory for recovery action params\n");
  return;
}


// ===== 0034c590 gpuUnmarkDeviceForDrainP2P_KERNEL =====

void gpuUnmarkDeviceForDrainP2P_KERNEL(long param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  uVar1 = *(undefined1 *)(param_1 + 0x4b9);
  *(undefined1 *)(param_1 + 0x4b7) = 0;
  puVar3 = (undefined1 *)portMemAllocNonPaged(1);
  if (puVar3 == (undefined1 *)0x0) {
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c7e,"gpuRefreshRecoveryAction_KERNEL",4,
                 "NVRM: Failed to allocate memory for recovery action params\n");
    return;
  }
  *puVar3 = uVar1;
  iVar2 = osQueueWorkItem(param_1,_gpuRefreshRecoveryActionInLock,puVar3,0x40);
  if (iVar2 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c8a,"gpuRefreshRecoveryAction_KERNEL",4,
               "NVRM: Failed to queue recovery action work item: 0x%x\n",iVar2);
  portMemFree(puVar3);
  return;
}


// ===== 0034c670 gpuSetPartitionErrorAttribution_KERNEL =====

undefined8 gpuSetPartitionErrorAttribution_KERNEL(undefined8 param_1,int param_2)

{
  if (param_2 != 0x12) {
    nvDbg_Printf("src/kernel/gpu/gpu.c",0x1cd6,"gpuSetPartitionErrorAttribution_KERNEL",4,
                 "NVRM: Invalid error ID: 0x%x\n",param_2);
    nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x1cd7);
    return 0x1f;
  }
  nvDbg_Printf("src/kernel/gpu/gpu.c",0x1cd0,"gpuSetPartitionErrorAttribution_KERNEL",4,
               "NVRM: MIG_INSTANCE_REF determining is not supported for error ID 0x%x.\n",0x12);
  nvAssertFailedNoLog(&DAT_00d24de3,"src/kernel/gpu/gpu.c",0x1cd1);
  return 0x1f;
}


// ===== 0034c720 gpuLogOobXidMessage_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuLogOobXidMessage_KERNEL(long param_1,int param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  int local_74;
  undefined8 local_70 [6];
  undefined8 local_3c;
  undefined8 local_34;
  undefined8 local_2c;
  undefined8 local_24;
  uint local_1c;
  
  uVar1 = 0;
  local_3c = 0;
  local_34 = 0;
  local_2c = 0;
  local_24 = 0;
  do {
    uVar3 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)local_70 + uVar3) = 0;
    *(undefined8 *)((long)local_70 + uVar3 + 8) = 0;
    *(undefined8 *)((long)local_70 + uVar3 + 0x10) = 0;
    *(undefined8 *)((long)local_70 + uVar3 + 0x18) = 0;
  } while (uVar1 < 0x40);
  if ((((((1 < param_2 - 0x77U) && (param_2 != 0x4f)) && (*(char *)(param_1 + 0x44f) == '\0')) &&
       ((*(char *)(param_1 + 0x450) == '\0' && (*(char *)(param_1 + 0x451) == '\0')))) &&
      ((*(char *)(param_1 + 0x461) == '\0' &&
       ((*(char *)(param_1 + 0x7e1) != '\0' && (*(char *)(param_1 + 0x4b6) == '\0')))))) &&
     ((*(char *)(param_1 + 0x455) == '\0' &&
      ((*(char *)(*(long *)(param_1 + 0x1ba8) + 0x69eff) == '\0' &&
       (*(char *)(param_1 + 0x44c) != '\0')))))) {
    local_1c = param_4;
    if (0x50 < param_4) {
      local_1c = 0x50;
    }
    local_74 = param_2;
    portMemCopy(local_70,0x51,param_3,local_1c);
    if (*(code **)(param_1 + 0x3b90) == _gpuRmApiControl) {
      iVar2 = _gpuRmApiControl();
    }
    else {
      iVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800a56,&local_74,0x5c);
    }
    if (iVar2 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar2,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_LOG_OOB_XID, &params, sizeof(params))"
                 ,"src/kernel/gpu/gpu.c",0x1d12);
      return;
    }
  }
  return;
}


// ===== 0034c8c0 gpuValidateMIGSupport_KERNEL =====

undefined1 gpuValidateMIGSupport_KERNEL(long param_1)

{
  if (*(char *)(param_1 + 0x90a) == '\0') {
    if (*(long *)(param_1 + 0x1ba8) != 0) {
      return *(undefined1 *)(*(long *)(param_1 + 0x1ba8) + 0x6a545);
    }
    nvAssertFailedNoLog("GPU_GET_KERNEL_GSP(pGpu) != NULL","src/kernel/gpu/gpu.c",0x17f8);
  }
  nvAssertFailedNoLog("pGSCI != NULL","src/kernel/gpu/gpu.c",0x1d24);
  return 0;
}


// ===== 0034c930 gpuSetRecoveryRebootRequired_IMPL =====

void gpuSetRecoveryRebootRequired_IMPL(long param_1,char param_2,undefined1 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  if ((*(char *)(param_1 + 0x4b8) != '\0') != (param_2 != '\0')) {
    uVar1 = *(undefined1 *)(param_1 + 0x4b9);
    *(char *)(param_1 + 0x4b8) = param_2;
    puVar3 = (undefined1 *)portMemAllocNonPaged(1);
    if (puVar3 == (undefined1 *)0x0) {
      nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c7e,"gpuRefreshRecoveryAction_KERNEL",4,
                   "NVRM: Failed to allocate memory for recovery action params\n");
    }
    else {
      *puVar3 = uVar1;
      iVar2 = osQueueWorkItem(param_1,_gpuRefreshRecoveryActionInLock,puVar3,0x40);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/gpu.c",0x1c8a,"gpuRefreshRecoveryAction_KERNEL",4,
                     "NVRM: Failed to queue recovery action work item: 0x%x\n",iVar2);
        portMemFree(puVar3);
      }
    }
  }
  *(undefined1 *)(param_1 + 0x4a7c) = param_3;
  return;
}


// ===== 0034ca30 gpuGenGidData_SOC =====

undefined4 gpuGenGidData_SOC(long param_1,long param_2,int param_3,uint param_4)

{
  undefined8 local_18;
  undefined4 local_10;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  
  if ((param_4 & 4) != 0) {
    return 0x29;
  }
  local_18 = 0xb80abb6dd26ac6a7;
  local_c = 0xba6d;
  local_10 = 0xba37a2c1;
  local_a = 0x36;
  local_9 = (undefined1)*(undefined4 *)(param_1 + 0x7a4);
  if ((param_3 == 0x10) && (param_2 != 0)) {
    portMemCopy(param_2,0x10,&local_18,0x10);
    return 0;
  }
  return 0x1f;
}


// ===== 0034cac0 gpuGetOneDeviceEntry_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuGetOneDeviceEntry_IMPL
              (long param_1,int param_2,int param_3,int param_4,int param_5,ulong *param_6)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  bool bVar6;
  
  if (param_6 == (ulong *)0x0) {
    nvAssertFailedNoLog("ppDeviceEntry != NULL","src/kernel/gpu/gpu.c",0x1da4);
    return 0x1f;
  }
  *param_6 = 0;
  iVar2 = (**(code **)(param_1 + 0xa0))();
  if (iVar2 == 0) {
    uVar1 = 1 << ((byte)param_3 & 0x1f);
    if (param_3 == -1) {
      uVar1 = 0xffffffff;
    }
    uVar3 = *(long *)(param_1 + 0x3b28) - 0x30;
    uVar5 = 0;
    uVar4 = (ulong)*(uint *)(param_1 + 0x3b30) * 0x30 + *(long *)(param_1 + 0x3b28);
LAB_0034cb60:
    uVar3 = uVar3 + 0x30;
    if (uVar3 < uVar4) {
      do {
        if ((param_2 == *(int *)(uVar3 + 8)) &&
           ((uVar1 >> (*(uint *)(uVar3 + 0x20) & 0x1f) & 1) != 0)) {
          if (((param_4 != -1) && (*(int *)(uVar3 + 4) != param_4)) ||
             ((param_5 != -1 && (*(int *)(uVar3 + 0x2c) != param_5)))) goto LAB_0034cb60;
          bVar6 = uVar5 != 0;
          uVar5 = uVar3;
          if (bVar6) {
            return 0x4c;
          }
        }
        uVar3 = uVar3 + 0x30;
        if (uVar4 <= uVar3) break;
      } while( true );
    }
    if (uVar5 == 0) {
      iVar2 = 0x57;
    }
    else {
      *param_6 = uVar5;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,"gpuConstructDeviceInfoTable_HAL(pGpu)","src/kernel/gpu/gpu.c",0x1da6);
  }
  return iVar2;
}


// ===== 0034cc60 gpuBootGspRmProxy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuBootGspRmProxy_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x1d08) != 0) {
    uVar2 = (**(code **)(*(long *)(param_1 + 0x1d08) + 0x1b8))();
    return uVar2;
  }
  lVar1 = *(long *)(param_1 + 0x1ba0);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x90c) == '\0')) {
    uVar2 = (**(code **)(lVar1 + 0x840))();
    return uVar2;
  }
  return 0;
}


// ===== 0034ccb0 gpuIsInstInSysBootByAcrEnabled_IMPL =====

undefined8 gpuIsInstInSysBootByAcrEnabled_IMPL(void)

{
  return 0;
}


// ===== 0034ccc0 regAccessConstruct =====

int regAccessConstruct(long *param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  
  *param_1 = param_2;
  if (*(char *)(param_2 + 0x45a) == '\0') {
    lVar4 = param_2 + 0x1a18;
    cVar1 = *(char *)(param_2 + 0x7a0);
    uVar5 = 0;
    do {
      lVar3 = gpuGetDeviceMapping_IMPL(param_2,uVar5,0);
      if ((lVar3 != 0) &&
         (iVar2 = __nvoc_objCreate_IoAperture
                            (lVar4,0,0,0,param_2,uVar5,0,lVar3,0,0,*(undefined8 *)(lVar3 + 0x10)),
         iVar2 != 0)) {
        nvDbg_Printf("src/kernel/gpu/gpu_access.c",0x30f,"_gpuInitIOAperture",4,
                     "NVRM: Failed to initialize pGpu IO aperture for devIdx %d.\n",uVar5);
        nvDbg_Printf("src/kernel/gpu/gpu_access.c",0x57,"regAccessConstruct",4,
                     "NVRM: Failed to initialize pGpu IO device/aperture for deviceIndex=%d.\n",
                     uVar5);
        return iVar2;
      }
      uVar5 = uVar5 + 1;
      lVar4 = lVar4 + 8;
    } while (uVar5 <= (-(uint)(cVar1 != '\0') & 0xc));
  }
  return 0;
}


// ===== 0034cdf0 regAccessDestruct =====

void regAccessDestruct(long *param_1)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  
  lVar1 = *param_1;
  if (lVar1 != 0) {
    plVar2 = (long *)(lVar1 + 0x1a18);
    do {
      if (*plVar2 != 0) {
        __nvoc_objDelete();
      }
      plVar2 = plVar2 + 1;
    } while (plVar2 != (long *)(lVar1 + 0x1a80));
    if (*(int *)(lVar1 + 0x934) != 0) {
      plVar2 = (long *)(lVar1 + 0x960);
      uVar3 = 0;
      do {
        if (*plVar2 != 0) {
          nvAssertFailedNoLog("!pGpu->deviceMappings[mappingNum].devRegFilterInfo.pRegFilterList",
                              "src/kernel/gpu/gpu_access.c",0x7f);
        }
        if (plVar2[2] != 0) {
          portSyncSpinlockDestroy();
          plVar2[2] = 0;
        }
        while ((long *)plVar2[1] != (long *)0x0) {
          plVar2[1] = *(long *)plVar2[1];
          portMemFree();
        }
        uVar3 = uVar3 + 1;
        plVar2 = plVar2 + 9;
      } while (uVar3 < *(uint *)(lVar1 + 0x934));
    }
  }
  return;
}


// ===== 0034cee0 ioaprtInit =====

void ioaprtInit(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_10;
  
  local_10 = param_1;
  __nvoc_objCreate_IoAperture(&local_10,0,2,param_2,0,0,0,0,0,param_3,param_4);
  return;
}


// ===== 0034cf20 ioaprtConstruct_IMPL =====

undefined1  [16]
ioaprtConstruct_IMPL
          (long param_1,long param_2,ulong param_3,undefined4 param_4,undefined4 param_5,
          long param_6,undefined4 param_7,uint param_8,long param_9)

{
  uint uVar1;
  undefined1 auVar2 [16];
  undefined8 extraout_RDX;
  undefined8 uVar3;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 extraout_RDX_02;
  undefined8 extraout_RDX_03;
  undefined1 auVar4 [16];
  
  if (param_9 == 0) {
    nvAssertFailedNoLog("length > 0","src/kernel/gpu/gpu_access.c",0x10a);
    uVar3 = extraout_RDX;
  }
  else if (param_2 == 0) {
    if (param_6 == 0) {
      nvAssertFailedNoLog("pMapping != NULL","src/kernel/gpu/gpu_access.c",0x123);
      uVar3 = extraout_RDX_02;
    }
    else {
      if (param_3 != 0) {
        *(long *)(param_1 + 0x70) = param_6;
        *(ulong *)(param_1 + 0x60) = param_3;
        *(undefined4 *)(param_1 + 0x68) = param_4;
        *(undefined4 *)(param_1 + 0x6c) = param_5;
        *(undefined4 *)(param_1 + 0x78) = param_7;
        goto LAB_0034cf9b;
      }
      nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/gpu_access.c",0x124);
      uVar3 = extraout_RDX_03;
    }
  }
  else if (param_6 == 0) {
    if ((param_3 == 0) || (*(ulong *)(param_2 + 0x60) == param_3)) {
      *(ulong *)(param_1 + 0x60) = *(ulong *)(param_2 + 0x60);
      *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_2 + 0x68);
      *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_2 + 0x6c);
      *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(param_2 + 0x70);
      uVar1 = *(uint *)(param_2 + 0x7c);
      *(uint *)(param_1 + 0x7c) = uVar1;
      *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_2 + 0x78);
      param_3 = *(ulong *)(param_2 + 0x80);
      if (param_3 < (ulong)param_8 + param_9) {
        nvDbg_Printf("src/kernel/gpu/gpu_access.c",0x11b,"ioaprtConstruct_IMPL",3,
                     "NVRM: Child aperture crosses parent\'s boundary, length 0x%llx offset 0x%x, Parent\'s length 0x%llx\n"
                     ,param_9,(ulong)param_8);
        param_8 = param_8 + *(int *)(param_1 + 0x7c);
      }
      else {
        param_8 = param_8 + uVar1;
        param_3 = (ulong)uVar1;
      }
LAB_0034cf9b:
      *(uint *)(param_1 + 0x7c) = param_8;
      *(long *)(param_1 + 0x80) = param_9;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = param_3;
      return auVar2 << 0x40;
    }
    nvAssertFailedNoLog("pGpu == NULL || pGpu == pParentAperture->pGpu",
                        "src/kernel/gpu/gpu_access.c",0x10f);
    uVar3 = extraout_RDX_01;
  }
  else {
    nvAssertFailedNoLog("pMapping == NULL","src/kernel/gpu/gpu_access.c",0x10e);
    uVar3 = extraout_RDX_00;
  }
  auVar4._8_8_ = uVar3;
  auVar4._0_8_ = 0x1f;
  return auVar4;
}


// ===== 0034d0e0 ioaprtDestruct_IMPL =====

void ioaprtDestruct_IMPL(long param_1)

{
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 0x80) = 0;
  }
  return;
}


// ===== 0034d100 ioaprtIsRegValid_IMPL =====

bool ioaprtIsRegValid_IMPL(long param_1,uint param_2)

{
  if (param_1 != 0) {
    return (ulong)param_2 < *(ulong *)(param_1 + 0x80);
  }
  nvAssertFailedNoLog("pAperture != NULL","src/kernel/gpu/gpu_access.c",0x24e);
  return false;
}


// ===== 0034d140 gpuSanityCheckRegisterAccess_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuSanityCheckRegisterAccess_IMPL(long param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  
  cVar4 = '\0';
  if (*(long *)(param_1 + 0x1d48) != 0) {
    cVar4 = *(char *)(*(long *)(param_1 + 0x1d48) + 0x168);
  }
  if ((((*(char *)(param_1 + 0x44f) == '\0') && (*(char *)(param_1 + 0x450) == '\0')) &&
      (*(char *)(param_1 + 0x451) == '\0')) && (*(char *)(param_1 + 0x461) == '\0')) {
    if (*(char *)(param_1 + 0x44c) == '\0') {
      uVar3 = 0xffffffff;
      iVar2 = 0xf;
    }
    else {
      iVar2 = (**(code **)(param_1 + 0x220))();
      if (iVar2 == 0) {
        cVar1 = gpuIsGpuFullPower_IMPL();
        if (cVar1 != '\0') {
          return 0;
        }
        if ((*(uint *)(param_1 + 0x4b34) & 0xfffffffd) == 1) {
          return 0;
        }
        if (*(char *)(param_1 + 0x49e) != '\0') {
          return 0;
        }
        if (cVar4 != '\0' || *(char *)(param_1 + 0x482) != '\0') {
          return 0;
        }
        if (*(char *)(param_1 + 0x444) != '\0') {
          return 0;
        }
        uVar3 = 0xffffffff;
        iVar2 = 0x11;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/gpu_access.c",0x458,"gpuSanityCheckRegisterAccess_IMPL",4,
                     "NVRM: Invalid register access on VF, addr: 0x%x\n",param_2);
        osAssertFailed();
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
    iVar2 = 0x10;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar3;
  }
  return iVar2;
}


// ===== 0034d290 ioaprtWriteReg32Uc_IMPL =====

void ioaprtWriteReg32Uc_IMPL(long param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    nvAssertFailedNoLog("ioaprtIsInitialized(pAperture)","src/kernel/gpu/gpu_access.c",0x152);
    return;
  }
  lVar2 = *(long *)(param_1 + 0x60);
  iVar1 = *(int *)(param_1 + 0x78);
  uVar3 = *(undefined8 *)(param_1 + 0x70);
  param_2 = param_2 + *(int *)(param_1 + 0x7c);
  if (*(char *)(lVar2 + 0x45a) != '\0') {
    osDevWriteReg032(lVar2,uVar3,param_2 - iVar1);
    return;
  }
  iVar4 = gpuSanityCheckRegisterAccess_IMPL(lVar2,param_2,0,param_3);
  if (iVar4 == 0) {
    osDevWriteReg032(lVar2,uVar3,param_2 - iVar1,param_3);
    return;
  }
  return;
}


// ===== 0034d340 regWrite032 =====

void regWrite032(long *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *param_1;
  piVar1 = (int *)(lVar4 + 0x3a34);
  *piVar1 = *piVar1 + 1;
  uVar2 = *(undefined8 *)(lVar4 + 0x3a18);
  lVar4 = gpuGetDeviceMapping_IMPL(uVar2);
  if (lVar4 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_access.c",0xb7,"_regWriteUnicast",4,
                 "NVRM: Could not find mapping for reg %x, deviceIndex=0x%x instance=%d\n",param_4,
                 param_2,param_3);
    nvAssertFailedNoLog(&DAT_00d2749f,"src/kernel/gpu/gpu_access.c",0xba);
    return;
  }
  iVar3 = gpuSanityCheckRegisterAccess_IMPL(uVar2,param_4,0);
  if (iVar3 == 0) {
    osDevWriteReg032(uVar2,lVar4,param_4,param_5);
    return;
  }
  return;
}


// ===== 0034d440 ioaprtWriteReg08_IMPL =====

void ioaprtWriteReg08_IMPL(long param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    nvAssertFailedNoLog("ioaprtIsInitialized(pAperture)","src/kernel/gpu/gpu_access.c",0x152);
    return;
  }
  lVar2 = *(long *)(param_1 + 0x60);
  iVar1 = *(int *)(param_1 + 0x78);
  uVar3 = *(undefined8 *)(param_1 + 0x70);
  param_2 = param_2 + *(int *)(param_1 + 0x7c);
  if (*(char *)(lVar2 + 0x45a) != '\0') {
    osDevWriteReg008(lVar2,uVar3,param_2 - iVar1);
    return;
  }
  iVar4 = gpuSanityCheckRegisterAccess_IMPL(lVar2,param_2,0);
  if (iVar4 == 0) {
    osDevWriteReg008(lVar2,uVar3,param_2 - iVar1,param_3);
    return;
  }
  return;
}


// ===== 0034d4f0 ioaprtWriteReg16_IMPL =====

void ioaprtWriteReg16_IMPL(long param_1,int param_2,undefined2 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    nvAssertFailedNoLog("ioaprtIsInitialized(pAperture)","src/kernel/gpu/gpu_access.c",0x152);
    return;
  }
  lVar2 = *(long *)(param_1 + 0x60);
  iVar1 = *(int *)(param_1 + 0x78);
  uVar3 = *(undefined8 *)(param_1 + 0x70);
  param_2 = param_2 + *(int *)(param_1 + 0x7c);
  if (*(char *)(lVar2 + 0x45a) == '\0') {
    iVar4 = gpuSanityCheckRegisterAccess_IMPL(lVar2,param_2,0);
    if (iVar4 != 0) {
      return;
    }
  }
  osDevWriteReg016(lVar2,uVar3,param_2 - iVar1,param_3);
  return;
}


// ===== 0034d590 ioaprtWriteReg32_IMPL =====

void ioaprtWriteReg32_IMPL(long param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    nvAssertFailedNoLog("ioaprtIsInitialized(pAperture)","src/kernel/gpu/gpu_access.c",0x152);
    return;
  }
  lVar2 = *(long *)(param_1 + 0x60);
  iVar1 = *(int *)(param_1 + 0x78);
  uVar3 = *(undefined8 *)(param_1 + 0x70);
  param_2 = param_2 + *(int *)(param_1 + 0x7c);
  if (*(char *)(lVar2 + 0x45a) != '\0') {
    osDevWriteReg032(lVar2,uVar3,param_2 - iVar1);
    return;
  }
  iVar4 = gpuSanityCheckRegisterAccess_IMPL(lVar2,param_2,0,param_3);
  if (iVar4 == 0) {
    osDevWriteReg032(lVar2,uVar3,param_2 - iVar1,param_3);
    return;
  }
  return;
}


// ===== 0034d640 regWrite032Unicast =====

void regWrite032Unicast(undefined8 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                       ,undefined4 param_5)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  
  uVar1 = *param_1;
  *(int *)((long)param_1 + 0x1c) = *(int *)((long)param_1 + 0x1c) + 1;
  lVar3 = gpuGetDeviceMapping_IMPL(uVar1);
  if (lVar3 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_access.c",0xb7,"_regWriteUnicast",4,
                 "NVRM: Could not find mapping for reg %x, deviceIndex=0x%x instance=%d\n",param_4,
                 param_2,param_3);
    nvAssertFailedNoLog(&DAT_00d2749f,"src/kernel/gpu/gpu_access.c",0xba);
    return;
  }
  iVar2 = gpuSanityCheckRegisterAccess_IMPL(uVar1,param_4,0);
  if (iVar2 == 0) {
    osDevWriteReg032(uVar1,lVar3,param_4,param_5);
    return;
  }
  return;
}


// ===== 0034d740 regWrite008 =====

void regWrite008(long *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined1 param_5)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *param_1;
  piVar1 = (int *)(lVar4 + 0x3a34);
  *piVar1 = *piVar1 + 1;
  uVar2 = *(undefined8 *)(lVar4 + 0x3a18);
  lVar4 = gpuGetDeviceMapping_IMPL(uVar2);
  if (lVar4 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_access.c",0xb7,"_regWriteUnicast",4,
                 "NVRM: Could not find mapping for reg %x, deviceIndex=0x%x instance=%d\n",param_4,
                 param_2,param_3);
    nvAssertFailedNoLog(&DAT_00d2749f,"src/kernel/gpu/gpu_access.c",0xba);
    return;
  }
  iVar3 = gpuSanityCheckRegisterAccess_IMPL(uVar2,param_4,0);
  if (iVar3 == 0) {
    osDevWriteReg008(uVar2,lVar4,param_4,param_5);
    return;
  }
  return;
}


// ===== 0034d840 regWrite016 =====

void regWrite016(long *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined2 param_5)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *param_1;
  piVar1 = (int *)(lVar4 + 0x3a34);
  *piVar1 = *piVar1 + 1;
  uVar2 = *(undefined8 *)(lVar4 + 0x3a18);
  lVar4 = gpuGetDeviceMapping_IMPL(uVar2);
  if (lVar4 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_access.c",0xb7,"_regWriteUnicast",4,
                 "NVRM: Could not find mapping for reg %x, deviceIndex=0x%x instance=%d\n",param_4,
                 param_2,param_3);
    nvAssertFailedNoLog(&DAT_00d2749f,"src/kernel/gpu/gpu_access.c",0xba);
    return;
  }
  iVar3 = gpuSanityCheckRegisterAccess_IMPL(uVar2,param_4,0);
  if (iVar3 == 0) {
    osDevWriteReg016(uVar2,lVar4,param_4,param_5);
    return;
  }
  return;
}


// ===== 0034d950 gpuValidateRegOffset_IMPL =====

undefined8 gpuValidateRegOffset_IMPL(long param_1,uint param_2,char param_3)

{
  char cVar1;
  
  if (*(long *)(param_1 + 0x948) - 4U < (ulong)param_2) {
    return 0x1f;
  }
  if (param_3 == '\0') {
    cVar1 = osIsAdministrator();
    if ((cVar1 == '\0') &&
       (cVar1 = gpuGetUserRegisterAccessPermissions_IMPL(param_1,param_2), cVar1 == '\0')) {
      nvDbg_Printf("src/kernel/gpu/gpu_access.c",0x4ae,"gpuValidateRegOffset_IMPL",4,
                   "NVRM: User does not have permission to access register offset 0x%x\n",param_2);
      return 0x1b;
    }
    return 0;
  }
  return 0;
}


// ===== 0034d9e0 gpuSanityCheckRegRead_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuSanityCheckRegRead_IMPL(long param_1,undefined4 param_2,int param_3,uint *param_4)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 == 0x10) {
    if ((short)*param_4 == -1) {
      iVar3 = osGpuReadReg032(param_1,0);
      if (iVar3 == -1) {
        osHandleGpuLost(param_1,1);
        sVar2 = osGpuReadReg016(param_1,param_2);
        *(short *)param_4 = sVar2;
      }
    }
  }
  else if (param_3 == 0x20) {
    uVar4 = *param_4;
    if (uVar4 == 0xffffffff) {
      iVar3 = osGpuReadReg032(param_1,0);
      if (iVar3 == -1) {
        osHandleGpuLost(param_1,1);
        uVar4 = osGpuReadReg032(param_1,param_2);
        *param_4 = uVar4;
      }
      else {
        uVar4 = *param_4;
      }
    }
    if ((uVar4 & 0xfff00000) == 0xbad00000) {
      (**(code **)(param_1 + 0x208))(param_1,param_2);
    }
  }
  else {
    if (param_3 != 8) {
      nvAssertFailedNoLog("Invalid access size","src/kernel/gpu/gpu_access.c",0x52d);
      return 0;
    }
    if ((char)*param_4 == -1) {
      iVar3 = osGpuReadReg032(param_1,0);
      if (iVar3 == -1) {
        osHandleGpuLost(param_1,1);
        cVar1 = osGpuReadReg008(param_1,param_2);
        *(char *)param_4 = cVar1;
      }
    }
  }
  return 0;
}


// ===== 0034db50 ioaprtReadReg =====

uint ioaprtReadReg(long param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  byte bVar5;
  ushort uVar6;
  int iVar7;
  uint local_2c [3];
  
  if (*(long *)(param_1 + 0x80) == 0) {
    nvAssertFailedNoLog("ioaprtIsInitialized(pAperture)","src/kernel/gpu/gpu_access.c",0x1f7);
    return 0;
  }
  lVar3 = *(long *)(param_1 + 0x60);
  param_2 = param_2 + *(int *)(param_1 + 0x7c);
  iVar2 = *(int *)(param_1 + 0x78);
  uVar4 = *(undefined8 *)(param_1 + 0x70);
  *(int *)(lVar3 + 0x3a30) = *(int *)(lVar3 + 0x3a30) + 1;
  if (*(char *)(lVar3 + 0x45a) == '\0') {
    iVar7 = gpuSanityCheckRegisterAccess_IMPL(lVar3,param_2,0);
    if (iVar7 != 0) {
      return 0xffffffff;
    }
    if (param_3 != 0x10) goto LAB_0034dba5;
LAB_0034dc40:
    uVar6 = osDevReadReg016(lVar3,uVar4,param_2 - iVar2);
    local_2c[0] = (uint)uVar6;
  }
  else {
    if (param_3 == 0x10) goto LAB_0034dc40;
LAB_0034dba5:
    if (param_3 != 0x20) {
      bVar5 = osDevReadReg008(lVar3,uVar4);
      local_2c[0] = (uint)bVar5;
      cVar1 = *(char *)(lVar3 + 0x45a);
      goto joined_r0x0034dbf0;
    }
    local_2c[0] = osDevReadReg032(lVar3,uVar4);
  }
  cVar1 = *(char *)(lVar3 + 0x45a);
joined_r0x0034dbf0:
  if (cVar1 == '\0') {
    gpuSanityCheckRegRead_IMPL(lVar3,param_2,param_3,local_2c);
  }
  return local_2c[0];
}


// ===== 0034dc80 ioaprtReadReg08_IMPL =====

void ioaprtReadReg08_IMPL(undefined8 param_1,undefined8 param_2)

{
  ioaprtReadReg(param_1,param_2,8);
  return;
}


// ===== 0034dca0 ioaprtReadReg16_IMPL =====

void ioaprtReadReg16_IMPL(undefined8 param_1,undefined8 param_2)

{
  ioaprtReadReg(param_1,param_2,0x10);
  return;
}


// ===== 0034dcc0 ioaprtReadReg32_IMPL =====

void ioaprtReadReg32_IMPL(undefined8 param_1,undefined8 param_2)

{
  ioaprtReadReg(param_1,param_2,0x20);
  return;
}


// ===== 0034dcd0 _regRead.isra.0 =====

ulong _regRead_isra_0(long *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     int param_5)

{
  long lVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  uint local_3c [3];
  
  *(int *)(param_1 + 3) = (int)param_1[3] + 1;
  lVar1 = *param_1;
  local_3c[0] = 0;
  lVar5 = gpuGetDeviceMapping_IMPL(lVar1);
  if (lVar5 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_access.c",0x269,"_regRead",4,
                 "NVRM: Could not find mapping for reg %x, deviceIndex=0x%x instance=%d\n",param_4,
                 param_2,param_3);
    nvAssertFailedNoLog(&DAT_00d2749f,"src/kernel/gpu/gpu_access.c",0x26c);
    return 0xd0d0d0d0;
  }
  if (param_5 == 0x20) {
    if (*(char *)(lVar1 + 0x462) != '\0') {
      uVar6 = osDevReadReg032(lVar1,lVar5,param_4);
      return uVar6;
    }
    iVar4 = gpuSanityCheckRegisterAccess_IMPL(lVar1,param_4,local_3c);
    if (iVar4 != 0) goto LAB_0034dd39;
    local_3c[0] = osDevReadReg032(lVar1,lVar5,param_4);
  }
  else {
    iVar4 = gpuSanityCheckRegisterAccess_IMPL(lVar1,param_4,local_3c);
    if (iVar4 != 0) goto LAB_0034dd39;
    if (param_5 == 0x10) {
      uVar3 = osDevReadReg016(lVar1,lVar5,param_4);
      local_3c[0] = (uint)uVar3;
    }
    else {
      bVar2 = osDevReadReg008();
      local_3c[0] = (uint)bVar2;
    }
  }
  gpuSanityCheckRegRead_IMPL(lVar1,param_4,param_5,local_3c);
LAB_0034dd39:
  return (ulong)local_3c[0];
}


// ===== 0034de40 gpuVerifyExistence_IMPL =====

undefined4 gpuVerifyExistence_IMPL(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _regRead_isra_0(param_1 + 0x3a18,0,0,0,0x20);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x8e8) != iVar1) {
    osHandleGpuLost(param_1,1);
    iVar1 = _regRead_isra_0(param_1 + 0x3a18,0,0,0,0x20);
    uVar2 = 0;
    if (*(int *)(param_1 + 0x8e8) != iVar1) {
      uVar2 = 0xf;
    }
  }
  return uVar2;
}


// ===== 0034dec0 regCheckAndLogReadFailure =====

void regCheckAndLogReadFailure(long *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined1 local_44 [2];
  undefined1 local_42 [2];
  ulong local_40 [2];
  
  lVar1 = *param_1;
  if ((*(char *)(lVar1 + 0x443) != '\0') || (*(char *)(lVar1 + 0x455) != '\0')) {
    uVar7 = 2;
    goto LAB_0034defd;
  }
  gpuSanityCheck_IMPL(lVar1,0xffffffff,local_40);
  if (param_4 == -1) {
    uVar7 = 1;
    if ((local_40[0] & 4) != 0) goto LAB_0034defd;
    if ((local_40[0] & 8) == 0) goto LAB_0034df65;
    uVar2 = *(ulong *)(lVar1 + 0x878);
    uVar6 = osPciInitHandle(uVar2 >> 0x20,uVar2 >> 8 & 0xff,uVar2 & 0xff,0,local_44,local_42);
    uVar5 = osPciReadDword(uVar6,4);
    if ((uVar5 & 2) == 0) {
      osPciWriteDword(uVar6,4,uVar5 | 6);
    }
    uVar7 = 4;
    iVar4 = _regRead_isra_0(lVar1 + 0x3a18,0,0,0,0x20);
    if (iVar4 != *(int *)(lVar1 + 0x8e8)) goto LAB_0034defd;
    uVar7 = 3;
  }
  else {
LAB_0034df65:
    uVar7 = 6;
  }
  if (((uint)local_40[0] & 2) != 0) {
    uVar7 = 5;
  }
LAB_0034defd:
  lVar3 = g_pSys;
  local_40[0] = 0;
  iVar4 = rcdbAllocNextJournalRec_IMPL(*(undefined8 *)(g_pSys + 0x228),local_40,1,0x8e,0x40);
  if (iVar4 == 0) {
    rcdbSetCommonJournalRecord(lVar1,local_40[0]);
    *(undefined4 *)(local_40[0] + 0x28) = 1;
    *(undefined4 *)(local_40[0] + 0x2c) = param_2;
    *(undefined4 *)(local_40[0] + 0x30) = param_3;
    *(int *)(local_40[0] + 0x34) = param_4;
    *(undefined4 *)(local_40[0] + 0x38) = uVar7;
    if ((*(byte *)(lVar3 + 0xac) & 0x80) != 0) {
      osBugCheck(1);
      return;
    }
  }
  return;
}


// ===== 0034e080 regCheckRead032 =====

ulong regCheckRead032(long *param_1,undefined4 param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *param_1;
  uVar2 = _regRead_isra_0(lVar1 + 0x3a18,0,0,param_2,0x20);
  if ((param_3 & (uint)uVar2) != 0) {
    if ((((lVar1 != 0) && (*(char *)(lVar1 + 0x44f) == '\0')) && (*(char *)(lVar1 + 0x450) == '\0'))
       && ((*(char *)(lVar1 + 0x451) == '\0' && (*(char *)(lVar1 + 0x461) == '\0')))) {
      regCheckAndLogReadFailure(param_1,param_2,param_3,uVar2 & 0xffffffff);
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0034e110 regRead032 =====

undefined8 regRead032(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    uVar1 = _regRead_isra_0();
    return uVar1;
  }
  return 0x3d;
}


// ===== 0034e130 regRead016 =====

void regRead016(void)

{
  _regRead_isra_0();
  return;
}


// ===== 0034e150 regRead008 =====

void regRead008(void)

{
  _regRead_isra_0();
  return;
}


// ===== 0034e170 gpuarchConstruct_IMPL =====

undefined8
gpuarchConstruct_IMPL
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  *(undefined4 *)(param_1 + 0x84) = param_2;
  *(undefined4 *)(param_1 + 0x88) = param_3;
  *(undefined4 *)(param_1 + 0x8c) = param_4;
  *(undefined4 *)(param_1 + 0x90) = param_5;
  return 0;
}


// ===== 0034e190 gpuGetDeviceMapping_IMPL =====

long gpuGetDeviceMapping_IMPL(long param_1,uint param_2,int param_3)

{
  long lVar1;
  
  if ((param_2 < 0xd) && (param_3 == 0)) {
    lVar1 = *(long *)(param_1 + 0x1a80 + (ulong)param_2 * 8);
    if (lVar1 != 0) {
      return lVar1;
    }
    if (param_2 == 0) {
      lVar1 = param_1 + 0x938;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gpu_device_mapping.c",0x48,"_gpuFindDeviceMapping",4,
                   "NVRM: Could not find mapping for deviceIndex=%d\n",param_2);
      lVar1 = 0;
    }
    *(long *)(param_1 + 0x1a80 + (ulong)param_2 * 8) = lVar1;
    return lVar1;
  }
  if (param_2 == 0) {
    return param_1 + 0x938;
  }
  nvDbg_Printf("src/kernel/gpu/gpu_device_mapping.c",0x48,"_gpuFindDeviceMapping",4,
               "NVRM: Could not find mapping for deviceIndex=%d\n",param_2);
  return 0;
}


// ===== 0034e280 gpuSanityCheck_IMPL =====

int gpuSanityCheck_IMPL(long param_1,uint param_2,uint *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short local_44;
  short local_42;
  long local_40 [2];
  
  local_40[0] = 0;
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  uVar6 = 0;
  if (*(char *)(param_1 + 0x7a0) == '\0') {
    uVar6 = param_2;
  }
  iVar2 = threadStateGetCurrent(local_40,param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((*(uint *)(local_40[0] + 0x3c) & 8) != 0) {
    return 0x56;
  }
  cVar1 = gpuIsGpuFullPower_IMPL(param_1);
  if (cVar1 == '\0') {
    nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x105);
    return 0x11;
  }
  uVar7 = uVar6 & 1;
  if (uVar7 != 0) {
    if ((((*(char *)(param_1 + 0x44f) == '\0') && (*(char *)(param_1 + 0x450) == '\0')) &&
        (*(char *)(param_1 + 0x451) == '\0')) &&
       ((*(char *)(param_1 + 0x461) == '\0' &&
        (iVar2 = regRead032(param_1 + 0x3a18,0,0,0,0), *(int *)(param_1 + 0x8e8) != iVar2)))) {
      nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x115);
    }
    else {
      uVar7 = 0;
    }
  }
  if ((uVar6 & 2) != 0) {
    uVar5 = 0;
    do {
      iVar2 = regRead032(param_1 + 0x3a18,0,0,uVar5 * 4,0);
      if (iVar2 == *(int *)(param_1 + 0x8e8)) {
        if ((0x100001UL >> ((ulong)uVar5 & 0x3f) & 1) == 0) {
          uVar7 = uVar7 | 2;
          nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x11f);
        }
        break;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 0x14);
  }
  if ((uVar6 & 4) == 0) {
LAB_0034e31f:
    if ((uVar6 & 8) != 0) {
LAB_0034e548:
      uVar4 = *(ulong *)(param_1 + 0x878);
      uVar3 = osPciInitHandle(uVar4 >> 0x20,uVar4 >> 8 & 0xff,uVar4 & 0xff,0,&local_44,&local_42);
      uVar4 = osPciReadDword(uVar3,4);
      if ((uVar4 & 2) == 0) {
        nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x131);
        uVar7 = uVar7 | 8;
        if (((uVar6 & 0x10) != 0) && (cVar1 = gpuIsGpuFullPower_IMPL(param_1), cVar1 == '\0')) {
          nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x139);
        }
        goto LAB_0034e503;
      }
    }
    if (((uVar6 & 0x10) != 0) && (cVar1 = gpuIsGpuFullPower_IMPL(param_1), cVar1 == '\0')) {
      nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x139);
    }
    uVar6 = 0;
    iVar2 = 0;
    if (uVar7 == 0) goto LAB_0034e33e;
  }
  else {
    uVar4 = *(ulong *)(param_1 + 0x878);
    osPciInitHandle(uVar4 >> 0x20,uVar4 >> 8 & 0xff,uVar4 & 0xff,0,&local_44,&local_42);
    if ((local_42 != -1) && (local_44 == 0x10de)) goto LAB_0034e31f;
    uVar7 = uVar7 | 4;
    nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x128);
    if ((uVar6 & 8) != 0) goto LAB_0034e548;
    if (((uVar6 & 0x10) != 0) && (cVar1 = gpuIsGpuFullPower_IMPL(param_1), cVar1 == '\0')) {
      nvAssertFailedNoLog(&DAT_00d27634,"src/kernel/gpu/gpu_device_mapping.c",0x139);
    }
  }
LAB_0034e503:
  uVar6 = uVar7;
  iVar2 = 0xffff;
  nvDbg_Printf("src/kernel/gpu/gpu_device_mapping.c",0x140,"gpuSanityCheck_IMPL",4,
               "NVRM: Failed test flags: 0x%x\n",uVar6);
LAB_0034e33e:
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar6;
  }
  return iVar2;
}


// ===== 0034e630 gpuGetRmEngineType_IMPL =====

undefined1 gpuGetRmEngineType_IMPL(uint param_1)

{
  if (0x53 < param_1) {
    nvCheckFailedNoLog(1,"index < NV2080_ENGINE_TYPE_LAST","src/kernel/gpu/gpu_engine_type.c",0x39);
    return 0x54;
  }
  if (0x52 < param_1 - 1) {
    return 0;
  }
  return (&CSWTCH_1)[param_1 - 1];
}


// ===== 0034e680 gpuGetNv2080EngineType_IMPL =====

undefined1 gpuGetNv2080EngineType_IMPL(uint param_1)

{
  if (0x53 < param_1) {
    nvAssertFailedNoLog("index < RM_ENGINE_TYPE_LAST","src/kernel/gpu/gpu_engine_type.c",0xa7);
    return 0x54;
  }
  if (0x3e < param_1 - 1) {
    return 0;
  }
  return CSWTCH_3[param_1 - 1];
}


// ===== 0034e6d0 gpuGetNv2080EngineTypeList_IMPL =====

void gpuGetNv2080EngineTypeList_IMPL(uint *param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (0x53 < param_2) {
    nvAssertFailedNoLog("engineCount < RM_ENGINE_TYPE_LAST","src/kernel/gpu/gpu_engine_type.c",0x103
                       );
    return;
  }
  if (param_2 != 0) {
    puVar1 = param_1 + param_2;
    do {
      if (*param_1 < 0x54) {
        uVar2 = *param_1 - 1;
        uVar3 = 0;
        if (uVar2 < 0x3f) {
          uVar3 = (uint)(byte)CSWTCH_3[uVar2];
        }
      }
      else {
        nvAssertFailedNoLog("index < RM_ENGINE_TYPE_LAST","src/kernel/gpu/gpu_engine_type.c",0xa7);
        uVar3 = 0x54;
      }
      param_1 = param_1 + 1;
      *param_3 = uVar3;
      param_3 = param_3 + 1;
    } while (param_1 != puVar1);
    return;
  }
  return;
}


// ===== 0034e7a0 gpuGetRmEngineTypeCapMask_IMPL =====

undefined8 gpuGetRmEngineTypeCapMask_IMPL(long param_1,int param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 3) {
    if (param_3 == (uint *)0x0) {
      nvAssertFailedNoLog("pRmEngineTypeCap != NULL","src/kernel/gpu/gpu_engine_type.c",0x13b);
    }
    else {
      if (param_1 != 0) {
        param_3[0] = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        uVar2 = 0xffffffff;
        do {
          while( true ) {
            uVar3 = uVar2 + 1;
            if ((*(uint *)(param_1 + (ulong)(uVar3 >> 5) * 4) & 1 << ((byte)uVar3 & 0x1f)) != 0)
            break;
            uVar2 = uVar3;
            if (uVar3 == 0x53) {
              return 0;
            }
          }
          if (uVar2 < 0x53) {
            puVar1 = (uint *)((long)param_3 + (ulong)((byte)(&CSWTCH_1)[uVar2] >> 3 & 0x1c));
            *puVar1 = *puVar1 | 1 << ((&CSWTCH_1)[uVar2] & 0x1f);
          }
          else {
            *param_3 = *param_3 | 1;
          }
          uVar2 = uVar3;
        } while (uVar3 != 0x53);
        return 0;
      }
      nvAssertFailedNoLog("pNV2080EngineTypeCap != NULL","src/kernel/gpu/gpu_engine_type.c",0x13c);
    }
  }
  else {
    nvAssertFailedNoLog("capSize == NVGPU_ENGINE_CAPS_MASK_ARRAY_MAX",
                        "src/kernel/gpu/gpu_engine_type.c",0x13a);
  }
  return 0x1f;
}


// ===== 0034e890 _gpuFabricProbeInvalidate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _gpuFabricProbeInvalidate(long param_1)

{
  uint uVar1;
  uint *puVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  puVar2 = *(uint **)(param_1 + 0x4c0);
  lVar3 = *(long *)(param_1 + 0x1ce8);
  lVar4 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
  LOCK();
  uVar1 = *puVar2;
  *puVar2 = 0;
  uVar5 = (ulong)uVar1;
  UNLOCK();
  if (lVar3 != 0) {
    (**(code **)(lVar3 + 0x180))(param_1,lVar3);
    uVar5 = (**(code **)(lVar3 + 400))(param_1,lVar3);
  }
  if (lVar4 != 0) {
    uVar5 = fabricvaspaceClearUCRange_IMPL(lVar4);
    return uVar5;
  }
  return uVar5;
}


// ===== 0034e920 gpuFabricProbeSuspend.part.0.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuFabricProbeSuspend_part_0_isra_0(long param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "src/kernel/gpu/gpu_fabric_probe.c",0x325);
  }
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x208001f7,0,0);
  if (iVar2 == 0) {
    return;
  }
  nvCheckOkFailedNoLog
            (4,iVar2,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_SUSPEND_FABRIC_PROBE, NULL, 0)"
             ,"src/kernel/gpu/gpu_fabric_probe.c",0x327);
  return;
}


// ===== 0034e9c0 _gpuFabricProbeRbmWakeLinks.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gpuFabricProbeRbmWakeLinks_isra_0(long param_1)

{
  undefined8 uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 local_40;
  undefined1 local_38 [8];
  undefined8 local_30;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1ce8);
  local_30 = 0;
  uVar5 = knvlinkGetEnabledLinkMask_IMPL(param_1,uVar1);
  bitVectorClrAll_IMPL(&local_40,0x40);
  bitVectorCopy_IMPL(local_38,0x40,uVar5,0x40);
  uVar3 = bitVectorCountTrailingZeros_IMPL(local_38,0x40);
  while( true ) {
    cVar2 = bitVectorTestAllCleared_IMPL(local_38,0x40);
    if (cVar2 != '\0') break;
    local_30 = CONCAT44(local_30._4_4_,uVar3);
    iVar4 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x2080300e,&local_30,8);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (1,iVar4,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_NVLINK_GET_POWER_STATE, &powerStatusParams, sizeof(powerStatusParams))"
                 ,"src/kernel/gpu/gpu_fabric_probe.c",0x380);
    }
    if (local_30._4_4_ == 2) {
      bitVectorSet_IMPL(&local_40,0x40,uVar3);
    }
    bitVectorClr_IMPL(local_38,0x40,uVar3);
    uVar3 = bitVectorCountTrailingZeros_IMPL(local_38,0x40);
  }
  cVar2 = bitVectorTestAllCleared_IMPL(&local_40,0x40);
  if (cVar2 == '\0') {
    iVar4 = knvlinkEnterExitSleep_IMPL(param_1,uVar1,&local_40,0);
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x393,"_gpuFabricProbeRbmWakeLinks",4,
                   "NVRM: Error waking links on linkmask 0x%llx\n",local_40);
      return;
    }
  }
  return;
}


// ===== 0034eb60 _gpuFabricProbeFullSanityCheck =====

undefined4 _gpuFabricProbeFullSanityCheck(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  if (param_1 == (int *)0x0) {
    return 0x56;
  }
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    LOCK();
    iVar2 = *param_1;
    bVar4 = iVar1 == iVar2;
    if (bVar4) {
      *param_1 = iVar1;
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar4);
  uVar3 = 0x55;
  if (iVar1 != 0) {
    uVar3 = 0;
    if (*(int *)((long)param_1 + 0x1a) != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x4b,"_gpuFabricProbeFullSanityCheck",4,
                   "NVRM: Fabric Probe failed: 0x%x\n",*(int *)((long)param_1 + 0x1a));
      return *(undefined4 *)((long)param_1 + 0x1a);
    }
  }
  return uVar3;
}


// ===== 0034ebe0 gpuFabricProbeGetGpuFabricHandle =====

int gpuFabricProbeGetGpuFabricHandle(int *param_1,undefined8 *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == (int *)0x0) {
    return 0x56;
  }
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    LOCK();
    iVar2 = *param_1;
    bVar3 = iVar1 == iVar2;
    if (bVar3) {
      *param_1 = iVar1;
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  iVar2 = 0x55;
  if (iVar1 != 0) {
    if (*(int *)((long)param_1 + 0x1a) != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x4b,"_gpuFabricProbeFullSanityCheck",4,
                   "NVRM: Fabric Probe failed: 0x%x\n");
      iVar2 = *(int *)((long)param_1 + 0x1a);
      if (iVar2 == 0) {
        *param_2 = *(undefined8 *)(param_1 + 0xb);
        iVar2 = 0;
      }
      return iVar2;
    }
    *param_2 = *(undefined8 *)(param_1 + 0xb);
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 0034ec80 gpuFabricProbeGetfmCaps =====

int gpuFabricProbeGetfmCaps(int *param_1,undefined8 *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == (int *)0x0) {
    return 0x56;
  }
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    LOCK();
    iVar2 = *param_1;
    bVar3 = iVar1 == iVar2;
    if (bVar3) {
      *param_1 = iVar1;
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  iVar2 = 0x55;
  if (iVar1 != 0) {
    if (*(int *)((long)param_1 + 0x1a) != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x4b,"_gpuFabricProbeFullSanityCheck",4,
                   "NVRM: Fabric Probe failed: 0x%x\n");
      iVar2 = *(int *)((long)param_1 + 0x1a);
      if (iVar2 == 0) {
        *param_2 = *(undefined8 *)(param_1 + 0xe);
        iVar2 = 0;
      }
      return iVar2;
    }
    *param_2 = *(undefined8 *)(param_1 + 0xe);
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 0034ed20 gpuFabricProbeGetClusterUuid =====

int gpuFabricProbeGetClusterUuid(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _gpuFabricProbeFullSanityCheck();
  if (iVar1 == 0) {
    portMemCopy(param_2,0x10,param_1 + 0x40,0x10);
  }
  return iVar1;
}


// ===== 0034ed70 gpuFabricProbeGetFabricPartitionId =====

int gpuFabricProbeGetFabricPartitionId(int *param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == (int *)0x0) {
    return 0x56;
  }
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    LOCK();
    iVar2 = *param_1;
    bVar3 = iVar1 == iVar2;
    if (bVar3) {
      *param_1 = iVar1;
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  iVar2 = 0x55;
  if (iVar1 != 0) {
    if (*(int *)((long)param_1 + 0x1a) != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x4b,"_gpuFabricProbeFullSanityCheck",4,
                   "NVRM: Fabric Probe failed: 0x%x\n");
      iVar2 = *(int *)((long)param_1 + 0x1a);
      if (iVar2 == 0) {
        *param_2 = (short)param_1[0x14];
        iVar2 = 0;
      }
      return iVar2;
    }
    *param_2 = (short)param_1[0x14];
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 0034ee10 gpuFabricProbeGetNumProbeReqs =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuFabricProbeGetNumProbeReqs(long param_1,undefined8 *param_2)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  undefined8 local_20;
  
  local_20 = 0;
  if (param_1 == 0) {
    return 0x56;
  }
  lVar1 = *(long *)(param_1 + 8);
  cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner( gpuGetInstance(pGpuFabricProbeInfoKernel->pGpu))",
                        "src/kernel/gpu/gpu_fabric_probe.c",0x149);
    return 0x2f;
  }
  if (*(char *)(lVar1 + 0x908) != '\0') {
    *param_2 = 1;
    return 0;
  }
  uVar3 = (**(code **)(lVar1 + 0x3b90))
                    (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),*(undefined4 *)(lVar1 + 0x3b3c),
                     0x208001f4,&local_20,8);
  if ((int)uVar3 == 0) {
    *param_2 = local_20;
    return uVar3;
  }
  nvCheckOkFailedNoLog
            (4,uVar3 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_GET_FABRIC_PROBE_INFO, &params, sizeof(params))"
             ,"src/kernel/gpu/gpu_fabric_probe.c",0x158);
  return uVar3 & 0xffffffff;
}


// ===== 0034ef20 gpuFabricProbeGetFabricCliqueId =====

int gpuFabricProbeGetFabricCliqueId(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == (int *)0x0) {
    return 0x56;
  }
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    LOCK();
    iVar2 = *param_1;
    bVar3 = iVar1 == iVar2;
    if (bVar3) {
      *param_1 = iVar1;
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  iVar2 = 0x55;
  if (iVar1 != 0) {
    if (*(int *)((long)param_1 + 0x1a) != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x4b,"_gpuFabricProbeFullSanityCheck",4,
                   "NVRM: Fabric Probe failed: 0x%x\n");
      iVar2 = *(int *)((long)param_1 + 0x1a);
      if (iVar2 == 0) {
        *param_2 = *(undefined4 *)((long)param_1 + 0x76);
        iVar2 = 0;
      }
      return iVar2;
    }
    *param_2 = *(undefined4 *)((long)param_1 + 0x76);
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 0034efc0 gpuFabricProbeGetFabricHealthStatus =====

int gpuFabricProbeGetFabricHealthStatus(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == (int *)0x0) {
    return 0x56;
  }
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    LOCK();
    iVar2 = *param_1;
    bVar3 = iVar1 == iVar2;
    if (bVar3) {
      *param_1 = iVar1;
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  iVar2 = 0x55;
  if (iVar1 != 0) {
    if (*(int *)((long)param_1 + 0x1a) != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x4b,"_gpuFabricProbeFullSanityCheck",4,
                   "NVRM: Fabric Probe failed: 0x%x\n");
      iVar2 = *(int *)((long)param_1 + 0x1a);
      if (iVar2 == 0) {
        *param_2 = *(undefined4 *)((long)param_1 + 0x7a);
        iVar2 = 0;
      }
      return iVar2;
    }
    *param_2 = *(undefined4 *)((long)param_1 + 0x7a);
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 0034f060 gpuFabricProbeIsReceived =====

undefined8 gpuFabricProbeIsReceived(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (param_1 != (uint *)0x0) {
    uVar3 = (ulong)*param_1;
    do {
      uVar2 = (uint)uVar3;
      LOCK();
      uVar1 = *param_1;
      if (uVar2 == uVar1) {
        *param_1 = uVar2;
      }
      else {
        uVar3 = (ulong)uVar1;
      }
      UNLOCK();
    } while (uVar2 != uVar1);
    uVar4 = CONCAT71((int7)(uVar3 >> 8),uVar2 != 0);
  }
  return uVar4;
}


// ===== 0034f080 gpuFabricProbeGetFmStatus =====

undefined4 gpuFabricProbeGetFmStatus(long param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x1a);
  }
  return 0x56;
}


// ===== 0034f0a0 gpuFabricProbeReceiveKernelCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuFabricProbeReceiveKernelCallback(undefined4 param_1,undefined8 param_2,long param_3)

{
  undefined4 *puVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined1 local_4c [4];
  uint local_48;
  uint local_44;
  undefined8 local_40 [2];
  
  lVar6 = gpumgrGetGpu();
  if (lVar6 == 0) {
    nvAssertFailedNoLog("Invalid GPU instance","src/kernel/gpu/gpu_fabric_probe.c",0x269);
    return 0x1f;
  }
  if (*(long *)(lVar6 + 0x4c0) == 0) {
    nvCheckFailedNoLog(4,"pGpu->pGpuFabricProbeInfoKernel != NULL",
                       "src/kernel/gpu/gpu_fabric_probe.c",0x276);
    return 0;
  }
  cVar4 = rmGpuGroupLockIsOwner(param_1,0,local_4c);
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmGpuGroupLockIsOwner(gpuInstance, GPU_LOCK_GRP_SUBDEVICE, &gpuMaskUnused)"
                        ,"src/kernel/gpu/gpu_fabric_probe.c",0x278);
  }
  if (param_3 == 0) {
    nvAssertFailedNoLog("pInbandRcvParams != NULL","src/kernel/gpu/gpu_fabric_probe.c",0x27b);
  }
  puVar1 = *(undefined4 **)(lVar6 + 0x4c0);
  portMemCopy(puVar1 + 4,0x82,param_3,0x82);
  LOCK();
  UNLOCK();
  LOCK();
  *puVar1 = 1;
  UNLOCK();
  iVar5 = _gpuFabricProbeFullSanityCheck(puVar1);
  if (iVar5 != 0) {
    nvCheckFailedNoLog(1,"status == NV_OK","src/kernel/gpu/gpu_fabric_probe.c",0x28f);
    return iVar5;
  }
  lVar2 = *(long *)(lVar6 + 0x1ce8);
  if (lVar2 == 0) {
    if (*(long *)(lVar6 + 0x4a18) != 0) goto LAB_0034f1c1;
LAB_0034f2be:
    if ((*(uint *)(param_3 + 0x6a) & 0xf00) != 0x800) {
      return 0;
    }
  }
  else {
    iVar5 = _gpuFabricProbeFullSanityCheck(puVar1);
    if (iVar5 == 0) {
      uVar8 = *(undefined8 *)((long)puVar1 + 0x52);
      iVar5 = _gpuFabricProbeFullSanityCheck(puVar1);
      if (iVar5 == 0) {
        iVar5 = (**(code **)(lVar2 + 0x178))(lVar6,lVar2,uVar8);
        if (iVar5 == 0) {
          iVar5 = _gpuFabricProbeFullSanityCheck(puVar1);
          if (iVar5 == 0) {
            if ((*(byte *)(puVar1 + 0xe) & 0x40) != 0) {
              iVar5 = _gpuFabricProbeFullSanityCheck(puVar1);
              if (iVar5 == 0) {
                iVar5 = (**(code **)(lVar2 + 0x188))
                                  (lVar6,lVar2,(ulong)*(uint *)((long)puVar1 + 0x7e) << 0x20);
                if (iVar5 != 0) {
                  nvCheckFailedNoLog(4,
                                     "knvlinkSetUniqueFabricEgmBaseAddress_HAL(pGpu, pKernelNvlink, egmGpaAddress) == NV_OK"
                                     ,"src/kernel/gpu/gpu_fabric_probe.c",0x1e1);
                }
              }
              else {
                nvCheckFailedNoLog(4,
                                   "gpuFabricProbeGetEgmGpaAddress(pGpuFabricProbeInfoKernel, &egmGpaAddress) == NV_OK"
                                   ,"src/kernel/gpu/gpu_fabric_probe.c",0x1dd);
              }
            }
          }
          else {
            nvCheckFailedNoLog(4,
                               "gpuFabricProbeGetfmCaps(pGpuFabricProbeInfoKernel, &fmCaps) == NV_OK"
                               ,"src/kernel/gpu/gpu_fabric_probe.c",0x1d7);
          }
        }
        else {
          nvCheckFailedNoLog(4,
                             "knvlinkSetUniqueFabricBaseAddress_HAL(pGpu, pKernelNvlink, gpaAddress) == NV_OK"
                             ,"src/kernel/gpu/gpu_fabric_probe.c",0x1d3);
        }
      }
      else {
        nvCheckFailedNoLog(4,
                           "gpuFabricProbeGetGpaAddressRange(pGpuFabricProbeInfoKernel, &gpaAddressSize) == NV_OK"
                           ,"src/kernel/gpu/gpu_fabric_probe.c",0x1cf);
      }
    }
    else {
      nvCheckFailedNoLog(4,
                         "gpuFabricProbeGetGpaAddress(pGpuFabricProbeInfoKernel, &gpaAddress) == NV_OK"
                         ,"src/kernel/gpu/gpu_fabric_probe.c",0x1cb);
    }
    if (*(long *)(lVar6 + 0x4a18) != 0) {
LAB_0034f1c1:
      iVar5 = _gpuFabricProbeFullSanityCheck(puVar1);
      if (iVar5 == 0) {
        uVar8 = *(undefined8 *)((long)puVar1 + 0x62);
        iVar5 = _gpuFabricProbeFullSanityCheck(puVar1);
        if (iVar5 == 0) {
          uVar3 = *(undefined8 *)((long)puVar1 + 0x6a);
          if (*(char *)(lVar6 + 0x908) != '\0') {
            uVar7 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 0x4a18),
                                       __nvoc_class_def_FABRIC_VASPACE);
            fabricvaspaceClearUCRange_IMPL(uVar7);
          }
          uVar7 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE
                                    );
          iVar5 = fabricvaspaceInitUCRange_IMPL(uVar7,lVar6,uVar8,uVar3);
          if (iVar5 != 0) {
            nvCheckFailedNoLog(4,
                               "fabricvaspaceInitUCRange(dynamicCast(pGpu->pFabricVAS, FABRIC_VASPACE), pGpu, flaBaseAddress, flaSize) == NV_OK"
                               ,"src/kernel/gpu/gpu_fabric_probe.c",0x201);
          }
        }
        else {
          nvCheckFailedNoLog(4,
                             "gpuFabricProbeGetFlaAddressRange(pGpuFabricProbeInfoKernel, &flaSize) == NV_OK"
                             ,"src/kernel/gpu/gpu_fabric_probe.c",0x1f8);
        }
      }
      else {
        nvCheckFailedNoLog(4,
                           "gpuFabricProbeGetFlaAddress(pGpuFabricProbeInfoKernel, &flaBaseAddress) == NV_OK"
                           ,"src/kernel/gpu/gpu_fabric_probe.c",500);
      }
    }
    if (*(long *)(lVar6 + 0x1ce8) == 0) goto LAB_0034f2be;
    if (*(byte *)((long)puVar1 + 0x82) < 0x25) {
      *(ushort *)(*(long *)(lVar6 + 0x1ce8) + 0x16d0) = (ushort)*(byte *)((long)puVar1 + 0x82);
    }
    else {
      nvAssertFailedNoLog("maxRbmLinks <= NVLINK_MAX_LINKS_SW","src/kernel/gpu/gpu_fabric_probe.c",
                          0x22b);
    }
    if ((*(uint *)(param_3 + 0x6a) & 0xf00) != 0x800) goto LAB_0034f274;
  }
  *(undefined1 *)(lVar6 + 0x4b9) = 1;
  (**(code **)(lVar6 + 0x128))(lVar6);
  *(undefined1 *)(lVar6 + 0x4b9) = 0;
LAB_0034f274:
  lVar2 = *(long *)(lVar6 + 0x1ce8);
  if (((lVar2 != 0) && (*(char *)(lVar2 + 0x2f4) != '\0')) &&
     (((*(ushort *)(puVar1 + 1) & 7) == 5 ||
      ((*(char *)(lVar2 + 0x171b) != '\0' && ((*(byte *)(puVar1 + 0xe) & 0x20) != 0)))))) {
    uVar8 = knvlinkGetEnabledLinkMask_IMPL(lVar6,lVar2);
    iVar5 = convertBitVectorToLinkMasks(uVar8,&local_48,4,0);
    uVar8 = 0x248;
    pcVar9 = 
    "convertBitVectorToLinkMasks(pEnabledLinksVec, &enabledLinkMask, sizeof(enabledLinkMask), NULL)"
    ;
    if (iVar5 == 0) {
      local_44 = *(uint *)((long)puVar1 + 0x72) & local_48;
      iVar5 = convertLinkMasksToBitVector(&local_44,4,0,local_40,0x248);
      if (iVar5 == 0) {
        iVar5 = knvlinkEnterExitSleep_IMPL(lVar6,lVar2,local_40,1);
        if (iVar5 == 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x253,"_gpuFabricProbeRbmSleepLinks",4,
                     "NVRM: Error setting links to sleep on linkmask 0x%llx\n",local_40[0]);
        return 0;
      }
      uVar8 = 0x24d;
      pcVar9 = "convertLinkMasksToBitVector(&linkMask, sizeof(linkMask), NULL, &sleepLinkVec)";
    }
    nvCheckOkFailedNoLog(4,iVar5,pcVar9,"src/kernel/gpu/gpu_fabric_probe.c",uVar8);
  }
  return 0;
}


// ===== 0034f670 gpuFabricProbeReceiveUpdateKernelCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuFabricProbeReceiveUpdateKernelCallback(undefined4 param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  undefined1 local_94 [4];
  uint local_90 [2];
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78;
  
  lVar8 = gpumgrGetGpu();
  if (lVar8 == 0) {
    iVar6 = 0x1f;
    nvAssertFailedNoLog("Invalid GPU instance","src/kernel/gpu/gpu_fabric_probe.c",0x2d4);
  }
  else if (*(long *)(lVar8 + 0x4c0) == 0) {
    iVar6 = 0;
    nvCheckFailedNoLog(4,"pGpu->pGpuFabricProbeInfoKernel != NULL",
                       "src/kernel/gpu/gpu_fabric_probe.c",0x2da);
  }
  else {
    lVar2 = *(long *)(lVar8 + 0x1ce8);
    cVar1 = *(char *)(lVar2 + 0x171b);
    cVar5 = rmGpuGroupLockIsOwner(param_1,0,local_94);
    if (cVar5 == '\0') {
      nvAssertFailedNoLog("rmGpuGroupLockIsOwner(gpuInstance, GPU_LOCK_GRP_SUBDEVICE, &gpuMaskUnused)"
                          ,"src/kernel/gpu/gpu_fabric_probe.c",0x2dc);
    }
    if (param_3 == 0) {
      nvAssertFailedNoLog("pInbandRcvParams != NULL","src/kernel/gpu/gpu_fabric_probe.c",0x2df);
    }
    lVar3 = *(long *)(lVar8 + 0x4c0);
    iVar6 = _gpuFabricProbeFullSanityCheck(lVar3);
    if (iVar6 == 0) {
      *(undefined4 *)(lVar3 + 0x7a) = *(undefined4 *)(param_3 + 0x28);
      lVar4 = g_pSys;
      iVar7 = *(int *)(param_3 + 0x24);
      if (*(int *)(lVar3 + 0x76) != iVar7) {
        *(int *)(lVar3 + 0x76) = iVar7;
        uVar9 = *(undefined8 *)(lVar4 + 0x260);
        local_88 = fabricGenerateEventId_IMPL();
        local_90[0] = CONCAT31(local_90[0]._1_3_,3);
        local_80 = 0;
        local_78 = CONCAT44(iVar7,*(undefined4 *)(lVar8 + 0x7ac));
        iVar7 = fabricPostEventsV2_IMPL(uVar9,local_90,1);
        if (iVar7 != 0) {
          nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x219,
                       "_gpuFabricProbeSendCliqueIdChangeEvent",4,
                       "NVRM: GPU%u Notifying cliqueId change failed\n",
                       *(undefined4 *)(lVar8 + 0x7a4));
        }
      }
      if (*(char *)(param_3 + 0x30) == '\x01') {
        (**(code **)(lVar2 + 0x278))(lVar8,lVar2);
      }
      if ((*(uint *)(lVar3 + 0x7a) & 0xf00) == 0x800) {
        *(undefined1 *)(lVar8 + 0x4b9) = 1;
        (**(code **)(lVar8 + 0x128))(lVar8);
        *(undefined1 *)(lVar8 + 0x4b9) = 0;
      }
      if (cVar1 != '\0') {
        uVar9 = knvlinkGetEnabledLinkMask_IMPL(lVar8,lVar2);
        iVar6 = convertBitVectorToLinkMasks(uVar9,local_90,4,0);
        if (iVar6 == 0) {
          *(uint *)(lVar3 + 0x72) = ~*(uint *)(param_3 + 0x31) & local_90[0];
          lVar2 = *(long *)(lVar8 + 0x1ce8);
          if ((lVar2 != 0) && ((byte)(*(char *)(param_3 + 0x30) - 2U) < 2)) {
            (**(code **)(lVar2 + 0x290))(lVar8,lVar2,*(char *)(param_3 + 0x30) == '\x03');
            return 0;
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,iVar6,
                     "convertBitVectorToLinkMasks(pEnabledLinksVec, &enabledLinkMask, sizeof(enabledLinkMask), NULL)"
                     ,"src/kernel/gpu/gpu_fabric_probe.c",0x306);
        }
      }
    }
    else {
      nvCheckFailedNoLog(4,"status == NV_OK","src/kernel/gpu/gpu_fabric_probe.c",0x2e4);
    }
  }
  return iVar6;
}


// ===== 0034f9c0 gpuFabricProbeSuspend =====

void gpuFabricProbeSuspend(long param_1)

{
  if (param_1 != 0) {
    gpuFabricProbeSuspend_part_0_isra_0(*(undefined8 *)(param_1 + 8));
    return;
  }
  return;
}


// ===== 0034f9e0 gpuFabricProbeInvalidate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuFabricProbeInvalidate(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(param_1 + 8);
    cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
    if (cVar2 == '\0') {
      nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                          "src/kernel/gpu/gpu_fabric_probe.c",0x341);
    }
    iVar3 = (**(code **)(lVar1 + 0x3b90))
                      (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                       *(undefined4 *)(lVar1 + 0x3b3c),0x208001f9,0,0);
    if (iVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar3,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_INVALIDATE_FABRIC_PROBE, NULL, 0)"
                 ,"src/kernel/gpu/gpu_fabric_probe.c",0x343);
    }
    _gpuFabricProbeInvalidate(lVar1);
    return;
  }
  return;
}


// ===== 0034faa0 gpuFabricProbeResume =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuFabricProbeResume(long param_1)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  undefined2 local_2a [5];
  
  local_2a[0] = 0;
  if (param_1 == 0) {
    return 0x56;
  }
  lVar1 = *(long *)(param_1 + 8);
  cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "src/kernel/gpu/gpu_fabric_probe.c",0x35f);
  }
  local_2a[0] = *(undefined2 *)(param_1 + 4);
  uVar3 = (**(code **)(lVar1 + 0x3b90))
                    (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),*(undefined4 *)(lVar1 + 0x3b3c),
                     0x208001f8,local_2a,2);
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  nvCheckOkFailedNoLog
            (4,uVar3 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_RESUME_FABRIC_PROBE, &params, sizeof(params))"
             ,"src/kernel/gpu/gpu_fabric_probe.c",0x363);
  return uVar3 & 0xffffffff;
}


// ===== 0034fb80 gpuFabricProbeStart =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuFabricProbeStart(long param_1,long *param_2)

{
  byte bVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  undefined2 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined4 local_64;
  undefined1 local_60 [4];
  undefined4 local_5c;
  undefined1 local_58 [40];
  
  lVar8 = *(long *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_1 + 0x1ce8);
  local_5c = 0;
  lVar3 = *(long *)(g_pSys + 0x1e0);
  local_64 = 0x20;
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "src/kernel/gpu/gpu_fabric_probe.c",0x3ac);
    return 0x2f;
  }
  if (*(char *)(param_1 + 0x4a4c) == '\0') {
    nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x42c,"gpuFabricProbeIsSupported",1,
                 "NVRM: GPU%u Probe handling is disabled\n",*(undefined4 *)(param_1 + 0x7a4));
    return 0;
  }
  if ((*(char *)(param_1 + 0x908) == '\0') && (*(long *)(param_1 + 0x1ce8) == 0)) {
    return 0;
  }
  lVar7 = portMemAllocNonPaged(0x98);
  *param_2 = lVar7;
  if (lVar7 == 0) {
    nvAssertFailedNoLog("*ppGpuFabricProbeInfoKernel != NULL","src/kernel/gpu/gpu_fabric_probe.c",
                        0x3b7);
    return 0x51;
  }
  portMemSet(lVar7,0,0x98);
  *(long *)(lVar7 + 8) = param_1;
  local_5c._0_3_ = CONCAT12(*(undefined1 *)(lVar8 + 0x454),(undefined2)local_5c);
  if (*(char *)(lVar3 + 0x444a) == '\x02') {
    if (lVar2 == 0) {
      local_5c = CONCAT22(local_5c._2_2_,*(undefined2 *)(lVar7 + 4));
      goto LAB_0034fc98;
    }
    bVar1 = *(byte *)(lVar2 + 0x16c0);
    *(ushort *)(lVar7 + 4) = (ushort)bVar1;
    local_5c = CONCAT22(local_5c._2_2_,(ushort)bVar1);
  }
  else {
    uVar5 = gpumgrGetGpuNvlinkBwMode_IMPL();
    *(undefined2 *)(lVar7 + 4) = uVar5;
    local_5c = CONCAT22(local_5c._2_2_,uVar5);
    if (lVar2 == 0) goto LAB_0034fc98;
  }
  iVar6 = osReadRegistryDword(param_1,"RmNvlinkBandwidthLinkCount",local_60);
  if (((iVar6 == 0) ||
      ((iVar6 = osReadRegistryString(param_1,"RmNvlinkBandwidth",local_58,&local_64), iVar6 == 0 &&
       ((local_5c & 7) == 0)))) && (*(char *)(lVar2 + 0x2f4) != '\0')) {
    _gpuFabricProbeRbmWakeLinks_isra_0(param_1);
  }
LAB_0034fc98:
  if (*(char *)(param_1 + 0x908) == '\0') {
    iVar6 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x208001f5,&local_5c,4);
    if (iVar6 == 0) {
      return 0;
    }
    nvCheckOkFailedNoLog
              (4,iVar6,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_START_FABRIC_PROBE, &params, sizeof(params))"
               ,"src/kernel/gpu/gpu_fabric_probe.c",0x3e9);
  }
  else {
    lVar8 = gpuGetRpc(param_1);
    if (lVar8 == 0) {
      iVar6 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gpu_fabric_probe.c",0x3de);
    }
    else {
      if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
        iVar6 = rpcDmaControl_wrapper(param_1,lVar8,0,0,0x208001f5,&local_5c,4);
      }
      else {
        iVar6 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,0,0,0x208001f5,&local_5c,4);
      }
      if (iVar6 == 0) {
        return 0;
      }
    }
  }
  portMemFree(lVar7);
  *(undefined8 *)(param_1 + 0x4c0) = 0;
  return iVar6;
}


// ===== 0034ff00 gpuFabricProbeStop =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuFabricProbeStop(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return;
  }
  lVar1 = *(long *)(param_1 + 8);
  cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar2 != '\0') {
    if (*(char *)(lVar1 + 0x908) == '\0') {
      iVar3 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                         *(undefined4 *)(lVar1 + 0x3b3c),0x208001f6,0,0);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_STOP_FABRIC_PROBE, NULL, 0)"
                   ,"src/kernel/gpu/gpu_fabric_probe.c",0x419);
      }
    }
    portMemFree(param_1);
    *(undefined8 *)(lVar1 + 0x4c0) = 0;
    return;
  }
  nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                      "src/kernel/gpu/gpu_fabric_probe.c",0x40b);
  return;
}


// ===== 0034ffc0 gpuFabricProbeIsSupported =====

bool gpuFabricProbeIsSupported(long param_1)

{
  bool bVar1;
  
  if (*(char *)(param_1 + 0x4a4c) != '\0') {
    bVar1 = true;
    if (*(char *)(param_1 + 0x908) == '\0') {
      bVar1 = *(long *)(param_1 + 0x1ce8) != 0;
    }
    return bVar1;
  }
  nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x42c,"gpuFabricProbeIsSupported",1,
               "NVRM: GPU%u Probe handling is disabled\n",*(undefined4 *)(param_1 + 0x7a4));
  return false;
}


// ===== 00350030 gpuFabricProbeSetBwModePerGpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuFabricProbeSetBwModePerGpu(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  lVar1 = *(long *)(param_1 + 0x4c0);
  lVar2 = *(long *)(param_1 + 0x1ce8);
  *(short *)(lVar1 + 4) = (short)param_2;
  gpuFabricProbeSuspend_part_0_isra_0(*(undefined8 *)(lVar1 + 8));
  uVar3 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x208001f9,0,0);
  uVar5 = 0x451;
  pcVar4 = 
  "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_INVALIDATE_FABRIC_PROBE, NULL, 0)"
  ;
  if ((int)uVar3 == 0) {
    _gpuFabricProbeInvalidate(param_1);
    if (((0x21UL >> (param_2 & 7) & 1) != 0) && (*(char *)(lVar2 + 0x2f4) != '\0')) {
      _gpuFabricProbeRbmWakeLinks_isra_0(param_1);
      LOCK();
      *(char *)(lVar2 + 0x16c0) = (char)param_2;
      UNLOCK();
    }
    uVar3 = gpuFabricProbeResume(lVar1);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    uVar5 = 0x465;
    pcVar4 = "gpuFabricProbeResume(pGpuFabricProbeInfoKernel)";
  }
  nvCheckOkFailedNoLog(4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/gpu_fabric_probe.c",uVar5);
  return uVar3 & 0xffffffff;
}


// ===== 00350140 gpuFabricProbeSetBwMode =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int gpuFabricProbeSetBwMode(ushort param_1)

{
  int *piVar1;
  ulong uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  bool bVar7;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar4 = gpumgrGetGpuAttachInfo(local_24,&local_20);
  if (iVar4 != 0) {
    return 0x40;
  }
  local_1c = 0;
  while (lVar6 = gpumgrGetNextGpu(local_20,&local_1c), lVar6 != 0) {
    if (*(char *)(lVar6 + 0x4a4c) == '\0') {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x42c,"gpuFabricProbeIsSupported",1,
                   "NVRM: GPU%u Probe handling is disabled\n",*(undefined4 *)(lVar6 + 0x7a4));
      return 0;
    }
    if ((*(char *)(lVar6 + 0x908) == '\0') && (*(long *)(lVar6 + 0x1ce8) == 0)) {
      return 0;
    }
  }
  local_1c = 0;
LAB_00350207:
  do {
    do {
      lVar6 = gpumgrGetNextGpu(local_20,&local_1c);
      if (lVar6 == 0) {
        local_1c = 0;
        do {
          lVar6 = gpumgrGetNextGpu(local_20,&local_1c);
          if (lVar6 == 0) {
            local_1c = 0;
            lVar6 = gpumgrGetNextGpu(local_20,&local_1c);
            while( true ) {
              if (lVar6 == 0) {
                return 0;
              }
              iVar4 = gpuFabricProbeSetBwModePerGpu(lVar6,param_1);
              if (iVar4 != 0) break;
              lVar6 = gpumgrGetNextGpu(local_20,&local_1c);
            }
            return iVar4;
          }
          lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE
                                    );
        } while ((lVar6 == 0) || (cVar3 = fabricvaspaceIsInUse_IMPL(lVar6), cVar3 == '\0'));
        return 99;
      }
      piVar1 = *(int **)(lVar6 + 0x4c0);
      if (piVar1 == (int *)0x0) {
        return 0x55;
      }
      iVar4 = *piVar1;
      do {
        iVar5 = iVar4;
        LOCK();
        iVar4 = *piVar1;
        bVar7 = iVar5 == iVar4;
        if (bVar7) {
          *piVar1 = iVar5;
          iVar4 = iVar5;
        }
        UNLOCK();
      } while (!bVar7);
      if (iVar5 == 0) {
        return 0x55;
      }
      if (*(long *)(lVar6 + 0x4c0) == 0) {
        return 0x55;
      }
      if (*(int *)(*(long *)(lVar6 + 0x4c0) + 0x1a) != 0) {
        return 0x55;
      }
      cVar3 = (**(code **)(*(long *)(lVar6 + 0x1ce8) + 0x260))
                        (lVar6,*(long *)(lVar6 + 0x1ce8),param_1);
      if (cVar3 == '\0') {
        return 0x56;
      }
    } while ((param_1 & 7) == 5);
    uVar2 = *(ulong *)(*(long *)(lVar6 + 0x4c0) + 0x38);
    if (param_1 == 3) {
      uVar2 = uVar2 & 8;
    }
    else if (param_1 < 4) {
      if (param_1 == 1) {
        return 0;
      }
      if (param_1 != 2) goto LAB_00350207;
      uVar2 = uVar2 & 4;
    }
    else {
      if (param_1 != 4) goto LAB_00350207;
      uVar2 = uVar2 & 0x10;
    }
    if (uVar2 == 0) {
      return 0x56;
    }
  } while( true );
}


// ===== 003503a0 gpuFabricProbeGetlinkMaskToBeReduced =====

int gpuFabricProbeGetlinkMaskToBeReduced(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == (int *)0x0) {
    return 0x56;
  }
  iVar2 = *param_1;
  do {
    iVar1 = iVar2;
    LOCK();
    iVar2 = *param_1;
    bVar3 = iVar1 == iVar2;
    if (bVar3) {
      *param_1 = iVar1;
      iVar2 = iVar1;
    }
    UNLOCK();
  } while (!bVar3);
  iVar2 = 0x55;
  if (iVar1 != 0) {
    if (*(int *)((long)param_1 + 0x1a) != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_fabric_probe.c",0x4b,"_gpuFabricProbeFullSanityCheck",4,
                   "NVRM: Fabric Probe failed: 0x%x\n");
      iVar2 = *(int *)((long)param_1 + 0x1a);
      if (iVar2 == 0) {
        *param_2 = *(undefined4 *)((long)param_1 + 0x72);
        iVar2 = 0;
      }
      return iVar2;
    }
    *param_2 = *(undefined4 *)((long)param_1 + 0x72);
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 00350440 gpuIsInternalSku_FWCLIENT =====

undefined1 gpuIsInternalSku_FWCLIENT(void)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  return *(undefined1 *)(lVar1 + 0x5c8);
}


// ===== 00350460 gpuInitSriov_FWCLIENT =====

undefined8 gpuInitSriov_FWCLIENT(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = gpuGetGspStaticInfo();
  *(undefined8 *)(&DAT_00003a70 + param_1) = *(undefined8 *)(lVar3 + 0x500);
  *(undefined8 *)(param_1 + 0x3a78) = *(undefined8 *)(lVar3 + 0x508);
  *(undefined8 *)(param_1 + 0x3a80) = *(undefined8 *)(lVar3 + 0x510);
  uVar2 = *(undefined4 *)(lVar3 + 0x528);
  *(undefined8 *)(param_1 + 0x3af8) = 0;
  *(undefined4 *)(param_1 + 0x3a60) = uVar2;
  *(undefined1 *)(param_1 + 0x3b00) = 0;
  *(undefined4 *)(param_1 + 0x3b04) = 0;
  iVar1 = *(int *)(param_1 + 0x3a58) + 1;
  lVar3 = portMemAllocNonPaged(iVar1);
  *(long *)(param_1 + 0x3a68) = lVar3;
  if (lVar3 != 0) {
    portMemSet(lVar3,0,iVar1);
    *(undefined4 *)(param_1 + 0x3a60) = *(undefined4 *)(param_1 + 0x3a58);
    gpuSetGfidUsage_IMPL(param_1,0,1);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/gpu_gspclient.c",0x55,"gpuInitSriov_FWCLIENT",4,
               "NVRM: Memory allocation failed for GFID tracking\n");
  return 0x51;
}


// ===== 00350550 gpuDeinitSriov_FWCLIENT =====

undefined8 gpuDeinitSriov_FWCLIENT(long param_1)

{
  if (*(long *)(param_1 + 0x3a68) != 0) {
    gpuSetGfidUsage_IMPL(param_1,0,0);
    portMemFree(*(undefined8 *)(param_1 + 0x3a68));
    *(undefined8 *)(param_1 + 0x3a68) = 0;
    return 0;
  }
  return 0;
}


// ===== 003505a0 gpuCheckPageRetirementSupport_GSPCLIENT =====

undefined1 gpuCheckPageRetirementSupport_GSPCLIENT(void)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  return *(undefined1 *)(lVar1 + 0x5fc);
}


// ===== 003505c0 gpuInitBranding_FWCLIENT =====

undefined8 gpuInitBranding_FWCLIENT(long param_1)

{
  char cVar1;
  char cVar2;
  long lVar3;
  bool bVar4;
  bool bVar5;
  
  lVar3 = gpuGetGspStaticInfo();
  if (*(char *)(lVar3 + 0x5ca) == '\0') {
    bVar5 = *(char *)(lVar3 + 0x5c9) == '\0';
    bVar4 = !bVar5;
  }
  else {
    bVar5 = false;
    bVar4 = true;
  }
  *(bool *)(param_1 + 0x4a2a) = bVar4;
  *(undefined1 *)(param_1 + 0x4a2b) = *(undefined1 *)(lVar3 + 0x5ca);
  cVar1 = *(char *)(lVar3 + 0x5cb);
  *(char *)(param_1 + 0x4a2d) = cVar1;
  *(undefined1 *)(param_1 + 0x4a2c) = *(undefined1 *)(lVar3 + 0x5cc);
  *(undefined1 *)(param_1 + 0x4a28) = *(undefined1 *)(lVar3 + 0x5cd);
  *(undefined1 *)(param_1 + 0x4a2e) = *(undefined1 *)(lVar3 + 0x5ce);
  cVar2 = *(char *)(lVar3 + 0x5cf);
  *(char *)(param_1 + 0x4a2f) = cVar2;
  *(char *)(param_1 + 0x4a29) = (cVar1 == '\0' && cVar2 == '\0') & bVar5;
  return 0;
}


// ===== 00350670 gpuGetPdi_FWCLIENT =====

undefined8 gpuGetPdi_FWCLIENT(long param_1,undefined8 *param_2)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  if (*(char *)(lVar1 + 0x4c8) == '\0') {
    if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
      return 0x40;
    }
    *param_2 = 0x6dbb0ab8a7c66ad2;
  }
  else {
    *param_2 = *(undefined8 *)(lVar1 + 0x4d0);
  }
  return 0;
}


// ===== 003506d0 gpuGenGidData_FWCLIENT =====

uint gpuGenGidData_FWCLIENT(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_38;
  undefined8 local_30;
  
  if ((param_4 & 4) != 0) {
    return 0x56;
  }
  lVar2 = gpuGetGspStaticInfo();
  local_38 = 0;
  local_30 = 0;
  iVar1 = portMemCmp(lVar2 + 0xc,&local_38,0x10);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_gspclient.c",0xb8,"gpuGenGidData_FWCLIENT",1,
                 "NVRM: GSP Static Info has not been initialized yet for UUID\n");
    return 0x40;
  }
  portMemCopy(param_2,0x10,lVar2 + 0xc,0x10);
  return param_4 & 4;
}


// ===== 003507a0 gpuIsGlobalPoisonFuseEnabled_FWCLIENT =====

undefined1 gpuIsGlobalPoisonFuseEnabled_FWCLIENT(void)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  if (lVar1 != 0) {
    return *(undefined1 *)(lVar1 + 0x538);
  }
  nvAssertFailedNoLog("pGSCI != NULL","src/kernel/gpu/gpu_gspclient.c",0xc5);
  return 0;
}


// ===== 003507e0 gpuGetRtd3GC6Data_FWCLIENT =====

void gpuGetRtd3GC6Data_FWCLIENT(long param_1)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  if (lVar1 != 0) {
    *(undefined2 *)(param_1 + 0x4b30) = *(undefined2 *)(lVar1 + 0x5d8);
    *(undefined2 *)(param_1 + 0x4b32) = *(undefined2 *)(lVar1 + 0x5d6);
    return;
  }
  nvAssertFailedNoLog("pGSCI != NULL","src/kernel/gpu/gpu_gspclient.c",0xce);
  return;
}


// ===== 00350840 gpuConstructDeviceInfoTable_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuConstructDeviceInfoTable_FWCLIENT(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  uint *puVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  
  if (*(long *)(param_1 + 0x3b28) != 0) {
    return 0;
  }
  puVar7 = (uint *)portMemAllocNonPaged(0x6004);
  if (puVar7 == (uint *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gpu_gspclient.c",0xef);
    iVar6 = 0x51;
  }
  else {
    iVar6 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a40,puVar7,0x6004);
    if ((iVar6 == 0) && (*puVar7 != 0)) {
      if (0x200 < *puVar7) {
        nvAssertFailedNoLog("pParams->numEntries <= NV2080_CTRL_CMD_INTERNAL_DEVICE_INFO_MAX_ENTRIES"
                            ,"src/kernel/gpu/gpu_gspclient.c",0xfd);
        return 0x40;
      }
      lVar8 = portMemAllocNonPaged();
      *(long *)(param_1 + 0x3b28) = lVar8;
      if (lVar8 == 0) {
        nvAssertOkFailedNoLog
                  (0x51,"pGpu->pDeviceInfoTable != NULL","src/kernel/gpu/gpu_gspclient.c",0x102);
        iVar6 = 0x51;
      }
      else {
        uVar9 = *puVar7;
        uVar10 = 0;
        lVar11 = 0;
        *(uint *)(param_1 + 0x3b30) = uVar9;
        if (uVar9 != 0) {
          while( true ) {
            uVar9 = (int)uVar10 + 1;
            uVar1 = *(undefined8 *)(puVar7 + uVar10 * 0xc + 3);
            uVar2 = *(undefined8 *)(puVar7 + uVar10 * 0xc + 5);
            uVar3 = *(undefined8 *)(puVar7 + uVar10 * 0xc + 7);
            uVar4 = *(undefined8 *)(puVar7 + uVar10 * 0xc + 9);
            uVar5 = *(undefined8 *)(puVar7 + uVar10 * 0xc + 0xb);
            *(undefined8 *)(lVar8 + lVar11) = *(undefined8 *)(puVar7 + uVar10 * 0xc + 1);
            *(undefined8 *)(lVar8 + 8 + lVar11) = uVar1;
            *(undefined8 *)(lVar8 + 0x10 + lVar11) = uVar2;
            *(undefined8 *)(lVar8 + 0x18 + lVar11) = uVar3;
            *(undefined8 *)(lVar8 + 0x20 + lVar11) = uVar4;
            *(undefined8 *)(lVar8 + 0x28 + lVar11) = uVar5;
            if (*puVar7 <= uVar9) break;
            lVar8 = *(long *)(param_1 + 0x3b28);
            lVar11 = lVar11 + 0x30;
            uVar10 = (ulong)uVar9;
          }
        }
      }
    }
    portMemFree(puVar7);
  }
  return iVar6;
}


// ===== 00350a00 gpuGetNameString_FWCLIENT =====

undefined8 gpuGetNameString_FWCLIENT(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  portMemCopy(param_2,0x40,lVar1 + 0x548,0x40);
  return 0;
}


// ===== 00350a40 gpuGetShortNameString_FWCLIENT =====

undefined8 gpuGetShortNameString_FWCLIENT(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  portMemCopy(param_2,0x40,lVar1 + 0x588,0x40);
  return 0;
}


// ===== 00350a80 gpuGetRegBaseOffset_FWCLIENT =====

undefined8 gpuGetRegBaseOffset_FWCLIENT(long param_1,uint param_2,int *param_3)

{
  int iVar1;
  
  if (*(long *)(param_1 + 0x3c58) == 0) {
    nvAssertFailedNoLog("pChipInfo != NULL","src/kernel/gpu/gpu_gspclient.c",0x146);
    return 0x40;
  }
  if (param_2 < 0x10) {
    iVar1 = *(int *)(*(long *)(param_1 + 0x3c58) + 0x18 + (ulong)param_2 * 4);
    if (iVar1 != -1) {
      *param_3 = iVar1;
      return 0;
    }
  }
  else {
    nvAssertFailedNoLog("regBase < NV_ARRAY_ELEMENTS(pChipInfo->regBases)",
                        "src/kernel/gpu/gpu_gspclient.c",0x147);
  }
  return 0x56;
}


// ===== 00350af0 gpuGetChipSubRev_FWCLIENT =====

undefined1 gpuGetChipSubRev_FWCLIENT(long param_1)

{
  if (*(undefined1 **)(param_1 + 0x3c58) != (undefined1 *)0x0) {
    return **(undefined1 **)(param_1 + 0x3c58);
  }
  nvAssertFailedNoLog("pChipInfo != NULL","src/kernel/gpu/gpu_gspclient.c",0x163);
  return 0;
}


// ===== 00350b30 gpuResetRequiredStateChanged_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuResetRequiredStateChanged_FWCLIENT(long param_1)

{
  (**(code **)(param_1 + 0x140))(param_1,0);
  return 0;
}


// ===== 00350b50 gpuIsSystemRebootRequired_FWCLIENT =====

undefined1 gpuIsSystemRebootRequired_FWCLIENT(void)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo();
  if (lVar1 != 0) {
    return *(undefined1 *)(lVar1 + 0x630);
  }
  return 0;
}


// ===== 00350b80 _gpuDumpEngineFunc =====

ulong _gpuDumpEngineFunc(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined1 uVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  uVar1 = *(uint *)(param_2 + 0x148);
  uVar3 = prbEncNestedStart(param_2,&prb_fields_nvdebug_gpuinfo);
  uVar5 = 0x73;
  pcVar4 = "prbEncNestedStart(pPrbEnc, NVDEBUG_GPUINFO_ENG_GPU)";
  if ((int)uVar3 == 0) {
    prbEncAddUInt32(param_2,prb_fields_nvdebug_eng_gpu,*(undefined4 *)(param_1 + 0x7ac),
                    "src/kernel/gpu/gpu_protobuf.c",0x73);
    prbEncAddBool(param_2,0xc42bb8,0);
    prbEncAddBool(param_2,0xc42bd0,*(undefined1 *)(param_1 + 0x485));
    prbEncAddBool(param_2,0xc42be8,*(undefined1 *)(param_1 + 0x908));
    uVar2 = gpuIsGpuFullPower_IMPL(param_1);
    prbEncAddBool(param_2,0xc42c00,uVar2);
    prbEncAddBool(param_2,0xc42c18,*(undefined1 *)(param_1 + 0x44f));
    prbEncAddBool(param_2,0xc42c30,*(undefined1 *)(param_1 + 0x450));
    prbEncAddBool(param_2,0xc42c48,*(undefined1 *)(param_1 + 0x451));
    prbEncAddBool(param_2,0xc42c60,*(undefined1 *)(param_1 + 0x443));
    prbEncAddBool(param_2,0xc42c78,*(undefined1 *)(param_1 + 0x455));
    prbEncAddBool(param_2,0xc42c90,*(undefined1 *)(param_3 + 2));
    prbEncAddUInt32(param_2,0xc42cc0,*(undefined4 *)(param_1 + 0x3c78));
    uVar3 = prbEncUnwindNesting(param_2,uVar1 & 0xff);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    uVar5 = 0x7b;
    pcVar4 = "prbEncUnwindNesting(pPrbEnc, startingDepth)";
  }
  nvCheckOkFailedNoLog(4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/gpu_protobuf.c",uVar5);
  return uVar3 & 0xffffffff;
}


// ===== 00350d40 gpuDumpCallbackRegister_IMPL =====

void gpuDumpCallbackRegister_IMPL(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 *puVar3;
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
  undefined8 local_28;
  
  lVar2 = *(long *)(param_1 + 0x1ce0);
  if (lVar2 != 0) {
    nvdEngineSignUp_IMPL(param_1,lVar2,_gpuDumpEngineFunc,0xf,0xd,param_1);
    if (*(char *)(param_1 + 0x909) == '\0') {
      return;
    }
    puVar3 = &local_80;
    local_80 = 0x300000002;
    local_78 = 0x500000004;
    local_70 = 0x700000006;
    local_68 = 0x900000008;
    local_60 = 0xb0000000a;
    local_58 = 0xe0000000c;
    local_50 = 0x1200000010;
    local_48 = 0x1400000013;
    local_40 = 0x1700000016;
    local_38 = 0x1900000018;
    local_30 = 0x1b0000001a;
    do {
      uVar1 = *(undefined4 *)puVar3;
      puVar3 = (undefined8 *)((long)puVar3 + 4);
      nvdEngineSignUp_IMPL(param_1,lVar2,0,uVar1,8,param_1);
    } while (&local_28 != puVar3);
  }
  return;
}


// ===== 00350e90 gpuSetUserRegisterAccessPermissions_IMPL =====

undefined4
gpuSetUserRegisterAccessPermissions_IMPL(long param_1,ulong param_2,uint param_3,char param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  undefined *puVar10;
  uint uVar11;
  uint uVar12;
  
  if (*(long *)(param_1 + 0x3a00) == 0) {
    nvAssertFailedNoLog("pGpu->pUserRegisterAccessMap != NULL",
                        "src/kernel/gpu/gpu_register_access_map.c",0x32);
    return 0x40;
  }
  if ((param_2 & 3) == 0) {
    if ((param_3 & 3) == 0) {
      uVar2 = (uint)param_2;
      uVar11 = uVar2 + param_3;
      puVar10 = &DAT_00d285dc;
      uVar1 = uVar11 - 1;
      uVar3 = *(int *)(param_1 + 0x3a10) << 3;
      if (param_4 == '\0') {
        puVar10 = &DAT_00d285de;
      }
      nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x36,
                   "gpuSetUserRegisterAccessPermissions_IMPL",1,
                   "NVRM: %sllowing access to 0x%x-0x%x\n",puVar10,param_2,uVar1,uVar11);
      uVar12 = uVar2 >> 2;
      uVar4 = uVar12 & 7;
      nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x39,
                   "gpuSetUserRegisterAccessPermissions_IMPL",1,
                   "NVRM: Byte 0x%x Bit 0x%x through Byte 0x%x Bit 0x%x\n",uVar2 >> 5,uVar4,
                   uVar11 >> 5,CONCAT44((int)(param_2 >> 0x20),uVar1 >> 2) & 0xffffffff00000007);
      uVar5 = 0x40;
      pcVar9 = "bitOffset < mapSize";
      if (uVar12 < uVar3) {
        param_3 = param_3 >> 2;
        if (uVar12 + param_3 <= uVar3) {
          while( true ) {
            if (uVar4 == 0) {
              if (param_3 != 0) {
                portMemSet((ulong)(uVar12 >> 3) + *(long *)(param_1 + 0x3a00),-(param_4 != '\0'),
                           param_3 >> 3);
                if ((param_3 & 7) != 0) {
                  iVar6 = (param_3 & 0xfffffff8) + uVar12;
                  iVar7 = iVar6;
                  do {
                    iVar8 = iVar7 + 1;
                    nvBitFieldSet(*(undefined8 *)(param_1 + 0x3a00),*(uint *)(param_1 + 0x3a10) >> 2
                                  ,iVar7,param_4);
                    iVar7 = iVar8;
                  } while (iVar6 + (param_3 & 7) != iVar8);
                }
              }
              return 0;
            }
            if (param_3 == 0) break;
            param_3 = param_3 - 1;
            nvBitFieldSet(*(undefined8 *)(param_1 + 0x3a00),*(uint *)(param_1 + 0x3a10) >> 2,uVar12,
                          param_4);
            uVar4 = uVar12 + 1 & 7;
            uVar12 = uVar12 + 1;
          }
          return 0;
        }
        uVar5 = 0x41;
        pcVar9 = "(bitOffset+bitSize) <= mapSize";
      }
      nvAssertFailedNoLog(pcVar9,"src/kernel/gpu/gpu_register_access_map.c",uVar5);
    }
    else {
      nvAssertFailedNoLog("(size & 3) == 0","src/kernel/gpu/gpu_register_access_map.c",0x34);
    }
  }
  else {
    nvAssertFailedNoLog("(offset & 3) == 0","src/kernel/gpu/gpu_register_access_map.c",0x33);
  }
  return 0x1f;
}


// ===== 00351140 gpuSetUserRegisterAccessPermissionsInBulk_IMPL =====

ulong gpuSetUserRegisterAccessPermissionsInBulk_IMPL
                (undefined8 param_1,undefined4 *param_2,uint param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  ulong uVar2;
  
  if ((param_3 & 7) != 0) {
    nvAssertFailedNoLog("(arrSizeBytes & (2 * sizeof(NvU32) - 1)) == 0",
                        "src/kernel/gpu/gpu_register_access_map.c",0x6d);
    return 0x1f;
  }
  param_3 = param_3 >> 2;
  uVar2 = (ulong)param_3;
  if (param_3 != 0) {
    puVar1 = param_2 + (ulong)(param_3 - 1 >> 1) * 2 + 2;
    do {
      uVar2 = gpuSetUserRegisterAccessPermissions_IMPL(param_1,*param_2,param_2[1],param_4);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      param_2 = param_2 + 2;
    } while (param_2 != puVar1);
  }
  return uVar2;
}


// ===== 003511d0 gpuGetUserRegisterAccessPermissions_IMPL =====

undefined8 gpuGetUserRegisterAccessPermissions_IMPL(long param_1,ulong param_2)

{
  char cVar1;
  undefined8 uVar2;
  uint uVar3;
  
  if (*(long *)(param_1 + 0x3a00) == 0) {
    if (*(char *)(param_1 + 0x4919) == '\0') {
      return 1;
    }
    nvAssertFailedNoLog("No user register access map available to read",
                        "src/kernel/gpu/gpu_register_access_map.c",0x96);
  }
  else {
    uVar3 = (uint)(param_2 >> 2) & 0x3fffffff;
    if (uVar3 < (uint)(*(int *)(param_1 + 0x3a10) << 3)) {
      if ((param_2 & 3) == 0) {
        cVar1 = osIsRaisedIRQL();
        if (cVar1 == '\0') {
          uVar2 = nvBitFieldTest(*(undefined8 *)(param_1 + 0x3a00),*(uint *)(param_1 + 0x3a10) >> 2,
                                 uVar3);
          return uVar2;
        }
        nvAssertFailedNoLog("!osIsRaisedIRQL()","src/kernel/gpu/gpu_register_access_map.c",0xa9);
        return 0x2d;
      }
      nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0xa3,
                   "gpuGetUserRegisterAccessPermissions_IMPL",4,
                   "NVRM: Parameter `offset` = %u must be 4-byte aligned.\n",param_2 & 0xffffffff);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x9c,
                   "gpuGetUserRegisterAccessPermissions_IMPL",4,
                   "NVRM: Parameter `offset` = %u is out of bounds.\n",param_2 & 0xffffffff);
    }
  }
  return 0;
}


// ===== 003512f0 gpuInitRegisterAccessMap_IMPL =====

undefined8
gpuInitRegisterAccessMap_IMPL(long param_1,long param_2,int param_3,long param_4,int param_5)

{
  int iVar1;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pAccessMap != NULL","src/kernel/gpu/gpu_register_access_map.c",0x161);
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("accessMapSize != 0","src/kernel/gpu/gpu_register_access_map.c",0x162);
  }
  else if (param_4 == 0) {
    nvAssertFailedNoLog("pComprData != NULL","src/kernel/gpu/gpu_register_access_map.c",0x163);
  }
  else {
    if (param_5 != 0) {
      iVar1 = utilGzGetData(param_4 + 10,param_3,0,param_3,param_2);
      if (param_3 == iVar1) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x170,"gpuInitRegisterAccessMap_IMPL",
                   4,"NVRM: failed to get inflated data, got %u bytes, expecting %u\n",iVar1,
                   *(undefined4 *)(param_1 + 0x3a10));
      return 0x18;
    }
    nvAssertFailedNoLog("comprDataSize != 0","src/kernel/gpu/gpu_register_access_map.c",0x164);
  }
  return 0x40;
}


// ===== 00351420 gpuConstructUserRegisterAccessMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuConstructUserRegisterAccessMap_IMPL(long param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  undefined8 uVar8;
  bool bVar9;
  int local_3c [3];
  
  if (*(char *)(param_1 + 0x45a) != '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x908) != '\0') {
    cVar3 = hypervisorIsVgxHyper_IMPL();
    bVar9 = true;
    if ((cVar3 == '\0') &&
       (iVar5 = osReadRegistryDword(param_1,"RmProfilingAdminOnly",local_3c), iVar5 == 0)) {
      bVar9 = local_3c[0] == 1;
    }
    *(bool *)(param_1 + 0x4a27) = bVar9;
    return 0;
  }
  if (*(int *)(param_1 + 0x3a10) != 0) {
    nvAssertFailedNoLog("pGpu->userRegisterAccessMapSize == 0",
                        "src/kernel/gpu/gpu_register_access_map.c",0xec);
  }
  piVar6 = (int *)portMemAllocPaged(0x200c);
  if (piVar6 == (int *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gpu_register_access_map.c",0xf1);
    return 0x51;
  }
  portMemSet(piVar6,0,0x200c);
  iVar5 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a41,piVar6,0x200c);
  if (iVar5 == 0) {
    iVar5 = *piVar6;
    *(int *)(param_1 + 0x3a10) = iVar5;
    iVar1 = piVar6[1];
    uVar4 = iVar5 + 3U & 0xfffffffc;
    iVar2 = piVar6[0x402];
    *(uint *)(param_1 + 0x3a10) = uVar4;
    if (uVar4 == 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x107,
                   "gpuConstructUserRegisterAccessMap_IMPL",1,
                   "NVRM: User Register Access Map unsupported for this chip.\n");
      iVar5 = 0;
      goto LAB_003516a7;
    }
    lVar7 = portMemAllocPaged(uVar4);
    *(long *)(param_1 + 0x3a00) = lVar7;
    uVar8 = 0;
    if (lVar7 != 0) {
      lVar7 = portMemAllocPaged(*(undefined4 *)(param_1 + 0x3a10));
      uVar8 = *(undefined8 *)(param_1 + 0x3a00);
      *(long *)(param_1 + 0x3a08) = lVar7;
      if (lVar7 != 0) {
        nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x11b,
                     "gpuConstructUserRegisterAccessMap_IMPL",1,
                     "NVRM: Allocated User Register Access Map of 0x%xB @%p\n",
                     *(undefined4 *)(param_1 + 0x3a10),uVar8);
        if ((*(char *)(param_1 + 0x3a38) == '\0') || (iVar1 == 0)) {
          nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x120,
                       "gpuConstructUserRegisterAccessMap_IMPL",1,
                       "NVRM: GPU/Platform does not have restricted user register access!  Allowing all registers.\n"
                      );
          portMemSet(*(undefined8 *)(param_1 + 0x3a00),0xff,*(undefined4 *)(param_1 + 0x3a10));
        }
        else {
          iVar5 = gpuInitRegisterAccessMap_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x3a00),
                             *(undefined4 *)(param_1 + 0x3a10),piVar6 + 2,iVar1);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "gpuInitRegisterAccessMap(pGpu, pGpu->pUserRegisterAccessMap, pGpu->userRegisterAccessMapSize, compressedData, compressedSize)"
                       ,"src/kernel/gpu/gpu_register_access_map.c",0x126);
            uVar8 = *(undefined8 *)(param_1 + 0x3a00);
            goto LAB_00351676;
          }
        }
        lVar7 = portMemCopy(*(undefined8 *)(param_1 + 0x3a08),*(undefined4 *)(param_1 + 0x3a10),
                            *(undefined8 *)(param_1 + 0x3a00),*(undefined4 *)(param_1 + 0x3a10));
        if (lVar7 == 0) {
          iVar5 = 0x1e;
          nvDbg_Printf("src/kernel/gpu/gpu_register_access_map.c",0x12f,
                       "gpuConstructUserRegisterAccessMap_IMPL",4,
                       "NVRM: Failed to initialize unrestricted register access map\n");
          uVar8 = *(undefined8 *)(param_1 + 0x3a00);
        }
        else {
          cVar3 = hypervisorIsVgxHyper_IMPL();
          if ((cVar3 == '\0') &&
             (iVar5 = osReadRegistryDword(param_1,"RmProfilingAdminOnly",local_3c), iVar5 == 0)) {
            *(bool *)(param_1 + 0x4a27) = local_3c[0] == 1;
            iVar5 = 0;
            if (local_3c[0] != 1) goto LAB_003516a7;
          }
          else {
            *(undefined1 *)(param_1 + 0x4a27) = 1;
          }
          iVar5 = 0;
          if ((iVar2 == 0) ||
             (iVar5 = gpuSetUserRegisterAccessPermissionsInBulk_IMPL(param_1,piVar6 + 0x403,iVar2,0)
             , iVar5 == 0)) goto LAB_003516a7;
          *(undefined1 *)(param_1 + 0x4a27) = 0;
          uVar8 = *(undefined8 *)(param_1 + 0x3a00);
        }
        goto LAB_00351676;
      }
    }
    iVar5 = 0x51;
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_GPU_GET_USER_REGISTER_ACCESS_MAP, pParams, sizeof(*pParams))"
               ,"src/kernel/gpu/gpu_register_access_map.c",0xf4);
    uVar8 = *(undefined8 *)(param_1 + 0x3a00);
  }
LAB_00351676:
  portMemFree(uVar8);
  *(undefined8 *)(param_1 + 0x3a00) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0x3a08));
  *(undefined8 *)(param_1 + 0x3a08) = 0;
  *(undefined4 *)(param_1 + 0x3a10) = 0;
LAB_003516a7:
  portMemFree(piVar6);
  return iVar5;
}


// ===== 00351880 gpuInitRegistryOverrides_KERNEL =====

undefined8 gpuInitRegistryOverrides_KERNEL(long param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  uint local_1c [3];
  
  local_1c[0] = 0;
  timeoutRegistryOverride(param_1 + 0x1af0,param_1);
  iVar2 = osReadRegistryDword(param_1,"nvBrokenFb",local_1c);
  cVar1 = *(char *)(*(long *)(param_1 + 0x4d8) + 0x80);
  if (iVar2 == 0) {
    if (cVar1 == '\0') {
      if ((local_1c[0] & 1) == 0) goto LAB_003518de;
    }
    else {
      local_1c[0] = local_1c[0] | 1;
    }
LAB_00351bf8:
    *(undefined1 *)(param_1 + 0x44d) = 1;
  }
  else {
    local_1c[0] = 0;
    if (cVar1 != '\0') {
      local_1c[0] = 1;
      goto LAB_00351bf8;
    }
  }
LAB_003518de:
  iVar2 = osReadRegistryDword(param_1,"RMInstVPR",param_1 + 0x4938);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + 0x4938) = 0;
  }
  *(undefined4 *)(param_1 + 0x1b1c) = 0;
  iVar2 = osReadRegistryDword(param_1,"RmComputeModeRules",local_1c);
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x1b1c) = local_1c[0];
  }
  threadStateInitRegistryOverrides(param_1);
  *(undefined1 *)(param_1 + 0x490a) = 1;
  iVar2 = osReadRegistryDword(param_1,"RMGpuSurpriseRemoval",local_1c);
  if (iVar2 == 0) {
    *(bool *)(param_1 + 0x490a) = local_1c[0] == 1;
  }
  if (*(char *)(param_1 + 0x4a50) != '\0') {
    iVar2 = osReadRegistryDword(param_1,"RMSetSriovMode",local_1c);
    if (iVar2 == 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_registry.c",0x6b,"gpuInitRegistryOverrides_KERNEL",1,
                   "NVRM: Overriding SRIOV Mode to %u\n",local_1c[0] == 1);
      uVar4 = local_1c[0] == 1;
      *(undefined1 *)(param_1 + 0x491d) = uVar4;
    }
    else {
      cVar1 = hypervisorIsVgxHyper_IMPL();
      if ((cVar1 != '\0') && (cVar1 = rmcfg_IsTURING_CLASSIC_GPUS(param_1), cVar1 == '\0')) {
        *(undefined1 *)(param_1 + 0x491d) = 1;
        osWriteRegistryDword(param_1,"RMSetSriovMode",1);
      }
      uVar4 = *(undefined1 *)(param_1 + 0x491d);
    }
    nvDbg_Printf("src/kernel/gpu/gpu_registry.c",0x82,"gpuInitRegistryOverrides_KERNEL",1,
                 "NVRM: SRIOV status[%d].\n",uVar4);
  }
  if ((*(char *)(param_1 + 0x491d) != '\0') && (*(char *)(param_1 + 0x909) != '\0')) {
    *(undefined1 *)(param_1 + 0x4a4e) = 1;
  }
  if ((*(char *)(param_1 + 0x4913) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) {
    *(undefined1 *)(param_1 + 0x4a4e) = *(undefined1 *)(param_1 + 0x473);
  }
  iVar2 = osReadRegistryDword(param_1,"RMSetClientRMAllocatedCtxBuffer",local_1c);
  if (iVar2 == 0) {
    *(bool *)(param_1 + 0x4a23) = local_1c[0] == 1;
    nvDbg_Printf("src/kernel/gpu/gpu_registry.c",0x95,"gpuInitRegistryOverrides_KERNEL",1,
                 "NVRM: Setting Client RM managed context buffer to %u\n",local_1c[0] == 1);
    if (*(char *)(param_1 + 0x491d) != '\0') goto LAB_00351ba0;
LAB_00351bad:
    if (*(char *)(param_1 + 0x909) == '\0') goto LAB_00351a2a;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x491d);
    if (*(char *)(param_1 + 0x909) == '\0') {
      if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') {
        if (cVar1 == '\0') goto LAB_00351d20;
      }
      else {
        if ((cVar1 == '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
LAB_00351d20:
          if (*(char *)(param_1 + 0x908) == '\0') {
            *(undefined1 *)(param_1 + 0x4a23) = 0;
          }
          goto LAB_00351a2a;
        }
        *(undefined1 *)(param_1 + 0x4a23) = 1;
        nvDbg_Printf("src/kernel/gpu/gpu_registry.c",0xa1,"gpuInitRegistryOverrides_KERNEL",1,
                     "NVRM: Enabled Client RM managed context buffer for zero-FB + SRIOV.\n");
        if (*(char *)(param_1 + 0x491d) == '\0') goto LAB_00351bad;
      }
LAB_00351ba0:
      if (*(char *)(param_1 + 0x491e) != '\0') goto LAB_00351bad;
    }
    else {
      *(undefined1 *)(param_1 + 0x4a23) = 1;
      if (cVar1 != '\0') goto LAB_00351ba0;
    }
  }
  iVar2 = osReadRegistryDword(param_1,"RMSplitVasMgmtServerClientRm",local_1c);
  *(bool *)(param_1 + 0x4922) = iVar2 != 0 || local_1c[0] == 1;
  nvDbg_Printf("src/kernel/gpu/gpu_registry.c",0xb7,"gpuInitRegistryOverrides_KERNEL",1,
               "NVRM: Split VAS mgmt between Server/Client RM %u\n",iVar2 != 0 || local_1c[0] == 1);
LAB_00351a2a:
  iVar2 = osReadRegistryDword(param_1,"RmGpuFabricProbe",param_1 + 0x4a48);
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x4a48) = *(uint *)(param_1 + 0x4a48) | 0x80000000;
  }
  *(undefined1 *)(param_1 + 0x491b) = 0;
  iVar2 = osReadRegistryDword(param_1,"RmDmaAdjustPeerMmioBF3",local_1c);
  if (iVar2 == 0) {
    *(bool *)(param_1 + 0x491b) = local_1c[0] == 1;
  }
  iVar2 = osReadRegistryDword(param_1,"RMDebugRusdPolling",local_1c);
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x3c84) = local_1c[0];
  }
  iVar2 = osReadRegistryDword(param_1,"RMRusdPollingInterval",local_1c);
  if (iVar2 == 0) {
    if (local_1c[0] < 100) {
      local_1c[0] = 100;
      uVar4 = 1;
      uVar3 = 100;
    }
    else if (local_1c[0] < 0x3e9) {
      uVar4 = 1;
      uVar3 = local_1c[0];
    }
    else {
      local_1c[0] = 1000;
      uVar4 = 1;
      uVar3 = 1000;
    }
  }
  else {
    uVar3 = 500;
    uVar4 = 0;
  }
  *(undefined1 *)(param_1 + 0x3c90) = uVar4;
  *(uint *)(param_1 + 0x3c8c) = uVar3;
  iVar2 = osReadRegistryDword(param_1,"RmInitMemReuse",local_1c);
  if (iVar2 == 0 && local_1c[0] == 0) {
    *(undefined1 *)(param_1 + 0x4ba) = 0;
  }
  iVar2 = osReadRegistryDword(param_1,"RmMemSubsystemErrorDetection",local_1c);
  if (iVar2 == 0) {
    *(bool *)(param_1 + 0x4b28) = local_1c[0] == 1;
  }
  return 0;
}


// ===== 00351dd0 gpuInitInstLocOverrides_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuInitInstLocOverrides_IMPL(long param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint local_20;
  uint local_1c [3];
  
  local_20 = 0;
  iVar3 = osReadRegistryDword(param_1,"RmConfidentialCompute",&local_20);
  if ((((iVar3 == 0) && ((local_20 & 1) != 0)) ||
      (cVar2 = (**(code **)(param_1 + 0x390))(param_1), cVar2 != '\0')) ||
     (cVar2 = (**(code **)(param_1 + 0x3b0))(param_1), cVar2 != '\0')) {
    *(undefined8 *)(param_1 + 0x4924) = 0xffffffffffffffff;
    *(undefined8 *)(param_1 + 0x492c) = 0xfffffeefffffffff;
    uVar4 = 0xffffffff;
    uVar1 = 0xffffffff;
    if (*(char *)(param_1 + 0x44d) != '\0') {
LAB_00351e33:
      uVar4 = uVar1;
      if (((*(char *)(param_1 + 1099) != '\0') || (*(char *)(param_1 + 0x4921) != '\0')) ||
         ((uVar4 & 0xc00000c) == 0)) {
        return 0;
      }
      goto LAB_00351e6a;
    }
  }
  else {
    osReadRegistryDword(param_1,"RMInstLoc",param_1 + 0x4924);
    osReadRegistryDword(param_1,"RMInstLoc2",param_1 + 0x4928);
    osReadRegistryDword(param_1,"RMInstLoc3",param_1 + 0x492c);
    osReadRegistryDword(param_1,"RMInstLoc4",param_1 + 0x4930);
    if (*(char *)(param_1 + 0x4934) != '\0') {
      if (((*(char *)(param_1 + 0x44d) == '\0') && (*(int *)(param_1 + 0x4924) == 0)) &&
         ((*(int *)(param_1 + 0x4928) == 0 &&
          ((*(int *)(param_1 + 0x492c) == 0 && (*(int *)(param_1 + 0x4930) == 0)))))) {
        *(undefined1 *)(param_1 + 0x4a22) = 1;
        *(undefined8 *)(param_1 + 0x4924) = 0x30033030;
        *(undefined8 *)(param_1 + 0x492c) = 0xc00000;
        uVar1 = 0x30033030;
        goto LAB_00351e33;
      }
      nvDbg_Printf("src/kernel/gpu/gpu_registry.c",0x196,"_gpuInitGlobalSurfaceOverride",1,
                   "NVRM: INSTLOC overrides may not work with large mem systems on GP100+\n");
    }
    if (*(char *)(param_1 + 0x4a22) == '\0') {
      iVar3 = osReadRegistryDword(param_1,"GlobalSurfaceOverrides",local_1c);
      if ((iVar3 == 0) && ((local_1c[0] & 8) != 0)) {
        *(undefined1 *)(param_1 + 0x4a22) = 1;
        local_1c[0] = local_1c[0] & 3;
        goto LAB_00351fd5;
      }
      if (*(char *)(param_1 + 0x4a22) != '\0') goto LAB_00351fd3;
      uVar4 = *(uint *)(param_1 + 0x4924);
    }
    else {
LAB_00351fd3:
      local_1c[0] = 0;
LAB_00351fd5:
      uVar4 = 0;
      iVar3 = 0;
      do {
        bVar5 = (byte)iVar3;
        iVar3 = iVar3 + 2;
        uVar4 = uVar4 | local_1c[0] << (bVar5 & 0x1f);
      } while (iVar3 != 0x20);
      *(uint *)(param_1 + 0x4924) = uVar4;
      *(uint *)(param_1 + 0x4928) = uVar4;
      *(uint *)(param_1 + 0x492c) = uVar4;
      *(uint *)(param_1 + 0x4930) = uVar4;
    }
    uVar1 = uVar4;
    if ((*(char *)(param_1 + 0x44d) == '\0') || ((uVar4 & 0xefffffff) != 0)) {
      if ((uVar4 + 0x65555556 & 0xefffffff) == 0) {
        if ((*(int *)(param_1 + 0x4928) == -0x55555556) &&
           (*(int *)(param_1 + 0x492c) == -0x55555556)) {
          *(undefined4 *)(param_1 + 0x4930) = 0x2000;
          *(undefined1 *)(param_1 + 1099) = 1;
          *(undefined4 *)(param_1 + 0x1e34) = 1;
          return 0;
        }
      }
      else {
        if ((uVar4 + 0xaaaaaaab & 0xbfffffff) != 0) goto LAB_00351e33;
        if (*(int *)(param_1 + 0x4928) == 0x55555555) goto LAB_003520b9;
      }
    }
    else {
      if (*(int *)(param_1 + 0x4928) != 0) goto LAB_00351e33;
      if (*(int *)(param_1 + 0x492c) != 0) {
        return 0;
      }
      if (*(int *)(param_1 + 0x4930) != 0) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x4924) = 0x55555555;
      *(undefined8 *)(param_1 + 0x4928) = 0x5555555555555555;
      uVar4 = 0x55555555;
LAB_003520b9:
      if (*(int *)(param_1 + 0x492c) == 0x55555555) {
        *(undefined4 *)(param_1 + 0x4930) = 0x1000;
        *(undefined1 *)(param_1 + 1099) = 1;
        *(undefined4 *)(param_1 + 0x1e34) = 0;
        return 0;
      }
    }
  }
  if (*(char *)(param_1 + 1099) != '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x4921) != '\0') {
    return 0;
  }
LAB_00351e6a:
  *(uint *)(param_1 + 0x4924) = uVar4 & 0xf3fffff3;
  nvDbg_Printf("src/kernel/gpu/gpu_registry.c",0x174,"gpuInitInstLocOverrides_IMPL",1,
               "NVRM: Ignoring regkeys to place BAR PTE/PDE in SYSMEM\n");
  return 0;
}


// ===== 0035216a gpuresCopyConstruct_IMPL.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gpuresCopyConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
  _DAT_000000a0 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00352180 gpuresCopyConstruct_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gpuresCopyConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  undefined1 uVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                             __nvoc_class_def_GpuResource);
  if (lVar4 == 0) {
    return 0x31;
  }
  lVar2 = *(long *)(lVar4 + 0xe0);
  if (lVar2 != 0) {
    uVar1 = *(undefined1 *)(lVar4 + 0xf8);
    if (param_1 == 0) {
      _DAT_000000a0 = 0;
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    *(undefined4 *)(*(long *)(param_1 + 200) + 0xa0) = *(undefined4 *)(lVar2 + 0x7a4);
    *(long *)(param_1 + 0xe0) = lVar2;
    uVar5 = gpumgrGetGpuGrpFromGpu();
    *(undefined8 *)(param_1 + 0xd8) = uVar5;
    *(undefined1 *)(param_1 + 0xf8) = uVar1;
  }
  return 0;
}


// ===== 0035220b gpuresConstruct_IMPL.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gpuresConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
  _DAT_000000a0 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00352220 gpuresConstruct_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 gpuresConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined1 local_41;
  long local_40;
  long local_38;
  long local_30;
  
  lVar1 = *(long *)(param_2 + 0x10);
  local_30 = 0;
  local_41 = 1;
  lVar7 = param_1;
  if (*(int *)(lVar1 + 0x118) == 0x4b01b3) {
    uVar6 = __nvoc_dynamicCast(param_1,__nvoc_class_def_Subdevice);
    *(undefined8 *)(param_1 + 0xf0) = uVar6;
    iVar5 = *(int *)(lVar1 + 0x118);
joined_r0x00352308:
    if (iVar5 != 0xe0ac20) {
LAB_0035230e:
      iVar5 = refFindAncestorOfType(lVar1,&DAT_00e0ac20,&local_40);
      if (iVar5 != 0) goto LAB_00352295;
      lVar7 = *(long *)(local_40 + 8);
    }
  }
  else {
    iVar5 = refFindAncestorOfType(lVar1,0x4b01b3,&local_38);
    if (iVar5 == 0) {
      uVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_Subdevice);
      *(undefined8 *)(param_1 + 0xf0) = uVar6;
      iVar5 = *(int *)(lVar1 + 0x118);
      goto joined_r0x00352308;
    }
    if (*(int *)(lVar1 + 0x118) != 0xe0ac20) goto LAB_0035230e;
    if (param_1 == 0) {
      lVar7 = 0;
    }
  }
  uVar6 = __nvoc_dynamicCast(lVar7,__nvoc_class_def_Device);
  *(undefined8 *)(param_1 + 0xe8) = uVar6;
LAB_00352295:
  if (*(long *)(param_3 + 0x58) == 0) {
    iVar5 = gpuGetByRef(lVar1,&local_41,&local_30);
    uVar3 = local_41;
    if (iVar5 != 0) {
      return 0;
    }
    uVar4 = 0;
    if (local_30 != 0) {
      if (param_1 == 0) {
        _DAT_000000a0 = 0;
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      *(undefined4 *)(*(long *)(param_1 + 200) + 0xa0) = *(undefined4 *)(local_30 + 0x7a4);
      *(long *)(param_1 + 0xe0) = local_30;
      uVar6 = gpumgrGetGpuGrpFromGpu();
      *(undefined1 *)(param_1 + 0xf8) = uVar3;
      *(undefined8 *)(param_1 + 0xd8) = uVar6;
    }
  }
  else {
    uVar4 = gpuresCopyConstruct_IMPL(param_1,param_2,param_3);
  }
  return uVar4;
}


// ===== 003523e0 gpuresMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuresMap_IMPL(long *param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined1 local_41;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar3 = CliGetGpuFromContext(*(undefined8 *)(param_4 + 0x20),&local_41);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/gpu_resource.c",0x83);
    iVar1 = 0x1f;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x1d0))(param_1,lVar3,&local_40,local_3c);
    if (iVar1 == 0) {
      iVar1 = rmapiMapGpuCommon(param_1[0x17],param_2,param_4,lVar3,local_40,local_3c[0]);
      uVar2 = osGetCurrentProcess();
      *(undefined4 *)(param_4 + 0x48) = uVar2;
      if (*(undefined8 **)(param_3 + 0x20) != (undefined8 *)0x0) {
        **(undefined8 **)(param_3 + 0x20) = *(undefined8 *)(param_4 + 0x18);
      }
    }
  }
  return iVar1;
}


// ===== 003524d0 gpuresUnmap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuresUnmap_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long *plVar5;
  long lVar6;
  undefined1 local_39 [9];
  
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  lVar6 = CliGetGpuFromContext(*(undefined8 *)(param_3 + 0x20),local_39);
  if (lVar6 != 0) {
    uVar1 = *(undefined8 *)(param_3 + 8);
    uVar2 = *(undefined8 *)(param_3 + 0x18);
    uVar3 = *(undefined8 *)(*(long *)(param_3 + 0x50) + 0x18);
    uVar4 = (**(code **)(*plVar5 + 0xd8))(plVar5);
    osUnmapGPU(*(undefined8 *)(lVar6 + 0x4e0),uVar4,uVar2,uVar1,uVar3);
    return 0;
  }
  nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/gpu_resource.c",0xa5);
  return 0x1f;
}


// ===== 003525a0 gpuresShareCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong gpuresShareCallback_IMPL(long param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  char cVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  long *plVar14;
  long local_60;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  
  lVar12 = *(long *)(*(long *)(param_1 + 0xd0) + 0xe0);
  if (((lVar12 == 0) || (*(long *)(lVar12 + 0x1bc0) == 0)) ||
     (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar12), cVar6 == '\0')) {
    sVar7 = *(short *)(param_4 + 8);
    if (sVar7 != 5) goto LAB_00352788;
    if ((*(byte *)(param_4 + 10) & 2) != 0) {
      return 1;
    }
  }
  else {
    sVar7 = *(short *)(param_4 + 8);
    if (sVar7 == 5) {
      if ((*(byte *)(param_4 + 4) & 1) != 0) {
        uVar9 = *(uint *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x11c);
        if (uVar9 == 0xc637) {
          plVar14 = (long *)__nvoc_dynamicCast(param_2,__nvoc_class_def_RmClient);
          if ((plVar14 != (long *)0x0) &&
             (uVar9 = (**(code **)(*plVar14 + 0xd8))(plVar14), 1 < uVar9)) {
            return 1;
          }
        }
        else if (uVar9 < 0xc638) {
          if ((uVar9 - 0x3e & 0xfffffffd) == 0) {
            return 1;
          }
          if (uVar9 == 0xa084) {
            return 1;
          }
        }
      }
      if (param_3 == 0) {
        nvAssertFailedNoLog("pParentRef != NULL","src/kernel/gpu/gpu_resource.c",0x100);
        return 0x1f;
      }
      uVar1 = *(undefined8 *)(lVar12 + 0x1bc0);
      lVar13 = param_3;
      if ((*(int *)(param_3 + 0x118) != 0xe0ac20) &&
         (uVar9 = refFindAncestorOfType(param_3,&DAT_00e0ac20,&local_60), lVar13 = local_60,
         uVar9 != 0)) {
        nvAssertOkFailedNoLog
                  (uVar9,"refFindAncestorOfType(pParentRef, classId(Device), &pInvokingDeviceRef)",
                   "src/kernel/gpu/gpu_resource.c",0x108);
        return (ulong)uVar9;
      }
      local_60 = lVar13;
      uVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_60 + 8),__nvoc_class_def_Device);
      iVar8 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar12,uVar1,uVar10,local_58);
      if (iVar8 == 0) {
        iVar8 = kmigmgrGetInstanceRefFromDevice_IMPL
                          (lVar12,uVar1,*(undefined8 *)(*(long *)(param_1 + 0xd0) + 0xe8),local_48);
        if (iVar8 == 0) {
          local_58 = kmigmgrMakeGIReference_IMPL(local_58._0_8_);
          local_48 = kmigmgrMakeGIReference_IMPL(local_48._0_8_);
          cVar6 = kmigmgrAreMIGReferencesSame_IMPL(local_58,local_48);
          if (cVar6 != '\0') {
            return 1;
          }
        }
      }
      goto LAB_003526a8;
    }
LAB_00352788:
    if (sVar7 != 6) goto LAB_003526a8;
  }
  if (param_3 != 0) {
    lVar12 = param_3;
    if (*(int *)(param_3 + 0x118) != 0xe0ac20) {
      iVar8 = refFindAncestorOfType(param_3,&DAT_00e0ac20,local_48);
      lVar12 = local_48._0_8_;
      if (iVar8 != 0) goto LAB_003526a8;
    }
    local_48._0_8_ = lVar12;
    iVar8 = refFindAncestorOfType
                      (*(undefined8 *)(*(long *)(param_1 + 0xb8) + 0x48),&DAT_00e0ac20,local_58);
    if (iVar8 == 0) {
      lVar12 = __nvoc_dynamicCast(*(undefined8 *)(local_58._0_8_ + 8),__nvoc_class_def_Device);
      lVar13 = __nvoc_dynamicCast(*(undefined8 *)(local_48._0_8_ + 8),__nvoc_class_def_Device);
      auVar5._8_8_ = local_48._8_8_;
      auVar5._0_8_ = local_48._0_8_;
      auVar4._8_8_ = local_48._8_8_;
      auVar4._0_8_ = local_48._0_8_;
      auVar3._8_8_ = local_58._8_8_;
      auVar3._0_8_ = local_58._0_8_;
      auVar2._8_8_ = local_58._8_8_;
      auVar2._0_8_ = local_58._0_8_;
      if (((lVar12 != 0) && (local_58 = auVar2, local_48 = auVar4, lVar13 != 0)) &&
         (local_58 = auVar3, local_48 = auVar5, *(int *)(lVar12 + 0x180) == *(int *)(lVar13 + 0x180)
         )) {
        return 1;
      }
    }
  }
LAB_003526a8:
  uVar11 = rmresShareCallback_IMPL(*(undefined8 *)(param_1 + 200),param_2,param_3,param_4);
  return uVar11;
}


// ===== 003528e0 gpuresGetRegBaseOffsetAndSize_IMPL =====

undefined8 gpuresGetRegBaseOffsetAndSize_IMPL(void)

{
  return 0x56;
}


// ===== 003528f0 gpuresGetMapAddrSpace_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuresGetMapAddrSpace_IMPL
               (long *param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 local_20 [4];
  undefined1 local_1c [12];
  
  iVar1 = (**(code **)(*param_1 + 0x1d0))
                    (param_1,*(undefined8 *)(param_1[0x1a] + 0xe0),local_20,local_1c);
  if ((param_4 != (undefined4 *)0x0) && (iVar1 == 0)) {
    *param_4 = 3;
  }
  return;
}


// ===== 00352940 gpuresInternalControlForward_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuresInternalControlForward_IMPL
               (long *param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  lVar1 = *(long *)(param_1[0x1a] + 0xe0);
  pcVar2 = *(code **)(lVar1 + 0x3b90);
  uVar3 = (**(code **)(*param_1 + 0x1e8))();
  (*pcVar2)(lVar1 + 0x3b58,*(undefined4 *)(**(long **)(param_1[0x17] + 0x48) + 0x48),uVar3,param_2,
            param_3,param_4);
  return;
}


// ===== 003529bf gpuresGetInternalObjectHandle_IMPL.cold =====

void gpuresGetInternalObjectHandle_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003529d0 gpuresGetInternalObjectHandle_IMPL =====

undefined4 gpuresGetInternalObjectHandle_IMPL(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    return *(undefined4 *)(*(long *)(*(long *)(param_1 + 0xb8) + 0x48) + 0x10);
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003529f0 gpuresControl_IMPL =====

undefined4 gpuresControl_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  lVar1 = *(long *)(param_1 + 0xe0);
  if (lVar1 != 0) {
    *(long *)(*(long *)(param_3 + 0x70) + 0x20) = lVar1;
    uVar2 = gpumgrSetCurrentGpuInstance(*(undefined4 *)(lVar1 + 0x7a4));
    uVar3 = resControl_IMPL(*(undefined8 *)(param_1 + 0xb8),param_2,param_3);
    gpumgrSetCurrentGpuInstance(uVar2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGpuResource->pGpu != NULL","src/kernel/gpu/gpu_resource.c",400);
  return 0x40;
}


// ===== 00352a90 gpuresControlSetup_IMPL =====

void gpuresControlSetup_IMPL(long param_1,long param_2)

{
  *(undefined8 *)(*(long *)(param_1 + 0x70) + 0x20) = *(undefined8 *)(param_2 + 0xe0);
  return;
}


// ===== 00352aa4 gpuresSetGpu_IMPL.cold =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gpuresSetGpu_IMPL_cold(void)

{
  code *pcVar1;
  
  _DAT_000000a0 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00352ab0 gpuresSetGpu_IMPL =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gpuresSetGpu_IMPL(long param_1,long param_2,undefined1 param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    return;
  }
  if (param_1 != 0) {
    *(undefined4 *)(*(long *)(param_1 + 200) + 0xa0) = *(undefined4 *)(param_2 + 0x7a4);
    *(long *)(param_1 + 0xe0) = param_2;
    uVar2 = gpumgrGetGpuGrpFromGpu(param_2);
    *(undefined8 *)(param_1 + 0xd8) = uVar2;
    *(undefined1 *)(param_1 + 0xf8) = param_3;
    return;
  }
  _DAT_000000a0 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00352b10 gpuresGetByDeviceOrSubdeviceHandle_IMPL =====

int gpuresGetByDeviceOrSubdeviceHandle_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long local_20;
  
  *param_3 = 0;
  iVar1 = clientGetResourceRef_IMPL(param_1,param_2,&local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_GpuResource);
    *param_3 = lVar2;
    if (lVar2 == 0) {
      return 0x33;
    }
    lVar2 = __nvoc_dynamicCast(lVar2,__nvoc_class_def_Device);
    if (lVar2 == 0) {
      lVar2 = __nvoc_dynamicCast(*param_3,__nvoc_class_def_Subdevice);
      iVar1 = 0;
      if (lVar2 == 0) {
        iVar1 = 0x33;
      }
      return iVar1;
    }
  }
  return iVar1;
}


// ===== 00352bb0 __pfx__gpuAddClassToClassDBByEngTagClassId =====

undefined8 __pfx__gpuAddClassToClassDBByEngTagClassId(long param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  int *piVar7;
  ulong uVar8;
  undefined8 *puVar9;
  int in_R10D;
  
  if (param_2 == (int *)0x0 && param_3 == (int *)0x0) {
    nvCheckFailedNoLog(1,"(NULL != pEngDesc) || (NULL != pExternalClassId)",
                       "src/kernel/gpu/gpu_resource_desc.c",0x171);
    return 0x1f;
  }
  uVar5 = *(uint *)(param_1 + 0x8e0);
  if (uVar5 != 0) {
    piVar7 = *(int **)(param_1 + 0x8d0);
    piVar2 = piVar7 + (ulong)uVar5 * 2;
    if (param_2 == (int *)0x0) {
      do {
        if (*piVar7 == *param_3) {
          return 0;
        }
        piVar7 = piVar7 + 2;
      } while (piVar2 != piVar7);
    }
    else {
      do {
        while (piVar7[1] != *param_2) {
          piVar7 = piVar7 + 2;
          if (piVar7 == piVar2) goto LAB_00352c44;
        }
        if (param_3 == (int *)0x0) {
          return 0;
        }
        if (*param_3 == *piVar7) {
          return 0;
        }
        piVar7 = piVar7 + 2;
      } while (piVar2 != piVar7);
    }
  }
LAB_00352c44:
  if (*(uint *)(param_1 + 0x8a0) == 0) {
    return 0;
  }
  piVar7 = *(int **)(param_1 + 0x898);
  piVar2 = piVar7 + (ulong)*(uint *)(param_1 + 0x8a0) * 2;
  do {
    if ((*piVar7 != -1) && (piVar7[1] != -0x4cc4eb00)) {
      if (param_2 == (int *)0x0) {
        iVar4 = *param_3;
      }
      else {
        if (piVar7[1] != *param_2) goto LAB_00352c68;
        if (param_3 == (int *)0x0) goto LAB_00352c8e;
        iVar4 = *param_3;
      }
      if (*piVar7 == iVar4) {
LAB_00352c8e:
        puVar9 = *(undefined8 **)(param_1 + 0x8d0);
        if (uVar5 != 0) {
          uVar8 = 0;
          bVar6 = false;
          do {
            if (*(int *)(puVar9 + uVar8) == *piVar7) {
              bVar6 = true;
              in_R10D = (int)uVar8;
            }
            uVar8 = uVar8 + 1;
          } while (uVar5 != uVar8);
          if (bVar6) {
            uVar1 = in_R10D + 1;
            lVar3 = (ulong)(uVar5 - uVar1) * 8;
            portMemMove(puVar9 + (in_R10D + 2),lVar3,puVar9 + uVar1,lVar3);
            puVar9 = (undefined8 *)((ulong)uVar1 * 8 + *(long *)(param_1 + 0x8d0));
          }
          else {
            puVar9 = puVar9 + uVar5;
          }
        }
        *puVar9 = *(undefined8 *)piVar7;
        *(int *)(param_1 + 0x8e0) = *(int *)(param_1 + 0x8e0) + 1;
        *(undefined1 *)(param_1 + 0x1e28) = 0;
        return 0;
      }
    }
LAB_00352c68:
    piVar7 = piVar7 + 2;
    if (piVar7 == piVar2) {
      return 0;
    }
  } while( true );
}


// ===== 00352bc0 _gpuAddClassToClassDBByEngTagClassId =====

undefined8 _gpuAddClassToClassDBByEngTagClassId(long param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  int *piVar7;
  ulong uVar8;
  undefined8 *puVar9;
  int in_R10D;
  
  if (param_2 == (int *)0x0 && param_3 == (int *)0x0) {
    nvCheckFailedNoLog(1,"(NULL != pEngDesc) || (NULL != pExternalClassId)",
                       "src/kernel/gpu/gpu_resource_desc.c",0x171);
    return 0x1f;
  }
  uVar5 = *(uint *)(param_1 + 0x8e0);
  if (uVar5 != 0) {
    piVar7 = *(int **)(param_1 + 0x8d0);
    piVar2 = piVar7 + (ulong)uVar5 * 2;
    if (param_2 == (int *)0x0) {
      do {
        if (*piVar7 == *param_3) {
          return 0;
        }
        piVar7 = piVar7 + 2;
      } while (piVar2 != piVar7);
    }
    else {
      do {
        while (piVar7[1] != *param_2) {
          piVar7 = piVar7 + 2;
          if (piVar7 == piVar2) goto LAB_00352c44;
        }
        if (param_3 == (int *)0x0) {
          return 0;
        }
        if (*param_3 == *piVar7) {
          return 0;
        }
        piVar7 = piVar7 + 2;
      } while (piVar2 != piVar7);
    }
  }
LAB_00352c44:
  if (*(uint *)(param_1 + 0x8a0) == 0) {
    return 0;
  }
  piVar7 = *(int **)(param_1 + 0x898);
  piVar2 = piVar7 + (ulong)*(uint *)(param_1 + 0x8a0) * 2;
  do {
    if ((*piVar7 != -1) && (piVar7[1] != -0x4cc4eb00)) {
      if (param_2 == (int *)0x0) {
        iVar4 = *param_3;
      }
      else {
        if (piVar7[1] != *param_2) goto LAB_00352c68;
        if (param_3 == (int *)0x0) goto LAB_00352c8e;
        iVar4 = *param_3;
      }
      if (*piVar7 == iVar4) {
LAB_00352c8e:
        puVar9 = *(undefined8 **)(param_1 + 0x8d0);
        if (uVar5 != 0) {
          uVar8 = 0;
          bVar6 = false;
          do {
            if (*(int *)(puVar9 + uVar8) == *piVar7) {
              bVar6 = true;
              in_R10D = (int)uVar8;
            }
            uVar8 = uVar8 + 1;
          } while (uVar5 != uVar8);
          if (bVar6) {
            uVar1 = in_R10D + 1;
            lVar3 = (ulong)(uVar5 - uVar1) * 8;
            portMemMove(puVar9 + (in_R10D + 2),lVar3,puVar9 + uVar1,lVar3);
            puVar9 = (undefined8 *)((ulong)uVar1 * 8 + *(long *)(param_1 + 0x8d0));
          }
          else {
            puVar9 = puVar9 + uVar5;
          }
        }
        *puVar9 = *(undefined8 *)piVar7;
        *(int *)(param_1 + 0x8e0) = *(int *)(param_1 + 0x8e0) + 1;
        *(undefined1 *)(param_1 + 0x1e28) = 0;
        return 0;
      }
    }
LAB_00352c68:
    piVar7 = piVar7 + 2;
    if (piVar7 == piVar2) {
      return 0;
    }
  } while( true );
}


// ===== 00352da0 gpuBuildClassDB_IMPL =====

undefined8 gpuBuildClassDB_IMPL(long param_1)

{
  int *piVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  
  if (*(uint *)(param_1 + 0x8a0) == 0) {
    lVar8 = 0;
    uVar6 = 0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x898);
    piVar1 = piVar2 + (ulong)*(uint *)(param_1 + 0x8a0) * 2;
    uVar6 = 0;
    do {
      if (*piVar2 != -1) {
        uVar6 = (ulong)((int)uVar6 + (uint)(piVar2[1] != -0x4cc4eb00));
      }
      piVar2 = piVar2 + 2;
    } while (piVar2 != piVar1);
    lVar8 = uVar6 << 3;
  }
  nvDbg_Printf("src/kernel/gpu/gpu_resource_desc.c",0x43,"gpuBuildClassDB_IMPL",1,
               "NVRM: num class descriptors: 0x%x\n",uVar6);
  lVar3 = portMemAllocNonPaged(lVar8);
  if (lVar3 != 0) {
    portMemSet(lVar3,0,lVar8);
    if (*(int *)(param_1 + 0x8a0) != 0) {
      lVar8 = *(long *)(param_1 + 0x898);
      lVar4 = 0;
      uVar5 = 0;
      do {
        if ((*(int *)(lVar8 + lVar4 * 8) != -1) && (*(int *)(lVar8 + 4 + lVar4 * 8) != -0x4cc4eb00))
        {
          uVar7 = (ulong)uVar5;
          uVar5 = uVar5 + 1;
          *(undefined8 *)(lVar3 + uVar7 * 8) = *(undefined8 *)(lVar8 + lVar4 * 8);
        }
        lVar4 = lVar4 + 1;
      } while ((uint)lVar4 < *(uint *)(param_1 + 0x8a0));
    }
    *(long *)(param_1 + 0x8d0) = lVar3;
    *(int *)(param_1 + 0x8e0) = (int)uVar6;
    *(undefined8 *)(param_1 + 0x8d8) = 0;
    *(undefined1 *)(param_1 + 0x8e4) = 0;
    *(undefined1 *)(param_1 + 0x1e28) = 0;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/gpu_resource_desc.c",0x4c,"gpuBuildClassDB_IMPL",4,
               "NVRM: alloc failed: 0x%x\n",0x51);
  return 0x51;
}


// ===== 00352f20 gpuDestroyClassDB_IMPL =====

undefined8 gpuDestroyClassDB_IMPL(long param_1)

{
  portMemFree(*(undefined8 *)(param_1 + 0x8d0));
  portMemFree(*(undefined8 *)(param_1 + 0x8d8));
  *(undefined1 *)(param_1 + 0x1e28) = 0;
  return 0;
}


// ===== 00352f60 gpuIsClassSupported_IMPL =====

undefined8 gpuIsClassSupported_IMPL(long param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if (*(uint *)(param_1 + 0x8e0) != 0) {
    piVar2 = *(int **)(param_1 + 0x8d0);
    piVar1 = piVar2 + (ulong)*(uint *)(param_1 + 0x8e0) * 2;
    do {
      if (param_2 == *piVar2) {
        return 1;
      }
      piVar2 = piVar2 + 2;
    } while (piVar2 != piVar1);
  }
  return 0;
}


// ===== 00352fa0 gpuGetClassByClassId_IMPL =====

undefined8 gpuGetClassByClassId_IMPL(long param_1,int param_2,undefined8 *param_3)

{
  int *piVar1;
  int *piVar2;
  
  if (*(uint *)(param_1 + 0x8e0) != 0) {
    piVar2 = *(int **)(param_1 + 0x8d0);
    piVar1 = piVar2 + (ulong)*(uint *)(param_1 + 0x8e0) * 2;
    do {
      if (*piVar2 == param_2) {
        if (param_3 != (undefined8 *)0x0) {
          *param_3 = piVar2;
        }
        return 0;
      }
      piVar2 = piVar2 + 2;
    } while (piVar2 != piVar1);
  }
  return 0x1f;
}


// ===== 00352ff0 gpuGetClassByEngineAndClassId_IMPL =====

undefined8
gpuGetClassByEngineAndClassId_IMPL(long param_1,int param_2,int param_3,undefined8 *param_4)

{
  int *piVar1;
  int *piVar2;
  
  if (*(uint *)(param_1 + 0x8e0) != 0) {
    piVar2 = *(int **)(param_1 + 0x8d0);
    piVar1 = piVar2 + (ulong)*(uint *)(param_1 + 0x8e0) * 2;
    do {
      if ((*piVar2 == param_2) && (piVar2[1] == param_3)) {
        *param_4 = piVar2;
        return 0;
      }
      piVar2 = piVar2 + 2;
    } while (piVar2 != piVar1);
  }
  return 0xffff;
}


// ===== 00353040 gpuGetClassList_IMPL =====

undefined8 gpuGetClassList_IMPL(long param_1,uint *param_2,long param_3,int param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  char *pcVar5;
  uint *puVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  uint uVar10;
  char *pcVar11;
  uint uVar12;
  undefined4 local_48 [2];
  char *local_40 [2];
  
  lVar1 = *(long *)(param_1 + 0x8d0);
  if (*(char *)(param_1 + 0x8e4) != '\0') {
    puVar6 = *(uint **)(param_1 + 0x8d8);
    goto LAB_0035307d;
  }
  local_48[0] = 0x100;
  pcVar5 = (char *)portMemAllocNonPaged(0x100);
  if (pcVar5 == (char *)0x0) {
    puVar6 = (uint *)0x0;
    nvDbg_Printf("src/kernel/gpu/gpu_resource_desc.c",0xc0,"gpuGetSuppressedClassList",4);
  }
  else {
    iVar3 = osReadRegistryString(param_1,"SuppressClassList",pcVar5,local_48);
    if ((iVar3 == 0) && (*pcVar5 != '\0')) {
      pcVar11 = pcVar5;
      iVar3 = 0;
      do {
        iVar2 = iVar3;
        nvStrToL(pcVar11,local_40,0x10,0);
        iVar3 = iVar2 + 1;
        pcVar11 = local_40[0];
      } while (*local_40[0] != '\0');
      if (iVar3 != 0) {
        uVar10 = iVar2 + 2;
        puVar6 = (uint *)portMemAllocNonPaged((ulong)uVar10 << 2);
        if (puVar6 == (uint *)0x0) {
          nvDbg_Printf("src/kernel/gpu/gpu_resource_desc.c",0xe4,"gpuGetSuppressedClassList",4);
          portMemFree(pcVar5);
        }
        else {
          *puVar6 = uVar10;
          if (*pcVar5 != '\0') {
            uVar9 = 1;
            pcVar11 = pcVar5;
            do {
              uVar10 = nvStrToL(pcVar11,local_40,0x10,0);
              puVar6[uVar9] = uVar10;
              uVar9 = (ulong)((int)uVar9 + 1);
              pcVar11 = local_40[0];
            } while (*local_40[0] != '\0');
          }
          portMemFree(pcVar5);
        }
        goto LAB_003532d0;
      }
    }
    puVar6 = (uint *)0x0;
    portMemFree(pcVar5);
  }
LAB_003532d0:
  *(uint **)(param_1 + 0x8d8) = puVar6;
  *(undefined1 *)(param_1 + 0x8e4) = 1;
LAB_0035307d:
  uVar10 = 0;
  if (*(int *)(param_1 + 0x8e0) != 0) {
    lVar8 = 0;
    uVar12 = 0;
    iVar3 = 0;
    uVar10 = 0;
    do {
      if (param_4 == -0x4cc4eb00) goto LAB_003530d8;
      while( true ) {
        while (*(int *)(lVar1 + 4 + lVar8 * 8) != param_4) {
          lVar8 = lVar8 + 1;
          if (*(uint *)(param_1 + 0x8e0) <= (uint)lVar8) goto joined_r0x00353117;
        }
LAB_003530d8:
        uVar7 = *(uint *)(lVar1 + lVar8 * 8);
        if (puVar6 == (uint *)0x0) break;
        while( true ) {
          if (*puVar6 < 2) goto LAB_003530e1;
          puVar4 = puVar6 + 1;
          while (*puVar4 != uVar7) {
            puVar4 = puVar4 + 1;
            if (puVar6 + (ulong)(*puVar6 - 2) + 2 == puVar4) goto LAB_003530e1;
          }
          lVar8 = lVar8 + 1;
          if (*(uint *)(param_1 + 0x8e0) <= (uint)lVar8) goto joined_r0x00353117;
          if (param_4 != -0x4cc4eb00) break;
          uVar7 = *(uint *)(lVar1 + lVar8 * 8);
        }
      }
LAB_003530e1:
      if (uVar12 != uVar7) {
        if (param_3 != 0) {
          if (uVar10 < *param_2) {
            *(uint *)(param_3 + (ulong)uVar10 * 4) = uVar7;
          }
          else {
            iVar3 = 0x3a;
          }
        }
        uVar10 = uVar10 + 1;
        uVar12 = uVar7;
      }
      lVar8 = lVar8 + 1;
    } while ((uint)lVar8 < *(uint *)(param_1 + 0x8e0));
joined_r0x00353117:
    if (iVar3 != 0) {
      return 0x3a;
    }
  }
  *param_2 = uVar10;
  return 0;
}


// ===== 00353350 gpuAddClassToClassDBByEngTagClassId_IMPL =====

void gpuAddClassToClassDBByEngTagClassId_IMPL
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_2;
  _gpuAddClassToClassDBByEngTagClassId(param_1,&local_c,&local_10);
  return;
}


// ===== 00353380 gpuAddClassToClassDBByEngTag_IMPL =====

void gpuAddClassToClassDBByEngTag_IMPL(undefined8 param_1,undefined4 param_2)

{
  undefined4 local_c;
  
  local_c = param_2;
  _gpuAddClassToClassDBByEngTagClassId(param_1,&local_c,0);
  return;
}


// ===== 003533a0 gpuAddClassToClassDBByClassId_IMPL =====

void gpuAddClassToClassDBByClassId_IMPL(undefined8 param_1,undefined4 param_2)

{
  undefined4 local_c;
  
  local_c = param_2;
  _gpuAddClassToClassDBByEngTagClassId(param_1,0,&local_c);
  return;
}


// ===== 003533c0 gpuDeleteClassFromClassDBByClassId_IMPL =====

undefined8 gpuDeleteClassFromClassDBByClassId_IMPL(long param_1,int param_2)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x8e0) != 0) {
    lVar2 = 0;
    uVar3 = 0;
    do {
      piVar1 = (int *)(*(long *)(param_1 + 0x8d0) + lVar2 * 8);
      if (*piVar1 != param_2) {
        uVar4 = (ulong)uVar3;
        uVar3 = uVar3 + 1;
        *(undefined8 *)(*(long *)(param_1 + 0x8d0) + uVar4 * 8) = *(undefined8 *)piVar1;
      }
      lVar2 = lVar2 + 1;
    } while ((uint)lVar2 < *(uint *)(param_1 + 0x8e0));
  }
  *(uint *)(param_1 + 0x8e0) = uVar3;
  *(undefined1 *)(param_1 + 0x1e28) = 0;
  return 0;
}


// ===== 00353440 gpuDeleteClassFromClassDBByEngTag_IMPL =====

undefined8 gpuDeleteClassFromClassDBByEngTag_IMPL(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x8e0) != 0) {
    lVar2 = 0;
    uVar3 = 0;
    do {
      lVar1 = *(long *)(param_1 + 0x8d0);
      if (*(int *)(lVar1 + 4 + lVar2 * 8) != param_2) {
        uVar4 = (ulong)uVar3;
        uVar3 = uVar3 + 1;
        *(undefined8 *)(lVar1 + uVar4 * 8) = *(undefined8 *)(lVar1 + lVar2 * 8);
      }
      lVar2 = lVar2 + 1;
    } while ((uint)lVar2 < *(uint *)(param_1 + 0x8e0));
  }
  *(uint *)(param_1 + 0x8e0) = uVar3;
  *(undefined1 *)(param_1 + 0x1e28) = 0;
  return 0;
}


// ===== 003534b8 _gpuGetUserClientCount.cold =====

void _gpuGetUserClientCount_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003534d0 _gpuGetUserClientCount =====

int _gpuGetUserClientCount(undefined8 param_1,char param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  int iVar5;
  undefined1 local_30 [8];
  
  plVar4 = (long *)serverutilGetFirstClientUnderLock();
  if (plVar4 == (long *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    do {
      if (*plVar4 == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      lVar1 = *(long *)(*plVar4 + 0x100);
    } while ((((*(int *)(lVar1 + 0x4c) == 1) ||
              (iVar3 = deviceGetByGpu_IMPL(lVar1,param_1,1,local_30), iVar3 != 0)) ||
             (iVar5 = iVar5 + 1, param_2 != '\0')) &&
            (plVar4 = (long *)serverutilGetNextClientUnderLock(plVar4), plVar4 != (long *)0x0));
  }
  return iVar5;
}


// ===== 00353570 gpuSetExternalKernelClientCount_IMPL =====

undefined8 gpuSetExternalKernelClientCount_IMPL(long param_1,char param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3b24);
  if (param_2 != '\0') {
    *(int *)(param_1 + 0x3b24) = iVar1 + 1;
    return 0;
  }
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x3b24) = iVar1 + -1;
    return 0;
  }
  nvAssertFailedNoLog("pGpu->externalKernelClientCount > 0","src/kernel/gpu/gpu_rmapi.c",0x34);
  return 0x38;
}


// ===== 003535d0 gpuIsInUse_IMPL =====

undefined4 gpuIsInUse_IMPL(long param_1)

{
  int iVar1;
  
  iVar1 = _gpuGetUserClientCount(param_1,0);
  if (iVar1 == 0) {
    return CONCAT31((int3)((uint)*(int *)(param_1 + 0x3b24) >> 8),*(int *)(param_1 + 0x3b24) != 0);
  }
  return 1;
}


// ===== 00353610 gpuGetUserClientCount_IMPL =====

void gpuGetUserClientCount_IMPL(undefined8 param_1)

{
  _gpuGetUserClientCount(param_1,1);
  return;
}


// ===== 00353620 gpuGetByRef =====

undefined8 gpuGetByRef(long param_1,undefined1 *param_2,undefined8 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long local_38;
  long local_30 [2];
  
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = 0;
  }
  if (param_1 == 0) {
    return 0x1f;
  }
  lVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 8),__nvoc_class_def_GpuResource);
  if (((lVar2 == 0) || (*(long *)(lVar2 + 0xe0) == 0)) &&
     ((iVar1 = refFindAncestorOfType(param_1,0x4b01b3,local_30), iVar1 != 0 ||
      ((lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_GpuResource),
       lVar2 == 0 || (*(long *)(lVar2 + 0xe0) == 0)))))) {
    uVar3 = refFindAncestorOfType(param_1,&DAT_00e0ac20,&local_38);
    if ((int)uVar3 != 0) {
      return uVar3;
    }
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_GpuResource);
    if ((lVar2 == 0) || (*(long *)(lVar2 + 0xe0) == 0)) {
      return 0x57;
    }
  }
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = *(undefined1 *)(lVar2 + 0xf8);
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = *(undefined8 *)(lVar2 + 0xe0);
  }
  return 0;
}


// ===== 00353730 gpuGetByHandle =====

void gpuGetByHandle(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 local_20;
  
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
  }
  iVar1 = clientGetResourceRef_IMPL(param_1,param_2,&local_20);
  if (iVar1 == 0) {
    gpuGetByRef(local_20,param_3,param_4);
  }
  return;
}


// ===== 00353780 gpuRegisterSubdevice_IMPL =====

undefined8 gpuRegisterSubdevice_IMPL(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  long *plVar4;
  undefined8 uVar5;
  
  portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x3c50));
  uVar1 = *(uint *)(param_1 + 0x3c48);
  plVar4 = *(long **)(param_1 + 0x3c40);
  if (uVar1 != 0) {
    plVar3 = plVar4;
    do {
      if (*plVar3 == 0) {
        *plVar3 = param_2;
        uVar5 = 0;
        plVar3 = (long *)0x0;
        goto LAB_003537f7;
      }
      plVar3 = plVar3 + 1;
    } while (plVar4 + uVar1 != plVar3);
  }
  plVar3 = (long *)0x0;
  if (*(uint *)(param_1 + 0x3c4c) == uVar1) {
    if (plVar4 == (long *)0x0) {
      portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x3c50));
      plVar3 = (long *)portMemAllocNonPaged(0x100);
      if (plVar3 == (long *)0x0) {
        uVar5 = 0x51;
        goto LAB_003537f7;
      }
      portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x3c50));
      if (*(long *)(param_1 + 0x3c40) == 0) {
        *(long **)(param_1 + 0x3c40) = plVar3;
        uVar2 = 0x20;
        plVar3 = (long *)0x0;
        *(undefined4 *)(param_1 + 0x3c4c) = 0x20;
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x3c4c);
      }
    }
    else {
      portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x3c50));
      plVar3 = (long *)portMemAllocNonPaged(uVar1 << 4);
      if (plVar3 == (long *)0x0) {
        uVar5 = 0x51;
        goto LAB_003537f7;
      }
      if (uVar1 << 3 != 0) {
        portMemCopy(plVar3,uVar1 << 4,plVar4,uVar1 << 3);
      }
      portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x3c50));
      uVar2 = *(uint *)(param_1 + 0x3c4c);
      if (*(long **)(param_1 + 0x3c40) == plVar4) {
        uVar2 = uVar2 * 2;
        *(long **)(param_1 + 0x3c40) = plVar3;
        *(uint *)(param_1 + 0x3c4c) = uVar2;
        plVar3 = plVar4;
      }
    }
    uVar1 = *(uint *)(param_1 + 0x3c48);
    if (uVar2 <= uVar1) {
      uVar5 = 0x1a;
      nvAssertFailedNoLog("pGpu->numSubdeviceBackReferences < pGpu->maxSubdeviceBackReferences",
                          "src/kernel/gpu/gpu_rmapi.c",0x155);
      goto LAB_003537f7;
    }
    plVar4 = *(long **)(param_1 + 0x3c40);
  }
  *(uint *)(param_1 + 0x3c48) = uVar1 + 1;
  plVar4[uVar1] = param_2;
  uVar5 = 0;
LAB_003537f7:
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x3c50));
  portMemFree(plVar3);
  return uVar5;
}


// ===== 003539c0 gpuUnregisterSubdevice_IMPL =====

void gpuUnregisterSubdevice_IMPL(long param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  uint uVar3;
  ulong uVar4;
  
  if (*(long *)(param_1 + 0x3c50) == 0) {
    nvAssertFailedNoLog("GPU is not fully constructed!","src/kernel/gpu/gpu_rmapi.c",0x169);
    return;
  }
  portSyncSpinlockAcquire(*(long *)(param_1 + 0x3c50));
  if (*(uint *)(param_1 + 0x3c48) != 0) {
    plVar2 = *(long **)(param_1 + 0x3c40);
    uVar4 = 0;
    do {
      if (*plVar2 == param_2) {
        *plVar2 = 0;
        iVar1 = *(int *)(param_1 + 0x3c48);
        if (iVar1 + -1 != (int)uVar4) goto LAB_00353a36;
        plVar2 = (long *)(*(long *)(param_1 + 0x3c40) + uVar4 * 8);
        goto LAB_00353ad7;
      }
      uVar3 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar3;
      plVar2 = plVar2 + 1;
    } while (uVar3 != *(uint *)(param_1 + 0x3c48));
  }
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x3c50));
  nvAssertFailedNoLog("Subdevice not found!","src/kernel/gpu/gpu_rmapi.c",0x185);
  return;
  while( true ) {
    iVar1 = iVar1 + -1;
    plVar2 = plVar2 + -1;
    *(int *)(param_1 + 0x3c48) = iVar1;
    if (iVar1 == 0) break;
LAB_00353ad7:
    if (*plVar2 != 0) break;
  }
LAB_00353a36:
  portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x3c50));
  return;
}


// ===== 00353af0 gpuNotifySubDeviceEvent_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuNotifySubDeviceEvent_IMPL
                (long param_1,uint param_2,undefined8 param_3,uint param_4,uint param_5,
                short param_6)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  char cVar6;
  short sVar7;
  int iVar8;
  undefined4 uVar9;
  ulong uVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  int local_54;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar10 = threadStateGetCurrent(&local_50,param_1);
  if (((int)uVar10 == 0) && (uVar10 = local_50, (*(byte *)(local_50 + 0x3c) & 8) != 0)) {
    uVar10 = nvAssertFailedNoLog("!(pCurThread->flags & THREAD_STATE_FLAGS_IS_ISR_LOCKLESS)",
                                 "src/kernel/gpu/gpu_rmapi.c",0x284);
  }
  else if (param_2 < 199) {
    lVar15 = 0;
    if (*(int *)(param_1 + 0x3c48) != 0) {
      do {
        while ((portSyncSpinlockAcquire(*(undefined8 *)(param_1 + 0x3c50)),
               *(uint *)(param_1 + 0x3c48) <= (uint)lVar15 ||
               (lVar5 = *(long *)(*(long *)(param_1 + 0x3c40) + lVar15 * 8), lVar5 == 0))) {
          lVar15 = lVar15 + 1;
          uVar10 = portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x3c50));
          if (*(uint *)(param_1 + 0x3c48) <= (uint)lVar15) {
            return uVar10;
          }
        }
        LOCK();
        *(int *)(lVar5 + 0x350) = *(int *)(lVar5 + 0x350) + 1;
        UNLOCK();
        portSyncSpinlockRelease(*(undefined8 *)(param_1 + 0x3c50));
        plVar3 = *(long **)(lVar5 + 0x160);
        lVar11 = (**(code **)(*plVar3 + 0x28))(plVar3);
        uVar10 = 0;
        if (lVar11 == 0) goto LAB_00353cf0;
        lVar11 = *(long *)(param_1 + 0x1bc0);
        uVar14 = param_2;
        uVar2 = param_5;
        if (lVar11 == 0) {
LAB_00353c5a:
          uVar10 = (ulong)uVar14;
          lVar11 = lVar5 + uVar10 * 4;
          if (*(int *)(lVar11 + 0x354) != 0) {
            if ((*(int *)(lVar5 + 0x670) != 0) && (*(long *)(lVar5 + 0x678) != 0)) {
              notifyFillNotifierMemory(param_1,*(long *)(lVar5 + 0x678),uVar2,param_6,0,uVar14);
            }
            lVar13 = inotifyGetNotificationList_IMPL(plVar3);
            uVar10 = 0;
            if (lVar13 != 0) {
              uVar10 = (ulong)param_4;
              osEventNotificationWithInfo(param_1,lVar13,uVar14,uVar2,param_6,param_3);
            }
            if (*(int *)(lVar11 + 0x354) == 1) {
              *(undefined4 *)(lVar11 + 0x354) = 0;
            }
          }
        }
        else {
          uVar4 = *(undefined8 *)(*(long *)(lVar5 + 0x158) + 0xe8);
          cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,lVar11);
          if (cVar6 == '\0') goto LAB_00353c5a;
          iVar8 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,lVar11,uVar4,&local_48);
          if (iVar8 == 0) {
            if (param_2 == 0x25) {
              cVar6 = kmigmgrIsInstanceAttributionIdValid_IMPL(param_6);
              if ((cVar6 == '\0') ||
                 (sVar7 = kmigmgrGetAttributionIdFromMIGReference_IMPL(local_48,local_40),
                 param_6 == sVar7)) {
                if (param_5 < 0x8c) {
                  if (param_5 < 0x55) {
                    uVar1 = param_5 - 0x27;
                    if (uVar1 < 0x2e) {
                      uVar10 = 1L << ((byte)uVar1 & 0x3f);
                      if ((uVar10 & 0x7380000007) != 0) {
                        if (uVar1 < 3) {
                          iVar8 = param_5 - 0x1e;
                        }
                        else {
                          iVar8 = param_5 - 0x3a;
                          if (2 < param_5 - 0x46) {
                            iVar8 = param_5 - 0x3c;
                          }
                        }
                        goto LAB_00354290;
                      }
                      if ((uVar10 & 0x404000100) != 0) {
                        cVar6 = '&';
                        if ((param_5 != 0x41) && (cVar6 = '\'', param_5 != 0x49)) {
                          cVar6 = (param_5 != 0x2f) * '\x03' + '%';
                        }
                        goto LAB_00354002;
                      }
                      if ((uVar10 & 0x300020000000) != 0) {
                        iVar8 = param_5 - 0x35;
                        if (param_5 == 0x44) {
                          iVar8 = 0x1d;
                        }
                        goto LAB_00354393;
                      }
                    }
                    goto LAB_00353c5a;
                  }
                  uVar10 = 1L << ((char)param_5 + 0xabU & 0x3f);
                  if ((uVar10 & 0x7fe0000000001) == 0) {
                    if ((uVar10 & 0x3818) == 0) {
                      if ((uVar10 & 0x40000000000002) == 0) goto LAB_00353c5a;
                      cVar6 = (param_5 != 0x56) + '>';
                      uVar10 = kmigmgrIsEngineInInstance_IMPL
                                         (param_1,lVar11,cVar6,local_48,local_40);
                      if ((char)uVar10 != '\0') {
                        iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                          (param_1,lVar11,local_48,local_40,cVar6,&local_54);
                        if (iVar8 == 0) {
                          uVar14 = 0x25;
                          uVar2 = 0x8b;
                          if (local_54 == 0x3e) {
                            uVar2 = 0x56;
                          }
                          goto LAB_00353c5a;
                        }
                        uVar10 = nvAssertOkFailedNoLog
                                           (iVar8,
                                            "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                            ,"src/kernel/gpu/gpu_rmapi.c",0x215);
                      }
                    }
                    else {
                      iVar8 = param_5 - 0x38;
                      if (1 < param_5 - 0x58) {
                        iVar8 = param_5 - 0x3e;
                      }
LAB_00354393:
                      uVar10 = kmigmgrIsEngineInInstance_IMPL
                                         (param_1,lVar11,iVar8,local_48,local_40);
                      if ((char)uVar10 != '\0') {
                        iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                          (param_1,lVar11,local_48,local_40,iVar8,&local_54);
                        if (iVar8 == 0) {
                          if (local_54 == 0x1d) {
                            uVar14 = 0x25;
                            uVar2 = 0x44;
                          }
                          else if (local_54 - 0x1dU < 3) {
                            uVar14 = 0x25;
                            uVar2 = local_54 + 0x35;
                          }
                          else if (local_54 - 0x1dU < 5) {
                            uVar14 = 0x25;
                            uVar2 = local_54 + 0x38;
                          }
                          else {
                            uVar14 = 0x25;
                            uVar2 = local_54 + 0x3e;
                          }
                          goto LAB_00353c5a;
                        }
                        uVar10 = nvAssertOkFailedNoLog
                                           (iVar8,
                                            "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                            ,"src/kernel/gpu/gpu_rmapi.c",0x1f7);
                      }
                    }
                  }
                  else {
                    iVar8 = param_5 - 0x6b;
                    if (param_5 == 0x55) {
                      iVar8 = 0x12;
                    }
LAB_00354290:
                    uVar10 = kmigmgrIsEngineInInstance_IMPL(param_1,lVar11,iVar8,local_48,local_40);
                    if ((char)uVar10 != '\0') {
                      iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                        (param_1,lVar11,local_48,local_40,iVar8,&local_54);
                      if (iVar8 == 0) {
                        uVar2 = local_54 - 9;
                        if (uVar2 < 3) {
                          uVar14 = 0x25;
                          uVar2 = local_54 + 0x1e;
                        }
                        else if (uVar2 < 6) {
                          uVar14 = 0x25;
                          uVar2 = local_54 + 0x3a;
                        }
                        else if (uVar2 < 9) {
                          uVar14 = 0x25;
                          uVar2 = local_54 + 0x3c;
                        }
                        else if (uVar2 == 9) {
                          uVar14 = 0x25;
                          uVar2 = 0x55;
                        }
                        else {
                          uVar14 = 0x25;
                          uVar2 = local_54 + 0x6b;
                        }
                        goto LAB_00353c5a;
                      }
                      uVar10 = nvAssertOkFailedNoLog
                                         (iVar8,
                                          "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                          ,"src/kernel/gpu/gpu_rmapi.c",0x1e8);
                    }
                  }
                }
                else {
                  if (param_5 != 0x8e) goto LAB_00353c5a;
                  cVar6 = '(';
LAB_00354002:
                  uVar10 = kmigmgrIsEngineInInstance_IMPL(param_1,lVar11,cVar6,local_48,local_40);
                  if ((char)uVar10 != '\0') {
                    iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                      (param_1,lVar11,local_48,local_40,cVar6,&local_54);
                    if (iVar8 == 0) {
                      uVar14 = 0x25;
                      if (local_54 == 0x25) {
                        uVar2 = 0x2f;
                      }
                      else if (local_54 == 0x26) {
                        uVar2 = 0x41;
                      }
                      else {
                        uVar2 = 0x8e;
                        if (local_54 == 0x27) {
                          uVar2 = 0x49;
                        }
                      }
                      goto LAB_00353c5a;
                    }
                    uVar10 = nvAssertOkFailedNoLog
                                       (iVar8,
                                        "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                        ,"src/kernel/gpu/gpu_rmapi.c",0x206);
                  }
                }
              }
              else {
                uVar10 = nvCheckFailedNoLog(1,
                                            "kmigmgrGetAttributionIdFromMIGReference(ref) == rcInstanceAttributionId"
                                            ,"src/kernel/gpu/gpu_rmapi.c",0x1d6);
              }
            }
            else if ((param_2 - 0x92 < 7) || (param_2 == 0xc)) {
              uVar10 = kmigmgrIsEngineInInstance_IMPL
                                 (param_1,lVar11,param_2 - 0xb,local_48,local_40);
              if ((char)uVar10 != '\0') {
                iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                  (param_1,lVar11,local_48,local_40,param_2 - 0xb,&local_54);
                if (iVar8 == 0) {
                  if (local_54 == 1) {
                    uVar14 = 0xc;
                  }
                  else {
                    uVar14 = local_54 + 0x90;
                  }
                  goto LAB_00353c5a;
                }
                uVar10 = nvAssertOkFailedNoLog
                                   (iVar8,
                                    "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                    ,"src/kernel/gpu/gpu_rmapi.c",0x225);
              }
            }
            else if ((param_2 - 0xa6 < 10) || (param_2 - 0x17 < 10)) {
              uVar14 = param_2 - 0x17;
              if (0x20 < param_2) {
                uVar14 = param_2 - 0x9c;
              }
              uVar10 = kmigmgrIsEngineInInstance_IMPL(param_1,lVar11,uVar14 + 9,local_48,local_40);
              if ((char)uVar10 != '\0') {
                iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                  (param_1,lVar11,local_48,local_40,uVar14 + 9,&local_54);
                if (iVar8 == 0) {
                  if (local_54 - 9U < 10) {
                    uVar14 = local_54 + 0xe;
                  }
                  else {
                    uVar14 = local_54 + 0x93;
                  }
                  goto LAB_00353c5a;
                }
                uVar10 = nvAssertOkFailedNoLog
                                   (iVar8,
                                    "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                    ,"src/kernel/gpu/gpu_rmapi.c",0x234);
              }
            }
            else if (param_2 - 0xe < 8) {
              uVar10 = kmigmgrIsEngineInInstance_IMPL
                                 (param_1,lVar11,param_2 + 0xf,local_48,local_40);
              if ((char)uVar10 != '\0') {
                iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                  (param_1,lVar11,local_48,local_40,param_2 + 0xf,&local_54);
                if (iVar8 == 0) {
                  uVar14 = local_54 - 0xf;
                  goto LAB_00353c5a;
                }
                uVar10 = nvAssertOkFailedNoLog
                                   (iVar8,
                                    "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                    ,"src/kernel/gpu/gpu_rmapi.c",0x243);
              }
            }
            else if ((param_2 - 0x26 < 3) || (param_2 == 0xb7)) {
              uVar14 = 0x29;
              if (param_2 < 0x2a) {
                uVar14 = param_2;
              }
              uVar10 = kmigmgrIsEngineInInstance_IMPL(param_1,lVar11,uVar14 - 1,local_48,local_40);
              if ((char)uVar10 != '\0') {
                iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                  (param_1,lVar11,local_48,local_40,uVar14 - 1,&local_54);
                if (iVar8 == 0) {
                  if (local_54 - 0x25U < 3) {
                    uVar14 = local_54 + 1;
                  }
                  else {
                    uVar14 = local_54 + 0x8f;
                  }
                  goto LAB_00353c5a;
                }
                uVar10 = nvAssertOkFailedNoLog
                                   (iVar8,
                                    "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                    ,"src/kernel/gpu/gpu_rmapi.c",0x252);
              }
            }
            else {
              if ((param_2 != 0x99) && (param_2 != 0xb4)) goto LAB_00353c5a;
              cVar6 = (param_2 != 0x99) + '>';
              uVar10 = kmigmgrIsEngineInInstance_IMPL(param_1,lVar11,cVar6,local_48,local_40);
              if ((char)uVar10 != '\0') {
                iVar8 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                  (param_1,lVar11,local_48,local_40,cVar6,&local_54);
                if (iVar8 == 0) {
                  uVar14 = 0x99;
                  if (local_54 != 0x3e) {
                    uVar14 = 0xb4;
                  }
                  goto LAB_00353c5a;
                }
                uVar10 = nvAssertOkFailedNoLog
                                   (iVar8,
                                    "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
                                    ,"src/kernel/gpu/gpu_rmapi.c",0x261);
              }
            }
          }
          else {
            plVar12 = (long *)__nvoc_dynamicCast(**(undefined8 **)(*(long *)(lVar5 + 0x140) + 0x48),
                                                 __nvoc_class_def_RmClient);
            if (plVar12 == (long *)0x0) {
              uVar10 = nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/gpu_rmapi.c",0x1bf);
            }
            else {
              uVar9 = (**(code **)(*plVar12 + 0xd8))(plVar12);
              cVar6 = rmclientIsCapableOrAdmin_IMPL(plVar12,3,uVar9);
              if (cVar6 != '\0') goto LAB_00353c5a;
              uVar10 = nvCheckFailedNoLog(1,
                                          "rmclientIsCapableOrAdmin(pRmClient, NV_RM_CAP_SYS_SMC_MONITOR, privLevel)"
                                          ,"src/kernel/gpu/gpu_rmapi.c",0x1c7);
            }
          }
        }
LAB_00353cf0:
        LOCK();
        *(int *)(lVar5 + 0x350) = *(int *)(lVar5 + 0x350) + -1;
        UNLOCK();
        lVar15 = lVar15 + 1;
      } while ((uint)lVar15 < *(uint *)(param_1 + 0x3c48));
    }
  }
  else {
    uVar10 = nvAssertFailedNoLog("notifyIndex < NV2080_NOTIFIERS_MAXCOUNT",
                                 "src/kernel/gpu/gpu_rmapi.c",0x287);
  }
  return uVar10;
}


// ===== 00354620 gpuGspPluginTriggeredEvent_IMPL =====

void gpuGspPluginTriggeredEvent_IMPL(long param_1,int param_2,uint param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  undefined1 local_58 [40];
  undefined8 local_30;
  
  serverutilShareIter(local_58,"");
  if (9 < param_3) {
    nvAssertFailedNoLog("notifyIndex < NVA084_NOTIFIERS_MAXCOUNT","src/kernel/gpu/gpu_rmapi.c",0x2ed
                       );
    return;
  }
  do {
    cVar1 = serverutilShareIterNext(local_58);
    while( true ) {
      if (cVar1 == '\0') {
        return;
      }
      lVar2 = __nvoc_dynamicCast(local_30,__nvoc_class_def_NotifShare);
      if ((((lVar2 == 0) || (lVar2 = *(long *)(lVar2 + 0x98), lVar2 == 0)) ||
          (lVar3 = __nvoc_dynamicCast(lVar2,__nvoc_class_def_KernelHostVgpuDeviceApi), lVar3 == 0))
         || (((*(long *)(*(long *)(lVar3 + 0x158) + 0xe0) != param_1 ||
              (lVar3 = *(long *)(*(long *)(lVar3 + 0x178) + 0x98), lVar3 == 0)) ||
             ((*(int *)(lVar3 + 0x18) != param_2 ||
              (lVar2 = inotifyGetNotificationList_IMPL(lVar2), lVar2 == 0)))))) break;
      osEventNotification(param_1,lVar2,param_3,0,0);
      cVar1 = serverutilShareIterNext(local_58);
    }
  } while( true );
}


// ===== 0035473e gpuGetProcWithObject_IMPL.cold =====

void gpuGetProcWithObject_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00354760 gpuGetProcWithObject_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
gpuGetProcWithObject_IMPL
          (long param_1,int param_2,uint param_3,int *param_4,uint *param_5,long *param_6)

{
  undefined4 uVar1;
  long *plVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  int *piVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  undefined1 auVar12 [16];
  uint local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  long local_b0;
  undefined8 local_a8;
  long local_98;
  undefined1 local_90 [16];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  if (param_4 == (int *)0x0) {
    nvAssertFailedNoLog("(pPidArray != NULL)","src/kernel/gpu/gpu_rmapi.c",0x354);
  }
  else {
    if (param_5 != (uint *)0x0) {
      plVar7 = (long *)serverutilGetFirstClientUnderLock();
      if (plVar7 == (long *)0x0) {
        local_f0 = 0;
      }
      else {
        local_f0 = 0;
        do {
          uVar5 = (**(code **)(*(long *)*plVar7 + 0xd8))();
          plVar2 = (long *)*plVar7;
          if (plVar2 == (long *)0x0) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          lVar10 = plVar2[0x20];
          uVar1 = *(undefined4 *)(lVar10 + 0x48);
          if (uVar5 < 2) {
LAB_00354841:
            if (local_f0 != 0) {
              piVar8 = param_4;
              do {
                if ((int)plVar2[0x23] == *piVar8) goto LAB_003547e0;
                piVar8 = piVar8 + 1;
              } while (param_4 + local_f0 != piVar8);
            }
            iVar6 = deviceGetByGpu_IMPL(lVar10,param_1,1,&local_98);
            if (iVar6 == 0) {
              lVar9 = *(long *)(param_1 + 0x1bc0);
              if ((lVar9 != 0) && (*param_6 != 0)) {
                auVar12 = kmigmgrMakeNoMIGReference_IMPL();
                local_90 = auVar12;
                clientRefIter(&local_80,lVar10,0,&DAT_00e0ac20,0,1);
                do {
                  do {
                    cVar4 = clientRefIterNext(lVar10,&local_80);
                    if (cVar4 == '\0') goto LAB_003547e0;
                    local_98 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),
                                                  __nvoc_class_def_Device);
                  } while (*(long *)(*(long *)(local_98 + 0x128) + 0xe0) != param_1);
                  iVar6 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,lVar9,local_98,local_90);
                } while (((iVar6 != 0) || (*param_6 != local_90._0_8_)) ||
                        ((param_6[1] != 0 && (param_6[1] != local_90._8_8_))));
              }
              serverutilRefIter(&local_e8,uVar1,0,0,1,1);
              local_80 = local_e8;
              local_78 = local_e0;
              local_70 = local_d8;
              local_68 = local_d0;
              local_60 = local_c8;
              local_58 = local_c0;
              local_50 = local_b8;
              local_48 = local_b0;
              local_40 = local_a8;
              do {
                while( true ) {
                  do {
                    cVar4 = clientRefIterNext(local_60,&local_80);
                    lVar10 = local_48;
                    if (cVar4 == '\0') goto LAB_003547e0;
                    lVar9 = objDynamicCastById_IMPL(*(undefined8 *)(local_48 + 8),param_3);
                  } while (lVar9 == 0);
                  if (param_3 == 0x4b01b3) goto LAB_00354ae0;
                  if (0x4b01b3 < param_3) break;
                  if (param_3 == 0x22ce42) goto LAB_00354ae0;
                  if (param_3 != 0x43d7c4) {
                    return 0x1f;
                  }
                  lVar10 = __nvoc_dynamicCast(*(undefined8 *)(lVar10 + 8),
                                              __nvoc_class_def_ChannelDescendant);
                  if (lVar10 == 0) {
                    /* WARNING: Does not return */
                    pcVar3 = (code *)invalidInstructionException();
                    (*pcVar3)();
                  }
                  if ((*(int *)(*(long *)(*(long *)(lVar10 + 0x140) + 0x48) + 0x11c) == param_2) &&
                     (*(long *)(lVar10 + 0x178) != 0)) {
                    lVar10 = __nvoc_dynamicCast(*(long *)(lVar10 + 0x178),
                                                __nvoc_class_def_GpuResource);
                    if ((lVar10 != 0) && (*(long *)(*(long *)(lVar10 + 0xd0) + 0xe8) == local_98))
                    goto LAB_00354ae0;
                  }
                }
                if (param_3 != 0xb12d7d) {
                  if (param_3 != 0xe0ac20) {
                    return 0x1f;
                  }
                  break;
                }
                lVar10 = __nvoc_dynamicCast(*(undefined8 *)(lVar10 + 8),
                                            __nvoc_class_def_KernelHostVgpuDeviceApi);
              } while (*(long *)(*(long *)(*(long *)(lVar10 + 0x178) + 0x98) + 0x10) == 0);
LAB_00354ae0:
              if (plVar2[0x33] == 0) {
                param_4[local_f0] = (int)plVar2[0x23];
LAB_00354b0a:
                local_f0 = local_f0 + 1;
              }
              else {
                uVar11 = osFindNsPid();
                if ((int)uVar11 == 0) goto LAB_00354b0a;
                if ((int)uVar11 != 0x57) {
                  return uVar11;
                }
              }
              if (local_f0 == 0x3b6) {
                nvDbg_Printf("src/kernel/gpu/gpu_rmapi.c",0x3de,"gpuGetProcWithObject_IMPL",4,
                             "NVRM: Maximum PIDs reached. Returning.\n");
                break;
              }
            }
          }
          else {
            cVar4 = (**(code **)(*plVar2 + 0xe0))(plVar2,uVar5,*(code **)(*plVar2 + 0xe0));
            if (cVar4 == '\0') goto LAB_00354841;
          }
LAB_003547e0:
          plVar7 = (long *)serverutilGetNextClientUnderLock(plVar7);
        } while (plVar7 != (long *)0x0);
      }
      *param_5 = local_f0;
      return 0;
    }
    nvAssertFailedNoLog("(pPidArrayCount != NULL)","src/kernel/gpu/gpu_rmapi.c",0x355);
  }
  return 0x1f;
}


// ===== 00354c62 gpuFindClientInfoWithPidIterator_IMPL.cold =====

void gpuFindClientInfoWithPidIterator_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00354c70 gpuFindClientInfoWithPidIterator_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8
gpuFindClientInfoWithPidIterator_IMPL
          (long param_1,int param_2,int param_3,int param_4,long *param_5,undefined4 *param_6,
          long *param_7,char param_8)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  char cVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined1 auVar13 [16];
  undefined4 local_154;
  undefined4 local_140;
  long local_138;
  long local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  long local_e0;
  undefined8 local_d8;
  long local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  undefined1 local_80 [16];
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("(pid != 0)","src/kernel/gpu/gpu_rmapi.c",0x494);
  }
  else if (param_5 == (long *)0x0) {
    nvAssertFailedNoLog("(pData != NULL)","src/kernel/gpu/gpu_rmapi.c",0x495);
  }
  else {
    if (param_6 != (undefined4 *)0x0) {
      local_138 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
      plVar9 = (long *)serverutilGetFirstClientUnderLock();
      auVar13._8_8_ = local_80._8_8_;
      auVar13._0_8_ = local_80._0_8_;
      if (plVar9 == (long *)0x0) {
        local_140 = 0xffffffff;
        local_154 = 0xffffffff;
      }
      else {
        local_154 = 0xffffffff;
        local_140 = 0xffffffff;
        do {
          plVar2 = (long *)*plVar9;
          lVar12 = 0;
          if (plVar2 != (long *)0x0) {
            lVar12 = plVar2[0x20];
          }
          if (plVar2[0x33] == 0) {
            local_80._0_4_ = (undefined4)plVar2[0x23];
            if (param_3 != 0) goto LAB_00354d90;
LAB_00354d38:
            if (param_2 != local_80._0_4_) goto LAB_00354d40;
LAB_00354da3:
            local_80 = auVar13;
            uVar8 = (**(code **)(*plVar2 + 0xd8))(plVar2);
            uVar1 = *(undefined4 *)(lVar12 + 0x48);
            if (uVar8 < 2) {
LAB_00354de0:
              clientRefIter(&local_118,lVar12,0,&DAT_00e0ac20,0,1);
              local_c8 = local_118;
              local_c0 = local_110;
              local_b8 = local_108;
              local_b0 = local_100;
              local_a8 = local_f8;
              local_a0 = local_f0;
              local_98 = local_e8;
              local_90 = local_e0;
              local_88 = local_d8;
LAB_00354e80:
              do {
                cVar5 = clientRefIterNext(lVar12,&local_c8);
                auVar13 = local_80;
                if (cVar5 == '\0') goto LAB_00354d40;
                lVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_90 + 8),__nvoc_class_def_Device);
                if (*(long *)(*(long *)(lVar10 + 0x128) + 0xe0) == param_1) {
                  if (*(long *)(param_1 + 0x1bc0) != 0) {
                    cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
                    if (cVar5 != '\0') {
                      uVar3 = *(undefined8 *)(param_1 + 0x1bc0);
                      auVar13 = kmigmgrMakeNoMIGReference_IMPL();
                      local_80 = auVar13;
                      iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar3,lVar10,local_80);
                      if (iVar7 != 0) goto LAB_00354e80;
                      if (param_8 == '\0') {
                        cVar5 = kmigmgrAreMIGReferencesSame_IMPL(param_7,local_80);
                        if (cVar5 == '\0') goto LAB_00354e80;
                      }
                      local_140 = *(undefined4 *)(local_80._0_8_ + 0x968);
                      if (local_80._8_8_ != 0) {
                        local_154 = *(undefined4 *)(local_80._8_8_ + 0xc0);
                      }
                      cVar5 = kmigmgrIsMIGReferenceValid_IMPL(param_7);
                      if (cVar5 != '\0') {
                        local_138 = *(long *)(*param_7 + 0x980);
                      }
                    }
                  }
                  if (param_4 != 0x4789f2) {
                    return 0x1f;
                  }
                  iVar7 = *(int *)(*(long *)(*(long *)(lVar10 + 0x110) + 0x48) + 0x10);
                  cVar5 = *(char *)(*(long *)(param_1 + 0x4d8) + 0x80);
                  serverutilRefIter(&local_118,uVar1,0,0,1,1);
                  local_80._0_8_ = local_118;
                  local_80._8_8_ = local_110;
                  local_70 = local_108;
                  local_68 = local_100;
                  local_60 = local_f8;
                  local_58 = local_f0;
                  local_50 = local_e8;
                  local_48 = local_e0;
                  local_40 = local_d8;
LAB_00354fa0:
                  cVar6 = clientRefIterNext(local_60,local_80);
                  lVar10 = local_48;
                  if (cVar6 != '\0') {
                    lVar11 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),
                                                __nvoc_class_def_Memory);
                    if (((lVar11 != 0) &&
                        (((uVar8 = *(uint *)(lVar10 + 0x11c), cVar5 != '\0' &&
                          ((((uVar8 & 0xfffffffd) == 0x81 || (uVar8 == 0x3e)) &&
                           (*(int *)(lVar11 + 0xfc) == 0x3e)))) ||
                         (((uVar8 - 0x82 < 2 || (uVar8 == 0x40)) &&
                          (*(int *)(lVar11 + 0xfc) == 0x40)))))) &&
                       ((param_8 != '\0' || (local_138 == *(long *)(lVar11 + 0x110))))) {
                      if (*(long *)(lVar11 + 0xe0) == 0) {
                    /* WARNING: Does not return */
                        pcVar4 = (code *)invalidInstructionException();
                        (*pcVar4)();
                      }
                      if ((iVar7 == *(int *)(*(long *)(*(long *)(*(long *)(lVar11 + 0xe0) + 0x110) +
                                                      0x48) + 0x10)) &&
                         (lVar10 = *(long *)(lVar11 + 0x118), lVar10 != 0)) {
                        if (param_3 == 0) {
                          cVar6 = memdescGetFlag(lVar10,0x400000000);
                          if (cVar6 != '\0') goto LAB_00354fa0;
                        }
                        else {
                          cVar6 = memdescGetFlag(lVar10,0x100);
                          if ((cVar6 == '\0') || (*(int *)(lVar11 + 0x194) == 10))
                          goto LAB_00354fa0;
                        }
                        cVar6 = gpuIsCCorApmFeatureEnabled_IMPL(**(undefined8 **)(lVar11 + 0x118));
                        if ((cVar6 == '\0') || ((*(byte *)(lVar11 + 0x19b) & 1) == 0)) {
                          if (*(int *)(*(long *)(lVar11 + 0x118) + 0x94) == 1) {
                            *param_5 = *param_5 + *(long *)(lVar11 + 0x100);
                          }
                          else if (*(char *)(lVar11 + 0x120) == '\0') {
                            param_5[2] = param_5[2] + *(long *)(lVar11 + 0x100);
                          }
                          else {
                            param_5[1] = param_5[1] + *(long *)(lVar11 + 0x100);
                          }
                        }
                        else {
                          cVar6 = memdescGetFlag(*(long *)(lVar11 + 0x118),0x200000000000);
                          if (cVar6 != '\0') {
                            nvAssertFailedNoLog("!memdescGetFlag(pMemory->pMemDesc, MEMDESC_FLAGS_ALLOC_IN_UNPROTECTED_MEMORY)"
                                                ,"src/kernel/gpu/gpu_rmapi.c",0x446);
                          }
                          lVar10 = *(long *)(lVar11 + 0x100);
                          if (*(int *)(*(long *)(lVar11 + 0x118) + 0x94) == 1) {
                            *param_5 = *param_5 + lVar10;
                            param_5[3] = param_5[3] + *(long *)(lVar11 + 0x100);
                          }
                          else if (*(char *)(lVar11 + 0x120) == '\0') {
                            param_5[2] = param_5[2] + lVar10;
                            param_5[5] = param_5[5] + *(long *)(lVar11 + 0x100);
                          }
                          else {
                            param_5[1] = param_5[1] + lVar10;
                            param_5[4] = param_5[4] + *(long *)(lVar11 + 0x100);
                          }
                        }
                      }
                    }
                    goto LAB_00354fa0;
                  }
                }
              } while( true );
            }
            cVar5 = (**(code **)(*plVar2 + 0xe0))(plVar2,uVar8,*(code **)(*plVar2 + 0xe0));
            auVar13 = local_80;
            if (cVar5 == '\0') goto LAB_00354de0;
          }
          else {
            local_80 = auVar13;
            iVar7 = osFindNsPid(plVar2[0x33],local_80);
            auVar13 = local_80;
            if (iVar7 == 0) {
              if (param_3 == 0) goto LAB_00354d38;
LAB_00354d90:
              if ((param_2 == local_80._0_4_) && (param_3 == *(int *)((long)plVar2 + 0x11c)))
              goto LAB_00354da3;
            }
          }
LAB_00354d40:
          local_80 = auVar13;
          plVar9 = (long *)serverutilGetNextClientUnderLock(plVar9);
          auVar13 = local_80;
        } while (plVar9 != (long *)0x0);
      }
      *param_6 = local_154;
      param_6[1] = local_140;
      return 0;
    }
    nvAssertFailedNoLog("(pSmcInfo != NULL)","src/kernel/gpu/gpu_rmapi.c",0x496);
  }
  return 0x1f;
}


// ===== 00355380 gpuPowerManagementResume =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuPowerManagementResume(long param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong extraout_RDX_03;
  ulong extraout_RDX_04;
  undefined8 uVar8;
  ulong uVar9;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 local_3c;
  
  if (*(int *)(param_1 + 0x7e4) == 1) {
    return 0;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  if ((*(long *)(g_pSys + 0x208) != 0) && (iVar4 = clResumeBridge_IMPL(), iVar4 != 0)) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/gpu_suspend.c",0xb6);
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    if (*(char *)(param_1 + 0x908) == '\0') {
      uVar5 = gpuBootGspRmProxy_IMPL(param_1);
      uVar9 = (ulong)uVar5;
      if (uVar5 != 0) {
        nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x10b,"gpuPowerManagementResume",4,
                     "NVRM: GSP-RM proxy boot command failed during resume.\n");
        uVar7 = extraout_RDX_01;
        if (*(int *)(param_1 + 0x4b08) == 0) {
          *(undefined4 *)(param_1 + 0x4b08) = 5;
          *(uint *)(param_1 + 0x4b0c) = uVar5;
        }
        goto LAB_00355446;
      }
    }
  }
  else {
    (**(code **)(*(long *)(param_1 + 0x1b70) + 0x1d0))(param_1);
    lVar2 = *(long *)(param_1 + 0x1ba8);
    lVar3 = *(long *)(param_1 + 0x1b88);
    local_3c = 1;
    local_44 = param_2;
    local_40 = param_3;
    kgspPopulateGspRmInitArgs_IMPL(param_1,lVar2,&local_44);
    uVar5 = (**(code **)(lVar2 + 0x950))(param_1,lVar2);
    uVar9 = (ulong)uVar5;
    if (uVar5 != 0) {
      uVar7 = extraout_RDX_00;
      if (*(int *)(param_1 + 0x4b08) == 0) {
        *(undefined4 *)(param_1 + 0x4b08) = 1;
        *(uint *)(param_1 + 0x4b0c) = uVar5;
      }
      goto LAB_00355446;
    }
    uVar8 = 2;
    if (*(int *)(param_1 + 0x4b34) != 4) {
      uVar5 = kpmuInitLibosLoggingStructures_IMPL(param_1,*(undefined8 *)(param_1 + 0x1c28));
      uVar9 = (ulong)uVar5;
      if (uVar5 != 0) {
        nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0xe1,"gpuPowerManagementResume",4,
                     "NVRM: cannot init libOS PMU logging structures: 0x%x\n",uVar5);
        uVar7 = extraout_RDX_04;
        if (*(int *)(param_1 + 0x4b08) == 0) {
          *(undefined4 *)(param_1 + 0x4b08) = 2;
          *(uint *)(param_1 + 0x4b0c) = uVar5;
        }
        goto LAB_00355446;
      }
      (**(code **)(lVar3 + 400))(param_1,lVar3);
      uVar8 = 1;
      libosLogUpdateTimerDelta(lVar2 + 0xb50,*(undefined8 *)(lVar3 + 0x24f8));
    }
    uVar6 = (**(code **)(lVar2 + 0x828))(param_1,lVar2,uVar8);
    uVar9 = uVar6 & 0xffffffff;
    if ((int)uVar6 != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0xf4,"gpuPowerManagementResume",4,
                   "NVRM: GSP boot preparation failed at resume (bootMode 0x%x): 0x%x\n",uVar8,uVar6
                  );
      uVar7 = extraout_RDX_03;
      if (*(int *)(param_1 + 0x4b08) == 0) {
        *(undefined4 *)(param_1 + 0x4b08) = 3;
        *(int *)(param_1 + 0x4b0c) = (int)uVar6;
      }
      goto LAB_00355446;
    }
    uVar7 = (**(code **)(lVar2 + 0x830))(param_1,lVar2,uVar8);
    iVar4 = (int)uVar7;
    uVar9 = uVar7 & 0xffffffff;
    if (iVar4 != 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0xfd,"gpuPowerManagementResume",4,
                   "NVRM: GSP boot failed at resume (bootMode 0x%x): 0x%x\n",uVar8);
      if (*(int *)(param_1 + 0x4b08) == 0) {
        *(undefined4 *)(param_1 + 0x4b08) = 4;
        *(int *)(param_1 + 0x4b0c) = iVar4;
      }
      goto LAB_00355446;
    }
  }
  *(undefined1 *)(param_1 + 0x4aa) = 0;
  uVar8 = 5;
  if (*(int *)(param_1 + 0x4b34) == 4) {
    uVar8 = 0x25;
  }
  uVar5 = gpuStateLoad_IMPL(param_1,uVar8);
  uVar9 = (ulong)uVar5;
  if (uVar5 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x121,"gpuPowerManagementResume",2,
                 "NVRM: Adapter now in D0 state\n");
    uVar7 = extraout_RDX;
  }
  else {
    nvAssertOkFailedNoLog
              (uVar5,
               "gpuStateLoad(pGpu, IS_GPU_GC6_STATE_EXITING(pGpu) ? GPU_STATE_FLAGS_PRESERVING | GPU_STATE_FLAGS_PM_TRANSITION | GPU_STATE_FLAGS_GC6_TRANSITION : GPU_STATE_FLAGS_PRESERVING | GPU_STATE_FLAGS_PM_TRANSITION)"
               ,"src/kernel/gpu/gpu_suspend.c",0x119);
    uVar7 = extraout_RDX_02;
  }
LAB_00355446:
  if (*(int *)(param_1 + 0x4b34) != 4) {
    if (*(char *)(param_1 + 0x909) != '\0') {
      (**(code **)(*(long *)(param_1 + 0x1ba8) + 0x948))(param_1,*(long *)(param_1 + 0x1ba8),uVar7);
    }
    memmgrFreeFbsrMemory_KERNEL(param_1,uVar1);
    return uVar9;
  }
  return uVar9;
}


// ===== 003557c0 gpuPowerManagementEnter.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuPowerManagementEnter_isra_0(long param_1,undefined4 param_2)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  ulong extraout_RDX;
  undefined8 uVar5;
  ulong uVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  *(undefined4 *)(param_1 + 0x7e4) = 1;
  lVar2 = *(long *)(param_1 + 0x1ba8);
  iVar7 = *(int *)(param_1 + 0x4b34);
  if (*(char *)(param_1 + 0x909) != '\0') {
    if (iVar7 == 1) {
      *(undefined4 *)(param_1 + 0x7e4) = 2;
      uVar8 = 2;
      uVar5 = 0x25;
      goto LAB_0035584a;
    }
    uVar3 = (**(code **)(lVar2 + 0x940))(param_1,lVar2);
    if (uVar3 != 0) {
      if (*(int *)(param_1 + 0x4b08) != 0) {
        return (ulong)uVar3;
      }
      *(undefined4 *)(param_1 + 0x4b08) = 0x17;
      *(uint *)(param_1 + 0x4b0c) = uVar3;
      return (ulong)uVar3;
    }
    *(undefined4 *)(param_1 + 0x7e4) = 2;
    iVar7 = *(int *)(param_1 + 0x4b34);
  }
  uVar5 = 0x25;
  uVar8 = 1;
  if (iVar7 != 1) {
    uVar8 = 1;
    uVar5 = 5;
  }
LAB_0035584a:
  uVar3 = gpuStateUnload_IMPL(param_1,uVar5);
  if (uVar3 == 0) {
    *(undefined4 *)(param_1 + 0x7e4) = 3;
    *(undefined1 *)(param_1 + 0x4aa) = 1;
    if (*(char *)(param_1 + 0x909) == '\0') {
      return 0;
    }
    uVar4 = kgspUnloadRm_IMPL(param_1,lVar2,uVar8,param_2);
    if ((int)uVar4 == 0) {
      if (*(int *)(param_1 + 0x4b34) == 1) {
        return uVar4 & 0xffffffff;
      }
      kpmuFreeLibosLoggingStructures_IMPL(param_1,*(undefined8 *)(param_1 + 0x1c28));
      return uVar4 & 0xffffffff;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x7b,"gpuPowerManagementEnter",4,
                 "NVRM: GSP unload failed at suspend (bootMode 0x%x, newLevel 0x%x): 0x%x\n",uVar8,
                 param_2);
    uVar6 = uVar4 & 0xffffffff;
    if (*(int *)(param_1 + 0x4b08) == 0) {
      *(undefined4 *)(param_1 + 0x4b08) = 0x20;
      *(int *)(param_1 + 0x4b0c) = (int)uVar4;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar3,
               "gpuStateUnload(pGpu, IS_GPU_GC6_STATE_ENTERING(pGpu) ? GPU_STATE_FLAGS_PRESERVING | GPU_STATE_FLAGS_PM_TRANSITION | GPU_STATE_FLAGS_GC6_TRANSITION : GPU_STATE_FLAGS_PRESERVING | GPU_STATE_FLAGS_PM_TRANSITION)"
               ,"src/kernel/gpu/gpu_suspend.c",0x6b);
    uVar6 = (ulong)uVar3;
    uVar4 = extraout_RDX;
  }
  if (*(int *)(param_1 + 0x4b34) != 1) {
    memmgrFreeFbsrMemory_KERNEL(param_1,uVar1,uVar4);
  }
  return uVar6;
}


// ===== 003559c0 gpuEnterStandby_IMPL =====

undefined4 gpuEnterStandby_IMPL(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  char *pcVar5;
  
  lVar1 = *(long *)(g_pSys + 0x210);
  if (lVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x20c,"gpuEnterStandby_IMPL",1,
                 "NVRM: gpuPowerState NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_4 Requested\n");
    if (*(int *)(param_1 + 0x4b34) == 1) {
      nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x20e,"gpuEnterStandby_IMPL",2,
                   "NVRM: Beginning transition to %s\n",&DAT_00d29759);
      *(undefined1 *)(param_1 + 0x443) = 1;
      gpuNotifySubDeviceEvent_IMPL(param_1,0xc1,0,0,0,0);
      uVar2 = gpuPowerManagementEnter_isra_0(param_1,3);
      *(undefined1 *)(param_1 + 0x441) = 1;
      *(undefined1 *)(param_1 + 0x490d) = 1;
      goto LAB_00355b94;
    }
LAB_00355a2a:
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x20e,"gpuEnterStandby_IMPL",2,
                 "NVRM: Beginning transition to %s\n","APM Suspend");
    *(undefined1 *)(param_1 + 0x443) = 1;
    gpuNotifySubDeviceEvent_IMPL(param_1,0xc1,0,0,0,0);
    uVar2 = gpuPowerManagementEnter_isra_0(param_1,3);
    *(undefined1 *)(param_1 + 0x441) = 1;
    *(undefined1 *)(param_1 + 0x490d) = 1;
    if (lVar1 == 0) goto LAB_00355b94;
  }
  else {
    if (*(char *)(lVar1 + 0x48) == '\0') {
      nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x20c,"gpuEnterStandby_IMPL",1,
                   "NVRM: gpuPowerState NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_4 Requested\n");
      if (*(int *)(param_1 + 0x4b34) != 1) goto LAB_00355a2a;
      puVar4 = &DAT_00d29759;
      pcVar5 = "NVRM: Beginning transition to %s\n";
      uVar3 = 0x20e;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x205,"gpuEnterStandby_IMPL",1,
                   "NVRM: gpuPowerState NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_3 Requested\n");
      puVar4 = &DAT_00d29759;
      if (*(int *)(param_1 + 0x4b34) != 1) {
        puVar4 = &DAT_00d2975d;
      }
      pcVar5 = "NVRM: Beginning transition from D0 to %s\n";
      uVar3 = 0x207;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",uVar3,"gpuEnterStandby_IMPL",2,pcVar5,puVar4);
    *(undefined1 *)(param_1 + 0x443) = 1;
    gpuNotifySubDeviceEvent_IMPL(param_1,0xc1,0,0,0,0);
    uVar2 = gpuPowerManagementEnter_isra_0(param_1,3);
    *(undefined1 *)(param_1 + 0x441) = 1;
    *(undefined1 *)(param_1 + 0x490d) = 1;
  }
  if (*(char *)(lVar1 + 0x48) != '\0') {
    puVar4 = &DAT_00d29759;
    if (*(int *)(param_1 + 0x4b34) != 1) {
      puVar4 = &DAT_00d2975d;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x21d,"gpuEnterStandby_IMPL",2,
                 "NVRM: Ending transition from D0 to %s\n",puVar4);
    return uVar2;
  }
LAB_00355b94:
  pcVar5 = "GC6";
  if (*(int *)(param_1 + 0x4b34) != 1) {
    pcVar5 = "APM Suspend";
  }
  nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x222,"gpuEnterStandby_IMPL",2,
               "NVRM: Ending transition to %s\n",pcVar5);
  return uVar2;
}


// ===== 00355cc0 gpuResumeFromStandby_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 gpuResumeFromStandby_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined *puVar6;
  undefined8 uVar7;
  
  lVar1 = *(long *)(g_pSys + 0x210);
  if ((lVar1 == 0) || (*(char *)(lVar1 + 0x48) == '\0')) {
    uVar7 = 4;
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x23c,"gpuResumeFromStandby_IMPL",1,
                 "NVRM: gpuPowerState Transitioning from NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_4\n"
                );
    pcVar5 = "GC6";
    if (*(int *)(param_1 + 0x4b34) != 4) {
      pcVar5 = "APM Suspend";
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x23e,"gpuResumeFromStandby_IMPL",2,
                 "NVRM: Beginning resume from %s\n",pcVar5);
  }
  else {
    uVar7 = 3;
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x234,"gpuResumeFromStandby_IMPL",1,
                 "NVRM: gpuPowerState Transitioning from NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_3\n"
                );
    puVar6 = &DAT_00d29759;
    if (*(int *)(param_1 + 0x4b34) != 4) {
      puVar6 = &DAT_00d2975d;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x236,"gpuResumeFromStandby_IMPL",2,
                 "NVRM: Beginning transition from %s to D0\n",puVar6);
  }
  *(undefined1 *)(param_1 + 0x444) = 1;
  if (*(char *)(param_1 + 0x4910) == '\0') {
    lVar2 = *(long *)(param_1 + 7000);
    iVar4 = kbifPollDeviceOnBus_IMPL(param_1);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(lVar2 + 0x1c0))(param_1);
      if (iVar4 == 0) goto LAB_00355d72;
      nvAssertOkFailedNoLog
                (iVar4,"kbifPollBarFirewallDisengage_HAL(pGpu, pKernelBif)",
                 "src/kernel/gpu/gpu_suspend.c",0x150);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar4,"kbifPollDeviceOnBus(pGpu, pKernelBif)","src/kernel/gpu/gpu_suspend.c",0x14a)
      ;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x247,"gpuResumeFromStandby_IMPL",4,
                 "NVRM: Polling BAR0 or BAR firewall timeout\n");
  }
  else {
LAB_00355d72:
    if (*(int *)(param_1 + 0x4b34) == 4) {
      gpuCheckGc6inD3Hot_IMPL(param_1);
    }
  }
  uVar3 = gpuPowerManagementResume(param_1,uVar7,8);
  *(undefined1 *)(param_1 + 0x441) = 0;
  *(undefined1 *)(param_1 + 0x490d) = 0;
  *(undefined2 *)(param_1 + 0x443) = 0;
  *(undefined4 *)(param_1 + 0x7e4) = 0;
  if ((lVar1 == 0) || (*(char *)(lVar1 + 0x48) == '\0')) {
    pcVar5 = "GC6";
    if (*(int *)(param_1 + 0x4b34) != 4) {
      pcVar5 = "APM Suspend";
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x25b,"gpuResumeFromStandby_IMPL",2,
                 "NVRM: Ending resume from %s\n",pcVar5);
  }
  else {
    puVar6 = &DAT_00d29759;
    if (*(int *)(param_1 + 0x4b34) != 4) {
      puVar6 = &DAT_00d2975d;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x256,"gpuResumeFromStandby_IMPL",2,
                 "NVRM: Ending transition from %s to D0\n",puVar6);
  }
  gpuNotifySubDeviceEvent_IMPL(param_1,0xc2,0,0,0,0);
  return uVar3;
}


// ===== 00355f90 gpuEnterHibernate_IMPL =====

undefined4 gpuEnterHibernate_IMPL(long param_1)

{
  undefined4 uVar1;
  
  if ((*(long *)(g_pSys + 0x210) == 0) || (*(char *)(*(long *)(g_pSys + 0x210) + 0x48) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x272,"gpuEnterHibernate_IMPL",1,
                 "NVRM: gpuPowerState NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_4 Requested\n");
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x274,"gpuEnterHibernate_IMPL",2,
                 "NVRM: Beginning APM Suspend\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x26c,"gpuEnterHibernate_IMPL",1,
                 "NVRM: gpuPowerState NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_7 Requested\n");
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x26e,"gpuEnterHibernate_IMPL",2,
                 "NVRM: Beginning transition from D0 to D4\n");
  }
  *(undefined1 *)(param_1 + 0x443) = 1;
  gpuNotifySubDeviceEvent_IMPL(param_1,0xc1,0,0,0,0);
  uVar1 = gpuPowerManagementEnter_isra_0(param_1,7);
  nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x27d,"gpuEnterHibernate_IMPL",1,
               "NVRM: gpuPowerState Saving clocks and throttling them down\n");
  *(undefined1 *)(param_1 + 0x442) = 1;
  nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x282,"gpuEnterHibernate_IMPL",2,
               "NVRM: Ending transition from D0 to D4\n");
  return uVar1;
}


// ===== 003560f0 gpuResumeFromHibernate_IMPL =====

undefined4 gpuResumeFromHibernate_IMPL(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(g_pSys + 0x210);
  nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x28d,"gpuResumeFromHibernate_IMPL",1,
               "NVRM: gpuPowerState Transitioning from NV2080_CTRL_GPU_SET_POWER_STATE_GPU_LEVEL_7\n"
              );
  nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x28f,"gpuResumeFromHibernate_IMPL",2,
               "NVRM: Beginning transition from D4 to D0\n");
  *(undefined1 *)(param_1 + 0x444) = 1;
  uVar2 = gpuPowerManagementResume(param_1,7,0x10);
  *(undefined1 *)(param_1 + 0x444) = 0;
  *(undefined4 *)(param_1 + 0x7e4) = 0;
  *(undefined2 *)(param_1 + 0x442) = 0;
  if ((lVar1 == 0) || (*(char *)(lVar1 + 0x48) == '\0')) {
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x2a2,"gpuResumeFromHibernate_IMPL",2,
                 "NVRM: End resuming from APM Suspend\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gpu_suspend.c",0x29e,"gpuResumeFromHibernate_IMPL",2,
                 "NVRM: Ending transition from D4 to D0\n");
  }
  gpuNotifySubDeviceEvent_IMPL(param_1,0xc2,0,0,0,0);
  return uVar2;
}


// ===== 00356220 gpuGetNameString_T234D =====

undefined8 gpuGetNameString_T234D(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_e;
  undefined2 local_a;
  
  local_e = 0x34333254;
  local_a = 0x44;
  portStringCopy(param_2,0x40,&local_e,6);
  return 0;
}


// ===== 00356260 gpuGetShortNameString_T234D =====

undefined8 gpuGetShortNameString_T234D(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_e;
  undefined2 local_a;
  
  local_e = 0x34333254;
  local_a = 0x44;
  portStringCopy(param_2,0x40,&local_e,6);
  return 0;
}


// ===== 003562a0 _checkTimeout =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _checkTimeout(ulong *param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong local_20 [2];
  
  uVar1 = (uint)param_1[1];
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x10) == 0) {
      if ((uVar1 & 0x20) == 0) {
        if ((uVar1 & 0x80) == 0) {
          nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0x1ca,"_checkTimeout",4,
                       "NVRM: Invalid timeout flags 0x%08x\n");
          return 0x40;
        }
        uVar3 = param_1[2];
        if (uVar3 == 0) {
          nvAssertFailedNoLog("pTimeout->pTmrGpu != NULL","src/kernel/gpu/gpu_timeout.c",0x1b5);
          return 0x40;
        }
        if ((*(char *)(uVar3 + 0x44c) != '\0') && (*(char *)(uVar3 + 0x450) == '\0')) {
          lVar2 = *(long *)(uVar3 + 0x1b88);
          if (lVar2 == 0) {
            nvAssertFailedNoLog("pTmr != NULL","src/kernel/gpu/gpu_timeout.c",0x1ba);
            return 0x40;
          }
          (**(code **)(lVar2 + 0x180))(lVar2,5000);
          uVar3 = *param_1;
          uVar4 = 5;
          if (uVar3 < 6) {
            uVar4 = uVar3;
          }
          *param_1 = uVar3 - uVar4;
          if (uVar3 - uVar4 != 0) {
            return uVar1 & 0x20;
          }
          if ((param_1[1] & 0x40) == 0) {
            nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0x1c3,"_checkTimeout",1,
                         "NVRM: ptmr timeout == 0\n");
          }
        }
      }
      else {
        uVar3 = param_1[2];
        if (uVar3 == 0) {
          nvAssertFailedNoLog("pTimeout->pTmrGpu != NULL","src/kernel/gpu/gpu_timeout.c",0x19f);
          return 0x40;
        }
        if ((*(char *)(uVar3 + 0x44c) != '\0') && (*(char *)(uVar3 + 0x450) == '\0')) {
          lVar2 = *(long *)(uVar3 + 0x1b88);
          if (lVar2 == 0) {
            nvAssertFailedNoLog("pTmr != NULL","src/kernel/gpu/gpu_timeout.c",0x1a4);
            return 0x40;
          }
          (**(code **)(lVar2 + 0x180))(lVar2,5000);
          tmrGetCurrentTime_IMPL(lVar2,local_20);
          if (local_20[0] < *param_1) {
            return 0;
          }
          if ((param_1[1] & 0x40) == 0) {
            nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0x1ad,"_checkTimeout",4,
                         "NVRM: ptmr elapsed %llx >= %llx\n",local_20[0],*param_1);
          }
        }
      }
    }
    else {
      osDelayUs(100);
      uVar3 = *param_1;
      if ((param_1[2] == 0) || (*(char *)(param_1[2] + 0x446) == '\0')) {
        uVar4 = 100;
        if (uVar3 < 0x65) {
          uVar4 = uVar3;
        }
      }
      else {
        uVar4 = 100000;
        if (uVar3 < 0x186a1) {
          uVar4 = uVar3;
        }
      }
      *param_1 = uVar3 - uVar4;
      if (uVar3 - uVar4 != 0) {
        return uVar1 & 8;
      }
      if ((param_1[1] & 0x40) == 0) {
        nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0x198,"_checkTimeout",1,
                     "NVRM: OS timeout == 0\n");
      }
    }
  }
  else {
    uVar3 = osGetMonotonicTimeNs();
    if (uVar3 < *param_1) {
      return 0;
    }
    if ((param_1[1] & 0x40) == 0) {
      nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0x176,"_checkTimeout",1,
                   "NVRM: OS elapsed %llx >= %llx\n",uVar3,*param_1);
    }
  }
  return 0x65;
}


// ===== 003565d0 timeoutInitializeGpuDefault =====

void timeoutInitializeGpuDefault(char *param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 local_1c;
  
  *(long *)(param_1 + 0x20) = param_2;
  osGetTimeoutParams(param_2,&local_1c,param_1 + 0x18,param_1 + 0x14);
  if (*param_1 == '\0') {
    *(undefined4 *)(param_1 + 8) = local_1c;
    *(undefined4 *)(param_1 + 4) = local_1c;
    param_1[1] = '\0';
  }
  if (((*(char *)(param_2 + 0x908) == '\0') && (*(char *)(param_2 + 0x909) == '\0')) &&
     (*(char *)(param_2 + 0x45a) == '\0')) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    param_1[0x14] = '\b';
    param_1[0x15] = '\0';
    param_1[0x16] = '\0';
    param_1[0x17] = '\0';
    uVar1 = 8;
  }
  if (param_1[1] == '\0') {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) * *(int *)(param_2 + 0x1b08);
    param_1[1] = '\x01';
  }
  if (param_1[0xc] == '\0') {
    param_1[0x10] = '\n';
    param_1[0x11] = '\0';
    param_1[0x12] = '\0';
    param_1[0x13] = '\0';
  }
  threadStateInitTimeout(param_2,*(undefined4 *)(param_1 + 4),uVar1);
  threadStateResetTimeout(param_2);
  return;
}


// ===== 00356690 timeoutRegistryOverride =====

void timeoutRegistryOverride(undefined1 *param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint local_1c;
  
  local_1c = 0;
  iVar2 = osReadRegistryDword(param_2,"RmOverrideInternalTimeoutsMs",&local_1c);
  if (iVar2 == 0) {
    *(uint *)(param_2 + 0x1b18) = local_1c;
    if (-1 < (int)local_1c) goto LAB_003566d1;
    local_1c = local_1c & 0xffffff;
  }
  else {
    *(undefined4 *)(param_2 + 0x1b18) = 0;
LAB_003566d1:
    iVar2 = osReadRegistryDword(param_2,"RmDefaultTimeout",&local_1c);
    if ((iVar2 != 0) || (local_1c == 0)) {
      cVar1 = *(char *)(param_2 + 0x490e);
      goto joined_r0x003567db;
    }
  }
  if (local_1c < 0x418938) {
    *(uint *)(param_1 + 4) = local_1c * 1000;
    *(uint *)(param_1 + 8) = local_1c * 1000;
  }
  else {
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
  }
  *param_1 = 1;
  nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0xa1,"timeoutRegistryOverride",4,
               "NVRM: Overriding default timeout to 0x%08x\n",*(undefined4 *)(param_1 + 4));
  cVar1 = *(char *)(param_2 + 0x490e);
joined_r0x003567db:
  if (((cVar1 != '\0') &&
      (iVar2 = osReadRegistryDword(param_2,"RmResetFsmStateTimeoutUs",&local_1c), iVar2 == 0)) &&
     (10 < local_1c)) {
    *(uint *)(param_1 + 0x10) = local_1c;
    param_1[0xc] = 1;
    nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0xae,"timeoutRegistryOverride",4,
                 "NVRM: Overriding default timeout for reset FSM state transition to 0x%08x\n",
                 *(undefined4 *)(param_1 + 0x10));
  }
  iVar2 = osReadRegistryDword(param_2,"RmDefaultTimeoutFlags",&local_1c);
  if (iVar2 == 0) {
    if (local_1c == 4) {
      *(undefined4 *)(param_1 + 0x14) = 8;
      uVar3 = 8;
    }
    else if (local_1c == 8) {
      *(undefined4 *)(param_1 + 0x14) = 0x10;
      uVar3 = 0x10;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",199,"timeoutRegistryOverride",4,
                   "NVRM: Unknown TIMEOUT_FLAGS value: 0x%08x\n");
      nvAssertFailedNoLog(&DAT_00d29e65,"src/kernel/gpu/gpu_timeout.c",0xc9);
      uVar3 = *(undefined4 *)(param_1 + 0x14);
    }
    nvDbg_Printf("src/kernel/gpu/gpu_timeout.c",0xcd,"timeoutRegistryOverride",4,
                 "NVRM: Overriding default flags to 0x%08x\n",uVar3);
  }
  return;
}


// ===== 003568e0 timeoutSet =====

void timeoutSet(long param_1,ulong *param_2,uint param_3,uint param_4)

{
  ulong uVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  ulong uVar9;
  long lVar10;
  
  uVar9 = (ulong)param_3;
  uVar1 = *(ulong *)(param_1 + 0x20);
  portMemSet(param_2,0,0x18);
  *(uint *)(param_2 + 1) = param_4;
  if (((param_4 == 0) || ((param_4 & 1) != 0)) || ((param_4 & 0xb8) == 0)) {
    param_4 = param_4 | *(uint *)(param_1 + 0x14);
    *(uint *)(param_2 + 1) = param_4;
  }
  if ((param_3 == 0) && (uVar9 = (ulong)*(uint *)(param_1 + 4), (param_4 & 4) == 0)) {
    if ((param_4 & 0x18) != 0) {
      param_4 = param_4 | 2;
      *(uint *)(param_2 + 1) = param_4;
      goto LAB_0035693a;
    }
    lVar10 = uVar9 * 1000;
  }
  else {
LAB_0035693a:
    lVar10 = uVar9 * 1000;
    if ((param_4 & 8) != 0) {
      if ((*(char *)(uVar1 + 0x909) != '\0') && (*(char *)(uVar1 + 0x4910) != '\0')) {
        lVar10 = uVar9 * 10000;
      }
      lVar3 = osGetMonotonicTickResolutionNs();
      lVar4 = osGetMonotonicTimeNs();
      param_2[2] = 0;
      *param_2 = lVar10 + lVar3 + lVar4;
      return;
    }
  }
  if ((param_4 & 0xa0) == 0) {
    param_2[2] = 0;
LAB_00356a0b:
    *param_2 = uVar9;
    return;
  }
  uVar7 = 0x133;
  pcVar8 = "pGpu != NULL";
  if (uVar1 != 0) {
    uVar5 = gpumgrGetParentGPU(uVar1,"src/kernel/gpu/gpu_timeout.c",0x133);
    uVar6 = gpumgrGetParentGPU(uVar1);
    if ((uVar1 != uVar6) &&
       (((cVar2 = gpuIsGpuFullPower_IMPL(uVar5), cVar2 != '\0' ||
         (uVar6 = uVar1, *(char *)(uVar5 + 0x444) != '\0')) &&
        (uVar6 = uVar5, *(char *)(uVar5 + 0x44f) != '\0')))) {
      uVar6 = uVar1;
    }
    param_2[2] = uVar6;
    if (*(long *)(uVar6 + 0x1b88) != 0) {
      if ((param_2[1] & 0x20) != 0) {
        tmrGetCurrentTime_IMPL(*(long *)(uVar6 + 0x1b88),param_2);
        *param_2 = *param_2 + lVar10;
        return;
      }
      goto LAB_00356a0b;
    }
    uVar7 = 0x149;
    pcVar8 = "pTmr != NULL";
  }
  nvAssertFailedNoLog(pcVar8,"src/kernel/gpu/gpu_timeout.c",uVar7);
  return;
}


// ===== 00356ad0 timeoutCheck =====

int timeoutCheck(long param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 unaff_retaddr;
  
  lVar1 = *(long *)(param_1 + 0x20);
  if (param_2 == 0) {
    nvAssertFailedNoLog("pTimeout != NULL","src/kernel/gpu/gpu_timeout.c",0x1e1);
  }
  if (lVar1 != 0) {
    if (*(char *)(lVar1 + 0x44f) != '\0') {
      return 0x65;
    }
    if (*(char *)(lVar1 + 0x450) != '\0') {
      return 0x65;
    }
    if (*(char *)(lVar1 + 0x451) != '\0') {
      return 0x65;
    }
    if (*(char *)(lVar1 + 0x461) != '\0') {
      return 0x65;
    }
  }
  uVar3 = *(uint *)(param_2 + 8);
  if ((uVar3 & 0x100) == 0) {
    threadStateYieldCpuIfNecessary(lVar1,uVar3 >> 6 & 1);
    uVar3 = *(uint *)(param_2 + 8);
  }
  iVar2 = 0;
  if ((uVar3 & 2) == 0) {
    iVar2 = _checkTimeout(param_2);
    uVar3 = *(uint *)(param_2 + 8);
    if (iVar2 == 0x65) {
      *(uint *)(param_2 + 8) = uVar3 | 0x40000000;
      threadPriorityThrottle();
      goto LAB_00356b8e;
    }
  }
  if ((uVar3 & 4) == 0) {
    iVar2 = threadStateCheckTimeout(lVar1,0);
    if (iVar2 == 0x65) {
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x80000000;
      threadPriorityThrottle();
    }
    else {
      if (((iVar2 == 0) || ((*(byte *)(param_2 + 8) & 2) == 0)) ||
         (iVar2 = _checkTimeout(param_2), iVar2 != 0x65)) goto LAB_00356b66;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x40000000;
      threadPriorityThrottle();
    }
LAB_00356b8e:
    if ((*(byte *)(param_2 + 8) & 0x40) == 0) {
      threadStateLogTimeout(lVar1,unaff_retaddr,param_3);
    }
    return 0x65;
  }
LAB_00356b66:
  threadPriorityThrottle();
  return iVar2;
}


// ===== 00356c50 timeoutCondWait =====

/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */

int timeoutCondWait(long param_1,undefined1 *param_2,code *param_3,undefined8 param_4,
                   undefined4 param_5)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  undefined1 *local_60;
  undefined1 local_50 [32];
  
  uVar1 = *(undefined8 *)(param_1 + 0x20);
  local_60 = param_2;
  if (param_2 == (undefined1 *)0x0) {
    timeoutSet(param_1,local_50,0,0);
    local_60 = local_50;
  }
  do {
    cVar2 = (*param_3)(uVar1,param_4);
    if (cVar2 != '\0') {
      return 0;
    }
    osSpinLoop();
    iVar3 = timeoutCheck(param_1,local_60,param_5);
  } while (iVar3 == 0);
  if (iVar3 == 0x65) {
    cVar2 = (*param_3)(uVar1,param_4);
    if (cVar2 != '\0') {
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ===== 00356d00 _gpushareddataSendDataPollRpc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _gpushareddataSendDataPollRpc(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  long local_38;
  uint local_30;
  
  if (param_3 == 0) {
    return 0x1f;
  }
  if (param_3 < 100) {
    nvAssertFailedNoLog("pollingIntervalMs >= NV_REG_STR_RM_RUSD_POLLING_INTERVAL_MIN",
                        "src/kernel/gpu/gpu_user_shared_data.c",0x1d7);
  }
  if (*(uint *)(param_1 + 0x3c88) < param_3) {
    nvAssertFailedNoLog("pollingIntervalMs <= pGpu->userSharedData.defaultPollingIntervalMs",
                        "src/kernel/gpu/gpu_user_shared_data.c",0x1d8);
  }
  if (*(int *)(param_1 + 0x3c84) == 2) {
    param_2 = -1;
  }
  if ((*(long *)(param_1 + 0x3c78) == param_2) && (*(uint *)(param_1 + 0x3c8c) == param_3)) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/gpu_user_shared_data.c",0x1ea,"_gpushareddataSendDataPollRpc",1,
               "NVRM: RUSD polledDataMask: 0x%llx, pollingIntervalMs: %u\n",param_2,param_3);
  portMemSet(&local_38,0,0x10);
  local_38 = param_2;
  local_30 = param_3;
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800aff,&local_38,0x10);
  if ((uVar1 & 0xffffffef) == 0) {
    if (uVar1 != 0x10) {
      *(long *)(param_1 + 0x3c78) = param_2;
      *(uint *)(param_1 + 0x3c8c) = param_3;
      return 0;
    }
  }
  else {
    nvCheckFailedNoLog(4,"(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                       "src/kernel/gpu/gpu_user_shared_data.c",0x1f7);
  }
  return uVar1;
}


// ===== 00356e90 _handlePollMaskHelper =====

ulong _handlePollMaskHelper(long param_1,byte param_2,byte param_3)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong local_88;
  undefined1 local_80 [32];
  undefined8 local_60;
  long local_48;
  
  iVar1 = *(int *)(param_1 + 0x3c8c);
  uVar8 = *(uint *)(param_1 + 0x3c88);
  local_88 = 0;
  if (uVar8 == 0) {
    nvAssertFailedNoLog("pollingIntervalMs != 0","src/kernel/gpu/gpu_user_shared_data.c",0x243);
  }
  if ((param_3 & param_2) != 0) {
    nvAssertFailedNoLog("!(bPermanentRequest && bPollingIntervalRequested)",
                        "src/kernel/gpu/gpu_user_shared_data.c",0x246);
    return 0x1f;
  }
  if ((*(int *)(param_1 + 0x4b4c) == 0) ||
     (iVar4 = gpudbGetRusdSettings(param_1 + 0x7c5,&local_88), iVar4 != 0)) {
    uVar10 = 0;
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gpu_user_shared_data.c",0x24e,"_handlePollMaskHelper",1,
                 "NVRM: RUSD permanent polled data mask: 0x%llx\n",local_88);
    uVar10 = local_88;
  }
  if (param_2 == 0) {
    plVar5 = (long *)serverutilGetFirstClientUnderLock();
    if (plVar5 != (long *)0x0) goto LAB_00356f22;
LAB_00356fe3:
    if (param_3 != 0) goto LAB_00356ff0;
  }
  else {
    if (*(ulong *)(param_1 + 0x3c78) == uVar10) {
      return 0;
    }
    plVar5 = (long *)serverutilGetFirstClientUnderLock();
    if (plVar5 != (long *)0x0) {
LAB_00356f22:
      uVar9 = 0;
      do {
        uVar7 = 0;
        if (*plVar5 != 0) {
          uVar7 = *(undefined8 *)(*plVar5 + 0x100);
        }
        clientRefIter(local_80,uVar7,0,0x5e7d1f,1,1);
        while (cVar3 = clientRefIterNext(local_60,local_80), cVar3 != '\0') {
          lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),
                                     __nvoc_class_def_GpuUserSharedData);
          if ((lVar6 != 0) && (param_1 == *(long *)(*(long *)(lVar6 + 0x210) + 0xf0))) {
            uVar2 = *(uint *)(lVar6 + 0x228);
            uVar9 = uVar9 | *(ulong *)(lVar6 + 0x220);
            if (uVar2 < 100) {
              nvAssertFailedNoLog("pIterData->pollingIntervalMs >= NV_REG_STR_RM_RUSD_POLLING_INTERVAL_MIN"
                                  ,"src/kernel/gpu/gpu_user_shared_data.c",0x21c);
              uVar2 = *(uint *)(lVar6 + 0x228);
            }
            if (*(uint *)(param_1 + 0x3c88) < uVar2) {
              nvAssertFailedNoLog("pIterData->pollingIntervalMs <= pGpu->userSharedData.defaultPollingIntervalMs"
                                  ,"src/kernel/gpu/gpu_user_shared_data.c",0x21d);
              uVar2 = *(uint *)(lVar6 + 0x228);
            }
            if (uVar2 < uVar8) {
              uVar8 = uVar2;
            }
          }
        }
        plVar5 = (long *)serverutilGetNextClientUnderLock(plVar5);
      } while (plVar5 != (long *)0x0);
      uVar10 = uVar10 | uVar9;
      goto LAB_00356fe3;
    }
  }
  if (*(uint *)(param_1 + 0x3c8c) != uVar8) {
    nvAssertFailedNoLog("pollingIntervalMs == pGpu->userSharedData.pollingIntervalMs",
                        "src/kernel/gpu/gpu_user_shared_data.c",0x266);
  }
LAB_00356ff0:
  uVar9 = _gpushareddataSendDataPollRpc(param_1,uVar10,uVar8);
  uVar10 = uVar9;
  if ((int)uVar9 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar9 & 0xffffffff,
               "_gpushareddataSendDataPollRpc(pGpu, polledDataMask, pollingIntervalMs)",
               "src/kernel/gpu/gpu_user_shared_data.c",0x26a);
    uVar10 = uVar9 & 0xffffffff;
    if (*(int *)(param_1 + 0x3c8c) != iVar1) {
      nvAssertFailedNoLog("pGpu->userSharedData.pollingIntervalMs == originalPollingIntervalMs",
                          "src/kernel/gpu/gpu_user_shared_data.c",0x26c);
      uVar10 = uVar9 & 0xffffffff;
    }
  }
  return uVar10;
}


// ===== 003571d0 _gpuRusdRequestPermanentDataPollCallback =====

void _gpuRusdRequestPermanentDataPollCallback(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = gpumgrGetGpu();
  if (lVar2 != 0) {
    iVar1 = _handlePollMaskHelper(lVar2,1,0);
    if (iVar1 != 0) {
      nvCheckFailedNoLog(4,"_handlePollMaskHelper(pGpu, NV_TRUE, NV_FALSE) == NV_OK",
                         "src/kernel/gpu/gpu_user_shared_data.c",0x27d);
      return;
    }
  }
  return;
}


// ===== 0035721e gpushareddataConstruct_IMPL.cold =====

void gpushareddataConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00357230 gpushareddataConstruct_IMPL =====

int gpushareddataConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  lVar2 = *(long *)(lVar1 + 0xf0);
  if ((*(char *)(lVar2 + 0x908) == '\0') && (*(char *)(g_pSys + 0xa4) == '\0')) {
    plVar3 = *(long **)(param_3 + 0x40);
    if (((*(int *)(lVar2 + 0x3c84) != 1) &&
        (((*(char *)(lVar2 + 0x909) != '\0' || (*(int *)(lVar2 + 0x3c84) == 2)) ||
         (*(char *)(lVar2 + 0x4bb) != '\0')))) || (*plVar3 == 0)) {
      *(undefined4 *)(param_1 + 0x228) = *(undefined4 *)(lVar2 + 0x3c88);
      if (*(long *)(param_3 + 0x58) != 0) {
        return 0;
      }
      lVar7 = *(long *)(lVar2 + 0x3c68);
      if (lVar7 != 0) {
        lVar4 = *plVar3;
        if (lVar4 != 0) {
          *(long *)(param_1 + 0x220) = lVar4;
          iVar6 = _handlePollMaskHelper(lVar2,0,0);
          if (iVar6 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar6,"_handlePollMaskHelper(pGpu, NV_FALSE, NV_FALSE)",
                       "src/kernel/gpu/gpu_user_shared_data.c",0x7b);
            return iVar6;
          }
          lVar7 = *(long *)(lVar2 + 0x3c68);
        }
        iVar6 = memConstructCommon_IMPL(lVar1,0x3e,0,lVar7,0,0,0,0,0,0,0,0);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,
                     "memConstructCommon(pMemory, NV01_MEMORY_SYSTEM, 0, *ppMemDesc, 0, NULL, 0, 0, 0, 0, NVOS32_MEM_TAG_NONE, NULL)"
                     ,"src/kernel/gpu/gpu_user_shared_data.c",0x7f);
          return iVar6;
        }
        memdescAddRef(*(undefined8 *)(lVar2 + 0x3c68));
        return 0;
      }
    }
  }
  return 0x56;
}


// ===== 003573b2 gpushareddataDestruct_IMPL.cold =====

void gpushareddataDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003573c0 gpushareddataDestruct_IMPL =====

void gpushareddataDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x210);
  if ((*(char *)(lVar1 + 0xd8) != '\0') && (*(long *)(lVar1 + 0x118) != 0)) {
    lVar2 = *(long *)(lVar1 + 0xf0);
    *(undefined8 *)(param_1 + 0x220) = 0;
    *(undefined4 *)(param_1 + 0x228) = *(undefined4 *)(lVar2 + 0x3c88);
    iVar4 = _handlePollMaskHelper(lVar2,0,1);
    if (iVar4 != 0) {
      nvCheckFailedNoLog(4,"_handlePollMaskHelper(pGpu, NV_FALSE, NV_TRUE) == NV_OK",
                         "src/kernel/gpu/gpu_user_shared_data.c",0x97);
    }
    memdescRemoveRef(*(undefined8 *)(lVar2 + 0x3c68));
    memDestructCommon_IMPL(lVar1);
    return;
  }
  return;
}


// ===== 00357480 gpushareddataCanCopy_IMPL =====

undefined8 gpushareddataCanCopy_IMPL(void)

{
  return 1;
}


// ===== 00357490 gpushareddataWriteStart_INTERNAL =====

long gpushareddataWriteStart_INTERNAL(long param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  ulong *puVar3;
  
  lVar2 = *(long *)(param_1 + 0x3c70);
  if (*(long *)(param_1 + 0x3c70) == 0) {
    lVar2 = param_1 + 0x3ca0;
  }
  puVar3 = (ulong *)(param_2 + lVar2);
  if (*puVar3 == 0) {
    LOCK();
    *puVar3 = 0xff00000000000001;
    UNLOCK();
  }
  else {
    LOCK();
    *puVar3 = *puVar3 + 1;
    UNLOCK();
  }
  LOCK();
  UNLOCK();
  uVar1 = *puVar3;
  if ((0xfefffffffffffffe < uVar1 - 1) && ((uVar1 < 0xff00000000000000 || ((uVar1 & 1) != 0)))) {
    return lVar2;
  }
  nvAssertFailedNoLog("!RUSD_SEQ_DATA_VALID(seqVal)","src/kernel/gpu/gpu_user_shared_data.c",0xb7);
  return lVar2;
}


// ===== 00357530 gpushareddataWriteFinish_INTERNAL =====

void gpushareddataWriteFinish_INTERNAL(long param_1,long param_2)

{
  ulong uVar1;
  ulong *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3c70);
  if (*(long *)(param_1 + 0x3c70) == 0) {
    lVar3 = param_1 + 0x3ca0;
  }
  puVar2 = (ulong *)(lVar3 + param_2);
  LOCK();
  *puVar2 = *puVar2 + 1;
  UNLOCK();
  LOCK();
  UNLOCK();
  uVar1 = *puVar2;
  if ((0xfefffffffffffffe < uVar1 - 1) && ((uVar1 < 0xff00000000000000 || ((uVar1 & 1) != 0)))) {
    nvAssertFailedNoLog("RUSD_SEQ_DATA_VALID(seqVal)","src/kernel/gpu/gpu_user_shared_data.c",200);
    return;
  }
  return;
}


// ===== 003575a0 gpuHandleRusdPollingRegistry_KERNEL =====

ulong gpuHandleRusdPollingRegistry_KERNEL(long param_1)

{
  ulong uVar1;
  
  if ((((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(g_pSys + 0xa4) == '\0')) &&
      (*(int *)(param_1 + 0x3c84) == 2)) && (*(long *)(param_1 + 0x3c78) == 0)) {
    uVar1 = _gpushareddataSendDataPollRpc
                      (param_1,0xffffffffffffffff,*(undefined4 *)(param_1 + 0x3c8c));
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    nvCheckOkFailedNoLog
              (4,uVar1 & 0xffffffff,
               "_gpushareddataSendDataPollRpc(pGpu, ~0ULL, pGpu->userSharedData.pollingIntervalMs)",
               "src/kernel/gpu/gpu_user_shared_data.c",0x115);
    return uVar1 & 0xffffffff;
  }
  return 0;
}


// ===== 00357630 gpuRusdInitPhysical_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gpuRusdInitPhysical_KERNEL(long param_1)

{
  ulong uVar1;
  undefined8 local_28;
  undefined8 local_20;
  
  local_20 = 0;
  local_28 = 1;
  local_20 = memdescGetPhysAddr(*(undefined8 *)(param_1 + 0x3c68),1,0);
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800afe,&local_28,0x10);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_INIT_USER_SHARED_DATA, &params, sizeof(params))"
             ,"src/kernel/gpu/gpu_user_shared_data.c",0x129);
  return uVar1 & 0xffffffff;
}


// ===== 003576d0 gpuCreateRusdMemory_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuCreateRusdMemory_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  long local_38;
  undefined8 local_30;
  
  if (*(char *)(g_pSys + 0xa4) != '\0') {
    return 0;
  }
  iVar1 = memdescCreate(param_1 + 0x3c68,param_1,0xc50,0,1,1);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,
               "memdescCreate(ppMemDesc, pGpu, sizeof(NV00DE_SHARED_DATA), 0, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, MEMDESC_FLAGS_USER_READ_ONLY)"
               ,"src/kernel/gpu/gpu_user_shared_data.c",0x184);
    return iVar1;
  }
  *(undefined4 *)(*(long *)(param_1 + 0x3c68) + 0x9c) = 0x44;
  iVar1 = memdescAlloc(*(undefined8 *)(param_1 + 0x3c68));
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog(iVar1,"status","src/kernel/gpu/gpu_user_shared_data.c",0x188);
LAB_003578ae:
    memdescFree(*(undefined8 *)(param_1 + 0x3c68));
    memdescDestroy(*(undefined8 *)(param_1 + 0x3c68));
    *(undefined8 *)(param_1 + 0x3c68) = 0;
    return iVar1;
  }
  lVar2 = memdescMapInternal(param_1,*(undefined8 *)(param_1 + 0x3c68),0);
  *(long *)(param_1 + 0x3c70) = lVar2;
  if (lVar2 == 0) {
    iVar1 = 0x72;
    goto LAB_003578ae;
  }
  portMemSet(lVar2,0,0xc50);
  (**(code **)(param_1 + 0x3f0))(param_1);
  local_38 = 0;
  local_30 = 0;
  if (*(char *)(param_1 + 0x908) != '\0') {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x3c8c);
  if (iVar1 == 0) {
    nvAssertFailedNoLog(&DAT_00d2a66a,"src/kernel/gpu/gpu_user_shared_data.c",0x13a);
    if (*(char *)(param_1 + 0x4a2f) == '\0') {
      *(undefined4 *)(param_1 + 0x3c8c) = 500;
      iVar1 = 500;
      goto LAB_00357802;
    }
    *(undefined4 *)(param_1 + 0x3c8c) = 100;
    if (*(char *)(param_1 + 0x3c90) == '\0') goto LAB_003577f2;
  }
  else {
    if ((*(char *)(param_1 + 0x3c90) != '\0') || (*(char *)(param_1 + 0x4a2f) == '\0'))
    goto LAB_00357802;
LAB_003577f2:
    *(undefined4 *)(param_1 + 0x3c8c) = 100;
  }
  iVar1 = 100;
LAB_00357802:
  *(int *)(param_1 + 0x3c88) = iVar1;
  nvDbg_Printf("src/kernel/gpu/gpu_user_shared_data.c",0x162,"_gpushareddataInitPollingFrequency",1,
               "NVRM: Default RUSD polling frequency: %d ms\n");
  local_38 = *(long *)(param_1 + 0x3c78);
  local_30 = CONCAT44(local_30._4_4_,*(undefined4 *)(param_1 + 0x3c8c));
  if (local_38 != 0) {
    nvAssertFailedNoLog("pGpu->userSharedData.lastPolledDataMask == 0",
                        "src/kernel/gpu/gpu_user_shared_data.c",0x168);
  }
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800aff,&local_38,0x10);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,
               "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_USER_SHARED_DATA_SET_DATA_POLL, &params, sizeof(params))"
               ,"src/kernel/gpu/gpu_user_shared_data.c",0x16a);
    return 0;
  }
  return 0;
}


// ===== 003579a0 gpuDestroyRusdMemory_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gpuDestroyRusdMemory_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 local_28;
  undefined8 local_20;
  
  if (*(long *)(param_1 + 0x3c68) != 0) {
    if (*(char *)(param_1 + 0x909) != '\0') {
      local_28 = 0;
      local_20 = 0;
      iVar1 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800afe,&local_28,0x10);
      if (iVar1 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar1,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_INIT_USER_SHARED_DATA, &params, sizeof(params))"
                   ,"src/kernel/gpu/gpu_user_shared_data.c",0xf8);
      }
    }
    if (*(long *)(param_1 + 0x48f0) != 0) {
      portMemFree();
      *(undefined8 *)(param_1 + 0x48f0) = 0;
    }
    if (*(long *)(param_1 + 0x48f8) != 0) {
      portMemFree();
      *(undefined8 *)(param_1 + 0x48f8) = 0;
    }
    lVar2 = *(long *)(param_1 + 0x3c68);
    if (*(int *)(lVar2 + 0x90) != 1) {
      nvAssertFailedNoLog("pGpu->userSharedData.pMemDesc->RefCount == 1",
                          "src/kernel/gpu/gpu_user_shared_data.c",0x1bd);
      lVar2 = *(long *)(param_1 + 0x3c68);
    }
    memdescUnmapInternal(param_1,lVar2,0);
    memdescFree(*(undefined8 *)(param_1 + 0x3c68));
    memdescDestroy(*(undefined8 *)(param_1 + 0x3c68));
    *(undefined8 *)(param_1 + 0x3c68) = 0;
    *(undefined8 *)(param_1 + 0x3c70) = 0;
    return;
  }
  return;
}


// ===== 00357b00 gpuRusdRequestPermanentDataPoll_IMPL =====

int gpuRusdRequestPermanentDataPoll_IMPL(long param_1)

{
  int iVar1;
  
  if ((((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(g_pSys + 0xa4) == '\0')) &&
      (*(int *)(param_1 + 0x3c84) != 1)) &&
     (((*(char *)(param_1 + 0x909) != '\0' || (*(int *)(param_1 + 0x3c84) == 2)) ||
      (*(char *)(param_1 + 0x4bb) != '\0')))) {
    iVar1 = osQueueWorkItem(param_1,_gpuRusdRequestPermanentDataPollCallback,0,0x90);
    if (iVar1 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_user_shared_data.c",0x293,
                 "gpuRusdRequestPermanentDataPoll_IMPL",4,
                 "NVRM: Fail to queue work _gpuRusdRequestPermanentDataPollCallback\n");
    return iVar1;
  }
  return 0x56;
}


// ===== 00357bb2 gpushareddataCtrlCmdRequestDataPoll_IMPL.cold =====

void gpushareddataCtrlCmdRequestDataPoll_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00357bc0 gpushareddataCtrlCmdRequestDataPoll_IMPL =====

ulong gpushareddataCtrlCmdRequestDataPoll_IMPL(long param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x210) + 0xf0);
  if (((*(char *)(lVar2 + 0x908) != '\0') || (*(char *)(g_pSys + 0xa4) != '\0')) ||
     (iVar1 = *(int *)(lVar2 + 0x3c84), iVar1 == 1)) {
    return 0x56;
  }
  if (*(char *)(lVar2 + 0x909) == '\0') {
    if (iVar1 == 2) {
      return 0;
    }
    if (*(char *)(lVar2 + 0x4bb) == '\0') {
      return 0x56;
    }
  }
  else if (iVar1 == 2) {
    return 0;
  }
  lVar3 = *(long *)(param_1 + 0x220);
  if (lVar3 == *param_2) {
    return 0;
  }
  *(long *)(param_1 + 0x220) = *param_2;
  uVar5 = _handlePollMaskHelper(lVar2,0,0);
  if ((int)uVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar5 & 0xffffffff,"_handlePollMaskHelper(pGpu, NV_FALSE, NV_FALSE)",
               "src/kernel/gpu/gpu_user_shared_data.c",0x2b0);
    uVar5 = uVar5 & 0xffffffff;
    *(long *)(param_1 + 0x220) = lVar3;
  }
  return uVar5;
}


// ===== 00357cb0 subdeviceCtrlCmdRusdGetSupportedFeatures_IMPL =====

undefined8 subdeviceCtrlCmdRusdGetSupportedFeatures_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  *param_2 = 0;
  if (((((*(char *)(lVar1 + 0x908) == '\0') && (*(char *)(g_pSys + 0xa4) == '\0')) &&
       (*param_2 = 1, *(char *)(lVar1 + 0x908) == '\0')) &&
      ((*(char *)(g_pSys + 0xa4) == '\0' && (*(int *)(lVar1 + 0x3c84) != 1)))) &&
     ((*(char *)(lVar1 + 0x909) != '\0' ||
      ((*(int *)(lVar1 + 0x3c84) == 2 || (*(char *)(lVar1 + 0x4bb) != '\0')))))) {
    *param_2 = 3;
  }
  return 0;
}


// ===== 00357d40 subdeviceCtrlCmdRusdSetFeatures_IMPL =====

ulong subdeviceCtrlCmdRusdSetFeatures_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_20 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((((*(char *)(lVar1 + 0x908) == '\0') && (*(char *)(g_pSys + 0xa4) == '\0')) &&
      (*(int *)(lVar1 + 0x3c84) != 1)) &&
     (((*(char *)(lVar1 + 0x909) != '\0' || (*(int *)(lVar1 + 0x3c84) == 2)) ||
      (*(char *)(lVar1 + 0x4bb) != '\0')))) {
    local_20[0] = *param_2;
    uVar2 = gpudbSetRusdSettings(lVar1 + 0x7c5,local_20);
    if ((int)uVar2 == 0) {
      uVar2 = _handlePollMaskHelper(lVar1,1,0);
      if ((int)uVar2 != 0) {
        nvCheckOkFailedNoLog
                  (4,uVar2 & 0xffffffff,"_handlePollMaskHelper(pGpu, NV_TRUE, NV_FALSE)",
                   "src/kernel/gpu/gpu_user_shared_data.c",0x2e8);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
  }
  else {
    uVar2 = 0x56;
  }
  return uVar2;
}


// ===== 00357e0b gpushareddataCtrlCmdRequestPollInterval_IMPL.cold =====

void gpushareddataCtrlCmdRequestPollInterval_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00357e20 gpushareddataCtrlCmdRequestPollInterval_IMPL =====

ulong gpushareddataCtrlCmdRequestPollInterval_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  undefined8 uVar9;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  if (param_2 == (uint *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gpu_user_shared_data.c",0x2fc);
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x210) + 0xf0);
    if ((((*(char *)(lVar3 + 0x908) != '\0') || (*(char *)(g_pSys + 0xa4) != '\0')) ||
        (*(int *)(lVar3 + 0x3c84) == 1)) ||
       (((*(char *)(lVar3 + 0x909) == '\0' && (*(int *)(lVar3 + 0x3c84) != 2)) &&
        (*(char *)(lVar3 + 0x4bb) == '\0')))) {
      return 0x56;
    }
    uVar6 = *param_2 - 1;
    if (0x62 < uVar6) {
      uVar1 = *(uint *)(lVar3 + 0x3c8c);
      uVar2 = *(uint *)(lVar3 + 0x3c88);
      if (uVar6 < *(uint *)(lVar3 + 0x3c88)) {
        uVar2 = *param_2;
      }
      uVar6 = *(uint *)(param_1 + 0x228);
      *(uint *)(param_1 + 0x228) = uVar2;
      if (uVar2 < uVar1) {
        uVar5 = _gpushareddataSendDataPollRpc(lVar3,*(undefined8 *)(lVar3 + 0x3c78));
        if ((int)uVar5 != 0) {
          uVar9 = 0x322;
          pcVar7 = 
          "_gpushareddataSendDataPollRpc(pGpu, pGpu->userSharedData.lastPolledDataMask, inputIntervalMs)"
          ;
          goto LAB_00357fec;
        }
      }
      else {
        uVar8 = uVar6;
        if (uVar2 <= uVar6) {
          uVar8 = uVar2;
        }
        if ((uVar1 < uVar8) || (uVar2 == uVar1)) {
          return 0;
        }
        if (uVar1 != uVar6) {
          nvAssertFailedNoLog("originalGlobalPollingIntervalMs == originalClientPollingIntervalMs",
                              "src/kernel/gpu/gpu_user_shared_data.c",0x343);
        }
        uVar5 = _handlePollMaskHelper(lVar3,0,1);
        if ((int)uVar5 != 0) {
          uVar9 = 0x346;
          pcVar7 = "_handlePollMaskHelper(pGpu, NV_FALSE, NV_TRUE)";
LAB_00357fec:
          nvCheckOkFailedNoLog
                    (4,uVar5 & 0xffffffff,pcVar7,"src/kernel/gpu/gpu_user_shared_data.c",uVar9);
          *(uint *)(param_1 + 0x228) = uVar6;
          return uVar5 & 0xffffffff;
        }
      }
      return uVar5;
    }
    nvDbg_Printf("src/kernel/gpu/gpu_user_shared_data.c",0x306,
                 "gpushareddataCtrlCmdRequestPollInterval_IMPL",4,
                 "NVRM: Invalid input polling interval: %u ms\n");
  }
  return 0x1f;
}


// ===== 00358050 _sha1Transform =====

void _sha1Transform(uint *param_1,long param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar5 = 0;
  uVar10 = param_1[4];
  uVar6 = *param_1;
  uVar4 = param_1[1];
  uVar3 = param_1[2];
  uVar8 = param_1[3];
  do {
    uVar7 = uVar3;
    uVar9 = uVar6;
    puVar1 = (uint *)(param_2 + (ulong)(uVar5 & 0xf) * 4);
    uVar6 = *puVar1;
    if (uVar5 < 0x10) {
      uVar6 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
      puVar1[0x10] = uVar6;
      *puVar1 = uVar6;
LAB_003580f7:
      iVar2 = ((uVar7 ^ uVar8) & uVar4 ^ uVar8) + 0x5a827999;
LAB_00358095:
      uVar3 = uVar4 >> 2 | uVar4 << 0x1e;
      uVar6 = iVar2 + uVar6 + (uVar9 << 5 | uVar9 >> 0x1b) + uVar10;
    }
    else {
      uVar6 = uVar6 ^ puVar1[2] ^ puVar1[8] ^ puVar1[0xd];
      uVar6 = uVar6 << 1 | (uint)((int)uVar6 < 0);
      puVar1[0x10] = uVar6;
      *puVar1 = uVar6;
      if (uVar5 < 0x28) {
        if (uVar5 < 0x14) goto LAB_003580f7;
        iVar2 = (uVar4 ^ uVar7 ^ uVar8) + 0x6ed9eba1;
        goto LAB_00358095;
      }
      if (uVar5 < 0x3c) {
        iVar2 = ((uVar4 | uVar7) & uVar8 | uVar4 & uVar7) + 0x8f1bbcdc;
        goto LAB_00358095;
      }
      uVar3 = uVar4 >> 2 | uVar4 << 0x1e;
      uVar6 = uVar6 + 0xca62c1d6 + (uVar4 ^ uVar7 ^ uVar8) + (uVar9 << 5 | uVar9 >> 0x1b) + uVar10;
      if (uVar5 == 0x4f) {
        *param_1 = *param_1 + uVar6;
        param_1[1] = param_1[1] + uVar9;
        param_1[2] = param_1[2] + uVar3;
        param_1[3] = param_1[3] + uVar7;
        param_1[4] = param_1[4] + uVar8;
        return;
      }
    }
    uVar5 = uVar5 + 1;
    uVar10 = uVar8;
    uVar4 = uVar9;
    uVar8 = uVar7;
  } while( true );
}


// ===== 00358150 _nvGenerateUuid =====

undefined8
_nvGenerateUuid(int param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,long param_7)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined1 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined8 uVar10;
  undefined4 local_d0;
  undefined8 local_c8;
  undefined4 local_c0;
  uint local_bc;
  undefined8 local_b8;
  undefined8 local_b0 [6];
  undefined4 local_80;
  uint local_7c;
  
  if (param_1 == 1) {
    uVar10 = 0x46;
    uVar7 = 0x32;
LAB_003581b1:
    lVar1 = portMemAllocNonPaged(uVar10);
  }
  else {
    if (param_1 == 2) {
      uVar10 = 0x42;
      uVar7 = 0x2e;
      goto LAB_003581b1;
    }
    uVar7 = 0x26;
    lVar1 = portMemAllocNonPaged(0x3a);
  }
  if (lVar1 == 0) {
    return 0x51;
  }
  portMemCopy(lVar1 + 0x14,0x26,&gpuUuidMessage,0x26);
  *(undefined2 *)(lVar1 + 0x2f) = param_2;
  *(undefined8 *)(lVar1 + 0x32) = param_3;
  if (param_1 == 1) {
    portMemCopy(lVar1 + 0x3a,0xc,smcUuidPostfix,0xc);
    *(undefined4 *)(lVar1 + 0x3e) = param_4;
    *(undefined4 *)(lVar1 + 0x42) = param_5;
  }
  else if (param_1 == 2) {
    portMemCopy(lVar1 + 0x3a,8,&ugcUuidPostfix,8);
    *(undefined4 *)(lVar1 + 0x3e) = param_6;
  }
  _local_d0 = 0xefcdab8967452301;
  local_c8 = 0x1032547698badcfe;
  local_c0 = 0xc3d2e1f0;
  local_bc = uVar7;
  portMemCopy(&local_b8,uVar7,lVar1 + 0x14,uVar7);
  uVar7 = local_bc & 0x3f;
  uVar2 = (ulong)(uVar7 + 0x18);
  *(undefined1 *)((long)local_b0 + ((ulong)uVar7 - 8)) = 0x80;
  puVar4 = (undefined1 *)((long)&local_d0 + uVar2);
  if (uVar7 < 0x38) {
    puVar8 = (undefined1 *)((long)&local_d0 + uVar2 + 1);
    puVar4 = puVar4 + (0x3c - uVar7);
    if (((int)puVar4 - (int)puVar8 & 1U) != 0) {
      *puVar8 = 0;
      puVar8 = (undefined1 *)((long)&local_d0 + uVar2 + 2);
      if (puVar4 == puVar8) goto LAB_003582d0;
    }
    do {
      *puVar8 = 0;
      puVar9 = puVar8 + 2;
      puVar8[1] = 0;
      puVar8 = puVar9;
    } while (puVar4 != puVar9);
    goto LAB_003582d0;
  }
  if (uVar7 != 0x3f) {
    puVar8 = puVar4 + (0x3f - uVar7);
    if ((0x3f - uVar7 & 1) != 0) {
      *(undefined1 *)((long)&local_d0 + uVar2 + 1) = 0;
      puVar4 = (undefined1 *)((long)&local_d0 + uVar2 + 1);
      if (puVar4 == puVar8) goto LAB_003583e0;
    }
    do {
      puVar4[1] = 0;
      puVar4 = puVar4 + 2;
      *puVar4 = 0;
    } while (puVar4 != puVar8);
  }
LAB_003583e0:
  _sha1Transform(&local_d0,&local_b8);
  local_b8 = 0;
  puVar5 = local_b0;
  do {
    *puVar5 = 0;
    puVar6 = puVar5 + 2;
    puVar5[1] = 0;
    puVar5 = puVar6;
  } while ((undefined8 *)&local_80 != puVar6);
  local_80 = 0;
LAB_003582d0:
  local_7c = (local_bc & 0x1fe0) << 0xb | (local_bc & 0x1fffffff) >> 0x15 | local_bc << 0x1b |
             (local_bc & 0x1fffffff) >> 5 & 0xff00;
  _sha1Transform(&local_d0,&local_b8);
  lVar3 = 0;
  do {
    uVar7 = *(uint *)((long)&local_d0 + lVar3);
    *(uint *)(lVar1 + lVar3) =
         uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
    lVar3 = lVar3 + 4;
  } while (lVar3 != 0x14);
  portMemCopy(param_7,0x10,lVar1,0x10);
  *(byte *)(param_7 + 6) = *(byte *)(param_7 + 6) & 0xf | 0x50;
  *(byte *)(param_7 + 8) = *(byte *)(param_7 + 8) & 0x3f | 0x80;
  portMemFree(lVar1);
  return 0;
}


// ===== 00358480 nvGenerateSmcUuid =====

void nvGenerateSmcUuid(undefined2 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                      undefined8 param_5)

{
  _nvGenerateUuid(1,param_1,param_2,param_3,param_4,0,param_5);
  return;
}


// ===== 003584b0 nvGenerateUgpuUuid =====

void nvGenerateUgpuUuid(undefined2 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  _nvGenerateUuid(2,param_1,param_3,0,0,param_2,param_4);
  return;
}


// ===== 003584e0 nvGetUuidString =====

undefined1  [16] nvGetUuidString(undefined8 param_1,char param_2,long param_3)

{
  undefined1 auVar1 [16];
  undefined *puVar2;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  
  puVar2 = &DAT_00d2a926;
  local_30 = 0x400000008;
  local_28 = 0x400000004;
  local_20 = 0xc;
  if ((byte)(param_2 - 1U) < 3) {
    puVar2 = *(undefined **)(CSWTCH_16 + (ulong)(byte)(param_2 - 1U) * 8);
  }
  portMemCopy(param_3,4,puVar2,4);
  portStringBufferToHexGroups(param_3 + 4,0x25,param_1,0x10,5,&local_30);
  auVar1._8_8_ = 0x358540;
  auVar1._0_8_ = &DAT_00d2a92b;
  return auVar1;
}


// ===== 00358580 transformGidToUserFriendlyString =====

undefined8
transformGidToUserFriendlyString
          (undefined8 param_1,int param_2,long *param_3,undefined4 *param_4,uint param_5,
          undefined1 param_6)

{
  long lVar1;
  undefined1 local_38 [16];
  
  if ((param_5 & 4) != 0) {
    return 0x29;
  }
  if (param_2 != 0x10) {
    nvAssertFailedNoLog("NV_UUID_LEN == gidSize","src/kernel/gpu/gpu_uuid.c",0x3d);
  }
  portMemCopy(local_38,0x10,param_1,param_2);
  lVar1 = portMemAllocNonPaged(0x29);
  *param_3 = lVar1;
  if (lVar1 != 0) {
    nvGetUuidString(local_38,param_6,lVar1);
    *param_4 = 0x29;
    return 0;
  }
  return 0x51;
}


// ===== 00358670 gpuGenGidData_VF =====

uint gpuGenGidData_VF(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if ((lVar1 != 0) && ((param_4 & 4) == 0)) {
    portMemCopy(param_2,0x10,lVar1 + 0x1f8a4,0x10);
    return param_4 & 4;
  }
  return 0x56;
}


// ===== 003586c0 gpuCreateDefaultClientShare_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuCreateDefaultClientShare_VF(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60 [8];
  
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  puVar3 = (undefined8 *)rmapiGetInterface(4);
  iVar2 = (*(code *)puVar3[1])(puVar3,local_70,local_70,local_70,0,&local_70,4);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->AllocWithHandle(pRmApi, hClient, hClient, hClient, NV01_ROOT, &hClient, sizeof(hClient))"
               ,"src/kernel/gpu/gpu_vgpu.c",0x4d,0x3586f3);
    return iVar2;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x7b4);
  *(undefined4 *)(param_1 + 0x3b18) = local_70;
  portMemSet(local_60,0,0x38);
  local_60[0] = CONCAT44(*(undefined4 *)(param_1 + 0x3b18),uVar1);
  uVar4 = 0x38;
  iVar2 = (*(code *)*puVar3)(puVar3,local_70,local_70,&local_6c,0x80,local_60);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x3b1c) = local_6c;
    portMemSet(&local_64,0,4,uVar4);
    local_64 = 0;
    iVar2 = (*(code *)*puVar3)(puVar3,local_70,local_6c,&local_68,0x2080,&local_64,4);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x3b20) = local_68;
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->Alloc(pRmApi, hClient, hDevice, &hSubDevice, NV20_SUBDEVICE_0, &subdeviceAllocParams, sizeof(subdeviceAllocParams))"
               ,"src/kernel/gpu/gpu_vgpu.c",0x6c);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->Alloc(pRmApi, hClient, hClient, &hDevice, NV01_DEVICE_0, &deviceAllocParams, sizeof(deviceAllocParams))"
               ,"src/kernel/gpu/gpu_vgpu.c",0x5f);
  }
  (*(code *)puVar3[3])(puVar3,local_70,local_70);
  *(undefined4 *)(param_1 + 0x3b18) = 0;
  return iVar2;
}


// ===== 003588a0 gpuDestroyDefaultClientShare_VF =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void gpuDestroyDefaultClientShare_VF(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(4);
  iVar1 = *(int *)(param_1 + 0x3b18);
  if (iVar1 != 0) {
    (**(code **)(lVar2 + 0x18))(lVar2,iVar1,iVar1,*(code **)(lVar2 + 0x18));
    return;
  }
  return;
}


// ===== 003588f0 gpuCheckPageRetirementSupport_VF =====

undefined1 gpuCheckPageRetirementSupport_VF(long param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)
            (*(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8) + 0x26160);
  }
  nvAssertFailedNoLog("pGpu != NULL","src/kernel/gpu/gpu_vgpu.c",0xa2);
  return 0x3d;
}


// ===== 00358940 gpuInitSriov_VF =====

undefined8 gpuInitSriov_VF(long param_1)

{
  long lVar1;
  
  if (*(char *)(param_1 + 0x4913) == '\0') {
    return 0;
  }
  lVar1 = gpuGetStaticInfo();
  *(undefined1 *)(param_1 + 0x4922) = *(undefined1 *)(lVar1 + 0x1fd48);
  return 0;
}


// ===== 00358980 gpuGetNameString_VF =====

undefined8 gpuGetNameString_VF(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    portMemCopy(param_2,0x40,lVar1 + 0x1fd49,0x40);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gpu_vgpu.c",0xc0);
  return 0x40;
}


