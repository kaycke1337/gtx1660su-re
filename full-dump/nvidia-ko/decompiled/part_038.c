// ===== 0041e5f0 knvlinkTrainFabricLinksToActive_IMPL =====

undefined8 knvlinkTrainFabricLinksToActive_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  undefined1 local_30 [8];
  
  if ((*(char *)(param_1 + 0x4911) != '\0') && (*(char *)(param_2 + 0x15fc) == '\0')) {
    return 0;
  }
  if (*(char *)(param_2 + 0x15fa) == '\0') {
    if (*(char *)(g_pSys + 0x6b) == '\0') {
      cVar2 = knvlinkIsForcedConfig_IMPL();
      if (cVar2 == '\0') {
        bitVectorCopy_IMPL(local_30,0x40,param_2 + 0x388,0x40);
        uVar3 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
        while( true ) {
          uVar5 = (ulong)uVar3;
          cVar2 = bitVectorTestAllCleared_IMPL(local_30,0x40);
          if (cVar2 != '\0') break;
          lVar1 = param_2 + uVar5 * 0x78;
          if (((*(char *)(lVar1 + 0x400) != '\0') && (*(long *)(lVar1 + 0x3f0) == 3)) &&
             (iVar4 = nvlink_lib_train_links_from_swcfg_to_active
                                (param_2 + 0x3c8 + uVar5 * 0x78,1,1), iVar4 != 0)) {
            nvErrorLog_va(param_1,0x4a,
                          "NVLink: failed to train link %d to remote PCI:%04x:%02x:%02x",uVar5,
                          *(undefined4 *)(lVar1 + 0x3d0),*(undefined2 *)(lVar1 + 0x3d4),
                          *(undefined2 *)(lVar1 + 0x3d6));
            gpuNotifySubDeviceEvent_IMPL(param_1,0x7b,0,0,0,0);
            return 0x40;
          }
          bitVectorClr_IMPL(local_30,0x40,uVar5);
          uVar3 = bitVectorCountTrailingZeros_IMPL(local_30,0x40);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x37a,
                     "knvlinkTrainFabricLinksToActive_IMPL",1,
                     "NVRM: Nvlink in Forced Config - skip link training.\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x372,
                   "knvlinkTrainFabricLinksToActive_IMPL",1,
                   "NVRM: Fabric is externally managed, skip link training\n");
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x368,
                 "knvlinkTrainFabricLinksToActive_IMPL",1,
                 "NVRM: Skipping link training due to regkey on GPU%d\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  return 0;
}


// ===== 0041e800 knvlinkEnterExitSleep_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int knvlinkEnterExitSleep_IMPL(long param_1,long param_2,undefined8 *param_3,char param_4)

{
  long lVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  long lVar8;
  char *pcVar9;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  undefined4 local_b4;
  undefined1 local_b0 [8];
  undefined1 local_a8 [8];
  undefined4 local_a0;
  undefined1 local_9c;
  ulong local_98;
  undefined1 local_90 [8];
  undefined1 local_88 [16];
  ulong local_78 [9];
  
  if (*(char *)(param_2 + 0x2e1) == '\0') {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x3ba,
                 "knvlinkEnterExitSleep_IMPL",4,"NVRM: NVLink L2 is not supported. Returning\n");
    return 0x56;
  }
  if (*(char *)(g_pSys + 0x6b) == '\0') {
    bitVectorCopy_IMPL(local_78,0x40,param_3,0x40);
    uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
    while( true ) {
      uVar11 = (ulong)uVar6;
      cVar3 = bitVectorTestAllCleared_IMPL(local_78,0x40);
      if (cVar3 != '\0') break;
      if (*(char *)(param_2 + 0x400 + uVar11 * 0x78) == '\0') {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x3d3,
                     "knvlinkEnterExitSleep_IMPL",4,
                     "NVRM: GPU%d: Link%d is not connected. Returning\n",
                     *(undefined4 *)(param_1 + 0x7a4),uVar11);
        return 0x56;
      }
      bitVectorClr_IMPL(local_78,0x40,uVar11);
      uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
    }
    if (*(uint *)(param_2 + 0x314) < 5) {
      bitVectorCopy_IMPL(local_78,0x40,param_3,0x40);
      uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
      while( true ) {
        cVar3 = bitVectorTestAllCleared_IMPL(local_78,0x40);
        if (cVar3 != '\0') break;
        lVar12 = param_2 + (ulong)uVar6 * 0x78;
        if (*(byte *)(lVar12 + 0x42c) == uVar6) {
          if (((*(char *)(lVar12 + 0x42d) != '$') &&
              (cVar3 = bitVectorTest_IMPL(param_2 + 0x388,0x40), cVar3 != '\0')) &&
             (cVar3 = bitVectorTest_IMPL(param_3,0x40,*(undefined1 *)(lVar12 + 0x42d)),
             cVar3 == '\0')) {
            pcVar9 = "NVRM: GPU%d: Links sharing PLL should enter/exit L2 together. Returning\n";
            uVar10 = 0x3e9;
            uVar7 = *(undefined4 *)(param_1 + 0x7a4);
            goto LAB_0041f235;
          }
        }
        else {
          cVar3 = bitVectorTest_IMPL(param_2 + 0x388,0x40);
          if ((cVar3 != '\0') &&
             (cVar3 = bitVectorTest_IMPL(param_3,0x40,*(undefined1 *)(lVar12 + 0x42c)),
             cVar3 == '\0')) {
            pcVar9 = "NVRM: GPU%d: Links sharing PLL should enter/exit L2 together. Returning\n";
            uVar10 = 0x3f6;
            uVar7 = *(undefined4 *)(param_1 + 0x7a4);
            goto LAB_0041f235;
          }
        }
        bitVectorClr_IMPL(local_78,0x40,(ulong)uVar6);
        uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
      }
    }
    lVar12 = g_pSys;
    if (*(long *)(param_2 + 0x15d0) == 0) {
      pcVar9 = "NVRM: GPU%d: not registered in core lib. Returning\n";
      uVar10 = 0x404;
      uVar7 = *(undefined4 *)(param_1 + 0x7a4);
LAB_0041f235:
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",uVar10,
                   "knvlinkEnterExitSleep_IMPL",4,pcVar9,uVar7);
      return 0x56;
    }
  }
  else {
    lVar12 = g_pSys;
    if (*(uint *)(param_2 + 0x314) < 8) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x3c8,
                   "knvlinkEnterExitSleep_IMPL",4,
                   "NVRM: Skipping L2 entry/exit since fabric is externally managed\n");
      return 0x56;
    }
  }
  g_pSys = lVar12;
  if (param_4 == '\0') {
    *(undefined1 *)(param_2 + 0x15f9) = 0;
    if (*(char *)(param_2 + 0x15ff) == '\0') {
      iVar4 = convertBitVectorToLinkMasks(param_3,&local_b4,4,0);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "convertBitVectorToLinkMasks(pLinkMask, &localLinkMask, sizeof(localLinkMask), NULL)"
                   ,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x861);
        return iVar4;
      }
      iVar4 = nvlink_lib_train_links_from_L2_to_active(*(undefined8 *)(param_2 + 0x15d0),local_b4,0)
      ;
    }
    else {
      iVar4 = 0;
      bitVectorCopy_IMPL(local_78,0x40,param_3,0x40);
      uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
      while( true ) {
        uVar11 = (ulong)uVar6;
        cVar3 = bitVectorTestAllCleared_IMPL(local_78,0x40);
        if (cVar3 != '\0') break;
        iVar4 = knvlinkTrainLinksToActiveAli_IMPL(param_1,param_2,1 << ((byte)uVar6 & 0x1f),0);
        if (iVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x83b,"_knvlinkExitSleep"
                       ,4,"NVRM: Failed to request Link %d to transition to active\n",uVar11);
        }
        *(undefined1 *)(*(long *)(param_2 + 0x3c8 + uVar11 * 0x78) + 0x60) = 0;
        bitVectorClr_IMPL(local_78,0x40,uVar11);
        uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
      }
      iVar5 = (**(code **)(param_2 + 0x230))(param_1,param_2,param_1);
      if (iVar5 == 0) {
        uVar7 = 0;
        if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
          uVar7 = 5;
        }
        timeoutSet(param_1 + 0x1af0,local_90,10000000,uVar7);
        do {
          iVar4 = timeoutCheck(param_1 + 0x1af0,local_90,0x84f);
          iVar5 = knvlinkCheckTrainingIsComplete_IMPL(param_1,param_1,param_2);
          if (iVar5 == 0) {
            if (iVar4 != 0x65) goto LAB_0041e964;
            break;
          }
          osSpinLoop();
        } while (iVar4 != 0x65);
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x85b,"_knvlinkExitSleep",4
                     ,"NVRM: Timedout while checking to see if training complete!\n");
        goto LAB_0041e977;
      }
    }
LAB_0041e964:
    if (iVar4 == 0) {
      bitVectorCopy_IMPL(local_78,0x40,param_3,0x40);
      uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
      while( true ) {
        cVar3 = bitVectorTestAllCleared_IMPL(local_78,0x40);
        if (cVar3 != '\0') break;
        iVar4 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,1 << ((byte)uVar6 & 0x1f));
        if (iVar4 != 0) {
          return iVar4;
        }
        knvlinkUpdateCurrentConfig_IMPL(param_1,param_2);
        lVar12 = (ulong)uVar6 * 0x78;
        if (*(long *)(param_2 + 0x3f0 + lVar12) == 2) {
          lVar8 = gpumgrGetGpu(0);
          iVar4 = 0;
          if (lVar8 != 0) goto LAB_0041ef3e;
          do {
            do {
              iVar4 = iVar4 + 1;
              if (iVar4 == 0x20) goto LAB_0041ee90;
              lVar8 = gpumgrGetGpu(iVar4);
            } while (lVar8 == 0);
LAB_0041ef3e:
            uVar10 = *(undefined8 *)(lVar8 + 0x878);
            lVar1 = param_2 + lVar12;
          } while (((*(int *)(lVar1 + 0x3d0) != (int)((ulong)uVar10 >> 0x20)) ||
                   (*(ushort *)(lVar1 + 0x3d4) != ((ushort)((ulong)uVar10 >> 8) & 0xff))) ||
                  ((*(ushort *)(lVar1 + 0x3d6) != ((ushort)uVar10 & 0xff) ||
                   (*(short *)(lVar1 + 0x3d8) != 0))));
          lVar12 = *(long *)(lVar8 + 0x1ce8);
          iVar4 = (**(code **)(lVar12 + 0x1b8))
                            (lVar8,lVar12,1 << ((byte)*(undefined4 *)(lVar1 + 0x3f8) & 0x1f));
          if (iVar4 != 0) {
            return iVar4;
          }
          knvlinkUpdateCurrentConfig_IMPL(lVar8,lVar12);
        }
LAB_0041ee90:
        bitVectorClr_IMPL(local_78,0x40,(ulong)uVar6);
        uVar6 = bitVectorCountTrailingZeros_IMPL(local_78,0x40);
      }
      portMemSet(local_78,0,0x18);
      iVar4 = convertBitVectorToLinkMasks(param_3,0,0,local_78 + 1);
      uVar10 = 0x8a4;
      pcVar9 = 
      "convertBitVectorToLinkMasks(pLinkMask, NULL, 0, &saveRestoreHshubStateParams.linkMask)";
      if (iVar4 == 0) {
        local_78[0] = local_78[0] & 0xffffffffffffff00;
        iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a62,local_78,0x18);
        if (iVar4 != 0) {
          return iVar4;
        }
        knvlinkUpdateCurrentConfig_IMPL(param_1,param_2);
        portMemSet(&local_a0,0,0x10);
        local_9c = 0;
        local_a0 = 2;
        iVar4 = convertBitVectorToLinkMasks(param_3,&local_98,8,0);
        if (iVar4 == 0) {
          iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a64,&local_a0,0x10);
          if (iVar4 != 0) {
            return iVar4;
          }
          bitVectorCopy_IMPL(local_b0,0x40,param_3,0x40);
          uVar6 = bitVectorCountTrailingZeros_IMPL(local_b0,0x40);
          do {
            cVar3 = bitVectorTestAllCleared_IMPL(local_b0,0x40);
            if (cVar3 != '\0') {
              return 0;
            }
            if (*(long *)(param_2 + 0x3f0 + (ulong)uVar6 * 0x78) == 2) {
              iVar4 = 0;
              do {
                lVar12 = gpumgrGetGpu(iVar4);
                if (lVar12 != 0) {
                  lVar8 = param_2 + (ulong)uVar6 * 0x78;
                  if ((((*(int *)(lVar8 + 0x3d0) ==
                         (int)((ulong)*(undefined8 *)(lVar12 + 0x878) >> 0x20)) &&
                       (uVar2 = (ushort)*(undefined8 *)(lVar12 + 0x878),
                       *(ushort *)(lVar8 + 0x3d4) == uVar2 >> 8)) &&
                      (*(ushort *)(lVar8 + 0x3d6) == (uVar2 & 0xff))) &&
                     (*(short *)(lVar8 + 0x3d8) == 0)) {
                    uVar7 = *(undefined4 *)(lVar8 + 0x3f8);
                    uVar10 = *(undefined8 *)(lVar12 + 0x1ce8);
                    portMemSet(local_78,0,0x18);
                    bitVectorSet_IMPL(local_a8,0x40,uVar7);
                    iVar4 = convertBitVectorToLinkMasks(local_a8,0,0,local_78 + 1);
                    if (iVar4 != 0) {
                      nvCheckOkFailedNoLog
                                (4,iVar4,
                                 "convertBitVectorToLinkMasks(&remoteLinkMask, NULL, 0, &saveRestoreHshubStateParams.linkMask)"
                                 ,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x8d9);
                      return iVar4;
                    }
                    local_78[0] = local_78[0] & 0xffffffffffffff00;
                    iVar4 = knvlinkExecGspRmRpc_IMPL(lVar12,uVar10,0x20800a62,local_78,0x18);
                    if (iVar4 != 0) {
                      return iVar4;
                    }
                    knvlinkUpdateCurrentConfig_IMPL(lVar12,uVar10);
                    portMemSet(&local_a0,0,0x10);
                    local_98 = (ulong)(uint)(1 << ((byte)uVar7 & 0x1f));
                    local_9c = 0;
                    local_a0 = 2;
                    iVar4 = knvlinkExecGspRmRpc_IMPL(lVar12,uVar10,0x20800a64,&local_a0,0x10);
                    if (iVar4 != 0) {
                      return iVar4;
                    }
                    break;
                  }
                }
                iVar4 = iVar4 + 1;
              } while (iVar4 != 0x20);
            }
            bitVectorClr_IMPL(local_b0,0x40,uVar6);
            uVar6 = bitVectorCountTrailingZeros_IMPL(local_b0,0x40);
          } while( true );
        }
        uVar10 = 0x8b5;
        pcVar9 = 
        "convertBitVectorToLinkMasks(pLinkMask, &programBufferRdyParams.peerLinkMask, sizeof(programBufferRdyParams.peerLinkMask), NULL)"
        ;
      }
      nvCheckOkFailedNoLog
                (4,iVar4,pcVar9,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",uVar10);
    }
    else {
      if (iVar4 != 10) {
LAB_0041e977:
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x90a,"_knvlinkExitSleep",4
                     ,"NVRM: Unable to wakeup the linkmask 0x%llx of GPU%d from SLEEP\n",*param_3,
                     *(undefined4 *)(param_1 + 0x7a4));
        return 0xffff;
      }
      iVar4 = 0x10005;
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x901,"_knvlinkExitSleep",1,
                   "NVRM: Transition to L0 for GPU%d: linkMask 0x%llx in progress... Waiting for remote endpoints to request L2 exit\n"
                   ,*(undefined4 *)(param_1 + 0x7a4),*param_3);
    }
  }
  else {
    portMemSet(&local_a0,0,0x10);
    local_9c = 0;
    local_a0 = 1;
    iVar4 = convertBitVectorToLinkMasks(param_3,&local_98,8,0);
    uVar10 = 0x7b7;
    pcVar9 = 
    "convertBitVectorToLinkMasks(pLinkMask, &programBufferRdyParams.peerLinkMask, sizeof(programBufferRdyParams.peerLinkMask), NULL)"
    ;
    if (iVar4 == 0) {
      iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a64,&local_a0,0x10);
      if (iVar4 != 0) {
        return iVar4;
      }
      portMemSet(local_90,0,0x18);
      iVar4 = convertBitVectorToLinkMasks(param_3,0,0,local_88);
      if (iVar4 == 0) {
        local_90[0] = 1;
        iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a62,local_90,0x18);
        if (iVar4 != 0) {
          return iVar4;
        }
        *(undefined1 *)(param_2 + 0x15f9) = 1;
        if ((7 < *(uint *)(param_2 + 0x314)) && (*(char *)(lVar12 + 0x6b) != '\0')) {
          local_78[0] = 0;
          local_78[2] = 0;
          local_78[3] = 0;
          local_78[4] = 0;
          local_78[5] = 0;
          local_78[6] = 0;
          local_78[7] = 0;
          local_78[1] = 3;
          bitVectorCopy_IMPL(local_a8,0x40,param_3,0x40);
          uVar7 = bitVectorCountTrailingZeros_IMPL(local_a8,0x40);
          while (cVar3 = bitVectorTestAllCleared_IMPL(local_a8,0x40), cVar3 == '\0') {
            local_78[0] = CONCAT44(local_78[0]._4_4_,uVar7);
            local_78[2] = 10;
            iVar4 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a24,local_78,0x40);
            if (iVar4 != 0) {
              nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x7ea,
                           "_knvlinkEnterSleep",4,"NVRM: Error setting link: %d to sleep!\n",uVar7);
            }
            bitVectorClr_IMPL(local_a8,0x40,uVar7);
            uVar7 = bitVectorCountTrailingZeros_IMPL(local_a8,0x40);
          }
          return 0;
        }
        iVar4 = convertBitVectorToLinkMasks(param_3,local_78,4,0);
        uVar10 = 0x7f2;
        pcVar9 = "convertBitVectorToLinkMasks(pLinkMask, &linkMask, sizeof(linkMask), NULL)";
        if (iVar4 == 0) {
          iVar4 = nvlink_lib_powerdown_links_from_active_to_L2
                            (*(undefined8 *)(param_2 + 0x15d0),local_78[0] & 0xffffffff,0);
          if (iVar4 == 10) {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x7fa,
                         "_knvlinkEnterSleep",1,
                         "NVRM: Transition to L2 for GPU%d: linkMask 0x%x in progress... Waiting for remote endpoints to request L2 entry\n"
                         ,*(undefined4 *)(param_1 + 0x7a4),local_78[0] & 0xffffffff);
            return 0x10005;
          }
          if (iVar4 == 0) {
            return 0;
          }
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x804,
                       "_knvlinkEnterSleep",4,
                       "NVRM: Unable to put the linkmask 0x%x of GPU%d to SLEEP\n",
                       local_78[0] & 0xffffffff,*(undefined4 *)(param_1 + 0x7a4));
          return 0xffff;
        }
      }
      else {
        uVar10 = 0x7c4;
        pcVar9 = 
        "convertBitVectorToLinkMasks(pLinkMask, NULL, 0, &saveRestoreHshubStateParams.linkMask)";
      }
    }
    nvCheckOkFailedNoLog(4,iVar4,pcVar9,"src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",uVar10);
  }
  return iVar4;
}


// ===== 0041f720 knvlinkCoreShutdownDeviceLinks_IMPL =====

undefined8 knvlinkCoreShutdownDeviceLinks_IMPL(long param_1,long param_2,char param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  undefined1 local_150 [8];
  undefined8 local_148 [36];
  
  memset(local_148,0,0x120);
  if (((*(uint *)(param_2 + 0x314) < 7) && (*(char *)(g_pSys + 0x6b) != '\0')) ||
     (*(long *)(param_2 + 0x15d0) == 0)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x43a,
                 "knvlinkCoreShutdownDeviceLinks_IMPL",1,
                 "NVRM: core lib device is either externally managed or not present, skipping\n");
  }
  else {
    cVar1 = bitVectorTestAllCleared_IMPL(param_2 + 0x388,0x40);
    if (cVar1 == '\0') {
      if ((param_3 == '\0') && (*(char *)(param_2 + 0x2ed) != '\0')) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",1099,
                     "knvlinkCoreShutdownDeviceLinks_IMPL",1,
                     "NVRM: GFW boot is enabled. Link shutdown is not required, skipping\n");
      }
      else {
        uVar6 = 0;
        bitVectorCopy_IMPL(local_150,0x40,param_2 + 0x388,0x40);
        uVar2 = bitVectorCountTrailingZeros_IMPL(local_150,0x40);
        while( true ) {
          uVar5 = (ulong)uVar2;
          cVar1 = bitVectorTestAllCleared_IMPL(local_150,0x40);
          if (cVar1 != '\0') break;
          if (*(char *)(param_2 + 0x2e5) == '\0') {
            nvlink_lib_powerdown_links_from_active_to_swcfg(param_2 + 0x3c8 + uVar5 * 0x78,1,1);
          }
          else {
            lVar4 = uVar5 * 0x78 + param_2;
            if ((*(long *)(lVar4 + 0x3f0) != 2) ||
               ((((lVar4 = gpumgrGetGpuFromBusInfo
                                     (*(undefined4 *)(lVar4 + 0x3d0),*(undefined1 *)(lVar4 + 0x3d4),
                                      *(undefined1 *)(lVar4 + 0x3d6)), lVar4 != 0 &&
                  (*(char *)(lVar4 + 0x44f) == '\0')) && (*(char *)(lVar4 + 0x450) == '\0')) &&
                ((*(char *)(lVar4 + 0x451) == '\0' && (*(char *)(lVar4 + 0x461) == '\0')))))) {
              local_148[uVar6] = *(undefined8 *)(param_2 + 0x3c8 + uVar5 * 0x78);
              uVar6 = (ulong)((int)uVar6 + 1);
            }
          }
          bitVectorClr_IMPL(local_150,0x40,uVar5);
          uVar2 = bitVectorCountTrailingZeros_IMPL(local_150,0x40);
        }
        if ((((int)uVar6 != 0) && (*(char *)(param_2 + 0x2e5) != '\0')) &&
           (iVar3 = nvlink_lib_powerdown_links_from_active_to_off(local_148,uVar6,1), iVar3 != 0)) {
          if (iVar3 != 3) {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x47e,
                         "knvlinkCoreShutdownDeviceLinks_IMPL",4,
                         "NVRM: Unable to turn off links for the GPU%d\n",
                         *(undefined4 *)(param_1 + 0x7a4));
            return 0x40;
          }
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x479,
                       "knvlinkCoreShutdownDeviceLinks_IMPL",4,
                       "NVRM: Need to shutdown all links unilaterally for GPU%d\n",
                       *(undefined4 *)(param_1 + 0x7a4));
        }
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x443,
                   "knvlinkCoreShutdownDeviceLinks_IMPL",1,
                   "NVRM: No links to shutdown for the GPU%d\n",*(undefined4 *)(param_1 + 0x7a4));
    }
  }
  return 0;
}


// ===== 0041fa50 knvlinkCoreResetDeviceLinks_IMPL =====

undefined8 knvlinkCoreResetDeviceLinks_IMPL(long param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  undefined1 local_160 [8];
  undefined8 local_158 [37];
  
  memset(local_158,0,0x120);
  if (((*(uint *)(param_2 + 0x314) < 7) && (*(char *)(g_pSys + 0x6b) != '\0')) ||
     (*(long *)(param_2 + 0x15d0) == 0)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x4a7,
                 "knvlinkCoreResetDeviceLinks_IMPL",1,
                 "NVRM: core lib device is either externally managed or not present, skipping\n");
  }
  else {
    cVar1 = bitVectorTestAllCleared_IMPL(param_2 + 0x388,0x40);
    if (cVar1 == '\0') {
      if (*(char *)(param_2 + 0x2e5) == '\0') {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x4d7,
                     "knvlinkCoreResetDeviceLinks_IMPL",1,
                     "NVRM: Lane shutdown not enabled, skipping link(s) reset for GPU%d\n",
                     *(undefined4 *)(param_1 + 0x7a4));
      }
      else {
        uVar6 = 0;
        bitVectorCopy_IMPL(local_160,0x40,param_2 + 0x388,0x40);
        uVar2 = bitVectorCountTrailingZeros_IMPL(local_160,0x40);
        while( true ) {
          uVar5 = (ulong)uVar2;
          cVar1 = bitVectorTestAllCleared_IMPL(local_160,0x40);
          if (cVar1 != '\0') break;
          lVar4 = uVar5 * 0x78 + param_2;
          if ((*(long *)(lVar4 + 0x3f0) != 2) ||
             (((lVar4 = gpumgrGetGpuFromBusInfo
                                  (*(undefined4 *)(lVar4 + 0x3d0),*(undefined1 *)(lVar4 + 0x3d4),
                                   *(undefined1 *)(lVar4 + 0x3d6)), lVar4 != 0 &&
               (*(char *)(lVar4 + 0x44f) == '\0')) &&
              ((*(char *)(lVar4 + 0x450) == '\0' &&
               ((*(char *)(lVar4 + 0x451) == '\0' && (*(char *)(lVar4 + 0x461) == '\0')))))))) {
            local_158[uVar6] = *(undefined8 *)(param_2 + 0x3c8 + uVar5 * 0x78);
            uVar6 = (ulong)((int)uVar6 + 1);
          }
          bitVectorClr_IMPL(local_160,0x40,uVar5);
          uVar2 = bitVectorCountTrailingZeros_IMPL(local_160,0x40);
        }
        iVar3 = nvlink_lib_reset_links(local_158,uVar6,1);
        if ((int)uVar6 == 0) {
          return 0;
        }
        if (iVar3 == 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x4cf,
                     "knvlinkCoreResetDeviceLinks_IMPL",4,
                     "NVRM: Unable to reset link(s) for GPU%d\n",*(undefined4 *)(param_1 + 0x7a4));
      }
      return 0x40;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x4b0,
                 "knvlinkCoreResetDeviceLinks_IMPL",1,"NVRM: No links to reset for the GPU%d\n",
                 *(undefined4 *)(param_1 + 0x7a4));
  }
  return 0;
}


// ===== 0041fd00 knvlinkRetrainLink_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkRetrainLink_IMPL(long param_1,long param_2,uint param_3,char param_4)

{
  long lVar1;
  int iVar2;
  long local_10;
  
  if (*(char *)(g_pSys + 0x6b) == '\0') {
    lVar1 = *(long *)(param_2 + 0x3c8 + (ulong)param_3 * 0x78);
    if (*(char *)(lVar1 + 0x28) == '\0') {
      iVar2 = nvlink_lib_get_link_master(lVar1,&local_10);
      if (iVar2 == 0) {
        if (lVar1 != local_10) {
          *(long *)(lVar1 + 0xa0) = local_10;
          *(long *)(lVar1 + 0xa8) = lVar1;
          *(uint *)(lVar1 + 0xb0) = (uint)(param_4 == '\0');
          iVar2 = (**(code **)(*(long *)(local_10 + 0x90) + 0x20))();
          return (-(uint)(iVar2 == 0) & 6) + 0xffff;
        }
        nvAssertFailedNoLog("master != slave","src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",
                            0x52d);
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkcorelibtrain.c",0x526,
                     "knvlinkRetrainLink_IMPL",4,
                     "NVRM: link master could not be found from GPU%u link %u\n",
                     *(undefined4 *)(param_1 + 0x7a4),param_3);
      }
      return 0x40;
    }
  }
  else {
    gpuNotifySubDeviceEvent_IMPL(param_1,0x7d,0,0,0,1);
  }
  return 0;
}


// ===== 0041fe40 knvlinkApplyRegkeyOverrides_IMPL =====

int knvlinkApplyRegkeyOverrides_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint local_34;
  int local_30;
  int local_2c [3];
  
  *(undefined1 *)(param_2 + 0x15fd) = 0;
  *(undefined1 *)(param_2 + 0x15fa) = 0;
  *(undefined1 *)(param_2 + 0x339) = 0;
  *(undefined8 *)(param_2 + 0x340) = 0;
  local_30 = 0;
  local_2c[0] = 0;
  bitVectorClrAll_IMPL(param_2 + 0x358,0x40);
  bitVectorClrAll_IMPL(param_2 + 0x360,0x40);
  *(undefined2 *)(param_2 + 0x1608) = 0;
  *(undefined4 *)(param_2 + 0x160c) = 0;
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkControl",param_2 + 800);
  if (iVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x4d,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,"NVRM: registryControl: 0x%x\n",
                 *(undefined4 *)(param_2 + 800));
    if ((*(uint *)(param_2 + 800) & 0x80000001) == 1) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x56,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Disabling NVLINK (forced disable via regkey)\n");
      return 0x56;
    }
    cVar1 = knvlinkIsNvlinkDefaultEnabled_IMPL(param_1,param_2);
    if ((cVar1 == '\0') && (-1 < (int)*(uint *)(param_2 + 800))) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x60,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Disabling NVLINK (disabled by platform default)\n");
      return 0x56;
    }
    if ((~*(uint *)(param_2 + 800) & 0x80000001) == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x6b,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Conflict in Nvlink Force Enable/Disable. Reverting to platform default.\n"
                  );
      cVar1 = knvlinkIsNvlinkDefaultEnabled_IMPL(param_1,param_2);
      if (cVar1 == '\0') {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x70,
                     "knvlinkApplyRegkeyOverrides_IMPL",1,
                     "NVRM: Disabling NVLINK (disabled by platform default)\n");
        return 0x56;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x78,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,"NVRM: NVLink is enabled\n");
      *(undefined1 *)(param_2 + 0x2e0) = 1;
    }
    uVar3 = *(uint *)(param_2 + 800);
    if ((uVar3 & 2) == 0) {
      *(undefined2 *)(param_2 + 0x15fd) = 0;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x84,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Overriding NvLink training during driver load via regkey.\n");
      *(undefined1 *)(param_2 + 0x15fd) = 1;
      uVar3 = *(uint *)(param_2 + 800);
    }
    *(byte *)(param_2 + 0x15fa) = (byte)(uVar3 >> 2) & 1;
    *(byte *)(param_2 + 0x15fb) = (byte)(uVar3 >> 8) & 1;
    if ((uVar3 & 0x80) != 0) {
      *(undefined1 *)(param_2 + 0x1608) = 1;
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xa8,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Link training debug spew turned on!\n");
    }
  }
  else {
    cVar1 = knvlinkIsNvlinkDefaultEnabled_IMPL(param_1,param_2);
    if (cVar1 == '\0') {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xaf,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Disabling NVLINK (disabled by platform default)\n");
      return 0x56;
    }
  }
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkverboseControlMask",param_2 + 0x328);
  if ((iVar2 == 0) && ((*(byte *)(param_2 + 0x328) & 1) != 0)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xc1,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: Forcing NVLINK Verbose Reg Init Prints enabled via regkey\n");
  }
  osReadRegistryDword(param_1,"RMNvLinkDisableLinks",&local_30);
  osReadRegistryDword(param_1,"RMNvLinkDisableLinks2",local_2c);
  if (local_30 != 0 || local_2c[0] != 0) {
    iVar2 = convertMaskToBitVector(CONCAT44(local_2c[0],local_30),param_2 + 0x360);
    if (iVar2 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar2,"convertMaskToBitVector(tmp, &pKernelNvlink->regkeyDisabledLinksMask)",
                 "src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xcf);
      return iVar2;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xd1,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: disable links regkey set with a value of\n");
  }
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkEnable",&local_34);
  if (iVar2 == 0) {
    *(undefined1 *)(param_2 + 0x339) = 1;
    *(ulong *)(param_2 + 0x340) = (ulong)local_34;
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xdf,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,"NVRM: Enable NvLinks 0x%llx via regkey\n");
  }
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkDisableP2PLoopback",&local_34);
  if ((iVar2 == 0) && (local_34 == 1)) {
    *(undefined1 *)(param_1 + 0x4a6) = 1;
  }
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkControlLinkPM",&local_34);
  if ((iVar2 == 0) &&
     (nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xef,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: RM NVLink Link PM controlled via regkey\n"), (local_34 & 0xc0) == 0x80)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0xf5,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: NVLink L2 power state disabled via regkey\n");
    *(undefined1 *)(param_2 + 0x1609) = 1;
  }
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkForceLaneshutdown",&local_34);
  if ((iVar2 == 0) && (local_34 == 1)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x100,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: NVLink lanedisable and laneshutdown is forced enabled via regkey\n");
    *(undefined1 *)(param_2 + 0x2e6) = 1;
  }
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkForcedSysmemDeviceType",param_2 + 0x15c8);
  if (iVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x10d,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: Forcing NVLINK SYSMEM device type with 0x%x via regkey\n",
                 *(undefined4 *)(param_2 + 0x15c8));
  }
  else {
    *(undefined4 *)(param_2 + 0x15c8) = 0;
  }
  iVar2 = osReadRegistryDword(param_1,"RMNvLinkForcedLoopbackOnSwitch",&local_34);
  if ((iVar2 == 0) && ((local_34 & 1) != 0)) {
    *(undefined1 *)(param_2 + 0x2ef) = 1;
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x11c,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,"NVRM: Forced Loopback on switch is enabled\n"
                );
  }
  iVar2 = osReadRegistryDword(param_1,"RmNvlinkEncryptionWithCC",&local_34);
  if (iVar2 == 0) {
    if ((local_34 & 1) == 0) {
      *(undefined1 *)(param_2 + 0x2f2) = 0;
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",300,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Nvlink Encryption with CC is disabled via regkey\n");
    }
    else {
      *(undefined1 *)(param_2 + 0x2f2) = 1;
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x127,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Nvlink Encryption with CC is enabled via regkey\n");
    }
  }
  iVar2 = osReadRegistryDword(param_1,"RmNvlinkEncryption",&local_34);
  if (iVar2 == 0) {
    if ((local_34 & 1) == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x15a,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Nvlink Encryption is disabled via regkey\n");
    }
    else {
      if ((*(long *)(param_1 + 0x1d18) == 0) ||
         (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a8) == '\0')) {
        if (*(char *)(param_2 + 0x2f2) != '\0') goto LAB_004201e0;
      }
      else if (*(char *)(param_2 + 0x2f2) != '\0') {
        *(undefined1 *)(param_2 + 0x1832) = 1;
        *(undefined4 *)(param_2 + 0x171c) = 0x40;
        *(undefined1 *)(param_2 + 0x2f3) = 1;
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x14b,
                     "knvlinkApplyRegkeyOverrides_IMPL",1,
                     "NVRM: Nvlink Encryption is enabled with CC via regkey\n");
        goto LAB_004201e0;
      }
      *(undefined1 *)(param_2 + 0x1832) = 1;
      *(undefined4 *)(param_2 + 0x171c) = 0x40;
      *(undefined1 *)(param_2 + 0x2f3) = 1;
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x153,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Nvlink Encryption is enabled via regkey\n");
    }
    goto LAB_004201e0;
  }
  *(undefined1 *)(param_2 + 0x1832) = 0;
  if ((*(long *)(param_1 + 0x1d18) == 0) || (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2a8) == '\0')
     ) {
    if (*(char *)(param_2 + 0x2f2) == '\0') goto LAB_004201e0;
  }
  else {
    if (*(char *)(param_2 + 0x2f2) == '\0') goto LAB_004201e0;
    cVar1 = gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL(param_1);
    if (cVar1 == '\0') {
      *(undefined1 *)(param_2 + 0x1832) = 1;
      *(undefined4 *)(param_2 + 0x171c) = 0x40;
      *(undefined1 *)(param_2 + 0x2f3) = 1;
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x177,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Nvlink Encryption is enabled by default because CC is enabled\n");
      goto LAB_004201e0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x17b,
               "knvlinkApplyRegkeyOverrides_IMPL",1,
               "NVRM: Nvlink Encryption is disabled by default because CC is disabled\n");
LAB_004201e0:
  *(undefined1 *)(param_2 + 0x1853) = 0;
  *(undefined4 *)(param_2 + 0x1854) = 0xe10;
  iVar2 = osReadRegistryDword(param_1,"RmNvlinkNvleKeyRefresh",&local_34);
  if (iVar2 == 0) {
    *(uint *)(param_2 + 0x1854) = local_34 & 0x7fffffff;
    *(byte *)(param_2 + 0x1853) = (byte)(local_34 >> 0x1f);
    if ((int)local_34 < 0) {
      if ((local_34 & 0x7fffffff) - 0x3c < 0xdd5) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x198,
                     "knvlinkApplyRegkeyOverrides_IMPL",1,
                     "NVRM: NVLE key refresh is enabled via regkey, key refresh interval is 0x%x seconds\n"
                    );
      }
      else {
        *(undefined1 *)(param_2 + 0x1853) = 0;
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x193,
                     "knvlinkApplyRegkeyOverrides_IMPL",1,
                     "NVRM: NVLE key refresh is disabled because of incorrect refresh interval via regkey\n"
                    );
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x19f,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: NVLE key refresh is disabled via regkey\n");
    }
  }
  else if (*(char *)(param_2 + 0x1853) == '\x01') {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x1a6,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: NVLE key refresh is enabled by default, key refresh interval is 0x%x seconds\n"
                 ,*(undefined4 *)(param_2 + 0x1854));
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x1ac,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: NVLE key refresh is disabled by default\n");
  }
  *(undefined1 *)(param_2 + 0x1831) = 0;
  iVar2 = osReadRegistryDword(param_1,"RmNvlinkAdaptiveBwMode",&local_34);
  if (iVar2 == 0) {
    if ((local_34 & 1) == 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x1b7,
                   "knvlinkApplyRegkeyOverrides_IMPL",1,
                   "NVRM: Adaptive Bandwidth Mode (ABM) disabled via regkey\n");
      *(undefined1 *)(param_2 + 0x171b) = 0;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x1bc,
                 "knvlinkApplyRegkeyOverrides_IMPL",1,
                 "NVRM: Adaptive Bandwidth Mode (ABM) enabled via regkey\n");
    *(undefined1 *)(param_2 + 0x171b) = 1;
    return 0;
  }
  *(undefined1 *)(param_2 + 0x171b) = 0;
  nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkoverrides.c",0x1ca,
               "knvlinkApplyRegkeyOverrides_IMPL",1,
               "NVRM: Adaptive Bandwidth Mode (ABM) disabled by default\n");
  return 0;
}


// ===== 00420910 knvlinkShutdownLinks_WORKITEM =====

void knvlinkShutdownLinks_WORKITEM(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = gpumgrGetGpu();
  if (*(long *)(lVar2 + 0x1ce8) == 0) {
    nvCheckFailedNoLog(1,"(pGpu != NULL && pKernelNvlink != NULL)",
                       "src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x49d);
    return;
  }
  iVar1 = knvlinkCoreShutdownDeviceLinks_IMPL(lVar2,*(long *)(lVar2 + 0x1ce8),1);
  if (iVar1 == 0) {
    return;
  }
  nvAssertFailedNoLog("knvlinkCoreShutdownDeviceLinks(pGpu, pKernelNvlink, NV_TRUE) == NV_OK",
                      "src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x4a1);
  return;
}


// ===== 00420980 _knvlinkPurgeState.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _knvlinkPurgeState_isra_0(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  long lVar5;
  bool bVar6;
  undefined1 local_40 [16];
  
  lVar5 = *(long *)(param_1 + 0x1b88);
  bVar6 = false;
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    cVar2 = kmigmgrIsMIGNvlinkP2PSupported_IMPL();
    bVar6 = cVar2 == '\0';
  }
  bitVectorCopy_IMPL(local_40,0x40,param_2 + 0x350,0x40);
  uVar3 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
  while( true ) {
    cVar2 = bitVectorTestAllCleared_IMPL(local_40,0x40);
    if (cVar2 != '\0') break;
    lVar1 = param_2 + (ulong)uVar3 * 0x78;
    if ((*(long *)(lVar1 + 0x438) != 0) && (lVar5 != 0)) {
      tmrEventDestroy_IMPL(lVar5);
      *(undefined8 *)(lVar1 + 0x438) = 0;
    }
    bitVectorClr_IMPL(local_40,0x40,(ulong)uVar3);
    uVar3 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
  }
  cVar2 = rmcfg_IsGH100orBetter(param_1);
  if ((cVar2 == '\0') && (bVar6)) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x444,"_knvlinkPurgeState",1,
                 "NVRM: Skipping device/link un-registration in MIG enabled path\n");
    goto LAB_00420b49;
  }
  cVar2 = (**(code **)(param_2 + 0x218))(param_1,param_2);
  if (cVar2 != '\0') {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x44c,"_knvlinkPurgeState",1,
                 "NVRM: Skipping device/link un-registration in RTD3 GC6 entry path\n");
    goto LAB_00420b49;
  }
  if (*(char *)(param_1 + 0x4911) == '\0') {
    lVar5 = *(long *)(param_2 + 0x15d0);
joined_r0x00420be5:
    if (lVar5 != 0) {
      bitVectorCopy_IMPL(local_40,0x40,param_2 + 0x388,0x40);
      uVar4 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
      while (cVar2 = bitVectorTestAllCleared_IMPL(local_40,0x40), cVar2 == '\0') {
        knvlinkCoreRemoveLink_IMPL(param_1,param_2,uVar4);
        bitVectorClr_IMPL(local_40,0x40,uVar4);
        uVar4 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
      }
      knvlinkCoreRemoveDevice_IMPL(param_1,param_2);
    }
  }
  else if (*(char *)(param_2 + 0x15fc) != '\0') {
    lVar5 = *(long *)(param_2 + 0x15d0);
    goto joined_r0x00420be5;
  }
  if (*(long *)(param_2 + 0x15f0) != 0) {
    portMemFree();
    *(undefined8 *)(param_2 + 0x15f0) = 0;
  }
LAB_00420b49:
  portMemSet(param_2 + 0x14c8,0,0x100);
  *(undefined4 *)(param_2 + 0x14c0) = 0;
  if (*(char *)(param_2 + 0x318) != '\0') {
    lVar5 = 0;
    do {
      if (*(long *)(param_2 + 0x2f8 + lVar5 * 8) != 0) {
        kioctrlDestructEngine_IMPL();
        *(uint *)(param_2 + 0x310) = *(uint *)(param_2 + 0x310) & ~(1 << ((byte)lVar5 & 0x1f));
      }
      lVar5 = lVar5 + 1;
    } while ((uint)lVar5 < (uint)*(byte *)(param_2 + 0x318));
  }
  portMemFree(*(undefined8 *)(param_2 + 0x330));
  *(undefined8 *)(param_2 + 0x330) = 0;
  return;
}


// ===== 00420c50 knvlinkConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkConstructEngine_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined1 *puVar2;
  ulong uVar3;
  long *local_30 [2];
  
  bitVectorClrAll_IMPL(param_2 + 0x350,0x40);
  knvlinkCoreDriverLoadWar_IMPL(param_1,param_2);
  iVar1 = knvlinkCoreIsDriverSupported_IMPL(param_1,param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = knvlinkApplyRegkeyOverrides_IMPL(param_1,param_2);
  if (iVar1 != 0x56) {
    *(undefined2 *)(param_2 + 0x15f8) = 0;
    iVar1 = (**(code **)(param_2 + 0x1f0))(param_1,param_2);
    if (iVar1 != 0x56) {
      *(undefined1 *)(param_2 + 0x14a8) = 0;
      uVar3 = 0;
      do {
        if (*(long *)(param_2 + 0x2f8 + uVar3 * 8) == 0) {
          local_30[0] = (long *)0x0;
          iVar1 = __nvoc_objCreate_KernelIoctrl(local_30,param_2,0);
          if (iVar1 == 0) {
            *(long **)(param_2 + 0x2f8 + uVar3 * 8) = local_30[0];
            (**(code **)(*local_30[0] + 0xb8))(param_1,local_30[0],uVar3 & 0xffffffff);
          }
          else {
            nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x3a)
            ;
          }
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 != 3);
      if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) != '\0')) {
        *(undefined1 *)(param_2 + 0x2ed) = 0;
      }
      puVar2 = (undefined1 *)gpumgrGetNvlinkRecoveryInfo_IMPL(*(undefined8 *)(param_1 + 0x878));
      if (puVar2 == (undefined1 *)0x0) {
        nvAssertFailedNoLog("pInfo != NULL","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x102);
        return 0x40;
      }
      *puVar2 = 1;
      *(undefined8 *)(puVar2 + 8) = *(undefined8 *)(param_1 + 0x878);
      LOCK();
      *(undefined4 *)(puVar2 + 0x18) = 0;
      UNLOCK();
      return 0;
    }
  }
  return 0x56;
}


// ===== 00420e20 knvlinkIsPresent_IMPL =====

bool knvlinkIsPresent_IMPL(undefined8 param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = gpuIsCCFeatureEnabled_IMPL();
  if (((cVar1 == '\0') ||
      (cVar1 = gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL(param_1), cVar1 != '\0')) ||
     (cVar1 = gpuIsCCMultiGpuNvleModeEnabled_IMPL(param_1), cVar1 != '\0')) {
    iVar2 = knvlinkCopyNvlinkDeviceInfo_IMPL(param_1,param_2);
    if (iVar2 == 0) {
      iVar2 = knvlinkCopyIoctrlDeviceInfo_IMPL(param_1,param_2);
      return iVar2 == 0;
    }
  }
  return false;
}


// ===== 00420e90 knvlinkRemoveMissingIoctrlObjects_IMPL =====

int knvlinkRemoveMissingIoctrlObjects_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = knvlinkCopyNvlinkDeviceInfo_IMPL();
  if (iVar1 == 0) {
    lVar2 = 0;
    do {
      if ((*(uint *)(param_2 + 0x310) & 1 << ((byte)lVar2 & 0x1f)) == 0) {
        __nvoc_objDelete(*(undefined8 *)(param_2 + 0x2f8 + lVar2 * 8));
        *(undefined8 *)(param_2 + 0x2f8 + lVar2 * 8) = 0;
      }
      lVar2 = lVar2 + 1;
    } while (lVar2 != 3);
  }
  return iVar1;
}


// ===== 00420f00 knvlinkStatePreInitLocked_IMPL =====

void knvlinkStatePreInitLocked_IMPL(void)

{
  knvlinkRemoveMissingIoctrlObjects_IMPL();
  return;
}


// ===== 00420f10 knvlinkStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkStateLoad_IMPL(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  byte bVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long *plVar13;
  ulong uVar14;
  bool bVar15;
  long local_80;
  undefined1 local_54 [4];
  undefined1 local_50 [8];
  uint local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  
  uVar11 = g_pSys;
  bVar15 = false;
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    cVar6 = kmigmgrIsMIGNvlinkP2PSupported_IMPL();
    bVar15 = cVar6 == '\0';
  }
  uVar2 = *(undefined8 *)(param_1 + 0x1b88);
  if (*(char *)(param_1 + 0x444) != '\0') {
    (**(code **)(param_2 + 0x168))(param_1,param_2);
  }
  iVar7 = knvlinkSyncLinkMasksAndVbiosInfo_IMPL(param_1,param_2);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",400);
    goto LAB_004216b8;
  }
  cVar6 = bitVectorTestAllCleared_IMPL(param_2 + 0x358,0x40);
  if (cVar6 == '\0') {
    bitVectorClrAll_IMPL(&local_48,0x40);
    iVar7 = bitVectorComplement_IMPL(&local_48,0x40,param_2 + 0x358,0x40);
    if (iVar7 == 0) {
      iVar7 = bitVectorAnd_IMPL(param_2 + 0x350,0x40,param_2 + 0x350,0x40,&local_48,0x40);
      uVar12 = 0x5f;
      if (iVar7 == 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",99,"_knvlinkFilterDiscoveredLinks"
                     ,1,"NVRM: Discovered Links:\n");
        goto LAB_00421042;
      }
LAB_0042185e:
      nvCheckOkFailedNoLog
                (4,iVar7,
                 "bitVectorAnd(&pKernelNvlink->discoveredLinks, &pKernelNvlink->discoveredLinks, &localBitVector)"
                 ,"src/kernel/gpu/nvlink/kernel_nvlinkstate.c",uVar12);
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar7,
                 "bitVectorComplement(&localBitVector, &pKernelNvlink->vbiosDisabledLinkMask)",
                 "src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x5d);
    }
LAB_00421879:
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x198);
    goto LAB_004216b8;
  }
LAB_00421042:
  cVar6 = bitVectorTestAllCleared_IMPL(param_2 + 0x360,0x40);
  if (cVar6 == '\0') {
    bitVectorClrAll_IMPL(&local_48,0x40);
    iVar7 = bitVectorComplement_IMPL(&local_48,0x40,param_2 + 0x360,0x40);
    if (iVar7 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar7,
                 "bitVectorComplement(&localBitVector, &pKernelNvlink->regkeyDisabledLinksMask)",
                 "src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x70);
      goto LAB_00421879;
    }
    iVar7 = bitVectorAnd_IMPL(param_2 + 0x350,0x40,param_2 + 0x350,0x40,&local_48,0x40);
    if (iVar7 != 0) {
      uVar12 = 0x72;
      goto LAB_0042185e;
    }
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x76,"_knvlinkFilterDiscoveredLinks",1
                 ,"NVRM: Links after applying disable links regkey\n");
  }
  uVar10 = *(uint *)(param_2 + 0x310);
  if (uVar10 != 0) {
    plVar13 = (long *)(param_2 + 0x2f8);
    do {
      if ((uVar10 & 1) != 0) {
        lVar3 = *plVar13;
        if (*(char *)(lVar3 + 0x179) == '\0') {
          uVar1 = *(uint *)(lVar3 + 0x180);
          iVar7 = bitVectorGetSlice_IMPL(param_2 + 0x350,0x40,0,0x3f,&local_48);
          if (iVar7 == 0) {
            if ((uVar1 & local_48 >> ((byte)*(undefined4 *)(lVar3 + 0x184) & 0x1f)) != 0)
            goto LAB_004210db;
          }
          else {
            nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                                "generated/g_kernel_nvlink_nvoc.h",0x8fd);
          }
          bVar5 = (byte)*(undefined4 *)(lVar3 + 0x17c) & 0x1f;
          *(uint *)(param_2 + 0x310) =
               *(uint *)(param_2 + 0x310) & (-2 << bVar5 | 0xfffffffeU >> 0x20 - bVar5);
        }
LAB_004210db:
        if (uVar10 >> 1 == 0) break;
      }
      uVar10 = uVar10 >> 1;
      plVar13 = plVar13 + 1;
    } while( true );
  }
  knvlinkSetPowerFeatures_IMPL(param_1,param_2);
  if ((*(char *)(param_1 + 0x4911) == '\0') || (*(char *)(param_2 + 0x15fc) != '\0')) {
    cVar6 = (**(code **)(param_2 + 0x218))(param_1,param_2);
    if ((cVar6 != '\0') || (bVar15)) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x1c0,"knvlinkStateLoad_IMPL",1,
                   "NVRM: MIG Enabled or NVLink L2 is supported on chip. Skip device registration in RTD3/FGC6 exit\n"
                  );
    }
    else {
      iVar7 = (**(code **)(param_2 + 0x220))(param_1,param_2);
      if (iVar7 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x1b1,"knvlinkStateLoad_IMPL",4,
                     "NVRM: Failed to get ALI status\n");
        goto LAB_004216b8;
      }
      iVar7 = knvlinkCoreAddDevice_IMPL(param_1,param_2);
      if (iVar7 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x1b9,"knvlinkStateLoad_IMPL",4,
                     "NVRM: Failed to add GPU device to nvlink core\n");
        goto LAB_004216b8;
      }
    }
  }
  iVar7 = knvlinkProcessInitDisabledLinks_IMPL(param_1,param_2);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x1ce);
    goto LAB_004216b8;
  }
  bitVectorClrAll_IMPL(local_50,0x40);
  iVar7 = convertMaskToBitVector(~(ulong)*(uint *)(param_2 + 0x368),local_50);
  if (iVar7 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar7,
               "convertMaskToBitVector(~((NvU64)pKernelNvlink->initDisabledLinksMask), &localBitVector)"
               ,"src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x1d5);
    return iVar7;
  }
  lVar3 = param_2 + 0x350;
  bitVectorAnd_IMPL(lVar3,0x40,lVar3,0x40,local_50,0x40);
  bitVectorCopy_IMPL(param_2 + 0x370,0x40,lVar3,0x40);
  *(undefined8 *)(param_2 + 0x3b8) = 0;
  iVar7 = knvlinkSyncLinkMasksAndVbiosInfo_IMPL(param_1,param_2);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x1e4);
    goto LAB_004216b8;
  }
  lVar4 = *(long *)(param_2 + 0x3b8);
  iVar7 = (**(code **)(param_2 + 0x208))(param_1,param_2);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x1f2);
    goto LAB_004216b8;
  }
  cVar6 = bitVectorTestAllCleared_IMPL(lVar3,0x40);
  if (cVar6 != '\0') {
    return 0;
  }
  iVar7 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,0xff000001);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x207);
    goto LAB_004216b8;
  }
  if (*(char *)(param_2 + 0x339) == '\0') {
    if (bVar15) {
      bitVectorClrAll_IMPL(param_2 + 0x388,0x40);
    }
    else {
      bitVectorCopy_IMPL(param_2 + 0x388,0x40,lVar3,0x40);
    }
  }
  else {
    iVar7 = convertMaskToBitVector(*(undefined8 *)(param_2 + 0x340),&local_48);
    if (iVar7 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar7,
                 "convertMaskToBitVector(KNVLINK_GET_MASK(pKernelNvlink, registryLinkMask, 64), &registryLinkMaskVec)"
                 ,"src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x212);
      return iVar7;
    }
    bitVectorAnd_IMPL(param_2 + 0x388,0x40,lVar3,0x40,&local_48,0x40);
  }
  local_80 = param_2 + 0x388;
  (**(code **)(param_2 + 0x1c8))(param_1,param_2);
  iVar7 = bitVectorGetSlice_IMPL(local_80,0x40,0,0x3f,&local_48);
  uVar12 = CONCAT44(uStack_44,local_48);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                        "generated/g_kernel_nvlink_nvoc.h",0x8fd);
    uVar12 = 0;
  }
  *(undefined8 *)(param_2 + 0x14b8) = uVar12;
  if ((*(char *)(param_1 + 0x4911) == '\0') || (*(char *)(param_2 + 0x15fc) != '\0')) {
    cVar6 = (**(code **)(param_2 + 0x218))(param_1,param_2);
    if (cVar6 == '\0') {
      bitVectorCopy_IMPL(&local_48,0x40,local_80,0x40);
      uVar8 = bitVectorCountTrailingZeros_IMPL(&local_48,0x40);
      while (cVar6 = bitVectorTestAllCleared_IMPL(&local_48,0x40), cVar6 == '\0') {
        iVar7 = knvlinkCoreAddLink_IMPL(param_1,param_2,uVar8);
        if (iVar7 != 0) {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x230,"knvlinkStateLoad_IMPL",4,
                       "NVRM: Failed to register Link%d in nvlink core\n",uVar8);
          goto LAB_004216b8;
        }
        bitVectorClr_IMPL(&local_48,0x40,uVar8);
        uVar8 = bitVectorCountTrailingZeros_IMPL(&local_48,0x40);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x239,"knvlinkStateLoad_IMPL",1,
                   "NVRM: NVLink L2 is supported on the chip. Skip link registration in RTD3/FGC6 exit\n"
                  );
    }
  }
  iVar7 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x2080303a,0,0);
  if (iVar7 != 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x245,"knvlinkStateLoad_IMPL",4,
                 "NVRM: Failed to perform pre-topology setup on mask of enabled links\n");
    return iVar7;
  }
  knvlinkDetectNvswitchProxy_IMPL(param_1,param_2);
  cVar6 = knvlinkIsNvswitchProxyPresent_IMPL(param_1,param_2);
  if (cVar6 != '\0') {
    sysEnableExternalFabricMgmt_IMPL(uVar11);
    sysForceInitFabricManagerState_IMPL(uVar11);
  }
  if (*(char *)(param_1 + 0x4cc) == '\x01') {
    sysEnableExternalFabricMgmt_IMPL(uVar11);
  }
  iVar7 = sysSyncExternalFabricMgmtWAR_IMPL(uVar11,param_1);
  if (iVar7 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x268);
    goto LAB_004216b8;
  }
  lVar3 = *(long *)(param_2 + 0x3b8);
  cVar6 = knvlinkIsForcedConfig_IMPL(param_1,param_2);
  if (((cVar6 != '\0') || (*(char *)(param_1 + 0x446) != '\0')) ||
     (*(char *)(param_1 + 0x490e) != '\0')) {
    knvlinkUpdateCurrentConfig_IMPL(param_1,param_2);
  }
  cVar6 = knvlinkIsForcedConfig_IMPL(param_1,param_2);
  if (((cVar6 == '\0') && (*(long *)(param_2 + 0x330) == 0)) ||
     (iVar7 = (**(code **)(param_2 + 0x228))(param_1,param_2), iVar7 == 0)) {
    portMemSet(&local_48,0,0x10);
    uStack_44 = CONCAT31(uStack_44._1_3_,1);
    local_48 = 0;
    local_40 = 0;
    iVar7 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a64,&local_48,0x10);
    if (iVar7 == 0) {
      iVar9 = knvlinkGetNumLinksToSystem_IMPL(param_1,param_2);
      if (iVar9 == 0) {
LAB_00421469:
        if (((param_3 & 1) == 0) &&
           (iVar7 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x360))
                              (param_1,*(long *)(&DAT_00001b90 + param_1),0,0), iVar7 != 0)) {
          nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x283,"knvlinkStateLoad_IMPL",4,
                       "NVRM: Init FLA failed, status:0x%x\n",iVar7);
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x284);
        }
        if (((*(char *)(param_2 + 0x2eb) != '\0') || (*(char *)(param_2 + 0x2ec) != '\0')) &&
           (*(char *)(param_2 + 0x2ed) != '\0')) {
          knvlinkCoreShutdownDeviceLinks_IMPL(param_1,param_2,0);
        }
        cVar6 = knvlinkIsForcedConfig_IMPL(param_1,param_2);
        if (((cVar6 == '\0') && (*(char *)(param_2 + 0x15ff) != '\0')) &&
           ((*(uint *)(param_2 + 0x314) < 8 &&
            ((*(char *)(param_2 + 0x2ed) == '\0' || (*(char *)(param_2 + 0x2eb) != '\0')))))) {
          iVar7 = bitVectorGetSlice_IMPL(local_80,0x40,0,0x3f,&local_48);
          uVar10 = local_48;
          if (iVar7 != 0) {
            nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                                "generated/g_kernel_nvlink_nvoc.h",0x8fd);
            uVar10 = 0;
          }
          iVar7 = knvlinkPreTrainLinksToActiveAli_IMPL(param_1,param_2,uVar10,1);
          if (iVar7 != 0) goto LAB_004216b8;
          bitVectorCopy_IMPL(&local_48,0x40,local_80,0x40);
          uVar8 = bitVectorCountTrailingZeros_IMPL(&local_48,0x40);
          while (cVar6 = bitVectorTestAllCleared_IMPL(&local_48,0x40), cVar6 == '\0') {
            iVar7 = knvlinkTrainLinksToActiveAli_IMPL(param_1,param_2,1 << ((byte)uVar8 & 0x1f),0);
            if (iVar7 != 0) {
              nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x2ae,
                           "knvlinkStateLoad_IMPL",4,
                           "NVRM: Failed to request Link %d to transition to active\n",uVar8);
            }
            if (*(char *)(param_1 + 0x446) != '\0') {
              osDelayUs(8000000);
            }
            bitVectorClr_IMPL(&local_48,0x40,uVar8);
            uVar8 = bitVectorCountTrailingZeros_IMPL(&local_48,0x40);
          }
        }
        bitVectorCopy_IMPL(&local_48,0x40,local_80,0x40);
        uVar10 = bitVectorCountTrailingZeros_IMPL(&local_48,0x40);
        while( true ) {
          uVar14 = (ulong)uVar10;
          cVar6 = bitVectorTestAllCleared_IMPL(&local_48,0x40);
          if (cVar6 != '\0') break;
          iVar7 = tmrEventCreate_IMPL(uVar2,param_2 + 0x438 + uVar14 * 0x78,ioctrlFaultUpTmrHandler,
                                      0,0);
          if (iVar7 != 0) {
            nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x2c8,"knvlinkStateLoad_IMPL",
                         4,"NVRM: Failed to create TmrEvent for Link %d\n",uVar14);
          }
          bitVectorClr_IMPL(&local_48,0x40,uVar14);
          uVar10 = bitVectorCountTrailingZeros_IMPL(&local_48,0x40);
        }
        uVar11 = portMemAllocatorGetGlobalNonPaged();
        listInit_IMPL(param_2 + 0x390,uVar11,1);
        (**(code **)(param_2 + 0x240))(param_1,param_2);
        (**(code **)(param_2 + 0x270))(param_1,param_2);
        (**(code **)(param_2 + 0x268))(param_1,param_2);
        if (iVar7 == 0) {
          return 0;
        }
        goto LAB_004216b8;
      }
      portMemSet(local_54,0,4);
      iVar9 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a97,local_54,4);
      if (iVar9 == 0) {
        iVar9 = kmemsysSetupCoherentCpuLink_IMPL
                          (param_1,*(undefined8 *)(param_1 + 0x1b70),lVar3 != lVar4);
        if (iVar9 == 0) goto LAB_00421469;
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x595);
        iVar7 = iVar9;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x590,"_knvlinkProcessSysmemLinks"
                     ,4,"NVRM: Failed to snable ATS functionality for NVLink sysmem!\n");
        iVar7 = iVar9;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x573,"_knvlinkProcessSysmemLinks",4
                   ,"NVRM: Failed to program bufferready for the sysmem nvlinks!\n");
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x55f,"_knvlinkProcessSysmemLinks",4,
                 "NVRM: Failed to perform NvLink post setup!\n");
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x275);
LAB_004216b8:
  _knvlinkPurgeState_isra_0(param_1,param_2);
  return iVar7;
}


// ===== 00421d80 knvlinkStatePostLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkStatePostLoad_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [24];
  
  knvlinkCoreUpdateDeviceUUID_IMPL();
  cVar1 = knvlinkIsForcedConfig_IMPL(param_1,param_2);
  if (cVar1 != '\0') goto LAB_00421f20;
  if (*(char *)(param_2 + 0x15ff) == '\0') {
    if (((*(char *)(param_2 + 0x15fe) == '\0') &&
        ((*(char *)(param_2 + 0x15fd) == '\0' && (*(char *)(param_2 + 0x15f8) == '\0')))) ||
       ((knvlinkCoreGetRemoteDeviceInfo_IMPL(param_1,param_2), *(char *)(param_2 + 0x15fd) == '\0'
        && (*(char *)(param_2 + 0x15f8) == '\0')))) goto LAB_00421f20;
    if (*(char *)(param_2 + 0x15ff) != '\0') goto LAB_00421e6d;
  }
  else {
    if ((*(char *)(param_2 + 0x15fd) == '\0') && (*(char *)(param_2 + 0x15f8) == '\0'))
    goto LAB_00421f20;
LAB_00421e6d:
    iVar2 = (**(code **)(param_2 + 0x230))(param_1,param_2,param_1);
    if (iVar2 == 0) {
      uVar5 = 0;
      if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
        uVar5 = 5;
      }
      timeoutSet(param_1 + 0x1af0,local_40,&DAT_00e4e1c0,uVar5);
      do {
        iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0x31b);
        iVar3 = knvlinkCheckTrainingIsComplete_IMPL(param_1,param_1,param_2);
        if (iVar3 == 0) {
          if (iVar2 == 0) goto LAB_00421f0e;
          break;
        }
        osSpinLoop();
      } while (iVar2 != 0x65);
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x327,"knvlinkStatePostLoad_IMPL",4,
                   "NVRM: Timedout while checking to see if training complete!\n");
LAB_00421f0e:
      knvlinkCoreGetRemoteDeviceInfo_IMPL(param_1,param_2);
      goto LAB_00421f20;
    }
  }
  iVar2 = gpumgrGetGpuAttachInfo(0,&local_44);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x330);
    return iVar2;
  }
  local_48 = 0;
  while (lVar4 = gpumgrGetNextGpu(local_44,&local_48), lVar4 != 0) {
    if ((*(char *)(lVar4 + 0x4918) != '\0') || (*(char *)(lVar4 + 0x4916) != '\0')) {
      knvlinkTrainP2pLinksToActive_IMPL(param_1,lVar4,param_2);
    }
  }
LAB_00421f20:
  if (*(char *)(param_2 + 0x1832) != '\0') {
    iVar2 = (**(code **)(param_2 + 0x2c8))(param_1,param_2);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"knvlinkGetEncryptionBits_HAL(pGpu, pKernelNvlink)",
                 "src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x344);
      return iVar2;
    }
    if ((*(char *)(param_2 + 0x1720) != '\0') &&
       (cVar1 = (**(code **)(param_2 + 0x2d0))(param_1,param_2), cVar1 == '\0')) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x34a,"knvlinkStatePostLoad_IMPL",4,
                   "NVRM:  NVLE not enabled on GPU%d\n",*(undefined4 *)(param_1 + 0x7a4));
      return 0x6d;
    }
    iVar2 = knvlinkAssignNvleClid_IMPL(param_1,param_2);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x353,"knvlinkStatePostLoad_IMPL",4,
                   "NVRM: Failed to assign CLID for GPU 0x%x\n",*(undefined4 *)(param_1 + 0x7a4));
      return iVar2;
    }
  }
  iVar2 = (**(code **)(param_2 + 0x1f8))(param_1,param_2);
  if (iVar2 == 0) {
    if ((*(char *)(param_1 + 0x4cc) != '\x01') &&
       (iVar2 = (**(code **)(param_2 + 0x170))(param_1,param_2), iVar2 != 0)) {
      nvAssertOkFailedNoLog
                (iVar2,"knvlinkSetDirectConnectBaseAddress_HAL(pGpu, pKernelNvlink)",
                 "src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x361);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x35b,"knvlinkStatePostLoad_IMPL",4,
                 "NVRM:  failed for GPU 0x%x\n",*(undefined4 *)(param_1 + 0x7a4));
  }
  return iVar2;
}


// ===== 00422150 knvlinkStateUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 knvlinkStateUnload_IMPL(long param_1,long param_2,uint param_3)

{
  code *pcVar1;
  
  if ((param_3 & 1) == 0) {
    pcVar1 = *(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x390);
    (*pcVar1)(param_1,*(long *)(&DAT_00001b90 + param_1),pcVar1);
  }
  (**(code **)(param_2 + 0x280))(param_1,param_2,*(code **)(param_2 + 0x280));
  return 0;
}


// ===== 004221a0 knvlinkStatePostUnload_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int knvlinkStatePostUnload_IMPL(long param_1,long param_2)

{
  ulong *puVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  undefined4 local_44;
  undefined4 local_40 [4];
  
  lVar5 = g_pSys;
  iVar3 = knvlinkGetNumLinksToSystem_IMPL();
  if ((iVar3 != 0) && (*(char *)(param_1 + 0x454) != '\0')) {
    kmemsysTeardownCoherentCpuLink_IMPL
              (param_1,*(undefined8 *)(param_1 + 0x1b70),*(undefined1 *)(param_2 + 0x2e6));
  }
  if (((*(char *)(param_1 + 0x443) == '\0') || (*(char *)(param_2 + 0x2e1) == '\0')) ||
     (*(char *)(param_2 + 0x2e9) == '\0')) {
    if (((*(char *)(lVar5 + 0x6a) != '\0') ||
        (cVar2 = knvlinkIsNvswitchProxyPresent_IMPL(param_1,param_2), cVar2 != '\0')) ||
       (*(char *)(param_1 + 0x4cc) == '\x01')) {
      (**(code **)(param_2 + 0x1e0))(param_1,param_2,0,0xff,0);
    }
    if (((*(char *)(param_2 + 0x2e6) != '\0') && (*(char *)(lVar5 + 0x6b) == '\0')) &&
       ((*(char *)(param_1 + 0x44f) == '\0' &&
        (((*(char *)(param_1 + 0x450) == '\0' && (*(char *)(param_1 + 0x451) == '\0')) &&
         (*(char *)(param_1 + 0x461) == '\0')))))) {
      portMemSet(&local_44,0,4);
      iVar3 = bitVectorGetSlice_IMPL(param_2 + 0x388,0x40,0,0x3f,local_40);
      if (iVar3 != 0) {
        nvAssertFailedNoLog("(bitVectorGetSlice(pSrc, rangeMake(0, 63), &localMask) == NV_OK)",
                            "generated/g_kernel_nvlink_nvoc.h",0x8fd);
        local_40[0] = 0;
      }
      local_44 = local_40[0];
      iVar3 = knvlinkExecGspRmRpc_IMPL(param_1,param_2,0x20800a92,&local_44,4);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x3eb,
                     "knvlinkStatePostUnload_IMPL",4,
                     "NVRM: Failed to disable DL interrupts for the links\n");
        return iVar3;
      }
      iVar3 = knvlinkPrepareForXVEReset_IMPL(param_1,param_2,0);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x3f3,
                     "knvlinkStatePostUnload_IMPL",4,
                     "NVRM: Failed to pseudo-clean shutdown the links for GPU%d\n",
                     *(undefined4 *)(param_1 + 0x7a4));
        return iVar3;
      }
    }
    bitVectorCopy_IMPL(local_40,0x40,param_2 + 0x388,0x40);
    uVar4 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
    while( true ) {
      cVar2 = bitVectorTestAllCleared_IMPL(local_40,0x40);
      if (cVar2 != '\0') break;
      lVar6 = (ulong)uVar4 * 0x78 + param_2;
      lVar5 = gpumgrGetGpuFromBusInfo
                        (*(undefined4 *)(lVar6 + 0x3d0),*(undefined1 *)(lVar6 + 0x3d4),
                         *(undefined1 *)(lVar6 + 0x3d6));
      if (((lVar5 != 0) && (*(char *)(lVar5 + 0x44f) == '\0')) &&
         ((*(char *)(lVar5 + 0x450) == '\0' &&
          ((*(char *)(lVar5 + 0x451) == '\0' && (*(char *)(lVar5 + 0x461) == '\0')))))) {
        puVar1 = (ulong *)(*(long *)(lVar5 + 0x1ce8) + 0x14b8);
        *puVar1 = *puVar1 | 1L << ((byte)*(undefined4 *)(lVar6 + 0x3f8) & 0x3f);
      }
      bitVectorClr_IMPL(local_40,0x40,(ulong)uVar4);
      uVar4 = bitVectorCountTrailingZeros_IMPL(local_40,0x40);
    }
    listDestroy_IMPL(param_2 + 0x390);
    iVar3 = knvlinkClearEncryptionKeys_IMPL(param_1,param_2);
    if ((iVar3 != 0) && (iVar3 != 0x56)) {
      nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x411,"knvlinkStatePostUnload_IMPL",
                   4,"NVRM: Failed to clear NVLE keys for the GPU\n");
    }
  }
  else {
    iVar3 = 0;
  }
  _knvlinkPurgeState_isra_0(param_1,param_2);
  return iVar3;
}


// ===== 00422540 knvlinkSetDegradedMode_IMPL =====

void knvlinkSetDegradedMode_IMPL(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x4bb,"knvlinkSetDegradedMode_IMPL",4,
                 "NVRM: Failed to get Local Nvlink info for linkId %d to update Degraded GPU%d status\n"
                 ,param_3 & 0xffffffff,*(undefined4 *)(param_1 + 0x7a4));
    return;
  }
  if (*(char *)(param_2 + 0x14a8) == '\0') {
    *(undefined1 *)(param_2 + 0x14a8) = 1;
    nvDbg_Printf("src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x4c8,"knvlinkSetDegradedMode_IMPL",4,
                 "NVRM: GPU%d marked Degraded. Error originated on linkId %d!\n",
                 *(undefined4 *)(param_1 + 0x7a4),param_3);
    iVar1 = osQueueWorkItem(param_1,knvlinkShutdownLinks_WORKITEM,0,0x120);
    if (iVar1 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "osQueueWorkItem(pGpu, knvlinkShutdownLinks_WORKITEM, NULL, (OsQueueWorkItemFlags){ .apiLock = WORKITEM_FLAGS_API_LOCK_READ_ONLY, .bLockGpuGroupSubdevice = NV_TRUE})"
                 ,"src/kernel/gpu/nvlink/kernel_nvlinkstate.c",0x4ce);
      return;
    }
  }
  return;
}


// ===== 00422620 knvlinkGetDegradedMode_IMPL =====

undefined1 knvlinkGetDegradedMode_IMPL(undefined8 param_1,long param_2)

{
  return *(undefined1 *)(param_2 + 0x14a8);
}


// ===== 00422630 knvlinkIsUncontainedErrorRecoveryActive_IMPL =====

ulong knvlinkIsUncontainedErrorRecoveryActive_IMPL(long param_1)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  ulong uVar4;
  
  pbVar3 = (byte *)gpumgrGetNvlinkRecoveryInfo_IMPL(*(undefined8 *)(param_1 + 0x878));
  uVar4 = 0;
  if ((pbVar3 != (byte *)0x0) && (uVar4 = (ulong)*pbVar3, *pbVar3 != 0)) {
    uVar4 = (ulong)*(uint *)(pbVar3 + 0x18);
    do {
      uVar2 = (uint)uVar4;
      LOCK();
      uVar1 = *(uint *)(pbVar3 + 0x18);
      if (uVar2 == uVar1) {
        *(uint *)(pbVar3 + 0x18) = uVar2;
      }
      else {
        uVar4 = (ulong)uVar1;
      }
      UNLOCK();
    } while (uVar2 != uVar1);
    return CONCAT71((int7)(uVar4 >> 8),uVar2 != 0);
  }
  return uVar4;
}


// ===== 00422680 knvlinkDestruct_IMPL =====

void knvlinkDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  plVar2 = (long *)(param_1 + 0x2f8);
  _knvlinkPurgeState_isra_0(uVar1,param_1);
  do {
    if (*plVar2 != 0) {
      __nvoc_objDelete();
      *plVar2 = 0;
    }
    plVar2 = plVar2 + 1;
  } while (plVar2 != (long *)(param_1 + 0x310));
  knvlinkCoreDriverUnloadWar_IMPL(uVar1,param_1);
  return;
}


// ===== 004226f4 ofactxConstructHal_KERNEL.cold =====

void ofactxConstructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00422700 ofactxConstructHal_KERNEL =====

undefined8 ofactxConstructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar5 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  lVar4 = kflcnGetKernelFalconForEngine_IMPL(uVar5,*(undefined4 *)(lVar1 + 0x184));
  if (lVar4 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 0x178);
    nvDbg_Printf("src/kernel/gpu/ofa/kernel_ofa_ctx.c",0x2d,"ofactxConstructHal_KERNEL",1,
                 "NVRM: ofactxConstruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
    uVar5 = kflcnAllocContext_IMPL
                      (uVar5,lVar4,uVar2,
                       *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
    return uVar5;
  }
  return 0xffff;
}


// ===== 004227ae ofactxDestructHal_KERNEL.cold =====

void ofactxDestructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004227c0 ofactxDestructHal_KERNEL =====

void ofactxDestructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar2 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  uVar6 = kflcnGetKernelFalconForEngine_IMPL(uVar2,*(undefined4 *)(lVar1 + 0x184));
  uVar3 = *(undefined8 *)(lVar1 + 0x178);
  nvDbg_Printf("src/kernel/gpu/ofa/kernel_ofa_ctx.c",0x3c,"ofactxDestructHal_KERNEL",1,
               "NVRM: ofactxDestruct for 0x%x\n",*(undefined4 *)(lVar1 + 0x184));
  iVar5 = kflcnFreeContext_IMPL
                    (uVar2,uVar6,uVar3,
                     *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
  if (iVar5 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar5,
             "kflcnFreeContext(pGpu, pKernelFalcon, pKernelChannel, RES_GET_EXT_CLASS_ID(pChannelDescendant))"
             ,"src/kernel/gpu/ofa/kernel_ofa_ctx.c",0x3e);
  return;
}


// ===== 00422890 ofaGetEngineDescFromAllocParams =====

uint ofaGetEngineDescFromAllocParams(long param_1,uint param_2,int *param_3)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  int local_44;
  long local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar5 = resservGetTlsCallContext();
  if (param_3 == (int *)0x0) {
    nvAssertFailedNoLog("(pOfaAllocParams != NULL)","src/kernel/gpu/ofa/kernel_ofa_engdesc.c",0x3d);
    return 0xb33b1500;
  }
  if (*param_3 != 0xc) {
    nvDbg_Printf("src/kernel/gpu/ofa/kernel_ofa_engdesc.c",0x41,"ofaGetEngineDescFromAllocParams",4,
                 "NVRM: createParams size mismatch (rm = 0x%x / client = 0x%x)\n",0xc,*param_3);
    return 0xb33b1500;
  }
  if (param_2 == 0xcdfa) {
LAB_00422948:
    uVar7 = param_3[2];
  }
  else {
    if (param_2 < 0xcdfb) {
      if (param_2 != 0xc7fa) {
        if (param_2 < 0xc7fb) {
          if ((param_2 != 0xb8fa) && (param_2 != 0xc6fa)) {
            return 0xb33b1500;
          }
        }
        else if (param_2 != 0xc9fa) {
          return 0xb33b1500;
        }
      }
    }
    else {
      if (param_2 == 0xd1fa) goto LAB_00422948;
      if (0xd1fa < param_2) {
        return 0xb33b1500;
      }
      if ((param_2 & 0xfffffeff) != 0xcefa) {
        return 0xb33b1500;
      }
    }
    uVar7 = 0;
  }
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar2 == '\0')) {
    uVar3 = uVar7 | 0xdd7bab00;
  }
  else {
    local_40 = 0;
    uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar4 = refFindAncestorOfType(*(undefined8 *)(lVar5 + 0x10),&DAT_00e0ac20,&local_40);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)",
                 "src/kernel/gpu/ofa/kernel_ofa_engdesc.c",0x61);
    }
    uVar3 = 0xb33b1500;
    if (local_40 != 0) {
      uVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 8),__nvoc_class_def_Device);
      iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar1,uVar6,&local_38);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, dynamicCast(pDeviceRef->pResource, Device), &ref)"
                   ,"src/kernel/gpu/ofa/kernel_ofa_engdesc.c",0x68);
      }
      iVar4 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (param_1,uVar1,local_38,local_30,uVar7 + 0x3e,&local_44);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,
                   "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_OFA(engineInstance), &rmEngineType)"
                   ,"src/kernel/gpu/ofa/kernel_ofa_engdesc.c",0x6d);
      }
      uVar3 = local_44 - 0x3eU | 0xdd7bab00;
    }
  }
  return uVar3;
}


// ===== 00422ae0 deviceKPerfCudaLimitCliDisable =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong deviceKPerfCudaLimitCliDisable(long param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = 0;
  if ((*(char *)(param_2 + 0x908) == '\0') &&
     (uVar1 = (ulong)*(uint *)(param_1 + 0x198), *(uint *)(param_1 + 0x198) != 0)) {
    uVar1 = (**(code **)(param_2 + 0x3b90))
                      (param_2 + 0x3b58,*(undefined4 *)(param_2 + 0x3b34),
                       *(undefined4 *)(param_2 + 0x3b38),0x802004,0,0);
    if ((int)uVar1 == 0) {
      *(undefined4 *)(param_1 + 0x198) = 0;
    }
    else {
      nvCheckFailedNoLog(1,"status == NV_OK","src/kernel/gpu/perf/kern_cuda_limit.c",0x47);
      uVar1 = uVar1 & 0xffffffff;
    }
    return uVar1;
  }
  return uVar1;
}


// ===== 00422b80 deviceCtrlCmdKPerfCudaLimitSetControl_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 deviceCtrlCmdKPerfCudaLimitSetControl_IMPL(long param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  int iVar5;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if ((*(char *)(lVar2 + 0x908) == '\0') && (*(char *)(lVar2 + 0x45f) == '\0')) {
    iVar1 = *(int *)(param_1 + 0x198);
    iVar5 = iVar1 + 1;
    if ((*param_2 == '\0') && (iVar5 = iVar1 + -1, iVar1 == 0)) {
      nvAssertOkFailedNoLog
                (0x3f,"kperfCudaLimitCliSet(pDevice, pParams->bCudaLimit)",
                 "src/kernel/gpu/perf/kern_cuda_limit.c",0x78);
      return 0x3f;
    }
    *(int *)(param_1 + 0x198) = iVar5;
    if ((iVar1 != 0) != (iVar5 != 0)) {
      plVar3 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
      uVar4 = (**(code **)(lVar2 + 0x3b90))
                        (lVar2 + 0x3b58,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2],0x802009,
                         param_2,1);
      return uVar4;
    }
  }
  return 0;
}


// ===== 00422c40 kperfConstructEngine_IMPL =====

undefined8 kperfConstructEngine_IMPL(void)

{
  return 0;
}


// ===== 00422c50 kperfStateInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kperfStateInitLocked_IMPL(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x168))();
  if (*(long *)(g_pSys + 0x220) != 0) {
    pfmreqhndlrStateInit_IMPL();
  }
  return uVar1;
}


// ===== 00422c90 kperfStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kperfStateLoad_IMPL(long param_1,long param_2)

{
  (**(code **)(param_2 + 0x168))();
  if ((*(char *)(param_1 + 0x486) == '\0') && (*(long *)(g_pSys + 0x220) != 0)) {
    pfmreqhndlrStateLoad_IMPL();
    return 0;
  }
  return 0;
}


// ===== 00422ce0 kperfStateUnload_IMPL =====

undefined8 kperfStateUnload_IMPL(void)

{
  if (*(long *)(g_pSys + 0x220) != 0) {
    pfmreqhndlrStateUnload_IMPL();
    return 0;
  }
  return 0;
}


// ===== 00422d10 kperfStateDestroy_IMPL =====

void kperfStateDestroy_IMPL(void)

{
  if (*(long *)(g_pSys + 0x220) != 0) {
    pfmreqhndlrStateDestroy_IMPL();
    return;
  }
  return;
}


// ===== 00422d40 kperfBoostSet_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kperfBoostSet_IMPL(undefined8 param_1,long param_2,uint *param_3)

{
  long lVar1;
  long *plVar2;
  uint local_10;
  uint local_c;
  
  local_c = param_3[1];
  local_10 = *param_3 & 0xff;
  lVar1 = *(long *)(*(long *)(param_2 + 0x158) + 0xe0);
  plVar2 = *(long **)(*(long *)(param_2 + 0x140) + 0x48);
  (**(code **)(lVar1 + 0x3b90))
            (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x20800a9a,&local_10,8);
  return;
}


// ===== 00422db0 subdeviceCtrlCmdKPerfBoost_IMPL =====

undefined8 subdeviceCtrlCmdKPerfBoost_IMPL(long param_1,byte *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  int iVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1c10);
  cVar3 = rmcfg_IsGB10Y(lVar1);
  if (cVar3 == '\0') {
    if (lVar2 != 0) {
      uVar4 = kperfBoostSet_IMPL(lVar2,param_1,param_2);
      return uVar4;
    }
    nvCheckFailedNoLog(1,"(pKernelPerf != NULL)","src/kernel/gpu/perf/kern_perf_boost.c",0x5a);
    uVar4 = 0x56;
  }
  else {
    iVar5 = *(int *)(param_2 + 4);
    if (0xfffff1ed < iVar5 - 0xe11U) {
      if ((*param_2 & 3) != 0) {
        if (iVar5 == -1) {
          param_2[4] = 1;
          param_2[5] = 0;
          param_2[6] = 0;
          param_2[7] = 0;
          iVar5 = 1;
        }
        uVar4 = osTegraiGpuPerfBoost(lVar1,1,iVar5);
        return uVar4;
      }
      uVar4 = osTegraiGpuPerfBoost(lVar1,0,0);
      return uVar4;
    }
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_boost.c",0x3a,"subdeviceCtrlCmdKPerfBoost_IMPL",4,
                 "NVRM: The specified duration exceed maximum %d!\n",0xe10);
    uVar4 = 0x1f;
  }
  return uVar4;
}


// ===== 00422ed0 subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_VF(long param_1,long param_2)

{
  undefined4 *puVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = resservGetTlsCallContext();
  puVar1 = *(undefined4 **)(lVar3 + 0x48);
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x1bc0) != 0)) &&
     (cVar2 = kmigmgrIsMIGEnabled_IMPL(), cVar2 != '\0')) {
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_ctrl.c",0x41,
                 "subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_VF",1,
                 "NVRM: Call not supported with SMC Enabled\n");
    return 0x56;
  }
  uVar4 = 0x1f;
  if (*(int *)(param_2 + 4) == 0xda40) {
    lVar3 = gpuGetRpc(*(undefined8 *)(puVar1 + 8));
    uVar4 = 0;
    if (lVar3 != 0) {
      uVar4 = (**(code **)(lVar3 + 0x288))
                        (*(undefined8 *)(puVar1 + 8),lVar3,*puVar1,puVar1[1],puVar1[2],
                         param_2 + 0x10,*(undefined4 *)(param_2 + 4));
      return uVar4;
    }
  }
  return uVar4;
}


// ===== 00422fb0 subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_KERNEL(long param_1,long param_2)

{
  uint uVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  long lVar7;
  uint uVar8;
  undefined4 local_2c;
  
  iVar4 = 0x56;
  lVar7 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar7 + 0x45f) == '\0') {
    plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
    iVar4 = (**(code **)(lVar7 + 0x3b90))
                      (lVar7 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x20802096,
                       param_2,0xda50);
    if (iVar4 == 0) {
      cVar3 = osIsInitNs();
      if (cVar3 != '\0') {
        return 0;
      }
      uVar1 = *(uint *)(param_2 + 4);
      if (uVar1 < 0xdd48) {
        if (0x307 < uVar1) {
          uVar8 = 0;
          puVar6 = (undefined4 *)(param_2 + 0x20);
          do {
            while( true ) {
              if ((*(long *)(puVar6 + 0x3c) == 0) ||
                 (iVar5 = osFindNsPid(*(long *)(puVar6 + 0x3c),&local_2c), iVar5 != 0)) break;
              lVar7 = *(long *)(puVar6 + 0x1c);
              *(undefined8 *)(puVar6 + 0x3c) = 0;
              puVar6[0x20] = local_2c;
              if (lVar7 != 0) goto LAB_00423120;
LAB_0042308d:
              lVar7 = *(long *)(puVar6 + 0x5c);
              if (lVar7 == 0) goto LAB_0042309d;
LAB_00423150:
              iVar5 = osFindNsPid(lVar7,&local_2c);
              if (iVar5 != 0) goto LAB_0042309d;
              lVar7 = *(long *)(puVar6 + 0x7c);
              *(undefined8 *)(puVar6 + 0x5c) = 0;
              puVar6[0x40] = local_2c;
              if (lVar7 != 0) goto LAB_00423190;
LAB_004230ad:
              lVar7 = *(long *)(puVar6 + 0x9c);
              if (lVar7 == 0) goto LAB_004230bd;
LAB_004231d0:
              iVar5 = osFindNsPid(lVar7,&local_2c);
              if (iVar5 != 0) goto LAB_004230bd;
              lVar7 = *(long *)(puVar6 + 0xbc);
              *(undefined8 *)(puVar6 + 0x9c) = 0;
              puVar6[0x80] = local_2c;
              if (lVar7 != 0) goto LAB_00423210;
LAB_004230cd:
              uVar8 = uVar8 + 1;
              puVar6 = puVar6 + 0xc2;
              if (uVar1 / 0x308 <= uVar8) {
                return 0;
              }
            }
            lVar7 = *(long *)(puVar6 + 0x1c);
            if (lVar7 == 0) goto LAB_0042308d;
LAB_00423120:
            iVar5 = osFindNsPid(lVar7,&local_2c);
            if (iVar5 != 0) goto LAB_0042308d;
            lVar7 = *(long *)(puVar6 + 0x5c);
            *(undefined8 *)(puVar6 + 0x1c) = 0;
            *puVar6 = local_2c;
            if (lVar7 != 0) goto LAB_00423150;
LAB_0042309d:
            lVar7 = *(long *)(puVar6 + 0x7c);
            if (lVar7 == 0) goto LAB_004230ad;
LAB_00423190:
            iVar5 = osFindNsPid(lVar7,&local_2c);
            if (iVar5 != 0) goto LAB_004230ad;
            lVar7 = *(long *)(puVar6 + 0x9c);
            *(undefined8 *)(puVar6 + 0x7c) = 0;
            puVar6[0x60] = local_2c;
            if (lVar7 != 0) goto LAB_004231d0;
LAB_004230bd:
            lVar7 = *(long *)(puVar6 + 0xbc);
            if (lVar7 == 0) goto LAB_004230cd;
LAB_00423210:
            iVar5 = osFindNsPid(lVar7,&local_2c);
            if (iVar5 != 0) goto LAB_004230cd;
            uVar8 = uVar8 + 1;
            *(undefined8 *)(puVar6 + 0xbc) = 0;
            puVar6[0xa0] = local_2c;
            puVar6 = puVar6 + 0xc2;
          } while (uVar8 < uVar1 / 0x308);
        }
      }
      else {
        iVar4 = 2;
        nvAssertFailedNoLog("numEntries <= NV2080_CTRL_PERF_GPUMON_SAMPLE_COUNT_PERFMON_UTIL",
                            "src/kernel/gpu/perf/kern_perf_ctrl.c",0x7d);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar4,
                 "pRmApi->Control(pRmApi, RES_GET_CLIENT_HANDLE(pSubdevice), RES_GET_HANDLE(pSubdevice), NV2080_CTRL_CMD_PERF_GET_GPUMON_PERFMON_UTIL_SAMPLES_V2, pParams, sizeof(*pParams))"
                 ,"src/kernel/gpu/perf/kern_perf_ctrl.c",0x6f);
    }
  }
  return iVar4;
}


// ===== 004232d0 subdeviceCtrlCmdPerfGetLevelInfo_V2_VF =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined4 subdeviceCtrlCmdPerfGetLevelInfo_V2_VF(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  long lVar7;
  
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar4 = plVar3[2];
  uVar5 = *(undefined4 *)(*plVar3 + 0x48);
  param_2[1] = 0;
  puVar6 = (undefined4 *)portMemAllocNonPaged(0x18);
  if (puVar6 == (undefined4 *)0x0) {
    uVar5 = 0x51;
  }
  else {
    *puVar6 = *param_2;
    puVar6[1] = param_2[1];
    uVar1 = param_2[0xc2];
    *(undefined4 **)(puVar6 + 2) = param_2 + 2;
    puVar6[4] = uVar1;
    lVar7 = gpuGetRpc(uVar2);
    if (lVar7 == 0) {
      uVar5 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/perf/kern_perf_ctrl.c",0xde);
    }
    else {
      uVar5 = (**(code **)(lVar7 + 0x340))(uVar2,lVar7,uVar5,(int)lVar4,puVar6);
    }
    *param_2 = *puVar6;
    param_2[1] = puVar6[1];
    param_2[0xc2] = puVar6[4];
    portMemFree(puVar6);
  }
  return uVar5;
}


// ===== 004233f0 subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_VF(long param_1,int *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = resservGetTlsCallContext();
  puVar1 = *(undefined4 **)(lVar3 + 0x48);
  if (((lVar4 != 0) && (*(long *)(lVar4 + 0x1bc0) != 0)) &&
     (cVar2 = kmigmgrIsMIGEnabled_IMPL(lVar4), cVar2 != '\0')) {
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_ctrl.c",0x106,
                 "subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_VF",4,
                 "NVRM: Call not supported with SMC Enabled\n");
    return 0x56;
  }
  if (*param_2 - 3U < 2) {
    return 0x56;
  }
  lVar4 = gpuGetRpc(*(undefined8 *)(puVar1 + 8));
  uVar5 = 0;
  if (lVar4 != 0) {
    uVar5 = (**(code **)(lVar4 + 0x288))
                      (*(undefined8 *)(puVar1 + 8),lVar4,*puVar1,puVar1[1],puVar1[2],param_2,0xc);
  }
  return uVar5;
}


// ===== 004234d0 subdeviceCtrlCmdPerfGetPowerstate_VF =====

undefined8 subdeviceCtrlCmdPerfGetPowerstate_VF(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0;
}


// ===== 004234e0 subdeviceCtrlCmdPerfGetCurrentPstate_VF =====

void subdeviceCtrlCmdPerfGetCurrentPstate_VF(long param_1)

{
  RmRpcPerfGetCurrentPstate(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 00423500 kperfGpuBoostSyncStateInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kperfGpuBoostSyncStateInit_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined8 local_28;
  undefined8 local_20;
  
  local_28 = 0;
  local_20 = 0;
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a80,&local_28,0x10);
  if (iVar1 == 0) {
    *(undefined8 *)(param_2 + 0x178) = 0xffffffffffffffff;
    *(undefined8 *)(param_2 + 0x180) = local_28;
    *(undefined2 *)(param_2 + 0x188) = (undefined2)local_20;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0x3e,"kperfGpuBoostSyncStateInit_IMPL"
               ,4,"NVRM: Failed to read Sync Gpu Boost init state, status=0x%x\n",iVar1);
  return 0;
}


// ===== 004235b0 kperfDoSyncGpuBoostLimits_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kperfDoSyncGpuBoostLimits_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  long lVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  byte bVar7;
  bool bVar8;
  undefined4 local_58;
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar1 = *(long *)(g_pSys + 0x248);
  lVar6 = *(long *)(g_pSys + 0x1e0);
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  gpuboostmgrGetBoostGrpIdFromGpu_IMPL(lVar1,param_1,&local_58);
  cVar3 = gpuboostmgrIsBoostGrpActive_IMPL(lVar1,local_58);
  if (cVar3 == '\0') {
    return 0;
  }
  if (param_2 == 0) {
    nvCheckFailedNoLog(4,"(pKernelPerf != NULL)","src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0x99
                      );
    return 0x3d;
  }
  *(undefined4 *)(param_2 + 0x178) = param_3[2];
  *(undefined4 *)(param_2 + 0x17c) = param_3[3];
  *(undefined1 *)(param_2 + 0x18a) = *(undefined1 *)(param_3 + 1);
  portMemSet(&local_40,0xff,8);
  cVar3 = gpuboostmgrIsBoostGrpActive_IMPL(lVar1,local_58);
  bVar7 = 0;
  if (cVar3 != '\0') {
    local_54 = 0;
    if (lVar1 == 0) {
      nvAssertFailedNoLog("NULL != (pBoostMgr)","src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0xb3)
      ;
    }
    bVar7 = 0;
    while (lVar5 = gpuboostmgrGpuItr_IMPL(lVar1,local_58,&local_54), lVar5 != 0) {
      param_2 = *(long *)(lVar5 + 0x1c10);
      if (param_2 == 0) {
        nvCheckFailedNoLog(4,"(pKernelPerf != NULL)","src/kernel/gpu/perf/kern_perf_gpuboostsync.c",
                           0xb6);
        return 0x3d;
      }
      uVar2 = (uint)local_40;
      if (*(uint *)(param_2 + 0x178) < (uint)local_40) {
        uVar2 = *(uint *)(param_2 + 0x178);
      }
      if (*(uint *)(param_2 + 0x17c) < local_40._4_4_) {
        local_40._4_4_ = *(uint *)(param_2 + 0x17c);
      }
      local_40 = CONCAT44(local_40._4_4_,uVar2);
      bVar7 = bVar7 | *(char *)(param_2 + 0x18a) != '\0';
    }
  }
  if (*(char *)(param_2 + 0x188) == '\0') goto LAB_00423762;
  osGetPerformanceCounter(&local_50);
  if (*(uint *)(lVar6 + 0x1b00) <= (uint)local_40) {
    if (*(uint *)(lVar6 + 0x1b00) < (uint)local_40) {
      if (*(uint *)(lVar6 + 0x1b04) <= local_40._4_4_) {
        bVar8 = *(ulong *)(param_2 + 0x180) < (ulong)(local_50 - *(long *)(lVar6 + 0x1af8)) / 1000;
        if (*(uint *)(lVar6 + 0x1b04) < local_40._4_4_) goto LAB_004238b7;
        goto LAB_004238e7;
      }
    }
    else if (*(uint *)(lVar6 + 0x1b04) <= local_40._4_4_) {
      if (local_40._4_4_ <= *(uint *)(lVar6 + 0x1b04)) {
        return 0;
      }
      bVar8 = false;
LAB_004238b7:
      bVar8 = (bool)(bVar8 | *(ulong *)(param_2 + 0x180) <
                             (ulong)(local_50 - *(long *)(lVar6 + 0x1af8)) / 1000);
LAB_004238e7:
      if (!bVar8) {
        return 0;
      }
    }
  }
  *(long *)(lVar6 + 0x1af8) = local_50;
  *(undefined8 *)(lVar6 + 0x1b00) = local_40;
LAB_00423762:
  local_48 = CONCAT44(CONCAT31(local_48._5_3_,bVar7),*param_3);
  cVar3 = gpuboostmgrIsBoostGrpActive_IMPL(lVar1,local_58);
  if (cVar3 == '\0') {
    return 0;
  }
  local_54 = 0;
  if (lVar1 == 0) {
    nvAssertFailedNoLog("NULL != (pBoostMgr)","src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0xfb);
  }
  uVar4 = 0;
  while (lVar6 = gpuboostmgrGpuItr_IMPL(lVar1,local_58,&local_54), lVar6 != 0) {
    uVar4 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(lVar6 + 0x3b34),
                       *(undefined4 *)(lVar6 + 0x3b3c),0x20800a7f,&local_48,0x10);
  }
  return uVar4;
}


// ===== 00423940 kPerfGpuBoostSyncBridgelessUpdateInfo =====

undefined8 kPerfGpuBoostSyncBridgelessUpdateInfo(long param_1,undefined1 param_2)

{
  if (*(long *)(param_1 + 0x1c10) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x1c10) + 0x18a) = param_2;
  }
  return 0;
}


// ===== 00423960 kperfGpuBoostSyncStateUpdate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kperfGpuBoostSyncStateUpdate(long param_1,ulong param_2,char param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined1 local_41;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar3 = g_pSys;
  param_2 = param_2 & 0xffffffff;
  if (1 < *(uint *)(param_1 + 0x58 + param_2 * 0x8c)) {
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0x13e,"kperfGpuBoostSyncStateUpdate"
                 ,4,"NVRM: Trying to activate and already active Sync GPU Boost Group = 0x%08x.\n",
                 param_2);
    return 0;
  }
  iVar2 = rmGpuLocksAcquire(0,0x80000);
  if (iVar2 == 0) {
    iVar2 = osAcquireRmSema(*(undefined8 *)(lVar3 + 0x160));
    if (iVar2 == 0) {
      local_40 = 0;
      while( true ) {
        lVar3 = gpuboostmgrGpuItr_IMPL(param_1,param_2,&local_40);
        iVar2 = 0;
        if (lVar3 == 0) break;
        lVar4 = *(long *)(lVar3 + 0x1c10);
        if ((lVar4 == 0) || (*(char *)(lVar4 + 0x189) == '\0')) {
          iVar2 = 0x40;
LAB_00423a15:
          nvDbg_Printf("src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0x169,
                       "kperfGpuBoostSyncStateUpdate",4,
                       "NVRM: Failed to toggle Sync Gpu Boost state on Gpu 0x%08x\n",
                       *(undefined4 *)(lVar3 + 0x7ac));
          local_3c[0] = 0;
          goto LAB_00423ab9;
        }
        local_3c[0] = CONCAT31(local_3c[0]._1_3_,param_3);
        iVar2 = (**(code **)(lVar3 + 0x3b90))
                          (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                           *(undefined4 *)(lVar3 + 0x3b3c),0x20800a7e,local_3c,1);
        if (iVar2 != 0) goto LAB_00423a15;
        *(undefined8 *)(lVar4 + 0x178) = 0xffffffffffffffff;
      }
      goto LAB_00423ba3;
    }
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0x193,"kperfGpuBoostSyncStateUpdate"
                 ,4,"NVRM: OS Semaphore acquire failed\n");
    rmGpuLocksRelease(0,0);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_gpuboostsync.c",0x19e,"kperfGpuBoostSyncStateUpdate"
                 ,4,"NVRM: GPU lock acquire failed\n");
  }
  return 99;
  while( true ) {
    lVar1 = *(long *)(lVar4 + 0x1c10);
    if (((lVar1 != 0) && (*(char *)(lVar1 + 0x189) != '\0')) &&
       (local_41 = param_3 == '\0',
       iVar2 = (**(code **)(lVar4 + 0x3b90))
                         (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),
                          *(undefined4 *)(lVar4 + 0x3b3c),0x20800a7e,&local_41,1), iVar2 == 0)) {
      *(undefined8 *)(lVar1 + 0x178) = 0xffffffffffffffff;
    }
    if (lVar3 == lVar4) break;
LAB_00423ab9:
    lVar4 = gpuboostmgrGpuItr_IMPL(param_1,param_2,local_3c);
    if (lVar4 == 0) break;
  }
LAB_00423ba3:
  rmGpuLocksRelease(0,0);
  return iVar2;
}


// ===== 00423c60 subdeviceCtrlCmdPerfReservePerfmonHw_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 subdeviceCtrlCmdPerfReservePerfmonHw_KERNEL(long param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar1 + 0x4a27) != '\0') {
    cVar3 = osIsAdministrator();
    if (cVar3 == '\0') {
      return 0x1b;
    }
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  uVar4 = (**(code **)(lVar1 + 0x3b90))
                    (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x20802093,
                     param_2,1);
  return uVar4;
}


// ===== 00423cf0 _kperfSendPostPowerStateCallback.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kperfSendPostPowerStateCallback_isra_0(long param_1)

{
  int iVar1;
  int iVar2;
  undefined2 local_22;
  uint local_20;
  uint local_1c;
  
  iVar2 = *(int *)(param_1 + 0x2198);
  local_20 = 0;
  local_22 = 4;
  local_1c = 0;
  if (iVar2 != 0xc) {
    iVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a81,&local_1c,4);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/perf/kern_perf_pwr.c",0x96,"_kperfSendPostPowerStateCallback",4,
                   "NVRM: Error getting Aux Power State:0x%x\n",iVar1);
    }
    local_20 = (local_1c & 0xf) << 4 | local_20 & 0xffffff0f | 4;
    iVar2 = osCallACPI_DSM(param_1,iVar2,0x205,&local_20,&local_22);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/perf/kern_perf_pwr.c",0xa4,"_kperfSendPostPowerStateCallback",4,
                   "NVRM: PostPState callback error:0x%x\n",iVar2);
      return;
    }
  }
  return;
}


// ===== 00423e10 subdeviceCtrlCmdPerfRatedTdpSetControl_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdPerfRatedTdpSetControl_KERNEL(long param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  bool bVar7;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 == 0) || (*(long *)(lVar1 + 0x1bc0) == 0)) {
    lVar4 = resservGetTlsCallContext();
    bVar7 = false;
  }
  else {
    cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar1);
    bVar7 = cVar3 != '\0';
    lVar4 = resservGetTlsCallContext();
  }
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/perf/kern_perf_pwr.c",0x42);
    return 0x40;
  }
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(lVar4 + 8),__nvoc_class_def_RmClient);
  if (plVar5 == (long *)0x0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/perf/kern_perf_pwr.c",0x45);
    return 0x23;
  }
  cVar3 = (**(code **)(*plVar5 + 0xe0))
                    (plVar5,*(undefined4 *)(lVar4 + 0x28),*(code **)(*plVar5 + 0xe0));
  if ((!bVar7) || (cVar3 != '\0')) {
    if ((*(int *)(param_2 + 8) != 1) ||
       (((cVar3 != '\0' || (*(char *)(lVar1 + 0x4a27) == '\0')) ||
        (cVar3 = osCheckAccess(3), cVar3 != '\0')))) {
      puVar2 = *(undefined4 **)(lVar4 + 0x48);
      lVar4 = gpuGetRpc(lVar1);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/perf/kern_perf_pwr.c",0x65);
        return 0x1a;
      }
      if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
        uVar6 = rpcDmaControl_wrapper
                          (lVar1,lVar4,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                           puVar2[6]);
        return uVar6;
      }
      uVar6 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
      return uVar6;
    }
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_pwr.c",0x5a,
                 "subdeviceCtrlCmdPerfRatedTdpSetControl_KERNEL",4,
                 "NVRM: Non-Privileged clients are not allowed to use Turbo Boost clock controls.\n"
                );
  }
  else {
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_pwr.c",0x4f,
                 "subdeviceCtrlCmdPerfRatedTdpSetControl_KERNEL",4,
                 "NVRM: Non-Privileged clients are not allowed to access clock controls with SMC enabled.\n"
                );
  }
  return 0x1b;
}


// ===== 00424060 subdeviceCtrlCmdPerfSetAuxPowerState_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdPerfSetAuxPowerState_KERNEL
              (long param_1,uint *param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(lVar1 + 0x1c10) != 0) {
    if (*param_2 < 5) {
      plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      iVar3 = (**(code **)(lVar1 + 0x3b90))
                        (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x20802092,
                         param_2,4);
      if (iVar3 != 0) {
        nvAssertFailedNoLog(&DAT_00d7359f,"src/kernel/gpu/perf/kern_perf_pwr.c",0xc3);
      }
      _kperfSendPostPowerStateCallback_isra_0(lVar1);
      gpuNotifySubDeviceEvent_IMPL(lVar1,0xb5,0,0,0,0);
    }
    else {
      iVar3 = 0x1f;
      nvAssertFailedNoLog("pPowerStateParams->powerState < NV2080_CTRL_PERF_AUX_POWER_STATE_COUNT",
                          "src/kernel/gpu/perf/kern_perf_pwr.c",0xb6,param_4,param_2);
    }
    return iVar3;
  }
  nvCheckFailedNoLog(1,"(pKernelPerf != NULL)","src/kernel/gpu/perf/kern_perf_pwr.c",0xb4);
  return 0x56;
}


// ===== 00424170 kperfPerfSetPowerstate_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kperfPerfSetPowerstate_KERNEL(long param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  ulong local_20;
  
  uVar1 = *param_3;
  if (1 < uVar1) {
    return 0x1f;
  }
  cVar2 = gpuIsGpuFullPower_IMPL();
  if (cVar2 == '\0') {
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_pwr.c",0xe2,"kperfPerfSetPowerstate_KERNEL",4,
                 "NVRM: NV2080_CTRL_CMD_PERF_SET_POWERSTATE called in power down state.\n");
    nvDbg_Printf("src/kernel/gpu/perf/kern_perf_pwr.c",0xe4,"kperfPerfSetPowerstate_KERNEL",4,
                 "NVRM:       Returning NV_ERR_GPU_NOT_FULL_POWER.\n");
    iVar3 = 0x11;
  }
  else {
    iVar3 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x2080205b,param_3,4);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/perf/kern_perf_pwr.c",0xf4,"kperfPerfSetPowerstate_KERNEL",4,
                   "NVRM: NV2080_CTRL_CMD_PERF_SET_POWERSTATE RPC failed\n");
    }
    _kperfSendPostPowerStateCallback_isra_0(param_1);
    local_20 = (ulong)(byte)uVar1 ^ 1;
    gpuNotifySubDeviceEvent_IMPL(param_1,0x76,&local_20,8,0,0);
  }
  return iVar3;
}


// ===== 004242d0 subdeviceCtrlCmdPerfSetPowerstate_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdPerfSetPowerstate_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1c10);
  if (lVar2 != 0) {
    uVar3 = (**(code **)(lVar2 + 0x170))(lVar1,lVar2,param_2);
    return uVar3;
  }
  nvCheckFailedNoLog(1,"(pKernelPerf != NULL)","src/kernel/gpu/perf/kern_perf_pwr.c",0x111);
  return 0x56;
}


// ===== 00424330 perfbufferConstructHal_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 perfbufferConstructHal_KERNEL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  char cVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar7 = *(long *)(param_2 + 0x10);
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  uVar2 = *(undefined4 *)(lVar7 + 0x10);
  uVar3 = *(undefined4 *)(lVar7 + 0x11c);
  uVar4 = *(undefined4 *)(*(long *)(lVar7 + 0x18) + 0x10);
  if (*(char *)(lVar5 + 0x4a27) != '\0') {
    cVar6 = osIsAdministrator();
    if (cVar6 == '\0') {
      nvCheckOkFailedNoLog
                (2,0x1b,"perfbufferPrivilegeCheck(pResource)",
                 "src/kernel/gpu/perf/kern_perfbuffer.c",0x3a);
      return 0x1b;
    }
  }
  lVar7 = gpuGetRpc(lVar5);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/perf/kern_perfbuffer.c",0x3c);
    uVar8 = 0;
  }
  else {
    if ((*(char *)(lVar5 + 0x909) == '\0') && (*(char *)(lVar5 + 0x90a) == '\0')) {
      uVar8 = (**(code **)(lVar7 + 0x348))
                        (lVar5,lVar7,uVar1,uVar4,uVar2,uVar3,*(undefined8 *)(param_3 + 0x40));
      return uVar8;
    }
    uVar8 = (**(code **)(lVar5 + 0x3b60))
                      (lVar5 + 0x3b58,uVar1,uVar4,uVar2,uVar3,*(undefined8 *)(param_3 + 0x40),
                       *(undefined4 *)(param_3 + 0x48));
  }
  return uVar8;
}


// ===== 00424490 kpmuStateDestroy_IMPL =====

void kpmuStateDestroy_IMPL(void)

{
  return;
}


// ===== 004244a0 kpmuDestruct_IMPL =====

void kpmuDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  if (*(char *)(lVar1 + 0x909) != '\0') {
    libosLogDestroy(param_1 + 0x170);
    portMemFree(*(undefined8 *)(param_1 + 0x2370));
    *(undefined8 *)(param_1 + 0x2370) = 0;
    portMemFree(*(undefined8 *)(param_1 + 0x2378));
    *(undefined8 *)(param_1 + 0x2378) = 0;
  }
  return;
}


// ===== 00424510 kpmuReservedMemorySizeGet_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kpmuReservedMemorySizeGet_IMPL(long param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar1 = (**(code **)(param_1 + 0x168))();
  cVar2 = (**(code **)(param_1 + 0x168))(param_1);
  cVar3 = (**(code **)(param_1 + 0x168))(param_1);
  return (-(uint)(cVar1 == '\0') & 0xff700000) + 0x91ffff +
         (uint)(cVar3 != '\0') * 0x1000 + (uint)(cVar2 != '\0') * 0x1000000 & 0xfffe0000;
}


// ===== 00424590 kpmuInitLibosLoggingStructures_IMPL =====

undefined8 kpmuInitLibosLoggingStructures_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x909) != '\0') {
    if (*(long *)(param_2 + 0x2370) == 0) {
      *(undefined8 *)(param_2 + 0x2378) = 0;
      *(undefined4 *)(param_2 + 0x2368) = 0x1000;
      uVar1 = portMemAllocNonPaged(0x1000);
      *(undefined8 *)(param_2 + 0x2370) = uVar1;
      libosLogCreateEx(param_2 + 0x170,&DAT_00d737e5);
      libosLogAddLogEx(param_2 + 0x170,*(undefined8 *)(param_2 + 0x2370),
                       *(undefined4 *)(param_2 + 0x2368),*(undefined4 *)(param_1 + 0x7a4),
                       *(uint *)(param_1 + 0x808) >> 4,*(undefined4 *)(param_1 + 0x80c),"NVRISCV",0,
                       0,0,2,0);
      libosLogInitEx(param_2 + 0x170,*(undefined8 *)(param_2 + 0x2378),1,1,1,
                     *(undefined4 *)(param_2 + 0x2380));
      uVar1 = 0;
    }
    else {
      nvAssertFailedNoLog("pKernelPmu->pPrintBuf == NULL","src/kernel/gpu/pmu/kern_pmu.c",0xbb);
      uVar1 = 0x40;
    }
    return uVar1;
  }
  return 0;
}


// ===== 004246b0 kpmuConstructEngine_IMPL =====

void kpmuConstructEngine_IMPL(void)

{
  kpmuInitLibosLoggingStructures_IMPL();
  return;
}


// ===== 004246c0 kpmuFreeLibosLoggingStructures_IMPL =====

void kpmuFreeLibosLoggingStructures_IMPL(long param_1,long param_2)

{
  if (*(char *)(param_1 + 0x909) == '\0') {
    return;
  }
  libosLogDestroy(param_2 + 0x170);
  portMemFree(*(undefined8 *)(param_2 + 0x2370));
  *(undefined8 *)(param_2 + 0x2370) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x2378));
  *(undefined8 *)(param_2 + 0x2378) = 0;
  return;
}


// ===== 00424720 kpmuLogBuf_IMPL =====

void kpmuLogBuf_IMPL(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  if (*(long *)(param_2 + 0x2370) != 0) {
    portMemCopy(*(long *)(param_2 + 0x2370),*(undefined4 *)(param_2 + 0x2368),param_3,param_4);
    libosExtractLogs(param_2 + 0x170,0);
    return;
  }
  nvAssertFailedNoLog("pKernelPmu->pPrintBuf != NULL","src/kernel/gpu/pmu/kern_pmu.c",0xf6);
  return;
}


// ===== 00424780 kpmuStateInitLocked_IMPL =====

undefined8 kpmuStateInitLocked_IMPL(void)

{
  return 0;
}


// ===== 00424790 krcConstructEngine_IMPL =====

undefined8 krcConstructEngine_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  int local_20;
  uint local_1c;
  
  local_20 = 0;
  iVar2 = osReadRegistryDword(param_1,"RmBreakonRC",&local_20);
  if (iVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x82,"_krcInitRegistryOverrides",1,
                 "NVRM: BreakOnRc set by regkey RmBreakonRC= 0x%08x\n",local_20);
    bVar4 = local_20 == 1;
  }
  else {
    local_20 = 0;
    bVar4 = false;
  }
  *(bool *)(param_2 + 0x189) = bVar4;
  if ((*(byte *)(g_pSys + 0xac) & 1) != 0) {
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x8d,"_krcInitRegistryOverrides",1,
                 "NVRM: BreakOnRc overridden by NV_DEBUG_BREAK_FLAGS_RC\n",bVar4);
    *(undefined1 *)(param_2 + 0x189) = 1;
    bVar4 = true;
  }
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x91,"_krcInitRegistryOverrides",1,
               "NVRM: BreakOnRc = %d\n",bVar4);
  iVar2 = osReadRegistryDword(param_1,"RmWatchDogTimeOut",param_2 + 0x28c);
  if ((iVar2 != 0) || (*(int *)(param_2 + 0x28c) == 0)) {
    *(undefined4 *)(param_2 + 0x28c) = 7;
  }
  local_1c = 0;
  iVar2 = osReadRegistryDword(param_1,"RmOverrideInternalTimeoutsMs",&local_1c);
  if ((iVar2 == 0) && ((local_1c & 0x40000000) != 0)) {
    *(uint *)(param_2 + 0x28c) = (local_1c & 0xffffff) / 1000;
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0xaf,"_krcInitRegistryOverrides",2,
                 "NVRM: RC Watchdog timeout forced to %d seconds.\n");
  }
  iVar2 = osReadRegistryDword(param_1,"RmWatchDogInterval",param_2 + 0x290);
  if ((iVar2 != 0) || (uVar3 = *(uint *)(param_2 + 0x290), uVar3 == 0)) {
    *(undefined4 *)(param_2 + 0x290) = 7;
    uVar3 = 7;
  }
  if (*(uint *)(param_2 + 0x28c) < uVar3) {
    *(uint *)(param_2 + 0x290) = *(uint *)(param_2 + 0x28c);
  }
  local_20 = 0;
  iVar2 = osReadRegistryDword(param_1,"RmRcWatchdog",&local_20);
  if (iVar2 == 0) {
    if (local_20 != 0) goto LAB_004248cc;
  }
  else if (((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) &&
          (cVar1 = gpuIsCCFeatureEnabled_IMPL(param_1), cVar1 == '\0')) goto LAB_004248cc;
  *(uint *)(param_2 + 0x1a8) = *(uint *)(param_2 + 0x1a8) | 2;
LAB_004248cc:
  local_20 = 0;
  iVar2 = osReadRegistryDword(param_1,"RmLogonRC",&local_20);
  if ((iVar2 == 0) && (*(bool *)(param_2 + 0x18a) = local_20 == 1, local_20 == 1)) {
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0xdd,"_krcInitRegistryOverrides",1,
                 "NVRM: RC Error Logging is enabled\n");
  }
  *(undefined1 *)(param_2 + 0x198) = 1;
  return 0;
}


// ===== 00424a80 krcInitRegistryOverridesDelayed_IMPL =====

void krcInitRegistryOverridesDelayed_IMPL(long param_1,long param_2)

{
  long lVar1;
  short sVar2;
  int iVar3;
  int local_2c [3];
  
  local_2c[0] = 0;
  lVar1 = *(long *)(param_1 + 7000);
  iVar3 = osReadRegistryDword(param_1,"RmRobustChannels",local_2c);
  *(bool *)(param_2 + 0x188) = iVar3 != 0 || local_2c[0] == 1;
  local_2c[0] = 0;
  iVar3 = osReadRegistryDword(param_1,"UseUncachedPCIMappings",local_2c);
  if (((iVar3 == 0) && (local_2c[0] != 0)) ||
     ((lVar1 != 0 && (sVar2 = kbifGetDmaCaps_IMPL(param_1,lVar1), sVar2 == 0)))) {
    *(uint *)(param_2 + 0x1a8) = *(uint *)(param_2 + 0x1a8) | 4;
  }
  return;
}


// ===== 00424b30 krcReportXid_IMPL =====

void krcReportXid_IMPL(long param_1,long param_2,ulong param_3,undefined8 *param_4,
                      undefined *param_5)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long local_90;
  undefined1 local_88 [4];
  undefined8 local_84;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (*(char *)(*(long *)(param_1 + 0x1c18) + 0x18a) == '\0') {
    return;
  }
  uVar6 = 0;
  if (param_2 != 0) {
    uVar6 = *(undefined8 *)(param_2 + 0x150);
  }
  lVar4 = gpuEngineGetGpu(uVar6);
  if (*(char *)(lVar4 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(ENG_GET_GPU(pKernelRc))","src/kernel/gpu/rc/kernel_rc.c",
                        0x24b);
LAB_00424dc7:
    local_7c = 0;
    local_84 = 0;
    if (param_4 != (undefined8 *)0x0) {
      uVar6 = gpuGetKernelFifoShared_IMPL(param_1);
      lVar4 = kfifoKernelChannelFromInfo_IMPL(param_1,uVar6,*param_4,*(undefined4 *)(param_4 + 1));
      if (lVar4 != 0) goto LAB_00424bbf;
    }
    lVar4 = resservGetTlsCallContext();
    local_90 = 0;
    lVar7 = 0;
    if (lVar4 != 0) {
      uVar3 = osGetCurrentProcess();
      nvDbgSnprintf(&local_84,0xc,&DAT_00d7399c,uVar3);
      lVar7 = portMemAllocNonPaged(100);
      local_90 = lVar7;
      if (lVar7 != 0) {
        osGetCurrentProcessName(lVar7,100);
      }
    }
  }
  else {
    lVar4 = *(long *)(param_2 + 400);
    local_84 = 0;
    local_7c = 0;
    if (lVar4 == 0) goto LAB_00424dc7;
LAB_00424bbf:
    lVar7 = 0;
    lVar5 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(lVar4 + 0x140) + 0x48),
                               __nvoc_class_def_RmClient);
    nvDbgSnprintf(&local_84,0xc,&DAT_00d7399c,*(undefined4 *)(lVar4 + 0x3e4));
    local_90 = lVar5 + 0x1a0;
  }
  if (*(char *)(param_2 + 0x199) == '\0') {
    local_78 = 0;
    iVar2 = gpuGetGidInfo_IMPL(param_1,&local_78,local_88,0);
    if (iVar2 == 0) {
      uVar1 = *(ulong *)(param_1 + 0x878);
      nv_printf(0xffffffff,"NVRM: GPU at PCI:%04x:%02x:%02x: %s\n",uVar1 >> 0x20,uVar1 >> 8 & 0xff,
                uVar1 & 0xff,local_78);
      portMemFree(local_78);
    }
    lVar4 = *(long *)(param_1 + 0x3c60);
    if ((lVar4 != 0) && (*(char *)(lVar4 + 0x1c) != '\0')) {
      nv_printf(0xffffffff,"NVRM: GPU Board Serial Number: %s\n",lVar4 + 0x1c);
    }
    *(undefined1 *)(param_2 + 0x199) = 1;
  }
  if (((int)param_3 == 0x2d) && (param_3 >> 0x20 != 0)) {
    local_78 = 0;
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    nvDbgSnprintf(&local_78,0x40," caused by previous Xid %d",(int)(param_3 >> 0x20));
  }
  else {
    local_78 = 0;
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
  }
  uVar1 = *(ulong *)(param_1 + 0x878);
  if (param_5 == (undefined *)0x0) {
    param_5 = &DAT_00d7399b;
  }
  uVar8 = uVar1 >> 8 & 0xff;
  if (local_90 == 0) {
    nv_printf(0xffffffff,"NVRM: Xid (PCI:%04x:%02x:%02x): %d, %s%s\n",uVar1 >> 0x20,uVar8,
              uVar1 & 0xff,param_3 & 0xffffffff,param_5);
  }
  else {
    nv_printf(0xffffffff,"NVRM: Xid (PCI:%04x:%02x:%02x): %d, pid=%s, name=%s, %s%s\n",uVar1 >> 0x20
              ,uVar8,uVar1 & 0xff,param_3 & 0xffffffff,&local_84,local_90,param_5,&local_78);
  }
  portMemFree(lVar7);
  return;
}


// ===== 00424ef0 krcTestAllowAlloc_IMPL =====

undefined8 krcTestAllowAlloc_IMPL(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  byte local_10 [8];
  
  if ((*(char *)(param_2 + 0x188) != '\0') && ((*(uint *)(param_2 + 0x1e0) & param_3) != 0)) {
    uVar1 = tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),local_10);
    if (((int)uVar1 != 0) || ((local_10[0] & 0x80) == 0)) {
      uVar1 = 1;
    }
    return uVar1;
  }
  return 1;
}


// ===== 00424f40 krcCheckBusError_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 krcCheckBusError_KERNEL(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint local_68;
  undefined4 local_64;
  undefined1 local_60 [4];
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  
  lVar1 = *(long *)(param_1 + 7000);
  local_68 = 0;
  lVar2 = *(long *)(g_pSys + 0x208);
  local_64 = 0;
  if (lVar1 == 0) {
    return 0;
  }
  iVar3 = (**(code **)(param_1 + 0x168))();
  if (iVar3 != 3) {
    return 0;
  }
  kbifClearConfigErrors_IMPL(param_1,lVar1,1,0xffffffff);
  if (lVar2 == 0) {
    return 0;
  }
  iVar3 = clPcieReadDevCtrlStatus_IMPL(param_1,lVar2,&local_68,&local_64);
  if ((iVar3 == 0) && (local_68 != 0)) {
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x1e7,"krcCheckBusError_KERNEL",1,
                 "NVRM: PCI-E corelogic: Pending errors in DEV_CTRL_STATUS = %08X\n",local_64);
    uVar4 = local_68;
    if ((local_68 & 1) != 0) {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x1f0,"krcCheckBusError_KERNEL",1,
                   "NVRM: PCI-E corelogic: CORR_ERROR_DETECTED\n");
      local_68 = local_68 & 0xfffffffe;
    }
    if ((local_68 & 2) != 0) {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x1f8,"krcCheckBusError_KERNEL",1,
                   "NVRM: PCI-E corelogic: NON_FATAL_ERROR_DETECTED\n");
    }
    if ((local_68 & 4) != 0) {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x1fd,"krcCheckBusError_KERNEL",4,
                   "NVRM: PCI-E corelogic: FATAL_ERROR_DETECTED\n");
    }
    if ((local_68 & 8) != 0) {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x202,"krcCheckBusError_KERNEL",1,
                   "NVRM: PCI-E corelogic: UNSUPP_REQUEST_DETECTED\n");
    }
    iVar3 = clPcieReadAerCapability_IMPL(param_1,lVar2,local_60);
    if ((iVar3 != 0) || ((local_30 & 0xfffffe7f) == 0 && local_5c == 0)) goto LAB_0042524f;
  }
  else {
    iVar3 = clPcieReadAerCapability_IMPL(param_1,lVar2,local_60);
    if (iVar3 != 0) {
      return 0;
    }
    uVar4 = 0;
    if ((local_30 & 0xfffffe7f) == 0 && local_5c == 0) {
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x20b,"krcCheckBusError_KERNEL",2,
               "NVRM: PCI-E Advanced Error Reporting Corelogic Info:\n");
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x20d,"krcCheckBusError_KERNEL",2,
               "NVRM:      Uncorr Error Status Register    : %08X\n",local_5c);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x210,"krcCheckBusError_KERNEL",2,
               "NVRM:      Uncorr Error Mask Register      : %08X\n",local_58);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x213,"krcCheckBusError_KERNEL",2,
               "NVRM:      Uncorr Error Severity Register  : %08X\n",local_54);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x216,"krcCheckBusError_KERNEL",2,
               "NVRM:      Corr Error Status Register      : %08X\n",local_50);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x219,"krcCheckBusError_KERNEL",2,
               "NVRM:      Corr Error Mask Register        : %08X\n",local_4c);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x21c,"krcCheckBusError_KERNEL",2,
               "NVRM:      Advanced Err Cap & Ctrl Register: %08X\n",local_48);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x21f,"krcCheckBusError_KERNEL",2,
               "NVRM:      Header Log [0-3]                : %08X\n",local_44);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x222,"krcCheckBusError_KERNEL",2,
               "NVRM:      Header Log [4-7]                : %08X\n",local_40);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x225,"krcCheckBusError_KERNEL",2,
               "NVRM:      Header Log [8-B]                : %08X\n",local_3c);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x228,"krcCheckBusError_KERNEL",2,
               "NVRM:      Header Log [C-F]                : %08X\n",local_38);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x22b,"krcCheckBusError_KERNEL",2,
               "NVRM:      Root Error Command Register     : %08X\n",local_34);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x22e,"krcCheckBusError_KERNEL",2,
               "NVRM:      Root Error Status               : %08X\n",local_30);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x231,"krcCheckBusError_KERNEL",2,
               "NVRM:      Error Source ID Register        : %08X\n",local_2c);
LAB_0042524f:
  if (uVar4 != 0) {
    clPcieClearDevCtrlStatus_IMPL(param_1,lVar2,&local_64);
  }
  return 0;
}


// ===== 004253a0 krcRcAndNotifyAllChannels_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void krcRcAndNotifyAllChannels_IMPL(long param_1,undefined8 param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  long local_80;
  undefined1 local_78 [24];
  undefined1 local_60 [48];
  
  lVar3 = gpuGetKernelFifoShared_IMPL();
  if (lVar3 != 0) {
    pcVar4 = "";
    if (param_4 != '\0') {
      pcVar4 = "user ";
    }
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc.c",0x2c7,"krcRcAndNotifyAllChannels_IMPL",4,
                 "NVRM: RC all %schannels for critical error %d.\n",pcVar4,param_3);
    kfifoGetChannelIterator_IMPL(param_1,lVar3,local_60,0xffffffff);
    while( true ) {
      iVar2 = kfifoGetNextKernelChannel_IMPL(param_1,lVar3,local_60,&local_80);
      if (iVar2 != 0) break;
      cVar1 = kchannelCheckIsKernel_IMPL(local_80);
      if ((cVar1 == '\0') || (param_4 == '\0')) {
        (**(code **)(lVar3 + 0x2e8))(param_1,lVar3,local_80);
      }
    }
    timeoutSet(param_1 + 0x1af0,local_78,0,0);
    kfifoGetChannelIterator_IMPL(param_1,lVar3,local_60,0xffffffff);
    while( true ) {
      iVar2 = kfifoGetNextKernelChannel_IMPL(param_1,lVar3,local_60,&local_80);
      if (iVar2 != 0) break;
      cVar1 = kchannelCheckIsKernel_IMPL(local_80);
      if ((cVar1 == '\0') || (param_4 == '\0')) {
        (**(code **)(lVar3 + 0x2f0))(param_1,lVar3,local_80,local_78);
        iVar2 = krcErrorSetNotifier_IMPL
                          (param_1,param_2,local_80,param_3,*(undefined4 *)(local_80 + 0x42c),0);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "krcErrorSetNotifier(pGpu, pKernelRc, pKernelChannel, exceptType, kchannelGetEngineType(pKernelChannel), RC_NOTIFIER_SCOPE_CHANNEL)"
                     ,"src/kernel/gpu/rc/kernel_rc.c",0x2e8);
        }
        iVar2 = krcErrorSendEventNotifications_KERNEL
                          (param_1,param_2,local_80,*(undefined4 *)(local_80 + 0x42c),0,param_3,0,0,
                           0);
        if (iVar2 != 0) {
          nvAssertOkFailedNoLog
                    (iVar2,
                     "krcErrorSendEventNotifications_HAL(pGpu, pKernelRc, pKernelChannel, kchannelGetEngineType(pKernelChannel), 0, exceptType, RC_NOTIFIER_SCOPE_CHANNEL, 0, NV_FALSE)"
                     ,"src/kernel/gpu/rc/kernel_rc.c",0x2ef);
        }
      }
    }
    return;
  }
  nvAssertFailedNoLog("pKernelFifo != NULL","src/kernel/gpu/rc/kernel_rc.c",0x2c5);
  return;
}


// ===== 004255e0 krcResetCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int krcResetCallback(undefined4 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                    long *param_5,char param_6)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  undefined8 uStack_f0;
  int local_dc;
  undefined8 local_d0;
  long local_c8;
  long local_c0;
  undefined1 local_b8 [144];
  
  lVar3 = g_pSys;
  if (param_5 == (long *)0x0) {
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_callback.c",0xe5,"krcResetCallback",4,
                 "NVRM: -- No context skipping reset of channel...\n");
    return 0;
  }
  if (param_6 != '\0') {
    portMemFree(param_5);
    return 0;
  }
  if (*(char *)(*param_5 + 0x908) == '\0') {
    iVar4 = osCondAcquireRmSema(*(undefined8 *)(g_pSys + 0x160));
    if (iVar4 != 0) {
      return 99;
    }
    iVar4 = rmGpuLocksAcquire(0,0x10001);
    if (iVar4 == 0) {
      local_c8 = 0;
      threadStateInitISRAndDeferredIntHandler(local_b8,*param_5,4);
      local_dc = serverGetClientUnderLock(g_resServ,param_1,&local_d0);
      if (local_dc != 0) {
        uVar6 = 0xb4;
        goto LAB_00425957;
      }
      local_dc = CliGetKernelChannel(local_d0,param_4,&local_c8);
      if (local_dc != 0) {
        uVar6 = 0xb8;
        goto LAB_00425980;
      }
      if (local_c8 != 0) {
        local_c0 = 0;
        plVar1 = *(long **)(*(long *)(local_c8 + 0x140) + 0x48);
        local_dc = (**(code **)(*param_5 + 0x3b90))
                             (*param_5 + 0x3b58,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],
                              0x506f0105,&local_c0,8);
        uStack_f0 = extraout_RDX;
        goto LAB_00425739;
      }
      nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/rc/kernel_rc_callback.c",0xbd);
      local_dc = 0x40;
      goto LAB_00425920;
    }
  }
  else {
    iVar4 = osCondAcquireRmSema();
    if (iVar4 != 0) {
      return 99;
    }
    iVar4 = rmGpuLocksAcquire(1,0x10001);
    if (iVar4 == 0) {
      local_d0 = 0;
      local_c0 = 0;
      threadStateInitISRAndDeferredIntHandler(local_b8,*param_5,4);
      local_dc = serverGetClientUnderLock(g_resServ,param_1,&local_c8);
      uVar6 = 0x48;
      if (local_dc == 0) {
        local_dc = CliGetKernelChannel(local_c8,param_4,&local_c0);
        uVar6 = 0x4c;
        if (local_dc == 0) {
          if (local_c0 != 0) {
            local_d0 = *(undefined8 *)((long)param_5 + 0x14);
            uStack_f0 = 0x425830;
            lVar5 = gpuGetRpc(*param_5);
            if (lVar5 == 0) {
              nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/rc/kernel_rc_callback.c",0x58);
              local_dc = 0x1a;
              uStack_f0 = extraout_RDX_01;
            }
            else {
              lVar2 = *param_5;
              if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
                local_dc = rpcDmaControl_wrapper(lVar2,lVar5,param_1,param_4,0x506f0105,&local_d0,8)
                ;
              }
              else {
                local_dc = (**(code **)(lVar2 + 0x3b90))
                                     (lVar2 + 0x3b58,param_1,param_4,0x506f0105,&local_d0,8);
                uStack_f0 = extraout_RDX_00;
              }
            }
LAB_00425739:
            rmGpuLocksRelease(0,0,uStack_f0);
            threadStateFreeISRAndDeferredIntHandler(local_b8,*param_5,4);
            portMemFree(param_5);
            goto LAB_004258cd;
          }
          nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/rc/kernel_rc_callback.c",0x51
                             );
          local_dc = 0x40;
        }
        else {
LAB_00425980:
          nvAssertOkFailedNoLog
                    (local_dc,"CliGetKernelChannel(pClient, hChannel, &pKernelChannel)",
                     "src/kernel/gpu/rc/kernel_rc_callback.c",uVar6);
        }
      }
      else {
LAB_00425957:
        nvAssertOkFailedNoLog
                  (local_dc,"serverGetClientUnderLock(&g_resServ, hClient, &pClient)",
                   "src/kernel/gpu/rc/kernel_rc_callback.c",uVar6);
      }
LAB_00425920:
      rmGpuLocksRelease(0,0);
      goto LAB_004258cd;
    }
  }
  local_dc = 99;
LAB_004258cd:
  osReleaseRmSema(*(undefined8 *)(lVar3 + 0x160),0);
  return local_dc;
}


// ===== 004259f5 krcErrorInvokeCallback_IMPL.cold =====

void krcErrorInvokeCallback_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00425a00 krcErrorInvokeCallback_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong krcErrorInvokeCallback_IMPL
                (long param_1,undefined8 param_2,long param_3,undefined4 *param_4,undefined4 param_5
                ,undefined4 param_6,int param_7,int param_8)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  code *pcVar5;
  char cVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  ulong uVar14;
  undefined4 local_70;
  int local_64;
  undefined1 local_60 [12];
  char local_54 [4];
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 uStack_3c;
  
  lVar2 = *(long *)(g_pSys + 0x228);
  uVar3 = *(undefined8 *)(param_1 + 0x1bc0);
  local_64 = param_7;
  if (param_3 == 0) {
    nvCheckFailedNoLog(4,"pKernelChannel != NULL","src/kernel/gpu/rc/kernel_rc_callback.c",0x10b);
    return 1;
  }
  lVar11 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_3 + 0x140) + 0x48),
                              __nvoc_class_def_RmClient);
  if (lVar11 == 0) {
    return 1;
  }
  if ((((*(long *)(param_1 + 0x1bc0) != 0) &&
       (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar6 != '\0')) &&
      (param_7 - 1U < 0x53)) &&
     (cVar6 = kmigmgrIsEnginePartitionable_IMPL(param_1,uVar3,param_7), cVar6 != '\0')) {
    iVar9 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (param_1,uVar3,*(undefined8 *)(*(long *)(param_3 + 0x158) + 0xe8),&local_48);
    if (iVar9 != 0) {
      return 1;
    }
    cVar6 = kmigmgrIsEngineInInstance_IMPL
                      (param_1,uVar3,param_7,local_48,CONCAT44(uStack_3c,local_40));
    if (cVar6 == '\0') {
      uVar10 = gpuGetNv2080EngineType_IMPL(param_7);
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_callback.c",0x123,"krcErrorInvokeCallback_IMPL",4,
                   "NVRM: RcErroCallback requested for an unsupported engine 0x%x (0x%x)\n",uVar10,
                   param_7);
      return 1;
    }
    iVar9 = kmigmgrGetGlobalToLocalEngineType_IMPL
                      (param_1,uVar3,local_48,CONCAT44(uStack_3c,local_40),param_7,&local_64);
    if (iVar9 != 0) {
      return 1;
    }
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    cVar6 = osCheckCallback();
    if (cVar6 == '\0') goto LAB_00425cbd;
LAB_00425add:
    lVar13 = *(long *)(*(long *)(param_3 + 0x158) + 0xe8);
    if (lVar13 == 0) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)invalidInstructionException();
      (*pcVar5)();
    }
    uVar10 = *(undefined4 *)(*(long *)(*(long *)(lVar13 + 0x110) + 0x48) + 0x10);
    lVar13 = *(long *)(*(long *)(param_3 + 0x140) + 0x48);
    if (*(char *)(*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) + 0x158) == '\0') {
      local_70 = *(undefined4 *)(*(long *)(lVar13 + 0x18) + 0x10);
    }
    else {
      local_70 = *(undefined4 *)(lVar13 + 0x10);
    }
    plVar12 = (long *)portMemAllocNonPaged(0x38);
    if (plVar12 != (long *)0x0) {
      portMemSet(plVar12,0,0x38);
      *plVar12 = param_1;
      uVar7 = *(undefined4 *)(param_3 + 0x2b4);
      *(undefined4 *)((long)plVar12 + 0xc) = 0xffffffff;
      *(undefined4 *)(plVar12 + 1) = uVar7;
      uVar7 = *(undefined4 *)(**(long **)(*(long *)(param_3 + 0x140) + 0x48) + 0x48);
      *(undefined4 *)((long)plVar12 + 0x14) = param_5;
      *(undefined4 *)(plVar12 + 2) = uVar7;
      uVar7 = gpuGetNv2080EngineType_IMPL(local_64);
      *(undefined4 *)(plVar12 + 3) = uVar7;
      *(undefined4 *)((long)plVar12 + 0x1c) = *(undefined4 *)(param_1 + 0x7b8);
      if (param_4 != (undefined4 *)0x0) {
        *(undefined4 *)(plVar12 + 4) = *param_4;
        *(undefined4 *)((long)plVar12 + 0x24) = param_4[1];
        *(undefined4 *)(plVar12 + 5) = param_4[2];
        lVar13 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x2a8))();
        plVar12[6] = lVar13;
      }
    }
    iVar9 = (**(code **)(param_1 + 0x110))(param_1,local_54);
    if (((iVar9 == 0) && (local_54[0] != '\0')) && (*(char *)(param_1 + 0x49d) != '\0')) {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_callback.c",0x167,"krcErrorInvokeCallback_IMPL",6,
                   "NVRM: Gpu marked for reset. Triggering TDR.\n");
      uVar14 = 0;
      gpuNotifySubDeviceEvent_IMPL(param_1,0xc5,0,0,0,0);
      goto LAB_00425c99;
    }
    plVar4 = *(long **)(*(long *)(param_3 + 0x140) + 0x48);
    uVar7 = (undefined4)plVar4[2];
    uVar1 = *(undefined4 *)(*plVar4 + 0x48);
    if (*(char *)(param_1 + 0x909) == '\0') {
      uVar8 = osRCCallback(param_1,uVar1,uVar10,local_70,uVar7,param_6,param_5,plVar12,
                           krcResetCallback);
    }
    else {
      uVar8 = osRCCallback_v2(param_1,uVar1,uVar10,local_70,uVar7,param_6,param_5,0,plVar12,
                              krcResetCallback);
    }
    if ((uVar8 & 0xfffffffd) == 0) {
      if (uVar8 == 0) {
        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_callback.c",0x18e,"krcErrorInvokeCallback_IMPL",4,
                     "NVRM: -- Drivers tells RM to ignore\n");
      }
      portMemFree(plVar12);
    }
    else if ((*(char *)(param_1 + 0x909) != '\0') && (uVar8 == 1)) {
      local_48 = 0;
      plVar4 = *(long **)(*(long *)(param_3 + 0x140) + 0x48);
      (**(code **)(*plVar12 + 0x3b90))
                (*plVar12 + 0x3b58,*(undefined4 *)(*plVar4 + 0x48),(int)plVar4[2],0x506f0105,
                 &local_48,8);
    }
    uVar14 = CONCAT71((int7)((ulong)param_1 >> 8),uVar8 != 0);
  }
  else {
    cVar6 = osCheckCallback_v2(param_1);
    if (cVar6 != '\0') goto LAB_00425add;
LAB_00425cbd:
    uVar14 = 1;
    tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),local_60);
    local_48 = CONCAT44((int)local_60._0_8_,SUB84(local_60._0_8_,4));
    local_40 = param_6;
    uStack_3c = param_5;
    CliGetChannelClassInfo
              (*(undefined4 *)(*(long *)(*(long *)(param_3 + 0x140) + 0x48) + 0x11c),local_54);
    kchannelNotifyEvent_IMPL(param_3,local_50,0,0,&local_48,0x10);
  }
  if (param_8 == -1) {
    return uVar14 & 0xffffffff;
  }
  rcdbUpdateRcDiagRecContext_IMPL
            (lVar2,(undefined2)param_8,*(short *)(lVar2 + 0x2f8) + -1,
             *(undefined4 *)(lVar11 + 0x118),0);
LAB_00425c99:
  return uVar14 & 0xffffffff;
}


// ===== 00425f70 subdeviceCtrlCmdRcReadVirtualMem_IMPL =====

undefined8 subdeviceCtrlCmdRcReadVirtualMem_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_10;
  
  if (((*(ulong *)(param_2 + 4) != 0) && ((*(ulong *)(param_2 + 4) & 7) == 0)) && (param_2[6] != 0))
  {
    lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
    iVar3 = CliGetKernelChannelWithDevice
                      (*puVar2,*(undefined4 *)(puVar2[3] + 0x10),*param_2,&local_10);
    if (iVar3 == 0) {
      uVar4 = krcReadVirtMem_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1c18),local_10,
                                  *(undefined8 *)(param_2 + 2),*(undefined8 *)(param_2 + 4),
                                  param_2[6]);
      return uVar4;
    }
    return 0x1f;
  }
  return 0x1f;
}


// ===== 00426010 krcSubdeviceCtrlGetErrorInfoCheckPermissions_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte krcSubdeviceCtrlGetErrorInfoCheckPermissions_KERNEL(undefined8 param_1,long param_2)

{
  long lVar1;
  char cVar2;
  byte bVar3;
  long lVar4;
  long *plVar5;
  
  lVar1 = *(long *)(*(long *)(param_2 + 0x158) + 0xe0);
  lVar4 = resservGetTlsCallContext();
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/rc/kernel_rc_ctrl.c",0x53);
    return 0x40;
  }
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(lVar4 + 8),__nvoc_class_def_RmClient);
  if (plVar5 == (long *)0x0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/rc/kernel_rc_ctrl.c",0x56);
    bVar3 = 0x23;
  }
  else {
    cVar2 = (**(code **)(*plVar5 + 0xe0))(plVar5,*(undefined4 *)(lVar4 + 0x28));
    if (cVar2 != '\0') {
      return 0;
    }
    if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
      cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
      if (cVar2 != '\0') {
        cVar2 = rmclientIsCapable_IMPL(plVar5,3);
        return -(cVar2 == '\0') & 0x1b;
      }
    }
    bVar3 = 0x1b;
  }
  return bVar3;
}


// ===== 00426150 subdeviceCtrlCmdRcGetErrorCount_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdRcGetErrorCount_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  iVar3 = krcSubdeviceCtrlGetErrorInfoCheckPermissions_KERNEL
                    (*(undefined8 *)(lVar1 + 0x1c18),param_1);
  if (iVar3 == 0) {
    if (*(char *)(lVar1 + 0x909) != '\0') {
      plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      (**(code **)(lVar1 + 0x3b90))
                (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x20802205,param_2,4)
      ;
      return;
    }
    *param_2 = *(undefined4 *)(*(long *)(g_pSys + 0x228) + 0x70);
  }
  return;
}


// ===== 00426200 krcSubdeviceCtrlCmdRcGetErrorV2_IMPL =====

int krcSubdeviceCtrlCmdRcGetErrorV2_IMPL(undefined8 param_1,undefined8 param_2,int *param_3)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  undefined8 local_180;
  undefined1 local_178 [344];
  
  lVar1 = *(long *)(g_pSys + 0x228);
  param_3[1] = 0;
  plVar5 = *(long **)(lVar1 + 0x78);
  if (plVar5 != (long *)0x0) {
    if (*param_3 == 0) {
LAB_00426265:
      if (*(char *)((long)plVar5 + 0x19) != -0x6f) {
        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_ctrl.c",0xed,
                     "krcSubdeviceCtrlCmdRcGetErrorV2_IMPL",4,
                     "NVRM: NVRM-RC: unknown error element type: %d\n");
        return 0x56;
      }
      prbEncStart(local_178,0x5a7ce0,param_3 + 4,0x1ff8,0);
      puVar2 = (undefined8 *)plVar5[1];
      do {
        if (puVar2 == (undefined8 *)0x0) {
          iVar3 = 0;
          local_180 = 0;
          iVar4 = prbEncFinish(local_178,&local_180);
          param_3[2] = 0x88301;
          param_3[3] = iVar4;
LAB_00426322:
          param_3[1] = iVar4 + 8;
          return iVar3;
        }
        iVar3 = prbEncNestedStart(local_178,&prb_fields_dcl_errorblock);
        if (iVar3 != 0) {
LAB_00426304:
          local_180 = 0;
          iVar4 = prbEncFinish(local_178,&local_180);
          goto LAB_00426322;
        }
        iVar3 = prbEncCatMsg(local_178,*puVar2,*(undefined4 *)(puVar2 + 1));
        iVar4 = prbEncNestedEnd(local_178);
        if ((iVar3 != 0) || (iVar3 = iVar4, iVar4 != 0)) goto LAB_00426304;
        puVar2 = (undefined8 *)puVar2[2];
      } while( true );
    }
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      plVar5 = (long *)*plVar5;
      if (*param_3 == iVar3) {
        if (plVar5 == (long *)0x0) {
          return 0;
        }
        goto LAB_00426265;
      }
    } while (plVar5 != (long *)0x0);
  }
  return 0;
}


// ===== 004263c0 subdeviceCtrlCmdRcGetErrorV2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdRcGetErrorV2_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  long *plVar3;
  int iVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined8 *)(lVar1 + 0x1c18);
  iVar4 = krcSubdeviceCtrlGetErrorInfoCheckPermissions_KERNEL(uVar2,param_1);
  if (iVar4 != 0) {
    return;
  }
  if (*(char *)(lVar1 + 0x909) != '\0') {
    plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
    (**(code **)(lVar1 + 0x3b90))
              (lVar1 + 0x3b58,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2],0x20802213,param_2,
               0x2008);
    return;
  }
  krcSubdeviceCtrlCmdRcGetErrorV2_IMPL(uVar2,param_1,param_2);
  return;
}


// ===== 00426469 krcCliresCtrlNvdGetRcerrRptCheckPermissions_KERNEL.cold =====

void krcCliresCtrlNvdGetRcerrRptCheckPermissions_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00426480 krcCliresCtrlNvdGetRcerrRptCheckPermissions_KERNEL =====

byte krcCliresCtrlNvdGetRcerrRptCheckPermissions_KERNEL
               (undefined8 param_1,long param_2,long param_3)

{
  code *pcVar1;
  byte bVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = resservGetTlsCallContext();
  if (param_2 != 0) {
    lVar4 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_2 + 0xe0) + 0x48),
                               __nvoc_class_def_RmClient);
    if (lVar4 == 0) {
      bVar2 = 0x57;
    }
    else {
      bVar2 = 0;
      if (*(uint *)(lVar3 + 0x28) < 2) {
        bVar2 = -(*(int *)(param_3 + 0x1c) == 0) & 0x1b;
      }
    }
    return bVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00426500 subdeviceCtrlCmdGetRcRecovery_VF =====

undefined8 subdeviceCtrlCmdGetRcRecovery_VF(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  return 0;
}


// ===== 00426510 krcReadVirtMem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int krcReadVirtMem_IMPL(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,
                       long param_5,uint param_6)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  ulong uVar9;
  uint uVar10;
  undefined8 uVar11;
  ulong uVar12;
  long local_200;
  undefined4 local_1dc;
  undefined8 local_1d8;
  undefined1 *local_1d0;
  undefined8 local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined1 local_1b0 [384];
  
  uVar11 = *(undefined8 *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_1 + 0x1bb8);
  local_1d0 = (undefined1 *)0x0;
  local_1c8 = 0;
  local_1c0 = 0;
  local_1b8 = 0;
  lVar5 = portMemAllocNonPaged(0x1000);
  if (lVar5 == 0) {
    iVar4 = 0x1a;
  }
  else {
    local_1d0 = local_1b0;
    local_1c8 = 0;
    uVar10 = (uint)(param_4 >> 0xc) & 0x1ffff;
    uVar6 = (param_6 - 1) + (uint)param_4 >> 0xc & 0x1ffff;
    if (uVar6 < uVar10) {
      iVar4 = 0;
    }
    else {
      uVar12 = param_4 & 0xfffffffffffff000;
      uVar3 = (uint)param_4 & 0xfff;
      lVar1 = uVar12 + 0x1000;
      uVar8 = 0x1000 - uVar3;
      local_200 = param_5;
      while (iVar4 = (**(code **)(lVar2 + 0x198))
                               (param_1,lVar2,param_3,uVar12,&local_1d8,&local_1dc), iVar4 == 0) {
        memdescCreateExisting(local_1b0,param_1,0x1000,local_1dc,1,0);
        memdescDescribe(local_1b0,local_1dc,local_1d8,0x1000);
        iVar4 = memmgrMemRead_IMPL(uVar11,&local_1d0,lVar5,0x1000,0);
        if (iVar4 != 0) {
          uVar11 = 0x5a;
          pcVar7 = "memmgrMemRead(pMemoryManager, &surf, pMem, RM_PAGE_SIZE, TRANSFER_FLAGS_NONE)";
          goto LAB_0042674c;
        }
        if (param_6 <= uVar8) {
          uVar8 = param_6;
        }
        uVar12 = uVar12 + 0x1000;
        uVar9 = (ulong)uVar8;
        portMemCopy(local_200,uVar9,(ulong)uVar3 + lVar5,uVar9);
        memdescDestroy(local_1b0);
        local_200 = local_200 + uVar9;
        param_6 = param_6 - uVar8;
        uVar8 = 0x1000;
        if (lVar1 + (ulong)(uVar6 - uVar10) * 0x1000 == uVar12) goto LAB_00426769;
        uVar3 = 0;
      }
      uVar11 = 0x4e;
      pcVar7 = 
      "dmaXlateVAtoPAforChannel_HAL(pGpu, pDma, pKernelChannel, virtAddr, &physaddr, &memtype)";
LAB_0042674c:
      nvCheckOkFailedNoLog(4,iVar4,pcVar7,"src/kernel/gpu/rc/kernel_rc_misc.c",uVar11);
    }
LAB_00426769:
    portMemFree(lVar5);
  }
  return iVar4;
}


// ===== 004267d0 _krcErrorWriteNotifierCpuMemHelper =====

undefined8
_krcErrorWriteNotifierCpuMemHelper
          (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined2 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = memdescGetAddressSpace(*(undefined8 *)(param_2 + 0x118));
  if (uVar2 < 3) {
    if (uVar2 == 0) {
      return 0x56;
    }
    uVar1 = gpuGetNv2080EngineType_IMPL(param_5);
    notifyFillNotifierMemory(param_1,param_2,param_4,uVar1,param_6,0);
  }
  else {
    if (uVar2 != 4) {
      return 0x56;
    }
    uVar1 = gpuGetNv2080EngineType_IMPL(param_5);
    uVar3 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x118),3,0);
    notifyFillNotifierGPUVA
              (param_1,param_3,*(undefined4 *)(*(long *)(*(long *)(param_2 + 0xb8) + 0x48) + 0x10),
               uVar3,param_4,uVar1,param_6,0);
  }
  return 0;
}


// ===== 004268a5 krcErrorWriteNotifier_CPU.cold =====

void krcErrorWriteNotifier_CPU_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004268d0 krcErrorWriteNotifier_CPU =====

int krcErrorWriteNotifier_CPU
              (undefined8 param_1,undefined8 param_2,long param_3,int param_4,undefined4 param_5,
              undefined4 param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  long local_48;
  undefined8 local_40 [2];
  
  lVar7 = *(long *)(*(long *)(param_3 + 0x158) + 0xe8);
  if ((param_4 - 0x5eU < 2) || (param_4 == 0x30)) {
    cVar3 = hypervisorIsVgxHyper_IMPL();
    if ((cVar3 == '\0') || (*(int *)(param_3 + 0x270) == 0)) goto LAB_00426922;
    iVar6 = ctxdmaGetByHandle_IMPL
                      (**(undefined8 **)(*(long *)(param_3 + 0x140) + 0x48),
                       *(int *)(param_3 + 0x270),&local_48);
    if (iVar6 != 0) {
      if (lVar7 == 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)invalidInstructionException();
        (*pcVar2)();
      }
      iVar6 = memGetByHandleAndDevice_IMPL
                        (**(undefined8 **)(*(long *)(param_3 + 0x140) + 0x48),
                         *(undefined4 *)(param_3 + 0x270),
                         *(undefined4 *)(*(long *)(*(long *)(lVar7 + 0x110) + 0x48) + 0x10),local_40
                        );
      if (iVar6 == 0) {
        iVar6 = _krcErrorWriteNotifierCpuMemHelper
                          (param_1,local_40[0],lVar7,param_4,param_5,param_6);
        if (iVar6 == 0) goto LAB_00426c52;
        iVar6 = 0x56;
      }
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0x9c,"krcErrorWriteNotifier_CPU",4,
                   "NVRM: No valid error notifier found for ECC error context 0x%x\nSkipping notification update\n"
                   ,*(undefined4 *)(param_3 + 0x270));
      iVar5 = ctxdmaGetByHandle_IMPL
                        (**(undefined8 **)(*(long *)(param_3 + 0x140) + 0x48),
                         *(undefined4 *)(param_3 + 0x250),&local_48);
      if (iVar5 == 0) goto LAB_00426a90;
      goto LAB_0042695a;
    }
    uVar4 = gpuGetNv2080EngineType_IMPL(param_5);
    notifyFillNotifier(param_1,local_48,param_4,uVar4,param_6);
LAB_00426c52:
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0x96,"krcErrorWriteNotifier_CPU",1,
                 "NVRM: notified (ECC) channel 0x%08x\n",
                 *(int *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4));
    uVar1 = *(undefined4 *)(param_3 + 0x250);
  }
  else {
    hypervisorIsVgxHyper_IMPL();
LAB_00426922:
    uVar1 = *(undefined4 *)(param_3 + 0x250);
  }
  iVar5 = ctxdmaGetByHandle_IMPL
                    (**(undefined8 **)(*(long *)(param_3 + 0x140) + 0x48),uVar1,&local_48);
  iVar6 = 0;
  if (iVar5 == 0) {
LAB_00426a90:
    uVar8 = 0;
    if (local_48 != 0) {
      uVar8 = *(undefined8 *)(local_48 + 0x100);
    }
    lVar7 = inotifyGetNotificationList_IMPL(uVar8);
    uVar4 = gpuGetNv2080EngineType_IMPL(param_5);
    notifyFillNotifier(param_1,local_48,param_4,uVar4,param_6);
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0xae,"krcErrorWriteNotifier_CPU",1,
                 "NVRM: notified channel 0x%08x\n",
                 *(int *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4));
    if (lVar7 == 0) {
      return iVar6;
    }
    if (local_48 != 0) {
      notifyEvents(param_1,lVar7,0,0,
                   *(undefined4 *)(*(long *)(*(long *)(local_48 + 0xe8) + 0x48) + 0x10),iVar6,1);
      return iVar6;
    }
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (lVar7 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
LAB_0042695a:
  iVar6 = memGetByHandleAndDevice_IMPL
                    (**(undefined8 **)(*(long *)(param_3 + 0x140) + 0x48),
                     *(undefined4 *)(param_3 + 0x250),
                     *(undefined4 *)(*(long *)(*(long *)(lVar7 + 0x110) + 0x48) + 0x10),local_40);
  if (iVar6 == 0) {
    iVar6 = _krcErrorWriteNotifierCpuMemHelper(param_1,local_40[0],lVar7,param_4,param_5,param_6);
    if (iVar6 == 0) {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0xc9,"krcErrorWriteNotifier_CPU",1,
                   "NVRM: notified channel 0x%08x\n",
                   *(int *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4));
      iVar6 = 0;
    }
    else {
      iVar6 = 0x56;
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0xcf,"krcErrorWriteNotifier_CPU",4,
                   "NVRM: No valid error notifier found for error context 0x%x\nSkipping notification update\n"
                   ,*(undefined4 *)(param_3 + 0x250));
    }
  }
  return iVar6;
}


// ===== 00426ca0 krcErrorSetNotifier_IMPL =====

int krcErrorSetNotifier_IMPL
              (long param_1,undefined8 param_2,long param_3,undefined4 param_4,int param_5,
              int param_6)

{
  long lVar1;
  undefined8 uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  long *plVar8;
  long *extraout_RDX;
  long *plVar9;
  undefined1 auVar10 [16];
  undefined8 local_58;
  long *local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  auVar10 = gpuGetKernelFifoShared_IMPL();
  plVar8 = auVar10._8_8_;
  lVar7 = auVar10._0_8_;
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/rc/kernel_rc_notification.c",0xfd);
    return 0x21;
  }
  if (*(char *)(param_3 + 0x2d5) != '\0') {
    sysSetRecoveryRebootRequired_IMPL(g_pSys,1);
    plVar8 = extraout_RDX;
  }
  if (((param_6 == 1) && (*(char *)(lVar7 + 0x4b3) != '\0')) && (*(char *)(param_1 + 0x4a3) == '\0')
     ) {
    local_50 = *(long **)(*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) + 0x140);
    plVar9 = (long *)*local_50;
    bVar3 = false;
    if (plVar9 == (long *)0x0) {
      return 0;
    }
  }
  else {
    iVar5 = kfifoChannelListCreate_IMPL(param_1,lVar7,&local_50);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"kfifoChannelListCreate(pGpu, pKernelFifo, &pChanList)",
                 "src/kernel/gpu/rc/kernel_rc_notification.c",0x117);
      return iVar5;
    }
    iVar5 = kfifoChannelListAppend_IMPL(param_1,lVar7,param_3,local_50);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"kfifoChannelListAppend(pGpu, pKernelFifo, pKernelChannel, pChanList)",
                 "src/kernel/gpu/rc/kernel_rc_notification.c",0x11c);
      goto LAB_00426e1c;
    }
    plVar9 = (long *)*local_50;
    if (plVar9 == (long *)0x0) goto LAB_00426e1c;
    bVar3 = true;
    plVar8 = local_50;
  }
  do {
    lVar1 = *plVar9;
    local_58._4_4_ = param_5;
    if (((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) &&
       ((cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,*(long *)(param_1 + 0x1bc0),plVar8),
        cVar4 != '\0' && (param_5 - 1U < 0x53)))) {
      uVar2 = *(undefined8 *)(param_1 + 0x1bc0);
      iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL
                        (param_1,uVar2,*(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe8),&local_48);
      if (iVar5 != 0) break;
      cVar4 = kmigmgrIsEngineInInstance_IMPL(param_1,uVar2,param_5,local_48,local_40);
      if (cVar4 == '\0') {
        iVar5 = 0x1f;
        uVar6 = gpuGetNv2080EngineType_IMPL(param_5);
        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0x13a,"krcErrorSetNotifier_IMPL",4
                     ,"NVRM: Notifier requested for an unsupported engine 0x%x (0x%x)\n",uVar6,
                     param_5);
        break;
      }
      iVar5 = kmigmgrGetGlobalToLocalEngineType_IMPL
                        (param_1,uVar2,local_48,local_40,param_5,(long)&local_58 + 4);
      if (iVar5 != 0) break;
    }
    plVar8 = &local_58;
    iVar5 = krcErrorWriteNotifier_CPU(param_1,param_2,lVar1,param_4,local_58._4_4_,0xffff);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "krcErrorWriteNotifier_HAL(pGpu, pKernelRc, pKernelChannel, exceptType, localRmEngineType, 0xffff , &flushFlags)"
                 ,"src/kernel/gpu/rc/kernel_rc_notification.c",0x14a);
      break;
    }
    plVar9 = (long *)plVar9[1];
    iVar5 = 0;
  } while (plVar9 != (long *)0x0);
  if (!bVar3) {
    return iVar5;
  }
LAB_00426e1c:
  kfifoChannelListDestroy_IMPL(param_1,lVar7,local_50);
  return iVar5;
}


// ===== 00426fb7 krcErrorSendEventNotificationsCtxDma_FWCLIENT.cold =====

void krcErrorSendEventNotificationsCtxDma_FWCLIENT_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00426fd0 krcErrorSendEventNotificationsCtxDma_FWCLIENT =====

int krcErrorSendEventNotificationsCtxDma_FWCLIENT
              (long param_1,undefined8 param_2,long param_3,int param_4)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  long *local_38;
  long local_30;
  
  lVar4 = gpuGetKernelFifoShared_IMPL();
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)","src/kernel/gpu/rc/kernel_rc_notification.c",0x17e);
    return 0x40;
  }
  if ((param_4 == 1) && (*(char *)(lVar4 + 0x4b3) != '\0')) {
    bVar2 = false;
    local_38 = *(long **)(*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) + 0x140);
    plVar6 = (long *)*local_38;
    if (plVar6 != (long *)0x0) {
LAB_00427050:
      do {
        iVar3 = ctxdmaGetByHandle_IMPL
                          (**(undefined8 **)(*(long *)(*plVar6 + 0x140) + 0x48),
                           *(undefined4 *)(*plVar6 + 0x250),&local_30);
        if (iVar3 == 0) {
          uVar7 = 0;
          if (local_30 != 0) {
            uVar7 = *(undefined8 *)(local_30 + 0x100);
          }
          lVar5 = inotifyGetNotificationList_IMPL(uVar7);
          if (lVar5 != 0) {
            if (local_30 == 0) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)invalidInstructionException();
              (*pcVar1)();
            }
            notifyEvents(param_1,lVar5,0,0,
                         *(undefined4 *)(*(long *)(*(long *)(local_30 + 0xe8) + 0x48) + 0x10),0,1);
          }
        }
        plVar6 = (long *)plVar6[1];
      } while (plVar6 != (long *)0x0);
      if (bVar2) {
        iVar3 = 0;
        goto LAB_004270dd;
      }
    }
    iVar3 = 0;
  }
  else {
    iVar3 = kfifoChannelListCreate_IMPL(param_1,lVar4,&local_38);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0x18d,
                   "krcErrorSendEventNotificationsCtxDma_FWCLIENT",4,
                   "NVRM: failed to create notification list\n");
      return iVar3;
    }
    iVar3 = kfifoChannelListAppend_IMPL(param_1,lVar4,param_3,local_38);
    if (iVar3 == 0) {
      plVar6 = (long *)*local_38;
      if (plVar6 != (long *)0x0) {
        bVar2 = true;
        goto LAB_00427050;
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_notification.c",0x194,
                   "krcErrorSendEventNotificationsCtxDma_FWCLIENT",4,
                   "NVRM: failed to insert channel into notification list\n");
    }
LAB_004270dd:
    kfifoChannelListDestroy_IMPL(param_1,lVar4,local_38);
  }
  return iVar3;
}


// ===== 004271f0 krcErrorSendEventNotifications_KERNEL =====

int krcErrorSendEventNotifications_KERNEL
              (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,
              undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined2 param_8)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = krcErrorSendEventNotificationsCtxDma_FWCLIENT();
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,
                 "krcErrorSendEventNotificationsCtxDma_HAL(pGpu, pKernelRc, pKernelChannel, scope)",
                 "src/kernel/gpu/rc/kernel_rc_notification.c",0x1c8,param_6);
      return iVar1;
    }
  }
  gpuNotifySubDeviceEvent_IMPL(param_1,0x25,0,0,param_6,param_8);
  return 0;
}


// ===== 00427270 krcWatchdogChangeState_IMPL =====

undefined8 krcWatchdogChangeState_IMPL(long param_1,long param_2,long param_3,int param_4)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  undefined8 uVar16;
  long lVar17;
  
  if (param_2 == 0) {
    lVar17 = param_1 + 0x1a0;
    piVar14 = (int *)(param_1 + 0x280);
  }
  else {
    lVar17 = param_2 + 0x148;
    piVar14 = (int *)(param_2 + 0x228);
  }
  iVar7 = *piVar14;
  iVar15 = piVar14[1];
  iVar8 = piVar14[2];
  cVar1 = *(char *)(param_3 + 0x699);
  cVar2 = *(char *)(param_3 + 0x69a);
  cVar3 = *(char *)(param_3 + 0x69b);
  uVar16 = 0;
  if (param_1 != 0) {
    uVar16 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar10 = gpuEngineGetGpu(uVar16);
  uVar12 = (ulong)(param_4 - 10U);
  if (4 < param_4 - 10U) {
    nvAssertFailedNoLog(&DAT_00d74940,"src/kernel/gpu/rc/kernel_rc_watchdog.c",0xf7);
    return 0x1f;
  }
  iVar9 = piVar14[1];
  bVar4 = *(byte *)((long)&CSWTCH_95 + uVar12);
  uVar16 = *(undefined8 *)(CSWTCH_98 + uVar12 * 8);
  iVar13 = *piVar14;
  if (((iVar9 != 0) && ((bVar4 & 1) != 0)) ||
     ((bVar5 = *(byte *)((long)&CSWTCH_96 + uVar12), iVar13 != 0 && ((bVar5 & 1) != 0)))) {
    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x10c,"krcWatchdogChangeState_IMPL",4,
                 "NVRM: Cannot %s on GPU 0x%x, due to another client\'s request\n(Enable requests: %d, Disable requests: %d)\n"
                 ,uVar16,*(undefined4 *)(lVar10 + 0x7ac),iVar13,iVar9);
    return 99;
  }
  bVar6 = *(byte *)((long)&CSWTCH_97 + uVar12);
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x117,"krcWatchdogChangeState_IMPL",1,
               "NVRM: (before) op: %s, GPU 0x%x, enableRefCt: %d, disableRefCt: %d, softDisableRefCt: %d, WDflags: 0x%x\n"
               ,uVar16,*(undefined4 *)(lVar10 + 0x7ac),iVar13,iVar9,piVar14[2],
               *(undefined4 *)(lVar17 + 8));
  if (cVar1 == '\0') {
    if ((bVar4 & 1) != 0) {
      *piVar14 = *piVar14 + 1;
    }
LAB_004273ab:
    if (cVar2 != '\0') goto LAB_004274a0;
LAB_004273b5:
    if ((bVar5 & 1) == 0) {
      if (cVar2 != '\0') goto LAB_004274a0;
    }
    else {
      piVar14[1] = piVar14[1] + 1;
    }
LAB_004273c3:
    if (cVar3 != '\0') goto LAB_004274c0;
LAB_004273cd:
    if ((bVar6 & 1) == 0) {
      if (cVar3 != '\0') goto LAB_004274c0;
    }
    else {
      piVar14[2] = piVar14[2] + 1;
    }
  }
  else {
    if ((bVar4 & 1) != 0) goto LAB_004273ab;
    *piVar14 = *piVar14 + -1;
    if (cVar2 == '\0') goto LAB_004273b5;
LAB_004274a0:
    if ((bVar5 & 1) != 0) goto LAB_004273c3;
    piVar14[1] = piVar14[1] + -1;
    if (cVar3 == '\0') goto LAB_004273cd;
LAB_004274c0:
    if ((bVar6 & 1) == 0) {
      piVar14[2] = piVar14[2] + -1;
    }
  }
  *(byte *)(param_3 + 0x699) = bVar4;
  *(byte *)(param_3 + 0x69a) = bVar5;
  *(byte *)(param_3 + 0x69b) = bVar6;
  iVar9 = *piVar14;
  iVar13 = piVar14[1];
  uVar11 = *(uint *)(lVar17 + 8);
  if (iVar9 == 1) {
    if ((iVar7 == 0) && (iVar13 == 0)) {
      uVar11 = uVar11 & 0xfffffffd;
      *(uint *)(lVar17 + 8) = uVar11;
      iVar15 = piVar14[2];
      iVar13 = piVar14[1];
      iVar9 = *piVar14;
      goto LAB_0042741b;
    }
LAB_0042754f:
    iVar15 = piVar14[2];
  }
  else {
    if (iVar13 == 1) {
      if (iVar15 != 0 || iVar9 != 0) goto LAB_0042754f;
    }
    else {
      iVar15 = piVar14[2];
      if (iVar9 != 0 || iVar13 != 0) goto LAB_0042741b;
      if (iVar7 < 1) {
        iVar9 = 0;
        iVar13 = 0;
        if (iVar8 != 0) goto LAB_0042741b;
      }
      if (iVar15 < 1) {
        iVar9 = 0;
        iVar13 = 0;
        goto LAB_0042741b;
      }
    }
    uVar11 = uVar11 | 2;
    *(uint *)(lVar17 + 8) = uVar11;
    iVar15 = piVar14[2];
    iVar13 = piVar14[1];
    iVar9 = *piVar14;
  }
LAB_0042741b:
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x163,"krcWatchdogChangeState_IMPL",1,
               "NVRM: (after) op: %s, GPU 0x%x, enableRefCt: %d, disableRefCt: %d, softDisableRefCt: %d, WDflags: 0x%x\n"
               ,uVar16,*(undefined4 *)(lVar10 + 0x7ac),iVar9,iVar13,iVar15,uVar11);
  return 0;
}


// ===== 00427610 krcWatchdogDisable_IMPL =====

void krcWatchdogDisable_IMPL(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = param_1 + 0x1a0;
  if (param_2 != 0) {
    lVar1 = param_2 + 0x148;
  }
  *(uint *)(lVar1 + 8) = *(uint *)(lVar1 + 8) | 2;
  return;
}


// ===== 00427630 krcWatchdogEnable_IMPL =====

void krcWatchdogEnable_IMPL(long param_1,long param_2,char param_3)

{
  long lVar1;
  
  lVar1 = param_1 + 0x1a0;
  if (param_2 != 0) {
    lVar1 = param_2 + 0x148;
  }
  if (param_3 != '\0') {
    *(undefined4 *)(lVar1 + 0x1c) = *(undefined4 *)(lVar1 + 0x20);
  }
  *(uint *)(lVar1 + 8) = *(uint *)(lVar1 + 8) & 0xfffffffd;
  return;
}


// ===== 00427660 krcWatchdogShutdown_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 krcWatchdogShutdown_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  undefined4 *puVar2;
  
  lVar1 = rmapiGetInterface(4);
  if (param_3 == 0) {
    puVar2 = (undefined4 *)(param_2 + 0x1a0);
    param_2 = param_2 + 0x2b0;
  }
  else {
    puVar2 = (undefined4 *)(param_3 + 0x148);
    param_2 = param_3 + 600;
  }
  if ((puVar2[2] & 1) != 0) {
    puVar2[2] = puVar2[2] | 2;
    osRemove1HzCallback(param_1,krcWatchdogTimerProc,param_3);
    (**(code **)(lVar1 + 0x18))(lVar1,*puVar2,*puVar2);
    portMemSet(puVar2,0,0xe0);
    portMemSet(param_2,0,0x30);
  }
  return 0;
}


// ===== 00427720 krcWatchdogGetReservationCounts_IMPL =====

void krcWatchdogGetReservationCounts_IMPL
               (long param_1,long param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_1 + 0x280);
  if (param_2 != 0) {
    puVar1 = (undefined4 *)(param_2 + 0x228);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *puVar1;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = puVar1[1];
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = puVar1[2];
  }
  return;
}


// ===== 00427760 krcWatchdogInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int krcWatchdogInit_IMPL(long param_1,long param_2,long param_3)

{
  byte bVar1;
  undefined8 uVar2;
  bool bVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  long lVar10;
  int *piVar11;
  undefined8 *puVar12;
  long lVar13;
  uint uVar14;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  char *pcVar16;
  ulong uVar17;
  bool bVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  long *local_128;
  undefined4 local_120;
  undefined4 local_11c;
  long local_118;
  long local_108;
  int *local_100;
  int local_ec;
  undefined4 local_e8;
  int local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  long local_d8;
  long local_d0;
  long local_c8;
  uint local_c0 [2];
  undefined8 local_b8 [2];
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  ulong uVar15;
  
  local_ec = 0;
  if (param_3 == 0) {
    local_100 = (int *)(param_2 + 0x1a0);
    local_108 = param_2 + 0x2b0;
    local_118 = param_2 + 0x280;
  }
  else {
    local_100 = (int *)(param_3 + 0x148);
    local_108 = param_3 + 600;
    local_118 = param_3 + 0x228;
  }
  cVar4 = rmGpuLockIsOwner();
  if (cVar4 == '\0') {
    lVar10 = rmapiGetInterface(3);
  }
  else {
    lVar10 = rmapiGetInterface(4);
  }
  if ((((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) &&
      (cVar4 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar4 != '\0')) ||
     ((*(byte *)(local_100 + 2) & 3) != 0)) {
    return 0;
  }
  bVar18 = true;
  if (*(char *)(*(long *)(param_1 + 0x1b78) + 0x434) != '\0') {
    local_c8 = CONCAT44(local_c8._4_4_,0xc);
    iVar6 = pmaQueryConfigs(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x1b78) + 0x478) + 0x128),
                            &local_c8);
    if (iVar6 == 0) {
      bVar18 = ((uint)local_c8 & 0xc) != 4;
    }
  }
  portMemSet(local_108,0,0x70);
  uVar19 = 0x427853;
  piVar11 = (int *)portMemAllocNonPaged(0x170);
  if (piVar11 == (int *)0x0) {
    iVar6 = 0x51;
    goto LAB_00427fb0;
  }
  if (*(long *)(param_1 + 0x1bc0) == 0) {
LAB_0042787c:
    local_e8 = 0x31415903;
    local_e4 = 0x31415904;
    iVar6 = (**(code **)(lVar10 + 8))(lVar10,0,0,0,0,&local_ec,4);
    if (iVar6 == 0) {
      *local_100 = local_ec;
      *(undefined1 *)(local_100 + 0x36) = 1;
      uVar20 = 0x4278e5;
      portMemSet(piVar11,0,0x38,local_100,uVar19);
      *piVar11 = *(int *)(param_1 + 0x7b4);
      piVar11[1] = local_ec;
      uVar19 = 0x38;
      iVar6 = (**(code **)(lVar10 + 8))(lVar10,local_ec,local_ec,local_e8,0x80,piVar11);
      if (iVar6 == 0) {
        iVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_1,uVar20,extraout_RDX,uVar19);
        portMemSet(piVar11,0,4);
        *piVar11 = iVar6;
        iVar6 = (**(code **)(lVar10 + 8))
                          (lVar10,local_ec,local_e8,local_e4 + iVar6,0x2080,piVar11,4);
        if (iVar6 == 0) goto LAB_00427995;
        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x261,"krcWatchdogInit_IMPL",3,
                     "NVRM: Unable to allocate a watchdog subdevice\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x249,"krcWatchdogInit_IMPL",3,
                     "NVRM: Unable to allocate a watchdog device\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x230,"krcWatchdogInit_IMPL",3,
                   "NVRM: Unable to allocate a watchdog client\n");
    }
    goto LAB_00427fb0;
  }
  uVar19 = 0x427874;
  cVar4 = kmigmgrIsMIGEnabled_IMPL(param_1);
  if (cVar4 == '\0') goto LAB_0042787c;
  uVar19 = *(undefined8 *)(param_1 + 0x1bc0);
  uVar20 = *(undefined8 *)(*(long *)(param_3 + 0x128) + 0xe8);
  puVar12 = (undefined8 *)rmapiGetInterface(4);
  local_e0 = 0;
  local_dc = 0;
  iVar6 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar19,uVar20,&local_d8);
  if (iVar6 != 0) {
    nvAssertOkFailedNoLog
              (iVar6,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
               "src/kernel/gpu/rc/kernel_rc_watchdog.c",0x271);
    goto LAB_00427fb0;
  }
  if (local_d8 == 0) {
    nvAssertFailedNoLog("ref.pKernelMIGGpuInstance != NULL","src/kernel/gpu/rc/kernel_rc_watchdog.c"
                        ,0x274);
LAB_0042863b:
    iVar6 = 0x40;
  }
  else {
    if (local_d0 == 0) {
      nvAssertFailedNoLog("ref.pMIGComputeInstance != NULL","src/kernel/gpu/rc/kernel_rc_watchdog.c"
                          ,0x275);
      goto LAB_0042863b;
    }
    iVar6 = rmapiutilAllocClientAndDeviceHandles(puVar12,param_1,&local_ec,&local_e8,&local_e4);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, &hClient, &hDevice, &hSubdevice)"
                 ,"src/kernel/gpu/rc/kernel_rc_watchdog.c",0x277);
      goto LAB_00427fb0;
    }
    portMemSet(&local_c8,0,0x10);
    local_c0[0] = *(undefined4 *)(local_d8 + 0x968);
    iVar6 = (*(code *)*puVar12)(puVar12,local_ec,local_e4,&local_e0,0xc637,&local_c8,0x10);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "pRmApi->Alloc(pRmApi, hClient, hSubdevice, &hGPUInstanceSubscription, AMPERE_SMC_PARTITION_REF, &params, sizeof(params))"
                 ,"src/kernel/gpu/rc/kernel_rc_watchdog.c",0x280);
      goto LAB_00427fb0;
    }
    portMemSet(&local_c8,0,0x10);
    local_c0[0] = *(undefined4 *)(local_d0 + 0xc0);
    iVar6 = (*(code *)*puVar12)(puVar12,local_ec,local_e0,&local_dc,0xc638,&local_c8);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "pRmApi->Alloc(pRmApi, hClient, hGPUInstanceSubscription, &hComputeInstanceSubscription, AMPERE_SMC_EXEC_PARTITION_REF, &params, sizeof(params))"
                 ,"src/kernel/gpu/rc/kernel_rc_watchdog.c",0x289);
      goto LAB_00427fb0;
    }
    *(ulong *)(param_3 + 0x138) = CONCAT44(local_e8,local_ec);
    *(int *)(param_3 + 0x140) = local_e4;
LAB_00427995:
    local_128 = &local_c8;
    uVar17 = 0;
    do {
      uVar14 = (int)uVar17 + 0x20;
      uVar15 = (ulong)uVar14;
      uVar19 = *(undefined8 *)((long)&DAT_005a7268 + uVar17);
      uVar20 = *(undefined8 *)((long)&DAT_005a7270 + uVar17);
      uVar2 = *(undefined8 *)((long)&DAT_005a7278 + uVar17);
      *(undefined8 *)((long)&local_c8 + uVar17) = *(undefined8 *)((long)&DAT_005a7260 + uVar17);
      *(undefined8 *)((long)local_c0 + uVar17) = uVar19;
      *(undefined8 *)((long)local_b8 + uVar17) = uVar20;
      *(undefined8 *)((long)local_b8 + uVar17 + 8) = uVar2;
      uVar17 = uVar15;
    } while (uVar14 < 0x80);
    uVar17 = 0;
    uVar19 = *(undefined8 *)((long)&DAT_005a7268 + uVar15);
    *(undefined8 *)((long)local_128 + uVar15) = *(undefined8 *)((long)&DAT_005a7260 + uVar15);
    *(undefined8 *)((long)local_c0 + uVar15) = uVar19;
    *(undefined4 *)(local_108 + 0x68) = 0;
    do {
      local_120 = (undefined4)local_128[uVar17 * 2];
      cVar4 = gpuIsClassSupported_IMPL(param_1,local_120);
      if (cVar4 != '\0') {
        uVar14 = local_c0[(uVar17 & 0xffffffff) * 4];
        *(undefined4 *)(local_108 + 0x68) = 3;
        goto LAB_00427a79;
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 != 9);
    uVar14 = 0x1000;
    local_120 = 0x906f;
LAB_00427a79:
    portMemSet(piVar11,0,0x18);
    iVar6 = (**(code **)(lVar10 + 8))(lVar10,local_ec,local_e8,0x3141590f,0x70,piVar11,0x18);
    if (iVar6 == 0) {
      *(undefined4 *)(local_108 + 100) = 0x200;
      sVar5 = kbifGetDmaCaps_IMPL(param_1,*(undefined8 *)(param_1 + 7000));
      local_c8 = 0;
      local_c0[0] = 0;
      local_c0[1] = 0;
      local_b8[0] = 0;
      local_b8[1] = 0;
      local_a8 = 0;
      local_a0 = 0;
      local_98 = 0;
      local_90 = 0;
      portMemSet(piVar11,0,0x80);
      piVar11[0x10] = 0x608;
      piVar11[0x11] = 0;
      piVar11[0] = -0x2150fffa;
      piVar11[1] = 0;
      piVar11[7] = 8;
      uVar7 = *(uint *)(param_1 + 0x4930) >> 2 & 3;
      if (uVar7 == 2) {
        uVar7 = piVar11[6] | 0xa000000;
LAB_00427b9b:
        piVar11[6] = uVar7;
        if (sVar5 == 1) {
          piVar11[6] = uVar7 & 0x1fffffff | 0x20000000;
          bVar1 = *(byte *)(local_100 + 2);
        }
        else {
          bVar1 = *(byte *)(local_100 + 2);
        }
        if ((bVar1 & 4) != 0) {
          piVar11[6] = uVar7 & 0x1fffffff;
        }
        iVar6 = (**(code **)(lVar10 + 8))(lVar10,local_ec,local_e8,0x3141590e,0x3e,piVar11,0x80);
        if (iVar6 != 0) {
          pcVar16 = "system";
LAB_0042832c:
          nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x34c,"krcWatchdogInit_IMPL",3,
                       "NVRM: Unable to allocate %s memory for watchdog\n",pcVar16);
          goto LAB_00427fb0;
        }
      }
      else {
        if (uVar7 != 3) {
          if (uVar7 == 1) {
            uVar7 = piVar11[6] | 0x2a000000;
          }
          else {
            uVar7 = piVar11[6] | 0xa000000;
          }
          goto LAB_00427b9b;
        }
        cVar4 = rmGpuLockIsOwner();
        if (cVar4 == '\0') {
          iVar6 = (**(code **)(lVar10 + 8))(lVar10,local_ec,local_e8,0x3141590e,0x40,piVar11,0x80);
          if (iVar6 == 0) goto LAB_00427c0b;
LAB_00428325:
          pcVar16 = "video";
          goto LAB_0042832c;
        }
        rmGpuLocksRelease(0,0);
        uVar20 = 0x42836a;
        lVar10 = rmapiGetInterface(3);
        uVar19 = 0x80;
        iVar6 = (**(code **)(lVar10 + 8))(lVar10,local_ec,local_e8,0x3141590e,0x40,piVar11);
        iVar8 = rmGpuLocksAcquire(0,0x10001);
        if (iVar8 != 0) {
          nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x342,"krcWatchdogInit_IMPL",4,
                       "NVRM: failed to grab RM-Lock\n");
          if (iVar6 == 0) goto LAB_00427fd2;
          goto LAB_00427fb0;
        }
        lVar10 = rmapiGetInterface(4,uVar20,extraout_RDX_00,uVar19);
        if (iVar6 != 0) goto LAB_00428325;
      }
LAB_00427c0b:
      iVar6 = (**(code **)(lVar10 + 0x70))
                        (lVar10,local_ec,local_e8,0x3141590e,0,*(undefined8 *)(piVar11 + 0x10),
                         local_108 + 0x48,0);
      if (iVar6 == 0) {
        portMemSet(*(undefined8 *)(local_108 + 0x48),0,*(undefined8 *)(piVar11 + 0x10));
        local_c8 = CONCAT44(local_e8,local_ec);
        local_b8[1] = 0x608;
        local_c0[0] = 0x3141590f;
        local_c0[1] = 0x3141590e;
        local_a8 = CONCAT44(local_a8._4_4_,(uint)(sVar5 == 1) << 4);
        iVar6 = (**(code **)(lVar10 + 0x98))(lVar10,local_128);
        if (iVar6 == 0) {
          *(undefined8 *)(local_108 + 0x40) = local_98;
          portMemSet(piVar11,0,0x20);
          *piVar11 = 0;
          iVar6 = 0x30100000;
          if (sVar5 == 1) {
            iVar6 = 0x20100000;
          }
          piVar11[2] = 0x3141590e;
          piVar11[1] = iVar6;
          iVar6 = *(int *)(local_108 + 100);
          piVar11[6] = 0x2f;
          piVar11[7] = 0;
          *(ulong *)(piVar11 + 4) = (ulong)((iVar6 * 2 + 7U & 0xfffffff8) + 0x2f & 0xfffffff0);
          iVar6 = (**(code **)(lVar10 + 8))(lVar10,local_ec,local_e8,0x3141590d,2,piVar11,0x20);
          if (iVar6 == 0) {
            portMemSet(piVar11,0,0x20);
            *piVar11 = 0;
            iVar6 = 0x30000000;
            if (sVar5 == 1) {
              iVar6 = 0x20000000;
            }
            piVar11[2] = 0x3141590e;
            piVar11[1] = iVar6;
            iVar6 = *(int *)(local_108 + 100);
            piVar11[6] = 0x17f;
            piVar11[7] = 0;
            *(ulong *)(piVar11 + 4) =
                 (ulong)((iVar6 * 2 + 7U & 0xfffffff8) + 0x2f & 0xfffffff0) + 0x30;
            uVar19 = 0x20;
            iVar6 = (**(code **)(lVar10 + 8))(lVar10,local_ec,local_e8,0x31415902,2,piVar11);
            if (iVar6 == 0) {
              if (bVar18) {
                portMemSet(piVar11,0,0x80);
                *(ulong *)(piVar11 + 0x10) = (ulong)uVar14;
                piVar11[0] = -0x2150fffa;
                piVar11[1] = 0;
                if (((*(ushort *)(param_1 + 0x4926) & 3) == 3) ||
                   ((*(ushort *)(param_1 + 0x4926) & 3) == 0)) {
                  piVar11[6] = 0;
                  cVar4 = rmGpuLockIsOwner();
                  if (cVar4 == '\0') {
                    uVar19 = 0x40;
                    uVar7 = piVar11[6] | 0x4000;
                    bVar3 = false;
                  }
                  else {
                    rmGpuLocksRelease(0,0);
                    lVar10 = rmapiGetInterface(3);
                    uVar19 = 0x40;
                    uVar7 = piVar11[6] | 0x4000;
                    bVar3 = true;
                  }
                }
                else {
                  bVar3 = false;
                  uVar7 = 0x2004000;
                  uVar19 = 0x3e;
                }
                piVar11[6] = uVar7;
                iVar6 = (**(code **)(lVar10 + 8))
                                  (lVar10,local_ec,local_e8,0x31415910,uVar19,piVar11,0x80);
                if (iVar6 == 0) {
                  portMemSet(piVar11,0,0x170);
                  piVar11[0] = 0x3141590d;
                  piVar11[1] = 0x3141590f;
                  iVar6 = *(int *)(local_108 + 100);
                  lVar13 = *(long *)(local_108 + 0x40);
                  piVar11[4] = 4;
                  *(ulong *)(piVar11 + 2) = (ulong)(iVar6 * 2 + 7U & 0xfffffff8) + lVar13;
                  piVar11[0x20] = 1;
                  piVar11[8] = 0x31415910;
                  if (!bVar3) goto LAB_00427e5d;
                  goto LAB_004285c7;
                }
                nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x3f9,"krcWatchdogInit_IMPL",3
                             ,"NVRM: Unable to allocate video memory for USERD\n");
              }
              else {
                portMemSet(piVar11,0,0x170);
                piVar11[0] = 0x3141590d;
                piVar11[1] = 0x3141590f;
                iVar6 = *(int *)(local_108 + 100);
                lVar13 = *(long *)(local_108 + 0x40);
                piVar11[4] = 4;
                *(ulong *)(piVar11 + 2) = (ulong)(iVar6 * 2 + 7U & 0xfffffff8) + lVar13;
                piVar11[0x20] = 1;
LAB_00427e5d:
                cVar4 = rmGpuLockIsOwner();
                if (cVar4 == '\0') {
                  iVar6 = (**(code **)(lVar10 + 8))
                                    (lVar10,local_ec,local_e8,0x31415900,local_120,piVar11,0x170);
                }
                else {
                  rmGpuLocksRelease(0,0);
                  lVar10 = rmapiGetInterface(3);
LAB_004285c7:
                  iVar6 = (**(code **)(lVar10 + 8))
                                    (lVar10,local_ec,local_e8,0x31415900,local_120,piVar11,0x170);
                  iVar8 = rmGpuLocksAcquire(0,0x10001);
                  if (iVar8 != 0) {
                    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x42c,
                                 "krcWatchdogInit_IMPL",4,"NVRM: failed to grab RM-Lock\n");
                    iVar6 = 0xffff;
                    goto LAB_00427fb0;
                  }
                  lVar10 = rmapiGetInterface(4);
                }
                if (iVar6 == 0) {
                  local_c8 = 0;
                  uVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
                  iVar6 = (**(code **)(lVar10 + 0x70))
                                    (lVar10,local_ec,uVar7 + local_e4,
                                     (-(uint)!bVar18 & 0xfffffff0) + 0x31415910,0,uVar14,local_128,0
                                    );
                  if (iVar6 == 0) {
                    uVar17 = (ulong)uVar7;
                    *(long *)(local_108 + uVar17 * 8) = local_c8;
                    *(ulong *)(local_100 + uVar17 * 2 + 0x22) =
                         (ulong)((*(int *)(local_108 + 100) * 2 + 7U & 0xfffffff8) + 0x2f &
                                0xfffffff0) + 0x30 + uVar17 * 0x30 + *(long *)(local_108 + 0x48);
                    *(ulong *)(local_100 + 0x32) =
                         (ulong)((*(int *)(local_108 + 100) * 2 + 7U & 0xfffffff8) + 0x2f &
                                0xfffffff0) + *(long *)(local_108 + 0x48);
                    *(ulong *)(local_100 + 0x34) =
                         *(long *)(local_108 + 0x48) + 0x10 +
                         (ulong)((*(int *)(local_108 + 100) * 2 + 7U & 0xfffffff8) + 0x2f &
                                0xfffffff0);
                    cVar4 = gpuIsClassSupported_IMPL(param_1,0x902d);
                    local_11c = 0x902d;
                    uVar9 = 3;
                    if (cVar4 == '\0') {
                      cVar4 = gpuIsClassSupported_IMPL(param_1,0xcdc0);
                      local_11c = 0xcdc0;
                      uVar9 = 1;
                      if (cVar4 == '\0') {
                        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x476,
                                     "krcWatchdogInit_IMPL",4,
                                     "NVRM: GPU lacks support for 2D and COMPUTE\n");
                        iVar6 = 0x56;
                        goto LAB_00427fb0;
                      }
                    }
                    *(undefined4 *)(local_108 + 0x68) = uVar9;
                    iVar6 = (**(code **)(lVar10 + 8))
                                      (lVar10,local_ec,0x31415900,0x3141590c,local_11c,0,0);
                    if (iVar6 == 0) {
                      iVar6 = serverGetClientUnderLock(g_resServ,local_ec,&local_d8);
                      if (iVar6 == 0) {
                        iVar6 = CliGetKernelChannelWithDevice
                                          (local_d8,local_e8,0x31415900,local_128);
                        if (iVar6 == 0) {
                          if (local_c8 != 0) {
                            iVar6 = (**(code **)(local_c8 + 0x228))
                                              (param_1,local_c8,0x3141590c,local_108 + 0x50,
                                               &local_e0,&local_dc);
                            if (iVar6 == 0) {
                              *local_100 = local_ec;
                              local_100[1] = *(int *)(local_c8 + 0x2b0);
                              portMemSet(&local_dc,0,3);
                              local_dc = CONCAT31(local_dc._1_3_,1);
                              iVar6 = (**(code **)(lVar10 + 0x38))
                                                (lVar10,*local_100,0x31415900,0xa06f0103,&local_dc,3
                                                );
                              iVar8 = local_ec;
                              if (iVar6 == 0) {
                                lVar13 = gpuGetKernelFifoShared_IMPL(param_1);
                                iVar6 = (**(code **)(lVar13 + 0x1b8))
                                                  (lVar13,iVar8,0x31415900,&local_dc,
                                                   *(code **)(lVar13 + 0x1b8));
                                if (iVar6 == 0) {
                                  (**(code **)(param_2 + 0x170))(param_1,param_2,param_3);
                                  local_100[2] = local_100[2] | 1;
                                  osSchedule1HzCallback(param_1,krcWatchdogTimerProc,param_3,1);
                                  *(undefined8 *)(local_118 + 0x20) = 0;
                                  goto LAB_00427fd2;
                                }
                                nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x4d4,
                                             "krcWatchdogInit_IMPL",3,
                                             "NVRM: Unable to get work submit token for watchdog\n")
                                ;
                              }
                              else {
                                nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x4c6,
                                             "krcWatchdogInit_IMPL",4,
                                             "NVRM: Unable to schedule watchdog channel\n");
                              }
                            }
                            else {
                              nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x4ad,
                                           "krcWatchdogInit_IMPL",3,
                                           "NVRM: Unable to get class engine ID %x\n",local_11c);
                            }
                            goto LAB_00427fb0;
                          }
                          nvAssertFailedNoLog("pKernelChannel != NULL",
                                              "src/kernel/gpu/rc/kernel_rc_watchdog.c",0x49f);
                        }
                        else {
                          nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x49a,
                                       "krcWatchdogInit_IMPL",4,
                                       "NVRM: CliGetKernelChannelWithDevice failed\n");
                        }
                        iVar6 = 0x21;
                      }
                      else {
                        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x48d,
                                     "krcWatchdogInit_IMPL",4,
                                     "NVRM: Unable to obtain client object\n");
                      }
                    }
                    else {
                      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x485,
                                   "krcWatchdogInit_IMPL",3,"NVRM: Unable to allocate class %x\n",
                                   local_11c);
                    }
                  }
                  else {
                    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x451,
                                 "krcWatchdogInit_IMPL",3,
                                 "NVRM: Unable to create a watchdog GPFIFO mapping\n");
                  }
                }
                else {
                  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x436,"krcWatchdogInit_IMPL"
                               ,3,"NVRM: Unable to alloc watchdog channel\n");
                  if (iVar6 == 0x22) {
                    iVar6 = 0x56;
                  }
                }
              }
            }
            else {
              nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x3b6,"krcWatchdogInit_IMPL",3,
                           "NVRM: Unable to set up watchdog\'s notifier\n",uVar19);
            }
          }
          else {
            nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x393,"krcWatchdogInit_IMPL",3,
                         "NVRM: Unable to set up watchdog\'s error context\n");
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x370,"krcWatchdogInit_IMPL",4,
                       "NVRM: Unable to map memory into watchdog\'s heap\n");
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x35c,"krcWatchdogInit_IMPL",3,
                     "NVRM: Unable to map memory for watchdog\n");
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x2cf,"krcWatchdogInit_IMPL",3,
                   "NVRM: Unable to allocate unified heap for watchdog\n");
    }
  }
LAB_00427fb0:
  (**(code **)(lVar10 + 0x18))(lVar10,local_ec,local_ec);
  *(undefined1 *)(local_100 + 0x36) = 0;
LAB_00427fd2:
  portMemFree(piVar11);
  return iVar6;
}


// ===== 00428c40 krcWatchdogWriteNotifierToGpfifo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void krcWatchdogWriteNotifierToGpfifo_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  long lVar5;
  
  if (param_3 == 0) {
    lVar5 = param_2 + 0x1a0;
    param_3 = param_2 + 0x2b0;
  }
  else {
    lVar5 = param_3 + 0x148;
    param_3 = param_3 + 600;
  }
  uVar2 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  uVar2 = *(uint *)(*(long *)(param_3 + (ulong)uVar2 * 8) + 0x8c);
  if (uVar2 < 4) {
    puVar4 = (undefined4 *)
             ((ulong)(*(int *)(param_3 + 100) * 2 + 7U & 0xfffffff8) + (ulong)(uVar2 * 8) +
             *(long *)(param_3 + 0x48));
    *puVar4 = *(undefined4 *)(param_3 + 0x5c);
    puVar4[1] = *(undefined4 *)(param_3 + 0x60);
    osFlushCpuWriteCombineBuffer();
    uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    *(uint *)(*(long *)(param_3 + (ulong)uVar3 * 8) + 0x8c) = uVar2 + 1 & 3;
    osFlushCpuWriteCombineBuffer();
    uVar1 = *(undefined4 *)(*(long *)(lVar5 + 0xd0) + 8);
    lVar5 = gpuGetKernelFifoShared_IMPL(param_1);
    (**(code **)(lVar5 + 0x238))(param_1,lVar5,uVar1,*(code **)(lVar5 + 0x238));
    return;
  }
  nvAssertFailedNoLog("GPPut < WATCHDOG_GPFIFO_ENTRIES","src/kernel/gpu/rc/kernel_rc_watchdog.c",
                      0x60d);
  return;
}


// ===== 00428d40 krcWatchdogInitPushbuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void krcWatchdogInitPushbuffer_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined4 *puVar7;
  long lVar8;
  long lVar9;
  uint *puVar10;
  
  gpuIsClassSupported_IMPL(param_1,0x902d);
  if (param_3 == 0) {
    lVar8 = param_2 + 0x1a0;
    lVar9 = param_2 + 0x2b0;
  }
  else {
    lVar8 = param_3 + 0x148;
    lVar9 = param_3 + 600;
  }
  puVar10 = *(uint **)(lVar9 + 0x48);
  *puVar10 = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x20010000;
  puVar10[1] = *(uint *)(lVar9 + 0x50);
  lVar6 = *(long *)(lVar9 + 0x40);
  uVar4 = *(uint *)(lVar9 + 100);
  puVar10 = (uint *)((ulong)uVar4 + *(long *)(lVar9 + 0x48));
  *(uint *)(lVar9 + 0x54) = (uint)lVar6 & 0xfffffffc;
  *(uint *)(lVar9 + 0x58) = (uint)CONCAT11(8,(char)((ulong)lVar6 >> 0x20));
  uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  lVar6 = (ulong)((uVar4 * 2 + 7 & 0xfffffff8) + 0x2f & 0xfffffff0) +
          lVar6 + 0x30 + (ulong)uVar3 * 0x30;
  *puVar10 = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x20010041;
  puVar10[1] = (uint)((ulong)lVar6 >> 0x20) & 0x1ffffff;
  puVar10[2] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x20010042;
  puVar10[3] = (uint)lVar6;
  puVar10[4] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x20010043;
  puVar10[5] = 0;
  puVar10[6] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x20010040;
  puVar10[7] = 0;
  cVar2 = gpuIsClassSupported_IMPL(param_1,0xc86f);
  if (cVar2 == '\0') {
    cVar2 = rmcfg_IsHOPPER_CLASSIC_GPUSorBetter(param_1);
    if (cVar2 != '\0') {
      nvAssertFailedNoLog("!IsHOPPERorBetter(pGpu)","src/kernel/gpu/rc/kernel_rc_watchdog.c",0x592);
    }
    uVar3 = 0x2800;
    puVar10[8] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x20010014;
    puVar10[9] = 0;
  }
  else {
    uVar3 = 0x4800;
    puVar10[8] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x2001001e;
    puVar10[9] = 0;
    puVar10[10] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x2001000a;
    puVar10[0xb] = 0;
    puVar10[0xc] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x2001000b;
    puVar10[0xd] = 0;
    puVar10[0xe] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x2001000c;
    puVar10[0xf] = 0;
    puVar10[0x10] = (*(uint *)(lVar9 + 0x68) & 7) << 0xd | 0x2001000d;
    puVar10[0x11] = 0x28000000;
  }
  lVar6 = (ulong)uVar4 + *(long *)(lVar9 + 0x40);
  *(uint *)(lVar9 + 0x5c) = (uint)lVar6 & 0xfffffffc;
  *(uint *)(lVar9 + 0x60) = (byte)((ulong)lVar6 >> 0x20) | uVar3 | 0x80000000;
  puVar7 = (undefined4 *)
           ((ulong)(*(int *)(lVar9 + 100) * 2 + 7U & 0xfffffff8) + *(long *)(lVar9 + 0x48));
  *puVar7 = *(undefined4 *)(lVar9 + 0x54);
  puVar7[1] = *(undefined4 *)(lVar9 + 0x58);
  osFlushCpuWriteCombineBuffer();
  uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  *(undefined4 *)(*(long *)(lVar9 + (ulong)uVar4 * 8) + 0x8c) = 1;
  *(undefined2 *)(*(long *)(lVar8 + 0x88 + (ulong)uVar4 * 8) + 0xe) = 0;
  osFlushCpuWriteCombineBuffer();
  iVar5 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x4f8))(param_1);
  if (iVar5 == 0) {
    uVar1 = *(undefined4 *)(*(long *)(lVar8 + 0xd0) + 8);
    lVar8 = gpuGetKernelFifoShared_IMPL(param_1);
    (**(code **)(lVar8 + 0x238))(param_1,lVar8,uVar1,*(code **)(lVar8 + 0x238));
    krcWatchdogWriteNotifierToGpfifo_IMPL(param_1,param_2,param_3);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog.c",0x5dd,"_watchdogInitPushbuffer",4,
               "NVRM: Busflush failed.\n");
  return;
}


// ===== 00429090 krcWatchdog_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void krcWatchdog_IMPL(long param_1,long param_2,long param_3)

{
  long *plVar1;
  char cVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  uint local_4c;
  ulong local_48 [3];
  
  if (param_3 == 0) {
    lVar8 = param_2 + 0x1a0;
    lVar10 = param_2 + 0x280;
  }
  else {
    lVar8 = param_3 + 0x148;
    lVar10 = param_3 + 0x228;
  }
  if (*(char *)(param_2 + 0x188) != '\0') {
    uVar3 = *(uint *)(lVar8 + 0x1c);
    if (uVar3 != *(uint *)(lVar8 + 0x20)) {
      if (*(int *)(lVar8 + 0xc + (ulong)uVar3 * 4) != 0) {
        *(uint *)(lVar8 + 8) = *(uint *)(lVar8 + 8) | 2;
        *(uint *)(lVar8 + 0x1c) = uVar3 + 1 & 3;
        return;
      }
      *(uint *)(lVar8 + 0x1c) = uVar3 + 1 & 3;
    }
    if ((*(uint *)(lVar8 + 8) & 2) == 0) {
      cVar2 = gpuIsGpuFullPower_IMPL();
      if (cVar2 != '\0') {
        if ((*(byte *)(lVar8 + 8) & 1) == 0) {
          iVar11 = (**(code **)(param_2 + 0x168))(param_1,param_2,param_3);
          if (iVar11 != 0) {
            nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0xda,"krcWatchdog_IMPL",1
                         ,"NVRM: krcWatchdogInit failed: %d\n",iVar11);
            return;
          }
        }
        else {
          *(int *)(lVar8 + 0x24) = *(int *)(lVar8 + 0x24) + 1;
          if (*(short *)(*(long *)(lVar8 + 200) + 0xe) != 0) {
            nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0xe5,"krcWatchdog_IMPL",3
                         ,"NVRM: RC watchdog: error on our channel (reinitializing).\n");
            *(undefined2 *)(*(long *)(lVar8 + 200) + 0xe) = 0;
            (**(code **)(param_2 + 0x170))(param_1,param_2,param_3);
            *(undefined8 *)(lVar10 + 0x20) = 0;
          }
          if ((*(int *)(lVar8 + 0x28) != 0) &&
             (iVar11 = *(int *)(lVar8 + 0x28) + -1, *(int *)(lVar8 + 0x28) = iVar11, iVar11 == 0)) {
            uVar3 = *(uint *)(lVar8 + 0x30);
            if ((uVar3 != 0) || (*(int *)(lVar8 + 0x38) != 0)) {
              iVar11 = 0;
              while( true ) {
                uVar7 = 1 << ((byte)iVar11 & 0x1f);
                if ((uVar7 & uVar3) != 0) {
                  uVar4 = gpuGetKernelFifoShared_IMPL(param_1);
                  uVar5 = kfifoGetChidMgr_IMPL(param_1,uVar4,*(undefined4 *)(lVar8 + 4));
                  lVar6 = kfifoChidMgrGetKernelChannel_IMPL(param_1,uVar4,uVar5,iVar11);
                  if (lVar6 == 0) {
                    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0x45,
                                 "_krcThwapChannel",3,
                                 "NVRM: Unable to thwap channel 0x%02x, it\'s not in use\n",iVar11);
                  }
                  else {
                    nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0x4a,
                                 "_krcThwapChannel",1,"NVRM: Thwapping channel channel 0x%08x.\n",
                                 *(int *)(lVar6 + 0x2b0) << 0x18 | *(uint *)(lVar6 + 0x2b4));
                    local_48[0] = 0;
                    local_48[1] = 5;
                    uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
                    local_48[0] = (ulong)uVar3 << 0x20;
                    plVar1 = *(long **)(*(long *)(lVar6 + 0x140) + 0x48);
                    (**(code **)(param_1 + 0x3b90))
                              (param_1 + 0x3b58,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],
                               0x906f0102,local_48,0x10);
                  }
                  if ((*(uint *)(lVar8 + 0x34) & uVar7) == 0) {
                    *(uint *)(lVar8 + 0x30) = *(uint *)(lVar8 + 0x30) & ~uVar7;
                  }
                }
                if (((uVar7 & *(uint *)(lVar8 + 0x38)) != 0) &&
                   ((*(uint *)(lVar8 + 0x3c) & uVar7) == 0)) {
                  *(uint *)(lVar8 + 0x38) = ~uVar7 & *(uint *)(lVar8 + 0x38);
                }
                iVar11 = iVar11 + 1;
                if (iVar11 == 0x20) break;
                uVar3 = *(uint *)(lVar8 + 0x30);
              }
            }
            *(undefined4 *)(lVar8 + 0x28) = *(undefined4 *)(lVar8 + 0x2c);
          }
          osGetSystemTime(local_48,&local_4c);
          uVar9 = (local_48[0] & 0xffffffff) * 1000000 + (ulong)local_4c;
          uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
          if (*(short *)(*(long *)(lVar8 + 0x88 + (ulong)uVar3 * 8) + 0xe) != 0) {
            if (*(ulong *)(lVar10 + 0x18) <= uVar9) {
              nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0x119,
                           "krcWatchdog_IMPL",4,
                           "NVRM: RC watchdog: GPU is probably locked!  Notify Timeout Seconds: %d\n"
                           ,*(undefined4 *)(lVar10 + 0xc));
              *(uint *)(lVar8 + 8) = *(uint *)(lVar8 + 8) | 2;
              (**(code **)(param_2 + 0x180))(param_1,param_2,param_3);
              *(uint *)(lVar8 + 8) = *(uint *)(lVar8 + 8) & 0xfffffffd;
              uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
              *(undefined2 *)(*(long *)(lVar8 + 0x88 + (ulong)uVar3 * 8) + 0xe) = 0;
              *(undefined8 *)(lVar10 + 0x20) = 0;
              nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0x132,
                           "krcWatchdog_IMPL",3,"NVRM: RC watchdog: Trying to recover.\n");
              return;
            }
            if (uVar9 < *(ulong *)(lVar10 + 0x28)) {
              return;
            }
            nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0x13f,"krcWatchdog_IMPL",
                         3,
                         "NVRM: RC watchdog: GPU is possibly locked. Attempting to restart watchdog.\n"
                        );
          }
          if (*(ulong *)(lVar10 + 0x20) <= uVar9) {
            *(ulong *)(lVar10 + 0x20) = (uint)(*(int *)(lVar10 + 0x10) * 1000000) + uVar9;
            *(ulong *)(lVar10 + 0x18) = (uint)(*(int *)(lVar10 + 0xc) * 1000000) + uVar9;
            *(ulong *)(lVar10 + 0x28) = uVar9 + 4000000;
            uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
            *(undefined2 *)(*(long *)(lVar8 + 0x88 + (ulong)uVar3 * 8) + 0xe) = 0xffff;
            krcWatchdogWriteNotifierToGpfifo_IMPL(param_1,param_2,param_3);
            return;
          }
        }
      }
      return;
    }
  }
  return;
}


// ===== 004295d0 krcWatchdogRecovery_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void krcWatchdogRecovery_KERNEL(long param_1)

{
  (**(code **)(param_1 + 0x3b90))
            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
             0x20800a6a,0,0);
  return;
}


// ===== 00429600 krcWatchdogCallbackVblankRecovery_IMPL =====

void krcWatchdogCallbackVblankRecovery_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uVar11;
  long local_60;
  undefined1 local_50 [32];
  
  if (param_3 == 0) {
    local_60 = param_2 + 0x280;
    param_3 = param_2 + 0x1a0;
  }
  else {
    local_60 = param_3 + 0x228;
    param_3 = param_3 + 0x148;
  }
  if ((*(char *)(param_2 + 0x188) != '\0') && ((*(uint *)(param_3 + 8) & 2) == 0)) {
    lVar4 = *(long *)(param_1 + 0x1b80);
    cVar5 = gpuIsGpuFullPower_IMPL();
    if ((lVar4 != 0) && (cVar5 != '\0')) {
      bitVectorClrAll_IMPL(local_50,0xb4);
      if (*(char *)(lVar4 + 0x27a) != '\0') {
        bitVectorSet_IMPL(local_50,0xb4,0xb1);
      }
      if (*(int *)(lVar4 + 0x360) != 0) {
        uVar11 = 0;
        do {
          while( true ) {
            if (uVar11 < 8) {
              uVar10 = *(undefined8 *)(lVar4 + 0x288 + (ulong)uVar11 * 8);
            }
            else {
              uVar10 = 0;
            }
            iVar6 = kheadReadVblankIntrState_IMPL(param_1,uVar10);
            if (iVar6 == 2) break;
            uVar11 = uVar11 + 1;
            if (*(uint *)(lVar4 + 0x360) <= uVar11) {
              return;
            }
          }
          lVar1 = param_3 + (ulong)uVar11 * 4;
          iVar6 = *(int *)(lVar1 + 0x44);
          iVar7 = kheadGetVblankTotalCounter_IMPL(uVar10);
          iVar2 = *(int *)(lVar1 + 100);
          if (iVar6 == iVar7) {
            *(uint *)(lVar1 + 100) = iVar2 + 1U;
            uVar9 = *(uint *)(local_60 + 0xc);
            if (uVar9 < iVar2 + 1U) {
              if (*(char *)(param_2 + 0x18a) != '\0') {
                uVar3 = *(uint *)(*(long *)(g_pSys + 0x228) + 0x6c);
                if (uVar3 < 0x10) {
                  *(uint *)(*(long *)(g_pSys + 0x228) + 0x6c) = uVar3 + 1;
                  nvErrorLog_va(param_1,0x10,"Head %08x Count %08x",uVar11,
                                *(undefined4 *)(lVar1 + 0x44));
                  uVar9 = *(uint *)(local_60 + 0xc);
                }
              }
              nvDbg_Printf("src/kernel/gpu/rc/kernel_rc_watchdog_callback.c",0x1c7,
                           "krcWatchdogCallbackVblankRecovery_IMPL",4,
                           "NVRM: NVRM-RC: RM has detected that %x Seconds without a Vblank Counter Update on head:%c%d\n"
                           ,uVar9,uVar11 + 0x41);
              kdispServiceLowLatencyIntrs_KERNEL
                        (param_1,lVar4,1 << ((byte)uVar11 & 0x1f),7,0,0,local_50);
              *(undefined4 *)(lVar1 + 100) = 0;
            }
          }
          else if (iVar2 != 0) {
            *(int *)(lVar1 + 100) = iVar2 + -1;
          }
          uVar11 = uVar11 + 1;
          uVar8 = kheadGetVblankTotalCounter_IMPL(uVar10);
          *(undefined4 *)(lVar1 + 0x44) = uVar8;
        } while (uVar11 < *(uint *)(lVar4 + 0x360));
        return;
      }
    }
  }
  return;
}


// ===== 00429890 krcWatchdogTimerProc =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void krcWatchdogTimerProc(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  
  if (param_2 != 0) {
    return;
  }
  cVar2 = gpuIsGpuFullPower_IMPL();
  if ((cVar2 != '\0') && (*(char *)(param_1 + 0x455) == '\0')) {
    lVar1 = *(long *)(param_1 + 0x1c18);
    (**(code **)(lVar1 + 0x178))(param_1,lVar1,0);
    krcWatchdogCallbackVblankRecovery_IMPL(param_1,lVar1,0);
    return;
  }
  return;
}


// ===== 00429900 subdeviceCtrlCmdRcGetWatchdogInfo_IMPL =====

undefined8 subdeviceCtrlCmdRcGetWatchdogInfo_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1c18);
  portMemSet(param_2,0,4);
  if ((*(uint *)(lVar3 + 0x1a8) & 1) == 0) {
    if ((*(uint *)(lVar3 + 0x1a8) & 2) == 0) {
      return 0;
    }
  }
  else {
    *param_2 = *param_2 | 4;
    uVar1 = *(uint *)(lVar3 + 0x1a8);
    if ((uVar1 & 2) == 0) goto joined_r0x00429985;
  }
  *param_2 = *param_2 | 1;
  uVar1 = *(uint *)(lVar3 + 0x1a8);
joined_r0x00429985:
  if (((uVar1 & 3) == 1) && (cVar4 = gpuIsGpuFullPower_IMPL(lVar2), cVar4 != '\0')) {
    *param_2 = *param_2 | 2;
  }
  return 0;
}


// ===== 004299a0 subdeviceCtrlCmdRcDisableWatchdog_IMPL =====

undefined8 subdeviceCtrlCmdRcDisableWatchdog_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
    cVar2 = kmigmgrIsMIGEnabled_IMPL(lVar1);
    if (cVar2 != '\0') {
      nvCheckFailedNoLog(1,"!IS_MIG_ENABLED(pGpu)","src/kernel/gpu/rc/kernel_rc_watchdog_ctrl.c",
                         0x4a);
      return 0x56;
    }
  }
  uVar3 = krcWatchdogChangeState_IMPL(*(undefined8 *)(lVar1 + 0x1c18),0,param_1,0xb);
  return uVar3;
}


// ===== 00429a30 subdeviceCtrlCmdRcSoftDisableWatchdog_IMPL =====

undefined8 subdeviceCtrlCmdRcSoftDisableWatchdog_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
    cVar2 = kmigmgrIsMIGEnabled_IMPL(lVar1);
    if (cVar2 != '\0') {
      nvCheckFailedNoLog(1,"!IS_MIG_ENABLED(pGpu)","src/kernel/gpu/rc/kernel_rc_watchdog_ctrl.c",
                         0x5b);
      return 0x56;
    }
  }
  uVar3 = krcWatchdogChangeState_IMPL(*(undefined8 *)(lVar1 + 0x1c18),0,param_1,0xe);
  return uVar3;
}


// ===== 00429ac0 subdeviceCtrlCmdRcEnableWatchdog_IMPL =====

undefined8 subdeviceCtrlCmdRcEnableWatchdog_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
    cVar2 = kmigmgrIsMIGEnabled_IMPL(lVar1);
    if (cVar2 != '\0') {
      nvCheckFailedNoLog(1,"!IS_MIG_ENABLED(pGpu)","src/kernel/gpu/rc/kernel_rc_watchdog_ctrl.c",
                         0x6c);
      return 0x56;
    }
  }
  uVar3 = krcWatchdogChangeState_IMPL(*(undefined8 *)(lVar1 + 0x1c18),0,param_1,10);
  return uVar3;
}


// ===== 00429b50 subdeviceCtrlCmdRcReleaseWatchdogRequests_IMPL =====

undefined8 subdeviceCtrlCmdRcReleaseWatchdogRequests_IMPL(long param_1)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
    cVar2 = kmigmgrIsMIGEnabled_IMPL(lVar1);
    if (cVar2 != '\0') {
      nvCheckFailedNoLog(1,"!IS_MIG_ENABLED(pGpu)","src/kernel/gpu/rc/kernel_rc_watchdog_ctrl.c",
                         0x7d);
      return 0x56;
    }
  }
  uVar3 = krcWatchdogChangeState_IMPL(*(undefined8 *)(lVar1 + 0x1c18),0,param_1,0xc);
  return uVar3;
}


// ===== 00429be0 ksec2ConfigureFalcon_GA100 =====

undefined8 ksec2ConfigureFalcon_GA100(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  
  portMemSet(&local_58,0,0x40);
  local_50 = 0x840600;
  local_58 = 0x840000;
  local_4c = 0;
  local_48 = 0;
  local_40 = 0x128c40800;
  local_38 = 0x10000;
  local_34 = memdescAddrSpaceListToU32(ADDRLIST_FBMEM_PREFERRED);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 2000);
  }
  kflcnConfigureEngine_IMPL(param_1,uVar1,&local_58);
  return 0;
}


// ===== 00429c70 ksec2ReadUcodeFuseVersion_GA100 =====

ulong ksec2ReadUcodeFuseVersion_GA100(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if (0xf < param_3 - 1U) {
    return 0;
  }
  uVar3 = regRead032(param_1 + 0x3a18,0,0,param_3 * 4 + 0x82413c,0);
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


// ===== 00429cc0 ksec2ConfigureFalcon_GA102 =====

undefined8 ksec2ConfigureFalcon_GA102(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  
  portMemSet(&local_58,0,0x40);
  local_50 = 0x840600;
  local_58 = 0x84100000840000;
  local_4c = 1;
  local_48 = 0;
  local_40 = 0x128c40800;
  local_38 = 0x10000;
  local_34 = memdescAddrSpaceListToU32(ADDRLIST_FBMEM_PREFERRED);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 2000);
  }
  kflcnConfigureEngine_IMPL(param_1,uVar1,&local_58);
  return 0;
}


// ===== 00429d50 ksec2ReadUcodeFuseVersion_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong ksec2ReadUcodeFuseVersion_GB100(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  if (0xf < param_3 - 1U) {
    return 0;
  }
  iVar1 = (**(code **)(param_1 + 0x438))();
  uVar3 = regRead032(param_1 + 0x3a18,0,0,iVar1 + 0x4140 + (param_3 - 1U) * 4,0);
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


// ===== 00429dc0 _ksec2IsCmdhandlingCompleted_GB10B =====

bool _ksec2IsCmdhandlingCompleted_GB10B(long param_1)

{
  int iVar1;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x840040,0);
  return iVar1 != -0x3ffe3502;
}


// ===== 00429df0 _ksec2IsGspTargetMaskReleased =====

bool _ksec2IsGspTargetMaskReleased(undefined8 param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = gpuGetDeviceMapping_IMPL(param_1,0,0);
  uVar1 = osDevReadReg032(param_1,uVar2,&DAT_001100f4);
  return uVar1 != 0 && (uVar1 & 0xffffff00) != 0xbadf4100;
}


// ===== 00429e30 ksec2GetMaxSendPacketSize_GB10B =====

undefined8 ksec2GetMaxSendPacketSize_GB10B(void)

{
  return 0x400;
}


// ===== 00429e40 ksec2CanSendPacket_GB10B =====

bool ksec2CanSendPacket_GB10B(long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x840c00,0);
  iVar2 = regRead032(param_1 + 0x3a18,0,0,0x840c04,0);
  return iVar1 == iVar2;
}


// ===== 00429e90 ksec2WaitForGspTargetMaskReleased_GB10B =====

void ksec2WaitForGspTargetMaskReleased_GB10B(long param_1)

{
  timeoutCondWait(param_1 + 0x1af0,0,_ksec2IsGspTargetMaskReleased,0,0x178);
  return;
}


// ===== 00429ec0 ksec2CreateNvdmHeader_GB10B =====

uint ksec2CreateNvdmHeader_GB10B(undefined8 param_1,undefined8 param_2,int param_3)

{
  return param_3 << 0x18 | 0x10de7e;
}


// ===== 00429ed0 ksec2SafeToSendBootCommands_GB10B =====

byte ksec2SafeToSendBootCommands_GB10B(undefined8 param_1,long param_2)

{
  return -(*(char *)(param_2 + 0x909) == '\0') & 0x56;
}


// ===== 00429ef0 ksec2SetupGspImages_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2SetupGspImages_GB10B(long param_1,long param_2,long param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  local_48 = 0;
  local_40[0] = 0;
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x1ca,
               "ksec2SetupGspImages_GB10B",1,"NVRM: Setup GSP FMC Images!\n");
  if (*(char *)(param_2 + 0x908) != '\0') {
    lVar8 = *(long *)(param_1 + 0x1ba8);
    cVar1 = (**(code **)(lVar8 + 0x800))(param_1,lVar8);
    if (cVar1 == '\0') {
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0xe9,
                   "_ksec2GetGspUcodeArchive",1,
                   "NVRM: Loading Prod GSP FMC image for GSP RM using SEC2.\n");
      lVar8 = (**(code **)(lVar8 + 0x868))(lVar8);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0xe4,
                   "_ksec2GetGspUcodeArchive",1,
                   "NVRM: Loading Debug GSP FMC image for GSP RM using SEC2.\n");
      lVar8 = (**(code **)(lVar8 + 0x860))(lVar8);
    }
    if (lVar8 != 0) {
      if (*(char *)(param_2 + 0x908) == '\0') {
        return 0;
      }
      lVar5 = bindataArchiveGetStorage(lVar8,0x23);
      lVar6 = bindataArchiveGetStorage(lVar8,0x17);
      lVar7 = bindataArchiveGetStorage(lVar8,0x38);
      lVar8 = bindataArchiveGetStorage(lVar8,0x33);
      if ((((lVar5 != 0) && (lVar6 != 0)) && (lVar7 != 0)) && (lVar8 != 0)) {
        iVar2 = bindataGetBufferSize(lVar5);
        uVar10 = iVar2 + 0xfffU & 0xfffff000;
        iVar3 = memdescCreate(param_2 + 0x910,param_1,uVar10,0,1,1);
        if (iVar3 == 0) {
          *(undefined4 *)(*(long *)(param_2 + 0x910) + 0x9c) = 0x28;
          iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x910));
          if (iVar3 == 0) {
            iVar3 = memdescMap(*(undefined8 *)(param_2 + 0x910),0,uVar10,1,3,&local_48,local_40);
            if (iVar3 == 0) {
              portMemSet(local_48,0,uVar10);
              iVar3 = bindataWriteToBuffer(lVar5,local_48,iVar2);
              if (iVar3 == 0) {
                memdescUnmap(*(undefined8 *)(param_2 + 0x910),1,local_48,local_40[0]);
                uVar9 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x910),1,0);
                *(undefined8 *)(param_3 + 4) = uVar9;
                *(int *)(param_3 + 0x14) = iVar2;
                memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x910),0,0);
                nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x1fd,
                             "ksec2SetupGspImages_GB10B",1,
                             "NVRM: Setup GSP FMC SysMem Offset GPA 0x%llx, SPA 0x%llx ,Size = 0x%x!\n"
                             ,*(undefined8 *)(param_3 + 4));
                iVar3 = bindataWriteToBuffer(lVar6,param_3 + 0x24,0x30);
                if (iVar3 == 0) {
                  iVar2 = bindataGetBufferSize(lVar7);
                  if (iVar2 == *(int *)(param_2 + 0x958)) {
                    uVar4 = bindataGetBufferSize(lVar7);
                    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x206,
                                 "ksec2SetupGspImages_GB10B",1,
                                 "NVRM: GSP FMC Signature Size 0x%08x\n",uVar4);
                    uVar10 = bindataGetBufferSize(lVar7);
                    if (uVar10 < 0x181) {
                      uVar4 = bindataGetBufferSize(lVar7);
                      iVar3 = bindataWriteToBuffer(lVar7,param_3 + 0x1d4,uVar4);
                      if (iVar3 == 0) {
                        iVar2 = bindataGetBufferSize(lVar8);
                        if (iVar2 == *(int *)(param_2 + 0x95c)) {
                          uVar4 = bindataGetBufferSize(lVar8);
                          nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",
                                       0x20d,"ksec2SetupGspImages_GB10B",1,
                                       "NVRM: GSP FMC PK Size 0x%08x\n",uVar4);
                          uVar10 = bindataGetBufferSize(lVar8);
                          if (uVar10 < 0x181) {
                            uVar4 = bindataGetBufferSize(lVar8);
                            iVar3 = bindataWriteToBuffer(lVar8,param_3 + 0x54,uVar4);
                            if (iVar3 == 0) {
                              if (*(char *)(param_2 + 0x908) == '\0') {
                                return 0;
                              }
                              lVar8 = *(long *)(param_1 + 0x1ba8);
                              if (*(long *)(lVar8 + 0xab8) == 0) {
                                nvAssertFailedNoLog("pKernelGsp->pGspFmcArgumentsCached != NULL",
                                                                                                        
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c"
                                                  ,0xff);
                              }
                              else {
                                iVar2 = memdescGetAddressSpace(*(undefined8 *)(lVar8 + 0xab0));
                                if (iVar2 == 1) {
                                  uVar9 = memdescGetPhysAddr(*(undefined8 *)(lVar8 + 0xab0),1,0);
                                  *(undefined8 *)(param_3 + 0x354) = uVar9;
                                  return 0;
                                }
                                nvAssertFailedNoLog(
                                                  "memdescGetAddressSpace(pKernelGsp->pGspFmcArgumentsDescriptor) == ADDR_SYSMEM"
                                                  ,
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c"
                                                  ,0x100);
                              }
                              nvAssertFailedNoLog("status == NV_OK",
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c"
                                                  ,0x215);
                              iVar3 = 0x40;
                            }
                            else {
                              nvAssertFailedNoLog("status == NV_OK",
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c"
                                                  ,0x211);
                            }
                          }
                          else {
                            nvAssertFailedNoLog("bindataGetBufferSize(pGspImagePublicKey) <= sizeof(pCotPayload->publicKey)"
                                                ,
                                                "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c"
                                                ,0x20e);
                          }
                        }
                        else {
                          nvAssertFailedNoLog("bindataGetBufferSize(pGspImagePublicKey) == pKernelSec2->cotPayloadPublicKeySize"
                                              ,
                                              "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c"
                                              ,0x20c);
                        }
                      }
                      else {
                        nvAssertFailedNoLog("status == NV_OK",
                                            "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c"
                                            ,0x20a);
                      }
                    }
                    else {
                      nvAssertFailedNoLog("bindataGetBufferSize(pGspImageSignature) <= sizeof(pCotPayload->signature)"
                                          ,"src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",
                                          0x207);
                    }
                  }
                  else {
                    nvAssertFailedNoLog("bindataGetBufferSize(pGspImageSignature) == pKernelSec2->cotPayloadSignatureSize"
                                        ,"src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",
                                        0x205);
                  }
                }
                else {
                  nvAssertFailedNoLog("status == NV_OK",
                                      "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x203
                                      ,iVar2);
                }
              }
              else {
                nvAssertFailedNoLog("status == NV_OK",
                                    "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x1f6);
              }
            }
            else {
              nvAssertFailedNoLog("status == NV_OK",
                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x1f1);
            }
          }
          else {
            nvAssertFailedNoLog("status == NV_OK",
                                "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x1ed);
          }
        }
        else {
          nvAssertFailedNoLog("status == NV_OK",
                              "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x1e9);
        }
        memdescDestroy(*(undefined8 *)(param_2 + 0x910));
        *(undefined8 *)(param_2 + 0x910) = 0;
        return iVar3;
      }
      return 0x56;
    }
  }
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x1d0,
               "ksec2SetupGspImages_GB10B",4,
               "NVRM: Cannot find correct ucode archive for booting!\n");
  return 0x57;
}


// ===== 0042a5f0 ksec2PrepareBootCommands_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2PrepareBootCommands_GB10B(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = (**(code **)(param_2 + 0x830))();
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x23c,
                 "ksec2PrepareBootCommands_GB10B",4,
                 "NVRM: SEC2 not yet ready to accept GSP Boot command!\n");
    return iVar1;
  }
  lVar2 = portMemAllocNonPaged(0x35c);
  *(long *)(param_2 + 0x950) = lVar2;
  if (lVar2 == 0) {
    iVar1 = 0x51;
    nvCheckOkFailedNoLog
              (4,0x51,"(pKernelSec2->pCotPayload == NULL) ? NV_ERR_NO_MEMORY : NV_OK",
               "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x241);
  }
  else {
    portMemSet(lVar2,0,0x35c);
    **(undefined2 **)(param_2 + 0x950) = (short)*(undefined4 *)(param_2 + 0x960);
    *(undefined2 *)(*(long *)(param_2 + 0x950) + 2) = 0x35c;
    iVar1 = (**(code **)(param_2 + 0x820))(param_1,param_2,*(undefined8 *)(param_2 + 0x950));
    if (iVar1 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x24a,
                 "ksec2PrepareBootCommands_GB10B",4,"NVRM: GSP Ucode image preparation failed!\n");
  }
  ksec2CleanupBootState_IMPL(param_1,param_2);
  return iVar1;
}


// ===== 0042a750 ksec2SendBootCommands_GB10B =====

int ksec2SendBootCommands_GB10B(long param_1,long param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 extraout_RDX;
  
  if (*(long *)(param_2 + 0x950) == 0) {
    nvAssertFailedNoLog("pKernelSec2->pCotPayload != NULL",
                        "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x26c);
    return 0x40;
  }
  iVar2 = ksec2SendMessage_IMPL();
  if (iVar2 == 0) {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x27f,
                 "ksec2SendBootCommands_GB10B",1,"NVRM: Wait for SEC2 CMD handling: \n");
    iVar2 = timeoutCondWait(param_1 + 0x1af0,0,_ksec2IsCmdhandlingCompleted_GB10B,0,0x134);
    if (iVar2 == 0) {
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x283,
                 "ksec2SendBootCommands_GB10B",4,"NVRM: Timed out waiting for SEC2 Cmd Handling.\n")
    ;
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x840040,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x284,
                 "ksec2SendBootCommands_GB10B",4,
                 "NVRM: After CMD timeout NV_PSEC_FALCON_MAILBOX0 = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x840044,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x286,
                 "ksec2SendBootCommands_GB10B",4,
                 "NVRM: After CMD timeout NV_PSEC_FALCON_MAILBOX1 = 0x%x\n",uVar3);
    uVar4 = extraout_RDX;
  }
  else {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x272,
                 "ksec2SendBootCommands_GB10B",4,"NVRM: Sent following content to SEC2: \n");
    puVar1 = *(undefined2 **)(param_2 + 0x950);
    uVar4 = *(undefined8 *)(puVar1 + 2);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x273,
                 "ksec2SendBootCommands_GB10B",4,
                 "NVRM: version=0x%x, size=0x%x, gspFmcSysmemOffset=0x%llx\n",*puVar1,puVar1[1]);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x276,
                 "ksec2SendBootCommands_GB10B",4,
                 "NVRM: frtsSysmemOffset=0x%llx, frtsSysmemSize=0x%x\n",
                 *(undefined8 *)(*(long *)(param_2 + 0x950) + 0xc),
                 *(undefined4 *)(*(long *)(param_2 + 0x950) + 0x14));
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x278,
                 "ksec2SendBootCommands_GB10B",4,
                 "NVRM: frtsVidmemOffset=0x%llx, frtsVidmemSize=0x%x\n",
                 *(undefined8 *)(*(long *)(param_2 + 0x950) + 0x18),
                 *(undefined4 *)(*(long *)(param_2 + 0x950) + 0x20));
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0x27a,
                 "ksec2SendBootCommands_GB10B",4,"NVRM: gspBootArgsSysmemOffset=0x%llx\n",
                 *(undefined8 *)(*(long *)(param_2 + 0x950) + 0x354));
  }
  ksec2CleanupBootState_IMPL(param_1,param_2,uVar4);
  return iVar2;
}


// ===== 0042aa00 ksec2PrepareAndSendBootCommands_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong ksec2PrepareAndSendBootCommands_GB10B(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = (**(code **)(param_2 + 0x828))();
  if (uVar1 == 0) {
    uVar2 = (**(code **)(param_2 + 0x838))(param_1,param_2);
    return uVar2;
  }
  uVar2 = (ulong)uVar1;
  if (uVar1 == 0x10006) {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0042aa50 ksec2SendPacket_GB10B =====

undefined8 ksec2SendPacket_GB10B(long param_1,undefined8 param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  uint local_4c;
  uint local_3c [3];
  
  uVar4 = 0x1a;
  iVar3 = ksec2PollForCanSend_IMPL();
  if (iVar3 == 0) {
    param_1 = param_1 + 0x3a18;
    uVar4 = 0;
    regWrite032(param_1,0,0,0x840ac0,0x1000000,0);
    local_3c[0] = regRead032(param_1,0,0,0x840ac0,0);
    iVar3 = (local_3c[0] >> 8 & 0xff) * 0x40 + (local_3c[0] >> 2 & 0x3f);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0xb9,
                 "_ksec2WriteToEmem_GB10B",1,
                 "NVRM: About to send data to SEC, ememcOff=0x%x, size=0x%x\n",iVar3,param_4);
    local_4c = param_4 >> 2;
    if (local_4c != 0) {
      puVar5 = param_3;
      do {
        uVar2 = *puVar5;
        puVar5 = puVar5 + 1;
        regWrite032(param_1,0,0,0x840ac4,uVar2,0);
      } while (puVar5 != (undefined4 *)((ulong)(local_4c * 4) + (long)param_3));
    }
    if ((param_4 & 3) != 0) {
      local_3c[0] = 0;
      portMemCopy(local_3c,4,(long)param_3 + (ulong)(param_4 & 0xfffffffc),param_4 & 3);
      regWrite032(param_1,0,0,0x840ac4,local_3c[0],0);
      local_4c = local_4c + 1;
    }
    local_3c[0] = regRead032(param_1,0,0,0x840ac0,0);
    iVar1 = (local_3c[0] >> 8 & 0xff) * 0x40 + (local_3c[0] >> 2 & 0x3f);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0xd0,
                 "_ksec2WriteToEmem_GB10B",1,"NVRM: After sending data, ememcOff = 0x%x\n",iVar1);
    if (iVar1 - iVar3 != local_4c) {
      nvAssertFailedNoLog("(ememOffsetEnd - ememOffsetStart) == wordsWritten",
                          "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb10b.c",0xd2);
    }
    regWrite032(param_1,0,0,0x840c04,(param_4 + 3 & 0xfffffffc) - 4,0);
    regWrite032(param_1,0,0,0x840c00,0,0);
  }
  return uVar4;
}


// ===== 0042ac80 _ksec2WaitBootCond_GB20B =====

bool _ksec2WaitBootCond_GB20B(long param_1)

{
  int iVar1;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x5e0,0);
  return iVar1 == 0xff;
}


// ===== 0042acb0 ksec2GetMaxRecvPacketSize_GB20B =====

undefined8 ksec2GetMaxRecvPacketSize_GB20B(void)

{
  return 0x400;
}


// ===== 0042acc0 ksec2IsResponseAvailable_GB20B =====

bool ksec2IsResponseAvailable_GB20B(long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0x840c80,0);
  iVar2 = regRead032(param_1 + 0x3a18,0,0,0x840c84,0);
  return iVar1 != iVar2;
}


// ===== 0042ad10 ksec2NvdmToSeid_GB20B =====

bool ksec2NvdmToSeid_GB20B(undefined8 param_1,undefined8 param_2,char param_3)

{
  return param_3 == '\x17';
}


// ===== 0042ad20 ksec2CreateMctpHeader_GB20B =====

uint ksec2CreateMctpHeader_GB20B
               (undefined8 param_1,undefined8 param_2,int param_3,uint param_4,byte param_5,
               uint param_6)

{
  return (param_6 & 3) << 0x1c | (uint)param_5 << 0x10 | param_3 << 0x1f | (param_4 & 1) << 0x1e;
}


// ===== 0042ad50 ksec2GetPacketInfo_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
ksec2GetPacketInfo_GB20B
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
      goto LAB_0042ada0;
    }
    if ((uVar1 >> 0x1f & uVar1 >> 0x1e) == 0) {
      *param_5 = 1;
      uVar2 = 0;
      goto LAB_0042ada0;
    }
    uVar3 = 3;
  }
  *param_5 = uVar3;
  uVar2 = (**(code **)(param_2 + 0x8b0))();
LAB_0042ada0:
  *param_6 = (byte)(uVar1 >> 0x18) & 7;
  return uVar2;
}


// ===== 0042adf0 ksec2ValidateMctpPayloadHeader_GB20B =====

undefined8
ksec2ValidateMctpPayloadHeader_GB20B
          (undefined8 param_1,undefined8 param_2,long param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 4);
  if ((char)(uVar1 & 0x7f) == '~') {
    if ((short)(uVar1 >> 8) == 0x10de) {
      if (7 < param_4) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x14b,
                   "ksec2ValidateMctpPayloadHeader_GB20B",4,
                   "NVRM: Packet doesn\'t contain NVDM type in payload header\n");
    }
    else {
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x144,
                   "ksec2ValidateMctpPayloadHeader_GB20B",4,
                   "NVRM: Invalid PCI Vendor Id 0x%0x, expecting 0x10de (Nvidia)\n",
                   uVar1 >> 8 & 0xffff);
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x13c,
                 "ksec2ValidateMctpPayloadHeader_GB20B",4,
                 "NVRM: Invalid MCTP Message type 0x%0x, expecting 0x7e (Vendor Defined PCI)\n",
                 uVar1 & 0x7f);
  }
  return 0x25;
}


// ===== 0042aeb0 ksec2ProcessNvdmMessage_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 ksec2ProcessNvdmMessage_GB20B(undefined8 param_1,long param_2,char *param_3)

{
  undefined8 uVar1;
  
  if ((*param_3 != '\x15') && (*param_3 != '\x18')) {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x171,
                 "ksec2ProcessNvdmMessage_GB20B",4,
                 "NVRM: Unknown or unsupported NVDM type received: 0x%0x\n");
    return 0x56;
  }
  uVar1 = (**(code **)(param_2 + 0x8c0))();
  return uVar1;
}


// ===== 0042af10 ksec2ProcessCommandResponse_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2ProcessCommandResponse_GB20B(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  
  if (param_4 < 0xd) {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x194,
                 "ksec2ProcessCommandResponse_GB20B",4,
                 "NVRM: Expected SEC2 command response, but packet is not big enough for payload. Size: 0x%0x\n"
                 ,param_4);
    return 0x25;
  }
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x199,
               "ksec2ProcessCommandResponse_GB20B",1,
               "NVRM: Received SEC2 command response. Task ID: 0x%0x Command type: 0x%0x Error code: 0x%0x\n"
               ,*(undefined4 *)(param_3 + 1),*(undefined4 *)(param_3 + 5),
               *(undefined4 *)(param_3 + 9));
  iVar1 = (**(code **)(param_2 + 0x8d0))(param_1,param_2,*(undefined4 *)(param_3 + 9));
  if (iVar1 != 0) {
    if (iVar1 != 0x57) {
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x1a3,
                   "ksec2ProcessCommandResponse_GB20B",4,
                   "NVRM: SEC2 response reported error. Task ID: 0x%0x Command type: 0x%0x Error code: 0x%0x\n"
                   ,*(undefined4 *)(param_3 + 1),*(undefined4 *)(param_3 + 5));
      return iVar1;
    }
    return 0x57;
  }
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x19f,
               "ksec2ProcessCommandResponse_GB20B",1,
               "NVRM: Last command was processed by SEC2 successfully!\n");
  return 0;
}


// ===== 0042b080 ksec2ReadPacket_GB20B =====

undefined8
ksec2ReadPacket_GB20B
          (long param_1,undefined8 param_2,undefined4 *param_3,uint param_4,uint *param_5)

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
  iVar2 = regRead032(param_1,0,0,0x840c80,0);
  iVar3 = regRead032(param_1,0,0,0x840c84,0);
  uVar4 = iVar3 - iVar2;
  if ((uVar4 < 0xfffffffc) && (uVar1 = uVar4 + 4, uVar1 <= param_4)) {
    regWrite032(param_1,0,0,0x840ac0,0x2000000,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x207,
                 "ksec2ReadPacket_GB20B",1,
                 "NVRM: About to read data from SEC2, ememcOff=0, size=0x%x\n",uVar1);
    if ((uVar4 & 3) != 0) {
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x20a,
                   "ksec2ReadPacket_GB20B",3,
                   "NVRM: Size=0x%x is not DWORD-aligned, data will be truncated!\n",uVar1);
    }
    puVar7 = param_3;
    do {
      puVar8 = puVar7 + 1;
      uVar5 = regRead032(param_1,0,0,0x840ac4,0);
      *puVar7 = uVar5;
      puVar7 = puVar8;
    } while ((undefined4 *)((ulong)((uVar1 >> 2) * 4) + (long)param_3) != puVar8);
    *param_5 = uVar1;
    uVar4 = regRead032(param_1,0,0,0x840ac0,0);
    uVar4 = (uVar4 >> 8 & 0xff) * 0x40 + (uVar4 >> 2 & 0x3f);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x218,
                 "ksec2ReadPacket_GB20B",1,"NVRM: After reading data, ememcOff = 0x%x\n",uVar4);
    regWrite032(param_1,0,0,0x840c84,iVar2,0);
    regWrite032(param_1,0,0,0x840c80,iVar2,0);
    uVar6 = 0;
    if (uVar4 != uVar1 >> 2) {
      nvAssertFailedNoLog("(ememOffsetEnd) == (packetSize / sizeof(NvU32))",
                          "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x21d);
      uVar6 = 0x40;
    }
    return uVar6;
  }
  nvAssertFailedNoLog("(packetSize >= sizeof(NvU32)) && (packetSize <= maxPacketSize)",
                      "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x1fc);
  return 0x25;
}


// ===== 0042b2c0 ksec2WaitForSecureBoot_GB20B =====

void ksec2WaitForSecureBoot_GB20B(long param_1)

{
  uint uVar1;
  undefined1 local_30 [32];
  
  uVar1 = *(int *)(param_1 + 0x1b08) * 4000000;
  if (uVar1 <= *(uint *)(param_1 + 0x1af4)) {
    uVar1 = *(uint *)(param_1 + 0x1af4);
  }
  timeoutSet(param_1 + 0x1af0,local_30,uVar1,8);
  timeoutCondWait(param_1 + 0x1af0,local_30,_ksec2WaitBootCond_GB20B,0,0x241);
  return;
}


// ===== 0042b320 ksec2SetupGspImages_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2SetupGspImages_GB20B(long param_1,long param_2,long param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  lVar8 = *(long *)(param_1 + 0x1d18);
  lVar5 = *(long *)(param_1 + 0x1ba8);
  local_48 = 0;
  local_40[0] = 0;
  if (lVar8 == 0) {
    nvAssertFailedNoLog("pCC != NULL","src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x24f
                       );
  }
  if (*(char *)(param_2 + 0x908) != '\0') {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x253,
                 "_ksec2GetGspUcodeArchive",2,"NVRM: Loading GSP-RM image using SEC2.\n");
    cVar1 = (**(code **)(lVar5 + 0x800))(param_1,lVar5);
    if (cVar1 == '\0') {
      if ((lVar8 == 0) || (*(char *)(lVar8 + 0x2a9) == '\0')) {
        lVar8 = (**(code **)(lVar5 + 0x868))(lVar5);
      }
      else {
        lVar8 = (**(code **)(lVar5 + 0x870))(lVar5);
      }
    }
    else {
      if ((lVar8 != 0) && (*(char *)(lVar8 + 0x2a9) != '\0')) goto LAB_0042b6a0;
      lVar8 = (**(code **)(lVar5 + 0x860))(lVar5);
    }
    if (lVar8 != 0) {
      lVar5 = bindataArchiveGetStorage(lVar8,0x23);
      lVar6 = bindataArchiveGetStorage(lVar8,0x17);
      lVar7 = bindataArchiveGetStorage(lVar8,0x38);
      lVar8 = bindataArchiveGetStorage(lVar8,0x33);
      if ((((lVar5 == 0) || (lVar6 == 0)) || (lVar7 == 0)) || (lVar8 == 0)) {
        iVar3 = 0x56;
      }
      else {
        iVar2 = bindataGetBufferSize(lVar5);
        uVar9 = iVar2 + 0xfffU & 0xfffff000;
        uVar10 = 0;
        iVar3 = memdescCreate(param_2 + 0x910,param_1,uVar9,0,1,1,0,0x200000000000);
        if (iVar3 == 0) {
          *(undefined4 *)(*(long *)(param_2 + 0x910) + 0x9c) = 0x28;
          iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x910),uVar10);
          if (iVar3 == 0) {
            iVar3 = memdescMap(*(undefined8 *)(param_2 + 0x910),0,uVar9,1,3,&local_48,local_40);
            if (iVar3 == 0) {
              portMemSet(local_48,0,uVar9);
              iVar3 = bindataWriteToBuffer(lVar5,local_48,iVar2);
              if (iVar3 == 0) {
                memdescUnmap(*(undefined8 *)(param_2 + 0x910),1,local_48,local_40[0]);
                uVar10 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x910),1,0);
                *(undefined8 *)(param_3 + 4) = uVar10;
                iVar3 = bindataWriteToBuffer(lVar6,param_3 + 0x24,0x30);
                if (iVar3 == 0) {
                  iVar2 = bindataGetBufferSize(lVar7);
                  if (iVar2 == *(int *)(param_2 + 0x958)) {
                    uVar9 = bindataGetBufferSize(lVar7);
                    if (uVar9 < 0x181) {
                      uVar4 = bindataGetBufferSize(lVar7);
                      iVar3 = bindataWriteToBuffer(lVar7,param_3 + 0x1d4,uVar4);
                      if (iVar3 == 0) {
                        iVar2 = bindataGetBufferSize(lVar8);
                        if (iVar2 == *(int *)(param_2 + 0x95c)) {
                          uVar9 = bindataGetBufferSize(lVar8);
                          if (uVar9 < 0x181) {
                            uVar4 = bindataGetBufferSize(lVar8);
                            iVar3 = bindataWriteToBuffer(lVar8,param_3 + 0x54,uVar4);
                            if (iVar3 == 0) {
                              if (*(long *)(param_1 + 0x1d18) == 0) {
                                nvAssertFailedNoLog("pCC != NULL",
                                                                                                        
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                                  ,0x2c6);
                              }
                              if (*(char *)(param_2 + 0x908) == '\0') {
                                return 0;
                              }
                              lVar8 = *(long *)(param_1 + 0x1ba8);
                              if (*(long *)(lVar8 + 0xab8) == 0) {
                                nvAssertFailedNoLog("pKernelGsp->pGspFmcArgumentsCached != NULL",
                                                                                                        
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                                  ,0x2cd);
                              }
                              else {
                                iVar3 = memdescGetAddressSpace(*(undefined8 *)(lVar8 + 0xab0));
                                if (iVar3 == 1) {
                                  uVar10 = memdescGetPhysAddr(*(undefined8 *)(lVar8 + 0xab0),1,0);
                                  *(undefined8 *)(param_3 + 0x354) = uVar10;
                                  return 0;
                                }
                                nvAssertFailedNoLog(
                                                  "memdescGetAddressSpace(pKernelGsp->pGspFmcArgumentsDescriptor) == ADDR_SYSMEM"
                                                  ,
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                                  ,0x2ce);
                              }
                              iVar3 = 0x40;
                              nvAssertFailedNoLog("status == NV_OK",
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                                  ,0x337);
                            }
                            else {
                              nvAssertFailedNoLog("status == NV_OK",
                                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                                  ,0x333);
                            }
                          }
                          else {
                            nvAssertFailedNoLog("bindataGetBufferSize(pGspImagePublicKey) <= sizeof(pCotPayload->publicKey)"
                                                ,
                                                "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                                ,0x331);
                          }
                        }
                        else {
                          nvAssertFailedNoLog("bindataGetBufferSize(pGspImagePublicKey) == pKernelSec2->cotPayloadPublicKeySize"
                                              ,
                                              "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                              ,0x330);
                        }
                      }
                      else {
                        nvAssertFailedNoLog("status == NV_OK",
                                            "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c"
                                            ,0x32e);
                      }
                    }
                    else {
                      nvAssertFailedNoLog("bindataGetBufferSize(pGspImageSignature) <= sizeof(pCotPayload->signature)"
                                          ,"src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",
                                          0x32c);
                    }
                  }
                  else {
                    nvAssertFailedNoLog("bindataGetBufferSize(pGspImageSignature) == pKernelSec2->cotPayloadSignatureSize"
                                        ,"src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",
                                        0x32b);
                  }
                }
                else {
                  nvAssertFailedNoLog("status == NV_OK",
                                      "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x329
                                     );
                }
              }
              else {
                nvAssertFailedNoLog("status == NV_OK",
                                    "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x321);
              }
            }
            else {
              nvAssertFailedNoLog("status == NV_OK",
                                  "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x31c);
            }
          }
          else {
            nvAssertFailedNoLog("status == NV_OK",
                                "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x318);
          }
        }
        else {
          nvAssertFailedNoLog("status == NV_OK",
                              "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x314);
        }
      }
      goto LAB_0042b6cc;
    }
  }
LAB_0042b6a0:
  iVar3 = 0x57;
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x2fd,
               "ksec2SetupGspImages_GB20B",4,
               "NVRM: Cannot find correct ucode archive for booting!\n");
LAB_0042b6cc:
  memdescDestroy(*(undefined8 *)(param_2 + 0x910));
  *(undefined8 *)(param_2 + 0x910) = 0;
  return iVar3;
}


// ===== 0042b9b0 ksec2DumpDebugState_GB20B =====

undefined1  [16] ksec2DumpDebugState_GB20B(long param_1)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auVar4 [16];
  long local_20 [2];
  
  iVar2 = gpuGetOneDeviceEntry_IMPL(param_1,0x33,0xffffffff,0,0xffffffff,local_20);
  if (iVar2 == 0) {
    uVar1 = *(ulong *)(param_1 + 0x878);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x367,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: GPU %04x:%02x:%02x\n",uVar1 >> 0x20);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x430,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x36b,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: Devinit Boot Status = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x4d8,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x36e,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: COT Polling Status = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x4d0,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x371,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: FRTS Completion = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x5e0,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x374,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: FWSEC Completion = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x840320,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x377,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: FWSEC Error Code = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x840324,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x37a,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: FWSEC Offending PC = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x840328,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x37d,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: FWSEC Offending Address = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,0x84032c,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x380,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: FWSEC Additional info = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x400,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",899,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: FWSEC version = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x408,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x386,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: Devinit version = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x43c,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x389,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: Failing Register Addr = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x440,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x38c,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: Devinit PC = 0x%x\n",uVar3);
    uVar3 = regRead032(param_1 + 0x3a18,0,0,*(int *)(local_20[0] + 0x10) + 0x470,0);
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x38f,
                 "ksec2DumpDebugState_GB20B",4,"NVRM: PRI error code = 0x%x\n",uVar3);
    auVar4._8_8_ = uVar1 & 0xff;
    auVar4._0_8_ = uVar1 >> 8 & 0xff;
    return auVar4;
  }
  auVar4 = nvAssertFailedNoLog("status == NV_OK",
                               "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x365);
  return auVar4;
}


// ===== 0042bde0 ksec2GspFmcIsEnforced_GB20B =====

undefined8 ksec2GspFmcIsEnforced_GB20B(void)

{
  return 1;
}


// ===== 0042bdf0 ksec2SafeToSendBootCommands_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 ksec2SafeToSendBootCommands_GB20B(long param_1,long param_2)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x446) == '\0') {
    if (*(char *)(param_1 + 0x490e) != '\0') {
      return 0x10006;
    }
    if (*(char *)(param_2 + 0x50) != '\0') {
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x3c6,
                   "ksec2SafeToSendBootCommands_GB20B",4,
                   "NVRM: RM cannot boot with SEC2 missing on silicon.\n");
      return 0x56;
    }
    cVar1 = (**(code **)(param_2 + 0x888))();
    if (cVar1 != '\0') {
      if (*(char *)(param_2 + 0x90b) == '\0') {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x3d3,
                   "ksec2SafeToSendBootCommands_GB20B",4,
                   "NVRM: Chain-of-trust (GSP-FMC) cannot be disabled on silicon.\n");
      return 0x56;
    }
  }
  else if (*(char *)(param_2 + 0x50) != '\0') {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x3ca,
                 "ksec2SafeToSendBootCommands_GB20B",3,
                 "NVRM: Secure boot is disabled due to missing SEC2.\n");
    return 0x10006;
  }
  if (*(char *)(param_2 + 0x90b) != '\0') {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x3d9,
                 "ksec2SafeToSendBootCommands_GB20B",3,
                 "NVRM: Chain-of-trust is disabled via regkey\n");
    *(undefined1 *)(param_2 + 0x90a) = 1;
    return 0x10006;
  }
  return 0;
}


// ===== 0042bf30 ksec2PrepareBootCommands_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2PrepareBootCommands_GB20B(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = (**(code **)(param_2 + 0x890))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_2 + 0x830))(param_1,param_2);
    if (iVar1 == 0) {
      if (*(char *)(param_1 + 0x444) == '\0') {
        lVar2 = portMemAllocNonPaged(0x35c);
        *(long *)(param_2 + 0x950) = lVar2;
        if (lVar2 == 0) {
          iVar1 = 0x51;
          nvCheckOkFailedNoLog
                    (4,0x51,"(pKernelSec2->pCotPayload == NULL) ? NV_ERR_NO_MEMORY : NV_OK",
                     "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x40e);
          goto LAB_0042c079;
        }
        portMemSet(lVar2,0,0x35c);
      }
      **(undefined2 **)(param_2 + 0x950) = (short)*(undefined4 *)(param_2 + 0x960);
      *(undefined2 *)(*(long *)(param_2 + 0x950) + 2) = 0x35c;
      *(undefined8 *)(*(long *)(param_2 + 0x950) + 0x18) = 0;
      *(undefined4 *)(*(long *)(param_2 + 0x950) + 0x20) = 0;
      *(undefined8 *)(*(long *)(param_2 + 0x950) + 4) = 0xffffffffffffffff;
      *(undefined8 *)(*(long *)(param_2 + 0x950) + 0x354) = 0xffffffffffffffff;
      if (*(char *)(param_2 + 0x90b) == '\0') {
        iVar1 = (**(code **)(param_2 + 0x820))(param_1,param_2,*(undefined8 *)(param_2 + 0x950));
        if (iVar1 != 0) {
          nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x424,
                       "ksec2PrepareBootCommands_GB20B",4,"NVRM: Ucode image preparation failed!\n")
          ;
          goto LAB_0042c079;
        }
      }
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x405,
                 "ksec2PrepareBootCommands_GB20B",4,"NVRM: FWSEC not ready to process COT command\n"
                );
  }
  else {
    nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x3fd,
                 "ksec2PrepareBootCommands_GB20B",4,"NVRM: FWSEC timed out processing COT command\n"
                );
  }
LAB_0042c079:
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x42c,
               "ksec2PrepareBootCommands_GB20B",4,
               "NVRM: FWSEC failed to process boot command. RM cannot boot.\n");
  ksec2CleanupBootState_IMPL(param_1,param_2);
  return iVar1;
}


// ===== 0042c150 ksec2SendBootCommands_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2SendBootCommands_GB20B(undefined8 param_1,long param_2)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (*(long *)(param_2 + 0x950) == 0) {
    nvAssertFailedNoLog("pKernelSec2->pCotPayload != NULL",
                        "src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x448);
    return 0x40;
  }
  iVar2 = ksec2SendAndReadMessage_IMPL();
  if (iVar2 == 0) {
    *(undefined1 *)(param_2 + 0x90a) = 1;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x44e,
               "ksec2SendBootCommands_GB20B",4,"NVRM: Sent following content to FWSEC: \n");
  puVar1 = *(undefined2 **)(param_2 + 0x950);
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x44f,
               "ksec2SendBootCommands_GB20B",4,
               "NVRM: version=0x%x, size=0x%x, gspFmcSysmemOffset=0x%llx\n",*puVar1,puVar1[1],
               *(undefined8 *)(puVar1 + 2));
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x452,
               "ksec2SendBootCommands_GB20B",4,
               "NVRM: frtsSysmemOffset=0x%llx, frtsSysmemSize=0x%x\n",
               *(undefined8 *)(*(long *)(param_2 + 0x950) + 0xc),
               *(undefined4 *)(*(long *)(param_2 + 0x950) + 0x14));
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x454,
               "ksec2SendBootCommands_GB20B",4,
               "NVRM: frtsVidmemOffset=0x%llx, frtsVidmemSize=0x%x\n",
               *(undefined8 *)(*(long *)(param_2 + 0x950) + 0x18),
               *(undefined4 *)(*(long *)(param_2 + 0x950) + 0x20));
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x456,
               "ksec2SendBootCommands_GB20B",4,"NVRM: gspBootArgsSysmemOffset=0x%llx\n",
               *(undefined8 *)(*(long *)(param_2 + 0x950) + 0x354));
  nvDbg_Printf("src/kernel/gpu/sec2/arch/blackwell/kernel_sec2_gb20b.c",0x46c,
               "ksec2SendBootCommands_GB20B",4,
               "NVRM: FWSEC failed to process boot command. RM cannot boot.\n");
  (**(code **)(param_2 + 0x8c8))(param_1,param_2);
  ksec2CleanupBootState_IMPL(param_1,param_2);
  return iVar2;
}


// ===== 0042c340 ksec2PrepareAndSendBootCommands_GB20B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong ksec2PrepareAndSendBootCommands_GB20B(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = (**(code **)(param_2 + 0x828))();
  if (uVar1 == 0) {
    uVar2 = (**(code **)(param_2 + 0x838))(param_1,param_2);
    return uVar2;
  }
  uVar2 = (ulong)uVar1;
  if (uVar1 == 0x10006) {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0042c390 ksec2ErrorCode2NvStatusMap_GB20B =====

undefined8 ksec2ErrorCode2NvStatusMap_GB20B(undefined8 param_1,undefined8 param_2,uint param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x57;
  if (param_3 != 0x9f) {
    if (param_3 < 0xa0) {
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
      uVar1 = 0xffff;
      if (param_3 == 0xa1) {
        uVar1 = 0x25;
      }
    }
  }
  return uVar1;
}


// ===== 0042c3e0 ksec2StateLoad_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong ksec2StateLoad_GH100(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x2a9) != '\0')) {
    uVar2 = (**(code **)(lVar1 + 0x1b8))(lVar1,0x2f);
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    nvAssertOkFailedNoLog
              (uVar2 & 0xffffffff,"confComputeDeriveSecrets_HAL(pConfCompute, MC_ENGINE_IDX_SEC2)",
               "src/kernel/gpu/sec2/arch/hopper/kernel_sec2_gh100.c",0x2b);
    return uVar2 & 0xffffffff;
  }
  return 0;
}


// ===== 0042c450 ksec2ConfigureFalcon_TU102 =====

undefined8 ksec2ConfigureFalcon_TU102(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 local_58;
  undefined4 local_50;
  undefined1 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  
  portMemSet(&local_58,0,0x40);
  local_50 = 0x840600;
  local_58 = 0x840000;
  local_4c = 0;
  local_48 = 0;
  local_40 = 0x128c40800;
  local_38 = 0x10000;
  local_34 = memdescAddrSpaceListToU32(ADDRLIST_FBMEM_PREFERRED);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 2000);
  }
  kflcnConfigureEngine_IMPL(param_1,uVar1,&local_58);
  return 0;
}


// ===== 0042c4e0 ksec2ResetHw_TU102 =====

undefined8 ksec2ResetHw_TU102(long param_1)

{
  uint uVar1;
  int iVar2;
  
  param_1 = param_1 + 0x3a18;
  iVar2 = 10;
  uVar1 = regRead032(param_1,0,0,0x8403c0,0);
  regWrite032(param_1,0,0,0x8403c0,uVar1 | 1,0);
  do {
    regRead032(param_1,0,0,0x8403c0,0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 10;
  uVar1 = regRead032(param_1,0,0,0x8403c0,0);
  regWrite032(param_1,0,0,0x8403c0,uVar1 & 0xfffffffe,0);
  do {
    regRead032(param_1,0,0,0x8403c0,0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}


// ===== 0042c5a0 ksec2GetGenericBlUcode_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2GetGenericBlUcode_TU102(undefined8 param_1,long param_2,long *param_3,undefined8 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  undefined8 uVar8;
  char *pcVar9;
  
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("ppDesc != NULL","src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0xb7)
    ;
    return 0x1f;
  }
  if (param_4 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("ppImg != NULL","src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0xb8);
    return 0x1f;
  }
  lVar5 = *(long *)(param_2 + 0x940);
  if (lVar5 == 0) {
    if (*(long *)(param_2 + 0x948) != 0) {
      nvAssertFailedNoLog("pKernelSec2->pGenericBlUcodeImg == NULL",
                          "src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0xbc);
      return 0x40;
    }
    lVar6 = (**(code **)(param_2 + 0x808))();
    uVar8 = 0x71;
    pcVar9 = "pBinArchive != NULL";
    if (lVar6 != 0) {
      lVar4 = bindataArchiveGetStorage(lVar6,0x12,0x71);
      if (lVar4 != 0) {
        iVar1 = bindataGetBufferSize(lVar4);
        iVar2 = bindataGetBufferSize(lVar4);
        iVar3 = bindataGetBufferSize(lVar4);
        uVar7 = (iVar2 + -0x100) - iVar3 & iVar1 + 0xffU;
        lVar5 = portMemAllocNonPaged(uVar7);
        if (lVar5 == 0) {
          portMemFree(0);
          portMemFree(0);
        }
        else {
          iVar1 = bindataWriteToBuffer(lVar4,lVar5,uVar7);
          if (iVar1 != 0) {
            nvAssertOkFailedNoLog
                      (iVar1,
                       "bindataWriteToBuffer(pBinDesc, (NvU8 *) pGenericBlUcodeDesc, descSizeAligned)"
                       ,"src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0x7f);
            portMemFree(lVar5);
            portMemFree(0);
            goto LAB_0042c864;
          }
          uVar8 = bindataArchiveGetStorage(lVar6,0x23);
          iVar1 = bindataGetBufferSize(uVar8);
          iVar2 = bindataGetBufferSize(uVar8);
          iVar3 = bindataGetBufferSize(uVar8);
          uVar7 = (iVar2 + -0x100) - iVar3 & iVar1 + 0xffU;
          if (uVar7 < *(uint *)(lVar5 + 0xc)) {
            portMemFree(lVar5);
            portMemFree(0);
            iVar1 = 0x25;
            goto LAB_0042c864;
          }
          lVar6 = portMemAllocNonPaged(uVar7);
          if (lVar6 != 0) {
            iVar1 = bindataWriteToBuffer(uVar8,lVar6,uVar7);
            if (iVar1 == 0) {
              *(long *)(param_2 + 0x940) = lVar5;
              *(long *)(param_2 + 0x948) = lVar6;
              goto LAB_0042c5df;
            }
            nvAssertOkFailedNoLog
                      (iVar1,"bindataWriteToBuffer(pBinImg, pGenericBlUcodeImg, imgSizeAligned)",
                       "src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0x93);
            portMemFree(lVar5);
            portMemFree(lVar6);
            goto LAB_0042c864;
          }
          portMemFree(lVar5);
          portMemFree(0);
        }
        iVar1 = 0x51;
LAB_0042c864:
        nvAssertOkFailedNoLog
                  (iVar1,
                   "s_allocateGenericBlUcode(pGpu, pKernelSec2, &pKernelSec2->pGenericBlUcodeDesc, &pKernelSec2->pGenericBlUcodeImg)"
                   ,"src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0xbd);
        return iVar1;
      }
      uVar8 = 0x75;
      pcVar9 = "pBinDesc != NULL";
    }
    nvAssertFailedNoLog(pcVar9,"src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",uVar8);
    portMemFree(0);
    portMemFree(0);
    lVar5 = *(long *)(param_2 + 0x940);
    if (lVar5 == 0) {
      nvAssertFailedNoLog("pKernelSec2->pGenericBlUcodeDesc != NULL",
                          "src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0xc3);
      return 0x40;
    }
  }
LAB_0042c5df:
  if (*(long *)(param_2 + 0x948) == 0) {
    nvAssertFailedNoLog("pKernelSec2->pGenericBlUcodeImg != NULL",
                        "src/kernel/gpu/sec2/arch/turing/kernel_sec2_tu102.c",0xc4);
    return 0x40;
  }
  *param_3 = lVar5;
  *param_4 = *(undefined8 *)(param_2 + 0x948);
  return 0;
}


// ===== 0042c970 ksec2ConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 ksec2ConstructEngine_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_2c [3];
  
  uVar2 = (**(code **)(param_2 + 0x7e0))();
  local_2c[0] = 0;
  iVar3 = osReadRegistryDword(param_1,"RMDevinitBySecureBoot",local_2c);
  if ((iVar3 == 0 && local_2c[0] == 0) ||
     ((iVar3 = osReadRegistryDword(param_1,"RMDevinitBySecureBoot",local_2c), iVar3 != 0 &&
      (((*(char *)(param_1 + 0x446) != '\0' || (*(char *)(param_1 + 0x4910) != '\0')) ||
       (*(char *)(param_1 + 0x4911) != '\0')))))) {
    nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x67,"_ksec2InitRegistryOverrides",3,
                 "NVRM: RM to boot GSP due to regkey override.\n");
    *(undefined1 *)(param_2 + 0x90c) = 1;
  }
  iVar3 = osReadRegistryDword(param_1,"RmDisableSec2",local_2c);
  if ((((iVar3 == 0) && (local_2c[0] == 1)) && (*(char *)(param_1 + 0x446) != '\0')) ||
     ((*(char *)(param_1 + 0x4910) != '\0' || (*(char *)(param_1 + 0x4911) != '\0')))) {
    nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x73,"_ksec2InitRegistryOverrides",3,
                 "NVRM: SEC2 disabled due to regkey override.\n");
    *(undefined1 *)(param_2 + 0x50) = 1;
  }
  iVar3 = osReadRegistryDword(param_1,"RmDisableCotCmd",local_2c);
  if ((iVar3 == 0) && ((local_2c[0] & 0x30) != 0)) {
    *(undefined1 *)(param_2 + 0x90b) = 1;
    cVar1 = *(char *)(param_2 + 0x50);
  }
  else {
    cVar1 = *(char *)(param_2 + 0x50);
  }
  if (cVar1 != '\0') {
    nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x4f,"ksec2ConstructEngine_IMPL",3,
                 "NVRM: KernelSec2 is disabled\n");
    return 0x57;
  }
  return uVar2;
}


// ===== 0042cb60 ksec2StateUnload_IMPL =====

undefined8 ksec2StateUnload_IMPL(long param_1,long param_2)

{
  if ((*(char *)(param_1 + 0x459) != '\0') && (*(int *)(param_1 + 0x4b34) == 1)) {
    return 0;
  }
  if (*(long *)(param_2 + 0x910) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x910));
    *(undefined8 *)(param_2 + 0x910) = 0;
  }
  if (*(long *)(param_2 + 0x918) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x918));
    *(undefined8 *)(param_2 + 0x918) = 0;
  }
  return 0;
}


// ===== 0042cbf0 ksec2PollForResponse_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2PollForResponse_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  
  timeoutSet(param_1 + 0x1af0,param_2 + 0x928,0,8);
  do {
    cVar1 = (**(code **)(param_2 + 0x880))(param_1,param_2);
    if (cVar1 != '\0') {
      return 0;
    }
    osSpinLoop();
    iVar2 = timeoutCheck(param_1 + 0x1af0,param_2 + 0x928,0x10c);
  } while (iVar2 == 0);
  if ((iVar2 == 0x65) && (cVar1 = (**(code **)(param_2 + 0x880))(param_1,param_2), cVar1 != '\0')) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0xe3,"_ksec2WaitForResponse",4,
               "NVRM: SEC2 command timed out\n");
  return iVar2;
}


// ===== 0042cce0 ksec2SendMessage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2SendMessage_IMPL(undefined8 param_1,long param_2,long param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  ulong uVar8;
  uint uVar9;
  
  iVar4 = (**(code **)(param_2 + 0x850))();
  puVar7 = (undefined4 *)portMemAllocNonPaged(iVar4);
  if (puVar7 == (undefined4 *)0x0) {
    nvCheckFailedNoLog(4,"pBuffer != NULL","src/kernel/gpu/sec2/kernel_sec2.c",0x13b);
    return 0x51;
  }
  uVar1 = iVar4 - 8;
  portMemSet(puVar7,0,iVar4);
  uVar3 = (**(code **)(param_2 + 0x8a0))(param_1,param_2,param_5 & 0xff);
  uVar5 = (**(code **)(param_2 + 0x860))(param_1,param_2,1,param_4 <= uVar1,uVar3,0);
  *puVar7 = uVar5;
  uVar5 = (**(code **)(param_2 + 0x858))(param_1,param_2,param_5);
  uVar9 = param_4;
  if (uVar1 <= param_4) {
    uVar9 = uVar1;
  }
  uVar8 = (ulong)uVar9;
  puVar7[1] = uVar5;
  portMemCopy(puVar7 + 2,uVar1,param_3,uVar8);
  iVar6 = (**(code **)(param_2 + 0x868))(param_1,param_2,puVar7,uVar9 + 8);
  if (((iVar6 == 0) && (uVar1 < param_4)) && (param_4 = param_4 - uVar9, param_4 != 0)) {
    uVar9 = 0;
    uVar1 = iVar4 - 4;
    do {
      uVar2 = param_4;
      if (uVar1 <= param_4) {
        uVar2 = uVar1;
      }
      uVar9 = uVar9 + 1;
      uVar5 = (**(code **)(param_2 + 0x860))(param_1,param_2,0,param_4 <= uVar1,uVar3,uVar9 & 3);
      *puVar7 = uVar5;
      portMemCopy(puVar7 + 1,iVar4 + -4,uVar8 + param_3,uVar2);
      iVar6 = (**(code **)(param_2 + 0x868))(param_1,param_2,puVar7,uVar2 + 4);
      if (iVar6 != 0) break;
      uVar8 = (ulong)((int)uVar8 + uVar2);
      param_4 = param_4 - uVar2;
    } while (param_4 != 0);
  }
  portMemFree(puVar7);
  return iVar6;
}


// ===== 0042cf20 ksec2SendAndReadMessage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2SendAndReadMessage_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  long in_R9;
  uint in_stack_00000008;
  undefined1 local_41;
  int local_40;
  int local_3c [3];
  
  iVar2 = ksec2SendMessage_IMPL();
  if ((iVar2 == 0) && (iVar2 = ksec2PollForResponse_IMPL(param_1,param_2), iVar2 == 0)) {
    local_40 = 0;
    cVar1 = (**(code **)(param_2 + 0x880))(param_1,param_2);
    if (cVar1 == '\0') {
      nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x195,"_ksec2ReadMessage",3,
                   "NVRM: Tried to read SEC2 response but none is available\n");
    }
    else {
      uVar3 = (**(code **)(param_2 + 0x898))(param_1,param_2);
      lVar4 = portMemAllocNonPaged(uVar3);
      if (lVar4 == 0) {
        iVar2 = 0x51;
        nvCheckFailedNoLog(4,"pPacketBuffer != NULL","src/kernel/gpu/sec2/kernel_sec2.c",0x19b);
      }
      else {
        if (local_40 - 2U < 2) {
          uVar7 = 0;
          if (in_R9 == 0) {
LAB_0042d0db:
            in_R9 = lVar4 + 7;
          }
        }
        else {
          uVar7 = 0;
          do {
            iVar2 = ksec2PollForResponse_IMPL(param_1,param_2);
            if (iVar2 != 0) goto LAB_0042d10e;
            iVar2 = (**(code **)(param_2 + 0x878))(param_1,param_2,lVar4,uVar3,local_3c);
            if (iVar2 != 0) {
              nvCheckOkFailedNoLog
                        (4,iVar2,
                         "ksec2ReadPacket_HAL(pGpu, pKernelSec2, pPacketBuffer, recvBufferSize, &packetSize)"
                         ,"src/kernel/gpu/sec2/kernel_sec2.c",0x1ab);
              goto LAB_0042d10e;
            }
            iVar2 = (**(code **)(param_2 + 0x8a8))
                              (param_1,param_2,lVar4,local_3c[0],&local_40,&local_41);
            if (iVar2 != 0) goto LAB_0042d10e;
            iVar2 = (int)uVar7;
            if ((local_40 == 0) || (local_40 == 3)) {
              iVar5 = local_3c[0] + -7;
              if (in_R9 != 0) {
                lVar6 = 7;
                goto LAB_0042d05d;
              }
              if (local_40 == 3) {
                uVar7 = (ulong)(uint)(iVar2 + iVar5);
                goto LAB_0042d0db;
              }
LAB_0042d1d0:
              nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x1c3,"_ksec2ReadMessage",4,
                           "NVRM: No buffer provided when receiving multi-packet message. Buffer needed to reconstruct message\n"
                          );
LAB_0042d1b0:
              iVar2 = 0x1a;
              goto LAB_0042d10e;
            }
            if (in_R9 == 0) goto LAB_0042d1d0;
            iVar5 = local_3c[0] + -4;
            lVar6 = 4;
LAB_0042d05d:
            uVar8 = iVar5 + iVar2;
            if (in_stack_00000008 < uVar8) {
              nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x1cc,"_ksec2ReadMessage",4,
                           "NVRM: Buffer provided for message payload too small. Payload size: 0x%x Buffer size: 0x%x\n"
                           ,uVar8,in_stack_00000008);
              goto LAB_0042d1b0;
            }
            portMemCopy(uVar7 + in_R9,in_stack_00000008 - iVar2,lVar6 + lVar4);
            uVar7 = (ulong)uVar8;
          } while (1 < local_40 - 2U);
        }
        iVar2 = (**(code **)(param_2 + 0x8b8))(param_1,param_2,in_R9,uVar7);
LAB_0042d10e:
        portMemFree(lVar4);
      }
    }
  }
  return iVar2;
}


// ===== 0042d200 ksec2Destruct_IMPL =====

void ksec2Destruct_IMPL(long param_1)

{
  portMemFree(*(undefined8 *)(param_1 + 0x940));
  *(undefined8 *)(param_1 + 0x940) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0x948));
  *(undefined8 *)(param_1 + 0x948) = 0;
  return;
}


// ===== 0042d250 ksec2RegisterIntrService_IMPL =====

void ksec2RegisterIntrService_IMPL(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  
  if ((param_2 != 0) && (*(long *)(param_2 + 2000) != 0)) {
    iVar1 = *(int *)(*(long *)(param_2 + 2000) + 0x634);
    if (iVar1 != -0x4cc4eb00) {
      nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x22a,"ksec2RegisterIntrService_IMPL",1,
                   "NVRM: Registering 0x%x/0x%x to handle SEC2 nonstall intr\n",iVar1,0x2f);
      if (*(long *)(param_3 + 0x470) != 0) {
        nvAssertFailedNoLog("pRecords[mcIdx].pNotificationService == NULL",
                            "src/kernel/gpu/sec2/kernel_sec2.c",0x22c);
      }
      *(undefined1 *)(param_3 + 0x478) = 0;
      *(undefined8 *)(param_3 + 0x470) = *(undefined8 *)(param_2 + 0x7b8);
      return;
    }
    nvAssertFailedNoLog("pKernelFalcon->physEngDesc != ENG_INVALID",
                        "src/kernel/gpu/sec2/kernel_sec2.c",0x226);
    return;
  }
  nvAssertFailedNoLog("pKernelFalcon","src/kernel/gpu/sec2/kernel_sec2.c",0x223);
  return;
}


// ===== 0042d340 ksec2ServiceNotificationInterrupt_IMPL =====

undefined8 ksec2ServiceNotificationInterrupt_IMPL(undefined8 param_1)

{
  nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x23a,"ksec2ServiceNotificationInterrupt_IMPL",1,
               "NVRM: servicing nonstall intr for SEC2 engine\n");
  engineNonStallIntrNotify(param_1,0x31);
  return 0;
}


// ===== 0042d390 ksec2StateDestroy_IMPL =====

void ksec2StateDestroy_IMPL(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x950) != 0) {
    portMemFree();
    *(undefined8 *)(param_2 + 0x950) = 0;
  }
  if (*(long *)(param_2 + 0x910) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x910));
    *(undefined8 *)(param_2 + 0x910) = 0;
  }
  return;
}


// ===== 0042d3f0 ksec2PollForCanSend_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int ksec2PollForCanSend_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined1 local_40 [24];
  
  timeoutSet(param_1 + 0x1af0,local_40,0,8);
  do {
    cVar1 = (**(code **)(param_2 + 0x848))(param_1,param_2);
    if (cVar1 != '\0') {
      return 0;
    }
    osSpinLoop();
    iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0x26e);
  } while (iVar2 == 0);
  if ((iVar2 == 0x65) && (cVar1 = (**(code **)(param_2 + 0x848))(param_1,param_2), cVar1 != '\0')) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/sec2/kernel_sec2.c",0x278,"ksec2PollForCanSend_IMPL",4,
               "NVRM: Timed out waiting for SEC2 command queue to be empty.\n");
  return iVar2;
}


// ===== 0042d4e0 ksec2CleanupBootState_IMPL =====

void ksec2CleanupBootState_IMPL(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x950) != 0) {
    portMemFree();
    *(undefined8 *)(param_2 + 0x950) = 0;
  }
  if (*(long *)(param_2 + 0x910) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x910));
    *(undefined8 *)(param_2 + 0x910) = 0;
  }
  return;
}


// ===== 0042d53a sec2ctxConstructHal_KERNEL.cold =====

void sec2ctxConstructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0042d550 sec2ctxConstructHal_KERNEL =====

void sec2ctxConstructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(param_1 + 0x1d8);
    uVar2 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
    uVar4 = kflcnGetKernelFalconForEngine_IMPL(uVar2,0x28c40800);
    kflcnAllocContext_IMPL
              (uVar2,uVar4,*(undefined8 *)(lVar1 + 0x178),
               *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 0042d5b2 sec2ctxDestructHal_KERNEL.cold =====

void sec2ctxDestructHal_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0042d5c0 sec2ctxDestructHal_KERNEL =====

void sec2ctxDestructHal_KERNEL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = *(long *)(param_1 + 0x1d8);
  uVar2 = *(undefined8 *)(*(long *)(lVar1 + 0x158) + 0xe0);
  uVar5 = kflcnGetKernelFalconForEngine_IMPL(uVar2,0x28c40800);
  iVar4 = kflcnFreeContext_IMPL
                    (uVar2,uVar5,*(undefined8 *)(lVar1 + 0x178),
                     *(undefined4 *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x11c));
  if (iVar4 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar4,
             "kflcnFreeContext(pGpu, pKernelFalcon, pKernelChannel, RES_GET_EXT_CLASS_ID(pChannelDescendant))"
             ,"src/kernel/gpu/sec2/sec2_context.c",0x37);
  return;
}


// ===== 0042d650 spdmGetRequesterCertificateCount_GB100 =====

undefined8
spdmGetRequesterCertificateCount_GB100(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 3;
    return 0;
  }
  return 0x1f;
}


// ===== 0042d670 spdmGetIndividualCertificate_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
spdmGetIndividualCertificate_GB100
          (undefined8 param_1,long param_2,int param_3,char param_4,long param_5,ulong *param_6)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_6 == (ulong *)0x0) {
    return 0x1f;
  }
  if (param_3 == 1) {
    lVar2 = (**(code **)(param_2 + 0x1f8))(param_2);
  }
  else if (param_3 == 2) {
    lVar2 = (**(code **)(param_2 + 0x200))(param_2);
  }
  else {
    if (param_3 != 0) {
      *param_6 = 0;
      return 0x1f;
    }
    lVar2 = spdmGetBinArchiveL1Certificate_IMPL(param_2);
  }
  if ((lVar2 == 0) || (lVar2 = bindataArchiveGetStorage(lVar2,0x41), lVar2 == 0)) {
    return 0x1f;
  }
  uVar1 = bindataGetBufferSize(lVar2);
  if (param_4 != '\0') {
    uVar3 = (**(code **)(param_2 + 0x210))(param_1,param_2,lVar2,param_5 != 0,param_5,param_6);
    return uVar3;
  }
  if (param_5 != 0) {
    if (*param_6 < (ulong)uVar1) {
      return 2;
    }
    uVar3 = bindataWriteToBuffer(lVar2,param_5,uVar1);
    if ((int)uVar3 != 0) {
      *param_6 = 0;
      return uVar3;
    }
  }
  *param_6 = (ulong)uVar1;
  return 0;
}


// ===== 0042d7e0 spdmConvertCertificateToDer_GH100 =====

int spdmConvertCertificateToDer_GH100
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,char param_4,
              undefined8 param_5,ulong *param_6)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  
  uVar2 = bindataGetBufferSize(param_3);
  if (uVar2 < 0x36) {
    *param_6 = 0;
    iVar3 = 0x25;
    lVar4 = 0;
  }
  else {
    lVar4 = portMemAllocNonPaged(uVar2);
    if (lVar4 == 0) {
      *param_6 = 0;
      iVar3 = 0x51;
    }
    else {
      iVar3 = bindataWriteToBuffer(param_3,lVar4,uVar2);
      if (iVar3 == 0) {
        uVar5 = (((uVar2 - 0x36) - (uVar2 + 10) / 0x41 >> 2) * 3 -
                (uint)(*(char *)(lVar4 + (ulong)(uVar2 - 0x1c)) == '=')) -
                (uint)(*(char *)(lVar4 + (ulong)(uVar2 - 0x1d)) == '=');
        if (param_4 == '\0') {
          *param_6 = (ulong)uVar5;
        }
        else {
          cVar1 = libspdm_pem_to_der(lVar4,param_5,uVar2,param_6);
          if (cVar1 == '\0') {
            *param_6 = 0;
            iVar3 = 0x1f;
          }
          else if (*param_6 != (ulong)uVar5) {
            iVar3 = 0x25;
            nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_certs_gh100.c",0xab,
                         "spdmConvertCertificateToDer_GH100",4,
                         "NVRM: Decoded cert size is different from calculated!\n");
            *param_6 = 0;
          }
        }
      }
      else {
        *param_6 = 0;
      }
    }
  }
  portMemFree(lVar4);
  return iVar3;
}


// ===== 0042d980 spdmGetRequesterCertificateCount_GH100 =====

undefined8
spdmGetRequesterCertificateCount_GH100(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 3;
    return 0;
  }
  return 0x1f;
}


// ===== 0042d9a0 spdmGetIndividualCertificate_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
spdmGetIndividualCertificate_GH100
          (undefined8 param_1,long param_2,int param_3,char param_4,long param_5,ulong *param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (param_6 == (ulong *)0x0) {
    return 0x1f;
  }
  if (param_3 == 1) {
    lVar1 = (**(code **)(param_2 + 0x1f8))(param_2);
  }
  else if (param_3 == 2) {
    lVar1 = (**(code **)(param_2 + 0x200))(param_2);
  }
  else {
    if (param_3 != 0) {
      *param_6 = 0;
      return 0x1f;
    }
    lVar1 = spdmGetBinArchiveL1Certificate_IMPL(param_2);
  }
  if ((lVar1 == 0) || (lVar1 = bindataArchiveGetStorage(lVar1,0x41), lVar1 == 0)) {
    return 0x1f;
  }
  if (param_4 != '\0') {
    uVar3 = (**(code **)(param_2 + 0x210))(param_1,param_2,lVar1,param_5 != 0,param_5,param_6);
    return uVar3;
  }
  uVar2 = bindataGetBufferSize();
  uVar2 = uVar2 & 0xffffffff;
  if (param_5 != 0) {
    if (*param_6 < uVar2) {
      return 2;
    }
    uVar3 = bindataWriteToBuffer(lVar1,param_5,uVar2);
    if ((int)uVar3 != 0) {
      *param_6 = 0;
      return uVar3;
    }
  }
  *param_6 = uVar2;
  return 0;
}


// ===== 0042db10 spdmGetCertificates_GH100 =====

int spdmGetCertificates_GH100(undefined8 param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined1 local_58 [40];
  
  local_60 = 0;
  if ((*(long *)(param_2 + 0x220) != 0) && (*(int *)(param_2 + 0x240) == 0)) {
    local_68 = 0x1000;
    lVar3 = portMemAllocNonPaged(0x1000);
    local_60 = 0x1400;
    lVar4 = portMemAllocNonPaged(0x1400);
    *(undefined8 *)(param_2 + 0x268) = 0x1400;
    lVar5 = portMemAllocNonPaged(0x1400);
    *(long *)(param_2 + 0x260) = lVar5;
    if (((lVar3 == 0) || (lVar4 == 0)) || (lVar5 == 0)) {
      iVar2 = 0x51;
      portMemFree(lVar3);
      portMemFree(lVar4);
    }
    else {
      portMemSet(lVar3,0,local_68);
      portMemSet(lVar4,0,local_60);
      portMemSet(*(undefined8 *)(param_2 + 0x260),0,*(undefined8 *)(param_2 + 0x268));
      uVar1 = libspdm_get_certificate(*(undefined8 *)(param_2 + 0x220),0,0,&local_68,lVar3);
      if (uVar1 >> 0x1c == 8) {
        iVar2 = 0xffff;
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_certs_gh100.c",0x161,
                     "spdmGetCertificates_GH100",4,"NVRM: SPDM failed with status 0x%0x\n",uVar1);
        portMemFree(lVar3);
        portMemFree(lVar4);
      }
      else {
        iVar2 = spdmSetupResponderCertCtx_IMPL(param_1,param_2,lVar3,local_68,local_58,&local_6c);
        if (iVar2 == 0) {
          iVar2 = spdmBuildCertChainDer_IMPL(param_1,param_2,local_58,local_6c,lVar4,&local_60);
          if (iVar2 == 0) {
            iVar2 = spdmBuildCertChainPem_IMPL
                              (param_1,param_2,local_58,local_6c,*(undefined8 *)(param_2 + 0x260),
                               param_2 + 0x268);
            if (iVar2 == 0) {
              portMemFree(lVar3);
              portMemFree(lVar4);
              return 0;
            }
            pcVar7 = "NVRM: spdmBuildCertChainPem() failed !!! \n";
            uVar6 = 0x185;
          }
          else {
            pcVar7 = "NVRM: spdmBuildCertChainDer() failed !!! \n";
            uVar6 = 0x177;
          }
        }
        else {
          pcVar7 = "NVRM: spdmRetrieveResponderCert() failed !!! \n";
          uVar6 = 0x16a;
        }
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_certs_gh100.c",uVar6,
                     "spdmGetCertificates_GH100",4,pcVar7);
        portMemFree(lVar3);
        portMemFree(lVar4);
      }
    }
    nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_certs_gh100.c",0x194,
                 "spdmGetCertificates_GH100",4,
                 "NVRM: SPDM failure most likely due to missing crypto implementation.\n");
    nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_certs_gh100.c",0x195,
                 "spdmGetCertificates_GH100",4,"NVRM: Are the LKCA modules properly loaded?\n");
    portMemFree(*(undefined8 *)(param_2 + 0x260));
    *(undefined8 *)(param_2 + 0x260) = 0;
    *(undefined8 *)(param_2 + 0x268) = 0;
    return iVar2;
  }
  return 0x40;
}


// ===== 0042de30 spdmGetCertChains_GH100 =====

undefined8
spdmGetCertChains_GH100
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,long param_5,
          uint *param_6)

{
  if ((param_5 == 0) || (param_6 == (uint *)0x0)) {
    return 0x1f;
  }
  if (((*(long *)(param_2 + 0x220) != 0) && (*(long *)(param_2 + 0x260) != 0)) &&
     (*(ulong *)(param_2 + 0x268) != 0)) {
    if (*(ulong *)(param_2 + 0x268) <= (ulong)*param_6) {
      portMemCopy(param_5,(ulong)*param_6);
      *param_6 = (uint)*(undefined8 *)(param_2 + 0x268);
      return 0;
    }
    return 2;
  }
  return 0x55;
}


// ===== 0042dec0 spdmGetReqEncapCertificates_GH100 =====

undefined8
spdmGetReqEncapCertificates_GH100
          (undefined8 param_1,undefined8 param_2,long *param_3,undefined4 *param_4)

{
  if ((*param_3 == 0) && (param_4 != (undefined4 *)0x0)) {
    *param_3 = (long)SPDM_REQ_ENCAP_CERTIFICATE_DER;
    *param_4 = 0x242;
    return 0;
  }
  return 0x1f;
}


// ===== 0042def0 _spdmGetSecuredMessageVersionGsp =====

undefined4 _spdmGetSecuredMessageVersionGsp(undefined4 param_1)

{
  return param_1;
}


// ===== 0042df00 _spdmGetSecuredMessageSequenceNumberGsp =====

undefined8 _spdmGetSecuredMessageSequenceNumberGsp(void)

{
  return 0;
}


// ===== 0042df10 _spdmGetSecuredMessageMaxRandomNumberCountGsp =====

undefined8 _spdmGetSecuredMessageMaxRandomNumberCountGsp(void)

{
  return 0;
}


// ===== 0042df20 _spdmReceiveMessageGsp =====

/* WARNING: Type propagation algorithm not settling */

int _spdmReceiveMessageGsp(undefined8 param_1,ulong *param_2,long *param_3)

{
  int iVar1;
  long local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 8;
  if (((param_2 != (ulong *)0x0) && (param_3 != (long *)0x0)) && (*param_3 != 0)) {
    iVar1 = libspdm_get_data(param_1,0x2a,0,local_28,local_28 + 1);
    if (iVar1 == 0) {
      if (local_28[0] == 0) {
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x2be,"_spdmReceiveMessageGsp",4
                     ,"NVRM:  pSpdm  == NULL, SPDM context probably corrupted !! \n ");
        iVar1 = -0x7ffefffd;
      }
      else {
        if ((*(uint *)(local_28[0] + 700) == 0) || (*param_2 < (ulong)*(uint *)(local_28[0] + 700)))
        {
          iVar1 = -0x7ffbffff;
        }
        else {
          portMemCopy(*param_3,*param_2,*(undefined8 *)(local_28[0] + 0x2b0));
          *param_2 = (ulong)*(uint *)(local_28[0] + 700);
          iVar1 = 0;
        }
        *(undefined4 *)(local_28[0] + 700) = 0;
      }
      return iVar1;
    }
    nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x2b8,"_spdmReceiveMessageGsp",4,
                 "NVRM:  spdmStatus != LIBSPDM_STATUS_SUCCESS \n ");
    return iVar1;
  }
  return -0x7ffeffff;
}


// ===== 0042e070 _spdmSendMessageGsp =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int _spdmSendMessageGsp(undefined8 param_1,ulong param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long local_28 [2];
  
  local_28[0] = 0;
  local_28[1] = 8;
  if ((param_2 == 0) || (param_3 == 0)) {
    iVar2 = -0x7ffeffff;
  }
  else {
    iVar2 = libspdm_get_data(param_1,0x2a,0,local_28,local_28 + 1);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x26c,"_spdmSendMessageGsp",4,
                   "NVRM:   spdmStatus != LIBSPDM_STATUS_SUCCESS \n ");
      return iVar2;
    }
    if (local_28[0] == 0) {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x272,"_spdmSendMessageGsp",4,
                   "NVRM:  pSpdm == NULL, SPDM context probably corrupted !! \n ");
    }
    else {
      lVar3 = gpuEngineGetGpu(*(undefined8 *)(local_28[0] + 0x150));
      if (lVar3 != 0) {
        uVar1 = *(uint *)(local_28[0] + 0x2b8);
        if (uVar1 < param_2) {
          *(undefined4 *)(local_28[0] + 700) = 0;
          return -0x7ffefff3;
        }
        *(uint *)(local_28[0] + 700) = uVar1;
        portMemCopy(*(undefined8 *)(local_28[0] + 0x2b0),(ulong)uVar1,param_3,param_2);
        iVar2 = (**(code **)(local_28[0] + 0x1d8))
                          (lVar3,local_28[0],*(undefined8 *)(local_28[0] + 0x2b0),
                           param_2 & 0xffffffff,*(undefined8 *)(local_28[0] + 0x2b0),
                           local_28[0] + 700);
        if (iVar2 != 0) {
          *(undefined4 *)(local_28[0] + 700) = 0;
          return -0x7ffc0000;
        }
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x27a,"_spdmSendMessageGsp",4,
                   "NVRM:  pGpu == NULL, SPDM context probably corrupted !! \n ");
    }
    iVar2 = -0x7ffefffd;
  }
  return iVar2;
}


// ===== 0042e260 _spdmDecodeMessageGsp =====

/* WARNING: Type propagation algorithm not settling */

int _spdmDecodeMessageGsp
              (long param_1,long *param_2,undefined1 *param_3,char param_4,ulong param_5,
              int *param_6,ulong *param_7,long *param_8)

{
  int iVar1;
  long lVar2;
  long local_58 [2];
  undefined4 local_48 [2];
  code *local_40;
  code *local_38;
  code *local_30;
  
  local_58[0] = 0;
  local_58[1] = 8;
  if (((((param_1 == 0) || (param_2 == (long *)0x0)) || (param_3 == (undefined1 *)0x0)) ||
      ((param_5 == 0 || (param_6 == (int *)0x0 || param_7 == (ulong *)0x0)))) ||
     ((param_8 == (long *)0x0 || ((*param_8 == 0 || (param_4 != '\0')))))) {
    iVar1 = -0x7ffeffff;
  }
  else {
    iVar1 = libspdm_get_data(param_1,0x2a,0,local_58,local_58 + 1);
    if (iVar1 == 0) {
      if (local_58[0] != 0) {
        if ((0xb < param_5) && (param_5 <= *(uint *)(local_58[0] + 0x250))) {
          if (param_6[2] == 0x10) {
            if (param_6[1] + 0xc == param_5) {
              iVar1 = *param_6;
              if (iVar1 == 0) {
                *param_2 = 0;
                *param_3 = 0;
                if ((ulong)(uint)param_6[1] <= *param_7) {
                  *param_8 = (long)(param_6 + 3);
                  *param_7 = (ulong)(uint)param_6[1];
                  return 0;
                }
                return -0x7ffefff3;
              }
              if (1 < iVar1 - 1U) {
                return -0x7ffefffb;
              }
              *param_3 = iVar1 == 2;
              if ((uint)param_6[1] < 4) {
                return -0x7ffefffb;
              }
              *param_2 = (long)(param_6 + 3);
              lVar2 = libspdm_get_secured_message_context_via_session_id(param_1,param_6[3]);
              if (lVar2 != 0) {
                portMemSet(local_48,0,0x20);
                local_48[0] = 2;
                local_40 = _spdmGetSecuredMessageSequenceNumberGsp;
                local_38 = _spdmGetSecuredMessageMaxRandomNumberCountGsp;
                local_30 = _spdmGetSecuredMessageVersionGsp;
                iVar1 = libspdm_decode_secured_message
                                  (lVar2,*(undefined4 *)*param_2,0,param_5 - 0xc,param_6 + 3,param_7
                                   ,param_8,local_48);
                return iVar1;
              }
              return -0x7ffefff1;
            }
          }
          else {
            nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x1ed,
                         "_spdmDecodeMessageGsp",4,
                         "NVRM: SPDM: Version mismatch: [Check] version = 0x%x, [SpdmRet] version = 0x%x\n"
                         ,0x10,param_6[2]);
          }
        }
        return -0x7ffefffb;
      }
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x1df,"_spdmDecodeMessageGsp",4,
                   "NVRM:  pSpdm == NULL, SPDM context probably corrupted !! \n ");
      iVar1 = -0x7ffefffd;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x1d9,"_spdmDecodeMessageGsp",4,
                   "NVRM:  spdmStatus != LIBSPDM_STATUS_SUCCESS \n ");
    }
  }
  return iVar1;
}


// ===== 0042e570 _spdmEncodeMessageGsp =====

/* WARNING: Type propagation algorithm not settling */

int _spdmEncodeMessageGsp
              (long param_1,undefined4 *param_2,byte param_3,char param_4,ulong param_5,long param_6
              ,ulong *param_7,long *param_8)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long local_70;
  long local_68 [2];
  undefined4 local_58 [2];
  code *local_50;
  code *local_48;
  code *local_40;
  
  local_70 = 0;
  local_68[0] = 0;
  local_68[1] = 8;
  if (((((param_1 == 0) || (param_6 == 0)) || (param_5 == 0)) ||
      ((param_8 == (long *)0x0 || (*param_8 == 0 || param_7 == (ulong *)0x0)))) ||
     ((param_4 == '\0' || ((param_2 == (undefined4 *)0x0 && (param_3 != 0)))))) {
    return -0x7ffeffff;
  }
  if (*param_7 < param_5 + 0xc) {
    return -0x7ffefffb;
  }
  iVar2 = libspdm_get_data(param_1,0x2a,0,local_68,local_68 + 1);
  if (iVar2 == 0) {
    if (local_68[0] == 0) {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x15a,"_spdmEncodeMessageGsp",4,
                   "NVRM:  pSpdm == NULL, SPDM context probably corrupted !! \n ");
      iVar2 = -0x7ffefffd;
    }
    else {
      piVar1 = (int *)*param_8;
      portMemSet(piVar1,0,0xc);
      piVar1[2] = 0x10;
      if (param_2 == (undefined4 *)0x0) {
        uVar5 = param_5 + 0xc & 0xffffffff;
        if ((*param_7 < uVar5) || (uVar5 < param_5)) {
          return -0x7ffefff3;
        }
        *piVar1 = 0;
        piVar1[1] = (int)param_5;
      }
      else {
        *piVar1 = param_3 + 1;
        lVar4 = libspdm_get_secured_message_context_via_session_id(param_1,*param_2);
        if (lVar4 == 0) {
          return -0x7ffefff1;
        }
        local_70 = *param_7 - 0xc;
        portMemSet(local_58,0,0x20);
        local_58[0] = 2;
        local_50 = _spdmGetSecuredMessageSequenceNumberGsp;
        local_48 = _spdmGetSecuredMessageMaxRandomNumberCountGsp;
        local_40 = _spdmGetSecuredMessageVersionGsp;
        iVar3 = libspdm_encode_secured_message
                          (lVar4,*param_2,1,param_5,param_6,&local_70,piVar1 + 3);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (*param_7 <= local_70 + 0xcU) {
          nvAssertFailedNoLog("*transport_message_size > (securedMessageSize + sizeof(NV_SPDM_DESC_HEADER))"
                              ,"src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x186,local_58);
          return -0x7ffefffb;
        }
        piVar1[1] = (int)local_70;
        uVar5 = local_70 + 0xc;
      }
      *param_7 = uVar5;
      if (*(uint *)(local_68[0] + 0x250) < uVar5) {
        iVar2 = -0x7ffefff3;
      }
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x154,"_spdmEncodeMessageGsp",4,
                 "NVRM: , spdmStatus != LIBSPDM_STATUS_SUCCESS \n ");
  }
  return iVar2;
}


// ===== 0042e8a0 _spdmTriggerHeartbeat =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _spdmTriggerHeartbeat(long param_1,long param_2,long param_3)

{
  long lVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 == 0 || param_2 == 0) {
    iVar2 = 0x1f;
    bVar3 = true;
  }
  else {
    if (param_3 == 0) {
      iVar2 = 0x1f;
      goto LAB_0042e906;
    }
    iVar2 = osQueueWorkItem(param_1,_spdmSendHeartbeat,*(undefined8 *)(param_3 + 8),0x51);
    bVar3 = iVar2 != 0;
  }
  if ((param_1 == 0) || (!bVar3)) {
    return iVar2;
  }
LAB_0042e906:
  lVar1 = *(long *)(param_1 + 0x1d18);
  nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0xfe,"_spdmTriggerHeartbeat",6,
               "NVRM: SPDM: Fatal heartbeat failure detected 0x%x\n");
  (**(code **)(lVar1 + 0x180))(param_1,lVar1);
  return iVar2;
}


// ===== 0042e970 _spdmSendHeartbeat =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _spdmSendHeartbeat(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  bool bVar6;
  
  lVar5 = gpumgrGetGpu();
  if (lVar5 == 0 || param_2 == 0) {
    iVar4 = 0x1f;
    bVar6 = true;
  }
  else {
    if ((*(long *)(param_2 + 0x220) == 0) || (*(int *)(param_2 + 0x240) == 0)) {
      iVar4 = 0x55;
      goto LAB_0042e9f6;
    }
    uVar1 = *(undefined8 *)(lVar5 + 0x1b88);
    iVar4 = (**(code **)(param_2 + 0x188))(lVar5,param_2,2);
    if (iVar4 != 0) goto LAB_0042e9f6;
    uVar3 = libspdm_heartbeat(*(undefined8 *)(param_2 + 0x220),*(undefined4 *)(param_2 + 0x240));
    if (uVar3 >> 0x1c == 8) {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0xbd,"_spdmSendHeartbeat",4,
                   "NVRM: SPDM failed with status 0x%0x\n",uVar3);
      iVar4 = 0xffff;
      goto LAB_0042e9f6;
    }
    iVar4 = tmrEventScheduleRel_IMPL
                      (uVar1,*(undefined8 *)(param_2 + 0x2a0),
                       (ulong)*(uint *)(param_2 + 0x2a8) * 1000000000);
    bVar6 = iVar4 != 0;
  }
  if ((lVar5 == 0) || (!bVar6)) {
    return;
  }
LAB_0042e9f6:
  lVar2 = *(long *)(lVar5 + 0x1d18);
  nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0xcb,"_spdmSendHeartbeat",6,
               "NVRM: SPDM: Fatal heartbeat failure detected 0x%x\n",iVar4);
  (**(code **)(lVar2 + 0x180))(lVar5,lVar2);
  return;
}


// ===== 0042eaf0 spdmDeviceInit_GH100 =====

undefined8 spdmDeviceInit_GH100(long param_1,long param_2)

{
  long lVar1;
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(long *)(param_2 + 0x220) != 0)) {
    *(undefined4 *)(param_2 + 700) = 0;
    lVar1 = portMemAllocNonPaged(*(undefined4 *)(param_2 + 0x250));
    *(long *)(param_2 + 0x2b0) = lVar1;
    if (lVar1 != 0) {
      *(undefined4 *)(param_2 + 0x2b8) = *(undefined4 *)(param_2 + 0x250);
      libspdm_register_transport_layer_func
                (*(undefined8 *)(param_2 + 0x220),0x11f4,0xc,0,_spdmEncodeMessageGsp,
                 _spdmDecodeMessageGsp);
      libspdm_register_device_io_func
                (*(undefined8 *)(param_2 + 0x220),_spdmSendMessageGsp,_spdmReceiveMessageGsp);
      *(bool *)(param_2 + 0x244) = *(char *)(param_1 + 0x909) != '\0';
      return 0;
    }
    *(undefined4 *)(param_2 + 0x2b8) = 0;
    return 0x51;
  }
  return 0x1f;
}


// ===== 0042ebd0 spdmDeviceDeinit_GH100 =====

undefined8 spdmDeviceDeinit_GH100(undefined8 param_1,long param_2)

{
  portMemFree(*(undefined8 *)(param_2 + 0x2b0));
  *(undefined8 *)(param_2 + 0x2b0) = 0;
  *(undefined8 *)(param_2 + 0x2b8) = 0;
  return 0;
}


// ===== 0042ec10 spdmMessageProcess_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmMessageProcess_GH100
              (long param_1,long param_2,long param_3,uint param_4,long param_5,uint *param_6)

{
  uint uVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uStack_140;
  long local_138;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined1 local_f8 [4];
  undefined1 local_f4;
  int local_50;
  
  local_118 = 0;
  local_110 = 0;
  local_108 = 0;
  local_100 = 0;
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0 || param_5 == 0)) ||
     (param_6 == (uint *)0x0)) {
    return 0x1f;
  }
  if (*(uint *)(param_2 + 0x250) < param_4) {
    return 0x1a;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x1b78);
  if (*(char *)(param_2 + 0x244) == '\0') {
    local_118 = *(undefined8 *)(param_2 + 0x248);
    iVar3 = memmgrMemWrite_IMPL(uVar2,&local_118,param_3,param_4,0);
    if (iVar3 != 0) {
      return iVar3;
    }
    portMemSet(local_f8,0,0xc0);
    local_f4 = 3;
    iVar3 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,local_f8);
    if (local_50 != 0) {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x37c,"spdmMessageProcess_GH100",4
                   ,"NVRM: SPDM: RPC failed! RPC status = 0x%x\n");
      return local_50;
    }
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x386,"spdmMessageProcess_GH100",4
                   ,"NVRM: SPDM: Send/receive failed! status = 0x%x\n",iVar3);
      return iVar3;
    }
    local_118 = *(undefined8 *)(param_2 + 0x248);
    lVar4 = portMemAllocNonPaged(*(undefined4 *)(param_2 + 0x250));
    if (lVar4 == 0) {
      return 0x1a;
    }
    uStack_140 = 0x42f0ed;
    iVar3 = memmgrMemRead_IMPL(uVar2,&local_118,lVar4,*(undefined4 *)(param_2 + 0x250),0);
    if (iVar3 != 0) goto LAB_0042efb0;
    local_138 = 0;
  }
  else {
    lVar4 = 0;
    if (*(long *)(param_1 + 0x1ba8) != 0) {
      lVar4 = *(long *)(*(long *)(param_1 + 0x1ba8) + 2000);
    }
    local_138 = memmgrMemDescBeginTransfer_IMPL(uVar2,*(undefined8 *)(param_2 + 0x248),2);
    if (local_138 == 0) {
      return 0x1a;
    }
    portMemCopy(local_138,param_4,param_3,param_4);
    memdescFlushCpuCaches(param_1,*(undefined8 *)(param_2 + 0x248));
    (**(code **)(lVar4 + 0x4c8))(param_1,lVar4,0x40,0xafafafaf);
    iVar3 = (**(code **)(lVar4 + 0x4c0))(param_1,lVar4,0x40);
    timeoutSet(param_1 + 0x1af0,local_f8,0,0);
    while (iVar3 != -0x5050506) {
      iVar3 = timeoutCheck(param_1 + 0x1af0,local_f8,0x35c);
      if (iVar3 == 0x65) {
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x35e,"spdmMessageProcess_GH100"
                     ,4,"NVRM: Timeout waiting for response from SPDM Responder!\n");
        memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_2 + 0x248),2);
        return 0x65;
      }
      iVar3 = (**(code **)(lVar4 + 0x4c0))(param_1,lVar4,0x40);
    }
    local_118 = *(undefined8 *)(param_2 + 0x248);
    lVar4 = portMemAllocNonPaged(*(undefined4 *)(param_2 + 0x250));
    if (lVar4 == 0) {
      memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_2 + 0x248),2);
      return 0x1a;
    }
    uStack_140 = 0x42ef62;
    iVar3 = memmgrMemRead_IMPL(uVar2,&local_118,lVar4,*(undefined4 *)(param_2 + 0x250),0);
    if (iVar3 != 0) {
      memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_2 + 0x248),2);
      goto LAB_0042efb0;
    }
  }
  uVar1 = *(int *)(lVar4 + 4) + 0xc;
  if (*param_6 < uVar1) {
    nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x3a2,"spdmMessageProcess_GH100",4,
                 "NVRM: SPDM: Error: transportResponseSize = 0x%x, responseSize = 0x%x\n",uVar1);
    if (local_138 != 0) {
      memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_2 + 0x248),2,uStack_140);
    }
    iVar3 = 0x1a;
  }
  else {
    portMemCopy(param_5,*param_6,lVar4,uVar1);
    *param_6 = uVar1;
    if (local_138 != 0) {
      memmgrMemDescEndTransfer_IMPL(uVar2,*(undefined8 *)(param_2 + 0x248),2);
    }
    iVar3 = 0;
  }
LAB_0042efb0:
  portMemFree(lVar4);
  return iVar3;
}


// ===== 0042f160 spdmDeviceSecuredSessionSupported_GH100 =====

undefined8 spdmDeviceSecuredSessionSupported_GH100(void)

{
  return 0;
}


// ===== 0042f170 spdmCheckConnection_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 spdmCheckConnection_GH100(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  char local_45;
  int local_44;
  uint local_40;
  int local_3c;
  undefined8 local_38;
  undefined4 local_30 [4];
  
  local_44 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x1f;
  }
  lVar1 = *(long *)(param_2 + 0x220);
  if (lVar1 != 0) {
    local_30[0] = 1;
    local_38 = 4;
    iVar3 = libspdm_get_data(lVar1,0x12,local_30,&local_40,&local_38);
    if ((iVar3 == 0) && (2 < local_40)) {
      cVar2 = libspdm_get_connection_version(lVar1);
      if (cVar2 == '\x12') {
        local_3c = 0;
        local_38 = 4;
        iVar3 = libspdm_get_data(lVar1,0x10,local_30,&local_3c,&local_38);
        if (iVar3 != 0) {
          return 0x40;
        }
        if (local_3c != 2) {
          return 0x40;
        }
      }
      else if (cVar2 != '\x11') {
        return 0x40;
      }
      local_38 = 1;
      iVar3 = libspdm_get_data(lVar1,3,local_30,&local_45,&local_38);
      if ((iVar3 != 0) || (local_45 != '\x1f')) {
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x40c,
                     "spdmCheckConnection_GH100",4,"NVRM: SPDM: Invalid Responder CT exponent.\n");
        return 0x40;
      }
      local_38 = 4;
      iVar3 = libspdm_get_data(lVar1,2,local_30,&local_44,&local_38);
      if ((iVar3 == 0) && (uVar4 = 0, local_44 == 0x73f2)) {
        do {
          iVar3 = (&g_SpdmAlgoCheckTable_GH100)[uVar4 * 2];
          if ((iVar3 != 0xe) ||
             (cVar2 = (**(code **)(param_2 + 0x1a8))(param_1,param_2), cVar2 != '\0')) {
            local_3c = 0;
            local_38 = 4;
            iVar3 = libspdm_get_data(lVar1,iVar3,local_30,&local_3c,&local_38);
            if ((iVar3 != 0) || (*(int *)(&DAT_00d779c4 + uVar4 * 8) != local_3c)) {
              nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x434,
                           "spdmCheckConnection_GH100",4,
                           "NVRM: SPDM: Invalid crypto algorithms selected.\n");
              nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x435,
                           "spdmCheckConnection_GH100",4,
                           "NVRM: SPDM: AlgoCheckCount 0x%0x, i is 0x%0x, status is 0x%0x.\n",8,
                           uVar4,iVar3);
              nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x436,
                           "spdmCheckConnection_GH100",4,
                           "NVRM: SPDM: Expected algo 0x%0x, actual algo 0x%0x\n",
                           *(undefined4 *)(&DAT_00d779c4 + (uVar4 & 0xffffffff) * 8),local_3c);
              return 0x40;
            }
          }
          uVar4 = uVar4 + 1;
          if (uVar4 == 8) {
            return 0;
          }
        } while( true );
      }
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x41c,"spdmCheckConnection_GH100",
                   4,"NVRM: SPDM: Invalid Responder capabilities.\n");
      return 0x40;
    }
  }
  return 0x55;
}


// ===== 0042f4c0 spdmGetAttestationReport_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmGetAttestationReport_GH100
              (long param_1,long param_2,undefined8 param_3,long param_4,uint *param_5,
              undefined1 *param_6)

{
  ulong uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined1 local_45;
  uint local_44;
  ulong local_40 [2];
  
  local_45 = 0;
  local_44 = 0;
  local_40[0] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x1f;
  }
  if ((*(long *)(param_2 + 0x220) == 0) || (*(char *)(param_2 + 0x23c) == '\0')) {
    return 0x55;
  }
  iVar5 = (**(code **)(param_2 + 0x188))(param_1,param_2,1);
  if (iVar5 != 0) {
    return iVar5;
  }
  if ((param_4 != 0) && (param_5 != (uint *)0x0)) {
    libspdm_reset_msg_log(*(undefined8 *)(param_2 + 0x220));
    libspdm_set_msg_log_mode(*(undefined8 *)(param_2 + 0x220),1);
    local_44 = *param_5;
    local_45 = 0x40;
    uVar4 = libspdm_get_measurement_ex
                      (*(undefined8 *)(param_2 + 0x220),param_2 + 0x240,1,0xff,0,0,&local_45,
                       &local_44,param_4,param_3,0,0,0,0);
    if (uVar4 >> 0x1c == 8) {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x475,
                   "spdmGetAttestationReport_GH100",4,"NVRM: SPDM failed with status 0x%0x\n",uVar4)
      ;
LAB_0042f759:
      iVar5 = 0xffff;
      goto LAB_0042f55a;
    }
    cVar2 = nvspdm_check_and_clear_libspdm_assert();
    if (cVar2 == '\0') {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x47e,
                   "spdmGetAttestationReport_GH100",4,
                   "NVRM: SPDM: spdmCheckAndClearLibspdmAssert() failed \n");
      return 0x40;
    }
    bVar3 = libspdm_get_connection_version(*(undefined8 *)(param_2 + 0x220));
    if (0x11 < bVar3) {
      local_40[0] = (ulong)*param_5;
      uVar4 = libspdm_get_data(*(undefined8 *)(param_2 + 0x220),0x2c,0,param_4,local_40);
      if (uVar4 >> 0x1c == 8) {
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x486,
                     "spdmGetAttestationReport_GH100",4,"NVRM: SPDM failed with status 0x%0x\n",
                     uVar4);
        goto LAB_0042f759;
      }
      if (local_40[0] == 0) {
        return 0x40;
      }
    }
    uVar1 = local_40[0];
    uVar4 = *param_5;
    lVar6 = libspdm_get_msg_log_size(*(undefined8 *)(param_2 + 0x220));
    if ((ulong)uVar4 < lVar6 + local_40[0]) {
      return 2;
    }
    uVar7 = libspdm_get_msg_log_size(*(undefined8 *)(param_2 + 0x220));
    portMemCopy(param_4 + uVar1,*param_5,*(undefined8 *)(param_2 + 0x278),uVar7);
    uVar1 = local_40[0];
    iVar5 = libspdm_get_msg_log_size(*(undefined8 *)(param_2 + 0x220));
    *param_5 = iVar5 + (int)uVar1;
  }
  iVar5 = 0;
  if (param_6 != (undefined1 *)0x0) {
    *param_6 = 0;
  }
LAB_0042f55a:
  libspdm_reset_msg_log(*(undefined8 *)(param_2 + 0x220));
  return iVar5;
}


// ===== 0042f7c0 spdmSendInitRmDataCommand_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmSendInitRmDataCommand_GH100(long param_1,long param_2)

{
  int iVar1;
  undefined1 local_f0 [24];
  undefined1 local_d8 [4];
  undefined1 local_d4;
  int local_30;
  
  if (((param_1 != 0) && (param_2 != 0)) && (*(char *)(param_2 + 0x23c) != '\0')) {
    portMemSet(local_d8,0,0xc0);
    local_d4 = 4;
    timeoutSet(param_1 + 0x1af0,local_f0,0,0);
    iVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,local_d8);
    if (iVar1 == 0) {
      iVar1 = local_30;
      if (local_30 != 0) {
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x4cf,
                     "spdmSendInitRmDataCommand_GH100",4,
                     "NVRM: SPDM: RPC returned failure in INIT_RM_DATA command! status = 0x%0x\n",
                     local_30);
      }
    }
    else {
      iVar1 = 0x70;
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x4c7,
                   "spdmSendInitRmDataCommand_GH100",4,
                   "NVRM: SPDM: Send/receive error in INIT_RM_DATA command\n");
    }
    return iVar1;
  }
  return 0x1f;
}


// ===== 0042f8d0 spdmCheckAndExecuteKeyUpdate_GH100 =====

undefined4 spdmCheckAndExecuteKeyUpdate_GH100(long param_1,long param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x1f;
  }
  if ((*(long *)(param_2 + 0x220) != 0) && (*(int *)(param_2 + 0x240) != 0)) {
    if (1 < param_3 - 1U) {
      return 0x1f;
    }
    uVar2 = *(int *)(param_2 + 0x298) + 1;
    *(uint *)(param_2 + 0x298) = uVar2;
    if (0xfffffff < uVar2) {
      uVar3 = libspdm_key_update(*(long *)(param_2 + 0x220),*(int *)(param_2 + 0x240),0);
      if ((int)uVar3 == 0) {
        cVar1 = nvspdm_check_and_clear_libspdm_assert();
        if (cVar1 == '\0') {
          nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x50c,
                       "spdmCheckAndExecuteKeyUpdate_GH100",4,
                       "NVRM: SPDM: spdmCheckAndExecuteKeyUpdate() assert !! \n",param_3);
          uVar4 = 0x40;
        }
        else {
          nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x511,
                       "spdmCheckAndExecuteKeyUpdate_GH100",1,
                       "NVRM: SPDM: Key update successfully, triggerId = (0x%x)!\n",param_3);
          *(undefined4 *)(param_2 + 0x298) = 0;
          uVar4 = 0;
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x504,
                     "spdmCheckAndExecuteKeyUpdate_GH100",4,
                     "NVRM: Key Update (single direction(0x%x)) failed, ret(0x%x), triggerId = (0x%x).\n"
                     ,0,uVar3,param_3);
        uVar4 = 0xffff;
      }
      return uVar4;
    }
    return 0;
  }
  return 0x55;
}


// ===== 0042fa20 spdmRegisterForHeartbeats_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmRegisterForHeartbeats_GH100(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 local_f0 [24];
  undefined1 local_d8 [4];
  undefined2 local_d4;
  int local_30;
  
  if (((param_1 == 0) || (param_2 == 0)) || (*(int *)(param_2 + 0x240) == 0)) {
    iVar2 = 0x55;
  }
  else {
    iVar2 = 0x1f;
    if (3 < param_3) {
      uVar1 = *(undefined8 *)(param_1 + 0x1b88);
      iVar2 = tmrEventCreate_IMPL(uVar1,param_2 + 0x2a0,_spdmTriggerHeartbeat,param_2,8);
      if (iVar2 == 0) {
        *(uint *)(param_2 + 0x2a8) = param_3;
        tmrEventScheduleRel_IMPL(uVar1,*(undefined8 *)(param_2 + 0x2a0),(ulong)param_3 * 1000000000)
        ;
        portMemSet(local_d8,0,0xc0);
        local_d4 = 0x105;
        timeoutSet(param_1 + 0x1af0,local_f0,0,0);
        iVar2 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,local_d8);
        if (iVar2 == 0) {
          iVar2 = local_30;
          if (local_30 != 0) {
            nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x553,
                         "spdmRegisterForHeartbeats_GH100",4,
                         "NVRM: SPDM: RPC returned failure in CC_HEARTBEAT_CTRL command! status = 0x%0x\n"
                        );
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x54b,
                       "spdmRegisterForHeartbeats_GH100",4,
                       "NVRM: SPDM: Send/receive error in CC_HEARTBEAT_CTRL command! Status = 0x%0x\n"
                       ,iVar2);
        }
      }
      return iVar2;
    }
  }
  return iVar2;
}


// ===== 0042fbd0 spdmUnregisterFromHeartbeats_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmUnregisterFromHeartbeats_GH100(long param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined1 local_100 [24];
  undefined1 local_e8 [4];
  undefined2 local_e4;
  int local_40;
  
  iVar2 = 0;
  if (*(long *)(param_2 + 0x2a0) != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x1b88);
    portMemSet(local_e8,0,0xc0);
    local_e4 = 5;
    timeoutSet(param_1 + 0x1af0,local_100,0,0);
    iVar2 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,local_e8);
    if (iVar2 == 0) {
      iVar2 = local_40;
      if (local_40 != 0) {
        nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x580,
                     "spdmUnregisterFromHeartbeats_GH100",4,
                     "NVRM: SPDM: RPC returned failure in CC_HEARTBEAT_CTRL command! status = 0x%0x\n"
                     ,local_40);
      }
    }
    else {
      nvDbg_Printf("src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x578,
                   "spdmUnregisterFromHeartbeats_GH100",4,
                   "NVRM: SPDM: Send/receive error in CC_HEARTBEAT_CTRL command! Status = 0x%0x\n",
                   iVar2);
    }
    tmrEventDestroy_IMPL(uVar1,*(undefined8 *)(param_2 + 0x2a0));
    *(undefined8 *)(param_2 + 0x2a0) = 0;
    *(undefined4 *)(param_2 + 0x2a8) = 0;
  }
  return iVar2;
}


// ===== 0042fd00 spdmSendCtrlCall_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 spdmSendCtrlCall_GH100(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x908) != '\0') {
    return 0x56;
  }
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    cVar1 = rmGpuLockIsOwner();
    if (cVar1 != '\0') {
      uVar2 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ad9,param_3,0xc0);
      return uVar2;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/spdm/arch/hopper/spdm_gh100.c",0x5ab);
  return 0x2f;
}


// ===== 0042fd90 spdmConstructEngine_IMPL =====

undefined8 spdmConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x220) = 0;
  *(undefined8 *)(param_2 + 0x230) = 0;
  *(undefined8 *)(param_2 + 0x260) = 0;
  *(undefined8 *)(param_2 + 0x270) = 0;
  *(undefined8 *)(param_2 + 0x278) = 0;
  *(undefined8 *)(param_2 + 0x288) = 0;
  *(undefined4 *)(param_2 + 0x228) = 0;
  *(undefined4 *)(param_2 + 0x238) = 0;
  *(undefined8 *)(param_2 + 0x268) = 0;
  *(undefined8 *)(param_2 + 0x280) = 0;
  *(undefined4 *)(param_2 + 0x290) = 0;
  *(undefined4 *)(param_2 + 0x240) = 0;
  *(undefined1 *)(param_2 + 0x23c) = 0;
  *(undefined1 *)(param_2 + 0x244) = 0;
  *(undefined1 *)(param_2 + 0x294) = 0;
  *(undefined8 *)(param_2 + 0x248) = 0;
  *(undefined4 *)(param_2 + 0x250) = 0;
  *(undefined8 *)(param_2 + 0x2a0) = 0;
  *(undefined4 *)(param_2 + 0x2a8) = 0;
  *(undefined4 *)(param_2 + 0x2c0) = 0;
  return 0;
}


// ===== 0042fe60 spdmStatePostLoad_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong spdmStatePostLoad_KERNEL
                (long param_1,long param_2,char *param_3,char *param_4,undefined8 param_5)

{
  ulong uVar1;
  
  if (*(char *)(param_2 + 0x218) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvDbg_Printf("src/kernel/gpu/spdm/kernel_spdm.c",0x5c,"spdmStatePostLoad_KERNEL",1,
                 "NVRM: Performing late SPDM initialization!\n");
    uVar1 = spdmEstablishSession_IMPL(param_1,param_2,1);
    param_5 = 0x5d;
    param_4 = "src/kernel/gpu/spdm/kernel_spdm.c";
    param_3 = "spdmEstablishSession(pGpu, pSpdm, NV_SPDM_REQUESTER_ID_MONOLITHIC)";
    if ((int)uVar1 != 0) goto LAB_0042ff12;
  }
  uVar1 = (**(code **)(param_2 + 400))(param_1,param_2,param_3,param_4,param_5);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  param_5 = 0x61;
  param_3 = "spdmSendInitRmDataCommand_HAL(pGpu, pSpdm)";
LAB_0042ff12:
  nvCheckOkFailedNoLog(4,uVar1 & 0xffffffff,param_3,"src/kernel/gpu/spdm/kernel_spdm.c",param_5);
  return uVar1 & 0xffffffff;
}


// ===== 0042ff50 spdmStatePreUnload_KERNEL =====

undefined8 spdmStatePreUnload_KERNEL(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_2 + 0x218) != '\0')) {
    uVar1 = spdmContextDeinit_IMPL(param_1,param_2,1);
    return uVar1;
  }
  return 0;
}


// ===== 0042ff80 spdmDestruct_IMPL =====

void spdmDestruct_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar2 = gpuEngineGetGpu(uVar3);
  if ((*(char *)(lVar2 + 0x909) != '\0') && (*(char *)(param_1 + 0x218) != '\0')) {
    iVar1 = spdmContextDeinit_IMPL(lVar2,param_1,1);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/spdm/kernel_spdm.c",0x92,"spdmDestruct_IMPL",4,
                   "NVRM: Failed deinitializing SPDM: 0x%x!\n",iVar1);
      return;
    }
  }
  return;
}


// ===== 00430010 _spdmVerifyCertChain =====

undefined8 _spdmVerifyCertChain(void)

{
  return 1;
}


// ===== 00430020 _spdmReleaseTransportBuffer =====

void _spdmReleaseTransportBuffer(undefined8 param_1,undefined8 param_2)

{
  portMemFree(param_2);
  return;
}


// ===== 00430030 _spdmClearContext =====

void _spdmClearContext(long param_1)

{
  if (param_1 != 0) {
    if (*(long *)(param_1 + 0x220) != 0) {
      libspdm_deinit_context();
      libspdm_reset_context(*(undefined8 *)(param_1 + 0x220));
      portMemSet(*(undefined8 *)(param_1 + 0x220),0,*(undefined4 *)(param_1 + 0x228));
    }
    if (*(long *)(param_1 + 0x230) != 0) {
      portMemSet(*(long *)(param_1 + 0x230),0,*(undefined4 *)(param_1 + 0x238));
    }
    memdescFree(*(undefined8 *)(param_1 + 0x248));
    memdescDestroy(*(undefined8 *)(param_1 + 0x248));
    *(undefined8 *)(param_1 + 0x248) = 0;
    *(undefined4 *)(param_1 + 0x250) = 0;
    portMemFree(*(undefined8 *)(param_1 + 0x220));
    portMemFree(*(undefined8 *)(param_1 + 0x230));
    portMemFree(*(undefined8 *)(param_1 + 0x260));
    portMemFree(*(undefined8 *)(param_1 + 0x270));
    portMemFree(*(undefined8 *)(param_1 + 0x278));
    portMemFree(*(undefined8 *)(param_1 + 0x288));
    *(undefined1 *)(param_1 + 0x23c) = 0;
    *(undefined8 *)(param_1 + 0x220) = 0;
    *(undefined8 *)(param_1 + 0x230) = 0;
    *(undefined8 *)(param_1 + 0x260) = 0;
    *(undefined8 *)(param_1 + 0x270) = 0;
    *(undefined8 *)(param_1 + 0x278) = 0;
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined4 *)(param_1 + 0x228) = 0;
    *(undefined4 *)(param_1 + 0x238) = 0;
    *(undefined8 *)(param_1 + 0x268) = 0;
    *(undefined8 *)(param_1 + 0x280) = 0;
    *(undefined4 *)(param_1 + 0x290) = 0;
    *(undefined4 *)(param_1 + 0x240) = 0;
    *(undefined1 *)(param_1 + 0x244) = 0;
    return;
  }
  return;
}


// ===== 004301b0 _spdmAcquireTransportBuffer =====

uint _spdmAcquireTransportBuffer(long param_1,long *param_2)

{
  long lVar1;
  
  if ((param_1 != 0) && (param_2 != (long *)0x0)) {
    lVar1 = portMemAllocNonPaged(0x1200);
    *param_2 = lVar1;
    return -(uint)(lVar1 == 0) & 0x8001000c;
  }
  return 0x80010001;
}


// ===== 00430200 spdmStart_IMPL.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmStart_IMPL_part_0(undefined8 param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  char local_29 [9];
  
  nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x260,"spdmStart_IMPL",1,
               "NVRM: SPDM: Starting new SPDM connection.\n");
  uVar2 = libspdm_init_connection(*(undefined8 *)(param_2 + 0x220),0);
  if (uVar2 >> 0x1c == 8) {
    nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x261,"spdmStart_IMPL",4,
                 "NVRM: SPDM failed with status 0x%0x\n",uVar2);
  }
  else {
    cVar1 = nvspdm_check_and_clear_libspdm_assert();
    if (cVar1 == '\0') {
      nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x265,"spdmStart_IMPL",4,
                   "NVRM: SPDM: libspdm_init_connection() assert hit !!!.\n");
    }
    else {
      iVar3 = (**(code **)(param_2 + 0x1d0))(param_1,param_2);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x26e,"spdmStart_IMPL",4,
                     "NVRM: SPDM: Connection attributes did not match expected!\n");
        goto LAB_0043039f;
      }
      iVar3 = (**(code **)(param_2 + 0x1e0))(param_1,param_2);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x276,"spdmStart_IMPL",4,
                     "NVRM: SPDM: Certificate retrieval failed!\n");
        goto LAB_0043039f;
      }
      cVar1 = nvspdm_check_and_clear_libspdm_assert();
      if (cVar1 == '\0') {
        nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x27c,"spdmStart_IMPL",4,
                     "NVRM: SPDM: spdmGetCertificates_HAL() assert hit !!!.\n");
      }
      else {
        iVar3 = (**(code **)(param_2 + 0x1c8))(param_1,param_2);
        if (iVar3 != 0) {
LAB_0043044b:
          uVar2 = libspdm_get_msg_log_size(*(undefined8 *)(param_2 + 0x220));
          *(uint *)(param_2 + 0x290) = uVar2;
          if ((*(ulong *)(param_2 + 0x280) < (ulong)uVar2) ||
             (uVar4 = libspdm_get_msg_log_size(*(undefined8 *)(param_2 + 0x220)), uVar2 < uVar4)) {
            *(undefined4 *)(param_2 + 0x290) = 0;
            iVar3 = 0x40;
          }
          else {
            lVar5 = portMemAllocNonPaged(*(undefined4 *)(param_2 + 0x290));
            *(long *)(param_2 + 0x288) = lVar5;
            if (lVar5 != 0) {
              portMemCopy(lVar5,*(undefined4 *)(param_2 + 0x290),*(undefined8 *)(param_2 + 0x278),
                          *(undefined4 *)(param_2 + 0x290));
              libspdm_reset_msg_log(*(undefined8 *)(param_2 + 0x220));
              return 0;
            }
            *(undefined4 *)(param_2 + 0x290) = 0;
            iVar3 = 0x51;
          }
          goto LAB_0043039f;
        }
        local_29[0] = '\0';
        nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x289,"spdmStart_IMPL",1,
                     "NVRM: SPDM: Attempting to establish SPDM session.\n");
        uVar2 = libspdm_start_session
                          (*(undefined8 *)(param_2 + 0x220),0,0,0,0,0,0,param_2 + 0x240,local_29,0);
        if (uVar2 >> 0x1c == 8) {
          nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x28a,"spdmStart_IMPL",4,
                       "NVRM: SPDM failed with status 0x%0x\n",uVar2);
        }
        else {
          cVar1 = nvspdm_check_and_clear_libspdm_assert();
          if (cVar1 != '\0') {
            if (local_29[0] != '\x04') {
              iVar3 = 0x56;
              nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x29a,"spdmStart_IMPL",4,
                           "NVRM: SPDM: Responder returned unexpected heartbeat 0x%x\n");
              goto LAB_0043039f;
            }
            nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x2a0,"spdmStart_IMPL",1,
                         "NVRM: SPDM: Session establishment successful: sessionId 0x%x.\n",
                         *(undefined4 *)(param_2 + 0x240));
            *(undefined1 *)(param_2 + 0x23c) = 1;
            *(undefined1 *)(param_2 + 0x244) = 0;
            goto LAB_0043044b;
          }
          nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x290,"spdmStart_IMPL",4,
                       "NVRM: SPDM: libspdm_start_session() assert hit !!!.\n");
        }
      }
    }
  }
  iVar3 = 0xffff;
LAB_0043039f:
  *(undefined1 *)(param_2 + 0x23c) = 0;
  *(undefined4 *)(param_2 + 0x240) = 0;
  nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x2c8,"spdmStart_IMPL",4,
               "NVRM: SPDM: Session establishment failed!\n");
  return iVar3;
}


// ===== 004305f0 spdmSetupCommunicationBuffers_IMPL =====

ulong spdmSetupCommunicationBuffers_IMPL(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  local_38 = 0;
  local_30 = 0;
  local_28 = 0;
  local_20 = 0;
  iVar1 = memdescCreate(param_2 + 0x248,param_1,0x2000,0x100,1,1);
  if ((iVar1 == 0) && (*(long *)(param_2 + 0x248) != 0)) {
    *(undefined4 *)(*(long *)(param_2 + 0x248) + 0x9c) = 0x73;
    uVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0x248));
    if ((int)uVar2 == 0) {
      local_38 = *(undefined8 *)(param_2 + 0x248);
      *(undefined4 *)(param_2 + 0x250) = 0x1200;
      local_30 = 0;
      uVar2 = memmgrMemSet_IMPL(*(undefined8 *)(param_1 + 0x1b78),&local_38,0,0x1200,0);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
  }
  else {
    uVar2 = 0x1a;
  }
  _spdmClearContext(param_2);
  return uVar2 & 0xffffffff;
}


// ===== 004306f0 spdmContextInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int spdmContextInit_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  long local_50;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  uint local_3c [5];
  long local_28;
  undefined4 local_20;
  undefined1 local_1c;
  
  local_28 = 0;
  if ((param_2 == 0) || (param_1 == 0)) {
    return 0x1f;
  }
  local_50 = param_2;
  cVar2 = libspdm_check_crypto_backend();
  if (cVar2 == '\0') {
    nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x15b,"spdmContextInit_IMPL",4,
                 "NVRM: SPDM cannot boot without proper crypto backend!\n");
    return 0x40;
  }
  uVar3 = libspdm_get_context_size();
  lVar1 = local_50;
  *(undefined4 *)(local_50 + 0x228) = uVar3;
  uVar6 = portMemAllocNonPaged(uVar3);
  *(undefined8 *)(lVar1 + 0x220) = uVar6;
  if ((*(int *)(local_50 + 0x228) == 0) || (*(long *)(local_50 + 0x220) == 0)) {
LAB_00430cb0:
    iVar4 = 0x51;
  }
  else {
    portMemSet(*(long *)(local_50 + 0x220),0);
    libspdm_init_context(*(undefined8 *)(local_50 + 0x220));
    lVar1 = local_50;
    uVar6 = portMemAllocNonPaged(0x23e8);
    *(undefined8 *)(lVar1 + 0x278) = uVar6;
    *(undefined8 *)(local_50 + 0x280) = 0x23e8;
    if (*(long *)(local_50 + 0x278) == 0) {
      *(undefined8 *)(local_50 + 0x280) = 0;
      iVar4 = 0x51;
      goto LAB_00430cb6;
    }
    cVar2 = (**(code **)(local_50 + 0x1a8))(param_1,local_50);
    if (cVar2 != '\0') {
      local_3c[4] = 0;
      iVar4 = (**(code **)(local_50 + 0x1e8))(param_1,local_50,&local_28,local_3c + 4);
      if (((iVar4 != 0) || (local_28 == 0)) || (local_3c[4] == 0)) {
        iVar4 = 0x56;
        goto LAB_00430cb6;
      }
    }
    portMemSet(&local_20,0,8);
    local_20 = 0;
    local_47 = 0x1f;
    uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),3,&local_20,&local_47,1);
    if (uVar5 >> 0x1c == 8) {
      uVar6 = 0x18d;
    }
    else {
      local_3c[0] = 0x72c2;
      cVar2 = (**(code **)(local_50 + 0x1a8))(param_1);
      if (cVar2 != '\0') {
        local_3c[0] = local_3c[0] | 0x100;
      }
      uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),2,&local_20,local_3c,4);
      if (uVar5 >> 0x1c == 8) {
        uVar6 = 0x19d;
      }
      else {
        local_46 = 1;
        uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),8,&local_20,&local_46,1);
        if (uVar5 >> 0x1c == 8) {
          uVar6 = 0x1a2;
        }
        else {
          local_3c[1] = 0x80;
          uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),10,&local_20,local_3c + 1,4);
          if (uVar5 >> 0x1c == 8) {
            uVar6 = 0x1a7;
          }
          else {
            local_3c[2] = 2;
            uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0xb,&local_20,local_3c + 2,4)
            ;
            if (uVar5 >> 0x1c == 8) {
              uVar6 = 0x1ac;
            }
            else {
              local_44 = 0x10;
              uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0xc,&local_20,&local_44,2);
              if (uVar5 >> 0x1c == 8) {
                uVar6 = 0x1b1;
              }
              else {
                local_42 = 2;
                uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0xd,&local_20,&local_42,2
                                        );
                if (uVar5 >> 0x1c == 8) {
                  uVar6 = 0x1b5;
                }
                else {
                  local_40 = 1;
                  uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0xf,&local_20,&local_40
                                           ,2);
                  if (uVar5 >> 0x1c == 8) {
                    uVar6 = 0x1b9;
                  }
                  else {
                    cVar2 = (**(code **)(local_50 + 0x1a8))(param_1);
                    if (cVar2 == '\0') {
LAB_00430a9b:
                      local_3c[3] = 1;
                      uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0x30,&local_20,
                                               local_3c + 3,4);
                      if (uVar5 >> 0x1c == 8) {
                        uVar6 = 0x1cf;
                      }
                      else {
                        local_3c[3] = 0;
                        uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0x31,&local_20,
                                                 local_3c + 3,4);
                        if (uVar5 >> 0x1c == 8) {
                          uVar6 = 0x1d3;
                        }
                        else {
                          local_45 = 0;
                          uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0x2e,&local_20,
                                                   &local_45,1);
                          if (uVar5 >> 0x1c == 8) {
                            uVar6 = 0x1d9;
                          }
                          else {
                            libspdm_init_msg_log
                                      (*(undefined8 *)(local_50 + 0x220),
                                       *(undefined8 *)(local_50 + 0x278),
                                       *(undefined8 *)(local_50 + 0x280));
                            libspdm_set_msg_log_mode(*(undefined8 *)(local_50 + 0x220),1);
                            uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0x2a,0,
                                                     &local_50,8);
                            if (uVar5 >> 0x1c != 8) {
                              iVar4 = (**(code **)(local_50 + 0x1b8))(param_1);
                              if (iVar4 != 0) goto LAB_00430cb6;
                              libspdm_register_device_buffer_func
                                        (*(undefined8 *)(local_50 + 0x220),0x1200,0x1200,
                                         _spdmAcquireTransportBuffer,_spdmReleaseTransportBuffer);
                              uVar3 = libspdm_get_sizeof_required_scratch_buffer
                                                (*(undefined8 *)(local_50 + 0x220));
                              lVar1 = local_50;
                              *(undefined4 *)(local_50 + 0x238) = uVar3;
                              uVar6 = portMemAllocNonPaged(uVar3);
                              *(undefined8 *)(lVar1 + 0x230) = uVar6;
                              if ((*(int *)(local_50 + 0x238) != 0) &&
                                 (*(long *)(local_50 + 0x230) != 0)) {
                                portMemSet(*(long *)(local_50 + 0x230),0,*(int *)(local_50 + 0x238))
                                ;
                                libspdm_set_scratch_buffer
                                          (*(undefined8 *)(local_50 + 0x220),
                                           *(undefined8 *)(local_50 + 0x230),
                                           *(undefined4 *)(local_50 + 0x238));
                                libspdm_register_verify_spdm_cert_chain_func
                                          (*(undefined8 *)(local_50 + 0x220),_spdmVerifyCertChain);
                                *(undefined4 *)(local_50 + 0x298) = 0;
                                cVar2 = libspdm_check_context(*(undefined8 *)(local_50 + 0x220));
                                if (cVar2 != '\0') {
                                  return 0;
                                }
                                nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x210,
                                             "spdmContextInit_IMPL",4,
                                             "NVRM: Failed libspdm context selftest!\n");
                                iVar4 = 0x40;
                                goto LAB_00430cb6;
                              }
                              goto LAB_00430cb0;
                            }
                            uVar6 = 0x1e0;
                          }
                        }
                      }
                    }
                    else {
                      local_3e = 8;
                      uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0xe,&local_20,
                                               &local_3e,2);
                      if (uVar5 >> 0x1c == 8) {
                        uVar6 = 0x1bf;
                      }
                      else {
                        local_1c = 0;
                        uVar5 = libspdm_set_data(*(undefined8 *)(local_50 + 0x220),0x14,&local_20,
                                                 local_28,local_3c[4]);
                        if (uVar5 >> 0x1c != 8) goto LAB_00430a9b;
                        uVar6 = 0x1c8;
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
    nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",uVar6,"spdmContextInit_IMPL",4,
                 "NVRM: SPDM failed with status 0x%0x\n",uVar5);
    iVar4 = 0xffff;
  }
LAB_00430cb6:
  _spdmClearContext(local_50);
  return iVar4;
}


// ===== 00430f60 spdmContextDeinit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int spdmContextDeinit_IMPL(long param_1,long param_2)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if (*(long *)(param_2 + 0x220) == 0) {
      iVar1 = 0;
      _spdmClearContext(param_2);
    }
    else {
      iVar1 = (**(code **)(param_2 + 0x1a0))();
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog(iVar1,"status","src/kernel/gpu/spdm/spdm.c",0x23b);
      }
      nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x241,"spdmContextDeinit_IMPL",1,
                   "NVRM: SPDM: Tearing down session.\n");
      iVar1 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,1);
      _spdmClearContext(param_2);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog(iVar1,"status","src/kernel/gpu/spdm/spdm.c",0x248);
      }
    }
    return iVar1;
  }
  return 0x1f;
}


// ===== 00431090 spdmRetrieveExportSecret_IMPL =====

undefined8 spdmRetrieveExportSecret_IMPL(long param_1,long param_2,uint param_3,long param_4)

{
  char cVar1;
  long lVar2;
  ulong local_30 [2];
  
  local_30[0] = 0;
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) && (param_4 != 0)) {
    if (((*(long *)(param_2 + 0x220) != 0) && (*(char *)(param_2 + 0x23c) != '\0')) &&
       (*(char *)(param_2 + 0x294) == '\0')) {
      lVar2 = libspdm_get_secured_message_context_via_session_id
                        (*(long *)(param_2 + 0x220),*(undefined4 *)(param_2 + 0x240));
      if (lVar2 != 0) {
        local_30[0] = (ulong)param_3;
        cVar1 = libspdm_secured_message_export_master_secret(lVar2,param_4,local_30);
        if (cVar1 != '\0') {
          libspdm_secured_message_clear_export_master_secret(lVar2);
          *(undefined1 *)(param_2 + 0x294) = 1;
          return 0;
        }
      }
      return 0x40;
    }
    return 0x55;
  }
  return 0x1f;
}


// ===== 00431190 spdmSendApplicationMessage_IMPL =====

uint spdmSendApplicationMessage_IMPL
               (undefined8 param_1,long param_2,long param_3,uint param_4,long param_5,uint *param_6
               )

{
  uint uVar1;
  ulong local_20 [2];
  
  if ((((param_3 != 0) && (param_5 != 0)) && (param_6 != (uint *)0x0)) &&
     ((3 < param_4 && (local_20[0] = (ulong)*param_6, 3 < *param_6)))) {
    uVar1 = libspdm_send_receive_data
                      (*(undefined8 *)(param_2 + 0x220),param_2 + 0x240,1,param_3,param_4,param_5,
                       local_20);
    if (uVar1 >> 0x1c == 8) {
      nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x324,"spdmSendApplicationMessage_IMPL",4,
                   "NVRM: SPDM failed with status 0x%0x\n",uVar1);
      uVar1 = 0xffff;
    }
    else {
      *param_6 = (uint)local_20[0];
      uVar1 = -(uint)((local_20[0] & 0xffffffff) < local_20[0]) & 0x5b;
    }
    return uVar1;
  }
  return 0x3b;
}


// ===== 00431240 subdeviceSpdmRetrieveTranscript_IMPL =====

undefined8 subdeviceSpdmRetrieveTranscript_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1d10);
  if (lVar1 == 0) {
    nvCheckFailedNoLog(4,"pSpdm != NULL","src/kernel/gpu/spdm/spdm.c",0x342);
  }
  else if (*(long *)(lVar1 + 0x288) != 0) {
    if (*(uint *)(lVar1 + 0x290) != 0) {
      uVar2 = 2;
      if (*(uint *)(lVar1 + 0x290) < 0x2401) {
        portMemCopy(param_2,0x2400);
        *(undefined4 *)(param_2 + 0x2400) = *(undefined4 *)(lVar1 + 0x290);
        uVar2 = 0;
      }
      return uVar2;
    }
  }
  return 0x40;
}


// ===== 00431300 spdmSetupResponderCertCtx_IMPL =====

undefined8
spdmSetupResponderCertCtx_IMPL
          (long param_1,long param_2,long param_3,long param_4,ulong *param_5,int *param_6)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0 || param_5 == (ulong *)0x0)) ||
     (param_6 == (int *)0x0)) {
    return 0x1f;
  }
  pbVar1 = (byte *)(param_3 + -1 + param_4);
  uVar4 = libspdm_get_hash_size();
  iVar9 = 0;
  pbVar8 = (byte *)(param_3 + 4 + (ulong)uVar4);
  do {
    if (pbVar1 <= pbVar8) {
      uVar6 = 0x1f;
      if (pbVar1 == pbVar8 + -1) {
        *param_6 = iVar9;
        uVar6 = 0;
      }
      return uVar6;
    }
    if (pbVar1 <= pbVar8 + 4) {
      nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0xcf,"_calcX509CertSize",4,
                   "NVRM:  %s: pCert + DER_CERT_SIZE_FIELD_LENGTH(0x%x) is not valid value !! \n",
                   "_calcX509CertSize",4);
      return 0x25;
    }
    bVar3 = pbVar8[1];
    uVar5 = (ulong)bVar3;
    if ((char)bVar3 < '\0') {
      bVar3 = bVar3 & 0x3f;
      pbVar10 = pbVar8 + (byte)(bVar3 + 2);
      if (pbVar1 < pbVar10) {
        return 0x25;
      }
      pbVar7 = pbVar8 + 3;
      uVar4 = (uint)pbVar8[2];
      if (pbVar7 < pbVar10) {
        do {
          bVar2 = *pbVar7;
          pbVar7 = pbVar7 + 1;
          uVar4 = uVar4 * 0x100 + (uint)bVar2;
        } while (pbVar10 != pbVar7);
        uVar4 = bVar3 + 2 + uVar4;
        uVar5 = (ulong)uVar4;
        goto joined_r0x00431460;
      }
      uVar4 = bVar3 + 2 + uVar4;
      uVar5 = (ulong)uVar4;
      if (pbVar1 < pbVar8 + (uVar4 - 1)) goto LAB_00431470;
    }
    else {
      uVar4 = (uint)bVar3;
joined_r0x00431460:
      if ((pbVar1 < pbVar8 + (uVar4 - 1)) || ((int)uVar5 == 1)) {
LAB_00431470:
        nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0xfb,"_calcX509CertSize",4,
                     "NVRM:  %s: pCert + (certSize(0x%x) - 1) is not a valid value !! \n",
                     "_calcX509CertSize",uVar5);
        return 0x25;
      }
    }
    iVar9 = iVar9 + 1;
    param_5[1] = (ulong)pbVar8;
    *param_5 = uVar5;
    if (iVar9 == 3) {
      return 2;
    }
    pbVar8 = pbVar8 + uVar5;
    param_5 = param_5 + 2;
  } while( true );
}


// ===== 00431510 spdmBuildCertChainDer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
spdmBuildCertChainDer_IMPL
          (long param_1,long param_2,long *param_3,uint param_4,long param_5,ulong *param_6)

{
  long lVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  long *plVar9;
  long *plVar10;
  bool bVar11;
  int local_44;
  ulong local_40 [2];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x1f;
  }
  if ((param_3 != (long *)0x0 && param_5 != 0) && (param_6 != (ulong *)0x0)) {
    uVar5 = 0;
    if (param_4 != 0) {
      uVar4 = *param_6;
      iVar8 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,&local_44);
      if (iVar8 == 0) {
        lVar6 = 0;
        iVar8 = local_44 + -1;
        bVar11 = local_44 != 0;
        lVar7 = param_5;
        local_44 = iVar8;
        if (bVar11) {
          iVar8 = 0;
          do {
            local_40[0] = uVar4;
            iVar3 = (**(code **)(param_2 + 0x208))(param_1,param_2,iVar8,1,lVar7,local_40);
            if ((iVar3 != 0) || (uVar4 < local_40[0])) {
              nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x3f5,"spdmBuildCertChainDer_IMPL",4,
                           "NVRM: spdmGetIndividualCertificate() failed !!! \n");
              return 2;
            }
            uVar4 = uVar4 - local_40[0];
            lVar7 = lVar7 + local_40[0];
            lVar6 = lVar6 + local_40[0];
            iVar8 = iVar8 + 1;
            bVar11 = local_44 != 0;
            local_44 = local_44 + -1;
          } while (bVar11);
          local_44 = -1;
        }
        plVar9 = param_3;
        do {
          plVar10 = plVar9 + 2;
          portMemCopy(lVar7,uVar4,plVar9[1],*plVar9);
          lVar1 = *plVar9;
          lVar7 = lVar7 + lVar1;
          uVar4 = uVar4 - lVar1;
          lVar6 = lVar6 + lVar1;
          plVar9 = plVar10;
        } while (param_3 + (ulong)param_4 * 2 != plVar10);
        (**(code **)(param_2 + 0x208))(param_1,param_2,0,1,0,local_40);
        cVar2 = libspdm_x509_verify_cert_chain
                          (param_5,local_40[0],param_5 + local_40[0],lVar6 - local_40[0]);
        if (cVar2 == '\0') {
          nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x412,"spdmBuildCertChainDer_IMPL",4,
                       "NVRM: libspdm_x509_verify_cert_chain() failed !!! \n");
          uVar5 = 0x25;
        }
        else {
          uVar5 = 0;
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x3df,"spdmBuildCertChainDer_IMPL",4,
                     "NVRM: spdmGetRequesterCertificateCount failed !!! \n");
        uVar5 = 0x56;
      }
    }
    return uVar5;
  }
  return 0x1f;
}


// ===== 004317c0 spdmBuildCertChainPem_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong spdmBuildCertChainPem_IMPL
                (long param_1,long param_2,long param_3,uint param_4,long param_5,ulong *param_6)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  uint local_44;
  ulong local_40 [2];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x1f;
  }
  if ((param_3 != 0 && param_5 != 0) && (param_6 != (ulong *)0x0)) {
    uVar4 = 0;
    if (param_4 != 0) {
      uVar6 = 0;
      uVar5 = *param_6;
      do {
        param_4 = param_4 - 1;
        puVar3 = (undefined8 *)((ulong)param_4 * 0x10 + param_3);
        local_40[0] = uVar5;
        cVar1 = libspdm_der_to_pem(puVar3[1],param_5,*puVar3,local_40);
        if (cVar1 == '\0') {
          nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x463,"spdmBuildCertChainPem_IMPL",4,
                       "NVRM: libspdm_der_to_pem() failed \n");
          return 0x25;
        }
        local_40[0] = local_40[0] - 1;
        uVar5 = uVar5 - local_40[0];
        param_5 = param_5 + local_40[0];
        uVar6 = uVar6 + local_40[0];
      } while (param_4 != 0);
      uVar4 = (**(code **)(param_2 + 0x1f0))(param_1,param_2,&local_44);
      if ((int)uVar4 == 0) {
        if (local_44 != 0) {
          iVar7 = 2;
          do {
            local_40[0] = uVar5;
            iVar2 = (**(code **)(param_2 + 0x208))(param_1,param_2,iVar7,0,param_5,local_40);
            if ((iVar2 != 0) || (uVar5 < local_40[0])) {
              nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x484,"spdmBuildCertChainPem_IMPL",4,
                           "NVRM: spdmGetIndividualCertificate_HAL() failed \n");
              return 0x25;
            }
            uVar5 = uVar5 - local_40[0];
            param_5 = param_5 + local_40[0];
            uVar6 = uVar6 + local_40[0];
            iVar7 = iVar7 + -1;
          } while (2U - iVar7 < local_44);
          uVar4 = uVar4 & 0xffffffff;
        }
        *param_6 = uVar6;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x477,"spdmBuildCertChainPem_IMPL",4,
                     "NVRM: spdmGetRequesterCertificateCount_HAL() failed \n");
        uVar4 = 0x56;
      }
    }
    return uVar4;
  }
  return 0x1f;
}


// ===== 00431a10 spdmEstablishSession_IMPL =====

ulong spdmEstablishSession_IMPL(long param_1,long param_2,int param_3)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (1 < param_3 - 1U) {
    nvDbg_Printf("src/kernel/gpu/spdm/spdm.c",0x4a7,"spdmCheckRequesterIdValid_IMPL",4,
                 "NVRM: Error, invalid NV SPDM requester id(0x%x) !!!!\n",param_3);
    nvCheckFailedNoLog(4,"status == NV_OK","src/kernel/gpu/spdm/spdm.c",0x4c2);
    return 0x56;
  }
  uVar1 = spdmContextInit_IMPL();
  if (uVar1 == 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      uVar2 = 0x1f;
    }
    else if (*(long *)(param_2 + 0x220) == 0) {
      uVar2 = 0x55;
    }
    else {
      uVar2 = spdmStart_IMPL_part_0(param_1,param_2);
      if ((int)uVar2 == 0) {
        *(int *)(param_2 + 0x2c0) = param_3;
        return uVar2;
      }
    }
    uVar1 = (uint)uVar2;
    uVar3 = 0x4cc;
  }
  else {
    uVar3 = 0x4c9;
  }
  nvCheckFailedNoLog(4,"status == NV_OK","src/kernel/gpu/spdm/spdm.c",uVar3);
  return (ulong)uVar1;
}


// ===== 00431b40 genapiConstruct_IMPL =====

undefined8 genapiConstruct_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  undefined8 local_20;
  
  cVar1 = gpuIsClassSupported_IMPL
                    (*(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0),
                     *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x11c));
  uVar2 = 0x22;
  if (cVar1 != '\0') {
    clientRefIter(&local_b8,*(undefined8 *)(param_2 + 8),
                  *(undefined8 *)(*(long *)(param_2 + 0x10) + 0x18),0x4bc329,0,1);
    local_60 = local_b8;
    local_58 = local_b0;
    local_50 = local_a8;
    local_48 = local_a0;
    local_40 = local_98;
    local_38 = local_90;
    local_30 = local_88;
    local_28 = local_80;
    local_20 = local_78;
    do {
      cVar1 = clientRefIterNext(*(undefined8 *)(param_2 + 8),&local_60);
      if (cVar1 == '\0') {
        return 0;
      }
    } while ((*(int *)(local_28 + 0x11c) != *(int *)(*(long *)(param_2 + 0x10) + 0x11c)) ||
            (local_28 == *(long *)(param_2 + 0x10)));
    uVar2 = 99;
  }
  return uVar2;
}


// ===== 00431c50 genapiDestruct_IMPL =====

void genapiDestruct_IMPL(void)

{
  return;
}


// ===== 00431c60 genapiControl_IMPL =====

undefined8 genapiControl_IMPL(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  if ((*(int *)(*(long *)(*(long *)(param_1 + 0x110) + 0x48) + 0x11c) == 0x90e7) &&
     (*(char *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x909) == '\0')) {
    return 0x56;
  }
  uVar2 = gpuresControl_IMPL(*(long *)(param_1 + 0x128));
  return uVar2;
}


// ===== 00431cc0 genapiMap_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int genapiMap_IMPL(long param_1,undefined8 param_2,long param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint local_2c [3];
  
  if (*(int *)(*(long *)(*(long *)(param_1 + 0x110) + 0x48) + 0x11c) != 0x90e6) {
    return 0x22;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  iVar3 = (**(code **)(lVar2 + 0x200))(lVar2,3,local_2c);
  if (iVar3 == 0) {
    uVar1 = *(uint *)(*(long *)(param_4 + 0x50) + 0x20);
    local_2c[0] = local_2c[0] & 0xfffff000;
    if (1 < uVar1) {
      pcVar5 = "";
      if ((uVar1 & 2) != 0) {
        pcVar5 = "Write ";
      }
      nvDbg_Printf("src/kernel/gpu/subdevice/generic_engine.c",0x8e,"genapiMap_IMPL",4,
                   "NVRM: %s%saccess not allowed on class 0x%x\n",&DAT_00d7816c,pcVar5,
                   *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x110) + 0x48) + 0x11c));
      return 0x5f;
    }
    iVar3 = rmapiMapGpuCommon(*(long *)(param_1 + 0x110),param_2,param_4,lVar2,local_2c[0],0x1000);
    uVar4 = osGetCurrentProcess();
    *(undefined4 *)(param_4 + 0x48) = uVar4;
    if (*(undefined8 **)(param_3 + 0x20) != (undefined8 *)0x0) {
      **(undefined8 **)(param_3 + 0x20) = *(undefined8 *)(param_4 + 0x18);
    }
  }
  return iVar3;
}


// ===== 00431e10 genapiGetMapAddrSpace_IMPL =====

undefined8 genapiGetMapAddrSpace_IMPL(void)

{
  undefined4 *in_RCX;
  
  if (in_RCX != (undefined4 *)0x0) {
    *in_RCX = 3;
  }
  return 0;
}


// ===== 00431e30 subdevicePreDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdevicePreDestruct_IMPL(long param_1)

{
  long lVar1;
  
  if (*(char *)(param_1 + 0x6b6) != '\0') {
    lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    (**(code **)(lVar1 + 0x3b90))
              (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),*(undefined4 *)(lVar1 + 0x3b3c),
               0x20800a7b,0,0);
    return;
  }
  return;
}


// ===== 00431e79 subdeviceDestruct_IMPL.cold =====

void subdeviceDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00431e90 subdeviceDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void subdeviceDestruct_IMPL(long param_1)

{
  int *piVar1;
  char cVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  bool bVar12;
  long local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  uVar11 = 0;
  piVar1 = (int *)(param_1 + 0x350);
  plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar4 = *plVar3;
  lVar5 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  gpuUnregisterSubdevice_IMPL(lVar5,param_1);
  while( true ) {
    iVar8 = *piVar1;
    do {
      iVar7 = iVar8;
      LOCK();
      iVar8 = *piVar1;
      bVar12 = iVar7 == iVar8;
      if (bVar12) {
        *piVar1 = iVar7;
        iVar8 = iVar7;
      }
      UNLOCK();
    } while (!bVar12);
    if (iVar7 == 0) break;
    if (uVar11 < 1000) {
      iVar8 = 100;
      do {
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
    else {
      osDelayUs(10);
    }
    uVar11 = uVar11 + 1;
  }
  if (*(long *)(lVar5 + 0x3b48) == param_1) {
    *(undefined8 *)(lVar5 + 0x3b48) = 0;
  }
  if (*(char *)(param_1 + 0x6b5) != '\0') {
    osClientGcoffDisallowRefcount(*(undefined8 *)(lVar5 + 0x4e0),0);
  }
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x140),local_40,0);
  if ((*(int *)(param_1 + 0x380) != 0) || (*(long *)(param_1 + 0x6b8) != 0)) {
    tmrEventDestroy_IMPL(*(undefined8 *)(lVar5 + 0x1b88));
    *(undefined8 *)(param_1 + 0x6b8) = 0;
    *(undefined4 *)(param_1 + 0x380) = 0;
  }
  lVar10 = *(long *)(local_40[0] + 8);
  lVar9 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((*(char *)(param_1 + 0x340) != '\0') && (*(long *)(local_40[0] + 0x10) != 0)) {
    refcntReleaseReferences_IMPL
              (*(undefined8 *)(*(long *)(lVar9 + 0x1b88) + 0x24f0),
               CONCAT44(*(undefined4 *)(lVar10 + 0x48),
                        *(undefined4 *)(*(long *)(local_40[0] + 0x10) + 0x10)),1);
    *(undefined1 *)(param_1 + 0x340) = 0;
    lVar10 = *(long *)(local_40[0] + 8);
    lVar9 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  }
  if (*(int *)(lVar9 + 0x1b24) == *(int *)(lVar10 + 0x48)) {
    *(undefined4 *)(lVar9 + 0x1b24) = 0;
    lVar9 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  }
  if (*(char *)(param_1 + 0x698) != '\0') {
    *(undefined1 *)(lVar9 + 0x1b28) = 0;
    lVar9 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  }
  if (*(long *)(lVar9 + 0x1c18) == 0) {
    nvCheckFailedNoLog(1,"pKernelRc != NULL","src/kernel/gpu/subdevice/subdevice.c",0x1c8);
  }
  else {
    krcWatchdogChangeState_IMPL(*(long *)(lVar9 + 0x1c18),0,param_1,0xd);
  }
  if (((*(char *)(lVar5 + 0x908) != '\0') || (*(char *)(lVar5 + 0x909) != '\0')) ||
     (*(char *)(lVar5 + 0x90a) != '\0')) {
    lVar10 = gpuGetRpc(lVar5);
    if (lVar10 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice.c",0xf4);
    }
    else {
      if ((*(char *)(lVar5 + 0x909) == '\0') && (*(char *)(lVar5 + 0x90a) == '\0')) {
        (**(code **)(lVar10 + 0xf0))
                  (lVar5,lVar10,*(undefined4 *)(lVar4 + 0x48),*(undefined4 *)(plVar3[3] + 0x10),
                   (int)plVar3[2],*(code **)(lVar10 + 0xf0));
        cVar2 = *(char *)(param_1 + 0x6b4);
        goto joined_r0x0043211c;
      }
      (**(code **)(lVar5 + 0x3b70))(lVar5 + 0x3b58,*(undefined4 *)(lVar4 + 0x48),(int)plVar3[2]);
    }
  }
  cVar2 = *(char *)(param_1 + 0x6b4);
joined_r0x0043211c:
  if (cVar2 != '\0') {
    gpuGetKernelFifoShared_IMPL(lVar5);
    *(undefined1 *)(param_1 + 0x6b4) = 0;
    return;
  }
  return;
}


// ===== 004321b0 subdeviceInternalControlForward_IMPL =====

void subdeviceInternalControlForward_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x158);
  }
  gpuresInternalControlForward_IMPL(uVar1);
  return;
}


// ===== 004321d0 subdeviceGetByHandle_IMPL =====

int subdeviceGetByHandle_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long local_20;
  
  *param_3 = 0;
  iVar1 = clientGetResourceRef_IMPL(param_1,param_2,&local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_Subdevice);
    *param_3 = lVar2;
    if (lVar2 == 0) {
      iVar1 = 0x33;
    }
  }
  return iVar1;
}


// ===== 00432230 subdeviceGetByDeviceAndGpu_IMPL =====

undefined8
subdeviceGetByDeviceAndGpu_IMPL(undefined8 param_1,long param_2,long param_3,long *param_4)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  undefined8 local_30;
  
  *param_4 = 0;
  uVar3 = 0;
  if (param_2 != 0) {
    uVar3 = *(undefined8 *)(*(long *)(param_2 + 0x110) + 0x48);
  }
  clientRefIter(&local_c8,param_1,uVar3,0x4b01b3,param_2 == 0,1);
  local_70 = local_c8;
  local_68 = local_c0;
  local_60 = local_b8;
  local_58 = local_b0;
  local_50 = local_a8;
  local_48 = local_a0;
  local_40 = local_98;
  local_38 = local_90;
  local_30 = local_88;
  do {
    cVar1 = clientRefIterNext(param_1,&local_70);
    if (cVar1 == '\0') {
      return 0x57;
    }
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_Subdevice);
  } while (*(long *)(*(long *)(lVar2 + 0x158) + 0xe0) != param_3);
  *param_4 = lVar2;
  return 0;
}


// ===== 00432360 subdeviceGetByInstance_IMPL =====

undefined8
subdeviceGetByInstance_IMPL(undefined8 param_1,undefined8 param_2,int param_3,long *param_4)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  undefined8 local_30;
  
  uVar4 = 0x1f;
  *param_4 = 0;
  iVar2 = clientGetResourceRefByType_IMPL(param_1,param_2,&DAT_00e0ac20,&local_78);
  if (iVar2 == 0) {
    uVar4 = 0;
    clientRefIter(&local_c8,param_1,local_78,0x4b01b3,0,1);
    local_70 = local_c8;
    local_68 = local_c0;
    local_60 = local_b8;
    local_58 = local_b0;
    local_50 = local_a8;
    local_48 = local_a0;
    local_40 = local_98;
    local_38 = local_90;
    local_30 = local_88;
    do {
      cVar1 = clientRefIterNext(param_1,&local_70);
      if (cVar1 == '\0') {
        return 0x57;
      }
      lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_38 + 8),__nvoc_class_def_Subdevice);
    } while ((lVar3 == 0) || (*(int *)(lVar3 + 0x334) != param_3));
    *param_4 = lVar3;
  }
  return uVar4;
}


// ===== 004324a0 subdeviceConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong subdeviceConstruct_IMPL(long param_1,long param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  ulong uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 extraout_RDX;
  ulong uVar13;
  undefined1 auVar14 [16];
  long local_50;
  long local_48;
  undefined1 local_40 [16];
  
  uVar13 = 0;
  lVar2 = *(long *)(param_2 + 8);
  lVar3 = *(long *)(param_2 + 0x10);
  lVar11 = *(long *)(param_1 + 0x158);
  lVar4 = *(long *)(lVar3 + 0x18);
  lVar5 = *(long *)(lVar11 + 0xe8);
  if (*(uint **)(param_3 + 0x40) != (uint *)0x0) {
    uVar13 = (ulong)**(uint **)(param_3 + 0x40);
  }
  cVar6 = gpumgrIsSubDeviceInstanceValid(uVar13);
  if (cVar6 != '\0') {
    uVar8 = gpuGetByRef(*(undefined8 *)(lVar3 + 0x18),0,&local_50);
    if ((int)uVar8 == 0) {
      iVar7 = gpugrpGetGpuFromSubDeviceInstance_IMPL
                        (*(undefined8 *)(*(long *)(lVar5 + 0x128) + 0xd8),uVar13,&local_48);
      if (iVar7 != 0) {
        return 0x22;
      }
      iVar7 = subdeviceGetByInstance_IMPL
                        (lVar2,*(undefined4 *)(*(long *)(*(long *)(lVar5 + 0x110) + 0x48) + 0x10),
                         uVar13,local_40);
      uVar8 = 0x1a;
      if (iVar7 != 0) {
        gpuresSetGpu_IMPL(lVar11,local_48,0);
        *(long *)(param_1 + 0x338) = lVar5;
        uVar1 = *(uint *)(lVar5 + 0x180);
        *(undefined1 *)(param_1 + 0x6b6) = 0;
        *(undefined4 *)(param_1 + 0x354) = 0;
        *(ulong *)(param_1 + 0x330) = (ulong)uVar1 | uVar13 << 0x20;
        puVar9 = (undefined4 *)(param_1 + 0x358);
        do {
          *puVar9 = 0;
          puVar10 = puVar9 + 2;
          puVar9[1] = 0;
          puVar9 = puVar10;
        } while ((undefined4 *)(param_1 + 0x670) != puVar10);
        *(undefined4 *)(param_1 + 0x670) = 0;
        *(undefined4 *)(param_1 + 0x680) = 0;
        if ((*(long *)(local_50 + 0x1c18) != 0) &&
           (cVar6 = krcTestAllowAlloc_IMPL(local_50,*(long *)(local_50 + 0x1c18),4), cVar6 == '\0'))
        {
          return 0xffff;
        }
        uVar8 = gpuRegisterSubdevice_IMPL(local_48,param_1);
        if ((int)uVar8 == 0) {
          if (((*(char *)(local_48 + 0x908) != '\0') || (*(char *)(local_48 + 0x909) != '\0')) ||
             (*(char *)(local_48 + 0x90a) != '\0')) {
            lVar11 = gpuGetRpc(local_50);
            if (lVar11 == 0) {
              nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice.c",0x7b);
              auVar14._8_8_ = extraout_RDX;
              auVar14._0_8_ = 0x1a;
            }
            else {
              if ((*(char *)(local_50 + 0x909) == '\0') && (*(char *)(local_50 + 0x90a) == '\0')) {
                uVar12 = (**(code **)(lVar11 + 0xe0))
                                   (local_50,lVar11,*(undefined4 *)(lVar2 + 0x48),
                                    *(undefined4 *)(lVar4 + 0x10),*(undefined4 *)(lVar3 + 0x10),
                                    0x2080);
                auVar14._8_8_ = uVar13;
                auVar14._0_8_ = uVar12;
              }
              else {
                auVar14 = (**(code **)(local_50 + 0x3b60))();
              }
              if (auVar14._0_4_ == 0) {
                return auVar14._0_8_;
              }
            }
            gpuUnregisterSubdevice_IMPL(local_48,param_1,auVar14._8_8_);
            uVar8 = auVar14._0_8_ & 0xffffffff;
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar8 & 0xffffffff,"gpuRegisterSubdevice(pGpu, pSubdevice)",
                     "src/kernel/gpu/subdevice/subdevice.c",0x77);
          uVar8 = uVar8 & 0xffffffff;
        }
      }
    }
    return uVar8;
  }
  return 0x22;
}


// ===== 00432760 subdeviceCtrlCmdEventSetTrigger_IMPL =====

undefined8 subdeviceCtrlCmdEventSetTrigger_IMPL(long param_1)

{
  gpuNotifySubDeviceEvent_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),0,0,0,0,0);
  return 0;
}


// ===== 00432790 subdeviceCtrlCmdEventSetTriggerFifo_IMPL =====

undefined8 subdeviceCtrlCmdEventSetTriggerFifo_IMPL(long param_1,undefined4 *param_2)

{
  engineNonStallIntrNotifyEvent(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),0x32,*param_2);
  return 0;
}


// ===== 004327c0 subdeviceCtrlCmdEventSetNotification_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdEventSetNotification_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  long lVar5;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = inotifyGetNotificationList_IMPL(*(undefined8 *)(param_1 + 0x160));
  if (lVar5 == 0) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x5c,
                 "subdeviceCtrlCmdEventSetNotification_IMPL",1,"NVRM: cmd 0x%x: no event list\n",
                 0x20800301);
    return 0x40;
  }
  if (*param_2 < 199) {
    if (*param_2 == 0xb) {
      nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x68,
                   "subdeviceCtrlCmdEventSetNotification_IMPL",1,
                   "NVRM: wrong control call for timer event\n");
      return 0x1f;
    }
    if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
      uVar1 = param_2[1];
    }
    else {
      plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      iVar4 = (**(code **)(lVar2 + 0x3b90))
                        (lVar2 + 0x3b58,*(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2],0x20800301,
                         param_2,0x14);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (3,iVar4,
                   "pRmApi->Control(pRmApi, RES_GET_CLIENT_HANDLE(pSubdevice), RES_GET_HANDLE(pSubdevice), NV2080_CTRL_CMD_EVENT_SET_NOTIFICATION, pSetEventParams, sizeof *pSetEventParams)"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x70);
        return iVar4;
      }
      uVar1 = param_2[1];
    }
    if (uVar1 == 0) {
      *(undefined4 *)(param_1 + 0x354 + (ulong)*param_2 * 4) = 0;
      return 0;
    }
    if (uVar1 - 1 < 2) {
      if (*(int *)(param_1 + 0x354 + (ulong)*param_2 * 4) != 0) {
        return 0x40;
      }
      *(uint *)(param_1 + 4 + ((ulong)*param_2 + 0xd4) * 4) = uVar1;
      return 0;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x62,
                 "subdeviceCtrlCmdEventSetNotification_IMPL",1,"NVRM: bad event 0x%x\n");
  }
  return 0x1f;
}


// ===== 004329ab subdeviceCtrlCmdEventSetMemoryNotifies_IMPL.cold =====

void subdeviceCtrlCmdEventSetMemoryNotifies_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004329c0 subdeviceCtrlCmdEventSetMemoryNotifies_IMPL =====

undefined8 subdeviceCtrlCmdEventSetMemoryNotifies_IMPL(long param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  undefined8 uVar4;
  long local_10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (*(int *)(param_1 + 0x670) != 0) {
    piVar3 = (int *)(param_1 + 0x354);
    do {
      if (*piVar3 != 0) {
        return 99;
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != (int *)(param_1 + 0x670));
  }
  if (*param_2 == 0) {
    *(undefined4 *)(param_1 + 0x670) = 0;
    *(undefined8 *)(param_1 + 0x678) = 0;
    return 0;
  }
  uVar4 = memGetByHandle_IMPL(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),*param_2,
                              &local_10);
  if ((int)uVar4 == 0) {
    if (*(ulong *)(*(long *)(local_10 + 0x118) + 0x30) < 0xc70) {
      return 0x2e;
    }
    iVar1 = *param_2;
    *(long *)(param_1 + 0x678) = local_10;
    *(int *)(param_1 + 0x670) = iVar1;
  }
  return uVar4;
}


// ===== 00432a8b subdeviceCtrlCmdEventSetSemaphoreMemory_IMPL.cold =====

void subdeviceCtrlCmdEventSetSemaphoreMemory_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00432aa0 subdeviceCtrlCmdEventSetSemaphoreMemory_IMPL =====

undefined8 subdeviceCtrlCmdEventSetSemaphoreMemory_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int *piVar3;
  undefined8 uVar4;
  long local_10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  if (*(int *)(param_1 + 0x680) != 0) {
    piVar3 = (int *)(param_1 + 0x354);
    do {
      if (*piVar3 != 0) {
        return 99;
      }
      piVar3 = piVar3 + 1;
    } while (piVar3 != (int *)(param_1 + 0x670));
  }
  uVar4 = memGetByHandle_IMPL(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),*param_2,
                              &local_10);
  if ((int)uVar4 == 0) {
    if (*(ulong *)(*(long *)(local_10 + 0x118) + 0x30) <= (ulong)(uint)param_2[1]) {
      return 0x1f;
    }
    *(undefined4 *)(param_1 + 0x680) = *param_2;
    uVar1 = param_2[1];
    *(undefined4 *)(local_10 + 0x1b8) = 0;
    *(undefined4 *)(local_10 + 0x1bc) = uVar1;
    *(undefined8 *)(local_10 + 0x1d0) = 0;
    *(undefined4 *)(local_10 + 0x1d8) = 0;
    *(undefined8 *)(local_10 + 0x1c8) = 0;
    *(undefined1 *)(local_10 + 0x1c0) = 1;
  }
  return uVar4;
}


// ===== 00432b87 subdeviceCtrlCmdEventSetSemaMemValidation_IMPL.cold =====

void subdeviceCtrlCmdEventSetSemaMemValidation_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00432ba0 subdeviceCtrlCmdEventSetSemaMemValidation_IMPL =====

int subdeviceCtrlCmdEventSetSemaMemValidation_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long local_20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  iVar2 = memGetByHandle_IMPL(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),*param_2,
                              &local_20);
  if (iVar2 != 0) {
    return iVar2;
  }
  lVar3 = memdescGetKernelMapping(*(undefined8 *)(local_20 + 0x118));
  if (lVar3 != 0) {
    portMemSet(lVar3,0,0x1000);
    *(undefined4 *)(local_20 + 0x1b8) = 0;
    *(undefined1 *)(local_20 + 0x1c0) = *(undefined1 *)(param_2 + 1);
    return 0;
  }
  return 0x1e;
}


// ===== 00432c48 subdeviceCtrlCmdEventVideoBindEvtbuf_IMPL.cold =====

void subdeviceCtrlCmdEventVideoBindEvtbuf_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00432c60 subdeviceCtrlCmdEventVideoBindEvtbuf_IMPL =====

ulong subdeviceCtrlCmdEventVideoBindEvtbuf_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  char cVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = *plVar2;
  lVar6 = plVar2[2];
  local_40[0] = 0;
  uVar1 = *(undefined4 *)(*plVar2 + 0x48);
  cVar7 = rmapiLockIsOwner();
  if (cVar7 != '\0') {
    cVar7 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar3 + 0x7a4));
    if (cVar7 != '\0') {
      uVar8 = serverutilGetResourceRefWithType(uVar1,*param_2,0x63502b,local_40);
      if (uVar8 == 0) {
        uVar9 = videoAddBindpoint(lVar3,lVar4,local_40[0],(int)lVar6,*(undefined1 *)(param_2 + 4),
                                  param_2[2],param_2[3]);
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar8,
                   "serverutilGetResourceRefWithType(hClient, pParams->hEventBuffer, classId(EventBuffer), &pEventBufferRef)"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x11d);
        uVar9 = (ulong)uVar8;
      }
      return uVar9;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x11a);
  return 0x2f;
}


// ===== 00432d6a subdeviceCtrlCmdEventGspTraceRatsBindEvtbuf_IMPL.cold =====

void subdeviceCtrlCmdEventGspTraceRatsBindEvtbuf_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00432d80 subdeviceCtrlCmdEventGspTraceRatsBindEvtbuf_IMPL =====

ulong subdeviceCtrlCmdEventGspTraceRatsBindEvtbuf_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long *plVar2;
  undefined8 uVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  char cVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 local_40 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = *plVar2;
  lVar6 = plVar2[2];
  local_40[0] = 0;
  uVar1 = *(undefined4 *)(*plVar2 + 0x48);
  cVar7 = rmapiLockIsOwner();
  if (cVar7 != '\0') {
    cVar7 = rmGpuLockIsOwner();
    if (cVar7 != '\0') {
      uVar8 = serverutilGetResourceRefWithType(uVar1,*param_2,0x63502b,local_40);
      if (uVar8 == 0) {
        uVar9 = gspTraceAddBindpoint
                          (uVar3,lVar4,local_40[0],(int)lVar6,*(undefined8 *)(param_2 + 2),
                           param_2[4],param_2[5]);
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar8,
                   "serverutilGetResourceRefWithType(hClient, pParams->hEventBuffer, classId(EventBuffer), &pEventBufferRef)"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x13e);
        uVar9 = (ulong)uVar8;
      }
      return uVar9;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_event_kernel.c",0x13c);
  return 0x2f;
}


// ===== 00432e90 subdeviceCtrlCmdFlaRange_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdFlaRange_IMPL(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  undefined8 extraout_RDX;
  char *pcVar11;
  undefined8 uVar12;
  char *pcVar13;
  int local_3c [3];
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = *(long *)(&DAT_00001b90 + lVar3);
  lVar9 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar9 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0xb7);
    return 0x23;
  }
  lVar10 = resservGetTlsCallContext();
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0xbb)
    ;
    return 0x40;
  }
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') || (cVar6 = rmGpuLockIsOwner(), cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0xbd);
    return 0x2f;
  }
  cVar6 = rmclientIsCapableOrAdmin_IMPL(lVar9,0x200,*(undefined4 *)(lVar10 + 0x28));
  if (cVar6 == '\0') {
    return 0x1b;
  }
  if (*(char *)(lVar4 + 0xa860) == '\0') {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",200,"subdeviceCtrlCmdFlaRange_IMPL"
                 ,1,"NVRM: FLA is not supported in this platform\n");
LAB_00433116:
    iVar8 = 0x56;
  }
  else {
    uVar7 = *(uint *)(param_2 + 2);
    if ((uVar7 != 0) && ((uVar7 - 1 & uVar7) == 0)) {
      if (*(long *)(lVar3 + 0x1bc0) != 0) {
        cVar6 = kmigmgrIsMIGNvlinkP2PSupported_IMPL(lVar3);
        if (cVar6 == '\0') {
          nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0xd9,
                       "subdeviceCtrlCmdFlaRange_IMPL",1,
                       "NVRM: ERROR: FLA cannot be enabled with peer support disabled with MIG\n");
          goto LAB_00433116;
        }
        uVar7 = *(uint *)(param_2 + 2);
      }
      if (uVar7 != 4) {
        if (uVar7 < 5) {
          if (uVar7 != 1) {
            if (uVar7 == 2) {
              return 0;
            }
            return 0x38;
          }
          lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
          if (*(char *)(lVar3 + 0x908) == '\0') {
            if (param_2[1] == 0) goto LAB_00432ff0;
            lVar4 = *(long *)(&DAT_00001b90 + lVar3);
            if (*(char *)(lVar4 + 0xa830) != '\0') {
              cVar6 = (**(code **)(lVar4 + 0x3a8))(lVar3,lVar4,*param_2);
              if (cVar6 != '\0') {
                return 0;
              }
              return 0x17;
            }
            if (*(long *)(lVar3 + 0x1ce8) != 0) {
              iVar8 = knvlinkSetUniqueFlaBaseAddress_IMPL(lVar3,*(long *)(lVar3 + 0x1ce8),*param_2);
              if (iVar8 != 0) {
                nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0x97,
                             "_subdeviceFlaRangeModeInit",4,
                             "NVRM: Failed to set FLA range because of invalid config for gpu: %x\n"
                             ,*(undefined4 *)(lVar3 + 0x7a4));
                return iVar8;
              }
              iVar8 = (**(code **)(lVar4 + 0x370))(lVar3,lVar4,*param_2,param_2[1]);
              if (iVar8 == 0) {
                return 0;
              }
              uVar2 = *(undefined4 *)(lVar3 + 0x7a4);
              pcVar13 = "NVRM: Allocating new FLA Vaspace failed, status: %x, gpu: %x \n";
              pcVar11 = "_subdeviceFlaRangeModeInit";
              uVar12 = 0xa0;
              goto LAB_0043327c;
            }
          }
        }
        else {
          if (uVar7 != 8) {
            return 0x38;
          }
          lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
          iVar8 = vgpuGetCallingContextGfid(lVar3,local_3c);
          if (iVar8 != 0) {
            uVar12 = 0x2e;
            goto LAB_00433378;
          }
          if (((*(long *)(lVar3 + 0x1ce8) == 0) || (local_3c[0] != 0)) ||
             (cVar6 = knvlinkIsGpuConnectedToNvswitch_IMPL(lVar3), cVar6 != '\0')) {
            (**(code **)(*(long *)(&DAT_00001b90 + lVar3) + 0x3a0))
                      (lVar3,*(long *)(&DAT_00001b90 + lVar3),local_3c[0]);
            return 0;
          }
        }
        goto LAB_00433116;
      }
      lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
      plVar5 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      lVar4 = *(long *)(&DAT_00001b90 + lVar3);
      lVar9 = plVar5[2];
      uVar2 = *(undefined4 *)(plVar5[3] + 0x10);
      uVar1 = *(undefined4 *)(*plVar5 + 0x48);
      iVar8 = vgpuGetCallingContextGfid(lVar3,local_3c);
      uVar12 = 0x4a;
      if (iVar8 != 0) {
LAB_00433378:
        nvAssertOkFailedNoLog
                  (iVar8,"vgpuGetCallingContextGfid(pGpu, &gfid)",
                   "src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",uVar12);
        return iVar8;
      }
      if (((local_3c[0] == 0) && (*(long *)(lVar3 + 0x1ce8) != 0)) &&
         (cVar6 = knvlinkIsGpuConnectedToNvswitch_IMPL
                            (lVar3,*(long *)(lVar3 + 0x1ce8),extraout_RDX,0x4a), cVar6 == '\0')) {
        return 0x56;
      }
      lVar10 = param_2[1];
      if (lVar10 != 0) {
        if (*(char *)(lVar4 + 0xa830) != '\0') {
          nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0x54,
                       "_subdeviceFlaRangeModeHostManagedVasInit",4,
                       "NVRM: FLA VAS is not allowed for base: %llx, size:%llx in gpu: %x\n",
                       *param_2,lVar10,*(undefined4 *)(lVar3 + 0x7a4));
          return 0x40;
        }
        iVar8 = (**(code **)(lVar4 + 0x388))
                          (lVar3,lVar4,uVar1,uVar2,(int)lVar9,*(undefined4 *)((long)param_2 + 0x14),
                           *param_2,lVar10,local_3c[0]);
        if (iVar8 == 0) {
          return 0;
        }
        uVar2 = *(undefined4 *)(lVar3 + 0x7a4);
        pcVar13 = "NVRM: Host Managed FLA Vaspace failed, status: %x, gpu: %x \n";
        pcVar11 = "_subdeviceFlaRangeModeHostManagedVasInit";
        uVar12 = 0x61;
LAB_0043327c:
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",uVar12,pcVar11,4,pcVar13,iVar8,
                     uVar2);
        return iVar8;
      }
    }
LAB_00432ff0:
    iVar8 = 0x1f;
  }
  return iVar8;
}


// ===== 00433410 subdeviceCtrlCmdFlaGetRange_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 subdeviceCtrlCmdFlaGetRange_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(&DAT_00001b90 + lVar1);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (*(long *)(lVar1 + 0x1ce8) == 0) {
        nvCheckFailedNoLog(4,"pKernelNvlink != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_fla.c"
                           ,0x109);
      }
      else {
        uVar4 = knvlinkIsGpuConnectedToNvswitch_IMPL(lVar1);
        if (*(char *)(lVar2 + 0xa860) != '\0') {
          uVar5 = (**(code **)(lVar2 + 0x378))
                            (lVar1,lVar2,param_2,param_2 + 8,uVar4,*(code **)(lVar2 + 0x378));
          return uVar5;
        }
        nvCheckFailedNoLog(4,"kbusIsFlaSupported(pKernelBus)",
                           "src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0x10d);
      }
      return 0x56;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0x105);
  return 0x2f;
}


// ===== 00433520 subdeviceCtrlCmdFlaGetFabricMemStats_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdFlaGetFabricMemStats_IMPL(long param_1,long *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",0x11d);
    return 0x2f;
  }
  if (*(long *)(lVar1 + 0x4a18) == 0) {
    return 0x56;
  }
  lVar4 = __nvoc_dynamicCast(*(long *)(lVar1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
  if (*(char *)(lVar4 + 0xa8) != '\0') {
    lVar4 = resservGetTlsCallContext();
    puVar2 = *(undefined4 **)(*(long *)(lVar4 + 0x48) + 0x70);
    lVar4 = gpuGetRpc(lVar1);
    if (lVar4 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_fla.c",299);
      return 0x1a;
    }
    if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
      uVar5 = rpcDmaControl_wrapper
                        (lVar1,lVar4,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                         puVar2[6]);
      return uVar5;
    }
    uVar5 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
    return uVar5;
  }
  *param_2 = (*(long *)(lVar4 + 200) + 1) - *(long *)(lVar4 + 0xc0);
  uVar5 = fabricvaspaceGetFreeHeap_IMPL(lVar4,param_2 + 1);
  return uVar5;
}


// ===== 00433690 getBridgeCountAndId =====

int getBridgeCountAndId(int *param_1,long param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *param_3;
  if (uVar1 < 100) {
    iVar3 = 0;
    do {
      if (param_1 == (int *)0x0) {
        return iVar3;
      }
      if (*param_1 - 2U < 2) {
        iVar3 = iVar3 + 1;
        *(int *)(param_2 + (ulong)uVar1 * 4) = param_1[1];
        *param_3 = *param_3 + 1;
      }
      iVar2 = getBridgeCountAndId(*(undefined8 *)(param_1 + 8),param_2,param_3);
      uVar1 = *param_3;
      param_1 = *(int **)(param_1 + 10);
      iVar3 = iVar3 + iVar2;
    } while (uVar1 < 100);
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ===== 00433720 getGpuInfos =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong getGpuInfos(long param_1,uint *param_2,byte param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  uint uVar12;
  byte local_4a;
  uint local_3c [3];
  
  if (0x45 < *param_2 - 1) {
    return 0x1f;
  }
  uVar8 = 0;
  local_4a = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
LAB_00433760:
  uVar11 = (ulong)uVar8;
  uVar7 = param_2[uVar11 * 2 + 1];
  uVar6 = uVar7 & 0xffffff;
  if (0x45 < uVar6) {
    return 0x1f;
  }
  if (uVar6 == 0x30) {
    cVar5 = osGpuSupportsAts(lVar3);
    uVar7 = (uint)(cVar5 != '\0');
  }
  else if (uVar6 < 0x31) {
    if (uVar6 == 0x25) {
      uVar7 = (uint)(*(char *)(lVar3 + 0x486) != '\0');
    }
    else if (uVar6 < 0x26) {
      uVar12 = uVar7 >> 0x1c & 7;
      uVar10 = uVar7 >> 0x18 & 0xf;
      if (uVar6 < 0x14) {
        if (0x11 < uVar6) goto LAB_004339a0;
        if (uVar6 == 2) {
          if (*(char *)(lVar3 + 0x909) != '\0') {
            lVar9 = gpuGetGspStaticInfo(lVar3);
            if (uVar10 == 0 && uVar12 == 0) {
              uVar7 = *(uint *)(lVar9 + 0x614);
            }
            else {
LAB_00433a0f:
              param_2[uVar11 * 2 + 1] = param_2[uVar11 * 2 + 1] | 0x80000000;
              uVar7 = 0;
              local_4a = 1;
            }
            goto LAB_004339b0;
          }
LAB_004337e3:
          uVar11 = 0x56;
          goto LAB_004337e8;
        }
        if (uVar6 == 4) {
          uVar7 = *(uint *)(lVar3 + 0x83c);
        }
        else {
          if (uVar6 != 1) goto LAB_00433cd8;
          if (*(char *)(lVar3 + 0x909) == '\0') goto LAB_004337e3;
          lVar9 = gpuGetGspStaticInfo(lVar3);
          if (uVar10 != 0 || uVar12 != 0) goto LAB_00433a0f;
          uVar7 = *(uint *)(lVar9 + 0x610);
        }
      }
      else {
        if (uVar6 == 0x1f) goto LAB_00433a45;
        if (uVar6 == 0x22) {
          uVar7 = (uint)(*(char *)(lVar3 + 0x452) != '\0');
        }
        else {
          if (uVar6 != 0x1b) goto LAB_00433cd8;
          if (*(char *)(lVar3 + 0x909) == '\0') goto LAB_004337e3;
          lVar9 = gpuGetGspStaticInfo(lVar3);
          if (uVar10 != 0 || uVar12 != 0) goto LAB_00433a0f;
          uVar7 = *(uint *)(lVar9 + 0x618);
        }
      }
    }
    else if (uVar6 == 0x2b) {
      uVar7 = (uint)(*(char *)(lVar3 + 0x4922) != '\0');
    }
    else if (uVar6 < 0x2c) {
      if (uVar6 == 0x28) {
        if (param_3 == 0) {
          nvCheckFailedNoLog(3,"bCanAccessHw","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c"
                             ,0xf1);
          if (*(long *)(lVar3 + 0x1ce8) == 0) {
            return 0x1f;
          }
          knvlinkIsNvswitchProxyPresent_IMPL(lVar3);
          return 0x1f;
        }
        if (*(long *)(lVar3 + 0x1ce8) == 0) goto LAB_004339a0;
        cVar5 = knvlinkIsNvswitchProxyPresent_IMPL(lVar3);
        uVar7 = (uint)(cVar5 != '\0');
      }
      else if (uVar6 == 0x2a) {
        if (param_3 == 0) {
          nvCheckFailedNoLog(3,"bCanAccessHw","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c"
                             ,0x101);
          if (*(char *)(lVar3 + 0x908) == '\0') goto LAB_00433ef8;
          if (*(long *)(lVar3 + 0x1bc0) == 0) {
            return 0x1f;
          }
          cVar5 = kmigmgrIsMIGSupported_IMPL(lVar3);
          if (cVar5 == '\0') {
            return 0x1f;
          }
          if (*(long *)(lVar3 + 0x1bc0) == 0) {
            return 0x1f;
          }
          uVar6 = 0x1f;
LAB_00433d94:
          cVar5 = kmigmgrIsMIGEnabled_IMPL(lVar3);
          uVar7 = (cVar5 == '\0') + 1;
        }
        else {
          if (*(char *)(lVar3 + 0x908) != '\0') {
            if (*(long *)(lVar3 + 0x1bc0) == 0) goto LAB_004339a0;
            cVar5 = kmigmgrIsMIGSupported_IMPL(lVar3);
            uVar7 = 0;
            if (cVar5 != '\0') {
              uVar6 = 0;
              uVar7 = 2;
              if (*(long *)(lVar3 + 0x1bc0) != 0) goto LAB_00433d94;
            }
            goto LAB_004339b0;
          }
LAB_00433ef8:
          portMemSet(local_3c,0,4);
          uVar6 = (**(code **)(lVar3 + 0x3b90))
                            (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                             *(undefined4 *)(lVar3 + 0x3b3c),0x20800a4c,local_3c,4);
          uVar7 = local_3c[0];
        }
        if (uVar6 != 0) {
          return (ulong)uVar6;
        }
      }
      else {
        if (uVar6 != 0x27) goto LAB_00433cd8;
        cVar5 = (**(code **)(lVar3 + 0x350))(lVar3);
        uVar7 = (uint)(cVar5 != '\0');
      }
    }
    else if (uVar6 == 0x2d) {
      uVar7 = (uint)(*(char *)(*(long *)(&DAT_00001b90 + lVar3) + 0xa860) != '\0');
    }
    else if (uVar6 == 0x2f) {
      lVar9 = gpuGetKernelFifoShared_IMPL(lVar3);
      uVar7 = (uint)(*(char *)(lVar9 + 0x4b0) != '\0');
    }
    else {
      if (uVar6 != 0x2c) goto LAB_00433cd8;
      lVar9 = *(long *)(lVar3 + 0x1bc8);
      if (((lVar9 == 0) || (*(char *)(lVar9 + 0x438) == '\0')) || (*(long *)(lVar9 + 0x430) == 0)) {
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x136,"getGpuInfos",4,
                     "NVRM: Unable to retrieve SM version!\n");
        return 0x40;
      }
      uVar7 = *(uint *)(*(long *)(lVar9 + 0x430) + 100);
    }
  }
  else {
    if (uVar6 == 0x3c) {
      if (*(long *)(lVar3 + 0x3c58) == 0) goto LAB_004339a0;
      uVar7 = (uint)(*(char *)(*(long *)(lVar3 + 0x3c58) + 8) != '\0');
      goto LAB_004339b0;
    }
    if (uVar6 < 0x3d) {
      if (uVar6 == 0x36) {
        if (*(char *)(lVar3 + 0x908) == '\0') {
LAB_00433a45:
          uVar7 = 1;
        }
        else {
          lVar9 = gpuGetStaticInfo(lVar3);
          if (lVar9 == 0) goto LAB_004339a0;
          uVar7 = (uint)(*(char *)(lVar9 + 0xa7ac) != '\0');
        }
        goto LAB_004339b0;
      }
      if (0x36 < uVar6) {
        if (uVar6 == 0x3a) {
          if (*(char *)(*(long *)(lVar3 + 0x1b78) + 0x454) == '\0') {
LAB_004339a0:
            uVar7 = 0;
          }
          else {
            uVar7 = *(int *)(*(long *)(lVar3 + 0x1b78) + 0x458) * 2 + 1;
          }
        }
        else if (uVar6 == 0x3b) {
          if (*(char *)(lVar3 + 0x4915) == '\0') goto LAB_004339a0;
          uVar7 = (uint)(*(char *)(*(long *)(lVar3 + 7000) + 0x3a8) != '\0');
        }
        else {
          if (uVar6 != 0x37) goto LAB_00433cd8;
          if (*(char *)(lVar3 + 0x908) == '\0') goto LAB_00433a45;
          lVar9 = gpuGetStaticInfo(lVar3);
          if (lVar9 == 0) goto LAB_004339a0;
          uVar7 = (uint)(*(char *)(lVar9 + 0xa7ad) != '\0');
        }
        goto LAB_004339b0;
      }
      if (uVar6 == 0x34) {
        uVar7 = (uint)(*(long *)(lVar3 + 0x1b80) != 0);
        goto LAB_004339b0;
      }
      if (uVar6 == 0x35) {
        uVar7 = (uint)(*(char *)(lVar3 + 0x485) != '\0');
        goto LAB_004339b0;
      }
      if (uVar6 != 0x31) goto LAB_00433cd8;
      uVar7 = *(uint *)(lVar3 + 0x49e0);
      if (*(char *)(lVar3 + 0x908) == '\0') goto LAB_004339b0;
      uVar8 = uVar8 + 1;
      param_2[uVar11 * 2 + 2] = (uVar7 == 2) + 1;
      if (*param_2 <= uVar8) {
LAB_00433880:
        uVar11 = 0;
        if (*(char *)(lVar3 + 0x909) == '\0') {
LAB_004337e8:
          if (*(char *)(lVar3 + 0x908) == '\0') {
            return uVar11;
          }
        }
        if (((int)uVar11 == 0) && ((local_4a & 1) != 0)) {
          lVar9 = gpuGetRpc(lVar3);
          if (lVar9 == 0) {
            nvAssertFailedNoLog("pRpc != NULL",
                                "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x245);
            uVar11 = 0x1a;
          }
          else {
            plVar4 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
            uVar1 = (undefined4)plVar4[2];
            uVar2 = *(undefined4 *)(*plVar4 + 0x48);
            if ((*(char *)(lVar3 + 0x909) != '\0') || (*(char *)(lVar3 + 0x90a) != '\0')) {
              uVar11 = (**(code **)(lVar3 + 0x3b90))
                                 (lVar3 + 0x3b58,uVar2,uVar1,0x20800102,param_2,0x234);
              return uVar11;
            }
            uVar8 = rpcDmaControl_wrapper(lVar3,lVar9,uVar2,uVar1,0x20800102,param_2,0x234);
            uVar11 = (ulong)uVar8;
          }
        }
        return uVar11;
      }
      goto LAB_00433760;
    }
    if (uVar6 == 0x42) {
      cVar5 = (**(code **)(*(long *)(lVar3 + 0x1b70) + 0x290))(lVar3);
      uVar7 = (uint)(cVar5 != '\0');
    }
    else if (uVar6 < 0x43) {
      if (uVar6 == 0x3f) {
        uVar7 = (uint)(*(char *)(lVar3 + 0x46d) != '\0');
      }
      else if (uVar6 == 0x41) {
        uVar7 = (uint)*(byte *)(*(long *)(lVar3 + 0x1b78) + 0xd35);
      }
      else {
        if (uVar6 != 0x3d) goto LAB_00433cd8;
        cVar5 = osDmabufIsSupported();
        if (cVar5 == '\0') goto LAB_004339a0;
        cVar5 = gpuIsApmFeatureEnabled_IMPL(lVar3);
        uVar7 = (uint)(cVar5 == '\0');
      }
    }
    else {
      if (uVar6 != 0x44) {
        if (uVar6 == 0x45) {
          if (*(char *)(lVar3 + 0x908) != '\0') goto LAB_00433a45;
          uVar7 = (uint)(*(char *)(*(long *)(lVar3 + 0x1b78) + 0xd34) != '\0');
          goto LAB_004339b0;
        }
LAB_00433cd8:
        if ((*(char *)(lVar3 + 0x909) != '\0') || (*(char *)(lVar3 + 0x908) != '\0')) {
          if (param_3 == 0) {
            return 0x1f;
          }
          param_2[uVar11 * 2 + 1] = uVar7 | 0x80000000;
          local_4a = param_3;
          goto LAB_004339a0;
        }
        uVar11 = 0x1f;
        goto LAB_004337e8;
      }
      if (*(char *)(lVar3 + 0x454) == '\0') goto LAB_004339a0;
      cVar5 = osNumaOnliningEnabled(*(undefined8 *)(lVar3 + 0x4e0));
      uVar7 = (cVar5 == '\0') + 1;
    }
  }
LAB_004339b0:
  param_2[uVar11 * 2 + 2] = uVar7;
  uVar8 = uVar8 + 1;
  if (*param_2 <= uVar8) goto LAB_00433880;
  goto LAB_00433760;
}


// ===== 00434010 getBridgeObject =====

long getBridgeObject(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  if (param_1 != 0) {
    while (*(int *)(param_1 + 4) != param_2) {
      for (lVar1 = *(long *)(param_1 + 0x20); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x28)) {
        if (param_2 == *(int *)(lVar1 + 4)) {
          return lVar1;
        }
        for (lVar2 = *(long *)(lVar1 + 0x20); lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x28)) {
          if (param_2 == *(int *)(lVar2 + 4)) {
            return lVar2;
          }
          for (lVar3 = *(long *)(lVar2 + 0x20); lVar3 != 0; lVar3 = *(long *)(lVar3 + 0x28)) {
            if (param_2 == *(int *)(lVar3 + 4)) {
              return lVar3;
            }
            for (lVar4 = *(long *)(lVar3 + 0x20); lVar4 != 0; lVar4 = *(long *)(lVar4 + 0x28)) {
              if (param_2 == *(int *)(lVar4 + 4)) {
                return lVar4;
              }
              for (lVar5 = *(long *)(lVar4 + 0x20); lVar5 != 0; lVar5 = *(long *)(lVar5 + 0x28)) {
                if (param_2 == *(int *)(lVar5 + 4)) {
                  return lVar5;
                }
                for (lVar6 = *(long *)(lVar5 + 0x20); lVar6 != 0; lVar6 = *(long *)(lVar6 + 0x28)) {
                  if (param_2 == *(int *)(lVar6 + 4)) {
                    return lVar6;
                  }
                  for (lVar7 = *(long *)(lVar6 + 0x20); lVar7 != 0; lVar7 = *(long *)(lVar7 + 0x28))
                  {
                    if (param_2 == *(int *)(lVar7 + 4)) {
                      return lVar7;
                    }
                    for (lVar8 = *(long *)(lVar7 + 0x20); lVar8 != 0;
                        lVar8 = *(long *)(lVar8 + 0x28)) {
                      if (param_2 == *(int *)(lVar8 + 4)) {
                        return lVar8;
                      }
                      lVar9 = getBridgeObject(*(undefined8 *)(lVar8 + 0x20),param_2);
                      if (lVar9 != 0) {
                        return lVar9;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      param_1 = *(long *)(param_1 + 0x28);
      if (param_1 == 0) {
        return 0;
      }
    }
  }
  return param_1;
}


// ===== 00434290 subdeviceCtrlCmdGpuGetInfoV2_IMPL =====

void subdeviceCtrlCmdGpuGetInfoV2_IMPL(undefined8 param_1,undefined8 param_2)

{
  getGpuInfos(param_1,param_2,1);
  return;
}


// ===== 004342a0 subdeviceCtrlCmdGpuGetVfCaps_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetVfCaps_IMPL(void)

{
  return 0x56;
}


// ===== 004342b0 subdeviceCtrlCmdGpuGetCachedInfo_IMPL =====

void subdeviceCtrlCmdGpuGetCachedInfo_IMPL(undefined8 param_1,undefined8 param_2)

{
  getGpuInfos(param_1,param_2,0);
  return;
}


// ===== 004342c0 subdeviceCtrlCmdGpuForceGspUnload_IMPL =====

undefined8 subdeviceCtrlCmdGpuForceGspUnload_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar1 + 0x4a4e) != '\0') {
    lVar2 = *(long *)(lVar1 + 0x1ba8);
    uVar3 = kgspUnloadRm_IMPL(lVar1,lVar2,0,0xc0);
    *(undefined2 *)(lVar2 + 0x69eff) = 0x101;
    return uVar3;
  }
  nvCheckFailedNoLog(1,"IS_VGPU_GSP_PLUGIN_OFFLOAD_ENABLED(pGpu)",
                     "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x27f);
  return 0x56;
}


// ===== 00434340 subdeviceCtrlCmdGpuGetPhysicalBridgeVersionInfo_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetPhysicalBridgeVersionInfo_IMPL(undefined8 param_1,byte *param_2)

{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined4 local_2c [3];
  
  local_2c[0] = 0;
  if (param_2 == (byte *)0x0) {
    return 0x1f;
  }
  bVar2 = getBridgeCountAndId(*(undefined8 *)(*(long *)(g_pSys + 0x208) + 0x88),param_2 + 4,local_2c
                             );
  *param_2 = bVar2;
  if (bVar2 < 100) {
    lVar5 = 0;
    if (bVar2 != 0) {
      do {
        puVar4 = *(undefined4 **)(*(long *)(g_pSys + 0x208) + 0x88);
        if (puVar4 == (undefined4 *)0x0) {
          return 0x1f;
        }
        iVar1 = *(int *)(param_2 + lVar5 * 4 + 4);
        while ((puVar3 = puVar4, iVar1 != puVar4[1] &&
               (puVar3 = (undefined4 *)getBridgeObject(*(undefined8 *)(puVar4 + 8),iVar1),
               puVar3 == (undefined4 *)0x0))) {
          puVar4 = *(undefined4 **)(puVar4 + 10);
          if (puVar4 == (undefined4 *)0x0) {
            return 0x1f;
          }
        }
        *(undefined4 *)(param_2 + lVar5 * 8 + 0x194) = puVar3[0x13];
        param_2[lVar5 * 8 + 0x198] = *(byte *)(puVar3 + 0x14);
        param_2[lVar5 * 8 + 0x199] = *(byte *)((long)puVar3 + 0x51);
        param_2[lVar5 * 8 + 0x19a] = (byte)*puVar3;
        lVar5 = lVar5 + 1;
      } while ((byte)lVar5 < *param_2);
    }
    return 0;
  }
  nvAssertFailedNoLog("*pPlxCount < NV2080_CTRL_MAX_PHYSICAL_BRIDGE",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x300);
  return 0x5b;
}


// ===== 00434480 subdeviceCtrlCmdGpuGetAllBridgesUpstreamOfGpu_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetAllBridgesUpstreamOfGpu_IMPL(long param_1,byte *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  byte *pbVar4;
  undefined8 *puVar5;
  long *plVar6;
  byte bVar7;
  
  if (param_2 == (byte *)0x0) {
    return 0x1f;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = 0;
  plVar6 = *(long **)(lVar1 + 0x1d50);
  while (plVar6 != (long *)0x0) {
    if (*plVar6 == 0) {
      nvAssertFailedNoLog("pGpuHWBCList->pHWBC != NULL",
                          "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x318);
      return 0x3d;
    }
    *(undefined4 *)(param_2 + lVar3 * 4 + 4) = *(undefined4 *)(*plVar6 + 4);
    lVar3 = lVar3 + 1;
    plVar6 = (long *)plVar6[1];
    if (lVar3 == 100) {
      nvAssertFailedNoLog("bridgeIndex < NV2080_CTRL_MAX_PHYSICAL_BRIDGE",
                          "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x31c);
      return 0x5b;
    }
  }
  *param_2 = (byte)lVar3;
  if ((byte)lVar3 != 0) {
    puVar5 = *(undefined8 **)(lVar1 + 0x1d50);
    bVar7 = 0;
    pbVar4 = param_2 + 0x194;
    do {
      if (puVar5 == (undefined8 *)0x0) {
        return 0;
      }
      puVar2 = (undefined4 *)*puVar5;
      if (puVar2 == (undefined4 *)0x0) {
        return 0x1f;
      }
      bVar7 = bVar7 + 1;
      *(undefined4 *)(pbVar4 + 8) = puVar2[2];
      *pbVar4 = *(byte *)(puVar2 + 3);
      pbVar4[1] = *(byte *)((long)puVar2 + 0xd);
      pbVar4[2] = *(byte *)((long)puVar2 + 0xe);
      *(undefined4 *)(pbVar4 + 0xc) = puVar2[0x13];
      pbVar4[3] = *(byte *)(puVar2 + 0x14);
      pbVar4[4] = *(byte *)((long)puVar2 + 0x51);
      pbVar4[5] = (byte)*puVar2;
      puVar5 = (undefined8 *)puVar5[1];
      pbVar4 = pbVar4 + 0x10;
    } while (bVar7 < *param_2);
  }
  return 0;
}


// ===== 004345b0 subdeviceCtrlCmdGpuSetOptimusInfo_IMPL =====

undefined8 subdeviceCtrlCmdGpuSetOptimusInfo_IMPL(long param_1,char *param_2)

{
  if (*param_2 != '\0') {
    *(undefined1 *)(*(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b78) + 0x43a) = 1;
  }
  return 0;
}


// ===== 004345e0 subdeviceCtrlCmdGpuGetEncoderCapacity_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 subdeviceCtrlCmdGpuGetEncoderCapacity_IMPL(long param_1,uint *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  char cVar5;
  long lVar6;
  undefined8 uVar7;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar4 = plVar3[2];
  uVar1 = *(undefined4 *)(*plVar3 + 0x48);
  cVar5 = rmapiLockIsOwner();
  if ((cVar5 == '\0') || (cVar5 = rmGpuLockIsOwner(), cVar5 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x3ab);
    return 0x2f;
  }
  if (*param_2 == 2) {
    if (*(char *)(lVar2 + 0x4a52) == '\0') {
      return 0x56;
    }
  }
  else if (1 < *param_2) {
    return 0x1f;
  }
  param_2[1] = 100;
  if ((*(char *)(lVar2 + 0x908) != '\0') && (lVar6 = gpuGetRpc(lVar2), lVar6 != 0)) {
    uVar7 = (**(code **)(lVar6 + 0x330))
                      (lVar2,lVar6,uVar1,(int)lVar4,param_2 + 1,*(code **)(lVar6 + 0x330));
    return uVar7;
  }
  return 0;
}


// ===== 004346f0 subdeviceCtrlCmdGpuGetNvencSwSessionStats_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 subdeviceCtrlCmdGpuGetNvencSwSessionStats_IMPL(long param_1,undefined8 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x3df);
    return 0x2f;
  }
  if ((*(char *)(lVar7 + 0x909) != '\0') && (*(char *)(lVar7 + 0x4a4e) != '\0')) {
    lVar6 = resservGetTlsCallContext();
    puVar1 = *(undefined4 **)(lVar6 + 0x48);
    uVar5 = (**(code **)(lVar7 + 0x3b90))
                      (lVar7 + 0x3b58,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                       puVar1[6]);
    return uVar5;
  }
  lVar7 = lVar7 + 0x49b8;
  uVar5 = listCount_IMPL(lVar7);
  if ((int)uVar5 == 0) {
    *param_2 = 0;
    *(undefined4 *)(param_2 + 1) = 0;
    return uVar5;
  }
  uVar8 = 0;
  uVar9 = 0;
  uVar3 = listCount_IMPL(lVar7);
  *(undefined4 *)param_2 = uVar3;
  lVar6 = listHead_IMPL(lVar7);
  while (lVar6 != 0) {
    lVar6 = *(long *)(lVar6 + 8);
    if (lVar6 != 0) {
      uVar9 = uVar9 + *(int *)(lVar6 + 0x154);
      uVar8 = uVar8 + *(int *)(lVar6 + 0x158);
    }
    lVar6 = listNext_IMPL(lVar7);
  }
  uVar4 = listCount_IMPL(lVar7);
  *(uint *)((long)param_2 + 4) = uVar9 / uVar4;
  uVar9 = listCount_IMPL(lVar7);
  *(uint *)(param_2 + 1) = uVar8 / uVar9;
  return 0;
}


// ===== 00434880 _subdeviceCtrlCmdGpuGetNvencSwSessionInfo =====

undefined8
_subdeviceCtrlCmdGpuGetNvencSwSessionInfo(long param_1,int param_2,long param_3,uint *param_4)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  
  if (param_2 != 0x200) {
    nvAssertFailedNoLog("sessionInfoTblEntry == NV2080_CTRL_GPU_NVENC_SESSION_INFO_MAX_COPYOUT_ENTRIES"
                        ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x41f);
    return 0x1f;
  }
  uVar4 = 0;
  portMemSet(param_3,0,0x4000);
  lVar2 = listHead_IMPL(param_1 + 0x49b8);
  uVar1 = 0;
  while (lVar2 != 0) {
    lVar2 = *(long *)(lVar2 + 8);
    uVar5 = uVar1;
    if (lVar2 != 0) {
      uVar4 = (int)uVar1 + 1;
      uVar5 = (ulong)uVar4;
      lVar3 = uVar1 * 0x20;
      *(undefined4 *)(param_3 + 8 + lVar3) = *(undefined4 *)(lVar2 + 0x144);
      *(undefined4 *)(param_3 + lVar3) = *(undefined4 *)(lVar2 + 0x13c);
      *(undefined4 *)(param_3 + 4 + lVar3) = *(undefined4 *)(lVar2 + 0x140);
      *(undefined4 *)(param_3 + 0xc + lVar3) = *(undefined4 *)(lVar2 + 0x148);
      *(undefined4 *)(param_3 + 0x10 + lVar3) = *(undefined4 *)(lVar2 + 0x14c);
      *(undefined4 *)(param_3 + 0x14 + lVar3) = *(undefined4 *)(lVar2 + 0x150);
      *(undefined4 *)(param_3 + 0x18 + lVar3) = *(undefined4 *)(lVar2 + 0x154);
      *(undefined4 *)(param_3 + 0x1c + lVar3) = *(undefined4 *)(lVar2 + 0x158);
      if (uVar4 == 0x200) break;
    }
    uVar4 = (uint)uVar5;
    lVar2 = listNext_IMPL(param_1 + 0x49b8);
    uVar1 = uVar5;
  }
  *param_4 = uVar4;
  return 0;
}


// ===== 004349a0 subdeviceCtrlCmdGpuGetNvencSwSessionInfo_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetNvencSwSessionInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 local_2c [3];
  
  local_2c[0] = 0;
  uVar5 = *(undefined8 *)(param_2 + 2);
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x45d);
    return 0x2f;
  }
  if ((*(char *)(lVar1 + 0x908) == '\0') && (*(int *)(lVar1 + 0x49e0) != 1)) {
    *param_2 = 0;
  }
  else {
    if ((*(long *)(param_2 + 2) != 0) && (iVar3 = listCount_IMPL(), iVar3 != 0)) {
      uVar5 = _subdeviceCtrlCmdGpuGetNvencSwSessionInfo(lVar1,*param_2,uVar5,local_2c);
      if ((int)uVar5 != 0) {
        return 0x1f;
      }
      *param_2 = local_2c[0];
      return uVar5;
    }
    uVar4 = listCount_IMPL(lVar1 + 0x49b8);
    *param_2 = uVar4;
  }
  return 0;
}


// ===== 00434a90 subdeviceCtrlCmdGpuGetNvencSwSessionInfoV2_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetNvencSwSessionInfoV2_IMPL(long param_1,int *param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  int local_1c;
  
  local_1c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x480);
    return 0x2f;
  }
  if ((*(char *)(lVar1 + 0x908) == '\0') && (*(int *)(lVar1 + 0x49e0) != 1)) {
    *param_2 = 0;
  }
  else {
    if ((*param_2 != 0) && (iVar3 = listCount_IMPL(), iVar3 != 0)) {
      uVar4 = _subdeviceCtrlCmdGpuGetNvencSwSessionInfo(lVar1,*param_2,param_2 + 1,&local_1c);
      if ((int)uVar4 != 0) {
        return 0x1f;
      }
      *param_2 = local_1c;
      return uVar4;
    }
    iVar3 = listCount_IMPL(lVar1 + 0x49b8);
    *param_2 = iVar3;
  }
  return 0;
}


// ===== 00434b90 subdeviceCtrlCmdGpuGetNvfbcSwSessionStats_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetNvfbcSwSessionStats_IMPL(long param_1,uint *param_2)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    cVar1 = rmGpuLockIsOwner();
    if (cVar1 != '\0') {
      lVar4 = lVar4 + 0x49e8;
      uVar2 = listCount_IMPL(lVar4);
      if ((int)uVar2 == 0) {
        param_2[0] = 0;
        param_2[1] = 0;
        param_2[2] = 0;
        return uVar2;
      }
      lVar3 = listHead_IMPL(lVar4);
      if (lVar3 == 0) {
        uVar5 = 0;
        uVar7 = 0;
        uVar6 = 0;
      }
      else {
        uVar5 = 0;
        uVar6 = 0;
        uVar7 = 0;
        do {
          lVar3 = *(long *)(lVar3 + 8);
          if (lVar3 != 0) {
            uVar7 = uVar7 + *(int *)(lVar3 + 0x164);
            uVar6 = uVar6 + *(int *)(lVar3 + 0x168);
            uVar5 = uVar5 + 1;
          }
          lVar3 = listNext_IMPL(lVar4);
        } while (lVar3 != 0);
        if (uVar5 == 0) {
          uVar7 = 0;
          uVar6 = 0;
        }
        else {
          uVar7 = uVar7 / uVar5;
          uVar6 = uVar6 / uVar5;
        }
      }
      param_2[2] = uVar6;
      param_2[1] = uVar7;
      *param_2 = uVar5;
      return 0;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x4aa);
  return 0x2f;
}


// ===== 00434cf0 subdeviceCtrlCmdGpuGetNvfbcSwSessionInfo_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetNvfbcSwSessionInfo_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x4e1);
    return 0x2f;
  }
  portMemSet(param_2,0,0x3404);
  lVar1 = lVar1 + 0x49e8;
  lVar4 = listHead_IMPL(lVar1);
  uVar6 = 0;
  do {
    if (lVar4 == 0) {
LAB_00434d70:
      *param_2 = uVar6;
      return 0;
    }
    lVar2 = *(long *)(lVar4 + 8);
    uVar7 = uVar6;
    if (lVar2 != 0) {
      puVar5 = param_2 + (ulong)uVar6 * 0xd + 1;
      *puVar5 = *(uint *)(lVar2 + 0x138);
      puVar5[2] = *(uint *)(lVar2 + 0x13c);
      puVar5[3] = *(uint *)(lVar2 + 0x140);
      puVar5[5] = *(uint *)(lVar2 + 0x144);
      puVar5[4] = *(uint *)(lVar2 + 0x148);
      puVar5[6] = *(uint *)(lVar2 + 0x14c);
      puVar5[7] = *(uint *)(lVar2 + 0x150);
      puVar5[8] = *(uint *)(lVar2 + 0x154);
      cVar3 = nvfbcIsSessionDataStale(*(undefined8 *)(lVar2 + 0x170));
      if (cVar3 == '\0') {
        puVar5[9] = *(uint *)(lVar2 + 0x158);
        puVar5[10] = *(uint *)(lVar2 + 0x15c);
        puVar5[0xb] = *(uint *)(lVar2 + 0x164);
        puVar5[0xc] = *(uint *)(lVar2 + 0x168);
      }
      else {
        puVar5[9] = 0;
        puVar5[10] = 0;
        puVar5[0xb] = 0;
        puVar5[0xc] = 0;
      }
      uVar7 = uVar6 + 1;
      if (uVar7 == 0x100) {
        uVar6 = uVar6 + 1;
        nvAssertFailedNoLog(&DAT_00d78956,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                            0x50c);
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x50d,
                     "subdeviceCtrlCmdGpuGetNvfbcSwSessionInfo_IMPL",4,
                     "NVRM: more entries in pGpu->nvencSessionList than NV2080_CTRL_GPU_NVENC_SESSION_INFO_MAX_COPYOUT_ENTRIES\n"
                    );
        goto LAB_00434d70;
      }
    }
    lVar4 = listNext_IMPL(lVar1,lVar4);
    uVar6 = uVar7;
  } while( true );
}


// ===== 00434ef0 subdeviceCtrlCmdGpuGetSdm_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetSdm_IMPL(long param_1,int *param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    *param_2 = 1 << ((byte)*(undefined4 *)(lVar1 + 0x7b8) & 0x1f);
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                      0x52b);
  return 0x2f;
}


// ===== 00434f60 subdeviceCtrlCmdGpuGetSimulationInfo_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetSimulationInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    if ((*(char *)(lVar1 + 0x446) == '\0') && (*(char *)(lVar1 + 0x490e) == '\0')) {
      *param_2 = 0;
    }
    else {
      *param_2 = 0xffffffff;
    }
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                      0x541);
  return 0x2f;
}


// ===== 00434ff0 subdeviceCtrlCmdGpuGetEnginesV2_IMPL =====

int subdeviceCtrlCmdGpuGetEnginesV2_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  int local_1a4;
  int local_18c;
  long local_188;
  long local_180;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x586);
    return 0x2f;
  }
  local_1a4 = gpuUpdateEngineTable_IMPL(lVar2);
  if (local_1a4 == 0) {
    if (0x54 < *(uint *)(lVar2 + 0x1e18)) {
      nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x58e,
                   "subdeviceCtrlCmdGpuGetEnginesV2_IMPL",4,
                   "NVRM: The engine database\'s size (0x%x) exceeds NV2080_GPU_MAX_ENGINES_LIST_SIZE (0x%x)!\n"
                   ,*(uint *)(lVar2 + 0x1e18),0x54);
      return 0x40;
    }
    if (*(long *)(lVar2 + 0x1bc0) == 0) {
      local_1a4 = 0;
    }
    else {
      local_1a4 = kmigmgrFilterEngineList_IMPL
                            (lVar2,*(long *)(lVar2 + 0x1bc0),param_1,&local_188,param_2);
      if (local_1a4 == 0) {
        gpuGetNv2080EngineTypeList_IMPL(&local_188,*param_2,param_2 + 1);
      }
      if (0x54 < *param_2) {
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x5ad,
                     "subdeviceCtrlCmdGpuGetEnginesV2_IMPL",4,
                     "NVRM: The engine count (0x%x) exceeds NV2080_GPU_MAX_ENGINES_LIST_SIZE (0x%x)!\n"
                     ,*param_2,0x54);
        return 0x40;
      }
    }
    cVar5 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4));
    bVar4 = false;
    if (cVar5 == '\0') {
      local_1a4 = rmDeviceGpuLocksAcquire(lVar2,2,0);
      bVar4 = true;
      if (local_1a4 != 0) {
        nvAssertOkFailedNoLog
                  (local_1a4,"status","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x5ba);
        return local_1a4;
      }
    }
    if (*param_2 != 0) {
      uVar7 = 0;
      do {
        while( true ) {
          uVar9 = param_2[(ulong)uVar7 + 1];
          if ((uVar9 - 0x34 < 10) || (uVar9 - 9 < 10)) break;
LAB_004350d0:
          uVar7 = uVar7 + 1;
          if (*param_2 <= uVar7) goto LAB_0043512d;
        }
        uVar1 = uVar9 - 9;
        if (0x12 < uVar9) {
          uVar1 = uVar9 - 0x2a;
        }
        cVar5 = kceIsDecompLce_STATIC_DISPATCH(lVar2,uVar1);
        if (cVar5 == '\0') goto LAB_004350d0;
        uVar9 = uVar7 + 1;
        param_2[(ulong)uVar7 + 1] = uVar1 + 0x40;
        uVar7 = uVar9;
      } while (uVar9 < *param_2);
    }
LAB_0043512d:
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x5cf,
                 "subdeviceCtrlCmdGpuGetEnginesV2_IMPL",1,
                 "NVRM: ================NV2080_ENGINE List==================\n");
    if ((((*(long *)(lVar2 + 0x1bc0) != 0) &&
         (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2), cVar5 != '\0')) &&
        (lVar3 = *(long *)(lVar2 + 0x1bc0), lVar3 != 0)) &&
       (((iVar6 = kmigmgrGetInstanceRefFromDevice_IMPL
                            (lVar2,lVar3,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),
                             &local_188), iVar6 == 0 && (local_180 != 0)) &&
        ((local_188 != 0 &&
         (iVar6 = kmigmgrGetLocalToGlobalEngineType_IMPL
                            (lVar2,lVar3,local_188,local_180,1,&local_18c), iVar6 == 0)))))) {
      nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x5e0,
                   "subdeviceCtrlCmdGpuGetEnginesV2_IMPL",1,
                   "NVRM: SwizzId = %d CiId = %d GrId = %d\n",*(undefined4 *)(local_188 + 0x968),
                   *(undefined4 *)(local_180 + 0xc0),local_18c + -1);
    }
    if (*param_2 != 0) {
      uVar7 = 0;
      do {
        uVar8 = (ulong)uVar7;
        uVar7 = uVar7 + 1;
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x5ec,
                     "subdeviceCtrlCmdGpuGetEnginesV2_IMPL",1,"NVRM: engine[%d] = 0x%x\n",uVar8,
                     param_2[uVar8 + 1]);
      } while (uVar7 < *param_2);
    }
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x5ee,
                 "subdeviceCtrlCmdGpuGetEnginesV2_IMPL",1,
                 "NVRM: =============================================\n");
    if (bVar4) {
      rmDeviceGpuLocksRelease(lVar2,2,0);
      return local_1a4;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (local_1a4,"gpuUpdateEngineTable(pGpu)",
               "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x589);
  }
  return local_1a4;
}


// ===== 00435480 subdeviceCtrlCmdGpuGetEngines_IMPL =====

int subdeviceCtrlCmdGpuGetEngines_IMPL(undefined8 param_1,uint *param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint local_17c;
  undefined1 local_178 [344];
  
  lVar1 = *(long *)(param_2 + 2);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x560);
    return 0x2f;
  }
  portMemSet(&local_17c,0,0x154);
  iVar3 = subdeviceCtrlCmdGpuGetEnginesV2_IMPL(param_1,&local_17c);
  if (iVar3 == 0) {
    if (lVar1 != 0) {
      if (*param_2 < local_17c) {
        nvCheckFailedNoLog(1,"pParams->engineCount >= getEngineParamsV2.engineCount",
                           "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x56a);
        return 2;
      }
      portMemCopy(lVar1,(ulong)local_17c << 2,local_178,(ulong)local_17c << 2);
    }
    *param_2 = local_17c;
  }
  else {
    nvCheckFailedNoLog(1,"NV_OK == status","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                       0x565);
  }
  return iVar3;
}


// ===== 004355a0 subdeviceCtrlCmdGpuGetEngineClasslist_IMPL =====

int subdeviceCtrlCmdGpuGetEngineClasslist_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_3c = gpuGetRmEngineType_IMPL(*param_2);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x608);
    return 0x2f;
  }
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    if (cVar3 != '\0') {
      uVar2 = *(undefined8 *)(lVar1 + 0x1bc0);
      iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL
                        (lVar1,uVar2,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),&local_38);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pSubdevice), &ref)"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x610);
        return iVar4;
      }
      iVar4 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (lVar1,uVar2,CONCAT44(uStack_34,local_38),local_30,local_3c,&local_3c);
      if (iVar4 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar4,
                   "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &rmEngineType)"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x613);
        return iVar4;
      }
    }
  }
  iVar4 = gpuXlateClientEngineIdToEngDesc_IMPL(lVar1,local_3c,&local_38);
  if (iVar4 == 0) {
    iVar5 = gpuGetClassList_IMPL(lVar1,param_2 + 1,*(undefined8 *)(param_2 + 2),local_38);
    iVar4 = 0;
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x62b,
                   "subdeviceCtrlCmdGpuGetEngineClasslist_IMPL",4,
                   "NVRM: NV2080_CTRL_CMD_GPU_GET_ENGINE_CLASSLIST Class List query failed\n");
      return iVar5;
    }
  }
  else {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x61c);
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x620,
                 "subdeviceCtrlCmdGpuGetEngineClasslist_IMPL",4,
                 "NVRM: NV2080_CTRL_CMD_GPU_GET_ENGINE_CLASSLIST Invalid engine ID 0x%x\n",*param_2)
    ;
  }
  return iVar4;
}


// ===== 004357c0 subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL(long param_1,int *param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined1 local_58 [4];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = *(undefined8 *)(lVar2 + 0x1bc0);
  param_2[3] = 0;
  local_54 = gpuGetRmEngineType_IMPL(*param_2);
  iVar5 = gpuXlateClientEngineIdToEngDesc_IMPL(lVar2,local_54,local_58);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x64f,
                 "subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL",4,
                 "NVRM: Invalid engine ID 0x%x (0x%x)\n",*param_2,local_54);
    return iVar5;
  }
  iVar5 = gpuGetClassByClassId_IMPL(lVar2,param_2[1],&local_50);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x658,
                 "subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL",4,"NVRM: Invalid class ID 0x%x\n",
                 param_2[1]);
    return iVar5;
  }
  if (*(int *)(local_50 + 4) != -0xc1eab00) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x660,
                 "subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL",4,
                 "NVRM: Class 0x%x is not considered a partnership class.\n",param_2[1]);
    return 0x56;
  }
  iVar5 = *param_2;
  if ((*(long *)(lVar2 + 0x1bc0) != 0) &&
     (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2), cVar4 != '\0')) {
    iVar6 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (lVar2,uVar3,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),&local_48);
    uVar8 = 0x66e;
    if (iVar6 != 0) goto LAB_00435aff;
    iVar6 = kmigmgrGetLocalToGlobalEngineType_IMPL(lVar2,uVar3,local_48,local_40,local_54,&local_54)
    ;
    if (iVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar6,
                 "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &rmEngineType)"
                 ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x672);
      return iVar6;
    }
    iVar6 = gpuGetNv2080EngineType_IMPL(local_54);
    *param_2 = iVar6;
  }
  lVar7 = gpuGetKernelFifoShared_IMPL(lVar2);
  iVar6 = (**(code **)(lVar7 + 0x268))(lVar2,lVar7,param_2,*(code **)(lVar7 + 0x268));
  *param_2 = iVar5;
  if (iVar6 != 0) {
    iVar5 = gpuUpdateEngineTable_IMPL(lVar2);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"gpuUpdateEngineTable(pGpu)",
                 "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x68d);
      return iVar5;
    }
    if (0x20 < *(uint *)(lVar2 + 0x1e18)) {
      nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x692,
                   "subdeviceCtrlCmdGpuGetEnginePartnerList_IMPL",4,
                   "NVRM: partnerList space is too small, time to increase. This is fatal\n");
      return iVar6;
    }
    lVar7 = 0;
    if (*(uint *)(lVar2 + 0x1e18) != 0) {
      do {
        iVar5 = gpuGetNv2080EngineType_IMPL(*(undefined4 *)(*(long *)(lVar2 + 0x1e20) + lVar7 * 4));
        if (*param_2 != iVar5) {
          uVar1 = param_2[3];
          param_2[3] = uVar1 + 1;
          param_2[(ulong)uVar1 + 4] = iVar5;
        }
        lVar7 = lVar7 + 1;
      } while ((uint)lVar7 < *(uint *)(lVar2 + 0x1e18));
    }
  }
  if (*(long *)(lVar2 + 0x1bc0) == 0) {
    return iVar6;
  }
  cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2);
  if (cVar4 == '\0') {
    return iVar6;
  }
  iVar6 = kmigmgrGetInstanceRefFromDevice_IMPL
                    (lVar2,uVar3,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),&local_48);
  if (iVar6 == 0) {
    iVar5 = kmigmgrFilterEnginePartnerList_IMPL(lVar2,uVar3,param_1,param_2);
    return iVar5;
  }
  uVar8 = 0x6aa;
LAB_00435aff:
  nvCheckOkFailedNoLog
            (4,iVar6,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
             "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",uVar8);
  return iVar6;
}


// ===== 00435b50 subdeviceCtrlCmdGpuGetEngineFaultInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGpuGetEngineFaultInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  bool bVar6;
  int local_3c;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = gpuGetKernelFifoShared_IMPL(lVar1);
  local_3c = gpuGetRmEngineType_IMPL(*param_2);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x6c8);
    return 0x2f;
  }
  if (((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) &&
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar3 != '\0')) {
    uVar2 = *(undefined8 *)(lVar1 + 0x1bc0);
    iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (lVar1,uVar2,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),&local_38);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                 "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x6d5);
      return iVar4;
    }
    iVar4 = kmigmgrGetLocalToGlobalEngineType_IMPL(lVar1,uVar2,local_38,local_30,local_3c,&local_3c)
    ;
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &rmEngineType)"
                 ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x6d8);
      return iVar4;
    }
  }
  iVar4 = (**(code **)(lVar5 + 0x218))(lVar1,lVar5,2,local_3c,4,param_2 + 1);
  if (iVar4 == 0) {
    bVar6 = false;
    if (local_3c - 1U < 8) {
      bVar6 = *(char *)(lVar5 + 0x4b3) != '\0';
    }
    *(bool *)(param_2 + 2) = bVar6;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x6e4,
               "subdeviceCtrlCmdGpuGetEngineFaultInfo_IMPL",4,
               "NVRM: NV2080_CTRL_CMD_GPU_GET_ENGINE_INFO failed\n");
  return iVar4;
}


// ===== 00435d35 subdeviceCtrlCmdGpuGetFermiGpcInfo_IMPL.cold =====

void subdeviceCtrlCmdGpuGetFermiGpcInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00435d40 subdeviceCtrlCmdGpuGetFermiGpcInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdGpuGetFermiGpcInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  char cVar5;
  long lVar6;
  ulong uVar7;
  undefined1 local_58 [16];
  undefined4 local_48;
  
  lVar6 = rmapiGetInterface(4);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar4 = plVar2[2];
  uVar1 = *(undefined4 *)(*plVar2 + 0x48);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 != '\0') {
    cVar5 = rmDeviceGpuLockIsOwner
                      (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7a4));
    if (cVar5 != '\0') {
      portMemSet(local_58,0,0x18);
      uVar7 = (**(code **)(lVar6 + 0x38))(lVar6,uVar1,(int)lVar4,0x2080122a,local_58,0x18);
      if ((int)uVar7 == 0) {
        *param_2 = local_48;
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar7 & 0xffffffff,
                   "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_GR_GET_GPC_MASK, &gpcMaskParams, sizeof(gpcMaskParams))"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x70a);
        uVar7 = uVar7 & 0xffffffff;
      }
      return uVar7;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(GPU_RES_GET_GPU(pSubdevice)->gpuInstance)"
                      ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x705);
  return 0x2f;
}


// ===== 00435e58 subdeviceCtrlCmdGpuGetFermiTpcInfo_IMPL.cold =====

void subdeviceCtrlCmdGpuGetFermiTpcInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00435e70 subdeviceCtrlCmdGpuGetFermiTpcInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdGpuGetFermiTpcInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  char cVar5;
  long lVar6;
  ulong uVar7;
  undefined1 local_58 [16];
  undefined4 local_48;
  undefined4 local_44;
  
  lVar6 = rmapiGetInterface(4);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar4 = plVar2[2];
  uVar1 = *(undefined4 *)(*plVar2 + 0x48);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 != '\0') {
    cVar5 = rmDeviceGpuLockIsOwner
                      (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7a4));
    if (cVar5 != '\0') {
      portMemSet(local_58,0,0x18);
      local_48 = *param_2;
      uVar7 = (**(code **)(lVar6 + 0x38))(lVar6,uVar1,(int)lVar4,0x2080122b,local_58,0x18);
      if ((int)uVar7 == 0) {
        param_2[1] = local_44;
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar7 & 0xffffffff,
                   "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_GR_GET_TPC_MASK, &tpcMaskParams, sizeof(tpcMaskParams))"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x72f);
        uVar7 = uVar7 & 0xffffffff;
      }
      return uVar7;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(GPU_RES_GET_GPU(pSubdevice)->gpuInstance)"
                      ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x729);
  return 0x2f;
}


// ===== 00435f88 subdeviceCtrlCmdGpuGetFermiZcullInfo_IMPL.cold =====

void subdeviceCtrlCmdGpuGetFermiZcullInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00435fa0 subdeviceCtrlCmdGpuGetFermiZcullInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdGpuGetFermiZcullInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  char cVar5;
  long lVar6;
  ulong uVar7;
  undefined4 local_40;
  undefined4 local_3c;
  
  lVar6 = rmapiGetInterface(4);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar4 = plVar2[2];
  uVar1 = *(undefined4 *)(*plVar2 + 0x48);
  cVar5 = rmapiLockIsOwner();
  if (cVar5 != '\0') {
    cVar5 = rmDeviceGpuLockIsOwner
                      (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7a4));
    if (cVar5 != '\0') {
      portMemSet(&local_40,0,8);
      local_40 = *param_2;
      uVar7 = (**(code **)(lVar6 + 0x38))(lVar6,uVar1,(int)lVar4,0x20801237,&local_40,8);
      if ((int)uVar7 == 0) {
        param_2[1] = local_3c;
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar7 & 0xffffffff,
                   "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_GR_GET_ZCULL_MASK, &zcullMaskParams, sizeof(zcullMaskParams))"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x77f);
        uVar7 = uVar7 & 0xffffffff;
      }
      return uVar7;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(GPU_RES_GET_GPU(pSubdevice)->gpuInstance)"
                      ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x779);
  return 0x2f;
}


// ===== 004360c0 subdeviceCtrlCmdGpuGetPesInfo_IMPL =====

int subdeviceCtrlCmdGpuGetPesInfo_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  undefined1 local_30 [8];
  
  uVar1 = *param_2;
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x7a7);
    return 0x2f;
  }
  iVar5 = serverGetClientUnderLock(g_resServ,uVar2,local_30);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"serverGetClientUnderLock(&g_resServ, hClient, &pRsClient)",
               "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x7a9);
    return iVar5;
  }
  if (((lVar3 == 0) || (*(long *)(lVar3 + 0x1bc0) == 0)) ||
     (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar3), cVar4 == '\0')) {
    plVar7 = (long *)kgraphicsGetStaticInfo_IMPL(lVar3,*(undefined8 *)(lVar3 + 0x1bd0));
    if (plVar7 == (long *)0x0) {
      nvAssertFailedNoLog("pKernelGraphicsStaticInfo != NULL",
                          "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x7af);
      return 0x40;
    }
    uVar6 = gpuGetLitterValues_KERNEL(lVar3,0x14);
    if (uVar6 <= uVar1) {
      return 0x1f;
    }
    param_2[1] = *(uint *)((long)plVar7 + (ulong)uVar1 * 4 + 0x12b4);
    if (plVar7[0x278] != 0) {
      param_2[2] = *(uint *)(plVar7[0x278] + (ulong)uVar1 * 4);
      param_2[3] = *(uint *)(*plVar7 + 0xbc);
      portMemCopy(param_2 + 4,0x28,(long)plVar7 + 0x128c,0x28);
      return 0;
    }
  }
  else {
    nvCheckFailedNoLog(1,"!IS_MIG_IN_USE(pGpu)",
                       "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x7ac);
  }
  return 0x56;
}


// ===== 004362b0 subdeviceCtrlCmdGpuHandleGpuSR_IMPL =====

undefined8 subdeviceCtrlCmdGpuHandleGpuSR_IMPL(void)

{
  return 0;
}


// ===== 004362c0 subdeviceCtrlCmdGpuSetComputeModeRules_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong subdeviceCtrlCmdGpuSetComputeModeRules_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x7e1);
    return 0x2f;
  }
  if (*(char *)(lVar1 + 0x909) != '\0') {
    lVar5 = resservGetTlsCallContext();
    puVar2 = *(undefined4 **)(lVar5 + 0x48);
    uVar4 = (**(code **)(lVar1 + 0x3b90))
                      (lVar1 + 0x3b58,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                       puVar2[6]);
    if (uVar4 != 0) {
      nvAssertOkFailedNoLog
                (uVar4,
                 "pRmApi->Control(pRmApi, pRmCtrlParams->hClient, pRmCtrlParams->hObject, pRmCtrlParams->cmd, pRmCtrlParams->pParams, pRmCtrlParams->paramsSize)"
                 ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x7ed);
      return (ulong)uVar4;
    }
  }
  if ((*(long *)(lVar1 + 0x1bc0) != 0) && (cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar1), cVar3 != '\0'))
  {
    return 0x56;
  }
  lVar5 = gpuGetStaticInfo(lVar1);
  if (((lVar5 != 0) && (*(char *)(lVar1 + 0x909) == '\0')) && (*(int *)(lVar5 + 0xa6f8) == 0)) {
    return 0x56;
  }
  uVar6 = 0x1f;
  if (*param_2 < 4) {
    *(uint *)(lVar1 + 0x1b1c) = *param_2;
    uVar6 = osWriteRegistryDword(lVar1,"RmComputeModeRules");
    if ((int)uVar6 != 0) {
      nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x817,
                   "subdeviceCtrlCmdGpuSetComputeModeRules_IMPL",4,
                   "NVRM: Could not store compute mode rule in the registry, current setting may not persist if all clients disconnect!\n"
                  );
      return 0;
    }
  }
  return uVar6;
}


// ===== 00436450 subdeviceCtrlCmdGpuQueryComputeModeRules_IMPL =====

undefined8 subdeviceCtrlCmdGpuQueryComputeModeRules_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  long lVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x834);
    return 0x2f;
  }
  lVar3 = gpuGetStaticInfo(lVar1);
  if (((lVar3 != 0) && (*(char *)(lVar1 + 0x909) == '\0')) && (*(int *)(lVar3 + 0xa6f8) == 0)) {
    *param_2 = 2;
    return 0;
  }
  *param_2 = *(undefined4 *)(lVar1 + 0x1b1c);
  return 0;
}


// ===== 004364f0 subdeviceCtrlCmdGpuAcquireComputeModeReservation_IMPL =====

undefined4 subdeviceCtrlCmdGpuAcquireComputeModeReservation_IMPL(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  char cVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  cVar4 = rmapiLockIsOwner();
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x851);
    return 0x2f;
  }
  if (((lVar3 != 0) && (*(long *)(lVar3 + 0x1bc0) != 0)) &&
     (cVar4 = kmigmgrIsMIGEnabled_IMPL(lVar3), cVar4 != '\0')) {
    return 0x56;
  }
  uVar2 = *(uint *)(lVar3 + 0x1b1c);
  if (uVar2 == 2) {
    return 99;
  }
  if (uVar2 < 3) {
    if (uVar2 == 0) goto LAB_00436565;
  }
  else if (uVar2 != 3) {
    nvAssertFailedNoLog(&DAT_00d78956,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x880);
    return 0;
  }
  if (*(int *)(lVar3 + 0x1b24) != 0) {
    return 99;
  }
LAB_00436565:
  *(undefined4 *)(lVar3 + 0x1b24) = uVar1;
  return 0;
}


// ===== 004365e0 subdeviceCtrlCmdGpuReleaseComputeModeReservation_IMPL =====

undefined8 subdeviceCtrlCmdGpuReleaseComputeModeReservation_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  iVar1 = *(int *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x890);
    return 0x2f;
  }
  if (((lVar2 != 0) && (*(long *)(lVar2 + 0x1bc0) != 0)) &&
     (cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar2), cVar3 != '\0')) {
    return 0x56;
  }
  uVar4 = 99;
  if (*(int *)(lVar2 + 0x1b24) == iVar1) {
    *(undefined4 *)(lVar2 + 0x1b24) = 0;
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 00436680 subdeviceCtrlCmdGpuGetId_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetId_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    *param_2 = *(undefined4 *)(lVar1 + 0x7ac);
    return 0;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                      0x8b5);
  return 0x2f;
}


// ===== 004366f0 subdeviceCtrlCmdGpuGetPids_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetPids_IMPL(long param_1,int *param_2)

{
  long lVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 local_48 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x8d0);
    return 0x2f;
  }
  if (*param_2 == 0) {
    uVar3 = 0x4b01b3;
    if ((param_2[1] != 0x2080) && (uVar3 = 0x22ce42, param_2[1] != 0x900e)) {
      uVar3 = 0x43d7c4;
    }
  }
  else {
    if (*param_2 != 1) {
      return 0x1f;
    }
    uVar3 = 0xb12d7d;
  }
  uVar6 = *(undefined8 *)(lVar1 + 0x1bc0);
  lVar5 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar5 != 0) {
    local_48 = kmigmgrMakeNoMIGReference_IMPL();
    if (*(long *)(lVar1 + 0x1bc0) != 0) {
      cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
      if (cVar2 != '\0') {
        cVar2 = rmclientIsCapable_IMPL(lVar5,3);
        if (cVar2 == '\0') {
          iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL
                            (lVar1,uVar6,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),local_48
                            );
          if (iVar4 != 0) {
            nvCheckFailedNoLog(1,
                               "(kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, pRef) == NV_OK)"
                               ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x902);
            return 0x1b;
          }
        }
      }
    }
    uVar6 = gpuGetProcWithObject_IMPL(lVar1,param_2[1],uVar3,param_2 + 3,param_2 + 2);
    return uVar6;
  }
  nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                      0x8f5);
  return 0x23;
}


// ===== 00436940 subdeviceCtrlCmdGpuGetPidInfo_IMPL =====

undefined4 subdeviceCtrlCmdGpuGetPidInfo_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  undefined1 local_49;
  undefined1 local_48 [16];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') || (cVar3 = rmGpuLockIsOwner(), cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x92a);
    return 0x2f;
  }
  if (199 < *param_2 - 1) {
    return 0x1f;
  }
  uVar2 = *(undefined8 *)(lVar1 + 0x1bc0);
  lVar6 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pRmClient != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0x93a);
    return 0x23;
  }
  local_48 = kmigmgrMakeNoMIGReference_IMPL();
  if (*(long *)(lVar1 + 0x1bc0) != 0) {
    cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    if (cVar3 != '\0') {
      cVar3 = rmclientIsCapable_IMPL(lVar6,3);
      if (cVar3 == '\0') {
        iVar5 = kmigmgrGetInstanceRefFromDevice_IMPL
                          (lVar1,uVar2,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),local_48);
        local_49 = 0;
        if (iVar5 != 0) {
          nvCheckFailedNoLog(1,
                             "(kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, pRef) == NV_OK)"
                             ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x947);
          return 0x1b;
        }
        goto LAB_004369ff;
      }
    }
  }
  local_49 = 1;
LAB_004369ff:
  if (*param_2 != 0) {
    puVar9 = param_2 + 6;
    uVar7 = 0;
    do {
      while (uVar4 = param_2[(ulong)uVar7 * 0x12 + 3],
            (param_2 + (ulong)uVar7 * 0x12 + 0x12)[0] = 0xffffffff,
            (param_2 + (ulong)uVar7 * 0x12 + 0x12)[1] = 0xffffffff, uVar4 == 0) {
        uVar8 = uVar7 + 1;
        portMemSet(puVar9,0,0x30);
        uVar4 = gpuFindClientInfoWithPidIterator_IMPL
                          (lVar1,param_2[(ulong)uVar7 * 0x12 + 2],0,0x4789f2,puVar9,puVar9 + 0xc,
                           local_48,local_49);
        param_2[(ulong)uVar7 * 0x12 + 4] = uVar4;
        puVar9 = puVar9 + 0x12;
        uVar7 = uVar8;
        if (*param_2 <= uVar8) {
          return 0;
        }
      }
      param_2[(ulong)uVar7 * 0x12 + 4] = 0x1f;
      uVar7 = uVar7 + 1;
      puVar9 = puVar9 + 0x12;
    } while (uVar7 < *param_2);
  }
  return 0;
}


// ===== 00436bb0 subdeviceCtrlCmdGpuGetEngineRunlistPriBase_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGpuGetEngineRunlistPriBase_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 extraout_RDX;
  char *pcVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = gpuGetKernelFifoShared_IMPL(lVar1);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    iVar7 = 0x2f;
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x97e);
  }
  else {
    iVar7 = 0x56;
    if (*(char *)(lVar4 + 0x4b2) != '\0') {
      iVar7 = 0;
      puVar8 = (undefined4 *)(param_2 + 0x2a0);
      do {
        while ((puVar8[-0xa8] == 0 || (puVar8[-0xa8] == 0x22))) {
          puVar8[-0x54] = 0xffffffff;
          puVar9 = puVar8 + 1;
          *puVar8 = 0xffffffff;
          puVar8 = puVar9;
          if (puVar9 == (undefined4 *)(param_2 + 0x3f0)) {
            return iVar7;
          }
        }
        local_4c = gpuGetRmEngineType_IMPL();
        if (((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) &&
           (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL
                              (lVar1,*(long *)(lVar1 + 0x1bc0),extraout_RDX,local_4c), cVar2 != '\0'
           )) {
          uVar6 = *(undefined8 *)(lVar1 + 0x1bc0);
          iVar3 = kmigmgrGetInstanceRefFromDevice_IMPL
                            (lVar1,uVar6,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),
                             &local_48);
          if (iVar3 != 0) {
            uVar6 = 0x99f;
            pcVar5 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
LAB_00436d9d:
            nvCheckOkFailedNoLog
                      (4,iVar3,pcVar5,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",uVar6);
            return iVar3;
          }
          iVar3 = kmigmgrGetLocalToGlobalEngineType_IMPL
                            (lVar1,uVar6,local_48,local_40,local_4c,&local_4c);
          if (iVar3 != 0) {
            uVar6 = 0x9a4;
            pcVar5 = 
            "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &rmEngineType)"
            ;
            goto LAB_00436d9d;
          }
        }
        iVar3 = (**(code **)(lVar4 + 0x218))(lVar1,lVar4,2,local_4c,0xb,puVar8 + -0x54);
        if (iVar3 != 0) {
          puVar8[-0x54] = 0xfffffffb;
          *puVar8 = 0xfffffffb;
          iVar7 = iVar3;
        }
        iVar3 = (**(code **)(lVar4 + 0x218))(lVar1,lVar4,2,local_4c,3,puVar8);
        if (iVar3 != 0) {
          puVar8[-0x54] = 0xfffffffb;
          *puVar8 = 0xfffffffb;
          iVar7 = iVar3;
        }
        puVar8 = puVar8 + 1;
      } while (puVar8 != (undefined4 *)(param_2 + 0x3f0));
    }
  }
  return iVar7;
}


// ===== 00436e00 subdeviceCtrlCmdGpuGetHwEngineId_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGpuGetHwEngineId_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 extraout_RDX;
  char *pcVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = gpuGetKernelFifoShared_IMPL(lVar1);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    iVar7 = 0x2f;
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x9d3);
  }
  else {
    iVar7 = 0x56;
    if (*(char *)(lVar4 + 0x4b2) != '\0') {
      iVar7 = 0;
      puVar8 = (undefined4 *)(param_2 + 0x150);
      do {
        while ((puVar8[-0x54] == 0 || (puVar8[-0x54] == 0x22))) {
          *puVar8 = 0xffffffff;
          puVar8 = puVar8 + 1;
          if ((undefined4 *)(param_2 + 0x2a0) == puVar8) {
            return iVar7;
          }
        }
        local_4c = gpuGetRmEngineType_IMPL();
        if (((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) &&
           (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL
                              (lVar1,*(long *)(lVar1 + 0x1bc0),extraout_RDX,local_4c), cVar2 != '\0'
           )) {
          uVar6 = *(undefined8 *)(lVar1 + 0x1bc0);
          iVar3 = kmigmgrGetInstanceRefFromDevice_IMPL
                            (lVar1,uVar6,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),
                             &local_48);
          if (iVar3 != 0) {
            uVar6 = 0x9f3;
            pcVar5 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
LAB_00436f8d:
            nvCheckOkFailedNoLog
                      (4,iVar3,pcVar5,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",uVar6);
            return iVar3;
          }
          iVar3 = kmigmgrGetLocalToGlobalEngineType_IMPL
                            (lVar1,uVar6,local_48,local_40,local_4c,&local_4c);
          if (iVar3 != 0) {
            uVar6 = 0x9f8;
            pcVar5 = 
            "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &rmEngineType)"
            ;
            goto LAB_00436f8d;
          }
        }
        iVar3 = (**(code **)(lVar4 + 0x218))(lVar1,lVar4,2,local_4c,1,puVar8);
        if (iVar3 != 0) {
          *puVar8 = 0xfffffffb;
          iVar7 = iVar3;
        }
        puVar8 = puVar8 + 1;
      } while ((undefined4 *)(param_2 + 0x2a0) != puVar8);
    }
  }
  return iVar7;
}


// ===== 00436ff0 subdeviceCtrlCmdGpuGetMaxSupportedPageSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdGpuGetMaxSupportedPageSize_IMPL(long param_1,ulong *param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (((cVar2 == '\0') ||
      (cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar5 + 0x7a4)), cVar2 == '\0')) &&
     (cVar2 = rmapiInRtd3PmPath(), cVar2 == '\0')) {
    nvAssertFailedNoLog("(rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)) || rmapiInRtd3PmPath()"
                        ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xa17);
    return 0x2f;
  }
  *param_2 = 0x1000;
  if (*(char *)(lVar5 + 0x908) == '\0') {
    if (*(char *)(lVar5 + 0x4913) != '\0') {
LAB_004370bc:
      if (*(char *)(lVar5 + 0x491e) != '\0') goto LAB_004370c5;
    }
    lVar1 = *(long *)(lVar5 + 0x1b98);
    uVar4 = 0x4000000000;
    if (((*(char *)(lVar1 + 0x67d2) == '\0') &&
        (uVar4 = 0x20000000, *(char *)(lVar1 + 0x67d1) == '\0')) &&
       (uVar4 = 0x200000, *(char *)(lVar1 + 0x67d0) == '\0')) {
      uVar3 = (**(code **)(lVar1 + 0x198))();
      uVar4 = (ulong)uVar3;
    }
    *param_2 = uVar4;
    if ((((*(char *)(lVar5 + 0x491d) != '\0') || (*(char *)(lVar5 + 0x4913) != '\0')) ||
        (cVar2 = gpuIsCCFeatureEnabled_IMPL(lVar5), cVar2 != '\0')) &&
       (*(long *)(lVar5 + 0x3b10) - 1U < 0x3fffffff)) {
      *param_2 = 0x200000;
    }
  }
  else {
    if (*(char *)(lVar5 + 0x4913) != '\0') goto LAB_004370bc;
LAB_004370c5:
    lVar5 = gpuGetStaticInfo(lVar5);
    *param_2 = *(ulong *)(lVar5 + 0xa7c8);
  }
  return 0;
}


// ===== 00437150 subdeviceCtrlCmdGpuSetComputePolicyConfig_IMPL =====

undefined8 subdeviceCtrlCmdGpuSetComputePolicyConfig_IMPL(long param_1,int *param_2)

{
  long lVar1;
  undefined8 uVar2;
  uint local_c;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*param_2 == 0) {
    if (*(char *)(lVar1 + 0x4a30) == '\0') {
      nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xa8f,
                   "subdeviceCtrlCmdGpuSetComputePolicyConfig_IMPL",4,
                   "NVRM: Setting the timeslice policy is not supported for gpu with pci id 0x%llx\n"
                   ,*(undefined8 *)(lVar1 + 0x878));
      return 0x56;
    }
    local_c = param_2[1];
    if (local_c < 4) {
      uVar2 = gpuGetGidInfo_IMPL(lVar1,0,0,2);
      if ((int)uVar2 == 0) {
        if (*(char *)(lVar1 + 0x7c4) == '\0') {
          nvAssertFailedNoLog("pGpu->gpuUuid.isInitialized",
                              "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xaac);
        }
        uVar2 = gpudbSetGpuComputePolicyConfig(lVar1 + 0x7c5,*param_2,&local_c);
      }
      return uVar2;
    }
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xa97,
                 "subdeviceCtrlCmdGpuSetComputePolicyConfig_IMPL",4,
                 "NVRM: Unsupported timeslice value %u specified for gpu with pci id 0x%llx\n",
                 local_c,*(undefined8 *)(lVar1 + 0x878));
  }
  else {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xa9f,
                 "subdeviceCtrlCmdGpuSetComputePolicyConfig_IMPL",4,
                 "NVRM: Unsupported compute policy %u specified for gpu id 0x%llx\n",*param_2,
                 *(undefined8 *)(lVar1 + 0x878));
  }
  return 0x1f;
}


// ===== 004372c0 subdeviceCtrlCmdGpuGetComputePolicyConfig_IMPL =====

void subdeviceCtrlCmdGpuGetComputePolicyConfig_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  undefined4 local_1c;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  iVar2 = gpuGetGidInfo_IMPL(lVar1,0,0,2);
  if (iVar2 == 0) {
    if (*(char *)(lVar1 + 0x7c4) == '\0') {
      nvAssertFailedNoLog("pGpu->gpuUuid.isInitialized",
                          "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xad9);
    }
    iVar2 = gpudbGetGpuComputePolicyConfigs(lVar1 + 0x7c5,&local_1c);
    if (iVar2 == 0) {
      *param_2 = 1;
      *(undefined4 *)(param_2 + 1) = local_1c;
    }
  }
  return;
}


// ===== 00437350 subdeviceCtrlCmdValidateMemMapRequest_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong subdeviceCtrlCmdValidateMemMapRequest_IMPL(long param_1,ulong *param_2)

{
  ulong uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint local_44;
  ulong local_40 [2];
  
  uVar7 = *param_2;
  uVar8 = param_2[1];
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if ((cVar3 == '\0') ||
     (cVar3 = rmDeviceGpuLockIsOwner
                        (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7a4)),
     cVar3 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(GPU_RES_GET_GPU(pSubdevice)->gpuInstance)"
                        ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xb37);
    return 0x2f;
  }
  uVar8 = uVar8 - 1;
  *(undefined4 *)(param_2 + 2) = 3;
  if (CARRY8(uVar7,uVar8)) {
LAB_00437546:
    return (ulong)(-(uint)(*(long *)(*(long *)(lVar2 + 0x1b70) + 0x478) == 0) & 0x5f);
  }
  uVar6 = *(ulong *)(lVar2 + 0x848);
  uVar1 = *(long *)(lVar2 + 0x948) + -1 + uVar6;
  if (((uVar1 < uVar6) || (uVar1 < uVar7 + uVar8)) || (uVar7 < uVar6)) {
    uVar1 = *(long *)(lVar2 + 0x910) + -1 + *(ulong *)(lVar2 + 0x850);
    uVar6 = uVar7;
    if (uVar1 < uVar7) {
      uVar6 = uVar1;
    }
    if ((*(ulong *)(lVar2 + 0x850) <= uVar6) && (uVar7 + uVar8 <= uVar1)) {
      return 0;
    }
    goto LAB_00437546;
  }
  uVar7 = uVar7 - uVar6;
  iVar4 = (**(code **)(*(long *)(lVar2 + 0x1b88) + 0x1f8))
                    (lVar2,*(long *)(lVar2 + 0x1b88),local_40,&local_44);
  if (iVar4 == 0) {
    if (CARRY8(uVar7,uVar8)) {
      lVar5 = gpuGetKernelFifoShared_IMPL(lVar2);
      iVar4 = (**(code **)(lVar5 + 0x1e0))(lVar2,lVar5,local_40,&local_44,*(code **)(lVar5 + 0x1e0))
      ;
      if (iVar4 == 0) {
LAB_004376a6:
        (**(code **)(*(long *)(lVar2 + 0x1b60) + 0x178))
                  (lVar2,*(long *)(lVar2 + 0x1b60),local_40,&local_44);
        goto LAB_004374d0;
      }
      goto LAB_00437640;
    }
    uVar1 = (local_40[0] - 1) + (ulong)local_44;
    uVar6 = uVar1;
    if (uVar7 <= uVar1) {
      uVar6 = uVar7;
    }
    if ((local_40[0] <= uVar6) && (uVar7 + uVar8 <= uVar1)) goto LAB_0043759c;
    lVar5 = gpuGetKernelFifoShared_IMPL(lVar2);
    iVar4 = (**(code **)(lVar5 + 0x1e0))(lVar2,lVar5,local_40,&local_44);
    if (iVar4 == 0) goto LAB_004375ea;
    iVar4 = (**(code **)(*(long *)(lVar2 + 0x1b60) + 0x178))
                      (lVar2,*(long *)(lVar2 + 0x1b60),local_40,&local_44);
joined_r0x0043762b:
    if (iVar4 != 0) goto LAB_004374d0;
  }
  else {
    lVar5 = gpuGetKernelFifoShared_IMPL(lVar2);
    iVar4 = (**(code **)(lVar5 + 0x1e0))(lVar2,lVar5,local_40,&local_44,*(code **)(lVar5 + 0x1e0));
    if (iVar4 == 0) {
      if (CARRY8(uVar8,uVar7)) goto LAB_004376a6;
LAB_004375ea:
      uVar1 = ((ulong)local_44 - 1) + local_40[0];
      uVar6 = uVar1;
      if (uVar7 <= uVar1) {
        uVar6 = uVar7;
      }
      if ((local_40[0] <= uVar6) && (uVar7 + uVar8 <= uVar1)) {
        return 0;
      }
      iVar4 = (**(code **)(*(long *)(lVar2 + 0x1b60) + 0x178))
                        (lVar2,*(long *)(lVar2 + 0x1b60),local_40,&local_44);
      goto joined_r0x0043762b;
    }
LAB_00437640:
    iVar4 = (**(code **)(*(long *)(lVar2 + 0x1b60) + 0x178))
                      (lVar2,*(long *)(lVar2 + 0x1b60),local_40,&local_44);
    if ((iVar4 != 0) || (CARRY8(uVar8,uVar7))) goto LAB_004374d0;
  }
  uVar1 = ((ulong)local_44 - 1) + local_40[0];
  uVar6 = uVar7;
  if (uVar1 < uVar7) {
    uVar6 = uVar1;
  }
  if ((local_40[0] <= uVar6) && (uVar7 + uVar8 <= uVar1)) {
LAB_0043759c:
    *(undefined4 *)(param_2 + 2) = 1;
    return 0;
  }
LAB_004374d0:
  if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
    return 0x5f;
  }
  uVar7 = (**(code **)(lVar2 + 0x3b90))
                    (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),*(undefined4 *)(lVar2 + 0x3b3c),
                     0x20800198,param_2,0x18);
  return uVar7;
}


// ===== 004376d0 subdeviceCtrlCmdGpuGetGfid_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetGfid_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  uint uVar5;
  
  lVar2 = g_pSys;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      if (((*(char *)(lVar1 + 0x491d) != '\0') && (*(char *)(lVar1 + 0x908) == '\0')) &&
         (*(char *)(lVar2 + 0x6b) != '\0')) {
        uVar5 = (((uint)*(byte *)(param_2 + 5) << 3 | (uint)*(byte *)(param_2 + 6)) -
                *(int *)(lVar1 + 0x3a5c)) + 1;
        if (*(uint *)(lVar1 + 0x3a60) < uVar5) {
          nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xbab,
                       "subdeviceCtrlCmdGpuGetGfid_IMPL",4,
                       "NVRM: Computed GFID %d greater than max supported GFID\n");
          uVar4 = 0x40;
        }
        else {
          *(uint *)(param_2 + 8) = uVar5;
          *(int *)(param_2 + 0xc) = *(int *)(lVar1 + 0x3a60) + -1;
          uVar4 = 0;
        }
        return uVar4;
      }
      return 0x56;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xb97);
  return 0x2f;
}


// ===== 004377e0 gpuUpdateGfidP2pCapability =====

undefined8 gpuUpdateGfidP2pCapability(long param_1,uint *param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  lVar1 = g_pSys;
  puVar4 = *(uint **)(param_1 + 0x3af8);
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') || (cVar2 = rmGpuLockIsOwner(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xbda);
    return 0x2f;
  }
  if (*(char *)(param_1 + 0x491d) != '\0') {
    if (puVar4 == (uint *)0x0) {
      nvAssertFailedNoLog("pP2PInfo != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                          0xbdf);
      return 0x40;
    }
    if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(lVar1 + 0x6b) != '\0')) {
      uVar3 = *param_2;
      if (*(uint *)(param_1 + 0x3a60) < uVar3) {
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xbe7,
                     "gpuUpdateGfidP2pCapability",4,
                     "NVRM: Input GFID %d greater than max allowed GFID\n");
        return 0x1f;
      }
      if (*(uint *)(param_1 + 0x3b04) != 0) {
        uVar6 = *puVar4;
        puVar5 = puVar4 + (ulong)*(uint *)(param_1 + 0x3b04) * 4;
        if ((char)param_2[1] == '\0') {
          while (uVar3 != uVar6) {
            puVar4 = puVar4 + 4;
            if (puVar4 == puVar5) {
              return 0x17;
            }
            uVar6 = *puVar4;
          }
          *puVar4 = 0xffffffff;
          uVar3 = 0xffffffff;
        }
        else {
          while (uVar6 != 0xffffffff) {
            puVar4 = puVar4 + 4;
            if (puVar5 == puVar4) {
              return 0x17;
            }
            uVar6 = *puVar4;
          }
          *puVar4 = uVar3;
          uVar3 = param_2[2];
        }
        *(uint *)(param_1 + 0x3b08) = uVar3;
        *(char *)(puVar4 + 1) = (char)param_2[1];
        return 0;
      }
      return 0x17;
    }
  }
  return 0x56;
}


// ===== 004379a0 subdeviceCtrlCmdUpdateGfidP2pCapability_IMPL =====

void subdeviceCtrlCmdUpdateGfidP2pCapability_IMPL(long param_1)

{
  gpuUpdateGfidP2pCapability(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 004379c0 subdeviceCtrlCmdGpuGetEngineLoadTimes_IMPL =====

undefined4 subdeviceCtrlCmdGpuGetEngineLoadTimes_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar1 = *(uint *)(lVar2 + 0x8c8);
  if (199 < uVar1) {
    nvAssertFailedNoLog("numEngDescriptors < NV2080_CTRL_GPU_MAX_ENGINE_OBJECTS",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xc3b);
    return 2;
  }
  lVar3 = *(long *)(lVar2 + 0x8a8);
  *param_2 = uVar1;
  if (uVar1 != 0) {
    uVar5 = 0;
    do {
      lVar4 = gpuGetEngstate_IMPL(lVar2,*(undefined4 *)(lVar3 + uVar5 * 4));
      if (lVar4 != 0) {
        param_2[uVar5 + 1] = *(uint *)(lVar4 + 0x4c);
        *(ulong *)(param_2 + uVar5 * 2 + 0xca) = (ulong)(uint)(*(int *)(lVar4 + 0xa0) * 1000);
      }
      *(bool *)((long)param_2 + uVar5 + 0x968) = lVar4 != 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 != uVar1);
  }
  return 0;
}


// ===== 00437ac0 subdeviceCtrlCmdGpuSetFabricAddr_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdGpuSetFabricAddr_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),
                             __nvoc_class_def_RmClient);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                        0xc60);
    return 0x23;
  }
  lVar4 = resservGetTlsCallContext();
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pCallContext != NULL",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xc65);
    uVar5 = 0x40;
  }
  else {
    cVar2 = rmapiLockIsOwner();
    if ((cVar2 != '\0') && (cVar2 = rmGpuLockIsOwner(), cVar2 != '\0')) {
      cVar2 = rmclientIsCapableOrAdmin_IMPL(lVar3,0x200,*(undefined4 *)(lVar4 + 0x28));
      if (cVar2 == '\0') {
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xc6d,
                     "subdeviceCtrlCmdGpuSetFabricAddr_IMPL",4,
                     "NVRM: Non-privileged context issued privileged cmd\n");
        return 0x1b;
      }
      lVar3 = *(long *)(lVar1 + 0x1ce8);
      if (lVar3 == 0) {
        return 0x56;
      }
      uVar5 = (**(code **)(lVar3 + 0x178))(lVar1,lVar3,*param_2);
      return uVar5;
    }
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xc67);
    uVar5 = 0x2f;
  }
  return uVar5;
}


// ===== 00437c80 subdeviceCtrlCmdGetGpuFabricProbeInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rbx replaced with injection: x86_indirect_thunk_rbx */
/* WARNING: Type propagation algorithm not settling */

int subdeviceCtrlCmdGetGpuFabricProbeInfo_IMPL(long param_1,char *param_2)

{
  long *plVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined8 extraout_RDX;
  ulong uVar8;
  ulong uVar9;
  uint uVar10;
  uint local_74;
  long local_70;
  ulong local_68 [9];
  
  local_70 = 0;
  local_68[0] = 0;
  local_74 = 0;
  lVar5 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') ||
     (cVar2 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar5 + 0x7a4)), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(gpuGetInstance(pGpu))",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xcd3);
    return 0x2f;
  }
  cVar2 = gpuFabricProbeIsSupported(lVar5);
  if (cVar2 == '\0') {
    *param_2 = '\0';
    return 0;
  }
  if (*(long *)(lVar5 + 0x4c0) == 0) {
    *param_2 = '\x03';
    param_2[4] = 'V';
    param_2[5] = '\0';
    param_2[6] = '\0';
    param_2[7] = '\0';
    return 0;
  }
  iVar3 = gpuFabricProbeGetNumProbeReqs(*(long *)(lVar5 + 0x4c0),&local_70);
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xcea,
                 "subdeviceCtrlCmdGetGpuFabricProbeInfo_IMPL",4,
                 "NVRM: Error while retrieving numProbeReqs\n");
    return iVar3;
  }
  *param_2 = '\x02' - (local_70 == 0);
  cVar2 = gpuFabricProbeIsReceived(*(undefined8 *)(lVar5 + 0x4c0));
  if (cVar2 == '\0') {
    return 0;
  }
  *param_2 = '\x03';
  iVar3 = gpuFabricProbeGetFmStatus(*(undefined8 *)(lVar5 + 0x4c0));
  *(int *)(param_2 + 4) = iVar3;
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = gpuFabricProbeGetClusterUuid(*(undefined8 *)(lVar5 + 0x4c0),param_2 + 8);
  uVar6 = 0xd02;
  if (iVar3 != 0) {
LAB_00437fc1:
    nvAssertOkFailedNoLog
              (iVar3,"status","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",uVar6);
    return iVar3;
  }
  iVar3 = gpuFabricProbeGetFabricPartitionId
                    (*(undefined8 *)(lVar5 + 0x4c0),param_2 + 0x18,extraout_RDX,0xd02);
  if (iVar3 != 0) {
    uVar6 = 0xd06;
    goto LAB_00437fc1;
  }
  iVar3 = gpuFabricProbeGetfmCaps(*(undefined8 *)(lVar5 + 0x4c0),local_68);
  uVar6 = 0xd09;
  if (iVar3 != 0) goto LAB_00437fc1;
  cVar2 = gpuIsCCMultiGpuProtectedPcieModeEnabled_IMPL(lVar5);
  if ((cVar2 == '\0') && (cVar2 = gpuIsCCMultiGpuNvleModeEnabled_IMPL(lVar5), cVar2 == '\0')) {
    uVar8 = 0;
    if (local_68[0] != 0) {
      iVar3 = 0;
      uVar4 = local_68[0];
      while( true ) {
        for (; (uVar4 & 1) == 0; uVar4 = uVar4 >> 1) {
          iVar3 = iVar3 + 1;
        }
        if (iVar3 == 5) {
          uVar8 = uVar8 | 3;
        }
        else {
          uVar9 = 1L << ((byte)iVar3 & 0x3f);
          if (uVar9 < 0x21) {
            if (uVar9 - 1 < 2) {
              uVar8 = uVar8 | 1;
            }
          }
          else if (iVar3 == 9) {
            uVar8 = uVar8 | 4;
          }
        }
        if (uVar4 >> 1 == 0) break;
        iVar3 = iVar3 + 1;
        uVar4 = uVar4 >> 1;
      }
    }
    *(ulong *)(param_2 + 0x20) = uVar8;
  }
  iVar3 = gpuFabricProbeGetFabricCliqueId(*(undefined8 *)(lVar5 + 0x4c0),param_2 + 0x28);
  uVar6 = 0xd12;
  if (iVar3 != 0) goto LAB_00437fc1;
  iVar3 = gpuFabricProbeGetFabricHealthStatus(*(undefined8 *)(lVar5 + 0x4c0),&local_74);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"status","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xd16);
    return iVar3;
  }
  uVar10 = 1;
  if ((local_74 & 3) != 1) {
    uVar10 = (uint)((local_74 & 3) == 2) * 2;
  }
  if ((local_74 & 0xc) == 4) {
    uVar10 = uVar10 | 4;
  }
  else if ((local_74 & 0xc) == 8) {
    uVar10 = uVar10 | 8;
  }
  if ((local_74 & 0x30) == 0x10) {
    uVar10 = uVar10 | 0x10;
  }
  else if ((local_74 & 0x30) == 0x20) {
    uVar10 = uVar10 | 0x20;
  }
  uVar7 = local_74 & 0xf00;
  if (uVar7 == 0x100) {
    uVar10 = uVar10 | 0x100;
  }
  else if (uVar7 == 0x200) {
    uVar10 = uVar10 | 0x200;
  }
  else if (uVar7 == 0x300) {
    uVar10 = uVar10 | 0x300;
  }
  else if (uVar7 == 0x400) {
    uVar10 = uVar10 | 0x400;
  }
  else if (uVar7 == 0x500) {
    uVar10 = uVar10 | 0x500;
  }
  else if (uVar7 == 0x600) {
    uVar10 = uVar10 | 0x600;
  }
  else if (uVar7 == 0x700) {
    uVar10 = uVar10 | 0x700;
  }
  else if (uVar7 == 0x800) {
    uVar10 = (uint)CONCAT11(8,(char)uVar10);
  }
  if ((local_74 & 0x3000) == 0x1000) {
    uVar10 = uVar10 | 0x1000;
    if (0x19f < *(uint *)(lVar5 + 0x808)) goto LAB_00438116;
LAB_00437ff9:
    *(uint *)(param_2 + 0x2c) = uVar10;
LAB_00437ffd:
    if (((local_74 & 0x30) != 0x10) && ((local_74 & 0xc0) != 0x40)) {
LAB_0043801c:
      if (((local_74 & 0xe00) == 0) && ((local_74 & 0x3000) != 0x2000)) {
        if ((local_74 & 3) == 1) {
          cVar2 = '\x03';
        }
        else {
          cVar2 = ((local_74 & 0xc) == 4) * '\x02' + '\x01';
        }
        goto LAB_00437f2e;
      }
    }
  }
  else {
    if ((local_74 & 0x3000) != 0x2000) {
      if (0x19f < *(uint *)(lVar5 + 0x808)) goto LAB_00438116;
      *(uint *)(param_2 + 0x2c) = uVar10;
      cVar2 = '\0';
      if (local_74 == 0) goto LAB_00437f2e;
      goto LAB_00437ffd;
    }
    uVar10 = uVar10 | 0x2000;
    if (*(uint *)(lVar5 + 0x808) < 0x1a0) goto LAB_00437ff9;
LAB_00438116:
    lVar5 = rmapiGetInterface(4);
    plVar1 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
    iVar3 = (**(code **)(lVar5 + 0x38))
                      (lVar5,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],0x20803088,local_68 + 1,
                       0x38);
    if (iVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar3,
                 "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_NVLINK_GET_LOCAL_DEVICE_INFO, &localDeviceInfoParams, sizeof(localDeviceInfoParams))"
                 ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xda5);
      return iVar3;
    }
    if ((local_68[7] & 2) != 0) {
      local_74 = local_74 | 0x40;
      uVar10 = uVar10 | 0x40;
      goto LAB_00437ff9;
    }
    *(uint *)(param_2 + 0x2c) = uVar10 | 0x80;
    if ((local_74 & 0x30) != 0x10) goto LAB_0043801c;
  }
  cVar2 = '\x02';
LAB_00437f2e:
  param_2[0x30] = cVar2;
  return 0;
}


// ===== 00438260 subdeviceCtrlCmdGspGetFeatures_KERNEL =====

undefined8 subdeviceCtrlCmdGspGetFeatures_KERNEL(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 4) = 0;
  return 0;
}


// ===== 00438270 subdeviceCtrlCmdGpuGetNameString_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdGpuGetNameString_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      uVar3 = (**(code **)(lVar1 + 0xa8))(lVar1,param_2 + 4);
      return uVar3;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xdf1);
  return 0x2f;
}


// ===== 004382f0 subdeviceCtrlCmdGpuGetShortNameString_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdGpuGetShortNameString_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    cVar2 = rmGpuLockIsOwner();
    if (cVar2 != '\0') {
      uVar3 = (**(code **)(lVar1 + 0xb0))(lVar1,param_2);
      return uVar3;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xe05);
  return 0x2f;
}


// ===== 00438360 subdeviceCtrlCmdGpuGetGidInfo_IMPL =====

int subdeviceCtrlCmdGpuGetGidInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  uint local_24;
  undefined8 local_20 [2];
  
  local_20[0] = 0;
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = param_2[1] & 0x38;
  if (uVar2 == 0) {
    iVar3 = gpuGetGidInfo_IMPL(uVar1,local_20,&local_24);
  }
  else {
    if (uVar2 != 8) {
      return 0x3b;
    }
    iVar3 = gpuGetUgidInfo_IMPL(uVar1,local_20,&local_24,param_2[1],*param_2);
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  if (local_24 < 0x101) {
    portMemCopy(param_2 + 3,local_24,local_20[0],local_24);
    param_2[2] = local_24;
    iVar3 = 0;
  }
  else {
    iVar3 = 0x1a;
  }
  portMemFree(local_20[0]);
  return iVar3;
}


// ===== 00438430 subdeviceCtrlCmdGpuReportNonReplayableFault_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdGpuReportNonReplayableFault_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 != '\0') {
    cVar3 = rmGpuLockIsOwner();
    if (cVar3 != '\0') {
      uVar4 = (**(code **)(lVar2 + 0x4c0))(lVar1,lVar2,param_2);
      return uVar4;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xe4b);
  return 0x2f;
}


// ===== 004384c0 subdeviceCtrlCmdGpuGetChipDetails_IMPL =====

void subdeviceCtrlCmdGpuGetChipDetails_IMPL(long param_1)

{
  gpuGetChipDetails_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 004384e0 subdeviceCtrlCmdBiosGetSKUInfo_KERNEL =====

undefined8 subdeviceCtrlCmdBiosGetSKUInfo_KERNEL(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetGspStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar1 != 0) {
    portMemCopy(param_2,0x30,lVar1 + 0x10c,0x30);
    return 0;
  }
  nvAssertFailedNoLog("pGSCI != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xe68);
  return 0x40;
}


// ===== 00438560 subdeviceCtrlCmdGpuSetIllum_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int subdeviceCtrlCmdGpuSetIllum_IMPL(long param_1,int *param_2)

{
  undefined8 uVar1;
  long *plVar2;
  int iVar3;
  long lVar4;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = rmapiGetInterface(4);
  plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  iVar3 = (**(code **)(lVar4 + 0x38))
                    (lVar4,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0x20800aec,param_2,8);
  if (iVar3 == 0) {
    if (*param_2 == 0) {
      osWriteRegistryDword(uVar1,"RmIllumLogoBrightness",param_2[1]);
      return 0;
    }
    if (*param_2 == 1) {
      osWriteRegistryDword(uVar1,"RmIllumSLIBrightness",param_2[1]);
      return 0;
    }
  }
  return iVar3;
}


// ===== 00438620 subdeviceCtrlCmdGpuGetRecoveryAction_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetRecoveryAction_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (((lVar1 != 0) && (*(char *)(lVar1 + 0x44c) != '\0')) && (*(char *)(lVar1 + 0x450) == '\0')) {
    gpuGetRecoveryAction_IMPL();
    return 0;
  }
  return 0xf;
}


// ===== 00438670 subdeviceCtrlCmdGpuGetVgpuHeapStats_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetVgpuHeapStats_IMPL(void)

{
  return 0x56;
}


// ===== 00438680 subdeviceCtrlCmdGpuRpcGspTest_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 subdeviceCtrlCmdGpuRpcGspTest_IMPL(long param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 local_30 [2];
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
    if (*param_2 == '\x01') {
      uVar6 = 0;
      if (*(int *)(param_2 + 4) != 0) {
        lVar3 = *(long *)(param_2 + 0x18);
        lVar8 = 0;
        uVar6 = 0;
        do {
          iVar2 = *(int *)(lVar3 + lVar8 * 4);
          iVar5 = (int)lVar8 * 2;
          if (iVar5 != iVar2) {
            uVar6 = 0x25;
            nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xf08,
                         "subdeviceCtrlCmdGpuRpcGspTest_IMPL",4,
                         "NVRM: RPC TEST: mismatch in input data, expected %u, received %u\n",iVar5,
                         iVar2);
          }
          *(int *)(lVar3 + lVar8 * 4) = (int)lVar8 * 3;
          lVar8 = lVar8 + 1;
        } while ((uint)lVar8 < *(uint *)(param_2 + 4));
      }
    }
    else {
      if (*param_2 == '\x04') {
        osDelay(10000);
      }
      uVar6 = 0;
    }
    return uVar6;
  }
  lVar8 = resservGetTlsCallContext();
  puVar4 = *(undefined4 **)(lVar8 + 0x48);
  uVar7 = osGetTimestamp();
  *(undefined8 *)(param_2 + 8) = uVar7;
  cVar1 = *param_2;
  if (((byte)(cVar1 - 3U) < 2) || (cVar1 == '\x01')) {
    lVar8 = gpuGetRpc(lVar3);
    if (lVar8 == 0) {
      uVar6 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                          0xee7);
    }
    else {
      if ((*(char *)(lVar3 + 0x909) != '\0') || (*(char *)(lVar3 + 0x90a) != '\0')) {
        uVar6 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58);
        uVar7 = osGetTimestamp();
        *(undefined8 *)(param_2 + 0x10) = uVar7;
        return uVar6;
      }
      uVar6 = rpcDmaControl_wrapper
                        (lVar3,lVar8,*puVar4,puVar4[1],puVar4[2],*(undefined8 *)(puVar4 + 4),
                         puVar4[6]);
    }
  }
  else {
    uVar6 = 0x1f;
    if (cVar1 == '\x02') {
      local_30[0] = 4;
      uVar6 = (**(code **)(lVar3 + 0x3b90))
                        (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                         *(undefined4 *)(lVar3 + 0x3b3c),0x2080014d,local_30,8);
    }
  }
  uVar7 = osGetTimestamp();
  *(undefined8 *)(param_2 + 0x10) = uVar7;
  return uVar6;
}


// ===== 004388c0 subdeviceCtrlCmdGpuRpcGspQuerySizes_IMPL =====

undefined8 subdeviceCtrlCmdGpuRpcGspQuerySizes_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = gpuGetRpc(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  uVar1 = *(undefined4 *)(lVar2 + 0x4f0);
  param_2[1] = 0x20;
  *param_2 = uVar1;
  *(undefined8 *)(param_2 + 2) = 0x2000000028;
  uVar3 = osGetTimestampFreq();
  *(undefined8 *)(param_2 + 4) = uVar3;
  return 0;
}


// ===== 00438920 subdeviceCtrlCmdThermalSystemExecuteV2_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong subdeviceCtrlCmdThermalSystemExecuteV2_IMPL(long param_1,int *param_2)

{
  long lVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  ulong uVar6;
  int *piVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  uint uVar12;
  int iVar13;
  undefined8 in_stack_ffffffffffffff78;
  long local_48;
  uint local_40;
  
  uVar12 = param_2[5];
  if (0x20 < uVar12) {
    nvCheckFailedNoLog(4,
                       "instructionListSize <= NV_ARRAY_ELEMENTS(pSystemExecuteParams->instructionList)"
                       ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0xfa2);
    return 0x1f;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (uVar12 != 0) {
    piVar5 = param_2;
    if (((ulong)uVar12 * 0x2c & 4) != 0) {
      param_2[7] = 0;
      piVar5 = param_2 + 0xb;
      if (param_2 + 0xb == param_2 + (ulong)uVar12 * 0xb) goto LAB_00438997;
    }
    do {
      piVar5[7] = 0;
      piVar7 = piVar5 + 0x16;
      piVar5[0x12] = 0;
      piVar5 = piVar7;
    } while (piVar7 != param_2 + (ulong)uVar12 * 0xb);
  }
LAB_00438997:
  if (((*param_2 != 1) || (param_2[1] != 0)) || (param_2[2] != 0x2c)) {
    uVar6 = (**(code **)(lVar1 + 0x3b90))
                      (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                       *(undefined4 *)(lVar1 + 0x3b3c),0x20808513,param_2,0x598);
    return uVar6;
  }
  uVar3 = 0;
  if (uVar12 != 0) {
    bVar2 = false;
    piVar5 = param_2;
    do {
      uVar10 = piVar5[8];
      if (uVar10 == 0x510) {
        if (((uint)piVar5[9] < 4) &&
           (lVar9 = (ulong)(uint)piVar5[9] * 0x20 + lVar1, *(char *)(lVar9 + 0x4aa4) != '\0')) {
          iVar13 = *(int *)(lVar9 + 0x4a98);
          piVar5[7] = 1;
          piVar5[6] = 0;
          piVar5[10] = iVar13;
          param_2[4] = param_2[4] + 1;
          goto LAB_00438a55;
        }
LAB_00438a50:
        bVar2 = true;
      }
      else {
        if (uVar10 < 0x511) {
          if (uVar10 == 0x301) {
            piVar7 = (int *)(lVar1 + 0x4a98);
            uVar6 = 0;
            do {
              if ((((char)piVar7[3] != '\0') && (*piVar7 == piVar5[9])) && ((char)piVar7[2] != '\0')
                 ) {
                iVar13 = *(int *)(uVar6 * 0x20 + 0x4a88 + lVar1);
                piVar5[7] = 1;
                piVar5[6] = 0;
                piVar5[10] = iVar13;
                param_2[4] = param_2[4] + 1;
                goto LAB_00438a55;
              }
              uVar10 = (int)uVar6 + 1;
              uVar6 = (ulong)uVar10;
              piVar7 = piVar7 + 8;
            } while (uVar10 != 4);
          }
          else if (uVar10 == 0x500) {
            if (*(char *)(lVar1 + 0x4a84) != '\0') {
              iVar13 = *(int *)(lVar1 + 0x4a80);
              piVar5[7] = 1;
              piVar5[6] = 0;
              piVar5[9] = iVar13;
              param_2[4] = param_2[4] + 1;
              goto LAB_00438a55;
            }
          }
          else {
            piVar7 = (int *)(lVar1 + 0x4a9c);
            uVar6 = 0;
            if (uVar10 == 0x101) {
              do {
                if (((*(char *)((long)piVar7 + 9) != '\0') && (*piVar7 == piVar5[9])) &&
                   (*(char *)((long)piVar7 + 5) != '\0')) {
                  iVar13 = *(int *)(lVar1 + 0x4a8c + uVar6 * 0x20);
                  piVar5[7] = 1;
                  piVar5[6] = 0;
                  piVar5[10] = iVar13;
                  param_2[4] = param_2[4] + 1;
                  goto LAB_00438a55;
                }
                uVar10 = (int)uVar6 + 1;
                uVar6 = (ulong)uVar10;
                piVar7 = piVar7 + 8;
              } while (uVar10 != 4);
            }
          }
          goto LAB_00438a50;
        }
        if (uVar10 != 0x540) {
          if (uVar10 == 0x1500) {
            if ((((uint)piVar5[9] < 4) &&
                (lVar9 = (ulong)(uint)piVar5[9] * 0x20 + lVar1, *(char *)(lVar9 + 0x4aa1) != '\0'))
               && (*(long *)(lVar1 + 0x3c70) != 0)) {
              uVar10 = *(uint *)(lVar9 + 0x4a8c);
              if (uVar10 == 4) {
                lVar9 = 0x938;
                uVar8 = 3;
              }
              else if (uVar10 < 5) {
                if (uVar10 == 1) {
                  uVar8 = 0;
                  lVar9 = 0x908;
                }
                else {
                  uVar8 = 1;
                  lVar9 = 0x918;
                  if (uVar10 != 2) goto LAB_00438a50;
                }
              }
              else {
                lVar9 = 0x928;
                uVar8 = 2;
                if (uVar10 != 8) goto LAB_00438a50;
              }
              portMemSet(&local_48,0,0x10);
              iVar13 = 10;
              lVar11 = ((ulong)uVar8 + 0x90) * 0x10;
              do {
                uVar6 = *(ulong *)(*(long *)(lVar1 + 0x3c70) + lVar11 + 8);
                LOCK();
                UNLOCK();
                if ((uVar6 - 1 < 0xfeffffffffffffff) ||
                   ((0xfeffffffffffffff < uVar6 && ((uVar6 & 1) == 0)))) {
                  portMemCopy(&local_48,0x10,*(long *)(lVar1 + 0x3c70) + lVar9,0x10,lVar11,uVar6,
                              in_stack_ffffffffffffff78);
                  LOCK();
                  UNLOCK();
                  if (*(ulong *)(*(long *)(lVar1 + 0x3c70) + lVar11 + 8) == uVar6) break;
                  local_48 = 0;
                }
                iVar13 = iVar13 + -1;
              } while (iVar13 != 0);
              if (local_48 != 0) {
                piVar5[7] = 1;
                piVar5[6] = 0;
                uVar8 = local_40 >> 7 & 1;
                uVar10 = local_40 >> 8;
                if ((int)local_40 < 0) {
                  uVar10 = local_40 >> 8 | 0xff000000;
                }
                uVar4 = -uVar8;
                if (-1 < (int)local_40) {
                  uVar4 = uVar8;
                }
                piVar5[10] = uVar10 + uVar4;
                param_2[4] = param_2[4] + 1;
                goto LAB_00438a55;
              }
            }
          }
          else if (((uVar10 == 0x520) && ((uint)piVar5[9] < 4)) &&
                  (lVar9 = (ulong)(uint)piVar5[9] * 0x20 + lVar1, *(char *)(lVar9 + 0x4aa5) != '\0')
                  ) {
            iVar13 = *(int *)(lVar9 + 0x4a9c);
            piVar5[7] = 1;
            piVar5[6] = 0;
            piVar5[10] = iVar13;
            param_2[4] = param_2[4] + 1;
            goto LAB_00438a55;
          }
          goto LAB_00438a50;
        }
        if (((3 < (uint)piVar5[9]) ||
            (lVar9 = (ulong)(uint)piVar5[9] * 0x20 + lVar1, *(char *)(lVar9 + 0x4aa2) == '\0')) ||
           (*(char *)(lVar9 + 0x4aa3) == '\0')) goto LAB_00438a50;
        piVar5[10] = *(int *)(lVar9 + 0x4a90);
        iVar13 = *(int *)(lVar9 + 0x4a94);
        piVar5[7] = 1;
        piVar5[0xb] = iVar13;
        piVar5[6] = 0;
        param_2[4] = param_2[4] + 1;
      }
LAB_00438a55:
      piVar5 = piVar5 + 0xb;
    } while (piVar5 != param_2 + (ulong)uVar12 * 0xb);
    if ((bVar2) &&
       (uVar3 = (**(code **)(lVar1 + 0x3b90))
                          (lVar1 + 0x3b58,*(undefined4 *)(lVar1 + 0x3b34),
                           *(undefined4 *)(lVar1 + 0x3b3c),0x20808513,param_2,0x598),
       param_2[5] != 0)) {
      lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
      uVar12 = 0;
      do {
        if ((param_2[(ulong)uVar12 * 0xb + 7] != 0) && (param_2[(ulong)uVar12 * 0xb + 6] == 0)) {
          uVar10 = param_2[(ulong)uVar12 * 0xb + 8];
          if (uVar10 == 0x510) {
            if ((uint)param_2[(ulong)uVar12 * 0xb + 9] < 4) {
              lVar9 = (ulong)(uint)param_2[(ulong)uVar12 * 0xb + 9] * 0x20;
              *(int *)(lVar1 + 0x4a98 + lVar9) = param_2[(ulong)uVar12 * 0xb + 10];
              *(undefined1 *)(lVar1 + 0x4aa4 + lVar9) = 1;
            }
          }
          else if (uVar10 < 0x511) {
            if (uVar10 == 0x301) {
              piVar5 = (int *)(lVar1 + 0x4a98);
              uVar10 = 0;
              do {
                if (((char)piVar5[3] != '\0') && (*piVar5 == param_2[(ulong)uVar12 * 0xb + 9])) {
                  *(int *)((ulong)uVar10 * 0x20 + 0x4a88 + lVar1) =
                       param_2[(ulong)uVar12 * 0xb + 10];
                  *(undefined1 *)(lVar1 + 0x4aa0 + (ulong)uVar10 * 0x20) = 1;
                  break;
                }
                uVar10 = uVar10 + 1;
                piVar5 = piVar5 + 8;
              } while (uVar10 != 4);
            }
            else if (uVar10 == 0x500) {
              iVar13 = param_2[(ulong)uVar12 * 0xb + 9];
              *(undefined1 *)(lVar1 + 0x4a84) = 1;
              *(int *)(lVar1 + 0x4a80) = iVar13;
            }
            else {
              piVar5 = (int *)(lVar1 + 0x4a9c);
              uVar8 = 0;
              if (uVar10 == 0x101) {
                do {
                  if ((*(char *)((long)piVar5 + 9) != '\0') &&
                     (*piVar5 == param_2[(ulong)uVar12 * 0xb + 9])) {
                    *(int *)(lVar1 + 0x4a8c + (ulong)uVar8 * 0x20) =
                         param_2[(ulong)uVar12 * 0xb + 10];
                    *(undefined1 *)(lVar1 + 0x4aa1 + (ulong)uVar8 * 0x20) = 1;
                    break;
                  }
                  uVar8 = uVar8 + 1;
                  piVar5 = piVar5 + 8;
                } while (uVar8 != 4);
              }
            }
          }
          else if (uVar10 == 0x520) {
            if ((uint)param_2[(ulong)uVar12 * 0xb + 9] < 4) {
              lVar9 = (ulong)(uint)param_2[(ulong)uVar12 * 0xb + 9] * 0x20;
              *(int *)(lVar1 + 0x4a9c + lVar9) = param_2[(ulong)uVar12 * 0xb + 10];
              *(undefined1 *)(lVar1 + 0x4aa5 + lVar9) = 1;
            }
          }
          else if ((uVar10 == 0x540) && ((uint)param_2[(ulong)uVar12 * 0xb + 9] < 4)) {
            iVar13 = param_2[(ulong)uVar12 * 0xb + 10];
            lVar9 = (ulong)(uint)param_2[(ulong)uVar12 * 0xb + 9] * 0x20;
            *(undefined1 *)(lVar1 + 0x4aa2 + lVar9) = 1;
            *(int *)(lVar1 + 0x4a90 + lVar9) = iVar13;
            iVar13 = param_2[(ulong)uVar12 * 0xb + 0xb];
            *(undefined1 *)(lVar1 + 0x4aa3 + lVar9) = 1;
            *(int *)(lVar1 + 0x4a94 + lVar9) = iVar13;
          }
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 < (uint)param_2[5]);
    }
  }
  return (ulong)uVar3;
}


// ===== 004390e0 subdeviceCtrlCmdGspGdmaFuzzTest_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGspGdmaFuzzTest_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  undefined8 extraout_RDX;
  undefined8 uVar7;
  long local_40 [2];
  
  iVar5 = 0x56;
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = **(long **)(*(long *)(param_1 + 0x140) + 0x48);
  local_40[0] = 0;
  if (*(char *)(lVar3 + 0x909) != '\0') {
    uVar7 = 1;
    iVar5 = memdescCreate(local_40,lVar3,0x100000,0x1000,1,1);
    if (iVar5 == 0) {
      *(undefined4 *)(local_40[0] + 0x9c) = 0x2e;
      iVar5 = memdescAlloc(local_40[0],0,extraout_RDX,uVar7);
      if (iVar5 == 0) {
        uVar7 = memdescGetPhysAddr(local_40[0],1,0);
        *(undefined8 *)(param_2 + 8) = uVar7;
        lVar6 = gpuGetRpc(lVar3);
        if (lVar6 == 0) {
          iVar5 = 0x1a;
          nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",
                              0x10eb);
        }
        else {
          uVar1 = *(undefined4 *)(lVar4 + 0x48);
          uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10);
          if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
            iVar5 = rpcDmaControl_wrapper(lVar3,lVar6,uVar1,uVar2,0x20803605,param_2,0x10);
          }
          else {
            iVar5 = (**(code **)(lVar3 + 0x3b90))
                              (lVar3 + 0x3b58,uVar1,uVar2,0x20803605,param_2,0x10);
          }
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x10e5,
                     "subdeviceCtrlCmdGspGdmaFuzzTest_IMPL",4,
                     "NVRM: Failed to alloc test buffer, status: 0x%x\n",iVar5);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "memdescCreate(&pMemDesc, pGpu, GDMA_FUZZ_BUFFER_SIZE, RM_PAGE_SIZE, NV_MEMORY_CONTIGUOUS, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                 ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x10d9);
    }
    memdescFree(local_40[0]);
    memdescDestroy(local_40[0]);
  }
  return iVar5;
}


// ===== 004392e0 subdeviceCtrlCmdGpuErrorInjectionControl_IMPL =====

undefined4 subdeviceCtrlCmdGpuErrorInjectionControl_IMPL(long param_1,int *param_2)

{
  long lVar1;
  
  if (*param_2 != 0) {
    return 0x56;
  }
  lVar1 = gpuGetRpc(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  *(undefined1 *)(*(long *)(lVar1 + 0x510) + 0x78) = 1;
  return 0;
}


// ===== 00439320 subdeviceCtrlCmdGpuCheckMemSubsysError_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGpuCheckMemSubsysError_IMPL(long param_1)

{
  (**(code **)(*(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b98) + 0x220))();
  return;
}


// ===== 00439350 subdeviceCtrlCmdGpuGetDefaultTimeout_IMPL =====

undefined8 subdeviceCtrlCmdGpuGetDefaultTimeout_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(int *)(lVar1 + 0x1af4) != 0) {
    *param_2 = *(uint *)(lVar1 + 0x1af4) / 1000;
    return 0;
  }
  nvAssertFailedNoLog("pGpu->timeoutData.defaultus != 0",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_kernel.c",0x1123);
  return 0xffff;
}


// ===== 004393c0 subdeviceCtrlCmdGpuExecRegOps_cmn.constprop.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8
subdeviceCtrlCmdGpuExecRegOps_cmn_constprop_0
          (long param_1,int param_2,int param_3,char param_4,long param_5,long param_6,uint param_7)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 *puVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  code *pcVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  long lVar13;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar8 = resservGetTlsCallContext();
  puVar5 = *(undefined4 **)(lVar8 + 0x48);
  cVar6 = rmapiLockIsOwner();
  if ((cVar6 == '\0') ||
     (cVar6 = rmDeviceGpuLockIsOwner
                        (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7a4)),
     cVar6 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(GPU_RES_GET_GPU(pSubdevice)->gpuInstance)"
                        ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",0x7c);
    return 0x2f;
  }
  nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",0x7f,
               "subdeviceCtrlCmdGpuExecRegOps_cmn",1,"NVRM: client 0x%x channel 0x%x\n",param_2,
               param_3);
  if (param_7 == 0) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",0x85,
                 "subdeviceCtrlCmdGpuExecRegOps_cmn",4,"NVRM: regOpCount is 0\n");
  }
  else if (param_5 == 0) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",0x8b,
                 "subdeviceCtrlCmdGpuExecRegOps_cmn",4,"NVRM: regOps is NULL\n");
  }
  else {
    if ((param_2 == 0) == (param_3 == 0)) {
      if (*(char *)(lVar4 + 0x908) == '\0') {
        lVar1 = param_5 + (ulong)param_7 * 0x20;
        lVar8 = param_5;
        if (((ulong)param_7 * 0x20 & 0x20) == 0) goto LAB_004394e0;
        *(undefined1 *)(param_5 + 2) = 0;
        for (lVar8 = param_5 + 0x20; lVar13 = param_5, lVar1 != lVar8; lVar8 = lVar8 + 0x40) {
LAB_004394e0:
          *(undefined1 *)(lVar8 + 2) = 0;
          *(undefined1 *)(lVar8 + 0x22) = 0;
        }
        do {
          iVar7 = gpuValidateRegOffset_IMPL(lVar4,*(undefined4 *)(lVar13 + 0xc),0);
          if ((iVar7 != 0) && (*(byte *)(lVar13 + 2) = *(byte *)(lVar13 + 2) | 4, param_4 == '\0'))
          {
            return 0x1f;
          }
          lVar13 = lVar13 + 0x20;
        } while (lVar1 != lVar13);
        if (*(char *)(lVar4 + 0x909) == '\0') {
          return 0;
        }
        if (param_6 != 0) {
          pcVar9 = *(code **)(lVar4 + 0x3b90);
          uVar2 = puVar5[2];
          uVar11 = puVar5[1];
          uVar12 = *puVar5;
          uVar3 = puVar5[6];
          uVar10 = *(undefined8 *)(puVar5 + 4);
LAB_0043960b:
          uVar10 = (*pcVar9)(lVar4 + 0x3b58,uVar12,uVar11,uVar2,uVar10,uVar3);
          return uVar10;
        }
        lVar8 = gpuGetRpc(lVar4);
        if (lVar8 != 0) {
LAB_004396d6:
          uVar10 = (**(code **)(lVar8 + 0x68))
                             (lVar4,lVar8,*puVar5,puVar5[1],*(undefined8 *)(puVar5 + 4),param_5);
          return uVar10;
        }
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",
                            0xe0);
      }
      else if (param_6 == 0) {
        lVar8 = gpuGetRpc(lVar4);
        if (lVar8 != 0) goto LAB_004396d6;
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",
                            0xb5);
      }
      else {
        lVar8 = gpuGetRpc(lVar4);
        if (lVar8 != 0) {
          uVar3 = puVar5[6];
          uVar2 = puVar5[2];
          uVar10 = *(undefined8 *)(puVar5 + 4);
          uVar11 = puVar5[1];
          uVar12 = *puVar5;
          if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
            uVar10 = rpcDmaControl_wrapper(lVar4,lVar8,uVar12,uVar11,uVar2,uVar10);
            return uVar10;
          }
          pcVar9 = *(code **)(lVar4 + 0x3b90);
          goto LAB_0043960b;
        }
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",
                            0xab);
      }
      return 0x1a;
    }
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",0x91,
                 "subdeviceCtrlCmdGpuExecRegOps_cmn",4,
                 "NVRM: hClientTarget and hChannelTarget must both be set or both be 0\n");
  }
  return 0x3a;
}


// ===== 00439790 gpuValidateRegOps =====

undefined8
gpuValidateRegOps(undefined8 param_1,long param_2,uint param_3,char param_4,char param_5,
                 undefined1 param_6)

{
  long lVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  if (param_5 == '\0') {
    lVar1 = param_2 + (ulong)param_3 * 0x20;
    while( true ) {
      iVar2 = gpuValidateRegOffset_IMPL(param_1,*(undefined4 *)(param_2 + 0xc),param_6);
      if ((iVar2 != 0) && (*(byte *)(param_2 + 2) = *(byte *)(param_2 + 2) | 4, param_4 == '\0'))
      break;
      param_2 = param_2 + 0x20;
      if (param_2 == lVar1) {
        return 0;
      }
    }
    return 0x1f;
  }
  return 0x1f;
}


// ===== 00439830 subdeviceCtrlCmdGpuExecRegOps_IMPL =====

void subdeviceCtrlCmdGpuExecRegOps_IMPL(undefined8 param_1,undefined4 *param_2)

{
  subdeviceCtrlCmdGpuExecRegOps_cmn_constprop_0
            (param_1,*param_2,param_2[1],param_2[2],*(undefined8 *)(param_2 + 6),0,param_2[5]);
  return;
}


// ===== 00439860 subdeviceCtrlCmdGpuMigratableOps_IMPL =====

undefined1  [16] subdeviceCtrlCmdGpuMigratableOps_IMPL(undefined8 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined8 extraout_RDX;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  uVar1 = param_2[3];
  if (uVar1 < 0x33) {
    auVar2._0_8_ = subdeviceCtrlCmdGpuExecRegOps_cmn_constprop_0
                             (param_1,*param_2,param_2[1],param_2[2],param_2 + 0x36,param_2 + 4);
    auVar2._8_4_ = uVar1;
    auVar2._12_4_ = 0;
    return auVar2;
  }
  nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_gpu_regops.c",0x114,
               "subdeviceCtrlCmdGpuMigratableOps_IMPL",4,"NVRM: Invalid regOpCount: %ud\n");
  auVar3._8_8_ = extraout_RDX;
  auVar3._0_8_ = 0x3a;
  return auVar3;
}


// ===== 004398e0 subdeviceCtrlCmdGpuGetSkylineInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdGpuGetSkylineInfo_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined1 local_1dc [432];
  uint local_2c;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = kmigmgrGetStaticInfo_IMPL(lVar4,*(undefined8 *)(lVar4 + 0x1bc0));
  portMemSet(param_2,0,400);
  portMemSet(local_1dc,0,0x1b4);
  if (*(char *)(lVar4 + 0x908) != '\0') {
    nvCheckFailedNoLog(3,"!IS_VIRTUAL(pGpu)","src/kernel/gpu/subdevice/subdevice_ctrl_gpu_smc.c",
                       0x37);
    return 0x56;
  }
  cVar1 = rmapiLockIsOwner();
  if ((cVar1 != '\0') && (cVar1 = rmGpuLockIsOwner(), cVar1 != '\0')) {
    if ((lVar3 == 0) || (*(long *)(lVar3 + 0x28) == 0)) {
      iVar2 = (**(code **)(lVar4 + 0x3b90))
                        (lVar4 + 0x3b58,*(undefined4 *)(lVar4 + 0x3b34),
                         *(undefined4 *)(lVar4 + 0x3b3c),0x20800aa2,local_1dc,0x1b4);
      if (iVar2 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar2,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_STATIC_GRMGR_GET_SKYLINE_INFO, &internalParams, sizeof(internalParams))"
                   ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_smc.c",0x40);
        return iVar2;
      }
    }
    else {
      portMemCopy(local_1dc,0x1b4,*(long *)(lVar3 + 0x28),0x1b4);
    }
    if (local_2c < 10) {
      if (local_2c != 0) {
        puVar5 = local_1dc;
        lVar4 = param_2;
        do {
          *(undefined4 *)(lVar4 + 0x24) = *(undefined4 *)(puVar5 + 0x24);
          *(undefined4 *)(lVar4 + 0x20) = *(undefined4 *)(puVar5 + 0x20);
          *(undefined4 *)(lVar4 + 0x28) = *(undefined4 *)(puVar5 + 0x28);
          lVar3 = 0;
          do {
            *(undefined1 *)(lVar4 + lVar3) = puVar5[lVar3];
            lVar3 = lVar3 + 1;
          } while (lVar3 != 0x20);
          lVar4 = lVar4 + 0x2c;
          puVar5 = puVar5 + 0x30;
        } while (lVar4 != (ulong)local_2c * 0x2c + param_2);
      }
      *(uint *)(param_2 + 0x18c) = local_2c;
      iVar2 = 0;
    }
    else {
      nvCheckFailedNoLog(4,"internalParams.validEntries <= NV_ARRAY_ELEMENTS(pParams->skylineTable)"
                         ,"src/kernel/gpu/subdevice/subdevice_ctrl_gpu_smc.c",0x4e);
      iVar2 = 0x40;
    }
    return iVar2;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_gpu_smc.c",0x39);
  return 0x2f;
}


// ===== 00439b10 subdeviceCtrlCmdInternalGetChipInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdInternalGetChipInfo_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(param_2 + 0x18);
  iVar4 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar2 = (**(code **)(lVar1 + 0x1e8))(lVar1);
  *param_2 = uVar2;
  uVar2 = (**(code **)(lVar1 + 0x428))(lVar1);
  param_2[8] = uVar2;
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar1 + 0x7f4);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar1 + 0x7fc);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(lVar1 + 0x800);
  do {
    iVar3 = (**(code **)(lVar1 + 0x200))(lVar1,iVar4,puVar5);
    if (iVar3 != 0) {
      *puVar5 = 0xffffffff;
    }
    iVar4 = iVar4 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar4 != 0x10);
  return 0;
}


// ===== 00439bd0 subdeviceCtrlCmdNvdGetDumpSize_IMPL =====

void subdeviceCtrlCmdNvdGetDumpSize_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  local_28 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_20 = 0x100000;
  uStack_1c = 0;
  nvdDumpComponent_IMPL(lVar1,*(undefined8 *)(lVar1 + 0x1ce0),*param_2,&local_28,2,0);
  param_2[1] = uStack_1c;
  return;
}


// ===== 00439c30 subdeviceCtrlCmdNvdGetDump_IMPL =====

void subdeviceCtrlCmdNvdGetDump_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_1c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_20 = *(undefined4 *)((long)param_2 + 0xc);
  local_28 = *param_2;
  nvdDumpComponent_IMPL
            (lVar1,*(undefined8 *)(lVar1 + 0x1ce0),*(undefined4 *)(param_2 + 1),&local_28,0,0);
  *(undefined4 *)((long)param_2 + 0xc) = local_1c;
  return;
}


// ===== 00439c90 subdeviceCtrlCmdNvdGetNocatJournalRpt_IMPL =====

undefined8 subdeviceCtrlCmdNvdGetNocatJournalRpt_IMPL(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_40;
  uint local_3c [3];
  
  lVar1 = *(long *)(g_pSys + 0x228);
  if (lVar1 == 0) {
    return 0x40;
  }
  iVar7 = 0;
  uVar3 = *param_2;
  portMemSet(param_2,0,0x3d28);
  *param_2 = uVar3;
  puVar8 = param_2 + 4;
  do {
    uVar4 = rcdbReportNextNocatJournalEntry(puVar8);
    if ((int)uVar4 != 0) {
      if (((int)uVar4 != 0x57) && (iVar7 == 0)) {
        return uVar4;
      }
      break;
    }
    lVar2 = *(long *)(puVar8 + 4);
    local_40 = 0;
    iVar7 = iVar7 + 1;
    local_3c[0] = 0;
    uVar5 = osGetMonotonicTimeNs();
    osGetSystemTime(&local_40,local_3c);
    uVar6 = osGetTimestampFreq();
    *(ulong *)(puVar8 + 4) =
         ((ulong)local_3c[0] / 1000 + (ulong)local_40 * 1000 + (ulong)(lVar2 * 1000) / uVar6) -
         uVar5 / 1000000;
    puVar8 = puVar8 + 0x182;
  } while (iVar7 != 10);
  param_2[1] = iVar7;
  uVar3 = rcdbGetNocatOutstandingCount(lVar1);
  param_2[2] = uVar3;
  portMemCopy(param_2 + 0xf18,0x80,lVar1 + 0x4b0,0x80);
  return 0;
}


// ===== 00439df0 subdeviceCtrlCmdNvdSetNocatJournalData_IMPL =====

undefined8 subdeviceCtrlCmdNvdSetNocatJournalData_IMPL(long param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined1 local_60 [8];
  undefined1 local_58;
  char *local_50;
  undefined4 local_38;
  int *local_30;
  
  iVar2 = *param_2;
  if (iVar2 == 2) {
    lVar1 = *(long *)(g_pSys + 0x228) + 0x370;
    if (((char)param_2[3] == '\0') || ((*(byte *)(param_2 + 2) & 1) != 0)) {
      portMemSet(lVar1,0,0x41);
      return 0;
    }
    lVar4 = portStringLength(param_2 + 3);
    portStringCopy(lVar1,0x41,param_2 + 3,lVar4 + 1);
  }
  else {
    if (iVar2 == 3) {
      uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
      portMemSet(local_60,0,0x48);
      local_58 = 1;
      local_50 = "RCLOG";
      local_30 = param_2 + 2;
      local_38 = 0x5c;
      rcdbNocatInsertNocatError(uVar3,local_60);
      return 0;
    }
    if (iVar2 == 1) {
      rcdbSetNocatTdrReason(param_2 + 2);
    }
  }
  return 0;
}


// ===== 00439ef0 subdeviceCtrlCmdNvdInsertNocatJournalRecord_IMPL =====

undefined8 subdeviceCtrlCmdNvdInsertNocatJournalRecord_IMPL(long param_1,long param_2)

{
  int *piVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_70;
  undefined1 local_68;
  undefined4 local_64;
  long local_60;
  undefined4 local_58;
  undefined8 local_50;
  undefined4 local_48;
  long local_40;
  long local_38;
  undefined4 local_30;
  
  lVar2 = *(long *)(g_pSys + 0x228);
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  portMemSet(&local_70,0,0x48);
  local_70 = *(undefined8 *)(param_2 + 8);
  local_68 = *(undefined1 *)(param_2 + 0x10);
  local_64 = *(undefined4 *)(param_2 + 0x14);
  local_60 = param_2 + 0x18;
  local_58 = *(undefined4 *)(param_2 + 0x5c);
  local_50 = *(undefined8 *)(param_2 + 0x60);
  local_40 = param_2 + 0xb4;
  local_48 = *(undefined4 *)(param_2 + 0xb0);
  local_38 = param_2 + 0x68;
  local_30 = *(undefined4 *)(param_2 + 0xac);
  piVar1 = (int *)(lVar2 + 0x4d8);
  *piVar1 = *piVar1 + 1;
  rcdbNocatInsertNocatError(uVar3,&local_70);
  return 0;
}


// ===== 00439fb0 gpuControlTimerCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gpuControlTimerCallback(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_30 [2];
  
  uVar3 = 0;
  lVar1 = *(long *)(param_3 + 8);
  if (lVar1 != 0) {
    uVar3 = *(undefined8 *)(lVar1 + 0x160);
  }
  lVar2 = inotifyGetNotificationList_IMPL(uVar3);
  if (*(int *)(lVar1 + 0x380) == 0) {
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x56,
                 "gpuControlTimerCallback",1,
                 "NVRM: callback is called but the timer is not scheduled\n");
  }
  else {
    *(undefined4 *)(lVar1 + 0x380) = 0;
    for (; lVar2 != 0; lVar2 = *(long *)(lVar2 + 0x40)) {
      if (*(int *)(lVar2 + 0xc) == 0xb) {
        if (*(long *)(lVar2 + 0x28) == 0) {
          nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x72,
                       "gpuControlTimerCallback",1,"NVRM: timer callback pointer is missing\n");
          return 0x40;
        }
        local_30[0] = (**(code **)(param_2 + 0x1a0))(param_1);
        osEventNotification(param_1,lVar2,0xb,local_30,8);
        return 0;
      }
    }
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x65,
                 "gpuControlTimerCallback",1,"NVRM: timer event is missing\n");
  }
  return 0x40;
}


// ===== 0043a100 subdeviceCtrlCmdTimerCancel_IMPL =====

undefined4 subdeviceCtrlCmdTimerCancel_IMPL(long param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = rmapiLockIsOwner();
  if (cVar1 != '\0') {
    cVar1 = rmGpuLockIsOwner();
    if (cVar1 != '\0') {
      if (param_1 == 0) {
        uVar2 = 0x1f;
      }
      else {
        uVar2 = 0;
        if (*(int *)(param_1 + 0x380) != 0) {
          tmrEventCancel_IMPL(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b88)
                              ,*(undefined8 *)(param_1 + 0x6b8));
          *(undefined4 *)(param_1 + 0x380) = 0;
          return 0;
        }
      }
      return uVar2;
    }
  }
  nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                      "src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x3b);
  return 0x2f;
}


// ===== 0043a1b0 subdeviceCtrlCmdTimerSchedule_IMPL =====

int subdeviceCtrlCmdTimerSchedule_IMPL(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = resservGetTlsCallContext();
  if ((*(byte *)(*(long *)(lVar4 + 0x48) + 0xc) & 1) == 0) {
    cVar2 = rmapiLockIsOwner();
    if ((cVar2 != '\0') && (cVar2 = rmGpuLockIsOwner(), cVar2 != '\0')) {
      if (param_1 == 0) {
        return 0x1f;
      }
      goto LAB_0043a1fe;
    }
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0xe0);
  }
  else {
    cVar2 = rmDeviceGpuLockIsOwner
                      (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7a4));
    if (cVar2 != '\0') {
LAB_0043a1fe:
      uVar1 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b88);
      lVar4 = inotifyGetNotificationList_IMPL(*(undefined8 *)(param_1 + 0x160));
      if (*(int *)(param_1 + 0x380) == 0) {
        for (; lVar4 != 0; lVar4 = *(long *)(lVar4 + 0x40)) {
          if (*(int *)(lVar4 + 0xc) == 0xb) {
            if (((*(int *)(lVar4 + 0x10) != 0x78) && (*(int *)(lVar4 + 0x10) != 0x7e)) ||
               (*(long *)(lVar4 + 0x28) == 0)) {
              nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0xa2,
                           "timerSchedule",1,
                           "NVRM: gpuControlTimer: cmd 0x%x: callback function is missing\n",
                           0x20800401);
              return 0x40;
            }
            *(undefined4 *)(param_1 + 0x380) = 1;
            if (*(long *)(param_1 + 0x6b8) == 0) {
              iVar3 = tmrEventCreate_IMPL(uVar1,param_1 + 0x6b8,gpuControlTimerCallback,param_1,0);
              if (iVar3 != 0) {
                nvAssertOkFailedNoLog
                          (iVar3,
                           "tmrEventCreate(pTmr, &pSubdevice->pTimerEvent, gpuControlTimerCallback, pSubdevice, TMR_FLAGS_NONE)"
                           ,"src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0xb6);
                return iVar3;
              }
            }
            else {
              cVar2 = tmrEventOnList_IMPL(uVar1);
              if (cVar2 != '\0') {
                tmrEventCancel_IMPL(uVar1,*(undefined8 *)(param_1 + 0x6b8));
              }
            }
            if ((*(uint *)(param_2 + 1) & 1) == 0) {
              tmrEventScheduleAbs_IMPL();
              return 0;
            }
            tmrEventScheduleRel_IMPL(uVar1,*(undefined8 *)(param_1 + 0x6b8),*param_2);
            return 0;
          }
        }
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x9b,"timerSchedule",1
                     ,"NVRM: gpuControlTimerCallback: timer event is missing\n");
      }
      else {
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x8f,"timerSchedule",1
                     ,
                     "NVRM: gpuControlTimerCallback: the timer is already scheduled for this subdevice\n"
                    );
      }
      return 0x40;
    }
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(GPU_RES_GET_GPU(pSubdevice)->gpuInstance)",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0xdb);
  }
  return 0x2f;
}


// ===== 0043a470 subdeviceCtrlCmdTimerGetTime_IMPL =====

undefined8 subdeviceCtrlCmdTimerGetTime_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  
  lVar4 = resservGetTlsCallContext();
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b88);
  if ((~*(uint *)(*(long *)(lVar4 + 0x48) + 0xc) & 3) == 0) {
    if (*(int *)(lVar2 + 0x24e8) != 0) {
      return 99;
    }
  }
  else {
    cVar3 = rmapiLockIsOwner();
    if ((cVar3 == '\0') ||
       (cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar1 + 0x7a4)), cVar3 == '\0')) {
      nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                          "src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x104);
      return 0x2f;
    }
  }
  tmrGetCurrentTime_IMPL(lVar2,param_2);
  return 0;
}


// ===== 0043a530 subdeviceCtrlCmdTimerGetRegisterOffset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdTimerGetRegisterOffset_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmapiLockIsOwner();
  if (cVar2 != '\0') {
    uVar3 = (**(code **)(lVar1 + 0x200))(lVar1,2,param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("rmapiLockIsOwner()","src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",
                      0x11d);
  return 0x2f;
}


// ===== 0043a5a0 subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

ulong subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo_IMPL(long param_1,byte *param_2)

{
  byte bVar1;
  long lVar2;
  byte *pbVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 uVar12;
  char *pcVar13;
  byte bVar14;
  uint *puVar15;
  byte *pbVar16;
  long *plVar17;
  long *plVar18;
  int local_78;
  uint local_64 [3];
  undefined8 local_58;
  long local_50 [4];
  
  lVar9 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar9 + 0x1b88);
  cVar4 = rmapiLockIsOwner();
  if ((cVar4 == '\0') || (cVar4 = rmGpuLockIsOwner(), cVar4 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmGpuLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x139);
    return 0x2f;
  }
  bVar1 = param_2[1];
  if (bVar1 < 0x11) {
    bVar14 = *param_2;
    if (bVar14 >> 4 == 1) {
      if ((*(char *)(lVar9 + 0x909) == '\0') && (*(char *)(lVar9 + 0x90a) == '\0')) {
        return 0x56;
      }
      uVar10 = (**(code **)(lVar9 + 0x3b90))
                         (lVar9 + 0x3b58,*(undefined4 *)(lVar9 + 0x3b34),
                          *(undefined4 *)(lVar9 + 0x3b3c),0x20800406,param_2,0x108);
      return uVar10;
    }
    if (bVar14 >> 4 == 0) {
      if (bVar14 == 2) {
        bVar14 = 0;
        pbVar3 = param_2;
        if (bVar1 != 0) {
          while( true ) {
            uVar5 = (**(code **)(lVar2 + 0x208))(lVar9,lVar2,pbVar3 + 0x10,pbVar3 + 8);
            if (uVar5 != 0) break;
            bVar14 = bVar14 + 1;
            pbVar3 = pbVar3 + 0x10;
            if (param_2[1] <= bVar14) {
              return 0;
            }
          }
          pcVar13 = "NVRM: Could not get CPU GPU time. status=0x%08x\n";
          uVar12 = 0x1c1;
LAB_0043a845:
          nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",uVar12,
                       "subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo_IMPL",4,pcVar13,uVar5);
          return (ulong)uVar5;
        }
      }
      else if (bVar14 == 3) {
        iVar6 = (**(code **)(lVar2 + 0x1c0))(lVar9,lVar2,0);
        do {
          local_78 = iVar6;
          puVar15 = local_64;
          plVar17 = &local_58;
          do {
            plVar18 = plVar17 + 1;
            osGetPerformanceCounter(plVar17);
            uVar5 = (**(code **)(lVar2 + 0x1b8))(lVar9,lVar2,0);
            *puVar15 = uVar5;
            puVar15 = puVar15 + 1;
            plVar17 = plVar18;
          } while (local_50 + 2 != plVar18);
          osGetPerformanceCounter(local_50 + 2);
          iVar6 = (**(code **)(lVar2 + 0x1c0))(lVar9,lVar2,0);
        } while (local_78 != iVar6);
        uVar11 = local_50[0] - CONCAT44(local_58._4_4_,(uint)local_58);
        uVar8 = local_50[1] - local_50[0];
        uVar10 = uVar8;
        if (uVar8 >= uVar11) {
          uVar10 = uVar11;
        }
        uVar8 = (ulong)(uVar8 < uVar11);
        if ((ulong)(local_50[2] - local_50[1]) < uVar10) {
          uVar8 = 2;
        }
        uVar5 = local_64[uVar8];
        lVar9 = (**(code **)(lVar2 + 0x1d0))(lVar9,lVar2);
        lVar9 = CONCAT44(local_78,uVar5) + lVar9;
        lVar2 = (&local_58)[uVar8];
        lVar7 = (&local_58)[(int)uVar8 + 1];
        *(long *)(param_2 + 0x10) = lVar9;
        uVar10 = (ulong)(lVar2 + lVar7) >> 1;
        *(ulong *)(param_2 + 8) = uVar10;
        nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",0x1b4,
                     "subdeviceCtrlCmdTimerGetGpuCpuTimeCorrelationInfo_IMPL",1,
                     "NVRM: GPUTime = %llx  CPUTime = %llx\n",lVar9,uVar10);
      }
      else {
        if (bVar14 != 1) {
          return 0x56;
        }
        bVar14 = 0;
        pbVar3 = param_2;
        if (bVar1 != 0) {
          while( true ) {
            pbVar16 = pbVar3 + 0x10;
            osGetSystemTime(local_64,&local_58);
            *(ulong *)(pbVar3 + 8) = (ulong)local_64[0] * 1000000 + (ulong)(uint)local_58;
            uVar5 = tmrGetCurrentTime_IMPL(lVar2,pbVar16);
            if (uVar5 != 0) break;
            bVar14 = bVar14 + 1;
            lVar7 = (**(code **)(lVar2 + 0x1d0))(lVar9,lVar2);
            *(long *)pbVar16 = *(long *)pbVar16 + lVar7;
            pbVar3 = pbVar16;
            if (param_2[1] <= bVar14) {
              return 0;
            }
          }
          pcVar13 = "NVRM: Could not get GPU time. status=0x%08x\n";
          uVar12 = 0x16c;
          goto LAB_0043a845;
        }
      }
      return 0;
    }
  }
  return 0x1f;
}


// ===== 0043a950 subdeviceCtrlCmdTimerSetGrTickFreq_IMPL =====

undefined8 subdeviceCtrlCmdTimerSetGrTickFreq_IMPL(long param_1,char *param_2)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x1b88);
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  cVar3 = rmapiLockIsOwner();
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmapiLockIsOwner()",
                        "src/kernel/gpu/subdevice/subdevice_ctrl_timer_kernel.c",499);
    return 0x2f;
  }
  uVar4 = 0x1f;
  if (lVar2 != 0) {
    uVar4 = *(undefined8 *)(lVar2 + 0x24f0);
    uVar5 = CONCAT44(uVar1,*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10));
    if (*param_2 == '\0') {
      uVar4 = refcntReleaseReferences_IMPL(uVar4,uVar5,1);
      *(undefined1 *)(param_1 + 0x340) = 0;
      return uVar4;
    }
    uVar4 = refcntRequestReference_IMPL(uVar4,uVar5,1,0);
    *(undefined1 *)(param_1 + 0x340) = 1;
  }
  return uVar4;
}


// ===== 0043aa30 subdeviceCtrlCmdBiosGetSKUInfo_VF =====

undefined8 subdeviceCtrlCmdBiosGetSKUInfo_VF(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar1 != 0) {
    portMemCopy(param_2,0x30,lVar1 + 0xa738,0x30);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_vgpu.c",0x29);
  return 0x40;
}


// ===== 0043aab0 subdeviceCtrlCmdGpuQueryEccConfiguration_VF =====

undefined8 subdeviceCtrlCmdGpuQueryEccConfiguration_VF(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  uint local_c;
  
  local_c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(lVar1 + 0x7a4) * 8);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pVGpu != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_vgpu.c",0x3b);
    return 0x40;
  }
  uVar4 = 0x56;
  if (*(char *)(lVar2 + 0x26150) != '\0') {
    iVar3 = osReadRegistryDword(lVar1,"RMGuestECCState",&local_c);
    if (iVar3 != 0) {
      local_c = (uint)*(byte *)(lVar2 + 0x26151);
    }
    param_2[1] = 1;
    *param_2 = local_c;
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 0043ab60 subdeviceCtrlCmdGpuSetEccConfiguration_VF =====

undefined8 subdeviceCtrlCmdGpuSetEccConfiguration_VF(long param_1,int *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(NvVGPU_Table + (ulong)*(uint *)(lVar1 + 0x7a4) * 8) == 0) {
    nvAssertFailedNoLog("pVGpu != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_vgpu.c",0x5b);
    return 0x40;
  }
  if (*(char *)(*(long *)(NvVGPU_Table + (ulong)*(uint *)(lVar1 + 0x7a4) * 8) + 0x26150) != '\0') {
    uVar2 = osWriteRegistryDword(lVar1,"RMGuestECCState",*param_2 != 0);
    return uVar2;
  }
  return 0x56;
}


// ===== 0043abe0 subdeviceCtrlCmdGpuQueryScrubberStatus_VF =====

undefined8 subdeviceCtrlCmdGpuQueryScrubberStatus_VF(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return 0;
}


// ===== 0043abf0 subdeviceCtrlCmdBiosGetPostTime_VF =====

undefined8 subdeviceCtrlCmdBiosGetPostTime_VF(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x928);
  return 0;
}


// ===== 0043ac20 subdeviceCtrlCmdGpuResetEccErrorStatus_VF =====

undefined8 subdeviceCtrlCmdGpuResetEccErrorStatus_VF(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  char *pcVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(NvVGPU_Table + (ulong)*(uint *)(lVar1 + 0x7a4) * 8);
  lVar4 = gpuGetStaticInfo(lVar1);
  if ((*(long *)(lVar1 + 0x1bc0) != 0) && (cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar1), cVar3 != '\0'))
  {
    nvCheckFailedNoLog(1,"!bMigEnabled","src/kernel/gpu/subdevice/subdevice_ctrl_vgpu.c",0x93);
    return 0x56;
  }
  if (((lVar2 != 0) && (*(char *)(lVar2 + 0x26150) != '\0')) && ((*param_2 & 2) == 0)) {
    pcVar5 = (char *)(lVar4 + 0x1ea82);
    do {
      if (*pcVar5 != '\0') {
        pcVar5[0x16] = '\0';
        pcVar5[0x17] = '\0';
        pcVar5[0x18] = '\0';
        pcVar5[0x19] = '\0';
        pcVar5[0x1a] = '\0';
        pcVar5[0x1b] = '\0';
        pcVar5[0x1c] = '\0';
        pcVar5[0x1d] = '\0';
        pcVar5[6] = '\0';
        pcVar5[7] = '\0';
        pcVar5[8] = '\0';
        pcVar5[9] = '\0';
        pcVar5[10] = '\0';
        pcVar5[0xb] = '\0';
        pcVar5[0xc] = '\0';
        pcVar5[0xd] = '\0';
      }
      pcVar5 = pcVar5 + 0x28;
    } while (pcVar5 != (char *)(lVar4 + 0x1f0ea));
    return 0;
  }
  return 0x56;
}


// ===== 0043ad20 subdeviceCtrlCmdGpuQueryEccStatus_VF =====

undefined8 subdeviceCtrlCmdGpuQueryEccStatus_VF(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(NvVGPU_Table +
                   (ulong)*(uint *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7a4) * 8);
  lVar2 = gpuGetStaticInfo();
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x26150) != '\0')) {
    if (*(char *)(lVar1 + 0x26151) == '\0') {
      portMemSet(param_2,0,0x680);
    }
    else {
      portMemCopy(param_2,0x680,lVar2 + 0x1ea80,0x680);
    }
    return 0;
  }
  return 0x56;
}


// ===== 0043adc0 subdeviceCtrlCmdGpuQueryIllumSupport_VF =====

undefined8 subdeviceCtrlCmdGpuQueryIllumSupport_VF(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 4) = 0;
  return 0;
}


// ===== 0043add0 subdeviceCtrlCmdBiosGetInfoV2_VF =====

undefined8 subdeviceCtrlCmdBiosGetInfoV2_VF(undefined8 param_1,uint *param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0x1f;
  if (*param_2 - 1 < 0xf) {
    lVar1 = 0;
    do {
      param_2[lVar1 * 2 + 2] = 0;
      lVar1 = lVar1 + 1;
    } while ((uint)lVar1 < *param_2);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 0043ae10 subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_VF =====

undefined8 subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_VF(void)

{
  return 0;
}


// ===== 0043ae20 subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_VF =====

undefined8 subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_VF(void)

{
  return 0;
}


// ===== 0043ae30 subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_VF =====

undefined8 subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_VF(void)

{
  return 0;
}


// ===== 0043ae40 subdeviceCtrlCmdCcuGetSampleInfo_VF =====

undefined8 subdeviceCtrlCmdCcuGetSampleInfo_VF(long param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = gpuGetStaticInfo(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (lVar1 != 0) {
    portMemCopy(param_2,4,lVar1 + 0x25f20,4);
    return 0;
  }
  nvAssertFailedNoLog("pVSI != NULL","src/kernel/gpu/subdevice/subdevice_ctrl_vgpu.c",0x11e);
  return 0x40;
}


// ===== 0043aec0 diagapiConstruct_IMPL =====

undefined8 diagapiConstruct_IMPL(void)

{
  return 0;
}


// ===== 0043aed0 diagapiControl_IMPL =====

void diagapiControl_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_3 + 0x70);
  if (param_1 == 0) {
    gpuresControlSetup_IMPL(param_3,0);
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_diag.c",0x3d,"diagapiControl_IMPL",1,
                 "NVRM: gpuControlSubDevice: cmd 0x%x\n",*(undefined4 *)(lVar1 + 8));
    uVar2 = 0;
  }
  else {
    gpuresControlSetup_IMPL(param_3,*(undefined8 *)(param_1 + 0x158));
    nvDbg_Printf("src/kernel/gpu/subdevice/subdevice_diag.c",0x3d,"diagapiControl_IMPL",1,
                 "NVRM: gpuControlSubDevice: cmd 0x%x\n",*(undefined4 *)(lVar1 + 8));
    uVar2 = *(undefined8 *)(param_1 + 0x158);
  }
  gpuresControl_IMPL(uVar2,param_2,param_3);
  return;
}


// ===== 0043af90 diagapiControlFilter_IMPL =====

undefined8 diagapiControlFilter_IMPL(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((*(char *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x908) != '\0') &&
     (iVar1 = *(int *)(*(long *)(param_3 + 0x70) + 8), iVar1 != 0x208f0401)) {
    uVar2 = 0x56;
    if (iVar1 == 0x208f1402) {
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0;
}


// ===== 0043afe0 swengConstructEngine_IMPL =====

undefined8 swengConstructEngine_IMPL(void)

{
  return 0;
}


// ===== 0043aff0 swtestConstruct_IMPL =====

undefined8 swtestConstruct_IMPL(void)

{
  return 0;
}


// ===== 0043b000 swtestDestruct_IMPL =====

void swtestDestruct_IMPL(void)

{
  return;
}


// ===== 0043b010 swtestGetSwMethods_IMPL =====

undefined8 swtestGetSwMethods_IMPL(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  *param_2 = Nv04SoftwareTestMethods;
  *param_3 = 1;
  return 0;
}


// ===== 0043b030 _class9074SetSemaphoreReleaseValue =====

undefined8
_class9074SetSemaphoreReleaseValue
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x1f9,"_class9074SetSemaphoreReleaseValue",1,
               "NVRM: \n");
  *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 0x40;
  *(undefined4 *)(lVar1 + 0x200) = param_4;
  return 0;
}


// ===== 0043b090 _class9074SetWaitTimestampLo =====

undefined8
_class9074SetWaitTimestampLo
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x1dd,"_class9074SetWaitTimestampLo",1,"NVRM: \n")
  ;
  if ((*(uint *)(lVar1 + 0x204) & 0x10) != 0) {
    *(undefined4 *)(lVar1 + 0x1fc) = param_4;
    *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 0x20;
    *(ulong *)(lVar1 + 0x218) = CONCAT44(*(undefined4 *)(lVar1 + 0x1f8),param_4);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x1e1,"_class9074SetWaitTimestampLo",4,
               "NVRM: WAIT_TIMESTAMP_HI not set\n");
  return 0x40;
}


// ===== 0043b140 _class9074SetWaitTimestampHi =====

undefined8
_class9074SetWaitTimestampHi
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x1cb,"_class9074SetWaitTimestampHi",1,"NVRM: \n")
  ;
  *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 0x10;
  *(undefined4 *)(lVar1 + 0x1f8) = param_4;
  return 0;
}


// ===== 0043b1a0 _class9074SetSemaphoreLo =====

uint _class9074SetSemaphoreLo(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x1a9,"_class9074SetSemaphoreLo",1,"NVRM: \n");
  if ((*(uint *)(lVar1 + 0x204) & 4) == 0) {
    nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x1ad,"_class9074SetSemaphoreLo",4,
                 "NVRM: SEMAPHORE_HI not set\n");
    return 0x40;
  }
  if ((param_4 & 3) == 0) {
    *(uint *)(lVar1 + 500) = param_4;
    *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 8;
    *(ulong *)(lVar1 + 0x210) = CONCAT44(*(undefined4 *)(lVar1 + 0x1f0),param_4);
    return param_4 & 3;
  }
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x1b2,"_class9074SetSemaphoreLo",4,
               "NVRM: Mis-aligned address\n");
  return 0x1f;
}


// ===== 0043b2a0 _class9074SetSemaphoreHi =====

undefined8
_class9074SetSemaphoreHi(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x196,"_class9074SetSemaphoreHi",1,"NVRM: \n");
  *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 4;
  *(uint *)(lVar1 + 0x1f0) = param_4 & 0xff;
  return 0;
}


// ===== 0043b310 _class9074SetNotifierLo =====

uint _class9074SetNotifierLo(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x174,"_class9074SetNotifierLo",1,"NVRM: \n");
  if ((*(uint *)(lVar1 + 0x204) & 1) == 0) {
    nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x178,"_class9074SetNotifierLo",4,
                 "NVRM: NOTIFIER_HI not set\n");
    return 0x40;
  }
  if ((param_4 & 3) == 0) {
    *(uint *)(lVar1 + 0x1ec) = param_4;
    *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 2;
    *(ulong *)(lVar1 + 0x208) = CONCAT44(*(undefined4 *)(lVar1 + 0x1e8),param_4);
    return param_4 & 3;
  }
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x17d,"_class9074SetNotifierLo",4,
               "NVRM: Mis-aligned address\n");
  return 0x1f;
}


// ===== 0043b410 _class9074SetNotifierHi =====

undefined8
_class9074SetNotifierHi(undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x161,"_class9074SetNotifierHi",1,"NVRM: \n");
  *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) | 1;
  *(uint *)(lVar1 + 0x1e8) = param_4 & 0xff;
  return 0;
}


// ===== 0043b472 tsemaConstruct_IMPL.cold =====

void tsemaConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0043b480 tsemaConstruct_IMPL =====

undefined8 tsemaConstruct_IMPL(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (param_1 != 0) {
    tmrEventCreate_IMPL(*(undefined8 *)
                         (*(long *)(*(long *)(*(long *)(param_1 + 0x1d8) + 0x158) + 0xe0) + 0x1b88),
                        param_1 + 0x228,_class9074TimerCallback,*(long *)(param_1 + 0x1d8),1);
    uVar2 = portMemAllocatorGetGlobalNonPaged();
    listInit_IMPL(param_1 + 0x230,uVar2,0x20);
    return 0;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0043b4ef tsemaDestruct_IMPL.cold =====

void tsemaDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0043b500 tsemaDestruct_IMPL =====

void tsemaDestruct_IMPL(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    tmrEventDestroy_IMPL
              (*(undefined8 *)
                (*(long *)(*(long *)(*(long *)(param_1 + 0x1d8) + 0x158) + 0xe0) + 0x1b88),
               *(undefined8 *)(param_1 + 0x228));
    *(undefined8 *)(param_1 + 0x228) = 0;
    listDestroy_IMPL(param_1 + 0x230);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0043b560 tsemaCtrlCmdGetTime_IMPL =====

undefined8 tsemaCtrlCmdGetTime_IMPL(long param_1)

{
  tmrGetCurrentTime_IMPL(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x1c0) + 0xe0) + 0x1b88));
  return 0;
}


// ===== 0043b590 tsemaGetSwMethods_IMPL =====

undefined8 tsemaGetSwMethods_IMPL(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  *param_2 = GF100TimedSemSwMethods;
  *param_3 = 9;
  return 0;
}


// ===== 0043b5b0 tsemaRelease_KERNEL =====

int tsemaRelease_KERNEL(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined8 param_7)

{
  int iVar1;
  int iVar2;
  undefined8 local_40 [2];
  
  tmrGetCurrentTime_IMPL(*(undefined8 *)(param_1 + 0x1b88),local_40);
  iVar1 = semaphoreFillGPUVATimestamp(param_1,param_7,param_4,param_2,param_5,0,1,local_40[0]);
  if (iVar1 != 0) {
    nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x297,"tsemaRelease_KERNEL",4,
                 "NVRM: Semaphore fill failed, error 0x%x\n",iVar1);
  }
  iVar2 = notifyFillNotifierGPUVATimestamp
                    (param_1,param_7,param_4,param_3,0,0,param_6,0,local_40[0]);
  if ((iVar2 != 0) &&
     (nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x2a8,"tsemaRelease_KERNEL",4,
                   "NVRM: Notifier fill failed, error 0x%x\n",iVar2), iVar1 == 0)) {
    iVar1 = iVar2;
  }
  return iVar1;
}


// ===== 0043b6c0 _9074TimedSemRelease.isra.0 =====

int _9074TimedSemRelease_isra_0
              (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 param_6,undefined2 param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 extraout_RDX;
  undefined8 uStack_30;
  
  iVar1 = tsemaRelease_KERNEL(param_1,param_5,param_4,
                              *(undefined4 *)(*(long *)(param_2 + 0x178) + 0x298),param_6,param_7);
  if (param_8 != 0) {
    uVar3 = inotifyGetNotificationList_IMPL
                      (*(undefined8 *)(param_2 + 0x160),uStack_30,extraout_RDX,param_3);
    iVar2 = notifyEvents(param_1,uVar3,0,0,0,0,param_8);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x92,"_9074TimedSemRelease",4,
                   "NVRM: Event notify failed, error 0x%x\n",iVar2);
      if (iVar1 == 0) {
        iVar1 = iVar2;
      }
      return iVar1;
    }
  }
  return iVar1;
}


// ===== 0043b790 _9074TimedSemRequest =====

int _9074TimedSemRequest
              (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,ulong param_5,
              undefined4 param_6,undefined4 param_7)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulong local_40 [2];
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b88);
  lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  iVar2 = listCount_IMPL(lVar3 + 0x230);
  if (iVar2 == 0) {
    tmrGetCurrentTime_IMPL(uVar1,local_40);
    if (*(char *)(param_1 + 0x908) == '\0') {
      if (local_40[0] < param_5) {
        if (((*(byte *)(lVar3 + 0x205) & 1) == 0) ||
           (uVar5 = 1, param_5 < *(ulong *)(lVar3 + 0x220))) goto LAB_0043b820;
      }
      else {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0x8000;
    }
    iVar2 = _9074TimedSemRelease_isra_0
                      (param_1,param_2,*(undefined8 *)(*(long *)(lVar3 + 0x1c0) + 0xe8),param_3,
                       param_4,param_6,uVar5,param_7);
    if (iVar2 != 0) {
      nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0xc3,"_9074TimedSemRequest",4,
                   "NVRM: Timed sem release failed, error 0x%x\n",iVar2);
    }
  }
  else {
LAB_0043b820:
    puVar4 = (undefined8 *)listAppendNew_IMPL(lVar3 + 0x230);
    if (puVar4 == (undefined8 *)0x0) {
      iVar2 = 0x51;
      nvCheckFailedNoLog(1,"pTimedSemEntry != NULL","src/kernel/gpu/timed_semaphore.c",0xcc);
    }
    else {
      puVar4[2] = param_5;
      *puVar4 = param_3;
      puVar4[1] = param_4;
      *(undefined4 *)(puVar4 + 3) = param_6;
      *(undefined4 *)((long)puVar4 + 0x1c) = param_7;
      iVar2 = listCount_IMPL(lVar3 + 0x230);
      if (iVar2 == 1) {
        tmrEventScheduleAbs_IMPL(uVar1,*(undefined8 *)(lVar3 + 0x228),puVar4[2]);
      }
      iVar2 = 0;
    }
  }
  return iVar2;
}


// ===== 0043b950 _class9074ScheduleSemaphoreRelease =====

undefined1  [16]
_class9074ScheduleSemaphoreRelease
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4)

{
  long lVar1;
  undefined8 extraout_RDX;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x20b,"_class9074ScheduleSemaphoreRelease",1,
               "NVRM: \n");
  if ((~*(uint *)(lVar1 + 0x204) & 0x7f) == 0) {
    *(uint *)(lVar1 + 0x204) = *(uint *)(lVar1 + 0x204) & 0xffffff80;
    auVar2._0_8_ = _9074TimedSemRequest
                             (param_1,param_2,*(undefined8 *)(lVar1 + 0x208),
                              *(undefined8 *)(lVar1 + 0x210),*(undefined8 *)(lVar1 + 0x218),
                              *(undefined4 *)(lVar1 + 0x200));
    auVar2._8_4_ = param_4 & 3;
    auVar2._12_4_ = 0;
    return auVar2;
  }
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x20f,"_class9074ScheduleSemaphoreRelease",4,
               "NVRM: Required methods were not written\n");
  auVar3._8_8_ = extraout_RDX;
  auVar3._0_8_ = 0x40;
  return auVar3;
}


// ===== 0043ba40 _class9074TimerCallback =====

undefined4 _class9074TimerCallback(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined1 auVar7 [16];
  ulong local_40 [2];
  
  uVar1 = *(undefined8 *)(param_3 + 8);
  lVar3 = __nvoc_dynamicCast(uVar1,__nvoc_class_def_TimedSemaSwObject);
  nvDbg_Printf("src/kernel/gpu/timed_semaphore.c",0x22d,"_class9074TimerCallback",1,"NVRM: \n");
  tmrGetCurrentTime_IMPL(param_2,local_40);
  auVar7 = listHead_IMPL(lVar3 + 0x230);
  if (auVar7._0_8_ == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    do {
      puVar6 = auVar7._0_8_;
      lVar4 = listNext_IMPL(lVar3 + 0x230,puVar6,auVar7._8_8_);
      if (local_40[0] < (ulong)puVar6[2]) {
        if (((*(byte *)(lVar3 + 0x205) & 1) == 0) || ((ulong)puVar6[2] < *(ulong *)(lVar3 + 0x220)))
        {
          tmrEventScheduleAbs_IMPL(param_2,*(undefined8 *)(lVar3 + 0x228));
          return uVar2;
        }
        uVar5 = 1;
      }
      else {
        uVar5 = 0;
      }
      auVar7._8_4_ = *(undefined4 *)((long)puVar6 + 0x1c);
      auVar7._0_8_ = lVar4;
      auVar7._12_4_ = 0;
      uVar2 = _9074TimedSemRelease_isra_0
                        (param_1,uVar1,*(undefined8 *)(*(long *)(lVar3 + 0x1c0) + 0xe8),*puVar6,
                         puVar6[1],*(undefined4 *)(puVar6 + 3),uVar5);
      listRemove_IMPL(lVar3 + 0x230,puVar6);
    } while (lVar4 != 0);
  }
  return uVar2;
}


// ===== 0043bb90 tmrGetGpuPtimerOffset_GA100 =====

undefined8 tmrGetGpuPtimerOffset_GA100(long param_1,undefined8 param_2,int *param_3,int *param_4)

{
  if (*(char *)(param_1 + 0x4913) != '\0') {
    *param_3 = 0x30080;
    *param_4 = 0x30084;
    return 0;
  }
  *param_3 = *(int *)(param_1 + 0x3a64) + 0x30080;
  *param_4 = *(int *)(param_1 + 0x3a64) + 0x30084;
  return 0;
}


// ===== 0043bbd0 tmrServiceInterrupt_GA100 =====

undefined8 tmrServiceInterrupt_GA100(undefined8 param_1,undefined8 param_2,short *param_3)

{
  if (param_3 == (short *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/timer/arch/ampere/timer_ga100.c",0x52);
    return 0;
  }
  if (*param_3 != 1) {
    if (*param_3 != 0xa4) {
      nvAssertFailedNoLog("Invalid engineIdx","src/kernel/gpu/timer/arch/ampere/timer_ga100.c",0x66)
      ;
    }
    return 0;
  }
  tmrCallExpiredCallbacks_IMPL();
  return 0;
}


// ===== 0043bc40 tmrGetTmrBaseAddr_GB100 =====

undefined4 tmrGetTmrBaseAddr_GB100(undefined8 param_1)

{
  int iVar1;
  long local_10;
  
  iVar1 = gpuGetOneDeviceEntry_IMPL(param_1,0x1f,0xffffffff,0,0xffffffff,&local_10);
  if (iVar1 == 0) {
    return *(undefined4 *)(local_10 + 0x10);
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/timer/arch/blackwell/timer_gb100.c",0x3a);
  return 0;
}


// ===== 0043bca0 tmrGetNsecShiftMask_GB100 =====

undefined8 tmrGetNsecShiftMask_GB100(void)

{
  return 0xffffffe0;
}


// ===== 0043bcb0 tmrGetTimerBar0MapInfo_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
tmrGetTimerBar0MapInfo_GB100(undefined8 param_1,long param_2,ulong *param_3,undefined4 *param_4)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x210))();
  *param_3 = (ulong)uVar1;
  *param_4 = 0x1000;
  return 0;
}


// ===== 0043bce0 tmrSetCurrentTime_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrSetCurrentTime_GB10B(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  bool bVar5;
  uint local_40;
  uint local_3c [3];
  
  osGetSystemTime(&local_40,local_3c);
  uVar4 = ((ulong)local_40 * 1000000 + (ulong)local_3c[0]) * 1000;
  iVar1 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,0);
  do {
    uVar2 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,0);
    iVar3 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,0);
    bVar5 = iVar1 != iVar3;
    iVar1 = iVar3;
  } while (bVar5);
  if (CONCAT44(iVar3,uVar2) < uVar4) {
    *(ulong *)(param_2 + 0x24f8) = uVar4 - CONCAT44(iVar3,uVar2);
    return 0;
  }
  nvAssertFailedNoLog("gpuTimerNs < osTimeNs","src/kernel/gpu/timer/arch/blackwell/timer_gb10b.c",
                      0x4a);
  return 0x40;
}


// ===== 0043bde0 tmrGetPtimerOffsetNs_GB10B =====

undefined8 tmrGetPtimerOffsetNs_GB10B(undefined8 param_1,long param_2)

{
  return *(undefined8 *)(param_2 + 0x24f8);
}


// ===== 0043bdf0 tmrSetCurrentTime_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrSetCurrentTime_GH100(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  ulong uVar6;
  bool bVar7;
  uint local_40;
  uint local_3c [5];
  
  lVar1 = *(long *)(param_1 + 0x1d08);
  osGetSystemTime(&local_40,local_3c);
  nvDbg_Printf("src/kernel/gpu/timer/arch/hopper/timer_gh100.c",0x3f,"tmrSetCurrentTime_GH100",1,
               "NVRM: osGetSystemTime returns 0x%x seconds, 0x%x useconds\n",local_40,local_3c[0]);
  uVar6 = ((ulong)local_40 * 1000000 + (ulong)local_3c[0]) * 1000;
  iVar3 = regRead032(param_1 + 0x3a18,0,0,0x118f58,0);
  do {
    uVar4 = regRead032(param_1 + 0x3a18,0,0,0x118f54,0);
    iVar5 = regRead032(param_1 + 0x3a18,0,0,0x118f58);
    bVar7 = iVar3 != iVar5;
    iVar3 = iVar5;
  } while (bVar7);
  if (CONCAT44(iVar5,uVar4) < uVar6) {
    uVar6 = uVar6 - CONCAT44(iVar5,uVar4);
    if ((lVar1 == 0) || (cVar2 = (**(code **)(lVar1 + 0x220))(param_1), cVar2 == '\0')) {
      regWrite032(param_1 + 0x3a18,0,0,0x118df8,uVar6 >> 0x20,0);
      regWrite032(param_1 + 0x3a18,0,0,0x118df4,(uint)uVar6 | 1,0);
    }
    *(ulong *)(param_2 + 0x24f8) = uVar6;
    return 0;
  }
  nvAssertFailedNoLog("secTimerNs < osTimeNs","src/kernel/gpu/timer/arch/hopper/timer_gh100.c",0x52)
  ;
  return 0x40;
}


// ===== 0043bfa0 tmrSetCountdown_GH100 =====

undefined8
tmrSetCountdown_GH100
          (long param_1,undefined8 param_2,undefined4 param_3,uint param_4,undefined8 param_5)

{
  if (param_4 < 2) {
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2300 + param_4 * 4,param_3,
                param_5);
    return 0;
  }
  nvAssertFailedNoLog("tmrId < NV_VIRTUAL_FUNCTION_PRIV_TIMER__SIZE_1",
                      "src/kernel/gpu/timer/arch/hopper/timer_gh100.c",0x75);
  return 0x56;
}


// ===== 0043c000 tmrGetTimeEx_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrGetTimeEx_GH100(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = 0;
  while( true ) {
    iVar1 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,param_3);
    if (*(int *)(param_2 + 0x24e0) == 0) break;
    uVar5 = 0;
    do {
      uVar2 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,param_3);
      uVar3 = (**(code **)(param_2 + 0x1a8))(param_1,param_2);
      if ((~uVar3 & uVar2) == 0) break;
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(uint *)(param_2 + 0x24e0));
    if (*(uint *)(param_2 + 0x24e0) == uVar5) break;
    iVar4 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,param_3);
    if (iVar1 == iVar4) {
      return CONCAT44(iVar1,uVar2);
    }
  }
  nvDbg_Printf("src/kernel/gpu/timer/arch/hopper/timer_gh100.c",0x98,"tmrGetTimeEx_GH100",4,
               "NVRM: NVRM-RC: Consistently Bad TimeLo value %x\n",uVar2);
  return 0;
}


// ===== 0043c120 tmrGetGpuAndCpuTimestampPair_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
tmrGetGpuAndCpuTimestampPair_GM107
          (undefined8 param_1,long param_2,undefined8 *param_3,ulong *param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  bool bVar9;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64 [3];
  long local_58 [5];
  
  local_6c = 0;
  local_68 = 0;
  (**(code **)(param_2 + 0x1c8))(param_1,param_2,&local_6c,&local_68);
  iVar3 = osGpuReadReg032(param_1,local_68);
  do {
    local_58[0] = rdtsc();
    local_64[0] = osGpuReadReg032(param_1,local_6c);
    local_58[1] = rdtsc();
    local_64[1] = osGpuReadReg032(param_1,local_6c);
    local_58[2] = rdtsc();
    local_64[2] = osGpuReadReg032(param_1,local_6c);
    local_58[3] = rdtsc();
    iVar4 = osGpuReadReg032(param_1,local_68);
    bVar9 = iVar3 != iVar4;
    iVar3 = iVar4;
  } while (bVar9);
  uVar7 = local_58[1] - local_58[0];
  uVar6 = local_58[2] - local_58[1];
  uVar8 = uVar7;
  if (uVar6 < uVar7) {
    uVar8 = uVar6;
  }
  uVar5 = (uint)(uVar6 < uVar7);
  if ((ulong)(local_58[3] - local_58[2]) < uVar8) {
    uVar5 = 2;
  }
  lVar1 = local_58[uVar5];
  lVar2 = local_58[uVar5 + 1];
  *param_3 = CONCAT44(iVar4,local_64[uVar5]);
  *param_4 = (ulong)(lVar1 + lVar2) >> 1;
  return 0;
}


// ===== 0043c280 tmrGetGpuPtimerOffset_GM107 =====

undefined8
tmrGetGpuPtimerOffset_GM107
          (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0x9400;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0x9410;
  }
  return 0;
}


// ===== 0043c2a0 tmrGrTickFreqChange_GM107 =====

undefined8 tmrGrTickFreqChange_GM107(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x9480,0);
  uVar1 = uVar2 & 0xfffffff8 | 5;
  if (param_3 != '\0') {
    uVar1 = uVar2 & 0xfffffff8;
  }
  regWrite032(param_1 + 0x3a18,0,0,0x9480,uVar1,0);
  return 0;
}


// ===== 0043c300 tmrGetTimeEx_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 tmrGetTimeEx_GM107(undefined8 param_1,long *param_2,undefined8 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  while( true ) {
    iVar1 = (*(code *)param_2[0x38])(param_1,param_2,param_3);
    if ((int)param_2[0x49c] == 0) break;
    uVar4 = 0;
    do {
      uVar2 = (*(code *)param_2[0x37])(param_1,param_2,param_3);
      if ((uVar2 & 0x1f) == 0) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_2 + 0x49c));
    if (*(uint *)(param_2 + 0x49c) == uVar4) break;
    iVar3 = (*(code *)param_2[0x38])(param_1,param_2,param_3);
    if (iVar1 == iVar3) {
      return CONCAT44(iVar1,uVar2);
    }
  }
  nvDbg_Printf("src/kernel/gpu/timer/arch/maxwell/timer_gm107.c",0xfe,"tmrGetTimeEx_GM107",4,
               "NVRM: NVRM-RC: Consistently Bad TimeLo value %x\n",uVar2);
  *(int *)((long)param_2 + 0x24e4) = *(int *)((long)param_2 + 0x24e4) + 1;
  (**(code **)(*param_2 + 0x110))(param_1,param_2);
  (**(code **)(*param_2 + 0x120))(param_1,param_2,0);
  return 0;
}


// ===== 0043c430 tmrGetTmrBaseAddr_GM107 =====

undefined8 tmrGetTmrBaseAddr_GM107(void)

{
  return 0x9400;
}


// ===== 0043c440 tmrGetNsecShiftMask_GM107 =====

undefined8 tmrGetNsecShiftMask_GM107(void)

{
  return 0xffffffe0;
}


// ===== 0043c450 tmrGetTimeLo_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint tmrGetTimeLo_GM107(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,0);
  uVar2 = (**(code **)(param_2 + 0x1a8))(param_1,param_2);
  if ((~uVar2 & uVar1) == 0) {
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/timer/arch/maxwell/timer_gm107.c",0x141,"tmrGetTimeLo_GM107",3,
               "NVRM: NVRM-RC: Bad TimeLo value %x, Let\'s see if it happens again.\n",uVar1);
  uVar1 = (**(code **)(param_2 + 0x1a0))(param_1,param_2);
  return uVar1;
}


// ===== 0043c4f0 tmrGetTime_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void tmrGetTime_GM107(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x1b0))(param_1,param_2,0);
  return;
}


// ===== 0043c510 tmrServiceInterrupt_GM107 =====

undefined8 tmrServiceInterrupt_GM107(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  
  if (param_3 != 0) {
    cVar1 = tmrGetCallbackInterruptPending_IMPL();
    if (cVar1 != '\0') {
      tmrResetCallbackInterrupt_IMPL(param_1,param_2);
      tmrCallExpiredCallbacks_IMPL(param_1,param_2);
      if (*(long *)(param_2 + 0x220) == 0) {
        tmrRmCallbackIntrDisable_IMPL(param_2,param_1);
      }
    }
    return 0;
  }
  nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/timer/arch/maxwell/timer_gm107.c",0x168);
  return 0;
}


// ===== 0043c5a0 tmrSetCountdownIntrDisable_GM200 =====

undefined8 tmrSetCountdownIntrDisable_GM200(long param_1)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,0x9140,0);
  regWrite032Unicast(param_1 + 0x3a18,0,0,0x9140,uVar1 & 0xfffffffd,0);
  return 0;
}


// ===== 0043c5f0 tmrReadTimeLoReg_T234D =====

void tmrReadTimeLoReg_T234D(void)

{
  osGetTimestamp();
  return;
}


// ===== 0043c600 tmrReadTimeHiReg_T234D =====

ulong tmrReadTimeHiReg_T234D(void)

{
  ulong uVar1;
  
  uVar1 = osGetTimestamp();
  return uVar1 >> 0x20;
}


// ===== 0043c620 tmrSetCountdown_TU102 =====

undefined8
tmrSetCountdown_TU102
          (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2300,param_3,param_5);
  return 0;
}


// ===== 0043c650 tmrSetCountdownIntrEnable_TU102 =====

undefined8 tmrSetCountdownIntrEnable_TU102(void)

{
  return 0;
}


// ===== 0043c660 tmrSetCountdownIntrReset_TU102 =====

undefined8 tmrSetCountdownIntrReset_TU102(void)

{
  return 0;
}


// ===== 0043c670 tmrGetGpuPtimerOffset_TU102 =====

undefined8
tmrGetGpuPtimerOffset_TU102(long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x4913) != '\0') {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0x30080;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x30084;
    }
    return 0;
  }
  uVar1 = tmrGetGpuPtimerOffset_GV100();
  return uVar1;
}


// ===== 0043c6b0 tmrReadTimeLoReg_TU102 =====

void tmrReadTimeLoReg_TU102(long param_1,undefined8 param_2,undefined8 param_3)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30080,param_3);
  return;
}


// ===== 0043c6e0 tmrReadTimeHiReg_TU102 =====

void tmrReadTimeHiReg_TU102(long param_1,undefined8 param_2,undefined8 param_3)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30084,param_3);
  return;
}


// ===== 0043c710 tmrServiceInterrupt_TU102 =====

undefined8 tmrServiceInterrupt_TU102(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_3 != 0) {
    tmrCallExpiredCallbacks_IMPL();
    uVar1 = tmrServiceInterrupt_GM107(param_1,param_2,param_3);
    return uVar1;
  }
  nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/timer/arch/turing/timer_tu102.c",0xb5);
  return 0;
}


// ===== 0043c770 tmrSetCurrentTime_GV100 =====

undefined1  [16] tmrSetCurrentTime_GV100(long param_1)

{
  ulong uVar1;
  undefined8 extraout_RDX;
  undefined1 auVar2 [16];
  uint local_20;
  uint local_1c;
  
  param_1 = param_1 + 0x3a18;
  uVar1 = regRead032(param_1,0,0,0x9430,0);
  if ((uVar1 & 0x10) != 0) {
    osGetSystemTime(&local_20,&local_1c);
    nvDbg_Printf("src/kernel/gpu/timer/arch/volta/timer_gv100.c",0x40,"tmrSetCurrentTime_GV100",1,
                 "NVRM: osGetSystemTime returns 0x%x seconds, 0x%x useconds\n",local_20,local_1c);
    uVar1 = ((ulong)local_20 * 1000000 + (ulong)local_1c) * 1000;
    regWrite032(param_1,0,0,0x9410,uVar1 >> 0x20,0);
    regWrite032(param_1,0,0,0x9400,uVar1 & 0xffffffff,0);
    return ZEXT816(0x43c7b4) << 0x40;
  }
  nvDbg_Printf("src/kernel/gpu/timer/arch/volta/timer_gv100.c",0x4e,"tmrSetCurrentTime_GV100",4,
               "NVRM: ERROR: Write to PTIMER attempted even though Level 0 PLM is disabled.\n");
  nvAssertFailedNoLog(&DAT_00d7aac5,"src/kernel/gpu/timer/arch/volta/timer_gv100.c",0x50);
  auVar2._8_8_ = extraout_RDX;
  auVar2._0_8_ = 0x6b;
  return auVar2;
}


// ===== 0043c890 tmrGetGpuPtimerOffset_GV100 =====

undefined8
tmrGetGpuPtimerOffset_GV100(long param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x4a7) != '\0') {
    *param_3 = 0x810080;
    *param_4 = 0x810084;
    return 0;
  }
  uVar1 = tmrGetGpuPtimerOffset_GM107();
  return uVar1;
}


// ===== 0043c8c0 _tmrCallbackWrapperfunction =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _tmrCallbackWrapperfunction(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)param_3[1];
  uVar2 = *param_3;
  *param_3 = *puVar1;
  param_3[1] = puVar1[1];
  (*(code *)*puVar1)();
  *puVar1 = *param_3;
  puVar1[1] = param_3[1];
  *param_3 = uVar2;
  param_3[1] = puVar1;
  return 0;
}


// ===== 0043c920 _tmrGrTimeStampFreqStateChange =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8
_tmrGrTimeStampFreqStateChange(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = __nvoc_dynamicCast(param_2,__nvoc_class_def_OBJTMR);
  if (param_1 == 0) {
    return 0x56;
  }
  if (lVar1 != 0) {
    lVar2 = gpuEngineGetGpu(*(undefined8 *)(lVar1 + 0x160));
    if (lVar2 != 0) {
      uVar3 = (**(code **)(lVar1 + 0x200))(lVar2,lVar1,param_4 == 1,*(code **)(lVar1 + 0x200));
      return uVar3;
    }
  }
  return 0x40;
}


// ===== 0043c9b0 _nv0004CtrlCmdTmrSetAlarmNotifyCallback =====

int _nv0004CtrlCmdTmrSetAlarmNotifyCallback(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  if (*(long *)(*(long *)(param_3 + 8) + 0x28) == 0) {
    return 0;
  }
  iVar1 = osNotifyEvent(param_1,*(long *)(param_3 + 8),0,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/timer/timer.c",0x1e6,"_nv0004CtrlCmdTmrSetAlarmNotifyCallback",4,
               "NVRM: failed to notify event in callback, status: 0x%08x\n");
  return iVar1;
}


// ===== 0043ca40 tmrConstructEngine_IMPL =====

undefined8 tmrConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  lVar2 = portSyncSpinlockCreate(uVar1);
  *(long *)(param_2 + 0x24d0) = lVar2;
  if (lVar2 != 0) {
    *(undefined8 *)(param_2 + 0x220) = 0;
    *(undefined8 *)(param_2 + 0x228) = 0;
    *(long *)(param_2 + 0x230) = param_2 + 0x238;
    lVar2 = param_2 + 0x288;
    do {
      *(long *)(lVar2 + -8) = lVar2;
      lVar3 = lVar2 + 0x50;
      *(undefined1 *)(lVar2 + -0x20) = 0;
      *(undefined1 *)(lVar2 + -0x30) = 1;
      lVar2 = lVar3;
    } while (lVar3 != param_2 + 0x2038);
    *(undefined8 *)(param_2 + 0x2030) = 0;
    *(undefined1 *)(param_2 + 0x2018) = 0;
    *(undefined1 *)(param_2 + 0x2008) = 1;
    osInit1HzCallbacks(param_2);
    *(undefined8 *)(param_2 + 0x24e0) = 3;
    *(undefined8 *)(param_2 + 0x24f0) = 0;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/timer/timer.c",0x3c,"tmrConstructEngine_IMPL",4,
               "NVRM: Alloc spinlock failed\n");
  return 0x1a;
}


// ===== 0043cb30 tmrStateInitUnlocked_IMPL =====

void tmrStateInitUnlocked_IMPL(undefined8 param_1,long param_2)

{
  __nvoc_objCreate_OBJREFCNT(param_2 + 0x24f0,param_2,0,param_2,0,_tmrGrTimeStampFreqStateChange,0);
  return;
}


// ===== 0043cb60 tmrDestruct_IMPL =====

void tmrDestruct_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x24d0) != 0) {
    portSyncSpinlockDestroy();
    *(undefined8 *)(param_1 + 0x24d0) = 0;
  }
  __nvoc_objDelete(*(undefined8 *)(param_1 + 0x24f0));
  *(undefined8 *)(param_1 + 0x24f0) = 0;
  osDestroy1HzCallbacks(param_1);
  return;
}


// ===== 0043cbb0 tmrEventCreate_IMPL =====

int tmrEventCreate_IMPL(long param_1,long *param_2,undefined8 param_3,undefined8 param_4,
                       undefined4 param_5)

{
  long lVar1;
  int iVar2;
  
  lVar1 = portMemAllocNonPaged(0x50);
  *param_2 = lVar1;
  if (lVar1 == 0) {
    iVar2 = 0x51;
    nvDbg_Printf("src/kernel/gpu/timer/timer.c",0xe9,"tmrEventCreate_IMPL",4,
                 "NVRM: Failed to allocate timer event\n");
  }
  else {
    *(undefined1 *)(lVar1 + 0x20) = 0;
    *(undefined1 *)(*param_2 + 0x30) = 0;
    *(undefined8 *)(*param_2 + 0x48) = 0;
    *(undefined8 *)*param_2 = param_3;
    *(undefined8 *)(*param_2 + 8) = param_4;
    *(undefined4 *)(*param_2 + 0x18) = param_5;
    iVar2 = 0;
    if (*param_2 != 0) {
      if (*(char *)(param_1 + 0x21a) == '\0') {
        if ((*(uint *)(*param_2 + 0x18) & 8) == 0) {
          return 0;
        }
        iVar2 = tmrEventCreateOSTimer_OSTIMER(param_1);
      }
      else {
        iVar2 = tmrEventCreateOSTimer_OSTIMER(param_1);
      }
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/timer/timer.c",0xf8,"tmrEventCreate_IMPL",4,
                     "NVRM: Failed to create OS timer \n");
        portMemFree(*param_2);
        *param_2 = 0;
      }
    }
  }
  return iVar2;
}


// ===== 0043ccd0 tmrResetCallbackInterrupt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void tmrResetCallbackInterrupt_IMPL(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x218) != '\0') {
    (**(code **)(param_2 + 0x1e8))(param_1,param_2,0);
    return;
  }
  return;
}


// ===== 0043cd00 tmrGetCallbackInterruptPending_IMPL =====

undefined8 tmrGetCallbackInterruptPending_IMPL(void)

{
  return 0;
}


// ===== 0043cd10 tmrGetCurrentTimeEx_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 tmrGetCurrentTimeEx_IMPL(long param_1,undefined8 *param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x160);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  if ((((lVar1 == 0) || (*(char *)(lVar1 + 0x44f) != '\0')) || (*(char *)(lVar1 + 0x450) != '\0'))
     || ((*(char *)(lVar1 + 0x451) != '\0' || (*(char *)(lVar1 + 0x461) != '\0')))) {
    uVar2 = 0xffffffffffffffff;
    uVar3 = 0x10;
  }
  else if (*(char *)(lVar1 + 0x44c) == '\0') {
    uVar2 = 0xffffffffffffffff;
    uVar3 = 0xf;
  }
  else {
    uVar2 = (**(code **)(param_1 + 0x1b0))(lVar1,param_1,param_3,*(code **)(param_1 + 0x1b0));
    uVar3 = 0;
  }
  *param_2 = uVar2;
  return uVar3;
}


// ===== 0043cdc0 _tmrScheduleCallbackInterrupt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _tmrScheduleCallbackInterrupt(undefined8 param_1,long param_2,ulong param_3)

{
  int local_24;
  ulong local_20 [2];
  
  if ((*(char *)(param_2 + 0x21c) == '\0') && (*(char *)(param_2 + 0x218) != '\0')) {
    local_24 = 0;
    tmrGetCurrentTimeEx_IMPL(param_2,local_20,0);
    if (local_20[0] < param_3) {
      local_24 = (int)param_3 - (int)local_20[0];
    }
    (**(code **)(param_2 + 0x1f0))(param_1,param_2,local_24,0,0);
    return;
  }
  return;
}


// ===== 0043ce40 tmrEventCancel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void tmrEventCancel_IMPL(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x160);
  }
  uVar3 = gpuEngineGetGpu(uVar3);
  if (param_2 != 0) {
    lVar1 = *(long *)(param_1 + 0x220);
    if (*(char *)(param_2 + 0x20) != '\0') {
      nvAssertFailedNoLog("!pEvent->bLegacy","src/kernel/gpu/timer/timer.c",0x161);
    }
    *(undefined1 *)(param_2 + 0x30) = 0;
    if ((*(char *)(param_1 + 0x21a) == '\0') && ((*(byte *)(param_2 + 0x18) & 8) == 0)) {
      if (param_2 == lVar1) {
        lVar1 = *(long *)(param_2 + 0x48);
        *(long *)(param_1 + 0x220) = lVar1;
        if (lVar1 != 0) {
          _tmrScheduleCallbackInterrupt(uVar3,param_1,*(undefined8 *)(lVar1 + 0x38));
          return;
        }
        if (*(char *)(param_1 + 0x218) != '\0') {
          (**(code **)(param_1 + 0x1d8))(uVar3,param_1);
          return;
        }
      }
      else {
        while (lVar4 = lVar1, lVar4 != 0) {
          lVar1 = *(long *)(lVar4 + 0x48);
          if (*(long *)(lVar4 + 0x48) == param_2) {
            *(undefined8 *)(lVar4 + 0x48) = *(undefined8 *)(param_2 + 0x48);
            return;
          }
        }
      }
    }
    else {
      lVar1 = *(long *)(param_1 + 0x228);
      if (param_2 == *(long *)(param_1 + 0x228)) {
        *(undefined8 *)(param_1 + 0x228) = *(undefined8 *)(param_2 + 0x48);
        *(undefined8 *)(param_2 + 0x48) = 0;
        *(undefined1 *)(param_2 + 0x30) = 0;
        iVar2 = tmrEventCancelOSTimer_OSTIMER(param_1,param_2);
      }
      else {
        do {
          lVar4 = lVar1;
          if (lVar4 == 0) {
            iVar2 = tmrEventCancelOSTimer_OSTIMER(param_1,param_2);
            goto joined_r0x0043cfb1;
          }
          lVar1 = *(long *)(lVar4 + 0x48);
        } while (param_2 != *(long *)(lVar4 + 0x48));
        *(undefined8 *)(lVar4 + 0x48) = *(undefined8 *)(param_2 + 0x48);
        *(undefined8 *)(param_2 + 0x48) = 0;
        *(undefined1 *)(param_2 + 0x30) = 0;
        iVar2 = tmrEventCancelOSTimer_OSTIMER(param_1,param_2);
      }
joined_r0x0043cfb1:
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/timer/timer.c",0x16c,"tmrEventCancel_IMPL",4,
                     "NVRM: Failed in cancel of OS timer callback\n");
        return;
      }
    }
  }
  return;
}


// ===== 0043d080 tmrEventDestroy_IMPL =====

void tmrEventDestroy_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  if (param_2 == 0) {
    return;
  }
  if (*(char *)(param_2 + 0x20) != '\0') {
    nvAssertFailedNoLog("!pEvent->bLegacy","src/kernel/gpu/timer/timer.c",0x19f);
  }
  if ((*(char *)(param_1 + 0x21a) == '\0') && ((*(byte *)(param_2 + 0x18) & 8) == 0)) {
    tmrEventCancel_IMPL(param_1,param_2);
    portMemFree(param_2);
    return;
  }
  lVar1 = *(long *)(param_1 + 0x228);
  if (param_2 == *(long *)(param_1 + 0x228)) {
    *(undefined8 *)(param_1 + 0x228) = *(undefined8 *)(param_2 + 0x48);
    *(undefined8 *)(param_2 + 0x48) = 0;
    *(undefined1 *)(param_2 + 0x30) = 0;
  }
  else {
    do {
      lVar2 = lVar1;
      if (lVar2 == 0) goto LAB_0043d0d2;
      lVar1 = *(long *)(lVar2 + 0x48);
    } while (param_2 != *(long *)(lVar2 + 0x48));
    *(undefined8 *)(lVar2 + 0x48) = *(undefined8 *)(param_2 + 0x48);
    *(undefined8 *)(param_2 + 0x48) = 0;
    *(undefined1 *)(param_2 + 0x30) = 0;
  }
LAB_0043d0d2:
  tmrEventDestroyOSTimer_OSTIMER(param_1,param_2);
  portMemFree(param_2);
  return;
}


// ===== 0043d190 tmrEventTimeUntilNextCallback_IMPL =====

int tmrEventTimeUntilNextCallback_IMPL(long param_1,long param_2,long *param_3)

{
  int iVar1;
  ulong uVar2;
  ulong local_20;
  
  if ((param_2 == 0) ||
     ((*(char *)(param_1 + 0x21a) == '\0' && ((*(byte *)(param_2 + 0x18) & 8) == 0)))) {
    iVar1 = tmrGetCurrentTimeEx_IMPL(param_1,&local_20,0);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"tmrGetCurrentTime(pTmr, &currentTime)","src/kernel/gpu/timer/timer.c",0x1ca)
      ;
      return iVar1;
    }
    uVar2 = *(ulong *)(param_2 + 0x38);
  }
  else {
    local_20 = osGetMonotonicTimeNs();
    uVar2 = *(ulong *)(param_2 + 0x38) + *(ulong *)(param_2 + 0x40);
    if (CARRY8(*(ulong *)(param_2 + 0x38),*(ulong *)(param_2 + 0x40))) {
      nvCheckFailedNoLog(4,"portSafeAddU64(pEvent->timens, pEvent->startTimeNs, &nextAlarmTime)",
                         "src/kernel/gpu/timer/timer.c",0x1c5);
      return 0x1f;
    }
  }
  iVar1 = 0x40;
  if (local_20 <= uVar2) {
    iVar1 = 0;
    *param_3 = uVar2 - local_20;
  }
  return iVar1;
}


