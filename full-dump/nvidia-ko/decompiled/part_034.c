// ===== 0037d3a0 kgspFreeVgpuPartitionLogging_IMPL =====

undefined8 kgspFreeVgpuPartitionLogging_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  int *piVar1;
  bool bVar2;
  
  if (0x30 < param_3) {
    return 0x1f;
  }
  kgspDumpGspLogs_IMPL(param_2,0);
  piVar1 = (int *)(param_2 + 0x69ef0);
  LOCK();
  bVar2 = *piVar1 == 0;
  if (bVar2) {
    *piVar1 = 1;
  }
  UNLOCK();
  while (!bVar2) {
    osSpinLoop();
    LOCK();
    bVar2 = *piVar1 == 0;
    if (bVar2) {
      *piVar1 = 1;
    }
    UNLOCK();
  }
  _kgspFreeLibosVgpuPartitionLoggingStructures(param_1,param_2);
  LOCK();
  if (*piVar1 == 1) {
    *piVar1 = 0;
  }
  UNLOCK();
  return 0;
}


// ===== 0037d440 kgspPreserveVgpuPartitionLogging_IMPL =====

undefined8 kgspPreserveVgpuPartitionLogging_IMPL(undefined8 param_1,long param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x1f;
  if (param_3 - 1U < 0x30) {
    kgspDumpGspLogs_IMPL(param_2,0);
    libosPreserveLogs(param_2 + 0x2d48 + (ulong)(param_3 - 1U) * 0x21f8,1,0);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 0037d4a0 kgspNvlogFlushCb =====

void kgspNvlogFlushCb(long param_1)

{
  if (param_1 != 0) {
    kgspDumpGspLogs_IMPL(param_1,1);
    return;
  }
  return;
}


// ===== 0037d4c0 _kgspRpcDrainEvents =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kgspRpcDrainEvents(long param_1,long param_2,uint param_3,int param_4,int param_5)

{
  long lVar1;
  int *piVar2;
  undefined1 *puVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  long lVar9;
  undefined8 uVar10;
  long lVar11;
  uint *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  long lVar15;
  undefined8 uVar16;
  undefined4 *puVar17;
  long lVar18;
  char *pcVar19;
  ulong extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  ulong extraout_RDX_02;
  ulong extraout_RDX_03;
  ulong extraout_RDX_04;
  ulong uVar20;
  ulong extraout_RDX_05;
  ulong extraout_RDX_06;
  ulong extraout_RDX_07;
  ulong extraout_RDX_08;
  ulong extraout_RDX_09;
  ulong extraout_RDX_10;
  ulong extraout_RDX_11;
  ulong extraout_RDX_12;
  ulong extraout_RDX_13;
  ulong extraout_RDX_14;
  ulong extraout_RDX_15;
  ulong extraout_RDX_16;
  ulong extraout_RDX_17;
  ulong extraout_RDX_18;
  ulong extraout_RDX_19;
  ulong extraout_RDX_20;
  ulong extraout_RDX_21;
  ulong extraout_RDX_22;
  ulong extraout_RDX_23;
  ulong extraout_RDX_24;
  ulong extraout_RDX_25;
  ulong extraout_RDX_26;
  ulong extraout_RDX_27;
  ulong extraout_RDX_28;
  ulong extraout_RDX_29;
  ulong extraout_RDX_30;
  ulong extraout_RDX_31;
  ulong extraout_RDX_32;
  ulong extraout_RDX_33;
  ulong extraout_RDX_34;
  ulong extraout_RDX_35;
  ulong extraout_RDX_36;
  undefined8 *puVar21;
  ulong extraout_RDX_37;
  ulong extraout_RDX_38;
  ulong extraout_RDX_39;
  ulong extraout_RDX_40;
  ulong extraout_RDX_41;
  ulong extraout_RDX_42;
  ulong extraout_RDX_43;
  ulong extraout_RDX_44;
  ulong extraout_RDX_45;
  ulong extraout_RDX_46;
  ulong extraout_RDX_47;
  ulong extraout_RDX_48;
  ulong extraout_RDX_49;
  ulong extraout_RDX_50;
  ulong extraout_RDX_51;
  ulong extraout_RDX_52;
  ulong extraout_RDX_53;
  ulong extraout_RDX_54;
  ulong extraout_RDX_55;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  undefined8 in_stack_fffffffffffffef8;
  uint local_f4;
  undefined4 local_ec;
  long local_e8;
  long local_b8;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  undefined4 local_68;
  undefined8 local_60;
  undefined4 local_58;
  long local_50;
  long local_48;
  undefined4 local_40;
  
  lVar9 = gpuGetRpc();
  do {
    LOCK();
    UNLOCK();
    iVar6 = GspMsgQueueReceiveStatus(*(undefined8 *)(lVar9 + 0x510),param_1);
    if (iVar6 != 0) {
      if (iVar6 == 0x10005) {
        iVar6 = 0xffff;
        nvAssertFailedNoLog("nvStatus != NV_WARN_MORE_PROCESSING_REQUIRED",
                            "src/kernel/gpu/gsp/kernel_gsp.c",0x736);
        kgspDumpGspLogs_IMPL(param_2,0);
      }
      else {
        kgspDumpGspLogs_IMPL(param_2,0);
      }
LAB_0037d7f9:
      cVar5 = (**(code **)(param_2 + 0x898))(param_1);
      if (cVar5 == '\0') {
        iVar6 = 0x62;
      }
      else if (iVar6 == 0x10006) {
        iVar6 = 0;
      }
      return iVar6;
    }
    lVar18 = *(long *)(lVar9 + 0x4d8);
    uVar24 = *(uint *)(lVar18 + 0xc);
    if ((param_3 == uVar24) && (param_4 == *(int *)(lVar18 + 0x18))) {
      iVar6 = 0x10005;
      kgspDumpGspLogs_IMPL(param_2,0);
      goto LAB_0037d7f9;
    }
    lVar1 = lVar9 + 0x1920;
    if (uVar24 < 0xe5) {
      pcVar19 = *(char **)(rpcName_40 + (ulong)uVar24 * 8);
LAB_0037d58b:
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x58e,"_kgspProcessRpcEvent",1,
                   "NVRM: received event from GPU%d: 0x%x (%s) status: 0x%x size: %d\n",
                   *(undefined4 *)(param_1 + 0x7a4),uVar24,pcVar19,*(undefined4 *)(lVar18 + 0x10),
                   *(undefined4 *)(lVar18 + 8),in_stack_fffffffffffffef8);
      _kgspAddRpcHistoryEntry(lVar9,lVar1,lVar9 + 0x2d20);
      if (param_5 == 1) {
        cVar5 = rmapiLockIsOwner();
        if (cVar5 == '\0') {
          uVar8 = *(int *)(lVar18 + 0xc) - 0x1001;
          if (uVar8 < 0x27) goto LAB_0037db36;
LAB_0037db4a:
          if (uVar24 < 0xe5) {
            pcVar19 = *(char **)(rpcName_40 + (ulong)uVar24 * 8);
          }
          else {
LAB_0037db5d:
            pcVar19 = "Unknown";
            if (uVar24 - 0x1001 < 0x29) {
              pcVar19 = *(char **)(rpcName_40 + (ulong)(uVar24 - 0xf1a) * 8);
            }
          }
          nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x5a5,"_kgspProcessRpcEvent",4,
                       "NVRM: Attempted to process RPC event from GPU%d: 0x%x (%s) during bootup without API lock\n"
                       ,*(undefined4 *)(param_1 + 0x7a4),uVar24,pcVar19);
          nvAssertFailedNoLog(&DAT_00d3972a,"src/kernel/gpu/gsp/kernel_gsp.c",0x5a7);
          uVar20 = extraout_RDX_05;
        }
        else {
          uVar20 = extraout_RDX;
          if (uVar24 < 0x1018) {
joined_r0x0037d8ea:
            if (uVar24 < 0x1009) {
              if (uVar24 == 0x1005) {
                osQueueMMUFaultHandler(param_1);
                uVar20 = extraout_RDX_21;
              }
              else if (uVar24 < 0x1006) {
                if (uVar24 == 0x1003) {
                  lVar18 = *(long *)(lVar9 + 0x4d8);
                  local_80 = 0;
                  cVar5 = CliGetEventInfo(*(undefined4 *)(lVar18 + 0x20),
                                          *(undefined4 *)(lVar18 + 0x24),&local_80);
                  if (cVar5 == '\0') {
                    nvAssertFailedNoLog("CliGetEventInfo(rpc_params->hClient, rpc_params->hEvent, &pEvent)"
                                        ,"src/kernel/gpu/gsp/kernel_gsp.c",0x20d);
LAB_0037eb37:
                    iVar6 = 0x57;
                  }
                  else {
                    lVar15 = *(long *)(local_80 + 0xd8);
                    if (lVar15 == 0) {
                      iVar6 = 0x3d;
                      nvAssertFailedNoLog("pEvent->pNotifierShare != NULL",
                                          "src/kernel/gpu/gsp/kernel_gsp.c",0x210);
                    }
                    else {
                      lVar11 = *(long *)(lVar15 + 0xa8);
                      iVar6 = __nvoc_objGetClassId(*(undefined8 *)(lVar15 + 0x98));
                      if (iVar6 == 0x4b01b3) {
                        iVar6 = *(int *)(lVar18 + 0x28);
                        if ((iVar6 == 0x70) &&
                           (*(char *)(*(long *)(param_1 + 0x1b78) + 0x443) != '\0')) {
                          iVar6 = heapStorePendingBlackList_IMPL
                                            (param_1,*(undefined8 *)
                                                      (*(long *)(param_1 + 0x1b78) + 0x478),
                                             *(undefined8 *)(lVar18 + 0x3d),
                                             *(undefined8 *)(lVar18 + 0x3d));
                          if (iVar6 == 0) {
                            cVar5 = *(char *)(lVar18 + 0x3c);
                          }
                          else if (iVar6 == 0x62) {
                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1ea,
                                         "_kgspProcessEccNotifier",1,
                                         "NVRM: Since we hit the DED on the reserved region, nothing to handle in this code path... \n"
                                         ,0x62);
                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1eb,
                                         "_kgspProcessEccNotifier",1,
                                         "NVRM: Relying on FBHUB interrupt to kill all the channels and force reset the GPU..\n"
                                        );
                            cVar5 = *(char *)(lVar18 + 0x3c);
                          }
                          else {
                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1ef,
                                         "_kgspProcessEccNotifier",1,
                                         "NVRM: Dynamically blacklisting the DED page offset failed with, status: %x\n"
                                         ,iVar6);
                            cVar5 = *(char *)(lVar18 + 0x3c);
                          }
                          if (cVar5 != '\0') {
                            iVar6 = *(int *)(lVar18 + 0x28);
LAB_0037eacb:
                            gpuNotifySubDeviceEvent_IMPL
                                      (param_1,iVar6,lVar18 + 0x3d,*(undefined4 *)(lVar18 + 0x38),
                                       *(undefined4 *)(lVar18 + 0x2c),*(undefined2 *)(lVar18 + 0x30)
                                      );
                            uVar20 = extraout_RDX_52;
                            goto LAB_0037dd90;
                          }
                        }
                        else if (*(char *)(lVar18 + 0x3c) != '\0') goto LAB_0037eacb;
LAB_0037deb0:
                        if (lVar11 != 0) {
                          do {
                            if (*(int *)(lVar11 + 4) == *(int *)(lVar18 + 0x24)) {
                              iVar6 = osNotifyEvent(param_1,lVar11,0,*(undefined4 *)(lVar18 + 0x2c),
                                                    *(undefined4 *)(lVar18 + 0x34));
                              uVar20 = extraout_RDX_15;
                              if (iVar6 == 0) goto LAB_0037dd90;
                              nvAssertOkFailedNoLog
                                        (iVar6,
                                         "osNotifyEvent(pGpu, pNotifyEvent, 0, rpc_params->data, rpc_params->status)"
                                         ,"src/kernel/gpu/gsp/kernel_gsp.c",0x243);
                              goto LAB_0037df2c;
                            }
                            lVar11 = *(long *)(lVar11 + 0x40);
                          } while (lVar11 != 0);
                        }
                        nvAssertFailedNoLog("pNotifyEvent != NULL","src/kernel/gpu/gsp/kernel_gsp.c"
                                            ,0x248);
                        goto LAB_0037eb37;
                      }
                      if (*(char *)(lVar18 + 0x3c) == '\0') goto LAB_0037deb0;
                      iVar6 = osEventNotificationWithInfo
                                        (param_1,lVar11,*(undefined4 *)(lVar18 + 0x28),
                                         *(undefined4 *)(lVar18 + 0x2c),
                                         *(undefined2 *)(lVar18 + 0x30),lVar18 + 0x3d,
                                         *(undefined4 *)(lVar18 + 0x38));
                      uVar20 = extraout_RDX_46;
                      if (iVar6 == 0) goto LAB_0037dd90;
                      nvCheckOkFailedNoLog
                                (4,iVar6,
                                 "osEventNotificationWithInfo(pGpu, pNotifyList, rpc_params->notifyIndex, rpc_params->data, rpc_params->info16, rpc_params->eventData, rpc_params->eventDataSize)"
                                 ,"src/kernel/gpu/gsp/kernel_gsp.c",0x232);
                    }
                  }
                }
                else {
                  if (uVar24 != 0x1004) {
                    uVar7 = *(undefined4 *)(lVar18 + 0x18);
                    if (uVar24 < 0xe5) goto LAB_0037e730;
                    if (0x28 < uVar24 - 0x1001) goto LAB_0037e9c6;
                    goto LAB_0037ee3a;
                  }
                  lVar18 = *(long *)(lVar9 + 0x4d8);
                  uVar16 = *(undefined8 *)(param_1 + 0x1c18);
                  uVar10 = gpuGetKernelFifoShared_IMPL(param_1);
                  uVar7 = gpuGetRmEngineType_IMPL(*(undefined4 *)(lVar18 + 0x20));
                  krcCheckBusError_KERNEL(param_1,uVar16);
                  if (*(int *)(lVar18 + 0x30) == 0x8d) {
                    lVar18 = gpuGetRpc(param_1);
                    if (lVar18 == 0) {
                      iVar6 = 0x1a;
                      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x26f);
                      nvAssertOkFailedNoLog(0x1a,"status","src/kernel/gpu/gsp/kernel_gsp.c",0x270);
                    }
                    else {
                      iVar6 = (**(code **)(lVar18 + 0x48))(param_1,lVar18,*(code **)(lVar18 + 0x48))
                      ;
                      uVar20 = extraout_RDX_53;
                      if (iVar6 == 0) goto LAB_0037dd90;
                      nvAssertOkFailedNoLog(iVar6,"status","src/kernel/gpu/gsp/kernel_gsp.c",0x270);
                    }
                  }
                  else {
                    iVar6 = kfifoGetChidMgrFromType_IMPL(param_1,uVar10,2,uVar7,&local_80);
                    if (iVar6 == 0) {
                      if (*(int *)(lVar18 + 0x28) == 0) {
                        local_e8 = kfifoChidMgrGetKernelChannel_IMPL
                                             (param_1,uVar10,local_80,*(undefined4 *)(lVar18 + 0x24)
                                             );
                        local_ec = 0;
                        if (local_e8 == 0) {
                          nvCheckFailedNoLog(4,"pKernelChannel != NULL",
                                             "src/kernel/gpu/gsp/kernel_gsp.c",0x280);
                          iVar6 = 0x21;
                          goto LAB_0037df2c;
                        }
                        local_b8 = *(long *)(g_pSys + 0x228);
                        uVar8 = rcdbGetOcaRecordSizeWithHeader_IMPL(local_b8,0x93);
                        local_f4 = (uint)*(ushort *)(local_b8 + 0x2f8);
                        lVar15 = __nvoc_dynamicCast(**(undefined8 **)
                                                      (*(long *)(local_e8 + 0x140) + 0x48),
                                                    __nvoc_class_def_RmClient);
                        if (lVar15 == 0) {
                          nvAssertFailedNoLog("pClient != NULL","src/kernel/gpu/gsp/kernel_gsp.c",
                                              0x294);
                          bVar4 = true;
                        }
                        else {
                          local_ec = *(undefined4 *)(lVar15 + 0x118);
                          bVar4 = true;
                        }
                      }
                      else {
                        local_b8 = *(long *)(g_pSys + 0x228);
                        uVar8 = rcdbGetOcaRecordSizeWithHeader_IMPL(local_b8,0x93);
                        bVar4 = false;
                        local_ec = 0;
                        local_e8 = 0;
                        local_f4 = (uint)*(ushort *)(local_b8 + 0x2f8);
                      }
                      if (uVar8 <= *(uint *)(lVar18 + 0x4c)) {
                        uVar23 = 0;
                        uVar22 = 0;
                        do {
                          lVar15 = lVar18 + 0x50 + (ulong)uVar23;
                          lVar11 = rcdbAddRcDiagRecFromGsp_IMPL
                                             (param_1,local_b8,lVar15,lVar15 + 0x28);
                          if (lVar11 == 0) {
                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x2b0,
                                         "_kgspRpcRCTriggered",3,
                                         "NVRM: Lost RC diagnostic record coming from GPU%d GSP: type=0x%x stateMask=0x%llx\n"
                                         ,*(undefined4 *)(param_1 + 0x7a4),
                                         *(undefined2 *)(lVar15 + 0x30),
                                         *(undefined8 *)(lVar15 + 0x18));
                          }
                          uVar22 = uVar22 + 1;
                          uVar23 = uVar23 + uVar8;
                        } while (uVar22 < *(uint *)(lVar18 + 0x4c) / uVar8);
                      }
                      if (*(ushort *)(local_b8 + 0x2f8) - 1 != local_f4) {
                        rcdbUpdateRcDiagRecContext_IMPL
                                  (local_b8,local_f4,*(ushort *)(local_b8 + 0x2f8) - 1,local_ec,0);
                      }
                      cVar5 = gpuIsCCFeatureEnabled_IMPL(param_1);
                      if (((cVar5 == '\0') || (!bVar4)) ||
                         (iVar6 = krcErrorSetNotifier_IMPL
                                            (param_1,uVar16,local_e8,*(undefined4 *)(lVar18 + 0x30),
                                             uVar7,*(undefined4 *)(lVar18 + 0x34)), iVar6 == 0)) {
                        iVar6 = krcErrorSendEventNotifications_KERNEL
                                          (param_1,uVar16,local_e8,uVar7,
                                           *(undefined4 *)(lVar18 + 0x2c),
                                           *(undefined4 *)(lVar18 + 0x30),
                                           *(undefined4 *)(lVar18 + 0x34),
                                           *(undefined2 *)(lVar18 + 0x38),0);
                        uVar20 = extraout_RDX_48;
                        goto LAB_0037dd0c;
                      }
                      nvAssertOkFailedNoLog
                                (iVar6,
                                 "krcErrorSetNotifier(pGpu, pKernelRc, pKernelChannel, rpc_params->exceptType, rmEngineType, rpc_params->scope)"
                                 ,"src/kernel/gpu/gsp/kernel_gsp.c",0x2c7);
                    }
                  }
                }
LAB_0037df2c:
                nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x652,"_kgspProcessRpcEvent",4,
                             "NVRM: Failed to process received event 0x%x (%s) from GPU%d: status=0x%x\n"
                             ,uVar24,*(undefined8 *)(rpcName_40 + (ulong)(uVar24 - 0xf1a) * 8),
                             *(undefined4 *)(param_1 + 0x7a4),iVar6);
                uVar20 = extraout_RDX_16;
              }
              else {
                if (uVar24 != 0x1006) {
LAB_0037ee36:
                  uVar7 = *(undefined4 *)(lVar18 + 0x18);
LAB_0037ee3a:
                  pcVar19 = *(char **)(rpcName_40 + (ulong)(uVar24 - 0xf1a) * 8);
                  goto LAB_0037e73a;
                }
                lVar18 = *(long *)(lVar9 + 0x4d8);
                lVar15 = *(long *)(param_1 + 0x1c18);
                uVar10 = gpuGetKernelFifoShared_IMPL(param_1);
                uVar16 = 0;
                if (*(int *)(lVar18 + 0x2c) != -1) {
                  lVar11 = kfifoGetChidMgr_IMPL(param_1,uVar10,*(undefined4 *)(lVar18 + 0x28));
                  uVar16 = 0;
                  if (lVar11 != 0) {
                    uVar16 = kfifoChidMgrGetKernelChannel_IMPL
                                       (param_1,uVar10,lVar11,*(undefined4 *)(lVar18 + 0x2c));
                  }
                }
                uVar10 = *(undefined8 *)(lVar18 + 0x20);
                *(undefined8 *)(lVar15 + 400) = uVar16;
                nvErrorLog2_va(param_1,uVar10,0,0,&DAT_00d3976f,lVar18 + 0x30);
                *(undefined8 *)(lVar15 + 400) = 0;
                uVar20 = extraout_RDX_20;
              }
            }
            else if (uVar24 == 0x100b) {
              lVar18 = *(long *)(lVar9 + 0x4d8);
              iVar6 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(lVar18 + 0x38),&local_88);
              uVar20 = extraout_RDX_23;
              if ((iVar6 == 0) &&
                 (iVar6 = deviceGetByHandle_IMPL(local_88,*(undefined4 *)(lVar18 + 0x3c),&local_80),
                 uVar20 = extraout_RDX_24, iVar6 == 0)) {
                dispswReleaseSemaphoreAndNotifierFill
                          (param_1,*(undefined8 *)(lVar18 + 0x20),*(undefined4 *)(lVar18 + 0x28),
                           *(undefined4 *)(lVar18 + 0x2c),*(undefined4 *)(lVar18 + 0x30),
                           *(undefined4 *)(lVar18 + 0x34),local_80);
                uVar20 = extraout_RDX_25;
              }
            }
            else if (uVar24 == 0x100c) {
              lVar18 = *(long *)(lVar9 + 0x4d8);
              if (*(int *)(lVar18 + 0x20) != -0xc28de00) {
                nvAssertFailedNoLog("Attempting to use libos prints with an unsupported ucode!\n",
                                    "src/kernel/gpu/gsp/kernel_gsp.c",0x483);
                goto LAB_0037df26;
              }
              if (*(long *)(param_1 + 0x1c28) == 0) {
                nvCheckFailedNoLog(4,"pKernelPmu != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x47b);
                goto LAB_0037eb37;
              }
              kpmuLogBuf_IMPL(param_1,*(long *)(param_1 + 0x1c28),lVar18 + 0x28,
                              *(undefined4 *)(lVar18 + 0x24));
              uVar20 = extraout_RDX_30;
            }
            else if (uVar24 == 0x1009) {
              if (*(char *)(param_1 + 0x490e) == '\0') {
LAB_0037df26:
                iVar6 = 0x56;
                goto LAB_0037df2c;
              }
              lVar18 = *(long *)(lVar9 + 0x4d8);
              if (0x10000 < *(uint *)(lVar18 + 0x124)) {
                iVar6 = 2;
                nvAssertFailedNoLog("rpc_params->count <= sizeof(pKernelGsp->pSimAccessBuf->data)",
                                    "src/kernel/gpu/gsp/kernel_gsp.c",0x40f);
                goto LAB_0037df2c;
              }
              uVar24 = *(uint *)(lVar18 + 0x120);
              lVar15 = *(long *)(param_1 + 0x1ba8);
              uVar8 = (*(uint *)(lVar18 + 0x124) >> 2) + uVar24;
              for (; uVar24 < uVar8; uVar24 = uVar24 + 1) {
                gpuSimEscapeRead(param_1,lVar18 + 0x20,uVar24,4,&local_80);
                *(uint *)(*(long *)(lVar15 + 0x69f18) + (ulong)uVar24 * 4) = (uint)local_80;
                uVar20 = extraout_RDX_01;
              }
              piVar2 = (int *)(*(long *)(lVar15 + 0x69f18) + 0x10000);
              *piVar2 = *piVar2 + 1;
            }
            else {
              if (*(char *)(param_1 + 0x490e) == '\0') goto LAB_0037df26;
              lVar18 = *(long *)(lVar9 + 0x4d8);
              lVar15 = *(long *)(param_1 + 0x1ba8);
              gpuSimEscapeWrite(param_1,lVar18 + 0x20,*(undefined4 *)(lVar18 + 0x120),
                                *(undefined4 *)(lVar18 + 0x124),*(undefined4 *)(lVar18 + 0x128));
              piVar2 = (int *)(*(long *)(lVar15 + 0x69f18) + 0x10000);
              *piVar2 = *piVar2 + 1;
              uVar20 = extraout_RDX_50;
            }
          }
          else {
LAB_0037d9e6:
            if (uVar24 < 0x1027) {
              if (uVar24 == 0x1023) {
                lVar18 = *(long *)(lVar9 + 0x4d8);
                nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x6d8,"_kgspRpcGspTriggerBugcheck",4,
                             "NVRM: Received signal from GSP to trigger bugcheck! BugCode=0x%x\n",
                             *(undefined4 *)(lVar18 + 0x20));
                osBugCheck(*(undefined4 *)(lVar18 + 0x20));
                uVar20 = extraout_RDX_32;
              }
              else if (uVar24 < 0x1024) {
                if (uVar24 == 0x1021) {
                  lVar18 = *(long *)(lVar9 + 0x4d8);
                  if (*(byte *)(lVar18 + 0x24) - 1 < 2) {
                    puVar17 = (undefined4 *)portMemAllocNonPaged(8);
                    if (puVar17 == (undefined4 *)0x0) {
                      nvAssertFailedNoLog("pErrorReport != NULL","src/kernel/gpu/gsp/kernel_gsp.c",
                                          0x671);
LAB_0037eb14:
                      iVar6 = 0x51;
                    }
                    else {
                      *puVar17 = *(undefined4 *)(lVar18 + 0x20);
                      puVar17[1] = (uint)*(byte *)(lVar18 + 0x24);
                      iVar6 = osQueueWorkItem(param_1,_kgspRpcGspEventHandleFecsBufferError,puVar17,
                                              0x120);
                      uVar20 = extraout_RDX_49;
                      if (iVar6 == 0) goto LAB_0037dd90;
                      portMemFree(puVar17);
                    }
                  }
                  else {
LAB_0037df99:
                    iVar6 = 0x3b;
                  }
                  goto LAB_0037df2c;
                }
                lVar18 = *(long *)(lVar9 + 0x4d8);
                uVar8 = *(uint *)(lVar18 + 0x20);
                if (uVar8 == 2) {
                  sysSetRecoveryRebootRequired_IMPL(g_pSys,*(undefined1 *)(lVar18 + 0x24));
                  uVar20 = extraout_RDX_54;
                }
                else if (uVar8 < 3) {
                  if (uVar8 == 0) {
                    (**(code **)(param_1 + 0x140))(param_1,0);
                    uVar20 = extraout_RDX_47;
                  }
                  else {
                    gpuSetRecoveryDrainP2P_KERNEL(param_1,*(undefined1 *)(lVar18 + 0x24));
                    uVar20 = extraout_RDX_02;
                  }
                }
                else {
                  if (uVar8 != 3) goto LAB_0037df99;
                  gpuSetRecoveryRebootRequired_IMPL
                            (param_1,*(undefined1 *)(lVar18 + 0x24),
                             *(undefined1 *)(param_1 + 0x4a7c));
                  uVar20 = extraout_RDX_51;
                }
              }
              else {
                if (uVar24 != 0x1025) goto LAB_0037ee36;
                lVar18 = *(long *)(param_1 + 0x1ba8);
                nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x6c8,
                             "_kgspRpcGspForcedDriverShutdown",4,
                             "NVRM: Forcing driver shutdown by error injection test, marking GPU%d for reset!\n"
                             ,*(undefined4 *)(param_1 + 0x7a4));
                (**(code **)(param_1 + 0x100))(param_1);
                *(undefined1 *)(lVar18 + 0x69eff) = 1;
                uVar20 = extraout_RDX_31;
              }
            }
            else if (uVar24 == 0x1028) {
              lVar18 = *(long *)(lVar9 + 0x4d8);
              lVar15 = *(long *)(param_1 + 0x1cf8);
              local_80 = 0;
              *(undefined4 *)(lVar15 + 0x168) = *(undefined4 *)(lVar18 + 0x20);
              *(undefined4 *)(lVar15 + 0x174) = *(undefined4 *)(lVar18 + 0x24);
              *(undefined4 *)(lVar15 + 0x178) = *(undefined4 *)(lVar18 + 0x28);
              *(undefined8 *)(lVar15 + 0x180) = *(undefined8 *)(lVar18 + 0x30);
              gpuNotifySubDeviceEvent_IMPL(param_1,1,&local_80,8,0,0);
              uVar20 = extraout_RDX_26;
            }
            else {
              if (uVar24 != 0x1029) {
                if (uVar24 == 0x1027) {
                  iVar6 = (**(code **)(*(long *)(param_1 + 0x1ba8) + 0x9f8))
                                    (param_1,*(long *)(param_1 + 0x1ba8),
                                     *(long *)(lVar9 + 0x4d8) + 0x20);
                  uVar20 = extraout_RDX_09;
                  goto LAB_0037dd0c;
                }
                uVar7 = *(undefined4 *)(lVar18 + 0x18);
                pcVar19 = "Unknown";
                goto LAB_0037e73a;
              }
              lVar18 = *(long *)(param_1 + 0x1ba8);
              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x695,"_kgspRpcGspEventPmuHalted",4,
                           "NVRM: Received signal from GSP that PMU has halted.\n");
              *(undefined1 *)(lVar18 + 0x69eff) = 1;
              uVar20 = extraout_RDX_10;
            }
          }
        }
      }
      else {
        uVar7 = *(undefined4 *)(lVar18 + 0x18);
        if (uVar24 < 0xe5) {
LAB_0037e730:
          pcVar19 = *(char **)(rpcName_40 + (ulong)uVar24 * 8);
        }
        else {
LAB_0037e9c6:
          pcVar19 = "Unknown";
        }
LAB_0037e73a:
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x647,"_kgspProcessRpcEvent",4,
                     "NVRM: Unexpected RPC event from GPU%d: 0x%x (%s), sequence: %u\n",
                     *(undefined4 *)(param_1 + 0x7a4),uVar24,pcVar19,uVar7);
        uVar20 = extraout_RDX_45;
      }
    }
    else {
      pcVar19 = "Unknown";
      if (0x28 < uVar24 - 0x1001) goto LAB_0037d58b;
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x58e,"_kgspProcessRpcEvent",1,
                   "NVRM: received event from GPU%d: 0x%x (%s) status: 0x%x size: %d\n",
                   *(undefined4 *)(param_1 + 0x7a4),uVar24,
                   *(undefined8 *)(rpcName_40 + (ulong)(uVar24 - 0xf1a) * 8),
                   *(undefined4 *)(lVar18 + 0x10),*(undefined4 *)(lVar18 + 8),
                   in_stack_fffffffffffffef8);
      _kgspAddRpcHistoryEntry(lVar9,lVar1,lVar9 + 0x2d20);
      uVar20 = extraout_RDX_00;
      if ((param_5 == 1) && (cVar5 = rmapiLockIsOwner(), uVar20 = extraout_RDX_55, cVar5 == '\0')) {
        uVar8 = *(int *)(lVar18 + 0xc) - 0x1001;
        if (0x26 < uVar8) goto LAB_0037db5d;
LAB_0037db36:
        uVar20 = 0x6088000821;
        if ((0x6088000821U >> ((ulong)uVar8 & 0x3f) & 1) == 0) goto LAB_0037db4a;
      }
      if (uVar24 == 0x1017) {
        iVar6 = knvlinkInbandMsgCallbackDispatcher_IMPL
                          (param_1,*(undefined8 *)(param_1 + 0x1ce8),
                           *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20),
                           *(long *)(lVar9 + 0x4d8) + 0x24);
        uVar20 = extraout_RDX_41;
        if (iVar6 != 0) {
          nvAssertFailedNoLog("NV_OK == knvlinkInbandMsgCallbackDispatcher(pGpu, pKernelNvlink, dest->dataSize, dest->data)"
                              ,"src/kernel/gpu/gsp/kernel_gsp.c",0x3c9);
          uVar20 = extraout_RDX_42;
        }
      }
      else if (uVar24 < 0x1018) {
        if (uVar24 == 0x100d) {
          if (*(char *)(param_1 + 0x4a4e) == '\0') goto LAB_0037df26;
          gpuGspPluginTriggeredEvent_IMPL
                    (param_1,*(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20),
                     *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x24));
          uVar20 = extraout_RDX_36;
        }
        else if (uVar24 < 0x100e) {
          if (uVar24 != 0x1008) goto joined_r0x0037d8ea;
          uVar20 = *(ulong *)(g_pSys + 0x218);
          lVar18 = (ulong)*(uint *)(param_1 + 0x7a4) * 0x10f0;
          puVar3 = *(undefined1 **)(uVar20 + 0x60 + lVar18);
          if (puVar3 != (undefined1 *)0x0) {
            lVar15 = *(long *)(lVar9 + 0x4d8);
            portMemSet(puVar3,0,0xda50);
            *puVar3 = *(undefined1 *)(lVar15 + 0x20);
            *(undefined4 *)(puVar3 + 4) = *(undefined4 *)(lVar15 + 0x24);
            *(undefined4 *)(puVar3 + 8) = *(undefined4 *)(lVar15 + 0x28);
            *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(lVar15 + 0x2c);
            puVar13 = (undefined8 *)(puVar3 + 0x10);
            puVar21 = (undefined8 *)(lVar15 + 0x30);
            do {
              puVar14 = puVar13 + 0x61;
              *puVar13 = *puVar21;
              *(undefined4 *)(puVar13 + 1) = *(undefined4 *)(puVar21 + 1);
              *(undefined4 *)(puVar13 + 2) = *(undefined4 *)((long)puVar21 + 0xc);
              *(undefined4 *)((long)puVar13 + 0x14) = *(undefined4 *)(puVar21 + 2);
              *(undefined4 *)(puVar13 + 0x11) = *(undefined4 *)((long)puVar21 + 0x14);
              *(undefined4 *)(puVar13 + 0x12) = *(undefined4 *)(puVar21 + 3);
              *(undefined4 *)((long)puVar13 + 0x94) = *(undefined4 *)((long)puVar21 + 0x1c);
              *(undefined4 *)(puVar13 + 0x21) = *(undefined4 *)(puVar21 + 4);
              *(undefined4 *)(puVar13 + 0x22) = *(undefined4 *)((long)puVar21 + 0x24);
              *(undefined4 *)((long)puVar13 + 0x114) = *(undefined4 *)(puVar21 + 5);
              *(undefined4 *)(puVar13 + 0x31) = *(undefined4 *)((long)puVar21 + 0x2c);
              *(undefined4 *)(puVar13 + 0x32) = *(undefined4 *)(puVar21 + 6);
              *(undefined4 *)((long)puVar13 + 0x194) = *(undefined4 *)((long)puVar21 + 0x34);
              puVar13 = puVar14;
              puVar21 = puVar21 + 7;
            } while (puVar14 != (undefined8 *)(puVar3 + 0xda50));
            gpuacctProcessGpuUtil(uVar20 + 0x48 + lVar18,puVar3 + 0x10);
            uVar20 = extraout_RDX_37;
          }
        }
        else if (uVar24 == 0x1013) {
          iVar6 = knvlinkInbandMsgCallbackDispatcher_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x1ce8),
                             *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20),
                             *(long *)(lVar9 + 0x4d8) + 0x24);
          uVar20 = extraout_RDX_39;
          if (iVar6 != 0) {
            nvAssertFailedNoLog("NV_OK == knvlinkInbandMsgCallbackDispatcher(pGpu, pKernelNvlink, dest->dataSize, dest->data)"
                                ,"src/kernel/gpu/gsp/kernel_gsp.c",0x38d);
            uVar20 = extraout_RDX_40;
          }
        }
        else if (uVar24 < 0x1014) {
          if (uVar24 == 0x1010) {
            if (4 < *(uint *)(*(long *)(lVar9 + 0x4d8) + 0x20)) {
              nvAssertFailedNoLog("rpc_params->notifyIndex < NVA081_NOTIFIERS_MAXCOUNT",
                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x4a1);
LAB_0037ebbd:
              iVar6 = 0x1f;
              goto LAB_0037df2c;
            }
            CliNotifyVgpuConfigEvent(param_1);
            uVar20 = extraout_RDX_34;
          }
          else if (uVar24 < 0x1011) {
            if (uVar24 == 0x100e) {
              local_80 = CONCAT35(local_80._5_3_,*(undefined5 *)(*(long *)(lVar9 + 0x4d8) + 0x20));
              local_78 = *(undefined8 *)(*(long *)(lVar9 + 0x4d8) + 0x28);
              kperfDoSyncGpuBoostLimits_IMPL(param_1,*(undefined8 *)(param_1 + 0x1c10),&local_80);
              uVar20 = extraout_RDX_17;
            }
            else {
              kPerfGpuBoostSyncBridgelessUpdateInfo
                        (param_1,*(undefined1 *)(*(long *)(lVar9 + 0x4d8) + 0x20));
              uVar20 = extraout_RDX_03;
            }
          }
          else {
            if (uVar24 != 0x1012) goto LAB_0037ee36;
            lVar18 = *(long *)(lVar9 + 0x4d8);
            extdevGsyncService(param_1,*(undefined1 *)(lVar18 + 0x20),*(undefined1 *)(lVar18 + 0x21)
                               ,*(undefined1 *)(lVar18 + 0x22),*(undefined1 *)(lVar18 + 0x23));
            uVar20 = extraout_RDX_33;
          }
        }
        else if (uVar24 == 0x1015) {
          iVar6 = knvlinkInbandMsgCallbackDispatcher_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x1ce8),
                             *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20),
                             *(long *)(lVar9 + 0x4d8) + 0x24);
          uVar20 = extraout_RDX_27;
          if (iVar6 != 0) {
            nvAssertFailedNoLog("NV_OK == knvlinkInbandMsgCallbackDispatcher(pGpu, pKernelNvlink, dest->dataSize, dest->data)"
                                ,"src/kernel/gpu/gsp/kernel_gsp.c",0x3ab);
            uVar20 = extraout_RDX_28;
          }
        }
        else if (uVar24 == 0x1016) {
          iVar6 = knvlinkInbandMsgCallbackDispatcher_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x1ce8),
                             *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20),
                             *(long *)(lVar9 + 0x4d8) + 0x24);
          uVar20 = extraout_RDX_11;
          if (iVar6 != 0) {
            nvAssertFailedNoLog("NV_OK == knvlinkInbandMsgCallbackDispatcher(pGpu, pKernelNvlink, dest->dataSize, dest->data)"
                                ,"src/kernel/gpu/gsp/kernel_gsp.c",0x3ba);
            uVar20 = extraout_RDX_12;
          }
        }
        else {
          iVar6 = knvlinkInbandMsgCallbackDispatcher_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x1ce8),
                             *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20),
                             *(long *)(lVar9 + 0x4d8) + 0x24);
          uVar20 = extraout_RDX_07;
          if (iVar6 != 0) {
            nvAssertFailedNoLog("NV_OK == knvlinkInbandMsgCallbackDispatcher(pGpu, pKernelNvlink, dest->dataSize, dest->data)"
                                ,"src/kernel/gpu/gsp/kernel_gsp.c",0x39c);
            uVar20 = extraout_RDX_08;
          }
        }
      }
      else if (uVar24 == 0x1020) {
        lVar18 = *(long *)(lVar9 + 0x4d8);
        lVar15 = *(long *)(g_pSys + 0x228);
        portMemSet(&local_80,0,0x48);
        local_80 = *(ulong *)(lVar18 + 0x28);
        local_78 = CONCAT71(local_78._1_7_,*(undefined1 *)(lVar18 + 0x30));
        local_78 = CONCAT44(*(undefined4 *)(lVar18 + 0x34),(undefined4)local_78);
        local_70 = lVar18 + 0x38;
        local_68 = *(undefined4 *)(lVar18 + 0x7c);
        local_60 = *(undefined8 *)(lVar18 + 0x80);
        local_58 = *(undefined4 *)(lVar18 + 0xd0);
        local_50 = lVar18 + 0xd4;
        local_48 = lVar18 + 0x88;
        local_40 = *(undefined4 *)(lVar18 + 0xcc);
        rcdbNocatInsertNocatError(param_1,&local_80);
        piVar2 = (int *)(lVar15 + 0x4d8);
        *piVar2 = *piVar2 + 1;
        uVar20 = extraout_RDX_43;
      }
      else if (uVar24 < 0x1021) {
        if (uVar24 == 0x101c) {
          pcVar19 = "engaged";
          cVar5 = *(char *)(*(long *)(lVar9 + 0x4d8) + 0x20);
          *(char *)(*(long *)(param_1 + 0x1ba8) + 0x69efd) = cVar5;
          if (cVar5 == '\0') {
            pcVar19 = "disengaged";
          }
          nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x55e,"_kgspRpcGspLockdownNotice",1,
                       "NVRM: GSP lockdown %s\n",pcVar19);
          uVar20 = extraout_RDX_38;
        }
        else if (uVar24 < 0x101d) {
          if (uVar24 == 0x101a) {
            lVar18 = *(long *)(lVar9 + 0x4d8);
            local_78 = 0;
            local_80._0_4_ = (uint)*(byte *)(lVar18 + 0x20);
            local_80 = (ulong)CONCAT14(*(char *)(lVar18 + 0x24),(uint)local_80);
            if (*(char *)(lVar18 + 0x24) == '\x02') {
              local_78 = *(undefined8 *)(lVar18 + 0x28);
            }
            pfmreqhndlrStateSync_IMPL(*(undefined8 *)(g_pSys + 0x220),param_1,&local_80);
            uVar20 = extraout_RDX_35;
          }
          else if (uVar24 == 0x101b) {
            (**(code **)(*(long *)(param_1 + 0x1ce8) + 0x198))
                      (param_1,*(long *)(param_1 + 0x1ce8),
                       *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20));
            uVar20 = extraout_RDX_29;
          }
          else if (uVar24 == 0x1018) {
            lVar18 = *(long *)(lVar9 + 0x4d8);
            iVar6 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(lVar18 + 0x3c),&local_88);
            uVar20 = extraout_RDX_18;
            if ((iVar6 == 0) &&
               (iVar6 = deviceGetByHandle_IMPL(local_88,*(undefined4 *)(lVar18 + 0x40),&local_80),
               uVar20 = extraout_RDX_19, iVar6 == 0)) {
              uVar20 = local_80;
              tsemaRelease_KERNEL(param_1,*(undefined8 *)(lVar18 + 0x20),
                                  *(undefined8 *)(lVar18 + 0x28),*(undefined4 *)(lVar18 + 0x30),
                                  *(undefined4 *)(lVar18 + 0x34),*(undefined4 *)(lVar18 + 0x38));
            }
          }
          else if (*(char *)(*(long *)(lVar9 + 0x4d8) + 0x24) != '\0') {
            knvlinkSetDegradedMode_IMPL
                      (param_1,*(undefined8 *)(param_1 + 0x1ce8),
                       *(undefined4 *)(*(long *)(lVar9 + 0x4d8) + 0x20));
            uVar20 = extraout_RDX_04;
          }
        }
        else if (uVar24 == 0x101e) {
          lVar18 = *(long *)(lVar9 + 0x4d8);
          if (*(int *)(lVar18 + 0x20) != 0) {
            uVar24 = 0;
            lVar15 = lVar18 + 0x24;
            do {
              uVar24 = uVar24 + 1;
              gspTraceEventBufferLogRecord(param_1,lVar15);
              uVar20 = extraout_RDX_22;
              lVar15 = lVar15 + 0x20;
            } while (uVar24 < *(uint *)(lVar18 + 0x20));
          }
        }
        else if (uVar24 == 0x101f) {
          iVar6 = knvlinkFatalErrorRecovery_IMPL
                            (param_1,*(undefined8 *)(param_1 + 0x1ce8),
                             *(undefined1 *)(*(long *)(lVar9 + 0x4d8) + 0x20),
                             *(undefined1 *)(*(long *)(lVar9 + 0x4d8) + 0x21));
          uVar20 = extraout_RDX_13;
          if (iVar6 != 0) {
            nvAssertOkFailedNoLog
                      (iVar6,
                       "knvlinkFatalErrorRecovery(pGpu, pKernelNvlink, pDest->bRecoverable, pDest->bLazy)"
                       ,"src/kernel/gpu/gsp/kernel_gsp.c",0x3ea);
            uVar20 = extraout_RDX_14;
          }
        }
        else {
          lVar18 = *(long *)(lVar9 + 0x4d8);
          if (8 < *(uint *)(lVar18 + 0x20)) {
            nvAssertFailedNoLog("rpc_params->execPartCount <= NVC637_CTRL_MAX_EXEC_PARTITIONS",
                                "src/kernel/gpu/gsp/kernel_gsp.c",0x4d5);
            goto LAB_0037ebbd;
          }
          puVar12 = (uint *)portMemAllocNonPaged(0x2c);
          if (puVar12 == (uint *)0x0) goto LAB_0037eb14;
          uVar8 = *(uint *)(lVar18 + 0x20);
          *puVar12 = uVar8;
          lVar15 = (ulong)uVar8 * 4;
          portMemCopy(puVar12 + 1,lVar15,lVar18 + 0x24,lVar15);
          puVar12[9] = *(uint *)(lVar18 + 0x44);
          *(undefined1 *)(puVar12 + 10) = *(undefined1 *)(lVar18 + 0x48);
          iVar6 = osQueueWorkItem(param_1,_kgspRpcMigCiConfigUpdateCallback,puVar12,0x50);
          uVar20 = extraout_RDX_06;
          if (iVar6 != 0) {
            portMemFree(puVar12);
            goto LAB_0037df2c;
          }
        }
      }
      else {
        if (uVar24 != 0x1026) goto LAB_0037d9e6;
        iVar6 = (**(code **)(*(long *)(param_1 + 0x1ba8) + 0x9f0))
                          (param_1,*(long *)(param_1 + 0x1ba8),*(long *)(lVar9 + 0x4d8) + 0x20);
        uVar20 = extraout_RDX_44;
LAB_0037dd0c:
        if (iVar6 != 0) goto LAB_0037df2c;
      }
    }
LAB_0037dd90:
    _kgspCompleteRpcHistoryEntry(lVar1,*(undefined4 *)(lVar9 + 0x2d20),uVar20);
    kgspDumpGspLogs_IMPL(param_2,0);
  } while( true );
}


// ===== 0037ee50 _kgspFreeLibosLoggingStructures =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kgspFreeLibosLoggingStructures(undefined8 param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  byte bVar3;
  
  bVar3 = 0;
  osRemove1HzCallback(param_1,_kgspLogPollingCallback,0);
  kgspDumpGspLogs_IMPL(param_2,0);
  nvlogDeregisterFlushCb(kgspNvlogFlushCb,param_2);
  libosLogDestroy(param_2 + 0xb50);
  while( true ) {
    uVar1 = (**(code **)(param_2 + 0x968))(param_2);
    if (uVar1 <= bVar3) break;
    lVar2 = (ulong)bVar3 * 0x20 + param_2;
    if (*(long *)(lVar2 + 0x68bd0) != 0) {
      memdescUnmap(*(undefined8 *)(lVar2 + 0x68bc8),1,*(long *)(lVar2 + 0x68bd0),
                   *(undefined8 *)(param_2 + 0x68bd8 + (ulong)bVar3 * 0x20));
      *(undefined8 *)(lVar2 + 0x68bd0) = 0;
      *(undefined8 *)(param_2 + 0x68bd8 + (ulong)bVar3 * 0x20) = 0;
    }
    if (*(long *)(lVar2 + 0x68bc8) != 0) {
      memdescFree();
      memdescDestroy(*(undefined8 *)(lVar2 + 0x68bc8));
      *(undefined8 *)(lVar2 + 0x68bc8) = 0;
    }
    bVar3 = bVar3 + 1;
  }
  portMemFree(*(undefined8 *)(param_2 + 0x69ed0));
  *(undefined8 *)(param_2 + 0x69ed0) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x69ee0));
  *(undefined8 *)(param_2 + 0x69ee0) = 0;
  return;
}


// ===== 0037ef70 kgspConstructEngine_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspConstructEngine_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  undefined8 local_38;
  long local_30;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0x56;
  }
  osReadRegistryDword(param_1,"RmGspWprEndMargin",param_2 + 0xa88);
  iVar3 = osReadRegistryDword(param_1,"RmGspFirmwareHeapSizeMB",param_2 + 0xa8c);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0xa8c) = 0;
  }
  iVar3 = osReadRegistryDword(param_1,"RmGspStallDetection",param_2 + 0x6a5dc);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0x6a5dc) = 1;
  }
  iVar3 = osReadRegistryDword(param_1,"RmGspTimeoutClassification",param_2 + 0x6a5e0);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0x6a5e0) = 1;
  }
  iVar3 = osReadRegistryDword(param_1,"RmGspRpcTimeoutGpuResetThreshold",param_2 + 0x6a5e4);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0x6a5e4) = 3;
  }
  iVar3 = osReadRegistryDword(param_1,"RMGspStateMonitor",param_2 + 0xa90);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0xa90) = 1;
  }
  iVar3 = osReadRegistryDword(param_1,"RmGspPreserveUnloadLogs",param_2 + 0x69ef4);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0x69ef4) = 0;
  }
  (**(code **)(param_2 + 0x7e0))(param_1,param_2);
  local_30 = 0;
  iVar3 = GspMsgQueuesInit(param_1,&local_30);
  lVar1 = local_30;
  if (iVar3 == 0) {
    *(long *)(param_2 + 0xa30) = local_30;
    lVar4 = initRpcObject(param_1);
    if (lVar4 != 0) {
      *(long *)(lVar4 + 0x510) = lVar1 + 0x20;
      portMemSet(lVar4 + 0x518,0,0x1400);
      *(undefined4 *)(lVar4 + 0x1918) = 0x7f;
      portMemSet(lVar4 + 0x1920,0,0x1400);
      lVar1 = *(long *)(lVar4 + 0x510);
      *(undefined4 *)(lVar4 + 0x2d20) = 0x7f;
      *(undefined8 *)(lVar4 + 0x4d8) = *(undefined8 *)(lVar1 + 0x40);
      uVar6 = *(undefined8 *)(lVar1 + 0x20);
      uVar2 = *(undefined8 *)(lVar1 + 0x10);
      *(code **)(lVar4 + 0x18) = _kgspRpcSendMessage;
      *(int *)(lVar4 + 0x4f0) = (int)uVar6 - (int)uVar2;
      *(code **)(lVar4 + 0x20) = _kgspRpcRecvPoll;
      *(long *)(param_2 + 0xa38) = lVar4;
      portMemSet(param_2 + 0x69f70,0,0x638);
      iVar3 = (**(code **)(param_2 + 0x808))(param_1,param_2);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x10b8,"kgspConstructEngine_IMPL",4,
                     "NVRM: boot arg alloc failed: 0x%x\n",iVar3);
        goto LAB_0037f3ea;
      }
      if (*(char *)(param_1 + 0x490e) == '\0') {
LAB_0037f26f:
        uVar6 = 1;
        local_38 = 0;
        local_30 = 0;
        iVar3 = memdescCreate(param_2 + 0x69f28,param_1,0x18,0x1000,0,1,1,0x200000000000);
        if (iVar3 == 0) {
          *(undefined4 *)(*(long *)(param_2 + 0x69f28) + 0x9c) = 0xb1;
          iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x69f28),uVar6);
          if (iVar3 == 0) {
            iVar3 = memdescMap(*(long *)(param_2 + 0x69f28),0,
                               *(undefined8 *)(*(long *)(param_2 + 0x69f28) + 0x30),1,3,&local_38,
                               &local_30);
            if (iVar3 == 0) {
              *(long *)(param_2 + 0x69f38) = local_30;
              *(undefined8 *)(param_2 + 0x69f30) = local_38;
              portMemSet(local_38,0,*(undefined8 *)(*(long *)(param_2 + 0x69f28) + 0x30));
              return 0;
            }
            nvAssertOkFailedNoLog
                      (iVar3,
                       "memdescMap(pKernelGsp->pNotifyOpSurfMemDesc, 0, memdescGetSize(pKernelGsp->pNotifyOpSurfMemDesc), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                       ,"src/kernel/gpu/gsp/kernel_gsp.c",0xff3);
          }
          else {
            nvAssertOkFailedNoLog(iVar3,"nvStatus","src/kernel/gpu/gsp/kernel_gsp.c",0xff1);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "memdescCreate(&pKernelGsp->pNotifyOpSurfMemDesc, pGpu, sizeof(NotifyOpSharedSurface), RM_PAGE_SIZE, NV_FALSE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, flags)"
                     ,"src/kernel/gpu/gsp/kernel_gsp.c",0xfe6);
        }
        if (*(long *)(param_2 + 0x69f28) != 0) {
          memdescUnmap(*(long *)(param_2 + 0x69f28),1,*(undefined8 *)(param_2 + 0x69f30),
                       *(undefined8 *)(param_2 + 0x69f38));
          memdescFree(*(undefined8 *)(param_2 + 0x69f28));
          memdescDestroy(*(undefined8 *)(param_2 + 0x69f28));
        }
        *(undefined8 *)(param_2 + 0x69f28) = 0;
        *(undefined8 *)(param_2 + 0x69f30) = 0;
        *(undefined8 *)(param_2 + 0x69f38) = 0;
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x10c9,"kgspConstructEngine_IMPL",4,
                     "NVRM: notify operation shared surface alloc failed: 0x%x\n",iVar3);
      }
      else {
        local_38 = 0;
        local_30 = 0;
        iVar3 = memdescCreate(param_2 + 0x69f10,param_1,0x10004,0x1000,1,1,1,0);
        if (iVar3 == 0) {
          *(undefined4 *)(*(long *)(param_2 + 0x69f10) + 0x9c) = 0x2e;
          uVar6 = 0x37f203;
          iVar3 = memdescAlloc(*(undefined8 *)(param_2 + 0x69f10));
          if (iVar3 == 0) {
            plVar5 = &local_30;
            iVar3 = memdescMap(*(long *)(param_2 + 0x69f10),0,
                               *(undefined8 *)(*(long *)(param_2 + 0x69f10) + 0x30),1,3,&local_38);
            if (iVar3 == 0) {
              *(long *)(param_2 + 0x69f20) = local_30;
              *(undefined8 *)(param_2 + 0x69f18) = local_38;
              portMemSet(local_38,0,*(undefined8 *)(*(long *)(param_2 + 0x69f10) + 0x30));
              goto LAB_0037f26f;
            }
            nvAssertOkFailedNoLog
                      (iVar3,
                       "memdescMap(pKernelGsp->pMemDesc_simAccessBuf, 0, memdescGetSize(pKernelGsp->pMemDesc_simAccessBuf), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                       ,"src/kernel/gpu/gsp/kernel_gsp.c",0xe7d,plVar5,uVar6);
          }
          else {
            nvAssertOkFailedNoLog(iVar3,"nvStatus","src/kernel/gpu/gsp/kernel_gsp.c",0xe7b);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "memdescCreate(&pKernelGsp->pMemDesc_simAccessBuf, pGpu, sizeof(SimAccessBuffer), RM_PAGE_SIZE, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                     ,"src/kernel/gpu/gsp/kernel_gsp.c",0xe70);
        }
        if (*(char *)(param_1 + 0x490e) != '\0') {
          if (*(long *)(param_2 + 0x69f10) != 0) {
            memdescFree();
            memdescDestroy(*(undefined8 *)(param_2 + 0x69f10));
          }
          *(undefined8 *)(param_2 + 0x69f10) = 0;
          *(undefined8 *)(param_2 + 0x69f18) = 0;
          *(undefined8 *)(param_2 + 0x69f20) = 0;
        }
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x10c1,"kgspConstructEngine_IMPL",4,
                     "NVRM: sim access buffer alloc failed: 0x%x\n",iVar3);
      }
      goto LAB_0037f3ea;
    }
    iVar3 = 0x1a;
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xbbf,"_kgspConstructRpcObject",4,
                 "NVRM: initRpcObject failed\n");
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xb9e,"_kgspInitRpcInfrastructure",4,
                 "NVRM: init task RM RPC infrastructure failed\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xb92,"_kgspInitRpcInfrastructure",4,
                 "NVRM: GspMsgQueueInit failed\n");
  }
  if (*(long *)(param_2 + 0xa38) != 0) {
    (**(code **)(*(long *)(param_2 + 0xa38) + 0x10))(param_1);
    portMemFree(*(undefined8 *)(param_2 + 0xa38));
    *(undefined8 *)(param_2 + 0xa38) = 0;
  }
  GspMsgQueuesCleanup(param_2 + 0xa30);
  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x10a4,"kgspConstructEngine_IMPL",4,
               "NVRM: init RPC infrastructure failed\n");
LAB_0037f3ea:
  if (*(char *)(param_1 + 0x490e) != '\0') {
    if (*(long *)(param_2 + 0x69f10) != 0) {
      memdescFree();
      memdescDestroy(*(undefined8 *)(param_2 + 0x69f10));
    }
    *(undefined8 *)(param_2 + 0x69f10) = 0;
    *(undefined8 *)(param_2 + 0x69f18) = 0;
    *(undefined8 *)(param_2 + 0x69f20) = 0;
  }
  (**(code **)(param_2 + 0x810))(param_1,param_2);
  _kgspFreeLibosLoggingStructures(param_1,param_2);
  if (*(long *)(param_2 + 0xa38) != 0) {
    (**(code **)(*(long *)(param_2 + 0xa38) + 0x10))(param_1);
    portMemFree(*(undefined8 *)(param_2 + 0xa38));
    *(undefined8 *)(param_2 + 0xa38) = 0;
  }
  GspMsgQueuesCleanup(param_2 + 0xa30);
  return iVar3;
}


// ===== 0037f700 kgspDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x7a8);
  }
  lVar1 = gpuEngineGetGpu(uVar2);
  if (*(char *)(lVar1 + 0x909) == '\0') {
    return;
  }
  portStringCopy(param_1 + 0xa40,0x10,"unknown",8);
  kgspFreeFlcnUcode(*(undefined8 *)(param_1 + 0xa50));
  *(undefined8 *)(param_1 + 0xa50) = 0;
  kgspFreeFlcnUcode(*(undefined8 *)(param_1 + 0xa60));
  *(undefined8 *)(param_1 + 0xa60) = 0;
  kgspFreeFlcnUcode(*(undefined8 *)(param_1 + 0xa68));
  *(undefined8 *)(param_1 + 0xa68) = 0;
  kgspFreeFlcnUcode(*(undefined8 *)(param_1 + 0xa58));
  *(undefined8 *)(param_1 + 0xa58) = 0;
  (**(code **)(param_1 + 0x810))(lVar1,param_1);
  portMemFree(*(undefined8 *)(param_1 + 0xb38));
  *(undefined8 *)(param_1 + 0xb38) = 0;
  portMemFree(*(undefined8 *)(param_1 + 0xb48));
  *(undefined8 *)(param_1 + 0xb48) = 0;
  _kgspFreeLibosLoggingStructures(lVar1,param_1);
  if (*(long *)(param_1 + 0xa38) != 0) {
    (**(code **)(*(long *)(param_1 + 0xa38) + 0x10))(lVar1);
    portMemFree(*(undefined8 *)(param_1 + 0xa38));
    *(undefined8 *)(param_1 + 0xa38) = 0;
  }
  GspMsgQueuesCleanup(param_1 + 0xa30);
  _kgspFreeBootBinaryImage_isra_0(param_1);
  if (*(char *)(lVar1 + 0x490e) != '\0') {
    if (*(long *)(param_1 + 0x69f10) != 0) {
      memdescFree();
      memdescDestroy(*(undefined8 *)(param_1 + 0x69f10));
    }
    *(undefined8 *)(param_1 + 0x69f10) = 0;
    *(undefined8 *)(param_1 + 0x69f18) = 0;
    *(undefined8 *)(param_1 + 0x69f20) = 0;
  }
  if (*(long *)(param_1 + 0x69f28) != 0) {
    memdescUnmap(*(long *)(param_1 + 0x69f28),1,*(undefined8 *)(param_1 + 0x69f30),
                 *(undefined8 *)(param_1 + 0x69f38));
    memdescFree(*(undefined8 *)(param_1 + 0x69f28));
    memdescDestroy(*(undefined8 *)(param_1 + 0x69f28));
  }
  *(undefined8 *)(param_1 + 0x69f28) = 0;
  *(undefined8 *)(param_1 + 0x69f30) = 0;
  *(undefined8 *)(param_1 + 0x69f38) = 0;
  if (*(long *)(param_1 + 0x6a5b8) != 0) {
    memdescUnmap(*(undefined8 *)(param_1 + 0x6a5a8),1,*(long *)(param_1 + 0x6a5b8),
                 *(undefined8 *)(param_1 + 0x6a5b0));
    *(undefined8 *)(param_1 + 0x6a5b8) = 0;
  }
  if (*(long *)(param_1 + 0x6a5a8) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_1 + 0x6a5a8));
    *(undefined8 *)(param_1 + 0x6a5a8) = 0;
  }
  if (*(long *)(param_1 + 0x69f68) != 0) {
    memdescUnmap(*(undefined8 *)(param_1 + 0x69f58),1,*(long *)(param_1 + 0x69f68),
                 *(undefined8 *)(param_1 + 0x69f60));
    *(undefined8 *)(param_1 + 0x69f68) = 0;
  }
  if (*(long *)(param_1 + 0x69f58) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_1 + 0x69f58));
    *(undefined8 *)(param_1 + 0x69f58) = 0;
  }
  (**(code **)(param_1 + 0x948))(lVar1,param_1);
  return;
}


// ===== 0037f9b0 _kgspLogPollingCallback =====

void _kgspLogPollingCallback(long param_1)

{
  kgspDumpGspLogs_IMPL(*(undefined8 *)(param_1 + 0x1ba8),0);
  return;
}


// ===== 0037f9d0 kgspUnloadRm_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspUnloadRm_IMPL(long param_1,long param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  
  if (*(char *)(param_2 + 0x69f00) == '\0') {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1412,"kgspUnloadRm_IMPL",1,
                 "NVRM: unloading GSP-RM\n");
    lVar5 = gpuGetRpc(param_1);
    if (lVar5 == 0) {
      iVar3 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x1413);
    }
    else {
      iVar3 = (**(code **)(lVar5 + 0x280))
                        (param_1,lVar5,param_3 != 0,param_3 == 2,param_4,*(code **)(lVar5 + 0x280));
    }
    cVar2 = gpuIsCCFeatureEnabled_IMPL(param_1);
    if (cVar2 != '\0') {
      (**(code **)(param_2 + 0x9e0))(param_1,param_2);
    }
    (**(code **)(param_2 + 0x938))(param_1,param_2);
    *(undefined8 *)(param_2 + 0x6a5c8) = 0;
    *(undefined8 *)(param_2 + 0x6a5d0) = 0;
    kgspDumpGspLogs_IMPL(param_2,*(int *)(param_2 + 0x69ef4) != 0);
    uVar1 = *(uint *)(param_2 + 0x69ef4);
    if (uVar1 != 0) {
      libosPreserveLogs(param_2 + 0xb50,uVar1 & 1,uVar1 >> 1 & 1);
    }
    iVar4 = (**(code **)(param_2 + 0x838))(param_1,param_2,param_3);
    if (((((param_1 == 0) || (*(char *)(param_1 + 0x44f) != '\0')) ||
         (*(char *)(param_1 + 0x450) != '\0')) ||
        ((*(char *)(param_1 + 0x451) != '\0' || (*(char *)(param_1 + 0x461) != '\0')))) &&
       ((*(char *)(param_1 + 0x491d) != '\0' && (*(char *)(param_1 + 0x4a4e) != '\0')))) {
      osDelay(0xfa);
    }
    if (iVar3 == 0) {
      iVar3 = iVar4;
    }
    return iVar3;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x140e,"kgspUnloadRm_IMPL",4,
               "NVRM: skipping attempt to unload GSP-RM after force unload\n");
  return 0;
}


// ===== 0037fbe0 kgspPopulateGspRmInitArgs_IMPL =====

void kgspPopulateGspRmInitArgs_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  uint local_2c [3];
  
  puVar1 = *(undefined8 **)(param_2 + 0xa30);
  puVar2 = *(undefined8 **)(param_2 + 0xae8);
  *puVar2 = puVar1[3];
  *(int *)(puVar2 + 1) = (int)*puVar1;
  lVar3 = puVar1[1];
  puVar2[2] = lVar3;
  puVar2[3] = lVar3 + puVar1[4];
  puVar2[4] = puVar1[6];
  puVar2[5] = puVar1[7];
  puVar2[6] = puVar1[8];
  *(undefined4 *)(puVar2 + 7) = *(undefined4 *)(puVar1 + 9);
  *(undefined4 *)((long)puVar2 + 0x3c) = *(undefined4 *)((long)puVar1 + 0x4c);
  if (param_3 == (undefined4 *)0x0) {
    iVar4 = osReadRegistryDword(param_1,"RmGspStackPlacement",local_2c);
    *(bool *)(puVar2 + 10) = iVar4 != 0 || (local_2c[0] & 0xfffffffd) == 0;
    *(undefined1 *)(puVar2 + 9) = 0;
    puVar2[8] = 0;
  }
  else {
    *(undefined1 *)(puVar2 + 9) = 1;
    *(undefined4 *)(puVar2 + 8) = *param_3;
    *(undefined4 *)((long)puVar2 + 0x44) = param_3[1];
  }
  *(undefined4 *)((long)puVar2 + 0x4c) = *(undefined4 *)(param_1 + 0x7a4);
  portMemSet(puVar2 + 0xb,0,0x10);
  if ((*(long *)(param_2 + 0x69f50) != 0) && (*(long *)(param_2 + 0x69f40) != 0)) {
    uVar5 = memdescGetPhysAddr(*(long *)(param_2 + 0x69f40),1,0);
    puVar2[0xb] = uVar5;
    puVar2[0xc] = *(undefined8 *)(*(long *)(param_2 + 0x69f40) + 0x30);
  }
  if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') {
    puVar2[0xd] = 0;
    uVar5 = 0;
  }
  else {
    uVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xaf8),1,0);
    puVar2[0xd] = uVar5;
    uVar5 = *(undefined8 *)(*(long *)(param_2 + 0xaf8) + 0x30);
  }
  puVar2[0xe] = uVar5;
  portMemSet(puVar2 + 0xf,0,0x10);
  if ((*(long *)(param_2 + 0x69f68) != 0) && (*(long *)(param_2 + 0x69f58) != 0)) {
    uVar5 = memdescGetPhysAddr(*(long *)(param_2 + 0x69f58),1,0);
    puVar2[0xf] = uVar5;
    puVar2[0x10] = *(undefined8 *)(*(long *)(param_2 + 0x69f58) + 0x30);
  }
  return;
}


// ===== 0037fda0 kgspPrepareBootBinaryImage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgspPrepareBootBinaryImage_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30 [2];
  
  local_40 = 0;
  local_38 = 0;
  local_30[0] = 0;
  if (*(long *)(param_2 + 0xb18) == 0) {
    if (*(long *)(param_2 + 0xb20) == 0) {
      (**(code **)(param_2 + 0x840))(param_1,param_2,&local_50,&local_48);
      iVar1 = bindataGetBufferSize(local_50);
      uVar2 = memdescCreate(param_2 + 0xb00,param_1,iVar1 + 0xfffU & 0xfffff000,0x1000,1,1,0);
      if (uVar2 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0xb00) + 0x9c) = 0x30;
        uVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0xb00));
        if (uVar2 == 0) {
          uVar2 = memdescMap(*(long *)(param_2 + 0xb00),0,
                             *(undefined8 *)(*(long *)(param_2 + 0xb00) + 0x30),1,3,&local_38,
                             local_30);
          if (uVar2 == 0) {
            *(int *)(param_2 + 0xb10) = iVar1;
            *(undefined8 *)(param_2 + 0xb18) = local_38;
            *(undefined8 *)(param_2 + 0xb08) = local_30[0];
            uVar2 = bindataWriteToBuffer(local_50,local_38,iVar1,0x37fe75);
            if (uVar2 == 0) {
              uVar3 = bindataStorageAcquireData(local_48,&local_40);
              uVar2 = (uint)uVar3;
              if (uVar2 == 0) {
                *(undefined8 *)(param_2 + 0xb20) = local_40;
                return uVar3;
              }
              nvAssertOkFailedNoLog
                        (uVar3 & 0xffffffff,
                         "bindataStorageAcquireData(pBinStorageDesc, (const void**)&pDesc)",
                         "src/kernel/gpu/gsp/kernel_gsp.c",0x1565);
            }
            else {
              nvAssertOkFailedNoLog
                        (uVar2,
                         "bindataWriteToBuffer(pBinStorageImage, pKernelGsp->pGspRmBootUcodeImage, bufSize)"
                         ,"src/kernel/gpu/gsp/kernel_gsp.c",0x155e);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (uVar2,
                       "memdescMap(pKernelGsp->pGspRmBootUcodeMemdesc, 0, memdescGetSize(pKernelGsp->pGspRmBootUcodeMemdesc), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                       ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1553);
          }
        }
        else {
          nvAssertOkFailedNoLog(uVar2,"status","src/kernel/gpu/gsp/kernel_gsp.c",0x1551);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar2,
                   "memdescCreate(&pKernelGsp->pGspRmBootUcodeMemdesc, pGpu, bufSizeAligned, RM_PAGE_SIZE, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
                   ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1546,0x200000000000);
      }
      _kgspFreeBootBinaryImage_isra_0(param_2);
      return (ulong)uVar2;
    }
    nvAssertFailedNoLog("pKernelGsp->pGspRmBootUcodeDesc == NULL","src/kernel/gpu/gsp/kernel_gsp.c",
                        0x153b);
  }
  else {
    nvAssertFailedNoLog("pKernelGsp->pGspRmBootUcodeImage == NULL","src/kernel/gpu/gsp/kernel_gsp.c"
                        ,0x153a);
  }
  return 0x40;
}


// ===== 00380030 kgspCreateRadix3_IMPL =====

int kgspCreateRadix3_IMPL
              (undefined8 param_1,undefined8 param_2,long *param_3,long param_4,long param_5,
              long param_6)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  int local_98;
  long local_88;
  undefined8 local_80;
  long local_78 [2];
  long local_68;
  long local_60;
  long local_58;
  long local_50;
  ulong local_48;
  long local_40;
  
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("ppMemdescRadix3 != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x1691);
    return 0x3b;
  }
  if ((param_5 != 0) && (param_4 != 0)) {
    nvAssertFailedNoLog("Specify pMemdescData or pData, or none, but not both",
                        "src/kernel/gpu/gsp/kernel_gsp.c",0x1692);
    return 0x3b;
  }
  if (param_6 == 0) {
    if (param_4 != 0) {
      param_6 = *(long *)(param_4 + 0x30);
    }
    if (param_6 == 0) {
      nvAssertFailedNoLog("size > 0","src/kernel/gpu/gsp/kernel_gsp.c",0x1699);
      return 0x5b;
    }
  }
  portMemSet(local_78,0,0x40);
  local_48 = param_6 + 0xfffU >> 0xc;
  uVar6 = local_48 - 1;
  local_78[0] = (uVar6 >> 0x1b) + 1;
  local_68 = (uVar6 >> 0x12) + 1;
  local_58 = (uVar6 >> 9) + 1;
  local_60 = local_78[0] * 0x1000;
  lVar7 = (local_58 + local_68 + local_78[0]) * 0x1000;
  local_50 = (local_68 + local_78[0]) * 0x1000;
  local_40 = lVar7;
  if (local_78[0] != 1) {
    nvAssertFailedNoLog("radix3[0].nPages == 1","src/kernel/gpu/gsp/kernel_gsp.c",0x16ac);
    return 0x5b;
  }
  lVar9 = (param_6 + 0xfffU & 0xfffffffffffff000) + lVar7;
  if (param_4 != 0) {
    lVar9 = lVar7;
  }
  iVar5 = memdescCreate(param_3,param_1,lVar9,0x1000,0,1,0,0x200000000200);
  if (iVar5 == 0) {
    memdescSetPageSize(*param_3,1,0x200000);
    *(undefined4 *)(*param_3 + 0x9c) = 0x32;
    iVar5 = memdescAlloc(*param_3);
    if (iVar5 == 0x51) {
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x16ca,"kgspCreateRadix3_IMPL",1,
                   "NVRM: memdescTagAllocate failed for huge pages, trying again with regular ones\n"
                  );
      memdescSetPageSize(*param_3,1,0x1000);
      *(undefined4 *)(*param_3 + 0x9c) = 0x32;
      iVar5 = memdescAlloc(*param_3);
    }
    if (iVar5 == 0) {
      iVar5 = memdescMap(*param_3,0,lVar9,1,2,&local_88,&local_80);
      lVar4 = local_88;
      if (iVar5 == 0) {
        if (local_88 != 0) {
          plVar8 = local_78;
          portMemSet(local_88,0,lVar7);
          do {
            plVar1 = plVar8 + 1;
            plVar2 = plVar8 + 3;
            plVar3 = plVar8 + 2;
            plVar8 = plVar8 + 2;
            memdescGetPhysAddrs(*param_3,1,*plVar2,0x1000,*plVar3,*plVar1 + lVar4);
            lVar7 = local_40;
          } while (&local_58 != plVar8);
          if (param_5 != 0) {
            portMemCopy(lVar4 + local_40,param_6,param_5,param_6);
            local_98 = (int)lVar9;
            local_98 = local_98 - ((int)lVar7 + (int)param_6);
            if (local_98 != 0) {
              portMemSet(param_6 + lVar7 + lVar4,0,local_98);
            }
          }
          memdescGetPhysAddrs(*param_3,1,lVar7,0x1000,local_48,lVar4 + local_50);
          memdescUnmap(*param_3,1,local_88,local_80);
          return 0;
        }
        iVar5 = 0x51;
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x16d9,"kgspCreateRadix3_IMPL",4,
                     "NVRM: VA error for radix3 shared buffer\n");
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "memdescMap(*ppMemdescRadix3, 0, allocSize, NV_TRUE, NV_PROTECT_WRITEABLE, &pVaKernel, &pPrivKernel)"
                   ,"src/kernel/gpu/gsp/kernel_gsp.c",0x16d2);
      }
    }
    else {
      nvAssertOkFailedNoLog(iVar5,"status","src/kernel/gpu/gsp/kernel_gsp.c",0x16cf);
    }
    if (*param_3 != 0) {
      memdescFree();
      memdescDestroy(*param_3);
      *param_3 = 0;
      return iVar5;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar5,
               "memdescCreate(ppMemdescRadix3, pGpu, allocSize, LIBOS_MEMORY_REGION_RADIX_PAGE_SIZE, NV_MEMORY_NONCONTIGUOUS, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
               ,"src/kernel/gpu/gsp/kernel_gsp.c",0x16bb);
  }
  return iVar5;
}


// ===== 003804d0 __pfx_kgspSetupLibosInitArgs_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __pfx_kgspSetupLibosInitArgs_IMPL(undefined8 param_1,long param_2)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  ulong uVar5;
  byte bVar6;
  
  bVar6 = 0;
  lVar2 = *(long *)(param_2 + 0xad0);
  portMemSet(lVar2,0,0x1000);
  while( true ) {
    uVar5 = (**(code **)(param_2 + 0x968))(param_2);
    lVar3 = (ulong)bVar6 * 0x20;
    puVar1 = (ulong *)(lVar2 + lVar3);
    *(undefined2 *)(puVar1 + 3) = 0x101;
    if (uVar5 <= bVar6) break;
    uVar5 = (ulong)bVar6;
    lVar3 = lVar3 + param_2;
    bVar6 = bVar6 + 1;
    *puVar1 = *(ulong *)(param_2 + 0x68be0 + uVar5 * 0x20);
    puVar1[1] = *(ulong *)(*(long *)(lVar3 + 0x68bd0) + 8);
    puVar1[2] = *(ulong *)(*(long *)(lVar3 + 0x68bc8) + 0x30);
  }
  uVar5 = 0;
  pcVar4 = "RMARGS";
  do {
    bVar6 = *pcVar4;
    if (bVar6 == 0) break;
    pcVar4 = pcVar4 + 1;
    uVar5 = uVar5 << 8 | (ulong)bVar6;
  } while (pcVar4 != &DAT_00d3a779);
  *puVar1 = uVar5;
  uVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xae0),1,0);
  puVar1[1] = uVar5;
  puVar1[2] = *(ulong *)(*(long *)(param_2 + 0xae0) + 0x30);
  LOCK();
  UNLOCK();
  return;
}


// ===== 003804e0 kgspSetupLibosInitArgs_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kgspSetupLibosInitArgs_IMPL(undefined8 param_1,long param_2)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  ulong uVar5;
  byte bVar6;
  
  bVar6 = 0;
  lVar2 = *(long *)(param_2 + 0xad0);
  portMemSet(lVar2,0,0x1000);
  while( true ) {
    uVar5 = (**(code **)(param_2 + 0x968))(param_2);
    lVar3 = (ulong)bVar6 * 0x20;
    puVar1 = (ulong *)(lVar2 + lVar3);
    *(undefined2 *)(puVar1 + 3) = 0x101;
    if (uVar5 <= bVar6) break;
    uVar5 = (ulong)bVar6;
    lVar3 = lVar3 + param_2;
    bVar6 = bVar6 + 1;
    *puVar1 = *(ulong *)(param_2 + 0x68be0 + uVar5 * 0x20);
    puVar1[1] = *(ulong *)(*(long *)(lVar3 + 0x68bd0) + 8);
    puVar1[2] = *(ulong *)(*(long *)(lVar3 + 0x68bc8) + 0x30);
  }
  uVar5 = 0;
  pcVar4 = "RMARGS";
  do {
    bVar6 = *pcVar4;
    if (bVar6 == 0) break;
    pcVar4 = pcVar4 + 1;
    uVar5 = uVar5 << 8 | (ulong)bVar6;
  } while (pcVar4 != &DAT_00d3a779);
  *puVar1 = uVar5;
  uVar5 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0xae0),1,0);
  puVar1[1] = uVar5;
  puVar1[2] = *(ulong *)(*(long *)(param_2 + 0xae0) + 0x30);
  LOCK();
  UNLOCK();
  return;
}


// ===== 003805f9 kgspInitRm_IMPL.cold =====

void kgspInitRm_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00380610 kgspInitRm_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_r15 replaced with injection: x86_indirect_thunk_r15 */

ulong kgspInitRm_IMPL(long param_1,long param_2,long *param_3)

{
  long lVar1;
  byte *pbVar2;
  uint uVar3;
  code *pcVar4;
  byte bVar5;
  char cVar6;
  undefined1 uVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined **ppuVar16;
  long lVar17;
  undefined8 *puVar18;
  undefined8 uVar19;
  long lVar20;
  char *pcVar21;
  undefined8 extraout_RDX;
  ulong *puVar22;
  ulong uVar23;
  ulong uVar24;
  bool bVar25;
  bool bVar26;
  undefined8 uVar27;
  char *local_c8;
  int local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  long local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined1 local_88;
  undefined4 local_84;
  uint local_80;
  undefined1 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64;
  undefined8 local_60;
  undefined1 local_58;
  undefined8 local_54;
  undefined1 local_4c;
  undefined8 local_48;
  undefined1 local_40;
  ulong local_3c;
  
  lVar17 = *(long *)(param_1 + 0x1b88);
  local_b0 = 0;
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0;
  }
  if (((param_3 == (long *)0x0) || (*param_3 == 0)) || ((int)param_3[1] == 0)) {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x12c7,"kgspInitRm_IMPL",4,
                 "NVRM: need firmware to initialize GSP\n");
    return 0x1f;
  }
  lVar20 = *(long *)(param_1 + 0x1d08);
  *(undefined1 *)(param_2 + 0x69efc) = 1;
  uVar9 = rmGpuGroupLockAcquire(*(undefined4 *)(param_1 + 0x7a4),0,0,0x400000,&local_b0);
  uVar24 = (ulong)uVar9;
  lVar1 = param_2 + 0xb50;
  if (uVar9 != 0) {
    nvAssertOkFailedNoLog
              (uVar24,
               "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_INIT, &gpusLockedMask)"
               ,"src/kernel/gpu/gsp/kernel_gsp.c",0x12ce);
    goto LAB_00380f46;
  }
  if (*(long *)(param_2 + 0xa50) == 0) {
    lVar15 = param_2 + 0xa40;
    local_98 = 0;
    portStringCopy(lVar15,0x10,"unknown",8);
    uVar9 = (**(code **)(param_2 + 0x8f0))(param_1,param_2,&local_98);
    uVar24 = (ulong)uVar9;
    if (uVar9 == 0) {
      local_90 = 0;
      uVar9 = kgspParseFwsecUcodeFromVbiosImg_IMPL
                        (param_1,param_2,local_98,param_2 + 0xa50,&local_90);
      uVar24 = (ulong)uVar9;
      kgspFreeVbiosImg(local_98);
      if (local_90 != 0) {
        nvDbgSnprintf(lVar15,0x10,"%2X.%02X.%02X.%02X.%02X",local_90 >> 0x20 & 0xff,
                      local_90 >> 0x18 & 0xff,local_90 >> 0x10 & 0xff,local_90 >> 8 & 0xff,
                      local_90 & 0xff);
      }
      if (uVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x12f4,"kgspInitRm_IMPL",4,
                     "NVRM: failed to parse FWSEC ucode from VBIOS image (VBIOS version %s): 0x%x\n"
                     ,lVar15,uVar24);
        goto LAB_00380f46;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x12f9,"kgspInitRm_IMPL",1,
                   "NVRM: parsed VBIOS version %s\n",lVar15);
    }
    else if (uVar9 != 0x56) {
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1302,"kgspInitRm_IMPL",4,
                   "NVRM: failed to extract VBIOS image from ROM: 0x%x\n",uVar9);
      goto LAB_00380f46;
    }
  }
  if (*(char *)(param_2 + 0x6a5e8) == '\0') {
    if (*(long *)(param_2 + 0xa60) == 0) {
      uVar9 = kgspAllocateBooterLoadUcodeImage_IMPL(param_1,param_2,param_2 + 0xa60);
      uVar24 = (ulong)uVar9;
      if (uVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1321,"kgspInitRm_IMPL",4,
                     "NVRM: failed to allocate Booter Load ucode: 0x%x\n",uVar9);
        goto LAB_00380f46;
      }
    }
    if (*(long *)(param_2 + 0xa68) == 0) {
      uVar9 = kgspAllocateBooterUnloadUcodeImage_IMPL(param_1,param_2,param_2 + 0xa68);
      uVar24 = (ulong)uVar9;
      if (uVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x132c,"kgspInitRm_IMPL",4,
                     "NVRM: failed to allocate Booter Unload ucode: 0x%x\n",uVar9);
        goto LAB_00380f46;
      }
    }
  }
  uVar9 = kgspPrepareBootBinaryImage_IMPL(param_1,param_2);
  uVar24 = (ulong)uVar9;
  if (uVar9 != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1336,"kgspInitRm_IMPL",4,
                 "NVRM: Error preparing boot binary image\n");
    goto LAB_00380f46;
  }
  uVar9 = _kgspFwContainerVerifyVersion_isra_0(*param_3,(int)param_3[1],"GSP firmware image");
  uVar24 = (ulong)uVar9;
  if (uVar9 == 0) {
    uVar9 = _kgspFwContainerGetSection_isra_0
                      (*param_3,(int)param_3[1],".fwimage",param_3 + 2,param_3 + 3);
    uVar24 = (ulong)uVar9;
    if (uVar9 == 0) {
      lVar15 = (**(code **)(param_2 + 0x9b8))(param_1,param_2);
      if (lVar15 == 0) {
        uVar24 = 0x1f;
        nvAssertFailedNoLog("pSectionPrefix != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x1612);
      }
      else {
        uVar9 = *(uint *)(param_1 + 0x808);
        if (uVar9 == 400) {
          local_c8 = "ad10x";
LAB_003807d0:
          lVar13 = portStringLength(local_c8);
          if (lVar13 != 0) {
            lVar13 = portStringLength(lVar15);
            lVar14 = portStringLength(local_c8);
            if (lVar13 + 1U < 0x21) {
              if (lVar14 + lVar13 + 1U < 0x21) {
                portStringCopy(&local_90,0x20,lVar15);
                portStringCat(&local_90,0x20,local_c8,lVar14 + 1);
                uVar9 = _kgspFwContainerGetSection_isra_0
                                  (*param_3,(int)param_3[1],&local_90,param_3 + 4,param_3 + 5);
                uVar24 = (ulong)uVar9;
                if (uVar9 != 0) {
                  nvCheckOkFailedNoLog
                            (4,uVar9,
                             "_kgspFwContainerGetSection(pGpu, pKernelGsp, pGspFw->pBuf, pGspFw->size, signatureSectionName, &pGspFw->pSignatureData, &pGspFw->signatureSize)"
                             ,"src/kernel/gpu/gsp/kernel_gsp.c",0x164a);
                  goto LAB_00381da0;
                }
                uVar9 = memdescCreate(param_2 + 0xb30,param_1,
                                      param_3[5] + 0xffU & 0xffffffffffffff00,0x100,1,1,0,
                                      0x200000000000);
                uVar24 = (ulong)uVar9;
                if (uVar9 == 0) {
                  *(undefined4 *)(*(long *)(param_2 + 0xb30) + 0x9c) = 0x31;
                  uVar9 = memdescAlloc(*(undefined8 *)(param_2 + 0xb30));
                  uVar24 = (ulong)uVar9;
                  if (uVar9 == 0) {
                    lVar15 = memdescMapInternal(param_1,*(undefined8 *)(param_2 + 0xb30),0);
                    if (lVar15 != 0) {
                      portMemCopy(lVar15,*(undefined8 *)(*(long *)(param_2 + 0xb30) + 0x30),
                                  param_3[4],param_3[5]);
                      memdescUnmapInternal(param_1,*(undefined8 *)(param_2 + 0xb30),0);
                      uVar9 = kgspCreateRadix3_IMPL
                                        (param_1,param_2,param_2 + 0xb28,0,param_3[2],param_3[3]);
                      uVar24 = (ulong)uVar9;
                      if (uVar9 == 0) {
                        local_a0 = 0;
                        local_98 = 0;
                        uVar9 = _kgspFwContainerGetSection_isra_0
                                          (*param_3,(int)param_3[1],".note.gnu.build-id",&local_a0,
                                           &local_98);
                        uVar27 = local_98;
                        if (uVar9 == 0) {
                          lVar15 = portMemAllocNonPaged(local_98);
                          *(long *)(param_2 + 0x69ee0) = lVar15;
                          if (lVar15 != 0) {
                            *(undefined8 *)(param_2 + 0x69ee8) = uVar27;
                            portMemCopy(lVar15,uVar27,local_a0,uVar27);
                            iVar10 = osReadRegistryDword(param_1,"RmGspLogBufferSizeTaskInit",
                                                         &local_a8);
                            if (iVar10 != 0) {
                              local_a8 = 0x10000;
                            }
                            iVar10 = osReadRegistryDword(param_1,"RmGspLogBufferSizeTaskIntr",
                                                         &local_a4);
                            if (iVar10 != 0) {
                              local_a4 = 0x10000;
                            }
                            iVar10 = osReadRegistryDword(param_1,"RmGspLogBufferSizeTaskRm",
                                                         &local_a0);
                            if (iVar10 != 0) {
                              local_a0 = CONCAT44(local_a0._4_4_,0x10000);
                            }
                            iVar10 = osReadRegistryDword(param_1,"RmGspLogBufferSizeTaskMnoc",
                                                         &local_98);
                            local_68 = (undefined4)local_98;
                            if (iVar10 != 0) {
                              local_98 = CONCAT44(local_98._4_4_,0x10000);
                              local_68 = 0x10000;
                            }
                            local_88 = 1;
                            local_90 = (ulong)local_a8 << 0x20;
                            local_84 = 2;
                            local_80 = local_a4;
                            local_7c = 1;
                            local_74 = (undefined4)local_a0;
                            local_60 = 0x1000000000005;
                            local_54 = 0x100000000006;
                            local_78 = 1;
                            local_70 = 1;
                            local_6c = 4;
                            local_64 = 1;
                            local_58 = 0;
                            local_4c = 1;
                            local_48 = 0x100000000007;
                            local_40 = 1;
                            libosLogCreate(lVar1);
                            puVar22 = &local_90;
                            iVar10 = 0;
                            do {
                              if (7 < (uint)*puVar22) {
                                uVar24 = 0x40;
                                goto LAB_003811c1;
                              }
                              lVar15 = (ulong)(uint)*puVar22 * 0x20;
                              bVar5 = infos_38[lVar15 + 0x18];
                              if ((bVar5 & 1) == 0) {
                                iVar11 = (**(code **)(param_2 + 0x9a0))(param_2);
                                if (iVar11 != 1) {
                                  bVar5 = infos_38[lVar15 + 0x18];
                                  goto LAB_00380b66;
                                }
                              }
                              else {
LAB_00380b66:
                                if (((bVar5 & 2) != 0) ||
                                   (iVar11 = (**(code **)(param_2 + 0x9a0))(param_2), iVar11 != 2))
                                {
                                  uVar9 = _setupLogBufferBaremetal_constprop_0
                                                    (param_1,param_2,iVar10,
                                                     *(undefined8 *)(infos_38 + lVar15),
                                                     *(undefined8 *)(infos_38 + lVar15 + 8),
                                                     *(uint *)((long)puVar22 + 4),
                                                     *(undefined8 *)(infos_38 + lVar15 + 0x10),
                                                     (char)puVar22[1]);
                                  if (uVar9 != 0) {
                                    uVar24 = (ulong)uVar9;
                                    goto LAB_003811c1;
                                  }
                                  iVar10 = iVar10 + 1;
                                }
                              }
                              puVar22 = (ulong *)((long)puVar22 + 0xc);
                            } while (&local_3c != puVar22);
                            cVar6 = kgspHasLibosKernelLogging_STATIC_DISPATCH(param_1);
                            if (cVar6 != '\0') {
                              ppuVar16 = &infos_37;
                              while( true ) {
                                bVar25 = *(uint *)(ppuVar16 + 1) <= *(uint *)(param_1 + 0x808);
                                if (*(uint *)((long)ppuVar16 + 0xc) != 0) {
                                  bVar25 = bVar25 && *(uint *)(param_1 + 0x808) <=
                                                     *(uint *)((long)ppuVar16 + 0xc);
                                }
                                bVar26 = *(uint *)(ppuVar16 + 2) <= *(uint *)(param_1 + 0x80c);
                                if (*(uint *)((long)ppuVar16 + 0x14) != 0) {
                                  bVar26 = bVar26 && *(uint *)(param_1 + 0x80c) <=
                                                     *(uint *)((long)ppuVar16 + 0x14);
                                }
                                if ((bool)(bVar26 & bVar25)) break;
                                ppuVar16 = ppuVar16 + 3;
                                if (ppuVar16 == (undefined **)&DAT_00d3de30) {
                                  uVar24 = kgspInitRm_IMPL_cold();
                                  return uVar24;
                                }
                              }
                              if (*ppuVar16 == (undefined *)0x0) {
                                nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xe2c,
                                             "_kgspInitLibosLoggingStructures",3,
                                             "NVRM: Unknown chip for libos kernel logging (non-fatal)\n"
                                            );
                              }
                              else {
                                uVar9 = _setupLogBufferBaremetal_constprop_0
                                                  (param_1,param_2,iVar10,"LOGKRNL",&DAT_00d39690,
                                                   0x10000,*ppuVar16,1);
                                uVar24 = (ulong)uVar9;
                                if (uVar9 != 0) {
LAB_003811c1:
                                  _kgspFreeLibosLoggingStructures(param_1,param_2);
                                  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1346,
                                               "kgspInitRm_IMPL",4,
                                               "NVRM: init libos logging structures failed: 0x%x\n",
                                               uVar24);
                                  goto LAB_00380f46;
                                }
                              }
                            }
                            if ((param_3[6] != 0) && (*(long *)(param_2 + 0x69ed0) == 0)) {
                              local_98 = 0;
                              local_90 = 0;
                              uVar9 = _kgspFwContainerVerifyVersion_isra_0
                                                (param_3[6],(int)param_3[7],"GSP firmware log");
                              uVar24 = (ulong)uVar9;
                              if (uVar9 == 0) {
                                uVar9 = _kgspFwContainerGetSection_isra_0
                                                  (param_3[6],(int)param_3[7],".fwlogging",&local_98
                                                   ,&local_90);
                                uVar23 = local_90;
                                uVar24 = (ulong)uVar9;
                                if (uVar9 == 0) {
                                  lVar15 = portMemAllocNonPaged(local_90);
                                  *(ulong *)(param_2 + 0x69ed8) = uVar23;
                                  *(long *)(param_2 + 0x69ed0) = lVar15;
                                  if (lVar15 != 0) {
                                    portMemCopy(lVar15,uVar23,local_98,uVar23);
                                    libosLogInit(lVar1,*(undefined8 *)(param_2 + 0x69ed0),uVar23);
                                    goto LAB_00380ca4;
                                  }
                                  uVar24 = 0x51;
                                  nvAssertFailedNoLog("pKernelGsp->pLogElf != NULL",
                                                      "src/kernel/gpu/gsp/kernel_gsp.c",0xe58);
                                }
                                else {
                                  nvAssertOkFailedNoLog
                                            (uVar9,
                                             "_kgspFwContainerGetSection(pGpu, pKernelGsp, pGspFw->pLogElf, pGspFw->logElfSize, GSP_LOGGING_SECTION_NAME, &pLogData, &logSize)"
                                             ,"src/kernel/gpu/gsp/kernel_gsp.c",0xe4d);
                                }
                              }
                              else {
                                nvAssertOkFailedNoLog
                                          (uVar9,
                                           "_kgspFwContainerVerifyVersion(pGpu, pKernelGsp, pGspFw->pLogElf, pGspFw->logElfSize, \"GSP firmware log\")"
                                           ,"src/kernel/gpu/gsp/kernel_gsp.c",0xe47);
                              }
                              nvCheckOkFailedNoLog
                                        (4,uVar24,
                                         "_kgspInitLibosLogDecoder(pGpu, pKernelGsp, pGspFw)",
                                         "src/kernel/gpu/gsp/kernel_gsp.c",0x134a);
                              goto LAB_00380f46;
                            }
LAB_00380ca4:
                            uVar9 = nvlogRegisterFlushCb(kgspNvlogFlushCb,param_2);
                            uVar24 = (ulong)uVar9;
                            if (uVar9 != 0) {
                              nvCheckOkFailedNoLog
                                        (4,uVar9,
                                         "nvlogRegisterFlushCb(kgspNvlogFlushCb, pKernelGsp)",
                                         "src/kernel/gpu/gsp/kernel_gsp.c",0x134c);
                              goto LAB_00380f46;
                            }
                            threadStateResetTimeout(param_1);
                            uVar9 = (**(code **)(param_2 + 0x950))(param_1,param_2);
                            uVar24 = (ulong)uVar9;
                            if (uVar9 != 0) {
                              nvCheckOkFailedNoLog
                                        (4,uVar9,"kgspWaitForGfwBootOk_HAL(pGpu, pKernelGsp)",
                                         "src/kernel/gpu/gsp/kernel_gsp.c",0x1350);
                              goto LAB_00380f46;
                            }
                            (**(code **)(lVar17 + 400))(param_1,lVar17);
                            libosLogUpdateTimerDelta(lVar1,*(undefined8 *)(lVar17 + 0x24f8));
                            if (lVar20 != 0) {
                              (**(code **)(lVar20 + 0x238))(param_1);
                            }
                            iVar10 = memdescCreate(param_2 + 0x69f58,param_1,0x1000,0x1000,1,1,1);
                            if (iVar10 == 0) {
                              *(undefined4 *)(*(long *)(param_2 + 0x69f58) + 0x9c) = 0x2f;
                              iVar10 = memdescAlloc(*(undefined8 *)(param_2 + 0x69f58));
                              if (iVar10 != 0) {
                                nvAssertOkFailedNoLog
                                          (iVar10,"status","src/kernel/gpu/gsp/kernel_gsp.c",0xf3d);
                                goto LAB_00382284;
                              }
                              iVar10 = memdescMap(*(long *)(param_2 + 0x69f58),0,
                                                  *(undefined8 *)
                                                   (*(long *)(param_2 + 0x69f58) + 0x30),1,3,
                                                  param_2 + 0x69f68,param_2 + 0x69f60);
                              if (iVar10 != 0) {
                                nvAssertOkFailedNoLog
                                          (iVar10,
                                           "memdescMap(pKernelGsp->pRmStateMonitorBufferMD, 0, memdescGetSize(pKernelGsp->pRmStateMonitorBufferMD), NV_TRUE, NV_PROTECT_READ_WRITE, &pKernelGsp->pRmStateMonitorBuffer, &pKernelGsp->pRmStateMonitorBufferMDPriv)"
                                           ,"src/kernel/gpu/gsp/kernel_gsp.c",0xf3f);
                                goto LAB_00382284;
                              }
                              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xf46,
                                           "kgspAllocRmStateMonitorBuffer",1,
                                           "NVRM: Mapped rm state monitor buffer: %p\n",
                                           *(undefined8 *)(param_2 + 0x69f68));
                              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xf47,
                                           "kgspAllocRmStateMonitorBuffer",1,
                                           "NVRM: bufferSize %llu memdesc size %llu\n",0x1000,
                                           *(undefined8 *)(*(long *)(param_2 + 0x69f58) + 0x30));
                              if (*(long *)(param_2 + 0x69f68) != 0) {
                                portMemSet(*(long *)(param_2 + 0x69f68),0,
                                           *(undefined8 *)(*(long *)(param_2 + 0x69f58) + 0x30));
                              }
                            }
                            else {
                              nvAssertOkFailedNoLog
                                        (iVar10,
                                         "memdescCreate(&pKernelGsp->pRmStateMonitorBufferMD, pGpu, bufferSize, RM_PAGE_SIZE, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, flags)"
                                         ,"src/kernel/gpu/gsp/kernel_gsp.c",0xf31);
LAB_00382284:
                              if (*(long *)(param_2 + 0x69f68) != 0) {
                                memdescUnmap(*(undefined8 *)(param_2 + 0x69f58),1,
                                             *(long *)(param_2 + 0x69f68),
                                             *(undefined8 *)(param_2 + 0x69f60));
                                *(undefined8 *)(param_2 + 0x69f68) = 0;
                              }
                              if (*(long *)(param_2 + 0x69f58) != 0) {
                                memdescFree();
                                memdescDestroy(*(undefined8 *)(param_2 + 0x69f58));
                                *(undefined8 *)(param_2 + 0x69f58) = 0;
                              }
                              nvCheckOkFailedNoLog
                                        (4,iVar10,"kgspAllocRmStateMonitorBuffer(pGpu, pKernelGsp)",
                                         "src/kernel/gpu/gsp/kernel_gsp.c",0x1362);
                            }
                            kgspSetupLibosInitArgs_IMPL(param_1,param_2);
                            kgspPopulateGspRmInitArgs_IMPL(param_1,param_2,0);
                            cVar6 = rmapiLockIsOwner();
                            if (cVar6 == '\0') {
                              uVar24 = 0x2f;
                              nvAssertFailedNoLog("rmapiLockIsOwner()",
                                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x11d5);
                            }
                            else {
                              uVar9 = osPackageRegistry(param_1,0,param_2 + 0xb40);
                              uVar24 = (ulong)uVar9;
                              if (uVar9 == 0) {
                                lVar17 = portMemAllocPaged(*(undefined4 *)(param_2 + 0xb40));
                                *(long *)(param_2 + 0xb48) = lVar17;
                                if (lVar17 == 0) {
                                  uVar24 = 0x51;
                                }
                                else {
                                  uVar9 = osPackageRegistry(param_1,lVar17,param_2 + 0xb40);
                                  uVar24 = (ulong)uVar9;
                                  if (uVar9 == 0) {
                                    cVar6 = rmapiLockIsOwner();
                                    lVar17 = g_pSys;
                                    if (cVar6 == '\0') {
                                      uVar24 = 0x2f;
                                      nvAssertFailedNoLog("rmapiLockIsOwner()",
                                                          "src/kernel/gpu/gsp/kernel_gsp.c",0x1129);
                                    }
                                    else {
                                      uVar27 = *(undefined8 *)(g_pSys + 0x238);
                                      puVar18 = (undefined8 *)portMemAllocPaged(0x3b0);
                                      if (puVar18 != (undefined8 *)0x0) {
                                        portMemSet(puVar18,0,0x3b0);
                                        *puVar18 = *(undefined8 *)(param_1 + 0x848);
                                        puVar18[1] = *(undefined8 *)(param_1 + 0x850);
                                        puVar18[2] = *(undefined8 *)(param_1 + 0x858);
                                        puVar18[3] = *(undefined8 *)(param_1 + 0x860);
                                        puVar18[4] = *(undefined8 *)(param_1 + 0x878);
                                        *(char *)(puVar18 + 0xd) =
                                             (char)*(undefined4 *)(param_1 + 0x884);
                                        *(undefined4 *)(puVar18 + 0xb) =
                                             *(undefined4 *)(param_1 + 0x7f4);
                                        *(undefined4 *)((long)puVar18 + 0x5c) =
                                             *(undefined4 *)(param_1 + 0x7fc);
                                        *(undefined4 *)(puVar18 + 0xc) =
                                             *(undefined4 *)(param_1 + 0x800);
                                        lVar20 = *(long *)(param_1 + 7000);
                                        if (lVar20 != 0) {
                                          iVar10 = (**(code **)(lVar20 + 0x2a8))
                                                             (param_1,lVar20,puVar18 + 10,
                                                              (long)puVar18 + 0x54);
                                          if ((iVar10 != 0) && (iVar10 != 0x52)) {
                                            nvAssertFailedNoLog(
                                                  "status == NV_OK || status == NV_ERR_NO_SUCH_DOMAIN"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1148);
                                          }
                                          *(undefined1 *)((long)puVar18 + 0x7f) =
                                               *(undefined1 *)(lVar20 + 0x2450);
                                          *(undefined4 *)(puVar18 + 0x10) =
                                               *(undefined4 *)(lVar20 + 0x2454);
                                          *(undefined4 *)((long)puVar18 + 0x3a4) =
                                               *(undefined4 *)(lVar20 + 0x23e0);
                                          *(undefined1 *)(puVar18 + 0x75) =
                                               *(undefined1 *)(lVar20 + 0x23e4);
                                          *(undefined4 *)((long)puVar18 + 0x3ac) =
                                               *(undefined4 *)(lVar20 + 0x23e8);
                                          *(undefined1 *)((long)puVar18 + 0x7d) =
                                               *(undefined1 *)(lVar20 + 0x3b0);
                                          *(undefined1 *)((long)puVar18 + 0x7e) =
                                               *(undefined1 *)(lVar20 + 0x3b1);
                                          *(undefined4 *)((long)puVar18 + 900) =
                                               *(undefined4 *)(lVar20 + 0x2474);
                                        }
                                        uVar19 = 0;
                                        if (*(char *)(param_1 + 0x490e) != '\0') {
                                          uVar19 = memdescGetPhysAddr(*(undefined8 *)
                                                                       (param_2 + 0x69f10),1,0);
                                        }
                                        puVar18[5] = uVar19;
                                        uVar19 = 0;
                                        if (*(long *)(param_2 + 0x69f28) != 0) {
                                          uVar19 = memdescGetPhysAddr(*(long *)(param_2 + 0x69f28),1
                                                                      ,0);
                                        }
                                        puVar18[6] = uVar19;
                                        uVar24 = 0;
                                        if (*(long *)(param_1 + 7000) != 0) {
                                          uVar24 = (ulong)*(uint *)(*(long *)(param_1 + 7000) +
                                                                   0x23ec);
                                        }
                                        puVar18[7] = uVar24;
                                        uVar12 = 0;
                                        if (*(long *)(param_1 + 7000) != 0) {
                                          uVar12 = *(undefined4 *)
                                                    (*(long *)(param_1 + 7000) + 0x23f0);
                                        }
                                        *(undefined4 *)((long)puVar18 + 100) = uVar12;
                                        puVar18[8] = *(undefined8 *)
                                                      (*(long *)(param_1 + 0x1b78) + 0xb38);
                                        uVar19 = osGetMaxUserVa();
                                        puVar18[9] = uVar19;
                                        *(undefined1 *)((long)puVar18 + 0x38f) =
                                             *(undefined1 *)(lVar17 + 400);
                                        if (*(long *)(g_pSys + 0x208) != 0) {
                                          clSyncWithGsp_IMPL(*(long *)(g_pSys + 0x208),puVar18);
                                        }
                                        uVar19 = osGetPageSize();
                                        puVar18[0x73] = uVar19;
                                        memcpy(puVar18 + 0x14,param_1 + 0x2218,0x2a4);
                                        *(undefined1 *)(puVar18 + 0x11) =
                                             *(undefined1 *)(param_1 + 0x24bc);
                                        *(undefined1 *)((long)puVar18 + 0x7c) =
                                             *(undefined1 *)(param_1 + 0x479);
                                        *(undefined1 *)((long)puVar18 + 0x84) =
                                             *(undefined1 *)(param_1 + 0x47c);
                                        *(undefined1 *)((long)puVar18 + 0x85) =
                                             *(undefined1 *)(param_1 + 0x47d);
                                        *(undefined1 *)((long)puVar18 + 0x86) =
                                             *(undefined1 *)(param_1 + 0x47e);
                                        *(undefined1 *)((long)puVar18 + 0x87) =
                                             *(undefined1 *)(param_1 + 0x47f);
                                        *(undefined1 *)((long)puVar18 + 0x89) =
                                             *(undefined1 *)(param_1 + 0x1d5f);
                                        uVar12 = hypervisorGetHypervisorType_IMPL(uVar27);
                                        *(undefined4 *)((long)puVar18 + 0x344) = uVar12;
                                        *(undefined2 *)(puVar18 + 0x69) =
                                             *(undefined2 *)(param_1 + 0x7ea);
                                        *(undefined1 *)((long)puVar18 + 0x34a) =
                                             *(undefined1 *)(param_1 + 0x4912);
                                        *(undefined4 *)(puVar18 + 0x6b) =
                                             *(undefined4 *)(param_1 + 0x3a58);
                                        *(undefined4 *)((long)puVar18 + 0x35c) =
                                             *(undefined4 *)(param_1 + 0x3a5c);
                                        puVar18[0x6c] = *(undefined8 *)(param_1 + 0x3ab0);
                                        puVar18[0x6d] = *(undefined8 *)(param_1 + 0x3ab8);
                                        puVar18[0x6e] = *(undefined8 *)(param_1 + 0x3ac0);
                                        *(undefined1 *)(puVar18 + 0x6f) =
                                             *(undefined1 *)(param_1 + 0x3af0);
                                        *(undefined1 *)((long)puVar18 + 0x379) =
                                             *(undefined1 *)(param_1 + 0x3af1);
                                        *(undefined1 *)((long)puVar18 + 0x37a) =
                                             *(undefined1 *)(param_1 + 0x3af2);
                                        puVar18[0x6a] =
                                             *(undefined8 *)(*(long *)(param_1 + 0x1b88) + 0x24f8);
                                        *(undefined1 *)(puVar18 + 0x70) =
                                             *(undefined1 *)(param_1 + 0x447);
                                        *(undefined1 *)((long)puVar18 + 0x381) =
                                             *(undefined1 *)(param_1 + 0x471);
                                        *(undefined1 *)((long)puVar18 + 0x3a2) =
                                             *(undefined1 *)(lVar17 + 0x87);
                                        uVar7 = os_is_grid_supported();
                                        *(undefined1 *)((long)puVar18 + 0x382) = uVar7;
                                        uVar12 = osGetGridCspSupport();
                                        *(undefined4 *)(puVar18 + 0x71) = uVar12;
                                        *(undefined1 *)((long)puVar18 + 0x38c) =
                                             *(undefined1 *)(*(long *)(param_1 + 0x1b70) + 0x2a0);
                                        *(undefined1 *)((long)puVar18 + 0x38d) =
                                             *(undefined1 *)(param_1 + 0x49d);
                                        lVar17 = *(long *)(param_1 + 0x1b80);
                                        if (lVar17 != 0) {
                                          *(undefined1 *)((long)puVar18 + 0x38e) =
                                               *(undefined1 *)(lVar17 + 0x279);
                                          *(undefined1 *)((long)puVar18 + 0x3a3) =
                                               *(undefined1 *)(lVar17 + 0x27e);
                                        }
                                        if (*(long *)(param_1 + 0x1d08) != 0) {
                                          *(undefined1 *)(puVar18 + 0x72) =
                                               *(undefined1 *)(*(long *)(param_1 + 0x1d08) + 0x2c8);
                                        }
                                        *(undefined8 **)(param_2 + 0xb38) = puVar18;
                                        iVar10 = osReadRegistryDword(param_1,
                                                  "RmGspBootRetryAttempts",&local_ac);
                                        if (iVar10 != 0) {
                                          local_ac = 4;
                                        }
                                        iVar10 = osReadRegistryDword(param_1,"RmGspBootInitialShift"
                                                                     ,param_2 + 0x69ef8);
                                        if (iVar10 == 0) {
                                          uVar23 = (ulong)*(uint *)(param_2 + 0x69ef8);
                                          if (local_ac <= *(uint *)(param_2 + 0x69ef8)) {
                                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1383,
                                                         "kgspInitRm_IMPL",4,
                                                                                                                  
                                                  "NVRM: Initial shift, %u, is larger than max allowed [0, %u]. Modulo applied\n"
                                                  ,uVar23,local_ac - 1);
                                            uVar23 = (ulong)*(uint *)(param_2 + 0x69ef8) %
                                                     (ulong)local_ac;
                                            *(int *)(param_2 + 0x69ef8) = (int)uVar23;
                                          }
                                        }
                                        else {
                                          *(undefined4 *)(param_2 + 0x69ef8) = 0;
                                          uVar23 = 0;
                                        }
LAB_00381730:
                                        uVar9 = (uint)uVar23;
                                        do {
                                          if (uVar9 != 0) {
                                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1391,
                                                         "kgspInitRm_IMPL",3,
                                                         "NVRM: GSP-RM boot attempt #%u of %u\n",
                                                         uVar23,local_ac);
                                          }
                                          cVar6 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x288))
                                                            (param_1);
                                          cVar8 = (**(code **)(param_2 + 0x8d8))(param_1,param_2);
                                          if ((cVar8 != '\0') &&
                                             (*(char *)(param_1 + 0x460) == '\0')) {
                                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1270,
                                                         "_kgspBootGspRm",4,
                                                                                                                  
                                                  "NVRM: unexpected WPR2 already up, cannot proceed with booting GSP\n"
                                                  );
                                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1271,
                                                         "_kgspBootGspRm",4,
                                                                                                                  
                                                  "NVRM: (the GPU is likely in a bad state and may need to be reset)\n"
                                                  );
                                            cVar6 = rmapiLockIsOwner();
                                            if ((cVar6 == '\0') || (local_b0 == 0))
                                            goto LAB_00381c78;
                                            uVar24 = 0x40;
LAB_00381b60:
                                            if (local_ac <= *(uint *)(param_2 + 0x69ef8)) {
                                              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x13b5,
                                                           "kgspInitRm_IMPL",4,
                                                                                                                      
                                                  "NVRM: Max GSP-RM boot attempts exceeded: %u/%u\n"
                                                  ,*(uint *)(param_2 + 0x69ef8),local_ac);
                                            }
                                            (**(code **)(param_2 + 0x898))(param_1,param_2);
                                            goto LAB_00380f46;
                                          }
                                          uVar9 = (**(code **)(param_2 + 0x878))
                                                            (param_1,param_2,param_3);
                                          uVar24 = (ulong)uVar9;
                                          if (uVar9 != 0) {
                                            uVar27 = 0x1276;
                                            pcVar21 = 
                                            "kgspPopulateWprMeta_HAL(pGpu, pKernelGsp, pGspFw)";
LAB_00381afc:
                                            nvCheckOkFailedNoLog
                                                      (4,uVar24,pcVar21,
                                                       "src/kernel/gpu/gsp/kernel_gsp.c",uVar27);
                                            cVar6 = rmapiLockIsOwner();
                                            if ((cVar6 == '\0') || (local_b0 == 0)) {
LAB_00381c78:
                                              nvAssertFailedNoLog(
                                                  "rmapiLockIsOwner() && (gpusLockedMask != 0)",
                                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x13a5);
                                              return 0x2f;
                                            }
LAB_00381b26:
                                            if ((int)uVar24 == 0x1c) {
                                              uVar27 = *(undefined8 *)(param_1 + 0x878);
                                              lVar17 = *(long *)(g_pSys + 0x1e0);
                                              bVar5 = *(byte *)(lVar17 + 0x1b20);
                                              *(byte *)(lVar17 + 0x1b20) = bVar5 + 1;
                                              *(char *)(lVar17 + 0x1b21 + (ulong)bVar5) =
                                                   (char)((ulong)uVar27 >> 8);
                                            }
                                            goto LAB_00381b60;
                                          }
                                          uVar23 = *(long *)(*(long *)(param_2 + 0xa78) + 0xb0) -
                                                   *(long *)(*(long *)(param_2 + 0xa78) + 0x58);
                                          uVar27 = 0x3817bf;
                                          uVar24 = (**(code **)(param_2 + 0x8e8))(param_1,param_2);
                                          nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x110d,
                                                       "_kgspPrepareScrubberImageIfNeeded",1,
                                                                                                              
                                                  "NVRM: pre-scrubbed memory: 0x%llx bytes, needed: 0x%llx bytes\n"
                                                  ,uVar24,uVar23);
                                          if ((uVar24 < uVar23) ||
                                             (iVar10 = (**(code **)(param_2 + 0x910))
                                                                 (param_1,param_2,uVar27),
                                             iVar10 != 0)) {
                                            uVar9 = kgspAllocateScrubberUcodeImage_IMPL
                                                              (param_1,param_2,param_2 + 0xa58);
                                            uVar24 = (ulong)uVar9;
                                            if (uVar9 != 0) {
                                              nvCheckOkFailedNoLog
                                                        (4,uVar9,
                                                  "kgspAllocateScrubberUcodeImage(pGpu, pKernelGsp, &pKernelGsp->pScrubberUcode)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1112);
                                              uVar27 = 0x127a;
                                              pcVar21 = 
                                              "_kgspPrepareScrubberImageIfNeeded(pGpu, pKernelGsp)";
                                              goto LAB_00381afc;
                                            }
                                          }
                                          uVar9 = (**(code **)(param_2 + 0x828))(param_1,param_2,0);
                                          uVar24 = (ulong)uVar9;
                                          if (uVar9 != 0) {
                                            uVar27 = 0x127e;
                                            pcVar21 = 
                                            "kgspPrepareForBootstrap_HAL(pGpu, pKernelGsp, KGSP_BOOT_MODE_NORMAL)"
                                            ;
                                            goto LAB_00381afc;
                                          }
                                          if (((*(long *)(param_1 + 0x1d10) == 0) ||
                                              (*(char *)(*(long *)(param_1 + 0x1d10) + 0x218) ==
                                               '\0')) &&
                                             ((iVar10 = osReadRegistryDword(param_1,
                                                  "RmRelaxedGspInitLocking",&local_90), iVar10 != 0
                                              || ((int)local_90 - 1U < 2)))) {
                                            rmapiLockRelease();
                                            bVar25 = true;
                                          }
                                          else {
                                            bVar25 = false;
                                          }
                                          if ((*(int *)(param_2 + 0x69ef8) != 0) && (cVar6 == '\0'))
                                          {
                                            iVar10 = osReadRegistryDword(param_1,
                                                  "RmGspScanWprEndMargin",&local_90);
                                            if (iVar10 != 0 || (int)local_90 != 0) {
                                              pbVar2 = (byte *)(*(long *)(param_2 + 0xa78) + 0xf1);
                                              *pbVar2 = *pbVar2 | 0x10;
                                            }
                                          }
                                          uVar9 = (**(code **)(param_2 + 0x830))(param_1,param_2,0);
                                          uVar24 = (ulong)uVar9;
                                          if ((uVar9 == 0) ||
                                             (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) != '\0'))
                                          {
                                            bVar26 = false;
                                          }
                                          else {
                                            *(int *)(param_2 + 0x69ef8) =
                                                 *(int *)(param_2 + 0x69ef8) + 1;
                                            cVar8 = (**(code **)(param_1 + 0x3f8))(param_1);
                                            if (cVar8 == '\0') {
                                              bVar26 = false;
                                              if (cVar6 != '\0') goto joined_r0x003819fa;
LAB_00381906:
                                              osWriteRegistryDword
                                                        (param_1,"RmGspBootInitialShift",
                                                         *(undefined4 *)(param_2 + 0x69ef8));
                                            }
                                            else if (cVar6 == '\0') goto LAB_00381906;
                                            bVar26 = true;
                                          }
joined_r0x003819fa:
                                          if (bVar25) {
                                            rmGpuGroupLockRelease(local_b0,0);
                                            local_b0 = 0;
                                            uVar9 = rmapiLockAcquire(0,0x400000);
                                            if (uVar9 == 0) {
                                              cVar6 = gpumgrIsGpuPointerAttached(param_1);
                                              if (cVar6 == '\0') {
                                                uVar24 = 0x26;
                                                nvAssertFailedNoLog(
                                                  "gpumgrIsGpuPointerAttached(pGpu)",
                                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x1259);
                                              }
                                              else {
                                                uVar9 = rmGpuGroupLockAcquire
                                                                  (*(undefined4 *)(param_1 + 0x7a4),
                                                                   0,0,0x400000,&local_b0);
                                                if (uVar9 == 0) goto LAB_00381930;
                                                nvAssertOkFailedNoLog
                                                          (uVar9,
                                                  "rmGpuGroupLockAcquire(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_INIT, pGpusLockedMask)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp.c",0x125c);
                                                uVar24 = (ulong)uVar9;
                                              }
                                            }
                                            else {
                                              nvAssertOkFailedNoLog
                                                        (uVar9,
                                                  "rmapiLockAcquire(API_LOCK_FLAGS_NONE, RM_LOCK_MODULES_INIT)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1253);
                                              uVar24 = (ulong)uVar9;
                                            }
                                            nvCheckOkFailedNoLog
                                                      (4,uVar24,
                                                  "_kgspBootReacquireLocks(pGpu, pKernelGsp, pGpusLockedMask)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp.c",0x12a5);
                                          }
LAB_00381930:
                                          cVar6 = rmapiLockIsOwner();
                                          if ((cVar6 == '\0') || (local_b0 == 0)) goto LAB_00381c78;
                                          if ((!bVar26) ||
                                             (uVar23 = (ulong)*(uint *)(param_2 + 0x69ef8),
                                             local_ac <= *(uint *)(param_2 + 0x69ef8))) {
                                            if ((int)uVar24 != 0) goto LAB_00381b26;
                                            lVar17 = gpuGetRpc(param_1);
                                            if (lVar17 == 0) {
                                              uVar24 = 0x1a;
                                              nvAssertFailedNoLog("pRpc != NULL",
                                                                  "src/kernel/gpu/gsp/kernel_gsp.c",
                                                                  0x13c3);
                                            }
                                            else {
                                              uVar9 = RmRpcSetGuestSystemInfo(param_1,lVar17);
                                              uVar24 = (ulong)uVar9;
                                              if (uVar9 == 0) {
                                                lVar17 = gpuGetRpc(param_1);
                                                if (lVar17 == 0) {
                                                  uVar24 = 0x1a;
                                                  nvAssertFailedNoLog("pRpc != NULL",
                                                                                                                                            
                                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x13ca);
                                                }
                                                else {
                                                  uVar9 = (**(code **)(lVar17 + 0x118))
                                                                    (param_1,lVar17,
                                                                     *(code **)(lVar17 + 0x118));
                                                  uVar24 = (ulong)uVar9;
                                                  if (uVar9 == 0) {
                                                    local_a0 = 0;
                                                    local_98 = 0;
                                                    local_90 = 0;
                                                    local_a4 = 0x32;
                                                    cVar6 = gpuIsCCFeatureEnabled_IMPL(param_1);
                                                    if (cVar6 != '\0') {
                                                      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c"
                                                                   ,0xeb6,
                                                  "kgspInitGspTraceCrashBuffer",1,
                                                  "NVRM: GSP Trace Crash logging is not supported on CC\n"
                                                  );
                                                  iVar10 = osReadRegistryDword(param_1,
                                                  "RmGspTraceCrashLogging",&local_a8);
                                                  if (iVar10 == 0) goto LAB_00382537;
LAB_00382544:
                                                  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",
                                                               0xec8,"kgspInitGspTraceCrashBuffer",1
                                                               ,
                                                  "NVRM: GSP Trace Crash logging is disabled\n");
LAB_0038256a:
                                                  lVar17 = gpuGetGspStaticInfo(param_1);
                                                  *(undefined1 *)(param_1 + 0x485) =
                                                       *(undefined1 *)(lVar17 + 0x5d0);
                                                  *(undefined1 *)(param_1 + 0x487) =
                                                       *(undefined1 *)(lVar17 + 0x5d1);
                                                  *(undefined1 *)(param_1 + 0x489) =
                                                       *(undefined1 *)(lVar17 + 0x5d2);
                                                  *(undefined1 *)(param_1 + 0x492) =
                                                       *(undefined1 *)(lVar17 + 0x5d3);
                                                  *(undefined1 *)(param_1 + 0x464) =
                                                       *(undefined1 *)(lVar17 + 0x60e);
                                                  *(undefined1 *)(param_1 + 0x465) =
                                                       *(undefined1 *)(lVar17 + 0x60f);
                                                  *(undefined1 *)(param_1 + 0x491) =
                                                       *(undefined1 *)(lVar17 + 0x5d4);
                                                  if (*(char *)(param_1 + 0x46f) != '\0') {
                                                    lVar20 = gpuGetGspStaticInfo(param_1);
                                                    lVar17 = *(long *)(*(long *)(param_1 + 0x1ba8) +
                                                                      0xa78);
                                                    *(undefined8 *)(lVar17 + 0x60) =
                                                         *(undefined8 *)(lVar20 + 0x620);
                                                    *(undefined8 *)(lVar17 + 0x98) =
                                                         *(undefined8 *)(lVar20 + 0x628);
                                                  }
                                                  uVar9 = osSchedule1HzCallback
                                                                    (param_1,_kgspLogPollingCallback
                                                                     ,0,1);
                                                  uVar24 = (ulong)uVar9;
                                                  if (uVar9 != 0) {
                                                    nvCheckOkFailedNoLog
                                                              (4,uVar9,
                                                  "kgspStartLogPolling(pGpu, pKernelGsp)",
                                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x13d9);
                                                  goto LAB_00380f46;
                                                  }
                                                  *(undefined1 *)(param_2 + 0x69efc) = 0;
                                                  goto LAB_00380f8e;
                                                  }
                                                  iVar10 = osReadRegistryDword(param_1,
                                                  "RmGspTraceCrashLogging",&local_a8);
                                                  if (iVar10 == 0) {
LAB_00382537:
                                                    if (local_a8 != 1) goto LAB_00382544;
                                                    cVar6 = gpuIsCCFeatureEnabled_IMPL(param_1);
                                                    if (cVar6 == '\0') goto LAB_003826de;
                                                    uVar24 = 0x56;
                                                    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",
                                                                 0xec1,"kgspInitGspTraceCrashBuffer"
                                                                 ,4,
                                                  "NVRM: Attempted to enable GSP Trace Crash logging on CC, which is not supported\n"
                                                  );
                                                  }
                                                  else {
LAB_003826de:
                                                    osReadRegistryDword(param_1,
                                                  "RmGspTraceCrashLoggingBufferSize",&local_a4);
                                                  if (local_a4 < 0x2711) {
                                                    if (local_a4 < 10) {
                                                      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c"
                                                                   ,0xed5,
                                                  "kgspInitGspTraceCrashBuffer",4,
                                                  "NVRM: GSP Trace Crash buffer size is too small, clamping to %u\n"
                                                  ,10);
                                                  local_a4 = 10;
                                                  }
                                                  }
                                                  else {
                                                    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",
                                                                 0xecf,"kgspInitGspTraceCrashBuffer"
                                                                 ,4,
                                                  "NVRM: GSP Trace Crash buffer size is too large, clamping to %u\n"
                                                  ,10000);
                                                  local_a4 = 10000;
                                                  }
                                                  uVar19 = 0;
                                                  uVar27 = 1;
                                                  iVar10 = local_a4 << 5;
                                                  uVar9 = memdescCreate(&local_a0,param_1,iVar10,
                                                                        0x1000,1,1);
                                                  uVar24 = (ulong)uVar9;
                                                  if (uVar9 == 0) {
                                                    *(undefined4 *)(local_a0 + 0x9c) = 0xbb;
                                                    uVar9 = memdescAlloc(local_a0,uVar19,
                                                                         extraout_RDX,uVar27);
                                                    uVar24 = (ulong)uVar9;
                                                    if (uVar9 == 0) {
                                                      uVar9 = memdescMap(local_a0,0,
                                                                         *(undefined8 *)
                                                                          (local_a0 + 0x30),1,3,
                                                                         &local_90,&local_98);
                                                      uVar24 = (ulong)uVar9;
                                                      if (uVar9 == 0) {
                                                        portMemSet(local_90,0,iVar10);
                                                        lVar17 = gpuGetRpc(param_1);
                                                        if (lVar17 == 0) {
                                                          uVar24 = 0x1a;
                                                          nvAssertFailedNoLog("pRpc != NULL",
                                                                                                                                                            
                                                  "src/kernel/gpu/gsp/kernel_gsp.c",0xef0);
                                                  }
                                                  else {
                                                    pcVar4 = *(code **)(lVar17 + 0x3d8);
                                                    uVar12 = *(undefined4 *)(local_a0 + 0x30);
                                                    uVar27 = memdescGetPhysAddr(local_a0,1,0);
                                                    uVar9 = (*pcVar4)(param_1,lVar17,uVar27,uVar12);
                                                    uVar24 = (ulong)uVar9;
                                                    if (uVar9 == 0) {
                                                      *(long *)(param_2 + 0x6a5a8) = local_a0;
                                                      *(undefined8 *)(param_2 + 0x6a5b0) = local_98;
                                                      *(ulong *)(param_2 + 0x6a5b8) = local_90;
                                                      *(uint *)(param_2 + 0x6a5c0) = local_a4;
                                                      goto LAB_0038256a;
                                                    }
                                                  }
                                                  nvAssertOkFailedNoLog
                                                            (uVar24,"status",
                                                             "src/kernel/gpu/gsp/kernel_gsp.c",0xef6
                                                            );
                                                  }
                                                  else {
                                                    nvAssertOkFailedNoLog
                                                              (uVar24,
                                                  "memdescMap(pMemDesc, 0, memdescGetSize(pMemDesc), NV_TRUE, NV_PROTECT_READ_WRITE, &pBuffer, &pMemDescPriv)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp.c",0xee8);
                                                  }
                                                  }
                                                  else {
                                                    nvAssertOkFailedNoLog
                                                              (uVar9,"status",
                                                               "src/kernel/gpu/gsp/kernel_gsp.c",
                                                               0xee6);
                                                  }
                                                  }
                                                  else {
                                                    nvAssertOkFailedNoLog
                                                              (uVar9,
                                                  "memdescCreate(&pMemDesc, pGpu, bufferSizeBytes, RM_PAGE_SIZE, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp.c",0xedb);
                                                  }
                                                  if (local_90 != 0) {
                                                    memdescUnmap(local_a0,1,local_90,local_98);
                                                  }
                                                  if (local_a0 != 0) {
                                                    memdescFree();
                                                    memdescDestroy(local_a0);
                                                  }
                                                  }
                                                  nvAssertOkFailedNoLog
                                                            (uVar24,
                                                  "kgspInitGspTraceCrashBuffer(pGpu, pKernelGsp)",
                                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x13d1);
                                                  goto LAB_00380f46;
                                                  }
                                                }
                                                nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",
                                                             0x13cd,"kgspInitRm_IMPL",4,
                                                                                                                          
                                                  "NVRM: GET_GSP_STATIC_INFO failed: 0x%x\n",uVar24)
                                                ;
                                                goto LAB_00380f46;
                                              }
                                            }
                                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x13c6,
                                                         "kgspInitRm_IMPL",4,
                                                                                                                  
                                                  "NVRM: SET_GUEST_SYSTEM_INFO failed: 0x%x\n",
                                                  uVar24);
                                            goto LAB_00380f46;
                                          }
                                          if ((int)uVar24 == 0) goto LAB_00381730;
                                          threadStateResetTimeout(param_1);
                                          uVar9 = *(uint *)(param_2 + 0x69ef8);
                                          uVar23 = (ulong)uVar9;
                                        } while( true );
                                      }
                                      uVar24 = 0x51;
                                    }
                                    nvCheckOkFailedNoLog
                                              (4,uVar24,"_kgspPrepareSystemInfo(pGpu, pKernelGsp)",
                                               "src/kernel/gpu/gsp/kernel_gsp.c",0x136e);
                                    goto LAB_00380f46;
                                  }
                                  portMemFree(*(undefined8 *)(param_2 + 0xb48));
                                  *(undefined8 *)(param_2 + 0xb48) = 0;
                                }
                              }
                            }
                            nvCheckOkFailedNoLog
                                      (4,uVar24,"_kgspPrepareRegistry(pGpu, pKernelGsp)",
                                       "src/kernel/gpu/gsp/kernel_gsp.c",0x136d);
                            goto LAB_00380f46;
                          }
                          uVar24 = 0x51;
                          nvAssertFailedNoLog("pKernelGsp->pBuildIdSection != NULL",
                                              "src/kernel/gpu/gsp/kernel_gsp.c",0x1669);
                        }
                        else {
                          uVar24 = (ulong)uVar9;
                          nvAssertOkFailedNoLog
                                    (uVar9,
                                     "_kgspFwContainerGetSection(pGpu, pKernelGsp, pGspFw->pBuf, pGspFw->size, GSP_BUILD_ID_SECTION_NAME, &pBuildIdSectionData, &buildIdSectionSize)"
                                     ,"src/kernel/gpu/gsp/kernel_gsp.c",0x165f);
                        }
                      }
                      else {
                        nvCheckOkFailedNoLog
                                  (4,uVar9,
                                   "kgspCreateRadix3(pGpu, pKernelGsp, &pKernelGsp->pGspUCodeRadix3Descriptor, NULL, pGspFw->pImageData, pGspFw->imageSize)"
                                   ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1656);
                      }
                      goto LAB_00381da0;
                    }
                    uVar24 = 0x1a;
                    nvCheckOkFailedNoLog
                              (4,0x1a,
                               "(pSignatureVa != NULL) ? NV_OK : NV_ERR_INSUFFICIENT_RESOURCES",
                               "src/kernel/gpu/gsp/kernel_gsp.c",0x15a7);
                    memdescFree(*(undefined8 *)(param_2 + 0xb30));
                  }
                  else {
                    nvCheckOkFailedNoLog(4,uVar9,"status","src/kernel/gpu/gsp/kernel_gsp.c",0x15a4);
                  }
                  memdescDestroy(*(undefined8 *)(param_2 + 0xb30));
                  *(undefined8 *)(param_2 + 0xb30) = 0;
                }
                else {
                  nvCheckOkFailedNoLog
                            (4,uVar9,
                             "memdescCreate(&pKernelGsp->pSignatureMemdesc, pGpu, NV_ALIGN_UP(pGspFw->signatureSize, 256), 256, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
                             ,"src/kernel/gpu/gsp/kernel_gsp.c",0x159d);
                }
                nvCheckOkFailedNoLog
                          (4,uVar24,"_kgspCreateSignatureMemdesc(pGpu, pKernelGsp, pGspFw)",
                           "src/kernel/gpu/gsp/kernel_gsp.c",0x1652);
                goto LAB_00381da0;
              }
              nvAssertFailedNoLog("sectionNameBufSize >= totalSize",
                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x1622);
            }
            else {
              nvAssertFailedNoLog("sectionNameBufSize >= sectionPrefixLength + 1",
                                  "src/kernel/gpu/gsp/kernel_gsp.c",0x1620);
            }
            uVar24 = 2;
            goto LAB_00381d7e;
          }
          nvAssertFailedNoLog("portStringLength(pChipFamilyName) != 0",
                              "src/kernel/gpu/gsp/kernel_gsp.c",0x161a);
        }
        else {
          uVar3 = *(uint *)(param_1 + 0x80c);
          if (uVar9 < 0x191) {
            if (uVar9 == 0x170) {
              local_c8 = "ga10x";
              if (uVar3 == 0) {
                local_c8 = "ga100";
              }
            }
            else if (uVar9 == 0x180) {
              local_c8 = "gh100";
            }
            else {
              if (uVar9 != 0x160) goto LAB_00381d60;
              local_c8 = "tu11x";
              if (uVar3 < 7) {
                local_c8 = "tu10x";
              }
            }
            goto LAB_003807d0;
          }
          if (uVar9 == 0x1a0) {
            local_c8 = "gb10x";
            if (uVar3 == 0xb) {
              local_c8 = "gb10y";
            }
            goto LAB_003807d0;
          }
          if (uVar9 == 0x1b0) {
            local_c8 = "gb20x";
            if (10 < uVar3) {
              local_c8 = "gb20y";
            }
            goto LAB_003807d0;
          }
LAB_00381d60:
          nvAssertFailedNoLog("chipFamily != NV_FIRMWARE_CHIP_FAMILY_NULL",
                              "src/kernel/gpu/gsp/kernel_gsp.c",0x1616);
        }
        uVar24 = 0x40;
      }
LAB_00381d7e:
      nvCheckOkFailedNoLog
                (4,uVar24,
                 "_kgspGetSectionNameForPrefix(pGpu, pKernelGsp, signatureSectionName, sizeof(signatureSectionName), kgspGetSignatureSectionNamePrefix_HAL(pGpu, pKernelGsp))"
                 ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1645);
    }
    else {
      nvCheckOkFailedNoLog
                (4,uVar9,
                 "_kgspFwContainerGetSection(pGpu, pKernelGsp, pGspFw->pBuf, pGspFw->size, GSP_IMAGE_SECTION_NAME, &pGspFw->pImageData, &pGspFw->imageSize)"
                 ,"src/kernel/gpu/gsp/kernel_gsp.c",0x163d);
    }
  }
  else {
    nvCheckOkFailedNoLog
              (4,uVar9,
               "_kgspFwContainerVerifyVersion(pGpu, pKernelGsp, pGspFw->pBuf, pGspFw->size, \"GSP firmware image\")"
               ,"src/kernel/gpu/gsp/kernel_gsp.c",0x1637);
  }
LAB_00381da0:
  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x133e,"kgspInitRm_IMPL",4,
               "NVRM: Error preparing GSP-RM image\n");
LAB_00380f46:
  *(undefined1 *)(param_2 + 0x69efc) = 0;
  lVar17 = *(long *)(param_1 + 0x1c28);
  kgspDumpGspLogs_IMPL(param_2,1);
  libosPreserveLogs(lVar1,1,0);
  if (lVar17 != 0) {
    libosPreserveLogs(lVar17 + 0x170,1,0);
  }
LAB_00380f8e:
  if (local_b0 != 0) {
    rmGpuGroupLockRelease(local_b0,0);
    return uVar24;
  }
  return uVar24;
}


// ===== 00382a70 kgspRpcRecvEvents_IMPL =====

void kgspRpcRecvEvents_IMPL(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  undefined1 local_1c [4];
  
  cVar1 = rmGpuGroupLockIsOwner(*(undefined4 *)(param_1 + 0x7a4),0,local_1c);
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("rmGpuGroupLockIsOwner(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, &gpuMaskUnused)"
                        ,"src/kernel/gpu/gsp/kernel_gsp.c",0x17ba);
  }
  iVar2 = _kgspRpcDrainEvents(param_1,param_2,0xe5,0,2);
  if (iVar2 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar2,
             "_kgspRpcDrainEvents(pGpu, pKernelGsp, NV_VGPU_MSG_FUNCTION_NUM_FUNCTIONS, 0, KGSP_RPC_EVENT_HANDLER_CONTEXT_INTERRUPT)"
             ,"src/kernel/gpu/gsp/kernel_gsp.c",0x17c0);
  return;
}


// ===== 00382b10 kgspRegisterIntrService_IMPL =====

void kgspRegisterIntrService_IMPL(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return;
  }
  if (*(long *)(param_3 + 0x4b0) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(undefined8 *)(param_2 + 0x7b8);
    }
    *(undefined8 *)(param_3 + 0x4b0) = uVar1;
    return;
  }
  nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL",
                      "src/kernel/gpu/gsp/kernel_gsp.c",0x1845);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 0x7b8);
  }
  *(undefined8 *)(param_3 + 0x4b0) = uVar1;
  return;
}


// ===== 00382ba0 kgspServiceInterrupt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspServiceInterrupt_IMPL(undefined8 param_1,long param_2,short *param_3)

{
  undefined8 uVar1;
  
  if (param_3 == (short *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/gsp/kernel_gsp.c",0x1857);
  }
  else {
    if (*param_3 == 0x32) {
      uVar1 = (**(code **)(param_2 + 0x8b0))();
      return uVar1;
    }
    nvAssertFailedNoLog("pParams->engineIdx == MC_ENGINE_IDX_GSP","src/kernel/gpu/gsp/kernel_gsp.c",
                        0x1858);
  }
  return 0;
}


// ===== 00382c00 kgspGetFwHeapSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kgspGetFwHeapSize_IMPL(long param_1,long param_2,long param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long local_40 [2];
  
  if (((*(char *)(param_2 + 0x6a5e9) == '\0') && (param_3 != 0 || param_4 != 0)) &&
     (lVar4 = (**(code **)(param_2 + 0x8e8))(), lVar4 != -1)) {
    iVar2 = *(int *)(param_2 + 0xa8c);
    uVar7 = (ulong)(lVar4 - (param_3 + param_4)) >> 0x14;
    uVar1 = (uint)uVar7;
  }
  else {
    iVar2 = *(int *)(param_2 + 0xa8c);
    uVar7 = 0xffffffff;
    uVar1 = 0xffffffff;
  }
  if (iVar2 == 0) {
    if (*(char *)(param_1 + 0x4a4e) != '\0') {
      uVar7 = (**(code **)(param_2 + 0x9a8))(param_1,param_2);
      return uVar7;
    }
    if (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') {
      local_40[0] = 0;
      iVar2 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x178))
                        (param_1,*(long *)(param_1 + 0x1b70),local_40);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"kmemsysGetUsableFbSize_HAL(pGpu, pKernelMemorySystem, &fbSize)",
                   "src/kernel/gpu/gsp/kernel_gsp.c",0x187e);
      }
      uVar5 = local_40[0] + 0x3fffffffU >> 0x1e;
      uVar7 = uVar5 & 0xffffffff;
      uVar3 = (int)uVar5 * 0x18000 + 0xfffffU & 0xfff00000;
    }
    else {
      uVar3 = 0x100000;
      uVar7 = 1;
    }
    iVar2 = (**(code **)(param_2 + 0x980))(param_1,param_2);
    uVar5 = (ulong)(iVar2 + uVar3 + *(int *)(param_2 + 0x6a5ec)) + 0x6000000;
    uVar6 = (**(code **)(param_2 + 0x970))(param_1,param_2);
    uVar6 = (uVar6 & 0xffffffff) << 0x14;
    if (uVar6 < uVar5) {
      uVar6 = uVar5;
    }
    if ((ulong)uVar1 << 0x14 <= uVar6) {
      uVar6 = (ulong)uVar1 << 0x14;
    }
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1898,"_kgspCalculateFwHeapSize",1,
                 "NVRM: GSP FW heap %lluMB of %uGB\n",uVar6 >> 0x14,uVar7);
  }
  else {
    uVar1 = (**(code **)(param_2 + 0x970))(param_1,param_2);
    uVar6 = (ulong)uVar1;
    uVar5 = (**(code **)(param_2 + 0x978))(param_1,param_2);
    uVar3 = (uint)uVar7;
    if (uVar5 < (uVar7 & 0xffffffff)) {
      uVar3 = (**(code **)(param_2 + 0x978))(param_1,param_2);
    }
    if (uVar3 <= uVar1) {
      nvAssertFailedNoLog("minGspFwHeapSizeMB < maxGspFwHeapSizeMB",
                          "src/kernel/gpu/gsp/kernel_gsp.c",0x18ce);
    }
    if (uVar3 < *(uint *)(param_2 + 0xa8c)) {
      uVar6 = (ulong)uVar3;
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x18d2,"kgspGetFwHeapSize_IMPL",3,
                   "NVRM: Firmware heap size clamped to maximum (%uMB)\n",uVar3);
      *(uint *)(param_2 + 0xa8c) = uVar3;
    }
    else if (*(uint *)(param_2 + 0xa8c) < uVar1) {
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x18d8,"kgspGetFwHeapSize_IMPL",3,
                   "NVRM: Firmware heap size clamped to minimum (%uMB)\n",uVar1);
      *(uint *)(param_2 + 0xa8c) = uVar1;
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x18de,"kgspGetFwHeapSize_IMPL",3,
                   "NVRM: Firmware heap size overridden (%uMB)\n");
      uVar6 = (ulong)*(uint *)(param_2 + 0xa8c);
    }
    uVar6 = uVar6 << 0x14;
  }
  return uVar6;
}


// ===== 00382f50 kgspGetWprEndMargin_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long kgspGetWprEndMargin_IMPL(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  
  uVar1 = *(uint *)(param_2 + 0xa88);
  lVar2 = *(long *)(param_2 + 0xa78);
  lVar8 = ((ulong)uVar1 & 0x7fffffff) << 0x14;
  if ((uVar1 & 0x7fffffff) == 0) {
    if (*(long *)(lVar2 + 0x18) == 0) {
      nvAssertFailedNoLog("pWprMeta->sizeOfRadix3Elf > 0","src/kernel/gpu/gsp/kernel_gsp.c",0x18f7);
    }
    if (*(ulong *)(lVar2 + 0x60) < *(ulong *)(lVar2 + 0xa8)) {
      lVar8 = *(ulong *)(lVar2 + 0xa8) - *(ulong *)(lVar2 + 0x60);
    }
    else {
      uVar4 = kpmuReservedMemorySizeGet_IMPL(*(undefined8 *)(param_1 + 0x1c28));
      uVar5 = (**(code **)(param_2 + 0x8e0))(param_1,param_2);
      lVar8 = *(long *)(lVar2 + 0x18);
      uVar1 = *(uint *)(param_2 + 0xb10);
      lVar7 = kgspGetFwHeapSize_IMPL(param_1,param_2,0,0);
      uVar6 = (**(code **)(param_2 + 0x880))(param_1,param_2);
      lVar8 = (ulong)uVar6 + lVar7 + lVar8 + (ulong)uVar1 + (ulong)uVar4 + (ulong)uVar5;
    }
    if (*(uint *)(param_2 + 0x69ef8) == 0) {
      if (-1 < *(int *)(param_2 + 0xa88)) goto LAB_0038300e;
    }
    else {
      lVar8 = lVar8 * (ulong)*(uint *)(param_2 + 0x69ef8);
    }
  }
  else if ((-1 < (int)uVar1) && (*(int *)(param_2 + 0x69ef8) == 0)) {
LAB_0038300e:
    lVar8 = 0;
    bVar3 = *(byte *)(lVar2 + 0xf1) & 0xfd;
    goto LAB_0038301d;
  }
  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1917,"kgspGetWprEndMargin_IMPL",3,
               "NVRM: Adding margin of 0x%llx bytes after the end of WPR2\n");
  bVar3 = *(byte *)(lVar2 + 0xf1) | 2;
LAB_0038301d:
  *(byte *)(lVar2 + 0xf1) = bVar3;
  return lVar8;
}


// ===== 00383110 kgspInitNocatData_IMPL =====

undefined8 kgspInitNocatData_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if (param_3 < 4) {
    puVar2 = &DAT_005a7e10;
    if (param_3 == 0) {
      return 0x1f;
    }
  }
  else {
    if (param_3 != 4) {
      return 0x1f;
    }
    puVar2 = &DAT_005a7e28;
  }
  portMemSet(param_2 + 0x6a5f8,0,0x160);
  *(uint *)(param_2 + 0x6a5fc) = param_3;
  *(undefined1 *)(param_2 + 0x6a5f8) = 1;
  uVar1 = prbSetupDclMsg(param_2 + 0x6a608,0x400,puVar2);
  if ((int)uVar1 != 0) {
    *(undefined1 *)(param_2 + 0x6a5f8) = 0;
    return uVar1;
  }
  return uVar1;
}


// ===== 003831d0 kgspPostNocatData_IMPL =====

int kgspPostNocatData_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 local_68;
  char *local_60;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_40;
  
  iVar2 = 0x40;
  local_78 = 0;
  if (*(char *)(param_2 + 0x6a5f8) != '\0') {
    iVar2 = prbEncNestedEnd();
    uVar3 = prbEncFinish(param_2 + 0x6a608,&local_78);
    if (iVar2 == 0) {
      portMemSet(&local_70,0,0x48);
      local_50 = *(undefined8 *)(param_2 + 0x6a600);
      local_40 = local_78;
      uVar1 = *(uint *)(param_2 + 0x6a5fc);
      if (uVar1 == 3) {
        local_68 = 3;
        local_60 = "GSP_RPC_TIMEOUT";
      }
      else if (uVar1 < 4) {
        if (uVar1 == 1) {
          local_68 = 3;
          local_60 = "GSP";
        }
        else {
          local_60 = "GSP";
          local_68 = 2;
          if (uVar1 == 2) {
            local_60 = "GSP_RPC_HISTORY";
          }
        }
      }
      else {
        local_60 = "GSP";
        local_68 = 2;
        if (uVar1 == 4) {
          local_60 = "GSP_RPC_PERF";
        }
      }
      local_70 = param_3;
      local_48 = uVar3;
      rcdbNocatInsertNocatError(param_1,&local_70);
    }
    portMemFree(local_78);
    *(undefined1 *)(param_2 + 0x6a5f8) = 0;
  }
  return iVar2;
}


// ===== 0038331e _kgspRpcRecvPoll.cold =====

void _kgspRpcRecvPoll_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00383330 _kgspRpcRecvPoll =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _kgspRpcRecvPoll(long param_1,long param_2,uint param_3,undefined4 param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  undefined2 *puVar6;
  code *pcVar7;
  bool bVar8;
  bool bVar9;
  long lVar10;
  char cVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  ulong uVar17;
  undefined8 uVar18;
  ulong uVar19;
  long *plVar20;
  char *pcVar21;
  long *plVar22;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 uVar23;
  uint uVar24;
  int iVar25;
  undefined2 *puVar26;
  undefined2 *puVar27;
  bool bVar28;
  ulong local_c0;
  ulong local_b8;
  undefined8 local_b0;
  long local_a0;
  undefined8 local_90;
  int local_80;
  undefined1 local_6c [4];
  undefined1 local_68 [24];
  undefined1 local_50 [32];
  
  uVar17 = (ulong)param_3;
  lVar3 = *(long *)(param_1 + 0x1b80);
  lVar4 = *(long *)(param_1 + 0x1ba8);
  cVar11 = *(char *)(lVar4 + 0x69efe);
  if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
    if (param_3 == 0x1001) {
      local_90 = 1;
      if (cVar11 != '\0') goto LAB_00383660;
    }
    else {
      if (cVar11 != '\0') goto LAB_00383660;
      local_90 = 0;
    }
    *(undefined1 *)(lVar4 + 0x69efe) = 1;
    uVar15 = *(uint *)(param_1 + 0x1af4);
    uVar24 = uVar15 >> 1;
    if (*(char *)(param_1 + 0x4a4e) == '\0') {
      bVar8 = false;
      iVar13 = uVar24 + uVar15;
    }
    else {
      bVar8 = false;
      if (uVar15 < 3100000) {
        uVar15 = 3100000;
      }
      iVar13 = uVar24 + uVar15;
    }
  }
  else if (param_3 == 0x1001) {
    if (cVar11 != '\0') goto LAB_00383660;
    *(undefined1 *)(lVar4 + 0x69efe) = 1;
    iVar13 = -0x207b8a80;
    bVar8 = true;
    local_90 = 1;
  }
  else {
    if (cVar11 != '\0') {
LAB_00383660:
      nvAssertFailedNoLog("!pKernelGsp->bPollingForRpcResponse","src/kernel/gpu/gsp/kernel_gsp.c",
                          0xaa6);
      return 0x40;
    }
    *(undefined1 *)(lVar4 + 0x69efe) = 1;
    iVar13 = -0x207b8a80;
    bVar8 = true;
    local_90 = 0;
  }
  cVar11 = rmGpuGroupLockIsOwner(*(undefined4 *)(param_1 + 0x7a4),0,local_6c);
  if (cVar11 == '\0') {
    nvAssertFailedNoLog("rmGpuGroupLockIsOwner(pGpu->gpuInstance, GPU_LOCK_GRP_SUBDEVICE, &gpuMaskUnused)"
                        ,"src/kernel/gpu/gsp/kernel_gsp.c",0xae3);
  }
  lVar1 = param_1 + 0x1af0;
  timeoutSet(lVar1,local_68,iVar13,
             (-(uint)(*(char *)(param_2 + 0x2d2c) == '\0') & 0xffffffc0) + 0x44);
  while( true ) {
    iVar13 = timeoutCheck(lVar1,local_68,0xaf1);
    iVar14 = _kgspRpcDrainEvents(param_1,lVar4,uVar17,param_4,local_90);
    if (iVar14 != 0) break;
    iVar14 = _kgspRpcSanityCheck(param_1,lVar4,param_2);
    if (iVar14 != 0) {
      iVar13 = iVar14;
      if (*(char *)(param_2 + 0x2d2c) == '\0') {
        uVar19 = (ulong)*(uint *)(param_2 + 0x1918);
        if (param_3 != *(uint *)(param_2 + 0x518 + uVar19 * 0x28)) {
          nvAssertFailedNoLog("expectedFunc == pHistoryEntry->function",
                              "src/kernel/gpu/gsp/kernel_gsp.c",0x98f);
        }
        if (param_3 < 0xe5) {
          pcVar21 = *(char **)(rpcName_40 + uVar17 * 8);
        }
        else {
          pcVar21 = "Unknown";
          if (param_3 - 0x1001 < 0x29) {
            pcVar21 = *(char **)(rpcName_40 + (ulong)(param_3 - 0xf1a) * 8);
          }
        }
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x991,"_kgspLogRpcSanityCheckFailure",4,
                     "NVRM: GPU%d sanity check failed 0x%x waiting for RPC response from GSP. Expected function %d (%s) sequence %u (0x%llx 0x%llx).\n"
                     ,*(undefined4 *)(param_1 + 0x7a4),iVar14,uVar17,pcVar21,param_4,
                     *(undefined8 *)(param_2 + 0x520 + uVar19 * 0x28),
                     *(undefined8 *)(param_2 + 0x528 + uVar19 * 0x28));
        kgspLogRpcDebugInfo(param_1,param_2,0x77,1);
        osAssertFailed();
        *(undefined1 *)(param_2 + 0x2d2c) = 1;
      }
      goto LAB_00383464;
    }
    if (iVar13 == 0x65) {
      _kgspRpcIncrementTimeoutCountAndRateLimitPrints(param_1,param_2);
      uVar16 = kflcnGetPendingHostInterrupts_IMPL(param_1,*(undefined8 *)(lVar4 + 2000));
      cVar11 = (**(code **)(lVar4 + 0x8b8))(param_1,lVar4,uVar16);
      if (cVar11 != '\0') {
        nvErrorLog_va(param_1,0x8c,"Poison error in GSP.");
        (**(code **)(param_1 + 0x3f8))(param_1);
        (**(code **)(param_1 + 0x100))(param_1);
        goto LAB_00383464;
      }
      uVar16 = (**(code **)(lVar4 + 0x8a8))(param_1,lVar4,0);
      cVar11 = _kgspIsHeartbeatTimedOut(param_1,lVar4,uVar16,*(undefined4 *)(lVar4 + 0x6a5c8));
      uVar16 = (**(code **)(lVar4 + 0x8a8))(param_1,lVar4,1);
      cVar12 = _kgspIsHeartbeatTimedOut(param_1,lVar4,uVar16,*(undefined4 *)(lVar4 + 0x6a5d0));
      iVar14 = (**(code **)(*(long *)(param_1 + 0x1b98) + 0x220))(param_1);
      if (iVar14 == 0) {
LAB_00383b43:
        if (((*(int *)(lVar4 + 0x6a5e0) == 1) && (*(long *)(lVar4 + 0x6a5c8) != 0)) &&
           (*(long *)(lVar4 + 0x6a5d0) != 0)) {
          if (cVar12 == '\0') {
            if (cVar11 == '\0') {
              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xa26,"_kgspClassifyGspTimeout",4,
                           "NVRM: =================== GSP-RM is slow ===================\n");
            }
            else {
              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xa22,"_kgspClassifyGspTimeout",4,
                           "NVRM: =============== GSP-RM unresponsive ==================\n");
            }
          }
          else {
            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xa1e,"_kgspClassifyGspTimeout",4,
                         "NVRM: ================ GSP core unresponsive ===============\n");
          }
        }
        local_80 = 0x77;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x9d7,"_kgspCheckIfMemsysError",4,
                     "NVRM: Unexpected error when checking for memory subsystem error: 0x%x \n",
                     iVar14);
        local_80 = 0xaf;
        if (iVar14 != 0x72) goto LAB_00383b43;
      }
      if (*(int *)(param_2 + 0x2d28) == *(int *)(lVar4 + 0x6a5e4)) {
        if (*(char *)(param_2 + 0x2d2c) == '\0') {
          local_c0 = (ulong)*(uint *)(param_2 + 0x1918);
          local_b8 = osGetTimestamp();
          local_a0 = *(long *)(param_1 + 0x1ba8);
          if (local_a0 == 0) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)invalidInstructionException();
            (*pcVar7)();
          }
          local_b0 = *(undefined8 *)(local_a0 + 2000);
          bVar28 = true;
          goto LAB_003841cb;
        }
        goto LAB_00383c30;
      }
      if (*(char *)(param_2 + 0x2d2c) != '\0') {
        bVar28 = local_80 != 0x77;
        goto LAB_00383b87;
      }
      local_c0 = (ulong)*(uint *)(param_2 + 0x1918);
      local_b8 = osGetTimestamp();
      local_a0 = *(long *)(param_1 + 0x1ba8);
      if (local_a0 == 0) {
        local_b0 = 0;
      }
      else {
        local_b0 = *(undefined8 *)(local_a0 + 2000);
      }
      if (local_80 == 0x77) {
        if (*(int *)(param_2 + 0x2d28) == 1) {
          bVar28 = false;
          goto LAB_003841cb;
        }
        (**(code **)(local_a0 + 0x7f8))(param_1);
        bVar28 = false;
        bVar9 = false;
      }
      else {
        bVar28 = true;
LAB_003841cb:
        (**(code **)(local_a0 + 0x7f8))(param_1);
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x94d,"_kgspLogRpcTimeout",4,
                     "NVRM: ********************************* GSP Timeout **********************************\n"
                    );
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x94f,"_kgspLogRpcTimeout",4,
                     "NVRM: Note: Please also check logs above.\n");
        bVar9 = true;
      }
      if (param_3 != *(uint *)(param_2 + 0x518 + local_c0 * 0x28)) {
        nvAssertFailedNoLog("expectedFunc == pHistoryEntry->function",
                            "src/kernel/gpu/gsp/kernel_gsp.c",0x953);
      }
      if (local_b8 <= *(ulong *)(param_2 + 0x530 + local_c0 * 0x28)) {
        nvAssertFailedNoLog("ts_end > pHistoryEntry->ts_start","src/kernel/gpu/gsp/kernel_gsp.c",
                            0x955);
      }
      lVar3 = *(long *)(param_2 + 0x530 + local_c0 * 0x28);
      uVar19 = osGetTimestampFreq();
      if (uVar19 < 1000000) {
        nvAssertFailedNoLog("tsFreqUs > 0","src/kernel/gpu/gsp/kernel_gsp.c",0x770);
        uVar18 = *(undefined8 *)(param_2 + 0x528 + local_c0 * 0x28);
        uVar23 = *(undefined8 *)(param_2 + 0x520 + local_c0 * 0x28);
        if (0xe4 < param_3) {
          uVar16 = *(undefined4 *)(param_1 + 0x7a4);
          uVar19 = 0;
          goto LAB_00383e3b;
        }
        uVar16 = *(undefined4 *)(param_1 + 0x7a4);
        uVar19 = 0;
        pcVar21 = *(char **)(rpcName_40 + uVar17 * 8);
      }
      else {
        uVar19 = (local_b8 - lVar3) / (uVar19 / 1000000);
        uVar16 = *(undefined4 *)(param_1 + 0x7a4);
        uVar18 = *(undefined8 *)(param_2 + 0x528 + local_c0 * 0x28);
        uVar23 = *(undefined8 *)(param_2 + 0x520 + local_c0 * 0x28);
        if (uVar19 < 1000000) {
          if (0xe4 < param_3) goto LAB_00383e3b;
LAB_0038425b:
          pcVar21 = *(char **)(rpcName_40 + uVar17 * 8);
        }
        else if (uVar19 < 10000000) {
          if (param_3 < 0xe5) {
            pcVar21 = *(char **)(rpcName_40 + uVar17 * 8);
          }
          else if (param_3 - 0x1001 < 0x29) {
            pcVar21 = *(char **)(rpcName_40 + (ulong)(param_3 - 0xf1a) * 8);
          }
          else {
            pcVar21 = "Unknown";
          }
          uVar19 = uVar19 / 1000000;
        }
        else {
          uVar19 = uVar19 / 1000000;
          if (param_3 < 0xe5) goto LAB_0038425b;
LAB_00383e3b:
          if (param_3 - 0x1001 < 0x29) {
            pcVar21 = *(char **)(rpcName_40 + (ulong)(param_3 - 0xf1a) * 8);
          }
          else {
            pcVar21 = "Unknown";
          }
        }
      }
      nvErrorLog_va(param_1,local_80,
                    "Timeout after %llus of waiting for RPC response from GPU%d GSP! Expected function %d (%s) sequence %u (0x%llx 0x%llx)."
                    ,uVar19,uVar16,uVar17,pcVar21,param_4,uVar23,uVar18);
      cVar11 = gpuIsCCFeatureEnabled_IMPL(param_1);
      if ((cVar11 != '\0') || (*(int *)(local_a0 + 0xa90) == 0)) goto LAB_00383f43;
      plVar5 = *(long **)(local_a0 + 0x69f68);
      if (plVar5 == (long *)0x0) {
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xf64,"_kgspDumpRmState",4,
                     "NVRM: Failed to dump RM state, RM state monitor buffer not allocated\n");
        goto LAB_00383f43;
      }
      *plVar5 = *plVar5 + 1;
      timeoutSet(lVar1,local_50,(ulong)*(uint *)(param_1 + 0x1af4) / 10,4);
      if (*plVar5 != plVar5[1]) goto LAB_00383f03;
      goto LAB_003843c8;
    }
    if (iVar13 != 0) {
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xb4b,"_kgspRpcRecvPoll",4,
                   "NVRM: gpuCheckTimeout() returned unexpected error (0x%08x)\n",iVar13);
      goto LAB_00383464;
    }
    if (((lVar3 != 0) && (*(char *)(lVar3 + 0x27c) != '\0')) && (*(char *)(lVar3 + 0x27a) == '\0'))
    {
      kdispApplyAggressiveVblankHandlingWar_IMPL(param_1,lVar3);
    }
    osSpinLoop();
  }
  iVar13 = iVar14;
  if (iVar14 != 0x10005) goto LAB_00383464;
  _kgspCompleteRpcHistoryEntry(param_2 + 0x518,*(undefined4 *)(param_2 + 0x1918));
  if (!bVar8) {
    uVar15 = *(uint *)(param_2 + 0x1918);
    lVar3 = *(long *)(param_1 + 0x1ba8);
    uVar17 = osGetTimestampFreq();
    if (uVar17 < 1000000) {
      nvAssertFailedNoLog("tsFreqUs > 0","src/kernel/gpu/gsp/kernel_gsp.c",0x89a);
    }
    else {
      uVar19 = (ulong)uVar15;
      lVar1 = param_2 + uVar19 * 0x28;
      uVar17 = (ulong)(*(long *)(lVar1 + 0x538) - *(long *)(lVar1 + 0x530)) / (uVar17 / 1000000);
      if (66000 < uVar17) {
        uVar15 = *(uint *)(lVar1 + 0x518);
        if (uVar15 < 0xe5) {
          pcVar21 = *(char **)(rpcName_40 + (ulong)uVar15 * 8);
        }
        else {
          pcVar21 = "Unknown";
          if (uVar15 - 0x1001 < 0x29) {
            pcVar21 = *(char **)(rpcName_40 + (ulong)(uVar15 - 0xf1a) * 8);
          }
        }
        lVar2 = lVar3 + 0x6a608;
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x8a0,"_kgspCheckSlowRpc",3,
                     "NVRM: Slow RPC response from GPU%d GSP (%lluus). Function %d (%s) sequence %u (0x%llx 0x%llx).\n"
                     ,*(undefined4 *)(param_1 + 0x7a4),uVar17,uVar15,pcVar21,
                     *(undefined4 *)(lVar1 + 0x51c),*(undefined8 *)(lVar1 + 0x520),
                     *(undefined8 *)(lVar1 + 0x528));
        portMemSet(lVar3 + 0x6a5f8,0,0x160);
        *(undefined1 *)(lVar3 + 0x6a5f8) = 1;
        *(undefined4 *)(lVar3 + 0x6a5fc) = 4;
        iVar13 = prbSetupDclMsg(lVar2,0x400,&DAT_005a7e28);
        if (iVar13 != 0) {
          *(undefined1 *)(lVar3 + 0x6a5f8) = 0;
        }
        prbEncAddUInt32(lVar2,0xc49b98,*(undefined4 *)(param_1 + 0x7a4));
        prbEncAddString(lVar2,prb_fields_gsp_rpcperf,"Slow RPC response from GSP!");
        prbEncNestedStart(lVar2,0xc49bb0);
        lVar1 = param_2 + uVar19 * 0x28;
        prbEncAddUInt64(lVar2,0xc49d18,*(undefined4 *)(lVar1 + 0x518));
        uVar15 = *(uint *)(lVar1 + 0x518);
        if (uVar15 < 0xe5) {
LAB_00383965:
          pcVar21 = *(char **)(rpcName_40 + (ulong)uVar15 * 8);
        }
        else {
          pcVar21 = "Unknown";
          if (uVar15 - 0x1001 < 0x29) {
            uVar15 = uVar15 - 0xf1a;
            goto LAB_00383965;
          }
        }
        prbEncAddString(lVar2,0xc49d30,pcVar21);
        prbEncAddUInt64(lVar2,0xc49da8,uVar17);
        param_2 = param_2 + uVar19 * 0x28;
        prbEncAddUInt32(lVar2,0xc49dc0,*(undefined4 *)(param_2 + 0x51c));
        prbEncAddUInt64(lVar2,0xc49d48,*(undefined8 *)(param_2 + 0x520));
        prbEncAddUInt64(lVar2,0xc49d60,*(undefined8 *)(param_2 + 0x528));
        prbEncNestedEnd(lVar2);
        uVar18 = osGetTimestamp();
        kgspPostNocatData_IMPL(param_1,lVar3,uVar18);
      }
    }
  }
  iVar13 = 0;
LAB_00383464:
  *(undefined1 *)(lVar4 + 0x69efe) = 0;
  uVar16 = (**(code **)(lVar4 + 0x8a8))(param_1,lVar4,0);
  cVar11 = _kgspIsHeartbeatTimedOut(param_1,lVar4,uVar16,*(undefined4 *)(lVar4 + 0x6a5c8));
  if (cVar11 != '\0') {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xb72,"_kgspRpcRecvPoll",4,
                 "NVRM: GSP RM heartbeat timed out\n");
  }
  uVar16 = (**(code **)(lVar4 + 0x8a8))(param_1,lVar4,1);
  cVar11 = _kgspIsHeartbeatTimedOut(param_1,lVar4,uVar16,*(undefined4 *)(lVar4 + 0x6a5d0));
  if (cVar11 != '\0') {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xb76,"_kgspRpcRecvPoll",4,
                 "NVRM: LibOS heartbeat timed out\n");
  }
  if (bVar8) {
    threadStateResetTimeout(param_1);
  }
  return iVar13;
  while (osSpinLoop(), *plVar5 != plVar5[1]) {
LAB_00383f03:
    iVar14 = timeoutCheck(lVar1,local_50,0xf75);
    if (iVar14 == 0x65) {
      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0xf78,"_kgspDumpRmState",4,
                   "NVRM: Failed to get RM state, timeout\n");
      goto LAB_00383f43;
    }
  }
LAB_003843c8:
  nv_printf(0xffffffff,
            "NVRM: ******************************RM DUMP REPORT******************************\n");
  plVar22 = plVar5 + 0x42;
  plVar20 = plVar5 + 2;
  while (*plVar20 == 0) {
    plVar20 = plVar20 + 4;
    if (plVar20 == plVar22) goto LAB_003843fc;
  }
  nv_printf(0xffffffff,"NVRM:     DPC QUEUE: \n");
  uVar18 = extraout_RDX;
  plVar20 = plVar5 + 2;
  iVar14 = 0;
  do {
    iVar25 = iVar14 + 1;
    nv_printf(0xffffffff,
              "NVRM: DPC QUEUE[%02u]: [%u]: %016llx [%u] %016llx [%u] %016llx [%u] %016llx\n",iVar14
              ,0,*plVar20,1,plVar20[1],2,plVar20[2],3,plVar20[3],uVar18);
    uVar18 = extraout_RDX_00;
    plVar20 = plVar20 + 4;
    iVar14 = iVar25;
  } while (iVar25 != 0x10);
LAB_003843fc:
  while (*plVar22 == 0) {
    plVar22 = plVar22 + 1;
    if (plVar5 + 0x62 == plVar22) goto LAB_0038448a;
  }
  uVar17 = 0;
  nv_printf(0xffffffff,"NVRM:     WORK ITEM QUEUE: \n");
  do {
    iVar14 = (int)uVar17;
    uVar19 = uVar17 & 0xffffffff;
    lVar3 = uVar17 + 0x43;
    lVar1 = uVar17 + 0x42;
    lVar2 = uVar17 + 0x45;
    lVar10 = uVar17 + 0x44;
    uVar17 = uVar17 + 4;
    nv_printf(0xffffffff,"NVRM: [%02u]: %016llx [%02u] %016llx [%02u] %016llx [%02u] %016llx\n",
              uVar19,plVar5[lVar1],iVar14 + 1,plVar5[lVar3],iVar14 + 2,plVar5[lVar10],iVar14 + 3,
              plVar5[lVar2]);
  } while (uVar17 != 0x20);
LAB_0038448a:
  nv_printf(0xffffffff,"NVRM: DPC execution time: %llx\n",plVar5[0x62]);
  nv_printf(0xffffffff,"NVRM: Total DPC execution time: %llx\n",plVar5[99]);
  nv_printf(0xffffffff,"NVRM: Work items execution time: %llx\n",plVar5[100]);
  nv_printf(0xffffffff,"NVRM: Total work items execution time: %llx\n",plVar5[0x65]);
  nv_printf(0xffffffff,
            "NVRM: **************************************************************************\n");
LAB_00383f43:
  puVar6 = *(undefined2 **)(local_a0 + 0x6a5b8);
  if (puVar6 == (undefined2 *)0x0) {
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x879,"_kgspLogGspTraceCrashBuffer",1,
                 "NVRM: Gsp Trace Crash Buffer is NULL\n");
  }
  else {
    uVar15 = *(uint *)(local_a0 + 0x6a5c0);
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x87d,"_kgspLogGspTraceCrashBuffer",4,
                 "NVRM: Gsp Trace Crash Buffer\n");
    if (uVar15 != 0) {
      puVar26 = puVar6;
      do {
        puVar27 = puVar26 + 0x10;
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x880,"_kgspLogGspTraceCrashBuffer",4,
                     "NVRM: %llu,%llu,%u,%u,%u,%llu\n",*(undefined8 *)(puVar26 + 8),
                     *(undefined8 *)(puVar26 + 0xc),*puVar26,puVar26[1],*(undefined1 *)(puVar26 + 2)
                     ,*(undefined8 *)(puVar26 + 4));
        puVar26 = puVar27;
      } while (puVar6 + (ulong)uVar15 * 0x10 != puVar27);
    }
  }
  kflcnCoreDumpNondestructive_IMPL(param_1,local_b0,2);
  (**(code **)(local_a0 + 0x8a0))(param_1,local_a0);
  if (bVar28) {
    if (*(int *)(local_a0 + 0x6a5dc) == 1) {
      kflcnCoreDumpDestructive_IMPL(param_1,local_b0);
    }
    if (bVar9) goto LAB_00384049;
  }
  else {
    if (!bVar9) goto LAB_00383464;
LAB_00384049:
    lVar3 = local_a0 + 0x6a608;
    portMemSet(local_a0 + 0x6a5f8,0,0x160);
    *(undefined1 *)(local_a0 + 0x6a5f8) = 1;
    *(undefined4 *)(local_a0 + 0x6a5fc) = 3;
    iVar14 = prbSetupDclMsg(lVar3,0x400,&DAT_005a7e10);
    if (iVar14 != 0) {
      *(undefined1 *)(local_a0 + 0x6a5f8) = 0;
    }
    prbEncAddUInt32(lVar3,&prb_fields_gsp_xidreport,local_80);
    kgspLogRpcDebugInfoToProtobuf(param_1,param_2,local_a0,lVar3);
    uVar18 = osGetTimestamp();
    kgspPostNocatData_IMPL(param_1,local_a0,uVar18);
    kgspLogRpcDebugInfo(param_1,param_2,local_80,1);
    osAssertFailed();
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x97f,"_kgspLogRpcTimeout",4,
                 "NVRM: ********************************************************************************\n"
                );
LAB_00383b87:
    if (!bVar28) goto LAB_00383464;
  }
LAB_00383c30:
  if (*(int *)(lVar4 + 0x6a5dc) == 1) {
    nvAssertFailedNoLog("GPU marked for reset","src/kernel/gpu/gsp/kernel_gsp.c",0xa33);
    (**(code **)(param_1 + 0x100))(param_1);
    *(undefined1 *)(lVar4 + 0x69eff) = 1;
    if (*(char *)(param_1 + 0x49d) == '\0') {
      gpuNotifySubDeviceEvent_IMPL(param_1,0xbf,0,0,local_80,0);
    }
    else {
      gpuNotifySubDeviceEvent_IMPL(param_1,0x9d,0,0,0,0);
    }
  }
  goto LAB_00383464;
}


// ===== 00384690 kgspWaitForRmInitDone_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspWaitForRmInitDone_IMPL(long param_1,long param_2)

{
  undefined1 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  
  lVar2 = *(long *)(param_2 + 0xa38);
  *(undefined2 *)(param_1 + 0x1b40) = 0;
  threadStateResetTimeout();
  if (*(code **)(lVar2 + 0x20) == _kgspRpcRecvPoll) {
    iVar4 = _kgspRpcRecvPoll();
  }
  else {
    iVar4 = (**(code **)(lVar2 + 0x20))(param_1,lVar2,0x1001,0);
  }
  if (iVar4 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar4,"rpcRecvPoll(pGpu, pRpc, NV_VGPU_MSG_EVENT_GSP_INIT_DONE, 0)",
               "src/kernel/gpu/gsp/kernel_gsp.c",0x17d8);
    return iVar4;
  }
  iVar4 = *(int *)(*(long *)(lVar2 + 0x4d8) + 0x10);
  if (iVar4 == 0) {
    *(undefined1 *)(param_1 + 0x7e1) = 1;
    cVar3 = kgspIsHeartbeatSupported_STATIC_DISPATCH(param_1);
    if (cVar3 != '\0') {
      cVar3 = kgspIsHeartbeatSupported_STATIC_DISPATCH(param_1);
      if (cVar3 == '\0') {
        nvAssertFailedNoLog("kgspIsHeartbeatSupported(pGpu)","src/kernel/gpu/gsp/kernel_gsp.c",0x8c4
                           );
      }
      else {
        uVar6 = (ulong)*(uint *)(param_1 + 0x1af4) / 1000;
        lVar5 = (uVar6 / 10) * 3 + uVar6;
        *(long *)(param_2 + 0x6a5c8) = lVar5;
        *(long *)(param_2 + 0x6a5d0) = lVar5;
      }
    }
    lVar2 = *(long *)(lVar2 + 0x4d8);
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x17eb,"kgspWaitForRmInitDone_IMPL",1,
                 "NVRM: GSP-RM reports bIsD3Hot = 0x%08x\n",*(undefined1 *)(lVar2 + 0x20));
    uVar1 = *(undefined1 *)(lVar2 + 0x20);
    if (*(int *)(param_1 + 0x4b34) == 4) {
      *(undefined1 *)(param_1 + 0x1b40) = uVar1;
      return 0;
    }
    *(undefined1 *)(param_1 + 0x1b41) = uVar1;
  }
  else {
    nvAssertOkFailedNoLog(iVar4,"RPC_HDR->rpc_result","src/kernel/gpu/gsp/kernel_gsp.c",0x17df);
  }
  return iVar4;
}


// ===== 00384850 kgspPostCrashcatReportToNocat_IMPL =====

void kgspPostCrashcatReportToNocat_IMPL
               (long param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 local_78 [72];
  
  puVar1 = *(uint **)(param_2 + 0x69ee0);
  portMemSet(param_2 + 0x6a5f8,0,0x160);
  *(undefined1 *)(param_2 + 0x6a5f8) = 1;
  *(undefined4 *)(param_2 + 0x6a5fc) = 1;
  iVar2 = prbSetupDclMsg(param_2 + 0x6a608,0x400,&DAT_005a7e10);
  if (iVar2 != 0) {
    *(undefined1 *)(param_2 + 0x6a5f8) = 0;
  }
  if (*(long *)(param_2 + 0x69ee0) != 0) {
    portStringBufferToHex(local_78,0x40,(long)puVar1 + (ulong)*puVar1 + 0xc,puVar1[1]);
    prbEncAddString(param_2 + 0x6a608,&DAT_00c49c10,local_78);
  }
  uVar4 = crashcatReportRa_V1(param_3);
  *(ulong *)(param_2 + 0x6a600) = *(ulong *)(param_2 + 0x6a600) | uVar4 >> 0x3f;
  uVar3 = crashcatReportRa_V1(param_3);
  *(ulong *)(param_2 + 0x6a600) = *(ulong *)(param_2 + 0x6a600) | (ulong)(uVar3 & 0xffffffe);
  uVar4 = crashcatReportXcause_V1(param_3);
  *(ulong *)(param_2 + 0x6a600) = *(ulong *)(param_2 + 0x6a600) | (uVar4 & 0xf) << 0x1c;
  lVar5 = crashcatReportXtval_V1(param_3);
  *(ulong *)(param_2 + 0x6a600) = *(ulong *)(param_2 + 0x6a600) | lVar5 << 0x20;
  prbEncAddUInt32(param_2 + 0x6a608,&prb_fields_gsp_xidreport,param_4);
  prbEncAddUInt32(param_2 + 0x6a608,&DAT_00c49bf8,*(undefined4 *)(param_1 + 0x7a4));
  crashcatReportLogToProtobuf_V1(param_3,param_2 + 0x6a608);
  uVar6 = osGetTimestamp();
  kgspPostNocatData_IMPL(param_1,param_2,uVar6);
  return;
}


// ===== 003849c0 kgspPrintGspBinBuildId_IMPL =====

void kgspPrintGspBinBuildId_IMPL(undefined8 param_1,long param_2)

{
  uint *puVar1;
  undefined1 local_48 [64];
  
  puVar1 = *(uint **)(param_2 + 0x69ee0);
  if (puVar1 != (uint *)0x0) {
    portStringBufferToHex(local_48,0x40,(long)puVar1 + (ulong)*puVar1 + 0xc,puVar1[1]);
    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp.c",0x1a43,"kgspPrintGspBinBuildId_IMPL",4,
                 "NVRM: GSP bin buildId: %s\n",local_48);
    return;
  }
  return;
}


// ===== 00384a30 s_patchBooterUcodeSignature =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8
s_patchBooterUcodeSignature
          (long param_1,undefined4 param_2,long param_3,uint param_4,uint param_5,long param_6,
          uint param_7,uint param_8)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pImage != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x94);
    return 0x40;
  }
  if (param_4 < param_5) {
    uVar2 = (ulong)param_7 / (ulong)param_8;
    if ((uint)uVar2 < param_5 - param_4) {
      if (param_6 == 0) {
        nvAssertFailedNoLog("pSignatures != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x97);
        return 0x40;
      }
      lVar1 = *(long *)(param_1 + 0x1ba0);
      if (lVar1 == 0) {
        nvAssertFailedNoLog("pKernelSec2 != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x9b);
        return 0x40;
      }
      uVar3 = (**(code **)(lVar1 + 0x800))(param_1,lVar1,param_2,uVar2,*(code **)(lVar1 + 0x800));
      if (param_8 != 1) {
        if (param_8 - 1 < uVar3) {
          nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_booter.c",0xa2,"s_patchBooterUcodeSignature",4
                       ,"NVRM: signature for fuse version %u not present\n",uVar3);
          return 0x5b;
        }
        param_6 = param_6 + (ulong)(((param_8 - 1) - uVar3) * (uint)uVar2);
      }
      portMemCopy(param_3 + (ulong)param_4,uVar2,param_6,uVar2);
      return 0;
    }
    nvAssertFailedNoLog("imageSize - sigDestOffset > sigSize",
                        "src/kernel/gpu/gsp/kernel_gsp_booter.c",0x96);
  }
  else {
    nvAssertFailedNoLog("imageSize > sigDestOffset","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x95);
  }
  return 0x25;
}


// ===== 00384bb0 kgspFreeVbiosImg =====

void kgspFreeVbiosImg(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    portMemFree(*param_1);
    *param_1 = 0;
    portMemFree(param_1);
    return;
  }
  return;
}


// ===== 00384bf0 kgspFreeFlcnUcode =====

void kgspFreeFlcnUcode(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return;
  }
  iVar1 = *param_1;
  if (iVar1 != 2) {
    if (iVar1 == 1) {
      if (*(long *)(param_1 + 2) != 0) {
        memdescFree();
        memdescDestroy(*(undefined8 *)(param_1 + 2));
        param_1[2] = 0;
        param_1[3] = 0;
      }
      if (*(long *)(param_1 + 4) != 0) {
        memdescFree();
        memdescDestroy(*(undefined8 *)(param_1 + 4));
        param_1[4] = 0;
        param_1[5] = 0;
      }
    }
    else if (iVar1 == 0) {
      portMemFree(*(undefined8 *)(param_1 + 2));
      param_1[2] = 0;
      param_1[3] = 0;
      portMemFree(param_1);
      return;
    }
    portMemFree(param_1);
    return;
  }
  if (*(long *)(param_1 + 2) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_1 + 2));
    param_1[2] = 0;
    param_1[3] = 0;
  }
  portMemFree(*(undefined8 *)(param_1 + 0x10));
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  portMemFree(param_1);
  return;
}


// ===== 00384ce0 s_allocateUcodeFromBinArchive =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int s_allocateUcodeFromBinArchive
              (undefined8 param_1,long param_2,undefined8 param_3,undefined8 *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined4 *puVar13;
  undefined8 uVar14;
  char *pcVar15;
  int local_7c;
  int local_78;
  uint local_74;
  undefined8 local_70;
  undefined1 local_68 [4];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  undefined4 uStack_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  
  local_70 = 0;
  cVar1 = (**(code **)(param_2 + 0x800))();
  if (cVar1 == '\0') {
    lVar6 = bindataArchiveGetStorage(param_3,4);
    lVar7 = bindataArchiveGetStorage(param_3,1);
    lVar8 = bindataArchiveGetStorage(param_3,0xe);
  }
  else {
    lVar6 = bindataArchiveGetStorage(param_3,3);
    lVar7 = bindataArchiveGetStorage(param_3,0);
    lVar8 = bindataArchiveGetStorage(param_3,0xd);
  }
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pBinImage != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0xe5);
    return 0x56;
  }
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pBinHeader != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0xe6);
    return 0x56;
  }
  if (lVar8 == 0) {
    nvAssertFailedNoLog("pBinSig != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0xe7);
    return 0x56;
  }
  lVar9 = bindataArchiveGetStorage(param_3,0xc);
  lVar10 = bindataArchiveGetStorage(param_3,10);
  lVar11 = bindataArchiveGetStorage(param_3,0xb);
  lVar12 = bindataArchiveGetStorage(param_3,7);
  if (lVar9 == 0) {
    nvAssertFailedNoLog("pBinPatchSig != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0xee);
    return 0x56;
  }
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pBinPatchLoc != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0xef);
    return 0x56;
  }
  if (lVar11 == 0) {
    nvAssertFailedNoLog("pBinPatchMeta != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0xf0);
    return 0x56;
  }
  if (lVar12 == 0) {
    nvAssertFailedNoLog("pBinNumSigs != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0xf1);
    return 0x56;
  }
  puVar13 = (undefined4 *)portMemAllocNonPaged(0x60);
  if (puVar13 == (undefined4 *)0x0) {
    return 0x51;
  }
  portMemSet(puVar13,0,0x60);
  iVar2 = bindataGetBufferSize(lVar7);
  iVar3 = 0x25;
  if ((iVar2 == 0x24) && (iVar3 = bindataWriteToBuffer(lVar7,&local_5c,0x24), iVar3 == 0)) {
    uVar14 = 0x101;
    if (local_4c != 1) goto LAB_00384f90;
    iVar2 = bindataGetBufferSize(lVar10);
    iVar3 = 0x25;
    if ((iVar2 == 4) && (iVar3 = bindataWriteToBuffer(lVar10,&local_7c,4), iVar3 == 0)) {
      iVar2 = bindataGetBufferSize(lVar9);
      iVar3 = 0x25;
      if ((iVar2 == 4) && (iVar3 = bindataWriteToBuffer(lVar9,&local_78,4), iVar3 == 0)) {
        uVar14 = 0x112;
        if (local_78 != 0) goto LAB_00384f90;
        iVar2 = bindataGetBufferSize(lVar11);
        iVar3 = 0x25;
        if ((iVar2 == 0xc) && (iVar3 = bindataWriteToBuffer(lVar11,local_68,0xc), iVar3 == 0)) {
          iVar2 = bindataGetBufferSize(lVar12);
          iVar3 = 0x25;
          if ((iVar2 == 4) && (iVar3 = bindataWriteToBuffer(lVar12,&local_74,4), iVar3 == 0)) {
            if (local_74 == 0) {
              uVar14 = 0x123;
            }
            else {
              uVar4 = bindataGetBufferSize(lVar8);
              if ((uVar4 != 0) && (uVar4 % local_74 == 0)) {
                iVar3 = bindataStorageAcquireData(lVar8,&local_70);
                if (iVar3 == 0) {
                  if (*(char *)(*(long *)(param_2 + 2000) + 0x628) == '\0') {
                    *puVar13 = 0;
                    uVar5 = bindataGetBufferSize(lVar6);
                    puVar13[0xc] = 0;
                    puVar13[4] = uVar5;
                    puVar13[7] = local_5c;
                    puVar13[6] = local_58;
                    puVar13[9] = local_48;
                    puVar13[8] = local_44;
                    *(ulong *)(puVar13 + 10) = CONCAT44(uStack_50,local_54);
                    lVar7 = portMemAllocNonPaged(uVar5);
                    *(long *)(puVar13 + 2) = lVar7;
                    if (lVar7 == 0) {
                      bindataStorageReleaseData(local_70);
                      iVar3 = 0x51;
                      goto LAB_00384e62;
                    }
                    iVar3 = bindataWriteToBuffer(lVar6,lVar7,puVar13[4]);
                    uVar14 = 0x191;
                    pcVar15 = "bindataWriteToBuffer(pBinImage, pUcode->pImage, pUcode->size)";
                    if (iVar3 == 0) {
                      iVar3 = s_patchBooterUcodeSignature
                                        (param_1,local_60,*(undefined8 *)(puVar13 + 2),local_7c,
                                         puVar13[4],local_70,uVar4,local_74);
                      if (iVar3 == 0) {
LAB_00385365:
                        bindataStorageReleaseData(local_70);
                        *param_4 = puVar13;
                        return 0;
                      }
                      uVar14 = 0x196;
                      pcVar15 = 
                      "s_patchBooterUcodeSignature(pGpu, patchMeta.ucodeId, pUcode->pImage, patchLoc, pUcode->size, pSignatures, signaturesTotalSize, numSigs)"
                      ;
                    }
                  }
                  else {
                    *puVar13 = 2;
                    uVar5 = bindataGetBufferSize(lVar6);
                    puVar13[7] = 0;
                    puVar13[4] = uVar5;
                    puVar13[5] = local_48;
                    puVar13[8] = local_48;
                    puVar13[6] = local_44;
                    *(ulong *)(puVar13 + 9) = CONCAT44(uStack_50,local_54);
                    *(undefined8 *)(puVar13 + 0xb) = 0xffffffff00000000;
                    puVar13[0xd] = local_7c - local_54;
                    puVar13[0xe] = local_60;
                    puVar13[0xf] = local_64;
                    iVar3 = memdescCreate(puVar13 + 2,param_1,uVar5,0x10,1,1);
                    uVar14 = 0x14d;
                    pcVar15 = 
                    "memdescCreate(&pUcode->pUcodeMemDesc, pGpu, pUcode->size, 16, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                    ;
                    if (iVar3 == 0) {
                      *(undefined4 *)(*(long *)(puVar13 + 2) + 0x9c) = 0x5a;
                      iVar3 = memdescAlloc(*(undefined8 *)(puVar13 + 2));
                      if (iVar3 == 0) {
                        lVar7 = memdescMapInternal(param_1,*(undefined8 *)(puVar13 + 2),0);
                        if (lVar7 == 0) {
                          bindataStorageReleaseData(local_70);
                          iVar3 = 0x1a;
                        }
                        else {
                          iVar3 = bindataWriteToBuffer(lVar6,lVar7,puVar13[4]);
                          if (iVar3 == 0) {
                            iVar3 = s_patchBooterUcodeSignature
                                              (param_1,local_60,lVar7,local_7c,puVar13[4],local_70,
                                               uVar4,local_74);
                            if (iVar3 == 0) {
                              memdescUnmapInternal(param_1,*(undefined8 *)(puVar13 + 2),0x10);
                              goto LAB_00385365;
                            }
                            nvAssertFailedNoLog("status == NV_OK",
                                                "src/kernel/gpu/gsp/kernel_gsp_booter.c",0x16a);
                          }
                          else {
                            nvAssertFailedNoLog("status == NV_OK",
                                                "src/kernel/gpu/gsp/kernel_gsp_booter.c",0x161);
                          }
                          memdescUnmapInternal(param_1,*(undefined8 *)(puVar13 + 2),0x10);
                          bindataStorageReleaseData(local_70);
                        }
                      }
                      else {
                        bindataStorageReleaseData(local_70);
                      }
                      goto LAB_00384e62;
                    }
                  }
                  nvAssertOkFailedNoLog
                            (iVar3,pcVar15,"src/kernel/gpu/gsp/kernel_gsp_booter.c",uVar14);
                  bindataStorageReleaseData(local_70);
                  goto LAB_00384e62;
                }
                uVar14 = 0x131;
                pcVar15 = "bindataStorageAcquireData(pBinSig, &pSignatures)";
                goto LAB_00384e43;
              }
              uVar14 = 300;
            }
LAB_00384f90:
            nvAssertFailedNoLog(&DAT_00d3f243,"src/kernel/gpu/gsp/kernel_gsp_booter.c",uVar14);
            bindataStorageReleaseData(local_70);
            iVar3 = 0x25;
            goto LAB_00384e62;
          }
          uVar14 = 0x11d;
          pcVar15 = "s_bindataWriteToFixedSizeBuffer(pBinNumSigs, &numSigs, sizeof(numSigs))";
        }
        else {
          uVar14 = 0x118;
          pcVar15 = "s_bindataWriteToFixedSizeBuffer(pBinPatchMeta, &patchMeta, sizeof(patchMeta))";
        }
      }
      else {
        uVar14 = 0x10c;
        pcVar15 = "s_bindataWriteToFixedSizeBuffer(pBinPatchSig, &patchSig, sizeof(patchSig))";
      }
    }
    else {
      uVar14 = 0x107;
      pcVar15 = "s_bindataWriteToFixedSizeBuffer(pBinPatchLoc, &patchLoc, sizeof(patchLoc))";
    }
  }
  else {
    uVar14 = 0xfb;
    pcVar15 = "s_bindataWriteToFixedSizeBuffer(pBinHeader, &header, sizeof(header))";
  }
LAB_00384e43:
  nvAssertOkFailedNoLog(iVar3,pcVar15,"src/kernel/gpu/gsp/kernel_gsp_booter.c",uVar14);
  bindataStorageReleaseData(local_70);
LAB_00384e62:
  local_70 = 0;
  kgspFreeFlcnUcode(puVar13);
  return iVar3;
}


// ===== 003854e0 kgspAllocateBooterLoadUcodeImage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspAllocateBooterLoadUcodeImage_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("ppBooterLoadUcode != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x1b9);
    return 0x1f;
  }
  lVar1 = (**(code **)(param_2 + 0x958))(param_2);
  if (lVar1 != 0) {
    uVar2 = s_allocateUcodeFromBinArchive(param_1,param_2,lVar1,param_3);
    return uVar2;
  }
  nvAssertFailedNoLog("pBinArchive != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x1bc);
  return 0x56;
}


// ===== 00385590 kgspAllocateBooterUnloadUcodeImage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspAllocateBooterUnloadUcodeImage_IMPL(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("ppBooterUnloadUcode != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x1cb
                       );
    return 0x1f;
  }
  lVar1 = (**(code **)(param_2 + 0x960))(param_2);
  if (lVar1 != 0) {
    uVar2 = s_allocateUcodeFromBinArchive(param_1,param_2,lVar1,param_3);
    return uVar2;
  }
  nvAssertFailedNoLog("pBinArchive != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x1ce);
  return 0x56;
}


// ===== 00385640 kgspAllocateScrubberUcodeImage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kgspAllocateScrubberUcodeImage_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x1ba0) == 0) {
    nvAssertFailedNoLog("pKernelSec2 != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x1e3);
    uVar2 = 0x40;
  }
  else if (param_3 == 0) {
    nvAssertFailedNoLog("ppScrubberUcode != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x1e4);
    uVar2 = 0x1f;
  }
  else {
    lVar1 = (**(code **)(*(long *)(param_1 + 0x1ba0) + 0x818))();
    if (lVar1 != 0) {
      uVar2 = s_allocateUcodeFromBinArchive(param_1,param_2,lVar1,param_3);
      return uVar2;
    }
    nvAssertFailedNoLog("pBinArchive != NULL","src/kernel/gpu/gsp/kernel_gsp_booter.c",0x1e7);
    uVar2 = 0x56;
  }
  return uVar2;
}


// ===== 00385700 s_vbiosReadStructure =====

uint s_vbiosReadStructure(long *param_1,uint *param_2,uint param_3,char *param_4)

{
  uint *puVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  char *pcVar7;
  char *pcVar8;
  char cVar9;
  uint *puVar10;
  uint uVar11;
  bool bVar12;
  
  cVar9 = *param_4;
  if (cVar9 == '\0') {
    return -(uint)(*(uint *)(param_1 + 1) < param_3) & 0x37;
  }
  param_4 = param_4 + 1;
  uVar11 = 0;
  pcVar8 = param_4;
  cVar3 = cVar9;
  do {
    iVar4 = 0;
    pcVar7 = pcVar8;
    if ((byte)(cVar3 - 0x30U) < 10) {
      do {
        pcVar8 = pcVar7 + 1;
        iVar4 = cVar3 + -0x30 + iVar4 * 10;
        cVar3 = *pcVar7;
        pcVar7 = pcVar8;
      } while ((byte)(cVar3 - 0x30U) < 10);
      if (iVar4 == 0) {
        iVar4 = 1;
      }
    }
    else {
      iVar4 = 1;
    }
    if (cVar3 == 's') {
LAB_003858a0:
      uVar11 = uVar11 + iVar4;
    }
    else if (cVar3 < 't') {
      if (cVar3 == 'b') goto LAB_003858a0;
      if (cVar3 == 'd') {
        uVar11 = uVar11 + iVar4 * 4;
      }
    }
    else if (cVar3 == 'w') {
      uVar11 = uVar11 + iVar4 * 2;
    }
    cVar3 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    if (cVar3 == '\0') {
      if ((CARRY4(uVar11,param_3)) || (*(uint *)(param_1 + 1) < uVar11 + param_3)) {
        return 0x37;
      }
      puVar5 = (uint *)((ulong)param_3 + *param_1);
      do {
        iVar4 = 0;
        pcVar8 = param_4;
        if ((byte)(cVar9 - 0x30U) < 10) {
          do {
            pcVar8 = param_4 + 1;
            iVar4 = cVar9 + -0x30 + iVar4 * 10;
            cVar9 = *param_4;
            param_4 = pcVar8;
          } while ((byte)(cVar9 - 0x30U) < 10);
          bVar12 = iVar4 == 0;
          iVar4 = iVar4 + -1;
          if (bVar12) {
            iVar4 = 0;
          }
        }
        puVar1 = param_2 + (iVar4 + 1);
        puVar6 = puVar5;
        if (cVar9 == 's') {
          do {
            puVar5 = (uint *)((long)puVar6 + 1);
            bVar2 = (byte)*puVar6;
            uVar11 = (uint)bVar2;
            if ((char)bVar2 < '\0') {
              uVar11 = bVar2 | 0xffffff00;
            }
            puVar10 = param_2 + 1;
            *param_2 = uVar11;
            puVar6 = puVar5;
            param_2 = puVar10;
          } while (puVar1 != puVar10);
        }
        else {
          if ('s' < cVar9) {
            if (cVar9 == 'w') goto LAB_003858e0;
            return 0xffff;
          }
          if (cVar9 != 'b') {
            if (cVar9 != 'd') {
              return 0xffff;
            }
            do {
              uVar11 = *puVar5;
              puVar5 = puVar5 + 1;
              *param_2 = uVar11;
              while( true ) {
                param_2 = param_2 + 1;
                if (param_2 == puVar1) goto LAB_00385867;
                if (cVar9 < 't') break;
LAB_003858e0:
                uVar11 = *puVar5;
                puVar5 = (uint *)((long)puVar5 + 2);
                *param_2 = (uint)(ushort)uVar11;
              }
            } while (cVar9 != 'b');
          }
          do {
            uVar11 = *puVar5;
            puVar6 = param_2 + 1;
            puVar5 = (uint *)((long)puVar5 + 1);
            *param_2 = (uint)(byte)uVar11;
            param_2 = puVar6;
          } while (puVar1 != puVar6);
        }
LAB_00385867:
        cVar9 = *pcVar8;
        if (cVar9 == '\0') {
          return 0;
        }
        param_4 = pcVar8 + 1;
        param_2 = puVar1;
      } while( true );
    }
  } while( true );
}


// ===== 00385940 kgspParseFwsecUcodeFromVbiosImg_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspParseFwsecUcodeFromVbiosImg_IMPL
              (long param_1,long param_2,long *param_3,undefined8 *param_4,ulong *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  undefined8 uVar12;
  undefined4 *puVar13;
  long lVar14;
  long lVar15;
  char *pcVar16;
  char cVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  undefined8 extraout_RDX;
  uint uVar21;
  int iVar22;
  uint uVar23;
  char *pcVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  undefined8 uVar30;
  uint local_160;
  undefined4 local_15c;
  undefined4 local_158;
  int local_148;
  undefined4 local_144;
  uint local_140;
  undefined4 local_13c;
  int local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_120;
  int local_dc;
  uint local_d8;
  int local_d4 [2];
  int local_cc;
  undefined8 local_c8;
  undefined8 local_c0;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  undefined1 local_9c [12];
  int local_90;
  uint local_8c;
  int local_88;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74 [4];
  int local_70;
  uint local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x909) != '\0') {
      if (param_3 == (long *)0x0) {
        nvAssertFailedNoLog("pVbiosImg != NULL","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x468);
      }
      else if (*param_3 == 0) {
        nvAssertFailedNoLog("pVbiosImg->pImage != NULL","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",
                            0x469);
      }
      else {
        if (param_4 != (undefined8 *)0x0) {
          if ((int)param_3[1] == 0) {
            iVar9 = 0x1f;
            nvAssertFailedNoLog("pVbiosImg->biosSize > 0","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",
                                0x1a0);
          }
          else {
            uVar21 = 0;
            if ((int)param_3[1] != 3) {
LAB_003859f3:
              iVar9 = s_vbiosReadStructure(param_3,&local_80,uVar21,&DAT_00d3f66c);
              if ((short)local_80 == -0x4701) {
                if (iVar9 != 0) goto LAB_00385ad0;
                iVar9 = s_vbiosReadStructure(param_3,&local_80,uVar21 + 2,&DAT_00d3f66e);
                if (local_80 != 0x544942) goto LAB_003859d8;
                if (iVar9 == 0) {
                  iVar9 = s_vbiosReadStructure(param_3,&local_80,uVar21 + 8,&DAT_00d3f670);
                  if ((char)local_80 != '\0') {
                    uVar29 = (local_80 & 0xff) + uVar21;
                    iVar26 = 0;
                    uVar23 = uVar21;
LAB_00385a80:
                    if (iVar9 == 0) goto code_r0x00385a88;
                    if ((uVar29 - uVar23 & 1) == 0) goto LAB_00386a38;
                    for (uVar23 = uVar23 + 1; uVar23 != uVar29; uVar23 = uVar23 + 2) {
LAB_00386a38:
                    }
                    goto LAB_00386a41;
                  }
                  if (iVar9 == 0) goto LAB_00385c29;
                }
LAB_00386a41:
                nvAssertOkFailedNoLog(iVar9,"status","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x1b7);
              }
              else {
LAB_003859d8:
                if (iVar9 == 0) goto LAB_003859e1;
LAB_00385ad0:
                nvAssertOkFailedNoLog(iVar9,"status","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x1c2);
              }
              goto LAB_00385aef;
            }
LAB_00385b50:
            iVar9 = 0xffff;
          }
LAB_00385aef:
          nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x46f,
                       "kgspParseFwsecUcodeFromVbiosImg_IMPL",4,
                       "NVRM: failed to find BIT header in VBIOS image: 0x%x\n",iVar9);
          return iVar9;
        }
        nvAssertFailedNoLog("ppFwsecUcode","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x46a);
      }
      return 0x1f;
    }
    nvAssertFailedNoLog("IS_GSP_CLIENT(pGpu)","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x466);
  }
  else {
    nvAssertFailedNoLog("!IS_VIRTUAL(pGpu)","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x465);
  }
  return 0x56;
code_r0x00385a88:
  uVar28 = uVar23 + 1;
  iVar9 = s_vbiosReadStructure(param_3,&local_80,uVar23,&DAT_00d3f670);
  iVar26 = iVar26 + (local_80 & 0xff);
  uVar23 = uVar28;
  if (uVar28 == uVar29) goto code_r0x00385aae;
  goto LAB_00385a80;
code_r0x00385aae:
  if (iVar9 != 0) goto LAB_00386a41;
  if ((char)iVar26 == '\0') {
LAB_00385c29:
    cVar8 = (**(code **)(param_2 + 0x800))(param_1);
    if (*param_3 == 0) {
      nvAssertFailedNoLog("pVbiosImg->pImage != NULL","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x1e3)
      ;
    }
    else {
      if ((int)param_3[1] != 0) {
        local_88 = 0;
        iVar26 = s_vbiosReadStructure(param_3,local_9c,uVar21,"1w1d1w4b");
        iVar9 = local_88;
        if (iVar26 != 0) {
          nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x1eb,
                       "s_vbiosParseFwsecUcodeDescFromBit",4,
                       "NVRM: failed to read BIT table structure: 0x%x\n",iVar26);
          goto LAB_00385e26;
        }
        if (local_8c < 8) {
          pcVar24 = "2b2w";
          if (local_8c < 6) {
            iVar26 = 0x40;
            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x1f9,
                         "s_vbiosParseFwsecUcodeDescFromBit",4,"NVRM: Invalid BIT token size: %u\n",
                         local_8c);
            goto LAB_00385e26;
          }
        }
        else {
          pcVar24 = "2b1w1d";
        }
        if (local_88 != 0) {
          iVar22 = uVar21 + local_90;
          iVar26 = 0;
          do {
            local_c8 = 0;
            local_c0 = 0;
            uVar12 = s_vbiosReadStructure(param_3,&local_c8,iVar22,pcVar24);
            if ((int)uVar12 == 0) {
              if ((param_5 == (ulong *)0x0) || ((int)local_c8 != 0x42)) {
                if (((int)local_c8 == 0x70) && ((local_c8._4_4_ == 2 && (3 < (uint)local_c0)))) {
                  uVar12 = s_vbiosReadStructure(param_3,&local_dc,local_c0._4_4_,&DAT_00d3f687);
                  iVar18 = local_dc;
                  if ((int)uVar12 == 0) {
                    local_a8 = 0;
                    uVar11 = s_vbiosReadStructure
                                       (param_3,&local_b4,local_dc + *(int *)((long)param_3 + 0xc),
                                        &DAT_00d3f68a);
                    uVar23 = local_a8;
                    uVar21 = local_ac;
                    if ((int)uVar11 == 0) {
                      if ((((local_b4 == 1) && (5 < local_b0)) && (5 < local_ac)) &&
                         (iVar18 = local_b0 + iVar18, local_a8 != 0)) {
                        uVar11 = uVar11 & 0xffffffff;
                        iVar27 = 0;
                        do {
                          uVar12 = s_vbiosReadStructure
                                             (param_3,local_d4,
                                              iVar18 + *(int *)((long)param_3 + 0xc) + iVar27,
                                              &DAT_00d3f68d);
                          iVar1 = local_cc;
                          if ((int)uVar12 != 0) {
                            nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x265,
                                         "s_vbiosParseFwsecUcodeDescFromBit",4,
                                         "NVRM: failed to read Falcon ucode entry %u (BIT token %u), skipping: 0x%x\n"
                                         ,uVar11,iVar26,uVar12);
                            goto LAB_003864cb;
                          }
                          if (local_d4[0] == 5) {
LAB_00386059:
                            uVar12 = s_vbiosReadStructure
                                               (param_3,&local_d8,
                                                *(int *)((long)param_3 + 0xc) + local_cc,
                                                &DAT_00d3f687);
                            if ((int)uVar12 == 0) {
                              if ((local_d8 & 1) == 0) {
                                nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x282,
                                             "s_vbiosParseFwsecUcodeDescFromBit",4,
                                             "NVRM: unexpected ucode desc version missing for entry %u (BIT token %u), skipping\n"
                                             ,uVar11,iVar26);
                              }
                              else {
                                uVar29 = local_d8 >> 8 & 0xff;
                                uVar28 = local_d8 >> 0x10;
                                cVar17 = (char)(local_d8 >> 8);
                                if ((cVar17 == '\x02') && (0x3b < uVar28)) {
                                  pcVar16 = "15d";
                                }
                                else if ((cVar17 != '\x03') || (pcVar16 = "9d1w2b2w", uVar28 < 0x2c)
                                        ) {
                                  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x299,
                                               "s_vbiosParseFwsecUcodeDescFromBit",4,
                                               "NVRM: unexpected ucode desc version 0x%x or size 0x%x for entry %u (BIT token %u), skipping\n"
                                               ,uVar29,uVar28,uVar11,iVar26);
                                  goto LAB_003864cb;
                                }
                                local_80 = local_160;
                                uVar19 = *(int *)((long)param_3 + 0xc) + iVar1;
                                local_7c = local_158;
                                local_78 = local_15c;
                                local_68 = local_13c;
                                local_64 = local_144;
                                local_60 = local_130;
                                local_58 = local_148;
                                local_54 = local_140;
                                local_50 = local_138;
                                local_4c = local_128;
                                local_48 = local_134;
                                local_44 = local_12c;
                                local_5c = local_120;
                                iVar10 = s_vbiosReadStructure(param_3,local_74,uVar19,pcVar16);
                                uVar7 = local_44;
                                uVar6 = local_48;
                                uVar20 = local_4c;
                                iVar5 = local_50;
                                uVar25 = local_54;
                                iVar1 = local_58;
                                uVar4 = local_60;
                                uVar3 = local_64;
                                uVar2 = local_68;
                                local_13c = local_68;
                                local_144 = local_64;
                                local_130 = local_60;
                                local_148 = local_58;
                                local_140 = local_54;
                                local_138 = local_50;
                                local_128 = local_4c;
                                local_134 = local_48;
                                local_12c = local_44;
                                if (iVar10 == 0) {
                                  puVar13 = (undefined4 *)portMemAllocNonPaged(0x60);
                                  if (puVar13 != (undefined4 *)0x0) {
                                    portMemSet(puVar13,0,0x60);
                                    if (uVar29 == 2) {
                                      if (*param_3 == 0) {
                                        nvAssertFailedNoLog("pVbiosImg->pImage != NULL",
                                                            "src/kernel/gpu/gsp/kernel_gsp_fwsec.c",
                                                            0x2e1);
                                      }
                                      *puVar13 = 1;
                                      *(undefined8 *)(puVar13 + 2) = 0;
                                      puVar13[7] = local_5c;
                                      puVar13[8] = local_5c - iVar5;
                                      *(undefined8 *)(puVar13 + 4) = 0;
                                      puVar13[10] = iVar5 + 0xffU & 0xffffff00;
                                      puVar13[6] = 0;
                                      puVar13[9] = uVar4;
                                      puVar13[0xb] = (uVar25 + uVar4) - iVar1;
                                      puVar13[0xc] = uVar2;
                                      puVar13[0xd] = uVar20;
                                      puVar13[0xe] = uVar7;
                                      puVar13[0xf] = uVar6;
                                      puVar13[0x10] = uVar3;
                                      uVar21 = uVar28 + uVar19;
                                      if ((((!CARRY4(uVar28,uVar19)) &&
                                           (uVar23 = *(uint *)(param_3 + 1), uVar21 < uVar23)) &&
                                          ((!CARRY4(local_5c,uVar21) &&
                                           (((local_5c + uVar21 <= uVar23 &&
                                             (uVar25 = uVar20 + uVar21, !CARRY4(uVar20,uVar21))) &&
                                            (uVar25 < uVar23)))))) &&
                                         ((uVar20 = local_5c + 0xff & 0xffffff00,
                                          uVar25 + uVar7 <= uVar23 && !CARRY4(uVar25,uVar7) &&
                                          (uVar4 < uVar20)))) {
                                        uVar23 = uVar7 + 0xff & 0xffffff00;
                                        if ((!CARRY4(uVar4,local_5c) && uVar4 + local_5c <= uVar20)
                                           && (((uVar6 < uVar23 && (!CARRY4(uVar6,uVar7))) &&
                                               (uVar6 + uVar7 <= uVar23)))) {
                                          uVar12 = 0x400;
                                          iVar9 = memdescCreate(puVar13 + 2,param_1,uVar20,0x100,1,1
                                                                ,1);
                                          if (iVar9 == 0) {
                                            uVar30 = 0x400;
                                            uVar23 = uVar7 + 0xff & 0xffffff00;
                                            uVar12 = 1;
                                            iVar9 = memdescCreate(puVar13 + 4,param_1,uVar23,0x100,1
                                                                  ,1);
                                            if (iVar9 == 0) {
                                              *(undefined4 *)(*(long *)(puVar13 + 2) + 0x9c) = 0x2a;
                                              iVar9 = memdescAlloc(*(undefined8 *)(puVar13 + 2),
                                                                   uVar30,extraout_RDX,uVar12);
                                              if (iVar9 == 0) {
                                                *(undefined4 *)(*(long *)(puVar13 + 4) + 0x9c) =
                                                     0x2b;
                                                iVar9 = memdescAlloc(*(undefined8 *)(puVar13 + 4));
                                                if (iVar9 == 0) {
                                                  lVar14 = memdescMapInternal(param_1,*(undefined8 *
                                                                                       )(puVar13 + 2
                                                                                        ),0);
                                                  if (lVar14 != 0) {
                                                    lVar15 = memdescMapInternal(param_1,*(undefined8
                                                                                          *)(puVar13
                                                                                            + 4),0);
                                                    if (lVar15 != 0) {
                                                      portMemSet(lVar14,0,uVar20);
                                                      portMemCopy(lVar14 + (ulong)(uint)puVar13[9],
                                                                  puVar13[7],
                                                                  (ulong)uVar21 + *param_3,
                                                                  puVar13[7]);
                                                      portMemSet(lVar15,0,uVar23);
                                                      portMemCopy(lVar15 + (ulong)(uint)puVar13[0xf]
                                                                  ,puVar13[0xe],
                                                                  (ulong)uVar25 + *param_3,
                                                                  puVar13[0xe]);
                                                      memdescUnmapInternal
                                                                (param_1,*(undefined8 *)
                                                                          (puVar13 + 2),0x10);
                                                      memdescUnmapInternal
                                                                (param_1,*(undefined8 *)
                                                                          (puVar13 + 4),0x10);
                                                      goto LAB_0038641d;
                                                    }
                                                    memdescUnmapInternal
                                                              (param_1,*(undefined8 *)(puVar13 + 2),
                                                               0x10);
                                                  }
                                                  goto LAB_00386ad6;
                                                }
                                              }
                                            }
                                            else {
                                              nvAssertOkFailedNoLog
                                                        (iVar9,
                                                  "memdescCreate(&pUcode->pDataMemDesc, pGpu, dataSizeAligned, 256, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_PHYSICALLY_CONTIGUOUS)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x330);
                                            }
                                          }
                                          else {
                                            nvAssertOkFailedNoLog
                                                      (iVar9,
                                                  "memdescCreate(&pUcode->pCodeMemDesc, pGpu, codeSizeAligned, 256, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_PHYSICALLY_CONTIGUOUS)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x32c,
                                                  uVar12);
                                          }
                                          goto LAB_00386446;
                                        }
                                      }
LAB_00386440:
                                      iVar9 = 0x37;
                                    }
                                    else {
                                      if (uVar29 != 3) {
                                        iVar26 = 0x40;
                                        nvAssertFailedNoLog(&DAT_00d3f692,
                                                            "src/kernel/gpu/gsp/kernel_gsp_fwsec.c",
                                                            0x434);
                                        goto LAB_0038651e;
                                      }
                                      if (*param_3 == 0) {
                                        nvAssertFailedNoLog("pVbiosImg->pImage != NULL",
                                                            "src/kernel/gpu/gsp/kernel_gsp_fwsec.c",
                                                            0x388);
                                      }
                                      *puVar13 = 2;
                                      *(undefined8 *)(puVar13 + 2) = 0;
                                      puVar13[7] = uVar3;
                                      puVar13[0xb] = iVar1;
                                      puVar13[8] = local_5c;
                                      uVar21 = local_70 + 0xffU & 0xffffff00;
                                      puVar13[0xf] = iVar5;
                                      puVar13[0xe] = uVar20;
                                      *(undefined8 *)(puVar13 + 0x12) = 0x18000000000;
                                      puVar13[0x14] = uVar6;
                                      puVar13[4] = uVar21;
                                      puVar13[5] = 0;
                                      puVar13[6] = uVar4;
                                      puVar13[9] = uVar4;
                                      puVar13[10] = uVar25;
                                      puVar13[0xc] = 0xffffffff;
                                      puVar13[0xd] = local_6c;
                                      *(undefined8 *)(puVar13 + 0x10) = 0;
                                      puVar13[0x15] = uVar7;
                                      puVar13[0x16] = uVar2;
                                      uVar23 = uVar28 + uVar19;
                                      if ((((((CARRY4(uVar28,uVar19)) ||
                                             (*(uint *)(param_3 + 1) <= uVar23)) ||
                                            ((*(uint *)(param_3 + 1) < uVar21 + uVar23 ||
                                             CARRY4(uVar21,uVar23)) || uVar21 < uVar4)) ||
                                           ((uVar21 <= uVar4 || (uVar21 < uVar25 + uVar4)))) ||
                                          (((CARRY4(uVar25,uVar4) ||
                                            ((uVar25 = uVar4 + local_6c, CARRY4(uVar4,local_6c) ||
                                             (uVar21 <= uVar25)))) || (0xfffffe7f < uVar25)))) ||
                                         (uVar21 < uVar25 + 0x180)) goto LAB_00386440;
                                      puVar13[0x12] = uVar28 - 0x2c;
                                      lVar14 = portMemAllocNonPaged();
                                      *(long *)(puVar13 + 0x10) = lVar14;
                                      if (lVar14 == 0) {
                                        iVar9 = 0x51;
                                      }
                                      else {
                                        portMemCopy(lVar14,puVar13[0x12],
                                                    *param_3 + 0x2c + (ulong)uVar19,puVar13[0x12]);
                                        iVar9 = memdescCreate(puVar13 + 2,param_1,puVar13[4],0x100,1
                                                              ,1,1);
                                        if (iVar9 == 0) {
                                          *(undefined4 *)(*(long *)(puVar13 + 2) + 0x9c) = 0x2c;
                                          iVar9 = memdescAlloc(*(undefined8 *)(puVar13 + 2));
                                          if (iVar9 == 0) {
                                            lVar14 = memdescMapInternal(param_1,*(undefined8 *)
                                                                                 (puVar13 + 2),0);
                                            if (lVar14 != 0) {
                                              portMemCopy(lVar14,puVar13[4],(ulong)uVar23 + *param_3
                                                          ,puVar13[4]);
                                              memdescUnmapInternal
                                                        (param_1,*(undefined8 *)(puVar13 + 2),0x10);
                                              goto LAB_0038641d;
                                            }
LAB_00386ad6:
                                            iVar9 = 0x1a;
                                          }
                                        }
                                        else {
                                          nvAssertOkFailedNoLog
                                                    (iVar9,
                                                  "memdescCreate(&pUcode->pUcodeMemDesc, pGpu, pUcode->size, 256, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                                                  ,"src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x3e4);
                                        }
                                      }
                                    }
LAB_00386446:
                                    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x43a,
                                                 "s_vbiosNewFlcnUcodeFromDesc",4,
                                                 "NVRM: failed to parse/prepare Falcon ucode (desc: version 0x%x, offset 0x%x, size 0x%x): 0x%x\n"
                                                 ,uVar29,uVar19,uVar28,iVar9);
                                    kgspFreeFlcnUcode(puVar13);
                                    puVar13 = (undefined4 *)0x0;
LAB_0038641d:
                                    *param_4 = puVar13;
                                    return 0;
                                  }
                                  iVar26 = 0x51;
LAB_0038651e:
                                  pcVar24 = 
                                  "NVRM: failed to prepare new flcn ucode for FWSEC: 0x%x\n";
                                  uVar12 = 0x47f;
                                  goto LAB_00385e41;
                                }
                                local_160 = local_80;
                                local_158 = local_7c;
                                local_15c = local_78;
                                nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x2a5,
                                             "s_vbiosParseFwsecUcodeDescFromBit",4,
                                             "NVRM: failed to read Falcon ucode desc (desc version 0x%x) for entry %u (BIT token %u), skipping: 0x%x\n"
                                             ,uVar29,uVar11,iVar26,iVar10);
                                local_120 = local_5c;
                              }
                            }
                            else {
                              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x279,
                                           "s_vbiosParseFwsecUcodeDescFromBit",4,
                                           "NVRM: failed to read Falcon ucode desc header for entry %u (BIT token %u), skipping: 0x%x\n"
                                           ,uVar11,iVar26,uVar12);
                            }
                          }
                          else if (cVar8 == '\0') {
                            if (local_d4[0] == 0x85) goto LAB_00386059;
                          }
                          else if (local_d4[0] == 0x45) goto LAB_00386059;
LAB_003864cb:
                          uVar29 = (int)uVar11 + 1;
                          uVar11 = (ulong)uVar29;
                          iVar27 = iVar27 + uVar21;
                        } while (uVar23 != uVar29);
                      }
                    }
                    else {
                      nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x244,
                                   "s_vbiosParseFwsecUcodeDescFromBit",4,
                                   "NVRM: failed to read Falcon ucode header (BIT token %u), skipping: 0x%x\n"
                                   ,iVar26,uVar11);
                    }
                  }
                  else {
                    nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x237,
                                 "s_vbiosParseFwsecUcodeDescFromBit",4,
                                 "NVRM: failed to read Falcon ucode data (BIT token %u), skipping: 0x%x\n"
                                 ,iVar26,uVar12);
                  }
                }
              }
              else if ((local_c8._4_4_ - 1U < 2) && (5 < (uint)local_c0)) {
                uVar12 = s_vbiosReadStructure(param_3,&local_b4,local_c0._4_4_,&DAT_00d3f682);
                if ((int)uVar12 == 0) {
                  *param_5 = (ulong)local_b4 << 8 | (ulong)local_b0;
                }
                else {
                  nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x221,
                               "s_vbiosParseFwsecUcodeDescFromBit",4,
                               "NVRM: failed to read BIOSDATA (BIT token %u), skipping: 0x%x\n",
                               iVar26,uVar12);
                }
              }
            }
            else {
              nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x20f,
                           "s_vbiosParseFwsecUcodeDescFromBit",4,
                           "NVRM: failed to read BIT token %u, skipping: 0x%x\n",iVar26,uVar12);
            }
            iVar22 = iVar22 + local_8c;
            iVar26 = iVar26 + 1;
          } while (iVar26 != iVar9);
        }
        iVar26 = 0x25;
LAB_00385e26:
        pcVar24 = "NVRM: failed to parse FWSEC ucode desc from VBIOS image: 0x%x\n";
        uVar12 = 0x478;
LAB_00385e41:
        nvDbg_Printf("src/kernel/gpu/gsp/kernel_gsp_fwsec.c",uVar12,
                     "kgspParseFwsecUcodeFromVbiosImg_IMPL",4,pcVar24,iVar26);
        return iVar26;
      }
      nvAssertFailedNoLog("pVbiosImg->biosSize > 0","src/kernel/gpu/gsp/kernel_gsp_fwsec.c",0x1e4);
    }
    iVar26 = 0x1f;
    goto LAB_00385e26;
  }
LAB_003859e1:
  uVar21 = uVar21 + 1;
  if ((int)param_3[1] - 3U <= uVar21) goto LAB_00385b50;
  goto LAB_003859f3;
}


// ===== 00386b30 gspTraceEventBufferLogRecord =====

void gspTraceEventBufferLogRecord(long param_1,short *param_2)

{
  short sVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char local_81;
  long local_80;
  long *local_78 [4];
  short *local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  
  lVar5 = multimapFindSubmap_IMPL(param_1 + 0x4980,0);
  if (lVar5 != 0) {
    uVar6 = mapFindLEQ_IMPL(lVar5,0xffffffffffffffff);
    uVar7 = mapFindGEQ_IMPL(lVar5,0);
    multimapItemIterRange_IMPL(local_78,param_1 + 0x4980,uVar7,uVar6);
    while (cVar3 = multimapItemIterNext_IMPL(local_78), cVar3 != '\0') {
      while( true ) {
        plVar2 = local_78[0];
        lVar5 = *(long *)(param_1 + 0x1b88);
        sVar1 = *(short *)(*local_78[0] + 0x15c);
        *(short *)(*local_78[0] + 0x15c) = sVar1 + 1;
        *param_2 = sVar1;
        *(long *)(param_2 + 8) = *(long *)(param_2 + 8) + *(long *)(lVar5 + 0x24f8);
        portMemSet(&local_58,0,0x20);
        local_40 = 0;
        local_48 = 0;
        local_50 = 0x20;
        local_58 = param_2;
        iVar4 = eventBufferAdd(*plVar2,&local_58,8,&local_81,&local_80);
        if (((iVar4 != 0) || (local_81 == '\0')) || (local_80 == 0)) break;
        osEventNotification(param_1,*(undefined8 *)(*plVar2 + 0x160),8,&local_58,0);
        *(undefined1 *)(*plVar2 + 0x15e) = 1;
        cVar3 = multimapItemIterNext_IMPL(local_78);
        if (cVar3 == '\0') {
          return;
        }
      }
    }
  }
  return;
}


// ===== 00386ca0 gspTraceNotifyAllConsumers =====

void gspTraceNotifyAllConsumers(long param_1)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  char cVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  uint uVar10;
  long *local_48 [4];
  
  lVar5 = multimapFindSubmap_IMPL(param_1 + 0x4980,0);
  if (lVar5 != 0) {
    uVar6 = mapFindLEQ_IMPL(lVar5,0xffffffffffffffff);
    uVar7 = mapFindGEQ_IMPL(lVar5,0);
    multimapItemIterRange_IMPL(local_48,param_1 + 0x4980,uVar7,uVar6);
LAB_00386d20:
    cVar4 = multimapItemIterNext_IMPL(local_48);
    if (cVar4 != '\0') {
      do {
        plVar3 = local_48[0];
        if (*(char *)(param_1 + 0x908) == '\0') {
LAB_00386d10:
          cVar4 = eventBufferIsEmpty(*plVar3);
        }
        else {
          lVar5 = local_48[0][4];
          lVar8 = osGetTimestamp();
          lVar2 = *(long *)(lVar5 + 0x20);
          uVar9 = osGetTimestampFreq();
          if ((ulong)(lVar8 - lVar2) <= uVar9) goto LAB_00386d10;
          uVar1 = *(uint *)(lVar5 + 0x1c);
          uVar10 = *(uint *)(lVar5 + 0x18);
          uVar9 = (ulong)uVar10;
          while (uVar10 != uVar1) {
            gspTraceEventBufferLogRecord(param_1,lVar5 + 0x30 + uVar9 * 0x20);
            uVar9 = (ulong)(*(int *)(lVar5 + 0x18) + 1) % (ulong)*(uint *)(lVar5 + 4);
            uVar10 = (uint)uVar9;
            *(uint *)(lVar5 + 0x18) = uVar10;
          }
          uVar6 = osGetTimestamp();
          *(undefined8 *)(lVar5 + 0x20) = uVar6;
          cVar4 = eventBufferIsEmpty(*plVar3);
        }
        if (cVar4 != '\0') goto LAB_00386d20;
        osEventNotification(param_1,*(undefined8 *)(*plVar3 + 0x160),8,0,0);
        cVar4 = multimapItemIterNext_IMPL(local_48);
        if (cVar4 == '\0') {
          return;
        }
      } while( true );
    }
  }
  return;
}


// ===== 00386e10 gspTraceServiceVgpuEventTracing =====

void gspTraceServiceVgpuEventTracing(long param_1)

{
  uint uVar1;
  char cVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  long local_48 [4];
  
  lVar3 = multimapFindSubmap_IMPL(param_1 + 0x4980,0);
  if (lVar3 != 0) {
    uVar4 = mapFindLEQ_IMPL(lVar3,0xffffffffffffffff);
    uVar5 = mapFindGEQ_IMPL(lVar3,0);
    multimapItemIterRange_IMPL(local_48,param_1 + 0x4980,uVar5,uVar4);
    cVar2 = multimapItemIterNext_IMPL(local_48);
    if ((cVar2 == '\0') || (local_48[0] == 0)) {
      return;
    }
    lVar3 = *(long *)(local_48[0] + 0x20);
    if (lVar3 == 0) {
      return;
    }
    uVar1 = *(uint *)(lVar3 + 0x1c);
    uVar6 = *(uint *)(lVar3 + 0x18);
    uVar7 = (ulong)uVar6;
    *(undefined1 *)(lVar3 + 1) = 0;
    while (uVar6 != uVar1) {
      gspTraceEventBufferLogRecord(param_1,lVar3 + 0x30 + uVar7 * 0x20);
      uVar7 = (ulong)(*(int *)(lVar3 + 0x18) + 1) % (ulong)*(uint *)(lVar3 + 4);
      uVar6 = (uint)uVar7;
      *(uint *)(lVar3 + 0x18) = uVar6;
    }
    uVar4 = osGetTimestamp();
    *(undefined8 *)(lVar3 + 0x20) = uVar4;
  }
  return;
}


// ===== 00386f30 gspTraceRemoveBindpoint =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void gspTraceRemoveBindpoint(long param_1,undefined8 param_2,long *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (*(short *)(param_1 + 0x49b4) == 0) {
    return;
  }
  lVar3 = *param_3;
  *(short *)(param_1 + 0x49b4) = *(short *)(param_1 + 0x49b4) + -1;
  uVar1 = *(undefined4 *)(param_1 + 0x3b34);
  uVar2 = *(undefined4 *)(param_1 + 0x3b3c);
  unregisterEventNotificationWithData
            (lVar3 + 0x160,(int)param_3[1],*(undefined4 *)((long)param_3 + 0xc),(int)param_3[2],1,
             *(undefined8 *)(lVar3 + 0x1a8));
  multimapRemoveItemByKey_IMPL(param_1 + 0x4980,param_2,lVar3);
  if (*(short *)(param_1 + 0x49b4) == 0) {
    osRemove1HzCallback(param_1,gspTraceNotifyAllConsumers,0);
    if (*(char *)(param_1 + 0x49b6) != '\0') {
      local_58 = 0;
      local_50 = 0;
      local_48 = 0;
      local_40 = 2;
      (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,uVar1,uVar2,0x208001e3,&local_58,0x20);
      if (*(char *)(param_1 + 0x908) != '\0') {
        memdescUnmapInternal(param_1,param_3[5],0);
        memdescFree(param_3[5]);
        memdescDestroy(param_3[5]);
        param_3[5] = 0;
        param_3[4] = 0;
      }
      *(undefined1 *)(param_1 + 0x49b6) = 0;
    }
  }
  return;
}


// ===== 00387090 gspTraceAddBindpoint =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gspTraceAddBindpoint
                (long param_1,long param_2,long param_3,undefined4 param_4,undefined8 param_5,
                int param_6,undefined4 param_7)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  ulong uVar13;
  uint local_5c;
  undefined8 local_58;
  undefined8 local_50;
  int local_48;
  undefined4 local_44;
  undefined8 local_40;
  
  uVar3 = *(undefined4 *)(param_2 + 0x48);
  uVar4 = *(undefined4 *)(param_3 + 0x10);
  uVar5 = *(undefined4 *)(param_1 + 0x3b34);
  uVar6 = *(undefined4 *)(param_1 + 0x3b3c);
  lVar9 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmClient);
  sVar2 = *(short *)(param_1 + 0x49b4);
  cVar7 = rmapiLockIsOwner();
  if ((cVar7 == '\0') ||
     (cVar7 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4)), cVar7 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() && rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/gsp/kernel_gsp_trace_rats.c",0xd4);
    return 0x2f;
  }
  if (sVar2 < 1) {
    lVar10 = __nvoc_dynamicCast(*(undefined8 *)(param_3 + 8),__nvoc_class_def_EventBuffer);
    if (lVar10 == 0) {
      return 0x1f;
    }
    lVar11 = multimapFindSubmap_IMPL(param_1 + 0x4980,0);
    if ((lVar11 == 0) && (lVar11 = multimapInsertSubmap_IMPL(param_1 + 0x4980,0), lVar11 == 0)) {
      return 0x51;
    }
    plVar12 = (long *)multimapInsertItemNew_IMPL(param_1 + 0x4980,0,lVar10);
    if (plVar12 == (long *)0x0) {
      return 0x1f;
    }
    *(undefined4 *)(plVar12 + 2) = uVar4;
    *plVar12 = lVar10;
    *(undefined4 *)(plVar12 + 1) = uVar3;
    *(undefined4 *)((long)plVar12 + 0xc) = param_4;
    plVar12[3] = *(long *)(lVar9 + 0x248);
    *(short *)(param_1 + 0x49b4) = *(short *)(param_1 + 0x49b4) + 1;
    local_5c = registerEventNotification
                         (lVar10 + 0x160,param_2,param_4,uVar4,0x10000008,0x7f,
                          *(undefined8 *)(lVar10 + 0x1a8),0);
    if (local_5c != 0) {
LAB_003872cb:
      gspTraceRemoveBindpoint(param_1,0,plVar12);
      return (ulong)local_5c;
    }
    local_50 = 0;
    local_40 = 0;
    local_44 = param_7;
    local_58 = param_5;
    local_48 = param_6;
    if (*(char *)(param_1 + 0x908) != '\0') {
      iVar1 = param_6 * 0x20 + 0x30;
      local_5c = memdescCreate(plVar12 + 5,param_1,iVar1,0,1,2);
      if (local_5c != 0) {
        nvAssertOkFailedNoLog
                  (local_5c,
                   "memdescCreate(&(pBind->pMemDesc), pGpu, allocBufferSize, 0, NV_TRUE, ADDR_FBMEM, NV_MEMORY_UNCACHED, MEMDESC_FLAGS_NONE)"
                   ,"src/kernel/gpu/gsp/kernel_gsp_trace_rats.c",0x107);
        goto LAB_003872cb;
      }
      memdescAlloc(plVar12[5]);
      lVar9 = memdescMapInternal(param_1,plVar12[5],0);
      plVar12[4] = lVar9;
      local_50 = *(undefined8 *)(plVar12[5] + 0x170);
      portMemSet(lVar9,0,iVar1);
    }
    uVar8 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,uVar5,uVar6,0x208001e3,&local_58,0x20);
    if (uVar8 != 0) {
      gspTraceRemoveBindpoint(param_1,0,plVar12);
      return (ulong)uVar8;
    }
    *(undefined1 *)(param_1 + 0x49b6) = 1;
    uVar13 = osSchedule1HzCallback(param_1,gspTraceNotifyAllConsumers,0,1);
    if ((int)uVar13 == 0) {
      return uVar13;
    }
    gspTraceRemoveBindpoint(param_1,0,plVar12);
    osRemove1HzCallback(param_1,gspTraceNotifyAllConsumers,0);
  }
  return 0x1a;
}


// ===== 003873b0 gspTraceRemoveAllBindpoints =====

void gspTraceRemoveAllBindpoints(undefined8 param_1)

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
    uVar3 = mapFindLEQ_IMPL(lVar2 + 0x4980,0xffffffffffffffff);
    uVar4 = mapFindGEQ_IMPL(lVar2 + 0x4980,0);
    mapIterRange_IMPL(&local_78,lVar2 + 0x4980,uVar4,uVar3);
    local_48 = local_78;
    local_40 = local_70;
    local_38 = local_68;
    local_30 = local_60;
    while( true ) {
      cVar1 = mapIterNext_IMPL(&local_48);
      if (cVar1 == '\0') break;
      uVar3 = mapKey_IMPL(local_40,local_48);
      while( true ) {
        lVar5 = multimapFindItem_IMPL(lVar2 + 0x4980,uVar3,param_1);
        if (lVar5 == 0) break;
        gspTraceRemoveBindpoint(lVar2,uVar3,lVar5);
      }
    }
  }
  return;
}


// ===== 003874e0 GspStatusQueueInit =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int GspStatusQueueInit(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  int iStack_64;
  undefined1 local_50 [32];
  
  lVar1 = *(long *)(param_1 + 0x1ba8);
  if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
    iStack_64 = 1;
    uVar6 = 4000000;
  }
  else {
    iStack_64 = 5;
    uVar6 = 0xffffffff;
  }
  timeoutSet(param_1 + 0x1af0,local_50,uVar6,iStack_64);
  do {
    LOCK();
    UNLOCK();
    lVar2 = *param_2;
    iVar5 = msgqRxLink(*(undefined8 *)(lVar2 + 0x60),*(undefined8 *)(lVar2 + 0x38),
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x18));
    if (iVar5 == 0) {
      nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x16a,"GspStatusQueueInit",1,
                   "NVRM: Status queue linked to command queue.\n");
      if (iStack_64 != 1) {
        threadStateResetTimeout(param_1);
      }
      return 0;
    }
    osSpinLoop();
    iVar4 = timeoutCheck(param_1 + 0x1af0,local_50,0x179);
    if (iVar4 != 0) goto LAB_003875f6;
    kgspDumpGspLogs_IMPL(lVar1,0);
    cVar3 = (**(code **)(lVar1 + 0x898))(param_1,lVar1);
  } while (cVar3 != '\0');
  iVar4 = 0x62;
LAB_003875f6:
  if (iVar5 < 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x187,"GspStatusQueueInit",4,
                 "NVRM: msgqRxLink failed: %d, nvStatus 0x%08x, retries: %d\n",iVar5,iVar4);
    lVar1 = *param_2;
    if (lVar1 != 0) {
      portMemFree(*(undefined8 *)(lVar1 + 0x48));
      *(undefined8 *)(lVar1 + 0x48) = 0;
      *(undefined8 *)(lVar1 + 0x50) = 0;
      *(undefined8 *)(lVar1 + 0x58) = 0;
    }
  }
  return iVar4;
}


// ===== 00387690 GspMsgQueuesCleanup =====

void GspMsgQueuesCleanup(long *param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_1 != (long *)0x0) {
    lVar1 = *param_1;
    if (lVar1 != 0) {
      portMemFree(*(undefined8 *)(lVar1 + 0x68));
      *(undefined8 *)(lVar1 + 0x68) = 0;
      *(undefined8 *)(lVar1 + 0x70) = 0;
      *(undefined8 *)(lVar1 + 0x78) = 0;
      if (*(long *)(lVar1 + 0x10) != 0) {
        lVar2 = memdescGetKernelMapping();
        uVar3 = memdescGetKernelMappingPriv(*(undefined8 *)(lVar1 + 0x10));
        if (lVar2 != 0) {
          memdescUnmap(*(undefined8 *)(lVar1 + 0x10),1,lVar2,uVar3);
        }
        memdescFree(*(undefined8 *)(lVar1 + 0x10));
        memdescDestroy(*(undefined8 *)(lVar1 + 0x10));
        *(undefined8 *)(lVar1 + 0x10) = 0;
      }
      portMemFree(lVar1);
      *param_1 = 0;
    }
    return;
  }
  return;
}


// ===== 00387750 GspMsgQueuesInit =====

int GspMsgQueuesInit(long param_1,long *param_2)

{
  undefined4 uVar1;
  ulong *puVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong *local_50;
  ulong *local_48;
  uint local_40;
  undefined4 uStack_3c;
  
  if (*param_2 != 0) {
    nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0xd2,"GspMsgQueuesInit",4,
                 "NVRM: GSP message queue was already initialized.\n");
    return 0x40;
  }
  puVar4 = (ulong *)portMemAllocNonPaged(0xa0);
  local_50 = puVar4;
  if (puVar4 == (ulong *)0x0) {
    nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0xd9,"GspMsgQueuesInit",4,
                 "NVRM: Error allocating queue info area.\n");
    return 0x51;
  }
  portMemSet(puVar4,0,0xa0);
  puVar4[6] = 0x30;
  puVar4[9] = 0xc00000004;
  uVar5 = 0x180000;
  puVar4[7] = 0x1000;
  puVar4[8] = 0x10000;
  if (*(char *)(param_1 + 0x446) == '\0') {
    uVar5 = (-(ulong)(*(char *)(param_1 + 0x490e) == '\0') & 0xffffffffffec0000) + 0x180000;
  }
  puVar4[4] = uVar5;
  iVar3 = osReadRegistryDword(param_1,"RmGspStatusQueueSize",&local_40);
  uVar5 = 0x40000;
  if (iVar3 == 0) {
    local_40 = local_40 << 10;
    if ((ulong)local_40 < puVar4[8]) {
      local_40 = (uint)puVar4[8];
    }
    local_40 = local_40 + 0xfff & 0xfffff000;
    uVar5 = (ulong)local_40;
  }
  puVar4[5] = uVar5;
  uVar5 = uVar5 + puVar4[4];
  *(undefined1 *)(puVar4 + 0x13) = 0;
  uVar6 = uVar5;
  if ((uVar5 & 0xfff) != 0) {
    nvAssertFailedNoLog("(queueSize & RM_PAGE_MASK) == 0","src/kernel/gpu/gsp/message_queue_cpu.c",
                        0x70);
    uVar6 = puVar4[5] + puVar4[4];
  }
  uVar5 = (ulong)(uint)((int)(uVar5 >> 0xc) + (int)((uVar5 >> 0xc & 0xffffffff) * 8 + 0xfff >> 0xc))
  ;
  *puVar4 = uVar5;
  uVar5 = uVar5 * 8 + 0xfff & 0xfffffffffffff000;
  puVar4[1] = uVar5;
  lVar7 = uVar5 + uVar6;
  iVar3 = memdescCreate(puVar4 + 2,param_1,lVar7,0x1000,0,1,0,0x200000000000);
  if (iVar3 == 0) {
    memdescSetFlag(puVar4[2],0x200,1);
    memdescSetPageSize(puVar4[2],1,0x200000);
    *(undefined4 *)(puVar4[2] + 0x9c) = 0x5b;
    iVar3 = memdescAlloc(puVar4[2]);
    if (iVar3 == 0x51) {
      nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0xfb,"GspMsgQueuesInit",4,
                   "NVRM: Allocation failed with big page size, retrying with default page size\n");
      memdescSetPageSize(puVar4[2],1,0x1000);
      *(undefined4 *)(puVar4[2] + 0x9c) = 0x5b;
      iVar3 = memdescAlloc(puVar4[2]);
    }
    if (iVar3 == 0) {
      iVar3 = memdescMap(puVar4[2],0,lVar7,1,2,&local_48,&local_40);
      if (iVar3 == 0) {
        memdescSetKernelMapping(puVar4[2],local_48);
        memdescSetKernelMappingPriv(puVar4[2],CONCAT44(uStack_3c,local_40));
        if (local_48 == (ulong *)0x0) {
          iVar3 = 0x51;
          nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x10f,"GspMsgQueuesInit",4,
                       "NVRM: Error allocating message queue shared buffer\n");
        }
        else {
          portMemSet(local_48,0,lVar7);
          puVar2 = local_48;
          memdescGetPhysAddrs(puVar4[2],1,0,0x1000,*puVar4,local_48);
          puVar4[10] = puVar4[1] + (long)local_48;
          uVar5 = puVar4[1] + (long)local_48 + puVar4[4];
          puVar4[0xb] = uVar5;
          if ((long)local_48 + lVar7 != uVar5 + puVar4[5]) {
            nvAssertFailedNoLog("NvP64_PLUS_OFFSET(pVaKernel, sharedBufSize) == NvP64_PLUS_OFFSET(lastQueueVa, lastQueueSize)"
                                ,"src/kernel/gpu/gsp/message_queue_cpu.c",0x131);
          }
          uVar1 = *(undefined4 *)((long)puVar4 + 0x4c);
          uVar5 = puVar4[8];
          iVar3 = msgqGetMetaSize();
          iVar3 = (1 << ((byte)uVar1 & 0x1f)) + (int)uVar5 + iVar3;
          uVar5 = portMemAllocNonPaged(iVar3);
          puVar4[0xd] = uVar5;
          if (uVar5 == 0) {
            iVar3 = 0x51;
            nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x8e,"_gspMsgQueueInit",4,
                         "NVRM: Error allocating pWorkArea.\n");
          }
          else {
            portMemSet(uVar5,0,iVar3);
            iVar3 = 1 << ((byte)*(undefined4 *)((long)puVar4 + 0x4c) & 0x1f);
            uVar5 = (long)(iVar3 + -1) + puVar4[0xd] & -(long)iVar3;
            puVar4[0xe] = uVar5;
            puVar4[0xf] = uVar5 + puVar4[8];
            iVar3 = msgqInit(puVar4 + 0x10);
            if (iVar3 < 0) {
              nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x9b,"_gspMsgQueueInit",4,
                           "NVRM: msgqInit failed: %d\n",iVar3);
            }
            else {
              iVar3 = msgqTxCreate(puVar4[0x10],puVar4[10],puVar4[4],puVar4[7],(int)puVar4[9],
                                   *(undefined4 *)((long)puVar4 + 0x4c),1);
              if (-1 < iVar3) {
                puVar4[0xc] = puVar4[0xe] + 0x30;
                nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0xb0,"_gspMsgQueueInit",1,
                             "NVRM: Created command queue.\n");
                *(undefined4 *)((long)puVar4 + 0x94) = 0;
                *param_2 = (long)puVar4;
                puVar4[3] = *puVar2;
                return 0;
              }
              nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0xa9,"_gspMsgQueueInit",4,
                           "NVRM: msgqTxCreate failed: %d\n",iVar3);
            }
            iVar3 = 0xffff;
            portMemFree(puVar4[0xd]);
            puVar4[0xd] = 0;
            puVar4[0xe] = 0;
            puVar4[0xf] = 0;
          }
          nvAssertOkFailedNoLog
                    (iVar3,"_gspMsgQueueInit(pRmQueueInfo)","src/kernel/gpu/gsp/message_queue_cpu.c"
                     ,0x134);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "memdescMap(pMQCollection->pSharedMemDesc, 0, sharedBufSize, NV_TRUE, NV_PROTECT_WRITEABLE, &pVaKernel, &pPrivKernel)"
                   ,"src/kernel/gpu/gsp/message_queue_cpu.c",0x104);
      }
    }
    else {
      nvAssertOkFailedNoLog(iVar3,"nvStatus","src/kernel/gpu/gsp/message_queue_cpu.c",0x101);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar3,
               "memdescCreate(&pMQCollection->pSharedMemDesc, pGpu, sharedBufSize, RM_PAGE_SIZE, NV_MEMORY_NONCONTIGUOUS, ADDR_SYSMEM, NV_MEMORY_CACHED, flags)"
               ,"src/kernel/gpu/gsp/message_queue_cpu.c",0xec);
  }
  GspMsgQueuesCleanup(&local_50);
  return iVar3;
}


// ===== 00387d90 GspMsgQueueSendCommand =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int GspMsgQueueSendCommand(long param_1,long param_2)

{
  ulong *puVar1;
  ulong uVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  ulong *puVar7;
  ulong *puVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  int iVar12;
  ulong *puVar13;
  undefined8 in_stack_ffffffffffffffa8;
  undefined1 local_50 [32];
  
  puVar1 = *(ulong **)(param_1 + 0x50);
  uVar5 = *(int *)(param_1 + 0x10) + (int)puVar1[7];
  if ((uVar5 < 0x50) || (uVar11 = (ulong)uVar5, *(ulong *)(param_1 + 0x20) < uVar11)) {
    nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x1dc,"GspMsgQueueSendCommand",4,
                 "NVRM: Incorrect message length %u\n");
    return 0x3a;
  }
  if ((uVar5 & 7) != 0) {
    portMemSet((long)puVar1 + uVar11,0,8 - (uVar5 & 7));
  }
  *(undefined4 *)((long)puVar1 + 0x24) = *(undefined4 *)(param_1 + 0x68);
  uVar2 = *(ulong *)(param_1 + 0x18);
  *(undefined4 *)(puVar1 + 4) = 0;
  *(int *)(puVar1 + 5) = (int)(((uVar11 - 1) + uVar2) / uVar2);
  cVar4 = gpuIsCCFeatureEnabled_IMPL(param_2);
  if (cVar4 != '\0') {
    lVar3 = *(long *)(param_2 + 0x1d18);
    portMemCopy(puVar1 + 2,0x10,(undefined4 *)((long)puVar1 + 0x24),4);
    lVar9 = (long)puVar1 + *(long *)(param_1 + 0x10);
    iVar6 = ccslEncryptWithRotationChecks_KERNEL
                      (*(undefined8 *)(lVar3 + 0x2c0),
                       (int)puVar1[5] * *(int *)(param_1 + 0x18) - (int)*(long *)(param_1 + 0x10),
                       lVar9,puVar1 + 2,0x10,lVar9,puVar1);
    if (iVar6 != 0) {
      nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x1fd,"GspMsgQueueSendCommand",4,
                   "NVRM: Encryption failed with status = 0x%x.\n",iVar6);
      if (iVar6 != 0x1a) {
        return iVar6;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x201,"GspMsgQueueSendCommand",4,
                   "NVRM: Fatal error detected in RPC encrypt: IV overflow!\n");
      (**(code **)(lVar3 + 0x180))(param_2,lVar3);
      return 0x1a;
    }
    iVar6 = (int)puVar1[5];
    puVar13 = (ulong *)((ulong)(uint)(iVar6 * *(int *)(param_1 + 0x18)) + (long)puVar1);
    uVar5 = 0;
    if (puVar1 < puVar13) {
      uVar11 = *puVar1;
      if (puVar1 + 1 < puVar13) {
        puVar7 = puVar1 + 1;
        if ((~(ulong)puVar1 + (long)puVar13 >> 3 & 1) != 0) {
          puVar7 = puVar1 + 2;
          uVar11 = uVar11 ^ puVar1[1];
          if (puVar13 <= puVar7) goto LAB_00388000;
        }
        do {
          puVar8 = puVar7 + 2;
          uVar11 = uVar11 ^ *puVar7 ^ puVar7[1];
          puVar7 = puVar8;
        } while (puVar8 < puVar13);
      }
LAB_00388000:
      uVar5 = (uint)(uVar11 >> 0x20) ^ (uint)uVar11;
    }
    *(uint *)(puVar1 + 4) = uVar5;
    goto LAB_00387e71;
  }
  puVar13 = (ulong *)((long)puVar1 + uVar11);
  if (puVar1 < puVar13) {
    uVar11 = *puVar1;
    if (puVar1 + 1 < puVar13) {
      puVar7 = puVar1 + 1;
      if ((~(ulong)puVar1 + (long)puVar13 >> 3 & 1) != 0) {
        uVar11 = uVar11 ^ puVar1[1];
        puVar7 = puVar1 + 2;
        if (puVar13 <= puVar1 + 2) goto LAB_00387e60;
      }
      do {
        puVar8 = puVar7 + 2;
        uVar11 = uVar11 ^ *puVar7 ^ puVar7[1];
        puVar7 = puVar8;
      } while (puVar8 < puVar13);
    }
LAB_00387e60:
    uVar5 = (uint)(uVar11 >> 0x20) ^ (uint)uVar11;
  }
  else {
    uVar5 = 0;
  }
  *(uint *)(puVar1 + 4) = uVar5;
  iVar6 = (int)puVar1[5];
LAB_00387e71:
  if (*(char *)(param_1 + 0x78) != '\0') {
    *(undefined4 *)puVar1 = 0xffffffff;
  }
  uVar5 = 0;
  puVar13 = puVar1;
  if (iVar6 != 0) {
    do {
      timeoutSet(param_2 + 0x1af0,local_50,1000000,(ulong)(*(int *)(param_1 + 0x70) != 0) << 6);
      while (lVar9 = msgqTxGetWriteBuffer(*(undefined8 *)(param_1 + 0x60),uVar5), lVar9 == 0) {
        iVar6 = timeoutCheck(param_2 + 0x1af0,local_50,0x228);
        if (iVar6 != 0) {
          iVar6 = *(int *)(param_1 + 0x70) + 1;
          *(int *)(param_1 + 0x70) = iVar6;
          if (iVar6 == 1) {
            uVar10 = 4;
          }
          else {
            uVar10 = 1;
          }
          nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x233,"GspMsgQueueSendCommand",
                       uVar10,"NVRM: buffer is full (waiting for %d free elements, got %d)\n",
                       (int)puVar1[5],uVar5);
          return 3;
        }
        LOCK();
        UNLOCK();
        osSpinLoop();
      }
      uVar5 = uVar5 + 1;
      *(undefined4 *)(param_1 + 0x70) = 0;
      portMemCopy(lVar9,*(undefined8 *)(param_1 + 0x18),puVar13,*(undefined8 *)(param_1 + 0x18));
      puVar13 = (ulong *)((long)puVar13 + *(long *)(param_1 + 0x18));
    } while (uVar5 < (uint)puVar1[5]);
  }
  LOCK();
  UNLOCK();
  iVar6 = msgqTxSubmitBuffers(*(undefined8 *)(param_1 + 0x60),(int)puVar1[5]);
  if (iVar6 == 0) {
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
    iVar12 = 0;
  }
  else {
    iVar12 = 0x40;
    nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x251,"GspMsgQueueSendCommand",4,
                 "NVRM: msgqTxSubmitBuffers failed: %d\n",iVar6,in_stack_ffffffffffffffa8);
  }
  return iVar12;
}


// ===== 003881c0 GspMsgQueueReceiveStatus =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int GspMsgQueueReceiveStatus(long param_1,long param_2)

{
  ulong *puVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong uVar10;
  long extraout_RDX;
  long extraout_RDX_00;
  long extraout_RDX_01;
  long lVar11;
  ulong *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_48;
  uint local_44;
  
  uVar4 = 0;
  local_48 = 0xffffffff;
  local_44 = 3;
  do {
    lVar11 = *(long *)(param_1 + 0x50);
    uVar13 = 1;
    uVar14 = 0;
    do {
      lVar7 = msgqRxGetReadBuffer(*(undefined8 *)(param_1 + 0x60),uVar14);
      if (lVar7 == 0) {
        if (uVar14 == 0) {
          return 0x10006;
        }
        iVar6 = 0x55;
        nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x28d,"GspMsgQueueReceiveStatus",4,
                     "NVRM: Incomplete read.\n");
        goto LAB_00388519;
      }
      portMemCopy(lVar11,*(undefined8 *)(param_1 + 0x18),lVar7,*(undefined8 *)(param_1 + 0x18));
      lVar11 = lVar11 + *(long *)(param_1 + 0x18);
      if (uVar14 == 0) {
        uVar13 = *(uint *)(*(long *)(param_1 + 0x50) + 0x28);
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < uVar13);
    cVar3 = gpuIsCCFeatureEnabled_IMPL(param_2);
    puVar1 = *(ulong **)(param_1 + 0x50);
    if (cVar3 == '\0') {
      puVar12 = (ulong *)((ulong)(uint)((int)puVar1[7] + *(int *)(param_1 + 0x10)) + (long)puVar1);
      if (puVar1 < puVar12) {
        uVar10 = *puVar1;
        if (puVar1 + 1 < puVar12) {
          puVar9 = puVar1 + 1;
          if ((~(ulong)puVar1 + (long)puVar12 >> 3 & 1) != 0) {
            puVar9 = puVar1 + 2;
            uVar10 = uVar10 ^ puVar1[1];
            if (puVar12 <= puVar9) goto LAB_003882b0;
          }
          do {
            uVar10 = uVar10 ^ *puVar9 ^ puVar9[1];
            if (puVar12 <= puVar9 + 2) break;
            puVar8 = puVar9 + 4;
            uVar10 = uVar10 ^ puVar9[2] ^ puVar9[3];
            puVar9 = puVar8;
          } while (puVar8 < puVar12);
        }
        goto LAB_003882b0;
      }
LAB_003882c1:
      if (*(int *)((long)puVar1 + 0x24) == *(int *)(param_1 + 0x6c)) {
        if (uVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x2e4,"GspMsgQueueReceiveStatus",4,
                       "NVRM: Read succeeded with %d retries.\n",uVar4);
        }
        cVar3 = gpuIsCCFeatureEnabled_IMPL(param_2);
        lVar11 = extraout_RDX;
        if (cVar3 != '\0') {
          lVar11 = *(long *)(param_1 + 0x50);
          lVar2 = *(long *)(param_2 + 0x1d18);
          lVar7 = lVar11 + *(long *)(param_1 + 0x10);
          iVar6 = ccslDecryptWithRotationChecks_KERNEL
                            (*(undefined8 *)(lVar2 + 0x2c0),
                             *(int *)(param_1 + 0x18) * uVar13 - (int)*(long *)(param_1 + 0x10),
                             lVar7,0,lVar11 + 0x10,0x10,lVar7);
          if (iVar6 != 0) {
            nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x2fc,"GspMsgQueueReceiveStatus",4
                         ,"NVRM: Fatal error detected in RPC decrypt: 0x%x!\n",iVar6);
            (**(code **)(lVar2 + 0x180))(param_2,lVar2);
            return iVar6;
          }
        }
        uVar4 = *(int *)(*(long *)(param_1 + 0x50) + 0x38) + *(int *)(param_1 + 0x10);
        if ((uVar4 < 0x50) || (iVar6 = 0, *(ulong *)(param_1 + 0x20) < (ulong)uVar4)) {
          iVar6 = 0x3a;
          nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x30a,"GspMsgQueueReceiveStatus",4,
                       "NVRM: Incorrect message length %u\n");
          lVar11 = extraout_RDX_00;
        }
        goto LAB_00388353;
      }
      nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x2c2,"GspMsgQueueReceiveStatus",4,
                   "NVRM: Bad sequence number.  Expected %u got %u. Possible memory corruption.\n",
                   *(int *)(param_1 + 0x6c),*(int *)((long)puVar1 + 0x24));
      uVar14 = *(uint *)(*(long *)(param_1 + 0x50) + 0x24);
      if ((uVar14 < *(uint *)(param_1 + 0x6c)) && (*(uint *)(param_1 + 0x6c) - uVar14 < local_48)) {
        nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x2cb,"GspMsgQueueReceiveStatus",4,
                     "NVRM: Attempting recovery: ignoring old package with seqNum=%u of %u elements.\n"
                     ,uVar14,uVar13);
        local_48 = *(int *)(param_1 + 0x6c) - *(int *)(*(long *)(param_1 + 0x50) + 0x24);
        iVar6 = msgqRxMarkConsumed(*(undefined8 *)(param_1 + 0x60),uVar13);
        if (iVar6 < 0) {
          nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x2d2,"GspMsgQueueReceiveStatus",4,
                       "NVRM: msgqRxMarkConsumed failed: %d\n",iVar6);
        }
        local_44 = local_44 + 1;
      }
    }
    else {
      puVar12 = (ulong *)((ulong)(uVar13 * *(int *)(param_1 + 0x18)) + (long)puVar1);
      if (puVar12 <= puVar1) goto LAB_003882c1;
      uVar10 = *puVar1;
      if (puVar1 + 1 < puVar12) {
        puVar9 = puVar1 + 1;
        if ((~(ulong)puVar1 + (long)puVar12 >> 3 & 1) != 0) {
          puVar9 = puVar1 + 2;
          uVar10 = uVar10 ^ puVar1[1];
          if (puVar12 <= puVar9) goto LAB_003882b0;
        }
        do {
          puVar8 = puVar9 + 2;
          uVar10 = uVar10 ^ *puVar9 ^ puVar9[1];
          puVar9 = puVar8;
        } while (puVar8 < puVar12);
      }
LAB_003882b0:
      if ((int)(uVar10 >> 0x20) == (int)uVar10) goto LAB_003882c1;
      nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x2ba,"GspMsgQueueReceiveStatus",4,
                   "NVRM: Bad checksum.\n");
    }
    iVar6 = 0x25;
LAB_00388519:
    uVar4 = uVar4 + 1;
    if (local_44 <= uVar4) {
      nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x2e8,"GspMsgQueueReceiveStatus",4,
                   "NVRM: Read failed after %d retries.\n",uVar4);
      lVar11 = extraout_RDX_01;
LAB_00388353:
      *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
      iVar5 = msgqRxMarkConsumed(*(undefined8 *)(param_1 + 0x60),uVar13,lVar11);
      if (iVar5 < 0) {
        iVar6 = 0xffff;
        nvDbg_Printf("src/kernel/gpu/gsp/message_queue_cpu.c",0x315,"GspMsgQueueReceiveStatus",4,
                     "NVRM: msgqRxMarkConsumed failed: %d\n",iVar5);
      }
      return iVar6;
    }
  } while( true );
}


// ===== 00388660 _kgspliteLogPollingCallback =====

void _kgspliteLogPollingCallback(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x168) == '\0') {
    return;
  }
  libosExtractLogs(param_2 + 0x170,0);
  return;
}


// ===== 00388680 kgspliteConstructEngine_IMPL =====

undefined8 kgspliteConstructEngine_IMPL(undefined8 param_1,long param_2,byte param_3)

{
  int iVar1;
  char *pcVar2;
  uint local_1c [3];
  
  *(uint *)(param_2 + 0x16c) = (uint)param_3;
  *(undefined1 *)(param_2 + 0x50) = 1;
  iVar1 = osReadRegistryDword(param_1,"RmGspliteEnableMask",local_1c);
  if (iVar1 == 0) {
    if ((local_1c[0] & 1 << ((byte)*(undefined4 *)(param_2 + 0x16c) & 0x1f)) == 0) {
      nvDbg_Printf("src/kernel/gpu/gsplite/kernel_gsplite.c",0x7f,"_kgspliteInitRegistryOverrides",1
                   ,"NVRM: KernelGsplite%d missing due to lack of regkey override.\n");
      *(undefined1 *)(param_2 + 0x50) = 1;
      pcVar2 = "disabled";
    }
    else {
      nvDbg_Printf("src/kernel/gpu/gsplite/kernel_gsplite.c",0x79,"_kgspliteInitRegistryOverrides",1
                   ,"NVRM: KernelGsplite%d enabled due to regkey override.\n");
      *(undefined1 *)(param_2 + 0x50) = 0;
      pcVar2 = "enabled";
    }
  }
  else {
    pcVar2 = "disabled";
    if (*(char *)(param_2 + 0x50) == '\0') {
      pcVar2 = "enabled";
    }
  }
  nvDbg_Printf("src/kernel/gpu/gsplite/kernel_gsplite.c",0x85,"_kgspliteInitRegistryOverrides",1,
               "NVRM: KernelGsplite%d: %s\n",*(undefined4 *)(param_2 + 0x16c),pcVar2);
  return 0;
}


// ===== 00388790 kgspliteFreeLibosLoggingStructures_IMPL =====

void kgspliteFreeLibosLoggingStructures_IMPL(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x168) != '\0') {
    libosExtractLogs(param_2 + 0x170,0);
  }
  libosLogDestroy(param_2 + 0x170);
  if (*(long *)(param_2 + 0x2378) != 0) {
    memdescUnmap(*(undefined8 *)(param_2 + 0x2370),1,*(long *)(param_2 + 0x2378),
                 *(undefined8 *)(param_2 + 0x2380));
    *(undefined8 *)(param_2 + 0x2378) = 0;
    *(undefined8 *)(param_2 + 0x2380) = 0;
  }
  if (*(long *)(param_2 + 0x2370) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(param_2 + 0x2370));
    *(undefined8 *)(param_2 + 0x2370) = 0;
  }
  if (*(long *)(param_2 + 0x2388) != 0) {
    portMemFree();
    *(undefined8 *)(param_2 + 0x2388) = 0;
  }
  return;
}


// ===== 00388860 kgspliteDestruct_IMPL =====

void kgspliteDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar1 = gpuEngineGetGpu(uVar1);
  if (*(char *)(param_1 + 0x168) == '\0') {
    return;
  }
  osRemove1HzCallback(uVar1,_kgspliteLogPollingCallback,param_1);
  kgspliteFreeLibosLoggingStructures_IMPL(uVar1,param_1);
  return;
}


// ===== 003888c0 kgspliteInitLibosLoggingStructures_IMPL =====

int kgspliteInitLibosLoggingStructures_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined8 extraout_RDX;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined8 local_30;
  
  local_38 = 0;
  local_30 = 0;
  if (*(long *)(param_2 + 0x2378) != 0) {
    nvAssertFailedNoLog("pKernelGsplite->pLogBuf == NULL","src/kernel/gpu/gsplite/kernel_gsplite.c",
                        0x9c);
    return 0x40;
  }
  *(undefined8 *)(param_2 + 0x2388) = 0;
  *(undefined4 *)(param_2 + 0x2368) = 0x10000;
  uVar3 = 0;
  uVar2 = 0;
  iVar1 = memdescCreate(param_2 + 0x2370,param_1,0x10000,0x1000,1,1);
  if (iVar1 == 0) {
    *(undefined4 *)(*(long *)(param_2 + 0x2370) + 0x9c) = 0xb4;
    iVar1 = memdescAlloc(*(undefined8 *)(param_2 + 0x2370),uVar3,extraout_RDX,uVar2);
    if (iVar1 == 0) {
      iVar1 = memdescMap(*(long *)(param_2 + 0x2370),0,
                         *(undefined8 *)(*(long *)(param_2 + 0x2370) + 0x30),1,3,&local_38,&local_30
                        );
      if (iVar1 == 0) {
        *(undefined8 *)(param_2 + 0x2378) = local_38;
        *(undefined8 *)(param_2 + 0x2380) = local_30;
        portMemSet(local_38,0,*(undefined4 *)(param_2 + 0x2368));
        libosLogCreateEx(param_2 + 0x170,&DAT_00d4074d);
        libosLogAddLogEx(param_2 + 0x170,*(undefined8 *)(param_2 + 0x2378),
                         *(undefined4 *)(param_2 + 0x2368),*(undefined4 *)(param_1 + 0x7a4),
                         *(uint *)(param_1 + 0x808) >> 4,*(undefined4 *)(param_1 + 0x80c),"UCODE",0,
                         0,0,2,0);
        libosLogInitEx(param_2 + 0x170,*(undefined8 *)(param_2 + 0x2388),0,1,1,0);
        return 0;
      }
      nvAssertOkFailedNoLog
                (iVar1,
                 "memdescMap(pKernelGsplite->pLogMemDesc, 0, memdescGetSize(pKernelGsplite->pLogMemDesc), NV_TRUE, NV_PROTECT_READ_WRITE, &pVa, &pPriv)"
                 ,"src/kernel/gpu/gsplite/kernel_gsplite.c",0xc0);
    }
    else {
      nvAssertOkFailedNoLog(iVar1,"status","src/kernel/gpu/gsplite/kernel_gsplite.c",0xbd);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,
               "memdescCreate(&pKernelGsplite->pLogMemDesc, pGpu, pKernelGsplite->logBufSize, RM_PAGE_SIZE, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, MEMDESC_FLAGS_NONE)"
               ,"src/kernel/gpu/gsplite/kernel_gsplite.c",0xb0);
  }
  kgspliteFreeLibosLoggingStructures_IMPL(param_1,param_2);
  return iVar1;
}


// ===== 00388b10 kgspliteStateInitUnlocked_IMPL =====

ulong kgspliteStateInitUnlocked_IMPL(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  if (*(char *)(param_2 + 0x168) == '\0') {
    return 0;
  }
  uVar1 = kgspliteInitLibosLoggingStructures_IMPL();
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,"kgspliteInitLibosLoggingStructures(pGpu, pKernelGsplite)",
             "src/kernel/gpu/gsplite/kernel_gsplite.c",0x43);
  return uVar1 & 0xffffffff;
}


// ===== 00388b60 kgspliteSendLibosLoggingStructuresInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kgspliteSendLibosLoggingStructuresInfo_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 local_30 [2];
  undefined8 local_28;
  undefined8 local_20;
  
  if (*(char *)(param_1 + 0x909) == '\0') {
    return 0;
  }
  local_20 = memdescGetPhysAddr(*(undefined8 *)(param_2 + 0x2370),1,0);
  local_30[0] = *(undefined4 *)(param_2 + 0x16c);
  local_28 = *(undefined8 *)(*(long *)(param_2 + 0x2370) + 0x30);
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800a89,local_30,0x18);
  if (iVar1 != 0x56) {
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/gsplite/kernel_gsplite.c",0x10d,
                   "kgspliteSendLibosLoggingStructuresInfo_IMPL",4,
                   "NVRM: Sending LibOS Log Buffer Info to CMC failed!\n");
      kgspliteFreeLibosLoggingStructures_IMPL(param_1,param_2);
    }
    return iVar1;
  }
  kgspliteFreeLibosLoggingStructures_IMPL(param_1,param_2);
  return 0;
}


// ===== 00388c60 kgspliteStateInitLocked_IMPL =====

ulong kgspliteStateInitLocked_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if ((*(char *)(param_2 + 0x168) == '\0') || (*(long *)(param_2 + 0x2370) == 0)) {
    return 0;
  }
  uVar1 = kgspliteSendLibosLoggingStructuresInfo_IMPL();
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,"kgspliteSendLibosLoggingStructuresInfo(pGpu, pKernelGsplite)",
               "src/kernel/gpu/gsplite/kernel_gsplite.c",0x52);
    return (ulong)uVar1;
  }
  uVar2 = osSchedule1HzCallback(param_1,_kgspliteLogPollingCallback,param_2,1);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,"_kgspliteStartLogPolling(pGpu, pKernelGsplite)",
             "src/kernel/gpu/gsplite/kernel_gsplite.c",0x54);
  return uVar2 & 0xffffffff;
}


// ===== 00388d02 _hfrpWriteByte.cold =====

void _hfrpWriteByte_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00388d20 _hfrpWriteByte =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _hfrpWriteByte(long param_1,uint param_2,byte param_3)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  
  lVar7 = (ulong)(param_2 >> 9) + 0x32;
  lVar1 = *(long *)(param_1 + 8 + lVar7 * 8);
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  uVar5 = (**(code **)(**(long **)(lVar1 + 0x50) + 0x28))();
  bVar4 = ((byte)param_2 & 3) * '\b';
  uVar6 = 0xffffffff >> ((bVar4 ^ 0x18) + bVar4 & 0x1f);
  lVar1 = *(long *)(param_1 + 8 + lVar7 * 8);
  if (lVar1 != 0) {
    plVar2 = *(long **)(lVar1 + 0x50);
    (**(code **)(*plVar2 + 0x40))
              (plVar2,param_2 & 0x1fc,~(uVar6 << bVar4) & uVar5 | (param_3 & uVar6) << bVar4);
    return;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 00388dc6 _hfrpWriteMailboxData.cold =====

void _hfrpWriteMailboxData_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00388de0 _hfrpWriteMailboxData =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _hfrpWriteMailboxData(long param_1,long param_2,byte param_3,uint param_4)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  ulong uVar4;
  byte bVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar16;
  uint uVar17;
  uint local_50;
  uint uVar15;
  
  uVar7 = (ulong)param_4;
  local_50 = *(uint *)(param_1 + 0x1b0);
  if ((param_4 < local_50) || (uVar17 = *(uint *)(param_1 + 0x1b4), uVar17 < param_4)) {
    local_50 = *(uint *)(param_1 + 0x1c0);
    uVar17 = *(uint *)(param_1 + 0x1c4);
  }
  uVar16 = (uint)param_3;
  if (param_3 == 0) {
    return uVar7;
  }
  uVar8 = 0;
LAB_00388e40:
  do {
    uVar15 = (uint)uVar7;
    uVar14 = uVar15 & 0x1fc;
    uVar4 = uVar7 >> 9;
    if ((((uVar7 & 3) == 0) && ((int)uVar8 + 4U <= uVar16)) && (uVar15 + 4 <= uVar17)) {
      uVar9 = 0;
    }
    else {
      lVar1 = *(long *)(param_1 + 0x198 + uVar4 * 8);
      if (lVar1 == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)invalidInstructionException();
        (*pcVar3)();
      }
      plVar2 = *(long **)(lVar1 + 0x50);
      uVar9 = (**(code **)(*plVar2 + 0x28))(plVar2,uVar14);
    }
    iVar6 = (uVar15 & 3) * 8;
    uVar12 = uVar8 + 1;
    do {
      uVar11 = uVar12;
      uVar10 = uVar7;
      bVar5 = (byte)iVar6;
      uVar13 = 0xffffffff >> ((-bVar5 - 8 & 0x18) + bVar5 & 0x1f);
      uVar9 = uVar9 & ~(uVar13 << (bVar5 & 0x1f)) |
              (uVar13 & *(byte *)(param_2 + -1 + uVar11)) << (bVar5 & 0x1f);
      uVar13 = (int)uVar10 + 1;
      uVar7 = (ulong)uVar13;
      if (uVar17 < uVar13) {
        uVar7 = (ulong)((local_50 + (int)uVar10) - uVar17);
        lVar1 = *(long *)(param_1 + 0x198 + uVar4 * 8);
        if (lVar1 == 0) {
          uVar7 = _hfrpWriteMailboxData_cold(uVar10,uVar11,uVar9);
          return uVar7;
        }
        plVar2 = *(long **)(lVar1 + 0x50);
        (**(code **)(*plVar2 + 0x40))(plVar2,uVar14);
        uVar8 = uVar11 & 0xffffffff;
        if (uVar16 <= (uint)uVar11) {
          return uVar7;
        }
        goto LAB_00388e40;
      }
      if (uVar16 <= (uint)uVar11) {
        lVar1 = *(long *)(param_1 + 0x198 + uVar4 * 8);
        if (lVar1 != 0) {
          (**(code **)(**(long **)(lVar1 + 0x50) + 0x40))();
          return uVar7;
        }
        uVar7 = _hfrpWriteMailboxData_cold(uVar10,uVar14,uVar9);
        return uVar7;
      }
      uVar12 = uVar11 + 1;
      iVar6 = iVar6 + 8;
    } while (uVar8 + 2 + (ulong)(3 - (uVar15 & 3)) != uVar12);
    lVar1 = *(long *)(param_1 + 0x198 + uVar4 * 8);
    if (lVar1 == 0) {
      uVar7 = _hfrpWriteMailboxData_cold(uVar10,uVar12,uVar9);
      return uVar7;
    }
    plVar2 = *(long **)(lVar1 + 0x50);
    (**(code **)(*plVar2 + 0x40))(plVar2,uVar14);
    uVar8 = uVar11 & 0xffffffff;
  } while( true );
}


// ===== 0038901b _hfrpReadMailboxData.cold =====

void _hfrpReadMailboxData_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00389030 _hfrpReadMailboxData =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong _hfrpReadMailboxData(long param_1,long param_2,uint param_3,uint param_4)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  undefined4 local_44;
  
  uVar10 = (ulong)param_4;
  local_44 = *(uint *)(param_1 + 0x1b0);
  if ((param_4 < local_44) || (uVar11 = *(uint *)(param_1 + 0x1b4), uVar11 < param_4)) {
    local_44 = *(uint *)(param_1 + 0x1c0);
    uVar11 = *(uint *)(param_1 + 0x1c4);
  }
  uVar5 = 0;
joined_r0x00389083:
  if ((param_3 & 0xff) <= uVar5) {
    return uVar10;
  }
  do {
    lVar1 = *(long *)(param_1 + 0x198 + (uVar10 >> 9) * 8);
    if (lVar1 == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    plVar2 = *(long **)(lVar1 + 0x50);
    uVar4 = (**(code **)(*plVar2 + 0x28))(plVar2,(uint)uVar10 & 0x1fc);
    uVar6 = (ulong)(uVar5 + 1);
    iVar7 = ((uint)uVar10 & 3) << 3;
    do {
      iVar8 = (int)uVar10;
      uVar9 = iVar8 + 1;
      uVar10 = (ulong)uVar9;
      uVar5 = (uint)uVar6;
      *(char *)(param_2 + -1 + uVar6) = (char)(uVar4 >> ((byte)iVar7 & 0x1f));
      if (uVar11 < uVar9) {
        uVar10 = (ulong)((iVar8 + local_44) - uVar11);
        goto joined_r0x00389083;
      }
      if ((param_3 & 0xff) <= uVar5) goto joined_r0x00389083;
      iVar7 = iVar7 + 8;
      uVar6 = uVar6 + 1;
    } while (iVar7 != 0x20);
  } while( true );
}


// ===== 0038912e khfrpMailboxDequeueMessage_IMPL.cold =====

void khfrpMailboxDequeueMessage_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00389150 khfrpMailboxDequeueMessage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
khfrpMailboxDequeueMessage_IMPL
          (long param_1,uint *param_2,undefined8 param_3,uint *param_4,int param_5)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  code *pcVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  
  if (param_5 == 0) {
    iVar13 = *(int *)(param_1 + 0x1b0);
    uVar14 = *(uint *)(param_1 + 0x1b4);
    uVar7 = *(uint *)(param_1 + 0x1a8);
    uVar12 = *(uint *)(param_1 + 0x1ac);
  }
  else {
    iVar13 = *(int *)(param_1 + 0x1c0);
    uVar14 = *(uint *)(param_1 + 0x1c4);
    uVar7 = *(uint *)(param_1 + 0x1b8);
    uVar12 = *(uint *)(param_1 + 0x1bc);
  }
  lVar1 = *(long *)(param_1 + 0x198 + (ulong)(uVar7 >> 9) * 8);
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar2 = *(long **)(lVar1 + 0x50);
  uVar6 = (**(code **)(*plVar2 + 0x28))(plVar2,uVar7 & 0x1fc);
  uVar6 = uVar6 >> (sbyte)((uVar7 & 3) << 3);
  lVar1 = *(long *)(param_1 + 0x198 + (ulong)(uVar12 >> 9) * 8);
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar2 = *(long **)(lVar1 + 0x50);
  uVar7 = (**(code **)(*plVar2 + 0x28))(plVar2,uVar12 & 0x1fc);
  uVar9 = (uVar14 + 1) - iVar13;
  uVar10 = uVar6 & 0xff;
  uVar7 = uVar7 >> (sbyte)((uVar12 & 3) << 3);
  uVar11 = uVar7 & 0xff;
  if ((uVar11 < uVar9) && (uVar10 < uVar9)) {
    if ((char)uVar7 == (char)uVar6) {
      nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0xc5,"khfrpMailboxDequeueMessage_IMPL",1,
                   "NVRM: Buffer empty: head (%u) == tail (%u)\n",uVar10,uVar11);
      return 0x89;
    }
    iVar8 = _hfrpReadMailboxData(param_1,param_2,4,uVar11 + iVar13);
    uVar3 = (ulong)((uVar9 + uVar10) - uVar11) % (ulong)uVar9;
    uVar7 = *param_2 & 0xff;
    if (uVar7 <= (uint)uVar3) {
      uVar7 = *param_2 - 4;
      uVar6 = uVar7 & 0xff;
      if ((byte)uVar7 < 0x33) {
        uVar15 = 0;
        cVar5 = _hfrpReadMailboxData(param_1,param_3,uVar6);
      }
      else {
        uVar7 = iVar8 + uVar6;
        uVar15 = 0x1a;
        if (uVar14 < uVar7) {
          uVar7 = ((iVar13 + -1) - uVar14) + uVar7;
        }
        cVar5 = (char)uVar7;
        nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0xdf,"khfrpMailboxDequeueMessage_IMPL",4,
                     "NVRM: payload size (%u) > Maximum allowed payload size (%u)\n",uVar6,0x32);
      }
      *param_4 = uVar6;
      _hfrpWriteByte(param_1,uVar12,cVar5 - (char)iVar13);
      return uVar15;
    }
    nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0xd2,"khfrpMailboxDequeueMessage_IMPL",4,
                 "NVRM: Invalid state: buffer size used (%u) < message size (%u)\n",uVar3,uVar7);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0xbe,"khfrpMailboxDequeueMessage_IMPL",4,
                 "NVRM: Invalid state: head (%u) or tail (%u) pointer is out of range\n",uVar10,
                 uVar11);
  }
  return 0x40;
}


// ===== 00389420 khfrpProcessResponse_IMPL =====

undefined8 khfrpProcessResponse_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  int *piVar3;
  long lVar4;
  uint *puVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  uint local_54;
  uint local_50;
  undefined1 local_4a [50];
  
  while( true ) {
    do {
      uVar7 = khfrpMailboxDequeueMessage_IMPL(param_1,&local_54,local_4a,&local_50,1);
      iVar6 = (int)uVar7;
      if (iVar6 == 0x89) {
        return 0;
      }
      if (iVar6 == 0x40) {
        return uVar7;
      }
      uVar9 = local_54 >> 8 & 0x3ff;
    } while (uVar9 == 0x3ff);
    uVar10 = 1 << ((byte)(local_54 >> 8) & 0x1f);
    lVar1 = param_1 + (ulong)(uVar9 >> 5) * 4;
    if ((*(uint *)(lVar1 + 0x1d8) & uVar10) == 0) {
      nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x124,"khfrpProcessResponse_IMPL",4,
                   "NVRM: Invalid state: sequence id (%u) is not allocated for any command\n");
      return 0x40;
    }
    lVar2 = param_1 + (ulong)uVar9 * 8;
    if (*(ushort **)(lVar2 + 0x2258) == (ushort *)0x0) break;
    piVar3 = *(int **)(lVar2 + 0x6258);
    lVar4 = *(long *)(lVar2 + 600);
    puVar5 = *(uint **)(lVar2 + 0x4258);
    **(ushort **)(lVar2 + 0x2258) = (ushort)(local_54 >> 0x12) & 0x3ff;
    if (piVar3 == (int *)0x0) {
      nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x13a,"khfrpProcessResponse_IMPL",4,
                   "NVRM: Invalid state: status pointer is not allocated\n");
      return 0x40;
    }
    *piVar3 = iVar6;
    if (puVar5 == (uint *)0x0) {
      nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x14d,"khfrpProcessResponse_IMPL",4,
                   "NVRM: Invalid state: response payload size pointer is not allocated\n");
      return 0x40;
    }
    uVar9 = *puVar5;
    *puVar5 = local_50;
    if (uVar9 < local_50) {
      nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x145,"khfrpProcessResponse_IMPL",4,
                   "NVRM: Invalid state: response size (%u) > client payload size (%u)\n",
                   (ulong)local_50,uVar9);
    }
    else if (((lVar4 != 0) && (iVar6 == 0)) && (local_50 != 0)) {
      uVar8 = 0;
      do {
        *(undefined1 *)(lVar4 + uVar8) = local_4a[uVar8];
        uVar8 = uVar8 + 1;
      } while (local_50 != uVar8);
    }
    *(undefined8 *)(lVar2 + 600) = 0;
    *(undefined8 *)(lVar2 + 0x2258) = 0;
    *(undefined8 *)(lVar2 + 0x4258) = 0;
    *(undefined8 *)(lVar2 + 0x6258) = 0;
    puVar5 = (uint *)(lVar1 + 0x1d8);
    *puVar5 = *puVar5 & ~uVar10;
  }
  nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x130,"khfrpProcessResponse_IMPL",4,
               "NVRM: Invalid state: response status pointer is not allocated\n");
  return 0x40;
}


// ===== 00389690 __pfx_khfrpConstructEngine_IMPL =====

undefined8 __pfx_khfrpConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int aiStack_1c [3];
  
  iVar1 = osReadRegistryDword(param_1,"RmEnableDStateHfrp",aiStack_1c);
  if (iVar1 != 0 || aiStack_1c[0] != 0) {
    iVar1 = osReadRegistryDword(param_1,"RmEnableHdaDStateHfrp",aiStack_1c);
    if (iVar1 == 0 && aiStack_1c[0] == 0) {
      *(undefined1 *)(param_2 + 0x169) = 0;
    }
    *(undefined8 *)(param_2 + 0x1a8) = 0x31100000110;
    *(undefined8 *)(param_2 + 0x1b0) = 0x1ff00000114;
    *(undefined8 *)(param_2 + 0x1b8) = 0x11100000310;
    *(undefined8 *)(param_2 + 0x1c0) = 0x3ff00000314;
    *(undefined8 *)(param_2 + 0x1c8) = 0x10400000100;
    *(undefined8 *)(param_2 + 0x1d0) = 0x10c00000108;
    puVar2 = (undefined4 *)(param_2 + 0x1d8);
    do {
      *puVar2 = 0;
      puVar3 = puVar2 + 2;
      puVar2[1] = 0;
      puVar2 = puVar3;
    } while (puVar3 != (undefined4 *)(param_2 + 600));
    *(undefined1 *)(param_2 + 0x8258) = 0;
    return 0;
  }
  *(undefined1 *)(param_2 + 0x168) = 0;
  return 0;
}


// ===== 003896a0 khfrpConstructEngine_IMPL =====

undefined8 khfrpConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_1c [3];
  
  iVar1 = osReadRegistryDword(param_1,"RmEnableDStateHfrp",local_1c);
  if (iVar1 != 0 || local_1c[0] != 0) {
    iVar1 = osReadRegistryDword(param_1,"RmEnableHdaDStateHfrp",local_1c);
    if (iVar1 == 0 && local_1c[0] == 0) {
      *(undefined1 *)(param_2 + 0x169) = 0;
    }
    *(undefined8 *)(param_2 + 0x1a8) = 0x31100000110;
    *(undefined8 *)(param_2 + 0x1b0) = 0x1ff00000114;
    *(undefined8 *)(param_2 + 0x1b8) = 0x11100000310;
    *(undefined8 *)(param_2 + 0x1c0) = 0x3ff00000314;
    *(undefined8 *)(param_2 + 0x1c8) = 0x10400000100;
    *(undefined8 *)(param_2 + 0x1d0) = 0x10c00000108;
    puVar2 = (undefined4 *)(param_2 + 0x1d8);
    do {
      *puVar2 = 0;
      puVar3 = puVar2 + 2;
      puVar2[1] = 0;
      puVar2 = puVar3;
    } while (puVar3 != (undefined4 *)(param_2 + 600));
    *(undefined1 *)(param_2 + 0x8258) = 0;
    return 0;
  }
  *(undefined1 *)(param_2 + 0x168) = 0;
  return 0;
}


// ===== 003897b0 khfrpDestruct_IMPL =====

void khfrpDestruct_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x198) != 0) {
    __nvoc_objDelete();
    *(undefined8 *)(param_1 + 0x198) = 0;
  }
  if (*(long *)(param_1 + 0x1a0) != 0) {
    __nvoc_objDelete();
    *(undefined8 *)(param_1 + 0x1a0) = 0;
  }
  return;
}


// ===== 00389800 khfrpIoApertureConstruct_IMPL =====

void khfrpIoApertureConstruct_IMPL(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = __nvoc_objCreate_IoAperture
                    (param_2 + 0x198,param_2,0,*(undefined8 *)(param_1 + 0x1a18),param_1,0,0,0,0,
                     *(undefined4 *)(param_2 + 0x178),0x200);
  if (iVar1 == 0) {
    __nvoc_objCreate_IoAperture
              (param_2 + 0x1a0,param_2,0,*(undefined8 *)(param_1 + 0x1a18),param_1,0,0,0,0,
               *(undefined4 *)(param_2 + 0x17c),0x200);
  }
  return;
}


// ===== 00389890 khfrpStatePreInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 khfrpStatePreInitLocked_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  if (*(char *)(param_2 + 0x168) != '\0') {
    local_40 = 0;
    local_38 = 0;
    local_30 = 0;
    local_28 = 0;
    local_20 = 0;
    iVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a7a,&local_40,0x28);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x1b2,"khfrpStatePreInitLocked_IMPL",4,
                   "NVRM: Failed to get HFRP info, bail out\n");
    }
    *(undefined8 *)(param_2 + 0x16c) = local_40;
    *(undefined8 *)(param_2 + 0x174) = local_38;
    *(undefined8 *)(param_2 + 0x17c) = local_30;
    *(undefined8 *)(param_2 + 0x184) = local_28;
    *(undefined8 *)(param_2 + 0x18c) = local_20;
    khfrpIoApertureConstruct_IMPL(param_1,param_2);
    return 0;
  }
  return 0;
}


// ===== 00389983 khfrpWriteBit_IMPL.cold =====

void khfrpWriteBit_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003899a0 khfrpWriteBit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void khfrpWriteBit_IMPL(long param_1,uint param_2,uint param_3,int param_4)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  code *pcVar4;
  uint uVar5;
  
  lVar1 = (ulong)(param_2 >> 9) + 0x32;
  lVar2 = *(long *)(param_1 + 8 + lVar1 * 8);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar3 = *(long **)(lVar2 + 0x50);
  uVar5 = (**(code **)(*plVar3 + 0x28))(plVar3,param_2 & 0x1ff);
  lVar1 = *(long *)(param_1 + 8 + lVar1 * 8);
  if (lVar1 != 0) {
    plVar3 = *(long **)(lVar1 + 0x50);
    (**(code **)(*plVar3 + 0x40))
              (plVar3,param_2 & 0x1ff,
               (uint)(param_4 != 0) << ((byte)param_3 & 0x1f) | uVar5 & ~(1 << (param_3 & 0x1f)));
    return;
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)invalidInstructionException();
  (*pcVar4)();
}


// ===== 00389a2d khfrpMailboxQueueMessage_IMPL.cold =====

void khfrpMailboxQueueMessage_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00389a50 khfrpMailboxQueueMessage_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
khfrpMailboxQueueMessage_IMPL
          (long param_1,undefined4 param_2,undefined8 param_3,int param_4,int param_5)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined1 local_44;
  undefined1 local_40;
  undefined4 local_3c [3];
  
  if (param_5 == 0) {
    iVar12 = *(int *)(param_1 + 0x1b0);
    iVar8 = *(int *)(param_1 + 0x1b4);
    uVar11 = *(uint *)(param_1 + 0x1a8);
    uVar9 = *(uint *)(param_1 + 0x1ac);
  }
  else {
    iVar12 = *(int *)(param_1 + 0x1c0);
    iVar8 = *(int *)(param_1 + 0x1c4);
    uVar11 = *(uint *)(param_1 + 0x1b8);
    uVar9 = *(uint *)(param_1 + 0x1bc);
  }
  uVar10 = (iVar8 + 1) - iVar12;
  lVar1 = *(long *)(param_1 + 0x198 + (ulong)(uVar11 >> 9) * 8);
  local_3c[0] = param_2;
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar2 = *(long **)(lVar1 + 0x50);
  uVar5 = (**(code **)(*plVar2 + 0x28))(plVar2,uVar11 & 0x1fc);
  uVar5 = uVar5 >> (sbyte)((uVar11 & 3) << 3);
  lVar1 = *(long *)(param_1 + 0x198 + (ulong)(uVar9 >> 9) * 8);
  if (lVar1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  plVar2 = *(long **)(lVar1 + 0x50);
  uVar6 = (**(code **)(*plVar2 + 0x28))(plVar2,uVar9 & 0x1fc);
  local_44 = (undefined1)uVar5;
  uVar9 = uVar6 >> ((byte)uVar9 & 3) * '\b' & 0xff;
  if ((uVar9 < uVar10) && ((uVar5 & 0xff) < uVar10)) {
    uVar3 = (ulong)((uVar10 + (uVar5 & 0xff)) - uVar9) % (ulong)uVar10;
    if ((uint)(param_4 + 4 + (int)uVar3) < uVar10) {
      uVar7 = _hfrpWriteMailboxData(param_1,local_3c,4,iVar12 + (uVar5 & 0xff));
      local_40 = (undefined1)param_4;
      iVar8 = _hfrpWriteMailboxData(param_1,param_3,local_40,uVar7);
      _hfrpWriteByte(param_1,uVar11,iVar8 - iVar12 & 0xff);
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x27f,"khfrpMailboxQueueMessage_IMPL",1,
                 "NVRM: Buffer full: buffer size used (%u) + payload size (%u) + header size (%u) >= mailbox buffer size (%u)\n"
                 ,uVar3,param_4,4,(ulong)uVar10);
    return 0x88;
  }
  nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x276,"khfrpMailboxQueueMessage_IMPL",4,
               "NVRM: Invalid state: head (%u) or tail (%u) pointer is out of range\n",local_44,
               uVar9);
  return 0x40;
}


// ===== 00389c60 khfrpAllocateSequenceId_IMPL =====

undefined8
khfrpAllocateSequenceId_IMPL
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,
          uint *param_6)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar5 = 0x20;
  uVar2 = 0x400;
  uVar3 = (ulong)*(byte *)(param_1 + 0x8258);
  do {
    uVar1 = *(uint *)(param_1 + 0x1d8 + uVar3 * 4);
    if (uVar1 != 0xffffffff) {
      uVar6 = ~uVar1 & uVar1 + 1;
      uVar2 = (uint)((uVar6 & 0xff00ff00) != 0) << 3 | (uint)((uVar6 & 0xf0f0f0f0) != 0) << 2 |
              (uint)(0xffff < uVar6) << 4;
      iVar7 = (int)uVar3 * 0x20;
      if ((uVar6 & 0xcccccccc) == 0) {
        if ((uVar6 & 0xaaaaaaaa) == 0) {
LAB_00389d06:
          uVar2 = uVar2 + iVar7;
        }
        else {
          uVar2 = (uVar2 | 1) + iVar7;
        }
LAB_00389d09:
        *(uint *)(param_1 + 0x1d8 + uVar3 * 4) = uVar1 + 1 | uVar1;
        *(char *)(param_1 + 0x8258) = (char)uVar3;
        uVar3 = (ulong)uVar2;
        *(undefined8 *)(param_1 + 600 + uVar3 * 8) = param_3;
        *(undefined8 *)(param_1 + 0x2258 + uVar3 * 8) = param_2;
        *(undefined8 *)(param_1 + 0x4258 + uVar3 * 8) = param_4;
        *(undefined8 *)(param_1 + 0x6258 + uVar3 * 8) = param_5;
        break;
      }
      if ((uVar6 & 0xaaaaaaaa) == 0) {
        uVar2 = uVar2 | 2;
        goto LAB_00389d06;
      }
      uVar2 = (uVar2 | 3) + iVar7;
      if (uVar2 != 0x3ff) goto LAB_00389d09;
    }
    uVar3 = (ulong)((int)uVar3 + 1U & 0x1f);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *param_6 = uVar2;
  uVar4 = 0;
  if (uVar2 == 0x400) {
    nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",699,"khfrpAllocateSequenceId_IMPL",1,
                 "NVRM: Could not allocate a sequence id to the command\n");
    uVar4 = 0x17;
  }
  return uVar4;
}


// ===== 00389de0 khfrpPollOnIrqRm_IMPL.cold =====

void khfrpPollOnIrqRm_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00389df0 khfrpPollOnIrqRm_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 khfrpPollOnIrqRm_IMPL(long param_1,uint param_2,byte param_3,char param_4)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined1 local_50 [32];
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar5 = gpuEngineGetGpu(uVar6);
  timeoutSet(lVar5 + 0x1af0,local_50,0,5);
  while( true ) {
    lVar1 = *(long *)(param_1 + 8 + ((ulong)(param_2 >> 9) + 0x32) * 8);
    if (lVar1 == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    plVar2 = *(long **)(lVar1 + 0x50);
    uVar4 = (**(code **)(*plVar2 + 0x28))(plVar2,param_2 & 0x1ff);
    if ((uint)(param_4 != '\0') == (uVar4 >> (param_3 & 0x1f) & 1)) break;
    uVar6 = timeoutCheck(lVar5 + 0x1af0,local_50,0x300);
    if ((int)uVar6 == 0x65) {
      return uVar6;
    }
    osSpinLoop();
  }
  return 0;
}


// ===== 00389ee0 khfrpPostCommandBlocking_IMPL =====

int khfrpPostCommandBlocking_IMPL
              (long param_1,uint param_2,undefined8 param_3,int param_4,undefined8 param_5,
              undefined8 param_6,undefined8 param_7)

{
  uint *puVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint local_40;
  int local_3c [3];
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar4 = gpuEngineGetGpu(uVar6);
  if (*(char *)(param_1 + 0x168) == '\0') {
    iVar3 = 0x6d;
    nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x31e,"khfrpPostCommandBlocking_IMPL",4,
                 "NVRM: hfrp is not enabled \n");
  }
  else {
    iVar3 = khfrpAllocateSequenceId_IMPL(param_1,param_5,param_6,param_7,local_3c,&local_40);
    if (iVar3 != 0x17) {
      uVar7 = (ulong)local_40;
      iVar3 = khfrpMailboxQueueMessage_IMPL
                        (param_1,(local_40 & 0x3ff) << 8 | (param_2 & 0x3ff) << 0x12 |
                                 param_4 + 4U & 0xff,param_3,param_4,0);
      uVar5 = 1 << ((byte)local_40 & 0x1f);
      if (iVar3 == 0x88) {
        *(undefined8 *)(param_1 + 600 + uVar7 * 8) = 0;
        *(undefined8 *)(param_1 + 0x2258 + uVar7 * 8) = 0;
        *(undefined8 *)(param_1 + 0x4258 + uVar7 * 8) = 0;
        *(undefined8 *)(param_1 + 0x6258 + uVar7 * 8) = 0;
        puVar1 = (uint *)(param_1 + 0x1d8 + (ulong)(local_40 >> 5) * 4);
        *puVar1 = *puVar1 & ~uVar5;
        iVar3 = 0x88;
      }
      else {
        uVar2 = (ulong)(local_40 >> 5);
        *(undefined1 *)(lVar4 + 0x4be) = 1;
        khfrpWriteBit_IMPL(param_1,*(undefined4 *)(param_1 + 0x1c8),1,1);
        do {
          iVar3 = khfrpPollOnIrqRm_IMPL(param_1,*(undefined4 *)(param_1 + 0x1cc),1,1);
          if (iVar3 == 0x65) {
            *(undefined8 *)(param_1 + 600 + uVar7 * 8) = 0;
            *(undefined8 *)(param_1 + 0x2258 + uVar7 * 8) = 0;
            *(undefined8 *)(param_1 + 0x4258 + uVar7 * 8) = 0;
            *(undefined8 *)(param_1 + 0x6258 + uVar7 * 8) = 0;
            puVar1 = (uint *)(param_1 + 0x1d8 + uVar2 * 4);
            *puVar1 = *puVar1 & ~uVar5;
            nvDbg_Printf("src/kernel/gpu/hfrp/kernel_hfrp.c",0x343,"khfrpPostCommandBlocking_IMPL",1
                         ,
                         "NVRM: Timed out while waiting to receive response for the command posted\n"
                        );
            *(undefined1 *)(lVar4 + 0x4be) = 0;
            return 0x65;
          }
          iVar3 = khfrpProcessResponse_IMPL(param_1);
          if (iVar3 == 0x40) {
LAB_0038a100:
            *(undefined8 *)(param_1 + 600 + uVar7 * 8) = 0;
            *(undefined8 *)(param_1 + 0x2258 + uVar7 * 8) = 0;
            *(undefined8 *)(param_1 + 0x4258 + uVar7 * 8) = 0;
            *(undefined8 *)(param_1 + 0x6258 + uVar7 * 8) = 0;
            puVar1 = (uint *)(param_1 + 0x1d8 + uVar2 * 4);
            *puVar1 = *puVar1 & ~uVar5;
            *(undefined1 *)(lVar4 + 0x4be) = 0;
            return 0x40;
          }
          khfrpWriteBit_IMPL(param_1,*(undefined4 *)(param_1 + 0x1d4),1,1);
          iVar3 = khfrpProcessResponse_IMPL(param_1);
          if (iVar3 == 0x40) goto LAB_0038a100;
        } while ((*(uint *)(param_1 + 0x1d8 + uVar2 * 4) & uVar5) != 0);
        *(undefined1 *)(lVar4 + 0x4be) = 0;
        iVar3 = local_3c[0];
      }
    }
  }
  return iVar3;
}


// ===== 0038a1a0 khwpmGetCblockInfo_GB100 =====

void khwpmGetCblockInfo_GB100
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 5;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 2;
  }
  return;
}


// ===== 0038a1c0 khwpmGetCblockInfo_GB10B =====

void khwpmGetCblockInfo_GB10B
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 3;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 2;
  }
  return;
}


// ===== 0038a1e0 khwpmGetCblockInfo_GB20B =====

void khwpmGetCblockInfo_GB20B
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 2;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 2;
  }
  return;
}


// ===== 0038a200 khwpmGetCblockInfo_GH100 =====

void khwpmGetCblockInfo_GH100
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 9;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  return;
}


// ===== 0038a220 khwpmGetCblockInfo_GM107 =====

void khwpmGetCblockInfo_GM107
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined4 *param_4)

{
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 1;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 1;
  }
  return;
}


// ===== 0038a240 _khwpmProfilerPmaVaSpaceAllocStateChange =====

ulong _khwpmProfilerPmaVaSpaceAllocStateChange
                (long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  uint local_2c;
  
  lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_KernelHwpm);
  if (((lVar3 != 0) && (param_1 != 0)) &&
     (lVar4 = gpuEngineGetGpu(*(undefined8 *)(lVar3 + 0x150)), lVar4 != 0)) {
    uVar2 = *(uint *)(param_1 + 0x58);
    if (uVar2 < *(uint *)(lVar3 + 0x17c)) {
      lVar6 = (ulong)uVar2 * 0x30;
      cVar1 = *(char *)(*(long *)(lVar3 + 400) + 0x18 + lVar6);
      if (param_4 == 1) {
        if (cVar1 != '\0') {
          return 99;
        }
        uVar5 = khwpmStreamoutCreatePmaVaSpace_IMPL(lVar4,lVar3,uVar2);
        local_2c = (uint)uVar5;
        if (local_2c == 0) {
          *(undefined1 *)(*(long *)(lVar3 + 400) + 0x18 + lVar6) = 1;
          return uVar5 & 0xffffffff;
        }
        pcVar8 = "NVRM: Failed to allocate PMA VA space for CBLOCK ID 0x%x. Error 0x%x\n";
        uVar7 = 0x58;
      }
      else {
        if (cVar1 == '\0') {
          return 0x40;
        }
        uVar5 = khwpmStreamoutFreePmaVaSpace_IMPL(lVar4,lVar3,uVar2);
        local_2c = (uint)uVar5;
        if (local_2c == 0) {
          *(undefined1 *)(*(long *)(lVar3 + 400) + 0x18 + lVar6) = 0;
          return uVar5 & 0xffffffff;
        }
        pcVar8 = "NVRM: Failed to free PMA VA space for CBLOCK ID 0x%x. Error 0x%x\n";
        uVar7 = 0x68;
      }
      nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm.c",uVar7,
                   "_khwpmProfilerPmaVaSpaceAllocStateChange",4,pcVar8,uVar2,uVar5);
      return (ulong)local_2c;
    }
    nvAssertFailedNoLog("bpcIdx < pKernelHwpm->maxCblocks","src/kernel/gpu/hwpm/kern_hwpm.c",0x4c);
  }
  return 0x40;
}


// ===== 0038a420 khwpmStateInitUnlocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int khwpmStateInitUnlocked_IMPL(long param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  int local_44;
  undefined8 local_40 [2];
  
  *(uint *)(param_2 + 0x2f) = 2 - (uint)((char)param_2[0x2e] == '\0');
  (*(code *)param_2[0x2d])(param_1,param_2,param_2 + 0x30,param_2 + 0x31);
  *(int *)((long)param_2 + 0x17c) = (int)param_2[0x30] * (int)param_2[0x2f];
  *(int *)((long)param_2 + 0x184) = (int)param_2[0x31] * (int)param_2[0x30] * (int)param_2[0x2f];
  if ((*(char *)(param_1 + 0x908) != '\0') &&
     ((*(char *)(param_1 + 0x4913) == '\0' || (*(char *)(param_1 + 0x491e) != '\0')))) {
    return 0;
  }
  param_2[0x34] = 0xff00000000;
  param_2[0x33] = 0x100000000;
  param_2[0x35] = 0x100000000;
  iVar1 = osReadRegistryDword(param_1,"RmHwpmExtendedBuffer",&local_44);
  if ((iVar1 == 0) && (local_44 == 1)) {
    if (*(char *)((long)param_2 + 0x173) != '\x01') {
      iVar1 = 0x1f;
      goto LAB_0038a5e5;
    }
    *(undefined1 *)((long)param_2 + 0x172) = 1;
    param_2[0x35] = 0x2000400000;
  }
  lVar2 = portMemAllocNonPaged((ulong)*(uint *)((long)param_2 + 0x17c) * 0x30);
  param_2[0x32] = lVar2;
  if (lVar2 == 0) {
    iVar1 = 0x51;
  }
  else {
    portMemSet(lVar2,0,(ulong)*(uint *)((long)param_2 + 0x17c) * 0x30);
    if (*(int *)((long)param_2 + 0x17c) == 0) {
      return 0;
    }
    uVar3 = 0;
    lVar2 = 0;
    while( true ) {
      local_40[0] = 0;
      iVar1 = __nvoc_objCreate_OBJREFCNT
                        (local_40,param_2,0,param_2,uVar3,_khwpmProfilerPmaVaSpaceAllocStateChange,0
                        );
      if (iVar1 != 0) break;
      uVar3 = uVar3 + 1;
      *(undefined8 *)(param_2[0x32] + lVar2) = local_40[0];
      lVar2 = lVar2 + 0x30;
      if (*(uint *)((long)param_2 + 0x17c) <= uVar3) {
        return 0;
      }
    }
    nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm.c",0xd6,"khwpmStateInitUnlocked_IMPL",4,
                 "NVRM: Initialization of VaSpace Refcnt objects failed!\n");
  }
LAB_0038a5e5:
  (**(code **)(*param_2 + 0xc0))(param_1,param_2);
  return iVar1;
}


// ===== 0038a670 khwpmStateDestroy_IMPL =====

void khwpmStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 400);
  if (lVar3 == 0) {
    return;
  }
  if (*(int *)(param_2 + 0x17c) != 0) {
    lVar1 = 0;
    do {
      lVar2 = lVar1 + 1;
      __nvoc_objDelete(*(undefined8 *)(lVar3 + lVar1 * 0x30));
      *(undefined8 *)(*(long *)(param_2 + 400) + lVar1 * 0x30) = 0;
      lVar3 = *(long *)(param_2 + 400);
      lVar1 = lVar2;
    } while ((uint)lVar2 < *(uint *)(param_2 + 0x17c));
    portMemFree();
    return;
  }
  portMemFree();
  return;
}


// ===== 0038a700 khwpmGetRequestCgStatusMask =====

undefined8 khwpmGetRequestCgStatusMask(uint *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = *(uint *)(param_2 + 8) & 3;
  uVar1 = *param_1;
  if (2 < uVar4 - 1) {
    uVar4 = 0;
  }
  *param_1 = uVar1 & 0xfffffffc | uVar4;
  uVar5 = *(uint *)(param_2 + 8) & 0xc;
  if (2 < (*(uint *)(param_2 + 8) >> 2 & 3) - 1) {
    uVar5 = 0;
  }
  *param_1 = uVar1 & 0xfffffff0 | uVar4 | uVar5;
  uVar2 = *(uint *)(param_2 + 8) & 0x30;
  if (2 < (*(uint *)(param_2 + 8) >> 4 & 3) - 1) {
    uVar2 = 0;
  }
  *param_1 = uVar1 & 0xffffffc0 | uVar4 | uVar5 | uVar2;
  uVar6 = *(uint *)(param_2 + 8) & 0xc0;
  if (2 < (*(uint *)(param_2 + 8) >> 6 & 3) - 1) {
    uVar6 = 0;
  }
  *param_1 = uVar1 & 0xffffff00 | uVar4 | uVar5 | uVar2 | uVar6;
  uVar3 = *(uint *)(param_2 + 8) & 0x300;
  if (2 < (*(uint *)(param_2 + 8) >> 8 & 3) - 1) {
    uVar3 = 0;
  }
  *param_1 = uVar1 & 0xfffffc00 | uVar4 | uVar5 | uVar2 | uVar6 | uVar3;
  return 0;
}


// ===== 0038a7b0 khwpmStreamoutAllocPmaStream_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int khwpmStreamoutAllocPmaStream_IMPL
              (long param_1,long param_2,undefined8 param_3,long param_4,long param_5,uint param_6,
              long *param_7)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  char cVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  undefined1 local_54 [4];
  long local_50;
  long local_48;
  long local_40 [2];
  
  uVar3 = (ulong)param_6 / (ulong)*(uint *)(param_2 + 0x188);
  local_50 = 0;
  local_48 = 0;
  if (*(uint *)(param_2 + 0x17c) <= (uint)uVar3) {
    nvCheckFailedNoLog(4,"(bpcIdx < pKernelHwpm->maxCblocks)",
                       "src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0xbd);
    return 0x1f;
  }
  lVar9 = uVar3 * 0x30;
  lVar1 = *(long *)(*(long *)(param_2 + 400) + lVar9);
  if (lVar1 == 0) {
    return 0x40;
  }
  iVar5 = refcntRequestReference_IMPL(lVar1,param_3,1,0);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"refcntRequestReference(pRefcnt, profilerId, REFCNT_STATE_ENABLED, NV_FALSE)",
               "src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0xc5);
    return iVar5;
  }
  plVar2 = *(long **)(*(long *)(param_2 + 400) + 0x10 + lVar9);
  if ((plVar2 != (long *)0x0) && (*(int *)((long)param_7 + 0x4c) == 0)) {
    lVar9 = (**(code **)(*plVar2 + 0xa0))(plVar2);
    uVar3 = *(ulong *)(param_2 + 0x1a8);
    uVar10 = -lVar9;
    if ((*(long *)(param_4 + 0x30) + -1 + lVar9 & uVar10) +
        (*(long *)(param_5 + 0x30) + -1 + lVar9 & uVar10) <= uVar3) {
      uVar6 = (**(code **)(*plVar2 + 0x60))(plVar2);
      uVar7 = (**(code **)(*plVar2 + 0x58))(plVar2);
      iVar5 = (**(code **)(*plVar2 + 0x38))(plVar2,uVar3,uVar3,uVar7,uVar6,0,8,&local_50);
      lVar8 = local_50;
      if (iVar5 == 0) {
        local_40[0] = local_50;
        iVar5 = (**(code **)(*(long *)(param_1 + 0x1bb8) + 0x168))
                          (param_1,*(long *)(param_1 + 0x1bb8),plVar2,param_4,local_40,
                           (-(uint)(*(int *)(param_4 + 0x74) == 0) & 0x10) + 0x20000000,0,0,
                           0xffffffffffffffff);
        if (iVar5 == 0) {
          lVar8 = lVar8 + (*(long *)(param_4 + 0x30) + -1 + lVar9 & uVar10);
          local_40[0] = lVar8;
          iVar5 = (**(code **)(*(long *)(param_1 + 0x1bb8) + 0x168))
                            (param_1,*(long *)(param_1 + 0x1bb8),plVar2,param_5,local_40,
                             (-(uint)(*(int *)(param_5 + 0x74) == 0) & 0x10) + 0x20000000,0,0,
                             0xffffffffffffffff);
          if (iVar5 == 0) {
            *(undefined4 *)(param_7 + 10) = 0;
            iVar5 = vgpuGetCallingContextGfid(param_1,local_54);
            if (iVar5 == 0) {
              cVar4 = hypervisorIsVgxHyper_IMPL();
              if (cVar4 == '\0') {
                lVar9 = *(long *)(param_5 + 0x40);
                if (lVar9 == 0) {
                  local_40[0] = 0;
                  iVar5 = memdescGetAddressSpace(param_5);
                  if (iVar5 == 2) {
                    lVar9 = memdescMapInternal(param_1,param_5,0);
                    if (lVar9 != 0) goto LAB_0038abb6;
                    nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x61,
                                 "_hwpmStreamoutAllocCpuMapping",4,
                                 "NVRM: busMapRmAperture_HAL failed\n");
                    iVar5 = 0xffff;
                  }
                  else {
                    iVar5 = memdescMap(param_5,0,*(undefined8 *)(param_5 + 0x30),1,3,local_40,
                                       &local_48);
                    lVar9 = local_40[0];
                    if (iVar5 == 0) goto LAB_0038abb6;
                    nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x6d,
                                 "_hwpmStreamoutAllocCpuMapping",4,"NVRM: memdescMap failed: 0x%x\n"
                                );
                  }
                  nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x77,
                               "_hwpmStreamoutAllocCpuMapping",4,"NVRM: Error: 0x%x\n");
                  nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x11b,
                               "khwpmStreamoutAllocPmaStream_IMPL",4,
                               "NVRM: Failed to map available bytes buffer to cpu vaspace: 0x%08x\n"
                               ,iVar5);
                  goto LAB_0038a9a0;
                }
                *(undefined8 *)(param_4 + 0x40) = 0;
                *(undefined8 *)(param_5 + 0x40) = 0;
                *(uint *)(param_7 + 10) = *(uint *)(param_7 + 10) | 1;
                local_48 = lVar9;
              }
              else {
                lVar9 = 0;
              }
LAB_0038abb6:
              param_7[7] = lVar9;
              *param_7 = param_4;
              param_7[1] = param_5;
              param_7[8] = local_48;
              param_7[5] = local_50;
              param_7[6] = lVar8;
              lVar1 = *(long *)(param_4 + 0x30);
              param_7[9] = (ulong)param_6 | 0x100000000;
              param_7[4] = lVar1;
              return 0;
            }
            nvAssertOkFailedNoLog
                      (iVar5,"vgpuGetCallingContextGfid(pGpu, &gfid)",
                       "src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x104);
          }
          else {
            nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0xfb,
                         "khwpmStreamoutAllocPmaStream_IMPL",4,
                         "NVRM: Failed to map available bytes buffer to pma vaspace: 0x%08x\n",iVar5
                        );
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0xee,
                       "khwpmStreamoutAllocPmaStream_IMPL",4,
                       "NVRM: Failed to map records buffer to pma vaspace: 0x%08x\n",iVar5);
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0xe4,
                     "khwpmStreamoutAllocPmaStream_IMPL",4,"NVRM: vaspaceAlloc failed: 0x%08x\n",
                     iVar5);
      }
    }
  }
LAB_0038a9a0:
  if (local_50 != 0) {
    (**(code **)(*plVar2 + 0x40))(plVar2);
  }
  iVar5 = refcntReleaseReferences_IMPL(lVar1,param_3,0);
  if (iVar5 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x140,"khwpmStreamoutAllocPmaStream_IMPL"
               ,4,"NVRM: Releasing pPmaVasRefcnt failed on pmChIdx-%d.\n",param_6);
  return iVar5;
}


// ===== 0038ad90 khwpmStreamoutFreePmaStream_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int khwpmStreamoutFreePmaStream_IMPL
              (undefined8 param_1,long param_2,undefined8 param_3,undefined8 *param_4,uint param_5)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  int iVar6;
  long *plVar7;
  
  uVar5 = (ulong)param_5 / (ulong)*(uint *)(param_2 + 0x188);
  if ((uint)uVar5 < *(uint *)(param_2 + 0x17c)) {
    plVar7 = (long *)(uVar5 * 0x30 + *(long *)(param_2 + 400));
    lVar1 = *plVar7;
    if ((lVar1 == 0) || (plVar7 = (long *)plVar7[2], plVar7 == (long *)0x0)) {
      return 0x40;
    }
    if (*(int *)((long)param_4 + 0x4c) != 0) {
      lVar2 = param_4[7];
      if ((lVar2 != 0) && ((*(byte *)(param_4 + 10) & 1) == 0)) {
        uVar3 = param_4[8];
        uVar4 = param_4[1];
        iVar6 = memdescGetAddressSpace();
        if (iVar6 == 2) {
          memdescUnmapInternal(param_1,uVar4,0);
        }
        else {
          memdescUnmap(uVar4,1,lVar2,uVar3);
        }
      }
      param_4[7] = 0;
      param_4[8] = 0;
      if (param_4[5] != 0) {
        (**(code **)(*plVar7 + 0x40))(plVar7);
        param_4[5] = 0;
      }
      param_4[4] = 0;
      memdescDestroy(*param_4);
      *param_4 = 0;
      memdescDestroy(param_4[1]);
      param_4[1] = 0;
      param_4[6] = 0;
      param_4[9] = 0xffffffff;
      iVar6 = refcntReleaseReferences_IMPL(lVar1,param_3,0);
      if (iVar6 != 0) {
        nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x18b,
                     "khwpmStreamoutFreePmaStream_IMPL",4,
                     "NVRM: Releasing pPmaVasRefcnt failed on pmChIdx-%d.\n",param_5);
        return iVar6;
      }
      return 0;
    }
  }
  else {
    nvAssertFailedNoLog("bpcIdx < pKernelHwpm->maxCblocks",
                        "src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x159);
  }
  return 0x1f;
}


// ===== 0038afc0 khwpmStreamoutCreatePmaVaSpace_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int khwpmStreamoutCreatePmaVaSpace_IMPL(long param_1,long param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  int local_60;
  undefined4 local_5c;
  long *local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar1 = *(undefined8 *)(g_pSys + 0x230);
  local_58 = (long *)0x0;
  lVar6 = *(long *)(param_2 + 0x198);
  uVar2 = *(undefined8 *)(param_1 + 0x1b98);
  local_48 = 0;
  lVar3 = *(long *)(param_2 + 0x1a0);
  local_40 = 0;
  if (*(uint *)(param_2 + 0x17c) <= param_3) {
    nvCheckFailedNoLog(4,"(bpcIdx < pKernelHwpm->maxCblocks)",
                       "src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x1ee);
    return 0x1f;
  }
  lVar7 = (ulong)param_3 * 0x30;
  if (*(long *)(*(long *)(param_2 + 400) + 0x10 + lVar7) != 0) {
    nvAssertFailedNoLog("(pKernelHwpm->streamoutState[bpcIdx].pPmaVAS == NULL)",
                        "src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x1ef);
    return 0x40;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x1b78);
  local_50 = 0;
  local_5c = 2;
  local_60 = (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0') + 1;
  memdescOverrideInstLoc
            (*(uint *)(param_1 + 0x4930) >> 0x14 & 3,"HWPM PMA instblk",&local_60,&local_5c);
  iVar5 = memdescCreate(&local_50,param_1,0x1000,0x1000,1,local_60,local_5c);
  if (iVar5 == 0) {
    iVar5 = memdescGetAddressSpace(local_50);
    if ((iVar5 == 1) && (*(char *)(param_1 + 0x4a25) != '\0')) {
      memdescSetGpuCacheAttrib(local_50,0);
    }
    *(undefined4 *)(local_50 + 0x9c) = 0x5c;
    iVar5 = memdescAlloc();
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x1b3,"khwpmInstBlkConstruct",4,
                   "NVRM: couldn\'t allocate PERF instblk!\n");
      goto joined_r0x0038b31d;
    }
    iVar5 = memmgrMemDescMemSet_IMPL(uVar4,local_50,0,0);
    if (iVar5 != 0) goto joined_r0x0038b31d;
    *(long *)(*(long *)(param_2 + 400) + 0x20 + lVar7) = local_50;
    iVar5 = vmmCreateVaspace_IMPL
                      (uVar1,0x90f1,0,1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f),lVar6,
                       lVar3 + -1 + lVar6,0,0,0,0x6000000,&local_58);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x204,
                   "khwpmStreamoutCreatePmaVaSpace_IMPL",4,
                   "NVRM: Could not construct PMA vaspace object. Status 0x%x\n",iVar5);
      local_58 = (long *)0x0;
      goto LAB_0038b12f;
    }
    iVar5 = (**(code **)(*local_58 + 0xd0))(local_58,param_1);
    if (iVar5 == 0) {
      iVar5 = kgmmuInstBlkInit_IMPL
                        (uVar2,*(undefined8 *)(*(long *)(param_2 + 400) + 0x20 + lVar7),local_58,
                         0xffffffff,&local_48);
      if (iVar5 == 0) {
        *(long **)(*(long *)(param_2 + 400) + 0x10 + lVar7) = local_58;
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x217,
                   "khwpmStreamoutCreatePmaVaSpace_IMPL",4,
                   "NVRM: Error initializing HWPM PMA Instance Block.\n");
      (**(code **)(*local_58 + 0xd8))(local_58,param_1);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x20e,
                   "khwpmStreamoutCreatePmaVaSpace_IMPL",4,
                   "NVRM: Error Locking down VA space root.\n");
    }
  }
  else {
joined_r0x0038b31d:
    if (local_50 != 0) {
      memdescFree();
      memdescDestroy(local_50);
    }
    nvDbg_Printf("src/kernel/gpu/hwpm/kern_hwpm_streamout.c",500,
                 "khwpmStreamoutCreatePmaVaSpace_IMPL",4,
                 "NVRM: Failed to construct PMA Instance block. Status 0x%x\n",iVar5);
  }
  if (local_58 != (long *)0x0) {
    vmmDestroyVaspace_IMPL(uVar1);
  }
LAB_0038b12f:
  lVar6 = *(long *)(param_2 + 400) + lVar7;
  if (*(long *)(lVar6 + 0x20) != 0) {
    memdescFree();
    memdescDestroy(*(undefined8 *)(*(long *)(param_2 + 400) + 0x20 + lVar7));
    *(undefined8 *)(*(long *)(param_2 + 400) + 0x20 + lVar7) = 0;
    lVar6 = *(long *)(param_2 + 400) + lVar7;
  }
  *(undefined8 *)(lVar6 + 0x10) = 0;
  return iVar5;
}


// ===== 0038b440 khwpmStreamoutFreePmaVaSpace_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 khwpmStreamoutFreePmaVaSpace_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if (param_3 < *(uint *)(param_2 + 0x17c)) {
    lVar4 = (ulong)param_3 * 0x30;
    plVar1 = *(long **)(*(long *)(param_2 + 400) + 0x10 + lVar4);
    if (plVar1 != (long *)0x0) {
      uVar2 = *(undefined8 *)(g_pSys + 0x230);
      (**(code **)(*plVar1 + 0xd8))(plVar1,param_1);
      vmmDestroyVaspace_IMPL(uVar2,plVar1);
      lVar3 = *(long *)(param_2 + 400) + lVar4;
      if (*(long *)(lVar3 + 0x20) != 0) {
        memdescFree();
        memdescDestroy(*(undefined8 *)(*(long *)(param_2 + 400) + 0x20 + lVar4));
        *(undefined8 *)(*(long *)(param_2 + 400) + 0x20 + lVar4) = 0;
        lVar3 = *(long *)(param_2 + 400) + lVar4;
      }
      *(undefined8 *)(lVar3 + 0x10) = 0;
    }
    return 0;
  }
  nvCheckFailedNoLog(4,"(bpcIdx < pKernelHwpm->maxCblocks)",
                     "src/kernel/gpu/hwpm/kern_hwpm_streamout.c",0x23e);
  return 0x1f;
}


// ===== 0038b550 profilerConstruct_IMPL =====

byte profilerConstruct_IMPL(long param_1)

{
  char cVar1;
  
  if (*(char *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x4a27) == '\0') {
    return 0;
  }
  cVar1 = osIsAdministrator();
  return -(cVar1 == '\0') & 0x1b;
}


// ===== 0038b590 profilerControl_IMPL =====

void profilerControl_IMPL(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x128);
  }
  gpuresControl_IMPL(uVar1);
  return;
}


// ===== 0038b5b0 _profilerPollForUpdatedMembytes.isra.0 =====

int _profilerPollForUpdatedMembytes_isra_0(long param_1,long param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  piVar1 = *(int **)(param_1 + 0x38 + (ulong)param_3 * 0x58);
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if (piVar1 == (int *)0x0) {
    nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0xd0,
                 "_profilerPollForUpdatedMembytes",4,"NVRM: Invalid MEM_BYTES_ADDR.\n");
    return 0x40;
  }
  threadStateResetTimeout(param_2);
  timeoutSet(param_2 + 0x1af0,&local_40,0,0);
  if (*piVar1 == -1) {
    do {
      osSpinLoop();
      iVar2 = timeoutCheck(param_2 + 0x1af0,&local_40,0xe0);
      if (*piVar1 != -1) goto LAB_0038b66a;
    } while (iVar2 != 0x65);
    nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0xdb,
                 "_profilerPollForUpdatedMembytes",4,
                 "NVRM: timeout occurred while waiting for PM streamout to idle.\n");
  }
  else {
    iVar2 = 0;
  }
LAB_0038b66a:
  nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0xe3,
               "_profilerPollForUpdatedMembytes",1,"NVRM: status=0x%08x, *MEM_BYTES_ADDR=0x%08x.\n",
               iVar2,*piVar1);
  return iVar2;
}


// ===== 0038b6f0 profilerBaseConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void profilerBaseConstruct_IMPL(long param_1)

{
  (**(code **)(param_1 + 0x138))();
  return;
}


// ===== 0038b700 profilerBaseConstructState_IMPL =====

undefined8 profilerBaseConstructState_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10);
  *(undefined1 *)(param_1 + 0x1c8) = 0;
  *(ulong *)(param_1 + 0x1b0) = CONCAT44(uVar1,uVar2);
  return 0;
}


// ===== 0038b730 profilerBaseDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void profilerBaseDestruct_IMPL(long param_1)

{
  if (*(long *)(param_1 + 400) != 0) {
    portMemFree();
    portMemFree(*(undefined8 *)(param_1 + 0x198));
    *(undefined8 *)(param_1 + 0x198) = 0;
    *(undefined8 *)(param_1 + 400) = 0;
  }
  (**(code **)(param_1 + 0x140))(param_1);
  return;
}


// ===== 0038b790 profilerBaseQuiesceStreamout_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int profilerBaseQuiesceStreamout_IMPL(long param_1,long param_2,undefined8 param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 local_30;
  
  lVar5 = resservGetTlsCallContext();
  lVar6 = *(long *)(param_1 + 0x1b8);
  local_30 = 0;
  if (lVar6 == 0) {
    return 0x40;
  }
  piVar3 = *(int **)(lVar6 + 0x38 + (ulong)param_4 * 0x58);
  if (piVar3 == (int *)0x0) {
    nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0xfc,
                 "profilerBaseQuiesceStreamout_IMPL",4,"NVRM: Invalid MEM_BYTES_ADDR.\n");
    return 0x40;
  }
  if (*piVar3 == -1) {
    iVar4 = _profilerPollForUpdatedMembytes_isra_0(lVar6,param_2,param_4);
    *piVar3 = -1;
    local_30 = CONCAT44(local_30._4_4_,param_4);
    lVar6 = gpuGetRpc(param_2);
    if (lVar6 == 0) goto LAB_0038b8f8;
    if (iVar4 != 0) goto LAB_0038b8ba;
  }
  else {
    *piVar3 = -1;
    local_30 = (ulong)param_4;
    lVar6 = gpuGetRpc(param_2);
    if (lVar6 == 0) {
LAB_0038b8f8:
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x10c)
      ;
      iVar4 = 0x1a;
      goto LAB_0038b8ba;
    }
  }
  uVar1 = *(undefined4 *)(*(long *)(lVar5 + 0x10) + 0x10);
  uVar2 = *(undefined4 *)(*(long *)(lVar5 + 8) + 0x48);
  if ((*(char *)(param_2 + 0x909) == '\0') && (*(char *)(param_2 + 0x90a) == '\0')) {
    iVar4 = rpcDmaControl_wrapper(param_2,lVar6,uVar2,uVar1,0xb0cc0201,&local_30,8);
  }
  else {
    iVar4 = (**(code **)(param_2 + 0x3b90))(param_2 + 0x3b58,uVar2,uVar1,0xb0cc0201,&local_30,8);
  }
  if (iVar4 == 0) {
    if (local_30._4_1_ != '\0') {
      iVar4 = _profilerPollForUpdatedMembytes_isra_0
                        (*(undefined8 *)(param_1 + 0x1b8),param_2,param_4);
      return iVar4;
    }
    return 0;
  }
LAB_0038b8ba:
  nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x115,
               "profilerBaseQuiesceStreamout_IMPL",4,
               "NVRM: Waiting for PMA to be idle failed with error 0x%x\n");
  return iVar4;
}


// ===== 0038b9b0 profilerBaseDestructState_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void profilerBaseDestructState_VF(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1cf0);
  lVar4 = resservGetTlsCallContext();
  lVar5 = *(long *)(param_1 + 0x1b8);
  if (lVar5 == 0) {
    return;
  }
  if (*(int *)(lVar2 + 0x184) == 0) {
    lVar5 = gpuGetRpc(lVar1);
    if (lVar5 == 0) goto LAB_0038bc00;
  }
  else {
    uVar6 = 0;
    iVar3 = 0;
    while( true ) {
      if (*(int *)(lVar5 + 0x4c + uVar6 * 0x58) != 0) {
        iVar3 = profilerBaseQuiesceStreamout_IMPL(param_1,lVar1,lVar2,uVar6 & 0xffffffff);
      }
      uVar6 = uVar6 + 1;
      if (*(uint *)(lVar2 + 0x184) <= (uint)uVar6) break;
      lVar5 = *(long *)(param_1 + 0x1b8);
    }
    lVar5 = gpuGetRpc(lVar1);
    if (lVar5 == 0) {
LAB_0038bc00:
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x13f)
      ;
      goto LAB_0038baa7;
    }
    if (iVar3 != 0) goto LAB_0038baa7;
  }
  if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
    (**(code **)(lVar5 + 0xf0))
              (lVar1,lVar5,*(undefined4 *)(*(long *)(lVar4 + 8) + 0x48),
               *(undefined4 *)(*(long *)(*(long *)(lVar4 + 0x10) + 0x18) + 0x10),
               *(undefined4 *)(*(long *)(lVar4 + 0x10) + 0x10),*(code **)(lVar5 + 0xf0));
  }
  else {
    (**(code **)(lVar1 + 0x3b70))(lVar1 + 0x3b58);
  }
LAB_0038baa7:
  lVar5 = *(long *)(param_1 + 0x1b8);
  if (*(int *)(lVar2 + 0x184) != 0) {
    uVar6 = 0;
    do {
      lVar7 = uVar6 * 0x58;
      lVar4 = lVar5 + lVar7;
      if (*(int *)(lVar4 + 0x4c) != 0) {
        if ((*(char *)(lVar1 + 0x4913) == '\0') || (*(char *)(lVar1 + 0x491e) != '\0')) {
          if (*(long *)(lVar4 + 0x38) != 0) {
            memdescUnmap(*(undefined8 *)(lVar4 + 8),1,*(long *)(lVar4 + 0x38),
                         *(undefined8 *)(lVar4 + 0x40));
            lVar4 = *(long *)(param_1 + 0x1b8) + lVar7;
          }
          if (*(long *)(lVar4 + 8) != 0) {
            memdescFree();
            memdescDestroy(*(undefined8 *)(*(long *)(param_1 + 0x1b8) + 8 + lVar7));
            lVar4 = *(long *)(param_1 + 0x1b8) + lVar7;
          }
          *(undefined4 *)(lVar4 + 0x4c) = 0;
          lVar5 = *(long *)(param_1 + 0x1b8);
        }
        else {
          khwpmStreamoutFreePmaStream_IMPL
                    (lVar1,lVar2,*(undefined8 *)(param_1 + 0x1b0),lVar4,uVar6 & 0xffffffff);
          lVar5 = *(long *)(param_1 + 0x1b8);
        }
      }
      uVar6 = uVar6 + 1;
    } while ((uint)uVar6 < *(uint *)(lVar2 + 0x184));
  }
  portMemFree();
  return;
}


// ===== 0038bc20 profilerBaseQueryCapabilities_IMPL =====

ulong profilerBaseQueryCapabilities_IMPL
                (long param_1,undefined8 param_2,long param_3,undefined1 *param_4)

{
  uint *puVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined1 uVar7;
  ulong uVar8;
  ulong local_48;
  long local_40;
  
  puVar1 = *(uint **)(param_3 + 0x38);
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar3 = *(long *)(lVar2 + 0x1cf0);
  uVar6 = __nvoc_dynamicCast(**(undefined8 **)(*(long *)(param_1 + 0x110) + 0x48),
                             __nvoc_class_def_RmClient);
  if (uVar6 == 0) {
    nvAssertFailedNoLog("NULL != pRmClient","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",
                        0x198);
    return 0x23;
  }
  if ((*(long *)(lVar2 + 0x1bc0) == 0) ||
     (uVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2), (char)uVar6 == '\0')) {
LAB_0038bc95:
    uVar8 = 1;
  }
  else {
    uVar4 = *(undefined8 *)(lVar2 + 0x1bc0);
    uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8);
    uVar6 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(lVar2);
    uVar8 = uVar6 & 0xffffffff;
    if ((char)uVar6 != '\0') goto LAB_0038bc95;
    uVar6 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar2,uVar4,uVar5,&local_48);
    if (((int)uVar6 == 0) &&
       (uVar6 = kmigmgrIsMIGReferenceValid_IMPL(&local_48), (char)uVar6 != '\0')) {
      if ((local_48 == 0) || (local_40 == 0)) {
        uVar6 = nvAssertFailedNoLog("(ref.pKernelMIGGpuInstance != NULL) && (ref.pMIGComputeInstance != NULL)"
                                    ,"src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x92);
      }
      else {
        uVar8 = CONCAT71((int7)(uVar8 >> 8),*(int *)(local_48 + 0x88) == *(int *)(local_40 + 0x80));
        uVar6 = local_48;
      }
    }
  }
  uVar7 = (undefined1)uVar8;
  *param_4 = uVar7;
  param_4[1] = uVar7;
  param_4[2] = uVar7;
  param_4[3] = 0;
  uVar8 = CONCAT71((int7)(uVar8 >> 8),*puVar1 != 0);
  param_4[3] = *puVar1 != 0;
  if (((*puVar1 != 0) || (*(char *)(lVar2 + 0x4a27) == '\0')) ||
     (uVar6 = osCheckAccess(3), (char)uVar6 != '\0')) {
    param_4[5] = 1;
    uVar8 = 1;
  }
  if (((*puVar1 == 0) && (uVar6 = osCheckAccess(3), (char)uVar6 == '\0')) &&
     (*(char *)(lVar2 + 0x4a27) != '\0')) {
    uVar6 = (ulong)*puVar1;
    if (*puVar1 == 0) {
LAB_0038bd50:
      uVar6 = osCheckAccess(3);
      if ((char)uVar6 == '\0') goto LAB_0038bd02;
    }
  }
  else {
    param_4[6] = 1;
    if ((*puVar1 == 0) && (*(char *)(lVar2 + 0x4a27) != '\0')) {
      uVar8 = 1;
      goto LAB_0038bd50;
    }
  }
  param_4[4] = 1;
  uVar8 = 1;
LAB_0038bd02:
  if (*(char *)(lVar3 + 0x171) != '\0') {
    uVar8 = (ulong)((uint)uVar8 |
                   (uint)CONCAT71((int7)(uVar6 >> 8),*(char *)(lVar2 + 0x908) == '\0'));
  }
  return uVar8;
}


// ===== 0038be60 profilerDevConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

ulong profilerDevConstruct_IMPL(long param_1,long param_2,long param_3)

{
  char cVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 local_2f;
  undefined3 local_2b;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x200);
  }
  local_2f = 0;
  local_2b = 0;
  if (((*(char *)(g_pSys + 0x6f) != '\0') && (**(int **)(param_3 + 0x38) == 0)) &&
     (**(int **)(param_3 + 0x40) != 0)) {
    uVar4 = rmclientGetSecurityTokenByHandle();
    uVar5 = rmclientGetSecurityTokenByHandle(*(undefined4 *)(*(long *)(param_2 + 8) + 0x48));
    uVar2 = osValidateClientTokens(uVar5,uVar4);
    if (uVar2 != 0) {
      nvCheckFailedNoLog(2,"rmStatus == NV_OK","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",
                         0x17c);
      return (ulong)uVar2;
    }
  }
  cVar1 = profilerBaseQueryCapabilities_IMPL(uVar6,param_2,param_3,&local_2f);
  uVar3 = 0x1b;
  if (cVar1 != '\0') {
    uVar3 = (**(code **)(param_1 + 0x210))
                      (param_1,param_2,param_3,(ulong)CONCAT34(local_2b,local_2f),
                       *(code **)(param_1 + 0x210));
  }
  return uVar3;
}


// ===== 0038bfc0 profilerDevConstructState_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 profilerDevConstructState_VF(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar7 = *(long *)(param_1 + 0x200);
  lVar4 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  lVar5 = *(long *)(*(long *)(lVar7 + 0x128) + 0xe0);
  lVar6 = portMemAllocNonPaged((ulong)*(uint *)(*(long *)(lVar5 + 0x1cf0) + 0x184) * 0x58);
  if (lVar6 == 0) {
    nvAssertOkFailedNoLog
              (0x51,"_profilerBaseConstructVgpuGuest(pProfBase, pParams)",
               "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x1ef);
    uVar8 = 0x51;
  }
  else {
    portMemSet(lVar6,0,(ulong)*(uint *)(*(long *)(lVar5 + 0x1cf0) + 0x184) * 0x58);
    *(long *)(lVar7 + 0x1b8) = lVar6;
    lVar7 = gpuGetRpc(lVar4);
    if (lVar7 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",500);
      uVar8 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10);
      uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 0x10);
      uVar3 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
      if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
        uVar8 = (**(code **)(lVar7 + 0x348))
                          (lVar4,lVar7,uVar3,uVar2,uVar1,0xb2cc,*(undefined8 *)(param_3 + 0x40));
      }
      else {
        uVar8 = (**(code **)(lVar4 + 0x3b60))
                          (lVar4 + 0x3b58,uVar3,uVar2,uVar1,0xb2cc,*(undefined8 *)(param_3 + 0x40),
                           *(undefined4 *)(param_3 + 0x48));
      }
    }
  }
  return uVar8;
}


// ===== 0038c160 profilerDevConstructState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong profilerDevConstructState_IMPL
                (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  uVar1 = (**(code **)(param_1 + 0x218))();
  uVar3 = 0x20a;
  pcVar2 = "profilerDevConstructStatePrologue_HAL(pProfDev, pCallContext, pAllocParams)";
  if ((int)uVar1 == 0) {
    uVar1 = (**(code **)(param_1 + 0x220))(param_1,param_2,param_3,param_4,0x20a);
    uVar3 = 0x20d;
    pcVar2 = 
    "profilerDevConstructStateInterlude_HAL(pProfDev, pCallContext, pAllocParams, clientPermissions)"
    ;
    if ((int)uVar1 == 0) {
      uVar1 = (**(code **)(param_1 + 0x228))
                        (param_1,param_2,param_3,
                         "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x20d);
      if ((int)uVar1 == 0) {
        return uVar1;
      }
      uVar3 = 0x210;
      pcVar2 = "profilerDevConstructStateEpilogue_HAL(pProfDev, pCallContext, pAllocParams)";
    }
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,pcVar2,"src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",uVar3)
  ;
  return uVar1 & 0xffffffff;
}


// ===== 0038c240 profilerDevConstructStatePrologue_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 profilerDevConstructStatePrologue_FWCLIENT(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  plVar5 = *(long **)(*(long *)(param_1 + 0x1e0) + 0x48);
  uVar1 = *(undefined4 *)((long)plVar5 + 0x11c);
  lVar6 = plVar5[2];
  uVar2 = *(undefined4 *)(*plVar5 + 0x48);
  uVar3 = *(undefined4 *)(plVar5[3] + 0x10);
  lVar7 = gpuGetRpc(lVar4);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x225);
    return 0;
  }
  if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
    uVar8 = (**(code **)(lVar7 + 0x348))
                      (lVar4,lVar7,uVar2,uVar3,(int)lVar6,uVar1,*(undefined8 *)(param_3 + 0x40));
    return uVar8;
  }
  uVar8 = (**(code **)(lVar4 + 0x3b60))
                    (lVar4 + 0x3b58,uVar2,uVar3,(int)lVar6,uVar1,*(undefined8 *)(param_3 + 0x40),
                     *(undefined4 *)(param_3 + 0x48));
  return uVar8;
}


// ===== 0038c360 profilerDevConstructStateInterlude_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void profilerDevConstructStateInterlude_IMPL
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long *plVar2;
  undefined2 local_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  ushort uStack_1c;
  undefined1 uStack_1a;
  undefined1 local_10;
  ushort local_f;
  undefined1 local_d;
  undefined2 local_c;
  undefined1 local_a;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  plVar2 = *(long **)(*(long *)(param_1 + 0x1e0) + 0x48);
  uStack_1a = (undefined1)((ulong)param_4 >> 0x30);
  local_d = uStack_1a;
  uStack_1c = (ushort)((ulong)param_4 >> 0x20);
  local_f = uStack_1c << 8 | uStack_1c >> 8;
  uStack_1d = (undefined1)((ulong)param_4 >> 0x18);
  local_10 = uStack_1d;
  uStack_1e = (undefined1)((ulong)param_4 >> 0x10);
  local_a = uStack_1e;
  local_20 = (undefined2)param_4;
  local_c = local_20;
  (**(code **)(lVar1 + 0x3b90))
            (lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2],0xb0cc0203,&local_10,7);
  return;
}


// ===== 0038c3f0 profilerCtxConstructStateInterlude_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void profilerCtxConstructStateInterlude_IMPL
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long *plVar1;
  long lVar2;
  undefined2 local_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 uStack_1a;
  undefined1 local_f;
  undefined2 local_e;
  undefined1 local_c;
  undefined2 local_b;
  undefined1 local_9;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x1e0) + 0x48);
  lVar2 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  local_e = 0;
  uStack_1a = (undefined1)((ulong)param_4 >> 0x30);
  local_c = uStack_1a;
  uStack_1d = (undefined1)((ulong)param_4 >> 0x18);
  local_f = uStack_1d;
  local_20 = (undefined2)param_4;
  local_b = local_20;
  uStack_1e = (undefined1)((ulong)param_4 >> 0x10);
  local_9 = uStack_1e;
  (**(code **)(lVar2 + 0x3b90))
            (lVar2 + 0x3b58,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],0xb0cc0203,&local_f,7);
  return;
}


// ===== 0038c470 profilerDevConstructStateEpilogue_FWCLIENT =====

undefined8 profilerDevConstructStateEpilogue_FWCLIENT(undefined8 param_1,long param_2)

{
  if (*(int *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 0x118) == 0x4b01b3) {
    return 0;
  }
  nvAssertFailedNoLog("(pParentRef->internalClassId == classId(Subdevice))",
                      "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x271);
  return 0x36;
}


// ===== 0038c4c0 profilerDevDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void profilerDevDestruct_IMPL(long param_1)

{
  (**(code **)(param_1 + 0x230))();
  return;
}


// ===== 0038c4d0 profilerDevDestructState_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void profilerDevDestructState_FWCLIENT(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined1 local_38 [8];
  long local_30;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x1e0),&local_30,local_38);
  uVar1 = *(undefined4 *)(*(long *)(local_30 + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(local_30 + 0x10) + 0x10);
  uVar3 = *(undefined4 *)(*(long *)(*(long *)(local_30 + 0x10) + 0x18) + 0x10);
  lVar5 = gpuGetRpc(lVar4);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x292);
    return;
  }
  if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
    (**(code **)(lVar5 + 0xf0))(lVar4,lVar5,uVar1,uVar3,uVar2,*(code **)(lVar5 + 0xf0));
    return;
  }
  (**(code **)(lVar4 + 0x3b70))(lVar4 + 0x3b58,uVar1,uVar2);
  return;
}


// ===== 0038c5c0 profilerCtxConstructState_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 profilerCtxConstructState_VF(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar7 = *(long *)(param_1 + 0x200);
  lVar4 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  lVar5 = *(long *)(*(long *)(lVar7 + 0x128) + 0xe0);
  lVar6 = portMemAllocNonPaged((ulong)*(uint *)(*(long *)(lVar5 + 0x1cf0) + 0x184) * 0x58);
  if (lVar6 == 0) {
    nvAssertOkFailedNoLog
              (0x51,"_profilerBaseConstructVgpuGuest(pProfBase, pParams)",
               "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x2a2);
    uVar8 = 0x51;
  }
  else {
    portMemSet(lVar6,0,(ulong)*(uint *)(*(long *)(lVar5 + 0x1cf0) + 0x184) * 0x58);
    *(long *)(lVar7 + 0x1b8) = lVar6;
    lVar7 = gpuGetRpc(lVar4);
    if (lVar7 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x2a7)
      ;
      uVar8 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(*(long *)(param_2 + 0x10) + 0x10);
      uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x10) + 0x18) + 0x10);
      uVar3 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x48);
      if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
        uVar8 = (**(code **)(lVar7 + 0x348))
                          (lVar4,lVar7,uVar3,uVar2,uVar1,0xb1cc,*(undefined8 *)(param_3 + 0x40));
      }
      else {
        uVar8 = (**(code **)(lVar4 + 0x3b60))
                          (lVar4 + 0x3b58,uVar3,uVar2,uVar1,0xb1cc,*(undefined8 *)(param_3 + 0x40),
                           *(undefined4 *)(param_3 + 0x48));
      }
    }
  }
  return uVar8;
}


// ===== 0038c760 profilerCtxConstructState_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong profilerCtxConstructState_IMPL
                (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  uVar1 = (**(code **)(param_1 + 0x218))();
  uVar3 = 0x2bd;
  pcVar2 = "profilerCtxConstructStatePrologue_HAL(pProfCtx, pCallContext, pAllocParams)";
  if ((int)uVar1 == 0) {
    uVar1 = (**(code **)(param_1 + 0x220))(param_1,param_2,param_3,param_4,0x2bd);
    uVar3 = 0x2bf;
    pcVar2 = 
    "profilerCtxConstructStateInterlude_HAL(pProfCtx, pCallContext, pAllocParams, clientPermissions)"
    ;
    if ((int)uVar1 == 0) {
      uVar1 = (**(code **)(param_1 + 0x228))
                        (param_1,param_2,param_3,
                         "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x2bf);
      if ((int)uVar1 == 0) {
        return uVar1;
      }
      uVar3 = 0x2c1;
      pcVar2 = "profilerCtxConstructStateEpilogue_HAL(pProfCtx, pCallContext, pAllocParams)";
    }
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,pcVar2,"src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",uVar3)
  ;
  return uVar1 & 0xffffffff;
}


// ===== 0038c840 profilerCtxConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

undefined8 profilerCtxConstruct_IMPL(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  char cVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  undefined4 local_3f;
  undefined3 local_3b;
  
  lVar6 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  uVar5 = *(undefined8 *)(param_1 + 0x200);
  lVar1 = *(long *)(lVar6 + 0x1cf0);
  lVar2 = *(long *)(*(long *)(param_2 + 0x10) + 0x18);
  lVar4 = serverutilGetClientUnderLock(*(undefined4 *)(*(long *)(param_2 + 8) + 0x48));
  local_3f = 0;
  local_3b = 0;
  if (*(char *)(lVar1 + 0x174) == '\0') {
    nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x2d7,
                 "profilerCtxConstruct_IMPL",4,"NVRM: Context level profiler is not supported\n");
    return 0x56;
  }
  cVar3 = profilerBaseQueryCapabilities_IMPL(uVar5,param_2,param_3,&local_3f);
  if (cVar3 == '\0') {
    return 0x1b;
  }
  if ((((*(int *)(lVar2 + 0x118) == 0x2b5b80) && (lVar4 != 0)) && (**(int **)(param_3 + 0x38) == 0))
     && ((*(char *)(lVar6 + 0x4a27) != '\0' && (cVar3 = osCheckAccess(3), cVar3 == '\0')))) {
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar2 + 8),__nvoc_class_def_KernelChannelGroupApi);
    plVar7 = (long *)**(long **)(*(long *)(lVar6 + 0x138) + 0x140);
    if (plVar7 != (long *)0x0) {
      do {
        if (*(int *)(lVar4 + 0x118) != *(int *)(*plVar7 + 0x3e4)) {
          nvCheckFailedNoLog(2,"(pClient->ProcID == pChannel->ProcessID)",
                             "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x2f4);
          return 0x1b;
        }
        plVar7 = (long *)plVar7[1];
      } while (plVar7 != (long *)0x0);
    }
  }
  uVar5 = (**(code **)(param_1 + 0x210))(param_1,param_2,param_3,(ulong)CONCAT34(local_3b,local_3f))
  ;
  return uVar5;
}


// ===== 0038ca70 profilerCtxConstructStatePrologue_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 profilerCtxConstructStatePrologue_FWCLIENT(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  plVar5 = *(long **)(*(long *)(param_1 + 0x1e0) + 0x48);
  uVar1 = *(undefined4 *)((long)plVar5 + 0x11c);
  lVar6 = plVar5[2];
  uVar2 = *(undefined4 *)(*plVar5 + 0x48);
  uVar3 = *(undefined4 *)(plVar5[3] + 0x10);
  lVar7 = gpuGetRpc(lVar4);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x30b);
    return 0;
  }
  if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
    uVar8 = (**(code **)(lVar7 + 0x348))
                      (lVar4,lVar7,uVar2,uVar3,(int)lVar6,uVar1,*(undefined8 *)(param_3 + 0x40));
    return uVar8;
  }
  uVar8 = (**(code **)(lVar4 + 0x3b60))
                    (lVar4 + 0x3b58,uVar2,uVar3,(int)lVar6,uVar1,*(undefined8 *)(param_3 + 0x40),
                     *(undefined4 *)(param_3 + 0x48));
  return uVar8;
}


// ===== 0038cb90 profilerCtxDestruct_FWCLIENT =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void profilerCtxDestruct_FWCLIENT(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  undefined1 local_38 [8];
  long local_30;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x1f8) + 0xe0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x1e0),&local_30,local_38);
  uVar1 = *(undefined4 *)(*(long *)(local_30 + 8) + 0x48);
  uVar2 = *(undefined4 *)(*(long *)(local_30 + 0x10) + 0x10);
  uVar3 = *(undefined4 *)(*(long *)(*(long *)(local_30 + 0x10) + 0x18) + 0x10);
  lVar5 = gpuGetRpc(lVar4);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2.c",0x324);
    return;
  }
  if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
    (**(code **)(lVar5 + 0xf0))(lVar4,lVar5,uVar1,uVar3,uVar2,*(code **)(lVar5 + 0xf0));
    return;
  }
  (**(code **)(lVar4 + 0x3b70))(lVar4 + 0x3b58,uVar1,uVar2);
  return;
}


// ===== 0038cc80 _issueRpcToHost =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _issueRpcToHost(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = resservGetTlsCallContext();
  puVar1 = *(undefined4 **)(lVar2 + 0x48);
  lVar2 = gpuGetRpc(param_1);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",
                        0x2a);
    return 0x1a;
  }
  if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
    uVar3 = rpcDmaControl_wrapper
                      (param_1,lVar2,*puVar1,puVar1[1],puVar1[2],*(undefined8 *)(puVar1 + 4),
                       puVar1[6]);
    return uVar3;
  }
  uVar3 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58);
  return uVar3;
}


// ===== 0038cd40 profilerBaseCtrlCmdFreePmaStream_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void profilerBaseCtrlCmdFreePmaStream_IMPL(long param_1,uint *param_2)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  uint local_3c [3];
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  portMemSet(local_3c,0,4);
  local_3c[0] = *param_2;
  if (((*(long *)(param_1 + 400) != 0) && (*(long *)(param_1 + 0x198) != 0)) &&
     (local_3c[0] < *(uint *)(param_1 + 0x180))) {
    plVar1 = (long *)(*(long *)(param_1 + 400) + (ulong)local_3c[0] * 8);
    lVar3 = *plVar1;
    *plVar1 = 0;
    lVar4 = *(long *)(*(long *)(param_1 + 0x198) + (ulong)*param_2 * 8);
    *(undefined8 *)(*(long *)(param_1 + 0x198) + (ulong)*param_2 * 8) = 0;
    if ((*(long *)(param_1 + 0x1a0) == lVar3) && (*(long *)(param_1 + 0x1a8) == lVar4)) {
      lVar5 = __nvoc_dynamicCast(*(undefined8 *)(lVar3 + 8),__nvoc_class_def_Memory);
      lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar4 + 8),__nvoc_class_def_Memory);
      *(undefined8 *)(param_1 + 0x1a0) = 0;
      *(undefined8 *)(param_1 + 0x1a8) = 0;
      *(undefined1 *)(*(long *)(lVar5 + 0x118) + 0xf0) = 0;
      *(undefined1 *)(*(long *)(lVar6 + 0x118) + 0xf0) = 0;
      refRemoveDependant(lVar3,*(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48));
    }
    else {
      if (lVar3 != 0) {
        refRemoveDependant(lVar3,*(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48));
      }
      if (lVar4 == 0) goto LAB_0038cde1;
    }
    refRemoveDependant(lVar4,*(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48));
  }
LAB_0038cde1:
  plVar1 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  (**(code **)(lVar2 + 0x3b90))
            (lVar2 + 0x3b58,*(undefined4 *)(*plVar1 + 0x48),(int)plVar1[2],0xb0cc0206,local_3c,4);
  return;
}


// ===== 0038cef0 profilerBaseCtrlCmdBindPmResources_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 profilerBaseCtrlCmdBindPmResources_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  char cVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  plVar5 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  uVar1 = (undefined4)plVar5[2];
  uVar2 = *(undefined4 *)(*plVar5 + 0x48);
  if ((*(long *)(param_1 + 400) != 0) && (*(long *)(param_1 + 0x198) != 0)) {
    if ((*(char *)(param_1 + 0x188) == '\0') && (*(uint *)(param_1 + 0x180) != 0)) {
      uVar3 = *(uint *)(param_1 + 0x184);
      if (*(uint *)(param_1 + 0x180) <= uVar3) {
        return 0x1f;
      }
      lVar6 = *(long *)(*(long *)(param_1 + 400) + (ulong)uVar3 * 8);
      lVar7 = *(long *)(*(long *)(param_1 + 0x198) + (ulong)uVar3 * 8);
      if ((lVar6 != 0) && (lVar7 != 0)) {
        lVar9 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_Memory);
        lVar10 = __nvoc_dynamicCast(*(undefined8 *)(lVar7 + 8),__nvoc_class_def_Memory);
        if ((lVar9 == 0) || (lVar10 == 0)) {
          nvAssertFailedNoLog("pCntMem != NULL && pBufMem != NULL",
                              "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x9b);
          return 0x40;
        }
        cVar8 = memdescAcquireRmExclusiveUse(*(undefined8 *)(lVar9 + 0x118));
        if ((cVar8 == '\0') ||
           (cVar8 = memdescAcquireRmExclusiveUse(*(undefined8 *)(lVar10 + 0x118)), cVar8 == '\0')) {
          *(undefined1 *)(*(long *)(lVar9 + 0x118) + 0xf0) = 0;
          *(undefined1 *)(*(long *)(lVar10 + 0x118) + 0xf0) = 0;
          return 0x1f;
        }
        *(long *)(param_1 + 0x1a0) = lVar6;
        *(long *)(param_1 + 0x1a8) = lVar7;
        if (*(char *)(lVar4 + 0x908) == '\0') {
          uVar11 = (**(code **)(lVar4 + 0x3b90))(lVar4 + 0x3b58,uVar2,uVar1,0xb0cc0208,0,0);
          if ((int)uVar11 != 0) {
            *(undefined1 *)(*(long *)(lVar9 + 0x118) + 0xf0) = 0;
            *(undefined1 *)(*(long *)(lVar10 + 0x118) + 0xf0) = 0;
            *(undefined8 *)(param_1 + 0x1a0) = 0;
            *(undefined8 *)(param_1 + 0x1a8) = 0;
            return uVar11;
          }
          return uVar11;
        }
        goto LAB_0038d163;
      }
      nvCheckFailedNoLog(1,"pCntRef != NULL && pBufRef != NULL",
                         "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x95);
    }
    else {
      nvCheckFailedNoLog(1,"!pProfiler->bLegacyHwpm && pProfiler->maxPmaChannels != 0",
                         "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x8a);
    }
  }
  if (*(char *)(lVar4 + 0x908) == '\0') {
    uVar11 = (**(code **)(lVar4 + 0x3b90))(lVar4 + 0x3b58,uVar2,uVar1,0xb0cc0208,0,0);
    return uVar11;
  }
LAB_0038d163:
  uVar11 = _issueRpcToHost(lVar4);
  return uVar11;
}


// ===== 0038d1e0 profilerBaseCtrlCmdUnbindPmResources_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void profilerBaseCtrlCmdUnbindPmResources_IMPL(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  plVar3 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  lVar4 = plVar3[2];
  uVar1 = *(undefined4 *)(*plVar3 + 0x48);
  lVar6 = *(long *)(param_1 + 0x1a8);
  if (*(long *)(param_1 + 0x1a0) != 0) {
    lVar5 = __nvoc_dynamicCast(*(undefined8 *)(*(long *)(param_1 + 0x1a0) + 8),
                               __nvoc_class_def_Memory);
    if (lVar5 != 0) {
      *(undefined1 *)(*(long *)(lVar5 + 0x118) + 0xf0) = 0;
    }
    *(undefined8 *)(param_1 + 0x1a0) = 0;
  }
  if (lVar6 != 0) {
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_Memory);
    if (lVar6 != 0) {
      *(undefined1 *)(*(long *)(lVar6 + 0x118) + 0xf0) = 0;
    }
    *(undefined8 *)(param_1 + 0x1a8) = 0;
  }
  (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58,uVar1,(int)lVar4,0xb0cc0209,0,0);
  return;
}


// ===== 0038d2e0 profilerBaseCtrlCmdReserveHwpmLegacy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void profilerBaseCtrlCmdReserveHwpmLegacy_IMPL(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long *plVar2;
  long lVar3;
  long lVar4;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar4 = plVar2[2];
  uVar1 = *(undefined4 *)(*plVar2 + 0x48);
  *(undefined1 *)(param_1 + 0x188) = 1;
  (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,uVar1,(int)lVar4,0xb0cc020a,param_2,1);
  return;
}


// ===== 0038d330 profilerBaseCtrlCmdAllocPmaStream_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int profilerBaseCtrlCmdAllocPmaStream_IMPL(long param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  char *pcVar11;
  undefined8 uVar12;
  undefined8 local_88;
  long local_80;
  uint local_78 [2];
  undefined8 local_70;
  undefined8 local_68;
  uint local_60;
  undefined8 local_58;
  undefined1 local_50;
  uint local_4c;
  undefined8 local_48;
  undefined1 local_40;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  plVar5 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
  lVar6 = *plVar5;
  uVar1 = (undefined4)plVar5[2];
  local_88 = 0;
  local_80 = 0;
  iVar7 = clientGetResourceRef_IMPL(lVar6,param_2[6],&local_88);
  iVar8 = clientGetResourceRef_IMPL(lVar6,*param_2,&local_88);
  iVar9 = refFindAncestorOfType
                    (*(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48),&DAT_00e0ac20,&local_80);
  if (iVar9 != 0) {
    nvAssertOkFailedNoLog
              (iVar9,"refFindAncestorOfType(RES_GET_REF(pProfiler), classId(Device), &pDevice)",
               "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x10d);
    return iVar9;
  }
  uVar2 = *(undefined4 *)(local_80 + 0x10);
  if ((iVar7 == 0 && iVar8 == 0) && (*(long *)(param_1 + 400) == 0)) {
    portMemSet(local_78,0,4);
    iVar9 = (**(code **)(lVar4 + 0x3b90))
                      (lVar4 + 0x3b58,*(undefined4 *)(lVar6 + 0x48),uVar1,0xb0cc0207,local_78,4);
    if (iVar9 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar9,
                 "pRmApi->Control(pRmApi, pClient->hClient, hObject, NVB0CC_CTRL_CMD_INTERNAL_GET_MAX_PMAS, &maxPmaParams, sizeof(maxPmaParams))"
                 ,"src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x116);
      return iVar9;
    }
    *(uint *)(param_1 + 0x180) = local_78[0];
    lVar10 = portMemAllocNonPaged((ulong)local_78[0] << 3);
    *(long *)(param_1 + 400) = lVar10;
    if (lVar10 == 0) {
      nvAssertFailedNoLog("pProfiler->ppBytesAvailable != NULL",
                          "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x11d);
      return 0x51;
    }
    lVar10 = portMemAllocNonPaged((ulong)local_78[0] << 3);
    *(long *)(param_1 + 0x198) = lVar10;
    if (lVar10 == 0) {
      nvAssertFailedNoLog("pProfiler->ppStreamBuffers != NULL",
                          "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x11f);
      portMemFree(*(undefined8 *)(param_1 + 400));
      *(undefined8 *)(param_1 + 400) = 0;
      return 0x51;
    }
  }
  iVar9 = memRegisterWithGsp_IMPL(lVar4,lVar6,uVar2,*param_2);
  if (iVar9 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar9,"memRegisterWithGsp(pGpu, pClient, hDevice, pParams->hMemPmaBuffer)",
               "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x12a);
    return iVar9;
  }
  iVar9 = memRegisterWithGsp_IMPL(lVar4,lVar6,uVar2,param_2[6]);
  if (iVar9 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar9,"memRegisterWithGsp(pGpu, pClient, hDevice, pParams->hMemPmaBytesAvailable)",
               "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x12d);
    return iVar9;
  }
  portMemSet(local_78,0,0x40);
  local_78[0] = *param_2;
  local_40 = 0;
  local_70 = *(undefined8 *)(param_2 + 2);
  local_68 = *(undefined8 *)(param_2 + 4);
  local_60 = param_2[6];
  local_58 = *(undefined8 *)(param_2 + 8);
  local_50 = (undefined1)param_2[10];
  local_4c = param_2[0xb];
  local_48 = *(undefined8 *)(param_2 + 0xc);
  iVar9 = (**(code **)(lVar4 + 0x3b90))
                    (lVar4 + 0x3b58,*(undefined4 *)(lVar6 + 0x48),uVar1,0xb0cc0204,local_78,0x40);
  if (iVar9 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar9,
               "pRmApi->Control(pRmApi, pClient->hClient, hObject, NVB0CC_CTRL_CMD_INTERNAL_ALLOC_PMA_STREAM, &internalParams, sizeof(internalParams))"
               ,"src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x13b);
    return iVar9;
  }
  param_2[0xb] = local_4c;
  if (iVar7 == 0 && iVar8 == 0) {
    iVar7 = clientGetResourceRef_IMPL(lVar6,param_2[6],&local_88);
    uVar12 = 0x147;
    pcVar11 = "clientGetResourceRef(pClient, pParams->hMemPmaBytesAvailable, &pMemoryRef)";
    if (iVar7 == 0) {
      uVar3 = param_2[0xb];
      *(undefined8 *)(*(long *)(param_1 + 400) + (ulong)uVar3 * 8) = local_88;
      refAddDependant(local_88,*(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48),(ulong)uVar3,
                      "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x147);
      iVar7 = clientGetResourceRef_IMPL(lVar6,*param_2,&local_88);
      if (iVar7 == 0) {
        *(undefined8 *)(*(long *)(param_1 + 0x198) + (ulong)param_2[0xb] * 8) = local_88;
        refAddDependant(local_88,*(undefined8 *)(*(long *)(param_1 + 0x110) + 0x48));
        uVar3 = param_2[0xb];
        *(undefined1 *)(param_1 + 0x188) = 0;
        *(uint *)(param_1 + 0x184) = uVar3;
        goto LAB_0038d4e0;
      }
      uVar12 = 0x14c;
      pcVar11 = "clientGetResourceRef(pClient, pParams->hMemPmaBuffer, &pMemoryRef)";
    }
    nvCheckOkFailedNoLog
              (4,iVar7,pcVar11,"src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",uVar12);
  }
  else {
LAB_0038d4e0:
    *(undefined8 *)(param_2 + 0xc) = local_48;
    iVar7 = 0;
  }
  return iVar7;
}


// ===== 0038d77a profilerBaseCtrlCmdInternalAllocPmaStream_VF.cold =====

void profilerBaseCtrlCmdInternalAllocPmaStream_VF_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  undefined8 unaff_R15;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
  *(undefined8 *)(unaff_RBP + -8) = unaff_R15;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0038d790 profilerBaseCtrlCmdInternalAllocPmaStream_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int profilerBaseCtrlCmdInternalAllocPmaStream_VF(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  undefined4 *puVar5;
  code *pcVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  undefined8 *puVar15;
  long local_98;
  long local_90;
  undefined8 local_88;
  long local_80;
  long local_78;
  long local_70;
  undefined4 local_68 [14];
  
  local_98 = 0;
  local_90 = 0;
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)invalidInstructionException();
    (*pcVar6)();
  }
  lVar9 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (((*(char *)(lVar9 + 0x446) == '\0') && (*(char *)(lVar9 + 0x490e) == '\0')) &&
     (*(char *)(param_2 + 0xe) != '\0')) {
    nvCheckFailedNoLog(4,"pParams->bInputPmaChIdx == NV_FALSE",
                       "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x276);
    return 0x1f;
  }
  uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48);
  iVar8 = serverutilGetResourceRef(uVar1,*param_2,&local_98);
  if (iVar8 != 0) {
    return iVar8;
  }
  lVar9 = __nvoc_dynamicCast(*(undefined8 *)(local_98 + 8),__nvoc_class_def_Memory);
  if (lVar9 != 0) {
    iVar8 = serverutilGetResourceRef(uVar1,param_2[6],&local_90);
    if (iVar8 != 0) {
      return iVar8;
    }
    lVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_90 + 8),__nvoc_class_def_Memory);
    if (lVar10 != 0) {
      if (0xffe00000 < *(ulong *)(param_2 + 4)) {
        return 0x1f;
      }
      if (*(long *)(lVar9 + 0x118) == 0) {
        return 0x1f;
      }
      if (*(ulong *)(*(long *)(lVar9 + 0x118) + 0x30) <
          *(ulong *)(param_2 + 4) + *(long *)(param_2 + 2)) {
        return 0x1f;
      }
      if (*(long *)(lVar10 + 0x118) == 0) {
        return 0x1f;
      }
      if (*(ulong *)(*(long *)(lVar10 + 0x118) + 0x30) < *(long *)(param_2 + 8) + 0x1000U) {
        return 0x1f;
      }
      if ((*(uint *)(lVar10 + 0x18c) & 0x400000) == 0) {
        nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x2a3,
                     "profilerBaseCtrlCmdInternalAllocPmaStream_VF",4,
                     "NVRM: failed: Memory 0x%x provided is not read only (Attr2: 0x%08x).\n",
                     param_2[6],*(uint *)(lVar10 + 0x18c));
        return 0x1f;
      }
      local_88 = 0;
      lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
      local_80 = 0;
      uVar3 = *(undefined8 *)(lVar2 + 0x1cf0);
      lVar11 = rmapiGetInterface(4);
      plVar4 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
      lVar7 = plVar4[2];
      local_78 = 0;
      local_70 = 0;
      uVar1 = *(undefined4 *)(*plVar4 + 0x48);
      lVar12 = resservGetTlsCallContext();
      puVar5 = *(undefined4 **)(lVar12 + 0x48);
      iVar8 = memdescGetAddressSpace(*(undefined8 *)(lVar10 + 0x118));
      if (iVar8 == 1) {
        iVar8 = memdescGetAddressSpace(*(undefined8 *)(lVar9 + 0x118));
        if (iVar8 == 1) {
          lVar12 = gpuGetRpc(lVar2);
          if (lVar12 == 0) {
            nvAssertFailedNoLog("pRpc != NULL",
                                "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x17d);
            iVar8 = 0x1a;
          }
          else {
            if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
              iVar8 = rpcDmaControl_wrapper
                                (lVar2,lVar12,*puVar5,puVar5[1],0xb0cc0105,
                                 *(undefined8 *)(puVar5 + 4),puVar5[6]);
            }
            else {
              iVar8 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58,*puVar5,puVar5[1],0xb0cc0105);
            }
            if (iVar8 == 0) {
              iVar8 = memdescCreateSubMem(&local_78,*(undefined8 *)(lVar10 + 0x118),0,
                                          *(undefined8 *)(param_2 + 8),0x1000);
              if (iVar8 == 0) {
                puVar15 = &local_88;
                iVar8 = memdescMap(local_78,0,*(undefined8 *)(local_78 + 0x30),1,3,&local_80);
                if (iVar8 == 0) {
                  if (*(long *)(param_1 + 0x1b8) == 0) {
                    iVar8 = 0x40;
                  }
                  else {
                    *(long *)(*(long *)(param_1 + 0x1b8) + 8 + (ulong)(uint)param_2[0xb] * 0x58) =
                         local_78;
                    *(long *)((ulong)(uint)param_2[0xb] * 0x58 + *(long *)(param_1 + 0x1b8) + 0x38)
                         = local_80;
                    *(undefined8 *)
                     ((ulong)(uint)param_2[0xb] * 0x58 + *(long *)(param_1 + 0x1b8) + 0x40) =
                         local_88;
                    if ((*(char *)(lVar2 + 0x4913) == '\0') || (*(char *)(lVar2 + 0x491e) != '\0'))
                    {
                      uVar13 = (ulong)(uint)param_2[0xb];
LAB_0038dbbd:
                      *(undefined4 *)(uVar13 * 0x58 + *(long *)(param_1 + 0x1b8) + 0x4c) = 1;
                      *(undefined1 *)
                       ((ulong)(uint)param_2[0xb] * 0x58 + *(long *)(param_1 + 0x1b8) + 0x54) = 1;
                      return 0;
                    }
                    uVar14 = *(undefined8 *)(lVar9 + 0x118);
                    iVar8 = memdescCreateSubMem(&local_70,uVar14,0,*(undefined8 *)(param_2 + 2),
                                                *(undefined8 *)(param_2 + 4),puVar15);
                    if (iVar8 == 0) {
                      *(long *)((ulong)(uint)param_2[0xb] * 0x58 + *(long *)(param_1 + 0x1b8)) =
                           local_70;
                      iVar8 = khwpmStreamoutAllocPmaStream_IMPL
                                        (lVar2,uVar3,*(undefined8 *)(param_1 + 0x1b0),local_70,
                                         local_78,(ulong)(uint)param_2[0xb],
                                         (ulong)(uint)param_2[0xb] * 0x58 +
                                         *(long *)(param_1 + 0x1b8),uVar14);
                      if (iVar8 == 0) {
                        local_68[0] = param_2[0xb];
                        iVar8 = (**(code **)(lVar11 + 0x38))
                                          (lVar11,uVar1,(int)lVar7,0xb0cc0202,local_68,0x30);
                        if (iVar8 == 0) {
                          uVar13 = (ulong)(uint)param_2[0xb];
                          *(undefined8 *)(param_2 + 0xc) =
                               *(undefined8 *)(uVar13 * 0x58 + *(long *)(param_1 + 0x1b8) + 0x28);
                          goto LAB_0038dbbd;
                        }
                      }
                    }
                  }
                }
                else {
                  nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x198,
                               "_profilerBaseCtrlCmdAllocPmaStreamVgpuGuest",4,
                               "NVRM: Mapping of MEM_BYTES_ADDR buffer into CPU VA failed: 0x%x\n",
                               iVar8);
                }
              }
              if (local_80 != 0) {
                memdescUnmap(local_78,1,local_80,local_88);
                if (*(long *)(param_1 + 0x1b8) != 0) {
                  *(undefined8 *)
                   (*(long *)(param_1 + 0x1b8) + 0x38 + (ulong)(uint)param_2[0xb] * 0x58) = 0;
                  *(undefined8 *)
                   ((ulong)(uint)param_2[0xb] * 0x58 + *(long *)(param_1 + 0x1b8) + 0x40) = 0;
                }
              }
              if (local_78 != 0) {
                memdescFree();
                memdescDestroy(local_78);
                if (*(long *)(param_1 + 0x1b8) != 0) {
                  *(undefined8 *)(*(long *)(param_1 + 0x1b8) + 8 + (ulong)(uint)param_2[0xb] * 0x58)
                       = 0;
                }
              }
              if (local_70 != 0) {
                memdescFree();
                memdescDestroy(local_70);
                if (*(long *)(param_1 + 0x1b8) != 0) {
                  *(undefined8 *)(*(long *)(param_1 + 0x1b8) + (ulong)(uint)param_2[0xb] * 0x58) = 0
                  ;
                  return iVar8;
                }
                return iVar8;
              }
              return iVar8;
            }
          }
          nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x186,
                       "_profilerBaseCtrlCmdAllocPmaStreamVgpuGuest",4,
                       "NVRM: Failed to allocate PMA stream. Error 0x%x\n",iVar8);
          return iVar8;
        }
        nvAssertFailedNoLog("(memdescGetAddressSpace(pMemPmaBuffer->pMemDesc) == ADDR_SYSMEM)",
                            "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x17a);
      }
      else {
        nvAssertFailedNoLog("(memdescGetAddressSpace(pMemPmaAvailBytes->pMemDesc) == ADDR_SYSMEM)",
                            "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x178);
      }
      return 0x56;
    }
  }
  return 0x31;
}


// ===== 0038ded0 profilerBaseCtrlCmdPmaStreamUpdateGetPut_VF =====

int profilerBaseCtrlCmdPmaStreamUpdateGetPut_VF(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  uint *puVar3;
  int iVar4;
  ulong uVar5;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar4 = 0x1f;
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (*(uint *)(param_2 + 0x28) <= *(int *)(*(long *)(lVar2 + 0x1cf0) + 0x184) - 1U) {
    puVar3 = *(uint **)((ulong)*(uint *)(param_2 + 0x28) * 0x58 + *(long *)(param_1 + 0x1b8) + 0x38)
    ;
    if (*(char *)(param_2 + 8) != '\0') {
      *puVar3 = 0xffffffff;
      *(undefined8 *)(param_2 + 0x10) = 0xffffffff;
    }
    iVar4 = _issueRpcToHost(lVar2);
    if ((((iVar4 == 0) &&
         (*(char *)((ulong)*(uint *)(param_2 + 0x28) * 0x58 + *(long *)(param_1 + 0x1b8) + 0x54) !=
          '\0')) && (*(char *)(param_2 + 8) != '\0')) && (*(char *)(param_2 + 9) != '\0')) {
      local_40 = 0;
      local_38 = 0;
      local_30 = 0;
      threadStateResetTimeout(lVar2);
      timeoutSet(lVar2 + 0x1af0,&local_40,0,0);
      uVar1 = *puVar3;
      while( true ) {
        if ((uVar1 != 0xffffffff) || (*(long *)(param_2 + 0x10) != 0xffffffff)) goto LAB_0038e010;
        if (iVar4 == 0x65) break;
        osSpinLoop();
        iVar4 = timeoutCheck(lVar2 + 0x1af0,&local_40,0x251);
        uVar1 = *puVar3;
      }
      nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x24d,
                   "_profilerBaseCtrlCmdPmaStreamUpdateGetPutVgpuGuest",4,
                   "NVRM: timeout occurred while waiting for PM streamout to idle.\n");
LAB_0038e010:
      if (*puVar3 == 0xffffffff) {
        uVar5 = *(ulong *)(param_2 + 0x10);
      }
      else {
        uVar5 = (ulong)*puVar3;
        *(ulong *)(param_2 + 0x10) = uVar5;
      }
      if (uVar5 != 0xffffffff) {
        *puVar3 = (uint)uVar5;
      }
      nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x25e,
                   "_profilerBaseCtrlCmdPmaStreamUpdateGetPutVgpuGuest",1,
                   "NVRM: status=0x%08x, *MEM_BYTES_ADDR=0x%08x.\n",iVar4,*puVar3);
    }
  }
  return iVar4;
}


// ===== 0038e0d0 profilerBaseCtrlCmdInternalFreePmaStream_VF =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int profilerBaseCtrlCmdInternalFreePmaStream_VF(long param_1,uint *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  int local_3c;
  uint local_2c;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf0);
  portMemSet(&local_2c,0,4);
  local_2c = *param_2;
  local_3c = 0x1f;
  if (local_2c <= *(int *)(lVar1 + 0x184) - 1U) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
    uVar4 = *(undefined8 *)(lVar1 + 0x1cf0);
    lVar3 = resservGetTlsCallContext();
    puVar2 = *(undefined4 **)(lVar3 + 0x48);
    local_3c = profilerBaseQuiesceStreamout_IMPL(param_1,lVar1,uVar4,local_2c);
    if (local_3c == 0) {
      lVar3 = gpuGetRpc(lVar1);
      if (lVar3 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c"
                            ,0x20b);
        local_3c = 0x1a;
      }
      else {
        if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
          local_3c = rpcDmaControl_wrapper
                               (lVar1,lVar3,*puVar2,puVar2[1],0xb0cc0106,*(undefined8 *)(puVar2 + 4)
                                ,puVar2[6]);
        }
        else {
          local_3c = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58,*puVar2,puVar2[1],0xb0cc0106);
        }
        if (local_3c == 0) {
          if ((*(char *)(lVar1 + 0x4913) != '\0') && (*(char *)(lVar1 + 0x491e) == '\0')) {
            khwpmStreamoutFreePmaStream_IMPL
                      (lVar1,uVar4,*(undefined8 *)(param_1 + 0x1b0),
                       (ulong)local_2c * 0x58 + *(long *)(param_1 + 0x1b8),(ulong)local_2c);
          }
          *(undefined4 *)(*(long *)(param_1 + 0x1b8) + 0x4c + (ulong)local_2c * 0x58) = 0;
          *(undefined1 *)(*(long *)(param_1 + 0x1b8) + 0x54 + (ulong)local_2c * 0x58) = 0;
          return 0;
        }
      }
      pcVar5 = "NVRM: Failed to free PMA stream. Error 0x%x\n";
      uVar4 = 0x214;
    }
    else {
      pcVar5 = "NVRM: Failed to quiesce HWPM streamout. Error 0x%x\n";
      uVar4 = 0x207;
    }
    nvDbg_Printf("src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",uVar4,
                 "_profilerBaseCtrlCmdFreePmaStreamVgpuGuest",4,pcVar5);
  }
  return local_3c;
}


// ===== 0038e310 profilerBaseCtrlCmdInternalSriovPromotePmaStream_VF =====

undefined8 profilerBaseCtrlCmdInternalSriovPromotePmaStream_VF(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  
  uVar1 = *param_2;
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar4 = *(long *)(lVar3 + 0x1cf0);
  if (*(uint *)(lVar4 + 0x184) <= uVar1) {
    nvCheckFailedNoLog(4,"vPmaChIdx < pKernelHwpm->maxPmaChannels",
                       "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x2e3);
    return 0x1f;
  }
  if ((*(char *)(lVar3 + 0x4913) != '\0') && (*(char *)(lVar3 + 0x491e) == '\0')) {
    lVar8 = (ulong)uVar1 * 0x58;
    uVar2 = *(uint *)(lVar4 + 0x188);
    *(undefined8 *)(param_2 + 2) = *(undefined8 *)(*(long *)(param_1 + 0x1b8) + 0x28 + lVar8);
    *(undefined8 *)(param_2 + 6) = *(undefined8 *)(*(long *)(param_1 + 0x1b8) + 0x30 + lVar8);
    *(undefined8 *)(param_2 + 4) =
         *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x1b8) + lVar8) + 0x30);
    uVar7 = *(undefined8 *)(((ulong)uVar1 / (ulong)uVar2) * 0x30 + *(long *)(lVar4 + 400) + 0x20);
    uVar6 = memdescGetPhysAddr(uVar7,1,0);
    *(undefined8 *)(param_2 + 8) = uVar6;
    cVar5 = memdescGetAddressSpace(uVar7);
    *(char *)(param_2 + 10) = cVar5;
    if (cVar5 == '\x02') {
      uVar7 = _issueRpcToHost(lVar3);
      return uVar7;
    }
    nvAssertFailedNoLog("(pParams->hwpmIBAperture == ADDR_FBMEM)",
                        "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x2f7);
  }
  return 0x56;
}


// ===== 0038e440 profilerBaseCtrlCmdInternalGetMaxPmas_IMPL =====

undefined8 profilerBaseCtrlCmdInternalGetMaxPmas_IMPL(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)
              (*(long *)(*(long *)(*(long *)(param_1 + 0x128) + 0xe0) + 0x1cf0) + 0x184);
  return 0;
}


// ===== 0038e470 profilerBaseCtrlCmdRequestCgControls_VF =====

ulong profilerBaseCtrlCmdRequestCgControls_VF(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  undefined4 local_24 [2];
  undefined4 local_1c;
  
  portMemSet(local_24,0,0xc);
  local_1c = 0;
  local_24[0] = 0;
  uVar1 = khwpmGetRequestCgStatusMask(param_2 + 2,local_24);
  if ((int)uVar1 == 0) {
    *param_2 = local_24[0];
    return uVar1;
  }
  nvCheckOkFailedNoLog
            (4,uVar1 & 0xffffffff,
             "khwpmGetRequestCgStatusMask(&pParams->statusMask, &requestParams)",
             "src/kernel/gpu/hwpm/profiler_v2/kern_profiler_v2_ctrl.c",0x325);
  return uVar1 & 0xffffffff;
}


// ===== 0038e4f0 i2capiConstruct_IMPL =====

undefined8 i2capiConstruct_IMPL(void)

{
  return 0;
}


// ===== 0038e500 i2capiDestruct_IMPL =====

void i2capiDestruct_IMPL(void)

{
  return;
}


// ===== 0038e510 intrReadRegTopEnSet_CPU_GA102 =====

undefined8
intrReadRegTopEnSet_CPU_GA102(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (param_3 != 0) {
    return 0;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1608,param_4);
  return uVar1;
}


// ===== 0038e540 intrWriteRegTopEnSet_CPU_GA102 =====

void intrWriteRegTopEnSet_CPU_GA102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  if (param_3 != 0) {
    return;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1608,param_4,param_5);
  return;
}


// ===== 0038e570 intrWriteRegTopEnClear_CPU_GA102 =====

void intrWriteRegTopEnClear_CPU_GA102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  if (param_3 != 0) {
    return;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1610,param_4,param_5);
  return;
}


// ===== 0038e5a0 intrGetLocklessVectorsInRmSubtree_GA100 =====

void intrGetLocklessVectorsInRmSubtree_GA100(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  
  *param_3 = 0xffffffffffffffff;
  if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(param_1 + 0x4a4e) != '\0')) {
    return;
  }
  uVar1 = intrGetVectorFromEngineId_IMPL(param_1,param_2,0x3d,0);
  *(undefined4 *)param_3 = uVar1;
  return;
}


// ===== 0038e5f0 intrSanityCheckEngineIntrStallVector_GA100 =====

undefined1  [16]
intrSanityCheckEngineIntrStallVector_GA100
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uStack_10;
  
  auVar2._0_4_ = (int)param_3 - 0xc0;
  auVar2._4_4_ = 0;
  if (auVar2._0_4_ < 0x20) {
    auVar2._8_8_ = param_3;
    return auVar2;
  }
  nvDbg_Printf("src/kernel/gpu/intr/arch/ampere/intr_ga100.c",0x62,
               "intrSanityCheckEngineIntrStallVector_GA100",4,
               "NVRM: MC_ENGINE_IDX %u has invalid stall intr vector %u\n",param_4);
  auVar1._8_8_ = uStack_10;
  auVar1._0_8_ = param_3;
  return auVar1;
}


// ===== 0038e640 intrSanityCheckEngineIntrNotificationVector_GA100 =====

undefined1  [16]
intrSanityCheckEngineIntrNotificationVector_GA100
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined1 auVar1 [16];
  undefined8 in_RAX;
  undefined1 auVar2 [16];
  undefined8 uStack_10;
  
  if ((uint)param_3 < 0x20) {
    auVar2._8_8_ = param_3;
    auVar2._0_8_ = in_RAX;
    return auVar2;
  }
  nvDbg_Printf("src/kernel/gpu/intr/arch/ampere/intr_ga100.c",0x7e,
               "intrSanityCheckEngineIntrNotificationVector_GA100",4,
               "NVRM: MC_ENGINE_IDX %u has invalid notification intr vector %u\n",param_4);
  auVar1._8_8_ = uStack_10;
  auVar1._0_8_ = param_3;
  return auVar1;
}


// ===== 0038e690 intrGetPendingLowLatencyHwDisplayIntr_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
intrGetPendingLowLatencyHwDisplayIntr_GB202
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  
  bitVectorClrAll_IMPL(param_3,0xb4);
  if (*(int *)(param_1 + 0x4b34) == 3) {
    return 0x11;
  }
  if ((*(char *)(param_1 + 0x44c) != '\0') && (*(char *)(param_1 + 0x450) == '\0')) {
    if (*(int *)(param_2 + 0x36c) != -1) {
      cVar1 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,*(int *)(param_2 + 0x36c),param_4);
      if (cVar1 != '\0') {
        bitVectorSet_IMPL(param_3,0xb4,0xb1);
      }
    }
    return 0;
  }
  return 0xf;
}


// ===== 0038e750 intrSetDisplayInterruptEnable_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrSetDisplayInterruptEnable_GB202
               (undefined8 param_1,long param_2,char param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x36c);
  if (uVar1 == 0xffffffff) {
    return;
  }
  if (param_3 != '\0') {
    (**(code **)(param_2 + 0x270))(param_1,param_2,uVar1 >> 5);
    return;
  }
  (**(code **)(param_2 + 0x278))(param_1,param_2,uVar1 >> 5,1 << ((byte)uVar1 & 0x1f),param_4);
  return;
}


// ===== 0038e7b0 intrCacheDispIntrVectors_GB202 =====

void intrCacheDispIntrVectors_GB202(long param_1,long param_2)

{
  undefined4 uVar1;
  
  if (*(long *)(param_1 + 0x1b80) != 0) {
    uVar1 = intrGetVectorFromEngineId_IMPL(param_1,param_2,2,0);
    *(undefined4 *)(param_2 + 0x368) = uVar1;
    uVar1 = intrGetVectorFromEngineId_IMPL(param_1,param_2,0xb1,0);
    *(undefined4 *)(param_2 + 0x36c) = uVar1;
    return;
  }
  *(undefined4 *)(param_2 + 0x368) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x36c) = 0xffffffff;
  return;
}


// ===== 0038e820 intrGetNumLeaves_GH100 =====

undefined8 intrGetNumLeaves_GH100(void)

{
  return 0xc;
}


// ===== 0038e830 intrGetLeafSize_GH100 =====

undefined8 intrGetLeafSize_GH100(void)

{
  return 0x10;
}


// ===== 0038e840 intrGetIntrTopNonStallMask_GH100 =====

ulong intrGetIntrTopNonStallMask_GH100(long param_1,undefined8 param_2)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = intrGetIntrTopCategoryMask_IMPL(param_2,2);
  if (*(char *)(param_1 + 0x475) != '\0') {
    uVar2 = intrGetIntrTopCategoryMask_IMPL(param_2,4);
    uVar1 = uVar1 | uVar2;
  }
  if (uVar1 == 0) {
    nvAssertFailedNoLog("mask != 0","src/kernel/gpu/intr/arch/hopper/intr_gh100.c",0x87);
    return 0;
  }
  return uVar1;
}


// ===== 0038e8e0 intrSanityCheckEngineIntrStallVector_GH100 =====

undefined1  [16]
intrSanityCheckEngineIntrStallVector_GH100
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uStack_10;
  
  auVar2._0_4_ = (int)param_3 - 0xc0;
  auVar2._4_4_ = 0;
  if (auVar2._0_4_ < 0x40) {
    auVar2._8_8_ = param_3;
    return auVar2;
  }
  nvDbg_Printf("src/kernel/gpu/intr/arch/hopper/intr_gh100.c",0xa4,
               "intrSanityCheckEngineIntrStallVector_GH100",4,
               "NVRM: MC_ENGINE_IDX %u has invalid stall intr vector %u\n",param_4);
  auVar1._8_8_ = uStack_10;
  auVar1._0_8_ = param_3;
  return auVar1;
}


// ===== 0038e930 intrSanityCheckEngineIntrNotificationVector_GH100 =====

undefined1  [16]
intrSanityCheckEngineIntrNotificationVector_GH100
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  undefined1 auVar1 [16];
  undefined8 in_RAX;
  undefined1 auVar2 [16];
  undefined8 uStack_10;
  
  if ((uint)param_3 < 0x40) {
    auVar2._8_8_ = param_3;
    auVar2._0_8_ = in_RAX;
    return auVar2;
  }
  nvDbg_Printf("src/kernel/gpu/intr/arch/hopper/intr_gh100.c",0xc1,
               "intrSanityCheckEngineIntrNotificationVector_GH100",4,
               "NVRM: MC_ENGINE_IDX %u has invalid notification intr vector %u\n",param_4);
  auVar1._8_8_ = uStack_10;
  auVar1._0_8_ = param_3;
  return auVar1;
}


// ===== 0038e980 intrGetIntrTopLegacyStallMask_GH100 =====

ulong intrGetIntrTopLegacyStallMask_GH100(long param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 uVar6;
  
  uVar6 = 0;
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar1 = gpuEngineGetGpu(uVar6);
  uVar2 = intrGetIntrTopCategoryMask_IMPL(param_1,1);
  uVar3 = intrGetIntrTopCategoryMask_IMPL(param_1,3);
  uVar4 = intrGetIntrTopCategoryMask_IMPL(param_1,5);
  uVar5 = intrGetIntrTopCategoryMask_IMPL(param_1,6);
  uVar5 = uVar2 | uVar3 | uVar4 | uVar5;
  if (*(char *)(lVar1 + 0x475) == '\0') {
    uVar2 = intrGetIntrTopCategoryMask_IMPL(param_1,4);
    uVar5 = uVar5 | uVar2;
  }
  if (uVar5 == 0) {
    nvAssertFailedNoLog("ret != 0","src/kernel/gpu/intr/arch/hopper/intr_gh100.c",0xd9);
    return 0;
  }
  return uVar5;
}


// ===== 0038ea50 intrGetIntrTopLockedMask_GH100 =====

ulong intrGetIntrTopLockedMask_GH100(long param_1)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x150);
  }
  lVar1 = gpuEngineGetGpu(uVar4);
  uVar2 = intrGetIntrTopCategoryMask_IMPL(param_1,1);
  uVar3 = intrGetIntrTopCategoryMask_IMPL(param_1,3);
  uVar2 = uVar2 | uVar3;
  if (*(char *)(lVar1 + 0x475) == '\0') {
    uVar3 = intrGetIntrTopCategoryMask_IMPL(param_1,4);
    uVar2 = uVar2 | uVar3;
  }
  if (uVar2 == 0) {
    nvAssertFailedNoLog("ret != 0","src/kernel/gpu/intr/arch/hopper/intr_gh100.c",0xee);
    return 0;
  }
  return uVar2;
}


// ===== 0038eb00 intrGetPendingStall_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int intrGetPendingStall_GM107(long param_1,long param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pEngines != NULL","src/kernel/gpu/intr/arch/maxwell/intr_gm107.c",0x2f);
    return 0x1f;
  }
  bitVectorClrAll_IMPL(param_3,0xb4);
  if (*(int *)(param_1 + 0x4b34) != 3) {
    iVar1 = intrGetPendingStallEngines_TU102(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      if ((*(char *)(param_1 + 0x44c) == '\0') || (*(char *)(param_1 + 0x450) != '\0')) {
        return 0xf;
      }
      (**(code **)(param_2 + 0x338))(param_1,param_2,param_3,1,0,param_4);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,"intrGetPendingStallEngines_HAL(pGpu, pIntr, pEngines, pThreadState)",
                 "src/kernel/gpu/intr/arch/maxwell/intr_gm107.c",0x42);
    }
    return iVar1;
  }
  return 0x11;
}


// ===== 0038ec40 intrGetAuxiliaryPendingStall_GM107 =====

void intrGetAuxiliaryPendingStall_GM107
               (long param_1,undefined8 param_2,undefined8 param_3,char param_4,short param_5,
               undefined8 param_6)

{
  long lVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x1b80);
  lVar1 = *(long *)(param_1 + 0x1bc8);
  if ((((param_4 != '\0') || (param_5 == 0x25)) && (*(char *)(param_1 + 0x908) != '\0')) &&
     (cVar3 = vgpuGetPendingEvent(param_1,param_6), cVar3 != '\0')) {
    bitVectorSet_IMPL(param_3,0xb4,0x25);
  }
  if ((lVar5 != 0) && (*(int *)(lVar5 + 0x364) != 0)) {
    if (*(char *)(lVar5 + 0x27a) == '\0') {
      bitVectorSet_IMPL(param_3,0xb4,2);
    }
    else {
      bitVectorSet_IMPL(param_3,0xb4,0xb1);
    }
  }
  if ((lVar1 != 0) && (sVar4 = fecsGetCtxswLogConsumerCount(param_1,lVar1), 0 < sVar4)) {
    lVar5 = 0;
    do {
      while (((lVar1 = *(long *)(param_1 + 0x1bd0 + lVar5 * 8), lVar1 != 0 &&
              (*(char *)(lVar1 + 0x1fa) != '\0')) &&
             (cVar3 = fecsIsIntrPending(param_1), cVar3 != '\0'))) {
        iVar2 = (int)lVar5;
        lVar5 = lVar5 + 1;
        bitVectorSet_IMPL(param_3,0xb4,iVar2 + 0x9c);
        if (lVar5 == 8) {
          return;
        }
      }
      lVar5 = lVar5 + 1;
    } while (lVar5 != 8);
  }
  return;
}


// ===== 0038edb0 _intrSetIntrEnInHw_GP100.part.0.isra.0 =====

void _intrSetIntrEnInHw_GP100_part_0_isra_0
               (long param_1,uint param_2,uint param_3,uint param_4,undefined8 param_5)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x8f4);
  regWrite032(param_1 + 0x3a18,0,0,0x180,uVar1 & (~param_2 | param_4));
  regWrite032(param_1 + 0x3a18,0,0,0x160,param_3 & param_2 & uVar1,param_5);
  return;
}


// ===== 0038ee10 intrSetIntrEnInHw_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void intrSetIntrEnInHw_GP100(long param_1,long param_2,uint param_3,undefined8 param_4)

{
  if (3 < param_3) {
    nvAssertFailedNoLog("intrEn0 <= INTERRUPT_TYPE_MAX",
                        "src/kernel/gpu/intr/arch/pascal/intr_gp100.c",0x5b);
  }
  *(uint *)(param_2 + 0x1544) = param_3;
  (**(code **)(param_2 + 400))
            (param_1,param_2,param_3,param_2 + 0x1548,param_2 + 0x154c,*(code **)(param_2 + 400));
  if (*(int *)(param_1 + 0x4b34) != 3) {
    _intrSetIntrEnInHw_GP100_part_0_isra_0
              (param_1,*(undefined4 *)(param_2 + 0x150c),*(undefined4 *)(param_2 + 0x1548),
               *(undefined4 *)(param_2 + 0x154c),param_4);
    return;
  }
  return;
}


// ===== 0038eed0 intrSetIntrMask_GP100 =====

undefined8 intrSetIntrMask_GP100(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = bitVectorTestAllSet_IMPL(param_3,0xb4);
  uVar2 = 0xffffffff;
  if (cVar1 == '\0') {
    cVar1 = bitVectorTestAllCleared_IMPL(param_3);
    uVar2 = 0;
    if (cVar1 == '\0') {
      uVar2 = intrConvertEngineMaskToPmcIntrMask_IMPL(param_1,param_2,param_3);
    }
  }
  *(undefined4 *)(param_2 + 0x150c) = uVar2;
  if (*(int *)(param_1 + 0x4b34) != 3) {
    _intrSetIntrEnInHw_GP100_part_0_isra_0
              (param_1,uVar2,*(undefined4 *)(param_2 + 0x1548),*(undefined4 *)(param_2 + 0x154c),
               param_4);
  }
  return 0;
}


// ===== 0038ef60 intrGetIntrEnFromHw_GP100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 intrGetIntrEnFromHw_GP100(long param_1,long param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x4b34) != 3) {
    uVar1 = regRead032(param_1 + 0x3a18,0,0,0x140,param_3);
    uVar2 = (**(code **)(param_2 + 0x198))(param_1,param_2,uVar1);
    return uVar2;
  }
  return 0;
}


// ===== 0038efc0 intrGetIntrMask_GP100 =====

undefined8 intrGetIntrMask_GP100(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x150c);
  if (iVar1 == 0) {
    bitVectorClrAll_IMPL(param_3,0xb4);
    return 0;
  }
  if (iVar1 != -1) {
    intrConvertPmcIntrMaskToEngineMask_IMPL(param_1,param_2,iVar1,param_3);
    return 0;
  }
  bitVectorSetAll_IMPL(param_3,0xb4);
  return 0;
}


// ===== 0038f010 intrGetAuxiliaryPendingStall_GP100 =====

void intrGetAuxiliaryPendingStall_GP100
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char param_4,short param_5,
               undefined8 param_6)

{
  intrGetAuxiliaryPendingStall_GM107();
  if ((param_4 == '\0') && (param_5 != 0x2e)) {
    return;
  }
  intrGetGmmuInterrupts_IMPL(param_1,param_2,param_3,param_6);
  return;
}


// ===== 0038f090 intrEncodeStallIntrEn_GP100 =====

void intrEncodeStallIntrEn_GP100
               (long param_1,undefined8 param_2,int param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == 2) {
    uVar2 = 0x80000000;
    uVar1 = 0x7fffffff;
  }
  else if (param_3 == 1) {
    uVar2 = 0x7fffffff;
    uVar1 = 0x80000000;
  }
  else {
    uVar1 = 0xffffffff;
    uVar2 = 0;
    if (param_3 != 0) {
      uVar1 = 0;
      uVar2 = 0xffffffff;
    }
  }
  *param_4 = uVar2;
  *param_5 = uVar1;
  if (*(uint *)(param_1 + 0x8f4) != 0) {
    *param_4 = *param_4 & *(uint *)(param_1 + 0x8f4);
    *param_5 = *param_5 & *(uint *)(param_1 + 0x8f4);
  }
  return;
}


// ===== 0038f0f0 intrReadRegLeafEnSet_CPU_TU102 =====

void intrReadRegLeafEnSet_CPU_TU102(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1200 + param_3 * 4,param_4);
  return;
}


// ===== 0038f120 intrReadRegLeaf_CPU_TU102 =====

void intrReadRegLeaf_CPU_TU102(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1000 + param_3 * 4,param_4);
  return;
}


// ===== 0038f150 intrReadRegTopEnSet_CPU_TU102 =====

undefined8
intrReadRegTopEnSet_CPU_TU102(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (param_3 != 0) {
    return 0;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1608,param_4);
  return uVar1;
}


// ===== 0038f180 intrReadRegTop_CPU_TU102 =====

undefined8 intrReadRegTop_CPU_TU102(long param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (param_3 != 0) {
    return 0;
  }
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1600,param_4);
  return uVar1;
}


// ===== 0038f1b0 intrWriteRegLeafEnSet_CPU_TU102 =====

void intrWriteRegLeafEnSet_CPU_TU102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1200 + param_3 * 4,param_4,param_5
             );
  return;
}


// ===== 0038f1e0 intrWriteRegLeafEnClear_CPU_TU102 =====

void intrWriteRegLeafEnClear_CPU_TU102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1400 + param_3 * 4,param_4,param_5
             );
  return;
}


// ===== 0038f210 intrWriteRegLeaf_CPU_TU102 =====

void intrWriteRegLeaf_CPU_TU102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1000 + param_3 * 4,param_4,param_5
             );
  return;
}


// ===== 0038f240 intrWriteRegTopEnSet_CPU_TU102 =====

void intrWriteRegTopEnSet_CPU_TU102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  if (param_3 != 0) {
    return;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1608,param_4,param_5);
  return;
}


// ===== 0038f270 intrWriteRegTopEnClear_CPU_TU102 =====

void intrWriteRegTopEnClear_CPU_TU102
               (long param_1,undefined8 param_2,int param_3,undefined4 param_4,undefined8 param_5)

{
  if (param_3 != 0) {
    return;
  }
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1610,param_4,param_5);
  return;
}


// ===== 0038f2a0 _intrServiceNonStallLeaf_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _intrServiceNonStallLeaf_TU102
              (undefined8 param_1,long param_2,uint param_3,int param_4,undefined8 param_5,
              undefined8 param_6)

{
  undefined2 uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int local_ac;
  undefined2 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined2 *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_ac = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_68);
  if (local_ac == 0) {
    iVar4 = vectCount_IMPL(local_68);
    uVar5 = vectAt_IMPL(local_68,iVar4 + -1);
    uVar6 = vectAt_IMPL(local_68,0);
    vectIterRange_IMPL(&local_98,local_68,uVar6,uVar5);
    local_60 = local_98;
    local_58 = local_90;
    local_50 = local_88;
    local_48 = local_80;
    local_40 = local_78;
LAB_0038f370:
    cVar3 = vectIterNext_IMPL(&local_60);
    if (cVar3 != '\0') {
      while ((((uVar2 = *(uint *)(local_60 + 6), uVar2 != 0xffffffff &&
               ((uint)(param_4 * 0x20) <= uVar2)) && (uVar2 <= param_4 * 0x20 + 0x1fU)) &&
             ((param_3 & 1 << ((byte)uVar2 & 0x1f)) != 0))) {
        uVar1 = *local_60;
        bitVectorSet_IMPL(param_5,0xb4,uVar1);
        (**(code **)(param_2 + 0x1d0))(param_1,param_2,uVar2,param_6);
        uVar5 = intrServiceNotificationRecords_IMPL(param_1,param_2,uVar1,param_6);
        iVar4 = (int)uVar5;
        if (iVar4 == 0) break;
        nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_nonstall_tu102.c",0x179,
                     "_intrServiceNonStallLeaf_TU102",4,
                     "NVRM: Could not service nonstall interrupt from mcEngineIdx %d. NV_STATUS = 0x%x\n"
                     ,uVar1,uVar5);
        cVar3 = vectIterNext_IMPL(&local_60,&local_60,0x38f402);
        local_ac = iVar4;
        if (cVar3 == '\0') {
          return iVar4;
        }
      }
      goto LAB_0038f370;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (local_ac,"intrGetInterruptTable_HAL(pGpu, pIntr, &pIntrTable)",
               "src/kernel/gpu/intr/arch/turing/intr_nonstall_tu102.c",0x14f);
  }
  return local_ac;
}


// ===== 0038f4b0 intrGetNonStallEnable_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte intrGetNonStallEnable_TU102(long param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  ulong uVar2;
  uint local_30;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return 0;
  }
  uVar2 = (**(code **)(param_2 + 0x2a8))();
  if (((uint)uVar2 != 0) &&
     (uVar1 = (**(code **)(param_2 + 0x260))(param_1,param_2,0,param_3), (uVar1 & (uint)uVar2) != 0)
     ) {
    return 3;
  }
  if (uVar2 >> 0x20 != 0) {
    uVar1 = (**(code **)(param_2 + 0x260))(param_1,param_2,1,param_3);
    local_30 = (uint)(uVar2 >> 0x20);
    return -((uVar1 & local_30) != 0) & 3;
  }
  return 0;
}


// ===== 0038f580 intrEnableTopNonstall_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void intrEnableTopNonstall_TU102(long param_1,long param_2,undefined8 param_3)

{
  ulong uVar1;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return;
  }
  uVar1 = (**(code **)(param_2 + 0x2a8))();
  if ((int)uVar1 != 0) {
    (**(code **)(param_2 + 0x288))
              (param_1,param_2,0,uVar1 & 0xffffffff,param_3,*(code **)(param_2 + 0x288));
  }
  if (uVar1 >> 0x20 != 0) {
    (**(code **)(param_2 + 0x288))
              (param_1,param_2,1,uVar1 >> 0x20,param_3,*(code **)(param_2 + 0x288));
    return;
  }
  return;
}


// ===== 0038f630 intrDisableTopNonstall_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void intrDisableTopNonstall_TU102(long param_1,long param_2,undefined8 param_3)

{
  ulong uVar1;
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return;
  }
  uVar1 = (**(code **)(param_2 + 0x2a8))();
  if ((int)uVar1 != 0) {
    (**(code **)(param_2 + 0x290))
              (param_1,param_2,0,uVar1 & 0xffffffff,param_3,*(code **)(param_2 + 0x290));
  }
  if (uVar1 >> 0x20 != 0) {
    (**(code **)(param_2 + 0x290))
              (param_1,param_2,1,uVar1 >> 0x20,param_3,*(code **)(param_2 + 0x290));
    return;
  }
  return;
}


// ===== 0038f6e0 intrRestoreNonStall_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrRestoreNonStall_TU102(long param_1,long param_2,int param_3,undefined8 param_4)

{
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return;
  }
  if (param_3 == 0) {
    (**(code **)(param_2 + 0x1c0))(param_1,param_2,param_4);
    return;
  }
  (**(code **)(param_2 + 0x1b8))(param_1,param_2,param_4);
  return;
}


// ===== 0038f730 intrGetPendingNonStall_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int intrGetPendingNonStall_TU102(long param_1,long param_2,long param_3,undefined8 param_4)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  ulong uVar11;
  int iVar12;
  uint uVar13;
  undefined2 *local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_68;
  undefined2 *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar8 = gpuGetKernelFifoShared_IMPL();
  if (param_3 == 0) {
    iVar3 = 0x1f;
    nvAssertFailedNoLog("pEngines != NULL","src/kernel/gpu/intr/arch/turing/intr_nonstall_tu102.c",
                        0xd0);
  }
  else {
    bitVectorClrAll_IMPL(param_3,0xb4);
    if (*(int *)(param_1 + 0x4b34) == 3) {
      iVar3 = 0x11;
    }
    else if ((*(char *)(param_1 + 0x908) == '\0') ||
            (iVar3 = 0x56, *(char *)(param_1 + 0x4913) != '\0')) {
      iVar3 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_68);
      if (iVar3 == 0) {
        uVar11 = (**(code **)(param_2 + 0x2a8))(param_1,param_2);
        if (uVar11 != 0) {
          iVar3 = 0;
          uVar13 = 0;
          while( true ) {
            for (; (uVar11 & 1) == 0; uVar11 = uVar11 >> 1) {
              uVar13 = uVar13 + 1;
            }
            uVar4 = (**(code **)(param_2 + 0x268))(param_1,param_2,uVar13 >> 5,param_4);
            if ((1 << ((byte)uVar13 & 0x1f) & uVar4) != 0) {
              iVar12 = uVar13 * 2;
              iVar5 = iVar12 + 2;
              do {
                uVar4 = (**(code **)(param_2 + 600))(param_1,param_2,iVar12,param_4);
                uVar7 = (**(code **)(param_2 + 0x250))(param_1,param_2,iVar12,param_4);
                if ((uVar4 & uVar7) != 0) {
                  iVar6 = vectCount_IMPL(local_68);
                  uVar9 = vectAt_IMPL(local_68,iVar6 + -1);
                  uVar10 = vectAt_IMPL(local_68,0);
                  vectIterRange_IMPL(&local_98,local_68,uVar10,uVar9);
                  local_60 = local_98;
                  local_58 = local_90;
                  local_50 = local_88;
                  local_48 = local_80;
                  local_40 = local_78;
                  while (cVar2 = vectIterNext_IMPL(&local_60), cVar2 != '\0') {
                    uVar1 = *(uint *)(local_60 + 6);
                    if ((((uVar1 != 0xffffffff) && ((uint)(iVar12 * 0x20) <= uVar1)) &&
                        (uVar1 <= iVar12 * 0x20 + 0x1fU)) &&
                       ((1 << ((byte)uVar1 & 0x1f) & uVar4 & uVar7) != 0)) {
                      bitVectorSet_IMPL(param_3,0xb4,*local_60);
                    }
                  }
                }
                iVar12 = iVar12 + 1;
              } while (iVar5 != iVar12);
            }
            if (uVar11 >> 1 == 0) break;
            uVar11 = uVar11 >> 1;
            uVar13 = uVar13 + 1;
          }
        }
        if (((*(char *)(lVar8 + 0x4b2) == '\0') && (*(char *)(param_1 + 0x909) == '\0')) &&
           ((*(char *)(param_1 + 0x908) == '\0' &&
            (uVar13 = intrGetVectorFromEngineId_IMPL(param_1,param_2,4,1), uVar13 != 0xffffffff))))
        {
          uVar4 = (**(code **)(param_2 + 600))(param_1,param_2,uVar13 >> 5,param_4);
          uVar7 = (**(code **)(param_2 + 0x250))(param_1,param_2,uVar13 >> 5,param_4);
          if (((uVar7 & uVar4) >> (uVar13 & 0x1f) & 1) == 0) {
            iVar3 = 0;
          }
          else {
            bitVectorSet_IMPL(param_3,0xb4,4);
          }
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar3,"intrGetInterruptTable_HAL(pGpu, pIntr, &pIntrTable)",
                   "src/kernel/gpu/intr/arch/turing/intr_nonstall_tu102.c",0xe3);
      }
    }
  }
  return iVar3;
}


// ===== 0038fb50 intrDisableNonStall_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrDisableNonStall_TU102(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x1c0))();
  return;
}


// ===== 0038fb60 intrServiceNonStall_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int intrServiceNonStall_TU102(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  byte local_48;
  int local_44;
  
  lVar6 = gpuGetKernelFifoShared_IMPL();
  bitVectorClrAll_IMPL(param_3,0xb4);
  if (((param_1 == 0) || (*(char *)(param_1 + 0x44c) == '\0')) ||
     (*(char *)(param_1 + 0x450) != '\0')) {
    local_44 = 0xf;
  }
  else if (((*(char *)(param_1 + 0x44f) == '\0') && (*(char *)(param_1 + 0x451) == '\0')) &&
          (*(char *)(param_1 + 0x461) == '\0')) {
    if ((*(char *)(param_1 + 0x908) == '\0') ||
       (local_44 = 0x56, *(char *)(param_1 + 0x4913) != '\0')) {
      uVar9 = (**(code **)(param_2 + 0x2a8))(param_1,param_2);
      if (uVar9 == 0) {
        local_44 = 0;
      }
      else {
        local_44 = 0;
        uVar7 = 0;
        while( true ) {
          for (; (uVar9 & 1) == 0; uVar9 = uVar9 >> 1) {
            uVar7 = uVar7 + 1;
          }
          uVar1 = (**(code **)(param_2 + 0x268))(param_1,param_2,uVar7 >> 5,param_4);
          if ((1 << ((byte)uVar7 & 0x1f) & uVar1) != 0) {
            iVar5 = uVar7 * 2;
            iVar2 = iVar5 + 2;
            do {
              uVar1 = (**(code **)(param_2 + 600))(param_1,param_2,iVar5,param_4);
              uVar4 = (**(code **)(param_2 + 0x250))(param_1,param_2,iVar5,param_4);
              if (((uVar4 & uVar1) != 0) &&
                 (iVar3 = _intrServiceNonStallLeaf_TU102
                                    (param_1,param_2,uVar4 & uVar1,iVar5,param_3,param_4),
                 iVar3 != 0)) {
                nvAssertOkFailedNoLog
                          (iVar3,"Could not service nonstall interrupt leafs",
                           "src/kernel/gpu/intr/arch/turing/intr_nonstall_tu102.c",0x1c2);
                local_44 = iVar3;
              }
              iVar5 = iVar5 + 1;
            } while (iVar2 != iVar5);
          }
          if (uVar9 >> 1 == 0) break;
          uVar9 = uVar9 >> 1;
          uVar7 = uVar7 + 1;
        }
      }
      if ((((*(char *)(lVar6 + 0x4b2) == '\0') && (*(char *)(param_1 + 0x909) == '\0')) &&
          (*(char *)(param_1 + 0x908) == '\0')) &&
         (uVar7 = intrGetVectorFromEngineId_IMPL(param_1,param_2,4,1), uVar7 != 0xffffffff)) {
        uVar8 = uVar7 >> 5;
        uVar1 = (**(code **)(param_2 + 600))(param_1,param_2,uVar8,param_4);
        uVar4 = (**(code **)(param_2 + 0x250))(param_1,param_2,uVar8,param_4);
        local_48 = (byte)uVar7;
        uVar7 = 1 << (local_48 & 0x1f) & uVar4 & uVar1;
        if ((uVar7 != 0) &&
           (iVar5 = _intrServiceNonStallLeaf_TU102(param_1,param_2,uVar7,uVar8,param_3,param_4),
           iVar5 != 0)) {
          nvAssertOkFailedNoLog
                    (iVar5,"Could not service FIFO \'non-stall\' intr",
                     "src/kernel/gpu/intr/arch/turing/intr_nonstall_tu102.c",0x1df);
          local_44 = iVar5;
        }
      }
    }
  }
  else {
    local_44 = 0x10;
  }
  return local_44;
}


// ===== 0038fe90 intrTriggerPrivDoorbell_TU102 =====

undefined8 intrTriggerPrivDoorbell_TU102(long param_1,undefined8 param_2,undefined4 param_3)

{
  if (*(char *)(param_1 + 0x491d) != '\0') {
    regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x2200,param_3,0);
    return 0;
  }
  return 0x56;
}


// ===== 0038fee0 intrSetStallSWIntr_TU102 =====

undefined8 intrSetStallSWIntr_TU102(long param_1)

{
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1640,0x81,0);
  return 0;
}


// ===== 0038ff20 intrClearStallSWIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 intrClearStallSWIntr_TU102(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x1d0))(param_1,param_2,0x81,0);
  return 0;
}


// ===== 0038ff40 intrEnableStallSWIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrEnableStallSWIntr_TU102(long param_1,long param_2)

{
  (**(code **)(param_2 + 0x1a8))(param_1,param_2,0x81);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1608,4,0);
  return;
}


// ===== 0038ff90 intrDisableStallSWIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrDisableStallSWIntr_TU102(long param_1,long param_2)

{
  (**(code **)(param_2 + 0x1b0))(param_1,param_2,0x81);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x1610,4,0);
  return;
}


// ===== 0038ffe0 intrGetStallInterruptMode_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrGetStallInterruptMode_TU102
               (long param_1,long param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  *param_3 = 2;
  if ((*(char *)(param_1 + 0x908) == '\0') || (uVar1 = 0, *(char *)(param_1 + 0x4913) != '\0')) {
    uVar1 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,0x81,0);
  }
  *param_4 = uVar1;
  return;
}


// ===== 00390030 _intrClearLeafEnables_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _intrClearLeafEnables_TU102(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (**(code **)(param_2 + 0x2a0))();
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      iVar3 = iVar2 + 1;
      (**(code **)(param_2 + 0x278))(param_1,param_2,iVar2,0xffffffff,0);
      iVar2 = iVar3;
    } while (iVar3 != iVar1);
  }
  return;
}


// ===== 003900b0 intrStateLoad_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int intrStateLoad_TU102(long param_1,long param_2)

{
  short *psVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  short *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_58;
  short *local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar3 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_58);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"intrGetInterruptTable_HAL(pGpu, pIntr, &pIntrTable)",
               "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x5b);
    return iVar3;
  }
  _intrClearLeafEnables_TU102(param_1,param_2);
  *(undefined4 *)(param_1 + 0x8f4) = 0;
  iVar3 = vectCount_IMPL(local_58);
  uVar4 = vectAt_IMPL(local_58,iVar3 + -1);
  uVar5 = vectAt_IMPL(local_58,0);
  vectIterRange_IMPL(&local_88,local_58,uVar5,uVar4);
  local_50 = local_88;
  local_48 = local_80;
  local_40 = local_78;
  local_38 = local_70;
  local_30 = local_68;
  do {
    cVar2 = vectIterNext_IMPL(&local_50);
    psVar1 = local_50;
    while( true ) {
      local_50 = psVar1;
      if (cVar2 == '\0') {
        iVar3 = (**(code **)(param_2 + 0x248))(param_1,param_2);
        if (*(char *)(param_2 + 0x340) != '\0') {
          (**(code **)(param_2 + 0x240))(param_1,param_2);
        }
        return iVar3;
      }
      if ((*(uint *)(psVar1 + 2) != 0) &&
         (*(uint *)(param_1 + 0x8f4) = *(uint *)(param_1 + 0x8f4) | *(uint *)(psVar1 + 2),
         *psVar1 != 1)) break;
      if (*(int *)(psVar1 + 4) != -1) {
        (**(code **)(param_2 + 0x1a8))(param_1,param_2);
      }
      if (*(int *)(psVar1 + 6) == -1) break;
      nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x81,"intrStateLoad_TU102",1,
                   "NVRM: Enabling non-stall interrupt vector 0x%x\n");
      (**(code **)(param_2 + 0x1a8))(param_1,param_2,*(undefined4 *)(psVar1 + 6));
      cVar2 = vectIterNext_IMPL(&local_50);
      psVar1 = local_50;
    }
  } while( true );
}


// ===== 00390280 intrStateUnload_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 intrStateUnload_TU102(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x290))(param_1,param_2,0,0xffffffff,0);
  (**(code **)(param_2 + 0x290))(param_1,param_2,1,0xffffffff,0);
  _intrClearLeafEnables_TU102(param_1,param_2);
  return 0;
}


// ===== 003902e0 intrCacheIntrFields_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int intrCacheIntrFields_TU102(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong local_30;
  
  uVar7 = (**(code **)(param_2 + 0x2b8))(param_2);
  *(ulong *)(param_2 + 0x370) = *(ulong *)(param_2 + 0x370) | uVar7;
  uVar4 = intrGetVectorFromEngineId_IMPL(param_1,param_2,0x3c,0);
  *(undefined4 *)(param_2 + 0x364) = uVar4;
  cVar3 = gpuIsCCFeatureEnabled_IMPL(param_1);
  if ((cVar3 == '\0') || (*(char *)(param_1 + 0x4a78) == '\0')) {
    uVar4 = intrGetVectorFromEngineId_IMPL(param_1,param_2,0x3b,0);
  }
  else {
    uVar4 = intrGetVectorFromEngineId_IMPL(param_1,param_2,0xa6,0);
  }
  *(undefined4 *)(param_2 + 0x360) = uVar4;
  (**(code **)(param_2 + 0x238))(param_1,param_2);
  uVar1 = *(uint *)(param_2 + 0x360);
  uVar2 = *(uint *)(param_2 + 0x364);
  if (((uVar1 == 0xffffffff) || (uVar2 == 0xffffffff)) || (uVar1 >> 5 == uVar2 >> 5)) {
    iVar5 = intrGetSubtreeRange_IMPL(param_2,5,&local_30);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"intrGetSubtreeRange(pIntr, NV2080_INTR_CATEGORY_UVM_OWNED, &uvmOwned)",
                 "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0xe6);
      return iVar5;
    }
    uVar7 = 1L << ((byte)(uVar2 >> 6) & 0x3f);
    if (local_30 == uVar7) {
      iVar5 = intrGetSubtreeRange_IMPL(param_2,6,&local_30);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,"intrGetSubtreeRange(pIntr, NV2080_INTR_CATEGORY_UVM_SHARED, &uvmShared)",
                   "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0xf7);
        return iVar5;
      }
      if ((local_30 != 0) && ((local_30 - 1 & local_30) == 0)) {
        local_30 = -local_30 & local_30;
        cVar3 = ((local_30 & 0xaaaaaaaaaaaaaaaa) != 0 | (local_30 >> 0x20 != 0) << 5 |
                 ((local_30 & 0xffff0000ffff0000) != 0) << 4 |
                 ((local_30 & 0xff00ff00ff00ff00) != 0) << 3 |
                 ((local_30 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                ((local_30 & 0xcccccccccccccccc) != 0) * '\x02') * '\x02';
        uVar4 = (**(code **)(param_2 + 0x250))(param_1,param_2,cVar3,0);
        uVar6 = (**(code **)(param_2 + 0x250))(param_1,param_2,cVar3 + '\x01',0);
        *(ulong *)(param_2 + 0x350) = CONCAT44(uVar4,uVar6);
        uVar8 = intrGetUvmSharedLeafEnDisableMask_IMPL(param_1,param_2);
        *(undefined8 *)(param_2 + 0x358) = uVar8;
        return 0;
      }
      nvAssertFailedNoLog("ONEBITSET(uvmShared.subtreeMask)",
                          "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x102);
      return 0x40;
    }
    nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0xec,"intrCacheIntrFields_TU102",4,
                 "NVRM: UVM owned interrupt vector for access counter is in an unexpected subtree\nExpected mask = 0x%llx, actual = 0x%llx\n"
                 ,local_30,uVar7);
  }
  else {
    nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0xd4,"intrCacheIntrFields_TU102",4,
                 "NVRM: UVM interrupt vectors for replayable fault 0x%x and access counter 0x%x are in different CPU_INTR_LEAF registers\n"
                 ,uVar1,uVar2);
  }
  return 0xffff;
}


// ===== 00390620 intrCacheDispIntrVectors_TU102 =====

void intrCacheDispIntrVectors_TU102(long param_1,long param_2)

{
  undefined4 uVar1;
  
  if (*(long *)(param_1 + 0x1b80) != 0) {
    uVar1 = intrGetVectorFromEngineId_IMPL(param_1,param_2,2,0);
    *(undefined4 *)(param_2 + 0x368) = uVar1;
    *(undefined4 *)(param_2 + 0x36c) = 0xffffffff;
    return;
  }
  *(undefined4 *)(param_2 + 0x36c) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x368) = 0xffffffff;
  return;
}


// ===== 00390680 intrEnableLeaf_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrEnableLeaf_TU102(undefined8 param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = param_3 >> 5 & 0x7ffffff;
  uVar1 = (**(code **)(param_2 + 0x2a0))();
  if ((uint)uVar2 < uVar1) {
    (**(code **)(param_2 + 0x270))
              (param_1,param_2,uVar2,1 << ((byte)(param_3 & 0xffffffff) & 0x1f),0);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x14e,"intrEnableLeaf_TU102",4,
               "NVRM: Exceeding the range of INTR leaf registers. intrVector = 0x%x, Reg = 0x%x\n",
               param_3 & 0xffffffff,uVar2);
  nvAssertFailedNoLog(&DAT_00d42719,"src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x150);
  return;
}


// ===== 00390730 intrDisableLeaf_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrDisableLeaf_TU102(undefined8 param_1,long param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = param_3 >> 5 & 0x7ffffff;
  uVar1 = (**(code **)(param_2 + 0x2a0))();
  if ((uint)uVar2 < uVar1) {
    (**(code **)(param_2 + 0x278))
              (param_1,param_2,uVar2,1 << ((byte)(param_3 & 0xffffffff) & 0x1f),0);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x16c,"intrDisableLeaf_TU102",4,
               "NVRM: Exceeding the range of INTR leaf registers. intrVector = 0x%x, Reg = 0x%x\n",
               param_3 & 0xffffffff,uVar2);
  nvAssertFailedNoLog(&DAT_00d42719,"src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x16e);
  return;
}


// ===== 003907e0 intrSetStall_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrSetStall_TU102(long param_1,long param_2,int param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  ulong local_30 [2];
  
  if ((*(char *)(param_1 + 0x908) != '\0') && (*(char *)(param_1 + 0x4913) == '\0')) {
    return;
  }
  lVar2 = *(long *)(param_1 + 0x1b98);
  if (param_3 != 0) {
    if (lVar2 == 0) goto LAB_00390a1e;
    uVar1 = *(uint *)(lVar2 + 0x548);
    if ((uVar1 & 8) == 0) {
      uVar4 = 0;
      if ((uVar1 & 1) == 0) goto LAB_00390a1e;
LAB_003909f3:
      uVar1 = *(uint *)(param_2 + 0x364);
      uVar4 = uVar4 | 1 << ((byte)uVar1 & 0x1f);
    }
    else {
      uVar4 = 1 << ((byte)*(undefined4 *)(param_2 + 0x360) & 0x1f);
      if ((uVar1 & 1) != 0) goto LAB_003909f3;
      uVar1 = *(uint *)(param_2 + 0x364);
    }
    (**(code **)(param_2 + 0x270))
              (param_1,param_2,uVar1 >> 5,uVar4,param_4,*(code **)(param_2 + 0x270));
LAB_00390a1e:
    iVar5 = intrGetSubtreeRange_IMPL(param_2,6,local_30);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"intrGetSubtreeRange(pIntr, NV2080_INTR_CATEGORY_UVM_SHARED, &uvmShared)",
                 "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x1cd);
    }
    uVar6 = -local_30[0] & local_30[0];
    bVar3 = (uVar6 & 0xaaaaaaaaaaaaaaaa) != 0 | (uVar6 >> 0x20 != 0) << 5 |
            ((uVar6 & 0xffff0000ffff0000) != 0) << 4 | ((uVar6 & 0xff00ff00ff00ff00) != 0) << 3 |
            ((uVar6 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 | ((uVar6 & 0xcccccccccccccccc) != 0) * '\x02';
    if ((local_30[0] == 0) || ((local_30[0] - 1 & local_30[0]) != 0)) {
      nvAssertFailedNoLog("ONEBITSET(uvmShared.subtreeMask)",
                          "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x1d7);
    }
    uVar6 = *(ulong *)(param_2 + 0x350);
    if (uVar6 >> 0x20 != 0) {
      (**(code **)(param_2 + 0x270))
                (param_1,param_2,bVar3 * '\x02',uVar6 >> 0x20,param_4,*(code **)(param_2 + 0x270));
      uVar6 = *(ulong *)(param_2 + 0x350);
    }
    if ((int)uVar6 != 0) {
      (**(code **)(param_2 + 0x270))
                (param_1,param_2,bVar3 * '\x02' + '\x01',uVar6 & 0xffffffff,param_4);
    }
    uVar6 = (**(code **)(param_2 + 0x2a8))(param_1,param_2);
    uVar6 = ~uVar6;
    if ((int)uVar6 != 0) {
      (**(code **)(param_2 + 0x288))
                (param_1,param_2,0,uVar6 & 0xffffffff,param_4,*(code **)(param_2 + 0x288));
    }
    if (uVar6 >> 0x20 == 0) {
      return;
    }
    (**(code **)(param_2 + 0x288))
              (param_1,param_2,1,uVar6 >> 0x20,param_4,*(code **)(param_2 + 0x288));
    return;
  }
  if (lVar2 == 0) goto LAB_00390865;
  uVar1 = *(uint *)(lVar2 + 0x548);
  if ((uVar1 & 8) == 0) {
    uVar4 = 0;
    if ((uVar1 & 1) == 0) goto LAB_00390865;
LAB_00390840:
    uVar4 = uVar4 | 1 << ((byte)*(uint *)(param_2 + 0x364) & 0x1f);
  }
  else {
    uVar4 = 1 << ((byte)*(undefined4 *)(param_2 + 0x360) & 0x1f);
    if ((uVar1 & 1) != 0) goto LAB_00390840;
  }
  (**(code **)(param_2 + 0x278))
            (param_1,param_2,*(uint *)(param_2 + 0x364) >> 5,uVar4,param_4,
             *(code **)(param_2 + 0x278));
LAB_00390865:
  iVar5 = intrGetSubtreeRange_IMPL(param_2,6,local_30);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"intrGetSubtreeRange(pIntr, NV2080_INTR_CATEGORY_UVM_SHARED, &uvmShared)",
               "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x229);
  }
  uVar6 = -local_30[0] & local_30[0];
  bVar3 = (uVar6 & 0xaaaaaaaaaaaaaaaa) != 0 | (uVar6 >> 0x20 != 0) << 5 |
          ((uVar6 & 0xffff0000ffff0000) != 0) << 4 | ((uVar6 & 0xff00ff00ff00ff00) != 0) << 3 |
          ((uVar6 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 | ((uVar6 & 0xcccccccccccccccc) != 0) * '\x02';
  if ((local_30[0] == 0) || ((local_30[0] - 1 & local_30[0]) != 0)) {
    nvAssertFailedNoLog("ONEBITSET(uvmShared.subtreeMask)",
                        "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x233);
  }
  if (*(char *)(param_1 + 0x4918) == '\0') {
    (**(code **)(param_2 + 0x278))
              (param_1,param_2,bVar3 * '\x02',0xffffffff,param_4,*(code **)(param_2 + 0x278));
    (**(code **)(param_2 + 0x278))(param_1,param_2,bVar3 * '\x02' + '\x01',0xffffffff,param_4);
  }
  else {
    uVar6 = *(ulong *)(param_2 + 0x358);
    if ((uVar6 >> 0x20 != 0) && (*(int *)(param_2 + 0x354) != 0)) {
      (**(code **)(param_2 + 0x278))
                (param_1,param_2,bVar3 * '\x02',uVar6 >> 0x20,param_4,*(code **)(param_2 + 0x278));
      uVar6 = *(ulong *)(param_2 + 0x358);
    }
    if (((int)uVar6 != 0) && (*(int *)(param_2 + 0x350) != 0)) {
      (**(code **)(param_2 + 0x278))
                (param_1,param_2,bVar3 * '\x02' + '\x01',uVar6 & 0xffffffff,param_4);
    }
  }
  uVar6 = *(ulong *)(param_2 + 0x370);
  if ((int)uVar6 != 0) {
    (**(code **)(param_2 + 0x290))(param_1,param_2,0,uVar6,param_4,*(code **)(param_2 + 0x290));
    uVar6 = *(ulong *)(param_2 + 0x370);
  }
  if (uVar6 >> 0x20 == 0) {
    return;
  }
  (**(code **)(param_2 + 0x290))(param_1,param_2,1,uVar6 >> 0x20,param_4);
  return;
}


// ===== 00390d10 intrClearLeafVector_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrClearLeafVector_TU102(undefined8 param_1,long param_2,uint param_3,undefined8 param_4)

{
  (**(code **)(param_2 + 0x280))(param_1,param_2,param_3 >> 5,1 << ((byte)param_3 & 0x1f),param_4);
  return;
}


// ===== 00390d40 intrIsPending_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
intrIsPending_TU102(undefined8 param_1,long param_2,ushort param_3,int param_4,undefined8 param_5)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 local_50 [32];
  
  if (0xb3 < param_3) {
    nvAssertFailedNoLog("engIdx < MC_ENGINE_IDX_MAX","src/kernel/gpu/intr/arch/turing/intr_tu102.c",
                        0x2ac);
  }
  if (param_4 == -1) {
    lVar3 = intrGetInterruptTableEntryFromEngineId_IMPL(param_1,param_2,param_3,0);
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pEntry != NULL","src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x2b6);
      return 0;
    }
    param_4 = *(int *)(lVar3 + 8);
    if (param_4 == -1) goto LAB_00390d95;
  }
  cVar1 = (**(code **)(param_2 + 0x1e0))
                    (param_1,param_2,param_4,param_5,*(code **)(param_2 + 0x1e0));
  if (cVar1 != '\0') {
    return 1;
  }
LAB_00390d95:
  bitVectorClrAll_IMPL(local_50,0xb4);
  (**(code **)(param_2 + 0x338))(param_1,param_2,local_50,0,param_3,param_5);
  uVar2 = bitVectorTest_IMPL(local_50,0xb4,param_3);
  return uVar2;
}


// ===== 00390e80 intrIsVectorPending_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool intrIsVectorPending_TU102(undefined8 param_1,long param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 600))(param_1,param_2,param_3 >> 5);
  return (uVar1 >> (param_3 & 0x1f) & 1) != 0;
}


// ===== 00390eb0 intrGetLocklessVectorsInRmSubtree_TU102 =====

void intrGetLocklessVectorsInRmSubtree_TU102(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 uVar1;
  
  *param_3 = 0xffffffffffffffff;
  uVar1 = intrGetVectorFromEngineId_IMPL(param_1,param_2,0x3d,0);
  *(undefined4 *)param_3 = uVar1;
  if (*(char *)(param_1 + 0x908) != '\0') {
    return;
  }
  uVar1 = intrGetVectorFromEngineId_IMPL(param_1,param_2,4,1);
  *(undefined4 *)((long)param_3 + 4) = uVar1;
  return;
}


// ===== 00390f20 intrGetPendingStallEngines_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int intrGetPendingStallEngines_TU102
              (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong extraout_RDX;
  ulong uVar7;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  int iVar8;
  ulong uStack_f0;
  undefined2 *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_a8;
  undefined2 *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  uint local_78 [18];
  
  uVar2 = (**(code **)(param_2 + 0x298))();
  if (0x10 < uVar2) {
    nvAssertFailedNoLog("numIntrLeaves <= NV_MAX_INTR_LEAVES",
                        "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x34e);
  }
  uVar4 = (**(code **)(param_2 + 0x2b0))(param_2);
  portMemSet(local_78,0,(ulong)uVar2 << 2);
  bitVectorClrAll_IMPL(param_3,0xb4);
  if ((*(char *)(param_1 + 0x908) == '\0') || (iVar8 = 0, *(char *)(param_1 + 0x4913) != '\0')) {
    iVar8 = (**(code **)(param_2 + 0x218))(param_1,param_2,local_78,param_4);
    if (iVar8 == 0) {
      iVar8 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_a8);
      if (iVar8 == 0) {
        iVar3 = vectCount_IMPL(local_a8);
        uVar5 = vectAt_IMPL(local_a8,iVar3 + -1);
        uVar6 = vectAt_IMPL(local_a8,0);
        vectIterRange_IMPL(&local_d8,local_a8,uVar6,uVar5);
        local_a0 = local_d8;
        local_98 = local_d0;
        local_90 = local_c8;
        local_88 = local_c0;
        local_80 = local_b8;
        uVar7 = extraout_RDX;
        while( true ) {
          uStack_f0 = 0x39108f;
          cVar1 = vectIterNext_IMPL(&local_a0,&local_a0,uVar7);
          if (cVar1 == '\0') break;
          uVar2 = *(uint *)(local_a0 + 4);
          uVar7 = extraout_RDX_00;
          if (uVar2 != 0xffffffff) {
            if ((uVar4 >> ((ulong)(uVar2 >> 6) & 0x3f) & 1) == 0) {
              nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x37a,
                           "intrGetPendingStallEngines_TU102",4,
                           "NVRM: MC_ENGINE_IDX %u has invalid stall intr vector %u\n",*local_a0,
                           uVar2);
              uVar7 = uStack_f0;
            }
            else {
              uVar7 = (ulong)(uVar2 >> 5);
              if ((local_78[uVar2 >> 5] & 1 << ((byte)uVar2 & 0x1f)) != 0) {
                bitVectorSet_IMPL(param_3,0xb4,*local_a0);
                uVar7 = extraout_RDX_01;
              }
            }
          }
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar8,"intrGetInterruptTable_HAL(pGpu, pIntr, &pIntrTable)",
                   "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x35d);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar8,"intrGetLeafStatus_HAL(pGpu, pIntr, intrLeafValues, pThreadState)",
                 "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x35c);
    }
  }
  return iVar8;
}


// ===== 00391180 intrGetAuxiliaryPendingStall_TU102 =====

void intrGetAuxiliaryPendingStall_TU102
               (long param_1,undefined8 param_2,undefined8 param_3,char param_4,short param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  
  lVar2 = *(long *)(param_1 + 0x1b98);
  intrGetAuxiliaryPendingStall_GP100();
  if ((param_4 != '\0' || param_5 == 0x2e) && (lVar2 != 0)) {
    uVar1 = *(uint *)(lVar2 + 0x548);
    piVar5 = (int *)kgmmuGetFatalFaultIntrPendingState_IMPL(lVar2,0);
    iVar4 = *piVar5;
    do {
      iVar3 = iVar4;
      LOCK();
      iVar4 = *piVar5;
      bVar6 = iVar3 == iVar4;
      if (bVar6) {
        *piVar5 = iVar3;
        iVar4 = iVar3;
      }
      UNLOCK();
    } while (!bVar6);
    if (iVar3 != 0) {
      bitVectorSet_IMPL(param_3,0xb4,0x3d);
    }
    if ((uVar1 & 8) == 0) {
      bitVectorClr_IMPL(param_3,0xb4,0x3b);
    }
    if ((uVar1 & 1) == 0) {
      bitVectorClr_IMPL(param_3,0xb4,0x3c);
      return;
    }
  }
  return;
}


// ===== 00391250 intrCheckAndServiceNonReplayableFault_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint intrCheckAndServiceNonReplayableFault_TU102(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  bool bVar6;
  undefined1 local_30 [32];
  
  (**(code **)(param_2 + 0x330))(param_1,param_2,local_30,param_3);
  cVar2 = bitVectorTest_IMPL(local_30,0xb4,0x3d);
  uVar5 = 0;
  if (cVar2 != '\0') {
    lVar1 = *(long *)(param_1 + 0x1b98);
    piVar4 = (int *)kgmmuGetFatalFaultIntrPendingState_IMPL(lVar1,0);
    LOCK();
    bVar6 = *piVar4 == 1;
    if (bVar6) {
      *piVar4 = 0;
    }
    UNLOCK();
    uVar5 = (uint)bVar6;
    if (bVar6) {
      uVar3 = (**(code **)(lVar1 + 0x4b8))(param_1,lVar1);
      uVar5 = 0;
      if (uVar3 != 0) {
        nvAssertOkFailedNoLog
                  (uVar3,"Failed to service MMU non-replayable fault",
                   "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x3f4);
        return uVar3;
      }
    }
  }
  return uVar5;
}


// ===== 00391320 intrRetriggerTopLevel_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrRetriggerTopLevel_TU102(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x449) != '\0') {
    uVar1 = (**(code **)(param_2 + 0x2a8))();
  }
  uVar2 = intrGetIntrTopCategoryMask_IMPL(param_2,5);
  uVar3 = intrGetIntrTopCategoryMask_IMPL(param_2,6);
  uVar3 = uVar3 | uVar1 | uVar2;
  if (uVar3 == 0) {
    return;
  }
  osGpuWriteReg032(param_1,*(int *)(param_1 + 0x3a64) + 0x1610,uVar3);
  osGpuWriteReg032(param_1,*(int *)(param_1 + 0x3a64) + 0x1608,uVar3);
  return;
}


// ===== 003913c0 intrGetLeafStatus_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 intrGetLeafStatus_TU102(undefined8 param_1,long param_2,long param_3,undefined8 param_4)

{
  undefined4 uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = (**(code **)(param_2 + 0x2b0))(param_2);
  if (uVar2 == 0) {
    return 0;
  }
  uVar4 = 0;
  do {
    if ((uVar2 & 1) != 0) {
      if (*(char *)(param_2 + 0x342) == '\0') {
        uVar3 = uVar4;
        do {
          uVar1 = (**(code **)(param_2 + 600))(param_1,param_2,uVar3 & 0xffffffff,param_4);
          *(undefined4 *)(param_3 + uVar3 * 4) = uVar1;
          uVar3 = uVar3 + 1;
        } while (uVar3 != uVar4 + 2);
      }
      else {
        uVar1 = (**(code **)(param_2 + 600))(param_1,param_2,uVar4 & 0xffffffff,param_4);
        *(undefined4 *)(param_3 + uVar4 * 4) = uVar1;
      }
      if (uVar2 >> 1 == 0) {
        return 0;
      }
    }
    uVar2 = uVar2 >> 1;
    uVar4 = uVar4 + 2;
  } while( true );
}


// ===== 003914b0 intrGetPendingLowLatencyHwDisplayIntr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
intrGetPendingLowLatencyHwDisplayIntr_TU102
          (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  
  bitVectorClrAll_IMPL(param_3,0xb4);
  if (*(int *)(param_1 + 0x4b34) == 3) {
    return 0x11;
  }
  if ((*(char *)(param_1 + 0x44c) != '\0') && (*(char *)(param_1 + 0x450) == '\0')) {
    if (*(int *)(param_2 + 0x368) != -1) {
      cVar1 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,*(int *)(param_2 + 0x368),param_4);
      if (cVar1 != '\0') {
        bitVectorSet_IMPL(param_3,0xb4,2);
      }
    }
    return 0;
  }
  return 0xf;
}


// ===== 00391570 intrSetDisplayInterruptEnable_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrSetDisplayInterruptEnable_TU102
               (undefined8 param_1,long param_2,char param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x368);
  if (uVar1 == 0xffffffff) {
    return;
  }
  if (param_3 != '\0') {
    (**(code **)(param_2 + 0x270))(param_1,param_2,uVar1 >> 5);
    return;
  }
  (**(code **)(param_2 + 0x278))(param_1,param_2,uVar1 >> 5,1 << ((byte)uVar1 & 0x1f),param_4);
  return;
}


// ===== 003915d0 intrDumpState_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrDumpState_TU102(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  undefined2 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_58;
  undefined2 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar2 = (**(code **)(param_2 + 0x2a0))();
  nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x4e3,"intrDumpState_TU102",1,
               "NVRM: Interrupt registers:\n");
  uVar3 = (**(code **)(param_2 + 0x260))(param_1,param_2,0,0);
  nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x4e6,"intrDumpState_TU102",1,
               "NVRM: INTR_TOP_EN_SET(%u)=0x%x\n",0,uVar3);
  if (iVar2 != 0) {
    iVar5 = 0;
    do {
      uVar3 = (**(code **)(param_2 + 0x250))(param_1,param_2,iVar5,0);
      iVar6 = iVar5 + 1;
      nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x4ec,"intrDumpState_TU102",1,
                   "NVRM: INTR_LEAF_EN_SET(%u)=0x%x\n",iVar5,uVar3);
      iVar5 = iVar6;
    } while (iVar6 != iVar2);
  }
  nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x4f0,"intrDumpState_TU102",1,
               "NVRM: MC Interrupt table:\n");
  iVar2 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_58);
  if (iVar2 == 0) {
    iVar2 = vectCount_IMPL(local_58);
    uVar3 = vectAt_IMPL(local_58,iVar2 + -1);
    uVar4 = vectAt_IMPL(local_58,0);
    vectIterRange_IMPL(&local_88,local_58,uVar4,uVar3);
    local_50 = local_88;
    local_48 = local_80;
    local_40 = local_78;
    local_38 = local_70;
    local_30 = local_68;
    iVar2 = 0;
    while( true ) {
      cVar1 = vectIterNext_IMPL(&local_50);
      if (cVar1 == '\0') break;
      nvDbg_Printf("src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x4f9,"intrDumpState_TU102",1,
                   "NVRM: %2u: mcEngineIdx=%-4u intrVector=%-10u intrVectorNonStall=%-10u\n",iVar2,
                   *local_50,*(undefined4 *)(local_50 + 4),*(undefined4 *)(local_50 + 6));
      iVar2 = iVar2 + 1;
    }
    return;
  }
  nvAssertFailedNoLog("intrGetInterruptTable_HAL(pGpu, pIntr, &pIntrTable) == NV_OK",
                      "src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x4f1);
  return;
}


// ===== 00391800 intrGetNumLeaves_TU102 =====

undefined8 intrGetNumLeaves_TU102(void)

{
  return 8;
}


// ===== 00391810 intrGetLeafSize_TU102 =====

undefined8 intrGetLeafSize_TU102(void)

{
  return 8;
}


// ===== 00391820 intrGetIntrTopNonStallMask_TU102 =====

long intrGetIntrTopNonStallMask_TU102(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = intrGetIntrTopCategoryMask_IMPL(param_2,2);
  if (lVar1 != 0) {
    return lVar1;
  }
  nvAssertFailedNoLog("mask != 0","src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x554);
  return 0;
}


// ===== 00391870 intrDecodeStallIntrEn_TU102 =====

byte intrDecodeStallIntrEn_TU102(long param_1,undefined8 param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x8f4);
  if (uVar2 == 0) {
    uVar2 = 0xffffffff;
  }
  param_3 = param_3 & uVar2;
  bVar1 = 1;
  if ((param_3 != 0x7fffffff) && (bVar1 = 2, param_3 != 0x80000000)) {
    bVar1 = -(param_3 != 0) & 3;
  }
  return bVar1;
}


// ===== 003918b0 intrGetIntrTopLegacyStallMask_TU102 =====

ulong intrGetIntrTopLegacyStallMask_TU102(undefined8 param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar1 = intrGetIntrTopCategoryMask_IMPL(param_1,1);
  uVar2 = intrGetIntrTopCategoryMask_IMPL(param_1,5);
  uVar3 = intrGetIntrTopCategoryMask_IMPL(param_1,6);
  uVar3 = uVar3 | uVar1 | uVar2;
  if (uVar3 != 0) {
    return uVar3;
  }
  nvAssertFailedNoLog("ret != 0","src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x589);
  return 0;
}


// ===== 00391930 intrGetIntrTopLockedMask_TU102 =====

long intrGetIntrTopLockedMask_TU102(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = intrGetIntrTopCategoryMask_IMPL(param_1,1);
  if (lVar1 != 0) {
    return lVar1;
  }
  nvAssertFailedNoLog("ret != 0","src/kernel/gpu/intr/arch/turing/intr_tu102.c",0x596);
  return 0;
}


// ===== 00391980 _intrLogLongRunningInterrupts =====

void _intrLogLongRunningInterrupts(long param_1)

{
  int *piVar1;
  int iVar2;
  long local_30 [2];
  
  iVar2 = 0;
  piVar1 = (int *)(param_1 + 0x1560);
  osGetPerformanceCounter(local_30);
  do {
    if ((*piVar1 != 0) && (10000000000 < (ulong)(local_30[0] - *(long *)(piVar1 + 4)))) {
      nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x5a1,"_intrLogLongRunningInterrupts",3,
                   "NVRM: %u long-running interrupts (%llu ns or slower) from engine %u, longest taking %llu ns\n"
                   ,*piVar1,1000000,iVar2,*(undefined8 *)(piVar1 + 2));
      *piVar1 = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      *(long *)(piVar1 + 4) = local_30[0];
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 6;
  } while (iVar2 != 0xb4);
  return;
}


// ===== 00391a50 intrReenableIntrMask_IMPL.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrReenableIntrMask_IMPL_part_0(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  uVar1 = rmIntrMaskLockAcquire();
  *(uint *)(param_2 + 0x1508) = *(uint *)(param_2 + 0x1508) & 0xfffffffe;
  if (*(char *)(param_2 + 0x344) != '\0') {
    (**(code **)(param_2 + 0x230))(param_1,param_2,1,0);
  }
  (**(code **)(param_2 + 0x318))(param_1,param_2,param_2 + 0x1510,0);
  if (*(char *)(param_2 + 0x1554) == '\0') {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x16c,"intrGetIntrEn_IMPL",1,
                 "NVRM: intrGetIntrEn: Returning interrupt disabled. Interrupts disabled in the HAL\n"
                );
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x1540);
  }
  (**(code **)(param_2 + 800))(param_1,param_2,uVar2,0);
  rmIntrMaskLockRelease(param_1,uVar1);
  return;
}


// ===== 00391b20 _intrServiceStallCommonCheckBegin.isra.0 =====

int _intrServiceStallCommonCheckBegin_isra_0(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = regRead032(param_1 + 0x3a18,0,0,0,0);
  if (iVar1 == -1) {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x634,"_intrServiceStallCommonCheckBegin",4,
                 "NVRM: Failed GPU reg read : 0x%x. Check whether GPU is present on the bus\n",
                 0xffffffff);
  }
  if ((((param_1 == 0) || (*(char *)(param_1 + 0x44c) == '\0')) ||
      (*(char *)(param_1 + 0x450) != '\0')) ||
     (((*(char *)(param_1 + 0x44f) != '\0' || (*(char *)(param_1 + 0x451) != '\0')) ||
      (*(char *)(param_1 + 0x461) != '\0')))) {
    iVar1 = 0xf;
  }
  else {
    iVar1 = resservSwapTlsCallContext(param_2,0);
    if (iVar1 == 0) {
      if (stuckIntrGeneration != -1) {
        stuckIntrGeneration = stuckIntrGeneration + 1;
        return 0;
      }
      stuckIntrGeneration = 0;
      portMemSet(stuckIntr,0,0x870);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,"resservSwapTlsCallContext(ppOldContext, NULL)","src/kernel/gpu/intr/intr.c",
                 0x640);
    }
  }
  return iVar1;
}


// ===== 00391c40 intrGetSubtreeRange_IMPL =====

undefined8 intrGetSubtreeRange_IMPL(long param_1,uint param_2,undefined8 *param_3)

{
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pRange != NULL","src/kernel/gpu/intr/intr.c",0x6b);
  }
  else {
    if (param_2 < 7) {
      *param_3 = *(undefined8 *)(param_1 + 0x1490 + (ulong)param_2 * 8);
      return 0;
    }
    nvAssertFailedNoLog("category < NV2080_INTR_CATEGORY_ENUM_COUNT","src/kernel/gpu/intr/intr.c",
                        0x6c);
  }
  return 0x1f;
}


// ===== 00391cb0 subdeviceCtrlCmdMcServiceInterrupts_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdMcServiceInterrupts_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined8 uStack_80;
  int local_64;
  long local_60;
  long local_58;
  undefined1 local_50 [32];
  
  bVar11 = false;
  lVar8 = *(long *)(param_1 + 0x158);
  lVar1 = *(long *)(lVar8 + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1c20);
  if (*(long *)(lVar1 + 0x1bc0) != 0) {
    cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    bVar11 = cVar6 != '\0';
    lVar8 = *(long *)(param_1 + 0x158);
  }
  uVar3 = *(undefined8 *)(lVar8 + 0xe8);
  bitVectorClrAll_IMPL(local_50,0xb4);
  if ((*(char *)(lVar1 + 0x908) == '\0') &&
     (uStack_80 = extraout_RDX, *(char *)(lVar1 + 0x909) == '\0')) {
LAB_00391d32:
    if (*param_2 == 0xffffffff) {
      bitVectorSetAll_IMPL(local_50,0xb4,uStack_80);
    }
    else {
      uVar9 = *param_2 & 1;
      if (uVar9 != 0) {
        if (bVar11) {
          uVar5 = *(undefined8 *)(lVar1 + 0x1bc0);
          iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar5,uVar3,&local_60);
          if (iVar7 != 0) {
            nvAssertOkFailedNoLog
                      (iVar7,
                       "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                       "src/kernel/gpu/intr/intr.c",0xf7);
            return iVar7;
          }
          uVar10 = 0;
          if ((local_58 != 0) ||
             (uVar9 = kmigmgrCountEnginesOfType_IMPL(local_60 + 0x98,1), uVar9 != 0)) {
            do {
              uVar10 = uVar10 + 1;
              iVar7 = kmigmgrGetLocalToGlobalEngineType_IMPL
                                (lVar1,uVar5,local_60,local_58,uVar10,&local_64);
              if (iVar7 != 0) {
                nvAssertOkFailedNoLog
                          (iVar7,
                           "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(i), &globalRmEngineType)"
                           ,"src/kernel/gpu/intr/intr.c",0x10b);
              }
              bitVectorSet_IMPL(local_50,0xb4,local_64 + 0x53);
            } while (uVar10 != uVar9);
          }
        }
        else {
          bitVectorSet_IMPL(local_50,0xb4,0x54);
        }
      }
    }
    iVar7 = 0;
    (**(code **)(lVar2 + 0x300))(lVar1,lVar2,local_50,1);
  }
  else {
    lVar8 = resservGetTlsCallContext();
    puVar4 = *(undefined4 **)(lVar8 + 0x48);
    if (*(char *)(lVar1 + 0x4b5) != '\0') {
      (**(code **)(lVar2 + 0x308))(lVar1,lVar2,0x32,1);
    }
    uStack_80 = 0x391d9a;
    lVar8 = gpuGetRpc(lVar1);
    if (lVar8 == 0) {
      iVar7 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/intr/intr.c",0xdb);
    }
    else {
      if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
        iVar7 = rpcDmaControl_wrapper
                          (lVar1,lVar8,*puVar4,puVar4[1],puVar4[2],*(undefined8 *)(puVar4 + 4),
                           puVar4[6]);
      }
      else {
        iVar7 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
        uStack_80 = extraout_RDX_00;
      }
      if (iVar7 == 0) goto LAB_00391d32;
    }
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0xdf,"subdeviceCtrlCmdMcServiceInterrupts_IMPL",4,
                 "NVRM: NVRM_RPC: NV2080_CTRL_CMD_MC_SERVICE_INTERRUPTS failed with error 0x%x\n",
                 iVar7);
  }
  return iVar7;
}


// ===== 00391fc0 intrGetGmmuInterrupts_IMPL =====

void intrGetGmmuInterrupts_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  if ((*(char *)(param_1 + 0x4a2) != '\0') || (lVar1 == 0)) {
    return;
  }
  cVar2 = bitVectorTest_IMPL(param_3,0xb4,0x2e);
  if (cVar2 == '\0') {
    piVar5 = (int *)kgmmuGetFatalFaultIntrPendingState_IMPL(lVar1,0);
    iVar4 = *piVar5;
    do {
      iVar3 = iVar4;
      LOCK();
      iVar4 = *piVar5;
      bVar6 = iVar3 == iVar4;
      if (bVar6) {
        *piVar5 = iVar3;
        iVar4 = iVar3;
      }
      UNLOCK();
    } while (!bVar6);
    if (iVar3 != 0) {
      bitVectorSet_IMPL(param_3,0xb4,0x2e);
      return;
    }
  }
  return;
}


// ===== 00392050 intrSetIntrEn_IMPL =====

void intrSetIntrEn_IMPL(long param_1,uint param_2)

{
  if (*(char *)(param_1 + 0x1554) == '\0') {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x15e,"intrSetIntrEn_IMPL",1,
                 "NVRM: intrSetIntrEn: set interrupt refused since interrupts are disabled in the HAL\n"
                );
    return;
  }
  if (param_2 < 4) {
    *(uint *)(param_1 + 0x1540) = param_2;
    return;
  }
  nvAssertFailedNoLog("intrEn0 <= INTERRUPT_TYPE_MAX","src/kernel/gpu/intr/intr.c",0x163);
  *(uint *)(param_1 + 0x1540) = param_2;
  return;
}


// ===== 003920e0 intrGetIntrEn_IMPL =====

undefined4 intrGetIntrEn_IMPL(long param_1)

{
  if (*(char *)(param_1 + 0x1554) != '\0') {
    return *(undefined4 *)(param_1 + 0x1540);
  }
  nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x16c,"intrGetIntrEn_IMPL",1,
               "NVRM: intrGetIntrEn: Returning interrupt disabled. Interrupts disabled in the HAL\n"
              );
  return 0;
}


// ===== 00392130 intrGetIntrMaskFlags_IMPL =====

undefined4 intrGetIntrMaskFlags_IMPL(long param_1)

{
  return *(undefined4 *)(param_1 + 0x1508);
}


// ===== 00392140 intrSetIntrMaskFlags_IMPL =====

void intrSetIntrMaskFlags_IMPL(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1508) = param_2;
  return;
}


// ===== 00392150 intrQueueInterruptBasedDpc_IMPL =====

void intrQueueInterruptBasedDpc_IMPL(undefined8 param_1,long param_2,undefined2 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)portMemAllocNonPaged(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined8 *)(puVar1 + 8) = 0;
    *puVar1 = 0;
    bitVectorClrAll_IMPL(puVar1 + 2,0xb4);
    bitVectorSet_IMPL(puVar1 + 2,0xb4,param_3);
    if (*(long *)(param_2 + 0x14f0) == 0) {
      *(undefined4 **)(param_2 + 0x14f8) = puVar1;
      *(undefined4 **)(param_2 + 0x14f0) = puVar1;
    }
    else {
      *(undefined4 **)(*(long *)(param_2 + 0x14f8) + 0x20) = puVar1;
      *(undefined4 **)(param_2 + 0x14f8) = puVar1;
    }
    *(int *)(param_2 + 0x14e8) = *(int *)(param_2 + 0x14e8) + 1;
    return;
  }
  nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x1cb,"intrQueueInterruptBasedDpc_IMPL",4,
               "NVRM: Cannot allocate memory for the DPC queue entry\n");
  return;
}


// ===== 00392240 intrServiceStallListDevice_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrServiceStallListDevice_IMPL
               (long param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  char cVar1;
  
  if (param_4 != '\0') {
    if (*(char *)(*(long *)(param_1 + 0x1c20) + 0x1554) == '\0') {
      nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x16c,"intrGetIntrEn_IMPL",1,
                   "NVRM: intrGetIntrEn: Returning interrupt disabled. Interrupts disabled in the HAL\n"
                  );
      return;
    }
    if (*(int *)(*(long *)(param_1 + 0x1c20) + 0x1540) == 0) {
      return;
    }
  }
  cVar1 = gpuIsGpuFullPower_IMPL();
  if (cVar1 != '\0') {
    (**(code **)(*(long *)(param_1 + 0x1c20) + 0x300))
              (param_1,*(long *)(param_1 + 0x1c20),param_3,0);
    return;
  }
  return;
}


// ===== 003922e0 intrServiceStallListAllGpusCond_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrServiceStallListAllGpusCond_IMPL
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,char param_4)

{
  long lVar1;
  char cVar2;
  long lVar3;
  undefined1 local_34 [4];
  undefined4 local_30;
  undefined4 local_2c;
  
  cVar2 = rmGpuLockIsOwner();
  if (cVar2 == '\0') {
    intrServiceStallListDevice_IMPL(param_1,param_2,param_3,param_4);
    return;
  }
  gpumgrGetGpuAttachInfo(local_34,&local_30);
  local_2c = 0;
  do {
    while( true ) {
      do {
        lVar3 = gpumgrGetNextGpu(local_30,&local_2c);
        if (lVar3 == 0) {
          return;
        }
        lVar1 = *(long *)(lVar3 + 0x1c20);
      } while (((lVar1 == 0) || (*(int *)(lVar3 + 0x7b4) == 0x20)) ||
              ((*(char *)(lVar3 + 0x4916) == '\0' && (*(char *)(lVar3 + 0x4918) == '\0'))));
      if (param_4 == '\0') break;
      if (*(char *)(lVar1 + 0x1554) == '\0') {
        nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x16c,"intrGetIntrEn_IMPL",1,
                     "NVRM: intrGetIntrEn: Returning interrupt disabled. Interrupts disabled in the HAL\n"
                    );
      }
      else if (*(int *)(lVar1 + 0x1540) != 0) break;
    }
    cVar2 = gpuIsGpuFullPower_IMPL(lVar3);
    if (((cVar2 != '\0') && (*(char *)(lVar3 + 0x44c) != '\0')) &&
       (*(char *)(lVar3 + 0x450) == '\0')) {
      (**(code **)(lVar1 + 0x300))(lVar3,lVar1,param_3,0);
    }
  } while( true );
}


// ===== 00392420 intrGetInterruptTableEntryFromEngineId_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

short * intrGetInterruptTableEntryFromEngineId_IMPL(undefined8 param_1,long param_2,short param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  short *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_48;
  short *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  
  iVar2 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_48);
  if (iVar2 == 0) {
    iVar2 = vectCount_IMPL(local_48);
    uVar3 = vectAt_IMPL(local_48,iVar2 + -1);
    uVar4 = vectAt_IMPL(local_48,0);
    vectIterRange_IMPL(&local_78,local_48,uVar4,uVar3);
    local_40 = local_78;
    local_38 = local_70;
    local_30 = local_68;
    local_28 = local_60;
    local_20 = local_58;
    while( true ) {
      cVar1 = vectIterNext_IMPL(&local_40);
      if (cVar1 == '\0') break;
      if (*local_40 == param_3) {
        return local_40;
      }
    }
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x266,"intrGetInterruptTableEntryFromEngineId_IMPL",4,
                 "NVRM: Could not find the specified engine Id %u\n",param_3);
  }
  else {
    nvAssertOkFailedNoLog(iVar2,"Failed to get interrupt table","src/kernel/gpu/intr/intr.c",0x259);
  }
  return (short *)0x0;
}


// ===== 00392530 intrGetVectorFromEngineId_IMPL =====

int intrGetVectorFromEngineId_IMPL
              (undefined8 param_1,undefined8 param_2,undefined2 param_3,char param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = intrGetInterruptTableEntryFromEngineId_IMPL(param_1,param_2,param_3,param_4);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pEntry != NULL","src/kernel/gpu/intr/intr.c",0x286);
    return -1;
  }
  iVar1 = *(int *)(lVar2 + 0xc);
  if (param_4 == '\0') {
    iVar1 = *(int *)(lVar2 + 8);
  }
  if (iVar1 == -1) {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x28b,"intrGetVectorFromEngineId_IMPL",4,
                 "NVRM: mcEngineIdx %d with bNonStall = %d has invalid vector\n",param_3,param_4);
    nvAssertFailedNoLog("intrVector != NV_INTR_VECTOR_INVALID","src/kernel/gpu/intr/intr.c",0x28e);
  }
  return iVar1;
}


// ===== 00392620 intrConvertEngineMaskToPmcIntrMask_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint intrConvertEngineMaskToPmcIntrMask_IMPL(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined2 *puVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined2 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_58;
  undefined2 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  iVar3 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_58);
  if (iVar3 != 0) {
    nvAssertFailedNoLog("pmcIntrMask","src/kernel/gpu/intr/intr.c",0x2ac);
    return 0;
  }
  uVar6 = 0;
  iVar3 = vectCount_IMPL(local_58);
  uVar4 = vectAt_IMPL(local_58,iVar3 + -1);
  uVar5 = vectAt_IMPL(local_58,0);
  vectIterRange_IMPL(&local_88,local_58,uVar5,uVar4);
  local_50 = local_88;
  local_48 = local_80;
  local_40 = local_78;
  local_38 = local_70;
  local_30 = local_68;
  do {
    cVar2 = vectIterNext_IMPL(&local_50);
    puVar1 = local_50;
    while( true ) {
      if (cVar2 == '\0') {
        return uVar6;
      }
      local_50 = puVar1;
      cVar2 = bitVectorTest_IMPL(param_3,0xb4,*puVar1);
      if (cVar2 == '\0') break;
      uVar6 = uVar6 | *(uint *)(puVar1 + 2);
      cVar2 = vectIterNext_IMPL(&local_50);
      puVar1 = local_50;
    }
  } while( true );
}


// ===== 00392740 intrConvertPmcIntrMaskToEngineMask_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrConvertPmcIntrMaskToEngineMask_IMPL
               (undefined8 param_1,long param_2,uint param_3,long param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined2 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_58;
  undefined2 *local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  if (param_4 == 0) {
    nvAssertFailedNoLog("pEngines != NULL","src/kernel/gpu/intr/intr.c",0x2d0);
    return;
  }
  iVar2 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_58);
  if (iVar2 == 0) {
    bitVectorClrAll_IMPL(param_4,0xb4);
    iVar2 = vectCount_IMPL(local_58);
    uVar3 = vectAt_IMPL(local_58,iVar2 + -1);
    uVar4 = vectAt_IMPL(local_58,0);
    vectIterRange_IMPL(&local_88,local_58,uVar4,uVar3);
    local_50 = local_88;
    local_48 = local_80;
    local_40 = local_78;
    local_38 = local_70;
    local_30 = local_68;
    do {
      cVar1 = vectIterNext_IMPL(&local_50);
      while( true ) {
        if (cVar1 == '\0') {
          return;
        }
        if ((*(uint *)(local_50 + 2) == 0) || ((*(uint *)(local_50 + 2) & param_3) == 0)) break;
        bitVectorSet_IMPL(param_4,0xb4,*local_50);
        cVar1 = vectIterNext_IMPL(&local_50);
      }
    } while( true );
  }
  nvAssertFailedNoLog("intrGetInterruptTable_HAL(pGpu, pIntr, &pIntrTable) == NV_OK",
                      "src/kernel/gpu/intr/intr.c",0x2d1);
  return;
}


// ===== 00392880 intrConstructEngine_IMPL =====

ulong intrConstructEngine_IMPL(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  *(undefined1 *)(param_2 + 0x14c8) = 0;
  *(undefined8 *)(param_2 + 0x14f0) = 0;
  *(undefined8 *)(param_2 + 0x14f8) = 0;
  *(undefined1 *)(param_2 + 0x345) = 1;
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  uVar2 = vectInit_IMPL(param_2 + 0x378,uVar1,0,0x10);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,
             "vectInit(&pIntr->intrTable, portMemAllocatorGetGlobalNonPaged(), 0 )",
             "src/kernel/gpu/intr/intr.c",0x31e);
  return uVar2 & 0xffffffff;
}


// ===== 00392910 intrDestruct_IMPL =====

void intrDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    uVar2 = *(undefined8 *)(param_1 + 0x150);
  }
  gpuEngineGetGpu(uVar2);
  lVar1 = *(long *)(param_1 + 0x14f0);
  while (lVar1 != 0) {
    lVar1 = *(long *)(lVar1 + 0x20);
    if (lVar1 == 0) {
      *(undefined8 *)(param_1 + 0x14f8) = 0;
    }
    *(long *)(param_1 + 0x14f0) = lVar1;
    portMemFree();
    lVar1 = *(long *)(param_1 + 0x14f0);
  }
  vectDestroy_IMPL(param_1 + 0x378);
  return;
}


// ===== 003929a0 intrStatePreInitLocked_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int intrStatePreInitLocked_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  undefined4 local_2c [3];
  
  *(undefined8 *)(param_2 + 0x1490) = 0;
  *(undefined8 *)(param_2 + 0x1498) = 0;
  *(undefined8 *)(param_2 + 0x14a0) = 0;
  *(undefined8 *)(param_2 + 0x14a8) = 0;
  *(undefined8 *)(param_2 + 0x14b0) = 0;
  *(undefined8 *)(param_2 + 0x14b8) = 0;
  *(undefined8 *)(param_2 + 0x14c0) = 0;
  iVar1 = (**(code **)(param_2 + 0x2e0))();
  if (iVar1 == 0) {
    param_2 = param_2 + 0x398;
    local_2c[0] = 0;
    portMemSet(param_2,0,0x10e0);
    while( true ) {
      plVar2 = (long *)gpuGetNextChildOfTypeUnsafe_IMPL(param_1,local_2c,0x2271cc);
      if (plVar2 == (long *)0x0) break;
      (**(code **)(*plVar2 + 0x18))(param_1,plVar2,param_2,*(code **)(*plVar2 + 0x18));
    }
    gpuRegisterGenericKernelFalconIntrService_IMPL(param_1,param_2);
    return 0;
  }
  nvAssertOkFailedNoLog
            (iVar1,"intrInitInterruptTable_HAL(pGpu, pIntr)","src/kernel/gpu/intr/intr.c",0x349);
  return iVar1;
}


// ===== 00392ab0 intrStateInitUnlocked_IMPL =====

/* WARNING: Type propagation algorithm not settling */

undefined8 intrStateInitUnlocked_IMPL(long param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  int local_34 [5];
  
  local_34[0] = 0;
  iVar1 = osReadRegistryDword(param_1,"RMIntrDetailedLogs",local_34);
  if ((iVar1 == 0) && (local_34[0] == 1)) {
    *(undefined1 *)(param_2 + 0x340) = 1;
  }
  local_34[2] = 0;
  iVar1 = osReadRegistryDword(param_1,"RMDisablePerIntrDPCQueueing",local_34 + 2);
  if ((iVar1 == 0) && (local_34[2] != 0)) {
    uVar2 = gpumgrGetGpuMask(param_1);
    local_34[1] = 0;
    while (lVar3 = gpumgrGetNextGpu(uVar2,local_34 + 1), lVar3 != 0) {
      *(undefined1 *)(*(long *)(lVar3 + 0x1c20) + 0x345) = 1;
    }
  }
  *(undefined1 *)(param_2 + 0x346) = 0;
  if ((*(char *)(param_2 + 0x347) != '\0') && (*(char *)(param_1 + 0x908) == '\0')) {
    *(undefined1 *)(param_2 + 0x346) = 1;
  }
  iVar1 = osReadRegistryDword(param_1,"RMIntrLockingMode",local_34 + 2);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x3ea,"_intrInitRegistryOverrides",4,
                 "NVRM: NV_REG_STR_RM_INTR_LOCKING_MODE was set to: 0x%x\n",local_34[2]);
    if (local_34[2] == 1) {
      if (*(char *)(param_2 + 0x347) != '\0') {
        *(undefined1 *)(param_2 + 0x346) = 1;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x346) = 0;
    }
  }
  *(undefined4 *)(param_2 + 0x1500) = 1000;
  iVar1 = osReadRegistryDword(param_1,"RM654663",local_34 + 2);
  if (iVar1 == 0) {
    *(int *)(param_2 + 0x1500) = local_34[2];
  }
  return 0;
}


// ===== 00392c60 intrStateInitLocked_IMPL =====

undefined8 intrStateInitLocked_IMPL(long param_1,long param_2)

{
  undefined1 local_30 [32];
  
  *(undefined1 *)(param_2 + 0x1554) = 1;
  *(undefined4 *)(param_2 + 0x1550) = 1;
  *(undefined4 *)(param_2 + 0x1540) = 1;
  *(undefined4 *)(param_2 + 0x150c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x8f4) = 0xffffffff;
  if (*(long *)(param_1 + 0x1b98) != 0) {
    *(undefined4 *)(*(long *)(param_1 + 0x1b98) + 0x548) = 0xff;
  }
  if (*(char *)(param_2 + 0x346) == '\0') {
    return 0;
  }
  bitVectorClrAll_IMPL(local_30,0xb4);
  bitVectorSet_IMPL(local_30,0xb4,2);
  bitVectorCopy_IMPL(param_2 + 0x1510,0xb4,local_30,0xb4);
  return 0;
}


// ===== 00392d10 intrStateDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrStateDestroy_IMPL(undefined8 param_1,long param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_2 + 0x1554) = 0;
  portMemSet(param_2 + 0x398,0,0x10e0);
  iVar1 = (**(code **)(param_2 + 0x2f0))(param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,"intrDestroyInterruptTable_HAL(pGpu, pIntr)","src/kernel/gpu/intr/intr.c",0x3a0);
  return;
}


// ===== 00392d80 intrInitInterruptTable_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int intrInitInterruptTable_KERNEL(long param_1,long param_2)

{
  int iVar1;
  uint *puVar2;
  long lVar3;
  uint *puVar4;
  uint uVar5;
  uint local_48;
  uint uStack_44;
  undefined8 local_40;
  
  vectClear_IMPL(param_2 + 0x378);
  puVar2 = (uint *)portMemAllocNonPaged(0x840);
  if (puVar2 == (uint *)0x0) {
    nvAssertOkFailedNoLog(0x51,"pParams != NULL","src/kernel/gpu/intr/intr.c",0x424);
LAB_00392ea5:
    iVar1 = 0x51;
  }
  else {
    iVar1 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a5c,puVar2,0x840);
    if (iVar1 == 0) {
      if (*puVar2 < 0x81) {
        iVar1 = vectReserve_IMPL(param_2 + 0x378);
        if (iVar1 == 0) {
          puVar4 = puVar2 + 1;
          uVar5 = 0;
          if (*puVar2 != 0) {
            do {
              _local_48 = CONCAT44(puVar4[1],(uint)(ushort)*puVar4);
              local_40 = *(undefined8 *)(puVar4 + 2);
              lVar3 = vectAppend_IMPL(param_2 + 0x378,&local_48);
              if (lVar3 == 0) {
                nvAssertOkFailedNoLog
                          (0x51,"vectAppend(&pIntr->intrTable, &entry) != NULL",
                           "src/kernel/gpu/intr/intr.c",0x43e);
                goto LAB_00392ea5;
              }
              uVar5 = uVar5 + 1;
              puVar4 = puVar4 + 4;
            } while (uVar5 < *puVar2);
          }
          iVar1 = vectTrim_IMPL(param_2 + 0x378,0);
          if (iVar1 == 0) {
            portMemCopy(param_2 + 0x1490,0x38,puVar2 + 0x202,0x38);
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar1,"vectTrim(&pIntr->intrTable, 0)","src/kernel/gpu/intr/intr.c",0x443);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar1,"vectReserve(&pIntr->intrTable, pParams->tableLen)",
                     "src/kernel/gpu/intr/intr.c",0x434);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (0x5b,"pParams->tableLen <= NV2080_CTRL_INTERNAL_INTR_MAX_TABLE_SIZE",
                   "src/kernel/gpu/intr/intr.c",0x42e);
        iVar1 = 0x5b;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_INTR_GET_KERNEL_TABLE, pParams, sizeof *pParams)"
                 ,"src/kernel/gpu/intr/intr.c",0x426);
    }
  }
  portMemFree(puVar2);
  return iVar1;
}


// ===== 00392fc0 intrServiceInterruptRecords_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
intrServiceInterruptRecords_IMPL(undefined8 param_1,long param_2,ushort param_3,char *param_4)

{
  int *piVar1;
  long *plVar2;
  char cVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  ushort local_4c;
  ushort local_4a;
  long local_48;
  long local_40 [2];
  
  uVar6 = (ulong)param_3;
  plVar2 = *(long **)(param_2 + 0x398 + uVar6 * 0x18);
  local_4c = param_3;
  local_4a = param_3;
  if (plVar2 == (long *)0x0) {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x472,"intrServiceInterruptRecords_IMPL",4,
                 "NVRM: Missing interrupt handler for engine idx %d\n",param_3);
    nvAssertFailedNoLog("Missing interrupt handler","src/kernel/gpu/intr/intr.c",0x473);
    if (param_4 != (char *)0x0) {
      *param_4 = '\0';
    }
  }
  else {
    cVar3 = (**(code **)(*plVar2 + 0x20))(param_1,plVar2,&local_4c);
    if (param_4 != (char *)0x0) {
      *param_4 = cVar3;
    }
    if (cVar3 != '\0') {
      osGetPerformanceCounter(&local_48);
      uVar4 = (**(code **)(*plVar2 + 0x28))(param_1,plVar2,&local_4a);
      osGetPerformanceCounter(local_40);
      uVar5 = local_40[0] - local_48;
      if ((1000000 < uVar5) &&
         (piVar1 = (int *)(param_2 + 0x1560 + uVar6 * 0x18), *piVar1 = *piVar1 + 1,
         *(ulong *)(param_2 + 0x1568 + uVar6 * 0x18) < uVar5)) {
        *(ulong *)(param_2 + 0x1568 + uVar6 * 0x18) = uVar5;
        return uVar4;
      }
      return uVar4;
    }
  }
  return 0;
}


// ===== 00393130 _intrServiceStallExactList =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _intrServiceStallExactList(long param_1,long param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  uint uVar11;
  byte local_aa;
  ushort *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  char local_69;
  undefined8 local_68;
  ushort *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar5 = bitVectorTestAllCleared_IMPL(param_3,0xb4);
  uVar11 = 0;
  if ((char)uVar5 == '\0') {
    iVar6 = (**(code **)(param_2 + 0x2e8))(param_1,param_2,&local_68);
    if (iVar6 == 0) {
      iVar6 = vectCount_IMPL(local_68);
      uVar7 = vectAt_IMPL(local_68,iVar6 + -1);
      uVar8 = vectAt_IMPL(local_68,0);
      vectIterRange_IMPL(&local_a8,local_68,uVar8,uVar7);
      local_aa = 0;
      bVar3 = false;
      local_60 = local_a8;
      local_58 = local_a0;
      local_50 = local_98;
      local_48 = local_90;
      local_40 = local_88;
      while (cVar4 = vectIterNext_IMPL(&local_60), cVar4 != '\0') {
        if (param_1 == 0) {
          return uVar5;
        }
        while( true ) {
          if (*(char *)(param_1 + 0x44c) == '\0') {
            return 0;
          }
          if (*(char *)(param_1 + 0x450) != '\0') {
            return uVar5;
          }
          if (*(char *)(param_1 + 0x44f) != '\0') {
            return 0;
          }
          if (*(char *)(param_1 + 0x451) != '\0') {
            return 0;
          }
          if (*(char *)(param_1 + 0x461) != '\0') {
            return 0;
          }
          uVar1 = *local_60;
          cVar4 = bitVectorTest_IMPL(param_3,0xb4,uVar1);
          if (cVar4 != '\0') break;
          cVar4 = vectIterNext_IMPL(&local_60);
          if (cVar4 == '\0') goto LAB_003932c0;
        }
        local_69 = '\0';
        iVar6 = intrServiceInterruptRecords_IMPL(param_1,param_2,uVar1,&local_69);
        if (local_69 != '\0') {
          uVar10 = (ulong)(uint)uVar1;
          if (iVar6 != 0) {
            lVar9 = uVar10 * 0xc;
            if (*(int *)(stuckIntr + lVar9 + 8) == stuckIntrGeneration) {
              if ((*(int *)(stuckIntr + lVar9 + 4) == iVar6) &&
                 (iVar2 = *(int *)(stuckIntr + uVar10 * 0xc),
                 *(uint *)(stuckIntr + uVar10 * 0xc) = iVar2 + 1U,
                 *(uint *)(param_2 + 0x1500) < iVar2 + 1U)) {
                nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x5f0,"_intrServiceStallExactList",4,
                             "NVRM: Stuck interrupt detected for mcEngine %u\n",(uint)uVar1);
                nvAssertFailedNoLog(&DAT_00d43228,"src/kernel/gpu/intr/intr.c",0x5f4);
                bVar3 = true;
              }
            }
            else {
              *(int *)(stuckIntr + lVar9 + 8) = stuckIntrGeneration;
              *(undefined4 *)(stuckIntr + lVar9) = 0;
            }
          }
          *(int *)(stuckIntr + uVar10 * 0xc + 4) = iVar6;
          local_aa = local_aa | iVar6 != 0;
        }
      }
LAB_003932c0:
      if ((*(char *)(param_1 + 0x908) != '\0') &&
         (cVar4 = bitVectorTest_IMPL(param_3,0xb4,0x25), cVar4 != '\0')) {
        vgpuService(param_1);
      }
      cVar4 = bitVectorTest_IMPL(param_3,0xb4,2);
      if (((cVar4 != '\0') || (cVar4 = bitVectorTest_IMPL(param_3,0xb4,0xb1), cVar4 != '\0')) &&
         (*(char *)(param_2 + 0x346) != '\0')) {
        intrReenableIntrMask_IMPL_part_0(param_1,param_2);
      }
      if (bVar3) {
        nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x60c,"_intrServiceStallExactList",4,
                     "NVRM: Interrupt is stuck. Bailing after %d iterations.\n",
                     *(undefined4 *)(param_2 + 0x1500));
        return uVar5;
      }
      return (uint)local_aa;
    }
    nvAssertOkFailedNoLog
              (iVar6,"intrGetInterruptTable_HAL(pGpu, pIntr, &pIntrTable)",
               "src/kernel/gpu/intr/intr.c",0x5c2);
    uVar11 = uVar5;
  }
  return uVar11;
}


// ===== 003934d0 intrServiceStall_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrServiceStall_IMPL(long param_1,long param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 local_30 [24];
  
  iVar3 = regRead032(param_1 + 0x3a18,0,0,0,0);
  if (iVar3 == -1) {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x8c,"intrServiceStall_IMPL",4,
                 "NVRM: Failed GPU reg read : 0x%x. Check whether GPU is present on the bus\n",
                 0xffffffff);
  }
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x44c) != '\0')) &&
      (*(char *)(param_1 + 0x450) == '\0')) &&
     (((*(char *)(param_1 + 0x44f) == '\0' && (*(char *)(param_1 + 0x451) == '\0')) &&
      (*(char *)(param_1 + 0x461) == '\0')))) {
    if (stuckIntrGeneration == -1) {
      stuckIntrGeneration = 0;
      portMemSet(stuckIntr,0,0x870);
    }
    else {
      stuckIntrGeneration = stuckIntrGeneration + 1;
    }
    if (*(char *)(param_2 + 0x345) == '\0') {
      if (*(char *)(param_2 + 0x14c8) == '\0') {
        (**(code **)(param_2 + 0x330))(param_1,param_2,local_30,0);
        cVar1 = bitVectorTestAllCleared_IMPL(local_30,0xb4);
        if (cVar1 == '\0') {
          uVar2 = bitVectorCountTrailingZeros_IMPL(local_30,0xb4);
          intrQueueInterruptBasedDpc_IMPL(param_1,param_2);
          bitVectorClr_IMPL(param_2 + 0x14d0,0xb4,uVar2);
          *(undefined1 *)(param_2 + 0x14c8) = 1;
          (**(code **)(param_2 + 0x310))(param_1,param_2);
        }
      }
      else {
        (**(code **)(param_2 + 0x310))(param_1,param_2);
      }
    }
    else {
      do {
        iVar3 = (**(code **)(param_2 + 0x330))(param_1,param_2,local_30,0);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,"intrGetPendingStall_HAL(pGpu, pIntr, &pendingEngines, NULL )",
                     "src/kernel/gpu/intr/intr.c",0xa1);
          return;
        }
        cVar1 = _intrServiceStallExactList(param_1,param_2,local_30);
      } while (cVar1 != '\0');
    }
    _intrLogLongRunningInterrupts(param_2);
  }
  return;
}


// ===== 003936f0 intrServiceNotificationRecords_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong intrServiceNotificationRecords_IMPL
                (undefined8 param_1,long param_2,ushort param_3,undefined8 param_4)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 local_38;
  ulong local_30;
  
  lVar1 = param_2 + (ulong)param_3 * 0x18;
  plVar2 = *(long **)(lVar1 + 0x3a0);
  local_30 = (ulong)param_3;
  local_38 = param_4;
  if (plVar2 == (long *)0x0) {
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x4a2,"intrServiceNotificationRecords_IMPL",4,
                 "NVRM: Missing notification interrupt handler for engine idx %d\n",param_3);
    nvAssertFailedNoLog("Missing notification interrupt handler","src/kernel/gpu/intr/intr.c",0x4a3)
    ;
  }
  else {
    uVar3 = (**(code **)(*plVar2 + 0x30))(param_1,plVar2,&local_38);
    if ((int)uVar3 == 0) {
      if ((*(char *)(param_2 + 0x1488) != '\0') && (*(char *)(lVar1 + 0x3a8) == '\0')) {
        engineNonStallIntrNotify(param_1,0x32);
        return uVar3 & 0xffffffff;
      }
      return uVar3 & 0xffffffff;
    }
    nvDbg_Printf("src/kernel/gpu/intr/intr.c",0x4aa,"intrServiceNotificationRecords_IMPL",4,
                 "NVRM: Could not service notification interrupt for engine idx %d; returned NV_STATUS = 0x%x\n"
                 ,param_3,uVar3);
    nvAssertFailedNoLog("Could not service notification interrupt","src/kernel/gpu/intr/intr.c",
                        0x4ad);
  }
  return 0xffff;
}


// ===== 00393880 intrCheckFecsEventbufferPending_IMPL =====

undefined8
intrCheckFecsEventbufferPending_IMPL
          (long param_1,undefined8 param_2,undefined8 param_3,undefined1 *param_4)

{
  long lVar1;
  char cVar2;
  short sVar3;
  long lVar4;
  
  sVar3 = fecsGetCtxswLogConsumerCount(param_1,*(undefined8 *)(param_1 + 0x1bc8));
  if (param_4 == (undefined1 *)0x0) {
    nvAssertFailedNoLog("pbCtxswLog != NULL","src/kernel/gpu/intr/intr.c",0x4cf);
    return 0x1f;
  }
  lVar4 = 0;
  *param_4 = 0;
  if (sVar3 < 1) {
    if (sVar3 != 0) {
      nvAssertFailedNoLog("fecsCtxswLogConsumerCount == 0","src/kernel/gpu/intr/intr.c",0x4d5);
    }
  }
  else {
    do {
      while ((((lVar1 = *(long *)(param_1 + 0x1bd0 + lVar4 * 8), lVar1 == 0 ||
               (*(char *)(lVar1 + 0x1fa) == '\0')) ||
              (cVar2 = bitVectorTest_IMPL(param_3,0xb4,(int)lVar4 + 0x54), cVar2 == '\0')) ||
             ((cVar2 = fecsBufferChanged(param_1,lVar1), cVar2 == '\0' ||
              (cVar2 = fecsSignalIntrPendingIfNotPending(param_1,lVar1), cVar2 == '\0'))))) {
        lVar4 = lVar4 + 1;
        if (lVar4 == 8) {
          return 0;
        }
      }
      lVar4 = lVar4 + 1;
      *param_4 = *(undefined1 *)(lVar1 + 0x1fb);
    } while (lVar4 != 8);
  }
  return 0;
}


// ===== 003939c0 intrCheckAndServiceFecsEventbuffer_IMPL =====

undefined8
intrCheckAndServiceFecsEventbuffer_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  short sVar3;
  long lVar4;
  
  sVar3 = fecsGetCtxswLogConsumerCount(param_1,*(undefined8 *)(param_1 + 0x1bc8));
  cVar2 = bitVectorTestAllCleared_IMPL(param_3,0xb4);
  if (cVar2 == '\0') {
    lVar4 = 0;
    if (sVar3 < 1) {
      if (sVar3 != 0) {
        nvAssertFailedNoLog("fecsCtxswLogConsumerCount == 0","src/kernel/gpu/intr/intr.c",0x4ff);
      }
    }
    else {
      do {
        lVar1 = *(long *)(param_1 + 0x1bd0 + lVar4 * 8);
        if ((((lVar1 != 0) &&
             (cVar2 = bitVectorTest_IMPL(param_3,0xb4,(int)lVar4 + 0x9c), cVar2 != '\0')) &&
            (*(char *)(lVar1 + 0x1fa) != '\0')) &&
           (cVar2 = fecsClearIntrPendingIfPending(param_1,lVar1), cVar2 != '\0')) {
          nvEventBufferFecsCallback(param_1,lVar1);
        }
        lVar4 = lVar4 + 1;
      } while (lVar4 != 8);
    }
  }
  return 0;
}


// ===== 00393aa0 intrServiceNonStallBottomHalf_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
intrServiceNonStallBottomHalf_IMPL
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x1a0))(param_1,param_2,param_4);
  intrCheckAndServiceFecsEventbuffer_IMPL(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== 00393af0 intrGetInterruptTable_IMPL =====

undefined8 intrGetInterruptTable_IMPL(undefined8 param_1,long param_2,long *param_3)

{
  char cVar1;
  
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("ppTable != NULL","src/kernel/gpu/intr/intr.c",0x51a);
    return 0x1f;
  }
  cVar1 = vectIsEmpty_IMPL(param_2 + 0x378);
  if (cVar1 == '\0') {
    *param_3 = param_2 + 0x378;
    return 0;
  }
  nvAssertFailedNoLog("!vectIsEmpty(&pIntr->intrTable)","src/kernel/gpu/intr/intr.c",0x51b);
  return 0x40;
}


// ===== 00393b80 intrDestroyInterruptTable_IMPL =====

undefined8 intrDestroyInterruptTable_IMPL(undefined8 param_1,long param_2)

{
  portMemFree(*(undefined8 *)(param_2 + 0x1478));
  *(undefined8 *)(param_2 + 0x1478) = 0;
  *(undefined8 *)(param_2 + 0x1480) = 0;
  vectClear_IMPL(param_2 + 0x378);
  return 0;
}


// ===== 00393bd0 intrProcessDPCQueue_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrProcessDPCQueue_IMPL(undefined8 param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  undefined2 uVar3;
  long local_60;
  long local_58;
  undefined1 local_50 [32];
  
  do {
    osGetPerformanceCounter(&local_60);
    bitVectorClrAll_IMPL(local_50,0xb4);
    piVar1 = *(int **)(param_2 + 0x14f0);
    if (piVar1 == (int *)0x0) {
LAB_00393c67:
      (**(code **)(param_2 + 0x330))(param_1,param_2,local_50,0);
      cVar2 = bitVectorTestAllCleared_IMPL(local_50,0xb4);
      if (cVar2 == '\0') {
        uVar3 = bitVectorCountTrailingZeros_IMPL(local_50,0xb4);
        intrQueueInterruptBasedDpc_IMPL(param_1,param_2,uVar3);
        bitVectorCopy_IMPL(param_2 + 0x14d0,0xb4,local_50);
        bitVectorClr_IMPL(param_2 + 0x14d0,0xb4,uVar3);
        *(undefined1 *)(param_2 + 0x14c8) = 1;
      }
    }
    else {
      if (*(long *)(piVar1 + 8) == 0) {
        *(undefined8 *)(param_2 + 0x14f8) = 0;
        *(undefined8 *)(param_2 + 0x14f0) = 0;
        if (*piVar1 == 0) goto LAB_00393d11;
        goto LAB_00393c67;
      }
      *(long *)(param_2 + 0x14f0) = *(long *)(piVar1 + 8);
      if (*piVar1 == 0) {
LAB_00393d11:
        _intrServiceStallExactList(param_1,param_2,piVar1 + 2);
        portMemFree(piVar1);
        cVar2 = bitVectorTestAllCleared_IMPL(param_2 + 0x14d0,0xb4);
        if (cVar2 == '\0') {
          uVar3 = bitVectorCountTrailingZeros_IMPL(param_2 + 0x14d0,0xb4);
          intrQueueInterruptBasedDpc_IMPL(param_1,param_2,uVar3);
          bitVectorClr_IMPL(param_2 + 0x14d0,0xb4,uVar3);
        }
        if (*(long *)(param_2 + 0x14f0) == 0) goto LAB_00393c67;
      }
    }
    osGetPerformanceCounter(&local_58);
    lastDpcExecutionTime = local_58 - local_60;
    totalDpcExecutionTime = totalDpcExecutionTime + lastDpcExecutionTime;
    cVar2 = bitVectorTestAllCleared_IMPL(local_50,0xb4);
    if (cVar2 != '\0') {
      return;
    }
  } while( true );
}


// ===== 00393db0 intrReenableIntrMask_IMPL =====

void intrReenableIntrMask_IMPL(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x346) == '\0') {
    return;
  }
  intrReenableIntrMask_IMPL_part_0();
  return;
}


// ===== 00393dd0 intrServiceStallList_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrServiceStallList_IMPL(undefined8 param_1,long param_2,long param_3,char param_4)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_48;
  undefined1 local_40 [24];
  
  local_48 = 0;
  iVar2 = _intrServiceStallCommonCheckBegin_isra_0(param_1,&local_48);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"_intrServiceStallCommonCheckBegin(pGpu, pIntr, &pOldContext)",
               "src/kernel/gpu/intr/intr.c",0x675);
    return;
  }
  do {
    iVar2 = (**(code **)(param_2 + 0x330))(param_1,param_2,local_40,0);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"intrGetPendingStall_HAL(pGpu, pIntr, &exactEngines, NULL )",
                 "src/kernel/gpu/intr/intr.c");
    }
    if (param_3 == 0) {
      bitVectorClr_IMPL(local_40,0xb4,0x25);
    }
    else {
      bitVectorAnd_IMPL(local_40,0xb4,local_40,0xb4,param_3,0xb4);
    }
    uVar3 = _intrServiceStallExactList(param_1,param_2,local_40);
    uVar1 = local_48;
  } while (((uVar3 & 1) != 0) && (param_4 != '\0'));
  _intrLogLongRunningInterrupts(param_2);
  iVar2 = resservRestoreTlsCallContext(uVar1);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"resservRestoreTlsCallContext(pOldContext)","src/kernel/gpu/intr/intr.c",0x652)
    ;
  }
  return;
}


// ===== 00393f10 intrServiceStallSingle_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void intrServiceStallSingle_IMPL(undefined8 param_1,long param_2,undefined2 param_3,char param_4)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined8 local_48;
  undefined1 local_40 [24];
  
  local_48 = 0;
  bitVectorClrAll_IMPL(local_40,0xb4);
  bitVectorSet_IMPL(local_40,0xb4,param_3);
  iVar3 = _intrServiceStallCommonCheckBegin_isra_0(param_1,&local_48);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"_intrServiceStallCommonCheckBegin(pGpu, pIntr, &pOldContext)",
               "src/kernel/gpu/intr/intr.c",0x6aa);
    return;
  }
  while( true ) {
    cVar2 = (**(code **)(param_2 + 0x1d8))(param_1,param_2,param_3,0xffffffff,0);
    if (cVar2 == '\0') break;
    uVar4 = _intrServiceStallExactList(param_1,param_2,local_40);
    if (((uVar4 & 1) == 0) || (param_4 == '\0')) break;
  }
  uVar1 = local_48;
  _intrLogLongRunningInterrupts(param_2);
  iVar3 = resservRestoreTlsCallContext(uVar1);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"resservRestoreTlsCallContext(pOldContext)","src/kernel/gpu/intr/intr.c",0x652)
    ;
  }
  return;
}


// ===== 00394020 intrGetIntrTopCategoryMask_IMPL =====

long intrGetIntrTopCategoryMask_IMPL(long param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x1490 + (ulong)param_2 * 8);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pIntr->subtreeMap[category].subtreeMask != 0x0",
                        "src/kernel/gpu/intr/intr.c",0x6c2);
    return 0;
  }
  if (lVar1 == 0xffff) {
    nvAssertFailedNoLog("pIntr->subtreeMap[category].subtreeMask != NV_U16_MAX",
                        "src/kernel/gpu/intr/intr.c",0x6c3);
  }
  else if (lVar1 == 0xffffffff) {
    nvAssertFailedNoLog("pIntr->subtreeMap[category].subtreeMask != NV_U32_MAX",
                        "src/kernel/gpu/intr/intr.c",0x6c4);
  }
  else {
    if (lVar1 != -1) {
      return lVar1;
    }
    nvAssertFailedNoLog("pIntr->subtreeMap[category].subtreeMask != NV_U64_MAX",
                        "src/kernel/gpu/intr/intr.c",0x6c5);
  }
  return 0;
}


// ===== 003940e0 intrGetUvmSharedLeafEnDisableMask_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong intrGetUvmSharedLeafEnDisableMask_IMPL(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint local_20 [2];
  uint local_18 [2];
  
  if (*(char *)(param_1 + 0x909) != '\0') {
    return 0xffffffffffffffff;
  }
  (**(code **)(param_2 + 0x220))(param_1,param_2,local_20);
  uVar4 = *(ulong *)(param_2 + 0x14c0);
  uVar3 = -uVar4 & uVar4;
  uVar5 = (uint)((uVar3 & 0xaaaaaaaaaaaaaaaa) != 0) | (uint)(uVar3 >> 0x20 != 0) << 5 |
          (uint)((uVar3 & 0xffff0000ffff0000) != 0) << 4 |
          (uint)((uVar3 & 0xff00ff00ff00ff00) != 0) << 3 |
          (uint)((uVar3 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
          (uint)((uVar3 & 0xcccccccccccccccc) != 0) * 2;
  uVar4 = uVar4 >> 1;
  if (uVar4 == 0) {
    uVar6 = 0;
    if (uVar5 != 0) goto LAB_00394270;
  }
  else {
    lVar1 = 0x3f;
    if (uVar4 != 0) {
      for (; uVar4 >> lVar1 == 0; lVar1 = lVar1 + -1) {
      }
    }
    uVar2 = (int)lVar1 + 1;
    if (uVar2 != uVar5) {
LAB_00394270:
      nvAssertFailedNoLog("lowestSubtreeIdx == highestSubtreeIdx","src/kernel/gpu/intr/intr.c",0x700
                         );
      return 0x40;
    }
    uVar6 = uVar5 * 2;
    if (uVar2 * 2 != uVar6) {
      nvAssertFailedNoLog("(NV_CTRL_INTR_SUBTREE_TO_LEAF_IDX_END(highestSubtreeIdx) - 1) == NV_CTRL_INTR_SUBTREE_TO_LEAF_IDX_START(lowestSubtreeIdx)"
                          ,"src/kernel/gpu/intr/intr.c",0x706);
    }
  }
  puVar7 = local_20;
  uVar4 = 0;
  do {
    uVar5 = *puVar7;
    if (uVar5 != 0xffffffff) {
      if (uVar5 >> 5 != uVar6) {
        nvAssertFailedNoLog("NV_CTRL_INTR_GPU_VECTOR_TO_LEAF_REG(vector) == NV_CTRL_INTR_SUBTREE_TO_LEAF_IDX_START(lowestSubtreeIdx)"
                            ,"src/kernel/gpu/intr/intr.c",0x714);
      }
      uVar4 = uVar4 | 1L << ((byte)uVar5 & 0x1f);
    }
    puVar7 = puVar7 + 1;
  } while (local_18 != puVar7);
  return ~(uVar4 << 0x20);
}


// ===== 003942c0 intrRefetchInterruptTable_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong intrRefetchInterruptTable_IMPL(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = (**(code **)(param_2 + 0x2d8))(param_1,param_2,1);
  if (uVar1 == 0) {
    uVar1 = (**(code **)(param_2 + 0x2e0))(param_1,param_2);
    if (uVar1 == 0) {
      uVar2 = (**(code **)(param_2 + 0x2d0))(param_1,param_2,1);
      if ((int)uVar2 != 0) {
        nvAssertOkFailedNoLog
                  (uVar2 & 0xffffffff,"intrStateLoad_HAL(pGpu, pIntr, GPU_STATE_FLAGS_PRESERVING)",
                   "src/kernel/gpu/intr/intr.c",0x72b);
        uVar2 = uVar2 & 0xffffffff;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar1,"intrInitInterruptTable_HAL(pGpu, pIntr)","src/kernel/gpu/intr/intr.c",0x729)
      ;
      uVar2 = (ulong)uVar1;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar1,"intrStateUnload_HAL(pGpu, pIntr, GPU_STATE_FLAGS_PRESERVING)",
             "src/kernel/gpu/intr/intr.c",0x727);
  return (ulong)uVar1;
}


// ===== 003943b0 intrservRegisterIntrService_IMPL =====

void intrservRegisterIntrService_IMPL(void)

{
  return;
}


// ===== 003943c0 intrservClearInterrupt_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 intrservClearInterrupt_IMPL(long param_1,undefined8 param_2,undefined2 *param_3)

{
  long lVar1;
  undefined4 uVar2;
  
  if (param_3 != (undefined2 *)0x0) {
    lVar1 = *(long *)(param_1 + 0x1c20);
    uVar2 = intrGetVectorFromEngineId_IMPL(param_1,lVar1,*param_3,0);
    (**(code **)(lVar1 + 0x1d0))(param_1,lVar1,uVar2,0);
    return 1;
  }
  nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/intr/intr_service.c",0x38);
  return 0;
}


// ===== 00394430 intrservServiceInterrupt_IMPL =====

undefined8 intrservServiceInterrupt_IMPL(void)

{
  nvAssertFailedNoLog("intrservServiceInterrupt called but not implemented",
                      "src/kernel/gpu/intr/intr_service.c",0x4e);
  return 0;
}


// ===== 00394460 intrservServiceNotificationInterrupt_IMPL =====

undefined8 intrservServiceNotificationInterrupt_IMPL(void)

{
  nvAssertFailedNoLog("intrservServiceNotificationInterrupt called but not implemented",
                      "src/kernel/gpu/intr/intr_service.c",0x5e);
  return 0x40;
}


// ===== 003944a0 intrInitInterruptTable_VF =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int intrInitInterruptTable_VF(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  ushort uVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 uVar14;
  int iVar15;
  int local_5c;
  undefined4 local_50;
  undefined1 local_4c [4];
  undefined8 local_48;
  undefined8 local_40;
  
  lVar1 = param_2 + 0x378;
  lVar7 = gpuGetKernelFifoShared_IMPL();
  iVar4 = (**(code **)(lVar7 + 0x240))(param_1,lVar7,*(code **)(lVar7 + 0x240));
  lVar7 = gpuGetStaticInfo(param_1);
  cVar3 = vectIsEmpty_IMPL(lVar1);
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("vectIsEmpty(&pIntr->intrTable)","src/kernel/gpu/intr/intr_vgpu.c",0xe8);
    local_5c = 0x40;
  }
  else {
    if (*(uint *)(lVar7 + 0x1e0) < 0x21) {
      if (*(uint *)(lVar7 + 0x1e278) < 0x101) {
        iVar5 = vectReserve_IMPL(lVar1,*(uint *)(lVar7 + 0x1e0) + *(uint *)(lVar7 + 0x1e278));
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "vectReserve(&pIntr->intrTable, pStaticParams->numEntries + pVSI->mcEngineNotificationIntrVectors.numEntries)"
                     ,"src/kernel/gpu/intr/intr_vgpu.c",0xf3);
          return iVar5;
        }
        uVar13 = 0;
        if (*(int *)(lVar7 + 0x1e0) != 0) {
          do {
            local_48 = 0;
            local_40 = 0;
            lVar8 = uVar13 * 0x10 + lVar7;
            uVar12 = *(uint *)(lVar8 + 0x1e4);
            if (uVar12 == 9) {
              uVar11 = 0x9c;
              uVar14 = 0x9c;
            }
            else if (uVar12 < 10) {
              if (uVar12 == 5) {
                uVar11 = 0x3e;
                uVar14 = 0x3e;
              }
              else if (uVar12 < 6) {
                if (uVar12 == 3) {
                  uVar11 = 0x40;
                  uVar14 = 0x40;
                }
                else if (uVar12 == 4) {
                  uVar11 = 0x3b;
                  uVar14 = 0x3b;
                }
                else if (uVar12 == 1) {
                  uVar11 = 0x3d;
                  uVar14 = 0x3d;
                }
                else {
                  if (uVar12 != 2) {
                    uVar12 = 0;
                    goto LAB_0039493b;
                  }
                  uVar11 = 0x3f;
                  uVar14 = 0x3f;
                }
              }
              else if (uVar12 == 7) {
                uVar11 = 1;
                uVar14 = 1;
              }
              else {
                uVar11 = 0x49;
                if (uVar12 != 8) {
                  uVar11 = 0x3c;
                }
                uVar14 = 0x49;
                if (uVar12 != 8) {
                  uVar14 = 0x3c;
                }
              }
            }
            else if (uVar12 == 0xd) {
              uVar11 = 0xa0;
              uVar14 = 0xa0;
            }
            else if (uVar12 < 0xe) {
              if (uVar12 == 0xb) {
                uVar11 = 0x9e;
                uVar14 = 0x9e;
              }
              else if (uVar12 == 0xc) {
                uVar11 = 0x9f;
                uVar14 = 0x9f;
              }
              else {
                uVar11 = 0x9d;
                uVar14 = 0x9d;
              }
            }
            else if (uVar12 == 0xf) {
              uVar11 = 0xa2;
              uVar14 = 0xa2;
            }
            else if (uVar12 == 0x10) {
              uVar11 = 0xa3;
              uVar14 = 0xa3;
            }
            else {
              if (uVar12 != 0xe) {
LAB_0039493b:
                nvDbg_Printf("src/kernel/gpu/intr/intr_vgpu.c",0x6e,
                             "_intrCopyVfStaticInterruptTable",4,
                             "NVRM: Unknown NV2080_INTR_TYPE 0x%x\n",uVar12);
                nvAssertFailedNoLog("Unknown NV2080_INTR_TYPE","src/kernel/gpu/intr/intr_vgpu.c",
                                    0x71);
                local_5c = 0x40;
                goto LAB_003948ff;
              }
              uVar11 = 0xa1;
              uVar14 = 0xa1;
            }
            local_48._0_4_ = (uint)uVar11;
            local_48 = CONCAT44(*(undefined4 *)(lVar8 + 0x1e8),(uint)local_48);
            uVar2 = *(undefined4 *)(lVar8 + 0x1ec);
            local_40 = CONCAT44(uVar2,uVar2);
            nvDbg_Printf("src/kernel/gpu/intr/intr_vgpu.c",0x79,"_intrCopyVfStaticInterruptTable",1,
                         "NVRM: VF: Static intr MC_ENGINE_IDX=%u, stall=0x%08x, nonstall=0x%08x, pmcMask=0x%08x\n"
                         ,uVar14,uVar2,uVar2,*(undefined4 *)(lVar8 + 0x1e8));
            lVar8 = vectAppend_IMPL(lVar1,&local_48);
            if (lVar8 == 0) {
              nvAssertFailedNoLog("vectAppend(pTable, &entry) != NULL",
                                  "src/kernel/gpu/intr/intr_vgpu.c",0x80);
              local_5c = 0x51;
LAB_003948ff:
              nvAssertOkFailedNoLog
                        (local_5c,
                         "_intrCopyVfStaticInterruptTable(pGpu, pIntr, &pIntr->intrTable, pStaticParams)"
                         ,"src/kernel/gpu/intr/intr_vgpu.c",0xf6);
              return local_5c;
            }
            uVar12 = (int)uVar13 + 1;
            uVar13 = (ulong)uVar12;
          } while (uVar12 < *(uint *)(lVar7 + 0x1e0));
        }
        lVar8 = gpuGetKernelFifoShared_IMPL(param_1);
        if (iVar4 != 0) {
          iVar5 = 0;
          do {
            local_48 = 0;
            local_40 = 0;
            local_5c = (**(code **)(lVar8 + 0x218))(param_1,lVar8,0xf,iVar5,2,&local_50);
            if (local_5c != 0) {
              nvAssertOkFailedNoLog
                        (local_5c,
                         "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&rmEngineType)"
                         ,"src/kernel/gpu/intr/intr_vgpu.c",0xa5);
LAB_00394867:
              nvAssertOkFailedNoLog
                        (local_5c,
                         "_intrCopyVfDynamicInterruptTable(pGpu, pIntr, numEngines, &pIntr->intrTable, &pVSI->mcEngineNotificationIntrVectors)"
                         ,"src/kernel/gpu/intr/intr_vgpu.c",0xf9);
              return local_5c;
            }
            local_5c = (**(code **)(lVar8 + 0x218))(param_1,lVar8,0xf,iVar5,8,local_4c);
            if (local_5c != 0) {
              nvAssertOkFailedNoLog
                        (local_5c,
                         "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, ENGINE_INFO_TYPE_MC, &engineIdx)"
                         ,"src/kernel/gpu/intr/intr_vgpu.c",0xa9);
              goto LAB_00394867;
            }
            local_40 = CONCAT44(local_40._4_4_,0xffffffff);
            local_48 = CONCAT62(local_48._2_6_,local_4c._0_2_);
            iVar6 = gpuGetNv2080EngineType_IMPL(local_50);
            uVar13 = local_40;
            if (*(uint *)(lVar7 + 0x1e278) == 0) {
LAB_00394860:
              local_5c = 0xffff;
              goto LAB_00394867;
            }
            uVar9 = 0;
            while (iVar6 != *(int *)(lVar7 + 0x1e27c + uVar9 * 8)) {
              uVar9 = uVar9 + 1;
              if (*(uint *)(lVar7 + 0x1e278) == uVar9) goto LAB_00394860;
            }
            iVar6 = *(int *)(lVar7 + 0x1e280 + (uVar9 & 0xffffffff) * 8);
            local_40 = CONCAT44(iVar6,(undefined4)local_40);
            iVar15 = 0;
            if ((*(char *)(param_2 + 0x341) == '\0') && (iVar6 != -1)) {
              iVar15 = 1 << ((byte)iVar6 & 0x1f);
            }
            uVar9 = local_48 & 0xffff;
            local_48 = CONCAT44(iVar15,(uint)local_48);
            nvDbg_Printf("src/kernel/gpu/intr/intr_vgpu.c",0xd0,"_intrCopyVfDynamicInterruptTable",1
                         ,
                         "NVRM: VF: Dynamic intr MC_ENGINE_IDX=%u, stall=0x%08x, nonstall=0x%08x, pmcMask=0x%08x\n"
                         ,uVar9,uVar13 & 0xffffffff,iVar6,iVar15);
            lVar10 = vectAppend_IMPL(lVar1,&local_48);
            if (lVar10 == 0) {
              nvAssertFailedNoLog("vectAppend(pTable, &entry) != NULL",
                                  "src/kernel/gpu/intr/intr_vgpu.c",0xd6);
              local_5c = 0x51;
              goto LAB_00394867;
            }
            iVar5 = iVar5 + 1;
          } while (iVar4 != iVar5);
        }
        vectTrim_IMPL(lVar1,0);
        portMemCopy(param_2 + 0x1490,0x38,lVar7 + 0x25f28,0x38);
        return 0;
      }
      nvAssertFailedNoLog("pVSI->mcEngineNotificationIntrVectors.numEntries <= NV2080_CTRL_MC_GET_ENGINE_NOTIFICATION_INTR_VECTORS_MAX_ENGINES"
                          ,"src/kernel/gpu/intr/intr_vgpu.c",0xee);
    }
    else {
      nvAssertFailedNoLog("pStaticParams->numEntries <= NV2080_CTRL_MC_GET_STATIC_INTR_TABLE_MAX",
                          "src/kernel/gpu/intr/intr_vgpu.c",0xea);
    }
    local_5c = 0x5b;
  }
  return local_5c;
}


// ===== 00394af0 swintrRegisterIntrService_IMPL =====

void swintrRegisterIntrService_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  
  if (*(long *)(param_3 + 0x6d8) == 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      uVar1 = *(undefined8 *)(param_2 + 0x170);
    }
    *(undefined8 *)(param_3 + 0x6d8) = uVar1;
    return;
  }
  nvAssertFailedNoLog("pRecords[engineIdx].pInterruptService == NULL","src/kernel/gpu/intr/swintr.c"
                      ,0x2a);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = *(undefined8 *)(param_2 + 0x170);
  }
  *(undefined8 *)(param_3 + 0x6d8) = uVar1;
  return;
}


// ===== 00394b70 swintrServiceInterrupt_IMPL =====

undefined8 swintrServiceInterrupt_IMPL(undefined8 param_1,undefined8 param_2,short *param_3)

{
  if (param_3 == (short *)0x0) {
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/intr/swintr.c",0x3d);
    return 0;
  }
  if (*param_3 == 0x49) {
    return 0;
  }
  nvAssertFailedNoLog("Invalid engineIdx","src/kernel/gpu/intr/swintr.c",0x4e);
  return 0;
}


// ===== 00394bd0 gpuGc6Exit_IMPL =====

int gpuGc6Exit_IMPL(long param_1,long param_2)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x4b38) & 2) == 0) {
    *(undefined4 *)(param_1 + 0x4b38) = 0;
    return 0;
  }
  if (*(int *)(param_1 + 0x4b34) == 3) {
    *(undefined4 *)(param_1 + 0x4b34) = 4;
    *(undefined1 *)(param_1 + 0x4b4) = 1;
    iVar1 = gpuResumeFromStandby_IMPL();
    if (*(char *)(param_1 + 0x1b40) == '\x01') {
      *(undefined1 *)(param_2 + 6) = 1;
    }
    *(undefined1 *)(param_1 + 0x4b4) = 0;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4b34) = 0;
      nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x66,"gpuGc6Exit_IMPL",1,
                   "NVRM: GPU is now in D0 state.\n");
      *(undefined1 *)(param_1 + 0x49e) = 0;
      *(undefined1 *)(param_1 + 0x48e) = 0;
      *(undefined1 *)(param_1 + 0x488) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x4b34) = 5;
      nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x29a,"_gpuGc6ExitStateLoad",4,
                   "NVRM: GPU is unable to transition from GC6 to D0 state.\n");
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x218,"_gpuGc6ExitSanityCheck",4,
                 "NVRM: GPU is not in GC6 state.\n");
    iVar1 = 0x40;
  }
  *(undefined4 *)(param_1 + 0x4b38) = 0;
  return iVar1;
}


// ===== 00394d40 gpuGc6EntryGpuPowerOff_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gpuGc6EntryGpuPowerOff_IMPL(long param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 800))();
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog(iVar1,"gpuPrePowerOff_HAL(pGpu)","src/kernel/gpu/kern_gpu_power.c",0xcd);
    return iVar1;
  }
  if ((*(char *)(param_1 + 0x488) == '\0') || (*(char *)(param_1 + 0x226e) != '\0')) {
    iVar1 = (**(code **)(param_1 + 0x148))(param_1);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x4b34) = 2;
      *(undefined1 *)(param_1 + 0x49e) = 0;
      *(undefined1 *)(param_1 + 0x48e) = 0;
      *(undefined1 *)(param_1 + 0x488) = 0;
      nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0xdf,"gpuGc6EntryGpuPowerOff_IMPL",4,
                   "NVRM: Call to power off GPU failed.\n");
      return iVar1;
    }
  }
  else {
    nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0xd3,"gpuGc6EntryGpuPowerOff_IMPL",1,
                 "NVRM: Skip call to power off GPU in OSPM RTD3\n");
  }
  return 0;
}


// ===== 00394e60 gpuGc6Entry_IMPL =====

int gpuGc6Entry_IMPL(long param_1,int *param_2)

{
  int iVar1;
  
  if ((param_2[1] & 2U) == 0) {
    return 0;
  }
  if ((char)param_2[2] == '\0') {
    if (*(int *)(param_1 + 0x4b34) == 3) {
LAB_00394fd0:
      nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x1ad,"_gpuGc6EntrySanityCheck",4,
                   "NVRM: GPU is already in GC6 state or stuck in transition.\n");
      return 0x40;
    }
    if (*param_2 != 0) goto LAB_00394eb6;
LAB_00394ea0:
    *(undefined1 *)(param_1 + 0x49e) = 1;
    if ((char)param_2[2] == '\0') goto LAB_00394eb6;
  }
  else {
    if (*(char *)(param_1 + 0x4b1) == '\0') {
      nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x1a5,"_gpuGc6EntrySanityCheck",4,
                   "NVRM: Cannot perform RTD3 as chip does not support.\n");
      return 0x56;
    }
    if (*(int *)(param_1 + 0x4b34) == 3) goto LAB_00394fd0;
    if (*param_2 == 0) goto LAB_00394ea0;
  }
  *(undefined1 *)(param_1 + 0x488) = 1;
LAB_00394eb6:
  *(undefined4 *)(param_1 + 0x4b34) = 1;
  *(undefined1 *)(param_1 + 0x4b4) = 1;
  iVar1 = gpuEnterStandby_IMPL(param_1);
  *(undefined1 *)(param_1 + 0x4b4) = 0;
  if (iVar1 == 0) {
    iVar1 = gpuGc6EntryGpuPowerOff_IMPL(param_1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4b34) = 3;
      nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0xb4,"gpuGc6Entry_IMPL",1,
                   "NVRM: GPU is now in GC6 state.\n");
      *(uint *)(param_1 + 0x4b38) = *(uint *)(param_1 + 0x4b38) | 2;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x4b34) = 2;
    *(undefined1 *)(param_1 + 0x49e) = 0;
    *(undefined1 *)(param_1 + 0x48e) = 0;
    *(undefined1 *)(param_1 + 0x488) = 0;
    nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x1ff,"_gpuGc6EntryStateUnload",4,
                 "NVRM: GPU is unable to transition from D0 to GC6 state.\n");
  }
  return iVar1;
}


// ===== 00395040 gpuPowerOff_KERNEL =====

ulong gpuPowerOff_KERNEL(long param_1)

{
  ulong uVar1;
  
  if ((*(char *)(param_1 + 0x226e) == '\0') && (*(char *)(param_1 + 0x488) != '\0')) {
    return 0;
  }
  uVar1 = osGC6PowerControl(param_1,0x134c02,0);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,"osGC6PowerControl(pGpu, deferCmd, NULL)",
             "src/kernel/gpu/kern_gpu_power.c",0x100);
  return uVar1 & 0xffffffff;
}


// ===== 003950b0 gpuPowerOn_KERNEL =====

int gpuPowerOn_KERNEL(long param_1)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  undefined1 local_48 [2];
  undefined1 local_46 [2];
  uint local_44;
  undefined1 local_40 [24];
  
  if ((*(char *)(param_1 + 0x226e) != '\0') || (iVar2 = 0, *(char *)(param_1 + 0x488) == '\0')) {
    if ((*(char *)(param_1 + 0x49e) != '\0') &&
       (iVar2 = osGC6PowerControl(param_1,0x8000,&local_44), iVar2 != 0)) {
      nvAssertOkFailedNoLog
                (iVar2,"osGC6PowerControl(pGpu, 0x8000, &powerStatus)",
                 "src/kernel/gpu/kern_gpu_power.c",299);
      return iVar2;
    }
    timeoutSet(param_1 + 0x1af0,local_40,0,0);
    while (iVar2 = osGC6PowerControl(param_1,0,&local_44), iVar2 == 0) {
      if ((local_44 & 8) != 0) {
        uVar1 = *(ulong *)(param_1 + 0x878);
        lVar3 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,local_48,local_46);
        if (lVar3 != 0) {
          return 0;
        }
        nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x15a,"gpuPowerOn_KERNEL",3,
                     "NVRM: GPU is not yet on the bus after GC6 power-up.\n");
        timeoutSet(param_1 + 0x1af0,local_40,0,0);
        while( true ) {
          uVar1 = *(ulong *)(param_1 + 0x878);
          lVar3 = osPciInitHandle(uVar1 >> 0x20,uVar1 >> 8 & 0xff,uVar1 & 0xff,0,local_48,local_46);
          if (lVar3 != 0) {
            return 0;
          }
          iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0x160);
          if (iVar2 == 0x65) break;
          osDelay(1);
        }
        nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x164,"gpuPowerOn_KERNEL",4,
                     "NVRM: Timeout waiting for GPU to appear on the bus.\n");
        return 0x65;
      }
      iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0x140);
      if (iVar2 == 0x65) {
        nvDbg_Printf("src/kernel/gpu/kern_gpu_power.c",0x144,"gpuPowerOn_KERNEL",4,
                     "NVRM: Timeout waiting for GPU to enter PWOK/ON state.Current State %x\n",
                     local_44);
        return 0x65;
      }
      osDelay(5);
    }
    nvAssertOkFailedNoLog
              (iVar2,"osGC6PowerControl(pGpu, 0x0, &powerStatus)","src/kernel/gpu/kern_gpu_power.c",
               0x138);
  }
  return iVar2;
}


// ===== 00395310 gpuCheckGc6inD3Hot_IMPL =====

void gpuCheckGc6inD3Hot_IMPL(long param_1)

{
  *(undefined1 *)(param_1 + 0x1b40) = 0;
  return;
}


// ===== 00395320 subdeviceCtrlCmdGc6Entry_IMPL =====

void subdeviceCtrlCmdGc6Entry_IMPL(long param_1)

{
  gpuGc6Entry_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 00395340 subdeviceCtrlCmdGc6Exit_IMPL =====

void subdeviceCtrlCmdGc6Exit_IMPL(long param_1)

{
  gpuGc6Exit_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 00395360 kmcWritePmcEnableReg_GA100 =====

undefined8
kmcWritePmcEnableReg_GA100(long param_1,undefined8 param_2,uint param_3,char param_4,char param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = -(uint)(param_5 == '\0') & 0xfffffc00;
  uVar2 = regRead032(param_1 + 0x3a18,0,0,uVar3 + 0x600,0);
  uVar1 = uVar2 | param_3;
  if (param_4 == '\0') {
    uVar1 = ~param_3 & uVar2;
  }
  regWrite032(param_1 + 0x3a18,0,0,uVar3 + 0x600,uVar1,0);
  osDelayUs(2);
  return 0;
}


// ===== 003953e0 kmcGetMcBar0MapInfo_GB100 =====

undefined8
kmcGetMcBar0MapInfo_GB100
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  *param_3 = 0;
  *param_4 = 0x1000;
  return 0;
}


// ===== 00395400 kmcReadPmcBoot0_GB100 =====

void kmcReadPmcBoot0_GB100(long param_1)

{
  regRead032(param_1 + 0x3a18,0,0,0,0);
  return;
}


// ===== 00395420 kmcGetMcBar0MapInfo_GM107 =====

undefined8
kmcGetMcBar0MapInfo_GM107
          (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  *param_3 = 0;
  *param_4 = 0x1000;
  return 0;
}


// ===== 00395440 kmcPrepareForXVEReset_GM107 =====

undefined8 kmcPrepareForXVEReset_GM107(void)

{
  return 0;
}


// ===== 00395450 kmcWritePmcEnableReg_GM107 =====

undefined8
kmcWritePmcEnableReg_GM107(long param_1,undefined8 param_2,uint param_3,char param_4,char param_5)

{
  uint uVar1;
  uint uVar2;
  
  if (param_5 != '\0') {
    return 0;
  }
  uVar2 = regRead032(param_1 + 0x3a18,0,0,0x200,0);
  uVar1 = uVar2 | param_3;
  if (param_4 == '\0') {
    uVar1 = ~param_3 & uVar2;
  }
  regWrite032(param_1 + 0x3a18,0,0,0x200,uVar1,0);
  osDelayUs(2);
  return 0;
}


// ===== 003954d0 kmcReadPmcBoot0_GM107 =====

void kmcReadPmcBoot0_GM107(long param_1)

{
  regRead032(param_1 + 0x3a18,0,0,0,0);
  return;
}


// ===== 003954f0 _kmcDumpEngineFunc =====

uint _kmcDumpEngineFunc(long param_1,long param_2,long param_3)

{
  ushort uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  uVar1 = *(ushort *)(param_3 + 10);
  uVar3 = (uint)uVar1;
  if (uVar1 != 0) {
    if (uVar1 == 7) {
      uVar3 = 0;
    }
    else {
      uVar4 = *(uint *)(param_2 + 0x148);
      uVar3 = prbEncNestedStart(param_2,&DAT_00c5e8d8);
      if (uVar3 == 0) {
        uVar3 = prbEncNestedStart(param_2,&prb_fields_nvdebug_eng_mc);
        if (uVar3 == 0) {
          prbEncAddUInt32(param_2,prb_fields_nvdebug_eng_mc_rmdata,*(undefined4 *)(param_1 + 0x8e8))
          ;
          prbEncAddUInt32(param_2,0xc42b18,*(undefined4 *)(param_1 + 0x8ec));
          uVar3 = prbEncNestedEnd(param_2);
          if (uVar3 == 0) {
            lVar2 = *(long *)(&DAT_00001b90 + param_1);
            uVar6 = 0;
            uVar3 = 0;
            if (*(int *)(lVar2 + 0x55c) != 0) {
              do {
                uVar3 = prbEncNestedStart(param_2,&DAT_00c42cf8);
                if (uVar3 != 0) {
                  nvCheckOkFailedNoLog
                            (4,uVar3,"prbEncNestedStart(pPrbEnc, NVDEBUG_ENG_MC_PCI_BARS)",
                             "src/kernel/gpu/mc/kernel_mc.c",0x93);
                  break;
                }
                uVar5 = kbusGetPciBarOffset_IMPL(lVar2,uVar6);
                prbEncAddUInt64(param_2,prb_fields_nvdebug_eng_mc_pcibarinfo,uVar5);
                uVar5 = kbusGetPciBarSize_IMPL(lVar2,uVar6);
                prbEncAddUInt64(param_2,0xc42ad8,uVar5);
                uVar3 = prbEncNestedEnd(param_2);
                if (uVar3 != 0) {
                  nvCheckOkFailedNoLog
                            (4,uVar3,"prbEncNestedEnd(pPrbEnc)","src/kernel/gpu/mc/kernel_mc.c",0x9e
                            );
                  break;
                }
                uVar6 = uVar6 + 1;
              } while (uVar6 < *(uint *)(lVar2 + 0x55c));
            }
          }
          else {
            nvCheckOkFailedNoLog
                      (4,uVar3,"prbEncNestedEnd(pPrbEnc)","src/kernel/gpu/mc/kernel_mc.c",0x88);
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,uVar3,"prbEncNestedStart(pPrbEnc, NVDEBUG_ENG_MC_RM_DATA)",
                     "src/kernel/gpu/mc/kernel_mc.c",0x81);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,uVar3,"prbEncNestedStart(pPrbEnc, NVDEBUG_GPUINFO_ENG_MC)",
                   "src/kernel/gpu/mc/kernel_mc.c",0x7d);
      }
      uVar4 = prbEncUnwindNesting(param_2,uVar4 & 0xff);
      if (uVar4 == 0) {
        return uVar3;
      }
      nvCheckOkFailedNoLog
                (4,uVar4,"prbEncUnwindNesting(pPrbEnc, startingDepth)",
                 "src/kernel/gpu/mc/kernel_mc.c",0xa6);
      if (uVar3 == 0) {
        uVar3 = uVar4;
      }
    }
  }
  return uVar3;
}


// ===== 00395770 subdeviceCtrlCmdMcGetArchInfo_IMPL =====

undefined8 subdeviceCtrlCmdMcGetArchInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  cVar2 = rmcfg_IsTEGRA_NVDISP_GPUS(lVar1);
  if (cVar2 != '\0') {
    *param_2 = *(undefined4 *)(lVar1 + 0x808);
    param_2[1] = *(undefined4 *)(lVar1 + 0x80c);
    param_2[2] = *(undefined4 *)(lVar1 + 0x810);
    return 0;
  }
  *param_2 = *(undefined4 *)(lVar1 + 0x81c);
  param_2[1] = *(undefined4 *)(lVar1 + 0x818);
  param_2[2] = *(int *)(lVar1 + 0x820) << 4 | *(uint *)(lVar1 + 0x824);
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(lVar1 + 0x840);
  return 0;
}


// ===== 00395800 subdeviceCtrlCmdMcGetManufacturer_IMPL =====

undefined8 subdeviceCtrlCmdMcGetManufacturer_IMPL(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7f8);
  return 0;
}


// ===== 00395820 subdeviceCtrlCmdMcChangeReplayableFaultOwnership_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 subdeviceCtrlCmdMcChangeReplayableFaultOwnership_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(lVar1 + 0x1b98);
  if (lVar2 != 0) {
    (**(code **)(lVar2 + 0x2b0))(lVar1,lVar2,*param_2);
    return 0;
  }
  return 0x56;
}


// ===== 00395870 kmcStateInitLocked_IMPL =====

undefined8 kmcStateInitLocked_IMPL(long param_1,long param_2)

{
  int iVar1;
  uint local_1c;
  
  *(undefined1 *)(param_2 + 0x188) = 0;
  *(undefined4 *)(param_2 + 0x18c) = 0x1f;
  iVar1 = osReadRegistryDword(param_1,"PciLatencyTimerControl",&local_1c);
  if (iVar1 == 0) {
    if (local_1c == 0xffffffff) {
      *(undefined1 *)(param_2 + 0x188) = 1;
    }
    else {
      *(uint *)(param_2 + 0x18c) = local_1c >> 3 & 0x1f;
    }
  }
  if (*(long *)(param_1 + 0x1ce0) != 0) {
    nvdEngineSignUp_IMPL(param_1,*(long *)(param_1 + 0x1ce0),_kmcDumpEngineFunc,1,0xf,param_2);
  }
  return 0;
}


// ===== 00395910 kmcStateLoad_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kmcStateLoad_IMPL(long param_1,long param_2)

{
  int iVar1;
  uint local_1c;
  
  iVar1 = (**(code **)(param_1 + 0x168))();
  if (((iVar1 != 8) && (*(char *)(param_2 + 0x188) == '\0')) && (*(char *)(param_1 + 0x908) == '\0')
     ) {
    iVar1 = (**(code **)(param_1 + 0x178))(param_1,0xc,&local_1c);
    if (iVar1 == 0) {
      local_1c = (*(uint *)(param_2 + 0x18c) & 0x1f) << 0xb | local_1c & 0xffff07ff;
      (**(code **)(param_1 + 0x170))(param_1,0xc);
    }
  }
  return 0;
}


// ===== 003959b0 memmgrGetMaxContextSize_AD102 =====

void memmgrGetMaxContextSize_AD102(void)

{
  memmgrGetMaxContextSize_GA100();
  return;
}


// ===== 003959c0 memmgrGetMaxContextSize_AD104 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long memmgrGetMaxContextSize_AD104(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long local_20 [2];
  
  local_20[0] = 0;
  lVar2 = memmgrGetMaxContextSize_GA100();
  iVar1 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x178))
                    (param_1,*(long *)(param_1 + 0x1b70),local_20);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"kmemsysGetUsableFbSize_HAL(pGpu, pKernelMemorySystem, &fbSize)",
               "src/kernel/gpu/mem_mgr/arch/ada/mem_mgr_ad104.c",0x2d);
  }
  lVar3 = lVar2 + 0xa00000;
  if (0xb < (uint)(local_20[0] + 0x3fffffffU >> 0x1e)) {
    lVar3 = lVar2;
  }
  return lVar3;
}


// ===== 00395a50 fbsrSendMemsysProgramRawCompressionMode_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fbsrSendMemsysProgramRawCompressionMode_GA100
               (long param_1,undefined8 param_2,undefined1 param_3)

{
  undefined1 local_9;
  
  local_9 = param_3;
  (**(code **)(param_1 + 0x3b90))
            (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),*(undefined4 *)(param_1 + 0x3b3c),
             0x20800a6f,&local_9,1);
  return;
}


// ===== 00395a90 fbsrBegin_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void fbsrBegin_GA100(long param_1,long param_2,int param_3)

{
  int iVar1;
  long lVar2;
  
  if (((param_3 == 2) && (*(char *)(param_1 + 0x908) == '\0')) &&
     (*(char *)(*(long *)(param_1 + 0x1b70) + 0x2a0) != '\0')) {
    lVar2 = kmemsysGetStaticConfig_IMPL();
    if (*(char *)(lVar2 + 2) != '\0') {
      iVar1 = (**(code **)(param_2 + 0x70))(param_1,param_2,0);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,"fbsrSendMemsysProgramRawCompressionMode_HAL(pGpu, pFbsr, NV_FALSE)",
                   "src/kernel/gpu/mem_mgr/arch/ampere/fbsr_ga100.c",0x4c);
      }
      *(undefined1 *)(param_2 + 0x107) = 1;
    }
    fbsrBegin_GM107(param_1,param_2,2);
    return;
  }
  fbsrBegin_GM107(param_1,param_2,param_3);
  return;
}


// ===== 00395b60 fbsrEnd_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 fbsrEnd_GA100(long param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_1 + 0x1b70);
  uVar2 = fbsrEnd_GM107();
  if ((((*(int *)(param_2 + 0x88) == 2) && (*(char *)(param_2 + 0x107) != '\0')) &&
      (*(char *)(param_1 + 0x908) == '\0')) && (*(char *)(lVar1 + 0x2a0) != '\0')) {
    iVar3 = (**(code **)(param_2 + 0x70))(param_1,param_2,1);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,"fbsrSendMemsysProgramRawCompressionMode_HAL(pGpu, pFbsr, NV_TRUE)",
                 "src/kernel/gpu/mem_mgr/arch/ampere/fbsr_ga100.c",0x68);
    }
    *(undefined1 *)(param_2 + 0x107) = 0;
  }
  return uVar2;
}


// ===== 00395c10 memmgrGetFlaKind_GA100 =====

undefined8 memmgrGetFlaKind_GA100(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  *param_3 = 0xf;
  return 0;
}


// ===== 00395c20 memmgrAllocDetermineAlignment_GA100 =====

void memmgrAllocDetermineAlignment_GA100
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

{
  kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  memmgrAllocDetermineAlignment_GM107(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ===== 00395cb0 memmgrScrubRegistryOverrides_GA100 =====

void memmgrScrubRegistryOverrides_GA100(long param_1,long param_2)

{
  char cVar1;
  
  if ((((*(char *)(param_1 + 0x490e) == '\0') && (*(char *)(param_1 + 0x4a3) == '\0')) &&
      ((*(char *)(param_1 + 0x908) == '\0' || (*(char *)(param_1 + 0x4913) != '\0')))) &&
     ((*(char *)(param_1 + 0x44d) == '\0' || (*(char *)(param_2 + 0x43f) != '\0')))) {
    if (*(char *)(param_2 + 0x480) != '\0') {
      if ((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) == '\0')) {
        cVar1 = gpuIsApmFeatureEnabled_IMPL();
        if (cVar1 != '\0') {
          *(undefined1 *)(param_2 + 0x485) = 1;
        }
        return;
      }
      *(undefined1 *)(param_2 + 0x485) = 1;
    }
    return;
  }
  *(undefined1 *)(param_2 + 0x480) = 0;
  return;
}


// ===== 00395d50 memmgrReadMmuLock_GA100 =====

undefined8
memmgrReadMmuLock_GA100
          (long param_1,undefined8 param_2,undefined1 *param_3,ulong *param_4,ulong *param_5)

{
  uint uVar1;
  ulong uVar2;
  
  param_1 = param_1 + 0x3a18;
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  uVar1 = regRead032(param_1,0,0,0x1fa7c8,0);
  if ((uVar1 & 1) != 0) {
    uVar1 = regRead032(param_1,0,0,&DAT_001fa82c,0);
    *param_4 = (ulong)(uVar1 >> 4) << 0xc;
    uVar1 = regRead032(param_1,0,0,&DAT_001fa830,0);
    uVar2 = (ulong)(uVar1 >> 4) << 0xc;
    *param_5 = uVar2;
    if (*param_4 <= uVar2) {
      *param_3 = 1;
    }
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0xad,"memmgrReadMmuLock_GA100",4
               ,"NVRM: MMU_LOCK read permission disabled, PLM val 0x%0x\n",uVar1);
  nvAssertFailedNoLog(&DAT_00d445b3,"src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0xaf);
  return 0x1a;
}


// ===== 00395e50 memmgrBlockMemLockedMemory_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrBlockMemLockedMemory_GA100(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  char local_51;
  long local_50;
  long local_48;
  long local_40;
  long local_38;
  undefined8 local_30;
  undefined1 local_28;
  undefined8 local_24;
  undefined1 local_1c;
  
  local_51 = '\0';
  local_50 = 0;
  local_48 = 0;
  iVar1 = (**(code **)(param_2 + 0x358))(param_1,param_2,&local_51,&local_50,&local_48);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,
               "memmgrReadMmuLock_HAL(pGpu, pMemoryManager, &bIsMmuLockValid, &memLockLo, &memLockHi)"
               ,"src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0xd8);
    return iVar1;
  }
  iVar1 = 0;
  if (local_51 != '\0') {
    uVar2 = local_48 + 0xffff;
    local_48 = (uVar2 & 0xffffffffffff0000) - 1;
    if (uVar2 >> 0x14 == *(ulong *)(param_2 + 0x830)) {
      portMemSet(&local_40,0,0x28);
      local_30 = 0;
      local_40 = local_50;
      local_38 = local_48;
      uVar2 = (local_48 + 0x1000) - local_50 & 0xfffffffffffff000;
      local_28 = 1;
      local_24 = 0;
      local_1c = 1;
      memmgrInsertFbRegion_IMPL(param_1,param_2,&local_40);
      *(long *)(param_2 + 0x828) = *(long *)(param_2 + 0x828) - uVar2;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0xfb,
                   "memmgrBlockMemLockedMemory_GA100",1,
                   "NVRM: Blocked  Start: 0x%0llx End: 0x%0llx Size: 0x%0llx\n",local_50,local_48,
                   uVar2);
      return 0;
    }
    iVar1 = 0x40;
  }
  return iVar1;
}


// ===== 00395fc0 memmgrGetMaxContextSize_GA100 =====

void memmgrGetMaxContextSize_GA100(void)

{
  memmgrGetMaxContextSize_TU102();
  return;
}


// ===== 00395fd0 memmgrGetDisablePlcKind_GA100 =====

void memmgrGetDisablePlcKind_GA100(undefined8 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 9;
  }
  return;
}


// ===== 00395fe0 memmgrEnableDynamicPageOfflining_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrEnableDynamicPageOfflining_GA100(long param_1,long param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(param_1 + 0x350))();
  if (cVar1 != '\0') {
    *(undefined1 *)(param_2 + 0x443) = 1;
  }
  return;
}


// ===== 00396040 memmgrGetBlackListPages_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrGetBlackListPages_GA100(long param_1,undefined8 param_2,long param_3,uint *param_4)

{
  char cVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  uint uVar5;
  ulong uVar6;
  uint uVar8;
  int local_3c;
  ulong uVar7;
  
  if (*(char *)(param_1 + 0x457) == '\0') {
    return 0x56;
  }
  cVar1 = (**(code **)(param_1 + 0x2f0))();
  iVar2 = 0x56;
  if (cVar1 != '\0') {
    plVar3 = (long *)portMemAllocNonPaged(0x410);
    if (plVar3 == (long *)0x0) {
      iVar2 = 0x51;
    }
    else {
      local_3c = 0;
      uVar6 = 0;
      while( true ) {
        uVar5 = (uint)uVar6;
        portMemSet(plVar3,0,0x410);
        *(int *)((long)plVar3 + 0x404) = local_3c;
        iVar2 = (**(code **)(param_1 + 0x3b90))
                          (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                           *(undefined4 *)(param_1 + 0x3b3c),0x20801348,plVar3,0x410);
        if (iVar2 != 0) break;
        uVar8 = 0;
        plVar4 = plVar3;
        uVar7 = uVar6;
        if ((int)plVar3[0x80] != 0) {
          do {
            uVar5 = (uint)uVar7;
            if (*param_4 <= uVar5) {
              iVar2 = 2;
              goto LAB_0039617a;
            }
            uVar8 = uVar8 + 1;
            uVar6 = (ulong)(uVar5 + 1);
            *(long *)(param_3 + uVar7 * 0x10) = *plVar4 << 0xc;
            *(uint *)(param_3 + 8 + uVar7 * 0x10) = (uint)*(byte *)(plVar4 + 1);
            plVar4 = plVar4 + 2;
            uVar7 = uVar6;
          } while (uVar8 < *(uint *)(plVar3 + 0x80));
        }
        uVar5 = (uint)uVar6;
        if (((char)plVar3[0x81] == '\0') || (local_3c = local_3c + 0x40, local_3c == 0x200))
        goto LAB_0039617a;
      }
      if (iVar2 - 0x56U < 2) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0x18d,
                     "memmgrGetBlackListPages_GA100",4,"NVRM: No blacklisted pages\n");
      }
      else {
        nvAssertFailedNoLog(&DAT_00d445b3,"src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0x192
                           );
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0x193,
                     "memmgrGetBlackListPages_GA100",4,"NVRM: Failed to read black list addresses\n"
                    );
      }
LAB_0039617a:
      portMemFree(plVar3);
      *param_4 = uVar5;
    }
  }
  return iVar2;
}


// ===== 00396270 memmgrInsertUnprotectedRegionAtBottomOfFb_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int memmgrInsertUnprotectedRegionAtBottomOfFb_GA100(undefined8 param_1,long param_2,ulong *param_3)

{
  int iVar1;
  ulong uVar2;
  char local_61;
  long local_60;
  long local_58 [4];
  uint local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_38 = 0;
  uStack_34 = 0;
  local_30 = 0;
  uStack_2c = 0;
  local_60 = 0;
  local_58[0] = 0;
  local_61 = '\0';
  iVar1 = (**(code **)(param_2 + 0x358))(param_1,param_2,&local_61,&local_60,local_58);
  if (iVar1 == 0) {
    if (local_61 == '\0') {
      *param_3 = 0;
    }
    else {
      local_58[1] = 0;
      local_58[3] = 0;
      local_58[0] = (local_58[0] + 0xffffU & 0xffffffffffff0000) - 1;
      local_38 = local_38 & 0xffffff00;
      uVar2 = (local_58[0] - local_60) + 0x1000U & 0xfffffffffffff000;
      if (uVar2 < 0x60000000) {
        uVar2 = 0x60000000;
      }
      uVar2 = uVar2 + 0xfffff & 0xfffffffffff00000;
      local_58[2] = uVar2 - 1;
      uStack_34 = 0;
      local_30 = 1;
      memmgrInsertFbRegion_IMPL(param_1,param_2,local_58 + 1);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0x1ef,
                   "memmgrInsertUnprotectedRegionAtBottomOfFb_GA100",1,
                   "NVRM: Unprotected Block Start: 0x%0llx End: 0x%0llx Size: 0x%0llx\n",local_60,
                   local_58[0],uVar2);
      *param_3 = uVar2;
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar1,
               "memmgrReadMmuLock_HAL(pGpu, pMemoryManager, &bIsMmuLockValid, &memLockLo, &memLockHi)"
               ,"src/kernel/gpu/mem_mgr/arch/ampere/mem_mgr_ga100.c",0x1c8);
  }
  return iVar1;
}


// ===== 00396400 memmgrIsMemDescSupportedByFla_GA100 =====

undefined8 memmgrIsMemDescSupportedByFla_GA100(long param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = memdescGetAddressSpace(param_3);
  if ((iVar1 == 2) && (*param_3 == param_1)) {
    uVar2 = 1;
  }
  else {
    uVar2 = memdescIsEgm(param_3);
    if ((char)uVar2 != '\0') {
      uVar2 = CONCAT71((int7)((ulong)*param_3 >> 8),
                       *(int *)(*param_3 + 0x7c0) == *(int *)(param_1 + 0x7c0));
    }
  }
  return uVar2;
}


// ===== 00396460 memmgrIsValidFlaPageSize_GA100 =====

bool memmgrIsValidFlaPageSize_GA100(undefined8 param_1,undefined8 param_2,long param_3,char param_4)

{
  if (param_3 != 0x200000) {
    return param_3 == 0x20000000;
  }
  return param_4 == '\0';
}


// ===== 00396490 memmgrEnableDynamicPageOfflining_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrEnableDynamicPageOfflining_GA102(long param_1,long param_2)

{
  char cVar1;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    cVar1 = hypervisorIsVgxHyper_IMPL();
    if (((cVar1 != '\0') || (cVar1 = (**(code **)(param_1 + 0x350))(), cVar1 != '\0')) ||
       (*(char *)(param_1 + 0x491d) != '\0')) {
      *(undefined1 *)(param_2 + 0x443) = 1;
    }
    return;
  }
  *(undefined1 *)(param_2 + 0x443) = 1;
  return;
}


// ===== 00396500 memmgrIsFlaSysmemSupported_GB100 =====

bool memmgrIsFlaSysmemSupported_GB100(long param_1,long param_2)

{
  bool bVar1;
  
  if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) == '\0')) {
    bVar1 = false;
    if (*(char *)(param_2 + 0x470) != '\0') {
      return *(char *)(param_2 + 0x454) == '\0';
    }
  }
  else {
    bVar1 = *(char *)(param_2 + 0x454) == '\0';
  }
  return bVar1;
}


// ===== 00396540 memmgrIsMemDescSupportedByFla_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 memmgrIsMemDescSupportedByFla_GB100(undefined8 param_1,long param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = memdescGetAddressSpace(param_3);
  if (iVar2 == 1) {
    cVar1 = (**(code **)(param_2 + 0x418))(param_1,param_2);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  uVar3 = memmgrIsMemDescSupportedByFla_GA100(param_1,param_2,param_3);
  return uVar3;
}


// ===== 003965b0 memmgrGetFBEndReserveSizeEstimate_GB100 =====

undefined8 memmgrGetFBEndReserveSizeEstimate_GB100(void)

{
  return 0x220000;
}


// ===== 003965c0 memmgrGetLocalizedOffset_GB100 =====

undefined8 memmgrGetLocalizedOffset_GB100(void)

{
  return 0x27;
}


// ===== 003965d0 memmgrIsValidFlaPageSize_GB100 =====

bool memmgrIsValidFlaPageSize_GB100(undefined8 param_1,undefined8 param_2,long param_3,char param_4)

{
  if ((param_3 != 0x20000000) && (param_3 != 0x4000000000)) {
    if (param_3 != 0x200000) {
      return false;
    }
    return param_4 == '\0';
  }
  return true;
}


// ===== 00396620 memmgrSc7SrInitGsp_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong memmgrSc7SrInitGsp_GB10B(long param_1,long param_2)

{
  ulong uVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  undefined8 local_20;
  
  local_30 = *(undefined4 *)(param_2 + 0xd10);
  local_28 = 0;
  local_2c = 0;
  local_20 = memdescGetPhysAddr(*(undefined8 *)(*(long *)(param_1 + 0x1ba8) + 0xaa0),1,0);
  uVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20800ac2,&local_30,0x18);
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,
             "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_FBSR_INIT, &params, sizeof(params))"
             ,"src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b.c",0x2f);
  return uVar1 & 0xffffffff;
}


// ===== 003966d0 memmgrInitZeroFbRegionsHal_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrInitZeroFbRegionsHal_GB10B(long param_1,long param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x490e) == '\0') {
    iVar1 = (**(code **)(param_2 + 1000))();
    if (iVar1 != 0x56) {
      if (iVar1 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x74,
                   "memmgrInitZeroFbRegionsHal_GB10B",4,
                   "NVRM: Failed to create scanout carveout heap.\n");
      return iVar1;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x6e,
                 "memmgrInitZeroFbRegionsHal_GB10B",1,
                 "NVRM: Carveout supported not configured on this platform\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x61,
                 "memmgrInitZeroFbRegionsHal_GB10B",1,
                 "NVRM: Carveout support not available on simulation\n");
  }
  return 0;
}


// ===== 003967a0 memmgrCreateScanoutCarveoutHeap_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined1  [16] memmgrCreateScanoutCarveoutHeap_GB10B(long param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 extraout_RDX;
  int *piVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  undefined1 auVar10 [16];
  uint local_f0 [2];
  long alStack_e8 [2];
  int local_d8 [44];
  
  portMemSet(local_f0,0,200);
  iVar1 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20801360,local_f0,200);
  if (iVar1 == 0) {
    uVar3 = 0;
    piVar5 = local_d8;
    if (local_f0[0] != 0) {
      do {
        if (*piVar5 == 0) {
          lVar8 = alStack_e8[uVar3 * 3];
          lVar9 = alStack_e8[uVar3 * 3 + 1];
          goto LAB_00396869;
        }
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulong)uVar2;
        piVar5 = piVar5 + 6;
      } while (uVar2 != local_f0[0]);
    }
    lVar9 = 0;
    lVar8 = 0;
LAB_00396869:
    auVar10 = portMemAllocNonPaged(0xd8);
    uVar6 = auVar10._8_8_;
    lVar4 = auVar10._0_8_;
    *(long *)(param_2 + 0x428) = lVar4;
    if (lVar4 != 0) {
      constructObjEHeap(lVar4,lVar8,lVar9 + lVar8,0,0);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x91,
                   "memmgrCreateScanoutCarveoutHeap_GB10B",1,
                   "NVRM: Created scanout carveout heap with base address=0x%llx and size=%llx\n",
                   lVar8,lVar9);
      return ZEXT816(0x396898) << 0x40;
    }
    uVar7 = 0x51;
  }
  else {
    *(undefined1 *)(param_1 + 0x4bd) = 0;
    uVar7 = 0;
    uVar6 = extraout_RDX;
  }
  auVar10._8_8_ = uVar6;
  auVar10._0_8_ = uVar7;
  return auVar10;
}


// ===== 00396920 memmgrDestroyScanoutCarveoutHeap_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 memmgrDestroyScanoutCarveoutHeap_GB10B(undefined8 param_1,long param_2)

{
  if (*(undefined8 **)(param_2 + 0x428) != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)(param_2 + 0x428))();
    portMemFree(*(undefined8 *)(param_2 + 0x428));
    *(undefined8 *)(param_2 + 0x428) = 0;
    return 0;
  }
  return 0;
}


// ===== 00396970 memmgrAllocScanoutCarveoutRegionResources_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrAllocScanoutCarveoutRegionResources_GB10B
              (long param_1,long param_2,undefined4 param_3,undefined8 param_4,long param_5)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  undefined8 local_48;
  undefined8 local_40 [2];
  
  local_48 = *(undefined8 *)(param_2 + 0x50);
  lVar1 = *(long *)(param_1 + 0x428);
  uVar2 = *(undefined8 *)(param_2 + 0x48);
  local_40[0] = *(undefined8 *)(param_5 + 0x30);
  if (lVar1 == 0) {
    nvCheckFailedNoLog(1,"pHeap != NULL",
                       "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0xc2);
    return 0x40;
  }
  cVar3 = memdescGetFlag(param_5,0x8000000000000);
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("memdescGetFlag(pMemDesc, MEMDESC_FLAGS_ALLOC_FROM_SCANOUT_CARVEOUT)",
                        "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0xc4);
  }
  iVar4 = (**(code **)(lVar1 + 8))(lVar1,param_3,param_4,&local_48,local_40,uVar2,uVar2,0,0,0);
  if (iVar4 == 0) {
    memdescSetPte(param_5,0,0,local_48);
    memdescSetContiguity(param_5,0,1);
    *(undefined8 *)(param_5 + 0x30) = local_40[0];
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0xca,
               "memmgrAllocScanoutCarveoutRegionResources_GB10B",4,
               "NVRM: EheapAlloc returns error 0x%0x\n",iVar4);
  return iVar4;
}


// ===== 00396af0 memmgrAllocFromScanoutCarveoutRegion_GB10B =====

undefined8 memmgrAllocFromScanoutCarveoutRegion_GB10B(void)

{
  nvCheckFailedNoLog(1,"pMemorySystem != NULL",
                     "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0xf1);
  return 0x40;
}


// ===== 00396b20 memmgrFreeScanoutCarveoutRegionResources_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrFreeScanoutCarveoutRegionResources_GB10B(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x428);
  if (lVar1 == 0) {
    nvCheckFailedNoLog(1,"pHeap != NULL",
                       "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x133);
    return;
  }
  lVar3 = (**(code **)(lVar1 + 0x40))(lVar1,param_2,0);
  if (lVar3 != 0) {
    iVar2 = (**(code **)(lVar1 + 0x10))(lVar1,param_2);
    if (iVar2 == 0) {
      return;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x140,
                 "memmgrFreeScanoutCarveoutRegionResources_GB10B",4,
                 "NVRM: Error in freeing eheap 0x%0x\n",iVar2);
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x139,
               "memmgrFreeScanoutCarveoutRegionResources_GB10B",4,
               "NVRM: Not found allocation in carveout region");
  return;
}


// ===== 00396c10 memmgrFreeFromScanoutCarveoutRegion_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrFreeFromScanoutCarveoutRegion_GB10B(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_3 == 0) {
    nvCheckFailedNoLog(1,"pMemDesc != NULL",
                       "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x158);
    return;
  }
  lVar2 = *(long *)(param_2 + 0x428);
  if (lVar2 != 0) {
    uVar1 = memdescGetPte(param_3,0,0);
    lVar2 = (**(code **)(lVar2 + 0x40))(lVar2,uVar1,0);
    if (lVar2 != 0) {
      if (*(int *)(lVar2 + 0x1c) == 0) {
        memdescFree(param_3);
        memdescDestroy(param_3);
      }
      else {
        memdescRemoveRef();
      }
      (**(code **)(param_2 + 0x3d8))(param_2,uVar1);
      return;
    }
    nvCheckFailedNoLog(1,"pBlock != NULL",
                       "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x15d);
    return;
  }
  nvCheckFailedNoLog(1,"pEHeap != NULL","src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c"
                     ,0x159);
  return;
}


// ===== 00396d40 memmgrDuplicateFromScanoutCarveoutRegion_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
memmgrDuplicateFromScanoutCarveoutRegion_GB10B(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_3 == 0) {
    nvCheckFailedNoLog(1,"pMemDesc != NULL",
                       "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x184);
    return 0x1f;
  }
  lVar2 = *(long *)(param_2 + 0x428);
  if (lVar2 == 0) {
    nvCheckFailedNoLog(1,"pEHeap != NULL",
                       "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x185);
  }
  else {
    uVar1 = memdescGetPte(param_3,0,0);
    lVar2 = (**(code **)(lVar2 + 0x40))(lVar2,uVar1,0);
    if (lVar2 != 0) {
      *(int *)(lVar2 + 0x1c) = *(int *)(lVar2 + 0x1c) + 1;
      return 0;
    }
    nvCheckFailedNoLog(1,"pBlock != NULL",
                       "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x189);
  }
  return 0x40;
}


// ===== 00396e00 memmgrAllocateConsoleRegion_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrAllocateConsoleRegion_GB10B(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  int *piVar4;
  uint local_e0 [2];
  undefined8 auStack_d8 [2];
  int local_c8 [44];
  
  portMemSet(local_e0,0,200);
  iVar2 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                     *(undefined4 *)(param_1 + 0x3b3c),0x20801360,local_e0,200);
  if (iVar2 == 0) {
    if (*(long *)(param_2 + 0xb60) == 0) {
      piVar4 = local_c8;
      uVar3 = 0;
      if (local_e0[0] != 0) {
        do {
          if (*piVar4 == 2) {
            iVar2 = memdescCreate(param_2 + 0xb60,param_1,auStack_d8[uVar3 * 3 + 1],0x10000,1,1,1,
                                  0x80000000020000);
            if (iVar2 != 0) {
              return iVar2;
            }
            memdescDescribe(*(undefined8 *)(param_2 + 0xb60),1,auStack_d8[uVar3 * 3],
                            auStack_d8[uVar3 * 3 + 1]);
            memdescSetPageSize(*(undefined8 *)(param_2 + 0xb60),0,0x1000);
            nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x1de,
                         "memmgrAllocateConsoleRegion_GB10B",1,
                         "NVRM: Allocating console region of size: %llx, at base : %llx \n ",
                         auStack_d8[uVar3 * 3 + 1],auStack_d8[uVar3 * 3]);
            return 0;
          }
          uVar1 = (int)uVar3 + 1;
          uVar3 = (ulong)uVar1;
          piVar4 = piVar4 + 6;
        } while (local_e0[0] != uVar1);
      }
    }
    else {
      nvAssertFailedNoLog("pMemoryManager->pReservedConsoleMemDesc == NULL",
                          "src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb10b_phys.c",0x1bc);
      iVar2 = 99;
    }
  }
  return iVar2;
}


// ===== 00396fd0 memmgrChooseKindZ_GB202 =====

undefined8 memmgrChooseKindZ_GB202(void)

{
  return 6;
}


// ===== 00396fe0 memmgrChooseKindCompressZ_GB202 =====

undefined8 memmgrChooseKindCompressZ_GB202(void)

{
  return 8;
}


// ===== 00396ff0 memmgrGetUncompressedKind_GB202 =====

byte memmgrGetUncompressedKind_GB202(undefined8 param_1,undefined8 param_2,int param_3)

{
  return -(param_3 != 0) & 6;
}


// ===== 00397000 memmgrGetCompressedKind_GB202 =====

int memmgrGetCompressedKind_GB202(undefined8 param_1,undefined8 param_2,char param_3)

{
  return 9 - (uint)(param_3 == '\0');
}


// ===== 00397010 memmgrGetMaxContextSize_GB202 =====

undefined1  [16] memmgrGetMaxContextSize_GB202(long param_1,long param_2)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  
  uVar2 = memmgrGetMaxContextSize_GA100();
  if ((*(char *)(param_1 + 0x909) != '\0') && (*(char *)(param_1 + 0x4a23) != '\0')) {
    uVar2 = uVar2 + 0x3200000;
  }
  uVar1 = *(ulong *)(param_2 + 0xba8);
  if (uVar2 <= uVar1 - 1) {
    auVar3._8_8_ = uVar1;
    auVar3._0_8_ = uVar2;
    return auVar3;
  }
  auVar4._8_8_ = uVar1 >> 0x14;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb202.c",0x87,
               "memmgrGetMaxContextSize_GB202",4,
               "NVRM: Max context size set from %llu MB to %llu MB\n",uVar2 >> 0x14);
  auVar4._0_8_ = *(undefined8 *)(param_2 + 0xba8);
  return auVar4;
}


// ===== 003970b0 memmgrIsKind_GB202 =====

bool memmgrIsKind_GB202(undefined8 param_1,uint param_2,ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_3;
  if (param_2 < 9) {
    if (param_2 < 6) {
      if (param_2 != 1) {
        if (param_2 < 2) {
          return uVar2 - 1 < 5 || uVar2 - 10 < 5;
        }
        if (param_2 < 4) {
          return false;
        }
        if (param_2 != 5) goto LAB_00397140;
      }
      return uVar2 - 8 < 7;
    }
  }
  else {
    if (param_2 == 10) {
      return uVar2 != 8;
    }
    if (param_2 == 0xb) {
      if (0xf < uVar2) {
        return true;
      }
      return (0xffffffffffff7cbeU >> (param_3 & 0x3f) & 1) != 0;
    }
    if (param_2 != 9) {
LAB_00397140:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb202_base.c",0x45,
                   "memmgrIsKind_GB202",4,"NVRM: Bad op (%08x) passed in\n",param_2);
      return false;
    }
    if (uVar2 < 0x10) {
      uVar1 = 1L << ((byte)param_3 & 0x3f);
      if ((uVar1 & 0x8340) != 0) {
        return true;
      }
      if ((uVar1 & 0x81) != 0) {
        return uVar2 != 7;
      }
    }
  }
  return false;
}


// ===== 003971a0 memmgrChooseKindZ_GB20B =====

long memmgrChooseKindZ_GB20B(void)

{
  long lVar1;
  
  lVar1 = memmgrChooseKindZ_TU102();
  if ((int)lVar1 != 2) {
    lVar1 = (ulong)((int)lVar1 != 1) * 5 + 1;
  }
  return lVar1;
}


// ===== 003971d0 memmgrChooseKindCompressZ_GB20B =====

long memmgrChooseKindCompressZ_GB20B(void)

{
  long lVar1;
  
  lVar1 = memmgrChooseKindCompressZ_TU102();
  if ((int)lVar1 != 10) {
    lVar1 = (ulong)((int)lVar1 == 0xb) * 3 + 8;
  }
  return lVar1;
}


// ===== 00397200 memmgrGetUncompressedKind_GB20B =====

ulong memmgrGetUncompressedKind_GB20B(void)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = memmgrGetUncompressedKind_TU102();
  iVar1 = (int)uVar2;
  if ((iVar1 != 2) && (iVar1 != 1)) {
    uVar2 = (ulong)(~-(uint)(iVar1 == 0) & 6);
  }
  return uVar2;
}


// ===== 00397230 memmgrGetCompressedKind_GB20B =====

int memmgrGetCompressedKind_GB20B(undefined8 param_1,uint param_2,char param_3)

{
  int iVar1;
  ulong uVar2;
  
  if (param_2 < 0xc) {
    uVar2 = 1L << ((byte)param_2 & 0x3f);
    if ((uVar2 & 0x340) != 0) {
      return 9 - (uint)(param_3 == '\0');
    }
    iVar1 = 10;
    if (((uVar2 & 0x404) != 0) || (iVar1 = 0xb, (uVar2 & 0x802) != 0)) {
      return iVar1;
    }
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb20b.c",0xa5,
               "memmgrGetCompressedKind_GB20B",4,"NVRM: Unknown kind 0x%x.\n",param_2);
  return 7;
}


// ===== 003972c0 memmgrIsMemoryIoCoherent_GB20B =====

byte memmgrIsMemoryIoCoherent_GB20B(undefined8 param_1,undefined8 param_2,long param_3)

{
  return *(byte *)(param_3 + 0x1e) >> 2 & 1 ^ 1;
}


// ===== 003972e0 memmgrIsKind_GB20B =====

bool memmgrIsKind_GB20B(undefined8 param_1,uint param_2,ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_3;
  if (param_2 < 9) {
    if (param_2 < 6) {
      if (param_2 != 1) {
        if (param_2 < 2) {
          return uVar2 - 1 < 5 || uVar2 - 10 < 5;
        }
        if (param_2 < 4) {
          return false;
        }
        if (param_2 != 5) goto LAB_00397370;
      }
      return uVar2 - 8 < 7;
    }
  }
  else {
    if (param_2 == 10) {
      return uVar2 != 8;
    }
    if (param_2 == 0xb) {
      if (0xf < uVar2) {
        return true;
      }
      return (0xffffffffffff7cbeU >> (param_3 & 0x3f) & 1) != 0;
    }
    if (param_2 != 9) {
LAB_00397370:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/blackwell/mem_mgr_gb20b_base.c",0x45,
                   "memmgrIsKind_GB20B",4,"NVRM: Bad op (%08x) passed in\n",param_2);
      return false;
    }
    if (uVar2 < 0x10) {
      uVar1 = 1L << ((byte)param_3 & 0x3f);
      if ((uVar1 & 0x8f46) != 0) {
        return true;
      }
      if ((uVar1 & 0x81) != 0) {
        return uVar2 != 7;
      }
    }
  }
  return false;
}


// ===== 003973d0 memmgrMemUtilsCheckMemoryFastScrubEnable_GH100 =====

ulong memmgrMemUtilsCheckMemoryFastScrubEnable_GH100
                (undefined8 param_1,long param_2,uint param_3,char param_4,uint param_5,uint param_6
                ,int param_7)

{
  ulong uVar1;
  
  uVar1 = (ulong)*(byte *)(param_2 + 0x481);
  if (*(byte *)(param_2 + 0x481) != 0) {
    if ((((int)((ulong)param_3 & 0xfffffffffffffeff) == 0xc8b5) || (param_3 == 0xcab5)) &&
       (param_4 == '\0')) {
      if ((param_7 == 2) && ((param_5 & 0xfff) == 0)) {
        return CONCAT71((int7)(((ulong)param_3 & 0xfffffffffffffeff) >> 8),(param_6 & 0xfff) == 0);
      }
      return 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00397430 memmgrMemUtilsSec2CtxInit_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrMemUtilsSec2CtxInit_GH100(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmapiGetInterface(4);
  iVar1 = (**(code **)(lVar2 + 8))
                    (lVar2,*(undefined4 *)(param_3 + 0xac),*(undefined4 *)(param_3 + 8),
                     *(undefined4 *)(param_3 + 0x18),*(undefined4 *)(param_3 + 0x120),0,0);
  if (iVar1 == 0) {
    iVar1 = memmgrMemUtilsChannelSchedulingSetup_IMPL(param_1,param_2,param_3,0x397456);
    if (iVar1 == 0) {
      return 0;
    }
    nvCheckOkFailedNoLog
              (4,iVar1,"memmgrMemUtilsChannelSchedulingSetup(pGpu, pMemoryManager, pChannel)",
               "src/kernel/gpu/mem_mgr/arch/hopper/mem_utils_gh100.c",0x6c);
  }
  else {
    nvCheckOkFailedNoLog
              (4,iVar1,
               "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, pChannel->channelId, pChannel->engineObjectId, pChannel->sec2Class, NULL, 0)"
               ,"src/kernel/gpu/mem_mgr/arch/hopper/mem_utils_gh100.c",0x61);
  }
  (**(code **)(lVar2 + 0x18))(lVar2,*(undefined4 *)(param_3 + 0xac),*(undefined4 *)(param_3 + 0xac))
  ;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/hopper/mem_utils_gh100.c",0x75,
               "memmgrMemUtilsSec2CtxInit_GH100",1,"NVRM: end  NV_STATUS=0x%08x\n",iVar1);
  return iVar1;
}


// ===== 00397570 dmaAllocBar1P2PMapping_GH100 =====

int dmaAllocBar1P2PMapping_GH100(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 *local_48;
  undefined8 local_40;
  long local_38;
  long local_30;
  
  local_48 = (undefined8 *)0x0;
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  if ((((param_3 != (long *)0x0) && (*param_3 != 0)) && (lVar1 = param_3[1], lVar1 != 0)) &&
     ((param_3[2] != 0 && (param_3[8] != 0)))) {
    uVar4 = *(undefined8 *)(&DAT_00001b90 + lVar1);
    iVar2 = memdescCreateSubMem(&local_40,param_3[2],lVar1,param_3[5],param_3[7]);
    if (iVar2 != 0) {
      return iVar2;
    }
    local_30 = param_3[7];
    iVar2 = kbusMapFbApertureSingle_IMPL(lVar1,uVar4,local_40,0,&local_38,&local_30,0x20);
    if (iVar2 == 0) {
      lVar3 = gpumgrGetGpuPhysFbAddr(lVar1);
      lVar3 = lVar3 + local_38;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/hopper/virt_mem_allocator_gh100.c",99,
                   "dmaAllocBar1P2PMapping_GH100",1,
                   "NVRM: bar1p2p surface mapped at bar1PhyAddr 0x%llx, len 0x%llx\n",lVar3,local_30
                  );
      iVar2 = memdescCreate(&local_48,lVar1,local_30,0,1,1,1,0);
      if (iVar2 == 0) {
        uVar4 = memdescGetPageSize(local_40,*(undefined8 *)(*param_3 + 0x50));
        memdescSetPageSize(local_48,*(undefined8 *)(*param_3 + 0x50),uVar4);
        memdescSetPteKindForGpu(local_48,*local_48,6);
        memdescDescribe(local_48,1,lVar3,local_30);
        *(undefined8 **)(param_3[8] + 0x100) = local_48;
        *(undefined8 *)(param_3[8] + 0x108) = local_40;
        param_3[3] = (long)local_48;
        param_3[6] = 0;
        *(uint *)((long)param_3 + 0x24) = *(uint *)(param_3 + 4) & 0xffcfffe7;
        *(uint *)(param_3[8] + 0xd8) = *(uint *)(param_3 + 4) & 0xffcfffe7;
        return 0;
      }
    }
    if (local_38 != 0) {
      kbusUnmapFbApertureSingle_IMPL(lVar1,uVar4,param_3[2],local_38,local_30,0x20);
    }
    memdescDestroy(local_40);
    memdescDestroy(local_48);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/hopper/virt_mem_allocator_gh100.c",0xa3,
                 "dmaAllocBar1P2PMapping_GH100",4,"NVRM: Failed to create bar1p2p mapping\n");
    return iVar2;
  }
  return 0x1f;
}


// ===== 00397800 dmaFreeBar1P2PMapping_GH100 =====

void dmaFreeBar1P2PMapping_GH100(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if (((param_2 != 0) && (*(long **)(param_2 + 0x108) != (long *)0x0)) &&
     (*(long *)(param_2 + 0x100) != 0)) {
    lVar1 = **(long **)(param_2 + 0x108);
    uVar2 = *(undefined8 *)(&DAT_00001b90 + lVar1);
    uVar4 = memdescGetPhysAddr(*(long *)(param_2 + 0x100),0,0);
    uVar3 = *(undefined8 *)(*(long *)(param_2 + 0x100) + 0x30);
    kbusUnmapFbApertureSingle_IMPL(lVar1,uVar2,*(undefined8 *)(param_2 + 0x108),uVar4,uVar3,0x20);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/hopper/virt_mem_allocator_gh100.c",199,
                 "dmaFreeBar1P2PMapping_GH100",1,
                 "NVRM: bar1p2p surface UN-mapped at 0x%llx + 0x%llx\n",uVar4,uVar3);
    memdescDestroy(*(undefined8 *)(param_2 + 0x108));
    memdescDestroy(*(undefined8 *)(param_2 + 0x100));
    return;
  }
  return;
}


// ===== 003978f0 fbsrInit_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong fbsrInit_GM107(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  lVar4 = *(long *)(param_1 + 0x1b78);
  portMemSet(param_2 + 0xa8,0,0x28);
  uVar1 = *(uint *)(param_2 + 0x78);
  if (uVar1 < 2) {
    uVar5 = (**(code **)(lVar4 + 0x230))(param_1,lVar4);
    *(undefined8 *)(param_2 + 0xc0) = uVar5;
    if ((*(char *)(param_1 + 0x4a1) == '\0') &&
       (uVar3 = osReserveCpuAddressSpaceUpperBound(param_2 + 0xa8,uVar5), (int)uVar3 != 0)) {
      return uVar3;
    }
    uVar1 = *(uint *)(param_2 + 0x78);
    if ((uVar1 & 0xfffffffb) != 1) goto LAB_00397a45;
    uVar5 = 0x1000;
    if (uVar1 != 5) {
      uVar5 = 0x10000;
    }
LAB_00397943:
    uVar6 = 0;
    uVar1 = memdescCreate(param_2 + 0x90,param_1,uVar5,0,1,1,0,0);
    if (uVar1 == 0) {
      *(undefined4 *)(*(long *)(param_2 + 0x90) + 0x9c) = 0x9f;
      uVar7 = 0x39798e;
      uVar1 = memdescAlloc(*(undefined8 *)(param_2 + 0x90),uVar6);
      if (uVar1 == 0) {
        lVar4 = param_2 + 0xd8;
        if (*(int *)(param_2 + 0x78) == 6) {
          lVar4 = param_2 + 0xe0;
        }
        iVar2 = memdescMapOld(*(undefined8 *)(param_2 + 0x90),0,uVar5,1,3,lVar4,param_2 + 0xe8);
        if (iVar2 == 0) {
          if (*(int *)(*(long *)(param_2 + 0x90) + 0x60) != 0) {
            nvAssertFailedNoLog("!pFbsr->pSysMemDesc->PteAdjust",
                                "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0xe4,uVar7);
          }
          goto LAB_00397a4a;
        }
        nvAssertFailedNoLog(&DAT_00d45127,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0xdc,
                            uVar7);
        memdescFree(*(undefined8 *)(param_2 + 0x90));
        memdescDestroy(*(undefined8 *)(param_2 + 0x90));
        uVar3 = 0x1a;
        *(undefined8 *)(param_2 + 0x90) = 0;
      }
      else {
        nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",
                            0xcf);
        memdescDestroy(*(undefined8 *)(param_2 + 0x90));
        uVar3 = (ulong)uVar1;
        *(undefined8 *)(param_2 + 0x90) = 0;
      }
    }
    else {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",199);
      uVar3 = (ulong)uVar1;
    }
    if ((*(char *)(param_1 + 0x4a1) == '\0') && (*(uint *)(param_2 + 0x78) < 2)) {
      osReleaseCpuAddressSpaceUpperBound(*(undefined8 *)(param_2 + 0xa8));
    }
  }
  else {
    if ((uVar1 & 0xfffffffb) == 1) {
      uVar5 = 0x1000;
      goto LAB_00397943;
    }
LAB_00397a45:
    if (uVar1 == 6) {
      uVar5 = 0x10000;
      goto LAB_00397943;
    }
LAB_00397a4a:
    *(undefined1 *)(param_2 + 0x106) = 1;
    uVar3 = 0;
  }
  return uVar3;
}


// ===== 00397b80 fbsrDestroy_GM107 =====

void fbsrDestroy_GM107(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar1 = *(uint *)(param_2 + 0x78);
  if ((uVar1 & 0xfffffffb) == 1) {
    lVar4 = *(long *)(param_2 + 0x90);
    if (lVar4 == 0) goto LAB_00397be7;
    uVar2 = *(undefined8 *)(param_2 + 0xe8);
    uVar3 = *(undefined8 *)(param_2 + 0xd8);
  }
  else {
    if (uVar1 != 6) goto LAB_00397be7;
    lVar4 = *(long *)(param_2 + 0x90);
    if (lVar4 == 0) {
      return;
    }
    uVar2 = *(undefined8 *)(param_2 + 0xe8);
    uVar3 = *(undefined8 *)(param_2 + 0xe0);
  }
  memdescUnmapOld(lVar4,1,uVar3,uVar2);
  memdescFree(*(undefined8 *)(param_2 + 0x90));
  memdescDestroy(*(undefined8 *)(param_2 + 0x90));
  uVar1 = *(uint *)(param_2 + 0x78);
  *(undefined8 *)(param_2 + 0x90) = 0;
LAB_00397be7:
  if (1 < uVar1) {
    return;
  }
  osReleaseCpuAddressSpaceUpperBound(*(undefined8 *)(param_2 + 0xa8));
  return;
}


// ===== 00397c40 fbsrBegin_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int fbsrBegin_GM107(long param_1,long param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 extraout_RDX;
  char *pcVar6;
  undefined8 uVar7;
  undefined8 uStack_60;
  undefined8 local_40;
  undefined1 local_38;
  undefined8 local_30;
  
  lVar4 = *(long *)(param_1 + 0x1b78);
  *(int *)(param_2 + 0x88) = param_3;
  *(undefined1 *)(param_2 + 0x104) = 0;
  if ((param_3 == 0) || (param_3 == 3)) {
LAB_00397d16:
    if (param_3 - 2U < 2) {
      uVar1 = *(uint *)(param_2 + 0x78);
      if (uVar1 == 2) {
        iVar2 = memdescLock(*(undefined8 *)(param_2 + 0x90));
        if (iVar2 != 0) {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",
                              0x1ff);
        }
        goto LAB_00397d23;
      }
      if (uVar1 < 3) {
        if (uVar1 == 0) {
          uVar5 = *(ulong *)(param_2 + 0xf0);
          if (uVar5 <= *(ulong *)(param_2 + 0xc0)) {
            if (*(char *)(param_1 + 0x4a1) == '\0') {
              *(undefined8 *)(param_2 + 0xb8) = 0;
              iVar2 = osMapViewToSection(*(undefined8 *)(param_1 + 0x4e0),
                                         *(undefined8 *)(param_2 + 0xa8),param_2 + 0xb8,uVar5,0,0);
              if (iVar2 == 0) {
                lVar4 = *(long *)(param_2 + 0xb8);
                if (lVar4 == 0) {
                  nvAssertFailedNoLog("pFbsr->pagedBufferInfo.sysAddr",
                                      "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x23c);
                  lVar4 = *(long *)(param_2 + 0xb8);
                }
                iVar2 = osCreateMemFromOsDescriptorInternal
                                  (param_1,lVar4,0,*(undefined8 *)(param_2 + 0xf0),param_2 + 0x90,1,
                                   2);
                if ((iVar2 != 0) &&
                   (iVar3 = osUnmapViewFromSection
                                      (*(undefined8 *)(param_1 + 0x4e0),
                                       *(undefined8 *)(param_2 + 0xb8),0), iVar3 != 0)) {
                  nvAssertFailedNoLog("osUnmapViewFromSection(pGpu->pOsGpuInfo, NvP64_VALUE(pFbsr->pagedBufferInfo.sysAddr), bIommuEnabled) == NV_OK"
                                      ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x247);
                }
              }
            }
            else {
              uStack_60 = 0x398028;
              iVar2 = osSrPinSysmem(*(undefined8 *)(param_1 + 0x4e0),uVar5,param_2 + 0xb0);
              if (iVar2 == 0) {
                lVar4 = *(long *)(param_2 + 0xb0);
                if (lVar4 == 0) {
                  uStack_60 = 0x3984ae;
                  nvAssertFailedNoLog("pFbsr->pagedBufferInfo.pMdl",
                                      "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x225);
                  lVar4 = *(long *)(param_2 + 0xb0);
                }
                uVar7 = 2;
                iVar2 = osCreateMemFromOsDescriptorInternal
                                  (param_1,lVar4,0,*(undefined8 *)(param_2 + 0xf0),param_2 + 0x90,1)
                ;
                if (iVar2 != 0) {
                  osSrUnpinSysmem(*(undefined8 *)(param_1 + 0x4e0),uStack_60,extraout_RDX,uVar7);
                }
              }
            }
            goto LAB_00397d23;
          }
        }
        else if (*(ulong *)(param_2 + 0xf0) <= *(ulong *)(param_2 + 0xc0)) {
          if (*(char *)(param_1 + 0x4a1) == '\0') goto LAB_00397da9;
          goto LAB_00397db3;
        }
LAB_00397d82:
        iVar2 = 0xffff;
        goto LAB_00397d23;
      }
      if (uVar1 == 6) {
LAB_00397da9:
        if (*(long *)(param_2 + 0xa8) == 0) goto LAB_00397d82;
LAB_00397db3:
        *(undefined8 *)(param_2 + 200) = 0;
      }
    }
  }
  else {
    if ((*(char *)(param_1 + 0x909) != '\0') ||
       (iVar2 = param_3, *(char *)(param_1 + 0x908) != '\0')) {
      *(undefined8 *)(param_2 + 0x80) = 0;
      uStack_60 = 0x397cb0;
      iVar2 = memmgrInitCeUtils_IMPL(lVar4,0,*(undefined1 *)(lVar4 + 0xd34));
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,"memmgrInitCeUtils(pMemoryManager, NV_FALSE, bVirtualMode)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x12f);
        return iVar2;
      }
      iVar2 = *(int *)(param_2 + 0x88);
    }
    pcVar6 = "restoring";
    if (iVar2 == 1) {
      pcVar6 = "saving";
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x132,"fbsrBegin_GM107",1,
                 "NVRM: %s %lld bytes of data\n",pcVar6,*(undefined8 *)(param_2 + 0xf0));
    if (param_3 != 1) {
      param_3 = *(int *)(param_2 + 0x88);
      goto LAB_00397d16;
    }
    uVar1 = *(uint *)(param_2 + 0x78);
    if (uVar1 == 3) goto LAB_00397e70;
    if (3 < uVar1) {
      if (uVar1 == 5) {
LAB_003980df:
        if (*(long *)(param_2 + 0x90) != 0) {
LAB_00397ede:
          if (*(char *)(param_1 + 0x909) != '\0') goto LAB_00397eec;
          goto LAB_00397d20;
        }
      }
      else if (uVar1 == 6) {
        if (*(long *)(param_2 + 0x90) != 0) {
          iVar2 = osOpenTemporaryFile(param_2 + 0xa8,uStack_60);
          if (iVar2 != 0) goto LAB_00397d23;
          *(undefined8 *)(param_2 + 200) = 0;
          goto LAB_00397e70;
        }
      }
      else {
        if (uVar1 == 4) {
          lVar4 = *(long *)(param_2 + 0x108);
          uVar5 = *(ulong *)(param_2 + 0xf0);
          if (lVar4 != 0) goto LAB_00397ec2;
          if (uVar5 != 0) {
            uVar7 = 1;
            goto LAB_0039826e;
          }
          goto LAB_00397e70;
        }
        nvAssertFailedNoLog(&DAT_00d45127,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x1ef);
      }
      goto LAB_00397d82;
    }
    if (uVar1 == 1) {
      if ((*(ulong *)(param_2 + 0xc0) < *(ulong *)(param_2 + 0xf0)) ||
         ((*(char *)(param_1 + 0x4a1) == '\0' && (*(long *)(param_2 + 0xa8) == 0))))
      goto LAB_00397d82;
      *(undefined8 *)(param_2 + 200) = 0;
      goto LAB_003980df;
    }
    if (uVar1 == 2) {
      lVar4 = *(long *)(param_2 + 0x108);
      uVar5 = *(ulong *)(param_2 + 0xf0);
      if (lVar4 != 0) {
LAB_00397ec2:
        if (*(ulong *)(lVar4 + 0x30) < uVar5) {
          nvAssertFailedNoLog("pFbsr->pSysReservedMemDesc->Size >= pFbsr->length",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x155);
          memdescFree(*(undefined8 *)(param_2 + 0x108));
          memdescDestroy(*(undefined8 *)(param_2 + 0x108));
          *(undefined8 *)(param_2 + 0x108) = 0;
          goto LAB_00397d82;
        }
        *(long *)(param_2 + 0x90) = lVar4;
        *(undefined8 *)(param_2 + 0x108) = 0;
        goto LAB_00397ede;
      }
      if (uVar5 != 0) {
        uVar7 = 0;
LAB_0039826e:
        iVar2 = memdescCreate(param_2 + 0x90,param_1,uVar5,0,0,1,uVar7);
        if (iVar2 != 0) {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",
                              0x171);
          goto LAB_00397d23;
        }
        *(undefined4 *)(*(long *)(param_2 + 0x90) + 0x9c) = 0xa0;
        iVar2 = memdescAlloc(*(undefined8 *)(param_2 + 0x90));
        if (iVar2 != 0) {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",
                              0x179);
          memdescDestroy(*(undefined8 *)(param_2 + 0x90));
          *(undefined8 *)(param_2 + 0x90) = 0;
          goto LAB_00397d23;
        }
        if ((*(int *)(param_2 + 0x78) == 2) &&
           (iVar2 = memdescLock(*(undefined8 *)(param_2 + 0x90)), iVar2 != 0)) {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",
                              0x184);
          memdescFree(*(undefined8 *)(param_2 + 0x90));
          memdescDestroy(*(undefined8 *)(param_2 + 0x90));
          *(undefined8 *)(param_2 + 0x90) = 0;
          goto LAB_00397d23;
        }
      }
    }
    else {
      uVar5 = *(ulong *)(param_2 + 0xf0);
      if (*(ulong *)(param_2 + 0xc0) < uVar5) goto LAB_00397d82;
      if (*(char *)(param_1 + 0x4a1) == '\0') {
        *(undefined8 *)(param_2 + 0xb8) = 0;
        iVar2 = osMapViewToSection(*(undefined8 *)(param_1 + 0x4e0),*(undefined8 *)(param_2 + 0xa8),
                                   param_2 + 0xb8,uVar5,0,0);
        if (*(long *)(param_2 + 0xb8) == 0) {
          nvAssertFailedNoLog("pFbsr->pagedBufferInfo.sysAddr",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x1b5);
        }
        if (iVar2 != 0) goto LAB_00397d23;
        iVar2 = osCreateMemFromOsDescriptorInternal
                          (param_1,*(undefined8 *)(param_2 + 0xb8),0,*(undefined8 *)(param_2 + 0xf0)
                           ,param_2 + 0x90,1,2);
        if (iVar2 != 0) {
          iVar3 = osUnmapViewFromSection
                            (*(undefined8 *)(param_1 + 0x4e0),*(undefined8 *)(param_2 + 0xb8),0);
          if (iVar3 != 0) {
            nvAssertFailedNoLog("osUnmapViewFromSection(pGpu->pOsGpuInfo, NvP64_VALUE(pFbsr->pagedBufferInfo.sysAddr), bIommuEnabled) == NV_OK"
                                ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x1c3);
          }
          goto LAB_00397d23;
        }
      }
      else {
        iVar2 = osSrPinSysmem(*(undefined8 *)(param_1 + 0x4e0),uVar5,param_2 + 0xb0);
        if (iVar2 != 0) goto LAB_00397d23;
        lVar4 = *(long *)(param_2 + 0xb0);
        if (lVar4 == 0) {
          nvAssertFailedNoLog("pFbsr->pagedBufferInfo.pMdl",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x1a2);
          lVar4 = *(long *)(param_2 + 0xb0);
        }
        iVar2 = osCreateMemFromOsDescriptorInternal
                          (param_1,lVar4,0,*(undefined8 *)(param_2 + 0xf0),param_2 + 0x90,1);
        if (iVar2 != 0) {
          osSrUnpinSysmem(*(undefined8 *)(param_1 + 0x4e0));
          goto LAB_00397d23;
        }
      }
    }
LAB_00397e70:
    if ((*(char *)(param_1 + 0x909) != '\0') && (*(long *)(param_2 + 0x90) != 0)) {
LAB_00397eec:
      local_40 = CONCAT44(*(undefined4 *)(*(long *)(param_1 + 0x1b78) + 0xd40),
                          *(undefined4 *)(*(long *)(param_1 + 0x1b78) + 0xd10));
      local_38 = *(undefined1 *)(param_1 + 0x493);
      local_30 = memdescGetPhysAddr(*(undefined8 *)(*(long *)(param_1 + 0x1ba8) + 0xaa0),1,0);
      iVar3 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20800ac2,&local_40,0x18);
      iVar2 = 0;
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_INTERNAL_FBSR_INIT, &params, sizeof(params))"
                   ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x79);
        nvAssertOkFailedNoLog
                  (iVar3,"_fbsrInitGsp(pGpu, pFbsr)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x1f6);
        return iVar3;
      }
      goto LAB_00397d23;
    }
  }
LAB_00397d20:
  iVar2 = 0;
LAB_00397d23:
  *(undefined8 *)(param_2 + 0xf0) = 0;
  *(undefined8 *)(param_2 + 0xf8) = 0;
  *(undefined8 *)(param_2 + 0xa0) = *(undefined8 *)(param_2 + 0x98);
  return iVar2;
}


// ===== 00398540 fbsrEnd_GM107 =====

short fbsrEnd_GM107(long param_1,long param_2)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_2 + 0x88);
  cVar4 = *(char *)(param_1 + 0x4a1);
  if ((iVar5 == 0) || (iVar5 == 3)) {
    if ((*(char *)(param_2 + 0x104) == '\0') && (iVar5 != 3)) {
      return 0;
    }
LAB_003985ad:
    uVar1 = *(uint *)(param_2 + 0x78);
    if (uVar1 == 4) {
LAB_0039874c:
      memdescFree(*(undefined8 *)(param_2 + 0x90));
      memdescDestroy(*(undefined8 *)(param_2 + 0x90));
      cVar4 = *(char *)(param_2 + 0x104);
      *(undefined8 *)(param_2 + 0x90) = 0;
      goto LAB_0039866a;
    }
    if (uVar1 < 5) {
      if (uVar1 == 1) {
        osFlushCpuWriteCombineBuffer();
        if (*(long *)(param_2 + 200) != 0) goto LAB_0039879c;
      }
      else {
        if (uVar1 == 2) {
          memdescUnlock(*(undefined8 *)(param_2 + 0x90));
          goto LAB_0039874c;
        }
        if (uVar1 == 0) goto LAB_003985d9;
      }
    }
    else {
      if (uVar1 == 5) {
        osFlushCpuWriteCombineBuffer();
        puVar3 = *(undefined8 **)(param_2 + 0x98);
        while (puVar3 != (undefined8 *)0x0) {
          puVar2 = (undefined8 *)*puVar3;
          portMemFree(puVar3);
          puVar3 = puVar2;
        }
        *(undefined8 *)(param_2 + 0x98) = 0;
        cVar4 = *(char *)(param_2 + 0x104);
        goto LAB_0039866a;
      }
      if (uVar1 == 6) {
        osFlushCpuWriteCombineBuffer();
        osCloseFile(*(undefined8 *)(param_2 + 0xa8));
        cVar4 = *(char *)(param_2 + 0x104);
        goto LAB_0039866a;
      }
    }
  }
  else {
    if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) {
      if (*(long *)(*(long *)(param_1 + 0x1b78) + 0x4a0) != 0) {
        memmgrDestroyCeUtils_IMPL();
        iVar5 = *(int *)(param_2 + 0x88);
      }
      if (iVar5 != 2) goto LAB_00398696;
      goto LAB_003985ad;
    }
    if (iVar5 == 2) goto LAB_003985ad;
LAB_00398696:
    if ((*(char *)(param_2 + 0x104) != '\0') || (iVar5 == 3)) goto LAB_003985ad;
    if (iVar5 != 1) {
      return 0;
    }
    iVar5 = *(int *)(param_2 + 0x78);
    if (iVar5 == 1) {
      if (*(long *)(param_2 + 200) == 0) {
        return 0;
      }
LAB_0039879c:
      iVar5 = osUnmapViewFromSection
                        (*(undefined8 *)(param_1 + 0x4e0),*(undefined8 *)(param_2 + 0xb8),cVar4);
    }
    else {
      if (iVar5 == 2) {
        memdescUnlock(*(undefined8 *)(param_2 + 0x90));
        cVar4 = *(char *)(param_2 + 0x104);
        goto LAB_0039866a;
      }
      if (iVar5 != 0) {
        return 0;
      }
LAB_003985d9:
      memdescDestroy(*(undefined8 *)(param_2 + 0x90));
      *(undefined8 *)(param_2 + 0x90) = 0;
      if (cVar4 == '\0') {
        iVar5 = osUnmapViewFromSection
                          (*(undefined8 *)(param_1 + 0x4e0),*(undefined8 *)(param_2 + 0xb8),0);
      }
      else {
        iVar5 = osSrUnpinSysmem();
      }
    }
    if (iVar5 != 0) {
      *(undefined1 *)(param_2 + 0x104) = 1;
      return -1;
    }
  }
  cVar4 = *(char *)(param_2 + 0x104);
LAB_0039866a:
  return -(ushort)(cVar4 != '\0');
}


// ===== 003987e0 fbsrCopyMemoryMemDesc_GM107 =====

void fbsrCopyMemoryMemDesc_GM107(long param_1,long param_2,undefined8 param_3)

{
  long *plVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  long lVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  char *pcVar14;
  undefined *puVar15;
  ulong local_90;
  ulong local_88;
  long local_78;
  long local_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  uVar4 = *(undefined8 *)(param_1 + 0x1b78);
  lVar6 = memdescGetMemDescFromGpu(param_3,param_1);
  if (*(char *)(param_2 + 0x104) != '\0') {
    return;
  }
  *(long *)(param_2 + 0xf0) = *(long *)(param_2 + 0xf0) + *(long *)(lVar6 + 0x30);
  if (*(char *)(param_1 + 0x44d) != '\0') {
    if (*(long *)(lVar6 + 0x30) != 0) {
      nvAssertFailedNoLog("pVidMemDesc->Size == 0",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x309);
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x30a,
                 "fbsrCopyMemoryMemDesc_GM107",3,"NVRM: return early since FB is broken!\n");
    return;
  }
  iVar5 = *(int *)(param_2 + 0x78);
  if (*(int *)(param_2 + 0x88) == 0) {
    if (iVar5 == 3) {
      lVar12 = memdescGetStandbyBuffer(lVar6);
      if (lVar12 != 0) {
        return;
      }
      iVar5 = memdescCreate(&local_58,param_1,*(undefined8 *)(lVar6 + 0x30),0,0,1);
      if (iVar5 == 0) {
        *(undefined4 *)(local_58 + 0x9c) = 0xa1;
        iVar5 = memdescAlloc();
        if (iVar5 == 0) {
          memdescSetStandbyBuffer(lVar6,local_58);
        }
        else {
          memdescDestroy(local_58);
          *(undefined1 *)(param_2 + 0x104) = 1;
        }
      }
      else {
        *(undefined1 *)(param_2 + 0x104) = 1;
      }
    }
    else {
      if (iVar5 != 5) {
        return;
      }
      puVar7 = (undefined8 *)portMemAllocNonPaged((ulong)*(uint *)(lVar6 + 0x30) + 0xc);
      if (puVar7 == (undefined8 *)0x0) {
        nvAssertFailedNoLog(&DAT_00d45127,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x31b);
        *(undefined1 *)(param_2 + 0x104) = 1;
      }
      else {
        *puVar7 = 0;
        if (*(long *)(param_2 + 0x98) == 0) {
          *(undefined8 **)(param_2 + 0x98) = puVar7;
        }
        else {
          **(undefined8 **)(param_2 + 0xa0) = puVar7;
        }
        *(undefined8 **)(param_2 + 0xa0) = puVar7;
      }
    }
    return;
  }
  puVar15 = &DAT_00d45322;
  if (iVar5 == 4) {
    puVar15 = &DAT_00d4531e;
  }
  lVar8 = memdescGetPhysAddr(lVar6,1,0);
  lVar12 = *(long *)(lVar6 + 0x30);
  uVar9 = memdescGetPhysAddr(lVar6,1,0);
  pcVar14 = "restoring";
  if (*(int *)(param_2 + 0x88) == 1) {
    pcVar14 = "saving";
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x354,
               "fbsrCopyMemoryMemDesc_GM107",1,"NVRM: %s allocation %llx-%llx [%s]\n",pcVar14,uVar9,
               lVar12 + -1 + lVar8,puVar15);
  uVar3 = *(uint *)(param_2 + 0x78);
  if (uVar3 == 3) {
    local_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    local_78 = lVar6;
    local_58 = memdescGetStandbyBuffer(lVar6);
    if (*(int *)(param_2 + 0x88) == 2) {
      iVar5 = memmgrMemCopy_IMPL(uVar4,&local_78,&local_58,*(undefined4 *)(lVar6 + 0x30),0xc0);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "memmgrMemCopy(pMemoryManager, &vidSurface, &sysSurface, pVidMemDesc->Size, TRANSFER_FLAGS_PREFER_CE | TRANSFER_FLAGS_CE_PRI_DEFER_FLUSH)"
                   ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x37d);
      }
    }
    else {
      iVar5 = memmgrMemCopy_IMPL(uVar4,&local_58,&local_78,*(undefined4 *)(lVar6 + 0x30),0xc0);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "memmgrMemCopy(pMemoryManager, &sysSurface, &vidSurface, pVidMemDesc->Size, TRANSFER_FLAGS_PREFER_CE | TRANSFER_FLAGS_CE_PRI_DEFER_FLUSH)"
                   ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x382);
      }
    }
  }
  else if (uVar3 < 4) {
    if (uVar3 == 1) {
      uVar10 = *(ulong *)(lVar6 + 0x30);
      lVar12 = 0;
      if (uVar10 == 0) goto LAB_00398c54;
      uVar2 = *(undefined1 *)(param_1 + 0x4a1);
      local_88 = 0;
      do {
        uVar11 = *(ulong *)(param_2 + 200);
        if (uVar11 == 0) {
          lVar12 = local_88 + *(long *)(param_2 + 0xf8);
          if ((short)lVar12 != 0) {
            nvAssertFailedNoLog("((pFbsr->sysOffset + vidOffset)& 0xffff) == 0",
                                "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x396);
            lVar12 = local_88 + *(long *)(param_2 + 0xf8);
          }
          *(undefined8 *)(param_2 + 200) = 0x10000;
          *(undefined8 *)(param_2 + 0xb8) = 0;
          iVar5 = osMapViewToSection(*(undefined8 *)(param_1 + 0x4e0),
                                     *(undefined8 *)(param_2 + 0xa8),param_2 + 0xb8,0x10000,lVar12,
                                     uVar2);
          if (iVar5 != 0) {
            *(undefined1 *)(param_2 + 0x104) = 1;
            nvAssertFailedNoLog(&DAT_00d45127,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",
                                0x3a5);
            break;
          }
          uVar11 = *(ulong *)(param_2 + 200);
        }
        lVar12 = (*(long *)(param_2 + 0xb8) + 0x10000) - uVar11;
        if (uVar10 <= uVar11) {
          uVar11 = uVar10;
        }
        if (*(int *)(param_2 + 0x88) == 2) {
          if (uVar11 >> 2 == 0) {
            local_58 = *(long *)(param_2 + 0x90);
          }
          else {
            lVar8 = 0;
            do {
              *(undefined4 *)(*(long *)(param_2 + 0xd8) + lVar8) = *(undefined4 *)(lVar12 + lVar8);
              lVar8 = lVar8 + 4;
            } while ((uVar11 >> 2) * 4 != lVar8);
            local_58 = *(long *)(param_2 + 0x90);
            if (*(int *)(param_2 + 0x88) != 2) goto LAB_00398d7e;
          }
          local_70 = local_88;
          local_40 = 0;
          local_48 = 0;
          local_50 = 0;
          local_60 = 0;
          local_68 = 0;
          local_78 = lVar6;
          iVar5 = memmgrMemCopy_IMPL(uVar4,&local_78,&local_58,uVar11 & 0xffffffff,0x40);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "memmgrMemCopy(pMemoryManager, &vidSurface, &sysSurface, copySize, TRANSFER_FLAGS_PREFER_CE)"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x3c3);
          }
        }
        else {
          local_58 = *(long *)(param_2 + 0x90);
LAB_00398d7e:
          local_70 = local_88;
          local_40 = 0;
          local_48 = 0;
          local_50 = 0;
          local_60 = 0;
          local_68 = 0;
          local_78 = lVar6;
          iVar5 = memmgrMemCopy_IMPL(uVar4,&local_58,&local_78,uVar11 & 0xffffffff,0x40);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "memmgrMemCopy(pMemoryManager, &sysSurface, &vidSurface, copySize, TRANSFER_FLAGS_PREFER_CE)"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x3c7);
          }
        }
        if ((*(int *)(param_2 + 0x88) == 1) && (uVar11 >> 2 != 0)) {
          lVar8 = 0;
          do {
            *(undefined4 *)(lVar12 + lVar8) = *(undefined4 *)(*(long *)(param_2 + 0xd8) + lVar8);
            lVar8 = lVar8 + 4;
          } while (lVar8 != (uVar11 >> 2) * 4);
        }
        plVar1 = (long *)(param_2 + 200);
        *plVar1 = *plVar1 - uVar11;
        if ((*plVar1 == 0) &&
           (iVar5 = osUnmapViewFromSection
                              (*(undefined8 *)(param_1 + 0x4e0),*(undefined8 *)(param_2 + 0xb8),
                               uVar2), iVar5 != 0)) {
          *(undefined1 *)(param_2 + 0x104) = 1;
          nvAssertFailedNoLog(&DAT_00d45127,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x3de
                             );
          break;
        }
        local_88 = local_88 + uVar11;
        uVar10 = uVar10 - uVar11;
      } while (uVar10 != 0);
    }
    else {
LAB_00398bd9:
      local_58 = *(long *)(param_2 + 0x90);
      local_70 = 0;
      local_68 = 0;
      local_50 = *(undefined8 *)(param_2 + 0xf8);
      local_60 = 0;
      local_48 = 0;
      local_40 = 0;
      if (*(int *)(param_2 + 0x88) == 2) {
        local_78 = lVar6;
        iVar5 = memmgrMemCopy_IMPL(uVar4,&local_78,&local_58,*(undefined4 *)(lVar6 + 0x30),0xc0);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "memmgrMemCopy(pMemoryManager, &vidSurface, &sysSurface, pVidMemDesc->Size, TRANSFER_FLAGS_PREFER_CE | TRANSFER_FLAGS_CE_PRI_DEFER_FLUSH)"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x369);
        }
      }
      else {
        local_78 = lVar6;
        iVar5 = memmgrMemCopy_IMPL(uVar4,&local_58,&local_78,*(undefined4 *)(lVar6 + 0x30),0xc0);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "memmgrMemCopy(pMemoryManager, &sysSurface, &vidSurface, pVidMemDesc->Size, TRANSFER_FLAGS_PREFER_CE | TRANSFER_FLAGS_CE_PRI_DEFER_FLUSH)"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x36e);
        }
      }
    }
  }
  else if (uVar3 == 5) {
    lVar12 = *(long *)(param_2 + 0xa0);
    uVar10 = *(ulong *)(lVar6 + 0x30);
    if (lVar12 == 0) {
      nvAssertFailedNoLog("pNode","src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x450);
    }
    if ((*(byte *)(param_2 + 0xf8) & 3) != 0) {
      nvAssertFailedNoLog("(pFbsr->sysOffset & 3) == 0",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x451);
    }
    lVar8 = 0;
    for (; uVar10 != 0; uVar10 = uVar10 - uVar11) {
      uVar11 = 0x1000;
      if (uVar10 < 0x1001) {
        uVar11 = uVar10;
      }
      local_70 = lVar8;
      if (*(int *)(param_2 + 0x88) == 2) {
        if (uVar11 >> 2 == 0) {
          local_58 = *(long *)(param_2 + 0x90);
        }
        else {
          lVar13 = 0;
          do {
            *(undefined4 *)(*(long *)(param_2 + 0xd8) + lVar13) =
                 *(undefined4 *)(lVar12 + 8 + lVar13);
            lVar13 = lVar13 + 4;
          } while ((uVar11 >> 2) * 4 != lVar13);
          local_58 = *(long *)(param_2 + 0x90);
          if (*(int *)(param_2 + 0x88) != 2) goto LAB_00399116;
        }
        local_40 = 0;
        local_48 = 0;
        local_50 = 0;
        local_60 = 0;
        local_68 = 0;
        local_78 = lVar6;
        iVar5 = memmgrMemCopy_IMPL(uVar4,&local_78,&local_58,uVar11 & 0xffffffff,0x40);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "memmgrMemCopy(pMemoryManager, &vidSurface, &sysSurface, copySize, TRANSFER_FLAGS_PREFER_CE)"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x468);
        }
      }
      else {
        local_58 = *(long *)(param_2 + 0x90);
LAB_00399116:
        local_40 = 0;
        local_48 = 0;
        local_50 = 0;
        local_60 = 0;
        local_68 = 0;
        local_78 = lVar6;
        iVar5 = memmgrMemCopy_IMPL(uVar4,&local_58,&local_78,uVar11 & 0xffffffff,0x40);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "memmgrMemCopy(pMemoryManager, &sysSurface, &vidSurface, copySize, TRANSFER_FLAGS_PREFER_CE)"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x46c);
        }
      }
      if ((*(int *)(param_2 + 0x88) == 1) && (uVar11 >> 2 != 0)) {
        lVar13 = 0;
        do {
          *(undefined4 *)(lVar12 + 8 + lVar13) = *(undefined4 *)(*(long *)(param_2 + 0xd8) + lVar13)
          ;
          lVar13 = lVar13 + 4;
        } while ((uVar11 >> 2) * 4 != lVar13);
      }
      lVar8 = lVar8 + uVar11;
    }
    *(undefined8 *)(param_2 + 0xa0) = **(undefined8 **)(param_2 + 0xa0);
  }
  else if (uVar3 == 6) {
    local_88 = *(ulong *)(lVar6 + 0x30);
    iVar5 = threadStateResetTimeout(param_1);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"threadStateResetTimeout(pGpu)",
                 "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x3f8);
    }
    if (local_88 != 0) {
      local_90 = 0;
      uVar10 = *(ulong *)(param_2 + 200);
      lVar12 = 0;
      do {
        if (uVar10 == 0) {
          if ((short)((short)lVar12 + *(short *)(param_2 + 0xf8)) != 0) {
            nvAssertFailedNoLog("((pFbsr->sysOffset + vidOffset) & (CPU_MAX_PINNED_BUFFER_SIZE - 1)) == 0"
                                ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x401);
          }
          *(undefined8 *)(param_2 + 200) = 0x10000;
          uVar10 = 0x10000;
        }
        uVar11 = uVar10;
        if (local_88 <= uVar10) {
          uVar11 = local_88;
        }
        if (local_90 < 0x4000000) {
          local_90 = local_90 + uVar11;
          if (*(int *)(param_2 + 0x88) == 2) goto LAB_00398af5;
LAB_00398a00:
          local_58 = *(long *)(param_2 + 0x90);
LAB_00398a3e:
          local_40 = 0;
          local_48 = 0;
          local_50 = 0;
          local_60 = 0;
          local_68 = 0;
          local_78 = lVar6;
          local_70 = lVar12;
          iVar5 = memmgrMemCopy_IMPL(uVar4,&local_58,&local_78,uVar11 & 0xffffffff,0x40);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "memmgrMemCopy(pMemoryManager, &sysSurface, &vidSurface, copySize, TRANSFER_FLAGS_PREFER_CE)"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x42f);
          }
        }
        else {
          iVar5 = threadStateResetTimeout(param_1);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,"threadStateResetTimeout(pGpu)",
                       "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x409);
          }
          local_90 = uVar11;
          if (*(int *)(param_2 + 0x88) != 2) goto LAB_00398a00;
LAB_00398af5:
          iVar5 = osReadFromFile(*(undefined8 *)(param_2 + 0xa8),*(undefined8 *)(param_2 + 0xe0),
                                 uVar11,*(long *)(param_2 + 0xf8) + lVar12);
          if (iVar5 != 0) {
            *(undefined1 *)(param_2 + 0x104) = 1;
            nvAssertFailedNoLog(&DAT_00d45127,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",
                                0x41d);
            break;
          }
          local_58 = *(long *)(param_2 + 0x90);
          local_68 = 0;
          local_60 = 0;
          local_50 = 0;
          local_48 = 0;
          local_40 = 0;
          if (*(int *)(param_2 + 0x88) != 2) goto LAB_00398a3e;
          local_78 = lVar6;
          local_70 = lVar12;
          iVar5 = memmgrMemCopy_IMPL(uVar4,&local_78,&local_58,uVar11 & 0xffffffff,0x40);
          if (iVar5 != 0) {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "memmgrMemCopy(pMemoryManager, &vidSurface, &sysSurface, copySize, TRANSFER_FLAGS_PREFER_CE)"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x42b);
          }
        }
        if ((*(int *)(param_2 + 0x88) == 1) &&
           (iVar5 = osWriteToFile(*(undefined8 *)(param_2 + 0xa8),*(undefined8 *)(param_2 + 0xe0),
                                  uVar11,*(long *)(param_2 + 0xf8) + lVar12), iVar5 != 0)) {
          *(undefined1 *)(param_2 + 0x104) = 1;
          nvAssertFailedNoLog(&DAT_00d45127,"src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x43b
                             );
          break;
        }
        lVar12 = lVar12 + uVar11;
        uVar10 = *(long *)(param_2 + 200) - uVar11;
        local_88 = local_88 - uVar11;
        *(ulong *)(param_2 + 200) = uVar10;
      } while (local_88 != 0);
    }
    iVar5 = threadStateResetTimeout(param_1);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"threadStateResetTimeout(pGpu)",
                 "src/kernel/gpu/mem_mgr/arch/maxwell/fbsr_gm107.c",0x446);
      lVar12 = *(long *)(lVar6 + 0x30);
      goto LAB_00398c54;
    }
  }
  else if (uVar3 == 4) goto LAB_00398bd9;
  lVar12 = *(long *)(lVar6 + 0x30);
LAB_00398c54:
  *(long *)(param_2 + 0xf8) = *(long *)(param_2 + 0xf8) + lVar12;
  return;
}


// ===== 00399640 memmgrSetZbcReferenced =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrSetZbcReferenced(long param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  undefined4 uVar1;
  int iVar2;
  long local_20 [2];
  
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
    local_20[0] = (ulong)param_4 << 0x20;
    uVar1 = gpumgrGetSubDeviceInstanceFromGpu();
    local_20[0] = CONCAT44(local_20[0]._4_4_,uVar1);
    iVar2 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,param_2,param_3,0x80200a,local_20,8);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "pRmApi->Control( pRmApi, hClient, hDevice, NV0080_CTRL_CMD_INTERNAL_MEMSYS_SET_ZBC_REFERENCED, &params, sizeof(params))"
                 ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x11b);
      return;
    }
  }
  return;
}


// ===== 003996d0 memmgrChooseKindCompressC_GM107 =====

uint memmgrChooseKindCompressC_GM107(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_3;
  uVar2 = uVar1 & 7;
  uVar3 = uVar1 >> 4 & 0xf;
  if (uVar2 != 5) {
    if (uVar2 < 6) {
      if (uVar2 < 3) {
        return 0xfe;
      }
      if (uVar2 == 4) {
        if (uVar3 < 7) {
          if (4 < uVar3) {
            return 0xe5;
          }
          if (uVar3 == 0) {
            return 0xdb;
          }
          if (1 < uVar3 - 2) {
            return 0;
          }
        }
        else if (8 < uVar3) {
          return -(uint)(uVar3 - 9 < 2) & 0xe5;
        }
        return (uint)((param_3[1] & 3) == 1) * 3 + 0xe0;
      }
    }
    else if (uVar2 == 6) {
      if ((uVar1 & 0xc0) == 0) {
        if ((uVar1 >> 4 & 0xe) == 0) {
          return (-(uint)(uVar3 == 0) & 0xfffffffe) + 0xf7;
        }
      }
      else {
        if (8 < uVar3) {
          return -(uint)(uVar3 - 9 < 2) & 0xfb;
        }
        if (uVar3 < 7) {
          return -(uint)(uVar3 - 5 < 2) & 0xfb;
        }
      }
      return 0xf9;
    }
    return 0;
  }
  if (6 < uVar3) {
    if (8 < uVar3) {
      return -(uint)(uVar3 - 9 < 2) & 0xf3;
    }
LAB_0039978b:
    return (uint)((param_3[1] & 3) == 1) * 3 + 0xee;
  }
  if (uVar3 < 5) {
    uVar1 = 0xe9;
    if (uVar3 != 0) {
      if (1 < uVar3 - 2) {
        return 0;
      }
      goto LAB_0039978b;
    }
  }
  else {
    uVar1 = 0xf3;
  }
  return uVar1;
}


// ===== 00399820 memmgrAllocDetermineAlignment_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
memmgrAllocDetermineAlignment_GM107
          (long param_1,long param_2,long *param_3,ulong *param_4,long param_5,uint param_6,
          uint param_7,undefined4 param_8,ulong param_9)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  
  lVar6 = *(long *)(param_1 + 0x1b98);
  lVar3 = kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  uVar2 = dmaNvos32ToPageSizeAttr(param_7,param_8);
  if (uVar2 == 3) {
    if (param_9 < 0x1fffff) {
      param_9 = 0x1fffff;
    }
    if (*(char *)(lVar6 + 0x67d0) == '\0') {
      nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0xb4);
      return 0x1f;
    }
  }
  else if (uVar2 < 4) {
    if (uVar2 == 1) {
      if (param_9 < 0xfff) {
        param_9 = 0xfff;
      }
    }
    else {
      if (uVar2 != 2) goto LAB_00399922;
      lVar5 = (**(code **)(lVar6 + 0x198))(lVar6);
      if (param_9 <= lVar5 - 1U) {
        lVar6 = (**(code **)(lVar6 + 0x198))(lVar6);
        param_9 = lVar6 - 1;
      }
    }
  }
  else if (uVar2 == 5) {
    if (param_9 < 0x3fffffffff) {
      param_9 = 0x3fffffffff;
    }
    if (*(char *)(lVar6 + 0x67d2) == '\0') {
      nvAssertFailedNoLog("kgmmuIsPageSize256gbSupported(pKernelGmmu)",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0xbe);
      return 0x1f;
    }
  }
  else {
    if (uVar2 == 6) {
LAB_00399922:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0xc4,
                   "memmgrAllocDetermineAlignment_GM107",4,"NVRM: - invalid page size specified\n");
      return 0x1f;
    }
    if (uVar2 == 4) {
      if (param_9 < 0x1fffffff) {
        param_9 = 0x1fffffff;
      }
      if (*(char *)(lVar6 + 0x67d1) == '\0') {
        nvAssertFailedNoLog("kgmmuIsPageSize512mbSupported(pKernelGmmu)",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0xb9);
        return 0x1f;
      }
    }
  }
  if ((param_7 & 0x3000) != 0) {
    uVar2 = *(uint *)(lVar3 + 0x14);
    if ((param_7 & 0x1800000) == 0x800000) {
      if ((param_6 & 0x80000) == 0) {
        if (*(char *)(param_2 + 0x43e) == '\0') {
          if (param_9 < uVar2 - 1) {
            param_9 = (ulong)(uVar2 - 1);
          }
LAB_00399aaf:
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0xdd,
                       "memmgrAllocDetermineAlignment_GM107",1,
                       "NVRM: Compression requested on small page size mappings\n");
        }
        else {
          uVar7 = *param_3 + -1 + param_5 + (ulong)uVar2;
          *param_3 = uVar7 - uVar7 % (ulong)uVar2;
        }
      }
      else {
        if (param_9 < uVar2 - 1) {
          param_9 = (ulong)(uVar2 - 1);
        }
        if (*(char *)(param_2 + 0x43e) == '\0') goto LAB_00399aaf;
      }
    }
    else if (param_9 < uVar2 - 1) {
      param_9 = (ulong)(uVar2 - 1);
    }
  }
  uVar1 = *param_4;
  uVar7 = param_9 + 1;
  if (uVar1 == 0) {
LAB_0039996f:
    *param_4 = param_9;
    goto LAB_00399973;
  }
  if ((param_9 < uVar1) && (uVar1 % uVar7 == 0)) {
    uVar4 = uVar1 - 1;
    if (uVar1 <= uVar7) goto LAB_003999ad;
  }
  else {
    if ((uVar7 < uVar1) || (uVar7 % uVar1 != 0)) {
      if ((param_6 & 0x100) != 0) {
        *param_4 = 0;
        return 0x1f;
      }
      goto LAB_0039996f;
    }
LAB_003999ad:
    uVar4 = param_9;
  }
  *param_4 = uVar4;
LAB_00399973:
  param_9 = param_5 + *param_3 + param_9;
  *param_3 = param_9 - param_9 % uVar7;
  return 0;
}


// ===== 00399b50 _memmgrGetZbcSurfacesIndex =====

ulong _memmgrGetZbcSurfacesIndex(long param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  int local_5c;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  long local_40;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1bc0);
  *param_4 = 0;
  if ((*(long *)(param_1 + 0x1bc0) == 0) ||
     (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar2 == '\0')) {
    return 0;
  }
  uVar4 = serverGetClientUnderLock(g_resServ,param_2,&local_58);
  uVar5 = 0x13e;
  pcVar6 = "serverGetClientUnderLock(&g_resServ, hClient, &pClient)";
  if ((int)uVar4 == 0) {
    iVar3 = deviceGetByHandle_IMPL(local_58,param_3,&local_50,0x13e);
    if (iVar3 != 0) {
      uVar4 = subdeviceGetByHandle_IMPL(local_58,param_3,&local_48);
      if ((int)uVar4 != 0) {
        uVar5 = 0x146;
        pcVar6 = "subdeviceGetByHandle(pClient, hDevice, &pSubdevice)";
        goto LAB_00399cc0;
      }
      local_50 = *(undefined8 *)(*(long *)(local_48 + 0x158) + 0xe8);
    }
    uVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar1,local_50,&local_48);
    uVar5 = 0x14c;
    pcVar6 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
    if ((int)uVar4 == 0) {
      if (local_48 == 0) {
        nvAssertFailedNoLog("ref.pKernelMIGGpuInstance != NULL",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x14e,0x14c);
      }
      else {
        if (local_40 != 0) {
          if (*(int *)(local_40 + 0x84) == 0) {
            return 0;
          }
          uVar4 = kmigmgrGetLocalToGlobalEngineType_IMPL
                            (param_1,uVar1,local_48,local_40,1,&local_5c);
          if ((int)uVar4 == 0) {
            *param_4 = local_5c + -1;
            return uVar4;
          }
          uVar5 = 0x152;
          pcVar6 = 
          "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(0), &globalRmEngineType)"
          ;
          goto LAB_00399cc0;
        }
        nvAssertFailedNoLog("ref.pMIGComputeInstance != NULL",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x14f,0x14c);
      }
      return 0x40;
    }
  }
LAB_00399cc0:
  nvAssertOkFailedNoLog
            (uVar4 & 0xffffffff,pcVar6,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",uVar5);
  return uVar4 & 0xffffffff;
}


// ===== 00399da0 memmgrAllocHal_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrAllocHal_GM107(long param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint *puVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  uint uVar10;
  uint uVar11;
  undefined4 local_44;
  uint local_40;
  uint local_3c [3];
  
  uVar2 = *(undefined8 *)(param_1 + 0x1b70);
  local_40 = *(uint *)(param_3 + 0x44);
  uVar11 = *(uint *)(param_3 + 0x48);
  lVar6 = kmemsysGetStaticConfig_IMPL();
  puVar3 = *(uint **)(param_3 + 0x90);
  uVar10 = puVar3[1];
  uVar1 = *puVar3;
  iVar5 = memmgrAllocGetAddrSpace_IMPL(param_2,puVar3[2],local_40);
  if ((uVar1 & 0x400) != 0) {
    return 0x1f;
  }
  lVar9 = *(long *)(param_3 + 0x90);
  uVar1 = *(uint *)(lVar9 + 8);
  if ((uVar10 & 0xc) == 0) {
    uVar10 = uVar11 & 0xfffffff3;
    uVar11 = uVar10 | 4;
    if (iVar5 == 1) {
      uVar11 = uVar10 | 8;
    }
  }
  uVar7 = (ulong)local_40;
  if ((local_40 & 0x3000) != 0) {
    if (*(char *)(lVar6 + 3) == '\0') {
      cVar4 = memmgrComprSupported_IMPL(param_2,iVar5);
      uVar7 = (ulong)local_40;
      if (cVar4 == '\0') {
        if ((local_40 & 0x3000) == 0x1000) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x1aa,
                       "memmgrAllocHal_GM107",4,
                       "NVRM: Compression not supported for this configuration.\n");
          return 0x56;
        }
        uVar7 = (ulong)local_40 & 0xffffffffffffcfff;
        local_40 = (uint)uVar7;
      }
      lVar9 = *(long *)(param_3 + 0x90);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x1a3,
                   "memmgrAllocHal_GM107",1,"NVRM: compression disabled due to regkey\n");
      lVar9 = *(long *)(param_3 + 0x90);
      uVar7 = (ulong)local_40 & 0xffffffffffffcfff;
      local_40 = (uint)uVar7;
    }
  }
  iVar5 = (**(code **)(param_2 + 0x2a0))(param_1,param_2,lVar9,(uint)(uVar7 >> 0xc) & 3,&local_44);
  if (iVar5 != 0) {
    return 0x1f;
  }
  *(undefined4 *)(*(long *)(param_3 + 0x90) + 0xc) = local_44;
  cVar4 = (**(code **)(param_2 + 0x2a8))(param_2,5);
  if (cVar4 == '\0') {
    uVar8 = local_40 & 0xffffcfff;
    uVar10 = local_40 & 0x1800000;
    local_40 = uVar8;
    if (uVar10 != 0x800000) {
      *(undefined4 *)(param_3 + 4) = 0;
LAB_00399eab:
      lVar6 = *(long *)(param_3 + 0x90);
      goto LAB_00399eb2;
    }
  }
  else {
    uVar10 = local_40 & 0x3000;
    if ((local_40 & 0x1800000) != 0x800000) {
      *(undefined4 *)(param_3 + 4) = 0;
      if (uVar10 != 0) {
LAB_00399f7e:
        lVar6 = *(long *)(param_3 + 0x90);
        if (((uVar1 & 0x10000000) != 0) || ((*(byte *)(lVar6 + 10) & 8) != 0)) goto LAB_00399eb2;
        iVar5 = kmemsysAllocComprResources_KERNEL
                          (param_1,uVar2,param_3,*(undefined8 *)(param_3 + 0x78),1,&local_40,uVar11)
        ;
        if (iVar5 != 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x1ff,
                       "memmgrAllocHal_GM107",4,"NVRM: memsysAllocComprResources failed\n");
          return iVar5;
        }
      }
      goto LAB_00399eab;
    }
    if (uVar10 != 0) {
      if (*(char *)(param_2 + 0x43e) != '\0') {
        *(undefined4 *)(param_3 + 4) = 0;
        goto LAB_00399f7e;
      }
      if (uVar10 == 0x1000) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x1d3,
                     "memmgrAllocHal_GM107",4,
                     "NVRM: ERROR: Compression requested for small page allocation.\n");
        return 0x56;
      }
    }
  }
  *(undefined4 *)(param_3 + 4) = 0;
  lVar6 = *(long *)(param_3 + 0x90);
LAB_00399eb2:
  if ((*(byte *)(lVar6 + 6) & 2) == 0) {
    cVar4 = (**(code **)(param_2 + 0x2a8))(param_2,1,*(undefined4 *)(lVar6 + 0xc));
    if ((cVar4 == '\0') || ((*(byte *)(*(long *)(param_3 + 0x90) + 10) & 8) != 0)) {
      uVar11 = uVar11 & 0xfffffffc | 1;
    }
    else {
      uVar11 = uVar11 & 0xfffffffc | 2;
      if ((uVar1 & 0x10000000) == 0) {
        iVar5 = _memmgrGetZbcSurfacesIndex
                          (param_1,*(undefined4 *)(param_3 + 0x98),*(undefined4 *)(param_3 + 0x9c),
                           local_3c);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "_memmgrGetZbcSurfacesIndex(pGpu, pFbAllocInfo->hClient, pFbAllocInfo->hDevice, &zbcTableIndex)"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x218);
          return iVar5;
        }
        param_2 = param_2 + (ulong)local_3c[0] * 4;
        iVar5 = *(int *)(param_2 + 0xb6c) + 1;
        *(int *)(param_2 + 0xb6c) = iVar5;
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x21b,
                     "memmgrAllocHal_GM107",1,"NVRM: zbcSurfaces[%d] = 0x%x, hwResId = 0x%x\n",
                     (ulong)local_3c[0],iVar5,*(undefined4 *)(param_3 + 4));
        if (*(int *)(param_2 + 0xb6c) == 1) {
          memmgrSetZbcReferenced
                    (param_1,*(undefined4 *)(param_3 + 0x98),*(undefined4 *)(param_3 + 0x9c),1);
        }
      }
    }
  }
  else if ((uVar11 & 3) != 1) {
    nvAssertFailedNoLog("FLD_TEST_DRF(OS32, _ATTR2, _ZBC, _PREFER_NO_ZBC, retAttr2)",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x22a);
  }
  *(uint *)(param_3 + 0x48) = uVar11;
  *(undefined4 *)(param_3 + 0x4c) = local_44;
  *(uint *)(param_3 + 0x44) = local_40;
  return 0;
}


// ===== 0039a200 memmgrSetAllocParameters_GM107 =====

undefined8 memmgrSetAllocParameters_GM107(void)

{
  return 0;
}


// ===== 0039a210 memmgrFreeHal_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint memmgrFreeHal_GM107(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  uint local_48;
  uint local_2c [3];
  
  local_48 = *(uint *)(*(long *)(param_3 + 0x90) + 8);
  if (((local_48 & 0x10000000) != 0) || ((*(byte *)(*(long *)(param_3 + 0x90) + 6) & 2) != 0)) {
    return 0;
  }
  local_48 = local_48 & 0x10000000;
  cVar1 = (**(code **)(param_2 + 0x2a8))(param_2,1,*(undefined4 *)(param_3 + 0x4c));
  if (cVar1 == '\0') {
    return local_48;
  }
  uVar2 = _memmgrGetZbcSurfacesIndex
                    (param_1,*(undefined4 *)(param_3 + 0x98),*(undefined4 *)(param_3 + 0x9c),
                     local_2c);
  if (uVar2 != 0) {
    nvAssertOkFailedNoLog
              (uVar2,
               "_memmgrGetZbcSurfacesIndex(pGpu, pFbAllocInfo->hClient, pFbAllocInfo->hDevice, &zbcTableIndex)"
               ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x25b);
    return uVar2;
  }
  uVar4 = (ulong)local_2c[0];
  iVar3 = *(int *)(param_2 + 0xc + (uVar4 + 0x2d8) * 4);
  if (iVar3 == 0) {
    nvAssertFailedNoLog("pMemoryManager->zbcSurfaces[zbcTableIndex] != 0",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x25d);
    iVar3 = *(int *)(param_2 + 0xc + (uVar4 + 0x2d8) * 4);
    if (iVar3 == 0) goto LAB_0039a2e9;
  }
  *(int *)(param_2 + 0xb6c + uVar4 * 4) = iVar3 + -1;
  if (iVar3 + -1 == 0) {
    memmgrSetZbcReferenced
              (param_1,*(undefined4 *)(param_3 + 0x98),*(undefined4 *)(param_3 + 0x9c),0);
  }
LAB_0039a2e9:
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x266,"memmgrFreeHal_GM107",1,
               "NVRM: [1] hwResId = 0x%x, offset = 0x%llx, size = 0x%llx\n",
               *(undefined4 *)(param_3 + 4),*(undefined8 *)(param_3 + 0x38),
               *(undefined8 *)(param_3 + 0x18));
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x26b,"memmgrFreeHal_GM107",1,
               "NVRM: [2] zbcSurfaces[%d] = 0x%x\n",local_2c[0],
               *(undefined4 *)(param_2 + 0xb6c + uVar4 * 4));
  return 0;
}


// ===== 0039a416 memmgrGetBAR1InfoForDevice_GM107.cold =====

void memmgrGetBAR1InfoForDevice_GM107_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0039a430 memmgrGetBAR1InfoForDevice_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrGetBAR1InfoForDevice_GM107(long param_1,undefined8 param_2,long param_3,int *param_4)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  ulong *puVar11;
  uint local_46c;
  ulong local_468;
  ulong local_460;
  long local_458;
  ulong local_450;
  ulong local_448;
  undefined8 local_440;
  int local_438;
  undefined4 local_434;
  int local_430;
  undefined4 local_42c;
  int local_428;
  undefined4 local_424;
  int local_420;
  
  lVar8 = *(long *)(&DAT_00001b90 + param_1);
  local_450 = 1;
  local_448 = 0;
  if (param_3 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = **(long **)(*(long *)(param_3 + 0x110) + 0x48);
  if ((*(char *)(param_1 + 0x908) == '\0') ||
     ((*(char *)(param_1 + 0x4913) != '\0' && (*(char *)(param_1 + 0x491e) == '\0')))) {
    if ((lVar8 == 0) || (*(char *)(lVar8 + 0xad45) == '\0')) {
      lVar2 = *(long *)(param_1 + 0x1bc0);
      plVar9 = (long *)(**(code **)(lVar8 + 0x4e8))(param_1,lVar8);
      if (plVar9 == (long *)0x0) {
        iVar6 = 0x40;
        nvAssertFailedNoLog("pBar1VAS != NULL","src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c"
                            ,0x2ab);
      }
      else {
        lVar10 = (**(code **)(*plVar9 + 0x90))(plVar9);
        iVar6 = kbusGetBar1VARangeForDevice_IMPL(param_1,lVar8,param_3,&local_450);
        if (iVar6 == 0) {
          iVar7 = (int)((local_448 + 1) - local_450 >> 10);
          if (local_448 < local_450) {
            iVar7 = 0;
          }
          *param_4 = iVar7;
          iVar7 = (**(code **)(*plVar9 + 0xa0))(plVar9);
          param_4[1] = 0;
          param_4[2] = iVar7;
          param_4[3] = 0;
          if (lVar10 != 0) {
            puVar11 = &local_460;
            (**(code **)(lVar10 + 0x20))(lVar10,local_450,local_448,0,&local_468,0);
            param_4[3] = (int)(local_468 >> 10);
            cVar4 = kbusIsStaticBar1Enabled_IMPL(param_1,lVar8);
            if ((cVar4 == '\0') ||
               (((lVar2 != 0 &&
                 (cVar4 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(param_1,lVar2,puVar11,0x39a6b9),
                 cVar4 != '\0')) &&
                (cVar4 = kmigmgrIsDeviceUsingDeviceProfiling_IMPL(param_1,lVar2,param_3),
                cVar4 == '\0')))) {
              param_4[1] = (int)(local_460 >> 10);
            }
            else {
              iVar6 = vgpuGetCallingContextGfid(param_1);
              if (iVar6 == 0) {
                memset(&local_440,0,0x404);
                local_434 = 0x16;
                local_440 = 0x900000002;
                uVar5 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
                iVar6 = subdeviceGetByInstance_IMPL
                                  (lVar1,*(undefined4 *)
                                          (*(long *)(*(long *)(param_3 + 0x110) + 0x48) + 0x10),
                                   uVar5,&local_458);
                if (iVar6 == 0) {
                  iVar6 = subdeviceCtrlCmdFbGetInfoV2_IMPL(local_458,&local_440);
                  if (iVar6 == 0) {
                    param_4[1] = (local_430 - local_438) +
                                 (int)(local_460 +
                                       *(long *)(lVar8 + 0x708 + (ulong)local_46c * 0x100) >> 10);
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar6,"subdeviceCtrlCmdFbGetInfoV2(pSubdevice, &fbInfoParams)",
                               "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x2e3);
                  }
                }
                else {
                  nvAssertOkFailedNoLog
                            (iVar6,
                             "subdeviceGetByInstance(pClient, RES_GET_HANDLE(pDevice), gpumgrGetSubDeviceInstanceFromGpu(pGpu), &pSubdevice)"
                             ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x2dc);
                }
              }
              else {
                nvAssertOkFailedNoLog
                          (iVar6,"vgpuGetCallingContextGfid(pGpu, &gfid)",
                           "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x2d4);
              }
            }
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar6,"kbusGetBar1VARangeForDevice(pGpu, pKernelBus, pDevice, &bar1VARange)",
                     "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x2ae);
        }
      }
    }
    else {
      param_4[0] = 0;
      param_4[1] = 0;
      iVar6 = 0;
      param_4[2] = 0;
      param_4[3] = 0;
    }
  }
  else {
    memset(&local_440,0,0x404);
    uVar5 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    iVar6 = subdeviceGetByInstance_IMPL
                      (lVar1,*(undefined4 *)(*(long *)(*(long *)(param_3 + 0x110) + 0x48) + 0x10),
                       uVar5,&local_458);
    if (iVar6 == 0) {
      local_434 = 0x1d;
      local_42c = 0x1f;
      local_424 = 6;
      local_440 = 0x500000004;
      lVar8 = gpuGetRpc(param_1);
      if (lVar8 == 0) {
        iVar6 = 0x1a;
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",
                            0x29b);
      }
      else {
        if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
          if (local_458 == 0) {
memmgrGetBAR1InfoForDevice_GM107_cold:
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          iVar6 = rpcDmaControl_wrapper
                            (param_1,lVar8,*(undefined4 *)(lVar1 + 0x48),
                             *(undefined4 *)(*(long *)(*(long *)(local_458 + 0x140) + 0x48) + 0x10),
                             0x20801303,&local_440,0x404);
        }
        else {
          if (local_458 == 0) goto memmgrGetBAR1InfoForDevice_GM107_cold;
          iVar6 = (**(code **)(param_1 + 0x3b90))
                            (param_1 + 0x3b58,*(undefined4 *)(lVar1 + 0x48),
                             *(undefined4 *)(*(long *)(*(long *)(local_458 + 0x140) + 0x48) + 0x10),
                             0x20801303,&local_440,0x404);
        }
        if (iVar6 == 0) {
          *param_4 = local_438;
          param_4[1] = local_430;
          param_4[3] = local_428;
          param_4[2] = local_420;
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar6,
                 "subdeviceGetByInstance(pClient, RES_GET_HANDLE(pDevice), gpumgrGetSubDeviceInstanceFromGpu(pGpu), &pSubdevice)"
                 ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x28e);
    }
  }
  return iVar6;
}


// ===== 0039a9c0 memmgrGetReservedHeapSizeMb_GM107 =====

undefined1  [16] memmgrGetReservedHeapSizeMb_GM107(undefined8 param_1,long param_2,ulong param_3)

{
  long lVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  undefined1 auVar7 [16];
  ulong uStack_30;
  
  if (*(int *)(param_2 + 0x858) == 0) {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_3;
    return auVar2 << 0x40;
  }
  uVar6 = 0;
  plVar5 = (long *)(param_2 + 0x870);
  uVar3 = 0;
  do {
    while( true ) {
      lVar1 = *plVar5;
      uVar6 = uVar6 + lVar1;
      if (lVar1 == 0) break;
      uVar4 = uVar3 + 1;
      plVar5 = plVar5 + 5;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x309,
                   "memmgrGetReservedHeapSizeMb_GM107",1,"NVRM: FB region #%d:rsvdSize=%d\n",uVar3,
                   lVar1);
      param_3 = uStack_30;
      uVar3 = uVar4;
      if (*(uint *)(param_2 + 0x858) <= uVar4) goto LAB_0039aa5c;
    }
    uVar3 = uVar3 + 1;
    plVar5 = plVar5 + 5;
  } while (uVar3 < *(uint *)(param_2 + 0x858));
LAB_0039aa5c:
  auVar7._0_8_ = uVar6 >> 0x14;
  auVar7._8_8_ = param_3;
  return auVar7;
}


// ===== 0039aa80 memmgrCheckReservedMemorySize_GK104 =====

undefined8 memmgrCheckReservedMemorySize_GK104(undefined8 param_1,long param_2)

{
  if (*(ulong *)(param_2 + 0x498) < 0x100000) {
    return 0;
  }
  nvAssertFailedNoLog("pMemoryManager->rsvdMemorySize < DRF_SIZE(NV_PRAMIN)",
                      "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x39b);
  return 0x1a;
}


// ===== 0039aac0 memmgrInitReservedMemory_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrInitReservedMemory_GM107(long param_1,long param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  ulong uVar9;
  undefined8 extraout_RDX;
  long lVar10;
  long local_60;
  long local_58;
  long local_50;
  undefined1 local_48;
  undefined4 local_44;
  undefined2 local_40;
  char local_3e;
  undefined2 local_3d;
  
  cVar2 = gpuIsCCFeatureEnabled_IMPL();
  *(ulong *)(param_2 + 0x498) = *(long *)(param_2 + 0x498) + 0xffffU & 0xffffffffffff0000;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x3c8,
               "memmgrInitReservedMemory_GM107",1,"NVRM: Final reserved memory size = 0x%llx\n");
  if ((*(char *)(param_1 + 0x908) == '\0') &&
     (iVar4 = (**(code **)(param_2 + 0x340))(param_1,param_2), iVar4 != 0)) {
    nvAssertFailedNoLog("RMCFG_FEATURE_PLATFORM_GSP || memmgrCheckReservedMemorySize_HAL(pGpu, pMemoryManager) == NV_OK"
                        ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x3d0);
    return 0x1a;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x3d4,
               "memmgrInitReservedMemory_GM107",1,"NVRM: RESERVED Memory size: 0x%llx\n",
               *(undefined8 *)(param_2 + 0x498));
  if (*(uint *)(param_2 + 0x858) == 0) {
    uVar6 = 0;
    bVar1 = false;
  }
  else {
    pcVar8 = (char *)(param_2 + 0x878);
    uVar6 = 0;
    bVar1 = false;
    uVar9 = 0;
    do {
      if (*pcVar8 == '\0') {
        if (cVar2 == '\0') {
          if (pcVar8[10] == '\0') {
            bVar1 = true;
            uVar6 = uVar9;
          }
        }
        else if (pcVar8[10] != '\0') {
          bVar1 = true;
          uVar6 = uVar9;
        }
      }
      uVar3 = (int)uVar9 + 1;
      uVar9 = (ulong)uVar3;
      pcVar8 = pcVar8 + 0x28;
    } while (*(uint *)(param_2 + 0x858) != uVar3);
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
    if ((*(char *)(param_1 + 0x4921) == '\0') && (*(char *)(param_2 + 0xd1c) != '\0')) {
      if (bVar1) {
        uVar6 = *(long *)(param_2 + 0x860 + uVar6 * 0x28) + 0xfffU & 0xfffffffffffff000;
      }
      else {
        uVar6 = 0;
      }
LAB_0039ad0e:
      *(ulong *)(param_2 + 0x490) = uVar6;
      *(ulong *)(param_2 + 0x498) = *(long *)(param_2 + 0x498) + 0xfffU & 0xfffffffffffff000;
      goto LAB_0039ac5d;
    }
  }
  else if (*(char *)(param_1 + 0x4921) == '\0') {
    bVar1 = false;
    if (*(char *)(param_2 + 0xd1c) != '\0') {
      bVar1 = false;
      uVar6 = 0;
      goto LAB_0039ad0e;
    }
  }
  else {
    bVar1 = false;
  }
  lVar5 = kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  if (*(char *)(param_1 + 0x4921) == '\0') {
    uVar9 = *(long *)(param_2 + 0x838) * 0x100000;
    if (*(char *)(param_1 + 0x4913) != '\0') {
      lVar5 = (**(code **)(param_2 + 0x220))(param_1,param_2);
      uVar9 = uVar9 - lVar5;
    }
    if ((bVar1) && (uVar6 = *(long *)(param_2 + 0x868 + uVar6 * 0x28) + 1, uVar6 < uVar9)) {
      uVar9 = uVar6;
    }
  }
  else {
    uVar9 = *(ulong *)(lVar5 + 8);
  }
  uVar6 = uVar9 - *(long *)(param_2 + 0x498) & 0xfffffffffffff000;
  uVar9 = uVar9 - uVar6;
  *(ulong *)(param_2 + 0x490) = uVar6;
  *(ulong *)(param_2 + 0x498) = uVar9;
  if (uVar9 >> 0x20 != 0) {
    nvAssertFailedNoLog("0 == NvU64_HI32(rsvdTopOfMem - pMemoryManager->rsvdMemoryBase)",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x42a);
  }
LAB_0039ac5d:
  if (*(char *)(param_1 + 0x44d) == '\0') {
    uVar6 = *(ulong *)(param_2 + 0x828);
    uVar9 = *(ulong *)(param_2 + 0x498);
    if (uVar6 < uVar9) {
      nvAssertFailedNoLog("pMemoryManager->Ram.fbUsableMemSize >= pMemoryManager->rsvdMemorySize",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x43a);
      uVar6 = *(ulong *)(param_2 + 0x828);
      uVar9 = *(ulong *)(param_2 + 0x498);
    }
    *(ulong *)(param_2 + 0x828) = uVar6 - (uVar9 + 0xfff & 0xfffffffffffff000);
  }
  if ((bVar1) && (*(long *)(param_2 + 0x498) != 0)) {
    portMemSet(&local_60,0,0x28);
    local_60 = *(long *)(param_2 + 0x490);
    local_50 = *(long *)(param_2 + 0x498);
    local_40 = 0;
    local_48 = 1;
    local_58 = local_60 + -1 + local_50;
    local_44 = 0;
    local_3d = 0x101;
    local_3e = cVar2;
    memmgrInsertFbRegion_IMPL(param_1,param_2,&local_60);
  }
  if (*(char *)(param_1 + 0x909) == '\0') {
    lVar5 = *(long *)(&DAT_00001b90 + param_1);
    kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
    cVar2 = *(char *)(lVar5 + 0xad44);
    uVar6 = (ulong)*(uint *)(lVar5 + 0xad40);
    iVar4 = memdescCreate(lVar5 + 0x648,param_1,0x1000,0x1000,1,*(undefined4 *)(lVar5 + 0xad3c));
    if (iVar4 == 0) {
      iVar4 = memdescGetAddressSpace
                        (*(undefined8 *)(lVar5 + 0x648),(ulong)(cVar2 != '\0') << 7,extraout_RDX,
                         uVar6);
      if ((iVar4 == 1) && (*(char *)(param_1 + 0x4a25) != '\0')) {
        memdescSetGpuCacheAttrib(*(undefined8 *)(lVar5 + 0x648),0);
      }
      iVar4 = memdescCreate(lVar5 + 0x4678,param_1,0x1000,0x1000,1,*(undefined4 *)(lVar5 + 0xad3c),
                            *(undefined4 *)(lVar5 + 0xad40));
      if (iVar4 == 0) {
        iVar4 = memdescGetAddressSpace(*(undefined8 *)(lVar5 + 0x4678));
        if ((iVar4 == 1) && (*(char *)(param_1 + 0x4a25) != '\0')) {
          memdescSetGpuCacheAttrib(*(undefined8 *)(lVar5 + 0x4678),0);
        }
        if (*(int *)(lVar5 + 0xad3c) != 1) {
          *(long *)(lVar5 + 0x640) = *(long *)(param_2 + 0x490) + *(long *)(lVar5 + 0x640);
          memdescDescribe();
          lVar10 = *(long *)(param_2 + 0x490) + *(long *)(lVar5 + 0x4670);
          *(long *)(lVar5 + 0x4670) = lVar10;
          memdescDescribe(*(undefined8 *)(lVar5 + 0x4678),*(undefined4 *)(lVar5 + 0xad3c),lVar10,
                          0x1000);
          return 0;
        }
        *(undefined4 *)(*(long *)(lVar5 + 0x648) + 0x9c) = 0xa8;
        iVar4 = memdescAlloc(*(undefined8 *)(lVar5 + 0x648));
        if (iVar4 == 0) {
          uVar7 = memdescGetPhysAddr(*(undefined8 *)(lVar5 + 0x648),1,0);
          *(undefined8 *)(lVar5 + 0x640) = uVar7;
          *(undefined4 *)(*(long *)(lVar5 + 0x4678) + 0x9c) = 0xa9;
          iVar4 = memdescAlloc(*(undefined8 *)(lVar5 + 0x4678));
          if (iVar4 == 0) {
            uVar7 = memdescGetPhysAddr(*(undefined8 *)(lVar5 + 0x4678),1,0);
            *(undefined8 *)(lVar5 + 0x4670) = uVar7;
            return 0;
          }
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",899,
                       "memmgrStateInitAdjustReservedMemory",4,
                       "NVRM: couldn\'t allocate BAR2 instblk in sysmem\n");
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x37a,
                       "memmgrStateInitAdjustReservedMemory",4,
                       "NVRM: couldn\'t allocate BAR1 instblk in sysmem\n");
        }
      }
    }
    nvAssertOkFailedNoLog
              (iVar4,"memmgrStateInitAdjustReservedMemory(pGpu, pMemoryManager)",
               "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x45e);
    return iVar4;
  }
  return 0;
}


// ===== 0039b130 memmgrComparePhysicalAddresses_GM107 =====

bool memmgrComparePhysicalAddresses_GM107
               (undefined8 param_1,undefined8 param_2,int param_3,long param_4,int param_5,
               long param_6)

{
  if (param_3 == 2) {
    param_3 = 3;
  }
  if (param_5 == 2) {
    param_5 = 3;
  }
  return param_3 == param_5 && param_4 == param_6;
}


// ===== 0039b160 memmgrGetPteKindBl_GM107 =====

undefined8 memmgrGetPteKindBl_GM107(void)

{
  return 0xfe;
}


// ===== 0039b170 memmgrGetPteKindPitch_GM107 =====

undefined8 memmgrGetPteKindPitch_GM107(void)

{
  return 0;
}


// ===== 0039b180 memmgrSetMemDescPageSize_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
memmgrSetMemDescPageSize_GM107
          (long param_1,long param_2,undefined8 *param_3,undefined8 param_4,uint param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  
  lVar7 = *(long *)(param_1 + 0x1b98);
  iVar2 = memdescGetAddressSpace(param_3);
  if (iVar2 == 4) {
    return 0;
  }
  if (iVar2 == 1) {
    uVar4 = osGetPageSize();
    uVar5 = memdescGetPte(param_3,param_4,0);
    if (param_5 == 4) {
      if (*(char *)(lVar7 + 0x67d1) == '\0') {
        nvAssertFailedNoLog("kgmmuIsPageSize512mbSupported(pKernelGmmu)",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x524);
        return 0x56;
      }
      if ((uVar5 & 0x1fffffff) != 0) {
        nvAssertFailedNoLog("0 == (physAddr & (RM_PAGE_SIZE_512M - 1))",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x527);
        return 0x37;
      }
      uVar4 = memdescGetPageSize(param_3,param_4);
joined_r0x0039b535:
      uVar9 = 0x20000000;
      if (uVar4 != 0) {
LAB_0039b226:
        if (uVar9 != uVar4) {
          nvAssertFailedNoLog("oldPageSize == newPageSize",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x57c);
          return 0x1f;
        }
        return 0;
      }
      uVar9 = 0x20000000;
      goto LAB_0039b206;
    }
    if (4 < param_5) {
      if (param_5 == 5) {
        if (*(char *)(lVar7 + 0x67d2) == '\0') {
          nvAssertFailedNoLog("kgmmuIsPageSize256gbSupported(pKernelGmmu)",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x52b);
          return 0x56;
        }
        if ((uVar5 & 0x3fffffffff) != 0) {
          nvAssertFailedNoLog("0 == (physAddr & (RM_PAGE_SIZE_256G - 1))",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x52e);
          return 0x37;
        }
        uVar4 = memdescGetPageSize(param_3,param_4);
joined_r0x0039b419:
        uVar9 = 0x4000000000;
        if (uVar4 != 0) goto LAB_0039b226;
        uVar9 = 0x4000000000;
        goto LAB_0039b206;
      }
      if (param_5 == 6) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x532,
                     "memmgrSetMemDescPageSize_GM107",4,"NVRM: invalid page size attr\n");
        return 0x1f;
      }
LAB_0039b1f0:
      uVar4 = memdescGetPageSize(param_3,param_4);
      if (uVar4 != 0) goto LAB_0039b220;
      goto LAB_0039b200;
    }
    if (param_5 == 2) {
      uVar9 = (**(code **)(lVar7 + 0x1d0))(lVar7);
LAB_0039b497:
      uVar4 = memdescGetPageSize(param_3,param_4);
      if (uVar4 != 0) goto LAB_0039b226;
      goto LAB_0039b206;
    }
    if (param_5 == 3) {
      if (*(char *)(lVar7 + 0x67d0) == '\0') {
        nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x51d);
        return 0x56;
      }
      if ((uVar5 & 0x1fffff) != 0) {
        nvAssertFailedNoLog("0 == (physAddr & (RM_PAGE_SIZE_HUGE - 1))",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x520);
        return 0x37;
      }
LAB_0039b449:
      uVar9 = 0x200000;
      uVar4 = memdescGetPageSize(param_3,param_4);
      if (uVar4 != 0) goto LAB_0039b226;
LAB_0039b390:
      uVar9 = 0x200000;
      goto LAB_0039b206;
    }
    if (param_5 != 0) goto LAB_0039b1f0;
    uVar6 = (**(code **)(lVar7 + 0x1d0))(lVar7);
    cVar1 = memdescGetContiguity(param_3,1);
    if ((cVar1 == '\0') ||
       ((((uVar5 & 0x1fffff) != 0 || (uVar9 = 0x200000, (*(uint *)(param_3 + 6) & 0x1fffff) != 0))
        && (((uVar5 & uVar6 - 1) != 0 || (uVar9 = uVar6 & 0xffffffff, (param_3[6] & uVar6 - 1) != 0)
            ))))) {
      uVar9 = uVar4 & 0xffffffff;
    }
LAB_0039b2f3:
    lVar7 = memdescGetPageSize(param_3,param_4);
    if (lVar7 != 0) {
      return 0;
    }
  }
  else {
    if (iVar2 == 2) {
      uVar4 = memdescGetPte(param_3,param_4,0);
      if (param_5 == 4) {
        if (*(char *)(lVar7 + 0x67d1) == '\0') {
          nvAssertFailedNoLog("kgmmuIsPageSize512mbSupported(pKernelGmmu)",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x560);
          return 0x56;
        }
        if ((uVar4 & 0x1fffffff) != 0) {
          nvAssertFailedNoLog("0 == (physAddr & (RM_PAGE_SIZE_512M - 1))",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x563);
          return 0x37;
        }
        uVar4 = memdescGetPageSize(param_3,param_4);
        goto joined_r0x0039b535;
      }
      if (4 < param_5) {
        if (param_5 == 5) {
          if (*(char *)(lVar7 + 0x67d2) == '\0') {
            nvAssertFailedNoLog("kgmmuIsPageSize256gbSupported(pKernelGmmu)",
                                "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x567);
            return 0x56;
          }
          if ((uVar4 & 0x3fffffffff) != 0) {
            nvAssertFailedNoLog("0 == (physAddr & (RM_PAGE_SIZE_256G - 1))",
                                "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x56a);
            return 0x37;
          }
          uVar4 = memdescGetPageSize(param_3,param_4);
          goto joined_r0x0039b419;
        }
        if (param_5 == 6) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x56e,
                       "memmgrSetMemDescPageSize_GM107",4,"NVRM: invalid page size attr\n");
          return 0x1f;
        }
        goto LAB_0039b1f0;
      }
      if (param_5 == 2) {
        uVar9 = (**(code **)(lVar7 + 0x1d0))(lVar7);
        if ((uVar9 - 1 & uVar4) != 0) {
          nvAssertFailedNoLog("0 == (physAddr & (newPageSize - 1))",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x556);
          return 0x37;
        }
        goto LAB_0039b497;
      }
      if (param_5 == 3) {
        if (*(char *)(lVar7 + 0x67d0) == '\0') {
          nvAssertFailedNoLog("kgmmuIsHugePageSupported(pKernelGmmu)",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x559);
          return 0x56;
        }
        if ((uVar4 & 0x1fffff) != 0) {
          nvAssertFailedNoLog("0 == (physAddr & (RM_PAGE_SIZE_HUGE - 1))",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x55c);
          return 0x37;
        }
        goto LAB_0039b449;
      }
      if (param_5 != 0) goto LAB_0039b1f0;
      uVar5 = param_3[6];
      if (((*(char *)(lVar7 + 0x67d0) != '\0') && (0x1fffff < uVar5)) && ((uVar4 & 0x1fffff) == 0))
      {
        lVar7 = memdescGetPageSize(param_3,param_4);
        if (lVar7 != 0) {
          return 0;
        }
        goto LAB_0039b390;
      }
      uVar9 = kgmmuGetMinBigPageSize_IMPL(lVar7);
      if (uVar5 < uVar9) {
        uVar3 = memdescGetPteKindForGpu(param_3,*param_3);
        cVar1 = (**(code **)(param_2 + 600))(param_2,uVar3);
        if (cVar1 != '\0') goto LAB_0039b62d;
      }
      else {
LAB_0039b62d:
        lVar8 = (**(code **)(lVar7 + 0x198))(lVar7);
        if ((lVar8 - 1U & uVar4) == 0) {
          uVar9 = (**(code **)(lVar7 + 0x1d0))(lVar7);
          goto LAB_0039b2f3;
        }
      }
      lVar7 = memdescGetPageSize(param_3,param_4);
      if (lVar7 != 0) {
        return 0;
      }
    }
    else {
      uVar4 = memdescGetPageSize(param_3,param_4);
      if (uVar4 != 0) {
        if (param_5 == 0) {
          return 0;
        }
LAB_0039b220:
        uVar9 = 0x1000;
        goto LAB_0039b226;
      }
    }
LAB_0039b200:
    uVar9 = 0x1000;
  }
LAB_0039b206:
  memdescSetPageSize(param_3,param_4,uVar9);
  return 0;
}


// ===== 0039b810 memmgrCalcReservedFbSpaceForUVM_GM107 =====

void memmgrCalcReservedFbSpaceForUVM_GM107(undefined8 param_1,undefined8 param_2,long *param_3)

{
  *param_3 = *param_3 + 0x100000;
  return;
}


// ===== 0039b820 memmgrGetUserdReservedFbSpace_GM107 =====

undefined8 memmgrGetUserdReservedFbSpace_GM107(void)

{
  return 0x200000;
}


// ===== 0039b830 memmgrGetRsvdSizeForSr_GM107 =====

long memmgrGetRsvdSizeForSr_GM107(long param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_2 + 0x830) >> 10;
  if (*(short *)(param_1 + 0x7f6) == 0x2b8c) {
    if (uVar1 < 0x1f) {
      return (-(ulong)(*(char *)(param_1 + 0x909) == '\0') & 0xfffffffff2c00000) + 0x20000000;
    }
  }
  else if (uVar1 < 0x1f) {
    return (-(ulong)(*(char *)(param_1 + 0x909) == '\0') & 0xfffffffff0000000) + 0x20000000;
  }
  return 0x20000000;
}


// ===== 0039b8a0 memmgrGetRunlistEntriesReservedFbSpace_GM107 =====

undefined8 memmgrGetRunlistEntriesReservedFbSpace_GM107(void)

{
  return 0x70000;
}


// ===== 0039b8b0 memmgrScrubRegistryOverrides_GM107 =====

void memmgrScrubRegistryOverrides_GM107(long param_1,long param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  if (((*(char *)(param_1 + 0x4911) == '\0') && (*(char *)(param_1 + 0x4910) == '\0')) &&
     (*(char *)(param_1 + 0x4a3) == '\0')) {
    if (*(char *)(param_1 + 0x908) == '\0') goto LAB_0039b8f4;
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_0039b8eb;
    if (*(char *)(param_2 + 0x484) != '\0') goto LAB_0039b940;
  }
  else {
LAB_0039b8eb:
    *(undefined1 *)(param_2 + 0x480) = 0;
LAB_0039b8f4:
    if (*(char *)(param_2 + 0x484) == '\0') {
      cVar1 = *(char *)(param_1 + 0x4913);
    }
    else {
LAB_0039b940:
      *(undefined1 *)(param_2 + 0x480) = 0;
      cVar1 = *(char *)(param_1 + 0x4913);
    }
    if (cVar1 == '\0') goto LAB_0039b901;
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    *(undefined1 *)(param_2 + 0x485) = 1;
    return;
  }
LAB_0039b901:
  if (*pcVar2 != '\0') {
    *(undefined1 *)(param_2 + 0x485) = 1;
  }
  return;
}


// ===== 0039b970 memmgrGetAddrSpaceSizeMB_GM107 =====

long memmgrGetAddrSpaceSizeMB_GM107(undefined8 param_1,long param_2)

{
  if (*(long *)(param_2 + 0x838) != 0) {
    return *(long *)(param_2 + 0x838);
  }
  nvAssertFailedNoLog("pMemoryManager->Ram.fbAddrSpaceSizeMb != 0",
                      "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x626);
  return *(long *)(param_2 + 0x838);
}


// ===== 0039b9c0 memmgrGetUsableMemSizeMB_GM107 =====

ulong memmgrGetUsableMemSizeMB_GM107(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  if (*(long *)(param_2 + 0x838) == 0) {
    nvAssertFailedNoLog("pMemoryManager->Ram.fbAddrSpaceSizeMb != 0",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x635);
    uVar1 = *(ulong *)(param_2 + 0x828);
  }
  else {
    uVar1 = *(ulong *)(param_2 + 0x828);
  }
  if (uVar1 >> 0x34 == 0) {
    return uVar1 >> 0x14;
  }
  nvAssertFailedNoLog("0 == NvU64_HI32(pMemoryManager->Ram.fbUsableMemSize >> 20)",
                      "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x638);
  return *(ulong *)(param_2 + 0x828) >> 0x14;
}


// ===== 0039ba50 memmgrGetBankPlacementData_GM107 =====

undefined8
memmgrGetBankPlacementData_GM107(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = 0xffffffc0ffffff00;
  param_3[1] = 0xffffffc0ffffff40;
  return 0;
}


// ===== 0039ba70 memmgrDirtyForPmTest_GM107 =====

void memmgrDirtyForPmTest_GM107(void)

{
  return;
}


// ===== 0039ba80 memmgrGetInvalidOffset_GM107 =====

undefined8 memmgrGetInvalidOffset_GM107(void)

{
  return 0xdead000000000000;
}


// ===== 0039ba90 memmgrGetBlackListPages_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrGetBlackListPages_GM107(long param_1,undefined8 param_2,long *param_3,uint *param_4)

{
  undefined4 *puVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  uint uVar8;
  
  lVar5 = kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  if ((*(char *)(param_1 + 0x457) == '\0') ||
     (cVar3 = (**(code **)(param_1 + 0x2f0))(param_1), cVar3 == '\0')) {
    iVar4 = 0x56;
  }
  else {
    plVar6 = (long *)portMemAllocNonPaged(0x808);
    if (plVar6 == (long *)0x0) {
      iVar4 = 0x51;
    }
    else {
      portMemSet(plVar6,0,0x808);
      iVar4 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                         *(undefined4 *)(param_1 + 0x3b3c),0x20801322,plVar6,0x808);
      if (iVar4 == 0) {
        uVar8 = 0;
        if ((int)plVar6[0x100] != 0) {
          uVar8 = 0;
          plVar7 = plVar6;
          do {
            if (*param_4 <= uVar8) {
              iVar4 = 2;
              break;
            }
            if (*(char *)(lVar5 + 5) == '\0') {
              lVar2 = plVar7[1];
            }
            else {
              lVar2 = *plVar7;
            }
            *param_3 = lVar2 << 0xc;
            puVar1 = (undefined4 *)((long)plVar7 + 0x14);
            uVar8 = uVar8 + 1;
            plVar7 = plVar7 + 4;
            *(undefined4 *)(param_3 + 1) = *puVar1;
            param_3 = param_3 + 2;
          } while (uVar8 < *(uint *)(plVar6 + 0x100));
        }
      }
      else if (iVar4 == 0x56) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x6d8,
                     "memmgrGetBlackListPages_GM107",1,"NVRM: Offlining pages not supported\n");
        uVar8 = 0;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x6dd,
                     "memmgrGetBlackListPages_GM107",4,"NVRM: Failed to read offlined addresses\n");
        uVar8 = 0;
      }
      *param_4 = uVar8;
      portMemFree(plVar6);
    }
  }
  return iVar4;
}


// ===== 0039bc50 memmgrGetBlackListPagesForHeap_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 memmgrGetBlackListPagesForHeap_GM107(long param_1,long param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  ulong *puVar3;
  ulong *puVar4;
  uint uVar5;
  uint local_3c [3];
  
  uVar1 = (**(code **)(*(long *)(param_1 + 0x1b70) + 0x270))();
  local_3c[0] = (uint)uVar1;
  puVar3 = (ulong *)portMemAllocNonPaged((ulong)uVar1 << 4);
  if (puVar3 == (ulong *)0x0) {
    return 0x51;
  }
  iVar2 = (**(code **)(param_2 + 0x3a8))(param_1,param_2,puVar3,local_3c);
  if (iVar2 == 2) {
    nvAssertFailedNoLog("status != NV_ERR_BUFFER_TOO_SMALL",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x702);
  }
  else if ((iVar2 == 0) && (local_3c[0] != 0)) {
    uVar5 = 0;
    puVar4 = puVar3;
    do {
      iVar2 = heapAddPageToBlackList_IMPL(param_1,param_3,*puVar4 >> 0xc,(int)puVar4[1]);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x70f,
                     "memmgrGetBlackListPagesForHeap_GM107",4,
                     "NVRM: No more space in blacklist, status: %x!\n",iVar2);
        nvAssertFailedNoLog(&DAT_00d46137,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",
                            0x710);
        break;
      }
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 2;
    } while (uVar5 < local_3c[0]);
  }
  portMemFree(puVar3);
  return 0;
}


// ===== 0039bdb0 memmgrGetFBEndReserveSizeEstimate_GM107 =====

undefined8 memmgrGetFBEndReserveSizeEstimate_GM107(void)

{
  return 0x200000;
}


// ===== 0039bdc0 memmgrCalcReservedFbSpaceHal_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrCalcReservedFbSpaceHal_GM107
               (long param_1,long param_2,ulong *param_3,ulong *param_4,ulong *param_5)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  ulong local_50;
  
  lVar2 = *(long *)(param_1 + 0x1b98);
  lVar7 = gpuGetKernelFifoShared_IMPL();
  lVar3 = *(long *)(param_1 + 0x1bd0);
  *(undefined4 *)(param_2 + 0xc68) = 0;
  puVar8 = (undefined4 *)(param_2 + 0xc70);
  do {
    *puVar8 = 0;
    puVar9 = puVar8 + 4;
    *(undefined8 *)(puVar8 + 2) = 0;
    puVar8 = puVar9;
  } while ((undefined4 *)(param_2 + 0xd10) != puVar9);
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_0039be91;
  }
  else if ((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0')) {
    *param_3 = 0x400000;
    *param_4 = 0;
    *param_5 = 0;
    return;
  }
  if (*(ulong *)(param_2 + 0x830) < 0x401) {
    *param_3 = 0x5800000;
    *param_4 = 0;
    *param_5 = 0;
    return;
  }
LAB_0039be91:
  *param_3 = 0;
  uVar11 = *(ulong *)(param_2 + 0xba0);
  uVar10 = *(ulong *)(param_2 + 0x828) >> 1;
  if (uVar10 < uVar11) {
    *(ulong *)(param_2 + 0xba0) = uVar10;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x771,
                 "memmgrCalcReservedFbSpaceHal_GM107",4,
                 "NVRM: RM can only increase reserved heap by 0x%llx bytes\n",uVar10);
    uVar11 = *(ulong *)(param_2 + 0xba0);
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x775,
               "memmgrCalcReservedFbSpaceHal_GM107",1,
               "NVRM: RT::: incrementing the reserved size by: %llx\n",uVar11);
  *param_4 = *(ulong *)(param_2 + 0xba0);
  *param_5 = 0;
  cVar4 = rmcfg_IsGB20XorBetter(param_1);
  if (((cVar4 != '\0') && (*(char *)(param_1 + 0x4a4e) != '\0')) &&
     (*(char *)(param_1 + 0x908) == '\0')) {
    *param_4 = *param_4 + 0x9600000;
  }
  iVar14 = 0x51;
  uVar5 = (**(code **)(param_2 + 0x328))(param_1,param_2);
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    iVar14 = 0;
    *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0xd;
    *(ulong *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = (ulong)uVar5;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
  }
  uVar11 = (ulong)uVar5 + *param_3;
  *param_3 = uVar11;
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0xf;
    *(undefined8 *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = 0x100000;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
    uVar11 = *param_3;
  }
  else {
    iVar14 = 0x51;
  }
  *param_3 = uVar11 + 0x100000;
  uVar11 = *(ulong *)(param_2 + 0x828);
  uVar10 = (uVar11 >> 0xc) * 8 + 0xfff & 0xfffffffffffff000;
  local_50 = uVar10;
  if (*(char *)(param_1 + 0x4a3) != '\0') {
    cVar4 = rmcfg_IsADA_CLASSIC_GPUSorBetter(param_1);
    uVar11 = *(ulong *)(param_2 + 0x828);
    local_50 = (uVar10 >> 3) + 0xfff & 0xfffffffffffff000;
    if (cVar4 == '\0') {
      local_50 = uVar10;
    }
  }
  uVar10 = (**(code **)(lVar2 + 0x198))();
  uVar13 = uVar11 % uVar10;
  uVar11 = (uVar11 / uVar10) * 8 + 0xfff & 0xfffffffffffff000;
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    uVar13 = (ulong)uVar1 * 0x10;
    *(undefined4 *)(param_2 + 0xc70 + uVar13) = 0x1d;
    *(ulong *)(param_2 + 0xc78 + uVar13) = local_50 + uVar11;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
  }
  else {
    iVar14 = 0x51;
  }
  uVar5 = (**(code **)(param_2 + 0x338))(param_1,param_2,uVar13);
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0x1b;
    *(ulong *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = (ulong)uVar5;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
  }
  else {
    iVar14 = 0x51;
  }
  uVar6 = (**(code **)(param_2 + 0x330))(param_1,param_2);
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0x1c;
    *(ulong *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = (ulong)uVar6;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
  }
  else {
    iVar14 = 0x51;
  }
  lVar12 = (**(code **)(param_2 + 0x200))(param_1,param_2);
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0xc;
    *(long *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = lVar12;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
  }
  else {
    iVar14 = 0x51;
  }
  *param_4 = local_50 + *param_4 + uVar11 + (ulong)uVar5 + (ulong)uVar6 + lVar12;
  (**(code **)(param_2 + 0x318))(param_1,param_2,param_4);
  uVar5 = (**(code **)(lVar2 + 400))(param_1);
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0x1e;
    *(ulong *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = (ulong)uVar5;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
  }
  else {
    iVar14 = 0x51;
  }
  *param_4 = *param_4 + (ulong)uVar5;
  uVar5 = (**(code **)(lVar7 + 0x2b0))(param_1,lVar7,1);
  uVar1 = *(uint *)(param_2 + 0xc68);
  if (uVar1 < 10) {
    *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0x1f;
    *(ulong *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = (ulong)uVar5;
    *(uint *)(param_2 + 0xc68) = uVar1 + 1;
  }
  else {
    iVar14 = 0x51;
  }
  uVar11 = (ulong)uVar5 + *param_4;
  *param_4 = uVar11;
  if (*(char *)(lVar3 + 0x207) != '\0') {
    uVar11 = uVar11 + *(uint *)(param_1 + 0x3a10);
    *param_4 = uVar11;
    uVar1 = *(uint *)(param_2 + 0xc68);
    if (uVar1 < 10) {
      *(undefined4 *)(param_2 + 0xc70 + (ulong)uVar1 * 0x10) = 0x11;
      *(ulong *)(param_2 + 0xc78 + (ulong)uVar1 * 0x10) = (ulong)*(uint *)(param_1 + 0x3a10);
      *(uint *)(param_2 + 0xc68) = uVar1 + 1;
      uVar11 = *param_4;
    }
    else {
      iVar14 = 0x51;
    }
  }
  uVar10 = *(ulong *)(param_2 + 0x828);
  uVar13 = *param_3;
  if (uVar10 >> 1 < uVar13 + uVar11) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x7d2,
                 "memmgrCalcReservedFbSpaceHal_GM107",4,
                 "NVRM: Before capping: rsvdFastSize = 0x%llx bytes rsvdSlowSize = 0x%llx bytes Usable FB = 0x%llx bytes\n"
                 ,uVar13,uVar11,uVar10);
    if (*(long *)(param_2 + 0xba0) != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x7d8,
                   "memmgrCalcReservedFbSpaceHal_GM107",4,
                   "NVRM: Fail the rsvd memory capping in case of user specified increase = %llx bytes\n"
                  );
      *param_3 = 0;
      *param_4 = 0;
      nvAssertFailedNoLog(&DAT_00d46137,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x7dd)
      ;
      return;
    }
    uVar11 = (*(long *)(param_2 + 0x828) * *param_3 >> 1) / (*param_3 + *param_4);
    *param_3 = uVar11;
    uVar11 = (*(ulong *)(param_2 + 0x828) >> 1) - uVar11;
    *param_4 = uVar11;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x7e4,
                 "memmgrCalcReservedFbSpaceHal_GM107",4,
                 "NVRM: After capping: rsvdFastSize = 0x%llx bytes rsvdSlowSize = 0x%llx bytes\n",
                 *param_3,uVar11,uVar10);
    uVar13 = *param_3;
  }
  if (*(char *)(param_2 + 0x439) == '\0') {
    *param_3 = uVar13 + *param_4;
    *param_4 = 0;
    uVar13 = *param_3;
  }
  *param_3 = uVar13 + 0xffff & 0xffffffffffff0000;
  *param_4 = *param_4 + 0xffff & 0xffffffffffff0000;
  *param_5 = *param_5 + 0xffff & 0xffffffffffff0000;
  if (iVar14 == 0) {
    return;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x7fa,
               "memmgrCalcReservedFbSpaceHal_GM107",3,
               "NVRM: Error logging the FB reservation entries\n");
  return;
}


// ===== 0039c5a0 memmgrPreInitReservedMemory_GM107 =====

undefined8 memmgrPreInitReservedMemory_GM107(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  undefined4 uVar4;
  long local_30 [2];
  
  lVar2 = *(long *)(&DAT_00001b90 + param_1);
  uVar1 = *(uint *)(param_1 + 0x4924);
  local_30[0] = (ulong)(*(char *)(param_1 + 0x909) != '\0' && *(long *)(param_1 + 0x1b80) != 0) <<
                0x10;
  *(undefined8 *)(lVar2 + 0xad3c) = 0x200000002;
  memdescOverrideInstLoc(uVar1 >> 4 & 3,"BAR instblk",lVar2 + 0xad3c,lVar2 + 0xad40);
  if (*(int *)(lVar2 + 0xad3c) == 2) {
    uVar3 = local_30[0] + 0xfffU & 0xfffffffffffff000;
    *(ulong *)(lVar2 + 0x640) = uVar3;
    *(ulong *)(lVar2 + 0x4670) = uVar3 + 0x1000;
    local_30[0] = uVar3 + 0x2000;
    uVar4 = 0;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x835,
                 "memmgrPreInitReservedMemory_GM107",1,
                 "NVRM: Reserve space for Bar1 inst block offset = 0x%llx size = 0x%x\n",uVar3,
                 0x1000);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x838,
                 "memmgrPreInitReservedMemory_GM107",1,
                 "NVRM: Reserve space for Bar2 inst block offset = 0x%llx size = 0x%x\n",
                 *(undefined8 *)(lVar2 + 0x4670),CONCAT44(uVar4,0x1000));
  }
  memmgrReserveBar2BackingStore_IMPL(param_1,param_2,local_30);
  *(long *)(param_2 + 0x498) = local_30[0];
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x848,
               "memmgrPreInitReservedMemory_GM107",1,
               "NVRM: Calculated size of reserved memory = 0x%llx. Size finalized in StateInit.\n");
  return 0;
}


// ===== 0039c710 memmgrAllocateConsoleRegion_GM107 =====

int memmgrAllocateConsoleRegion_GM107(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  if (*(long *)(param_2 + 0xb38) == 0) {
    return 0;
  }
  *(undefined2 *)(param_2 + 0x884) = 0x100;
  if (*(long *)(param_2 + 0xb60) == 0) {
    lVar1 = *(long *)(param_2 + 0x860);
    lVar3 = (*(long *)(param_2 + 0x868) + 1) - lVar1;
    iVar2 = memdescCreate(param_2 + 0xb60,param_1,lVar3,0x10000,1,2,1,0x20000);
    if (iVar2 != 0) {
      return iVar2;
    }
    memdescDescribe(*(undefined8 *)(param_2 + 0xb60),2,lVar1,lVar3);
    memdescSetPageSize(*(undefined8 *)(param_2 + 0xb60),1,0x1000);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x879,
                 "memmgrAllocateConsoleRegion_GM107",1,
                 "NVRM: Allocating console region of size: %llx, at base : %llx \n ",lVar3,lVar1);
    iVar2 = 0;
  }
  else {
    nvAssertFailedNoLog("pMemoryManager->pReservedConsoleMemDesc == NULL",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_mgr_gm107.c",0x867);
    iVar2 = 99;
  }
  return iVar2;
}


// ===== 0039c860 memmgrGetMaxContextSize_GM200 =====

long memmgrGetMaxContextSize_GM200(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0x700000;
  if (*(char *)(param_2 + 0x433) != '\0') {
    lVar1 = (ulong)(*(char *)(param_2 + 0x432) != '\0') * 0x2000000 + 0x700000;
  }
  return lVar1;
}


// ===== 0039c890 memmgrMemUtilsChannelInitialize_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_r11 replaced with injection: x86_indirect_thunk_r11 */

int memmgrMemUtilsChannelInitialize_GM107(long param_1,long param_2,undefined4 *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined8 *puVar18;
  long lVar19;
  long lVar20;
  ulong uVar21;
  long lVar22;
  undefined4 uVar23;
  ulong uVar24;
  ulong uVar25;
  undefined4 uVar26;
  ulong uVar27;
  char *pcVar28;
  ulong uVar29;
  ulong uVar30;
  bool bVar31;
  undefined4 *puVar32;
  undefined8 uVar33;
  undefined8 uVar34;
  undefined8 uVar35;
  undefined4 local_308;
  uint local_304;
  uint local_2f0;
  long local_2b8;
  undefined4 local_2a0;
  ulong local_298;
  long local_290;
  undefined4 local_27c;
  undefined8 local_278;
  undefined8 local_270;
  long local_268;
  undefined8 local_260;
  ulong local_250;
  uint local_248;
  undefined8 local_238;
  undefined1 local_228 [16];
  ulong local_218;
  undefined8 local_210;
  undefined4 local_208;
  undefined8 local_204;
  undefined4 local_1fc;
  undefined4 uStack_1f8;
  undefined4 local_1f4;
  undefined4 uStack_1f0;
  undefined4 local_1ec;
  undefined1 local_1e8 [48];
  undefined4 local_1b8;
  ulong local_1a8;
  ulong local_1a0 [2];
  ulong local_190;
  undefined4 local_188;
  ulong local_168;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_128;
  undefined4 local_104;
  ulong local_f0;
  
  uVar33 = *(undefined8 *)(param_3 + 0x18);
  uVar2 = param_3[0x2b];
  uVar3 = *param_3;
  uVar4 = param_3[1];
  uVar5 = param_3[0xe];
  local_2a0 = param_3[2];
  uVar10 = *(undefined8 *)(param_3 + 4);
  uVar26 = param_3[4];
  uVar6 = param_3[5];
  uVar7 = param_3[8];
  local_290 = rmapiGetInterface(4);
  if ((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) {
    bVar31 = false;
  }
  else {
    cVar12 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
    bVar31 = cVar12 != '\0';
  }
  cVar12 = *(char *)(param_3 + 0x65);
  cVar14 = *(char *)(*(long *)(g_pSys + 0x208) + 0x68);
  puVar18 = (undefined8 *)portMemAllocNonPaged(0x80);
  if (puVar18 == (undefined8 *)0x0) {
    iVar17 = 0x51;
    goto LAB_0039d524;
  }
  *(undefined1 *)(param_3 + 0x5c) = 1;
  if ((*(char *)((long)param_3 + 0x5e) != '\0') ||
     ((*(char *)(param_1 + 0x909) != '\0' && (bVar31)))) {
    lVar19 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
    lVar20 = *(long *)(lVar19 + 0x70);
    local_2b8 = *(long *)(lVar19 + 0x68);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x256,
                 "memmgrMemUtilsChannelInitialize_GM107",1,
                 "NVRM: Channel VAS heap base: %llx total: %llx \n",local_2b8,lVar20);
    *(long *)(param_3 + 0x1e) = local_2b8;
    *(long *)(param_3 + 0x20) = lVar20;
    if (*(char *)((long)param_3 + 0x5e) != '\0') {
      iVar17 = clientGenResourceHandle_IMPL(uVar33,param_3 + 0xc);
      if (iVar17 != 0) {
        nvAssertOkFailedNoLog
                  (iVar17,"clientGenResourceHandle(pRsClient, &pChannel->hFbAlias)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x25e);
        goto LAB_0039d524;
      }
      iVar17 = (**(code **)(param_2 + 0x1c0))(param_1,param_2,param_3);
      if (iVar17 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x265,
                     "memmgrMemUtilsChannelInitialize_GM107",4,
                     "NVRM: Setting Identity mapping failed.. status: %x\n",iVar17);
        goto LAB_0039d524;
      }
    }
    portMemSet(puVar18,0,0x38);
    *(undefined4 *)puVar18 = 0;
    lVar19 = puVar18[1];
    puVar18[5] = *(undefined8 *)(param_3 + 0x1e);
    if (*(char *)(param_1 + 0x4922) != '\0') {
      lVar19 = lVar19 + 0x120000000;
      puVar18[1] = lVar19;
    }
    puVar18[1] = lVar20 + 0x20000000 + (ulong)(uint)param_3[0xe] + lVar19;
    uVar15 = *(uint *)((long)puVar18 + 4) | 0xd00;
    *(uint *)((long)puVar18 + 4) = uVar15;
    if (*(long *)(param_1 + 0x1bc0) == 0) {
LAB_0039d327:
      *(uint *)((long)puVar18 + 4) = uVar15 | 0x2000;
    }
    else {
      cVar13 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
      if (cVar13 == '\0') {
        uVar15 = *(uint *)((long)puVar18 + 4);
        goto LAB_0039d327;
      }
    }
    cVar13 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
    if ((cVar13 == '\0') || (cVar13 = rmapiInRtd3PmPath(), cVar13 != '\0')) {
      iVar17 = (**(code **)(local_290 + 8))
                         (local_290,uVar2,*param_3,param_3[0xb],0x90f1,puVar18,0x38);
LAB_0039d372:
      if (iVar17 == 0) {
        iVar17 = vaspaceGetByHandleOrDeviceDefault_IMPL(uVar33,*param_3,param_3[0xb],param_3 + 0x1a)
        ;
        if (iVar17 != 0) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x2aa,
                       "memmgrMemUtilsChannelInitialize_GM107",4,
                       "NVRM: failed getting the scrubber vaspace from handle, status=0x%x\n",iVar17
                      );
          goto LAB_0039d524;
        }
        if (*(char *)((long)param_3 + 0x5e) != '\0') {
          if ((*(char *)(param_1 + 0x491e) == '\0') &&
             (iVar17 = (**(code **)(**(long **)(param_3 + 0x1a) + 0xd0))
                                 (*(long **)(param_3 + 0x1a),param_1), iVar17 != 0)) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x2b7,
                         "memmgrMemUtilsChannelInitialize_GM107",4,
                         "NVRM: failed pinning down Scrubber VAS, status=0x%x\n",iVar17);
            goto LAB_0039d524;
          }
          iVar17 = clientGenResourceHandle_IMPL(uVar33,param_3 + 0xd);
          if (iVar17 != 0) {
            nvAssertOkFailedNoLog
                      (iVar17,"clientGenResourceHandle(pRsClient, &pChannel->hFbAliasVA)",
                       "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x2bd);
            goto LAB_0039d524;
          }
        }
        if (*(char *)(param_1 + 0x4922) != '\0') {
          lVar19 = __nvoc_dynamicCast(*(undefined8 *)(param_3 + 0x1a),__nvoc_class_def_OBJGVASPACE);
          local_2b8 = local_2b8 + (*(long *)(lVar19 + 0x158) + 0x20000000U & 0xffffffffe0000000);
          *(long *)(param_3 + 0x24) = local_2b8;
        }
        cVar13 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_1 + 0x7a4));
        if (cVar13 == '\0') {
          if (*(char *)((long)param_3 + 0x5e) == '\0') goto LAB_0039c9b7;
          portMemSet(puVar18,0,0x80);
          *puVar18 = 0xc;
          uVar33 = *(undefined8 *)(param_3 + 0x20);
          puVar18[3] = 0x3000000;
          puVar18[8] = uVar33;
          *(undefined4 *)(puVar18 + 1) = 0x80410;
          puVar18[10] = local_2b8;
          *(undefined4 *)((long)puVar18 + 0x6c) = param_3[0xb];
          iVar17 = (**(code **)(local_290 + 8))
                             (local_290,uVar2,*param_3,param_3[0xd],0x50a0,puVar18,0x80);
LAB_0039d4bf:
          if (iVar17 == 0) {
LAB_0039d978:
            if (*(char *)((long)param_3 + 0x5e) == '\0') goto LAB_0039c9b7;
            lVar19 = rmapiGetInterface(4);
            local_268 = 0;
            iVar17 = (**(code **)(lVar19 + 0x38))
                               (lVar19,param_3[0x2b],param_3[3],0x20800188,&local_268,8);
            if (iVar17 == 0) {
              uVar15 = 0;
              if (local_268 == 0) {
                nvAssertFailedNoLog("maxPageSizeParams.maxSupportedPageSize != 0",
                                    "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x1a3);
              }
              else {
                do {
                  uVar24 = (ulong)uVar15;
                  uVar15 = uVar15 + 0x20;
                  *(undefined8 *)((long)&local_1a8 + uVar24) = 0;
                  *(undefined8 *)((long)local_1a0 + uVar24) = 0;
                  *(undefined8 *)((long)local_1a0 + uVar24 + 8) = 0;
                  *(undefined8 *)((long)&local_190 + uVar24) = 0;
                } while (uVar15 < 0xc0);
                local_104 = param_3[0xb];
                iVar17 = (**(code **)(lVar19 + 0x38))
                                   (lVar19,param_3[0x2b],*param_3,0x801806,&local_1a8,0xc0);
                if (iVar17 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar17,
                             "pRmApi->Control(pRmApi, pChannel->hClient, pChannel->deviceId, NV0080_CTRL_CMD_DMA_ADV_SCHED_GET_VA_CAPS, &vasCapsParams, sizeof(vasCapsParams))"
                             ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x1a7);
                  goto LAB_0039e367;
                }
                if (local_f0 == 0) {
                  nvAssertFailedNoLog("vasCapsParams.supportedPageSizeMask != 0",
                                      "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x1ab)
                  ;
                }
                else {
                  uVar24 = *(ulong *)(param_3 + 0x1e);
                  local_f0 = local_f0 & 0xffffffbfdfffffff;
                  if ((uVar24 & 0x1fffffff) == 0) {
                    uVar29 = *(ulong *)(param_3 + 0x24);
                    uVar27 = (ulong)((uint)uVar29 & 0x1fffffff);
                    if ((uVar29 & 0x1fffffff) == 0) {
                      local_298 = *(ulong *)(param_3 + 0x20);
                      uVar25 = (-uVar29 & uVar29) * 2 - 1 &
                               (-uVar24 & uVar24) * 2 - 1 & local_268 * 2 - 1U & local_f0;
                      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x1c1,
                                   "memmgrMemUtilsMapFbAlias",1,
                                   "NVRM: fb start 0x%llx size 0x%llx supported page sizes 0x%llx (0x%llx) va start 0x%llx\n"
                                   ,uVar24,local_298,uVar25,local_f0,uVar29);
                      uVar24 = *(ulong *)(param_3 + 0x20);
                      if (uVar24 != 0) {
                        do {
                          if (uVar25 == 0) break;
                          uVar21 = uVar25 >> 1 | uVar25;
                          uVar21 = uVar21 | uVar21 >> 2;
                          uVar21 = uVar21 | uVar21 >> 4;
                          uVar21 = uVar21 | uVar21 >> 8;
                          uVar21 = uVar21 | uVar21 >> 0x10;
                          uVar21 = uVar21 | uVar21 >> 0x20;
                          uVar30 = uVar21 - (uVar21 >> 1);
                          if ((uVar27 & uVar30 - 1) != 0) {
                            nvAssertFailedNoLog("NV_IS_ALIGNED64(currentFbOffset, pageSize)",
                                                "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c"
                                                ,0x1cd);
                            goto LAB_0039e362;
                          }
                          if ((uVar30 - 1 & uVar29) != 0) {
                            nvAssertFailedNoLog("NV_IS_ALIGNED64(currentVaddr, pageSize)",
                                                "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c"
                                                ,0x1ce);
                            goto LAB_0039e362;
                          }
                          if (uVar30 <= local_298) {
                            if (uVar30 == 0x200000) {
                              uVar11 = 0x8400;
                            }
                            else if (uVar30 < 0x200001) {
                              if ((uVar30 - 0x10000 & 0xfffffffffffeffff) == 0) {
                                if (uVar30 != local_1a0[0] >> 0x20) {
                                  nvAssertFailedNoLog("pageSize == vasCapsParams.bigPageSize",
                                                                                                            
                                                  "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c"
                                                  ,0x1dc);
                                  goto LAB_0039e362;
                                }
                                uVar11 = 0x8200;
                              }
                              else {
                                uVar11 = 0x8100;
                                if (uVar30 != 0x1000) goto LAB_0039e292;
                              }
                            }
                            else {
                              uVar11 = 0x8500;
                              if (uVar30 != 0x20000000) {
LAB_0039e292:
                                nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c"
                                             ,0x1e6,"memmgrMemUtilsMapFbAlias",1,
                                             "NVRM: page size not supported: 0x%llx\n",uVar30);
                                uVar24 = *(ulong *)(param_3 + 0x20);
                                goto LAB_0039dd02;
                              }
                            }
                            local_208 = uVar11;
                            local_1fc = 0;
                            uVar21 = (uVar21 >> 1) - uVar21 & local_298;
                            uStack_1f0 = 0;
                            local_228._8_8_ = CONCAT44(param_3[0xc],param_3[0xd]);
                            local_204 = 0;
                            local_1ec = 0;
                            local_228._0_8_ = CONCAT44(*param_3,param_3[0x2b]);
                            uStack_1f8 = (undefined4)uVar29;
                            local_1f4 = (undefined4)(uVar29 >> 0x20);
                            local_218 = uVar27;
                            local_210 = uVar21;
                            iVar17 = (**(code **)(lVar19 + 0x98))(lVar19,local_228);
                            if (iVar17 != 0) {
                              nvAssertOkFailedNoLog
                                        (iVar17,"pRmApi->Map(pRmApi, &mapDmaParams)",
                                         "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
                                         0x1f7);
                              goto LAB_0039e367;
                            }
                            lVar20 = CONCAT44(local_1f4,uStack_1f8);
                            nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
                                         0x1fb,"memmgrMemUtilsMapFbAlias",1,
                                         "NVRM: CeUtils VAS : FB (addr: %llx, size: %llx) identity mapped to VAS at addr: %llx, page size: 0x%llx\n"
                                         ,uVar27,uVar21,lVar20,uVar30);
                            local_298 = local_298 - uVar21;
                            uVar24 = *(ulong *)(param_3 + 0x20);
                            uVar29 = lVar20 + uVar21;
                            uVar27 = uVar27 + uVar21;
                          }
LAB_0039dd02:
                          uVar25 = uVar25 & ~uVar30;
                        } while (uVar27 < uVar24);
                        if (uVar24 != uVar27) {
                          nvAssertFailedNoLog("currentFbOffset == pChannel->fbSize",
                                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c"
                                              ,0x203);
                          goto LAB_0039e362;
                        }
                      }
                      *(undefined8 *)(param_3 + 0x22) = *(undefined8 *)(param_3 + 0x24);
                      goto LAB_0039c9b7;
                    }
                    nvAssertFailedNoLog("NV_IS_ALIGNED64(pChannel->vaStartOffset, RM_PAGE_SIZE_512M)"
                                        ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
                                        0x1be);
                  }
                  else {
                    nvAssertFailedNoLog("NV_IS_ALIGNED64(pChannel->startFbOffset, RM_PAGE_SIZE_512M)"
                                        ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
                                        0x1bb);
                  }
                }
              }
LAB_0039e362:
              iVar17 = 0x40;
            }
            else {
              nvAssertOkFailedNoLog
                        (iVar17,
                         "pRmApi->Control(pRmApi, pChannel->hClient, pChannel->subdeviceId, NV2080_CTRL_CMD_GPU_GET_MAX_SUPPORTED_PAGE_SIZE, &maxPageSizeParams, sizeof(maxPageSizeParams))"
                         ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x19f);
            }
LAB_0039e367:
            nvCheckOkFailedNoLog
                      (4,iVar17,"memmgrMemUtilsMapFbAlias(pMemoryManager, pChannel)",
                       "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x2fc);
            goto LAB_0039d524;
          }
        }
        else {
          rmGpuLocksRelease(0,0);
          lVar19 = rmapiGetInterface(3);
          if (*(char *)((long)param_3 + 0x5e) != '\0') {
            uVar35 = 0x39df3f;
            portMemSet(puVar18,0,0x80);
            *puVar18 = 0xc;
            uVar33 = *(undefined8 *)(param_3 + 0x20);
            puVar18[3] = 0x3000000;
            puVar18[8] = uVar33;
            *(undefined4 *)(puVar18 + 1) = 0x80410;
            puVar18[10] = local_2b8;
            *(undefined4 *)((long)puVar18 + 0x6c) = param_3[0xb];
            iVar17 = (**(code **)(lVar19 + 8))
                               (lVar19,uVar2,*param_3,param_3[0xd],0x50a0,puVar18,0x80);
            iVar16 = rmGpuLocksAcquire(0,0x2000);
            if (iVar16 != 0) {
              nvAssertOkFailedNoLog
                        (iVar16,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM)",
                         "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x2ed,uVar35);
              if (iVar17 == 0) {
                iVar17 = iVar16;
              }
              goto LAB_0039e5c7;
            }
            local_290 = rmapiGetInterface(4);
            goto LAB_0039d4bf;
          }
          iVar17 = rmGpuLocksAcquire(0,0x2000);
          if (iVar17 == 0) {
            local_290 = rmapiGetInterface(4);
            goto LAB_0039d978;
          }
          nvAssertOkFailedNoLog
                    (iVar17,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM)",
                     "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x2ed);
LAB_0039e5c7:
          local_290 = rmapiGetInterface(4);
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x2f4,
                     "memmgrMemUtilsChannelInitialize_GM107",4,
                     "NVRM: Allocating VASpace for (base, size): (%llx, %llx) failed, with status: %x\n"
                     ,local_2b8,*(undefined8 *)(param_3 + 0x20),iVar17);
        goto LAB_0039d524;
      }
    }
    else {
      rmGpuLocksRelease(0,0);
      uVar34 = 0x39d6e8;
      lVar19 = rmapiGetInterface(3);
      uVar35 = 0x38;
      iVar17 = (**(code **)(lVar19 + 8))(lVar19,uVar2,*param_3,param_3[0xb],0x90f1,puVar18);
      iVar16 = rmGpuLocksAcquire(0,0x2000);
      if (iVar16 == 0) {
        local_290 = rmapiGetInterface(4);
        goto LAB_0039d372;
      }
      nvAssertOkFailedNoLog
                (iVar16,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM)",
                 "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x298,uVar35,uVar34);
      if (iVar17 == 0) {
        local_290 = rmapiGetInterface(4);
        iVar17 = iVar16;
      }
      else {
        local_290 = rmapiGetInterface(4);
      }
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x29f,
                 "memmgrMemUtilsChannelInitialize_GM107",4,
                 "NVRM: failed allocating scrubber vaspace, status=0x%x\n",iVar17);
    goto LAB_0039d524;
  }
LAB_0039c9b7:
  rmGpuLocksRelease(0,0);
  bVar31 = (~*(uint *)(param_1 + 0x4930) & 0xc) == 0;
  uVar1 = *(ushort *)(param_1 + 0x4926);
  lVar19 = gpuGetKernelFifoShared_IMPL(param_1);
  iVar17 = (**(code **)(lVar19 + 0x1c8))
                     (lVar19,(1 < (uVar1 & 3) - 1) + '\x01',bVar31 + '\x01',bVar31 + '\x01',
                      *(code **)(lVar19 + 0x1c8));
  if (iVar17 != 0) {
    nvAssertFailedNoLog("USERD in sysmem and PushBuffer/GPFIFO in vidmem not allowed",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x333);
    goto LAB_0039d524;
  }
  lVar19 = rmapiGetInterface(4);
  uVar15 = *(uint *)(param_1 + 0x4930) >> 2 & 3;
  if (uVar15 == 2) {
    local_308 = 0;
    local_2f0 = 0x2000000;
    local_304 = 0x2000000;
    uVar11 = 0x3e;
  }
  else if (uVar15 == 3) {
    if (*(long *)(param_1 + 0x1bc0) == 0) {
      local_2f0 = 0x4000;
      local_308 = 0x10000;
      local_304 = 0x4000;
      uVar11 = 0x40;
    }
    else {
      cVar13 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
      local_308 = 0x10000;
      uVar11 = 0x40;
      local_304 = -(uint)(cVar13 == '\0') & 0x4000;
      local_2f0 = -(uint)(cVar13 == '\0') & 0x4000;
    }
  }
  else {
    local_308 = 0;
    local_304 = 0x2000000;
    if (uVar15 == 1) {
      local_304 = 0x22000000;
    }
    local_2f0 = 0x22000000;
    uVar11 = 0x3e;
  }
  uVar8 = *param_3;
  uVar23 = param_3[1];
  uVar9 = param_3[8];
  uVar15 = param_3[0xe];
  cVar13 = rmGpuLockIsOwner();
  if (cVar13 == '\0') {
    portMemSet(&local_1a8,0,0x80);
    local_1a8 = 0xdeaf0006;
    local_168 = (ulong)uVar15;
    local_138 = 4;
    local_190 = (ulong)local_304;
    local_1a0[0] = CONCAT44(local_1a0[0]._4_4_,local_308);
    uVar33 = 0x39cb0e;
    cVar13 = gpuIsApmFeatureEnabled_IMPL(param_1);
    if ((cVar13 != '\0') || (((uint)local_190 & 0x6000000) == 0x2000000)) {
      local_190 = local_190 | 0x400000000000000;
    }
    iVar16 = (**(code **)(lVar19 + 8))(lVar19,param_3[0x2b],uVar8,uVar23,uVar11,&local_1a8,0x80);
    if (iVar16 == 0) {
      portMemSet(&local_1a8,0,0x80,uVar33);
      local_1a0[0] = local_1a0[0] | 0x80000;
      local_1a8 = 0xdeaf0006;
      local_168 = (ulong)uVar15;
      local_190 = 0x2000000;
      local_13c = param_3[0xb];
      iVar16 = (**(code **)(lVar19 + 8))(lVar19,param_3[0x2b],uVar8,uVar9,0x50a0,&local_1a8,0x80);
      if (iVar16 == 0) {
        cVar13 = gpuIsCCFeatureEnabled_IMPL(param_1);
        uVar23 = 0x3e;
        if (cVar13 == '\0') {
          uVar23 = uVar11;
        }
        uVar15 = 0x2000000;
        if (cVar13 == '\0') {
          uVar15 = local_2f0;
        }
        portMemSet(&local_1a8,0,0x80);
        local_1a8 = 0xdeaf0006;
        local_168 = (ulong)(uint)param_3[0x11];
        local_190 = (ulong)uVar15;
        local_1a0[0] = local_1a0[0] & 0xffffffff00000000;
        local_138 = 4;
        uVar33 = 0x39cc84;
        cVar13 = gpuIsApmFeatureEnabled_IMPL(param_1);
        if ((cVar13 != '\0') || (((uint)local_190 & 0x6000000) == 0x2000000)) {
          local_190 = local_190 | 0x400000000000000;
        }
        iVar16 = (**(code **)(lVar19 + 8))(lVar19,param_3[0x2b],uVar8,param_3[5],uVar23,&local_1a8);
        if (iVar16 == 0) {
          portMemSet(&local_1a8,0,0x80);
          local_1a0[0] = local_1a0[0] | 0x80000;
          local_1a8 = 0xdeaf0006;
          local_168 = (ulong)(uint)param_3[0x11];
          local_190 = 0x2000000;
          local_13c = param_3[0xb];
          iVar16 = (**(code **)(lVar19 + 8))
                             (lVar19,param_3[0x2b],uVar8,param_3[4],0x50a0,&local_1a8,0x80);
          if (iVar16 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar16,
                       "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, hDevice, pChannel->errNotifierIdVirt, NV50_MEMORY_VIRTUAL, &memAllocParams, sizeof(memAllocParams))"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x188);
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,iVar16,
                     "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, hDevice, pChannel->errNotifierIdPhys, hClass, &memAllocParams, sizeof(memAllocParams))"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x174,uVar33);
        }
      }
      else {
        nvCheckOkFailedNoLog
                  (4,iVar16,
                   "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, hDevice, hVirtMem, NV50_MEMORY_VIRTUAL, &memAllocParams, sizeof(memAllocParams))"
                   ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x142);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar16,
                 "pRmApi->AllocWithHandle(pRmApi, pChannel->hClient, hDevice, hPhysMem, hClass, &memAllocParams, sizeof(memAllocParams))"
                 ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x12e);
    }
  }
  else {
    nvAssertFailedNoLog("!rmGpuLockIsOwner()",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x114);
  }
  iVar16 = rmGpuLocksAcquire(0,0x2000);
  if (iVar16 != 0) {
    nvAssertFailedNoLog("Could not get back lock after allocating Push Buffer sema",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x33b);
    goto LAB_0039d524;
  }
  uVar24 = CONCAT44(uVar7,uVar26);
  uVar15 = (uint)(cVar14 != '\0') << 4;
  portMemSet(&local_268,0,0x40);
  local_268 = CONCAT44(uVar3,uVar2);
  local_260 = CONCAT44(uVar4,uVar7);
  local_250 = (ulong)uVar5;
  local_248 = uVar15;
  (**(code **)(local_290 + 0x98))(local_290,&local_268);
  *(undefined8 *)(param_3 + 0x2e) = local_238;
  portMemSet(&local_268,0,0x40);
  local_250 = (ulong)(uint)param_3[0x11];
  local_268 = CONCAT44(uVar3,uVar2);
  local_260 = uVar10;
  local_248 = uVar15 | 0x20;
  (**(code **)(local_290 + 0x98))(local_290,&local_268);
  *(undefined8 *)(param_3 + 0x32) = local_238;
  lVar19 = rmapiGetInterface(4);
  bVar31 = false;
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    cVar14 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
    bVar31 = cVar14 != '\0';
  }
  iVar16 = 0x31;
  if (param_3[0x54] != 3) {
    iVar16 = param_3[0x60] + 9;
  }
  cVar14 = *(char *)((long)param_3 + 0x195);
  portMemSet(&local_1a8,0,0x170);
  local_1a0[0] = (ulong)(uint)param_3[0x10] + *(long *)(param_3 + 0x2e);
  local_1a0[1] = CONCAT44((-(uint)(cVar14 == '\0') & 0xfffffffc) + 0x800004,param_3[0xf]);
  local_190 = (ulong)(uint)param_3[0xb] << 0x20;
  local_1a8 = uVar24;
  if ((bVar31) && (*(long *)(param_3 + 0x62) != 0)) {
    uVar33 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar17 = serverGetClientUnderLock(g_resServ,uVar2,&local_278);
    if (iVar17 == 0) {
      iVar17 = deviceGetByHandle_IMPL(local_278,uVar3,&local_270);
      if (iVar17 == 0) {
        iVar17 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar33,local_270,local_228);
        if (iVar17 == 0) {
          local_228 = kmigmgrMakeGIReference_IMPL(local_228._0_8_);
          iVar17 = kmigmgrGetGlobalToLocalEngineType_IMPL
                             (param_1,uVar33,local_228._0_8_,local_228._8_8_,iVar16,&local_27c);
          if (iVar17 == 0) {
            local_128 = gpuGetNv2080EngineType_IMPL(local_27c);
            goto LAB_0039d059;
          }
          nvAssertOkFailedNoLog
                    (iVar17,
                     "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, engineType, &localCe)"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x4ec);
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar17,
                     "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                     "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x4e8);
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar17,"deviceGetByHandle(pClient, hDeviceId, &pDevice)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x4e5);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar17,"serverGetClientUnderLock(&g_resServ, hClientId, &pClient)",
                 "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x4e2);
    }
  }
  else {
    local_128 = gpuGetNv2080EngineType_IMPL(iVar16);
LAB_0039d059:
    uVar33 = gpuGetKernelFifoShared_IMPL(param_1);
    iVar16 = kfifoGetChannelClassId_IMPL(param_1,uVar33);
    if (iVar16 == 0) {
      iVar17 = 0xffff;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x4fa,
                   "_memUtilsAllocateChannel",4,"NVRM: Unable to determine CE\'s channel class.\n");
    }
    else {
      rmGpuLocksRelease(0,0);
      if (*(char *)(param_3 + 0x5c) == '\0') {
LAB_0039d08e:
        iVar17 = (**(code **)(lVar19 + 8))(lVar19,uVar2,uVar3,local_2a0,iVar16,&local_1a8,0x170);
        if (iVar17 == 0) {
          iVar17 = rmGpuLocksAcquire(0,0x2000);
          if (iVar17 != 0) {
            nvAssertOkFailedNoLog
                      (iVar17,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM)",
                       "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x520);
            goto LAB_0039e050;
          }
          if (*(char *)(param_3 + 0x5c) == '\0') {
            local_1a8 = local_1a8 & 0xffffffff00000000;
            lVar19 = rmapiGetInterface(4);
            lVar20 = gpuGetKernelFifoShared_IMPL(param_1);
            (**(code **)(lVar20 + 0x2a0))(lVar20,&local_1a8,0,*(code **)(lVar20 + 0x2a0));
            puVar32 = param_3 + 0x3e;
            if (*(char *)(param_3 + 0x5c) != '\0') {
              local_2a0 = param_3[0x5b];
            }
            iVar16 = (**(code **)(lVar19 + 0x70))
                               (lVar19,uVar2,uVar3,local_2a0,0,local_1a8 & 0xffffffff,puVar32,0);
            if (iVar16 == 0) goto LAB_0039d13d;
            nvCheckOkFailedNoLog
                      (4,iVar16,
                       "pRmApi->MapToCpu(pRmApi, hClientId, hDeviceId, pChannel->bClientUserd ? pChannel->hUserD : hChannelId, 0, userdSize, (void **)&pChannel->pControlGPFifo, 0)"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x464,puVar32);
            iVar17 = iVar16;
          }
          else {
            lVar19 = memmgrMemUtilsGetMemDescFromHandle_IMPL(param_2,uVar2,param_3[0x5b]);
            *(long *)(param_3 + 0x34) = lVar19;
            if (lVar19 != 0) {
              if (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad0c) == '\0') {
                lVar19 = memmgrMemDescBeginTransfer_IMPL
                                   (param_2,lVar19,(ulong)(*(char *)(param_3 + 0x65) != '\0') << 5);
                *(long *)(param_3 + 0x3e) = lVar19;
                if (lVar19 == 0) {
                  nvAssertFailedNoLog("pChannel->pControlGPFifo != NULL",
                                      "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x45b)
                  ;
                  goto LAB_0039d91f;
                }
              }
              else {
                *(undefined8 *)(param_3 + 0x3e) = 0;
              }
LAB_0039d13d:
              lVar19 = memmgrMemUtilsGetMemDescFromHandle_IMPL(param_2,param_3[0x2b],uVar4);
              *(long *)(param_3 + 0x36) = lVar19;
              if (lVar19 == 0) {
                nvAssertFailedNoLog("pChannel->pChannelBufferMemdesc != NULL",
                                    "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x371);
              }
              else {
                lVar19 = memmgrMemUtilsGetMemDescFromHandle_IMPL(param_2,param_3[0x2b],uVar6);
                *(long *)(param_3 + 0x38) = lVar19;
                if (lVar19 == 0) {
                  nvAssertFailedNoLog("pChannel->pErrNotifierMemdesc != NULL",
                                      "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x376)
                  ;
                }
                else {
                  if (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad0c) == '\0') {
                    lVar19 = memmgrMemDescBeginTransfer_IMPL
                                       (param_2,*(undefined8 *)(param_3 + 0x36),
                                        (ulong)(cVar12 != '\0') << 5);
                    *(long *)(param_3 + 0x3a) = lVar19;
                    if (lVar19 == 0) {
                      nvAssertFailedNoLog("pChannel->pbCpuVA != NULL",
                                          "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
                                          0x397);
                      goto LAB_0039d524;
                    }
                    lVar19 = memmgrMemDescBeginTransfer_IMPL
                                       (param_2,*(undefined8 *)(param_3 + 0x38),
                                        (ulong)(cVar12 != '\0') << 5);
                    if (lVar19 == 0) {
                      nvAssertFailedNoLog("pErrNotifierCpuVA != NULL",
                                          "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
                                          0x39b);
                      goto LAB_0039d524;
                    }
                    portMemSet(*(undefined8 *)(param_3 + 0x3a),0,(ulong)uVar5);
                    lVar19 = lVar19 + 0x10;
                  }
                  else {
                    iVar17 = memmgrMemDescMemSet_IMPL(param_2,*(undefined8 *)(param_3 + 0x36),0,6);
                    if (iVar17 != 0) {
                      nvAssertFailedNoLog("rmStatus == NV_OK",
                                          "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
                                          0x37c);
                      goto LAB_0039d524;
                    }
                    *(undefined8 *)(param_3 + 0x3a) = 0;
                    lVar19 = 0;
                  }
                  *(long *)(param_3 + 0x50) = lVar19;
                  iVar17 = (**(code **)(param_2 + 0x308))(param_1,param_2,param_3);
                  if (iVar17 == 0) {
                    portMemFree(puVar18);
                    return 0;
                  }
                  nvCheckOkFailedNoLog
                            (4,iVar17,
                             "memmgrScrubMapDoorbellRegion_HAL(pGpu, pMemoryManager, pChannel)",
                             "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x3aa);
                }
              }
              goto LAB_0039d524;
            }
            nvAssertFailedNoLog("pChannel->pUserdMemdesc != NULL",
                                "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x44c);
LAB_0039d91f:
            iVar17 = 0xffff;
          }
          nvCheckOkFailedNoLog
                    (4,iVar17,
                     "_memUtilsMapUserd_GM107(pGpu, pMemoryManager, pChannel, hClient, hDevice, hChannel, bUseRmApiForBar1)"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x367);
          goto LAB_0039d524;
        }
        uVar33 = 0x515;
        pcVar28 = 
        "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, hChannelId, hClass, &channelGPFIFOAllocParams, sizeof(channelGPFIFOAllocParams))"
        ;
      }
      else {
        lVar20 = gpuGetKernelFifoShared_IMPL(param_1);
        lVar22 = rmapiGetInterface(4);
        cVar14 = rmGpuLockIsOwner();
        if (cVar14 == '\0') {
          portMemSet(local_228,0,0x80);
          local_228._0_4_ = 0xdeaf0006;
          (**(code **)(lVar20 + 0x2a0))(lVar20,local_1e8,0);
          local_228._0_8_ = local_228._0_8_ & 0xffffffff;
          local_1b8 = 4;
          if (((*(ushort *)(param_1 + 0x4926) & 3) == 3) ||
             ((*(ushort *)(param_1 + 0x4926) & 3) == 0)) {
            local_228._8_8_ = local_228._8_8_ | 0x10000;
            local_210 = (ulong)local_210._4_4_ << 0x20;
            if (*(long *)(param_1 + 0x1bc0) == 0) {
              uVar15 = 0x4000;
LAB_0039e211:
              local_210 = CONCAT44(local_210._4_4_,uVar15);
            }
            else {
              cVar14 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
              if (cVar14 == '\0') {
                uVar15 = (uint)local_210 | 0x4000;
                goto LAB_0039e211;
              }
            }
            uVar26 = 0x40;
          }
          else {
            local_210 = CONCAT44(local_210._4_4_,0x2000000);
            uVar26 = 0x3e;
          }
          cVar14 = gpuIsApmFeatureEnabled_IMPL(param_1);
          if ((cVar14 != '\0') || (((uint)local_210 & 0x6000000) == 0x2000000)) {
            local_210 = local_210 | 0x400000000000000;
          }
          iVar17 = (**(code **)(lVar22 + 8))(lVar22,uVar2,uVar3,param_3[0x5b],uVar26,local_228,0x80)
          ;
          if (iVar17 == 0) {
            local_188 = param_3[0x5b];
            local_168 = 0;
            goto LAB_0039d08e;
          }
          nvAssertOkFailedNoLog
                    (iVar17,
                     "pRmApi->AllocWithHandle(pRmApi, hClientId, hDeviceId, pChannel->hUserD, userdMemClass, &memAllocParams, sizeof(memAllocParams))"
                     ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x4a9);
        }
        else {
          iVar17 = 0x2f;
          nvAssertFailedNoLog("!rmGpuLockIsOwner()",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x47d);
        }
        uVar33 = 0x502;
        pcVar28 = "_memUtilsAllocateUserD(pGpu, pMemoryManager, hClientId, hDeviceId, pChannel)";
      }
      nvAssertOkFailedNoLog
                (iVar17,pcVar28,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",uVar33);
      iVar16 = rmGpuLocksAcquire(0,0x2000);
      if (iVar16 != 0) {
        nvAssertOkFailedNoLog
                  (iVar16,"rmGpuLocksAcquire(GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_MEM)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x520);
      }
    }
  }
LAB_0039e050:
  nvCheckOkFailedNoLog
            (4,iVar17,
             "_memUtilsAllocateChannel(pGpu, pMemoryManager, hClient, hDevice, hChannel, hErrNotifierVirt, hPushBuffer, pChannel)"
             ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x359);
LAB_0039d524:
  if (*(char *)(param_3 + 0x2c) == '\0') {
    (**(code **)(local_290 + 0x18))(local_290,param_3[0x2b],param_3[0x2b]);
  }
  portMemFree(puVar18);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x3b9,
               "memmgrMemUtilsChannelInitialize_GM107",1,"NVRM: end  NV_STATUS=0x%08x\n",iVar17);
  return iVar17;
}


// ===== 0039e670 memmgrMemUtilsCreateMemoryAlias_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrMemUtilsCreateMemoryAlias_GM107(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  lVar2 = rmapiGetInterface(4);
  local_40 = 0;
  local_38 = 0;
  local_30 = 0;
  (**(code **)(param_2 + 0x2e8))(param_2,&local_38);
  iVar1 = (**(code **)(lVar2 + 8))(lVar2,param_3[0x2b],*param_3,param_3[0xc],0xc2,&local_40,0x18);
  if (iVar1 == 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x3e4,
                 "memmgrMemUtilsCreateMemoryAlias_GM107",1,
                 "NVRM: Allocating FbAlias: %x for size: %llx, kind: %x\n",param_3[0xc],
                 *(undefined8 *)(param_3 + 0x20));
    return 0;
  }
  nvCheckOkFailedNoLog
            (3,iVar1,"Aliasing FbListMem","src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",
             0x3e0);
  return iVar1;
}


// ===== 0039e770 memmgrMemUtilsCopyEngineInitialize_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int memmgrMemUtilsCopyEngineInitialize_GM107(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 local_40;
  
  lVar7 = rmapiGetInterface(4);
  uVar1 = *(undefined4 *)(param_3 + 0x18);
  local_40 = 0;
  uVar2 = *(undefined4 *)(param_3 + 0xac);
  uVar3 = *(undefined4 *)(param_3 + 8);
  lVar8 = rmapiGetInterface(4);
  uVar4 = *(uint *)(param_3 + 0x180);
  local_40._4_4_ = uVar4 + 0x2a;
  if (uVar4 < 10) {
    local_40._4_4_ = uVar4 + 9;
  }
  local_40._0_4_ = 1;
  (**(code **)(param_2 + 0x1b8))(param_1,param_2,param_3 + 0x11c);
  uVar5 = gpuGetRmEngineType_IMPL(local_40._4_4_);
  *(undefined4 *)(param_3 + 0x70) = uVar5;
  if (*(int *)(param_3 + 0x11c) == 0) {
    iVar6 = 0xffff;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x426,
                 "_memUtilsAllocCe_GM107",4,"NVRM: Unable to determine CE\'s engine class.\n");
  }
  else {
    iVar6 = (**(code **)(lVar8 + 8))(lVar8,uVar2,uVar3,uVar1,*(int *)(param_3 + 0x11c),&local_40,8);
    if (iVar6 == 0) {
      iVar6 = memmgrMemUtilsChannelSchedulingSetup_IMPL(param_1,param_2,param_3);
      if (iVar6 == 0) {
        return 0;
      }
      nvCheckOkFailedNoLog
                (4,iVar6,"memmgrMemUtilsChannelSchedulingSetup(pGpu, pMemoryManager, pChannel)",
                 "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x403);
      goto LAB_0039e8bd;
    }
    nvCheckOkFailedNoLog
              (4,iVar6,
               "pRmApi->AllocWithHandle(pRmApi, hClientId, hChannelId, hCopyObjectId, pChannel->hTdCopyClass, &createParams, sizeof(createParams))"
               ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x42a);
  }
  nvCheckOkFailedNoLog
            (4,iVar6,
             "_memUtilsAllocCe_GM107(pGpu, pMemoryManager, pChannel, pChannel->hClient, pChannel->deviceId, pChannel->channelId, pChannel->engineObjectId)"
             ,"src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x3f7);
LAB_0039e8bd:
  (**(code **)(lVar7 + 0x18))(lVar7,*(undefined4 *)(param_3 + 0xac),*(undefined4 *)(param_3 + 0xac))
  ;
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x40c,
               "memmgrMemUtilsCopyEngineInitialize_GM107",1,"NVRM: end  NV_STATUS=0x%08x\n",iVar6);
  return iVar6;
}


// ===== 0039e960 memmgrMemUtilsGetCopyEngineClass_GM107 =====

undefined8
memmgrMemUtilsGetCopyEngineClass_GM107(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint local_2c [3];
  
  uVar5 = 0;
  do {
    iVar2 = gpuGetClassList_IMPL(param_1,local_2c,0,uVar5 | 0x793ceb00);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"gpuGetClassList(pGpu, &numClasses, NULL, ENG_CE(eng))",
                 "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x8ab);
      return 0;
    }
  } while ((local_2c[0] == 0) && (uVar5 = uVar5 + 1, uVar5 != 0x14));
  puVar3 = (uint *)portMemAllocNonPaged((ulong)local_2c[0] << 2);
  if (puVar3 == (uint *)0x0) {
    nvAssertFailedNoLog("(pClassList != NULL)",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x8b7);
    return 0;
  }
  iVar2 = gpuGetClassList_IMPL(param_1,local_2c,puVar3,uVar5 | 0x793ceb00);
  if ((iVar2 == 0) && (local_2c[0] != 0)) {
    puVar4 = puVar3;
    uVar5 = 0;
    do {
      uVar6 = uVar5;
      uVar1 = *puVar4;
      uVar5 = uVar6;
      if (uVar6 < uVar1) {
        uVar5 = uVar1;
      }
      puVar4 = puVar4 + 1;
    } while (puVar4 != puVar3 + local_2c[0]);
    if (uVar6 != 0 || uVar1 != 0) goto LAB_0039ea36;
  }
  uVar5 = 0;
  nvAssertFailedNoLog("class != 0","src/kernel/gpu/mem_mgr/arch/maxwell/mem_utils_gm107.c",0x8c1);
LAB_0039ea36:
  portMemFree(puVar3);
  *param_3 = uVar5;
  return 0;
}


// ===== 0039eaa0 _dmaGetMaxVAPageSize.constprop.0 =====

undefined8
_dmaGetMaxVAPageSize_constprop_0
          (ulong param_1,long param_2,ulong param_3,long param_4,ulong param_5,ulong param_6,
          ulong *param_7,undefined8 param_8)

{
  long lVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long local_60;
  ulong local_58 [5];
  
  local_58[1] = 0x200000;
  local_58[2] = param_8;
  local_58[3] = 0x1000;
  if (param_2 == 0) {
    local_58[0] = 0;
    uVar6 = 0xffffffffffffffff;
    local_60 = -1;
  }
  else {
    virtmemGetAddressAndSize_IMPL(param_2,local_58,&local_60);
    uVar6 = (local_58[0] - 1) + local_60;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xd5,
               "_dmaGetMaxVAPageSize",0,
               "NVRM: targetSpaceBase: 0x%llx, targetSpaceLength: 0x%llx, targetSpaceLimit: 0x%llx\n"
               ,local_58[0],local_60,uVar6);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xd6,
               "_dmaGetMaxVAPageSize",0,
               "NVRM: memDescribedStartAddr: 0x%llx, memDescribedSize: 0x%llx\n",param_5,param_6);
  puVar3 = local_58 + 1;
  do {
    uVar2 = *puVar3;
    uVar4 = -uVar2;
    if (local_58[0] <= (uVar4 & param_1)) {
      lVar1 = (uVar2 - 1) + param_4;
      uVar5 = uVar2 - 1 & param_3;
      if (((((uVar4 & param_1) + uVar5 + lVar1 & uVar4) - 1 <= uVar6) &&
          ((lVar1 + uVar5 & uVar4) <= param_6)) && (param_5 <= param_3 - uVar5)) {
        *param_7 = uVar2;
        return 0;
      }
    }
    puVar3 = puVar3 + 1;
    if (local_58 + 4 == puVar3) {
      return 0x40;
    }
  } while( true );
}


// ===== 0039ec20 _gmmuWalkCBMapNextEntries_Direct.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _gmmuWalkCBMapNextEntries_Direct_isra_0
               (long param_1,undefined8 *param_2,uint param_3,uint param_4,int *param_5)

{
  long *plVar1;
  byte bVar2;
  long *plVar3;
  long lVar4;
  byte *pbVar5;
  uint *puVar6;
  long lVar7;
  ulong uVar8;
  char cVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  ulong *puVar15;
  long lVar16;
  uint uVar17;
  ulong uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  bool bVar22;
  ulong local_48 [3];
  
  plVar3 = (long *)param_2[1];
  lVar4 = plVar3[0x10];
  if (lVar4 == 0) {
    nvAssertFailedNoLog("pMap != NULL",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x6fa);
    return;
  }
  if (param_4 < param_3) {
LAB_0039ee06:
    *param_5 = (param_4 + 1) - param_3;
    return;
  }
  iVar20 = 0;
  pbVar5 = (byte *)*param_2;
  uVar10 = 1L << (*pbVar5 & 0x3f);
  uVar21 = param_3;
LAB_0039eca0:
  bVar2 = pbVar5[2];
  uVar19 = (uint)bVar2 * iVar20;
  if ((char)plVar3[0xf] != '\0') {
    portMemCopy(local_48,bVar2,(ulong)uVar19 + lVar4,bVar2);
    if (*(char *)((long)plVar3 + 0x7b) != '\0') goto LAB_0039ee5a;
LAB_0039ecd3:
    if (*(char *)((long)plVar3 + 0x79) != '\0') {
      if (*(uint *)(plVar3 + 3) < *(uint *)(plVar3[2] + 0xc)) {
        lVar11 = dmaPageArrayGetPhysAddr();
        plVar3[5] = (ulong)*(uint *)((long)plVar3 + 0x1c) + lVar11 & -uVar10;
        if (*(char *)((long)plVar3 + 0x7a) != '\0') goto LAB_0039ed0e;
        goto LAB_0039ed80;
      }
      if ((*(uint *)(plVar3[2] + 0xc) != 1) || (*(uint *)(plVar3 + 3) == 0)) {
        nvAssertFailedNoLog("(pIter->pPageArray->count == 1) && (currIdxMod > 0)",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x72f);
        return;
      }
      plVar3[5] = plVar3[5] + uVar10;
      if (*(char *)((long)plVar3 + 0x7a) != '\0') {
LAB_0039ed0e:
        puVar6 = (uint *)*plVar3;
        lVar11 = *(long *)(param_1 + 8);
        lVar7 = *(long *)(lVar11 + 0x1b78);
        if (1 < *(uint *)(lVar7 + 0x858)) {
          lVar16 = *(long *)(puVar6 + 8);
          if (*(byte *)(lVar16 + 0x24) != 0) {
            lVar12 = 0;
            do {
              if ((*(char *)(*(long *)(lVar16 + 0x28) + lVar12 * 2) != '\0') &&
                 ((*(uint *)((long)local_48 + (ulong)*(ushort *)(lVar16 + 0x22)) &
                  *(uint *)(lVar16 + 0x18)) >> ((byte)*(undefined2 *)(lVar16 + 0x20) & 0x1f) ==
                  (uint)*(byte *)(*(long *)(lVar16 + 0x28) + 1 + lVar12 * 2))) {
                if ((int)lVar12 == 1) {
                  puVar15 = (ulong *)(lVar7 + 0x860);
                  uVar13 = 0;
                  goto LAB_0039f1b0;
                }
                break;
              }
              lVar12 = lVar12 + 1;
            } while ((uint)lVar12 < (uint)*(byte *)(lVar16 + 0x24));
          }
          if ((char)plVar3[0xb] != '\0') goto LAB_0039ed3b;
          goto LAB_0039ef17;
        }
        if ((char)plVar3[0xb] == '\0') {
          lVar16 = *(long *)(puVar6 + 8);
          goto LAB_0039ef17;
        }
        goto LAB_0039ed3b;
      }
      goto LAB_0039ed86;
    }
    if (*(char *)((long)plVar3 + 0x7a) != '\0') goto LAB_0039ed0e;
    goto LAB_0039ed91;
  }
  portMemCopy(local_48,bVar2,plVar3 + 0xc,bVar2);
  if (*(char *)((long)plVar3 + 0x7b) == '\0') goto LAB_0039ecd3;
LAB_0039ee5a:
  portMemCopy((ulong)uVar19 + lVar4,pbVar5[2],local_48,pbVar5[2]);
  goto LAB_0039ede0;
  while( true ) {
    uVar17 = (int)uVar13 + 1;
    uVar13 = (ulong)uVar17;
    puVar15 = puVar15 + 5;
    if (*(uint *)(lVar7 + 0x858) == uVar17) break;
LAB_0039f1b0:
    if ((*puVar15 <= (ulong)plVar3[5]) && ((ulong)plVar3[5] <= puVar15[1])) {
      bVar22 = *(char *)(lVar7 + 0x880 + uVar13 * 0x28) != '\0';
      goto LAB_0039f1d0;
    }
  }
  bVar22 = true;
LAB_0039f1d0:
  if (((char)plVar3[0xb] == '\0') || (!bVar22)) {
LAB_0039ef17:
    *(uint *)((long)local_48 + (ulong)*(ushort *)(lVar16 + 0x186)) =
         *(int *)((long)plVar3 + 0x54) << ((byte)*(undefined2 *)(lVar16 + 0x184) & 0x1f) |
         *(uint *)((long)local_48 + (ulong)*(ushort *)(lVar16 + 0x186)) & *(uint *)(lVar16 + 0x180);
    if (*(uint *)*plVar3 < 3) {
      lVar11 = *(long *)((uint *)*plVar3 + 8);
      puVar6 = (uint *)((long)local_48 + (ulong)*(ushort *)(lVar11 + 0x192));
      *puVar6 = *puVar6 & *(uint *)(lVar11 + 0x18c);
      lVar11 = *(long *)(*plVar3 + 0x20);
      if (*(int *)(lVar11 + 0x194) != 0) {
        puVar6 = (uint *)((long)local_48 + (ulong)*(ushort *)(lVar11 + 0x19e));
        *puVar6 = *puVar6 & *(uint *)(lVar11 + 0x198);
      }
    }
  }
  else {
LAB_0039ed3b:
    lVar16 = plVar3[7];
    if ((*(char *)(lVar11 + 0x4913) == '\0') && (*puVar6 < 3)) {
      lVar12 = *(long *)(lVar11 + 0x1b70);
      lVar14 = kmemsysGetStaticConfig_IMPL(lVar11);
      plVar1 = plVar3 + 7;
      if ((((*(char *)(lVar14 + 2) == '\0') || (*(char *)(lVar12 + 0x2a8) == '\0')) ||
          (cVar9 = (**(code **)(lVar7 + 0x2a8))(lVar7,10,(int)plVar3[7]), cVar9 != '\0')) ||
         (cVar9 = (**(code **)(lVar12 + 0x1e0))
                            (lVar11,lVar12,(ulong)*(uint *)(plVar3 + 3) * param_2[3] + plVar3[4],
                             uVar10), cVar9 != '\0')) {
        kgmmuFieldSetKindCompTags_IMPL
                  (*(undefined8 *)(lVar11 + 0x1b98),*plVar3,pbVar5,plVar1,plVar3[5],
                   (ulong)*(uint *)(plVar3 + 3) * param_2[3] + plVar3[4],uVar21,local_48);
      }
      else {
        (**(code **)(lVar7 + 0x378))(lVar7,plVar1);
        kgmmuFieldSetKindCompTags_IMPL
                  (*(undefined8 *)(lVar11 + 0x1b98),*plVar3,pbVar5,plVar1,plVar3[5],
                   (ulong)*(uint *)(plVar3 + 3) * param_2[3] + plVar3[4],uVar21,local_48);
        *(int *)(plVar3 + 7) = (int)lVar16;
      }
    }
    else {
      lVar11 = *(long *)(puVar6 + 8);
      *(uint *)((long)local_48 + (ulong)*(ushort *)(lVar11 + 0x186)) =
           *(uint *)((long)local_48 + (ulong)*(ushort *)(lVar11 + 0x186)) &
           *(uint *)(lVar11 + 0x180) | (int)lVar16 << ((byte)*(undefined2 *)(lVar11 + 0x184) & 0x1f)
      ;
    }
  }
LAB_0039ed80:
  if (*(char *)((long)plVar3 + 0x79) != '\0') {
LAB_0039ed86:
    if (plVar3[0xe] != 0) {
      uVar13 = kgmmuEncodePhysAddr_IMPL
                         (*(undefined8 *)(*(long *)(param_1 + 8) + 0x1b98),(int)plVar3[1],plVar3[5],
                          plVar3[6]);
      puVar6 = (uint *)plVar3[0xe];
      if (*puVar6 != 0) {
        uVar13 = uVar13 >> ((byte)puVar6[0xe] & 0x3f);
        uVar18 = 0;
        do {
          uVar17 = (int)uVar18 + 1;
          uVar8 = *(ulong *)((long)local_48 + (ulong)puVar6[uVar18 * 6 + 6]);
          *(ulong *)((long)local_48 + (ulong)puVar6[uVar18 * 6 + 6]) =
               (uVar13 << ((byte)puVar6[uVar18 * 6 + 5] & 0x3f) ^ uVar8) &
               *(ulong *)(puVar6 + uVar18 * 6 + 2) ^ uVar8;
          uVar13 = uVar13 >> ((byte)puVar6[uVar18 * 6 + 4] & 0x3f);
          uVar18 = (ulong)uVar17;
        } while (uVar17 < *puVar6);
      }
    }
  }
LAB_0039ed91:
  portMemCopy((ulong)uVar19 + lVar4,pbVar5[2],local_48,pbVar5[2]);
  if ((*(char *)(g_pSys + 400) == '\0') || ((ulong)param_2[3] <= uVar10)) {
    *(undefined4 *)((long)plVar3 + 0x1c) = 0;
    *(int *)(plVar3 + 3) = (int)plVar3[3] + (int)(uVar10 / (ulong)param_2[3]);
  }
  else {
    uVar19 = (int)uVar10 + *(int *)((long)plVar3 + 0x1c);
    *(uint *)((long)plVar3 + 0x1c) = uVar19;
    if ((ulong)param_2[3] <= (ulong)uVar19) {
      *(int *)(plVar3 + 3) = (int)plVar3[3] + 1;
      *(undefined4 *)((long)plVar3 + 0x1c) = 0;
    }
  }
LAB_0039ede0:
  uVar21 = uVar21 + 1;
  iVar20 = iVar20 + 1;
  if (param_4 < uVar21) goto LAB_0039ee06;
  goto LAB_0039eca0;
}


// ===== 0039f260 _gmmuWalkCBMapNextEntries_RmAperture =====

void _gmmuWalkCBMapNextEntries_RmAperture
               (long *param_1,long *param_2,undefined8 param_3,int param_4,int param_5,
               undefined8 param_6)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar5 = param_1[1];
  lVar1 = *param_2;
  uVar2 = *(undefined8 *)(lVar5 + 0x1b78);
  lVar3 = *(long *)(lVar5 + 0x1b98);
  local_58 = 0;
  lVar4 = param_2[1];
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  lVar6 = 0;
  if (*(long *)(lVar5 + 0x4a18) != 0) {
    lVar5 = __nvoc_dynamicCast(*(long *)(lVar5 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
    lVar6 = 0;
    if (lVar5 != 0) {
      lVar6 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 0x98),__nvoc_class_def_OBJGVASPACE);
    }
  }
  uVar7 = memdescGetPhysAddr(param_3,1,0);
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x7d5,
               "_gmmuWalkCBMapNextEntries_RmAperture",1,
               "NVRM: [GPU%u]: PA 0x%llX, Entries 0x%X-0x%X\n",*(undefined4 *)(param_1[1] + 0x7a4),
               uVar7,param_4,param_5);
  if ((*(char *)(*param_1 + 0xb8) < '\0') || (iVar8 = 6, *param_1 == lVar6)) {
    iVar8 = (-(uint)(*(char *)(lVar3 + 0x54c) == '\0') & 0xfffff000) + 0x1006;
  }
  local_50 = (ulong)((uint)*(byte *)(lVar1 + 2) * param_4);
  iVar9 = ((param_5 + 1) - param_4) * (uint)*(byte *)(lVar1 + 2);
  local_58 = param_3;
  lVar5 = memmgrMemBeginTransfer_IMPL(uVar2,&local_58,iVar9,iVar8);
  *(long *)(lVar4 + 0x80) = lVar5;
  if (lVar5 != 0) {
    _gmmuWalkCBMapNextEntries_Direct_isra_0(param_1,param_2,param_4,param_5,param_6);
    memmgrMemEndTransfer_IMPL(uVar2,&local_58,iVar9,iVar8);
    return;
  }
  nvAssertFailedNoLog("NULL != pIter->pMap",
                      "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x7e8);
  return;
}


// ===== 0039f450 dmaIsDefaultGpuUncached_GM107 =====

bool dmaIsDefaultGpuUncached_GM107(undefined8 param_1,long param_2,uint param_3,char param_4)

{
  int iVar1;
  
  if (param_3 == 2) {
LAB_0039f4a8:
    iVar1 = memdescGetGpuP2PCacheAttrib(param_2);
    return iVar1 == 1;
  }
  if (param_3 < 3) {
    if (param_3 == 1) {
      return false;
    }
  }
  else if (param_3 - 3 < 2) {
    if (param_4 == '\0') {
      return *(int *)(param_2 + 0x6c) == 1;
    }
    goto LAB_0039f4a8;
  }
  nvAssertFailedNoLog(&DAT_00d47b29,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c"
                      ,0x122);
  return false;
}


// ===== 0039f4b8 dmaAllocMapping_GM107.cold =====

void dmaAllocMapping_GM107_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0039f4d0 dmaAllocMapping_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dmaAllocMapping_GM107
              (long param_1,long param_2,long *param_3,long param_4,ulong *param_5,ulong param_6,
              uint param_7,long *param_8,undefined4 param_9)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  code *pcVar9;
  byte bVar10;
  char cVar11;
  undefined1 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  long lVar16;
  long lVar17;
  uint *puVar18;
  long lVar19;
  undefined8 uVar20;
  undefined8 *puVar21;
  undefined8 uVar22;
  long lVar23;
  long lVar24;
  long lVar25;
  long lVar26;
  ulong uVar27;
  ulong uVar28;
  undefined8 uVar29;
  long lVar30;
  uint uVar31;
  ulong uVar32;
  uint uVar33;
  bool bVar34;
  undefined1 auVar35 [16];
  uint local_b8;
  ulong local_90;
  long local_70;
  char local_55;
  int local_54;
  long local_50;
  long local_48;
  ulong local_40 [2];
  
  uVar28 = param_6 & 0xffffffff;
  lVar1 = *(long *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_1 + 0x1b70);
  lVar30 = *(long *)(param_1 + 0x1b98);
  lVar3 = *(long *)(&DAT_00001b90 + param_1);
  lVar19 = *(long *)(param_1 + 0x1bc0);
  lVar16 = __nvoc_dynamicCast(*(undefined8 *)(param_1 + 0x4a18),__nvoc_class_def_FABRIC_VASPACE);
  local_50 = param_4;
  lVar17 = kmemsysGetStaticConfig_IMPL(param_1,lVar2);
  puVar18 = (uint *)portMemAllocNonPaged(0x168);
  if (puVar18 == (uint *)0x0) {
    return 0x51;
  }
  portMemSet(puVar18,0,0x168);
  *(long *)(puVar18 + 0x2c) = param_1;
  puVar18[0x2e] = 0xffffffff;
  puVar18[0x46] = 1;
  puVar18[0x47] = 0;
  puVar18[0x48] = 0;
  puVar18[0x49] = 0;
  if (param_8 != (long *)0x0) {
    *(long *)(puVar18 + 0x4e) = param_8[2];
  }
  uVar20 = (**(code **)(*param_3 + 0xa0))(param_3);
  *(undefined8 *)(puVar18 + 0x3e) = uVar20;
  uVar27 = (**(code **)(*param_3 + 0x70))(param_3);
  uVar33 = (uint)param_6;
  *(bool *)((long)puVar18 + 0xbd) = (uVar27 & 0x800401) != 0;
  puVar18[0x1e] = (uint)(uVar28 >> 0x14) & 3;
  puVar18[0x21] = (uint)(param_6 >> 0x16) & 7;
  puVar18[0x22] = (uint)(uVar28 >> 0x1f);
  *(byte *)(puVar18 + 0x2f) = (byte)(param_6 >> 0x1d) & 1 ^ 1;
  bVar10 = (**(code **)(*param_3 + 0x70))(param_3);
  *(byte *)((long)puVar18 + 0xbe) = bVar10 >> 7;
  bVar34 = false;
  if (lVar19 != 0) {
    cVar11 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(param_1,lVar19);
    bVar34 = cVar11 != '\0';
  }
  *(bool *)((long)puVar18 + 0xbf) = bVar34;
  uVar31 = uVar33 & 3;
  puVar18[0x1f] = (uint)(uVar31 == 2);
  puVar18[0x20] = (uint)(uVar31 == 1) << 0x1b;
  puVar18[0x1d] = uVar33 * 2 & 0x20000000;
  iVar14 = *(int *)(param_4 + 0x7c);
  if (iVar14 != 1) {
    if (iVar14 == 2) {
      puVar18[0x12] = 1;
      iVar14 = *(int *)(param_4 + 0x78);
      goto joined_r0x0039f993;
    }
    if (iVar14 == 0) {
      uVar13 = (uint)(param_6 >> 4) & 1;
      goto LAB_0039f6d4;
    }
    nvAssertOkFailedNoLog
              (0x40,"status","src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x1bb)
    ;
    goto LAB_0039fa0d;
  }
  uVar13 = 0;
LAB_0039f6d4:
  puVar18[0x12] = uVar13;
  iVar14 = *(int *)(param_4 + 0x78);
joined_r0x0039f993:
  if (iVar14 == 1) {
    puVar18[0x13] = 0;
    if ((param_7 & 3) != 1) goto LAB_0039f70c;
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x1d5,
                 "dmaAllocMapping_GM107",1,
                 "NVRM: GPU cache snoop flag is disabled at allocation time, but the mapping is requested with cache snoop enabled.\n"
                );
    goto LAB_003a0786;
  }
  if (iVar14 == 2) {
    puVar18[0x13] = 1;
    if ((param_7 & 3) == 2) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x1ca,
                   "dmaAllocMapping_GM107",1,
                   "NVRM: GPU cache snoop flag is enabled at allocation time, but the mapping is requested with cache snoop disabled.\n"
                  );
      goto LAB_003a0786;
    }
  }
  else {
    if (iVar14 != 0) {
      nvAssertOkFailedNoLog
                (0x40,"status","src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",
                 0x1df);
      goto LAB_0039fa0d;
    }
    puVar18[0x13] = (uint)((param_7 & 3) == 1);
  }
LAB_0039f70c:
  uVar13 = (uint)(uVar28 >> 6) & 3;
  if (uVar13 == 2) {
    puVar18[0x26] = 0x40000000;
  }
  else if (uVar13 == 3) {
    puVar18[0x26] = 0;
  }
  else if ((uVar13 == 1) || (uVar31 == 1)) {
    puVar18[0x26] = 0x80000000;
  }
  else {
    puVar18[0x26] = (uint)(uVar31 == 2) << 0x1e;
  }
  lVar19 = param_3[10];
  iVar14 = vgpuIsCallingContextPlugin(param_1,&local_55);
  if (iVar14 != 0) {
    nvAssertOkFailedNoLog
              (iVar14,"vgpuIsCallingContextPlugin(pGpu, &bCallingContextPlugin)",
               "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x1fa);
    goto LAB_0039fa13;
  }
  local_70 = lVar19;
  if (local_55 != '\0') {
    iVar14 = memdescGetAddressSpace(param_4);
    local_70 = 2;
    if (iVar14 != 2) {
      local_70 = lVar19;
    }
  }
  iVar14 = vgpuGetCallingContextGfid(param_1,&local_54);
  if (iVar14 != 0) {
    nvAssertOkFailedNoLog
              (iVar14,"vgpuGetCallingContextGfid(pGpu, &gfid)",
               "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x1fe);
    goto LAB_0039fa13;
  }
  if ((lVar16 != 0) &&
     (iVar15 = fabricvaspaceGetGpaMemdesc_IMPL(lVar16,param_4,param_1,&local_50), iVar15 != 0)) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x205,
                 "dmaAllocMapping_GM107",4,
                 "NVRM: Failed to get the adjusted memdesc for the fabric memdesc\n");
    iVar14 = iVar15;
    goto LAB_0039fa13;
  }
  lVar19 = memdescGetMemDescFromGpu(local_50,param_1);
  *(long *)(puVar18 + 0x4c) = lVar19;
  *(ulong *)(puVar18 + 0x50) = (ulong)*(uint *)(lVar19 + 0x160);
  uVar20 = memdescGetPageSize(lVar19,local_70);
  *(undefined8 *)(puVar18 + 0x54) = uVar20;
  uVar12 = memdescGetContiguity(*(undefined8 *)(puVar18 + 0x4c),local_70);
  uVar31 = (uint)(param_6 >> 8);
  *(undefined1 *)(puVar18 + 0x40) = uVar12;
  uVar13 = uVar31 & 0xf;
  if (uVar13 == 3) {
LAB_0039f835:
    if (*(char *)(*(long *)(param_1 + 0x1b78) + 0x483) == '\0') {
      lVar19 = memdescGetPageSize(*(undefined8 *)(puVar18 + 0x4c),local_70);
      *(long *)(puVar18 + 10) = lVar19;
      uVar27 = memdescGetPhysAddr(*(undefined8 *)(puVar18 + 0x4c),local_70,0);
      uVar28 = *param_5;
      if ((((uVar28 == (-lVar19 & uVar28)) ||
           ((lVar19 - 1U & uVar27) == uVar28 - (-lVar19 & uVar28))) || ((char)puVar18[0x2f] != '\0')
          ) || (param_8 == (long *)0x0)) {
        uVar28 = *(ulong *)(puVar18 + 10);
      }
      else {
        if (param_8[1] == 0) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)invalidInstructionException();
          (*pcVar9)();
        }
        plVar8 = *(long **)(param_8[1] + 0x248);
        (**(code **)(*plVar8 + 0x1e8))(plVar8,local_40);
        uVar27 = memdescGetPageSize(local_40[0],3);
        uVar28 = *(ulong *)(puVar18 + 0x54);
        if (uVar27 < uVar28) {
          uVar28 = memdescGetPageSize(local_40[0],3);
        }
        *(ulong *)(puVar18 + 10) = uVar28;
        if (uVar28 == 0) {
          nvAssertFailedNoLog("pLocals->pageSize != 0",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x284
                             );
          goto LAB_0039fa13;
        }
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x285,
                     "dmaAllocMapping_GM107",1,"NVRM: Use preallocated VA\'s page size(0x%llx)\n");
        uVar28 = *(ulong *)(puVar18 + 10);
      }
    }
    else {
      if ((param_6 & 0x8000) == 0) {
        if (param_8 == (long *)0x0) {
          if ((char)puVar18[0x2f] == '\0') goto LAB_0039fb48;
LAB_0039f871:
          local_40[0] = 0;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x260,
                       "dmaAllocMapping_GM107",0,
                       "NVRM: Choosing default map pagesize based on the map call allocating VA for the mapping.\n"
                      );
          puVar21 = *(undefined8 **)(puVar18 + 0x4c);
          uVar20 = *(undefined8 *)(puVar18 + 0x3e);
          uVar29 = puVar21[7];
          puVar21 = (undefined8 *)memdescGetPteArrayForGpu(puVar21,*puVar21,local_70);
          uVar4 = *puVar21;
          uVar5 = *(undefined8 *)(*(long *)(puVar18 + 0x4c) + 0x30);
          uVar22 = memdescGetPhysAddr(*(long *)(puVar18 + 0x4c),local_70,0);
          iVar15 = _dmaGetMaxVAPageSize_constprop_0
                             (*param_5,0,uVar22,uVar5,uVar4,uVar29,local_40,uVar20);
          if (iVar15 != 0) {
            nvAssertOkFailedNoLog
                      (0x40,
                       "_dmaGetMaxVAPageSize(*pVaddr, NULL, memdescGetPhysAddr(pLocals->pTempMemDesc, addressTranslation, 0), memdescGetSize(pLocals->pTempMemDesc), memdescGetPteArray(pLocals->pTempMemDesc, addressTranslation)[0], pLocals->pTempMemDesc->ActualSize, &vaMaxPageSize, pLocals->vaspaceBigPageSize)"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x263);
            goto LAB_0039fa0d;
          }
        }
        else {
          if ((char)puVar18[0x2f] != '\0') goto LAB_0039f871;
          local_40[0] = 0;
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x246,
                       "dmaAllocMapping_GM107",0,
                       "NVRM: Choosing default map pagesize based on client provided VA range.\n");
          puVar21 = *(undefined8 **)(puVar18 + 0x4c);
          uVar20 = *(undefined8 *)(puVar18 + 0x3e);
          uVar29 = puVar21[7];
          puVar21 = (undefined8 *)memdescGetPteArrayForGpu(puVar21,*puVar21,local_70);
          uVar4 = *puVar21;
          uVar5 = *(undefined8 *)(*(long *)(puVar18 + 0x4c) + 0x30);
          uVar22 = memdescGetPhysAddr(*(long *)(puVar18 + 0x4c),local_70,0);
          iVar15 = _dmaGetMaxVAPageSize_constprop_0
                             (*param_5,param_8[1],uVar22,uVar5,uVar4,uVar29,local_40,uVar20);
          if (iVar15 != 0) {
            nvAssertOkFailedNoLog
                      (0x40,
                       "_dmaGetMaxVAPageSize(*pVaddr, pCliMapInfo->pVirtualMemory, memdescGetPhysAddr(pLocals->pTempMemDesc, addressTranslation, 0), memdescGetSize(pLocals->pTempMemDesc), memdescGetPteArray(pLocals->pTempMemDesc, addressTranslation)[0], pLocals->pTempMemDesc->ActualSize, &vaMaxPageSize, pLocals->vaspaceBigPageSize)"
                       ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x248);
            goto LAB_0039fa0d;
          }
        }
        uVar28 = *(ulong *)(puVar18 + 0x54);
        if (local_40[0] < *(ulong *)(puVar18 + 0x54)) {
          uVar28 = local_40[0];
        }
      }
      else {
LAB_0039fb48:
        uVar27 = *param_5;
        lVar23 = memdescGetPhysAddr(*(undefined8 *)(puVar18 + 0x4c),local_70,0);
        uVar13 = *(uint *)(*(long *)(puVar18 + 0x4c) + 0x60);
        lVar24 = memdescGetPhysAddr(*(long *)(puVar18 + 0x4c),local_70,0);
        lVar19 = *(long *)(*(long *)(puVar18 + 0x4c) + 0x30);
        lVar25 = memdescGetPhysAddr(*(long *)(puVar18 + 0x4c),local_70,0);
        lVar6 = *(long *)(*(long *)(puVar18 + 0x4c) + 0x30);
        lVar26 = memdescGetPhysAddr(*(long *)(puVar18 + 0x4c),local_70,0);
        lVar7 = *(long *)(*(long *)(puVar18 + 0x4c) + 0x30);
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x227,
                     "dmaAllocMapping_GM107",0,
                     "NVRM: Choosing default map pagesize through fixed offset path.\n");
        uVar32 = lVar23 - (ulong)uVar13 |
                 (lVar25 + ((lVar6 + -0x1000) - lVar7)) - lVar26 & lVar19 + 0xfff + lVar24;
        if ((uVar27 & 0x1ff000) == 0 && (uVar32 & 0x1fffff) == 0) goto LAB_003a0558;
        uVar28 = *(ulong *)(puVar18 + 0x3e);
        if (((uVar27 & 0xfffffffffffff000 | uVar32) & uVar28 - 1) != 0) goto LAB_0039fc80;
      }
      *(ulong *)(puVar18 + 10) = uVar28;
    }
    if (uVar28 == 0) {
      nvAssertFailedNoLog("pLocals->pageSize != 0",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x289);
      goto LAB_0039fa13;
    }
  }
  else if ((param_6 & 0xc00) == 0) {
    if (uVar13 == 1) {
LAB_0039fc80:
      puVar18[10] = 0x1000;
      puVar18[0xb] = 0;
      uVar28 = 0x1000;
    }
    else {
      if (uVar13 != 2) goto LAB_0039f835;
      uVar28 = *(ulong *)(puVar18 + 0x3e);
      *(ulong *)(puVar18 + 10) = uVar28;
    }
  }
  else if (uVar13 == 4) {
LAB_003a0558:
    puVar18[10] = 0x200000;
    puVar18[0xb] = 0;
    uVar28 = 0x200000;
  }
  else {
    if (uVar13 != 5) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x299,
                   "dmaAllocMapping_GM107",4,
                   "NVRM: Unknown page size flag encountered during mapping\n");
      goto LAB_003a0786;
    }
    puVar18[10] = 0x20000000;
    puVar18[0xb] = 0;
    uVar28 = 0x20000000;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x29e,
               "dmaAllocMapping_GM107",1,
               "NVRM: Picked Page size based on flags: 0x%llx flagVal: 0x%x\n",uVar28,uVar31 & 0xf);
  uVar28 = *(ulong *)(puVar18 + 0x54);
  uVar27 = *(ulong *)(puVar18 + 10);
  if (uVar28 < uVar27) {
    if ((char)puVar18[0x40] != '\0') {
      uVar28 = memdescGetPhysAddr(*(undefined8 *)(puVar18 + 0x4c),local_70,0);
      uVar27 = *(ulong *)(puVar18 + 10);
      if (((uVar28 & uVar27 - 1) == 0) &&
         (lVar19 = *(long *)(puVar18 + 0x4c), (*(ulong *)(lVar19 + 0x30) & uVar27 - 1) == 0))
      goto LAB_0039fcd9;
      uVar28 = *(ulong *)(puVar18 + 0x54);
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x2ab,
                 "dmaAllocMapping_GM107",3,
                 "NVRM: Requested mapping at larger page size than the physical granularity PhysPageSize = 0x%llx MapPageSize = 0x%llx. Overriding to physical page granularity...\n"
                 ,uVar28,uVar27);
    lVar19 = *(long *)(puVar18 + 0x4c);
    *(undefined8 *)(puVar18 + 10) = *(undefined8 *)(puVar18 + 0x54);
  }
  else {
    lVar19 = *(long *)(puVar18 + 0x4c);
  }
LAB_0039fcd9:
  cVar11 = memdescGetFlag(lVar19,0x200000000);
  if ((cVar11 != '\0') && (puVar18[0x20] != 0x8000000)) {
    nvAssertFailedNoLog("(pLocals->readOnly == DMA_UPDATE_VASPACE_FLAGS_READ_ONLY)",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x2b6);
LAB_003a0786:
    iVar14 = 0x1f;
    goto LAB_0039fa13;
  }
  if ((*(char *)(lVar30 + 0x67d4) != '\0') &&
     (((*(char *)((long)puVar18 + 0xbe) != '\0' &&
       (uVar28 = *(ulong *)(puVar18 + 0x3e), uVar28 < *(ulong *)(puVar18 + 10))) &&
      (*(char *)(lVar3 + 0xad03) != '\0')))) {
    *(ulong *)(puVar18 + 10) = uVar28;
    uVar20 = memdescGetMemDescFromGpu(local_50,param_1);
    memdescSetPageSize(uVar20,local_70,uVar28 & 0xffffffff);
  }
  uVar28 = *(ulong *)(puVar18 + 0x50);
  *(char *)(puVar18 + 0x52) =
       ((uVar28 & 0xffff0000) != 0) << 4 | ((uVar28 & 0xff00ff00) != 0) << 3 |
       (uVar28 & 0xaaaaaaaa) != 0 | ((uVar28 & 0xf0f0f0f0) != 0) << 2 |
       ((uVar28 & 0xcccccccc) != 0) * '\x02';
  uVar27 = memdescGetPhysAddr(*(undefined8 *)(puVar18 + 0x4c),local_70,0);
  uVar28 = *(long *)(puVar18 + 10) - 1;
  uVar27 = uVar27 & uVar28;
  *(ulong *)(puVar18 + 8) = uVar27;
  lVar30 = *(long *)(*(long *)(puVar18 + 0x4c) + 0x30);
  puVar18[0x10] = 0;
  uVar28 = uVar27 + uVar28 + lVar30 & -*(long *)(puVar18 + 10);
  *(ulong *)(puVar18 + 6) = uVar28;
  puVar18[1] = (uint)(uVar28 >> ((byte)puVar18[0x52] & 0x3f));
  iVar14 = memmgrGetKindComprFromMemDesc_IMPL(lVar1,*(long *)(puVar18 + 0x4c),0,puVar18 + 0x10);
  if (iVar14 != 0) goto LAB_0039fa13;
  if (((*(char *)(lVar1 + 0x483) == '\0') && (*(long *)(puVar18 + 10) == 0x1000)) &&
     ((cVar11 = (**(code **)(lVar1 + 0x2a8))(lVar1,5,puVar18[0x10]), cVar11 != '\0' &&
      (*(char *)(lVar17 + 2) == '\0')))) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x2ed,
                 "dmaAllocMapping_GM107",3,
                 "NVRM: Requested 4K mapping on compressible sufrace. Overriding to physical page granularity...\n"
                );
    *(undefined8 *)(puVar18 + 10) = *(undefined8 *)(puVar18 + 0x54);
  }
  uVar31 = 1;
  if ((char)puVar18[0x40] == '\0') {
    uVar31 = *(uint *)(*(long *)(puVar18 + 0x4c) + 0x18);
  }
  *puVar18 = uVar31;
  if ((*(char *)(lVar17 + 2) != '\0') && (*(char *)(lVar2 + 0x2a8) != '\0')) {
    lVar30 = *(long *)(param_1 + 0x1b78);
    uVar28 = (**(code **)(*param_3 + 0x70))(param_3);
    if ((((uVar28 & 0x1000000) != 0) ||
        (lVar19 = __nvoc_dynamicCast(param_3,__nvoc_class_def_FABRIC_VASPACE), lVar19 != 0)) &&
       ((cVar11 = (**(code **)(lVar30 + 0x2a8))(lVar30,5,puVar18[0x10]), cVar11 != '\0' &&
        (cVar11 = (**(code **)(lVar30 + 0x2a8))(lVar30,10,puVar18[0x10]), cVar11 == '\0')))) {
      (**(code **)(lVar30 + 0x378))(lVar30,puVar18 + 0x10);
    }
  }
  if (*(char *)((long)puVar18 + 0xbd) == '\0') {
    lVar30 = *(long *)(puVar18 + 10);
    if ((((*(long *)(puVar18 + 0x3e) != lVar30 && lVar30 != 0x1000) && lVar30 != 0x200000) &&
         lVar30 != 0x20000000) && (lVar30 != 0x4000000000)) {
      nvAssertFailedNoLog("(pLocals->pageSize == pLocals->vaspaceBigPageSize) || (pLocals->pageSize == RM_PAGE_SIZE) || (pLocals->pageSize == RM_PAGE_SIZE_HUGE) || (pLocals->pageSize == RM_PAGE_SIZE_512M) || (pLocals->pageSize == RM_PAGE_SIZE_256G)"
                          ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x34b);
    }
    if (param_8 == (long *)0x0) {
      local_40[0] = (**(code **)(*param_3 + 0x58))(param_3);
      local_90 = (**(code **)(*param_3 + 0x60))(param_3);
      local_48 = (local_90 - local_40[0]) + 1;
    }
    else {
      virtmemGetAddressAndSize_IMPL(param_8[1],local_40,&local_48);
      local_90 = (local_40[0] - 1) + local_48;
    }
    uVar27 = *(ulong *)(puVar18 + 0x50);
    uVar28 = local_48 + -1 + uVar27;
    if (uVar28 / uVar27 < (ulong)*puVar18) {
      nvAssertFailedNoLog(&DAT_00d47b29,
                          "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x362);
      goto LAB_003a0786;
    }
    lVar30 = (**(code **)(*param_3 + 0x90))(param_3,(ulong)*puVar18,uVar28 % uVar27);
    if ((param_6 & 0x8000) == 0) {
      uVar27 = (**(code **)(*param_3 + 0x58))(param_3);
      uVar28 = local_40[0];
      if (local_40[0] <= uVar27) {
        uVar28 = (**(code **)(*param_3 + 0x58))(param_3);
      }
      *(ulong *)(puVar18 + 0xc) = uVar28;
      uVar28 = (**(code **)(*param_3 + 0x60))(param_3);
      if (uVar28 <= local_90) {
        local_90 = (**(code **)(*param_3 + 0x60))(param_3);
      }
      *(ulong *)(puVar18 + 0xe) = local_90;
      if ((param_6 & 4) == 0) {
        if ((*(char *)(param_2 + 0x1c5) != '\0') && (0x100000000 < *(ulong *)(lVar30 + 0x78))) {
          uVar28 = *(ulong *)(puVar18 + 0xc);
          if (uVar28 < 0x100000000) {
            uVar28 = 0x100000000;
          }
          *(ulong *)(puVar18 + 0xc) = uVar28;
        }
      }
      else {
        uVar28 = 0xffffffff;
        if (local_90 < 0x100000000) {
          uVar28 = local_90;
        }
        *(ulong *)(puVar18 + 0xe) = uVar28;
      }
    }
  }
  else {
    uVar20 = (**(code **)(*param_3 + 0x60))(param_3);
    uVar29 = (**(code **)(*param_3 + 0x58))(param_3);
    *(undefined8 *)(puVar18 + 0x46) = uVar29;
    *(undefined8 *)(puVar18 + 0x48) = uVar20;
    puVar18[0x27] = (uVar33 & 0x10000) << 10;
    if (((*(char *)((long)puVar18 + 0xbe) != '\0') && (*(char *)((long)puVar18 + 0xbf) != '\0')) &&
       (local_54 == 0)) {
      uVar20 = *(undefined8 *)(param_1 + 0x1b70);
      auVar35 = memmgrGetMIGPartitionableBAR1Range_IMPL(param_1,lVar1);
      *(undefined1 (*) [16])(puVar18 + 0x46) = auVar35;
      iVar15 = kmemsysSwizzIdToMIGMemRange_IMPL
                         (param_1,uVar20,param_9,auVar35._0_8_,auVar35._8_8_,puVar18 + 0x46);
      if (iVar15 != 0) {
        nvAssertOkFailedNoLog
                  (iVar15,
                   "kmemsysSwizzIdToMIGMemRange(pGpu, pKernelMemorySystem, swizzId, pLocals->totalVaRange, &pLocals->totalVaRange)"
                   ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x33b);
        iVar14 = iVar15;
        goto LAB_0039fa13;
      }
    }
    if ((param_6 & 0x8000) == 0) {
      *(undefined8 *)(puVar18 + 0xc) = *(undefined8 *)(puVar18 + 0x46);
      *(undefined8 *)(puVar18 + 0xe) = *(undefined8 *)(puVar18 + 0x48);
    }
  }
  uVar28 = *(ulong *)(puVar18 + 10);
  uVar27 = -uVar28 & *param_5;
  *(ulong *)(puVar18 + 2) = uVar27;
  if ((char)puVar18[0x2f] != '\0') {
    lVar30 = *(long *)(puVar18 + 6);
    uVar27 = 1L << ((byte)puVar18[0x15] & 0x3f);
    if (uVar27 < uVar28) {
      uVar27 = uVar28;
    }
    lVar19 = __nvoc_dynamicCast(param_3,__nvoc_class_def_OBJGVASPACE);
    uVar31 = uVar33 & 0xf00;
    if (uVar31 == 0x300) {
      if (uVar27 < *(ulong *)(puVar18 + 0x3e)) {
        uVar27 = *(ulong *)(puVar18 + 0x3e);
      }
      lVar30 = *(long *)(puVar18 + 6);
    }
    local_90 = (uVar27 - 1) + lVar30 & -uVar27;
    if (*(char *)((long)puVar18 + 0xbe) == '\0') {
      if ((param_6 & 0x8000) != 0) {
        *(long *)(puVar18 + 0xc) = *(long *)(puVar18 + 2);
        *(ulong *)(puVar18 + 0xe) = (local_90 - 1) + *(long *)(puVar18 + 2);
        goto LAB_003a0d05;
      }
LAB_003a0bd0:
      if (*(char *)(param_2 + 0x1c1) != '\0') {
        uVar28 = *(ulong *)(puVar18 + 0xe);
        if (0xffffffffff < uVar28) {
          uVar28 = 0xffffffffff;
        }
        *(ulong *)(puVar18 + 0xe) = uVar28;
      }
      if (uVar31 == 0x300) {
LAB_003a1200:
        uVar28 = *(ulong *)(puVar18 + 0x3e);
        if (uVar28 < *(ulong *)(puVar18 + 10)) {
          nvAssertFailedNoLog("pLocals->pageSize <= pLocals->vaspaceBigPageSize",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x3ce
                             );
          uVar28 = *(ulong *)(puVar18 + 0x3e);
        }
        uVar28 = uVar28 | 0x1000;
      }
      else {
        uVar28 = *(ulong *)(puVar18 + 10);
      }
      uVar31 = (uint)(param_6 >> 0xe) & 1;
      if (lVar19 != 0) {
        if (((*(byte *)(lVar19 + 0xb8) & 0x40) != 0) && ((param_6 & 0x8000) == 0)) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x3e4,
                       "dmaAllocMapping_GM107",4,
                       "NVRM: The VA space requires all allocations to specify a fixed address\n");
          goto LAB_003a0786;
        }
LAB_003a0c2d:
        cVar11 = gvaspaceIsInternalVaRestricted_IMPL(lVar19);
        if (cVar11 != '\0') {
          uVar31 = uVar31 | 0x20;
        }
      }
    }
    else {
      if (uVar27 < *(ulong *)(puVar18 + 0x3e)) {
        uVar27 = *(ulong *)(puVar18 + 0x3e);
      }
      local_90 = (uVar27 - 1) + *(long *)(puVar18 + 6) & -uVar27;
      if ((param_6 & 0x8000) == 0) goto LAB_003a0bd0;
      uVar32 = *(ulong *)(puVar18 + 2);
      uVar28 = (local_90 - 1) + uVar32;
      *(ulong *)(puVar18 + 0xc) = uVar32;
      *(ulong *)(puVar18 + 0xe) = uVar28;
      if ((uVar32 < *(ulong *)(puVar18 + 0x46)) || (*(ulong *)(puVar18 + 0x48) < uVar28)) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x3b3,
                     "dmaAllocMapping_GM107",4,
                     "NVRM: Requested BAR1 VA Lo=0x%llx Hi=0x%llx\ntotal BAR1 VA range Lo=0x%llx Hi=0x%llx\n"
                     ,uVar32,uVar28,*(ulong *)(puVar18 + 0x46),*(ulong *)(puVar18 + 0x48));
        goto LAB_003a0786;
      }
LAB_003a0d05:
      if (lVar19 != 0) {
        local_b8 = uVar33 & 0xf00;
        cVar11 = gvaspaceIsInternalVaRestricted_IMPL(lVar19);
        if (cVar11 != '\0') {
          if (((*(ulong *)(lVar19 + 0x138) <= *(ulong *)(puVar18 + 0xc)) &&
              (*(ulong *)(puVar18 + 0xc) <= *(ulong *)(lVar19 + 0x140))) ||
             ((*(ulong *)(puVar18 + 0xe) <= *(ulong *)(lVar19 + 0x140) &&
              (*(ulong *)(lVar19 + 0x138) <= *(ulong *)(puVar18 + 0xe))))) {
            iVar14 = 0x3b;
            goto LAB_0039fa13;
          }
        }
        if (local_b8 == 0x300) goto LAB_003a1200;
        uVar28 = *(ulong *)(puVar18 + 10);
        uVar31 = (uint)(param_6 >> 0xe) & 1;
        goto LAB_003a0c2d;
      }
      if (uVar31 == 0x300) goto LAB_003a1200;
      uVar28 = *(ulong *)(puVar18 + 10);
      uVar31 = (uint)(param_6 >> 0xe) & 1;
    }
    iVar15 = (**(code **)(*param_3 + 0x38))
                       (param_3,local_90,uVar27,*(undefined8 *)(puVar18 + 0xc),
                        *(undefined8 *)(puVar18 + 0xe),uVar28,uVar31,puVar18 + 2);
    if (iVar15 != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x3f9,
                   "dmaAllocMapping_GM107",4,"NVRM: can\'t alloc VA space for mapping.\n");
      iVar14 = iVar15;
      goto LAB_0039fa13;
    }
    uVar27 = *(ulong *)(puVar18 + 2);
    if ((*(long *)(puVar18 + 10) - 1U & uVar27) == 0) {
      uVar28 = *(ulong *)(puVar18 + 6);
      if (uVar28 <= local_90) goto LAB_003a0023;
      nvAssertFailedNoLog("vaSize >= pLocals->mapLength",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x3ff);
    }
    else {
      nvAssertFailedNoLog("0 == (pLocals->vaLo & (pLocals->pageSize - 1))",
                          "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x3fc);
    }
LAB_0039fa0d:
    iVar14 = 0x40;
    goto LAB_0039fa13;
  }
  uVar32 = *param_5;
  if ((uVar27 != uVar32) && (uVar32 - uVar27 != *(long *)(puVar18 + 8))) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x410,
                 "dmaAllocMapping_GM107",4,
                 "NVRM: Virtual address 0x%llX is not compatible with page size 0x%llX or page offset 0x%llX.\n"
                 ,uVar32,uVar28,*(long *)(puVar18 + 8));
    iVar14 = 0x37;
    goto LAB_0039fa13;
  }
  uVar28 = *(ulong *)(puVar18 + 6);
LAB_003a0023:
  *(ulong *)(puVar18 + 4) = (uVar27 - 1) + uVar28;
  if (puVar18[0x1e] == 2) {
    if (*(long *)(puVar18 + 0x4e) != 0) {
      *(undefined8 *)(puVar18 + 0x2c) = *(undefined8 *)(*(long *)(puVar18 + 0x4e) + 0xf0);
      uVar31 = (**(code **)(lVar3 + 0x288))(param_1);
      uVar20 = *(undefined8 *)(puVar18 + 2);
      puVar18[0x2e] = uVar31;
      uVar29 = memdescGetPhysAddr(local_50,local_70,0);
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x438,
                   "dmaAllocMapping_GM107",1,
                   "NVRM: P2P LOOPBACK setup with physical vidmem at 0x%llx and virtual address at 0x%llx\n"
                   ,uVar29,uVar20);
      goto LAB_003a0042;
    }
    nvAssertFailedNoLog("pLocals->pMemory != NULL",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x421);
    goto LAB_003a0ae6;
  }
  if (puVar18[0x1e] == 1) {
    uVar20 = gpumgrGetGpuFromSubDeviceInst(*(undefined4 *)(param_1 + 0x7b4),puVar18[0x21]);
    *(undefined8 *)(puVar18 + 0x2c) = uVar20;
  }
LAB_003a0042:
  uVar20 = memdescGetRootMemDesc(local_50,0);
  *(undefined8 *)(puVar18 + 0x4a) = uVar20;
  iVar15 = memdescGetAddressSpace(uVar20);
  if ((iVar15 == 2) &&
     (cVar11 = gpumgrCheckIndirectPeer_IMPL(param_1,**(undefined8 **)(puVar18 + 0x4a)),
     cVar11 != '\0')) {
    *(undefined1 *)(puVar18 + 0x44) = 1;
  }
  if ((puVar18[0x1e] == 0) || (*(char *)((long)puVar18 + 0x111) != '\0')) {
    puVar21 = (undefined8 *)memdescGetMemDescFromGpu(local_50,param_1);
  }
  else {
    puVar21 = (undefined8 *)memdescGetMemDescFromGpu(local_50,*(undefined8 *)(puVar18 + 0x2c));
  }
  *(undefined8 **)(puVar18 + 0x4c) = puVar21;
  uVar20 = memdescGetPteArrayForGpu(puVar21,*puVar21,local_70);
  *(undefined8 *)(puVar18 + 0x30) = uVar20;
  if (*(char *)((long)puVar18 + 0xbf) == '\0') {
    cVar11 = memdescGetFlag(*(undefined8 *)(puVar18 + 0x4c),0x4000000000000);
    uVar28 = *(ulong *)(puVar18 + 0x56);
    if (cVar11 != '\0') {
      uVar28 = uVar28 | 1;
      *(ulong *)(puVar18 + 0x56) = uVar28;
    }
    uVar20 = *(undefined8 *)(puVar18 + 0x30);
  }
  else {
    uVar28 = *(ulong *)(puVar18 + 0x56);
  }
  dmaPageArrayInitWithFlags
            (puVar18 + 0x32,uVar20,*puVar18,uVar28,
             *(undefined8 *)(*(long *)(puVar18 + 0x4c) + 0x158));
  uVar31 = *(uint *)(*(long *)(puVar18 + 0x4c) + 0x60);
  puVar18[0x3a] = uVar31;
  if (*(uint *)(*(long *)(puVar18 + 0x4c) + 0x160) <= uVar31) {
    nvAssertFailedNoLog("pLocals->pageArray.PteAdjust < pLocals->pTempMemDesc->pageArrayGranularity"
                        ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x46e);
    goto LAB_0039fa0d;
  }
  iVar15 = memdescGetAddressSpace();
  if (iVar15 == 2) {
    if (puVar18[0x1e] == 0) {
      if ((char)puVar18[0x44] != '\0') {
        puVar18[0x1b] = 4;
        if ((*(char *)(param_1 + 0x491d) != '\0') && (uVar31 = 4, local_54 == 0)) {
LAB_003a0dd0:
          if (*(char *)(param_1 + 0x4913) != '\0') {
LAB_003a017b:
            if (uVar31 == 1) goto LAB_003a1242;
          }
        }
        goto LAB_003a0190;
      }
      puVar18[0x1b] = 1;
      if (*(char *)(param_1 + 0x491d) == '\0') {
        if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_003a0190;
      }
      else {
        uVar31 = 1;
        if (local_54 == 0) goto LAB_003a0dd0;
      }
LAB_003a1242:
      if (*(ulong *)(puVar18 + 10) <= *(ulong *)(param_1 + 0x3b10)) goto LAB_003a0190;
      nvCheckFailedNoLog(4,
                         "Vidmem page size is limited by VMMU segment size when GPU is in SRIOV mode"
                         ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x527);
LAB_003a11d5:
      iVar14 = 0x1f;
    }
    else {
      puVar18[0x1b] = 2;
      if (puVar18[0x1e] == 1) goto LAB_003a0129;
LAB_003a0e40:
      if (puVar18[0x2e] == 0xffffffff) goto LAB_003a0ae0;
LAB_003a0190:
      if (((((*(char *)((long)puVar18 + 0x111) == '\0') &&
            (iVar15 = memdescGetAddressSpace(*(undefined8 *)(puVar18 + 0x4c)), iVar15 != 7)) &&
           (iVar15 = memdescGetAddressSpace(*(undefined8 *)(puVar18 + 0x4c)), iVar15 != 6)) &&
          ((cVar11 = memdescIsEgm(*(undefined8 *)(puVar18 + 0x4c)), cVar11 == '\0' ||
           (*(long *)(puVar18 + 0x2c) != param_1)))) && (*(long *)(param_1 + 0x1ce8) != 0)) {
        if ((*(char *)(param_1 + 0x4cc) != '\x01') && (*(char *)(param_1 + 0x4915) != '\0')) {
          cVar11 = memdescIsEgm(*(undefined8 *)(puVar18 + 0x4c));
          if (cVar11 == '\0') {
            *(undefined8 *)(puVar18 + 0x42) = *(undefined8 *)(*(long *)(param_1 + 0x1ce8) + 0x16b8);
            goto LAB_003a01a9;
          }
          goto LAB_003a019e;
        }
        cVar11 = memdescIsEgm(*(undefined8 *)(puVar18 + 0x4c));
        lVar30 = *(long *)(*(long *)(puVar18 + 0x2c) + 0x1ce8);
        lVar3 = *(long *)(*(long *)(puVar18 + 0x2c) + 0x1b78);
        puVar18[0x42] = 0xffffffff;
        puVar18[0x43] = 0xffffffff;
        if (cVar11 == '\0') {
          if (((puVar18[0x1b] == 2 && lVar30 != 0) &&
              (lVar30 = *(long *)(lVar30 + 0x16a8), *(long *)(puVar18 + 0x42) = lVar30, lVar30 != -1
              )) && (cVar11 = (**(code **)(lVar3 + 0x2a8))(lVar3,5,puVar18[0x10]), cVar11 != '\0'))
          {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x813,
                         "_dmaGetFabricAddress",4,
                         "NVRM: Nvswitch systems don\'t support compression.\n");
            goto LAB_003a1139;
          }
        }
        else if (((puVar18[0x1b] == 2 && lVar30 != 0) &&
                 (lVar30 = *(long *)(lVar30 + 0x16b0), *(long *)(puVar18 + 0x42) = lVar30,
                 lVar30 != -1)) &&
                (cVar11 = (**(code **)(lVar3 + 0x2a8))(lVar3,5,puVar18[0x10]), cVar11 != '\0')) {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x83e,
                       "_dmaGetFabricEgmAddress",4,
                       "NVRM: Nvswitch systems don\'t support compression.\n");
LAB_003a1139:
          iVar14 = 0x56;
          goto LAB_003a0ae6;
        }
      }
      else {
LAB_003a019e:
        puVar18[0x42] = 0xffffffff;
        puVar18[0x43] = 0xffffffff;
      }
LAB_003a01a9:
      uVar12 = (**(code **)(param_2 + 0x188))
                         (param_2,*(undefined8 *)(puVar18 + 0x4c),puVar18[0x1b],(char)puVar18[0x44])
      ;
      *(undefined1 *)(puVar18 + 0x1c) = uVar12;
      cVar11 = memdescGetFlag(*(undefined8 *)(puVar18 + 0x4c),0x8000000000);
      if (cVar11 == '\0') {
        uVar33 = uVar33 >> 0x11 & 3;
        if (uVar33 != 1) {
          if (uVar33 != 2) goto LAB_003a0b70;
          uVar33 = puVar18[0x1b];
          *(undefined1 *)(puVar18 + 0x1c) = 1;
          if ((*(char *)(lVar1 + 0x447) == '\0') || (uVar33 != 3)) {
            cVar11 = '\x01';
            goto LAB_003a0240;
          }
          goto LAB_003a0b9b;
        }
        *(undefined1 *)(puVar18 + 0x1c) = 0;
        uVar33 = puVar18[0x1b];
        cVar11 = '\0';
      }
      else {
LAB_003a0b70:
        cVar11 = (char)puVar18[0x1c];
        uVar33 = puVar18[0x1b];
        if (((*(char *)(lVar1 + 0x447) != '\0') && (uVar33 == 3)) && (cVar11 != '\0')) {
LAB_003a0b9b:
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x588,
                       "dmaAllocMapping_GM107",1,
                       "NVRM: SYS_NCOH + VOL=1 mappings do not support platform atomics.\n");
          uVar33 = puVar18[0x1b];
          cVar11 = (char)puVar18[0x1c];
        }
      }
LAB_003a0240:
      cVar11 = (**(code **)(lVar2 + 0x228))(param_1,lVar2,cVar11,uVar33);
      *(char *)(puVar18 + 0x58) = cVar11;
      if (param_8 == (long *)0x0) {
        if (cVar11 != '\0') {
          nvAssertOkFailedNoLog
                    (0x1f,"!pLocals->bNeedL2InvalidateAtUnmap",
                     "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x594);
          goto LAB_003a11d5;
        }
      }
      else {
        *(uint *)(*param_8 + 0xf0) = puVar18[0x1b];
        *(char *)(*param_8 + 0xf4) = (char)puVar18[0x58];
      }
      iVar15 = (**(code **)(*(long *)(param_1 + 0x1bb8) + 400))
                         (param_1,*(long *)(param_1 + 0x1bb8),param_3,
                          *(undefined8 *)(puVar18 + 0x4c),0,*(undefined8 *)(puVar18 + 2),
                          *(undefined8 *)(puVar18 + 4),
                          puVar18[0x20] | puVar18[0x27] | puVar18[0x11] | puVar18[0x1d] |
                          puVar18[0x26] | 0x7ff,puVar18 + 0x32,puVar18 + 0x14,0,1,puVar18[0x1b],
                          (char)puVar18[0x1c],puVar18[0x2e],*(undefined8 *)(puVar18 + 0x42),
                          puVar18[0x22],0,*(undefined8 *)(puVar18 + 10));
      if (iVar15 == 0) goto LAB_003a0324;
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x5ae,
                   "dmaAllocMapping_GM107",4,
                   "NVRM: can\'t update VA space for mapping @vaddr=0x%llx\n",
                   *(undefined8 *)(puVar18 + 2));
      iVar14 = iVar15;
    }
LAB_003a0ae6:
    uVar20 = 0;
    if (*(long *)(puVar18 + 0x24) != 0) {
      btreeUnlink(*(long *)(puVar18 + 0x24),*(undefined8 *)(puVar18 + 0x2a));
      uVar20 = *(undefined8 *)(puVar18 + 0x24);
    }
    portMemFree(uVar20);
    if ((char)puVar18[0x2f] != '\0') {
      (**(code **)(*param_3 + 0x40))(param_3,*(undefined8 *)(puVar18 + 2));
    }
  }
  else {
    iVar15 = memdescGetAddressSpace(*(undefined8 *)(puVar18 + 0x4c));
    if ((iVar15 == 7) ||
       (iVar15 = memdescGetAddressSpace(*(undefined8 *)(puVar18 + 0x4c)), iVar15 == 6)) {
      puVar18[0x2e] = 0xffffffff;
      if (*(long *)(puVar18 + 0x4e) != 0) {
        lVar30 = *(long *)(*(long *)(puVar18 + 0x4e) + 0xf0);
        cVar11 = (**(code **)(lVar1 + 0x2a8))(lVar1,5,puVar18[0x10]);
        if (cVar11 == '\0') {
          puVar18[0x1b] = 2;
          cVar11 = (**(code **)(**(long **)(puVar18 + 0x4e) + 0x200))
                             (*(long **)(puVar18 + 0x4e),param_1);
          if (cVar11 == '\0') {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x49f,
                         "dmaAllocMapping_GM107",4,
                         "NVRM: Mapping Gpu is not attached to the given memory object\n");
          }
          else {
            if (lVar30 == 0) {
              uVar31 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x298))(param_1);
              puVar18[0x2e] = uVar31;
            }
            else if ((*(char *)(param_1 + 0x4913) == '\0') || (*(char *)(param_1 + 0x491e) != '\0'))
            {
              if ((*(long *)(param_1 + 0x1ce8) == 0) ||
                 (cVar11 = knvlinkIsNvlinkP2pSupported_IMPL
                                     (param_1,*(long *)(param_1 + 0x1ce8),lVar30), cVar11 == '\0'))
              {
                uVar31 = puVar18[0x2e];
              }
              else {
                uVar31 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x288))
                                   (param_1,*(long *)(&DAT_00001b90 + param_1),lVar30);
                puVar18[0x2e] = uVar31;
              }
            }
            else {
              uVar31 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x290))(param_1);
              puVar18[0x2e] = uVar31;
            }
            if (uVar31 != 0xffffffff) goto LAB_003a0606;
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x494,
                       "dmaAllocMapping_GM107",4,"NVRM: Fabric memory should not be compressible.\n"
                      );
        }
      }
LAB_003a0ae0:
      iVar14 = 0x40;
      goto LAB_003a0ae6;
    }
    cVar11 = memdescIsEgm(*(undefined8 *)(puVar18 + 0x4c));
    if (cVar11 != '\0') {
      puVar18[0x1b] = 2;
      if (puVar18[0x1e] == 0) {
        if (*(char *)(lVar1 + 0x454) != '\0') {
          puVar18[0x2e] = *(uint *)(lVar1 + 0x458);
          goto LAB_003a0e40;
        }
        nvAssertFailedNoLog("pMemoryManager->bLocalEgmEnabled",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x4dc);
      }
      else {
        if (*(long *)(puVar18 + 0x4e) != 0) {
          uVar31 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x280))
                             (param_1,*(long *)(&DAT_00001b90 + param_1),
                              *(undefined8 *)(*(long *)(puVar18 + 0x4e) + 0xf0));
          puVar18[0x2e] = uVar31;
LAB_003a0606:
          if (puVar18[0x1e] == 1) goto LAB_003a0129;
          goto LAB_003a0156;
        }
        nvAssertFailedNoLog("pLocals->pMemory != NULL",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x4d1);
      }
      goto LAB_0039fa0d;
    }
    if (puVar18[0x1e] != 0) {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x4e6,
                   "dmaAllocMapping_GM107",4,"NVRM: No P2P for system memory.\n");
      goto LAB_003a11d5;
    }
    cVar11 = memdescGetFlag(local_50,0x800000000);
    uVar31 = 3;
    if (cVar11 == '\0') {
      if (*(char *)(lVar1 + 0x447) == '\0') {
        uVar31 = 4 - (puVar18[0x12] == 0);
      }
      else {
        uVar31 = 4 - (puVar18[0x13] == 0);
      }
    }
    puVar18[0x1b] = uVar31;
    if (puVar18[0x1e] != 1) goto LAB_003a0190;
LAB_003a0129:
    if (*(long *)(puVar18 + 0x2c) != param_1) {
      uVar31 = (**(code **)(*(long *)(&DAT_00001b90 + param_1) + 0x288))(param_1);
      puVar18[0x2e] = uVar31;
LAB_003a0156:
      uVar31 = puVar18[0x1b];
      if (uVar31 == 2) goto LAB_003a0e40;
      if ((*(char *)(param_1 + 0x491d) == '\0') || (local_54 == 0)) goto LAB_003a0dd0;
      goto LAB_003a017b;
    }
LAB_003a0324:
    *param_5 = *(long *)(puVar18 + 8) + *(long *)(puVar18 + 2);
    if (param_8 != (long *)0x0) {
      *(undefined8 *)(*param_8 + 0xe8) = *(undefined8 *)(puVar18 + 10);
    }
    uVar20 = *(undefined8 *)(puVar18 + 10);
    uVar29 = memdescGetMemDescFromGpu(local_50,param_1);
    memdescSetPageSize(uVar29,local_70,uVar20);
  }
LAB_0039fa13:
  if (local_50 != param_4) {
    fabricvaspacePutGpaMemdesc_IMPL(lVar16);
  }
  portMemFree(puVar18);
  return iVar14;
}


// ===== 003a1700 dmaFreeMapping_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dmaFreeMapping_GM107
              (long param_1,undefined8 param_2,long *param_3,ulong param_4,long param_5,uint param_6
              ,long *param_7)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_5 == 0) {
    nvAssertFailedNoLog("NULL != pMemDesc",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x612);
    return 0x1f;
  }
  lVar5 = param_3[10];
  uVar4 = memdescGetMemDescFromGpu(param_5,param_1);
  lVar5 = memdescGetPageSize(uVar4,lVar5);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("memdescGetPageSize(memdescGetMemDescFromGpu(pMemDesc, pGpu), VAS_ADDRESS_TRANSLATION(pVAS)) != 0"
                        ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x616);
  }
  if (param_7 == (long *)0x0) {
    (**(code **)(*param_3 + 0x40))(param_3,param_4);
    uVar4 = memdescGetMemDescFromGpu(param_5,param_1);
    memdescGetGpuP2PCacheAttrib(uVar4);
    return 0;
  }
  lVar5 = param_7[1];
  uVar9 = *(uint *)(*param_7 + 0xd8) >> 0x14 & 3;
  if (uVar9 == 1) {
    lVar6 = gpumgrGetGpuFromSubDeviceInst
                      (*(undefined4 *)(param_1 + 0x7b4),*(uint *)(*param_7 + 0xd8) >> 0x16 & 7);
    if ((lVar5 == 0) || (*(char *)(lVar5 + 0x265) == '\0')) {
      bVar10 = true;
      goto LAB_003a17aa;
    }
    if (param_1 == lVar6) {
      bVar10 = true;
      goto LAB_003a17bd;
    }
  }
  else if ((lVar5 == 0) || (*(char *)(lVar5 + 0x265) == '\0')) {
    bVar10 = uVar9 != 0;
LAB_003a17aa:
    (**(code **)(*param_3 + 0x40))(param_3,param_4);
    goto LAB_003a17bd;
  }
  lVar6 = memdescGetMemDescFromGpu(param_5,param_1);
  lVar5 = *(long *)(*param_7 + 0xe8);
  if (lVar5 == 0) {
    nvAssertFailedNoLog("pCliMapInfo->pDmaMappingInfo->mapPageSize != 0",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x638);
    return 0x40;
  }
  uVar7 = memdescGetPhysAddr(lVar6,param_3[10],0);
  lVar1 = *(long *)(param_1 + 0x1bb8);
  lVar2 = *(long *)(lVar6 + 0x30);
  uVar8 = (**(code **)(*param_3 + 0x70))(param_3);
  if ((uVar8 & 0x80) != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x643,
                 "dmaFreeMapping_GM107",4,
                 "NVRM: Using dmaFreeMapping with sparse == False in BAR1 path!\n");
    nvAssertFailedNoLog(&DAT_00d47b29,
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x644);
    return 0;
  }
  param_4 = param_4 & -lVar5;
  iVar3 = (**(code **)(lVar1 + 400))
                    (param_1,lVar1,param_3,lVar6,0,param_4,
                     (param_4 - 1) + (lVar2 + (lVar5 - 1U) + (lVar5 - 1U & uVar7) & -lVar5),8,0,0,0,
                     0,0,0,0,0xffffffffffffffff,param_6 & 1,0,lVar5);
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x65a,
                 "dmaFreeMapping_GM107",4,"NVRM: error updating VA space.\n");
    (**(code **)(*param_3 + 0x40))(param_3,param_4);
    return iVar3;
  }
  bVar10 = uVar9 != 0;
LAB_003a17bd:
  uVar4 = memdescGetMemDescFromGpu(param_5,param_1);
  iVar3 = memdescGetGpuP2PCacheAttrib(uVar4);
  if ((iVar3 == 0) && (bVar10)) {
    (**(code **)(*(long *)(param_1 + 0x1b70) + 0x188))(param_1,*(long *)(param_1 + 0x1b70),0,3,1);
  }
  if (*(char *)(*param_7 + 0xf4) != '\0') {
    (**(code **)(*(long *)(param_1 + 0x1b70) + 0x188))
              (param_1,*(long *)(param_1 + 0x1b70),0,
               (*(int *)(*param_7 + 0xf0) == 2) * '\x02' + '\x01',1);
  }
  return 0;
}


// ===== 003a1b10 dmaUpdateVASpace_GF100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

int dmaUpdateVASpace_GF100
              (ulong param_1,long param_2,long *param_3,long param_4,long param_5,ulong param_6,
              long param_7,uint param_8,long param_9,int *param_10,undefined8 param_11,uint param_12
              ,uint param_13,char param_14,int param_15,undefined8 param_16,int param_17,
              char param_18,ulong param_19)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  undefined4 *puVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  long *plVar15;
  undefined8 *puVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  uint uVar20;
  uint *puVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  byte local_228;
  long *local_220;
  byte local_218;
  uint local_1dc;
  int local_1c8;
  byte *local_1b8;
  int **local_1b0;
  code *local_1a8;
  ulong local_1a0;
  long local_198;
  undefined4 **local_190;
  code *local_188;
  undefined8 local_180;
  ulong local_178;
  undefined8 local_170;
  long local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  int *local_148;
  int local_140 [2];
  long local_138 [6];
  undefined8 local_108;
  undefined8 local_100;
  int local_f8;
  int local_f4;
  undefined1 local_f0;
  uint local_e8 [4];
  undefined8 local_d8;
  byte local_d0;
  byte local_cf;
  byte local_ce;
  long local_c8;
  undefined4 *local_c0;
  ulong local_b8 [2];
  ulong *local_a8 [9];
  undefined1 local_60 [27];
  undefined1 local_45;
  
  lVar1 = *(long *)(&DAT_00001b90 + param_1);
  lVar19 = *(long *)(param_1 + 0x1b70);
  lVar2 = *(long *)(param_1 + 0x1b78);
  lVar12 = kmemsysGetStaticConfig_IMPL(param_1,lVar19);
  iVar22 = *(int *)(lVar12 + 0x14);
  lVar3 = *(long *)(param_1 + 0x1b98);
  local_220 = param_3;
  if ((param_8 & 0x2000000) == 0) {
    if (((param_8 & 8) == 0) || ((param_12 & 1) != 0)) {
      if (param_3 == (long *)0x0) {
        __nvoc_dynamicCast(0,__nvoc_class_def_OBJGVASPACE);
        local_220 = (long *)0x0;
        local_1dc = 0;
        local_220 = local_220;
      }
      else {
        __nvoc_dynamicCast(param_3,__nvoc_class_def_OBJGVASPACE);
        local_1dc = 0;
      }
    }
    else if (param_3 == (long *)0x0) {
      __nvoc_dynamicCast(0,__nvoc_class_def_OBJGVASPACE);
      local_220 = (long *)0x0;
      local_1dc = 1;
    }
    else {
      __nvoc_dynamicCast(param_3,__nvoc_class_def_OBJGVASPACE);
      local_1dc = 1;
    }
  }
  else {
    if (param_3 == (long *)0x0) {
      lVar18 = __nvoc_dynamicCast(0,__nvoc_class_def_OBJGVASPACE);
      local_220 = (long *)0x0;
    }
    else {
      lVar18 = __nvoc_dynamicCast(param_3,__nvoc_class_def_OBJGVASPACE);
    }
    local_1dc = 0;
    if ((((*(byte *)(lVar18 + 0xb8) & 0x80) != 0) && ((param_8 & 8) != 0)) && ((param_12 & 1) == 0))
    {
      param_18 = '\x01';
    }
  }
  if (param_19 == 0) {
    nvAssertFailedNoLog("pageSize","src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",
                        0x888);
    return 0x1f;
  }
  uVar13 = (**(code **)(*param_3 + 0xa0))(param_3);
  if (((param_19 - 0x10000 & 0xfffffffffffeffff) == 0) && (param_19 != uVar13)) {
    nvAssertFailedNoLog("pageSize == vaSpaceBigPageSize",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x88d);
    return 0x40;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("pMemDesc","src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",
                        0x89b);
    return 0x1f;
  }
  cVar8 = '\0';
  if ((param_8 & 0x4000000) == 0) {
    cVar8 = memdescGetFlag(param_4,0x800);
  }
  if ((param_8 & 1) == 0) {
LAB_003a1c57:
    bVar7 = (byte)(param_8 >> 3) & 1 ^ 1 | (byte)param_12 & 1;
  }
  else {
    if (param_9 == 0) {
      return 0x1f;
    }
    bVar7 = 0;
    if ((~param_8 & 0x7ff) != 0) goto LAB_003a1c57;
  }
  if ((*(char *)(lVar2 + 0x43e) == '\0') || (*(char *)(lVar12 + 2) == '\0')) {
    local_1c8 = (int)uVar13;
    if (*(char *)(param_2 + 0x1c6) == '\0') {
      local_1c8 = iVar22;
    }
  }
  else {
    local_1c8 = 0x1000;
  }
  if ((((*(char *)(g_pSys + 400) == '\0') && (param_9 != 0)) && (param_19 != 0x1000)) &&
     ((uVar20 = *(uint *)(param_9 + 0xc), 1 < uVar20 && ((param_8 & 0x1000) == 0)))) {
    uVar23 = 0;
    do {
      uVar24 = uVar23 + 1;
      if (uVar24 < uVar20) {
        do {
          uVar13 = dmaPageArrayGetPhysAddr(param_9,uVar24 - 1);
          uVar14 = dmaPageArrayGetPhysAddr(param_9,uVar24);
          if ((uVar13 >> 0xc) + 1 != uVar14 >> 0xc) {
            nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x8e7,
                         "dmaUpdateVASpace_GF100",4,
                         "NVRM: MMU: given non-contig 4KB pages for %lldkB mapping\n",param_19 >> 10
                        );
            return 0xffff;
          }
          uVar20 = *(uint *)(param_9 + 0xc);
          uVar24 = uVar24 + 1;
        } while (((uVar14 + 0x1000) % param_19 != 0) && (uVar24 < uVar20));
      }
      uVar23 = uVar23 + uVar24;
    } while (uVar23 < uVar20);
  }
  local_1b8 = (byte *)0x0;
  local_1b0 = (int **)0x0;
  local_1a8 = (code *)0x0;
  uVar20 = param_8 >> 0x1d & 1;
  local_1a0 = 0;
  uVar23 = param_8 >> 0x1b & 1;
  iVar22 = 0;
  if (param_13 == 2) {
    iVar22 = param_15;
  }
  uVar13 = 0;
  do {
    uVar24 = (int)uVar13 + 0x20;
    *(undefined8 *)((long)&local_148 + uVar13) = 0;
    *(undefined8 *)((long)local_140 + uVar13) = 0;
    *(undefined8 *)((long)local_138 + uVar13) = 0;
    *(undefined8 *)((long)local_138 + uVar13 + 8) = 0;
    uVar13 = (ulong)uVar24;
  } while (uVar24 < 0x80);
  *(undefined8 *)((long)&local_148 + (ulong)uVar24) = 0;
  plVar15 = (long *)__nvoc_dynamicCast(local_220,__nvoc_class_def_OBJGVASPACE);
  uVar14 = param_6 & -param_19;
  uVar13 = (param_7 + param_19 & -param_19) - 1;
  puVar16 = (undefined8 *)gvaspaceGetGpuState_IMPL(plVar15,param_1);
  if (local_1dc == 0) {
    piVar4 = (int *)*puVar16;
    iVar10 = *param_10;
    cVar9 = (**(code **)(lVar2 + 0x2a8))(lVar2,5,iVar10);
    if (cVar9 != '\0') {
      iVar10 = (**(code **)(lVar2 + 0x290))(param_1,lVar2,iVar10,0);
    }
    cVar9 = (**(code **)(lVar2 + 0x2a8))(lVar2,5,*param_10);
    if (((cVar9 != '\0') && ((param_6 & local_1c8 - 1) != 0)) && ((param_8 & 0x1000000) == 0)) {
      return 0x1f;
    }
    local_1b8 = (byte *)mmuFmtFindLevelWithPageShift
                                  (*(undefined8 *)(piVar4 + 2),
                                   (param_19 & 0xaaaaaaaaaaaaaaaa) != 0 |
                                   (param_19 >> 0x20 != 0) << 5 |
                                   ((param_19 & 0xffff0000ffff0000) != 0) << 4 |
                                   ((param_19 & 0xff00ff00ff00ff00) != 0) << 3 |
                                   ((param_19 & 0xf0f0f0f0f0f0f0f0) != 0) << 2 |
                                   ((param_19 & 0xcccccccccccccccc) != 0) * '\x02');
    local_1b0 = &local_148;
    local_1a8 = _gmmuWalkCBMapNextEntries_RmAperture;
    local_1a0 = (ulong)*(uint *)(param_4 + 0x160);
    local_138[0] = param_9;
    local_138[2] = param_11;
    local_138[5] = *(long *)param_10;
    local_108 = *(undefined8 *)(param_10 + 2);
    local_100 = *(undefined8 *)(param_10 + 4);
    local_f8 = param_10[6];
    local_148 = piVar4;
    local_f4 = iVar10;
    local_d0 = bVar7;
    local_f0 = (**(code **)(lVar2 + 0x2a8))(lVar2,5,*param_10);
    local_cf = (byte)param_8 & 1;
    local_ce = (byte)(param_8 >> 1) & 1;
    local_138[4] = param_16;
    if ((param_19 == 0x20000000) && (*(char *)(lVar3 + 0x67d3) != '\0')) {
      lVar2 = *(long *)(&DAT_00001b90 + param_1);
      lVar12 = *(long *)(param_1 + 0x1b98);
      puVar16 = (undefined8 *)gvaspaceGetGpuState_IMPL(plVar15,param_1);
      puVar5 = (undefined4 *)*puVar16;
      lVar18 = kgmmuFmtGetFamily_IMPL(lVar12,*puVar5);
      local_178 = 0;
      local_170 = 0;
      local_168 = 0;
      local_160 = 0;
      local_158 = 0;
      local_150 = 0;
      local_198 = 0;
      local_190 = (undefined4 **)0x0;
      local_188 = (code *)0x0;
      local_180 = 0;
      uVar17 = 0;
      do {
        uVar24 = (int)uVar17 + 0x20;
        *(undefined8 *)((long)&local_c0 + uVar17) = 0;
        *(undefined8 *)((long)local_b8 + uVar17) = 0;
        *(undefined8 *)((long)local_a8 + (uVar17 - 8)) = 0;
        *(undefined8 *)((long)local_a8 + uVar17) = 0;
        uVar17 = (ulong)uVar24;
      } while (uVar24 < 0x80);
      *(undefined8 *)((long)&local_c0 + (ulong)uVar24) = 0;
      iVar11 = (**(code **)(lVar12 + 0x330))(lVar12);
      if (iVar11 != 0) {
        nvAssertOkFailedNoLog
                  (iVar11,"kgmmuSetupWarForBug2720120_HAL(pKernelGmmu)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xbb2);
LAB_003a2e92:
        nvAssertOkFailedNoLog
                  (iVar11,"_dmaApplyWarForBug2720120(pGVAS, pGpu, vaLo, vaHi)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x93d);
        return iVar11;
      }
      local_198 = mmuFmtFindLevelWithPageShift(*(undefined8 *)(puVar5 + 2),0x1d);
      local_45 = 1;
      local_188 = _gmmuWalkCBMapNextEntries_RmAperture;
      local_190 = &local_c0;
      local_c0 = puVar5;
      portMemCopy(local_60,*(undefined1 *)(local_198 + 2),lVar18 + 0x510,
                  *(undefined1 *)(local_198 + 2));
      lVar12 = (**(code **)(plVar15[0x13] + 0x40))(plVar15[0x13],uVar14,0);
      if (lVar12 == 0) {
        iVar11 = 0x1f;
        nvAssertFailedNoLog("pMemBlock != NULL",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xbc3);
        goto LAB_003a2e92;
      }
      iVar11 = gvaspaceWalkUserCtxAcquire_IMPL
                         (plVar15,param_1,*(undefined8 *)(lVar12 + 0x80),&local_178);
      if (iVar11 != 0) {
        nvAssertOkFailedNoLog
                  (iVar11,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, pVASBlock, &userCtx)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xbc6);
        goto LAB_003a2e92;
      }
      iVar11 = mmuWalkMap(*(undefined8 *)(local_168 + 8),uVar14,uVar13,&local_198);
      if (iVar11 != 0) {
        nvAssertOkFailedNoLog
                  (iVar11,"mmuWalkMap(userCtx.pGpuState->pWalk, vaLo, vaHi, &mapTarget)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xbc7);
        goto LAB_003a2e92;
      }
      gvaspaceWalkUserCtxRelease_IMPL(plVar15,&local_178);
      (**(code **)(lVar2 + 0x500))(param_1,lVar2,3);
      (**(code **)(*plVar15 + 0x1b8))(plVar15,param_1,0);
    }
    uVar24 = param_8 >> 0x1c & 1;
    cVar9 = (**(code **)(lVar19 + 0x220))(param_1,lVar19,param_14,param_13);
    if (cVar9 != '\0') {
      (**(code **)(lVar19 + 0x188))(param_1,lVar19,param_4,(param_13 == 2) * '\x02' + '\x01',3);
    }
    if (*piVar4 == 3) {
      local_c0 = (undefined4 *)((ulong)local_c0 & 0xffffffff00000000);
      if (param_12 == 0) {
        uVar24 = (-(uint)(param_18 == '\0') & 0xfffffffd) + 4;
      }
      else {
        lVar19 = *(long *)(piVar4 + 8);
        puVar21 = (uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0xe));
        *puVar21 = (uint)(*(byte *)(lVar19 + 0x10) ^ 1) <<
                   ((byte)*(undefined2 *)(lVar19 + 0xc) & 0x1f) | *puVar21 & *(uint *)(lVar19 + 8);
        lVar19 = *(long *)(piVar4 + 8);
        puVar21 = (uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x22));
        *puVar21 = (uint)*(byte *)(*(long *)(lVar19 + 0x28) + 1 + (ulong)param_13 * 2) <<
                   ((byte)*(undefined2 *)(lVar19 + 0x20) & 0x1f) |
                   *puVar21 & *(uint *)(lVar19 + 0x1c);
        lVar19 = *(long *)(piVar4 + 8);
        puVar21 = (uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0xfa));
        *puVar21 = *puVar21 & *(uint *)(lVar19 + 0xf4) |
                   iVar22 << ((byte)*(undefined2 *)(lVar19 + 0xf8) & 0x1f);
        lVar19 = *(long *)(piVar4 + 8);
        puVar21 = (uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x186));
        *puVar21 = *puVar21 & *(uint *)(lVar19 + 0x180) |
                   iVar10 << ((byte)*(undefined2 *)(lVar19 + 0x184) & 0x1f);
        uVar24 = uVar24 << 8 ^ 0x100 |
                 (param_8 >> 0x1b & 1) << 7 | (param_8 >> 0x1d & 1) << 6 |
                 (uint)(param_14 != '\0') << 5;
        iVar22 = memdescGetAddressSpace(param_4);
        if (iVar22 == 7) {
          uVar24 = uVar24 | 0x10;
        }
      }
      if ((param_8 & 0x8000) != 0) {
        uVar24 = uVar24 & 0xffffffef;
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x979,
                     "dmaUpdateVASpace_GF100",1,"NVRM: force ACD=true with ptePcfSw = 0x%X\n",uVar24
                    );
      }
      iVar22 = (**(code **)(lVar3 + 0x280))(lVar3,uVar24,&local_c0);
      if (iVar22 != 0) {
        nvCheckFailedNoLog(4,
                           "(kgmmuTranslatePtePcfFromSw_HAL(pKernelGmmu, ptePcfSw, &ptePcfHw) == NV_OK)"
                           ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x97b);
        return 0x1f;
      }
      lVar19 = *(long *)(piVar4 + 8);
      puVar21 = (uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x1aa));
      *puVar21 = (int)local_c0 << ((byte)*(undefined2 *)(lVar19 + 0x1a8) & 0x1f) |
                 *puVar21 & *(uint *)(lVar19 + 0x1a4);
      lVar19 = *(long *)(piVar4 + 8);
    }
    else if (param_18 == '\0') {
      lVar19 = *(long *)(piVar4 + 8);
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0xe)) =
           (uint)(param_12 != 0 ^ *(byte *)(lVar19 + 0x10)) <<
           ((byte)*(undefined2 *)(lVar19 + 0xc) & 0x1f) |
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0xe)) & *(uint *)(lVar19 + 8);
      lVar19 = *(long *)(piVar4 + 8);
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x22)) =
           (uint)*(byte *)(*(long *)(lVar19 + 0x28) + 1 + (ulong)param_13 * 2) <<
           ((byte)*(undefined2 *)(lVar19 + 0x20) & 0x1f) |
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x22)) & *(uint *)(lVar19 + 0x1c);
      lVar19 = *(long *)(piVar4 + 8);
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0xfa)) =
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0xfa)) & *(uint *)(lVar19 + 0xf4)
           | iVar22 << ((byte)*(undefined2 *)(lVar19 + 0xf8) & 0x1f);
      lVar19 = *(long *)(piVar4 + 8);
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x106)) =
           (uint)(param_14 != '\0' ^ *(byte *)(lVar19 + 0x108)) <<
           ((byte)*(undefined2 *)(lVar19 + 0x104) & 0x1f) |
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x106)) &
           *(uint *)(lVar19 + 0x100);
      lVar19 = *(long *)(piVar4 + 8);
      local_218 = (byte)uVar23;
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x186)) =
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x186)) &
           *(uint *)(lVar19 + 0x180) | iVar10 << ((byte)*(undefined2 *)(lVar19 + 0x184) & 0x1f);
      lVar19 = *(long *)(piVar4 + 8);
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x116)) =
           (uint)(local_218 ^ *(byte *)(lVar19 + 0x118)) <<
           ((byte)*(undefined2 *)(lVar19 + 0x114) & 0x1f) |
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x116)) &
           *(uint *)(lVar19 + 0x110);
      lVar19 = *(long *)(piVar4 + 8);
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x146)) =
           (uint)(byte)((byte)uVar24 ^ *(byte *)(lVar19 + 0x148)) <<
           ((byte)*(undefined2 *)(lVar19 + 0x144) & 0x1f) |
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x146)) &
           *(uint *)(lVar19 + 0x140);
      lVar19 = *(long *)(piVar4 + 8);
      *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x156)) =
           (uint)(cVar8 != '\0' ^ *(byte *)(lVar19 + 0x158)) <<
           ((byte)*(undefined2 *)(lVar19 + 0x154) & 0x1f) |
           *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x156)) &
           *(uint *)(lVar19 + 0x150);
      lVar19 = *(long *)(piVar4 + 8);
      bVar6 = (byte)(param_8 >> 0x18);
      if (*(int *)(lVar19 + 0x11c) != 0) {
        *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x126)) =
             (uint)(bVar6 >> 6 & 1 ^ *(byte *)(lVar19 + 0x128)) <<
             ((byte)*(undefined2 *)(lVar19 + 0x124) & 0x1f) |
             *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x126)) &
             *(uint *)(lVar19 + 0x120);
        lVar19 = *(long *)(piVar4 + 8);
      }
      if (*(int *)(lVar19 + 300) != 0) {
        *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x136)) =
             (uint)(byte)(bVar6 >> 7 ^ *(byte *)(lVar19 + 0x138)) <<
             ((byte)*(undefined2 *)(lVar19 + 0x134) & 0x1f) |
             *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x136)) &
             *(uint *)(lVar19 + 0x130);
        lVar19 = *(long *)(piVar4 + 8);
      }
      local_228 = (byte)uVar20;
      if (*(int *)(lVar19 + 0x15c) != 0) {
        *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x166)) =
             (uint)(local_228 ^ *(byte *)(lVar19 + 0x168)) <<
             ((byte)*(undefined2 *)(lVar19 + 0x164) & 0x1f) |
             *(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x166)) &
             *(uint *)(lVar19 + 0x160);
        lVar19 = *(long *)(piVar4 + 8);
      }
      if (*(int *)(lVar19 + 0x16c) != 0) {
        puVar21 = (uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x176));
        *puVar21 = (uint)(local_228 ^ *(byte *)(lVar19 + 0x178)) <<
                   ((byte)*(undefined2 *)(lVar19 + 0x174) & 0x1f) |
                   *puVar21 & *(uint *)(lVar19 + 0x170);
        lVar19 = *(long *)(piVar4 + 8);
      }
    }
    else {
      lVar19 = kgmmuFmtGetFamily_IMPL(lVar3);
      if (lVar19 == 0) {
        nvAssertFailedNoLog("NULL != pFmtFamily",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x987);
        return 0x25;
      }
      portMemCopy(local_e8,local_1b8[2],lVar19 + 0x4c0,local_1b8[2]);
      lVar19 = *(long *)(piVar4 + 8);
    }
    if (*(byte *)(lVar19 + 0x24) != 0) {
      uVar17 = 0;
      do {
        if ((*(char *)(*(long *)(lVar19 + 0x28) + uVar17 * 2) != '\0') &&
           ((*(uint *)((long)local_e8 + (ulong)*(ushort *)(lVar19 + 0x22)) &
            *(uint *)(lVar19 + 0x18)) >> ((byte)*(undefined2 *)(lVar19 + 0x20) & 0x1f) ==
            (uint)*(byte *)(*(long *)(lVar19 + 0x28) + 1 + uVar17 * 2))) {
          local_140[0] = (int)uVar17;
          if (local_140[0] != 0) {
            local_d8 = gmmuFmtPtePhysAddrFld(lVar19,uVar17 & 0xffffffff,0);
          }
          goto LAB_003a2666;
        }
        uVar17 = uVar17 + 1;
      } while ((uint)uVar17 < (uint)*(byte *)(lVar19 + 0x24));
    }
    local_140[0] = 0;
LAB_003a2666:
    if ((param_8 & 0x2000000) == 0) {
      uVar24 = param_8 >> 0x17 & 1;
      if (bVar7 != 0) {
        uVar24 = 1;
      }
      iVar22 = (**(code **)(*plVar15 + 0x150))(plVar15,param_1,uVar14,uVar13,&local_1b8,uVar24);
      if (iVar22 != 0) {
        nvCheckFailedNoLog(4,"NV_OK == status",
                           "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x9f8);
      }
    }
    else {
      local_c0 = (undefined4 *)0x0;
      local_b8[0] = 0;
      local_b8[1] = 0;
      local_a8[0] = (ulong *)0x0;
      local_a8[1] = (ulong *)0x0;
      local_a8[2] = (ulong *)0x0;
      if (param_5 != 0) {
        local_178 = local_178 & 0xffffffff00000000;
        bVar7 = *local_1b8;
        uVar17 = (~(-1L << (local_1b8[1] + 1 & 0x3f)) & -1L << (bVar7 & 0x3f) & uVar14) >>
                 (bVar7 & 0x3f);
        iVar22 = (int)(uVar13 >> (bVar7 & 0x3f)) - (int)(uVar14 >> (bVar7 & 0x3f));
        local_c8 = param_5;
        local_b8[0] = param_1;
        _gmmuWalkCBMapNextEntries_Direct_isra_0
                  (&local_c0,&local_1b8,uVar17 & 0xffffffff,iVar22 + (int)uVar17,&local_178);
        if (iVar22 + 1 == (int)local_178) {
          iVar22 = 0;
        }
        else {
          iVar22 = 0;
          nvAssertFailedNoLog("progress == entryIndexHi - entryIndexLo + 1",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x9dc
                             );
        }
        goto LAB_003a1fae;
      }
      lVar19 = (**(code **)(plVar15[0x13] + 0x40))(plVar15[0x13],uVar14,0);
      if (lVar19 == 0) {
        nvAssertFailedNoLog("NULL != pMemBlock",
                            "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x9e6);
        return 0x1f;
      }
      iVar22 = gvaspaceWalkUserCtxAcquire_IMPL
                         (plVar15,param_1,*(undefined8 *)(lVar19 + 0x80),&local_c0);
      if (iVar22 == 0) {
        iVar22 = mmuWalkMap(*(undefined8 *)(local_b8[1] + 8),uVar14,uVar13,&local_1b8);
        if (iVar22 != 0) {
          nvAssertFailedNoLog("NV_OK == status",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x9ee
                             );
        }
        gvaspaceWalkUserCtxRelease_IMPL(plVar15,&local_c0);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar22,"gvaspaceWalkUserCtxAcquire(pGVAS, pGpu, pVASBlock, &userCtx)",
                   "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0x9e9);
      }
    }
  }
  else {
    iVar22 = 0;
    (**(code **)(*plVar15 + 0x158))(plVar15,param_1,uVar14,uVar13);
  }
  if ((param_5 == 0) && (param_17 == 0)) {
    (**(code **)(lVar1 + 0x500))(param_1,lVar1,3);
    (**(code **)(*plVar15 + 0x1b8))(plVar15,param_1,uVar20 ^ 1 | uVar23 | local_1dc);
  }
LAB_003a1fae:
  iVar10 = nvDbgRmMsgCheck("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xa06,
                           "dmaUpdateVASpace_GF100",1,0,0);
  if (iVar10 == 2) {
    local_178 = 0;
    local_170 = 0;
    local_b8[1] = param_7;
    local_a8[0] = &local_178;
    local_168 = 0;
    local_c0 = (undefined4 *)0x1;
    local_b8[0] = param_6;
    mmuTrace(param_1,param_3,&local_c0);
  }
  return iVar22;
}


// ===== 003a2f10 dmaInit_GM107 =====

undefined8 dmaInit_GM107(long param_1,long param_2)

{
  uint *puVar1;
  undefined8 uVar2;
  int local_1c;
  
  puVar1 = (uint *)addInfoPtr(param_2 + 0x1c8,0,8);
  if (puVar1 == (uint *)0x0) {
    return 0x51;
  }
  if ((*(char *)(param_1 + 0x908) != '\0') || (*(char *)(param_1 + 0x909) != '\0')) {
    *(undefined4 *)(param_1 + 0x493c) = 0;
  }
  puVar1[1] = 1;
  *puVar1 = (uint)(*puVar1 != 0);
  uVar2 = osReadRegistryDword(param_1,"RMRestrictVARange",&local_1c);
  if ((int)uVar2 == 0) {
    if (local_1c == 1) {
      *(undefined1 *)(param_2 + 0x1c1) = 1;
      return uVar2;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 003a2fc0 dmaDestruct_GM107 =====

void dmaDestruct_GM107(long param_1)

{
  deleteInfoPtr(param_1 + 0x1c8,0);
  return;
}


// ===== 003a2fe0 dmaStatePostLoad_GM107 =====

undefined8 dmaStatePostLoad_GM107(void)

{
  return 0;
}


// ===== 003a2ff0 dmaMapBuffer_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int dmaMapBuffer_GM107(long param_1,long param_2,long *param_3,long param_4,long *param_5,
                      uint param_6,uint param_7)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long *plVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  char cVar18;
  ulong uVar19;
  undefined1 local_94 [4];
  long local_90;
  undefined1 local_84 [4];
  byte local_80;
  undefined1 local_68 [56];
  
  lVar1 = *(long *)(param_1 + 0x1b70);
  lVar13 = *(long *)(param_1 + 0x1b78);
  lVar2 = *(long *)(param_1 + 0x1b98);
  lVar7 = (**(code **)(*param_3 + 0x90))(param_3);
  if (param_5 == (long *)0x0) {
    nvAssertFailedNoLog("pVaddr","src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",
                        0xa7d);
  }
  uVar8 = memdescGetMemDescFromGpu(param_4,param_1);
  iVar6 = (**(code **)(lVar13 + 0x388))(param_1,lVar13,uVar8,param_3[10],0);
  if (iVar6 == 0) {
    uVar9 = memdescGetPageSize(uVar8,param_3[10]);
    uVar10 = memdescGetPhysAddr(uVar8,param_3[10],0);
    iVar6 = memmgrGetKindComprFromMemDesc_IMPL(lVar13,param_4,0,local_94,local_84);
    if (iVar6 == 0) {
      uVar15 = uVar9 - 1;
      if ((*(char *)(lVar2 + 0x590) != '\0') && (0xffff < uVar9)) {
        if (uVar9 == 0x200000) {
          nvAssertFailedNoLog("pageSize != RM_PAGE_SIZE_HUGE",
                              "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xaa4
                             );
        }
        uVar9 = (**(code **)(*param_3 + 0xa0))(param_3);
      }
      local_90 = 0;
      uVar19 = 1L << (local_80 & 0x3f);
      uVar10 = ((uVar15 & uVar10) - 1) + *(long *)(param_4 + 0x30) + uVar9 & -uVar9;
      if (uVar19 < uVar9) {
        uVar19 = uVar9;
      }
      uVar15 = (uVar19 - 1) + uVar10 & -uVar19;
      if (((param_6 & 0x200) != 0) &&
         (uVar16 = uVar15 - 1, uVar16 = uVar16 >> 1 | uVar16, uVar16 = uVar16 >> 2 | uVar16,
         uVar16 = uVar16 >> 4 | uVar16, uVar16 = uVar16 >> 8 | uVar16,
         uVar16 = uVar16 >> 0x10 | uVar16, uVar16 = (uVar16 >> 0x20 | uVar16) + 1, uVar19 < uVar16))
      {
        uVar19 = uVar16;
      }
      uVar16 = (**(code **)(*param_3 + 0x58))(param_3);
      uVar17 = (**(code **)(*param_3 + 0x60))(param_3);
      if (((param_6 & 0x400) == 0) ||
         (lVar13 = __nvoc_dynamicCast(param_3,__nvoc_class_def_OBJGVASPACE), lVar13 == 0)) {
        cVar3 = *(char *)(param_2 + 0x1c5);
      }
      else {
        uVar16 = *(ulong *)(lVar13 + 0x138);
        uVar17 = *(ulong *)(lVar13 + 0x140);
        cVar3 = *(char *)(param_2 + 0x1c5);
      }
      if (cVar3 != '\0') {
        uVar14 = 0x100000000;
        if (0xffffffff < uVar16) {
          uVar14 = uVar16;
        }
        if (0x100000000 < *(ulong *)(lVar7 + 0x78)) {
          uVar16 = uVar14;
        }
      }
      if ((param_6 & 2) == 0) {
        if ((param_6 & 1) == 0) {
          uVar14 = 0xffffffffff;
          if (uVar17 < 0x10000000000) {
            uVar14 = uVar17;
          }
          if (*(char *)(param_2 + 0x1c1) != '\0') {
            uVar17 = uVar14;
          }
        }
        else if (0x1ffffffffffff < uVar17) {
          uVar17 = 0x1ffffffffffff;
        }
      }
      else if (0x1ffffffffffffff < uVar17) {
        uVar17 = 0x1ffffffffffffff;
      }
      iVar6 = (**(code **)(*param_3 + 0x38))(param_3,uVar15,uVar19,uVar16,uVar17,uVar9,0);
      if (iVar6 != 0) {
        nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xadd,
                     "dmaMapBuffer_GM107",4,"NVRM: vaspaceAlloc failed\n");
        return iVar6;
      }
      puVar11 = (undefined8 *)memdescGetMemDescFromGpu(param_4,param_1,&local_90);
      cVar3 = memdescGetContiguity(puVar11,param_3[10]);
      uVar15 = 1;
      if (cVar3 == '\0') {
        uVar15 = uVar10 >> 0xc & 0xffffffff;
      }
      uVar8 = memdescGetPteArrayForGpu(puVar11,*puVar11,param_3[10]);
      cVar18 = '\x01';
      dmaPageArrayInit(local_68,uVar8,uVar15);
      cVar3 = memdescGetFlag(puVar11,0x2000);
      iVar6 = memdescGetAddressSpace(puVar11);
      if (iVar6 != 2) {
        cVar18 = (*(int *)((long)puVar11 + 0x74) == 0) + '\x03';
      }
      uVar4 = (**(code **)(param_2 + 0x188))(param_2,puVar11,cVar18,0);
      cVar5 = (**(code **)(lVar1 + 0x228))(param_1,lVar1,uVar4,cVar18);
      if (cVar5 != '\0') {
        plVar12 = (long *)memdescGetRootMemDesc(puVar11,0);
        if ((*plVar12 != param_1) || (iVar6 = memdescGetAddressSpace(plVar12), iVar6 != 1)) {
          nvAssertFailedNoLog("pGpu == pRootMemDesc->pGpu && memdescGetAddressSpace(pRootMemDesc) == ADDR_SYSMEM"
                              ,"src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",
                              0xb03);
          goto LAB_003a3460;
        }
        *(undefined1 *)(plVar12 + 0x10) = 1;
      }
      iVar6 = (**(code **)(param_2 + 400))
                        (param_1,param_2,param_3,puVar11,0,local_90,local_90 + -1 + uVar10,
                         (uint)(cVar3 != '\0') << 0x1c | param_7 | 0x7ff,local_68,local_84,0,1,
                         cVar18,uVar4,0,0xffffffffffffffff,0,0,uVar9);
      if (iVar6 == 0) {
        if (param_5 == (long *)0x0) {
          return 0;
        }
        *param_5 = local_90;
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xb21,
                   "dmaMapBuffer_GM107",4,"NVRM: dmaUpdateVASpace_GF100 failed\n");
      (**(code **)(*param_3 + 0x40))(param_3,local_90);
    }
    else {
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xa9d,
                   "dmaMapBuffer_GM107",4,"NVRM: memmgrGetKindComprFromMemDesc failed\n");
    }
    iVar6 = 0xffff;
  }
  else {
LAB_003a3460:
    iVar6 = 0x1f;
  }
  return iVar6;
}


// ===== 003a3620 dmaUnmapBuffer_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void dmaUnmapBuffer_GM107(undefined8 param_1,undefined8 param_2,long *param_3,undefined8 param_4)

{
  if (param_3 != (long *)0x0) {
    (**(code **)(*param_3 + 0x40))(param_3,param_4);
    return;
  }
  nvAssertFailedNoLog("NULL != pVAS",
                      "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xb30);
  return;
}


// ===== 003a3660 dmaXlateVAtoPAforChannel_GM107 =====

undefined8
dmaXlateVAtoPAforChannel_GM107
          (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4,undefined8 *param_5
          ,undefined4 *param_6)

{
  undefined8 uVar1;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 *local_10;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xb87);
  }
  else if (param_5 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pAddr != NULL",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xb88);
  }
  else {
    if (param_6 != (undefined4 *)0x0) {
      local_10 = &local_40;
      local_40 = 0;
      local_38 = 0;
      local_30 = 0;
      local_28 = 2;
      local_20 = param_4;
      local_18 = param_4;
      uVar1 = mmuTrace(param_1,*(undefined8 *)(param_3 + 0x2a0),&local_28);
      if ((int)uVar1 == 0) {
        *param_6 = (undefined4)local_38;
        *param_5 = local_40;
      }
      return uVar1;
    }
    nvAssertFailedNoLog("memType != NULL",
                        "src/kernel/gpu/mem_mgr/arch/maxwell/virt_mem_allocator_gm107.c",0xb89);
  }
  return 0x1f;
}


// ===== 003a3750 dmaInitGart_GM107 =====

undefined8 dmaInitGart_GM107(long param_1,long param_2)

{
  long lVar1;
  short sVar2;
  
  lVar1 = *(long *)(param_1 + 7000);
  *(undefined4 *)(param_2 + 0x1b8) = 2;
  if (lVar1 == 0) {
    return 0;
  }
  sVar2 = kbifGetDmaCaps_IMPL(param_1,lVar1);
  if (sVar2 != 1) {
    return 0;
  }
  *(uint *)(param_2 + 0x1b8) = *(uint *)(param_2 + 0x1b8) | 1;
  return 0;
}


// ===== 003a37b0 dmaGetPTESize_GM107 =====

undefined8 dmaGetPTESize_GM107(void)

{
  return 8;
}


// ===== 003a37c0 memmgrChooseKindCompressC_GP100 =====

undefined8 memmgrChooseKindCompressC_GP100(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar1 = *param_3;
  uVar3 = uVar1 >> 4;
  if ((uVar1 & 7) != 4) {
    if ((uVar1 & 7) == 5) {
      if ((uVar1 & 0xc0) == 0) {
        if ((uVar3 & 0xe) != 0) {
          return 0x2d;
        }
      }
      else if ((uVar3 & 0xf) - 7 < 2) {
        return 0x2d;
      }
    }
LAB_003a37f1:
    uVar2 = memmgrChooseKindCompressC_GM107(param_1,param_2,param_3);
    return uVar2;
  }
  if ((uVar3 & 0xc) == 0) {
    if ((uVar3 & 0xe) == 0) {
      uVar2 = memmgrChooseKindCompressC_GM107(param_1,param_2,param_3);
      return uVar2;
    }
  }
  else if (1 < (uVar3 & 0xf) - 7) goto LAB_003a37f1;
  return 0x2c;
}


// ===== 003a3840 memmgrHandleSizeOverrides_GP100 =====

void memmgrHandleSizeOverrides_GP100(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  long local_30;
  long local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(ulong *)(param_2 + 0x830) <= *(ulong *)(param_2 + 0x848)) {
    return;
  }
  local_20 = 0;
  local_28 = (*(long *)(param_2 + 0x868) + 0xffffU & 0xffffffffffff0000) - 1;
  local_10 = 0;
  uVar2 = local_28 + (*(ulong *)(param_2 + 0x830) - *(ulong *)(param_2 + 0x848)) * -0x100000;
  local_18 = 1;
  if (*(ulong *)(param_2 + 0xb98) < uVar2) {
    uVar2 = *(ulong *)(param_2 + 0xb98);
  }
  local_30 = uVar2 + 1;
  uVar1 = memmgrInsertFbRegion_IMPL(param_1,param_2,&local_30);
  *(long *)(param_2 + 0xb98) = *(long *)(param_2 + 0x860 + (ulong)uVar1 * 0x28) + -1;
  return;
}


// ===== 003a38f0 memmgrFinishHandleSizeOverrides_GP100 =====

undefined8 memmgrFinishHandleSizeOverrides_GP100(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong local_30;
  ulong local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  if (*(long *)(param_2 + 0xb90) != 0) {
    if (*(int *)(param_2 + 0x858) != 0) {
      uVar2 = 0;
LAB_003a393a:
      do {
        lVar1 = param_2 + (ulong)uVar2 * 0x28;
        local_28 = *(ulong *)(lVar1 + 0x868);
        if (*(ulong *)(param_2 + 0xb98) < local_28) {
          local_30 = *(ulong *)(param_2 + 0xb98) + 1;
          if (*(ulong *)(lVar1 + 0x860) < local_30) {
            if (*(char *)(lVar1 + 0x878) == '\0') {
              local_20 = 0;
              local_10 = 0;
              local_18 = 1;
              iVar3 = memmgrInsertFbRegion_IMPL(param_1,param_2,&local_30);
              uVar2 = iVar3 + 1;
              if (*(uint *)(param_2 + 0x858) <= uVar2) goto LAB_003a39b5;
              goto LAB_003a393a;
            }
          }
          else {
            *(undefined1 *)(lVar1 + 0x878) = 1;
          }
        }
        uVar2 = uVar2 + 1;
        if (*(uint *)(param_2 + 0x858) <= uVar2) {
LAB_003a39b5:
          *(undefined8 *)(param_2 + 0xb90) = 0;
          return 0;
        }
      } while( true );
    }
    *(undefined8 *)(param_2 + 0xb90) = 0;
  }
  return 0;
}


// ===== 003a39e0 memmgrGetMaxContextSize_GP100 =====

void memmgrGetMaxContextSize_GP100(void)

{
  memmgrGetMaxContextSize_GM200();
  return;
}


// ===== 003a39f0 memmgrScrubHandlePostSchedulingEnable_GP100 =====

ulong memmgrScrubHandlePostSchedulingEnable_GP100(long param_1,long param_2)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  ulong uVar4;
  bool bVar5;
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x1b78) + 0x478);
  bVar5 = false;
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    cVar2 = kmigmgrIsMIGEnabled_IMPL();
    bVar5 = cVar2 != '\0';
  }
  if ((*(char *)(param_1 + 0x443) == '\0') && (*(char *)(param_2 + 0x480) != '\0')) {
    if ((*(char *)(param_2 + 0x434) != '\0') &&
       (((!bVar5 || (*(char *)(param_1 + 0x908) == '\0')) &&
        (uVar3 = scrubberConstruct(param_1,uVar1), uVar3 != 0)))) {
      nvAssertOkFailedNoLog
                (uVar3,"scrubberConstruct(pGpu, pHeap)",
                 "src/kernel/gpu/mem_mgr/arch/pascal/mem_mgr_scrub_gp100.c",0x42);
      return (ulong)uVar3;
    }
    if (*(char *)(param_2 + 0x43f) != '\0') {
      uVar4 = __nvoc_objCreate_SysmemScrubber(param_2 + 0x4b0,param_2,0,param_1);
      if ((int)uVar4 == 0) {
        return uVar4;
      }
      nvAssertOkFailedNoLog
                (uVar4 & 0xffffffff,
                 "objCreate(&pMemoryManager->pSysmemScrubber, pMemoryManager, SysmemScrubber, pGpu)"
                 ,"src/kernel/gpu/mem_mgr/arch/pascal/mem_mgr_scrub_gp100.c",0x47);
      return uVar4 & 0xffffffff;
    }
  }
  return 0;
}


// ===== 003a3b00 memmgrScrubHandlePreSchedulingDisable_GP100 =====

undefined8 memmgrScrubHandlePreSchedulingDisable_GP100(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  bool bVar4;
  bool bVar5;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x1b78) + 0x478);
  if (*(long *)(param_1 + 0x1bc0) == 0) {
    bVar4 = false;
    bVar5 = false;
  }
  else {
    cVar3 = kmigmgrIsMIGEnabled_IMPL();
    bVar4 = cVar3 != '\0';
    if (*(long *)(param_1 + 0x1bc0) == 0) {
      bVar5 = false;
    }
    else {
      cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
      bVar5 = cVar3 != '\0';
    }
  }
  if (*(char *)(param_2 + 0x480) != '\0') {
    uVar2 = *(undefined8 *)(param_2 + 0x4b0);
    *(undefined8 *)(param_2 + 0x4b0) = 0;
    __nvoc_objDelete(uVar2);
    if (lVar1 == 0) {
      return 0xffff;
    }
    if (bVar5) {
      return 0x10005;
    }
    if ((*(char *)(param_2 + 0x434) != '\0') && ((!bVar4 || (*(char *)(param_1 + 0x908) == '\0'))))
    {
      scrubberDestruct(param_1,lVar1);
    }
  }
  return 0;
}


// ===== 003a3bf0 memmgrAllocateConsoleRegion_T234D =====

int memmgrAllocateConsoleRegion_T234D(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar1 = *(long *)(param_2 + 0xb40);
  lVar2 = *(long *)(param_2 + 0xb38);
  if ((lVar1 != 0) && (lVar2 != 0)) {
    iVar3 = memdescCreate(param_2 + 0xb60,param_1,lVar2,0x1000,1,1,1,0x80000000020000);
    if (iVar3 != 0) {
      return iVar3;
    }
    memdescDescribe(*(undefined8 *)(param_2 + 0xb60),1,lVar1,lVar2);
    memdescSetPageSize(*(undefined8 *)(param_2 + 0xb60),0,0x1000);
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/t23x/mem_mgr_t234d.c",0x46,
                 "memmgrAllocateConsoleRegion_T234D",1,
                 "NVRM: Allocating console region of size: %llx, at base : %llx \n ",lVar2,lVar1);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/t23x/mem_mgr_t234d.c",0x2c,
               "memmgrAllocateConsoleRegion_T234D",1,"NVRM: No Frame Buffer Present\n");
  return 0;
}


// ===== 003a3d30 memmgrChooseKindZ_TU102 =====

int memmgrChooseKindZ_TU102(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *param_3;
  uVar2 = uVar1 >> 0x13 & 7;
  if (((uVar1 & 7) != 1) || (iVar3 = 2, uVar2 != 0)) {
    if ((uVar1 & 0x40000) == 0) {
      if (uVar2 != 4) {
        if (4 < uVar2) {
          iVar3 = 7;
          if (uVar2 == 7) {
            iVar3 = 1;
          }
          return iVar3;
        }
        if (uVar2 != 1) {
          return (-(uint)((0xfffffffffffffff6U >> uVar2 & 1) == 0) & 0xfffffffe) + 7;
        }
      }
      iVar3 = 3;
    }
    else {
      iVar3 = 6;
      if (uVar2 != 2) {
        return (uint)(uVar2 != 5) * 3 + 4;
      }
    }
  }
  return iVar3;
}


// ===== 003a3dd0 memmgrChooseKindCompressZ_TU102 =====

char memmgrChooseKindCompressZ_TU102(undefined8 param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  uVar1 = *param_3;
  uVar2 = uVar1 >> 0x13 & 7;
  if (((uVar1 & 7) != 1) || (cVar3 = '\n', uVar2 != 0)) {
    if ((uVar1 & 0x40000) == 0) {
      if (uVar2 != 4) {
        if (4 < uVar2) {
          return (uVar2 == 7) * '\x04' + '\a';
        }
        if (uVar2 != 1) {
          return (-((0xfffffffffffffff6U >> uVar2 & 1) == 0) & 7U) + 7;
        }
      }
      cVar3 = '\f';
    }
    else {
      cVar3 = '\t';
      if (uVar2 != 2) {
        cVar3 = '\a';
        if (uVar2 == 5) {
          cVar3 = '\r';
        }
        return cVar3;
      }
    }
  }
  return cVar3;
}


// ===== 003a3e70 memmgrChooseKind_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
memmgrChooseKind_TU102(long param_1,long param_2,undefined4 *param_3,int param_4,int *param_5)

{
  char cVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  code *pcVar5;
  
  lVar3 = kmemsysGetStaticConfig_IMPL(param_1,*(undefined8 *)(param_1 + 0x1b70));
  if (((*(char *)(param_1 + 0x484) == '\0') || ((*(byte *)((long)param_3 + 0xb) & 0x10) != 0)) ||
     (cVar1 = hypervisorIsVgxHyper_IMPL(), cVar1 != '\0')) {
    if ((uint)param_3[4] < 0x12) {
      uVar4 = 1L << ((byte)param_3[4] & 0x3f);
      if ((uVar4 & 0x2fd6d) != 0) {
        if ((param_4 != 0) && (*(char *)(lVar3 + 3) == '\0')) {
          if ((param_4 != 3) && (*(char *)(lVar3 + 4) == '\0')) {
            *param_5 = 8;
            return 0;
          }
          *param_5 = 9;
          return 0;
        }
LAB_003a3f38:
        *param_5 = 6;
        return 0;
      }
      if ((uVar4 & 0x10002) != 0) {
        if (param_4 == 0) goto LAB_003a4028;
        pcVar5 = *(code **)(param_2 + 0x278);
LAB_003a3ef0:
        iVar2 = (*pcVar5)(param_1,param_2,param_3);
        goto LAB_003a3f01;
      }
    }
  }
  else {
    iVar2 = param_3[3];
    if ((param_4 != 0) || (cVar1 = (**(code **)(param_2 + 0x2a8))(param_2,5,iVar2), cVar1 == '\0'))
    {
LAB_003a3f01:
      *param_5 = iVar2;
      if (iVar2 != 7) {
        return 0;
      }
      goto LAB_003a3fe7;
    }
    nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/turing/mem_mgr_tu102.c",0xdc,"memmgrChooseKind_TU102",
                 4,
                 "NVRM: Client sets a compressible PTE kind 0x%x, while sets NVOS32_ATTR_COMPR_NONE. RM will ignore the PTE kind from client and choose an uncompressible kind instead.\n"
                );
    if ((uint)param_3[4] < 0x12) {
      uVar4 = 1L << ((byte)param_3[4] & 0x3f);
      if ((uVar4 & 0x2fd6d) != 0) goto LAB_003a3f38;
      if ((uVar4 & 0x10002) != 0) {
LAB_003a4028:
        pcVar5 = *(code **)(param_2 + 0x270);
        goto LAB_003a3ef0;
      }
    }
  }
  *param_5 = 7;
LAB_003a3fe7:
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/turing/mem_mgr_tu102.c",0x11d,"memmgrChooseKind_TU102",4
               ,
               "NVRM: Unable to set a kind, dumping attributes:comprAttr = 0x%x, type = 0x%x, attr = 0x%x\n"
               ,param_4,param_3[4],*param_3);
  return 0;
}


// ===== 003a4050 memmgrGetUncompressedKind_TU102 =====

uint memmgrGetUncompressedKind_TU102
               (undefined8 param_1,undefined8 param_2,uint param_3,char param_4)

{
  uint uVar1;
  
  if ((param_4 != '\0') && (param_3 != 10)) {
    return 6;
  }
  if (param_3 != 6) {
    if (6 < param_3) {
      if (param_3 == 0xc) {
        return 3;
      }
      if (param_3 < 0xd) {
        uVar1 = 2;
        if ((param_3 == 10) || (uVar1 = 1, param_3 == 0xb)) {
          return uVar1;
        }
        if (param_3 - 8 < 2) {
          return 6;
        }
      }
      else {
        if (param_3 == 0xd) {
          return 4;
        }
        if (param_3 == 0xe) {
          return 5;
        }
      }
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/turing/mem_mgr_tu102.c",0x15b,
                   "memmgrGetUncompressedKind_TU102",4,"NVRM: Unknown kind 0x%x.\n",param_3);
      return 7;
    }
    if (param_3 != 2) {
      if (param_3 < 3) {
        return (uint)(param_3 != 0);
      }
      if (param_3 != 4) {
        return (param_3 == 5) + 3 + (uint)(param_3 == 5);
      }
    }
  }
  return param_3;
}


// ===== 003a4130 memmgrGetCompressedKind_TU102 =====

uint memmgrGetCompressedKind_TU102(undefined8 param_1,uint param_2,char param_3)

{
  uint uVar1;
  
  if (9 < param_2) {
    if (param_2 != 0xc) {
      if (param_2 < 0xd) {
        return (param_2 != 10) + 10;
      }
      if ((param_2 != 0xd) && (param_2 != 0xe)) goto LAB_003a41b8;
    }
    return param_2;
  }
  if (7 < param_2) {
LAB_003a41a7:
    return 9 - (param_3 == '\0');
  }
  if (param_2 == 4) {
    return 0xd;
  }
  if (param_2 < 5) {
    uVar1 = 10;
    if (((param_2 != 2) && (uVar1 = 0xc, param_2 != 3)) && (uVar1 = 0xb, param_2 != 1)) {
LAB_003a41b8:
      nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/turing/mem_mgr_tu102.c",0x183,
                   "memmgrGetCompressedKind_TU102",4,"NVRM: Unknown kind 0x%x.\n",param_2);
      return 7;
    }
  }
  else {
    uVar1 = 0xe;
    if (param_2 != 5) {
      if (param_2 == 6) goto LAB_003a41a7;
      goto LAB_003a41b8;
    }
  }
  return uVar1;
}


// ===== 003a4200 memmgrGetMessageKind_TU102 =====

undefined8 memmgrGetMessageKind_TU102(void)

{
  return 0xf;
}


// ===== 003a4210 memmgrGetDefaultPteKindForNoHandle_TU102 =====

undefined8 memmgrGetDefaultPteKindForNoHandle_TU102(void)

{
  return 6;
}


// ===== 003a4220 memmgrIsKindCompressible_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void memmgrIsKindCompressible_TU102(long param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x2a8))(param_1,5,param_2);
  return;
}


// ===== 003a4240 memmgrGetCtagOffsetFromParams_TU102 =====

uint memmgrGetCtagOffsetFromParams_TU102(undefined8 param_1,undefined8 param_2,long param_3)

{
  return *(uint *)(param_3 + 0xa4) & 0xfffff;
}


// ===== 003a4250 memmgrSetCtagOffsetInParams_TU102 =====

undefined8
memmgrSetCtagOffsetInParams_TU102(undefined8 param_1,undefined8 param_2,long param_3,uint param_4)

{
  undefined8 uVar1;
  
  if (param_4 < 0x100000) {
    *(uint *)(param_3 + 0xa4) = *(uint *)(param_3 + 0xa4) & 0xfff00000 | param_4;
    uVar1 = nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/turing/mem_mgr_tu102.c",0x1e5,
                         "memmgrSetCtagOffsetInParams_TU102",1,
                         "NVRM: Setting ctag offset before allocating: %x\n");
    return uVar1;
  }
  nvDbg_Printf("src/kernel/gpu/mem_mgr/arch/turing/mem_mgr_tu102.c",0x1ea,
               "memmgrSetCtagOffsetInParams_TU102",4,
               "NVRM: - comptagline offset is outside the bounds, offset: %x, limit:%x.\n",param_4);
  return 0x100000;
}


// ===== 003a42e0 memmgrDetermineComptag_TU102 =====

int memmgrDetermineComptag_TU102(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  return ((uint)((ulong)param_3 >> 0x10) & 0xfffff) + 1;
}


// ===== 003a4300 memmgrGetHwPteKindFromSwPteKind_TU102 =====

int memmgrGetHwPteKindFromSwPteKind_TU102(undefined8 param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 6;
  if (param_3 != 0x100) {
    iVar1 = param_3;
  }
  return iVar1;
}


// ===== 003a4320 memmgrGetSwPteKindFromHwPteKind_TU102 =====

int memmgrGetSwPteKindFromHwPteKind_TU102(undefined8 param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0x100;
  if (param_3 != 6) {
    iVar1 = param_3;
  }
  return iVar1;
}


// ===== 003a4330 memmgrGetPteKindForScrubber_TU102 =====

void memmgrGetPteKindForScrubber_TU102(undefined8 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 9;
  }
  return;
}


// ===== 003a4340 memmgrGetMaxContextSize_TU102 =====

void memmgrGetMaxContextSize_TU102(void)

{
  memmgrGetMaxContextSize_GV100();
  return;
}


