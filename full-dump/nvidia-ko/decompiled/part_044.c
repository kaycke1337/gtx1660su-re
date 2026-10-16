// ===== 004e1d60 kvgpumgrGetHostVgpuDeviceFromVgpuDevName =====

undefined8 kvgpumgrGetHostVgpuDeviceFromVgpuDevName(int param_1,undefined8 param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  iVar2 = osIsVgpuVfioPresent();
  if (iVar2 != 0) {
    return 0x56;
  }
  uVar6 = 0;
  piVar3 = (int *)(lVar1 + 0x48);
  while ((param_1 != *piVar3 || ((char)piVar3[0x18e] != '\x01'))) {
    uVar5 = (int)uVar6 + 1;
    uVar6 = (ulong)uVar5;
    piVar3 = piVar3 + 0x2eee0;
    if (uVar5 == 0x20) {
      return 0x57;
    }
  }
  lVar1 = lVar1 + 600 + uVar6 * 0xbbb80;
  lVar4 = listHead_IMPL(lVar1);
  while( true ) {
    if (lVar4 == 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xb95,
                   "kvgpumgrGetHostVgpuDeviceFromVgpuDevName",4,"NVRM: Object not found\n");
      return 0x57;
    }
    if (*(long *)(lVar4 + 0x2e0) == 0) break;
    iVar2 = portMemCmp(*(long *)(lVar4 + 0x2e0) + 4,param_2,0x10);
    if (iVar2 == 0) {
      *param_3 = lVar4;
      return 0;
    }
    lVar4 = listNext_IMPL(lVar1,lVar4);
  }
  return 0x3d;
}


// ===== 004e1ea0 kvgpumgrSetSupportedPlacementIds =====

undefined8 kvgpumgrSetSupportedPlacementIds(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  char cVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  int *piVar12;
  long lVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  short sVar19;
  ulong uVar20;
  uint uVar21;
  ulong uVar22;
  ushort uVar24;
  int iVar25;
  ulong uVar26;
  uint uVar27;
  int iVar28;
  ulong uVar29;
  long lVar30;
  ulong uVar31;
  long lVar32;
  ulong uVar33;
  long lVar34;
  long lVar35;
  long local_88;
  ulong local_58;
  long local_50;
  long local_48;
  long local_40 [2];
  ulong uVar23;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  lVar11 = gpuGetKernelFifoShared_IMPL();
  uVar22 = 0;
  piVar12 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar12 || ((char)piVar12[0x18e] != '\x01'))) {
    uVar27 = (int)uVar22 + 1;
    uVar22 = (ulong)uVar27;
    piVar12 = piVar12 + 0x2eee0;
    if (uVar27 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0xe68);
      return 0x57;
    }
  }
  lVar34 = *(long *)(param_1 + 0x1b78);
  lVar18 = *(long *)(lVar34 + 0x478);
  *(undefined2 *)(lVar1 + 0xbb839 + uVar22 * 0xbbb80) = 0;
  if ((*(char *)(param_1 + 0x491d) == '\0') ||
     ((iVar10 = osIsVgpuVfioPresent(), iVar10 != 0 &&
      (iVar10 = osIsVgpuDeviceVmPresent(), iVar10 != 0)))) {
    cVar5 = rmcfg_IsADA_CLASSIC_GPUSorBetter(param_1);
  }
  else {
    *(undefined1 *)(lVar1 + 0xbb839 + uVar22 * 0xbbb80) = 1;
    cVar5 = rmcfg_IsADA_CLASSIC_GPUSorBetter(param_1);
  }
  if ((cVar5 == '\0') ||
     ((iVar10 = osIsVgpuVfioPresent(), iVar10 != 0 &&
      (iVar10 = osIsVgpuDeviceVmPresent(), iVar10 != 0)))) {
    lVar13 = uVar22 * 0xbbb80 + lVar1;
    if ((*(char *)(lVar13 + 0xbb839) == '\0') && (*(char *)(lVar13 + 0xbb83a) == '\0')) {
      return 0;
    }
  }
  else {
    *(undefined1 *)(lVar1 + 0xbb83a + uVar22 * 0xbbb80) = 1;
  }
  lVar30 = uVar22 * 0xbbb80;
  lVar13 = lVar1 + lVar30;
  if (*(char *)(lVar13 + 0xbbb98) == '\0') {
    uVar7 = kfifoChidMgrGetNumChannels_IMPL(param_1,lVar11,**(undefined8 **)(lVar11 + 0x368));
    uVar27 = 0;
    if (*(int *)(lVar13 + 0x250) != 0) {
      lVar11 = lVar1 + 0xbbba0 + lVar30;
      lVar35 = 0;
      uVar27 = 0;
      lVar32 = lVar13;
      do {
        puVar2 = *(undefined4 **)(lVar13 + 0x280 + lVar35 * 8);
        if (puVar2 == (undefined4 *)0x0) break;
        uVar8 = vgpuMgrGetPlacementRegionSize(param_1,lVar11,puVar2);
        puVar14 = puVar2 + 99;
        do {
          puVar15 = puVar14 + 2;
          *(undefined2 *)puVar14 = 0xffff;
          *(undefined2 *)(puVar14 + 1) = 0xffff;
          puVar14 = puVar15;
        } while (puVar15 != puVar2 + 0xc3);
        if ((puVar2[0xcc] == 0) || (*(char *)(param_1 + 0x46b) != '\0')) {
          puVar2[0xc3] = 0;
          *(undefined4 *)(lVar32 + 0x5f08) = 0;
          iVar10 = (int)(*(ulong *)(puVar2 + 0xd2) >> 0x1e);
          if ((uVar8 == 0x60) && (iVar10 == 2)) {
            iVar10 = 3;
          }
          puVar2[0x61] = iVar10;
          if (*(char *)(param_1 + 0x491d) == '\0') {
LAB_004e21c8:
            iVar10 = puVar2[0xc4];
          }
          else {
            if (puVar2[0xcc] == 0) {
              uVar9 = puVar2[0xc4];
            }
            else {
              uVar9 = puVar2[0xe3];
            }
            if (*(char *)(param_1 + 0x491f) == '\0') {
              uVar9 = (uint)((ulong)uVar7 / (ulong)uVar9) | (uint)((ulong)uVar7 / (ulong)uVar9 >> 1)
              ;
              uVar9 = uVar9 >> 2 | uVar9;
              uVar9 = uVar9 >> 4 | uVar9;
              uVar9 = uVar9 >> 8 | uVar9;
              uVar9 = uVar9 >> 0x10 | uVar9;
              uVar21 = uVar9 >> 1;
              uVar23 = (ulong)uVar21;
              uVar9 = uVar9 - uVar21;
            }
            else {
              uVar9 = (iVar10 * uVar7) / uVar8;
              uVar23 = (ulong)(iVar10 * uVar7) % (ulong)uVar8;
            }
            puVar2[0x62] = uVar9;
            if (*(char *)(param_1 + 0x909) == '\0') {
              lVar16 = memmgrGetVgpuHostRmReservedFb_KERNEL(param_1,lVar34,*puVar2);
              lVar17 = kvgpumgrGetEccAndPrReservedFb(param_1);
              uVar23 = *(ulong *)(param_1 + 0x3b10);
              uVar20 = (uVar23 - 1) + (ulong)(lVar17 + lVar16) / (ulong)(uint)puVar2[0xc4] & -uVar23
              ;
              if (*(long *)(puVar2 + 0xd2) == 0x40000000) {
                heapGetUsableSize_IMPL(lVar18,&local_58);
                uVar23 = *(ulong *)(param_1 + 0x3b10);
                uVar33 = 0;
                if (local_58 <= (ulong)(uint)puVar2[0xc4] * (uVar20 + 0x40000000)) {
                  uVar33 = uVar20;
                }
                uVar20 = *(long *)(puVar2 + 0xd2) - uVar33;
              }
              else {
                uVar20 = *(long *)(puVar2 + 0xd2) - uVar20;
              }
LAB_004e21bb:
              *(int *)(lVar32 + 0x5f08) = (int)(uVar20 / uVar23);
              goto LAB_004e21c8;
            }
            cVar5 = rmcfg_IsGB100orBetter(param_1,uVar8,uVar23);
            uVar33 = *(ulong *)(puVar2 + 0xd4);
            uVar23 = *(ulong *)(param_1 + 0x3b10);
            if (cVar5 == '\0') {
              local_58 = uVar23 * 8 + -1 + *(long *)(lVar34 + 0x830) * 0x100000 & uVar23 * -8;
              uVar20 = (local_58 / (uint)puVar2[0xc4] - *(long *)(puVar2 + 0xd6)) -
                       *(long *)(puVar2 + 0xd8);
              if (uVar33 < uVar20) {
                uVar20 = uVar33;
              }
              uVar20 = -uVar23 & uVar20;
              goto LAB_004e21bb;
            }
            *(int *)(lVar32 + 0x5f08) = (int)(uVar33 / uVar23);
            iVar10 = puVar2[0xc4];
          }
          if (iVar10 == 1) {
            uVar6 = vgpuMgrGetPlacementRegionSize(param_1,lVar11,puVar2);
            *(undefined2 *)(lVar1 + 0x29e88 + lVar30) = uVar6;
            if (((*(char *)(param_1 + 0x491d) != '\0') &&
                (uVar8 = *(uint *)(lVar32 + 0x5f08), uVar8 != 0)) &&
               (uVar27 = uVar8, *(char *)(param_1 + 0x909) != '\0')) {
              uVar27 = uVar8 + (int)(*(ulong *)(puVar2 + 0xd6) / *(ulong *)(param_1 + 0x3b10));
            }
          }
        }
        else {
          puVar2[0x61] = 0;
        }
        lVar35 = lVar35 + 1;
        lVar32 = lVar32 + 0x488;
      } while ((uint)lVar35 < *(uint *)(lVar1 + 0x250 + lVar30));
    }
    if (*(char *)(param_1 + 0x491d) != '\0') {
      lVar11 = lVar1 + 0x48 + lVar30;
      pmaGetLargestFree(*(undefined8 *)(lVar18 + 0x128),&local_50,&local_48,local_40);
      uVar23 = *(ulong *)(param_1 + 0x3b10);
      uVar33 = local_40[0] + local_48 + -1 + uVar23 & -uVar23;
      uVar20 = uVar27 * uVar23;
      if ((local_40[0] + local_48 + local_50) - uVar33 < uVar20) {
        nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xf28,
                     "kvgpumgrSetSupportedPlacementIds",4,
                     "NVRM: Required FB for heterogeneous vGPU (%llu) less than available FB (%llu)\n"
                     ,uVar20,local_50);
        nvAssertFailedNoLog(&DAT_00da00f9,"src/kernel/virtualization/kernel_vgpu_mgr.c",0xf2a);
        *(undefined1 *)(lVar1 + 0xbb839 + uVar22 * 0xbbb80) = 0;
        uVar20 = uVar33 / *(ulong *)(param_1 + 0x3b10);
      }
      else {
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar23;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar33;
        uVar20 = SUB168(auVar4 / auVar3,0);
        lVar34 = lVar1 + uVar22 * 0xbbb80;
        if (*(char *)(lVar34 + 0xbb839) != '\0') {
          cVar5 = rmcfg_IsGB100orBetter(param_1,uVar23,uVar33 % uVar23);
          iVar10 = SUB164(auVar4 / auVar3,0);
          if (cVar5 == '\0') {
            _kvgpumgrSetHeterogeneousResources_constprop_0
                      (param_1,lVar11,0,*(undefined2 *)(lVar34 + 0x29e88),0,uVar7,uVar20,
                       uVar27 + uVar20,0,0,1);
          }
          else {
            lVar18 = _kvgpumgrGetMaxTotalGspHeapSize(param_1,lVar11,0);
            if (*(int *)(lVar34 + 0x250) != 0) {
              uVar23 = *(ulong *)(param_1 + 0x3b10);
              uVar33 = 0;
              iVar28 = uVar27 - (int)(((uVar23 - 1) + lVar18) / uVar23);
              local_88 = lVar11;
              do {
                lVar34 = *(long *)(lVar13 + 0x280 + uVar33 * 8);
                if (lVar34 == 0) break;
                if (*(int *)(lVar34 + 0x184) != 0) {
                  *(undefined2 *)(lVar34 + 0x30c) = 0;
                  if ((*(char *)(param_1 + 0x46b) == '\0') || (*(int *)(lVar34 + 0x330) == 0)) {
                    uVar27 = *(uint *)(lVar34 + 0x310);
                  }
                  else {
                    uVar27 = *(uint *)(lVar34 + 0x38c);
                  }
                  uVar8 = vgpuMgrGetPlacementRegionSize(param_1,lVar1 + 0xbbba0 + lVar30,lVar34);
                  if (uVar27 != 0) {
                    uVar31 = 0;
                    uVar29 = 0;
                    lVar32 = local_88;
                    do {
                      *(short *)(lVar34 + 0x18c + uVar29 * 8) = (short)(uVar31 / uVar27);
                      uVar26 = uVar31 / uVar27 & 0xffff;
                      iVar25 = (int)uVar26;
                      *(short *)(lVar34 + 0x18e + uVar29 * 8) = (short)((uVar7 * iVar25) / uVar8);
                      *(short *)(lVar34 + 0x30c) = *(short *)(lVar34 + 0x30c) + 1;
                      if (*(int *)(lVar34 + 0x330) == 0) {
                        if (uVar27 == 1) {
                          lVar34 = (uVar33 & 0xffffffff) * 0x488 + (uVar29 & 0xffffffff) * 0x18 +
                                   lVar11;
                          *(int *)(lVar34 + 0x5a44) = iVar10;
                          *(ulong *)(lVar34 + 0x5a48) =
                               (uint)(iVar10 + *(int *)(local_88 + 0x5ec0)) * uVar23;
                          break;
                        }
                        *(uint *)(lVar32 + 0x5a44) = (uint)(iVar28 * iVar25) / uVar8 + iVar10;
                        *(ulong *)(lVar32 + 0x5a48) =
                             ((uVar26 * lVar18) / (ulong)uVar8 & 0xffffffffffe00000) +
                             (uint)(iVar28 + iVar10) * uVar23;
                      }
                      uVar29 = uVar29 + 1;
                      uVar31 = (ulong)((int)uVar31 + uVar8);
                      lVar32 = lVar32 + 0x18;
                    } while (uVar29 != uVar27);
                  }
                }
                local_88 = local_88 + 0x488;
                uVar33 = uVar33 + 1;
              } while ((uint)uVar33 < *(uint *)(lVar1 + 0x250 + uVar22 * 0xbbb80));
            }
          }
        }
      }
      lVar34 = uVar22 * 0xbbb80 + lVar1;
      if (*(char *)(lVar34 + 0xbb83a) != '\0') {
        cVar5 = rmcfg_IsGB100orBetter();
        if (cVar5 == '\0') {
          if ((*(char *)(lVar34 + 0xbb83a) != '\0') && (*(int *)(lVar34 + 0x250) != 0)) {
            lVar30 = 0;
            lVar18 = lVar11;
            do {
              lVar32 = *(long *)(lVar13 + 0x280 + lVar30 * 8);
              uVar27 = *(uint *)(lVar32 + 0x184);
              if (uVar27 != 0) {
                if (*(ushort *)(lVar11 + 0x29e40) < uVar27) {
                  uVar24 = *(ushort *)(lVar32 + 0x30e);
                }
                else {
                  uVar9 = *(ushort *)(lVar11 + 0x29e40) / uVar27;
                  lVar16 = 0;
                  lVar35 = lVar18;
                  uVar8 = uVar7;
                  while( true ) {
                    *(short *)(lVar32 + 400 + lVar16 * 8) = (short)uVar27 * (short)lVar16;
                    *(int *)(lVar35 + 0x5a50) =
                         *(int *)(lVar18 + 0x5ec0) * (int)lVar16 + (int)uVar20;
                    iVar10 = *(int *)(lVar32 + 0x188);
                    *(short *)(lVar32 + 0x192 + lVar16 * 8) = (short)uVar8 - (short)iVar10;
                    uVar24 = *(short *)(lVar32 + 0x30e) + 1;
                    *(ushort *)(lVar32 + 0x30e) = uVar24;
                    if (((uint)uVar24 == *(uint *)(lVar32 + 0x310)) ||
                       (lVar16 = lVar16 + 1, uVar9 <= (uint)lVar16)) break;
                    uVar27 = *(uint *)(lVar32 + 0x184);
                    lVar35 = lVar35 + 0x18;
                    uVar8 = uVar8 - iVar10;
                  }
                }
                if (uVar24 != 0) {
                  lVar16 = 0;
                  lVar35 = lVar18;
                  do {
                    lVar17 = lVar16 * 8;
                    lVar16 = lVar16 + 1;
                    *(undefined2 *)(lVar35 + 0x5a40) = *(undefined2 *)(lVar32 + 400 + lVar17);
                    lVar35 = lVar35 + 0x18;
                  } while ((uint)lVar16 < (uint)*(ushort *)(lVar32 + 0x30e));
                }
              }
              lVar30 = lVar30 + 1;
              lVar18 = lVar18 + 0x488;
            } while ((uint)lVar30 < *(uint *)(lVar34 + 0x250));
          }
        }
        else if (*(char *)(lVar34 + 0xbb839) == '\0') {
          *(undefined1 *)(lVar34 + 0xbb83a) = 0;
          nvAssertFailedNoLog("pPgpuInfo->homogeneousPlacementSupported",
                              "src/kernel/virtualization/kernel_vgpu_mgr.c",0xe0c);
        }
        else {
          lVar18 = 0;
          if (*(int *)(lVar34 + 0x250) != 0) {
            do {
              lVar30 = *(long *)(lVar13 + 0x280 + lVar18 * 8);
              if (lVar30 == 0) break;
              if ((*(int *)(lVar30 + 0x184) != 0) &&
                 (*(undefined2 *)(lVar30 + 0x30e) = 0, *(short *)(lVar30 + 0x30c) != 0)) {
                lVar35 = 0;
                lVar32 = lVar11;
                do {
                  *(undefined4 *)(lVar30 + 400 + lVar35 * 8) =
                       *(undefined4 *)(lVar30 + 0x18c + lVar35 * 8);
                  lVar35 = lVar35 + 1;
                  *(undefined4 *)(lVar32 + 0x5a50) = *(undefined4 *)(lVar32 + 0x5a44);
                  sVar19 = *(short *)(lVar30 + 0x30e) + 1;
                  *(short *)(lVar30 + 0x30e) = sVar19;
                  lVar32 = lVar32 + 0x18;
                } while ((uint)lVar35 < (uint)*(ushort *)(lVar30 + 0x30c));
                if (sVar19 != 0) {
                  lVar35 = 0;
                  lVar32 = lVar11;
                  do {
                    lVar16 = lVar35 * 8;
                    lVar35 = lVar35 + 1;
                    *(undefined2 *)(lVar32 + 0x5a40) = *(undefined2 *)(lVar30 + 400 + lVar16);
                    lVar32 = lVar32 + 0x18;
                  } while ((uint)lVar35 < (uint)*(ushort *)(lVar30 + 0x30e));
                }
              }
              lVar18 = lVar18 + 1;
              lVar11 = lVar11 + 0x488;
            } while ((uint)lVar18 < *(uint *)(lVar34 + 0x250));
          }
        }
      }
    }
    *(undefined1 *)(lVar1 + 0xbbb98 + uVar22 * 0xbbb80) = 1;
  }
  return 0;
}


// ===== 004e2a20 kvgpumgrGetConfigEventInfoFromDb =====

undefined8
kvgpumgrGetConfigEventInfoFromDb(int param_1,int param_2,undefined8 *param_3,uint param_4)

{
  long lVar1;
  int *piVar2;
  
  if (param_3 == (undefined8 *)0x0) {
    return 0x1f;
  }
  lVar1 = *(long *)(g_pSys + 0x1f8) + 0xbb810 + (ulong)param_4 * 0xbbb80;
  piVar2 = (int *)listHead_IMPL(lVar1);
  while( true ) {
    if (piVar2 == (int *)0x0) {
      *param_3 = 0;
      return 0x57;
    }
    if ((*piVar2 == param_1) && (piVar2[1] == param_2)) break;
    piVar2 = (int *)listNext_IMPL(lVar1);
  }
  *param_3 = piVar2;
  return 0;
}


// ===== 004e2ac0 kvgpuMgrRestoreSmcExecPart =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpuMgrRestoreSmcExecPart(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  long lVar7;
  undefined4 local_5c;
  int local_58;
  
  pcVar6 = (char *)(param_3 + 0x198);
  iVar5 = 0;
  lVar3 = rmapiGetInterface(4);
  do {
    if (*pcVar6 != '\0') {
      portMemSet(&local_5c,0,0x24);
      local_5c = 1;
      local_58 = iVar5;
      iVar2 = (**(code **)(lVar3 + 0x38))
                        (lVar3,*(undefined4 *)(param_3 + 0x9c0),*(undefined4 *)(param_3 + 0x9cc),
                         0xc6370102,&local_5c,0x24);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_DELETE, &params, sizeof(params))"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x11d5);
      }
    }
    iVar5 = iVar5 + 1;
    pcVar6 = pcVar6 + 0x110;
  } while (iVar5 != 8);
  lVar7 = param_2 + 0x550;
  puVar4 = (undefined4 *)portMemAllocNonPaged(0x60);
  if (puVar4 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pExecPartImportParams != NULL",
                        "src/kernel/virtualization/kernel_vgpu_mgr.c",0x11e0);
    return 0x51;
  }
  do {
    if (*(char *)(lVar7 + -8) != '\0') {
      portMemSet(puVar4,0,0x60);
      uVar1 = *(undefined4 *)(lVar7 + 0x50);
      *(undefined1 *)(puVar4 + 0x16) = 1;
      *puVar4 = uVar1;
      portMemCopy(puVar4 + 2,0x50,lVar7,0x50);
      iVar5 = (**(code **)(lVar3 + 0x38))
                        (lVar3,*(undefined4 *)(param_3 + 0x9c0),*(undefined4 *)(param_3 + 0x9cc),
                         0xc6370106,puVar4,0x60);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "pRmApi->Control(pRmApi, pKernelMIGGpuInstance->instanceHandles.hClient, pKernelMIGGpuInstance->instanceHandles.hSubscription, NVC637_CTRL_CMD_EXEC_PARTITIONS_IMPORT, pExecPartImportParams, sizeof(*pExecPartImportParams))"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x11ee);
        goto LAB_004e2c17;
      }
    }
    lVar7 = lVar7 + 0x68;
  } while (lVar7 != param_2 + 0x890);
  gpuNotifySubDeviceEvent_IMPL(param_1,0x9f,0,0,0,0);
  iVar5 = 0;
LAB_004e2c17:
  portMemFree(puVar4);
  return iVar5;
}


// ===== 004e2cc0 kvgpumgrGetHostVgpuDeviceFromVmId =====

undefined4 kvgpumgrGetHostVgpuDeviceFromVmId(int param_1,long param_2,long *param_3)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  iVar2 = osIsVgpuDeviceVmPresent();
  uVar6 = 0;
  piVar3 = (int *)(lVar1 + 0x48);
  if (iVar2 == 0) {
    while ((param_1 != *piVar3 || ((char)piVar3[0x18e] != '\x01'))) {
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulong)uVar5;
      piVar3 = piVar3 + 0x2eee0;
      if (uVar5 == 0x20) {
        nvCheckOkFailedNoLog
                  (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, gpuPciId, &pgpuIndex)",
                   "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1214);
        return 0x57;
      }
    }
    if (*(char *)(lVar1 + 0xbb838 + uVar6 * 0xbbb80) != '\0') {
      lVar1 = lVar1 + 600 + uVar6 * 0xbbb80;
      lVar4 = listHead_IMPL(lVar1);
      while( true ) {
        if (lVar4 == 0) {
          return 0x57;
        }
        if (*(long *)(*(long *)(lVar4 + 0x10) + 8) == param_2) break;
        lVar4 = listNext_IMPL(lVar1);
      }
      *param_3 = lVar4;
      return 0;
    }
  }
  return 0x56;
}


// ===== 004e2de0 kvgpuMgrGetVgpuPlacementInfo =====

long kvgpuMgrGetVgpuPlacementInfo(long param_1,long param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) {
    cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    if (cVar1 != '\0') {
      cVar1 = kvgpumgrIsMigTimeslicingModeEnabled(param_1);
      if (cVar1 != '\0') {
        piVar2 = (int *)(param_2 + 0x29e88);
        uVar3 = 0;
        while ((param_3 != *piVar2 || (*(char *)((long)piVar2 + 5) == '\0'))) {
          uVar3 = uVar3 + 1;
          piVar2 = piVar2 + 0x9194;
          if (uVar3 == 4) {
            return 0;
          }
        }
        return param_2 + 0x29e90 + (ulong)uVar3 * 0x24650;
      }
    }
    return param_2 + 0x5a40;
  }
  return param_2 + 0x5a40;
}


// ===== 004e2ea0 _kvgpumgrUpdateHomogeneousCreatablePlacementIds =====

undefined4
_kvgpumgrUpdateHomogeneousCreatablePlacementIds
          (long param_1,short param_2,int param_3,char param_4,uint param_5)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  bool bVar4;
  long lVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  long lVar11;
  short *psVar12;
  ulong uVar13;
  long lVar14;
  short *psVar15;
  uint uVar16;
  short *psVar17;
  ulong uVar18;
  ulong uVar19;
  long lVar20;
  char local_39 [9];
  
  uVar16 = 0;
  lVar2 = *(long *)(g_pSys + 0x1f8);
  piVar10 = (int *)(lVar2 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar10 || ((char)piVar10[0x18e] != '\x01'))) {
    uVar16 = uVar16 + 1;
    piVar10 = piVar10 + 0x2eee0;
    if (uVar16 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0xf7b);
      return 0x57;
    }
  }
  piVar10 = (int *)listHead_IMPL(lVar2 + 0x1777050);
  while( true ) {
    if (piVar10 == (int *)0x0) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetVgpuTypeInfo(vgpuTypeId, &pVgpuTypeInfo)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0xf7e);
      return 0x57;
    }
    if (param_3 == *piVar10) break;
    piVar10 = (int *)listNext_IMPL(lVar2 + 0x1777050);
  }
  uVar19 = (ulong)uVar16;
  lVar11 = uVar19 * 0xbbb80;
  psVar12 = (short *)kvgpuMgrGetVgpuPlacementInfo(param_1,lVar2 + 0x48 + lVar11,param_5);
  if (psVar12 == (short *)0x0) {
    nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                       "src/kernel/virtualization/kernel_vgpu_mgr.c",0xf83);
    return 0x57;
  }
  iVar1 = piVar10[0x61];
  if ((*(long *)(param_1 + 0x1bc0) == 0) ||
     (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar6 == '\0')) {
    iVar8 = osIsVgpuVfioPresent();
    if (iVar8 == 0) {
      iVar8 = *(int *)(lVar2 + 0xbb83c + uVar19 * 0xbbb80);
    }
    else {
      iVar8 = *(int *)(lVar2 + 0x24c + uVar19 * 0xbbb80);
    }
  }
  else {
    if (0xe < param_5) {
      nvCheckFailedNoLog(4,"swizzId < KMIGMGR_MAX_GPU_SWIZZID",
                         "src/kernel/virtualization/kernel_vgpu_mgr.c",0xf8a);
      return 0x1f;
    }
    iVar8 = *(int *)(lVar2 + 8 + ((ulong)param_5 + 0x2eed4 + uVar19 * 0x2eee0) * 4);
  }
  lVar20 = uVar19 * 0xbbb80;
  iVar9 = *(int *)(lVar2 + 0x250 + lVar20);
  if (param_4 != '\0') {
    if (iVar9 == 0) {
      return 0;
    }
    cVar6 = '\0';
    uVar13 = 0;
    do {
      puVar3 = *(undefined4 **)(lVar11 + lVar2 + 0x280 + uVar13 * 8);
      if ((puVar3 != (undefined4 *)0x0) && (puVar3[0x61] == iVar1)) {
        if ((*(long *)(param_1 + 0x1bc0) == 0) ||
           (cVar7 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar7 == '\0')) {
          if (puVar3[0xcc] == 0) goto LAB_004e3306;
        }
        else if ((puVar3[0xcc] != 0) &&
                ((iVar8 = _kvgpumgrCheckPartitionFlag(param_1,param_5,*puVar3,local_39), iVar8 != 0
                 || (local_39[0] != '\0')))) {
LAB_004e3306:
          if (*(ushort *)((long)puVar3 + 0x30e) != 0) {
            uVar18 = 0;
            psVar15 = psVar12 + uVar13 * 0x244;
            do {
              if (*psVar15 == param_2) {
                psVar12[uVar18 * 0xc + (uVar13 & 0xffffffff) * 0x244] = -1;
                cVar6 = param_4;
                goto LAB_004e32c0;
              }
              uVar16 = (int)uVar18 + 1;
              uVar18 = (ulong)uVar16;
              psVar15 = psVar15 + 0xc;
            } while (*(ushort *)((long)puVar3 + 0x30e) != uVar16);
          }
          if (cVar6 == '\0') {
            nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xfc2,
                         "_kvgpumgrUpdateHomogeneousCreatablePlacementIds",4,
                         "NVRM: Failed to find creatable placement id for vGPU type %d with placement id %d\n"
                         ,*puVar3,param_2);
            return 0x40;
          }
        }
      }
LAB_004e32c0:
      uVar16 = *(uint *)(lVar2 + 0x250 + lVar20);
      uVar13 = uVar13 + 1;
      if (uVar16 <= (uint)uVar13) {
        if (uVar16 != 0) {
          lVar20 = 0;
          do {
            puVar3 = *(undefined4 **)(lVar11 + lVar2 + 0x280 + lVar20 * 8);
            if (((puVar3 != (undefined4 *)0x0) && (puVar3[0x61] != iVar1)) &&
               ((((*(long *)(param_1 + 0x1bc0) == 0 ||
                  (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar6 == '\0')) ||
                 ((puVar3[0xcc] != 0 &&
                  ((iVar8 = _kvgpumgrCheckPartitionFlag(param_1,param_5,*puVar3,local_39),
                   iVar8 != 0 || (local_39[0] != '\0')))))) &&
                (*(short *)((long)puVar3 + 0x30e) != 0)))) {
              uVar16 = 0;
              psVar15 = psVar12 + lVar20 * 0x244;
              do {
                uVar16 = uVar16 + 1;
                *psVar15 = -1;
                psVar15 = psVar15 + 0xc;
              } while (uVar16 < *(ushort *)((long)puVar3 + 0x30e));
            }
            lVar20 = lVar20 + 1;
          } while ((uint)lVar20 < *(uint *)(lVar2 + uVar19 * 0xbbb80 + 0x250));
          return 0;
        }
        return 0;
      }
    } while( true );
  }
  if (iVar9 == 0) {
    return 0;
  }
  uVar19 = 0;
  bVar4 = false;
  psVar15 = psVar12;
  do {
    puVar3 = *(undefined4 **)(lVar11 + lVar2 + 0x280 + uVar19 * 8);
    if (puVar3 != (undefined4 *)0x0) {
      if (iVar8 == 0) {
        if (*(short *)((long)puVar3 + 0x30e) != 0) {
          lVar14 = 0;
          psVar17 = psVar15;
          do {
            lVar5 = lVar14 * 2;
            lVar14 = lVar14 + 1;
            *psVar17 = *(short *)(puVar3 + lVar5 + 100);
            psVar17 = psVar17 + 0xc;
          } while ((uint)lVar14 < (uint)*(ushort *)((long)puVar3 + 0x30e));
        }
      }
      else if (puVar3[0x61] == iVar1) {
        if ((*(long *)(param_1 + 0x1bc0) == 0) ||
           (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar6 == '\0')) {
          if (puVar3[0xcc] == 0) goto LAB_004e316e;
        }
        else if ((puVar3[0xcc] != 0) &&
                ((iVar9 = _kvgpumgrCheckPartitionFlag(param_1,param_5,*puVar3,local_39), iVar9 != 0
                 || (local_39[0] != '\0')))) {
LAB_004e316e:
          if (*(ushort *)((long)puVar3 + 0x30e) != 0) {
            uVar13 = 0;
            psVar17 = psVar15;
            do {
              if ((*(short *)(puVar3 + uVar13 * 2 + 100) == param_2) && (*psVar17 == -1)) {
                bVar4 = true;
                psVar12[(uVar13 & 0xffffffff) * 0xc + (uVar19 & 0xffffffff) * 0x244] = param_2;
                goto LAB_004e30d0;
              }
              uVar13 = uVar13 + 1;
              psVar17 = psVar17 + 0xc;
            } while ((uint)uVar13 < (uint)*(ushort *)((long)puVar3 + 0x30e));
          }
          if (!bVar4) {
            return 0x40;
          }
        }
      }
    }
LAB_004e30d0:
    uVar19 = uVar19 + 1;
    psVar15 = psVar15 + 0x244;
    if (*(uint *)(lVar2 + 0x250 + lVar20) <= (uint)uVar19) {
      return 0;
    }
  } while( true );
}


// ===== 004e3540 kvgpuMgrGetVgpuCreatableTypeIdFromSwizzId =====

long kvgpuMgrGetVgpuCreatableTypeIdFromSwizzId(long param_1,long param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) {
    cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    if (cVar1 != '\0') {
      cVar1 = kvgpumgrIsMigTimeslicingModeEnabled(param_1);
      if (cVar1 != '\0') {
        piVar2 = (int *)(param_2 + 0x29e88);
        uVar3 = 0;
        while ((param_3 != *piVar2 || (*(char *)((long)piVar2 + 5) == '\0'))) {
          uVar3 = uVar3 + 1;
          piVar2 = piVar2 + 0x9194;
          if (uVar3 == 4) {
            return 0;
          }
        }
        return param_2 + 0x4e2d8 + (ulong)uVar3 * 0x24650;
      }
    }
    return param_2 + 4;
  }
  return param_2 + 4;
}


// ===== 004e3600 _kvgpumgrUpdateHeterogeneousCreatablePlacementIds =====

undefined4
_kvgpumgrUpdateHeterogeneousCreatablePlacementIds
          (long param_1,ushort param_2,int param_3,byte param_4,undefined4 param_5)

{
  ushort uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  long lVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  ushort *puVar11;
  ushort uVar12;
  uint uVar13;
  long lVar14;
  byte bVar15;
  byte bVar16;
  long lVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  long lVar21;
  ushort local_80;
  uint local_60;
  uint local_58;
  char local_39 [9];
  
  uVar13 = 0;
  lVar2 = *(long *)(g_pSys + 0x1f8);
  piVar5 = (int *)(lVar2 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar5 || ((char)piVar5[0x18e] != '\x01'))) {
    uVar13 = uVar13 + 1;
    piVar5 = piVar5 + 0x2eee0;
    if (uVar13 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x104c);
      return 0x57;
    }
  }
  piVar5 = (int *)listHead_IMPL(lVar2 + 0x1777050);
  while( true ) {
    if (piVar5 == (int *)0x0) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetVgpuTypeInfo(vgpuTypeId, &pVgpuTypeInfo)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x104f);
      return 0x57;
    }
    if (param_3 == *piVar5) break;
    piVar5 = (int *)listNext_IMPL(lVar2 + 0x1777050);
  }
  lVar6 = (ulong)uVar13 * 0xbbb80;
  lVar17 = lVar2 + 0x48 + lVar6;
  lVar7 = kvgpuMgrGetVgpuPlacementInfo(param_1,lVar17,param_5);
  if (lVar7 == 0) {
    nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                       "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1055);
    return 0x57;
  }
  puVar8 = (undefined4 *)kvgpuMgrGetVgpuCreatableTypeIdFromSwizzId(param_1,lVar17,param_5);
  uVar18 = (uint)param_2;
  uVar19 = (uint)param_2 + piVar5[0x61];
  uVar20 = uVar19 - 1;
  lVar17 = lVar7 + 0x24408;
  if (param_4 == 0) {
    bitVectorClrRange_IMPL();
    uVar18 = (uint)param_2;
    while ((uVar18 != 0 && (cVar3 = bitVectorTest_IMPL(lVar17,0x200,uVar18 - 1), cVar3 == '\0'))) {
      uVar18 = uVar18 - 1;
    }
    if (uVar19 < *(ushort *)(lVar7 + 0x24400)) {
      do {
        uVar20 = uVar19;
        cVar3 = bitVectorTest_IMPL(lVar17,0x200,uVar20);
        if (cVar3 != '\0') {
          uVar20 = uVar20 - 1;
          break;
        }
        uVar19 = uVar20 + 1;
      } while (uVar20 + 1 < (uint)*(ushort *)(lVar7 + 0x24400));
    }
  }
  else {
    bitVectorSetRange_IMPL(lVar17,0x200,(uint)param_2,uVar20);
    uVar20 = uVar19;
  }
  puVar9 = puVar8;
  do {
    *puVar9 = 0;
    puVar10 = puVar9 + 2;
    puVar9[1] = 0;
    puVar9 = puVar10;
  } while (puVar10 != puVar8 + 0x80);
  lVar17 = (ulong)uVar13 * 0xbbb80;
  if (*(int *)(lVar2 + 0x250 + lVar17) == 0) {
    return 0;
  }
  local_60 = 0;
  lVar21 = 0;
  local_58 = uVar20 - uVar18 & 0xffff;
LAB_004e3902:
  do {
    puVar9 = *(undefined4 **)(lVar2 + lVar6 + 0x280 + lVar21 * 8);
    if (puVar9 == (undefined4 *)0x0) {
      return 0;
    }
    if (puVar9[0x61] != 0) {
      if ((*(long *)(param_1 + 0x1bc0) == 0) ||
         (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar3 == '\0')) {
        if (puVar9[0xcc] == 0) goto LAB_004e393f;
      }
      else if ((puVar9[0xcc] != 0) &&
              ((iVar4 = _kvgpumgrCheckPartitionFlag(param_1,param_5,*puVar9,local_39), iVar4 != 0 ||
               (local_39[0] != '\0')))) {
LAB_004e393f:
        if (*(short *)(puVar9 + 0xc3) != 0) {
          lVar14 = 0;
          local_80 = (ushort)uVar20;
          puVar11 = (ushort *)(lVar21 * 0x488 + lVar7);
          bVar16 = 0;
          do {
            uVar1 = *puVar11;
            bVar15 = bVar16;
            if (uVar1 == 0xffff) {
              if (((param_4 == 0) &&
                  (uVar1 = *(ushort *)(puVar9 + lVar14 * 2 + 99), (ushort)uVar18 <= uVar1)) &&
                 ((int)((*(ushort *)(puVar9 + 0x61) - 1) + (uint)uVar1) <= (int)(uVar20 & 0xffff)))
              {
                *puVar11 = uVar1;
                bVar15 = bVar16 | uVar1 != 0xffff;
              }
            }
            else if (param_4 == 0) {
              bVar15 = 1;
            }
            else {
              uVar13 = (uint)uVar1 + (uint)*(ushort *)(puVar9 + 0x61);
              uVar12 = (ushort)uVar13;
              if (uVar13 < (uVar20 & 0xffff)) {
                uVar12 = local_80;
              }
              uVar13 = (uint)uVar1;
              if ((ushort)uVar18 < uVar1) {
                uVar13 = uVar18;
              }
              bVar15 = param_4;
              if ((int)((uint)uVar12 - (uVar13 & 0xffff)) <
                  (int)(local_58 + *(ushort *)(puVar9 + 0x61))) {
                *puVar11 = 0xffff;
                bVar15 = bVar16;
              }
            }
            lVar14 = lVar14 + 1;
            puVar11 = puVar11 + 0xc;
            bVar16 = bVar15;
          } while ((uint)lVar14 < (uint)*(ushort *)(puVar9 + 0xc3));
          if (bVar15 != 0) {
            lVar21 = lVar21 + 1;
            puVar8[local_60] = *puVar9;
            local_60 = local_60 + 1;
            if (*(uint *)(lVar2 + 0x250 + lVar17) <= (uint)lVar21) {
              return 0;
            }
            goto LAB_004e3902;
          }
        }
      }
    }
    lVar21 = lVar21 + 1;
    if (*(uint *)(lVar2 + 0x250 + lVar17) <= (uint)lVar21) {
      return 0;
    }
  } while( true );
}


// ===== 004e3ae0 kvgpuMgrGetSwizzIdFromDevice =====

int kvgpuMgrGetSwizzIdFromDevice(long param_1,undefined8 param_2)

{
  char cVar1;
  int iVar2;
  long local_28 [3];
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x1bc0) != 0)) {
    cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,*(long *)(param_1 + 0x1bc0));
    if (cVar1 == '\0') {
      iVar2 = -1;
    }
    else {
      iVar2 = kmigmgrGetInstanceRefFromDevice_IMPL
                        (param_1,*(undefined8 *)(param_1 + 0x1bc0),param_2,local_28);
      if (iVar2 == 0) {
        return *(int *)(local_28[0] + 0x968);
      }
      nvCheckOkFailedNoLog
                (4,iVar2,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x143c);
    }
    return iVar2;
  }
  return -1;
}


// ===== 004e3ba0 kvgpumgrUpdateHeterogeneousInfo =====

undefined8
kvgpumgrUpdateHeterogeneousInfo
          (long param_1,undefined8 param_2,int param_3,short *param_4,long *param_5,long *param_6,
          undefined8 *param_7,undefined8 *param_8)

{
  short *psVar1;
  ushort uVar2;
  long lVar3;
  bool bVar4;
  char cVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  uint uVar9;
  int *piVar10;
  ulong uVar11;
  short sVar12;
  short *psVar13;
  short *psVar14;
  long lVar15;
  undefined4 local_64;
  short *local_60;
  
  lVar3 = *(long *)(g_pSys + 0x1f8);
  uVar8 = 0;
  piVar10 = (int *)(lVar3 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar10 || ((char)piVar10[0x18e] != '\x01'))) {
    uVar9 = (int)uVar8 + 1;
    uVar8 = (ulong)uVar9;
    piVar10 = piVar10 + 0x2eee0;
    if (uVar9 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x10e3);
      return 0x57;
    }
  }
  lVar15 = uVar8 * 0xbbb80;
  if (((*(long *)(param_1 + 0x1bc0) == 0) ||
      (cVar5 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar5 == '\0')) ||
     (cVar5 = kvgpumgrIsMigTimeslicingModeEnabled(param_1), cVar5 == '\0')) {
    local_60 = (short *)(lVar3 + 0x5a88 + lVar15);
    local_64 = 0xffffffff;
  }
  else {
    local_64 = kvgpuMgrGetSwizzIdFromDevice(param_1,param_2);
    local_60 = (short *)kvgpuMgrGetVgpuPlacementInfo(param_1,lVar3 + 0x48 + lVar15,local_64);
    if (local_60 == (short *)0x0) {
      nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                         "src/kernel/virtualization/kernel_vgpu_mgr.c",0x10ec);
      return 0x57;
    }
  }
  lVar6 = uVar8 * 0xbbb80 + lVar3;
  if (*(int *)(lVar6 + 0x250) != 0) {
    bVar4 = false;
    uVar8 = 0;
    psVar14 = local_60;
    do {
      piVar10 = *(int **)(lVar3 + lVar15 + 0x280 + uVar8 * 8);
      if (piVar10 == (int *)0x0) break;
      if ((*piVar10 == param_3) && (uVar2 = *(ushort *)(piVar10 + 0xc3), uVar2 != 0)) {
        sVar12 = *psVar14;
        uVar11 = 0;
        psVar13 = psVar14;
        if (*param_4 == -1) {
          while (sVar12 == -1) {
            uVar9 = (int)uVar11 + 1;
            uVar11 = (ulong)uVar9;
            if (uVar2 == uVar9) goto LAB_004e3ca0;
            sVar12 = psVar13[0xc];
            psVar13 = psVar13 + 0xc;
          }
          *param_4 = sVar12;
          cVar5 = *(char *)(param_1 + 0x491d);
        }
        else {
          while (*param_4 != sVar12) {
            uVar9 = (int)uVar11 + 1;
            uVar11 = (ulong)uVar9;
            if (uVar2 == uVar9) goto LAB_004e3ca0;
            psVar1 = psVar13 + 0xc;
            psVar13 = psVar13 + 0xc;
            sVar12 = *psVar1;
          }
          cVar5 = *(char *)(param_1 + 0x491d);
        }
        if (cVar5 != '\0') {
          *param_6 = (ulong)*(uint *)(local_60 + uVar11 * 0xc + (uVar8 & 0xffffffff) * 0x244 + 2) *
                     *(long *)(param_1 + 0x3b10);
          *param_5 = (ulong)*(uint *)(psVar14 + 0x240) * *(long *)(param_1 + 0x3b10);
          *param_7 = *(undefined8 *)(local_60 + uVar11 * 0xc + (uVar8 & 0xffffffff) * 0x244 + 4);
          *param_8 = 0;
        }
        bVar4 = true;
      }
LAB_004e3ca0:
      uVar8 = uVar8 + 1;
      psVar14 = psVar14 + 0x244;
    } while ((uint)uVar8 < *(uint *)(lVar6 + 0x250));
    if (bVar4) {
      uVar7 = _kvgpumgrUpdateHeterogeneousCreatablePlacementIds(param_1,*param_4,param_3,1,local_64)
      ;
      return uVar7;
    }
  }
  return 0x40;
}


// ===== 004e3ec0 kvgpuMgrReserveVgpuPlacementInfoPerGI =====

ulong kvgpuMgrReserveVgpuPlacementInfoPerGI(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  long lVar10;
  ulong uVar11;
  undefined2 *puVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  int *piVar19;
  int *piVar20;
  undefined2 *puVar21;
  ulong uVar22;
  long lVar23;
  long lVar24;
  long lVar25;
  undefined1 local_70 [8];
  long local_68;
  long local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  long local_40 [2];
  
  lVar23 = g_pSys;
  uVar22 = 0;
  lVar2 = *(long *)(g_pSys + 0x1f8);
  piVar9 = (int *)(lVar2 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar9 || ((char)piVar9[0x18e] != '\x01'))) {
    uVar5 = (int)uVar22 + 1;
    uVar22 = (ulong)uVar5;
    piVar9 = piVar9 + 0x2eee0;
    if (uVar5 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x144f);
      return 0x57;
    }
  }
  lVar1 = lVar2 + uVar22 * 0xbbb80;
  uVar11 = 0;
  lVar16 = lVar1;
  while (*(char *)(lVar16 + 0x29ed5) != '\0') {
    uVar5 = (int)uVar11 + 1;
    uVar11 = (ulong)uVar5;
    lVar16 = lVar16 + 0x24650;
    if (uVar5 == 4) {
      return 0x5b;
    }
  }
  lVar16 = uVar11 * 0x24650 + uVar22 * 0xbbb80;
  *(int *)(lVar2 + 0x29ed0 + lVar16) = param_2;
  *(undefined1 *)(lVar2 + 0x29ed5 + lVar16) = 1;
  if (*(char *)(lVar2 + 0xbb839 + uVar22 * 0xbbb80) == '\0') goto LAB_004e3fc3;
  uVar11 = 0;
  lVar23 = *(long *)(lVar23 + 0x1f8);
  local_50 = 0;
  lVar16 = *(long *)(param_1 + 0x1bc0);
  piVar9 = (int *)(lVar23 + 0x48);
  do {
    if ((*(int *)(param_1 + 0x7ac) == *piVar9) && ((char)piVar9[0x18e] == '\x01')) {
      if ((*(char *)(param_1 + 0x491d) == '\0') ||
         ((lVar16 == 0 ||
          (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,lVar16), cVar4 == '\0'))))
      goto LAB_004e4558;
      uVar5 = kmigmgrGetGPUInstanceInfo_IMPL(param_1,lVar16,param_2,&local_58);
      if (uVar5 != 0) {
        nvAssertOkFailedNoLog
                  (uVar5,
                   "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, &pKernelMIGGpuInstance)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x14fa);
        goto LAB_004e44d5;
      }
      uVar5 = serverGetClientUnderLock(g_resServ,*(undefined4 *)(local_58 + 0x9c0),local_40);
      if (uVar5 != 0) {
        nvCheckOkFailedNoLog
                  (4,uVar5,
                   "serverGetClientUnderLock(&g_resServ, pKernelMIGGpuInstance->instanceHandles.hClient, &pClient)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1500);
        goto LAB_004e44d5;
      }
      iVar6 = deviceGetByHandle_IMPL(local_40[0],*(undefined4 *)(local_58 + 0x9c4),&local_48);
      if (iVar6 == 0) {
        iVar6 = kmigmgrGetMemoryPartitionHeapFromDevice_IMPL(param_1,lVar16,local_48,&local_50);
        if (iVar6 == 0) {
          lVar25 = uVar11 * 0xbbb80;
          lVar13 = lVar23 + 0x48 + lVar25;
          pmaGetLargestFree(*(undefined8 *)(local_50 + 0x128),local_70,&local_68,&local_60);
          uVar18 = *(ulong *)(param_1 + 0x3b10);
          lVar10 = _kvgpumgrGetMaxTotalGspHeapSize(param_1,lVar13,*(undefined4 *)(local_58 + 0x96c))
          ;
          lVar16 = lVar23 + lVar25;
          uVar15 = 0;
          lVar17 = lVar16;
          goto LAB_004e4250;
        }
        nvCheckFailedNoLog(4,
                           "(kmigmgrGetMemoryPartitionHeapFromDevice(pGpu, pKernelMIGManager, pDevice, &pMemoryPartitionHeap) == NV_OK)"
                           ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1507);
      }
      else {
        nvCheckFailedNoLog(4,
                           "(deviceGetByHandle(pClient, pKernelMIGGpuInstance->instanceHandles.hDevice, &pDevice) == NV_OK)"
                           ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1503);
      }
      uVar5 = 0x1b;
      goto LAB_004e44d5;
    }
    uVar5 = (int)uVar11 + 1;
    uVar11 = (ulong)uVar5;
    piVar9 = piVar9 + 0x2eee0;
  } while (uVar5 != 0x20);
  nvCheckOkFailedNoLog
            (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
             "src/kernel/virtualization/kernel_vgpu_mgr.c",0x14f1);
  goto LAB_004e44d0;
LAB_004e4651:
  do {
    piVar9 = *(int **)(lVar16 + 0x280 + lVar24 * 8);
    if (piVar9 == (int *)0x0) break;
    if (piVar9[0xcc] != 0) {
      piVar19 = &DAT_00da1848;
      uVar14 = 0;
      do {
        if (*piVar9 == *piVar19) {
          iVar7 = (&DAT_00da1844)[uVar14 * 3];
          goto LAB_004e46a2;
        }
        uVar8 = (int)uVar14 + 1;
        uVar14 = (ulong)uVar8;
        piVar19 = piVar19 + 3;
      } while (uVar8 != 0x129);
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,"kvgpumgrGetPartitionFlag",4,
                   "NVRM: Invalid SMC vGpu TypeId: 0x%x\n");
      iVar7 = -1;
LAB_004e46a2:
      if (*(int *)(local_58 + 0x96c) == iVar7) {
        uVar14 = (ulong)uVar5;
        uVar5 = uVar5 + 1;
        *(int *)(lVar13 + uVar14 * 4) = *piVar9;
        if ((!bVar3) && (piVar9[0xe3] == 1)) {
          bVar3 = true;
          iVar6 = (int)(*(ulong *)(piVar9 + 0xd6) / *(ulong *)(param_1 + 0x3b10)) +
                  *(int *)(lVar16 + 0x5f08 + lVar24 * 0x488);
        }
      }
    }
    lVar24 = lVar24 + 1;
  } while ((uint)lVar24 < *(uint *)(lVar23 + 0x250 + lVar17));
  if (bVar3) {
    if (*(int *)(lVar23 + 0x250 + uVar11 * 0xbbb80) != 0) {
      lVar13 = 0;
      uVar14 = (local_68 + -1 + local_60 + uVar18 & -uVar18) / uVar18;
      uVar5 = iVar6 - (int)(((uVar18 - 1) + lVar10) / uVar18);
      piVar9 = (int *)(lVar23 + 0x29edc + lVar25 + uVar15 * 0x24650);
      do {
        piVar19 = *(int **)(lVar16 + 0x280 + lVar13 * 8);
        if (piVar19 == (int *)0x0) break;
        if (piVar19[0xcc] != 0) {
          piVar20 = &DAT_00da1848;
          uVar15 = 0;
          do {
            if (*piVar19 == *piVar20) {
              iVar6 = (&DAT_00da1844)[uVar15 * 3];
              goto LAB_004e4862;
            }
            uVar8 = (int)uVar15 + 1;
            uVar15 = (ulong)uVar8;
            piVar20 = piVar20 + 3;
          } while (uVar8 != 0x129);
          nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,
                       "kvgpumgrGetPartitionFlag",4);
          iVar6 = -1;
LAB_004e4862:
          if (*(int *)(local_58 + 0x96c) == iVar6) {
            piVar9[0x11f] = *(int *)(lVar13 * 0x488 + 0x5f08 + lVar16);
            uVar15 = vgpuMgrGetPlacementRegionSize(param_1,lVar23 + 0xbbba0 + lVar25,piVar19);
            if ((short)piVar19[0xc3] != 0) {
              lVar17 = 0;
              piVar20 = piVar9;
              do {
                iVar6 = (int)uVar14;
                if (piVar19[0xe3] == 1) {
                  lVar24 = ((uint)piVar9[0x11f] + uVar14) * uVar18;
                }
                else {
                  iVar6 = (int)((ulong)(*(ushort *)(piVar19 + lVar17 * 2 + 99) * uVar5) /
                               (uVar15 & 0xffffffff)) + iVar6;
                  lVar24 = (((ulong)(uint)*(ushort *)(piVar19 + lVar17 * 2 + 99) * lVar10) /
                            (uVar15 & 0xffffffff) & 0xffffffffffe00000) + (uVar5 + uVar14) * uVar18;
                }
                *piVar20 = iVar6;
                lVar17 = lVar17 + 1;
                *(long *)(piVar20 + 1) = lVar24;
                piVar20 = piVar20 + 6;
              } while ((uint)lVar17 < (uint)*(ushort *)(piVar19 + 0xc3));
            }
          }
        }
        lVar13 = lVar13 + 1;
        piVar9 = piVar9 + 0x122;
      } while ((uint)lVar13 < *(uint *)(lVar23 + 0x250 + uVar11 * 0xbbb80));
    }
LAB_004e3fc3:
    lVar23 = uVar22 * 0xbbb80 + lVar2;
    if (*(char *)(lVar23 + 0xbb83a) == '\0') {
      return 0;
    }
    uVar11 = kmigmgrGetGPUInstanceInfo_IMPL
                       (param_1,*(undefined8 *)(param_1 + 0x1bc0),param_2,local_40);
    uVar5 = (uint)uVar11;
    if (uVar5 == 0) {
      uVar18 = 0;
      lVar16 = lVar1;
      if (*(char *)(lVar23 + 0xbb839) == '\0') {
        *(undefined1 *)(lVar23 + 0xbb83a) = 0;
        nvCheckFailedNoLog(4,"pPgpuInfo->homogeneousPlacementSupported",
                           "src/kernel/virtualization/kernel_vgpu_mgr.c",0x159b);
        uVar5 = 0x56;
      }
      else {
        do {
          if ((*(char *)(lVar16 + 0x29ed5) != '\0') && (param_2 == *(int *)(lVar16 + 0x29ed0))) {
            if (*(int *)(lVar2 + 0x250 + uVar22 * 0xbbb80) == 0) {
              return uVar11;
            }
            lVar23 = 0;
            puVar21 = (undefined2 *)(lVar2 + 0x29ed8 + uVar22 * 0xbbb80 + uVar18 * 0x24650);
            goto LAB_004e43b0;
          }
          uVar5 = (int)uVar18 + 1;
          uVar18 = (ulong)uVar5;
          lVar16 = lVar16 + 0x24650;
        } while (uVar5 != 4);
        nvAssertFailedNoLog("pKernelVgpuTypePlacementInfo != NULL",
                            "src/kernel/virtualization/kernel_vgpu_mgr.c",0x15a8);
        uVar5 = 0x57;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar11 & 0xffffffff,
                 "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, &pKernelMIGGpuInstance)"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1596);
    }
    nvCheckOkFailedNoLog
              (4,uVar5,"_kvgpumgrSetHomogeneousResourcesPerGI(pGpu, swizzId, pPgpuInfo)",
               "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1469);
    return (ulong)uVar5;
  }
LAB_004e4540:
  nvAssertFailedNoLog("bFoundOne2OneProfile","src/kernel/virtualization/kernel_vgpu_mgr.c",0x154c);
LAB_004e4558:
  uVar5 = 0x1f;
  goto LAB_004e44d5;
LAB_004e43b0:
  do {
    piVar9 = *(int **)(lVar1 + 0x280 + lVar23 * 8);
    if (piVar9 == (int *)0x0) break;
    if (piVar9[0xcc] != 0) {
      piVar19 = &DAT_00da1848;
      uVar5 = 0;
      do {
        if (*piVar9 == *piVar19) {
          iVar6 = (&DAT_00da1844)[(ulong)uVar5 * 3];
          goto LAB_004e4402;
        }
        uVar5 = uVar5 + 1;
        piVar19 = piVar19 + 3;
      } while (uVar5 != 0x129);
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,"kvgpumgrGetPartitionFlag",4,
                   "NVRM: Invalid SMC vGpu TypeId: 0x%x\n");
      iVar6 = -1;
LAB_004e4402:
      if ((*(int *)(local_40[0] + 0x96c) == iVar6) && ((short)piVar9[0xc3] != 0)) {
        lVar16 = 0;
        puVar12 = puVar21;
        do {
          *(undefined4 *)(puVar12 + 8) = *(undefined4 *)(puVar12 + 2);
          lVar13 = lVar16 * 2;
          lVar16 = lVar16 + 1;
          *puVar12 = (short)piVar9[lVar13 + 100];
          puVar12 = puVar12 + 0xc;
        } while ((uint)lVar16 < (uint)*(ushort *)(piVar9 + 0xc3));
      }
    }
    lVar23 = lVar23 + 1;
    puVar21 = puVar21 + 0x244;
  } while ((uint)lVar23 < *(uint *)(lVar2 + 0x250 + uVar22 * 0xbbb80));
  goto LAB_004e4426;
  while( true ) {
    uVar5 = (int)uVar15 + 1;
    uVar15 = (ulong)uVar5;
    lVar17 = lVar17 + 0x24650;
    if (uVar5 == 4) break;
LAB_004e4250:
    if ((*(char *)(lVar17 + 0x29ed5) != '\0') && (param_2 == *(int *)(lVar17 + 0x29ed0))) {
      lVar17 = uVar11 * 0xbbb80;
      *(short *)(lVar23 + 0x4e2d8 + uVar15 * 0x24650 + lVar17) =
           (short)((uint)*(ushort *)(lVar23 + lVar17 + 0x29e88) /
                  *(uint *)(CSWTCH_223 + (ulong)(*(uint *)(local_58 + 0x96c) & 3) * 4));
      lVar13 = kvgpuMgrGetVgpuCreatableTypeIdFromSwizzId(param_1,lVar13,param_2);
      iVar6 = 0;
      uVar5 = 0;
      if (*(int *)(lVar23 + lVar17 + 0x250) == 0) goto LAB_004e4540;
      lVar24 = 0;
      bVar3 = false;
      goto LAB_004e4651;
    }
  }
  nvAssertFailedNoLog("pKernelVgpuTypePlacementInfo != NULL",
                      "src/kernel/virtualization/kernel_vgpu_mgr.c",0x151c);
LAB_004e44d0:
  uVar5 = 0x57;
LAB_004e44d5:
  nvCheckOkFailedNoLog
            (4,uVar5,"_kvgpuMgrSetHeterogeneousResourcesPerGI(pGpu, swizzId, pPgpuInfo)",
             "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1464);
  uVar11 = (ulong)uVar5;
LAB_004e4426:
  return uVar11 & 0xffffffff;
}


// ===== 004e4b20 kvgpuMgrClearVgpuPlacementInfoPerGI =====

undefined8 kvgpuMgrClearVgpuPlacementInfoPerGI(long param_1,int param_2)

{
  long lVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  uVar5 = 0;
  piVar2 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar2 || ((char)piVar2[0x18e] != '\x01'))) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    piVar2 = piVar2 + 0x2eee0;
    if (uVar4 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x147b);
      return 0x57;
    }
  }
  uVar4 = 0;
  lVar3 = lVar1 + uVar5 * 0xbbb80;
  while ((*(int *)(lVar3 + 0x29ed0) != param_2 || (*(char *)(lVar3 + 0x29ed5) == '\0'))) {
    uVar4 = uVar4 + 1;
    lVar3 = lVar3 + 0x24650;
    if (uVar4 == 4) {
      return 0x5b;
    }
  }
  portMemSet(lVar1 + uVar5 * 0xbbb80 + 0x29ed0 + (ulong)uVar4 * 0x24650,0,0x24650);
  return 0;
}


// ===== 004e4c10 __pfx_kvgpuMgrSetHeterogeneousModePerGI =====

undefined8 __pfx_kvgpuMgrSetHeterogeneousModePerGI(long param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  uVar5 = 0;
  piVar2 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar2 || ((char)piVar2[0x18e] != '\x01'))) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    piVar2 = piVar2 + 0x2eee0;
    if (uVar4 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x149f);
      return 0x57;
    }
  }
  uVar4 = 0;
  lVar3 = uVar5 * 0xbbb80 + lVar1;
  while ((*(int *)(lVar3 + 0x29ed0) != param_2 || (*(char *)(lVar3 + 0x29ed5) == '\0'))) {
    uVar4 = uVar4 + 1;
    lVar3 = lVar3 + 0x24650;
    if (uVar4 == 4) {
      return 0x5b;
    }
  }
  *(undefined1 *)(lVar1 + 0x29ed4 + (ulong)uVar4 * 0x24650 + uVar5 * 0xbbb80) = param_3;
  return 0;
}


// ===== 004e4c20 kvgpuMgrSetHeterogeneousModePerGI =====

undefined8 kvgpuMgrSetHeterogeneousModePerGI(long param_1,int param_2,undefined1 param_3)

{
  long lVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  uVar5 = 0;
  piVar2 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar2 || ((char)piVar2[0x18e] != '\x01'))) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    piVar2 = piVar2 + 0x2eee0;
    if (uVar4 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x149f);
      return 0x57;
    }
  }
  uVar4 = 0;
  lVar3 = uVar5 * 0xbbb80 + lVar1;
  while ((*(int *)(lVar3 + 0x29ed0) != param_2 || (*(char *)(lVar3 + 0x29ed5) == '\0'))) {
    uVar4 = uVar4 + 1;
    lVar3 = lVar3 + 0x24650;
    if (uVar4 == 4) {
      return 0x5b;
    }
  }
  *(undefined1 *)(lVar1 + 0x29ed4 + (ulong)uVar4 * 0x24650 + uVar5 * 0xbbb80) = param_3;
  return 0;
}


// ===== 004e4d20 kvgpuMgrGetHeterogeneousModePerGI =====

undefined8 kvgpuMgrGetHeterogeneousModePerGI(long param_1,int param_2,undefined1 *param_3)

{
  long lVar1;
  int *piVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  uVar5 = 0;
  piVar2 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar2 || ((char)piVar2[0x18e] != '\x01'))) {
    uVar4 = (int)uVar5 + 1;
    uVar5 = (ulong)uVar4;
    piVar2 = piVar2 + 0x2eee0;
    if (uVar4 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x14c2);
      return 0x57;
    }
  }
  uVar4 = 0;
  lVar3 = uVar5 * 0xbbb80 + lVar1;
  while ((*(int *)(lVar3 + 0x29ed0) != param_2 || (*(char *)(lVar3 + 0x29ed5) == '\0'))) {
    uVar4 = uVar4 + 1;
    lVar3 = lVar3 + 0x24650;
    if (uVar4 == 4) {
      return 0x5b;
    }
  }
  *param_3 = *(undefined1 *)(lVar1 + 0x29ed4 + (ulong)uVar4 * 0x24650 + uVar5 * 0xbbb80);
  return 0;
}


// ===== 004e4e20 kvgpuMgrGetPlacementResource =====

int kvgpuMgrGetPlacementResource
              (long param_1,undefined8 param_2,undefined8 param_3,undefined2 *param_4,long *param_5,
              long *param_6,undefined8 *param_7,undefined8 *param_8)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  int *piVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  long local_78;
  char local_39 [9];
  
  uVar8 = 0;
  lVar7 = *(long *)(g_pSys + 0x1f8);
  piVar6 = (int *)(lVar7 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar6 || ((char)piVar6[0x18e] != '\x01'))) {
    uVar9 = (int)uVar8 + 1;
    uVar8 = (ulong)uVar9;
    piVar6 = piVar6 + 0x2eee0;
    if (uVar9 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",4999);
      return 0x57;
    }
  }
  lVar5 = uVar8 * 0xbbb80;
  if (((*(long *)(param_1 + 0x1bc0) == 0) ||
      (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar2 == '\0')) ||
     (cVar2 = kvgpumgrIsMigTimeslicingModeEnabled(param_1), cVar2 == '\0')) {
    local_78 = lVar7 + 0x5a88 + lVar5;
    local_39[0] = *(char *)(param_1 + 0x4a5);
  }
  else {
    uVar4 = kvgpuMgrGetSwizzIdFromDevice(param_1,param_2);
    local_78 = kvgpuMgrGetVgpuPlacementInfo(param_1,lVar7 + 0x48 + lVar5,uVar4);
    if (local_78 == 0) {
      nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                         "src/kernel/virtualization/kernel_vgpu_mgr.c",0x138e);
      return 0x57;
    }
    iVar3 = kvgpuMgrGetHeterogeneousModePerGI(param_1,uVar4,local_39);
    if (iVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar3,
                 "kvgpuMgrGetHeterogeneousModePerGI(pGpu, swizzId, &bHeterogeneousModeEnabled)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x138f);
      return iVar3;
    }
  }
  piVar6 = (int *)listHead_IMPL(lVar7 + 0x17770b0);
  while( true ) {
    if (piVar6 == (int *)0x0) {
      return 0x57;
    }
    iVar3 = portMemCmp(piVar6 + 1,param_3,0x10);
    if (iVar3 == 0) break;
    piVar6 = (int *)listNext_IMPL(lVar7 + 0x17770b0,piVar6);
  }
  uVar9 = *(uint *)(lVar7 + 0x250 + uVar8 * 0xbbb80);
  if (uVar9 != 0) {
    uVar8 = 0;
    do {
      piVar1 = *(int **)(lVar7 + lVar5 + 0x280 + uVar8 * 8);
      if (((piVar1 != (int *)0x0) && (*piVar1 == *piVar6)) && (piVar1[0x61] != 0)) {
        if (local_39[0] == '\0') {
          if (*(ushort *)((long)piVar1 + 0x30e) != 0) {
            uVar10 = 0;
            do {
              if ((uint)*(ushort *)(piVar1 + uVar10 * 2 + 100) == piVar6[8]) {
                *param_4 = (short)piVar6[8];
                lVar7 = (uVar8 & 0xffffffff) * 0x488;
                *param_6 = (ulong)*(uint *)(local_78 + 0x10 + lVar7 + (uVar10 & 0xffffffff) * 0x18)
                           * *(long *)(param_1 + 0x3b10);
                *param_5 = (ulong)*(uint *)(local_78 + 0x480 + lVar7) * *(long *)(param_1 + 0x3b10);
                *param_7 = 0;
                *param_8 = 0;
                return 0;
              }
              uVar10 = uVar10 + 1;
            } while ((uint)uVar10 < (uint)*(ushort *)((long)piVar1 + 0x30e));
          }
        }
        else if (*(ushort *)(piVar1 + 0xc3) != 0) {
          uVar10 = 0;
          do {
            if ((uint)*(ushort *)(piVar1 + uVar10 * 2 + 99) == piVar6[8]) {
              *param_4 = (short)piVar6[8];
              if (*(char *)(param_1 + 0x491d) == '\0') {
                return 0;
              }
              lVar5 = (uVar8 & 0xffffffff) * 0x488;
              lVar7 = lVar5 + (uVar10 & 0xffffffff) * 0x18 + local_78;
              *param_6 = (ulong)*(uint *)(lVar7 + 4) * *(long *)(param_1 + 0x3b10);
              *param_5 = (ulong)*(uint *)(local_78 + 0x480 + lVar5) * *(long *)(param_1 + 0x3b10);
              *param_7 = *(undefined8 *)(lVar7 + 8);
              *param_8 = 0;
              return 0;
            }
            uVar10 = uVar10 + 1;
          } while ((uint)uVar10 < (uint)*(ushort *)(piVar1 + 0xc3));
        }
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 != uVar9);
  }
  return 0x40;
}


// ===== 004e5200 kvgpuMgrGetHeterogeneousMode =====

ulong kvgpuMgrGetHeterogeneousMode(long param_1,undefined4 param_2,undefined1 *param_3)

{
  char cVar1;
  ulong uVar2;
  
  if (param_1 == 0) {
    *param_3 = uRam00000000000004a5;
    return 0;
  }
  if ((*(long *)(param_1 + 0x1bc0) == 0) ||
     (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar1 == '\0')) {
    *param_3 = *(undefined1 *)(param_1 + 0x4a5);
  }
  else {
    if ((*(char *)(param_1 + 0x46b) != '\0') &&
       (cVar1 = kvgpumgrIsMigTimeslicingModeEnabled(), cVar1 != '\0')) {
      uVar2 = kvgpuMgrGetHeterogeneousModePerGI(param_1,param_2);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      nvCheckOkFailedNoLog
                (4,uVar2 & 0xffffffff,
                 "kvgpuMgrGetHeterogeneousModePerGI(pGpu, swizzId, bHeterogeneousModeEnabled)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x13e8);
      return uVar2 & 0xffffffff;
    }
    *param_3 = 0;
  }
  return 0;
}


// ===== 004e52c0 kvgpumgrCheckHomogeneousPlacementSupported =====

int kvgpumgrCheckHomogeneousPlacementSupported(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  char local_9;
  
  if (param_1 == 0) {
    nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/virtualization/kernel_vgpu_mgr.c",0xd4);
    return 0x1f;
  }
  uVar4 = 0;
  lVar1 = *(long *)(g_pSys + 0x1f8);
  piVar3 = (int *)(lVar1 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar3 || ((char)piVar3[0x18e] != '\x01'))) {
    uVar4 = uVar4 + 1;
    piVar3 = piVar3 + 0x2eee0;
    if (uVar4 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0xd6);
      return 0x57;
    }
  }
  iVar2 = kvgpuMgrGetHeterogeneousMode(param_1,param_2,&local_9);
  if (iVar2 == 0) {
    if (local_9 == '\0') {
      iVar2 = 0;
      if (*(char *)(lVar1 + 0xbb83a + (ulong)uVar4 * 0xbbb80) == '\0') {
        iVar2 = 0x56;
      }
      return iVar2;
    }
    return 0x56;
  }
  nvCheckOkFailedNoLog
            (4,iVar2,"kvgpuMgrGetHeterogeneousMode(pGpu, swizzId, &bHeterogeneousModeEnabled)",
             "src/kernel/virtualization/kernel_vgpu_mgr.c",0xdb);
  return iVar2;
}


// ===== 004e53e0 kvgpumgrUpdateHomogeneousInfo =====

ulong kvgpumgrUpdateHomogeneousInfo
                (long param_1,undefined8 param_2,int param_3,short *param_4,long *param_5,
                long *param_6)

{
  short *psVar1;
  ushort uVar2;
  long lVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  undefined4 uVar8;
  int *piVar9;
  long lVar10;
  short *psVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  short sVar15;
  long lVar16;
  long lVar17;
  long local_50;
  
  if (param_1 == 0) {
    nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/virtualization/kernel_vgpu_mgr.c",0x1146);
    return 0x56;
  }
  uVar13 = 0;
  lVar3 = *(long *)(g_pSys + 0x1f8);
  piVar9 = (int *)(lVar3 + 0x48);
  while ((*(int *)(param_1 + 0x7ac) != *piVar9 || ((char)piVar9[0x18e] != '\x01'))) {
    uVar7 = (int)uVar13 + 1;
    uVar13 = (ulong)uVar7;
    piVar9 = piVar9 + 0x2eee0;
    if (uVar7 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1148);
      return 0x57;
    }
  }
  lVar10 = uVar13 * 0xbbb80;
  if (((*(long *)(param_1 + 0x1bc0) == 0) ||
      (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar6 == '\0')) ||
     (cVar6 = kvgpumgrIsMigTimeslicingModeEnabled(), cVar6 == '\0')) {
    uVar8 = 0xffffffff;
    local_50 = lVar3 + 0x5a88 + lVar10;
  }
  else {
    uVar8 = kvgpuMgrGetSwizzIdFromDevice(param_1,param_2);
    local_50 = kvgpuMgrGetVgpuPlacementInfo(param_1,lVar3 + 0x48 + lVar10,uVar8);
    if (local_50 == 0) {
      nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                         "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1151);
      return 0x57;
    }
  }
  uVar7 = kvgpumgrCheckHomogeneousPlacementSupported(param_1,uVar8);
  if (uVar7 == 0) {
    uVar14 = 0;
    lVar17 = uVar13 * 0xbbb80 + lVar3;
    bVar5 = false;
    if (*(int *)(lVar17 + 0x250) != 0) {
      do {
        while( true ) {
          bVar4 = bVar5;
          piVar9 = *(int **)(lVar10 + lVar3 + 0x280 + uVar14 * 8);
          if (piVar9 == (int *)0x0) goto LAB_004e55f0;
          if ((*piVar9 != param_3) || (uVar2 = *(ushort *)((long)piVar9 + 0x30e), uVar2 == 0))
          break;
          lVar16 = uVar14 * 0x488;
          uVar13 = 0;
          psVar11 = (short *)(local_50 + lVar16);
          sVar15 = *psVar11;
          if (*param_4 == -1) {
            while (sVar15 == -1) {
              uVar7 = (int)uVar13 + 1;
              uVar13 = (ulong)uVar7;
              if (uVar2 == uVar7) goto LAB_004e5518;
              psVar1 = psVar11 + 0xc;
              psVar11 = psVar11 + 0xc;
              sVar15 = *psVar1;
            }
            *param_4 = sVar15;
          }
          else {
            while (*param_4 != sVar15) {
              uVar7 = (int)uVar13 + 1;
              uVar13 = (ulong)uVar7;
              if (uVar2 == uVar7) goto LAB_004e5518;
              psVar1 = psVar11 + 0xc;
              psVar11 = psVar11 + 0xc;
              sVar15 = *psVar1;
            }
          }
          uVar12 = uVar14 & 0xffffffff;
          uVar14 = uVar14 + 1;
          bVar4 = true;
          *param_6 = (ulong)*(uint *)(local_50 + 0x10 + uVar12 * 0x488 + uVar13 * 0x18) *
                     *(long *)(param_1 + 0x3b10);
          *param_5 = (ulong)*(uint *)(local_50 + 0x480 + lVar16) * *(long *)(param_1 + 0x3b10);
          bVar5 = true;
          if (*(uint *)(lVar17 + 0x250) <= (uint)uVar14) goto LAB_004e55f0;
        }
LAB_004e5518:
        uVar14 = uVar14 + 1;
        bVar5 = bVar4;
      } while ((uint)uVar14 < *(uint *)(lVar17 + 0x250));
LAB_004e55f0:
      if (bVar4) {
        uVar13 = _kvgpumgrUpdateHomogeneousCreatablePlacementIds(param_1,*param_4,param_3,1,uVar8);
        return uVar13;
      }
    }
    uVar13 = 0x40;
  }
  else {
    nvCheckOkFailedNoLog
              (4,uVar7,"kvgpumgrCheckHomogeneousPlacementSupported(pGpu, swizzId)",
               "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1158);
    uVar13 = (ulong)uVar7;
  }
  return uVar13;
}


// ===== 004e5780 kvgpumgrSetVgpuType =====

ulong kvgpumgrSetVgpuType(long param_1,long param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  int *piVar7;
  ulong uVar8;
  long lVar9;
  char local_29;
  
  if (param_1 != 0) {
    uVar3 = kvgpuMgrGetHeterogeneousMode(param_1,param_4,&local_29);
    if ((int)uVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar3 & 0xffffffff,
                 "kvgpuMgrGetHeterogeneousMode(pGpu, swizzId, &bHeterogeneousModeEnabled)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0xfc);
      return uVar3 & 0xffffffff;
    }
    if (local_29 != '\0') {
      return uVar3;
    }
  }
  puVar4 = (undefined4 *)(param_2 + 4);
  do {
    *puVar4 = 0;
    puVar5 = puVar4 + 2;
    puVar4[1] = 0;
    puVar4 = puVar5;
  } while (puVar5 != (undefined4 *)(param_2 + 0x204));
  if (param_3 == 0) {
    uVar1 = *(uint *)(param_2 + 0x208);
    if (uVar1 == 0) {
      return 0;
    }
    lVar6 = 1;
    do {
      *(undefined4 *)(param_2 + lVar6 * 4) = **(undefined4 **)(param_2 + 0x230 + lVar6 * 8);
      lVar6 = lVar6 + 1;
    } while (lVar6 != (ulong)uVar1 + 1);
  }
  else {
    iVar2 = osIsVgpuVfioPresent();
    if ((iVar2 == 0) || (iVar2 = osIsVgpuDeviceVmPresent(), iVar2 == 0)) {
      lVar6 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
      piVar7 = (int *)listHead_IMPL(lVar6);
      while( true ) {
        if (piVar7 == (int *)0x0) {
          return 0x57;
        }
        if (param_3 == *piVar7) break;
        piVar7 = (int *)listNext_IMPL(lVar6);
      }
      uVar1 = *(uint *)(param_2 + 0x208);
      if (uVar1 == 0) {
        return 0;
      }
      lVar6 = *(long *)(piVar7 + 0xd2);
      uVar3 = 0;
      lVar9 = param_2;
      do {
        uVar8 = uVar3;
        if (lVar6 == *(long *)(*(undefined4 **)(lVar9 + 0x238) + 0xd2)) {
          uVar8 = (ulong)((int)uVar3 + 1);
          *(undefined4 *)(param_2 + 4 + uVar3 * 4) = **(undefined4 **)(lVar9 + 0x238);
        }
        lVar9 = lVar9 + 8;
        uVar3 = uVar8;
      } while (param_2 + (ulong)uVar1 * 8 != lVar9);
    }
    else {
      *(int *)(param_2 + 4) = param_3;
    }
  }
  return 0;
}


// ===== 004e5960 kvgpumgrGetCreatableVgpuTypes =====

int kvgpumgrGetCreatableVgpuTypes
              (long param_1,long param_2,ulong param_3,int param_4,uint *param_5,int *param_6)

{
  long lVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  int *piVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  long lVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  char local_45;
  int local_44;
  long local_40 [2];
  
  param_3 = param_3 & 0xffffffff;
  lVar18 = param_3 * 0xbbb80;
  lVar1 = param_2 + 0x48 + lVar18;
  *param_5 = 0;
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar3 = kmigmgrIsMIGEnabled_IMPL(), cVar3 == '\0')) {
    *param_5 = 0;
    if (*(int *)(param_2 + 0x250 + param_3 * 0xbbb80) == 0) {
      return 0;
    }
    lVar2 = param_3 * 0xbbb80 + param_2;
    lVar14 = 0;
    do {
      while ((*(int *)(*(long *)(lVar18 + param_2 + 0x280 + lVar14 * 8) + 0x330) != 0 ||
             (iVar6 = kvgpumgrCheckVgpuTypeCreatable(param_1,lVar1), iVar6 != 0))) {
        lVar14 = lVar14 + 1;
        if (*(uint *)(lVar2 + 0x250) <= (uint)lVar14) {
          return 0;
        }
      }
      lVar8 = lVar14 * 8;
      lVar14 = lVar14 + 1;
      param_6[*param_5] = **(int **)(lVar18 + param_2 + 0x280 + lVar8);
      *param_5 = *param_5 + 1;
    } while ((uint)lVar14 < *(uint *)(lVar2 + 0x250));
  }
  else {
    lVar2 = *(long *)(param_1 + 0x1bc0);
    if ((lVar2 != 0) &&
       (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1,lVar2), cVar3 != '\0')) {
      uVar7 = kmigmgrGetSwizzIdInUseMask_IMPL(param_1,lVar2);
      uVar16 = 0;
      lVar14 = param_2 + lVar18;
      do {
        iVar6 = (int)uVar16;
        if (((uVar7 >> (uVar16 & 0x3f) & 1) != 0) && ((param_4 == iVar6 || (param_4 == -1)))) {
          iVar4 = kmigmgrGetGPUInstanceInfo_IMPL(param_1,lVar2,uVar16 & 0xffffffff,local_40);
          if (iVar4 != 0) {
            nvAssertOkFailedNoLog
                      (iVar4,
                       "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, id, &pKernelMIGGpuInstance)"
                       ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1c9);
            return iVar4;
          }
          iVar4 = kvgpuMgrGetHeterogeneousMode(param_1,iVar6,&local_45);
          if (iVar4 != 0x5b) {
            piVar13 = &vgpuSmcTypeIdMappings;
            if (local_45 == '\0') {
LAB_004e5b31:
              if ((*piVar13 == *(int *)(param_1 + 0x7f4)) &&
                 (piVar13[1] == *(int *)(local_40[0] + 0x96c))) {
                if (*(int *)(lVar14 + 0xbbb58 + uVar16 * 4) == 0) {
                  if (*(int *)(param_2 + 0x250 + lVar18) != 0) {
                    lVar8 = 0;
                    do {
                      if (*(long *)(lVar14 + 0x280 + lVar8 * 8) != 0) {
                        cVar3 = kvgpumgrIsMigTimeslicingModeEnabled(param_1);
                        piVar10 = *(int **)(lVar14 + 0x280 + lVar8 * 8);
                        if (((cVar3 != '\0') || (piVar10[0xe3] == 1)) &&
                           (iVar4 = piVar13[2], *piVar10 == iVar4)) {
                          if (iVar4 != 0) {
                            uVar12 = *param_5;
                            uVar11 = 0;
                            piVar10 = param_6;
                            if (uVar12 != 0) goto LAB_004e5ecb;
                            goto LAB_004e5edf;
                          }
                          break;
                        }
                      }
                      lVar8 = lVar8 + 1;
                    } while ((uint)lVar8 < *(uint *)(param_2 + 0x250 + lVar18));
                  }
                }
                else if ((*(char *)(param_2 + lVar18 + 0xbbb99) != '\0') &&
                        (uVar12 = *(uint *)(param_2 + lVar18 + 0x250), uVar12 != 0)) {
                  piVar10 = (int *)0x0;
                  lVar8 = lVar14;
                  do {
                    piVar9 = *(int **)(lVar8 + 0x280);
                    if ((piVar9 != (int *)0x0) && (*piVar9 == piVar13[2])) {
                      piVar10 = piVar9;
                    }
                    lVar8 = lVar8 + 8;
                  } while (lVar8 != param_2 + ((ulong)uVar12 + param_3 * 0x17770) * 8);
                  if ((piVar10 != (int *)0x0) &&
                     (iVar5 = _kvgpumgrGetCreatedVgpuOnGpuInstance(param_1,iVar6,&local_44),
                     iVar4 = local_44, iVar5 == 0)) {
                    lVar8 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
                    piVar9 = (int *)listHead_IMPL(lVar8);
                    while( true ) {
                      if (piVar9 == (int *)0x0) {
                        nvAssertOkFailedNoLog
                                  (0x57,"kvgpumgrGetVgpuTypeInfo(vgpuTypeId, &existingVgpuTypeInfo)"
                                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x211);
                        return 0x57;
                      }
                      if (iVar4 == *piVar9) break;
                      piVar9 = (int *)listNext_IMPL(lVar8);
                    }
                    if (*(uint *)(lVar14 + 0xbbb58 + uVar16 * 4) < (uint)piVar9[0xe3]) {
                      iVar4 = osIsVgpuVfioPresent();
                      if (iVar4 != 0) {
                        iVar4 = osIsVgpuDeviceVmPresent();
                        uVar12 = 0;
                        if (iVar4 != 0) {
                          if ((*piVar9 == *piVar10) && (iVar4 = piVar13[2], iVar4 != 0)) {
                            uVar11 = *param_5;
                            piVar10 = param_6;
                            if (uVar11 != 0) {
                              do {
                                if (iVar4 == *piVar10) {
                                  if (uVar11 != uVar12) goto LAB_004e5b20;
                                  break;
                                }
                                uVar12 = uVar12 + 1;
                                piVar10 = piVar10 + 1;
                              } while (uVar11 != uVar12);
                            }
                            param_6[uVar11] = iVar4;
                            *param_5 = *param_5 + 1;
                          }
                          goto LAB_004e5b20;
                        }
                      }
                      uVar12 = 0;
                      if ((*(long *)(piVar9 + 0xd2) == *(long *)(piVar10 + 0xd2)) &&
                         (iVar4 = piVar13[2], iVar4 != 0)) {
                        uVar11 = *param_5;
                        piVar10 = param_6;
                        if (uVar11 != 0) {
                          do {
                            if (iVar4 == *piVar10) {
                              if (uVar11 != uVar12) goto LAB_004e5b20;
                              break;
                            }
                            uVar12 = uVar12 + 1;
                            piVar10 = piVar10 + 1;
                          } while (uVar12 != uVar11);
                        }
                        param_6[uVar11] = iVar4;
                        *param_5 = *param_5 + 1;
                      }
                    }
                  }
                }
              }
              goto LAB_004e5b20;
            }
            lVar8 = kvgpuMgrGetVgpuCreatableTypeIdFromSwizzId(param_1,lVar1,uVar16 & 0xffffffff);
            lVar17 = param_3 * 0xbbb80 + param_2;
            if (*(int *)(lVar17 + 0x250) != 0) {
              lVar15 = 0;
              do {
                iVar6 = *(int *)(lVar8 + lVar15 * 4);
                if (iVar6 == 0) break;
                uVar12 = *param_5;
                piVar13 = param_6;
                if (uVar12 != 0) {
                  uVar11 = 0;
                  do {
                    if (iVar6 == *piVar13) {
                      if (uVar12 != uVar11) goto LAB_004e5f93;
                      break;
                    }
                    uVar11 = uVar11 + 1;
                    piVar13 = piVar13 + 1;
                  } while (uVar11 != uVar12);
                  piVar13 = param_6 + uVar12;
                }
                *piVar13 = iVar6;
                *param_5 = *param_5 + 1;
LAB_004e5f93:
                lVar15 = lVar15 + 1;
              } while ((uint)lVar15 < *(uint *)(lVar17 + 0x250));
            }
          }
        }
LAB_004e5a79:
        uVar16 = uVar16 + 1;
      } while (uVar16 != 0xf);
    }
  }
  return 0;
  while( true ) {
    uVar11 = uVar11 + 1;
    piVar10 = piVar10 + 1;
    if (uVar11 == uVar12) break;
LAB_004e5ecb:
    if (iVar4 == *piVar10) {
      if (uVar12 != uVar11) goto LAB_004e5b20;
      break;
    }
  }
  piVar10 = param_6 + uVar12;
LAB_004e5edf:
  *piVar10 = iVar4;
  *param_5 = *param_5 + 1;
LAB_004e5b20:
  piVar13 = piVar13 + 3;
  if (piVar13 == (int *)&DAT_00da262c) goto LAB_004e5a79;
  goto LAB_004e5b31;
}


// ===== 004e60a0 kvgpumgrGuestUnregister =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrGuestUnregister(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  int *piVar7;
  undefined8 uVar8;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  uint uVar9;
  undefined8 uStack_c0;
  undefined8 local_a8;
  undefined8 local_a0;
  int local_98;
  undefined4 uStack_94;
  undefined4 local_48;
  undefined8 local_40;
  
  lVar2 = *(long *)(g_pSys + 0x1f8);
  lVar6 = rmapiGetInterface(4);
  uVar1 = param_2[6];
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x601,"kvgpumgrGuestUnregister",1,
               "NVRM: Enter function\n");
  if (*(char *)(param_1 + 0x491d) == '\0') {
    if (*(long *)(param_1 + 0x1bc0) != 0) {
LAB_004e6121:
      cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1);
      if ((cVar3 != '\0') && (*(char *)(param_2 + 0x150) == '\0')) {
        iVar5 = kmigmgrGetGPUInstanceInfo_IMPL
                          (param_1,*(undefined8 *)(param_1 + 0x1bc0),param_2[7],&local_98);
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, pKernelHostVgpuDevice->swizzId, &pKernelMIGGpuInstance)"
                     ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x618);
          goto LAB_004e6184;
        }
        iVar5 = kvgpuMgrRestoreSmcExecPart(param_1,param_2,CONCAT44(uStack_94,local_98));
        if (iVar5 != 0) {
          nvAssertOkFailedNoLog
                    (iVar5,
                     "kvgpuMgrRestoreSmcExecPart(pGpu, pKernelHostVgpuDevice, pKernelMIGGpuInstance)"
                     ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x61d);
          goto LAB_004e6184;
        }
        portMemSet(param_2 + 0x152,0,0x340);
      }
      goto LAB_004e613c;
    }
LAB_004e6300:
    portMemFree(*(undefined8 *)(param_2 + 200));
    *(undefined8 *)(param_2 + 200) = 0;
    if (*(long *)(param_2 + 0xbe) == 0) {
      cVar3 = *(char *)(param_1 + 0x491d);
    }
    else {
LAB_004e615a:
      portMemFree();
      *(undefined8 *)(param_2 + 0xbe) = 0;
      param_2[0xc0] = 0;
      cVar3 = *(char *)(param_1 + 0x491d);
    }
    if (cVar3 == '\0') goto LAB_004e6184;
  }
  else {
    iVar5 = gpuGetGfidState_IMPL(param_1,uVar1,&local_98);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"gpuGetGfidState(pGpu, gfid, &gfidState)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x608);
      goto LAB_004e6184;
    }
    if (local_98 == 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x60d,"kvgpumgrGuestUnregister",4,
                   "NVRM: Request to unregister Invalid GFID\n");
      goto LAB_004e6184;
    }
    if (*(long *)(param_1 + 0x1bc0) != 0) goto LAB_004e6121;
LAB_004e613c:
    if (*(char *)(param_1 + 0x491d) == '\0') goto LAB_004e6300;
    if (*(long *)(param_2 + 0xbe) != 0) goto LAB_004e615a;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    uVar8 = gpuGetKernelFifoShared_IMPL(param_1);
    local_a8 = 0;
    portMemSet(&local_98,0,0x60);
    if ((*(long *)(param_1 + 0x1bc0) == 0) ||
       (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar3 == '\0')) {
LAB_004e6486:
      iVar5 = kfifoGetHostDeviceInfoTable_KERNEL(param_1,uVar8,&local_98,local_a8);
      if (iVar5 == 0) {
        vgpuMgrFreeSystemChannelIDs
                  (param_1,param_2[6],param_2 + 0xb,param_2 + 0x5f,local_a8,local_48,local_40);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kfifoGetHostDeviceInfoTable_HAL(pGpu, pKernelFifo, &tmpEngineInfo, pMigDevice)",
                   "src/kernel/virtualization/kernel_vgpu_mgr.c",0x64b);
      }
    }
    else {
      iVar5 = serverGetClientUnderLock(g_resServ,param_2[1],&local_a0);
      if (iVar5 == 0) {
        iVar5 = deviceGetByHandle_IMPL(local_a0,param_2[2],&local_a8);
        if (iVar5 == 0) goto LAB_004e6486;
        nvAssertOkFailedNoLog
                  (iVar5,
                   "deviceGetByHandle(pClient, pKernelHostVgpuDevice->hMigDevice, &pMigDevice)",
                   "src/kernel/virtualization/kernel_vgpu_mgr.c",0x646);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "serverGetClientUnderLock(&g_resServ, pKernelHostVgpuDevice->hMigClient, &pClient)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x642);
      }
    }
    portMemFree(local_40);
  }
  gpuSetGfidUsage_IMPL(param_1,uVar1,0);
LAB_004e6184:
  if ((*(long *)(param_1 + 0x1bc0) != 0) &&
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar3 != '\0')) {
    (**(code **)(lVar6 + 0x18))(lVar6,param_2[1],param_2[1]);
    *(undefined8 *)(param_2 + 1) = 0;
  }
  piVar7 = (int *)(lVar2 + 0x48);
  uVar9 = 0;
  while ((*(int *)(param_1 + 0x7ac) != *piVar7 || ((char)piVar7[0x18e] != '\x01'))) {
    uVar9 = uVar9 + 1;
    piVar7 = piVar7 + 0x2eee0;
    if (uVar9 == 0x20) {
      return 0x57;
    }
  }
  if (*(long *)(param_2 + 4) == 0) {
    cVar3 = hypervisorIsType_IMPL(2);
    if (cVar3 == '\0') {
      return 0x10007;
    }
  }
  else {
    lVar6 = *(long *)(g_pSys + 0x1f8);
    piVar7 = (int *)(*(long *)(param_2 + 4) + 0x98);
    *piVar7 = *piVar7 + -1;
    if (*piVar7 == 0) {
      listRemove_IMPL(lVar6 + 0x1777078);
    }
    *(undefined8 *)(param_2 + 4) = 0;
  }
  lVar6 = (ulong)uVar9 * 0xbbb80;
  piVar7 = (int *)(lVar2 + lVar6 + 0x24c);
  *piVar7 = *piVar7 + -1;
  if ((*piVar7 == 0) && (*(int *)(lVar2 + lVar6 + 0xbb83c) == 0)) {
    kvgpumgrSetVgpuType(param_1,lVar2 + 0x48 + lVar6,0,param_2[7]);
  }
  if (*(long *)(param_2 + 0xb8) != 0) {
    *(undefined8 *)(*(long *)(param_2 + 0xb8) + 0x28) = 0;
  }
  iVar4 = osIsVgpuVfioPresent();
  iVar5 = 0;
  if ((iVar4 != 0) && (iVar5 = 0, param_2[7] != -1)) {
    iVar5 = _kvgpumgrClearAssignedSwizzIdMask(param_1);
  }
  iVar4 = osIsVgpuVfioPresent();
  uVar8 = extraout_RDX;
  if ((iVar4 != 0) && (uVar8 = extraout_RDX, *(short *)(param_2 + 9) != -1)) {
    iVar4 = kvgpuMgrGetHeterogeneousMode(param_1,param_2[7],&local_98);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,
                 "kvgpuMgrGetHeterogeneousMode(pGpu, pKernelHostVgpuDevice->swizzId, &bHeterogeneousModeEnabled)"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x6a3);
      return iVar4;
    }
    if ((char)local_98 != '\0') {
      iVar5 = _kvgpumgrUpdateHeterogeneousCreatablePlacementIds
                        (param_1,*(undefined2 *)(param_2 + 9),*param_2,0,param_2[7]);
    }
    uStack_c0 = 0x4e62cd;
    iVar4 = kvgpumgrCheckHomogeneousPlacementSupported(param_1,param_2[7]);
    uVar8 = extraout_RDX_00;
    if (iVar4 == 0) {
      uStack_c0 = 0x4e65ff;
      iVar5 = _kvgpumgrUpdateHomogeneousCreatablePlacementIds
                        (param_1,*(undefined2 *)(param_2 + 9),*param_2,0,param_2[7]);
      uVar8 = extraout_RDX_01;
    }
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x6ba,"kvgpumgrGuestUnregister",4,
                   "NVRM: Failed to free placement ID: %d, error: 0x%x\n",
                   *(undefined2 *)(param_2 + 9),iVar5);
      uVar8 = uStack_c0;
    }
  }
  listRemove_IMPL(lVar2 + 600 + lVar6,param_2,uVar8);
  return iVar5;
}


// ===== 004e66e0 _kvgpumgrSetAssignedSwizzIdMask =====

undefined1  [16] _kvgpumgrSetAssignedSwizzIdMask(long param_1,long param_2,ulong param_3)

{
  ulong *puVar1;
  uint uVar2;
  long lVar3;
  char cVar4;
  undefined8 uVar5;
  int *piVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined8 uStack_40;
  char local_9;
  
  local_9 = '\0';
  lVar3 = *(long *)(g_pSys + 0x1f8);
  uVar5 = 0x1f;
  if (0xe < (uint)param_3) goto LAB_004e67f5;
  piVar6 = (int *)(lVar3 + 0x48);
  uVar9 = 0;
  while ((*(int *)(param_1 + 0x7ac) != *piVar6 || ((char)piVar6[0x18e] != '\x01'))) {
    uVar8 = (int)uVar9 + 1;
    uVar9 = (ulong)uVar8;
    piVar6 = piVar6 + 0x2eee0;
    if (uVar8 == 0x20) {
      auVar11._8_4_ = *(int *)(param_1 + 0x7ac);
      auVar11._0_8_ = 0x57;
      auVar11._12_4_ = 0;
      return auVar11;
    }
  }
  if (*(long *)(param_1 + 0x1bc0) == 0) {
LAB_004e67a0:
    uVar2 = *(uint *)(param_2 + 0x38c);
    uVar8 = *(uint *)(lVar3 + 8 + (uVar9 * 0x2eee0 + 0x2eed4 + (param_3 & 0xffffffff)) * 4);
    if (uVar2 <= uVar8) {
LAB_004e6854:
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x80d,
                   "_kvgpumgrSetAssignedSwizzIdMask",4,"NVRM: SwizzID - %d max vgpu count is %d\n",
                   (uint)param_3,uVar2);
      auVar12._8_8_ = uStack_40;
      auVar12._0_8_ = 0x1a;
      return auVar12;
    }
  }
  else {
    uStack_40 = 0x4e6768;
    cVar4 = kmigmgrIsMIGEnabled_IMPL();
    if (cVar4 == '\0') goto LAB_004e67a0;
    uStack_40 = 0x4e6784;
    cVar4 = kvgpumgrIsMigTimeslicingModeEnabled(param_1);
    if (cVar4 == '\0') goto LAB_004e67a0;
    uStack_40 = 0x4e6815;
    kvgpuMgrGetHeterogeneousMode(param_1,param_3 & 0xffffffff,&local_9);
    uVar2 = *(uint *)(param_2 + 0x38c);
    uVar8 = *(uint *)(lVar3 + 8 + (uVar9 * 0x2eee0 + 0x2eed4 + (param_3 & 0xffffffff)) * 4);
    if ((uVar2 <= uVar8) && (local_9 == '\0')) goto LAB_004e6854;
  }
  uVar7 = param_3 & 0xffffffff;
  param_3 = uVar9 * 0x2eee0 + 0x2eed4 + uVar7;
  *(uint *)(lVar3 + 8 + param_3 * 4) = uVar8 + 1;
  puVar1 = (ulong *)(lVar3 + 0xbbb50 + uVar9 * 0xbbb80);
  *puVar1 = *puVar1 | 1L << ((byte)uVar7 & 0x3f);
  uVar5 = 0;
LAB_004e67f5:
  auVar10._8_8_ = param_3;
  auVar10._0_8_ = uVar5;
  return auVar10;
}


// ===== 004e68a0 kvgpumgrValidateSwizzId =====

int kvgpumgrValidateSwizzId(long param_1,int param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  long local_30;
  
  uVar2 = *(undefined8 *)(param_1 + 0x1bc0);
  cVar3 = kmigmgrIsSwizzIdInUse_IMPL(param_1,uVar2);
  if (cVar3 == '\0') {
    return 0x1f;
  }
  iVar4 = kmigmgrGetGPUInstanceInfo_IMPL(param_1,uVar2,param_3,&local_30);
  piVar5 = &DAT_00da1848;
  uVar6 = 0;
  if (iVar4 != 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8c6,"kvgpumgrValidateSwizzId",4,
                 "NVRM: No valid GPU instance with SwizzId - %d found\n",param_3);
    return iVar4;
  }
  while (param_2 != *piVar5) {
    uVar6 = uVar6 + 1;
    piVar5 = piVar5 + 3;
    if (uVar6 == 0x129) {
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,"kvgpumgrGetPartitionFlag",4,
                   "NVRM: Invalid SMC vGpu TypeId: 0x%x\n",param_2);
      nvAssertOkFailedNoLog
                (0x1f,"kvgpumgrGetPartitionFlag(vgpuTypeId, &partitionFlag)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x8ca);
      return 0x1f;
    }
  }
  if (*(int *)(local_30 + 0x96c) != (&DAT_00da1844)[(ulong)uVar6 * 3]) {
    return 0x40;
  }
  lVar1 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar5 = (int *)listHead_IMPL(lVar1);
  while( true ) {
    if (piVar5 == (int *)0x0) {
      nvAssertOkFailedNoLog
                (0x57,"kvgpumgrGetVgpuTypeInfo(vgpuTypeId, &vgpuTypeInfo)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x8d0);
      return 0x57;
    }
    if (param_2 == *piVar5) break;
    piVar5 = (int *)listNext_IMPL(lVar1);
  }
  iVar4 = _kvgpumgrSetAssignedSwizzIdMask(param_1,piVar5,param_3);
  if (iVar4 != 0) {
    nvAssertOkFailedNoLog
              (iVar4,"_kvgpumgrSetAssignedSwizzIdMask(pGpu, vgpuTypeInfo, swizzId)",
               "src/kernel/virtualization/kernel_vgpu_mgr.c",0x8d1);
    return iVar4;
  }
  return 0;
}


// ===== 004e6a80 kvgpumgrGetSwizzId =====

int kvgpumgrGetSwizzId(long param_1,long param_2,int param_3,int *param_4,int *param_5)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  int *piVar7;
  ulong uVar8;
  char local_45;
  int local_44;
  long local_40 [2];
  
  uVar8 = 0;
  uVar2 = *(undefined8 *)(param_1 + 0x1bc0);
  uVar5 = kmigmgrGetSwizzIdInUseMask_IMPL(param_1,uVar2);
  do {
    if (((*param_5 == -1) || (*param_5 == (int)uVar8)) && ((uVar5 >> (uVar8 & 0x3f) & 1) != 0)) {
      iVar3 = kmigmgrGetGPUInstanceInfo_IMPL(param_1,uVar2,uVar8 & 0xffffffff,local_40);
      if (iVar3 != 0) {
        nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x86a,"kvgpumgrGetSwizzId",4,
                     "NVRM: No valid GPU instance with SwizzId - %d found\n",uVar8 & 0xffffffff);
        return iVar3;
      }
      if (*(int *)(local_40[0] + 0x96c) == param_3) {
        if (*(char *)(param_2 + 0xbbb51) == '\0') {
          if (*(uint *)(param_2 + 0xbbb10 + uVar8 * 4) < (uint)param_4[0xe3]) goto LAB_004e6b31;
        }
        else {
          iVar3 = kvgpuMgrGetHeterogeneousMode(param_1,uVar8 & 0xffffffff,&local_45);
          if (iVar3 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar3,"kvgpuMgrGetHeterogeneousMode(pGpu, id, &bHeterogeneousModeEnabled)",
                       "src/kernel/virtualization/kernel_vgpu_mgr.c",0x873);
            return iVar3;
          }
          if (local_45 == '\0') {
            if (*(int *)(param_2 + 0xbbb10 + uVar8 * 4) == 0) {
              if (param_4[0xe3] != 0) goto LAB_004e6b31;
            }
            else {
              iVar4 = _kvgpumgrGetCreatedVgpuOnGpuInstance(param_1,uVar8 & 0xffffffff,&local_44);
              iVar3 = local_44;
              if (iVar4 == 0) {
                lVar6 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
                piVar7 = (int *)listHead_IMPL(lVar6);
                while( true ) {
                  if (piVar7 == (int *)0x0) {
                    nvAssertOkFailedNoLog
                              (0x57,"kvgpumgrGetVgpuTypeInfo(vgpuTypeId, &existingVgpuTypeInfo)",
                               "src/kernel/virtualization/kernel_vgpu_mgr.c",0x88d);
                    return 0x57;
                  }
                  if (iVar3 == *piVar7) break;
                  piVar7 = (int *)listNext_IMPL(lVar6);
                }
                iVar3 = osIsVgpuVfioPresent();
                if ((iVar3 == 0) || (iVar3 = osIsVgpuDeviceVmPresent(), iVar3 == 0)) {
                  if (*(long *)(piVar7 + 0xd2) == *(long *)(param_4 + 0xd2)) goto LAB_004e6be2;
                }
                else if (*piVar7 == *param_4) goto LAB_004e6be2;
              }
              else {
LAB_004e6be2:
                if (*(uint *)(param_2 + 0xbbb10 + uVar8 * 4) < (uint)param_4[0xe3]) {
LAB_004e6b31:
                  iVar3 = _kvgpumgrSetAssignedSwizzIdMask
                                    (param_1,param_4,*(undefined4 *)(local_40[0] + 0x968));
                  if (iVar3 == 0) {
                    *param_5 = *(int *)(local_40[0] + 0x968);
                    return 0;
                  }
                  nvAssertOkFailedNoLog
                            (iVar3,
                             "_kvgpumgrSetAssignedSwizzIdMask(pGpu, vgpuTypeInfo, pKernelMIGGpuInstance->swizzId)"
                             ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x8a0);
                  return iVar3;
                }
              }
            }
          }
          else {
            piVar7 = (int *)kvgpuMgrGetVgpuCreatableTypeIdFromSwizzId
                                      (param_1,param_2,uVar8 & 0xffffffff);
            if (*(uint *)(param_2 + 0x208) != 0) {
              piVar1 = piVar7 + *(uint *)(param_2 + 0x208);
              do {
                if (*piVar7 == *param_4) goto LAB_004e6b31;
                piVar7 = piVar7 + 1;
              } while (piVar7 != piVar1);
            }
          }
        }
      }
    }
    uVar8 = uVar8 + 1;
    if (uVar8 == 0xf) {
      return 0x40;
    }
  } while( true );
}


// ===== 004e6da0 kvgpumgrGuestRegister =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrGuestRegister
              (long param_1,int param_2,int param_3,undefined4 param_4,uint param_5,int param_6,
              undefined8 param_7,undefined8 param_8,undefined8 param_9,uint param_10,uint param_11,
              undefined8 param_12,undefined1 param_13,undefined8 param_14,undefined8 param_15,
              int param_16,long *param_17)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  int *piVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  int *piVar14;
  long lVar15;
  uint uVar16;
  bool bVar17;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  undefined4 uStack_64;
  uint local_60;
  ulong local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar13 = *(long *)(g_pSys + 0x1f8);
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if ((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) {
    bVar17 = false;
  }
  else {
    cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    bVar17 = cVar4 != '\0';
  }
  nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x4f2,"kvgpumgrGuestRegister",1,
               "NVRM: Enter function\n");
  if (5 < param_10) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x4f6,"kvgpumgrGuestRegister",4,
                 "NVRM: failed, wrong number of plugin channels\n");
    return 0x3b;
  }
  if (*(char *)(param_1 + 0x4a4) != '\0') {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x4fc,"kvgpumgrGuestRegister",4,
                 "NVRM: GPU is previously set in vSGA mode!\n");
    return 0x26;
  }
  if (*(char *)(param_1 + 0x491d) == '\0') {
    param_10 = 0;
    if (bVar17) {
      nvAssertFailedNoLog("!bMIGInUse","src/kernel/virtualization/kernel_vgpu_mgr.c",0x509);
      return 0x40;
    }
  }
  else {
    iVar5 = gpuGetGfidState_IMPL(param_1,param_2,&local_68);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"gpuGetGfidState(pGpu, gfid, &gfidState)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x503);
      return iVar5;
    }
    if (local_68 != 0) {
      nvAssertFailedNoLog("(gfidState == GFID_FREE)","src/kernel/virtualization/kernel_vgpu_mgr.c",
                          0x504);
      return 0x1a;
    }
  }
  piVar10 = (int *)(lVar13 + 0x48);
  uVar7 = 0;
  while ((*(int *)(param_1 + 0x7ac) != *piVar10 || ((char)piVar10[0x18e] != '\x01'))) {
    uVar7 = uVar7 + 1;
    piVar10 = piVar10 + 0x2eee0;
    if (uVar7 == 0x20) {
      return 0x57;
    }
  }
  uVar8 = (ulong)uVar7;
  lVar9 = uVar8 * 0xbbb80;
  lVar15 = lVar13 + lVar9;
  uVar7 = *(uint *)(lVar15 + 0x250);
  if (uVar7 == 0) {
    return 0x56;
  }
  uVar16 = 0;
  lVar12 = lVar15;
  while (**(int **)(lVar12 + 0x280) != param_3) {
    uVar16 = uVar16 + 1;
    lVar12 = lVar12 + 8;
    if (uVar7 == uVar16) {
      return 0x56;
    }
  }
  if (uVar7 == uVar16) {
    return 0x56;
  }
  lVar12 = 0;
  iVar5 = osIsVgpuVfioPresent();
  if (iVar5 == 0) {
    lVar12 = listHead_IMPL(lVar13 + 0x17770b0);
    while( true ) {
      if (lVar12 == 0) {
        return 0x57;
      }
      iVar5 = portMemCmp(lVar12 + 4,param_15,0x10);
      if (iVar5 == 0) break;
      lVar12 = listNext_IMPL(lVar13 + 0x17770b0,lVar12);
    }
  }
  lVar1 = lVar13 + 0x48 + lVar9;
  if (*(long *)(param_1 + 0x1bc0) == 0) {
LAB_004e71e4:
    if (*(char *)(param_1 + 0x4a5) == '\0') {
      lVar11 = uVar8 * 0xbbb80 + lVar13;
      uVar7 = *(uint *)(lVar11 + 0x24c);
      if (uVar7 != 0) {
        uVar2 = *(uint *)(lVar11 + 0x250);
        piVar10 = *(int **)(lVar13 + 0x10 + ((ulong)uVar16 + 0x4e + uVar8 * 0x17770) * 8);
        if (uVar2 != 0) {
          do {
            if (*(int *)(lVar15 + 0x4c) == *piVar10) break;
            if (*(int *)(lVar15 + 0x4c) == 0) {
              return 0x56;
            }
            lVar15 = lVar15 + 4;
          } while (lVar15 != lVar13 + ((ulong)uVar2 + uVar8 * 0x2eee0) * 4);
        }
        if ((uint)piVar10[0xc4] <= uVar7) {
          return 0x1a;
        }
      }
      iVar5 = kvgpumgrSetVgpuType(param_1,lVar1,param_3,0xffffffff);
      if (iVar5 != 0) {
        return iVar5;
      }
    }
  }
  else {
    cVar4 = kmigmgrIsMIGEnabled_IMPL(param_1);
    if ((cVar4 != '\0') && (iVar5 = osIsVgpuDeviceVmPresent(), iVar5 == 0)) {
      if (0xe < param_11) {
        return 0x1f;
      }
      piVar10 = &DAT_00da1848;
      uVar7 = 0;
      while (param_3 != *piVar10) {
        uVar7 = uVar7 + 1;
        piVar10 = piVar10 + 3;
        if (uVar7 == 0x129) {
          nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,
                       "kvgpumgrGetPartitionFlag",4,"NVRM: Invalid SMC vGpu TypeId: 0x%x\n",param_3)
          ;
          nvAssertOkFailedNoLog
                    (0x1f,"kvgpumgrGetPartitionFlag(vgpuType, &partitionFlag)",
                     "src/kernel/virtualization/kernel_vgpu_mgr.c",0x53f);
          return 0x1f;
        }
      }
      iVar5 = kvgpumgrGetSwizzId(param_1,lVar1,(&DAT_00da1844)[(ulong)uVar7 * 3],
                                 *(undefined8 *)
                                  (lVar13 + 0x10 + ((ulong)uVar16 + 0x4e + uVar8 * 0x17770) * 8),
                                 &param_11);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kvgpumgrGetSwizzId(pGpu, pPhysGpuInfo, partitionFlag, pPhysGpuInfo->vgpuTypes[vgpuTypeIdx], &swizzId)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x541);
        return iVar5;
      }
    }
    if ((*(long *)(param_1 + 0x1bc0) == 0) ||
       (cVar4 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar4 == '\0')) goto LAB_004e71e4;
  }
  lVar9 = lVar13 + 600 + lVar9;
  iVar5 = listCount_IMPL(lVar9);
  if (iVar5 == 0x30) {
    if (*(char *)(param_1 + 0x491d) != '\0') {
      gpuSetGfidUsage_IMPL(param_1,param_2,0);
    }
    iVar5 = 0x1a;
    goto LAB_004e73c9;
  }
  piVar10 = (int *)listAppendNew_IMPL(lVar9);
  if (piVar10 == (int *)0x0) {
    if (*(char *)(param_1 + 0x491d) != '\0') {
      gpuSetGfidUsage_IMPL(param_1,param_2,0);
    }
    iVar5 = 0x51;
    goto LAB_004e73c9;
  }
  portMemSet(piVar10,0,0x890);
  *piVar10 = param_3;
  if (1 < param_5) {
    nvAssertFailedNoLog("((vmIdType == VM_ID_DOMAIN_ID) || (vmIdType == VM_ID_UUID))",
                        "src/kernel/virtualization/kernel_vgpu_mgr.c",0x568);
    return 0x1f;
  }
  local_58 = CONCAT44(param_4,(int)local_58) & 0xffffffffffffff00;
  local_50 = CONCAT44(local_50._4_4_,param_5);
  if (param_5 == 0) {
    local_48 = param_7;
  }
  else {
    portMemCopy(&local_48,0x10,&param_7,0x10);
  }
  iVar5 = kvgpumgrRegisterGuestId(&local_58,piVar10,param_1);
  uVar7 = param_11;
  if (iVar5 == 0) {
    *(undefined2 *)(piVar10 + 9) = 0xffff;
    piVar10[6] = param_2;
    piVar10[7] = param_11;
    piVar10[8] = param_16;
    piVar10[10] = param_10;
    *(undefined1 *)(piVar10 + 0x150) = param_13;
    if ((*(long *)(param_1 + 0x1bc0) != 0) &&
       (cVar4 = kmigmgrIsMIGEnabled_IMPL(param_1), cVar4 != '\0')) {
      iVar5 = **(int **)(lVar13 + 0x10 + ((ulong)uVar16 + 0x4e + uVar8 * 0x17770) * 8);
      lVar15 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
      piVar14 = (int *)listHead_IMPL(lVar15);
      while( true ) {
        if (piVar14 == (int *)0x0) {
          nvAssertOkFailedNoLog
                    (0x57,
                     "kvgpumgrGetVgpuTypeInfo(pPhysGpuInfo->vgpuTypes[vgpuTypeIdx]->vgpuTypeId, &pVgpuTypeInfo)"
                     ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x58a);
          return 0x57;
        }
        if (iVar5 == *piVar14) break;
        piVar14 = (int *)listNext_IMPL(lVar15);
      }
      if (1 < (uint)piVar14[0xe3]) {
        *(undefined1 *)(piVar10 + 0x150) = 1;
      }
    }
    iVar5 = osIsVgpuVfioPresent();
    if (iVar5 == 0) {
      *(long *)(piVar10 + 0xb8) = lVar12;
      *(int **)(lVar12 + 0x28) = piVar10;
    }
    *(undefined1 *)(piVar10 + 0xc6) = 0;
    piVar10[0xc1] = param_6;
    piVar10[0xc2] = 0;
    piVar10[0xc3] = 0;
    piVar10[0xc4] = 0;
    piVar10[0xc5] = 0;
    *(undefined1 *)(piVar10 + 0xcc) = 0;
    piVar14 = (int *)(lVar13 + 0x24c + uVar8 * 0xbbb80);
    *piVar14 = *piVar14 + 1;
    if (((*(char *)(param_1 + 0x491d) == '\0') ||
        (gpuSetGfidUsage_IMPL(param_1,param_2,1), *(char *)(param_1 + 0x491d) == '\0')) || (!bVar17)
       ) goto LAB_004e7131;
    lVar13 = rmapiGetInterface(4);
    iVar5 = rmapiutilAllocClientAndDeviceHandles(lVar13,param_1,piVar10 + 1,piVar10 + 2,&local_70);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "rmapiutilAllocClientAndDeviceHandles(pRmApi, pGpu, phClient, phDevice, &hSubDevice)"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x45a);
LAB_004e787b:
      nvAssertOkFailedNoLog
                (iVar5,
                 "_kvgpumgrVgpuAllocGPUInstanceSubscription(pGpu, &pKernelHostVgpuDevice->hMigClient, &pKernelHostVgpuDevice->hMigDevice, swizzId)"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x5b4);
      cVar4 = *(char *)(param_1 + 0x491d);
      goto joined_r0x004e751d;
    }
    iVar5 = serverutilGenResourceHandle(piVar10[1],&local_6c);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"serverutilGenResourceHandle(*phClient, &hGPUInstanceSubscription)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x45e);
LAB_004e785f:
      (**(code **)(lVar13 + 0x18))(lVar13,piVar10[1],piVar10[1]);
      goto LAB_004e787b;
    }
    portMemSet(&local_68,0,0x10);
    local_60 = uVar7;
    iVar5 = (**(code **)(lVar13 + 8))(lVar13,piVar10[1],local_70,local_6c,0xc637,&local_68,0x10);
    if (iVar5 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "pRmApi->AllocWithHandle(pRmApi, *phClient, hSubDevice, hGPUInstanceSubscription, AMPERE_SMC_PARTITION_REF, &nvC637AllocParams, sizeof(nvC637AllocParams))"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x466);
      goto LAB_004e785f;
    }
    if ((*(char *)(param_1 + 0x491d) == '\0') || ((char)piVar10[0x150] != '\0')) {
LAB_004e7131:
      *param_17 = (long)piVar10;
      return 0;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar5 = kmigmgrGetGPUInstanceInfo_IMPL(param_1,uVar3,uVar7,&local_68);
    if (iVar5 == 0) {
      iVar5 = kmigmgrSaveComputeInstances_IMPL
                        (param_1,uVar3,CONCAT44(uStack_64,local_68),piVar10 + 0x152);
      if (iVar5 == 0) {
        cVar4 = kmigmgrIsPartitionVeidAllocationContiguous_IMPL
                          (param_1,uVar3,CONCAT44(uStack_64,local_68));
        if ((cVar4 != '\0') ||
           (iVar5 = kvgpuMgrRestoreSmcExecPart(param_1,piVar10,CONCAT44(uStack_64,local_68)),
           iVar5 == 0)) goto LAB_004e7131;
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kvgpuMgrRestoreSmcExecPart(pGpu, pKernelHostVgpuDevice, pKernelMIGGpuInstance)",
                   "src/kernel/virtualization/kernel_vgpu_mgr.c",0x5d3);
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kmigmgrSaveComputeInstances(pGpu, pKernelMIGManager, pKernelMIGGpuInstance, pKernelHostVgpuDevice->savedExecPartitions)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x5ca);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar5,
                 "kmigmgrGetGPUInstanceInfo(pGpu, pKernelMIGManager, swizzId, &pKernelMIGGpuInstance)"
                 ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x5c2);
    }
    if (*(char *)(param_1 + 0x491d) != '\0') {
      gpuSetGfidUsage_IMPL(param_1,param_2,0);
    }
  }
  else {
    cVar4 = *(char *)(param_1 + 0x491d);
joined_r0x004e751d:
    if (cVar4 != '\0') {
      gpuSetGfidUsage_IMPL(param_1,param_2,0);
    }
  }
  if (*(long *)(piVar10 + 4) != 0) {
    local_58 = CONCAT71(local_58._1_7_,1);
    lVar13 = *(long *)(g_pSys + 0x1f8);
    piVar14 = (int *)(*(long *)(piVar10 + 4) + 0x98);
    *piVar14 = *piVar14 + -1;
    if (*piVar14 == 0) {
      listRemove_IMPL(lVar13 + 0x1777078);
    }
    piVar10[4] = 0;
    piVar10[5] = 0;
  }
  listRemove_IMPL(lVar9,piVar10);
LAB_004e73c9:
  iVar6 = osIsVgpuVfioPresent();
  if (iVar6 == 0) {
    return iVar5;
  }
  if (param_11 == 0xffffffff) {
    return iVar5;
  }
  _kvgpumgrClearAssignedSwizzIdMask(param_1);
  return iVar5;
}


// ===== 004e7a00 kvgpumgrDeleteRequestVgpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrDeleteRequestVgpu(undefined8 param_1,undefined2 param_2)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  long lVar9;
  uint uVar10;
  ulong uVar11;
  undefined4 *puVar12;
  char local_39 [9];
  
  lVar3 = *(long *)(g_pSys + 0x1f8);
  puVar7 = (undefined4 *)listHead_IMPL(lVar3 + 0x17770b0);
  do {
    puVar12 = puVar7;
    if (puVar12 == (undefined4 *)0x0) {
      return 0x57;
    }
    puVar7 = (undefined4 *)listNext_IMPL(lVar3 + 0x17770b0,puVar12);
    iVar6 = portMemCmp(param_1,puVar12 + 1,0x10);
  } while (iVar6 != 0);
  piVar8 = (int *)(lVar3 + 0x48);
  uVar11 = 0;
  while ((puVar12[5] != *piVar8 || ((char)piVar8[0x18e] != '\x01'))) {
    uVar10 = (int)uVar11 + 1;
    uVar11 = (ulong)uVar10;
    piVar8 = piVar8 + 0x2eee0;
    if (uVar10 == 0x20) {
      return 0x57;
    }
  }
  lVar9 = gpumgrGetGpuFromId();
  uVar2 = puVar12[6];
  lVar1 = lVar3 + uVar11 * 0xbbb80;
  iVar6 = *(int *)(lVar1 + 0xbb83c) + -1;
  *(int *)(lVar1 + 0xbb83c) = iVar6;
  if (lVar9 == 0) {
    if (iVar6 == 0) {
      kvgpumgrSetVgpuType(0,lVar3 + 0x48 + uVar11 * 0xbbb80,0,puVar12[7]);
    }
  }
  else {
    if (*(char *)(lVar9 + 0x878) != (char)uVar2) {
      bVar4 = (char)uVar2 - *(char *)(lVar9 + 0x3a5c) & 0x3f;
      *(ulong *)(lVar1 + 0xbbb40) =
           *(ulong *)(lVar1 + 0xbbb40) & (-2L << bVar4 | 0xfffffffffffffffeU >> 0x40 - bVar4);
    }
    if (*(long *)(lVar9 + 0x1bc0) == 0) {
      if (iVar6 != 0) goto LAB_004e7b80;
LAB_004e7bee:
      kvgpumgrSetVgpuType(lVar9,lVar3 + 0x48 + uVar11 * 0xbbb80,0,puVar12[7]);
    }
    else {
      cVar5 = kmigmgrIsMIGEnabled_IMPL(lVar9);
      if (cVar5 == '\0') {
        if (*(int *)(lVar3 + 0xbb83c + uVar11 * 0xbbb80) == 0) goto LAB_004e7bee;
      }
      else {
        _kvgpumgrClearAssignedSwizzIdMask(lVar9,puVar12[7]);
      }
    }
    if (((*(long *)(lVar9 + 0x1bc0) != 0) &&
        (cVar5 = kmigmgrIsMIGEnabled_IMPL(lVar9), cVar5 != '\0')) &&
       ((*(long *)(lVar9 + 0x1bc0) == 0 ||
        ((cVar5 = kmigmgrIsMIGEnabled_IMPL(lVar9), cVar5 == '\0' ||
         (cVar5 = kvgpumgrIsMigTimeslicingModeEnabled(lVar9), cVar5 == '\0')))))) goto LAB_004e7bc0;
  }
LAB_004e7b80:
  iVar6 = kvgpuMgrGetHeterogeneousMode(lVar9,puVar12[7],local_39);
  if (iVar6 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar6,
               "kvgpuMgrGetHeterogeneousMode(pGpu, pRequestVgpu->swizzId, &bHeterogeneousModeEnabled)"
               ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0xad5);
    return iVar6;
  }
  if (local_39[0] == '\0') {
    iVar6 = kvgpumgrCheckHomogeneousPlacementSupported(lVar9,puVar12[7]);
    if (iVar6 != 0) goto LAB_004e7bc0;
    iVar6 = _kvgpumgrUpdateHomogeneousCreatablePlacementIds
                      (lVar9,*(undefined2 *)(puVar12 + 8),*puVar12,0,puVar12[7]);
  }
  else {
    iVar6 = _kvgpumgrUpdateHeterogeneousCreatablePlacementIds
                      (lVar9,*(undefined2 *)(puVar12 + 8),*puVar12,0);
  }
  if (iVar6 != 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xae5,"kvgpumgrDeleteRequestVgpu",4,
                 "NVRM: Failed to free up allocated placementId, status: 0x%x\n");
  }
LAB_004e7bc0:
  (**(code **)(*(long *)(lVar3 + 0x17770a8) + 0x10))(*(long *)(lVar3 + 0x17770a8),param_2);
  listRemove_IMPL(lVar3 + 0x17770b0,puVar12);
  return 0;
}


// ===== 004e7cc0 kvgpumgrSetPlacementId =====

int kvgpumgrSetPlacementId(int *param_1,uint param_2)

{
  ushort *puVar1;
  long lVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  long lVar6;
  int *piVar7;
  long lVar8;
  ushort *puVar9;
  long lVar10;
  ushort uVar11;
  uint uVar12;
  ulong uVar13;
  long lVar14;
  uint local_5c;
  char local_39 [9];
  
  if ((param_1[8] != 0xffff) && (param_1[8] == param_2)) {
    return 0;
  }
  lVar2 = *(long *)(g_pSys + 0x1f8);
  lVar6 = gpumgrGetGpuFromId(param_1[5]);
  if (lVar6 == 0) {
    return 0x56;
  }
  uVar13 = 0;
  piVar7 = (int *)(lVar2 + 0x48);
  while ((*(int *)(lVar6 + 0x7ac) != *piVar7 || ((char)piVar7[0x18e] != '\x01'))) {
    uVar12 = (int)uVar13 + 1;
    uVar13 = (ulong)uVar12;
    piVar7 = piVar7 + 0x2eee0;
    if (uVar12 == 0x20) {
      nvCheckOkFailedNoLog
                (4,0x57,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &index)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1245);
      return 0x57;
    }
  }
  lVar8 = uVar13 * 0xbbb80;
  if ((*(long *)(lVar6 + 0x1bc0) == 0) ||
     ((cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar6), cVar4 == '\0' ||
      (cVar4 = kvgpumgrIsMigTimeslicingModeEnabled(lVar6), cVar4 == '\0')))) {
    lVar10 = lVar2 + 0x5a88 + lVar8;
  }
  else {
    lVar10 = kvgpuMgrGetVgpuPlacementInfo(lVar6,lVar2 + 0x48 + lVar8,param_1[7]);
    if (lVar10 == 0) {
      nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                         "src/kernel/virtualization/kernel_vgpu_mgr.c",0x124c);
      return 0x57;
    }
  }
  iVar5 = kvgpuMgrGetHeterogeneousMode(lVar6,param_1[7],local_39);
  if (iVar5 != 0) {
    nvCheckOkFailedNoLog
              (4,iVar5,
               "kvgpuMgrGetHeterogeneousMode(pGpu, pRequestVgpu->swizzId, &bHeterogeneousModeEnabled)"
               ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1252);
    return iVar5;
  }
  if ((local_39[0] == '\0') &&
     (iVar5 = kvgpumgrCheckHomogeneousPlacementSupported(lVar6), iVar5 != 0)) {
    param_1[8] = 0xffff;
    return 0x56;
  }
  uVar12 = *(uint *)(lVar2 + 0x250 + uVar13 * 0xbbb80);
  if (uVar12 == 0) {
    return 0x40;
  }
  lVar14 = 0;
  lVar8 = lVar8 + lVar2;
  bVar3 = false;
  do {
    piVar7 = *(int **)(lVar8 + 0x280);
    if (piVar7 == (int *)0x0) break;
    if (*piVar7 == *param_1) {
      uVar11 = *(ushort *)((long)piVar7 + 0x30e);
      if (local_39[0] != '\0') {
        uVar11 = *(ushort *)(piVar7 + 0xc3);
      }
      if (uVar11 != 0) {
        puVar9 = (ushort *)(lVar10 + lVar14);
        puVar1 = (ushort *)(lVar10 + 0x18 + lVar14 + (ulong)(uVar11 - 1) * 0x18);
        uVar11 = *puVar9;
        if (param_2 == 0xffff) {
          while (uVar11 == 0xffff) {
            puVar9 = puVar9 + 0xc;
            if (puVar9 == puVar1) goto joined_r0x004e7e89;
            uVar11 = *puVar9;
          }
          bVar3 = true;
          local_5c = (uint)uVar11;
        }
        else {
          while (uVar11 != param_2) {
            puVar9 = puVar9 + 0xc;
            if (puVar1 == puVar9) goto joined_r0x004e7e89;
            uVar11 = *puVar9;
          }
          bVar3 = true;
          local_5c = param_2;
        }
      }
    }
joined_r0x004e7e89:
    lVar8 = lVar8 + 8;
    lVar14 = lVar14 + 0x488;
  } while (lVar14 != (ulong)uVar12 * 0x488);
  if (!bVar3) {
    return 0x40;
  }
  if (local_39[0] == '\0') {
    iVar5 = _kvgpumgrUpdateHomogeneousCreatablePlacementIds
                      (lVar6,(undefined2)local_5c,*param_1,1,param_1[7]);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (param_2 == 0xffff) goto LAB_004e7ed6;
    iVar5 = _kvgpumgrUpdateHomogeneousCreatablePlacementIds
                      (lVar6,(short)param_1[8],*param_1,0,param_1[7]);
  }
  else {
    iVar5 = _kvgpumgrUpdateHeterogeneousCreatablePlacementIds();
    if (iVar5 != 0) {
      return 0x57;
    }
    if (param_2 == 0xffff) goto LAB_004e7ed6;
    iVar5 = _kvgpumgrUpdateHeterogeneousCreatablePlacementIds
                      (lVar6,(short)param_1[8],*param_1,0,param_1[7]);
  }
  if (iVar5 != 0) {
    return iVar5;
  }
LAB_004e7ed6:
  param_1[8] = local_5c;
  return 0;
}


// ===== 004e80c0 kvgpumgrCreateRequestVgpu =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kvgpumgrCreateRequestVgpu
              (int param_1,undefined8 param_2,int param_3,undefined2 *param_4,int *param_5,
              int *param_6,int param_7)

{
  ulong *puVar1;
  undefined2 uVar2;
  long lVar3;
  ulong uVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  ulong uVar13;
  int *piVar14;
  long lVar15;
  undefined8 *puVar16;
  char local_51;
  undefined4 local_50;
  int local_4c;
  undefined8 local_48;
  long local_40 [2];
  
  lVar3 = g_pSys;
  lVar10 = gpumgrGetGpuFromId();
  lVar12 = *(long *)(lVar3 + 0x1f8);
  uVar7 = 0;
  local_50 = 2;
  lVar3 = *(long *)(lVar3 + 0x238);
  local_48 = 1;
  local_4c = -1;
  piVar11 = (int *)(lVar12 + 0x48);
  if (lVar10 == 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xa13,"kvgpumgrCreateRequestVgpu",4,
                 "NVRM: GPU %u is not initialized yet \n",param_7);
    return 0x66;
  }
  while ((param_1 != *piVar11 || ((char)piVar11[0x18e] != '\x01'))) {
    uVar7 = uVar7 + 1;
    piVar11 = piVar11 + 0x2eee0;
    if (uVar7 == 0x20) {
      return 0x57;
    }
  }
  lVar15 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar11 = (int *)listHead_IMPL(lVar15);
  while( true ) {
    if (piVar11 == (int *)0x0) {
      return 0x57;
    }
    if (param_3 == *piVar11) break;
    piVar11 = (int *)listNext_IMPL(lVar15);
  }
  uVar4 = (ulong)uVar7;
  if ((*(char *)(lVar10 + 0x491d) != '\0') && (*(char *)(lVar3 + 0x48) == '\0')) {
    bVar5 = (char)param_7 - *(char *)(lVar10 + 0x3a5c);
    if (0x3f < bVar5) {
      nvAssertFailedNoLog("(fnId < 64)","src/kernel/virtualization/kernel_vgpu_mgr.c",0xa2a);
      return 0x1f;
    }
    if ((*(ulong *)(lVar12 + 0xbbb40 + uVar4 * 0xbbb80) >> ((ulong)bVar5 & 0x3f) & 1) != 0) {
      return 0x38;
    }
  }
  lVar3 = lVar12 + 0x48 + uVar4 * 0xbbb80;
  if ((*(long *)(lVar10 + 0x1bc0) == 0) || (cVar6 = kmigmgrIsMIGEnabled_IMPL(lVar10), cVar6 == '\0')
     ) {
    if (piVar11[0xcc] != 0) {
      return 0x38;
    }
    iVar8 = kvgpumgrCheckVgpuTypeCreatable(lVar10,lVar3,piVar11);
    if (iVar8 != 0) {
      return iVar8;
    }
  }
  else {
    if ((*(long *)(lVar10 + 0x1bc0) == 0) ||
       (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar10), cVar6 == '\0')) {
      nvCheckFailedNoLog(1,"IS_MIG_IN_USE(pGpu)","src/kernel/virtualization/kernel_vgpu_mgr.c",0xa35
                        );
      return 0x38;
    }
    piVar14 = &DAT_00da1848;
    uVar13 = 0;
    while (*piVar11 != *piVar14) {
      uVar7 = (int)uVar13 + 1;
      uVar13 = (ulong)uVar7;
      piVar14 = piVar14 + 3;
      if (uVar7 == 0x129) {
        nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,"kvgpumgrGetPartitionFlag",
                     4,"NVRM: Invalid SMC vGpu TypeId: 0x%x\n");
        nvAssertOkFailedNoLog
                  (0x1f,"kvgpumgrGetPartitionFlag(vgpuTypeInfo->vgpuTypeId, &partitionFlag)",
                   "src/kernel/virtualization/kernel_vgpu_mgr.c",0xa39);
        return 0x1f;
      }
    }
    iVar8 = kvgpumgrGetSwizzId(lVar10,lVar3,(&DAT_00da1844)[uVar13 * 3],piVar11,&local_4c);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,
                 "kvgpumgrGetSwizzId(pGpu, pPhysGpuInfo, partitionFlag, vgpuTypeInfo, &swizzId)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0xa3c);
      return iVar8;
    }
  }
  puVar16 = *(undefined8 **)(lVar12 + 0x17770a8);
  if (puVar16 == (undefined8 *)0x0) {
    lVar15 = portMemAllocNonPaged(0xd8);
    *(long *)(lVar12 + 0x17770a8) = lVar15;
    if (lVar15 == 0) {
      iVar9 = 0x51;
      iVar8 = local_4c;
      goto LAB_004e8504;
    }
    constructObjEHeap(lVar15,1,0x10000,0,0);
    (**(code **)(*(long *)(lVar12 + 0x17770a8) + 0x28))(*(long *)(lVar12 + 0x17770a8),local_40);
    puVar16 = *(undefined8 **)(lVar12 + 0x17770a8);
    if (local_40[0] != 0xffff) {
      iVar9 = 0x1a;
      (*(code *)*puVar16)();
      portMemFree(*(undefined8 *)(lVar12 + 0x17770a8));
      *(undefined8 *)(lVar12 + 0x17770a8) = 0;
      iVar8 = local_4c;
      goto LAB_004e8504;
    }
  }
  iVar9 = (*(code *)puVar16[1])(puVar16,0xdeadbeef,&local_50,local_40,&local_48,1,1,0,0,0);
  if (iVar9 == 0) {
    *param_4 = (undefined2)local_40[0];
    piVar11 = (int *)listPrependNew_IMPL(lVar12 + 0x17770b0);
    if (piVar11 != (int *)0x0) {
      portMemSet(piVar11,0,0x30);
      portMemCopy(piVar11 + 1,0x10,param_2,0x10);
      piVar11[5] = param_1;
      piVar11[6] = param_7;
      uVar2 = *param_4;
      piVar11[8] = 0xffff;
      *(undefined2 *)(piVar11 + 9) = uVar2;
      *piVar11 = param_3;
      if ((*(long *)(lVar10 + 0x1bc0) == 0) ||
         (cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar10), iVar8 = local_4c, cVar6 == '\0')) {
        iVar8 = -1;
      }
      piVar11[7] = iVar8;
      if (((*(long *)(lVar10 + 0x1bc0) == 0) ||
          (cVar6 = kmigmgrIsMIGEnabled_IMPL(lVar10), cVar6 == '\0')) ||
         ((*(long *)(lVar10 + 0x1bc0) != 0 &&
          ((cVar6 = kmigmgrIsMIGEnabled_IMPL(lVar10), cVar6 != '\0' &&
           (cVar6 = kvgpumgrIsMigTimeslicingModeEnabled(lVar10), cVar6 != '\0')))))) {
        iVar8 = local_4c;
        iVar9 = kvgpuMgrGetHeterogeneousMode(lVar10,local_4c,&local_51);
        if (iVar9 != 0) {
          nvCheckOkFailedNoLog
                    (4,iVar9,
                     "kvgpuMgrGetHeterogeneousMode(pGpu, swizzId, &bHeterogeneousModeEnabled)",
                     "src/kernel/virtualization/kernel_vgpu_mgr.c",0xa8b);
          return iVar9;
        }
        if (((local_51 != '\0') ||
            (iVar9 = kvgpumgrCheckHomogeneousPlacementSupported(lVar10,piVar11[7]), iVar9 == 0)) &&
           (iVar9 = kvgpumgrSetPlacementId(piVar11,piVar11[8]), iVar9 != 0)) {
          nvCheckOkFailedNoLog
                    (4,iVar9,"kvgpumgrSetPlacementId(pRequestVgpu, pRequestVgpu->placementId)",
                     "src/kernel/virtualization/kernel_vgpu_mgr.c",0xa91);
          goto LAB_004e8504;
        }
      }
      kvgpumgrSetVgpuType(lVar10,lVar3,param_3,piVar11[7]);
      lVar12 = uVar4 * 0xbbb80 + lVar12;
      piVar14 = (int *)(lVar12 + 0xbb83c);
      *piVar14 = *piVar14 + 1;
      if (*(char *)(lVar10 + 0x878) != (char)param_7) {
        puVar1 = (ulong *)(lVar12 + 0xbbb40);
        *puVar1 = *puVar1 | 1L << ((char)param_7 - *(char *)(lVar10 + 0x3a5c) & 0x3fU);
      }
      *param_6 = piVar11[8];
      *param_5 = piVar11[7];
      return 0;
    }
    iVar9 = 0x51;
    iVar8 = local_4c;
  }
  else {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0xa69,"kvgpumgrCreateRequestVgpu",3,
                 "NVRM: Failed to allocate heap for vGPU ID 0x%x\n",iVar9);
    iVar8 = local_4c;
  }
LAB_004e8504:
  if (iVar8 != -1) {
    _kvgpumgrClearAssignedSwizzIdMask(lVar10,iVar8);
    return iVar9;
  }
  return iVar9;
}


// ===== 004e8720 kvgpumgrSetGpuInstanceId =====

int kvgpumgrSetGpuInstanceId(int *param_1,ulong param_2)

{
  long lVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int *piVar8;
  long lVar9;
  ulong uVar10;
  ushort *puVar11;
  ushort *puVar12;
  undefined8 uVar13;
  int *piVar14;
  long lVar15;
  ushort uVar16;
  char *pcVar17;
  uint uVar18;
  char local_42;
  char local_41;
  long local_40 [2];
  
  if (param_1[7] == (int)param_2) {
    return 0;
  }
  lVar1 = *(long *)(g_pSys + 0x1f8);
  lVar7 = gpumgrGetGpuFromId(param_1[5]);
  if (lVar7 == 0) {
    return 0x56;
  }
  lVar15 = *(long *)(lVar7 + 0x1bc0);
  if ((lVar15 == 0) || (cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar7,lVar15), cVar3 == '\0')) {
    nvCheckFailedNoLog(1,"IS_MIG_ENABLED(pGpu)","src/kernel/virtualization/kernel_vgpu_mgr.c",0x12c9
                      );
    return 0x38;
  }
  if ((*(long *)(lVar7 + 0x1bc0) == 0) ||
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar7), cVar3 == '\0')) {
    nvCheckFailedNoLog(1,"IS_MIG_IN_USE(pGpu)","src/kernel/virtualization/kernel_vgpu_mgr.c",0x12ca)
    ;
    return 0x38;
  }
  uVar18 = 0;
  piVar8 = (int *)(lVar1 + 0x48);
  while ((param_1[5] != *piVar8 || ((char)piVar8[0x18e] != '\x01'))) {
    uVar18 = uVar18 + 1;
    piVar8 = piVar8 + 0x2eee0;
    if (uVar18 == 0x20) {
      return 0x57;
    }
  }
  iVar6 = *param_1;
  lVar9 = *(long *)(g_pSys + 0x1f8) + 0x1777050;
  piVar8 = (int *)listHead_IMPL(lVar9);
  while( true ) {
    if (piVar8 == (int *)0x0) {
      return 0x57;
    }
    if (iVar6 == *piVar8) break;
    piVar8 = (int *)listNext_IMPL(lVar9,piVar8);
  }
  piVar14 = &DAT_00da1848;
  uVar10 = 0;
  while (iVar6 != *piVar14) {
    uVar4 = (int)uVar10 + 1;
    uVar10 = (ulong)uVar4;
    piVar14 = piVar14 + 3;
    if (uVar4 == 0x129) {
      nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x8e8,"kvgpumgrGetPartitionFlag",4,
                   "NVRM: Invalid SMC vGpu TypeId: 0x%x\n",iVar6);
      nvAssertOkFailedNoLog
                (0x1f,"kvgpumgrGetPartitionFlag(vgpuTypeInfo->vgpuTypeId, &partitionFlag)",
                 "src/kernel/virtualization/kernel_vgpu_mgr.c",0x12d4);
      return 0x1f;
    }
  }
  iVar6 = (&DAT_00da1844)[uVar10 * 3];
  uVar4 = param_1[8];
  uVar10 = kmigmgrGetSwizzIdInUseMask_IMPL(lVar7,lVar15);
  if ((uVar10 >> (param_2 & 0x3f) & 1) == 0) goto LAB_004e88a5;
  iVar5 = kmigmgrGetGPUInstanceInfo_IMPL(lVar7,lVar15,param_2 & 0xffffffff,local_40);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x12e4,"kvgpumgrSetGpuInstanceId",4,
                 "NVRM: No valid GPU instance with SwizzId - %d found\n",param_2 & 0xffffffff);
    return iVar5;
  }
  if (*(int *)(local_40[0] + 0x96c) != iVar6) goto LAB_004e88a5;
  local_42 = '\0';
  local_41 = '\0';
  cVar3 = kvgpumgrIsMigTimeslicingModeEnabled(lVar7);
  if (cVar3 != '\0') {
    iVar6 = kvgpuMgrGetHeterogeneousMode(lVar7,param_2 & 0xffffffff,&local_41);
    uVar13 = 0x12fd;
    pcVar17 = "kvgpuMgrGetHeterogeneousMode(pGpu, swizzId, &bHeterogeneousModeEnabledCurrentGI)";
    if (iVar6 != 0) {
LAB_004e8d5f:
      nvCheckOkFailedNoLog(4,iVar6,pcVar17,"src/kernel/virtualization/kernel_vgpu_mgr.c",uVar13);
      return iVar6;
    }
    iVar6 = kvgpuMgrGetHeterogeneousMode
                      (lVar7,param_2 & 0xffffffff,&local_42,
                       "src/kernel/virtualization/kernel_vgpu_mgr.c",0x12fd);
    if (iVar6 != 0) {
      uVar13 = 0x1300;
      pcVar17 = "kvgpuMgrGetHeterogeneousMode(pGpu, swizzId, &bHeterogeneousModeEnabledTargetGI)";
      goto LAB_004e8d5f;
    }
    puVar11 = (ushort *)
              kvgpuMgrGetVgpuPlacementInfo
                        (lVar7,lVar1 + 0x48 + (ulong)uVar18 * 0xbbb80,param_2 & 0xffffffff);
    if (puVar11 == (ushort *)0x0) {
      nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                         "src/kernel/virtualization/kernel_vgpu_mgr.c",0x1304);
      return 0x57;
    }
    lVar1 = lVar1 + (ulong)uVar18 * 0xbbb80;
    puVar12 = puVar11;
    if (*(int *)(lVar1 + 0x250) != 0) {
      lVar9 = 0;
      lVar15 = 0;
      bVar2 = false;
      do {
        puVar12 = *(ushort **)(lVar1 + 0x280 + lVar15 * 8);
        if (puVar12 == (ushort *)0x0) break;
        uVar16 = puVar12[0x187];
        if (local_42 != '\0') {
          uVar16 = puVar12[0x186];
        }
        if ((*(int *)puVar12 == *param_1) && (uVar16 != 0)) {
          puVar12 = (ushort *)((long)puVar11 + lVar9);
          do {
            if (*puVar12 != 0xffff) {
              param_1[8] = (uint)*puVar12;
              bVar2 = true;
              break;
            }
            puVar12 = puVar12 + 0xc;
          } while (puVar12 != (ushort *)((long)puVar11 + (ulong)(uVar16 - 1) * 0x18 + lVar9 + 0x18))
          ;
        }
        lVar15 = lVar15 + 1;
        lVar9 = lVar9 + 0x488;
      } while ((uint)lVar15 < *(uint *)(lVar1 + 0x250));
      if (bVar2) goto LAB_004e8a06;
    }
    nvDbg_Printf("src/kernel/virtualization/kernel_vgpu_mgr.c",0x1324,"kvgpumgrSetGpuInstanceId",4,
                 "NVRM: Cannot find vGPU type %d placement id in GPU instance %d",*param_1,
                 param_2 & 0xffffffff,puVar12);
    goto LAB_004e88a5;
  }
  if ((uint)piVar8[0xe3] <=
      *(uint *)(lVar1 + 8 + ((param_2 & 0xffffffff) + 0x2eed4 + (ulong)uVar18 * 0x2eee0) * 4))
  goto LAB_004e88a5;
LAB_004e8a06:
  iVar6 = _kvgpumgrClearAssignedSwizzIdMask(lVar7,param_1[7]);
  uVar13 = 0x1333;
  pcVar17 = "_kvgpumgrClearAssignedSwizzIdMask(pGpu, pRequestVgpu->swizzId)";
  if (iVar6 != 0) {
LAB_004e8d2e:
    nvAssertOkFailedNoLog(iVar6,pcVar17,"src/kernel/virtualization/kernel_vgpu_mgr.c",uVar13);
    return iVar6;
  }
  iVar6 = _kvgpumgrSetAssignedSwizzIdMask(lVar7,piVar8,*(undefined4 *)(local_40[0] + 0x968),0x1333);
  if (iVar6 != 0) {
    uVar13 = 0x1335;
    pcVar17 = "_kvgpumgrSetAssignedSwizzIdMask(pGpu, vgpuTypeInfo, pKernelMIGGpuInstance->swizzId)";
    goto LAB_004e8d2e;
  }
  cVar3 = kvgpumgrIsMigTimeslicingModeEnabled(lVar7);
  if (cVar3 != '\0') {
    if (local_42 == '\0') {
      iVar6 = _kvgpumgrUpdateHomogeneousCreatablePlacementIds
                        (lVar7,param_1[8] & 0xffff,*param_1,1,param_2 & 0xffffffff);
      if (iVar6 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar6,
                   "_kvgpumgrUpdateHomogeneousCreatablePlacementIds(pGpu, pRequestVgpu->placementId, pRequestVgpu->vgpuTypeId, NV_TRUE, swizzId)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x134b);
        goto LAB_004e88a5;
      }
    }
    else {
      iVar6 = _kvgpumgrUpdateHeterogeneousCreatablePlacementIds();
      if (iVar6 != 0) {
        nvCheckOkFailedNoLog
                  (4,0x57,
                   "_kvgpumgrUpdateHeterogeneousCreatablePlacementIds(pGpu, pRequestVgpu->placementId, pRequestVgpu->vgpuTypeId, NV_TRUE, swizzId)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1342);
        goto LAB_004e88a5;
      }
    }
    if (local_41 == '\0') {
      iVar6 = _kvgpumgrUpdateHomogeneousCreatablePlacementIds
                        (lVar7,uVar4 & 0xffff,*param_1,0,param_1[7]);
      if (iVar6 != 0) {
        nvCheckOkFailedNoLog
                  (4,iVar6,
                   "_kvgpumgrUpdateHomogeneousCreatablePlacementIds(pGpu, currPlacementId, pRequestVgpu->vgpuTypeId, NV_FALSE, pRequestVgpu->swizzId)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x135e);
        goto LAB_004e88a5;
      }
    }
    else {
      iVar6 = _kvgpumgrUpdateHeterogeneousCreatablePlacementIds();
      if (iVar6 != 0) {
        nvCheckOkFailedNoLog
                  (4,0x57,
                   "_kvgpumgrUpdateHeterogeneousCreatablePlacementIds(pGpu, currPlacementId, pRequestVgpu->vgpuTypeId, NV_FALSE, pRequestVgpu->swizzId)"
                   ,"src/kernel/virtualization/kernel_vgpu_mgr.c",0x1355);
LAB_004e88a5:
        param_1[8] = uVar4;
        return 0x40;
      }
    }
  }
  param_1[7] = *(int *)(local_40[0] + 0x968);
  return 0;
}


// ===== 004e8de0 vgpuconfigapiConstruct_IMPL =====

undefined4 vgpuconfigapiConstruct_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  uint local_3c [3];
  
  uVar6 = 0x56;
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar2 + 0x908) == '\0') {
    lVar3 = *(long *)(g_pSys + 0x1f8);
    uVar6 = *param_3;
    uVar1 = param_3[2];
    *(undefined8 *)(param_1 + 0x178) = 0;
    *(undefined8 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    iVar4 = kvgpumgrGetPgpuIndex(lVar3,*(undefined4 *)(lVar2 + 0x7ac),local_3c);
    if (iVar4 != 0) {
      return 0x57;
    }
    puVar5 = (undefined8 *)listAppendNew_IMPL(lVar3 + 0xbb810 + (ulong)local_3c[0] * 0xbbb80);
    if (puVar5 == (undefined8 *)0x0) {
      return 0;
    }
    portMemSet(puVar5,0,0x10);
    *puVar5 = CONCAT44(uVar1,uVar6);
    puVar5[1] = param_1;
    uVar6 = 0;
  }
  return uVar6;
}


// ===== 004e8f20 vgpuconfigapiDestruct_IMPL =====

void vgpuconfigapiDestruct_IMPL(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint local_44;
  undefined8 local_40;
  undefined1 local_38 [8];
  undefined4 *local_30;
  
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar4 = *(long *)(g_pSys + 0x1f8);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x140),local_38,&local_30);
  uVar1 = *local_30;
  uVar2 = local_30[1];
  iVar5 = kvgpumgrGetPgpuIndex(lVar4,*(undefined4 *)(lVar3 + 0x7ac),&local_44);
  if (iVar5 != 0) {
    local_30[0xc] = 0x57;
    return;
  }
  iVar5 = kvgpumgrGetConfigEventInfoFromDb(uVar1,uVar2,&local_40,local_44);
  if (iVar5 == 0) {
    listRemove_IMPL(lVar4 + 0xbb810 + (ulong)local_44 * 0xbbb80,local_40);
    local_30[0xc] = 0;
    return;
  }
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x78,"vgpuconfigapiDestruct_IMPL",4,
               "NVRM: Failed to remove config event info from DB\n");
  nvAssertFailedNoLog(&DAT_00da2692,"src/kernel/virtualization/vgpuconfigapi.c",0x79);
  local_30[0xc] = iVar5;
  return;
}


// ===== 004e9050 CliNotifyVgpuConfigEvent =====

void CliNotifyVgpuConfigEvent(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  uint local_3c [3];
  
  lVar2 = *(long *)(g_pSys + 0x1f8);
  iVar3 = kvgpumgrGetPgpuIndex(lVar2,*(undefined4 *)(param_1 + 0x7ac),local_3c);
  if ((iVar3 != 0) ||
     (lVar4 = listHead_IMPL(lVar2 + 0xbb810 + (ulong)local_3c[0] * 0xbbb80), lVar4 == 0)) {
    return;
  }
  do {
    lVar1 = *(long *)(lVar4 + 8) + (ulong)param_2 * 4;
    if (*(int *)(lVar1 + 0x178) != 0) {
      for (lVar5 = inotifyGetNotificationList_IMPL(*(undefined8 *)(*(long *)(lVar4 + 8) + 0x160));
          lVar5 != 0; lVar5 = *(long *)(lVar5 + 0x40)) {
        while ((*(uint *)(lVar5 + 0xc) != param_2 ||
               (iVar3 = osNotifyEvent(param_1,lVar5,0,0,0), iVar3 == 0))) {
          lVar5 = *(long *)(lVar5 + 0x40);
          if (lVar5 == 0) goto LAB_004e91a0;
        }
        nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0xaa,"CliNotifyVgpuConfigEvent",4,
                     "NVRM: CliNotifyVgpuEvent: failed to deliver event 0x%x\n",param_2);
      }
LAB_004e91a0:
      if (*(int *)(lVar1 + 0x178) == 1) {
        *(undefined4 *)(lVar1 + 0x178) = 0;
      }
    }
    lVar4 = listNext_IMPL(lVar2 + 0xbb810 + (ulong)local_3c[0] * 0xbbb80,lVar4);
    if (lVar4 == 0) {
      return;
    }
  } while( true );
}


// ===== 004e91e0 vgpuconfigapiCtrlCmdVgpuConfigSetInfo_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigSetInfo_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  uint local_2c [3];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",200,
               "vgpuconfigapiCtrlCmdVgpuConfigSetInfo_IMPL",1,"NVRM: %s\n");
  iVar2 = kvgpumgrGetPgpuIndex(lVar3,*(undefined4 *)(lVar1 + 0x7ac),local_2c);
  if (iVar2 != 0) {
    nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0xcb,
                 "vgpuconfigapiCtrlCmdVgpuConfigSetInfo_IMPL",4,
                 "NVRM: Failed to find pGpu info entry.\n");
    return iVar2;
  }
  lVar3 = lVar3 + (ulong)local_2c[0] * 0xbbb80;
  *(undefined4 *)(lVar3 + 0x254) = *(undefined4 *)(param_2 + 0x1538);
  iVar2 = kvgpumgrPgpuAddVgpuType(lVar1,*param_2,param_2 + 8);
  if (iVar2 == 0) {
    return 0;
  }
  *(undefined4 *)(lVar3 + 0x254) = 0;
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0xdb,
               "vgpuconfigapiCtrlCmdVgpuConfigSetInfo_IMPL",4,
               "NVRM: Failed to add vGPU type to pGPU info.\n");
  return iVar2;
}


// ===== 004e9320 vgpuconfigapiCtrlCmdVgpuConfigGetVgpuFbUsage_IMPL =====

void vgpuconfigapiCtrlCmdVgpuConfigGetVgpuFbUsage_IMPL(long param_1)

{
  kvgpumgrGetVgpuFbUsage(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return;
}


// ===== 004e9340 vgpuconfigapiCtrlCmdVgpuConfigEnumerateVgpuPerPgpu_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigEnumerateVgpuPerPgpu_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  long lVar9;
  undefined4 *puVar10;
  ulong uVar11;
  long lVar12;
  uint *puVar13;
  ulong uVar14;
  ulong uVar15;
  uint local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_70 = 1;
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(g_pSys + 0x1f8);
  local_78 = 0x200000003;
  local_68 = 0x400000005;
  local_60 = 0x600000007;
  local_58 = 0x900000008;
  local_50 = 0xb0000000a;
  local_48 = 0xd0000000c;
  local_40 = 0xf0000000e;
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x102,
               "vgpuconfigapiCtrlCmdVgpuConfigEnumerateVgpuPerPgpu_IMPL",1,"NVRM: %s\n");
  puVar8 = (uint *)portMemAllocNonPaged(0x2888);
  if (puVar8 == (uint *)0x0) {
    iVar5 = 0x51;
  }
  else {
    portMemSet(puVar8,0,0x2888);
    iVar5 = kvgpumgrGetPgpuIndex(lVar3,*(undefined4 *)(lVar2 + 0x7ac),&local_7c);
    if (iVar5 == 0) {
      iVar5 = kvgpumgrEnumerateVgpuPerPgpu(lVar2,puVar8);
      if (iVar5 == 0) {
        uVar15 = (ulong)local_7c;
        lVar9 = uVar15 * 0xbbb80;
        if (*puVar8 == *(uint *)(lVar3 + 0x24c + lVar9)) {
          lVar9 = lVar3 + 600 + lVar9;
          local_7c = 0;
          puVar10 = (undefined4 *)listHead_IMPL(lVar9);
          while (puVar10 != (undefined4 *)0x0) {
            piVar4 = *(int **)(puVar10 + 4);
            if (piVar4 == (int *)0x0) goto LAB_004e949a;
            uVar14 = (ulong)local_7c;
            if (0x2f < local_7c) {
              iVar5 = 0x1a;
              goto LAB_004e94a4;
            }
            portMemSet(param_2 + uVar14 * 0x66 + 0x30,0,0x80);
            portMemSet(param_2 + uVar14 * 0x66 + 0x5a,0,0x10);
            iVar6 = osIsVgpuVfioPresent();
            if ((iVar6 == 0) || (iVar6 = osIsVgpuDeviceVmPresent(), iVar6 == 0)) {
              portMemCopy(param_2 + uVar14 * 0x66 + 0x30,0x80,piVar4 + 6,0x80);
            }
            iVar6 = osIsVgpuVfioPresent();
            if (iVar6 == 0) {
              if (*(long *)(puVar10 + 0xb8) == 0) {
                iVar5 = 0x3d;
                goto LAB_004e94a4;
              }
              iVar6 = osIsVfioPciCorePresent();
              if ((iVar6 == 0) || (*(char *)(lVar2 + 0x491d) == '\0')) {
                lVar12 = 0;
                do {
                  *(undefined1 *)((long)param_2 + lVar12 + uVar14 * 0x198 + 0x168) =
                       *(undefined1 *)
                        (*(long *)(puVar10 + 0xb8) + 4 +
                        (ulong)*(uint *)((long)&local_78 + lVar12 * 4));
                  lVar12 = lVar12 + 1;
                } while (lVar12 != 0x10);
              }
            }
            if (*(char *)(lVar2 + 0x909) == '\0') {
              uVar11 = (ulong)local_7c;
            }
            else {
              if (*puVar8 == 0) {
LAB_004e9870:
                iVar5 = 0x57;
                goto LAB_004e94a4;
              }
              puVar13 = puVar8 + 0x2c;
              uVar11 = 0;
              while (*puVar13 != puVar10[6]) {
                uVar7 = (int)uVar11 + 1;
                uVar11 = (ulong)uVar7;
                puVar13 = puVar13 + 0x36;
                if (*puVar8 == uVar7) goto LAB_004e9870;
              }
            }
            puVar13 = puVar8 + uVar11 * 0x36 + 2;
            param_2[uVar14 * 0x66 + 2] = *puVar13;
            param_2[uVar14 * 0x66 + 4] = puVar13[1];
            param_2[uVar14 * 0x66 + 5] = puVar13[2];
            param_2[uVar14 * 0x66 + 6] = puVar13[3];
            *(char *)(param_2 + uVar14 * 0x66 + 8) = (char)puVar13[5];
            param_2[uVar14 * 0x66 + 9] = puVar13[6];
            param_2[uVar14 * 0x66 + 0x50] = puVar13[0x29];
            param_2[uVar14 * 0x66 + 10] = puVar13[7];
            *(char *)(param_2 + uVar14 * 0x66 + 0xb) = (char)puVar13[8];
            param_2[uVar14 * 0x66 + 7] = puVar13[4];
            portStringCopy(param_2 + uVar14 * 0x66 + 0x10,0x40,(long)puVar13 + 0x21,0x40);
            portStringCopy(param_2 + uVar14 * 0x66 + 0x20,0x40,(long)puVar13 + 0x61,0x40);
            iVar6 = *piVar4;
            param_2[uVar14 * 0x66 + 3] = iVar6;
            if (iVar6 == 0) {
              *(undefined8 *)(param_2 + uVar14 * 0x66 + 0xc) = *(undefined8 *)(piVar4 + 2);
            }
            else {
              if (iVar6 != 1) goto LAB_004e949a;
              portMemCopy(param_2 + uVar14 * 0x66 + 0xc,0x10,piVar4 + 2,0x10);
            }
            param_2[uVar14 * 0x66 + 0x52] = *puVar10;
            param_2[uVar14 * 0x66 + 0x53] = puVar13[0x2e];
            param_2[uVar14 * 0x66 + 0x5e] = puVar13[0x32];
            *(undefined8 *)(param_2 + uVar14 * 0x66 + 0x60) = *(undefined8 *)(puVar13 + 0x30);
            param_2[uVar14 * 0x66 + 100] = puVar10[7];
            param_2[uVar14 * 0x66 + 0x62] = puVar13[0x33];
            *(char *)(param_2 + uVar14 * 0x66 + 99) = (char)puVar13[0x34];
            param_2[uVar14 * 0x66 + 0x65] = (uint)*(ushort *)(puVar10 + 9);
            portMemCopy(param_2 + uVar14 * 0x66 + 0x56,0x10,puVar10 + 0xb3,0x10);
            *(undefined8 *)(param_2 + uVar14 * 0x66 + 0x54) = *(undefined8 *)(puVar13 + 0x2c);
            param_2[uVar14 * 0x66 + 0x66] = puVar13[0x2f];
            puVar10 = (undefined4 *)listNext_IMPL(lVar9);
            local_7c = local_7c + 1;
          }
          uVar1 = *(undefined4 *)(lVar3 + 0x24c + uVar15 * 0xbbb80);
          *param_2 = 0;
          param_2[1] = uVar1;
        }
        else {
LAB_004e949a:
          iVar5 = 0x40;
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,"kvgpumgrEnumerateVgpuPerPgpu(pGpu, pVgpuPerPgpuParams)",
                   "src/kernel/virtualization/vgpuconfigapi.c",0x10c);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar5,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &i)",
                 "src/kernel/virtualization/vgpuconfigapi.c",0x10a);
    }
LAB_004e94a4:
    portMemFree(puVar8);
  }
  return iVar5;
}


// ===== 004e9940 vgpuconfigapiCtrlCmdVgpuConfigEnumerateVgpuPerGpuInstance_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigEnumerateVgpuPerGpuInstance_IMPL(long param_1,int *param_2)

{
  long lVar1;
  ulong uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  uint local_3c [3];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x1b1,
               "vgpuconfigapiCtrlCmdVgpuConfigEnumerateVgpuPerGpuInstance_IMPL",1,"NVRM: %s\n");
  if (lVar1 == 0) {
    nvAssertFailedNoLog("(pGpu != NULL)","src/kernel/virtualization/vgpuconfigapi.c",0x1b3);
  }
  else {
    iVar4 = kvgpumgrGetPgpuIndex(lVar5,*(undefined4 *)(lVar1 + 0x7ac),local_3c);
    if (iVar4 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar4,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &pgpuIndex)",
                 "src/kernel/virtualization/vgpuconfigapi.c",0x1b5);
      return iVar4;
    }
    if (*param_2 != -1) {
      if ((*(long *)(lVar1 + 0x1bc0) != 0) &&
         (cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar1), cVar3 != '\0')) {
        iVar4 = 0;
        lVar1 = lVar5 + 600 + (ulong)local_3c[0] * 0xbbb80;
        lVar5 = listHead_IMPL(lVar1);
        uVar2 = 0;
        while (lVar5 != 0) {
          uVar6 = uVar2;
          if (*(int *)(lVar5 + 0x1c) == *param_2) {
            uVar6 = (ulong)((int)uVar2 + 1);
            param_2[uVar2 + 2] = *(int *)(lVar5 + 0x88c);
          }
          iVar4 = (int)uVar6;
          lVar5 = listNext_IMPL(lVar1);
          uVar2 = uVar6;
        }
        param_2[1] = iVar4;
        return 0;
      }
      return 0x56;
    }
    nvAssertFailedNoLog("(pParams->gpuInstanceId != KMIGMGR_SWIZZID_INVALID || pParams->gpuInstanceId < KMIGMGR_MAX_GPU_SWIZZID)"
                        ,"src/kernel/virtualization/vgpuconfigapi.c",0x1ba);
  }
  return 0x1f;
}


// ===== 004e9aea vgpuconfigapiCtrlCmdVgpuConfigGetVgpuTypeInfo_IMPL.cold =====

void vgpuconfigapiCtrlCmdVgpuConfigGetVgpuTypeInfo_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004e9b00 vgpuconfigapiCtrlCmdVgpuConfigGetVgpuTypeInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int vgpuconfigapiCtrlCmdVgpuConfigGetVgpuTypeInfo_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  char cVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  char local_89;
  int local_88;
  uint local_84;
  undefined4 *local_80;
  undefined1 local_78 [72];
  
  local_88 = 0;
  lVar10 = *(long *)(g_pSys + 0x1f8);
  lVar11 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xf0);
  uVar8 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  uVar1 = *(undefined4 *)(*(long *)(*(long *)(lVar2 + 0x140) + 0x48) + 0x10);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x1ec,
               "vgpuconfigapiCtrlCmdVgpuConfigGetVgpuTypeInfo_IMPL",1,"NVRM: %s\n");
  iVar7 = kvgpumgrGetVgpuTypeInfo(*param_2,&local_80);
  if ((iVar7 == 0) &&
     (iVar7 = kvgpumgrGetPgpuIndex(lVar10,*(undefined4 *)(lVar11 + 0x7ac),&local_84), iVar7 == 0)) {
    param_2[2] = *local_80;
    param_2[99] = local_80[0xc4];
    param_2[100] = local_80[0xc5];
    param_2[0x65] = local_80[0xc6];
    param_2[0x66] = local_80[199];
    param_2[0x67] = local_80[200];
    param_2[0x68] = local_80[0xc9];
    param_2[0x69] = local_80[0xca];
    param_2[0x6a] = local_80[0xcb];
    param_2[0x6b] = local_80[0xcc];
    *(undefined8 *)(param_2 + 0x6e) = *(undefined8 *)(local_80 + 0xce);
    *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(local_80 + 0xd0);
    *(undefined8 *)(param_2 + 0x72) = *(undefined8 *)(local_80 + 0xd2);
    *(undefined8 *)(param_2 + 0x74) = *(undefined8 *)(local_80 + 0xd4);
    *(undefined8 *)(param_2 + 0x76) = *(undefined8 *)(local_80 + 0xd6);
    *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(local_80 + 0xd8);
    *(undefined8 *)(param_2 + 0x7a) = *(undefined8 *)(local_80 + 0xda);
    param_2[0x7c] = local_80[0xdc];
    *(undefined8 *)(param_2 + 0x7e) = *(undefined8 *)(local_80 + 0xde);
    param_2[0x4e3] = local_80[0xe1];
    param_2[0x4e4] = local_80[0xe2];
    param_2[0x4e5] = local_80[0xe3];
    param_2[0x4e6] = local_80[0xe4];
    param_2[0x80] = local_80[0xe0];
    param_2[0x6d] = local_80[0xcd];
    uVar6 = vgpuMgrGetVgpuSsvid(lVar11);
    *(undefined2 *)(param_2 + 0x81) = uVar6;
    cVar5 = kvgpumgrIsHeterogeneousVgpuTypeSupported();
    param_2[0x4e7] = (uint)(cVar5 == '\0');
    uVar4 = (ulong)local_84;
    param_2[0x4e8] = (uint)(*(char *)(lVar10 + 0xbb839 + uVar4 * 0xbbb80) == '\0');
    iVar7 = (**(code **)(lVar11 + 0x3b90))(lVar11 + 0x3b58,uVar8,uVar1,0x2080400d,&local_89,1);
    if (iVar7 == 0) {
      if (local_89 != '\0') {
        param_2[0x80] = 0;
      }
      portStringCopy(param_2 + 3,0x40,local_80 + 1,0x40);
      portStringCopy(param_2 + 0x13,0x40,local_80 + 0x11,0x40);
      portStringCopy(param_2 + 0x43,0x80,local_80 + 0x21,0x80);
      portStringCopy(param_2 + 0xe2,0x1000,local_80 + 0xe5,0x1000);
      portStringCopy((long)param_2 + 0x306,0x80,local_80 + 0x41,0x80);
      iVar7 = osReadRegistryDword(lVar11,"RmEnablePluginFtrace",&local_88);
      if ((iVar7 == 0) && (local_88 == 1)) {
        param_2[0x4e2] = 1;
      }
      iVar7 = (**(code **)(lVar11 + 0xb0))(lVar11,local_78);
      if (iVar7 == 0) {
        portMemCopy((long)param_2 + 0x2c6,0x40,local_78,0x40);
        portStringCopy((long)param_2 + 0x206,0x40,local_80 + 1,0x40);
        lVar2 = (long)param_2 + 0x246;
        portStringCopy(lVar2,0x80,local_80 + 1,0x40);
        portStringConvertAsciiToUtf16(lVar2,0x40,lVar2,0x40);
        if (local_80[0xcc] == 0) {
          param_2[0x4e9] = 0xffffffff;
        }
        else {
          iVar9 = kvgpumgrGetPartitionFlag(*local_80,param_2 + 0x4e9);
          if (iVar9 != 0) {
            nvAssertOkFailedNoLog
                      (iVar9,
                       "kvgpumgrGetPartitionFlag(vgpuTypeInfo->vgpuTypeId, &pParams->vgpuTypeInfo.gpuInstanceProfileId)"
                       ,"src/kernel/virtualization/vgpuconfigapi.c",0x246);
            return iVar9;
          }
        }
        uVar8 = vgpuMgrGetPlacementRegionSize(lVar11,lVar10 + 0xbbba0 + uVar4 * 0xbbb80,local_80);
        param_2[0x6c] = uVar8;
        lVar11 = uVar4 * 0xbbb80 + lVar10;
        if ((*(char *)(lVar11 + 0xbb839) == '\x01') ||
           (uVar8 = 0, *(char *)(lVar11 + 0xbb83a) == '\x01')) {
          uVar8 = local_80[0x61];
        }
        param_2[0x4ea] = uVar8;
        if (*(char *)(lVar10 + 0xbb839 + uVar4 * 0xbbb80) == '\x01') {
          param_2[0x51c] = (uint)*(ushort *)(local_80 + 0xc3);
          if (*(short *)(local_80 + 0xc3) != 0) {
            lVar11 = 0;
            do {
              param_2[lVar11 + 0x51d] = (uint)*(ushort *)(local_80 + lVar11 * 2 + 99);
              lVar11 = lVar11 + 1;
            } while ((uint)lVar11 < (uint)*(ushort *)(local_80 + 0xc3));
          }
        }
        else {
          param_2[0x51c] = 0;
        }
        if (*(char *)(lVar10 + 0xbb83a + uVar4 * 0xbbb80) == '\x01') {
          param_2[0x4eb] = (uint)*(ushort *)((long)local_80 + 0x30e);
          if (*(short *)((long)local_80 + 0x30e) != 0) {
            lVar10 = 0;
            do {
              param_2[lVar10 + 0x4ec] = (uint)*(ushort *)(local_80 + lVar10 * 2 + 100);
              lVar10 = lVar10 + 1;
            } while ((uint)lVar10 < (uint)*(ushort *)((long)local_80 + 0x30e));
          }
        }
        else {
          param_2[0x4eb] = 0;
        }
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar7,
                 "pRmApi->Control(pRmApi, hClient, hSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_GET_FRAME_RATE_LIMITER_STATUS, &frlStatus, sizeof(frlStatus))"
                 ,"src/kernel/virtualization/vgpuconfigapi.c",0x21d);
    }
  }
  return iVar7;
}


// ===== 004ea140 vgpuconfigapiCtrlCmdVgpuConfigGetSupportedVgpuTypes_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigGetSupportedVgpuTypes_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined4 *puVar2;
  char cVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  int local_54;
  uint local_3c [3];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar6 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x290,
               "vgpuconfigapiCtrlCmdVgpuConfigGetSupportedVgpuTypes_IMPL",1,"NVRM: %s\n");
  if ((lVar1 == 0) || (*(char *)(lVar1 + 0x4a3) == '\0')) {
    local_54 = 0x56;
  }
  else {
    local_54 = kvgpumgrGetPgpuIndex(lVar6,*(undefined4 *)(lVar1 + 0x7ac),local_3c);
    if (local_54 == 0) {
      lVar6 = lVar6 + (ulong)local_3c[0] * 0xbbb80;
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(lVar6 + 0x254);
      uVar7 = 0;
      if (*(int *)(lVar6 + 0x250) != 0) {
        uVar7 = 0;
        lVar5 = 0;
        do {
          puVar2 = *(undefined4 **)(lVar6 + 0x280 + lVar5 * 8);
          if ((puVar2 != (undefined4 *)0x0) &&
             ((cVar3 = kvgpumgrIsMigTimeslicingModeEnabled(lVar1), cVar3 != '\0' ||
              ((uint)puVar2[0xe3] < 2)))) {
            uVar4 = (ulong)uVar7;
            uVar7 = uVar7 + 1;
            *(undefined4 *)(param_2 + 0xc + uVar4 * 4) = *puVar2;
          }
          lVar5 = lVar5 + 1;
        } while ((uint)lVar5 < *(uint *)(lVar6 + 0x250));
      }
      *(uint *)(param_2 + 8) = uVar7;
    }
  }
  return local_54;
}


// ===== 004ea290 vgpuconfigapiCtrlCmdVgpuConfigGetCreatableVgpuTypes_IMPL =====

undefined8
vgpuconfigapiCtrlCmdVgpuConfigGetCreatableVgpuTypes_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 local_2c [3];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = *(undefined8 *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x2c1,
               "vgpuconfigapiCtrlCmdVgpuConfigGetCreatableVgpuTypes_IMPL",1,"NVRM: %s\n");
  if ((lVar1 != 0) && (*(char *)(lVar1 + 0x4a3) != '\0')) {
    uVar2 = kvgpumgrGetPgpuIndex(uVar3,*(undefined4 *)(lVar1 + 0x7ac),local_2c);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    uVar3 = kvgpumgrGetCreatableVgpuTypes(lVar1,uVar3,local_2c[0],*param_2,param_2 + 2,param_2 + 3);
    return uVar3;
  }
  return 0x56;
}


// ===== 004ea360 vgpuconfigapiCtrlCmdVgpuConfigEventSetNotification_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigEventSetNotification_IMPL(long param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined4 local_44;
  long local_40 [2];
  
  uVar7 = *(undefined8 *)(g_pSys + 0x1f8);
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  plVar4 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
  lVar6 = plVar4[2];
  local_40[0] = 0;
  uVar1 = *(undefined4 *)(*plVar4 + 0x48);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x2e4,
               "vgpuconfigapiCtrlCmdVgpuConfigEventSetNotification_IMPL",1,"NVRM: %s\n");
  if (*param_2 < 5) {
    iVar5 = kvgpumgrGetPgpuIndex(uVar7,*(undefined4 *)(lVar3 + 0x7ac),&local_44);
    if (iVar5 != 0) {
      return iVar5;
    }
    iVar5 = kvgpumgrGetConfigEventInfoFromDb(uVar1,(int)lVar6,local_40,local_44);
    if ((iVar5 != 0) || (local_40[0] == 0)) {
      nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x2f5,
                   "vgpuconfigapiCtrlCmdVgpuConfigEventSetNotification_IMPL",4,
                   "NVRM: Failed to find config event info for %x from DB\n",uVar1);
      return iVar5;
    }
    lVar3 = *(long *)(local_40[0] + 8);
    uVar7 = 0;
    if (lVar3 != 0) {
      uVar7 = *(undefined8 *)(lVar3 + 0x160);
    }
    lVar6 = inotifyGetNotificationList_IMPL(uVar7);
    if (lVar6 == 0) {
      nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x2fe,
                   "vgpuconfigapiCtrlCmdVgpuConfigEventSetNotification_IMPL",1,
                   "NVRM: Cmd 0x%x: no event list\n",0xa0810106);
    }
    else {
      uVar2 = param_2[1];
      if (uVar2 == 0) {
        *(undefined4 *)(lVar3 + 0x178 + (ulong)*param_2 * 4) = 0;
        return 0;
      }
      if (1 < uVar2 - 1) goto LAB_004ea4c6;
      if (*(int *)(lVar3 + 0x178 + (ulong)*param_2 * 4) == 0) {
        *(uint *)(lVar3 + 8 + ((ulong)*param_2 + 0x5c) * 4) = uVar2;
        return 0;
      }
    }
    iVar5 = 0x40;
  }
  else {
    nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x2e8,
                 "vgpuconfigapiCtrlCmdVgpuConfigEventSetNotification_IMPL",1,
                 "NVRM: Bad event 0x%x\n");
LAB_004ea4c6:
    iVar5 = 0x1f;
  }
  return iVar5;
}


// ===== 004ea560 vgpuconfigapiCtrlCmdVgpuConfigGetCreatablePlacements_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigGetCreatablePlacements_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ushort *puVar6;
  ushort uVar7;
  uint uVar8;
  ulong uVar9;
  char local_3d;
  uint local_3c [3];
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar1 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x336,
               "vgpuconfigapiCtrlCmdVgpuConfigGetCreatablePlacements_IMPL",1,"NVRM: %s\n");
  if (lVar4 == 0) {
    nvCheckFailedNoLog(4,"pGpu != NULL","src/kernel/virtualization/vgpuconfigapi.c",0x338);
    iVar3 = 0x56;
  }
  else {
    iVar3 = kvgpuMgrGetHeterogeneousMode(lVar4,*param_2,&local_3d);
    if (iVar3 == 0) {
      if ((local_3d == '\0') &&
         (iVar3 = kvgpumgrCheckHomogeneousPlacementSupported(lVar4,*param_2), iVar3 != 0)) {
        iVar3 = 0x56;
      }
      else {
        iVar3 = kvgpumgrGetPgpuIndex(lVar1,*(undefined4 *)(lVar4 + 0x7ac),local_3c);
        if (iVar3 == 0) {
          lVar4 = kvgpuMgrGetVgpuPlacementInfo
                            (lVar4,lVar1 + 0x48 + (ulong)local_3c[0] * 0xbbb80,*param_2);
          if (lVar4 == 0) {
            nvCheckFailedNoLog(4,"pKernelVgpuTypePlacementInfo != NULL",
                               "src/kernel/virtualization/vgpuconfigapi.c",0x349);
            iVar3 = 0x57;
          }
          else {
            lVar1 = lVar1 + (ulong)local_3c[0] * 0xbbb80;
            uVar8 = *(uint *)(lVar1 + 0x250);
            if (uVar8 != 0) {
              uVar5 = 0;
              do {
                piVar2 = *(int **)(lVar1 + 0x280 + uVar5 * 8);
                if (param_2[1] == *piVar2) {
                  uVar7 = *(ushort *)((long)piVar2 + 0x30e);
                  if (local_3d != '\0') {
                    uVar7 = *(ushort *)(piVar2 + 0xc3);
                  }
                  uVar8 = (uint)uVar7;
                  if (uVar7 != 0) {
                    puVar6 = (ushort *)(lVar4 + uVar5 * 0x488);
                    uVar8 = 0;
                    do {
                      if (*puVar6 != 0xffff) {
                        uVar9 = (ulong)uVar8;
                        uVar8 = uVar8 + 1;
                        param_2[uVar9 + 4] = (uint)*puVar6;
                      }
                      puVar6 = puVar6 + 0xc;
                    } while (puVar6 != (ushort *)
                                       (lVar4 + 0x18 + uVar5 * 0x488 + (ulong)(uVar7 - 1) * 0x18));
                  }
                  iVar3 = piVar2[0x61];
                  param_2[3] = uVar8;
                  param_2[2] = iVar3;
                  return 0;
                }
                uVar5 = uVar5 + 1;
              } while (uVar5 != uVar8);
            }
          }
        }
        else {
          nvCheckOkFailedNoLog
                    (4,iVar3,"kvgpumgrGetPgpuIndex(pKernelVgpuMgr, pGpu->gpuId, &pgpuIndex)",
                     "src/kernel/virtualization/vgpuconfigapi.c",0x344);
        }
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar3,
                 "kvgpuMgrGetHeterogeneousMode(pGpu, pParams->gpuInstanceId, &bHeterogeneousModeEnabled)"
                 ,"src/kernel/virtualization/vgpuconfigapi.c",0x33a);
    }
  }
  return iVar3;
}


// ===== 004ea7e0 vgpuconfigapiCtrlCmdVgpuConfigSetCapability_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong vgpuconfigapiCtrlCmdVgpuConfigSetCapability_IMPL(long param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  undefined1 local_2d;
  uint local_2c [3];
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x37d,
               "vgpuconfigapiCtrlCmdVgpuConfigSetCapability_IMPL",1,"NVRM: %s\n");
  uVar4 = kvgpumgrGetPgpuIndex(lVar3,*(undefined4 *)(lVar2 + 0x7ac),local_2c);
  if ((int)uVar4 == 0) {
    iVar1 = *param_2;
    if (iVar1 == 1) {
      *(char *)(lVar3 + 0xbbb49 + (ulong)local_2c[0] * 0xbbb80) = (char)param_2[1];
      return uVar4;
    }
    if (iVar1 != 0xb) {
      if (iVar1 != 0) {
        return 0x1f;
      }
      *(char *)(lVar3 + 0xbbb48 + (ulong)local_2c[0] * 0xbbb80) = (char)param_2[1];
      return uVar4;
    }
    uVar4 = 0x56;
    if (*(char *)(lVar2 + 0x46b) != '\0') {
      local_2d = (undefined1)param_2[1];
      uVar4 = (**(code **)(lVar2 + 0x3b90))
                        (lVar2 + 0x3b58,*(undefined4 *)(lVar2 + 0x3b34),
                         *(undefined4 *)(lVar2 + 0x3b3c),0x2080400f,&local_2d,1);
      if ((int)uVar4 == 0) {
        *(char *)(lVar3 + 0xbbb99 + (ulong)local_2c[0] * 0xbbb80) = (char)param_2[1];
        return uVar4;
      }
      nvCheckOkFailedNoLog
                (4,uVar4 & 0xffffffff,
                 "pRmApi->Control(pRmApi, pGpu->hInternalClient, pGpu->hInternalSubdevice, NV2080_CTRL_CMD_VGPU_MGR_INTERNAL_SET_VGPU_MIG_TIMESLICE_MODE, &params, sizeof(params))"
                 ,"src/kernel/virtualization/vgpuconfigapi.c",0x39a);
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  else {
    uVar4 = 0x57;
  }
  return uVar4;
}


// ===== 004ea970 vgpuconfigapiCtrlCmdVgpuConfigGetCapability_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int vgpuconfigapiCtrlCmdVgpuConfigGetCapability_IMPL(long param_1,uint *param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  uint local_2c [3];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar2 = *(long *)(g_pSys + 0x1f8);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x3be,
               "vgpuconfigapiCtrlCmdVgpuConfigGetCapability_IMPL",1,"NVRM: %s\n");
  iVar5 = kvgpumgrGetPgpuIndex(lVar2,*(undefined4 *)(lVar1 + 0x7ac),local_2c);
  if (iVar5 != 0) {
    return 0x57;
  }
  uVar6 = *param_2;
  uVar7 = (ulong)local_2c[0];
  if (uVar6 == 6) {
    param_2[1] = (uint)*(byte *)(lVar2 + 0xbb839 + uVar7 * 0xbbb80);
    return 0;
  }
  if (uVar6 < 7) {
    if (uVar6 == 2) {
      if (*(int *)(lVar2 + 0x250 + uVar7 * 0xbbb80) == 0) goto LAB_004eaa33;
      uVar6 = 1;
      if (*(long *)(lVar1 + 0x1bc0) != 0) {
        cVar3 = kmigmgrIsMIGEnabled_IMPL(lVar1);
        uVar6 = (uint)(cVar3 == '\0');
      }
    }
    else {
      if (uVar6 < 3) {
        if (uVar6 != 0) {
          param_2[1] = (uint)*(byte *)(lVar2 + 0xbbb49 + uVar7 * 0xbbb80);
          return 0;
        }
        param_2[1] = (uint)*(byte *)(lVar2 + 0xbbb48 + uVar7 * 0xbbb80);
        return 0;
      }
      if (uVar6 != 3) {
        iVar5 = (**(code **)(*(long *)(lVar1 + 7000) + 0x360))
                          (lVar1,*(long *)(lVar1 + 7000),param_2 + 1);
        if (iVar5 == 0) {
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kbifGetMigrationBandwidth_HAL(pGpu, pKernelBif, &pGetCapabilityParams->state)",
                   "src/kernel/virtualization/vgpuconfigapi.c",0x3ee);
        return iVar5;
      }
      uVar6 = (uint)*(byte *)(lVar1 + 0x491d);
    }
    param_2[1] = uVar6;
  }
  else {
    if (uVar6 == 9) {
      param_2[1] = (uint)*(byte *)(lVar2 + 0xbb83a + uVar7 * 0xbbb80);
      return 0;
    }
    if (uVar6 < 10) {
      if (uVar6 != 7) {
        param_2[1] = *(uint *)(lVar2 + 0x14 + (uVar7 + 1) * 0xbbb80);
        return 0;
      }
      if (*(int *)(lVar2 + 0x250 + uVar7 * 0xbbb80) != 0) {
        bVar4 = kvgpumgrIsHeterogeneousVgpuTypeSupported();
        param_2[1] = (uint)bVar4;
        return 0;
      }
    }
    else if (uVar6 == 10) {
      if (*(int *)(lVar2 + 0x250 + uVar7 * 0xbbb80) != 0) {
        param_2[1] = (uint)*(byte *)(lVar1 + 0x46b);
        return 0;
      }
    }
    else {
      if (uVar6 != 0xb) {
        nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x42a,
                     "vgpuconfigapiCtrlCmdVgpuConfigGetCapability_IMPL",4,
                     "NVRM: Failed to find vGPU device capability\n");
        return 0x1f;
      }
      if (*(int *)(lVar2 + 0x250 + uVar7 * 0xbbb80) != 0) {
        bVar4 = kvgpumgrIsMigTimeslicingModeEnabled(lVar1);
        param_2[1] = (uint)bVar4;
        return 0;
      }
    }
LAB_004eaa33:
    param_2[1] = 0;
  }
  return 0;
}


// ===== 004eac70 vgpuconfigapiCtrlCmdVgpuConfigUpdatePgpuInfo_IMPL =====

undefined8 vgpuconfigapiCtrlCmdVgpuConfigUpdatePgpuInfo_IMPL(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(*(long *)(param_1 + 0x158) + 0xe0) != 0) {
    uVar1 = kvgpumgrSetSupportedPlacementIds();
    return uVar1;
  }
  return 0x40;
}


// ===== 004eaca0 vgpuconfigapiCtrlCmdVgpuConfigSetVgpuInstanceEncoderCapacity_IMPL =====

void vgpuconfigapiCtrlCmdVgpuConfigSetVgpuInstanceEncoderCapacity_IMPL(long param_1,long param_2)

{
  kvgpumgrSetVgpuEncoderCapacity
            (*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0),param_2,
             *(undefined4 *)(param_2 + 0x10));
  return;
}


// ===== 004eacc0 vgpuconfigapiCtrlCmdVgpuConfigGetMigrationCap_IMPL =====

undefined8 vgpuconfigapiCtrlCmdVgpuConfigGetMigrationCap_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  long lVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  int local_2c [3];
  
  local_2c[0] = 0;
  lVar1 = *(long *)(g_pSys + 0x238);
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x460,
               "vgpuconfigapiCtrlCmdVgpuConfigGetMigrationCap_IMPL",1,"NVRM: %s\n");
  if (lVar1 == 0) {
    return 0x3f;
  }
  if (lVar2 == 0) {
    return 0x40;
  }
  iVar5 = osIsVgpuVfioPresent();
  if (iVar5 == 0) {
    iVar5 = osReadRegistryDword(lVar2,"RmEnableKvmVgpuMigration",local_2c);
    if (iVar5 != 0) {
      cVar4 = kvgpumgrCheckPgpuMigrationSupport(lVar2);
      *param_2 = cVar4 != '\0';
      return 0;
    }
    if (local_2c[0] == 0) {
      *param_2 = 0;
      return 0;
    }
  }
  uVar3 = kvgpumgrCheckPgpuMigrationSupport(lVar2);
  *param_2 = uVar3;
  return 0;
}


// ===== 004eade0 vgpuconfigapiCtrlCmdVgpuConfigGetPgpuMetadataString_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigGetPgpuMetadataString_IMPL(long param_1,long param_2)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_24;
  undefined8 local_20;
  
  local_20 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(g_pSys + 0x238) == 0) {
    return 0x3f;
  }
  if (lVar1 == 0) {
    return 0x40;
  }
  portMemSet(param_2,0,0x100);
  cVar2 = kvgpumgrCheckPgpuMigrationSupport(lVar1);
  if (cVar2 == '\0') {
    iVar4 = gpuGetGidInfo_IMPL(lVar1,&local_20,&local_24,0);
    if (iVar4 != 0) {
      return iVar4;
    }
    if (local_24 < 0x101) {
      portMemCopy(param_2,local_24,local_20,local_24);
      portMemFree(local_20);
      return 0;
    }
    portMemFree(local_20);
  }
  else {
    uVar3 = kvgpumgrGetPgpuDevIdEncoding(lVar1,param_2,0x100);
    if ((uVar3 != 0xffffffff) &&
       (iVar4 = kvgpumgrGetPgpuSubdevIdEncoding(lVar1,(ulong)uVar3 + param_2,0x100 - uVar3),
       iVar4 != -1)) {
      uVar3 = uVar3 + iVar4;
      cVar2 = rmcfg_IsdHOPPERorBetter(lVar1);
      if (cVar2 == '\0') {
        iVar4 = kvgpumgrGetPgpuFSEncoding(lVar1,(ulong)uVar3 + param_2,0x100 - uVar3);
        if (iVar4 == -1) {
          return 0x1a;
        }
        uVar3 = uVar3 + iVar4;
      }
      iVar4 = kvgpumgrGetPgpuCapEncoding(lVar1,param_2 + (ulong)uVar3,0x100 - uVar3);
      iVar5 = 0;
      if (iVar4 == -1) {
        iVar5 = 0x1a;
      }
      return iVar5;
    }
  }
  return 0x1a;
}


// ===== 004eafa0 vgpuconfigapiCtrlCmdVgpuConfigGetHostFbReservation_IMPL =====

undefined8 vgpuconfigapiCtrlCmdVgpuConfigGetHostFbReservation_IMPL(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar3 = *(undefined8 *)(lVar2 + 0x1b78);
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x4f3,
               "vgpuconfigapiCtrlCmdVgpuConfigGetHostFbReservation_IMPL",1,"NVRM: %s\n");
  if ((int)param_2[3] == 0) {
    *param_2 = 0;
    lVar2 = 0;
    uVar3 = 0x1f;
    param_2[1] = 0;
  }
  else {
    lVar1 = memmgrGetVgpuHostRmReservedFb_KERNEL(lVar2,uVar3);
    *param_2 = lVar1;
    lVar2 = kvgpumgrGetEccAndPrReservedFb(lVar2);
    uVar3 = 0;
    param_2[1] = lVar2;
    lVar2 = lVar2 + *param_2;
  }
  param_2[2] = lVar2;
  return uVar3;
}


// ===== 004eb050 vgpuconfigapiCtrlCmdVgpuConfigGetDoorbellEmulationSupport_IMPL =====

undefined8 vgpuconfigapiCtrlCmdVgpuConfigGetDoorbellEmulationSupport_IMPL(void)

{
  return 0x56;
}


// ===== 004eb060 vgpuconfigapiCtrlCmdVgpuConfigGetFreeSwizzId_IMPL =====

int vgpuconfigapiCtrlCmdVgpuConfigGetFreeSwizzId_IMPL(long param_1,int *param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  uint local_48;
  undefined4 local_44;
  undefined8 local_40 [2];
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar1 = *(long *)(g_pSys + 0x1f8);
  iVar3 = kvgpumgrGetPgpuIndex(lVar1,*(undefined4 *)(lVar4 + 0x7ac),&local_48);
  if (iVar3 == 0) {
    if ((*(long *)(lVar4 + 0x1bc0) == 0) ||
       (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar4), cVar2 == '\0')) {
      nvCheckFailedNoLog(1,"IS_MIG_IN_USE(pGpu)","src/kernel/virtualization/vgpuconfigapi.c",0x527);
      return 0x38;
    }
    iVar3 = osIsVgpuVfioPresent();
    if (iVar3 != 0) {
      local_44 = 0xffffffff;
      local_40[0] = 0;
      iVar3 = kvgpumgrGetPartitionFlag(param_2[1],&local_44);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,"kvgpumgrGetPartitionFlag(pParams->vgpuTypeId, &partitionFlag)",
                   "src/kernel/virtualization/vgpuconfigapi.c",0x541);
        return iVar3;
      }
      iVar3 = kvgpumgrGetVgpuTypeInfo(param_2[1],local_40);
      if (iVar3 == 0) {
        param_2[2] = -1;
        iVar3 = kvgpumgrGetSwizzId(lVar4,lVar1 + 0x48 + (ulong)local_48 * 0xbbb80,local_44,
                                   local_40[0],param_2 + 2);
        if (iVar3 == 0) {
          return 0;
        }
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kvgpumgrGetSwizzId(pGpu, pPhysGpuInfo, partitionFlag, vgpuTypeInfo, &pParams->swizzId)"
                   ,"src/kernel/virtualization/vgpuconfigapi.c",0x548);
        return iVar3;
      }
      nvAssertOkFailedNoLog
                (iVar3,"kvgpumgrGetVgpuTypeInfo(pParams->vgpuTypeId, &vgpuTypeInfo)",
                 "src/kernel/virtualization/vgpuconfigapi.c",0x544);
      return iVar3;
    }
    lVar4 = listHead_IMPL(lVar1 + 0x17770b0);
    while (lVar4 != 0) {
      if (*(int *)(lVar4 + 0x18) == *param_2) {
        param_2[2] = *(int *)(lVar4 + 0x1c);
        return 0;
      }
      lVar4 = listNext_IMPL(lVar1 + 0x17770b0);
    }
  }
  return 0x57;
}


// ===== 004eb260 vgpuconfigapiCtrlCmdPgpuGetMultiVgpuSupportInfo_IMPL =====

undefined8 vgpuconfigapiCtrlCmdPgpuGetMultiVgpuSupportInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  uint local_2c;
  
  uVar4 = 0x57;
  lVar1 = *(long *)(g_pSys + 0x1f8);
  iVar3 = kvgpumgrGetPgpuIndex
                    (lVar1,*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7ac),
                     &local_2c);
  if (iVar3 == 0) {
    uVar4 = 0;
    *param_2 = *(undefined4 *)(lVar1 + 0x14 + ((ulong)local_2c + 1) * 0xbbb80);
    bVar2 = kvgpumgrIsHeterogeneousVgpuTypeSupported();
    param_2[1] = (uint)bVar2;
    param_2[2] = (uint)*(byte *)(lVar1 + 0xbb839 + (ulong)local_2c * 0xbbb80);
  }
  return uVar4;
}


// ===== 004eb310 vgpuconfigapiCtrlCmdPgpuGetVgpuStreamingCapability_IMPL =====

undefined8 vgpuconfigapiCtrlCmdPgpuGetVgpuStreamingCapability_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  *param_2 = 0;
  *param_2 = *(char *)(lVar1 + 0x491d) != '\0';
  return 0;
}


// ===== 004eb340 vgpuconfigapiCtrlCmdGetVgpuDriversCaps_IMPL =====

undefined8 vgpuconfigapiCtrlCmdGetVgpuDriversCaps_IMPL(undefined8 param_1,uint *param_2)

{
  byte bVar1;
  
  bVar1 = kvgpumgrIsHeterogeneousVgpuTypeSupported();
  *param_2 = (uint)bVar1;
  bVar1 = kvgpumgrIsVgpuWarmUpdateSupported();
  param_2[1] = (uint)bVar1;
  return 0;
}


// ===== 004eb370 vgpuconfigapiCtrlCmdVgpuConfigSetPgpuInfo_IMPL =====

undefined8 vgpuconfigapiCtrlCmdVgpuConfigSetPgpuInfo_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  uint local_1c;
  
  lVar1 = *(long *)(g_pSys + 0x1f8);
  uVar2 = kvgpumgrGetPgpuIndex
                    (lVar1,*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x158) + 0xe0) + 0x7ac),
                     &local_1c);
  if ((int)uVar2 == 0) {
    *(undefined4 *)(lVar1 + 0x14 + ((ulong)local_1c + 1) * 0xbbb80) = *param_2;
    return uVar2;
  }
  return 0x57;
}


// ===== 004eb3f0 vgpuconfigapiCtrlCmdVgpuConfigValidateSwizzId_IMPL =====

ulong vgpuconfigapiCtrlCmdVgpuConfigValidateSwizzId_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  char cVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (((lVar1 == 0) || (*(long *)(lVar1 + 0x1bc0) == 0)) ||
     (cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar2 == '\0')) {
    nvCheckFailedNoLog(1,"IS_MIG_IN_USE(pGpu)","src/kernel/virtualization/vgpuconfigapi.c",0x5ad);
    uVar3 = 0x38;
  }
  else {
    uVar3 = kvgpumgrValidateSwizzId(lVar1,*param_2,param_2[1]);
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,
               "kvgpumgrValidateSwizzId(pGpu, pParams->vgpuTypeId, pParams->swizzId)",
               "src/kernel/virtualization/vgpuconfigapi.c",0x5b1);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 004eb4b0 vgpuconfigapiCtrlCmdVgpuConfigUpdatePlacementInfo_IMPL =====

ulong vgpuconfigapiCtrlCmdVgpuConfigUpdatePlacementInfo_IMPL(long param_1,char *param_2)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ulong uVar7;
  char local_29 [9];
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (lVar1 == 0) {
    return 0x40;
  }
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8);
  if (((*(long *)(lVar1 + 0x1bc0) == 0) ||
      (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1), cVar3 == '\0')) ||
     (cVar3 = kvgpumgrIsMigTimeslicingModeEnabled(lVar1), cVar3 == '\0')) {
    local_29[0] = *(char *)(lVar1 + 0x4a5);
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = kvgpuMgrGetSwizzIdFromDevice(lVar1,uVar2);
    uVar6 = kvgpuMgrGetHeterogeneousModePerGI(lVar1,uVar5,local_29);
    if (uVar6 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar6,
                 "kvgpuMgrGetHeterogeneousModePerGI(pGpu, swizzId, &bHeterogeneousModeEnabled)",
                 "src/kernel/virtualization/vgpuconfigapi.c",0x5ca);
      return (ulong)uVar6;
    }
  }
  if ((local_29[0] == '\0') &&
     (iVar4 = kvgpumgrCheckHomogeneousPlacementSupported(lVar1,uVar5), iVar4 != 0)) {
    *param_2 = '\0';
    param_2[2] = -1;
    param_2[3] = -1;
    return 0;
  }
  *param_2 = local_29[0];
  iVar4 = osIsVgpuVfioPresent();
  if (iVar4 == 0) {
    uVar7 = kvgpuMgrGetPlacementResource
                      (lVar1,uVar2,param_2 + 8,param_2 + 2,param_2 + 0x18,param_2 + 0x20,
                       param_2 + 0x28,param_2 + 0x30);
    return uVar7;
  }
  if (local_29[0] == '\0') {
    uVar7 = kvgpumgrUpdateHomogeneousInfo(lVar1,uVar2);
    param_2[0x28] = '\0';
    param_2[0x29] = '\0';
    param_2[0x2a] = '\0';
    param_2[0x2b] = '\0';
    param_2[0x2c] = '\0';
    param_2[0x2d] = '\0';
    param_2[0x2e] = '\0';
    param_2[0x2f] = '\0';
    param_2[0x30] = '\0';
    param_2[0x31] = '\0';
    param_2[0x32] = '\0';
    param_2[0x33] = '\0';
    param_2[0x34] = '\0';
    param_2[0x35] = '\0';
    param_2[0x36] = '\0';
    param_2[0x37] = '\0';
    return uVar7;
  }
  uVar7 = kvgpumgrUpdateHeterogeneousInfo(lVar1,uVar2,*(undefined4 *)(param_2 + 4));
  return uVar7;
}


// ===== 004eb680 vgpuconfigapiCtrlCmdVgpuSetVmName_IMPL =====

int vgpuconfigapiCtrlCmdVgpuSetVmName_IMPL(long param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  long local_20 [2];
  
  local_20[0] = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*param_2 == 0) {
    iVar2 = kvgpumgrGetHostVgpuDeviceFromVmId
                      (*(undefined4 *)(lVar1 + 0x7ac),*(undefined8 *)(param_2 + 2),local_20);
  }
  else {
    if (*param_2 != 1) {
      return 0x1f;
    }
    iVar2 = kvgpumgrGetHostVgpuDeviceFromVgpuDevName
                      (*(undefined4 *)(lVar1 + 0x7ac),param_2 + 2,local_20);
  }
  if (iVar2 != 0) {
    return iVar2;
  }
  portStringCopy(*(long *)(local_20[0] + 0x10) + 0x18,0x80,param_2 + 6,0x80);
  return 0;
}


// ===== 004eb730 vgpuconfigapiCtrlCmdVgpuConfigGetMigrationBandwidth_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int vgpuconfigapiCtrlCmdVgpuConfigGetMigrationBandwidth_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar1 + 0x908) != '\0') {
    return 0x56;
  }
  iVar2 = (**(code **)(*(long *)(lVar1 + 7000) + 0x360))(lVar1,*(long *)(lVar1 + 7000),param_2);
  if (iVar2 == 0) {
    return 0;
  }
  nvDbg_Printf("src/kernel/virtualization/vgpuconfigapi.c",0x63f,
               "vgpuconfigapiCtrlCmdVgpuConfigGetMigrationBandwidth_IMPL",4,
               "NVRM: Failed to get Migration Bandwidth rmStatus 0x%x\n");
  return iVar2;
}


// ===== 004eb7c0 nvLogBase2 =====

long nvLogBase2(ulong param_1)

{
  long lVar1;
  
  if (param_1 != 0) {
    if ((param_1 - 1 & param_1) != 0) {
      nvAssertFailedNoLog("((val) & (val - 1)) == 0","src/lib/base_utils.c",0x27);
    }
    lVar1 = 0;
    for (; (param_1 & 1) == 0; param_1 = param_1 >> 1 | 0x8000000000000000) {
      lVar1 = lVar1 + 1;
    }
    return lVar1;
  }
  nvAssertFailedNoLog("val != 0","src/lib/base_utils.c",0x26);
  return 0x40;
}


// ===== 004eb840 nvBitFieldLSZero =====

int nvBitFieldLSZero(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  
  if (param_2 != 0) {
    uVar3 = 0;
    do {
      uVar1 = *(uint *)(param_1 + uVar3 * 4);
      uVar2 = uVar1 ^ 0xffffffff;
      if (uVar2 != 0) {
        uVar2 = uVar1 + 1 & uVar2;
        return ((uint)((uVar2 & 0xaaaaaaaa) != 0) | (uint)(0xffff < uVar2) << 4 |
                (uint)((uVar2 & 0xff00ff00) != 0) << 3 | (uint)((uVar2 & 0xf0f0f0f0) != 0) << 2 |
               (uint)((uVar2 & 0xcccccccc) != 0) * 2) + (int)uVar3 * 0x20;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != param_2);
  }
  return param_2 << 5;
}


// ===== 004eb8e0 nvBitFieldTest =====

undefined4 nvBitFieldTest(long param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_3 < (uint)(param_2 << 5)) {
    uVar1 = 1 << ((byte)param_3 & 0x1f);
    uVar2 = CONCAT31((int3)(uVar1 >> 8),
                     (*(uint *)(param_1 + (ulong)(param_3 >> 5) * 4) & uVar1) != 0);
  }
  return uVar2;
}


// ===== 004eb910 nvBitFieldSet =====

void nvBitFieldSet(long param_1,int param_2,uint param_3,char param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((uint)(param_2 << 5) <= param_3) {
    nvAssertFailedNoLog("bit < numElements*32","src/lib/base_utils.c",0x71);
  }
  puVar1 = (uint *)(param_1 + (ulong)(param_3 >> 5) * 4);
  uVar4 = 1 << ((byte)param_3 & 0x1f);
  uVar2 = *puVar1;
  uVar3 = uVar2 | uVar4;
  if (param_4 == '\0') {
    uVar3 = ~uVar4 & uVar2;
  }
  *puVar1 = uVar3;
  return;
}


// ===== 004eb9a0 nvStrToL =====

int nvStrToL(byte *param_1,undefined8 *param_2,int param_3,byte param_4,undefined4 *param_5)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  *param_5 = 0;
  bVar2 = *param_1;
  while (bVar2 != 0) {
    if (((byte)(bVar2 - 0x30) < 10) ||
       ((param_3 == 0x10 && (((byte)(bVar2 + 0x9f) < 6 || ((byte)(bVar2 + 0xbf) < 6)))))) {
      *param_5 = 1;
      bVar2 = *param_1;
LAB_004eba0a:
      iVar3 = 0;
      goto joined_r0x004eba0e;
    }
    if (param_4 == bVar2) {
      bVar2 = *param_1;
      goto LAB_004eba0a;
    }
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    bVar2 = *pbVar1;
  }
  iVar3 = 0;
LAB_004eba62:
  *param_2 = param_1;
  return iVar3;
joined_r0x004eba0e:
  if (bVar2 == 0) goto LAB_004eba62;
  uVar4 = (uint)bVar2;
  if ((byte)(bVar2 - 0x30) < 10) {
    iVar5 = uVar4 - 0x30;
  }
  else {
    if (param_3 != 0x10) goto LAB_004eba62;
    if ((byte)(bVar2 + 0x9f) < 6) {
      iVar5 = uVar4 - 0x57;
    }
    else {
      if (5 < (byte)(bVar2 + 0xbf)) goto LAB_004eba62;
      iVar5 = uVar4 - 0x37;
    }
  }
  param_1 = param_1 + 1;
  iVar3 = iVar3 * param_3 + iVar5;
  bVar2 = *param_1;
  goto joined_r0x004eba0e;
}


// ===== 004eba80 nvU64ToStr =====

char * nvU64ToStr(ulong param_1,char *param_2,uint param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  char local_49 [65];
  
  if (param_3 != 0) {
    pcVar4 = local_49;
    do {
      uVar5 = (uint)param_1 & 0xf;
      cVar2 = (char)uVar5;
      cVar1 = cVar2 + '0';
      if (9 < uVar5) {
        cVar1 = cVar2 + 'W';
      }
      pcVar3 = pcVar4 + 1;
      *pcVar4 = cVar1;
      pcVar4 = pcVar3;
      param_1 = param_1 >> 4;
    } while (pcVar3 != local_49 + param_3);
    pcVar4 = param_2;
    do {
      pcVar3 = pcVar4 + 1;
      *pcVar4 = local_49[((param_3 - 1) + (int)param_2) - (int)pcVar4];
      pcVar4 = pcVar3;
    } while (param_2 + param_3 != pcVar3);
    param_2[param_3] = '\0';
    return param_2;
  }
  *param_2 = '\0';
  return param_2;
}


// ===== 004ebb30 nvStringLen =====

ulong nvStringLen(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = 0;
  do {
    uVar2 = (ulong)uVar1;
    uVar1 = uVar1 + 1;
  } while (*(char *)(param_1 + uVar2) != '\0');
  return uVar2;
}


// ===== 004ebb60 prbEndPackedField =====

ulong prbEndPackedField(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  int *piVar6;
  byte *pbVar7;
  byte bVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  
  uVar2 = *(uint *)(param_1 + 0x148);
  if (0 < (int)uVar2) {
    uVar3 = *(uint *)(param_1 + 0x14c);
    if ((uVar3 & 4) == 0) {
      return 0;
    }
    *(uint *)(param_1 + 0x14c) = uVar3 & 0xfffffffb;
    if (uVar2 != 1) {
      lVar1 = param_1 + (ulong)uVar2 * 0x28;
      lVar4 = *(long *)(lVar1 + -0x28);
      lVar5 = *(long *)(lVar1 + -0x20);
      piVar6 = *(int **)(param_1 + 0x18 + (ulong)(uVar2 - 1) * 0x28);
      *(uint *)(param_1 + 0x148) = uVar2 - 1;
      uVar11 = lVar5 - lVar4;
      if ((uint)uVar11 == 0) {
        return uVar11 & 0xffffffff;
      }
      uVar10 = (ulong)(uVar2 - 2);
      pbVar7 = *(byte **)(lVar1 + -0x48);
      lVar5 = param_1 + uVar10 * 0x28;
      if (*(int *)(lVar5 + 0x10) != (int)pbVar7) {
        uVar9 = (ulong)(*piVar6 * 8 + 2);
        if ((uVar3 & 0x10) == 0) {
          do {
            bVar8 = (byte)uVar9;
            if (uVar9 < 0x80) {
              *pbVar7 = bVar8;
              pbVar7 = (byte *)(*(long *)(lVar1 + -0x48) + 1);
              *(byte **)(lVar1 + -0x48) = pbVar7;
LAB_004ebc6e:
              lVar5 = param_1 + uVar10 * 0x28;
              if (*(int *)(lVar5 + 0x10) == (int)pbVar7) {
                return 2;
              }
              uVar12 = uVar11 & 0xffffffff;
              uVar9 = uVar12;
              if ((*(byte *)(param_1 + 0x14c) & 0x10) == 0) {
                while (bVar8 = (byte)uVar9, 0x7f < uVar9) {
                  uVar9 = uVar9 >> 7;
                  *pbVar7 = bVar8 | 0x80;
                  pbVar7 = (byte *)(*(long *)(lVar1 + -0x48) + 1);
                  *(byte **)(lVar1 + -0x48) = pbVar7;
                  if (*(int *)(param_1 + 0x10 + uVar10 * 0x28) == (int)pbVar7) {
                    return 2;
                  }
                }
                *pbVar7 = bVar8;
                pbVar7 = (byte *)(*(long *)(lVar1 + -0x48) + 1);
                *(byte **)(lVar1 + -0x48) = pbVar7;
              }
              else {
                while( true ) {
                  pbVar7 = pbVar7 + 1;
                  uVar9 = uVar9 >> 7;
                  *(byte **)(lVar1 + -0x48) = pbVar7;
                  if (uVar9 == 0) break;
                  if (*(int *)(lVar5 + 0x10) == (int)pbVar7) {
                    return 2;
                  }
                }
              }
              if ((uint)((int)*(undefined8 *)(param_1 + 0x10 + uVar10 * 0x28) - (int)pbVar7) <
                  (uint)uVar11) {
                return 2;
              }
              if ((*(byte *)(param_1 + 0x14c) & 0x10) == 0) {
                portMemMove(pbVar7,uVar12,lVar4,uVar12);
                pbVar7 = *(byte **)(lVar1 + -0x48);
              }
              *(byte **)(lVar1 + -0x48) = pbVar7 + uVar12;
              return 0;
            }
            uVar9 = uVar9 >> 7;
            *pbVar7 = bVar8 | 0x80;
            pbVar7 = (byte *)(*(long *)(lVar1 + -0x48) + 1);
            *(byte **)(lVar1 + -0x48) = pbVar7;
          } while (*(int *)(param_1 + 0x10 + uVar10 * 0x28) != (int)pbVar7);
        }
        else {
          do {
            pbVar7 = pbVar7 + 1;
            uVar9 = uVar9 >> 7;
            *(byte **)(lVar1 + -0x48) = pbVar7;
            if (uVar9 == 0) goto LAB_004ebc6e;
          } while (*(int *)(lVar5 + 0x10) != (int)pbVar7);
        }
      }
      return 2;
    }
  }
  return 0x3f;
}


// ===== 004ebd80 prbEncAddField =====

undefined8 prbEncAddField(long param_1,int *param_2,ulong *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  byte *pbVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  long lVar14;
  byte bVar15;
  uint uVar16;
  ulong uVar17;
  
  uVar13 = *(uint *)(param_1 + 0x14c);
  if (((uVar13 & 1) != 0) || (*(int *)(param_1 + 0x148) < 1)) {
    return 0x3f;
  }
  uVar7 = *(int *)(param_1 + 0x148) - 1;
  if ((*(byte *)((long)param_2 + 5) & 8) == 0) {
    piVar9 = *(int **)(param_1 + 0x20 + (ulong)uVar7 * 0x28);
    iVar3 = *piVar9;
    if (iVar3 != 0) {
      piVar9 = *(int **)(piVar9 + 2);
      iVar2 = 0;
      do {
        if (param_2 == piVar9) {
          if (iVar2 == iVar3) {
            return 0x3f;
          }
          goto LAB_004ebe1e;
        }
        iVar2 = iVar2 + 1;
        piVar9 = piVar9 + 6;
      } while (iVar2 != iVar3);
    }
    return 0x3f;
  }
LAB_004ebe1e:
  if ((*(byte *)((long)param_2 + 5) & 2) == 0) {
    uVar4 = prbEndPackedField(param_1);
    if ((int)uVar4 != 0) {
      return uVar4;
    }
    uVar13 = *(uint *)(param_1 + 0x14c);
    uVar7 = *(int *)(param_1 + 0x148) - 1;
    lVar14 = (long)(int)uVar7;
    lVar5 = *(long *)(param_1 + 0x10 + lVar14 * 0x28);
LAB_004ebeb1:
    uVar12 = 0;
    iVar3 = (int)lVar5;
    bVar15 = *(byte *)(param_2 + 1) >> 2;
    bVar8 = *(byte *)((long)param_2 + 5) & 2;
    if (bVar15 == 8) {
LAB_004ec0be:
      uVar11 = (uint)*param_3;
      uVar12 = (ulong)uVar11;
      if (bVar8 != 0) goto LAB_004ec01c;
LAB_004ec0cc:
      uVar17 = 0;
      uVar11 = 5;
    }
    else {
      if (bVar15 < 9) {
        if (bVar15 == 4) {
          uVar11 = (uint)*param_3;
joined_r0x004ec53e:
          uVar12 = (ulong)uVar11;
        }
        else {
          if (bVar15 < 5) {
            if (bVar15 == 2) goto LAB_004ec49c;
            if (bVar15 != 3) {
              if (*(byte *)(param_2 + 1) >> 2 == 0) goto LAB_004ebefe;
              goto LAB_004ec0be;
            }
          }
          else {
            if (bVar15 == 6) {
              uVar11 = (uint)*param_3 * 2 ^ (int)(uint)*param_3 >> 0x1f;
              goto joined_r0x004ec53e;
            }
            if (bVar15 == 7) {
              uVar12 = *param_3 * 2 ^ (long)*param_3 >> 0x3f;
              goto joined_r0x004ec5af;
            }
          }
          uVar12 = *param_3;
        }
      }
      else {
        if (bVar15 != 0xd) {
          if (0xd < bVar15) {
            if (((bVar15 != 0xf) && (bVar15 != 0x10)) && (bVar15 != 0xe)) {
              if (bVar8 != 0) {
                uVar11 = 0;
                pbVar10 = *(byte **)(param_1 + 8 + lVar14 * 0x28);
                goto LAB_004ec025;
              }
              goto LAB_004ec0cc;
            }
            uVar17 = *param_3;
            uVar12 = (ulong)(uint)param_3[1];
            uVar11 = 2;
            if (bVar8 != 0) goto LAB_004ec24d;
            goto LAB_004ec0d5;
          }
          if (bVar15 != 0xb) {
            if (bVar15 == 0xc) {
              uVar12 = (ulong)(byte)*param_3;
              goto joined_r0x004ec5af;
            }
            if (bVar15 != 9) goto LAB_004ec0be;
          }
LAB_004ebefe:
          uVar12 = *param_3;
          if (bVar8 != 0) goto LAB_004ec16c;
          uVar17 = 0;
          uVar11 = 1;
          goto LAB_004ec0d5;
        }
LAB_004ec49c:
        uVar12 = (ulong)(int)(uint)*param_3;
      }
joined_r0x004ec5af:
      if (bVar8 != 0) goto LAB_004ec390;
      uVar17 = 0;
      uVar11 = 0;
    }
LAB_004ec0d5:
    lVar5 = param_1 + lVar14 * 0x28;
    pbVar10 = *(byte **)(lVar5 + 8);
    if (iVar3 != (int)pbVar10) {
      uVar6 = (ulong)(*param_2 << 3 | uVar11);
      if ((uVar13 & 0x10) == 0) {
        do {
          bVar8 = (byte)uVar6;
          if (uVar6 < 0x80) {
            *pbVar10 = bVar8;
            pbVar10 = (byte *)(*(long *)(lVar5 + 8) + 1);
            *(byte **)(lVar5 + 8) = pbVar10;
            goto LAB_004ec42e;
          }
          uVar6 = uVar6 >> 7;
          *pbVar10 = bVar8 | 0x80;
          pbVar10 = (byte *)(*(long *)(lVar5 + 8) + 1);
          *(byte **)(lVar5 + 8) = pbVar10;
        } while (*(int *)(param_1 + 0x10 + lVar14 * 0x28) != (int)pbVar10);
      }
      else {
        do {
          pbVar10 = pbVar10 + 1;
          uVar6 = uVar6 >> 7;
          *(byte **)(lVar5 + 8) = pbVar10;
          if (uVar6 == 0) goto LAB_004ec42e;
        } while (*(int *)(lVar5 + 0x10) != (int)pbVar10);
      }
    }
  }
  else {
    lVar5 = param_1 + (ulong)uVar7 * 0x28;
    if (*(int **)(lVar5 + 0x18) != param_2) {
      uVar4 = prbEndPackedField(param_1);
      if ((int)uVar4 != 0) {
        return uVar4;
      }
      if ((*(byte *)((long)param_2 + 5) & 2) == 0) {
        return 0x3f;
      }
      uVar7 = *(uint *)(param_1 + 0x148);
      if (7 < (int)uVar7) {
        return 0x1a;
      }
      lVar14 = (long)(int)uVar7;
      *(uint *)(param_1 + 0x148) = uVar7 + 1;
      *(int **)(param_1 + 0x18 + lVar14 * 0x28) = param_2;
      lVar1 = param_1 + (long)(int)(uVar7 - 1) * 0x28;
      *(undefined8 *)(param_1 + 0x20 + lVar14 * 0x28) = *(undefined8 *)(lVar1 + 0x20);
      uVar11 = *(uint *)(param_1 + 0x14c);
      uVar13 = uVar11 | 4;
      *(uint *)(param_1 + 0x14c) = uVar13;
      lVar5 = *(long *)(param_1 + -0x20 + lVar14 * 0x28);
      uVar16 = (int)*(undefined8 *)(lVar1 + 0x10) - (int)lVar5;
      if (uVar16 < 10) {
        *(ulong *)(param_1 + 0x148) = CONCAT44(uVar11,uVar7) & 0xfffffffbffffffff;
        return 2;
      }
      lVar5 = lVar5 + 10;
      *(long *)(param_1 + lVar14 * 0x28) = lVar5;
      *(long *)(param_1 + 8 + lVar14 * 0x28) = lVar5;
      lVar5 = lVar5 + (ulong)(uVar16 - 10);
      *(long *)(param_1 + 0x10 + lVar14 * 0x28) = lVar5;
      goto LAB_004ebeb1;
    }
    iVar3 = (int)*(undefined8 *)(lVar5 + 0x10);
    bVar8 = *(byte *)(param_2 + 1) >> 2;
    if (bVar8 == 8) {
LAB_004ec017:
      uVar11 = (uint)*param_3;
      lVar14 = (long)(int)uVar7;
LAB_004ec01c:
      pbVar10 = *(byte **)(param_1 + 8 + lVar14 * 0x28);
LAB_004ec025:
      if ((uint)(iVar3 - (int)pbVar10) < 4) {
        return 2;
      }
      if ((uVar13 & 0x10) == 0) {
        *pbVar10 = (byte)uVar11;
        lVar5 = param_1 + (long)(int)uVar7 * 0x28;
        *(char *)(*(long *)(lVar5 + 8) + 1) = (char)(uVar11 >> 8);
        *(char *)(*(long *)(lVar5 + 8) + 2) = (char)(uVar11 >> 0x10);
        *(char *)(*(long *)(lVar5 + 8) + 3) = (char)(uVar11 >> 0x18);
        pbVar10 = *(byte **)(lVar5 + 8);
      }
      *(byte **)(param_1 + 8 + (long)(int)uVar7 * 0x28) = pbVar10 + 4;
      return 0;
    }
    if (8 < bVar8) {
      if (bVar8 == 0xd) {
LAB_004ec4bf:
        uVar12 = (ulong)(int)(uint)*param_3;
        lVar14 = (long)(int)uVar7;
        goto LAB_004ec390;
      }
      if (0xd < bVar8) {
        if (((bVar8 != 0xf) && (bVar8 != 0x10)) && (bVar8 != 0xe)) {
          pbVar10 = *(byte **)(lVar5 + 8);
          uVar11 = 0;
          goto LAB_004ec025;
        }
        lVar14 = (long)(int)uVar7;
        uVar17 = *param_3;
        uVar12 = (ulong)(uint)param_3[1];
LAB_004ec24d:
        pbVar10 = *(byte **)(param_1 + 8 + lVar14 * 0x28);
LAB_004ec256:
        if (iVar3 == (int)pbVar10) {
          return 2;
        }
        uVar6 = uVar12;
        if ((uVar13 & 0x10) == 0) {
          while (bVar8 = (byte)uVar6, 0x7f < uVar6) {
            uVar6 = uVar6 >> 7;
            *pbVar10 = bVar8 | 0x80;
            lVar5 = param_1 + lVar14 * 0x28;
            pbVar10 = (byte *)(*(long *)(lVar5 + 8) + 1);
            *(byte **)(lVar5 + 8) = pbVar10;
            if (*(int *)(lVar5 + 0x10) == (int)pbVar10) {
              return 2;
            }
          }
          *pbVar10 = bVar8;
          lVar5 = *(long *)(param_1 + 8 + lVar14 * 0x28) + 1;
          *(long *)(param_1 + 8 + lVar14 * 0x28) = lVar5;
        }
        else {
          lVar5 = param_1 + lVar14 * 0x28;
          while( true ) {
            pbVar10 = pbVar10 + 1;
            uVar6 = uVar6 >> 7;
            *(byte **)(lVar5 + 8) = pbVar10;
            if (uVar6 == 0) break;
            if (*(int *)(lVar5 + 0x10) == (int)pbVar10) {
              return 2;
            }
          }
          lVar5 = *(long *)(param_1 + 8 + lVar14 * 0x28);
        }
        lVar1 = param_1 + lVar14 * 0x28;
        if ((uint)((int)*(undefined8 *)(lVar1 + 0x10) - (int)lVar5) < uVar12) {
          return 2;
        }
        if ((*(byte *)(param_1 + 0x14c) & 0x10) == 0) {
          if ((*(byte *)(param_2 + 1) & 0xfc) == 0x40) {
            portMemMove(lVar5,uVar12,uVar17,uVar12);
            lVar5 = *(long *)(lVar1 + 8);
          }
          else {
            portMemCopy();
            lVar5 = *(long *)(lVar1 + 8);
          }
        }
        *(ulong *)(param_1 + 8 + lVar14 * 0x28) = lVar5 + uVar12;
        return 0;
      }
      if (bVar8 != 0xb) {
        if (bVar8 == 0xc) {
          uVar12 = (ulong)(byte)*param_3;
          lVar14 = (long)(int)uVar7;
          goto LAB_004ec390;
        }
        if (bVar8 != 9) goto LAB_004ec017;
      }
LAB_004ec166:
      uVar12 = *param_3;
      lVar14 = (long)(int)uVar7;
LAB_004ec16c:
      pbVar10 = *(byte **)(param_1 + 8 + lVar14 * 0x28);
LAB_004ec175:
      if ((uint)(iVar3 - (int)pbVar10) < 8) {
        return 2;
      }
      if ((uVar13 & 0x10) == 0) {
        *pbVar10 = (byte)uVar12;
        lVar5 = param_1 + lVar14 * 0x28;
        *(char *)(*(long *)(lVar5 + 8) + 1) = (char)(uVar12 >> 8);
        *(char *)(*(long *)(lVar5 + 8) + 2) = (char)(uVar12 >> 0x10);
        *(char *)(*(long *)(lVar5 + 8) + 3) = (char)(uVar12 >> 0x18);
        *(char *)(*(long *)(lVar5 + 8) + 4) = (char)(uVar12 >> 0x20);
        *(char *)(*(long *)(lVar5 + 8) + 5) = (char)(uVar12 >> 0x28);
        *(char *)(*(long *)(lVar5 + 8) + 6) = (char)(uVar12 >> 0x30);
        *(char *)(*(long *)(lVar5 + 8) + 7) = (char)(uVar12 >> 0x38);
        pbVar10 = *(byte **)(lVar5 + 8);
      }
      *(byte **)(param_1 + 8 + lVar14 * 0x28) = pbVar10 + 8;
      return 0;
    }
    if (bVar8 == 4) {
      uVar12 = (ulong)(uint)*param_3;
      lVar14 = (long)(int)uVar7;
    }
    else if (bVar8 < 5) {
      if (bVar8 == 2) goto LAB_004ec4bf;
      if (bVar8 != 3) {
        if (*(byte *)(param_2 + 1) >> 2 == 0) goto LAB_004ec166;
        goto LAB_004ec017;
      }
LAB_004ec38a:
      uVar12 = *param_3;
      lVar14 = (long)(int)uVar7;
    }
    else if (bVar8 == 6) {
      lVar14 = (long)(int)uVar7;
      uVar12 = (ulong)((int)(uint)*param_3 >> 0x1f ^ (uint)*param_3 * 2);
    }
    else {
      if (bVar8 != 7) goto LAB_004ec38a;
      lVar14 = (long)(int)uVar7;
      uVar12 = (long)*param_3 >> 0x3f ^ *param_3 * 2;
    }
LAB_004ec390:
    lVar5 = param_1 + lVar14 * 0x28;
    pbVar10 = *(byte **)(lVar5 + 8);
    if (iVar3 != (int)pbVar10) {
      if ((uVar13 & 0x10) == 0) {
        do {
          bVar8 = (byte)uVar12;
          if (uVar12 < 0x80) {
            *pbVar10 = bVar8;
            *(long *)(lVar5 + 8) = *(long *)(lVar5 + 8) + 1;
            return 0;
          }
          uVar12 = uVar12 >> 7;
          *pbVar10 = bVar8 | 0x80;
          pbVar10 = (byte *)(*(long *)(lVar5 + 8) + 1);
          *(byte **)(lVar5 + 8) = pbVar10;
        } while (*(int *)(param_1 + 0x10 + lVar14 * 0x28) != (int)pbVar10);
      }
      else {
        do {
          pbVar10 = pbVar10 + 1;
          uVar12 = uVar12 >> 7;
          *(byte **)(lVar5 + 8) = pbVar10;
          if (uVar12 == 0) {
            return 0;
          }
        } while (*(int *)(lVar5 + 0x10) != (int)pbVar10);
      }
    }
  }
  return 2;
LAB_004ec42e:
  uVar13 = *(uint *)(param_1 + 0x14c);
  iVar3 = (int)*(undefined8 *)(param_1 + 0x10 + lVar14 * 0x28);
  if (uVar11 == 2) goto LAB_004ec256;
  if (uVar11 == 5) {
    uVar11 = (uint)uVar12;
    goto LAB_004ec025;
  }
  if (uVar11 == 1) goto LAB_004ec175;
  goto LAB_004ec390;
}


// ===== 004ec5f0 prbEncStart =====

void prbEncStart(long *param_1,long param_2,long param_3,uint param_4,long param_5)

{
  *param_1 = param_3;
  param_1[1] = param_3;
  param_1[2] = param_3 + (ulong)param_4;
  param_1[3] = 0;
  *(undefined4 *)(param_1 + 0x29) = 1;
  param_1[4] = param_2;
  param_1[0x28] = param_5;
  *(uint *)((long)param_1 + 0x14c) = (uint)(param_5 != 0) << 5;
  return;
}


// ===== 004ec640 prbEncStartAlloc =====

undefined8 prbEncStartAlloc(long *param_1,long param_2,ulong param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = portMemAllocNonPaged(param_3 & 0xffffffff);
  if (lVar2 == 0) {
    nvDbg_Printf("src/lib/protobuf/prbenc.c",0x127,"prbEncStartAlloc",4,
                 "NVRM: Can\'t allocate memory for protocol buffers.\n");
    uVar1 = 1;
    uVar3 = 0x51;
  }
  else {
    *param_1 = lVar2;
    param_1[1] = lVar2;
    param_1[2] = lVar2 + (param_3 & 0xffffffff);
    param_1[3] = 0;
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x29) = 1;
    param_1[4] = param_2;
    uVar1 = (uint)(param_4 != 0) << 5 | 2;
    param_1[0x28] = param_4;
  }
  *(uint *)((long)param_1 + 0x14c) = uVar1;
  return uVar3;
}


// ===== 004ec6f0 prbEncStartCount =====

void prbEncStartCount(undefined8 *param_1,undefined8 param_2,uint param_3)

{
  *param_1 = 0;
  param_1[2] = (ulong)param_3;
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[4] = param_2;
  param_1[0x28] = 0;
  param_1[0x29] = 0x1000000001;
  return;
}


// ===== 004ec740 prbFreeAllocatedBuffer =====

void prbFreeAllocatedBuffer(undefined8 *param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((long)param_1 + 0x14c);
  if ((uVar1 & 2) != 0) {
    portMemFree(*param_1);
    *param_1 = 0;
    uVar1 = *(uint *)((long)param_1 + 0x14c);
    param_1[1] = 0;
    param_1[2] = 0;
  }
  *(undefined4 *)(param_1 + 0x29) = 1;
  *(uint *)((long)param_1 + 0x14c) = uVar1 & 0xfffffffd | 1;
  return;
}


// ===== 004ec7b0 prbEncFinish =====

int prbEncFinish(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  if ((*(byte *)((long)param_1 + 0x14c) & 1) == 0) {
    prbEndPackedField();
  }
  uVar1 = *param_1;
  *param_2 = uVar1;
  *(uint *)((long)param_1 + 0x14c) = *(uint *)((long)param_1 + 0x14c) | 1;
  return (int)param_1[1] - (int)uVar1;
}


// ===== 004ec800 prbEncNestedStart =====

undefined8 prbEncNestedStart(long param_1,long param_2)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  
  if ((*(byte *)(param_1 + 0x14c) & 1) != 0) {
    return 0x3f;
  }
  uVar3 = prbEndPackedField();
  if ((int)uVar3 == 0) {
    if ((*(byte *)(param_2 + 4) & 0xfc) != 0x40) {
      return 0x3f;
    }
    iVar2 = *(int *)(param_1 + 0x148);
    if (7 < iVar2) {
      return 0x1a;
    }
    *(int *)(param_1 + 0x148) = iVar2 + 1;
    plVar1 = (long *)(param_1 + (long)iVar2 * 0x28);
    plVar1[3] = param_2;
    plVar1[4] = *(long *)(param_2 + 8);
    uVar5 = (int)*(undefined8 *)(param_1 + 0x10 + (long)(iVar2 + -1) * 0x28) - (int)plVar1[-4];
    if (uVar5 < 10) {
      *(int *)(param_1 + 0x148) = iVar2;
      return 2;
    }
    lVar4 = plVar1[-4] + 10;
    *plVar1 = lVar4;
    plVar1[1] = lVar4;
    plVar1[2] = lVar4 + (ulong)(uVar5 - 10);
  }
  return uVar3;
}


// ===== 004ec8e0 prbEncStubbedAddBytes =====

int prbEncStubbedAddBytes(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return 0x1f;
  }
  iVar2 = 2;
  lVar1 = param_1 + (long)*(int *)(param_1 + 0x148) * 0x28;
  if (param_3 <=
      (uint)((int)*(undefined8 *)(param_1 + 0x10 + (long)(*(int *)(param_1 + 0x148) + -1) * 0x28) -
            (int)*(undefined8 *)(lVar1 + -0x20))) {
    iVar2 = prbEndPackedField();
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((*(byte *)(param_1 + 0x14c) & 0x10) == 0) {
      portMemMove(*(undefined8 *)(lVar1 + -0x20),(ulong)param_3,param_2);
    }
    *(long *)(lVar1 + -0x20) = *(long *)(lVar1 + -0x20) + (ulong)param_3;
    iVar2 = 0;
  }
  return iVar2;
}


// ===== 004ec9b0 prbEncNestedEnd =====

undefined8 prbEncNestedEnd(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 local_18;
  int local_10;
  
  if ((*(byte *)(param_1 + 0x14c) & 1) != 0) {
    return 0x3f;
  }
  uVar2 = prbEndPackedField();
  if ((int)uVar2 == 0) {
    uVar1 = *(uint *)(param_1 + 0x148);
    if ((int)uVar1 < 2) {
      return 0x3f;
    }
    *(uint *)(param_1 + 0x148) = uVar1 - 1;
    local_18 = *(undefined8 *)(param_1 + -0x28 + (ulong)uVar1 * 0x28);
    local_10 = (int)*(undefined8 *)(param_1 + -0x20 + (ulong)uVar1 * 0x28) - (int)local_18;
    uVar2 = prbEncAddField(param_1,*(undefined8 *)(param_1 + 0x18 + (ulong)(uVar1 - 1) * 0x28),
                           &local_18);
  }
  return uVar2;
}


// ===== 004eca40 prbEncBufLeft =====

int prbEncBufLeft(long param_1)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x148)) {
    uVar2 = (ulong)(*(int *)(param_1 + 0x148) - 1);
    iVar1 = (int)*(undefined8 *)(param_1 + 0x10 + uVar2 * 0x28) -
            *(int *)(param_1 + 8 + uVar2 * 0x28);
  }
  return iVar1;
}


// ===== 004eca70 prbEncAddUInt32 =====

void prbEncAddUInt32(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_18 [4];
  
  local_18[0] = param_3;
  prbEncAddField(param_1,param_2,local_18);
  return;
}


// ===== 004eca90 prbEncAddUInt64 =====

void prbEncAddUInt64(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_18 [2];
  
  local_18[0] = param_3;
  prbEncAddField(param_1,param_2,local_18);
  return;
}


// ===== 004ecab0 prbEncAddBool =====

void prbEncAddBool(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  undefined1 local_18 [16];
  
  local_18[0] = param_3;
  prbEncAddField(param_1,param_2,local_18);
  return;
}


// ===== 004ecad0 prbEncAddEnum =====

void prbEncAddEnum(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 local_18 [4];
  
  local_18[0] = param_3;
  prbEncAddField(param_1,param_2,local_18);
  return;
}


// ===== 004ecaf0 prbEncAddString =====

void prbEncAddString(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_28;
  undefined4 local_20;
  
  local_28 = param_3;
  local_20 = portStringLength(param_3);
  prbEncAddField(param_1,param_2,&local_28);
  return;
}


// ===== 004ecb30 prbEncAddBytes =====

void prbEncAddBytes(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_18;
  undefined4 local_10;
  
  local_18 = param_3;
  local_10 = param_4;
  prbEncAddField(param_1,param_2,&local_18);
  return;
}


// ===== 004ecb60 prbEncCatMsg =====

undefined4 prbEncCatMsg(long param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  uint uVar14;
  byte *local_38;
  uint local_30;
  
  if (param_2 == (byte *)0x0) {
    return 0x3d;
  }
  bVar1 = *param_2;
  uVar9 = 1;
  uVar10 = (uint)bVar1;
  if ((char)bVar1 < '\0') {
    lVar11 = 0;
    uVar12 = 0;
    iVar7 = 0;
    do {
      if (lVar11 == (ulong)param_3 - 1) goto LAB_004ecce0;
      iVar8 = (int)lVar11;
      bVar6 = (byte)iVar7;
      iVar7 = iVar7 + 7;
      uVar12 = uVar12 | (ulong)(bVar1 & 0x7f) << (bVar6 & 0x3f);
      uVar10 = (uint)uVar12;
      bVar1 = param_2[lVar11 + 1];
      if (-1 < (char)bVar1) {
        uVar9 = iVar8 + 2;
        uVar10 = uVar10 | (uint)bVar1 << ((byte)iVar7 & 0x3f);
        goto LAB_004ecbc3;
      }
      lVar11 = lVar11 + 1;
    } while (iVar7 != 0x46);
    uVar9 = iVar8 + 2;
  }
LAB_004ecbc3:
  if (uVar9 < param_3) {
    if ((uVar10 & 7) == 2) {
      puVar3 = *(uint **)(param_1 + 0x20 + (long)(*(int *)(param_1 + 0x148) + -1) * 0x28);
      uVar2 = *puVar3;
      if (uVar2 != 0) {
        uVar12 = 0;
        puVar3 = *(uint **)(puVar3 + 2);
        puVar5 = puVar3;
        while (*puVar5 != uVar10 >> 3) {
          uVar14 = (uint)uVar12 + 1;
          uVar12 = (ulong)uVar14;
          puVar5 = puVar5 + 6;
          if (uVar14 == uVar2) {
            return 0x3f;
          }
        }
        if ((uint)uVar12 == uVar2) {
          return 0x3f;
        }
        uVar10 = 1;
        param_2 = param_2 + uVar9;
        bVar1 = *param_2;
        local_30 = (uint)bVar1;
        uVar4 = 2;
        if ((char)bVar1 < '\0') {
          lVar11 = 0;
          uVar13 = 0;
          iVar7 = 0;
          do {
            if (lVar11 == (ulong)(param_3 - uVar9) - 1) {
              return 2;
            }
            iVar8 = (int)lVar11;
            bVar6 = (byte)iVar7;
            iVar7 = iVar7 + 7;
            uVar13 = uVar13 | (ulong)(bVar1 & 0x7f) << (bVar6 & 0x3f);
            local_30 = (uint)uVar13;
            bVar1 = param_2[lVar11 + 1];
            if (-1 < (char)bVar1) {
              uVar10 = iVar8 + 2;
              local_30 = local_30 | (uint)bVar1 << ((byte)iVar7 & 0x3f);
              goto LAB_004ecca7;
            }
            lVar11 = lVar11 + 1;
          } while (iVar7 != 0x46);
          uVar10 = iVar8 + 2;
        }
LAB_004ecca7:
        if (local_30 <= (param_3 - uVar9) - uVar10) {
          local_38 = param_2 + uVar10;
          uVar4 = prbEncAddField(param_1,puVar3 + uVar12 * 6,&local_38);
        }
        return uVar4;
      }
    }
    uVar4 = 0x3f;
  }
  else {
LAB_004ecce0:
    uVar4 = 2;
  }
  return uVar4;
}


// ===== 004ecd60 prbEncGpuRegImm =====

int prbEncGpuRegImm(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = prbEncNestedStart(param_4,param_5);
  if (iVar1 == 0) {
    iVar1 = prbEncAddEnum(param_4,prb_fields_regs_regsandmem,1);
    if ((iVar1 != 0) || (iVar1 = prbEncAddUInt64(param_4,0xc63538,param_2), iVar1 != 0)) {
      prbEncNestedEnd(param_4);
      return iVar1;
    }
    iVar1 = prbEncAddUInt32(param_4,0xc63568,param_3);
    iVar2 = prbEncNestedEnd(param_4);
    if (iVar1 == 0) {
      iVar1 = iVar2;
    }
  }
  return iVar1;
}


// ===== 004ece20 prbSetupDclMsg =====

ulong prbSetupDclMsg(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  ulong uVar1;
  
  uVar1 = prbEncStartAlloc(param_1,0x5a7cd0,param_2,0);
  if ((int)uVar1 == 0) {
    uVar1 = prbEncNestedStart(param_1,param_3);
    if ((int)uVar1 != 0) {
      prbFreeAllocatedBuffer(param_1);
      return uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}


// ===== 004ece80 prbEncUnwindNesting =====

undefined8 prbEncUnwindNesting(long param_1,byte param_2)

{
  undefined8 uVar1;
  
  do {
    if (*(int *)(param_1 + 0x148) <= (int)(uint)param_2) {
      return 0;
    }
    uVar1 = prbEncNestedEnd(param_1);
  } while ((int)uVar1 == 0);
  return uVar1;
}


// ===== 004ecec0 _refcntReleaseReferences =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int _refcntReleaseReferences
              (long param_1,undefined8 param_2,char param_3,ulong param_4,undefined1 *param_5)

{
  int iVar1;
  uint *puVar2;
  undefined8 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  *param_5 = 0;
  if (*(int *)(param_1 + 0x80) == 3) {
    return 0x40;
  }
  puVar2 = (uint *)mapFind_IMPL(param_1 + 0x60);
  if (puVar2 == (uint *)0x0) {
    iVar6 = 0x16;
LAB_004ed00e:
    if (*(int *)(param_1 + 0x80) != 0) {
      return iVar6;
    }
  }
  else {
    uVar5 = *puVar2;
    uVar4 = *(uint *)(param_1 + 0x84);
    if (param_3 != '\0') {
      if (uVar5 <= uVar4) {
LAB_004ecf1a:
        uVar4 = uVar4 - uVar5;
        goto LAB_004ecf1c;
      }
LAB_004ecf75:
      nvAssertFailedNoLog(&DAT_00da31b5,"src/lib/ref_count.c",0x1db);
      iVar6 = 0x40;
      *(undefined4 *)(param_1 + 0x80) = 3;
      uVar5 = 3;
      if (*puVar2 == 0) {
LAB_004ed028:
        mapRemove_IMPL(param_1 + 0x60,puVar2,uVar5);
        *param_5 = 1;
        goto LAB_004ecf34;
      }
LAB_004ecfb0:
      if (*(int *)(param_1 + 0x84) != 0) {
        return iVar6;
      }
      if ((param_4 & 1) != 0) {
        return iVar6;
      }
      if (*(code **)(param_1 + 0x88) == (code *)0x0) {
        *(undefined4 *)(param_1 + 0x80) = 0;
        return iVar6;
      }
      uVar3 = (**(code **)(param_1 + 0x88))(param_1,*(undefined8 *)(param_1 + 0x50),uVar5,0);
      if ((int)uVar3 == 0) {
        *(undefined4 *)(param_1 + 0x80) = 0;
        iVar1 = *(int *)(param_1 + 0x84);
        goto LAB_004ecf44;
      }
      nvDbg_Printf("src/lib/ref_count.c",0x1f5,"_refcntReleaseReferences",4,
                   "NVRM: Failed to enter default state (current state: %d, status: 0x%08x)\n",
                   *(undefined4 *)(param_1 + 0x80),uVar3);
      bVar7 = iVar6 == 0;
      iVar6 = 0x40;
      if (bVar7) {
        iVar6 = (int)uVar3;
      }
      goto LAB_004ed00e;
    }
    if (uVar5 != 0) {
      uVar5 = 1;
      if (uVar4 != 0) goto LAB_004ecf1a;
      goto LAB_004ecf75;
    }
LAB_004ecf1c:
    *(uint *)(param_1 + 0x84) = uVar4;
    uVar4 = *puVar2;
    *puVar2 = uVar4 - uVar5;
    iVar6 = 0;
    if (uVar4 - uVar5 == 0) goto LAB_004ed028;
    iVar6 = 0;
LAB_004ecf34:
    uVar5 = *(uint *)(param_1 + 0x80);
    if (uVar5 != 0) goto LAB_004ecfb0;
  }
  iVar1 = *(int *)(param_1 + 0x84);
LAB_004ecf44:
  if (iVar1 != 0) {
    nvAssertFailedNoLog("pRefcnt->count == 0","src/lib/ref_count.c",0x20b);
  }
  return iVar6;
}


// ===== 004ed0e0 refcntConstruct_IMPL =====

undefined8
refcntConstruct_IMPL
          (long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 uVar1;
  
  *(undefined8 *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x58) = param_3;
  *(undefined8 *)(param_1 + 0x88) = param_4;
  *(undefined8 *)(param_1 + 0x90) = param_5;
  *(undefined8 *)(param_1 + 0x80) = 0;
  uVar1 = portMemAllocatorGetGlobalNonPaged();
  mapInit_IMPL(param_1 + 0x60,uVar1,4);
  return 0;
}


// ===== 004ed130 refcntDestruct_IMPL =====

void refcntDestruct_IMPL(long param_1)

{
  mapDestroy_IMPL(param_1 + 0x60);
  return;
}


// ===== 004ed140 refcntReleaseReferences_IMPL =====

void refcntReleaseReferences_IMPL(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  undefined1 local_9;
  
  _refcntReleaseReferences(param_1,param_2,param_3,0,&local_9);
  return;
}


// ===== 004ed160 refcntReset_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int refcntReset_IMPL(long param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_88 [5];
  char local_59;
  undefined8 local_58 [5];
  
  iVar3 = 0;
  uVar4 = mapFindLEQ_IMPL(param_1 + 0x60,0xffffffffffffffff);
  uVar5 = mapFindGEQ_IMPL(param_1 + 0x60,0);
  mapIterRange_IMPL(local_58,param_1 + 0x60,uVar5,uVar4);
  do {
    cVar1 = mapIterNext_IMPL(local_58);
    while( true ) {
      if (cVar1 == '\0') {
        if (*(int *)(param_1 + 0x84) == 0) {
          if ((param_2 != '\0') && (iVar3 == 0)) {
            if ((*(code **)(param_1 + 0x88) == (code *)0x0) ||
               (iVar3 = (**(code **)(param_1 + 0x88))
                                  (param_1,*(undefined8 *)(param_1 + 0x50),
                                   *(undefined4 *)(param_1 + 0x80),0), iVar3 == 0)) {
              *(undefined4 *)(param_1 + 0x80) = 0;
              iVar3 = 0;
            }
            else {
              nvDbg_Printf("src/lib/ref_count.c",0x182,"refcntReset_IMPL",4,
                           "NVRM: Failed to reset setting (status: 0x%x)\n",iVar3);
              *(undefined4 *)(param_1 + 0x80) = 3;
            }
          }
        }
        else {
          iVar3 = 0x40;
          nvAssertFailedNoLog("pRefcnt->count == 0","src/lib/ref_count.c",0x176);
          *(undefined4 *)(param_1 + 0x80) = 3;
        }
        return iVar3;
      }
      uVar4 = mapKey_IMPL(param_1 + 0x60,local_58[0]);
      iVar2 = _refcntReleaseReferences(param_1,uVar4,1,1,&local_59);
      if (local_59 != '\0') {
        uVar5 = mapFindLEQ_IMPL(param_1 + 0x60,0xffffffffffffffff);
        uVar6 = mapFindGEQ_IMPL(param_1 + 0x60,uVar4);
        mapIterRange_IMPL(local_88,param_1 + 0x60,uVar6,uVar5);
        local_58[0] = local_88[0];
      }
      if (iVar2 != 0) {
        if (iVar3 == 0) {
          iVar3 = iVar2;
        }
        nvDbg_Printf("src/lib/ref_count.c",0x167,"refcntReset_IMPL",3,
                     "NVRM: Failed to release references on behalf of requester 0x%016llx prior to a forced reset (status: 0x%08x)\n"
                     ,uVar4,iVar2);
      }
      if (*(code **)(param_1 + 0x90) == (code *)0x0) break;
      (**(code **)(param_1 + 0x90))(param_1,*(undefined8 *)(param_1 + 0x50),uVar4);
      cVar1 = mapIterNext_IMPL(local_58);
    }
  } while( true );
}


// ===== 004ed3c0 refcntRequestReference_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int refcntRequestReference_IMPL(long param_1,undefined8 param_2,int param_3,char param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined8 uVar4;
  undefined4 local_2c;
  
  if (1 < param_3 - 1U) {
    return 0x1f;
  }
  iVar1 = *(int *)(param_1 + 0x80);
  if (iVar1 == 3) {
    return 0x40;
  }
  if ((*(int *)(param_1 + 0x84) != 0) && (iVar1 != param_3)) {
    if (param_4 == '\0') {
      nvDbg_Printf("src/lib/ref_count.c",0xa8,"refcntRequestReference_IMPL",1,
                   "NVRM: Cannot enter requested state %d (current state: %d, count: %d)\n",param_3,
                   iVar1,*(int *)(param_1 + 0x84));
      return 99;
    }
    iVar1 = refcntReset_IMPL(param_1,0);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  piVar3 = (int *)mapFind_IMPL(param_1 + 0x60,param_2);
  iVar1 = *(int *)(param_1 + 0x84);
  if (piVar3 == (int *)0x0) {
    local_2c = 0;
    if (((iVar1 == 0) && (*(code **)(param_1 + 0x88) != (code *)0x0)) &&
       (iVar1 = (**(code **)(param_1 + 0x88))
                          (param_1,*(undefined8 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x80),
                           param_3), iVar1 != 0)) {
      nvDbg_Printf("src/lib/ref_count.c",0xd7,"refcntRequestReference_IMPL",4,
                   "NVRM: Failed to enter state %d (current state: %d, status: 0x%08x)\n",param_3,
                   *(undefined4 *)(param_1 + 0x80),iVar1);
      return iVar1;
    }
    piVar3 = (int *)mapInsertValue_IMPL(param_1 + 0x60,param_2,&local_2c);
    if (piVar3 == (int *)0x0) {
      nvDbg_Printf("src/lib/ref_count.c",0xe5,"refcntRequestReference_IMPL",4,
                   "NVRM: Failed to insert entry for requester 0x%016llx (status: 0x%08x)\n",param_2
                   ,0x51);
      *(undefined4 *)(param_1 + 0x80) = 3;
      return 0x51;
    }
LAB_004ed48e:
    iVar2 = *piVar3;
LAB_004ed491:
    *piVar3 = iVar2 + 1;
    *(int *)(param_1 + 0x80) = param_3;
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + 1;
    iVar1 = 0;
    if (*piVar3 != 0) {
      return 0;
    }
  }
  else {
    iVar2 = *piVar3;
    if ((iVar2 == 0) || (*(char *)(param_1 + 0x48) != '\0')) {
      if ((iVar1 != 0) || (*(code **)(param_1 + 0x88) == (code *)0x0)) goto LAB_004ed491;
      uVar4 = (**(code **)(param_1 + 0x88))
                        (param_1,*(undefined8 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x80),
                         param_3);
      iVar1 = (int)uVar4;
      if (iVar1 == 0) goto LAB_004ed48e;
      nvDbg_Printf("src/lib/ref_count.c",0xd7,"refcntRequestReference_IMPL",4,
                   "NVRM: Failed to enter state %d (current state: %d, status: 0x%08x)\n",param_3,
                   *(undefined4 *)(param_1 + 0x80),uVar4);
      iVar2 = *piVar3;
    }
    else {
      nvDbg_Printf("src/lib/ref_count.c",0xbe,"refcntRequestReference_IMPL",2,
                   "NVRM: Requester 0x%016llx already has a reference to this setting (current state: %d, count: %d)\n"
                   ,param_2,*(undefined4 *)(param_1 + 0x80),iVar1);
      iVar1 = 0x16;
      iVar2 = *piVar3;
    }
    if (iVar2 != 0) {
      return iVar1;
    }
  }
  mapRemove_IMPL(param_1 + 0x60,piVar3);
  return iVar1;
}


// ===== 004ed6c0 huft_build =====

undefined1
huft_build(byte *param_1,uint param_2,uint param_3,long param_4,long param_5,long *param_6,
          uint *param_7)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  ulong uVar9;
  long lVar10;
  undefined8 *puVar11;
  byte bVar12;
  byte bVar13;
  long lVar14;
  uint *puVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  ulong uVar20;
  char cVar21;
  ulong uVar22;
  ulong uVar23;
  int iVar24;
  ulong uVar25;
  uint uVar26;
  undefined8 unaff_R13;
  long unaff_R14;
  undefined6 uVar27;
  ushort *local_3f8;
  char local_3e0;
  uint local_3cc;
  ushort local_3c0;
  uint local_3b4;
  long *local_390;
  uint local_380 [34];
  long local_2f8 [16];
  ushort local_278 [292];
  
  portMemSet(local_380,0,0x44);
  uVar20 = (ulong)param_2 & 0xffff;
  pbVar8 = param_1;
  do {
    bVar12 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    local_380[bVar12] = local_380[bVar12] + 1;
  } while (pbVar8 != param_1 + uVar20);
  if (local_380[0] == (param_2 & 0xffff)) {
    *param_6 = 0;
    *param_7 = 0;
    return 0;
  }
  lVar14 = 1;
  do {
    if (local_380[lVar14] != 0) {
      uVar7 = (uint)lVar14;
      uVar6 = 1 << ((byte)lVar14 & 0x1f);
      goto LAB_004ed78c;
    }
    lVar14 = lVar14 + 1;
  } while (lVar14 != 0x11);
  uVar6 = 0x20000;
  uVar7 = 0x11;
LAB_004ed78c:
  puVar15 = local_380 + 0x10;
  uVar26 = *param_7;
  if (*param_7 < uVar7) {
    uVar26 = uVar7;
  }
  local_3cc = 0x10;
  do {
    if (*puVar15 != 0) {
      local_3c0 = (ushort)local_3cc;
      if (local_3cc < uVar26) {
        uVar26 = local_3cc;
      }
      goto LAB_004ed822;
    }
    puVar15 = puVar15 + -1;
    local_3cc = local_3cc - 1;
  } while (local_380 != puVar15);
  local_3cc = 0;
  local_3c0 = 0;
  uVar26 = 0;
LAB_004ed822:
  *param_7 = uVar26;
  if (uVar7 < local_3cc) {
    puVar15 = local_380 + uVar7;
    do {
      uVar3 = *puVar15;
      if ((int)(uVar6 - uVar3) < 0) goto LAB_004ed85f;
      puVar15 = puVar15 + 1;
      uVar6 = (uVar6 - uVar3) * 2;
    } while (local_380 + (ulong)((local_3cc - uVar7) - 1) + (ulong)uVar7 + 1 != puVar15);
  }
  uVar3 = local_380[local_3cc];
  if ((int)(uVar6 - uVar3) < 0) {
LAB_004ed85f:
    uVar4 = 2;
  }
  else {
    local_380[local_3cc] = uVar6;
    local_380[0x12] = 0;
    if (local_3c0 != 1) {
      iVar16 = 0;
      lVar14 = 0;
      do {
        iVar16 = iVar16 + *(int *)((long)local_380 + lVar14 + 4);
        *(int *)((long)local_380 + lVar14 + 0x4c) = iVar16;
        lVar14 = lVar14 + 4;
      } while ((ulong)(local_3c0 - 1 & 0xffff) << 2 != lVar14);
    }
    uVar9 = 0;
    do {
      bVar12 = param_1[uVar9];
      if (bVar12 != 0) {
        uVar19 = local_380[(ulong)bVar12 + 0x11];
        local_278[uVar19] = (ushort)uVar9;
        local_380[(ulong)bVar12 + 0x11] = uVar19 + 1;
      }
      uVar9 = uVar9 + 1;
    } while (uVar20 != uVar9);
    local_380[0x11] = 0;
    local_2f8[0] = 0;
    if ((int)uVar7 <= (int)local_3cc) {
      uVar18 = 0;
      uVar19 = 0;
      iVar16 = -uVar26;
      local_3f8 = local_278;
      uVar17 = 0xffffffff;
      uVar9 = (ulong)uVar7;
      lVar14 = 0;
      local_390 = param_6;
LAB_004ed98a:
      local_3b4 = local_380[uVar9];
      if (local_3b4 != 0) {
        iVar24 = (int)uVar9;
        uVar25 = (ulong)uVar17;
LAB_004ed9d5:
        local_3e0 = (char)uVar9;
        if ((int)(uVar26 + iVar16) < iVar24) {
          uVar22 = (ulong)((int)uVar25 + 1);
          uVar23 = uVar22;
          iVar16 = uVar26 + iVar16;
          do {
            bVar12 = local_3e0 - (char)iVar16;
            uVar18 = 1 << (bVar12 & 0x1f);
            bVar13 = bVar12;
            if (local_3b4 < uVar18) {
              uVar7 = local_3cc - iVar16;
              if (uVar26 < local_3cc - iVar16) {
                uVar7 = uVar26;
              }
              uVar17 = (iVar24 + 1) - iVar16;
              iVar5 = uVar18 - local_3b4;
              puVar15 = local_380 + uVar9;
              if (uVar17 < uVar7) {
                do {
                  puVar1 = puVar15 + 1;
                  puVar15 = puVar15 + 1;
                  if ((uint)(iVar5 * 2) <= *puVar1) break;
                  uVar17 = uVar17 + 1;
                  iVar5 = iVar5 * 2 - *puVar1;
                } while (uVar17 != uVar7);
              }
              bVar13 = (byte)uVar17;
              uVar18 = 1 << (bVar13 & 0x1f);
            }
            lVar10 = portMemAllocNonPaged((ulong)(uVar18 + 1) << 4);
            if (lVar10 == 0) goto LAB_004ed85f;
            lVar14 = lVar10 + 0x10;
            hufts = uVar18 + 1 + hufts;
            *local_390 = lVar14;
            local_2f8[uVar23] = lVar14;
            *(undefined8 *)(lVar10 + 8) = 0;
            if ((int)uVar23 != 0) {
              local_380[uVar23 + 0x11] = uVar19 & 0xffff;
              puVar11 = (undefined8 *)
                        ((ulong)(uint)((int)(uVar19 & 0xffff) >>
                                      ((char)iVar16 - (char)uVar26 & 0x1fU)) * 0x10 +
                        local_2f8[(long)(int)uVar25 + (uVar23 - uVar22)]);
              puVar11[1] = lVar14;
              unaff_R13 = CONCAT62((int6)((ulong)unaff_R13 >> 0x10),
                                   CONCAT11((char)uVar26,bVar13 + 0x10));
              *puVar11 = unaff_R13;
              unaff_R14 = lVar14;
            }
            local_390 = (long *)(lVar10 + 8);
            if (iVar24 <= (int)(uVar26 + iVar16)) goto LAB_004edbd8;
            uVar23 = uVar23 + 1;
            iVar16 = uVar26 + iVar16;
          } while( true );
        }
        bVar12 = local_3e0 - (char)iVar16;
        goto LAB_004edbf2;
      }
      goto LAB_004edd0f;
    }
LAB_004edd27:
    uVar4 = local_3c0 != 1 && uVar6 != uVar3;
  }
  return uVar4;
LAB_004edbd8:
  uVar19 = uVar19 & 0xffff;
  uVar25 = uVar23 & 0xffffffff;
LAB_004edbf2:
  cVar21 = 'c';
  if (local_3f8 < local_278 + uVar20) {
    uVar2 = *local_3f8;
    local_3f8 = local_3f8 + 1;
    uVar27 = (undefined6)((ulong)unaff_R14 >> 0x10);
    if (uVar2 < param_3) {
      unaff_R14 = CONCAT62(uVar27,uVar2);
      cVar21 = (uVar2 != 0x100) + '\x0f';
    }
    else {
      uVar23 = (ulong)(uVar2 - param_3);
      cVar21 = *(char *)(param_5 + uVar23 * 2);
      unaff_R14 = CONCAT62(uVar27,*(undefined2 *)(param_4 + uVar23 * 2));
    }
  }
  bVar13 = (byte)iVar16;
  uVar7 = (int)(uVar19 & 0xffff) >> (bVar13 & 0x1f);
  if (uVar7 < uVar18) {
    do {
      unaff_R13 = CONCAT62((int6)((ulong)unaff_R13 >> 0x10),CONCAT11(local_3e0 - bVar13,cVar21));
      uVar23 = (ulong)uVar7;
      uVar7 = uVar7 + (1 << (bVar12 & 0x1f));
      *(undefined8 *)(lVar14 + uVar23 * 0x10) = unaff_R13;
      *(long *)(lVar14 + 8 + uVar23 * 0x10) = unaff_R14;
    } while (uVar7 < uVar18);
  }
  uVar17 = 1 << (local_3e0 - 1U & 0x1f);
  uVar7 = uVar19 & 0xffff & uVar17;
  while (uVar7 != 0) {
    uVar19 = uVar19 ^ uVar17;
    uVar17 = uVar17 >> 1;
    uVar7 = uVar19 & 0xffff & uVar17;
  }
  uVar19 = uVar19 ^ uVar17;
  if (((1 << (bVar13 & 0x1f)) - 1U & uVar19 & 0xffff) != local_380[(long)(int)uVar25 + 0x11]) {
    uVar23 = (long)((int)uVar25 + -1);
    do {
      uVar25 = uVar23;
      iVar16 = iVar16 - uVar26;
      uVar23 = uVar25 - 1;
    } while (((1 << ((byte)iVar16 & 0x1f)) - 1U & uVar19 & 0xffff) != local_380[uVar25 + 0x11]);
    uVar25 = uVar25 & 0xffffffff;
  }
  local_3b4 = local_3b4 - 1;
  if (local_3b4 == 0) goto code_r0x004edcf6;
  goto LAB_004ed9d5;
code_r0x004edcf6:
  uVar17 = (uint)uVar25;
LAB_004edd0f:
  uVar9 = uVar9 + 1;
  if ((int)local_3cc < (int)uVar9) goto LAB_004edd27;
  goto LAB_004ed98a;
}


// ===== 004eddf0 flush_window =====

void flush_window(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  
  iVar8 = *(int *)(param_1 + 0x3c);
  if (iVar8 != 0) {
    uVar2 = *(uint *)(param_1 + 0x34);
    *(int *)(param_1 + 0x44) = iVar8;
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar9 = (ulong)uVar3;
    if ((uVar2 == 0xffffffff) && (*(int *)(param_1 + 0x38) == -1)) {
      portMemCopy(uVar9 + *(long *)(param_1 + 0x20),iVar8,*(undefined8 *)(param_1 + 0x48),iVar8);
      iVar7 = *(int *)(param_1 + 0x3c);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + iVar7;
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + iVar7;
      iVar7 = iVar7 + *(int *)(param_1 + 0x30);
    }
    else {
      iVar7 = iVar8 + uVar3;
      uVar1 = iVar7 - 1;
      if ((uVar2 <= uVar1) && (uVar4 = *(uint *)(param_1 + 0x38), uVar3 <= uVar4)) {
        lVar6 = *(long *)(param_1 + 0x48);
        lVar5 = *(long *)(param_1 + 0x20);
        if (uVar2 < uVar3) {
          lVar5 = lVar5 + (uVar9 - uVar2);
          if (uVar4 < uVar1) {
            iVar8 = (uVar4 + 1) - uVar3;
            portMemCopy(lVar5,iVar8,lVar6,iVar8);
            iVar8 = *(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x30);
            iVar7 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x3c);
            *(int *)(param_1 + 0x40) = iVar8 + 1 + *(int *)(param_1 + 0x40);
            *(int *)(param_1 + 0x60) = iVar8 + 1 + *(int *)(param_1 + 0x60);
          }
          else {
            portMemCopy(lVar5,iVar8,lVar6,iVar8);
            iVar7 = *(int *)(param_1 + 0x3c);
            *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + iVar7;
            *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + iVar7;
            iVar7 = iVar7 + *(int *)(param_1 + 0x30);
          }
        }
        else {
          lVar6 = (uVar2 - uVar9) + lVar6;
          if (uVar4 < uVar1) {
            iVar8 = (uVar4 + 1) - uVar2;
            portMemCopy(lVar5,iVar8,lVar6,iVar8);
            iVar7 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x3c);
            *(int *)(param_1 + 0x40) =
                 (*(int *)(param_1 + 0x40) + 1 + *(int *)(param_1 + 0x38)) -
                 *(int *)(param_1 + 0x30);
            *(int *)(param_1 + 0x60) =
                 (*(int *)(param_1 + 0x38) + *(int *)(param_1 + 0x60) + 1) -
                 *(int *)(param_1 + 0x34);
          }
          else {
            portMemCopy(lVar5,iVar7 - uVar2,lVar6,iVar7 - uVar2);
            iVar7 = *(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x3c);
            iVar8 = iVar7 - *(int *)(param_1 + 0x34);
            *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + iVar8;
            *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + iVar8;
          }
        }
      }
    }
    *(int *)(param_1 + 0x30) = iVar7;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    return;
  }
  return;
}


// ===== 004ee000 utilGzGetData =====

int utilGzGetData(long param_1,uint param_2,uint param_3,uint param_4,long param_5)

{
  long lVar1;
  uint *puVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  ulong uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  undefined8 *puVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  byte bVar19;
  int iVar20;
  uint uVar21;
  ushort uVar22;
  uint uVar23;
  ulong uVar24;
  uint uVar25;
  uint uVar26;
  byte *pbVar27;
  byte *local_228;
  uint local_220;
  uint local_21c;
  long local_208;
  long local_200;
  uint local_1f8;
  uint local_1f4;
  long local_1f0;
  long local_1e8;
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  undefined8 local_1d4;
  uint local_1cc;
  uint uStack_1c8;
  uint uStack_1c4;
  long local_1c0;
  uint local_1b8;
  uint local_1b4;
  uint local_1b0;
  int local_1ac;
  int local_1a8;
  undefined4 local_1a0;
  uint local_19c;
  uint local_198;
  uint local_194;
  byte *local_190;
  uint local_188;
  uint local_184;
  int local_180;
  uint local_17c;
  undefined8 local_178 [3];
  undefined4 local_160;
  undefined2 local_15c;
  undefined8 local_e8;
  undefined8 local_e0 [13];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  
  lVar6 = portMemAllocNonPaged(0x8000);
  if (lVar6 == 0) {
    nvDbg_Printf("src/lib/zlib/inflate.c",0x4ca,"utilGzGetData",4,
                 "NVRM: utilGzGetData: failed to allocate slide window\n");
    return 0;
  }
  portMemSet(&local_208,0,0x90);
  portMemSet(lVar6,0,0x8000);
  local_1e8 = 0;
  local_1ac = 1;
  local_1d4 = 0xffffffffffffffff;
  local_1f0 = param_1;
  local_1e0 = param_2;
  local_1c0 = lVar6;
  if ((param_5 == 0) || (param_2 <= param_3)) {
LAB_004ee2c7:
    iVar20 = 0;
LAB_004ee2ca:
    lVar17 = local_208;
    if (local_208 != 0) {
      do {
        lVar1 = lVar17 + -0x10;
        lVar17 = *(long *)(lVar17 + -8);
        portMemFree(lVar1);
      } while (lVar17 != 0);
      local_208 = 0;
    }
    lVar17 = local_200;
    if (local_200 != 0) {
      do {
        lVar1 = lVar17 + -0x10;
        lVar17 = *(long *)(lVar17 + -8);
        portMemFree(lVar1);
      } while (lVar17 != 0);
      local_200 = 0;
    }
    portMemFree(lVar6);
    return iVar20;
  }
  local_1a8 = 0;
  if (local_1d8 != 0) {
    iVar20 = (local_1d8 + 0x7fff & 0xffff8000) - 0x8000;
    if (param_3 < uStack_1c8 + iVar20) {
      lVar17 = local_208;
      if (local_208 != 0) {
        do {
          lVar1 = lVar17 + -0x10;
          lVar17 = *(long *)(lVar17 + -8);
          portMemFree(lVar1);
        } while (lVar17 != 0);
        local_208 = 0;
      }
      lVar17 = local_200;
      if (local_200 != 0) {
        do {
          lVar1 = lVar17 + -0x10;
          lVar17 = *(long *)(lVar17 + -8);
          portMemFree(lVar1);
        } while (lVar17 != 0);
        local_200 = 0;
      }
      lVar1 = local_1c0;
      uVar5 = local_1e0;
      lVar17 = local_1f0;
      portMemSet(&local_208,0,0x90);
      portMemSet(lVar1,0,0x8000);
      local_1f0 = lVar17;
      local_1e0 = uVar5;
      local_1c0 = lVar1;
    }
    else {
      uStack_1c8 = param_3 - iVar20;
      if (uStack_1c8 < uStack_1c4) {
        uVar5 = iVar20 + uStack_1c4;
        uVar18 = uVar5 - param_3;
        if (param_4 <= uVar18) {
          portMemCopy(param_5,param_4,(ulong)uStack_1c8 + lVar6,param_4);
          uStack_1c8 = uStack_1c8 + param_4;
          local_1a8 = param_4 + local_1a8;
          iVar20 = local_1a8;
          goto LAB_004ee2ca;
        }
        portMemCopy(param_5,(ulong)uVar18,(ulong)uStack_1c8 + lVar6);
        local_1a8 = local_1a8 + uVar18;
        param_5 = param_5 + (ulong)uVar18;
        goto LAB_004ee0d0;
      }
    }
  }
  local_1ac = 1;
  uVar5 = param_3;
LAB_004ee0d0:
  local_1d4 = CONCAT44((param_3 + param_4) - 1,uVar5);
  uStack_1c8 = 0;
  uStack_1c4 = 0;
  local_1e8 = param_5;
  uVar5 = local_1b8;
joined_r0x004ee10c:
  local_1b8 = uVar5;
  iVar20 = local_1a8;
  if (local_1d8 < param_3 + param_4) {
    if (local_1ac != 1) goto LAB_004ee139;
    if (local_1b4 != 0) {
      uVar12 = local_1b4 - 1;
      uVar18 = uVar5 >> 1;
      local_1b0 = uVar5 & 1;
      uVar5 = uVar12;
      if (uVar12 < 2) {
        uVar14 = (ulong)local_1dc;
        local_1dc = local_1dc + 1;
        uVar5 = local_1b4 + 7;
        uVar18 = uVar18 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)uVar12 & 0x1f);
      }
      local_1b4 = uVar5 - 2;
      local_1b8 = uVar18 >> 2;
      uVar18 = uVar18 & 3;
      if (uVar18 == 1) goto LAB_004ee5f0;
      if (uVar18 == 2) {
        if (local_1b4 < 5) {
          uVar14 = (ulong)local_1dc;
          uVar18 = uVar5 + 1;
          local_1dc = local_1dc + 1;
          uVar12 = local_1b8 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)local_1b4 & 0x1f);
          uVar16 = uVar5 + 6;
        }
        else {
          uVar18 = uVar5 - 7;
          uVar12 = local_1b8;
          uVar16 = local_1b4;
        }
        uVar5 = uVar12 >> 5;
        local_21c = (uint)(ushort)(((ushort)uVar12 & 0x1f) + 0x101);
        uVar12 = uVar18;
        if (uVar18 < 5) goto LAB_004ee9b7;
        goto LAB_004ee9d5;
      }
      if (uVar18 == 0) {
        uVar18 = local_1b4 & 0xfffffff8;
        uVar5 = local_1b8 >> ((byte)local_1b4 & 7);
        if (uVar18 < 0x10) goto LAB_004ee4ea;
        uVar12 = uVar18 - 0x10;
        uVar16 = uVar5 & 0xffff;
        uVar5 = uVar5 >> 0x10;
        if (uVar12 < 0x10) goto LAB_004ee53d;
LAB_004ee585:
        if ((uVar5 ^ 0xffff) == uVar16) {
          local_1b4 = uVar12 - 0x10;
          local_1b8 = 0;
          local_17c = uVar16;
LAB_004ee5b1:
          local_194 = local_1cc;
          local_1ac = 0;
          local_188 = local_1b8;
          local_184 = local_1b4;
          goto LAB_004ee139;
        }
      }
      goto LAB_004ee2c7;
    }
    uVar14 = (ulong)local_1dc;
    local_1dc = local_1dc + 1;
    local_1b4 = 5;
    uVar18 = *(byte *)(local_1f0 + uVar14) | uVar5;
    local_1b0 = uVar18 & 1;
    local_1b8 = uVar18 >> 3;
    uVar18 = uVar18 >> 1 & 3;
    if (uVar18 == 1) {
LAB_004ee5f0:
      puVar15 = &local_e8;
      puVar7 = local_178;
      do {
        *puVar7 = 0x808080808080808;
        puVar8 = puVar7 + 2;
        puVar7[1] = 0x808080808080808;
        puVar7 = puVar8;
      } while (puVar8 != puVar15);
      if (((int)&local_78 - (int)puVar15 & 8U) == 0) goto LAB_004ee650;
      local_e8 = 0x909090909090909;
      for (puVar15 = local_e0; puVar15 != &local_78; puVar15 = puVar15 + 2) {
LAB_004ee650:
        *puVar15 = 0x909090909090909;
        puVar15[1] = 0x909090909090909;
      }
      local_78 = 0x707070707070707;
      local_70 = 0x707070707070707;
      local_68 = 0x707070707070707;
      local_60 = 0x808080808080808;
      local_1f8 = 7;
      iVar20 = huft_build(local_178,0x120,0x101,cplens,cplext,&local_208,&local_1f8);
      if (iVar20 != 0) goto LAB_004ee2c7;
      local_15c = 0x505;
      local_178[0] = 0x505050505050505;
      local_178[1] = 0x505050505050505;
      local_178[2] = 0x505050505050505;
      local_160 = 0x5050505;
      local_1f4 = 5;
      iVar20 = huft_build(local_178,0x1e,0,cpdist,cpdext,&local_200,&local_1f4);
      lVar17 = local_208;
      if (iVar20 != 2) goto LAB_004ee5b1;
      while (lVar17 != 0) {
        lVar1 = *(long *)(lVar17 + -8);
        portMemFree(lVar17 + -0x10);
        lVar17 = lVar1;
      }
      iVar20 = 0;
    }
    else {
      if (uVar18 == 2) {
        uVar5 = uVar5 >> 8;
        uVar16 = 5;
        local_21c = (uint)(ushort)(((ushort)local_1b8 & 0x1f) + 0x101);
        uVar12 = 0;
LAB_004ee9b7:
        uVar14 = (ulong)local_1dc;
        local_1dc = local_1dc + 1;
        uVar18 = uVar16 + 3;
        uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)uVar12 & 0x1f);
LAB_004ee9d5:
        uVar12 = uVar18 - 5;
        uVar16 = uVar5 >> 5;
        bVar19 = ((byte)uVar5 & 0x1f) + 1;
        if (uVar12 < 4) {
          uVar14 = (ulong)local_1dc;
          local_1dc = local_1dc + 1;
          bVar10 = (byte)uVar12;
          uVar12 = uVar18 + 3;
          uVar16 = uVar16 | (uint)*(byte *)(local_1f0 + uVar14) << (bVar10 & 0x1f);
        }
        if (((ushort)local_21c < 0x11f) && (bVar19 < 0x1f)) {
          uVar5 = uVar16 >> 4;
          uVar14 = 0;
          uVar12 = uVar12 - 4;
          uVar24 = (ulong)((uVar16 & 0xf) + 4);
          do {
            uVar18 = uVar5;
            if (uVar12 < 3) {
              uVar9 = (ulong)local_1dc;
              local_1dc = local_1dc + 1;
              bVar10 = (byte)uVar12;
              uVar12 = uVar12 + 8;
              uVar18 = uVar5 | (uint)*(byte *)(local_1f0 + uVar9) << (bVar10 & 0x1f);
            }
            puVar2 = &border + uVar14;
            uVar12 = uVar12 - 3;
            uVar5 = uVar18 >> 3;
            uVar14 = uVar14 + 1;
            *(byte *)((long)local_178 + (ulong)*puVar2) = (byte)uVar18 & 7;
          } while (uVar14 != uVar24);
          if ((uVar16 & 0xf) != 0xf) {
            do {
              puVar2 = &border + uVar24;
              uVar24 = uVar24 + 1;
              *(undefined1 *)((long)local_178 + (ulong)*puVar2) = 0;
            } while ((int)uVar24 != 0x13);
          }
          local_1f8 = 7;
          iVar20 = huft_build(local_178,0x13,0x13,0,0,&local_208,&local_1f8);
          if (iVar20 == 0) {
            uVar22 = 0;
            uVar3 = *(ushort *)(mask_bits + (long)(int)local_1f8 * 2);
            uVar18 = 0;
            uVar16 = bVar19 + local_21c;
            do {
              for (; uVar12 < local_1f8; uVar12 = uVar12 + 8) {
                uVar14 = (ulong)local_1dc;
                local_1dc = local_1dc + 1;
                uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)uVar12 & 0x1f);
              }
              local_200 = (ulong)(uVar3 & uVar5) * 0x10 + local_208;
              uVar4 = *(ushort *)(local_200 + 8);
              uVar5 = uVar5 >> (*(byte *)(local_200 + 1) & 0x1f);
              uVar12 = uVar12 - *(byte *)(local_200 + 1);
              if (uVar4 < 0x10) {
                uVar14 = (ulong)uVar18;
                uVar18 = uVar18 + 1;
                *(char *)((long)local_178 + uVar14) = (char)uVar4;
                uVar22 = uVar4;
              }
              else {
                bVar10 = (byte)uVar12;
                if (uVar4 == 0x10) {
                  if (uVar12 < 2) {
                    uVar14 = (ulong)local_1dc;
                    local_1dc = local_1dc + 1;
                    uVar12 = uVar12 + 8;
                    uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + uVar14) << (bVar10 & 0x1f);
                  }
                  uVar25 = uVar18 + 3 + (uVar5 & 3);
                  if (uVar16 < uVar25) goto LAB_004ee2c7;
                  uVar5 = uVar5 >> 2;
                  uVar12 = uVar12 - 2;
                  do {
                    uVar14 = (ulong)uVar18;
                    uVar18 = uVar18 + 1;
                    *(char *)((long)local_178 + uVar14) = (char)uVar22;
                  } while (uVar25 != uVar18);
                }
                else if (uVar4 == 0x11) {
                  if (uVar12 < 3) {
                    uVar14 = (ulong)local_1dc;
                    local_1dc = local_1dc + 1;
                    uVar12 = uVar12 + 8;
                    uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + uVar14) << (bVar10 & 0x1f);
                  }
                  uVar25 = uVar18 + 3 + (uVar5 & 7);
                  if (uVar16 < uVar25) goto LAB_004ee2c7;
                  uVar5 = uVar5 >> 3;
                  uVar12 = uVar12 - 3;
                  do {
                    uVar14 = (ulong)uVar18;
                    uVar18 = uVar18 + 1;
                    *(undefined1 *)((long)local_178 + uVar14) = 0;
                  } while (uVar25 != uVar18);
                  uVar22 = 0;
                }
                else {
                  if (uVar12 < 7) {
                    uVar14 = (ulong)local_1dc;
                    local_1dc = local_1dc + 1;
                    uVar12 = uVar12 + 8;
                    uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + uVar14) << (bVar10 & 0x1f);
                  }
                  uVar25 = uVar18 + 0xb + (uVar5 & 0x7f);
                  if (uVar16 < uVar25) goto LAB_004ee2c7;
                  uVar5 = uVar5 >> 7;
                  uVar12 = uVar12 - 7;
                  do {
                    uVar14 = (ulong)uVar18;
                    uVar18 = uVar18 + 1;
                    *(undefined1 *)((long)local_178 + uVar14) = 0;
                  } while (uVar25 != uVar18);
                  uVar22 = 0;
                }
              }
              lVar17 = local_208;
            } while (uVar18 < uVar16);
            while (lVar17 != 0) {
              lVar1 = *(long *)(lVar17 + -8);
              portMemFree(lVar17 + -0x10);
              lVar17 = lVar1;
            }
            local_1f8 = 9;
            local_1b8 = uVar5;
            local_1b4 = uVar12;
            iVar20 = huft_build(local_178,local_21c,0x101,cplens,cplext,&local_208,&local_1f8);
            if (iVar20 == 0) {
              local_1f4 = 6;
              iVar20 = huft_build((ulong)(ushort)local_21c + (long)local_178,bVar19,0,cpdist,cpdext,
                                  &local_200,&local_1f4);
              if (iVar20 == 0) goto LAB_004ee5b1;
              lVar17 = local_208;
              if (iVar20 == 1) {
                nvDbg_Printf("src/lib/zlib/inflate.c",0x3c6,"dynamic_huft_build",4,
                             "NVRM: dload, incomplete distance tree\n");
                lVar1 = local_200;
                while (lVar17 = local_208, lVar1 != 0) {
                  lVar17 = lVar1 + -0x10;
                  lVar1 = *(long *)(lVar1 + -8);
                  portMemFree(lVar17);
                }
              }
              while (lVar17 != 0) {
                lVar1 = *(long *)(lVar17 + -8);
                portMemFree(lVar17 + -0x10);
                lVar17 = lVar1;
              }
            }
            else {
              if (iVar20 != 1) goto LAB_004ee5e0;
              nvDbg_Printf("src/lib/zlib/inflate.c",0x3bd,"dynamic_huft_build",4,
                           "NVRM: dload, incomplete literal tree\n");
              lVar17 = local_208;
              while (lVar17 != 0) {
                lVar1 = lVar17 + -0x10;
                lVar17 = *(long *)(lVar17 + -8);
                portMemFree(lVar1);
              }
            }
          }
          else {
            lVar17 = local_208;
            if (iVar20 == 1) {
              while (lVar17 != 0) {
                lVar1 = *(long *)(lVar17 + -8);
                portMemFree(lVar17 + -0x10);
                lVar17 = lVar1;
              }
            }
          }
        }
        goto LAB_004ee2c7;
      }
      if (uVar18 == 0) {
        uVar5 = uVar5 >> 8;
        uVar18 = 0;
LAB_004ee4ea:
        uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + (ulong)local_1dc) << ((byte)uVar18 & 0x1f);
        uVar12 = local_1dc + 1;
        if (uVar18 != 8) {
          uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + (ulong)(local_1dc + 1)) << 8;
          uVar12 = local_1dc + 2;
        }
        local_1dc = uVar12;
        uVar16 = uVar5 & 0xffff;
        uVar5 = uVar5 >> 0x10;
        uVar18 = 0x10;
        uVar12 = 0;
LAB_004ee53d:
        uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + (ulong)local_1dc) << ((byte)uVar12 & 0x1f);
        uVar25 = local_1dc + 1;
        if (uVar12 != 8) {
          uVar5 = uVar5 | (uint)*(byte *)(local_1f0 + (ulong)(local_1dc + 1)) << 8;
          uVar25 = local_1dc + 2;
        }
        local_1dc = uVar25;
        uVar12 = uVar12 + (0x20 - uVar18);
        goto LAB_004ee585;
      }
LAB_004ee5e0:
      iVar20 = 0;
    }
  }
  goto LAB_004ee2ca;
LAB_004ee139:
  uVar5 = local_194;
  uVar18 = local_188;
  uVar12 = local_17c;
  uVar16 = local_184;
  if (local_17c == 0) {
    uVar14 = (ulong)(int)local_1f8;
    uVar3 = *(ushort *)(mask_bits + uVar14 * 2);
    local_220 = local_19c;
    uVar22 = *(ushort *)(mask_bits + (long)(int)local_1f4 * 2);
    uVar18 = local_184;
    uVar12 = local_198;
    uVar16 = local_188;
    if (local_180 == 1) {
      local_228 = local_190;
      goto LAB_004ee97b;
    }
    do {
      for (; uVar18 < (uint)uVar14; uVar18 = uVar18 + 8) {
LAB_004ee214:
        uVar24 = (ulong)local_1dc;
        local_1dc = local_1dc + 1;
        uVar16 = uVar16 | (uint)*(byte *)(local_1f0 + uVar24) << ((byte)uVar18 & 0x1f);
      }
      while( true ) {
        pbVar27 = (byte *)((ulong)(uVar3 & uVar16) * 0x10 + local_208);
        uVar23 = (uint)*pbVar27;
        uVar25 = uVar18;
        iVar20 = 0;
        if (0x10 < *pbVar27) {
          do {
            if (uVar23 == 99) goto LAB_004ee2ca;
            bVar19 = pbVar27[1];
            uVar21 = uVar23 - 0x10;
            uVar25 = uVar18 - bVar19;
            uVar16 = uVar16 >> (bVar19 & 0x1f);
            uVar26 = uVar25;
            if (uVar25 < uVar21) {
              do {
                uVar14 = (ulong)local_1dc;
                local_1dc = local_1dc + 1;
                uVar11 = uVar26 + 8;
                uVar16 = uVar16 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)uVar26 & 0x1f);
                uVar26 = uVar11;
              } while (uVar11 < uVar21);
              uVar25 = uVar25 + 8 + ((uVar23 - 0x11) + (bVar19 - uVar18) & 0xfffffff8);
            }
            pbVar27 = (byte *)((ulong)(*(ushort *)(mask_bits + (ulong)uVar21 * 2) & uVar16) * 0x10 +
                              *(long *)(pbVar27 + 8));
            uVar23 = (uint)*pbVar27;
            uVar18 = uVar25;
          } while (0x10 < uVar23);
        }
        bVar19 = pbVar27[1];
        uVar18 = uVar25 - bVar19;
        uVar16 = uVar16 >> (bVar19 & 0x1f);
        if (uVar23 != 0x10) break;
        *(char *)(local_1c0 + (ulong)uVar5) = (char)*(undefined2 *)(pbVar27 + 8);
        if (uVar5 == 0x7fff) {
          local_1cc = 0x8000;
          uStack_1c8 = 0;
          flush_window(&local_208);
          local_1a0 = 0x10;
          local_194 = 0;
          uVar5 = local_1b8;
          local_19c = local_220;
          local_198 = uVar12;
          local_190 = pbVar27;
          local_188 = uVar16;
          local_184 = uVar18;
          goto joined_r0x004ee10c;
        }
        uVar14 = (ulong)local_1f8;
        uVar5 = uVar5 + 1;
        if (uVar18 < local_1f8) goto LAB_004ee214;
      }
      if (uVar23 == 0xf) {
        local_19c = local_220;
        local_1a0 = 0xf;
        local_198 = uVar12;
        local_194 = uVar5;
        local_190 = pbVar27;
        local_188 = uVar16;
        local_184 = uVar18;
        goto LAB_004ee78a;
      }
      if (uVar18 < uVar23) {
        uVar12 = uVar18 + 8;
        uVar16 = uVar16 | (uint)*(byte *)(local_1f0 + (ulong)local_1dc) << ((byte)uVar18 & 0x1f);
        uVar18 = local_1dc + 1;
        if (uVar12 < uVar23) {
          uVar16 = uVar16 | (uint)*(byte *)(local_1f0 + (ulong)(local_1dc + 1)) <<
                            ((byte)uVar12 & 0x1f);
          uVar18 = local_1dc + 2;
        }
        local_1dc = uVar18;
        uVar18 = ((uVar23 - 1) + (bVar19 - uVar25) & 0xfffffff8) + uVar12;
      }
      uVar25 = uVar16 >> ((byte)uVar23 & 0x1f);
      for (uVar12 = uVar18 - uVar23; uVar12 < local_1f4; uVar12 = uVar12 + 8) {
        uVar14 = (ulong)local_1dc;
        local_1dc = local_1dc + 1;
        uVar25 = uVar25 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)uVar12 & 0x1f);
      }
      local_228 = (byte *)(local_200 + (ulong)(uVar22 & uVar25) * 0x10);
      uVar21 = (uint)*local_228;
      if (0x10 < *local_228) {
        do {
          if (uVar21 == 99) goto LAB_004ee2ca;
          bVar19 = local_228[1];
          uVar18 = uVar21 - 0x10;
          uVar26 = uVar12 - bVar19;
          uVar25 = uVar25 >> (bVar19 & 0x1f);
          uVar11 = uVar26;
          if (uVar26 < uVar18) {
            do {
              uVar14 = (ulong)local_1dc;
              local_1dc = local_1dc + 1;
              uVar13 = uVar11 + 8;
              uVar25 = uVar25 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)uVar11 & 0x1f);
              uVar11 = uVar13;
            } while (uVar13 < uVar18);
            uVar26 = uVar26 + 8 + ((uVar21 - 0x11) + (bVar19 - uVar12) & 0xfffffff8);
          }
          uVar12 = uVar26;
          local_228 = (byte *)((ulong)(*(ushort *)(mask_bits + (ulong)uVar18 * 2) & uVar25) * 0x10 +
                              *(long *)(local_228 + 8));
          uVar21 = (uint)*local_228;
        } while (0x10 < uVar21);
      }
      local_220 = (*(ushort *)(mask_bits + (ulong)uVar23 * 2) & uVar16) +
                  (uint)*(ushort *)(pbVar27 + 8);
      bVar19 = local_228[1];
      uVar18 = uVar12 - bVar19;
      uVar25 = uVar25 >> (bVar19 & 0x1f);
      if (uVar18 < uVar21) {
        uVar16 = uVar18 + 8;
        uVar25 = uVar25 | (uint)*(byte *)(local_1f0 + (ulong)local_1dc) << ((byte)uVar18 & 0x1f);
        uVar18 = local_1dc + 1;
        if (uVar16 < uVar21) {
          uVar25 = uVar25 | (uint)*(byte *)(local_1f0 + (ulong)(local_1dc + 1)) <<
                            ((byte)uVar16 & 0x1f);
          uVar18 = local_1dc + 2;
        }
        local_1dc = uVar18;
        uVar18 = uVar16 + ((uVar21 - 1) + (bVar19 - uVar12) & 0xfffffff8);
      }
      uVar18 = uVar18 - uVar21;
      uVar12 = (uVar5 - *(ushort *)(local_228 + 8)) -
               (*(ushort *)(mask_bits + (ulong)uVar21 * 2) & uVar25);
      uVar16 = uVar25 >> ((byte)uVar21 & 0x1f);
      do {
        uVar25 = uVar12 & 0x7fff;
        uVar12 = uVar5;
        if (uVar5 < uVar25) {
          uVar12 = uVar25;
        }
        uVar23 = 0x8000 - uVar12;
        if (local_220 < 0x8000 - uVar12) {
          uVar23 = local_220;
        }
        local_220 = local_220 - uVar23;
        uVar12 = uVar25 + uVar23;
        iVar20 = uVar5 - uVar25;
        do {
          uVar14 = (ulong)uVar25;
          uVar21 = uVar25 + iVar20;
          uVar25 = uVar25 + 1;
          *(undefined1 *)(local_1c0 + (ulong)uVar21) = *(undefined1 *)(local_1c0 + uVar14);
        } while (uVar25 != uVar12);
        uVar5 = uVar5 + uVar23;
        if (uVar5 == 0x8000) {
          local_1cc = 0x8000;
          uStack_1c8 = 0;
          flush_window(&local_208);
          local_180 = 1;
          local_1a0 = 0;
          local_194 = 0;
          uVar5 = local_1b8;
          local_19c = local_220;
          local_198 = uVar25;
          local_190 = local_228;
          local_188 = uVar16;
          local_184 = uVar18;
          goto joined_r0x004ee10c;
        }
LAB_004ee97b:
      } while (local_220 != 0);
      local_180 = 0;
      uVar14 = (ulong)local_1f8;
    } while( true );
  }
  do {
    uVar12 = uVar12 - 1;
    if (uVar16 < 8) {
      uVar14 = (ulong)local_1dc;
      local_1dc = local_1dc + 1;
      uVar18 = uVar18 | (uint)*(byte *)(local_1f0 + uVar14) << ((byte)uVar16 & 0x1f);
    }
    else {
      uVar16 = uVar16 - 8;
    }
    uVar25 = uVar5 + 1;
    *(char *)(local_1c0 + (ulong)uVar5) = (char)uVar18;
    uVar18 = uVar18 >> 8;
    if (uVar5 == 0x7fff) {
      local_1cc = 0x8000;
      flush_window(&local_208);
      local_194 = 0;
      local_188 = uVar18;
      local_184 = uVar16;
      local_17c = uVar12;
      uVar5 = local_1b8;
      if (uVar12 != 0) goto joined_r0x004ee10c;
      goto LAB_004ee78a;
    }
    uVar5 = uVar25;
  } while (uVar12 != 0);
  local_17c = 0;
  local_194 = uVar25;
  local_188 = uVar18;
  local_184 = uVar16;
LAB_004ee78a:
  local_1cc = local_194;
  local_1b8 = local_188;
  local_1b4 = local_184;
  portMemSet(&local_1a0,0,0x28);
  lVar17 = local_208;
  if (local_208 != 0) {
    do {
      lVar1 = lVar17 + -0x10;
      lVar17 = *(long *)(lVar17 + -8);
      portMemFree(lVar1);
    } while (lVar17 != 0);
    local_208 = 0;
  }
  lVar17 = local_200;
  if (local_200 != 0) {
    do {
      lVar1 = lVar17 + -0x10;
      lVar17 = *(long *)(lVar17 + -8);
      portMemFree(lVar1);
    } while (lVar17 != 0);
    local_200 = 0;
  }
  local_1ac = 1;
  uVar5 = local_1b8;
  if (local_1b0 != 0) {
    if (7 < local_1b4) {
      local_1dc = local_1dc - (local_1b4 >> 3);
      local_1b4 = local_1b4 & 7;
    }
    flush_window(&local_208);
    uVar5 = local_1b8;
  }
  goto joined_r0x004ee10c;
}


// ===== 004ef510 _rotateRight =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rotateRight(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_2 + 0x28);
  if (lVar1 == 0) {
    nvAssertFailedNoLog(&DAT_00da35f7,"src/libraries/containers/btree/btree.c",0x11e);
    *(long *)(param_2 + 0x28) = _DAT_00000030;
    if (_DAT_00000030 != 0) {
      *(long *)(_DAT_00000030 + 0x20) = param_2;
    }
    _DAT_00000020 = *(long *)(param_2 + 0x20);
    if (_DAT_00000020 == 0) {
      *param_1 = 0;
    }
    else if (*(long *)(_DAT_00000020 + 0x30) == param_2) {
      *(undefined8 *)(_DAT_00000020 + 0x30) = 0;
    }
    else {
      *(undefined8 *)(_DAT_00000020 + 0x28) = 0;
    }
    _DAT_00000030 = param_2;
    *(undefined8 *)(param_2 + 0x20) = 0;
    return;
  }
  lVar2 = *(long *)(lVar1 + 0x30);
  *(long *)(param_2 + 0x28) = lVar2;
  if (lVar2 != 0) {
    *(long *)(lVar2 + 0x20) = param_2;
  }
  lVar2 = *(long *)(param_2 + 0x20);
  *(long *)(lVar1 + 0x20) = lVar2;
  if (lVar2 != 0) {
    if (*(long *)(lVar2 + 0x30) != param_2) {
      *(long *)(lVar2 + 0x28) = lVar1;
      *(long *)(lVar1 + 0x30) = param_2;
      *(long *)(param_2 + 0x20) = lVar1;
      return;
    }
    *(long *)(lVar2 + 0x30) = lVar1;
    *(long *)(lVar1 + 0x30) = param_2;
    *(long *)(param_2 + 0x20) = lVar1;
    return;
  }
  *param_1 = lVar1;
  *(long *)(lVar1 + 0x30) = param_2;
  *(long *)(param_2 + 0x20) = lVar1;
  return;
}


// ===== 004ef600 _rotateLeft =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rotateLeft(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_2 + 0x30);
  if (lVar1 == 0) {
    nvAssertFailedNoLog(&DAT_00da35f7,"src/libraries/containers/btree/btree.c",0xf6);
    *(long *)(param_2 + 0x30) = _DAT_00000028;
    if (_DAT_00000028 != 0) {
      *(long *)(_DAT_00000028 + 0x20) = param_2;
    }
    _DAT_00000020 = *(long *)(param_2 + 0x20);
    if (_DAT_00000020 == 0) {
      *param_1 = 0;
    }
    else if (*(long *)(_DAT_00000020 + 0x28) == param_2) {
      *(undefined8 *)(_DAT_00000020 + 0x28) = 0;
    }
    else {
      *(undefined8 *)(_DAT_00000020 + 0x30) = 0;
    }
    _DAT_00000028 = param_2;
    *(undefined8 *)(param_2 + 0x20) = 0;
    return;
  }
  lVar2 = *(long *)(lVar1 + 0x28);
  *(long *)(param_2 + 0x30) = lVar2;
  if (lVar2 != 0) {
    *(long *)(lVar2 + 0x20) = param_2;
  }
  lVar2 = *(long *)(param_2 + 0x20);
  *(long *)(lVar1 + 0x20) = lVar2;
  if (lVar2 != 0) {
    if (*(long *)(lVar2 + 0x28) != param_2) {
      *(long *)(lVar2 + 0x30) = lVar1;
      *(long *)(lVar1 + 0x28) = param_2;
      *(long *)(param_2 + 0x20) = lVar1;
      return;
    }
    *(long *)(lVar2 + 0x28) = lVar1;
    *(long *)(lVar1 + 0x28) = param_2;
    *(long *)(param_2 + 0x20) = lVar1;
    return;
  }
  *param_1 = lVar1;
  *(long *)(lVar1 + 0x28) = param_2;
  *(long *)(param_2 + 0x20) = lVar1;
  return;
}


// ===== 004ef700 btreeInsert =====

undefined8 btreeInsert(long param_1,long *param_2)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == 0) {
    return 0x3d;
  }
  if (param_2 == (long *)0x0) {
    return 0x3d;
  }
  uVar1 = *(ulong *)(param_1 + 0x10);
  if (uVar1 < *(ulong *)(param_1 + 8)) {
    return 0x1f;
  }
  lVar4 = *param_2;
  if (*param_2 == 0) {
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    *(undefined1 *)(param_1 + 0x18) = 1;
    *param_2 = param_1;
LAB_004ef800:
    *(undefined1 *)(param_1 + 0x18) = 0;
    return 0;
  }
  do {
    lVar2 = lVar4;
    if (uVar1 < *(ulong *)(lVar2 + 8)) {
      lVar4 = *(long *)(lVar2 + 0x28);
    }
    else {
      if (*(ulong *)(param_1 + 8) <= *(ulong *)(lVar2 + 0x10)) {
        return 0x19;
      }
      lVar4 = *(long *)(lVar2 + 0x30);
    }
  } while (lVar4 != 0);
  *(long *)(param_1 + 0x20) = lVar2;
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 0x18) = 1;
  lVar4 = param_1;
  if (uVar1 < *(ulong *)(lVar2 + 8)) {
    *(long *)(lVar2 + 0x28) = param_1;
  }
  else {
    *(long *)(lVar2 + 0x30) = param_1;
  }
LAB_004ef7b0:
  param_1 = *param_2;
  if (lVar4 != param_1) {
    do {
      lVar2 = *(long *)(lVar4 + 0x20);
      if (*(char *)(lVar2 + 0x18) == '\0') break;
      lVar3 = *(long *)(*(long *)(lVar2 + 0x20) + 0x28);
      if (lVar2 == lVar3) {
        lVar3 = *(long *)(*(long *)(lVar2 + 0x20) + 0x30);
        if ((lVar3 == 0) || (*(char *)(lVar3 + 0x18) == '\0')) {
          lVar3 = lVar2;
          if (*(long *)(lVar2 + 0x30) == lVar4) {
            _rotateLeft(param_2,lVar2);
            lVar3 = *(long *)(lVar2 + 0x20);
            lVar4 = lVar2;
          }
          *(undefined1 *)(lVar3 + 0x18) = 0;
          *(undefined1 *)(*(long *)(*(long *)(lVar4 + 0x20) + 0x20) + 0x18) = 1;
          _rotateRight(param_2,*(undefined8 *)(*(long *)(lVar4 + 0x20) + 0x20));
          goto LAB_004ef7b0;
        }
      }
      else if ((lVar3 == 0) || (*(char *)(lVar3 + 0x18) == '\0')) goto LAB_004ef810;
      *(undefined1 *)(lVar2 + 0x18) = 0;
      *(undefined1 *)(lVar3 + 0x18) = 0;
      *(undefined1 *)(*(long *)(*(long *)(lVar4 + 0x20) + 0x20) + 0x18) = 1;
      param_1 = *param_2;
      lVar4 = *(long *)(*(long *)(lVar4 + 0x20) + 0x20);
      if (lVar4 == param_1) break;
    } while( true );
  }
  goto LAB_004ef800;
LAB_004ef810:
  lVar3 = lVar2;
  if (*(long *)(lVar2 + 0x28) == lVar4) {
    _rotateRight(param_2,lVar2);
    lVar3 = *(long *)(lVar2 + 0x20);
    lVar4 = lVar2;
  }
  *(undefined1 *)(lVar3 + 0x18) = 0;
  *(undefined1 *)(*(long *)(*(long *)(lVar4 + 0x20) + 0x20) + 0x18) = 1;
  _rotateLeft(param_2,*(undefined8 *)(*(long *)(lVar4 + 0x20) + 0x20));
  goto LAB_004ef7b0;
}


// ===== 004ef940 btreeUnlink =====

undefined8 btreeUnlink(long param_1,long *param_2)

{
  long *plVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  bool bVar7;
  
  if ((param_1 == 0) || (param_2 == (long *)0x0)) {
    return 0x3d;
  }
  lVar3 = *(long *)(param_1 + 0x28);
  lVar4 = param_1;
  if (lVar3 == 0) {
LAB_004ef98c:
    lVar3 = *(long *)(lVar4 + 0x30);
    lVar5 = *(long *)(lVar4 + 0x20);
    lVar6 = lVar5;
    if (lVar3 != 0) {
      *(long *)(lVar3 + 0x20) = lVar5;
      lVar6 = *(long *)(lVar4 + 0x20);
    }
    if (lVar6 == 0) {
      *param_2 = lVar3;
    }
    else {
LAB_004ef9a9:
      if (*(long *)(lVar6 + 0x28) == lVar4) {
        *(long *)(lVar6 + 0x28) = lVar3;
      }
      else {
        *(long *)(lVar6 + 0x30) = lVar3;
      }
    }
    cVar2 = *(char *)(lVar4 + 0x18);
    if (param_1 == lVar4) goto joined_r0x004efa42;
    lVar6 = *(long *)(param_1 + 0x20);
    *(long *)(lVar4 + 0x20) = lVar6;
    if (lVar6 == 0) {
      *param_2 = lVar4;
    }
    else if (*(long *)(lVar6 + 0x28) == param_1) {
      *(long *)(lVar6 + 0x28) = lVar4;
    }
    else {
      *(long *)(lVar6 + 0x30) = lVar4;
    }
    *(undefined1 *)(lVar4 + 0x18) = *(undefined1 *)(param_1 + 0x18);
    lVar6 = *(long *)(param_1 + 0x28);
    *(long *)(lVar4 + 0x28) = lVar6;
    if (lVar6 != 0) {
      *(long *)(lVar6 + 0x20) = lVar4;
    }
    lVar6 = *(long *)(param_1 + 0x30);
    *(long *)(lVar4 + 0x30) = lVar6;
    if (lVar6 != 0) {
      *(long *)(lVar6 + 0x20) = lVar4;
    }
    if (param_1 != lVar5) goto joined_r0x004efa42;
    if (cVar2 != '\0') {
      return 0;
    }
    if (*param_2 == lVar3) goto LAB_004efad3;
    if (lVar3 != 0) goto LAB_004efba8;
  }
  else {
    lVar5 = *(long *)(param_1 + 0x30);
    if (lVar5 != 0) {
      do {
        plVar1 = (long *)(lVar5 + 0x28);
        lVar4 = lVar5;
        lVar5 = *plVar1;
      } while (*plVar1 != 0);
      goto LAB_004ef98c;
    }
    lVar5 = *(long *)(param_1 + 0x20);
    *(long *)(lVar3 + 0x20) = lVar5;
    lVar6 = *(long *)(param_1 + 0x20);
    if (lVar6 != 0) goto LAB_004ef9a9;
    *param_2 = lVar3;
    cVar2 = *(char *)(param_1 + 0x18);
joined_r0x004efa42:
    lVar4 = lVar5;
    if (cVar2 != '\0') {
      return 0;
    }
    if (*param_2 == lVar3) goto LAB_004efad3;
    if (lVar3 != 0) goto LAB_004efba8;
    if (lVar4 == 0) {
      nvAssertFailedNoLog("!(x == NULL && parentOfX == NULL)",
                          "src/libraries/containers/btree/btree.c",0x1cd);
      return 0;
    }
  }
  lVar5 = *(long *)(lVar4 + 0x28);
  lVar3 = lVar4;
  if (lVar5 == 0) goto LAB_004efb10;
  if (*(char *)(lVar5 + 0x18) != '\0') goto LAB_004efbd3;
LAB_004efa77:
  lVar4 = *(long *)(lVar5 + 0x30);
  if ((lVar4 == 0) || (*(char *)(lVar4 + 0x18) == '\0')) {
    if ((*(long *)(lVar5 + 0x28) == 0) || (*(char *)(*(long *)(lVar5 + 0x28) + 0x18) == '\0')) {
LAB_004efb93:
      *(undefined1 *)(lVar5 + 0x18) = 1;
      do {
        do {
          while( true ) {
            do {
              lVar4 = *(long *)(lVar3 + 0x20);
              if (lVar3 == *param_2) goto LAB_004efadc;
LAB_004efba8:
              if (*(char *)(lVar3 + 0x18) != '\0') goto LAB_004efadc;
            } while (lVar4 == 0);
            lVar5 = *(long *)(lVar4 + 0x28);
            bVar7 = lVar5 == lVar3;
            lVar3 = lVar4;
            if (bVar7) break;
            if (lVar5 != 0) {
              if (*(char *)(lVar5 + 0x18) == '\0') goto LAB_004efa77;
LAB_004efbd3:
              *(undefined1 *)(lVar5 + 0x18) = 0;
              *(undefined1 *)(lVar3 + 0x18) = 1;
              _rotateRight(param_2,lVar3);
              lVar5 = *(long *)(lVar3 + 0x28);
              if (lVar5 != 0) goto LAB_004efa77;
            }
          }
LAB_004efb10:
          lVar5 = *(long *)(lVar3 + 0x30);
        } while (lVar5 == 0);
        if (*(char *)(lVar5 + 0x18) == '\0') break;
        *(undefined1 *)(lVar5 + 0x18) = 0;
        *(undefined1 *)(lVar3 + 0x18) = 1;
        _rotateLeft(param_2,lVar3);
        lVar5 = *(long *)(lVar3 + 0x30);
      } while (lVar5 == 0);
      lVar4 = *(long *)(lVar5 + 0x28);
      if ((lVar4 == 0) || (*(char *)(lVar4 + 0x18) == '\0')) goto LAB_004efc18;
      if ((*(long *)(lVar5 + 0x30) == 0) || (*(char *)(*(long *)(lVar5 + 0x30) + 0x18) == '\0')) {
        *(undefined1 *)(lVar4 + 0x18) = 0;
        *(undefined1 *)(lVar5 + 0x18) = 1;
        _rotateRight(param_2);
        lVar5 = *(long *)(lVar3 + 0x30);
      }
      goto LAB_004efb5d;
    }
  }
  else if ((*(long *)(lVar5 + 0x28) == 0) || (*(char *)(*(long *)(lVar5 + 0x28) + 0x18) == '\0')) {
    *(undefined1 *)(lVar4 + 0x18) = 0;
    *(undefined1 *)(lVar5 + 0x18) = 1;
    _rotateLeft(param_2);
    lVar5 = *(long *)(lVar3 + 0x28);
  }
  *(undefined1 *)(lVar5 + 0x18) = *(undefined1 *)(lVar3 + 0x18);
  *(undefined1 *)(lVar3 + 0x18) = 0;
  *(undefined1 *)(*(long *)(lVar5 + 0x28) + 0x18) = 0;
  _rotateRight(param_2,lVar3);
LAB_004efacf:
  lVar3 = *param_2;
LAB_004efad3:
  if (lVar3 == 0) {
    return 0;
  }
LAB_004efadc:
  *(undefined1 *)(lVar3 + 0x18) = 0;
  return 0;
LAB_004efc18:
  if ((*(long *)(lVar5 + 0x30) != 0) && (*(char *)(*(long *)(lVar5 + 0x30) + 0x18) != '\0')) {
LAB_004efb5d:
    *(undefined1 *)(lVar5 + 0x18) = *(undefined1 *)(lVar3 + 0x18);
    *(undefined1 *)(lVar3 + 0x18) = 0;
    *(undefined1 *)(*(long *)(lVar5 + 0x30) + 0x18) = 0;
    _rotateLeft(param_2,lVar3);
    goto LAB_004efacf;
  }
  goto LAB_004efb93;
}


// ===== 004efce0 btreeSearch =====

undefined8 btreeSearch(ulong param_1,long *param_2,long param_3)

{
  undefined8 uVar1;
  
LAB_004efcf0:
  do {
    if (param_3 == 0) {
      uVar1 = 0x57;
LAB_004efd25:
      *param_2 = param_3;
      return uVar1;
    }
    if (*(ulong *)(param_3 + 8) <= param_1) {
      if (param_1 <= *(ulong *)(param_3 + 0x10)) {
        uVar1 = 0;
        goto LAB_004efd25;
      }
      param_3 = *(long *)(param_3 + 0x30);
      goto LAB_004efcf0;
    }
    param_3 = *(long *)(param_3 + 0x28);
  } while( true );
}


// ===== 004efd40 btreeEnumStart =====

undefined8 btreeEnumStart(ulong param_1,long *param_2,long param_3)

{
  *param_2 = 0;
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    while (param_1 < *(ulong *)(param_3 + 8)) {
      *param_2 = param_3;
      param_3 = *(long *)(param_3 + 0x28);
      if (param_3 == 0) {
        return 0;
      }
    }
    if (param_1 <= *(ulong *)(param_3 + 0x10)) break;
    param_3 = *(long *)(param_3 + 0x30);
  }
  *param_2 = param_3;
  return 0;
}


// ===== 004efd80 btreeEnumNext =====

undefined8 btreeEnumNext(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = 0;
  if (param_2 != 0) {
    lVar1 = *param_1;
    lVar3 = 0;
    if (lVar1 != 0) {
      lVar2 = *(long *)(lVar1 + 0x30);
      if (*(long *)(lVar1 + 0x30) == 0) {
        lVar3 = *(long *)(lVar1 + 0x20);
        if (lVar3 == 0) {
          lVar3 = 0;
        }
        else {
          do {
            if (*(ulong *)(lVar1 + 0x10) < *(ulong *)(lVar3 + 8)) break;
            lVar3 = *(long *)(lVar3 + 0x20);
          } while (lVar3 != 0);
        }
      }
      else {
        do {
          lVar3 = lVar2;
          lVar2 = *(long *)(lVar3 + 0x28);
        } while (*(long *)(lVar3 + 0x28) != 0);
      }
    }
  }
  *param_1 = lVar3;
  return 0;
}


// ===== 004efdf0 btreeDestroyData =====

undefined8 btreeDestroyData(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)param_1[5];
    if (puVar1 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)puVar1[5];
      if (puVar2 != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)puVar2[5];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        puVar3 = (undefined8 *)puVar2[6];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        portMemFree(*puVar2);
      }
      puVar2 = (undefined8 *)puVar1[6];
      if (puVar2 != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)puVar2[5];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        puVar3 = (undefined8 *)puVar2[6];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        portMemFree(*puVar2);
      }
      portMemFree(*puVar1);
    }
    puVar1 = (undefined8 *)param_1[6];
    if (puVar1 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)puVar1[5];
      if (puVar2 != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)puVar2[5];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        puVar3 = (undefined8 *)puVar2[6];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        portMemFree(*puVar2);
      }
      puVar2 = (undefined8 *)puVar1[6];
      if (puVar2 != (undefined8 *)0x0) {
        puVar3 = (undefined8 *)puVar2[5];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            puVar5 = (undefined8 *)puVar4[5];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            puVar5 = (undefined8 *)puVar4[6];
            if (puVar5 != (undefined8 *)0x0) {
              btreeDestroyData(puVar5[5]);
              btreeDestroyData(puVar5[6]);
              portMemFree(*puVar5);
            }
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        puVar3 = (undefined8 *)puVar2[6];
        if (puVar3 != (undefined8 *)0x0) {
          puVar4 = (undefined8 *)puVar3[5];
          if (puVar4 != (undefined8 *)0x0) {
            btreeDestroyData(puVar4[5]);
            btreeDestroyData(puVar4[6]);
            portMemFree(*puVar4);
          }
          puVar4 = (undefined8 *)puVar3[6];
          if (puVar4 != (undefined8 *)0x0) {
            btreeDestroyData(puVar4[5]);
            btreeDestroyData(puVar4[6]);
            portMemFree(*puVar4);
          }
          portMemFree(*puVar3);
        }
        portMemFree(*puVar2);
      }
      portMemFree(*puVar1);
    }
    portMemFree(*param_1);
    return 0;
  }
  return 0;
}


// ===== 004f06b0 btreeDestroyNodes =====

undefined8 btreeDestroyNodes(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(param_1 + 0x28);
    if (lVar1 != 0) {
      lVar2 = *(long *)(lVar1 + 0x28);
      if (lVar2 != 0) {
        lVar3 = *(long *)(lVar2 + 0x28);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        lVar3 = *(long *)(lVar2 + 0x30);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        portMemFree(lVar2);
      }
      lVar2 = *(long *)(lVar1 + 0x30);
      if (lVar2 != 0) {
        lVar3 = *(long *)(lVar2 + 0x28);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        lVar3 = *(long *)(lVar2 + 0x30);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        portMemFree(lVar2);
      }
      portMemFree(lVar1);
    }
    lVar1 = *(long *)(param_1 + 0x30);
    if (lVar1 != 0) {
      lVar2 = *(long *)(lVar1 + 0x28);
      if (lVar2 != 0) {
        lVar3 = *(long *)(lVar2 + 0x28);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        lVar3 = *(long *)(lVar2 + 0x30);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        portMemFree(lVar2);
      }
      lVar2 = *(long *)(lVar1 + 0x30);
      if (lVar2 != 0) {
        lVar3 = *(long *)(lVar2 + 0x28);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        lVar3 = *(long *)(lVar2 + 0x30);
        if (lVar3 != 0) {
          lVar4 = *(long *)(lVar3 + 0x28);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          lVar4 = *(long *)(lVar3 + 0x30);
          if (lVar4 != 0) {
            lVar5 = *(long *)(lVar4 + 0x28);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            lVar5 = *(long *)(lVar4 + 0x30);
            if (lVar5 != 0) {
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x28));
              btreeDestroyNodes(*(undefined8 *)(lVar5 + 0x30));
              portMemFree(lVar5);
            }
            portMemFree(lVar4);
          }
          portMemFree(lVar3);
        }
        portMemFree(lVar2);
      }
      portMemFree(lVar1);
    }
    portMemFree(param_1);
    return 0;
  }
  return 0;
}


// ===== 004f0fb0 eheapGetSize =====

undefined8 eheapGetSize(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x70);
  return 0;
}


// ===== 004f0fc0 eheapGetFree =====

undefined8 eheapGetFree(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x78);
  return 0;
}


// ===== 004f0fd0 eheapGetBase =====

undefined8 eheapGetBase(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(param_1 + 0x68);
  return 0;
}


// ===== 004f0fe0 eheapSetAllocRange =====

undefined8 eheapSetAllocRange(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar1 = *(ulong *)(param_1 + 0x68);
  if (param_2 <= uVar1) {
    param_2 = uVar1;
  }
  uVar1 = (uVar1 + *(long *)(param_1 + 0x70)) - 1;
  if (param_3 < uVar1) {
    uVar1 = param_3;
  }
  uVar2 = 0x1f;
  if (param_2 <= uVar1) {
    *(ulong *)(param_1 + 0x80) = param_2;
    uVar2 = 0;
    *(ulong *)(param_1 + 0x88) = uVar1;
  }
  return uVar2;
}


// ===== 004f1020 eheapGetNumBlocks =====

undefined4 eheapGetNumBlocks(long param_1)

{
  return *(undefined4 *)(param_1 + 0xac);
}


// ===== 004f1030 eheapInfoForRange =====

void eheapInfoForRange(long param_1,ulong param_2,ulong param_3,ulong *param_4,ulong *param_5,
                      int *param_6,long *param_7)

{
  ulong *puVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  
  if (param_7 != (long *)0x0) {
    *param_7 = 0;
  }
  puVar1 = *(ulong **)(param_1 + 0xa0);
  if (puVar1 == (ulong *)0x0) {
    iVar6 = 0;
    uVar5 = 0;
    uVar7 = 0;
  }
  else {
    if (param_3 < param_2) {
      nvAssertFailedNoLog("range.lo <= range.hi","src/libraries/containers/eheap/eheap_old.c",0x456)
      ;
    }
    iVar6 = 0;
    uVar5 = 0;
    uVar7 = 0;
    puVar3 = puVar1;
    do {
      uVar4 = *puVar3;
      if (*puVar3 <= param_2) {
        uVar4 = param_2;
      }
      uVar2 = puVar3[1];
      if (param_3 <= puVar3[1]) {
        uVar2 = param_3;
      }
      if (uVar4 <= uVar2) {
        iVar6 = iVar6 + 1;
        uVar2 = (uVar2 + 1) - uVar4;
        if (param_7 != (long *)0x0) {
          *param_7 = *param_7 + uVar2;
        }
        if (uVar5 < uVar2) {
          uVar5 = uVar2;
          uVar7 = uVar4;
        }
      }
      puVar3 = (ulong *)puVar3[0xd];
    } while (puVar1 != puVar3);
  }
  if (param_4 != (ulong *)0x0) {
    *param_4 = uVar7;
  }
  if (param_5 != (ulong *)0x0) {
    *param_5 = uVar5;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = iVar6;
  }
  return;
}


// ===== 004f1150 eheapInfo =====

void eheapInfo(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = *(undefined8 *)(param_1 + 0x80);
  uVar2 = *(undefined8 *)(param_1 + 0x88);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(param_1 + 0x78);
  }
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = *(undefined8 *)(param_1 + 0x70);
  }
  eheapInfoForRange(param_1,uVar1,uVar2);
  return;
}


// ===== 004f11a0 eheapGetBlock =====

long eheapGetBlock(long param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  long lVar2;
  long *local_20 [2];
  
  iVar1 = btreeSearch(param_2,local_20,*(undefined8 *)(param_1 + 0xb8));
  if (iVar1 == 0) {
    lVar2 = *local_20[0];
    if ((*(int *)(lVar2 + 0x20) == -1) && (param_3 == '\0')) {
      lVar2 = 0;
    }
    return lVar2;
  }
  return 0;
}


// ===== 004f11f0 eheapSetOwnerIsolation =====

undefined8 eheapSetOwnerIsolation(long param_1,char param_2,uint param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0x40;
  if (*(long *)(param_1 + 0x78) == *(long *)(param_1 + 0x70)) {
    if ((param_2 != '\0') &&
       ((param_3 < 2 || ((param_2 != '\0' && ((param_3 - 1 & param_3) != 0)))))) {
      return 0x1f;
    }
    *(char *)(param_1 + 0x90) = param_2;
    uVar1 = 0;
    *(uint *)(param_1 + 0x94) = param_3;
  }
  return uVar1;
}


// ===== 004f1240 _eheapAllocMemStruct =====

undefined4 _eheapAllocMemStruct(long param_1,long *param_2)

{
  long lVar1;
  
  if (*(int *)(param_1 + 0xc0) == 0) {
    lVar1 = portMemAllocNonPaged(*(undefined4 *)(param_1 + 0xb0));
    *param_2 = lVar1;
    if (lVar1 != 0) {
      portMemSet(lVar1,0,*(undefined4 *)(param_1 + 0xb0));
      return 0;
    }
    nvAssertFailedNoLog(&DAT_00da3668,"src/libraries/containers/eheap/eheap_old.c",0x69);
  }
  else {
    lVar1 = *(long *)(param_1 + 200);
    if (lVar1 != 0) {
      *param_2 = lVar1;
      *(undefined8 *)(param_1 + 200) = *(undefined8 *)(lVar1 + 0x78);
      return 0;
    }
    nvAssertFailedNoLog(&DAT_00da3668,"src/libraries/containers/eheap/eheap_old.c",0x5c);
  }
  return 0x59;
}


// ===== 004f12fa _eheapCheckOwnership.cold =====

void _eheapCheckOwnership_cold(void)

{
  code *pcVar1;
  
  nvAssertFailedNoLog("pTmpBlock","src/libraries/containers/eheap/eheap_old.c",0x548);
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004f1320 _eheapCheckOwnership =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_r12 replaced with injection: x86_indirect_thunk_r12 */

undefined8
_eheapCheckOwnership
          (long param_1,undefined8 param_2,ulong param_3,ulong param_4,ulong *param_5,code *param_6)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  long *local_40 [2];
  
  uVar1 = *(uint *)(param_1 + 0x94);
  uVar8 = *(ulong *)(param_1 + 0x68);
  uVar7 = -(ulong)uVar1;
  param_3 = param_3 & uVar7;
  uVar3 = (ulong)(uVar1 - 1);
  if (param_4 % (ulong)uVar1 == 0) {
    uVar3 = (ulong)(uVar1 - 1) + 1;
  }
  uVar7 = param_4 + uVar3 & uVar7;
  if (param_3 <= uVar8) {
    param_3 = uVar8;
  }
  uVar8 = (uVar8 + *(long *)(param_1 + 0x70)) - 1;
  if (uVar7 < uVar8) {
    uVar8 = uVar7;
  }
  if (param_5 == (ulong *)0x0) {
    nvAssertFailedNoLog("NULL != blockFree","src/libraries/containers/eheap/eheap_old.c",0x541);
  }
  if ((param_3 < *param_5) || (param_5[1] < uVar8)) {
    while (param_3 < uVar8) {
      if (*(code **)(param_1 + 0x40) == eheapGetBlock) {
        iVar4 = btreeSearch(param_3,local_40,*(undefined8 *)(param_1 + 0xb8));
        if (iVar4 != 0) {
          nvAssertFailedNoLog("pTmpBlock","src/libraries/containers/eheap/eheap_old.c",0x548);
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        lVar5 = *local_40[0];
      }
      else {
        lVar5 = (**(code **)(param_1 + 0x40))(param_1,param_3,1);
        if (lVar5 == 0) {
          uVar6 = _eheapCheckOwnership_cold();
          return uVar6;
        }
      }
      if ((*(int *)(lVar5 + 0x20) != -1) &&
         (uVar6 = (*param_6)(param_2,*(undefined8 *)(lVar5 + 0x80)), (char)uVar6 == '\0')) {
        return uVar6;
      }
      param_3 = *(long *)(lVar5 + 8) + 1;
    }
  }
  return 1;
}


// ===== 004f1490 eheapTraverse =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 eheapTraverse(long param_1,undefined8 param_2,code *param_3,int param_4)

{
  ulong uVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong uVar9;
  int local_48;
  int local_44;
  ulong *local_40 [2];
  
  puVar7 = *(ulong **)(param_1 + 0x98);
  local_48 = 1;
  if (param_4 < 1) {
    puVar7 = (ulong *)puVar7[0xe];
  }
  if (puVar7 == (ulong *)0x0) {
    nvAssertFailedNoLog("pBlock != NULL","src/libraries/containers/eheap/eheap_old.c",0x4a6);
    return 0x40;
  }
  uVar1 = puVar7[1];
  uVar2 = *puVar7;
  do {
    puVar8 = (ulong *)puVar7[0xe];
    local_44 = 0;
    if (param_4 < 1) {
      uVar9 = puVar8[1];
    }
    else {
      uVar9 = *(ulong *)puVar7[0xf];
      puVar8 = (ulong *)puVar7[0xf];
    }
    uVar3 = (*param_3)(param_1,param_2,puVar7,&local_48,&local_44);
    if (local_44 == 0) {
      uVar5 = *puVar8;
      uVar6 = puVar8[1];
    }
    else {
      iVar4 = btreeSearch(uVar9,local_40,*(undefined8 *)(param_1 + 0xb8));
      if (iVar4 == 0) {
        puVar8 = (ulong *)*local_40[0];
      }
      else {
        puVar8 = (ulong *)0x0;
      }
      if (param_4 < 1) {
        uVar6 = puVar8[1];
        if (uVar9 < uVar6) {
          puVar8 = (ulong *)puVar8[0xe];
          goto LAB_004f15b2;
        }
        uVar5 = *puVar8;
      }
      else {
        uVar5 = *puVar8;
        if (uVar5 < uVar9) {
          puVar8 = (ulong *)puVar8[0xf];
LAB_004f15b2:
          if (puVar8 == (ulong *)0x0) {
            nvAssertFailedNoLog("pBlock != NULL","src/libraries/containers/eheap/eheap_old.c",0x4d7)
            ;
            return 0x40;
          }
          uVar5 = *puVar8;
        }
        uVar6 = puVar8[1];
      }
    }
    if ((((uVar5 <= uVar2) && (uVar2 <= uVar6)) || ((uVar1 <= uVar6 && (uVar5 <= uVar1)))) ||
       (puVar7 = puVar8, local_48 == 0)) {
      return uVar3;
    }
  } while( true );
}


// ===== 004f1660 _eheapBlockFree.part.0 =====

undefined8 _eheapBlockFree_part_0(long param_1,ulong *param_2)

{
  ulong uVar1;
  ulong uVar2;
  int iVar3;
  ulong *puVar4;
  ulong *puVar5;
  
  *(ulong *)(param_1 + 0x78) = (param_2[1] + 1 + *(long *)(param_1 + 0x78)) - *param_2;
  puVar4 = param_2;
  if ((*(int *)(param_2[0xe] + 0x20) == -1) && (param_2 != *(ulong **)(param_1 + 0x98))) {
    iVar3 = btreeUnlink(param_2 + 5,param_1 + 0xb8);
    if (iVar3 != 0) {
      return 0x37;
    }
    iVar3 = btreeUnlink(param_2[0xe] + 0x28,param_1 + 0xb8);
    if (iVar3 != 0) {
      return 0x37;
    }
    uVar1 = param_2[0xf];
    *(ulong *)(param_2[0xe] + 0x78) = uVar1;
    uVar2 = param_2[0xe];
    *(ulong *)(uVar1 + 0x70) = uVar2;
    *(ulong *)(uVar2 + 8) = param_2[1];
    puVar4 = (ulong *)param_2[0xe];
    *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + -1;
    if (*(int *)(param_1 + 0xc0) == 0) {
      portMemFree(param_2);
    }
    else {
      portMemSet(param_2,0,*(undefined4 *)(param_1 + 0xb0));
      param_2[0xf] = *(ulong *)(param_1 + 200);
      *(ulong **)(param_1 + 200) = param_2;
    }
    puVar4[7] = puVar4[1];
    iVar3 = btreeInsert(puVar4 + 5,param_1 + 0xb8);
    if (iVar3 != 0) {
      return 0x37;
    }
  }
  puVar5 = puVar4;
  if ((*(int *)(puVar4[0xf] + 0x20) == -1) && (puVar4[0xf] != *(ulong *)(param_1 + 0x98))) {
    iVar3 = btreeUnlink(puVar4 + 5,param_1 + 0xb8);
    if ((iVar3 == 0) && (iVar3 = btreeUnlink(puVar4[0xf] + 0x28,param_1 + 0xb8), iVar3 == 0)) {
      uVar1 = puVar4[0xf];
      *(ulong *)(puVar4[0xe] + 0x78) = uVar1;
      *(ulong *)(uVar1 + 0x70) = puVar4[0xe];
      *(ulong *)puVar4[0xf] = *puVar4;
      if (puVar4 == *(ulong **)(param_1 + 0x98)) {
        *(ulong *)(param_1 + 0x98) = puVar4[0xf];
      }
      if ((int)puVar4[4] == -1) {
        if (puVar4 == *(ulong **)(param_1 + 0xa0)) {
          *(ulong *)(param_1 + 0xa0) = puVar4[0xd];
        }
        uVar1 = puVar4[0xc];
        *(ulong *)(puVar4[0xd] + 0x60) = uVar1;
        *(ulong *)(uVar1 + 0x68) = puVar4[0xd];
      }
      puVar5 = (ulong *)puVar4[0xf];
      *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + -1;
      if (*(int *)(param_1 + 0xc0) == 0) {
        portMemFree(puVar4);
      }
      else {
        portMemSet(puVar4,0,*(undefined4 *)(param_1 + 0xb0));
        puVar4[0xf] = *(ulong *)(param_1 + 200);
        *(ulong **)(param_1 + 200) = puVar4;
      }
      puVar5[6] = *puVar5;
      iVar3 = btreeInsert(puVar5 + 5,param_1 + 0xb8);
      if (iVar3 == 0) goto LAB_004f16a6;
    }
    return 0x37;
  }
LAB_004f16a6:
  if ((int)puVar5[4] != -1) {
    puVar4 = *(ulong **)(param_1 + 0xa0);
    if (puVar4 == (ulong *)0x0) {
      *(ulong **)(param_1 + 0xa0) = puVar5;
      puVar5[0xd] = (ulong)puVar5;
      puVar5[0xc] = (ulong)puVar5;
    }
    else {
      uVar1 = *puVar5;
      if (uVar1 < *puVar4) {
        *(ulong **)(param_1 + 0xa0) = puVar5;
      }
      else if (uVar1 < *(ulong *)puVar4[0xc]) {
        do {
          puVar4 = (ulong *)puVar4[0xd];
          if (uVar1 <= *puVar4) break;
          puVar4 = (ulong *)puVar4[0xd];
        } while (*puVar4 < uVar1);
      }
      puVar5[0xd] = (ulong)puVar4;
      uVar1 = puVar4[0xc];
      puVar5[0xc] = uVar1;
      *(ulong **)(uVar1 + 0x68) = puVar5;
      puVar4[0xc] = (ulong)puVar5;
    }
  }
  *(undefined4 *)(puVar5 + 4) = 0xffffffff;
  puVar5[2] = *puVar5;
  portMemSet(puVar5 + 0x11,0,(ulong)*(uint *)(param_1 + 0xb0) - 0x88);
  return 0;
}


// ===== 004f19d0 eheapFree =====

undefined8 eheapFree(long param_1,undefined8 param_2)

{
  int *piVar1;
  undefined8 uVar2;
  long *local_20 [2];
  
  uVar2 = btreeSearch(param_2,local_20,*(undefined8 *)(param_1 + 0xb8));
  if (((int)uVar2 == 0) && (*(int *)(*local_20[0] + 0x20) != -1)) {
    piVar1 = (int *)(*local_20[0] + 0x1c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 != 0) {
      return uVar2;
    }
    uVar2 = _eheapBlockFree_part_0(param_1);
    return uVar2;
  }
  return 0x37;
}


// ===== 004f1a30 eheapDestruct.part.0 =====

void eheapDestruct_part_0(long param_1)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar6 = lVar5;
  lVar3 = lVar5;
  do {
    lVar4 = lVar3;
    lVar2 = *(long *)(lVar6 + 0x78);
    if (*(int *)(lVar6 + 0x20) != -1) {
      piVar1 = (int *)(lVar6 + 0x1c);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        _eheapBlockFree_part_0(param_1);
      }
      lVar5 = *(long *)(param_1 + 0x98);
    }
    lVar6 = lVar5;
    lVar3 = lVar5;
  } while ((lVar5 != lVar4) || (lVar6 = lVar2, lVar3 = lVar4, lVar2 != lVar5));
  if (*(int *)(param_1 + 0xc0) == 0) {
    portMemFree(lVar2);
    *(undefined8 *)(param_1 + 0x98) = 0;
    return;
  }
  portMemFree(*(undefined8 *)(param_1 + 0xd0));
  *(undefined8 *)(param_1 + 0xd0) = 0;
  return;
}


// ===== 004f1ae0 eheapDestruct =====

undefined8 eheapDestruct(long param_1)

{
  if (*(long *)(param_1 + 0x98) != 0) {
    eheapDestruct_part_0();
    return 0;
  }
  return 0;
}


// ===== 004f1b10 eheapAlloc =====

undefined8
eheapAlloc(long param_1,undefined4 param_2,uint *param_3,ulong *param_4,ulong *param_5,ulong param_6
          ,ulong param_7,undefined8 *param_8,undefined8 param_9,long param_10)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  ulong *puVar9;
  ulong uVar10;
  ulong *puVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong *puVar15;
  ulong uVar16;
  ulong uVar17;
  ulong *local_48;
  long *local_40 [2];
  
  uVar5 = *param_3;
  local_48 = (ulong *)0x0;
  local_40[0] = (long *)0x0;
  if ((uVar5 & 0x100000) == 0) {
    if ((uVar5 & 0x10) == 0) goto LAB_004f1b56;
    uVar12 = *param_4;
    *param_4 = 0;
    uVar17 = *param_5;
  }
  else {
    if ((uVar5 & 0x10) != 0) {
      return 0x1f;
    }
LAB_004f1b56:
    *param_4 = 0;
    uVar17 = *param_5;
    uVar12 = 0;
  }
  if (uVar17 == 0) {
    return 0x1f;
  }
  uVar10 = *(ulong *)(param_1 + 0x88);
  uVar8 = *(long *)(param_1 + 0x70) + -1 + *(ulong *)(param_1 + 0x68);
  uVar7 = uVar10;
  if (uVar8 <= uVar10) {
    uVar7 = uVar8;
  }
  uVar14 = *(ulong *)(param_1 + 0x68);
  if (uVar10 != 0 || *(ulong *)(param_1 + 0x80) != 0) {
    uVar8 = uVar7;
    uVar14 = *(ulong *)(param_1 + 0x80);
  }
  if (uVar8 < uVar14) {
    return 0x1f;
  }
  uVar17 = (uVar17 - 1) + param_7;
  uVar17 = uVar17 - uVar17 % param_7;
  if (*(ulong *)(param_1 + 0x78) < uVar17) {
    return 0x51;
  }
  uVar5 = *param_3;
  if ((uVar5 & 0x100000) != 0) {
    uVar5 = *(uint *)(param_1 + 0x94);
    if (uVar5 == 0) {
      nvAssertFailedNoLog("pHeap->ownerGranularity","src/libraries/containers/eheap/eheap_old.c",
                          0x171);
      return 0x1f;
    }
    if ((*(char *)(param_1 + 0x90) == '\0') || (param_10 == 0)) {
      nvAssertFailedNoLog("pHeap->bOwnerIsolation && checker",
                          "src/libraries/containers/eheap/eheap_old.c",0x172);
      return 0x1f;
    }
    puVar15 = *(ulong **)(param_1 + 0xa0);
    if (puVar15 == (ulong *)0x0) {
      return 0x51;
    }
    lVar1 = uVar17 - 1;
    do {
      uVar14 = (ulong)uVar5;
      uVar8 = *puVar15;
      uVar7 = puVar15[1];
      uVar12 = (-uVar14 & uVar8) + param_6;
      uVar10 = uVar12 + lVar1;
      if (uVar10 <= uVar7) {
        uVar16 = (ulong)uVar5;
        do {
          uVar5 = (uint)uVar16;
          uVar13 = -uVar14 & uVar12;
          uVar2 = uVar12;
          if (uVar12 % uVar14 == 0) {
            uVar2 = uVar12 + 1;
          }
          if (uVar12 <= uVar13) {
            uVar13 = uVar12;
          }
          if ((uVar13 < uVar8) || (uVar7 < ((uVar5 - 1) + uVar2 & -uVar14))) {
            uVar12 = uVar12 + uVar14;
            uVar10 = uVar12 + lVar1;
            if (uVar7 < uVar10) break;
          }
          else {
            cVar4 = _eheapCheckOwnership(param_1,param_9,uVar12,uVar10,puVar15,param_10);
            if (cVar4 != '\0') {
              uVar8 = *puVar15;
              goto LAB_004f2077;
            }
            uVar5 = *(uint *)(param_1 + 0x94);
            uVar14 = (ulong)uVar5;
            uVar7 = puVar15[1];
            uVar12 = uVar12 + uVar14;
            uVar10 = uVar12 + lVar1;
            uVar16 = uVar14;
            if (uVar7 < uVar10) break;
          }
          uVar8 = *puVar15;
        } while( true );
      }
      puVar15 = (ulong *)puVar15[0xd];
    } while (*(ulong **)(param_1 + 0xa0) != puVar15);
    goto LAB_004f1d3e;
  }
  if ((uVar5 & 0x10) != 0) {
    if (uVar12 % param_6 != 0) {
      return 0x51;
    }
    puVar9 = *(ulong **)(param_1 + 0xa0);
    if (puVar9 == (ulong *)0x0) {
      return 0x51;
    }
    uVar10 = (uVar12 - 1) + uVar17;
    puVar15 = puVar9;
LAB_004f1f70:
    puVar15 = (ulong *)puVar15[0xd];
    if ((uVar12 < *puVar15) || (puVar15[1] < uVar10)) goto LAB_004f1f8c;
    if (*(char *)(param_1 + 0x90) != '\0') {
      if (param_10 == 0) {
        nvAssertFailedNoLog("NULL != checker","src/libraries/containers/eheap/eheap_old.c",0x1c4);
      }
      cVar4 = _eheapCheckOwnership(param_1,param_9,uVar12,uVar10,puVar15,param_10);
      if (cVar4 == '\0') {
        return 0x51;
      }
      uVar8 = *puVar15;
LAB_004f2077:
      if (uVar12 == uVar8) goto LAB_004f22a8;
      puVar11 = local_48;
      if (uVar8 <= uVar12) goto LAB_004f2118;
      goto LAB_004f208a;
    }
    if ((*puVar15 != uVar12) || (uVar10 != puVar15[1])) goto LAB_004f2125;
    goto LAB_004f22b5;
  }
  puVar9 = *(ulong **)(param_1 + 0xa0);
  if (puVar9 == (ulong *)0x0) {
    return 0x51;
  }
  if ((uVar5 & 4) != 0) {
    puVar9 = (ulong *)puVar9[0xc];
  }
  puVar15 = puVar9;
LAB_004f1f1b:
  uVar12 = puVar15[1];
  if ((uVar12 < uVar14) || (uVar7 = *puVar15, uVar8 < uVar7)) {
    puVar11 = puVar15 + 0xd;
    if ((uVar5 & 4) != 0) {
      puVar11 = puVar15 + 0xc;
    }
    puVar15 = (ulong *)*puVar11;
    goto LAB_004f1f12;
  }
  if ((uVar5 & 4) == 0) {
    uVar12 = uVar14;
    if (uVar14 <= uVar7) {
      uVar12 = uVar7;
    }
    uVar12 = (param_6 - 1) + uVar12;
    uVar12 = uVar12 - uVar12 % param_6;
  }
  else {
    if (uVar8 < uVar12) {
      uVar12 = uVar8;
    }
    uVar12 = uVar12 + (1 - uVar17);
    uVar12 = uVar12 - uVar12 % param_6;
  }
  uVar10 = uVar12 + (uVar17 - 1);
  if (*(char *)(param_1 + 0x90) == '\0') {
LAB_004f1ee0:
    if ((((uVar7 <= uVar12) && (uVar10 <= puVar15[1])) && (uVar12 <= uVar10)) &&
       ((uVar14 <= uVar12 && (uVar10 <= uVar8)))) {
      if (uVar12 != uVar7) goto LAB_004f2118;
LAB_004f22a8:
      uVar8 = puVar15[1];
      if (uVar10 == uVar8) {
LAB_004f22b5:
        uVar8 = puVar15[0xc];
        *(ulong *)(puVar15[0xd] + 0x60) = uVar8;
        puVar9 = (ulong *)puVar15[0xd];
        *(ulong **)(uVar8 + 0x68) = puVar9;
        if (*(ulong **)(param_1 + 0xa0) == puVar15) {
          if (puVar9 == puVar15) {
            puVar9 = (ulong *)0x0;
          }
          *(ulong **)(param_1 + 0xa0) = puVar9;
        }
        *(undefined4 *)((long)puVar15 + 0x1c) = 1;
        puVar15[2] = uVar12;
        *(undefined4 *)(puVar15 + 4) = param_2;
        goto LAB_004f2093;
      }
      goto LAB_004f211c;
    }
LAB_004f1f00:
    uVar5 = *param_3;
    if ((uVar5 & 4) == 0) {
LAB_004f1fd0:
      puVar15 = (ulong *)puVar15[0xd];
      goto LAB_004f1f12;
    }
  }
  else {
    if (param_10 == 0) {
      nvAssertFailedNoLog("NULL != checker","src/libraries/containers/eheap/eheap_old.c",0x214);
    }
    cVar4 = _eheapCheckOwnership(param_1,param_9,uVar12,uVar10,puVar15,param_10);
    if (cVar4 != '\0') {
      uVar7 = *puVar15;
      goto LAB_004f1ee0;
    }
    uVar7 = -(ulong)*(uint *)(param_1 + 0x94);
    uVar5 = *param_3;
    if ((uVar5 & 4) == 0) {
      uVar7 = uVar7 & uVar10 + (*(uint *)(param_1 + 0x94) - 1);
      if (uVar7 < puVar15[1]) {
        uVar12 = (uVar7 - 1) + param_6;
        goto LAB_004f1ea7;
      }
      goto LAB_004f1fd0;
    }
    uVar7 = uVar7 & uVar12;
    if (*puVar15 < uVar7) {
      uVar12 = (uVar7 - uVar17) + 1;
LAB_004f1ea7:
      uVar12 = uVar12 - uVar12 % param_6;
      uVar10 = uVar12 + (uVar17 - 1);
      cVar4 = _eheapCheckOwnership(param_1,param_9,uVar12,uVar10,puVar15,param_10);
      if (cVar4 != '\0') {
        uVar7 = *puVar15;
        goto LAB_004f1ee0;
      }
      goto LAB_004f1f00;
    }
  }
  puVar15 = (ulong *)puVar15[0xc];
LAB_004f1f12:
  puVar11 = local_48;
  if (puVar9 == puVar15) goto LAB_004f2028;
  goto LAB_004f1f1b;
LAB_004f1f8c:
  if (puVar9 == puVar15) goto LAB_004f1d3e;
  goto LAB_004f1f70;
LAB_004f2118:
  uVar8 = puVar15[1];
LAB_004f211c:
  puVar11 = local_48;
  if (uVar8 < uVar10) {
LAB_004f208a:
    puVar15 = puVar11;
    if (puVar11 == (ulong *)0x0) {
      nvAssertFailedNoLog("blockNew != NULL","src/libraries/containers/eheap/eheap_old.c",0x338);
    }
    goto LAB_004f2093;
  }
LAB_004f2125:
  iVar6 = _eheapAllocMemStruct(param_1,&local_48);
  puVar11 = local_48;
  if (iVar6 == 0) {
    *(undefined4 *)((long)local_48 + 0x1c) = 1;
    *local_48 = uVar12;
    *(undefined4 *)(local_48 + 4) = param_2;
    local_48[2] = uVar12;
    local_48[1] = uVar10;
    uVar8 = puVar15[1];
    if (*puVar15 < uVar12) {
      if (uVar10 < uVar8) {
        iVar6 = _eheapAllocMemStruct(param_1,local_40);
        if (iVar6 == 0) {
          lVar1 = param_1 + 0xb8;
          iVar6 = btreeUnlink(puVar15 + 5,lVar1);
          plVar3 = local_40[0];
          if (iVar6 == 0) {
            *(undefined8 *)((long)local_40[0] + 0x1c) = 0xffffffff00000000;
            uVar12 = puVar11[1];
            *local_40[0] = uVar12 + 1;
            local_40[0][2] = uVar12 + 1;
            local_40[0][1] = puVar15[1];
            local_40[0][0x10] = (long)(puVar11 + 0x11);
            puVar15[1] = *puVar11 - 1;
            uVar12 = puVar15[0xd];
            local_40[0][0xc] = (long)puVar15;
            local_40[0][0xd] = uVar12;
            *(long **)(uVar12 + 0x60) = local_40[0];
            puVar15[0xd] = (ulong)local_40[0];
            puVar11[0xf] = (ulong)local_40[0];
            puVar11[0xe] = (ulong)puVar15;
            uVar12 = puVar15[0xf];
            local_40[0][0xe] = (long)puVar11;
            local_40[0][0xf] = uVar12;
            puVar15[0xf] = (ulong)puVar11;
            *(long **)(local_40[0][0xf] + 0x70) = local_40[0];
            *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
            puVar15[7] = puVar15[1];
            iVar6 = btreeInsert(puVar15 + 5,lVar1);
            if (iVar6 == 0) {
              portMemSet(puVar11 + 5,0,0x38);
              portMemSet(plVar3 + 5,0,0x38);
              puVar11[5] = (ulong)puVar11;
              puVar11[6] = *puVar11;
              puVar11[7] = puVar11[1];
              plVar3[5] = (long)plVar3;
              plVar3[6] = *plVar3;
              plVar3[7] = plVar3[1];
              iVar6 = btreeInsert(puVar11 + 5,lVar1);
              if ((iVar6 == 0) && (iVar6 = btreeInsert(plVar3 + 5,lVar1), iVar6 == 0)) {
                *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
                goto LAB_004f208a;
              }
            }
            goto LAB_004f2031;
          }
        }
        goto LAB_004f2028;
      }
      if (uVar10 == uVar8) goto LAB_004f2182;
    }
    else {
      if (uVar10 == uVar8) {
LAB_004f2182:
        iVar6 = btreeUnlink(puVar15 + 5,param_1 + 0xb8);
        if (iVar6 != 0) goto LAB_004f2028;
        puVar15[1] = *puVar11 - 1;
        uVar12 = puVar15[0xf];
        puVar11[0xe] = (ulong)puVar15;
        puVar11[0xf] = uVar12;
        *(ulong **)(puVar15[0xf] + 0x70) = puVar11;
        puVar15[0xf] = (ulong)puVar11;
        puVar15[7] = puVar15[1];
        iVar6 = btreeInsert(puVar15 + 5,param_1 + 0xb8);
        if (iVar6 != 0) goto LAB_004f2031;
        portMemSet(puVar11 + 5,0,0x38);
        puVar11[5] = (ulong)puVar11;
        puVar11[6] = *puVar11;
        puVar11[7] = puVar11[1];
      }
      else {
        if (*puVar15 != uVar12) goto LAB_004f2031;
        lVar1 = param_1 + 0xb8;
        puVar9 = puVar15 + 5;
        iVar6 = btreeUnlink(puVar9,lVar1);
        if (iVar6 != 0) goto LAB_004f2028;
        uVar12 = puVar11[1];
        *puVar15 = uVar12 + 1;
        puVar15[2] = uVar12 + 1;
        puVar11[0xf] = (ulong)puVar15;
        uVar12 = puVar15[0xe];
        puVar11[0xe] = uVar12;
        *(ulong **)(uVar12 + 0x78) = puVar11;
        puVar15[0xe] = (ulong)puVar11;
        if (*(ulong **)(param_1 + 0x98) == puVar15) {
          *(ulong **)(param_1 + 0x98) = puVar11;
          puVar15[6] = *puVar15;
          iVar6 = btreeInsert(puVar9,lVar1);
          if (iVar6 != 0) goto LAB_004f2028;
        }
        else {
          puVar15[6] = *puVar15;
          iVar6 = btreeInsert(puVar9,lVar1);
          if (iVar6 != 0) goto LAB_004f2031;
        }
        portMemSet(puVar11 + 5,0,0x38);
        puVar11[5] = (ulong)puVar11;
        puVar11[6] = *puVar11;
        puVar11[7] = puVar11[1];
      }
      iVar6 = btreeInsert(puVar11 + 5,param_1 + 0xb8);
      if (iVar6 == 0) {
        *(int *)(param_1 + 0xac) = *(int *)(param_1 + 0xac) + 1;
        puVar15 = puVar11;
LAB_004f2093:
        *(ulong *)(param_1 + 0x78) = (*(long *)(param_1 + 0x78) + -1 + *puVar15) - puVar15[1];
        puVar15[0x10] = (ulong)(puVar15 + 0x11);
        *param_5 = uVar17;
        *param_4 = puVar15[2];
        if (param_8 != (undefined8 *)0x0) {
          *param_8 = puVar15;
        }
        return 0;
      }
    }
  }
  else {
LAB_004f2028:
    if (puVar11 == (ulong *)0x0) goto LAB_004f1d3e;
  }
LAB_004f2031:
  if (*(int *)(param_1 + 0xc0) == 0) {
    portMemFree(puVar11);
  }
  else {
    portMemSet(puVar11,0,*(undefined4 *)(param_1 + 0xb0));
    puVar11[0xf] = *(ulong *)(param_1 + 200);
    *(ulong **)(param_1 + 200) = puVar11;
  }
LAB_004f1d3e:
  plVar3 = local_40[0];
  if (local_40[0] != (long *)0x0) {
    if (*(int *)(param_1 + 0xc0) == 0) {
      portMemFree(local_40[0]);
    }
    else {
      portMemSet(local_40[0],0,*(undefined4 *)(param_1 + 0xb0));
      plVar3[0xf] = *(long *)(param_1 + 200);
      *(long **)(param_1 + 200) = plVar3;
    }
  }
  return 0x51;
}


// ===== 004f2640 constructObjEHeap =====

void constructObjEHeap(undefined8 *param_1,long param_2,long param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long *local_30;
  
  *param_1 = eheapDestruct;
  param_1[1] = eheapAlloc;
  param_1[2] = eheapFree;
  param_1[3] = eheapInfo;
  param_1[4] = eheapInfoForRange;
  param_1[5] = eheapGetSize;
  param_1[6] = eheapGetFree;
  param_1[7] = eheapGetBase;
  param_1[8] = eheapGetBlock;
  param_1[9] = eheapSetAllocRange;
  param_1[10] = eheapTraverse;
  param_1[0xb] = eheapGetNumBlocks;
  param_1[0xc] = eheapSetOwnerIsolation;
  param_1[0xd] = param_2;
  param_1[0xe] = param_3 - param_2;
  param_1[0x10] = param_2;
  param_1[0x11] = param_3 + -1;
  param_1[0xf] = param_3 - param_2;
  *(int *)(param_1 + 0x16) = param_4 + 0x88;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[0x1a] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x19] = 0;
  *(undefined4 *)((long)param_1 + 0xac) = 0;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined4 *)((long)param_1 + 0x94) = 0;
  if (param_5 != 0) {
    iVar1 = param_5 + 1;
    lVar3 = portMemAllocNonPaged((param_4 + 0x88) * iVar1);
    param_1[0x1a] = lVar3;
    if (lVar3 != 0) {
      param_1[0x19] = lVar3;
      *(int *)(param_1 + 0x18) = iVar1;
      portMemSet(lVar3,0,iVar1 * *(int *)(param_1 + 0x16));
      iVar1 = 0;
      do {
        iVar1 = iVar1 + 1;
        uVar2 = iVar1 * *(int *)(param_1 + 0x16);
        *(ulong *)(param_1[0x19] + 0x78 + (ulong)(uVar2 - *(int *)(param_1 + 0x16))) =
             (ulong)uVar2 + param_1[0x19];
      } while (param_5 != iVar1);
    }
  }
  iVar1 = _eheapAllocMemStruct(param_1,&local_30);
  if (iVar1 == 0) {
    *(undefined8 *)((long)local_30 + 0x1c) = 0xffffffff00000000;
    *local_30 = param_2;
    local_30[2] = param_2;
    local_30[1] = param_3 + -1;
    local_30[0xc] = (long)local_30;
    local_30[0xd] = (long)local_30;
    local_30[0xf] = (long)local_30;
    local_30[0xe] = (long)local_30;
    local_30[0x10] = (long)(local_30 + 0x11);
    param_1[0x13] = local_30;
    param_1[0x14] = local_30;
    *(undefined4 *)((long)param_1 + 0xac) = 1;
    portMemSet(local_30 + 5,0,0x38);
    local_30[5] = (long)local_30;
    local_30[6] = *local_30;
    local_30[7] = local_30[1];
    iVar1 = btreeInsert(local_30 + 5,param_1 + 0x17);
    if ((iVar1 != 0) && (param_1[0x13] != 0)) {
      eheapDestruct_part_0(param_1);
      return;
    }
  }
  return;
}


// ===== 004f28e0 listInit_IMPL =====

void listInit_IMPL(long param_1,long param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x25);
    return;
  }
  if (param_2 != 0) {
    portMemSet(param_1,0,0x18);
    *(long *)(param_1 + 0x18) = param_2;
    *(undefined4 *)(param_1 + 0x20) = param_3;
    *(undefined4 *)(param_1 + 0x14) = 0xfffffff0;
    return;
  }
  nvAssertFailedNoLog("NULL != pAllocator","src/libraries/containers/list.c",0x26);
  return;
}


// ===== 004f2970 listInitIntrusive_IMPL =====

void listInitIntrusive_IMPL(long param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    portMemSet(param_1,0,0x18);
    *(undefined4 *)(param_1 + 0x14) = param_2;
    return;
  }
  nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x31);
  return;
}


// ===== 004f29c0 listDestroy_IMPL =====

void listDestroy_IMPL(undefined8 *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  puVar3 = (undefined8 *)*param_1;
  param_1[1] = 0;
  lVar1 = param_1[3];
  *param_1 = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  do {
    if (puVar3 == (undefined8 *)0x0) {
      return;
    }
    puVar2 = (undefined8 *)puVar3[1];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar4 = puVar3;
    puVar3 = puVar2;
  } while (lVar1 == 0);
  while (puVar3 = puVar2, _portMemAllocatorFree(lVar1,puVar4), puVar3 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)puVar3[1];
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar4 = puVar3;
  }
  return;
}


// ===== 004f2a60 listDestroyIntrusive_IMPL =====

void listDestroyIntrusive_IMPL(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (param_1 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_1;
    param_1[1] = 0;
    *param_1 = 0;
    *(undefined4 *)(param_1 + 2) = 0;
    while (puVar1 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)puVar1[1];
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1 = puVar2;
    }
    return;
  }
  nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x3b);
  return;
}


// ===== 004f2ae0 listCount_IMPL =====

undefined4 listCount_IMPL(long param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x10);
  }
  nvAssertFailedNoLog("pList","src/libraries/containers/list.c",0x5e);
  return 0;
}


// ===== 004f2b10 listInsertNew_IMPL =====

long listInsertNew_IMPL(undefined8 *param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  long *plVar4;
  long *plVar5;
  
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x67);
    return 0;
  }
  plVar4 = (long *)_portMemAllocatorAlloc(param_1[3],(ulong)*(uint *)(param_1 + 4) + 0x10);
  if (plVar4 != (long *)0x0) {
    portMemSet(plVar4,0,(ulong)*(uint *)(param_1 + 4) + 0x10);
    iVar1 = *(int *)((long)param_1 + 0x14);
    if (param_2 == 0) {
      lVar2 = param_1[1];
      plVar4[1] = 0;
      *plVar4 = lVar2;
    }
    else {
      plVar5 = (long *)(param_2 + iVar1);
      lVar2 = *plVar5;
      plVar4[1] = (long)plVar5;
      *plVar4 = lVar2;
    }
    if (lVar2 == 0) {
      *param_1 = plVar4;
      puVar3 = (undefined8 *)plVar4[1];
    }
    else {
      *(long **)(lVar2 + 8) = plVar4;
      puVar3 = (undefined8 *)plVar4[1];
    }
    if (puVar3 == (undefined8 *)0x0) {
      param_1[1] = plVar4;
    }
    else {
      *puVar3 = plVar4;
    }
    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
    return (long)plVar4 - (long)iVar1;
  }
  nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/list.c",0x6a);
  return 0;
}


// ===== 004f2c30 listAppendNew_IMPL =====

void listAppendNew_IMPL(undefined8 param_1)

{
  listInsertNew_IMPL(param_1,0);
  return;
}


// ===== 004f2c40 listPrependNew_IMPL =====

void listPrependNew_IMPL(long *param_1)

{
  long lVar1;
  
  if (param_1 != (long *)0x0) {
    lVar1 = *param_1;
    if (lVar1 != 0) {
      lVar1 = lVar1 - *(int *)((long)param_1 + 0x14);
    }
    listInsertNew_IMPL(param_1,lVar1);
    return;
  }
  nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x11c);
  listInsertNew_IMPL(0,0);
  return;
}


// ===== 004f2cb0 listInsertValue_IMPL =====

undefined8 listInsertValue_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/list.c",0x86);
    return 0;
  }
  lVar1 = listInsertNew_IMPL();
  if (lVar1 != 0) {
    uVar2 = portMemCopy(lVar1,*(undefined4 *)(param_1 + 0x20),param_3,
                        *(undefined4 *)(param_1 + 0x20));
    return uVar2;
  }
  return 0;
}


// ===== 004f2d20 listAppendValue_IMPL =====

undefined8 listAppendValue_IMPL(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/list.c",0x86);
    return 0;
  }
  lVar1 = listInsertNew_IMPL(param_1,0);
  if (lVar1 != 0) {
    uVar2 = portMemCopy(lVar1,*(undefined4 *)(param_1 + 0x20),param_2,
                        *(undefined4 *)(param_1 + 0x20));
    return uVar2;
  }
  return 0;
}


// ===== 004f2da0 listPrependValue_IMPL =====

undefined8 listPrependValue_IMPL(long *param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x11c);
    lVar1 = 0;
  }
  else {
    lVar1 = *param_1;
    if (lVar1 != 0) {
      lVar1 = lVar1 - *(int *)((long)param_1 + 0x14);
    }
  }
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/list.c",0x86);
  }
  else {
    lVar1 = listInsertNew_IMPL(param_1,lVar1);
    if (lVar1 != 0) {
      uVar2 = portMemCopy(lVar1,(int)param_1[4],param_2,(int)param_1[4]);
      return uVar2;
    }
  }
  return 0;
}


// ===== 004f2e50 listInsertExisting_IMPL =====

void listInsertExisting_IMPL(undefined8 *param_1,long param_2,long param_3)

{
  long lVar1;
  undefined8 *puVar2;
  long *plVar3;
  long *plVar4;
  
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x9b);
    return;
  }
  if (param_3 != 0) {
    plVar3 = (long *)(param_3 + *(int *)((long)param_1 + 0x14));
    if (param_2 == 0) {
      lVar1 = param_1[1];
      plVar3[1] = 0;
      *plVar3 = lVar1;
    }
    else {
      plVar4 = (long *)(param_2 + *(int *)((long)param_1 + 0x14));
      lVar1 = *plVar4;
      plVar3[1] = (long)plVar4;
      *plVar3 = lVar1;
    }
    if (lVar1 == 0) {
      *param_1 = plVar3;
      puVar2 = (undefined8 *)plVar3[1];
    }
    else {
      *(long **)(lVar1 + 8) = plVar3;
      puVar2 = (undefined8 *)plVar3[1];
    }
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = plVar3;
      *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
      return;
    }
    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
    param_1[1] = plVar3;
    return;
  }
  nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/list.c",0x9c);
  return;
}


// ===== 004f2f00 listAppendExisting_IMPL =====

void listAppendExisting_IMPL(undefined8 *param_1,long param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long *plVar3;
  
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x9b);
    return;
  }
  if (param_2 != 0) {
    plVar3 = (long *)(param_2 + *(int *)((long)param_1 + 0x14));
    lVar1 = param_1[1];
    plVar3[1] = 0;
    *plVar3 = lVar1;
    if (lVar1 == 0) {
      *param_1 = plVar3;
      puVar2 = (undefined8 *)plVar3[1];
    }
    else {
      *(long **)(lVar1 + 8) = plVar3;
      puVar2 = (undefined8 *)plVar3[1];
    }
    if (puVar2 != (undefined8 *)0x0) {
      *puVar2 = plVar3;
      *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
      return;
    }
    *(int *)(param_1 + 2) = *(int *)(param_1 + 2) + 1;
    param_1[1] = plVar3;
    return;
  }
  nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/list.c",0x9c);
  return;
}


// ===== 004f2f90 listPrependExisting_IMPL =====

void listPrependExisting_IMPL(long *param_1,undefined8 param_2)

{
  long lVar1;
  
  if (param_1 != (long *)0x0) {
    lVar1 = *param_1;
    if (lVar1 != 0) {
      lVar1 = lVar1 - *(int *)((long)param_1 + 0x14);
    }
    listInsertExisting_IMPL(param_1,lVar1,param_2);
    return;
  }
  nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x11c);
  listInsertExisting_IMPL(0,0,param_2);
  return;
}


// ===== 004f3010 listRemoveIntrusive_IMPL =====

void listRemoveIntrusive_IMPL(long *param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  
  if (param_2 == 0) {
    return;
  }
  if (param_1 != (long *)0x0) {
    plVar3 = (long *)(param_2 + *(int *)((long)param_1 + 0x14));
    if (*plVar3 == 0) {
      *param_1 = plVar3[1];
      plVar1 = (long *)plVar3[1];
      lVar2 = *plVar3;
    }
    else {
      *(long *)(*plVar3 + 8) = plVar3[1];
      plVar1 = (long *)plVar3[1];
      lVar2 = *plVar3;
    }
    if (plVar1 == (long *)0x0) {
      param_1[1] = lVar2;
    }
    else {
      *plVar1 = lVar2;
    }
    plVar3[1] = 0;
    *plVar3 = 0;
    *(int *)(param_1 + 2) = (int)param_1[2] + -1;
    return;
  }
  nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/list.c",0xc0);
  return;
}


// ===== 004f3090 listRemove_IMPL =====

void listRemove_IMPL(long param_1,long param_2)

{
  long lVar1;
  
  if (param_2 != 0) {
    listRemoveIntrusive_IMPL();
    lVar1 = 0;
    if (param_1 != 0) {
      lVar1 = *(int *)(param_1 + 0x14) + param_2;
    }
    _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),lVar1);
    return;
  }
  return;
}


// ===== 004f30e0 listFindByValue_IMPL =====

long listFindByValue_IMPL(long *param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x106);
    return 0;
  }
  if (param_2 == 0) {
    lVar3 = 0;
    nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/list.c",0x107);
  }
  else {
    lVar1 = *param_1;
    while( true ) {
      if (lVar1 == 0) {
        return 0;
      }
      lVar3 = lVar1 - *(int *)((long)param_1 + 0x14);
      iVar2 = portMemCmp(lVar3,param_2,(int)param_1[4]);
      if (iVar2 == 0) break;
      lVar1 = *(long *)(lVar1 + 8);
    }
  }
  return lVar3;
}


// ===== 004f31d0 listRemoveFirstByValue_IMPL =====

void listRemoveFirstByValue_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = listFindByValue_IMPL();
  if (lVar1 != 0) {
    listRemoveIntrusive_IMPL(param_1,lVar1);
    lVar2 = 0;
    if (param_1 != 0) {
      lVar2 = *(int *)(param_1 + 0x14) + lVar1;
    }
    _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x18),lVar2);
    return;
  }
  return;
}


// ===== 004f3230 listHead_IMPL =====

long listHead_IMPL(long *param_1)

{
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x11c);
    return 0;
  }
  if (*param_1 != 0) {
    return *param_1 - (long)*(int *)((long)param_1 + 0x14);
  }
  return 0;
}


// ===== 004f3280 listTail_IMPL =====

long listTail_IMPL(long param_1)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x125);
    return 0;
  }
  if (*(long *)(param_1 + 8) != 0) {
    return *(long *)(param_1 + 8) - (long)*(int *)(param_1 + 0x14);
  }
  return 0;
}


// ===== 004f32d0 listNext_IMPL =====

long listNext_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    lVar1 = *(long *)(param_2 + 8 + (long)*(int *)(param_1 + 0x14));
    lVar2 = (long)*(int *)(param_1 + 0x14);
    if (lVar1 == 0) {
      lVar2 = 0;
    }
    return lVar1 - lVar2;
  }
  nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/list.c",0x130);
  return 0;
}


// ===== 004f3320 listPrev_IMPL =====

long listPrev_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    lVar1 = *(long *)(param_2 + *(int *)(param_1 + 0x14));
    lVar2 = (long)*(int *)(param_1 + 0x14);
    if (lVar1 == 0) {
      lVar2 = 0;
    }
    return lVar1 - lVar2;
  }
  nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/list.c",0x13c);
  return 0;
}


// ===== 004f3370 listIterRange_IMPL =====

void listIterRange_IMPL(undefined8 *param_1,long param_2,long param_3,long param_4)

{
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pList","src/libraries/containers/list.c",0x14a);
    param_3 = 0;
    param_4 = 0;
  }
  else {
    if (param_3 != 0) {
      param_3 = param_3 + *(int *)(param_2 + 0x14);
    }
    if (param_4 != 0) {
      param_4 = param_4 + *(int *)(param_2 + 0x14);
    }
  }
  *param_1 = 0;
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[3] = param_4;
  return;
}


// ===== 004f33f0 listIterNext_IMPL =====

undefined8 listIterNext_IMPL(long *param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pIt","src/libraries/containers/list.c",0x15c);
    return 0;
  }
  lVar1 = param_1[2];
  if (lVar1 != 0) {
    lVar2 = 0;
    if (param_1[1] != 0) {
      lVar2 = lVar1 - *(int *)(param_1[1] + 0x14);
    }
    *param_1 = lVar2;
    if (lVar1 != param_1[3]) {
      param_1[2] = *(long *)(lVar1 + 8);
      return 1;
    }
    param_1[2] = 0;
    return 1;
  }
  return 0;
}


// ===== 004f3470 _mapDestroy =====

void _mapDestroy(long *param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0x55);
    return;
  }
  lVar4 = *param_1;
  if (lVar4 == 0) {
    *param_1 = 0;
    *(undefined4 *)((long)param_1 + 0xc) = 0;
    return;
  }
LAB_004f34a0:
  do {
    do {
      do {
        plVar1 = (long *)(lVar4 + 0x10);
        lVar2 = lVar4;
        lVar4 = *plVar1;
      } while (*plVar1 != 0);
      do {
        lVar3 = lVar2;
        lVar2 = *(long *)(lVar3 + 0x18);
      } while (*(long *)(lVar3 + 0x18) != 0);
      lVar4 = lVar3;
    } while (*(long *)(lVar3 + 0x10) != 0);
    lVar4 = *(long *)(lVar3 + 8);
    if (lVar4 == 0) {
      if (param_2 != 0) {
        _portMemAllocatorFree(param_2);
      }
      *param_1 = 0;
      *(undefined4 *)((long)param_1 + 0xc) = 0;
      return;
    }
    if (*(long *)(lVar4 + 0x10) == lVar3) goto LAB_004f3531;
    *(undefined8 *)(lVar4 + 0x18) = 0;
    *(undefined8 *)(lVar3 + 8) = 0;
  } while (param_2 == 0);
  goto LAB_004f34e7;
LAB_004f3531:
  *(undefined8 *)(lVar4 + 0x10) = 0;
  *(undefined8 *)(lVar3 + 8) = 0;
  if (param_2 != 0) {
LAB_004f34e7:
    _portMemAllocatorFree(param_2);
  }
  goto LAB_004f34a0;
}


// ===== 004f3560 _mapInsertBase =====

undefined8 _mapInsertBase(ulong *param_1,ulong param_2,ulong *param_3)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  ulong uVar7;
  
  if (param_3 != (ulong *)0x0) {
    param_3 = (ulong *)((long)param_3 + (long)(int)param_1[1]);
  }
  puVar5 = (ulong *)*param_1;
  if ((ulong *)*param_1 == (ulong *)0x0) {
    *param_3 = param_2;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    *(undefined1 *)(param_3 + 4) = 1;
    *param_1 = (ulong)param_3;
  }
  else {
    do {
      puVar6 = puVar5;
      if (param_2 < *puVar6) {
        puVar5 = (ulong *)puVar6[2];
      }
      else {
        if (param_2 <= *puVar6) {
          return 0;
        }
        puVar5 = (ulong *)puVar6[3];
      }
    } while (puVar5 != (ulong *)0x0);
    *param_3 = param_2;
    param_3[1] = (ulong)puVar6;
    param_3[2] = 0;
    param_3[3] = 0;
    *(undefined1 *)(param_3 + 4) = 1;
    if (param_2 < *puVar6) {
      puVar6[2] = (ulong)param_3;
    }
    else {
      puVar6[3] = (ulong)param_3;
    }
    puVar5 = (ulong *)*param_1;
    if (puVar5 != param_3) {
      do {
        while( true ) {
          puVar6 = (ulong *)param_3[1];
          if ((char)puVar6[4] == '\0') goto LAB_004f36af;
          uVar7 = puVar6[1];
          puVar5 = *(ulong **)(uVar7 + 0x10);
          if (puVar6 == puVar5) break;
          if ((puVar5 == (ulong *)0x0) || ((char)puVar5[4] == '\0')) {
            puVar4 = param_3;
            if ((ulong *)puVar6[2] == param_3) {
              uVar3 = param_3[3];
              puVar6[2] = uVar3;
              if (uVar3 != 0) {
                *(ulong **)(uVar3 + 8) = puVar6;
                uVar7 = puVar6[1];
              }
              param_3[1] = uVar7;
              if (uVar7 == 0) {
                *param_1 = (ulong)param_3;
              }
              else if (puVar6 == *(ulong **)(uVar7 + 0x18)) {
                *(ulong **)(uVar7 + 0x18) = param_3;
              }
              else {
                *(ulong **)(uVar7 + 0x10) = param_3;
              }
              param_3[3] = (ulong)puVar6;
              puVar6[1] = (ulong)param_3;
              puVar4 = puVar6;
              puVar6 = param_3;
            }
            *(undefined1 *)(puVar6 + 4) = 0;
            *(undefined1 *)(*(long *)(puVar4[1] + 8) + 0x20) = 1;
            lVar1 = *(long *)(puVar4[1] + 8);
            uVar7 = *(ulong *)(lVar1 + 0x18);
            lVar2 = *(long *)(uVar7 + 0x10);
            *(long *)(lVar1 + 0x18) = lVar2;
            if (lVar2 != 0) {
              *(long *)(lVar2 + 8) = lVar1;
            }
            lVar2 = *(long *)(lVar1 + 8);
            *(long *)(uVar7 + 8) = lVar2;
            if (lVar2 == 0) {
              *param_1 = uVar7;
            }
            else if (lVar1 == *(long *)(lVar2 + 0x10)) {
              *(ulong *)(lVar2 + 0x10) = uVar7;
            }
            else {
              *(ulong *)(lVar2 + 0x18) = uVar7;
            }
            *(long *)(uVar7 + 0x10) = lVar1;
            *(ulong *)(lVar1 + 8) = uVar7;
          }
          else {
LAB_004f35f3:
            *(undefined1 *)(puVar6 + 4) = 0;
            *(undefined1 *)(puVar5 + 4) = 0;
            *(undefined1 *)(*(long *)(param_3[1] + 8) + 0x20) = 1;
            puVar4 = *(ulong **)(param_3[1] + 8);
          }
          puVar5 = (ulong *)*param_1;
          param_3 = puVar4;
          if (puVar4 == puVar5) goto LAB_004f36af;
        }
        puVar5 = *(ulong **)(uVar7 + 0x18);
        if ((puVar5 != (ulong *)0x0) && ((char)puVar5[4] != '\0')) goto LAB_004f35f3;
        puVar4 = param_3;
        if ((ulong *)puVar6[3] == param_3) {
          uVar3 = param_3[2];
          puVar6[3] = uVar3;
          if (uVar3 != 0) {
            *(ulong **)(uVar3 + 8) = puVar6;
            uVar7 = puVar6[1];
          }
          param_3[1] = uVar7;
          if (uVar7 == 0) {
            *param_1 = (ulong)param_3;
          }
          else if (puVar6 == *(ulong **)(uVar7 + 0x10)) {
            *(ulong **)(uVar7 + 0x10) = param_3;
          }
          else {
            *(ulong **)(uVar7 + 0x18) = param_3;
          }
          param_3[2] = (ulong)puVar6;
          puVar6[1] = (ulong)param_3;
          puVar4 = puVar6;
          puVar6 = param_3;
        }
        *(undefined1 *)(puVar6 + 4) = 0;
        *(undefined1 *)(*(long *)(puVar4[1] + 8) + 0x20) = 1;
        lVar1 = *(long *)(puVar4[1] + 8);
        uVar7 = *(ulong *)(lVar1 + 0x10);
        lVar2 = *(long *)(uVar7 + 0x18);
        *(long *)(lVar1 + 0x10) = lVar2;
        if (lVar2 != 0) {
          *(long *)(lVar2 + 8) = lVar1;
        }
        lVar2 = *(long *)(lVar1 + 8);
        *(long *)(uVar7 + 8) = lVar2;
        if (lVar2 == 0) {
          *param_1 = uVar7;
        }
        else if (lVar1 == *(long *)(lVar2 + 0x18)) {
          *(ulong *)(lVar2 + 0x18) = uVar7;
        }
        else {
          *(ulong *)(lVar2 + 0x10) = uVar7;
        }
        *(long *)(uVar7 + 0x18) = lVar1;
        *(ulong *)(lVar1 + 8) = uVar7;
        puVar5 = (ulong *)*param_1;
        param_3 = puVar4;
      } while (puVar4 != puVar5);
LAB_004f36af:
      *(undefined1 *)(puVar5 + 4) = 0;
      *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + 1;
      return 1;
    }
  }
  *(undefined1 *)(param_3 + 4) = 0;
  *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + 1;
  return 1;
}


// ===== 004f3840 mapInit_IMPL =====

void mapInit_IMPL(long param_1,long param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0x3c);
    return;
  }
  if (param_2 != 0) {
    portMemSet(param_1,0,0x10);
    *(long *)(param_1 + 0x10) = param_2;
    *(undefined4 *)(param_1 + 0x18) = param_3;
    *(undefined4 *)(param_1 + 8) = 0xffffffd8;
    return;
  }
  nvAssertFailedNoLog("NULL != pAllocator","src/libraries/containers/map.c",0x3d);
  return;
}


// ===== 004f38d0 mapInitIntrusive_IMPL =====

void mapInitIntrusive_IMPL(long param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    portMemSet(param_1,0,0x10);
    *(undefined4 *)(param_1 + 8) = param_2;
    return;
  }
  nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0x4b);
  return;
}


// ===== 004f3920 mapDestroy_IMPL =====

void mapDestroy_IMPL(long param_1)

{
  _mapDestroy(param_1,*(undefined8 *)(param_1 + 0x10));
  return;
}


// ===== 004f3930 mapDestroyIntrusive_IMPL =====

void mapDestroyIntrusive_IMPL(undefined8 param_1)

{
  _mapDestroy(param_1,0);
  return;
}


// ===== 004f3940 mapCount_IMPL =====

undefined4 mapCount_IMPL(long param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0xc);
  }
  nvAssertFailedNoLog(&DAT_00da37a7,"src/libraries/containers/map.c",0x93);
  return 0;
}


// ===== 004f3970 mapKey_IMPL =====

undefined8 mapKey_IMPL(long param_1,long param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    return *(undefined8 *)(param_2 + *(int *)(param_1 + 8));
  }
  nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0x9e);
  return 0;
}


// ===== 004f39b0 mapInsertNew_IMPL =====

long mapInsertNew_IMPL(long param_1,undefined8 param_2)

{
  char cVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0xac);
    return 0;
  }
  lVar2 = _portMemAllocatorAlloc
                    (*(undefined8 *)(param_1 + 0x10),(ulong)*(uint *)(param_1 + 0x18) + 0x28);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0xaf);
    lVar3 = 0;
  }
  else {
    portMemSet(lVar2,0,(ulong)*(uint *)(param_1 + 0x18) + 0x28);
    lVar3 = lVar2 - *(int *)(param_1 + 8);
    cVar1 = _mapInsertBase(param_1,param_2,lVar3);
    if (cVar1 == '\0') {
      _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x10),lVar2);
      lVar3 = 0;
    }
  }
  return lVar3;
}


// ===== 004f3aa0 mapInsertValue_IMPL =====

undefined8 mapInsertValue_IMPL(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/map.c",199);
    return 0;
  }
  lVar1 = mapInsertNew_IMPL();
  if (lVar1 != 0) {
    uVar2 = portMemCopy(lVar1,*(undefined4 *)(param_1 + 0x18),param_3,
                        *(undefined4 *)(param_1 + 0x18));
    return uVar2;
  }
  return 0;
}


// ===== 004f3b10 mapInsertExisting_IMPL =====

undefined8 mapInsertExisting_IMPL(long param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0xd7);
  }
  else {
    if (param_3 != 0) {
      uVar1 = _mapInsertBase();
      return uVar1;
    }
    nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/map.c",0xd8);
  }
  return 0;
}


// ===== 004f3b70 mapRemoveIntrusive_IMPL =====

void mapRemoveIntrusive_IMPL(long *param_1,long param_2)

{
  char cVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if (param_2 == 0) {
    return;
  }
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != z","src/libraries/containers/map.c",0xfa);
    return;
  }
  param_2 = param_2 + (int)param_1[1];
  lVar4 = *(long *)(param_2 + 0x10);
  lVar5 = param_2;
  if (lVar4 == 0) {
LAB_004f3bbc:
    lVar4 = *(long *)(lVar5 + 0x18);
    if (lVar4 != 0) goto LAB_004f3cd3;
    lVar3 = *(long *)(lVar5 + 8);
    if (lVar3 == 0) goto LAB_004f3ce8;
LAB_004f3bd6:
    if (*(long *)(lVar3 + 0x10) == lVar5) {
      *(long *)(lVar3 + 0x10) = lVar4;
    }
    else {
      *(long *)(lVar3 + 0x18) = lVar4;
    }
  }
  else {
    lVar3 = *(long *)(param_2 + 0x18);
    if (*(long *)(param_2 + 0x18) != 0) {
      do {
        lVar5 = lVar3;
        lVar3 = *(long *)(lVar5 + 0x10);
      } while (lVar3 != 0);
      goto LAB_004f3bbc;
    }
LAB_004f3cd3:
    *(undefined8 *)(lVar4 + 8) = *(undefined8 *)(lVar5 + 8);
    lVar3 = *(long *)(lVar5 + 8);
    if (lVar3 != 0) goto LAB_004f3bd6;
LAB_004f3ce8:
    *param_1 = lVar4;
  }
  lVar3 = *(long *)(lVar5 + 8);
  cVar1 = *(char *)(lVar5 + 0x20);
  if (param_2 == lVar5) {
LAB_004f3cc0:
    if (cVar1 != '\0') goto LAB_004f3cc5;
    if (*param_1 != lVar4) {
      if (lVar4 != 0) {
LAB_004f3c60:
        while (lVar5 = lVar3, *(char *)(lVar4 + 0x20) == '\0') {
          while (lVar3 = lVar5, lVar3 != 0) {
            lVar5 = *(long *)(lVar3 + 0x10);
            if (lVar5 == lVar4) goto LAB_004f3da8;
            if (lVar5 != 0) goto LAB_004f3d24;
            lVar4 = lVar3;
            if ((*param_1 == lVar3) ||
               (lVar5 = *(long *)(lVar3 + 8), *(char *)(lVar3 + 0x20) != '\0')) goto LAB_004f3e9a;
          }
          lVar3 = *(long *)(lVar4 + 8);
          if (*param_1 == lVar4) break;
        }
        goto LAB_004f3e9a;
      }
      if (lVar3 != 0) {
LAB_004f3d17:
        lVar5 = *(long *)(lVar3 + 0x10);
        if (lVar5 == 0) goto LAB_004f3da8;
        goto LAB_004f3d24;
      }
      goto LAB_004f3cc5;
    }
  }
  else {
    lVar2 = *(long *)(param_2 + 8);
    *(long *)(lVar5 + 8) = lVar2;
    if (lVar2 == 0) {
      *param_1 = lVar5;
    }
    else if (param_2 == *(long *)(lVar2 + 0x10)) {
      *(long *)(lVar2 + 0x10) = lVar5;
    }
    else {
      *(long *)(lVar2 + 0x18) = lVar5;
    }
    lVar2 = *(long *)(param_2 + 0x10);
    *(long *)(lVar5 + 0x10) = lVar2;
    if (lVar2 != 0) {
      *(long *)(lVar2 + 8) = lVar5;
    }
    lVar2 = *(long *)(param_2 + 0x18);
    *(long *)(lVar5 + 0x18) = lVar2;
    if (lVar2 != 0) {
      *(long *)(lVar2 + 8) = lVar5;
    }
    *(undefined1 *)(lVar5 + 0x20) = *(undefined1 *)(param_2 + 0x20);
    if (lVar3 != param_2) goto LAB_004f3cc0;
    if (cVar1 != '\0') goto LAB_004f3cc5;
    if (lVar4 != *param_1) {
      lVar3 = lVar5;
      if (lVar4 == 0) goto LAB_004f3d17;
      goto LAB_004f3c60;
    }
  }
LAB_004f3e91:
  if (lVar4 != 0) {
LAB_004f3e9a:
    *(undefined1 *)(lVar4 + 0x20) = 0;
    *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + -1;
    return;
  }
LAB_004f3cc5:
  *(int *)((long)param_1 + 0xc) = *(int *)((long)param_1 + 0xc) + -1;
  return;
LAB_004f3da8:
  lVar5 = *(long *)(lVar3 + 0x18);
  lVar4 = lVar3;
  if (lVar5 == 0) goto LAB_004f3eac;
  if (*(char *)(lVar5 + 0x20) != '\0') {
    *(undefined1 *)(lVar5 + 0x20) = 0;
    lVar2 = *(long *)(lVar3 + 0x18);
    *(undefined1 *)(lVar3 + 0x20) = 1;
    lVar5 = *(long *)(lVar2 + 0x10);
    *(long *)(lVar3 + 0x18) = lVar5;
    if (lVar5 != 0) {
      *(long *)(lVar5 + 8) = lVar3;
    }
    lVar5 = *(long *)(lVar3 + 8);
    *(long *)(lVar2 + 8) = lVar5;
    if (lVar5 == 0) {
      *param_1 = lVar2;
    }
    else if (*(long *)(lVar5 + 0x10) == lVar3) {
      *(long *)(lVar5 + 0x10) = lVar2;
    }
    else {
      *(long *)(lVar5 + 0x18) = lVar2;
    }
    *(long *)(lVar2 + 0x10) = lVar3;
    lVar5 = *(long *)(lVar3 + 0x18);
    *(long *)(lVar3 + 8) = lVar2;
    if (lVar5 == 0) goto LAB_004f3f7d;
  }
  lVar4 = *(long *)(lVar5 + 0x10);
  if ((lVar4 != 0) && (*(char *)(lVar4 + 0x20) != '\0')) {
    if ((*(long *)(lVar5 + 0x18) == 0) || (*(char *)(*(long *)(lVar5 + 0x18) + 0x20) == '\0')) {
      *(undefined1 *)(lVar4 + 0x20) = 0;
      lVar4 = *(long *)(lVar5 + 0x10);
      *(undefined1 *)(lVar5 + 0x20) = 1;
      lVar2 = *(long *)(lVar4 + 0x18);
      *(long *)(lVar5 + 0x10) = lVar2;
      if (lVar2 != 0) {
        *(long *)(lVar2 + 8) = lVar5;
      }
      lVar2 = *(long *)(lVar5 + 8);
      *(long *)(lVar4 + 8) = lVar2;
      if (lVar2 == 0) {
        *param_1 = lVar4;
      }
      else if (lVar5 == *(long *)(lVar2 + 0x18)) {
        *(long *)(lVar2 + 0x18) = lVar4;
      }
      else {
        *(long *)(lVar2 + 0x10) = lVar4;
      }
      *(long *)(lVar4 + 0x18) = lVar5;
      *(long *)(lVar5 + 8) = lVar4;
      lVar5 = *(long *)(lVar3 + 0x18);
    }
LAB_004f3e3f:
    *(undefined1 *)(lVar5 + 0x20) = *(undefined1 *)(lVar3 + 0x20);
    *(undefined1 *)(lVar3 + 0x20) = 0;
    *(undefined1 *)(*(long *)(lVar5 + 0x18) + 0x20) = 0;
    lVar4 = *(long *)(lVar3 + 0x18);
    lVar5 = *(long *)(lVar4 + 0x10);
    *(long *)(lVar3 + 0x18) = lVar5;
    if (lVar5 != 0) {
      *(long *)(lVar5 + 8) = lVar3;
    }
    lVar5 = *(long *)(lVar3 + 8);
    *(long *)(lVar4 + 8) = lVar5;
    if (lVar5 == 0) {
      *param_1 = lVar4;
    }
    else if (*(long *)(lVar5 + 0x10) == lVar3) {
      *(long *)(lVar5 + 0x10) = lVar4;
    }
    else {
      *(long *)(lVar5 + 0x18) = lVar4;
    }
    *(long *)(lVar4 + 0x10) = lVar3;
    *(long *)(lVar3 + 8) = lVar4;
    lVar4 = *param_1;
    goto LAB_004f3e91;
  }
  if ((*(long *)(lVar5 + 0x18) != 0) && (*(char *)(*(long *)(lVar5 + 0x18) + 0x20) != '\0'))
  goto LAB_004f3e3f;
  goto LAB_004f3ea8;
LAB_004f3d24:
  if (*(char *)(lVar5 + 0x20) != '\0') {
    *(undefined1 *)(lVar5 + 0x20) = 0;
    lVar2 = *(long *)(lVar3 + 0x10);
    *(undefined1 *)(lVar3 + 0x20) = 1;
    lVar4 = *(long *)(lVar2 + 0x18);
    *(long *)(lVar3 + 0x10) = lVar4;
    if (lVar4 != 0) {
      *(long *)(lVar4 + 8) = lVar3;
    }
    lVar4 = *(long *)(lVar3 + 8);
    *(long *)(lVar2 + 8) = lVar4;
    if (lVar4 == 0) {
      *param_1 = lVar2;
    }
    else if (*(long *)(lVar4 + 0x18) == lVar3) {
      *(long *)(lVar4 + 0x18) = lVar2;
    }
    else {
      *(long *)(lVar4 + 0x10) = lVar2;
    }
    *(long *)(lVar2 + 0x18) = lVar3;
    lVar5 = *(long *)(lVar3 + 0x10);
    *(long *)(lVar3 + 8) = lVar2;
    lVar4 = lVar3;
    if (lVar5 == 0) {
LAB_004f3f7d:
      lVar3 = lVar2;
      if (*param_1 == lVar4) goto LAB_004f3e9a;
      goto LAB_004f3c60;
    }
  }
  lVar4 = *(long *)(lVar5 + 0x18);
  if ((lVar4 != 0) && (*(char *)(lVar4 + 0x20) != '\0')) {
    if ((*(long *)(lVar5 + 0x10) == 0) || (*(char *)(*(long *)(lVar5 + 0x10) + 0x20) == '\0')) {
      *(undefined1 *)(lVar4 + 0x20) = 0;
      lVar4 = *(long *)(lVar5 + 0x18);
      *(undefined1 *)(lVar5 + 0x20) = 1;
      lVar2 = *(long *)(lVar4 + 0x10);
      *(long *)(lVar5 + 0x18) = lVar2;
      if (lVar2 != 0) {
        *(long *)(lVar2 + 8) = lVar5;
      }
      lVar2 = *(long *)(lVar5 + 8);
      *(long *)(lVar4 + 8) = lVar2;
      if (lVar2 == 0) {
        *param_1 = lVar4;
      }
      else if (lVar5 == *(long *)(lVar2 + 0x10)) {
        *(long *)(lVar2 + 0x10) = lVar4;
      }
      else {
        *(long *)(lVar2 + 0x18) = lVar4;
      }
      *(long *)(lVar4 + 0x10) = lVar5;
      *(long *)(lVar5 + 8) = lVar4;
      lVar5 = *(long *)(lVar3 + 0x10);
    }
LAB_004f3ed7:
    *(undefined1 *)(lVar5 + 0x20) = *(undefined1 *)(lVar3 + 0x20);
    *(undefined1 *)(lVar3 + 0x20) = 0;
    *(undefined1 *)(*(long *)(lVar5 + 0x10) + 0x20) = 0;
    lVar4 = *(long *)(lVar3 + 0x10);
    lVar5 = *(long *)(lVar4 + 0x18);
    *(long *)(lVar3 + 0x10) = lVar5;
    if (lVar5 != 0) {
      *(long *)(lVar5 + 8) = lVar3;
    }
    lVar5 = *(long *)(lVar3 + 8);
    *(long *)(lVar4 + 8) = lVar5;
    if (lVar5 == 0) {
      *param_1 = lVar4;
    }
    else if (*(long *)(lVar5 + 0x18) == lVar3) {
      *(long *)(lVar5 + 0x18) = lVar4;
    }
    else {
      *(long *)(lVar5 + 0x10) = lVar4;
    }
    *(long *)(lVar4 + 0x18) = lVar3;
    *(long *)(lVar3 + 8) = lVar4;
    lVar4 = *param_1;
    goto LAB_004f3e91;
  }
  if ((*(long *)(lVar5 + 0x10) != 0) && (*(char *)(*(long *)(lVar5 + 0x10) + 0x20) != '\0'))
  goto LAB_004f3ed7;
LAB_004f3ea8:
  *(undefined1 *)(lVar5 + 0x20) = 1;
  lVar4 = lVar3;
LAB_004f3eac:
  lVar3 = *(long *)(lVar4 + 8);
  if (*param_1 == lVar4) goto LAB_004f3e9a;
  goto LAB_004f3c60;
}


// ===== 004f4100 mapRemove_IMPL =====

void mapRemove_IMPL(long param_1,long param_2)

{
  long lVar1;
  
  if (param_2 != 0) {
    mapRemoveIntrusive_IMPL();
    lVar1 = 0;
    if (param_1 != 0) {
      lVar1 = *(int *)(param_1 + 8) + param_2;
    }
    _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x10),lVar1);
    return;
  }
  return;
}


// ===== 004f4150 mapRemoveByKey_IMPL =====

void mapRemoveByKey_IMPL(ulong *param_1,ulong param_2)

{
  ulong uVar1;
  ulong *puVar2;
  
  if (param_1 == (ulong *)0x0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0x146);
    return;
  }
  puVar2 = (ulong *)*param_1;
  while( true ) {
    if (puVar2 == (ulong *)0x0) {
      return;
    }
    while (param_2 < *puVar2) {
      puVar2 = (ulong *)puVar2[2];
      if (puVar2 == (ulong *)0x0) {
        return;
      }
    }
    if (param_2 <= *puVar2) break;
    puVar2 = (ulong *)puVar2[3];
  }
  uVar1 = param_1[1];
  mapRemoveIntrusive_IMPL();
  _portMemAllocatorFree(param_1[2],(long)puVar2 + ((long)(int)param_1[1] - (long)(int)uVar1));
  return;
}


// ===== 004f41e0 mapFind_IMPL =====

long mapFind_IMPL(long *param_1,ulong param_2)

{
  ulong *puVar1;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0x146);
    return 0;
  }
  puVar1 = (ulong *)*param_1;
  if (puVar1 != (ulong *)0x0) {
    do {
      while (param_2 < *puVar1) {
        puVar1 = (ulong *)puVar1[2];
        if (puVar1 == (ulong *)0x0) {
          return 0;
        }
      }
      if (param_2 <= *puVar1) {
        return (long)puVar1 - (long)(int)param_1[1];
      }
      puVar1 = (ulong *)puVar1[3];
    } while (puVar1 != (ulong *)0x0);
    return 0;
  }
  return 0;
}


// ===== 004f4260 mapFindGEQ_IMPL =====

long mapFindGEQ_IMPL(long *param_1,ulong param_2)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0x15e);
    return 0;
  }
  if ((ulong *)*param_1 != (ulong *)0x0) {
    puVar2 = (ulong *)*param_1;
    puVar3 = (ulong *)0x0;
    do {
      while (puVar4 = puVar2, *puVar4 <= param_2) {
        if (*puVar4 == param_2) {
          return (long)puVar4 - (long)(int)param_1[1];
        }
        puVar1 = puVar4 + 3;
        puVar2 = (ulong *)*puVar1;
        puVar4 = puVar3;
        if ((ulong *)*puVar1 == (ulong *)0x0) goto LAB_004f42a2;
      }
      puVar2 = (ulong *)puVar4[2];
      puVar3 = puVar4;
    } while ((ulong *)puVar4[2] != (ulong *)0x0);
LAB_004f42a2:
    if (puVar4 != (ulong *)0x0) {
      return (long)puVar4 - (long)(int)param_1[1];
    }
  }
  return 0;
}


// ===== 004f42e0 mapFindLEQ_IMPL =====

long mapFindLEQ_IMPL(long *param_1,ulong param_2)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pMap","src/libraries/containers/map.c",0x17e);
    return 0;
  }
  if ((ulong *)*param_1 != (ulong *)0x0) {
    puVar1 = (ulong *)*param_1;
    puVar3 = (ulong *)0x0;
    do {
      while (puVar2 = puVar1, *puVar2 <= param_2) {
        if (*puVar2 == param_2) {
          return (long)puVar2 - (long)(int)param_1[1];
        }
        puVar1 = (ulong *)puVar2[3];
        puVar3 = puVar2;
        if ((ulong *)puVar2[3] == (ulong *)0x0) goto LAB_004f4322;
      }
      puVar1 = (ulong *)puVar2[2];
    } while ((ulong *)puVar2[2] != (ulong *)0x0);
LAB_004f4322:
    if (puVar3 != (ulong *)0x0) {
      return (long)puVar3 - (long)(int)param_1[1];
    }
  }
  return 0;
}


// ===== 004f4360 mapNext_IMPL =====

long mapNext_IMPL(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if ((param_2 == 0) || (param_1 == (long *)0x0)) {
    nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0x19e);
    return 0;
  }
  param_2 = param_2 + (int)param_1[1];
  lVar1 = *(long *)(param_2 + 0x18);
  if (lVar1 == 0) {
    lVar2 = *(long *)(param_2 + 8);
    if (*(long *)(param_2 + 8) == 0) {
      return lVar1;
    }
    while (lVar3 = lVar2, *(long *)(lVar3 + 0x18) == param_2) {
      if (*param_1 == lVar3) {
        return lVar1;
      }
      lVar2 = *(long *)(lVar3 + 8);
      param_2 = lVar3;
      if (*(long *)(lVar3 + 8) == 0) {
        return 0;
      }
    }
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = *(long *)(lVar3 + 0x10);
    } while (*(long *)(lVar3 + 0x10) != 0);
  }
  return lVar3 - (int)param_1[1];
}


// ===== 004f4400 mapPrev_IMPL =====

long mapPrev_IMPL(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if ((param_2 == 0) || (param_1 == (long *)0x0)) {
    nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0x1c6);
    return 0;
  }
  param_2 = param_2 + (int)param_1[1];
  lVar1 = *(long *)(param_2 + 0x10);
  if (lVar1 == 0) {
    lVar2 = *(long *)(param_2 + 8);
    if (*(long *)(param_2 + 8) == 0) {
      return lVar1;
    }
    while (lVar3 = lVar2, *(long *)(lVar3 + 0x10) == param_2) {
      if (*param_1 == lVar3) {
        return lVar1;
      }
      lVar2 = *(long *)(lVar3 + 8);
      param_2 = lVar3;
      if (*(long *)(lVar3 + 8) == 0) {
        return 0;
      }
    }
  }
  else {
    do {
      lVar3 = lVar1;
      lVar1 = *(long *)(lVar3 + 0x18);
    } while (*(long *)(lVar3 + 0x18) != 0);
  }
  return lVar3 - (int)param_1[1];
}


// ===== 004f44a0 mapIterRange_IMPL =====

undefined8 * mapIterRange_IMPL(undefined8 *param_1,long param_2,long param_3,long param_4)

{
  undefined8 local_48;
  long local_40;
  ulong *local_38;
  long local_30;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog(&DAT_00da37a7,"src/libraries/containers/map.c",499);
  }
  portMemSet(&local_48,0,0x20);
  local_40 = param_2;
  if (*(int *)(param_2 + 0xc) != 0) {
    local_30 = param_4;
    if (param_3 == 0) {
      nvAssertFailedNoLog("pFirst","src/libraries/containers/map.c",0x1fe);
      if (param_4 == 0) {
        nvAssertFailedNoLog("pLast","src/libraries/containers/map.c",0x1ff);
        nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0x9e);
        nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0x9e);
        local_38 = (ulong *)0x0;
        goto LAB_004f4511;
      }
      nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0x9e);
      local_30 = (long)*(int *)(param_2 + 8);
      local_38 = (ulong *)0x0;
    }
    else {
      if (param_4 == 0) {
        nvAssertFailedNoLog("pLast","src/libraries/containers/map.c",0x1ff);
        nvAssertFailedNoLog("NULL != pNode","src/libraries/containers/map.c",0x9e);
        local_38 = (ulong *)(*(int *)(param_2 + 8) + param_3);
        if (*local_38 != 0) {
          nvAssertFailedNoLog("mapKey_IMPL(pMap, pLast) >= mapKey_IMPL(pMap, pFirst)",
                              "src/libraries/containers/map.c",0x202);
          local_38 = (ulong *)(*(int *)(param_2 + 8) + param_3);
        }
        goto LAB_004f4511;
      }
      local_30 = (long)*(int *)(param_2 + 8);
      local_38 = (ulong *)(param_3 + local_30);
      if (*(ulong *)(param_4 + local_30) < *local_38) {
        nvAssertFailedNoLog("mapKey_IMPL(pMap, pLast) >= mapKey_IMPL(pMap, pFirst)",
                            "src/libraries/containers/map.c",0x202);
        local_30 = (long)*(int *)(param_2 + 8);
        local_38 = (ulong *)(local_30 + param_3);
      }
    }
    local_30 = param_4 + local_30;
  }
LAB_004f4511:
  *param_1 = local_48;
  param_1[1] = local_40;
  param_1[2] = local_38;
  param_1[3] = local_30;
  return param_1;
}


// ===== 004f4690 mapIterNext_IMPL =====

undefined8 mapIterNext_IMPL(long *param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog(&DAT_00da3816,"src/libraries/containers/map.c",0x20e);
  }
  else {
    lVar1 = param_1[2];
    if (lVar1 != 0) {
      if (param_1[1] == 0) {
        lVar2 = 0;
      }
      else {
        lVar2 = lVar1 - *(int *)(param_1[1] + 8);
      }
      *param_1 = lVar2;
      if (lVar1 == param_1[3]) {
        param_1[2] = 0;
      }
      else {
        lVar1 = mapNext_IMPL();
        if ((lVar1 == 0) || (param_1[1] == 0)) {
          lVar1 = 0;
        }
        else {
          lVar1 = lVar1 + *(int *)(param_1[1] + 8);
        }
        param_1[2] = lVar1;
      }
      return 1;
    }
  }
  return 0;
}


// ===== 004f4740 multimapInit_IMPL =====

void multimapInit_IMPL(long param_1,long param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0x24);
    return;
  }
  if (param_2 != 0) {
    mapInit_IMPL(param_1,param_2,param_5);
    *(undefined4 *)(param_1 + 0x20) = param_4;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = param_3;
    return;
  }
  nvAssertFailedNoLog("NULL != pAllocator","src/libraries/containers/multimap.c",0x25);
  return;
}


// ===== 004f47d0 multimapInsertSubmap_IMPL =====

long multimapInsertSubmap_IMPL(long param_1)

{
  long lVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0x5e);
    return 0;
  }
  lVar1 = mapInsertNew_IMPL();
  if (lVar1 != 0) {
    mapInitIntrusive_IMPL(lVar1,*(int *)(param_1 + 0x20) + 8);
    return lVar1;
  }
  return 0;
}


// ===== 004f4840 multimapFindSubmap_IMPL =====

void multimapFindSubmap_IMPL(void)

{
  mapFind_IMPL();
  return;
}


// ===== 004f4850 multimapInsertItemNew_IMPL =====

long multimapInsertItemNew_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  lVar3 = mapFind_IMPL();
  if (lVar3 != 0) {
    iVar1 = *(int *)(param_1 + 0x20) + 0x30;
    lVar4 = _portMemAllocatorAlloc(*(undefined8 *)(param_1 + 0x10),iVar1);
    if (lVar4 != 0) {
      portMemSet(lVar4,0,iVar1);
      *(long *)(lVar4 + *(int *)(param_1 + 0x20)) = lVar3;
      cVar2 = mapInsertExisting_IMPL(lVar3,param_3,lVar4);
      if (cVar2 == '\0') {
        lVar3 = 0;
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x10),lVar4);
      }
      else {
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
        lVar3 = lVar4;
      }
      return lVar3;
    }
    return 0;
  }
  return 0;
}


// ===== 004f4960 multimapInsertItemValue_IMPL =====

undefined8
multimapInsertItemValue_IMPL(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0xab);
    return 0;
  }
  if (param_4 == 0) {
    nvAssertFailedNoLog("NULL != pValue","src/libraries/containers/multimap.c",0xac);
  }
  else {
    lVar1 = multimapInsertItemNew_IMPL();
    if (lVar1 != 0) {
      uVar2 = portMemCopy(lVar1,*(undefined4 *)(param_1 + 0x28),param_4,
                          *(undefined4 *)(param_1 + 0x28));
      return uVar2;
    }
  }
  return 0;
}


// ===== 004f49f0 multimapFindItem_IMPL =====

undefined8 multimapFindItem_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0xbf);
    return 0;
  }
  lVar1 = mapFind_IMPL();
  if (lVar1 != 0) {
    uVar2 = mapFind_IMPL(lVar1,param_3);
    return uVar2;
  }
  return 0;
}


// ===== 004f4a50 multimapRemoveItem_IMPL =====

void multimapRemoveItem_IMPL(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0xcd);
    return;
  }
  if (param_2 != 0) {
    lVar2 = *(long *)(param_2 + *(int *)(param_1 + 0x20));
    if (lVar2 != 0) {
      iVar1 = *(int *)(lVar2 + 0xc);
      mapRemoveIntrusive_IMPL(lVar2);
      if (*(int *)(lVar2 + 0xc) != iVar1) {
        _portMemAllocatorFree(*(undefined8 *)(param_1 + 0x10),param_2);
        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
      }
      return;
    }
    nvAssertFailedNoLog("NULL != pSubmap","src/libraries/containers/multimap.c",0xd1);
    return;
  }
  nvAssertFailedNoLog("NULL != pLeaf","src/libraries/containers/multimap.c",0xce);
  return;
}


// ===== 004f4b20 multimapRemoveSubmap_IMPL =====

void multimapRemoveSubmap_IMPL(long param_1,long param_2)

{
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0xe4);
    return;
  }
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      mapDestroyIntrusive_IMPL(param_2);
      mapRemove_IMPL(param_1,param_2);
      return;
    }
    nvAssertFailedNoLog("pSubmap->count == 0","src/libraries/containers/multimap.c",0xe6);
    return;
  }
  nvAssertFailedNoLog("NULL != pSubmap","src/libraries/containers/multimap.c",0xe5);
  return;
}


// ===== 004f4bc0 multimapRemoveItemByKey_IMPL =====

void multimapRemoveItemByKey_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0xbf);
    return;
  }
  lVar1 = mapFind_IMPL();
  if (lVar1 != 0) {
    lVar1 = mapFind_IMPL(lVar1,param_3);
    if (lVar1 != 0) {
      multimapRemoveItem_IMPL(param_1,lVar1);
      return;
    }
  }
  return;
}


// ===== 004f4c20 multimapNextItem_IMPL =====

long multimapNextItem_IMPL(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar2 = *(long *)(param_2 + *(int *)(param_1 + 0x20));
    if (lVar2 == 0) {
      nvAssertFailedNoLog("NULL != pSubmap","src/libraries/containers/multimap.c",0xfe);
    }
    else {
      lVar1 = mapNext_IMPL(lVar2);
      while( true ) {
        if (lVar1 != 0) {
          return lVar1;
        }
        lVar2 = mapNext_IMPL(param_1,lVar2);
        if (lVar2 == 0) break;
        lVar1 = mapFindGEQ_IMPL(lVar2,0);
      }
    }
    return 0;
  }
  nvAssertFailedNoLog("NULL != pBase && NULL != pValue","src/libraries/containers/multimap.c",0xfb);
  return 0;
}


// ===== 004f4cf0 multimapFirstItem_IMPL =====

long multimapFirstItem_IMPL(long param_1)

{
  long lVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0x126);
    return 0;
  }
  lVar1 = mapFindGEQ_IMPL(param_1,0);
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    lVar1 = mapFindGEQ_IMPL(lVar1,0);
    if (lVar1 != 0) break;
    lVar1 = mapNext_IMPL(param_1);
  }
  return lVar1;
}


// ===== 004f4da0 multimapDestroy_IMPL =====

void multimapDestroy_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 != 0) {
    lVar1 = multimapFirstItem_IMPL();
    while (lVar1 != 0) {
      lVar2 = multimapNextItem_IMPL(param_1,lVar1);
      multimapRemoveItem_IMPL(param_1,lVar1);
      lVar1 = lVar2;
    }
    while (lVar1 = mapFindGEQ_IMPL(param_1,0), lVar1 != 0) {
      mapDestroyIntrusive_IMPL(lVar1);
      mapRemove_IMPL(param_1);
    }
    mapDestroy_IMPL(param_1);
    return;
  }
  nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0x34);
  return;
}


// ===== 004f4e50 multimapLastItem_IMPL =====

long multimapLastItem_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0x138);
    return 0;
  }
  lVar1 = mapFindLEQ_IMPL(param_1,0xffffffffffffffff);
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    lVar2 = mapFindLEQ_IMPL(lVar1,0xffffffffffffffff);
    if (lVar2 != 0) break;
    lVar1 = mapPrev_IMPL(param_1,lVar1);
  }
  return lVar2;
}


// ===== 004f4f01 multimapItemIterRange_IMPL.cold =====

void multimapItemIterRange_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 004f4f10 multimapItemIterRange_IMPL =====

undefined8 * multimapItemIterRange_IMPL(undefined8 *param_1,long param_2,long param_3,long param_4)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  code *pcVar5;
  long *plVar6;
  undefined8 local_48;
  long local_40;
  long local_38;
  long local_30;
  
  portMemSet(&local_48,0,0x20);
  local_40 = param_2;
  if (param_2 == 0) {
    nvAssertFailedNoLog("NULL != pBase","src/libraries/containers/multimap.c",0x153);
  }
  else if (((*(int *)(param_2 + 0x24) != 0) && (param_3 != 0)) && (param_4 != 0)) {
    plVar1 = (long *)(param_3 + *(int *)(param_2 + 0x20));
    plVar6 = (long *)(*(int *)(param_2 + 0x20) + param_4);
    lVar2 = *plVar1;
    if (lVar2 != 0) {
      uVar3 = *(ulong *)(lVar2 + *(int *)(param_2 + 8));
      lVar2 = *plVar6;
      if (lVar2 != 0) {
        uVar4 = *(ulong *)(lVar2 + *(int *)(param_2 + 8));
        local_38 = param_3;
        local_30 = param_4;
        if ((uVar4 <= uVar3) && (((ulong)plVar6[1] < (ulong)plVar1[1] || (uVar3 != uVar4)))) {
          nvAssertFailedNoLog("firstSubmapKey < lastSubmapKey || (firstSubmapKey == lastSubmapKey && firstKey <= lastKey)"
                              ,"src/libraries/containers/multimap.c",0x165);
        }
        goto LAB_004f4f9e;
      }
    }
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
LAB_004f4f9e:
  *param_1 = local_48;
  param_1[1] = local_40;
  param_1[2] = local_38;
  param_1[3] = local_30;
  return param_1;
}


// ===== 004f5020 multimapItemIterNext_IMPL =====

undefined8 multimapItemIterNext_IMPL(long *param_1)

{
  long lVar1;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pIt","src/libraries/containers/multimap.c",0x16f);
  }
  else {
    lVar1 = param_1[2];
    *param_1 = lVar1;
    if (lVar1 != 0) {
      if (lVar1 == param_1[3]) {
        param_1[2] = 0;
      }
      else {
        lVar1 = multimapNextItem_IMPL(param_1[1]);
        param_1[2] = lVar1;
      }
      return 1;
    }
  }
  return 0;
}


// ===== 004f50a0 managedCopyData =====

void managedCopyData(long param_1,long param_2,long param_3,long param_4,long param_5,char param_6)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_3 + 8) + param_1 * param_2;
  lVar2 = lVar1;
  if (param_6 == '\0') {
    lVar2 = param_4;
    param_4 = lVar1;
  }
  portMemCopy(lVar2,param_5 * param_1,param_4,param_5 * param_1);
  return;
}


// ===== 004f50d0 circularQueueInit_IMPL =====

undefined8 circularQueueInit_IMPL(long *param_1,long param_2,long param_3,long param_4)

{
  long local_38;
  long local_30;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pAllocator != NULL","src/libraries/containers/queue.c",0x62);
    return 0x1f;
  }
  local_38 = _portMemAllocatorAlloc(param_2,(param_3 + 1) * param_4);
  if (local_38 != 0) {
    local_30 = param_2;
    if (param_1 != (long *)0x0) {
      portMemCopy(param_1 + 2,8,&local_38,8);
      portMemCopy(param_1 + 1,8,&local_30,8);
      param_1[3] = param_4;
      *param_1 = param_3 + 1;
      param_1[8] = 0;
      param_1[0x10] = 0;
      return 0;
    }
    nvAssertFailedNoLog("pQueue != NULL","src/libraries/containers/queue.c",0x26);
    return 0x1f;
  }
  return 0x51;
}


// ===== 004f51f0 circularQueueInitNonManaged_IMPL =====

undefined8
circularQueueInitNonManaged_IMPL(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30 [2];
  
  local_38 = 0;
  local_30[0] = 0;
  if (param_1 != (undefined8 *)0x0) {
    portMemCopy(param_1 + 2,8,&local_38,8);
    portMemCopy(param_1 + 1,8,local_30,8);
    param_1[3] = param_3;
    *param_1 = param_2;
    param_1[8] = 0;
    param_1[0x10] = 0;
    return 0;
  }
  nvAssertFailedNoLog("pQueue != NULL","src/libraries/containers/queue.c",0x26);
  return 0x1f;
}


// ===== 004f52a0 circularQueueDestroy_IMPL =====

void circularQueueDestroy_IMPL(undefined8 *param_1)

{
  long local_20 [2];
  
  if (param_1 != (undefined8 *)0x0) {
    *param_1 = 1;
    param_1[8] = 0;
    param_1[0x10] = 0;
    portMemCopy(local_20,8,param_1 + 1,8);
    if (local_20[0] != 0) {
      _portMemAllocatorFree(param_1[1],param_1[2]);
    }
    return;
  }
  nvAssertFailedNoLog("NULL != pQueue","src/libraries/containers/queue.c",0x79);
  return;
}


// ===== 004f5320 circularQueueIsEmpty_IMPL =====

undefined8 circularQueueIsEmpty_IMPL(long *param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("NULL != pQueue","src/libraries/containers/queue.c",0x94);
    return 0;
  }
  uVar1 = param_1[8];
  uVar2 = param_1[0x10];
  if (uVar1 <= uVar2) {
    return CONCAT71((int7)(uVar2 - uVar1 >> 8),uVar2 - uVar1 == 0);
  }
  lVar3 = (uVar2 + *param_1) - uVar1;
  return CONCAT71((int7)((ulong)lVar3 >> 8),lVar3 == 0);
}


// ===== 004f5380 circularQueuePushNonManaged_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong circularQueuePushNonManaged_IMPL
                (ulong *param_1,undefined8 *param_2,long param_3,ulong param_4)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  
  if (param_1 == (ulong *)0x0) {
    nvAssertFailedNoLog("NULL != pQueue","src/libraries/containers/queue.c",0xa8);
    return 0;
  }
  uVar1 = param_1[0x10];
  uVar2 = *param_1;
  uVar5 = param_1[8];
  lVar8 = (uVar1 + uVar2) - uVar5;
  if (uVar5 <= uVar1) {
    lVar8 = uVar1 - uVar5;
  }
  uVar5 = (uVar2 - 1) - lVar8;
  if (param_4 < uVar5) {
    uVar5 = param_4;
  }
  if (uVar5 != 0) {
    uVar3 = param_1[3];
    uVar4 = uVar2 - uVar1;
    uVar6 = uVar5;
    uVar7 = uVar1;
    uVar9 = uVar1 + uVar5;
    if (uVar2 < uVar1 + uVar5) {
      lVar8 = uVar3 * uVar4;
      if ((code *)*param_2 == managedCopyData) {
        portMemCopy(uVar3 * uVar1 + param_2[1],lVar8,param_3,lVar8);
      }
      else {
        (*(code *)*param_2)(uVar3,uVar1,param_2,param_3,uVar4,1);
      }
      param_3 = param_3 + lVar8;
      uVar7 = 0;
      uVar6 = (uVar1 - uVar2) + uVar5;
      uVar4 = uVar2;
      uVar9 = uVar6;
    }
    if (uVar4 < uVar6) {
      nvAssertFailedNoLog("remainingElemToCpy <= capacity - putIdx",
                          "src/libraries/containers/queue.c",0xca);
    }
    if ((code *)*param_2 == managedCopyData) {
      portMemCopy(param_2[1] + uVar3 * uVar7,uVar3 * uVar6,param_3,uVar3 * uVar6);
    }
    else {
      (*(code *)*param_2)(uVar3,uVar7,param_2,param_3,uVar6,1);
    }
    LOCK();
    UNLOCK();
    param_1[0x10] = uVar9 % uVar2;
    return uVar5;
  }
  return 0;
}


// ===== 004f5590 circularQueuePush_IMPL =====

undefined8 circularQueuePush_IMPL(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *local_18;
  undefined8 local_10;
  
  local_18 = (code *)0x0;
  local_10 = 0;
  if (param_1 == 0) {
    nvAssertFailedNoLog("pQueue != NULL","src/libraries/containers/queue.c",0xdf);
  }
  else {
    if (*(long *)(param_1 + 8) != 0) {
      local_10 = *(undefined8 *)(param_1 + 0x10);
      local_18 = managedCopyData;
      uVar1 = circularQueuePushNonManaged_IMPL(param_1,&local_18,param_2,param_3);
      return uVar1;
    }
    nvAssertFailedNoLog("pQueue->pAllocator != NULL","src/libraries/containers/queue.c",0xe0);
  }
  return 0;
}


// ===== 004f5620 circularQueuePopAndCopyNonManaged_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r14 replaced with injection: x86_indirect_thunk_r14 */

undefined8
circularQueuePopAndCopyNonManaged_IMPL(ulong *param_1,undefined8 *param_2,undefined8 param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  
  if (param_1 == (ulong *)0x0) {
    nvAssertFailedNoLog("pQueue != NULL","src/libraries/containers/queue.c",0x109);
  }
  else {
    uVar1 = *param_1;
    uVar2 = param_1[0x10];
    uVar3 = param_1[8];
    lVar4 = (uVar1 + uVar2) - uVar3;
    if (uVar3 <= uVar2) {
      lVar4 = uVar2 - uVar3;
    }
    if (lVar4 != 0) {
      uVar2 = param_1[3];
      if ((code *)*param_2 == managedCopyData) {
        portMemCopy(param_3,uVar2,uVar2 * uVar3 + param_2[1],uVar2);
      }
      else {
        (*(code *)*param_2)(uVar2,uVar3,param_2,param_3,1,0);
      }
      LOCK();
      UNLOCK();
      param_1[8] = (uVar3 + 1) % uVar1;
      return 1;
    }
  }
  return 0;
}


// ===== 004f5720 circularQueuePopAndCopy_IMPL =====

undefined8 circularQueuePopAndCopy_IMPL(ulong *param_1,undefined8 param_2)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  
  if (param_1 == (ulong *)0x0) {
    nvAssertFailedNoLog("pQueue != NULL","src/libraries/containers/queue.c",0x121);
  }
  else if (param_1[1] == 0) {
    nvAssertFailedNoLog("pQueue->pAllocator != NULL","src/libraries/containers/queue.c",0x122);
  }
  else {
    uVar1 = param_1[0x10];
    uVar2 = *param_1;
    uVar3 = param_1[8];
    lVar4 = (uVar2 + uVar1) - uVar3;
    if (uVar3 <= uVar1) {
      lVar4 = uVar1 - uVar3;
    }
    if (lVar4 != 0) {
      uVar1 = param_1[3];
      portMemCopy(param_2,uVar1,uVar1 * uVar3 + param_1[2],uVar1);
      LOCK();
      UNLOCK();
      param_1[8] = (uVar3 + 1) % uVar2;
      return 1;
    }
  }
  return 0;
}


// ===== 004f5800 _vectReallocHelper =====

undefined8 _vectReallocHelper(long *param_1,uint param_2,uint param_3)

{
  long lVar1;
  long lVar2;
  
  if (param_2 < param_3) {
    nvAssertFailedNoLog("newSize >= copySize","src/libraries/containers/vector.c",0x19c);
  }
  else {
    lVar1 = _portMemAllocatorAlloc(param_1[1],param_2);
    if ((lVar1 != 0) || (param_2 == 0)) {
      portMemSet(lVar1,0,param_2);
      lVar2 = lVar1;
      if (param_3 != 0) {
        lVar2 = portMemCopy(lVar1,param_2,*param_1,param_3);
        if (lVar2 == 0) {
          nvAssertFailedNoLog("pCopiedArray","src/libraries/containers/vector.c",0x1ab);
          _portMemAllocatorFree(param_1[1],lVar1);
          return 0;
        }
        _portMemAllocatorFree(param_1[1],*param_1);
      }
      *param_1 = lVar2;
      *(uint *)((long)param_1 + 0x14) = param_2 / *(uint *)(param_1 + 2);
      *(uint *)(param_1 + 3) = param_3 / *(uint *)(param_1 + 2);
      return 1;
    }
  }
  return 0;
}


// ===== 004f5930 vectInit_IMPL =====

undefined4 vectInit_IMPL(long *param_1,long param_2,int param_3,int param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  if (param_1 == (long *)0x0) {
    nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x31);
  }
  else {
    if (param_2 != 0) {
      portMemSet(param_1,0,0x20);
      param_1[1] = param_2;
      *(int *)((long)param_1 + 0x14) = param_3;
      *(int *)(param_1 + 2) = param_4;
      *(undefined4 *)(param_1 + 3) = 0;
      if (param_3 == 0) {
        uVar2 = 0;
      }
      else {
        lVar1 = _portMemAllocatorAlloc(param_2,param_4 * param_3);
        *param_1 = lVar1;
        if (lVar1 != 0) {
          portMemSet(lVar1,0,param_3 * (int)param_1[2]);
          return 0;
        }
        uVar2 = 0x51;
      }
      return uVar2;
    }
    nvAssertFailedNoLog("pAllocator != NULL","src/libraries/containers/vector.c",0x32);
  }
  return 0x1f;
}


// ===== 004f5a50 vectDestroy_IMPL =====

void vectDestroy_IMPL(undefined8 *param_1)

{
  if (param_1 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x4c);
    return;
  }
  if (param_1[1] != 0) {
    _portMemAllocatorFree(param_1[1],*param_1);
    *param_1 = 0;
    *(undefined8 *)((long)param_1 + 0x14) = 0;
    return;
  }
  *param_1 = 0;
  *(undefined8 *)((long)param_1 + 0x14) = 0;
  return;
}


// ===== 004f5ac0 vectClear_IMPL =====

void vectClear_IMPL(long param_1)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    return;
  }
  nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x5a);
  return;
}


// ===== 004f5af0 vectAt_IMPL =====

ulong vectAt_IMPL(ulong *param_1,int param_2)

{
  ulong uVar1;
  ulong uVar2;
  
  if (param_1 == (ulong *)0x0) {
    nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x65);
    return 0;
  }
  if ((int)param_1[3] != 0) {
    uVar2 = *param_1;
    uVar1 = uVar2 + (uint)(param_2 * (int)param_1[2]);
    if ((uVar1 <= (uint)(((int)param_1[3] + -1) * (int)param_1[2]) + uVar2) && (uVar2 <= uVar1)) {
      return uVar1;
    }
    nvAssertFailedNoLog("_vectIndexCheck(pVector, index)","src/libraries/containers/vector.c",0x6b);
  }
  return 0;
}


// ===== 004f5b60 vectCount_IMPL =====

undefined4 vectCount_IMPL(long param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x18);
  }
  nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x7d);
  return 0;
}


// ===== 004f5b90 vectIsEmpty_IMPL =====

undefined4 vectIsEmpty_IMPL(long param_1)

{
  if (param_1 != 0) {
    return CONCAT31((int3)((uint)*(int *)(param_1 + 0x18) >> 8),*(int *)(param_1 + 0x18) == 0);
  }
  nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x86);
  return 0;
}


// ===== 004f5bd0 vectTrim_IMPL =====

byte vectTrim_IMPL(long param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x91);
    return 0x1f;
  }
  if (*(uint *)(param_1 + 0x14) < param_2) {
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar3 = uVar1;
  if (uVar1 < param_2) {
    uVar3 = param_2;
  }
  cVar2 = _vectReallocHelper(param_1,uVar3 * *(int *)(param_1 + 0x10),
                             uVar1 * *(int *)(param_1 + 0x10));
  return -(cVar2 == '\0') & 0x51;
}


// ===== 004f5c40 vectReserve_IMPL =====

byte vectReserve_IMPL(long param_1,uint param_2)

{
  char cVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0xad);
  }
  else {
    if (param_2 != 0) {
      if (param_2 <= *(uint *)(param_1 + 0x14)) {
        return 0;
      }
      cVar1 = _vectReallocHelper(param_1,param_2 * *(int *)(param_1 + 0x10),
                                 *(int *)(param_1 + 0x18) * *(int *)(param_1 + 0x10));
      return -(cVar1 == '\0') & 0x51;
    }
    nvAssertFailedNoLog("n > 0","src/libraries/containers/vector.c",0xae);
  }
  return 0x1f;
}


// ===== 004f5cc0 vectInsert_IMPL =====

long vectInsert_IMPL(ulong *param_1,uint param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_1 == (ulong *)0x0) {
    nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",199);
    return 0;
  }
  uVar8 = (uint)param_1[3];
  iVar2 = (int)param_1[2];
  if (uVar8 == param_2) {
    uVar4 = *(uint *)((long)param_1 + 0x14);
    uVar9 = param_2 + 1;
    if (uVar9 <= uVar4) {
      uVar3 = *param_1;
      goto LAB_004f5da6;
    }
LAB_004f5de2:
    iVar6 = uVar4 * 2;
    if (uVar4 == 0) {
      iVar6 = 10;
    }
    cVar1 = _vectReallocHelper(param_1,iVar6 * iVar2,uVar8 * iVar2);
    if (cVar1 == '\0') {
      return 0;
    }
    uVar8 = (uint)param_1[3];
    uVar3 = *param_1;
    iVar2 = (int)param_1[2];
  }
  else {
    if (uVar8 == 0) {
LAB_004f5d1f:
      nvAssertFailedNoLog("_vectIndexCheck(pVector, index)","src/libraries/containers/vector.c",0xcb
                         );
      return 0;
    }
    uVar3 = *param_1;
    uVar7 = param_2 * iVar2 + uVar3;
    if (((uVar8 - 1) * iVar2 + uVar3 < uVar7) || (uVar7 < uVar3)) goto LAB_004f5d1f;
    uVar4 = *(uint *)((long)param_1 + 0x14);
    if (uVar4 < uVar8 + 1) goto LAB_004f5de2;
  }
  if (param_2 < uVar8) {
    do {
      uVar9 = uVar8 - 1;
      portMemCopy(uVar8 * iVar2 + uVar3,iVar2,(uVar8 * iVar2 - iVar2) + uVar3,iVar2);
      uVar3 = *param_1;
      iVar2 = (int)param_1[2];
      uVar8 = uVar9;
    } while (uVar9 != param_2);
    uVar9 = (int)param_1[3] + 1;
  }
  else {
    uVar3 = *param_1;
    iVar2 = (int)param_1[2];
    uVar9 = uVar8 + 1;
  }
LAB_004f5da6:
  *(uint *)(param_1 + 3) = uVar9;
  lVar5 = param_2 * iVar2 + uVar3;
  portMemCopy(lVar5,iVar2,param_3,iVar2);
  return lVar5;
}


// ===== 004f5e70 vectAppend_IMPL =====

void vectAppend_IMPL(long param_1,undefined8 param_2)

{
  vectInsert_IMPL(param_1,*(undefined4 *)(param_1 + 0x18),param_2);
  return;
}


// ===== 004f5e80 vectIterRange_IMPL =====

undefined8 * vectIterRange_IMPL(undefined8 *param_1,long *param_2,long param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog("pVector != NULL","src/libraries/containers/vector.c",0x118);
  }
  if ((param_3 != 0) && (param_4 != 0)) {
    uVar3 = (uint)((param_3 - *param_2) / (long)(ulong)*(uint *)(param_2 + 2));
    uVar1 = (uint)((param_4 - *param_2) / (long)(ulong)*(uint *)(param_2 + 2));
    uVar2 = uVar3;
    if (uVar3 <= uVar1) {
      uVar2 = uVar1;
    }
    if (uVar2 < *(uint *)(param_2 + 3)) {
      bVar4 = uVar3 <= uVar1;
      goto LAB_004f5edd;
    }
  }
  uVar3 = 0xffffffff;
  uVar1 = 0xffffffff;
  bVar4 = true;
LAB_004f5edd:
  *(bool *)(param_1 + 4) = bVar4;
  *param_1 = 0;
  param_1[1] = param_2;
  *(uint *)(param_1 + 2) = uVar3;
  *(uint *)((long)param_1 + 0x14) = uVar1;
  *(uint *)(param_1 + 3) = uVar3;
  *(uint *)((long)param_1 + 0x1c) = uVar1;
  return param_1;
}


// ===== 004f5f60 vectIterNext_IMPL =====

undefined8 vectIterNext_IMPL(long param_1,long *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pIter != NULL","src/libraries/containers/vector.c",0x144);
  }
  else if (param_2 == (long *)0x0) {
    nvAssertFailedNoLog("ppValue != NULL","src/libraries/containers/vector.c",0x145);
  }
  else if (*(int *)(param_1 + 0x10) != -1) {
    *param_2 = (ulong)(uint)(*(int *)(param_1 + 0x10) * (int)(*(long **)(param_1 + 8))[2]) +
               **(long **)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0x10);
    if (*(char *)(param_1 + 0x20) == '\0') {
      *(int *)(param_1 + 0x14) = iVar2 + 1;
      iVar1 = iVar2 + -1;
    }
    else {
      *(int *)(param_1 + 0x14) = iVar2 + -1;
      iVar1 = iVar2 + 1;
    }
    if (*(int *)(param_1 + 0x1c) == iVar2) {
      *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
    }
    else {
      *(int *)(param_1 + 0x10) = iVar1;
    }
    return 1;
  }
  return 0;
}


// ===== 004f6010 _crashcatEngineUnmapBufferDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _crashcatEngineUnmapBufferDescriptor(long *param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(param_2 + 0x14);
  if (uVar1 < 2) {
    uVar2 = (**(code **)(*param_1 + 0x50))();
    return uVar2;
  }
  if (uVar1 - 2 < 2) {
    uVar2 = portMemFree(*(undefined8 *)(param_2 + 8));
    return uVar2;
  }
  uVar2 = *(undefined8 *)(param_2 + 0x18);
  nvDbg_Printf("src/libraries/crashcat/crashcat_engine.c",0xd7,
               "_crashcatEngineUnmapBufferDescriptor",3,
               "NVRM: Unknown CrashCat aperture ID 0x%02x (offset = 0x%llx, size = 0x%llx)\n",uVar1,
               uVar2,*(undefined8 *)(param_2 + 0x20));
  return uVar2;
}


// ===== 004f6080 crashcatEngineLoadWayfinder_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong crashcatEngineLoadWayfinder_IMPL(long *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar1 = (**(code **)(*param_1 + 0x68))();
  uVar2 = (**(code **)(*param_1 + 0x38))(param_1,uVar1);
  uVar3 = 0x10006;
  if ((short)uVar2 == -0x2153) {
    uVar3 = __nvoc_objCreate_CrashCatWayfinder(param_1 + 3,param_1,0,uVar2 >> 0x10 & 0xf);
    if ((int)uVar3 != 0) {
      nvCheckOkFailedNoLog
                (4,uVar3 & 0xffffffff,
                 "objCreate(&pCrashCatEng->pWayfinder, pCrashCatEng, CrashCatWayfinder, crashcatWayfinderL0Version(wfl0), wfl0)"
                 ,"src/libraries/crashcat/crashcat_engine.c",0x31);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
  return uVar3;
}


// ===== 004f6110 crashcatEngineGetNextCrashReport_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 crashcatEngineGetNextCrashReport_IMPL(long *param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  cVar1 = (**(code **)(*param_1 + 0x20))();
  if (cVar1 != '\0') {
    lVar3 = param_1[3];
    if (lVar3 == 0) {
      iVar2 = crashcatEngineLoadWayfinder_IMPL(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      lVar3 = param_1[3];
    }
    lVar3 = crashcatWayfinderGetReportQueue_V1(lVar3);
    if (lVar3 != 0) {
      uVar4 = crashcatQueueConsumeNextReport_V1(lVar3);
      return uVar4;
    }
  }
  return 0;
}


// ===== 004f6180 crashcatEngineConstruct_IMPL =====

undefined8 crashcatEngineConstruct_IMPL(long param_1)

{
  mapInitIntrusive_IMPL(param_1 + 0x20,0x28);
  mapInitIntrusive_IMPL(param_1 + 0x30,0x50);
  return 0;
}


// ===== 004f61c0 crashcatEngineDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void crashcatEngineDestruct_IMPL(long *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x18))();
  iVar1 = mapCount_IMPL(param_1 + 6);
  if (iVar1 == 0) {
    iVar1 = mapCount_IMPL(param_1 + 4);
  }
  else {
    nvAssertFailedNoLog("mapCount(&pCrashCatEng->mappedCrashBuffers) == 0",
                        "src/libraries/crashcat/crashcat_engine.c",0x5e);
    iVar1 = mapCount_IMPL(param_1 + 4);
  }
  if (iVar1 != 0) {
    nvAssertFailedNoLog("mapCount(&pCrashCatEng->registeredCrashBuffers) == 0",
                        "src/libraries/crashcat/crashcat_engine.c",0x5f);
  }
  mapDestroyIntrusive_IMPL(param_1 + 6);
  mapDestroyIntrusive_IMPL(param_1 + 4);
  return;
}


// ===== 004f6260 crashcatEngineUnload_IMPL =====

void crashcatEngineUnload_IMPL(long param_1)

{
  __nvoc_objDelete(*(undefined8 *)(param_1 + 0x18));
  return;
}


// ===== 004f6270 crashcatEnginePrintf =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void crashcatEnginePrintf(long *param_1)

{
  (**(code **)(*param_1 + 0x28))();
  return;
}


// ===== 004f62c0 crashcatEngineRegisterCrashBuffer_IMPL =====

undefined8
crashcatEngineRegisterCrashBuffer_IMPL
          (long param_1,uint param_2,ulong param_3,long param_4,long param_5)

{
  char cVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if (param_2 < 2) {
    if (param_4 == 0) {
      nvCheckFailedNoLog(1,"size > 0","src/libraries/crashcat/crashcat_engine.c",0xeb);
    }
    else {
      if (param_5 != 0) {
        plVar2 = (long *)portMemAllocNonPaged(0x78);
        uVar3 = 0x51;
        if (plVar2 != (long *)0x0) {
          portMemSet(plVar2,0,0x78);
          *(uint *)((long)plVar2 + 0x14) = param_2;
          plVar2[3] = param_3;
          plVar2[4] = param_4;
          *plVar2 = param_5;
          *(undefined1 *)(plVar2 + 2) = 1;
          cVar1 = mapInsertExisting_IMPL(param_1 + 0x20,param_2 | param_3,plVar2);
          uVar3 = 0;
          if (cVar1 == '\0') {
            portMemFree(plVar2);
            uVar3 = 0x19;
          }
        }
        return uVar3;
      }
      nvCheckFailedNoLog(1,"pEngPriv != NULL","src/libraries/crashcat/crashcat_engine.c",0xec);
    }
  }
  else {
    nvCheckFailedNoLog(1,
                       "(aperture == NV_CRASHCAT_MEM_APERTURE_SYSGPA) || (aperture == NV_CRASHCAT_MEM_APERTURE_FBGPA)"
                       ,"src/libraries/crashcat/crashcat_engine.c",0xe8);
  }
  return 0x1f;
}


// ===== 004f6420 crashcatEngineUnregisterCrashBuffer_IMPL =====

void crashcatEngineUnregisterCrashBuffer_IMPL(long param_1,uint param_2,ulong param_3)

{
  long lVar1;
  
  lVar1 = mapFind_IMPL(param_1 + 0x20,param_2 | param_3);
  if (lVar1 != 0) {
    mapRemoveIntrusive_IMPL(param_1 + 0x20,lVar1);
    portMemFree(lVar1);
    return;
  }
  return;
}


// ===== 004f6470 crashcatEngineMapCrashBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long crashcatEngineMapCrashBuffer_IMPL(long *param_1,uint param_2,ulong param_3,undefined8 param_4)

{
  char cVar1;
  undefined8 *puVar2;
  long lVar3;
  undefined8 uVar4;
  
  puVar2 = (undefined8 *)mapFind_IMPL(param_1 + 4,param_2 | param_3);
  if (param_2 == 0) {
    if (puVar2 == (undefined8 *)0x0) {
LAB_004f65b0:
      nvCheckFailedNoLog(4,"pBufDesc != NULL","src/libraries/crashcat/crashcat_engine.c",299);
      return 0;
    }
LAB_004f64b4:
    param_2 = *(uint *)((long)puVar2 + 0x14);
  }
  else {
    if (puVar2 != (undefined8 *)0x0) goto LAB_004f64b4;
    puVar2 = (undefined8 *)portMemAllocNonPaged(0x78);
    if (puVar2 == (undefined8 *)0x0) goto LAB_004f65b0;
    portMemSet(puVar2,0,0x78);
    *(undefined1 *)(puVar2 + 2) = 0;
    *(uint *)((long)puVar2 + 0x14) = param_2;
    puVar2[3] = param_3;
    puVar2[4] = param_4;
    *puVar2 = 0;
  }
  if (param_2 < 2) {
    lVar3 = (**(code **)(*param_1 + 0x48))(param_1,puVar2);
    uVar4 = 0xb1;
    if (lVar3 == 0) {
LAB_004f6530:
      nvCheckFailedNoLog(4,"ptr != NULL","src/libraries/crashcat/crashcat_engine.c",uVar4);
      puVar2[1] = 0;
      goto LAB_004f6619;
    }
  }
  else {
    if (1 < param_2 - 2) {
      nvDbg_Printf("src/libraries/crashcat/crashcat_engine.c",0xbc,
                   "_crashcatEngineMapBufferDescriptor",3,
                   "NVRM: Unknown CrashCat aperture ID 0x%02x (offset = 0x%llx, size = 0x%llx)\n",
                   param_2,puVar2[3]);
      puVar2[1] = 0;
      goto LAB_004f6619;
    }
    lVar3 = portMemAllocNonPaged(puVar2[4]);
    if (lVar3 == 0) {
      uVar4 = 0xb8;
      goto LAB_004f6530;
    }
  }
  puVar2[1] = lVar3;
  cVar1 = mapInsertExisting_IMPL(param_1 + 6,lVar3,puVar2);
  if (cVar1 != '\0') {
    return puVar2[1];
  }
  if (puVar2[1] != 0) {
    _crashcatEngineUnmapBufferDescriptor(param_1,puVar2);
    puVar2[1] = 0;
  }
LAB_004f6619:
  if (*(char *)(puVar2 + 2) == '\0') {
    portMemFree(puVar2);
  }
  return 0;
}


// ===== 004f6660 crashcatEngineUnmapCrashBuffer_IMPL =====

void crashcatEngineUnmapCrashBuffer_IMPL(long param_1)

{
  long lVar1;
  
  lVar1 = mapFind_IMPL(param_1 + 0x30);
  if (lVar1 != 0) {
    mapRemoveIntrusive_IMPL(param_1 + 0x30,lVar1);
    _crashcatEngineUnmapBufferDescriptor(param_1,lVar1);
    *(undefined8 *)(lVar1 + 8) = 0;
    if (*(char *)(lVar1 + 0x10) == '\0') {
      portMemFree(lVar1);
      return;
    }
  }
  return;
}


// ===== 004f66e0 crashcatEngineSyncCrashBuffer_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

void crashcatEngineSyncCrashBuffer_IMPL
               (long *param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = mapFind_IMPL(param_1 + 6);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pBufDesc != NULL","src/libraries/crashcat/crashcat_engine.c",0x165);
    return;
  }
  if (1 < *(uint *)(lVar1 + 0x14)) {
    (**(code **)(*param_1 + 0x58))(param_1,lVar1,param_3,param_4,*(code **)(*param_1 + 0x58));
    return;
  }
  return;
}


// ===== 004f6770 crashcatQueueConstruct_IMPL =====

undefined8 crashcatQueueConstruct_IMPL(long param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = objFindAncestor_IMPL(param_1,0x654166);
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = objFindAncestor_IMPL(param_1,0x654166);
  }
  uVar3 = __nvoc_dynamicCast(uVar2,__nvoc_class_def_CrashCatEngine);
  *(undefined8 *)(param_1 + 0x60) = uVar3;
  *(undefined8 *)(param_1 + 0x48) = *param_2;
  uVar2 = param_2[1];
  *(undefined8 *)(param_1 + 0x50) = uVar2;
  *(undefined8 *)(param_1 + 0x58) = param_2[2];
  lVar1 = crashcatEngineMapCrashBuffer_IMPL
                    (uVar3,*(undefined4 *)(param_1 + 0x48),uVar2,*(undefined4 *)(param_1 + 0x4c));
  *(long *)(param_1 + 0x68) = lVar1;
  if (lVar1 != 0) {
    return 0;
  }
  nvCheckFailedNoLog(3,"pQueue->pMapping != NULL","src/libraries/crashcat/crashcat_queue.c",0x22);
  return 0x32;
}


// ===== 004f6820 crashcatQueueDestruct_IMPL =====

void crashcatQueueDestruct_IMPL(long param_1)

{
  crashcatEngineUnmapCrashBuffer_IMPL
            (*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68));
  return;
}


// ===== 004f6840 crashcatReportConstruct_IMPL =====

undefined8 crashcatReportConstruct_IMPL(long param_1,long *param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = objFindAncestor_IMPL(param_1,0x654166);
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = objFindAncestor_IMPL(param_1,0x654166);
  }
  uVar2 = __nvoc_dynamicCast(uVar2,__nvoc_class_def_CrashCatEngine);
  *(undefined8 *)(param_1 + 0x70) = uVar2;
  lVar1 = *param_2;
  lVar3 = crashcatReportExtract_V1(param_1,lVar1,param_3);
  uVar2 = 0;
  *param_2 = lVar3;
  if (lVar3 == lVar1) {
    nvDbg_Printf("src/libraries/crashcat/crashcat_report.c",0x2c,"crashcatReportConstruct_IMPL",4,
                 "NVRM: no report data extracted from %llu bytes\n",param_3);
    uVar2 = 0x25;
  }
  return uVar2;
}


// ===== 004f68e0 crashcatReportLog_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void crashcatReportLog_IMPL(long param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((~*(uint *)(param_1 + 0x78) & 1) != 0) {
    nvAssertFailedNoLog("(pReport->validTags & NVBIT(NV_CRASHCAT_PACKET_TYPE_REPORT)) != 0",
                        "src/libraries/crashcat/crashcat_report.c",0x37);
    return;
  }
  (**(code **)(**(long **)(param_1 + 0x70) + 0x30))();
  (**(code **)(param_1 + 0x58))(param_1);
  (**(code **)(param_1 + 0x50))(param_1);
  uVar2 = *(uint *)(param_1 + 0x78) & 0xfffffffe;
  uVar1 = 0;
  if (uVar2 != 0) {
    do {
      for (; (uVar2 & 1) == 0; uVar2 = uVar2 >> 1) {
        uVar1 = uVar1 + 1;
      }
      if (uVar1 == 3) {
        crashcatReportLogRiscv64Traces_V1(param_1);
      }
      else if (uVar1 < 4) {
        if (uVar1 == 1) {
          crashcatReportLogRiscv64CsrState_V1(param_1);
        }
        else {
          if (uVar1 != 2) goto LAB_004f69c0;
          crashcatReportLogRiscv64GprState_V1(param_1);
        }
      }
      else if (uVar1 == 4) {
        crashcatReportLogIo32State_V1(param_1);
      }
      else {
LAB_004f69c0:
        nvDbg_Printf("src/libraries/crashcat/crashcat_report.c",0x51,"crashcatReportLog_IMPL",3,
                     "NVRM: unrecognized packet type 0x%02x\n",uVar1);
      }
      if (uVar2 >> 1 == 0) break;
      uVar2 = uVar2 >> 1;
      uVar1 = uVar1 + 1;
    } while( true );
  }
  nv_printf(0xffffffff,"NVRM:     ------------[ end crash report ]------------\n");
  return;
}


// ===== 004f6a20 crashcatReportRiscvCauseToString =====

char * crashcatReportRiscvCauseToString(ulong param_1)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = (uint)param_1 & 0x1f;
  if ((long)param_1 < 0) {
    pcVar2 = "unknown interrupt";
    if ((byte)uVar1 < 0xc) {
      return *(char **)(CSWTCH_9 + (ulong)uVar1 * 8);
    }
  }
  else {
    pcVar2 = "unknown exception";
    if ((param_1 & 0x10) == 0) {
      return *(char **)(CSWTCH_10 + (ulong)uVar1 * 8);
    }
  }
  return pcVar2;
}


// ===== 004f6a70 crashcatWayfinderConstruct_IMPL =====

undefined8 crashcatWayfinderConstruct_IMPL(void)

{
  crashcatWayfinderSetWFL0_V1();
  return 0;
}


// ===== 004f6a90 crashcatWayfinderDestruct_IMPL =====

void crashcatWayfinderDestruct_IMPL(long param_1)

{
  __nvoc_objDelete(*(undefined8 *)(param_1 + 0x50));
  return;
}


// ===== 004f6aa0 crashcatQueueConsumeNextReport_V1 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 crashcatQueueConsumeNextReport_V1(long param_1)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  uint uVar7;
  ulong uVar9;
  undefined8 local_48;
  ulong *local_40 [2];
  ulong uVar8;
  
  uVar1 = *(uint *)(param_1 + 0x4c);
  uVar3 = (**(code **)(**(long **)(param_1 + 0x60) + 0x38))
                    (*(long **)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x58));
  uVar4 = (**(code **)(**(long **)(param_1 + 0x60) + 0x38))
                    (*(long **)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x5c));
  if (uVar1 <= uVar4) {
    nvCheckFailedNoLog(4,"get < size","src/libraries/crashcat/v1/crashcat_queue_v1.c",0x41);
    return 0;
  }
  if (uVar1 <= uVar3) {
    nvCheckFailedNoLog(4,"put < size","src/libraries/crashcat/v1/crashcat_queue_v1.c",0x42);
    return 0;
  }
  if (uVar4 == uVar3) {
    return 0;
  }
  if (uVar4 < uVar3) {
    uVar8 = (ulong)(uVar3 - uVar4);
  }
  else {
    uVar9 = (ulong)(uVar1 - uVar4);
    uVar8 = uVar9;
    if (uVar3 != 0) {
      uVar7 = (uVar1 - uVar4) + uVar3;
      uVar8 = (ulong)uVar7;
      puVar6 = (ulong *)portMemAllocNonPaged(uVar8);
      if (puVar6 == (ulong *)0x0) {
        nvCheckFailedNoLog(4,"pBuf != NULL","src/libraries/crashcat/v1/crashcat_queue_v1.c",0x5e);
        return 0;
      }
      crashcatEngineSyncCrashBuffer_IMPL
                (*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68),uVar4,uVar9);
      portMemCopy(puVar6,uVar9,(ulong)uVar4 + *(long *)(param_1 + 0x68),uVar9);
      crashcatEngineSyncCrashBuffer_IMPL
                (*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68),0,uVar3);
      portMemCopy((long)puVar6 + uVar9,uVar3,*(undefined8 *)(param_1 + 0x68),uVar3);
      bVar2 = true;
      goto LAB_004f6bb4;
    }
  }
  uVar7 = (uint)uVar8;
  crashcatEngineSyncCrashBuffer_IMPL
            (*(undefined8 *)(param_1 + 0x60),*(undefined8 *)(param_1 + 0x68),uVar4,uVar8);
  puVar6 = (ulong *)((ulong)uVar4 + *(long *)(param_1 + 0x68));
  bVar2 = false;
LAB_004f6bb4:
  local_48 = 0;
  local_40[0] = puVar6;
  if ((((uint)*puVar6 & 0xeffff) == 0xdead) && ((*puVar6 & 0xf0000) != 0)) {
    iVar5 = __nvoc_objCreate_CrashCatReport(&local_48,param_1,0,1,puVar6[1],local_40,uVar8);
    if (iVar5 == 0) {
      if ((long)local_40[0] - (long)puVar6 != 0) {
        uVar7 = (uint)((long)local_40[0] - (long)puVar6);
      }
    }
    else {
      nvCheckOkFailedNoLog
                (4,iVar5,
                 "objCreate(&pReport, pQueue, CrashCatReport, reportFormatVersion, reportImplementer, &pReadBuf, readSize)"
                 ,"src/libraries/crashcat/v1/crashcat_queue_v1.c",0x79);
    }
  }
  else {
    nvCheckFailedNoLog(4,"crashcatPacketHeaderValid(header)",
                       "src/libraries/crashcat/v1/crashcat_queue_v1.c",0x29);
    nvCheckOkFailedNoLog
              (4,0x25,
               "_getCrashCatReportHalspecArgs(pBuf, &reportFormatVersion, &reportImplementer)",
               "src/libraries/crashcat/v1/crashcat_queue_v1.c",0x75);
  }
  (**(code **)(**(long **)(param_1 + 0x60) + 0x40))
            (*(long **)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x5c),
             (ulong)(uVar7 + uVar4) % (ulong)uVar1);
  if (bVar2) {
    portMemFree(puVar6);
    return local_48;
  }
  return local_48;
}


// ===== 004f6da0 crashcatReportLogRiscv64Trace_V1.isra.0 =====

void crashcatReportLogRiscv64Trace_V1_isra_0(ulong *param_1)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong *puVar8;
  uint uVar9;
  ushort uVar10;
  uint uVar11;
  int iVar12;
  
  uVar6 = *param_1;
  uVar5 = ((uint)(uVar6 >> 0x14) & 3) - 1;
  if (uVar5 < 3) {
    uVar7 = ((ulong)((uint)(uVar6 >> 0x16) & 0x3ff) + 1 <<
            (*(byte *)((long)&CSWTCH_25 + (ulong)uVar5) & 0x3f)) >> 3;
    uVar10 = (ushort)uVar7;
    iVar12 = (int)uVar7;
    if ((uVar6 >> 0x2b & 1) == 0) {
      nv_printf(0xffffffff,"NVRM:     Stack Trace:\n");
      if (uVar10 == 0) {
        return;
      }
LAB_004f6f24:
      puVar8 = param_1 + 1;
      do {
        uVar6 = *puVar8;
        puVar8 = puVar8 + 1;
        nv_printf(0xffffffff,"NVRM:         0x%016llx\n",uVar6);
      } while (param_1 + (ulong)(iVar12 - 1U & 0xffff) + 2 != puVar8);
      return;
    }
  }
  else {
    iVar12 = ((uint)(uVar6 >> 0x16) & 0x3ff) + 1;
    uVar10 = (ushort)iVar12;
    if ((uVar6 >> 0x2b & 1) == 0) {
      nv_printf(0xffffffff,"NVRM:     Stack Trace:\n");
      goto LAB_004f6f24;
    }
  }
  uVar5 = (uint)uVar10;
  nv_printf(0xffffffff,"NVRM:     PC Trace:\n");
  uVar11 = (uint)uVar10;
  if (uVar10 < 5) {
    uVar6 = 0;
    if (uVar10 == 3) goto LAB_004f7008;
    if (uVar11 == 4) goto LAB_004f6fa6;
  }
  else {
    puVar8 = param_1 + 1;
    uVar9 = 0;
    do {
      puVar1 = puVar8 + 1;
      uVar6 = *puVar8;
      puVar2 = puVar8 + 4;
      puVar3 = puVar8 + 3;
      uVar9 = uVar9 + 5;
      puVar4 = puVar8 + 2;
      puVar8 = puVar8 + 5;
      nv_printf(0xffffffff,"NVRM:         0x%016llx  0x%016llx  0x%016llx  0x%016llx  0x%016llx\n",
                uVar6,*puVar1,*puVar4,*puVar3,*puVar2);
      uVar5 = uVar9 & 0xffff;
      uVar6 = (ulong)uVar5;
    } while (uVar5 < (uVar11 / 5) * 5);
    uVar5 = uVar11 - uVar5;
    if (uVar5 == 3) {
LAB_004f7008:
      nv_printf(0xffffffff,"NVRM:         0x%016llx  0x%016llx  0x%016llx\n",param_1[uVar6 + 1],
                param_1[uVar6 + 2],param_1[uVar6 + 3]);
      return;
    }
    if (3 < (int)uVar5) {
      if (uVar5 != 4) {
        return;
      }
LAB_004f6fa6:
      nv_printf(0xffffffff,"NVRM:         0x%016llx  0x%016llx  0x%016llx  0x%016llx\n",
                param_1[uVar6 + 1],param_1[uVar6 + 2],param_1[uVar6 + 3],param_1[uVar6 + 4]);
      return;
    }
  }
  if (uVar5 == 1) {
    nv_printf(0xffffffff,"NVRM:         0x%016llx\n",param_1[uVar6 + 1]);
    return;
  }
  if (uVar5 != 2) {
    return;
  }
  nv_printf(0xffffffff,"NVRM:         0x%016llx  0x%016llx\n",param_1[uVar6 + 1],
            param_1[(ulong)((int)uVar6 + 1) + 1]);
  return;
}


// ===== 004f7060 crashcatReportDestruct_V1 =====

void crashcatReportDestruct_V1(long param_1)

{
  portMemFree(*(undefined8 *)(param_1 + 0x200));
  portMemFree(*(undefined8 *)(param_1 + 0x208));
  portMemFree(*(undefined8 *)(param_1 + 0x210));
  return;
}


// ===== 004f70a0 crashcatReportExtractReport_V1 =====

ulong * crashcatReportExtractReport_V1(long param_1,ulong *param_2,ulong param_3)

{
  ulong uVar1;
  
  if (param_3 < 0x40) {
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x90,
                 "crashcatReportExtractReport_V1",3,
                 "NVRM: Not enough data (%llu bytes) to decode NvCrashCatReport_V1\n",param_3);
  }
  else {
    uVar1 = *param_2;
    if (((((uint)uVar1 & 0xfffff) == 0x1dead) && (2 < ((uint)(uVar1 >> 0x14) & 3) - 1)) &&
       (((uint)(uVar1 >> 0x16) & 0x3ff) == 6)) {
      *(ulong *)(param_1 + 0x80) = uVar1;
      *(ulong *)(param_1 + 0x88) = param_2[1];
      *(ulong *)(param_1 + 0x90) = param_2[2];
      *(ulong *)(param_1 + 0x98) = param_2[3];
      *(ulong *)(param_1 + 0xa0) = param_2[4];
      *(ulong *)(param_1 + 0xa8) = param_2[5];
      *(ulong *)(param_1 + 0xb0) = param_2[6];
      uVar1 = param_2[7];
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 1;
      *(ulong *)(param_1 + 0xb8) = uVar1;
      return param_2 + 8;
    }
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x9d,
                 "crashcatReportExtractReport_V1",3,"NVRM: Invalid V1 report header 0x%llx\n");
  }
  return param_2;
}


// ===== 004f71c0 crashcatReportExtractRiscv64CsrState_V1 =====

ulong * crashcatReportExtractRiscv64CsrState_V1(long param_1,ulong *param_2,ulong param_3)

{
  ulong uVar1;
  
  if (param_3 < 0x40) {
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0xb0,
                 "crashcatReportExtractRiscv64CsrState_V1",3,
                 "NVRM: Not enough data (%llu bytes) to decode NvCrashCatRiscv64CsrState_V1\n",
                 param_3);
  }
  else {
    uVar1 = *param_2;
    if (((((uint)uVar1 & 0xfffff) == 0x1dead) && (2 < ((uint)(uVar1 >> 0x14) & 3) - 1)) &&
       (((uint)(uVar1 >> 0x16) & 0x3ff) == 6)) {
      *(ulong *)(param_1 + 0xc0) = uVar1;
      *(ulong *)(param_1 + 200) = param_2[1];
      *(ulong *)(param_1 + 0xd0) = param_2[2];
      *(ulong *)(param_1 + 0xd8) = param_2[3];
      *(ulong *)(param_1 + 0xe0) = param_2[4];
      *(ulong *)(param_1 + 0xe8) = param_2[5];
      *(ulong *)(param_1 + 0xf0) = param_2[6];
      uVar1 = param_2[7];
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 2;
      *(ulong *)(param_1 + 0xf8) = uVar1;
      return param_2 + 8;
    }
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0xbd,
                 "crashcatReportExtractRiscv64CsrState_V1",3,
                 "NVRM: Invalid V1 RISCV CSR state header 0x%llx\n");
  }
  return param_2;
}


// ===== 004f72e0 crashcatReportExtractRiscv64GprState_V1 =====

ulong * crashcatReportExtractRiscv64GprState_V1(long param_1,ulong *param_2,ulong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  ulong uVar5;
  
  if (param_3 < 0x100) {
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0xd0,
                 "crashcatReportExtractRiscv64GprState_V1",3,
                 "NVRM: Not enough data (%llu bytes) to decode NvCrashCatRiscv64GprState_V1\n",
                 param_3);
  }
  else {
    uVar5 = *param_2;
    if (((((uint)uVar5 & 0xfffff) == 0x1dead) && (2 < ((uint)(uVar5 >> 0x14) & 3) - 1)) &&
       (((uint)(uVar5 >> 0x16) & 0x3ff) == 0x1e)) {
      uVar5 = 0;
      do {
        uVar4 = (int)uVar5 + 0x20;
        uVar1 = *(undefined8 *)((long)param_2 + uVar5 + 8);
        uVar2 = *(undefined8 *)((long)param_2 + uVar5 + 0x10);
        uVar3 = *(undefined8 *)((long)param_2 + uVar5 + 0x18);
        *(undefined8 *)(param_1 + 0x100 + uVar5) = *(undefined8 *)((long)param_2 + uVar5);
        *(undefined8 *)(param_1 + 0x108 + uVar5) = uVar1;
        *(undefined8 *)(param_1 + 0x110 + uVar5) = uVar2;
        *(undefined8 *)(param_1 + 0x118 + uVar5) = uVar3;
        uVar5 = (ulong)uVar4;
      } while (uVar4 < 0x100);
      *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 4;
      return param_2 + 0x20;
    }
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0xdd,
                 "crashcatReportExtractRiscv64GprState_V1",3,
                 "NVRM: Invalid V1 RISCV GPR state header 0x%llx\n");
  }
  return param_2;
}


// ===== 004f73f0 crashcatReportExtractRiscv64Trace_V1 =====

ulong * crashcatReportExtractRiscv64Trace_V1(long param_1,ulong *param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  byte bVar4;
  long lVar5;
  
  if (param_3 < 8) {
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0xf0,
                 "crashcatReportExtractRiscv64Trace_V1",3,
                 "NVRM: Not enough data (%llu bytes) to decode NvCrashCatRiscv64Trace_V1\n",param_3)
    ;
  }
  else {
    uVar2 = *param_2;
    if (((uint)uVar2 & 0xfffff) == 0x1dead) {
      bVar4 = 3;
      uVar3 = ((uint)(uVar2 >> 0x14) & 3) - 1;
      if (uVar3 < 3) {
        bVar4 = *(byte *)((long)&CSWTCH_25 + (ulong)uVar3);
      }
      lVar5 = (ulong)((uint)(uVar2 >> 0x16) & 0x3ff) + 1 << (bVar4 & 0x3f);
      lVar1 = lVar5 + 8;
      lVar5 = portMemAllocNonPaged(lVar5 + 8);
      if (lVar5 != 0) {
        portMemCopy(lVar5,lVar1,param_2,lVar1);
        if ((*(byte *)(lVar5 + 5) & 8) == 0) {
          if (*(long *)(param_1 + 0x200) != 0) {
            nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x111,
                         "crashcatReportExtractRiscv64Trace_V1",3,
                         "NVRM: Only one stack trace packet is supported, discarding the old one\n")
            ;
            portMemFree(*(undefined8 *)(param_1 + 0x200));
          }
          uVar3 = *(uint *)(param_1 + 0x78);
          *(long *)(param_1 + 0x200) = lVar5;
        }
        else {
          if (*(long *)(param_1 + 0x208) != 0) {
            nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x11c,
                         "crashcatReportExtractRiscv64Trace_V1",3,
                         "NVRM: Only one PC trace packet is supported, discarding the old one\n");
            portMemFree(*(undefined8 *)(param_1 + 0x208));
          }
          uVar3 = *(uint *)(param_1 + 0x78);
          *(long *)(param_1 + 0x208) = lVar5;
        }
        *(uint *)(param_1 + 0x78) = uVar3 | 8;
        return (ulong *)((long)param_2 + lVar1);
      }
      nvCheckFailedNoLog(4,"pRiscv64Trace != NULL","src/libraries/crashcat/v1/crashcat_report_v1.c",
                         0x104);
    }
    else {
      nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0xfa,
                   "crashcatReportExtractRiscv64Trace_V1",3,
                   "NVRM: Invalid V1 trace packet header 0x%llx\n");
    }
  }
  return param_2;
}


// ===== 004f7610 crashcatReportExtractIo32State_V1 =====

ulong * crashcatReportExtractIo32State_V1(long param_1,ulong *param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  byte bVar4;
  long lVar5;
  
  if (param_3 < 8) {
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x137,
                 "crashcatReportExtractIo32State_V1",3,
                 "NVRM: Not enough data (%llu bytes) to decode NvCrashCatIo32State_V1\n",param_3);
  }
  else if ((*(byte *)(param_1 + 0x78) & 0x10) == 0) {
    uVar2 = *param_2;
    if (((uint)uVar2 & 0xfffff) == 0x1dead) {
      bVar4 = 3;
      uVar3 = ((uint)(uVar2 >> 0x14) & 3) - 1;
      if (uVar3 < 3) {
        bVar4 = *(byte *)((long)&CSWTCH_25 + (ulong)uVar3);
      }
      lVar5 = (ulong)((uint)(uVar2 >> 0x16) & 0x3ff) + 1 << (bVar4 & 0x3f);
      lVar1 = lVar5 + 8;
      lVar5 = portMemAllocNonPaged(lVar5 + 8);
      *(long *)(param_1 + 0x210) = lVar5;
      if (lVar5 != 0) {
        portMemCopy(lVar5,lVar1,param_2,lVar1);
        *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x10;
        return (ulong *)((long)param_2 + lVar1);
      }
      nvCheckFailedNoLog(4,"pReport->v1.pIo32State != NULL",
                         "src/libraries/crashcat/v1/crashcat_report_v1.c",0x155);
    }
    else {
      nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x14b,
                   "crashcatReportExtractIo32State_V1",3,
                   "NVRM: Invalid V1 reg32 state header 0x%llx\n");
    }
  }
  else {
    nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x143,
                 "crashcatReportExtractIo32State_V1",3,
                 "NVRM: Report already contains valid reg32 data, skipping\n");
  }
  return param_2;
}


// ===== 004f77b0 crashcatReportExtract_V1 =====

ulong * crashcatReportExtract_V1(undefined8 param_1,ulong *param_2,long param_3)

{
  ulong uVar1;
  uint uVar2;
  ulong *puVar3;
  ulong *puVar4;
  byte bVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  
  puVar3 = (ulong *)crashcatReportExtractReport_V1();
  if (param_2 != puVar3) {
    if (param_2 < puVar3) {
      lVar7 = (long)param_2 + (param_3 - (long)puVar3);
      while (lVar7 != 0) {
        uVar1 = *puVar3;
        if ((((uint)uVar1 & 0xeffff) != 0xdead) || ((uVar1 & 0xf0000) == 0)) {
          nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x57,
                       "crashcatReportExtract_V1",3,
                       "NVRM: Invalid packet header (0x%llx) found, skipping %llu bytes remaining\n"
                       ,uVar1,lVar7);
          return (ulong *)((long)puVar3 + lVar7);
        }
        uVar8 = (uint)(uVar1 >> 0x20) & 0xff;
        if ((uVar1 & 0xff00000000) == 0) {
          return puVar3;
        }
        if (uVar8 == 3) {
          puVar4 = (ulong *)crashcatReportExtractRiscv64Trace_V1(param_1,puVar3,lVar7);
LAB_004f789e:
          if (puVar3 == puVar4) goto LAB_004f7929;
          lVar7 = (long)puVar3 + (lVar7 - (long)puVar4);
          puVar3 = puVar4;
        }
        else {
          if ((uVar1 >> 0x20 & 0xfc) == 0) {
            if (uVar8 == 1) {
              puVar4 = (ulong *)crashcatReportExtractRiscv64CsrState_V1(param_1,puVar3,lVar7);
            }
            else {
              puVar4 = (ulong *)crashcatReportExtractRiscv64GprState_V1(param_1,puVar3,lVar7);
            }
            goto LAB_004f789e;
          }
          if (uVar8 == 4) {
            puVar4 = (ulong *)crashcatReportExtractIo32State_V1(param_1,puVar3,lVar7);
            goto LAB_004f789e;
          }
          nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x73,
                       "crashcatReportExtract_V1",3,"NVRM: Unsupported V1 packet type 0x%02x\n",
                       uVar8);
LAB_004f7929:
          bVar5 = 3;
          uVar2 = ((uint)(uVar1 >> 0x14) & 3) - 1;
          if (uVar2 < 3) {
            bVar5 = *(byte *)((long)&CSWTCH_25 + (ulong)uVar2);
          }
          lVar6 = ((ulong)((uint)(uVar1 >> 0x16) & 0x3ff) + 1 << (bVar5 & 0x3f)) + 8;
          lVar7 = lVar7 - lVar6;
          nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x7c,
                       "crashcatReportExtract_V1",3,
                       "NVRM: Unable to extract packet type 0x%02x (%llu bytes), skipping\n",uVar8,
                       lVar6);
          puVar3 = (ulong *)((long)puVar3 + lVar6);
        }
      }
    }
    else {
      nvAssertFailedNoLog("pStart < pEnd","src/libraries/crashcat/v1/crashcat_report_v1.c",0x48);
      puVar3 = param_2;
    }
  }
  return puVar3;
}


// ===== 004f79e0 crashcatReportLogRiscv64CsrState_V1 =====

void crashcatReportLogRiscv64CsrState_V1(long param_1)

{
  uint uVar1;
  
  uVar1 = (uint)((ulong)*(undefined8 *)(param_1 + 0xc0) >> 0x28) & 7;
  nv_printf(0xffffffff,"NVRM:     RISC-V CSR State:\n");
  if (uVar1 == 1) {
    nv_printf(0xffffffff,
              "NVRM:         mstatus:0x%016llx  mscratch:0x%016llx     mie:0x%016llx  mip:0x%016llx\n"
              ,*(undefined8 *)(param_1 + 200),*(undefined8 *)(param_1 + 0xf8),
              *(undefined8 *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xd8));
    nv_printf(0xffffffff,"NVRM:         mepc:0x%016llx  mbadaddr:0x%016llx  mcause:0x%016llx\n",
              *(undefined8 *)(param_1 + 0xe0),*(undefined8 *)(param_1 + 0xe8),
              *(undefined8 *)(param_1 + 0xf0));
    return;
  }
  if (uVar1 == 2) {
    nv_printf(0xffffffff,
              "NVRM:         sstatus:0x%016llx  sscratch:0x%016llx     sie:0x%016llx  sip:0x%016llx\n"
              ,*(undefined8 *)(param_1 + 200),*(undefined8 *)(param_1 + 0xf8),
              *(undefined8 *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xd8));
    nv_printf(0xffffffff,"NVRM:         sepc:0x%016llx     stval:0x%016llx  scause:0x%016llx\n",
              *(undefined8 *)(param_1 + 0xe0),*(undefined8 *)(param_1 + 0xe8),
              *(undefined8 *)(param_1 + 0xf0));
    return;
  }
  nvDbg_Printf("src/libraries/crashcat/v1/crashcat_report_v1.c",0x17d,
               "crashcatReportLogRiscv64CsrState_V1",3,
               "NVRM: Unexpected RISC-V mode (%u) CSR dump\n",uVar1);
  nv_printf(0xffffffff,
            "NVRM:         xstatus:0x%016llx  xscratch:0x%016llx     xie:0x%016llx  xip:0x%016llx\n"
            ,*(undefined8 *)(param_1 + 200),*(undefined8 *)(param_1 + 0xf8),
            *(undefined8 *)(param_1 + 0xd0),*(undefined8 *)(param_1 + 0xd8));
  nv_printf(0xffffffff,"NVRM:         xepc:0x%016llx     xtval:0x%016llx  xcause:0x%016llx\n",
            *(undefined8 *)(param_1 + 0xe0),*(undefined8 *)(param_1 + 0xe8),
            *(undefined8 *)(param_1 + 0xf0));
  return;
}


// ===== 004f7b70 crashcatReportLogRiscv64GprState_V1 =====

void crashcatReportLogRiscv64GprState_V1(long param_1)

{
  nv_printf(0xffffffff,"NVRM:     RISC-V GPR State:\n");
  nv_printf(0xffffffff,"NVRM:         ra:0x%016llx   sp:0x%016llx   gp:0x%016llx   tp:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x108),*(undefined8 *)(param_1 + 0x110),
            *(undefined8 *)(param_1 + 0x118),*(undefined8 *)(param_1 + 0x120));
  nv_printf(0xffffffff,"NVRM:         a0:0x%016llx   a1:0x%016llx   a2:0x%016llx   a3:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x150),*(undefined8 *)(param_1 + 0x158),
            *(undefined8 *)(param_1 + 0x160),*(undefined8 *)(param_1 + 0x168));
  nv_printf(0xffffffff,"NVRM:         a4:0x%016llx   a5:0x%016llx   a6:0x%016llx   a7:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x170),*(undefined8 *)(param_1 + 0x178),
            *(undefined8 *)(param_1 + 0x180),*(undefined8 *)(param_1 + 0x188));
  nv_printf(0xffffffff,"NVRM:         s0:0x%016llx   s1:0x%016llx   s2:0x%016llx   s3:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x140),*(undefined8 *)(param_1 + 0x148),
            *(undefined8 *)(param_1 + 400),*(undefined8 *)(param_1 + 0x198));
  nv_printf(0xffffffff,"NVRM:         s4:0x%016llx   s5:0x%016llx   s6:0x%016llx   s7:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x1a0),*(undefined8 *)(param_1 + 0x1a8),
            *(undefined8 *)(param_1 + 0x1b0),*(undefined8 *)(param_1 + 0x1b8));
  nv_printf(0xffffffff,"NVRM:         s8:0x%016llx   s9:0x%016llx  s10:0x%016llx  s11:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x1c0),*(undefined8 *)(param_1 + 0x1c8),
            *(undefined8 *)(param_1 + 0x1d0),*(undefined8 *)(param_1 + 0x1d8));
  nv_printf(0xffffffff,"NVRM:         t0:0x%016llx   t1:0x%016llx   t2:0x%016llx   t3:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x128),*(undefined8 *)(param_1 + 0x130),
            *(undefined8 *)(param_1 + 0x138),*(undefined8 *)(param_1 + 0x1e0));
  nv_printf(0xffffffff,"NVRM:         t4:0x%016llx   t5:0x%016llx   t6:0x%016llx\n",
            *(undefined8 *)(param_1 + 0x1e8),*(undefined8 *)(param_1 + 0x1f0),
            *(undefined8 *)(param_1 + 0x1f8));
  return;
}


// ===== 004f7d10 crashcatReportLogRiscv64Traces_V1 =====

void crashcatReportLogRiscv64Traces_V1(long param_1)

{
  if (*(long *)(param_1 + 0x200) == 0) {
    if (*(long *)(param_1 + 0x208) != 0) {
      crashcatReportLogRiscv64Trace_V1_isra_0();
      return;
    }
    return;
  }
  crashcatReportLogRiscv64Trace_V1_isra_0();
  if (*(long *)(param_1 + 0x208) != 0) {
    crashcatReportLogRiscv64Trace_V1_isra_0();
    return;
  }
  return;
}


// ===== 004f7d80 crashcatReportLogIo32State_V1 =====

ulong crashcatReportLogIo32State_V1(long param_1)

{
  long lVar1;
  ulong *puVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  byte bVar8;
  uint uVar9;
  ulong *puVar10;
  uint uVar11;
  
  bVar8 = 3;
  puVar2 = *(ulong **)(param_1 + 0x210);
  uVar7 = *puVar2;
  uVar9 = ((uint)(uVar7 >> 0x14) & 3) - 1;
  if (uVar9 < 3) {
    bVar8 = *(byte *)((long)&CSWTCH_25 + (ulong)uVar9);
  }
  uVar5 = (uint)(uVar7 >> 0x28) & 3;
  uVar9 = (uint)(((ulong)((uint)(uVar7 >> 0x16) & 0x3ff) + 1 << (bVar8 & 0x3f)) >> 3);
  if (uVar5 == 1) {
    nv_printf(0xffffffff,"NVRM:     Local I/O Register State:\n");
  }
  else if (uVar5 == 2) {
    nv_printf(0xffffffff,"NVRM:     External I/O Register State:\n");
  }
  else {
    nv_printf(0xffffffff,"NVRM:     Additional Register State:\n");
  }
  iVar3 = (int)(uVar9 & 0xffff) >> 2;
  if (iVar3 == 0) {
    uVar6 = uVar9 & 0xffff;
    uVar7 = 0;
    uVar5 = 0;
  }
  else {
    uVar5 = iVar3 * 4;
    uVar11 = 0;
    puVar10 = puVar2 + 1;
    do {
      uVar11 = uVar11 + 4;
      nv_printf(0xffffffff,
                "NVRM:         0x%08x:0x%08x   0x%08x:0x%08x   0x%08x:0x%08x   0x%08x:0x%08x\n",
                *(undefined4 *)((long)puVar10 + 4),(int)*puVar10,
                *(undefined4 *)((long)puVar10 + 0xc),(int)puVar10[1],
                *(undefined4 *)((long)puVar10 + 0x14),(int)puVar10[2],
                *(undefined4 *)((long)puVar10 + 0x1c),(int)puVar10[3]);
      uVar6 = uVar11 & 0xffff;
      uVar7 = (ulong)uVar6;
      puVar10 = puVar10 + 4;
    } while (uVar6 < uVar5);
    if (iVar3 == 1) {
      uVar5 = 4;
    }
    uVar6 = (uVar9 & 0xffff) - uVar6;
  }
  if (uVar6 == 2) {
    uVar7 = nv_printf(0xffffffff,"NVRM:         0x%08x:0x%08x   0x%08x:0x%08x\n",
                      *(undefined4 *)((long)puVar2 + uVar7 * 8 + 0xc),(int)puVar2[uVar7 + 1],
                      *(undefined4 *)((long)puVar2 + (ulong)(uVar5 + 1) * 8 + 0xc),
                      (int)puVar2[(ulong)(uVar5 + 1) + 1]);
    return uVar7;
  }
  if (uVar6 == 3) {
    lVar1 = uVar7 * 8;
    lVar4 = uVar7 + 1;
    uVar7 = (ulong)*(uint *)((long)puVar2 + (ulong)(uVar5 + 2) * 8 + 0xc);
    nv_printf(0xffffffff,"NVRM:         0x%08x:0x%08x   0x%08x:0x%08x   0x%08x:0x%08x\n",
              *(undefined4 *)((long)puVar2 + lVar1 + 0xc),(int)puVar2[lVar4],
              *(undefined4 *)((long)puVar2 + (ulong)(uVar5 + 1) * 8 + 0xc),
              (int)puVar2[(ulong)(uVar5 + 1) + 1],uVar7,(int)puVar2[(ulong)(uVar5 + 2) + 1]);
  }
  else if (uVar6 == 1) {
    uVar7 = nv_printf(0xffffffff,"NVRM:         0x%08x:0x%08x\n",
                      *(undefined4 *)((long)puVar2 + uVar7 * 8 + 0xc),(int)puVar2[uVar7 + 1]);
    return uVar7;
  }
  return uVar7;
}


// ===== 004f7fc0 crashcatReportLogToProtobuf_V1 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void crashcatReportLogToProtobuf_V1(long param_1,undefined8 param_2)

{
  undefined4 *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  ushort uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  ulong *puVar9;
  
  iVar5 = prbEncNestedStart(param_2,&DAT_00c49c28);
  if (iVar5 != 0) {
    return;
  }
  prbEncAddUInt64(param_2,&DAT_00c38548,*(undefined8 *)(param_1 + 0xb0));
  prbEncAddUInt64(param_2,&DAT_00c38608,*(undefined4 *)(param_1 + 0x9c));
  uVar4 = *(ushort *)(param_1 + 0xa2) & 7;
  if (uVar4 == 2) {
    iVar5 = prbEncAddEnum(param_2,&prb_fields_crashcat_report,3);
  }
  else if (uVar4 == 3) {
    iVar5 = prbEncAddEnum(param_2,&prb_fields_crashcat_report,4);
  }
  else if (uVar4 == 1) {
    iVar5 = prbEncAddEnum(param_2,&prb_fields_crashcat_report,2);
  }
  else {
    iVar5 = prbEncAddEnum(param_2,&prb_fields_crashcat_report,1);
  }
  (**(code **)(param_1 + 0x60))(param_1,param_2);
  uVar8 = *(uint *)(param_1 + 0xa8) & 0xf;
  if (uVar8 == 1) {
    if (iVar5 == 0) {
      prbEncAddEnum(param_2,&DAT_00c38518,3);
    }
  }
  else if (uVar8 == 2) {
    if (iVar5 == 0) {
      prbEncAddEnum(param_2,&DAT_00c38518,4);
    }
  }
  else if (uVar8 == 0) {
    if (iVar5 == 0) {
      prbEncAddEnum(param_2,&DAT_00c38518,2);
    }
  }
  else if (iVar5 == 0) {
    prbEncAddEnum(param_2,&DAT_00c38518,1);
  }
  prbEncAddUInt32(param_2,&DAT_00c38560,*(undefined1 *)(param_1 + 0xa0));
  prbEncAddUInt32(param_2,&DAT_00c38578,*(undefined1 *)(param_1 + 0xa1));
  prbEncAddUInt32(param_2,&DAT_00c38590,*(undefined1 *)(param_1 + 0x90));
  prbEncAddUInt32(param_2,&DAT_00c385a8,*(undefined1 *)(param_1 + 0x91));
  iVar5 = prbEncNestedStart(param_2,&DAT_00c38620);
  if (iVar5 == 0) {
    prbEncAddUInt64(param_2,0xc38a18,*(undefined8 *)(param_1 + 200));
    prbEncAddUInt64(param_2,0xc38a30,*(undefined8 *)(param_1 + 0xd0));
    prbEncAddUInt64(param_2,0xc38a48,*(undefined8 *)(param_1 + 0xd8));
    prbEncAddUInt64(param_2,0xc38a60,*(undefined8 *)(param_1 + 0xe0));
    prbEncAddUInt64(param_2,0xc38a78,*(undefined8 *)(param_1 + 0xe8));
    prbEncAddUInt64(param_2,0xc38a90,*(undefined8 *)(param_1 + 0xf0));
    prbEncAddUInt64(param_2,0xc38aa8,*(undefined8 *)(param_1 + 0xf8));
    prbEncNestedEnd(param_2);
  }
  iVar5 = prbEncNestedStart(param_2,&DAT_00c38638);
  if (iVar5 == 0) {
    prbEncAddUInt64(param_2,0xc38718,*(undefined8 *)(param_1 + 0x108));
    prbEncAddUInt64(param_2,0xc38730,*(undefined8 *)(param_1 + 0x110));
    prbEncAddUInt64(param_2,0xc38748,*(undefined8 *)(param_1 + 0x118));
    prbEncAddUInt64(param_2,0xc38760,*(undefined8 *)(param_1 + 0x120));
    prbEncAddUInt64(param_2,0xc387f0,*(undefined8 *)(param_1 + 0x150));
    prbEncAddUInt64(param_2,0xc38808,*(undefined8 *)(param_1 + 0x158));
    prbEncAddUInt64(param_2,0xc38820,*(undefined8 *)(param_1 + 0x160));
    prbEncAddUInt64(param_2,0xc38838,*(undefined8 *)(param_1 + 0x168));
    prbEncAddUInt64(param_2,0xc38850,*(undefined8 *)(param_1 + 0x170));
    prbEncAddUInt64(param_2,0xc38868,*(undefined8 *)(param_1 + 0x178));
    prbEncAddUInt64(param_2,0xc38880,*(undefined8 *)(param_1 + 0x180));
    prbEncAddUInt64(param_2,0xc38898,*(undefined8 *)(param_1 + 0x188));
    prbEncAddUInt64(param_2,0xc387c0,*(undefined8 *)(param_1 + 0x140));
    prbEncAddUInt64(param_2,0xc387d8,*(undefined8 *)(param_1 + 0x148));
    prbEncAddUInt64(param_2,0xc388b0,*(undefined8 *)(param_1 + 400));
    prbEncAddUInt64(param_2,0xc388c8,*(undefined8 *)(param_1 + 0x198));
    prbEncAddUInt64(param_2,0xc388e0,*(undefined8 *)(param_1 + 0x1a0));
    prbEncAddUInt64(param_2,0xc388f8,*(undefined8 *)(param_1 + 0x1a8));
    prbEncAddUInt64(param_2,0xc38910,*(undefined8 *)(param_1 + 0x1b0));
    prbEncAddUInt64(param_2,0xc38928,*(undefined8 *)(param_1 + 0x1b8));
    prbEncAddUInt64(param_2,0xc38940,*(undefined8 *)(param_1 + 0x1c0));
    prbEncAddUInt64(param_2,0xc38958,*(undefined8 *)(param_1 + 0x1c8));
    prbEncAddUInt64(param_2,0xc38970,*(undefined8 *)(param_1 + 0x1d0));
    prbEncAddUInt64(param_2,0xc38988,*(undefined8 *)(param_1 + 0x1d8));
    prbEncAddUInt64(param_2,0xc38778,*(undefined8 *)(param_1 + 0x128));
    prbEncAddUInt64(param_2,0xc38790,*(undefined8 *)(param_1 + 0x130));
    prbEncAddUInt64(param_2,0xc387a8,*(undefined8 *)(param_1 + 0x138));
    prbEncAddUInt64(param_2,0xc389a0,*(undefined8 *)(param_1 + 0x1e0));
    prbEncAddUInt64(param_2,0xc389b8,*(undefined8 *)(param_1 + 0x1e8));
    prbEncAddUInt64(param_2,0xc389d0,*(undefined8 *)(param_1 + 0x1f0));
    prbEncAddUInt64(param_2,0xc389e8,*(undefined8 *)(param_1 + 0x1f8));
    prbEncNestedEnd(param_2);
  }
  puVar9 = *(ulong **)(param_1 + 0x210);
  if (puVar9 != (ulong *)0x0) {
    uVar6 = (ulong)((uint)(*puVar9 >> 0x16) & 0x3ff) + 1;
    uVar8 = ((uint)(*puVar9 >> 0x14) & 3) - 1;
    if ((2 < uVar8) ||
       (uVar7 = (uVar6 << (*(byte *)((long)&CSWTCH_25 + (ulong)uVar8) & 0x3f)) >> 3,
       uVar6 = uVar7 & 0xffff, (short)uVar7 != 0)) {
      puVar3 = puVar9 + uVar6;
      do {
        while (iVar5 = prbEncNestedStart(param_2,&DAT_00c38680), iVar5 == 0) {
          puVar1 = (undefined4 *)((long)puVar9 + 0xc);
          puVar9 = puVar9 + 1;
          prbEncAddUInt32(param_2,prb_fields_crashcat_localioregister,*puVar1);
          prbEncAddUInt32(param_2,0xc386d8,(int)*puVar9);
          iVar5 = prbEncNestedEnd(param_2);
          if (puVar9 == puVar3) goto LAB_004f81f1;
        }
        puVar9 = puVar9 + 1;
      } while (puVar9 != puVar3);
    }
  }
LAB_004f81f1:
  puVar9 = *(ulong **)(param_1 + 0x200);
  if (puVar9 != (ulong *)0x0) {
    uVar6 = (ulong)((uint)(*puVar9 >> 0x16) & 0x3ff) + 1;
    uVar8 = ((uint)(*puVar9 >> 0x14) & 3) - 1;
    if ((2 < uVar8) ||
       (uVar7 = (uVar6 << (*(byte *)((long)&CSWTCH_25 + (ulong)uVar8) & 0x3f)) >> 3,
       uVar6 = uVar7 & 0xffff, (short)uVar7 != 0)) {
      puVar3 = puVar9 + uVar6;
      do {
        while (iVar5 != 0) {
          puVar9 = puVar9 + 1;
          if (puVar9 == puVar3) goto LAB_004f825d;
        }
        puVar2 = puVar9 + 1;
        puVar9 = puVar9 + 1;
        iVar5 = prbEncAddUInt64(param_2,&DAT_00c38650,*puVar2);
      } while (puVar9 != puVar3);
    }
  }
LAB_004f825d:
  puVar9 = *(ulong **)(param_1 + 0x208);
  if (puVar9 != (ulong *)0x0) {
    uVar6 = (ulong)((uint)(*puVar9 >> 0x16) & 0x3ff) + 1;
    uVar8 = ((uint)(*puVar9 >> 0x14) & 3) - 1;
    if ((2 < uVar8) ||
       (uVar7 = (uVar6 << (*(byte *)((long)&CSWTCH_25 + (ulong)uVar8) & 0x3f)) >> 3,
       uVar6 = uVar7 & 0xffff, (short)uVar7 != 0)) {
      puVar3 = puVar9 + uVar6;
      do {
        while (iVar5 != 0) {
          puVar9 = puVar9 + 1;
          if (puVar9 == puVar3) goto LAB_004f82ce;
        }
        puVar2 = puVar9 + 1;
        puVar9 = puVar9 + 1;
        iVar5 = prbEncAddUInt64(param_2,&DAT_00c38668,*puVar2);
      } while (puVar9 != puVar3);
    }
  }
LAB_004f82ce:
  prbEncNestedEnd(param_2);
  return;
}


// ===== 004f87e0 crashcatReportRa_V1 =====

undefined8 crashcatReportRa_V1(long param_1)

{
  return *(undefined8 *)(param_1 + 0x108);
}


// ===== 004f87f0 crashcatReportXcause_V1 =====

undefined8 crashcatReportXcause_V1(long param_1)

{
  return *(undefined8 *)(param_1 + 0xf0);
}


// ===== 004f8800 crashcatReportXtval_V1 =====

undefined8 crashcatReportXtval_V1(long param_1)

{
  return *(undefined8 *)(param_1 + 0xe8);
}


// ===== 004f8810 crashcatReportIsWatchdog_V1 =====

bool crashcatReportIsWatchdog_V1(long param_1)

{
  return ((uint)*(undefined8 *)(param_1 + 0xa8) & 0xf) == 3;
}


// ===== 004f8830 crashcatWayfinderSetWFL0_V1 =====

void crashcatWayfinderSetWFL0_V1(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x58) = param_2;
  return;
}


// ===== 004f8840 crashcatWayfinderGetReportQueue_V1 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

long crashcatWayfinderGetReportQueue_V1(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  int *piVar8;
  long lVar9;
  uint local_40;
  undefined4 local_3c;
  ulong local_38;
  int local_30;
  int local_2c;
  
  lVar9 = *(long *)(param_1 + 0x50);
  if ((lVar9 == 0) && (*(long *)(param_1 + 0x60) == 0)) {
    lVar5 = objFindAncestor_IMPL(param_1,0x654166);
    uVar6 = 0;
    if (lVar5 != 0) {
      uVar6 = objFindAncestor_IMPL(param_1,0x654166);
    }
    plVar7 = (long *)__nvoc_dynamicCast(uVar6,__nvoc_class_def_CrashCatEngine);
    uVar1 = *(uint *)(param_1 + 0x58) >> 0x14 & 7;
    piVar8 = (int *)(**(code **)(*plVar7 + 0x60))(plVar7,uVar1);
    if (piVar8 == (int *)0x0) {
      lVar9 = 0;
      nvDbg_Printf("src/libraries/crashcat/v1/crashcat_wayfinder_v1.c",0x39,
                   "crashcatWayfinderGetReportQueue_V1",4,"NVRM: invalid WFL1 scratch location %u\n"
                   ,uVar1);
    }
    else if ((*piVar8 == 0) || (piVar8[1] == 0)) {
      nvDbg_Printf("src/libraries/crashcat/v1/crashcat_wayfinder_v1.c",0x44,
                   "crashcatWayfinderGetReportQueue_V1",4,
                   "NVRM: insufficiently-sized L1 wayfinder scratch location %u\n",uVar1);
    }
    else {
      local_38 = *(ulong *)(param_1 + 0x60);
      if (local_38 == 0) {
        uVar2 = (**(code **)(*plVar7 + 0x38))(plVar7);
        uVar3 = (**(code **)(*plVar7 + 0x38))(plVar7,*piVar8);
        local_38 = CONCAT44(uVar2,uVar3);
        *(ulong *)(param_1 + 0x60) = local_38;
      }
      local_3c = 0;
      local_40 = (uint)local_38 & 7;
      uVar1 = ((uint)(local_38 >> 3) & 3) - 1;
      if (uVar1 < 3) {
        local_3c = (undefined4)
                   ((ulong)((uint)(local_38 >> 6) & 0xf) + 1 <<
                   (*(byte *)((long)&CSWTCH_11 + (ulong)uVar1) & 0x3f));
      }
      local_38 = local_38 & 0xfffffffffffffc00;
      local_30 = piVar8[2];
      if ((local_30 == 0) || (piVar8[3] == 0)) {
        local_30 = *piVar8;
        local_2c = piVar8[1];
        (**(code **)(*plVar7 + 0x40))(plVar7,local_2c,0);
        (**(code **)(*plVar7 + 0x40))(plVar7,local_30,0);
        uVar2 = (**(code **)(*plVar7 + 0x68))(plVar7);
        (**(code **)(*plVar7 + 0x40))(plVar7,uVar2,*(uint *)(param_1 + 0x58) & 0xff8fffff);
      }
      else {
        local_2c = piVar8[3];
      }
      iVar4 = __nvoc_objCreate_CrashCatQueue(param_1 + 0x50,param_1,0,&local_40);
      if (iVar4 == 0) {
        return *(long *)(param_1 + 0x50);
      }
      nvCheckOkFailedNoLog
                (4,iVar4,"objCreate(&pWayfinder->pQueue, pWayfinder, CrashCatQueue, &queueConfig)",
                 "src/libraries/crashcat/v1/crashcat_wayfinder_v1.c",0x78);
    }
  }
  return lVar9;
}


// ===== 004f8af0 crashcatReportLogSource_V1_GENERIC =====

void crashcatReportLogSource_V1_GENERIC(long param_1)

{
  ulong uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = *(ulong *)(param_1 + 0xa0);
  iVar4 = 0x3f;
  uVar5 = *(uint *)(param_1 + 0xa8) & 0xf;
  uVar2 = ((uint)(uVar1 >> 0x10) & 7) - 1;
  if (uVar2 < 3) {
    iVar4 = (int)"MSUkernel"[uVar2];
  }
  pcVar3 = "unknown failure";
  if (uVar5 < 3) {
    pcVar3 = *(char **)(CSWTCH_12 + (ulong)uVar5 * 8);
  }
  crashcatEnginePrintf
            (*(undefined8 *)(param_1 + 0x70),1,
             "%s in partition:%u ucode:%u [%c-mode] @ pc:0x%llx, data:0x%llx",pcVar3,uVar1 & 0xff,
             uVar1 >> 8 & 0xff,iVar4,*(undefined8 *)(param_1 + 0xb0),*(undefined8 *)(param_1 + 0xb8)
            );
  return;
}


// ===== 004f8b80 crashcatReportLogReporter_V1_GENERIC =====

undefined1  [16] crashcatReportLogReporter_V1_GENERIC(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  uint uVar4;
  int iVar5;
  undefined8 uStack_10;
  
  uVar1 = *(ulong *)(param_1 + 0x98);
  iVar5 = 0x3f;
  uVar2 = *(ulong *)(param_1 + 0x90);
  uVar4 = ((uint)(uVar2 >> 0x10) & 7) - 1;
  if (uVar4 < 3) {
    iVar5 = (int)"MSUkernel"[uVar4];
  }
  nv_printf(0xffffffff,"NVRM:     Reported by partition:%u ucode:%u [%c-mode] version:%u @ %u\n",
            uVar2 & 0xff,uVar2 >> 8 & 0xff,iVar5);
  auVar3._8_8_ = uStack_10;
  auVar3._0_8_ = uVar1 >> 0x20;
  return auVar3;
}


// ===== 004f8bf0 crashcatReportLogVersionProtobuf_V1_GENERIC =====

void crashcatReportLogVersionProtobuf_V1_GENERIC(long param_1,undefined8 param_2)

{
  prbEncAddUInt32(param_2,&DAT_00c385c0,*(undefined4 *)(param_1 + 0x98));
  return;
}


// ===== 004f8c10 crashcatReportLogSource_V1_LIBOS2 =====

ulong crashcatReportLogSource_V1_LIBOS2(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong uVar6;
  char *pcVar7;
  char *pcVar8;
  char cVar9;
  ulong uVar10;
  
  uVar4 = *(ulong *)(param_1 + 0xa0);
  uVar3 = (uint)(uVar4 >> 0x10) & 7;
  uVar10 = uVar4 >> 0x18;
  if (uVar3 < 3) {
    pcVar7 = "unspecified";
    if ((uVar4 & 0x70000) != 0) {
      pcVar7 = "kernel";
    }
  }
  else {
    pcVar7 = "unspecified";
    if (uVar3 == 3) {
      pcVar7 = "task";
    }
  }
  uVar6 = *(ulong *)(param_1 + 0xa8);
  uVar3 = (uint)uVar6 & 0xf;
  cVar9 = (char)(uVar4 >> 0x18);
  if (uVar3 == 2) {
    uVar4 = *(ulong *)(param_1 + 0xb0);
    uVar6 = uVar6 >> 0x20 & 0xff;
    uVar3 = (int)uVar6 - 1;
    if (cVar9 == -1) {
      pcVar8 = "unknown error";
      if (uVar3 < 0xc) {
        pcVar8 = *(char **)(CSWTCH_12 + (ulong)uVar3 * 8);
      }
      crashcatEnginePrintf
                (*(undefined8 *)(param_1 + 0x70),1,"%s panic: %s (%u) @ pc:0x%llx, aux:0x%llx",
                 pcVar7,pcVar8,uVar6,uVar4,*(undefined8 *)(param_1 + 0xb8));
      return uVar4;
    }
    pcVar8 = "unknown error";
    if (uVar3 < 0xc) {
      pcVar8 = *(char **)(CSWTCH_12 + (ulong)uVar3 * 8);
    }
    uVar4 = crashcatEnginePrintf
                      (*(undefined8 *)(param_1 + 0x70),1,
                       "%s panic: %s (%u) @ pc:0x%llx, aux:0x%llx, task:%u",pcVar7,pcVar8,uVar6,
                       uVar4,*(undefined8 *)(param_1 + 0xb8),uVar10 & 0xff);
    return uVar4;
  }
  if (uVar3 < 3) {
    if ((uVar6 & 0xf) != 0) {
      if (cVar9 == -1) {
        uVar4 = crashcatEnginePrintf
                          (*(undefined8 *)(param_1 + 0x70),1,"%s timeout @ pc:0x%llx",pcVar7,
                           *(undefined8 *)(param_1 + 0xb0));
        return uVar4;
      }
      uVar4 = crashcatEnginePrintf
                        (*(undefined8 *)(param_1 + 0x70),1,"%s timeout @ pc:0x%llx, task:%u",pcVar7,
                         *(undefined8 *)(param_1 + 0xb0),uVar10 & 0xff);
      return uVar4;
    }
    uVar1 = *(undefined8 *)(param_1 + 0xb8);
    uVar2 = *(undefined8 *)(param_1 + 0xb0);
    if (cVar9 == -1) {
      uVar5 = crashcatReportRiscvCauseToString(uVar1);
      uVar4 = crashcatEnginePrintf
                        (*(undefined8 *)(param_1 + 0x70),1,
                         "%s exception: %s (cause:0x%llx) @ pc:0x%llx",pcVar7,uVar5,uVar1,uVar2);
      return uVar4;
    }
    uVar5 = crashcatReportRiscvCauseToString(uVar1);
    uVar6 = crashcatEnginePrintf
                      (*(undefined8 *)(param_1 + 0x70),1,
                       "%s exception: %s (cause:0x%llx) @ pc:0x%llx, task:%u",pcVar7,uVar5,uVar1,
                       uVar2,uVar10 & 0xff);
  }
  else if (uVar3 == 3) {
    if (cVar9 == -1) {
      uVar4 = crashcatEnginePrintf
                        (*(undefined8 *)(param_1 + 0x70),1,
                         "Watchdog is not supported in libos2, please check if NV_CRASHCAT_CAUSE_TYPE is set correctly"
                        );
      return uVar4;
    }
    uVar4 = crashcatEnginePrintf
                      (*(undefined8 *)(param_1 + 0x70),1,
                       "Watchdog is not supported in libos2, please check if NV_CRASHCAT_CAUSE_TYPE is set correctly, task:%u"
                       ,uVar10 & 0xff);
    return uVar4;
  }
  return uVar6;
}


// ===== 004f8e90 crashcatReportLogReporter_V1_LIBOS2 =====

undefined1  [16] crashcatReportLogReporter_V1_LIBOS2(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  undefined1 auVar3 [16];
  undefined8 uStack_10;
  
  uVar1 = *(ulong *)(param_1 + 0x98);
  uVar2 = uVar1 >> 0x1c & 0xf;
  if ((char)(*(ulong *)(param_1 + 0x90) >> 0x18) != -1) {
    nv_printf(0xffffffff,"NVRM:     Reported by libos task:%u v%u.%u [%u] @ ts:%u\n",
              *(ulong *)(param_1 + 0x90) >> 0x18 & 0xff,uVar2,(uint)(uVar1 >> 0x18) & 0xf,
              (uint)uVar1 & 0xffffff);
    auVar3._8_8_ = uStack_10;
    auVar3._0_8_ = uVar1 >> 0x20;
    return auVar3;
  }
  auVar3 = nv_printf(0xffffffff,"NVRM:     Reported by libos kernel v%u.%u [%u] @ %u\n",uVar2);
  return auVar3;
}


// ===== 004f8f10 crashcatReportLogVersionProtobuf_V1_LIBOS2 =====

void crashcatReportLogVersionProtobuf_V1_LIBOS2(long param_1,undefined8 param_2)

{
  prbEncAddUInt32(param_2,&DAT_00c385c0,*(uint *)(param_1 + 0x98) >> 0x1c);
  prbEncAddUInt32(param_2,&DAT_00c385d8,*(byte *)(param_1 + 0x9b) & 0xf);
  prbEncAddUInt32(param_2,&DAT_00c385f0,(uint)*(undefined8 *)(param_1 + 0x98) & 0xffffff);
  return;
}


// ===== 004f8f80 crashcatReportLogSource_V1_LIBOS3 =====

ulong crashcatReportLogSource_V1_LIBOS3(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong uVar9;
  char *pcVar10;
  uint uVar11;
  char cVar12;
  ulong uVar13;
  char *pcVar14;
  
  pcVar14 = "unspecified";
  uVar7 = *(ulong *)(param_1 + 0xa0);
  uVar13 = uVar7 >> 0x18;
  uVar9 = uVar7 >> 8;
  uVar4 = ((uint)(uVar7 >> 0x10) & 7) - 1;
  if (uVar4 < 3) {
    pcVar14 = *(char **)(CSWTCH_16 + (ulong)uVar4 * 8);
  }
  uVar6 = *(ulong *)(param_1 + 0xa8);
  uVar4 = (uint)uVar6 & 0xf;
  uVar5 = (ulong)uVar4;
  cVar12 = (char)(uVar7 >> 0x18);
  if (uVar4 == 2) {
    uVar9 = uVar9 & 0xff;
    uVar7 = uVar7 & 0xff;
    uVar11 = (uint)(uVar6 >> 0x20) & 0xff;
    cVar3 = crashcatReportIsWatchdog_V1(param_1);
    uVar1 = *(undefined8 *)(param_1 + 0xb0);
    uVar2 = *(undefined8 *)(param_1 + 0xb8);
    uVar4 = uVar11 - 1;
    uVar6 = (ulong)uVar4;
    if (cVar3 != '\0') {
      pcVar10 = "unknown error";
      if (uVar4 < 0xd) {
        pcVar10 = *(char **)(CSWTCH_18 + uVar6 * 8);
      }
      uVar7 = crashcatEnginePrintf
                        (*(undefined8 *)(param_1 + 0x70),0,
                         "%s panic: %s (%u) @ pc:0x%llx, aux:0x%llx, partition:%u#%u, task:%u",
                         pcVar14,pcVar10,uVar11,uVar1,uVar2,uVar7,uVar9,uVar13 & 0xff);
      return uVar7;
    }
    if (cVar12 != -1) {
      pcVar10 = "unknown error";
      if (uVar4 < 0xd) {
        pcVar10 = *(char **)(CSWTCH_18 + uVar6 * 8);
      }
      uVar7 = crashcatEnginePrintf
                        (*(undefined8 *)(param_1 + 0x70),0x78,
                         "%s panic: %s (%u) @ pc:0x%llx, aux:0x%llx, partition:%u#%u, task:%u",
                         pcVar14,pcVar10,uVar11,uVar1,uVar2,uVar7,uVar9,uVar13 & 0xff);
      return uVar7;
    }
    pcVar10 = "unknown error";
    if (uVar4 < 0xd) {
      pcVar10 = *(char **)(CSWTCH_18 + uVar6 * 8);
    }
    uVar5 = crashcatEnginePrintf
                      (*(undefined8 *)(param_1 + 0x70),0x78,
                       "%s panic: %s (%u) @ pc:0x%llx, aux:0x%llx, partition:%u#%u",pcVar14,pcVar10,
                       uVar11,uVar1,uVar2,uVar7,uVar9);
  }
  else if (uVar4 < 3) {
    if ((uVar6 & 0xf) == 0) {
      uVar1 = *(undefined8 *)(param_1 + 0xb8);
      uVar9 = uVar9 & 0xff;
      uVar7 = uVar7 & 0xff;
      cVar3 = crashcatReportIsWatchdog_V1(param_1);
      uVar2 = *(undefined8 *)(param_1 + 0xb0);
      if (cVar3 == '\0') {
        if (cVar12 == -1) {
          uVar8 = crashcatReportRiscvCauseToString(uVar1);
          uVar5 = crashcatEnginePrintf
                            (*(undefined8 *)(param_1 + 0x70),0x78,
                             "%s exception: %s (cause:0x%llx) @ pc:0x%llx, partition:%u#%u",pcVar14,
                             uVar8,uVar1,uVar2,uVar7,uVar9);
        }
        else {
          uVar8 = crashcatReportRiscvCauseToString(uVar1);
          uVar5 = crashcatEnginePrintf
                            (*(undefined8 *)(param_1 + 0x70),0x78,
                             "%s exception: %s (cause:0x%llx) @ pc:0x%llx, partition:%u#%u, task:%u"
                             ,pcVar14,uVar8,uVar1,uVar2,uVar7,uVar9,uVar13 & 0xff);
        }
      }
      else {
        uVar8 = crashcatReportRiscvCauseToString(uVar1);
        uVar5 = crashcatEnginePrintf
                          (*(undefined8 *)(param_1 + 0x70),0,
                           "%s exception: %s (cause:0x%llx) @ pc:0x%llx, partition:%u#%u, task:%u",
                           pcVar14,uVar8,uVar1,uVar2,uVar7,uVar9,uVar13 & 0xff);
      }
    }
    else {
      uVar9 = uVar9 & 0xff;
      cVar3 = crashcatReportIsWatchdog_V1(param_1);
      uVar1 = *(undefined8 *)(param_1 + 0xb0);
      uVar2 = *(undefined8 *)(param_1 + 0x70);
      uVar7 = uVar7 & 0xff;
      if (cVar3 == '\0') {
        if (cVar12 == -1) {
          uVar5 = crashcatEnginePrintf
                            (uVar2,0x78,"%s timeout @ pc:0x%llx, partition:%u#%u",pcVar14,uVar1,
                             uVar7,uVar9);
        }
        else {
          uVar5 = crashcatEnginePrintf
                            (uVar2,0x78,"%s timeout @ pc:0x%llx, partition:%u#%u, task:%u",pcVar14,
                             uVar1,uVar7,uVar9,uVar13 & 0xff);
        }
      }
      else {
        uVar5 = crashcatEnginePrintf
                          (uVar2,0,"%s timeout @ pc:0x%llx, partition:%u#%u, task:%u",pcVar14,uVar1,
                           uVar7,uVar9,uVar13 & 0xff);
      }
    }
  }
  else if (uVar4 == 3) {
    uVar5 = uVar9 & 0xff;
    cVar3 = crashcatReportIsWatchdog_V1(param_1);
    uVar1 = *(undefined8 *)(param_1 + 0xb0);
    uVar2 = *(undefined8 *)(param_1 + 0x70);
    uVar7 = uVar7 & 0xff;
    if (cVar3 == '\0') {
      if (cVar12 == -1) {
        uVar5 = crashcatEnginePrintf
                          (uVar2,0x78,"%s watchdog timeout @ pc:0x%llx, partition:%u#%u",pcVar14,
                           uVar1,uVar7,uVar5);
      }
      else {
        crashcatEnginePrintf
                  (uVar2,0x78,"%s watchdog timeout @ pc:0x%llx, partition:%u#%u, task:%u",pcVar14,
                   uVar1,uVar7,uVar5,uVar13 & 0xff);
      }
    }
    else {
      uVar5 = crashcatEnginePrintf
                        (uVar2,0,"%s watchdog timeout @ pc:0x%llx, partition:%u#%u, task:%u",pcVar14
                         ,uVar1,uVar7,uVar5,uVar13 & 0xff);
    }
  }
  return uVar5;
}


// ===== 004f9390 crashcatReportSourceContainment_V1_LIBOS3 =====

uint crashcatReportSourceContainment_V1_LIBOS3(long param_1)

{
  return (uint)(*(ulong *)(param_1 + 0xa8) >> 4) & 0xf;
}


// ===== 004f93b0 crashcatReportLogReporter_V1_LIBOS3 =====

ulong crashcatReportLogReporter_V1_LIBOS3(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = *(ulong *)(param_1 + 0x90);
  uVar1 = *(ulong *)(param_1 + 0x98);
  uVar3 = uVar2 >> 8 & 0xff;
  uVar4 = (ulong)((uint)uVar1 & 0xffffff);
  if ((char)(uVar2 >> 0x18) != -1) {
    uVar2 = nv_printf(0xffffffff,
                      "NVRM:     Reported by libos partition:%u#%u task:%u v%u.%u [%u] @ ts:%u\n",
                      uVar2 & 0xff,uVar3,uVar2 >> 0x18 & 0xff,uVar1 >> 0x1c & 0xf,
                      (uint)(uVar1 >> 0x18) & 0xf,uVar4,uVar1 >> 0x20);
    return uVar2;
  }
  nv_printf(0xffffffff,"NVRM:     Reported by libos partition:%u#%u kernel v%u.%u [%u] @ ts:%u\n",
            uVar2 & 0xff,uVar3);
  return uVar4;
}


// ===== 004f9440 crashcatReportLogVersionProtobuf_V1_LIBOS3 =====

void crashcatReportLogVersionProtobuf_V1_LIBOS3(long param_1,undefined8 param_2)

{
  ulong uVar1;
  uint uVar2;
  
  uVar1 = *(ulong *)(param_1 + 0xa8);
  if (((uint)uVar1 & 0xf) != 2) goto LAB_004f9462;
  uVar2 = (uint)(uVar1 >> 0x20) & 0xff;
  if (uVar2 == 6) {
LAB_004f956f:
    prbEncAddEnum(param_2,&DAT_00c38530,7);
LAB_004f9583:
    prbEncAddEnum(param_2,&DAT_00c38530,8);
LAB_004f9597:
    prbEncAddEnum(param_2,&DAT_00c38530,9);
LAB_004f95ab:
    prbEncAddEnum(param_2,&DAT_00c38530,10);
LAB_004f95bf:
    prbEncAddEnum(param_2,&DAT_00c38530,0xb);
LAB_004f95d3:
    prbEncAddEnum(param_2,&DAT_00c38530,0xc);
  }
  else {
    if (uVar2 < 7) {
      if (uVar2 == 3) {
LAB_004f9533:
        prbEncAddEnum(param_2,&DAT_00c38530,4);
LAB_004f9547:
        prbEncAddEnum(param_2,&DAT_00c38530,5);
      }
      else {
        if ((uVar1 >> 0x20 & 0xfc) == 0) {
          if (uVar2 == 1) {
            prbEncAddEnum(param_2,&DAT_00c38530,2);
          }
          else if (uVar2 != 2) goto LAB_004f95e7;
          prbEncAddEnum(param_2,&DAT_00c38530,3);
          goto LAB_004f9533;
        }
        if (uVar2 == 4) goto LAB_004f9547;
      }
      prbEncAddEnum(param_2,&DAT_00c38530,6);
      goto LAB_004f956f;
    }
    if (uVar2 == 0xb) goto LAB_004f95ab;
    if (0xb < uVar2) {
      if (uVar2 == 0xc) goto LAB_004f95bf;
      if (uVar2 != 0xd) goto LAB_004f95e7;
      goto LAB_004f95d3;
    }
    if (uVar2 == 8) goto LAB_004f9583;
    if (uVar2 == 10) goto LAB_004f9597;
  }
LAB_004f95e7:
  prbEncAddEnum(param_2,&DAT_00c38530,1);
LAB_004f9462:
  prbEncAddUInt32(param_2,&DAT_00c385c0,*(uint *)(param_1 + 0x98) >> 0x1c);
  prbEncAddUInt32(param_2,&DAT_00c385d8,*(byte *)(param_1 + 0x9b) & 0xf);
  prbEncAddUInt32(param_2,&DAT_00c385f0,(uint)*(undefined8 *)(param_1 + 0x98) & 0xffffff);
  return;
}


// ===== 004f9640 eventBufferInitRecordBuffer =====

void eventBufferInitRecordBuffer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 2) = param_4;
  *(undefined4 *)((long)param_1 + 0x14) = param_5;
  *(undefined4 *)(param_1 + 3) = param_6;
  *(undefined4 *)((long)param_1 + 0x1c) = param_7;
  return;
}


// ===== 004f9670 eventBufferInitVardataBuffer =====

void eventBufferInitVardataBuffer
               (long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined8 *)(param_1 + 0x20) = param_2;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  *(undefined4 *)(param_1 + 0x2c) = param_4;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x38) = param_3;
  return;
}


// ===== 004f9690 eventBufferInitNotificationHandle =====

void eventBufferInitNotificationHandle(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x40) = param_2;
  return;
}


// ===== 004f96a0 eventBufferSetEnable =====

void eventBufferSetEnable(long param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x48) = param_2;
  return;
}


// ===== 004f96b0 eventBufferSetKeepNewest =====

void eventBufferSetKeepNewest(long param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x49) = param_2;
  return;
}


// ===== 004f96c0 eventBufferUpdateRecordBufferGet =====

void eventBufferUpdateRecordBufferGet(long *param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  
  *(undefined4 *)*param_1 = param_2;
  puVar1 = (uint *)*param_1;
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    uVar2 = uVar2 + *(int *)((long)param_1 + 0x14);
  }
  *(ulong *)(puVar1 + 2) = (ulong)(uVar2 - *puVar1);
  *(undefined8 *)(*param_1 + 0x10) = 0;
  *(undefined8 *)(*param_1 + 0x18) = 0;
  return;
}


// ===== 004f9700 eventBufferUpdateVardataBufferGet =====

void eventBufferUpdateVardataBufferGet(long param_1,uint param_2)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x30) = param_2;
  if (*(char *)(param_1 + 0x49) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x34);
    if (param_2 <= uVar1) {
      *(uint *)(param_1 + 0x38) = (param_2 + *(int *)(param_1 + 0x28)) - uVar1;
      return;
    }
    *(uint *)(param_1 + 0x38) = param_2 - uVar1;
  }
  return;
}


// ===== 004f9730 eventBufferGetRecordBufferCount =====

undefined4 eventBufferGetRecordBufferCount(long param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}


// ===== 004f9740 eventBufferGetVardataBufferCount =====

undefined4 eventBufferGetVardataBufferCount(long param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}


// ===== 004f9750 eventBufferProducerAddEvent =====

ulong eventBufferProducerAddEvent
                (ulong *param_1,undefined2 param_2,undefined2 param_3,undefined8 *param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  ulong in_RAX;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined2 *puVar11;
  
  if ((char)param_1[9] == '\0') {
    return in_RAX;
  }
  puVar3 = (uint *)*param_1;
  uVar9 = puVar3[1] + 1;
  uVar7 = (ulong)uVar9 / (ulong)*(uint *)((long)param_1 + 0x14);
  uVar9 = uVar9 % *(uint *)((long)param_1 + 0x14);
  if ((*(char *)((long)param_1 + 0x49) == '\0') && (uVar9 == *puVar3)) {
    *(long *)(puVar3 + 4) = *(long *)(puVar3 + 4) + 1;
    return uVar7;
  }
  puVar11 = (undefined2 *)((ulong)(puVar3[1] * (int)param_1[2]) + param_1[1]);
  if (puVar11 == (undefined2 *)0x0) {
    return uVar7;
  }
  *puVar11 = param_2;
  puVar11[1] = param_3;
  iVar1 = *(int *)(param_4 + 1);
  if (iVar1 != 0) {
    portMemCopy(puVar11 + 4,iVar1,*param_4,iVar1);
  }
  uVar2 = *(uint *)(param_4 + 3);
  uVar10 = *(uint *)((long)param_1 + 0x34);
  uVar8 = uVar2 + 0x1f & 0xffffffe0;
  uVar6 = uVar8 + uVar10;
  if ((uint)param_1[5] < uVar6) {
    if ((*(char *)((long)param_1 + 0x49) == '\0') && ((uint)param_1[6] <= uVar8)) goto LAB_004f9910;
    uVar10 = 0;
    uVar6 = uVar8;
    uVar5 = uVar8 | 1;
  }
  else {
    uVar5 = uVar6;
    if ((*(char *)((long)param_1 + 0x49) == '\0') && ((uint)param_1[7] < uVar8)) {
LAB_004f9910:
      uVar7 = *param_1;
      *(uint *)(puVar11 + 2) = uVar10;
      *(long *)(uVar7 + 0x18) = *(long *)(uVar7 + 0x18) + 1;
      goto LAB_004f9848;
    }
  }
  uVar7 = (ulong)uVar5;
  uVar4 = param_4[2];
  *(uint *)(puVar11 + 2) = uVar5;
  if ((uVar2 != 0) &&
     (uVar7 = portMemCopy((ulong)uVar10 + param_1[4],uVar2,uVar4,uVar2), uVar2 != uVar8)) {
    uVar7 = portMemSet((ulong)(uVar2 + uVar10) + param_1[4],0,uVar8 - uVar2);
  }
  *(uint *)((long)param_1 + 0x34) = uVar6;
  if (*(char *)((long)param_1 + 0x49) == '\0') {
    uVar2 = (uint)param_1[6];
    if (uVar6 < uVar2) {
      uVar7 = (ulong)(uVar2 - uVar6);
      *(uint *)(param_1 + 7) = uVar2 - uVar6;
    }
    else {
      uVar6 = (uVar2 + (int)param_1[5]) - uVar6;
      uVar7 = (ulong)uVar6;
      *(uint *)(param_1 + 7) = uVar6;
    }
  }
LAB_004f9848:
  puVar3[1] = uVar9;
  return uVar7;
}


// ===== 004f9930 eventBufferIsNotifyThresholdMet =====

bool eventBufferIsNotifyThresholdMet(long *param_1)

{
  bool bVar1;
  
  bVar1 = true;
  if ((ulong)*(uint *)((long)param_1 + 0x1c) <
      (ulong)*(uint *)((long)param_1 + 0x14) - *(long *)(*param_1 + 8)) {
    bVar1 = *(uint *)(param_1 + 7) <= *(uint *)((long)param_1 + 0x2c);
  }
  return bVar1;
}


// ===== 004f9960 fnv32buf =====

uint fnv32buf(byte *param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  pbVar1 = param_1 + param_2;
  if (param_1 < pbVar1) {
    iVar5 = (int)param_1;
    do {
      bVar2 = *param_1;
      iVar3 = (int)param_1;
      uVar4 = (uint)bVar2;
      if ((byte)(bVar2 + 0x9f) < 0x1a) {
        uVar4 = bVar2 - 0x20;
      }
      param_1 = param_1 + 1;
      param_3 = ((((param_4 & 1) - iVar5) + iVar3 & 1) << 7 ^ uVar4 ^ param_3) * 0x1000193;
    } while (pbVar1 != param_1);
    return param_3;
  }
  return param_3;
}


// ===== 004f99e0 fnv1Hash16 =====

uint fnv1Hash16(long param_1,undefined4 param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog(&DAT_00da5a0a,"src/libraries/fnv_hash/fnv_hash.c",0xc3);
  }
  uVar1 = fnv32buf(param_1,param_2,0x811c9dc5,0);
  return uVar1 >> 0x10 ^ uVar1;
}


// ===== 004f9a50 fnv1Hash20Array =====

void fnv1Hash20Array(long param_1,int param_2,uint *param_3,byte param_4)

{
  uint uVar1;
  byte *pbVar2;
  long lVar3;
  ulong uVar4;
  
  pbVar2 = (byte *)getNbsiObject();
  if (param_1 == 0) {
    nvAssertFailedNoLog(&DAT_00da5a0a,"src/libraries/fnv_hash/fnv_hash.c",0x101);
  }
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("rtnHashArray","src/libraries/fnv_hash/fnv_hash.c",0x102);
  }
  if (*pbVar2 < param_4) {
    nvAssertFailedNoLog("numOSes <= pNbsiObj->curMaxNbsiOSes","src/libraries/fnv_hash/fnv_hash.c",
                        0x103);
    if (*pbVar2 < 4) {
      if (param_2 != 0) goto LAB_004f9b00;
      goto LAB_004f9aa5;
    }
LAB_004f9bd0:
    nvAssertFailedNoLog("pNbsiObj->curMaxNbsiOSes <= MAX_NBSI_OS",
                        "src/libraries/fnv_hash/fnv_hash.c",0x104);
  }
  else if (3 < *pbVar2) goto LAB_004f9bd0;
  if (param_2 != 0) {
LAB_004f9b00:
    uVar1 = fnv32buf(param_1,param_2,0x811c9dc5,0);
    uVar4 = (ulong)uVar1;
    *param_3 = (uVar1 >> 0x14 ^ uVar1) & 0xfffff;
    if (param_4 < 2) {
      return;
    }
    uVar1 = fnv32buf(pbVar2 + 0x1d,*(undefined4 *)(pbVar2 + 0x38),uVar1,param_2);
    param_3[1] = (uVar1 >> 0x14 ^ uVar1) & 0xfffff;
    if (param_4 == 2) {
      return;
    }
    uVar1 = fnv32buf(pbVar2 + 0x28,*(undefined4 *)(pbVar2 + 0x3c),uVar4 & 0xffffffff,param_2);
    param_3[2] = (uVar1 >> 0x14 ^ uVar1) & 0xfffff;
    return;
  }
  if (param_4 == 0) {
    return;
  }
LAB_004f9aa5:
  lVar3 = 0;
  do {
    param_3[lVar3] = *(uint *)(pbVar2 + lVar3 * 4 + 4);
    lVar3 = lVar3 + 1;
  } while ((byte)lVar3 < param_4);
  return;
}


// ===== 004f9c00 fnv1Hash64 =====

void fnv1Hash64(ulong param_1,uint param_2)

{
  ulong uVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog(&DAT_00da5a0a,"src/libraries/fnv_hash/fnv_hash.c",0x1a1);
  }
  uVar1 = param_2 + param_1;
  if (param_1 < uVar1) {
    do {
      param_1 = param_1 + 1;
    } while (uVar1 != param_1);
  }
  return;
}


// ===== 004f9cc0 libspdm_version_number_sort.part.0 =====

void libspdm_version_number_sort_part_0(ushort *param_1,ulong param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ulong uVar5;
  ushort *puVar6;
  ulong uVar7;
  ushort uVar8;
  ushort *puVar9;
  ulong uVar10;
  ulong uVar11;
  
  if ((param_2 == 0) || (param_2 == 1)) {
    return;
  }
  uVar11 = 1;
  puVar3 = param_1;
  do {
    uVar1 = *puVar3;
    puVar4 = puVar3 + 1;
    uVar5 = uVar11;
    uVar10 = uVar11 - 1;
    uVar8 = uVar1;
    do {
      while (uVar7 = uVar5, puVar6 = puVar4, uVar2 = *puVar6, uVar8 < uVar2) {
        puVar4 = puVar6 + 1;
        uVar5 = uVar7 + 1;
        puVar9 = puVar6;
        uVar10 = uVar7;
        uVar8 = uVar2;
        if (param_2 <= uVar7 + 1) goto LAB_004f9d4e;
      }
      puVar9 = param_1 + uVar10;
      puVar4 = puVar6 + 1;
      uVar5 = uVar7 + 1;
    } while (uVar7 + 1 < param_2);
LAB_004f9d4e:
    uVar11 = uVar11 + 1;
    *puVar3 = uVar8;
    *puVar9 = uVar1;
    puVar3 = puVar3 + 1;
    if (param_2 == uVar11) {
      return;
    }
  } while( true );
}


// ===== 004f9d70 libspdm_get_scratch_buffer_last_spdm_request_capacity =====

undefined4 libspdm_get_scratch_buffer_last_spdm_request_capacity(long param_1)

{
  return *(undefined4 *)(param_1 + 0x118);
}


// ===== 004f9d80 libspdm_set_data =====

uint libspdm_set_data(long param_1,uint param_2,int *param_3,uint *param_4,ulong param_5)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 local_28;
  undefined8 local_20;
  
  if ((param_4 == (uint *)0x0 || 0x3a < param_2) || (param_1 == 0)) {
    return 0x80010001;
  }
  if (param_2 - 0x26 < 0x12) {
    if ((0x2300fUL >> ((ulong)(param_2 - 0x26) & 0x3f) & 1) != 0) {
      if (*param_3 != 2) {
        return 0x80010001;
      }
      uVar4 = libspdm_read_uint32(param_3 + 1);
      lVar8 = libspdm_get_session_info_via_session_id(param_1,uVar4);
      if (lVar8 == 0) {
        return 0x80010001;
      }
    }
    if (param_2 == 0x2d) {
      if (param_5 != 1) {
        return 0x80010001;
      }
      if (*param_3 == 0) {
        *(byte *)(param_1 + 0x233) = (byte)*param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (param_2 < 0x2e) {
      if (param_2 == 0x2b) {
        if (param_5 == 1) {
          *(byte *)(param_1 + 0xb40) = (byte)*param_4;
          return 0;
        }
        return 0x80010001;
      }
      if (param_2 == 0x2c) {
        if (param_5 < 0xd3) {
          *(ulong *)(param_1 + 0x658) = param_5;
          libspdm_copy_mem(param_1 + 0x660,0xd2,param_4,param_5);
          return 0;
        }
        return 0x80010001;
      }
      if (param_2 == 0x2a) {
        if (param_5 != 8) {
          return 0x80010001;
        }
        if (*(long *)param_4 != 0) {
          *(long *)(param_1 + 0xb38) = *(long *)param_4;
          return 0;
        }
        return 0x80010001;
      }
      return 0x80010002;
    }
    if (param_2 == 0x35) {
      if (param_5 != 1) {
        return 0x80010001;
      }
      if ((byte)*param_4 < 3) {
        *(byte *)(param_1 + 0xb90) = (byte)*param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (0x35 < param_2) {
      if (param_2 != 0x36) {
        return 0x80010002;
      }
      if (param_5 == 1) {
        *(byte *)(param_1 + 0xb60) = (byte)*param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (param_2 == 0x30) {
      if (param_5 != 4) {
        return 0x80010001;
      }
      if (*param_4 <= 1U - *(int *)(param_1 + 0xb48)) {
        *(uint *)(param_1 + 0xb44) = *param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (param_2 < 0x31) {
      if (param_2 == 0x2e) {
        if (param_5 == 1) {
          *(byte *)(param_1 + 0xb25) = (byte)*param_4;
          return 0;
        }
        return 0x80010001;
      }
      if (param_5 == 8) {
        *(undefined8 *)(param_1 + 0xb28) = *(undefined8 *)param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (param_2 == 0x31) {
      if (param_5 != 4) {
        return 0x80010001;
      }
      if (*param_4 <= 1U - *(int *)(param_1 + 0xb44)) {
        *(uint *)(param_1 + 0xb48) = *param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (param_2 != 0x34) {
      return 0x80010002;
    }
    if (param_5 == 8) {
      lVar8 = *(long *)param_4;
      if (lVar8 == 0) {
        lVar8 = -1;
      }
      *(long *)(param_1 + 0xb58) = lVar8;
      return 0;
    }
    return 0x80010001;
  }
  if (param_2 == 0x18) {
    if (*param_3 != 0) {
      return 0x80010001;
    }
    if (param_5 != 1) {
      return 0x80010001;
    }
    *(byte *)(param_1 + 0x1d0) = (byte)*param_4;
    return 0;
  }
  if (0x18 < param_2) {
    if (0x2d < param_2) {
      if (param_2 == 0x39) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        if (param_5 != 1) {
          return 0x80010001;
        }
        *(byte *)(param_1 + 0x64b) = (byte)*param_4;
        return 0;
      }
      if (param_2 == 0x3a) {
        if (param_5 != 1) {
          return 0x80010001;
        }
        if (*param_3 == 0) {
          *(byte *)(param_1 + 0x234) = (byte)*param_4;
          return 0;
        }
        return 0x80010001;
      }
      if (*param_3 != 1) {
        return 0x80010001;
      }
      if (param_5 == 1) {
        *(byte *)(param_1 + 0x64a) = (byte)*param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (param_2 == 0x1e) {
      if (param_5 != 1) {
        return 0x80010001;
      }
      if (*param_3 != 0) {
        return 0x80010001;
      }
      *(byte *)(param_1 + 0x232) = (byte)*param_4;
      return 0;
    }
    if (0x1e < param_2) {
      if (param_2 != 0x1f) {
        return 0x80010002;
      }
      if (*param_3 != 1) {
        return 0x80010001;
      }
      bVar1 = *(byte *)(param_3 + 1);
      if (7 < bVar1) {
        return 0x80010001;
      }
      if (param_5 < 0x1001) {
        *(byte *)(param_1 + 0x630) = bVar1;
        cVar2 = libspdm_hash_all(*(undefined4 *)(param_1 + 0x27c),param_4,param_5,
                                 param_1 + 0x430 + (ulong)bVar1 * 0x40);
        if (cVar2 != '\0') {
          uVar4 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
          *(undefined4 *)(param_1 + 0x460 + (ulong)bVar1 * 0x40) = uVar4;
          uVar6 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
          uVar7 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
          cVar2 = libspdm_x509_get_cert_from_cert_chain
                            ((byte *)((long)param_4 + (ulong)uVar6 + 4),(param_5 - 4) - (ulong)uVar7
                             ,0xffffffff,&local_28,&local_20);
          if (cVar2 != '\0') {
            cVar2 = libspdm_rsa_get_public_key_from_x509(local_28,local_20);
            if (cVar2 != '\0') {
              return 0;
            }
            cVar2 = libspdm_ec_get_public_key_from_x509
                              (local_28,local_20,param_1 + 0x468 + (ulong)bVar1 * 0x40);
            return -(uint)(cVar2 == '\0') & 0x80030000;
          }
        }
        return 0x80020000;
      }
      return 0x8001000c;
    }
    if (param_2 == 0x1b) {
      if (*param_3 != 0) {
        return 0x80010001;
      }
      bVar1 = *(byte *)(param_3 + 1);
      if (param_5 != 2) {
        return 0x80010001;
      }
      if (7 < bVar1) {
        return 0x80010001;
      }
      uVar3 = libspdm_read_uint16(param_4);
      *(undefined2 *)(param_1 + 0x1e2 + (ulong)bVar1 * 2) = uVar3;
      return 0;
    }
    if (param_2 < 0x1c) {
      if (param_2 == 0x19) {
        if (*param_3 != 0) {
          return 0x80010001;
        }
        if (param_5 != 1) {
          return 0x80010001;
        }
        if (7 < *(byte *)(param_3 + 1)) {
          return 0x80010001;
        }
        *(byte *)(param_1 + 0x1d1 + (ulong)*(byte *)(param_3 + 1)) = (byte)*param_4;
        return 0;
      }
      if (*param_3 != 0) {
        return 0x80010001;
      }
      if (param_5 != 1) {
        return 0x80010001;
      }
      if (7 < *(byte *)(param_3 + 1)) {
        return 0x80010001;
      }
      *(byte *)(param_1 + 0x1d9 + (ulong)*(byte *)(param_3 + 1)) = (byte)*param_4;
      return 0;
    }
    if (param_2 != 0x1c) {
      if (param_5 != 1) {
        return 0x80010001;
      }
      if (*param_3 != 0) {
        return 0x80010001;
      }
      bVar1 = (byte)*param_4;
      if ((2 < bVar1) && (bVar1 != 4)) {
        return 0x80010001;
      }
      *(byte *)(param_1 + 0x231) = bVar1;
      *(undefined1 *)(param_1 + 0xae) = 0;
      if ((byte)((char)param_3[1] - 8U) < 0xf7) {
        return 0x80010001;
      }
      *(char *)(param_1 + 0xaf) = (char)param_3[1];
      return 0;
    }
    if (param_5 != 1) {
      return 0x80010001;
    }
    if (*param_3 != 0) {
      return 0x80010001;
    }
    bVar1 = (byte)*param_4;
    if (1 < bVar1) {
      return 0x80010001;
    }
    *(undefined1 *)(param_1 + 0xae) = 0;
    *(byte *)(param_1 + 0x230) = bVar1 & 1;
    if ((byte)((char)param_3[1] - 8U) < 0xf7) {
      return 0x80010001;
    }
    *(char *)(param_1 + 0xaf) = (char)param_3[1];
    if (bVar1 == 0) {
      return 0;
    }
    libspdm_debug_print(0x40,"Basic mutual authentication is a deprecated feature.\n");
    return 0;
  }
  if (param_2 == 0xd) {
    if (param_5 != 2) {
      return 0x80010001;
    }
    uVar3 = libspdm_read_uint16(param_4);
    if (*param_3 != 1) {
      if (*param_3 == 0) {
        *(undefined2 *)(param_1 + 0x13a) = uVar3;
        return 0;
      }
      return 0x80010001;
    }
    *(undefined2 *)(param_1 + 0x282) = uVar3;
    return 0;
  }
  if (0xd < param_2) {
    if (param_2 == 0x13) {
      if (param_5 == 4) {
        uVar4 = libspdm_read_uint32(param_4);
        *(undefined4 *)(param_1 + 0xb1c) = uVar4;
        return 0;
      }
      return 0x80010001;
    }
    if (0x13 < param_2) {
      if (param_2 == 0x16) {
        if (*param_3 == 0) {
          *(ulong *)(param_1 + 0x220) = param_5;
          *(uint **)(param_1 + 0x218) = param_4;
          return 0;
        }
        return 0x80010001;
      }
      if (param_2 == 0x17) {
        if (*param_3 == 0) {
          *(ulong *)(param_1 + 0x200) = param_5;
          *(uint **)(param_1 + 0x1f8) = param_4;
          return 0;
        }
        return 0x80010001;
      }
      if (param_2 != 0x14) {
        if (*param_3 != 0) {
          return 0x80010001;
        }
        if (*(long *)(param_1 + 0x208) == 0) {
          *(ulong *)(param_1 + 0x210) = param_5;
          *(uint **)(param_1 + 0x208) = param_4;
          return 0;
        }
        return 0x8001000c;
      }
      if (*param_3 != 0) {
        return 0x80010001;
      }
      bVar1 = *(byte *)(param_3 + 1);
      if (bVar1 < 8) {
        *(ulong *)(param_1 + 400 + (ulong)bVar1 * 8) = param_5;
        *(uint **)(param_1 + 0x150 + (ulong)bVar1 * 8) = param_4;
        return 0;
      }
      return 0x80010001;
    }
    if (param_2 == 0x10) {
      if (param_5 != 1) {
        return 0x80010001;
      }
      if (*param_3 != 1) {
        if (*param_3 == 0) {
          *(byte *)(param_1 + 0x129) = (byte)*param_4;
          return 0;
        }
        return 0x80010001;
      }
      *(byte *)(param_1 + 0x271) = (byte)*param_4;
      return 0;
    }
    if (0x10 < param_2) {
      if (param_2 == 0x11) {
        if (param_5 != 1) {
          return 0x80010001;
        }
        if (*param_3 != 1) {
          if (*param_3 == 0) {
            *(byte *)(param_1 + 0x12a) = (byte)*param_4;
            return 0;
          }
          return 0x80010001;
        }
        *(byte *)(param_1 + 0x272) = (byte)*param_4;
        return 0;
      }
      if (param_5 != 4) {
        return 0x80010001;
      }
      if (*param_3 != 1) {
        return 0x80010001;
      }
      uVar4 = libspdm_read_uint32(param_4);
      *(undefined4 *)(param_1 + 0x238) = uVar4;
      return 0;
    }
    if (param_2 == 0xe) {
      if (param_5 != 2) {
        return 0x80010001;
      }
      uVar3 = libspdm_read_uint16(param_4);
      if (*param_3 != 1) {
        if (*param_3 == 0) {
          *(undefined2 *)(param_1 + 0x13c) = uVar3;
          return 0;
        }
        return 0x80010001;
      }
      *(undefined2 *)(param_1 + 0x284) = uVar3;
      return 0;
    }
    if (param_5 != 2) {
      return 0x80010001;
    }
    uVar3 = libspdm_read_uint16(param_4);
    if (*param_3 != 1) {
      if (*param_3 == 0) {
        *(undefined2 *)(param_1 + 0x13e) = uVar3;
        return 0;
      }
      return 0x80010001;
    }
    *(undefined2 *)(param_1 + 0x286) = uVar3;
    return 0;
  }
  if (param_2 == 6) {
    if (param_5 != 4) {
      return 0x80010001;
    }
    if (*param_3 == 1) {
      uVar6 = libspdm_read_uint32(param_4);
      if (uVar6 < 0x2a) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
                   0x13a,"data32 >= SPDM_MIN_DATA_TRANSFER_SIZE_VERSION_12");
      }
      *(uint *)(param_1 + 0x260) = uVar6;
      return 0;
    }
    return 0x80010001;
  }
  if (6 < param_2) {
    if (param_2 == 10) {
      if (param_5 != 4) {
        return 0x80010001;
      }
      uVar4 = libspdm_read_uint32(param_4);
      if (*param_3 != 1) {
        if (*param_3 == 0) {
          *(undefined4 *)(param_1 + 0x130) = uVar4;
          return 0;
        }
        return 0x80010001;
      }
      *(undefined4 *)(param_1 + 0x278) = uVar4;
      return 0;
    }
    if (10 < param_2) {
      if (param_2 == 0xb) {
        if (param_5 != 4) {
          return 0x80010001;
        }
        uVar4 = libspdm_read_uint32(param_4);
        if (*param_3 != 1) {
          if (*param_3 == 0) {
            *(undefined4 *)(param_1 + 0x134) = uVar4;
            return 0;
          }
          return 0x80010001;
        }
        *(undefined4 *)(param_1 + 0x27c) = uVar4;
        return 0;
      }
      if (param_5 != 2) {
        return 0x80010001;
      }
      uVar3 = libspdm_read_uint16(param_4);
      if (*param_3 != 1) {
        if (*param_3 == 0) {
          *(undefined2 *)(param_1 + 0x138) = uVar3;
          return 0;
        }
        return 0x80010001;
      }
      *(undefined2 *)(param_1 + 0x280) = uVar3;
      return 0;
    }
    if (param_2 == 8) {
      if (param_5 != 1) {
        return 0x80010001;
      }
      if (*param_3 != 1) {
        if (*param_3 == 0) {
          *(byte *)(param_1 + 0x128) = (byte)*param_4;
          return 0;
        }
        return 0x80010001;
      }
      *(byte *)(param_1 + 0x270) = (byte)*param_4;
      return 0;
    }
    if (param_2 != 9) {
      return 0x80010002;
    }
    if (param_5 != 4) {
      return 0x80010001;
    }
    uVar4 = libspdm_read_uint32(param_4);
    if (*param_3 == 1) {
      *(undefined4 *)(param_1 + 0x274) = uVar4;
      return 0;
    }
    if (*param_3 == 0) {
      *(undefined4 *)(param_1 + 300) = uVar4;
      return 0;
    }
    return 0x80010001;
  }
  if (param_2 == 2) {
    if (param_5 != 4) {
      return 0x80010001;
    }
    uVar6 = libspdm_read_uint32(param_4);
    if (*param_3 == 0) {
      if ((uVar6 & 4) != 0) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
                   0x101,"(data32 & SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_CHAL_CAP) == 0");
      }
      if ((uVar6 & 0xc00) != 0) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
                   0x111,"(data32 & SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_PSK_CAP) == 0");
      }
      *(uint *)(param_1 + 0x10c) = uVar6;
      return 0;
    }
    if (*param_3 == 1) {
      *(uint *)(param_1 + 0x254) = uVar6;
      return 0;
    }
    return 0x80010001;
  }
  if (2 < param_2) {
    if (param_2 == 3) {
      if (param_5 != 1) {
        return 0x80010001;
      }
      if (*param_3 != 1) {
        if (*param_3 == 0) {
          *(byte *)(param_1 + 0xf8) = (byte)*param_4;
          return 0;
        }
        return 0x80010001;
      }
      *(byte *)(param_1 + 0x240) = (byte)*param_4;
      return 0;
    }
    if (param_2 != 4) {
      return 0x80010002;
    }
    if (param_5 != 8) {
      return 0x80010001;
    }
    if (*param_3 != 0) {
      return 0x80010001;
    }
    uVar9 = libspdm_read_uint64(param_4);
    *(undefined8 *)(param_1 + 0x100) = uVar9;
    return 0;
  }
  if (param_2 == 0) {
    if (param_5 < 9) {
      iVar5 = *param_3;
      if (iVar5 != 1) {
LAB_004fa746:
        if (iVar5 == 0) {
          *(char *)(param_1 + 0xe8) = (char)(param_5 >> 1);
          libspdm_copy_mem(param_1 + 0xea,8,param_4,(uint)param_5 & 0x1fe);
          return 0;
        }
        return 0x80010001;
      }
      if (param_5 == 2) goto LAB_004fa9b8;
    }
    else {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
                 200,"data_size <= sizeof(spdm_version_number_t) * SPDM_MAX_VERSION_COUNT");
      iVar5 = *param_3;
      if (iVar5 != 1) goto LAB_004fa746;
    }
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",0xcb
               ,"data_size == sizeof(spdm_version_number_t)");
LAB_004fa9b8:
    libspdm_copy_mem(param_1 + 0x23c,2,param_4,2);
    return 0;
  }
  if (param_5 < 7) {
    iVar5 = *param_3;
    if (iVar5 != 1) {
LAB_004fa01d:
      if (iVar5 == 0) {
        *(char *)(param_1 + 0x140) = (char)(param_5 >> 1);
        libspdm_copy_mem(param_1 + 0x142,8,param_4,(uint)param_5 & 0x1fe);
        return 0;
      }
      return 0x80010001;
    }
    if (param_5 == 2) goto LAB_004fa92c;
  }
  else {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",0xdd
               ,"data_size <= sizeof(spdm_version_number_t) * SECURED_SPDM_MAX_VERSION_COUNT");
    iVar5 = *param_3;
    if (iVar5 != 1) goto LAB_004fa01d;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",0xe1,
             "data_size == sizeof(spdm_version_number_t)");
LAB_004fa92c:
  libspdm_copy_mem(param_1 + 0x288,2,param_4,2);
  return 0;
}


// ===== 004faca0 libspdm_get_data =====

undefined8 libspdm_get_data(long param_1,uint param_2,int *param_3,long param_4,ulong *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  byte bVar5;
  long lVar6;
  
  if ((((param_1 == 0) || (param_4 == 0)) || (param_5 == (ulong *)0x0)) || (0x3a < param_2)) {
    return 0x80010001;
  }
  if (param_2 == 0x28) {
    uVar1 = libspdm_read_uint32(param_3 + 1);
    lVar6 = libspdm_get_session_info_via_session_id(param_1,uVar1);
    if (*param_3 != 1) {
      return 0x80010001;
    }
    uVar4 = 1;
    lVar3 = lVar6 + 6;
    if (lVar6 == 0) {
      lVar3 = param_1 + 0x649;
    }
    goto LAB_004fad60;
  }
  if (param_2 - 0x26 < 0x12) {
    if ((0x2300fUL >> ((ulong)(param_2 - 0x26) & 0x3f) & 1) == 0) {
      lVar3 = 0;
      lVar6 = 0;
    }
    else {
      if (*param_3 != 2) {
        return 0x80010001;
      }
      uVar1 = libspdm_read_uint32(param_3 + 1);
      lVar3 = libspdm_get_session_info_via_session_id(param_1,uVar1);
      if (lVar3 == 0) {
        return 0x80010001;
      }
      lVar6 = *(long *)(lVar3 + 0x1f0);
    }
    if (param_2 == 0x31) {
      uVar4 = 4;
      lVar3 = param_1 + 0xb48;
      goto LAB_004fad60;
    }
    if (param_2 < 0x32) {
      if (param_2 == 0x29) {
        uVar4 = 1;
        lVar3 = lVar3 + 7;
      }
      else if (param_2 < 0x2a) {
        if (param_2 == 0x26) {
          uVar4 = 1;
          lVar3 = lVar3 + 4;
        }
        else {
          uVar4 = 1;
          lVar3 = lVar3 + 5;
        }
      }
      else if (param_2 == 0x2c) {
        uVar4 = *(ulong *)(param_1 + 0x658);
        lVar3 = param_1 + 0x660;
      }
      else if (param_2 < 0x2d) {
        if (param_2 == 0x2a) {
          uVar4 = 8;
          lVar3 = param_1 + 0xb38;
        }
        else {
          uVar4 = 1;
          lVar3 = param_1 + 0xb40;
        }
      }
      else {
        uVar4 = 4;
        lVar3 = param_1 + 0xb44;
        if (param_2 != 0x30) {
          return 0x80010002;
        }
      }
      goto LAB_004fad60;
    }
    if (param_2 == 0x36) {
      uVar4 = 1;
      lVar3 = param_1 + 0xb60;
      goto LAB_004fad60;
    }
    if (param_2 != 0x37) {
      if (param_2 == 0x34) {
        uVar4 = 8;
        lVar3 = param_1 + 0xb58;
      }
      else if (param_2 == 0x35) {
        uVar4 = 1;
        lVar3 = param_1 + 0xb90;
      }
      else if (param_2 == 0x32) {
        uVar4 = 8;
        lVar3 = lVar6 + 0x308;
      }
      else {
        uVar4 = 8;
        lVar3 = lVar6 + 0x2d0;
      }
      goto LAB_004fad60;
    }
  }
  else {
    if (param_2 == 0x22) {
      if (*param_3 != 1) {
        return 0x80010001;
      }
      lVar6 = 0;
      lVar3 = 0;
      do {
        bVar5 = (byte)lVar6;
        lVar6 = lVar6 + 1;
        lVar3 = lVar3 + (ulong)((int)(uint)*(byte *)(param_1 + 0x28a) >> (bVar5 & 0x1f) & 1);
      } while (lVar6 != 8);
      uVar2 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
      uVar4 = (ulong)uVar2 * lVar3;
      lVar3 = param_1 + 0x28c;
      goto LAB_004fad60;
    }
    if (param_2 < 0x23) {
      if (param_2 == 0xb) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        uVar4 = 4;
        lVar3 = param_1 + 0x27c;
      }
      else if (param_2 < 0xc) {
        if (param_2 == 6) {
          if (*param_3 == 1) {
            uVar4 = 4;
            lVar3 = param_1 + 0x260;
          }
          else {
            if (*param_3 != 0) {
              return 0x80010001;
            }
            uVar4 = 4;
            lVar3 = param_1 + 0x118;
          }
        }
        else if (param_2 < 7) {
          if (param_2 == 2) {
            if (*param_3 == 1) {
              uVar4 = 4;
              lVar3 = param_1 + 0x254;
            }
            else {
              if (*param_3 != 0) {
                return 0x80010001;
              }
              uVar4 = 4;
              lVar3 = param_1 + 0x10c;
            }
          }
          else if (param_2 < 3) {
            if (param_2 == 0) {
              if (*param_3 != 1) {
                return 0x80010001;
              }
              uVar4 = 2;
              lVar3 = param_1 + 0x23c;
            }
            else {
              if (*param_3 != 1) {
                return 0x80010001;
              }
              uVar4 = 2;
              lVar3 = param_1 + 0x288;
            }
          }
          else if (param_2 == 3) {
            if (*param_3 == 1) {
              uVar4 = 1;
              lVar3 = param_1 + 0x240;
            }
            else {
              if (*param_3 != 0) {
                return 0x80010001;
              }
              uVar4 = 1;
              lVar3 = param_1 + 0xf8;
            }
          }
          else {
            if (param_2 != 5) {
              return 0x80010002;
            }
            if (*param_3 == 1) {
              uVar4 = 4;
              lVar3 = param_1 + 600;
            }
            else {
              if (*param_3 != 0) {
                return 0x80010001;
              }
              uVar4 = 4;
              lVar3 = param_1 + 0x110;
            }
          }
        }
        else if (param_2 == 9) {
          if (*param_3 != 1) {
            return 0x80010001;
          }
          uVar4 = 4;
          lVar3 = param_1 + 0x274;
        }
        else if (param_2 == 10) {
          if (*param_3 != 1) {
            return 0x80010001;
          }
          uVar4 = 4;
          lVar3 = param_1 + 0x278;
        }
        else if (param_2 == 7) {
          if (*param_3 != 0) {
            return 0x80010001;
          }
          uVar4 = 4;
          lVar3 = param_1 + 0x114;
        }
        else {
          if (*param_3 != 1) {
            return 0x80010001;
          }
          uVar4 = 1;
          lVar3 = param_1 + 0x270;
        }
      }
      else if (param_2 == 0x11) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        uVar4 = 1;
        lVar3 = param_1 + 0x272;
      }
      else if (param_2 < 0x12) {
        if (param_2 == 0xe) {
          if (*param_3 != 1) {
            return 0x80010001;
          }
          uVar4 = 2;
          lVar3 = param_1 + 0x284;
        }
        else if (param_2 < 0xf) {
          if (param_2 == 0xc) {
            if (*param_3 != 1) {
              return 0x80010001;
            }
            uVar4 = 2;
            lVar3 = param_1 + 0x280;
          }
          else {
            if (*param_3 != 1) {
              return 0x80010001;
            }
            uVar4 = 2;
            lVar3 = param_1 + 0x282;
          }
        }
        else if (param_2 == 0xf) {
          if (*param_3 != 1) {
            return 0x80010001;
          }
          uVar4 = 2;
          lVar3 = param_1 + 0x286;
        }
        else {
          if (*param_3 != 1) {
            return 0x80010001;
          }
          uVar4 = 1;
          lVar3 = param_1 + 0x271;
        }
      }
      else if (param_2 == 0x20) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        uVar4 = 1;
        lVar3 = param_1 + 0x28a;
      }
      else if (param_2 == 0x21) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        uVar4 = 1;
        lVar3 = param_1 + 0x28b;
      }
      else if (param_2 == 0x12) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        uVar4 = 4;
        lVar3 = param_1 + 0x238;
      }
      else {
        uVar4 = 4;
        lVar3 = param_1 + 0xb1c;
        if (param_2 != 0x13) {
          return 0x80010002;
        }
      }
      goto LAB_004fad60;
    }
    if (param_2 < 0x32) {
      if (param_2 == 0x25) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        if (7 < *(byte *)(param_3 + 1)) {
          return 0x80010001;
        }
        uVar4 = 2;
        lVar3 = param_1 + 0x41c + (ulong)*(byte *)(param_3 + 1) * 2;
      }
      else if (param_2 == 0x23) {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        if (7 < *(byte *)(param_3 + 1)) {
          return 0x80010001;
        }
        uVar4 = 1;
        lVar3 = param_1 + 0x40c + (ulong)*(byte *)(param_3 + 1);
      }
      else {
        if (*param_3 != 1) {
          return 0x80010001;
        }
        if (7 < *(byte *)(param_3 + 1)) {
          return 0x80010001;
        }
        uVar4 = 1;
        lVar3 = param_1 + 0x414 + (ulong)*(byte *)(param_3 + 1);
      }
      goto LAB_004fad60;
    }
    if (param_2 == 0x39) {
      if (*param_3 != 1) {
        return 0x80010001;
      }
      uVar4 = 1;
      lVar3 = param_1 + 0x64b;
      goto LAB_004fad60;
    }
    if (param_2 == 0x3a) {
      if (*param_3 != 0) {
        return 0x80010001;
      }
      uVar4 = 1;
      lVar3 = param_1 + 0x234;
      goto LAB_004fad60;
    }
    lVar6 = 0;
    if (param_2 != 0x37) {
      if (*param_3 != 1) {
        return 0x80010001;
      }
      uVar4 = 1;
      lVar3 = param_1 + 0x64a;
      goto LAB_004fad60;
    }
  }
  uVar4 = 1;
  lVar3 = lVar6 + 0x420;
LAB_004fad60:
  if (uVar4 <= *param_5) {
    libspdm_copy_mem(param_4,*param_5,lVar3,uVar4);
    *param_5 = uVar4;
    return 0;
  }
  *param_5 = uVar4;
  return 0x8001000d;
}


// ===== 004fb450 libspdm_check_context =====

undefined8 libspdm_check_context(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  if (*(uint *)(param_1 + 0x110) < 0x2a) {
    libspdm_debug_print(0x80000000,
                        "data_transfer_size must be greater than or equal to SPDM_MIN_DATA_TRANSFER_SIZE (%d).\n"
                        ,0x2a);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x118);
    if (uVar1 < *(uint *)(param_1 + 0x110)) {
      libspdm_debug_print(0x80000000,
                          "max_spdm_msg_size (%d) must be greater than or equal to data_transfer_size (%d).\n"
                         );
    }
    else if (*(uint *)(param_1 + 0x114) < 0x2a) {
      libspdm_debug_print(0x80000000,
                          "sender_data_transfer_size must be greater than or equal to %d.\n",0x2a);
    }
    else {
      if (*(uint *)(param_1 + 0x114) <= uVar1) {
        if ((*(byte *)(param_1 + 0x10e) & 2) != 0) {
          lVar3 = 0;
          do {
            lVar2 = *(long *)(param_1 + 400 + lVar3 * 8);
            if ((lVar2 != 0) && ((ulong)uVar1 < lVar2 + 8U)) {
              libspdm_debug_print(0x80000000,
                                  "max_spdm_msg_size (%d) must be greater than or equal to local_cert_chain_provision_size[%zu] (%zu).\n"
                                 );
              return 0;
            }
            lVar3 = lVar3 + 1;
          } while (lVar3 != 8);
        }
        return 1;
      }
      libspdm_debug_print(0x80000000,
                          "max_spdm_msg_size (%d) must be greater than or equal to sender_data_transfer_size (%d).\n"
                         );
    }
  }
  return 0;
}


// ===== 004fb570 libspdm_reset_message_a =====

void libspdm_reset_message_a(long param_1)

{
  libspdm_reset_managed_buffer(param_1 + 0x650);
  return;
}


// ===== 004fb580 libspdm_reset_message_d =====

void libspdm_reset_message_d(long param_1)

{
  libspdm_reset_managed_buffer(param_1 + 0x738);
  return;
}


// ===== 004fb590 libspdm_reset_message_b =====

void libspdm_reset_message_b(long param_1)

{
  if (*(long *)(param_1 + 0x8f0) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    *(undefined8 *)(param_1 + 0x8f0) = 0;
    return;
  }
  return;
}


// ===== 004fb5e0 libspdm_reset_message_c =====

void libspdm_reset_message_c(long param_1)

{
  if (*(long *)(param_1 + 0x8f0) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    *(undefined8 *)(param_1 + 0x8f0) = 0;
    return;
  }
  return;
}


// ===== 004fb630 libspdm_reset_message_mut_b =====

void libspdm_reset_message_mut_b(long param_1)

{
  if (*(long *)(param_1 + 0x8f8) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    *(undefined8 *)(param_1 + 0x8f8) = 0;
    return;
  }
  return;
}


// ===== 004fb680 libspdm_reset_message_mut_c =====

void libspdm_reset_message_mut_c(long param_1)

{
  if (*(long *)(param_1 + 0x8f8) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    *(undefined8 *)(param_1 + 0x8f8) = 0;
    return;
  }
  return;
}


// ===== 004fb6d0 libspdm_reset_message_m =====

void libspdm_reset_message_m(long param_1,long param_2)

{
  if (param_2 == 0) {
    if (*(long *)(param_1 + 0x900) != 0) {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
      *(undefined8 *)(param_1 + 0x900) = 0;
      return;
    }
  }
  else if (*(long *)(param_2 + 0x1d8) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    *(undefined8 *)(param_2 + 0x1d8) = 0;
  }
  return;
}


// ===== 004fb750 libspdm_reset_message_f =====

void libspdm_reset_message_f(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_2 + 0x1d0) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    uVar1 = *(undefined8 *)(param_2 + 0x1e0);
    *(undefined1 *)(param_2 + 0x1c8) = 0;
    *(undefined8 *)(param_2 + 0x1e0) = 0;
    *(undefined8 *)(param_2 + 0x1d0) = uVar1;
    return;
  }
  *(undefined1 *)(param_2 + 0x1c8) = 0;
  return;
}


// ===== 004fb7b0 libspdm_reset_message_buffer_via_request_code =====

void libspdm_reset_message_buffer_via_request_code(long param_1,long param_2,byte param_3)

{
  if (param_3 != 0xe0) {
    if (param_2 == 0) {
      if (*(long *)(param_1 + 0x900) != 0) {
        libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
        *(undefined8 *)(param_1 + 0x900) = 0;
      }
    }
    else if (*(long *)(param_2 + 0x1d8) != 0) {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
      *(undefined8 *)(param_2 + 0x1d8) = 0;
    }
    if (param_3 == 0xeb) {
      if (5 < *(uint *)(param_1 + 0x238)) {
        return;
      }
LAB_004fb879:
      if (*(long *)(param_1 + 0x8f0) == 0) {
        return;
      }
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
      *(undefined8 *)(param_1 + 0x8f0) = 0;
      return;
    }
    if (param_3 < 0xec) {
      if (param_3 == 0x81) goto LAB_004fb879;
      if (6 < (byte)(param_3 + 0x1c)) {
        return;
      }
    }
    else if ((param_3 != 0xec) && (param_3 != 0xef)) {
      return;
    }
  }
  if (*(uint *)(param_1 + 0x238) < 6) {
    if (*(long *)(param_1 + 0x8f0) != 0) {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
      *(undefined8 *)(param_1 + 0x8f0) = 0;
    }
    if (*(long *)(param_1 + 0x8f8) != 0) {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
      *(undefined8 *)(param_1 + 0x8f8) = 0;
      return;
    }
  }
  return;
}


// ===== 004fb930 libspdm_append_message_a =====

void libspdm_append_message_a(long param_1)

{
  libspdm_append_managed_buffer(param_1 + 0x650);
  return;
}


// ===== 004fb940 libspdm_append_message_b =====

undefined8 libspdm_append_message_b(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  lVar2 = *(long *)(param_1 + 0x8f0);
  if (lVar2 == 0) {
    lVar2 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
    *(long *)(param_1 + 0x8f0) = lVar2;
    if (lVar2 == 0) {
      return 0x80020000;
    }
    cVar1 = libspdm_hash_init(*(undefined4 *)(param_1 + 0x27c),lVar2);
    if (cVar1 == '\0') goto LAB_004fba18;
    uVar3 = libspdm_get_managed_buffer_size();
    uVar4 = libspdm_get_managed_buffer(param_1 + 0x650);
    cVar1 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_1 + 0x8f0),
                                uVar4,uVar3);
    lVar2 = *(long *)(param_1 + 0x8f0);
    if (cVar1 == '\0') {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar2);
      *(undefined8 *)(param_1 + 0x8f0) = 0;
      return 0x80020000;
    }
  }
  cVar1 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),lVar2,param_2,param_3);
  if (cVar1 != '\0') {
    return 0;
  }
LAB_004fba18:
  libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_1 + 0x8f0));
  *(undefined8 *)(param_1 + 0x8f0) = 0;
  return 0x80020000;
}


// ===== 004fba70 libspdm_append_message_mut_b =====

undefined8 libspdm_append_message_mut_b(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  lVar2 = *(long *)(param_1 + 0x8f8);
  if (lVar2 == 0) {
    lVar2 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
    *(long *)(param_1 + 0x8f8) = lVar2;
    if (lVar2 == 0) {
      return 0x80020000;
    }
    cVar1 = libspdm_hash_init(*(undefined4 *)(param_1 + 0x27c),lVar2);
    if (cVar1 == '\0') goto LAB_004fbb08;
    if (*(byte *)(param_1 + 0x23d) < 0x12) {
      lVar2 = *(long *)(param_1 + 0x8f8);
    }
    else {
      uVar3 = libspdm_get_managed_buffer_size();
      uVar4 = libspdm_get_managed_buffer(param_1 + 0x650);
      cVar1 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_1 + 0x8f8),
                                  uVar4,uVar3);
      lVar2 = *(long *)(param_1 + 0x8f8);
      if (cVar1 == '\0') {
        libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar2);
        *(undefined8 *)(param_1 + 0x8f8) = 0;
        return 0x80020000;
      }
    }
  }
  cVar1 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),lVar2,param_2,param_3);
  if (cVar1 != '\0') {
    return 0;
  }
LAB_004fbb08:
  libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_1 + 0x8f8));
  *(undefined8 *)(param_1 + 0x8f8) = 0;
  return 0x80020000;
}


// ===== 004fbbb0 libspdm_append_message_m =====

undefined8 libspdm_append_message_m(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_1 + 0x27c);
  if (param_2 == 0) {
    lVar2 = *(long *)(param_1 + 0x900);
    if (lVar2 == 0) {
      lVar2 = libspdm_hash_new(uVar5);
      *(long *)(param_1 + 0x900) = lVar2;
      if (lVar2 == 0) {
        return 0x80020000;
      }
      cVar1 = libspdm_hash_init(*(undefined4 *)(param_1 + 0x27c),lVar2);
      if (cVar1 == '\0') goto LAB_004fbc83;
      if (*(byte *)(param_1 + 0x23d) < 0x12) {
        lVar2 = *(long *)(param_1 + 0x900);
        uVar5 = *(undefined4 *)(param_1 + 0x27c);
      }
      else {
        uVar3 = libspdm_get_managed_buffer_size(param_1 + 0x650);
        uVar4 = libspdm_get_managed_buffer(param_1 + 0x650);
        cVar1 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),
                                    *(undefined8 *)(param_1 + 0x900),uVar4,uVar3);
        lVar2 = *(long *)(param_1 + 0x900);
        uVar5 = *(undefined4 *)(param_1 + 0x27c);
        if (cVar1 == '\0') {
          libspdm_hash_free(uVar5,lVar2);
          *(undefined8 *)(param_1 + 0x900) = 0;
          return 0x80020000;
        }
      }
    }
    cVar1 = libspdm_hash_update(uVar5,lVar2,param_3,param_4);
    if (cVar1 != '\0') {
      return 0;
    }
LAB_004fbc83:
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_1 + 0x900));
    *(undefined8 *)(param_1 + 0x900) = 0;
    return 0x80020000;
  }
  lVar2 = *(long *)(param_2 + 0x1d8);
  if (lVar2 == 0) {
    lVar2 = libspdm_hash_new();
    *(long *)(param_2 + 0x1d8) = lVar2;
    if (lVar2 == 0) {
      return 0x80020000;
    }
    cVar1 = libspdm_hash_init(*(undefined4 *)(param_1 + 0x27c),lVar2);
    if (cVar1 == '\0') goto LAB_004fbca8;
    if (*(byte *)(param_1 + 0x23d) < 0x12) {
      lVar2 = *(long *)(param_2 + 0x1d8);
      uVar5 = *(undefined4 *)(param_1 + 0x27c);
    }
    else {
      uVar3 = libspdm_get_managed_buffer_size();
      uVar4 = libspdm_get_managed_buffer(param_1 + 0x650);
      cVar1 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d8),
                                  uVar4,uVar3);
      lVar2 = *(long *)(param_2 + 0x1d8);
      uVar5 = *(undefined4 *)(param_1 + 0x27c);
      if (cVar1 == '\0') {
        libspdm_hash_free(uVar5,lVar2);
        *(undefined8 *)(param_2 + 0x1d8) = 0;
        return 0x80020000;
      }
    }
  }
  cVar1 = libspdm_hash_update(uVar5,lVar2,param_3,param_4);
  if (cVar1 != '\0') {
    return 0;
  }
LAB_004fbca8:
  libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d8));
  *(undefined8 *)(param_2 + 0x1d8) = 0;
  return 0x80020000;
}


// ===== 004fbe20 libspdm_append_message_k =====

undefined8
libspdm_append_message_k
          (long param_1,long param_2,char param_3,undefined8 param_4,undefined8 param_5)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 local_68 [56];
  
  iVar3 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  lVar4 = *(long *)(param_2 + 0x1d0);
  if (lVar4 == 0) {
    if (*(char *)(param_2 + 4) == '\0') {
      if (param_3 == '\0') {
        if ((byte)(*(char *)(param_1 + 0x648) - 8U) < 0xf7) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c"
                     ,0x7cd,"(slot_id < SPDM_MAX_SLOT_COUNT) || (slot_id == 0xFF)");
LAB_004fc0d0:
          cVar2 = libspdm_get_local_cert_chain_buffer(param_1,&local_78,&local_70);
        }
        else {
          if (*(char *)(param_1 + 0x648) != -1) goto LAB_004fc0d0;
          cVar2 = libspdm_get_local_public_key_buffer(param_1,&local_78,&local_70);
        }
        uVar5 = 0x80010003;
joined_r0x004fc061:
        if (cVar2 == '\0') {
          return uVar5;
        }
        cVar2 = libspdm_hash_all(*(undefined4 *)(param_1 + 0x27c),local_78,local_70,local_68);
        if (cVar2 == '\0') {
          return 0x80020000;
        }
      }
      else {
        bVar1 = *(byte *)(param_1 + 0x630);
        if ((byte)(bVar1 - 8) < 0xf7) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c"
                     ,0x7af,"(slot_id < SPDM_MAX_SLOT_COUNT) || (slot_id == 0xFF)");
        }
        else if (bVar1 == 0xff) {
          cVar2 = libspdm_get_peer_public_key_buffer(param_1,&local_78,&local_70);
          uVar5 = 0x80010004;
          goto joined_r0x004fc061;
        }
        if (*(int *)(param_1 + 0x460 + (ulong)bVar1 * 0x40) != iVar3) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c"
                     ,0x7c0,
                     "hash_size == spdm_context->connection_info .peer_used_cert_chain[slot_id].buffer_hash_size"
                    );
        }
        libspdm_copy_mem(local_68,0x30,param_1 + 0x430 + (ulong)bVar1 * 0x40,iVar3);
      }
      lVar4 = *(long *)(param_2 + 0x1d0);
      if (lVar4 != 0) goto LAB_004fbe5e;
    }
    lVar4 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
    *(long *)(param_2 + 0x1d0) = lVar4;
    if (lVar4 == 0) {
      return 0x80020000;
    }
    cVar2 = libspdm_hash_init(*(undefined4 *)(param_1 + 0x27c),lVar4);
    if (cVar2 != '\0') {
      uVar5 = libspdm_get_managed_buffer_size();
      uVar6 = libspdm_get_managed_buffer(param_1 + 0x650);
      cVar2 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),
                                  uVar6,uVar5);
      if (cVar2 != '\0') {
        if (*(char *)(param_2 + 4) == '\0') {
          if (*(char *)(param_1 + 0x64b) != '\0') {
            uVar5 = libspdm_get_managed_buffer_size();
            uVar6 = libspdm_get_managed_buffer(param_1 + 0x738);
            cVar2 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),
                                        *(undefined8 *)(param_2 + 0x1d0),uVar6,uVar5);
            if (cVar2 == '\0') goto LAB_004fbfd0;
          }
          cVar2 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),
                                      *(undefined8 *)(param_2 + 0x1d0),local_68,iVar3);
          lVar4 = *(long *)(param_2 + 0x1d0);
          if (cVar2 == '\0') goto LAB_004fbfd7;
        }
        else {
          lVar4 = *(long *)(param_2 + 0x1d0);
        }
        goto LAB_004fbe5e;
      }
    }
  }
  else {
LAB_004fbe5e:
    cVar2 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),lVar4,param_4,param_5);
    if (cVar2 != '\0') {
      return 0;
    }
  }
LAB_004fbfd0:
  lVar4 = *(long *)(param_2 + 0x1d0);
LAB_004fbfd7:
  libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar4);
  return 0x80020000;
}


// ===== 004fc140 libspdm_append_message_encap_d =====

undefined8
libspdm_append_message_encap_d
          (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = libspdm_get_managed_buffer_size(param_2 + 0x10);
  if (lVar1 != 0) {
    return 0;
  }
  uVar2 = libspdm_append_managed_buffer(param_2 + 0x10,param_4,param_5);
  return uVar2;
}


// ===== 004fc190 libspdm_append_message_f =====

ulong libspdm_append_message_f
                (long param_1,long param_2,char param_3,undefined8 param_4,undefined8 param_5)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 local_68 [56];
  
  iVar3 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  lVar4 = *(long *)(param_2 + 0x1d0);
  if (*(char *)(param_2 + 0x1c8) == '\0') {
    if (lVar4 == 0) {
      uVar7 = libspdm_append_message_k(param_1,param_2,param_3,0,0);
      if (((uint)(uVar7 >> 0x1c) & 0xf) == 8) {
        return uVar7;
      }
      if ((*(char *)(param_2 + 4) == '\0') && (*(char *)(param_2 + 5) != '\0')) goto LAB_004fc3a0;
LAB_004fc404:
      if (*(long *)(param_2 + 0x1d0) == 0) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
                   0x8b3,"spdm_session_info->session_transcript.digest_context_th != NULL");
      }
    }
    else if ((*(char *)(param_2 + 4) == '\0') && (*(char *)(param_2 + 5) != '\0')) {
LAB_004fc3a0:
      if (param_3 == '\0') {
        bVar1 = *(byte *)(param_1 + 0x630);
        if ((byte)(bVar1 - 8) < 0xf7) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c"
                     ,0x890,"(slot_id < SPDM_MAX_SLOT_COUNT) || (slot_id == 0xFF)");
LAB_004fc448:
          if (*(int *)(param_1 + 0x460 + (ulong)bVar1 * 0x40) != iVar3) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c"
                       ,0x8a2,
                       "hash_size == spdm_context->connection_info .peer_used_cert_chain[slot_id].buffer_hash_size"
                      );
          }
          libspdm_copy_mem(local_68,0x30,param_1 + 0x430 + (ulong)bVar1 * 0x40,iVar3);
          goto LAB_004fc404;
        }
        if (bVar1 != 0xff) goto LAB_004fc448;
        cVar2 = libspdm_get_peer_public_key_buffer(param_1,&local_78,&local_70);
        uVar7 = 0x80010004;
      }
      else {
        if ((byte)(*(char *)(param_1 + 0x648) - 8U) < 0xf7) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c"
                     ,0x877,"(slot_id < SPDM_MAX_SLOT_COUNT) || (slot_id == 0xFF)");
LAB_004fc4e0:
          cVar2 = libspdm_get_local_cert_chain_buffer(param_1,&local_78,&local_70);
        }
        else {
          if (*(char *)(param_1 + 0x648) != -1) goto LAB_004fc4e0;
          cVar2 = libspdm_get_local_public_key_buffer(param_1,&local_78,&local_70);
        }
        uVar7 = 0x80010003;
      }
      if (cVar2 == '\0') {
        return uVar7;
      }
      cVar2 = libspdm_hash_all(*(undefined4 *)(param_1 + 0x27c),local_78,local_70,local_68);
      if (cVar2 == '\0') {
        return 0x80020000;
      }
      goto LAB_004fc404;
    }
    lVar4 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
    *(long *)(param_2 + 0x1e0) = lVar4;
    if (lVar4 == 0) {
      return 0x80020000;
    }
    cVar2 = libspdm_hash_duplicate
                      (*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),lVar4);
    if (cVar2 == '\0') {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1e0));
      *(undefined8 *)(param_2 + 0x1e0) = 0;
      return 0x80020000;
    }
    if (*(long *)(param_2 + 0x1d0) == 0) {
LAB_004fc305:
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
                 0x8c7,"spdm_session_info->session_transcript.digest_context_th != NULL");
    }
    if (((*(char *)(param_2 + 0x1c8) != '\0') || (*(char *)(param_2 + 4) != '\0')) ||
       (*(char *)(param_2 + 5) == '\0')) {
      lVar4 = *(long *)(param_2 + 0x1d0);
      goto LAB_004fc2d0;
    }
    if (*(char *)(param_1 + 0x64a) == '\0') {
LAB_004fc29c:
      cVar2 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),
                                  local_68,iVar3);
      lVar4 = *(long *)(param_2 + 0x1d0);
      if (cVar2 == '\0') goto LAB_004fc33f;
      goto LAB_004fc2d0;
    }
    uVar5 = libspdm_get_managed_buffer_size();
    uVar6 = libspdm_get_managed_buffer(param_2 + 0x10);
    cVar2 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),
                                uVar6,uVar5);
    if (cVar2 != '\0') goto LAB_004fc29c;
  }
  else {
    if (lVar4 == 0) goto LAB_004fc305;
LAB_004fc2d0:
    cVar2 = libspdm_hash_update(*(undefined4 *)(param_1 + 0x27c),lVar4,param_4,param_5);
    if (cVar2 != '\0') {
      *(undefined1 *)(param_2 + 0x1c8) = 1;
      return 0;
    }
  }
  lVar4 = *(long *)(param_2 + 0x1d0);
LAB_004fc33f:
  libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar4);
  *(undefined8 *)(param_2 + 0x1d0) = 0;
  return 0x80020000;
}


// ===== 004fc550 libspdm_get_connection_version =====

undefined1 libspdm_get_connection_version(long param_1)

{
  return *(undefined1 *)(param_1 + 0x23d);
}


// ===== 004fc560 libspdm_is_capabilities_flag_supported =====

bool libspdm_is_capabilities_flag_supported(long param_1,char param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = *(uint *)(param_1 + 0x254);
  uVar2 = *(uint *)(param_1 + 0x10c);
  if (param_2 == '\0') {
    uVar1 = *(uint *)(param_1 + 0x10c);
    uVar2 = *(uint *)(param_1 + 0x254);
  }
  if (((param_3 == 0) || (bVar3 = false, (uVar2 & param_3) != 0)) && (bVar3 = true, param_4 != 0)) {
    bVar3 = (uVar1 & param_4) != 0;
  }
  return bVar3;
}


// ===== 004fc5a0 libspdm_is_encap_supported =====

uint libspdm_is_encap_supported(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 0x23d) != '\x10') {
    uVar1 = *(uint *)(param_1 + 0x254);
    uVar2 = *(uint *)(param_1 + 0x10c);
    if (*(char *)(param_1 + 0x23d) == '\x12') {
      uVar3 = uVar1;
      if (*(char *)(param_1 + 0x233) == '\0') {
        uVar3 = uVar2;
        uVar2 = uVar1;
      }
      if ((uVar2 & 0x100) != 0) {
        return CONCAT31((int3)(uVar3 >> 8),(uVar3 & 0x1100) != 0);
      }
      if ((uVar3 & 0x1100) != 0) {
        return uVar2 >> 0xc & 1;
      }
    }
    else {
      uVar3 = uVar1;
      if (*(char *)(param_1 + 0x233) == '\0') {
        uVar3 = uVar2;
        uVar2 = uVar1;
      }
      if ((uVar2 & 0x1000) != 0) {
        return uVar3 >> 0xc & 1;
      }
    }
  }
  return 0;
}


// ===== 004fc620 libspdm_register_device_io_func =====

void libspdm_register_device_io_func(long param_1,undefined8 param_2,undefined8 param_3)

{
  *(undefined8 *)(param_1 + 8) = param_2;
  *(undefined8 *)(param_1 + 0x10) = param_3;
  return;
}


// ===== 004fc630 libspdm_register_device_buffer_func =====

void libspdm_register_device_buffer_func
               (long param_1,uint param_2,uint param_3,undefined8 param_4,undefined8 param_5,
               undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  
  *(ulong *)(param_1 + 0x70) = (ulong)param_2;
  *(ulong *)(param_1 + 0x80) = (ulong)param_3;
  *(undefined8 *)(param_1 + 0x18) = param_4;
  *(undefined8 *)(param_1 + 0x30) = param_7;
  uVar1 = *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x11c);
  *(undefined8 *)(param_1 + 0x20) = param_5;
  *(undefined8 *)(param_1 + 0x28) = param_6;
  if (param_2 < uVar1) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0x9af,
               "sender_buffer_size >= context->local_context.capability.transport_header_size + context->local_context.capability.transport_tail_size"
              );
    uVar1 = *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x11c);
  }
  param_2 = param_2 - uVar1;
  if (param_2 < 0x2a) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0x9b4,"sender_buffer_size >= SPDM_MIN_DATA_TRANSFER_SIZE_VERSION_12");
    uVar1 = *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x11c);
    *(uint *)(param_1 + 0x114) = param_2;
  }
  else {
    *(uint *)(param_1 + 0x114) = param_2;
  }
  if (param_3 < uVar1) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0x9b7,
               "receiver_buffer_size >= context->local_context.capability.transport_header_size + context->local_context.capability.transport_tail_size"
              );
    uVar1 = *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x11c);
  }
  param_3 = param_3 - uVar1;
  if (0x29 < param_3) {
    *(uint *)(param_1 + 0x110) = param_3;
    return;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",0x9bc,
             "receiver_buffer_size >= SPDM_MIN_DATA_TRANSFER_SIZE_VERSION_12");
  *(uint *)(param_1 + 0x110) = param_3;
  return;
}


// ===== 004fc790 libspdm_register_transport_layer_func =====

void libspdm_register_transport_layer_func
               (long param_1,undefined4 param_2,int param_3,int param_4,undefined8 param_5,
               undefined8 param_6)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x110);
  if ((uVar1 != 0) && ((ulong)uVar1 == *(ulong *)(param_1 + 0x80))) {
    *(uint *)(param_1 + 0x110) = uVar1 - (param_3 + param_4);
  }
  uVar1 = *(uint *)(param_1 + 0x114);
  if ((uVar1 != 0) && ((ulong)uVar1 == *(ulong *)(param_1 + 0x70))) {
    *(uint *)(param_1 + 0x114) = uVar1 - (param_3 + param_4);
  }
  *(undefined4 *)(param_1 + 0x118) = param_2;
  *(int *)(param_1 + 0x11c) = param_3;
  *(int *)(param_1 + 0x120) = param_4;
  *(undefined8 *)(param_1 + 0x38) = param_5;
  *(undefined8 *)(param_1 + 0x40) = param_6;
  return;
}


// ===== 004fc800 libspdm_register_verify_spdm_cert_chain_func =====

void libspdm_register_verify_spdm_cert_chain_func(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x228) = param_2;
  return;
}


// ===== 004fc810 libspdm_get_sizeof_required_scratch_buffer =====

int libspdm_get_sizeof_required_scratch_buffer(long param_1)

{
  if (*(int *)(param_1 + 0x118) != 0) {
    return *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x11c) + *(int *)(param_1 + 0x118) * 2;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",0xa14,
             "context->local_context.capability.max_spdm_msg_size != 0");
  return *(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x11c) + *(int *)(param_1 + 0x118) * 2;
}


// ===== 004fc870 libspdm_set_scratch_buffer =====

void libspdm_set_scratch_buffer(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x118);
  if (iVar1 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa2c,"context->local_context.capability.max_spdm_msg_size != 0");
    iVar1 = *(int *)(param_1 + 0x118);
  }
  iVar2 = *(int *)(param_1 + 0x11c);
  iVar3 = *(int *)(param_1 + 0x120);
  if (param_3 < (uint)(iVar2 + iVar3 + iVar1 * 2)) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa2d,"scratch_buffer_size >= libspdm_get_scratch_buffer_capacity(spdm_context)");
    iVar1 = *(int *)(param_1 + 0x118);
    iVar2 = *(int *)(param_1 + 0x11c);
    iVar3 = *(int *)(param_1 + 0x120);
  }
  *(long *)(param_1 + 0x58) = param_2;
  *(ulong *)(param_1 + 0x60) = param_3;
  *(ulong *)(param_1 + 0x48) = param_2 + (ulong)(uint)(iVar1 + iVar2 + iVar3);
  return;
}


// ===== 004fc920 libspdm_get_scratch_buffer =====

void libspdm_get_scratch_buffer(long param_1,undefined8 *param_2,long *param_3)

{
  long lVar1;
  
  if (*(long *)(param_1 + 0x58) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa48,"context->scratch_buffer != NULL");
  }
  if (*(ulong *)(param_1 + 0x60) <
      (ulong)(uint)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x11c) +
                   *(int *)(param_1 + 0x118) * 2)) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa49,
               "context->scratch_buffer_size >= libspdm_get_scratch_buffer_capacity(spdm_context)");
  }
  *param_2 = *(undefined8 *)(param_1 + 0x58);
  lVar1 = *(long *)(param_1 + 0x60);
  *param_3 = lVar1;
  *param_3 = lVar1 - (ulong)*(uint *)(param_1 + 0x118);
  return;
}


// ===== 004fc9f0 libspdm_acquire_sender_buffer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void libspdm_acquire_sender_buffer(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  
  if (*(long *)(param_1 + 0x68) != 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa61,"spdm_context->sender_buffer == NULL");
  }
  if (*(long *)(param_1 + 0x70) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa62,"spdm_context->sender_buffer_size != 0");
  }
  iVar1 = (**(code **)(param_1 + 0x18))(param_1,param_3);
  if (iVar1 == 0) {
    *(undefined8 *)(param_1 + 0x68) = *param_3;
    *param_2 = *(undefined8 *)(param_1 + 0x70);
  }
  return;
}


// ===== 004fca80 libspdm_release_sender_buffer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void libspdm_release_sender_buffer(long param_1)

{
  if (*(long *)(param_1 + 0x68) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa7b,"spdm_context->sender_buffer != NULL");
  }
  if (*(long *)(param_1 + 0x70) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xa7c,"spdm_context->sender_buffer_size != 0");
  }
  (**(code **)(param_1 + 0x20))(param_1,*(undefined8 *)(param_1 + 0x68));
  *(undefined8 *)(param_1 + 0x68) = 0;
  return;
}


// ===== 004fcb00 libspdm_get_sender_buffer =====

void libspdm_get_sender_buffer(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  *param_2 = *(undefined8 *)(param_1 + 0x68);
  *param_3 = *(undefined8 *)(param_1 + 0x70);
  return;
}


// ===== 004fcb20 libspdm_acquire_receiver_buffer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void libspdm_acquire_receiver_buffer(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  
  if (*(long *)(param_1 + 0x78) != 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xaa1,"spdm_context->receiver_buffer == NULL");
  }
  if (*(long *)(param_1 + 0x80) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xaa2,"spdm_context->receiver_buffer_size != 0");
  }
  iVar1 = (**(code **)(param_1 + 0x28))(param_1,param_3);
  if (iVar1 == 0) {
    *(undefined8 *)(param_1 + 0x78) = *param_3;
    *param_2 = *(undefined8 *)(param_1 + 0x80);
  }
  return;
}


// ===== 004fcbc0 libspdm_release_receiver_buffer =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void libspdm_release_receiver_buffer(long param_1)

{
  if (*(long *)(param_1 + 0x78) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xabb,"spdm_context->receiver_buffer != NULL");
  }
  if (*(long *)(param_1 + 0x80) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xabc,"spdm_context->receiver_buffer_size != 0");
  }
  (**(code **)(param_1 + 0x30))(param_1,*(undefined8 *)(param_1 + 0x78));
  *(undefined8 *)(param_1 + 0x78) = 0;
  return;
}


// ===== 004fcc40 libspdm_init_context =====

undefined8 libspdm_init_context(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0xba8;
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xbd2,"spdm_context != NULL");
    libspdm_secured_message_get_context_size();
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xb78,"spdm_context != NULL");
  }
  else {
    libspdm_secured_message_get_context_size();
    puVar1 = param_1 + 0x2ea;
  }
  libspdm_zero_mem(param_1,0xba8);
  *(undefined4 **)(param_1 + 0x2be) = puVar1;
  *(undefined8 *)((long)param_1 + 0xea) = 0x1300120011001000;
  *(undefined2 *)((long)param_1 + 0x142) = 0x1000;
  *param_1 = 3;
  *(undefined8 *)(param_1 + 0x194) = 0xd2;
  *(undefined8 *)(param_1 + 0x1ce) = 0x1a4;
  *(undefined1 *)(param_1 + 0x3a) = 4;
  *(undefined1 *)(param_1 + 0x50) = 3;
  param_1[0x51] = 0x12001100;
  param_1[0x42] = 100000;
  *(undefined8 *)(param_1 + 0x2c2) = 0;
  *(undefined8 *)(param_1 + 0x2d6) = 0xffffffffffffffff;
  *(undefined8 *)(param_1 + 0x2c6) = 0;
  param_1[0x22] = 0;
  *(undefined1 *)(param_1 + 0x23) = 0;
  *(undefined8 *)(param_1 + 0x14) = 0;
  *(undefined8 *)(param_1 + 0x44) = 0;
  param_1[0x46] = 0;
  libspdm_secured_message_init_context(puVar1);
  return 0;
}


// ===== 004fcd70 libspdm_reset_context =====

void libspdm_reset_context(long param_1)

{
  libspdm_session_info_init(param_1,param_1 + 0x908,0,0);
  *(undefined4 *)(param_1 + 0x238) = 0;
  libspdm_zero_mem(param_1 + 0x23c,2);
  libspdm_zero_mem(param_1 + 0x240,0x30);
  libspdm_zero_mem(param_1 + 0x270,0x18);
  libspdm_zero_mem(param_1 + 0x90,8);
  libspdm_zero_mem(param_1 + 0xa8,0x28);
  *(undefined8 *)(param_1 + 0x640) = 0;
  *(undefined8 *)(param_1 + 0x638) = 0;
  *(undefined2 *)(param_1 + 0x64a) = 0;
  *(undefined1 *)(param_1 + 0xb24) = 0;
  *(undefined8 *)(param_1 + 0xb18) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(undefined8 *)(param_1 + 0xb08) = 0;
  *(undefined8 *)(param_1 + 0xb4c) = 0;
  return;
}


// ===== 004fce60 libspdm_deinit_context =====

void libspdm_deinit_context(long param_1)

{
  long *plVar1;
  char cVar2;
  undefined8 uVar3;
  long *plVar4;
  long *plVar5;
  
  plVar1 = (long *)(param_1 + 0x668);
  cVar2 = *(char *)(param_1 + 0x233);
  plVar4 = (long *)(param_1 + 0x468);
  do {
    if (*plVar4 != 0) {
      plVar5 = plVar4;
      if (cVar2 == '\0') {
        do {
          plVar5 = plVar4;
          plVar4 = plVar5 + 8;
          libspdm_req_asym_free(*(undefined2 *)(param_1 + 0x284));
          *plVar5 = 0;
          if (plVar1 == plVar4) goto LAB_004fcec8;
        } while (*plVar4 != 0);
        plVar4 = plVar5 + 0x10;
        goto joined_r0x004fcec6;
      }
      do {
        plVar4 = plVar5 + 8;
        libspdm_asym_free(*(undefined4 *)(param_1 + 0x278));
        *plVar5 = 0;
        if (plVar1 == plVar4) goto LAB_004fcec8;
        plVar5 = plVar4;
      } while (*plVar4 != 0);
    }
    plVar4 = plVar4 + 8;
joined_r0x004fcec6:
    if (plVar1 == plVar4) {
LAB_004fcec8:
      libspdm_reset_managed_buffer(param_1 + 0x650);
      libspdm_reset_managed_buffer(param_1 + 0x738);
      if (*(long *)(param_1 + 0x8f0) != 0) {
        libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
        *(undefined8 *)(param_1 + 0x8f0) = 0;
      }
      if (*(long *)(param_1 + 0x8f8) != 0) {
        libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
        *(undefined8 *)(param_1 + 0x8f8) = 0;
      }
      if (*(long *)(param_1 + 0xae0) != 0) {
        libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
        *(undefined8 *)(param_1 + 0xae0) = 0;
      }
      libspdm_reset_managed_buffer(param_1 + 0x918);
      if (*(long *)(param_1 + 0xad8) != 0) {
        libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
        *(undefined8 *)(param_1 + 0xad8) = 0;
      }
      if (*(long *)(param_1 + 0xae8) != 0) {
        libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
        *(undefined8 *)(param_1 + 0xae8) = 0;
        if (*(long *)(param_1 + 0xad8) != 0) {
          libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
          uVar3 = *(undefined8 *)(param_1 + 0xae8);
          *(undefined8 *)(param_1 + 0xae8) = 0;
          *(undefined8 *)(param_1 + 0xad8) = uVar3;
        }
      }
      *(undefined1 *)(param_1 + 0xad0) = 0;
      return;
    }
  } while( true );
}


// ===== 004fd040 libspdm_get_context_size =====

long libspdm_get_context_size(void)

{
  long lVar1;
  
  lVar1 = libspdm_secured_message_get_context_size();
  if (lVar1 != 0x430) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data.c",
               0xc56,"size == LIBSPDM_CONTEXT_SIZE_ALL");
  }
  return lVar1 + 0xba8;
}


// ===== 004fd090 libspdm_get_version_from_version_number =====

uint libspdm_get_version_from_version_number(uint param_1)

{
  return param_1 >> 8 & 0xff;
}


// ===== 004fd0a0 libspdm_version_number_sort =====

void libspdm_version_number_sort(undefined8 param_1,ulong param_2)

{
  if (1 < param_2) {
    libspdm_version_number_sort_part_0();
    return;
  }
  return;
}


// ===== 004fd0c0 libspdm_negotiate_connection_version =====

ulong libspdm_negotiate_connection_version
                (undefined2 *param_1,long param_2,ulong param_3,long param_4,ulong param_5)

{
  undefined2 uVar1;
  ulong uVar2;
  bool bVar3;
  ulong uVar4;
  ulong uVar5;
  undefined2 local_4c [5];
  undefined1 local_42;
  char acStack_41 [17];
  
  bVar3 = 4 < param_3 - 1 || 4 < param_5 - 1;
  if (bVar3) {
    return 0;
  }
  uVar5 = CONCAT71((int7)(param_3 >> 8),bVar3) & 0xffffffff;
  if ((param_2 != 0) && (param_4 != 0)) {
    libspdm_zero_mem(local_4c,10);
    libspdm_zero_mem(&local_42,10);
    libspdm_copy_mem(local_4c,10,param_2,param_3 * 2);
    libspdm_copy_mem(&local_42,10,param_4,param_5 * 2);
    if (param_3 != 1) {
      libspdm_version_number_sort_part_0(local_4c,param_3);
    }
    uVar5 = 0;
    if (param_5 != 1) {
      libspdm_version_number_sort_part_0(&local_42);
    }
    uVar4 = 0;
    do {
      uVar2 = 0;
      do {
        uVar1 = local_4c[uVar2];
        if ((char)((ushort)uVar1 >> 8) == acStack_41[uVar4 * 2]) {
          *param_1 = uVar1;
          return 1;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_5);
  }
  return uVar5;
}


// ===== 004fd230 libspdm_session_info_init =====

undefined2 libspdm_session_info_init(long param_1,int *param_2,int param_3,char param_4)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_3 == 0) {
    if (param_4 == '\0') {
      if (*(int *)(param_1 + 0xb4c) != 0) {
        *(int *)(param_1 + 0xb4c) = *(int *)(param_1 + 0xb4c) + -1;
      }
    }
    else if (*(int *)(param_1 + 0xb50) != 0) {
      *(int *)(param_1 + 0xb50) = *(int *)(param_1 + 0xb50) + -1;
    }
  }
  else if (param_4 == '\0') {
    uVar2 = *(uint *)(param_1 + 0xb4c);
    if ((*(uint *)(param_1 + 0xb44) != 0) && (*(uint *)(param_1 + 0xb44) <= uVar2)) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
                 ,0x1d,
                 "(spdm_context->max_dhe_session_count == 0) || (spdm_context->current_dhe_session_count < spdm_context->max_dhe_session_count)"
                );
      uVar2 = *(uint *)(param_1 + 0xb4c);
    }
    *(uint *)(param_1 + 0xb4c) = uVar2 + 1;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xb50);
    if ((*(uint *)(param_1 + 0xb48) != 0) && (*(uint *)(param_1 + 0xb48) <= uVar2)) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
                 ,0x18,
                 "(spdm_context->max_psk_session_count == 0) || (spdm_context->current_psk_session_count < spdm_context->max_psk_session_count)"
                );
      uVar2 = *(uint *)(param_1 + 0xb50);
    }
    *(uint *)(param_1 + 0xb50) = uVar2 + 1;
  }
  uVar2 = *(uint *)(param_1 + 0x254) & *(uint *)(param_1 + 0x10c) & 0xc0;
  if (uVar2 == 0x80) {
    uVar3 = 1;
  }
  else if (uVar2 == 0xc0) {
    uVar3 = 2;
  }
  else {
    uVar3 = 0;
    if (uVar2 != 0) {
      uVar3 = 3;
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
                 ,0x3e,"false");
    }
  }
  if (*(long *)(param_2 + 0x74) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    param_2[0x74] = 0;
    param_2[0x75] = 0;
  }
  if (*(long *)(param_2 + 0x78) != 0) {
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c));
    param_2[0x78] = 0;
    param_2[0x79] = 0;
  }
  libspdm_zero_mem(param_2 + 0x7a,4);
  libspdm_zero_mem(param_2,0x1f0);
  libspdm_secured_message_init_context(*(undefined8 *)(param_2 + 0x7c));
  *param_2 = param_3;
  *(char *)(param_2 + 1) = param_4;
  libspdm_secured_message_set_use_psk(*(undefined8 *)(param_2 + 0x7c),param_4);
  libspdm_secured_message_set_session_type(*(undefined8 *)(param_2 + 0x7c),uVar3);
  if (*(byte *)(param_1 + 0x289) < 0x12) {
    libspdm_secured_message_set_sequence_number_endian
              (*(undefined8 *)(param_2 + 0x7c),*(undefined1 *)(param_1 + 0xb60));
  }
  else {
    libspdm_secured_message_set_sequence_number_endian(*(undefined8 *)(param_2 + 0x7c),0);
  }
  libspdm_secured_message_set_max_spdm_session_sequence_number
            (*(undefined8 *)(param_2 + 0x7c),*(undefined8 *)(param_1 + 0xb58));
  uVar1 = *(undefined2 *)(param_1 + 0x286);
  libspdm_secured_message_set_algorithms
            (*(undefined8 *)(param_2 + 0x7c),*(undefined2 *)(param_1 + 0x23c),
             *(undefined2 *)(param_1 + 0x288),*(undefined4 *)(param_1 + 0x27c),
             *(undefined2 *)(param_1 + 0x280),*(undefined2 *)(param_1 + 0x282));
  param_2[4] = 0x1a4;
  param_2[5] = 0;
  return uVar1;
}


// ===== 004fd4f0 libspdm_get_session_info_via_session_id =====

long libspdm_get_session_info_via_session_id(long param_1,int param_2)

{
  if (param_2 == 0) {
    libspdm_debug_print(0x80000000,"libspdm_get_session_info_via_session_id - Invalid session_id\n")
    ;
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
               ,0x97,"false");
  }
  else {
    if (*(int *)(param_1 + 0x908) == param_2) {
      return param_1 + 0x908;
    }
    libspdm_debug_print(0x80000000,
                        "libspdm_get_session_info_via_session_id - not found session_id\n");
  }
  return 0;
}


// ===== 004fd560 libspdm_get_secured_message_context_via_session_id =====

undefined8 libspdm_get_secured_message_context_via_session_id(long param_1,int param_2)

{
  if (param_2 == 0) {
    libspdm_debug_print(0x80000000,"libspdm_get_session_info_via_session_id - Invalid session_id\n")
    ;
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
               ,0x97,"false");
  }
  else {
    if (param_2 == *(int *)(param_1 + 0x908)) {
      return *(undefined8 *)(param_1 + 0xaf8);
    }
    libspdm_debug_print(0x80000000,
                        "libspdm_get_session_info_via_session_id - not found session_id\n");
  }
  return 0;
}


// ===== 004fd5d0 libspdm_generate_session_id =====

uint libspdm_generate_session_id(ushort param_1,int param_2)

{
  return param_2 << 0x10 | (uint)param_1;
}


// ===== 004fd5e0 libspdm_assign_session_id =====

long libspdm_assign_session_id(long param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    libspdm_debug_print(0x80000000,"libspdm_assign_session_id - Invalid session_id\n");
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
               ,0xee,"false");
  }
  else {
    iVar1 = *(int *)(param_1 + 0x908);
    if (param_2 == iVar1) {
      libspdm_debug_print(0x80000000,"libspdm_assign_session_id - Duplicated session_id\n",iVar1,
                          param_3);
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
                 ,0xf8,"false");
    }
    else {
      if (iVar1 == 0) {
        libspdm_session_info_init(param_1,param_1 + 0x908,param_2);
        *(int *)(param_1 + 0xb18) = param_2;
        return param_1 + 0x908;
      }
      libspdm_debug_print(0x80000000,"libspdm_assign_session_id - MAX session_id\n",iVar1,param_3);
    }
  }
  return 0;
}


// ===== 004fd6c0 libspdm_free_session_id =====

void libspdm_free_session_id(long param_1,int param_2)

{
  if (param_2 == 0) {
    libspdm_debug_print(0x80000000,"libspdm_free_session_id - Invalid session_id\n");
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
               ,0x118,"false");
    return;
  }
  if (*(int *)(param_1 + 0xb18) == param_2) {
    *(undefined4 *)(param_1 + 0xb18) = 0;
  }
  if (param_2 == *(int *)(param_1 + 0x908)) {
    libspdm_session_info_init(param_1,param_1 + 0x908,0,*(undefined1 *)(param_1 + 0x90c));
    return;
  }
  libspdm_debug_print(0x80000000,"libspdm_free_session_id - MAX session_id\n");
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_context_data_session.c"
             ,300,"false");
  return;
}


// ===== 004fd760 libspdm_get_local_cert_chain_buffer =====

undefined8 libspdm_get_local_cert_chain_buffer(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (*(long *)(param_1 + 0x640) == 0) {
    return 0;
  }
  *param_2 = *(undefined8 *)(param_1 + 0x638);
  *param_3 = *(undefined8 *)(param_1 + 0x640);
  return 1;
}


// ===== 004fd7a0 libspdm_get_peer_public_key_buffer =====

undefined8 libspdm_get_peer_public_key_buffer(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (*(long *)(param_1 + 0x220) == 0) {
    return 0;
  }
  *param_2 = *(undefined8 *)(param_1 + 0x218);
  *param_3 = *(undefined8 *)(param_1 + 0x220);
  return 1;
}


// ===== 004fd7e0 libspdm_get_local_public_key_buffer =====

undefined8 libspdm_get_local_public_key_buffer(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (*(long *)(param_1 + 0x220) == 0) {
    return 0;
  }
  *param_2 = *(undefined8 *)(param_1 + 0x1f8);
  *param_3 = *(undefined8 *)(param_1 + 0x200);
  return 1;
}


// ===== 004fd820 libspdm_calculate_l1l2_hash =====

undefined4 libspdm_calculate_l1l2_hash(long param_1,long param_2,ulong *param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  if (param_2 == 0) {
    uVar2 = libspdm_hash_final(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_1 + 0x900),
                               param_4);
  }
  else {
    libspdm_debug_print(0x40,"use message_m in session :\n");
    uVar2 = libspdm_hash_final(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d8),
                               param_4);
  }
  if ((char)uVar2 != '\0') {
    libspdm_debug_print(0x40,"l1l2 hash - ");
    libspdm_internal_dump_data(param_4,(ulong)uVar1);
    libspdm_debug_print(0x40,&DAT_00da65cb);
    *param_3 = (ulong)uVar1;
  }
  return uVar2;
}


// ===== 004fd8f0 libspdm_generate_cert_chain_hash =====

void libspdm_generate_cert_chain_hash(long param_1,ulong param_2,undefined8 param_3)

{
  if (7 < param_2) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service.c",
               0x1fc,"slot_id < SPDM_MAX_SLOT_COUNT");
  }
  libspdm_hash_all(*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_1 + 0x150 + param_2 * 8),
                   *(undefined8 *)(param_1 + 400 + param_2 * 8),param_3);
  return;
}


// ===== 004fd970 libspdm_get_cert_slot_count =====

char libspdm_get_cert_slot_count(long param_1)

{
  long *plVar1;
  char cVar2;
  
  plVar1 = (long *)(param_1 + 0x150);
  cVar2 = '\0';
  do {
    cVar2 = (cVar2 + '\x01') - (*plVar1 == 0);
    plVar1 = plVar1 + 1;
  } while (plVar1 != (long *)(param_1 + 400));
  return cVar2;
}


// ===== 004fd9b0 libspdm_verify_peer_cert_chain_buffer_integrity =====

void libspdm_verify_peer_cert_chain_buffer_integrity
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  if (*(char *)(param_1 + 0x233) != '\0') {
    libspdm_verify_certificate_chain_buffer
              (*(undefined4 *)(param_1 + 0x27c),*(undefined4 *)(param_1 + 0x278),param_2,param_3,0,
               *(byte *)(param_1 + 0x256) >> 2 & 1 ^ 1);
    return;
  }
  libspdm_verify_certificate_chain_buffer
            (*(undefined4 *)(param_1 + 0x27c),*(undefined2 *)(param_1 + 0x284),param_2,param_3,1,0);
  return;
}


// ===== 004fda20 libspdm_verify_peer_cert_chain_buffer_authority =====

undefined8
libspdm_verify_peer_cert_chain_buffer_authority
          (long param_1,long param_2,long param_3,long *param_4,long *param_5)

{
  long lVar1;
  long lVar2;
  char cVar3;
  uint uVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulong uVar7;
  undefined8 local_78;
  undefined8 local_70;
  undefined1 local_68 [56];
  
  lVar1 = *(long *)(param_1 + 0x208);
  lVar2 = *(long *)(param_1 + 0x210);
  uVar4 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  if ((lVar1 == 0) || (lVar2 == 0)) {
LAB_004fdb40:
    libspdm_debug_print(0x40,"!!! verify_peer_cert_chain_buffer - PASS !!!\n");
    uVar5 = 1;
  }
  else {
    uVar7 = (ulong)uVar4;
    cVar3 = libspdm_hash_all(*(undefined4 *)(param_1 + 0x27c),lVar1,lVar2,local_68);
    if (cVar3 == '\0') {
      pcVar6 = "!!! verify_peer_cert_chain_buffer - FAIL (hash calculation) !!!\n";
    }
    else {
      cVar3 = libspdm_consttime_is_mem_equal(param_2 + 4,local_68,uVar7);
      if (cVar3 == '\0') {
        pcVar6 = "!!! verify_peer_cert_chain_buffer - FAIL (all root cert hash mismatch) !!!\n";
      }
      else {
        cVar3 = libspdm_x509_get_cert_from_cert_chain
                          (param_2 + 4 + uVar7,(param_3 + -4) - uVar7,0,&local_78,&local_70);
        if (cVar3 == '\0') {
          pcVar6 = "!!! verify_peer_cert_chain_buffer - FAIL (cert retrieval fail) !!!\n";
        }
        else {
          cVar3 = libspdm_is_root_certificate(local_78,local_70);
          if (cVar3 == '\0') {
            cVar3 = libspdm_x509_verify_cert(local_78,local_70,lVar1,lVar2);
            if (cVar3 != '\0') goto LAB_004fdb12;
            pcVar6 = 
            "!!! verify_peer_cert_chain_buffer - FAIL (received root cert verify failed)!!!\n";
          }
          else {
            cVar3 = libspdm_consttime_is_mem_equal(local_78,lVar1,lVar2);
            if (cVar3 != '\0') {
LAB_004fdb12:
              if (param_4 != (long *)0x0) {
                *param_4 = lVar1;
              }
              if (param_5 != (long *)0x0) {
                *param_5 = lVar2;
              }
              goto LAB_004fdb40;
            }
            pcVar6 = "!!! verify_peer_cert_chain_buffer - FAIL (root cert mismatch) !!!\n";
          }
        }
      }
    }
    libspdm_debug_print(0x80000000,pcVar6);
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 004fdc00 libspdm_get_measurement_summary_hash_size =====

undefined8 libspdm_get_measurement_summary_hash_size(long param_1,undefined1 param_2,char param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = libspdm_is_capabilities_flag_supported(param_1,param_2,0,0x18);
  if ((cVar1 != '\0') && ((param_3 == '\x01' || (param_3 == -1)))) {
    uVar2 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
    return uVar2;
  }
  return 0;
}


// ===== 004fdc50 libspdm_calculate_th_hash_for_exchange =====

char libspdm_calculate_th_hash_for_exchange
               (long param_1,long param_2,ulong *param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  
  uVar2 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  if (*param_3 < (ulong)uVar2) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service_session.c"
               ,0x77,"*th_hash_buffer_size >= hash_size");
  }
  lVar3 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
  cVar1 = '\0';
  if (lVar3 != 0) {
    cVar1 = libspdm_hash_duplicate
                      (*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),lVar3);
    if (cVar1 == '\0') {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar3);
      return '\0';
    }
    cVar1 = libspdm_hash_final(*(undefined4 *)(param_1 + 0x27c),lVar3,param_4);
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar3);
    if (cVar1 != '\0') {
      *param_3 = (ulong)uVar2;
    }
  }
  return cVar1;
}


// ===== 004fdd40 libspdm_calculate_th_hmac_for_exchange_rsp =====

ulong libspdm_calculate_th_hmac_for_exchange_rsp
                (long param_1,long param_2,undefined8 param_3,ulong *param_4,undefined8 param_5)

{
  undefined8 uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined1 local_68 [56];
  
  uVar1 = *(undefined8 *)(param_2 + 0x1f0);
  uVar4 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  uVar7 = (ulong)uVar4;
  if (*param_4 < uVar7) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service_session.c"
               ,0xac,"*th_hmac_buffer_size >= hash_size");
  }
  lVar5 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
  uVar6 = 0;
  if (lVar5 != 0) {
    cVar2 = libspdm_hash_duplicate
                      (*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),lVar5);
    if (cVar2 == '\0') {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar5);
      return 0;
    }
    bVar3 = libspdm_hash_final(*(undefined4 *)(param_1 + 0x27c),lVar5,local_68);
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar5);
    uVar6 = (ulong)bVar3;
    if (bVar3 != 0) {
      uVar6 = libspdm_hmac_all_with_response_finished_key(uVar1,local_68,uVar7,param_5);
      if ((char)uVar6 != '\0') {
        *param_4 = uVar7;
      }
    }
  }
  return uVar6;
}


// ===== 004fde50 libspdm_calculate_th_hash_for_finish =====

char libspdm_calculate_th_hash_for_finish
               (long param_1,long param_2,ulong *param_3,undefined8 param_4)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  
  uVar2 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  if (*param_3 < (ulong)uVar2) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service_session.c"
               ,0x16b,"*th_hash_buffer_size >= hash_size");
  }
  lVar3 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
  cVar1 = '\0';
  if (lVar3 != 0) {
    cVar1 = libspdm_hash_duplicate
                      (*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),lVar3);
    if (cVar1 == '\0') {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar3);
      return '\0';
    }
    cVar1 = libspdm_hash_final(*(undefined4 *)(param_1 + 0x27c),lVar3,param_4);
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar3);
    if (cVar1 != '\0') {
      *param_3 = (ulong)uVar2;
    }
  }
  return cVar1;
}


// ===== 004fdf40 libspdm_calculate_th_hmac_for_finish_rsp =====

ulong libspdm_calculate_th_hmac_for_finish_rsp
                (long param_1,long param_2,ulong *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined1 local_68 [56];
  
  uVar1 = *(undefined8 *)(param_2 + 0x1f0);
  uVar4 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  uVar7 = (ulong)uVar4;
  if (*param_3 < uVar7) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service_session.c"
               ,0x1a1,"*th_hmac_buffer_size >= hash_size");
    lVar5 = *(long *)(param_2 + 0x1d0);
  }
  else {
    lVar5 = *(long *)(param_2 + 0x1d0);
  }
  if (lVar5 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service_session.c"
               ,0x1a2,"session_info->session_transcript.digest_context_th != NULL");
  }
  lVar5 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
  uVar6 = 0;
  if (lVar5 != 0) {
    cVar2 = libspdm_hash_duplicate
                      (*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),lVar5);
    if (cVar2 == '\0') {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar5);
      return 0;
    }
    bVar3 = libspdm_hash_final(*(undefined4 *)(param_1 + 0x27c),lVar5,local_68);
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar5);
    uVar6 = (ulong)bVar3;
    if ((bVar3 != 0) &&
       (uVar6 = libspdm_hmac_all_with_response_finished_key(uVar1,local_68,uVar7,param_4),
       (char)uVar6 != '\0')) {
      *param_3 = uVar7;
    }
  }
  return uVar6;
}


// ===== 004fe090 libspdm_calculate_th_hmac_for_finish_req =====

ulong libspdm_calculate_th_hmac_for_finish_req
                (long param_1,long param_2,ulong *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined1 local_68 [56];
  
  uVar1 = *(undefined8 *)(param_2 + 0x1f0);
  uVar4 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  uVar7 = (ulong)uVar4;
  if (*param_3 < uVar7) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service_session.c"
               ,0x1dc,"*th_hmac_buffer_size >= hash_size");
    lVar5 = *(long *)(param_2 + 0x1d0);
  }
  else {
    lVar5 = *(long *)(param_2 + 0x1d0);
  }
  if (lVar5 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_crypto_service_session.c"
               ,0x1dd,"session_info->session_transcript.digest_context_th != NULL");
  }
  lVar5 = libspdm_hash_new(*(undefined4 *)(param_1 + 0x27c));
  uVar6 = 0;
  if (lVar5 != 0) {
    cVar2 = libspdm_hash_duplicate
                      (*(undefined4 *)(param_1 + 0x27c),*(undefined8 *)(param_2 + 0x1d0),lVar5);
    if (cVar2 == '\0') {
      libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar5);
      return 0;
    }
    bVar3 = libspdm_hash_final(*(undefined4 *)(param_1 + 0x27c),lVar5,local_68);
    libspdm_hash_free(*(undefined4 *)(param_1 + 0x27c),lVar5);
    uVar6 = (ulong)bVar3;
    if ((bVar3 != 0) &&
       (uVar6 = libspdm_hmac_all_with_request_finished_key(uVar1,local_68,uVar7,param_4),
       (char)uVar6 != '\0')) {
      *param_3 = uVar7;
    }
  }
  return uVar6;
}


// ===== 004fe1e0 libspdm_calculate_th1_hash =====

undefined4
libspdm_calculate_th1_hash(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  ulong local_30 [2];
  
  libspdm_debug_print(0x40,"Calc th1 hash ...\n");
  uVar1 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  local_30[0] = (ulong)uVar1;
  uVar2 = libspdm_calculate_th_hash_for_exchange(param_1,param_2,local_30,param_4);
  if ((char)uVar2 != '\0') {
    libspdm_debug_print(0x40,"th1 hash - ");
    libspdm_internal_dump_data(param_4,local_30[0]);
    libspdm_debug_print(0x40,&DAT_00da6932);
  }
  return uVar2;
}


// ===== 004fe280 libspdm_calculate_th2_hash =====

undefined4
libspdm_calculate_th2_hash(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  ulong local_30 [2];
  
  libspdm_debug_print(0x40,"Calc th2 hash ...\n");
  uVar1 = libspdm_get_hash_size(*(undefined4 *)(param_1 + 0x27c));
  local_30[0] = (ulong)uVar1;
  uVar2 = libspdm_calculate_th_hash_for_finish(param_1,param_2,local_30,param_4);
  if ((char)uVar2 != '\0') {
    libspdm_debug_print(0x40,"th2 hash - ");
    libspdm_internal_dump_data(param_4,local_30[0]);
    libspdm_debug_print(0x40,&DAT_00da6932);
  }
  return uVar2;
}


// ===== 004fe320 libspdm_init_msg_log =====

void libspdm_init_msg_log(long param_1,long param_2,long param_3)

{
  if ((param_1 == 0) || (param_2 == 0)) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_msg_log.c",0xe,
               "(spdm_context != NULL) && (msg_buffer != NULL)");
  }
  if (param_3 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_msg_log.c",0xf,
               "msg_buffer_size != 0");
  }
  *(long *)(param_1 + 0xb68) = param_2;
  *(long *)(param_1 + 0xb70) = param_3;
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined4 *)(param_1 + 0xb78) = 0;
  *(undefined4 *)(param_1 + 0xb88) = 0;
  return;
}


// ===== 004fe3c0 libspdm_set_msg_log_mode =====

void libspdm_set_msg_log_mode(long param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0xb78) = param_2;
    return;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_msg_log.c",0x1d,
             "spdm_context != NULL");
  uRam0000000000000b78 = param_2;
  return;
}


// ===== 004fe410 libspdm_get_msg_log_size =====

undefined8 libspdm_get_msg_log_size(long param_1)

{
  if (param_1 != 0) {
    return *(undefined8 *)(param_1 + 0xb80);
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_msg_log.c",0x32,
             "spdm_context != NULL");
  return uRam0000000000000b80;
}


// ===== 004fe460 libspdm_reset_msg_log =====

void libspdm_reset_msg_log(long param_1)

{
  if (param_1 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_msg_log.c",0x3d,
               "spdm_context != NULL");
  }
  *(undefined8 *)(param_1 + 0xb80) = 0;
  *(undefined4 *)(param_1 + 0xb78) = 0;
  *(undefined4 *)(param_1 + 0xb88) = 0;
  return;
}


// ===== 004fe4c0 libspdm_append_msg_log =====

void libspdm_append_msg_log(long param_1,long param_2,long param_3)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_msg_log.c",0x48,
               "(spdm_context != NULL) && (message != NULL)");
  }
  if (((*(byte *)(param_1 + 0xb78) & 1) != 0) && ((*(byte *)(param_1 + 0xb88) & 1) == 0)) {
    lVar4 = *(long *)(param_1 + 0xb80);
    uVar1 = *(ulong *)(param_1 + 0xb70);
    lVar3 = *(long *)(param_1 + 0xb68) + lVar4;
    if (uVar1 < (ulong)(lVar4 + param_3)) {
      libspdm_copy_mem(lVar3,uVar1,param_2,uVar1 - lVar4);
      param_3 = *(long *)(param_1 + 0xb70);
      uVar2 = *(uint *)(param_1 + 0xb88) | 1;
      *(uint *)(param_1 + 0xb88) = uVar2;
      lVar4 = param_3;
    }
    else {
      libspdm_copy_mem(lVar3,uVar1,param_2);
      uVar2 = *(uint *)(param_1 + 0xb88);
      param_3 = param_3 + *(long *)(param_1 + 0xb80);
      lVar4 = *(long *)(param_1 + 0xb70);
    }
    *(long *)(param_1 + 0xb80) = param_3;
    libspdm_debug_print(0x40,
                        "Message Logging Status = [%x] Buffer Size = [%zx] Max Buffer Size = [%zx]\n"
                        ,uVar2,param_3,lVar4);
    libspdm_internal_dump_hex(*(undefined8 *)(param_1 + 0xb68),*(undefined8 *)(param_1 + 0xb80));
    return;
  }
  return;
}


// ===== 004fe5f0 libspdm_get_opaque_data_supported_version_data_size =====

ulong libspdm_get_opaque_data_supported_version_data_size(long param_1)

{
  long lVar1;
  byte bVar2;
  long lVar3;
  
  if (*(char *)(param_1 + 0x140) == '\0') {
    return 0;
  }
  bVar2 = libspdm_get_connection_version();
  lVar1 = (ulong)*(byte *)(param_1 + 0x140) * 2;
  lVar3 = lVar1 + 0xf;
  if (0x11 < bVar2) {
    lVar3 = lVar1 + 0xb;
  }
  return lVar3 + 3U & 0xfffffffffffffffc;
}


// ===== 004fe640 libspdm_get_element_from_opaque_data =====

bool libspdm_get_element_from_opaque_data
               (undefined8 param_1,ulong param_2,int *param_3,byte param_4,byte param_5,
               undefined8 *param_6,ulong *param_7)

{
  byte bVar1;
  ulong uVar2;
  bool bVar3;
  byte *pbVar4;
  ulong uVar5;
  char cVar6;
  char cVar7;
  ulong uVar8;
  
  if ((10 < param_4) ||
     (bVar3 = param_2 == 0 || param_3 == (int *)0x0, param_2 == 0 || param_3 == (int *)0x0)) {
    return false;
  }
  bVar1 = libspdm_get_connection_version();
  if (bVar1 < 0x12) {
    if (param_2 < 8) {
      return bVar3;
    }
    if (*param_3 != 0x444d5446) {
      return bVar3;
    }
    if ((char)param_3[1] != '\x01') {
      return bVar3;
    }
    cVar6 = *(char *)((long)param_3 + 5);
    if (cVar6 == '\0') {
      return bVar3;
    }
    pbVar4 = (byte *)(param_3 + 2);
    uVar8 = param_2 - 8;
  }
  else {
    if (param_2 < 4) {
      return bVar3;
    }
    cVar6 = (char)*param_3;
    if (cVar6 == '\0') {
      return bVar3;
    }
    pbVar4 = (byte *)(param_3 + 1);
    uVar8 = param_2 - 4;
  }
  bVar1 = 0;
  uVar5 = 0;
  cVar7 = '\0';
  while( true ) {
    if (uVar8 < uVar5 + 4) {
      return bVar3;
    }
    if (10 < *pbVar4) {
      return bVar3;
    }
    if (pbVar4[1] != 0) {
      return bVar3;
    }
    uVar2 = (ulong)*(ushort *)(pbVar4 + 2) + 7 & 0xfffffffffffffffc;
    uVar5 = uVar5 + uVar2;
    if (uVar8 < uVar5) break;
    if (*pbVar4 == param_4) {
      if ((byte *)((long)param_3 + param_2) < pbVar4 + 6) {
        return bVar3;
      }
      if ((pbVar4[5] == param_5) && (pbVar4[4] == 1)) {
        *param_6 = pbVar4;
        bVar1 = 1;
        *param_7 = uVar2;
      }
    }
    cVar7 = cVar7 + '\x01';
    pbVar4 = pbVar4 + uVar2;
    if (cVar6 == cVar7) {
      return (bool)(uVar8 == uVar5 & bVar1);
    }
  }
  return bVar3;
}


// ===== 004fe7d0 libspdm_process_general_opaque_data_check =====

ulong libspdm_process_general_opaque_data_check
                (long param_1,ulong param_2,char *param_3,undefined8 param_4,undefined8 param_5)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  ulong uVar4;
  byte *pbVar5;
  ulong uVar6;
  ulong uVar7;
  char cVar8;
  bool bVar9;
  undefined4 local_2c [3];
  
  local_2c[0] = 0;
  if (0x400 < param_2) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_opaque_data.c",0x105
               ,"data_in_size <= SPDM_MAX_OPAQUE_DATA_SIZE");
  }
  bVar2 = libspdm_get_connection_version(param_1);
  if ((0x11 < bVar2) && ((*(byte *)(param_1 + 0x271) & 0xf) == 2)) {
    bVar9 = (param_2 & 3) != 0;
    uVar6 = CONCAT71((int7)((ulong)param_5 >> 8),bVar9 || param_2 < 4);
    if (bVar9 || param_2 < 4) {
LAB_004fe864:
      uVar6 = 0;
      goto LAB_004fe81a;
    }
    cVar1 = *param_3;
    if (cVar1 == '\0') goto LAB_004fe81a;
    pbVar5 = (byte *)(param_3 + 4);
    uVar7 = 0;
    cVar8 = '\0';
    do {
      if ((param_2 - 4 < uVar7 + 4) || (10 < *pbVar5)) goto LAB_004fe81a;
      uVar4 = (ulong)*(ushort *)(pbVar5 + (ulong)pbVar5[1] + 2) + (ulong)pbVar5[1];
      if ((uVar4 & 3) != 0) {
        cVar3 = libspdm_consttime_is_mem_equal
                          (local_2c,pbVar5 + uVar4 + 4,4 - (ulong)((uint)uVar4 & 3));
        uVar6 = uVar6 & 0xff;
        if (cVar3 == '\0') goto LAB_004fe864;
      }
      uVar4 = uVar4 + 7 & 0xfffffffffffffffc;
      uVar7 = uVar7 + uVar4;
      if (param_2 - 4 < uVar7) goto LAB_004fe81a;
      cVar8 = cVar8 + '\x01';
      pbVar5 = pbVar5 + uVar4;
    } while (cVar1 != cVar8);
  }
  uVar6 = 1;
LAB_004fe81a:
  return uVar6 & 0xffffffff;
}


// ===== 004fe940 libspdm_get_code_str =====

char * libspdm_get_code_str(char param_1)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    if ((&code_str_struct_0)[lVar1 * 0x10] == param_1) {
      return (&PTR_s_SPDM_DIGESTS_00da6fc8)[lVar1 * 2];
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 0x2e);
  libspdm_debug_print(0x80000000,"msg code 0x%x not found!!!\n",param_1);
  return "<unknown>";
}


// ===== 004fe9b0 libspdm_internal_dump_hex_str =====

void libspdm_internal_dump_hex_str(undefined1 *param_1,long param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  if (param_2 != 0) {
    puVar1 = param_1 + param_2;
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      libspdm_debug_print(0x40,&DAT_00da6b24,uVar2);
    } while (param_1 != puVar1);
    return;
  }
  return;
}


// ===== 004fea00 libspdm_internal_dump_data =====

void libspdm_internal_dump_data(undefined1 *param_1,long param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  if (param_2 != 0) {
    puVar1 = param_1 + param_2;
    do {
      uVar2 = *param_1;
      param_1 = param_1 + 1;
      libspdm_debug_print(0x40,"%02x ",uVar2);
    } while (param_1 != puVar1);
    return;
  }
  return;
}


// ===== 004fea50 libspdm_internal_dump_hex =====

void libspdm_internal_dump_hex(long param_1,ulong param_2)

{
  undefined1 uVar1;
  ulong uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  long lVar5;
  undefined1 *puVar6;
  
  uVar2 = (ulong)((uint)param_2 & 0x1f);
  param_2 = param_2 >> 5;
  if (param_2 != 0) {
    puVar3 = (undefined1 *)(param_1 + 0x20);
    puVar4 = puVar3 + param_2 * 0x20;
    do {
      puVar6 = puVar3 + -0x20;
      libspdm_debug_print(0x40,"%04zx: ",puVar3 + (-0x20 - param_1));
      do {
        uVar1 = *puVar6;
        puVar6 = puVar6 + 1;
        libspdm_debug_print(0x40,"%02x ",uVar1);
      } while (puVar6 != puVar3);
      puVar3 = puVar3 + 0x20;
      libspdm_debug_print(0x40,&DAT_00da6b37);
    } while (puVar3 != puVar4);
  }
  if (uVar2 != 0) {
    lVar5 = param_2 * 0x20;
    puVar3 = (undefined1 *)(param_1 + lVar5);
    libspdm_debug_print(0x40,"%04zx: ",lVar5);
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      libspdm_debug_print(0x40,"%02x ",uVar1);
    } while ((undefined1 *)(uVar2 + param_1 + lVar5) != puVar3);
    libspdm_debug_print(0x40,&DAT_00da6b37);
    return;
  }
  return;
}


// ===== 004feba0 libspdm_read_uint24 =====

ulong libspdm_read_uint24(uint3 *param_1)

{
  return (ulong)*param_1;
}


// ===== 004febc0 libspdm_write_uint24 =====

void libspdm_write_uint24(undefined2 *param_1,undefined4 param_2)

{
  *param_1 = (short)param_2;
  *(char *)(param_1 + 1) = (char)((uint)param_2 >> 0x10);
  return;
}


// ===== 004febd0 libspdm_read_uint16 =====

undefined2 libspdm_read_uint16(undefined2 *param_1)

{
  return *param_1;
}


// ===== 004febe0 libspdm_write_uint16 =====

void libspdm_write_uint16(undefined2 *param_1,undefined2 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== 004febf0 libspdm_read_uint32 =====

undefined4 libspdm_read_uint32(undefined4 *param_1)

{
  return *param_1;
}


// ===== 004fec00 libspdm_read_uint64 =====

undefined8 libspdm_read_uint64(undefined8 *param_1)

{
  return *param_1;
}


// ===== 004fec10 libspdm_append_managed_buffer =====

undefined8 libspdm_append_managed_buffer(ulong *param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (param_2 == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_support.c",0xf4,
               "buffer != NULL");
  }
  if (param_3 != 0) {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    if (uVar1 < uVar2) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_support.c",0xfd,
                 "managed_buffer->max_buffer_size >= managed_buffer->buffer_size");
      uVar1 = *param_1;
      uVar2 = param_1[1];
      uVar3 = uVar1 - uVar2;
    }
    else {
      uVar3 = uVar1 - uVar2;
    }
    if (uVar3 < param_3) {
      libspdm_debug_print(0x80000000,"libspdm_append_managed_buffer 0x%x fail, rest 0x%x only\n",
                          param_3 & 0xffffffff,(int)uVar1 - (int)uVar2);
      return 0x8001000c;
    }
    libspdm_copy_mem((long)param_1 + uVar2 + 0x10,param_3,param_2,param_3);
    param_1[1] = param_1[1] + param_3;
  }
  return 0;
}


// ===== 004fed00 libspdm_reset_managed_buffer =====

void libspdm_reset_managed_buffer(undefined8 *param_1)

{
  param_1[1] = 0;
  libspdm_zero_mem(param_1 + 2,*param_1);
  return;
}


// ===== 004fed20 libspdm_get_managed_buffer_size =====

undefined8 libspdm_get_managed_buffer_size(long param_1)

{
  return *(undefined8 *)(param_1 + 8);
}


// ===== 004fed30 libspdm_get_managed_buffer =====

long libspdm_get_managed_buffer(long param_1)

{
  return param_1 + 0x10;
}


// ===== 004fed40 libspdm_mask_capability_flags =====

uint libspdm_mask_capability_flags(undefined8 param_1,char param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = libspdm_get_connection_version();
  if (bVar1 == 0x12) {
    uVar2 = param_3 & 0x3ffc6;
    if (param_2 == '\0') {
      uVar2 = param_3 & 0x3fffff;
    }
    return uVar2;
  }
  if (bVar1 < 0x13) {
    if (bVar1 == 0x10) {
      if (param_2 != '\0') {
        return 0;
      }
      return param_3 & 0x3f;
    }
    if (bVar1 == 0x11) {
      uVar2 = param_3 & 0x1ffc6;
      if (param_2 == '\0') {
        uVar2 = param_3 & 0x1ffff;
      }
      return uVar2;
    }
  }
  else if (bVar1 == 0x13) {
    uVar2 = param_3 & 0xec3ffc6;
    if (param_2 == '\0') {
      uVar2 = param_3 & 0x3fffffff;
    }
    return uVar2;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_common_lib/libspdm_com_support.c",0x16d,
             "false");
  return 0;
}


// ===== 004fedf0 libspdm_get_aead_key_size =====

long libspdm_get_aead_key_size(short param_1)

{
  return (ulong)(param_1 == 2) << 5;
}


// ===== 004fee10 libspdm_get_aead_iv_size =====

undefined8 libspdm_get_aead_iv_size(short param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0xc;
  if (param_1 != 2) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 004fee30 libspdm_get_aead_tag_size =====

long libspdm_get_aead_tag_size(short param_1)

{
  return (ulong)(param_1 == 2) << 4;
}


// ===== 004fee50 libspdm_aead_encryption =====

undefined8
libspdm_aead_encryption
          (undefined8 param_1,ushort param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 uVar1;
  
  if (param_2 == 4) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",0x89,
               "false");
  }
  else {
    if (param_2 < 5) {
      if ((ushort)(param_2 - 1) < 2) {
        if (param_2 == 1) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",0x77,
                     "aead_cipher_suite != SPDM_ALGORITHMS_AEAD_CIPHER_SUITE_AES_128_GCM");
        }
        uVar1 = libspdm_aead_aes_gcm_encrypt(param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar1;
      }
    }
    else if (param_2 == 8) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",0x92,
                 "false");
      return 0;
    }
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",0x96,
               "false");
  }
  return 0;
}


// ===== 004fefb0 libspdm_aead_decryption =====

undefined8
libspdm_aead_decryption
          (undefined8 param_1,ushort param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 uVar1;
  
  if (param_2 == 4) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",0xbb,
               "false");
  }
  else {
    if (param_2 < 5) {
      if ((ushort)(param_2 - 1) < 2) {
        if (param_2 == 1) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",0xa9,
                     "aead_cipher_suite != SPDM_ALGORITHMS_AEAD_CIPHER_SUITE_AES_128_GCM");
        }
        uVar1 = libspdm_aead_aes_gcm_decrypt(param_3,param_4,param_5,param_6,param_7,param_8);
        return uVar1;
      }
    }
    else if (param_2 == 8) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",0xc4,
                 "false");
      return 0;
    }
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_aead.c",200,"false"
              );
  }
  return 0;
}


// ===== 004ff110 libspdm_asym_func_need_hash =====

undefined8 libspdm_asym_func_need_hash(uint param_1)

{
  if (param_1 == 0x200) {
    return 0;
  }
  if (param_1 < 0x201) {
    if (param_1 < 0x41) {
      if ((param_1 != 0) && ((0x800000008000808bU >> ((ulong)(param_1 - 1) & 0x3f) & 1) != 0)) {
        return 0x8000000080008001;
      }
    }
    else if ((param_1 - 0x80 & 0xffffff7f) == 0) {
      return 1;
    }
  }
  else if ((param_1 - 0x400 & 0xfffffbff) == 0) {
    return 0;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x20b,"false"
            );
  return 0;
}


// ===== 004ff190 libspdm_asym_get_public_key_from_der_wrap =====

undefined8
libspdm_asym_get_public_key_from_der_wrap
          (uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (param_1 == 0x200) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x1dc,
               "false");
    return 0;
  }
  if (param_1 < 0x201) {
    if (param_1 < 0x41) {
      if (param_1 != 0) {
        if ((0x800000008000008bU >> ((ulong)(param_1 - 1) & 0x3f) & 1) != 0) {
          if (param_1 == 1) {
            pcVar2 = "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSASSA_2048";
            uVar1 = 0x1a2;
          }
          else if (param_1 == 4) {
            pcVar2 = "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSASSA_3072";
            uVar1 = 0x1a5;
          }
          else if (param_1 == 0x20) {
            pcVar2 = "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSASSA_4096";
            uVar1 = 0x1a8;
          }
          else {
            if (param_1 != 2) {
              if (param_1 == 0x40) {
                libspdm_debug_assert
                          ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c"
                           ,0x1b1,
                           "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_4096");
              }
              uVar1 = libspdm_rsa_get_public_key_from_der(param_2,param_3,param_4);
              return uVar1;
            }
            pcVar2 = "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_2048";
            uVar1 = 0x1ab;
          }
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",uVar1
                     ,pcVar2);
          uVar1 = libspdm_rsa_get_public_key_from_der(param_2,param_3,param_4);
          return uVar1;
        }
        if (param_1 == 0x10) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x1bd
                     ,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P256")
          ;
          goto LAB_004ff2e5;
        }
      }
    }
    else if ((param_1 - 0x80 & 0xffffff7f) == 0) {
      if (param_1 == 0x100) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x1c3,
                   "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P521");
      }
LAB_004ff2e5:
      uVar1 = libspdm_ec_get_public_key_from_der(param_2,param_3,param_4);
      return uVar1;
    }
  }
  else if ((param_1 - 0x400 & 0xfffffbff) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x1cf,
               "false");
    return 0;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x1e0,"false"
            );
  return 0;
}


// ===== 004ff3f0 libspdm_create_signing_context =====

void libspdm_create_signing_context(undefined4 param_1,char param_2,char param_3,long param_4)

{
  long lVar1;
  long lVar2;
  byte bVar3;
  char *pcVar4;
  ushort uVar5;
  long lVar6;
  
  uVar5 = (ushort)param_1;
  if (uVar5 < 0x1200) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x8c,
               "(spdm_version >> SPDM_VERSION_NUMBER_SHIFT_BIT) > SPDM_MESSAGE_VERSION_11");
joined_r0x004ff551:
    if ((uVar5 >> 8 & 0xf) < 10) goto LAB_004ff440;
  }
  else if (uVar5 >> 0xc < 10) goto joined_r0x004ff551;
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x8f,
             "(((spdm_version >> 12) & 0xF) < 10) && (((spdm_version >> 8) & 0xF) < 10)");
LAB_004ff440:
  bVar3 = (byte)((uint)param_1 >> 8);
  lVar1 = param_4 + 0x40;
  do {
    libspdm_copy_mem(param_4,0x10,"dmtf-spdm-v1.2.*",0x10);
    lVar6 = param_4 + 0x10;
    *(byte *)(param_4 + 0xb) = (bVar3 >> 4) + 0x30;
    *(byte *)(param_4 + 0xd) = (bVar3 & 0xf) + 0x30;
    *(undefined1 *)(param_4 + 0xf) = 0x2a;
    param_4 = lVar6;
  } while (lVar6 != lVar1);
  pcVar4 = "";
  lVar6 = 0;
  while ((*pcVar4 != param_3 || (pcVar4[1] != param_2))) {
    lVar6 = lVar6 + 1;
    pcVar4 = pcVar4 + 0x20;
    if (lVar6 == 5) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0xab,
                 "false");
      return;
    }
  }
  lVar6 = lVar6 * 0x20;
  lVar2 = *(long *)(&UNK_00da77b8 + lVar6);
  libspdm_zero_mem(lVar1,lVar2);
  libspdm_copy_mem(lVar1 + lVar2,*(undefined8 *)(&UNK_00da77b0 + lVar6),
                   *(undefined8 *)(&UNK_00da77a8 + lVar6),*(undefined8 *)(&UNK_00da77b0 + lVar6));
  return;
}


// ===== 004ff560 libspdm_get_signing_context_string.constprop.0 =====

undefined8
libspdm_get_signing_context_string_constprop_0
          (ushort param_1,char param_2,char param_3,undefined8 *param_4)

{
  char *pcVar1;
  long lVar2;
  
  if (param_1 < 0x1200) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x6d,
               "(spdm_version >> SPDM_VERSION_NUMBER_SHIFT_BIT) > SPDM_MESSAGE_VERSION_11");
  }
  pcVar1 = "";
  lVar2 = 0;
  while ((*pcVar1 != param_3 || (pcVar1[1] != param_2))) {
    lVar2 = lVar2 + 1;
    pcVar1 = pcVar1 + 0x20;
    if (lVar2 == 5) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x76,
                 "false");
      return 0;
    }
  }
  *param_4 = *(undefined8 *)(&UNK_00da77b0 + lVar2 * 0x20);
  return *(undefined8 *)(&UNK_00da77a8 + lVar2 * 0x20);
}


// ===== 004ff610 libspdm_asym_verify_wrap.isra.0 =====

undefined8
libspdm_asym_verify_wrap_isra_0
          (undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (param_3 == 0x80) {
LAB_004ff70a:
    uVar3 = libspdm_ecdsa_verify(param_1,param_2,param_4,param_5,param_6,param_7);
    return uVar3;
  }
  if (param_3 < 0x81) {
    uVar1 = param_3 - 1;
    if (uVar1 < 0x40) {
      uVar2 = 1L << ((byte)uVar1 & 0x3f);
      if ((uVar2 & 0x8000000000000082) != 0) {
        if (param_3 == 2) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x34e
                     ,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_2048");
        }
        else if (param_3 == 0x40) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x354
                     ,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_4096");
        }
        uVar3 = libspdm_rsa_pss_verify(param_1,param_2,param_4,param_5,param_6,param_7);
        return uVar3;
      }
      if ((uVar2 & 0x80000009) != 0) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x346,
                   "false");
        return 0;
      }
      if (uVar1 == 0xf) {
        if (param_3 == 0x10) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x363
                     ,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P256")
          ;
        }
        goto LAB_004ff70a;
      }
    }
  }
  else {
    if (param_3 == 0x200) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x38b,
                 "false");
      return 0;
    }
    if (param_3 < 0x201) {
      if (param_3 == 0x100) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x369,
                   "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P521");
        goto LAB_004ff70a;
      }
    }
    else if ((param_3 - 0x400 & 0xfffffbff) == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x381,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x38f,"false"
            );
  return 0;
}


// ===== 004ff890 libspdm_asym_sign_wrap.isra.0 =====

undefined8
libspdm_asym_sign_wrap_isra_0
          (undefined8 param_1,undefined8 param_2,uint param_3,undefined8 param_4,undefined8 param_5,
          undefined8 param_6,undefined8 param_7)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  if (param_3 == 0x80) {
LAB_004ff98a:
    uVar3 = libspdm_ecdsa_sign(param_1,param_2,param_4,param_5,param_6,param_7);
    return uVar3;
  }
  if (param_3 < 0x81) {
    uVar1 = param_3 - 1;
    if (uVar1 < 0x40) {
      uVar2 = 1L << ((byte)uVar1 & 0x3f);
      if ((uVar2 & 0x8000000000000082) != 0) {
        if (param_3 == 2) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x11e
                     ,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_2048");
        }
        else if (param_3 == 0x40) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x124
                     ,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_4096");
        }
        uVar3 = libspdm_rsa_pss_sign(param_1,param_2,param_4,param_5,param_6,param_7);
        return uVar3;
      }
      if ((uVar2 & 0x80000009) != 0) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x116,
                   "false");
        return 0;
      }
      if (uVar1 == 0xf) {
        if (param_3 == 0x10) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x133
                     ,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P256")
          ;
        }
        goto LAB_004ff98a;
      }
    }
  }
  else {
    if (param_3 == 0x200) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x15b,
                 "false");
      return 0;
    }
    if (param_3 < 0x201) {
      if (param_3 == 0x100) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x139,
                   "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P521");
        goto LAB_004ff98a;
      }
    }
    else if ((param_3 - 0x400 & 0xfffffbff) == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x151,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x15f,"false"
            );
  return 0;
}


// ===== 004ffb10 libspdm_get_asym_signature_size =====

undefined8 libspdm_get_asym_signature_size(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x180;
  if ((param_1 != 8) && (uVar1 = 0x60, param_1 != 0x80)) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 004ffb40 libspdm_asym_free =====

void libspdm_asym_free(uint param_1,long param_2)

{
  if (param_2 == 0) {
    return;
  }
  if (param_1 == 0x200) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x18b,
               "false");
    return;
  }
  if (param_1 < 0x201) {
    if (param_1 < 0x41) {
      if (param_1 != 0) {
        if ((0x800000008000008bU >> ((ulong)(param_1 - 1) & 0x3f) & 1) != 0) {
          libspdm_rsa_free(param_2);
          return;
        }
        if (param_1 == 0x10) goto LAB_004ffbd5;
      }
    }
    else if ((param_1 - 0x80 & 0xffffff7f) == 0) {
LAB_004ffbd5:
      libspdm_ec_free(param_2);
      return;
    }
  }
  else if ((param_1 - 0x400 & 0xfffffbff) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x184,
               "false");
    return;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",399,"false");
  return;
}


// ===== 004ffc10 libspdm_asym_get_public_key_from_der =====

void libspdm_asym_get_public_key_from_der(void)

{
  libspdm_asym_get_public_key_from_der_wrap();
  return;
}


// ===== 004ffc20 libspdm_copy_signature_swap_endian =====

void libspdm_copy_signature_swap_endian
               (ulong param_1,undefined1 *param_2,ulong param_3,undefined1 *param_4,ulong param_5)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  ulong uVar6;
  
  if ((param_1 & 0x6f) != 0) {
    if (param_2 == param_4) {
      if (param_3 != param_5) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x228,
                   "dst_size == src_size");
      }
      if (param_3 >> 1 == 0) {
        return;
      }
      puVar2 = param_2 + (param_3 - 1);
      puVar3 = param_2;
      do {
        uVar1 = *puVar3;
        puVar5 = puVar3 + 1;
        *puVar3 = *puVar2;
        *puVar2 = uVar1;
        puVar2 = puVar2 + -1;
        puVar3 = puVar5;
      } while (param_2 + (param_3 >> 1) != puVar5);
      return;
    }
    if (param_3 < param_5) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x236,
                 "dst_size >= src_size");
      if (param_4 < param_2) {
        if (param_4 + param_5 <= param_2) goto LAB_004ffd4c;
      }
      else if (param_2 + param_3 <= param_4) goto LAB_004ffd4c;
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x237,
                 "(src < dst && src + src_size <= dst) || (dst < src && dst + dst_size <= src)");
      goto LAB_004ffd4c;
    }
    if (param_4 < param_2) {
      if (param_2 < param_4 + param_5) goto LAB_004ffe6d;
    }
    else if (param_4 < param_2 + param_3) {
LAB_004ffe6d:
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x237,
                 "(src < dst && src + src_size <= dst) || (dst < src && dst + dst_size <= src)");
    }
    if (param_5 == 0) {
      return;
    }
LAB_004ffd4c:
    puVar2 = param_4 + (param_5 - 1);
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + -1;
      *param_2 = uVar1;
      param_2 = param_2 + 1;
    } while (param_4 + -1 != puVar2);
    return;
  }
  if ((param_1 & 400) == 0) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x2b0,
               &DAT_00da7665);
    return;
  }
  if (param_2 == param_4) {
    if (param_3 != param_5) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",599,
                 "dst_size == src_size");
    }
    uVar6 = param_3 >> 2;
    if (uVar6 == 0) {
      return;
    }
    param_3 = param_3 >> 1;
    puVar2 = param_2 + param_3;
    puVar3 = param_2 + (param_3 - 1);
    puVar5 = param_2;
    do {
      uVar1 = *puVar5;
      puVar4 = puVar5 + 1;
      *puVar5 = *puVar3;
      *puVar3 = uVar1;
      puVar3 = puVar3 + -1;
      puVar5 = puVar4;
    } while (puVar4 != param_2 + uVar6);
    puVar3 = puVar2;
    puVar5 = puVar2 + (param_3 - 1);
    do {
      uVar1 = *puVar3;
      puVar4 = puVar3 + 1;
      *puVar3 = *puVar5;
      *puVar5 = uVar1;
      puVar3 = puVar4;
      puVar5 = puVar5 + -1;
    } while (puVar4 != puVar2 + uVar6);
    return;
  }
  if (param_3 < param_5) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x276,
               "dst_size >= src_size");
    if (param_4 < param_2) goto LAB_004ffdc1;
LAB_004ffc66:
    if (param_2 + param_3 <= param_4) goto LAB_004ffc9e;
  }
  else {
    if (param_2 <= param_4) goto LAB_004ffc66;
LAB_004ffdc1:
    if (param_4 + param_5 <= param_2) goto LAB_004ffc9e;
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x277,
             "(src < dst && src + src_size <= dst) || (dst < src && dst + dst_size <= src)");
LAB_004ffc9e:
  param_5 = param_5 >> 1;
  if (param_5 != 0) {
    puVar2 = param_4 + (param_5 - 1);
    puVar3 = param_2;
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + -1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    } while (puVar2 != param_4 + -1);
    puVar2 = param_4 + param_5 * 2 + -1;
    puVar3 = param_2 + param_5;
    do {
      uVar1 = *puVar2;
      puVar2 = puVar2 + -1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
    } while (puVar2 != param_4 + (param_5 - 1));
  }
  return;
}


// ===== 00500000 libspdm_is_signature_buffer_palindrome =====

undefined8 libspdm_is_signature_buffer_palindrome(ulong param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  
  if ((param_1 & 0x6f) == 0) {
    if ((param_1 & 400) == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x2e9,
                 &DAT_00da7665);
      return 0;
    }
    uVar3 = (param_3 >> 1) - 1;
    if (uVar3 != 0) {
      uVar1 = 0;
      uVar2 = uVar3;
      do {
        if (*(char *)(param_2 + uVar1) != *(char *)(param_2 + uVar2)) {
          return 0;
        }
        uVar1 = uVar1 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar1 < uVar2);
      param_2 = param_2 + (param_3 >> 1);
      uVar2 = 0;
      do {
        if (*(char *)(param_2 + uVar2) != *(char *)(param_2 + uVar3)) {
          return 0;
        }
        uVar2 = uVar2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar2 < uVar3);
    }
  }
  else {
    param_3 = param_3 - 1;
    if (param_3 != 0) {
      uVar3 = 0;
      do {
        if (*(char *)(param_2 + uVar3) != *(char *)(param_2 + param_3)) {
          return 0;
        }
        uVar3 = uVar3 + 1;
        param_3 = param_3 - 1;
      } while (uVar3 < param_3);
    }
  }
  return 1;
}


// ===== 00500100 libspdm_asym_verify_hash_ex =====

uint libspdm_asym_verify_hash_ex
               (ushort param_1,undefined1 param_2,int param_3,undefined4 param_4,undefined8 param_5,
               undefined8 param_6,ulong param_7,undefined8 param_8,undefined8 param_9,byte *param_10
               )

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined1 *puVar7;
  byte bVar8;
  ulong uVar9;
  undefined1 local_1f0 [8];
  undefined1 local_1e8 [48];
  undefined1 local_1b8 [100];
  undefined1 local_154 [292];
  
  uVar6 = libspdm_get_hash_nid(param_4);
  uVar3 = libspdm_asym_func_need_hash(param_3);
  uVar4 = libspdm_get_hash_size(param_4);
  if (uVar4 != param_7) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x435,
               "hash_size == libspdm_get_hash_size(base_hash_algo)");
  }
  if (param_1 < 0x1200) {
    if ((char)uVar3 == '\0') {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x498,
                 "false");
      return uVar3;
    }
    bVar1 = *param_10;
    bVar8 = bVar1 - 1;
    if ((bVar1 & 0xfd) == 0) {
      uVar4 = libspdm_asym_verify_wrap_isra_0(param_5,uVar6,param_3,param_6,param_7,param_8,param_9)
      ;
      bVar2 = ((byte)uVar4 ^ 1) & bVar8 < 2;
      uVar3 = (uint)bVar2;
      if (bVar2 == 0) goto LAB_0050028b;
    }
    else if (1 < bVar8) {
      return 0;
    }
    libspdm_copy_signature_swap_endian(param_3,local_1b8,0x180,param_8,param_9);
    uVar3 = libspdm_asym_verify_wrap_isra_0(param_5,uVar6,param_3,param_6,param_7,local_1b8,param_9)
    ;
    uVar4 = uVar3;
LAB_0050028b:
    if ((bVar1 & 0xfd) != 0) {
      return uVar4;
    }
    if (bVar8 >= 2) {
      return uVar4;
    }
    if ((char)uVar4 == '\0') {
      return uVar4;
    }
    uVar5 = libspdm_is_signature_buffer_palindrome(param_3,param_8,param_9);
    if ((char)uVar5 != '\0') {
      return uVar5;
    }
    if ((char)uVar3 != '\0') {
      *param_10 = 1;
      return uVar3 & 0xff;
    }
    *param_10 = 0;
    return uVar4;
  }
  if (param_3 != 0x400) {
    if (param_3 != 0x800) goto LAB_005001a0;
    libspdm_get_signing_context_string_constprop_0(param_1,param_2,0,local_1f0);
  }
  uVar6 = 0;
LAB_005001a0:
  libspdm_create_signing_context(param_1,param_2,0,local_1b8);
  libspdm_copy_mem(local_154,0x30,param_6,param_7);
  uVar9 = param_7 + 100;
  if ((char)uVar3 == '\0') {
    puVar7 = local_1b8;
  }
  else {
    uVar3 = libspdm_hash_all(param_4,local_1b8,uVar9,local_1e8);
    if ((char)uVar3 == '\0') {
      return uVar3;
    }
    puVar7 = local_1e8;
    uVar9 = param_7;
  }
  uVar3 = libspdm_asym_verify_wrap_isra_0(param_5,uVar6,param_3,puVar7,uVar9,param_8,param_9);
  return uVar3;
}


// ===== 005003e0 libspdm_get_req_asym_signature_size =====

undefined8 libspdm_get_req_asym_signature_size(short param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x180;
  if ((param_1 != 8) && (uVar1 = 0x60, param_1 != 0x80)) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00500410 libspdm_req_asym_free =====

void libspdm_req_asym_free(undefined2 param_1)

{
  libspdm_asym_free(param_1);
  return;
}


// ===== 00500420 libspdm_req_asym_sign_hash =====

ulong libspdm_req_asym_sign_hash
                (ushort param_1,undefined1 param_2,short param_3,undefined4 param_4,
                undefined8 param_5,undefined8 param_6,ulong param_7,undefined8 param_8,
                undefined8 param_9)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 *puVar4;
  undefined8 local_118;
  undefined1 local_108 [12];
  undefined1 local_fc [48];
  undefined1 local_cc [100];
  undefined1 local_68 [56];
  
  local_118 = libspdm_get_hash_nid(param_4);
  uVar1 = libspdm_asym_func_need_hash(param_3);
  uVar2 = libspdm_get_hash_size(param_4);
  if (uVar2 != param_7) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x6f4,
               "hash_size == libspdm_get_hash_size(base_hash_algo)");
  }
  if (param_1 < 0x1200) {
    if ((char)uVar1 == '\0') {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_asym.c",0x732,
                 "false");
      return (ulong)uVar1;
    }
    uVar3 = libspdm_asym_sign_wrap_isra_0(param_5,local_118,param_3,param_6,param_7,param_8);
    return uVar3;
  }
  if (param_3 != 0x400) {
    if (param_3 != 0x800) goto LAB_005004f0;
    libspdm_get_signing_context_string_constprop_0(param_1,param_2,1,local_108);
  }
  local_118 = 0;
LAB_005004f0:
  libspdm_create_signing_context(param_1,param_2,1,local_cc);
  libspdm_copy_mem(local_68,0x30,param_6,param_7);
  uVar3 = param_7 + 100;
  if ((char)uVar1 == '\0') {
    puVar4 = local_cc;
  }
  else {
    uVar1 = libspdm_hash_all(param_4,local_cc,uVar3,local_fc);
    if ((char)uVar1 == '\0') {
      return (ulong)uVar1;
    }
    puVar4 = local_fc;
    uVar3 = param_7;
  }
  uVar1 = libspdm_asym_sign_wrap_isra_0(param_5,local_118,param_3,puVar4,uVar3,param_8,param_9);
  return (ulong)uVar1;
}


// ===== 00500670 libspdm_get_asym_get_public_key_from_x509 =====

code * libspdm_get_asym_get_public_key_from_x509(uint param_1)

{
  if (param_1 == 0x200) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",0xc2,
               "false");
  }
  else {
    if (param_1 < 0x201) {
      if (param_1 < 0x41) {
        if (param_1 != 0) {
          if ((0x800000008000008bU >> ((ulong)(param_1 - 1) & 0x3f) & 1) != 0) {
            if (param_1 == 1) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",
                         0x88,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSASSA_2048")
              ;
            }
            else if (param_1 == 4) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",
                         0x8b,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSASSA_3072")
              ;
            }
            else if (param_1 == 0x20) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",
                         0x8e,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSASSA_4096")
              ;
            }
            else if (param_1 == 2) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",
                         0x91,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_2048")
              ;
            }
            else if (param_1 == 0x40) {
              libspdm_debug_assert
                        ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",
                         0x97,"base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_RSAPSS_4096")
              ;
            }
            return libspdm_rsa_get_public_key_from_x509;
          }
          if (param_1 == 0x10) {
            libspdm_debug_assert
                      ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",
                       0xa3,
                       "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P256"
                      );
            return libspdm_ec_get_public_key_from_x509;
          }
        }
      }
      else if ((param_1 - 0x80 & 0xffffff7f) == 0) {
        if (param_1 == 0x100) {
          libspdm_debug_assert
                    ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",0xa9,
                     "base_asym_algo!= SPDM_ALGORITHMS_BASE_ASYM_ALGO_TPM_ALG_ECDSA_ECC_NIST_P521");
        }
        return libspdm_ec_get_public_key_from_x509;
      }
    }
    else if ((param_1 - 0x400 & 0xfffffbff) == 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",0xbb,
                 "false");
      return (code *)0x0;
    }
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",0xc6,
               "false");
  }
  return (code *)0x0;
}


// ===== 00500840 libspdm_get_public_key_algo_OID_len =====

undefined4 libspdm_get_public_key_algo_OID_len(uint param_1)

{
  if (param_1 < 0x41) {
    if (param_1 != 0) {
      if ((0x800000008000800bU >> ((ulong)(param_1 - 1) & 0x3f) & 1) != 0) {
        return 0;
      }
      if (param_1 == 8) {
        return 4;
      }
    }
  }
  else {
    if (param_1 == 0x80) {
      return 5;
    }
    if (0x7f < param_1) {
      if ((param_1 - 0x400 & 0xfffffbff) == 0) {
        return 0;
      }
      if (param_1 == 0x100) {
        return 0;
      }
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c",400,"false");
  return 0;
}


// ===== 005008d0 libspdm_verify_leaf_cert_basic_constraints =====

ulong libspdm_verify_leaf_cert_basic_constraints(undefined8 param_1,undefined8 param_2,uint param_3)

{
  ulong uVar1;
  undefined2 local_37;
  undefined4 local_35;
  undefined1 local_31;
  long local_30;
  undefined1 local_22 [18];
  
  local_37 = 0x30;
  local_35 = 0x1010330;
  local_31 = 0;
  local_30 = 10;
  uVar1 = libspdm_x509_get_extended_basic_constraints(param_1,param_2,local_22,&local_30);
  if ((char)uVar1 != '\0') {
    if (local_30 == 0) {
      return (ulong)(param_3 ^ 1);
    }
    if (((local_30 != 2) ||
        (uVar1 = libspdm_consttime_is_mem_equal(local_22,&local_37), (char)uVar1 == '\0')) &&
       (uVar1 = 0, local_30 == 5)) {
      uVar1 = libspdm_consttime_is_mem_equal(local_22,&local_35);
    }
  }
  return uVar1;
}


// ===== 00500970 libspdm_x509_common_certificate_check.part.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Type propagation algorithm not settling */

uint libspdm_x509_common_certificate_check_part_0
               (long param_1,long param_2,uint param_3,byte param_4,char param_5,byte param_6)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  code *pcVar8;
  byte bVar9;
  byte bVar10;
  ulong uVar11;
  ulong *puVar12;
  ulong *puVar13;
  uint uVar14;
  undefined4 *local_280;
  ulong *local_278;
  ulong *local_270;
  byte local_25b;
  long local_250 [7];
  ulong *local_218;
  long local_210;
  long local_208;
  undefined2 local_200;
  ulong local_1f8 [8];
  undefined4 local_1b8;
  undefined1 local_1b4;
  undefined8 local_178;
  undefined2 local_170;
  ulong local_138 [33];
  
  local_250[4] = 0;
  local_250[0] = 0x40;
  local_250[1] = 0x40;
  local_250[3] = 0;
  uVar5 = libspdm_x509_get_version(param_1,param_2,local_250 + 3);
  cVar3 = (char)uVar5;
  if (cVar3 == '\0') goto LAB_005009e9;
  if (local_250[3] == 2) {
    local_250[2] = 0;
    libspdm_x509_get_serial_number(param_1,param_2,0,local_250 + 2);
    if (local_250[2] != 0) {
      local_250[5] = 0;
      cVar1 = libspdm_x509_get_signature_algorithm(param_1,param_2,0,local_250 + 5);
      if (cVar1 == '\0') {
        if (local_250[5] != 0) goto LAB_00500dce;
      }
      else {
        if (local_250[5] == 0) {
          if (param_5 != '\x03') goto LAB_005009e6;
LAB_00500a7b:
          local_25b = param_6 ^ 1;
          libspdm_zero_mem(&local_178,10);
          libspdm_zero_mem(local_138,10);
          cVar1 = cVar3;
          if (param_3 != 0x200) {
            uVar5 = libspdm_get_public_key_algo_OID_len(param_3);
            if ((uVar5 != 0) && (iVar6 = libspdm_get_public_key_algo_OID_len(param_3), iVar6 != 0))
            {
              if (param_3 < 0x41) {
                if (param_3 != 0) {
                  uVar11 = 1L << ((char)param_3 - 1U & 0x3f);
                  if ((uVar11 & 0x8000000080008003) != 0) goto LAB_005009e6;
                  if ((uVar11 & 0x88) != 0) {
                    local_1f8[0] = CONCAT44(local_1f8[0]._4_4_,0x81018202);
                    local_1b8 = 0x80018202;
                    libspdm_copy_mem(&local_178,iVar6,local_1f8,iVar6);
                    libspdm_copy_mem(local_138,iVar6,&local_1b8,iVar6);
                    goto LAB_00500b85;
                  }
                }
LAB_00501491:
                libspdm_debug_assert
                          ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_cert.c"
                           ,0x205,"false");
              }
              else if (param_3 == 0x80) {
                local_1b8 = 0x4812b;
                local_1b4 = 0x22;
                libspdm_copy_mem(&local_178,iVar6,&local_1b8,iVar6);
LAB_00500b85:
                local_278 = local_1f8;
                local_280 = &local_1b8;
                lVar7 = (int)param_2 + param_1;
                local_1f8[0] = 0;
                local_208 = param_1;
                cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,0x30);
                if ((cVar1 != '\0') &&
                   (cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,0x30), cVar1 != '\0')) {
                  lVar7 = local_1f8[0] + local_208;
                  cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,0xa0);
                  if (cVar1 != '\0') {
                    local_208 = local_208 + local_1f8[0];
                    cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,2);
                    if (cVar1 != '\0') {
                      cVar1 = '\x05';
                      do {
                        local_208 = local_208 + local_1f8[0];
                        cVar2 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,0x30);
                        if (cVar2 == '\0') goto LAB_005009e6;
                        cVar1 = cVar1 + -1;
                      } while (cVar1 != '\0');
                      uVar11 = (ulong)uVar5;
                      if (param_3 == 0x80) {
                        cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,0x30);
                        if ((cVar1 != '\0') &&
                           (cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,6),
                           cVar1 != '\0')) {
                          local_208 = local_208 + local_1f8[0];
                          cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,6);
                          if ((cVar1 != '\0') && (uVar11 == local_1f8[0])) {
                            libspdm_copy_mem(local_280,uVar11,local_208,uVar11);
LAB_00500d62:
                            cVar1 = libspdm_consttime_is_mem_equal(local_280,&local_178,uVar11);
                            if ((cVar1 != '\0') ||
                               (cVar2 = libspdm_consttime_is_mem_equal(local_280,local_138,uVar11),
                               cVar1 = cVar3, cVar2 != '\0')) goto LAB_00500df3;
                          }
                        }
                      }
                      else {
                        cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,0x30);
                        if (cVar1 != '\0') {
                          local_208 = local_208 + local_1f8[0];
                          cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,3);
                          if (cVar1 != '\0') {
                            local_208 = local_208 + 1;
                            cVar1 = libspdm_asn1_get_tag(&local_208,lVar7,local_278,0x30);
                            if (cVar1 != '\0') {
                              libspdm_copy_mem(local_280,uVar11,local_208,uVar11);
                              goto LAB_00500d62;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              else if ((param_3 < 0x80) ||
                      (((param_3 - 0x400 & 0xfffffbff) != 0 && (param_3 != 0x100))))
              goto LAB_00501491;
            }
            goto LAB_005009e6;
          }
        }
        else {
LAB_00500dce:
          if (param_6 != 1 || param_5 != '\x02') goto LAB_00500a7b;
          local_25b = 0;
          cVar1 = '\0';
        }
LAB_00500df3:
        local_250[2] = 0;
        uVar5 = libspdm_x509_get_issuer_name(param_1,param_2,0,local_250 + 2);
        if ((char)uVar5 == '\0') {
          if (local_250[2] == 0) goto LAB_005009e9;
        }
        else if ((local_250[2] == 0) && (param_5 != '\x03')) goto LAB_005009e6;
        local_250[2] = 0;
        uVar5 = libspdm_x509_get_subject_name(param_1,param_2,0,local_250 + 2);
        if ((char)uVar5 == '\0') {
          if (local_250[2] == 0) goto LAB_005009e9;
        }
        else if ((local_250[2] == 0) && (param_5 != '\x03')) goto LAB_005009e6;
        uVar5 = libspdm_x509_get_validity
                          (param_1,param_2,local_1f8,local_250,&local_1b8,local_250 + 1);
        if ((char)uVar5 == '\0') {
          if (local_250[0] == 0) goto LAB_005009e9;
LAB_00500edc:
          local_210 = 0x40;
          local_208 = 0x40;
          cVar3 = libspdm_x509_set_date_time("19700101000000Z",&local_178,&local_210);
          if ((((cVar3 == '\0') ||
               (cVar3 = libspdm_x509_set_date_time("99991231235959Z",local_138,&local_208),
               cVar3 == '\0')) ||
              (iVar6 = libspdm_x509_compare_date_time(local_1f8,&local_178), iVar6 < 0)) ||
             (iVar6 = libspdm_x509_compare_date_time(local_138,&local_1b8), iVar6 < 0))
          goto LAB_005009e6;
        }
        else {
          if (param_5 != '\x03') {
            if (local_250[0] == 0) goto LAB_005009e6;
            goto LAB_00500edc;
          }
          if (local_250[0] != 0) goto LAB_00500edc;
        }
        pcVar8 = (code *)libspdm_get_asym_get_public_key_from_x509(param_3);
        if (pcVar8 != (code *)0x0) {
          uVar5 = (*pcVar8)(param_1,param_2,local_250 + 4);
          if ((char)uVar5 == '\0') goto LAB_005009e9;
          if (cVar1 == '\0') goto LAB_00500fb5;
          local_138[0] = 0;
          cVar3 = libspdm_x509_get_key_usage(param_1,param_2,local_138);
          if (cVar3 != '\0') {
            if (local_138[0] == 0) {
              if (param_5 == '\x03') {
LAB_00500fb5:
                local_270 = local_138;
                local_200 = 0x412;
                local_208 = -0x7de37cfefbfef9d5;
                local_178 = 0x821c83010401062b;
                local_170 = 0x312;
                local_250[6] = 0x100;
                uVar5 = libspdm_x509_get_extended_key_usage(param_1,param_2,local_270,local_250 + 6)
                ;
                if ((char)uVar5 != '\0') {
                  if (local_250[6] == 0) {
LAB_00501247:
                    if ((param_5 == '\x01') || (local_25b != 0)) {
                      local_208 = -0x7de37cfefbfef9d5;
                      local_178 = 0x821c83010401062b;
                      uVar5 = 0;
                      local_200 = 0x612;
                      local_170 = 0x212;
                      local_250[6] = 0x1e;
                      if (((param_1 != 0 && param_2 != 0) &&
                          (uVar5 = libspdm_x509_get_extension_data
                                             (param_1,param_2,&local_208,10,local_270,local_250 + 6)
                          , (char)uVar5 != '\0')) && (local_250[6] != 0)) {
                        local_210 = 0;
                        local_218 = local_270;
                        uVar5 = libspdm_asn1_get_tag
                                          (&local_218,(long)local_270 + local_250[6],&local_210,0x30
                                          );
                        if ((char)uVar5 != '\0') {
                          puVar13 = (ulong *)((long)local_270 + local_250[6]);
                          uVar14 = 0;
                          if (local_218 < puVar13) {
                            do {
                              uVar5 = libspdm_asn1_get_tag(&local_218,puVar13,&local_210,0x30);
                              lVar7 = local_210;
                              puVar12 = local_218;
                              if (((char)uVar5 == '\0') ||
                                 (uVar5 = libspdm_asn1_get_tag
                                                    (&local_218,(long)local_270 + local_250[6],
                                                     &local_210,6), (char)uVar5 == '\0'))
                              goto LAB_005009e9;
                              puVar12 = (ulong *)((long)puVar12 + lVar7);
                              if (local_210 == 10) {
                                uVar5 = libspdm_consttime_is_mem_equal(local_218,&local_178,10);
                                uVar14 = uVar14 | uVar5;
                              }
                              puVar13 = (ulong *)((long)local_270 + local_250[6]);
                              local_218 = puVar12;
                            } while (puVar12 < puVar13);
                          }
                          uVar5 = 0;
                          if ((puVar13 == local_218) && (uVar5 = (uint)param_4, param_4 == 0)) {
                            uVar5 = param_5 == '\x02' & uVar14 ^ 1;
                          }
                        }
                      }
                    }
                    goto LAB_005009e9;
                  }
                  local_218 = local_270;
                  local_210 = 0;
                  cVar3 = libspdm_asn1_get_tag(&local_218,(long)local_270 + local_250[6],&local_210)
                  ;
                  if (cVar3 != '\0') {
                    puVar13 = (ulong *)(local_250[6] + (long)local_270);
                    if (local_218 < puVar13) {
                      bVar10 = 0;
                      bVar9 = 0;
                      do {
                        cVar3 = libspdm_asn1_get_tag(&local_218,puVar13,&local_210,6);
                        if (cVar3 == '\0') goto LAB_005009e6;
                        if (local_210 == 10) {
                          bVar4 = libspdm_consttime_is_mem_equal(local_218,&local_208,10);
                          bVar10 = bVar10 | bVar4;
                          if (local_210 == 10) {
                            bVar4 = libspdm_consttime_is_mem_equal(local_218,&local_178,10);
                            bVar9 = bVar9 | bVar4;
                          }
                        }
                        local_218 = (ulong *)(local_210 + (long)local_218);
                        puVar13 = (ulong *)(local_250[6] + (long)local_270);
                      } while (local_218 < puVar13);
                      uVar5 = uVar5 & 0xff;
                    }
                    else {
                      bVar9 = 0;
                      bVar10 = 0;
                    }
                    if (puVar13 == local_218) {
                      bVar4 = bVar10;
                      if (param_4 != 0) {
                        bVar4 = bVar9;
                        bVar9 = bVar10;
                      }
                      if ((bVar9 == 1) || (bVar4 == 0)) goto LAB_00501247;
                    }
                  }
                }
              }
            }
            else if ((local_138[0] & 0x80) != 0) goto LAB_00500fb5;
          }
        }
      }
    }
  }
LAB_005009e6:
  uVar5 = 0;
LAB_005009e9:
  libspdm_asym_free(param_3,local_250[4]);
  return uVar5;
}


// ===== 005015d0 libspdm_is_root_certificate =====

undefined8 libspdm_is_root_certificate(long param_1,long param_2)

{
  undefined8 uVar1;
  long local_e0;
  long local_d8;
  undefined1 local_d0 [100];
  undefined1 local_6c [100];
  
  if (param_1 == 0 || param_2 == 0) {
    return 0;
  }
  local_e0 = 100;
  uVar1 = libspdm_x509_get_issuer_name(param_1,param_2,local_d0,&local_e0);
  if ((char)uVar1 != '\0') {
    local_d8 = 100;
    uVar1 = libspdm_x509_get_subject_name(param_1,param_2,local_6c,&local_d8);
    if ((char)uVar1 != '\0') {
      uVar1 = 0;
      if (local_e0 == local_d8) {
        uVar1 = libspdm_consttime_is_mem_equal(local_d0,local_6c);
      }
    }
  }
  return uVar1;
}


// ===== 00501680 libspdm_verify_certificate_chain_buffer =====

undefined4
libspdm_verify_certificate_chain_buffer
          (undefined4 param_1,undefined4 param_2,ushort *param_3,ulong param_4,undefined1 param_5,
          char param_6)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 local_88;
  ulong local_80;
  long local_78;
  long local_70;
  undefined1 local_68 [56];
  
  uVar3 = libspdm_get_hash_size();
  uVar6 = (ulong)uVar3;
  if (uVar6 + 4 < param_4) {
    if (*param_3 == param_4) {
      lVar1 = (long)param_3 + uVar6 + 4;
      uVar5 = ((ulong)*param_3 - 4) - uVar6;
      uVar4 = libspdm_x509_get_cert_from_cert_chain(lVar1,uVar5,0,&local_88,&local_80);
      if ((char)uVar4 == '\0') {
        libspdm_debug_print(0x40,
                            "!!! VerifyCertificateChainBuffer - FAIL (get root certificate failed)!!!\n"
                           );
        return uVar4;
      }
      cVar2 = libspdm_is_root_certificate(local_88,local_80);
      if (cVar2 != '\0') {
        uVar4 = libspdm_hash_all(param_1,local_88,local_80,local_68);
        if ((char)uVar4 == '\0') {
          libspdm_debug_print(0x40,
                              "!!! VerifyCertificateChainBuffer - FAIL (hash calculation fail) !!!\n"
                             );
          return uVar4;
        }
        uVar4 = libspdm_consttime_is_mem_equal(param_3 + 2,local_68,uVar6);
        if ((char)uVar4 == '\0') {
          libspdm_debug_print(0x40,
                              "!!! VerifyCertificateChainBuffer - FAIL (cert root hash mismatch) !!!\n"
                             );
          return uVar4;
        }
        libspdm_debug_print(0x40,
                            "!!! VerifyCertificateChainBuffer - PASS (cert root hash match) !!!\n");
      }
      if ((local_80 < uVar5) &&
         (uVar4 = libspdm_x509_verify_cert_chain
                            (local_88,local_80,lVar1 + local_80,uVar5 - local_80),
         (char)uVar4 == '\0')) {
        libspdm_debug_print(0x40,
                            "!!! VerifyCertificateChainBuffer - FAIL (cert chain verify failed)!!!\n"
                           );
        return uVar4;
      }
      uVar4 = libspdm_x509_get_cert_from_cert_chain(lVar1,uVar5,0xffffffff,&local_78,&local_70);
      if ((char)uVar4 == '\0') {
        libspdm_debug_print(0x40,
                            "!!! VerifyCertificateChainBuffer - FAIL (get leaf certificate failed)!!!\n"
                           );
        return uVar4;
      }
      if ((((local_78 != 0) && (local_70 != 0)) &&
          (cVar2 = libspdm_x509_common_certificate_check_part_0
                             (local_78,local_70,param_2,param_5,'\x02' - param_6,0), cVar2 != '\0'))
         && (uVar4 = libspdm_verify_leaf_cert_basic_constraints(local_78,local_70,0),
            (char)uVar4 != '\0')) {
        return uVar4;
      }
      libspdm_debug_print(0x40,
                          "!!! VerifyCertificateChainBuffer - FAIL (leaf certificate check failed)!!!\n"
                         );
    }
    else {
      libspdm_debug_print(0x40,
                          "!!! VerifyCertificateChainBuffer - FAIL (cert_chain->length mismatch) !!!\n"
                         );
    }
  }
  else {
    libspdm_debug_print(0x40,"!!! VerifyCertificateChainBuffer - FAIL (buffer too small) !!!\n");
  }
  return 0;
}


// ===== 00501930 libspdm_get_leaf_cert_public_key_from_cert_chain =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
libspdm_get_leaf_cert_public_key_from_cert_chain
          (undefined8 param_1,undefined4 param_2,long param_3,long param_4,undefined8 param_5)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar1 = libspdm_get_hash_size();
  uVar2 = libspdm_x509_get_cert_from_cert_chain
                    (param_3 + 4 + (ulong)uVar1,(param_4 + -4) - (ulong)uVar1,0xffffffff,&local_38,
                     &local_30);
  if ((char)uVar2 != '\0') {
    pcVar3 = (code *)libspdm_get_asym_get_public_key_from_x509(param_2);
    if (pcVar3 != (code *)0x0) {
      uVar2 = (*pcVar3)(local_38,local_30,param_5);
      return uVar2;
    }
    uVar2 = 0;
  }
  return uVar2;
}


// ===== 005019d0 libspdm_get_dhe_pub_key_size =====

undefined8 libspdm_get_dhe_pub_key_size(short param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x60;
  if (param_1 != 0x10) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 005019f0 libspdm_dhe_new =====

undefined8 libspdm_dhe_new(undefined8 param_1,ushort param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  ushort uVar4;
  
  uVar4 = param_2 - 1;
  if ((param_2 ^ uVar4) <= uVar4) {
    return 0;
  }
  iVar1 = 0;
  if (param_2 != 0) {
    for (; (param_2 >> iVar1 & 1) == 0; iVar1 = iVar1 + 1) {
    }
  }
  if (param_2 == 0) {
    iVar1 = -1;
  }
  if (6 < (ushort)iVar1) {
    return 0;
  }
  if (uVar4 < 0x40) {
    uVar2 = 1L << ((byte)uVar4 & 0x3f);
    if ((uVar2 & 0xb) != 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x81,
                 "false");
      return 0;
    }
    if ((uVar2 & 0x80008080) != 0) {
      if (param_2 == 8) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x8a,
                   "dhe_named_group != SPDM_ALGORITHMS_DHE_NAMED_GROUP_SECP_256_R1");
      }
      else if (param_2 == 0x20) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x90,
                   "dhe_named_group != SPDM_ALGORITHMS_DHE_NAMED_GROUP_SECP_521_R1");
      }
      uVar3 = libspdm_ec_new_by_nid((short)(iVar1 + 1) + 0x200);
      return uVar3;
    }
    if ((long)uVar2 < 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0xb6,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0xbb,"false");
  return 0;
}


// ===== 00501b20 libspdm_dhe_free =====

void libspdm_dhe_free(short param_1,long param_2)

{
  ulong uVar1;
  
  if (param_2 == 0) {
    return;
  }
  if ((ushort)(param_1 - 1U) < 0x40) {
    uVar1 = 1L << ((byte)(param_1 - 1U) & 0x3f);
    if ((uVar1 & 0xb) != 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0xcc,
                 "false");
      return;
    }
    if ((uVar1 & 0x80008080) != 0) {
      libspdm_ec_free(param_2);
      return;
    }
    if ((long)uVar1 < 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0xdc,
                 "false");
      return;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0xe0,"false");
  return;
}


// ===== 00501bd0 libspdm_dhe_generate_key =====

undefined8
libspdm_dhe_generate_key(short param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  
  if ((ushort)(param_1 - 1U) < 0x40) {
    uVar1 = 1L << ((byte)(param_1 - 1U) & 0x3f);
    if ((uVar1 & 0xb) != 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0xf9,
                 "false");
      return 0;
    }
    if ((uVar1 & 0x80008080) != 0) {
      if (param_1 == 8) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x101,
                   "dhe_named_group != SPDM_ALGORITHMS_DHE_NAMED_GROUP_SECP_256_R1");
      }
      else if (param_1 == 0x20) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x107,
                   "dhe_named_group != SPDM_ALGORITHMS_DHE_NAMED_GROUP_SECP_521_R1");
      }
      uVar2 = libspdm_ec_generate_key(param_2,param_3,param_4);
      return uVar2;
    }
    if ((long)uVar1 < 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x112,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x116,"false")
  ;
  return 0;
}


// ===== 00501d00 libspdm_dhe_compute_key =====

undefined8
libspdm_dhe_compute_key
          (short param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5
          ,undefined8 param_6)

{
  ulong uVar1;
  undefined8 uVar2;
  
  if ((ushort)(param_1 - 1U) < 0x40) {
    uVar1 = 1L << ((byte)(param_1 - 1U) & 0x3f);
    if ((uVar1 & 0xb) != 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x134,
                 "false");
      return 0;
    }
    if ((uVar1 & 0x80008080) != 0) {
      if (param_1 == 8) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x13c,
                   "dhe_named_group != SPDM_ALGORITHMS_DHE_NAMED_GROUP_SECP_256_R1");
      }
      else if (param_1 == 0x20) {
        libspdm_debug_assert
                  ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x142,
                   "dhe_named_group != SPDM_ALGORITHMS_DHE_NAMED_GROUP_SECP_521_R1");
      }
      uVar2 = libspdm_ec_compute_key(param_2,param_3,param_4,param_5,param_6);
      return uVar2;
    }
    if ((long)uVar1 < 0) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x158,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_dhe.c",0x15c,"false")
  ;
  return 0;
}


// ===== 00501e50 libspdm_get_hash_size =====

undefined8 libspdm_get_hash_size(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x20;
  if ((param_1 != 1) && (uVar1 = 0x30, param_1 != 2)) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== 00501e70 libspdm_get_hash_nid =====

int libspdm_get_hash_nid(uint param_1)

{
  uint uVar1;
  
  if (param_1 - 1 < (param_1 ^ param_1 - 1)) {
    uVar1 = 0;
    if (param_1 != 0) {
      for (; (param_1 >> uVar1 & 1) == 0; uVar1 = uVar1 + 1) {
      }
    }
    if (param_1 == 0) {
      uVar1 = 0xffffffff;
    }
    if (uVar1 < 7) {
      return uVar1 + 1;
    }
  }
  return 0;
}


// ===== 00501ea0 libspdm_hash_new =====

undefined8 libspdm_hash_new(uint param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x6d,
               "false");
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_sha384_new();
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x66,
                 "false");
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_sha256_new();
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x7b,
                 "false");
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x82,
                 "false");
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x74,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x86,"false")
  ;
  return 0;
}


// ===== 00501fb0 libspdm_hash_free =====

void libspdm_hash_free(uint param_1,long param_2)

{
  if (param_2 == 0) {
    return;
  }
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xaa,
               "false");
    return;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      libspdm_sha384_free(param_2);
      return;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xa3,
                 "false");
      return;
    }
    if (param_1 == 1) {
      libspdm_sha256_free(param_2);
      return;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xb8,
                 "false");
      return;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xbf,
                 "false");
      return;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xb1,
                 "false");
      return;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xc3,"false")
  ;
  return;
}


// ===== 005020d0 libspdm_hash_init =====

undefined8 libspdm_hash_init(uint param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xe4,
               "false");
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_sha384_init(param_2);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xdd,
                 "false");
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_sha256_init(param_2);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xf2,
                 "false");
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xf9,
                 "false");
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xeb,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0xfd,"false")
  ;
  return 0;
}


// ===== 005021f0 libspdm_hash_duplicate =====

undefined8 libspdm_hash_duplicate(uint param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x11e,
               "false");
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_sha384_duplicate(param_2,param_3);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x117,
                 "false");
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_sha256_duplicate(param_2,param_3);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",300,
                 "false");
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x133,
                 "false");
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x125,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x137,"false"
            );
  return 0;
}


// ===== 00502320 libspdm_hash_update =====

undefined8
libspdm_hash_update(uint param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (param_1 == 8) {
    libspdm_debug_assert
              ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x159,
               "false");
    return 0;
  }
  if (param_1 < 9) {
    if (param_1 == 2) {
      uVar1 = libspdm_sha384_update(param_2,param_3,param_4);
      return uVar1;
    }
    if (param_1 == 4) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x152,
                 "false");
      return 0;
    }
    if (param_1 == 1) {
      uVar1 = libspdm_sha256_update(param_2,param_3,param_4);
      return uVar1;
    }
  }
  else {
    if (param_1 == 0x20) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x167,
                 "false");
      return 0;
    }
    if (param_1 == 0x40) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x16e,
                 "false");
      return 0;
    }
    if (param_1 == 0x10) {
      libspdm_debug_assert
                ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x160,
                 "false");
      return 0;
    }
  }
  libspdm_debug_assert
            ("src/libraries/libspdm/3.5.0/library/spdm_crypt_lib/libspdm_crypt_hash.c",0x172,"false"
            );
  return 0;
}


