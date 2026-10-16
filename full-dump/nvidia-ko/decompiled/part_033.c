// ===== 003589f0 gpuGetShortNameString_VF =====

undefined8 gpuGetShortNameString_VF(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    portMemCopy(param_2,0x40,lVar1 + 0x1fe0a,0x40);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gpu_vgpu.c",0xd1);
  return 0x40;
}


// ===== 00358a60 gpuIsGlobalPoisonFuseEnabled_VF =====

undefined1 gpuIsGlobalPoisonFuseEnabled_VF(void)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    return *(undefined1 *)(lVar1 + 0x1fe4a);
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gpu_vgpu.c",0xe0);
  return 0;
}


// ===== 00358aa0 gpuConstructDeviceInfoTable_VF =====

undefined8 gpuConstructDeviceInfoTable_VF(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  long lVar13;
  long lVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  
  lVar13 = gpuGetStaticInfo();
  if (lVar13 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gpu_vgpu.c",0xed);
    return 0x40;
  }
  if (*(long *)(param_1 + 0x3b28) == 0) {
    uVar17 = *(uint *)(lVar13 + 0x1fe4c);
    if (uVar17 == 0) {
      return 0;
    }
    if (0x200 < uVar17) {
      nvAssertFailedNoLog("pVSI->deviceInfoTable.numEntries <= NV2080_CTRL_CMD_INTERNAL_DEVICE_INFO_MAX_ENTRIES"
                          ,"src/kernel/gpu/gpu_vgpu.c",0xf5);
      return 0x40;
    }
    lVar14 = portMemAllocNonPaged((ulong)uVar17 * 0x30);
    *(long *)(param_1 + 0x3b28) = lVar14;
    if (lVar14 == 0) {
      nvAssertFailedNoLog("pGpu->pDeviceInfoTable != NULL","src/kernel/gpu/gpu_vgpu.c",0xfb);
      return 0x51;
    }
    iVar1 = *(int *)(lVar13 + 0x1fe4c);
    *(int *)(param_1 + 0x3b30) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    puVar16 = (undefined4 *)(lVar13 + 0x1fe50);
    uVar17 = 0;
    while( true ) {
      uVar2 = puVar16[3];
      uVar3 = puVar16[4];
      uVar4 = puVar16[9];
      uVar5 = puVar16[5];
      puVar15 = (undefined4 *)((long)puVar16 + lVar14 + (-0x1fe50 - lVar13));
      uVar6 = puVar16[6];
      uVar7 = puVar16[7];
      uVar8 = puVar16[0xb];
      uVar9 = puVar16[1];
      uVar10 = puVar16[2];
      uVar11 = puVar16[10];
      uVar12 = *puVar16;
      puVar15[8] = puVar16[8];
      puVar15[3] = uVar2;
      puVar15[4] = uVar3;
      puVar15[5] = uVar5;
      puVar15[6] = uVar6;
      puVar15[7] = uVar7;
      puVar15[9] = uVar4;
      puVar15[10] = uVar11;
      puVar15[0xb] = uVar8;
      *puVar15 = uVar12;
      puVar15[1] = uVar9;
      puVar15[2] = uVar10;
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x112,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF: Engine Entry [%d]\n",uVar17);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x113,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Type Enum        : %d\n",puVar16[2]);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x114,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     DieletGlobal Id  : %d\n",puVar16[1]);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x115,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Dielet, LocalId  : %d, %d\n",puVar16[8],puVar16[0xb]);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x116,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Fault Id         : %d\n",*puVar16);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x117,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Reset Id         : %d\n",puVar16[3]);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x118,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Device PRI Base  : 0x%x\n",puVar16[4]);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x119,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Is Engine        : %d\n",puVar16[5]);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x11a,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Runlist Engine ID: %d\n",puVar16[6]);
      nvDbg_Printf("src/kernel/gpu/gpu_vgpu.c",0x11b,"gpuConstructDeviceInfoTable_VF",1,
                   "NVRM: VF:     Runlist PRI Base : 0x%x\n",puVar16[7]);
      if (*(uint *)(param_1 + 0x3b30) <= uVar17 + 1) break;
      lVar14 = *(long *)(param_1 + 0x3b28);
      puVar16 = puVar16 + 0xc;
      uVar17 = uVar17 + 1;
    }
  }
  return 0;
}


// ===== 00358e40 gpuInitBranding_VF =====

undefined8 gpuInitBranding_VF(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  bool bVar4;
  
  lVar3 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(param_1 + 0x7a4) * 8);
  if (lVar3 != 0) {
    iVar1 = *(int *)(lVar3 + 0x2614c);
    *(undefined1 *)(param_1 + 0x4a2b) = 0;
    *(bool *)(param_1 + 0x4a2a) = iVar1 == 2;
    iVar2 = *(int *)(lVar3 + 0x2614c);
    *(undefined1 *)(param_1 + 0x4a2c) = 1;
    *(undefined1 *)(param_1 + 0x4a28) = 0;
    *(undefined1 *)(param_1 + 0x4a2e) = 0;
    *(bool *)(param_1 + 0x4a2d) = iVar2 == 1;
    bVar4 = *(int *)(lVar3 + 0x2614c) == 4;
    *(bool *)(param_1 + 0x4a2f) = bVar4;
    *(bool *)(param_1 + 0x4a29) = (!bVar4 && iVar1 != 2) && iVar2 != 1;
    return 0;
  }
  nvAssertFailedNoLog("pVGpu != NULL","src/kernel/gpu/gpu_vgpu.c",0x128);
  return 0x40;
}


// ===== 00358ef0 gpuGetSkuInfo_VF =====

undefined8 gpuGetSkuInfo_VF(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  if (lVar1 != 0) {
    portMemCopy(param_2,0x30,lVar1 + 0xa738,0x30);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gpu_vgpu.c",0x13f);
  return 0x40;
}


// ===== 00358f60 gpuValidateMIGSupport_VF =====

bool gpuValidateMIGSupport_VF(void)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo();
  return *(int *)(lVar1 + 0xa7d0) != -1;
}


// ===== 00358f80 _videoTimerCallback =====

int _videoTimerCallback(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = osQueueWorkItem(param_1,_videoOsWorkItem,0,0x80);
  if (iVar1 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "osQueueWorkItem(pGpu, _videoOsWorkItem, NULL, (OsQueueWorkItemFlags){.bLockGpuGroupDevice = NV_TRUE})"
               ,"src/kernel/gpu/gpuvideo/videoeventlist.c",0x1aa);
  }
  iVar2 = tmrEventScheduleRel_IMPL(param_2,param_3,50000000);
  if (iVar2 == 0) {
    return iVar1;
  }
  nvCheckOkFailedNoLog
            (4,iVar2,"tmrEventScheduleRel(pTmr, pTmrEvent, NV_VIDEO_TRACE_CALLBACK_TIME_NS)",
             "src/kernel/gpu/gpuvideo/videoeventlist.c",0x1b2);
  if (iVar1 == 0) {
    iVar1 = iVar2;
  }
  return iVar1;
}


// ===== 00359040 _notifyEventBuffers =====

void _notifyEventBuffers(long param_1,long param_2,long *param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  bool bVar10;
  bool bVar11;
  char local_a9;
  long local_a8;
  long *local_a0 [4];
  undefined1 *local_80;
  undefined4 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined1 local_60 [2];
  undefined2 local_5e;
  undefined4 local_5c;
  ulong local_58;
  ulong local_50;
  ulong local_48;
  undefined8 local_40;
  
  if (param_2 == 0) {
    return;
  }
  lVar1 = param_3[2];
  mapFindLEQ_IMPL(param_2,0xffffffffffffffff);
  uVar9 = mapFindGEQ_IMPL(param_2,0);
  multimapItemIterRange_IMPL(local_a0,param_1 + 0x4948,uVar9);
  do {
    cVar6 = multimapItemIterNext_IMPL(local_a0);
    plVar5 = local_a0[0];
    while( true ) {
      if (cVar6 == '\0') {
        return;
      }
      bVar10 = false;
      if (*(char *)((long)plVar5 + 0x21) == '\0') {
        bVar10 = *(long *)(lVar1 + 0x20) == 0;
      }
      bVar11 = false;
      if ((char)plVar5[4] == '\0') {
        bVar11 = plVar5[3] != *(long *)(lVar1 + 0x20);
      }
      local_a0[0] = plVar5;
      if ((*(byte *)((long)plVar5 + 0x22) >> (*(uint *)(lVar1 + 0x10) & 0x1f) & 1) == 0) break;
      lVar2 = param_3[2];
      portMemSet(&local_80,0,0x20);
      local_70 = 0;
      local_68 = 0;
      portMemSet(local_60,0,0x28);
      local_58 = (ulong)*(uint *)(lVar2 + 0x2c);
      local_60[0] = (undefined1)*(undefined4 *)(lVar2 + 0x10);
      local_50 = *(ulong *)(lVar2 + 8);
      local_5e = (undefined2)*(undefined4 *)(lVar2 + 0x14);
      local_5c = *(undefined4 *)(lVar2 + 0x28);
      local_48 = *(ulong *)(lVar2 + 0x30);
      if (bVar10) {
        local_5c = 0xffffffff;
        local_58 = 0xffffffff;
LAB_00359190:
        uVar3 = param_3[1];
        local_48 = local_58;
        if ((local_50 != uVar3) && (*param_3 != 0)) {
          bVar10 = local_50 < uVar3;
          lVar4 = local_50 - uVar3;
          uVar7 = portCryptoPseudoRandomGeneratorGetU32();
          local_50 = (ulong)uVar7 % (lVar4 - (ulong)bVar10) + uVar3;
        }
      }
      else if (bVar11) {
        local_58 = 0;
        local_5c = 0;
        goto LAB_00359190;
      }
      uVar7 = *(uint *)(lVar2 + 0x10);
      if (uVar7 == 2) {
        local_40 = CONCAT62(CONCAT42(local_40._4_4_,*(undefined2 *)(lVar2 + 0x1a)),
                            *(undefined2 *)(lVar2 + 0x18));
      }
      else if (uVar7 < 3) {
        local_40 = *(undefined8 *)(lVar2 + 0x18);
      }
      else if (uVar7 == 3) {
        local_68 = *(undefined4 *)(lVar2 + 0x1c);
        local_40 = *(undefined8 *)(lVar2 + 0x18);
        local_70 = param_4;
      }
      else {
        local_40 = *(undefined8 *)(lVar2 + 0x18);
      }
      local_78 = 0x28;
      local_80 = local_60;
      iVar8 = eventBufferAdd(*plVar5,&local_80,1);
      if (((iVar8 != 0) || (local_a9 == '\0')) || (local_a8 == 0)) break;
      osEventNotification(param_1,*(undefined8 *)(*plVar5 + 0x160),1);
      *(undefined1 *)(*plVar5 + 0x15e) = 1;
      cVar6 = multimapItemIterNext_IMPL(local_a0);
      plVar5 = local_a0[0];
    }
  } while( true );
}


// ===== 00359340 videoEventTraceCtxInit =====

undefined8 videoEventTraceCtxInit(undefined8 param_1,long param_2,ulong param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  long local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_4c;
  
  uVar2 = (uint)(param_3 >> 8) & 0xffffff;
  if (((uVar2 != 0x8f99e1 && uVar2 != 0xdd7bab) && uVar2 != 0x2b3a54) && (uVar2 != 0xe97b6c)) {
    return 0;
  }
  cVar1 = hypervisorIsVgxHyper_IMPL();
  if (cVar1 != '\0') {
    return 0;
  }
  lVar5 = kvidengFromEngDesc_IMPL(param_1,param_3 & 0xffffffff);
  if (lVar5 == 0) {
    nvCheckFailedNoLog(4,"pKernelVideoEngine != NULL","src/kernel/gpu/gpuvideo/videoeventlist.c",
                       0x4c);
    return 0;
  }
  if (*(char *)(lVar5 + 0x80) == '\0') {
    return 0;
  }
  if (*(long *)(lVar5 + 0x50) == 0) {
    return 0;
  }
  local_60 = *(undefined8 *)(param_2 + 0x290);
  local_4c = (undefined1)(param_3 & 0xffffffff);
  local_58 = CONCAT44(*(undefined4 *)(param_2 + 0x3e4),*(undefined4 *)(param_2 + 0x414));
  local_50 = kchannelGetGfid_IMPL(param_2);
  kchangrpGetEngineContextMemDesc_IMPL
            (param_1,*(undefined8 *)(*(long *)(param_2 + 0x2b8) + 0x138),&local_68);
  if (local_68 == 0) {
    return 0;
  }
  if (*(ulong *)(local_68 + 0x30) < 0xfc0) {
    nvCheckFailedNoLog(1,
                       "memdescGetSize(pCtxMemDesc) >= (VIDEO_ENGINE_EVENT__LOG_INFO__OFFSET + VIDEO_ENGINE_EVENT__LOG_INFO__SIZE)"
                       ,"src/kernel/gpu/gpuvideo/videoeventlist.c",0x62);
    return 2;
  }
  lVar6 = memdescMapInternal(param_1,local_68,0);
  puVar7 = &local_60;
  puVar10 = (undefined4 *)(lVar6 + 4000);
  if (lVar6 == 0) {
    nvCheckFailedNoLog(4,"pInstMem != NULL","src/kernel/gpu/gpuvideo/videoeventlist.c",0x67);
    return 0x1a;
  }
  do {
    uVar4 = *(undefined4 *)puVar7;
    puVar7 = (undefined8 *)((long)puVar7 + 4);
    *puVar10 = uVar4;
    puVar10 = puVar10 + 1;
  } while (puVar7 != (undefined8 *)&stack0xffffffffffffffd8);
  lVar5 = *(long *)(lVar5 + 0x50);
  uVar8 = memdescGetPhysAddr(lVar5,1,0);
  iVar3 = memdescGetAddressSpace(lVar5);
  uVar11 = (undefined4)uVar8;
  uVar4 = (undefined4)((ulong)uVar8 >> 0x20);
  if (iVar3 == 2) {
    cVar1 = memdescGetContiguity(lVar5,1);
    if (cVar1 != '\0') {
      uVar9 = 2;
      goto LAB_00359551;
    }
  }
  else {
    iVar3 = memdescGetAddressSpace(lVar5);
    if ((iVar3 == 1) && (*(int *)(lVar5 + 0x74) == 0)) {
      cVar1 = memdescGetContiguity(lVar5,1);
      if (cVar1 != '\0') {
        uVar9 = 3;
        goto LAB_00359551;
      }
    }
    else {
      iVar3 = memdescGetAddressSpace(lVar5);
      if (iVar3 == 1) {
        if (*(int *)(lVar5 + 0x74) - 1U < 2) {
          cVar1 = memdescGetContiguity(lVar5,1);
          if (cVar1 != '\0') {
            uVar9 = 4;
            goto LAB_00359551;
          }
        }
        else {
          memdescGetContiguity(lVar5,1);
        }
      }
      else {
        memdescGetContiguity(lVar5,1);
      }
    }
  }
  nvAssertFailedNoLog("(memdescGetContiguity(pMemDesc, AT_GPU) && memPhysType != RM_VIDENG_DMAIDX_END)"
                      ,"src/kernel/gpu/gpuvideo/videoeventlist.c",0x83);
  uVar4 = 0;
  uVar11 = 0;
  uVar9 = 0;
LAB_00359551:
  *(undefined4 *)(lVar6 + 0xf90) = uVar11;
  *(undefined4 *)(lVar6 + 0xf94) = uVar4;
  *(undefined4 *)(lVar6 + 0xf98) = uVar9;
  memdescUnmapInternal(param_1,local_68,0);
  return 0;
}


// ===== 00359640 nvEventBufferVideoCallback =====

void nvEventBufferVideoCallback(long param_1)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_b8;
  long local_b0;
  byte local_99;
  undefined8 local_90;
  undefined8 local_88;
  undefined1 *local_80;
  undefined1 local_78 [8];
  undefined8 local_70;
  int local_68;
  long local_58;
  
  cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  if (cVar3 == '\0') {
    nvAssertFailedNoLog(&DAT_00d2af60,"src/kernel/gpu/gpuvideo/videoeventlist.c",0x1e7);
    return;
  }
  if (*(short *)(param_1 + 0x4940) < 1) {
    if (*(short *)(param_1 + 0x4940) != 0) {
      nvAssertFailedNoLog("pGpu->videoCtxswLogConsumerCount >= 0",
                          "src/kernel/gpu/gpuvideo/videoeventlist.c",0x1ed);
      return;
    }
  }
  else {
    lVar6 = multimapFindSubmap_IMPL(param_1 + 0x4948,0);
    if ((lVar6 != 0) && (*(int *)(param_1 + 0x39f8) != 0)) {
      uVar7 = 0;
      local_99 = 0;
      do {
        lVar1 = *(long *)(param_1 + 0x3948 + uVar7 * 8);
        if (lVar1 == 0) {
          nvAssertFailedNoLog("pKernelVideoEngine != NULL",
                              "src/kernel/gpu/gpuvideo/videoeventlist.c",0x145);
        }
        else if (*(char *)(lVar1 + 0x80) == '\0') {
          nvCheckFailedNoLog(1,"pKernelVideoEngine->bVideoTraceEnabled",
                             "src/kernel/gpu/gpuvideo/videoeventlist.c",0x146);
        }
        else {
          lVar2 = *(long *)(lVar1 + 0x58);
          if (lVar2 != 0) {
            local_b0 = 0;
            local_b8 = 0;
LAB_00359720:
            uVar4 = kvidengRingbufferGetDataSize_IMPL(param_1,lVar2);
            if (0x3f < uVar4) {
              do {
                uVar4 = *(uint *)(lVar2 + 4);
                iVar5 = kvidengEventbufferGetRecord_IMPL
                                  (param_1,lVar1,lVar2,local_78,0xdeadbeef,0xdead0001);
                if (local_68 == 3) {
                  if (iVar5 == 0) goto LAB_00359720;
LAB_00359878:
                  local_88 = *(undefined8 *)(lVar1 + 0x68);
                }
                else {
                  if (((ulong)uVar4 + 0x40 != (ulong)*(uint *)(lVar2 + 4)) || (iVar5 == 0))
                  goto LAB_00359720;
                  if (local_68 != 0) goto LAB_00359878;
                  *(undefined8 *)(lVar1 + 0x68) = local_70;
                  local_88 = local_70;
                }
                local_90 = *(undefined8 *)(lVar1 + 0x70);
                local_80 = local_78;
                if (local_58 != 0) {
                  if (local_58 != local_b0) {
                    local_b8 = multimapFindSubmap_IMPL(param_1 + 0x4948);
                    local_b0 = local_58;
                  }
                  _notifyEventBuffers(param_1,local_b8,&local_90,*(undefined8 *)(lVar1 + 0x60));
                }
                _notifyEventBuffers(param_1,lVar6,&local_90,*(undefined8 *)(lVar1 + 0x60));
                uVar4 = kvidengRingbufferGetDataSize_IMPL(param_1,lVar2);
                if (uVar4 < 0x40) break;
              } while( true );
            }
          }
        }
        local_99 = local_99 + 1;
        uVar7 = (ulong)local_99;
      } while ((uint)local_99 < *(uint *)(param_1 + 0x39f8));
    }
  }
  return;
}


// ===== 003598f0 _videoOsWorkItem =====

void _videoOsWorkItem(void)

{
  undefined8 uVar1;
  
  uVar1 = gpumgrGetGpu();
  nvEventBufferVideoCallback(uVar1,0);
  return;
}


// ===== 00359910 videoRemoveBindpoint =====

void videoRemoveBindpoint(long param_1,undefined8 param_2,long *param_3)

{
  short *psVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar2 = *param_3;
  psVar1 = (short *)(param_1 + 0x4940);
  *psVar1 = *psVar1 + -1;
  if ((*psVar1 == 0) && (*(int *)(param_1 + 0x39f8) != 0)) {
    lVar4 = 0;
    do {
      lVar3 = *(long *)(param_1 + 0x3948 + lVar4 * 8);
      if (((lVar3 != 0) && (*(char *)(lVar3 + 0x7c) == '\0')) && (*(long *)(lVar3 + 0x58) != 0)) {
        *(undefined4 *)(*(long *)(lVar3 + 0x58) + 0xc) = 0;
      }
      lVar4 = lVar4 + 1;
    } while ((uint)lVar4 < *(uint *)(param_1 + 0x39f8));
  }
  unregisterEventNotificationWithData
            (lVar2 + 0x160,(int)param_3[1],*(undefined4 *)((long)param_3 + 0xc),(int)param_3[2],1,
             *(undefined8 *)(lVar2 + 0x1a8));
  multimapRemoveItemByKey_IMPL(param_1 + 0x4948,param_2,lVar2);
  return;
}


// ===== 003599d0 videoAddBindpoint =====

ulong videoAddBindpoint(long param_1,long param_2,long param_3,undefined4 param_4,char param_5,
                       int param_6,undefined1 param_7)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  char cVar7;
  short sVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  long *plVar14;
  
  uVar2 = *(undefined4 *)(param_2 + 0x48);
  lVar10 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmClient);
  uVar3 = *(undefined4 *)(param_3 + 0x10);
  sVar1 = *(short *)(param_1 + 0x4940);
  uVar6 = osIsAdministrator();
  lVar11 = resservGetTlsCallContext();
  if (lVar11 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/gpuvideo/videoeventlist.c",0x234);
    uVar12 = 0x40;
  }
  else {
    uVar9 = *(uint *)(lVar11 + 0x28);
    cVar7 = rmapiLockIsOwner();
    if ((cVar7 == '\0') ||
       (cVar7 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4)), cVar7 == '\0')) {
      nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                          "src/kernel/gpu/gpuvideo/videoeventlist.c",0x23c);
      uVar12 = 0x2f;
    }
    else {
      cVar7 = kvidengIsVideoTraceLogSupported_STATIC_DISPATCH(param_1);
      uVar12 = 0x56;
      if (cVar7 != '\0') {
        if (uVar9 < 2) {
          param_7 = 3;
          uVar5 = param_7;
        }
        else if (param_6 == 0) {
          param_7 = 0xff;
          uVar5 = param_7;
        }
        else {
          uVar5 = 3;
          if (param_6 == 2) {
            uVar5 = param_7;
          }
        }
        param_7 = uVar5;
        if (param_5 == '\0') {
          nvAssertFailedNoLog("bAllUsers","src/kernel/gpu/gpuvideo/videoeventlist.c",0x261);
        }
        else {
          lVar11 = __nvoc_dynamicCast(*(undefined8 *)(param_3 + 8),__nvoc_class_def_EventBuffer);
          if (lVar11 != 0) {
            lVar13 = multimapFindSubmap_IMPL(param_1 + 0x4948,0);
            if ((lVar13 == 0) &&
               (lVar13 = multimapInsertSubmap_IMPL(param_1 + 0x4948,0), lVar13 == 0)) {
              nvDbg_Printf("src/kernel/gpu/gpuvideo/videoeventlist.c",0x26c,"videoAddBindpoint",4,
                           "NVRM: failed to add UID binding!\n");
              return 0x1a;
            }
            lVar13 = multimapFindItem_IMPL(param_1 + 0x4948,0,lVar11);
            if (lVar13 != 0) {
              return 0;
            }
            plVar14 = (long *)multimapInsertItemNew_IMPL(param_1 + 0x4948,0,lVar11);
            if (plVar14 != (long *)0x0) {
              *plVar14 = lVar11;
              *(undefined4 *)(plVar14 + 1) = uVar2;
              *(undefined4 *)((long)plVar14 + 0xc) = param_4;
              *(undefined4 *)(plVar14 + 2) = uVar3;
              lVar10 = *(long *)(lVar10 + 0x248);
              *(bool *)((long)plVar14 + 0x21) = 1 < uVar9;
              plVar14[3] = lVar10;
              *(undefined1 *)(plVar14 + 4) = uVar6;
              *(undefined1 *)((long)plVar14 + 0x22) = param_7;
              sVar8 = *(short *)(param_1 + 0x4940) + 1;
              *(short *)(param_1 + 0x4940) = sVar8;
              if ((sVar8 == 1) && (*(int *)(param_1 + 0x39f8) != 0)) {
                lVar10 = 0;
                do {
                  lVar13 = *(long *)(param_1 + 0x3948 + lVar10 * 8);
                  if (((lVar13 != 0) && (*(char *)(lVar13 + 0x7c) == '\0')) &&
                     (*(long *)(lVar13 + 0x58) != 0)) {
                    *(undefined4 *)(*(long *)(lVar13 + 0x58) + 0xc) = 1;
                  }
                  lVar10 = lVar10 + 1;
                } while ((uint)lVar10 < *(uint *)(param_1 + 0x39f8));
              }
              uVar12 = registerEventNotification
                                 (lVar11 + 0x160,param_2,param_4,uVar3,0x10000001,0x7f,
                                  *(undefined8 *)(lVar11 + 0x1a8),0);
              if ((int)uVar12 == 0) {
                if (0 < sVar1) {
                  return uVar12;
                }
                uVar4 = *(undefined8 *)(param_1 + 0x1b88);
                uVar9 = tmrEventCreate_IMPL(uVar4,param_1 + 0x4978,_videoTimerCallback,0,9);
                if (uVar9 == 0) {
                  uVar12 = tmrEventScheduleRel_IMPL
                                     (uVar4,*(undefined8 *)(param_1 + 0x4978),50000000);
                  uVar9 = (uint)uVar12;
                  if (uVar9 == 0) {
                    return uVar12;
                  }
                  nvCheckOkFailedNoLog
                            (4,uVar12 & 0xffffffff,
                             "tmrEventScheduleRel(pTmr, pGpu->pVideoTimerEvent, NV_VIDEO_TRACE_CALLBACK_TIME_NS)"
                             ,"src/kernel/gpu/gpuvideo/videoeventlist.c",0x1c6);
                }
                else {
                  nvCheckOkFailedNoLog
                            (4,uVar9,
                             "tmrEventCreate(pTmr, &pGpu->pVideoTimerEvent, _videoTimerCallback, NULL, timerFlags)"
                             ,"src/kernel/gpu/gpuvideo/videoeventlist.c",0x1c2);
                }
                nvCheckOkFailedNoLog
                          (4,uVar9,"_videoTimerCreate(pGpu)",
                           "src/kernel/gpu/gpuvideo/videoeventlist.c",0x298);
                uVar12 = (ulong)uVar9;
              }
              videoRemoveBindpoint(param_1,0,plVar14);
              if (*(long *)(param_1 + 0x4978) == 0) {
                return uVar12 & 0xffffffff;
              }
              tmrEventDestroy_IMPL(*(undefined8 *)(param_1 + 0x1b88));
              *(undefined8 *)(param_1 + 0x4978) = 0;
              return uVar12 & 0xffffffff;
            }
          }
        }
        uVar12 = 0x1f;
      }
    }
  }
  return uVar12;
}


// ===== 00359e30 videoRemoveAllBindpointsForGpu =====

void videoRemoveAllBindpointsForGpu(long param_1)

{
  short sVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58 [5];
  
  if (*(long *)(param_1 + 0x4958) != 0) {
    sVar1 = *(short *)(param_1 + 0x4940);
    uVar3 = mapFindLEQ_IMPL(param_1 + 0x4948,0xffffffffffffffff);
    uVar4 = mapFindGEQ_IMPL(param_1 + 0x4948,0);
    mapIterRange_IMPL(&local_98,param_1 + 0x4948,uVar4,uVar3);
    local_78 = local_98;
    local_70 = local_90;
    local_68 = local_88;
    local_60 = local_80;
    while( true ) {
      cVar2 = mapIterNext_IMPL(&local_78);
      uVar3 = local_78;
      if (cVar2 == '\0') break;
      uVar4 = mapFindLEQ_IMPL(local_78,0xffffffffffffffff);
      uVar5 = mapFindGEQ_IMPL(uVar3,0);
      multimapItemIterRange_IMPL(local_58,param_1 + 0x4948,uVar5,uVar4);
      uVar4 = mapKey_IMPL(local_70,uVar3);
      while( true ) {
        cVar2 = multimapItemIterNext_IMPL(local_58);
        if (cVar2 == '\0') break;
        videoRemoveBindpoint(param_1,uVar4,local_58[0]);
        uVar5 = mapFindLEQ_IMPL(uVar3,0xffffffffffffffff);
        uVar6 = mapFindGEQ_IMPL(uVar3,0);
        multimapItemIterRange_IMPL(&local_98,param_1 + 0x4948,uVar6,uVar5);
        local_58[0] = local_98;
      }
    }
    if (((sVar1 != 0) && (*(short *)(param_1 + 0x4940) == 0)) && (*(long *)(param_1 + 0x4978) != 0))
    {
      tmrEventDestroy_IMPL(*(undefined8 *)(param_1 + 0x1b88));
      *(undefined8 *)(param_1 + 0x4978) = 0;
    }
    return;
  }
  return;
}


// ===== 0035a000 videoRemoveAllBindpoints =====

void videoRemoveAllBindpoints(undefined8 param_1)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_50 = 0;
  local_4c = 0;
  gpumgrGetGpuAttachInfo(0,&local_50);
  while( true ) {
    lVar2 = gpumgrGetNextGpu(local_50,&local_4c);
    if (lVar2 == 0) break;
    uVar3 = mapFindLEQ_IMPL(lVar2 + 0x4948,0xffffffffffffffff);
    uVar4 = mapFindGEQ_IMPL(lVar2 + 0x4948,0);
    mapIterRange_IMPL(&local_78,lVar2 + 0x4948,uVar4,uVar3);
    local_48 = local_78;
    local_40 = local_70;
    local_38 = local_68;
    local_30 = local_60;
    while( true ) {
      cVar1 = mapIterNext_IMPL(&local_48);
      if (cVar1 == '\0') break;
      uVar3 = mapKey_IMPL(local_40,local_48);
      while( true ) {
        lVar5 = multimapFindItem_IMPL(lVar2 + 0x4948,uVar3,param_1);
        if (lVar5 == 0) break;
        videoRemoveBindpoint(lVar2,uVar3,lVar5);
      }
    }
    if ((*(short *)(lVar2 + 0x4940) == 0) && (*(long *)(lVar2 + 0x4978) != 0)) {
      tmrEventDestroy_IMPL(*(undefined8 *)(lVar2 + 0x1b88));
      *(undefined8 *)(lVar2 + 0x4978) = 0;
    }
  }
  return;
}


// ===== 0035a160 kgraphicsSetFecsTraceHwEnable_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsSetFecsTraceHwEnable_GA100(long param_1,long param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(param_2 + 0x1d0))();
  uVar1 = uVar2 & 0x7fffffff;
  if (param_3 != '\0') {
    uVar1 = uVar2 | 0x80000000;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2104,uVar1,0);
  *(char *)(param_2 + 0x1f9) = param_3;
  return;
}


// ===== 0035a1d0 kgraphicsGetFecsTraceRdOffset_GA100 =====

uint kgraphicsGetFecsTraceRdOffset_GA100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2104,0);
  return uVar1 & 0x7fffffff;
}


// ===== 0035a200 kgraphicsSetFecsTraceRdOffset_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsSetFecsTraceRdOffset_GA100(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(param_2 + 0x1f0))();
  uVar1 = param_3 & 0x7fffffff;
  if (cVar2 != '\0') {
    uVar1 = param_3 | 0x80000000;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2104,uVar1,0);
  return;
}


// ===== 0035a260 kgraphicsSetFecsTraceWrOffset_GA100 =====

void kgraphicsSetFecsTraceWrOffset_GA100(long param_1,undefined8 param_2,undefined4 param_3)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2100,param_3,0);
  return;
}


// ===== 0035a290 kgrmgrGetVeidsFromGpcCount_GA100 =====

ulong kgrmgrGetVeidsFromGpcCount_GA100
                (undefined8 param_1,undefined8 param_2,int param_3,int *param_4)

{
  ulong uVar1;
  int local_1c [3];
  
  if (param_4 == (int *)0x0) {
    nvAssertFailedNoLog("pVeidCount != NULL","src/kernel/gpu/gr/arch/ampere/kgrmgr_ga100.c",0x28);
  }
  else {
    if (param_3 != 0) {
      uVar1 = kgrmgrGetVeidStepSize_IMPL(param_1,param_2,local_1c);
      if ((int)uVar1 == 0) {
        *param_4 = param_3 * local_1c[0];
        return uVar1;
      }
      nvAssertOkFailedNoLog
                (uVar1 & 0xffffffff,
                 "kgrmgrGetVeidStepSize(pGpu, pKernelGraphicsManager, &veidStepSize)",
                 "src/kernel/gpu/gr/arch/ampere/kgrmgr_ga100.c",0x2b);
      return uVar1 & 0xffffffff;
    }
    nvAssertFailedNoLog("gpcCount > 0","src/kernel/gpu/gr/arch/ampere/kgrmgr_ga100.c",0x29);
  }
  return 0x1f;
}


// ===== 0035a340 kgraphicsSetFecsTraceHwEnable_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsSetFecsTraceHwEnable_GB100(long param_1,long param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(param_2 + 0x1d0))();
  uVar1 = uVar2 & 0x7fffffff;
  if (param_3 != '\0') {
    uVar1 = uVar2 | 0x80000000;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2104,uVar1,0);
  *(char *)(param_2 + 0x1f9) = param_3;
  return;
}


// ===== 0035a3b0 kgraphicsSetFecsTraceRdOffset_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsSetFecsTraceRdOffset_GB100(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(param_2 + 0x1f0))();
  uVar1 = param_3 & 0x7fffffff;
  if (cVar2 != '\0') {
    uVar1 = param_3 | 0x80000000;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2104,uVar1,0);
  return;
}


// ===== 0035a410 kgraphicsSetFecsTraceWrOffset_GB100 =====

void kgraphicsSetFecsTraceWrOffset_GB100(long param_1,undefined8 param_2,undefined4 param_3)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2100,param_3,0);
  return;
}


// ===== 0035a440 kgrmgrGetVeidsFromGpcCount_GB100 =====

undefined1  [16]
kgrmgrGetVeidsFromGpcCount_GB100(undefined8 param_1,long param_2,ulong param_3,uint *param_4)

{
  long lVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  uint uVar4;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 uVar5;
  undefined8 extraout_RDX_02;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  
  if (param_4 == (uint *)0x0) {
    nvAssertFailedNoLog("pVeidCount != NULL","src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb100.c",0x2d)
    ;
    uVar5 = extraout_RDX;
  }
  else {
    uVar4 = (uint)param_3;
    if (uVar4 != 0) {
      if (*(char *)(param_2 + 0x438) == '\0') {
        nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                            ,"src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb100.c",0x2f);
        uVar5 = extraout_RDX_01;
      }
      else {
        lVar1 = *(long *)(param_2 + 0x430);
        if (lVar1 != 0) {
          uVar3 = *(uint *)(lVar1 + 0x1ac);
          if (uVar3 != 0) {
            do {
              param_3 = (ulong)*(uint *)(lVar1 + 0x1b4) % (ulong)uVar3;
              if (uVar4 <= *(uint *)(lVar1 + 0x1b4) / uVar3) {
                param_3 = (ulong)*(uint *)(lVar1 + 0x164) % (ulong)uVar3;
                *param_4 = *(uint *)(lVar1 + 0x164) / uVar3;
                goto LAB_0035a4ae;
              }
              uVar3 = uVar3 >> 1;
            } while (uVar3 != 0);
          }
          *param_4 = 0;
LAB_0035a4ae:
          auVar2._8_8_ = 0;
          auVar2._0_8_ = param_3;
          return auVar2 << 0x40;
        }
        nvAssertFailedNoLog("pGrInfo != NULL","src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb100.c",0x31
                           );
        uVar5 = extraout_RDX_02;
      }
      auVar7._8_8_ = uVar5;
      auVar7._0_8_ = 0x40;
      return auVar7;
    }
    nvAssertFailedNoLog("gpcCount > 0","src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb100.c",0x2e);
    uVar5 = extraout_RDX_00;
  }
  auVar6._8_8_ = uVar5;
  auVar6._0_8_ = 0x1f;
  return auVar6;
}


// ===== 0035a540 kgrmgrGetVeidsFromGpcCount_GB10B =====

undefined1  [16]
kgrmgrGetVeidsFromGpcCount_GB10B(undefined8 param_1,long param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined1 auVar5 [16];
  ulong uVar6;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 uVar7;
  undefined8 extraout_RDX_02;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  
  if (param_4 == (uint *)0x0) {
    nvAssertFailedNoLog("pVeidCount != NULL","src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb10b.c",0x2b)
    ;
    uVar7 = extraout_RDX;
  }
  else {
    if (param_3 != 0) {
      if (*(char *)(param_2 + 0x438) == '\0') {
        nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized"
                            ,"src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb10b.c",0x2d);
        uVar7 = extraout_RDX_01;
      }
      else {
        lVar4 = *(long *)(param_2 + 0x430);
        if (lVar4 != 0) {
          iVar1 = *(int *)(lVar4 + 0x1b4);
          uVar2 = *(uint *)(lVar4 + 0x164);
          uVar6 = (ulong)uVar2;
          uVar3 = *(uint *)(lVar4 + 0x1ac);
          nvDbg_Printf("src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb10b.c",0x35,
                       "kgrmgrGetVeidsFromGpcCount_GB10B",1,
                       "NVRM: Max SysPipes:%d, Max GPCs:%d, Max VEIDs:%d.\n",uVar3,iVar1);
          if (param_3 == iVar1) {
            *param_4 = uVar2;
          }
          else {
            uVar6 = uVar6 % (ulong)uVar3;
            *param_4 = uVar2 / uVar3;
          }
          auVar5._8_8_ = 0;
          auVar5._0_8_ = uVar6;
          return auVar5 << 0x40;
        }
        nvAssertFailedNoLog("pGrInfo != NULL","src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb10b.c",0x2f
                           );
        uVar7 = extraout_RDX_02;
      }
      auVar9._8_8_ = uVar7;
      auVar9._0_8_ = 0x40;
      return auVar9;
    }
    nvAssertFailedNoLog("gpcCount > 0","src/kernel/gpu/gr/arch/blackwell/kgrmgr_gb10b.c",0x2c);
    uVar7 = extraout_RDX_00;
  }
  auVar8._8_8_ = uVar7;
  auVar8._0_8_ = 0x1f;
  return auVar8;
}


// ===== 0035a6a0 kgraphicsAllocGrGlobalCtxBuffers_GM200 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgraphicsAllocGrGlobalCtxBuffers_GM200(long param_1,long param_2,uint param_3,long param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  long lVar7;
  char cVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  char *pcVar15;
  undefined8 uVar16;
  long *plVar17;
  undefined8 *puVar18;
  ulong uVar19;
  bool bVar20;
  ulong local_78;
  long local_48;
  long local_40 [2];
  
  lVar7 = *(long *)(param_1 + 0x1b78);
  lVar12 = kgraphicsGetStaticInfo_IMPL();
  if (lVar12 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",0x44);
    return 0x40;
  }
  lVar12 = *(long *)(lVar12 + 0x13d8);
  if (lVar12 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                        "src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",0x45);
    return 0x40;
  }
  iVar1 = *(int *)(lVar12 + 0x88);
  uVar10 = *(undefined4 *)(lVar12 + 0x94);
  iVar2 = *(int *)(lVar12 + 0x98);
  local_48 = 0;
  uVar9 = *(undefined4 *)(lVar12 + 0x8c);
  iVar3 = *(int *)(lVar12 + 0xc0);
  iVar4 = *(int *)(lVar12 + 0x90);
  uVar19 = (-(ulong)(*(char *)(param_2 + 0x206) == '\0') & 0xffffffffffffe000) + 0x2004;
  uVar5 = *(undefined4 *)(lVar12 + 0x9c);
  uVar6 = *(undefined4 *)(lVar12 + 0xc4);
  if (param_4 == 0) {
    lVar12 = *(long *)(param_2 + 0x230);
    uVar11 = ctxBufPoolGetGlobalPool(param_1,2,*(int *)(param_2 + 0x20c) + 1,&local_48);
    uVar16 = 0x86;
    pcVar15 = 
    "ctxBufPoolGetGlobalPool(pGpu, CTX_BUF_ID_GR_GLOBAL, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &pCtxBufPool)"
    ;
    if (uVar11 != 0) goto LAB_0035ae8e;
    puVar18 = (undefined8 *)(param_2 + 0x248);
    plVar17 = (long *)(lVar12 + (ulong)param_3 * 0x60);
  }
  else {
    uVar13 = kgrctxGetUnicast_IMPL(param_1,param_4,local_40);
    uVar16 = 0x6d;
    pcVar15 = "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)";
    if ((int)uVar13 != 0) goto LAB_0035adfe;
    if (*(char *)(local_40[0] + 0x148) != '\0') {
      return uVar13;
    }
    plVar17 = (long *)(local_40[0] + 0xf8);
    puVar18 = (undefined8 *)(param_2 + 0x2e8);
    if (*(char *)(local_40[0] + 0x590) != '\0') {
      uVar19 = uVar19 | 0x80;
    }
    uVar19 = uVar19 | 0x2000000;
  }
  local_78 = 0;
  if (param_3 != 0) {
    local_78 = 0x2000000;
    puVar18 = (undefined8 *)(param_2 + 0x388);
    uVar19 = uVar19 | 0x2000000;
  }
  cVar8 = ctxBufPoolIsSupported(param_1);
  if ((cVar8 != '\0') && (local_48 != 0)) {
    local_78 = local_78 | 0x1000000000;
    uVar19 = uVar19 | 0x1000000000;
  }
  if (iVar1 != 0) {
    uVar13 = memdescCreate(plVar17,param_1,iVar1,uVar9,
                           (undefined8 *)*puVar18 == &ADDRLIST_FBMEM_ONLY,0,
                           *(undefined4 *)(puVar18 + 1),uVar19 | 0x82000);
    uVar16 = 0xa2;
    pcVar15 = 
    "memdescCreate(ppMemDesc, pGpu, circularBufferSize, circularBufferAlign, bPhysicallyContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_BUNDLE_CB].cpuAttr, cbAllocFlags | MEMDESC_FLAGS_GPU_PRIVILEGED | MEMDESC_FLAGS_HIGH_PRIORITY)"
    ;
    if ((int)uVar13 != 0) goto LAB_0035adfe;
    memdescSetGpuCacheAttrib
              (*plVar17,0,
               "memdescCreate(ppMemDesc, pGpu, circularBufferSize, circularBufferAlign, bPhysicallyContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_BUNDLE_CB].cpuAttr, cbAllocFlags | MEMDESC_FLAGS_GPU_PRIVILEGED | MEMDESC_FLAGS_HIGH_PRIORITY)"
               ,"src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",0xa2);
    if ((uVar19 >> 0x24 & 1) == 0) {
LAB_0035a98e:
      uVar9 = (**(code **)(lVar7 + 0x288))(param_1);
      kgraphicsSetContextBufferPteKind_IMPL(param_1,param_2,plVar17,0,1,uVar9);
      *(undefined4 *)(*plVar17 + 0x9c) = 0xf;
      uVar13 = memdescAllocList(*plVar17,*puVar18);
      uVar16 = 0xb5;
      if ((int)uVar13 == 0) goto joined_r0x0035a9e7;
      goto LAB_0035adf0;
    }
    (**(code **)(lVar7 + 0x388))(param_1,lVar7,*plVar17,1,1);
    uVar11 = memdescSetCtxBufPool(*plVar17,local_48);
    uVar16 = 0xaf;
    if (uVar11 == 0) goto LAB_0035a98e;
LAB_0035ae80:
    pcVar15 = "memdescSetCtxBufPool(*ppMemDesc, pCtxBufPool)";
LAB_0035ae8e:
    nvAssertOkFailedNoLog(uVar11,pcVar15,"src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",uVar16);
    return (ulong)uVar11;
  }
joined_r0x0035a9e7:
  if (iVar4 == 0) {
joined_r0x0035aaed:
    if (iVar2 != 0) {
      uVar14 = (ulong)*(uint *)(puVar18 + 5);
      uVar13 = memdescCreate(plVar17 + 2,param_1,iVar2,uVar5,
                             (undefined8 *)puVar18[4] == &ADDRLIST_FBMEM_ONLY,0,uVar14,
                             uVar19 | 0x80000);
      uVar16 = 0xda;
      pcVar15 = 
      "memdescCreate(ppMemDesc, pGpu, attribBufferSize, attribBufferAlign, bPhysicallyContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_ATTRIBUTE_CB].cpuAttr, cbAllocFlags | MEMDESC_FLAGS_HIGH_PRIORITY)"
      ;
      if ((int)uVar13 != 0) goto LAB_0035adfe;
      memdescSetGpuCacheAttrib
                (plVar17[2],0,
                 "memdescCreate(ppMemDesc, pGpu, attribBufferSize, attribBufferAlign, bPhysicallyContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_ATTRIBUTE_CB].cpuAttr, cbAllocFlags | MEMDESC_FLAGS_HIGH_PRIORITY)"
                 ,"src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",0xda,uVar14);
      if ((uVar19 >> 0x24 & 1) != 0) {
        (**(code **)(lVar7 + 0x388))(param_1,lVar7,plVar17[2],1,1);
        uVar11 = memdescSetCtxBufPool(plVar17[2],local_48);
        uVar16 = 0xe7;
        if (uVar11 != 0) goto LAB_0035ae80;
      }
      uVar10 = (**(code **)(lVar7 + 0x288))(param_1);
      kgraphicsSetContextBufferPteKind_IMPL(param_1,param_2,plVar17 + 2,2,1,uVar10);
      *(undefined4 *)(plVar17[2] + 0x9c) = 0xd;
      uVar13 = memdescAllocList(plVar17[2],puVar18[4]);
      uVar16 = 0xed;
      if ((int)uVar13 != 0) goto LAB_0035adf0;
      memdescSetName(param_1,plVar17[2],"rm_gr_ctx_circular_buffer_surface",0,0xed);
    }
    if (((param_4 != 0) || (*(char *)(param_2 + 0x207) == '\0')) || (iVar3 == 0)) goto LAB_0035a84e;
    bVar20 = *(char *)(param_1 + 0x4a23) != '\0';
    uVar13 = memdescCreate(plVar17 + 7,param_1,iVar3,uVar6,bVar20,0,*(undefined4 *)(puVar18 + 0xf),
                           local_78);
    uVar16 = 0xfe;
    pcVar15 = 
    "memdescCreate(ppMemDesc, pGpu, privMapBufferSize, privMapBufferAlign, bIsContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_PRIV_ACCESS_MAP].cpuAttr, flags)"
    ;
    if ((int)uVar13 != 0) goto LAB_0035adfe;
    if (*(char *)(param_2 + 0x1fc) != '\0') {
      memdescSetGpuCacheAttrib
                (plVar17[7],0,
                 "memdescCreate(ppMemDesc, pGpu, privMapBufferSize, privMapBufferAlign, bIsContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_PRIV_ACCESS_MAP].cpuAttr, flags)"
                 ,"src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",0xfe);
    }
    if ((local_78 & 0x1000000000) != 0) {
      (**(code **)(lVar7 + 0x388))(param_1,lVar7,plVar17[7],1,1);
      uVar11 = memdescSetCtxBufPool(plVar17[7],local_48);
      uVar16 = 0x110;
      if (uVar11 != 0) goto LAB_0035ae80;
    }
    *(undefined4 *)(plVar17[7] + 0x9c) = 0x11;
    uVar13 = memdescAllocList(plVar17[7],puVar18[0xe]);
    uVar16 = 0x113;
    if ((int)uVar13 == 0) {
      cVar8 = (**(code **)(param_2 + 0x1c8))(param_1,param_2);
      if (cVar8 == '\0') goto LAB_0035a84e;
      uVar13 = memdescCreate(plVar17 + 8,param_1,iVar3,uVar6,bVar20,0,
                             *(undefined4 *)(puVar18 + 0x11),local_78);
      uVar16 = 0x11f;
      pcVar15 = 
      "memdescCreate(ppMemDesc, pGpu, unresPrivMapBufferSize, unresPrivMapBufferAlign, bIsContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_UNRESTRICTED_PRIV_ACCESS_MAP].cpuAttr, flags)"
      ;
      if ((int)uVar13 != 0) goto LAB_0035adfe;
      if (*(char *)(param_2 + 0x1fc) != '\0') {
        memdescSetGpuCacheAttrib
                  (plVar17[8],0,
                   "memdescCreate(ppMemDesc, pGpu, unresPrivMapBufferSize, unresPrivMapBufferAlign, bIsContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_UNRESTRICTED_PRIV_ACCESS_MAP].cpuAttr, flags)"
                   ,"src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",0x11f);
      }
      if ((local_78 & 0x1000000000) != 0) {
        (**(code **)(lVar7 + 0x388))(param_1,lVar7,plVar17[8],1,1);
        uVar11 = memdescSetCtxBufPool(plVar17[8],local_48);
        if (uVar11 != 0) {
          uVar16 = 0x132;
          goto LAB_0035ae80;
        }
      }
      *(undefined4 *)(plVar17[8] + 0x9c) = 0x11;
      uVar13 = memdescAllocList(plVar17[8],puVar18[0x10]);
      if ((int)uVar13 == 0) {
LAB_0035a84e:
        *(undefined1 *)(plVar17 + 10) = 1;
        return 0;
      }
      uVar16 = 0x137;
    }
  }
  else {
    uVar13 = memdescCreate(plVar17 + 1,param_1,iVar4,uVar10,
                           (undefined8 *)puVar18[2] == &ADDRLIST_FBMEM_ONLY,0,
                           *(undefined4 *)(puVar18 + 3),uVar19 | 0x2000);
    uVar16 = 0xbe;
    pcVar15 = 
    "memdescCreate(ppMemDesc, pGpu, pagepoolBufferSize, pagepoolBufferAlign, bPhysicallyContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_PAGEPOOL].cpuAttr, cbAllocFlags | MEMDESC_FLAGS_GPU_PRIVILEGED)"
    ;
    if ((int)uVar13 != 0) goto LAB_0035adfe;
    memdescSetGpuCacheAttrib
              (plVar17[1],0,
               "memdescCreate(ppMemDesc, pGpu, pagepoolBufferSize, pagepoolBufferAlign, bPhysicallyContiguous, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_PAGEPOOL].cpuAttr, cbAllocFlags | MEMDESC_FLAGS_GPU_PRIVILEGED)"
               ,"src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",0xbe);
    if ((uVar19 >> 0x24 & 1) != 0) {
      (**(code **)(lVar7 + 0x388))(param_1,lVar7,plVar17[1],1,1);
      uVar11 = memdescSetCtxBufPool(plVar17[1],local_48);
      uVar16 = 0xcb;
      if (uVar11 != 0) goto LAB_0035ae80;
    }
    uVar10 = (**(code **)(lVar7 + 0x288))(param_1);
    kgraphicsSetContextBufferPteKind_IMPL(param_1,param_2,plVar17 + 1,1,1,uVar10);
    *(undefined4 *)(plVar17[1] + 0x9c) = 0x10;
    uVar13 = memdescAllocList(plVar17[1],puVar18[2]);
    uVar16 = 0xd1;
    if ((int)uVar13 == 0) goto joined_r0x0035aaed;
  }
LAB_0035adf0:
  pcVar15 = "status";
LAB_0035adfe:
  nvCheckOkFailedNoLog
            (4,uVar13 & 0xffffffff,pcVar15,"src/kernel/gpu/gr/arch/maxwell/kgraphics_gm200.c",uVar16
            );
  return uVar13 & 0xffffffff;
}


// ===== 0035aed0 kgraphicsSetFecsTraceRdOffset_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void kgraphicsSetFecsTraceRdOffset_GP100(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    nvAssertFailedNoLog("!IS_VIRTUAL(pGpu)","src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x3d);
  }
  cVar2 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,*(code **)(param_2 + 0x1f0));
  uVar1 = param_3 & 0x7fffffff;
  if (cVar2 != '\0') {
    uVar1 = param_3 | 0x80000000;
  }
  regWrite032(param_1 + 0x3a18,0,0,0x409044,uVar1,0);
  return;
}


// ===== 0035af70 kgraphicsSetFecsTraceWrOffset_GP100 =====

void kgraphicsSetFecsTraceWrOffset_GP100
               (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  if (*(char *)(param_1 + 0x908) != '\0') {
    nvAssertFailedNoLog("!IS_VIRTUAL(pGpu)","src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x51,
                        param_4,param_3);
  }
  regWrite032(param_1 + 0x3a18,0,0,0x409040,param_3,0);
  return;
}


// ===== 0035afe0 kgraphicsSetFecsTraceHwEnable_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsSetFecsTraceHwEnable_GP100(long param_1,long param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(param_2 + 0x1d0))();
  if (*(char *)(param_1 + 0x908) != '\0') {
    nvAssertFailedNoLog("!IS_VIRTUAL(pGpu)","src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x61);
  }
  uVar1 = uVar2 & 0x7fffffff;
  if (param_3 != '\0') {
    uVar1 = uVar2 | 0x80000000;
  }
  regWrite032(param_1 + 0x3a18,0,0,0x409044,uVar1,0);
  *(char *)(param_2 + 0x1f9) = param_3;
  return;
}


// ===== 0035b070 kgraphicsInitFecsRegistryOverrides_GP100 =====

void kgraphicsInitFecsRegistryOverrides_GP100(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int local_1c;
  
  iVar2 = osReadRegistryDword(param_1,"RMCtxswLog",&local_1c);
  if (iVar2 == 0) {
    uVar3 = local_1c - 1;
    if (2 < uVar3) {
      uVar5 = 0;
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined1 *)((long)&CSWTCH_24 + (ulong)uVar3);
      uVar5 = *(undefined1 *)((long)&CSWTCH_25 + (ulong)uVar3);
    }
    *(undefined1 *)(param_2 + 0x1fb) = uVar4;
    *(undefined1 *)(param_2 + 0x1fa) = uVar5;
    *(bool *)(param_2 + 0x1f8) = 2 >= uVar3;
  }
  cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if (cVar1 != '\0') {
    cVar1 = gpuIsCCDevToolsModeEnabled_IMPL(param_1);
    if (cVar1 == '\0') {
      *(undefined1 *)(param_2 + 0x1f8) = 0;
    }
  }
  fecsSetRecordsPerIntr(param_1,param_2,0x30);
  iVar2 = osReadRegistryDword(param_1,"RMCtxswLogMaxRecordsPerIntr",&local_1c);
  if (iVar2 != 0) {
    return;
  }
  fecsSetRecordsPerIntr(param_1,param_2,local_1c);
  return;
}


// ===== 0035b160 kgraphicsAllocGrGlobalCtxBuffers_GP100 =====

ulong kgraphicsAllocGrGlobalCtxBuffers_GP100
                (undefined8 param_1,long param_2,undefined4 param_3,long param_4)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  undefined8 local_38;
  long local_30;
  
  local_38 = 0;
  if (param_4 == 0) {
    uVar1 = ctxBufPoolGetGlobalPool(param_1,2,*(int *)(param_2 + 0x20c) + 1,&local_38);
    if (uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1,
                 "ctxBufPoolGetGlobalPool(pGpu, CTX_BUF_ID_GR_GLOBAL, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &pCtxBufPool)"
                 ,"src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0xcd);
      return (ulong)uVar1;
    }
  }
  else {
    uVar2 = kgrctxGetUnicast_IMPL(param_1,param_4,&local_30);
    if ((int)uVar2 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar2 & 0xffffffff,
                 "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
                 "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0xbd);
      return uVar2 & 0xffffffff;
    }
    if (*(char *)(local_30 + 0x148) != '\0') {
      return uVar2;
    }
  }
  lVar3 = kgraphicsGetStaticInfo_IMPL(param_1,param_2);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0xd2);
  }
  else {
    if (*(long *)(lVar3 + 0x13d8) != 0) {
      uVar2 = kgraphicsAllocGrGlobalCtxBuffers_GM200(param_1,param_2,param_3,param_4);
      return uVar2;
    }
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                        "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0xd3);
  }
  return 0x40;
}


// ===== 0035b2b0 kgraphicsAllocGlobalCtxBuffers_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgraphicsAllocGlobalCtxBuffers_GP100(long param_1,long param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  uint local_3c;
  long local_30;
  
  local_30 = 0;
  if (param_3 != 0) {
    return 0;
  }
  lVar3 = *(long *)(param_2 + 0x230);
  uVar5 = ctxBufPoolGetGlobalPool(param_1,2,*(int *)(param_2 + 0x20c) + 1,&local_30);
  lVar4 = local_30;
  if (uVar5 != 0) {
    nvAssertOkFailedNoLog
              (uVar5,
               "ctxBufPoolGetGlobalPool(pGpu, CTX_BUF_ID_GR_GLOBAL, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &pCtxBufPool)"
               ,"src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0xf4);
LAB_0035b4a4:
    return (ulong)uVar5;
  }
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0'))
  goto LAB_0035b4a4;
  lVar6 = kgraphicsGetStaticInfo_IMPL(param_1,param_2);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x105);
    return 0x40;
  }
  iVar1 = *(int *)(*(long *)(lVar6 + 0x13d8) + 0xb8);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(char *)(param_2 + 0x1f8) == '\0') goto LAB_0035b4a4;
  uVar2 = *(undefined4 *)(*(long *)(lVar6 + 0x13d8) + 0xbc);
  if ((*(char *)(param_1 + 0x44d) == '\0') && (*(char *)(param_1 + 1099) == '\0')) {
    uVar9 = *(undefined4 *)(param_2 + 0x2b0);
  }
  else {
    *(undefined8 **)(param_2 + 0x2a8) = &ADDRLIST_SYSMEM_ONLY;
    uVar9 = 1;
    *(undefined4 *)(param_2 + 0x2b0) = 1;
  }
  uVar7 = memdescCreate(lVar3 + 0x30,param_1,iVar1,uVar2,1,0,uVar9,
                        (ulong)(lVar4 != 0) << 0x24 | 0x2400);
  uVar10 = 0x11a;
  pcVar8 = 
  "memdescCreate(ppMemDesc, pGpu, fecsBufferSize, fecsBufferAlign, NV_TRUE, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_FECS_EVENT].cpuAttr, allocFlags | MEMDESC_FLAGS_PHYSICALLY_CONTIGUOUS | MEMDESC_FLAGS_GPU_PRIVILEGED)"
  ;
  if ((int)uVar7 == 0) {
    lVar6 = *(long *)(lVar3 + 0x30);
    if ((*(char *)(param_2 + 0x1fc) != '\0') || (*(int *)(lVar6 + 0x68) == 2)) {
      memdescSetGpuCacheAttrib
                (lVar6,0,lVar6,"src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x11a);
      lVar6 = *(long *)(lVar3 + 0x30);
    }
    if (lVar4 != 0) {
      (**(code **)(*(long *)(param_1 + 0x1b78) + 0x388))
                (param_1,*(long *)(param_1 + 0x1b78),lVar6,1,1);
      local_3c = memdescSetCtxBufPool(*(undefined8 *)(lVar3 + 0x30),local_30);
      if (local_3c != 0) {
        nvAssertOkFailedNoLog
                  (local_3c,"memdescSetCtxBufPool(*ppMemDesc, pCtxBufPool)",
                   "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",299);
        goto LAB_0035b484;
      }
      lVar6 = *(long *)(lVar3 + 0x30);
    }
    *(undefined4 *)(lVar6 + 0x9c) = 0x8d;
    uVar7 = memdescAllocList(*(undefined8 *)(lVar3 + 0x30),*(undefined8 *)(param_2 + 0x2a8));
    if ((int)uVar7 == 0) {
      return uVar7;
    }
    uVar10 = 0x130;
    pcVar8 = "status";
  }
  local_3c = (uint)uVar7;
  nvCheckOkFailedNoLog
            (4,uVar7 & 0xffffffff,pcVar8,"src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",uVar10);
LAB_0035b484:
  return (ulong)local_3c;
}


// ===== 0035b590 kgraphicsServiceInterrupt_GP100 =====

undefined8 kgraphicsServiceInterrupt_GP100(long param_1,long param_2,ushort *param_3)

{
  int iVar1;
  undefined8 uVar2;
  char cVar3;
  short sVar4;
  
  if (param_3 == (ushort *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x146);
    return 0;
  }
  iVar1 = *(int *)(param_2 + 0x20c);
  if ((uint)*param_3 == iVar1 + 0x9cU) {
    uVar2 = *(undefined8 *)(param_1 + 0x1bc8);
    if (((*(long *)(param_1 + 0x1bc0) == 0) ||
        (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar3 == '\0')) && (iVar1 != 0)) {
      nvAssertFailedNoLog("GR[1-7]_FECS_LOG is not supported if MIG is disabled!",
                          "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x14c);
      return 0;
    }
    sVar4 = fecsGetCtxswLogConsumerCount(param_1,uVar2);
    if (((0 < sVar4) && (*(char *)(param_2 + 0x1fa) != '\0')) &&
       (cVar3 = fecsClearIntrPendingIfPending(param_1,param_2), cVar3 != '\0')) {
      nvEventBufferFecsCallback(param_1,param_2);
    }
  }
  else {
    nvAssertFailedNoLog("pParams->engineIdx == MC_ENGINE_IDX_GRn_FECS_LOG(grIdx)",
                        "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x147);
  }
  return 0;
}


// ===== 0035b6c0 kgraphicsClearInterrupt_GP100 =====

undefined8 kgraphicsClearInterrupt_GP100(undefined8 param_1,long param_2,ushort *param_3)

{
  if (param_3 == (ushort *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x16d);
  }
  else {
    if ((uint)*param_3 == *(int *)(param_2 + 0x20c) + 0x9cU) {
      return 1;
    }
    nvAssertFailedNoLog("pParams->engineIdx == MC_ENGINE_IDX_GRn_FECS_LOG(grIdx)",
                        "src/kernel/gpu/gr/arch/pascal/kgraphics_gp100.c",0x16e);
  }
  return 0;
}


// ===== 0035b730 kgraphicsAllocGrGlobalCtxBuffers_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgraphicsAllocGrGlobalCtxBuffers_TU102(long param_1,long param_2,uint param_3,long param_4)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  char *pcVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  bool local_55;
  long local_48;
  long local_40 [2];
  
  local_48 = 0;
  local_55 = true;
  if (*(char *)(param_1 + 0x44d) == '\0') {
    local_55 = *(char *)(param_1 + 1099) != '\0';
  }
  uVar8 = (-(ulong)(*(char *)(param_2 + 0x206) == '\0') & 0xffffffffffffe000) + 0x2004;
  if (param_4 == 0) {
    lVar9 = *(long *)(param_2 + 0x230);
    uVar3 = ctxBufPoolGetGlobalPool(param_1,2,*(int *)(param_2 + 0x20c) + 1,&local_48);
    if (uVar3 != 0) {
      nvAssertOkFailedNoLog
                (uVar3,
                 "ctxBufPoolGetGlobalPool(pGpu, CTX_BUF_ID_GR_GLOBAL, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &pCtxBufPool)"
                 ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x82);
      return (ulong)uVar3;
    }
    lVar9 = (ulong)param_3 * 0x60 + lVar9;
    lVar10 = param_2 + 0x248;
  }
  else {
    uVar4 = kgrctxGetUnicast_IMPL(param_1,param_4,local_40);
    uVar7 = 0x69;
    pcVar6 = "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)";
    if ((int)uVar4 != 0) goto LAB_0035ba04;
    if (*(char *)(local_40[0] + 0x148) != '\0') {
      return uVar4;
    }
    lVar9 = local_40[0] + 0xf8;
    lVar10 = param_2 + 0x2e8;
    if (*(char *)(local_40[0] + 0x590) != '\0') {
      uVar8 = uVar8 | 0x80;
    }
    uVar8 = uVar8 | 0x2000000;
  }
  cVar1 = ctxBufPoolIsSupported(param_1);
  if ((cVar1 != '\0') && (local_48 != 0)) {
    uVar8 = uVar8 | 0x1000000000;
  }
  if (param_3 != 0) {
    lVar10 = param_2 + 0x388;
  }
  if (param_3 != 0) {
    uVar8 = uVar8 | 0x2000000;
  }
  lVar5 = kgraphicsGetStaticInfo_IMPL(param_1,param_2);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x93);
    return 0x40;
  }
  lVar5 = *(long *)(lVar5 + 0x13d8);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                        "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x94);
    return 0x40;
  }
  if (*(int *)(lVar5 + 0xa0) == 0) {
LAB_0035b91e:
    uVar8 = kgraphicsAllocGrGlobalCtxBuffers_GP100(param_1,param_2,param_3,param_4);
    return uVar8;
  }
  uVar2 = *(undefined4 *)(lVar10 + 0x38);
  uVar4 = memdescCreate(lVar9 + 0x18,param_1,*(int *)(lVar5 + 0xa0),*(undefined4 *)(lVar5 + 0xa4),
                        local_55 ^ 1,0);
  if ((int)uVar4 == 0) {
    memdescSetGpuCacheAttrib(*(undefined8 *)(lVar9 + 0x18),0,uVar2,uVar8);
    if ((uVar8 >> 0x24 & 1) != 0) {
      (**(code **)(*(long *)(param_1 + 0x1b78) + 0x388))
                (param_1,*(long *)(param_1 + 0x1b78),*(undefined8 *)(lVar9 + 0x18),1,1);
      uVar3 = memdescSetCtxBufPool(*(undefined8 *)(lVar9 + 0x18),local_48);
      if (uVar3 != 0) {
        nvAssertOkFailedNoLog
                  (uVar3,"memdescSetCtxBufPool(*ppMemDesc, pCtxBufPool)",
                   "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0xad);
        return (ulong)uVar3;
      }
    }
    uVar2 = (**(code **)(*(long *)(param_1 + 0x1b78) + 0x288))(param_1);
    kgraphicsSetContextBufferPteKind_IMPL(param_1,param_2,lVar9 + 0x18,3,1,uVar2);
    *(undefined4 *)(*(long *)(lVar9 + 0x18) + 0x9c) = 0x92;
    uVar4 = memdescAllocList(*(undefined8 *)(lVar9 + 0x18),*(undefined8 *)(lVar10 + 0x30));
    uVar7 = 0xb4;
    pcVar6 = "status";
    if ((int)uVar4 == 0) goto LAB_0035b91e;
  }
  else {
    uVar7 = 0x9e;
    pcVar6 = 
    "memdescCreate(ppMemDesc, pGpu, rtvcbBufferSize, rtvcbBufferAlign, !bIsFbBroken, ADDR_UNKNOWN, pCtxAttr[GR_GLOBALCTX_BUFFER_RTV_CB].cpuAttr, allocFlags)"
    ;
  }
LAB_0035ba04:
  nvCheckOkFailedNoLog
            (4,uVar4 & 0xffffffff,pcVar6,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",uVar7);
  return uVar4 & 0xffffffff;
}


// ===== 0035baa0 kgraphicsTeardownBug4208224State_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsTeardownBug4208224State_TU102(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined1 local_19;
  
  lVar2 = gpumgrGetParentGPU();
  if (param_1 == lVar2) {
    if ((*(char *)(param_2 + 0x5cc) != '\0') && (*(char *)(param_1 + 0x908) == '\0')) {
      lVar2 = gpumgrGetParentGPU(param_1);
      if (param_1 == lVar2) {
        lVar2 = rmapiGetInterface(4);
        local_19 = 1;
        iVar1 = (**(code **)(lVar2 + 0x38))
                          (lVar2,*(undefined4 *)(param_2 + 0x5c0),*(undefined4 *)(param_2 + 0x5c4),
                           0x802046,&local_19,1);
        if (iVar1 != 0) {
          nvAssertOkFailedNoLog
                    (iVar1,
                     "pRmApi->Control(pRmApi, pKernelGraphics->bug4208224Info.hClient, pKernelGraphics->bug4208224Info.hDeviceId, NV0080_CTRL_CMD_INTERNAL_KGR_INIT_BUG4208224_WAR, &params, sizeof(params))"
                     ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0xd9);
        }
        iVar1 = (**(code **)(lVar2 + 0x18))
                          (lVar2,*(undefined4 *)(param_2 + 0x5c0),*(undefined4 *)(param_2 + 0x5c0));
        if (iVar1 != 0) {
          nvAssertOkFailedNoLog
                    (iVar1,
                     "pRmApi->Free(pRmApi, pKernelGraphics->bug4208224Info.hClient, pKernelGraphics->bug4208224Info.hClient)"
                     ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0xdf);
        }
        *(undefined1 *)(param_2 + 0x5cc) = 0;
      }
    }
    return;
  }
  nvAssertFailedNoLog("gpumgrIsParentGPU(pGpu)","src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",
                      0xc5);
  return;
}


// ===== 0035bbb0 kgraphicsInitializeBug4208224WAR_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgraphicsInitializeBug4208224WAR_TU102(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined1 local_29 [9];
  
  lVar3 = rmapiGetInterface(4);
  local_29[0] = 0;
  if ((*(char *)(param_2 + 0x5cc) == '\0') &&
     (lVar4 = gpumgrGetParentGPU(param_1), param_1 == lVar4)) {
    iVar1 = (**(code **)(param_2 + 400))(param_1,param_2);
    if (iVar1 == 0) {
      local_29[0] = 0;
      iVar1 = (**(code **)(lVar3 + 0x38))
                        (lVar3,*(undefined4 *)(param_2 + 0x5c0),*(undefined4 *)(param_2 + 0x5c4),
                         0x802046,local_29,1);
      if ((iVar1 == 0) ||
         (iVar2 = (**(code **)(lVar3 + 0x18))
                            (lVar3,*(undefined4 *)(param_2 + 0x5c0),*(undefined4 *)(param_2 + 0x5c0)
                            ), iVar2 == 0)) {
        return iVar1;
      }
      nvAssertOkFailedNoLog
                (iVar2,
                 "pRmApi->Free(pRmApi, pKernelGraphics->bug4208224Info.hClient, pKernelGraphics->bug4208224Info.hClient)"
                 ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x119);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar1,"kgraphicsCreateBug4208224Channel_HAL(pGpu, pKernelGraphics)",
                 "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x100);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 0035bce0 kgraphicsCreateBug4208224Channel_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgraphicsCreateBug4208224Channel_TU102(long param_1,long param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 extraout_RDX;
  undefined8 uVar7;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  int local_26c;
  undefined8 local_268;
  undefined1 local_260 [4];
  undefined4 local_25c;
  ulong local_228;
  undefined4 local_220;
  undefined8 local_210;
  undefined8 local_1e8;
  undefined4 local_1bc;
  int local_1a8 [7];
  undefined8 local_18c;
  undefined4 local_128;
  
  local_278 = 0;
  lVar5 = rmapiGetInterface(4);
  lVar6 = gpumgrGetParentGPU(param_1);
  if (param_1 != lVar6) {
    return 0;
  }
  iVar3 = rmapiutilAllocClientAndDeviceHandles(lVar5,param_1,&local_278,&local_274,&local_270);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,
               "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &hClientId, &hDeviceId, &hSubdeviceId)"
               ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x151);
    return iVar3;
  }
  *(ulong *)(param_2 + 0x5c0) = CONCAT44(local_274,local_278);
  *(undefined4 *)(param_2 + 0x5c8) = local_270;
  iVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar4 = serverGetClientUnderLock(g_resServ,local_278,&local_268);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"serverGetClientUnderLock(&g_resServ, hClientId, &pClientId)",
               "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x15b);
    return iVar4;
  }
  iVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  if (iVar3 != iVar4) {
    iVar3 = clientGenResourceHandle_IMPL(local_268,&local_228);
    if (iVar3 == 0) {
      portMemSet(local_1a8,0,4);
      local_1a8[0] = iVar4;
      (**(code **)(lVar5 + 8))(lVar5,local_278,local_274,local_228 & 0xffffffff,0x2080,local_1a8,4);
      goto LAB_0035be3b;
    }
    nvCheckOkFailedNoLog
              (4,iVar3,"clientGenResourceHandle(pClientId, &hSecondary)",
               "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x16e);
    goto LAB_0035c23d;
  }
LAB_0035be3b:
  rmGpuLocksRelease(0,0);
  lVar6 = rmapiGetInterface(3);
  portMemSet(local_260,0,0x38);
  local_25c = 0x2000;
  iVar3 = (**(code **)(lVar6 + 8))(lVar6,local_278,local_274,0xdada0042,0x90f1,local_260,0x38);
  if (iVar3 == 0) {
    portMemSet(&local_228,0,0x80);
    local_1e8 = 0x100;
    local_228 = 0xdeaf0006;
    local_210 = CONCAT44(local_210._4_4_,0x2000000);
    local_1bc = 0;
    iVar3 = (**(code **)(lVar6 + 8))(lVar6,local_278,local_274,0xdada0044,0x3e,&local_228,0x80);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, hPBPhysMemId, NV01_MEMORY_SYSTEM, &memAllocParams, sizeof(memAllocParams))"
                 ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x19a);
      goto LAB_0035c200;
    }
    portMemSet(&local_228,0,0x80);
    local_1e8 = 0x100;
    local_228 = 0xdeaf0006;
    local_210 = CONCAT44(local_210._4_4_,0x2000000);
    local_220 = 0x80000;
    local_1bc = 0xdada0042;
    iVar3 = (**(code **)(lVar6 + 8))(lVar6,local_278,local_274,0xdada0043,0x50a0,&local_228);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, hPBVirtMemId, NV50_MEMORY_VIRTUAL, &memAllocParams, sizeof(memAllocParams))"
                 ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x1a7);
      goto LAB_0035c200;
    }
    cVar1 = gpuIsClassSupported_IMPL(param_1,0xc36f);
    if ((cVar1 == '\0') && (cVar1 = gpuIsClassSupported_IMPL(param_1,0xc46f), cVar1 == '\0')) {
      iVar3 = 0x56;
      goto LAB_0035c200;
    }
    portMemSet(&local_228,0,0x80);
    local_1e8 = 0x200;
    local_228 = 0xdeaf0006;
    if (((*(ushort *)(param_1 + 0x4926) & 3) == 3) || ((*(ushort *)(param_1 + 0x4926) & 3) == 0)) {
      uVar7 = 0x40;
      local_220 = 4;
      local_210 = 0x400000004000;
    }
    else {
      local_210 = CONCAT44(local_210._4_4_,0x2000000);
      uVar7 = 0x3e;
    }
    iVar3 = (**(code **)(lVar6 + 8))(lVar6,local_278,local_274,0xdada0047,uVar7,&local_228,0x80);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, hUserdId, userdMemClass, &memAllocParams, sizeof(memAllocParams))"
                 ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x1d5,0x35bfe6);
      goto LAB_0035c200;
    }
    uVar7 = gpuGetKernelFifoShared_IMPL(param_1);
    local_26c = kfifoGetChannelClassId_IMPL(param_1,uVar7);
    if (local_26c != 0) {
      portMemSet(local_1a8,0,0x170);
      local_1a8[1] = -0x2525ffbd;
      local_1a8[2] = 0;
      local_1a8[3] = 0;
      local_1a8[4] = 0x20;
      local_18c = 0xdada0047dada0042;
      local_128 = gpuGetNv2080EngineType_IMPL(1);
      uVar7 = 0x170;
      iVar3 = (**(code **)(lVar6 + 8))(lVar6,local_278,local_274,0xdada0045,local_26c,local_1a8);
      if (iVar3 == 0) {
        iVar3 = rmGpuLocksAcquire(0,0x80001,extraout_RDX,uVar7);
        if (iVar3 == 0) {
          lVar5 = rmapiGetInterface(4);
          iVar3 = kgraphicsGetClassByType_IMPL(param_1,param_2,0,&local_26c);
          if (iVar3 == 0) {
            if (local_26c == 0) {
              nvAssertFailedNoLog("classNum != 0","src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",
                                  0x1ff);
              uVar2 = 1;
              iVar3 = 0;
              goto LAB_0035c1b8;
            }
            iVar3 = (**(code **)(lVar5 + 8))(lVar5,local_278,0xdada0045,0xdada0046,local_26c,0,0);
            uVar2 = 1;
            if (iVar3 == 0) goto LAB_0035c1b8;
            nvAssertOkFailedNoLog
                      (iVar3,
                       "pRmApi->AllocWithHandle(pRmApi, hClientId, hChannelId, hObj3D, classNum, NULL, 0)"
                       ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x202);
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar3,
                       "kgraphicsGetClassByType(pGpu, pKernelGraphics, GR_OBJECT_TYPE_3D, &classNum)"
                       ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x1fc);
          }
          goto LAB_0035c23d;
        }
        nvAssertOkFailedNoLog
                  (iVar3,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GR)",
                   "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x1f5);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, hChannelId, classNum, &channelGPFIFOAllocParams, sizeof(channelGPFIFOAllocParams))"
                   ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x1ef);
      }
      goto LAB_0035c200;
    }
    nvAssertFailedNoLog("classNum != 0","src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x1dd);
    iVar3 = rmGpuLocksAcquire(0,0x80001);
    if (iVar3 == 0) {
      rmapiGetInterface(4);
      uVar2 = 1;
      goto LAB_0035c1b8;
    }
    nvAssertOkFailedNoLog
              (iVar3,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GR)",
               "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x20a);
    lVar5 = rmapiGetInterface(4);
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,
               "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, hVASpace, FERMI_VASPACE_A, &vaParams, sizeof(vaParams))"
               ,"src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x18e);
LAB_0035c200:
    iVar4 = rmGpuLocksAcquire(0,0x80001);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GR)",
                 "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x20a);
    }
    lVar5 = rmapiGetInterface(4);
  }
LAB_0035c23d:
  iVar4 = (**(code **)(lVar5 + 0x18))(lVar5,local_278,local_278);
  if (iVar4 == 0) {
    uVar2 = 0;
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,"pRmApi->Free(pRmApi, hClientId, hClientId)",
               "src/kernel/gpu/gr/arch/turing/kgraphics_tu102.c",0x213);
    uVar2 = 0;
  }
LAB_0035c1b8:
  *(undefined1 *)(param_2 + 0x5cc) = uVar2;
  return iVar3;
}


// ===== 0035c570 kgraphicsIsBug4208224WARNeeded_TU102 =====

undefined1 kgraphicsIsBug4208224WARNeeded_TU102(long param_1,long param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 1099) == '\0') {
    uVar1 = *(undefined1 *)(param_2 + 0x20a);
  }
  return uVar1;
}


// ===== 0035c590 _fecsLoadInternalRoutingInfo =====

undefined8
_fecsLoadInternalRoutingInfo
          (long param_1,long param_2,undefined4 *param_3,undefined4 *param_4,undefined8 param_5)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(param_2 + 0x220);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x90);
    return 0x40;
  }
  portMemSet(param_5,0,0x10);
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar2 == '\0')) {
    *param_3 = *(undefined4 *)(param_1 + 0x3b34);
    *param_4 = *(undefined4 *)(param_1 + 0x3b3c);
  }
  else {
    if (*(int *)(lVar1 + 0x20) == 0) {
      nvCheckFailedNoLog(1,"pFecsTraceInfo->hClient != NV01_NULL_OBJECT",
                         "src/kernel/gpu/gr/fecs_event_list.c",0x9c);
      return 0x1f;
    }
    kgrmgrCtrlSetEngineID_IMPL(*(undefined4 *)(lVar1 + 0x28),param_5);
    *param_3 = *(undefined4 *)(lVar1 + 0x20);
    *param_4 = *(undefined4 *)(lVar1 + 0x24);
  }
  return 0;
}


// ===== 0035c6b0 _getFecsEventListParameters =====

undefined8
_getFecsEventListParameters
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_2,0);
  *param_3 = 0;
  if (lVar1 == 0) {
    nvCheckOkFailedNoLog
              (4,0x40,"_getFecsMemDesc(pGpu, pKernelGraphics, ppFecsMemDesc)",
               "src/kernel/gpu/gr/fecs_event_list.c",0x26a);
  }
  else {
    uVar2 = 0;
    if (*(long *)(lVar1 + 0x30) != 0) {
      uVar2 = memdescGetMemDescFromGpu(*(long *)(lVar1 + 0x30),param_1);
    }
    *param_3 = uVar2;
    lVar1 = kgraphicsGetStaticInfo_IMPL(param_1,param_2);
    if (lVar1 == 0) {
      nvCheckFailedNoLog(4,"pStaticInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x26e);
    }
    else {
      if (*(undefined4 **)(lVar1 + 0x1400) != (undefined4 *)0x0) {
        *param_4 = **(undefined4 **)(lVar1 + 0x1400);
        return 0;
      }
      nvAssertFailedNoLog("pStaticInfo->pFecsTraceDefines != NULL",
                          "src/kernel/gpu/gr/fecs_event_list.c",0x26f);
    }
  }
  return 0x40;
}


// ===== 0035c7a0 notifyEventBuffers =====

void notifyEventBuffers(long param_1,long param_2,byte *param_3)

{
  uint uVar1;
  long lVar2;
  bool bVar3;
  long *plVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  byte bVar10;
  byte bVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  byte bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  undefined4 local_ac;
  char local_99;
  long local_98;
  byte local_90 [2];
  short local_8e;
  undefined4 local_8c;
  undefined4 local_88;
  byte local_82;
  byte local_81;
  undefined8 local_80;
  long *local_78 [4];
  byte *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  
  bVar15 = false;
  lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    bVar15 = cVar5 != '\0';
  }
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x1f1);
    return;
  }
  if (param_2 != 0) {
    uVar8 = mapFindLEQ_IMPL(param_2,0xffffffffffffffff);
    uVar9 = mapFindGEQ_IMPL(param_2,0);
    multimapItemIterRange_IMPL(local_78,lVar2,uVar9,uVar8);
LAB_0035c840:
    cVar5 = multimapItemIterNext_IMPL();
    if (cVar5 != '\0') {
      do {
        plVar4 = local_78[0];
        if (*(char *)((long)local_78[0] + 0x21) == '\0') {
          bVar16 = *(long *)(param_3 + 8) == 0;
        }
        else {
          bVar16 = false;
        }
        bVar17 = false;
        bVar3 = bVar16;
        if ((char)local_78[0][4] == '\0') {
          bVar17 = local_78[0][3] != *(long *)(param_3 + 8);
          bVar3 = (bool)(bVar16 | bVar17);
        }
        bVar14 = *param_3;
        bVar11 = param_3[0x1c];
        bVar10 = param_3[0x1d];
        *(short *)(*local_78[0] + 0x15c) =
             *(short *)(*local_78[0] + 0x15c) + *(short *)(param_3 + 0x1e);
        if (bVar3) {
          if (bVar14 == 5) goto LAB_0035caca;
LAB_0035c8d4:
          if (bVar14 == 3) {
            bVar14 = 7;
          }
          else {
LAB_0035c8de:
            if (1 < bVar14 - 6) goto LAB_0035c840;
          }
LAB_0035c8eb:
          if (bVar15) goto LAB_0035c8f4;
LAB_0035cad9:
          bVar6 = *(byte *)(local_78[0] + 5);
          if (bVar16) {
            uVar8 = *(undefined8 *)(param_3 + 0x28);
            uVar12 = 0xffffffff;
            uVar13 = 0xffffffff;
          }
          else if (bVar17) {
            uVar8 = *(undefined8 *)(param_3 + 0x28);
            uVar12 = 0;
            uVar13 = 0;
          }
          else {
            uVar8 = *(undefined8 *)(param_3 + 0x20);
            uVar13 = *(undefined4 *)(param_3 + 0x14);
            uVar12 = *(undefined4 *)(param_3 + 0x10);
          }
          bVar10 = 0xff;
          bVar11 = 0xff;
          if (bVar6 != 1) goto LAB_0035c93b;
          local_ac = 0x86;
        }
        else {
          uVar1 = *(uint *)((long)local_78[0] + 0x24);
          if ((uVar1 >> (*param_3 & 0x1f) & 1) != 0) goto LAB_0035c8eb;
          if (((uVar1 & 0x40) == 0) || (bVar14 != 5)) {
            if ((uVar1 & 0x80) != 0) goto LAB_0035c8d4;
            goto LAB_0035c8de;
          }
LAB_0035caca:
          bVar14 = 6;
          if (!bVar15) goto LAB_0035cad9;
LAB_0035c8f4:
          if (((*(uint *)((long)local_78[0] + 0x2c) != 0xffffffff) &&
              (*(uint *)((long)local_78[0] + 0x2c) != (uint)param_3[0x1c])) ||
             (bVar6 = *(byte *)(local_78[0] + 5), bVar6 < 2)) goto LAB_0035c840;
          if (bVar16) {
            uVar8 = *(undefined8 *)(param_3 + 0x28);
            uVar12 = 0xffffffff;
            uVar13 = 0xffffffff;
            bVar10 = 0xfd;
            bVar11 = 0xfd;
          }
          else if (bVar17) {
            uVar8 = *(undefined8 *)(param_3 + 0x28);
            uVar12 = 0;
            uVar13 = 0;
            bVar10 = 0xfe;
            bVar11 = 0xfe;
          }
          else {
            uVar8 = *(undefined8 *)(param_3 + 0x20);
            uVar13 = *(undefined4 *)(param_3 + 0x14);
            uVar12 = *(undefined4 *)(param_3 + 0x10);
          }
LAB_0035c93b:
          if (bVar6 != 2) goto LAB_0035c840;
          local_ac = 2;
        }
        portMemSet(&local_58,0,0x20);
        local_48 = 0;
        local_40 = 0;
        portMemSet(local_90,0,0x18);
        if (1 < *(byte *)(plVar4 + 5)) {
          local_82 = bVar11;
          local_81 = bVar10;
        }
        local_8e = *(short *)(*plVar4 + 0x15c);
        local_50 = 0x18;
        *(short *)(*plVar4 + 0x15c) = local_8e + 1;
        local_90[0] = bVar14;
        local_8c = uVar12;
        local_88 = uVar13;
        local_80 = uVar8;
        local_58 = local_90;
        iVar7 = eventBufferAdd(*plVar4,&local_58,local_ac,&local_99,&local_98);
        if (((iVar7 != 0) || (local_99 == '\0')) || (local_98 == 0)) goto LAB_0035c840;
        osEventNotification(param_1,*(undefined8 *)(*plVar4 + 0x160),local_ac,&local_58,0);
        *(undefined1 *)(*plVar4 + 0x15e) = 1;
        cVar5 = multimapItemIterNext_IMPL();
        if (cVar5 == '\0') {
          return;
        }
      } while( true );
    }
  }
  return;
}


// ===== 0035cbd0 fecsSetRoutingInfo =====

void fecsSetRoutingInfo(undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x220);
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0x20) = param_3;
    *(undefined4 *)(lVar1 + 0x24) = param_4;
    *(undefined4 *)(lVar1 + 0x28) = param_5;
    return;
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x28a);
  return;
}


// ===== 0035cc10 fecsClearRoutingInfo =====

void fecsClearRoutingInfo(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x220);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x20) = 0;
    *(undefined4 *)(lVar1 + 0x28) = 0;
    return;
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x29a);
  return;
}


// ===== 0035cc50 fecsCtxswLoggingInit =====

undefined8 fecsCtxswLoggingInit(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("ppFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x2ac);
    return 0x56;
  }
  lVar1 = portMemAllocNonPaged(0x38);
  if (lVar1 != 0) {
    portMemSet(lVar1,0,0x38);
    uVar2 = osGetMonotonicTimeNs();
    uVar2 = portCryptoPseudoRandomGeneratorCreate(uVar2);
    *(undefined8 *)(lVar1 + 0x18) = uVar2;
    *param_3 = lVar1;
    kgraphicsInitFecsRegistryOverrides_GP100(param_1,param_2);
    return 0;
  }
  return 0x51;
}


// ===== 0035cd10 fecsCtxswLoggingTeardown =====

void fecsCtxswLoggingTeardown(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x220);
  if (lVar1 != 0) {
    portCryptoPseudoRandomGeneratorDestroy(*(undefined8 *)(lVar1 + 0x18));
    *(undefined8 *)(lVar1 + 0x18) = 0;
    portMemFree(lVar1);
    return;
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x2c5);
  return;
}


// ===== 0035cd70 fecsGlobalLoggingInit =====

undefined8 fecsGlobalLoggingInit(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = portMemAllocNonPaged(0x48);
  if (lVar1 != 0) {
    portMemSet(lVar1,0,0x48);
    uVar2 = portMemAllocatorGetGlobalNonPaged();
    multimapInit_IMPL(lVar1,uVar2,0x38,0x38,0x10);
    *param_3 = lVar1;
    *(undefined4 *)(lVar1 + 0x38) = 0x1fca055;
    return 0;
  }
  nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x2d7);
  return 0x51;
}


// ===== 0035ce10 fecsGlobalLoggingTeardown =====

void fecsGlobalLoggingTeardown(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x488);
  if (lVar1 != 0) {
    multimapDestroy_IMPL(lVar1);
    portMemFree(lVar1);
    return;
  }
  nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x2ec);
  return;
}


// ===== 0035ce60 fecsSetRecordsPerIntr =====

void fecsSetRecordsPerIntr(undefined8 param_1,long param_2,undefined2 param_3)

{
  if (*(long *)(param_2 + 0x220) != 0) {
    *(undefined2 *)(*(long *)(param_2 + 0x220) + 8) = param_3;
    return;
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x2fd);
  return;
}


// ===== 0035ce90 fecsBufferChanged =====

undefined4 fecsBufferChanged(undefined8 param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  int local_24;
  long local_20;
  
  plVar1 = *(long **)(param_2 + 0x220);
  if (plVar1 == (long *)0x0) {
    nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x30f);
  }
  else {
    lVar2 = *plVar1;
    iVar3 = _getFecsEventListParameters(param_1,param_2,&local_20,&local_24);
    if (((iVar3 == 0) && (local_20 != 0)) && (lVar2 != 0)) {
      uVar4 = (uint)*(ushort *)((long)plVar1 + 10) * local_24;
      return CONCAT31((int3)(uVar4 >> 8),*(int *)(lVar2 + (ulong)uVar4) != -0x21212122);
    }
  }
  return 0;
}


// ===== 0035cf20 _fecsTimerCallback =====

int _fecsTimerCallback(long param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  uVar6 = 1;
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    uVar6 = (ulong)((-(uint)(cVar3 == '\0') & 0xfffffff9) + 8);
  }
  if (lVar2 == 0) {
    iVar4 = 0x40;
    nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x35e);
  }
  else {
    lVar7 = param_1;
    do {
      if ((*(long *)(lVar7 + 0x1bd0) != 0) && (cVar3 = fecsBufferChanged(param_1), cVar3 != '\0')) {
        piVar1 = (int *)(lVar2 + 0x3c);
        LOCK();
        iVar4 = *piVar1;
        if (iVar4 == 0) {
          *piVar1 = 1;
        }
        UNLOCK();
        if (iVar4 == 0) {
          iVar4 = osQueueWorkItem(param_1,_fecsOsWorkItem,0,0x80);
          if (iVar4 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar4,
                       "osQueueWorkItem(pGpu, _fecsOsWorkItem, NULL, (OsQueueWorkItemFlags){.bLockGpuGroupDevice = NV_TRUE})"
                       ,"src/kernel/gpu/gr/fecs_event_list.c",0x36a);
            LOCK();
            *piVar1 = 0;
            UNLOCK();
            iVar5 = tmrEventScheduleRel_IMPL(param_2,param_3,*(undefined4 *)(lVar2 + 0x38));
            if (iVar5 == 0) {
              return iVar4;
            }
            nvCheckOkFailedNoLog
                      (4,iVar5,
                       "tmrEventScheduleRel(pTmr, pTmrEvent, pFecsGlobalTraceInfo->fecsTimerInterval)"
                       ,"src/kernel/gpu/gr/fecs_event_list.c",0x379);
            return iVar4;
          }
          break;
        }
      }
      lVar7 = lVar7 + 8;
    } while (param_1 + uVar6 * 8 != lVar7);
    iVar4 = tmrEventScheduleRel_IMPL(param_2,param_3,*(undefined4 *)(lVar2 + 0x38));
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "tmrEventScheduleRel(pTmr, pTmrEvent, pFecsGlobalTraceInfo->fecsTimerInterval)",
                 "src/kernel/gpu/gr/fecs_event_list.c",0x379);
    }
  }
  return iVar4;
}


// ===== 0035d0e0 nvEventBufferFecsCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong nvEventBufferFecsCallback(long param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  char cVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  byte bVar16;
  uint uVar17;
  undefined8 uVar18;
  int *piVar19;
  long *plVar20;
  char *pcVar21;
  long *plVar22;
  ulong *puVar23;
  long lVar24;
  byte bVar25;
  long lVar26;
  long local_e0;
  ulong local_c0;
  uint local_b0;
  int local_ac;
  long local_a8;
  long *local_a0;
  long *local_98;
  undefined1 local_90 [8];
  ulong local_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  ulong local_78;
  int local_70;
  undefined4 local_6c;
  byte local_68 [8];
  long local_60;
  ulong local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 local_4b;
  short local_4a;
  long local_48;
  long local_40;
  
  bVar25 = (-(param_2 == 0) & 7U) + 1;
  lVar26 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  if (*(long *)(param_1 + 0x1bc0) == 0) {
    bVar25 = 1;
  }
  else {
    cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    if (cVar7 == '\0') {
      bVar25 = 1;
    }
  }
  uVar13 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
  uVar18 = 0x3ef;
  pcVar21 = "rmDeviceGpuLockIsOwner(pGpu->gpuInstance)";
  if ((char)uVar13 != '\0') {
    uVar18 = 0x3f1;
    pcVar21 = "pFecsGlobalTraceInfo != NULL";
    if (lVar26 != 0) {
      uVar18 = 0x3f2;
      pcVar21 = "pFecsGlobalTraceInfo->fecsCtxswLogConsumerCount >= 0";
      sVar8 = *(short *)(lVar26 + 0x40);
      if (-1 < sVar8) {
        if (sVar8 != 0) {
          lVar24 = 0;
          uVar13 = param_1 + 0x3b58U;
          lVar26 = param_2;
          do {
            if (param_2 == 0) {
              while (lVar26 = *(long *)(param_1 + 0x1bd0 + lVar24 * 8), lVar26 == 0) {
                lVar24 = lVar24 + 1;
                if ((uint)bVar25 <= (uint)lVar24) {
                  return uVar13;
                }
              }
            }
            plVar3 = *(long **)(lVar26 + 0x220);
            if (plVar3 == (long *)0x0) {
              uVar18 = 0x402;
              pcVar21 = "pFecsTraceInfo != NULL";
              goto LAB_0035d817;
            }
            lVar4 = *plVar3;
            uVar13 = 0;
            if (lVar4 != 0) {
              uVar10 = (uint)*(ushort *)(plVar3 + 1);
              uVar13 = _getFecsEventListParameters(param_1,lVar26,&local_a8,&local_b0);
              uVar2 = local_b0;
              if (((int)uVar13 == 0) && (uVar13 = 0, local_a8 != 0)) {
                if (*(ulong *)(local_a8 + 0x30) < (ulong)local_b0) {
                  uVar18 = 0x40f;
                  pcVar21 = "fecsBufferSize > 0";
                  goto LAB_0035d817;
                }
                uVar14 = *(ulong *)(local_a8 + 0x30) / (ulong)local_b0;
                uVar17 = (uint)*(ushort *)((long)plVar3 + 10);
                local_c0 = (ulong)uVar17;
                cVar7 = osIsRaisedIRQL();
                if (cVar7 == '\0') {
                  uVar10 = (uint)uVar14;
                }
                uVar13 = (ulong)(uVar2 * uVar17);
                if (*(int *)(lVar4 + uVar13) == -0x21212122) goto LAB_0035d7d0;
                if (*(int *)(lVar4 + (ulong)((int)((ulong)(uVar17 - 1) % uVar14) * uVar2)) !=
                    -0x21212122) {
                  nvDbg_Printf("src/kernel/gpu/gr/fecs_event_list.c",0x427,
                               "nvEventBufferFecsCallback",4,"NVRM: FECS buffer overflow detected\n"
                              );
                  iVar9 = _fecsLoadInternalRoutingInfo(param_1,lVar26,&local_80,&local_78,local_68);
                  if (iVar9 != 0) {
                    uVar13 = nvAssertOkFailedNoLog
                                       (iVar9,
                                        "_fecsLoadInternalRoutingInfo(pGpu, pKernelGraphics, &hClient, &hSubdevice, &params.grRouteInfo)"
                                        ,"src/kernel/gpu/gr/fecs_event_list.c",0x429);
                    return uVar13;
                  }
                  iVar9 = (**(code **)(param_1 + 0x3b90))
                                    (param_1 + 0x3b58U,local_80,local_78 & 0xffffffff,0x20800a3b,
                                     local_68,0x18);
                  if (iVar9 != 0) {
                    uVar13 = nvAssertOkFailedNoLog
                                       (iVar9,
                                        "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_GR_GET_FECS_TRACE_RD_OFFSET, &params, sizeof(params))"
                                        ,"src/kernel/gpu/gr/fecs_event_list.c",0x432);
                    return uVar13;
                  }
                  *(undefined2 *)((long)plVar3 + 0xc) = 0;
                  local_c0 = local_58 & 0xffffffff;
                }
                uVar10 = uVar10 & 0xffff;
                if (uVar10 == 0) {
                  if (*(short *)((long)plVar3 + 0xc) != 0) {
                    uVar17 = 0;
                    goto LAB_0035d783;
                  }
LAB_0035dd30:
                  *(undefined2 *)((long)plVar3 + 10) = (undefined2)local_c0;
                }
                else {
                  uVar17 = 0;
                  do {
                    piVar19 = (int *)((ulong)((int)local_c0 * uVar2) + lVar4);
                    if (*piVar19 == -0x21212122) {
                      if (*(short *)((long)plVar3 + 0xc) == 0) goto LAB_0035d7b0;
                      goto LAB_0035d783;
                    }
                    *piVar19 = -0x21212122;
                    osFlushCpuWriteCombineBuffer();
                    lVar15 = gpuGetKernelFifoShared_IMPL(param_1);
                    local_a0 = (long *)0x0;
                    local_98 = (long *)0x0;
                    lVar5 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
                    if (lVar5 == 0) {
                      nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL",
                                          "src/kernel/gpu/gr/fecs_event_list.c",0xe7);
                    }
                    else {
                      iVar9 = (**(code **)(lVar15 + 0x188))
                                        (lVar15,local_90,&local_88,0,&local_ac,&local_80);
                      if (iVar9 != 0) {
                        nvDbg_Printf("src/kernel/gpu/gr/fecs_event_list.c",0xec,
                                     "formatAndNotifyFecsRecord",4,
                                     "NVRM: Unable to get instance memory info!\n");
                      }
                      iVar9 = 3 - (uint)(local_ac == 0);
                      if (*(int *)CONCAT44(uStack_7c,local_80) != 1) {
                        iVar9 = 0;
                      }
                      portMemSet(local_68,0,0x30);
                      local_6c = 0;
                      bVar16 = (0xffffffff < local_88) << 5 | (local_88 & 0xaaaaaaaaaaaaaaaa) != 0 |
                               ((local_88 & 0xffff0000ffff0000) != 0) << 4 |
                               ((local_88 & 0xff00ff00ff00ff00) != 0) << 3 |
                               ((local_88 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                               ((local_88 & 0xcccccccccccccccc) != 0) * '\x02';
                      local_78 = (ulong)(uint)piVar19[3] << bVar16;
                      if (piVar19[3] != 0) {
                        local_70 = iVar9;
                        iVar11 = (**(code **)(lVar15 + 0x1d0))(param_1,lVar15,&local_78,&local_a0);
                        if (iVar11 == 0) {
                          bVar16 = (0xffffffff < local_88) << 5 |
                                   (local_88 & 0xaaaaaaaaaaaaaaaa) != 0 |
                                   ((local_88 & 0xff00ff00ff00ff00) != 0) << 3 |
                                   ((local_88 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                                   ((local_88 & 0xcccccccccccccccc) != 0) * '\x02' |
                                   ((local_88 & 0xffff0000ffff0000) != 0) << 4;
                        }
                        else {
                          nvDbg_Printf("src/kernel/gpu/gr/fecs_event_list.c",0x106,
                                       "formatAndNotifyFecsRecord",1,
                                       "NVRM: Error getting channel!\n");
                          local_a0 = (long *)0x0;
                          bVar16 = (0xffffffff < local_88) << 5 |
                                   (local_88 & 0xaaaaaaaaaaaaaaaa) != 0 |
                                   ((local_88 & 0xff00ff00ff00ff00) != 0) << 3 |
                                   ((local_88 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                                   ((local_88 & 0xcccccccccccccccc) != 0) * '\x02' |
                                   ((local_88 & 0xffff0000ffff0000) != 0) << 4;
                        }
                      }
                      local_6c = 0;
                      local_78 = (ulong)(uint)piVar19[5] << bVar16;
                      local_70 = iVar9;
                      if ((piVar19[5] == 0) ||
                         (iVar9 = (**(code **)(lVar15 + 0x1d0))(param_1,lVar15,&local_78,&local_98),
                         iVar9 == 0)) {
                        plVar20 = local_a0;
                        if (local_a0 != (long *)0x0) {
                          plVar20 = local_a0 + 0x83;
                        }
                        plVar22 = local_98;
                        if (local_98 != (long *)0x0) {
                          plVar22 = local_98 + 0x83;
                        }
                      }
                      else {
                        nvDbg_Printf("src/kernel/gpu/gr/fecs_event_list.c",0x110,
                                     "formatAndNotifyFecsRecord",1,
                                     "NVRM: Error getting new channel!\n");
                        local_98 = (long *)0x0;
                        plVar20 = (long *)0x0;
                        if (local_a0 != (long *)0x0) {
                          plVar20 = local_a0 + 0x83;
                        }
                        plVar22 = (long *)0x0;
                      }
                      if (*(char *)(lVar26 + 0x209) != '\0') {
                        iVar9 = piVar19[0x1d];
                        iVar11 = *(int *)(*(long *)(lVar26 + 0x220) + 0x14);
                        if (iVar11 + 1 != iVar9) {
                          local_4a = ((short)iVar9 - (short)iVar11) + -1;
                        }
                        *(int *)(*(long *)(lVar26 + 0x220) + 0x14) = iVar9;
                      }
                      puVar23 = (ulong *)(piVar19 + 6);
                      uVar13 = 0;
                      local_e0 = 0;
                      do {
                        uVar6 = *puVar23;
                        lVar15 = kgraphicsGetStaticInfo_IMPL(param_1,lVar26);
                        if (lVar15 == 0) {
                          nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                                              "src/kernel/gpu/gr/fecs_event_list.c",0xb0);
LAB_0035db40:
                          nvAssertOkFailedNoLog
                                    (0x40,
                                     "fecsExtractTagAndTimestamp(pGpu, pKernelGraphics, pRecord->ts[timestampId], &notifRecord.timestamp, &notifRecord.tag)"
                                     ,"src/kernel/gpu/gr/fecs_event_list.c",0x126);
                          break;
                        }
                        lVar15 = *(long *)(lVar15 + 0x1400);
                        if (lVar15 == 0) {
                          nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pFecsTraceDefines != NULL"
                                              ,"src/kernel/gpu/gr/fecs_event_list.c",0xb1);
                          goto LAB_0035db40;
                        }
                        local_68[0] = (byte)((uint)(uVar6 >> 0x20) >> (*(byte *)(lVar15 + 8) & 0x1f)
                                            ) & *(byte *)(lVar15 + 4);
                        local_48 = (uVar6 & *(ulong *)(lVar15 + 0x10)) <<
                                   (*(byte *)(lVar15 + 0x18) & 0x3f);
                        lVar15 = local_e0;
                        if (local_68[0] < 6) {
                          if (local_68[0] < 4) {
                            if ((local_68[0] & 0xfd) == 0) goto LAB_0035d701;
                            if (local_a0 == (long *)0x0) goto LAB_0035da80;
                            local_50 = (undefined4)local_a0[0x7d];
                            local_60 = local_a0[0x52];
                            local_58 = CONCAT44(*(undefined4 *)((long)local_a0 + 0x3e4),
                                                *(undefined4 *)((long)local_a0 + 0x414));
                            cVar7 = kmigmgrIsMIGReferenceValid_IMPL(plVar20);
                            if (cVar7 != '\0') {
                              local_4c = (undefined1)*(undefined4 *)(*plVar20 + 0x968);
                              if (plVar20[1] == 0) {
                                local_4b = 0xfd;
                              }
                              else {
                                local_4b = (undefined1)*(undefined4 *)(plVar20[1] + 0xc0);
                              }
                            }
                            lVar15 = local_48;
                            if (local_68[0] != 1) goto LAB_0035d9de;
LAB_0035d8e0:
                            local_e0 = lVar15;
                            if (local_a0 == (long *)0x0) goto LAB_0035da80;
                          }
                          else {
                            if (local_98 != (long *)0x0) {
                              local_50 = (undefined4)local_98[0x7d];
                              local_60 = local_98[0x52];
                              local_58 = CONCAT44(*(undefined4 *)((long)local_98 + 0x3e4),
                                                  *(undefined4 *)((long)local_98 + 0x414));
                              cVar7 = kmigmgrIsMIGReferenceValid_IMPL(plVar22);
                              if (cVar7 != '\0') {
                                local_4c = (undefined1)*(undefined4 *)(*plVar22 + 0x968);
                                if (plVar22[1] == 0) {
                                  local_4b = 0xfd;
                                }
                                else {
                                  local_4b = (undefined1)*(undefined4 *)(plVar22[1] + 0xc0);
                                }
                              }
                              lVar15 = local_48;
                              if (local_68[0] != 4) {
LAB_0035d9de:
                                uVar13 = local_48 - local_e0;
                                lVar15 = local_e0;
                              }
                              goto LAB_0035d8e0;
                            }
                            if (local_a0 == (long *)0x0) goto LAB_0035d701;
                          }
                          lVar15 = *(long *)(lVar26 + 0x220);
joined_r0x0035da98:
                          if (lVar15 == 0) {
                            nvAssertFailedNoLog("pFecsTraceInfo != NULL",
                                                "src/kernel/gpu/gr/fecs_event_list.c",0x18c);
                            break;
                          }
                          local_40 = 0;
                          if ((uVar13 != 0) && (*(long *)(lVar15 + 0x18) != 0)) {
                            uVar12 = portCryptoPseudoRandomGeneratorGetU32();
                            local_40 = (ulong)uVar12 % uVar13 + local_e0;
                          }
                          if (local_60 != 0) {
                            uVar18 = multimapFindSubmap_IMPL(lVar5);
                            notifyEventBuffers(param_1,uVar18,local_68);
                          }
                          uVar18 = multimapFindSubmap_IMPL(lVar5,0);
                          notifyEventBuffers(param_1,uVar18,local_68);
                          local_4a = 0;
                        }
                        else if ((byte)(local_68[0] - 10) < 4) {
                          if (local_a0 != (long *)0x0) {
                            local_50 = (undefined4)local_a0[0x7d];
                            local_60 = local_a0[0x52];
                            local_58 = CONCAT44(*(undefined4 *)((long)local_a0 + 0x3e4),
                                                *(undefined4 *)((long)local_a0 + 0x414));
                            cVar7 = kmigmgrIsMIGReferenceValid_IMPL(plVar20);
                            if (cVar7 != '\0') {
                              local_4c = (undefined1)*(undefined4 *)(*plVar20 + 0x968);
                              if (plVar20[1] == 0) {
                                local_4b = 0xfd;
                              }
                              else {
                                local_4b = (undefined1)*(undefined4 *)(plVar20[1] + 0xc0);
                              }
                            }
                            goto LAB_0035d8e0;
                          }
LAB_0035da80:
                          if (local_98 != (long *)0x0) {
                            lVar15 = *(long *)(lVar26 + 0x220);
                            goto joined_r0x0035da98;
                          }
                        }
LAB_0035d701:
                        puVar23 = puVar23 + 1;
                      } while (puVar23 != (ulong *)(piVar19 + 0x10));
                    }
                    sVar8 = *(short *)((long)plVar3 + 0xc) + 1;
                    *(short *)((long)plVar3 + 0xc) = sVar8;
                    uVar12 = 0;
                    if ((int)local_c0 + 1U < uVar14) {
                      uVar12 = (int)local_c0 + 1U;
                    }
                    uVar17 = uVar17 + 1;
                    local_c0 = (ulong)uVar12;
                  } while (uVar17 != uVar10);
                  if (sVar8 == 0) goto LAB_0035dd30;
LAB_0035d783:
                  (**(code **)(lVar26 + 0x1d8))(param_1,lVar26,local_c0);
                  *(undefined2 *)((long)plVar3 + 0xc) = 0;
LAB_0035d7b0:
                  uVar13 = local_c0 & 0xffff;
                  *(undefined2 *)((long)plVar3 + 10) = (undefined2)local_c0;
                  if (uVar10 != uVar17) goto LAB_0035d7d0;
                }
                if (*(long *)(lVar26 + 0x220) == 0) {
                  uVar13 = nvAssertFailedNoLog("pFecsTraceInfo != NULL",
                                               "src/kernel/gpu/gr/fecs_event_list.c",0x6d1);
                }
                else {
                  uVar13 = 0;
                  puVar1 = (uint *)(*(long *)(lVar26 + 0x220) + 0x10);
                  LOCK();
                  uVar2 = *puVar1;
                  if (uVar2 == 0) {
                    *puVar1 = 1;
                  }
                  else {
                    uVar13 = (ulong)uVar2;
                  }
                  UNLOCK();
                }
              }
            }
LAB_0035d7d0:
            lVar24 = lVar24 + 1;
          } while ((uint)lVar24 < (uint)bVar25);
        }
        return uVar13;
      }
    }
  }
LAB_0035d817:
  uVar13 = nvAssertFailedNoLog(pcVar21,"src/kernel/gpu/gr/fecs_event_list.c",uVar18);
  return uVar13;
}


// ===== 0035ddf0 _fecsOsWorkItem =====

ulong _fecsOsWorkItem(void)

{
  uint *puVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = gpumgrGetGpu();
  if (lVar4 == 0) {
    uVar5 = nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x343);
    return uVar5;
  }
  lVar3 = *(long *)(*(long *)(lVar4 + 0x1bc8) + 0x488);
  if (lVar3 != 0) {
    nvEventBufferFecsCallback(lVar4,0);
    LOCK();
    puVar1 = (uint *)(lVar3 + 0x3c);
    uVar2 = *puVar1;
    *puVar1 = 0;
    UNLOCK();
    return (ulong)uVar2;
  }
  uVar5 = nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",
                              0x347);
  return uVar5;
}


// ===== 0035de80 fecsBufferReset =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fecsBufferReset(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  char local_a8;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined8 local_78;
  undefined8 local_70;
  undefined4 local_68;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48;
  
  plVar2 = *(long **)(param_2 + 0x220);
  if (plVar2 == (long *)0x0) {
    nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x5e9);
    return;
  }
  if (*plVar2 != 0) {
    iVar3 = _fecsLoadInternalRoutingInfo(param_1,param_2,&local_c0,&local_bc,&local_b8);
    if (iVar3 == 0) {
      lVar1 = param_1 + 0x3b58;
      iVar3 = (**(code **)(param_1 + 0x3b90))();
      uVar5 = 0x5f7;
      pcVar6 = 
      "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_GR_GET_FECS_TRACE_HW_ENABLE, &getHwEnableParams, sizeof(getHwEnableParams))"
      ;
      if (iVar3 == 0) {
        lVar4 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_2,0,0x5f7);
        if (lVar4 == 0) {
          return;
        }
        if (*(long *)(lVar4 + 0x30) == 0) {
          return;
        }
        lVar4 = memdescGetMemDescFromGpu(*(long *)(lVar4 + 0x30),param_1);
        if (lVar4 == 0) {
          return;
        }
        if (local_a8 == '\x01') {
          return;
        }
        portMemSet(*plVar2,0xde,*(undefined8 *)(lVar4 + 0x30));
        *(undefined4 *)((long)plVar2 + 0x14) = 0;
        local_88 = 0;
        local_98 = local_b8;
        local_90 = local_b0;
        local_78 = local_b8;
        local_70 = local_b0;
        local_58 = local_b8;
        local_50 = local_b0;
        iVar3 = (**(code **)(param_1 + 0x3b90))(lVar1,local_c0,local_bc,0x20800a3a,&local_98,0x18);
        uVar5 = 0x615;
        pcVar6 = 
        "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_GR_SET_FECS_TRACE_WR_OFFSET, &traceWrOffsetParams, sizeof(traceWrOffsetParams))"
        ;
        if (iVar3 == 0) {
          local_68 = 0;
          iVar3 = (**(code **)(param_1 + 0x3b90))(lVar1,local_c0,local_bc,0x20800a39,&local_78,0x18)
          ;
          uVar5 = 0x620;
          pcVar6 = 
          "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_GR_SET_FECS_TRACE_RD_OFFSET, &traceRdOffsetParams, sizeof(traceRdOffsetParams))"
          ;
          if (iVar3 == 0) {
            *(undefined2 *)((long)plVar2 + 10) = 0;
            local_48 = 1;
            iVar3 = (**(code **)(param_1 + 0x3b90))
                              (lVar1,local_c0,local_bc,0x20800a37,&local_58,0x18);
            if (iVar3 == 0) {
              return;
            }
            uVar5 = 0x62c;
            pcVar6 = 
            "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_GR_SET_FECS_TRACE_HW_ENABLE, &setHwEnableParams, sizeof(setHwEnableParams))"
            ;
          }
        }
      }
      nvAssertOkFailedNoLog(iVar3,pcVar6,"src/kernel/gpu/gr/fecs_event_list.c",uVar5);
      return;
    }
    nvAssertOkFailedNoLog
              (iVar3,
               "_fecsLoadInternalRoutingInfo(pGpu, pKernelGraphics, &hClient, &hSubdevice, &getHwEnableParams.grRouteInfo)"
               ,"src/kernel/gpu/gr/fecs_event_list.c",0x5ee);
  }
  return;
}


// ===== 0035e120 fecsBufferDisableHw =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fecsBufferDisableHw(long param_1,undefined8 param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  char local_58;
  undefined8 local_48;
  undefined8 local_40;
  undefined1 local_38;
  
  iVar1 = _fecsLoadInternalRoutingInfo(param_1,param_2,&local_70,&local_6c,&local_68);
  if (iVar1 != 0) {
    nvCheckOkFailedNoLog
              (1,iVar1,
               "_fecsLoadInternalRoutingInfo(pGpu, pKernelGraphics, &hClient, &hSubdevice, &getHwEnableParams.grRouteInfo)"
               ,"src/kernel/gpu/gr/fecs_event_list.c",0x647);
    return;
  }
  uVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,local_70,local_6c,0x20800a38,&local_68,0x18);
  uVar3 = 0x657;
  if ((uVar2 & 0xffffffef) == 0) {
    if ((uVar2 != 0x10) && (local_58 != '\0')) {
      local_38 = 0;
      local_48 = local_68;
      local_40 = local_60;
      uVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,local_70,local_6c,0x20800a37,&local_48,0x18);
      if ((uVar2 & 0xffffffef) != 0) {
        uVar3 = 0x667;
        goto LAB_0035e1f6;
      }
    }
    return;
  }
LAB_0035e1f6:
  nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                      "src/kernel/gpu/gr/fecs_event_list.c",uVar3);
  return;
}


// ===== 0035e250 fecsRemoveBindpoint =====

void fecsRemoveBindpoint(long param_1,undefined8 param_2,long *param_3)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  long *plVar6;
  byte bVar7;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x56a);
    return;
  }
  lVar3 = *param_3;
  *(short *)(lVar2 + 0x40) = *(short *)(lVar2 + 0x40) + -1;
  unregisterEventNotificationWithData
            (lVar3 + 0x160,(int)param_3[1],*(undefined4 *)((long)param_3 + 0xc),(int)param_3[2],1,
             *(undefined8 *)(lVar3 + 0x1a8));
  multimapRemoveItemByKey_IMPL(lVar2,param_2,lVar3);
  if (*(short *)(lVar2 + 0x40) == 0) {
    uVar5 = 1;
    if (*(long *)(param_1 + 0x1bc0) != 0) {
      cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
      uVar5 = (-(uint)(cVar4 == '\0') & 0xfffffff9) + 8;
    }
    plVar6 = (long *)(param_1 + 0x1bd0);
    bVar7 = 0;
    plVar1 = plVar6 + (uVar5 & 0xff);
    do {
      lVar2 = *plVar6;
      if (lVar2 != 0) {
        fecsBufferDisableHw(param_1,lVar2);
        bVar7 = bVar7 | *(byte *)(lVar2 + 0x1fa);
      }
      plVar6 = plVar6 + 1;
    } while (plVar6 != plVar1);
    if (bVar7 == 0) {
      lVar2 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",
                            0x3a2);
        return;
      }
      if (*(long *)(lVar2 + 0x30) != 0) {
        tmrEventDestroy_IMPL(*(undefined8 *)(param_1 + 0x1b88));
        *(undefined8 *)(lVar2 + 0x30) = 0;
      }
    }
  }
  return;
}


// ===== 0035e3da fecsAddBindpoint.cold =====

void fecsAddBindpoint_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0035e3f0 fecsAddBindpoint =====

int fecsAddBindpoint(long param_1,long param_2,long param_3,long param_4,char param_5,int param_6,
                    uint param_7,char param_8,undefined4 *param_9)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  code *pcVar8;
  uint uVar9;
  char cVar10;
  char cVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  long *plVar15;
  undefined8 uVar16;
  byte bVar17;
  long *plVar18;
  undefined8 uVar19;
  bool bVar20;
  long local_40 [2];
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)invalidInstructionException();
    (*pcVar8)();
  }
  uVar2 = *(undefined4 *)(*(long *)(param_2 + 0x100) + 0x48);
  uVar3 = *(undefined4 *)(param_3 + 0x10);
  if (param_4 == 0) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)invalidInstructionException();
    (*pcVar8)();
  }
  uVar4 = *(undefined4 *)(*(long *)(*(long *)(param_4 + 0x140) + 0x48) + 0x10);
  cVar10 = osIsAdministrator();
  bVar20 = false;
  lVar6 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  lVar7 = *(long *)(param_1 + 0x1bc0);
  if (lVar7 != 0) {
    cVar11 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,lVar7);
    bVar20 = cVar11 != '\0';
  }
  lVar13 = resservGetTlsCallContext();
  if (lVar13 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x48c);
    return 0x40;
  }
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x48d);
    return 0x40;
  }
  sVar1 = *(short *)(lVar6 + 0x40);
  uVar5 = *(uint *)(lVar13 + 0x28);
  cVar11 = rmapiLockIsOwner();
  if ((cVar11 == '\0') ||
     (cVar11 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4)), cVar11 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/fecs_event_list.c",0x49a);
    return 0x2f;
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
LAB_0035e4e5:
    cVar11 = hypervisorIsVgxHyper_IMPL();
    if (cVar11 != '\0') goto LAB_0035e4f0;
  }
  else {
    lVar13 = gpuGetStaticInfo(param_1);
    if ((lVar13 == 0) || (*(char *)(lVar13 + 0xa7ac) == '\0')) {
      if (param_9 == (undefined4 *)0x0) {
        return 0x56;
      }
      *param_9 = 5;
      return 0x56;
    }
    if (*(char *)(param_1 + 0x908) == '\0') goto LAB_0035e4e5;
LAB_0035e4f0:
    if (((*(char *)(param_1 + 0x4a27) != '\0') && (cVar10 == '\0')) &&
       (cVar11 = osCheckAccess(3), cVar11 == '\0')) {
      if (param_9 == (undefined4 *)0x0) {
        return 0x56;
      }
      *param_9 = 4;
      return 0x56;
    }
  }
  if (uVar5 < 2) {
    param_7 = 0xc0;
    uVar9 = param_7;
  }
  else if (param_6 == 2) {
    param_7 = 0x32;
    uVar9 = param_7;
  }
  else if (param_6 == 3) {
    uVar9 = param_7 | 0xf;
    if ((param_7 & 4) == 0) {
      uVar9 = param_7;
    }
  }
  else {
    uVar9 = -(uint)(param_6 == 0) | 0xc0;
  }
  param_7 = uVar9;
  if (param_5 == '\0') {
    uVar19 = *(undefined8 *)(param_2 + 0x248);
    if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
      if (param_9 != (undefined4 *)0x0) {
        *param_9 = 3;
      }
      return 0x56;
    }
  }
  else {
    uVar19 = 0;
  }
  lVar13 = __nvoc_dynamicCast(*(undefined8 *)(param_3 + 8),__nvoc_class_def_EventBuffer);
  if (lVar13 == 0) {
    return 0x1f;
  }
  lVar14 = multimapFindSubmap_IMPL(lVar6,uVar19);
  if ((lVar14 == 0) && (lVar14 = multimapInsertSubmap_IMPL(lVar6,uVar19), lVar14 == 0)) {
    nvDbg_Printf("src/kernel/gpu/gr/fecs_event_list.c",0x4f4,"fecsAddBindpoint",4,
                 "NVRM: failed to add UID binding!\n");
    return 0x1a;
  }
  lVar14 = multimapFindItem_IMPL(lVar6,uVar19,lVar13);
  if (lVar14 != 0) {
    return 0;
  }
  plVar15 = (long *)multimapInsertItemNew_IMPL(lVar6,uVar19,lVar13);
  if (plVar15 == (long *)0x0) {
    return 0x1f;
  }
  *(short *)(lVar6 + 0x40) = *(short *)(lVar6 + 0x40) + 1;
  *(undefined4 *)(plVar15 + 2) = uVar3;
  *plVar15 = lVar13;
  plVar15[1] = CONCAT44(uVar4,uVar2);
  lVar14 = *(long *)(param_2 + 0x248);
  *(bool *)((long)plVar15 + 0x21) = 1 < uVar5;
  plVar15[3] = lVar14;
  uVar16 = 0x10000002;
  if (param_8 != '\x02') {
    uVar16 = 0x10000086;
  }
  *(char *)(plVar15 + 4) = cVar10;
  *(uint *)((long)plVar15 + 0x24) = param_7;
  *(char *)(plVar15 + 5) = param_8;
  iVar12 = registerEventNotification
                     (lVar13 + 0x160,*(undefined8 *)(param_2 + 0x100),uVar4,uVar3,uVar16,0x7f,
                      *(undefined8 *)(lVar13 + 0x1a8),0);
  if (iVar12 != 0) goto LAB_0035e887;
  lVar13 = 1;
  if (bVar20) {
    cVar10 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL
                       (param_1,lVar7,*(undefined8 *)(*(long *)(param_4 + 0x158) + 0xe8));
    if (cVar10 == '\0') {
      iVar12 = gisubscriptionGetGPUInstanceSubscription_IMPL
                         (*(undefined8 *)(param_2 + 0x100),uVar4,local_40);
      if (iVar12 != 0) goto LAB_0035e887;
      if (*(long *)(local_40[0] + 0x138) == 0) {
        if (param_9 != (undefined4 *)0x0) {
          *param_9 = 3;
        }
LAB_0035e881:
        iVar12 = 0x56;
        goto LAB_0035e887;
      }
      *(undefined4 *)((long)plVar15 + 0x2c) =
           *(undefined4 *)(*(long *)(local_40[0] + 0x138) + 0x968);
    }
    else {
      *(undefined4 *)((long)plVar15 + 0x2c) = 0xffffffff;
    }
    lVar13 = 8;
  }
  bVar17 = 0;
  plVar18 = (long *)(param_1 + 0x1bd0);
  do {
    lVar7 = *plVar18;
    if (lVar7 != 0) {
      if (*(char *)(lVar7 + 0x1f8) == '\0') {
        if (param_9 != (undefined4 *)0x0) {
          *param_9 = 2;
        }
        goto LAB_0035e881;
      }
      if (sVar1 < 1) {
        fecsBufferReset(param_1,lVar7);
      }
      bVar17 = bVar17 | *(byte *)(lVar7 + 0x1fa);
    }
    plVar18 = plVar18 + 1;
  } while ((long *)(param_1 + 0x1bd0 + lVar13 * 8) != plVar18);
  if (0 < sVar1 || bVar17 != 0) {
    return 0;
  }
  lVar7 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x38d);
    iVar12 = 0x40;
  }
  else {
    uVar16 = *(undefined8 *)(param_1 + 0x1b88);
    iVar12 = tmrEventCreate_IMPL(uVar16,lVar7 + 0x30,_fecsTimerCallback,0,9);
    if (iVar12 == 0) {
      iVar12 = tmrEventScheduleRel_IMPL
                         (uVar16,*(undefined8 *)(lVar7 + 0x30),*(undefined4 *)(lVar7 + 0x38));
      if (iVar12 == 0) {
        return 0;
      }
      nvCheckOkFailedNoLog
                (4,iVar12,
                 "tmrEventScheduleRel(pTmr, pFecsGlobalTraceInfo->pFecsTimerEvent, pFecsGlobalTraceInfo->fecsTimerInterval)"
                 ,"src/kernel/gpu/gr/fecs_event_list.c",0x393);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar12,
                 "tmrEventCreate(pTmr, &pFecsGlobalTraceInfo->pFecsTimerEvent, _fecsTimerCallback, NULL, timerFlags)"
                 ,"src/kernel/gpu/gr/fecs_event_list.c",0x38f);
    }
  }
  nvCheckOkFailedNoLog
            (4,iVar12,"_fecsTimerCreate(pGpu)","src/kernel/gpu/gr/fecs_event_list.c",0x54f);
LAB_0035e887:
  if (sVar1 != *(short *)(lVar6 + 0x40)) {
    fecsRemoveBindpoint(param_1,uVar19,plVar15);
  }
  lVar6 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x3a2);
    return iVar12;
  }
  if (*(long *)(lVar6 + 0x30) != 0) {
    tmrEventDestroy_IMPL(*(undefined8 *)(param_1 + 0x1b88));
    *(undefined8 *)(lVar6 + 0x30) = 0;
    return iVar12;
  }
  return iVar12;
}


// ===== 0035eb90 fecsRemoveAllBindpointsForGpu =====

void fecsRemoveAllBindpointsForGpu(long param_1)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48 [4];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1bc8) + 0x488);
  if (lVar1 != 0) {
    uVar3 = mapFindLEQ_IMPL(lVar1,0xffffffffffffffff);
    uVar4 = mapFindGEQ_IMPL(lVar1,0);
    mapIterRange_IMPL(&local_88,lVar1,uVar4,uVar3);
    local_68 = local_88;
    local_60 = local_80;
    local_58 = local_78;
    local_50 = local_70;
    while (cVar2 = mapIterNext_IMPL(&local_68), uVar3 = local_68, cVar2 != '\0') {
      uVar4 = mapFindLEQ_IMPL(local_68,0xffffffffffffffff);
      uVar5 = mapFindGEQ_IMPL(uVar3,0);
      multimapItemIterRange_IMPL(local_48,lVar1,uVar5,uVar4);
      uVar3 = mapKey_IMPL(local_60,uVar3);
      while (cVar2 = multimapItemIterNext_IMPL(local_48), cVar2 != '\0') {
        fecsRemoveBindpoint(param_1,uVar3,local_48[0]);
      }
    }
  }
  return;
}


// ===== 0035ecb0 fecsRemoveAllBindpoints =====

void fecsRemoveAllBindpoints(long param_1)

{
  long lVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_50 = 0;
  local_4c = 0;
  eventBufferSetEnable(param_1 + 0x168,0);
  gpumgrGetGpuAttachInfo(0,&local_50);
  while( true ) {
    lVar3 = gpumgrGetNextGpu(local_50,&local_4c);
    if (lVar3 == 0) break;
    lVar1 = *(long *)(*(long *)(lVar3 + 0x1bc8) + 0x488);
    if (lVar1 == 0) {
      nvCheckFailedNoLog(4,"pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",
                         0x5c6);
    }
    uVar4 = mapFindLEQ_IMPL(lVar1,0xffffffffffffffff);
    uVar5 = mapFindGEQ_IMPL(lVar1,0);
    mapIterRange_IMPL(&local_78,lVar1,uVar5,uVar4);
    local_48 = local_78;
    local_40 = local_70;
    local_38 = local_68;
    local_30 = local_60;
    while( true ) {
      cVar2 = mapIterNext_IMPL(&local_48);
      if (cVar2 == '\0') break;
      uVar4 = mapKey_IMPL(local_40,local_48);
      while( true ) {
        lVar6 = multimapFindItem_IMPL(lVar1,uVar4,param_1);
        if (lVar6 == 0) break;
        fecsRemoveBindpoint(lVar3,uVar4,lVar6);
      }
    }
  }
  return;
}


// ===== 0035ee00 fecsHandleFecsLoggingError =====

undefined8 fecsHandleFecsLoggingError(long param_1,uint param_2,int param_3)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_2 < 8) {
    lVar1 = *(long *)(param_1 + 0x1bd0 + (ulong)param_2 * 8);
  }
  if (param_3 == 1) {
    fecsBufferDisableHw(param_1,lVar1);
    *(undefined1 *)(lVar1 + 0x1f9) = 0;
    fecsBufferReset(param_1,lVar1);
  }
  else {
    if (param_3 != 2) {
      return 0x1f;
    }
    nvEventBufferFecsCallback(param_1,lVar1);
  }
  return 0;
}


// ===== 0035ee70 fecsBufferIsMapped =====

undefined8 fecsBufferIsMapped(undefined8 param_1,long param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_2 + 0x220);
  if (plVar1 != (long *)0x0) {
    return CONCAT71((int7)((ulong)plVar1 >> 8),*plVar1 != 0);
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x680);
  return 0;
}


// ===== 0035eeb0 fecsBufferMap =====

undefined8 fecsBufferMap(long param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  
  plVar1 = *(long **)(param_2 + 0x220);
  if (plVar1 == (long *)0x0) {
    nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x691);
    return 0x40;
  }
  if (((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) &&
     (*plVar1 == 0)) {
    uVar2 = *(undefined8 *)(param_1 + 0x1b78);
    lVar3 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_2,0);
    if (lVar3 == 0) {
      return 0x40;
    }
    if (*(long *)(lVar3 + 0x30) == 0) {
      return 0x40;
    }
    lVar3 = memdescGetMemDescFromGpu(*(long *)(lVar3 + 0x30),param_1);
    if (lVar3 == 0) {
      return 0x40;
    }
    lVar3 = memmgrMemDescBeginTransfer_IMPL(uVar2,lVar3,0x408);
    if (lVar3 == 0) {
      return 0x1a;
    }
    *plVar1 = lVar3;
  }
  return 0;
}


// ===== 0035efa0 fecsBufferUnmap =====

void fecsBufferUnmap(long param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  
  plVar1 = *(long **)(param_2 + 0x220);
  if (plVar1 == (long *)0x0) {
    nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x6b4);
    return;
  }
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
    uVar2 = *(undefined8 *)(param_1 + 0x1b78);
    lVar3 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_2,0);
    if ((lVar3 != 0) &&
       (((*(long *)(lVar3 + 0x30) != 0 &&
         (lVar3 = memdescGetMemDescFromGpu(*(long *)(lVar3 + 0x30),param_1), lVar3 != 0)) &&
        (*plVar1 != 0)))) {
      memmgrMemDescEndTransfer_IMPL(uVar2,lVar3,0x408);
      *plVar1 = 0;
      return;
    }
  }
  return;
}


// ===== 0035f060 fecsBufferTeardown =====

void fecsBufferTeardown(undefined8 param_1,undefined8 param_2)

{
  fecsBufferDisableHw();
  fecsBufferUnmap(param_1,param_2);
  return;
}


// ===== 0035f090 fecsSignalIntrPendingIfNotPending =====

undefined8 fecsSignalIntrPendingIfNotPending(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  
  if (*(long *)(param_2 + 0x220) != 0) {
    uVar3 = 0;
    puVar1 = (uint *)(*(long *)(param_2 + 0x220) + 0x10);
    LOCK();
    uVar2 = *puVar1;
    if (uVar2 == 0) {
      *puVar1 = 1;
    }
    else {
      uVar3 = (ulong)uVar2;
    }
    UNLOCK();
    return CONCAT71((int7)(uVar3 >> 8),uVar2 == 0);
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x6d1);
  return 0;
}


// ===== 0035f0d0 fecsClearIntrPendingIfPending =====

undefined8 fecsClearIntrPendingIfPending(undefined8 param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  ulong uVar3;
  
  if (*(long *)(param_2 + 0x220) != 0) {
    uVar3 = 0;
    puVar1 = (uint *)(*(long *)(param_2 + 0x220) + 0x10);
    LOCK();
    uVar2 = *puVar1;
    if (uVar2 == 1) {
      *puVar1 = 0;
    }
    else {
      uVar3 = (ulong)uVar2;
    }
    UNLOCK();
    return CONCAT71((int7)(uVar3 >> 8),uVar2 == 1);
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x6e0);
  return 0;
}


// ===== 0035f110 fecsIsIntrPending =====

undefined8 fecsIsIntrPending(undefined8 param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  
  lVar2 = *(long *)(param_2 + 0x220);
  if (lVar2 != 0) {
    uVar4 = (ulong)*(uint *)(lVar2 + 0x10);
    do {
      uVar3 = (uint)uVar4;
      LOCK();
      uVar1 = *(uint *)(lVar2 + 0x10);
      if (uVar3 == uVar1) {
        *(uint *)(lVar2 + 0x10) = uVar3;
      }
      else {
        uVar4 = (ulong)uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    return CONCAT71((int7)(uVar4 >> 8),uVar3 != 0);
  }
  nvAssertFailedNoLog("pFecsTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x6ee);
  return 0;
}


// ===== 0035f160 fecsGetCtxswLogConsumerCount =====

undefined2 fecsGetCtxswLogConsumerCount(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x488) != 0) {
    return *(undefined2 *)(*(long *)(param_2 + 0x488) + 0x40);
  }
  nvCheckFailedNoLog(4,"pFecsGlobalTraceInfo != NULL","src/kernel/gpu/gr/fecs_event_list.c",0x6fc);
  return 0;
}


// ===== 0035f1a0 _kgraphicsInternalClientAlloc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kgraphicsInternalClientAlloc
              (long param_1,long param_2,int param_3,undefined4 *param_4,undefined8 param_5,
              undefined4 *param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined4 local_4c;
  undefined1 local_48 [8];
  int local_40;
  
  lVar4 = rmapiGetInterface(4);
  iVar2 = *(int *)(param_2 + 0x20c);
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar1 == '\0')) {
    iVar3 = 0x55;
    if ((iVar2 == 0) &&
       (iVar3 = rmapiutilAllocClientAndDeviceHandles(lVar4,param_1,param_4,param_5,param_6),
       iVar3 != 0)) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, phClient, phDevice, phSubdevice)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x268);
    }
    return iVar3;
  }
  if (param_3 == -1) {
    return 0x55;
  }
  iVar2 = rmapiutilAllocClientAndDeviceHandles(lVar4,param_1,param_4,param_5,param_6);
  if (iVar2 == 0) {
    iVar2 = serverutilGenResourceHandle(*param_4,&local_4c);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"serverutilGenResourceHandle(*phClient, &hSubscription)",
                 "src/kernel/gpu/gr/kernel_graphics.c",600);
    }
    portMemSet(local_48,0,0x10);
    local_40 = param_3;
    iVar2 = (**(code **)(lVar4 + 8))(lVar4,*param_4,*param_6,local_4c,0xc637,local_48,0x10);
    if (iVar2 == 0) {
      return 0;
    }
    nvAssertOkFailedNoLog
              (iVar2,
               "pRmApi->AllocWithHandle(pRmApi, *phClient, *phSubdevice, hSubscription, AMPERE_SMC_PARTITION_REF, &params, sizeof(params))"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0x25c);
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar2,
             "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, phClient, phDevice, phSubdevice)",
             "src/kernel/gpu/gr/kernel_graphics.c",0x253);
  return iVar2;
}


// ===== 0035f380 _kgraphicsCtrlCmdGrGetInfoV2 =====

int _kgraphicsCtrlCmdGrGetInfoV2(long param_1,undefined8 param_2,uint *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  long local_30;
  
  lVar6 = *(long *)(param_1 + 0x1bc8);
  if (lVar6 == 0) {
    return 0x56;
  }
  uVar3 = *param_3;
  if (uVar3 - 1 < 0x3b) {
    cVar4 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL
                      (param_1,*(undefined8 *)(param_1 + 0x1bc0),param_2);
    if (cVar4 == '\0') {
      iVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(param_1,lVar6,param_2,param_3 + 0x78,&local_30);
      if (iVar5 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar5,
                   "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0xb17);
        return iVar5;
      }
      pcVar8 = *(char **)(local_30 + 0x210);
      if ((pcVar8 == (char *)0x0) || (*pcVar8 == '\0')) {
        uVar7 = 0xb1b;
        pcVar8 = "pKernelGraphicsStaticInfo != NULL";
        goto LAB_0035f4f3;
      }
      lVar6 = *(long *)(pcVar8 + 8);
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pGrInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xb1c);
        return 0x56;
      }
    }
    else {
      uVar7 = 0xb0d;
      pcVar8 = "kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->bInitialized";
      if (*(char *)(lVar6 + 0x438) == '\0') {
LAB_0035f4f3:
        nvAssertFailedNoLog(pcVar8,"src/kernel/gpu/gr/kernel_graphics.c",uVar7);
        return 0x40;
      }
      lVar6 = *(long *)(lVar6 + 0x430);
      if (lVar6 == 0) {
        nvAssertFailedNoLog("kgrmgrGetLegacyKGraphicsStaticInfo(pGpu, pKernelGraphicsManager)->pGrInfo != NULL"
                            ,"src/kernel/gpu/gr/kernel_graphics.c",0xb0e);
        return 0x56;
      }
    }
    puVar2 = param_3 + (ulong)uVar3 * 2;
    while (puVar1 = param_3 + 1, *puVar1 < 0x3b) {
      param_3 = param_3 + 2;
      *param_3 = *(uint *)(lVar6 + 4 + (ulong)*puVar1 * 8);
      if (puVar2 == param_3) {
        return 0;
      }
    }
    nvCheckFailedNoLog(4,"pParams->grInfoList[i].index < NV2080_CTRL_GR_INFO_MAX_SIZE",
                       "src/kernel/gpu/gr/kernel_graphics.c",0xb23);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0xb07,"_kgraphicsCtrlCmdGrGetInfoV2",4,
                 "NVRM: Invalid grInfoList size: 0x%x\n",(ulong)uVar3);
  }
  return 0x1f;
}


// ===== 0035f5c0 kgraphicsConstructEngine_IMPL =====

int kgraphicsConstructEngine_IMPL(long param_1,long param_2,byte param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint *puVar10;
  char *pcVar11;
  uint local_88 [22];
  
  *(uint *)(param_2 + 0x20c) = (uint)param_3;
  lVar6 = portMemAllocNonPaged(0x1418);
  if (lVar6 == 0) {
    return 0x51;
  }
  portMemSet(lVar6,0,0x1418);
  *(long *)(param_2 + 0x210) = lVar6;
  puVar7 = (undefined8 *)(param_2 + 0x520);
  do {
    *puVar7 = ADDRLIST_FBMEM_PREFERRED;
    puVar8 = puVar7 + 2;
    *(undefined4 *)(puVar7 + 1) = 1;
    puVar7 = puVar8;
  } while (puVar8 != (undefined8 *)(param_2 + 0x5c0));
  local_88[0] = 0;
  puVar10 = local_88;
  local_88[2] = 8;
  local_88[4] = 1;
  local_88[6] = 2;
  local_88[1] = *(uint *)(param_1 + 0x4924) >> 10 & 3;
  uVar2 = *(uint *)(param_1 + 0x4928);
  local_88[8] = 3;
  local_88[10] = 5;
  local_88[0xc] = 6;
  local_88[0xe] = 4;
  local_88[3] = uVar2 >> 0xe & 3;
  local_88[0x10] = 7;
  local_88[7] = uVar2 >> 0x18 & 3;
  uVar3 = *(uint *)(param_1 + 0x492c);
  local_88[5] = uVar2 >> 0x16 & 3;
  local_88[0x12] = 9;
  local_88[9] = uVar3 >> 2 & 3;
  local_88[0xb] = uVar3 >> 4 & 3;
  local_88[0xd] = uVar3 >> 6 & 3;
  local_88[0xf] = uVar3 >> 0x10 & 3;
  local_88[0x13] = uVar3 >> 0x18 & 3;
  local_88[0x11] = uVar3 >> 0x1a & 3;
  do {
    uVar2 = *puVar10;
    pcVar11 = "GR_CTX_BUFFER__UNKNOWN";
    lVar6 = (ulong)uVar2 * 0x10;
    if (uVar2 < 10) {
      pcVar11 = *(char **)(CSWTCH_220 + (ulong)uVar2 * 8);
    }
    puVar1 = puVar10 + 1;
    puVar10 = puVar10 + 2;
    memdescOverrideInstLocList(*puVar1,pcVar11,param_2 + 0x520 + lVar6,param_2 + 0x528 + lVar6);
  } while (puVar10 != local_88 + 0x14);
  puVar7 = (undefined8 *)(param_2 + 0x248);
  puVar8 = puVar7;
  do {
    *puVar8 = ADDRLIST_FBMEM_PREFERRED;
    puVar9 = puVar8 + 2;
    *(undefined4 *)(puVar8 + 1) = 1;
    puVar8 = puVar9;
  } while ((undefined8 *)(param_2 + 0x2e8) != puVar9);
  *(undefined8 **)(param_2 + 0x2a8) = &ADDRLIST_SYSMEM_ONLY;
  puVar10 = local_88;
  *(undefined4 *)(param_2 + 0x2b0) = 0;
  local_88[0] = 6;
  local_88[2] = 2;
  local_88[4] = 0;
  local_88[1] = *(uint *)(param_1 + 0x4930) >> 0x16 & 3;
  uVar2 = *(uint *)(param_1 + 0x4928);
  local_88[6] = 1;
  local_88[8] = 7;
  local_88[10] = 8;
  local_88[0xc] = 9;
  local_88[3] = uVar2 >> 2 & 3;
  local_88[0xe] = 3;
  local_88[7] = uVar2 >> 6 & 3;
  local_88[5] = uVar2 >> 4 & 3;
  local_88[9] = *(uint *)(param_1 + 0x492c) >> 10 & 3;
  local_88[0xf] = *(uint *)(param_1 + 0x492c) >> 0x18 & 3;
  local_88[0xb] = local_88[9];
  local_88[0xd] = local_88[9];
  do {
    uVar2 = *puVar10;
    pcVar11 = "GR_GLOBALCTX_BUFFER__UNKNOWN";
    lVar6 = ((ulong)uVar2 + 0x25) * 0x10;
    if (uVar2 < 10) {
      pcVar11 = *(char **)(CSWTCH_217 + (ulong)uVar2 * 8);
    }
    puVar1 = puVar10 + 1;
    puVar10 = puVar10 + 2;
    memdescOverrideInstLocList(*puVar1,pcVar11,param_2 + -8 + lVar6,param_2 + lVar6);
  } while (local_88 + 0x10 != puVar10);
  do {
    puVar7[0x28] = &ADDRLIST_FBMEM_ONLY;
    puVar8 = puVar7 + 2;
    *(undefined4 *)(puVar7 + 0x29) = 1;
    puVar7[0x14] = *puVar7;
    puVar7[0x15] = puVar7[1];
    puVar7 = puVar8;
  } while ((undefined8 *)(param_2 + 0x2e8) != puVar8);
  *(undefined8 *)(param_2 + 0x238) = 0x10000;
  *(undefined2 *)(param_2 + 0x240) = 0;
  iVar4 = fecsCtxswLoggingInit(param_1,param_2,param_2 + 0x220);
  if (iVar4 == 0) {
    iVar5 = osReadRegistryDword(param_1,"RmForceGrScrubberChannel",local_88);
    if (iVar5 == 0) {
      if (local_88[0] == 0) {
        *(undefined1 *)(param_2 + 0x20a) = 0;
        return 0;
      }
      if (local_88[0] == 1) {
        *(undefined1 *)(param_2 + 0x20a) = 1;
      }
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,"fecsCtxswLoggingInit(pGpu, pKernelGraphics, &pKernelGraphics->pFecsTraceInfo)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xe7);
  }
  return iVar4;
}


// ===== 0035f9e0 kgraphicsStateInitLocked_IMPL =====

int kgraphicsStateInitLocked_IMPL(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  int local_3c [3];
  
  iVar1 = gpuGetClassList_IMPL(param_1,local_3c,0,*(uint *)(param_2 + 0x20c) | 0xd334df00);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"gpuGetClassList(pGpu, &numClasses, NULL, ENG_GR(pKernelGraphics->instance))",
               "src/kernel/gpu/gr/kernel_graphics.c",0x107);
    return iVar1;
  }
  if ((local_3c[0] == 0) && (*(int *)(param_1 + 0x8a0) != 0)) {
    lVar3 = 0;
    lVar2 = *(long *)(param_1 + 0x898);
    do {
      iVar1 = *(int *)(lVar2 + lVar3 * 8);
      if ((iVar1 != -1) &&
         ((*(uint *)(param_2 + 0x20c) | 0xd334df00) == *(uint *)(lVar2 + 4 + lVar3 * 8))) {
        nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x11d,"kgraphicsStateInitLocked_IMPL",1,
                     "NVRM: Adding class ID 0x%x to ClassDB\n",iVar1);
        iVar1 = gpuAddClassToClassDBByEngTagClassId_IMPL
                          (param_1,*(uint *)(param_2 + 0x20c) | 0xd334df00,iVar1);
        if (iVar1 != 0) {
          nvAssertOkFailedNoLog
                    (iVar1,
                     "gpuAddClassToClassDBByEngTagClassId(pGpu, ENG_GR(pKernelGraphics->instance), classNum)"
                     ,"src/kernel/gpu/gr/kernel_graphics.c",0x11e);
          return iVar1;
        }
      }
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < *(uint *)(param_1 + 0x8a0));
  }
  uVar4 = -(ulong)(*(char *)(param_1 + 0x491d) == '\0') & 0xffffffffffffe860;
  lVar2 = portMemAllocNonPaged(uVar4 + 0x1800);
  *(long *)(param_2 + 0x230) = lVar2;
  if (lVar2 != 0) {
    portMemSet(lVar2,0,uVar4 + 0x1800);
    if (*(char *)(param_1 + 1099) != '\0') {
      *(undefined1 *)(param_2 + 0x20a) = 0;
    }
    *(undefined8 *)(param_2 + 0x5c0) = 0;
    *(undefined4 *)(param_2 + 0x5c8) = 0;
    *(undefined1 *)(param_2 + 0x5cc) = 0;
    return 0;
  }
  return 0x51;
}


// ===== 0035fbe0 kgraphicsStateUnload_IMPL =====

undefined8 kgraphicsStateUnload_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(int *)(param_2 + 0x20c) != 0) {
    return 0;
  }
  uVar1 = gpuGetKernelFifoShared_IMPL();
  kfifoRemoveSchedulingHandler_IMPL(param_1,uVar1,_kgraphicsPostSchedulingEnableHandler,0,0,0);
  return 0;
}


// ===== 0035fc30 kgraphicsStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

ulong kgraphicsStateLoad_IMPL(long param_1,long param_2)

{
  short sVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  uVar2 = *(undefined8 *)(param_1 + 0x1bc8);
  if (*(char *)(param_1 + 0x4913) != '\0') {
    (**(code **)(param_2 + 0x1e8))(param_1,param_2,0,*(code **)(param_2 + 0x1e8));
  }
  sVar1 = fecsGetCtxswLogConsumerCount(param_1,uVar2);
  if (0 < sVar1) {
    fecsBufferMap(param_1,param_2);
    fecsBufferReset(param_1,param_2);
  }
  uVar3 = 0;
  if (*(int *)(param_2 + 0x20c) == 0) {
    uVar2 = gpuGetKernelFifoShared_IMPL(param_1);
    uVar3 = kfifoAddSchedulingHandler_IMPL
                      (param_1,uVar2,_kgraphicsPostSchedulingEnableHandler,0,0,0);
    if ((int)uVar3 != 0) {
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,
                 "kfifoAddSchedulingHandler(pGpu, GPU_GET_KERNEL_FIFO(pGpu), _kgraphicsPostSchedulingEnableHandler, (void *)((NvUPtr)(pKernelGraphics->instance)), NULL, NULL)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x175);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  return uVar3;
}


// ===== 0035fd00 kgraphicsIsPresent_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool kgraphicsIsPresent_IMPL(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined1 local_1c [4];
  
  lVar2 = gpuGetKernelFifoShared_IMPL();
  if (*(char *)(param_1 + 0x490f) == '\0') {
    iVar1 = (**(code **)(lVar2 + 0x218))(param_1,lVar2,2,*(int *)(param_2 + 0x20c) + 1,0xf,local_1c)
    ;
    return iVar1 == 0;
  }
  return true;
}


// ===== 0035fd70 kgraphicsStatePostLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgraphicsStatePostLoad_IMPL(long param_1,long param_2)

{
  ulong uVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  uVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,0xffffffff);
  uVar3 = 0x1be;
  pcVar2 = "kgraphicsLoadStaticInfo(pGpu, pKernelGraphics, KMIGMGR_SWIZZID_INVALID)";
  if ((int)uVar1 != 0) {
LAB_0035fe1c:
    nvCheckOkFailedNoLog(4,uVar1 & 0xffffffff,pcVar2,"src/kernel/gpu/gr/kernel_graphics.c",uVar3);
    return uVar1 & 0xffffffff;
  }
  pcVar2 = *(char **)(param_2 + 0x210);
  if ((((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) && (*(char *)(param_1 + 0x908) == '\0')) &&
     ((*(long *)(pcVar2 + 0x13e0) != 0 && (*(long *)(*(long *)(param_2 + 0x230) + 0x30) == 0)))) {
    uVar1 = (**(code **)(param_2 + 0x1a8))
                      (param_1,param_2,0,"src/kernel/gpu/gr/kernel_graphics.c",0x1be);
    if ((int)uVar1 != 0) {
      uVar3 = 0x1c6;
      pcVar2 = "kgraphicsAllocGlobalCtxBuffers_HAL(pGpu, pKernelGraphics, GPU_GFID_PF)";
      goto LAB_0035fe1c;
    }
  }
  return uVar1;
}


// ===== 0035fe40 kgraphicsInvalidateStaticInfo_IMPL =====

void kgraphicsInvalidateStaticInfo_IMPL(undefined8 param_1,long param_2)

{
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 8));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 8) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13c8));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13c8) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13d0));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13d0) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13d8));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13d8) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13e0));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13e0) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13e8));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13e8) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13f0));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13f0) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13f8));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x13f8) = 0;
  portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x210) + 0x1408));
  *(undefined8 *)(*(long *)(param_2 + 0x210) + 0x1408) = 0;
  portMemSet(*(long *)(param_2 + 0x210) + 8,0,0x1410);
  **(undefined1 **)(param_2 + 0x210) = 0;
  return;
}


// ===== 0035ffc0 kgraphicsDestruct_IMPL =====

void kgraphicsDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x160);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  fecsCtxswLoggingTeardown(uVar1,param_1);
  *(undefined8 *)(param_1 + 0x220) = 0;
  kgraphicsInvalidateStaticInfo_IMPL(uVar1,param_1);
  portMemFree(*(undefined8 *)(param_1 + 0x210));
  *(undefined8 *)(param_1 + 0x210) = 0;
  return;
}


// ===== 00360030 kgraphicsStateDestroy_IMPL =====

void kgraphicsStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  fecsBufferTeardown();
  kgraphicsInvalidateStaticInfo_IMPL(param_1,param_2);
  portMemFree(*(undefined8 *)(param_2 + 0x230));
  *(undefined8 *)(param_2 + 0x230) = 0;
  return;
}


// ===== 00360080 kgraphicsGetStaticInfo_IMPL =====

char * kgraphicsGetStaticInfo_IMPL(undefined8 param_1,long param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = *(char **)(param_2 + 0x210);
  pcVar2 = pcVar1;
  if (pcVar1 != (char *)0x0) {
    pcVar2 = (char *)0x0;
    if (*pcVar1 != '\0') {
      pcVar2 = pcVar1 + 8;
    }
  }
  return pcVar2;
}


// ===== 003600b0 kgraphicsInitializeDeferredStaticData_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgraphicsInitializeDeferredStaticData_IMPL
              (long param_1,long param_2,int param_3,undefined4 param_4)

{
  undefined8 uVar1;
  char *pcVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined8 uVar11;
  uint local_74;
  undefined4 local_70;
  int local_6c [2];
  char local_61;
  uint local_60;
  int local_5c;
  long local_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
  pcVar2 = *(char **)(param_2 + 0x210);
  local_70 = param_4;
  local_6c[0] = param_3;
  lVar6 = rmapiGetInterface(4);
  local_74 = *(uint *)(param_2 + 0x20c);
  iVar5 = vgpuGetCallingContextGfid(param_1,&local_60);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/gr/kernel_graphics.c",
               0x285);
    return iVar5;
  }
  iVar5 = vgpuIsCallingContextPlugin(param_1,&local_61);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin)",
               "src/kernel/gpu/gr/kernel_graphics.c",0x286);
    return iVar5;
  }
  if (local_61 != '\0') {
    local_60 = 0;
  }
  if (*(char *)(param_1 + 0x490f) != '\0') {
    return 0;
  }
  if (*pcVar2 == '\0') {
    return 0;
  }
  if (*(long *)(pcVar2 + 0x13e0) != 0) {
    return 0;
  }
  if (*(char *)(param_2 + 0x218) != '\0') {
    return 0;
  }
  bVar3 = false;
  if (local_6c[0] == 0) {
    local_50 = 0;
    if ((*(long *)(param_1 + 0x1bc0) == 0) ||
       (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar4 == '\0')) {
      uVar9 = 0xffffffff;
    }
    else {
      iVar5 = kmigmgrGetMIGReferenceFromEngineType_IMPL
                        (param_1,uVar1,*(int *)(param_2 + 0x20c) + 1,&local_48);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kmigmgrGetMIGReferenceFromEngineType(pGpu, pKernelMIGManager, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &ref)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0x2aa);
        return iVar5;
      }
      uVar9 = *(undefined4 *)(local_48 + 0x968);
    }
    iVar5 = _kgraphicsInternalClientAlloc(param_1,param_2,uVar9,local_6c,&local_50,&local_70);
    if (iVar5 == 0x55) {
      return 0;
    }
    if (iVar5 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/gr/kernel_graphics.c",0x2b6);
      return iVar5;
    }
    bVar3 = true;
    if (local_6c[0] == 0) {
      nvAssertFailedNoLog("hClient != NV01_NULL_OBJECT","src/kernel/gpu/gr/kernel_graphics.c",0x2b7)
      ;
      return 0x40;
    }
  }
  *(undefined1 *)(param_2 + 0x218) = 1;
  if ((*(long *)(param_1 + 0x1bc0) == 0) ||
     (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar4 == '\0')) {
LAB_003602a5:
    lVar7 = portMemAllocNonPaged(0x680);
    if (lVar7 == 0) {
      return 0x51;
    }
    portMemSet(lVar7,0,0x680);
    iVar5 = (**(code **)(lVar6 + 0x38))(lVar6,local_6c[0],local_70,0x20800a32,lVar7,0x680);
    if (iVar5 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KGR_GET_CONTEXT_BUFFERS_INFO, pParams, sizeof(*pParams))"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x2e9);
      portMemFree(lVar7);
      if (bVar3) goto LAB_00360500;
      goto LAB_003604c6;
    }
    lVar8 = portMemAllocNonPaged(0xd0);
    *(long *)(pcVar2 + 0x13e0) = lVar8;
    if (lVar8 != 0) {
      portMemCopy(lVar8,0xd0,(ulong)local_74 * 0xd0 + lVar7,0xd0);
      portMemFree(lVar7);
      if (bVar3) {
        (**(code **)(lVar6 + 0x18))(lVar6,local_6c[0],local_6c[0]);
      }
      *(undefined1 *)(param_2 + 0x218) = 0;
      if (*(char *)((ulong)local_60 * 0x60 + *(long *)(param_2 + 0x230) + 0x50) != '\0') {
        return 0;
      }
      if (*(char *)(param_1 + 0x4a23) != '\0') {
        return 0;
      }
      iVar5 = (**(code **)(param_2 + 0x180))(param_1,param_2,(ulong)local_60,0);
      if (iVar5 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar5,"kgraphicsAllocGrGlobalCtxBuffers_HAL(pGpu, pKernelGraphics, gfid, NULL)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0x31c);
        return iVar5;
      }
      return 0;
    }
    portMemFree(lVar7);
    if (!bVar3) {
      *(undefined1 *)(param_2 + 0x218) = 0;
      return 0x51;
    }
    iVar5 = 0x51;
    goto LAB_00360500;
  }
  iVar5 = serverGetClientUnderLock(g_resServ,local_6c[0],&local_50);
  uVar11 = 0x2c5;
  pcVar10 = "serverGetClientUnderLock(&g_resServ, hClient, &pClient)";
  if (iVar5 == 0) {
    iVar5 = subdeviceGetByHandle_IMPL
                      (CONCAT44(uStack_4c,local_50),local_70,&local_58,
                       "src/kernel/gpu/gr/kernel_graphics.c",0x2c5);
    if (iVar5 != 0) {
      uVar11 = 0x2cb;
      pcVar10 = "subdeviceGetByHandle(pClient, hSubdevice, &pSubdevice)";
      goto LAB_003605b7;
    }
    iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (param_1,uVar1,*(undefined8 *)(*(long *)(local_58 + 0x158) + 0xe8),&local_48);
    uVar11 = 0x2d2;
    pcVar10 = 
    "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pSubdevice), &ref)"
    ;
    if (iVar5 != 0) goto LAB_003605b7;
    iVar5 = kmigmgrGetGlobalToLocalEngineType_IMPL
                      (param_1,uVar1,local_48,local_40,local_74 + 1,&local_5c);
    local_74 = local_5c - 1;
    if (iVar5 == 0) goto LAB_003602a5;
    nvCheckOkFailedNoLog
              (4,iVar5,
               "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(grIdx), &localRmEngineType)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0x2d9);
  }
  else {
LAB_003605b7:
    nvCheckOkFailedNoLog(4,iVar5,pcVar10,"src/kernel/gpu/gr/kernel_graphics.c",uVar11);
  }
  if (!bVar3) {
LAB_003604c6:
    *(undefined1 *)(param_2 + 0x218) = 0;
    return iVar5;
  }
LAB_00360500:
  (**(code **)(lVar6 + 0x18))(lVar6,local_6c[0],local_6c[0]);
  *(undefined1 *)(param_2 + 0x218) = 0;
  return iVar5;
}


// ===== 00360620 kgraphicsLoadStaticInfo_VF =====

undefined8 kgraphicsLoadStaticInfo_VF(long param_1,long param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  char cVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  
  pcVar2 = *(char **)(param_2 + 0x210);
  lVar4 = gpuGetStaticInfo();
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x331);
    return 0x40;
  }
  if (pcVar2 == (char *)0x0) {
    nvAssertFailedNoLog("pPrivate != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x332);
    return 0x40;
  }
  if (*pcVar2 != '\0') {
    return 0;
  }
  uVar1 = *(uint *)(param_2 + 0x20c);
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar3 == '\0')) {
    if (uVar1 != 0) {
      return 0;
    }
    portMemCopy(pcVar2 + 0x10,0x17,lVar4 + 0xa8c4,0x17);
    lVar6 = portMemAllocNonPaged(0x1d8);
    *(long *)(pcVar2 + 8) = lVar6;
    uVar7 = 0;
    if (lVar6 == 0) goto LAB_00360c64;
    portMemCopy(lVar6,0x1d8,lVar4 + 0xa8dc,0x1d8);
    cVar3 = *(char *)(lVar4 + 0xa8db);
    pcVar2[0x1410] = cVar3;
    *(char *)(param_2 + 0x205) = cVar3;
    portMemCopy(pcVar2 + 0x28,0x10e4,lVar4 + 0xc21c,0x10e4);
    lVar6 = portMemAllocNonPaged(9);
    *(long *)(pcVar2 + 0x13e8) = lVar6;
    if (lVar6 != 0) {
      portMemCopy(lVar6,9,lVar4 + 0x1493c,9);
      lVar6 = portMemAllocNonPaged(0x7fc);
      *(long *)(pcVar2 + 0x13f0) = lVar6;
      if (lVar6 != 0) {
        portMemCopy(lVar6,0x7fc,lVar4 + 0x14984,0x7fc);
        lVar6 = portMemAllocNonPaged(0x7fc);
        *(long *)(pcVar2 + 0x13f8) = lVar6;
        if (lVar6 != 0) {
          portMemCopy(lVar6,0x7fc,lVar4 + 0x18964,0x7fc);
          lVar6 = portMemAllocNonPaged(0x80);
          *(long *)(pcVar2 + 0x13c8) = lVar6;
          if (lVar6 != 0) {
            portMemCopy(lVar6,0x80,lVar4 + 0xbe1c,0x80);
            lVar6 = portMemAllocNonPaged(0xd0);
            *(long *)(pcVar2 + 0x13e0) = lVar6;
            if (lVar6 != 0) {
              portMemCopy(lVar6,0xd0,lVar4 + 0xb79c,0xd0);
              portMemCopy(pcVar2 + 0x110c,0x2b8,lVar4 + 0x1c944,0x2b8);
              lVar6 = portMemAllocNonPaged(0xc);
              *(long *)(pcVar2 + 0x13d8) = lVar6;
              if (lVar6 != 0) {
                portMemCopy(lVar6,0xc,lVar4 + 0x1e030,0xc);
                lVar6 = portMemAllocNonPaged(0x28);
                *(long *)(pcVar2 + 0x13d0) = lVar6;
                if (lVar6 != 0) {
                  portMemCopy(lVar6,0x28,lVar4 + 0x1e090,0x28);
                  *(undefined4 *)(pcVar2 + 0x1400) = *(undefined4 *)(lVar4 + 0x1df04);
                  lVar6 = portMemAllocNonPaged(0x20);
                  *(long *)(pcVar2 + 0x1408) = lVar6;
                  if (lVar6 != 0) {
                    portMemCopy(lVar6,0x20,lVar4 + 0x1df28,0x20);
                    portMemCopy(pcVar2 + 0x1410,1,lVar4 + 0x1e028,1);
                    *pcVar2 = '\x01';
                    if (((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) &&
                       (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar3 != '\0'))
                    goto LAB_00360c1b;
                    goto LAB_00360950;
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
    if (param_3 == -1) {
      return 0;
    }
    lVar6 = *(long *)(param_1 + 0x1bc0);
    lVar5 = portMemAllocNonPaged(0x1d8);
    *(long *)(pcVar2 + 8) = lVar5;
    uVar7 = 0;
    if (lVar5 == 0) goto LAB_00360c64;
    uVar8 = (ulong)uVar1;
    portMemCopy(lVar5,0x1d8,lVar4 + 0xa8dc + uVar8 * 0x1d8,0x1d8);
    portMemCopy(pcVar2 + 0x28,0x10e4,lVar4 + 0xc21c + uVar8 * 0x10e4,0x10e4);
    portMemCopy(pcVar2 + 0x10,0x17,lVar4 + 0xa8c4,0x17);
    cVar3 = *(char *)(lVar4 + 0xa8db);
    pcVar2[0x1410] = cVar3;
    *(char *)(param_2 + 0x205) = cVar3;
    lVar5 = portMemAllocNonPaged(9);
    *(long *)(pcVar2 + 0x13e8) = lVar5;
    if (lVar5 != 0) {
      portMemCopy(lVar5,9,uVar8 * 9 + 0x1493c + lVar4,9);
      lVar5 = portMemAllocNonPaged(0x7fc);
      *(long *)(pcVar2 + 0x13f8) = lVar5;
      if (lVar5 != 0) {
        portMemCopy(lVar5,0x7fc,lVar4 + 0x18964 + uVar8 * 0x7fc,0x7fc);
        lVar5 = portMemAllocNonPaged(0x80);
        *(long *)(pcVar2 + 0x13c8) = lVar5;
        if (lVar5 != 0) {
          portMemCopy(lVar5,0x80,lVar4 + 0xbe1c + uVar8 * 0x80,0x80);
          portMemCopy(pcVar2 + 0x110c,0x2b8,lVar4 + 0x1c944 + uVar8 * 0x2b8,0x2b8);
          lVar5 = portMemAllocNonPaged(0xd0);
          *(long *)(pcVar2 + 0x13e0) = lVar5;
          if (lVar5 != 0) {
            portMemCopy(lVar5,0xd0,lVar4 + 0xb79c + uVar8 * 0xd0,0xd0);
            if (*(char *)(lVar6 + 0x5380) != '\0') {
              lVar6 = portMemAllocNonPaged(0x28);
              *(long *)(pcVar2 + 0x13d0) = lVar6;
              if (lVar6 == 0) goto LAB_00360c60;
              portMemCopy(lVar6,0x28,lVar4 + 0x1e090 + uVar8 * 0x28,0x28);
            }
            *(undefined4 *)(pcVar2 + 0x1400) = *(undefined4 *)(lVar4 + 0x1df04 + uVar8 * 4);
            lVar6 = portMemAllocNonPaged(0x20);
            *(long *)(pcVar2 + 0x1408) = lVar6;
            if (lVar6 != 0) {
              portMemCopy(lVar6,0x20,lVar4 + 0x1df28 + uVar8 * 0x20,0x20);
              portMemCopy(pcVar2 + 0x1410,1,lVar4 + 0x1e028 + uVar8,1);
              *pcVar2 = '\x01';
              if (((*(long *)(param_1 + 0x1bc0) != 0) &&
                  (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar3 != '\0')) ||
                 (uVar1 != 0)) goto LAB_00360c1b;
LAB_00360950:
              kgrmgrSetLegacyKgraphicsStaticInfo_IMPL
                        (param_1,*(undefined8 *)(param_1 + 0x1bc8),param_2);
LAB_00360c1b:
              if (*(char *)(lVar4 + 0xa7ac) == '\0') {
                *(undefined1 *)(param_2 + 0x1f8) = 0;
                nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x43c,
                             "kgraphicsLoadStaticInfo_VF",2,
                             "NVRM: Profiling support not requested. Disabling ctxsw logging\n");
              }
              return 0;
            }
          }
        }
      }
    }
  }
LAB_00360c60:
  uVar7 = *(undefined8 *)(pcVar2 + 8);
LAB_00360c64:
  portMemFree(uVar7);
  pcVar2[8] = '\0';
  pcVar2[9] = '\0';
  pcVar2[10] = '\0';
  pcVar2[0xb] = '\0';
  pcVar2[0xc] = '\0';
  pcVar2[0xd] = '\0';
  pcVar2[0xe] = '\0';
  pcVar2[0xf] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13c8));
  pcVar2[0x13c8] = '\0';
  pcVar2[0x13c9] = '\0';
  pcVar2[0x13ca] = '\0';
  pcVar2[0x13cb] = '\0';
  pcVar2[0x13cc] = '\0';
  pcVar2[0x13cd] = '\0';
  pcVar2[0x13ce] = '\0';
  pcVar2[0x13cf] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13d0));
  pcVar2[0x13d0] = '\0';
  pcVar2[0x13d1] = '\0';
  pcVar2[0x13d2] = '\0';
  pcVar2[0x13d3] = '\0';
  pcVar2[0x13d4] = '\0';
  pcVar2[0x13d5] = '\0';
  pcVar2[0x13d6] = '\0';
  pcVar2[0x13d7] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13d8));
  pcVar2[0x13d8] = '\0';
  pcVar2[0x13d9] = '\0';
  pcVar2[0x13da] = '\0';
  pcVar2[0x13db] = '\0';
  pcVar2[0x13dc] = '\0';
  pcVar2[0x13dd] = '\0';
  pcVar2[0x13de] = '\0';
  pcVar2[0x13df] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13e0));
  pcVar2[0x13e0] = '\0';
  pcVar2[0x13e1] = '\0';
  pcVar2[0x13e2] = '\0';
  pcVar2[0x13e3] = '\0';
  pcVar2[0x13e4] = '\0';
  pcVar2[0x13e5] = '\0';
  pcVar2[0x13e6] = '\0';
  pcVar2[0x13e7] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13e8));
  pcVar2[0x13e8] = '\0';
  pcVar2[0x13e9] = '\0';
  pcVar2[0x13ea] = '\0';
  pcVar2[0x13eb] = '\0';
  pcVar2[0x13ec] = '\0';
  pcVar2[0x13ed] = '\0';
  pcVar2[0x13ee] = '\0';
  pcVar2[0x13ef] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13f0));
  pcVar2[0x13f0] = '\0';
  pcVar2[0x13f1] = '\0';
  pcVar2[0x13f2] = '\0';
  pcVar2[0x13f3] = '\0';
  pcVar2[0x13f4] = '\0';
  pcVar2[0x13f5] = '\0';
  pcVar2[0x13f6] = '\0';
  pcVar2[0x13f7] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13f8));
  pcVar2[0x13f8] = '\0';
  pcVar2[0x13f9] = '\0';
  pcVar2[0x13fa] = '\0';
  pcVar2[0x13fb] = '\0';
  pcVar2[0x13fc] = '\0';
  pcVar2[0x13fd] = '\0';
  pcVar2[0x13fe] = '\0';
  pcVar2[0x13ff] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x1408));
  pcVar2[0x1408] = '\0';
  pcVar2[0x1409] = '\0';
  pcVar2[0x140a] = '\0';
  pcVar2[0x140b] = '\0';
  pcVar2[0x140c] = '\0';
  pcVar2[0x140d] = '\0';
  pcVar2[0x140e] = '\0';
  pcVar2[0x140f] = '\0';
  return 0x51;
}


// ===== 00360d90 kgraphicsLoadStaticInfo_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgraphicsLoadStaticInfo_KERNEL(long param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  char *pcVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint local_74;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  pcVar2 = *(char **)(param_2 + 0x210);
  local_68 = 0;
  lVar5 = rmapiGetInterface(4);
  if (pcVar2 == (char *)0x0) {
    nvAssertFailedNoLog("pPrivate != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x483);
    return 0x40;
  }
  if (*pcVar2 != '\0') {
    return 0;
  }
  local_74 = *(uint *)(param_2 + 0x20c);
  iVar4 = _kgraphicsInternalClientAlloc(param_1,param_2,param_3,&local_68,&local_64,&local_60);
  if (iVar4 == 0x55) {
    return 0;
  }
  if (iVar4 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/gr/kernel_graphics.c",0x48e);
    return iVar4;
  }
  if (local_68 == 0) {
    nvAssertFailedNoLog("hClient != NV01_NULL_OBJECT","src/kernel/gpu/gr/kernel_graphics.c",0x48f);
    return 0x40;
  }
  lVar6 = portMemAllocNonPaged(0x8720);
  if (lVar6 == 0) {
LAB_003611a8:
    uVar10 = *(undefined8 *)(pcVar2 + 8);
    iVar4 = 0x51;
  }
  else if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
          (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar3 == '\0')) {
LAB_00360e76:
    portMemSet(lVar6,0,0x8720);
    iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a1f,lVar6,0xb8);
    uVar10 = 0x4be;
    pcVar9 = 
    "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KGR_GET_CAPS, pParams, sizeof(pParams->caps))"
    ;
    if (iVar4 != 0) goto LAB_00361090;
    uVar7 = (ulong)local_74;
    lVar1 = lVar6 + uVar7 * 0x17;
    portMemCopy(pcVar2 + 0x10,0x17,lVar1,0x17,0x4be);
    portMemSet(lVar6,0,0x8720);
    iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a2a,lVar6,0xec0);
    if (iVar4 == 0) {
      lVar8 = portMemAllocNonPaged(0x1d8);
      *(long *)(pcVar2 + 8) = lVar8;
      if (lVar8 != 0) {
        portMemCopy(lVar8,0x1d8,uVar7 * 0x1c1 + lVar1,0x1d8);
        goto LAB_00360f52;
      }
      iVar4 = 0x51;
      uVar10 = 0;
      goto LAB_003610a7;
    }
LAB_00360f52:
    portMemSet(lVar6,0,0x8720);
    iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a26,lVar6,0x15c0);
    uVar10 = 0x4e7;
    pcVar9 = 
    "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KGR_GET_FLOORSWEEPING_MASKS, pParams, sizeof(pParams->floorsweepingMasks))"
    ;
    if (iVar4 != 0) goto LAB_00361090;
    lVar1 = lVar1 + uVar7 * 0x2a1;
    portMemCopy(pcVar2 + 0x110c,0x2b8,lVar1,0x2b8,0x4e7);
    if (*(char *)(param_1 + 0x490f) != '\0') {
      *pcVar2 = '\x01';
      lVar1 = *(long *)(param_1 + 0x1bc0);
joined_r0x00361623:
      if (lVar1 != 0) {
        cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
        iVar4 = 0;
        if (cVar3 != '\0') goto LAB_00361000;
      }
LAB_00361050:
      iVar4 = 0;
      if (local_74 == 0) {
        kgrmgrSetLegacyKgraphicsStaticInfo_IMPL(param_1,*(undefined8 *)(param_1 + 0x1bc8),param_2);
        iVar4 = 0;
      }
      goto LAB_00361000;
    }
    portMemSet(lVar6,0,0x8720);
    iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a22,lVar6,0x8720);
    uVar10 = 0x509;
    pcVar9 = 
    "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KGR_GET_GLOBAL_SM_ORDER, pParams, sizeof(pParams->globalSmOrder))"
    ;
    if (iVar4 == 0) {
      lVar1 = lVar1 + uVar7 * 0xe2c;
      portMemCopy(pcVar2 + 0x28,0x10e4,lVar1,0x10e4,0x509);
      portMemSet(lVar6,0,0x8720);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a30,lVar6,0x400);
      if (iVar4 == 0) {
        lVar8 = portMemAllocNonPaged(0x80);
        *(long *)(pcVar2 + 0x13c8) = lVar8;
        if (lVar8 == 0) goto LAB_003611a8;
        portMemCopy(lVar8,0x80,uVar7 * -0x1064 + lVar1,0x80);
      }
      portMemSet(lVar6,0,0x8720);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a2c,lVar6,0x140);
      if (iVar4 == 0) {
        lVar8 = portMemAllocNonPaged(0x28);
        *(long *)(pcVar2 + 0x13d0) = lVar8;
        if (lVar8 == 0) goto LAB_003611a8;
        portMemCopy(lVar8,0x28,uVar7 * -0x10bc + lVar1,0x28);
      }
      else if ((iVar4 == 0x56) && (*(long *)(param_1 + 0x1bc0) != 0)) {
        kmigmgrIsMIGEnabled_IMPL(param_1);
      }
      portMemSet(lVar6,0,0x8720);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a2e,lVar6,0x60);
      if (iVar4 == 0) {
        lVar8 = portMemAllocNonPaged(0xc);
        *(long *)(pcVar2 + 0x13d8) = lVar8;
        if (lVar8 == 0) goto LAB_003611a8;
        portMemCopy(lVar8,0xc,uVar7 * -0x10d8 + lVar1,0xc);
      }
      else if ((iVar4 == 0x56) && (*(long *)(param_1 + 0x1bc0) != 0)) {
        kmigmgrIsMIGEnabled_IMPL(param_1);
      }
      portMemSet(lVar6,0,0x8720);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a34,lVar6,0x48);
      if (iVar4 == 0) {
        lVar8 = portMemAllocNonPaged(9);
        *(long *)(pcVar2 + 0x13e8) = lVar8;
        if (lVar8 == 0) goto LAB_003611a8;
        portMemCopy(lVar8,9,uVar7 * -0x10db + lVar1,9);
      }
      portMemSet(lVar6,0,0x8720);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800b03,lVar6,0x3fe0);
      if (iVar4 == 0) {
        lVar8 = portMemAllocNonPaged(0x7fc);
        *(long *)(pcVar2 + 0x13f0) = lVar8;
        if (lVar8 == 0) goto LAB_003611a8;
        portMemCopy(lVar8,0x7fc,uVar7 * -0x8e8 + lVar1,0x7fc);
      }
      portMemSet(lVar6,0,0x8720);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800b05,lVar6,0x3fe0);
      if (iVar4 == 0) {
        lVar8 = portMemAllocNonPaged(0x7fc);
        *(long *)(pcVar2 + 0x13f8) = lVar8;
        if (lVar8 == 0) goto LAB_003611a8;
        portMemCopy(lVar8,0x7fc,uVar7 * -0x8e8 + lVar1,0x7fc);
      }
      portMemSet(lVar6,0,0x8720);
      iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a3d,lVar6,0x20);
      uVar10 = 0x5be;
      pcVar9 = 
      "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KGR_GET_FECS_RECORD_SIZE, pParams, sizeof(pParams->fecsRecordSize))"
      ;
      if (iVar4 == 0) {
        *(undefined4 *)(pcVar2 + 0x1400) = *(undefined4 *)(lVar6 + uVar7 * 4);
        portMemSet(lVar6,0,0x8720,"src/kernel/gpu/gr/kernel_graphics.c",0x5be);
        iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a3f,lVar6,0x100);
        if (iVar4 == 0) {
          lVar8 = portMemAllocNonPaged(0x20);
          *(long *)(pcVar2 + 0x1408) = lVar8;
          if (lVar8 == 0) goto LAB_003611a8;
          portMemCopy(lVar8,0x20,uVar7 * -0x10c4 + lVar1,0x20);
        }
        portMemSet(lVar6,0,0x8720);
        iVar4 = (**(code **)(lVar5 + 0x38))(lVar5,local_68,local_60,0x20800a48,lVar6,8);
        uVar10 = 0x5e3;
        pcVar9 = 
        "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_KGR_GET_PDB_PROPERTIES, pParams, sizeof(pParams->pdbProperties))"
        ;
        if (iVar4 == 0) {
          portMemCopy(pcVar2 + 0x1410,1,uVar7 * -0x10e3 + lVar1,1,0x5e3);
          *(char *)(param_2 + 0x205) = pcVar2[0x1410];
          *pcVar2 = '\x01';
          if (*(long *)(param_1 + 0x1bc0) != 0) {
            cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
            if ((cVar3 != '\0') || (*(char *)(param_2 + 0x204) == '\0')) goto LAB_003615f8;
LAB_00361619:
            lVar1 = *(long *)(param_1 + 0x1bc0);
            goto joined_r0x00361623;
          }
          if (*(char *)(param_2 + 0x204) == '\0') {
LAB_003615f8:
            iVar4 = kgraphicsInitializeDeferredStaticData_IMPL(param_1,param_2,local_68,local_60);
            if (iVar4 != 0) {
              uVar10 = 0x5f9;
              pcVar9 = 
              "kgraphicsInitializeDeferredStaticData(pGpu, pKernelGraphics, hClient, hSubdevice)";
              goto LAB_00361090;
            }
            goto LAB_00361619;
          }
          goto LAB_00361050;
        }
      }
    }
LAB_00361090:
    nvCheckOkFailedNoLog(4,iVar4,pcVar9,"src/kernel/gpu/gr/kernel_graphics.c",uVar10);
    uVar10 = *(undefined8 *)(pcVar2 + 8);
  }
  else {
    uVar10 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar4 = serverGetClientUnderLock(g_resServ,local_68,&local_58);
    uVar11 = 0x4a0;
    pcVar9 = "serverGetClientUnderLock(&g_resServ, hClient, &pClient)";
    if (iVar4 == 0) {
      iVar4 = deviceGetByHandle_IMPL
                        (local_58,local_64,&local_50,"src/kernel/gpu/gr/kernel_graphics.c",0x4a0);
      if (iVar4 != 0) {
        uVar11 = 0x4a6;
        pcVar9 = "deviceGetByHandle(pClient, hDevice, &pDevice)";
        goto LAB_00361859;
      }
      iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar10,local_50,&local_48);
      uVar11 = 0x4ad;
      pcVar9 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
      if (iVar4 != 0) goto LAB_00361859;
      iVar4 = kmigmgrGetGlobalToLocalEngineType_IMPL
                        (param_1,uVar10,local_48,local_40,local_74 + 1,&local_5c);
      local_74 = local_5c - 1;
      if (iVar4 == 0) goto LAB_00360e76;
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(grIdx), &localRmEngineType)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x4b2);
    }
    else {
LAB_00361859:
      nvCheckOkFailedNoLog(4,iVar4,pcVar9,"src/kernel/gpu/gr/kernel_graphics.c",uVar11);
    }
    uVar10 = *(undefined8 *)(pcVar2 + 8);
  }
LAB_003610a7:
  *pcVar2 = '\0';
  portMemFree(uVar10);
  pcVar2[8] = '\0';
  pcVar2[9] = '\0';
  pcVar2[10] = '\0';
  pcVar2[0xb] = '\0';
  pcVar2[0xc] = '\0';
  pcVar2[0xd] = '\0';
  pcVar2[0xe] = '\0';
  pcVar2[0xf] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13c8));
  pcVar2[0x13c8] = '\0';
  pcVar2[0x13c9] = '\0';
  pcVar2[0x13ca] = '\0';
  pcVar2[0x13cb] = '\0';
  pcVar2[0x13cc] = '\0';
  pcVar2[0x13cd] = '\0';
  pcVar2[0x13ce] = '\0';
  pcVar2[0x13cf] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13d0));
  pcVar2[0x13d0] = '\0';
  pcVar2[0x13d1] = '\0';
  pcVar2[0x13d2] = '\0';
  pcVar2[0x13d3] = '\0';
  pcVar2[0x13d4] = '\0';
  pcVar2[0x13d5] = '\0';
  pcVar2[0x13d6] = '\0';
  pcVar2[0x13d7] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13d8));
  pcVar2[0x13d8] = '\0';
  pcVar2[0x13d9] = '\0';
  pcVar2[0x13da] = '\0';
  pcVar2[0x13db] = '\0';
  pcVar2[0x13dc] = '\0';
  pcVar2[0x13dd] = '\0';
  pcVar2[0x13de] = '\0';
  pcVar2[0x13df] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13e0));
  pcVar2[0x13e0] = '\0';
  pcVar2[0x13e1] = '\0';
  pcVar2[0x13e2] = '\0';
  pcVar2[0x13e3] = '\0';
  pcVar2[0x13e4] = '\0';
  pcVar2[0x13e5] = '\0';
  pcVar2[0x13e6] = '\0';
  pcVar2[0x13e7] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13e8));
  pcVar2[0x13e8] = '\0';
  pcVar2[0x13e9] = '\0';
  pcVar2[0x13ea] = '\0';
  pcVar2[0x13eb] = '\0';
  pcVar2[0x13ec] = '\0';
  pcVar2[0x13ed] = '\0';
  pcVar2[0x13ee] = '\0';
  pcVar2[0x13ef] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13f0));
  pcVar2[0x13f0] = '\0';
  pcVar2[0x13f1] = '\0';
  pcVar2[0x13f2] = '\0';
  pcVar2[0x13f3] = '\0';
  pcVar2[0x13f4] = '\0';
  pcVar2[0x13f5] = '\0';
  pcVar2[0x13f6] = '\0';
  pcVar2[0x13f7] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x13f8));
  pcVar2[0x13f8] = '\0';
  pcVar2[0x13f9] = '\0';
  pcVar2[0x13fa] = '\0';
  pcVar2[0x13fb] = '\0';
  pcVar2[0x13fc] = '\0';
  pcVar2[0x13fd] = '\0';
  pcVar2[0x13fe] = '\0';
  pcVar2[0x13ff] = '\0';
  portMemFree(*(undefined8 *)(pcVar2 + 0x1408));
  pcVar2[0x1408] = '\0';
  pcVar2[0x1409] = '\0';
  pcVar2[0x140a] = '\0';
  pcVar2[0x140b] = '\0';
  pcVar2[0x140c] = '\0';
  pcVar2[0x140d] = '\0';
  pcVar2[0x140e] = '\0';
  pcVar2[0x140f] = '\0';
LAB_00361000:
  if (local_68 != 0) {
    (**(code **)(lVar5 + 0x18))(lVar5,local_68,local_68);
  }
  portMemFree(lVar6);
  return iVar4;
}


// ===== 00361880 kgraphicsIsGFXSupported_IMPL =====

undefined4 kgraphicsIsGFXSupported_IMPL(undefined8 param_1,long param_2)

{
  char *pcVar1;
  uint uVar2;
  
  pcVar1 = *(char **)(param_2 + 0x210);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                        0x642);
  }
  else {
    if (*(long *)(pcVar1 + 8) != 0) {
      uVar2 = ~*(uint *)(*(long *)(pcVar1 + 8) + 0x1a4);
      return CONCAT31((int3)(uVar2 >> 8),(uVar2 & 0xb) == 0);
    }
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pGrInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics.c",0x643);
  }
  return 0;
}


// ===== 00361900 kgraphicsGetCtxBufferInfo_IMPL =====

long kgraphicsGetCtxBufferInfo_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (param_3 < 10) {
    return param_2 + 0x430 + (ulong)param_3 * 0x18;
  }
  nvAssertFailedNoLog("NV_ENUM_IS(GR_CTX_BUFFER, buf)","src/kernel/gpu/gr/kernel_graphics.c",0x655);
  return 0;
}


// ===== 00361940 kgraphicsClearCtxBufferInfo_IMPL =====

void kgraphicsClearCtxBufferInfo_IMPL(undefined8 param_1,long param_2)

{
  portMemSet(param_2 + 0x430,0,0xf0);
  return;
}


// ===== 00361960 kgraphicsInitCtxBufPool_IMPL =====

void kgraphicsInitCtxBufPool_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  ctxBufPoolInit(param_1,param_3,param_2 + 0x428);
  return;
}


// ===== 00361980 kgraphicsGetCtxBufPool_IMPL =====

undefined8 kgraphicsGetCtxBufPool_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined8 *)(param_2 + 0x428);
}


// ===== 00361990 kgraphicsDestroyCtxBufPool_IMPL =====

void kgraphicsDestroyCtxBufPool_IMPL(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x428) != 0) {
    ctxBufPoolRelease();
    ctxBufPoolDestroy(param_2 + 0x428);
    *(undefined8 *)(param_2 + 0x428) = 0;
    return;
  }
  return;
}


// ===== 003619e0 kgraphicsGetGlobalCtxBuffers_IMPL =====

long kgraphicsGetGlobalCtxBuffers_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x230);
  if (lVar1 != 0) {
    lVar1 = (ulong)param_3 * 0x60 + lVar1;
  }
  return lVar1;
}


// ===== 00361a00 kgraphicsIsGlobalCtxBufferSizeAligned_IMPL =====

undefined1 kgraphicsIsGlobalCtxBufferSizeAligned_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (param_3 < 10) {
    return *(undefined1 *)(param_2 + 0x238 + (ulong)param_3);
  }
  nvAssertFailedNoLog("NV_ENUM_IS(GR_GLOBALCTX_BUFFER, buf)","src/kernel/gpu/gr/kernel_graphics.c",
                      0x6b9);
  return 0;
}


// ===== 00361a40 kgraphicsGetMainCtxBufferSize_IMPL =====

undefined8
kgraphicsGetMainCtxBufferSize_IMPL(undefined8 param_1,long param_2,char param_3,int *param_4)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = *(char **)(param_2 + 0x210);
  if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                        0x6dc);
  }
  else if (*(long *)(pcVar1 + 8) == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pGrInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics.c",0x6dd);
  }
  else {
    if (*(int **)(pcVar1 + 0x13e0) != (int *)0x0) {
      iVar2 = **(int **)(pcVar1 + 0x13e0);
      if ((param_3 != '\0') && (*(char *)(param_2 + 0x205) != '\0')) {
        iVar2 = (iVar2 + 0xfffU & 0xfffff000) + *(int *)(*(long *)(pcVar1 + 8) + 0x164) * 0x1000;
      }
      *param_4 = iVar2;
      return 0;
    }
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics.c",0x6de);
  }
  return 0x40;
}


// ===== 00361b00 kgraphicsMapCtxBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgraphicsMapCtxBuffer_IMPL
              (long param_1,long param_2,undefined8 param_3,undefined8 param_4,int *param_5,
              char param_6,char param_7)

{
  char cVar1;
  int iVar2;
  long *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  uint uVar8;
  long *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_60 = 0;
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x78c,"kgraphicsMapCtxBuffer_IMPL",1,
               "NVRM: gpu:%d isBC=%d\n",*(undefined4 *)(param_1 + 0x7a4),0);
  plVar3 = (long *)__nvoc_dynamicCast(param_4,__nvoc_class_def_OBJGVASPACE);
  cVar1 = (**(code **)(*plVar3 + 0x188))(plVar3);
  if (cVar1 != '\0') {
    nvAssertFailedNoLog("!gvaspaceIsExternallyOwned(pGVAS)","src/kernel/gpu/gr/kernel_graphics.c",
                        0x790);
    return 0x38;
  }
  iVar2 = vaListFindVa(param_5,param_4,&local_60);
  if (iVar2 != 0x57) goto joined_r0x00361c7d;
  uVar8 = (uint)(param_6 != '\0') << 9;
  if ((*(byte *)(plVar3 + 0x17) & 8) != 0) {
    uVar8 = uVar8 | 0x400;
  }
  if (*(char *)(param_2 + 0x205) == '\0') {
    iVar2 = vaListMapCount(param_5);
    if (iVar2 == 0) {
      lVar7 = *(long *)(param_1 + 0x1bb8);
      pcVar4 = *(code **)(lVar7 + 0x1a8);
      goto LAB_00361c24;
    }
    local_60 = 0;
    if (*param_5 == 0) {
      if (*(long *)(param_5 + 4) == 0) {
        local_60 = *(long *)(param_5 + 0xc);
      }
      else {
        local_60 = *(long *)(param_5 + 6);
      }
    }
    else {
      uVar5 = mapFindLEQ_IMPL(param_5 + 2,0xffffffffffffffff);
      uVar6 = mapFindGEQ_IMPL(param_5 + 2,0);
      mapIterRange_IMPL(&local_88,param_5 + 2,uVar6,uVar5);
      local_58 = local_88;
      local_50 = local_80;
      local_48 = local_78;
      local_40 = local_70;
      cVar1 = mapIterNext_IMPL(&local_58);
      if (((cVar1 != '\0') && (cVar1 = mapIterNext_IMPL(&local_58), cVar1 != '\0')) &&
         (local_58 != (long *)0x0)) {
        local_60 = *local_58;
        mapKey_IMPL(param_5 + 2);
      }
    }
    if (param_6 != '\0') {
      nvAssertFailedNoLog("!bAlignSize","src/kernel/gpu/gr/kernel_graphics.c",0x7c9);
    }
    lVar7 = local_60;
    iVar2 = (**(code **)(*(long *)(param_1 + 0x1bb8) + 0x168))
                      (param_1,*(long *)(param_1 + 0x1bb8),param_4,param_3,&local_60,
                       (-(uint)(param_7 == '\0') & 0xffffffbf) + 0x8041,0,0,0xffffffffffffffff);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "dmaAllocMapping_HAL(pGpu, GPU_GET_DMA(pGpu), pVAS, pMemDesc, &vaddr, mapFlags, 0, NULL, KMIGMGR_SWIZZID_INVALID)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x7cb);
    }
    if (local_60 != lVar7) {
      nvAssertFailedNoLog("vaddr == vaddrCached","src/kernel/gpu/gr/kernel_graphics.c",0x7d3);
      lVar7 = local_60;
    }
  }
  else {
    lVar7 = *(long *)(param_1 + 0x1bb8);
    pcVar4 = *(code **)(lVar7 + 0x1a8);
LAB_00361c24:
    iVar2 = (*pcVar4)(param_1,lVar7,param_4,param_3,&local_60,uVar8,
                      -(uint)(param_7 != '\0') & 0x88000000);
    lVar7 = local_60;
  }
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x7d7,"kgraphicsMapCtxBuffer_IMPL",1,
               "NVRM: New ctx buffer mapping at VA 0x%llx\n",lVar7);
joined_r0x00361c7d:
  if ((iVar2 == 0) && (iVar2 = vaListAddVa(param_5,param_4,local_60), iVar2 != 0)) {
    nvAssertOkFailedNoLog
              (iVar2,"vaListAddVa(pVaList, pVAS, vaddr)","src/kernel/gpu/gr/kernel_graphics.c",0x7db
              );
  }
  return iVar2;
}


// ===== 00361efc kgraphicsAllocKgraphicsBuffers_KERNEL.cold =====

void kgraphicsAllocKgraphicsBuffers_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00361f10 kgraphicsAllocKgraphicsBuffers_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgraphicsAllocKgraphicsBuffers_KERNEL
                (long param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char *pcVar3;
  code *pcVar4;
  char cVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  long lVar14;
  undefined8 uVar15;
  uint local_4c;
  long local_48;
  undefined8 local_40 [2];
  
  if (param_4 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x700);
    return 0x21;
  }
  plVar10 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_4 + 0x2a0),__nvoc_class_def_OBJGVASPACE
                                      );
  uVar7 = kchannelGetGfid_IMPL(param_4);
  if ((*(char *)(param_1 + 0x908) == '\0') &&
     (uVar9 = kgraphicsInitializeDeferredStaticData_IMPL(param_1,param_2,0,0), uVar9 != 0)) {
    nvCheckOkFailedNoLog
              (4,uVar9,
               "kgraphicsInitializeDeferredStaticData(pGpu, pKernelGraphics, NV01_NULL_OBJECT, NV01_NULL_OBJECT)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0x707);
    return (ulong)uVar9;
  }
  lVar11 = *(long *)(param_2 + 0x230);
  if (lVar11 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar14 = (ulong)uVar7 * 0x60;
  if (*(long *)(lVar11 + 0x30 + lVar14) == 0) {
    uVar13 = (**(code **)(param_2 + 0x1a8))(param_1,param_2,(ulong)uVar7);
    if ((int)uVar13 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar13 & 0xffffffff,
                 "kgraphicsAllocGlobalCtxBuffers_HAL(pGpu, pKernelGraphics, gfid)",
                 "src/kernel/gpu/gr/kernel_graphics.c",0x711);
      return uVar13 & 0xffffffff;
    }
    if (*(char *)(param_2 + 0x1f8) == '\0') {
      return uVar13;
    }
    lVar11 = *(long *)(param_2 + 0x230);
    if (lVar11 == 0) {
      uVar13 = kgraphicsAllocKgraphicsBuffers_KERNEL_cold();
      return uVar13;
    }
  }
  else if (*(char *)(param_2 + 0x1f8) == '\0') {
    return 0;
  }
  if (*(long *)(lVar11 + 0x30 + lVar14) != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x1bc8);
    cVar5 = (**(code **)(*plVar10 + 0x188))(plVar10);
    if ((cVar5 == '\0') &&
       ((*(char *)(param_1 + 0x908) == '\0' || (*(char *)(param_1 + 0x4913) != '\0')))) {
      local_40[0] = 0;
      uVar2 = *(undefined8 *)(param_4 + 0x2a0);
      uVar15 = 0x362015;
      iVar8 = kgrctxGetUnicast_IMPL(param_1,param_3,&local_48);
      if (iVar8 == 0) {
        lVar11 = *(long *)(*(long *)(param_2 + 0x230) + 0x30 + lVar14);
        if (lVar11 == 0) {
          pcVar3 = *(char **)(param_2 + 0x210);
          if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
            nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                                "src/kernel/gpu/gr/kernel_graphics.c",0x750);
          }
          else if (*(long *)(pcVar3 + 0x13e0) == 0) {
            nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                                "src/kernel/gpu/gr/kernel_graphics.c",0x751);
          }
          else {
            iVar8 = kgrctxGlobalCtxBufferToFifoEngineId_IMPL(6,&local_4c);
            if (iVar8 == 0) {
              if (*(int *)(*(long *)(pcVar3 + 0x13e0) + (ulong)local_4c * 8) == 0) {
                nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x757,
                             "_kgraphicsMapGlobalCtxBuffer",1,
                             "NVRM: Could not map %s Buffer as buffer is not supported\n",
                             "GR_GLOBALCTX_BUFFER_FECS_EVENT");
              }
              else {
                nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x75e,
                             "_kgraphicsMapGlobalCtxBuffer",4,
                             "NVRM: Could not map %s Buffer, no memory allocated for it!\n",
                             "GR_GLOBALCTX_BUFFER_FECS_EVENT");
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar8,"kgrctxGlobalCtxBufferToFifoEngineId(buffId, &fifoEngineId)",
                         "src/kernel/gpu/gr/kernel_graphics.c",0x753);
            }
          }
        }
        else {
          iVar8 = kgraphicsMapCtxBuffer_IMPL
                            (param_1,param_2,lVar11,uVar2,local_48 + 0x2d8,
                             *(undefined1 *)(param_2 + 0x23e),0);
          if (iVar8 == 0) {
            iVar8 = vaListFindVa(local_48 + 0x2d8,uVar2,local_40,uVar15);
            if (iVar8 != 0) {
              nvAssertOkFailedNoLog
                        (iVar8,
                         "vaListFindVa(&pKernelGraphicsContextUnicast->globalCtxBufferVaList[buffId], pVAS, &vaddr)"
                         ,"src/kernel/gpu/gr/kernel_graphics.c",0x76c);
            }
            uVar15 = local_40[0];
            uVar2 = *(undefined8 *)(lVar11 + 0x30);
            uVar12 = memdescGetMemDescFromGpu(lVar11,param_1);
            uVar12 = memdescGetPhysAddr(uVar12,1,0);
            nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x76e,"_kgraphicsMapGlobalCtxBuffer",
                         1,"NVRM: GPU:%d %s Buffer PA @ 0x%llx VA @ 0x%llx of Size 0x%llx\n",
                         *(undefined4 *)(param_1 + 0x7a4),"GR_GLOBALCTX_BUFFER_FECS_EVENT",uVar12,
                         uVar15,uVar2);
          }
          else {
            nvCheckOkFailedNoLog
                      (4,iVar8,
                       "kgraphicsMapCtxBuffer(pGpu, pKernelGraphics, pMemDesc, pVAS, &pKernelGraphicsContextUnicast->globalCtxBufferVaList[buffId], bSizeAligned, bIsReadOnly)"
                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x766);
          }
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
                   "src/kernel/gpu/gr/kernel_graphics.c",0x743);
      }
    }
    cVar5 = fecsBufferIsMapped(param_1,param_2);
    if (cVar5 == '\0') {
      fecsBufferMap(param_1,param_2);
    }
    sVar6 = fecsGetCtxswLogConsumerCount(param_1,uVar1);
    if (0 < sVar6) {
      fecsBufferReset(param_1,param_2);
    }
  }
  return 0;
}


// ===== 003623c0 kgraphicsUnmapCtxBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsUnmapCtxBuffer_IMPL
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uStack_40;
  undefined8 local_30 [2];
  
  local_30[0] = 0;
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x7f1,"kgraphicsUnmapCtxBuffer_IMPL",1,
               "NVRM: gpu:%d isBC=%d\n",*(undefined4 *)(param_1 + 0x7a4));
  iVar2 = vaListFindVa(param_4,param_3,local_30);
  if (iVar2 == 0) {
    iVar2 = vaListRemoveVa(param_4,param_3,0,uStack_40);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"vaListRemoveVa(pVaList, pVAS)","src/kernel/gpu/gr/kernel_graphics.c",0x7f7);
    }
    iVar2 = vaListFindVa(param_4,param_3,local_30);
    if (iVar2 == 0) {
      return;
    }
    if (iVar2 == 0x57) {
      cVar1 = vaListGetManaged(param_4);
      if (cVar1 != '\0') {
        (**(code **)(*(long *)(param_1 + 0x1bb8) + 0x1b0))
                  (param_1,*(long *)(param_1 + 0x1bb8),param_3,local_30[0]);
      }
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x803,"kgraphicsUnmapCtxBuffer_IMPL",1,
                   "NVRM: Freed ctx buffer mapping at VA 0x%llx\n",local_30[0]);
    }
    else {
      nvAssertFailedNoLog("(NV_OK == status) || (NV_ERR_OBJECT_NOT_FOUND == status)",
                          "src/kernel/gpu/gr/kernel_graphics.c",0x7fb);
    }
  }
  return;
}


// ===== 00362510 kgraphicsGetClassByType_IMPL =====

int kgraphicsGetClassByType_IMPL(undefined8 param_1,long param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ulong extraout_RDX;
  long lVar5;
  uint local_40;
  uint local_3c [3];
  
  *param_4 = 0;
  if (param_3 < 4) {
    iVar1 = gpuGetClassList_IMPL(param_1,local_3c,0,*(uint *)(param_2 + 0x20c) | 0xd334df00);
    if (iVar1 == 0) {
      lVar3 = portMemAllocNonPaged((ulong)local_3c[0] << 2);
      if (lVar3 == 0) {
        nvCheckFailedNoLog(4,"pClassesSupported != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x82e
                          );
        iVar1 = 0x51;
      }
      else {
        iVar2 = gpuGetClassList_IMPL(param_1,local_3c,lVar3,*(uint *)(param_2 + 0x20c) | 0xd334df00)
        ;
        if ((iVar2 == 0) && (local_3c[0] != 0)) {
          lVar5 = 0;
          uVar4 = extraout_RDX;
          do {
            kgrmgrGetGrObjectType_IMPL(*(undefined4 *)(lVar3 + lVar5 * 4),&local_40,uVar4);
            uVar4 = (ulong)local_40;
            nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x838,"kgraphicsGetClassByType_IMPL",
                         1,"NVRM: classNum=0x%08x, type=%d\n",*(undefined4 *)(lVar3 + lVar5 * 4));
            if (local_40 == param_3) {
              *param_4 = *(int *)(lVar3 + lVar5 * 4);
            }
            lVar5 = lVar5 + 1;
          } while ((uint)lVar5 < local_3c[0]);
        }
        portMemFree(lVar3);
        if (*param_4 == 0) {
          iVar1 = 0x22;
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,"gpuGetClassList(pGpu, &numClasses, NULL, ENG_GR(pKernelGraphics->instance))"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x82a);
    }
    return iVar1;
  }
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x824,"kgraphicsGetClassByType_IMPL",4,
               "NVRM: bad requested object type : %d\n",param_3);
  return 0x1f;
}


// ===== 003626f0 kgraphicsGetContextBufferAttr_IMPL =====

long kgraphicsGetContextBufferAttr_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (param_3 < 10) {
    return param_2 + ((ulong)param_3 + 0x52) * 0x10;
  }
  nvAssertFailedNoLog("NV_ENUM_IS(GR_CTX_BUFFER, buf)","src/kernel/gpu/gr/kernel_graphics.c",0x850);
  return 0;
}


// ===== 00362730 __pfx_kgraphicsCreateGoldenImageChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int __pfx_kgraphicsCreateGoldenImageChannel_IMPL(long param_1,long param_2)

{
  uint *puVar1;
  char *pcVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  undefined8 *puVar11;
  long lVar12;
  uint *puVar13;
  long lVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  undefined8 uStack_70;
  long lStack_68;
  long lStack_60;
  ulong uStack_58;
  undefined8 uStack_50;
  long lStack_48;
  ulong uStack_40;
  
  uStack_80 = 0;
  lVar9 = rmapiGetInterface(4);
  uVar17 = *(undefined8 *)(param_1 + 0x1bc0);
  lVar10 = gpumgrGetParentGPU(param_1);
  if (param_1 != lVar10) {
    return 0;
  }
  iVar6 = rmapiutilAllocClientAndDeviceHandles(lVar9,param_1,&uStack_80,&uStack_7c,&uStack_78);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,
               "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &hClientId, &hDeviceId, &hSubdeviceId)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0x87f);
    return iVar6;
  }
  iVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar7 = serverGetClientUnderLock(g_resServ,uStack_80,&uStack_70);
  if (iVar7 != 0) {
    nvAssertOkFailedNoLog
              (iVar7,"serverGetClientUnderLock(&g_resServ, hClientId, &pClientId)",
               "src/kernel/gpu/gr/kernel_graphics.c",0x884);
    return iVar7;
  }
  lVar10 = portMemAllocNonPaged(0x38);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pVaParams != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x88c);
  }
  else {
    puVar11 = (undefined8 *)portMemAllocNonPaged(0x80);
    if (puVar11 == (undefined8 *)0x0) {
      nvAssertFailedNoLog("pMemAllocParams != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x891);
      portMemFree(lVar10);
    }
    else {
      lVar12 = portMemAllocNonPaged(0x170);
      if (lVar12 != 0) {
        if (*(long *)(param_1 + 0x1bc0) == 0) {
          iVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
          bVar3 = false;
          if (iVar6 != iVar7) goto LAB_003628aa;
LAB_00363120:
          bVar3 = false;
LAB_00362a8a:
          cVar5 = rmapiLockIsOwner();
          if (cVar5 == '\0') {
            cVar5 = rmapiInRtd3PmPath();
            if (cVar5 == '\0') {
              iVar6 = 0x2f;
              nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x8f4,
                           "kgraphicsCreateGoldenImageChannel_IMPL",4,
                           "NVRM: Caller missing proper locks\n");
              portMemFree(lVar10);
              goto LAB_00362a3c;
            }
            lVar9 = rmapiGetInterface(4);
            bVar4 = false;
          }
          else {
            rmGpuLocksRelease(0,0);
            lVar9 = rmapiGetInterface(3);
            bVar4 = true;
          }
          portMemSet(lVar10,0,0x38);
          *(uint *)(lVar10 + 4) = *(uint *)(lVar10 + 4) | 0x2000;
          iVar7 = (**(code **)(lVar9 + 8))(lVar9,uStack_80,uStack_7c,0xbaba0042,0x90f1,lVar10,0x38);
          if (iVar7 == 0) {
            portMemSet(puVar11,0,0x80);
            *(uint *)((long)puVar11 + 0x1c) = *(uint *)((long)puVar11 + 0x1c) | 0x4000000;
            *puVar11 = 0xdeaf0006;
            puVar11[8] = 0x100;
            *(undefined4 *)(puVar11 + 3) = 0x2000000;
            *(undefined4 *)((long)puVar11 + 0x6c) = 0;
            iVar7 = (**(code **)(lVar9 + 8))(lVar9,uStack_80,uStack_7c,0xbaba0044,0x3e,puVar11,0x80)
            ;
            if (iVar7 == 0) {
              portMemSet(puVar11,0,0x80);
              puVar11[8] = 0x100;
              *puVar11 = 0xdeaf0006;
              *(undefined4 *)(puVar11 + 3) = 0x2000000;
              *(undefined4 *)(puVar11 + 1) = 0x80000;
              *(undefined4 *)((long)puVar11 + 0x6c) = 0xbaba0042;
              iVar7 = (**(code **)(lVar9 + 8))
                                (lVar9,uStack_80,uStack_7c,0xbaba0043,0x50a0,puVar11,0x80);
              if (iVar7 == 0) {
                cVar5 = gpuIsClassSupported_IMPL(param_1,0xc36f);
                if ((((cVar5 == '\0') &&
                     (cVar5 = gpuIsClassSupported_IMPL(param_1,0xc46f), cVar5 == '\0')) &&
                    (cVar5 = gpuIsClassSupported_IMPL(param_1,0xc56f), cVar5 == '\0')) &&
                   (((cVar5 = gpuIsClassSupported_IMPL(param_1,0xc86f), cVar5 == '\0' &&
                     (cVar5 = gpuIsClassSupported_IMPL(param_1,0xc96f), cVar5 == '\0')) &&
                    (cVar5 = gpuIsClassSupported_IMPL(param_1,0xca6f), cVar5 == '\0')))) {
                  iVar7 = 0x56;
                }
                else {
                  portMemSet(puVar11,0,0x80);
                  puVar11[8] = 0x200;
                  *puVar11 = 0xdeaf0006;
                  if (((*(ushort *)(param_1 + 0x4926) & 3) == 3) ||
                     ((*(ushort *)(param_1 + 0x4926) & 3) == 0)) {
                    *(undefined4 *)(puVar11 + 1) = 4;
                    uVar15 = 0x40;
                    puVar11[3] = 0x400000000000;
                  }
                  else {
                    *(undefined4 *)(puVar11 + 3) = 0x2000000;
                    uVar15 = 0x3e;
                  }
                  cVar5 = gpuIsApmFeatureEnabled_IMPL(param_1);
                  if ((cVar5 != '\0') || ((*(uint *)(puVar11 + 3) & 0x6000000) == 0x2000000)) {
                    *(uint *)((long)puVar11 + 0x1c) = *(uint *)((long)puVar11 + 0x1c) | 0x4000000;
                  }
                  *(uint *)(puVar11 + 3) = *(uint *)(puVar11 + 3) | 0x4000;
                  uVar16 = 0x80;
                  iVar7 = (**(code **)(lVar9 + 8))
                                    (lVar9,uStack_80,uStack_7c,0xbaba0049,uVar15,puVar11);
                  if (iVar7 == 0) {
                    uVar15 = gpuGetKernelFifoShared_IMPL(param_1);
                    iVar6 = kfifoGetChannelClassId_IMPL(param_1,uVar15);
                    iStack_74 = iVar6;
                    if (iVar6 == 0) {
                      nvAssertFailedNoLog("classNum != 0","src/kernel/gpu/gr/kernel_graphics.c",
                                          0x977);
                      iVar7 = 0;
                    }
                    else {
                      portMemSet(lVar12,0,0x170);
                      *(undefined8 *)(lVar12 + 4) = 0xbaba0043;
                      *(undefined8 *)(lVar12 + 0xc) = 0x2000000000;
                      *(undefined8 *)(lVar12 + 0x1c) = 0xbaba0049baba0042;
                      if (bVar3) {
                        iVar7 = deviceGetByHandle_IMPL(uStack_70,uStack_7c,&lStack_48);
                        if (iVar7 == 0) {
                          iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL
                                            (param_1,uVar17,lStack_48,&lStack_68);
                          if (iVar7 == 0) {
                            iVar7 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                              (param_1,uVar17,lStack_68,lStack_60,
                                               *(int *)(param_2 + 0x20c) + 1,&uStack_58);
                            if (iVar7 == 0) {
                              uVar8 = gpuGetNv2080EngineType_IMPL(uStack_58 & 0xffffffff);
                              *(undefined4 *)(lVar12 + 0x80) = uVar8;
                              goto LAB_00362ecd;
                            }
                            nvAssertOkFailedNoLog
                                      (iVar7,
                                       "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &localRmEngineType)"
                                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x993);
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar7,
                                       "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)"
                                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x98f);
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar7,"deviceGetByHandle(pClientId, hDeviceId, &pDevice)",
                                     "src/kernel/gpu/gr/kernel_graphics.c",0x98b);
                        }
                      }
                      else {
                        uVar8 = gpuGetNv2080EngineType_IMPL(1);
                        *(undefined4 *)(lVar12 + 0x80) = uVar8;
LAB_00362ecd:
                        uVar17 = 0x170;
                        iVar7 = (**(code **)(lVar9 + 8))
                                          (lVar9,uStack_80,uStack_7c,0xbaba0045,iVar6,lVar12);
                        if (iVar7 == 0) {
                          if (*(char *)(param_1 + 0x909) == '\0') {
LAB_00362fd4:
                            iVar7 = rmGpuLocksAcquire(0,0x80001);
                            if (iVar7 == 0) {
                              lVar9 = rmapiGetInterface(4);
                              cVar5 = kgraphicsIsGFXSupported_IMPL(param_1,param_2);
                              uVar8 = 0;
                              if (cVar5 == '\0') {
                                uVar8 = 3;
                              }
                              iVar6 = kgraphicsGetClassByType_IMPL(param_1,param_2,uVar8,&iStack_74)
                              ;
                              if (iVar6 == 0) {
                                if (iStack_74 != 0) {
                                  iVar7 = (**(code **)(lVar9 + 8))
                                                    (lVar9,uStack_80,0xbaba0045,0xbaba0046,iStack_74
                                                     ,0,0);
                                  if (iVar7 != 0) {
                                    nvAssertOkFailedNoLog
                                              (iVar7,
                                               "pRmApi->AllocWithHandle(pRmApi, hClientId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, KGRAPHICS_CHANNEL_HANDLE_3DOBJ, classNum, NULL, 0)"
                                               ,"src/kernel/gpu/gr/kernel_graphics.c",0x9e0);
                                  }
                                  goto LAB_00362a30;
                                }
                                nvAssertFailedNoLog("classNum != 0",
                                                    "src/kernel/gpu/gr/kernel_graphics.c",0x9dd);
                                portMemFree(lVar10);
                                iVar6 = 0;
                              }
                              else {
                                nvAssertOkFailedNoLog
                                          (iVar6,
                                           "kgraphicsGetClassByType(pGpu, pKernelGraphics, objectType, &classNum)"
                                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x9da);
                                portMemFree(lVar10);
                              }
                              goto LAB_00362a3c;
                            }
                            nvAssertOkFailedNoLog
                                      (iVar7,
                                       "rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GR)"
                                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x9ca);
                          }
                          else {
                            pcVar2 = *(char **)(param_2 + 0x210);
                            if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
                              iVar6 = CliGetKernelChannel(uStack_70,0xbaba0045,&lStack_48,uVar17);
                              if (iVar6 != 0) {
                                nvAssertOkFailedNoLog
                                          (iVar6,
                                           "CliGetKernelChannel(pClientId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, &pKernelChannel)"
                                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x9b2);
                              }
                              nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                                                  "src/kernel/gpu/gr/kernel_graphics.c",0x9b4);
                            }
                            else {
                              iVar6 = CliGetKernelChannel(uStack_70,0xbaba0045,&lStack_48,uVar17);
                              if (iVar6 != 0) {
                                nvAssertOkFailedNoLog
                                          (iVar6,
                                           "CliGetKernelChannel(pClientId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, &pKernelChannel)"
                                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x9b2);
                              }
                              puVar13 = *(uint **)(pcVar2 + 0x13e0);
                              lVar14 = 0;
                              puVar1 = puVar13 + 0x34;
                              if (puVar13 != (uint *)0x0) {
                                do {
                                  if (*puVar13 != 0xffffffff) {
                                    lVar14 = (ulong)*puVar13 + lVar14;
                                  }
                                  puVar13 = puVar13 + 2;
                                } while (puVar1 != puVar13);
                                iVar6 = (**(code **)(**(long **)(lStack_48 + 0x2a0) + 0x88))
                                                  (*(long **)(lStack_48 + 0x2a0),param_1,
                                                   *(undefined8 *)
                                                    (*(long *)(lStack_48 + 0x158) + 0xe8),lVar14,
                                                   0x1000,0);
                                if (iVar6 != 0) {
                                  nvAssertOkFailedNoLog
                                            (iVar6,
                                             "vaspaceReserveMempool(pKernelChannel->pVAS, pGpu, GPU_RES_GET_DEVICE(pKernelChannel), reserveSize, RM_PAGE_SIZE, VASPACE_RESERVE_FLAGS_NONE)"
                                             ,"src/kernel/gpu/gr/kernel_graphics.c",0x9c2);
                                }
                                goto LAB_00362fd4;
                              }
                              nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL"
                                                  ,"src/kernel/gpu/gr/kernel_graphics.c",0x9b7,0);
                            }
                            iVar7 = 0x40;
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar7,
                                     "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, classNum, pChannelGPFIFOAllocParams, sizeof(NV_CHANNEL_ALLOC_PARAMS))"
                                     ,"src/kernel/gpu/gr/kernel_graphics.c",0x99f);
                        }
                      }
                    }
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar7,
                               "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_USERD, userdMemClass, pMemAllocParams, sizeof(NV_MEMORY_ALLOCATION_PARAMS))"
                               ,"src/kernel/gpu/gr/kernel_graphics.c",0x96f,uVar16,0x362d86);
                  }
                }
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar7,
                           "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_PBVIRT, NV50_MEMORY_VIRTUAL, pMemAllocParams, sizeof(NV_MEMORY_ALLOCATION_PARAMS))"
                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x922);
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar7,
                         "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_PBPHYS, NV01_MEMORY_SYSTEM, pMemAllocParams, sizeof(NV_MEMORY_ALLOCATION_PARAMS))"
                         ,"src/kernel/gpu/gr/kernel_graphics.c",0x914);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar7,
                       "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_VAS, FERMI_VASPACE_A, pVaParams, sizeof(NV_VASPACE_ALLOCATION_PARAMETERS))"
                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x8fd);
          }
          if (((bVar4) && (iVar6 = rmGpuLocksAcquire(0,0x80001), iVar6 != 0)) &&
             (nvAssertOkFailedNoLog
                        (iVar6,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GR)",
                         "src/kernel/gpu/gr/kernel_graphics.c",0x9e9), iVar7 == 0)) {
            portMemFree(lVar10);
          }
          else {
LAB_00362a30:
            iVar6 = iVar7;
            portMemFree(lVar10);
          }
        }
        else {
          cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
          if (cVar5 != '\0') {
            iVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
            bVar3 = true;
            if (iVar7 != iVar6) goto LAB_003628aa;
LAB_0036291b:
            uStack_58 = 0;
            uStack_50 = 0;
            iVar7 = kmigmgrGetMIGReferenceFromEngineType_IMPL
                              (param_1,uVar17,*(int *)(param_2 + 0x20c) + 1,&lStack_68);
            if (iVar7 == 0) {
              portMemSet(&uStack_58,0,0x10);
              uStack_50 = CONCAT44(uStack_50._4_4_,*(undefined4 *)(lStack_68 + 0x968));
              iVar7 = (**(code **)(lVar9 + 8))
                                (lVar9,uStack_80,uStack_78,0xbaba0048,0xc637,&uStack_58,0x10);
              if (iVar7 == 0) {
                if (lStack_60 != 0) {
                  lStack_48 = 0;
                  uStack_40 = (ulong)*(uint *)(lStack_60 + 0xc0);
                  iVar7 = (**(code **)(lVar9 + 8))
                                    (lVar9,uStack_80,0xbaba0048,0xbaba004a,0xc638,&lStack_48,0x10);
                  if (iVar7 != 0) {
                    nvAssertOkFailedNoLog
                              (iVar7,
                               "pRmApi->AllocWithHandle(pRmApi, hClientId, KGRAPHICS_CHANNEL_HANDLE_PARTITIONREF, KGRAPHICS_CHANNEL_HANDLE_EXECPARTITIONREF, AMPERE_SMC_EXEC_PARTITION_REF, &nvC638AllocParams, sizeof(nvC638AllocParams))"
                               ,"src/kernel/gpu/gr/kernel_graphics.c",0x8d6);
                    goto LAB_00362a30;
                  }
                }
                bVar3 = true;
                goto LAB_00362a8a;
              }
              nvAssertOkFailedNoLog
                        (iVar7,
                         "pRmApi->AllocWithHandle(pRmApi, hClientId, hSubdeviceId, KGRAPHICS_CHANNEL_HANDLE_PARTITIONREF, AMPERE_SMC_PARTITION_REF, &nvC637AllocParams, sizeof(nvC637AllocParams))"
                         ,"src/kernel/gpu/gr/kernel_graphics.c",0x8c8,0x36296f);
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar7,
                         "kmigmgrGetMIGReferenceFromEngineType(pGpu, pKernelMIGManager, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &ref)"
                         ,"src/kernel/gpu/gr/kernel_graphics.c",0x8bf);
            }
            goto LAB_00362a30;
          }
          iVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
          if (iVar6 == iVar7) goto LAB_00363120;
          bVar3 = false;
LAB_003628aa:
          iVar6 = clientGenResourceHandle_IMPL(uStack_70,&uStack_58);
          if (iVar6 == 0) {
            portMemSet(&lStack_48,0,4);
            lStack_48 = CONCAT44(lStack_48._4_4_,iVar7);
            (**(code **)(lVar9 + 8))
                      (lVar9,uStack_80,uStack_7c,uStack_58 & 0xffffffff,0x2080,&lStack_48,4);
            if (!bVar3) goto LAB_00362a8a;
            goto LAB_0036291b;
          }
          nvCheckOkFailedNoLog
                    (4,iVar6,"clientGenResourceHandle(pClientId, &hSecondary)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0x8a8);
          portMemFree(lVar10);
        }
LAB_00362a3c:
        portMemFree(puVar11);
        portMemFree(lVar12);
        goto LAB_00362a54;
      }
      nvAssertFailedNoLog("pChannelGPFIFOAllocParams != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                          0x896);
      portMemFree(lVar10);
      portMemFree(puVar11);
    }
  }
  iVar6 = 0x51;
LAB_00362a54:
  iVar7 = (**(code **)(lVar9 + 0x18))(lVar9,uStack_80,uStack_80);
  if ((iVar7 != 0) &&
     (nvAssertOkFailedNoLog
                (iVar7,"pRmApi->Free(pRmApi, hClientId, hClientId)",
                 "src/kernel/gpu/gr/kernel_graphics.c",0x9f7), iVar6 == 0)) {
    iVar6 = iVar7;
  }
  return iVar6;
}


// ===== 00362740 kgraphicsCreateGoldenImageChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgraphicsCreateGoldenImageChannel_IMPL(long param_1,long param_2)

{
  uint *puVar1;
  char *pcVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  undefined8 *puVar11;
  long lVar12;
  uint *puVar13;
  long lVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  int local_74;
  undefined8 local_70;
  long local_68;
  long local_60;
  ulong local_58;
  undefined8 local_50;
  long local_48;
  ulong local_40;
  
  local_80 = 0;
  lVar9 = rmapiGetInterface(4);
  uVar17 = *(undefined8 *)(param_1 + 0x1bc0);
  lVar10 = gpumgrGetParentGPU(param_1);
  if (param_1 != lVar10) {
    return 0;
  }
  iVar6 = rmapiutilAllocClientAndDeviceHandles(lVar9,param_1,&local_80,&local_7c,&local_78);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,
               "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &hClientId, &hDeviceId, &hSubdeviceId)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0x87f);
    return iVar6;
  }
  iVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar7 = serverGetClientUnderLock(g_resServ,local_80,&local_70);
  if (iVar7 != 0) {
    nvAssertOkFailedNoLog
              (iVar7,"serverGetClientUnderLock(&g_resServ, hClientId, &pClientId)",
               "src/kernel/gpu/gr/kernel_graphics.c",0x884);
    return iVar7;
  }
  lVar10 = portMemAllocNonPaged(0x38);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pVaParams != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x88c);
  }
  else {
    puVar11 = (undefined8 *)portMemAllocNonPaged(0x80);
    if (puVar11 == (undefined8 *)0x0) {
      nvAssertFailedNoLog("pMemAllocParams != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x891);
      portMemFree(lVar10);
    }
    else {
      lVar12 = portMemAllocNonPaged(0x170);
      if (lVar12 != 0) {
        if (*(long *)(param_1 + 0x1bc0) == 0) {
          iVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
          bVar3 = false;
          if (iVar6 != iVar7) goto LAB_003628aa;
LAB_00363120:
          bVar3 = false;
LAB_00362a8a:
          cVar5 = rmapiLockIsOwner();
          if (cVar5 == '\0') {
            cVar5 = rmapiInRtd3PmPath();
            if (cVar5 == '\0') {
              iVar6 = 0x2f;
              nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0x8f4,
                           "kgraphicsCreateGoldenImageChannel_IMPL",4,
                           "NVRM: Caller missing proper locks\n");
              portMemFree(lVar10);
              goto LAB_00362a3c;
            }
            lVar9 = rmapiGetInterface(4);
            bVar4 = false;
          }
          else {
            rmGpuLocksRelease(0,0);
            lVar9 = rmapiGetInterface(3);
            bVar4 = true;
          }
          portMemSet(lVar10,0,0x38);
          *(uint *)(lVar10 + 4) = *(uint *)(lVar10 + 4) | 0x2000;
          iVar7 = (**(code **)(lVar9 + 8))(lVar9,local_80,local_7c,0xbaba0042,0x90f1,lVar10,0x38);
          if (iVar7 == 0) {
            portMemSet(puVar11,0,0x80);
            *(uint *)((long)puVar11 + 0x1c) = *(uint *)((long)puVar11 + 0x1c) | 0x4000000;
            *puVar11 = 0xdeaf0006;
            puVar11[8] = 0x100;
            *(undefined4 *)(puVar11 + 3) = 0x2000000;
            *(undefined4 *)((long)puVar11 + 0x6c) = 0;
            iVar7 = (**(code **)(lVar9 + 8))(lVar9,local_80,local_7c,0xbaba0044,0x3e,puVar11,0x80);
            if (iVar7 == 0) {
              portMemSet(puVar11,0,0x80);
              puVar11[8] = 0x100;
              *puVar11 = 0xdeaf0006;
              *(undefined4 *)(puVar11 + 3) = 0x2000000;
              *(undefined4 *)(puVar11 + 1) = 0x80000;
              *(undefined4 *)((long)puVar11 + 0x6c) = 0xbaba0042;
              iVar7 = (**(code **)(lVar9 + 8))
                                (lVar9,local_80,local_7c,0xbaba0043,0x50a0,puVar11,0x80);
              if (iVar7 == 0) {
                cVar5 = gpuIsClassSupported_IMPL(param_1,0xc36f);
                if ((((cVar5 == '\0') &&
                     (cVar5 = gpuIsClassSupported_IMPL(param_1,0xc46f), cVar5 == '\0')) &&
                    (cVar5 = gpuIsClassSupported_IMPL(param_1,0xc56f), cVar5 == '\0')) &&
                   (((cVar5 = gpuIsClassSupported_IMPL(param_1,0xc86f), cVar5 == '\0' &&
                     (cVar5 = gpuIsClassSupported_IMPL(param_1,0xc96f), cVar5 == '\0')) &&
                    (cVar5 = gpuIsClassSupported_IMPL(param_1,0xca6f), cVar5 == '\0')))) {
                  iVar7 = 0x56;
                }
                else {
                  portMemSet(puVar11,0,0x80);
                  puVar11[8] = 0x200;
                  *puVar11 = 0xdeaf0006;
                  if (((*(ushort *)(param_1 + 0x4926) & 3) == 3) ||
                     ((*(ushort *)(param_1 + 0x4926) & 3) == 0)) {
                    *(undefined4 *)(puVar11 + 1) = 4;
                    uVar15 = 0x40;
                    puVar11[3] = 0x400000000000;
                  }
                  else {
                    *(undefined4 *)(puVar11 + 3) = 0x2000000;
                    uVar15 = 0x3e;
                  }
                  cVar5 = gpuIsApmFeatureEnabled_IMPL(param_1);
                  if ((cVar5 != '\0') || ((*(uint *)(puVar11 + 3) & 0x6000000) == 0x2000000)) {
                    *(uint *)((long)puVar11 + 0x1c) = *(uint *)((long)puVar11 + 0x1c) | 0x4000000;
                  }
                  *(uint *)(puVar11 + 3) = *(uint *)(puVar11 + 3) | 0x4000;
                  uVar16 = 0x80;
                  iVar7 = (**(code **)(lVar9 + 8))
                                    (lVar9,local_80,local_7c,0xbaba0049,uVar15,puVar11);
                  if (iVar7 == 0) {
                    uVar15 = gpuGetKernelFifoShared_IMPL(param_1);
                    iVar6 = kfifoGetChannelClassId_IMPL(param_1,uVar15);
                    local_74 = iVar6;
                    if (iVar6 == 0) {
                      nvAssertFailedNoLog("classNum != 0","src/kernel/gpu/gr/kernel_graphics.c",
                                          0x977);
                      iVar7 = 0;
                    }
                    else {
                      portMemSet(lVar12,0,0x170);
                      *(undefined8 *)(lVar12 + 4) = 0xbaba0043;
                      *(undefined8 *)(lVar12 + 0xc) = 0x2000000000;
                      *(undefined8 *)(lVar12 + 0x1c) = 0xbaba0049baba0042;
                      if (bVar3) {
                        iVar7 = deviceGetByHandle_IMPL(local_70,local_7c,&local_48);
                        if (iVar7 == 0) {
                          iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL
                                            (param_1,uVar17,local_48,&local_68);
                          if (iVar7 == 0) {
                            iVar7 = kmigmgrGetGlobalToLocalEngineType_IMPL
                                              (param_1,uVar17,local_68,local_60,
                                               *(int *)(param_2 + 0x20c) + 1,&local_58);
                            if (iVar7 == 0) {
                              uVar8 = gpuGetNv2080EngineType_IMPL(local_58 & 0xffffffff);
                              *(undefined4 *)(lVar12 + 0x80) = uVar8;
                              goto LAB_00362ecd;
                            }
                            nvAssertOkFailedNoLog
                                      (iVar7,
                                       "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &localRmEngineType)"
                                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x993);
                          }
                          else {
                            nvAssertOkFailedNoLog
                                      (iVar7,
                                       "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)"
                                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x98f);
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar7,"deviceGetByHandle(pClientId, hDeviceId, &pDevice)",
                                     "src/kernel/gpu/gr/kernel_graphics.c",0x98b);
                        }
                      }
                      else {
                        uVar8 = gpuGetNv2080EngineType_IMPL(1);
                        *(undefined4 *)(lVar12 + 0x80) = uVar8;
LAB_00362ecd:
                        uVar17 = 0x170;
                        iVar7 = (**(code **)(lVar9 + 8))
                                          (lVar9,local_80,local_7c,0xbaba0045,iVar6,lVar12);
                        if (iVar7 == 0) {
                          if (*(char *)(param_1 + 0x909) == '\0') {
LAB_00362fd4:
                            iVar7 = rmGpuLocksAcquire(0,0x80001);
                            if (iVar7 == 0) {
                              lVar9 = rmapiGetInterface(4);
                              cVar5 = kgraphicsIsGFXSupported_IMPL(param_1,param_2);
                              uVar8 = 0;
                              if (cVar5 == '\0') {
                                uVar8 = 3;
                              }
                              iVar6 = kgraphicsGetClassByType_IMPL(param_1,param_2,uVar8,&local_74);
                              if (iVar6 == 0) {
                                if (local_74 != 0) {
                                  iVar7 = (**(code **)(lVar9 + 8))
                                                    (lVar9,local_80,0xbaba0045,0xbaba0046,local_74,0
                                                     ,0);
                                  if (iVar7 != 0) {
                                    nvAssertOkFailedNoLog
                                              (iVar7,
                                               "pRmApi->AllocWithHandle(pRmApi, hClientId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, KGRAPHICS_CHANNEL_HANDLE_3DOBJ, classNum, NULL, 0)"
                                               ,"src/kernel/gpu/gr/kernel_graphics.c",0x9e0);
                                  }
                                  goto LAB_00362a30;
                                }
                                nvAssertFailedNoLog("classNum != 0",
                                                    "src/kernel/gpu/gr/kernel_graphics.c",0x9dd);
                                portMemFree(lVar10);
                                iVar6 = 0;
                              }
                              else {
                                nvAssertOkFailedNoLog
                                          (iVar6,
                                           "kgraphicsGetClassByType(pGpu, pKernelGraphics, objectType, &classNum)"
                                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x9da);
                                portMemFree(lVar10);
                              }
                              goto LAB_00362a3c;
                            }
                            nvAssertOkFailedNoLog
                                      (iVar7,
                                       "rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GR)"
                                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x9ca);
                          }
                          else {
                            pcVar2 = *(char **)(param_2 + 0x210);
                            if ((pcVar2 == (char *)0x0) || (*pcVar2 == '\0')) {
                              iVar6 = CliGetKernelChannel(local_70,0xbaba0045,&local_48,uVar17);
                              if (iVar6 != 0) {
                                nvAssertOkFailedNoLog
                                          (iVar6,
                                           "CliGetKernelChannel(pClientId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, &pKernelChannel)"
                                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x9b2);
                              }
                              nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                                                  "src/kernel/gpu/gr/kernel_graphics.c",0x9b4);
                            }
                            else {
                              iVar6 = CliGetKernelChannel(local_70,0xbaba0045,&local_48,uVar17);
                              if (iVar6 != 0) {
                                nvAssertOkFailedNoLog
                                          (iVar6,
                                           "CliGetKernelChannel(pClientId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, &pKernelChannel)"
                                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x9b2);
                              }
                              puVar13 = *(uint **)(pcVar2 + 0x13e0);
                              lVar14 = 0;
                              puVar1 = puVar13 + 0x34;
                              if (puVar13 != (uint *)0x0) {
                                do {
                                  if (*puVar13 != 0xffffffff) {
                                    lVar14 = (ulong)*puVar13 + lVar14;
                                  }
                                  puVar13 = puVar13 + 2;
                                } while (puVar1 != puVar13);
                                iVar6 = (**(code **)(**(long **)(local_48 + 0x2a0) + 0x88))
                                                  (*(long **)(local_48 + 0x2a0),param_1,
                                                   *(undefined8 *)
                                                    (*(long *)(local_48 + 0x158) + 0xe8),lVar14,
                                                   0x1000,0);
                                if (iVar6 != 0) {
                                  nvAssertOkFailedNoLog
                                            (iVar6,
                                             "vaspaceReserveMempool(pKernelChannel->pVAS, pGpu, GPU_RES_GET_DEVICE(pKernelChannel), reserveSize, RM_PAGE_SIZE, VASPACE_RESERVE_FLAGS_NONE)"
                                             ,"src/kernel/gpu/gr/kernel_graphics.c",0x9c2);
                                }
                                goto LAB_00362fd4;
                              }
                              nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL"
                                                  ,"src/kernel/gpu/gr/kernel_graphics.c",0x9b7,0);
                            }
                            iVar7 = 0x40;
                          }
                        }
                        else {
                          nvAssertOkFailedNoLog
                                    (iVar7,
                                     "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_CHANNELID, classNum, pChannelGPFIFOAllocParams, sizeof(NV_CHANNEL_ALLOC_PARAMS))"
                                     ,"src/kernel/gpu/gr/kernel_graphics.c",0x99f);
                        }
                      }
                    }
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar7,
                               "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_USERD, userdMemClass, pMemAllocParams, sizeof(NV_MEMORY_ALLOCATION_PARAMS))"
                               ,"src/kernel/gpu/gr/kernel_graphics.c",0x96f,uVar16,0x362d86);
                  }
                }
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar7,
                           "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_PBVIRT, NV50_MEMORY_VIRTUAL, pMemAllocParams, sizeof(NV_MEMORY_ALLOCATION_PARAMS))"
                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x922);
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar7,
                         "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_PBPHYS, NV01_MEMORY_SYSTEM, pMemAllocParams, sizeof(NV_MEMORY_ALLOCATION_PARAMS))"
                         ,"src/kernel/gpu/gr/kernel_graphics.c",0x914);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar7,
                       "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, KGRAPHICS_CHANNEL_HANDLE_VAS, FERMI_VASPACE_A, pVaParams, sizeof(NV_VASPACE_ALLOCATION_PARAMETERS))"
                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x8fd);
          }
          if (((bVar4) && (iVar6 = rmGpuLocksAcquire(0,0x80001), iVar6 != 0)) &&
             (nvAssertOkFailedNoLog
                        (iVar6,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_GR)",
                         "src/kernel/gpu/gr/kernel_graphics.c",0x9e9), iVar7 == 0)) {
            portMemFree(lVar10);
          }
          else {
LAB_00362a30:
            iVar6 = iVar7;
            portMemFree(lVar10);
          }
        }
        else {
          cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
          if (cVar5 != '\0') {
            iVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
            bVar3 = true;
            if (iVar7 != iVar6) goto LAB_003628aa;
LAB_0036291b:
            local_58 = 0;
            local_50 = 0;
            iVar7 = kmigmgrGetMIGReferenceFromEngineType_IMPL
                              (param_1,uVar17,*(int *)(param_2 + 0x20c) + 1,&local_68);
            if (iVar7 == 0) {
              portMemSet(&local_58,0,0x10);
              local_50 = CONCAT44(local_50._4_4_,*(undefined4 *)(local_68 + 0x968));
              iVar7 = (**(code **)(lVar9 + 8))
                                (lVar9,local_80,local_78,0xbaba0048,0xc637,&local_58,0x10);
              if (iVar7 == 0) {
                if (local_60 != 0) {
                  local_48 = 0;
                  local_40 = (ulong)*(uint *)(local_60 + 0xc0);
                  iVar7 = (**(code **)(lVar9 + 8))
                                    (lVar9,local_80,0xbaba0048,0xbaba004a,0xc638,&local_48,0x10);
                  if (iVar7 != 0) {
                    nvAssertOkFailedNoLog
                              (iVar7,
                               "pRmApi->AllocWithHandle(pRmApi, hClientId, KGRAPHICS_CHANNEL_HANDLE_PARTITIONREF, KGRAPHICS_CHANNEL_HANDLE_EXECPARTITIONREF, AMPERE_SMC_EXEC_PARTITION_REF, &nvC638AllocParams, sizeof(nvC638AllocParams))"
                               ,"src/kernel/gpu/gr/kernel_graphics.c",0x8d6);
                    goto LAB_00362a30;
                  }
                }
                bVar3 = true;
                goto LAB_00362a8a;
              }
              nvAssertOkFailedNoLog
                        (iVar7,
                         "pRmApi->AllocWithHandle(pRmApi, hClientId, hSubdeviceId, KGRAPHICS_CHANNEL_HANDLE_PARTITIONREF, AMPERE_SMC_PARTITION_REF, &nvC637AllocParams, sizeof(nvC637AllocParams))"
                         ,"src/kernel/gpu/gr/kernel_graphics.c",0x8c8,0x36296f);
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar7,
                         "kmigmgrGetMIGReferenceFromEngineType(pGpu, pKernelMIGManager, RM_ENGINE_TYPE_GR(pKernelGraphics->instance), &ref)"
                         ,"src/kernel/gpu/gr/kernel_graphics.c",0x8bf);
            }
            goto LAB_00362a30;
          }
          iVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
          if (iVar6 == iVar7) goto LAB_00363120;
          bVar3 = false;
LAB_003628aa:
          iVar6 = clientGenResourceHandle_IMPL(local_70,&local_58);
          if (iVar6 == 0) {
            portMemSet(&local_48,0,4);
            local_48 = CONCAT44(local_48._4_4_,iVar7);
            (**(code **)(lVar9 + 8))
                      (lVar9,local_80,local_7c,local_58 & 0xffffffff,0x2080,&local_48,4);
            if (!bVar3) goto LAB_00362a8a;
            goto LAB_0036291b;
          }
          nvCheckOkFailedNoLog
                    (4,iVar6,"clientGenResourceHandle(pClientId, &hSecondary)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0x8a8);
          portMemFree(lVar10);
        }
LAB_00362a3c:
        portMemFree(puVar11);
        portMemFree(lVar12);
        goto LAB_00362a54;
      }
      nvAssertFailedNoLog("pChannelGPFIFOAllocParams != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                          0x896);
      portMemFree(lVar10);
      portMemFree(puVar11);
    }
  }
  iVar6 = 0x51;
LAB_00362a54:
  iVar7 = (**(code **)(lVar9 + 0x18))(lVar9,local_80,local_80);
  if ((iVar7 != 0) &&
     (nvAssertOkFailedNoLog
                (iVar7,"pRmApi->Free(pRmApi, hClientId, hClientId)",
                 "src/kernel/gpu/gr/kernel_graphics.c",0x9f7), iVar6 == 0)) {
    iVar6 = iVar7;
  }
  return iVar6;
}


// ===== 003634f2 _kgraphicsPostSchedulingEnableHandler.cold =====

void _kgraphicsPostSchedulingEnableHandler_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00363500 _kgraphicsPostSchedulingEnableHandler =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _kgraphicsPostSchedulingEnableHandler(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  uint uVar5;
  ulong uVar6;
  char *pcVar7;
  uint local_2c;
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  if (7 < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  cVar4 = *(char *)(param_1 + 0x909);
  lVar2 = *(long *)(param_1 + 0x1bd0 + (ulong)param_2 * 8);
  pcVar7 = *(char **)(lVar2 + 0x210);
  if (pcVar7 == (char *)0x0) {
    pcVar7 = (char *)0x0;
    if (cVar4 == '\0') goto LAB_0036355e;
LAB_0036368c:
    if ((*(long *)(param_1 + 0x1bc0) == 0) ||
       (cVar4 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar4 == '\0')) {
LAB_003636a4:
      uVar5 = 0x40;
      nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                          0x1e7);
      goto LAB_00363673;
    }
LAB_00363670:
    uVar5 = 0;
  }
  else {
    if (*pcVar7 == '\0') {
      if (cVar4 != '\0') goto LAB_0036368c;
      pcVar7 = (char *)0x0;
LAB_0036355e:
      cVar4 = (**(code **)(lVar2 + 0x1a0))(param_1,lVar2);
      if ((cVar4 == '\0') ||
         ((*(long *)(param_1 + 0x1bc0) != 0 &&
          (cVar4 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar4 != '\0')))) goto LAB_00363670;
      if (pcVar7 == (char *)0x0) goto LAB_003636a4;
    }
    else {
      pcVar7 = pcVar7 + 8;
      if (cVar4 == '\0') goto LAB_0036355e;
      if ((*(long *)(param_1 + 0x1bc0) != 0) && (cVar4 = kmigmgrIsMIGEnabled_IMPL(), cVar4 != '\0'))
      goto LAB_00363670;
    }
    uVar5 = 0;
    if (*(int *)(pcVar7 + 0x1104) != 0) {
      if (*(char *)(lVar1 + 0x434) != '\0') {
        local_2c = 3;
        uVar5 = pmaQueryConfigs(*(undefined8 *)
                                 (*(long *)(*(long *)(param_1 + 0x1b78) + 0x478) + 0x128),&local_2c)
        ;
        if (uVar5 != 0) {
          nvAssertOkFailedNoLog
                    (uVar5,"pmaQueryConfigs(pHeap->pPmaObject, &pmaConfig)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0x1f0);
          goto LAB_00363673;
        }
        uVar5 = 0x10005;
        if ((local_2c & 3) == 1) goto LAB_00363673;
      }
      uVar5 = kgraphicsCreateGoldenImageChannel_IMPL(param_1,lVar2);
      if (uVar5 == 0) {
        cVar4 = (**(code **)(lVar2 + 0x1a0))(param_1,lVar2);
        if (cVar4 != '\0') {
          uVar6 = (**(code **)(lVar2 + 0x198))(param_1,lVar2);
          return uVar6;
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar5,"kgraphicsCreateGoldenImageChannel(pGpu, pKernelGraphics)",
                   "src/kernel/gpu/gr/kernel_graphics.c",0x1fe);
      }
    }
  }
LAB_00363673:
  return (ulong)uVar5;
}


// ===== 00363730 kgraphicsFreeGlobalCtxBuffers_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgraphicsFreeGlobalCtxBuffers_IMPL(long param_1,long param_2,uint param_3)

{
  long lVar1;
  bool bVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  
  if ((*(long *)(param_2 + 0x230) != 0) &&
     (lVar5 = *(long *)(param_2 + 0x230) + (ulong)param_3 * 0x60, *(char *)(lVar5 + 0x50) != '\0'))
  {
    bVar2 = false;
    lVar4 = 0;
    lVar1 = *(long *)(param_1 + 0x1b70);
    do {
      if (*(long *)(lVar5 + lVar4 * 8) != 0) {
        memdescFree();
        memdescDestroy(*(undefined8 *)(lVar5 + lVar4 * 8));
        *(undefined8 *)(lVar5 + lVar4 * 8) = 0;
        bVar2 = true;
        *(undefined1 *)(lVar5 + 0x51 + lVar4) = 0;
      }
      lVar4 = lVar4 + 1;
    } while (lVar4 != 10);
    *(undefined1 *)(lVar5 + 0x50) = 0;
    if ((bVar2) &&
       (uVar3 = (**(code **)(lVar1 + 0x188))(param_1,lVar1,0,2,3), (uVar3 & 0xffffffef) != 0)) {
      nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                          "src/kernel/gpu/gr/kernel_graphics.c",0xa30);
      return;
    }
  }
  return;
}


// ===== 00363820 kgraphicsStatePreUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgraphicsStatePreUnload_IMPL(undefined8 param_1,long param_2,ulong param_3)

{
  (**(code **)(param_2 + 0x188))();
  fecsBufferUnmap(param_1,param_2);
  if ((param_3 & 1) != 0) {
    return 0;
  }
  kgraphicsFreeGlobalCtxBuffers_IMPL(param_1,param_2,0);
  return 0;
}


// ===== 00363890 kgraphicsIsUnrestrictedAccessMapSupported_PF =====

bool kgraphicsIsUnrestrictedAccessMapSupported_PF(void)

{
  char cVar1;
  
  cVar1 = hypervisorIsVgxHyper_IMPL();
  return cVar1 == '\0';
}


// ===== 003638b0 kgraphicsRegisterIntrService_IMPL =====

void kgraphicsRegisterIntrService_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long *plVar1;
  
  plVar1 = (long *)(param_3 + (ulong)(*(int *)(param_2 + 0x20c) + 0x9c) * 0x18);
  if (*plVar1 != 0) {
    nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xa63);
  }
  *plVar1 = *(long *)(param_2 + 0x170);
  param_3 = param_3 + (ulong)(*(int *)(param_2 + 0x20c) + 0x54) * 0x18;
  if (*(long *)(param_3 + 8) != 0) {
    nvAssertFailedNoLog("pRecords[engineIdx].pNotificationService == NULL",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xa68);
  }
  *(undefined1 *)(param_3 + 0x10) = 0;
  *(undefined8 *)(param_3 + 8) = *(undefined8 *)(param_2 + 0x170);
  return;
}


// ===== 00363980 kgraphicsServiceNotificationInterrupt_IMPL =====

undefined8 kgraphicsServiceNotificationInterrupt_IMPL(undefined8 param_1,long param_2,long param_3)

{
  if (param_3 != 0) {
    if ((uint)*(ushort *)(param_3 + 8) == *(int *)(param_2 + 0x20c) + 0x54U) {
      engineNonStallIntrNotify(param_1,*(int *)(param_2 + 0x20c) + 1);
    }
    else {
      nvAssertFailedNoLog("pParams->engineIdx == MC_ENGINE_IDX_GRn(grIdx)",
                          "src/kernel/gpu/gr/kernel_graphics.c",0xa7b);
    }
    return 0;
  }
  nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xa7a);
  return 0;
}


// ===== 003639f0 deviceCtrlCmdKGrGetCaps_IMPL =====

int deviceCtrlCmdKGrGetCaps_IMPL(long param_1,int *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  long local_40;
  undefined1 local_38 [16];
  
  lVar1 = *(long *)(param_2 + 2);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/gr/kernel_graphics.c",0xa9b);
    return 0x2f;
  }
  if (lVar1 == 0) {
    nvCheckFailedNoLog(4,"pGrCaps != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xaa2);
  }
  else {
    if (*param_2 == 0x17) {
      uVar3 = *(undefined8 *)(lVar2 + 0x1bc8);
      portMemSet(local_38,0,0x10);
      kgrmgrCtrlSetEngineID_IMPL(0,local_38);
      iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar2,uVar3,param_1,local_38,&local_40);
      if (iVar6 == 0) {
        pcVar4 = *(char **)(local_40 + 0x210);
        if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
          iVar6 = 0x40;
          nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                              "src/kernel/gpu/gr/kernel_graphics.c",0xa3f);
          nvCheckOkFailedNoLog
                    (4,0x40,"kgraphicsGetCaps(pGpu, pKernelGraphics, pGrCaps)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0xab4);
        }
        else {
          portMemCopy(lVar1,0x17,pcVar4 + 0x10,0x17);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar6,
                   "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0xaae);
      }
      return iVar6;
    }
    nvCheckFailedNoLog(4,"pParams->capsTblSize == NV0080_CTRL_GR_CAPS_TBL_SIZE",
                       "src/kernel/gpu/gr/kernel_graphics.c",0xaa3);
  }
  return 0x1f;
}


// ===== 00363bc0 deviceCtrlCmdKGrGetCapsV2_IMPL =====

int deviceCtrlCmdKGrGetCapsV2_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar4 = rmapiLockIsOwner();
  if (cVar4 == '\0') {
    iVar5 = 0x2f;
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/gr/kernel_graphics.c",0xacf);
  }
  else {
    local_38 = *(undefined8 *)(param_2 + 0x18);
    local_30 = *(undefined8 *)(param_2 + 0x20);
    uVar2 = *(undefined8 *)(lVar1 + 0x1bc8);
    kgrmgrCtrlSetEngineID_IMPL(0,&local_38);
    iVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar2,param_1,&local_38,&local_40);
    if (iVar5 == 0) {
      if (*(char *)(param_2 + 0x28) == '\0') {
        pcVar3 = *(char **)(local_40 + 0x210);
        if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
          iVar5 = 0x40;
          nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                              "src/kernel/gpu/gr/kernel_graphics.c",0xa3f);
          nvCheckOkFailedNoLog
                    (4,0x40,"kgraphicsGetCaps(pGpu, pKernelGraphics, pParams->capsTbl)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0xae4);
        }
        else {
          portMemCopy(param_2,0x17,pcVar3 + 0x10,0x17);
          *(undefined1 *)(param_2 + 0x28) = 1;
        }
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xade);
    }
  }
  return iVar5;
}


// ===== 00363d40 deviceCtrlCmdKGrGetInfo_IMPL =====

int deviceCtrlCmdKGrGetInfo_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  uint local_218;
  undefined1 local_214 [492];
  
  lVar2 = *(long *)(param_2 + 2);
  uVar1 = *param_2;
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xb3f);
    return 0x2f;
  }
  if (lVar2 == 0) {
    nvCheckFailedNoLog(4,"pGrInfos != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xb41);
    return 0x1f;
  }
  if (0x3b < uVar1) {
    uVar1 = 0x3b;
  }
  portMemSet(&local_218,0,0x1f0);
  portMemCopy(local_214,(ulong)uVar1 << 3,lVar2);
  local_218 = uVar1;
  iVar5 = _kgraphicsCtrlCmdGrGetInfoV2(uVar3,param_1,&local_218);
  if (iVar5 == 0) {
    portMemCopy(lVar2,(ulong)uVar1 << 3,local_214);
    return 0;
  }
  nvCheckOkFailedNoLog
            (4,iVar5,"_kgraphicsCtrlCmdGrGetInfoV2(pGpu, pDevice, &grInfoParamsV2)",
             "src/kernel/gpu/gr/kernel_graphics.c",0xb48);
  return iVar5;
}


// ===== 00363e90 deviceCtrlCmdKGrGetInfoV2_IMPL =====

ulong deviceCtrlCmdKGrGetInfoV2_IMPL(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  char cVar2;
  ulong uVar3;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      uVar3 = _kgraphicsCtrlCmdGrGetInfoV2(uVar1,param_1,param_2);
      if ((int)uVar3 != 0) {
        nvCheckOkFailedNoLog
                  (4,uVar3 & 0xffffffff,"_kgraphicsCtrlCmdGrGetInfoV2(pGpu, pDevice, pParams)",
                   "src/kernel/gpu/gr/kernel_graphics.c",0xb61);
        uVar3 = uVar3 & 0xffffffff;
      }
      return uVar3;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_graphics.c",0xb5f);
  return 0x2f;
}


// ===== 00363f40 kgraphicsDiscoverMaxLocalCtxBufferSize_IMPL =====

int kgraphicsDiscoverMaxLocalCtxBufferSize_IMPL(long param_1,long param_2)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  ulong *puVar6;
  uint local_3c [3];
  
  pcVar2 = *(char **)(param_2 + 0x210);
  pcVar5 = pcVar2;
  if (pcVar2 != (char *)0x0) {
    pcVar5 = (char *)0x0;
    if (*pcVar2 != '\0') {
      pcVar5 = pcVar2 + 8;
    }
  }
  iVar3 = 0;
  if (*(char *)(param_1 + 0x490f) == '\0') {
    iVar3 = kgraphicsInitializeDeferredStaticData_IMPL(param_1,param_2,0,0);
    if (iVar3 == 0) {
      if (*(long *)(pcVar5 + 0x13d8) == 0) {
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xb77);
      }
      else {
        iVar3 = kgraphicsGetMainCtxBufferSize_IMPL(param_1,param_2,1,local_3c);
        if (iVar3 == 0) {
          *(undefined1 *)(param_2 + 0x444) = 1;
          *(undefined8 *)(param_2 + 0x438) = 0x1000;
          *(ulong *)(param_2 + 0x430) = (ulong)local_3c[0];
          *(undefined4 *)(param_2 + 0x440) = 1;
          puVar6 = (ulong *)(param_2 + 0x430);
          iVar3 = 1;
          do {
            iVar4 = kgrctxCtxBufferToFifoEngineId_IMPL(iVar3,local_3c);
            if (iVar4 != 0) {
              nvAssertOkFailedNoLog
                        (iVar4,"kgrctxCtxBufferToFifoEngineId(bufId, &fifoEngineId)",
                         "src/kernel/gpu/gr/kernel_graphics.c",0xb8a);
              return iVar4;
            }
            iVar4 = iVar3 + 1;
            uVar1 = *(uint *)(*(long *)(pcVar5 + 0x13d8) + (ulong)local_3c[0] * 8);
            puVar6[4] = 0x1000;
            *(undefined4 *)(puVar6 + 5) = 1;
            puVar6[3] = (ulong)uVar1;
            *(byte *)((long)puVar6 + 0x2c) = (byte)(0x104L >> ((byte)iVar3 & 0x3f)) & 1;
            puVar6 = puVar6 + 3;
            iVar3 = iVar4;
          } while (iVar4 != 10);
          return 0;
        }
        nvAssertOkFailedNoLog
                  (0x40,"kgraphicsGetMainCtxBufferSize(pGpu, pKernelGraphics, NV_TRUE, &size)",
                   "src/kernel/gpu/gr/kernel_graphics.c",0xb7f);
      }
      return 0x40;
    }
    nvAssertOkFailedNoLog
              (iVar3,
               "kgraphicsInitializeDeferredStaticData(pGpu, pKernelGraphics, NV01_NULL_OBJECT, NV01_NULL_OBJECT)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xb74);
  }
  return iVar3;
}


// ===== 00364150 subdeviceCtrlCmdKGrGetCapsV2_IMPL =====

int subdeviceCtrlCmdKGrGetCapsV2_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  local_38 = *(undefined8 *)(param_2 + 0x18);
  local_30 = *(undefined8 *)(param_2 + 0x20);
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  kgrmgrCtrlSetEngineID_IMPL(0,&local_38);
  iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,&local_38,&local_40);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xbb0);
    return iVar6;
  }
  cVar5 = rmapiLockIsOwner();
  if (cVar5 == '\0') {
    iVar6 = 0x2f;
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/gr/kernel_graphics.c",0xbb3);
  }
  else {
    pcVar4 = *(char **)(local_40 + 0x210);
    if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
      return 0x40;
    }
    iVar6 = 0;
    if (*(char *)(param_2 + 0x28) == '\0') {
      portMemCopy(param_2,0x17,pcVar4 + 0x10,0x17);
      *(undefined1 *)(param_2 + 0x28) = 1;
      return 0;
    }
  }
  return iVar6;
}


// ===== 003642b0 subdeviceCtrlCmdKGrGetInfo_IMPL =====

int subdeviceCtrlCmdKGrGetInfo_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  ulong uVar9;
  undefined4 local_228;
  undefined1 local_224 [476];
  uint local_48;
  undefined8 local_40;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(lVar3 + 0x1bc8) == 0) {
    nvCheckFailedNoLog(4,"pKernelGraphicsManager != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                       0xbe1);
    return 0x56;
  }
  uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  lVar5 = *(long *)(param_2 + 2);
  uVar1 = param_2[4];
  uVar6 = *(undefined8 *)(param_2 + 6);
  uVar2 = *param_2;
  uVar9 = (ulong)uVar2;
  cVar7 = rmapiLockIsOwner();
  if (cVar7 != '\0') {
    cVar7 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar3 + 0x7a4));
    if (cVar7 != '\0') {
      if (lVar5 == 0) {
        nvCheckFailedNoLog(4,"pGrInfos != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xbe6);
        iVar8 = 0x1f;
      }
      else {
        if (0x3b < uVar2) {
          uVar9 = 0x3b;
        }
        portMemSet(&local_228,0,0x1f0);
        local_228 = (undefined4)uVar9;
        portMemCopy(local_224,uVar9 * 8,lVar5,uVar9 * 8);
        local_48 = uVar1;
        local_40 = uVar6;
        iVar8 = _kgraphicsCtrlCmdGrGetInfoV2(lVar3,uVar4,&local_228);
        if (iVar8 == 0) {
          portMemCopy(lVar5,uVar9 * 8,local_224,uVar9 * 8);
        }
        else {
          nvCheckOkFailedNoLog
                    (4,iVar8,"_kgraphicsCtrlCmdGrGetInfoV2(pGpu, pDevice, &grInfoParamsV2)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0xbee);
        }
      }
      return iVar8;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0xbe3);
  return 0x2f;
}


// ===== 003644d0 subdeviceCtrlCmdKGrGetInfoV2_IMPL =====

ulong subdeviceCtrlCmdKGrGetInfoV2_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
    if (cVar3 != '\0') {
      uVar4 = _kgraphicsCtrlCmdGrGetInfoV2(lVar1,uVar2,param_2);
      if ((int)uVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,uVar4 & 0xffffffff,"_kgraphicsCtrlCmdGrGetInfoV2(pGpu, pDevice, pParams)",
                   "src/kernel/gpu/gr/kernel_graphics.c",0xc09);
        uVar4 = uVar4 & 0xffffffff;
      }
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0xc06);
  return 0x2f;
}


// ===== 003645b0 __pfx_subdeviceCtrlCmdKGrGetSmToGpcTpcMappings_IMPL =====

int __pfx_subdeviceCtrlCmdKGrGetSmToGpcTpcMappings_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  ushort *puVar8;
  long alStack_40 [2];
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar2 = *(undefined8 *)(lVar7 + 0x1bc8);
  uVar3 = *(undefined8 *)(lVar7 + 0x1bc0);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') ||
     (cVar5 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar7 + 0x7a4)), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xc24);
    return 0x2f;
  }
  cVar5 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar7,uVar3,uVar1);
  if (cVar5 != '\0') {
    return 0x56;
  }
  iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar7,uVar2,uVar1,param_2 + 0x788,alStack_40);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xc2d);
    return iVar6;
  }
  pcVar4 = *(char **)(alStack_40[0] + 0x210);
  if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xc33);
    return 0x40;
  }
  if (0xf0 < *(ushort *)(pcVar4 + 0x1108)) {
    nvAssertFailedNoLog("pStaticInfo->globalSmOrder.numSm <= NV2080_CTRL_GR_GET_SM_TO_GPC_TPC_MAPPINGS_MAX_SM_COUNT"
                        ,"src/kernel/gpu/gr/kernel_graphics.c",0xc36);
    return 0x2e;
  }
  *(uint *)(param_2 + 0x780) = (uint)*(ushort *)(pcVar4 + 0x1108);
  if (*(short *)(pcVar4 + 0x1108) == 0) {
    return 0;
  }
  lVar7 = 0;
  puVar8 = (ushort *)(pcVar4 + 0x28);
  do {
    *(uint *)(param_2 + lVar7 * 8) = (uint)*puVar8;
    *(uint *)(param_2 + 4 + lVar7 * 8) = (uint)puVar8[1];
    lVar7 = lVar7 + 1;
    puVar8 = puVar8 + 9;
  } while ((uint)lVar7 < (uint)*(ushort *)(pcVar4 + 0x1108));
  return 0;
}


// ===== 003645c0 subdeviceCtrlCmdKGrGetSmToGpcTpcMappings_IMPL =====

int subdeviceCtrlCmdKGrGetSmToGpcTpcMappings_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  ushort *puVar8;
  long local_40 [2];
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar2 = *(undefined8 *)(lVar7 + 0x1bc8);
  uVar3 = *(undefined8 *)(lVar7 + 0x1bc0);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') ||
     (cVar5 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar7 + 0x7a4)), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xc24);
    return 0x2f;
  }
  cVar5 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar7,uVar3,uVar1);
  if (cVar5 != '\0') {
    return 0x56;
  }
  iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar7,uVar2,uVar1,param_2 + 0x788,local_40);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xc2d);
    return iVar6;
  }
  pcVar4 = *(char **)(local_40[0] + 0x210);
  if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xc33);
    return 0x40;
  }
  if (0xf0 < *(ushort *)(pcVar4 + 0x1108)) {
    nvAssertFailedNoLog("pStaticInfo->globalSmOrder.numSm <= NV2080_CTRL_GR_GET_SM_TO_GPC_TPC_MAPPINGS_MAX_SM_COUNT"
                        ,"src/kernel/gpu/gr/kernel_graphics.c",0xc36);
    return 0x2e;
  }
  *(uint *)(param_2 + 0x780) = (uint)*(ushort *)(pcVar4 + 0x1108);
  if (*(short *)(pcVar4 + 0x1108) == 0) {
    return 0;
  }
  lVar7 = 0;
  puVar8 = (ushort *)(pcVar4 + 0x28);
  do {
    *(uint *)(param_2 + lVar7 * 8) = (uint)*puVar8;
    *(uint *)(param_2 + 4 + lVar7 * 8) = (uint)puVar8[1];
    lVar7 = lVar7 + 1;
    puVar8 = puVar8 + 9;
  } while ((uint)lVar7 < (uint)*(ushort *)(pcVar4 + 0x1108));
  return 0;
}


// ===== 00364790 subdeviceCtrlCmdKGrGetGlobalSmOrder_IMPL =====

int subdeviceCtrlCmdKGrGetGlobalSmOrder_IMPL(long param_1,undefined2 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  long local_40 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') ||
     (cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xc54);
    return 0x2f;
  }
  cVar6 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar1,uVar4,uVar2);
  if (cVar6 != '\0') {
    return 0x56;
  }
  iVar7 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2 + 0x1204,local_40);
  if (iVar7 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar7,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xc5d);
    return iVar7;
  }
  pcVar5 = *(char **)(local_40[0] + 0x210);
  if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xc63);
    return 0x40;
  }
  if (0x200 < *(ushort *)(pcVar5 + 0x1108)) {
    nvAssertFailedNoLog("pStaticInfo->globalSmOrder.numSm <= NV2080_CTRL_CMD_GR_GET_GLOBAL_SM_ORDER_MAX_SM_COUNT"
                        ,"src/kernel/gpu/gr/kernel_graphics.c",0xc66);
    return 0x2e;
  }
  param_2[0x1200] = *(ushort *)(pcVar5 + 0x1108);
  param_2[0x1201] = *(undefined2 *)(pcVar5 + 0x110a);
  if (*(short *)(pcVar5 + 0x1108) == 0) {
    return 0;
  }
  uVar8 = 0;
  pcVar9 = pcVar5 + 0x28;
  do {
    uVar8 = uVar8 + 1;
    *param_2 = *(undefined2 *)pcVar9;
    param_2[1] = *(undefined2 *)(pcVar9 + 2);
    param_2[2] = *(undefined2 *)(pcVar9 + 4);
    param_2[3] = *(undefined2 *)(pcVar9 + 6);
    param_2[4] = *(undefined2 *)(pcVar9 + 8);
    param_2[5] = *(undefined2 *)(pcVar9 + 10);
    param_2[6] = *(undefined2 *)(pcVar9 + 0xc);
    param_2[7] = *(undefined2 *)(pcVar9 + 0xe);
    param_2[8] = *(undefined2 *)(pcVar9 + 0x10);
    param_2 = param_2 + 9;
    pcVar9 = pcVar9 + 0x12;
  } while (uVar8 < *(ushort *)(pcVar5 + 0x1108));
  return 0;
}


// ===== 003649c0 subdeviceCtrlCmdKGrGetSmIssueRateModifier_IMPL =====

int subdeviceCtrlCmdKGrGetSmIssueRateModifier_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  long *plVar8;
  long local_40 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') || (cVar6 = rmGpuLockIsOwner(), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xc90);
    return 0x2f;
  }
  cVar6 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar1,uVar4,uVar2);
  plVar8 = (long *)(lVar1 + 0x1bd0);
  if (cVar6 == '\0') {
    iVar7 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,local_40);
    if (iVar7 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar7,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xca0);
      return iVar7;
    }
LAB_00364abd:
    pcVar5 = *(char **)(local_40[0] + 0x210);
    if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {
      if (*(undefined1 **)(pcVar5 + 0x13e8) == (undefined1 *)0x0) {
        nvAssertFailedNoLog("pStaticInfo->pSmIssueRateModifier != NULL",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xca7);
        return 0x56;
      }
      *(undefined1 *)(param_2 + 0x10) = **(undefined1 **)(pcVar5 + 0x13e8);
      *(undefined1 *)(param_2 + 0x11) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 1);
      *(undefined1 *)(param_2 + 0x12) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 2);
      *(undefined1 *)(param_2 + 0x13) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 3);
      *(undefined1 *)(param_2 + 0x14) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 4);
      *(undefined1 *)(param_2 + 0x15) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 5);
      *(undefined1 *)(param_2 + 0x16) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 6);
      *(undefined1 *)(param_2 + 0x17) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 7);
      *(undefined1 *)(param_2 + 0x18) = *(undefined1 *)(*(long *)(pcVar5 + 0x13e8) + 8);
      return 0;
    }
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xca6);
  }
  else {
    do {
      local_40[0] = *plVar8;
      if (local_40[0] != 0) goto LAB_00364abd;
      plVar8 = plVar8 + 1;
    } while (plVar8 != (long *)(lVar1 + 0x1c10));
  }
  return 0x40;
}


// ===== 00364c20 subdeviceCtrlCmdKGrGetSmIssueRateModifierV2_IMPL =====

int subdeviceCtrlCmdKGrGetSmIssueRateModifierV2_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  long *plVar7;
  uint *puVar8;
  ulong uVar9;
  char *pcVar10;
  long lVar11;
  ulong uVar12;
  uint *puVar13;
  undefined8 uVar14;
  uint *puVar15;
  int local_3c;
  long local_38;
  long local_30;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar14 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar4 = *(undefined8 *)(lVar3 + 0x1bc0);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xcde);
    return 0x2f;
  }
  if (((*(long *)(lVar3 + 0x1bc0) == 0) ||
      (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar3), cVar5 == '\0')) ||
     (cVar5 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar3,uVar4,uVar14), cVar5 != '\0')) {
    plVar7 = (long *)(lVar3 + 0x1bd0);
    while (lVar11 = *plVar7, lVar11 == 0) {
      plVar7 = plVar7 + 1;
      if (plVar7 == (long *)(lVar3 + 0x1c10)) {
        return 0x40;
      }
    }
LAB_00364d60:
    pcVar10 = *(char **)(lVar11 + 0x210);
    if ((pcVar10 == (char *)0x0) || (*pcVar10 == '\0')) {
      nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xcfd);
      return 0x40;
    }
    puVar13 = *(uint **)(pcVar10 + 0x13f0);
    if (puVar13 == (uint *)0x0) {
      nvAssertFailedNoLog("pStaticInfo->pSmIssueRateModifierV2 != NULL",
                          "src/kernel/gpu/gr/kernel_graphics.c",0xcfe);
      return 0x56;
    }
    uVar1 = *param_2;
    if (uVar1 < 0xff) {
      uVar2 = *puVar13;
      if (uVar1 == 0) {
        *param_2 = uVar2;
        if (uVar2 == 0) {
          return 0;
        }
        uVar12 = (ulong)uVar2;
        uVar9 = 0;
        do {
          param_2[uVar9 * 2 + 1] =
               *(uint *)(*(long *)(pcVar10 + 0x13f0) + 4 + (uVar9 & 0xffffffff) * 8);
          uVar9 = uVar9 + 1;
        } while (uVar9 != uVar12);
        puVar13 = *(uint **)(pcVar10 + 0x13f0);
      }
      else {
        if (uVar2 == 0) {
LAB_00364f10:
          nvAssertOkFailedNoLog
                    (0x1f,
                     "findSmIssueRateModifier(pParams->smIssueRateModifierList[i].index, &fuseValue, pStaticInfo->pSmIssueRateModifierV2)"
                     ,"src/kernel/gpu/gr/kernel_graphics.c",0xd09);
          return 0x1f;
        }
        puVar15 = param_2;
        do {
          puVar8 = puVar13;
          while (puVar15[1] != puVar8[1]) {
            puVar8 = puVar8 + 2;
            if (puVar8 == puVar13 + (ulong)uVar2 * 2) goto LAB_00364f10;
          }
          puVar15 = puVar15 + 2;
        } while (puVar15 != param_2 + (ulong)uVar1 * 2);
        uVar12 = (ulong)uVar1;
      }
      puVar15 = param_2 + uVar12 * 2;
      while (*puVar13 != 0) {
        uVar9 = 0;
        while (param_2[1] != puVar13[uVar9 * 2 + 1]) {
          uVar9 = uVar9 + 1;
          if (uVar9 == *puVar13) goto LAB_00364e48;
        }
        param_2 = param_2 + 2;
        *param_2 = puVar13[(uVar9 & 0xffffffff) * 2 + 2];
        if (puVar15 == param_2) {
          return 0;
        }
        puVar13 = *(uint **)(pcVar10 + 0x13f0);
      }
LAB_00364e48:
      nvAssertOkFailedNoLog
                (0x1f,
                 "findSmIssueRateModifier(pParams->smIssueRateModifierList[i].index, &(pParams->smIssueRateModifierList[i].data), pStaticInfo->pSmIssueRateModifierV2)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xd15);
    }
    return 0x1f;
  }
  iVar6 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar3,uVar4,uVar14,&local_38);
  uVar14 = 0xcf1;
  pcVar10 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
  if (iVar6 == 0) {
    if ((local_30 == 0) || (local_38 == 0)) {
      nvAssertFailedNoLog("ref.pMIGComputeInstance != NULL && ref.pKernelMIGGpuInstance != NULL",
                          "src/kernel/gpu/gr/kernel_graphics.c",0xcf3,
                          "src/kernel/gpu/gr/kernel_graphics.c",0xcf1);
      return 0x40;
    }
    iVar6 = kmigmgrGetLocalToGlobalEngineType_IMPL(lVar3,uVar4,local_38,local_30,1,&local_3c);
    if (iVar6 == 0) {
      lVar11 = 0;
      if (local_3c - 1U < 8) {
        lVar11 = *(long *)(lVar3 + 0x1bd0 + (ulong)(local_3c - 1U) * 8);
      }
      goto LAB_00364d60;
    }
    uVar14 = 0xcf5;
    pcVar10 = 
    "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(0), &globalGrEngine)"
    ;
  }
  nvCheckOkFailedNoLog(4,iVar6,pcVar10,"src/kernel/gpu/gr/kernel_graphics.c",uVar14);
  return iVar6;
}


// ===== 00364fc0 subdeviceCtrlCmdKGrGetSmIssueThrottleCtrl_IMPL =====

int subdeviceCtrlCmdKGrGetSmIssueThrottleCtrl_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  char cVar5;
  int iVar6;
  long *plVar7;
  uint *puVar8;
  ulong uVar9;
  char *pcVar10;
  long lVar11;
  ulong uVar12;
  uint *puVar13;
  undefined8 uVar14;
  uint *puVar15;
  int local_3c;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar14 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar4 = *(undefined8 *)(lVar3 + 0x1bc0);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xd42);
    return 0x2f;
  }
  if (((*(long *)(lVar3 + 0x1bc0) != 0) &&
      (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar3), cVar5 != '\0')) &&
     (cVar5 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar3,uVar4,uVar14), cVar5 == '\0')) {
    iVar6 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar3,uVar4,uVar14,&local_38);
    uVar14 = 0xd55;
    pcVar10 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
    if (iVar6 == 0) {
      iVar6 = kmigmgrGetLocalToGlobalEngineType_IMPL(lVar3,uVar4,local_38,local_30,1,&local_3c);
      if (iVar6 == 0) {
        lVar11 = 0;
        if (local_3c - 1U < 8) {
          lVar11 = *(long *)(lVar3 + 0x1bd0 + (ulong)(local_3c - 1U) * 8);
        }
        goto LAB_003650f0;
      }
      uVar14 = 0xd58;
      pcVar10 = 
      "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(0), &globalGrEngine)"
      ;
    }
    nvCheckOkFailedNoLog(4,iVar6,pcVar10,"src/kernel/gpu/gr/kernel_graphics.c",uVar14);
    return iVar6;
  }
  plVar7 = (long *)(lVar3 + 0x1bd0);
  while (lVar11 = *plVar7, lVar11 == 0) {
    plVar7 = plVar7 + 1;
    if (plVar7 == (long *)(lVar3 + 0x1c10)) {
      return 0x40;
    }
  }
LAB_003650f0:
  pcVar10 = *(char **)(lVar11 + 0x210);
  if ((pcVar10 == (char *)0x0) || (*pcVar10 == '\0')) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xd60);
    return 0x40;
  }
  puVar13 = *(uint **)(pcVar10 + 0x13f8);
  if (puVar13 == (uint *)0x0) {
    nvAssertFailedNoLog("pStaticInfo->pSmIssueThrottleCtrl != NULL",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xd61);
    return 0x56;
  }
  uVar1 = *param_2;
  if (uVar1 < 0xff) {
    uVar2 = *puVar13;
    if (uVar1 == 0) {
      *param_2 = uVar2;
      if (uVar2 == 0) {
        return 0;
      }
      uVar12 = (ulong)uVar2;
      uVar9 = 0;
      do {
        param_2[uVar9 * 2 + 1] =
             *(uint *)(*(long *)(pcVar10 + 0x13f8) + 4 + (uVar9 & 0xffffffff) * 8);
        uVar9 = uVar9 + 1;
      } while (uVar9 != uVar12);
      puVar13 = *(uint **)(pcVar10 + 0x13f8);
    }
    else {
      if (uVar2 == 0) {
LAB_00365290:
        nvAssertOkFailedNoLog
                  (0x1f,
                   "findSmIssueThrottleCtrl(pParams->smIssueThrottleCtrlList[i].index, &fuseValue, pStaticInfo->pSmIssueThrottleCtrl)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0xd6c);
        return 0x1f;
      }
      puVar15 = param_2;
      do {
        puVar8 = puVar13;
        while (puVar15[1] != puVar8[1]) {
          puVar8 = puVar8 + 2;
          if (puVar8 == puVar13 + (ulong)uVar2 * 2) goto LAB_00365290;
        }
        puVar15 = puVar15 + 2;
      } while (puVar15 != param_2 + (ulong)uVar1 * 2);
      uVar12 = (ulong)uVar1;
    }
    puVar15 = param_2 + uVar12 * 2;
    while (*puVar13 != 0) {
      uVar9 = 0;
      while (param_2[1] != puVar13[uVar9 * 2 + 1]) {
        uVar9 = uVar9 + 1;
        if (uVar9 == *puVar13) goto LAB_003651d8;
      }
      param_2 = param_2 + 2;
      *param_2 = puVar13[(uVar9 & 0xffffffff) * 2 + 2];
      if (puVar15 == param_2) {
        return 0;
      }
      puVar13 = *(uint **)(pcVar10 + 0x13f8);
    }
LAB_003651d8:
    nvAssertOkFailedNoLog
              (0x1f,
               "findSmIssueThrottleCtrl(pParams->smIssueThrottleCtrlList[i].index, &(pParams->smIssueThrottleCtrlList[i].data), pStaticInfo->pSmIssueThrottleCtrl)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xd78);
  }
  return 0x1f;
}


// ===== 00365310 subdeviceCtrlCmdKGrGetGpcMask_IMPL =====

ulong subdeviceCtrlCmdKGrGetGpcMask_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  char cVar6;
  undefined4 uVar7;
  ulong uVar8;
  long local_40 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') ||
     (cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xd97);
    return 0x2f;
  }
  if (((*(long *)(lVar1 + 0x1bc0) != 0) &&
      (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar6 != '\0')) &&
     (cVar6 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar1,uVar4,uVar2), cVar6 == '\0')) {
    uVar8 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,local_40);
    if ((int)uVar8 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar8 & 0xffffffff,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xda1);
      return uVar8 & 0xffffffff;
    }
    pcVar5 = *(char **)(local_40[0] + 0x210);
    if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(pcVar5 + 0x110c);
      return uVar8;
    }
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                        0xda5);
    return 0x40;
  }
  uVar7 = kgrmgrGetLegacyGpcMask_IMPL(lVar1,uVar3);
  *(undefined4 *)(param_2 + 0x10) = uVar7;
  return 0;
}


// ===== 00365470 subdeviceCtrlCmdKGrGetTpcMask_IMPL =====

ulong subdeviceCtrlCmdKGrGetTpcMask_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  char cVar6;
  undefined4 uVar7;
  ulong uVar8;
  uint uVar9;
  long local_40 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') ||
     (cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xdc7);
    return 0x2f;
  }
  if (((*(long *)(lVar1 + 0x1bc0) != 0) &&
      (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar6 != '\0')) &&
     (cVar6 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar1,uVar4,uVar2), cVar6 == '\0')) {
    uVar8 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,local_40);
    if ((int)uVar8 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar8 & 0xffffffff,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xdd1);
      return uVar8 & 0xffffffff;
    }
    pcVar5 = *(char **)(local_40[0] + 0x210);
    if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {
      uVar9 = *(uint *)(pcVar5 + 0x110c) - (*(uint *)(pcVar5 + 0x110c) >> 1 & 0x55555555);
      uVar9 = (uVar9 & 0x33333333) + (uVar9 >> 2 & 0x33333333);
      if (*(uint *)(param_2 + 0x10) < ((uVar9 >> 4) + uVar9 & 0xf0f0f0f) * 0x1010101 >> 0x18) {
        *(undefined4 *)(param_2 + 0x14) =
             *(undefined4 *)(pcVar5 + (ulong)*(uint *)(param_2 + 0x10) * 4 + 0x1110);
        return uVar8;
      }
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0xdda,"subdeviceCtrlCmdKGrGetTpcMask_IMPL",
                   4,"NVRM: Incorrect GPC-Idx provided = %d\n");
      return 0x1f;
    }
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                        0xdd5);
    return 0x40;
  }
  uVar7 = kgrmgrGetLegacyTpcMask_IMPL(lVar1,uVar3,*(undefined4 *)(param_2 + 0x10));
  *(undefined4 *)(param_2 + 0x14) = uVar7;
  return 0;
}


// ===== 00365660 subdeviceCtrlCmdKGrGetNumTpcsForGpc_IMPL =====

ulong subdeviceCtrlCmdKGrGetNumTpcsForGpc_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  ulong uVar5;
  uint uVar6;
  long local_40;
  undefined1 local_38 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  portMemSet(local_38,0,0x10);
  uVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,local_38,&local_40);
  if ((int)uVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar5 & 0xffffffff,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xdf4);
    return uVar5 & 0xffffffff;
  }
  pcVar4 = *(char **)(local_40 + 0x210);
  if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
    uVar6 = *(uint *)(pcVar4 + 0x110c) - (*(uint *)(pcVar4 + 0x110c) >> 1 & 0x55555555);
    uVar6 = (uVar6 & 0x33333333) + (uVar6 >> 2 & 0x33333333);
    if (*param_2 < ((uVar6 >> 4) + uVar6 & 0xf0f0f0f) * 0x1010101 >> 0x18) {
      param_2[1] = *(uint *)(pcVar4 + (ulong)*param_2 * 4 + 0x1190);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0xdfd,
                   "subdeviceCtrlCmdKGrGetNumTpcsForGpc_IMPL",4,
                   "NVRM: Incorrect GPC-Idx provided = %d\n");
      uVar5 = 0x1f;
    }
    return uVar5;
  }
  nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                      0xdf8);
  return 0x40;
}


// ===== 003657d0 subdeviceCtrlCmdKGrGetPpcMask_IMPL =====

ulong subdeviceCtrlCmdKGrGetPpcMask_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 uVar7;
  long local_40 [2];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar7 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar2 = *(undefined8 *)(lVar1 + 0x1bc8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') ||
     (cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xe1a);
    return 0x2f;
  }
  cVar4 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar1,uVar3,uVar7);
  if (cVar4 == '\0') {
    uVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar2,uVar7,param_2,local_40);
    if ((int)uVar5 == 0) {
      pcVar6 = *(char **)(local_40[0] + 0x210);
      if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
        if (*(long *)(pcVar6 + 0x13c8) == 0) {
          nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pPpcMasks != NULL",
                              "src/kernel/gpu/gr/kernel_graphics.c",0xe28);
        }
        else {
          if (*(long *)(pcVar6 + 8) != 0) {
            if (*(uint *)(param_2 + 0x10) < *(uint *)(*(long *)(pcVar6 + 8) + 0xa4)) {
              *(undefined4 *)(param_2 + 0x14) =
                   *(undefined4 *)
                    (*(long *)(pcVar6 + 0x13c8) + (ulong)*(uint *)(param_2 + 0x10) * 4);
              return uVar5;
            }
            nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0xe2e,
                         "subdeviceCtrlCmdKGrGetPpcMask_IMPL",4,
                         "NVRM: Incorrect GPC-Idx provided = %d\n");
            return 0x1f;
          }
          nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pGrInfo != NULL",
                              "src/kernel/gpu/gr/kernel_graphics.c",0xe29);
        }
        return 0x56;
      }
      nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                          0xe27);
      return 0x40;
    }
    uVar7 = 0xe23;
    pcVar6 = 
    "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
    ;
  }
  else {
    uVar5 = kgrmgrGetLegacyPpcMask_IMPL(lVar1,uVar2,*(undefined4 *)(param_2 + 0x10),param_2 + 0x14);
    uVar7 = 0xe1f;
    pcVar6 = 
    "kgrmgrGetLegacyPpcMask(pGpu, pKernelGraphicsManager, pParams->gpcId, &pParams->ppcMask)";
    if ((int)uVar5 == 0) {
      return uVar5;
    }
  }
  nvCheckOkFailedNoLog(4,uVar5 & 0xffffffff,pcVar6,"src/kernel/gpu/gr/kernel_graphics.c",uVar7);
  return uVar5 & 0xffffffff;
}


// ===== 003659f0 subdeviceCtrlCmdKGrFecsBindEvtbufForUid_IMPL =====

ulong subdeviceCtrlCmdKGrFecsBindEvtbufForUid_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  bool bVar7;
  undefined8 local_40 [2];
  
  local_40[0] = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  if ((lVar2 == 0) || (*(long *)(lVar2 + 0x1bc0) == 0)) {
    bVar7 = false;
    cVar3 = rmapiLockIsOwner();
  }
  else {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2);
    bVar7 = cVar3 != '\0';
    cVar3 = rmapiLockIsOwner();
  }
  if ((cVar3 != '\0') &&
     (cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4)), cVar3 != '\0')) {
    uVar4 = serverutilGetResourceRefWithType(uVar1,*param_2,0x63502b,local_40);
    if (uVar4 == 0) {
      lVar5 = serverutilGetClientUnderLock(uVar1);
      if (lVar5 == 0) {
        nvAssertFailedNoLog("pClient != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xe53);
        uVar6 = 0x23;
      }
      else {
        uVar6 = 0x56;
        if (!bVar7) {
          uVar6 = fecsAddBindpoint(lVar2,lVar5,local_40[0],param_1,*(undefined1 *)(param_2 + 4),
                                   param_2[2],param_2[3],1,0);
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar4,
                 "serverutilGetResourceRefWithType(hClient, pParams->hEventBuffer, classId(EventBuffer), &pEventBufferRef)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xe4f);
      uVar6 = (ulong)uVar4;
    }
    return uVar6;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0xe4c);
  return 0x2f;
}


// ===== 00365b70 subdeviceCtrlCmdKGrFecsBindEvtbufForUidV2_IMPL =====

ulong subdeviceCtrlCmdKGrFecsBindEvtbufForUidV2_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 local_30;
  
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  param_2[5] = 0;
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4));
    if (cVar3 != '\0') {
      uVar4 = serverutilGetResourceRefWithType(uVar1,*param_2,0x63502b,&local_30);
      if (uVar4 == 0) {
        lVar5 = serverutilGetClientUnderLock(uVar1);
        if (lVar5 == 0) {
          nvAssertFailedNoLog("pClient != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xe80);
          uVar6 = 0x23;
        }
        else {
          uVar6 = fecsAddBindpoint(lVar2,lVar5,local_30,param_1,*(undefined1 *)(param_2 + 4),
                                   param_2[2],param_2[3],2,param_2 + 5);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar4,
                   "serverutilGetResourceRefWithType(hClient, pParams->hEventBuffer, classId(EventBuffer), &pEventBufferRef)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0xe7c);
        uVar6 = (ulong)uVar4;
      }
      return uVar6;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0xe79);
  return 0x2f;
}


// ===== 00365cc0 subdeviceCtrlCmdKGrGetPhysGpcMask_IMPL =====

int subdeviceCtrlCmdKGrGetPhysGpcMask_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 uVar7;
  undefined1 local_3c [4];
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar7 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar2 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') ||
     (cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xea2);
    return 0x2f;
  }
  if ((*(long *)(lVar1 + 0x1bc0) == 0) || (cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar1), cVar3 == '\0'))
  {
    uVar5 = 0;
  }
  else {
    cVar3 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar1,uVar2,uVar7);
    if (cVar3 == '\0') {
      iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar2,uVar7,&local_38);
      uVar7 = 0xebe;
      pcVar6 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
      if (iVar4 != 0) {
LAB_00365e99:
        nvCheckOkFailedNoLog(4,iVar4,pcVar6,"src/kernel/gpu/gr/kernel_graphics.c",uVar7);
        return iVar4;
      }
      iVar4 = kmigmgrGetGlobalToLocalEngineType_IMPL
                        (lVar1,uVar2,local_38,local_30,*param_2 + 1,local_3c);
      if (iVar4 != 0) {
        uVar7 = 0xec2;
        pcVar6 = 
        "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(pParams->physSyspipeId), &localRmEngineType)"
        ;
        goto LAB_00365e99;
      }
      uVar5 = (ulong)*param_2;
      if (7 < *param_2) goto LAB_00365e68;
    }
    else {
      uVar5 = (ulong)*param_2;
      if (7 < *param_2) {
        nvAssertFailedNoLog("pParams->physSyspipeId < GPU_MAX_GRS",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xeb2);
        return 0x1f;
      }
    }
  }
  lVar1 = *(long *)(lVar1 + 0x1bd0 + uVar5 * 8);
  if (lVar1 != 0) {
    pcVar6 = *(char **)(lVar1 + 0x210);
    if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
      param_2[1] = *(uint *)(pcVar6 + 0x1210);
      return 0;
    }
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                        0xecd);
    return 0x40;
  }
LAB_00365e68:
  nvAssertFailedNoLog("pKernelGraphics != NULL","src/kernel/gpu/gr/kernel_graphics.c",0xecb);
  return 0x40;
}


// ===== 00365eb0 subdeviceCtrlCmdKGrGetZcullMask_IMPL =====

ulong subdeviceCtrlCmdKGrGetZcullMask_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  ulong uVar8;
  long local_50;
  undefined1 local_48 [24];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
  cVar6 = rmapiLockIsOwner();
  if (cVar6 != '\0') {
    cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
    if (cVar6 != '\0') {
      cVar6 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar1,uVar4,uVar2);
      if (cVar6 == '\0') {
        portMemSet(local_48,0,0x10);
        uVar8 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,local_48,&local_50);
        if ((int)uVar8 == 0) {
          pcVar5 = *(char **)(local_50 + 0x210);
          if ((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) {
            nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                                "src/kernel/gpu/gr/kernel_graphics.c",0xef7);
            uVar8 = 0x40;
          }
          else if (*param_2 < *(uint *)(*(long *)(pcVar5 + 8) + 0xa4)) {
            if (*(uint *)(pcVar5 + (ulong)*param_2 * 4 + 0x133c) != 0xffffffff) {
              param_2[1] = *(uint *)(pcVar5 + (ulong)*param_2 * 4 + 0x133c);
              return uVar8;
            }
            uVar8 = 0x56;
          }
          else {
            nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics.c",0xefc,
                         "subdeviceCtrlCmdKGrGetZcullMask_IMPL",4,
                         "NVRM: Incorrect GPC-Idx provided = %d\n");
            uVar8 = 0x1f;
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,uVar8 & 0xffffffff,
                     "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
                     ,"src/kernel/gpu/gr/kernel_graphics.c",0xef3);
          uVar8 = uVar8 & 0xffffffff;
        }
      }
      else {
        uVar7 = kgrmgrGetLegacyZcullMask_IMPL(lVar1,uVar3,*param_2);
        param_2[1] = uVar7;
        uVar8 = 0;
      }
      return uVar8;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0xee9);
  return 0x2f;
}


// ===== 00366090 subdeviceCtrlCmdKGrGetZcullInfo_IMPL =====

int subdeviceCtrlCmdKGrGetZcullInfo_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  long local_40;
  undefined1 local_38 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  lVar3 = *(long *)(lVar1 + 0x1bc8);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/gr/kernel_graphics.c",0xf21);
    return 0x2f;
  }
  if (lVar3 != 0) {
    portMemSet(local_38,0,0x10);
    iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,lVar3,uVar2,local_38,&local_40);
    if (iVar6 == 0) {
      pcVar4 = *(char **)(local_40 + 0x210);
      if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xf2d);
        return 0x40;
      }
      if (*(long *)(pcVar4 + 0x13d0) == 0) {
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pZcullInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xf2e);
        return 0x56;
      }
      portMemCopy(param_2,0x28,*(long *)(pcVar4 + 0x13d0),0x28);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xf29);
    }
    return iVar6;
  }
  return 0x56;
}


// ===== 00366210 subdeviceCtrlCmdKGrCtxswPmMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdKGrCtxswPmMode_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 uVar7;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar1 + 0x909) == '\0') {
    return 0;
  }
  local_38 = *(undefined8 *)(param_2 + 2);
  local_30 = *(undefined8 *)(param_2 + 4);
  uVar7 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') ||
     (cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xf4b);
    return 0x2f;
  }
  if (param_2[1] != 0) {
    kgrmgrCtrlSetChannelHandle_IMPL(*param_2,&local_38);
    uVar4 = kgrmgrCtrlRouteKGRWithDevice_IMPL
                      (lVar1,uVar7,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),&local_38,
                       &local_50);
    uVar7 = 0xf51;
    pcVar6 = 
    "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, GPU_RES_GET_DEVICE(pSubdevice), &grRouteInfo, &pKernelGraphics)"
    ;
    if (uVar4 == 0) {
      uVar4 = kchannelGetFromDualHandleRestricted_IMPL
                        (**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),*param_2,&local_48,
                         "src/kernel/gpu/gr/kernel_graphics.c",0xf51);
      if (uVar4 == 0) {
        uVar4 = kgrctxFromKernelChannel_IMPL(local_48,&local_40);
        if (uVar4 != 0) {
          nvAssertOkFailedNoLog
                    (uVar4,"kgrctxFromKernelChannel(pKernelChannel, &pKernelGraphicsContext)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0xf5c);
          return (ulong)uVar4;
        }
        uVar4 = kgrctxSetupDeferredPmBuffer_IMPL(lVar1,local_40,local_50,local_48);
        uVar7 = 0xf60;
        pcVar6 = 
        "kgrctxSetupDeferredPmBuffer(pGpu, pKernelGraphicsContext, pKernelGraphics, pKernelChannel)"
        ;
        if (uVar4 == 0) goto LAB_00366293;
      }
      else {
        uVar7 = 0xf58;
        pcVar6 = 
        "kchannelGetFromDualHandleRestricted(RES_GET_CLIENT(pSubdevice), pParams->hChannel, &pKernelChannel)"
        ;
      }
    }
    nvCheckOkFailedNoLog(4,uVar4,pcVar6,"src/kernel/gpu/gr/kernel_graphics.c",uVar7);
    return (ulong)uVar4;
  }
LAB_00366293:
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  uVar5 = (**(code **)(lVar1 + 0x3b90))
                    (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x20801207,
                     param_2,0x18);
  return uVar5;
}


// ===== 00366420 subdeviceCtrlCmdKGrGetROPInfo_IMPL =====

int subdeviceCtrlCmdKGrGetROPInfo_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  long local_40;
  undefined1 local_38 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/gr/kernel_graphics.c",0xf85);
    return 0x2f;
  }
  portMemSet(local_38,0,0x10);
  iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,local_38,&local_40);
  if (iVar6 == 0) {
    pcVar4 = *(char **)(local_40 + 0x210);
    if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
      nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                          0xf8c);
      return 0x40;
    }
    if (*(long *)(pcVar4 + 0x13d8) == 0) {
      iVar6 = 0x56;
      nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pRopInfo != NULL",
                          "src/kernel/gpu/gr/kernel_graphics.c",0xf8d);
    }
    else {
      portMemCopy(param_2,0xc,*(long *)(pcVar4 + 0x13d8),0xc);
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xf88);
  }
  return iVar6;
}


// ===== 00366590 subdeviceCtrlCmdKGrGetAttributeBufferSize_IMPL =====

int subdeviceCtrlCmdKGrGetAttributeBufferSize_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long local_40;
  undefined1 local_38 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xfae);
    return 0x2f;
  }
  portMemSet(local_38,0,0x10);
  iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,local_38,&local_40);
  if (iVar6 == 0) {
    pcVar4 = *(char **)(local_40 + 0x210);
    if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
      nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                          0xfb6);
      return 0x40;
    }
    lVar8 = *(long *)(pcVar4 + 0x13e0);
    if (lVar8 == 0) {
      iVar7 = kgraphicsInitializeDeferredStaticData_IMPL(lVar1,local_40,0,0);
      if (iVar7 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar7,
                   "kgraphicsInitializeDeferredStaticData(pGpu, pKernelGraphics, NV01_NULL_OBJECT, NV01_NULL_OBJECT)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0xfba);
        return iVar7;
      }
      lVar8 = *(long *)(pcVar4 + 0x13e0);
      if (lVar8 == 0) {
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xfbd);
        return 0x40;
      }
    }
    *param_2 = *(undefined4 *)(lVar8 + 0x98);
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics.c",0xfb1);
  }
  return iVar6;
}


// ===== 00366750 subdeviceCtrlCmdKGrGetEngineContextProperties_IMPL =====

int subdeviceCtrlCmdKGrGetEngineContextProperties_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  uint uVar9;
  uint uVar10;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0xfdc);
    return 0x2f;
  }
  iVar6 = 0x1f;
  uVar10 = *(uint *)(param_2 + 0x10) & 0x1f;
  if (uVar10 < 0x1a) {
    iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,&local_30);
    if (iVar6 == 0) {
      pcVar4 = *(char **)(local_30 + 0x210);
      if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics.c",0xfeb);
        return 0x40;
      }
      lVar8 = *(long *)(pcVar4 + 0x13e0);
      if (lVar8 == 0) {
        iVar7 = kgraphicsInitializeDeferredStaticData_IMPL(lVar1,local_30,0,0);
        if (iVar7 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar7,
                     "kgraphicsInitializeDeferredStaticData(pGpu, pKernelGraphics, NV01_NULL_OBJECT, NV01_NULL_OBJECT)"
                     ,"src/kernel/gpu/gr/kernel_graphics.c",0xfef);
          return iVar7;
        }
        lVar8 = *(long *)(pcVar4 + 0x13e0);
        if (lVar8 == 0) {
          nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                              "src/kernel/gpu/gr/kernel_graphics.c",0xff2);
          return 0x40;
        }
      }
      uVar9 = *(uint *)(lVar8 + (ulong)uVar10 * 8);
      if (uVar9 == 0xffffffff) {
        iVar6 = 0x56;
      }
      else {
        uVar10 = *(uint *)(lVar8 + 4 + (ulong)uVar10 * 8);
        if (*(char *)(param_2 + 0x1c) != '\0') {
          if (uVar9 < *(uint *)(param_2 + 0x18)) {
            uVar9 = *(uint *)(param_2 + 0x18);
          }
          if (uVar10 < *(uint *)(param_2 + 0x14)) {
            uVar10 = *(uint *)(param_2 + 0x14);
          }
        }
        *(uint *)(param_2 + 0x18) = uVar9;
        *(uint *)(param_2 + 0x14) = uVar10;
        *(undefined1 *)(param_2 + 0x1c) = 1;
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0xfe5);
    }
  }
  return iVar6;
}


// ===== 00366980 subdeviceCtrlCmdKGrGetCtxBufferSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdKGrGetCtxBufferSize_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined4 *puVar5;
  char cVar6;
  uint uVar7;
  undefined4 uVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long *plVar13;
  long lVar14;
  ulong uVar15;
  uint local_64;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 local_48 [24];
  
  lVar14 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar2 = **(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
  uVar3 = *(undefined8 *)(lVar14 + 0x1bc8);
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') ||
     (cVar6 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar14 + 0x7a4)), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gr/kernel_graphics.c",0x1026);
    return 0x2f;
  }
  if (*(char *)(lVar14 + 0x908) == '\0') {
    if (*(char *)(lVar14 + 0x4913) != '\0') {
      cVar6 = *(char *)(lVar14 + 0x491e);
      goto joined_r0x00366bb1;
    }
LAB_00366a14:
    portMemSet(local_48,0,0x10);
    kgrmgrCtrlSetChannelHandle_IMPL(*param_2,local_48);
    uVar7 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar14,uVar3,uVar1,local_48,&local_60);
    uVar15 = (ulong)uVar7;
    if (uVar7 == 0) {
      uVar7 = CliGetKernelChannel(uVar2,*param_2,&local_58);
      uVar15 = (ulong)uVar7;
      if (uVar7 == 0) {
        uVar7 = kgrctxFromKernelChannel_IMPL(local_58,&local_50);
        uVar15 = (ulong)uVar7;
        if (uVar7 == 0) {
          uVar7 = kgrctxGetBufferCount_IMPL(lVar14,local_50,local_60,&local_64);
          uVar15 = (ulong)uVar7;
          if (uVar7 == 0) {
            plVar9 = (long *)portMemAllocNonPaged((ulong)local_64 * 0x50);
            if (plVar9 == (long *)0x0) {
              nvCheckFailedNoLog(4,"pCtxBufferInfo != NULL","src/kernel/gpu/gr/kernel_graphics.c",
                                 0x1052);
              uVar15 = 0x51;
            }
            else {
              portMemSet(plVar9,0,(ulong)local_64 * 0x50);
              uVar7 = local_64;
              uVar8 = kchannelGetGfid_IMPL(local_58);
              uVar7 = kgrctxGetCtxBufferInfo_IMPL
                                (lVar14,local_50,local_60,uVar8,uVar7,&local_64,plVar9);
              uVar15 = (ulong)uVar7;
              if (uVar7 == 0) {
                lVar14 = 0;
                if (local_64 != 0) {
                  lVar14 = 0;
                  lVar10 = 0;
                  plVar13 = plVar9;
                  do {
                    lVar4 = *plVar13;
                    lVar11 = 0;
                    if (lVar4 != lVar10) {
                      lVar11 = lVar4;
                    }
                    uVar12 = plVar13[1];
                    if (lVar4 != 0) {
                      uVar12 = (plVar13[1] - 1U) + lVar4 & -lVar4;
                    }
                    plVar13 = plVar13 + 10;
                    lVar14 = lVar14 + lVar11 + uVar12;
                    lVar10 = lVar4;
                  } while (plVar13 != plVar9 + (ulong)local_64 * 10);
                }
                *(long *)(param_2 + 2) = lVar14;
              }
              else {
                nvCheckOkFailedNoLog
                          (4,uVar15,
                           "kgrctxGetCtxBufferInfo(pGpu, pKernelGraphicsContext, pKernelGraphics, kchannelGetGfid(pKernelChannel), bufferCount, &bufferCount, pCtxBufferInfo)"
                           ,"src/kernel/gpu/gr/kernel_graphics.c",0x1058);
              }
            }
            portMemFree(plVar9);
          }
          else {
            nvCheckOkFailedNoLog
                      (4,uVar7,
                       "kgrctxGetBufferCount(pGpu, pKernelGraphicsContext, pKernelGraphics, &bufferCount)"
                       ,"src/kernel/gpu/gr/kernel_graphics.c",0x104e);
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,uVar7,"kgrctxFromKernelChannel(pKernelChannel, &pKernelGraphicsContext)",
                     "src/kernel/gpu/gr/kernel_graphics.c",0x104a);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (1,uVar7,"CliGetKernelChannel(pClient, pParams->hChannel, &pKernelChannel)",
                   "src/kernel/gpu/gr/kernel_graphics.c",0x1047);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,uVar7,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x1042);
    }
  }
  else {
    if (*(char *)(lVar14 + 0x4913) != '\0') {
      cVar6 = *(char *)(lVar14 + 0x491e);
joined_r0x00366bb1:
      if (cVar6 == '\0') goto LAB_00366a14;
    }
    lVar10 = resservGetTlsCallContext();
    puVar5 = *(undefined4 **)(lVar10 + 0x48);
    lVar10 = gpuGetRpc(lVar14);
    if (lVar10 == 0) {
      uVar15 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x1036);
    }
    else {
      if ((*(char *)(lVar14 + 0x909) != '\0') || (*(char *)(lVar14 + 0x90a) != '\0')) {
        uVar15 = (**(code **)(lVar14 + 0x3b90))(lVar14 + 0x3b58);
        return uVar15;
      }
      uVar7 = rpcDmaControl_wrapper
                        (lVar14,lVar10,*puVar5,puVar5[1],puVar5[2],*(undefined8 *)(puVar5 + 4),
                         puVar5[6]);
      uVar15 = (ulong)uVar7;
    }
  }
  return uVar15;
}


// ===== 00366d90 subdeviceCtrlCmdKGrGetCtxBufferInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdKGrGetCtxBufferInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  ulong uVar6;
  long lVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  undefined1 local_38 [24];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar10 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0x1092);
    return 0x2f;
  }
  if (*(char *)(lVar1 + 0x908) == '\0') {
    if (*(char *)(lVar1 + 0x4913) != '\0') {
      cVar3 = *(char *)(lVar1 + 0x491e);
      goto joined_r0x00366f27;
    }
LAB_00366dfc:
    uVar4 = serverGetClientUnderLock(g_resServ,*param_2,&local_58);
    uVar9 = 0x10ab;
    pcVar8 = "serverGetClientUnderLock(&g_resServ, pParams->hUserClient, &pUserClient)";
    if (uVar4 == 0) {
      uVar4 = CliGetKernelChannel(local_58,param_2[1],&local_48,
                                  "src/kernel/gpu/gr/kernel_graphics.c",0x10ab);
      if (uVar4 == 0) {
        portMemSet(local_38,0,0x10);
        kgrmgrCtrlSetChannelHandle_IMPL(param_2[1],local_38);
        uVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL
                          (lVar1,uVar10,*(undefined8 *)(*(long *)(local_48 + 0x158) + 0xe8),local_38
                           ,&local_50);
        uVar10 = 0x10b4;
        pcVar8 = 
        "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, GPU_RES_GET_DEVICE(pKernelChannel), &grRouteInfo, &pKernelGraphics)"
        ;
        if ((int)uVar6 == 0) {
          uVar6 = kgrctxFromKernelChannel_IMPL
                            (local_48,&local_40,
                             "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, GPU_RES_GET_DEVICE(pKernelChannel), &grRouteInfo, &pKernelGraphics)"
                             ,"src/kernel/gpu/gr/kernel_graphics.c",0x10b4);
          uVar10 = 0x10b9;
          pcVar8 = "kgrctxFromKernelChannel(pKernelChannel, &pKernelGraphicsContext)";
          if ((int)uVar6 == 0) {
            uVar5 = kchannelGetGfid_IMPL(local_48);
            uVar6 = kgrctxGetCtxBufferInfo_IMPL
                              (lVar1,local_40,local_50,uVar5,0x40,param_2 + 2,param_2 + 4);
            if ((int)uVar6 == 0) {
              return uVar6;
            }
            uVar10 = 0x10bc;
            pcVar8 = 
            "kgrctxGetCtxBufferInfo(pGpu, pKernelGraphicsContext, pKernelGraphics, kchannelGetGfid(pKernelChannel), NV_ARRAY_ELEMENTS(pParams->ctxBufferInfo), &pParams->bufferCount, pParams->ctxBufferInfo)"
            ;
          }
        }
        nvCheckOkFailedNoLog
                  (4,uVar6 & 0xffffffff,pcVar8,"src/kernel/gpu/gr/kernel_graphics.c",uVar10);
        return uVar6 & 0xffffffff;
      }
      uVar9 = 0x10af;
      pcVar8 = "CliGetKernelChannel(pUserClient, pParams->hChannel, &pKernelChannel)";
    }
    nvCheckOkFailedNoLog(1,uVar4,pcVar8,"src/kernel/gpu/gr/kernel_graphics.c",uVar9);
    uVar6 = (ulong)uVar4;
  }
  else {
    if (*(char *)(lVar1 + 0x4913) != '\0') {
      cVar3 = *(char *)(lVar1 + 0x491e);
joined_r0x00366f27:
      if (cVar3 == '\0') goto LAB_00366dfc;
    }
    lVar7 = resservGetTlsCallContext();
    puVar2 = *(undefined4 **)(lVar7 + 0x48);
    lVar7 = gpuGetRpc(lVar1);
    if (lVar7 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x10a1);
      uVar6 = 0x1a;
    }
    else {
      if ((*(char *)(lVar1 + 0x909) != '\0') || (*(char *)(lVar1 + 0x90a) != '\0')) {
        uVar6 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
        return uVar6;
      }
      uVar6 = rpcDmaControl_wrapper
                        (lVar1,lVar7,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
    }
  }
  return uVar6;
}


// ===== 00367070 subdeviceCtrlCmdKGrGetCtxBufferPtes_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdKGrGetCtxBufferPtes_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  char cVar5;
  uint uVar6;
  undefined4 uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  undefined1 local_38 [16];
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar13 = *(undefined8 *)(lVar3 + 0x1bc8);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics.c",0x10de);
    return 0x2f;
  }
  if (*(char *)(lVar3 + 0x908) == '\0') {
    if (*(char *)(lVar3 + 0x4913) == '\0') goto LAB_003670e1;
    cVar5 = *(char *)(lVar3 + 0x491e);
  }
  else {
    if (*(char *)(lVar3 + 0x4913) == '\0') goto LAB_0036722d;
    cVar5 = *(char *)(lVar3 + 0x491e);
  }
  if (cVar5 != '\0') {
LAB_0036722d:
    lVar9 = resservGetTlsCallContext();
    lVar9 = *(long *)(lVar9 + 0x48);
    plVar4 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
    uVar1 = (undefined4)plVar4[2];
    uVar2 = *(undefined4 *)(*plVar4 + 0x48);
    lVar10 = gpuGetRpc(lVar3);
    if (lVar10 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gr/kernel_graphics.c",0x10f3);
      uVar8 = 0x1a;
    }
    else {
      if ((*(char *)(lVar3 + 0x909) != '\0') || (*(char *)(lVar3 + 0x90a) != '\0')) {
        uVar8 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,uVar2,uVar1);
        return uVar8;
      }
      uVar8 = rpcDmaControl_wrapper
                        (lVar3,lVar10,uVar2,uVar1,*(undefined4 *)(lVar9 + 8),
                         *(undefined8 *)(lVar9 + 0x10),*(undefined4 *)(lVar9 + 0x18));
    }
    return uVar8;
  }
LAB_003670e1:
  uVar6 = serverGetClientUnderLock(g_resServ,*param_2,&local_58);
  uVar12 = 0x10fd;
  pcVar11 = "serverGetClientUnderLock(&g_resServ, pParams->hUserClient, &pUserClient)";
  if (uVar6 == 0) {
    uVar6 = CliGetKernelChannel(local_58,param_2[1],&local_48,"src/kernel/gpu/gr/kernel_graphics.c",
                                0x10fd);
    if (uVar6 == 0) {
      portMemSet(local_38,0,0x10);
      kgrmgrCtrlSetChannelHandle_IMPL(param_2[1],local_38);
      uVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL
                        (lVar3,uVar13,*(undefined8 *)(*(long *)(local_48 + 0x158) + 0xe8),local_38,
                         &local_50);
      uVar12 = 0x1106;
      pcVar11 = 
      "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, GPU_RES_GET_DEVICE(pKernelChannel), &grRouteInfo, &pKernelGraphics)"
      ;
      if (uVar6 == 0) {
        uVar8 = kgrctxFromKernelChannel_IMPL(local_48,&local_40);
        uVar13 = 0x110b;
        pcVar11 = "kgrctxFromKernelChannel(pKernelChannel, &pKernelGraphicsContext)";
        if ((int)uVar8 == 0) {
          uVar1 = param_2[3];
          uVar2 = param_2[2];
          uVar7 = kchannelGetGfid_IMPL(local_48);
          uVar8 = kgrctxGetCtxBufferPtes_IMPL
                            (lVar3,local_40,local_50,uVar7,uVar2,uVar1,param_2 + 6,0x80,param_2 + 4,
                             param_2 + 0x106);
          if ((int)uVar8 == 0) {
            return uVar8;
          }
          uVar13 = 0x110e;
          pcVar11 = 
          "kgrctxGetCtxBufferPtes(pGpu, pKernelGraphicsContext, pKernelGraphics, kchannelGetGfid(pKernelChannel), pParams->bufferType, pParams->firstPage, pParams->physAddrs, NV_ARRAY_ELEMENTS(pParams->physAddrs), &pParams->numPages, &pParams->bNoMorePages)"
          ;
        }
        nvCheckOkFailedNoLog
                  (4,uVar8 & 0xffffffff,pcVar11,"src/kernel/gpu/gr/kernel_graphics.c",uVar13);
        return uVar8 & 0xffffffff;
      }
    }
    else {
      uVar12 = 0x1101;
      pcVar11 = "CliGetKernelChannel(pUserClient, pParams->hChannel, &pKernelChannel)";
    }
  }
  nvCheckOkFailedNoLog(1,uVar6,pcVar11,"src/kernel/gpu/gr/kernel_graphics.c",uVar12);
  return (ulong)uVar6;
}


// ===== 003673a0 subdeviceCtrlCmdKGrGetGfxGpcAndTpcInfo_IMPL =====

ulong subdeviceCtrlCmdKGrGetGfxGpcAndTpcInfo_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  char cVar5;
  ulong uVar6;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 != '\0') {
    cVar5 = rmGpuLockIsOwner();
    if (cVar5 != '\0') {
      uVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,&local_30);
      if ((int)uVar6 == 0) {
        pcVar4 = *(char **)(local_30 + 0x210);
        if ((pcVar4 == (char *)0x0) || (*pcVar4 == '\0')) {
          nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                              "src/kernel/gpu/gr/kernel_graphics.c",0x1138);
          return 0x40;
        }
        *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(pcVar4 + 0x13bc);
        *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(pcVar4 + 0x13c0);
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar6 & 0xffffffff,
                   "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                   ,"src/kernel/gpu/gr/kernel_graphics.c",0x1132);
        uVar6 = uVar6 & 0xffffffff;
      }
      return uVar6;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_graphics.c",0x1130);
  return 0x2f;
}


// ===== 003674d0 subdeviceCtrlCmdGrInternalSetFecsTraceHwEnable_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGrInternalSetFecsTraceHwEnable_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar4 != '\0') {
    iVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,&local_30);
    if (iVar5 == 0) {
      (**(code **)(local_30 + 0x1e8))(lVar1,local_30,*(undefined1 *)(param_2 + 0x10));
      *(undefined1 *)(local_30 + 0x1f9) = *(undefined1 *)(param_2 + 0x10);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x1155);
    }
    return iVar5;
  }
  nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0x1152);
  return 0x2f;
}


// ===== 003675c0 subdeviceCtrlCmdGrInternalGetFecsTraceHwEnable_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGrInternalGetFecsTraceHwEnable_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar4 != '\0') {
    iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,&local_30);
    if (iVar6 == 0) {
      uVar5 = (**(code **)(local_30 + 0x1f0))(lVar1);
      *(undefined1 *)(param_2 + 0x10) = uVar5;
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x1171);
    }
    return iVar6;
  }
  nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0x116e);
  return 0x2f;
}


// ===== 003676a0 subdeviceCtrlCmdGrInternalSetFecsTraceRdOffset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGrInternalSetFecsTraceRdOffset_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar4 != '\0') {
    iVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,&local_30);
    if (iVar5 == 0) {
      (**(code **)(local_30 + 0x1d8))(lVar1,local_30,*(undefined4 *)(param_2 + 0x10));
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x118c);
    }
    return iVar5;
  }
  nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0x1189);
  return 0x2f;
}


// ===== 00367780 subdeviceCtrlCmdGrInternalGetFecsTraceRdOffset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGrInternalGetFecsTraceRdOffset_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar4 != '\0') {
    iVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,&local_30);
    if (iVar5 == 0) {
      uVar6 = (**(code **)(local_30 + 0x1d0))(lVar1);
      *(undefined4 *)(param_2 + 0x10) = uVar6;
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x11a7);
    }
    return iVar5;
  }
  nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0x11a4);
  return 0x2f;
}


// ===== 00367860 subdeviceCtrlCmdGrInternalSetFecsTraceWrOffset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGrInternalSetFecsTraceWrOffset_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  long local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  uVar3 = *(undefined8 *)(lVar1 + 0x1bc8);
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4));
  if (cVar4 != '\0') {
    iVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar1,uVar3,uVar2,param_2,&local_30);
    if (iVar5 == 0) {
      (**(code **)(local_30 + 0x1e0))(lVar1,local_30,*(undefined4 *)(param_2 + 0x10));
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &pParams->grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics.c",0x11c2);
    }
    return iVar5;
  }
  nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/gr/kernel_graphics.c",0x11bf);
  return 0x2f;
}


// ===== 00367940 kgraphicsIsCtxswLoggingEnabled_FWCLIENT =====

void kgraphicsIsCtxswLoggingEnabled_FWCLIENT
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6)

{
  ulong uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 local_48;
  undefined1 local_40;
  
  uVar2 = 0;
  if (*(long *)(param_1 + 0x3c70) != 0) {
    iVar3 = 10;
    portMemSet(&local_48,0,0x10);
    do {
      uVar1 = *(ulong *)(*(long *)(param_1 + 0x3c70) + 0x38);
      LOCK();
      UNLOCK();
      if ((uVar1 - 1 < 0xfeffffffffffffff) || ((0xfeffffffffffffff < uVar1 && ((uVar1 & 1) == 0))))
      {
        portMemCopy(&local_48,0x10,*(long *)(param_1 + 0x3c70) + 0x38,0x10,param_5,param_6,
                    in_stack_ffffffffffffffa8);
        LOCK();
        UNLOCK();
        uVar2 = local_40;
        if (*(ulong *)(*(long *)(param_1 + 0x3c70) + 0x38) == uVar1) break;
        local_48 = 0;
      }
      iVar3 = iVar3 + -1;
      uVar2 = local_40;
    } while (iVar3 != 0);
  }
  *(undefined1 *)(param_2 + 0x1f9) = uVar2;
  return;
}


// ===== 00367a40 kgraphicsSetContextBufferPteKind_IMPL =====

void kgraphicsSetContextBufferPteKind_IMPL(void)

{
  return;
}


// ===== 00367a50 shrkgrctxConstructUnicast_IMPL.part.0 =====

int shrkgrctxConstructUnicast_IMPL_part_0(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = vaListInit(param_2 + 0x20);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"vaListInit(&pKernelGraphicsContextUnicast->ctxPatchBuffer.vAddrList)",
               "src/kernel/gpu/gr/kernel_graphics_context.c",0xde4);
    return iVar1;
  }
  iVar1 = vaListInit(param_2 + 0xb0);
  if (iVar1 == 0) {
    iVar1 = vaListInit(param_2 + 0x68);
    if (iVar1 == 0) {
      iVar1 = vaListInit(param_2 + 1000);
      if (iVar1 == 0) {
        iVar1 = vaListInit(param_2 + 0x430);
        if (iVar1 == 0) {
          iVar1 = vaListInit(param_2 + 0x478);
          if (iVar1 == 0) {
            iVar1 = vaListInit(param_2 + 0x4c0);
            if (iVar1 == 0) {
              iVar1 = vaListInit(param_2 + 0x508);
              if (iVar1 == 0) {
                if ((*(char *)(param_1 + 0x1fd) != '\0') &&
                   (iVar2 = vaListInit(param_2 + 0x550), iVar2 != 0)) {
                  nvAssertOkFailedNoLog
                            (iVar2,
                             "vaListInit(&pKernelGraphicsContextUnicast->setupCtxswBuffer.vAddrList)"
                             ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xdee);
                  return iVar2;
                }
                *(undefined1 *)(param_2 + 0x591) = *(undefined1 *)(param_1 + 0x205);
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar1,
                           "vaListInit(&pKernelGraphicsContextUnicast->rtvCbCtxswBuffer.vAddrList)",
                           "src/kernel/gpu/gr/kernel_graphics_context.c",0xdec);
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar1,
                         "vaListInit(&pKernelGraphicsContextUnicast->pagepoolCtxswBuffer.vAddrList)"
                         ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xdeb);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar1,
                       "vaListInit(&pKernelGraphicsContextUnicast->betaCBCtxswBuffer.vAddrList)",
                       "src/kernel/gpu/gr/kernel_graphics_context.c",0xdea);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar1,"vaListInit(&pKernelGraphicsContextUnicast->spillCtxswBuffer.vAddrList)",
                     "src/kernel/gpu/gr/kernel_graphics_context.c",0xde9);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar1,"vaListInit(&pKernelGraphicsContextUnicast->preemptCtxswBuffer.vAddrList)",
                   "src/kernel/gpu/gr/kernel_graphics_context.c",0xde8);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,"vaListInit(&pKernelGraphicsContextUnicast->zcullCtxswBuffer.vAddrList)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0xde6);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,"vaListInit(&pKernelGraphicsContextUnicast->pmCtxswBuffer.vAddrList)",
               "src/kernel/gpu/gr/kernel_graphics_context.c",0xde5);
  }
  return iVar1;
}


// ===== 00367c80 kgrctxFromKernelChannel_IMPL =====

int kgrctxFromKernelChannel_IMPL(long param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  long local_20 [2];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x3c)
    ;
    return 0x1f;
  }
  if (*(int *)(param_1 + 0x2a8) == 0) {
    if ((*(long *)(param_1 + 0x2b8) == 0) ||
       (iVar1 = *(int *)(*(long *)(param_1 + 0x2b8) + 0x148), iVar1 == 0)) {
      return 0x57;
    }
    iVar1 = clientGetResourceRefByType_IMPL
                      (**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),iVar1,0x7ead09,local_20)
    ;
    if (iVar1 != 0) {
      uVar3 = 0x49;
      pcVar4 = 
      "clientGetResourceRefByType(RES_GET_CLIENT(pKernelChannel), pKernelChannel->pKernelChannelGroupApi->hKernelGraphicsContext, classId(KernelGraphicsContext), &pResourceRef)"
      ;
LAB_00367d53:
      nvAssertOkFailedNoLog(iVar1,pcVar4,"src/kernel/gpu/gr/kernel_graphics_context.c",uVar3);
      return iVar1;
    }
  }
  else {
    iVar1 = clientGetResourceRefByType_IMPL
                      (**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                       *(int *)(param_1 + 0x2a8),0x7ead09,local_20);
    uVar3 = 0x40;
    pcVar4 = 
    "clientGetResourceRefByType(RES_GET_CLIENT(pKernelChannel), pKernelChannel->hKernelGraphicsContext, classId(KernelGraphicsContext), &pResourceRef)"
    ;
    if (iVar1 != 0) goto LAB_00367d53;
  }
  lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20[0] + 8),__nvoc_class_def_KernelGraphicsContext
                            );
  *param_2 = lVar2;
  if (lVar2 != 0) {
    return 0;
  }
  nvAssertFailedNoLog("*ppKernelGraphicsContext != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x55);
  return 0x40;
}


// ===== 00367dd0 kgrctxCtrlHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgrctxCtrlHandle(long param_1,undefined8 param_2)

{
  uint uVar1;
  ulong uVar2;
  long local_20 [2];
  
  uVar1 = clientGetResourceRefByType_IMPL(*(undefined8 *)(param_1 + 8),param_2,0x7ead09,local_20);
  if (uVar1 == 0) {
    uVar2 = (**(code **)(**(long **)(local_20[0] + 8) + 0x48))
                      (*(long **)(local_20[0] + 8),param_1,*(undefined8 *)(param_1 + 0x48));
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,
             "clientGetResourceRefByType(pCallContext->pClient, hKernelGraphicsContext, classId(KernelGraphicsContext), &pResourceRef)"
             ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x85);
  return (ulong)uVar1;
}


// ===== 00367e50 kgrctxGetGlobalContextBufferExternalId_IMPL =====

undefined8 kgrctxGetGlobalContextBufferExternalId_IMPL(uint param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    nvAssertFailedNoLog("pExternalId != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x98);
  }
  else {
    if (param_1 < 10) {
      if (param_1 == 5) {
        *param_2 = 8;
      }
      else if (param_1 < 6) {
        if (param_1 == 3) {
          *param_2 = 6;
        }
        else if (param_1 == 4) {
          *param_2 = 7;
        }
        else if (param_1 == 1) {
          *param_2 = 4;
        }
        else {
          *param_2 = (param_1 == 2) + 3 + (uint)(param_1 == 2);
        }
      }
      else if (param_1 == 8) {
        *param_2 = 0xb;
      }
      else if (param_1 == 9) {
        *param_2 = 0xc;
      }
      else {
        *param_2 = (param_1 != 6) + 9;
      }
      return 0;
    }
    nvAssertFailedNoLog("NV_ENUM_IS(GR_GLOBALCTX_BUFFER, id)",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x99);
  }
  return 0x1f;
}


// ===== 00367f60 kgrctxGetGlobalContextBufferInternalId_IMPL =====

undefined8 kgrctxGetGlobalContextBufferInternalId_IMPL(uint param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    nvAssertFailedNoLog("pInternalId != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0xcf);
    return 0x1f;
  }
  if (param_1 == 8) {
    *param_2 = 5;
  }
  else if (param_1 < 9) {
    if (param_1 == 5) {
      *param_2 = 2;
    }
    else {
      if (5 < param_1) {
        *param_2 = (param_1 != 6) + 3;
        return 0;
      }
      if (param_1 == 3) {
        *param_2 = 0;
      }
      else {
        if (param_1 != 4) {
          return 0x1f;
        }
        *param_2 = 1;
      }
    }
  }
  else if (param_1 == 0xb) {
    *param_2 = 8;
  }
  else if (param_1 < 0xc) {
    *param_2 = (param_1 != 9) + 6;
  }
  else {
    if (param_1 != 0xc) {
      return 0x1f;
    }
    *param_2 = 9;
  }
  return 0;
}


// ===== 00368040 kgrctxCtxBufferToFifoEngineId_IMPL =====

undefined8 kgrctxCtxBufferToFifoEngineId_IMPL(uint param_1,int *param_2)

{
  if (9 < param_1) {
    nvAssertFailedNoLog("NV_ENUM_IS(GR_CTX_BUFFER, buffer)",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x106);
    return 0x1f;
  }
  if (param_1 == 5) {
    *param_2 = 0xe;
  }
  else if (param_1 < 6) {
    if (param_1 == 3) {
      *param_2 = 0xb;
    }
    else if (param_1 == 4) {
      *param_2 = 0xc;
    }
    else if (param_1 == 1) {
      *param_2 = 8;
    }
    else {
      *param_2 = (uint)(param_1 == 2) * 9;
    }
  }
  else if (param_1 == 8) {
    *param_2 = 0x10;
  }
  else {
    if (param_1 != 9) {
      *param_2 = (param_1 != 6) + 0xd + (uint)(param_1 != 6);
      return 0;
    }
    *param_2 = 0x19;
  }
  return 0;
}


// ===== 00368120 kgrctxGlobalCtxBufferToFifoEngineId_IMPL =====

undefined8 kgrctxGlobalCtxBufferToFifoEngineId_IMPL(uint param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    nvAssertFailedNoLog("pFifoEngineId != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x138)
    ;
  }
  else {
    if (param_1 < 10) {
      if (param_1 == 4) {
        *param_2 = 0x15;
      }
      else if (param_1 < 5) {
        if (param_1 == 2) {
          *param_2 = 0x13;
        }
        else if (param_1 == 3) {
          *param_2 = 0x14;
        }
        else {
          *param_2 = (param_1 == 1) + 0x11;
        }
      }
      else if (param_1 == 6) {
        *param_2 = 0x17;
      }
      else {
        *param_2 = (-(uint)(param_1 < 7) & 0xfffffffe) + 0x18;
      }
      return 0;
    }
    nvAssertFailedNoLog("NV_ENUM_IS(GR_GLOBALCTX_BUFFER, buffId)",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x139);
  }
  return 0x1f;
}


// ===== 00368200 kgrctxGetGidInfoInPlace_IMPL =====

int kgrctxGetGidInfoInPlace_IMPL(undefined8 param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  int local_34;
  undefined8 local_30 [2];
  
  iVar1 = gpuGetGidInfo_IMPL(param_1,local_30,&local_34);
  if (iVar1 == 0) {
    if (local_34 == param_3) {
      portMemCopy(param_2,param_3,local_30[0],param_3);
    }
    portMemFree(local_30[0]);
    if (local_34 != param_3) {
      iVar1 = 0x1f;
    }
  }
  return iVar1;
}


// ===== 00368270 kgrctxFillCtxBufferInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgrctxFillCtxBufferInfo_IMPL(long *param_1,undefined4 param_2,char param_3,ulong *param_4)

{
  long lVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 local_40 [2];
  
  plVar4 = (long *)memdescGetRootMemDesc(param_1,0);
  *(undefined4 *)(param_4 + 5) = param_2;
  param_4[2] = (ulong)param_1;
  uVar2 = memdescGetContiguity(param_1,1);
  *(undefined1 *)(param_4 + 7) = uVar2;
  uVar3 = memdescGetAddressSpace(param_1);
  *(undefined4 *)((long)param_4 + 0x2c) = uVar3;
  param_4[3] = param_1[3];
  uVar3 = memdescGetPteKindForGpu(param_1,*param_1);
  *(undefined4 *)(param_4 + 6) = uVar3;
  uVar3 = kgmmuGetExternalAllocAperture_IMPL(*(undefined4 *)((long)param_4 + 0x2c));
  memdescGetPhysAddrsForGpu(param_1,*param_1,1,0,0,1,local_40);
  uVar5 = kgmmuEncodePhysAddr_IMPL
                    (*(undefined8 *)(*param_1 + 0x1b98),uVar3,local_40[0],0xffffffffffffffff);
  param_4[4] = uVar5;
  uVar5 = memdescGetPageSize(param_1,1);
  if (uVar5 == 0) {
    lVar1 = *(long *)(*param_1 + 0x1b78);
    uVar6 = (**(code **)(lVar1 + 0x388))(*param_1,lVar1,param_1,1,0);
    if ((int)uVar6 != 0) {
      return uVar6;
    }
    uVar5 = memdescGetPageSize(param_1,1);
    if (uVar5 == 0) {
      nvAssertFailedNoLog("pageSize != 0","src/kernel/gpu/gr/kernel_graphics_context.c",0x1b0);
    }
  }
  uVar7 = param_1[5] + -1 + uVar5 & -uVar5;
  if (param_1[5] == 0) {
    uVar7 = uVar5;
  }
  *param_4 = uVar7;
  uVar7 = param_1[7];
  *(int *)((long)param_4 + 0x34) = (int)uVar5;
  *(bool *)((long)param_4 + 0x3a) = param_3 == '\0';
  param_4[1] = uVar7;
  *(char *)((long)param_4 + 0x39) = param_3;
  lVar1 = *plVar4;
  *(bool *)((long)param_4 + 0x3b) = lVar1 != 0;
  if (lVar1 == 0) {
    return 0;
  }
  uVar6 = kgrctxGetGidInfoInPlace_IMPL(*param_1,(long)param_4 + 0x3c,0x10,2);
  return uVar6;
}


// ===== 00368430 kgrctxGetInternalObjectHandle_IMPL =====

undefined8 kgrctxGetInternalObjectHandle_IMPL(void)

{
  return 0;
}


// ===== 00368440 kgrctxGetUnicast_IMPL =====

undefined8 kgrctxGetUnicast_IMPL(undefined8 param_1,long param_2,long *param_3)

{
  *param_3 = 0;
  if (*(long *)(param_2 + 0x148) != 0) {
    *param_3 = *(long *)(param_2 + 0x148) + 0x98;
    return 0;
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  return 0x40;
}


// ===== 003684c0 kgrctxLookupMmuFaultInfo_IMPL =====

undefined8 kgrctxLookupMmuFaultInfo_IMPL(undefined8 param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  undefined8 *puVar6;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x242);
  }
  else if (*(uint *)(lVar1 + 0x678) < 4) {
    if (*(uint *)(lVar1 + 0x67c) < 4) {
      *(undefined4 *)(param_3 + 8) = 0;
      uVar3 = *(uint *)(lVar1 + 0x67c);
      if (uVar3 != *(uint *)(lVar1 + 0x678)) {
        iVar4 = 1;
        puVar6 = param_3;
        do {
          uVar5 = (ulong)uVar3;
          uVar3 = uVar3 + 1 & 3;
          uVar2 = *(undefined8 *)(uVar5 * 0x10 + 0x640 + lVar1);
          *puVar6 = *(undefined8 *)(uVar5 * 0x10 + 0x638 + lVar1);
          puVar6[1] = uVar2;
          *(int *)(param_3 + 8) = iVar4;
          iVar4 = iVar4 + 1;
          puVar6 = puVar6 + 2;
        } while (*(uint *)(lVar1 + 0x678) != uVar3);
      }
      return 0;
    }
    nvAssertFailedNoLog("pKernelGraphicsContextUnicast->mmuFault.tail < size",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x246);
  }
  else {
    nvAssertFailedNoLog("pKernelGraphicsContextUnicast->mmuFault.head < size",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x245);
  }
  return 0x40;
}


// ===== 00368600 kgrctxLookupMmuFault_IMPL =====

undefined8 kgrctxLookupMmuFault_IMPL(undefined8 param_1,long param_2,undefined8 *param_3)

{
  if (*(long *)(param_2 + 0x148) != 0) {
    *param_3 = *(undefined8 *)(*(long *)(param_2 + 0x148) + 0x630);
    return 0;
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  nvAssertOkFailedNoLog
            (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0x261);
  return 0x40;
}


// ===== 00368660 kgrctxClearMmuFault_IMPL =====

undefined8 kgrctxClearMmuFault_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x630) = 0;
    *(undefined4 *)(lVar1 + 0x634) = 0;
    return 0;
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  nvAssertOkFailedNoLog
            (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0x274);
  return 0x40;
}


// ===== 003686d0 kgrctxRecordMmuFault_IMPL =====

void kgrctxRecordMmuFault_IMPL
               (undefined8 param_1,long param_2,undefined4 param_3,undefined8 param_4,
               undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  
  lVar2 = *(long *)(param_2 + 0x148);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x28d);
    return;
  }
  *(undefined4 *)(lVar2 + 0x634) = param_3;
  uVar4 = *(uint *)(lVar2 + 0x678);
  *(undefined1 *)(lVar2 + 0x630) = 1;
  if (3 < uVar4) {
    nvAssertFailedNoLog("pKernelGraphicsContextUnicast->mmuFault.head < size",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x297);
    return;
  }
  uVar1 = *(uint *)(lVar2 + 0x67c);
  if (3 < uVar1) {
    nvAssertFailedNoLog("pKernelGraphicsContextUnicast->mmuFault.tail < size",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x298);
    return;
  }
  lVar3 = (ulong)uVar4 * 0x10;
  uVar4 = uVar4 + 1 & 3;
  *(undefined8 *)(lVar2 + 0x638 + lVar3) = param_4;
  *(undefined4 *)(lVar2 + 0x640 + lVar3) = param_5;
  *(undefined4 *)(lVar2 + 0x644 + lVar3) = param_6;
  *(uint *)(lVar2 + 0x678) = uVar4;
  if (uVar1 != uVar4) {
    return;
  }
  *(uint *)(lVar2 + 0x67c) = uVar1 + 1 & 3;
  return;
}


// ===== 003687d0 kgrctxRegisterKernelSMDebuggerSession_IMPL =====

bool kgrctxRegisterKernelSMDebuggerSession_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 local_10;
  
  local_10 = param_3;
  lVar1 = listAppendValue_IMPL(*(long *)(param_2 + 0x148) + 0x680,&local_10);
  return lVar1 != 0;
}


// ===== 00368810 kgrctxDeregisterKernelSMDebuggerSession_IMPL =====

void kgrctxDeregisterKernelSMDebuggerSession_IMPL
               (undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined8 local_10;
  
  local_10 = param_3;
  listRemoveFirstByValue_IMPL(*(long *)(param_2 + 0x148) + 0x680,&local_10);
  return;
}


// ===== 00368840 kgrctxIsValid_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 kgrctxIsValid_IMPL(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  int local_1c;
  
  if (*(int *)(param_3 + 0x42c) - 9U < 0x4b) {
    return 0;
  }
  cVar2 = kchannelIsRunlistSet(param_1,param_3);
  if (cVar2 == '\0') {
    nvCheckFailedNoLog(1,"kchannelIsRunlistSet(pGpu, pKernelChannel)",
                       "src/kernel/gpu/gr/kernel_graphics_context.c",0x2e0);
    uVar5 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 0x2b0);
    lVar4 = gpuGetKernelFifoShared_IMPL(param_1);
    iVar3 = (**(code **)(lVar4 + 0x218))(param_1,lVar4,3,uVar1,2,&local_1c);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "kfifoEngineInfoXlate_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), ENGINE_INFO_TYPE_RUNLIST, runlistId, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *) &engineType)"
                 ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x2e3);
    }
    uVar5 = 1;
    if (7 < local_1c - 1U) {
      nvCheckFailedNoLog(1,"RM_ENGINE_TYPE_IS_GR(engineType)",
                         "src/kernel/gpu/gr/kernel_graphics_context.c",0x2e8);
      return 0;
    }
  }
  return uVar5;
}


// ===== 0036893f kgrctxGetMainContextBuffer_IMPL.cold =====

void kgrctxGetMainContextBuffer_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00368950 kgrctxGetMainContextBuffer_IMPL =====

undefined8 kgrctxGetMainContextBuffer_IMPL(undefined8 param_1,long param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  
  uVar3 = gpumgrGetSubDeviceInstanceFromGpu();
  if (param_2 != 0) {
    lVar4 = *(long *)(*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x18);
    *param_3 = 0;
    lVar4 = __nvoc_dynamicCast(*(undefined8 *)(lVar4 + 8),__nvoc_class_def_KernelChannelGroupApi);
    puVar1 = *(undefined8 **)(*(long *)(*(long *)(lVar4 + 0x138) + 0x150) + (ulong)uVar3 * 8);
    if (puVar1 != (undefined8 *)0x0) {
      *param_3 = *puVar1;
    }
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 003689d0 kgrctxGetCtxBuffers_IMPL =====

undefined8
kgrctxGetCtxBuffers_IMPL
          (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,uint param_5,
          long *param_6,undefined4 *param_7,uint *param_8,uint *param_9)

{
  long lVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  long local_40 [2];
  
  lVar3 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,param_4);
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x32e);
    return 0x40;
  }
  kgrctxGetMainContextBuffer_IMPL(param_1,param_2,local_40);
  if (local_40[0] == 0) {
    nvCheckFailedNoLog(4,"pGrCtxBufferMemDesc != NULL","src/kernel/gpu/gr/kernel_graphics_context.c"
                       ,0x335);
    return 0x31;
  }
  if (param_5 == 0) {
    nvCheckFailedNoLog(1,"bufferCountOut < bufferCount",
                       "src/kernel/gpu/gr/kernel_graphics_context.c",0x339);
  }
  else {
    *param_7 = 0;
    *param_6 = local_40[0];
    if (*(long *)(lVar1 + 0xb0) == 0) {
      return 0x40;
    }
    if (param_5 != 1) {
      param_7[1] = 2;
      param_6[1] = *(long *)(lVar1 + 0xb0);
      if (*(long *)(lVar1 + 0x140) == 0) {
        uVar5 = 2;
      }
      else {
        if (param_5 == 2) {
          nvCheckFailedNoLog(1,"bufferCountOut < bufferCount",
                             "src/kernel/gpu/gr/kernel_graphics_context.c",0x349);
          return 0x1f;
        }
        uVar5 = 3;
        param_7[2] = 1;
        param_6[2] = *(long *)(lVar1 + 0x140);
      }
      if (param_9 != (uint *)0x0) {
        *param_9 = uVar5;
      }
      uVar4 = 0;
      do {
        lVar1 = *(long *)(lVar3 + uVar4 * 8);
        if (lVar1 != 0) {
          if (param_5 <= uVar5) {
            nvCheckFailedNoLog(1,"bufferCountOut < bufferCount",
                               "src/kernel/gpu/gr/kernel_graphics_context.c",0x359);
            return 0x1f;
          }
          iVar2 = kgrctxGetGlobalContextBufferExternalId_IMPL(uVar4 & 0xffffffff,param_7 + uVar5);
          if (iVar2 != 0) {
            nvAssertOkFailedNoLog
                      (0x1f,
                       "kgrctxGetGlobalContextBufferExternalId(i, &pCtxBufferType[bufferCountOut])",
                       "src/kernel/gpu/gr/kernel_graphics_context.c",0x35a);
          }
          param_6[uVar5] = lVar1;
          uVar5 = uVar5 + 1;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 != 10);
      *param_8 = uVar5;
      return 0;
    }
    nvCheckFailedNoLog(1,"bufferCountOut < bufferCount",
                       "src/kernel/gpu/gr/kernel_graphics_context.c",0x342);
  }
  return 0x1f;
}


// ===== 00368ca0 kgrctxGetBufferCount_IMPL =====

int kgrctxGetBufferCount_IMPL(undefined8 param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  long *plVar1;
  int iVar2;
  long *plVar3;
  undefined1 local_2d;
  undefined4 local_2c;
  
  *param_4 = 0;
  iVar2 = vgpuGetCallingContextGfid(param_1,&local_2c);
  if (iVar2 == 0) {
    iVar2 = vgpuIsCallingContextPlugin(param_1,&local_2d);
    if (iVar2 == 0) {
      plVar3 = (long *)kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,local_2c);
      plVar1 = plVar3 + 10;
      do {
        if (*plVar3 != 0) {
          *param_4 = *param_4 + 1;
        }
        plVar3 = plVar3 + 1;
      } while (plVar3 != plVar1);
      *param_4 = *param_4 + 3;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0x37e);
    }
    return iVar2;
  }
  nvAssertOkFailedNoLog
            (iVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0x37d);
  return iVar2;
}


// ===== 00368d80 kgrctxGetCtxBufferInfo_IMPL =====

int kgrctxGetCtxBufferInfo_IMPL(void)

{
  int iVar1;
  int iVar2;
  ulong *puVar3;
  uint in_R8D;
  uint *in_R9;
  ulong *puVar4;
  ulong uVar5;
  uint uVar6;
  ulong *in_stack_00000008;
  uint local_12c;
  uint local_128;
  undefined4 local_124 [13];
  undefined1 local_f0 [80];
  undefined8 local_a0 [14];
  
  iVar1 = kgrctxGetCtxBuffers_IMPL();
  if (iVar1 == 0) {
    iVar2 = 0x1f;
    if (local_12c <= in_R8D) {
      if (local_12c != 0) {
        uVar5 = 0;
        puVar3 = in_stack_00000008;
        do {
          iVar2 = kgrctxFillCtxBufferInfo_IMPL
                            (local_a0[uVar5],local_124[uVar5],local_128 <= (uint)uVar5,puVar3);
          if (iVar2 != 0) {
            nvCheckOkFailedNoLog
                      (1,iVar2,
                       "kgrctxFillCtxBufferInfo(pMemDescArray[i], bufferExternalId[i], bGlobalBuffer, &pCtxBufferInfo[i])"
                       ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x3c5);
            return iVar2;
          }
          uVar5 = uVar5 + 1;
          puVar3 = puVar3 + 10;
        } while (uVar5 != local_12c);
        if (local_12c != 1) {
          uVar6 = 0;
          puVar3 = in_stack_00000008;
          do {
            puVar4 = puVar3 + 10;
            if (*puVar3 < puVar3[10]) {
              portMemCopy(local_f0,0x50,puVar3,0x50);
              portMemCopy(puVar3,0x50,puVar4,0x50);
              portMemCopy(puVar4,0x50,local_f0,0x50);
            }
            puVar3 = puVar4;
          } while ((in_stack_00000008 + (ulong)(local_12c - 2) * 10 + 10 != puVar4) ||
                  (uVar6 = uVar6 + 1, puVar3 = in_stack_00000008, local_12c != uVar6));
        }
      }
      *in_R9 = local_12c;
      iVar2 = iVar1;
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "kgrctxGetCtxBuffers(pGpu, pKernelGraphicsContext, pKernelGraphics, gfid, NV_ARRAY_ELEMENTS(pMemDescArray), pMemDescArray, bufferExternalId, &memdescCount, &firstGlobalBuffer)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x3b5);
    iVar2 = iVar1;
  }
  return iVar2;
}


// ===== 00368fa0 kgrctxGetCtxBufferPtes_IMPL =====

int kgrctxGetCtxBufferPtes_IMPL(void)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  int in_R8D;
  uint in_R9D;
  bool bVar9;
  undefined8 in_stack_00000008;
  uint in_stack_00000010;
  uint *in_stack_00000018;
  undefined1 *in_stack_00000020;
  uint local_d8;
  int local_d4 [13];
  long local_a0 [14];
  
  piVar5 = local_d4;
  iVar3 = kgrctxGetCtxBuffers_IMPL();
  if (iVar3 == 0) {
    uVar6 = 0;
    if (local_d8 != 0) {
      do {
        if (*piVar5 == in_R8D) {
          if (in_stack_00000010 == 0) goto LAB_003690bb;
          if ((uint)uVar6 != local_d8) {
            lVar1 = local_a0[uVar6];
            lVar8 = *(long *)(lVar1 + 0x30);
            uVar6 = memdescGetPageSize(lVar1,1);
            if (uVar6 != 0) {
              uVar7 = (lVar8 + -1 + uVar6) - (lVar8 + -1 + uVar6) % uVar6;
              uVar4 = (uint)(uVar7 / uVar6);
              if (in_R9D < uVar4) {
                cVar2 = memdescGetContiguity(lVar1,1,uVar7 % uVar6);
                if (cVar2 == '\0') {
                  uVar4 = uVar4 - in_R9D;
                  bVar9 = uVar4 <= in_stack_00000010;
                  if (in_stack_00000010 <= uVar4) {
                    uVar4 = in_stack_00000010;
                  }
                  lVar8 = in_R9D * uVar6;
                }
                else {
                  lVar8 = 0;
                  bVar9 = true;
                  uVar4 = 1;
                }
                *in_stack_00000020 = bVar9;
                memdescGetPhysAddrs(lVar1,1,lVar8,uVar6,uVar4,in_stack_00000008);
              }
              else {
                uVar4 = 0;
                *in_stack_00000020 = 1;
              }
              *in_stack_00000018 = uVar4;
              return 0;
            }
            return 0x40;
          }
          goto LAB_00369170;
        }
        uVar4 = (uint)uVar6 + 1;
        uVar6 = (ulong)uVar4;
        piVar5 = piVar5 + 1;
      } while (local_d8 != uVar4);
    }
    if (in_stack_00000010 != 0) {
LAB_00369170:
      nvCheckFailedNoLog(4,"i != bufferCount","src/kernel/gpu/gr/kernel_graphics_context.c",0x425);
    }
LAB_003690bb:
    iVar3 = 0x1f;
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar3,
               "kgrctxGetCtxBuffers(pGpu, pKernelGraphicsContext, pKernelGraphics, gfid, NV_ARRAY_ELEMENTS(pMemDescArray), pMemDescArray, bufferExternalId, &bufferCount, NULL)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x411);
  }
  return iVar3;
}


// ===== 003691b0 kgrctxAllocMainCtxBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgrctxAllocMainCtxBuffer_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  ulong uVar8;
  long local_58;
  undefined4 local_44;
  long local_40 [2];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  local_40[0] = 0;
  puVar6 = (undefined8 *)kgraphicsGetContextBufferAttr_IMPL(param_1,param_3,0);
  lVar2 = *(long *)(param_2 + 0x148);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x46e);
    uVar8 = 0x40;
  }
  else {
    uVar4 = kgraphicsGetMainCtxBufferSize_IMPL(param_1,param_3,1,&local_44);
    if (uVar4 == 0) {
      cVar3 = ctxBufPoolIsSupported(param_1);
      if (cVar3 == '\0') {
        local_58 = 0;
        uVar7 = 0x2002000;
      }
      else {
        local_58 = *(long *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 400);
        uVar7 = 0x2002000;
        if (local_58 != 0) {
          uVar7 = 0x1002002000;
        }
      }
      uVar5 = *(undefined4 *)(puVar6 + 1);
      uVar4 = memdescCreate(local_40,param_1,local_44,0x1000,1,0);
      if (uVar4 == 0) {
        if (*(char *)(param_3 + 0x1fc) != '\0') {
          memdescSetGpuCacheAttrib(local_40[0],0,uVar5,uVar7);
        }
        uVar4 = (**(code **)(lVar1 + 0x388))(param_1,lVar1,local_40[0],1,1);
        if (uVar4 == 0) {
          uVar4 = memdescSetCtxBufPool(local_40[0],local_58);
          if (uVar4 == 0) {
            uVar5 = (**(code **)(lVar1 + 0x288))(param_1,lVar1);
            kgraphicsSetContextBufferPteKind_IMPL(param_1,param_3,local_40,0,0,uVar5);
            *(undefined4 *)(local_40[0] + 0x9c) = 0xc;
            uVar4 = memdescAllocList(local_40[0],*puVar6);
            if (uVar4 == 0) {
              uVar8 = kchannelSetEngineContextMemDesc_IMPL
                                (param_1,param_4,*(uint *)(param_3 + 0x20c) | 0xd334df00,local_40[0]
                                );
              uVar4 = (uint)uVar8;
              if (uVar4 == 0) {
                *(long *)(lVar2 + 0x188) = local_40[0];
                return uVar8;
              }
              nvAssertOkFailedNoLog
                        (uVar8 & 0xffffffff,
                         "kchannelSetEngineContextMemDesc(pGpu, pKernelChannel, ENG_GR(kgraphicsGetInstance(pGpu, pKernelGraphics)), pGrCtxBufferMemDesc)"
                         ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x4a1);
            }
            else {
              nvAssertOkFailedNoLog
                        (uVar4,"status","src/kernel/gpu/gr/kernel_graphics_context.c",0x49f);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (uVar4,"memdescSetCtxBufPool(pGrCtxBufferMemDesc, pCtxBufPool)",
                       "src/kernel/gpu/gr/kernel_graphics_context.c",0x499);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar4,
                     "memmgrSetMemDescPageSize_HAL(pGpu, pMemoryManager, pGrCtxBufferMemDesc, AT_GPU, RM_ATTR_PAGE_SIZE_4KB)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x495);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar4,
                   "memdescCreate(&pGrCtxBufferMemDesc, pGpu, ctxSize, RM_PAGE_SIZE, bIsContiguous, ADDR_UNKNOWN, pAttr->cpuAttr, allocFlags | MEMDESC_FLAGS_OWNED_BY_CURRENT_DEVICE)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x487);
      }
      memdescFree(local_40[0]);
      memdescDestroy(local_40[0]);
      uVar8 = (ulong)uVar4;
    }
    else {
      nvAssertOkFailedNoLog
                (uVar4,"kgraphicsGetMainCtxBufferSize(pGpu, pKernelGraphics, NV_TRUE, &ctxSize)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0x47c);
      uVar8 = (ulong)uVar4;
    }
  }
  return uVar8;
}


// ===== 00369500 kgrctxAllocPatchBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgrctxAllocPatchBuffer_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  ulong uVar9;
  long local_48;
  
  lVar6 = kgraphicsGetStaticInfo_IMPL(param_1,param_3);
  lVar2 = *(long *)(param_1 + 0x1b78);
  puVar7 = (undefined8 *)kgraphicsGetContextBufferAttr_IMPL(param_1,param_3,8);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pStaticInfo != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x4c8);
  }
  else if (*(long *)(lVar6 + 0x13d8) == 0) {
    nvAssertFailedNoLog("pStaticInfo->pContextBuffersInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x4c9);
  }
  else {
    lVar3 = *(long *)(param_2 + 0x148);
    if (lVar3 != 0) {
      cVar4 = ctxBufPoolIsSupported(param_1);
      if (cVar4 == '\0') {
        local_48 = 0;
        uVar8 = 0x2000000;
      }
      else {
        local_48 = *(long *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 400);
        uVar8 = 0x2000000;
        if (local_48 != 0) {
          uVar8 = 0x1002000000;
        }
      }
      uVar1 = *(undefined4 *)(puVar7 + 1);
      uVar5 = memdescCreate(lVar3 + 0xb0,param_1,*(undefined4 *)(*(long *)(lVar6 + 0x13d8) + 0x80),
                            0x1000,1,0);
      if (uVar5 == 0) {
        if (*(char *)(param_3 + 0x1fc) != '\0') {
          memdescSetGpuCacheAttrib(*(undefined8 *)(lVar3 + 0xb0),0,uVar1,uVar8);
        }
        (**(code **)(lVar2 + 0x388))(param_1,lVar2,*(undefined8 *)(lVar3 + 0xb0),1,1);
        uVar5 = memdescSetCtxBufPool(*(undefined8 *)(lVar3 + 0xb0),local_48);
        if (uVar5 == 0) {
          *(undefined4 *)(*(long *)(lVar3 + 0xb0) + 0x9c) = 0x96;
          uVar9 = memdescAllocList(*(undefined8 *)(lVar3 + 0xb0),*puVar7);
          uVar5 = (uint)uVar9;
          if (uVar5 == 0) {
            return uVar9;
          }
          nvCheckOkFailedNoLog
                    (4,uVar9 & 0xffffffff,"status","src/kernel/gpu/gr/kernel_graphics_context.c",
                     0x4ec);
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar5,"memdescSetCtxBufPool(*ppMemDesc, pCtxBufPool)",
                     "src/kernel/gpu/gr/kernel_graphics_context.c",0x4e6);
        }
        memdescFree(*(undefined8 *)(lVar3 + 0xb0));
        memdescDestroy(*(undefined8 *)(lVar3 + 0xb0));
        *(undefined8 *)(lVar3 + 0xb0) = 0;
        return (ulong)uVar5;
      }
      nvCheckOkFailedNoLog
                (4,uVar5,
                 "memdescCreate(ppMemDesc, pGpu, size, RM_PAGE_SIZE, NV_TRUE, ADDR_UNKNOWN, pAttr->cpuAttr, flags)"
                 ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x4d8);
      return (ulong)uVar5;
    }
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x4cb);
  }
  return 0x40;
}


// ===== 003697f0 kgrctxAllocPmBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgrctxAllocPmBuffer_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  uint uVar6;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  char *pcVar10;
  undefined8 uVar11;
  
  lVar7 = kgraphicsGetStaticInfo_IMPL(param_1,param_3);
  lVar3 = *(long *)(param_1 + 0x1b78);
  puVar8 = (undefined8 *)kgraphicsGetContextBufferAttr_IMPL(param_1,param_3,2);
  lVar4 = *(long *)(param_2 + 0x148);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x511);
    return 0x40;
  }
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x514);
    return 0x40;
  }
  if (*(long *)(lVar7 + 0x13d8) == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x515);
    return 0x40;
  }
  iVar1 = *(int *)(*(long *)(lVar7 + 0x13d8) + 0x48);
  if (iVar1 == 0) {
    return 0x40;
  }
  cVar5 = ctxBufPoolIsSupported(param_1);
  if (cVar5 == '\0') {
    lVar7 = 0;
    uVar9 = 0x2000;
  }
  else {
    lVar7 = *(long *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 400);
    uVar9 = 0x2000;
    if (lVar7 != 0) {
      uVar9 = 0x1000002000;
    }
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    uVar9 = uVar9 | 0x2000000;
  }
  uVar2 = *(undefined4 *)(puVar8 + 1);
  uVar6 = memdescCreate(lVar4 + 0x140,param_1,iVar1,0x1000,1,0);
  if (uVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar6,
               "memdescCreate(ppMemDesc, pGpu, size, RM_PAGE_SIZE, NV_TRUE, ADDR_UNKNOWN, pAttr->cpuAttr, flags)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x52d);
    return (ulong)uVar6;
  }
  if (*(char *)(param_3 + 0x1fc) != '\0') {
    memdescSetGpuCacheAttrib(*(undefined8 *)(lVar4 + 0x140),0,uVar2,uVar9);
  }
  uVar9 = (**(code **)(lVar3 + 0x388))(param_1,lVar3,*(undefined8 *)(lVar4 + 0x140),1,1);
  uVar11 = 0x53d;
  pcVar10 = 
  "memmgrSetMemDescPageSize_HAL(pGpu, pMemoryManager, *ppMemDesc, AT_GPU, RM_ATTR_PAGE_SIZE_4KB)";
  if ((int)uVar9 == 0) {
    uVar6 = memdescSetCtxBufPool
                      (*(undefined8 *)(lVar4 + 0x140),lVar7,
                       "memmgrSetMemDescPageSize_HAL(pGpu, pMemoryManager, *ppMemDesc, AT_GPU, RM_ATTR_PAGE_SIZE_4KB)"
                       ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x53d);
    if (uVar6 != 0) {
      nvAssertOkFailedNoLog
                (uVar6,"memdescSetCtxBufPool(*ppMemDesc, pCtxBufPool)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0x541);
      goto LAB_00369a8e;
    }
    *(undefined4 *)(*(long *)(lVar4 + 0x140) + 0x9c) = 0x97;
    uVar9 = memdescAllocList(*(undefined8 *)(lVar4 + 0x140),*puVar8);
    if ((int)uVar9 == 0) {
      return uVar9;
    }
    uVar11 = 0x545;
    pcVar10 = "status";
  }
  uVar6 = (uint)uVar9;
  nvCheckOkFailedNoLog
            (4,uVar9 & 0xffffffff,pcVar10,"src/kernel/gpu/gr/kernel_graphics_context.c",uVar11);
LAB_00369a8e:
  memdescFree(*(undefined8 *)(lVar4 + 0x140));
  memdescDestroy(*(undefined8 *)(lVar4 + 0x140));
  *(undefined8 *)(lVar4 + 0x140) = 0;
  return (ulong)uVar6;
}


// ===== 00369b15 kgrctxAllocCtxBuffers_IMPL.cold =====

void kgrctxAllocCtxBuffers_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00369b20 kgrctxAllocCtxBuffers_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgrctxAllocCtxBuffers_IMPL(undefined8 param_1,long param_2,long param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  code *pcVar5;
  char cVar6;
  undefined4 uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  char *extraout_RDX;
  char *pcVar11;
  char *extraout_RDX_00;
  undefined8 uVar12;
  long local_40 [2];
  
  if (param_4 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar2 = *(long *)(param_4 + 0x1d8);
  uVar1 = *(undefined4 *)(lVar2 + 0x180);
  uVar7 = kchannelGetGfid_IMPL(*(undefined8 *)(lVar2 + 0x178));
  uVar3 = *(undefined8 *)(lVar2 + 0x178);
  lVar9 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,uVar7);
  if (*(long *)(param_4 + 0x208) == 0) {
    nvAssertFailedNoLog("kgrobjGetKernelGraphicsContext(pGpu, pKernelGraphicsObject) != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x56a);
    return 0x40;
  }
  lVar4 = *(long *)(*(long *)(param_4 + 0x208) + 0x148);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvCheckOkFailedNoLog
              (4,0x40,
               "kgrctxGetUnicast(pGpu, kgrobjGetKernelGraphicsContext(pGpu, pKernelGraphicsObject), &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x56c);
    return 0x40;
  }
  kgrctxGetMainContextBuffer_IMPL(param_1,param_2,local_40);
  pcVar11 = extraout_RDX;
  if ((local_40[0] == 0) && (*(char *)(*(long *)(lVar2 + 0x178) + 0x408) == '\0')) {
    if (*(long *)(lVar4 + 0x188) == 0) {
      uVar10 = kgrctxAllocMainCtxBuffer_IMPL(param_1,param_2,param_3,uVar3);
      uVar12 = 0x577;
      pcVar11 = 
      "kgrctxAllocMainCtxBuffer(pGpu, pKernelGraphicsContext, pKernelGraphics, pKernelChannel)";
      if ((int)uVar10 != 0) goto LAB_00369d5c;
    }
    else {
      uVar8 = kchannelSetEngineContextMemDesc_IMPL
                        (param_1,uVar3,*(uint *)(param_3 + 0x20c) | 0xd334df00);
      pcVar11 = extraout_RDX_00;
      if (uVar8 != 0) {
        nvAssertOkFailedNoLog
                  (uVar8,
                   "kchannelSetEngineContextMemDesc(pGpu, pKernelChannel, ENG_GR(kgraphicsGetInstance(pGpu, pKernelGraphics)), pKernelGraphicsContextUnicast->pMainCtxBuffer)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x57d);
        return (ulong)uVar8;
      }
    }
  }
  kgrmgrGetGrObjectType_IMPL(uVar1,local_40,pcVar11);
  if ((*(long *)(lVar4 + 0xb0) == 0) &&
     (uVar8 = kgrctxAllocPatchBuffer_IMPL(param_1,param_2,param_3,uVar3), uVar8 != 0)) {
    nvAssertOkFailedNoLog
              (uVar8,
               "kgrctxAllocPatchBuffer(pGpu, pKernelGraphicsContext, pKernelGraphics, pKernelChannel)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x58d);
    return (ulong)uVar8;
  }
  cVar6 = (**(code **)(param_2 + 0x138))(param_1,param_2,*(undefined8 *)(lVar2 + 0x178));
  if ((cVar6 != '\0') &&
     (uVar8 = kgrctxAllocPmBuffer_IMPL
                        (param_1,*(undefined8 *)(param_4 + 0x208),param_3,
                         *(undefined8 *)(lVar2 + 0x178)), uVar8 != 0)) {
    nvAssertOkFailedNoLog
              (uVar8,
               "kgrctxAllocPmBuffer(pGpu, kgrobjGetKernelGraphicsContext(pGpu, pKernelGraphicsObject), pKernelGraphics, pChannelDescendant->pKernelChannel)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x594);
    return (ulong)uVar8;
  }
  if ((*(char *)(lVar4 + 0x628) != '\0') && (*(char *)(lVar4 + 0x1e0) == '\0')) {
    uVar10 = (**(code **)(param_3 + 0x180))(param_1,param_3,uVar7,*(undefined8 *)(param_4 + 0x208));
    uVar12 = 0x5a1;
    pcVar11 = 
    "kgraphicsAllocGrGlobalCtxBuffers_HAL(pGpu, pKernelGraphics, gfid, kgrobjGetKernelGraphicsContext(pGpu, pKernelGraphicsObject))"
    ;
    if ((int)uVar10 != 0) goto LAB_00369d5c;
  }
  if (*(char *)(lVar9 + 0x50) != '\0') {
    return 0;
  }
  uVar10 = (**(code **)(param_3 + 0x180))(param_1,param_3,uVar7,0);
  if ((int)uVar10 == 0) {
    return uVar10;
  }
  uVar12 = 0x5a9;
  pcVar11 = "kgraphicsAllocGrGlobalCtxBuffers_HAL(pGpu, pKernelGraphics, gfid, NULL)";
LAB_00369d5c:
  nvCheckOkFailedNoLog
            (4,uVar10 & 0xffffffff,pcVar11,"src/kernel/gpu/gr/kernel_graphics_context.c",uVar12);
  return uVar10 & 0xffffffff;
}


// ===== 00369e70 kgrctxMapGlobalCtxBuffer_IMPL =====

int kgrctxMapGlobalCtxBuffer_IMPL
              (long param_1,long param_2,undefined8 param_3,undefined4 param_4,undefined8 param_5,
              uint param_6,undefined1 param_7)

{
  undefined8 uVar1;
  undefined1 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  long lVar8;
  ulong uVar9;
  uint local_40;
  undefined4 uStack_3c;
  
  lVar4 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,param_4);
  lVar6 = *(long *)(param_2 + 0x148);
  if (lVar6 == 0) {
    iVar3 = 0x40;
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x5c3);
  }
  else {
    uVar9 = (ulong)param_6;
    lVar8 = *(long *)(lVar6 + 400 + uVar9 * 8);
    if ((lVar8 == 0) && (lVar8 = *(long *)(lVar4 + uVar9 * 8), lVar8 == 0)) {
      lVar6 = kgraphicsGetStaticInfo_IMPL(param_1,param_3);
      if (lVar6 == 0) {
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics_context.c",0x5d4);
      }
      else {
        if (*(long *)(lVar6 + 0x13d8) != 0) {
          iVar3 = kgrctxGlobalCtxBufferToFifoEngineId_IMPL(param_6,&local_40);
          if (iVar3 == 0) {
            pcVar7 = "GR_GLOBALCTX_BUFFER__UNKNOWN";
            if (*(int *)(*(long *)(lVar6 + 0x13d8) + (ulong)local_40 * 8) == 0) {
              if (param_6 < 10) {
                pcVar7 = *(char **)(CSWTCH_280 + uVar9 * 8);
              }
              nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0x5db,
                           "kgrctxMapGlobalCtxBuffer_IMPL",1,
                           "NVRM: Could not map %s Buffer as buffer is not supported\n",pcVar7);
              return 0;
            }
            if (param_6 < 10) {
              pcVar7 = *(char **)(CSWTCH_280 + uVar9 * 8);
            }
            nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0x5e2,
                         "kgrctxMapGlobalCtxBuffer_IMPL",4,
                         "NVRM: Could not map %s Buffer, no memory allocated for it!\n",pcVar7);
          }
          else {
            nvAssertOkFailedNoLog
                      (0x1f,"kgrctxGlobalCtxBufferToFifoEngineId(buffId, &fifoEngineId)",
                       "src/kernel/gpu/gr/kernel_graphics_context.c",0x5d6);
          }
          return 0x1f;
        }
        nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics_context.c",0x5d5);
      }
      iVar3 = 0x40;
    }
    else {
      uVar2 = kgraphicsIsGlobalCtxBufferSizeAligned_IMPL(param_1,param_3,param_6);
      lVar6 = lVar6 + 0x1f0 + uVar9 * 0x40;
      iVar3 = kgraphicsMapCtxBuffer_IMPL(param_1,param_3,lVar8,param_5,lVar6,uVar2,param_7);
      if (iVar3 == 0) {
        iVar3 = vaListFindVa(lVar6,param_5,&local_40);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "vaListFindVa(&pKernelGraphicsContextUnicast->globalCtxBufferVaList[buffId], pVAS, &vaddr)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x5f3);
        }
        uVar1 = *(undefined8 *)(lVar8 + 0x30);
        uVar5 = memdescGetMemDescFromGpu(lVar8,param_1);
        uVar5 = memdescGetPhysAddr(uVar5,1,0);
        pcVar7 = "GR_GLOBALCTX_BUFFER__UNKNOWN";
        if (param_6 < 10) {
          pcVar7 = *(char **)(CSWTCH_280 + uVar9 * 8);
        }
        nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0x5f6,
                     "kgrctxMapGlobalCtxBuffer_IMPL",1,
                     "NVRM: GPU:%d %s Buffer PA @ 0x%llx VA @ 0x%llx of Size 0x%llx\n",
                     *(undefined4 *)(param_1 + 0x7a4),pcVar7,uVar5,CONCAT44(uStack_3c,local_40),
                     uVar1);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kgraphicsMapCtxBuffer(pGpu, pKernelGraphics, pMemDesc, pVAS, &pKernelGraphicsContextUnicast->globalCtxBufferVaList[buffId], kgraphicsIsGlobalCtxBufferSizeAligned(pGpu, pKernelGraphics, buffId), bIsReadOnly)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x5ea);
        pcVar7 = "GR_GLOBALCTX_BUFFER__UNKNOWN";
        if (param_6 < 10) {
          pcVar7 = *(char **)(CSWTCH_280 + uVar9 * 8);
        }
        nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0x5ef,
                     "kgrctxMapGlobalCtxBuffer_IMPL",4,"NVRM: %s Buffer could not be mapped\n",
                     pcVar7);
      }
    }
  }
  return iVar3;
}


// ===== 0036a200 kgrctxMapGlobalCtxBuffers_IMPL =====

undefined8
kgrctxMapGlobalCtxBuffers_IMPL
          (undefined8 param_1,long param_2,long param_3,undefined4 param_4,long param_5)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,param_4);
  if (*(long *)(param_2 + 0x148) == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x611);
  }
  else if ((*(char *)(*(long *)(param_2 + 0x148) + 0x1e0) != '\0') ||
          (*(char *)(lVar1 + 0x50) != '\0')) {
    uVar2 = 0;
    kgrctxMapGlobalCtxBuffer_IMPL
              (param_1,param_2,param_3,param_4,*(undefined8 *)(param_5 + 0x2a0),0,0);
    uVar2 = uVar2 & 0xffffffff00000000;
    kgrctxMapGlobalCtxBuffer_IMPL
              (param_1,param_2,param_3,param_4,*(undefined8 *)(param_5 + 0x2a0),2,uVar2);
    kgrctxMapGlobalCtxBuffer_IMPL
              (param_1,param_2,param_3,param_4,*(undefined8 *)(param_5 + 0x2a0),1,
               uVar2 & 0xffffffff00000000);
    if (*(char *)(param_3 + 0x208) != '\0') {
      kgrctxMapGlobalCtxBuffer_IMPL
                (param_1,param_2,param_3,param_4,*(undefined8 *)(param_5 + 0x2a0),3,0);
    }
    return 0;
  }
  return 0x40;
}


// ===== 0036a359 kgrctxMapCtxBuffers_IMPL.cold =====

void kgrctxMapCtxBuffers_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0036a370 kgrctxMapCtxBuffers_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgrctxMapCtxBuffers_IMPL(undefined8 param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  long *plVar10;
  uint local_3c [3];
  
  if (param_4 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar1 = *(long *)(param_4 + 0x1d8);
  lVar2 = *(long *)(lVar1 + 0x178);
  uVar9 = *(undefined4 *)(lVar1 + 0x180);
  uVar6 = kchannelGetGfid_IMPL(lVar2);
  lVar3 = *(long *)(*(long *)(param_4 + 0x208) + 0x148);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,
               "kgrctxGetUnicast(pGpu, kgrobjGetKernelGraphicsContext(pGpu, pKernelGraphicsObject), &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x656);
  }
  else {
    plVar10 = (long *)__nvoc_dynamicCast(*(undefined8 *)(lVar2 + 0x2a0),__nvoc_class_def_OBJGVASPACE
                                        );
    cVar5 = (**(code **)(*plVar10 + 0x188))(plVar10);
    if (cVar5 != '\0') {
      return 0;
    }
    if (*(char *)(lVar2 + 0x408) != '\0') {
LAB_0036a471:
      kgrmgrGetGrObjectType_IMPL(uVar9,local_3c);
      iVar8 = kgraphicsMapCtxBuffer_IMPL
                        (param_1,param_3,*(undefined8 *)(lVar3 + 0xb0),
                         *(undefined8 *)(lVar2 + 0x2a0),lVar3 + 0xb8,0,0);
      if (iVar8 != 0) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kgraphicsMapCtxBuffer(pGpu, pKernelGraphics, pKernelGraphicsContextUnicast->ctxPatchBuffer.pMemDesc, pKernelChannel->pVAS, &pKernelGraphicsContextUnicast->ctxPatchBuffer.vAddrList, NV_FALSE, NV_FALSE)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x675,0x36a47d);
        return iVar8;
      }
      if ((*(long *)(lVar3 + 0x140) != 0) &&
         (iVar8 = kgraphicsMapCtxBuffer_IMPL
                            (param_1,param_3,*(long *)(lVar3 + 0x140),*(undefined8 *)(lVar2 + 0x2a0)
                             ,lVar3 + 0x148,0,0), iVar8 != 0)) {
        nvAssertOkFailedNoLog
                  (iVar8,
                   "kgraphicsMapCtxBuffer(pGpu, pKernelGraphics, pKernelGraphicsContextUnicast->pmCtxswBuffer.pMemDesc, pKernelChannel->pVAS, &pKernelGraphicsContextUnicast->pmCtxswBuffer.vAddrList, NV_FALSE, NV_FALSE)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x67b);
        return iVar8;
      }
      if (*(char *)(param_3 + 0x207) != '\0') {
        uVar9 = (**(code **)(param_2 + 0x140))(param_1,param_2,*(undefined8 *)(lVar1 + 0x178));
        kgrctxMapGlobalCtxBuffer_IMPL
                  (param_1,param_2,param_3,uVar6,*(undefined8 *)(lVar2 + 0x2a0),uVar9,1);
      }
      if ((*(char *)(*(long *)(*(long *)(lVar2 + 0x2b8) + 0x138) + 0x159) == '\0') &&
         (1 < local_3c[0])) {
        return 0;
      }
      kgrctxMapGlobalCtxBuffers_IMPL(param_1,param_2,param_3,uVar6,lVar2);
      return 0;
    }
    uVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    plVar10 = *(long **)(*(long *)(*(long *)(*(long *)(lVar2 + 0x2b8) + 0x138) + 0x150) +
                        (ulong)uVar7 * 8);
    if (plVar10 == (long *)0x0) {
      nvAssertFailedNoLog("pEngCtx != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x66a);
    }
    else {
      if (*plVar10 != 0) {
        iVar8 = kgraphicsMapCtxBuffer_IMPL
                          (param_1,param_3,*plVar10,*(undefined8 *)(lVar2 + 0x2a0),plVar10 + 1,0);
        if (iVar8 != 0) {
          nvAssertOkFailedNoLog
                    (iVar8,
                     "kgraphicsMapCtxBuffer(pGpu, pKernelGraphics, pMemDesc, pKernelChannel->pVAS, &pEngCtx->vaList, NV_FALSE, NV_FALSE)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x66e);
          return iVar8;
        }
        goto LAB_0036a471;
      }
      nvAssertFailedNoLog("pEngCtx->pMemDesc != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",
                          0x66b);
    }
  }
  return 0x40;
}


// ===== 0036a6b0 kgrctxPrepareInitializeCtxBuffer_IMPL =====

undefined8
kgrctxPrepareInitializeCtxBuffer_IMPL
          (undefined8 param_1,long param_2,undefined8 param_3,long param_4,uint param_5,
          undefined8 *param_6,undefined1 *param_7)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  uint local_1c [3];
  
  *param_7 = 0;
  if (param_4 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x6b6
                       );
    return 0x21;
  }
  lVar6 = *(long *)(param_2 + 0x148);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x6b8);
    return 0x40;
  }
  if (param_5 < 8) {
    if (2 < param_5) {
      return 0;
    }
    if (param_5 == 1) {
      if (*(char *)(lVar6 + 0x472) != '\0') {
        return 0;
      }
      lVar7 = *(long *)(lVar6 + 0x140);
    }
    else {
      if (param_5 != 2) {
        if (*(char *)(lVar6 + 0x470) != '\0') {
          return 0;
        }
        if (*(char *)(param_4 + 0x408) != '\0') {
          return 0;
        }
        uVar4 = gpumgrGetSubDeviceInstanceFromGpu();
        plVar1 = *(long **)(*(long *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 0x150) +
                           (ulong)uVar4 * 8);
        if (plVar1 == (long *)0x0) {
          nvAssertFailedNoLog("pEngCtx != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x6cb)
          ;
          return 0x40;
        }
        lVar7 = *plVar1;
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pEngCtx->pMemDesc != NULL",
                              "src/kernel/gpu/gr/kernel_graphics_context.c",0x6cc);
          return 0x40;
        }
        goto LAB_0036a78f;
      }
      if (*(char *)(lVar6 + 0x471) != '\0') {
        return 0;
      }
      lVar7 = *(long *)(lVar6 + 0xb0);
      if (lVar7 != 0) goto LAB_0036a78f;
      nvAssertFailedNoLog("pKernelGraphicsContextUnicast->ctxPatchBuffer.pMemDesc != NULL",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x6dd);
      lVar7 = *(long *)(lVar6 + 0xb0);
    }
  }
  else {
    if (0xb < param_5) {
      if (param_5 == 0xc) {
        return 0;
      }
      nvAssertFailedNoLog("!\"Unrecognized promote ctx enum\"",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x71b);
      return 0x1f;
    }
    if (param_5 == 8) {
      uVar2 = kchannelGetGfid_IMPL(param_4);
      if (*(char *)(lVar6 + 0x1e0) == '\0') {
        lVar6 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,uVar2);
      }
      else {
        lVar6 = lVar6 + 400;
      }
      if (*(char *)(lVar6 + 0x56) != '\0') {
        return 0;
      }
      lVar7 = *(long *)(lVar6 + 0x28);
    }
    else {
      uVar2 = kchannelGetGfid_IMPL(param_4);
      iVar3 = kgrctxGetGlobalContextBufferInternalId_IMPL(param_5,local_1c);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (0x1f,"kgrctxGetGlobalContextBufferInternalId(externalId, &internalId)",
                   "src/kernel/gpu/gr/kernel_graphics_context.c",0x70b);
        return 0x1f;
      }
      lVar6 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,uVar2);
      if (*(char *)(lVar6 + 0x51 + (ulong)local_1c[0]) != '\0') {
        return 0;
      }
      lVar7 = *(long *)(lVar6 + (ulong)local_1c[0] * 8);
    }
  }
  if (lVar7 == 0) {
    return 0;
  }
LAB_0036a78f:
  iVar3 = memdescGetAddressSpace();
  if (iVar3 == 1) {
    if (*(int *)(lVar7 + 0x74) == 0) {
      uVar2 = 5;
    }
    else {
      uVar2 = 6;
      if (*(int *)(lVar7 + 0x74) != 1) {
        return 0x40;
      }
    }
  }
  else {
    if (iVar3 != 2) {
      return 0x40;
    }
    uVar2 = 4;
  }
  uVar5 = memdescGetPhysAddr(lVar7,1,0);
  *param_6 = uVar5;
  uVar5 = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(param_6 + 3) = uVar2;
  param_6[2] = uVar5;
  *(undefined2 *)((long)param_6 + 0x1e) = 0x101;
  *(short *)((long)param_6 + 0x1c) = (short)param_5;
  *param_7 = 1;
  return 0;
}


// ===== 0036aae0 kgrctxPreparePromoteCtxBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong kgrctxPreparePromoteCtxBuffer_IMPL
                (undefined8 param_1,long param_2,long param_3,uint param_4,long param_5,
                undefined1 *param_6)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  undefined8 local_48;
  uint local_40;
  undefined4 uStack_3c;
  
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_3 + 0x2a0),__nvoc_class_def_OBJGVASPACE)
  ;
  lVar7 = *(long *)(param_2 + 0x148);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x762);
    return 0x40;
  }
  *param_6 = 0;
  cVar2 = (**(code **)(*plVar5 + 0x188))(plVar5);
  if (cVar2 == '\0') {
    if (param_4 == 2) {
      lVar7 = lVar7 + 0xb8;
    }
    else if (param_4 < 3) {
      lVar7 = lVar7 + 0x148;
      if (param_4 == 0) {
        if (*(char *)(param_3 + 0x408) != '\0') {
          return 0;
        }
        uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
        lVar1 = *(long *)(*(long *)(*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) + 0x150) +
                         (ulong)uVar3 * 8);
        lVar7 = lVar1 + 8;
        if (lVar1 == 0) {
          nvAssertFailedNoLog("pEngCtx != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0x779)
          ;
          return 0x40;
        }
      }
    }
    else {
      if (9 < param_4 - 3) {
        nvAssertFailedNoLog("!\"Unrecognized promote ctx enum\"",
                            "src/kernel/gpu/gr/kernel_graphics_context.c",0x7a0);
        return 0x1f;
      }
      iVar4 = kgrctxGetGlobalContextBufferInternalId_IMPL(param_4,&local_40);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (0x1f,"kgrctxGetGlobalContextBufferInternalId(externalId, &internalId)",
                   "src/kernel/gpu/gr/kernel_graphics_context.c",0x799);
        return 0x1f;
      }
      lVar7 = lVar7 + 0x1f0 + (ulong)local_40 * 0x40;
    }
    uVar6 = vaListGetRefCount(lVar7,*(undefined8 *)(param_3 + 0x2a0),&local_40);
    if ((int)uVar6 == 0) {
      if (CONCAT44(uStack_3c,local_40) < 2) {
        uVar6 = vaListFindVa(lVar7,*(undefined8 *)(param_3 + 0x2a0),&local_48);
        if ((int)uVar6 == 0) {
          *(short *)(param_5 + 0x1c) = (short)param_4;
          *(undefined1 *)(param_5 + 0x1f) = 0;
          *(undefined8 *)(param_5 + 8) = local_48;
          *param_6 = 1;
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar6 & 0xffffffff,"vaListFindVa(pVaList, pKernelChannel->pVAS, &vaddr)",
                     "src/kernel/gpu/gr/kernel_graphics_context.c",0x7a8);
          uVar6 = uVar6 & 0xffffffff;
        }
      }
      return uVar6;
    }
  }
  return 0;
}


// ===== 0036ad70 kgrctxMarkCtxBufferInitialized_IMPL =====

void kgrctxMarkCtxBufferInitialized_IMPL
               (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  uint local_1c [3];
  
  lVar3 = *(long *)(param_2 + 0x148);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x7c0);
    return;
  }
  if (param_5 == 2) {
    *(undefined1 *)(lVar3 + 0x471) = 1;
    return;
  }
  if (param_5 < 3) {
    if (param_5 != 0) {
      *(undefined1 *)(lVar3 + 0x472) = 1;
      return;
    }
    *(undefined1 *)(lVar3 + 0x470) = 1;
    return;
  }
  if (param_5 < 9) {
    if (*(char *)(lVar3 + 0x1e0) != '\0') {
      iVar2 = kgrctxGetGlobalContextBufferInternalId_IMPL(param_5,local_1c);
      if (iVar2 == 0) {
        *(undefined1 *)(lVar3 + 0x1e1 + (ulong)local_1c[0]) = 1;
        return;
      }
      nvAssertOkFailedNoLog
                (0x1f,"kgrctxGetGlobalContextBufferInternalId(externalId, &internalId)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0x7e3);
      return;
    }
  }
  else if (3 < param_5 - 9) {
    nvAssertFailedNoLog("!\"Unrecognized promote ctx enum\"",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x804);
    return;
  }
  uVar1 = kchannelGetGfid_IMPL(param_4);
  iVar2 = kgrctxGetGlobalContextBufferInternalId_IMPL(param_5,local_1c);
  if (iVar2 == 0) {
    lVar3 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,uVar1);
    *(undefined1 *)(lVar3 + 0x51 + (ulong)local_1c[0]) = 1;
    return;
  }
  nvAssertOkFailedNoLog
            (0x1f,"kgrctxGetGlobalContextBufferInternalId(externalId, &internalId)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0x7f9);
  return;
}


// ===== 0036af00 kgrctxUnmapCtxZcullBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgrctxUnmapCtxZcullBuffer_IMPL(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 local_30 [2];
  
  lVar2 = *(long *)(param_2 + 0x148);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x8f8);
    return;
  }
  lVar1 = lVar2 + 0x100;
  if (*(long *)(lVar2 + 0xf8) == 0) {
    iVar3 = vaListFindVa(lVar1,param_4,local_30);
    if (iVar3 == 0) {
      vaListRemoveVa(lVar1,param_4);
    }
  }
  else {
    if (1 < *(uint *)(*(long *)(lVar2 + 0xf8) + 0x8c)) {
      nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x906);
    }
    iVar3 = vaListFindVa(lVar1,param_4,local_30);
    if (iVar3 == 0) {
      (**(code **)(*(long *)(param_1 + 0x1bb8) + 0x1b0))
                (param_1,*(long *)(param_1 + 0x1bb8),param_4,local_30[0]);
      vaListRemoveVa(lVar1,param_4);
      return;
    }
  }
  return;
}


// ===== 0036b030 kgrctxUnmapCtxPreemptionBuffers_IMPL =====

void kgrctxUnmapCtxPreemptionBuffers_IMPL
               (undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x926);
    return;
  }
  kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,param_4,lVar1 + 0x480);
  kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,param_4,lVar1 + 0x4c8);
  kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,param_4,lVar1 + 0x510);
  kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,param_4,lVar1 + 0x558);
  kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,param_4,lVar1 + 0x5a0);
  if (*(char *)(param_3 + 0x1fd) == '\0') {
    return;
  }
  kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,param_4,lVar1 + 0x5e8);
  return;
}


// ===== 0036b160 kgrctxShouldPreAllocPmBuffer_PF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgrctxShouldPreAllocPmBuffer_PF(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pKernelChannel","src/kernel/gpu/gr/kernel_graphics_context.c",0x9dc
                       );
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x9dd);
  }
  else {
    lVar1 = *(long *)(param_2 + 0x148);
    if (lVar1 != 0) {
      plVar2 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_3 + 0x2a0),
                                          __nvoc_class_def_OBJGVASPACE);
      if (*(long *)(lVar1 + 0x140) != 0) {
        return 0;
      }
      uVar3 = (**(code **)(*plVar2 + 0x188))();
      return uVar3;
    }
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvCheckOkFailedNoLog
              (4,0x40,
               "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
               "src/kernel/gpu/gr/kernel_graphics_context.c",0x9df);
  }
  return 0x40;
}


// ===== 0036b260 kgrctxShouldPreAllocPmBuffer_VF =====

undefined8 kgrctxShouldPreAllocPmBuffer_VF(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pKernelChannel","src/kernel/gpu/gr/kernel_graphics_context.c",0xa05
                       );
  }
  else if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0xa06);
  }
  else {
    if (*(long *)(param_2 + 0x148) != 0) {
      if (*(long *)(*(long *)(param_2 + 0x148) + 0x140) != 0) {
        return 0;
      }
      if ((((*(char *)(param_1 + 0x4913) != '\0') && (*(char *)(param_1 + 0x491e) == '\0')) &&
          (lVar2 = gpuGetStaticInfo(), lVar2 != 0)) && (*(char *)(lVar2 + 0xa7ac) != '\0')) {
        return 1;
      }
      uVar1 = kgrctxShouldPreAllocPmBuffer_PF(param_1,param_2,param_3);
      return uVar1;
    }
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvCheckOkFailedNoLog
              (4,0x40,
               "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
               "src/kernel/gpu/gr/kernel_graphics_context.c",0xa08);
  }
  return 0x40;
}


// ===== 0036b380 kgrctxShouldManageCtxBuffers_KERNEL =====

uint kgrctxShouldManageCtxBuffers_KERNEL(long param_1,undefined8 param_2,int param_3)

{
  undefined8 in_RAX;
  
  return (uint)CONCAT71((int7)((ulong)in_RAX >> 8),*(char *)(param_1 + 0x4a23) != '\0') &
         CONCAT31((int3)((uint)param_3 >> 8),param_3 == 0);
}


// ===== 0036b3a0 kgrctxUnmapMainCtxBuffer_IMPL =====

void kgrctxUnmapMainCtxBuffer_IMPL(undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  long local_30 [2];
  
  iVar1 = kchangrpGetEngineContextMemDesc_IMPL
                    (param_1,*(undefined8 *)(*(long *)(param_4 + 0x2b8) + 0x138),local_30);
  if ((iVar1 == 0) && (local_30[0] != 0)) {
    kchannelUnmapEngineCtxBuf_IMPL(param_1,param_4,*(uint *)(param_3 + 0x20c) | 0xd334df00);
    iVar1 = kchannelSetEngineContextMemDesc_IMPL
                      (param_1,param_4,*(uint *)(param_3 + 0x20c) | 0xd334df00,0);
    if (iVar1 != 0) {
      nvAssertFailedNoLog("kchannelSetEngineContextMemDesc(pGpu, pKernelChannel, ENG_GR(kgraphicsGetInstance(pGpu, pKernelGraphics)), NULL) == NV_OK"
                          ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xa86);
    }
  }
  return;
}


// ===== 0036b440 kgrctxUnmapGlobalCtxBuffer_IMPL =====

undefined8
kgrctxUnmapGlobalCtxBuffer_IMPL
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  ulong uVar5;
  undefined8 local_40 [2];
  
  if (*(long *)(param_2 + 0x148) != 0) {
    uVar5 = (ulong)param_5;
    lVar1 = *(long *)(param_2 + 0x148) + 0x1f0 + uVar5 * 0x40;
    iVar2 = vaListFindVa(lVar1,param_4,local_40);
    if (iVar2 == 0) {
      pcVar4 = "GR_GLOBALCTX_BUFFER__UNKNOWN";
      if (param_5 < 10) {
        pcVar4 = *(char **)(CSWTCH_280 + uVar5 * 8);
      }
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xacc,
                   "kgrctxUnmapGlobalCtxBuffer_IMPL",1,"NVRM: Unmapping %s from VA @ 0x%llx\n",
                   pcVar4);
      kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,param_4,lVar1);
    }
    else {
      pcVar4 = "GR_GLOBALCTX_BUFFER__UNKNOWN";
      if (param_5 < 10) {
        pcVar4 = *(char **)(CSWTCH_280 + uVar5 * 8);
      }
      local_40[0] = nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xad3,
                                 "kgrctxUnmapGlobalCtxBuffer_IMPL",1,
                                 "NVRM: Buffer for %s already unmapped\n",pcVar4);
    }
    return local_40[0];
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  uVar3 = nvAssertOkFailedNoLog
                    (0x40,
                     "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xac5);
  return uVar3;
}


// ===== 0036b5a0 kgrctxUnmapGlobalCtxBuffers_IMPL =====

void kgrctxUnmapGlobalCtxBuffers_IMPL
               (undefined8 param_1,long param_2,long param_3,undefined8 param_4,undefined4 param_5)

{
  long lVar1;
  
  lVar1 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,param_5);
  if (*(long *)(param_2 + 0x148) == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xa9e);
    return;
  }
  if ((*(char *)(*(long *)(param_2 + 0x148) + 0x1e0) != '\0') || (*(char *)(lVar1 + 0x50) != '\0'))
  {
    kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_3,param_4,0);
    kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_3,param_4,2);
    kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_3,param_4,1);
    if (*(char *)(param_3 + 0x208) != '\0') {
      kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_3,param_4,3);
      return;
    }
  }
  return;
}


// ===== 0036b6a0 kgrctxUnmapAssociatedCtxBuffers_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgrctxUnmapAssociatedCtxBuffers_IMPL(undefined8 param_1,long param_2,long param_3,long param_4)

{
  char cVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  long *plVar8;
  undefined1 local_40 [16];
  
  uVar3 = kchannelGetGfid_IMPL(param_4);
  uVar4 = (**(code **)(param_2 + 0x140))(param_1,param_2,param_4);
  lVar2 = *(long *)(param_2 + 0x148);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x952);
    return;
  }
  lVar7 = *(long *)(*(long *)(param_4 + 0x2b8) + 0x138);
  if (*(char *)(lVar7 + 0x159) == '\0') {
    if (*(int *)(lVar2 + 0x9c) == 0) {
      if (*(int *)(lVar2 + 0xa0) != 0) {
        cVar1 = *(char *)(lVar7 + 0x158);
        goto joined_r0x0036b7f3;
      }
      goto LAB_0036b721;
    }
  }
  else if (*(int *)(lVar2 + 0x98) == 0) {
LAB_0036b721:
    kgrctxUnmapGlobalCtxBuffers_IMPL(param_1,param_2,param_3,*(undefined8 *)(param_4 + 0x2a0),uVar3)
    ;
    lVar7 = *(long *)(*(long *)(param_4 + 0x2b8) + 0x138);
  }
  cVar1 = *(char *)(lVar7 + 0x158);
joined_r0x0036b7f3:
  if (((cVar1 == '\0') && (*(long **)(lVar7 + 0x140) != (long *)0x0)) &&
     (plVar8 = (long *)**(long **)(lVar7 + 0x140), plVar8 != (long *)0x0)) {
    do {
      lVar7 = *plVar8;
      if (lVar7 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = *(int *)(lVar7 + 0x2b0) << 0x18 | *(uint *)(lVar7 + 0x2b4);
      }
      if ((uVar5 != (*(int *)(param_4 + 0x2b0) << 0x18 | *(uint *)(param_4 + 0x2b4))) &&
         (*(long *)(lVar7 + 0x2a0) == *(long *)(param_4 + 0x2a0))) {
        return;
      }
      plVar8 = (long *)plVar8[1];
    } while (plVar8 != (long *)0x0);
  }
  lVar7 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_3,uVar3);
  if (*(long *)(lVar7 + 0x30) != 0) {
    kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_3,*(undefined8 *)(param_4 + 0x2a0),6);
  }
  if (*(long *)(lVar2 + 0x140) != 0) {
    if (*(long *)(param_2 + 0x148) == 0) {
      nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
      nvAssertOkFailedNoLog
                (0x40,
                 "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0x8df);
    }
    else {
      kgraphicsUnmapCtxBuffer_IMPL
                (param_1,param_3,*(undefined8 *)(param_4 + 0x2a0),*(long *)(param_2 + 0x148) + 0x148
                );
    }
  }
  if (*(char *)(param_3 + 0x207) != '\0') {
    kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_3,*(undefined8 *)(param_4 + 0x2a0),uVar4);
  }
  if (*(long *)(lVar2 + 0xb0) != 0) {
    kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,*(undefined8 *)(param_4 + 0x2a0),lVar2 + 0xb8);
  }
  kgrctxUnmapCtxZcullBuffer_IMPL(param_1,param_2,param_3,*(undefined8 *)(param_4 + 0x2a0));
  kgrctxUnmapCtxPreemptionBuffers_IMPL(param_1,param_2,param_3,*(undefined8 *)(param_4 + 0x2a0));
  lVar7 = *(long *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 0x150);
  uVar5 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  if (*(long *)(lVar7 + (ulong)uVar5 * 8) != 0) {
    uVar5 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    lVar7 = *(long *)(*(long *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 0x150) +
                     (ulong)uVar5 * 8) + 8;
    while (iVar6 = vaListFindVa(lVar7,*(undefined8 *)(param_4 + 0x2a0),local_40), iVar6 == 0) {
      kgraphicsUnmapCtxBuffer_IMPL(param_1,param_3,*(undefined8 *)(param_4 + 0x2a0),lVar7);
    }
  }
  if (*(int *)(lVar2 + 0x98) != 0) {
    return;
  }
  kgrctxUnmapMainCtxBuffer_IMPL(param_1,param_2,param_3,param_4);
  return;
}


// ===== 0036ba40 kgrctxUnmapBuffers_KERNEL =====

void kgrctxUnmapBuffers_KERNEL(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 local_50;
  undefined1 local_48 [24];
  
  uVar2 = *(undefined8 *)(param_1 + 0x1bc8);
  uVar3 = *(undefined8 *)(*(long *)(param_2 + 0x128) + 0xe8);
  uVar1 = *(undefined4 *)(*(long *)(*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x18) + 0x10);
  portMemSet(local_48,0,0x10);
  kgrmgrCtrlSetChannelHandle_IMPL(uVar1,local_48);
  iVar4 = kgrmgrCtrlRouteKGRWithDevice_IMPL(param_1,uVar2,uVar3,local_48,&local_50);
  if (iVar4 == 0) {
    kgrctxUnmapAssociatedCtxBuffers_IMPL(param_1,param_2,local_50,param_4);
    return;
  }
  nvAssertOkFailedNoLog
            (iVar4,
             "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
             ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xa64);
  return;
}


// ===== 0036bb10 kgrctxFreeMainCtxBuffer_IMPL =====

void kgrctxFreeMainCtxBuffer_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 != 0) {
    if (*(long *)(lVar1 + 0x188) != 0) {
      memdescFree();
      memdescDestroy(*(undefined8 *)(lVar1 + 0x188));
      *(undefined1 *)(lVar1 + 0x470) = 0;
      *(undefined8 *)(lVar1 + 0x188) = 0;
    }
    return;
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  nvAssertOkFailedNoLog
            (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0xae5);
  return;
}


// ===== 0036bba0 kgrctxFreeZcullBuffer_IMPL =====

void kgrctxFreeZcullBuffer_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0xf8);
    if (lVar2 == 0) {
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xb0a,"kgrctxFreeZcullBuffer_IMPL",
                   1,"NVRM: call to free zcull ctx buffer not RM managed, skipped!\n");
    }
    memdescFree(lVar2);
    memdescDestroy(lVar2);
    *(undefined8 *)(lVar1 + 0xf8) = 0;
    return;
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  nvAssertOkFailedNoLog
            (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0xb01);
  return;
}


// ===== 0036bc60 kgrctxFreeCtxPreemptionBuffers_IMPL =====

void kgrctxFreeCtxPreemptionBuffers_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 != 0) {
    memdescFree(*(undefined8 *)(lVar1 + 0x478));
    memdescDestroy(*(undefined8 *)(lVar1 + 0x478));
    *(undefined8 *)(lVar1 + 0x478) = 0;
    memdescFree(*(undefined8 *)(lVar1 + 0x4c0));
    memdescDestroy(*(undefined8 *)(lVar1 + 0x4c0));
    *(undefined8 *)(lVar1 + 0x4c0) = 0;
    memdescFree(*(undefined8 *)(lVar1 + 0x508));
    memdescDestroy(*(undefined8 *)(lVar1 + 0x508));
    *(undefined8 *)(lVar1 + 0x508) = 0;
    memdescFree(*(undefined8 *)(lVar1 + 0x550));
    memdescDestroy(*(undefined8 *)(lVar1 + 0x550));
    *(undefined8 *)(lVar1 + 0x550) = 0;
    memdescFree(*(undefined8 *)(lVar1 + 0x598));
    memdescDestroy(*(undefined8 *)(lVar1 + 0x598));
    *(undefined8 *)(lVar1 + 0x598) = 0;
    memdescFree(*(undefined8 *)(lVar1 + 0x5e0));
    memdescDestroy(*(undefined8 *)(lVar1 + 0x5e0));
    *(undefined8 *)(lVar1 + 0x5e0) = 0;
    return;
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  nvAssertOkFailedNoLog
            (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0xb23);
  return;
}


// ===== 0036bda0 kgrctxFreePatchBuffer_IMPL =====

void kgrctxFreePatchBuffer_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xb4d);
    return;
  }
  if (*(long *)(lVar1 + 0xb0) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(lVar1 + 0xb0));
    *(undefined1 *)(lVar1 + 0x471) = 0;
    *(undefined8 *)(lVar1 + 0xb0) = 0;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xb55,"kgrctxFreePatchBuffer_IMPL",1,
               "NVRM: Attempt to free null ctx patch buffer pointer, skipped!\n");
  return;
}


// ===== 0036be60 kgrctxFreePmBuffer_IMPL =====

void kgrctxFreePmBuffer_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 != 0) {
    lVar2 = *(long *)(lVar1 + 0x140);
    if (lVar2 == 0) {
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xb85,"kgrctxFreePmBuffer_IMPL",1,
                   "NVRM: Attempt to free null pm ctx buffer pointer??\n");
    }
    else {
      if (1 < *(uint *)(lVar2 + 0x8c)) {
        nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(pMemDesc)",
                            "src/kernel/gpu/gr/kernel_graphics_context.c",0xb7e);
      }
      memdescFree(lVar2);
      memdescDestroy(lVar2);
    }
    *(undefined8 *)(lVar1 + 0x140) = 0;
    *(undefined1 *)(lVar1 + 0x472) = 0;
    return;
  }
  nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
  nvAssertOkFailedNoLog
            (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
             "src/kernel/gpu/gr/kernel_graphics_context.c",0xb71);
  return;
}


// ===== 0036bf5d kgrctxSetupDeferredPmBuffer_IMPL.cold =====

void kgrctxSetupDeferredPmBuffer_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0036bf80 kgrctxSetupDeferredPmBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int kgrctxSetupDeferredPmBuffer_IMPL(undefined8 param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  code *pcVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  undefined8 *puVar11;
  int local_4b4;
  undefined1 local_4a8 [286];
  char local_38a;
  char local_389;
  long local_388;
  undefined1 local_380 [8];
  undefined8 local_378;
  undefined1 local_370 [232];
  undefined8 local_288;
  long local_270;
  int local_268 [3];
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_240;
  undefined1 local_238 [28];
  undefined2 local_21c;
  char local_21a;
  undefined8 local_180;
  long local_168;
  
  plVar8 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_4 + 0x2a0),__nvoc_class_def_OBJGVASPACE)
  ;
  lVar2 = *(long *)(*(long *)(param_4 + 0x158) + 0xe8);
  uVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  iVar7 = subdeviceGetByInstance_IMPL
                    (**(undefined8 **)(*(long *)(param_4 + 0x140) + 0x48),
                     *(undefined4 *)(*(long *)(*(long *)(lVar2 + 0x110) + 0x48) + 0x10),uVar6,
                     &local_388);
  if (iVar7 != 0) {
    nvAssertOkFailedNoLog
              (iVar7,
               "subdeviceGetByInstance( RES_GET_CLIENT(pKernelChannel), RES_GET_HANDLE(pDevice), gpumgrGetSubDeviceInstanceFromGpu(pGpu), &pSubdevice)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x818);
    return iVar7;
  }
  lVar2 = *(long *)(param_2 + 0x148);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x821);
  }
  else {
    cVar5 = (**(code **)(*plVar8 + 0x188))(plVar8);
    if (cVar5 == '\0') {
      if (*(long *)(lVar2 + 0x140) != 0) {
        return 0;
      }
      iVar7 = kgrctxAllocPmBuffer_IMPL(param_1,param_2,param_3,param_4);
      if (iVar7 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar7,
                   "kgrctxAllocPmBuffer(pGpu, pKernelGraphicsContext, pKernelGraphics, pKernelChannel)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x835);
        return iVar7;
      }
      puVar3 = *(undefined8 **)(*(long *)(param_4 + 0x140) + 0x48);
      puVar11 = puVar3;
      if ((*(char *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 0x158) == '\0') &&
         (*(char *)(param_3 + 0x205) != '\0')) {
        puVar11 = *(undefined8 **)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x110) + 0x48);
      }
      kchannelGetIter(local_4a8,*puVar3,puVar11);
      memcpy(local_370,local_4a8,0x108);
      do {
        do {
          do {
            cVar5 = clientRefOrderedIterNext(local_288,local_370);
            if (cVar5 == '\0') {
              return 0;
            }
            lVar9 = __nvoc_dynamicCast(*(undefined8 *)(local_270 + 8),__nvoc_class_def_KernelChannel
                                      );
            if (lVar9 == 0) {
              nvAssertFailedNoLog("pLoopKernelChannel != NULL",
                                  "src/kernel/gpu/gr/kernel_graphics_context.c",0x84f);
              local_4b4 = 0x40;
              goto LAB_0036c40a;
            }
            iVar7 = vaListFindVa(lVar2 + 0xb8,*(undefined8 *)(lVar9 + 0x2a0),local_380);
          } while (iVar7 != 0);
          lVar1 = lVar2 + 0x148;
          iVar7 = vaListFindVa(lVar1,*(undefined8 *)(lVar9 + 0x2a0),local_380);
        } while (iVar7 == 0);
        lVar10 = rmapiGetInterface(4);
        local_4b4 = kgraphicsMapCtxBuffer_IMPL
                              (param_1,param_3,*(undefined8 *)(lVar2 + 0x140),
                               *(undefined8 *)(lVar9 + 0x2a0),lVar1,0,0);
        if (local_4b4 != 0) {
          nvAssertOkFailedNoLog
                    (local_4b4,
                     "kgraphicsMapCtxBuffer(pGpu, pKernelGraphics, pKernelGraphicsContextUnicast->pmCtxswBuffer.pMemDesc, pLoopKernelChannel->pVAS, &pKernelGraphicsContextUnicast->pmCtxswBuffer.vAddrList, NV_FALSE, NV_FALSE)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x85c);
          goto LAB_0036c40a;
        }
        portMemSet(local_268,0,0x230);
        local_4b4 = kgrctxPrepareInitializeCtxBuffer_IMPL
                              (param_1,param_2,param_3,param_4,1,local_238,&local_38a);
        if (local_4b4 != 0) {
          nvAssertOkFailedNoLog
                    (local_4b4,
                     "kgrctxPrepareInitializeCtxBuffer(pGpu, pKernelGraphicsContext, pKernelGraphics, pKernelChannel, NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PM, &params.promoteEntry[0], &bInitialize)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x869);
          goto LAB_0036c40a;
        }
        local_4b4 = kgrctxPreparePromoteCtxBuffer_IMPL
                              (param_1,param_2,param_4,1,local_238,&local_389);
        if (local_4b4 != 0) {
          nvAssertOkFailedNoLog
                    (local_4b4,
                     "kgrctxPreparePromoteCtxBuffer(pGpu, pKernelGraphicsContext, pKernelChannel, NV2080_CTRL_GPU_PROMOTE_CTX_BUFFER_ID_PM, &params.promoteEntry[0], &bPromote)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x874);
          goto LAB_0036c40a;
        }
        if (local_38a == '\0' && local_389 == '\0') {
          nvAssertFailedNoLog("bInitialize || bPromote",
                              "src/kernel/gpu/gr/kernel_graphics_context.c",0x87d);
          local_4b4 = 0x40;
          goto LAB_0036c40a;
        }
        local_268[0] = *(int *)(param_3 + 0x20c) + 1;
        plVar8 = *(long **)(*(long *)(param_4 + 0x140) + 0x48);
        local_25c = *(undefined4 *)(*plVar8 + 0x48);
        local_258 = (undefined4)plVar8[2];
        local_240 = 1;
        if (local_388 == 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)invalidInstructionException();
          (*pcVar4)();
        }
        plVar8 = *(long **)(*(long *)(local_388 + 0x140) + 0x48);
        local_4b4 = (**(code **)(lVar10 + 0x38))
                              (lVar10,*(undefined4 *)(*plVar8 + 0x48),(int)plVar8[2],0x2080012b,
                               local_268);
        if (local_4b4 != 0) {
          nvCheckOkFailedNoLog
                    (4,local_4b4,
                     "pRmApi->Control(pRmApi, RES_GET_CLIENT_HANDLE(pSubdevice), RES_GET_HANDLE(pSubdevice), NV2080_CTRL_CMD_GPU_PROMOTE_CTX, &params, sizeof(params))"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x886);
          goto LAB_0036c40a;
        }
        if (local_21a != '\0') {
          kgrctxMarkCtxBufferInitialized_IMPL(param_1,param_2,param_3,param_4,local_21c);
        }
        local_4b4 = vaListGetRefCount(lVar2 + 0xb8,*(undefined8 *)(lVar9 + 0x2a0),&local_378);
        if (local_4b4 != 0) {
          nvAssertOkFailedNoLog
                    (local_4b4,
                     "vaListGetRefCount(&pKernelGraphicsContextUnicast->ctxPatchBuffer.vAddrList, pLoopKernelChannel->pVAS, &refCount)"
                     ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x89e);
          goto LAB_0036c40a;
        }
        local_4b4 = vaListSetRefCount(lVar1,*(undefined8 *)(lVar9 + 0x2a0),local_378);
      } while (local_4b4 == 0);
      nvAssertOkFailedNoLog
                (local_4b4,
                 "vaListSetRefCount(&pKernelGraphicsContextUnicast->pmCtxswBuffer.vAddrList, pLoopKernelChannel->pVAS, refCount)"
                 ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x8a1);
LAB_0036c40a:
      if (*(char *)(param_3 + 0x205) != '\0') {
        puVar3 = *(undefined8 **)(*(long *)(param_4 + 0x140) + 0x48);
        puVar11 = puVar3;
        if (*(char *)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x138) + 0x158) == '\0') {
          puVar11 = *(undefined8 **)(*(long *)(*(long *)(param_4 + 0x2b8) + 0x110) + 0x48);
        }
        kchannelGetIter(local_4a8,*puVar3,puVar11);
        memcpy(local_268,local_4a8,0x108);
        while (cVar5 = clientRefOrderedIterNext(local_180,local_268), cVar5 != '\0') {
          lVar9 = __nvoc_dynamicCast(*(undefined8 *)(local_168 + 8),__nvoc_class_def_KernelChannel);
          if (lVar9 != 0) {
            while (iVar7 = vaListFindVa(lVar2 + 0x148,*(undefined8 *)(lVar9 + 0x2a0),local_370),
                  iVar7 == 0) {
              kgraphicsUnmapCtxBuffer_IMPL
                        (param_1,param_3,*(undefined8 *)(lVar9 + 0x2a0),lVar2 + 0x148);
            }
          }
        }
      }
      kgrctxFreePmBuffer_IMPL(param_1,param_2);
      return local_4b4;
    }
    if (*(long *)(lVar2 + 0x140) != 0) {
      return 0;
    }
    nvAssertFailedNoLog("pKernelGraphicsContextUnicast->pmCtxswBuffer.pMemDesc != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x82d);
  }
  return 0x40;
}


// ===== 0036c660 kgrctxFreeLocalGlobalCtxBuffers_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgrctxFreeLocalGlobalCtxBuffers_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  lVar1 = *(long *)(param_2 + 0x148);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xb9f);
    return;
  }
  if (*(char *)(lVar1 + 0x1e0) != '\0') {
    lVar2 = *(long *)(param_1 + 0x1b70);
    puVar5 = (undefined8 *)(lVar1 + 400);
    do {
      uVar3 = *puVar5;
      puVar6 = puVar5 + 1;
      memdescFree(uVar3);
      memdescDestroy(uVar3);
      *puVar5 = 0;
      puVar5 = puVar6;
    } while (puVar6 != (undefined8 *)(lVar1 + 0x1e0));
    *(undefined1 *)(lVar1 + 0x1e0) = 0;
    iVar4 = (**(code **)(lVar2 + 0x188))(param_1,lVar2,0,2,3);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "kmemsysCacheOp_HAL(pGpu, pKernelMemorySystem, NULL, FB_CACHE_VIDEO_MEMORY, FB_CACHE_EVICT)"
                 ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xbb5);
      return;
    }
  }
  return;
}


// ===== 0036c7a0 kgrctxFreeAssociatedCtxBuffers_IMPL =====

void kgrctxFreeAssociatedCtxBuffers_IMPL(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x148) == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xbc9);
    return;
  }
  if (*(int *)(*(long *)(param_2 + 0x148) + 0x98) == 0) {
    kgrctxFreePatchBuffer_IMPL();
    kgrctxFreePmBuffer_IMPL(param_1,param_2);
    kgrctxFreeZcullBuffer_IMPL(param_1,param_2);
    kgrctxFreeCtxPreemptionBuffers_IMPL(param_1,param_2);
    kgrctxFreeLocalGlobalCtxBuffers_IMPL(param_1,param_2);
    kgrctxFreeMainCtxBuffer_IMPL(param_1,param_2);
    return;
  }
  return;
}


// ===== 0036c862 kgrctxUnmapCtxBuffers_IMPL.cold =====

void kgrctxUnmapCtxBuffers_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0036c870 kgrctxUnmapCtxBuffers_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kgrctxUnmapCtxBuffers_IMPL(long param_1,long param_2,long param_3,long param_4,char param_5)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  long lVar8;
  uint local_44;
  ulong local_40 [2];
  
  if (param_3 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar8 = *(long *)(param_3 + 0x1d8);
  lVar2 = *(long *)(lVar8 + 0x178);
  uVar1 = *(undefined4 *)(lVar8 + 0x180);
  uVar5 = (**(code **)(param_2 + 0x140))(param_1,param_2,lVar2);
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xbfe,"kgrctxUnmapCtxBuffers_IMPL",1,
               "NVRM: gpu:%d isBC=%d\n",*(undefined4 *)(param_1 + 0x7a4));
  uVar6 = kchannelGetGfid_IMPL(lVar2);
  lVar3 = *(long *)(*(long *)(param_3 + 0x208) + 0x148);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e,0);
    nvAssertOkFailedNoLog
              (0x40,
               "kgrctxGetUnicast(pGpu, kgrobjGetKernelGraphicsContext(pGpu, pKernelGraphicsObject), &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xc03);
    return 0x40;
  }
  kgrmgrGetGrObjectType_IMPL(uVar1,&local_44);
  if (param_5 == '\0') {
    kgrctxUnmapMainCtxBuffer_IMPL(param_1,param_2,param_4,*(undefined8 *)(lVar8 + 0x178));
    kgrctxFreeMainCtxBuffer_IMPL(param_1,param_2);
    return 0;
  }
  if ((*(int *)(lVar3 + 0x98) != 0) && (*(long *)(lVar3 + 0xb0) != 0)) {
    kgraphicsUnmapCtxBuffer_IMPL(param_1,param_4,*(undefined8 *)(lVar2 + 0x2a0),lVar3 + 0xb8);
  }
  if (((*(long *)(lVar3 + 0x140) != 0) &&
      (iVar7 = vaListGetRefCount(lVar3 + 0x148,*(undefined8 *)(lVar2 + 0x2a0),local_40), iVar7 == 0)
      ) && (1 < local_40[0])) {
    if (*(long *)(param_2 + 0x148) == 0) {
      nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
      nvAssertOkFailedNoLog
                (0x40,
                 "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0x8df);
    }
    else {
      kgraphicsUnmapCtxBuffer_IMPL
                (param_1,param_4,*(undefined8 *)(lVar2 + 0x2a0),*(long *)(param_2 + 0x148) + 0x148);
    }
  }
  if (((*(char *)(param_4 + 0x207) != '\0') &&
      (iVar7 = vaListGetRefCount(lVar3 + 0x1f0 + (ulong)uVar5 * 0x40,*(undefined8 *)(lVar2 + 0x2a0),
                                 local_40), iVar7 == 0)) && (1 < local_40[0])) {
    kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_4,*(undefined8 *)(lVar2 + 0x2a0),uVar5);
  }
  lVar8 = kgraphicsGetGlobalCtxBuffers_IMPL(param_1,param_4,uVar6);
  if (((*(long *)(lVar8 + 0x30) != 0) &&
      (iVar7 = vaListGetRefCount(lVar3 + 0x370,*(undefined8 *)(lVar2 + 0x2a0),local_40), iVar7 == 0)
      ) && (1 < local_40[0])) {
    kgrctxUnmapGlobalCtxBuffer_IMPL(param_1,param_2,param_4,*(undefined8 *)(lVar2 + 0x2a0),6);
  }
  if (*(char *)(*(long *)(*(long *)(lVar2 + 0x2b8) + 0x138) + 0x159) == '\0') {
    if (1 < local_44) {
      return 0;
    }
    if (*(int *)(lVar3 + 0xa0) != 0) goto LAB_0036ca63;
    iVar7 = *(int *)(lVar3 + 0x9c);
  }
  else {
    iVar7 = *(int *)(lVar3 + 0x98);
  }
  if (iVar7 == 0) {
    return 0;
  }
LAB_0036ca63:
  kgrctxUnmapGlobalCtxBuffers_IMPL(param_1,param_2,param_4,*(undefined8 *)(lVar2 + 0x2a0),uVar6);
  return 0;
}


// ===== 0036cbc0 kgrctxIncObjectCount_IMPL =====

undefined1  [16] kgrctxIncObjectCount_IMPL(undefined8 param_1,long param_2,undefined4 param_3)

{
  uint uVar1;
  long lVar2;
  undefined1 auVar3 [16];
  undefined8 uStack_40;
  uint local_2c [3];
  
  uStack_40 = 0x36cbe4;
  kgrmgrGetGrObjectType_IMPL(param_3,local_2c);
  lVar2 = *(long *)(param_2 + 0x148);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    auVar3 = nvAssertOkFailedNoLog
                       (0x40,
                        "kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
                        ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xc72);
    return auVar3;
  }
  if (local_2c[0] == 2) {
    *(int *)(lVar2 + 0xa4) = *(int *)(lVar2 + 0xa4) + 1;
  }
  else if (local_2c[0] < 3) {
    if (local_2c[0] == 0) {
      *(int *)(lVar2 + 0x9c) = *(int *)(lVar2 + 0x9c) + 1;
    }
    else {
      *(int *)(lVar2 + 0xa0) = *(int *)(lVar2 + 0xa0) + 1;
    }
  }
  else {
    if (local_2c[0] != 3) {
      auVar3 = nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xc8a,
                            "kgrctxIncObjectCount_IMPL",4,"NVRM: Unrecognized graphics class 0x%x\n"
                            ,param_3);
      return auVar3;
    }
    *(int *)(lVar2 + 0xa8) = *(int *)(lVar2 + 0xa8) + 1;
    uStack_40 = 0x36cc83;
    gpuChangeComputeModeRefCount_IMPL(param_1,10);
  }
  uVar1 = *(int *)(lVar2 + 0x98) + 1;
  auVar3._4_4_ = 0;
  auVar3._0_4_ = uVar1;
  *(uint *)(lVar2 + 0x98) = uVar1;
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xc91,"kgrctxIncObjectCount_IMPL",1,
               "NVRM: Class 0x%x allocated.  %d objects allocated\n",param_3);
  auVar3._8_8_ = uStack_40;
  return auVar3;
}


// ===== 0036cd20 kgrctxDecObjectCount_IMPL =====

void kgrctxDecObjectCount_IMPL(undefined8 param_1,long param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  uint local_2c [3];
  
  kgrmgrGetGrObjectType_IMPL(param_3,local_2c);
  lVar2 = *(long *)(param_2 + 0x148);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    nvAssertOkFailedNoLog
              (0x40,"kgrctxGetUnicast(pGpu, pKernelGraphicsContext, &pKernelGraphicsContextUnicast)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xcab);
    return;
  }
  if (*(int *)(lVar2 + 0x98) == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContextUnicast->channelObjects != 0",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0xcaf);
    nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xcb0,"kgrctxDecObjectCount_IMPL",4,
                 "NVRM: No active GR objects to free for Class 0x%x\n",param_3);
  }
  uVar3 = (ulong)local_2c[0];
  if (local_2c[0] != 2) {
    if (local_2c[0] < 3) {
      uVar3 = (ulong)(local_2c[0] != 0);
    }
    else {
      if (local_2c[0] != 3) {
        nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xcc9,"kgrctxDecObjectCount_IMPL"
                     ,4,"NVRM: Unrecognized graphics class 0x%x\n",param_3);
        return;
      }
      gpuChangeComputeModeRefCount_IMPL(param_1,0xb);
      uVar3 = 3;
    }
  }
  iVar1 = *(int *)(lVar2 + 0x9c + uVar3 * 4);
  if (iVar1 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsContextUnicast->objectCounts[countIdx] > 0",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0xccf);
  }
  else {
    *(int *)(lVar2 + 0x9c + uVar3 * 4) = iVar1 + -1;
    *(int *)(lVar2 + 0x98) = *(int *)(lVar2 + 0x98) + -1;
  }
  return;
}


// ===== 0036cec0 kgrctxGetRegisterAccessMapId_IMPL =====

char kgrctxGetRegisterAccessMapId_IMPL(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = kchannelCheckIsAdmin_IMPL(param_3);
  if (cVar1 != '\0') {
    cVar1 = hypervisorIsVgxHyper_IMPL();
    if (cVar1 == '\0') {
      iVar2 = kchannelGetGfid_IMPL(param_3);
      return (iVar2 == 0) + '\a';
    }
  }
  return '\a';
}


// ===== 0036cf20 kgrctxCtrlGetTpcPartitionMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 kgrctxCtrlGetTpcPartitionMode_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*(char *)(lVar1 + 0x909) == '\0') {
        uVar4 = gpuresInternalControlForward_IMPL
                          (*(undefined8 *)(param_1 + 0x128),0x900104,param_2,8);
        return uVar4;
      }
      lVar5 = resservGetTlsCallContext();
      puVar2 = *(undefined4 **)(lVar5 + 0x48);
      uVar4 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0xcf8);
  return 0x2f;
}


// ===== 0036cff0 kgrctxCtrlSetTpcPartitionMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 kgrctxCtrlSetTpcPartitionMode_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*(char *)(lVar1 + 0x909) == '\0') {
        uVar4 = gpuresInternalControlForward_IMPL
                          (*(undefined8 *)(param_1 + 0x128),0x900102,param_2,8);
        return uVar4;
      }
      lVar5 = resservGetTlsCallContext();
      puVar2 = *(undefined4 **)(lVar5 + 0x48);
      uVar4 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0xd17);
  return 0x2f;
}


// ===== 0036d0c0 kgrctxCtrlSetLgSectorPromotion_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 kgrctxCtrlSetLgSectorPromotion_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*(char *)(lVar1 + 0x909) == '\0') {
        uVar4 = gpuresInternalControlForward_IMPL
                          (*(undefined8 *)(param_1 + 0x128),0x90010c,param_2,4);
        return uVar4;
      }
      lVar5 = resservGetTlsCallContext();
      puVar2 = *(undefined4 **)(lVar5 + 0x48);
      uVar4 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0xd36);
  return 0x2f;
}


// ===== 0036d190 kgrctxCtrlGetMMUDebugMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 kgrctxCtrlGetMMUDebugMode_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*(char *)(lVar1 + 0x909) == '\0') {
        uVar4 = gpuresInternalControlForward_IMPL
                          (*(undefined8 *)(param_1 + 0x128),0x900106,param_2,1);
        return uVar4;
      }
      lVar5 = resservGetTlsCallContext();
      puVar2 = *(undefined4 **)(lVar5 + 0x48);
      uVar4 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0xd55);
  return 0x2f;
}


// ===== 0036d260 kgrctxCtrlProgramVidmemPromote_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgrctxCtrlProgramVidmemPromote_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_graphics_context.c",0xd74);
    return 0x2f;
  }
  if ((*(char *)(lVar1 + 0x908) == '\0') && (*(char *)(lVar1 + 0x909) == '\0')) {
    uVar4 = gpuresInternalControlForward_IMPL(*(undefined8 *)(param_1 + 0x128),0x900108,param_2,8);
    return uVar4;
  }
  lVar5 = resservGetTlsCallContext();
  puVar2 = *(undefined4 **)(lVar5 + 0x48);
  lVar5 = gpuGetRpc(lVar1);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gr/kernel_graphics_context.c",0xd7c);
    return 0x1a;
  }
  if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
    uVar4 = rpcDmaControl_wrapper
                      (lVar1,lVar5,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),puVar2[6]
                      );
    return uVar4;
  }
  uVar4 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
  return uVar4;
}


// ===== 0036d3b0 shrkgrctxConstruct_IMPL =====

undefined8 shrkgrctxConstruct_IMPL(void)

{
  return 0;
}


// ===== 0036d3c0 shrkgrctxDestruct_IMPL =====

void shrkgrctxDestruct_IMPL(long param_1)

{
  int iVar1;
  
  param_1 = param_1 + 0x680;
  iVar1 = listCount_IMPL(param_1);
  if (iVar1 == 0) {
    listDestroy_IMPL(param_1);
    return;
  }
  nvAssertFailedNoLog("listCount(&pKernelGraphicsContextShared->activeDebuggers) == 0",
                      "src/kernel/gpu/gr/kernel_graphics_context.c",0xdfc);
  listDestroy_IMPL(param_1);
  return;
}


// ===== 0036d420 shrkgrctxDestructUnicast_IMPL =====

void shrkgrctxDestructUnicast_IMPL(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x4a23) != '\0') {
    kgrctxFreeAssociatedCtxBuffers_IMPL(param_1,param_3);
  }
  lVar1 = param_4 + 0x158;
  do {
    lVar2 = lVar1 + 0x40;
    vaListDestroy(lVar1);
    lVar1 = lVar2;
  } while (lVar2 != param_4 + 0x3d8);
  vaListDestroy(param_4 + 0x20);
  vaListDestroy(param_4 + 0xb0);
  vaListDestroy(param_4 + 0x68);
  vaListDestroy(param_4 + 1000);
  vaListDestroy(param_4 + 0x430);
  vaListDestroy(param_4 + 0x478);
  vaListDestroy(param_4 + 0x4c0);
  vaListDestroy(param_4 + 0x508);
  vaListDestroy(param_4 + 0x550);
  return;
}


// ===== 0036d500 kgrctxDestruct_IMPL =====

void kgrctxDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (*(long *)(param_1 + 0x148) != 0) {
    uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x148) + 0x88);
  }
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  iVar3 = serverGetShareRefCount(g_resServ,uVar4);
  if (iVar3 == 1) {
    lVar2 = *(long *)(param_1 + 0x148);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    }
    else {
      shrkgrctxDestructUnicast_IMPL(uVar1,lVar2,param_1,lVar2 + 0x98);
    }
    portMemSet(*(long *)(param_1 + 0x148) + 0x98,0,0x5e8);
  }
  serverFreeShare(g_resServ,uVar4);
  return;
}


// ===== 0036d5d0 shrkgrctxInit_IMPL =====

int shrkgrctxInit_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 local_50;
  undefined1 local_48 [24];
  
  uVar6 = *(undefined8 *)(param_1 + 0x1bc8);
  uVar2 = *(undefined8 *)(*(long *)(param_3 + 0x128) + 0xe8);
  uVar1 = *(undefined4 *)(*(long *)(*(long *)(*(long *)(param_3 + 0x110) + 0x48) + 0x18) + 0x10);
  portMemSet(local_48,0,0x10);
  kgrmgrCtrlSetChannelHandle_IMPL(uVar1,local_48);
  iVar4 = kgrmgrCtrlRouteKGRWithDevice_IMPL(param_1,uVar6,uVar2,local_48,&local_50);
  if (iVar4 == 0) {
    lVar3 = *(long *)(param_3 + 0x148);
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    }
    else {
      lVar7 = lVar3 + 0x1f0;
      do {
        iVar5 = vaListInit(lVar7);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,"vaListInit(&pKernelGraphicsContextUnicast->globalCtxBufferVaList[i])",
                     "src/kernel/gpu/gr/kernel_graphics_context.c",0xde2);
          goto LAB_0036d6b9;
        }
        lVar7 = lVar7 + 0x40;
      } while (lVar3 + 0x470 != lVar7);
      iVar5 = shrkgrctxConstructUnicast_IMPL_part_0(local_50,lVar3 + 0x98);
      if (iVar5 != 0) {
LAB_0036d6b9:
        nvCheckOkFailedNoLog
                  (4,iVar5,
                   "shrkgrctxConstructUnicast(pGpu, pKernelGraphicsContextShared, pKernelGraphicsContext, pKernelGraphics, pKernelGraphicsContextUnicast)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xdbb);
        iVar4 = iVar5;
        goto LAB_0036d6e0;
      }
    }
    uVar6 = portMemAllocatorGetGlobalNonPaged();
    listInit_IMPL(param_2 + 0x680,uVar6,8);
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar4,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xdb3);
LAB_0036d6e0:
    uVar6 = portMemAllocatorGetGlobalNonPaged();
    listInit_IMPL(param_2 + 0x680,uVar6,8);
    if (*(long *)(param_3 + 0x148) == 0) {
      nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    }
    else {
      shrkgrctxDestructUnicast_IMPL(param_1,param_2,param_3,*(long *)(param_3 + 0x148) + 0x98);
    }
    portMemSet(*(long *)(param_3 + 0x148) + 0x98,0,0x5e8);
  }
  return iVar4;
}


// ===== 0036d800 kgrctxConstruct_IMPL =====

int kgrctxConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_20 [2];
  
  if (*(long *)(param_3 + 0x58) == 0) {
    iVar1 = serverAllocShare(g_resServ,__nvoc_class_def_KernelGraphicsContextShared,local_20);
    if (iVar1 == 0) {
      uVar3 = __nvoc_dynamicCast(local_20[0],__nvoc_class_def_KernelGraphicsContextShared);
      *(undefined8 *)(param_1 + 0x148) = uVar3;
      iVar1 = shrkgrctxInit_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0),uVar3,param_1);
      if (iVar1 == 0) {
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar1,
                 "shrkgrctxInit(GPU_RES_GET_GPU(pKernelGraphicsContext), pKernelGraphicsContext->pShared, pKernelGraphicsContext)"
                 ,"src/kernel/gpu/gr/kernel_graphics_context.c",0x1e3);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,
                 "serverAllocShare(&g_resServ, classInfo(KernelGraphicsContextShared), &pShared)",
                 "src/kernel/gpu/gr/kernel_graphics_context.c",0x1de);
    }
    if (*(long *)(param_1 + 0x148) != 0) {
      serverFreeShare(g_resServ,local_20[0]);
    }
  }
  else {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_3 + 0x58) + 8),
                               __nvoc_class_def_KernelGraphicsContext);
    lVar2 = *(long *)(lVar2 + 0x148);
    *(long *)(param_1 + 0x148) = lVar2;
    uVar3 = 0;
    if (lVar2 != 0) {
      uVar3 = *(undefined8 *)(lVar2 + 0x88);
    }
    serverRefShare(g_resServ,uVar3);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 0036d930 shrkgrctxDetach_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void shrkgrctxDetach_IMPL(long param_1,undefined8 param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  int local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_54 = *(int *)(param_4 + 0x42c);
  uVar4 = local_54 - 1;
  if (0x52 < uVar4) {
    cVar3 = kchannelIsRunlistSet(param_1,param_4);
    if (cVar3 == '\0') {
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_context.c",0xe55,"shrkgrctxDetach_IMPL",1,
                   "NVRM: Channel destroyed but never bound, scheduled, or had a descendant object created\n"
                  );
    }
    else {
      lVar6 = gpuGetKernelFifoShared_IMPL(param_1);
      iVar5 = (**(code **)(lVar6 + 0x218))
                        (param_1,lVar6,3,*(undefined4 *)(param_4 + 0x2b0),2,&local_54);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RUNLIST, kchannelGetRunlistId(pKernelChannel), ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&rmEngineType)"
                   ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xe4e);
        uVar4 = local_54 - 1;
        goto joined_r0x0036d9ef;
      }
    }
    uVar4 = local_54 - 1;
  }
joined_r0x0036d9ef:
  if (uVar4 < 8) {
    local_40 = 0;
    lVar6 = *(long *)(*(long *)(param_4 + 0x158) + 0xe0);
    uVar1 = *(undefined8 *)(*(long *)(param_4 + 0x158) + 0xe8);
    local_48 = 0;
    uVar2 = *(undefined8 *)(lVar6 + 0x1bc8);
    kgrmgrCtrlSetChannelHandle_IMPL
              (*(undefined4 *)(*(long *)(*(long *)(param_4 + 0x140) + 0x48) + 0x10),&local_48);
    iVar5 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar6,uVar2,uVar1,&local_48,&local_50);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
                 ,"src/kernel/gpu/gr/kernel_graphics_context.c",0xe63);
      return;
    }
    nvEventBufferFecsCallback(lVar6,local_50);
  }
  if (*(char *)(param_1 + 0x4a23) != '\0') {
    if (*(long *)(param_3 + 0x148) == 0) {
      nvAssertFailedNoLog("pKernelGraphicsContext->pShared != NULL",
                          "src/kernel/gpu/gr/kernel_graphics_context.c",0x22e);
    }
    else {
      kgrctxUnmapBuffers_KERNEL(param_1,param_3,*(long *)(param_3 + 0x148) + 0x98,param_4);
    }
  }
  return;
}


// ===== 0036db30 kgrmgrGetGrObjectType_IMPL =====

void kgrmgrGetGrObjectType_IMPL(uint param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 != 0xc0c0) {
    if (param_1 < 0xc0c1) {
      iVar1 = 1;
      if (param_1 == 0x902d) goto LAB_0036dc0d;
      if (0x902c < param_1) {
        if (param_1 == 0xa140) goto LAB_0036dc08;
        if (0xa13f < param_1) {
          if (param_1 == 0xb197) goto LAB_0036dc70;
          if (param_1 < 0xb198) {
            if (param_1 == 0xb097) goto LAB_0036dc70;
            iVar1 = (param_1 != 0xb0c0) + 3;
            goto LAB_0036dc0d;
          }
          if (param_1 != 0xb1c0) {
            iVar1 = (uint)(param_1 != 0xc097) << 2;
            goto LAB_0036dc0d;
          }
          goto LAB_0036dc68;
        }
      }
      iVar1 = 4;
      goto LAB_0036dc0d;
    }
    if (param_1 == 0xcb97) {
LAB_0036dc70:
      *param_2 = 0;
      return;
    }
    if (0xcb97 < param_1) {
      if (param_1 != 0xcd40) {
        if (param_1 < 0xcd41) {
          iVar1 = (param_1 != 0xcbc0) + 3;
        }
        else {
          if (param_1 == 0xce97) goto LAB_0036dc70;
          if (param_1 < 0xce98) {
            if (param_1 == 0xcd97) goto LAB_0036dc70;
            iVar1 = (param_1 != 0xcdc0) + 3;
          }
          else {
            iVar1 = (param_1 != 0xcec0) + 3;
          }
        }
        goto LAB_0036dc0d;
      }
LAB_0036dc08:
      iVar1 = 2;
      goto LAB_0036dc0d;
    }
    if (param_1 == 0xc697) goto LAB_0036dc70;
    if (param_1 < 0xc698) {
      if (param_1 != 0xc3c0) {
        if (0xc3c0 < param_1) {
          if (param_1 == 0xc597) goto LAB_0036dc70;
          iVar1 = (param_1 != 0xc5c0) + 3;
          goto LAB_0036dc0d;
        }
        if (param_1 != 0xc1c0) {
          iVar1 = (uint)((param_1 & 0xfffffdff) != 0xc197) << 2;
          goto LAB_0036dc0d;
        }
      }
    }
    else if (param_1 != 0xc7c0) {
      if (0xc7c0 < param_1) {
        if (param_1 == 0xc997) goto LAB_0036dc70;
        iVar1 = (param_1 != 0xc9c0) + 3;
        goto LAB_0036dc0d;
      }
      if (param_1 != 0xc6c0) {
        iVar1 = (uint)(param_1 != 0xc797) << 2;
        goto LAB_0036dc0d;
      }
    }
  }
LAB_0036dc68:
  iVar1 = 3;
LAB_0036dc0d:
  *param_2 = iVar1;
  return;
}


// ===== 0036dd10 kgrmgrIsCtxBufSupported_IMPL =====

ulong kgrmgrIsCtxBufSupported_IMPL(ulong param_1,uint param_2)

{
  ulong uVar1;
  
  if (9 < (uint)param_1) {
    nvAssertFailedNoLog("NV_ENUM_IS(GR_CTX_BUFFER, bufId)",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0xa4);
    return 0;
  }
  if ((char)param_2 == '\0') {
    uVar1 = CONCAT71(1,(0x105UL >> (param_1 & 0x3f) & 1) != 0);
    if ((uint)param_1 == 9) {
      uVar1 = (ulong)param_2;
    }
    return uVar1;
  }
  return 1;
}


// ===== 0036dd70 kgrmgrIsGlobalCtxBufSupported_IMPL =====

bool kgrmgrIsGlobalCtxBufSupported_IMPL(uint param_1,char param_2)

{
  if (9 < param_1) {
    nvAssertFailedNoLog("NV_ENUM_IS(GR_GLOBALCTX_BUFFER, bufId)",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0xda);
    return false;
  }
  if (param_2 == '\0') {
    return param_1 - 6 < 4;
  }
  return true;
}


// ===== 0036ddc0 kgrmgrCtrlSetEngineID_IMPL =====

void kgrmgrCtrlSetEngineID_IMPL(uint param_1,byte *param_2)

{
  if ((param_2 != (byte *)0x0) && ((*param_2 & 3) == 0)) {
    param_2[0] = 1;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    *(ulong *)(param_2 + 8) = (ulong)param_1;
  }
  return;
}


// ===== 0036dde0 kgrmgrCtrlSetChannelHandle_IMPL =====

void kgrmgrCtrlSetChannelHandle_IMPL(uint param_1,byte *param_2)

{
  if ((param_2 != (byte *)0x0) && ((*param_2 & 3) == 0)) {
    param_2[0] = 2;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    *(ulong *)(param_2 + 8) = (ulong)param_1;
  }
  return;
}


// ===== 0036de00 kgrmgrConstructEngine_IMPL =====

undefined8 kgrmgrConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  fecsGlobalLoggingInit(param_1,param_2,param_2 + 0x488);
  return 0;
}


// ===== 0036de20 kgrmgrDestruct_IMPL =====

void kgrmgrDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  fecsGlobalLoggingTeardown(uVar1,param_1);
  portMemSet(param_1 + 0x170,0,0x2b8);
  portMemFree(*(undefined8 *)(param_1 + 0x428));
  *(undefined8 *)(param_1 + 0x428) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0x430));
  *(undefined1 *)(param_1 + 0x438) = 0;
  *(undefined8 *)(param_1 + 0x430) = 0;
  return;
}


// ===== 0036dea0 kgrmgrStateDestroy_IMPL =====

void kgrmgrStateDestroy_IMPL(void)

{
  fecsRemoveAllBindpointsForGpu();
  return;
}


// ===== 0036deb0 kgrmgrSetLegacyKgraphicsStaticInfo_IMPL =====

void kgrmgrSetLegacyKgraphicsStaticInfo_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long *plVar1;
  long lVar2;
  
  if (*(char *)(param_2 + 0x438) != '\0') {
    nvCheckFailedNoLog(1,"!pKernelGraphicsManager->legacyKgraphicsStaticInfo.bInitialized",
                       "src/kernel/gpu/gr/kernel_graphics_manager.c",0x174);
    return;
  }
  if ((param_3 == 0) || (*(int *)(param_3 + 0x20c) != 0)) {
    nvAssertFailedNoLog("(pKernelGraphics != NULL) && (kgraphicsGetInstance(pGpu, pKernelGraphics) == 0)"
                        ,"src/kernel/gpu/gr/kernel_graphics_manager.c",0x175);
    return;
  }
  plVar1 = (long *)kgraphicsGetStaticInfo_IMPL(param_1,param_3);
  if (plVar1 == (long *)0x0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x177);
    return;
  }
  portMemCopy(param_2 + 0x170,0x2b8,(long)plVar1 + 0x1104,0x2b8);
  if (plVar1[0x278] == 0) {
LAB_0036df6a:
    if (*plVar1 != 0) {
      lVar2 = portMemAllocNonPaged(0x1d8);
      *(long *)(param_2 + 0x430) = lVar2;
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.pGrInfo != NULL",
                            "src/kernel/gpu/gr/kernel_graphics_manager.c",0x188);
        goto LAB_0036e008;
      }
      portMemCopy(lVar2,0x1d8,*plVar1,0x1d8);
    }
    *(undefined1 *)(param_2 + 0x438) = 1;
  }
  else {
    lVar2 = portMemAllocNonPaged(0x80);
    *(long *)(param_2 + 0x428) = lVar2;
    if (lVar2 != 0) {
      portMemCopy(lVar2,0x80,plVar1[0x278],0x80);
      goto LAB_0036df6a;
    }
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.pPpcMasks != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x17f);
LAB_0036e008:
    portMemFree(*(undefined8 *)(param_2 + 0x428));
    *(undefined8 *)(param_2 + 0x428) = 0;
    portMemFree(*(undefined8 *)(param_2 + 0x430));
    *(undefined8 *)(param_2 + 0x430) = 0;
  }
  return;
}


// ===== 0036e05a kgrmgrCtrlRouteKGRWithDevice_IMPL.cold =====

void kgrmgrCtrlRouteKGRWithDevice_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0036e070 kgrmgrCtrlRouteKGRWithDevice_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgrmgrCtrlRouteKGRWithDevice_IMPL
              (long param_1,undefined8 param_2,long param_3,ulong *param_4,long *param_5)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  long *plVar8;
  long lVar9;
  char *pcVar10;
  undefined8 uVar11;
  long local_58;
  int local_50;
  undefined4 uStack_4c;
  long local_48;
  long local_40;
  ulong local_38;
  ulong local_30;
  ulong uVar7;
  
  local_38 = *param_4;
  local_30 = param_4[1];
  lVar9 = *(long *)(param_1 + 0x1bc0);
  if ((lVar9 == 0) || (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,lVar9), cVar3 == '\0'))
  {
    uVar7 = 0;
    goto LAB_0036e182;
  }
  if (param_3 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = **(long **)(*(long *)(param_3 + 0x110) + 0x48);
  iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,lVar9,param_3,&local_48);
  uVar11 = 0x1bc;
  pcVar10 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
  if (iVar4 != 0) goto LAB_0036e3c6;
  if (local_40 == 0) {
    plVar8 = (long *)__nvoc_dynamicCast(lVar1,__nvoc_class_def_RmClient,
                                        "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)"
                                        ,"src/kernel/gpu/gr/kernel_graphics_manager.c",0x1bc);
    if (plVar8 == (long *)0x0) {
      return 0x33;
    }
    uVar6 = (**(code **)(*plVar8 + 0xd8))();
    cVar3 = (**(code **)(*plVar8 + 0xe0))(plVar8,uVar6);
    if (cVar3 == '\0') {
      pcVar10 = (char *)(local_48 + 0x198);
      if (local_48 == 0) {
        nvAssertFailedNoLog("pKernelMIGGpuInstance != NULL",
                            "src/kernel/gpu/gr/kernel_graphics_manager.c",0x4f);
      }
      else {
        do {
          if (*pcVar10 != '\0') {
            return 0x1b;
          }
          pcVar10 = pcVar10 + 0x110;
        } while (pcVar10 != (char *)(local_48 + 0xa18));
      }
    }
    if (((uint)local_38 & 3) != 2) {
      if (((uint)local_38 & 3) == 3) {
LAB_0036e270:
        nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_manager.c",0x22e,
                     "kgrmgrCtrlRouteKGRWithDevice_IMPL",4,
                     "NVRM: Unrecognized GR Route flag type 0x%x!\n",3);
        return 0x1f;
      }
      if ((local_38 & 3) == 0) {
        nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_manager.c",0x1db,
                     "kgrmgrCtrlRouteKGRWithDevice_IMPL",4,
                     "NVRM: Cannot give GR Route flag of TYPE_NONE with MIG enabled!\n");
        return 0x1f;
      }
LAB_0036e1c2:
      iVar4 = (int)local_30 + 1;
      goto LAB_0036e146;
    }
LAB_0036e2a0:
    uVar7 = local_30;
    iVar4 = CliGetKernelChannel(lVar1,local_30 & 0xffffffff,&local_58);
    if (iVar4 == 0) {
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_manager.c",0x21c,
                   "kgrmgrCtrlRouteKGRWithDevice_IMPL",1,
                   "NVRM: Found channel with given handle 0x%08x, using this to determine GR engine ID\n"
                   ,uVar7 & 0xffffffff);
      iVar4 = *(int *)(local_58 + 0x42c);
    }
    else {
      iVar4 = CliGetChannelGroup(*(undefined4 *)(lVar1 + 0x48),uVar7 & 0xffffffff,&local_50,0);
      if (iVar4 != 0) {
        iVar4 = *(int *)(lVar1 + 0x48);
        uVar7 = uVar7 & 0xffffffff;
        pcVar10 = 
        "NVRM: Failed to find a channel or TSG with given handle 0x%08x associated with hClient=0x%08x\n"
        ;
        uVar11 = 0x206;
        goto LAB_0036e453;
      }
      lVar9 = __nvoc_dynamicCast(*(undefined8 *)(CONCAT44(uStack_4c,local_50) + 8),
                                 __nvoc_class_def_KernelChannelGroupApi);
      if ((lVar9 == 0) || (lVar9 = *(long *)(lVar9 + 0x138), lVar9 == 0)) {
        nvAssertFailedNoLog("(pKernelChannelGroupApi != NULL && pKernelChannelGroupApi->pKernelChannelGroup != NULL)"
                            ,"src/kernel/gpu/gr/kernel_graphics_manager.c",0x20e);
        return 0x40;
      }
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_manager.c",0x215,
                   "kgrmgrCtrlRouteKGRWithDevice_IMPL",1,
                   "NVRM: Found TSG with given handle 0x%08x, using this to determine GR engine ID\n"
                   ,uVar7 & 0xffffffff);
      iVar4 = *(int *)(lVar9 + 0xfc);
    }
    uVar5 = iVar4 - 1;
    if (7 < uVar5) {
      uVar5 = gpuGetNv2080EngineType_IMPL(iVar4);
      pcVar10 = "NVRM: Failed to route GR using non-GR engine type 0x%x (0x%x)\n";
      uVar7 = (ulong)uVar5;
      uVar11 = 0x224;
LAB_0036e453:
      nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_manager.c",uVar11,
                   "kgrmgrCtrlRouteKGRWithDevice_IMPL",4,pcVar10,uVar7,iVar4);
      return 0x1f;
    }
  }
  else {
    portMemSet(&local_38,0,0x10);
    if ((local_38 & 3) != 0) {
      if (((uint)local_38 & 3) != 2) {
        if (((uint)local_38 & 3) == 3) goto LAB_0036e270;
        goto LAB_0036e1c2;
      }
      goto LAB_0036e2a0;
    }
    local_38 = CONCAT44(local_38._4_4_,1);
    iVar4 = 1;
    local_30 = 0;
LAB_0036e146:
    iVar4 = kmigmgrGetLocalToGlobalEngineType_IMPL(param_1,lVar9,local_48,local_40,iVar4,&local_50);
    if (iVar4 != 0) {
      uVar11 = 0x1e5;
      pcVar10 = 
      "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(localGrIdx), &globalRmEngType)"
      ;
LAB_0036e3c6:
      nvCheckOkFailedNoLog(4,iVar4,pcVar10,"src/kernel/gpu/gr/kernel_graphics_manager.c",uVar11);
      return iVar4;
    }
    uVar5 = local_50 - 1;
    if (7 < uVar5) {
      nvAssertFailedNoLog("RM_ENGINE_TYPE_IS_GR(globalRmEngType)",
                          "src/kernel/gpu/gr/kernel_graphics_manager.c",0x1ea);
      return 0x40;
    }
  }
  uVar7 = (ulong)uVar5;
LAB_0036e182:
  lVar9 = *(long *)(param_1 + 0x1bd0 + uVar7 * 8);
  if (lVar9 == 0) {
    nvAssertFailedNoLog("pKernelGraphics != NULL","src/kernel/gpu/gr/kernel_graphics_manager.c",
                        0x235);
    iVar4 = 0x40;
  }
  else {
    if (param_5 != (long *)0x0) {
      *param_5 = lVar9;
    }
    iVar4 = 0;
  }
  return iVar4;
}


// ===== 0036e510 kgrmgrGetLegacyGpcMask_IMPL =====

undefined4 kgrmgrGetLegacyGpcMask_IMPL(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x438) != '\0') {
    return *(undefined4 *)(param_2 + 0x170);
  }
  nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.bInitialized",
                      "src/kernel/gpu/gr/kernel_graphics_manager.c",0x247);
  return 0;
}


// ===== 0036e550 kgrmgrGetLegacyTpcMask_IMPL =====

undefined4 kgrmgrGetLegacyTpcMask_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (*(char *)(param_2 + 0x438) == '\0') {
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.bInitialized",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x26d);
  }
  else if (*(long *)(param_2 + 0x430) == 0) {
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.pGrInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x26e);
  }
  else {
    if (param_3 < *(uint *)(*(long *)(param_2 + 0x430) + 0xa4)) {
      return *(undefined4 *)(param_2 + 0x174 + (ulong)param_3 * 4);
    }
    nvCheckFailedNoLog(4,"(gpcId < maxNumGpcs)","src/kernel/gpu/gr/kernel_graphics_manager.c",0x271)
    ;
  }
  return 0;
}


// ===== 0036e5f0 kgrmgrGetLegacyPpcMask_IMPL =====

undefined8
kgrmgrGetLegacyPpcMask_IMPL(undefined8 param_1,long param_2,uint param_3,undefined4 *param_4)

{
  if (*(char *)(param_2 + 0x438) == '\0') {
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.bInitialized",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x284);
  }
  else {
    if (*(long *)(param_2 + 0x430) != 0) {
      if (param_3 < *(uint *)(*(long *)(param_2 + 0x430) + 0xa4)) {
        if (param_4 != (undefined4 *)0x0) {
          if (*(long *)(param_2 + 0x428) != 0) {
            *param_4 = *(undefined4 *)(*(long *)(param_2 + 0x428) + (ulong)param_3 * 4);
            return 0;
          }
          nvAssertFailedNoLog("(pKernelGraphicsManager->legacyKgraphicsStaticInfo.pPpcMasks != NULL)"
                              ,"src/kernel/gpu/gr/kernel_graphics_manager.c",0x289);
          return 0x56;
        }
        nvAssertFailedNoLog("(pPpcMask != NULL)","src/kernel/gpu/gr/kernel_graphics_manager.c",0x288
                           );
      }
      else {
        nvCheckFailedNoLog(4,"(physGpcId < maxNumGpcs)",
                           "src/kernel/gpu/gr/kernel_graphics_manager.c",0x287);
      }
      return 0x1f;
    }
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.pGrInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x285);
  }
  return 0x40;
}


// ===== 0036e6f0 kgrmgrGetLegacyZcullMask_IMPL =====

undefined4 kgrmgrGetLegacyZcullMask_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (*(char *)(param_2 + 0x438) == '\0') {
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.bInitialized",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x29d);
    return 0;
  }
  if (*(long *)(param_2 + 0x430) != 0) {
    if (param_3 < *(uint *)(*(long *)(param_2 + 0x430) + 0xa4)) {
      return *(undefined4 *)(param_2 + 0x3a0 + (ulong)param_3 * 4);
    }
    nvCheckFailedNoLog(4,"(physGpcId < maxNumGpcs)","src/kernel/gpu/gr/kernel_graphics_manager.c",
                       0x2a0);
    return 0x1f;
  }
  nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.pGrInfo != NULL",
                      "src/kernel/gpu/gr/kernel_graphics_manager.c",0x29e);
  return 0x40;
}


// ===== 0036e790 kgrmgrClearVeidsForGrIdx_IMPL =====

void kgrmgrClearVeidsForGrIdx_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = *(ulong *)(param_2 + 0x440);
  uVar1 = *(ulong *)(param_2 + 0x448 + (ulong)param_3 * 8);
  if ((~uVar2 & uVar1) != 0) {
    nvAssertFailedNoLog("(pKernelGraphicsManager->veidInUseMask & veidMask) == veidMask",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x304);
    uVar2 = *(ulong *)(param_2 + 0x440);
  }
  *(ulong *)(param_2 + 0x440) = ~uVar1 & uVar2;
  *(undefined8 *)(param_2 + 0x448 + (ulong)param_3 * 8) = 0;
  return;
}


// ===== 0036e820 kgrmgrGetVeidStepSize_IMPL =====

undefined8 kgrmgrGetVeidStepSize_IMPL(undefined8 param_1,long param_2,undefined4 *param_3)

{
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pVeidStepSize != NULL","src/kernel/gpu/gr/kernel_graphics_manager.c",0x314)
    ;
    return 0x1f;
  }
  if (*(char *)(param_2 + 0x438) == '\0') {
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.bInitialized",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x315);
  }
  else {
    if (*(long *)(param_2 + 0x430) != 0) {
      *param_3 = *(undefined4 *)(*(long *)(param_2 + 0x430) + 0x1bc);
      return 0;
    }
    nvAssertFailedNoLog("pKernelGraphicsManager->legacyKgraphicsStaticInfo.pGrInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x316);
  }
  return 0x40;
}


// ===== 0036e8b0 kgrmgrGetVeidSizePerSpan_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgrmgrGetVeidSizePerSpan_IMPL(long param_1,long param_2,long param_3)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined1 local_40 [8];
  undefined4 local_38;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pVeidSizePerSpan != NULL","src/kernel/gpu/gr/kernel_graphics_manager.c",
                        0x32c);
    return 0x1f;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x1bc0);
  iVar1 = kmigmgrSmallestComputeProfileSize_IMPL(param_1,uVar4);
  if (iVar1 != 8) {
    uVar2 = kmigmgrGetComputeProfileFromSize_IMPL(param_1,uVar4,iVar1,local_40);
    uVar4 = 0x331;
    pcVar3 = 
    "kmigmgrGetComputeProfileFromSize(pGpu, pKernelMIGManager, computeSize, &computeProfile)";
    if ((int)uVar2 == 0) {
      uVar2 = (**(code **)(param_2 + 0x168))(param_1,param_2,local_38,param_3,0x331);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      uVar4 = 0x335;
      pcVar3 = 
      "kgrmgrGetVeidsFromGpcCount_HAL(pGpu, pKernelGraphicsManager, computeProfile.gpcCount, pVeidSizePerSpan)"
      ;
    }
    nvCheckOkFailedNoLog
              (4,uVar2 & 0xffffffff,pcVar3,"src/kernel/gpu/gr/kernel_graphics_manager.c",uVar4);
    return uVar2 & 0xffffffff;
  }
  nvCheckFailedNoLog(4,"computeSize != KMIGMGR_COMPUTE_SIZE_INVALID",
                     "src/kernel/gpu/gr/kernel_graphics_manager.c",0x32f);
  return 0x40;
}


// ===== 0036e9f0 kgrmgrAllocVeidsForGrIdx_IMPL =====

ulong kgrmgrAllocVeidsForGrIdx_IMPL
                (undefined8 param_1,long param_2,uint param_3,int param_4,uint param_5,long param_6)

{
  ulong *puVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  uint local_2c;
  
  lVar3 = param_2 + (ulong)param_3 * 8;
  if (*(long *)(lVar3 + 0x448) != 0) {
    nvAssertFailedNoLog("pKernelGraphicsManager->grIdxVeidMask[grIdx] == 0",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x2c3);
    return 0x40;
  }
  uVar8 = kgrmgrGetVeidSizePerSpan_IMPL(param_1,param_2,&local_2c);
  if (uVar8 != 0) {
    nvAssertOkFailedNoLog
              (uVar8,"kgrmgrGetVeidSizePerSpan(pGpu, pKernelGraphicsManager, &veidSizePerSpan)",
               "src/kernel/gpu/gr/kernel_graphics_manager.c",0x2c5);
    return (ulong)uVar8;
  }
  uVar5 = (ulong)param_5 % (ulong)local_2c;
  if ((int)uVar5 == 0) {
    if (param_4 == -1) {
      nvAssertFailedNoLog("veidSpanOffset != KMIGMGR_SPAN_OFFSET_INVALID",
                          "src/kernel/gpu/gr/kernel_graphics_manager.c",0x2cf);
    }
    else {
      uVar2 = local_2c * param_4 + *(int *)(param_6 + 0x90);
      uVar8 = (param_5 + uVar2) - 1;
      if (uVar8 <= uVar2) {
        nvAssertFailedNoLog("veidStart < veidEnd","src/kernel/gpu/gr/kernel_graphics_manager.c",
                            0x2d4);
        return 0x40;
      }
      if (uVar2 < 0x40) {
        if (uVar8 < 0x40) {
          uVar10 = (0xffffffffffffffffU >> ((-(char)(param_5 + uVar2) & 0x3fU) + (byte)uVar2 & 0x3f)
                   ) << ((byte)uVar2 & 0x3f);
          if (uVar10 == 0) {
            nvAssertFailedNoLog("reqVeidMask != 0x0","src/kernel/gpu/gr/kernel_graphics_manager.c",
                                0x2da);
            return 0x40;
          }
          bVar7 = (byte)*(int *)(param_6 + 0x90);
          bVar6 = bVar7 & 0x3f;
          uVar9 = (0xffffffffffffffffU >>
                  ((-(bVar7 + (char)*(undefined4 *)(param_6 + 0x94)) & 0x3f) + bVar6 & 0x3f)) <<
                  bVar6;
          if (uVar9 == 0) {
            nvAssertFailedNoLog("GPUInstanceVeidMask != 0x0",
                                "src/kernel/gpu/gr/kernel_graphics_manager.c",0x2e0);
            return 0x40;
          }
          uVar4 = *(ulong *)(param_2 + 0x440);
          if ((uVar4 & uVar10) != 0) {
            nvAssertFailedNoLog("(pKernelGraphicsManager->veidInUseMask & reqVeidMask) == 0",
                                "src/kernel/gpu/gr/kernel_graphics_manager.c",0x2e5);
            return 99;
          }
          if ((*(int *)(param_6 + 0x968) != 0) && ((~(~uVar4 & uVar9) & uVar10) != 0)) {
            nvAssertFailedNoLog("((pKernelMIGGPUInstance->swizzId == 0) || ((GPUInstanceFreeVeidMask & reqVeidMask) == reqVeidMask))"
                                ,"src/kernel/gpu/gr/kernel_graphics_manager.c",0x2eb);
            return 0x1a;
          }
          *(ulong *)(param_2 + 0x440) = uVar4 | uVar10;
          puVar1 = (ulong *)(lVar3 + 0x448);
          *puVar1 = *puVar1 | uVar10;
          return uVar5;
        }
        nvAssertFailedNoLog("veidEnd < 64","src/kernel/gpu/gr/kernel_graphics_manager.c",0x2d6);
      }
      else {
        nvAssertFailedNoLog("veidStart < 64","src/kernel/gpu/gr/kernel_graphics_manager.c",0x2d5);
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_manager.c",0x2cb,"kgrmgrAllocVeidsForGrIdx_IMPL"
                 ,4,"NVRM: veidCount %d is not aligned to veidSizePerSpan=%d\n",param_5,
                 (ulong)local_2c);
  }
  return 0x1f;
}


// ===== 0036ed40 kgrmgrGetVeidBaseForGrIdx_IMPL =====

undefined8 kgrmgrGetVeidBaseForGrIdx_IMPL(undefined8 param_1,long param_2,uint param_3,int *param_4)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  
  if (param_4 == (int *)0x0) {
    nvAssertFailedNoLog("pVeidStart != NULL","src/kernel/gpu/gr/kernel_graphics_manager.c",0x348);
  }
  else {
    if (param_3 != 8) {
      *param_4 = 0;
      iVar2 = 0;
      uVar1 = *(ulong *)(param_2 + 0x448 + (ulong)param_3 * 8);
      for (uVar3 = uVar1; (uVar3 & 1) == 0; uVar3 = uVar3 >> 1 | 0x8000000000000000) {
        iVar2 = iVar2 + 1;
      }
      iVar4 = 0;
      if (uVar1 != 0) {
        iVar4 = iVar2;
      }
      *param_4 = iVar4;
      return 0;
    }
    nvAssertFailedNoLog("grIdx != KGRMGR_MAX_GR","src/kernel/gpu/gr/kernel_graphics_manager.c",0x349
                       );
  }
  return 0x1f;
}


// ===== 0036edc0 kgrmgrGetGrIdxForVeid_IMPL =====

undefined8
kgrmgrGetGrIdxForVeid_IMPL(undefined8 param_1,long param_2,byte param_3,undefined4 *param_4)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_4 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pGrIdx != NULL","src/kernel/gpu/gr/kernel_graphics_manager.c",0x368);
    return 0x1f;
  }
  do {
    if ((*(ulong *)(param_2 + 0x448 + lVar1 * 8) & 1L << (param_3 & 0x3f)) != 0) {
      *param_4 = (int)lVar1;
      return 0;
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 8);
  nvAssertFailedNoLog("i != KGRMGR_MAX_GR","src/kernel/gpu/gr/kernel_graphics_manager.c",0x36e);
  return 0x57;
}


// ===== 0036ee40 kgrmgrDiscoverMaxLocalCtxBufInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kgrmgrDiscoverMaxLocalCtxBufInfo_IMPL
          (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  char cVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x490f) != '\0') {
    return 0;
  }
  cVar1 = (**(code **)(*(long *)(param_1 + 0x1bc0) + 0x228))
                    (param_1,*(long *)(param_1 + 0x1bc0),param_4);
  if (cVar1 != '\0') {
    uVar2 = kgraphicsDiscoverMaxLocalCtxBufferSize_IMPL(param_1,param_3);
    return uVar2;
  }
  return 0;
}


// ===== 0036eeb0 kgrmgrGetGlobalCtxBufInfo_IMPL =====

long kgrmgrGetGlobalCtxBufInfo_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  if (param_3 < 10) {
    return param_2 + 0x498 + (ulong)param_3 * 0x18;
  }
  nvAssertFailedNoLog("NV_ENUM_IS(GR_GLOBALCTX_BUFFER, buf)",
                      "src/kernel/gpu/gr/kernel_graphics_manager.c",0x39a);
  return 0;
}


// ===== 0036eef0 kgrmgrSetGlobalCtxBufInfo_IMPL =====

void kgrmgrSetGlobalCtxBufInfo_IMPL
               (undefined8 param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5,
               undefined4 param_6,undefined1 param_7)

{
  ulong uVar1;
  
  if (param_3 < 10) {
    uVar1 = (ulong)param_3;
    *(undefined8 *)(param_2 + 0x498 + uVar1 * 0x18) = param_4;
    *(undefined8 *)(param_2 + 0x4a0 + uVar1 * 0x18) = param_5;
    *(undefined4 *)(param_2 + 0x4a8 + uVar1 * 0x18) = param_6;
    *(undefined1 *)(param_2 + 0x4ac + uVar1 * 0x18) = param_7;
    return;
  }
  nvAssertFailedNoLog("NV_ENUM_IS(GR_GLOBALCTX_BUFFER, buf)",
                      "src/kernel/gpu/gr/kernel_graphics_manager.c",0x3ae);
  return;
}


// ===== 0036ef50 kgrmgrDiscoverMaxGlobalCtxBufSizes_IMPL =====

ulong kgrmgrDiscoverMaxGlobalCtxBufSizes_IMPL
                (long param_1,long param_2,undefined8 param_3,char param_4)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong *puVar6;
  int iVar7;
  uint local_2c;
  
  if (*(char *)(param_1 + 0x490f) != '\0') {
    return 0;
  }
  if ((*(long *)(param_1 + 0x1bc0) != 0) &&
     (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar2 != '\0')) {
    nvAssertFailedNoLog("!IS_MIG_IN_USE(pGpu)","src/kernel/gpu/gr/kernel_graphics_manager.c",0x3d0);
    return 0x40;
  }
  if (param_4 == '\0') {
    return 0;
  }
  uVar3 = kgraphicsInitializeDeferredStaticData_IMPL(param_1,param_3,0,0);
  if (uVar3 != 0) {
    nvAssertOkFailedNoLog
              (uVar3,
               "kgraphicsInitializeDeferredStaticData(pGpu, pKernelGraphics, NV01_NULL_OBJECT, NV01_NULL_OBJECT)"
               ,"src/kernel/gpu/gr/kernel_graphics_manager.c",0x3e0);
    return (ulong)uVar3;
  }
  lVar4 = kgraphicsGetStaticInfo_IMPL(param_1,param_3);
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x3e4);
  }
  else {
    iVar7 = 0;
    puVar6 = (ulong *)(param_2 + 0x498);
    if (*(long *)(lVar4 + 0x13d8) != 0) {
      do {
        uVar5 = kgrctxGlobalCtxBufferToFifoEngineId_IMPL(iVar7,&local_2c);
        if ((int)uVar5 != 0) {
          nvAssertOkFailedNoLog
                    (uVar5 & 0xffffffff,"kgrctxGlobalCtxBufferToFifoEngineId(bufId, &fifoEngineId)",
                     "src/kernel/gpu/gr/kernel_graphics_manager.c",0x3eb);
          return uVar5 & 0xffffffff;
        }
        iVar7 = iVar7 + 1;
        uVar3 = *(uint *)(*(long *)(lVar4 + 0x13d8) + 4 + (ulong)local_2c * 8);
        uVar1 = *(uint *)(*(long *)(lVar4 + 0x13d8) + (ulong)local_2c * 8);
        *(undefined4 *)(puVar6 + 2) = 1;
        *(undefined1 *)((long)puVar6 + 0x14) = 0;
        *puVar6 = (ulong)uVar1;
        puVar6[1] = (ulong)uVar3;
        puVar6 = puVar6 + 3;
      } while (iVar7 != 10);
      return uVar5;
    }
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo->pContextBuffersInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_manager.c",0x3e5);
  }
  return 0x40;
}


// ===== 0036f120 kgrmgrCheckVeidsRequest_IMPL =====

ulong kgrmgrCheckVeidsRequest_IMPL
                (undefined8 param_1,undefined8 param_2,ulong *param_3,uint param_4,int *param_5,
                long param_6)

{
  ulong uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  uint local_3c [3];
  
  uVar3 = kgrmgrGetVeidSizePerSpan_IMPL(param_1,param_2,local_3c);
  if (uVar3 != 0) {
    nvAssertOkFailedNoLog
              (uVar3,"kgrmgrGetVeidSizePerSpan(pGpu, pKernelGraphicsManager, &veidSizePerSpan)",
               "src/kernel/gpu/gr/kernel_graphics_manager.c",0x434);
    return (ulong)uVar3;
  }
  if (param_5 == (int *)0x0) {
    nvAssertFailedNoLog("pSpanStart != NULL","src/kernel/gpu/gr/kernel_graphics_manager.c",0x437);
  }
  else if (param_3 == (ulong *)0x0) {
    nvAssertFailedNoLog("pInUseMask != NULL","src/kernel/gpu/gr/kernel_graphics_manager.c",0x438);
  }
  else {
    uVar8 = (ulong)local_3c[0];
    uVar1 = (ulong)param_4 % uVar8;
    if ((int)uVar1 == 0) {
      uVar3 = *(uint *)(param_6 + 0x90);
      iVar5 = *(int *)(param_6 + 0x94) + uVar3;
      bVar2 = (byte)uVar3 & 0x3f;
      uVar9 = (0xffffffffffffffffU >> ((-(char)iVar5 & 0x3fU) + bVar2 & 0x3f)) << bVar2;
      if (uVar9 == 0) {
        nvAssertFailedNoLog("GPUInstanceVeidMask != 0x0",
                            "src/kernel/gpu/gr/kernel_graphics_manager.c",0x445);
      }
      else {
        if (*param_5 == -1) {
          uVar6 = iVar5 - 1;
          if (uVar3 <= uVar6) {
            uVar4 = uVar3;
            do {
              if ((~((~*param_3 & uVar9) >> ((byte)uVar4 & 0x3f)) &
                  0xffffffffffffffffU >> (-(char)param_4 & 0x3fU)) == 0) {
                param_4 = (uVar4 - 1) + param_4;
                if (uVar6 < uVar4) {
                  return 0x1a;
                }
                goto LAB_0036f1ef;
              }
              uVar4 = uVar4 + local_3c[0];
            } while (uVar4 <= uVar6);
          }
          return 0x1a;
        }
        uVar4 = *param_5 * local_3c[0] + uVar3;
        param_4 = (uVar4 - 1) + param_4;
        if (uVar4 < param_4) {
          if (0x3f < uVar4) {
            nvAssertFailedNoLog("veidStart < 64","src/kernel/gpu/gr/kernel_graphics_manager.c",0x44f
                               );
            return 0x1f;
          }
          if (0x3f < param_4) {
            nvAssertFailedNoLog("veidEnd < 64","src/kernel/gpu/gr/kernel_graphics_manager.c",0x450);
            return 0x1f;
          }
LAB_0036f1ef:
          bVar2 = (byte)uVar4 & 0x3f;
          uVar7 = (0xffffffffffffffffU >> ((~(byte)param_4 & 0x3f) + bVar2 & 0x3f)) << bVar2;
          if (uVar7 == 0) {
            nvAssertFailedNoLog("veidMask != 0x0","src/kernel/gpu/gr/kernel_graphics_manager.c",
                                0x467);
            return 0x40;
          }
          if ((*(int *)(param_6 + 0x968) != 0) && ((~uVar9 & uVar7) != 0)) {
            nvCheckFailedNoLog(4,
                               "((pKernelMIGGPUInstance->swizzId == 0) || (GPUInstanceVeidMask & veidMask) == veidMask)"
                               ,"src/kernel/gpu/gr/kernel_graphics_manager.c",0x46d);
            return 0x1a;
          }
          if ((*param_3 & uVar7) != 0) {
            nvAssertFailedNoLog("(*pInUseMask & veidMask) == 0",
                                "src/kernel/gpu/gr/kernel_graphics_manager.c",0x473);
            return 99;
          }
          if (uVar4 < uVar3) {
            nvAssertFailedNoLog("veidStart >= pKernelMIGGPUInstance->resourceAllocation.veidOffset",
                                "src/kernel/gpu/gr/kernel_graphics_manager.c",0x475);
            uVar3 = *(uint *)(param_6 + 0x90);
            uVar8 = (ulong)local_3c[0];
          }
          *param_5 = (int)((uVar4 - uVar3) / uVar8);
          *param_3 = *param_3 | uVar7;
          return uVar1;
        }
        nvAssertFailedNoLog("veidStart < veidEnd","src/kernel/gpu/gr/kernel_graphics_manager.c",
                            0x44e);
      }
      return 0x40;
    }
    nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_manager.c",0x43d,"kgrmgrCheckVeidsRequest_IMPL",
                 4,"NVRM: veidCount %d is not aligned to veidSizePerSpan=%d\n",param_4,uVar8);
  }
  return 0x1f;
}


// ===== 0036f4c0 _kgrobjDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kgrobjDestruct(long param_1,char param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_40 = 0;
  local_48 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x1c0) + 0xe0);
  lVar3 = *(long *)(param_1 + 0x1d8);
  uVar1 = *(undefined4 *)(lVar3 + 0x180);
  uVar4 = *(undefined8 *)(lVar2 + 0x1bc8);
  uVar5 = *(undefined8 *)(*(long *)(lVar3 + 0x158) + 0xe8);
  kgrmgrCtrlSetChannelHandle_IMPL
            (*(undefined4 *)(*(long *)(*(long *)(*(long *)(lVar3 + 0x140) + 0x48) + 0x18) + 0x10),
             &local_48);
  iVar6 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar2,uVar4,uVar5,&local_48,&local_50);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics_object.c",0x102);
    return;
  }
  (**(code **)(param_1 + 0x1f8))(lVar2,param_1);
  if (param_2 != '\0') {
    kgrctxDecObjectCount_IMPL(lVar2,*(undefined8 *)(param_1 + 0x208),uVar1);
  }
  iVar6 = kchannelGetGfid_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x1d8) + 0x178));
  if ((*(char *)(lVar2 + 0x4a23) != '\0') && (iVar6 == 0)) {
    kgrctxUnmapCtxBuffers_IMPL(lVar2,*(undefined8 *)(param_1 + 0x208),param_1,local_50,param_2);
    return;
  }
  return;
}


// ===== 0036f611 kgrobjPromoteContext_IMPL.cold =====

void kgrobjPromoteContext_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0036f620 kgrobjPromoteContext_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong kgrobjPromoteContext_IMPL(long param_1,long param_2,long param_3)

{
  undefined2 *puVar1;
  long *plVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  char *pcVar9;
  long lVar10;
  undefined2 *puVar11;
  long lVar12;
  long lVar13;
  char local_2b7;
  char local_2b6;
  char local_2b5;
  uint local_2b4;
  long local_2b0;
  undefined4 local_2a8 [16];
  int local_268 [3];
  undefined4 local_25c;
  undefined4 local_258;
  uint local_240;
  undefined1 auStack_238 [28];
  undefined2 local_21c;
  char local_21a [490];
  
  lVar5 = rmapiGetInterface(4);
  uVar6 = 0;
  if (*(char *)(param_1 + 0x490f) == '\0') {
    lVar12 = *(long *)(param_2 + 0x1d8);
    uVar4 = subdeviceGetByDeviceAndGpu_IMPL
                      (**(undefined8 **)(*(long *)(param_2 + 0x1a8) + 0x48),
                       *(undefined8 *)(*(long *)(param_2 + 0x1c0) + 0xe8),param_1,&local_2b0);
    uVar6 = (ulong)uVar4;
    if (uVar4 == 0) {
      (**(code **)(param_2 + 0x1e8))(param_1,param_2,0x10,local_2a8,&local_2b4,&local_2b7);
      if ((local_2b4 == 0) || (portMemSet(local_268,0,0x230), local_2b4 == 0)) {
        return 0;
      }
      lVar10 = 0;
      uVar8 = 0;
      lVar13 = lVar12;
      do {
        local_2b5 = '\0';
        uVar4 = kgrctxPrepareInitializeCtxBuffer_IMPL
                          (param_1,*(undefined8 *)(param_2 + 0x208),param_3,
                           *(undefined8 *)(lVar12 + 0x178),local_2a8[lVar10],
                           auStack_238 + uVar8 * 0x20,&local_2b6);
        if (uVar4 != 0) {
          uVar7 = 100;
          pcVar9 = 
          "kgrctxPrepareInitializeCtxBuffer(pGpu, pKernelGraphicsObject->pKernelGraphicsContext, pKernelGraphics, pChannelDescendant->pKernelChannel, promoteIds[i], &params.promoteEntry[entryCount], &bInitialize)"
          ;
LAB_0036f83b:
          nvAssertOkFailedNoLog(uVar4,pcVar9,"src/kernel/gpu/gr/kernel_graphics_object.c",uVar7);
          return (ulong)uVar4;
        }
        if ((local_2b7 != '\0') &&
           (uVar4 = kgrctxPreparePromoteCtxBuffer_IMPL
                              (param_1,*(undefined8 *)(param_2 + 0x208),
                               *(undefined8 *)(lVar12 + 0x178),local_2a8[lVar10],
                               auStack_238 + uVar8 * 0x20,&local_2b5), uVar4 != 0)) {
          uVar7 = 0x70;
          pcVar9 = 
          "kgrctxPreparePromoteCtxBuffer(pGpu, pKernelGraphicsObject->pKernelGraphicsContext, pChannelDescendant->pKernelChannel, promoteIds[i], &params.promoteEntry[entryCount], &bPromote)"
          ;
          goto LAB_0036f83b;
        }
        local_240 = ((int)uVar8 + 1) - (uint)(local_2b6 == '\0' && local_2b5 == '\0');
        uVar8 = (ulong)local_240;
        lVar10 = lVar10 + 1;
      } while ((uint)lVar10 < local_2b4);
      if (local_240 == 0) {
        uVar6 = 0;
      }
      else {
        local_268[0] = *(int *)(param_3 + 0x20c) + 1;
        plVar2 = *(long **)(*(long *)(lVar13 + 0x140) + 0x48);
        local_258 = *(undefined4 *)(plVar2[3] + 0x10);
        local_25c = *(undefined4 *)(*plVar2 + 0x48);
        if (local_2b0 == 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)invalidInstructionException();
          (*pcVar3)();
        }
        plVar2 = *(long **)(*(long *)(local_2b0 + 0x140) + 0x48);
        uVar6 = (**(code **)(lVar5 + 0x38))
                          (lVar5,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x2080012b,local_268
                           ,0x230,lVar5,lVar13,*(int *)(param_3 + 0x20c));
        if ((int)uVar6 == 0) {
          uVar6 = 0;
          puVar11 = &local_21c;
          puVar1 = puVar11 + uVar8 * 0x10;
          do {
            if (*(char *)(puVar11 + 1) != '\0') {
              kgrctxMarkCtxBufferInitialized_IMPL
                        (param_1,*(undefined8 *)(param_2 + 0x208),param_3,
                         *(undefined8 *)(lVar13 + 0x178),*puVar11);
            }
            puVar11 = puVar11 + 0x10;
          } while (puVar11 != puVar1);
          uVar6 = uVar6 & 0xffffffff;
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar4,
                 "subdeviceGetByDeviceAndGpu( RES_GET_CLIENT(pKernelGraphicsObject), pDevice, pGpu, &pSubdevice)"
                 ,"src/kernel/gpu/gr/kernel_graphics_object.c",0x49);
    }
  }
  return uVar6;
}


// ===== 0036f9c0 kgrobjConstruct_IMPL.cold =====

void kgrobjConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0036f9e0 kgrobjConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgrobjConstruct_IMPL(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  long lVar10;
  ulong uVar11;
  char *pcVar12;
  undefined8 uVar13;
  undefined8 uStack_70;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  lVar2 = *(long *)(param_1 + 0x1d8);
  lVar10 = *(long *)(lVar2 + 0x178);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/gr/kernel_graphics_object.c",299);
    return 0x40;
  }
  lVar3 = *(long *)(*(long *)(lVar2 + 0x158) + 0xe0);
  uVar13 = *(undefined8 *)(*(long *)(param_1 + 0x1c0) + 0xe8);
  nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_object.c",0x12d,"kgrobjConstruct_IMPL",1,
               "NVRM: class: 0x%x on channel 0x%08x\n",*(undefined4 *)(lVar2 + 0x180),
               *(int *)(lVar10 + 0x2b0) << 0x18 | *(uint *)(lVar10 + 0x2b4));
  if (*(int *)(param_3 + 8) == 0) {
    nvAssertFailedNoLog("pParams->hResource != NV01_NULL_OBJECT",
                        "src/kernel/gpu/gr/kernel_graphics_object.c",0x136);
    return 0x40;
  }
  if (*(long *)(lVar2 + 0x178) == 0) {
    nvAssertFailedNoLog("pkChannel != NULL","src/kernel/gpu/gr/kernel_graphics_object.c",0x13c);
    return 0x40;
  }
  iVar7 = kgrctxFromKernelChannel_IMPL(*(long *)(lVar2 + 0x178),param_1 + 0x208,uStack_70);
  if (iVar7 == 0) {
    if (*(long *)(param_1 + 0x208) == 0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)invalidInstructionException();
      (*pcVar5)();
    }
    refAddDependant(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x208) + 0x110) + 0x48),
                    *(undefined8 *)(*(long *)(param_1 + 0x1a8) + 0x48));
  }
  uVar4 = *(undefined8 *)(lVar3 + 0x1bc8);
  local_48 = 0;
  local_40 = 0;
  kgrmgrCtrlSetChannelHandle_IMPL(*(undefined4 *)(param_3 + 4),&local_48);
  uVar8 = kgrmgrCtrlRouteKGRWithDevice_IMPL(lVar3,uVar4,uVar13,&local_48,&local_50);
  if (uVar8 != 0) {
    nvAssertOkFailedNoLog
              (uVar8,
               "kgrmgrCtrlRouteKGRWithDevice(pGpu, pKernelGraphicsManager, pDevice, &grRouteInfo, &pKernelGraphics)"
               ,"src/kernel/gpu/gr/kernel_graphics_object.c",0x154);
    goto LAB_0036fd82;
  }
  lVar2 = *(long *)(param_1 + 0x1d8);
  uVar1 = *(undefined4 *)(lVar2 + 0x180);
  lVar10 = kgraphicsGetStaticInfo_IMPL(lVar3,local_50);
  uVar9 = kchannelGetGfid_IMPL(*(undefined8 *)(lVar2 + 0x178));
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                        "src/kernel/gpu/gr/kernel_graphics_object.c",0xba);
    uVar8 = 0x40;
    goto LAB_0036fd82;
  }
  if ((*(char *)(lVar3 + 0x490f) == '\0') &&
     (uVar8 = *(uint *)(lVar10 + 0x1104) - (*(uint *)(lVar10 + 0x1104) >> 1 & 0x55555555),
     uVar8 = (uVar8 & 0x33333333) + (uVar8 >> 2 & 0x33333333),
     ((uVar8 >> 4) + uVar8 & 0xf0f0f0f) * 0x1010101 >> 0x18 == 0)) {
    nvCheckFailedNoLog(4,"numGpcs > 0","src/kernel/gpu/gr/kernel_graphics_object.c",0xc0);
    uVar8 = 0x1a;
    goto LAB_0036fd82;
  }
  uVar11 = (**(code **)(param_1 + 0x1f0))(lVar3,param_1);
  uVar13 = 0xc4;
  pcVar12 = "kgrobjSetComputeMmio_HAL(pGpu, pKernelGraphicsObject)";
  if ((int)uVar11 != 0) goto LAB_0036fd70;
  if ((*(char *)(lVar3 + 0x490f) == '\0') &&
     (uVar8 = kgraphicsInitializeDeferredStaticData_IMPL(lVar3,local_50,0,0,0xc4), uVar8 != 0)) {
    nvAssertOkFailedNoLog
              (uVar8,
               "kgraphicsInitializeDeferredStaticData(pGpu, pKernelGraphics, NV01_NULL_OBJECT, NV01_NULL_OBJECT)"
               ,"src/kernel/gpu/gr/kernel_graphics_object.c",0xca);
    goto LAB_0036fd82;
  }
  cVar6 = kgrctxShouldManageCtxBuffers_KERNEL(lVar3,*(undefined8 *)(param_1 + 0x208),uVar9);
  if ((cVar6 != '\0') || (*(char *)(lVar3 + 0x4913) != '\0')) {
    uVar11 = kgraphicsAllocKgraphicsBuffers_KERNEL
                       (lVar3,local_50,*(undefined8 *)(param_1 + 0x208),
                        *(undefined8 *)(lVar2 + 0x178));
    uVar13 = 0xd1;
    pcVar12 = 
    "kgraphicsAllocKgraphicsBuffers_HAL(pGpu, pKernelGraphics, pKernelGraphicsObject->pKernelGraphicsContext, pChannelDescendant->pKernelChannel)"
    ;
    if ((int)uVar11 != 0) goto LAB_0036fd70;
  }
  cVar6 = kgrctxShouldManageCtxBuffers_KERNEL(lVar3,*(undefined8 *)(param_1 + 0x208),uVar9);
  if (cVar6 == '\0') {
LAB_0036fc15:
    kgrctxIncObjectCount_IMPL(lVar3,*(undefined8 *)(param_1 + 0x208),uVar1);
    uVar11 = kgrobjPromoteContext_IMPL(lVar3,param_1,local_50);
    if ((int)uVar11 == 0) {
      return uVar11;
    }
    uVar13 = 0xe0;
    pcVar12 = "kgrobjPromoteContext(pGpu, pKernelGraphicsObject, pKernelGraphics)";
  }
  else {
    uVar11 = kgrctxAllocCtxBuffers_IMPL(lVar3,*(undefined8 *)(param_1 + 0x208),local_50,param_1);
    uVar13 = 0xd7;
    pcVar12 = 
    "kgrctxAllocCtxBuffers(pGpu, pKernelGraphicsObject->pKernelGraphicsContext, pKernelGraphics, pKernelGraphicsObject)"
    ;
    if ((int)uVar11 == 0) {
      uVar11 = kgrctxMapCtxBuffers_IMPL
                         (lVar3,*(undefined8 *)(param_1 + 0x208),local_50,param_1,0xd7);
      uVar13 = 0xda;
      pcVar12 = 
      "kgrctxMapCtxBuffers(pGpu, pKernelGraphicsObject->pKernelGraphicsContext, pKernelGraphics, pKernelGraphicsObject)"
      ;
      if ((int)uVar11 == 0) goto LAB_0036fc15;
    }
  }
LAB_0036fd70:
  uVar8 = (uint)uVar11;
  nvCheckOkFailedNoLog
            (4,uVar11 & 0xffffffff,pcVar12,"src/kernel/gpu/gr/kernel_graphics_object.c",uVar13);
LAB_0036fd82:
  _kgrobjDestruct(param_1,0);
  return (ulong)uVar8;
}


// ===== 0036fe90 kgrobjDestruct_IMPL =====

void kgrobjDestruct_IMPL(undefined8 param_1)

{
  _kgrobjDestruct(param_1,1);
  return;
}


// ===== 0036fea0 kgrobjGetMemInterMapParams_IMPL =====

undefined8 kgrobjGetMemInterMapParams_IMPL(long param_1,long param_2)

{
  undefined8 *puVar1;
  
  if (*(char *)(param_2 + 0x10) != '\0') {
    nvDbg_Printf("src/kernel/gpu/gr/kernel_graphics_object.c",0x185,
                 "kgrobjGetMemInterMapParams_IMPL",4,
                 "NVRM: Unicast DMA mappings of non-memory objects not supported.\n");
    return 0x56;
  }
  puVar1 = *(undefined8 **)(param_1 + 0x200);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined8 **)(param_2 + 0x20) = puVar1;
    *(undefined8 *)(param_2 + 0x18) = *puVar1;
    return 0;
  }
  return 0x33;
}


// ===== 0036ff01 kgrobjSetComputeMmio_IMPL.cold =====

void kgrobjSetComputeMmio_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0036ff10 kgrobjSetComputeMmio_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgrobjSetComputeMmio_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined8 uVar7;
  char cVar8;
  int local_2c;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_2 + 0x1d8);
  lVar2 = *(long *)(param_1 + 0x1b78);
  kgrmgrGetGrObjectType_IMPL(*(undefined4 *)(lVar1 + 0x180),&local_2c);
  if ((local_2c != 3) || (*(long *)(param_2 + 0x200) != 0)) {
    return 0;
  }
  cVar8 = (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') + '\x01';
  iVar4 = memdescCreate(param_2 + 0x200,param_1,0x1000,0,1,cVar8,1,0);
  uVar7 = 0x1b6;
  pcVar6 = 
  "memdescCreate(&pKernelGraphicsObject->pMmioMemDesc, pGpu, RM_PAGE_SIZE, 0, NV_TRUE, addrSpace, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
  ;
  if (iVar4 == 0) {
    memdescDescribe(*(undefined8 *)(param_2 + 0x200),cVar8,
                    *(int *)(*(long *)(lVar1 + 0x178) + 0x2b4) << 0xc,0x1000,0x1b6);
    uVar5 = (**(code **)(lVar2 + 0x2b0))(param_1,lVar2);
    memdescSetPteKindForGpu
              (*(undefined8 **)(param_2 + 0x200),**(undefined8 **)(param_2 + 0x200),uVar5);
    (**(code **)(lVar2 + 0x388))(param_1,lVar2,*(undefined8 *)(param_2 + 0x200),1,1);
    if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') {
      return 0;
    }
    iVar4 = memdescAlloc(*(undefined8 *)(param_2 + 0x200));
    if (iVar4 == 0) {
      memdescSetFlag(*(undefined8 *)(param_2 + 0x200),0x800000000,1);
      return 0;
    }
    uVar7 = 0x1cf;
    pcVar6 = "memdescAlloc(pKernelGraphicsObject->pMmioMemDesc)";
  }
  nvCheckOkFailedNoLog(4,iVar4,pcVar6,"src/kernel/gpu/gr/kernel_graphics_object.c",uVar7);
  return iVar4;
}


// ===== 003700c0 kgrobjFreeComputeMmio_IMPL =====

void kgrobjFreeComputeMmio_IMPL(long param_1,long param_2)

{
  if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0') {
    memdescFree(*(undefined8 *)(param_2 + 0x200));
  }
  memdescDestroy(*(undefined8 *)(param_2 + 0x200));
  *(undefined8 *)(param_2 + 0x200) = 0;
  return;
}


// ===== 00370110 kgrobjGetPromoteIds_FWCLIENT =====

void kgrobjGetPromoteIds_FWCLIENT
               (long param_1,long param_2,uint param_3,undefined8 param_4,undefined4 *param_5,
               undefined1 *param_6)

{
  long lVar1;
  uint local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  lVar1 = 0;
  if (param_2 != 0) {
    lVar1 = *(long *)(param_2 + 0x1d8);
  }
  *param_5 = 0;
  local_50 = 0x100000000;
  local_38 = 0x100000000;
  local_30 = 0x300000002;
  local_28 = 0x500000004;
  local_20 = 0x700000006;
  local_48 = 0x900000002;
  local_40 = 0xb0000000a;
  local_18 = 0x900000008;
  local_10 = 0xb0000000a;
  *param_6 = 1;
  if (*(char *)(param_1 + 0x4a23) != '\0') {
    if (*(char *)(*(long *)(*(long *)(*(long *)(lVar1 + 0x178) + 0x2b8) + 0x138) + 0x159) == '\0') {
      kgrmgrGetGrObjectType_IMPL(*(undefined4 *)(lVar1 + 0x180),&local_54);
      if (1 < local_54) {
        if (5 < param_3) {
          *param_5 = 6;
          portMemCopy(param_4,0x18,&local_50,0x18);
          return;
        }
        nvAssertFailedNoLog("NV_ARRAY_ELEMENTS(promoteNon3d) <= maxPromoteIds",
                            "src/kernel/gpu/gr/kernel_graphics_object.c",0x288);
        return;
      }
    }
    if (param_3 < 0xc) {
      nvAssertFailedNoLog("NV_ARRAY_ELEMENTS(promote3d) <= maxPromoteIds",
                          "src/kernel/gpu/gr/kernel_graphics_object.c",0x282);
      return;
    }
    *param_5 = 0xc;
    portMemCopy(param_4,0x30,&local_38,0x30);
  }
  return;
}


// ===== 00370280 kgrobjGetPromoteIds_VF =====

void kgrobjGetPromoteIds_VF
               (long param_1,undefined8 param_2,int param_3,undefined8 param_4,undefined4 *param_5,
               undefined1 *param_6)

{
  undefined4 local_c;
  
  local_c = 9;
  if (*(char *)(param_1 + 0x491e) == '\0') {
    kgrobjGetPromoteIds_FWCLIENT();
    return;
  }
  *param_5 = 0;
  *param_6 = 0;
  if (param_3 != 0) {
    *param_5 = 1;
    portMemCopy(param_4,4,&local_c,4);
    return;
  }
  nvAssertFailedNoLog("NV_ARRAY_ELEMENTS(promoteSriovHeavy) <= maxPromoteIds",
                      "src/kernel/gpu/gr/kernel_graphics_object.c",0x239);
  return;
}


// ===== 003702fa ksmdbgssnConstruct_IMPL.cold =====

void ksmdbgssnConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00370310 ksmdbgssnConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksmdbgssnConstruct_IMPL(long param_1,long param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  long lVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  long lVar12;
  char *pcVar13;
  undefined8 extraout_RDX;
  undefined8 uVar14;
  undefined8 uVar15;
  bool bVar16;
  undefined4 local_ac;
  long local_a8;
  long local_a0;
  long local_98;
  undefined1 local_90 [8];
  undefined4 local_88;
  long local_80 [2];
  ulong local_70 [8];
  
  piVar4 = *(int **)(param_3 + 0x10);
  if (*piVar4 != 0) {
    nvAssertFailedNoLog("Old Nv83deAllocParams interface not supported",
                        "src/kernel/gpu/gr/kernel_sm_debugger_session.c",0xed);
    return 0x1f;
  }
  iVar11 = piVar4[1];
  iVar9 = piVar4[2];
  iVar1 = param_3[2];
  if (iVar11 == 0) {
    iVar11 = *param_3;
  }
  iVar8 = serverGetClientUnderLock(g_resServ,iVar11,&local_a8);
  uVar14 = 0xfc;
  pcVar13 = "serverGetClientUnderLock(&g_resServ, hAppClient, &pAppClient)";
  if (iVar8 != 0) {
LAB_00370844:
    nvCheckOkFailedNoLog(4,iVar8,pcVar13,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",uVar14);
    return iVar8;
  }
  iVar9 = clientGetResourceRef_IMPL
                    (local_a8,iVar9,&local_98,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0xfc)
  ;
  if (iVar9 != 0) {
    nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x103,"ksmdbgssnConstruct_IMPL",4,
                 "NVRM: hObject 0x%x not found for client 0x%x\n",param_3[1],*param_3);
    return 0x36;
  }
  cVar7 = hypervisorIsVgxHyper_IMPL();
  if (cVar7 == '\0') {
    portMemSet(local_70,0,4);
    local_70[0] = local_70[0] | 4;
    iVar11 = rsAccessCheckRights(local_98,*(undefined8 *)(param_2 + 8),local_70);
    if (iVar11 != 0) {
      nvCheckFailedNoLog(4,"status == NV_OK","src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x12a)
      ;
      nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session.c",300,"ksmdbgssnConstruct_IMPL",4,
                   "NVRM: Current user does not have debugging rights on the compute object. Status = 0x%x\n"
                   ,iVar11);
      return 0x1b;
    }
  }
  else if ((*(char *)(g_pSys + 0x6f) != '\0') && (**(int **)(param_3 + 0xe) == 0)) {
    uVar14 = rmclientGetSecurityTokenByHandle(iVar11);
    uVar15 = rmclientGetSecurityTokenByHandle(*(undefined4 *)(*(long *)(param_2 + 8) + 0x48));
    iVar11 = osValidateClientTokens(uVar15,uVar14);
    if (iVar11 != 0) {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x116);
      return iVar11;
    }
  }
  lVar12 = __nvoc_dynamicCast(*(undefined8 *)(local_98 + 8),__nvoc_class_def_KernelGraphicsObject);
  *(long *)(param_1 + 0x188) = lVar12;
  if (lVar12 == 0) {
    return 0x31;
  }
  lVar5 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(*(long *)(lVar12 + 0x1c0) + 0xe0) != lVar5) {
    nvCheckFailedNoLog(4,"pGpu == GPU_RES_GET_GPU(pKernelSMDebuggerSession->pObject)",
                       "src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x13b);
    return 0x1f;
  }
  lVar12 = *(long *)(*(long *)(lVar12 + 0x1c0) + 0xe8);
  uVar2 = *(undefined4 *)(*(long *)(local_98 + 0x18) + 0x10);
  uVar10 = gpumgrGetSubDeviceInstanceFromGpu(lVar5);
  if (lVar12 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  iVar8 = subdeviceGetByInstance_IMPL
                    (local_a8,*(undefined4 *)(*(long *)(*(long *)(lVar12 + 0x110) + 0x48) + 0x10),
                     uVar10,&local_a0);
  if (iVar8 != 0) {
    uVar14 = 0x140;
    pcVar13 = 
    "subdeviceGetByInstance(pAppClient, RES_GET_HANDLE(pAppDevice), gpumgrGetSubDeviceInstanceFromGpu(pGpu), &pSubdevice)"
    ;
    goto LAB_00370844;
  }
  if (local_a0 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  uVar10 = *(undefined4 *)(*(long *)(*(long *)(local_a0 + 0x140) + 0x48) + 0x10);
  *(undefined4 *)(param_1 + 0x19c) = *(undefined4 *)(local_a8 + 0x48);
  *(int *)(param_1 + 400) = iVar1;
  uVar3 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  *(undefined4 *)(param_1 + 0x1a0) = uVar10;
  *(undefined4 *)(param_1 + 0x198) = uVar2;
  *(undefined4 *)(param_1 + 0x194) = uVar3;
  cVar7 = kgrctxRegisterKernelSMDebuggerSession_IMPL
                    (lVar5,*(undefined8 *)(*(long *)(param_1 + 0x188) + 0x208),param_1);
  if (cVar7 == '\0') {
    nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x154,"ksmdbgssnConstruct_IMPL",4,
                 "NVRM: Failed to insert Debugger into channel list, handle = 0x%x\n",
                 *(undefined4 *)(param_1 + 400));
    return 0x1a;
  }
  uVar14 = *(undefined8 *)(lVar5 + 0x1bc0);
  bVar16 = false;
  lVar12 = rmapiGetInterface(4);
  if (*(long *)(lVar5 + 0x1bc0) != 0) {
    cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar5);
    bVar16 = cVar7 != '\0';
  }
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  iVar11 = (**(code **)(lVar12 + 8))(lVar12,0,0,0,0,param_1 + 0x1a4,4);
  uVar15 = 0x7d;
  pcVar13 = 
  "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &pKernelSMDebuggerSession->hInternalClient, sizeof(pKernelSMDebuggerSession->hInternalClient))"
  ;
  if (iVar11 == 0) {
    iVar11 = serverutilGenResourceHandle
                       (*(undefined4 *)(param_1 + 0x1a4),param_1 + 0x1a8,
                        "pRmApi->AllocWithHandle(pRmApi, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_NULL_OBJECT, NV01_ROOT, &pKernelSMDebuggerSession->hInternalClient, sizeof(pKernelSMDebuggerSession->hInternalClient))"
                        ,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x7d);
    if (iVar11 == 0) {
      portMemSet(local_70,0,0x38);
      uVar2 = *(undefined4 *)(param_1 + 0x1a4);
      local_70[0] = CONCAT44(uVar2,*(undefined4 *)(lVar5 + 0x7b4));
      iVar11 = (**(code **)(lVar12 + 8))
                         (lVar12,uVar2,uVar2,*(undefined4 *)(param_1 + 0x1a8),0x80,local_70,0x38);
      uVar15 = 0x8f;
      pcVar13 = 
      "pRmApi->AllocWithHandle(pRmApi, pKernelSMDebuggerSession->hInternalClient, pKernelSMDebuggerSession->hInternalClient, pKernelSMDebuggerSession->hInternalDevice, NV01_DEVICE_0, &nv0080AllocParams, sizeof(nv0080AllocParams))"
      ;
      if (iVar11 != 0) goto LAB_00370a70;
      iVar11 = serverutilGenResourceHandle
                         (*(undefined4 *)(param_1 + 0x1a4),param_1 + 0x1ac,
                          "pRmApi->AllocWithHandle(pRmApi, pKernelSMDebuggerSession->hInternalClient, pKernelSMDebuggerSession->hInternalClient, pKernelSMDebuggerSession->hInternalDevice, NV01_DEVICE_0, &nv0080AllocParams, sizeof(nv0080AllocParams))"
                          ,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x8f,0x3705a2);
      if (iVar11 == 0) {
        portMemSet(&local_ac,0,4);
        local_ac = gpumgrGetSubDeviceInstanceFromGpu(lVar5);
        iVar11 = (**(code **)(lVar12 + 8))
                           (lVar12,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1a8)
                            ,*(undefined4 *)(param_1 + 0x1ac),0x2080,&local_ac,4);
        if (iVar11 == 0) {
          uVar15 = extraout_RDX;
          if (!bVar16) {
LAB_00370684:
            uVar14 = *(undefined8 *)(param_2 + 0x10);
            if (*(long *)(local_98 + 0x1c0) == 0) {
              local_70[0] = 0;
              iVar11 = serverAllocShare(g_resServ,__nvoc_class_def_RmDebuggerSession,local_70);
              if (iVar11 == 0) {
                lVar12 = __nvoc_dynamicCast(local_70[0],__nvoc_class_def_RmDebuggerSession);
                *(long *)(param_1 + 0x180) = lVar12;
                uVar15 = 0;
                if (lVar12 != 0) {
                  uVar15 = *(undefined8 *)(lVar12 + 0x110);
                }
                sessionAddDependency_IMPL(uVar15,local_98);
                sessionAddDependant_IMPL(uVar15,uVar14);
                serverFreeShare(g_resServ,local_70[0]);
                return 0;
              }
            }
            else {
              lVar12 = __nvoc_dynamicCast(*(long *)(local_98 + 0x1c0),
                                          __nvoc_class_def_RmDebuggerSession,uVar15);
              *(long *)(param_1 + 0x180) = lVar12;
              if (lVar12 != 0) {
                sessionAddDependant_IMPL(*(undefined8 *)(lVar12 + 0x110),uVar14);
                return 0;
              }
              nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x19b,"_ShareDebugger",4
                           ,
                           "NVRM: KernelGraphicsObject already a dependent of a non-debugger session\n"
                          );
              iVar11 = 0x40;
            }
            uVar14 = 0x15d;
            pcVar13 = 
            "_ShareDebugger(pKernelSMDebuggerSession, pCallContext->pResourceRef, pGrResourceRef)";
            goto LAB_00370ae3;
          }
          uVar15 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
          portMemSet(local_90,0,0x10);
          iVar11 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar5,uVar14,uVar15,local_80);
          uVar15 = 0xb1;
          pcVar13 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
          if (iVar11 == 0) {
            iVar11 = serverutilGenResourceHandle
                               (*(undefined4 *)(param_1 + 0x1a4),param_1 + 0x1b0,
                                "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)"
                                ,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0xb1);
            if (iVar11 != 0) {
              nvAssertOkFailedNoLog
                        (iVar11,
                         "serverutilGenResourceHandle(pKernelSMDebuggerSession->hInternalClient, &pKernelSMDebuggerSession->hInternalSubscription)"
                         ,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0xb5);
              goto LAB_00370a89;
            }
            local_88 = *(undefined4 *)(local_80[0] + 0x968);
            uVar15 = 0x10;
            iVar11 = (**(code **)(lVar12 + 8))
                               (lVar12,*(undefined4 *)(param_1 + 0x1a4),
                                *(undefined4 *)(param_1 + 0x1ac),*(undefined4 *)(param_1 + 0x1b0),
                                0xc637,local_90);
            if (iVar11 == 0) goto LAB_00370684;
            uVar15 = 0xba;
            pcVar13 = 
            "pRmApi->AllocWithHandle(pRmApi, pKernelSMDebuggerSession->hInternalClient, pKernelSMDebuggerSession->hInternalSubdevice, pKernelSMDebuggerSession->hInternalSubscription, AMPERE_SMC_PARTITION_REF, &nvC637AllocParams, sizeof(nvC637AllocParams))"
            ;
          }
          goto LAB_00370a70;
        }
        nvCheckOkFailedNoLog
                  (4,iVar11,
                   "pRmApi->AllocWithHandle(pRmApi, pKernelSMDebuggerSession->hInternalClient, pKernelSMDebuggerSession->hInternalDevice, pKernelSMDebuggerSession->hInternalSubdevice, NV20_SUBDEVICE_0, &nv2080AllocParams, sizeof(nv2080AllocParams))"
                   ,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0xa0);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar11,
                   "serverutilGenResourceHandle(pKernelSMDebuggerSession->hInternalClient, &pKernelSMDebuggerSession->hInternalSubdevice)"
                   ,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x9a);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar11,
                 "serverutilGenResourceHandle(pKernelSMDebuggerSession->hInternalClient, &pKernelSMDebuggerSession->hInternalDevice)"
                 ,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",0x88);
    }
  }
  else {
LAB_00370a70:
    nvCheckOkFailedNoLog(4,iVar11,pcVar13,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",uVar15);
  }
LAB_00370a89:
  iVar9 = *(int *)(param_1 + 0x1a4);
  if (iVar9 != 0) {
    (**(code **)(lVar12 + 0x18))(lVar12,iVar9,iVar9);
    *(undefined4 *)(param_1 + 0x1a4) = 0;
    *(undefined8 *)(param_1 + 0x1a8) = 0;
    *(undefined8 *)(param_1 + 0x1b0) = 0;
  }
  uVar14 = 0x15a;
  pcVar13 = "_ksmdbgssnInitClient(pGpu, pKernelSMDebuggerSession)";
LAB_00370ae3:
  nvCheckOkFailedNoLog(4,iVar11,pcVar13,"src/kernel/gpu/gr/kernel_sm_debugger_session.c",uVar14);
  return iVar11;
}


// ===== 00370c50 ksmdbgssnDestruct_IMPL =====

void ksmdbgssnDestruct_IMPL(void)

{
  return;
}


// ===== 00370c60 ksmdbgssnFreeCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void ksmdbgssnFreeCallback_IMPL(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(4);
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  (**(code **)(lVar2 + 0x18))
            (lVar2,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x1a4),
             *(code **)(lVar2 + 0x18));
  kgrctxDeregisterKernelSMDebuggerSession_IMPL
            (uVar1,*(undefined8 *)(*(long *)(param_1 + 0x188) + 0x208),param_1);
  return;
}


// ===== 00370cc0 dbgSessionRemoveDependant_IMPL =====

void dbgSessionRemoveDependant_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
    lVar1 = __nvoc_dynamicCast(0,__nvoc_class_def_RsSession);
    uVar2 = 0;
    if ((*(char *)(lVar1 + 0xa0) != '\0') && (*(int *)(param_2 + 0x11c) == 0x83de)) {
      uVar3 = __nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),
                                 __nvoc_class_def_KernelSMDebuggerSession);
      ksmdbgssnFreeCallback_IMPL(uVar3);
    }
  }
  else {
    lVar1 = __nvoc_dynamicCast(param_1,__nvoc_class_def_RsSession);
    if ((*(char *)(lVar1 + 0xa0) != '\0') && (*(int *)(param_2 + 0x11c) == 0x83de)) {
      uVar2 = __nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),
                                 __nvoc_class_def_KernelSMDebuggerSession);
      ksmdbgssnFreeCallback_IMPL(uVar2);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x110);
  }
  sessionRemoveDependant_IMPL(uVar2,param_2);
  return;
}


// ===== 00370d80 dbgSessionRemoveDependency_IMPL =====

void dbgSessionRemoveDependency_IMPL(long param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  if (param_1 == 0) {
    lVar2 = __nvoc_dynamicCast(0,__nvoc_class_def_RsSession);
    if (*(char *)(lVar2 + 0xa0) == '\0') goto LAB_00370dbb;
LAB_00370de0:
    lVar2 = lVar2 + 0xd0;
    uVar3 = listTail_IMPL(lVar2);
    uVar4 = listHead_IMPL(lVar2);
    listIterRange_IMPL(&local_68,lVar2,uVar4,uVar3);
    local_48 = local_68;
    local_40 = local_60;
    local_38 = local_58;
    local_30 = local_50;
    while (cVar1 = listIterNext_IMPL(&local_48), cVar1 != '\0') {
      if (*(int *)(*local_48 + 0x11c) == 0x83de) {
        uVar3 = __nvoc_dynamicCast(*(undefined8 *)(*local_48 + 8),
                                   __nvoc_class_def_KernelSMDebuggerSession);
        ksmdbgssnFreeCallback_IMPL(uVar3);
      }
    }
    if (param_1 == 0) goto LAB_00370dbb;
  }
  else {
    lVar2 = __nvoc_dynamicCast(param_1,__nvoc_class_def_RsSession);
    if (*(char *)(lVar2 + 0xa0) != '\0') goto LAB_00370de0;
  }
  param_1 = *(long *)(param_1 + 0x110);
LAB_00370dbb:
  sessionRemoveDependency_IMPL(param_1,param_2);
  return;
}


// ===== 00370ea0 ksmdbgssnInternalControlForward_IMPL =====

void ksmdbgssnInternalControlForward_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x158);
  }
  gpuresInternalControlForward_IMPL(uVar1);
  return;
}


// ===== 00370ec0 ksmdbgssnGetInternalObjectHandle_IMPL =====

undefined8 ksmdbgssnGetInternalObjectHandle_IMPL(void)

{
  return 0;
}


// ===== 00370ed0 _nv8deCtrlCmdReadWriteSurface =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _nv8deCtrlCmdReadWriteSurface(long param_1,uint *param_2,char param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  char *pcVar10;
  uint *puVar11;
  ulong uVar12;
  long lVar13;
  int iVar14;
  ulong uVar15;
  long local_80;
  long local_68;
  long *local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *param_2;
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1b78);
  uVar9 = **(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x5f);
    iVar14 = 0x2f;
  }
  else if (uVar1 < 0x41) {
    iVar5 = CliGetKernelChannel(uVar9,*(undefined4 *)(param_1 + 0x198),&local_68);
    if (iVar5 == 0) {
      iVar14 = 0;
      if (uVar1 != 0) {
        puVar11 = param_2 + 2;
        do {
          uVar15 = (ulong)puVar11[4];
          if (uVar15 == 0) {
            nvCheckFailedNoLog(4,"bufSize != 0",
                               "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x6e);
            return 0x1f;
          }
          local_80 = *(long *)(puVar11 + 2);
          lVar13 = *(long *)puVar11;
          do {
            uVar6 = gpumgrGetDeviceGpuMask(*(undefined4 *)(lVar2 + 0x7b4));
            cVar4 = CliGetDmaMappingInfo
                              (uVar9,*(undefined4 *)
                                      (*(long *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x18
                                                ) + 0x10),*(undefined4 *)(local_68 + 0x298),lVar13,
                               uVar6,&local_60);
            if (cVar4 == '\0') {
              nvCheckFailedNoLog(4,
                                 "CliGetDmaMappingInfo(pClient, RES_GET_PARENT_HANDLE(pKernelSMDebuggerSession), pKernelChannel->hVASpace, virtAddr, gpumgrGetDeviceGpuMask(pGpu->deviceInstance), &pDmaMappingInfo)"
                                 ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x75);
              return 0x1f;
            }
            local_58 = local_60[0x1a];
            local_48 = 0;
            local_40 = 0;
            uVar12 = (*(long *)(local_58 + 0x30) + *local_60) - lVar13;
            if (uVar15 < uVar12) {
              uVar12 = uVar15;
            }
            local_50 = lVar13 - *local_60;
            lVar8 = portMemAllocNonPaged(uVar12);
            if (lVar8 == 0) {
              nvCheckFailedNoLog(4,"pKernBuffer != NULL",
                                 "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x7f);
              return 0x1a;
            }
            uVar6 = memdescGetPteKindForGpu
                              ((undefined8 *)local_60[0x1a],*(undefined8 *)local_60[0x1a]);
            cVar4 = (**(code **)(lVar3 + 0x2a8))(lVar3,0xb,uVar6);
            if ((cVar4 == '\0') && (*(char *)(lVar2 + 0x490e) == '\0')) {
              cVar4 = gpuIsCCFeatureEnabled_IMPL(lVar2);
              iVar14 = (uint)(cVar4 == '\0') << 6;
            }
            else {
              iVar14 = 0x400;
            }
            if (param_3 == '\0') {
              iVar7 = memmgrMemRead_IMPL(lVar3,&local_58,lVar8,uVar12);
              if (iVar7 != 0) {
                uVar9 = 0xa4;
                pcVar10 = 
                "memmgrMemRead(pMemoryManager, &surf, pKernBuffer, curSize, transferFlags)";
                goto LAB_003711b6;
              }
              iVar7 = portMemExCopyToUser(lVar8,local_80,uVar12);
              if (iVar7 != 0) {
                uVar9 = 0xa9;
                pcVar10 = "portMemExCopyToUser(pKernBuffer, bufPtr, curSize)";
                goto LAB_003711b6;
              }
            }
            else {
              iVar7 = portMemExCopyFromUser(local_80,lVar8,uVar12);
              if (iVar7 != 0) {
                uVar9 = 0x97;
                pcVar10 = "portMemExCopyFromUser(bufPtr, pKernBuffer, curSize)";
LAB_003711b6:
                nvAssertOkFailedNoLog
                          (iVar7,pcVar10,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",uVar9
                          );
                portMemFree(lVar8);
                return iVar7;
              }
              iVar7 = memmgrMemWrite_IMPL(lVar3,&local_58,lVar8,uVar12,iVar14);
              if (iVar7 != 0) {
                uVar9 = 0x9d;
                pcVar10 = 
                "memmgrMemWrite(pMemoryManager, &surf, pKernBuffer, curSize, transferFlags)";
                goto LAB_003711b6;
              }
            }
            lVar13 = lVar13 + uVar12;
            portMemFree(lVar8);
            local_80 = local_80 + uVar12;
            uVar15 = uVar15 - uVar12;
          } while (uVar15 != 0);
          puVar11 = puVar11 + 6;
          iVar14 = iVar5;
        } while (puVar11 != param_2 + (ulong)uVar1 * 6 + 2);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "CliGetKernelChannel(pClient, pKernelSMDebuggerSession->hChannel, &pKernelChannel)"
                 ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",100);
      iVar14 = iVar5;
    }
  }
  else {
    iVar14 = 0x1f;
  }
  return iVar14;
}


// ===== 00371310 _nv83deCtrlCmdDebugAccessMemory =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

ulong _nv83deCtrlCmdDebugAccessMemory
                (long param_1,long param_2,undefined4 param_3,uint param_4,ulong param_5,
                uint param_6,undefined8 param_7,int param_8)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  char *pcVar10;
  ulong uVar11;
  undefined8 uVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 *local_88;
  undefined1 local_68 [4];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar13 = (ulong)param_6;
  uVar14 = (ulong)param_4;
  iVar3 = serverutilGetResourceRef(param_3,param_4,&local_60);
  if (iVar3 != 0) {
    return 0x1b;
  }
  lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_60 + 8),__nvoc_class_def_Memory);
  if (lVar6 == 0) {
    nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x1ae,
                 "_nv83deCtrlCmdDebugAccessMemory",3,
                 "NVRM: Invalid handle: hMemory %x is not of type classId(Memory): (GPU 0x%llx, hClient 0x%x, hMemory %x, offset 0x%llx, length 0x%x, flags 0x%x)\n"
                 ,uVar14,*(undefined8 *)(param_1 + 0x848),param_3,uVar14,param_5,uVar13,0);
    return 0x1f;
  }
  lVar6 = *(long *)(lVar6 + 0x118);
  if (lVar6 == 0) {
    return 0x40;
  }
  if (param_6 == 0) {
    return 0x1f;
  }
  if (CARRY8(param_5,uVar13)) {
    return 0x1f;
  }
  if (*(ulong *)(lVar6 + 0x30) < param_5 + uVar13) {
    return 0x1f;
  }
  iVar4 = memdescGetAddressSpace(lVar6);
  iVar3 = *(int *)(lVar6 + 0x6c);
  osFlushCpuWriteCombineBuffer();
  if (iVar4 == 1) {
    if (iVar3 == 0) {
      local_58 = (ulong)local_58._4_4_ << 0x20;
      gpumgrGetGpuAttachInfo(local_68,&local_64);
      while (lVar7 = gpumgrGetNextGpu(local_64,&local_58), lVar7 != 0) {
        if ((*(char *)(lVar7 + 0x45a) == '\0') &&
           (pcVar1 = *(code **)(*(long *)(lVar7 + 0x1b70) + 0x188),
           uVar5 = (*pcVar1)(lVar7,*(long *)(lVar7 + 0x1b70),lVar6,1,1,pcVar1), uVar5 != 0)) {
          nvCheckOkFailedNoLog
                    (4,uVar5,
                     "kmemsysCacheOp_HAL(pTempGpu, GPU_GET_KERNEL_MEMORY_SYSTEM(pTempGpu), pMemDesc, FB_CACHE_SYSTEM_MEMORY, FB_CACHE_INVALIDATE)"
                     ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x112);
          nvAssertOkFailedNoLog
                    (uVar5,"_nv83deFlushAllGpusL2Cache(pMemDesc)",
                     "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x1d2);
          return (ulong)uVar5;
        }
      }
    }
    goto LAB_00371675;
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_00371675;
LAB_0037165c:
    if (*(char *)(param_1 + 0x491e) == '\0') {
LAB_00371675:
      local_88 = &local_58;
      local_48 = 0;
      local_40 = 0;
      uVar12 = *(undefined8 *)(param_1 + 0x1b78);
      local_58 = lVar6;
      local_50 = param_5;
      cVar2 = gpuIsCCFeatureEnabled_IMPL();
      lVar6 = 0x440;
      if (cVar2 != '\0') {
        cVar2 = gpuIsCCDevToolsModeEnabled_IMPL(param_1);
        lVar6 = (ulong)(cVar2 != '\0') << 10;
      }
      if (param_8 == 1) {
        uVar5 = memmgrMemRead_IMPL(uVar12,local_88,param_7,uVar13,lVar6);
        uVar12 = 0x234;
        pcVar10 = "memmgrMemRead(pMemoryManager, &surf, NvP64_VALUE(buffer), length, transferFlags)"
        ;
        if (uVar5 == 0) {
          return 0;
        }
      }
      else {
        uVar5 = memmgrMemWrite_IMPL();
        if (uVar5 == 0) {
          return 0;
        }
        uVar12 = 0x239;
        pcVar10 = 
        "memmgrMemWrite(pMemoryManager, &surf, NvP64_VALUE(buffer), length, transferFlags)";
      }
      nvCheckOkFailedNoLog
                (4,uVar5,pcVar10,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",uVar12);
      return (ulong)uVar5;
    }
  }
  else if (*(char *)(param_1 + 0x4913) != '\0') goto LAB_0037165c;
  local_58 = 0;
  lVar6 = rmapiGetInterface(4);
  if (*(int *)(param_2 + 0x1b4) == 0) {
    uVar12 = (**(code **)(lVar6 + 0x50))
                       (lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1a8),
                        param_2 + 0x1b4,param_3,uVar14,0);
    if ((int)uVar12 != 0) {
      uVar11 = uVar14;
      nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x15c,
                   "_nv83deMapMemoryIntoGrdbgClient",3,
                   "NVRM: Unable to dup source memory (0x%x,0x%x) under device (status = 0x%x). Attempting subdevice dup.\n"
                   ,param_3,uVar14,uVar12);
      uVar9 = (**(code **)(lVar6 + 0x50))
                        (lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1ac),
                         param_2 + 0x1b4,param_3,uVar14,uVar11 & 0xffffffff00000000);
      uVar11 = uVar9 & 0xffffffff;
      if ((int)uVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x16a,
                     "_nv83deMapMemoryIntoGrdbgClient",3,
                     "NVRM: Unable to dup source memory (0x%x,0x%x) under subdevice (status = 0x%x). Aborting.\n"
                     ,param_3,uVar14,uVar9);
        goto LAB_003718a0;
      }
    }
    uVar5 = (**(code **)(lVar6 + 0x70))
                      (lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1ac),
                       *(undefined4 *)(param_2 + 0x1b4),param_5,uVar13,&local_58,param_8);
    uVar12 = local_58;
    uVar11 = (ulong)uVar5;
    if (uVar5 == 0) {
      if (param_8 == 1) {
        lVar6 = portMemCopy(param_7,uVar13,local_58);
        if (lVar6 != 0) {
          nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x205,
                       "_nv83deCtrlCmdDebugAccessMemory",1,
                       "NVRM: Reading %d bytes of memory from 0x%x\n",param_6,uVar14);
          goto LAB_003715d8;
        }
        nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x200,
                     "_nv83deCtrlCmdDebugAccessMemory",3,
                     "NVRM: portMemCopy failed (from VA 0x%p to 0x%p, length 0x%x)\n",uVar12,param_7
                     ,uVar13);
      }
      else {
        lVar6 = portMemCopy(local_58,uVar13,param_7);
        if (lVar6 != 0) {
          nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x213,
                       "_nv83deCtrlCmdDebugAccessMemory",1,
                       "NVRM: Writing %d bytes of memory to 0x%x\n",param_6,uVar14);
LAB_003715d8:
          lVar6 = rmapiGetInterface(4);
          pcVar1 = *(code **)(lVar6 + 0x88);
          uVar8 = osGetCurrentProcess();
          uVar5 = (*pcVar1)(lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1a8),
                            *(undefined4 *)(param_2 + 0x1b4),uVar12,param_8,uVar8);
          (**(code **)(lVar6 + 0x18))
                    (lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1b4));
          *(undefined4 *)(param_2 + 0x1b4) = 0;
          return (ulong)uVar5;
        }
        nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x20d,
                     "_nv83deCtrlCmdDebugAccessMemory",3,
                     "NVRM: portMemCopy failed (from VA 0x%p to 0x%p, length 0x%x)\n",param_7,uVar12
                     ,uVar13);
      }
      lVar6 = rmapiGetInterface(4);
      pcVar1 = *(code **)(lVar6 + 0x88);
      uVar8 = osGetCurrentProcess();
      (*pcVar1)(lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1a8),
                *(undefined4 *)(param_2 + 0x1b4),uVar12,param_8,uVar8);
      (**(code **)(lVar6 + 0x18))
                (lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1b4));
      *(undefined4 *)(param_2 + 0x1b4) = 0;
      return 0x1f;
    }
    nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x17c,
                 "_nv83deMapMemoryIntoGrdbgClient",3,"NVRM: RmMapMemory failed 0x%x\n",uVar5);
    (**(code **)(lVar6 + 0x18))
              (lVar6,*(undefined4 *)(param_2 + 0x1a4),*(undefined4 *)(param_2 + 0x1b4));
    *(undefined4 *)(param_2 + 0x1b4) = 0;
  }
  else {
    uVar11 = 0x40;
    nvAssertFailedNoLog("pKernelSMDebuggerSession->hInternalMemMapping == NV01_NULL_OBJECT",
                        "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x150);
  }
LAB_003718a0:
  nvDbg_Printf("src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x1ee,
               "_nv83deCtrlCmdDebugAccessMemory",3,
               "NVRM: Failed to map memory into internal smdbg client (GPU 0x%llx, hClient 0x%x, hMemory %x, offset 0x%llx, length 0x%x, flags 0x%x): (rmStatus = %x)\n"
               ,*(undefined8 *)(param_1 + 0x848),param_3,uVar14,param_5,uVar13,param_8,uVar11);
  return uVar11;
}


// ===== 00371a60 ksmdbgssnCtrlCmdReadSurface_IMPL =====

void ksmdbgssnCtrlCmdReadSurface_IMPL(undefined8 param_1,undefined8 param_2)

{
  _nv8deCtrlCmdReadWriteSurface(param_1,param_2,0);
  return;
}


// ===== 00371a70 ksmdbgssnCtrlCmdWriteSurface_IMPL =====

void ksmdbgssnCtrlCmdWriteSurface_IMPL(undefined8 param_1,undefined8 param_2)

{
  _nv8deCtrlCmdReadWriteSurface(param_1,param_2,1);
  return;
}


// ===== 00371a80 ksmdbgssnCtrlCmdGetMappings_IMPL =====

/* WARNING: Type propagation algorithm not settling */

ulong ksmdbgssnCtrlCmdGetMappings_IMPL(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  long local_68 [3];
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  long *local_30;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = **(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
  local_68[1] = 0;
  local_68[2] = 0;
  local_50 = (undefined8 *)0x0;
  local_48 = 0;
  local_40 = 0;
  local_38 = 0;
  local_30 = (long *)0x0;
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 != '\0') && (cVar3 = rmGpuLockIsOwner(), cVar3 != '\0')) {
    local_68[0] = 0;
    uVar4 = CliGetKernelChannel(uVar2,*(undefined4 *)(param_1 + 0x198),local_68);
    if (uVar4 == 0) {
      if (local_68[0] != 0) {
        local_40 = *param_2;
        local_38 = param_2[1];
        local_48 = CONCAT44(local_48._4_4_,3);
        local_30 = local_68 + 1;
        local_50 = param_2;
        uVar5 = mmuTrace(uVar1,*(undefined8 *)(local_68[0] + 0x2a0),&local_48);
        return uVar5;
      }
      nvAssertFailedNoLog("pKernelChannel != NULL",
                          "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x48);
      uVar4 = 0x1f;
    }
    else {
      nvAssertOkFailedNoLog
                (uVar4,"CliGetKernelChannel(pClient, hChannel, &pKernelChannel)",
                 "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x47);
    }
    nvAssertOkFailedNoLog
              (uVar4,
               "_nv83deCtrlCmdFetchVAS(pClient, pKernelSMDebuggerSession->hChannel, &pVASpace)",
               "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0xe0);
    return (ulong)uVar4;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0xdd);
  return 0x2f;
}


// ===== 00371c17 ksmdbgssnCtrlCmdDebugReadMemory_IMPL.cold =====

void ksmdbgssnCtrlCmdDebugReadMemory_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00371c30 ksmdbgssnCtrlCmdDebugReadMemory_IMPL =====

void ksmdbgssnCtrlCmdDebugReadMemory_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    _nv83deCtrlCmdDebugAccessMemory
              (*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),param_1,
               *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48),*param_2,
               *(undefined8 *)(param_2 + 2),param_2[1],*(undefined8 *)(param_2 + 4),1);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00371c7b ksmdbgssnCtrlCmdDebugWriteMemory_IMPL.cold =====

void ksmdbgssnCtrlCmdDebugWriteMemory_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00371c90 ksmdbgssnCtrlCmdDebugWriteMemory_IMPL =====

void ksmdbgssnCtrlCmdDebugWriteMemory_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    _nv83deCtrlCmdDebugAccessMemory
              (*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),param_1,
               *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48),*param_2,
               *(undefined8 *)(param_2 + 2),param_2[1],*(undefined8 *)(param_2 + 4),2);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00371ce0 ksmdbgssnCtrlCmdDebugExecRegOps_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong ksmdbgssnCtrlCmdDebugExecRegOps_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  
  if (100 < *(uint *)(param_2 + 4)) {
    nvCheckFailedNoLog(3,"pParams->regOpCount <= NV83DE_CTRL_GPU_EXEC_REG_OPS_MAX_OPS",
                       "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x27a);
    return 0x1f;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = gpuValidateRegOps(lVar1,param_2 + 8,*(uint *)(param_2 + 4),*param_2,0,0);
  if (uVar3 == 0) {
    if (*(char *)(lVar1 + 0x909) == '\0') {
      return 0x56;
    }
    lVar4 = resservGetTlsCallContext();
    puVar2 = *(undefined4 **)(lVar4 + 0x48);
    uVar5 = (**(code **)(lVar1 + 0x3b90))
                      (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                       puVar2[6]);
    return uVar5;
  }
  nvCheckOkFailedNoLog
            (1,uVar3,
             "gpuValidateRegOps(pGpu, pParams->regOps, pParams->regOpCount, pParams->bNonTransactional, isClientGspPlugin, NV_FALSE)"
             ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x27f);
  return (ulong)uVar3;
}


// ===== 00371dd0 ksmdbgssnCtrlCmdDebugReadBatchMemory_IMPL =====

int ksmdbgssnCtrlCmdDebugReadBatchMemory_IMPL(long param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  
  if (0x96 < *(uint *)((long)param_2 + 0xc)) {
    nvCheckFailedNoLog(3,"pParams->count <= MAX_ACCESS_MEMORY_OPS",
                       "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x29f);
    return 0x1f;
  }
  iVar6 = 0;
  if (*(uint *)((long)param_2 + 0xc) != 0) {
    iVar6 = 0;
    uVar7 = 0;
    uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
    do {
      uVar5 = (ulong)uVar7;
      uVar1 = *(uint *)(param_2 + uVar5 * 3 + 4);
      uVar2 = *(uint *)((long)param_2 + uVar5 * 0x18 + 0x14);
      if ((CARRY4(uVar1,uVar2)) || (*(uint *)(param_2 + 1) < uVar1 + uVar2)) {
        nvCheckFailedNoLog(3,
                           "portSafeAddU32(pParams->entries[i].dataOffset, pParams->entries[i].length, &endingOffset) && (endingOffset <= pParams->dataLength)"
                           ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x2a8);
        iVar4 = 0x37;
LAB_00371eb7:
        if (iVar6 == 0) {
          iVar6 = iVar4;
        }
      }
      else {
        iVar4 = _nv83deCtrlCmdDebugAccessMemory
                          (uVar3,param_1,
                           *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48),
                           (int)param_2[uVar5 * 3 + 2],param_2[uVar5 * 3 + 3],uVar2,
                           (ulong)uVar1 + *param_2,1);
        if (iVar4 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar4,
                     "_nv83deCtrlCmdDebugAccessMemory(pGpu, pKernelSMDebuggerSession, RES_GET_CLIENT_HANDLE(pKernelSMDebuggerSession), pParams->entries[i].hMemory, pParams->entries[i].memOffset, pParams->entries[i].length, pData, GRDBG_MEM_ACCESS_TYPE_READ)"
                     ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x2ae);
          goto LAB_00371eb7;
        }
      }
      uVar7 = uVar7 + 1;
      *(int *)((long)param_2 + uVar5 * 0x18 + 0x24) = iVar4;
    } while (uVar7 < *(uint *)((long)param_2 + 0xc));
  }
  return iVar6;
}


// ===== 00371f40 ksmdbgssnCtrlCmdDebugWriteBatchMemory_IMPL =====

int ksmdbgssnCtrlCmdDebugWriteBatchMemory_IMPL(long param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  uint uVar7;
  
  if (0x96 < *(uint *)((long)param_2 + 0xc)) {
    nvCheckFailedNoLog(3,"pParams->count <= MAX_ACCESS_MEMORY_OPS",
                       "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x2cd);
    return 0x1f;
  }
  iVar6 = 0;
  if (*(uint *)((long)param_2 + 0xc) != 0) {
    iVar6 = 0;
    uVar7 = 0;
    uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
    do {
      uVar5 = (ulong)uVar7;
      uVar1 = *(uint *)(param_2 + uVar5 * 3 + 4);
      uVar2 = *(uint *)((long)param_2 + uVar5 * 0x18 + 0x14);
      if ((CARRY4(uVar1,uVar2)) || (*(uint *)(param_2 + 1) < uVar1 + uVar2)) {
        nvCheckFailedNoLog(3,
                           "portSafeAddU32(pParams->entries[i].dataOffset, pParams->entries[i].length, &endingOffset) && (endingOffset <= pParams->dataLength)"
                           ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x2d6);
        iVar4 = 0x37;
LAB_00372027:
        if (iVar6 == 0) {
          iVar6 = iVar4;
        }
      }
      else {
        iVar4 = _nv83deCtrlCmdDebugAccessMemory
                          (uVar3,param_1,
                           *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48),
                           (int)param_2[uVar5 * 3 + 2],param_2[uVar5 * 3 + 3],uVar2,
                           (ulong)uVar1 + *param_2,2);
        if (iVar4 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar4,
                     "_nv83deCtrlCmdDebugAccessMemory(pGpu, pKernelSMDebuggerSession, RES_GET_CLIENT_HANDLE(pKernelSMDebuggerSession), pParams->entries[i].hMemory, pParams->entries[i].memOffset, pParams->entries[i].length, pData, GRDBG_MEM_ACCESS_TYPE_WRITE)"
                     ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x2dc);
          goto LAB_00372027;
        }
      }
      uVar7 = uVar7 + 1;
      *(int *)((long)param_2 + uVar5 * 0x18 + 0x24) = iVar4;
    } while (uVar7 < *(uint *)((long)param_2 + 0xc));
  }
  return iVar6;
}


// ===== 003720b0 ksmdbgssnCtrlCmdDebugReadAllSmErrorStates_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 ksmdbgssnCtrlCmdDebugReadAllSmErrorStates_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar4 = rmapiLockIsOwner();
  if (cVar4 != '\0') {
    cVar4 = rmGpuLockIsOwner();
    if (cVar4 != '\0') {
      uVar6 = 0x56;
      if (*(char *)(lVar1 + 0x908) != '\0') {
        lVar7 = resservGetTlsCallContext();
        puVar2 = *(undefined4 **)(*(long *)(lVar7 + 0x48) + 0x70);
        lVar7 = gpuGetRpc(*(undefined8 *)(puVar2 + 8));
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",
                              0x301);
          uVar6 = 0x1a;
        }
        else {
          lVar3 = *(long *)(puVar2 + 8);
          if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
            uVar6 = rpcDmaControl_wrapper
                              (lVar3,lVar7,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                               puVar2[6]);
          }
          else {
            uVar6 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,*puVar2,puVar2[1]);
          }
        }
        if (*(char *)(lVar1 + 0x4913) != '\0') {
          iVar5 = kgrctxLookupMmuFault_IMPL
                            (lVar1,*(undefined8 *)(*(long *)(param_1 + 0x188) + 0x208),
                             param_2 + 0x12cc);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "kgrctxLookupMmuFault(pGpu, kgrobjGetKernelGraphicsContext(pGpu, pKernelSMDebuggerSession->pObject), &pParams->mmuFault)"
                       ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x312);
          }
        }
      }
      return uVar6;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x2fa);
  return 0x2f;
}


// ===== 00372260 ksmdbgssnCtrlCmdDebugClearAllSmErrorStates_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 ksmdbgssnCtrlCmdDebugClearAllSmErrorStates_IMPL(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 uStack_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar4 = rmapiLockIsOwner();
  if (cVar4 != '\0') {
    cVar4 = rmGpuLockIsOwner();
    if (cVar4 != '\0') {
      uVar6 = 0x56;
      if (*(char *)(lVar1 + 0x908) != '\0') {
        lVar7 = resservGetTlsCallContext();
        puVar2 = *(undefined4 **)(*(long *)(lVar7 + 0x48) + 0x70);
        uStack_30 = 0x3722fa;
        lVar7 = gpuGetRpc(*(undefined8 *)(puVar2 + 8));
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",
                              0x32e);
          uVar6 = 0x1a;
          uStack_30 = extraout_RDX_00;
        }
        else {
          lVar3 = *(long *)(puVar2 + 8);
          if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
            uVar6 = rpcDmaControl_wrapper
                              (lVar3,lVar7,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                               puVar2[6]);
          }
          else {
            uVar6 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,*puVar2,puVar2[1]);
            uStack_30 = extraout_RDX;
          }
        }
        if (*(char *)(lVar1 + 0x4913) != '\0') {
          iVar5 = kgrctxClearMmuFault_IMPL
                            (lVar1,*(undefined8 *)(*(long *)(param_1 + 0x188) + 0x208),uStack_30);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "kgrctxClearMmuFault(pGpu, kgrobjGetKernelGraphicsContext(pGpu, pKernelSMDebuggerSession->pObject))"
                       ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x33f);
          }
        }
      }
      return uVar6;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x328);
  return 0x2f;
}


// ===== 003723f0 ksmdbgssnCtrlCmdDebugReadMMUFaultInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong ksmdbgssnCtrlCmdDebugReadMMUFaultInfo_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  ulong uVar4;
  long lVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*(char *)(lVar1 + 0x909) == '\0') {
        uVar4 = kgrctxLookupMmuFaultInfo_IMPL
                          (lVar1,*(undefined8 *)(*(long *)(param_1 + 0x188) + 0x208),param_2);
        if ((int)uVar4 != 0) {
          nvAssertOkFailedNoLog
                    (uVar4 & 0xffffffff,
                     "kgrctxLookupMmuFaultInfo(pGpu, kgrobjGetKernelGraphicsContext(pGpu, pKernelSMDebuggerSession->pObject), pParams)"
                     ,"src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x362);
          uVar4 = uVar4 & 0xffffffff;
        }
        return uVar4;
      }
      lVar5 = resservGetTlsCallContext();
      puVar2 = *(undefined4 **)(*(long *)(lVar5 + 0x48) + 0x70);
      uVar4 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/gr/kernel_sm_debugger_session_ctrl.c",0x352);
  return 0x2f;
}


// ===== 00372500 kwdtConstruct_IMPL =====

undefined8 kwdtConstruct_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int local_1c;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) &&
     (cVar2 = kmigmgrIsMIGEnabled_IMPL(lVar1), cVar2 != '\0')) {
    *(uint *)(param_1 + 0x150) = *(uint *)(param_1 + 0x150) | 2;
  }
  local_1c = 0;
  iVar3 = osReadRegistryDword(lVar1,"RmEnableGrWatchdog",&local_1c);
  if (iVar3 == 0) {
    if (local_1c != 0) {
      if (local_1c != 1) {
        return 0;
      }
      *(uint *)(param_1 + 0x150) = *(uint *)(param_1 + 0x150) & 0xfffffffd;
      return 0;
    }
  }
  else if (((*(char *)(lVar1 + 0x446) == '\0') && (*(char *)(lVar1 + 0x490e) == '\0')) &&
          (cVar2 = gpuIsCCFeatureEnabled_IMPL(lVar1), cVar2 == '\0')) {
    return 0;
  }
  *(uint *)(param_1 + 0x150) = *(uint *)(param_1 + 0x150) | 2;
  return 0;
}


// ===== 003725c0 kwdtDestruct_IMPL =====

void kwdtDestruct_IMPL(void)

{
  return;
}


// ===== 003725d0 kgspExecuteScrubberIfNeeded_AD102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspExecuteScrubberIfNeeded_AD102(long param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  
  lVar1 = *(long *)(param_1 + 0x1ba0);
  uVar3 = regRead032(param_1 + 0x3a18,0,0,0x1180fc,0);
  if (uVar3 < 0x60000000) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/ada/kernel_gsp_ad102.c",0x41,
                 "kgspExecuteScrubberIfNeeded_AD102",1,"NVRM: executing Scrubber\n");
    if (*(long *)(param_2 + 0xa58) == 0) {
      nvAssertFailedNoLog("pKernelGsp->pScrubberUcode != NULL",
                          "src/kernel/gpu/gsp/arch/ada/kernel_gsp_ad102.c",0x42);
      iVar4 = 0x40;
    }
    else {
      if (lVar1 == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      iVar4 = (**(code **)(*(long *)(lVar1 + 2000) + 0x508))(param_1);
      if (iVar4 == 0) {
        iVar4 = (**(code **)(param_2 + 0x930))
                          (param_1,param_2,*(undefined8 *)(param_2 + 0xa58),
                           *(undefined8 *)(lVar1 + 2000),0,0);
        if (iVar4 == 0) {
          uVar3 = regRead032(param_1 + 0x3a18,0,0,0x1180fc,0);
          if (uVar3 < 0x60000000) {
            nvDbg_Printf("src/kernel/gpu/gsp/arch/ada/kernel_gsp_ad102.c",0x51,
                         "kgspExecuteScrubberIfNeeded_AD102",4,
                         "NVRM: failed to execute Scrubber: done bit not set\n");
            iVar4 = 0xffff;
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/gsp/arch/ada/kernel_gsp_ad102.c",0x4b,
                       "kgspExecuteScrubberIfNeeded_AD102",4,
                       "NVRM: failed to execute Scrubber: 0x%x\n",iVar4);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,"kflcnReset_HAL(pGpu, staticCast(pKernelSec2, KernelFalcon))",
                   "src/kernel/gpu/gsp/arch/ada/kernel_gsp_ad102.c",0x44);
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/ada/kernel_gsp_ad102.c",0x3d,
                 "kgspExecuteScrubberIfNeeded_AD102",1,
                 "NVRM: skipping executing Scrubber as it already ran\n");
    iVar4 = 0;
  }
  return iVar4;
}


// ===== 003727e0 s_dmaPollCondFunc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 s_dmaPollCondFunc(undefined8 param_1,long *param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_2 + 0x4c0))(param_1,*param_2,0x118);
  return CONCAT31((int3)((uVar1 & *(uint *)(param_2 + 1)) >> 8),
                  (uVar1 & *(uint *)(param_2 + 1)) == *(uint *)((long)param_2 + 0xc));
}


// ===== 00372820 _kgspSetupPkcParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kgspSetupPkcParams(undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                        undefined1 param_5)

{
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x210,param_3);
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x19c,param_4);
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x198,param_5);
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x180,1);
  return;
}


// ===== 003728b0 s_dmaPoll_GA102 =====

ulong s_dmaPoll_GA102(long param_1,undefined8 param_2,int param_3)

{
  ulong uVar1;
  undefined8 local_28;
  int local_20;
  uint local_1c;
  
  local_1c = -(uint)(param_3 != 0) & 2;
  local_20 = 2 - (uint)(param_3 == 0);
  local_28 = param_2;
  uVar1 = timeoutCondWait(param_1 + 0x1af0,0,s_dmaPollCondFunc,&local_28,0x5c);
  if ((int)uVar1 == 0) {
    return uVar1 & 0xffffffff;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0x5f,"s_dmaPoll_GA102",4,
               "NVRM: Error while waiting for Falcon DMA; mode: %d, status: 0x%08x\n",param_3,uVar1)
  ;
  return uVar1 & 0xffffffff;
}


// ===== 00372950 s_dmaTransfer_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void s_dmaTransfer_GA102(undefined8 param_1,long param_2,int param_3,int param_4,ulong param_5,
                        uint param_6,undefined4 param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = s_dmaPoll_GA102(param_1,param_2,0);
  if (iVar1 != 0) {
    return;
  }
  (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x110,param_5 >> 8);
  (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x128,(uint)(param_5 >> 0x28) & 0x1ff);
  uVar3 = 0;
  if (param_6 != 0) {
    do {
      iVar1 = s_dmaPoll_GA102(param_1,param_2,0);
      if (iVar1 != 0) {
        return;
      }
      iVar1 = uVar3 + param_4;
      uVar2 = uVar3 + param_3;
      uVar3 = uVar3 + 0x100;
      (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x114,uVar2 & 0xffffff);
      (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x11c,iVar1);
      (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x118,param_7);
    } while (uVar3 < param_6);
  }
  s_dmaPoll_GA102(param_1,param_2,1);
  return;
}


// ===== 00372a90 kgspExecuteHsFalcon_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgspExecuteHsFalcon_GA102
                (long param_1,undefined8 param_2,int *param_3,long param_4,undefined4 *param_5,
                undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("pFlcnUcode != NULL",
                        "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",200);
    return 0x1f;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("pKernelFlcn != NULL",
                        "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0xc9);
    return 0x40;
  }
  if (*(char *)(param_4 + 0x628) == '\0') {
    nvAssertFailedNoLog("pKernelFlcn->bBootFromHs",
                        "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0xcb);
  }
  else {
    if (*param_3 == 2) {
      if (*(long *)(param_3 + 2) == 0) {
        nvAssertFailedNoLog("pUcode->pUcodeMemDesc != NULL",
                            "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0xd0);
        return 0x1f;
      }
      iVar2 = memdescGetAddressSpace();
      if (iVar2 != 1) {
        nvAssertFailedNoLog("memdescGetAddressSpace(pUcode->pUcodeMemDesc) == ADDR_SYSMEM",
                            "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0xd2);
        return 0x1f;
      }
      (**(code **)(param_4 + 0x520))(param_1,param_4);
      uVar3 = regRead032(param_1 + 0x3a18,0,0,*(undefined4 *)(param_4 + 0x624),0);
      regWrite032(param_1 + 0x3a18,0,0,*(undefined4 *)(param_4 + 0x624),uVar3 & 0xfffffffc | 5,0);
      lVar5 = memdescGetPhysAddr(*(undefined8 *)(param_3 + 2),1,0);
      uVar3 = s_dmaTransfer_GA102(param_1,param_4,param_3[7],(ulong)(uint)param_3[8],
                                  ((ulong)(uint)param_3[5] - (ulong)(uint)param_3[8]) + lVar5,
                                  param_3[6],0x614);
      uVar8 = 0xec;
      pcVar9 = 
      "s_dmaTransfer_GA102(pGpu, pKernelFlcn, pUcode->imemPa, pUcode->imemVa, srcPhysAddr, pUcode->imemSize, dmaCmd)"
      ;
      if (uVar3 == 0) {
        uVar4 = 0x10600;
        if (param_3[0xc] == -1) {
          uVar4 = 0x600;
        }
        lVar6 = memdescGetPhysAddr(*(undefined8 *)(param_3 + 2),1,0);
        uVar3 = param_3[0xc];
        lVar5 = (ulong)(uint)param_3[9] + lVar6;
        uVar1 = 0;
        if (uVar3 != 0xffffffff) {
          lVar5 = ((ulong)(uint)param_3[9] + lVar6) - (ulong)uVar3;
          uVar1 = uVar3;
        }
        uVar3 = s_dmaTransfer_GA102(param_1,param_4,param_3[0xb],uVar1,lVar5,param_3[10],uVar4);
        if (uVar3 == 0) {
          _kgspSetupPkcParams(param_1,param_4,param_3[0xd],param_3[0xf],param_3[0xe]);
          (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x104,param_3[8]);
          if (param_5 == (undefined4 *)0x0) {
            if (param_6 == (undefined4 *)0x0) {
              (**(code **)(param_4 + 0x518))(param_1,param_4);
              uVar7 = (**(code **)(param_4 + 0x538))(param_1,param_4,0,0);
              return uVar7;
            }
          }
          else {
            (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x40,*param_5);
            if (param_6 == (undefined4 *)0x0) {
              (**(code **)(param_4 + 0x518))(param_1,param_4);
              uVar3 = (**(code **)(param_4 + 0x538))(param_1,param_4,0,0);
              uVar4 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x40);
              *param_5 = uVar4;
              return (ulong)uVar3;
            }
          }
          (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x44,*param_6);
          (**(code **)(param_4 + 0x518))(param_1,param_4);
          uVar3 = (**(code **)(param_4 + 0x538))(param_1,param_4,0,0);
          if (param_5 != (undefined4 *)0x0) {
            uVar4 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x40);
            *param_5 = uVar4;
          }
          uVar4 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x44);
          *param_6 = uVar4;
          return (ulong)uVar3;
        }
        uVar8 = 0x109;
        pcVar9 = 
        "s_dmaTransfer_GA102(pGpu, pKernelFlcn, pUcode->dmemPa, memOff, srcPhysAddr, pUcode->dmemSize, dmaCmd)"
        ;
      }
      nvAssertOkFailedNoLog
                ((ulong)uVar3,pcVar9,"src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",
                 uVar8);
      return (ulong)uVar3;
    }
    nvAssertFailedNoLog("pFlcnUcode->bootType == KGSP_FLCN_UCODE_BOOT_FROM_HS",
                        "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0xcc);
  }
  return 0x56;
}


// ===== 00372f20 kgspLoadAndExecuteHsBinary_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgspLoadAndExecuteHsBinary_GA102(long param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  
  lVar6 = 0;
  if (param_2 != 0) {
    lVar6 = *(long *)(param_2 + 2000);
  }
  uVar2 = (**(code **)(param_2 + 0x938))(param_1,param_2);
  if (uVar2 == 0) {
    uVar2 = (**(code **)(lVar6 + 0x508))(param_1,lVar6);
    if (uVar2 == 0) {
      (**(code **)(lVar6 + 0x520))(param_1,lVar6);
      uVar2 = regRead032(param_1 + 0x3a18,0,0,*(undefined4 *)(lVar6 + 0x624),0);
      regWrite032(param_1 + 0x3a18,0,0,*(undefined4 *)(lVar6 + 0x624),uVar2 & 0xfffefffc | 4,0);
      uVar2 = s_dmaTransfer_GA102(param_1,lVar6,*(undefined4 *)((long)param_3 + 0x24),
                                  *(undefined4 *)(param_3 + 4),*param_3,*(undefined4 *)(param_3 + 5)
                                  ,0x614);
      if (uVar2 == 0) {
        iVar1 = *(int *)((long)param_3 + 0x2c);
        uVar4 = 0x10600;
        if (iVar1 == -1) {
          uVar4 = 0x600;
          iVar1 = 0;
        }
        uVar2 = s_dmaTransfer_GA102(param_1,lVar6,*(undefined4 *)(param_3 + 6),iVar1,param_3[1],
                                    *(undefined4 *)((long)param_3 + 0x34),uVar4);
        if (uVar2 == 0) {
          _kgspSetupPkcParams(param_1,lVar6,*(undefined4 *)(param_3 + 7),
                              *(undefined4 *)((long)param_3 + 0x3c),*(undefined4 *)(param_3 + 8));
          (**(code **)(lVar6 + 0x4c8))(param_1,lVar6,0x40,0xfe);
          (**(code **)(lVar6 + 0x4c8))(param_1,lVar6,0x104,*(undefined4 *)(param_3 + 4));
          (**(code **)(lVar6 + 0x518))(param_1,lVar6);
          uVar2 = (**(code **)(lVar6 + 0x538))(param_1,lVar6,0,0);
          if (uVar2 == 0) {
            uVar5 = (**(code **)(param_2 + 0x9e8))(param_1,param_2);
            return uVar5;
          }
          nvAssertOkFailedNoLog
                    (uVar2,"kflcnWaitForHalt_HAL(pGpu, pKernelFlcn, GPU_TIMEOUT_DEFAULT, 0)",
                     "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0x18e);
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar2,
                     "s_dmaTransfer_GA102(pGpu, pKernelFlcn, pParams->ucodeDmemPA, memOff, pParams->dmemPhysAddr, pParams->ucodeDmemSize, dmaCmd)"
                     ,"src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0x175);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar2,
                   "s_dmaTransfer_GA102(pGpu, pKernelFlcn, pParams->ucodeImemPA, pParams->ucodeImemVA, pParams->imemPhysAddr, pParams->ucodeImemSize, dmaCmd)"
                   ,"src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0x163);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar2,"kflcnReset_HAL(pGpu, pKernelFlcn)",
                 "src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0x14e);
    }
  }
  else {
    uVar3 = (**(code **)(lVar6 + 0x4c0))(param_1,lVar6,0x40);
    nvDbg_Printf("src/kernel/gpu/gsp/arch/ampere/kernel_gsp_falcon_ga102.c",0x149,
                 "kgspLoadAndExecuteHsBinary_GA102",4,
                 "NVRM: Timeout waiting for falcon to suspend. mailbox0: 0x%x\n",uVar3);
  }
  return (ulong)uVar2;
}


// ===== 003731f0 kgspIsDebugModeEnabled_GA100 =====

uint kgspIsDebugModeEnabled_GA100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x82074c,0);
  return ~uVar1 & 1;
}


// ===== 00373220 kgspReadUcodeFuseVersion_GA100 =====

ulong kgspReadUcodeFuseVersion_GA100(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if (0xf < param_3 - 1U) {
    return 0;
  }
  uVar3 = regRead032(param_1 + 0x3a18,0,0,param_3 * 4 + 0x8241bc,0);
  if ((uint)uVar3 != 0) {
    uVar2 = (uint)uVar3 >> 1;
    if (uVar2 == 0) {
      return 1;
    }
    iVar1 = 0x1f;
    if (uVar2 != 0) {
      for (; uVar2 >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    uVar3 = (ulong)(iVar1 + 2);
  }
  return uVar3;
}


// ===== 00373270 kgspConfigureFalcon_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspConfigureFalcon_GA102(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1f;
  
  portMemSet(&local_58,0,0x40);
  local_50 = 0x110600;
  local_58 = 0x11100000110000;
  local_4c = 1;
  local_48 = 0;
  local_40 = 0xda3de400;
  if ((*(long *)(param_1 + 0x1d18) == 0) || (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) == '\0')
     ) {
    local_1f = 1;
    local_30 = &DAT_00d35320;
    local_24 = 0x78;
    local_28 = (**(code **)(param_2 + 0x9d0))(param_2);
  }
  else if (param_2 == 0) {
    uVar1 = 0;
    goto LAB_003732ff;
  }
  uVar1 = *(undefined8 *)(param_2 + 2000);
LAB_003732ff:
  kflcnConfigureEngine_IMPL(param_1,uVar1,&local_58);
  return;
}


// ===== 00373330 kgspGetGspRmBootUcodeStorage_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspGetGspRmBootUcodeStorage_GA102
               (undefined8 param_1,long param_2,undefined8 *param_3,undefined8 *param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = (**(code **)(param_2 + 0x848))(param_2);
  cVar1 = (**(code **)(param_2 + 0x800))(param_1);
  if (cVar1 != '\0') {
    uVar2 = bindataArchiveGetStorage(uVar3,0x24);
    *param_3 = uVar2;
    uVar3 = bindataArchiveGetStorage(uVar3,0x13);
    *param_4 = uVar3;
    return;
  }
  uVar2 = bindataArchiveGetStorage(uVar3,0x26);
  *param_3 = uVar2;
  uVar3 = bindataArchiveGetStorage(uVar3,0x14);
  *param_4 = uVar3;
  return;
}


// ===== 003733e0 kgspEccServiceEvent_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void kgspEccServiceEvent_GB100(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x110888,0);
  if (uVar1 == 0) {
    nvAssertFailedNoLog("eccIntrStatus != 0",
                        "src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x31);
    return;
  }
  if ((uVar1 & 2) != 0) {
    (**(code **)(param_2 + 0x8d0))(param_1,param_2,*(code **)(param_2 + 0x8d0));
  }
  if ((uVar1 & 1) != 0) {
    nvAssertFailedNoLog("Corrected errors are not supported",
                        "src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x3b);
  }
  regWrite032(param_1 + 0x3a18,0,0,0x110878,0x80000000,0);
  return;
}


// ===== 003734c0 kgspEccServiceUncorrError_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspEccServiceUncorrError_GB100(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x1c18);
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x110878,0);
  if (uVar2 == 0) {
    nvAssertFailedNoLog("eccStatus != 0","src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",
                        0x50);
    return;
  }
  if ((uVar2 & 0x100) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x54,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_IMEM PENDING\n");
  }
  if ((uVar2 & 0x200) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x5a,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_DMEM PENDING\n");
  }
  if ((uVar2 & 0x4000) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x60,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_ICACHE PENDING\n");
  }
  if ((uVar2 & 0x8000) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x66,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_DCACHE PENDING\n");
  }
  if ((uVar2 & 0x400) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x6c,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_MPU_RAM PENDING\n");
  }
  if ((uVar2 & 0x800) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x72,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_DCLS PENDING\n");
  }
  if ((uVar2 & 0x1000) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x78,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_REG PENDING\n");
  }
  if ((uVar2 & 0x2000) != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x82,
                 "kgspEccServiceUncorrError_GB100",4,
                 "NVRM: NV_PGSP_FALCON_ECC_STATUS_UNCORRECTED_ERR_EMEM PENDING\n");
    *(undefined1 *)(param_2 + 0x69eff) = 1;
    if (lVar1 != 0) {
      krcRcAndNotifyAllChannels_IMPL(param_1,lVar1,0x30,1);
    }
    iVar3 = (**(code **)(param_1 + 0x100))(param_1);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,"gpuMarkDeviceForReset(pGpu)",
                 "src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_ecc_gb100.c",0x8c);
    }
  }
  gpuNotifySubDeviceEvent_IMPL(param_1,0x70,0,0,0,0x1d);
  nvErrorLog_va(param_1,0x30,"GSP-RISCV uncorrectable ECC error");
  nvErrorLog_va(param_1,0xac,"GSP-RISCV, Uncorrectable SRAM error");
  return;
}


// ===== 003737b0 _kgspWaitForResetAccess =====

uint _kgspWaitForResetAccess(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x1103c4,0);
  if ((uVar2 & 1) == 0) {
    return 0;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1103c4,0);
  return uVar1 >> 4 & 1;
}


// ===== 00373810 kgspResetHw_GB100 =====

void kgspResetHw_GB100(long param_1,undefined8 param_2)

{
  int iVar1;
  undefined1 local_40 [32];
  
  timeoutSet(param_1 + 0x1af0,local_40,0,0x20);
  iVar1 = timeoutCondWait(param_1 + 0x1af0,local_40,_kgspWaitForResetAccess,0,0x53);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb100.c",0x56,"kgspResetHw_GB100",4,
                 "NVRM: Timed out waiting for GSP reset PLM to be lowered\n");
  }
  kgspResetHw_GH100(param_1,param_2);
  return;
}


// ===== 003738b0 kgspGetSignatureSectionNamePrefix_GB100 =====

char * kgspGetSignatureSectionNamePrefix_GB100(long param_1)

{
  char *pcVar1;
  
  pcVar1 = ".fwsignature_";
  if ((*(long *)(param_1 + 0x1d18) != 0) && (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) != '\0')
     ) {
    pcVar1 = ".fwsignature_cc_";
  }
  return pcVar1;
}


// ===== 003738e0 kgspGetGspRmBootUcodeStorage_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspGetGspRmBootUcodeStorage_GB100
               (long param_1,long param_2,undefined8 *param_3,undefined8 *param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if ((*(long *)(param_1 + 0x1d18) != 0) && (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) != '\0')
     ) {
    uVar3 = (**(code **)(param_2 + 0x850))(param_2);
    uVar2 = (**(code **)(param_2 + 0x858))(param_2);
    cVar1 = (**(code **)(param_2 + 0x800))(param_1);
    if (cVar1 == '\0') {
      uVar2 = bindataArchiveGetStorage(uVar2,0x26);
      *param_3 = uVar2;
      uVar3 = bindataArchiveGetStorage(uVar3,0x14);
    }
    else {
      uVar2 = bindataArchiveGetStorage(uVar2,0x24);
      *param_3 = uVar2;
      uVar3 = bindataArchiveGetStorage(uVar3,0x13);
    }
    *param_4 = uVar3;
    return;
  }
  kgspGetGspRmBootUcodeStorage_GA102();
  return;
}


// ===== 003739af kgspCheckGspPoisonError_GB100.cold =====

void kgspCheckGspPoisonError_GB100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003739c0 kgspCheckGspPoisonError_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspCheckGspPoisonError_GB100(long param_1,long param_2,uint param_3)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  uint local_c;
  
  local_c = 0;
  if ((param_3 & 0x1000000) != 0) {
    if (param_2 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    iVar3 = (**(code **)(*(long *)(param_2 + 2000) + 0x5f0))
                      (param_1,*(long *)(param_2 + 2000),&local_c);
    if (iVar3 == 0) {
      if ((local_c & 1) != 0) {
        cVar2 = (**(code **)(param_1 + 0x350))();
        if (cVar2 == '\0') {
          nvAssertFailedNoLog("GSP poison pending when poison is disabled",
                              "src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb100.c",199);
        }
        return 1;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb100.c",0xb7,
                   "kgspCheckGspPoisonError_GB100",4,
                   "NVRM: NV_PGSP_FALCON_IRQSTAT_FATAL_ERROR unknown error pending\n");
    }
  }
  return 0;
}


// ===== 00373a80 kgspServiceFatalHwError_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspServiceFatalHwError_GB100(long param_1,long param_2,uint param_3)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  long lVar8;
  uint local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar8 = 0;
  if (param_2 != 0) {
    lVar8 = *(long *)(param_2 + 2000);
  }
  lVar1 = *(long *)(param_1 + 0x1c18);
  local_54 = 0;
  if ((param_3 & 0x1000000) != 0) {
    *(undefined1 *)(param_2 + 0x69eff) = 1;
    iVar5 = (**(code **)(lVar8 + 0x5f0))(param_1,lVar8,&local_54);
    if (iVar5 == 0) {
      bVar7 = 0;
      uVar6 = local_54;
      if (local_54 != 0) {
        while( true ) {
          for (; (uVar6 & 1) == 0; uVar6 = uVar6 >> 1) {
            bVar7 = bVar7 + 1;
          }
          iVar5 = 1 << (bVar7 & 0x1f);
          uVar3 = (**(code **)(lVar8 + 0x5f8))(param_1,lVar8,iVar5,0);
          uVar4 = (**(code **)(lVar8 + 0x5f8))(param_1,lVar8,iVar5,1);
          nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb100.c",0xfb,
                       "kgspServiceFatalHwError_GB100",4,
                       "NVRM: NV_PGSP_FALCON_IRQSTAT_FATAL_ERROR %s pending (mask: 0x%x)\n",uVar4,
                       local_54);
          cVar2 = (**(code **)(param_2 + 0x8b8))(param_1,param_2,param_3);
          if (cVar2 == '\0') {
            nvErrorLog_va(param_1,0x5e,"GSP-RISCV instance 0 %s fatal error (mask: 0x%x)",uVar3,
                          local_54);
          }
          else {
            local_50 = 0;
            local_48 = 0;
            local_40 = 0;
            iVar5 = (**(code **)(param_1 + 0x3d0))(param_1,0x12,0,0x373b51);
            if (iVar5 != 0) {
              nvAssertOkFailedNoLog
                        (iVar5,
                         "gpuUpdateErrorContainmentState_HAL(pGpu, NV_ERROR_CONT_ERR_ID_E24_GSP_POISON, loc, NULL)"
                         ,"src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb100.c",0x108);
            }
          }
          if (uVar6 >> 1 == 0) break;
          bVar7 = bVar7 + 1;
          uVar6 = uVar6 >> 1;
        }
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb100.c",0xea,
                   "kgspServiceFatalHwError_GB100",4,
                   "NVRM: NV_PGSP_FALCON_IRQSTAT_FATAL_ERROR unknown error pending\n");
      nvErrorLog_va(param_1,0x5e,"GSP-RISCV instance 0 unknown fatal error");
    }
    if (lVar1 != 0) {
      krcRcAndNotifyAllChannels_IMPL(param_1,lVar1,0x5e,1);
    }
    iVar5 = (**(code **)(param_1 + 0x100))(param_1);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"gpuMarkDeviceForReset(pGpu)",
                 "src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb100.c",0x119);
    }
  }
  return;
}


// ===== 00373d20 kgspIsDebugModeEnabled_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kgspIsDebugModeEnabled_GB100(long param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (**(code **)(param_1 + 0x438))();
  uVar2 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x74c,0);
  return ~uVar2 & 1;
}


// ===== 00373d60 kgspReadUcodeFuseVersion_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgspReadUcodeFuseVersion_GB100(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if (0xf < param_3 - 1U) {
    return 0;
  }
  iVar1 = (**(code **)(param_1 + 0x438))();
  uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x41c0 + (param_3 - 1U) * 4,0);
  if ((uint)uVar3 != 0) {
    uVar2 = (uint)uVar3 >> 1;
    if (uVar2 == 0) {
      return 1;
    }
    iVar1 = 0x1f;
    if (uVar2 != 0) {
      for (; uVar2 >> iVar1 == 0; iVar1 = iVar1 + -1) {
      }
    }
    uVar3 = (ulong)(iVar1 + 2);
  }
  return uVar3;
}


// ===== 00373dd0 kgspIsWpr2Up_GB100 =====

undefined4 kgspIsWpr2Up_GB100(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x88a828,0);
  if ((*(long *)(param_1 + 0x1d18) != 0) && (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) != '\0')
     ) {
    return 0;
  }
  return CONCAT31((uint3)(uVar1 >> 0xc),uVar1 >> 4 != 0);
}


// ===== 00373e30 kgspPopulateWprMeta_GB10B =====

ulong kgspPopulateWprMeta_GB10B(undefined8 param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(param_2 + 0xa78);
  uVar2 = kgspPopulateWprMeta_GH100();
  if ((int)uVar2 == 0) {
    *(undefined8 *)(lVar1 + 0xc0) = 0;
    *(undefined4 *)(lVar1 + 0xf4) = 0;
    *(undefined8 *)(lVar1 + 0x68) = 0;
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,"kgspPopulateWprMeta_GH100(pGpu, pKernelGsp, pGspFw)",
             "src/kernel/gpu/gsp/arch/blackwell/kernel_gsp_gb10b.c",0x48);
  return uVar2 & 0xffffffff;
}


// ===== 00373ea0 kgspVgpuFwHeapSize_GB202 =====

undefined8 kgspVgpuFwHeapSize_GB202(long param_1)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x7f4) & 0xffff0000;
  sVar1 = (short)((uint)*(undefined4 *)(param_1 + 0x7fc) >> 0x10);
  if (uVar2 == 0x2bb50000) {
    uVar3 = 0x55a00000;
    if (sVar1 != 0x204e) {
      if (sVar1 != 0x220b) {
        uVar3 = 0x24500000;
      }
      return uVar3;
    }
  }
  else {
    uVar3 = 0x24500000;
    if (uVar2 == 0x2bb10000) {
      if (sVar1 == 0x204b) {
        uVar3 = 0x55a00000;
      }
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00373f20 kgspVgpuNumVgpuPartitions_GB202 =====

undefined8 kgspVgpuNumVgpuPartitions_GB202(long param_1)

{
  short sVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = *(uint *)(param_1 + 0x7f4) & 0xffff0000;
  sVar1 = (short)((uint)*(undefined4 *)(param_1 + 0x7fc) >> 0x10);
  if (uVar2 == 0x2bb50000) {
    uVar3 = 0x30;
    if (sVar1 != 0x204e) {
      if (sVar1 != 0x220b) {
        uVar3 = 0x20;
      }
      return uVar3;
    }
  }
  else {
    uVar3 = 0x20;
    if (uVar2 == 0x2bb10000) {
      if (sVar1 == 0x204b) {
        uVar3 = 0x30;
      }
      return uVar3;
    }
  }
  return uVar3;
}


// ===== 00373fa0 _kgspFalconMailbox0Cleared =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool _kgspFalconMailbox0Cleared(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x40);
  return iVar1 == 0;
}


// ===== 00373fc0 _kgspHasCcCleanupFinished =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _kgspHasCcCleanupFinished(undefined8 param_1,long param_2)

{
  undefined7 uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x44);
  uVar1 = (undefined7)((ulong)uVar2 >> 8);
  return (uint)CONCAT71(uVar1,(int)uVar2 == 0x59d35ede) |
         (uint)CONCAT71(uVar1,(int)uVar2 == 0x59d35efa);
}


// ===== 00373ff0 _kgspWaitForDeasserted =====

undefined4 _kgspWaitForDeasserted(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,__pfx_nv_dma_buf_map,0);
  return CONCAT31((int3)((uVar1 & 0x700) >> 8),(uVar1 & 0x700) == 0x200);
}


// ===== 00374020 _kgspWaitForAsserted =====

bool _kgspWaitForAsserted(long param_1)

{
  byte extraout_AH;
  
  regRead032(param_1 + 0x3a18,0,0,__pfx_nv_dma_buf_map,0);
  return (extraout_AH & 7) == 0;
}


// ===== 00374048 _kgspLockdownReleasedOrFmcError.cold =====

void _kgspLockdownReleasedOrFmcError_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00374060 _kgspLockdownReleasedOrFmcError =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _kgspLockdownReleasedOrFmcError(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 extraout_RDX;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  lVar1 = *(long *)(param_2 + 2000);
  iVar3 = (**(code **)(lVar1 + 0x4c0))(param_1,lVar1,0x40);
  if (((iVar3 != 0) &&
      (uVar6 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xab0),1,0), iVar3 == (int)uVar6)) &&
     (iVar5 = (**(code **)(lVar1 + 0x4c0))(param_1,lVar1,0x44), iVar5 == (int)((ulong)uVar6 >> 0x20)
     )) {
    return 0;
  }
  uVar4 = (**(code **)(lVar1 + 0x4c0))(param_1,lVar1,0xf4);
  return uVar4 >> 0xd & 1 ^ 1 | (uint)CONCAT71((int7)((ulong)extraout_RDX >> 8),iVar3 != 0);
}


// ===== 00374120 _kgspSpdmBootedOrFmcError =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool _kgspSpdmBootedOrFmcError(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(param_1 + 0x1ba8);
  iVar2 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x40);
  if (((iVar2 != 0) &&
      (uVar3 = memdescGetPhysAddr(*(undefined8 *)(lVar1 + 0xab0),1,0), iVar2 == (int)uVar3)) &&
     (iVar2 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x44),
     iVar2 == (int)((ulong)uVar3 >> 0x20))) {
    return false;
  }
  iVar2 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x40);
  return iVar2 != 0;
}


// ===== 003741d0 kgspGetSignatureSectionNamePrefix_GH100 =====

char * kgspGetSignatureSectionNamePrefix_GH100(long param_1)

{
  char *pcVar1;
  
  pcVar1 = ".fwsignature_";
  if ((*(long *)(param_1 + 0x1d18) != 0) && (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) != '\0')
     ) {
    pcVar1 = ".fwsignature_cc_";
  }
  return pcVar1;
}


// ===== 00374200 kgspResetHw_GH100 =====

int kgspResetHw_GH100(long param_1)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 local_40 [32];
  
  lVar1 = param_1 + 0x1af0;
  lVar2 = param_1 + 0x3a18;
  uVar3 = *(undefined4 *)(param_1 + 0x1b00);
  timeoutSet(lVar1,local_40,uVar3,0x20);
  uVar4 = regRead032(lVar2,0,0,__pfx_nv_dma_buf_map,0);
  regWrite032(lVar2,0,0,__pfx_nv_dma_buf_map,uVar4 | 1,0);
  iVar5 = timeoutCondWait(lVar1,local_40,_kgspWaitForAsserted,0,0x85);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x88,"kgspResetHw_GH100",4,
                 "NVRM: Timed out waiting for GSP falcon reset to assert\n");
  }
  timeoutSet(lVar1,local_40,uVar3,0x20);
  uVar4 = regRead032(lVar2,0,0,__pfx_nv_dma_buf_map,0);
  regWrite032(lVar2,0,0,__pfx_nv_dma_buf_map,uVar4 & 0xfffffffe,0);
  iVar5 = timeoutCondWait(lVar1,local_40,_kgspWaitForDeasserted,0,0x90);
  if (iVar5 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x93,"kgspResetHw_GH100",4,
               "NVRM: Timed out waiting for GSP falcon reset to deassert\n");
  return iVar5;
}


// ===== 00374370 kgspAllocBootArgs_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong kgspAllocBootArgs_GH100(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = 0;
  local_20 = 0;
  uVar1 = memdescCreate(param_2 + 0xab0,param_1,0x58,0x1000,1,1,0);
  if (uVar1 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0xab0) + 0x9c) = 0x59;
    uVar1 = memdescAlloc(*(undefined8 *)(param_2 + 0xab0));
    if (uVar1 == 0) {
      puVar3 = &local_20;
      uVar1 = memdescMap(*(long *)(param_2 + 0xab0),0,
                         *(undefined8 *)(*(long *)(param_2 + 0xab0) + 0x30),1,3,&local_28);
      if (uVar1 == 0) {
        *(undefined8 *)(param_2 + 0xab8) = local_28;
        *(undefined8 *)(param_2 + 0xac0) = local_20;
        uVar2 = kgspAllocBootArgs_TU102(param_1,param_2,puVar3,0x3743f1);
        return uVar2;
      }
      nvAssertOkFailedNoLog
                (uVar1,
                 "memdescMap(pKernelGsp->pGspFmcArgumentsDescriptor, 0, memdescGetSize(pKernelGsp->pGspFmcArgumentsDescriptor), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                 ,"src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0xb6);
    }
    else {
      nvAssertOkFailedNoLog
                (uVar1,"nvStatus","src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0xb2);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (uVar1,
               "memdescCreate(&pKernelGsp->pGspFmcArgumentsDescriptor, pGpu, sizeof(GSP_FMC_BOOT_PARAMS), 0x1000, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
               ,"src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0xa9,0x200000000000);
  }
  (**(code **)(param_2 + 0x810))(param_1,param_2,*(code **)(param_2 + 0x810));
  return (ulong)uVar1;
}


// ===== 00374500 kgspFreeBootArgs_GH100 =====

void kgspFreeBootArgs_GH100(undefined8 param_1,long param_2)

{
  kgspFreeBootArgs_TU102();
  if (*(long *)(param_2 + 0xab8) != 0) {
    memdescUnmap(*(undefined8 *)(param_2 + 0xab0),1,*(long *)(param_2 + 0xab8),
                 *(undefined8 *)(param_2 + 0xac0));
    *(undefined8 *)(param_2 + 0xab8) = 0;
    *(undefined8 *)(param_2 + 0xac0) = 0;
  }
  if (*(long *)(param_2 + 0xab0) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xab0));
    *(undefined8 *)(param_2 + 0xab0) = 0;
  }
  return;
}


// ===== 00374580 kgspIsWpr2Up_GH100 =====

undefined8 kgspIsWpr2Up_GH100(long param_1)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_1 + 0x1d18) != 0) && (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) != '\0')
     ) {
    return 0;
  }
  uVar1 = kgspIsWpr2Up_TU102();
  return uVar1;
}


// ===== 003745b0 kgspWaitForGfwBootOk_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspWaitForGfwBootOk_GH100(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x1d08) != 0) {
    uVar1 = (**(code **)(*(long *)(param_1 + 0x1d08) + 0x1c0))();
    return uVar1;
  }
  return 0;
}


// ===== 003745e0 kgspPopulateWprMeta_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspPopulateWprMeta_GH100(long param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined8 uVar7;
  long lVar8;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)","src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",
                        0x13a);
    return 0x56;
  }
  if (*(long *)(param_2 + 0xb18) == 0) {
    nvAssertFailedNoLog("pKernelGsp->pGspRmBootUcodeImage != NULL",
                        "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x13c);
  }
  else if (*(int *)(param_2 + 0xb10) == 0) {
    nvAssertFailedNoLog("pKernelGsp->gspRmBootUcodeSize != 0",
                        "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x13d);
  }
  else {
    lVar8 = *(long *)(param_2 + 0xb20);
    if (lVar8 != 0) {
      puVar1 = *(undefined8 **)(param_2 + 0xa78);
      puVar1[0x18] = 0x20000;
      uVar5 = kpmuReservedMemorySizeGet_IMPL(*(undefined8 *)(param_1 + 0x1c28));
      *(undefined4 *)((long)puVar1 + 0xf4) = uVar5;
      puVar1[5] = (ulong)*(uint *)(param_2 + 0xb10);
      uVar7 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xb00),1,0);
      puVar1[4] = uVar7;
      puVar1[3] = *(undefined8 *)(param_3 + 0x18);
      uVar7 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xb28),1,0);
      puVar1[2] = uVar7;
      puVar1[6] = (ulong)*(uint *)(lVar8 + 0x30);
      puVar1[7] = (ulong)*(uint *)(lVar8 + 0x28);
      puVar1[8] = (ulong)*(uint *)(lVar8 + 0x20);
      if (*(long *)(param_2 + 0xb30) != 0) {
        uVar7 = memdescGetPhysAddr(*(long *)(param_2 + 0xb30),1,0);
        puVar1[9] = uVar7;
        puVar1[10] = *(undefined8 *)(*(long *)(param_2 + 0xb30) + 0x30);
      }
      uVar6 = (**(code **)(param_2 + 0x880))(param_1,param_2);
      puVar1[0xd] = (ulong)uVar6;
      uVar7 = kgspGetFwHeapSize_IMPL(param_1,param_2,0,0);
      puVar1[0x10] = uVar7;
      uVar6 = (**(code **)(param_2 + 0x8e0))(param_1,param_2);
      puVar1[0x14] = (ulong)uVar6;
      uVar2 = 0;
      if (*(char *)(param_1 + 0x4a4e) != '\0') {
        uVar2 = (**(code **)(param_2 + 0x9b0))(param_1,param_2);
      }
      *(undefined1 *)(puVar1 + 0x1e) = uVar2;
      lVar8 = kcrashcatEngineGetQueueMemDesc_IMPL(*(undefined8 *)(param_2 + 0x7c8));
      if (lVar8 != 0) {
        uVar7 = memdescGetPhysAddr(lVar8,1,0);
        puVar1[0x1c] = uVar7;
        *(int *)(puVar1 + 0x1d) = (int)*(undefined8 *)(lVar8 + 0x30);
      }
      puVar1[1] = 1;
      *puVar1 = 0xdc3aae21371a60b3;
      cVar3 = gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL(param_1);
      bVar4 = *(byte *)((long)puVar1 + 0xf1) | 4;
      if (cVar3 == '\0') {
        bVar4 = *(byte *)((long)puVar1 + 0xf1) & 0xfb;
      }
      *(byte *)((long)puVar1 + 0xf1) = bVar4;
      return 0;
    }
    nvAssertFailedNoLog("pRiscvDesc != NULL","src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",
                        0x13e);
  }
  return 0x40;
}


// ===== 00374880 kgspSetupGspFmcArgs_GH100 =====

int kgspSetupGspFmcArgs_GH100(long param_1,long param_2,int param_3)

{
  uint *puVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)","src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",
                        0x1a9);
    return 0x56;
  }
  puVar1 = *(uint **)(param_2 + 0xab8);
  if (puVar1 == (uint *)0x0) {
    iVar3 = 0x40;
    nvAssertFailedNoLog("pKernelGsp->pGspFmcArgumentsCached != NULL",
                        "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x1aa);
  }
  else {
    lVar2 = *(long *)(param_1 + 0x1d18);
    if (lVar2 != 0) {
      uVar4 = *(uint *)(lVar2 + 0x2b4);
      puVar1[0x14] = 0;
      puVar1[0x15] = 0;
      *puVar1 = uVar4;
      if (*(char *)(lVar2 + 0x2b3) != '\0') {
        lVar2 = *(long *)(param_1 + 0x1b70);
        puVar1[0x14] = (uint)*(undefined8 *)(lVar2 + 0x468);
        puVar1[0x15] = *(uint *)(lVar2 + 0x46c);
      }
    }
    if (*(long *)(param_1 + 0x1ce8) != 0) {
      *puVar1 = *puVar1 | *(uint *)(*(long *)(param_1 + 0x1ce8) + 0x171c);
    }
    if (param_3 == 1) {
      uVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xaa0),1,0);
      puVar1[3] = 0x100;
      *(undefined8 *)(puVar1 + 4) = uVar5;
      lVar2 = *(long *)(param_2 + 0xaa0);
      iVar3 = memdescGetAddressSpace(lVar2);
      if (iVar3 == 1) {
        uVar4 = 2;
        if (*(int *)(lVar2 + 0x74) == 0) {
          uVar4 = 1;
        }
      }
      else {
        uVar4 = (uint)(iVar3 != 2) + (uint)(iVar3 != 2) * 2;
      }
    }
    else {
      uVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xa70),1,0);
      puVar1[3] = 0x100;
      *(undefined8 *)(puVar1 + 4) = uVar5;
      lVar2 = *(long *)(param_2 + 0xa70);
      iVar3 = memdescGetAddressSpace(lVar2);
      if (iVar3 == 1) {
        uVar4 = 1;
        if (*(int *)(lVar2 + 0x74) != 0) {
          uVar4 = 2;
        }
      }
      else {
        uVar4 = (uint)(iVar3 != 2) + (uint)(iVar3 != 2) * 2;
      }
    }
    puVar1[2] = uVar4;
    *(undefined1 *)(puVar1 + 9) = 1;
    uVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xac8),1,0);
    *(undefined8 *)(puVar1 + 0xc) = uVar5;
    lVar2 = *(long *)(param_2 + 0xac8);
    iVar3 = memdescGetAddressSpace(lVar2);
    if (iVar3 == 1) {
      uVar4 = 1;
      if (*(int *)(lVar2 + 0x74) != 0) {
        uVar4 = 2;
      }
    }
    else {
      uVar4 = (uint)(iVar3 != 2) + (uint)(iVar3 != 2) * 2;
    }
    puVar1[10] = uVar4;
    lVar2 = *(long *)(param_1 + 0x1d10);
    if ((lVar2 == 0) || (*(char *)(lVar2 + 0x218) == '\0')) {
      iVar3 = 0;
    }
    else {
      iVar3 = spdmSetupCommunicationBuffers_IMPL(param_1,lVar2);
      if (iVar3 == 0) {
        puVar1[0xe] = 1;
        uVar5 = memdescGetPhysAddr(*(undefined8 *)(lVar2 + 0x248),1,0);
        *(undefined8 *)(puVar1 + 0x10) = uVar5;
        puVar1[0x12] = *(uint *)(lVar2 + 0x250);
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x1e0,
                   "kgspSetupGspFmcArgs_GH100",4,
                   "NVRM: Failure when initializing SPDM messaging infrastructure. Status:0x%x\n",
                   iVar3);
    }
  }
  return iVar3;
}


// ===== 00374b90 kgspPrepareForBootstrap_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgspPrepareForBootstrap_GH100(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x326,
                 "kgspPrepareForBootstrap_GH100",4,"NVRM: IS_GSP_CLIENT is not set.\n");
    return 0x56;
  }
  lVar1 = *(long *)(param_1 + 0x1d08);
  lVar2 = *(long *)(param_1 + 0x1ba0);
  uVar3 = (**(code **)(param_2 + 0x9c0))();
  uVar5 = 0x32b;
  pcVar4 = "kgspSetupGspFmcArgs_HAL(pGpu, pKernelGsp, bootMode)";
  if ((int)uVar3 == 0) {
    if ((lVar1 == 0) || (*(char *)(lVar1 + 0x24d) != '\0')) {
      if ((lVar2 != 0) && (*(char *)(lVar2 + 0x909) != '\0')) {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x336,
                     "kgspPrepareForBootstrap_GH100",1,"NVRM: Sec2 preparing for GSPRM boot\n");
        *(undefined1 *)(lVar2 + 0x908) = 1;
        uVar3 = (**(code **)(lVar2 + 0x828))(param_1,lVar2);
        if ((int)uVar3 != 0) {
          uVar5 = 0x338;
          pcVar4 = "ksec2PrepareBootCommands_HAL(pGpu, pKernelSec2)";
          goto LAB_00374ca7;
        }
      }
    }
    else {
      *(undefined1 *)(lVar1 + 0x24a) = 1;
      uVar3 = (**(code **)(lVar1 + 0x1a8))
                        (param_1,lVar1,"kgspSetupGspFmcArgs_HAL(pGpu, pKernelGsp, bootMode)",
                         "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x32b);
      uVar5 = 0x331;
      pcVar4 = "kfspPrepareBootCommands_HAL(pGpu, pKernelFsp)";
      if ((int)uVar3 != 0) goto LAB_00374ca7;
    }
    return uVar3;
  }
LAB_00374ca7:
  nvCheckOkFailedNoLog
            (4,uVar3 & 0xffffffff,pcVar4,"src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",uVar5);
  return uVar3 & 0xffffffff;
}


// ===== 00374d00 kgspFmcResetErrorCode_GH100 =====

void kgspFmcResetErrorCode_GH100(long param_1)

{
  regWrite032(param_1 + 0x3a18,0,0,0x14dc,0,0);
  return;
}


// ===== 00374d20 kgspFmcCheckForErrorCode_GH100 =====

bool kgspFmcCheckForErrorCode_GH100(long param_1)

{
  int iVar1;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x14dc,0);
  return iVar1 != 0;
}


// ===== 00374d50 kgspFmcReportErrorCode_GH100 =====

ulong kgspFmcReportErrorCode_GH100(long param_1)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x14dc,0);
  if (((uint)uVar1 != 0) && (uVar2 = (uint)(uVar1 >> 0x18) & 0xf, uVar2 < 3)) {
    uVar3 = (uint)uVar1 >> 0x1c;
    if (uVar3 == 0) {
      uVar1 = nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x378,
                           "kgspFmcReportErrorCode_GH100",4,
                           "NVRM: Fatal GSP-FMC Error: SK error code =0x%x, phase 0x%x\n",
                           uVar1 >> 8 & 0xff,uVar1 & 0xff);
      return uVar1;
    }
    if (uVar3 == 1) {
      uVar1 = nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",900,
                           "kgspFmcReportErrorCode_GH100",4,
                           "NVRM: Fatal GSP-FMC Error: version=0x%x, partition=0x%x, error code=0x%x, additional info=0x%x\n"
                           ,1,uVar2 - 1 & 0xf,uVar1 & 0xffff,uVar1 >> 0x10 & 0xff);
      return uVar1;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x38c,
                 "kgspFmcReportErrorCode_GH100",4,
                 "NVRM: Fatal GSP-FMC Error: Unknown version (0x%x). Full error code: 0x%x\n");
  }
  return uVar1;
}


// ===== 00374e50 kgspBootstrap_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

int kgspBootstrap_GH100(long param_1,long param_2,int param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  ulong uVar9;
  long lVar10;
  char *pcVar11;
  undefined8 uVar12;
  bool bVar13;
  undefined8 local_58;
  
  lVar1 = *(long *)(param_1 + 0x1ba0);
  lVar2 = *(long *)(param_2 + 2000);
  lVar3 = *(long *)(param_1 + 0x1d08);
  (**(code **)(param_2 + 0x7e8))();
  *(undefined1 *)(lVar2 + 0x618) = 1;
  if ((lVar3 == 0) || (*(char *)(lVar3 + 0x24d) != '\0')) {
    if ((lVar1 == 0) || (*(char *)(lVar1 + 0x909) == '\0')) {
      lVar4 = *(long *)(param_2 + 2000);
      iVar7 = (**(code **)(param_2 + 0x890))(param_1,param_2);
      if (iVar7 != 0) {
        nvAssertOkFailedNoLog
                  (iVar7,"kgspResetHw_HAL(pGpu, pKernelGsp)",
                   "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x2d6);
        nvAssertOkFailedNoLog
                  (iVar7,"_kgspBootstrapGspFmc_GH100(pGpu, pKernelGsp)",
                   "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x3d4);
        return iVar7;
      }
      uVar9 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xab0),1,0);
      (**(code **)(lVar4 + 0x4c8))(param_1,lVar4,0x40,uVar9 & 0xffffffff,*(code **)(lVar4 + 0x4c8));
      (**(code **)(lVar4 + 0x4c8))(param_1,lVar4,0x44,uVar9 >> 0x20,*(code **)(lVar4 + 0x4c8));
      regWrite032(param_1 + 0x3a18,0,0,0x110804,*(undefined4 *)(*(long *)(param_1 + 0x1d18) + 0x2b4)
                  ,0);
      lVar5 = *(long *)(param_2 + 0xb20);
      lVar10 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xb00),1,0);
      uVar9 = (ulong)*(uint *)(lVar5 + 0x30) + lVar10;
      (**(code **)(lVar4 + 0x4d8))(param_1,lVar4,0x678,uVar9 >> 8,uVar9,*(code **)(lVar4 + 0x4d8));
      (**(code **)(lVar4 + 0x4d8))
                (param_1,lVar4,0x67c,uVar9 >> 0x28,uVar9 >> 0x28,*(code **)(lVar4 + 0x4d8));
      uVar9 = (ulong)*(uint *)(lVar5 + 0x28) + lVar10;
      (**(code **)(lVar4 + 0x4d8))(param_1,lVar4,0x680,uVar9 >> 8,uVar9,*(code **)(lVar4 + 0x4d8));
      (**(code **)(lVar4 + 0x4d8))
                (param_1,lVar4,0x684,uVar9 >> 0x28,uVar9 >> 0x28,*(code **)(lVar4 + 0x4d8));
      uVar9 = lVar10 + (ulong)*(uint *)(lVar5 + 0x20);
      (**(code **)(lVar4 + 0x4d8))(param_1,lVar4,0x670,uVar9 >> 8,*(code **)(lVar4 + 0x4d8));
      (**(code **)(lVar4 + 0x4d8))(param_1,lVar4,0x674,uVar9 >> 0x28,*(code **)(lVar4 + 0x4d8));
      (**(code **)(lVar4 + 0x4d8))(param_1,lVar4,0x66c,0x80000001);
      (**(code **)(lVar4 + 0x4f8))(param_1,lVar4,1);
      (**(code **)(lVar4 + 0x4d8))(param_1,lVar4,0x388,1);
      if (lVar3 != 0) goto LAB_003750cf;
      if (lVar1 != 0) goto LAB_0037534a;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x3cf,"kgspBootstrap_GH100",1
                   ,"NVRM: Starting to boot GSP via SEC2.\n");
      iVar7 = (**(code **)(lVar1 + 0x838))(param_1);
      if (iVar7 != 0) {
        uVar12 = 0x3d0;
        pcVar11 = "ksec2SendBootCommands_HAL(pGpu, pKernelSec2)";
        goto LAB_003752de;
      }
      if (lVar3 != 0) goto LAB_003750cf;
LAB_0037534a:
      if (((*(char *)(lVar1 + 0x909) != '\0') && (*(char *)(lVar1 + 0x908) != '\0')) &&
         (iVar7 = (**(code **)(lVar1 + 0x870))(param_1), iVar7 != 0)) {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x3f1,"kgspBootstrap_GH100"
                     ,4,
                     "NVRM: SEC2 GSP Boot:Timeout waiting for GSP target mask release. This error may be caused by several reasons: Bootrom may have failed, GSP init code may have failed or ACR failed to release target mask. RM does not have access to information on which of those conditions happened.\n"
                    );
        (**(code **)(param_2 + 0x7f8))(param_1,param_2);
        return iVar7;
      }
    }
  }
  else {
    if (param_3 != 0) {
      *(undefined8 *)(*(long *)(lVar3 + 0x270) + 0x18) = 0;
      *(undefined4 *)(*(long *)(lVar3 + 0x270) + 0x20) = 0;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x3ca,"kgspBootstrap_GH100",2,
                 "NVRM: Starting to boot GSP via FSP.\n");
    iVar7 = (**(code **)(lVar3 + 0x1b0))(param_1,lVar3);
    uVar12 = 0x3cb;
    pcVar11 = "kfspSendBootCommands_HAL(pGpu, pKernelFsp)";
    if (iVar7 != 0) {
LAB_003752de:
      nvCheckOkFailedNoLog
                (4,iVar7,pcVar11,"src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",uVar12);
      return iVar7;
    }
LAB_003750cf:
    iVar7 = (**(code **)(lVar3 + 0x218))(param_1,lVar3);
    if (iVar7 != 0) {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x3dd,"kgspBootstrap_GH100",4
                   ,
                   "NVRM: Timeout waiting for GSP target mask release. This error may be caused by several reasons: Bootrom may have failed, GSP init code may have failed or ACR failed to release target mask. RM does not have access to information on which of those conditions happened.\n"
                  );
      (**(code **)(param_2 + 0x7f8))(param_1,param_2);
      if (*(char *)(lVar3 + 0x24a) == '\0') {
        return iVar7;
      }
      (**(code **)(lVar3 + 0x200))(param_1,lVar3);
      return iVar7;
    }
  }
  if ((*(long *)(param_1 + 0x1d10) == 0) || (*(char *)(*(long *)(param_1 + 0x1d10) + 0x218) == '\0')
     ) {
LAB_00375102:
    if ((param_3 == 0) && (iVar7 = kgspSendInitRpcs_IMPL(param_1,param_2), iVar7 != 0)) {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x413,"kgspBootstrap_GH100",4
                   ,"NVRM: kgspSendInitRpcs failed 0x%x!\n",iVar7);
    }
    else {
      iVar7 = timeoutCondWait(param_1 + 0x1af0,0,_kgspLockdownReleasedOrFmcError,param_2,0x41a);
      if (iVar7 == 0) {
        cVar6 = (**(code **)(param_2 + 0x7f0))(param_1,param_2);
        if (cVar6 == '\x01') {
          (**(code **)(param_2 + 0x7f8))(param_1,param_2);
        }
        else {
          iVar7 = (**(code **)(lVar2 + 0x4c0))(param_1,lVar2,0x40);
          if (iVar7 == 0) {
            (**(code **)(lVar2 + 0x4c8))
                      (param_1,lVar2,0x80,*(undefined4 *)(*(long *)(param_2 + 0xb20) + 0x1c));
            cVar6 = (**(code **)(lVar2 + 0x4e8))(param_1,lVar2);
            if (cVar6 != '\0') {
              nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x43f,
                           "kgspBootstrap_GH100",1,"NVRM: GSP ucode loaded and RISCV started.\n");
              nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x448,
                           "kgspBootstrap_GH100",1,"NVRM: Waiting for GSP fw RM to be ready...\n");
              if ((param_3 == 0) &&
                 (iVar7 = GspStatusQueueInit(param_1,*(long *)(param_2 + 0xa38) + 0x510), iVar7 != 0
                 )) {
                nvAssertOkFailedNoLog
                          (iVar7,"GspStatusQueueInit(pGpu, &pKernelGsp->pRpc->pMessageQueueInfo)",
                           "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x450);
                return iVar7;
              }
              iVar7 = kgspWaitForRmInitDone_IMPL(param_1,param_2);
              if (iVar7 == 0) {
                nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x455,
                             "kgspBootstrap_GH100",1,"NVRM: GSP FW RM ready.\n");
                return 0;
              }
              nvAssertOkFailedNoLog
                        (iVar7,"kgspWaitForRmInitDone(pGpu, pKernelGsp)",
                         "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x453);
              return iVar7;
            }
            nvAssertFailedNoLog("Failed to boot GSP",
                                "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x443);
            (**(code **)(param_2 + 0x7f8))(param_1,param_2);
          }
          else {
            nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x433,
                         "kgspBootstrap_GH100",4,
                         "NVRM: GSP-FMC reported an error while attempting to boot GSP: 0x%x\n",
                         iVar7);
          }
        }
        iVar7 = 0x55;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x41d,"kgspBootstrap_GH100"
                     ,4,
                     "NVRM: Timeout waiting for lockdown release. It\'s also possible that bootrom may have failed. RM may not have access to the BR status to be able to say for sure what failed.\n"
                    );
        (**(code **)(param_2 + 0x7f8))(param_1,param_2);
        if ((lVar3 != 0) && (*(char *)(lVar3 + 0x24a) != '\0')) {
          (**(code **)(lVar3 + 0x200))(param_1,lVar3);
        }
        uVar8 = (**(code **)(lVar2 + 0x4c0))(param_1,lVar2,0x40);
        nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x426,"kgspBootstrap_GH100"
                     ,4,"NVRM: NV_PGSP_FALCON_MAILBOX0 = 0x%x\n",uVar8);
        uVar8 = (**(code **)(lVar2 + 0x4c0))(param_1,lVar2,0x44);
        nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x428,"kgspBootstrap_GH100"
                     ,4,"NVRM: NV_PGSP_FALCON_MAILBOX1 = 0x%x\n",uVar8);
      }
    }
  }
  else {
    cVar6 = rmapiLockIsOwner();
    if (cVar6 == '\0') {
      nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",
                          0x404);
      return 0x2f;
    }
    uVar12 = *(undefined8 *)(param_1 + 0x1d10);
    lVar1 = *(long *)(param_2 + 2000);
    lVar4 = *(long *)(param_1 + 0x1d18);
    bVar13 = *(char *)(lVar4 + 0x2a8) != '\0';
    if (bVar13) {
      local_58 = 2;
    }
    else {
      local_58 = 0;
    }
    iVar7 = timeoutCondWait(param_1 + 0x1af0,0,_kgspSpdmBootedOrFmcError,lVar1,0x26c);
    if (iVar7 == 0) {
      iVar7 = (**(code **)(lVar1 + 0x4c0))(param_1,lVar1,0x40);
      if (iVar7 == 0x59d3b007) {
        iVar7 = spdmEstablishSession_IMPL(param_1,uVar12,local_58);
        if (iVar7 == 0) {
          if ((bVar13) && (iVar7 = (**(code **)(lVar4 + 600))(param_1), iVar7 != 0)) {
            nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x289,
                         "_kgspEstablishSpdmSession",4,"NVRM: CC key derivation failed.\n");
          }
          else {
            (**(code **)(lVar1 + 0x4c8))(param_1,lVar1,0x40,0x59d35ded);
            iVar7 = timeoutCondWait(param_1 + 0x1af0,0,_kgspFalconMailbox0Cleared,lVar1,0x296);
            if (iVar7 == 0) goto LAB_00375102;
            nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x299,
                         "_kgspEstablishSpdmSession",4,
                         "NVRM: Timeout waiting for SPDM to proceed with boot!\n");
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,iVar7,"spdmEstablishSession(pGpu, pSpdm, requesterId)",
                     "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x280);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x27a,
                     "_kgspEstablishSpdmSession",4,
                     "NVRM: GSP-FMC reported an error prior to SPDM boot: 0x%x\n",iVar7);
        iVar7 = 0x55;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x26f,
                   "_kgspEstablishSpdmSession",4,
                   "NVRM: Timeout waiting for SPDM Responder to initialize!\n");
    }
    lVar2 = *(long *)(param_1 + 0x1d08);
    if (lVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x2a4,
                   "_kgspEstablishSpdmSession",4,
                   "NVRM: Failed to establish session with SPDM Responder!\n");
      if (*(char *)(lVar2 + 0x24a) != '\0') {
        (**(code **)(lVar2 + 0x200))(param_1,lVar2);
      }
      uVar8 = (**(code **)(lVar1 + 0x4c0))(param_1,lVar1,0x40);
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x2a9,
                   "_kgspEstablishSpdmSession",4,"NVRM: NV_PGSP_FALCON_MAILBOX0 = 0x%x\n",uVar8);
      uVar8 = (**(code **)(lVar1 + 0x4c0))(param_1,lVar1,0x44);
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x2ab,
                   "_kgspEstablishSpdmSession",4,"NVRM: NV_PGSP_FALCON_MAILBOX1 = 0x%x\n",uVar8);
    }
    nvAssertOkFailedNoLog
              (iVar7,"_kgspEstablishSpdmSession(pGpu, pKernelGsp)",
               "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x405);
  }
  return iVar7;
}


// ===== 00375a4f kgspTeardown_GH100.cold =====

void kgspTeardown_GH100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00375a60 kgspTeardown_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspTeardown_GH100(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  if (param_2 != 0) {
    (**(code **)(*(long *)(param_2 + 2000) + 0x540))(param_1,*(long *)(param_2 + 2000),0,0);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00375a90 kgspGetGspRmBootUcodeStorage_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspGetGspRmBootUcodeStorage_GH100
               (long param_1,long param_2,undefined8 *param_3,undefined8 *param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if ((*(long *)(param_1 + 0x1d18) != 0) && (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a9) != '\0')
     ) {
    uVar3 = (**(code **)(param_2 + 0x850))(param_2);
    uVar2 = (**(code **)(param_2 + 0x858))(param_2);
    cVar1 = (**(code **)(param_2 + 0x800))(param_1);
    if (cVar1 == '\0') {
      uVar2 = bindataArchiveGetStorage(uVar2,0x26);
      *param_3 = uVar2;
      uVar3 = bindataArchiveGetStorage(uVar3,0x14);
    }
    else {
      uVar2 = bindataArchiveGetStorage(uVar2,0x24);
      *param_3 = uVar2;
      uVar3 = bindataArchiveGetStorage(uVar3,0x13);
    }
    *param_4 = uVar3;
    return;
  }
  kgspGetGspRmBootUcodeStorage_GA102();
  return;
}


// ===== 00375b60 kgspIssueNotifyOp_GH100 =====

int kgspIssueNotifyOp_GH100(long param_1,long param_2,uint param_3,int *param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  bool bVar5;
  int *in_stack_ffffffffffffffa8;
  undefined1 local_40 [24];
  
  if (param_3 < 3) {
    if (param_5 < 2) {
      if ((param_4 != (int *)0x0) || ((param_5 & 1) == 0)) {
        piVar2 = *(int **)(param_2 + 0x69f30);
        if (piVar2 == (int *)0x0) {
          nvAssertFailedNoLog("pKernelGsp->pNotifyOpSurf != NULL",
                              "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4ae);
LAB_00375d78:
          iVar4 = 0x40;
        }
        else {
          LOCK();
          bVar5 = *piVar2 == 0;
          if (bVar5) {
            *piVar2 = 1;
          }
          UNLOCK();
          while (!bVar5) {
            cVar3 = portSyncExSafeToSleep();
            if (cVar3 == '\0') {
              nvAssertFailedNoLog("portSyncExSafeToSleep()",
                                  "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4bc);
              goto LAB_00375d78;
            }
            osSpinLoop();
            LOCK();
            bVar5 = *piVar2 == 0;
            if (bVar5) {
              *piVar2 = 1;
            }
            UNLOCK();
            in_stack_ffffffffffffffa8 = param_4;
          }
          iVar1 = piVar2[1];
          piVar2[2] = param_3;
          piVar2[4] = param_5;
          if (param_5 != 0) {
            piVar2[5] = *param_4;
          }
          LOCK();
          UNLOCK();
          timeoutSet(param_1 + 0x1af0,local_40,0,0);
          regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2200,2,0,
                      in_stack_ffffffffffffffa8);
          iVar4 = piVar2[1];
          while (iVar4 != iVar1 + 1) {
            iVar4 = timeoutCheck(param_1 + 0x1af0,local_40,0x4d8);
            if (iVar4 != 0) {
              nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4dc,
                           "kgspIssueNotifyOp_GH100",4,
                           "NVRM: gpuCheckTimeout failed, status = 0x%x\n",iVar4);
              LOCK();
              *piVar2 = 0;
              UNLOCK();
              goto LAB_00375c84;
            }
            osSpinLoop();
            iVar4 = piVar2[1];
          }
          iVar4 = piVar2[3];
          LOCK();
          *piVar2 = 0;
          UNLOCK();
          if (iVar4 == 0) {
            return 0;
          }
LAB_00375c84:
          nvCheckOkFailedNoLog
                    (4,iVar4,"status","src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4e7);
        }
        return iVar4;
      }
      nvCheckFailedNoLog(4,"(argc == 0 || pArgs != NULL)",
                         "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4ab);
    }
    else {
      nvCheckFailedNoLog(4,"argc <= GSP_NOTIFY_OP_MAX_ARGUMENT_COUNT",
                         "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4aa);
    }
  }
  else {
    nvCheckFailedNoLog(4,"opCode < GSP_NOTIFY_OP_OPCODE_MAX",
                       "src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4a9);
  }
  return 0x1f;
}


// ===== 00375df0 kgspCheckGspRmCcCleanup_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspCheckGspRmCcCleanup_GH100(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = 0;
  if (param_2 != 0) {
    lVar3 = *(long *)(param_2 + 2000);
  }
  iVar1 = timeoutCondWait(param_1 + 0x1af0,0,_kgspHasCcCleanupFinished,lVar3,0x4f7);
  if (iVar1 == 0) {
    iVar2 = (**(code **)(lVar3 + 0x4c0))(param_1,lVar3,0x44);
    if (iVar2 == 0x59d35ede) {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x503,
                   "kgspCheckGspRmCcCleanup_GH100",4,"NVRM: CC secret cleanup successful!\n");
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x507,
                   "kgspCheckGspRmCcCleanup_GH100",4,"NVRM: CC secret cleanup failed! Status 0x%x\n"
                   ,iVar2);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/hopper/kernel_gsp_gh100.c",0x4fa,
                 "kgspCheckGspRmCcCleanup_GH100",4,
                 "NVRM: CC secret cleanup failed due to timeout!\n");
  }
  (**(code **)(lVar3 + 0x4c8))(param_1,lVar3,0x44,0x59d35eac);
  return iVar1;
}


// ===== 00375f10 s_executeBooterUcode_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int s_executeBooterUcode_TU102
              (undefined8 param_1,long param_2,long param_3,long param_4,int param_5,
              undefined4 param_6)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  int local_40;
  undefined4 local_3c [3];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pBooterUcode != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x2f);
    return 0x1f;
  }
  if (param_4 != 0) {
    local_40 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x40);
    uVar2 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x44);
    local_3c[0] = (undefined4)uVar2;
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x35,
                 "s_executeBooterUcode_TU102",1,
                 "NVRM: before Booter mailbox0 0x%08x, mailbox1 0x%08x\n",local_40,uVar2);
    uVar2 = CONCAT44((int)((ulong)uVar2 >> 0x20),param_6);
    local_40 = param_5;
    local_3c[0] = param_6;
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x3a,
                 "s_executeBooterUcode_TU102",1,
                 "NVRM: starting Booter with mailbox0 0x%08x, mailbox1 0x%08x\n",param_5,uVar2);
    uVar3 = (undefined4)((ulong)uVar2 >> 0x20);
    iVar1 = (**(code **)(param_2 + 0x930))(param_1,param_2,param_3,param_4,&local_40,local_3c);
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x40,
                 "s_executeBooterUcode_TU102",1,
                 "NVRM: after Booter mailbox0 0x%08x, mailbox1 0x%08x\n",local_40,
                 CONCAT44(uVar3,local_3c[0]));
    if (iVar1 == 0) {
      iVar1 = 0;
      if (local_40 != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x4a,
                     "s_executeBooterUcode_TU102",4,
                     "NVRM: Booter failed with non-zero error code: 0x%x\n",local_40);
        iVar1 = 0xffff;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x44,
                   "s_executeBooterUcode_TU102",4,
                   "NVRM: failed to execute Booter: status 0x%x, mailbox 0x%x\n",iVar1,local_40);
    }
    return iVar1;
  }
  nvAssertFailedNoLog("pKernelFlcn != NULL",
                      "src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x30);
  return 0x40;
}


// ===== 00376120 kgspExecuteBooterLoad_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspExecuteBooterLoad_TU102(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (*(long *)(param_2 + 0xa60) == 0) {
    nvAssertFailedNoLog("pKernelGsp->pBooterLoadUcode != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x5e);
    return 0x40;
  }
  lVar1 = *(long *)(param_1 + 0x1ba0);
  if (param_3 == 0) {
    uVar4 = 0;
    uVar5 = 0;
  }
  else {
    uVar5 = param_3 & 0xffffffff;
    uVar4 = param_3 >> 0x20;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x6a,
               "kgspExecuteBooterLoad_TU102",1,
               "NVRM: executing Booter Load, sysmemAddrOfData 0x%llx\n",param_3);
  if (lVar1 != 0) {
    iVar3 = (**(code **)(*(long *)(lVar1 + 2000) + 0x508))(param_1);
    if (iVar3 == 0) {
      iVar3 = s_executeBooterUcode_TU102
                        (param_1,param_2,*(undefined8 *)(param_2 + 0xa60),
                         *(undefined8 *)(lVar1 + 2000),uVar5,uVar4);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x75,
                     "kgspExecuteBooterLoad_TU102",4,"NVRM: failed to execute Booter Load: 0x%x\n");
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar3,"kflcnReset_HAL(pGpu, staticCast(pKernelSec2, KernelFalcon))",
                 "src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x6d);
    }
    return iVar3;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 0037629e kgspExecuteBooterUnloadIfNeeded_TU102.cold =====

void kgspExecuteBooterUnloadIfNeeded_TU102_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003762b0 kgspExecuteBooterUnloadIfNeeded_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspExecuteBooterUnloadIfNeeded_TU102(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  
  uVar4 = 0xff;
  if (*(int *)(param_1 + 0x4b34) == 1) {
    uVar4 = 0xdeaddead;
  }
  if ((((*(char *)(param_1 + 0x44f) == '\0') && (*(char *)(param_1 + 0x450) == '\0')) &&
      (*(char *)(param_1 + 0x451) == '\0')) && (*(char *)(param_1 + 0x461) == '\0')) {
    lVar1 = *(long *)(param_1 + 0x1ba0);
    cVar3 = (**(code **)(param_2 + 0x8d8))();
    if (cVar3 == '\0') {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x93,
                   "kgspExecuteBooterUnloadIfNeeded_TU102",1,
                   "NVRM: skipping executing Booter Unload as WPR2 is not up\n");
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x97,
                 "kgspExecuteBooterUnloadIfNeeded_TU102",1,"NVRM: executing Booter Unload\n");
    if (*(long *)(param_2 + 0xa68) == 0) {
      iVar5 = 0x40;
      nvAssertFailedNoLog("pKernelGsp->pBooterUnloadUcode != NULL",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x98);
    }
    else {
      if (lVar1 == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      iVar5 = (**(code **)(*(long *)(lVar1 + 2000) + 0x508))(param_1);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,"kflcnReset_HAL(pGpu, staticCast(pKernelSec2, KernelFalcon))",
                   "src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0x9a);
      }
      uVar7 = (ulong)uVar4;
      if (param_3 != 0) {
        uVar7 = param_3 & 0xffffffff;
      }
      uVar6 = param_3 >> 0x20;
      if (param_3 == 0) {
        uVar6 = (ulong)uVar4;
      }
      iVar5 = s_executeBooterUcode_TU102
                        (param_1,param_2,*(undefined8 *)(param_2 + 0xa68),
                         *(undefined8 *)(lVar1 + 2000),uVar7,uVar6);
      if (iVar5 == 0) {
        if (*(int *)(param_1 + 0x4b34) == 1) {
          cVar3 = (**(code **)(param_2 + 0x8d8))(param_1,param_2);
          if (cVar3 != '\0') {
            return 0;
          }
          nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0xb1,
                       "kgspExecuteBooterUnloadIfNeeded_TU102",4,
                       "NVRM: failed to execute Booter Unload: WPR2 is cleared despite GC6\n");
        }
        else {
          cVar3 = (**(code **)(param_2 + 0x8d8))(param_1,param_2);
          if (cVar3 == '\0') {
            return 0;
          }
          nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0xba,
                       "kgspExecuteBooterUnloadIfNeeded_TU102",4,
                       "NVRM: failed to execute Booter Unload: WPR2 is still up\n");
        }
        iVar5 = 0xffff;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_booter_tu102.c",0xa8,
                     "kgspExecuteBooterUnloadIfNeeded_TU102",4,
                     "NVRM: failed to execute Booter Unload: 0x%x\n",iVar5);
      }
    }
  }
  else {
    iVar5 = 0x10;
  }
  return iVar5;
}


// ===== 00376590 _kgspIsReloadCompleted =====

uint _kgspIsReloadCompleted(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x1180f8,0);
  return uVar1 >> 0x1a & 1;
}


// ===== 003765c0 s_imemCopyTo_TU102.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

uint s_imemCopyTo_TU102_part_0
               (undefined8 param_1,long param_2,undefined8 param_3,long param_4,uint param_5,
               int param_6,uint param_7)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  if (param_4 == 0) {
    nvAssertFailedNoLog("pSrc != NULL","src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",
                        0x80);
  }
  else {
    if ((param_5 & 3) == 0) {
      uVar2 = (**(code **)(param_2 + 0x560))();
      (**(code **)(param_2 + 0x4c8))
                (param_1,param_2,0x180,uVar2 & 0xefffffff | param_6 << 0x1c | 0x1000000);
      uVar3 = 0;
      param_7 = param_7 >> 8;
      do {
        if ((uVar3 & 0x3f) == 0) {
          uVar2 = param_7 & 0xffff;
          param_7 = param_7 + 1;
          (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x188,uVar2,*(code **)(param_2 + 0x4c8));
        }
        lVar1 = uVar3 * 4;
        uVar3 = uVar3 + 1;
        (**(code **)(param_2 + 0x4c8))
                  (param_1,param_2,0x184,*(undefined4 *)(param_4 + lVar1),
                   *(code **)(param_2 + 0x4c8));
      } while (param_5 >> 2 != uVar3);
      return param_5 & 3;
    }
    nvAssertFailedNoLog("RM_IS_ALIGNED(sizeBytes, FLCN_IMEM_ACCESS_ALIGNMENT)",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x81);
  }
  return 0x1f;
}


// ===== 00376700 s_setupLoader =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int s_setupLoader(long param_1,long param_2,undefined4 *param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  long lVar3;
  uint3 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  char *pcVar10;
  int *local_48;
  undefined8 local_40 [2];
  
  lVar3 = *(long *)(param_1 + 0x1ba0);
  local_48 = (int *)0x0;
  local_40[0] = 0;
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pBlDesc != NULL","src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c"
                        ,0x117);
    return 0x1f;
  }
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pKernelSec2 != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x118);
    return 0x40;
  }
  iVar5 = (**(code **)(lVar3 + 0x810))(param_1,lVar3,&local_48,local_40);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"ksec2GetGenericBlUcode_HAL(pGpu, pKernelSec2, &pBlUcDesc, &pBlImg)",
               "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x11b);
    return iVar5;
  }
  iVar5 = local_48[3];
  (**(code **)(param_2 + 0x520))(param_1,param_2);
  if (param_4 == 2) {
    uVar7 = 0;
  }
  else if (((param_5 != 0) || (uVar7 = 1, param_4 != 1)) &&
          ((param_5 != 1 || (uVar7 = 2, param_4 != 1)))) {
    nvAssertFailedNoLog("Unsupported address space/cache attribute combination",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0xf7);
    uVar9 = 0x121;
    pcVar10 = "s_setupLoaderAperture(pGpu, pKernelFlcn, pBlDesc->ctxDma, addrSpace, cpuCacheAttrib)"
    ;
    goto LAB_0037694f;
  }
  iVar8 = param_3[8];
  uVar6 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + iVar8 * 4,0);
  uVar4 = (uint3)((uint)(iVar5 + 0xff) >> 8);
  puVar1 = param_3 + 0x15;
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + iVar8 * 4,
              uVar7 | uVar6 & 0xfffffffc | 4,0);
  uVar7 = (**(code **)(param_2 + 0x568))(param_1,param_2,0);
  (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x1c0,uVar7 | 0x1000000);
  do {
    uVar2 = *param_3;
    param_3 = param_3 + 1;
    (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x1c4,uVar2);
  } while (param_3 != puVar1);
  uVar7 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x108);
  iVar5 = *local_48;
  if ((uVar4 == 0) ||
     (iVar8 = s_imemCopyTo_TU102_part_0
                        (param_1,param_2,((uVar7 & 0x1ff) - (uint)uVar4) * 0x100,local_40[0],
                         (uint)uVar4 << 8,0,iVar5 << 8), iVar8 == 0)) {
    (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x104,iVar5 << 8);
    return 0;
  }
  uVar9 = 0x133;
  pcVar10 = 
  "s_imemCopyTo_TU102(pGpu, pKernelFlcn, imemDstBlk << FALCON_IMEM_BLKSIZE2, pBlImg, blSize, NV_FALSE, virtAddr)"
  ;
LAB_0037694f:
  nvAssertOkFailedNoLog
            (0x1f,pcVar10,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",uVar9);
  return 0x1f;
}


// ===== 00376a30 kgspExecuteHsFalcon_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong kgspExecuteHsFalcon_TU102
                (undefined8 param_1,undefined8 param_2,int *param_3,long param_4,undefined4 *param_5
                ,undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  long lVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 uVar10;
  char *pcVar11;
  undefined1 local_98 [16];
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_74;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  undefined4 local_5c;
  undefined8 local_58;
  int local_50;
  
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("pFlcnUcode != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x18a);
    return 0x1f;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("pKernelFlcn != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x18b);
    return 0x40;
  }
  if (*(char *)(param_4 + 0x628) != '\0') {
    nvAssertFailedNoLog("!pKernelFlcn->bBootFromHs",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x18d);
    return 0x56;
  }
  if (*param_3 == 1) {
    if (*(long *)(param_3 + 2) == 0) {
      uVar10 = 0x14d;
      pcVar11 = "pUcode->pCodeMemDesc != NULL";
LAB_00376f43:
      nvAssertFailedNoLog(pcVar11,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",uVar10)
      ;
      return 0x1f;
    }
    if (*(long *)(param_3 + 4) == 0) {
      uVar10 = 0x14e;
      pcVar11 = "pUcode->pDataMemDesc != NULL";
      goto LAB_00376f43;
    }
    uVar10 = memdescGetPhysAddr(*(long *)(param_3 + 2),1,0);
    uVar8 = memdescGetPhysAddr(*(undefined8 *)(param_3 + 4),1,0);
    portMemSet(local_98,0,0x54);
    local_6c = param_3[9];
    local_88 = 0;
    local_68 = param_3[8];
    local_64 = param_3[0xb];
    local_80 = 0;
    local_60 = param_3[10];
    local_78 = 4;
    local_5c = 0;
    local_50 = param_3[0xe];
    local_74 = uVar10;
    local_58 = uVar8;
    uVar4 = s_setupLoader(param_1,param_4,local_98,1,0);
    if (uVar4 != 0) {
      nvAssertOkFailedNoLog
                (uVar4,
                 "s_setupLoader(pGpu, pKernelFlcn, &blDmemDesc, ADDR_SYSMEM, NV_MEMORY_CACHED)",
                 "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x168);
      return (ulong)uVar4;
    }
    goto LAB_00376c30;
  }
  if (*param_3 != 0) {
    return 0x56;
  }
  uVar10 = 0xa9;
  pcVar11 = "pUcode->pImage != NULL";
  if (*(long *)(param_3 + 2) == 0) goto LAB_00376f43;
  (**(code **)(param_4 + 0x520))(param_1,param_4);
  lVar5 = *(long *)(param_3 + 2);
  iVar1 = 0;
  if (param_3[6] != 0) {
    iVar1 = s_imemCopyTo_TU102_part_0
                      (param_1,param_4,0,(ulong)(uint)param_3[7] + lVar5,param_3[6],0,
                       (ulong)(uint)param_3[7]);
    if (iVar1 != 0) {
      uVar10 = 0xae;
      pcVar11 = 
      "s_imemCopyTo_TU102(pGpu, pKernelFlcn, 0, pUcode->pImage + pUcode->imemNsPa, pUcode->imemNsSize, NV_FALSE, pUcode->imemNsPa)"
      ;
      goto LAB_00376f73;
    }
    lVar5 = *(long *)(param_3 + 2);
    iVar1 = param_3[6];
  }
  if (param_3[8] != 0) {
    iVar1 = s_imemCopyTo_TU102_part_0
                      (param_1,param_4,(ulong)(uint3)((uint)(iVar1 + 0xff) >> 8) << 8,
                       (ulong)(uint)param_3[9] + lVar5,param_3[8],1,(ulong)(uint)param_3[9]);
    if (iVar1 != 0) {
      uVar10 = 0xb7;
      pcVar11 = 
      "s_imemCopyTo_TU102(pGpu, pKernelFlcn, NV_ALIGN_UP(pUcode->imemNsSize, FLCN_BLK_ALIGNMENT), pUcode->pImage + pUcode->imemSecPa, pUcode->imemSecSize, NV_TRUE, pUcode->imemSecPa)"
      ;
      goto LAB_00376f73;
    }
    lVar5 = *(long *)(param_3 + 2);
  }
  uVar4 = param_3[0xb];
  if (uVar4 != 0) {
    if ((param_3[0xc] & 3U) == 0) {
      puVar6 = (undefined4 *)(lVar5 + (ulong)(uint)param_3[10]);
      if (puVar6 == (undefined4 *)0x0) {
        nvAssertFailedNoLog("pSrc != NULL",
                            "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x48);
      }
      else {
        if ((uVar4 & 3) == 0) {
          uVar2 = (**(code **)(param_4 + 0x568))(param_1,param_4);
          (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x1c0,uVar2 | 0x1000000);
          puVar7 = (undefined4 *)((ulong)(uVar4 & 0xfffffffc) + (long)puVar6);
          do {
            uVar3 = *puVar6;
            puVar6 = puVar6 + 1;
            (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x1c4,uVar3,*(code **)(param_4 + 0x4c8));
          } while (puVar7 != puVar6);
          goto LAB_00376c17;
        }
        nvAssertFailedNoLog("RM_IS_ALIGNED(sizeBytes, FLCN_DMEM_ACCESS_ALIGNMENT)",
                            "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x49);
      }
    }
    else {
      nvAssertFailedNoLog("RM_IS_ALIGNED(dmemDest, FLCN_DMEM_ACCESS_ALIGNMENT)",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x47);
    }
    uVar10 = 0xc0;
    pcVar11 = 
    "s_dmemCopyTo_TU102(pGpu, pKernelFlcn, pUcode->dmemPa, pUcode->pImage + pUcode->dataOffset, pUcode->dmemSize)"
    ;
LAB_00376f73:
    nvAssertOkFailedNoLog
              (0x1f,pcVar11,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",uVar10);
    return 0x1f;
  }
LAB_00376c17:
  (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x104,0);
LAB_00376c30:
  if (param_5 == (undefined4 *)0x0) {
    if (param_6 == (undefined4 *)0x0) {
      (**(code **)(param_4 + 0x518))(param_1,param_4);
      uVar9 = (**(code **)(param_4 + 0x538))(param_1,param_4,0,0);
      return uVar9;
    }
  }
  else {
    (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x40,*param_5);
    if (param_6 == (undefined4 *)0x0) {
      (**(code **)(param_4 + 0x518))(param_1,param_4);
      uVar4 = (**(code **)(param_4 + 0x538))(param_1,param_4,0,0);
      uVar3 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x40);
      *param_5 = uVar3;
      return (ulong)uVar4;
    }
  }
  (**(code **)(param_4 + 0x4c8))(param_1,param_4,0x44,*param_6);
  (**(code **)(param_4 + 0x518))(param_1,param_4);
  uVar4 = (**(code **)(param_4 + 0x538))(param_1,param_4,0,0);
  if (param_5 != (undefined4 *)0x0) {
    uVar3 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x40);
    *param_5 = uVar3;
  }
  uVar3 = (**(code **)(param_4 + 0x4c0))(param_1,param_4,0x44);
  *param_6 = uVar3;
  return (ulong)uVar4;
}


// ===== 00377040 kgspExecuteCoreResume_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspExecuteCoreResume_TU102(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = 0;
  if (param_2 != 0) {
    lVar6 = *(long *)(param_2 + 2000);
  }
  lVar1 = *(long *)(param_2 + 0xb20);
  lVar5 = 0;
  if (*(long *)(param_1 + 0x1ba0) != 0) {
    lVar5 = *(long *)(*(long *)(param_1 + 0x1ba0) + 2000);
  }
  iVar3 = (**(code **)(lVar6 + 0x510))(param_1,lVar6);
  if (iVar3 == 0) {
    (**(code **)(param_2 + 0x818))(param_1,param_2);
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x1d4,
                 "kgspExecuteCoreResume_TU102",1,
                 "NVRM: ---------------Starting SEC2 to resume GSP-RM------------\n");
    (**(code **)(lVar5 + 0x518))(param_1,lVar5);
    iVar3 = timeoutCondWait(param_1 + 0x1af0,0,_kgspIsReloadCompleted,0,0x1d9);
    iVar4 = (**(code **)(lVar5 + 0x4c0))(param_1,lVar5,0x40);
    if (iVar3 == 0 && iVar4 == 0) {
      (**(code **)(lVar6 + 0x4c8))(param_1,lVar6,0x80,*(undefined4 *)(lVar1 + 0x1c));
      cVar2 = (**(code **)(lVar6 + 0x4e8))(param_1,lVar6);
      if (cVar2 == '\0') {
        iVar3 = 0x55;
        nvAssertFailedNoLog("Failed to boot GSP",
                            "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x1ef);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x1eb,
                     "kgspExecuteCoreResume_TU102",1,"NVRM: GSP ucode loaded and RISCV started.\n");
        iVar3 = 0;
      }
    }
    else {
      iVar3 = 0x65;
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x1e0,
                   "kgspExecuteCoreResume_TU102",4,
                   "NVRM: Timeout waiting for SEC2-RTOS to resume GSP-RM. SEC2 Mailbox0 is : 0x%x\n"
                   ,iVar4);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,"kflcnResetIntoRiscv_HAL(pGpu, pKernelFalcon)",
               "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x1d1);
  }
  return iVar3;
}


// ===== 00377220 kgspLoadAndExecuteGenericBootloader_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspLoadAndExecuteGenericBootloader_TU102(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  
  lVar5 = 0;
  if (param_2 != 0) {
    lVar5 = *(long *)(param_2 + 2000);
  }
  if (*(uint *)(param_3 + 0x20) < 8) {
    if (*(int *)(param_3 + 0x54) == 0x54) {
      iVar2 = (**(code **)(param_2 + 0x938))(param_1,param_2);
      if (iVar2 != 0) {
        uVar1 = (**(code **)(lVar5 + 0x4c0))(param_1,lVar5,0x40);
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x217,
                     "kgspLoadAndExecuteGenericBootloader_TU102",4,
                     "NVRM: Timeout waiting for falcon to suspend. mailbox0: 0x%x\n",uVar1);
        return iVar2;
      }
      iVar2 = (**(code **)(lVar5 + 0x508))(param_1,lVar5);
      if (iVar2 == 0) {
        (**(code **)(lVar5 + 0x520))(param_1,lVar5);
        uVar1 = regRead032(param_1 + 0x3a18,0,0,
                           *(int *)(lVar5 + 0x624) + *(int *)(param_3 + 0x20) * 4,0);
        iVar2 = s_setupLoader(param_1,lVar5,param_3,*(undefined4 *)(param_3 + 0x58),
                              *(undefined4 *)(param_3 + 0x5c));
        uVar3 = 0x221;
        pcVar4 = 
        "s_setupLoader(pGpu, pKernelFlcn, pBlDesc, pParams->addrSpace, pParams->cpuCacheAttrib)";
        if (iVar2 == 0) {
          (**(code **)(lVar5 + 0x4c8))(param_1,lVar5,0x40,0xfe);
          (**(code **)(lVar5 + 0x518))(param_1,lVar5);
          iVar2 = (**(code **)(lVar5 + 0x538))(param_1,lVar5,0,0);
          if (iVar2 == 0) {
            regWrite032(param_1 + 0x3a18,0,0,*(int *)(lVar5 + 0x624) + *(int *)(param_3 + 0x20) * 4,
                        uVar1,0);
            iVar2 = (**(code **)(param_2 + 0x9e8))(param_1,param_2);
            if (iVar2 == 0) {
              return 0;
            }
            nvAssertOkFailedNoLog
                      (iVar2,"kgspExecuteCoreResume_HAL(pGpu, pKernelGsp)",
                       "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x235);
            return iVar2;
          }
          uVar3 = 0x22f;
          pcVar4 = "kflcnWaitForHalt_HAL(pGpu, pKernelFlcn, GPU_TIMEOUT_DEFAULT, 0)";
        }
        nvAssertOkFailedNoLog
                  (iVar2,pcVar4,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",uVar3);
        return iVar2;
      }
      nvAssertOkFailedNoLog
                (iVar2,"kflcnReset_HAL(pGpu, pKernelFlcn)",
                 "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x21c);
      return iVar2;
    }
    nvAssertFailedNoLog("sizeof(RM_FLCN_BL_DMEM_DESC) == pParams->dmemDescSize",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x210);
  }
  else {
    nvAssertFailedNoLog("pBlDesc->ctxDma < NV_PFALCON_FBIF_TRANSCFG__SIZE_1",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_falcon_tu102.c",0x20d);
  }
  return 0x1f;
}


// ===== 003774e0 s_vbiosPatchInterfaceData =====

undefined8
s_vbiosPatchInterfaceData
          (long param_1,uint param_2,undefined4 param_3,undefined8 param_4,uint param_5,uint param_6
          )

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  
  if (((param_6 < param_2) && (param_6 < 0xfffffffc)) && (param_6 + 4 <= param_2)) {
    bVar2 = *(byte *)(param_1 + 3 + (ulong)param_6);
    if (bVar2 < 2) {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0xbf,
                   "s_vbiosPatchInterfaceData",4,
                   "NVRM: too few interface entires found for FWSEC cmd 0x%x\n",param_3);
    }
    else {
      uVar5 = 0;
      lVar6 = 0;
      uVar4 = param_6 + 4;
      do {
        if (((param_2 <= uVar4) || (0xfffffff7 < uVar4)) || (param_2 < uVar4 + 8))
        goto LAB_003775e0;
        piVar1 = (int *)(param_1 + (ulong)uVar4);
        if (*piVar1 == 4) {
          uVar3 = piVar1[1];
          if (((param_2 <= uVar3) || (0xffffffbf < uVar3)) || (param_2 < uVar3 + 0x40))
          goto LAB_003775e0;
          lVar6 = (ulong)uVar3 + param_1;
        }
        uVar5 = uVar5 + 1;
        uVar4 = uVar4 + 8;
      } while (uVar5 != bVar2);
      if (lVar6 != 0) {
        *(undefined4 *)(lVar6 + 0x2c) = param_3;
        if (*(uint *)(lVar6 + 0xc) < param_5) {
          nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0xf3,
                       "s_vbiosPatchInterfaceData",4,
                       "NVRM: insufficient cmd buffer for FWSEC interface cmd 0x%x\n",param_3);
        }
        if (((*(uint *)(lVar6 + 8) < param_2) && (param_5 + piVar1[1] <= param_2)) &&
           (!CARRY4(param_5,piVar1[1]))) {
          portMemCopy(param_1 + (ulong)*(uint *)(lVar6 + 8),param_5,param_4,param_5);
          return 0;
        }
        goto LAB_003775e0;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0xeb,
                   "s_vbiosPatchInterfaceData",4,
                   "NVRM: failed to find required interface entry for FWSEC cmd 0x%x\n",param_3);
    }
    uVar7 = 0x25;
  }
  else {
LAB_003775e0:
    uVar7 = 0x37;
  }
  return uVar7;
}


// ===== 003776c0 s_prepareForFwsec_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int s_prepareForFwsec_TU102
              (long param_1,long param_2,int *param_3,int param_4,ulong param_5,undefined8 *param_6)

{
  undefined8 *puVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    nvAssertFailedNoLog("!IS_VIRTUAL(pGpu)","src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c"
                        ,0x124);
    return 0x56;
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x125);
    return 0x56;
  }
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("pFwsecUcode != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x127);
    return 0x1f;
  }
  if (param_6 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pPreparedCmd != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x128);
    return 0x1f;
  }
  if ((param_4 == 0x15) && (param_5 == 0)) {
    nvAssertFailedNoLog("(cmd != FALCON_APPLICATION_INTERFACE_DMEM_MAPPER_V3_CMD_FRTS) || (frtsOffset > 0)"
                        ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x129);
    return 0x1f;
  }
  puVar1 = &local_80;
  uVar9 = 0x18;
  local_80 = 0x1800000001;
  *param_6 = param_3;
  *(int *)(param_6 + 1) = param_4;
  param_6[2] = param_5;
  local_78 = 0;
  local_70 = 0x200000000;
  if (param_4 == 0x15) {
    uVar9 = 0x30;
    puVar1 = &local_68;
    local_50 = 0x1400000001;
    local_44 = 0x200000100;
    local_68 = 0x1800000001;
    local_58 = 0x200000000;
    iVar4 = *param_3;
    local_48 = (undefined4)(param_5 >> 0xc);
    local_60 = 0;
  }
  else {
    iVar4 = *param_3;
  }
  if (iVar4 == 2) {
    if (*(long *)(param_3 + 2) == 0) {
      nvAssertFailedNoLog("pUcode->pUcodeMemDesc != NULL",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x162);
      return 0x1f;
    }
    if (*(long *)(param_3 + 0x10) == 0) {
      nvAssertFailedNoLog("pUcode->pSignatures != NULL",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x163);
      return 0x1f;
    }
    bVar3 = (**(code **)(param_2 + 0x888))(param_1,param_2,param_3[0xe]);
    uVar6 = 1 << (bVar3 & 0x1f);
    uVar8 = uVar6 & param_3[0x15];
    if (uVar8 == 0) {
      return 0x56;
    }
    if ((uVar8 & 1) == 0) {
      uVar8 = 0;
      uVar7 = param_3[0x15];
      do {
        uVar8 = uVar8 + (-(uVar7 & 1) & param_3[0x13]);
        uVar2 = uVar7 & uVar6;
        uVar6 = uVar6 >> 1;
        uVar7 = uVar7 >> 1;
      } while ((uVar2 >> 1 & 1) == 0);
    }
    else {
      uVar8 = 0;
    }
    if ((((uint)param_3[0x12] <= uVar8) || ((uint)param_3[0x12] < uVar8 + param_3[0x13])) ||
       (CARRY4(uVar8,param_3[0x13]))) {
      return 0x37;
    }
    lVar5 = memdescMapInternal(param_1,*(undefined8 *)(param_3 + 2),0);
    if (lVar5 != 0) {
      uVar6 = param_3[9];
      iVar4 = s_vbiosPatchInterfaceData
                        (lVar5 + (ulong)uVar6,param_3[10],param_4,puVar1,uVar9,param_3[0x16]);
      portMemCopy(lVar5 + (ulong)uVar6 + (ulong)(uint)param_3[0xd],param_3[0x13],
                  (ulong)uVar8 + *(long *)(param_3 + 0x10),param_3[0x13]);
      memdescUnmapInternal(param_1,*(undefined8 *)(param_3 + 2),0x10);
      if (iVar4 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x196,
                   "s_prepareForFwsec_TU102",4,
                   "NVRM: failed to prepare interface data for FWSEC cmd 0x%x: 0x%x\n",param_4,iVar4
                  );
      goto LAB_00377b99;
    }
  }
  else {
    if (iVar4 != 1) {
      return 0x56;
    }
    if (*(long *)(param_3 + 2) == 0) {
      nvAssertFailedNoLog("pUcode->pCodeMemDesc != NULL",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1a0);
      return 0x1f;
    }
    if (*(long *)(param_3 + 4) == 0) {
      nvAssertFailedNoLog("pUcode->pDataMemDesc != NULL",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1a1);
      return 0x1f;
    }
    lVar5 = memdescMapInternal(param_1,*(long *)(param_3 + 4),0);
    if (lVar5 != 0) {
      iVar4 = s_vbiosPatchInterfaceData(lVar5,param_3[0xe],param_4,puVar1,uVar9,param_3[0x10]);
      memdescUnmapInternal(param_1,*(undefined8 *)(param_3 + 4),0x10);
      if (iVar4 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1b2,
                   "s_prepareForFwsec_TU102",4,
                   "NVRM: failed to prepare interface data for FWSEC cmd 0x%x: 0x%x\n",param_4,iVar4
                  );
LAB_00377b99:
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1bf,
                   "s_prepareForFwsec_TU102",4,"NVRM: (note: VBIOS version %s)\n",param_2 + 0xa40);
      return iVar4;
    }
  }
  return 0x1a;
}


// ===== 00377cc0 kgspGetFrtsSize_TU102 =====

undefined8 kgspGetFrtsSize_TU102(void)

{
  return 0x100000;
}


// ===== 00377cd0 kgspExecuteFwsec_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspExecuteFwsec_TU102(long param_1,long param_2,undefined8 *param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    nvAssertFailedNoLog("!IS_VIRTUAL(pGpu)","src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c"
                        ,0x1d8);
    return 0x56;
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1d9);
    return 0x56;
  }
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pPreparedCmd != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1db);
    return 0x1f;
  }
  if ((((*(char *)(param_1 + 0x44f) == '\0') && (*(char *)(param_1 + 0x450) == '\0')) &&
      (*(char *)(param_1 + 0x451) == '\0')) && (*(char *)(param_1 + 0x461) == '\0')) {
    uVar5 = 0;
    if (param_2 != 0) {
      uVar5 = *(undefined8 *)(param_2 + 2000);
    }
    uVar5 = (**(code **)(param_2 + 0x930))(param_1,param_2,*param_3,uVar5,0,0);
    iVar3 = (int)uVar5;
    if (iVar3 == 0) {
      param_1 = param_1 + 0x3a18;
      if (*(int *)(param_3 + 1) == 0x15) {
        uVar4 = regRead032(param_1,0,0,0x1438,0);
        if (uVar4 >> 0x10 == 0) {
          uVar4 = regRead032(param_1,0,0,&DAT_001fa828,0);
          if (uVar4 >> 4 == 0) {
            nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1fe,
                         "kgspExecuteFwsec_TU102",4,
                         "NVRM: failed to execute FWSEC for FRTS: no initialized WPR2 found\n");
          }
          else {
            uVar4 = regRead032(param_1,0,0,0x1fa824,0);
            if (uVar4 >> 4 == (uint)((ulong)param_3[2] >> 0xc)) {
              return 0;
            }
            nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x208,
                         "kgspExecuteFwsec_TU102",4,
                         "NVRM: failed to execute FWSEC for FRTS: WPR2 initialized at an unexpected location: 0x%08x (expected 0x%08x)\n"
                         ,uVar4 >> 4,(ulong)param_3[2] >> 0xc);
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1f5,
                       "kgspExecuteFwsec_TU102",4,
                       "NVRM: failed to execute FWSEC for FRTS: FRTS error code 0x%x\n",
                       uVar4 >> 0x10);
        }
      }
      else {
        uVar6 = regRead032(param_1,0,0,0x118128,0);
        if ((uVar6 & 1) == 0) {
          nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x217,
                       "kgspExecuteFwsec_TU102",4,
                       "NVRM: failed to execute FWSEC for SB: GFW PLM not lowered\n");
        }
        else {
          cVar1 = regRead032(param_1,0,0,0x118234,0);
          if (cVar1 == -1) {
            sVar2 = regRead032(param_1,0,0,0x1454,0);
            if (sVar2 == 0) {
              return 0;
            }
            nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x228,
                         "kgspExecuteFwsec_TU102",4,
                         "NVRM: failed to execute FWSEC for SB: SB error code 0x%x\n",sVar2);
          }
          else {
            nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x21f,
                         "kgspExecuteFwsec_TU102",4,
                         "NVRM: failed to execute FWSEC for SB: GFW progress not completed\n");
          }
        }
      }
      iVar3 = 0xffff;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x1e5,
                   "kgspExecuteFwsec_TU102",4,
                   "NVRM: failed to execute FWSEC cmd 0x%x: status 0x%x\n",*(int *)(param_3 + 1),
                   uVar5);
    }
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_frts_tu102.c",0x231,
                 "kgspExecuteFwsec_TU102",4,"NVRM: (note: VBIOS version %s)\n",param_2 + 0xa40);
    return iVar3;
  }
  return 0x10;
}


// ===== 003780c0 kgspPrepareForFwsecFrts_TU102 =====

void kgspPrepareForFwsecFrts_TU102(void)

{
  s_prepareForFwsec_TU102();
  return;
}


// ===== 003780e0 kgspPrepareForFwsecSb_TU102 =====

void kgspPrepareForFwsecSb_TU102(void)

{
  s_prepareForFwsec_TU102();
  return;
}


// ===== 003780f4 _kgspIsProcessorSuspended.cold =====

void _kgspIsProcessorSuspended_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00378100 _kgspIsProcessorSuspended =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _kgspIsProcessorSuspended(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    uVar2 = (**(code **)(*(long *)(param_2 + 2000) + 0x4c0))(param_1,*(long *)(param_2 + 2000),0x40)
    ;
    return uVar2 >> 0x1f;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00378130 kgspConfigureFalcon_TU102 =====

void kgspConfigureFalcon_TU102(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined *local_30;
  undefined4 local_24;
  undefined1 local_1f;
  
  portMemSet(&local_58,0,0x40);
  local_50 = 0x110600;
  local_58 = 0x11100000110000;
  local_4c = 0;
  local_48 = 0;
  local_40 = 0xda3de400;
  local_1f = 1;
  local_30 = &DAT_00d378a7;
  local_24 = 0x78;
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 2000);
  }
  kflcnConfigureEngine_IMPL(param_1,uVar1,&local_58);
  return;
}


// ===== 003781c0 kgspIsDebugModeEnabled_TU102 =====

uint kgspIsDebugModeEnabled_TU102(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x2174c,0);
  return ~uVar1 & 1;
}


// ===== 003781f0 kgspAllocBootArgs_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspAllocBootArgs_TU102(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  uint local_4c;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  local_48 = 0;
  local_40[0] = 0;
  iVar2 = memdescCreate(param_2 + 0xa70,param_1,0x1000,0x1000,1,1,0);
  if (iVar2 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0xa70) + 0x9c) = 0x12;
    iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0xa70));
    if (iVar2 == 0) {
      puVar5 = local_40;
      iVar2 = memdescMap(*(long *)(param_2 + 0xa70),0,
                         *(undefined8 *)(*(long *)(param_2 + 0xa70) + 0x30),1,3,&local_48);
      if (iVar2 == 0) {
        *(undefined8 *)(param_2 + 0xa78) = local_48;
        *(undefined8 *)(param_2 + 0xa80) = local_40[0];
        portMemSet(local_48,0,0x100,puVar5);
        iVar2 = memdescCreate(param_2 + 0xac8,param_1,0x1000,0x1000,1,1,1);
        if (iVar2 == 0) {
          *(undefined4 *)(*(long *)(param_2 + 0xac8) + 0x9c) = 0x13;
          iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0xac8));
          uVar3 = 0x9f;
          if (iVar2 == 0) {
            iVar2 = memdescMap(*(long *)(param_2 + 0xac8),0,
                               *(undefined8 *)(*(long *)(param_2 + 0xac8) + 0x30),1,3,&local_48,
                               local_40);
            if (iVar2 != 0) {
              nvAssertOkFailedNoLog
                        (iVar2,
                         "memdescMap(pKernelGsp->pLibosInitArgumentsDescriptor, 0, memdescGetSize(pKernelGsp->pLibosInitArgumentsDescriptor), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                         ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0xa2);
              goto LAB_003784b0;
            }
            *(undefined8 *)(param_2 + 0xad0) = local_48;
            *(undefined8 *)(param_2 + 0xad8) = local_40[0];
            portMemSet(local_48,0,0x1000);
            uVar3 = 0;
            iVar2 = memdescCreate(param_2 + 0xae0,param_1,0x1000,0x1000,1,1);
            if (iVar2 != 0) {
              nvAssertOkFailedNoLog
                        (iVar2,
                         "memdescCreate(&pKernelGsp->pGspArgumentsDescriptor, pGpu, 0x1000, 0x1000, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
                         ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0xb1,uVar3,
                         0x200000000000);
              goto LAB_003784b0;
            }
            *(undefined4 *)(*(long *)(param_2 + 0xae0) + 0x9c) = 0x14;
            iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0xae0));
            if (iVar2 == 0) {
              iVar2 = memdescMap(*(long *)(param_2 + 0xae0),0,
                                 *(undefined8 *)(*(long *)(param_2 + 0xae0) + 0x30),1,3,&local_48,
                                 local_40);
              if (iVar2 != 0) {
                nvAssertOkFailedNoLog
                          (iVar2,
                           "memdescMap(pKernelGsp->pGspArgumentsDescriptor, 0, memdescGetSize(pKernelGsp->pGspArgumentsDescriptor), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                           ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0xbd);
                goto LAB_003784b0;
              }
              *(undefined8 *)(param_2 + 0xae8) = local_48;
              *(undefined8 *)(param_2 + 0xaf0) = local_40[0];
              portMemSet(local_48,0,0x88);
              if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') {
                return 0;
              }
              local_4c = 0;
              iVar2 = osReadRegistryDword(param_1,"RmGspSysmemHeapSizeMB",&local_4c);
              if (iVar2 == 0) {
                lVar4 = (ulong)local_4c << 0x14;
              }
              else {
                local_4c = 0x200;
                lVar4 = 0x20000000;
              }
              iVar2 = memdescCreate(param_2 + 0xaf8,param_1,lVar4,0,0,1);
              if (iVar2 != 0) {
                nvAssertOkFailedNoLog
                          (iVar2,
                           "memdescCreate(&pKernelGsp->pSysmemHeapDescriptor, pGpu, (NvU64)heapSizeMB << 20, 0, NV_FALSE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, flags)"
                           ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0xd2);
                goto LAB_003784b0;
              }
              *(undefined4 *)(*(long *)(param_2 + 0xaf8) + 0x9c) = 0x14;
              iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0xaf8));
              uVar3 = 0xdb;
              if (iVar2 == 0) {
                cVar1 = memdescCheckContiguity(*(undefined8 *)(param_2 + 0xaf8),1);
                if (cVar1 != '\0') {
                  return 0;
                }
                nvAssertFailedNoLog("memdescCheckContiguity(pKernelGsp->pSysmemHeapDescriptor, AT_GPU)"
                                    ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0xde);
                goto LAB_003784b0;
              }
            }
            else {
              uVar3 = 0xba;
            }
          }
          nvAssertOkFailedNoLog
                    (iVar2,"nvStatus","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",uVar3);
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "memdescCreate(&pKernelGsp->pLibosInitArgumentsDescriptor, pGpu, LIBOS_MEMORY_REGION_INIT_ARGUMENTS_MAX, LIBOS_MEMORY_REGION_INIT_ARGUMENTS_MAX, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, flags)"
                     ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x94);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "memdescMap(pKernelGsp->pWprMetaDescriptor, 0, memdescGetSize(pKernelGsp->pWprMetaDescriptor), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                   ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x85);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"nvStatus","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x82);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,
               "memdescCreate(&pKernelGsp->pWprMetaDescriptor, pGpu, 0x1000, 0x1000, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
               ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x79,0x200000000000);
  }
LAB_003784b0:
  (**(code **)(param_2 + 0x810))(param_1,param_2);
  return iVar2;
}


// ===== 003786e0 kgspFreeBootArgs_TU102 =====

void kgspFreeBootArgs_TU102(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0xa78) != 0) {
    memdescUnmap(*(undefined8 *)(param_2 + 0xa70),1,*(long *)(param_2 + 0xa78),
                 *(undefined8 *)(param_2 + 0xa80));
    *(undefined8 *)(param_2 + 0xa78) = 0;
    *(undefined8 *)(param_2 + 0xa80) = 0;
  }
  if (*(long *)(param_2 + 0xa70) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xa70));
    *(undefined8 *)(param_2 + 0xa70) = 0;
  }
  if (*(long *)(param_2 + 0xad0) != 0) {
    memdescUnmap(*(undefined8 *)(param_2 + 0xac8),1,*(long *)(param_2 + 0xad0),
                 *(undefined8 *)(param_2 + 0xad8));
    *(undefined8 *)(param_2 + 0xad0) = 0;
    *(undefined8 *)(param_2 + 0xad8) = 0;
  }
  if (*(long *)(param_2 + 0xac8) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xac8));
    *(undefined8 *)(param_2 + 0xac8) = 0;
  }
  if (*(long *)(param_2 + 0xae8) != 0) {
    memdescUnmap(*(undefined8 *)(param_2 + 0xae0),1,*(long *)(param_2 + 0xae8),
                 *(undefined8 *)(param_2 + 0xaf0));
    *(undefined8 *)(param_2 + 0xae8) = 0;
    *(undefined8 *)(param_2 + 0xaf0) = 0;
  }
  if (*(long *)(param_2 + 0xae0) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xae0));
    *(undefined8 *)(param_2 + 0xae0) = 0;
  }
  if (*(long *)(param_2 + 0xb28) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xb28));
    *(undefined8 *)(param_2 + 0xb28) = 0;
  }
  if (*(long *)(param_2 + 0xb30) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xb30));
    *(undefined8 *)(param_2 + 0xb30) = 0;
  }
  if (*(long *)(param_2 + 0xaf8) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xaf8));
    *(undefined8 *)(param_2 + 0xaf8) = 0;
  }
  return;
}


// ===== 003788a0 kgspSetCmdQueueHead_TU102 =====

undefined8
kgspSetCmdQueueHead_TU102(long param_1,undefined8 param_2,uint param_3,undefined4 param_4)

{
  if (param_3 < 8) {
    regWrite032(param_1 + 0x3a18,0,0,param_3 * 8 + 0x110c00,param_4,0);
    return 0;
  }
  nvAssertFailedNoLog("queueIdx < NV_PGSP_QUEUE_HEAD__SIZE_1",
                      "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x14f);
  return 0x1f;
}


// ===== 003788f0 kgspProgramLibosBootArgsAddr_TU102 =====

void kgspProgramLibosBootArgsAddr_TU102(long param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xac8),1,0);
  regWrite032(param_1 + 0x3a18,0,0,0x110040,(int)uVar1,0);
  regWrite032(param_1 + 0x3a18,0,0,0x110044,(int)((ulong)uVar1 >> 0x20),0);
  return;
}


// ===== 00378950 kgspPrepareForBootstrap_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgspPrepareForBootstrap_TU102(long param_1,long param_2,int param_3)

{
  char cVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = 0;
  if (param_2 != 0) {
    lVar4 = *(long *)(param_2 + 2000);
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x189,
                 "kgspPrepareForBootstrap_TU102",4,"NVRM: IS_GSP_CLIENT is not set.\n");
  }
  else {
    cVar1 = (**(code **)(lVar4 + 0x4e0))(param_1);
    if (cVar1 != '\0') {
      uVar2 = 0;
      if (param_3 == 0) {
        uVar2 = (**(code **)(param_2 + 0x8e0))(param_1,param_2);
        if ((int)uVar2 != 0) {
          uVar3 = portMemAllocNonPaged(0x18);
          *(undefined8 *)(param_2 + 0xa98) = uVar3;
          uVar2 = (**(code **)(param_2 + 0x8f8))
                            (param_1,param_2,*(undefined8 *)(param_2 + 0xa50),
                             *(undefined8 *)(*(long *)(param_2 + 0xa78) + 0x98),uVar3);
          if ((int)uVar2 != 0) {
            portMemFree(*(undefined8 *)(param_2 + 0xa98));
            uVar2 = uVar2 & 0xffffffff;
            *(undefined8 *)(param_2 + 0xa98) = 0;
          }
        }
      }
      return uVar2;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",399,
                 "kgspPrepareForBootstrap_TU102",4,"NVRM: RISC-V core is not enabled.\n");
  }
  return 0x56;
}


// ===== 00378aa0 kgspBootstrap_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspBootstrap_TU102(undefined8 param_1,long param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = 0;
  if (param_2 != 0) {
    lVar4 = *(long *)(param_2 + 2000);
  }
  if (param_3 < 2) {
    if ((*(long *)(param_2 + 0xa58) != 0) &&
       (iVar2 = (**(code **)(param_2 + 0x918))(param_1,param_2), iVar2 != 0)) {
      nvAssertOkFailedNoLog
                (iVar2,"kgspExecuteScrubberIfNeeded_HAL(pGpu, pKernelGsp)",
                 "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x1eb);
      return iVar2;
    }
    if (param_3 == 0) {
      iVar2 = (**(code **)(param_2 + 0x8e0))(param_1,param_2);
      if (iVar2 != 0) {
        if (*(long *)(param_2 + 0xa98) == 0) {
          nvAssertFailedNoLog("pKernelGsp->pPreparedFwsecCmd != NULL",
                              "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x1f7);
          return 0x40;
        }
        iVar2 = (**(code **)(lVar4 + 0x508))(param_1,lVar4);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,"kflcnReset_HAL(pGpu, pKernelFalcon)",
                     "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x1f9);
          return iVar2;
        }
        iVar2 = (**(code **)(param_2 + 0x908))(param_1,param_2,*(undefined8 *)(param_2 + 0xa98));
        portMemFree(*(undefined8 *)(param_2 + 0xa98));
        *(undefined8 *)(param_2 + 0xa98) = 0;
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x1ff);
          return iVar2;
        }
      }
      iVar2 = (**(code **)(lVar4 + 0x510))(param_1,lVar4);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"kflcnResetIntoRiscv_HAL(pGpu, pKernelFalcon)",
                   "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x202);
        return iVar2;
      }
      (**(code **)(param_2 + 0x818))(param_1,param_2);
      uVar3 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xa70),1,0);
      iVar2 = (**(code **)(param_2 + 0x920))(param_1,param_2,uVar3);
      if (iVar2 != 0) goto LAB_00378e68;
      iVar2 = kgspSendInitRpcs_IMPL(param_1,param_2);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x218,"kgspBootstrap_TU102"
                     ,4,"NVRM: kgspSendInitRpcs failed 0x%x!\n",iVar2);
        return iVar2;
      }
      (**(code **)(lVar4 + 0x4c8))
                (param_1,lVar4,0x80,*(undefined4 *)(*(long *)(param_2 + 0xb20) + 0x1c));
      cVar1 = (**(code **)(lVar4 + 0x4e8))(param_1,lVar4);
      if ((cVar1 == '\0') &&
         (iVar2 = (**(code **)(*(long *)(param_2 + 2000) + 0x4c0))
                            (param_1,*(long *)(param_2 + 2000),0x40), -1 < iVar2))
      goto LAB_00378b95;
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x225,"kgspBootstrap_TU102",1
                   ,"NVRM: GSP ucode loaded and RISCV started.\n");
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x22e,"kgspBootstrap_TU102",1
                   ,"NVRM: Waiting for GSP fw RM to be ready...\n");
      iVar2 = GspStatusQueueInit(param_1,*(long *)(param_2 + 0xa38) + 0x510);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"GspStatusQueueInit(pGpu, &pKernelGsp->pRpc->pMessageQueueInfo)",
                   "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x236);
        return iVar2;
      }
      goto LAB_00378dec;
    }
    uVar3 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xaa0),1,0);
  }
  else {
    if (param_3 != 2) {
      nvAssertFailedNoLog("unexpected GSP boot mode",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x1c2);
    }
    uVar3 = 0;
  }
  iVar2 = (**(code **)(param_2 + 0x920))(param_1,param_2,uVar3);
  if (iVar2 != 0) {
LAB_00378e68:
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x20d,"kgspBootstrap_TU102",4,
                 "NVRM: failed to execute Booter Load (ucode for initial boot): 0x%x\n",iVar2);
    return iVar2;
  }
  (**(code **)(lVar4 + 0x4c8))
            (param_1,lVar4,0x80,*(undefined4 *)(*(long *)(param_2 + 0xb20) + 0x1c));
  cVar1 = (**(code **)(lVar4 + 0x4e8))(param_1,lVar4);
  if ((cVar1 == '\0') &&
     (iVar2 = (**(code **)(*(long *)(param_2 + 2000) + 0x4c0))
                        (param_1,*(long *)(param_2 + 2000),0x40), -1 < iVar2)) {
LAB_00378b95:
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x229,"kgspBootstrap_TU102",4,
                 "NVRM: Failed to boot GSP.\n");
    return 0x55;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x225,"kgspBootstrap_TU102",1,
               "NVRM: GSP ucode loaded and RISCV started.\n");
  nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x22e,"kgspBootstrap_TU102",1,
               "NVRM: Waiting for GSP fw RM to be ready...\n");
LAB_00378dec:
  iVar2 = kgspWaitForRmInitDone_IMPL(param_1,param_2);
  if (iVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x23b,"kgspBootstrap_TU102",1,
                 "NVRM: GSP FW RM ready.\n");
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,"kgspWaitForRmInitDone(pGpu, pKernelGsp)",
               "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x239);
  }
  return iVar2;
}


// ===== 00378f97 kgspTeardown_TU102.cold =====

void kgspTeardown_TU102_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00378fb0 kgspTeardown_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspTeardown_TU102(undefined8 param_1,long param_2,int param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 local_40 [32];
  
  threadStateResetTimeout();
  if (param_3 != 2) {
    if (param_2 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    uVar2 = (**(code **)(*(long *)(param_2 + 2000) + 0x508))(param_1);
    if ((uVar2 & 0xffffffef) != 0) {
      nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x27c);
    }
    iVar3 = (**(code **)(param_2 + 0x900))
                      (param_1,param_2,*(undefined8 *)(param_2 + 0xa50),local_40);
    if (iVar3 == 0) {
      uVar2 = (**(code **)(param_2 + 0x908))(param_1,param_2,local_40);
      if ((uVar2 & 0xffffffef) != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x28a,"kgspTeardown_TU102",
                     4,"NVRM: failed to execute FWSEC-SB for PreOsApps during driver unload: 0x%x\n"
                     ,uVar2);
        nvAssertFailedNoLog("FWSEC-SB failed","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",
                            0x28b);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x282,"kgspTeardown_TU102",4,
                   "NVRM: failed to prepare for FWSEC-SB for PreOsApps during driver unload: 0x%x\n"
                   ,iVar3);
      nvAssertFailedNoLog("FWSEC-SB prep failed","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c"
                          ,0x283);
    }
    if (param_3 != 0) {
      if (param_3 == 1) {
        uVar4 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xaa0),1,0);
        goto LAB_0037908a;
      }
      nvAssertFailedNoLog("unexpected GSP unload mode",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",600);
    }
  }
  uVar4 = 0;
LAB_0037908a:
  (**(code **)(param_2 + 0x928))(param_1,param_2,uVar4);
  return;
}


// ===== 00379170 kgspGetGspRmBootUcodeStorage_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void kgspGetGspRmBootUcodeStorage_TU102
               (undefined8 param_1,long param_2,undefined8 *param_3,undefined8 *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar2 = (**(code **)(param_2 + 0x848))(param_2,param_2,*(code **)(param_2 + 0x848));
  uVar1 = bindataArchiveGetStorage(uVar2,0x23);
  *param_3 = uVar1;
  uVar2 = bindataArchiveGetStorage(uVar2,0x12);
  *param_4 = uVar2;
  return;
}


// ===== 003791d0 kgspPopulateWprMeta_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspPopulateWprMeta_TU102(long param_1,long param_2,long param_3)

{
  undefined8 *puVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  char local_4d;
  int local_4c;
  ulong local_48;
  undefined1 local_40 [16];
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",
                        0x2d9);
    return 0x56;
  }
  if (*(long *)(param_2 + 0xb18) == 0) {
    nvAssertFailedNoLog("pKernelGsp->pGspRmBootUcodeImage != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x2db);
    return 0x40;
  }
  if (*(int *)(param_2 + 0xb10) == 0) {
    nvAssertFailedNoLog("pKernelGsp->gspRmBootUcodeSize != 0",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x2dc);
    return 0x40;
  }
  lVar10 = *(long *)(param_2 + 0xb20);
  if (lVar10 != 0) {
    lVar7 = *(long *)(param_1 + 0x1b80);
    puVar1 = *(undefined8 **)(param_2 + 0xa78);
    lVar2 = *(long *)(param_1 + 0x1b78);
    iVar4 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x178))
                      (param_1,*(long *)(param_1 + 0x1b70),puVar1 + 0x16);
    if (iVar4 == 0) {
      cVar3 = (**(code **)(param_1 + 0x2b8))(param_1);
      if ((cVar3 == '\0') ||
         (cVar3 = (**(code **)(lVar7 + 0x1c8))(param_1,lVar7,puVar1 + 0x17), cVar3 == '\0')) {
        puVar1[0x17] = puVar1[0x16] + -0x100000;
        lVar7 = 0x100000;
      }
      else {
        lVar7 = puVar1[0x16];
        if ((ulong)puVar1[0x17] < lVar7 - 0x100000U) {
          puVar1[0x17] = lVar7 + -0x20000;
          lVar7 = 0x20000;
        }
        else {
          lVar7 = lVar7 - puVar1[0x17];
        }
      }
      puVar1[0x18] = lVar7;
      iVar4 = (**(code **)(lVar2 + 0x358))(param_1,lVar2,&local_4d,&local_48,local_40);
      if (iVar4 == 0) {
        uVar8 = puVar1[0x17];
        if (uVar8 <= local_48) {
          local_48 = uVar8;
        }
        if (local_4d != '\0') {
          uVar8 = local_48;
        }
        puVar1[3] = *(undefined8 *)(param_3 + 0x18);
        lVar7 = kgspGetWprEndMargin_IMPL(param_1,param_2);
        puVar1[0x15] = uVar8 - lVar7 & 0xfffffffffffe0000;
        uVar5 = (**(code **)(param_2 + 0x8e0))(param_1,param_2);
        puVar1[0x14] = (ulong)uVar5;
        lVar7 = puVar1[0x15] - (ulong)uVar5;
        puVar1[0x13] = lVar7;
        uVar5 = *(uint *)(param_2 + 0xb10);
        puVar1[5] = (ulong)uVar5;
        uVar8 = lVar7 - (ulong)uVar5 & 0xfffffffffffff000;
        puVar1[0x12] = uVar8;
        puVar1[0x11] = uVar8 - puVar1[3] & 0xffffffffffff0000;
        uVar5 = (**(code **)(param_2 + 0x880))(param_1,param_2);
        uVar11 = (ulong)uVar5 + 0xfffff & 0xfffffffffff00000;
        lVar7 = kgspGetFwHeapSize_IMPL
                          (param_1,param_2,uVar11 + 0x100000,
                           (puVar1[0x16] + 0xfffff) - puVar1[0x11] & 0xfffffffffff00000);
        uVar8 = puVar1[0x11] - lVar7 & 0xfffffffffff00000;
        puVar1[0xf] = uVar8;
        puVar1[0x10] = puVar1[0x11] - uVar8 & 0xfffffffffff00000;
        cVar3 = *(char *)(param_1 + 0x4a4e);
        puVar1[0xd] = uVar11;
        puVar1[0xe] = uVar8 - 0x100000;
        lVar7 = (uVar8 - 0x100000) - uVar11;
        puVar1[0xc] = lVar7;
        puVar1[0xb] = lVar7;
        *(char *)(puVar1 + 0x1e) = (cVar3 != '\0') << 5;
        uVar9 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xb28),1,0);
        puVar1[2] = uVar9;
        uVar9 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xb00),1,0);
        puVar1[4] = uVar9;
        puVar1[6] = (ulong)*(uint *)(lVar10 + 0x30);
        puVar1[7] = (ulong)*(uint *)(lVar10 + 0x28);
        puVar1[8] = (ulong)*(uint *)(lVar10 + 0x20);
        if (*(long *)(param_2 + 0xb30) != 0) {
          uVar9 = memdescGetPhysAddr(*(long *)(param_2 + 0xb30),1,0);
          puVar1[9] = uVar9;
          puVar1[10] = *(undefined8 *)(*(long *)(param_2 + 0xb30) + 0x30);
        }
        lVar10 = kcrashcatEngineGetQueueMemDesc_IMPL(*(undefined8 *)(param_2 + 0x7c8));
        if (lVar10 != 0) {
          uVar9 = memdescGetPhysAddr(lVar10,1,0);
          puVar1[0x1c] = uVar9;
          *(int *)(puVar1 + 0x1d) = (int)*(undefined8 *)(lVar10 + 0x30);
        }
        iVar6 = osReadRegistryDword(param_1,"RmBootGspRmWithBoostClocks",&local_4c);
        if (iVar6 == 0 && local_4c == 0) {
          *(undefined1 *)(param_2 + 0x6a5f0) = 0;
        }
        if ((*(int *)(param_1 + 0x7f4) == 0x20bb10de) && (*(int *)(param_1 + 0x7fc) == 0x14a110de))
        {
          *(undefined1 *)(param_2 + 0x6a5f0) = 0;
        }
        puVar1[1] = 1;
        puVar1[0x19] = 0;
        puVar1[0x1f] = 0;
        *puVar1 = 0xdc3aae21371a60b3;
        if (*(char *)(param_2 + 0x6a5f0) != '\0') {
          *(byte *)((long)puVar1 + 0xf1) = *(byte *)((long)puVar1 + 0xf1) | 1;
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "memmgrReadMmuLock_HAL(pGpu, pMemoryManager, &bIsMmuLockValid, &mmuLockLo, &mmuLockHi)"
                   ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x2f8);
      }
      return iVar4;
    }
    nvAssertOkFailedNoLog
              (iVar4,"kmemsysGetUsableFbSize_HAL(pGpu, pKernelMemorySystem, &pWprMeta->fbSize)",
               "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x2df);
    return iVar4;
  }
  nvAssertFailedNoLog("pRiscvDesc != NULL","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x2dd
                     );
  return 0x40;
}


// ===== 003796b0 kgspResetHw_TU102 =====

undefined8 kgspResetHw_TU102(long param_1)

{
  uint uVar1;
  int iVar2;
  
  param_1 = param_1 + 0x3a18;
  iVar2 = 10;
  uVar1 = regRead032(param_1,0,0,__pfx_nv_dma_buf_map,0);
  regWrite032(param_1,0,0,__pfx_nv_dma_buf_map,uVar1 | 1,0);
  do {
    regRead032(param_1,0,0,__pfx_nv_dma_buf_map,0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 10;
  uVar1 = regRead032(param_1,0,0,__pfx_nv_dma_buf_map,0);
  regWrite032(param_1,0,0,__pfx_nv_dma_buf_map,uVar1 & 0xfffffffe,0);
  do {
    regRead032(param_1,0,0,__pfx_nv_dma_buf_map,0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}


// ===== 00379770 kgspHealthCheck_TU102.cold =====

void kgspHealthCheck_TU102_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00379790 kgspHealthCheck_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte kgspHealthCheck_TU102(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  char cVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  byte bVar9;
  
  lVar1 = *(long *)(param_1 + 0x1c18);
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar2 = *(long **)(param_2 + 0x7c8);
  cVar5 = (**(code **)(*plVar2 + 0x88))(plVar2);
  if (cVar5 == '\0') {
    return 1;
  }
  bVar9 = 1;
  lVar3 = plVar2[9];
  while (lVar7 = crashcatEngineGetNextCrashReport_IMPL(lVar3), lVar7 != 0) {
    uVar8 = 0x78;
    cVar5 = crashcatReportIsWatchdog_V1(lVar7);
    if (cVar5 != '\0') {
      *(undefined1 *)(param_2 + 0x6a5d8) = 1;
      uVar8 = 0;
    }
    uVar6 = (**(code **)(lVar7 + 0x48))(lVar7);
    if (((uint)uVar6 < 0x10) && ((0x8012UL >> (uVar6 & 0x3f) & 1) != 0)) {
      cVar5 = crashcatReportIsWatchdog_V1(lVar7);
      bVar9 = bVar9 & cVar5 != '\0';
    }
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x3d2,"kgspHealthCheck_TU102",4
                 ,
                 "NVRM: ****************************** GSP-CrashCat Report *******************************\n"
                );
    kgspPrintGspBinBuildId_IMPL(param_1,param_2);
    crashcatReportLog_IMPL(lVar7);
    kgspPostCrashcatReportToNocat_IMPL(param_1,param_2,lVar7,uVar8);
    __nvoc_objDelete(lVar7);
  }
  if (bVar9 == 0) {
    cVar5 = *(char *)(param_2 + 0x69eff);
    *(undefined1 *)(param_2 + 0x69eff) = 1;
    if (*(long *)(param_2 + 0xa38) != 0) {
      kgspInitNocatData_IMPL(param_1,param_2,2);
      prbEncAddUInt32(param_2 + 0x6a608,&prb_fields_gsp_xidreport,0x78);
      kgspLogRpcDebugInfoToProtobuf
                (param_1,*(undefined8 *)(param_2 + 0xa38),param_2,param_2 + 0x6a608);
      kgspPostNocatData_IMPL
                (param_1,param_2,
                 *(undefined8 *)
                  (*(long *)(param_2 + 0xa38) + 0x530 +
                  (ulong)*(uint *)(*(long *)(param_2 + 0xa38) + 0x1918) * 0x28));
      kgspLogRpcDebugInfo(param_1,*(undefined8 *)(param_2 + 0xa38),0x78,
                          *(undefined1 *)(param_2 + 0x69efe));
    }
    if (cVar5 == '\0') {
      if (lVar1 != 0) {
        krcRcAndNotifyAllChannels_IMPL(param_1,lVar1,0x78,1);
      }
      (**(code **)(param_1 + 0x100))(param_1);
    }
    (**(code **)(param_1 + 0x3f8))(param_1);
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x400,"kgspHealthCheck_TU102",4
                 ,
                 "NVRM: **********************************************************************************\n"
                );
    if (*(char *)(param_1 + 0x49d) == '\0') {
      return 0;
    }
    nvAssertFailedNoLog("GSP timed out. Triggering TDR.",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x405);
    gpuNotifySubDeviceEvent_IMPL(param_1,0x9d,0,0,0,0);
  }
  return bVar9;
}


// ===== 00379a40 kgspService_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspService_TU102(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = 0;
  if (param_2 != 0) {
    lVar4 = *(long *)(param_2 + 2000);
  }
  uVar1 = kflcnGetPendingHostInterrupts_IMPL(param_1,lVar4);
  if (uVar1 != 0) {
    if (((param_1 != 0) && (*(char *)(param_1 + 0x44c) != '\0')) &&
       (*(char *)(param_1 + 0x450) == '\0')) {
      if ((uVar1 & 0x10) != 0) {
        (**(code **)(lVar4 + 0x4c8))(param_1,lVar4,4,0x10);
        kgspDumpGspLogs_IMPL(param_2,0);
        (**(code **)(param_2 + 0x898))(param_1,param_2);
      }
      if ((uVar1 & 0x40) != 0) {
        (**(code **)(lVar4 + 0x4c8))(param_1,lVar4,4,0x40);
        kgspRpcRecvEvents_IMPL(param_1,param_2);
        if (*(char *)(param_2 + 0x69efd) != '\0') {
          return 0;
        }
      }
      (**(code **)(param_2 + 0x8c0))(param_1,param_2,uVar1);
      uVar2 = (**(code **)(lVar4 + 0x5e8))(param_1,lVar4);
      if ((uVar1 & uVar2) != 0) {
        (**(code **)(param_2 + 0x8c8))(param_1,param_2);
      }
      if (*(char *)(param_2 + 0x69eff) == '\0') {
        (**(code **)(lVar4 + 0x558))(param_1,lVar4);
      }
      uVar3 = kflcnGetPendingHostInterrupts_IMPL(param_1,lVar4);
      return uVar3;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x428,"kgspService_TU102",4,
                 "NVRM: GPU is detached, bailing!\n");
    return 0;
  }
  nvAssertFailedNoLog("KGSP service called when no KGSP interrupt pending\n",
                      "src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x422);
  return 0;
}


// ===== 00379bf0 kgspWaitForProcessorSuspend_TU102 =====

void kgspWaitForProcessorSuspend_TU102(long param_1,undefined8 param_2)

{
  timeoutCondWait(param_1 + 0x1af0,0,_kgspIsProcessorSuspended,param_2,0x47f);
  return;
}


// ===== 00379c20 kgspIsWpr2Up_TU102 =====

undefined4 kgspIsWpr2Up_TU102(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,&DAT_001fa828,0);
  return CONCAT31((uint3)(uVar1 >> 0xc),uVar1 >> 4 != 0);
}


// ===== 00379c50 kgspWaitForGfwBootOk_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspWaitForGfwBootOk_TU102(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x400))();
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x49a,
               "kgspWaitForGfwBootOk_TU102",4,
               "NVRM: failed to wait for GFW boot complete: 0x%x VBIOS version %s\n",iVar1,
               param_2 + 0xa40);
  nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x49c,
               "kgspWaitForGfwBootOk_TU102",4,
               "NVRM: (the GPU may be in a bad state and may need to be reset)\n");
  return iVar1;
}


// ===== 00379cf0 kgspFreeSuspendResumeData_TU102 =====

void kgspFreeSuspendResumeData_TU102(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0xaa0) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xaa0));
    *(undefined8 *)(param_2 + 0xaa0) = 0;
  }
  if (*(long *)(param_2 + 0xaa8) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0xaa8));
    *(undefined8 *)(param_2 + 0xaa8) = 0;
  }
  return;
}


// ===== 00379d60 kgspPrepareSuspendResumeData_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspPrepareSuspendResumeData_TU102(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 extraout_RDX;
  undefined8 uVar3;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  long local_110;
  uint local_88;
  
  local_138 = 0;
  local_130 = 0;
  portMemSet(&local_128,0,0x100);
  local_120 = 2;
  local_128 = 0x8a3bb9e6c6c39d93;
  lVar1 = *(long *)(param_2 + 0xa78);
  local_110 = ((*(long *)(lVar1 + 0xa0) + *(long *)(lVar1 + 0x98)) - *(long *)(lVar1 + 0x60)) -
              *(long *)(lVar1 + 0x68);
  local_88 = (uint)*(byte *)(lVar1 + 0xf1);
  iVar2 = kgspCreateRadix3_IMPL(param_1,param_2,param_2 + 0xaa8,0,0);
  if (iVar2 == 0) {
    local_118 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xaa8),1,0);
    uVar3 = 1;
    iVar2 = memdescCreate(param_2 + 0xaa0,param_1,0x100,0x100,1,1);
    if (iVar2 == 0) {
      *(undefined4 *)(*(long *)(param_2 + 0xaa0) + 0x9c) = 0x15;
      iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0xaa0),0,extraout_RDX,uVar3);
      if (iVar2 == 0) {
        iVar2 = memdescMap(*(long *)(param_2 + 0xaa0),0,
                           *(undefined8 *)(*(long *)(param_2 + 0xaa0) + 0x30),1,2,&local_138,
                           &local_130);
        if (iVar2 == 0) {
          portMemCopy(local_138,0x100,&local_128,0x100);
          memdescUnmap(*(undefined8 *)(param_2 + 0xaa0),1,local_138,local_130);
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar2,
                   "memdescMap(pKernelGsp->pSRMetaDescriptor, 0, memdescGetSize(pKernelGsp->pSRMetaDescriptor), NV_TRUE, NV_PROTECT_WRITEABLE, &pVa, &pPriv)"
                   ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x4ec);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar2,"nvStatus","src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x4e8);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,
                 "memdescCreate(&pKernelGsp->pSRMetaDescriptor, pGpu, sizeof(GspFwSRMeta), 256, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                 ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x4db);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar2,
               "kgspCreateRadix3(pGpu, pKernelGsp, &pKernelGsp->pSRRadix3Descriptor, NULL, NULL, gspfwSRMeta.sizeOfSuspendResumeData)"
               ,"src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x4cf);
  }
  (**(code **)(param_2 + 0x948))(param_1,param_2);
  return iVar2;
}


// ===== 00379fb0 kgspDumpMailbox_TU102 =====

undefined8 kgspDumpMailbox_TU102(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    uVar1 = regRead032(param_1 + 0x3a18,0,0,iVar2 * 4 + 0x110804,0);
    iVar3 = iVar2 + 1;
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_tu102.c",0x510,"kgspDumpMailbox_TU102",4
                 ,"NVRM: GSP: MAILBOX(%d) = 0x%08X\n",iVar2);
    iVar2 = iVar3;
  } while (iVar3 != 4);
  return uVar1;
}


// ===== 0037a020 kgspReadMailbox_TU102 =====

void kgspReadMailbox_TU102(long param_1,undefined8 param_2,int param_3)

{
  regRead032(param_1 + 0x3a18,0,0,param_3 * 4 + 0x110804,0);
  return;
}


// ===== 0037a040 kgspReadEmem_TU102 =====

void kgspReadEmem_TU102(long param_1,ulong param_2,ulong param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint uVar5;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x7a8);
  }
  uVar5 = (int)param_3 - 4;
  lVar2 = gpuEngineGetGpu(uVar4);
  portMemSet(param_4,0,param_3);
  if ((((param_2 & 0xffff0003) == 0) && (uVar5 < 0xfffd)) && (uVar5 + param_2 < 0xfffd)) {
    uVar3 = 0;
    regWrite032(lVar2 + 0x3a18,0,0,(uint)*(byte *)(param_1 + 0x6a5f1) * 8 + 0x110ac0,
                (uint)param_2 | 0x2000000,0);
    do {
      uVar1 = regRead032(lVar2 + 0x3a18,0,0,(uint)*(byte *)(param_1 + 0x6a5f1) * 8 + 0x110ac4,0);
      *(undefined4 *)(param_4 + uVar3 * 4) = uVar1;
      uVar3 = (ulong)((int)uVar3 + 1);
    } while (uVar3 < param_3 >> 2);
  }
  return;
}


// ===== 0037a140 s_romImgReadGeneric =====

uint s_romImgReadGeneric(uint *param_1,uint param_2,uint param_3,int *param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar5;
  long lVar6;
  uint uVar7;
  undefined4 local_40;
  undefined4 local_3c;
  ulong uVar4;
  
  if (*param_4 != 0) {
    return 0;
  }
  uVar5 = param_2 + *param_1;
  uVar7 = (uint)CARRY4(param_2,*param_1);
  if ((!CARRY4(param_2,*param_1)) &&
     ((param_1[1] == 0 || ((param_3 + uVar5 <= param_1[1] && (!CARRY4(param_3,uVar5))))))) {
    lVar6 = *(long *)(param_1 + 2);
    param_3 = param_3 + (uVar5 & 3);
    uVar4 = (ulong)param_3;
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pSrc->pGpu != NULL",
                          "src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x98);
      lVar6 = *(long *)(param_1 + 2);
    }
    uVar1 = gpuGetDeviceMapping_IMPL(lVar6,0,0);
    local_40 = osDevReadReg032(lVar6,uVar1,(uVar5 & 0xfffffffc) + 0x300000);
    if (4 < param_3) {
      uVar1 = *(undefined8 *)(param_1 + 2);
      uVar2 = gpuGetDeviceMapping_IMPL(uVar1,0,0);
      local_3c = osDevReadReg032(uVar1,uVar2,(uVar5 & 0xfffffffc) + 0x300004);
    }
    do {
      uVar3 = (int)uVar4 - 1;
      uVar4 = (ulong)uVar3;
      uVar7 = (uint)*(byte *)((long)&local_40 + uVar4) + uVar7 * 0x100;
    } while ((uVar5 & 3) != uVar3);
    *param_4 = 0;
    return uVar7;
  }
  *param_4 = 0x37;
  return 0;
}


// ===== 0037a2c0 kgspExtractVbiosFromRom_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspExtractVbiosFromRom_TU102(long param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  short sVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 *puVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  undefined1 *puVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  bool bVar22;
  int local_84;
  int local_70;
  int local_6c;
  undefined8 local_68;
  long local_60;
  uint local_58;
  undefined4 uStack_54;
  long local_50;
  undefined8 local_48;
  long local_40;
  
  local_70 = 0;
  if (*(char *)(param_1 + 0x908) != '\0') {
    nvAssertFailedNoLog("!IS_VIRTUAL(pGpu)",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1cf);
    return 0x56;
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1d0);
    return 0x56;
  }
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("ppVbiosImg != NULL",
                        "src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1d2);
    return 0x1f;
  }
  lVar1 = *(long *)(param_1 + 7000);
  puVar11 = (undefined8 *)portMemAllocNonPaged(0x10);
  if (puVar11 == (undefined8 *)0x0) {
    return 0x51;
  }
  portMemSet(puVar11,0,0x10);
  portMemSet(&local_68,0,0x10);
  local_68 = 0x10000000000000;
  local_60 = param_1;
  if ((lVar1 != 0) &&
     (iVar15 = (**(code **)(lVar1 + 0x2b8))(param_1,lVar1), local_70 = iVar15, iVar15 != 0)) {
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1e5,
                 "kgspExtractVbiosFromRom_TU102",4,
                 "NVRM: ERoT Req/Grant for EEPROM access failed, status=%u\n",iVar15);
    goto LAB_0037a660;
  }
  sVar5 = s_romImgReadGeneric(&local_68,0,2,&local_70);
  iVar15 = local_70;
  if (local_70 != 0) {
    nvAssertOkFailedNoLog
              (local_70,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1ed);
    goto LAB_0037a660;
  }
  if (((sVar5 == -0x55ab) || (sVar5 == 0x4e56)) || (sVar5 == -0x4489)) {
    uVar14 = 0;
LAB_0037a3cb:
    local_6c = 0;
    iVar18 = 0;
    local_84 = 0;
    uVar17 = uVar14;
    while( true ) {
      local_50 = local_60;
      uStack_54 = (undefined4)((ulong)local_68 >> 0x20);
      _local_58 = CONCAT44(uStack_54,uVar17);
      uVar6 = s_romImgReadGeneric(&local_58,0x18,2,&local_6c);
      iVar15 = local_6c;
      if (local_6c != 0) break;
      _local_58 = CONCAT44(uStack_54,uVar6 + uVar17);
      iVar8 = s_romImgReadGeneric(&local_58,0,4,&local_6c);
      iVar15 = local_6c;
      if (local_6c != 0) {
        nvAssertOkFailedNoLog
                  (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x13a
                  );
        goto LAB_0037a820;
      }
      if ((iVar8 != 0x52494350 && iVar8 != 0x5344504e) && (iVar8 != 0x53494752)) {
        iVar15 = 0x25;
        goto LAB_0037a820;
      }
      bVar2 = s_romImgReadGeneric(&local_58,0x15,1,&local_6c);
      uVar9 = s_romImgReadGeneric(&local_58,0x10,2,&local_6c);
      iVar15 = local_6c;
      bVar2 = bVar2 >> 7;
      if (local_6c != 0) {
        nvAssertOkFailedNoLog
                  (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x145
                  );
        goto LAB_0037a820;
      }
      uVar7 = s_romImgReadGeneric(&local_58,10,2,&local_6c);
      iVar15 = local_6c;
      if (local_6c != 0) {
        nvAssertOkFailedNoLog
                  (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x14d
                  );
        goto LAB_0037a820;
      }
      local_40 = local_50;
      local_48._4_4_ = (undefined4)((ulong)_local_58 >> 0x20);
      local_48 = CONCAT44(local_48._4_4_,uVar6 + uVar17 + 0xf + (uint)uVar7) & 0xfffffffffffffff0;
      iVar8 = s_romImgReadGeneric(&local_48,0,4,&local_6c);
      iVar15 = local_6c;
      if (local_6c != 0) {
        nvAssertOkFailedNoLog
                  (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x153
                  );
        goto LAB_0037a820;
      }
      uVar16 = uVar9 & 0xffff;
      if (iVar8 == 0x4544504e) {
        sVar5 = s_romImgReadGeneric(&local_48,4,2,&local_6c);
        iVar15 = local_6c;
        if (local_6c != 0) {
          nvAssertOkFailedNoLog
                    (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",
                     0x158);
          goto LAB_0037a820;
        }
        uVar16 = uVar9 & 0xffff;
        if ((ushort)(sVar5 - 0x100U) < 2) {
          uVar6 = s_romImgReadGeneric(&local_48,6,2,&local_6c);
          uVar7 = s_romImgReadGeneric(&local_48,8,2,&local_6c);
          iVar15 = local_6c;
          if (local_6c != 0) {
            nvAssertOkFailedNoLog
                      (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",
                       0x160);
            goto LAB_0037a820;
          }
          uVar16 = (uint)uVar7;
          if (uVar6 < 0xb) {
            bVar22 = (uVar9 & 0xffff) <= uVar16;
            uVar16 = (uint)uVar7;
            bVar2 = bVar2 & bVar22;
          }
          else {
            bVar2 = s_romImgReadGeneric(&local_48,10,1,&local_6c);
            iVar15 = local_6c;
            if (local_6c != 0) {
              nvAssertOkFailedNoLog
                        (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c"
                         ,0x16d);
              goto LAB_0037a820;
            }
            bVar2 = bVar2 >> 7;
          }
        }
      }
      cVar3 = s_romImgReadGeneric(&local_58,0x14,1,&local_6c);
      iVar15 = local_6c;
      if (local_6c != 0) {
        nvAssertOkFailedNoLog
                  (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x174
                  );
        goto LAB_0037a820;
      }
      iVar15 = uVar16 * 0x200;
      if ((((local_84 != 0) || (iVar8 = uVar17 - uVar14, cVar3 != -0x20)) &&
          (iVar8 = local_84, iVar18 == 0)) && (cVar3 == '\0')) {
        iVar18 = iVar15;
      }
      local_84 = iVar8;
      if (bVar2 != 0) {
        uVar17 = (uVar17 - uVar14) + iVar15;
        if ((local_84 == 0) || (iVar18 == 0)) {
          local_84 = 0;
        }
        else {
          local_84 = local_84 - iVar18;
        }
        if (0x100000 < uVar17) {
          nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x209,
                       "kgspExtractVbiosFromRom_TU102",4,
                       "NVRM: expansion ROM has exceedingly large size: 0x%x\n");
          goto LAB_0037a650;
        }
        puVar12 = (undefined4 *)portMemAllocNonPaged(uVar17);
        if (puVar12 != (undefined4 *)0x0) {
          uVar9 = uVar17 & 0xfffffffc;
          if (uVar9 != 0) {
            puVar20 = puVar12;
            do {
              uVar13 = gpuGetDeviceMapping_IMPL(param_1,0,0);
              puVar21 = puVar20 + 1;
              uVar10 = osDevReadReg032(param_1,uVar13,
                                       ((uVar14 + 0x300000) - (int)puVar12) + (int)puVar20);
              *puVar20 = uVar10;
              puVar20 = puVar21;
            } while (puVar21 != puVar12 + ((uVar9 - 1 >> 2) + 1));
          }
          if (uVar9 < uVar17) {
            puVar19 = (undefined1 *)((ulong)uVar9 + (long)puVar12);
            iVar15 = uVar14 + 0x300000 + uVar9;
            do {
              uVar13 = gpuGetDeviceMapping_IMPL(param_1,0,0);
              iVar18 = iVar15 + 1;
              uVar4 = osDevReadReg008(param_1,uVar13,iVar15);
              *puVar19 = uVar4;
              puVar19 = puVar19 + 1;
              iVar15 = iVar18;
            } while (uVar14 + 0x300000 + uVar17 != iVar18);
          }
          *puVar11 = puVar12;
          *(uint *)(puVar11 + 1) = uVar17;
          *(int *)((long)puVar11 + 0xc) = local_84;
          *param_3 = puVar11;
          return 0;
        }
        iVar15 = 0x51;
        goto LAB_0037a660;
      }
      uVar17 = uVar17 + iVar15;
    }
    nvAssertOkFailedNoLog
              (local_6c,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x135);
LAB_0037a820:
    nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x203,
                 "kgspExtractVbiosFromRom_TU102",4,"NVRM: failed to locate expansion ROMs: 0x%x\n",
                 iVar15);
    goto LAB_0037a660;
  }
  local_48 = local_48 & 0xffffffff00000000;
  iVar18 = s_romImgReadGeneric(&local_68,0,4,&local_48);
  uVar17 = s_romImgReadGeneric(&local_68,4,4,&local_48);
  uVar9 = s_romImgReadGeneric(&local_68,8,4,&local_48);
  iVar15 = (int)local_48;
  if ((int)local_48 == 0) {
    uVar14 = 0;
    if (iVar18 != 0x4947564e) {
LAB_0037a5d9:
      local_68 = CONCAT44(local_68._4_4_,uVar14);
      local_70 = 0;
      sVar5 = s_romImgReadGeneric(&local_68,0,2,&local_70);
      iVar15 = local_70;
      if (local_70 != 0) {
        nvAssertOkFailedNoLog
                  (local_70,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1f6
                  );
        goto LAB_0037a660;
      }
      if ((sVar5 != -0x55ab && sVar5 != 0x4e56) && (sVar5 != -0x4489)) {
        nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1fb,
                     "kgspExtractVbiosFromRom_TU102",4,"NVRM: did not find valid ROM signature\n");
LAB_0037a650:
        iVar15 = 0x25;
        goto LAB_0037a660;
      }
      goto LAB_0037a3cb;
    }
    uVar14 = uVar17 >> 8 & 0xff;
    if (uVar14 < 3) {
      if (uVar14 != 0) {
        iVar18 = (uVar17 >> 0x10 & 0x7fff) + 4;
LAB_0037a99b:
        uVar14 = s_romImgReadGeneric(&local_68,iVar18,4,&local_48);
        iVar15 = (int)local_48;
        if ((int)local_48 == 0) {
          if ((uVar14 & 3) == 0) goto LAB_0037a5d9;
          iVar15 = 0x1e;
          nvAssertFailedNoLog("NV_IS_ALIGNED(imageOffset, 4)",
                              "src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x10d);
        }
        else {
          nvAssertOkFailedNoLog
                    (local_48 & 0xffffffff,"status",
                     "src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x10c);
        }
        goto LAB_0037a9f0;
      }
LAB_0037aaaa:
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x106,
                   "s_romImgFindPciHeader_TU102",4,
                   "NVRM: Error: IFR version not supported = 0x%08x.\n",uVar14);
    }
    else {
      if (uVar14 != 3) goto LAB_0037aaaa;
      iVar18 = s_romImgReadGeneric(&local_68,uVar9 & 0xfffff,4,&local_48);
      iVar8 = s_romImgReadGeneric(&local_68,iVar18 + 0x1000,4,&local_48);
      iVar15 = (int)local_48;
      if ((int)local_48 != 0) {
        nvAssertOkFailedNoLog
                  ((int)local_48,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",
                   0xf7);
        goto LAB_0037a9f0;
      }
      if (iVar8 == 0x44524652) {
        iVar18 = iVar18 + 0x1008;
        goto LAB_0037a99b;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0xff,
                   "s_romImgFindPciHeader_TU102",4,
                   "NVRM: Error: ROM Directory not found = 0x%08x.\n",iVar8);
    }
    iVar15 = 0x25;
  }
  else {
    nvAssertOkFailedNoLog
              ((int)local_48,"status","src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0xe3
              );
  }
LAB_0037a9f0:
  nvAssertOkFailedNoLog
            (iVar15,"s_romImgFindPciHeader_TU102(&src, &pciOffset)",
             "src/kernel/gpu/gsp/arch/turing/kernel_gsp_vbios_tu102.c",0x1f0);
LAB_0037a660:
  kgspFreeVbiosImg(puVar11);
  return iVar15;
}


// ===== 0037ae50 _kgspGetActiveRpcDebugData =====

void _kgspGetActiveRpcDebugData(long param_1,uint param_2,ulong *param_3,ulong *param_4)

{
  long lVar1;
  
  if (param_2 == 0x1004) {
    lVar1 = *(long *)(param_1 + 0x4d8);
    *param_3 = (ulong)*(uint *)(lVar1 + 0x20);
    *param_4 = (ulong)*(uint *)(lVar1 + 0x30);
    return;
  }
  if (param_2 < 0x1005) {
    if (param_2 == 0x67) {
      lVar1 = *(long *)(param_1 + 0x4d8);
      *param_3 = (ulong)*(uint *)(lVar1 + 0x2c);
      *param_4 = (ulong)*(uint *)(lVar1 + 0x34);
      return;
    }
    if (param_2 < 0x68) {
      if (param_2 == 10) {
        lVar1 = *(long *)(param_1 + 0x4d8);
        *param_3 = (ulong)*(uint *)(lVar1 + 0x28);
        *param_4 = (ulong)*(uint *)(lVar1 + 0x24);
        return;
      }
      if (param_2 == 0x4c) {
        lVar1 = *(long *)(param_1 + 0x4d8);
        *param_3 = (ulong)*(uint *)(lVar1 + 0x28);
        *param_4 = (ulong)*(uint *)(lVar1 + 0x30);
        return;
      }
    }
    else if (param_2 == 0x1003) {
      lVar1 = *(long *)(param_1 + 0x4d8);
      *param_3 = (ulong)*(uint *)(lVar1 + 0x28);
      *param_4 = (ulong)*(uint *)(lVar1 + 0x2c);
      return;
    }
  }
  else {
    if (param_2 == 0x101c) {
      *param_3 = (ulong)*(byte *)(*(long *)(param_1 + 0x4d8) + 0x20);
      goto LAB_0037af60;
    }
    if (param_2 == 0x1020) {
      lVar1 = *(long *)(param_1 + 0x4d8);
      *param_3 = (ulong)*(byte *)(lVar1 + 0x30);
      *param_4 = *(ulong *)(lVar1 + 0x80);
      return;
    }
    if (param_2 == 0x100d) {
      lVar1 = *(long *)(param_1 + 0x4d8);
      *param_3 = (ulong)*(uint *)(lVar1 + 0x20);
      *param_4 = (ulong)*(uint *)(lVar1 + 0x24);
      return;
    }
  }
  *param_3 = 0;
LAB_0037af60:
  *param_4 = 0;
  return;
}


// ===== 0037af80 _kgspFreeLibosVgpuPartitionLoggingStructures =====

void _kgspFreeLibosVgpuPartitionLoggingStructures(undefined8 param_1,long param_2,int param_3)

{
  long *plVar1;
  long *plVar2;
  long local_40 [3];
  
  local_40[0] = param_2 + 0x68cc8;
  plVar2 = local_40;
  local_40[1] = param_2 + 0x692c8;
  local_40[2] = param_2 + 0x698c8;
  libosLogDestroy(param_2 + 0x2d48 + (ulong)(param_3 - 1) * 0x21f8);
  do {
    plVar1 = (long *)(*plVar2 + (ulong)(param_3 - 1) * 0x20);
    if (plVar1[1] != 0) {
      memdescUnmapInternal(param_1,*plVar1,0);
      plVar1[1] = 0;
    }
    if (*plVar1 != 0) {
      memdescFree();
      memdescDestroy(*plVar1);
      *plVar1 = 0;
    }
    plVar2 = plVar2 + 1;
  } while (plVar2 != (long *)&stack0xffffffffffffffd8);
  return;
}


// ===== 0037b030 _kgspRpcIncrementTimeoutCountAndRateLimitPrints =====

void _kgspRpcIncrementTimeoutCountAndRateLimitPrints(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar1 = *(uint *)(param_2 + 0x2d28);
  lVar3 = *(long *)(param_1 + 0x1ba8);
  uVar5 = uVar1 + 1;
  *(uint *)(param_2 + 0x2d28) = uVar5;
  uVar2 = *(uint *)(lVar3 + 0x6a5e4);
  if (uVar1 != uVar2) {
    bVar6 = false;
    if (uVar2 < uVar5) {
      bVar6 = 0x8888888 <
              (uVar5 * -0x11111111 >> 1 | (uint)((uVar5 * -0x11111111 & 1) != 0) << 0x1f);
    }
    *(bool *)(param_2 + 0x2d2c) = bVar6;
    return;
  }
  if (*(char *)(*(long *)(param_1 + 0x1c18) + 0x18a) != '\0') {
    uVar4 = *(ulong *)(param_1 + 0x878);
    nv_printf(0xffffffff,
              "NVRM: Rate limiting GSP RPC error prints for GPU at PCI:%04x:%02x:%02x (printing 1 of every %d).  The GPU likely needs to be reset.\n"
              ,uVar4 >> 0x20,uVar4 >> 8 & 0xff,uVar4 & 0xff,0x1e);
  }
  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x9b7,
               "_kgspRpcIncrementTimeoutCountAndRateLimitPrints",3,
               "NVRM: Rate limiting GSP RPC error prints (printing 1 of every %d)\n",0x1e);
  bVar6 = false;
  if (*(uint *)(lVar3 + 0x6a5e4) < *(uint *)(param_2 + 0x2d28)) {
    uVar5 = *(uint *)(param_2 + 0x2d28) * -0x11111111;
    bVar6 = 0x8888888 < (uVar5 >> 1 | (uint)((uVar5 & 1) != 0) << 0x1f);
  }
  *(bool *)(param_2 + 0x2d2c) = bVar6;
  return;
}


// ===== 0037b140 _kgspIsHeartbeatTimedOut =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kgspIsHeartbeatTimedOut(long param_1,long param_2,int param_3,uint param_4)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  
  if ((*(long *)(param_2 + 0x6a5c8) == 0) || (*(long *)(param_2 + 0x6a5d0) == 0)) {
    return 0;
  }
  lVar1 = *(long *)(param_1 + 0x1b88);
  lVar2 = *(long *)(param_1 + 0x1d08);
  lVar5 = (**(code **)(lVar1 + 0x1a0))(param_1,lVar1);
  lVar6 = (**(code **)(lVar1 + 0x1d0))(param_1,lVar1);
  uVar10 = lVar5 + lVar6;
  if (lVar2 == 0) {
    uVar9 = *(ulong *)(lVar1 + 0x24f8);
  }
  else {
    cVar3 = (**(code **)(lVar2 + 0x220))(param_1,lVar2);
    uVar9 = *(ulong *)(lVar1 + 0x24f8);
    uVar7 = 0;
    if (cVar3 != '\0') {
      uVar7 = uVar9;
    }
    uVar10 = uVar10 + uVar7;
  }
  uVar10 = uVar10 / 1000000;
  iVar4 = param_3 + (int)(uVar9 / 1000000);
  uVar8 = (int)uVar10 - iVar4;
  if (param_4 < uVar8) {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x906,"_kgspIsHeartbeatTimedOut",4,
                 "NVRM: Heartbeat timed out, currentTimeMs %u heartbeat %u heartbeatWithOffsetMs %u diff %u timeout %u\n"
                 ,uVar10,param_3,iVar4,uVar8,param_4);
    return 1;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x90b,"_kgspIsHeartbeatTimedOut",1,
               "NVRM: Heartbeat not timed out, currentTimeMs %u heartbeat %u heartbeatWithOffsetMs %u diff %u timeout %u\n"
               ,uVar10,param_3,iVar4,uVar8,param_4);
  return 0;
}


// ===== 0037b2d0 _kgspAddRpcHistoryEntry =====

void _kgspAddRpcHistoryEntry(long param_1,long param_2,uint *param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  uVar2 = *(undefined4 *)(*(long *)(param_1 + 0x4d8) + 0xc);
  uVar3 = *(undefined4 *)(*(long *)(param_1 + 0x4d8) + 0x18);
  uVar4 = *param_3 + 1 & 0x7f;
  *param_3 = uVar4;
  puVar1 = (undefined8 *)(param_2 + (ulong)uVar4 * 0x28);
  portMemSet(puVar1,0,0x28);
  *puVar1 = CONCAT44(uVar3,uVar2);
  uVar5 = osGetTimestamp();
  puVar1[3] = uVar5;
  _kgspGetActiveRpcDebugData(param_1,uVar2,puVar1 + 1,puVar1 + 2);
  return;
}


// ===== 0037b340 _kgspCompleteRpcHistoryEntry =====

void _kgspCompleteRpcHistoryEntry(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  uint uVar4;
  
  lVar1 = param_1 + (ulong)param_2 * 0x28;
  if (*(long *)(lVar1 + 0x18) == 0) {
    nvAssertFailedNoLog("pHistory[current].ts_start != 0","src/kernel/gpu/gsp/kernel_gsp.c",0x175);
    return;
  }
  uVar2 = osGetTimestamp();
  uVar4 = param_2 - 1;
  *(undefined8 *)(lVar1 + 0x20) = uVar2;
  while( true ) {
    uVar3 = (ulong)(uVar4 & 0x7f);
    if (*(long *)(param_1 + 0x18 + uVar3 * 0x28) == 0) {
      return;
    }
    if (*(long *)(param_1 + 0x20 + uVar3 * 0x28) != 0) break;
    uVar4 = uVar4 - 1;
    *(undefined8 *)(param_1 + 0x20 + uVar3 * 0x28) = *(undefined8 *)(lVar1 + 0x20);
    if (uVar4 == param_2 - 0x80) {
      return;
    }
  }
  return;
}


// ===== 0037b3e0 _kgspRpcMigCiConfigUpdateCallback =====

void _kgspRpcMigCiConfigUpdateCallback(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = gpumgrGetGpu();
  kmigmgrUpdateCiConfigForVgpu_IMPL
            (lVar1,*(undefined8 *)(lVar1 + 0x1bc0),*param_2,param_2 + 1,param_2[9],
             *(undefined1 *)(param_2 + 10));
  return;
}


// ===== 0037b420 _kgspRpcGspEventHandleFecsBufferError =====

void _kgspRpcGspEventHandleFecsBufferError(undefined8 param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = gpumgrGetGpu();
  fecsHandleFecsLoggingError(uVar1,*param_2,param_2[1]);
  return;
}


// ===== 0037b450 _kgspRpcSanityCheck =====

undefined8 _kgspRpcSanityCheck(long param_1,long param_2,long param_3)

{
  char cVar1;
  
  if (*(char *)(param_2 + 0x69eff) != '\0') {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x126,"_kgspRpcSanityCheck",1,
                 "NVRM: GSP crashed, skipping RPC\n");
    *(undefined1 *)(param_3 + 0x2d2c) = 1;
    return 0x62;
  }
  if ((((param_1 == 0) || (*(char *)(param_1 + 0x44f) != '\0')) ||
      (*(char *)(param_1 + 0x450) != '\0')) ||
     ((*(char *)(param_1 + 0x451) != '\0' || (*(char *)(param_1 + 0x461) != '\0')))) {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x132,"_kgspRpcSanityCheck",1,
                 "NVRM: GPU in reset, skipping RPC\n");
    *(undefined1 *)(param_3 + 0x2d2c) = 1;
    return 0x10;
  }
  if ((*(char *)(param_1 + 0x44c) == '\0') || (*(char *)(param_1 + 0x455) != '\0')) {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x13c,"_kgspRpcSanityCheck",1,
                 "NVRM: GPU lost, skipping RPC\n");
  }
  else {
    cVar1 = osIsGpuShutdown();
    if (cVar1 == '\0') {
      cVar1 = gpuIsGpuFullPowerForPmResume_IMPL();
      if (cVar1 == '\0') {
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x146,"_kgspRpcSanityCheck",1,
                     "NVRM: GPU not full power, skipping RPC\n");
        return 0x11;
      }
      cVar1 = gpuCheckSysmemAccess_IMPL(param_1);
      if (cVar1 != '\0') {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x14b,"_kgspRpcSanityCheck",1,
                   "NVRM: GPU has no sysmem access, skipping RPC\n");
      return 0x1d;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x141,"_kgspRpcSanityCheck",1,
                 "NVRM: GPU shutdown, skipping RPC\n");
  }
  return 0xf;
}


// ===== 0037b630 _kgspRpcSendMessage =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kgspRpcSendMessage(long param_1,long param_2,int *param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 local_2c [4];
  
  lVar1 = *(long *)(param_1 + 0x1ba8);
  cVar2 = rmGpuGroupLockIsOwner(*(undefined4 *)(param_1 + 0x7a4),0,local_2c);
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmGpuGroupLockIsOwner(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, &gpuMaskUnused)"
                        ,"src/kernel/gpu/gsp/kernel_gsp.c",0x19b);
  }
  *(undefined1 *)(lVar1 + 0x6a5d8) = 0;
  if (param_3 == (int *)0x0) {
    *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x18) = 0;
  }
  else {
    iVar3 = *(int *)(param_2 + 0x2d24);
    *(int *)(param_2 + 0x2d24) = iVar3 + 1;
    *param_3 = iVar3;
    *(int *)(*(long *)(param_2 + 0x4d8) + 0x18) = iVar3;
  }
  iVar3 = _kgspRpcSanityCheck(param_1,lVar1,param_2);
  if (iVar3 == 0) {
    iVar3 = GspMsgQueueSendCommand(*(undefined8 *)(param_2 + 0x510),param_1);
    if (iVar3 != 0) {
      if ((iVar3 == 0x65) || (iVar3 == 3)) {
        _kgspRpcIncrementTimeoutCountAndRateLimitPrints(param_1,param_2);
      }
      if (*(char *)(param_2 + 0x2d2c) == '\0') {
        uVar4 = 4;
      }
      else {
        uVar4 = 1;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1ae,"_kgspRpcSendMessage",uVar4,
                   "NVRM: GspMsgQueueSendCommand failed on GPU%d: 0x%x\n",
                   *(undefined4 *)(param_1 + 0x7a4),iVar3);
      return iVar3;
    }
    (**(code **)(lVar1 + 0x820))(param_1,lVar1,*(undefined4 *)(*(long *)(param_2 + 0x510) + 0x74),0)
    ;
    _kgspAddRpcHistoryEntry(param_2,param_2 + 0x518,param_2 + 0x1918);
    iVar3 = 0;
  }
  return iVar3;
}


// ===== 0037b7d0 _kgspDumpEngineFunc =====

ulong _kgspDumpEngineFunc(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  undefined1 local_3c;
  
  lVar4 = gpuGetRpc();
  uVar2 = *(undefined4 *)(param_2 + 0x148);
  uVar3 = prbEncNestedStart(param_2,&DAT_00c5e908);
  if (uVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar3,"prbEncNestedStart(pPrbEnc, NVDEBUG_GPUINFO_ENG_KGSP)",
               "src/kernel/gpu/gsp/kernel_gsp.c",0x193c);
    return (ulong)uVar3;
  }
  iVar8 = 0;
  do {
    lVar1 = lVar4 + (ulong)(*(int *)(lVar4 + 0x1918) - iVar8 & 0x7f) * 0x28;
    iVar9 = 0;
    if (*(int *)(lVar1 + 0x518) == 0) break;
    uVar5 = prbEncNestedStart(param_2,&prb_fields_nvdebug_eng_kgsp);
    if ((int)uVar5 != 0) {
      uVar7 = 0x1947;
      pcVar6 = "prbEncNestedStart(pPrbEnc, NVDEBUG_ENG_KGSP_RPC_HISTORY)";
      goto LAB_0037b91d;
    }
    iVar8 = iVar8 + 1;
    prbEncAddUInt32(param_2,prb_fields_nvdebug_eng_kgsp_rpcinfo,*(undefined4 *)(lVar1 + 0x518));
    prbEncAddUInt32(param_2,0xc42a98,*(undefined4 *)(lVar1 + 0x51c));
    prbEncAddUInt64(param_2,0xc42a38,*(undefined8 *)(lVar1 + 0x530));
    prbEncAddUInt64(param_2,0xc42a50,*(undefined8 *)(lVar1 + 0x538));
    prbEncAddUInt32(param_2,0xc42a68,*(undefined4 *)(lVar1 + 0x520));
    prbEncAddUInt32(param_2,0xc42a80,*(undefined4 *)(lVar1 + 0x528));
    prbEncNestedEnd(param_2);
  } while (iVar8 != 0x80);
  do {
    lVar1 = lVar4 + (ulong)(*(int *)(lVar4 + 0x2d20) - iVar9 & 0x7f) * 0x28;
    if (*(int *)(lVar1 + 0x1920) == 0) break;
    uVar5 = prbEncNestedStart(param_2,&DAT_00c42b58);
    if ((int)uVar5 != 0) {
      uVar7 = 0x195c;
      pcVar6 = "prbEncNestedStart(pPrbEnc, NVDEBUG_ENG_KGSP_EVENT_HISTORY)";
      goto LAB_0037b91d;
    }
    iVar9 = iVar9 + 1;
    prbEncAddUInt32(param_2,prb_fields_nvdebug_eng_kgsp_rpcinfo,*(undefined4 *)(lVar1 + 0x1920));
    prbEncAddUInt32(param_2,0xc42a98,*(undefined4 *)(lVar1 + 0x1924));
    prbEncAddUInt64(param_2,0xc42a38,*(undefined8 *)(lVar1 + 0x1938));
    prbEncAddUInt64(param_2,0xc42a50,*(undefined8 *)(lVar1 + 0x1940));
    prbEncAddUInt32(param_2,0xc42a68,*(undefined4 *)(lVar1 + 0x1928));
    prbEncAddUInt32(param_2,0xc42a80,*(undefined4 *)(lVar1 + 0x1930));
    prbEncNestedEnd(param_2);
  } while (iVar9 != 0x80);
  local_3c = (undefined1)uVar2;
  uVar5 = prbEncUnwindNesting(param_2,local_3c);
  if ((int)uVar5 != 0) {
    uVar7 = 0x196a;
    pcVar6 = "prbEncUnwindNesting(pPrbEnc, startingDepth)";
LAB_0037b91d:
    nvCheckOkFailedNoLog(4,uVar5 & 0xffffffff,pcVar6,"src/kernel/gpu/gsp/kernel_gsp.c",uVar7);
    uVar5 = uVar5 & 0xffffffff;
  }
  return uVar5;
}


// ===== 0037bac0 _setupLogBufferBaremetal.constprop.0 =====

int _setupLogBufferBaremetal_constprop_0
              (long param_1,long param_2,uint param_3,byte *param_4,undefined8 param_5,
              undefined4 param_6,undefined8 param_7,char param_8)

{
  byte *pbVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  lVar6 = (ulong)param_3 * 0x20;
  local_48 = 0;
  local_40[0] = 0;
  uVar7 = 0;
  iVar4 = memdescCreate(param_2 + 0x68bc8 + lVar6,param_1,param_6,0x1000,1,1,0,0x200000000000);
  if (iVar4 == 0) {
    lVar6 = lVar6 + param_2;
    *(undefined4 *)(*(long *)(lVar6 + 0x68bc8) + 0x9c) = 0x2d;
    iVar4 = memdescAlloc(*(undefined8 *)(lVar6 + 0x68bc8),uVar7);
    if (iVar4 == 0) {
      iVar4 = memdescMap(*(long *)(lVar6 + 0x68bc8),0,
                         *(undefined8 *)(*(long *)(lVar6 + 0x68bc8) + 0x30),1,3,&local_48,local_40);
      if (iVar4 == 0) {
        *(undefined8 *)(lVar6 + 0x68bd8) = local_40[0];
        *(undefined8 *)(lVar6 + 0x68bd0) = local_48;
        portMemSet(local_48,0,*(undefined8 *)(*(long *)(lVar6 + 0x68bc8) + 0x30));
        lVar3 = *(long *)(lVar6 + 0x68bd0);
        uVar7 = memdescGetPhysAddr(*(undefined8 *)(lVar6 + 0x68bc8),1,0);
        uVar5 = 0;
        *(undefined8 *)(lVar3 + 8) = uVar7;
        pbVar1 = param_4 + 8;
        do {
          bVar2 = *param_4;
          if (bVar2 == 0) break;
          param_4 = param_4 + 1;
          uVar5 = uVar5 << 8 | (ulong)bVar2;
        } while (pbVar1 != param_4);
        *(ulong *)(param_2 + 0x68be0 + (ulong)param_3 * 0x20) = uVar5;
        libosLogAddLogEx(param_2 + 0xb50,*(undefined8 *)(lVar6 + 0x68bd0),
                         *(undefined8 *)(*(long *)(lVar6 + 0x68bc8) + 0x30),
                         *(undefined4 *)(param_1 + 0x7a4),*(uint *)(param_1 + 0x808) >> 4,
                         *(undefined4 *)(param_1 + 0x80c),param_5,param_7,param_8 == '\0',
                         *(undefined8 *)(param_2 + 0x69ee0),2,1);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "memdescMap(pLog->pTaskLogDescriptor, 0, memdescGetSize(pLog->pTaskLogDescriptor), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                   ,"src/kernel/gpu/gsp/kernel_gsp.c",0xd8e);
      }
    }
    else {
      nvAssertOkFailedNoLog(iVar4,"nvStatus","src/kernel/gpu/gsp/kernel_gsp.c",0xd8b);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar4,
               "memdescCreate(&pLog->pTaskLogDescriptor, pGpu, size, RM_PAGE_SIZE, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
               ,"src/kernel/gpu/gsp/kernel_gsp.c",0xd80);
  }
  return iVar4;
}


// ===== 0037bd00 _setupLogBufferVgpu.constprop.0.isra.0 =====

int _setupLogBufferVgpu_constprop_0_isra_0
              (long param_1,long param_2,int param_3,byte *param_4,undefined8 param_5,
              undefined8 param_6,undefined8 param_7,undefined8 param_8,long param_9)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  undefined1 local_40 [16];
  
  plVar6 = (long *)((ulong)(param_3 - 1) * 0x20 + param_9);
  iVar3 = memdescCreate(plVar6,param_1,param_8,0x1000,1,2,0,0);
  if (iVar3 == 0) {
    memdescDescribe(*plVar6,2,param_7,param_8);
    lVar4 = memdescMapInternal(param_1,*plVar6,0);
    if (lVar4 == 0) {
      iVar3 = 0x1a;
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xc87,"_setupLogBufferVgpu",4,
                   "NVRM: Failed to map memory for %s task log buffer for vGPU partition \n",param_5
                  );
    }
    else {
      plVar6[1] = lVar4;
      portMemSet(lVar4,0,param_8);
      pbVar1 = param_4 + 8;
      uVar5 = 0;
      do {
        bVar2 = *param_4;
        if (bVar2 == 0) break;
        param_4 = param_4 + 1;
        uVar5 = uVar5 << 8 | (ulong)bVar2;
      } while (pbVar1 != param_4);
      plVar6[3] = uVar5;
      nvDbgSnprintf(local_40,8,&DAT_00d38f87,param_5,param_3);
      libosLogAddLogEx(param_2 + 0x2d48 + (ulong)(param_3 - 1) * 0x21f8,plVar6[1],
                       *(undefined8 *)(*plVar6 + 0x30),*(undefined4 *)(param_1 + 0x7a4),
                       *(uint *)(param_1 + 0x808) >> 4,*(undefined4 *)(param_1 + 0x80c),local_40,
                       param_6,0,*(undefined8 *)(param_2 + 0x69ee0),2,3);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,
               "memdescCreate(&pTaskLog->pTaskLogDescriptor, pGpu, logVgpuSetupParams.bufSize, RM_PAGE_SIZE, NV_TRUE, ADDR_FBMEM, NV_MEMORY_CACHED, MEMDESC_FLAGS_NONE)"
               ,"src/kernel/gpu/gsp/kernel_gsp.c",0xc5c);
  }
  return iVar3;
}


// ===== 0037bec0 _kgspFwContainerGetSection.isra.0 =====

undefined8
_kgspFwContainerGetSection_isra_0
          (int *param_1,ulong param_2,undefined8 param_3,long *param_4,undefined8 *param_5)

{
  ushort uVar1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  uint *puVar8;
  undefined8 uVar9;
  ulong uVar10;
  char *pcVar11;
  short sVar12;
  ulong uVar13;
  
  if (param_1 == (int *)0x0) {
    nvCheckFailedNoLog(4,"pElfData != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x1733);
  }
  else {
    if (param_2 != 0) {
      if (param_2 < 0x40) {
        nvCheckFailedNoLog(4,"elfDataSize >= sizeof(LibosElf64Header)",
                           "src/kernel/gpu/gsp/kernel_gsp.c",0x1738);
      }
      else {
        uVar5 = portStringLength(param_3);
        if (*param_1 == 0x464c457f) {
          if (*(char *)((long)param_1 + 5) == '\x01') {
            if ((char)param_1[1] == '\x02') {
              if (*(short *)((long)param_1 + 0x3a) == 0x40) {
                uVar1 = *(ushort *)(param_1 + 0xf);
                uVar2 = *(ulong *)(param_1 + 10);
                uVar7 = (uVar2 - 1) + (ulong)uVar1 * 0x40;
                if (uVar7 < uVar2) {
                  uVar9 = 0x1748;
                  pcVar11 = 
                  "portSafeAddU64(pElfHeader->shoff, elfSectionHeaderTableLength - 1, &elfSectionHeaderMaxIdx)"
                  ;
                }
                else if (param_2 < uVar7) {
                  uVar9 = 0x1749;
                  pcVar11 = "elfDataSize >= elfSectionHeaderMaxIdx";
                }
                else if (uVar1 < *(ushort *)((long)param_1 + 0x3e)) {
                  uVar9 = 0x174a;
                  pcVar11 = "pElfHeader->shstrndx <= pElfHeader->shnum";
                }
                else {
                  lVar6 = (ulong)*(ushort *)((long)param_1 + 0x3e) * 0x40 + uVar2;
                  uVar2 = *(ulong *)((long)param_1 + lVar6 + 0x18);
                  uVar13 = *(long *)((long)param_1 + lVar6 + 0x20) - 1;
                  if (CARRY8(uVar2,uVar13)) {
                    uVar9 = 0x1750;
                    pcVar11 = 
                    "portSafeAddU64(elfSectionNamesTableOffset, elfSectionNamesTableSize - 1, &elfSectionNamesTableMaxIdx)"
                    ;
                  }
                  else {
                    if (uVar2 + uVar13 <= param_2) {
                      sVar12 = uVar1 - 1;
                      if (-1 < sVar12) {
                        puVar8 = (uint *)((long)param_1 + (uVar7 - 0x3f));
                        do {
                          uVar7 = (ulong)*puVar8;
                          if (uVar13 < uVar7) {
                            uVar9 = 0x175c;
                            pcVar11 = "elfSectionNamesTableSize - 1 >= pElfSectionHeader->name";
                            goto LAB_0037c090;
                          }
                          uVar3 = *(ulong *)(puVar8 + 6);
                          uVar10 = uVar3;
                          if ((*(long *)(puVar8 + 8) != 0) &&
                             (uVar10 = *(long *)(puVar8 + 8) + -1 + uVar3, uVar10 < uVar3)) {
                            uVar9 = 0x1763;
                            pcVar11 = 
                            "portSafeAddU64(pElfSectionHeader->offset, pElfSectionHeader->size - 1, &elfSectionMaxIdx)"
                            ;
                            goto LAB_0037c090;
                          }
                          if (param_2 < uVar10) {
                            uVar9 = 0x1769;
                            pcVar11 = "elfDataSize >= elfSectionMaxIdx";
                            goto LAB_0037c090;
                          }
                          if (uVar5 <= uVar13 - uVar7) {
                            lVar6 = (long)param_1 + uVar7 + uVar2;
                            iVar4 = portStringCompare(lVar6,param_3);
                            if ((iVar4 == 0) && (*(char *)(lVar6 + uVar5) == '\0')) {
                              *param_4 = (long)param_1 + *(long *)(puVar8 + 6);
                              *param_5 = *(undefined8 *)(puVar8 + 8);
                              return 0;
                            }
                          }
                          sVar12 = sVar12 + -1;
                          puVar8 = puVar8 + -0x10;
                        } while (sVar12 != -1);
                      }
                      return 0x57;
                    }
                    uVar9 = 0x1751;
                    pcVar11 = "elfDataSize >= elfSectionNamesTableMaxIdx";
                  }
                }
              }
              else {
                uVar9 = 0x1746;
                pcVar11 = "pElfHeader->shentsize == sizeof(LibosElf64SectionHeader)";
              }
            }
            else {
              uVar9 = 0x1743;
              pcVar11 = "pElfHeader->ident[4] == elfClass64";
            }
          }
          else {
            uVar9 = 0x1741;
            pcVar11 = "pElfHeader->ident[5] == elfLittleEndian";
          }
        }
        else {
          uVar9 = 0x173f;
          pcVar11 = "*(NvU32*)&pElfHeader->ident == elfMagicNumber";
        }
LAB_0037c090:
        nvCheckFailedNoLog(4,pcVar11,"src/kernel/gpu/gsp/kernel_gsp.c",uVar9);
      }
      return 0x25;
    }
    nvCheckFailedNoLog(4,"elfDataSize > 0","src/kernel/gpu/gsp/kernel_gsp.c",0x1734);
  }
  return 0x1f;
}


// ===== 0037c270 _kgspFwContainerVerifyVersion.isra.0 =====

int _kgspFwContainerVerifyVersion_isra_0(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long local_38;
  long local_30;
  
  iVar1 = _kgspFwContainerGetSection_isra_0(param_1,param_2,".fwversion",&local_30,&local_38);
  if (iVar1 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "_kgspFwContainerGetSection(pGpu, pKernelGsp, pElfData, elfDataSize, GSP_VERSION_SECTION_NAME, &pFwversionRaw, &fwversionSize)"
               ,"src/kernel/gpu/gsp/kernel_gsp.c",0x15d2);
    return iVar1;
  }
  if ((local_38 - 1U < 0x3f) && (*(char *)(local_30 + -1 + local_38) == '\0')) {
    lVar2 = portStringLength("595.71.05");
    if ((local_38 == lVar2 + 1) &&
       (iVar1 = portStringCompare(local_30,"595.71.05",lVar2), iVar1 == 0)) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x15eb,"_kgspFwContainerVerifyVersion",4,
                 "NVRM: %s version mismatch: got version %s, expected version %s\n",param_3,local_30
                 ,"595.71.05");
  }
  else {
    lVar2 = portStringLength("595.71.05");
    if ((local_38 == lVar2 + 1) &&
       (iVar1 = portStringCompare(local_30,"595.71.05",lVar2), iVar1 == 0)) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x15f0,"_kgspFwContainerVerifyVersion",4,
                 "NVRM: %s version unknown or malformed, expected version %s\n",param_3,"595.71.05")
    ;
  }
  return 0x25;
}


// ===== 0037c400 _kgspFreeBootBinaryImage.isra.0 =====

void _kgspFreeBootBinaryImage_isra_0(long param_1)

{
  bindataStorageReleaseData(*(undefined8 *)(param_1 + 0xb20));
  *(undefined8 *)(param_1 + 0xb20) = 0;
  if (*(long *)(param_1 + 0xb18) != 0) {
    memdescUnmap(*(undefined8 *)(param_1 + 0xb00),1,*(long *)(param_1 + 0xb18),
                 *(undefined8 *)(param_1 + 0xb08));
    *(undefined8 *)(param_1 + 0xb18) = 0;
    *(undefined8 *)(param_1 + 0xb08) = 0;
  }
  if (*(long *)(param_1 + 0xb00) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_1 + 0xb00));
    *(undefined8 *)(param_1 + 0xb00) = 0;
  }
  *(undefined4 *)(param_1 + 0xb10) = 0;
  return;
}


// ===== 0037c4a0 _kgspLogRpcHistoryEntry.isra.0 =====

void _kgspLogRpcHistoryEntry_isra_0(int param_1,uint *param_2,char param_3)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  
  uVar1 = *param_2;
  if (uVar1 == 0) {
    return;
  }
  uVar4 = *(ulong *)(param_2 + 8);
  uVar2 = *(ulong *)(param_2 + 6);
  if (uVar4 <= uVar2) {
    if (uVar1 < 0xe5) {
      pcVar6 = *(char **)(rpcName_40 + (ulong)uVar1 * 8);
    }
    else {
      pcVar6 = "Unknown";
      if (uVar1 - 0x1001 < 0x29) {
        pcVar6 = *(char **)(rpcName_40 + (ulong)(uVar1 - 0xf1a) * 8);
      }
    }
    nv_printf(0xffffffff,
              "NVRM:     %c%-4d %-4d %-21.21s %10u 0x%016llx 0x%016llx 0x%016llx 0x%016llx          %c\n"
              ,(-(uint)(param_1 == 0) & 0xfffffff3) + 0x2d,param_1,uVar1,pcVar6,param_2[1],
              *(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 4),uVar2,uVar4,
              (-(uint)(param_3 == '\0') & 0xffffffa7) + 0x79);
    return;
  }
  uVar3 = osGetTimestampFreq();
  if (uVar3 < 1000000) {
    nvAssertFailedNoLog("tsFreqUs > 0","src/kernel/gpu/gsp/kernel_gsp.c",0x770);
    uVar4 = 0;
    uVar5 = 0x75;
  }
  else {
    uVar4 = (uVar4 - uVar2) / (uVar3 / 1000000);
    uVar5 = 0x75;
    if (999999 < uVar4) {
      if (uVar4 < 10000000) {
        uVar5 = 0x6d;
        uVar4 = uVar4 / 1000;
      }
      else {
        uVar5 = 0x20;
        uVar4 = uVar4 / 1000000;
      }
    }
  }
  uVar1 = *param_2;
  if (uVar1 < 0xe5) {
    pcVar6 = *(char **)(rpcName_40 + (ulong)uVar1 * 8);
  }
  else {
    pcVar6 = "Unknown";
    if (uVar1 - 0x1001 < 0x29) {
      pcVar6 = *(char **)(rpcName_40 + (ulong)(uVar1 - 0xf1a) * 8);
    }
  }
  nv_printf(0xffffffff,
            "NVRM:     %c%-4d %-4d %-21.21s %10u 0x%016llx 0x%016llx 0x%016llx 0x%016llx %6llu%cs %c\n"
            ,(-(uint)(param_1 == 0) & 0xfffffff3) + 0x2d,param_1,uVar1,pcVar6,param_2[1],
            *(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6),
            *(undefined8 *)(param_2 + 8),uVar4,uVar5,(-(uint)(param_3 == '\0') & 0xffffffa7) + 0x79)
  ;
  return;
}


// ===== 0037c720 kgspLogRpcDebugInfoToProtobuf =====

void kgspLogRpcDebugInfoToProtobuf(long param_1,long param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  ulong uVar8;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  lVar7 = *(long *)(param_2 + 0x4d8);
  uVar5 = osGetTimestampFreq();
  if (uVar5 < 1000000) {
    nvAssertFailedNoLog("tsFreqUs > 0","src/kernel/gpu/gsp/kernel_gsp.c",0x7e7);
    return;
  }
  prbEncAddUInt32(param_4,&DAT_00c49bf8,*(undefined4 *)(param_1 + 0x7a4));
  iVar2 = prbEncNestedStart(param_4,&DAT_00c49c40);
  if (iVar2 != 0) {
    return;
  }
  _kgspGetActiveRpcDebugData(param_2,*(undefined4 *)(lVar7 + 0xc),&local_48,local_40);
  *(undefined8 *)(param_3 + 0x6a600) = local_48;
  iVar2 = prbEncNestedStart(param_4,&prb_fields_gsp_rpcdebuginfo);
  if (iVar2 != 0) goto LAB_0037c7ff;
  prbEncAddUInt64(param_4,0xc49d18,*(undefined4 *)(lVar7 + 0xc));
  uVar4 = *(uint *)(lVar7 + 0xc);
  if (uVar4 < 0xe5) {
LAB_0037cbfd:
    pcVar6 = *(char **)(rpcName_40 + (ulong)uVar4 * 8);
  }
  else {
    pcVar6 = "Unknown";
    if (uVar4 - 0x1001 < 0x29) {
      uVar4 = uVar4 - 0xf1a;
      goto LAB_0037cbfd;
    }
  }
  prbEncAddString(param_4,0xc49d30,pcVar6);
  prbEncAddUInt64(param_4,0xc49d48,local_48);
  prbEncAddUInt64(param_4,0xc49d60,local_40[0]);
  prbEncNestedEnd(param_4);
LAB_0037c7ff:
  iVar2 = prbEncNestedStart(param_4,&DAT_00c49c78);
  if (iVar2 == 0) {
    lVar7 = 0;
    do {
      while( true ) {
        iVar2 = *(int *)(param_2 + 0x1918);
        iVar3 = prbEncNestedStart(param_4,prb_fields_gsp_rpchistorycputogsp);
        if (iVar3 != 0) break;
        prbEncAddUInt64(param_4,prb_fields_gsp_rpcentry,lVar7);
        uVar8 = (ulong)(iVar2 - (int)lVar7 & 0x7f);
        lVar1 = param_2 + uVar8 * 0x28;
        prbEncAddUInt64(param_4,0xc49d18,*(undefined4 *)(lVar1 + 0x518));
        uVar4 = *(uint *)(lVar1 + 0x518);
        if (uVar4 < 0xe5) {
LAB_0037cafd:
          pcVar6 = *(char **)(rpcName_40 + (ulong)uVar4 * 8);
        }
        else {
          pcVar6 = "Unknown";
          if (uVar4 - 0x1001 < 0x29) {
            uVar4 = uVar4 - 0xf1a;
            goto LAB_0037cafd;
          }
        }
        prbEncAddString(param_4,0xc49d30,pcVar6);
        lVar1 = param_2 + uVar8 * 0x28;
        prbEncAddUInt32(param_4,0xc49dc0,*(undefined4 *)(lVar1 + 0x51c));
        prbEncAddUInt64(param_4,0xc49d48,*(undefined8 *)(lVar1 + 0x520));
        prbEncAddUInt64(param_4,0xc49d60,*(undefined8 *)(lVar1 + 0x528));
        prbEncAddUInt64(param_4,0xc49d78,*(undefined8 *)(lVar1 + 0x530));
        prbEncAddUInt64(param_4,0xc49d90,*(undefined8 *)(lVar1 + 0x538));
        if (*(ulong *)(lVar1 + 0x530) < *(ulong *)(lVar1 + 0x538)) {
          prbEncAddUInt64(param_4,0xc49da8,
                          (*(ulong *)(lVar1 + 0x538) - *(ulong *)(lVar1 + 0x530)) /
                          (uVar5 / 1000000));
        }
        lVar7 = lVar7 + 1;
        prbEncNestedEnd(param_4);
        if (lVar7 == 8) goto LAB_0037c95a;
      }
      lVar7 = lVar7 + 1;
    } while (lVar7 != 8);
LAB_0037c95a:
    prbEncNestedEnd(param_4);
  }
  iVar2 = prbEncNestedStart(param_4,&DAT_00c49c90);
  if (iVar2 == 0) {
    lVar7 = 0;
    do {
      while( true ) {
        iVar2 = *(int *)(param_2 + 0x2d20);
        iVar3 = prbEncNestedStart(param_4,prb_fields_gsp_rpchistorygsptocpu);
        if (iVar3 != 0) break;
        prbEncAddUInt64(param_4,prb_fields_gsp_rpcentry,lVar7);
        uVar8 = (ulong)(iVar2 - (int)lVar7 & 0x7f);
        lVar1 = param_2 + uVar8 * 0x28;
        prbEncAddUInt64(param_4,0xc49d18,*(undefined4 *)(lVar1 + 0x1920));
        uVar4 = *(uint *)(lVar1 + 0x1920);
        if (uVar4 < 0xe5) {
LAB_0037cae5:
          pcVar6 = *(char **)(rpcName_40 + (ulong)uVar4 * 8);
        }
        else {
          pcVar6 = "Unknown";
          if (uVar4 - 0x1001 < 0x29) {
            uVar4 = uVar4 - 0xf1a;
            goto LAB_0037cae5;
          }
        }
        prbEncAddString(param_4,0xc49d30,pcVar6);
        lVar1 = param_2 + uVar8 * 0x28;
        prbEncAddUInt32(param_4,0xc49dc0,*(undefined4 *)(lVar1 + 0x1924));
        prbEncAddUInt64(param_4,0xc49d48,*(undefined8 *)(lVar1 + 0x1928));
        prbEncAddUInt64(param_4,0xc49d60,*(undefined8 *)(lVar1 + 0x1930));
        prbEncAddUInt64(param_4,0xc49d78,*(undefined8 *)(lVar1 + 0x1938));
        prbEncAddUInt64(param_4,0xc49d90,*(undefined8 *)(lVar1 + 0x1940));
        if (*(ulong *)(lVar1 + 0x1938) < *(ulong *)(lVar1 + 0x1940)) {
          prbEncAddUInt64(param_4,0xc49da8,
                          (*(ulong *)(lVar1 + 0x1940) - *(ulong *)(lVar1 + 0x1938)) /
                          (uVar5 / 1000000));
        }
        lVar7 = lVar7 + 1;
        prbEncNestedEnd(param_4);
        if (lVar7 == 8) goto LAB_0037caba;
      }
      lVar7 = lVar7 + 1;
    } while (lVar7 != 8);
LAB_0037caba:
    prbEncNestedEnd(param_4);
  }
  prbEncNestedEnd(param_4);
  return;
}


// ===== 0037cc10 kgspLogRpcDebugInfo =====

void kgspLogRpcDebugInfo(long param_1,long param_2,undefined8 param_3,char param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar5 = *(long *)(param_2 + 0x4d8);
  uVar4 = (ulong)*(uint *)(lVar5 + 0xc);
  _kgspGetActiveRpcDebugData(param_2,uVar4,&local_38,&local_30);
  uVar7 = (uint)uVar4;
  if (uVar7 < 0xe5) {
    pcVar6 = *(char **)(rpcName_40 + (uVar4 & 0xffffffff) * 8);
  }
  else {
    pcVar6 = "Unknown";
    if (uVar7 - 0x1001 < 0x29) {
      pcVar6 = *(char **)(rpcName_40 + (ulong)(uVar7 - 0xf1a) * 8);
    }
  }
  nv_printf(0xffffffff,
            "NVRM: GPU%d GSP RPC buffer contains function %d (%s) sequence %u and data 0x%016llx 0x%016llx.\n"
            ,*(undefined4 *)(param_1 + 0x7a4),uVar4 & 0xffffffff,pcVar6,
            *(undefined4 *)(lVar5 + 0x18),local_38,local_30);
  nv_printf(0xffffffff,"NVRM: GPU%d RPC history (CPU -> GSP):\n",*(undefined4 *)(param_1 + 0x7a4));
  nv_printf(0xffffffff,
            "NVRM:     entry function                     sequence data0              data1              ts_start           ts_end             duration actively_polling\n"
           );
  iVar8 = 0;
  do {
    iVar9 = iVar8 + 1;
    _kgspLogRpcHistoryEntry_isra_0
              (iVar8,param_2 + 0x518 + (ulong)(*(int *)(param_2 + 0x1918) - iVar8 & 0x7f) * 0x28,
               iVar8 == 0 && param_4 != '\0');
    iVar8 = iVar9;
  } while (iVar9 != 8);
  nv_printf(0xffffffff,"NVRM: GPU%d RPC event history (CPU <- GSP):\n",
            *(undefined4 *)(param_1 + 0x7a4));
  nv_printf(0xffffffff,
            "NVRM:     entry function                     sequence data0              data1              ts_start           ts_end             duration during_incomplete_rpc\n"
           );
  iVar8 = 0;
  do {
    uVar4 = (ulong)(*(int *)(param_2 + 0x2d20) - iVar8 & 0x7f);
    uVar1 = *(uint *)(param_2 + 0x1918);
    uVar7 = uVar1 - 0x80;
    do {
      uVar2 = (ulong)(uVar1 & 0x7f);
      if (((*(int *)(param_2 + 0x518 + uVar2 * 0x28) != 0) &&
          (*(ulong *)(param_2 + 0x530 + uVar2 * 0x28) <= *(ulong *)(param_2 + 0x1938 + uVar4 * 0x28)
          )) && (*(long *)(param_2 + 0x538 + uVar2 * 0x28) == 0)) {
        uVar3 = 1;
        goto LAB_0037cdb4;
      }
      uVar1 = uVar1 - 1;
    } while (uVar7 != uVar1);
    uVar3 = 0;
LAB_0037cdb4:
    iVar9 = iVar8 + 1;
    _kgspLogRpcHistoryEntry_isra_0(iVar8,param_2 + 0x1920 + uVar4 * 0x28,uVar3);
    iVar8 = iVar9;
    if (iVar9 == 8) {
      return;
    }
  } while( true );
}


// ===== 0037ce0e kgspInitVgpuPartitionLogging_IMPL.cold =====

void kgspInitVgpuPartitionLogging_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0037ce20 kgspInitVgpuPartitionLogging_IMPL =====

ulong kgspInitVgpuPartitionLogging_IMPL
                (long param_1,long param_2,uint param_3,undefined8 param_4,long param_5,
                undefined8 param_6,long param_7,undefined8 param_8,long param_9)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  undefined **ppuVar6;
  uint *puVar7;
  ulong uVar8;
  bool bVar9;
  bool bVar10;
  undefined1 local_84 [4];
  undefined1 local_80 [8];
  uint local_78 [2];
  undefined8 local_70;
  long local_68;
  long local_60;
  undefined4 local_58;
  undefined8 local_50;
  long local_48;
  long local_40;
  uint local_38 [2];
  
  local_60 = param_2 + 0x68cc8;
  local_40 = param_2 + 0x692c8;
  local_78[0] = 0;
  local_58 = 3;
  if (0x30 < param_3) {
    return 0x1f;
  }
  lVar3 = *(long *)(param_1 + 0x1b88);
  piVar1 = (int *)(param_2 + 0x69ef0);
  LOCK();
  bVar10 = *piVar1 == 0;
  if (bVar10) {
    *piVar1 = 1;
  }
  UNLOCK();
  local_70 = param_4;
  local_68 = param_5;
  local_50 = param_6;
  local_48 = param_7;
  while (!bVar10) {
    osSpinLoop();
    LOCK();
    bVar10 = *piVar1 == 0;
    if (bVar10) {
      *piVar1 = 1;
    }
    UNLOCK();
  }
  puVar7 = local_78;
  nvDbgSnprintf(local_84,4,"V%02d",param_3);
  lVar2 = param_2 + 0x2d48 + (ulong)(param_3 - 1) * 0x21f8;
  libosLogCreateEx(lVar2,local_84);
  do {
    if (7 < *puVar7) goto LAB_0037d0e9;
    lVar5 = (ulong)*puVar7 * 0x20;
    uVar4 = _setupLogBufferVgpu_constprop_0_isra_0
                      (param_1,param_2,param_3,*(undefined8 *)(infos_38 + lVar5),
                       *(undefined8 *)(infos_38 + lVar5 + 8),
                       *(undefined8 *)(infos_38 + lVar5 + 0x10),*(undefined8 *)(puVar7 + 2),
                       *(undefined8 *)(puVar7 + 4),*(undefined8 *)(puVar7 + 6));
    if (uVar4 != 0) {
      uVar8 = (ulong)uVar4;
      goto LAB_0037d0ef;
    }
    puVar7 = puVar7 + 8;
  } while (puVar7 != local_38);
  ppuVar6 = &infos_37;
  while( true ) {
    bVar10 = *(uint *)(ppuVar6 + 1) <= *(uint *)(param_1 + 0x808);
    if (*(uint *)((long)ppuVar6 + 0xc) != 0) {
      bVar10 = bVar10 && *(uint *)(param_1 + 0x808) <= *(uint *)((long)ppuVar6 + 0xc);
    }
    bVar9 = *(uint *)(ppuVar6 + 2) <= *(uint *)(param_1 + 0x80c);
    if (*(uint *)((long)ppuVar6 + 0x14) != 0) {
      bVar9 = bVar9 && *(uint *)(param_1 + 0x80c) <= *(uint *)((long)ppuVar6 + 0x14);
    }
    if ((bool)(bVar9 & bVar10)) break;
    ppuVar6 = ppuVar6 + 3;
    if (ppuVar6 == (undefined **)&DAT_00d3de30) {
      uVar8 = kgspInitVgpuPartitionLogging_IMPL_cold();
      return uVar8;
    }
  }
  if (*ppuVar6 == (undefined *)0x0) {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xcdd,"kgspInitVgpuPartitionLogging_IMPL",3,
                 "NVRM: Unknown chip for libos kernel logging\n");
LAB_0037d0e9:
    uVar8 = 0x40;
  }
  else {
    uVar4 = _setupLogBufferVgpu_constprop_0_isra_0
                      (param_1,param_2,param_3,"LOGKRNL",&DAT_00d39690,*ppuVar6,param_8,param_9,
                       param_2 + 0x698c8);
    uVar8 = (ulong)uVar4;
    nvDbgSnprintf(local_80,8,&DAT_00d38f87,&DAT_00d3969d,param_3);
    libosLogSetupMergedNvlog
              (lVar2,*(undefined4 *)(param_1 + 0x7a4),param_7 + param_9 + param_5,local_80,
               *(uint *)(param_1 + 0x808) >> 4,*(undefined4 *)(param_1 + 0x80c),
               *(undefined8 *)(param_2 + 0x69ee0));
    if (uVar4 == 0) {
      libosLogInit(lVar2,*(undefined8 *)(param_2 + 0x69ed0),*(undefined8 *)(param_2 + 0x69ed8));
      portStringCopy(lVar2,4,&DAT_00d396a2,4);
      *(undefined1 *)(param_2 + 0x69ec8) = 1;
      libosLogUpdateTimerDelta(lVar2,*(undefined8 *)(lVar3 + 0x24f8));
      goto LAB_0037d0fd;
    }
  }
LAB_0037d0ef:
  _kgspFreeLibosVgpuPartitionLoggingStructures(param_1,param_2,param_3);
LAB_0037d0fd:
  LOCK();
  if (*piVar1 == 1) {
    *piVar1 = 0;
  }
  UNLOCK();
  return uVar8;
}


// ===== 0037d170 kgspStateInitLocked_IMPL =====

undefined8 kgspStateInitLocked_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x1ce0) != 0) {
    nvdEngineSignUp_IMPL(param_1,*(long *)(param_1 + 0x1ce0),_kgspDumpEngineFunc,0x1e,7,param_1);
    return 0;
  }
  return 0;
}


// ===== 0037d1b0 kgspSendInitRpcs_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong kgspSendInitRpcs_IMPL(undefined8 param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = gpuGetRpc();
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x11fe);
    uVar1 = 0x1a;
  }
  else {
    uVar1 = (**(code **)(lVar2 + 0x130))(param_1,lVar2,*(code **)(lVar2 + 0x130));
    if (uVar1 == 0) {
      lVar2 = gpuGetRpc(param_1);
      if (lVar2 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x1205);
        uVar3 = 0x1a;
      }
      else {
        uVar3 = (**(code **)(lVar2 + 0x2b0))(param_1,lVar2,*(code **)(lVar2 + 0x2b0));
        if ((int)uVar3 == 0) {
          return uVar3;
        }
      }
      nvAssertOkFailedNoLog
                (uVar3 & 0xffffffff,"NV_RM_RPC_SET_REGISTRY","src/kernel/gpu/gsp/kernel_gsp.c",
                 0x1208);
      return uVar3 & 0xffffffff;
    }
  }
  nvAssertOkFailedNoLog
            (uVar1,"NV_RM_RPC_GSP_SET_SYSTEM_INFO","src/kernel/gpu/gsp/kernel_gsp.c",0x1201);
  return (ulong)uVar1;
}


// ===== 0037d2b0 kgspDumpGspLogs_IMPL =====

ulong kgspDumpGspLogs_IMPL(long param_1,char param_2)

{
  uint *puVar1;
  ulong in_RAX;
  ulong uVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  
  if ((((*(char *)(param_1 + 0x69efc) == '\0') && (*(long *)(param_1 + 0x69ed0) == 0)) &&
      (param_2 == '\0')) && (*(char *)(param_1 + 0x69ec8) == '\0')) {
    return in_RAX;
  }
  puVar1 = (uint *)(param_1 + 0x69ef0);
  LOCK();
  bVar5 = *puVar1 == 0;
  if (bVar5) {
    *puVar1 = 1;
  }
  UNLOCK();
  while( true ) {
    if (bVar5) {
      libosExtractLogs(param_1 + 0xb50,param_2);
      if (*(char *)(param_1 + 0x69ec8) != '\0') {
        lVar3 = param_1 + 0x2d48;
        do {
          lVar4 = lVar3 + 0x21f8;
          libosExtractLogs(lVar3,param_2);
          lVar3 = lVar4;
        } while (lVar4 != param_1 + 0x68bc8);
      }
      uVar2 = 1;
      LOCK();
      if (*puVar1 == 1) {
        *puVar1 = 0;
      }
      else {
        uVar2 = (ulong)*puVar1;
      }
      UNLOCK();
      return uVar2;
    }
    uVar2 = osIsRaisedIRQL();
    if ((char)uVar2 != '\0') break;
    osSpinLoop();
    LOCK();
    bVar5 = *puVar1 == 0;
    if (bVar5) {
      *puVar1 = 1;
    }
    UNLOCK();
  }
  return uVar2;
}


