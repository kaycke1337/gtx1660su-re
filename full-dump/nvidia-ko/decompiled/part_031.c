// ===== 003184b0 gsyncapiCtrlCmdGsyncGetStatusSignals_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint gsyncapiCtrlCmdGsyncGetStatusSignals_IMPL(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar5 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar5;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar6 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar5);
    uVar2 = (**(code **)(lVar1 + 0x130))
                      (uVar6,*(undefined8 *)(lVar1 + 0x90),1,0,*(uint *)(param_2 + 0xc) & 1,param_2)
    ;
    uVar3 = (**(code **)(lVar1 + 0x130))
                      (uVar6,*(undefined8 *)(lVar1 + 0x90),1,1,*(byte *)(param_2 + 0xc) >> 1 & 1,
                       param_2 + 4);
    uVar4 = (**(code **)(lVar1 + 0x130))
                      (uVar6,*(undefined8 *)(lVar1 + 0x90),1,2,*(byte *)(param_2 + 0xc) >> 2 & 1,
                       param_2 + 8);
    return uVar4 | uVar2 | uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x4ce);
  return 0x26;
}


// ===== 003185e0 gsyncapiCtrlCmdGsyncGetControlParams_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gsyncapiCtrlCmdGsyncGetControlParams_IMPL(long param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  uint local_40;
  uint local_3c [3];
  
  lVar6 = *(long *)(g_pSys + 0x1e8);
  local_40 = param_2[1];
  uVar7 = (ulong)*(uint *)(param_1 + 0x118);
  local_3c[0] = param_2[2];
  lVar5 = lVar6 + uVar7 * 0x178;
  if (*(long *)(lVar5 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x4ea);
    iVar1 = 0x26;
  }
  else {
    uVar4 = gsyncGetMasterableGpu(lVar6 + 0x50 + uVar7 * 0x178);
    uVar2 = *param_2;
    iVar1 = 0;
    if ((uVar2 & 1) != 0) {
      iVar1 = (**(code **)(lVar5 + 0xa8))(uVar4,*(undefined8 *)(lVar5 + 0x90),&local_40);
      if (iVar1 != 0) {
        nvCheckOkFailedNoLog
                  (1,iVar1,
                   "pGsync->gsyncHal.gsyncGetSyncPolarity(pGpu, pGsync->pExtDev, &SyncPolarity)",
                   "src/kernel/gpu/external_device/gsync.c",0x4f0);
      }
      param_2[1] = local_40;
      uVar2 = *param_2;
    }
    if ((uVar2 & 2) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      iVar3 = (**(code **)(lVar5 + 0xb8))(uVar4,*(undefined8 *)(lVar5 + 0x90),local_3c);
      if ((iVar3 != 0) &&
         (nvCheckOkFailedNoLog
                    (1,iVar3,"pGsync->gsyncHal.gsyncGetVideoMode(pGpu, pGsync->pExtDev, &VideoMode)"
                     ,"src/kernel/gpu/external_device/gsync.c",0x4f6), iVar1 == 0)) {
        iVar1 = iVar3;
      }
      param_2[2] = local_3c[0];
      uVar2 = *param_2;
    }
    if ((uVar2 & 4) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      iVar3 = (**(code **)(lVar5 + 200))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 3);
      if (iVar3 == 0) {
        uVar2 = *param_2;
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar3,"pGsync->gsyncHal.gsyncGetNSync(pGpu, pGsync->pExtDev, &pParams->nSync)",
                   "src/kernel/gpu/external_device/gsync.c",0x4fc);
        uVar2 = *param_2;
        if (iVar1 == 0) {
          iVar1 = iVar3;
        }
      }
    }
    if ((uVar2 & 8) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      iVar3 = (**(code **)(lVar5 + 0xd8))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 4);
      if (iVar3 == 0) {
        uVar2 = *param_2;
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "pGsync->gsyncHal.gsyncGetSyncSkew(pGpu, pGsync->pExtDev, &pParams->syncSkew)",
                   "src/kernel/gpu/external_device/gsync.c",0x501);
        uVar2 = *param_2;
        if (iVar1 == 0) {
          iVar1 = iVar3;
        }
      }
    }
    if ((uVar2 & 0x10) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      iVar3 = (**(code **)(lVar5 + 0xf8))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 5);
      if (iVar3 == 0) {
        uVar2 = *param_2;
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "pGsync->gsyncHal.gsyncGetSyncStartDelay(pGpu, pGsync->pExtDev, &pParams->syncStartDelay)"
                   ,"src/kernel/gpu/external_device/gsync.c",0x506);
        uVar2 = *param_2;
        if (iVar1 == 0) {
          iVar1 = iVar3;
        }
      }
    }
    if ((uVar2 & 0x20) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      iVar3 = (**(code **)(lVar5 + 0xe8))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 6);
      if (iVar3 == 0) {
        uVar2 = *param_2;
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "pGsync->gsyncHal.gsyncGetUseHouse(pGpu, pGsync->pExtDev, &pParams->useHouseSync)"
                   ,"src/kernel/gpu/external_device/gsync.c",0x50b);
        uVar2 = *param_2;
        if (iVar1 == 0) {
          iVar1 = iVar3;
        }
      }
    }
    if ((uVar2 & 0x40) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      iVar3 = (**(code **)(lVar5 + 0x1a0))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 7);
      if (iVar3 == 0) {
        uVar2 = *param_2;
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "pGsync->gsyncHal.gsyncGetMulDiv(pGpu, pGsync->pExtDev, &pParams->syncMulDiv)",
                   "src/kernel/gpu/external_device/gsync.c",0x510);
        uVar2 = *param_2;
        if (iVar1 == 0) {
          iVar1 = iVar3;
        }
      }
    }
    if ((((uVar2 & 0x80) != 0) &&
        (lVar6 = lVar6 + uVar7 * 0x178,
        iVar3 = (**(code **)(lVar6 + 0x1b0))(uVar4,*(undefined8 *)(lVar6 + 0x90),param_2 + 8),
        iVar3 != 0)) &&
       (nvCheckOkFailedNoLog
                  (1,iVar3,"pGsync->gsyncHal.gsyncGetVRR(pGpu, pGsync->pExtDev, &pParams->syncVRR)",
                   "src/kernel/gpu/external_device/gsync.c",0x515), iVar1 == 0)) {
      iVar1 = iVar3;
    }
  }
  return iVar1;
}


// ===== 003189f0 gsyncapiCtrlCmdGsyncSetControlParams_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint gsyncapiCtrlCmdGsyncSetControlParams_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  uint uVar8;
  
  uVar7 = (ulong)*(uint *)(param_1 + 0x118);
  lVar6 = *(long *)(g_pSys + 0x1e8);
  lVar5 = lVar6 + uVar7 * 0x178;
  if (*(long *)(lVar5 + 0x90) == 0) {
    uVar8 = 0x26;
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x524);
  }
  else {
    uVar3 = param_2[1];
    uVar1 = param_2[2];
    uVar4 = gsyncGetMasterableGpu(lVar6 + 0x50 + uVar7 * 0x178);
    uVar2 = *param_2;
    uVar8 = 0;
    if ((uVar2 & 1) != 0) {
      uVar8 = (**(code **)(lVar5 + 0xb0))(uVar4,*(undefined8 *)(lVar5 + 0x90),uVar3);
      param_2[1] = uVar3;
      uVar2 = *param_2;
    }
    if ((uVar2 & 2) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      uVar3 = (**(code **)(lVar5 + 0xc0))(uVar4,*(undefined8 *)(lVar5 + 0x90),uVar1);
      uVar8 = uVar8 | uVar3;
      param_2[2] = uVar1;
      uVar2 = *param_2;
    }
    if ((uVar2 & 4) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      uVar3 = (**(code **)(lVar5 + 0xd0))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2[3]);
      uVar8 = uVar8 | uVar3;
      uVar2 = *param_2;
    }
    if ((uVar2 & 8) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      uVar3 = (**(code **)(lVar5 + 0xe0))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2[4]);
      uVar8 = uVar8 | uVar3;
      uVar2 = *param_2;
    }
    if ((uVar2 & 0x10) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      uVar3 = (**(code **)(lVar5 + 0x100))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2[5]);
      uVar8 = uVar8 | uVar3;
      uVar2 = *param_2;
    }
    if ((uVar2 & 0x20) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      uVar3 = (**(code **)(lVar5 + 0xf0))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2[6]);
      uVar8 = uVar8 | uVar3;
      uVar2 = *param_2;
    }
    if ((uVar2 & 0x40) != 0) {
      lVar5 = uVar7 * 0x178 + lVar6;
      uVar3 = (**(code **)(lVar5 + 0x1a8))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 7);
      uVar8 = uVar8 | uVar3;
      uVar2 = *param_2;
    }
    if ((uVar2 & 0x80) != 0) {
      lVar6 = lVar6 + uVar7 * 0x178;
      uVar3 = (**(code **)(lVar6 + 0x1b8))(uVar4,*(undefined8 *)(lVar6 + 0x90),param_2[8]);
      uVar8 = uVar8 | uVar3;
    }
  }
  return uVar8;
}


// ===== 00318c30 gsyncapiCtrlCmdGsyncGetControlSync_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gsyncapiCtrlCmdGsyncGetControlSync_IMPL(long param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  int local_40;
  undefined4 local_3c;
  
  uVar5 = (ulong)*(uint *)(param_1 + 0x118);
  lVar6 = *(long *)(g_pSys + 0x1e8);
  lVar7 = uVar5 * 0x178;
  if (*(long *)(lVar6 + 0x90 + lVar7) == 0) {
    uVar5 = 0x26;
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x5c8);
  }
  else {
    lVar3 = gpumgrGetGpuFromId(*param_2);
    if (lVar3 != 0) {
      lVar4 = lVar6 + lVar7;
      do {
        if (*(int *)(lVar3 + 0x7ac) == *(int *)(lVar4 + 0x5c)) {
          local_40 = param_2[2];
          if (local_40 != 0) {
            local_3c = 0;
            uVar2 = (**(code **)(lVar3 + 0x3b90))
                              (lVar3 + 0x3b58,*(undefined4 *)(lVar3 + 0x3b34),
                               *(undefined4 *)(lVar3 + 0x3b3c),0x20800ac9,&local_40,8);
            if (uVar2 == 0) {
              lVar6 = uVar5 * 0x178 + lVar6;
              bVar1 = (**(code **)(lVar6 + 0xa0))(lVar3,*(undefined8 *)(lVar6 + 0x90));
              param_2[1] = (uint)bVar1;
              param_2[2] = local_3c;
              return 0;
            }
            param_2[2] = 0;
            nvDbg_Printf("src/kernel/gpu/external_device/gsync.c",0x5f7,"gsyncGetControlSync",4,
                         "NVRM: Extdev display IDs for the display doesn\'t exist!\n");
            return (ulong)uVar2;
          }
          lVar7 = lVar6 + 0x50 + lVar7;
          if (param_2[1] != 0) {
            uVar2 = (**(code **)(lVar6 + 0x138 + uVar5 * 0x178))
                              (lVar3,lVar7,1,param_2 + 2,param_2 + 4,0,0);
            return (ulong)uVar2;
          }
          uVar5 = (**(code **)(lVar6 + 0x140 + uVar5 * 0x178))
                            (lVar3,lVar7,1,param_2 + 2,param_2 + 4);
          return uVar5;
        }
        lVar4 = lVar4 + 0xc;
      } while (lVar4 != lVar6 + 0x30 + lVar7);
    }
    uVar5 = 0x1f;
  }
  return uVar5;
}


// ===== 00318e40 gsyncapiCtrlCmdGsyncSetControlSync_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gsyncapiCtrlCmdGsyncSetControlSync_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  undefined4 uVar10;
  uint local_40;
  undefined1 local_3c [12];
  
  uVar8 = (ulong)*(uint *)(param_1 + 0x118);
  lVar9 = *(long *)(g_pSys + 0x1e8);
  lVar7 = uVar8 * 0x178;
  lVar4 = lVar9 + lVar7;
  if (*(long *)(lVar4 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x60c);
    return 0x26;
  }
  lVar3 = gpumgrGetGpuFromId(*param_2);
  if (lVar3 != 0) {
    do {
      if (*(int *)(lVar3 + 0x7ac) == *(int *)(lVar4 + 0x5c)) {
        if (param_2[4] == 0) {
          return 0x1f;
        }
        lVar7 = lVar9 + 0x50 + lVar7;
        if (param_2[1] == 0) {
          lVar4 = uVar8 * 0x178 + lVar9;
          uVar6 = (**(code **)(lVar4 + 0x140))(lVar3,lVar7,0,&local_40,local_3c);
          param_2[2] = param_2[2] | local_40;
          uVar2 = (**(code **)(lVar4 + 0x140))(lVar3,lVar7,2,param_2 + 2,param_2 + 4);
          uVar6 = uVar6 | uVar2;
        }
        else {
          uVar1 = param_2[5];
          uVar10 = 0;
          lVar4 = uVar8 * 0x178 + lVar9;
          uVar6 = (**(code **)(lVar4 + 0x138))(lVar3,lVar7,0,&local_40,local_3c,0,0);
          param_2[2] = param_2[2] | local_40;
          uVar2 = (**(code **)(lVar4 + 0x138))
                            (lVar3,lVar7,2,param_2 + 2,param_2 + 4,0,
                             CONCAT44(uVar10,uVar1) & 0xffffffff00000001);
          uVar6 = uVar6 | uVar2;
        }
        uVar5 = (ulong)uVar6;
        lVar9 = uVar8 * 0x178 + lVar9;
        if ((((*(char *)(lVar9 + 0x98) != '\0') && (uVar6 == 0)) &&
            (uVar5 = (ulong)(uint)param_2[2], param_2[2] != 0)) &&
           (uVar5 = (**(code **)(lVar9 + 0x150))(lVar3,*(undefined8 *)(lVar9 + 0x90),1),
           (int)uVar5 != 0)) {
          nvAssertFailedNoLog(&DAT_00d11409,"src/kernel/gpu/external_device/gsync.c",0x63b);
          return 0;
        }
        return uVar5;
      }
      lVar4 = lVar4 + 0xc;
    } while (lVar9 + 0x30 + lVar7 != lVar4);
  }
  return 0x1f;
}


// ===== 003190a0 gsyncapiCtrlCmdGsyncSetControlUnsync_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong gsyncapiCtrlCmdGsyncSetControlUnsync_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  uint local_48;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  int local_3c [3];
  
  uVar6 = (ulong)*(uint *)(param_1 + 0x118);
  lVar1 = *(long *)(g_pSys + 0x1e8);
  lVar11 = uVar6 * 0x178;
  lVar10 = lVar1 + lVar11;
  if (*(long *)(lVar10 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x64a);
    return 0x26;
  }
  lVar4 = gpumgrGetGpuFromId(*param_2);
  if (lVar4 != 0) {
    lVar5 = lVar10;
    do {
      if (*(int *)(lVar4 + 0x7ac) == *(int *)(lVar5 + 0x5c)) {
        lVar11 = lVar1 + 0x50 + lVar11;
        if (param_2[1] == 0) {
          lVar5 = uVar6 * 0x178 + lVar1;
          uVar8 = (**(code **)(lVar5 + 0x140))(lVar4,lVar11,0,&local_48,local_44);
          param_2[2] = ~param_2[2] & local_48;
          uVar2 = (**(code **)(lVar5 + 0x140))(lVar4,lVar11,2,param_2 + 2,local_44);
          uVar8 = uVar8 | uVar2;
        }
        else {
          uVar12 = 0;
          lVar5 = uVar6 * 0x178 + lVar1;
          uVar8 = (**(code **)(lVar5 + 0x138))(lVar4,lVar11,0,&local_48,local_44,0,0);
          param_2[2] = ~param_2[2] & local_48;
          uVar2 = (**(code **)(lVar5 + 0x138))
                            (lVar4,lVar11,2,param_2 + 2,local_44,param_2[3] != 0,
                             uVar12 & 0xffffffff00000000);
          uVar8 = uVar8 | uVar2;
        }
        lVar7 = uVar6 * 0x178;
        lVar5 = lVar1 + lVar7;
        if (*(char *)(lVar5 + 0x98) == '\0') {
          return (ulong)uVar8;
        }
        if (uVar8 != 0) {
          return (ulong)uVar8;
        }
        if (param_2[2] != 0) {
          return 0;
        }
        uVar9 = 0;
        if (*(long *)(lVar5 + 0x90) == 0) goto LAB_0031938d;
        if (*(int *)(lVar5 + 0x54) == 0) goto LAB_0031937e;
        uVar8 = 0;
        goto LAB_003192f0;
      }
      lVar5 = lVar5 + 0xc;
    } while (lVar5 != lVar1 + 0x30 + lVar11);
  }
  return 0x1f;
  while( true ) {
    uVar8 = uVar8 + 1;
    lVar10 = lVar10 + 0xc;
    if (*(uint *)(lVar1 + 0x54 + lVar7) <= uVar8) break;
LAB_003192f0:
    lVar5 = gpumgrGetGpuFromId(*(undefined4 *)(lVar10 + 0x5c));
    if ((lVar5 != 0) &&
       (((iVar3 = (**(code **)(lVar1 + 0x140 + lVar7))(lVar5,lVar11,0,local_3c,local_40), iVar3 == 0
         && (local_3c[0] != 0)) ||
        ((iVar3 = (**(code **)(lVar1 + 0x138 + lVar7))(lVar5,lVar11,0,local_3c,local_40,0,0),
         iVar3 == 0 && (local_3c[0] != 0)))))) goto LAB_003193c3;
  }
LAB_0031937e:
  uVar9 = *(undefined8 *)(lVar1 + 0x90 + uVar6 * 0x178);
LAB_0031938d:
  uVar6 = (**(code **)(lVar1 + 0x150 + uVar6 * 0x178))(lVar4,uVar9,0);
  if ((int)uVar6 != 0) {
    nvAssertFailedNoLog(&DAT_00d11409,"src/kernel/gpu/external_device/gsync.c",0x674);
LAB_003193c3:
    uVar6 = 0;
  }
  return uVar6;
}


// ===== 003193d0 gsyncapiCtrlCmdGsyncGetStatusSync_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint gsyncapiCtrlCmdGsyncGetStatusSync_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  uVar1 = *(uint *)(param_1 + 0x118);
  lVar7 = *(long *)(g_pSys + 0x1e8);
  lVar6 = (ulong)uVar1 * 0x178;
  lVar5 = lVar7 + lVar6;
  if (*(long *)(lVar5 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x681);
    return 0x26;
  }
  lVar4 = gpumgrGetGpuFromId(*param_2);
  if (lVar4 != 0) {
    do {
      if (*(int *)(lVar4 + 0x7ac) == *(int *)(lVar5 + 0x5c)) {
        lVar7 = lVar7 + (ulong)uVar1 * 0x178;
        uVar1 = (**(code **)(lVar7 + 0x148))(lVar4,*(undefined8 *)(lVar7 + 0x90),4,param_2 + 1);
        uVar2 = (**(code **)(lVar7 + 0x148))(lVar4,*(undefined8 *)(lVar7 + 0x90),5,param_2 + 2);
        uVar3 = (**(code **)(lVar7 + 0x148))(lVar4,*(undefined8 *)(lVar7 + 0x90),2,param_2 + 3);
        return uVar3 | uVar1 | uVar2;
      }
      lVar5 = lVar5 + 0xc;
    } while (lVar7 + 0x30 + lVar6 != lVar5);
  }
  return 0x1f;
}


// ===== 00319530 gsyncapiCtrlCmdGsyncGetStatus_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int gsyncapiCtrlCmdGsyncGetStatus_IMPL(long param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  uint local_3c [3];
  
  uVar6 = (ulong)*(uint *)(param_1 + 0x118);
  lVar7 = *(long *)(g_pSys + 0x1e8);
  lVar5 = lVar7 + uVar6 * 0x178;
  if (*(long *)(lVar5 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x6a1);
    return 0x26;
  }
  uVar4 = gsyncGetMasterableGpu(lVar7 + 0x50 + uVar6 * 0x178);
  uVar2 = *param_2;
  iVar1 = 0;
  if ((uVar2 & 1) != 0) {
    local_3c[0] = 0;
    iVar1 = (**(code **)(lVar5 + 0xa8))(uVar4,*(undefined8 *)(lVar5 + 0x90),local_3c);
    if (iVar1 == 0) {
      param_2[1] = (uint)((local_3c[0] & 0xfffffffd) == 0);
      param_2[2] = (uint)(local_3c[0] - 1 < 2);
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar1,
                 "pGsync->gsyncHal.gsyncGetSyncPolarity(pGpu, pGsync->pExtDev, &SyncPolarity)",
                 "src/kernel/gpu/external_device/gsync.c",0x6a9);
      uVar2 = *param_2;
    }
  }
  if ((uVar2 & 2) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0xf8))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 3);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetSyncStartDelay(pGpu, pGsync->pExtDev, &pParams->syncDelay)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6b9);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((uVar2 & 4) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),0,param_2 + 4);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_Refresh, &pParams->refresh)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6c0);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((uVar2 & 8) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),1,param_2 + 5);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_HouseSyncIncoming, &pParams->houseSyncIncoming)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6c7);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((uVar2 & 0x10) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 200))(uVar4,*(undefined8 *)(lVar5 + 0x90),param_2 + 6);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetNSync(pGpu, pGsync->pExtDev, &pParams->syncInterval)",
                 "src/kernel/gpu/external_device/gsync.c",0x6ce);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((uVar2 & 0x20) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),2,param_2 + 7);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bSyncReady, &pParams->bSyncReady)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6d5);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((uVar2 & 0x40) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),3,param_2 + 8);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bSwapReady, &pParams->bSwapReady)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6dc);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((uVar2 & 0x200) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),6,param_2 + 9);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bHouseSync, &pParams->bHouseSync)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6e3);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((uVar2 & 0x400) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),7,param_2 + 10);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),8,param_2 + 0xb);
      if (iVar3 == 0) {
LAB_003197d9:
        uVar2 = *param_2;
      }
      else {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bPort1Input, &pParams->bPort1Input)"
                   ,"src/kernel/gpu/external_device/gsync.c",0x6ed);
        uVar2 = *param_2;
        if (iVar1 == 0) {
          iVar1 = iVar3;
        }
      }
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bPort0Input, &pParams->bPort0Input)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6ea);
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
      iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),8,param_2 + 0xb);
      if (iVar3 == 0) goto LAB_003197d9;
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bPort1Input, &pParams->bPort1Input)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6ed);
      uVar2 = *param_2;
    }
  }
  if ((uVar2 & 0x800) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),9,param_2 + 0xc);
    if (iVar3 == 0) {
      iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),10,param_2 + 0xd);
      if (iVar3 != 0) {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bPort1Ethernet, &pParams->bPort1Ethernet)"
                   ,"src/kernel/gpu/external_device/gsync.c",0x6f7);
        uVar2 = *param_2;
        if (iVar1 == 0) {
          iVar1 = iVar3;
        }
        goto LAB_00319844;
      }
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bPort0Ethernet, &pParams->bPort0Ethernet)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6f4);
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
      iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),10,param_2 + 0xd);
      if (iVar3 != 0) {
        nvCheckOkFailedNoLog
                  (1,iVar3,
                   "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bPort1Ethernet, &pParams->bPort1Ethernet)"
                   ,"src/kernel/gpu/external_device/gsync.c",0x6f7);
        uVar2 = *param_2;
        goto LAB_00319844;
      }
    }
    uVar2 = *param_2;
  }
LAB_00319844:
  if ((uVar2 & 0x1000) != 0) {
    lVar5 = uVar6 * 0x178 + lVar7;
    iVar3 = (**(code **)(lVar5 + 0x148))(uVar4,*(undefined8 *)(lVar5 + 0x90),0xb,param_2 + 0xe);
    if (iVar3 == 0) {
      uVar2 = *param_2;
    }
    else {
      nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_UniversalFrameCount, &pParams->universalFrameCount)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x6fe);
      uVar2 = *param_2;
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
    }
  }
  if ((((uVar2 & 0x2000) != 0) &&
      (lVar7 = uVar6 * 0x178 + lVar7,
      iVar3 = (**(code **)(lVar7 + 0x148))(uVar4,*(undefined8 *)(lVar7 + 0x90),0xc,param_2 + 0xf),
      iVar3 != 0)) &&
     (nvCheckOkFailedNoLog
                (1,iVar3,
                 "pGsync->gsyncHal.gsyncGetCplStatus(pGpu, pGsync->pExtDev, gsync_Status_bInternalSlave, &pParams->bInternalSlave)"
                 ,"src/kernel/gpu/external_device/gsync.c",0x705), iVar1 == 0)) {
    iVar1 = iVar3;
  }
  return iVar1;
}


// ===== 00319c50 gsyncapiCtrlCmdGsyncGetControlTesting_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncGetControlTesting_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar3 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar2);
    uVar3 = (**(code **)(lVar1 + 0x108))(uVar3,*(undefined8 *)(lVar1 + 0x90),param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x714);
  return 0x26;
}


// ===== 00319cf0 gsyncapiCtrlCmdGsyncSetControlTesting_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncSetControlTesting_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar3 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar2);
    uVar3 = (**(code **)(lVar1 + 0x110))(uVar3,*(undefined8 *)(lVar1 + 0x90),*param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x725);
  return 0x26;
}


// ===== 00319d80 gsyncapiCtrlCmdGsyncSetControlWatchdog_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncSetControlWatchdog_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar3 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar2);
    *(undefined1 *)(lVar1 + 0x98) = 0;
    uVar3 = (**(code **)(lVar1 + 0x150))(uVar3,*(undefined8 *)(lVar1 + 0x90),*param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x736);
  return 0x26;
}


// ===== 00319e20 gsyncapiCtrlCmdGsyncGetControlInterlaceMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncGetControlInterlaceMode_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar3 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar2);
    uVar3 = (**(code **)(lVar1 + 0x118))(uVar3,*(undefined8 *)(lVar1 + 0x90),param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x74b);
  return 0x26;
}


// ===== 00319ec0 gsyncapiCtrlCmdGsyncSetControlInterlaceMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncSetControlInterlaceMode_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar3 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar2);
    uVar3 = (**(code **)(lVar1 + 0x120))(uVar3,*(undefined8 *)(lVar1 + 0x90),*param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x75c);
  return 0x26;
}


// ===== 00319f50 gsyncapiCtrlCmdGsyncGetControlSwapBarrier_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncGetControlSwapBarrier_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar1 = *(uint *)(param_1 + 0x118);
  lVar2 = *(long *)(g_pSys + 0x1e8);
  lVar4 = gpumgrGetGpuFromId(*param_2);
  if (lVar4 == 0) {
    return 0x1f;
  }
  lVar2 = lVar2 + (ulong)uVar1 * 0x178;
  lVar3 = *(long *)(lVar2 + 0x90);
  if (lVar3 != 0) {
    uVar5 = (**(code **)(lVar2 + 0x128))(lVar4,lVar3,1,param_2 + 1);
    return uVar5;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x76d);
  return 0x26;
}


// ===== 0031a000 gsyncapiCtrlCmdGsyncSetControlSwapBarrier_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncSetControlSwapBarrier_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  
  uVar1 = *(uint *)(param_1 + 0x118);
  lVar2 = *(long *)(g_pSys + 0x1e8);
  lVar4 = gpumgrGetGpuFromId(*param_2);
  if (lVar4 == 0) {
    return 0x1f;
  }
  lVar2 = lVar2 + (ulong)uVar1 * 0x178;
  lVar3 = *(long *)(lVar2 + 0x90);
  if (lVar3 != 0) {
    uVar5 = (**(code **)(lVar2 + 0x128))(lVar4,lVar3,2,param_2 + 1);
    return uVar5;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x77c);
  return 0x26;
}


// ===== 0031a0b0 gsyncapiCtrlCmdGsyncGetControlSwapLockWindow_IMPL =====

undefined8 gsyncapiCtrlCmdGsyncGetControlSwapLockWindow_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_1c [3];
  
  local_1c[0] = 0;
  lVar1 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  if (*(long *)(*(long *)(g_pSys + 0x1e8) + 0x90 + lVar1) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x78c);
    return 0x26;
  }
  lVar1 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar1);
  if (lVar1 != 0) {
    uVar2 = osReadRegistryDword(lVar1,"TSwapRdyHiSwapLockoutStart",local_1c);
    if ((int)uVar2 != 0) {
      *param_2 = 0xfa;
      return 0;
    }
    *param_2 = local_1c[0];
    return uVar2;
  }
  return 0xffff;
}


// ===== 0031a170 gsyncapiCtrlCmdGsyncGetCaps_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncGetCaps_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    lVar2 = *(long *)(g_pSys + 0x1e8) + 0x50 + lVar2;
    uVar3 = gsyncGetMasterableGpu(lVar2);
    uVar3 = (**(code **)(lVar1 + 0x158))(uVar3,lVar2,param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x55b);
  return 0x26;
}


// ===== 0031a210 gsyncapiCtrlCmdGsyncGetOptimizedTiming_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 gsyncapiCtrlCmdGsyncGetOptimizedTiming_IMPL(long param_1,undefined4 *param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = (ulong)*(uint *)(param_1 + 0x118) * 0x178 + *(long *)(g_pSys + 0x1e8);
  if (*(long *)(lVar4 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x7ac);
    uVar3 = 0x26;
  }
  else {
    lVar2 = gpumgrGetGpuFromId(*param_2);
    if (lVar2 != 0) {
      pcVar1 = *(code **)(lVar4 + 0x168);
      uVar3 = (*pcVar1)(lVar2,param_2,pcVar1);
      return uVar3;
    }
    uVar3 = 0x1f;
  }
  return uVar3;
}


// ===== 0031a2a0 gsyncapiCtrlCmdGsyncSetLocalSync_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncSetLocalSync_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  
  lVar8 = *(long *)(g_pSys + 0x1e8);
  uVar3 = *(uint *)(param_1 + 0x118);
  lVar10 = (ulong)uVar3 * 0x178;
  lVar1 = lVar8 + lVar10;
  if (*(long *)(lVar1 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x582);
    return 0x26;
  }
  lVar5 = gpumgrGetGpuFromId(*param_2);
  if (lVar5 != 0) {
    lVar10 = lVar8 + 0x30 + lVar10;
    lVar6 = lVar1;
    do {
      if (*(int *)(lVar5 + 0x7ac) == *(int *)(lVar6 + 0x5c)) {
        if (4 < (uint)param_2[5]) {
          return 0x1f;
        }
        if (param_2[5] != 0) {
          lVar6 = 0;
          do {
            lVar7 = gpumgrGetGpuFromId(param_2[lVar6 + 1]);
            if (lVar7 == 0) {
              return 0x1f;
            }
            iVar2 = *(int *)(lVar1 + 0x5c);
            lVar4 = lVar1;
            while (*(int *)(lVar7 + 0x7ac) != iVar2) {
              if (lVar4 + 0xc == lVar10) {
                return 0x1f;
              }
              iVar2 = *(int *)(lVar4 + 0x68);
              lVar4 = lVar4 + 0xc;
            }
            lVar6 = lVar6 + 1;
          } while ((uint)lVar6 < (uint)param_2[5]);
        }
        lVar8 = (ulong)uVar3 * 0x178 + lVar8;
        uVar9 = (**(code **)(lVar8 + 0x180))(lVar5,*(undefined8 *)(lVar8 + 0x90),param_2);
        return uVar9;
      }
      lVar6 = lVar6 + 0xc;
    } while (lVar6 != lVar10);
  }
  return 0x1f;
}


// ===== 0031a400 gsyncapiCtrlCmdGsyncConfigFlash_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncConfigFlash_IMPL(long param_1,undefined4 *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  uVar1 = *(uint *)(param_1 + 0x118);
  lVar5 = *(long *)(g_pSys + 0x1e8);
  lVar6 = (ulong)uVar1 * 0x178;
  if (*(long *)(lVar5 + 0x90 + lVar6) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x5ae);
    return 0x26;
  }
  lVar2 = gpumgrGetGpuFromId(*param_2);
  if (lVar2 != 0) {
    lVar3 = lVar5 + lVar6;
    do {
      if (*(int *)(lVar2 + 0x7ac) == *(int *)(lVar3 + 0x5c)) {
        lVar5 = lVar5 + (ulong)uVar1 * 0x178;
        uVar4 = (**(code **)(lVar5 + 0x188))(lVar2,*(undefined8 *)(lVar5 + 0x90),param_2[1]);
        return uVar4;
      }
      lVar3 = lVar3 + 0xc;
    } while (lVar5 + 0x30 + lVar6 != lVar3);
  }
  return 0x1f;
}


// ===== 0031a4f0 gsyncapiCtrlCmdGsyncSetEventNotification_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncSetEventNotification_IMPL(long param_1,uint *param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  
  if (*param_2 == 0) {
    *(undefined4 *)(param_1 + 0x120) = 0;
    return 0;
  }
  if (*(long *)(*(long *)(param_1 + 0x108) + 0x28) == 0) {
    return 0x40;
  }
  uVar1 = *(uint *)(param_1 + 0x118);
  lVar2 = *(long *)(g_pSys + 0x1e8);
  plVar4 = (long *)(**(code **)(**(long **)(*(long *)(param_1 + 0x108) + 0x18) + 0x18))();
  if (*plVar4 == 0) {
    return 0x40;
  }
  uVar5 = *param_2;
  if ((uVar5 & 0x1ff) == 0) {
    return 0x1f;
  }
  if ((uVar5 - 1 & uVar5) != 0) {
    nvAssertFailedNoLog("ONEBITSET(tempMask)","src/kernel/gpu/external_device/gsync.c",0x40c);
  }
  uVar5 = uVar5 >> 1;
  uVar6 = 0;
  if (uVar5 != 0) {
    uVar6 = 0x1f;
    if (uVar5 != 0) {
      for (; uVar5 >> uVar6 == 0; uVar6 = uVar6 - 1) {
      }
    }
    if (8 < (uVar6 ^ 0x1f) - 0x18) goto LAB_0031a595;
    uVar6 = 0x20 - (uVar6 ^ 0x1f);
  }
  uVar7 = (ulong)uVar6;
  if (*(long *)(param_1 + 0x128 + uVar7 * 8) != 0) {
    nvAssertFailedNoLog("pGsyncApi->pEventByType[eventNum] == NULL",
                        "src/kernel/gpu/external_device/gsync.c",0x416);
    return 0x40;
  }
  lVar3 = *plVar4;
  *(long *)(param_1 + 0x128 + uVar7 * 8) = lVar3;
  *plVar4 = *(long *)(lVar3 + 0x40);
  *(undefined8 *)(*(long *)(param_1 + 0x128 + uVar7 * 8) + 0x40) = 0;
  *(uint *)(param_1 + 0x120) = *(uint *)(param_1 + 0x120) | *param_2;
LAB_0031a595:
  *(undefined1 *)(param_1 + 0x170) = 1;
  *(undefined1 *)(lVar2 + 0x99 + (ulong)uVar1 * 0x178) = 1;
  return 0;
}


// ===== 0031a680 gsyncapiCtrlCmdGsyncGetControlStereoLockMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 gsyncapiCtrlCmdGsyncGetControlStereoLockMode_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = (ulong)*(uint *)(param_1 + 0x118) * 0x178 + *(long *)(g_pSys + 0x1e8);
  if (*(long *)(lVar3 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x7be);
    uVar2 = 0x26;
  }
  else {
    lVar1 = gpumgrGetGpuFromId(*param_2);
    if (lVar1 != 0) {
      uVar2 = (**(code **)(lVar3 + 0x170))
                        (lVar1,*(undefined8 *)(lVar3 + 0x90),param_2 + 1,*(code **)(lVar3 + 0x170));
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 0031a720 gsyncapiCtrlCmdGsyncSetControlStereoLockMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

undefined8 gsyncapiCtrlCmdGsyncSetControlStereoLockMode_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = (ulong)*(uint *)(param_1 + 0x118) * 0x178 + *(long *)(g_pSys + 0x1e8);
  if (*(long *)(lVar3 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",1999);
    uVar2 = 0x26;
  }
  else {
    lVar1 = gpumgrGetGpuFromId(*param_2);
    if (lVar1 != 0) {
      uVar2 = (**(code **)(lVar3 + 0x178))
                        (lVar1,*(undefined8 *)(lVar3 + 0x90),param_2[1],*(code **)(lVar3 + 0x178));
      return uVar2;
    }
    uVar2 = 0x1f;
  }
  return uVar2;
}


// ===== 0031a7c0 gsyncapiCtrlCmdGsyncReadRegister_IMPL =====

undefined8 gsyncapiCtrlCmdGsyncReadRegister_IMPL(long param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  
  uVar2 = *(uint *)(param_1 + 0x118);
  lVar3 = *(long *)(g_pSys + 0x1e8);
  lVar4 = (ulong)uVar2 * 0x178 + lVar3;
  if (*(long *)(lVar4 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x7e2);
    return 0x26;
  }
  piVar1 = (int *)(lVar4 + 0x54);
  iVar6 = 0;
  while( true ) {
    if (iVar6 == *piVar1) {
      return 0x1f;
    }
    if (*param_2 == *(int *)(lVar4 + 0x5c)) break;
    iVar6 = iVar6 + 1;
    lVar4 = lVar4 + 0xc;
    if (iVar6 == 4) {
      return 0x1f;
    }
  }
  lVar4 = gpumgrGetGpuFromId();
  if (lVar4 == 0) {
    return 0x1f;
  }
  uVar5 = readregu008_extdeviceTargeted
                    (lVar4,*(undefined8 *)(lVar3 + 0x90 + (ulong)uVar2 * 0x178),(char)param_2[1],
                     (long)param_2 + 5);
  return uVar5;
}


// ===== 0031a890 gsyncapiCtrlCmdGsyncWriteRegister_IMPL =====

undefined8 gsyncapiCtrlCmdGsyncWriteRegister_IMPL(long param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  int iVar6;
  
  uVar2 = *(uint *)(param_1 + 0x118);
  lVar3 = *(long *)(g_pSys + 0x1e8);
  lVar4 = (ulong)uVar2 * 0x178 + lVar3;
  if (*(long *)(lVar4 + 0x90) == 0) {
    nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x7ff);
    return 0x26;
  }
  piVar1 = (int *)(lVar4 + 0x54);
  iVar6 = 0;
  while( true ) {
    if (iVar6 == *piVar1) {
      return 0x1f;
    }
    if (*param_2 == *(int *)(lVar4 + 0x5c)) break;
    iVar6 = iVar6 + 1;
    lVar4 = lVar4 + 0xc;
    if (iVar6 == 4) {
      return 0x1f;
    }
  }
  lVar4 = gpumgrGetGpuFromId();
  if (lVar4 == 0) {
    return 0x1f;
  }
  uVar5 = writeregu008_extdeviceTargeted
                    (lVar4,*(undefined8 *)(lVar3 + 0x90 + (ulong)uVar2 * 0x178),(char)param_2[1],
                     *(undefined1 *)((long)param_2 + 5));
  return uVar5;
}


// ===== 0031a960 gsyncapiCtrlCmdGsyncGetHouseSyncMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncGetHouseSyncMode_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar3 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar2);
    uVar3 = (**(code **)(lVar1 + 400))(uVar3,*(undefined8 *)(lVar1 + 0x90),param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x856);
  return 0x26;
}


// ===== 0031aa00 gsyncapiCtrlCmdGsyncSetHouseSyncMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 gsyncapiCtrlCmdGsyncSetHouseSyncMode_IMPL(long param_1,undefined1 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = (ulong)*(uint *)(param_1 + 0x118) * 0x178;
  lVar1 = *(long *)(g_pSys + 0x1e8) + lVar2;
  if (*(long *)(lVar1 + 0x90) != 0) {
    uVar3 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + lVar2);
    uVar3 = (**(code **)(lVar1 + 0x198))(uVar3,*(undefined8 *)(lVar1 + 0x90),*param_2);
    return uVar3;
  }
  nvAssertFailedNoLog("pGsync && pGsync->pExtDev","src/kernel/gpu/external_device/gsync.c",0x864);
  return 0x26;
}


// ===== 0031aaa0 gsyncIsInstanceValid =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

undefined8 gsyncIsInstanceValid(uint param_1)

{
  long lVar1;
  long *plVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  if (param_1 < 4) {
    lVar1 = *(long *)(g_pSys + 0x1e8) + (ulong)param_1 * 0x178;
    if (*(int *)(lVar1 + 0x54) != 0) {
      lVar4 = gsyncGetMasterableGpu(*(long *)(g_pSys + 0x1e8) + 0x50 + (ulong)param_1 * 0x178);
      if (lVar4 != 0) {
        plVar2 = *(long **)(lVar1 + 0x90);
        pcVar3 = *(code **)(*plVar2 + 0x20);
        uVar5 = (*pcVar3)(lVar4,plVar2,pcVar3);
        return uVar5;
      }
      return 0;
    }
  }
  return 0;
}


// ===== 0031ab20 gsyncFilterEvents =====

uint gsyncFilterEvents(uint param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  cVar1 = (char)param_2;
  uVar4 = 1 << (cVar1 + 4U & 0x1f);
  uVar3 = 1 << (cVar1 + 8U & 0x1f);
  uVar2 = ~uVar4 & param_1;
  if ((~param_1 & (uVar4 | uVar3)) != 0) {
    uVar2 = param_1;
  }
  if ((~uVar2 & (uVar3 | 1 << (param_2 & 0x1f))) == 0) {
    uVar2 = ~uVar3 & uVar2;
  }
  uVar3 = 1 << (cVar1 + 0xcU & 0x1f);
  if ((~uVar2 & (uVar4 | uVar3)) == 0) {
    uVar2 = ~uVar3 & uVar2;
  }
  return uVar2;
}


// ===== 0031ab90 gsyncSignalServiceRequested =====

undefined8 gsyncSignalServiceRequested(uint param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  ulong uVar2;
  
  uVar2 = (ulong)param_1;
  if (param_1 < 4) {
    lVar1 = uVar2 * 0x178 + *(long *)(g_pSys + 0x1e8);
    if (*(int *)(lVar1 + 0x54) != 0) {
      if (*(char *)(lVar1 + 0x99) != '\0') {
        param_2 = gsyncFilterEvents(param_2,param_3);
      }
      CliNotifyGsyncEvent(uVar2 & 0xffffffff,param_2);
      return 0;
    }
  }
  return 0xffff;
}


// ===== 0031abf0 gsyncConvertNewEventToOldEventNum =====

byte gsyncConvertNewEventToOldEventNum(ulong param_1)

{
  byte bVar1;
  
  bVar1 = (param_1 & 0xf) != 0;
  if ((param_1 & 0xf0) != 0) {
    bVar1 = bVar1 | 2;
  }
  if ((param_1 & 0xf000) != 0) {
    bVar1 = bVar1 | 8;
  }
  if ((param_1 & 0xf00) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((param_1 & 0x10000) != 0) {
    bVar1 = bVar1 | 0x10;
  }
  if ((param_1 & 0x20000) != 0) {
    bVar1 = bVar1 | 0x20;
  }
  if ((param_1 & 0x40000) != 0) {
    bVar1 = bVar1 | 0x40;
  }
  if ((param_1 & 0x80000) != 0) {
    bVar1 = bVar1 | 0x80;
  }
  return bVar1;
}


// ===== 0031ac60 gsyncapiConstruct_IMPL =====

undefined8 gsyncapiConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  puVar2 = *(undefined4 **)(param_3 + 0x40);
  lVar4 = __nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (lVar4 != 0) {
    cVar3 = gsyncIsInstanceValid(*puVar2);
    uVar5 = 0x1f;
    if (cVar3 != '\0') {
      uVar1 = *puVar2;
      *(undefined1 *)(param_1 + 0x170) = 0;
      *(undefined4 *)(param_1 + 0x11c) = 0x30f1;
      *(undefined4 *)(param_1 + 0x118) = uVar1;
      *(undefined8 *)(param_1 + 0x120) = 0x100000000;
      puVar6 = (undefined8 *)(param_1 + 0x128);
      do {
        *puVar6 = 0;
        puVar7 = puVar6 + 3;
        puVar6[1] = 0;
        puVar6[2] = 0;
        puVar6 = puVar7;
      } while (puVar7 != (undefined8 *)(param_1 + 0x170));
      uVar5 = 0;
    }
    return uVar5;
  }
  return 0x23;
}


// ===== 0031ad10 gsyncapiControl_IMPL =====

undefined8 gsyncapiControl_IMPL(long param_1,undefined8 param_2,long param_3)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = gsyncIsInstanceValid(*(undefined4 *)(param_1 + 0x118));
  if (cVar1 != '\0') {
    uVar2 = resControl_IMPL(*(undefined8 *)(param_1 + 0xe8),param_2,*(undefined8 *)(param_3 + 0x70))
    ;
    return uVar2;
  }
  return 0x1f;
}


// ===== 0031ad70 __pfx_CliNotifyGsyncEvent =====

void __pfx_CliNotifyGsyncEvent(int param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  undefined1 auStack_88 [8];
  uint uStack_80;
  undefined1 auStack_78 [8];
  int iStack_70;
  undefined1 auStack_68 [40];
  undefined8 uStack_40;
  
  serverutilShareIter(auStack_68,"");
LAB_0031adb0:
  cVar2 = serverutilShareIterNext(auStack_68);
  do {
    if (cVar2 == '\0') {
      return;
    }
    lVar5 = __nvoc_dynamicCast(uStack_40,__nvoc_class_def_NotifShare);
    if ((((lVar5 == 0) || (lVar7 = *(long *)(lVar5 + 0x98), lVar7 == 0)) ||
        (lVar6 = __nvoc_dynamicCast(lVar7,__nvoc_class_def_GSyncApi), lVar6 == 0)) ||
       (*(int *)(lVar6 + 0x118) != param_1)) goto LAB_0031adb0;
    lVar7 = inotifyGetNotificationList_IMPL(lVar7);
    if (*(char *)(lVar6 + 0x170) != '\0') {
      lVar5 = gsyncGetMasterableGpuByInstance(param_1);
      uVar3 = gsyncConvertNewEventToOldEventNum(param_2);
      uVar4 = uVar3 >> 1;
      if (uVar4 == 0) {
        lVar7 = *(long *)(lVar6 + 0x128);
        if ((lVar7 != 0) || ((uVar3 & 1) == 0)) goto LAB_0031afd4;
        *(undefined4 *)(lVar6 + 0x124) = 1;
      }
      else {
        uVar1 = 0x1f;
        if (uVar4 != 0) {
          for (; uVar4 >> uVar1 == 0; uVar1 = uVar1 - 1) {
          }
        }
        if ((uVar1 ^ 0x1f) - 0x18 < 9) {
          lVar7 = *(long *)(lVar6 + 0x128 + (ulong)(0x20 - (uVar1 ^ 0x1f)) * 8);
        }
LAB_0031afd4:
        if (((lVar5 != 0) && (lVar7 != 0)) &&
           (((*(uint *)(lVar6 + 0x120) & uVar3) != 0 && (*(uint *)(lVar6 + 0x124) != uVar3)))) {
          nvDbg_Printf("src/kernel/gpu/external_device/gsync_api.c",0xaf,"CliNotifyGsyncEvent",1,
                       "NVRM: gsync instance 0x%0x has had a status change: 0x%0x\n",param_1,uVar3);
          osEventNotification(lVar5,lVar7,0xffffffff,0,0);
          *(uint *)(lVar6 + 0x124) = uVar3;
        }
      }
      goto LAB_0031adb0;
    }
    uVar8 = gsyncGetMasterableGpuByInstance(param_1);
    if (lVar7 == 0) goto LAB_0031adb0;
    iVar9 = *(int *)(lVar7 + 0x10);
    if ((iVar9 != 0x78) && (*(int *)(lVar7 + 0xc) != 0x14)) break;
    portMemSet(auStack_88,0,0x10);
    uStack_80 = param_2;
    nvDbg_Printf("src/kernel/gpu/external_device/gsync_api.c",0xd2,"CliNotifyGsyncEvent",1,
                 "NVRM: gsync instance 0x%0x has had a status change: 0x%0x\n",param_1,param_2);
    osEventNotification(uVar8,lVar7,0xffffffff,auStack_88,0x10);
    cVar2 = serverutilShareIterNext(auStack_68);
  } while( true );
  if ((iVar9 != 0x7e) && (iVar9 != 0x79)) {
    nvAssertFailedNoLog("(pEventNotification->NotifyType == NV01_EVENT_KERNEL_CALLBACK_EX) || (pEventNotification->NotifyType == NV01_EVENT_OS_EVENT)"
                        ,"src/kernel/gpu/external_device/gsync_api.c",0xe1);
  }
  if (param_2 != 0) {
    uVar10 = 0;
    do {
      iVar9 = (int)uVar10;
      if ((1 << ((byte)uVar10 & 0x1f) & param_2) != 0) {
        uVar11 = uVar10;
        nvDbg_Printf("src/kernel/gpu/external_device/gsync_api.c",0xe8,"CliNotifyGsyncEvent",1,
                     "NVRM: gsync instance 0x%0x has had a status change: %d\n",param_1);
        if (*(int *)(lVar7 + 0x10) == 0x79) {
          osObjectEventNotification
                    (*(undefined4 *)(lVar5 + 0xa0),*(undefined4 *)(lVar5 + 0xa4),
                     *(undefined4 *)(lVar6 + 0x11c),lVar7,uVar10,0,0);
        }
        else {
          portMemSet(auStack_78,0,0x10,uVar11);
          iStack_70 = iVar9;
          if (*(int *)(lVar7 + 0x10) != 0x7e) {
            nvAssertFailedNoLog("pEventNotification->NotifyType == NV01_EVENT_KERNEL_CALLBACK_EX",
                                "src/kernel/gpu/external_device/gsync_api.c",0xf9);
          }
          osEventNotification(uVar8,lVar7,uVar10,auStack_78,0x10);
        }
      }
      uVar10 = (ulong)(iVar9 + 1U);
    } while (param_2 >> ((byte)(iVar9 + 1U) & 0x1f) != 0);
  }
  goto LAB_0031adb0;
}


// ===== 0031ad80 CliNotifyGsyncEvent =====

void CliNotifyGsyncEvent(int param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  undefined1 local_88 [8];
  uint local_80;
  undefined1 local_78 [8];
  int local_70;
  undefined1 local_68 [40];
  undefined8 local_40;
  
  serverutilShareIter(local_68,"");
LAB_0031adb0:
  cVar2 = serverutilShareIterNext(local_68);
  do {
    if (cVar2 == '\0') {
      return;
    }
    lVar5 = __nvoc_dynamicCast(local_40,__nvoc_class_def_NotifShare);
    if ((((lVar5 == 0) || (lVar7 = *(long *)(lVar5 + 0x98), lVar7 == 0)) ||
        (lVar6 = __nvoc_dynamicCast(lVar7,__nvoc_class_def_GSyncApi), lVar6 == 0)) ||
       (*(int *)(lVar6 + 0x118) != param_1)) goto LAB_0031adb0;
    lVar7 = inotifyGetNotificationList_IMPL(lVar7);
    if (*(char *)(lVar6 + 0x170) != '\0') {
      lVar5 = gsyncGetMasterableGpuByInstance(param_1);
      uVar3 = gsyncConvertNewEventToOldEventNum(param_2);
      uVar4 = uVar3 >> 1;
      if (uVar4 == 0) {
        lVar7 = *(long *)(lVar6 + 0x128);
        if ((lVar7 != 0) || ((uVar3 & 1) == 0)) goto LAB_0031afd4;
        *(undefined4 *)(lVar6 + 0x124) = 1;
      }
      else {
        uVar1 = 0x1f;
        if (uVar4 != 0) {
          for (; uVar4 >> uVar1 == 0; uVar1 = uVar1 - 1) {
          }
        }
        if ((uVar1 ^ 0x1f) - 0x18 < 9) {
          lVar7 = *(long *)(lVar6 + 0x128 + (ulong)(0x20 - (uVar1 ^ 0x1f)) * 8);
        }
LAB_0031afd4:
        if (((lVar5 != 0) && (lVar7 != 0)) &&
           (((*(uint *)(lVar6 + 0x120) & uVar3) != 0 && (*(uint *)(lVar6 + 0x124) != uVar3)))) {
          nvDbg_Printf("src/kernel/gpu/external_device/gsync_api.c",0xaf,"CliNotifyGsyncEvent",1,
                       "NVRM: gsync instance 0x%0x has had a status change: 0x%0x\n",param_1,uVar3);
          osEventNotification(lVar5,lVar7,0xffffffff,0,0);
          *(uint *)(lVar6 + 0x124) = uVar3;
        }
      }
      goto LAB_0031adb0;
    }
    uVar8 = gsyncGetMasterableGpuByInstance(param_1);
    if (lVar7 == 0) goto LAB_0031adb0;
    iVar9 = *(int *)(lVar7 + 0x10);
    if ((iVar9 != 0x78) && (*(int *)(lVar7 + 0xc) != 0x14)) break;
    portMemSet(local_88,0,0x10);
    local_80 = param_2;
    nvDbg_Printf("src/kernel/gpu/external_device/gsync_api.c",0xd2,"CliNotifyGsyncEvent",1,
                 "NVRM: gsync instance 0x%0x has had a status change: 0x%0x\n",param_1,param_2);
    osEventNotification(uVar8,lVar7,0xffffffff,local_88,0x10);
    cVar2 = serverutilShareIterNext(local_68);
  } while( true );
  if ((iVar9 != 0x7e) && (iVar9 != 0x79)) {
    nvAssertFailedNoLog("(pEventNotification->NotifyType == NV01_EVENT_KERNEL_CALLBACK_EX) || (pEventNotification->NotifyType == NV01_EVENT_OS_EVENT)"
                        ,"src/kernel/gpu/external_device/gsync_api.c",0xe1);
  }
  if (param_2 != 0) {
    uVar10 = 0;
    do {
      iVar9 = (int)uVar10;
      if ((1 << ((byte)uVar10 & 0x1f) & param_2) != 0) {
        uVar11 = uVar10;
        nvDbg_Printf("src/kernel/gpu/external_device/gsync_api.c",0xe8,"CliNotifyGsyncEvent",1,
                     "NVRM: gsync instance 0x%0x has had a status change: %d\n",param_1);
        if (*(int *)(lVar7 + 0x10) == 0x79) {
          osObjectEventNotification
                    (*(undefined4 *)(lVar5 + 0xa0),*(undefined4 *)(lVar5 + 0xa4),
                     *(undefined4 *)(lVar6 + 0x11c),lVar7,uVar10,0,0);
        }
        else {
          portMemSet(local_78,0,0x10,uVar11);
          local_70 = iVar9;
          if (*(int *)(lVar7 + 0x10) != 0x7e) {
            nvAssertFailedNoLog("pEventNotification->NotifyType == NV01_EVENT_KERNEL_CALLBACK_EX",
                                "src/kernel/gpu/external_device/gsync_api.c",0xf9);
          }
          osEventNotification(uVar8,lVar7,uVar10,local_78,0x10);
        }
      }
      uVar10 = (ulong)(iVar9 + 1U);
    } while (param_2 >> ((byte)(iVar9 + 1U) & 0x1f) != 0);
  }
  goto LAB_0031adb0;
}


// ===== 0031b110 dacAttachExternalDevice_Base =====

undefined8 dacAttachExternalDevice_Base(void)

{
  return 0;
}


// ===== 0031b120 extdevValidate_Default =====

bool extdevValidate_Default(undefined8 param_1,long param_2)

{
  return param_2 != 0;
}


// ===== 0031b130 extdevDestroy_Base =====

void extdevDestroy_Base(undefined8 param_1,undefined8 *param_2)

{
  portMemFree(*param_2);
  return;
}


// ===== 0031b140 extdevConstruct_Base =====

long * extdevConstruct_Base(undefined8 param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  
  lVar1 = portMemAllocNonPaged(0x50);
  *param_2 = lVar1;
  plVar2 = (long *)0x0;
  if (lVar1 != 0) {
    portMemSet(lVar1,0,0x50);
    *(code **)(*param_2 + 0x10) = extdevDestroy_Base;
    *(code **)(*param_2 + 0x18) = dacAttachExternalDevice_Base;
    *(undefined8 *)*param_2 = 0;
    *(undefined8 *)(*param_2 + 8) = 0;
    *(code **)(*param_2 + 0x20) = extdevValidate_Default;
    *(undefined4 *)((long)param_2 + 0x14) = 1;
    *(undefined1 *)(param_2 + 5) = 0;
    *(undefined4 *)((long)param_2 + 0x2c) = 1000000000;
    plVar2 = param_2;
  }
  return plVar2;
}


// ===== 0031b1d0 extdevDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

void extdevDestroy(undefined8 param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = gsyncmgrGetGsync();
  if ((lVar2 != 0) && (*(long **)(lVar2 + 0x40) != (long *)0x0)) {
    pcVar1 = *(code **)(**(long **)(lVar2 + 0x40) + 0x10);
    if (pcVar1 == extdevDestroy_Base) {
      portMemFree();
    }
    else {
      (*pcVar1)(param_1);
    }
    if (*(int *)(*(long *)(lVar2 + 0x40) + 8) == 0) {
      portMemFree();
      *(undefined8 *)(lVar2 + 0x40) = 0;
      return;
    }
  }
  return;
}


// ===== 0031b260 extdevServiceWatchdog =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 extdevServiceWatchdog(undefined8 param_1,undefined8 param_2)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = gsyncmgrGetGsync();
  if ((lVar2 != 0) && (plVar1 = *(long **)(lVar2 + 0x40), plVar1 != (long *)0x0)) {
    *(undefined1 *)(plVar1 + 5) = 0;
    uVar3 = (**(code **)(*plVar1 + 0x40))(param_1,param_2);
    return uVar3;
  }
  return 0xffff;
}


// ===== 0031b2c0 extdevScheduleWatchdog =====

undefined8 extdevScheduleWatchdog(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(char *)(param_2 + 0x28) != '\0') {
    return 0xffff;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x1b88);
  *(undefined1 *)(param_2 + 0x28) = 1;
  uVar1 = tmrEventScheduleRel_IMPL
                    (uVar1,*(undefined8 *)(param_2 + 0x30 + (ulong)*(uint *)(param_1 + 0x7a4) * 8),
                     *(undefined4 *)(param_2 + 0x2c));
  if ((int)uVar1 != 0) {
    *(undefined1 *)(param_2 + 0x28) = 0;
  }
  return uVar1;
}


// ===== 0031b310 extdevCancelWatchdog =====

undefined8 extdevCancelWatchdog(long param_1,long param_2)

{
  tmrEventCancel_IMPL(*(undefined8 *)(param_1 + 0x1b88),
                      *(undefined8 *)(param_2 + 0x30 + (ulong)*(uint *)(param_1 + 0x7a4) * 8));
  *(undefined1 *)(param_2 + 0x28) = 0;
  return 0;
}


// ===== 0031b350 writeregu008_extdeviceTargeted =====

undefined8
writeregu008_extdeviceTargeted(long param_1,long param_2,undefined1 param_3,undefined1 param_4)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 local_9;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 0x7f0);
    if (0xf < uVar1) {
      uVar1 = *(uint *)(param_2 + 0x10);
    }
    local_9 = param_4;
    uVar2 = i2c_extdeviceHelper(param_1,param_2,uVar1,param_3,&local_9,1);
    return uVar2;
  }
  return 0xffff;
}


// ===== 0031b3a0 readregu008_extdevice =====

void readregu008_extdevice(long param_1,long param_2,undefined1 param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x7f0);
  if (0xf < uVar1) {
    uVar1 = *(uint *)(param_2 + 0x10);
  }
  i2c_extdeviceHelper(param_1,param_2,uVar1,param_3,param_4,0);
  return;
}


// ===== 0031b3d0 readregu008_extdeviceTargeted =====

undefined8
readregu008_extdeviceTargeted(long param_1,long param_2,undefined1 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xffff;
  }
  if (*(uint *)(param_1 + 0x7f0) < 0x10) {
    uVar1 = i2c_extdeviceHelper(param_1,param_2,*(uint *)(param_1 + 0x7f0),param_3,param_4,0);
    return uVar1;
  }
  uVar1 = i2c_extdeviceHelper(param_1,param_2,*(undefined4 *)(param_2 + 0x10),param_3,param_4,0);
  return uVar1;
}


// ===== 0031b420 extdevGsyncService =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void extdevGsyncService(undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                       undefined1 param_5)

{
  long *plVar1;
  long lVar2;
  
  lVar2 = gsyncmgrGetGsync();
  if ((lVar2 != 0) && (plVar1 = *(long **)(lVar2 + 0x40), plVar1 != (long *)0x0)) {
    (**(code **)(*plVar1 + 0x38))(param_1,plVar1,param_2,param_3,param_4,param_5);
    return;
  }
  return;
}


// ===== 0031b4a0 extdevGetBoundHeadsAndDisplayIds =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void extdevGetBoundHeadsAndDisplayIds(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar1 = *(undefined4 *)(param_1 + 0x3b34);
  uVar2 = *(undefined4 *)(param_1 + 0x3b3c);
  local_38 = 0;
  local_30 = 0;
  portMemSet(param_2,0,0x20);
  iVar3 = (**(code **)(param_1 + 0x3b90))(param_1 + 0x3b58,uVar1,uVar2,0x20800ac0,&local_38,0x10);
  if (iVar3 != 0) {
    nvDbg_Printf("src/kernel/gpu/external_device/kern_external_device.c",0x16a,
                 "extdevGetBoundHeadsAndDisplayIds",4,
                 "NVRM: Extdev getting display IDs have failed!\n");
    return;
  }
  portMemCopy(param_2,0x20,&local_38,0x10);
  return;
}


// ===== 0031b570 kflcnIntrRetrigger_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnIntrRetrigger_GA100(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x4c8))(param_1,param_2,1000,1);
  return;
}


// ===== 0031b590 kflcnMaskImemAddr_GA100 =====

uint kflcnMaskImemAddr_GA100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return param_3 & 0xfffffc;
}


// ===== 0031b5a0 kflcnMaskDmemAddr_GA100 =====

uint kflcnMaskDmemAddr_GA100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return param_3 & 0xfffffc;
}


// ===== 0031b5b0 kflcnFatalHwErrorCodeToString_GA100 =====

char * kflcnFatalHwErrorCodeToString_GA100(void)

{
  return "Unknown";
}


// ===== 0031b5c0 _kflcnWaitForScrubbingToFinish =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint _kflcnWaitForScrubbingToFinish(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0xf4);
  return uVar1 >> 0xc & 1 ^ 1;
}


// ===== 0031b5f0 kflcnIsRiscvActive_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

byte kflcnIsRiscvActive_GA102(undefined8 param_1,long param_2)

{
  byte bVar1;
  
  bVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x388);
  return bVar1 >> 7;
}


// ===== 0031b610 kflcnIsRiscvSelected_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool kflcnIsRiscvSelected_GA102(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x668);
  return (uVar1 & 0x10) != 0 || (uVar1 & 0xffff0000) == 0xbadf0000;
}


// ===== 0031b650 kflcnResetIntoRiscv_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kflcnResetIntoRiscv_GA102(undefined8 param_1,long *param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)param_2[0xa5])();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_2 + 0x108))(param_1,param_2);
    if (iVar1 != 0) {
      nvAssertOkFailedNoLog
                (iVar1,"kflcnResetHw(pGpu, pKernelFlcn)",
                 "src/kernel/gpu/falcon/arch/ampere/kernel_falcon_ga102.c",0x5b);
    }
    iVar1 = (*(code *)param_2[0xa6])(param_1,param_2);
    if (iVar1 == 0) {
      (*(code *)param_2[0x9f])(param_1,param_2,1);
      *(undefined1 *)(param_2 + 0xc3) = 1;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,"kflcnWaitForResetToFinish_HAL(pGpu, pKernelFlcn)",
                 "src/kernel/gpu/falcon/arch/ampere/kernel_falcon_ga102.c",0x5c);
    }
    return iVar1;
  }
  nvAssertOkFailedNoLog
            (iVar1,"kflcnPreResetWait_HAL(pGpu, pKernelFlcn)",
             "src/kernel/gpu/falcon/arch/ampere/kernel_falcon_ga102.c",0x5a);
  return iVar1;
}


// ===== 0031b750 kflcnRiscvProgramBcr_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnRiscvProgramBcr_GA102(undefined8 param_1,long param_2,uint param_3)

{
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x668,(param_3 & 1) << 8 | 0x11);
  return;
}


// ===== 0031b780 kflcnSwitchToFalcon_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnSwitchToFalcon_GA102(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  ulong uVar3;
  undefined1 local_40 [32];
  
  cVar1 = (**(code **)(param_2 + 0x4e0))();
  if ((cVar1 != '\0') &&
     (uVar3 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x668), (uVar3 & 0x10) != 0)) {
    (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x668,0);
    timeoutSet(param_1 + 0x1af0,local_40,0,0);
    do {
      uVar3 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x668);
      if ((uVar3 & 1) != 0) {
        *(undefined1 *)(param_2 + 0x618) = 0;
        return;
      }
      if ((((param_1 == 0) || (*(char *)(param_1 + 0x44f) != '\0')) ||
          (*(char *)(param_1 + 0x450) != '\0')) ||
         ((*(char *)(param_1 + 0x451) != '\0' || (*(char *)(param_1 + 0x461) != '\0')))) {
        iVar2 = 0x10;
        break;
      }
      if (*(char *)(param_1 + 0x44c) == '\0') {
        iVar2 = 0xf;
        break;
      }
      iVar2 = timeoutCheck(param_1 + 0x1af0,local_40,0xa1);
    } while (iVar2 == 0);
    nvAssertOkFailedNoLog
              (iVar2,"Failed to switch core to Falcon mode",
               "src/kernel/gpu/falcon/arch/ampere/kernel_falcon_ga102.c",0xa9);
  }
  return;
}


// ===== 0031b8e0 kflcnPreResetWait_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnPreResetWait_GA102(long param_1,long param_2)

{
  int iVar1;
  undefined1 local_40 [24];
  
  if ((*(char *)(param_1 + 0x446) == '\0') && (*(char *)(param_1 + 0x490e) != '\0')) {
    return 0;
  }
  iVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0xf4);
  if (*(char *)(param_1 + 0x446) == '\0') {
    if (*(char *)(param_1 + 0x490e) == '\0') {
      timeoutSet(param_1 + 0x1af0,local_40,0x96,100);
    }
  }
  else {
    timeoutSet(param_1 + 0x1af0,local_40,300000,100);
  }
  while ((-1 < iVar1 && (iVar1 = timeoutCheck(param_1 + 0x1af0,local_40,0xd6), iVar1 != 0x65))) {
    osSpinLoop();
    iVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0xf4);
  }
  return 0;
}


// ===== 0031b9e0 kflcnWaitForResetToFinish_GA102 =====

undefined8 kflcnWaitForResetToFinish_GA102(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x44f) == '\0')) &&
      (*(char *)(param_1 + 0x450) == '\0')) &&
     ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))) {
    uVar1 = timeoutCondWait(param_1 + 0x1af0,0,_kflcnWaitForScrubbingToFinish,param_2,0x108);
    return uVar1;
  }
  return 0x10;
}


// ===== 0031ba40 kflcnWaitForHaltRiscv_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kflcnWaitForHaltRiscv_GA102(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined1 local_40 [24];
  
  iVar1 = 0;
  timeoutSet(param_1 + 0x1af0,local_40);
  while( true ) {
    uVar2 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x388);
    if ((uVar2 & 0x10) != 0) {
      return iVar1;
    }
    iVar1 = timeoutCheck(param_1 + 0x1af0,local_40,0x125);
    if (iVar1 == 0x65) break;
    osSpinLoop();
  }
  nvDbg_Printf("src/kernel/gpu/falcon/arch/ampere/kernel_falcon_ga102.c",0x128,
               "kflcnWaitForHaltRiscv_GA102",4,"NVRM: Timeout waiting for RISC-V to halt\n");
  return 0x65;
}


// ===== 0031bb00 kflcnRiscvReadIntrStatus_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kflcnRiscvReadIntrStatus_GA102(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,8);
  uVar2 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x528);
  uVar3 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x52c);
  return uVar3 & uVar1 & uVar2;
}


// ===== 0031bb70 kflcnIcdReadCmdReg_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnIcdReadCmdReg_GA102(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x3d0);
  return;
}


// ===== 0031bb90 kflcnRiscvIcdReadRdata_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnRiscvIcdReadRdata_GA102(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,1000);
  uVar2 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x3e4);
  return CONCAT44(uVar1,uVar2);
}


// ===== 0031bbe0 kflcnRiscvIcdWriteAddress_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnRiscvIcdWriteAddress_GA102(undefined8 param_1,long param_2,ulong param_3)

{
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x3d8,param_3 >> 0x20);
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x3d4,param_3 & 0xffffffff);
  return;
}


// ===== 0031bc30 kflcnIcdWriteCmdReg_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnIcdWriteCmdReg_GA102(undefined8 param_1,long param_2,undefined4 param_3)

{
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x3d0,param_3);
  return;
}


// ===== 0031bc50 kflcnDumpTracepc_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnDumpTracepc_GA102(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  ulong uVar10;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x404);
  uVar2 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x408);
  if ((~uVar1 & 0xbadf0000) == 0) {
    if ((~uVar2 & 0xbadf0000) == 0) {
      pcVar8 = "NVRM: Trace buffer blocked, skipping.\n";
      uVar6 = 0x18b;
      goto LAB_0031be11;
    }
  }
  else {
    uVar7 = uVar1 >> 0x10 & 0xff;
    if ((byte)(uVar1 >> 0x10) < 0x41) {
      uVar2 = uVar2 >> 0x18;
      uVar1 = uVar1 & 0xff;
      uVar10 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x400);
      if (uVar1 == uVar2) {
        if ((uVar10 & 0x40000000) == 0) {
          *(undefined4 *)(param_3 + 0x58) = 0;
          goto LAB_0031bd95;
        }
LAB_0031bdcf:
        uVar9 = (uVar7 - uVar1) + uVar2;
        *(uint *)(param_3 + 0x58) = uVar9;
        if (uVar9 == 0) goto LAB_0031bd95;
      }
      else {
        if (uVar2 <= uVar1) goto LAB_0031bdcf;
        uVar9 = uVar2 - uVar1;
        *(uint *)(param_3 + 0x58) = uVar9;
      }
      uVar10 = 0;
      do {
        uVar3 = 0;
        if (uVar2 < (uint)uVar10) {
          uVar3 = uVar7;
        }
        uVar2 = uVar2 + uVar3;
        (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x404,uVar2 - (uint)uVar10);
        uVar4 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x410);
        uVar5 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x40c);
        *(ulong *)(param_3 + 0x60 + uVar10 * 8) = CONCAT44(uVar4,uVar5);
        uVar10 = uVar10 + 1;
      } while (uVar10 != uVar9);
LAB_0031bd95:
      (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x404,uVar1);
      return;
    }
  }
  pcVar8 = "NVRM: Trace buffer larger than expected. Bailing!\n";
  uVar6 = 0x193;
LAB_0031be11:
  nvDbg_Printf("src/kernel/gpu/falcon/arch/ampere/kernel_falcon_ga102.c",uVar6,
               "kflcnDumpTracepc_GA102",4,pcVar8);
  return;
}


// ===== 0031be70 kflcnCoreDumpPc_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnCoreDumpPc_GA102(undefined8 param_1,long param_2,ulong *param_3)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x3ec);
  *param_3 = (ulong)uVar1 | 0xfa11bacc00000000;
  return 0;
}


// ===== 0031beb0 kflcnDumpCoreRegs_GA102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnDumpCoreRegs_GA102(undefined8 param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x388);
  param_3[1] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x528);
  param_3[2] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x52c);
  param_3[3] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x3ec);
  *param_3 = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x534);
  param_3[4] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x500);
  param_3[0x11] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x504);
  param_3[0x12] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x50c);
  param_3[0x13] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x508);
  param_3[0x14] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x510);
  param_3[0x15] = uVar1;
  return;
}


// ===== 0031bff0 kflcnGetEccInterruptMask_GB100 =====

undefined8 kflcnGetEccInterruptMask_GB100(void)

{
  return 0x4000;
}


// ===== 0031c000 kflcnGetFatalHwErrorStatus_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnGetFatalHwErrorStatus_GB100(undefined8 param_1,long param_2,uint *param_3)

{
  uint uVar1;
  
  if (param_3 == (uint *)0x0) {
    nvAssertFailedNoLog("pErrorStatus != NULL",
                        "src/kernel/gpu/falcon/arch/blackwell/kernel_falcon_gb100.c",0x42);
    return 0x1f;
  }
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x700);
  if ((uVar1 & 0xfff00000) != 0xbad00000) {
    *param_3 = uVar1;
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/falcon/arch/blackwell/kernel_falcon_gb100.c",0x48,
               "kflcnGetFatalHwErrorStatus_GB100",4,
               "NVRM: Cannot read NV_PRISCV_RISCV_FAULT_CONTAINMENT_SRCSTAT (0x%x)\n",uVar1);
  return 0x42;
}


// ===== 0031c0b0 kflcnFatalHwErrorCodeToString_GB100 =====

char * kflcnFatalHwErrorCodeToString_GB100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  byte bVar1;
  char *pcVar2;
  
  if ((param_3 != 0) && ((param_3 - 1 & param_3) == 0)) {
    bVar1 = (param_3 & 0xaaaaaaaa) != 0 | (0xffff < param_3) << 4 |
            ((param_3 & 0xff00ff00) != 0) << 3 | ((param_3 & 0xf0f0f0f0) != 0) << 2 |
            ((param_3 & 0xcccccccc) != 0) * '\x02';
    if (bVar1 == 10) {
      pcVar2 = "TKE Watchdog Timeout";
    }
    else if (bVar1 < 0xb) {
      if (bVar1 == 5) {
        pcVar2 = "DCACHE ECC";
      }
      else if (bVar1 < 6) {
        if (bVar1 == 2) {
          pcVar2 = "ITCM ECC";
        }
        else if (bVar1 < 3) {
          pcVar2 = "FB Poison";
          if (bVar1 != 0) {
            pcVar2 = "BROM ECC";
          }
        }
        else {
          pcVar2 = "DTCM ECC";
          if (bVar1 != 3) {
            pcVar2 = "ICACHE ECC";
          }
        }
      }
      else {
        pcVar2 = "SE Logic";
        if (((bVar1 != 8) && (pcVar2 = "SE Keyslot ECC", bVar1 != 9)) &&
           (pcVar2 = "RISCV Delayed Lockstep", bVar1 != 6)) {
          pcVar2 = "TKE Register ECC";
        }
      }
    }
    else if (bVar1 == 0x13) {
      pcVar2 = "Engine Fault 3";
    }
    else if (bVar1 < 0x14) {
      if (bVar1 == 0x10) {
        pcVar2 = "Engine Fault 0";
      }
      else if (bVar1 < 0x11) {
        pcVar2 = "FBIF ECC";
        if ((bVar1 != 0xb) && (pcVar2 = "Unknown", bVar1 == 0xc)) {
          pcVar2 = "MPU RAM ECC";
        }
      }
      else {
        pcVar2 = "Engine Fault 1";
        if (bVar1 != 0x11) {
          pcVar2 = "Engine Fault 2";
        }
      }
    }
    else {
      pcVar2 = "Engine Fault 6";
      if (bVar1 != 0x16) {
        if (bVar1 < 0x17) {
          pcVar2 = "Engine Fault 4";
          if (bVar1 != 0x14) {
            pcVar2 = "Engine Fault 5";
          }
        }
        else {
          pcVar2 = "Unknown";
          if (bVar1 == 0x17) {
            pcVar2 = "Engine Fault 7";
          }
        }
      }
    }
    return pcVar2;
  }
  nvAssertFailedNoLog("ONEBITSET(errorCode)",
                      "src/kernel/gpu/falcon/arch/blackwell/kernel_falcon_gb100.c",0x5c);
  return "Unknown";
}


// ===== 0031c2e0 kflcnDumpCoreRegs_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnDumpCoreRegs_GB202(undefined8 param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x388);
  param_3[1] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x528);
  param_3[2] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x52c);
  param_3[3] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x3ec);
  *param_3 = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x534);
  param_3[4] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x420);
  param_3[0x11] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x424);
  param_3[0x12] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x42c);
  param_3[0x13] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x428);
  param_3[0x14] = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x430);
  param_3[0x15] = uVar1;
  return;
}


// ===== 0031c420 kcrashcatEngineReadDmem_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kcrashcatEngineReadDmem_TU102(long *param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((param_2 & 3) != 0) {
    nvCheckFailedNoLog(4,"(offset & (sizeof(NvU32) - 1)) == 0",
                       "src/kernel/gpu/falcon/arch/turing/kernel_crashcat_engine_tu102.c",0x28);
    return;
  }
  if ((param_3 & 3) == 0) {
    uVar1 = *(uint *)(param_1 + 0x13);
    uVar2 = (**(code **)(*param_1 + 0xb8))(param_1[0x12],param_1,param_2);
    (**(code **)(*param_1 + 0xb0))
              (param_1[0x12],param_1,(uVar1 & 0xff) * 8 + 0x1c0,uVar2 | 0x2000000);
    if (param_3 >> 2 != 0) {
      puVar4 = param_4;
      do {
        puVar5 = puVar4 + 1;
        uVar3 = (**(code **)(*param_1 + 0xa8))(param_1[0x12],param_1,(uVar1 & 0xff) * 8 + 0x1c4);
        *puVar4 = uVar3;
        puVar4 = puVar5;
      } while (puVar5 != (undefined4 *)((ulong)((param_3 >> 2) * 4) + (long)param_4));
    }
    return;
  }
  nvCheckFailedNoLog(4,"(size & (sizeof(NvU32) - 1)) == 0",
                     "src/kernel/gpu/falcon/arch/turing/kernel_crashcat_engine_tu102.c",0x29);
  return;
}


// ===== 0031c540 kcrashcatEngineGetWFL0Offset_TU102 =====

undefined8 kcrashcatEngineGetWFL0Offset_TU102(void)

{
  return 0x94;
}


// ===== 0031c550 kcrashcatEngineGetScratchOffsets_TU102 =====

undefined1 * kcrashcatEngineGetScratchOffsets_TU102(undefined8 param_1,uint param_2)

{
  if (param_2 < 8) {
    return scratchOffsetTable_1 + (ulong)param_2 * 0x14;
  }
  nvDbg_Printf("src/kernel/gpu/falcon/arch/turing/kernel_crashcat_engine_tu102.c",0x47,
               "kcrashcatEngineGetScratchOffsets_TU102",4,"NVRM: unknown CrashCat scratch ID %u\n",
               param_2);
  return (undefined1 *)0x0;
}


// ===== 0031c5b0 _kflcnMemScrubbingFinished =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

bool _kflcnMemScrubbingFinished(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x10c);
  return (uVar1 & 6) == 0;
}


// ===== 0031c5d0 s_riscvIsIcdNotBusy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint s_riscvIsIcdNotBusy(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x5a8))();
  return uVar1 >> 0xf & 1 ^ 1;
}


// ===== 0031c5f0 kflcnRegRead_TU102 =====

void kflcnRegRead_TU102(long param_1,long param_2,int param_3)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x61c) + param_3,0);
  return;
}


// ===== 0031c610 kflcnRegWrite_TU102 =====

void kflcnRegWrite_TU102(long param_1,long param_2,int param_3,undefined4 param_4)

{
  regWrite032(param_1 + 0x3a18,0,0,param_3 + *(int *)(param_2 + 0x61c),param_4,0);
  return;
}


// ===== 0031c640 kflcnRiscvRegRead_TU102 =====

void kflcnRiscvRegRead_TU102(long param_1,long param_2,int param_3)

{
  regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x620) + param_3,0);
  return;
}


// ===== 0031c660 kflcnRiscvRegWrite_TU102 =====

void kflcnRiscvRegWrite_TU102(long param_1,long param_2,int param_3,undefined4 param_4)

{
  regWrite032(param_1 + 0x3a18,0,0,param_3 + *(int *)(param_2 + 0x620),param_4,0);
  return;
}


// ===== 0031c690 kflcnIsRiscvCpuEnabled_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kflcnIsRiscvCpuEnabled_TU102(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0xf4);
  return uVar1 >> 10 & 1;
}


// ===== 0031c6c0 kflcnIsRiscvActive_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kflcnIsRiscvActive_TU102(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x240);
  return uVar1 & 1;
}


// ===== 0031c6e0 kflcnIsRiscvSelected_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnIsRiscvSelected_TU102(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x4e8))();
  return;
}


// ===== 0031c6f0 kflcnReset_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

uint kflcnReset_TU102(long param_1,long *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (*(code *)param_2[0xa5])();
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,"kflcnPreResetWait_HAL(pGpu, pKernelFlcn)",
               "src/kernel/gpu/falcon/arch/turing/kernel_falcon_tu102.c",0xb8);
    return uVar1;
  }
  iVar2 = (**(code **)(*param_2 + 0x108))(param_1,param_2);
  if (iVar2 != 0) {
    nvAssertOkFailedNoLog
              (iVar2,"kflcnResetHw(pGpu, pKernelFlcn)",
               "src/kernel/gpu/falcon/arch/turing/kernel_falcon_tu102.c",0xb9);
  }
  uVar1 = (*(code *)param_2[0xa6])(param_1,param_2);
  if ((uVar1 & 0xffffffef) == 0) {
    if (uVar1 != 0x10) {
      (*(code *)param_2[0xa0])(param_1,param_2,(code *)param_2[0xa0]);
      (*(code *)param_2[0x99])
                (param_1,param_2,0x84,*(undefined4 *)(param_1 + 0x8e8),(code *)param_2[0x99]);
      return 0;
    }
  }
  else {
    nvAssertFailedNoLog("(status == NV_OK) || (status == NV_ERR_GPU_IN_FULLCHIP_RESET)",
                        "src/kernel/gpu/falcon/arch/turing/kernel_falcon_tu102.c",0xbb);
  }
  return uVar1;
}


// ===== 0031c820 kflcnResetIntoRiscv_TU102 =====

ulong kflcnResetIntoRiscv_TU102(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = kflcnReset_TU102();
  if ((int)uVar1 == 0) {
    *(undefined1 *)(param_2 + 0x618) = 1;
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,"kflcnReset_TU102(pGpu, pKernelFlcn)",
             "src/kernel/gpu/falcon/arch/turing/kernel_falcon_tu102.c",0xd2);
  return uVar1 & 0xffffffff;
}


// ===== 0031c880 kflcnSwitchToFalcon_TU102 =====

void kflcnSwitchToFalcon_TU102(undefined8 param_1,long param_2)

{
  *(undefined1 *)(param_2 + 0x618) = 0;
  return;
}


// ===== 0031c890 kflcnStartCpu_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnStartCpu_TU102(undefined8 param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x100);
  if ((uVar1 & 0x40) != 0) {
    (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x130,2);
    return;
  }
  (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x100,2);
  return;
}


// ===== 0031c8f0 kflcnDisableCtxReq_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnDisableCtxReq_TU102(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x24,0);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x24,uVar1 | 0x80,0);
  (**(code **)(param_2 + 0x4c8))(param_1,param_2,0x10c,0);
  return;
}


// ===== 0031c970 kflcnWaitForResetToFinish_TU102 =====

undefined8 kflcnWaitForResetToFinish_TU102(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if ((((param_1 != 0) && (*(char *)(param_1 + 0x44f) == '\0')) &&
      (*(char *)(param_1 + 0x450) == '\0')) &&
     ((*(char *)(param_1 + 0x451) == '\0' && (*(char *)(param_1 + 0x461) == '\0')))) {
    uVar1 = timeoutCondWait(param_1 + 0x1af0,0,_kflcnMemScrubbingFinished,param_2,0x13f);
    return uVar1;
  }
  return 0x10;
}


// ===== 0031c9d0 kflcnWaitForHalt_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kflcnWaitForHalt_TU102(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined1 local_40 [24];
  
  iVar1 = 0;
  timeoutSet(param_1 + 0x1af0,local_40);
  while( true ) {
    uVar2 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x100);
    if ((uVar2 & 0x10) != 0) {
      return iVar1;
    }
    iVar1 = timeoutCheck(param_1 + 0x1af0,local_40,0x15c);
    if (iVar1 == 0x65) break;
    osSpinLoop();
  }
  nvDbg_Printf("src/kernel/gpu/falcon/arch/turing/kernel_falcon_tu102.c",0x15f,
               "kflcnWaitForHalt_TU102",4,"NVRM: Timeout waiting for Falcon to halt\n");
  return 0x65;
}


// ===== 0031ca90 kflcnReadIntrStatus_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kflcnReadIntrStatus_TU102(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,8);
  uVar2 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x18);
  uVar3 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x1c);
  return uVar3 & uVar1 & uVar2;
}


// ===== 0031cb00 kflcnRiscvReadIntrStatus_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kflcnRiscvReadIntrStatus_TU102(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,8);
  uVar2 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x2b4);
  uVar3 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x2b8);
  return uVar3 & uVar1 & uVar2;
}


// ===== 0031cb70 kflcnMaskImemAddr_TU102 =====

uint kflcnMaskImemAddr_TU102(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return param_3 & 0xfffc;
}


// ===== 0031cb80 kflcnMaskDmemAddr_TU102 =====

uint kflcnMaskDmemAddr_TU102(undefined8 param_1,undefined8 param_2,uint param_3)

{
  return param_3 & 0xfffc;
}


// ===== 0031cb90 kflcnIcdReadCmdReg_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnIcdReadCmdReg_TU102(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x300);
  return;
}


// ===== 0031cbb0 kflcnRiscvIcdReadRdata_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnRiscvIcdReadRdata_TU102(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x318);
  uVar2 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x30c);
  return CONCAT44(uVar1,uVar2);
}


// ===== 0031cc00 kflcnRiscvIcdWriteAddress_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnRiscvIcdWriteAddress_TU102(undefined8 param_1,long param_2,ulong param_3)

{
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x310,param_3 >> 0x20);
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x304,param_3 & 0xffffffff);
  return;
}


// ===== 0031cc50 kflcnIcdWriteCmdReg_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnIcdWriteCmdReg_TU102(undefined8 param_1,long param_2,undefined4 param_3)

{
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x300,param_3);
  return;
}


// ===== 0031cc70 kflcnRiscvIcdWaitForIdle_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

uint kflcnRiscvIcdWaitForIdle_TU102(long param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 local_40 [32];
  
  timeoutSet(param_1 + 0x1af0,local_40,0x1e848,4);
  iVar1 = timeoutCondWait(param_1 + 0x1af0,local_40,s_riscvIsIcdNotBusy,param_2,0x221);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(param_2 + 0x5a8))(param_1,param_2);
    return uVar2 >> 8 & 0x40;
  }
  return 0x65;
}


// ===== 0031cd00 kflcnRiscvIcdReadMem_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kflcnRiscvIcdReadMem_TU102
          (undefined8 param_1,long param_2,ulong param_3,ulong param_4,undefined8 *param_5)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if ((((param_4 - 4 & 0xfffffffffffffffb) != 0) && (1 < param_4 - 1)) ||
     ((param_4 - 1 & param_3) != 0)) {
    return 0x1f;
  }
  uVar4 = 0;
  for (; param_4 != 1; param_4 = param_4 >> 1) {
    uVar4 = uVar4 + 1;
  }
  cVar1 = (**(code **)(param_2 + 0x4e8))(param_1,param_2);
  if ((cVar1 != '\0') && (iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2), iVar2 != 0x65)) {
    (**(code **)(param_2 + 0x5b8))(param_1,param_2,param_3);
    (**(code **)(param_2 + 0x5c0))(param_1,param_2,(uVar4 & 3) << 6 | 0x1000a);
    iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
    if (iVar2 != 0) {
      uVar5 = 0x1f;
      if (iVar2 != 0x40) {
        uVar5 = 0x40;
      }
      return uVar5;
    }
    uVar3 = (**(code **)(param_2 + 0x5b0))(param_1,param_2);
    *param_5 = uVar3;
    return 0;
  }
  return 0x40;
}


// ===== 0031ce70 kflcnRiscvIcdReadReg_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kflcnRiscvIcdReadReg_TU102(undefined8 param_1,long param_2,uint param_3,undefined8 *param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0x1f;
  if (param_3 < 0x20) {
    if (param_3 != 0) {
      cVar1 = (**(code **)(param_2 + 0x4e8))();
      if (cVar1 != '\0') {
        iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
        if (iVar2 != 0x65) {
          (**(code **)(param_2 + 0x5c0))(param_1,param_2,param_3 << 8 | 8);
          iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
          if (iVar2 != 0) {
            uVar4 = 0x1f;
            if (iVar2 != 0x40) {
              uVar4 = 0x40;
            }
            return uVar4;
          }
          uVar3 = (**(code **)(param_2 + 0x5b0))(param_1,param_2);
          *param_4 = uVar3;
          return 0;
        }
      }
      return 0x40;
    }
    *param_4 = 0;
    uVar4 = 0;
  }
  return uVar4;
}


// ===== 0031cf90 kflcnRiscvIcdRcsr_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kflcnRiscvIcdRcsr_TU102(undefined8 param_1,long param_2,uint param_3,undefined8 *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (0xfff < param_3) {
    return 0x1f;
  }
  cVar1 = (**(code **)(param_2 + 0x4e8))();
  if ((cVar1 != '\0') && (iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2), iVar2 != 0x65)) {
    (**(code **)(param_2 + 0x5c0))(param_1,param_2,param_3 << 0x10 | 0x10);
    iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
    if (iVar2 == 0) {
      uVar4 = (**(code **)(param_2 + 0x5b0))(param_1,param_2);
      *param_4 = uVar4;
      return 0;
    }
    uVar3 = 0x40;
    if (iVar2 == 0x40) {
      uVar3 = 0x1f;
    }
    return uVar3;
  }
  return 0x40;
}


// ===== 0031d0b0 kflcnRiscvIcdRstat_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kflcnRiscvIcdRstat_TU102(undefined8 param_1,long param_2,uint param_3,undefined8 *param_4)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(param_2 + 0x4e8))();
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
    if (iVar2 != 0x65) {
      (**(code **)(param_2 + 0x5c0))(param_1,param_2,(param_3 & 0x1f) << 8 | 0xe);
      iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
      if (iVar2 != 0) {
        uVar4 = 0x1f;
        if (iVar2 != 0x40) {
          uVar4 = 0x40;
        }
        return uVar4;
      }
      uVar3 = (**(code **)(param_2 + 0x5b0))(param_1,param_2);
      *param_4 = uVar3;
      return 0;
    }
  }
  return 0x40;
}


// ===== 0031d1a0 kflcnRiscvIcdRpc_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kflcnRiscvIcdRpc_TU102(undefined8 param_1,long param_2,undefined8 *param_3)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  cVar1 = (**(code **)(param_2 + 0x4e8))();
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
    if (iVar2 != 0x65) {
      (**(code **)(param_2 + 0x5c0))(param_1,param_2,0x12);
      iVar2 = (**(code **)(param_2 + 0x570))(param_1,param_2);
      if (iVar2 != 0) {
        uVar4 = 0x1f;
        if (iVar2 != 0x40) {
          uVar4 = 0x40;
        }
        return uVar4;
      }
      uVar3 = (**(code **)(param_2 + 0x5b0))(param_1,param_2);
      *param_3 = uVar3;
      return 0;
    }
  }
  return 0x40;
}


// ===== 0031d280 kflcnRiscvIcdHalt_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnRiscvIcdHalt_TU102(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  char cVar2;
  
  cVar2 = (**(code **)(param_2 + 0x4e8))();
  uVar1 = 0x40;
  if (cVar2 != '\0') {
    cVar2 = '\n';
    do {
      (**(code **)(param_2 + 0x5c0))(param_1,param_2,0);
      uVar1 = (**(code **)(param_2 + 0x570))(param_1,param_2);
      cVar2 = cVar2 + -1;
      if (cVar2 == '\0') {
        return uVar1;
      }
    } while ((int)uVar1 != 0);
  }
  return uVar1;
}


// ===== 0031d300 kflcnDumpTracepc_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnDumpTracepc_TU102(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x348);
  uVar8 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x34c);
  uVar5 = uVar1 >> 0x10 & 0xff;
  if (0x40 < (byte)(uVar1 >> 0x10)) {
    nvDbg_Printf("src/kernel/gpu/falcon/arch/turing/kernel_falcon_tu102.c",0x35a,
                 "kflcnDumpTracepc_TU102",4,"NVRM: Trace buffer larger than expected. Bailing!\n");
    return;
  }
  uVar8 = uVar8 >> 0x18;
  uVar1 = uVar1 & 0xff;
  uVar7 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x344);
  if (uVar1 == uVar8) {
    if ((uVar7 & 0x40000000) == 0) {
      *(undefined4 *)(param_3 + 0x58) = 0;
      goto LAB_0031d435;
    }
LAB_0031d46f:
    uVar6 = (uVar5 - uVar1) + uVar8;
    *(uint *)(param_3 + 0x58) = uVar6;
    if (uVar6 == 0) goto LAB_0031d435;
  }
  else {
    if (uVar8 <= uVar1) goto LAB_0031d46f;
    uVar6 = uVar8 - uVar1;
    *(uint *)(param_3 + 0x58) = uVar6;
  }
  uVar7 = 0;
  do {
    uVar2 = 0;
    if (uVar8 < (uint)uVar7) {
      uVar2 = uVar5;
    }
    uVar8 = uVar8 + uVar2;
    (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x348,uVar8 - (uint)uVar7);
    uVar3 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x350);
    uVar4 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x354);
    *(ulong *)(param_3 + 0x60 + uVar7 * 8) = CONCAT44(uVar3,uVar4);
    uVar7 = uVar7 + 1;
  } while (uVar7 != uVar6);
LAB_0031d435:
  (**(code **)(param_2 + 0x4d8))(param_1,param_2,0x348,uVar1);
  return;
}


// ===== 0031d4e0 kflcnDumpCoreRegs_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnDumpCoreRegs_TU102(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x268);
  *(undefined4 *)(param_3 + 4) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x2b4);
  *(undefined4 *)(param_3 + 8) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x2b8);
  *(undefined4 *)(param_3 + 0xc) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x360);
  *(undefined4 *)(param_3 + 0x44) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x364);
  *(undefined4 *)(param_3 + 0x48) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x368);
  *(undefined4 *)(param_3 + 0x50) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4d0))(param_1,param_2,0x36c);
  *(undefined4 *)(param_3 + 0x54) = uVar1;
  return;
}


// ===== 0031d5d0 kflcnDumpPeripheralRegs_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnDumpPeripheralRegs_TU102(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x40);
  *(undefined4 *)(param_3 + 0x14) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0x44);
  *(undefined4 *)(param_3 + 0x18) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,8);
  *(undefined4 *)(param_3 + 0x1c) = uVar1;
  uVar1 = (**(code **)(param_2 + 0x4c0))(param_1,param_2,0xc);
  *(undefined4 *)(param_3 + 0x20) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x20,0);
  *(undefined4 *)(param_3 + 0x24) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x24,0);
  *(undefined4 *)(param_3 + 0x28) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x2c,0);
  *(undefined4 *)(param_3 + 0x2c) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x30,0);
  *(undefined4 *)(param_3 + 0x30) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x38,0);
  *(undefined4 *)(param_3 + 0x34) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x34,0);
  *(undefined4 *)(param_3 + 0x38) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x3c,0);
  *(undefined4 *)(param_3 + 0x3c) = uVar1;
  uVar1 = regRead032(param_1 + 0x3a18,0,0,*(int *)(param_2 + 0x624) + 0x74,0);
  *(undefined4 *)(param_3 + 0x40) = uVar1;
  return;
}


// ===== 0031d770 kcrashcatEngineConfigured_IMPL =====

undefined1 kcrashcatEngineConfigured_IMPL(long param_1)

{
  return *(undefined1 *)(param_1 + 0x70);
}


// ===== 0031d780 kcrashcatEngineGetQueueMemDesc_IMPL =====

undefined8 kcrashcatEngineGetQueueMemDesc_IMPL(long param_1)

{
  return *(undefined8 *)(param_1 + 0x78);
}


// ===== 0031d790 kcrashcatEnginePriRead_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void kcrashcatEnginePriRead_IMPL(long *param_1,undefined4 param_2)

{
  (**(code **)(*param_1 + 0xa8))(param_1[0x12],param_1,param_2,*(code **)(*param_1 + 0xa8));
  return;
}


// ===== 0031d7c0 kcrashcatEnginePriWrite_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

void kcrashcatEnginePriWrite_IMPL(long *param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(*param_1 + 0xb0))(param_1[0x12],param_1,param_2,param_3,*(code **)(*param_1 + 0xb0));
  return;
}


// ===== 0031d7f0 kcrashcatEngineResetLog_IMPL =====

void kcrashcatEngineResetLog_IMPL(long param_1)

{
  *(undefined1 *)(param_1 + 0x9c) = 1;
  return;
}


// ===== 0031d800 kcrashcatEngineVprintf_IMPL =====

void kcrashcatEngineVprintf_IMPL(long param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  
  lVar1 = param_1 + 0x29d;
  if (*(char *)(param_1 + 0x9c) != '\0') {
    if (param_2 == 0) {
      nvDbgSnprintf(lVar1,0x200,"%s %s\n",*(undefined8 *)(param_1 + 0x80),param_3);
      nvDbgVsnprintf(param_1 + 0x9d,0x200,lVar1,param_4);
      out_string(param_1 + 0x9d);
    }
    else {
      nvDbgSnprintf(lVar1,0x200,"%s %s",*(undefined8 *)(param_1 + 0x80),param_3);
      nvErrorLog(*(undefined8 *)(param_1 + 0x90),param_2 & 0xffffffff,0,lVar1,param_4);
    }
    *(undefined1 *)(param_1 + 0x9c) = 0;
    return;
  }
  lVar2 = portStringLength(param_3);
  portStringCat(lVar1,lVar2 + 3,&DAT_00d12404,3);
  nvDbgVsnprintf(param_1 + 0x9d,0x200,lVar1,param_4);
  out_string(param_1 + 0x9d);
  return;
}


// ===== 0031d930 kcrashcatEngineRegisterCrashBuffer_IMPL =====

void kcrashcatEngineRegisterCrashBuffer_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar1 = *(undefined8 *)(param_2 + 0x30);
  uVar2 = memdescGetPhysAddr(param_2,1,0);
  iVar3 = memdescGetAddressSpace(param_2);
  uVar5 = 0;
  if ((iVar3 != 1) && (uVar5 = 1, iVar3 != 2)) {
    nvAssertFailedNoLog(&DAT_00d12437,"src/kernel/gpu/falcon/kernel_crashcat_engine.c",0xca);
    uVar5 = 0xff;
  }
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x48);
  }
  crashcatEngineRegisterCrashBuffer_IMPL(uVar4,uVar5,uVar2,uVar1,param_2);
  return;
}


// ===== 0031d9c0 kcrashcatEngineConfigure_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong kcrashcatEngineConfigure_IMPL(long *param_1,long *param_2)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  lVar3 = __nvoc_dynamicCast(param_1,__nvoc_class_def_Object);
  if (*(char *)((long)param_2 + 0x11) == '\0') {
    return 0;
  }
  if (*param_2 == 0) {
    nvCheckFailedNoLog(4,"pEngConfig->pName != NULL",
                       "src/kernel/gpu/falcon/kernel_crashcat_engine.c",0x2a);
  }
  else {
    if (*(int *)((long)param_2 + 0xc) != 0) {
      *(undefined1 *)(param_1 + 0xe) = 1;
      param_1[0x10] = *param_2;
      *(undefined4 *)(param_1 + 0x11) = *(undefined4 *)((long)param_2 + 0xc);
      uVar6 = 0;
      if (lVar3 != 0) {
        uVar6 = *(undefined8 *)(lVar3 + 8);
      }
      lVar3 = gpuEngineGetGpu(uVar6);
      param_1[0x12] = lVar3;
      bVar1 = *(byte *)(param_2 + 2);
      *(undefined1 *)((long)param_1 + 0x9c) = 1;
      *(uint *)(param_1 + 0x13) = (uint)bVar1;
      uVar2 = *(uint *)(param_2 + 1);
      uVar4 = (ulong)uVar2;
      if (uVar2 != 0) {
        uVar2 = uVar2 + 0x3ff & 0xfffffc00;
        *(uint *)(param_2 + 1) = uVar2;
        uVar2 = memdescCreate(param_1 + 0xf,param_1[0x12],uVar2,0x400,1,1);
        if (uVar2 == 0) {
          uVar4 = memdescAlloc(param_1[0xf]);
          uVar6 = 0x44;
          pcVar5 = "memdescAlloc(pKernelCrashCatEng->pQueueMemDesc)";
          if ((int)uVar4 == 0) {
            uVar4 = kcrashcatEngineRegisterCrashBuffer_IMPL
                              (param_1,param_1[0xf],
                               "memdescAlloc(pKernelCrashCatEng->pQueueMemDesc)",
                               "src/kernel/gpu/falcon/kernel_crashcat_engine.c",0x44);
            if ((int)uVar4 == 0) {
              return uVar4;
            }
            uVar6 = 0x4c;
            pcVar5 = 
            "kcrashcatEngineRegisterCrashBuffer(pKernelCrashCatEng, pKernelCrashCatEng->pQueueMemDesc)"
            ;
          }
          nvCheckOkFailedNoLog
                    (4,uVar4 & 0xffffffff,pcVar5,"src/kernel/gpu/falcon/kernel_crashcat_engine.c",
                     uVar6);
          (**(code **)(*param_1 + 0x90))(param_1);
          uVar4 = uVar4 & 0xffffffff;
        }
        else {
          nvCheckOkFailedNoLog
                    (4,uVar2,
                     "memdescCreate(&pKernelCrashCatEng->pQueueMemDesc, pKernelCrashCatEng->pGpu, pEngConfig->allocQueueSize, CRASHCAT_QUEUE_ALIGNMENT, NV_TRUE, ADDR_SYSMEM, NV_MEMORY_CACHED, MEMDESC_FLAGS_NONE)"
                     ,"src/kernel/gpu/falcon/kernel_crashcat_engine.c",0x3f);
          uVar4 = (ulong)uVar2;
        }
      }
      return uVar4;
    }
    nvCheckFailedNoLog(4,"pEngConfig->errorId != 0","src/kernel/gpu/falcon/kernel_crashcat_engine.c"
                       ,0x2b);
  }
  return 0x1f;
}


// ===== 0031db90 kcrashcatEngineUnregisterCrashBuffer_IMPL =====

void kcrashcatEngineUnregisterCrashBuffer_IMPL(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar1 = *(undefined8 *)(param_2 + 0x30);
  uVar2 = memdescGetPhysAddr(param_2,1,0);
  iVar3 = memdescGetAddressSpace(param_2);
  uVar5 = 0;
  if ((iVar3 != 1) && (uVar5 = 1, iVar3 != 2)) {
    nvAssertFailedNoLog(&DAT_00d12437,"src/kernel/gpu/falcon/kernel_crashcat_engine.c",0xca);
    uVar5 = 0xff;
  }
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x48);
  }
  crashcatEngineUnregisterCrashBuffer_IMPL(uVar4,uVar5,uVar2,uVar1);
  return;
}


// ===== 0031dc20 kcrashcatEngineUnload_IMPL =====

void kcrashcatEngineUnload_IMPL(long param_1)

{
  if (*(long *)(param_1 + 0x78) != 0) {
    kcrashcatEngineUnregisterCrashBuffer_IMPL();
    memdescFree(*(undefined8 *)(param_1 + 0x78));
    memdescDestroy(*(undefined8 *)(param_1 + 0x78));
    *(undefined8 *)(param_1 + 0x78) = 0;
  }
  crashcatEngineUnload_IMPL(*(undefined8 *)(param_1 + 0x48));
  return;
}


// ===== 0031dc70 kcrashcatEngineMapBufferDescriptor_IMPL =====

undefined8 kcrashcatEngineMapBufferDescriptor_IMPL(long param_1,long *param_2)

{
  int iVar1;
  char cVar2;
  long lVar3;
  long *plVar4;
  undefined8 in_stack_ffffffffffffffd0;
  undefined8 local_28;
  long local_20;
  
  if ((char)param_2[2] == '\0') {
    cVar2 = '\x01';
    if (*(int *)((long)param_2 + 0x14) != 0) {
      cVar2 = (*(int *)((long)param_2 + 0x14) == 1) * '\x02';
    }
    iVar1 = memdescCreate(&local_20,*(undefined8 *)(param_1 + 0x90),param_2[4],0,1,cVar2,0,0);
    if (iVar1 != 0) {
      nvCheckOkFailedNoLog
                (4,iVar1,
                 "memdescCreate(&pMemDesc, pKernelCrashCatEng->pGpu, pBufDesc->size, 0, NV_TRUE, bufAddrSpace, NV_MEMORY_CACHED, MEMDESC_FLAGS_NONE)"
                 ,"src/kernel/gpu/falcon/kernel_crashcat_engine.c",0xf9);
      goto LAB_0031dd70;
    }
    in_stack_ffffffffffffffd0 = 0x31dd47;
    memdescDescribe(local_20,cVar2,param_2[3],param_2[4]);
    lVar3 = local_20;
  }
  else {
    lVar3 = *param_2;
  }
  if (lVar3 != 0) {
    plVar4 = &local_20;
    iVar1 = memdescMap(lVar3,0,*(undefined8 *)(lVar3 + 0x30),1,1,&local_28);
    if (iVar1 == 0) {
      memdescSetKernelMapping(lVar3,local_28,plVar4,in_stack_ffffffffffffffd0);
      memdescSetKernelMappingPriv(lVar3,local_20);
      *param_2 = lVar3;
      return local_28;
    }
    nvCheckOkFailedNoLog
              (4,iVar1,
               "memdescMap(pMemDesc, 0, memdescGetSize(pMemDesc), NV_TRUE, NV_PROTECT_READABLE, &pBuf, &pPriv)"
               ,"src/kernel/gpu/falcon/kernel_crashcat_engine.c",0x115);
    if ((char)param_2[2] != '\0') {
      return 0;
    }
    memdescDestroy(lVar3);
    return 0;
  }
LAB_0031dd70:
  nvCheckFailedNoLog(4,"pMemDesc != NULL","src/kernel/gpu/falcon/kernel_crashcat_engine.c",0x10f);
  return 0;
}


// ===== 0031dde0 kcrashcatEngineUnmapBufferDescriptor_IMPL =====

void kcrashcatEngineUnmapBufferDescriptor_IMPL(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = *param_2;
  uVar2 = memdescGetKernelMapping(uVar1);
  uVar3 = memdescGetKernelMappingPriv(uVar1);
  memdescUnmap(uVar1,1,uVar2,uVar3);
  memdescSetKernelMapping(uVar1,0);
  memdescSetKernelMappingPriv(uVar1,0);
  if (*(char *)(param_2 + 2) != '\0') {
    return;
  }
  memdescDestroy(uVar1);
  return;
}


// ===== 0031de60 kcrashcatEngineSyncBufferDescriptor_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kcrashcatEngineSyncBufferDescriptor_IMPL
               (long *param_1,long param_2,uint param_3,undefined4 param_4)

{
  if (*(int *)(param_2 + 0x14) == 2) {
    (*(code *)param_1[0xb])
              (param_1,param_3 + *(int *)(param_2 + 0x18),param_4,
               (ulong)param_3 + *(long *)(param_2 + 8));
    return;
  }
  if (*(int *)(param_2 + 0x14) != 3) {
    return;
  }
  (**(code **)(*param_1 + 0xe8))
            (param_1,param_3 + *(int *)(param_2 + 0x18),param_4,
             (ulong)param_3 + *(long *)(param_2 + 8));
  return;
}


// ===== 0031deb7 _kflcnPromoteContext.cold =====

void _kflcnPromoteContext_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0031dee0 _kflcnPromoteContext =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

ulong _kflcnPromoteContext(long param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  undefined4 uVar10;
  undefined4 local_27c;
  long local_278;
  long local_270;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  long local_250;
  ulong local_248;
  undefined4 local_240;
  undefined8 local_238;
  undefined8 local_228;
  undefined4 local_220;
  undefined4 local_21c;
  
  if (param_3 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  lVar1 = **(long **)(*(long *)(param_3 + 0x140) + 0x48);
  lVar2 = *(long *)(*(long *)(param_3 + 0x158) + 0xe8);
  memset(&local_268,0,0x230);
  plVar7 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_3 + 0x2a0),__nvoc_class_def_OBJGVASPACE)
  ;
  iVar5 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  if (iVar5 != 0) {
    nvAssertFailedNoLog("gpumgrGetSubDeviceInstanceFromGpu(pGpu) == 0",
                        "src/kernel/gpu/falcon/kernel_falcon.c",200);
    return 0x40;
  }
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)invalidInstructionException();
    (*pcVar3)();
  }
  uVar6 = subdeviceGetByInstance_IMPL
                    (lVar1,*(undefined4 *)(*(long *)(*(long *)(lVar2 + 0x110) + 0x48) + 0x10),0,
                     &local_278);
  if (uVar6 == 0) {
    lVar2 = **(long **)(*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) + 0x150);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pEngCtx != NULL","src/kernel/gpu/falcon/kernel_falcon.c",0xcc);
      return 0x1f;
    }
    uVar10 = *(undefined4 *)(param_2 + 0x634);
    lVar8 = gpuGetKernelFifoShared_IMPL(param_1);
    uVar6 = (**(code **)(lVar8 + 0x218))(param_1,lVar8,0,uVar10,2,&local_27c);
    if (uVar6 != 0) {
      nvAssertOkFailedNoLog
                (uVar6,
                 "kfifoEngineInfoXlate_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), ENGINE_INFO_TYPE_ENG_DESC, pKernelFalcon->physEngDesc, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&rmEngineType)"
                 ,"src/kernel/gpu/falcon/kernel_falcon.c",0xce);
      return (ulong)uVar6;
    }
    local_264 = *(undefined4 *)(lVar1 + 0x48);
    local_258 = *(undefined4 *)(*(long *)(*(long *)(param_3 + 0x140) + 0x48) + 0x10);
    local_248 = (ulong)*(uint *)(param_2 + 0x63c);
    local_25c = local_264;
    local_268 = gpuGetNv2080EngineType_IMPL(local_27c);
    local_260 = *(undefined4 *)(param_3 + 0x2b4);
    cVar4 = (**(code **)(*plVar7 + 0x188))(plVar7);
    if (cVar4 == '\0') {
      uVar6 = vaListFindVa(lVar2 + 8,*(undefined8 *)(param_3 + 0x2a0),&local_270);
      if (uVar6 != 0) {
        nvAssertOkFailedNoLog
                  (uVar6,"vaListFindVa(&pEngCtx->vaList, pKernelChannel->pVAS, &addr)",
                   "src/kernel/gpu/falcon/kernel_falcon.c",0x10c);
        return (ulong)uVar6;
      }
      local_250 = local_270;
    }
    else {
      local_270 = 0;
      uVar6 = kchangrpGetEngineContextMemDesc_IMPL
                        (param_1,*(undefined8 *)(*(long *)(param_3 + 0x2b8) + 0x138),&local_270);
      if (uVar6 != 0) {
        nvAssertOkFailedNoLog
                  (uVar6,
                   "kchangrpGetEngineContextMemDesc(pGpu, pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup, &pMemDesc)"
                   ,"src/kernel/gpu/falcon/kernel_falcon.c",0xdf);
        return (ulong)uVar6;
      }
      cVar4 = memdescGetContiguity(local_270,1);
      if (cVar4 == '\0') {
        nvAssertFailedNoLog("memdescGetContiguity(pMemDesc, AT_GPU)",
                            "src/kernel/gpu/falcon/kernel_falcon.c",0xe1);
        return 0x40;
      }
      iVar5 = memdescGetAddressSpace(local_270);
      if (iVar5 == 1) {
        if (*(int *)(local_270 + 0x74) == 0) {
          uVar10 = 5;
        }
        else {
          uVar10 = 6;
          if (*(int *)(local_270 + 0x74) != 1) {
            return 0x40;
          }
        }
      }
      else {
        if (iVar5 != 2) {
          return 0x40;
        }
        uVar10 = 4;
      }
      local_240 = 1;
      local_238 = memdescGetPhysAddr(local_270,1,0);
      local_228 = *(undefined8 *)(local_270 + 0x30);
      local_21c = 0x1010000;
      local_220 = uVar10;
    }
    if (local_278 == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    uVar9 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(lVar1 + 0x48),
                       *(undefined4 *)(*(long *)(*(long *)(local_278 + 0x140) + 0x48) + 0x10),
                       0x2080012b,&local_268,0x230);
    if ((int)uVar9 != 0) {
      nvAssertOkFailedNoLog
                (uVar9 & 0xffffffff,
                 "pRmApi->Control(pRmApi, pClient->hClient, RES_GET_HANDLE(pSubdevice), NV2080_CTRL_CMD_GPU_PROMOTE_CTX, &rmCtrlParams, sizeof(rmCtrlParams))"
                 ,"src/kernel/gpu/falcon/kernel_falcon.c",0x110);
      uVar9 = uVar9 & 0xffffffff;
    }
    return uVar9;
  }
  nvAssertOkFailedNoLog
            (uVar6,"subdeviceGetByInstance(pClient, RES_GET_HANDLE(pDevice), 0, &pSubdevice)",
             "src/kernel/gpu/falcon/kernel_falcon.c",0xc9);
  return (ulong)uVar6;
}


// ===== 0031e360 kflcnConfigureEngine_IMPL =====

void kflcnConfigureEngine_IMPL(undefined8 param_1,long param_2,undefined4 *param_3)

{
  *(undefined4 *)(param_2 + 0x61c) = *param_3;
  *(undefined4 *)(param_2 + 0x620) = param_3[1];
  *(undefined4 *)(param_2 + 0x624) = param_3[2];
  *(undefined1 *)(param_2 + 0x628) = *(undefined1 *)(param_3 + 3);
  *(undefined4 *)(param_2 + 0x62c) = param_3[4];
  *(undefined4 *)(param_2 + 0x630) = param_3[5];
  *(undefined4 *)(param_2 + 0x634) = param_3[6];
  *(undefined4 *)(param_2 + 0x638) = param_3[7];
  *(undefined4 *)(param_2 + 0x63c) = param_3[8];
  *(undefined4 *)(param_2 + 0x640) = param_3[9];
  kcrashcatEngineConfigure_IMPL(*(undefined8 *)(param_2 + 0x4b0),param_3 + 10);
  nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x3b,"kflcnConfigureEngine_IMPL",1,
               "NVRM: for physEngDesc 0x%x\n",*(undefined4 *)(param_2 + 0x634));
  return;
}


// ===== 0031e410 kflcnGetKernelFalconForEngine_IMPL =====

long kflcnGetKernelFalconForEngine_IMPL(long param_1,int param_2)

{
  long lVar1;
  long lVar2;
  
  if (param_2 == 0x28c40800) {
    if ((*(long *)(param_1 + 0x1ba0) != 0) &&
       (lVar2 = *(long *)(*(long *)(param_1 + 0x1ba0) + 2000), lVar2 != 0)) {
      return lVar2;
    }
  }
  else if (param_2 == -0x25c21c00) {
    if (*(long *)(param_1 + 0x1ba8) == 0) {
      return 0;
    }
    return *(long *)(*(long *)(param_1 + 0x1ba8) + 2000);
  }
  lVar1 = gpuGetGenericKernelFalconForEngine_IMPL();
  lVar2 = 0;
  if (lVar1 != 0) {
    lVar2 = gpuGetGenericKernelFalconForEngine_IMPL(param_1,param_2);
    lVar2 = *(long *)(lVar2 + 0x6a0);
  }
  return lVar2;
}


// ===== 0031e4a0 kflcnGetPendingHostInterrupts_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kflcnGetPendingHostInterrupts_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  
  if (*(char *)(param_2 + 0x618) == '\x02') {
    cVar1 = (**(code **)(param_2 + 0x4f0))();
    *(char *)(param_2 + 0x618) = cVar1;
    if (cVar1 != '\0') {
      (**(code **)(param_2 + 0x550))();
      return;
    }
    (**(code **)(param_2 + 0x548))(param_1);
    return;
  }
  if (*(char *)(param_2 + 0x618) != '\0') {
    (**(code **)(param_2 + 0x550))();
    return;
  }
  (**(code **)(param_2 + 0x548))();
  return;
}


// ===== 0031e520 kflcnAllocContext_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kflcnAllocContext_IMPL(long param_1,long param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long local_40 [2];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/falcon/kernel_falcon.c",0x11f);
    return 0x21;
  }
  iVar3 = kchannelGetGfid_IMPL(param_3);
  if ((*(char *)(param_1 + 0x4a23) == '\0') || (iVar3 != 0)) {
    return 0;
  }
  cVar2 = gpuIsClassSupported_IMPL(param_1,param_4);
  if (cVar2 == '\0') {
    nvAssertFailedNoLog("gpuIsClassSupported(pGpu, classNum)",
                        "src/kernel/gpu/falcon/kernel_falcon.c",0x124);
    return 0x31;
  }
  local_40[0] = 0;
  lVar1 = *(long *)(*(long *)(param_3 + 0x2b8) + 0x138);
  plVar5 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_3 + 0x2a0),__nvoc_class_def_OBJGVASPACE)
  ;
  if (*(char *)(param_3 + 0x408) == '\0') {
    kchangrpGetEngineContextMemDesc_IMPL(param_1,lVar1,local_40);
    if (local_40[0] == 0) {
      cVar2 = ctxBufPoolIsSupported(param_1);
      uVar7 = 0x2000000;
      lVar8 = 0;
      if ((cVar2 != '\0') && (lVar8 = *(long *)(lVar1 + 400), lVar8 != 0)) {
        uVar7 = 0x1002000000;
      }
      uVar6 = (ulong)*(uint *)(param_2 + 0x638);
      uVar4 = memdescCreate(local_40,param_1,*(undefined4 *)(param_2 + 0x63c),0x100,1,0);
      if (uVar4 == 0) {
        uVar4 = memdescSetCtxBufPool(local_40[0],lVar8,uVar6,uVar7);
        if (uVar4 == 0) {
          *(undefined4 *)(local_40[0] + 0x9c) = 0x94;
          uVar7 = memdescU32ToAddrSpaceList(*(undefined4 *)(param_2 + 0x640));
          uVar4 = memdescAllocList(local_40[0],uVar7);
          if (uVar4 == 0) {
            uVar4 = memmgrMemDescMemSet_IMPL(*(undefined8 *)(param_1 + 0x1b78),local_40[0],0,0);
            if (uVar4 == 0) {
              uVar4 = kchannelSetEngineContextMemDesc_IMPL
                                (param_1,param_3,*(undefined4 *)(param_2 + 0x634),local_40[0]);
              if (uVar4 == 0) {
                cVar2 = (**(code **)(*plVar5 + 0x188))(plVar5);
                if ((cVar2 != '\0') ||
                   (uVar4 = kchannelMapEngineCtxBuf_IMPL
                                      (param_1,param_3,*(undefined4 *)(param_2 + 0x634)), uVar4 == 0
                   )) goto LAB_0031e5bc;
                nvAssertOkFailedNoLog
                          (uVar4,
                           "kchannelMapEngineCtxBuf(pGpu, pKernelChannel, pKernelFalcon->physEngDesc)"
                           ,"src/kernel/gpu/falcon/kernel_falcon.c",0xa9);
              }
              else {
                nvAssertOkFailedNoLog
                          (uVar4,
                           "kchannelSetEngineContextMemDesc(pGpu, pKernelChannel, pKernelFalcon->physEngDesc, pCtxMemDesc)"
                           ,"src/kernel/gpu/falcon/kernel_falcon.c",0xa3);
              }
            }
            else {
              nvAssertOkFailedNoLog
                        (uVar4,
                         "memmgrMemDescMemSet(GPU_GET_MEMORY_MANAGER(pGpu), pCtxMemDesc, 0, TRANSFER_FLAGS_NONE)"
                         ,"src/kernel/gpu/falcon/kernel_falcon.c",0x9e);
            }
          }
          else {
            nvAssertOkFailedNoLog(uVar4,"status","src/kernel/gpu/falcon/kernel_falcon.c",0x9c);
          }
        }
        else {
          nvAssertOkFailedNoLog
                    (uVar4,"memdescSetCtxBufPool(pCtxMemDesc, pCtxBufPool)",
                     "src/kernel/gpu/falcon/kernel_falcon.c",0x97);
        }
        memdescFree(local_40[0]);
        memdescDestroy(local_40[0]);
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar4,
                   "memdescCreate(&pCtxMemDesc, pGpu, pKernelFalcon->ctxBufferSize, FLCN_BLK_ALIGNMENT, NV_TRUE, ADDR_UNKNOWN, pKernelFalcon->ctxAttr, flags)"
                   ,"src/kernel/gpu/falcon/kernel_falcon.c",0x90);
      }
      nvAssertOkFailedNoLog
                (uVar4,"_kflcnAllocAndMapCtxBuffer(pGpu, pKernelFalcon, pKernelChannel)",
                 "src/kernel/gpu/falcon/kernel_falcon.c",0x126);
      return (ulong)uVar4;
    }
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x81,"_kflcnAllocAndMapCtxBuffer",4,
                 "NVRM: This channel already has a falcon engine instance on engine %d:%d\n",
                 *(uint *)(param_2 + 0x634) >> 8,*(uint *)(param_2 + 0x634) & 0xff);
  }
LAB_0031e5bc:
  iVar3 = videoEventTraceCtxInit(param_1,param_3,*(undefined4 *)(param_2 + 0x634));
  if (iVar3 != 0) {
    nvCheckFailedNoLog(4,
                       "videoEventTraceCtxInit(pGpu, pKernelChannel, pKernelFalcon->physEngDesc) == NV_OK"
                       ,"src/kernel/gpu/falcon/kernel_falcon.c",0x128);
  }
  uVar6 = _kflcnPromoteContext(param_1,param_2,param_3);
  return uVar6;
}


// ===== 0031e950 kflcnFreeContext_IMPL =====

int kflcnFreeContext_IMPL(long param_1,long param_2,long param_3)

{
  int iVar1;
  long local_30 [2];
  
  local_30[0] = 0;
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/falcon/kernel_falcon.c",0x137);
    return 0x21;
  }
  iVar1 = kchannelGetGfid_IMPL(param_3);
  if (((*(char *)(param_1 + 0x4a23) != '\0') && (iVar1 == 0)) &&
     (*(char *)(param_3 + 0x408) == '\0')) {
    kchangrpGetEngineContextMemDesc_IMPL
              (param_1,*(undefined8 *)(*(long *)(param_3 + 0x2b8) + 0x138),local_30);
    if (local_30[0] != 0) {
      kchannelUnmapEngineCtxBuf_IMPL(param_1,param_3);
      iVar1 = kchannelSetEngineContextMemDesc_IMPL
                        (param_1,param_3,*(undefined4 *)(param_2 + 0x634),0);
      if (iVar1 != 0) {
        nvAssertOkFailedNoLog
                  (iVar1,
                   "kchannelSetEngineContextMemDesc(pGpu, pKernelChannel, pKernelFalcon->physEngDesc, NULL)"
                   ,"src/kernel/gpu/falcon/kernel_falcon.c",0x14d);
      }
      memdescFree(local_30[0]);
      memdescDestroy(local_30[0]);
      return iVar1;
    }
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x145,"kflcnFreeContext_IMPL",3,
                 "NVRM: channel 0x%08x does not have a falcon engine instance for engDesc=0x%x\n",
                 *(int *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4),
                 *(undefined4 *)(param_2 + 0x634));
  }
  return 0;
}


// ===== 0031eac0 gkflcnConstruct_IMPL =====

undefined8 gkflcnConstruct_IMPL(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1 != 0) {
    lVar1 = *(long *)(param_1 + 0x6a0);
  }
  if (param_3 != (undefined4 *)0x0) {
    *(undefined4 *)(lVar1 + 0x61c) = *param_3;
    *(undefined4 *)(lVar1 + 0x620) = param_3[1];
    *(undefined4 *)(lVar1 + 0x624) = param_3[2];
    *(undefined1 *)(lVar1 + 0x628) = *(undefined1 *)(param_3 + 3);
    *(undefined4 *)(lVar1 + 0x62c) = param_3[4];
    *(undefined4 *)(lVar1 + 0x630) = param_3[5];
    *(undefined4 *)(lVar1 + 0x634) = param_3[6];
    *(undefined4 *)(lVar1 + 0x638) = param_3[7];
    *(undefined4 *)(lVar1 + 0x63c) = param_3[8];
    *(undefined4 *)(lVar1 + 0x640) = param_3[9];
    kcrashcatEngineConfigure_IMPL(*(undefined8 *)(lVar1 + 0x4b0),param_3 + 10);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x3b,"kflcnConfigureEngine_IMPL",1,
                 "NVRM: for physEngDesc 0x%x\n",*(undefined4 *)(lVar1 + 0x634));
    return 0;
  }
  return 0;
}


// ===== 0031eba0 gkflcnResetHw_IMPL =====

undefined8 gkflcnResetHw_IMPL(void)

{
  nvAssertFailedNoLog("This should only be called on full KernelFalcon implementations",
                      "src/kernel/gpu/falcon/kernel_falcon.c",0x166);
  return 0x56;
}


// ===== 0031ebd0 gkflcnRegisterIntrService_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

void gkflcnRegisterIntrService_IMPL(long param_1,long param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  uint local_2c;
  
  if ((param_2 != 0) && (lVar4 = *(long *)(param_2 + 0x6a0), lVar4 != 0)) {
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x16f,"gkflcnRegisterIntrService_IMPL",1,
                 "NVRM: physEngDesc 0x%x\n",*(undefined4 *)(lVar4 + 0x634));
    uVar1 = *(uint *)(lVar4 + 0x634);
    uVar5 = uVar1 >> 8;
    if ((((uVar5 == 0x8f99e1 || uVar5 == 0xdd7bab) || uVar1 == 0x28c40800) || uVar5 == 0x2b3a54) ||
       (uVar5 == 0xe97b6c)) {
      local_2c = 0;
      lVar3 = gpuGetKernelFifoShared_IMPL(param_1);
      iVar2 = (**(code **)(lVar3 + 0x218))(param_1,lVar3,0,uVar1,8,&local_2c);
      if ((*(char *)(param_1 + 0x908) == '\0') || (iVar2 != 0x57)) {
        if (iVar2 == 0) {
          nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x18a,
                       "gkflcnRegisterIntrService_IMPL",1,
                       "NVRM: Registering 0x%x/0x%x to handle nonstall intr\n",
                       *(undefined4 *)(lVar4 + 0x634),local_2c);
          lVar4 = param_3 + (ulong)local_2c * 0x18;
          if (*(long *)(lVar4 + 8) != 0) {
            nvAssertFailedNoLog("pRecords[mcIdx].pNotificationService == NULL",
                                "src/kernel/gpu/falcon/kernel_falcon.c",0x18c,0x31ecb6);
            lVar4 = param_3 + (ulong)local_2c * 0x18;
          }
          *(undefined1 *)(lVar4 + 0x10) = 0;
          *(undefined8 *)(lVar4 + 8) = *(undefined8 *)(param_2 + 0x6a8);
        }
        else {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/falcon/kernel_falcon.c",0x187);
        }
      }
    }
    return;
  }
  nvAssertFailedNoLog("pKernelFalcon","src/kernel/gpu/falcon/kernel_falcon.c",0x16d);
  return;
}


// ===== 0031edb0 gkflcnServiceNotificationInterrupt_IMPL =====

undefined8
gkflcnServiceNotificationInterrupt_IMPL(undefined8 param_1,undefined8 param_2,long param_3)

{
  ushort uVar1;
  undefined8 uVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_3 + 8);
  nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x197,
               "gkflcnServiceNotificationInterrupt_IMPL",1,"NVRM: nonstall intr for MC 0x%x\n",uVar1
              );
  iVar3 = uVar1 - 0x24;
  if ((((uVar1 - 0x41 < 8) || (iVar3 = uVar1 - 0x13, uVar1 - 0x51 < 2)) ||
      (iVar3 = uVar1 + 3, uVar1 - 0x33 < 8)) ||
     ((iVar3 = uVar1 - 1, uVar1 - 0x26 < 4 || (iVar3 = 0x31, uVar1 == 0x2f)))) {
    engineNonStallIntrNotify(param_1,iVar3);
    uVar2 = 0;
  }
  else {
    nvAssertFailedNoLog("rmEngineType != RM_ENGINE_TYPE_NULL",
                        "src/kernel/gpu/falcon/kernel_falcon.c",0x1b6);
    uVar2 = 0x40;
  }
  return uVar2;
}


// ===== 0031ee60 kflcnCoreDumpNondestructive_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnCoreDumpNondestructive_IMPL(undefined8 param_1,long param_2,int param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  ulong uVar3;
  undefined4 uVar4;
  undefined4 local_288;
  undefined4 local_284;
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_274;
  uint local_270;
  undefined4 local_26c;
  undefined4 local_268;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  uint local_230;
  undefined8 auStack_228 [65];
  
  memset(&local_288,0,0x260);
  (**(code **)(param_2 + 0x5d0))(param_1,param_2,&local_288);
  if (param_3 == 0) {
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d0,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvPc               : %08x\n",local_288);
  }
  else {
    (**(code **)(param_2 + 0x5e0))(param_1,param_2,&local_288);
    if (param_3 != 1) {
      (**(code **)(param_2 + 0x5d8))(param_1,param_2,&local_288);
    }
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d0,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvPc               : %08x\n",local_288);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d3,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvCpuctl           : %08x\n",local_284);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d4,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvIrqmask          : %08x\n",local_280);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d5,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvIrqdest          : %08x\n",local_27c);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d6,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvPrivErrStat      : %08x\n",local_244);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d7,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvPrivErrInfo      : %08x\n",local_240);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d8,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvPrivErrAddr      : %016llx\n",CONCAT44(local_23c,local_238));
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1d9,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: riscvHubErrStat       : %08x\n",local_234);
    uVar2 = (ulong)local_270;
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1da,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: falconMailbox         : 0:%08x 1:%08x\n",local_274,uVar2);
    uVar4 = (undefined4)(uVar2 >> 0x20);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1db,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: falconIrqstat         : %08x\n",local_26c);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1dc,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: falconIrqmode         : %08x\n",local_268);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1dd,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: fbifInstblk           : %08x\n",local_264);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1de,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: fbifCtl               : %08x\n",local_260);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1df,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: fbifThrottle          : %08x\n",local_25c);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1e0,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: fbifAchkBlk           : 0:%08x 1:%08x\n",local_258,
                 CONCAT44(uVar4,local_254));
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1e1,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: fbifAchkCtl           : 0:%08x 1:%08x\n",local_250,local_24c);
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1e2,"kflcnCoreDumpNondestructive_IMPL",4,
                 "NVRM: PRI: fbifCg1               : %08x\n",local_248);
    if ((param_3 != 1) && (local_230 != 0)) {
      uVar2 = 0;
      do {
        puVar1 = auStack_228 + uVar2;
        uVar3 = uVar2 & 0xffffffff;
        uVar2 = uVar2 + 1;
        nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x1e8,
                     "kflcnCoreDumpNondestructive_IMPL",4,"NVRM: TRACE: %02u = 0x%016llx\n",uVar3,
                     *puVar1);
      } while ((uint)uVar2 < local_230);
      return 0;
    }
  }
  return 0;
}


// ===== 0031f2c0 kflcnCoreDumpDestructive_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kflcnCoreDumpDestructive_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  int iVar7;
  ulong uVar8;
  ulong local_158;
  ulong local_150;
  ulong local_148;
  ulong local_140;
  ulong local_138 [33];
  
  local_158 = 1;
  local_150 = 0;
  local_148 = 0;
  cVar1 = (**(code **)(param_2 + 0x4e8))();
  if (cVar1 == '\0') {
    nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x205,"kflcnCoreDumpDestructive_IMPL",4,
                 "NVRM: ICD: [ERROR] Core is not booted.\n");
    return 0;
  }
  iVar7 = 0;
  nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x201,"kflcnCoreDumpDestructive_IMPL",4,
               "NVRM: ICD: Core is booted.\n");
  iVar4 = 0;
  do {
    while (iVar3 = (**(code **)(param_2 + 0x590))(param_1,param_2,iVar4,&local_140), iVar3 == 0) {
      iVar3 = iVar4 + 1;
      iVar7 = iVar7 + 1;
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x210,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: RSTAT%d 0x%016llx\n",iVar4,local_140);
      iVar4 = iVar3;
      if (iVar3 == 8) goto LAB_0031f3b9;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 8);
LAB_0031f3b9:
  if (iVar7 == 0) {
    pcVar6 = "NVRM: ICD: [ERROR] Unable to retrieve any RSTAT register.\n";
    uVar5 = 0x216;
  }
  else {
    iVar4 = (**(code **)(param_2 + 0x5a0))(param_1,param_2);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(param_2 + 0x598))(param_1,param_2,&local_158);
      if (iVar4 == 0) {
        nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x232,"kflcnCoreDumpDestructive_IMPL",4
                     ,"NVRM: ICD: PC = 0x%016llx\n",local_158);
      }
      else {
        iVar4 = (**(code **)(param_2 + 0x5c8))(param_1,param_2,&local_158);
        if (iVar4 == 0) {
          nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x22d,"kflcnCoreDumpDestructive_IMPL"
                       ,4,"NVRM: ICD: PC = 0x--------%08llx\n",local_158 & 0xffffffff);
        }
        else {
          nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x229,"kflcnCoreDumpDestructive_IMPL"
                       ,4,"NVRM: ICD: [WARN] Cannot retrieve PC.\n");
        }
      }
      uVar8 = 0;
LAB_0031f460:
      do {
        iVar4 = (**(code **)(param_2 + 0x580))(param_1,param_2,uVar8 & 0xffffffff,&local_140);
        if (iVar4 == 0) {
          local_138[uVar8] = local_140;
          if (uVar8 == 1) {
            uVar8 = 2;
            local_150 = local_140;
            goto LAB_0031f460;
          }
          if (uVar8 == 8) {
            uVar8 = 9;
            local_148 = local_140;
            goto LAB_0031f460;
          }
        }
        else {
          nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x244,"kflcnCoreDumpDestructive_IMPL"
                       ,4,"NVRM: ICD: register read failed for x%02d\n",uVar8 & 0xffffffff);
          local_138[uVar8] = 0xbaadbaadbaadbaad;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 != 0x20);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x248,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: ra:0x%016llx   sp:0x%016llx   gp:0x%016llx   tp:0x%016llx\n",
                   local_138[1],local_138[2],local_138[3],local_138[4]);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x24b,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: a0:0x%016llx   a1:0x%016llx   a2:0x%016llx   a3:0x%016llx\n",
                   local_138[5],local_138[6],local_138[7],local_138[8]);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x24e,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: a4:0x%016llx   a5:0x%016llx   a6:0x%016llx   a7:0x%016llx\n",
                   local_138[9],local_138[10],local_138[0xb],local_138[0xc]);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x251,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: s0:0x%016llx   s1:0x%016llx   s2:0x%016llx   s3:0x%016llx\n",
                   local_138[0xd],local_138[0xe],local_138[0xf],local_138[0x10]);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x254,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: s4:0x%016llx   s5:0x%016llx   s6:0x%016llx   s7:0x%016llx\n",
                   local_138[0x11],local_138[0x12],local_138[0x13],local_138[0x14]);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",599,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: s8:0x%016llx   s9:0x%016llx  s10:0x%016llx  s11:0x%016llx\n",
                   local_138[0x15],local_138[0x16],local_138[0x17],local_138[0x18]);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x25a,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: t0:0x%016llx   t1:0x%016llx   t2:0x%016llx   t3:0x%016llx\n",
                   local_138[0x19],local_138[0x1a],local_138[0x1b],local_138[0x1c]);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x25d,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: t4:0x%016llx   t5:0x%016llx   t6:0x%016llx\n",local_138[0x1d],
                   local_138[0x1e],local_138[0x1f]);
      iVar4 = 0;
      do {
        while (iVar7 = (**(code **)(param_2 + 0x588))(param_1,param_2,iVar4,&local_140), iVar7 == 0)
        {
          iVar7 = iVar4 + 1;
          nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x266,"kflcnCoreDumpDestructive_IMPL"
                       ,4,"NVRM: ICD: csr[%03x] = 0x%016llx\n",iVar4,local_140);
          iVar4 = iVar7;
          if (iVar7 == 0x1000) goto LAB_0031f719;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 0x1000);
LAB_0031f719:
      if ((local_150 == 0) || (iVar4 = 0, local_148 == 0)) {
        return 0;
      }
      do {
        if ((local_148 == 0) || ((local_150 == 0 || ((local_148 & 7) != 0)))) {
LAB_0031f97a:
          if (iVar4 != 0) goto LAB_0031f834;
          pcVar6 = "NVRM: ICD: [WARN] unwind retrieved zero values :(\n";
          uVar5 = 0x28e;
          goto LAB_0031f84c;
        }
        lVar2 = local_148 - 8;
        local_148 = local_148 - 0x10;
        iVar7 = (**(code **)(param_2 + 0x578))(param_1,param_2,lVar2,8,&local_150);
        if ((iVar7 != 0) ||
           (iVar7 = (**(code **)(param_2 + 0x578))(param_1,param_2,local_148,8,&local_148),
           iVar7 != 0)) goto LAB_0031f97a;
        iVar7 = iVar4 + 1;
        nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x282,"kflcnCoreDumpDestructive_IMPL",4
                     ,"NVRM: ICD: unwind%02u: 0x%016llx\n",iVar4,local_150);
        iVar4 = iVar7;
      } while (iVar7 != 0x20);
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",0x287,"kflcnCoreDumpDestructive_IMPL",4,
                   "NVRM: ICD: [WARN] unwind greater than max depth...\n");
LAB_0031f834:
      pcVar6 = "NVRM: ICD: unwind complete.\n";
      uVar5 = 0x294;
LAB_0031f84c:
      nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",uVar5,"kflcnCoreDumpDestructive_IMPL",4,
                   pcVar6);
      return 0;
    }
    pcVar6 = "NVRM: ICD: [ERROR] ICD Halt command failed.\n";
    uVar5 = 0x21f;
  }
  nvDbg_Printf("src/kernel/gpu/falcon/kernel_falcon.c",uVar5,"kflcnCoreDumpDestructive_IMPL",4,
               pcVar6);
  return 0;
}


// ===== 0031fa10 subdeviceCtrlCmdFlcnGetCtxBufferInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdFlcnGetCtxBufferInfo_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  char *pcVar10;
  ulong uVar11;
  undefined8 uVar12;
  long *local_50;
  undefined8 local_48;
  long local_40;
  undefined8 local_38;
  int local_30;
  undefined4 uStack_2c;
  
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_38 = 0;
  if (*(char *)(lVar2 + 0x908) == '\0') {
    if (*(char *)(lVar2 + 0x4913) != '\0') {
      cVar1 = *(char *)(lVar2 + 0x491e);
      goto joined_r0x0031fafd;
    }
  }
  else {
    if (*(char *)(lVar2 + 0x4913) == '\0') goto LAB_0031fb03;
    cVar1 = *(char *)(lVar2 + 0x491e);
joined_r0x0031fafd:
    if (cVar1 != '\0') {
LAB_0031fb03:
      lVar7 = resservGetTlsCallContext();
      puVar3 = *(undefined4 **)(lVar7 + 0x48);
      lVar7 = gpuGetRpc(lVar2);
      if (lVar7 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0x3c);
        return 0x1a;
      }
      if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
        iVar5 = rpcDmaControl_wrapper
                          (lVar2,lVar7,*puVar3,puVar3[1],puVar3[2],*(undefined8 *)(puVar3 + 4),
                           puVar3[6]);
        return iVar5;
      }
      iVar5 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58);
      return iVar5;
    }
  }
  iVar5 = serverGetClientUnderLock(g_resServ,*param_2,&local_48);
  uVar12 = 0x46;
  pcVar10 = "serverGetClientUnderLock(&g_resServ, pParams->hUserClient, &pUserClient)";
  if (iVar5 != 0) {
LAB_0031fcf4:
    nvCheckOkFailedNoLog(1,iVar5,pcVar10,"src/kernel/gpu/falcon/kernel_falcon_ctrl.c",uVar12);
    return iVar5;
  }
  iVar5 = CliGetKernelChannel(local_48,param_2[1],&local_40,
                              "src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0x46);
  if (iVar5 != 0) {
    uVar12 = 0x49;
    pcVar10 = "CliGetKernelChannel(pUserClient, pParams->hChannel, &pKernelChannel)";
    goto LAB_0031fcf4;
  }
  if (local_40 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0x4b);
    return 0x21;
  }
  if (*(int *)(local_40 + 0x42c) != 0x31) {
    return 0x56;
  }
  iVar5 = kchangrpGetEngineContextMemDesc_IMPL
                    (lVar2,*(undefined8 *)(*(long *)(local_40 + 0x2b8) + 0x138),&local_50);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,
               "kchangrpGetEngineContextMemDesc(pGpu, pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup, &pMemDesc)"
               ,"src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0x59);
    return iVar5;
  }
  plVar8 = (long *)memdescGetRootMemDesc(local_50,0);
  *(long **)(param_2 + 6) = local_50;
  uVar4 = memdescGetContiguity(local_50,1);
  *(undefined1 *)(param_2 + 0xf) = uVar4;
  uVar6 = memdescGetAddressSpace(local_50);
  param_2[0xc] = uVar6;
  *(long *)(param_2 + 8) = local_50[3];
  uVar6 = memdescGetPteKindForGpu(local_50,*local_50);
  param_2[0xd] = uVar6;
  uVar6 = kgmmuGetExternalAllocAperture_IMPL(param_2[0xc]);
  memdescGetPhysAddrsForGpu(local_50,*local_50,1,0,0,1,&local_30);
  uVar12 = kgmmuEncodePhysAddr_IMPL
                     (*(undefined8 *)(*local_50 + 0x1b98),uVar6,CONCAT44(uStack_2c,local_30),
                      0xffffffffffffffff);
  *(undefined8 *)(param_2 + 10) = uVar12;
  uVar9 = memdescGetPageSize(local_50,1);
  if (uVar9 == 0) {
    iVar5 = (**(code **)(*(long *)(*local_50 + 0x1b78) + 0x388))();
    if (iVar5 != 0) {
      return iVar5;
    }
    uVar9 = memdescGetPageSize(local_50,1);
    if (uVar9 == 0) {
      nvAssertFailedNoLog("pageSize != 0","src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0x7a);
      *(undefined8 *)(param_2 + 2) = 0;
      *(long *)(param_2 + 4) = local_50[7];
      uVar6 = 0;
      goto LAB_0031fd4d;
    }
  }
  uVar11 = local_50[5] + -1 + uVar9 & -uVar9;
  if (local_50[5] == 0) {
    uVar11 = uVar9;
  }
  *(ulong *)(param_2 + 2) = uVar11;
  uVar6 = (undefined4)uVar9;
  *(long *)(param_2 + 4) = local_50[7];
  if (uVar9 >> 0x20 != 0) {
    nvAssertFailedNoLog("pageSize <= NV_U32_MAX","src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0x86);
    return 0x40;
  }
LAB_0031fd4d:
  param_2[0xe] = uVar6;
  lVar7 = *plVar8;
  *(bool *)((long)param_2 + 0x3d) = lVar7 != 0;
  iVar5 = 0;
  if (lVar7 != 0) {
    iVar5 = gpuGetGidInfo_IMPL(lVar2,&local_38,&local_30,2);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"gpuGetGidInfo(pGpu, &pUuid, &uuidLength, flags)",
                 "src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0x91);
      return iVar5;
    }
    if (local_30 == 0x10) {
      portMemCopy((long)param_2 + 0x3e,0x10,local_38,0x10);
      iVar5 = 0;
    }
    else {
      iVar5 = 0x1f;
    }
  }
  portMemFree(local_38);
  return iVar5;
}


// ===== 0031fef0 subdeviceCtrlCmdFlcnGetCtxBufferSize_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int subdeviceCtrlCmdFlcnGetCtxBufferSize_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long *local_28;
  long local_20;
  
  local_20 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar6 + 0x908) == '\0') {
    if (*(char *)(lVar6 + 0x4913) != '\0') {
      cVar1 = *(char *)(lVar6 + 0x491e);
      goto joined_r0x0031ff93;
    }
  }
  else {
    if (*(char *)(lVar6 + 0x4913) == '\0') goto LAB_0031ff95;
    cVar1 = *(char *)(lVar6 + 0x491e);
joined_r0x0031ff93:
    if (cVar1 != '\0') {
LAB_0031ff95:
      lVar4 = resservGetTlsCallContext();
      puVar2 = *(undefined4 **)(lVar4 + 0x48);
      lVar4 = gpuGetRpc(lVar6);
      if (lVar4 == 0) {
        nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0xbc);
        iVar3 = 0x1a;
      }
      else {
        if ((*(char *)(lVar6 + 0x909) != '\0') || (*(char *)(lVar6 + 0x90a) != '\0')) {
          iVar3 = (**(code **)(lVar6 + 0x3b90))(lVar6 + 0x3b58);
          return iVar3;
        }
        iVar3 = rpcDmaControl_wrapper
                          (lVar6,lVar4,*puVar2,puVar2[1],puVar2[2],*(undefined8 *)(puVar2 + 4),
                           puVar2[6]);
      }
      return iVar3;
    }
  }
  iVar3 = CliGetKernelChannel(**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),*param_2,
                              &local_20);
  if (iVar3 != 0) {
    nvCheckOkFailedNoLog
              (1,iVar3,
               "CliGetKernelChannel(RES_GET_CLIENT(pSubdevice), pParams->hChannel, &pKernelChannel)"
               ,"src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0xc6);
    return iVar3;
  }
  if (local_20 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0xc9);
    return 0x21;
  }
  if (*(int *)(local_20 + 0x42c) != 0x31) {
    return 0x56;
  }
  iVar3 = kchangrpGetEngineContextMemDesc_IMPL
                    (lVar6,*(undefined8 *)(*(long *)(local_20 + 0x2b8) + 0x138),&local_28);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,
               "kchangrpGetEngineContextMemDesc(pGpu, pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup, &pMemDesc)"
               ,"src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0xd7);
    return iVar3;
  }
  uVar5 = memdescGetPageSize(local_28,1);
  if (uVar5 == 0) {
    iVar3 = (**(code **)(*(long *)(*local_28 + 0x1b78) + 0x388))();
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar5 = memdescGetPageSize(local_28,1);
    if (uVar5 != 0) goto LAB_003200d8;
    nvAssertFailedNoLog("pageSize != 0","src/kernel/gpu/falcon/kernel_falcon_ctrl.c",0xe5);
  }
  else {
LAB_003200d8:
    if ((local_28[5] == 0) || (uVar5 = -uVar5 & local_28[5] + -1 + uVar5, uVar5 != 0)) {
      lVar6 = uVar5 + ((uVar5 - 1) + local_28[7] & -uVar5);
      goto LAB_003200f2;
    }
  }
  lVar6 = local_28[7];
LAB_003200f2:
  *(long *)(param_2 + 2) = lVar6;
  return 0;
}


// ===== 003201d0 kfifoPrintInternalEngine_AD102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoPrintInternalEngine_AD102(long param_1,long param_2,uint param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint local_2c;
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  cVar2 = kfifoIsMmuFaultEngineIdPbdma_IMPL();
  if (cVar2 != '\0') {
    pcVar4 = (char *)kfifoPrintFaultingPbdmaEngineName_IMPL(param_1,param_2,param_3);
    return pcVar4;
  }
  cVar2 = (**(code **)(lVar1 + 0x378))(lVar1,param_3);
  pcVar4 = "BAR1";
  if (cVar2 == '\0') {
    cVar2 = (**(code **)(lVar1 + 0x380))(lVar1,param_3);
    pcVar4 = "BAR2";
    if (cVar2 == '\0') {
      if (param_3 == 0x11) {
        pcVar4 = "CE2";
      }
      else {
        if (param_3 < 0x12) {
          if (param_3 == 10) {
            return "OFA";
          }
          if (10 < param_3) {
            if (param_3 == 0xe) {
              return "SEC";
            }
            if (0xe < param_3) {
              if (param_3 == 0xf) {
                return "CE0";
              }
              return "CE1";
            }
            if (param_3 == 0xc) {
              return "NVENC1";
            }
            if (param_3 == 0xd) {
              return "NVENC2";
            }
            return "NVENC0";
          }
          if (param_3 == 6) {
            return "PMU";
          }
          if (param_3 < 7) {
            if (param_3 == 3) {
              return "PTP";
            }
            if (param_3 == 4) {
              return "FLA";
            }
            if (param_3 == 1) {
              return "DISPLAY";
            }
          }
          else {
            if (param_3 == 8) {
              return "PERF";
            }
            if (param_3 == 9) {
              return "IFB";
            }
          }
        }
        else {
          if (param_3 == 0x18) {
            return "NVJPG3";
          }
          if (param_3 < 0x19) {
            if (param_3 == 0x15) {
              return "NVJPG0";
            }
            if (0x15 < param_3) {
              if (param_3 == 0x16) {
                return "NVJPG1";
              }
              return "NVJPG2";
            }
            if (param_3 == 0x13) {
              return "CE4";
            }
            if (param_3 == 0x14) {
              return "CE5";
            }
            return "CE3";
          }
          if (param_3 == 0x1b) {
            return "NVDEC2";
          }
          if (param_3 < 0x1c) {
            if (param_3 == 0x19) {
              return "NVDEC0";
            }
            return "NVDEC1";
          }
          if (param_3 == 0x1c) {
            return "NVDEC3";
          }
          if (param_3 == 0x1f) {
            return "PHYSICAL";
          }
        }
        pcVar4 = (char *)(**(code **)(param_2 + 0x338))(param_1,param_2,param_3);
        if (pcVar4 == (char *)0x0) {
          iVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,4,param_3,0,&local_2c);
          if (((iVar3 == 0) && (local_2c >> 8 == 0xd334df)) && (local_2c + 0x2ccb2100 < 8)) {
            pcVar4 = *(char **)(CSWTCH_8 + (ulong)(local_2c + 0x2ccb2100) * 8);
          }
          else {
            pcVar4 = "UNKNOWN";
          }
        }
      }
    }
  }
  return pcVar4;
}


// ===== 003204e0 kfifoGetClientIdString_AD102 =====

undefined8 kfifoGetClientIdString_AD102(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((*(char *)(param_3 + 0x10) == '\0') && (uVar1 = *(int *)(param_3 + 0xc) - 0x72, uVar1 < 3)) {
    return *(undefined8 *)(CSWTCH_10 + (ulong)uVar1 * 8);
  }
  uVar2 = kfifoGetClientIdString_GA100();
  return uVar2;
}


// ===== 00320510 kchannelIsUserdAddrSizeValid_GA100 =====

uint kchannelIsUserdAddrSizeValid_GA100(undefined8 param_1,uint param_2,uint param_3)

{
  undefined8 in_RAX;
  
  return (uint)CONCAT71((int7)((ulong)in_RAX >> 8),param_2 < 0x1000000) &
         CONCAT31((int3)(param_3 >> 8),param_3 < 0x100);
}


// ===== 00320530 kchannelCreateUserMemDesc_GA10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelCreateUserMemDesc_GA10B(long param_1,long param_2)

{
  long lVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 uVar8;
  long local_40 [2];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  lVar7 = gpuGetKernelFifoShared_IMPL();
  local_40[0] = 0;
  uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar5 = (**(code **)(lVar7 + 0x1c0))(param_1,lVar7,param_2,1,local_40);
  if (iVar5 == 0) {
    if (local_40[0] == 0) {
      iVar5 = 0x57;
      nvAssertFailedNoLog("pSubDevInstMemDesc != NULL",
                          "src/kernel/gpu/fifo/arch/ampere/kernel_channel_ga10b.c",0x35);
    }
    else {
      uVar6 = *(undefined4 *)(local_40[0] + 0x74);
      uVar4 = memdescGetAddressSpace();
      uVar2 = memdescGetContiguity(local_40[0],1);
      iVar5 = memdescCreate(param_2 + 0x318 + (ulong)uVar3 * 8,param_1,0x1000,0,uVar2,uVar4,uVar6,
                            0x2000000);
      if (iVar5 == 0) {
        param_2 = param_2 + (ulong)uVar3 * 8;
        if (*(long *)(param_2 + 0x318) == 0) {
          iVar5 = 0x51;
          nvAssertFailedNoLog("*ppMemDesc != NULL",
                              "src/kernel/gpu/fifo/arch/ampere/kernel_channel_ga10b.c",0x40);
        }
        else {
          uVar8 = memdescGetPhysAddr(local_40[0],1,0);
          uVar6 = memdescGetAddressSpace(local_40[0]);
          memdescDescribe(*(undefined8 *)(param_2 + 0x318),uVar6,uVar8,0x1000);
          (**(code **)(lVar1 + 0x388))(param_1,lVar1,*(undefined8 *)(param_2 + 0x318),1,1);
        }
      }
    }
  }
  return iVar5;
}


// ===== 003206b0 kfifoEngineInfoXlate_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoEngineInfoXlate_GA100
                (long param_1,long param_2,int param_3,uint param_4,int param_5,int *param_6)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  uint local_44;
  int local_40;
  int local_3c [3];
  
  if ((param_3 == 7) || (param_5 == 7)) {
    return 0x56;
  }
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x1bc8);
    cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    if (cVar2 != '\0') {
      uVar3 = kfifoEngineInfoXlate_GV100(param_1,param_2,0,0xd334df00,4,&local_44);
      if (uVar3 == 0) {
        if (((param_3 == 4) &&
            (iVar4 = (**(code **)(param_2 + 0x1e8))(param_1,param_2,0), local_44 <= param_4)) &&
           (param_4 < iVar4 + local_44)) {
          uVar3 = kgrmgrGetGrIdxForVeid_IMPL(param_1,uVar1,param_4 - local_44,local_3c);
          if (uVar3 != 0) {
            nvAssertOkFailedNoLog
                      (uVar3,"kgrmgrGetGrIdxForVeid(pGpu, pKernelGraphicsManager, subctxId, &grIdx)"
                       ,"src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x4e);
            return (ulong)uVar3;
          }
          param_3 = 2;
          param_4 = local_3c[0] + 1;
        }
        if (param_5 != 4) goto LAB_00320703;
        uVar5 = kfifoEngineInfoXlate_GV100(param_1,param_2,param_3,param_4,2,local_3c);
        if ((int)uVar5 == 0) {
          if (7 < local_3c[0] - 1U) goto LAB_00320703;
          uVar5 = kgrmgrGetVeidBaseForGrIdx_IMPL(param_1,uVar1,local_3c[0] - 1U,&local_40);
          if ((int)uVar5 == 0) {
            *param_6 = local_40 + local_44;
          }
          else {
            nvAssertOkFailedNoLog
                      (uVar5 & 0xffffffff,
                       "kgrmgrGetVeidBaseForGrIdx(pGpu, pKernelGraphicsManager, grIdx, &startSubctxId)"
                       ,"src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",99);
            uVar5 = uVar5 & 0xffffffff;
          }
        }
      }
      else {
        nvAssertOkFailedNoLog
                  (uVar3,
                   "kfifoEngineInfoXlate_GV100(pGpu, pKernelFifo, ENGINE_INFO_TYPE_ENG_DESC, ENG_GR(0), ENGINE_INFO_TYPE_MMU_FAULT_ID, &baseGrFaultId)"
                   ,"src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x41);
        uVar5 = (ulong)uVar3;
      }
      return uVar5;
    }
  }
LAB_00320703:
  uVar5 = kfifoEngineInfoXlate_GV100(param_1,param_2,param_3,param_4,param_5,param_6);
  return uVar5;
}


// ===== 003208a0 kfifoChannelGroupGetLocalMaxSubcontext_GA100 =====

ulong kfifoChannelGroupGetLocalMaxSubcontext_GA100
                (long param_1,undefined8 param_2,long param_3,char param_4)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  ulong uVar4;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroup != NULL",
                        "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x81);
    return 0x1f;
  }
  if (*(long *)(param_1 + 0x1bc0) != 0) {
    lVar1 = *(long *)(param_1 + 0x1bc8);
    cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL();
    if (((param_4 == '\0') && (cVar2 != '\0')) && (uVar3 = *(int *)(param_3 + 0xfc) - 1, uVar3 < 8))
    {
      uVar4 = *(ulong *)(lVar1 + 0x448 + (ulong)uVar3 * 8);
      uVar4 = uVar4 - (uVar4 >> 1 & 0x5555555555555555);
      uVar4 = (uVar4 & 0x3333333333333333) + (uVar4 >> 2 & 0x3333333333333333);
      return ((uVar4 >> 4) + uVar4 & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38;
    }
  }
  uVar4 = kfifoChannelGroupGetLocalMaxSubcontext_GM107(param_1,param_2,param_3,param_4);
  return uVar4;
}


// ===== 003209b0 kfifoUpdateUsermodeDoorbell_GA100 =====

undefined8 kfifoUpdateUsermodeDoorbell_GA100(long param_1,undefined8 param_2,undefined4 param_3)

{
  nvDbg_Printf("src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xa0,
               "kfifoUpdateUsermodeDoorbell_GA100",1,"NVRM: Poking workSubmitToken 0x%x\n",param_3);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30090,param_3,0);
  return 0;
}


// ===== 00320a20 kfifoGenerateWorkSubmitTokenHal_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGenerateWorkSubmitTokenHal_GA100
              (undefined8 param_1,long param_2,long param_3,uint *param_4,char param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_40;
  uint local_3c [3];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xc0);
    return 0x21;
  }
  if (param_4 == (uint *)0x0) {
    iVar2 = 0x31;
    nvAssertFailedNoLog("pGeneratedToken != NULL",
                        "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xc2);
  }
  else {
    if ((*(long *)(param_3 + 0x2b8) == 0) || (*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) == 0)) {
      nvAssertFailedNoLog("(pKernelChannel->pKernelChannelGroupApi != NULL) && (pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup != NULL)"
                          ,"src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xc3);
      return 0x40;
    }
    uVar5 = *(uint *)(param_3 + 0x2b4);
    iVar2 = vgpuGetCallingContextGfid(param_1,&local_40);
    if (iVar2 == 0) {
      if (((param_5 == '\0') && (local_40 != 0)) &&
         (iVar3 = (**(code **)(param_2 + 0x2c8))
                            (param_1,param_2,uVar5,local_40,*(undefined4 *)(param_3 + 0x42c),
                             local_3c), uVar5 = local_3c[0], iVar3 != 0)) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kfifoGetVChIdForSChId_HAL(pGpu, pKernelFifo, chId, gfId, kchannelGetEngineType(pKernelChannel), &vChId)"
                   ,"src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xd0);
        return iVar3;
      }
      cVar1 = kchannelIsRunlistSet(param_1,param_3);
      if (cVar1 == '\0') {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xd9,
                     "kfifoGenerateWorkSubmitTokenHal_GA100",2,
                     "NVRM: FAILED Channel 0x%x is not assigned to runlist yet\n",uVar5);
        return 0x40;
      }
      uVar4 = (*(uint *)(param_3 + 0x2b0) & 0x7f) << 0x10 | uVar5 & 0xfff;
      nvDbg_Printf("src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xe5,
                   "kfifoGenerateWorkSubmitTokenHal_GA100",1,
                   "NVRM: Generated workSubmitToken 0x%x for channel 0x%x runlist 0x%x\n",uVar4,
                   uVar5,*(uint *)(param_3 + 0x2b0));
      *param_4 = uVar4;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"vgpuGetCallingContextGfid(pGpu, &gfId)",
                 "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0xc9);
    }
  }
  return iVar2;
}


// ===== 00320c90 kfifoRunlistGetBaseShift_GA100 =====

undefined8 kfifoRunlistGetBaseShift_GA100(void)

{
  return 0xc;
}


// ===== 00320ca0 kfifoGetMaxCeChannelGroups_GA100 =====

int kfifoGetMaxCeChannelGroups_GA100(long param_1,long param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  uint *puVar5;
  long lVar6;
  int iVar7;
  
  lVar4 = *(long *)(param_2 + 0x3d8);
  if (lVar4 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    if (*(int *)(param_2 + 0x3d0) != 0) {
      iVar7 = 0;
      lVar6 = 0;
      do {
        puVar5 = (uint *)(lVar4 + lVar6 * 0x60);
        uVar1 = *puVar5;
        if (uVar1 == 0xd334df00) {
          iVar3 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,0);
LAB_00320d2a:
          iVar7 = iVar7 + iVar3;
          if (*(uint *)(param_2 + 0x3d0) <= (int)lVar6 + 1U) break;
        }
        else {
          if ((uVar1 >> 8 == 0x793ceb) && (cVar2 = ceIsCeGrce(param_1,puVar5[2]), cVar2 == '\0')) {
            iVar3 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,0);
            goto LAB_00320d2a;
          }
          if (*(uint *)(param_2 + 0x3d0) <= (int)lVar6 + 1U) break;
        }
        lVar6 = lVar6 + 1;
        lVar4 = *(long *)(param_2 + 0x3d8);
      } while( true );
    }
    if (*(char *)(*(long *)(&DAT_00001b90 + param_1) + 0xad0d) != '\0') {
      iVar7 = 0x1000;
    }
  }
  return iVar7;
}


// ===== 00320da0 kfifoGetEnginePbdmaFaultIds_GA100 =====

int kfifoGetEnginePbdmaFaultIds_GA100
              (undefined8 param_1,long param_2,uint param_3,uint param_4,long *param_5,
              undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  if (*(long *)(param_2 + 0x3d8) == 0) {
    *param_6 = 0;
    iVar2 = kfifoConstructEngineList_KERNEL();
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"kfifoConstructEngineList_HAL(pGpu, pKernelFifo)",
                 "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x14b);
      return iVar2;
    }
    if (*(long *)(param_2 + 0x3d8) == 0) {
      nvAssertFailedNoLog("pEngineInfo != NULL",
                          "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x14e);
      return 0x40;
    }
  }
  else {
    *param_6 = 0;
  }
  uVar1 = *(uint *)(param_2 + 0x3d0);
  if (param_3 == 0xf) {
    if (param_4 < uVar1) {
      *param_5 = *(long *)(param_2 + 0x3d8) + 0x44 + (ulong)param_4 * 0x60;
      *param_6 = *(undefined4 *)(*(long *)(param_2 + 0x3d8) + 0x4c + (ulong)param_4 * 0x60);
      return 0;
    }
    nvAssertFailedNoLog("val < pEngineInfo->engineInfoListSize",
                        "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x153);
    return 0x1f;
  }
  if (uVar1 != 0) {
    lVar3 = 0;
    do {
      if (*(uint *)(*(long *)(param_2 + 0x3d8) + (ulong)param_3 * 4 + lVar3) == param_4) {
        *param_5 = lVar3 + 0x44 + *(long *)(param_2 + 0x3d8);
        *param_6 = *(undefined4 *)(*(long *)(param_2 + 0x3d8) + 0x4c + lVar3);
        return 0;
      }
      lVar3 = lVar3 + 0x60;
    } while (lVar3 != (ulong)uVar1 * 0x60);
  }
  return 0x57;
}


// ===== 00320efc kfifoGetNumPBDMAs_GA100.cold =====

void kfifoGetNumPBDMAs_GA100_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00320f10 kfifoGetNumPBDMAs_GA100 =====

int kfifoGetNumPBDMAs_GA100(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  if (*(long *)(param_2 + 0x3d8) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  nvDbg_Printf("src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x175,"kfifoGetNumPBDMAs_GA100"
               ,1,"NVRM: %d PBDMAs\n",*(undefined4 *)(param_2 + 0x380));
  if (*(int *)(param_2 + 0x380) != 0) {
    return *(int *)(param_2 + 0x380);
  }
  nvAssertFailedNoLog("pEngineInfo->maxNumPbdmas != 0",
                      "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x176);
  return *(int *)(param_2 + 0x380);
}


// ===== 00320fa0 kfifoPrintInternalEngine_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoPrintInternalEngine_GA100(long param_1,long param_2,uint param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint local_2c;
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  cVar2 = kfifoIsMmuFaultEngineIdPbdma_IMPL();
  if (cVar2 != '\0') {
    pcVar4 = (char *)kfifoPrintFaultingPbdmaEngineName_IMPL(param_1,param_2,param_3);
    return pcVar4;
  }
  cVar2 = (**(code **)(lVar1 + 0x378))(lVar1,param_3);
  pcVar4 = "BAR1";
  if (cVar2 == '\0') {
    cVar2 = (**(code **)(lVar1 + 0x380))(lVar1,param_3);
    pcVar4 = "BAR2";
    if (cVar2 == '\0') {
      if (param_3 == 0x12) {
        pcVar4 = "CE3";
      }
      else {
        if (param_3 < 0x13) {
          if (param_3 == 10) {
            return "OFA";
          }
          if (param_3 < 0xb) {
            if (param_3 == 6) {
              return "PMU";
            }
            if (param_3 < 7) {
              if (param_3 == 3) {
                return "PTP";
              }
              if (param_3 == 4) {
                return "FLA";
              }
              if (param_3 == 1) {
                return "DISPLAY";
              }
            }
            else {
              if (param_3 == 8) {
                return "PERF";
              }
              if (param_3 == 9) {
                return "IFB";
              }
            }
          }
          else {
            if (param_3 == 0xf) {
              return "CE0";
            }
            if (0xf < param_3) {
              if (param_3 == 0x10) {
                return "CE1";
              }
              return "CE2";
            }
            if (param_3 == 0xc) {
              return "NVENC1";
            }
            if (param_3 == 0xe) {
              return "SEC";
            }
          }
        }
        else {
          if (param_3 == 0x19) {
            return "NVDEC0";
          }
          if (param_3 < 0x1a) {
            if (param_3 == 0x16) {
              return "CE7";
            }
            if (0x16 < param_3) {
              if (param_3 == 0x17) {
                return "CE8";
              }
              return "CE9";
            }
            if (param_3 == 0x14) {
              return "CE5";
            }
            if (param_3 == 0x15) {
              return "CE6";
            }
            return "CE4";
          }
          if (param_3 == 0x1c) {
            return "NVDEC3";
          }
          if (param_3 < 0x1d) {
            if (param_3 == 0x1a) {
              return "NVDEC1";
            }
            return "NVDEC2";
          }
          if (param_3 == 0x1e) {
            return "NVJPG";
          }
          if (param_3 == 0x1f) {
            return "PHYSICAL";
          }
        }
        pcVar4 = (char *)(**(code **)(param_2 + 0x338))(param_1,param_2,param_3);
        if (pcVar4 == (char *)0x0) {
          iVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,4,param_3,0,&local_2c);
          if (((iVar3 == 0) && (local_2c >> 8 == 0xd334df)) && (local_2c + 0x2ccb2100 < 8)) {
            pcVar4 = *(char **)(CSWTCH_45 + (ulong)(local_2c + 0x2ccb2100) * 8);
          }
          else {
            pcVar4 = "UNKNOWN";
          }
        }
      }
    }
  }
  return pcVar4;
}


// ===== 003212b0 kfifoPrintInternalEngineCheck_GA100 =====

char * kfifoPrintInternalEngineCheck_GA100(undefined8 param_1,undefined8 param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = "NVENC0";
  if ((param_3 != 0xb) && (pcVar1 = "NVDEC4", param_3 != 0x1d)) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}


// ===== 003212e0 kfifoGetClientIdString_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoGetClientIdString_GA100(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = *(uint *)(param_3 + 0xc);
  if (*(char *)(param_3 + 0x10) == '\0') {
    if (uVar1 == 0x2e) {
      return "HUBCLIENT_PTP_X3";
    }
    if (0x2e < uVar1) {
      if (uVar1 == 0x4e) {
        return "HUBCLIENT_FE1";
      }
      if (uVar1 < 0x4f) {
        if (uVar1 == 0x3a) {
          return "HUBCLIENT_NVDEC1";
        }
        if (uVar1 < 0x3b) {
          if (uVar1 == 0x34) {
            return "HUBCLIENT_VPR_SCRUBBER0";
          }
          if (0x34 < uVar1) {
            if (uVar1 == 0x37) {
              return "HUBCLIENT_FBFALCON";
            }
            if (0x37 < uVar1) {
              pcVar2 = "HUBCLIENT_CE_SHIM";
              if (uVar1 != 0x38) {
                pcVar2 = "HUBCLIENT_GSP";
              }
              return pcVar2;
            }
            pcVar2 = "HUBCLIENT_VPR_SCRUBBER1";
            if (uVar1 != 0x35) {
              pcVar2 = "HUBCLIENT_DWBIF";
            }
            return pcVar2;
          }
          if (uVar1 == 0x31) {
            return "HUBCLIENT_PTP_X6";
          }
          if (0x31 < uVar1) {
            pcVar2 = "HUBCLIENT_PTP_X7";
            if (uVar1 != 0x32) {
              pcVar2 = "HUBCLIENT_NVENC2";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_PTP_X4";
          if (uVar1 != 0x2f) {
            pcVar2 = "HUBCLIENT_PTP_X5";
          }
          return pcVar2;
        }
        if (uVar1 == 0x41) {
          return "HUBCLIENT_HSCE11";
        }
        if (uVar1 < 0x42) {
          if (uVar1 == 0x3d) {
            return "HUBCLIENT_NVDEC3";
          }
          if (uVar1 < 0x3e) {
            pcVar2 = "HUBCLIENT_NVDEC2";
            if (uVar1 != 0x3b) {
              pcVar2 = "HUBCLIENT_NVJPG0";
            }
            return pcVar2;
          }
          if (uVar1 == 0x3f) {
            return "HUBCLIENT_OFA0";
          }
          if (uVar1 == 0x40) {
            return "HUBCLIENT_HSCE10";
          }
        }
        else {
          if (uVar1 == 0x44) {
            return "HUBCLIENT_HSCE14";
          }
          if (uVar1 < 0x45) {
            pcVar2 = "HUBCLIENT_HSCE12";
            if (uVar1 != 0x42) {
              pcVar2 = "HUBCLIENT_HSCE13";
            }
            return pcVar2;
          }
          if (uVar1 == 0x45) {
            return "HUBCLIENT_HSCE15";
          }
        }
      }
      else {
        if (uVar1 == 0x59) {
          return "HUBCLIENT_FECS5";
        }
        if (uVar1 < 0x5a) {
          if (uVar1 == 0x54) {
            return "HUBCLIENT_FE7";
          }
          if (uVar1 < 0x55) {
            if (uVar1 == 0x51) {
              return "HUBCLIENT_FE4";
            }
            if (0x51 < uVar1) {
              pcVar2 = "HUBCLIENT_FE5";
              if (uVar1 != 0x52) {
                pcVar2 = "HUBCLIENT_FE6";
              }
              return pcVar2;
            }
            pcVar2 = "HUBCLIENT_FE2";
            if (uVar1 != 0x4f) {
              pcVar2 = "HUBCLIENT_FE3";
            }
            return pcVar2;
          }
          if (uVar1 == 0x57) {
            return "HUBCLIENT_FECS3";
          }
          if (uVar1 == 0x58) {
            return "HUBCLIENT_FECS4";
          }
          pcVar2 = "HUBCLIENT_FECS1";
          if (uVar1 != 0x55) {
            pcVar2 = "HUBCLIENT_FECS2";
          }
          return pcVar2;
        }
        if (uVar1 == 0x5f) {
          return "HUBCLIENT_SKED4";
        }
        if (uVar1 < 0x60) {
          if (uVar1 == 0x5c) {
            return "HUBCLIENT_SKED1";
          }
          if (0x5c < uVar1) {
            pcVar2 = "HUBCLIENT_SKED2";
            if (uVar1 != 0x5d) {
              pcVar2 = "HUBCLIENT_SKED3";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_FECS6";
          if (uVar1 != 0x5a) {
            pcVar2 = "HUBCLIENT_FECS7";
          }
          return pcVar2;
        }
        if (uVar1 == 0x62) {
          return "HUBCLIENT_SKED7";
        }
        if (uVar1 < 99) {
          pcVar2 = "HUBCLIENT_SKED5";
          if (uVar1 != 0x60) {
            pcVar2 = "HUBCLIENT_SKED6";
          }
          return pcVar2;
        }
        if (uVar1 == 99) {
          return "HUBCLIENT_ESC";
        }
      }
LAB_00321487:
      pcVar2 = (char *)(**(code **)(param_2 + 0x350))();
      return pcVar2;
    }
    if (uVar1 == 0x17) {
      return "HUBCLIENT_SSYNC";
    }
    if (uVar1 < 0x18) {
      if (uVar1 == 0xb) {
        return "HUBCLIENT_NVDEC0";
      }
      if (uVar1 < 0xc) {
        if (uVar1 == 5) {
          return "HUBCLIENT_FECS";
        }
        if (5 < uVar1) {
          if (uVar1 == 8) {
            return "HUBCLIENT_HOST_CPU_NB";
          }
          if (8 < uVar1) {
            pcVar2 = "HUBCLIENT_ISO";
            if (uVar1 != 9) {
              pcVar2 = "HUBCLIENT_MMU";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_HOST";
          if (uVar1 != 6) {
            pcVar2 = "HUBCLIENT_HOST_CPU";
          }
          return pcVar2;
        }
        if (uVar1 == 2) {
          return "HUBCLIENT_CE1";
        }
        if (2 < uVar1) {
          pcVar2 = "HUBCLIENT_DNISO";
          if (uVar1 != 3) {
            pcVar2 = "HUBCLIENT_FE";
          }
          return pcVar2;
        }
        pcVar2 = "HUBCLIENT_VIP";
        if (uVar1 != 0) {
          pcVar2 = "HUBCLIENT_CE0";
        }
        return pcVar2;
      }
      if (uVar1 == 0x12) {
        return "HUBCLIENT_PMU";
      }
      if (uVar1 < 0x13) {
        if (uVar1 == 0xf) {
          return "HUBCLIENT_P2P";
        }
        if (0xf < uVar1) {
          pcVar2 = "HUBCLIENT_PD";
          if (uVar1 != 0x10) {
            pcVar2 = "HUBCLIENT_PERF";
          }
          return pcVar2;
        }
        if (uVar1 == 0xd) {
          return "HUBCLIENT_NVENC1";
        }
        pcVar2 = "HUBCLIENT_NISO";
        if (uVar1 != 0xe) goto LAB_00321487;
      }
      else {
        pcVar2 = "HUBCLIENT_SCC_NB";
        if ((uVar1 != 0x15) && (pcVar2 = "HUBCLIENT_SEC", uVar1 != 0x16)) {
          pcVar2 = "HUBCLIENT_RASTERTWOD";
          if (uVar1 != 0x13) {
            pcVar2 = "HUBCLIENT_SCC";
          }
          return pcVar2;
        }
      }
    }
    else {
      if (uVar1 == 0x23) {
        return "HUBCLIENT_HSCE3";
      }
      if (uVar1 < 0x24) {
        if (uVar1 == 0x1e) {
          return "HUBCLIENT_AFALCON";
        }
        if (uVar1 < 0x1f) {
          if (uVar1 == 0x1a) {
            return "HUBCLIENT_MMU_NB";
          }
          if (uVar1 < 0x1b) {
            pcVar2 = "HUBCLIENT_CE2";
            if (uVar1 != 0x18) {
              pcVar2 = "HUBCLIENT_XV";
            }
            return pcVar2;
          }
          if (uVar1 == 0x1c) {
            return "HUBCLIENT_DFALCON";
          }
          if (uVar1 == 0x1d) {
            return "HUBCLIENT_SKED";
          }
          goto LAB_00321487;
        }
        pcVar2 = "HUBCLIENT_HSCE1";
        if ((uVar1 != 0x21) && (pcVar2 = "HUBCLIENT_HSCE2", uVar1 != 0x22)) {
          pcVar2 = "HUBCLIENT_DONT_CARE";
          if (uVar1 != 0x1f) {
            pcVar2 = "HUBCLIENT_HSCE0";
          }
          return pcVar2;
        }
      }
      else {
        if (uVar1 == 0x29) {
          return "HUBCLIENT_HSCE9";
        }
        if (uVar1 < 0x2a) {
          if (uVar1 == 0x26) {
            return "HUBCLIENT_HSCE6";
          }
          if (0x26 < uVar1) {
            pcVar2 = "HUBCLIENT_HSCE7";
            if (uVar1 != 0x27) {
              pcVar2 = "HUBCLIENT_HSCE8";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_HSCE4";
          if (uVar1 != 0x24) {
            pcVar2 = "HUBCLIENT_HSCE5";
          }
          return pcVar2;
        }
        pcVar2 = "HUBCLIENT_PTP_X1";
        if ((uVar1 != 0x2c) && (pcVar2 = "HUBCLIENT_PTP_X2", uVar1 != 0x2d)) {
          pcVar2 = "HUBCLIENT_HSHUB";
          if (uVar1 != 0x2a) {
            pcVar2 = "HUBCLIENT_PTP_X0";
          }
          return pcVar2;
        }
      }
    }
  }
  else {
    pcVar2 = "UNRECOGNIZED_CLIENT";
    if (uVar1 < 0x72) {
      return *(char **)(CSWTCH_48 + (ulong)uVar1 * 8);
    }
  }
  return pcVar2;
}


// ===== 00321920 kfifoGetClientIdStringCheck_GA100 =====

char * kfifoGetClientIdStringCheck_GA100(undefined8 param_1,undefined8 param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = "HUBCLIENT_NVENC0";
  if ((param_3 != 0x1b) && (pcVar1 = "HUBCLIENT_NVDEC4", param_3 != 0x3e)) {
    pcVar1 = "UNRECOGNIZED_CLIENT";
  }
  return pcVar1;
}


// ===== 00321950 kfifoStartChannelHalt_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoStartChannelHalt_GA100(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_30;
  int local_2c;
  
  uVar1 = *(undefined4 *)(param_3 + 0x2b0);
  iVar2 = (**(code **)(param_2 + 0x218))(param_1,param_2,3,uVar1,0xe,&local_30);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(param_2 + 0x218))(param_1,param_2,3,uVar1,0xb,&local_2c);
    if (iVar2 == 0) {
      regWrite032(param_1 + 0x3a18,0,0,local_30 + *(int *)(param_3 + 0x2b4) * 4,3,0);
      regWrite032(param_1 + 0x3a18,0,0,local_2c + 0x98,0,0);
      return;
    }
  }
  return;
}


// ===== 00321a30 kfifoCompleteChannelHalt_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoCompleteChannelHalt_GA100(long param_1,long param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  int local_2c [3];
  
  iVar1 = (**(code **)(param_2 + 0x218))
                    (param_1,param_2,3,*(undefined4 *)(param_3 + 0x2b0),0xb,local_2c);
  if (iVar1 == 0) {
    do {
      iVar1 = timeoutCheck(param_1 + 0x1af0,param_4,0x3b4);
      if (iVar1 == 0x65) {
        return;
      }
      uVar2 = regRead032(param_1 + 0x3a18,0,0,local_2c[0] + 0x98,0);
    } while ((uVar2 & 0x200000) != 0);
  }
  return;
}


// ===== 00321ac0 kfifoRingChannelDoorBell_GA100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoRingChannelDoorBell_GA100(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined4 local_c;
  
  uVar1 = kfifoGenerateWorkSubmitToken_IMPL();
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,
               "kfifoGenerateWorkSubmitToken(pGpu, pKernelFifo, pKernelChannel, &workSubmitToken, NV_TRUE)"
               ,"src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x3d3);
    return (ulong)uVar1;
  }
  uVar2 = (**(code **)(param_2 + 0x238))(param_1,param_2,local_c);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,
             "kfifoUpdateUsermodeDoorbell_HAL(pGpu, pKernelFifo, workSubmitToken)",
             "src/kernel/gpu/fifo/arch/ampere/kernel_fifo_ga100.c",0x3d6);
  return uVar2 & 0xffffffff;
}


// ===== 00321b60 kfifoRunlistGetBaseShift_GA102 =====

undefined8 kfifoRunlistGetBaseShift_GA102(void)

{
  return 10;
}


// ===== 00321b70 kchannelIsUserdAddrSizeValid_GB10B =====

uint kchannelIsUserdAddrSizeValid_GB10B(undefined8 param_1,uint param_2,uint param_3)

{
  undefined8 in_RAX;
  
  return (uint)CONCAT71((int7)((ulong)in_RAX >> 8),param_2 < 0x1000000) &
         CONCAT31((int3)(param_3 >> 8),param_3 < 0x100000);
}


// ===== 00321ba0 kfifoReservePbdmaFaultIds_GB100 =====

undefined8
kfifoReservePbdmaFaultIds_GB100(undefined8 param_1,long param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_4 != 0) {
    puVar2 = param_3 + (ulong)param_4 * 0x18;
    do {
      if (*param_3 >> 8 == 0xd334df) {
        uVar1 = param_3[0x11];
        uVar3 = uVar1;
        do {
          uVar4 = uVar3 + 1;
          bitVectorSet_IMPL(param_2 + 0x388,0x200,uVar3);
          uVar3 = uVar4;
        } while (uVar4 != uVar1 + 0x40);
        return 0;
      }
      param_3 = param_3 + 0x18;
    } while (param_3 != puVar2);
  }
  return 0;
}


// ===== 00321c20 kfifoGenerateWorkSubmitTokenHal_GB100 =====

undefined1  [16]
kfifoGenerateWorkSubmitTokenHal_GB100
          (undefined8 param_1,undefined8 param_2,long param_3,uint *param_4)

{
  uint uVar1;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0x68);
    auVar4._8_8_ = extraout_RDX_00;
    auVar4._0_8_ = 0x21;
    return auVar4;
  }
  if (param_4 != (uint *)0x0) {
    if ((*(long *)(param_3 + 0x2b8) != 0) && (*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) != 0)) {
      uVar1 = *(uint *)(param_3 + 0x2b0);
      uVar2 = (uVar1 & 0x7f) << 0x10 | *(uint *)(param_3 + 0x2b4) & 0xfff;
      nvDbg_Printf("src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0x79,
                   "kfifoGenerateWorkSubmitTokenHal_GB100",1,
                   "NVRM: Generated workSubmitToken 0x%x for channel 0x%x runlist 0x%x\n",uVar2,
                   *(uint *)(param_3 + 0x2b4));
      *param_4 = uVar2;
      return ZEXT416(uVar1) << 0x40;
    }
    nvAssertFailedNoLog("(pKernelChannel->pKernelChannelGroupApi != NULL) && (pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup != NULL)"
                        ,"src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0x6b);
    auVar3._8_8_ = extraout_RDX;
    auVar3._0_8_ = 0x40;
    return auVar3;
  }
  nvAssertFailedNoLog("pGeneratedToken != NULL",
                      "src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0x6a);
  auVar5._8_8_ = extraout_RDX_01;
  auVar5._0_8_ = 0x31;
  return auVar5;
}


// ===== 00321d40 kfifoPrintInternalEngine_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoPrintInternalEngine_GB100(undefined8 param_1,long param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = kfifoIsMmuFaultEngineIdPbdma_IMPL();
  if (cVar1 != '\0') {
    pcVar2 = (char *)kfifoPrintFaultingPbdmaEngineName_IMPL(param_1,param_2,param_3);
    return pcVar2;
  }
  if (param_3 != 0x14) {
    pcVar2 = (char *)(**(code **)(param_2 + 0x338))(param_1,param_2,param_3);
    if (pcVar2 != (char *)0x0) {
      return pcVar2;
    }
    pcVar2 = (char *)kfifoPrintInternalEngine_GH100(param_1,param_2,param_3);
    return pcVar2;
  }
  return "GSPLITE";
}


// ===== 00321de0 kfifoGetClientIdString_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kfifoGetClientIdString_GB100(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((*(char *)(param_3 + 0x10) == '\0') && (uVar1 = *(int *)(param_3 + 0xc) - 99, uVar1 < 0xc)) {
    return *(undefined8 *)(CSWTCH_22 + (ulong)uVar1 * 8);
  }
  uVar2 = (**(code **)(param_2 + 0x340))();
  return uVar2;
}


// ===== 00321e10 kfifoWriteRamfcGpfifo_GB100 =====

void kfifoWriteRamfcGpfifo_GB100
               (undefined8 param_1,undefined8 param_2,long param_3,ulong param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_4 & 7) != 0) {
    nvAssertFailedNoLog("FLD_TEST_DRF(_PBDMA, _GP_BASE, _RSVD, _ZERO, NvU64_LO32(gpFifoOffset))",
                        "src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0xf4);
  }
  *(int *)(param_3 + 0x90) = (int)param_4;
  *(uint *)(param_3 + 0x94) = (uint)(param_4 >> 0x20) & 0x1ffffff;
  uVar1 = nvLogBase2(param_5);
  uVar2 = nvLogBase2(param_5);
  if ((uVar1 & 0x1f) == uVar2) {
    uVar1 = *(uint *)(param_3 + 0xb4);
    uVar2 = nvLogBase2(param_5);
    *(uint *)(param_3 + 0xb4) = (uVar2 & 0x1f) << 0x18 | uVar1 & 0xe0ffffff;
    *(undefined4 *)(param_3 + 0x5c) = 0;
    *(undefined4 *)(param_3 + 0xc0) = 0;
    *(undefined4 *)(param_3 + 0x98) = 0;
    return;
  }
  nvAssertFailedNoLog("(nvLogBase2(gpFifoEntries) & DRF_MASK(NV_PBDMA_MISC_FETCH_STATE_GP_INFO_LIMIT2)) == nvLogBase2(gpFifoEntries)"
                      ,"src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0xfb);
  return;
}


// ===== 00321f10 kfifoDisableChannelsForKeyRotation_GB100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoDisableChannelsForKeyRotation_GB100(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long in_R9;
  ulong uVar7;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  long local_40 [2];
  
  lVar2 = *(long *)(param_1 + 0x1d18);
  local_48 = 0;
  local_40[0] = 0;
  if ((*(char *)(lVar2 + 0x2b0) == '\0') || (*(char *)(lVar2 + 0x2b1) == '\0')) {
    return 0x56;
  }
  if (*(int *)(in_R9 + 4) != 0) {
    uVar7 = 0;
    do {
      uVar4 = serverGetClientUnderLock
                        (g_resServ,*(undefined4 *)(in_R9 + 0x18 + uVar7 * 4),&local_48);
      iVar3 = (int)uVar4;
      if (iVar3 != 0) {
        pcVar6 = "NVRM: Failed to get client with hClient = 0x%x status = 0x%x\n";
        uVar1 = *(undefined4 *)(in_R9 + 0x18 + (uVar7 & 0xffffffff) * 4);
        uVar5 = 299;
LAB_00322165:
        nvDbg_Printf("src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",uVar5,
                     "kfifoDisableChannelsForKeyRotation_GB100",4,pcVar6,uVar1,uVar4);
        return iVar3;
      }
      iVar3 = CliGetKernelChannel(local_48,*(undefined4 *)(in_R9 + 0x118 + uVar7 * 4),local_40);
      if (iVar3 != 0) {
        uVar1 = *(undefined4 *)(in_R9 + 0x18 + (uVar7 & 0xffffffff) * 4);
        pcVar6 = "NVRM: Failed to get channel with hclient = 0x%x hChannel = 0x%x status = 0x%x\n";
        uVar4 = (ulong)*(uint *)(in_R9 + 0x118 + (uVar7 & 0xffffffff) * 4);
        uVar5 = 0x134;
        goto LAB_00322165;
      }
      iVar3 = (**(code **)(lVar2 + 0x210))(param_1,lVar2,local_40[0],&local_50,&local_4c);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "confComputeGetKeyPairByChannel_HAL(pGpu, pConfCompute, pKernelChannel, &h2dKey, &d2hKey)"
                   ,"src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0x139);
        return iVar3;
      }
      if ((*(uint *)(lVar2 + 0x304) & 1 << ((byte)((uint)local_50 >> 0x10) & 0x1f)) == 0) {
        return 0x56;
      }
      if (*(int *)(local_40[0] + 0x42c) - 9U < 0x14) {
        iVar3 = (**(code **)(lVar2 + 0x1d0))(lVar2,local_40[0]);
        if (iVar3 != 0) {
          uVar5 = 0x146;
          pcVar6 = "confComputeUpdatePerChannelSecrets_HAL(pConfCompute, pKernelChannel)";
          goto LAB_003220b1;
        }
      }
      else {
        iVar3 = (**(code **)(lVar2 + 0x1c8))(lVar2);
        if (iVar3 != 0) {
          uVar5 = 0x14b;
          pcVar6 = "confComputeUpdateSecrets_HAL(pConfCompute, h2dKey)";
LAB_003220b1:
          nvAssertOkFailedNoLog
                    (iVar3,pcVar6,"src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",uVar5);
          return iVar3;
        }
      }
      uVar7 = uVar7 + 1;
      nvDbg_Printf("src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb100.c",0x14d,
                   "kfifoDisableChannelsForKeyRotation_GB100",1,
                   "NVRM: Key rotation successful for key IDs 0x%x and 0x%x\n",local_50,local_4c);
    } while ((uint)uVar7 < *(uint *)(in_R9 + 4));
  }
  return 0;
}


// ===== 003221b0 kfifoGetClientIdString_GB10B =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoGetClientIdString_GB10B(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  char *pcVar2;
  
  if (*(char *)(param_3 + 0x10) != '\0') goto LAB_0032223e;
  uVar1 = *(uint *)(param_3 + 0xc);
  if (uVar1 == 0x4d) {
    pcVar2 = "HUBCLIENT_PD3";
  }
  else if (uVar1 < 0x4e) {
    if (uVar1 == 0x44) {
      pcVar2 = "HUBCLIENT_SCC3";
    }
    else if (uVar1 < 0x45) {
      if (uVar1 == 0x40) {
        pcVar2 = "HUBCLIENT_SCC1";
      }
      else if (uVar1 < 0x41) {
        if (uVar1 == 0x29) {
          pcVar2 = "HUBCLIENT_SSYNC2";
        }
        else if (uVar1 < 0x2a) {
          if (uVar1 == 0x1e) {
            pcVar2 = "HUBCLIENT_PD1";
          }
          else {
            pcVar2 = "HUBCLIENT_SSYNC1";
            if (uVar1 != 0x28) goto LAB_0032223e;
          }
        }
        else {
          pcVar2 = "HUBCLIENT_SSYNC3";
          if (uVar1 != 0x36) {
LAB_0032223e:
            pcVar2 = (char *)(**(code **)(param_2 + 0x340))();
            return pcVar2;
          }
        }
      }
      else {
        pcVar2 = "HUBCLIENT_SCC2";
        if ((uVar1 != 0x42) && (pcVar2 = "HUBCLIENT_SCC_NB2", uVar1 != 0x43)) {
          pcVar2 = "HUBCLIENT_SCC_NB1";
        }
      }
    }
    else if (uVar1 == 0x49) {
      pcVar2 = "HUBCLIENT_GSPLITE1";
    }
    else if (uVar1 < 0x4a) {
      pcVar2 = "HUBCLIENT_RASTERTWOD2";
      if (((uVar1 != 0x47) && (pcVar2 = "HUBCLIENT_RASTERTWOD3", uVar1 != 0x48)) &&
         (pcVar2 = "HUBCLIENT_SCC_NB3", uVar1 != 0x45)) {
        pcVar2 = "HUBCLIENT_RASTERTWOD1";
      }
    }
    else {
      pcVar2 = "HUBCLIENT_GSPLITE3";
      if ((uVar1 != 0x4b) && (pcVar2 = "HUBCLIENT_PD2", uVar1 != 0x4c)) {
        pcVar2 = "HUBCLIENT_GSPLITE2";
      }
    }
  }
  else if (uVar1 == 0x6b) {
    pcVar2 = "HUBCLIENT_ESC8";
  }
  else if (uVar1 < 0x6c) {
    if (uVar1 == 0x67) {
      pcVar2 = "HUBCLIENT_ESC4";
    }
    else if (uVar1 < 0x68) {
      if (uVar1 == 0x65) {
        pcVar2 = "HUBCLIENT_ESC2";
      }
      else if (uVar1 == 0x66) {
        pcVar2 = "HUBCLIENT_ESC3";
      }
      else if (uVar1 == 99) {
        pcVar2 = "HUBCLIENT_ESC0";
      }
      else {
        pcVar2 = "HUBCLIENT_ESC1";
        if (uVar1 != 100) goto LAB_0032223e;
      }
    }
    else {
      pcVar2 = "HUBCLIENT_ESC6";
      if ((uVar1 != 0x69) && (pcVar2 = "HUBCLIENT_ESC7", uVar1 != 0x6a)) {
        pcVar2 = "HUBCLIENT_ESC5";
      }
    }
  }
  else if (uVar1 == 0x7c) {
    pcVar2 = "HUBCLIENT_VPR_SCRUBBER2";
  }
  else if (uVar1 < 0x7d) {
    if (uVar1 == 0x6e) {
      pcVar2 = "HUBCLIENT_ESC11";
    }
    else if (uVar1 < 0x6f) {
      pcVar2 = "HUBCLIENT_ESC9";
      if (uVar1 != 0x6c) {
        pcVar2 = "HUBCLIENT_ESC10";
      }
    }
    else {
      pcVar2 = "HUBCLIENT_GSPLITE";
      if (uVar1 != 0x7b) goto LAB_0032223e;
    }
  }
  else if (uVar1 == 0x7e) {
    pcVar2 = "HUBCLIENT_VPR_SCRUBBER4";
  }
  else if (uVar1 == 0x7f) {
    pcVar2 = "HUBCLIENT_NVENC3";
  }
  else {
    pcVar2 = "HUBCLIENT_VPR_SCRUBBER3";
    if (uVar1 != 0x7d) goto LAB_0032223e;
  }
  return pcVar2;
}


// ===== 003224c0 kfifoGenerateWorkSubmitTokenHal_GB202 =====

undefined1  [16]
kfifoGenerateWorkSubmitTokenHal_GB202
          (undefined8 param_1,undefined8 param_2,long param_3,uint *param_4)

{
  uint uVar1;
  undefined8 extraout_RDX;
  undefined8 extraout_RDX_00;
  undefined8 extraout_RDX_01;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb202.c",0x3b);
    auVar4._8_8_ = extraout_RDX_00;
    auVar4._0_8_ = 0x21;
    return auVar4;
  }
  if (param_4 != (uint *)0x0) {
    if ((*(long *)(param_3 + 0x2b8) != 0) && (*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) != 0)) {
      uVar1 = *(uint *)(param_3 + 0x2b0);
      uVar2 = (uVar1 & 0x7f) << 0x10 | *(uint *)(param_3 + 0x2b4) & 0xfff | 0x40000000;
      nvDbg_Printf("src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb202.c",0x4c,
                   "kfifoGenerateWorkSubmitTokenHal_GB202",1,
                   "NVRM: Generated workSubmitToken 0x%x for channel 0x%x runlist 0x%x\n",uVar2,
                   *(uint *)(param_3 + 0x2b4));
      *param_4 = uVar2;
      return ZEXT416(uVar1) << 0x40;
    }
    nvAssertFailedNoLog("(pKernelChannel->pKernelChannelGroupApi != NULL) && (pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup != NULL)"
                        ,"src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb202.c",0x3e);
    auVar3._8_8_ = extraout_RDX;
    auVar3._0_8_ = 0x40;
    return auVar3;
  }
  nvAssertFailedNoLog("pGeneratedToken != NULL",
                      "src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb202.c",0x3d);
  auVar5._8_8_ = extraout_RDX_01;
  auVar5._0_8_ = 0x31;
  return auVar5;
}


// ===== 003225e0 kfifoPrintInternalEngineCheck_GB202 =====

undefined8 kfifoPrintInternalEngineCheck_GB202(undefined8 param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_3 - 0x14U < 8) {
    uVar1 = *(undefined8 *)(CSWTCH_9 + (ulong)(param_3 - 0x14U) * 8);
  }
  return uVar1;
}


// ===== 00322600 kfifoGetClientIdString_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoGetClientIdString_GB202(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  char *pcVar2;
  
  if (*(char *)(param_3 + 0x10) != '\0') goto LAB_0032267e;
  uVar1 = *(uint *)(param_3 + 0xc);
  if (uVar1 == 99) {
    pcVar2 = "HUBCLIENT_ESC0";
  }
  else if (uVar1 < 100) {
    if (uVar1 == 0x45) {
      pcVar2 = "HUBCLIENT_SCC_NB3";
    }
    else if (uVar1 < 0x46) {
      if (uVar1 == 0x40) {
        pcVar2 = "HUBCLIENT_SCC1";
      }
      else if (uVar1 < 0x41) {
        if (uVar1 == 0x29) {
          pcVar2 = "HUBCLIENT_SSYNC2";
        }
        else if (uVar1 < 0x2a) {
          if (uVar1 == 0x1e) {
            pcVar2 = "HUBCLIENT_PD1";
          }
          else {
            pcVar2 = "HUBCLIENT_SSYNC1";
            if (uVar1 != 0x28) goto LAB_0032267e;
          }
        }
        else {
          pcVar2 = "HUBCLIENT_SSYNC3";
          if (uVar1 != 0x36) {
LAB_0032267e:
            pcVar2 = (char *)(**(code **)(param_2 + 0x340))();
            return pcVar2;
          }
        }
      }
      else {
        pcVar2 = "HUBCLIENT_SCC_NB2";
        if (((uVar1 != 0x43) && (pcVar2 = "HUBCLIENT_SCC3", uVar1 != 0x44)) &&
           (pcVar2 = "HUBCLIENT_SCC_NB1", uVar1 != 0x41)) {
          pcVar2 = "HUBCLIENT_SCC2";
        }
      }
    }
    else if (uVar1 == 0x4a) {
      pcVar2 = "HUBCLIENT_GSPLITE2";
    }
    else if (uVar1 < 0x4b) {
      pcVar2 = "HUBCLIENT_RASTERTWOD3";
      if (((uVar1 != 0x48) && (pcVar2 = "HUBCLIENT_GSPLITE1", uVar1 != 0x49)) &&
         (pcVar2 = "HUBCLIENT_RASTERTWOD1", uVar1 != 0x46)) {
        pcVar2 = "HUBCLIENT_RASTERTWOD2";
      }
    }
    else if (uVar1 == 0x4c) {
      pcVar2 = "HUBCLIENT_PD2";
    }
    else if (uVar1 == 0x4d) {
      pcVar2 = "HUBCLIENT_PD3";
    }
    else {
      pcVar2 = "HUBCLIENT_GSPLITE3";
      if (uVar1 != 0x4b) goto LAB_0032267e;
    }
  }
  else if (uVar1 == 0x6c) {
    pcVar2 = "HUBCLIENT_ESC9";
  }
  else if (uVar1 < 0x6d) {
    if (uVar1 == 0x68) {
      pcVar2 = "HUBCLIENT_ESC5";
    }
    else if (uVar1 < 0x69) {
      pcVar2 = "HUBCLIENT_ESC3";
      if (((uVar1 != 0x66) && (pcVar2 = "HUBCLIENT_ESC4", uVar1 != 0x67)) &&
         (pcVar2 = "HUBCLIENT_ESC1", uVar1 != 100)) {
        pcVar2 = "HUBCLIENT_ESC2";
      }
    }
    else {
      pcVar2 = "HUBCLIENT_ESC7";
      if ((uVar1 != 0x6a) && (pcVar2 = "HUBCLIENT_ESC8", uVar1 != 0x6b)) {
        pcVar2 = "HUBCLIENT_ESC6";
      }
    }
  }
  else if (uVar1 == 0x7c) {
    pcVar2 = "HUBCLIENT_VPR_SCRUBBER2";
  }
  else if (uVar1 < 0x7d) {
    if (uVar1 == 0x79) {
      pcVar2 = "HUBCLIENT_FSP";
    }
    else if (uVar1 < 0x7a) {
      if (uVar1 == 0x6d) {
        pcVar2 = "HUBCLIENT_ESC10";
      }
      else {
        pcVar2 = "HUBCLIENT_ESC11";
        if (uVar1 != 0x6e) goto LAB_0032267e;
      }
    }
    else {
      pcVar2 = "HUBCLIENT_GSPLITE";
      if (uVar1 != 0x7b) goto LAB_0032267e;
    }
  }
  else if (uVar1 == 0x7e) {
    pcVar2 = "HUBCLIENT_VPR_SCRUBBER4";
  }
  else if (uVar1 == 0x7f) {
    pcVar2 = "HUBCLIENT_NVENC3";
  }
  else {
    pcVar2 = "HUBCLIENT_VPR_SCRUBBER3";
    if (uVar1 != 0x7d) goto LAB_0032267e;
  }
  return pcVar2;
}


// ===== 00322930 kfifoValidateSCGTypeAndRunqueue_GB202 =====

undefined1  [16]
kfifoValidateSCGTypeAndRunqueue_GB202(undefined8 param_1,int param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  ulong uStack_10;
  
  if ((param_2 == 1) && ((int)param_3 == 0)) {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/blackwell/kernel_fifo_gb202.c",0xf7,
                 "kfifoValidateSCGTypeAndRunqueue_GB202",1,
                 "NVRM: Invalid (SCG,runqueue) combination: (0x%x,0x%x)\n",1,0);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uStack_10;
    return auVar1 << 0x40;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = 1;
  return auVar2;
}


// ===== 00322990 kfifoRunlistGetBaseShift_GB202 =====

undefined8 kfifoRunlistGetBaseShift_GB202(void)

{
  return 8;
}


// ===== 003229a0 kfifoStartChannelHalt_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoStartChannelHalt_GB202(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  int iVar2;
  int local_30;
  int local_2c;
  
  uVar1 = *(undefined4 *)(param_3 + 0x2b0);
  iVar2 = (**(code **)(param_2 + 0x218))(param_1,param_2,3,uVar1,0xe,&local_30);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(param_2 + 0x218))(param_1,param_2,3,uVar1,0xb,&local_2c);
    if (iVar2 == 0) {
      regWrite032(param_1 + 0x3a18,0,0,local_30 + *(int *)(param_3 + 0x2b4) * 4,3,0);
      regWrite032(param_1 + 0x3a18,0,0,local_2c + 0x14,0,0);
      return;
    }
  }
  return;
}


// ===== 00322a80 kfifoCompleteChannelHalt_GB202 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoCompleteChannelHalt_GB202(long param_1,long param_2,long param_3,undefined8 param_4)

{
  int iVar1;
  ulong uVar2;
  int local_2c [3];
  
  iVar1 = (**(code **)(param_2 + 0x218))
                    (param_1,param_2,3,*(undefined4 *)(param_3 + 0x2b0),0xb,local_2c);
  if (iVar1 == 0) {
    do {
      iVar1 = timeoutCheck(param_1 + 0x1af0,param_4,0x160);
      if (iVar1 == 0x65) {
        return;
      }
      uVar2 = regRead032(param_1 + 0x3a18,0,0,local_2c[0] + 0x14,0);
    } while ((uVar2 & 0x200000) != 0);
  }
  return;
}


// ===== 00322b10 kchannelIsUserdAddrSizeValid_GH100 =====

uint kchannelIsUserdAddrSizeValid_GH100(undefined8 param_1,uint param_2,uint param_3)

{
  undefined8 in_RAX;
  
  return (uint)CONCAT71((int7)((ulong)in_RAX >> 8),param_2 < 0x1000000) &
         CONCAT31((int3)(param_3 >> 8),param_3 < 0x100000);
}


// ===== 00322b30 kfifoCheckChannelAllocAddrSpaces_GH100 =====

undefined8
kfifoCheckChannelAllocAddrSpaces_GH100(undefined8 param_1,int param_2,int param_3,int param_4)

{
  if ((param_2 == 1) && ((param_3 == 2 || (param_4 == 2)))) {
    return 0x56;
  }
  return 0;
}


// ===== 00322b50 kfifoGetCtxBufferMapFlags_GH100 =====

void kfifoGetCtxBufferMapFlags_GH100
               (undefined8 param_1,undefined8 param_2,uint param_3,uint *param_4)

{
  if (param_3 >> 8 != 0xd334df) {
    return;
  }
  *param_4 = *param_4 | 2;
  return;
}


// ===== 00322b70 kfifoConstructUsermodeMemdescs_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoConstructUsermodeMemdescs_GH100(long param_1,long param_2)

{
  long lVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long *plVar8;
  undefined8 uStack_50;
  
  uVar7 = 0x30000;
  uVar6 = 0;
  plVar8 = (long *)(param_2 + 0x4e8);
  bVar2 = false;
  lVar1 = *(long *)(param_1 + 0x1b78);
  do {
    uVar3 = memCreateMemDesc_IMPL(param_1,plVar8,1,uVar6,uVar7,0x30000000);
    if (uVar3 != 0) {
      nvAssertOkFailedNoLog
                (uVar3,"memCreateMemDesc(pGpu, ppMemDesc, ADDR_SYSMEM, offset, size, attr, attr2)",
                 "src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x77);
LAB_00322c90:
      memdescDestroy(*(undefined8 *)(param_2 + 0x4e0));
      memdescDestroy(*(undefined8 *)(param_2 + 0x4e8));
      return (ulong)uVar3;
    }
    uVar4 = (**(code **)(lVar1 + 0x2b0))(param_1,lVar1,8,uStack_50);
    memdescSetPteKindForGpu((undefined8 *)*plVar8,*(undefined8 *)*plVar8,uVar4);
    memdescSetFlag(*plVar8,0x8000000000,1);
    uStack_50 = 0x322c12;
    memdescSetPageSize(*plVar8,1,0x1000);
    *(undefined4 *)(*plVar8 + 0x78) = 2;
    *(undefined4 *)(*plVar8 + 0x7c) = 2;
    if (bVar2) {
      uVar5 = kfifoConstructUsermodeMemdescs_GV100(param_1,param_2);
      uVar3 = (uint)uVar5;
      if (uVar3 == 0) {
        return uVar5;
      }
      nvAssertOkFailedNoLog
                (uVar5 & 0xffffffff,"kfifoConstructUsermodeMemdescs_GV100(pGpu, pKernelFifo)",
                 "src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x86);
      goto LAB_00322c90;
    }
    plVar8 = (long *)(param_2 + 0x4e0);
    bVar2 = true;
    uVar7 = 0x10000;
    uVar6 = 0x30000;
  } while( true );
}


// ===== 00322cf0 kfifoPrintInternalEngine_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoPrintInternalEngine_GH100(long param_1,long param_2,uint param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int local_2c;
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  cVar2 = kfifoIsMmuFaultEngineIdPbdma_IMPL();
  if (cVar2 != '\0') {
    pcVar4 = (char *)kfifoPrintFaultingPbdmaEngineName_IMPL(param_1,param_2,param_3);
    return pcVar4;
  }
  cVar2 = (**(code **)(lVar1 + 0x378))(lVar1,param_3);
  pcVar4 = "BAR1";
  if (cVar2 == '\0') {
    cVar2 = (**(code **)(lVar1 + 0x380))(lVar1,param_3);
    pcVar4 = "BAR2";
    if (cVar2 == '\0') {
      if (param_3 == 4) {
        pcVar4 = "FLA";
      }
      else {
        if (param_3 < 5) {
          if (param_3 == 2) {
            return "GSP";
          }
          if (param_3 == 3) {
            return "PTP";
          }
          if (param_3 == 1) {
            return "DISPLAY";
          }
        }
        else {
          if (param_3 == 7) {
            return "FSP";
          }
          if (param_3 == 10) {
            return "PERF";
          }
          if (param_3 == 5) {
            return "PMU";
          }
        }
        iVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,4,param_3,0,&local_2c);
        pcVar4 = "UNKNOWN";
        if ((iVar3 == 0) && (pcVar4 = "GRAPHICS", local_2c != -0x2ccb2100)) {
          pcVar4 = (char *)(**(code **)(param_2 + 0x248))(param_2,0);
        }
      }
    }
  }
  return pcVar4;
}


// ===== 00322e50 kfifoGetClientIdStringCommon_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoGetClientIdStringCommon_GH100(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  char *pcVar2;
  
  uVar1 = *(uint *)(param_3 + 0xc);
  if (*(char *)(param_3 + 0x10) != '\0') {
    if (0x71 < uVar1) {
      return "UNRECOGNIZED_CLIENT";
    }
    return *(char **)(CSWTCH_36 + (ulong)uVar1 * 8);
  }
  if (uVar1 == 0x32) {
    return "HUBCLIENT_PTP_X7";
  }
  if (uVar1 < 0x33) {
    if (uVar1 == 0x17) {
      return "HUBCLIENT_SSYNC";
    }
    if (uVar1 < 0x18) {
      if (uVar1 == 0xb) {
        return "HUBCLIENT_NVDEC0";
      }
      if (0xb < uVar1) {
        if (uVar1 == 0x11) {
          return "HUBCLIENT_PERF";
        }
        if (uVar1 < 0x12) {
          if (uVar1 == 0xe) {
            return "HUBCLIENT_NISO";
          }
          if (0xe < uVar1) {
            pcVar2 = "HUBCLIENT_P2P";
            if (uVar1 != 0xf) {
              pcVar2 = "HUBCLIENT_PD";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_CE3";
          if (uVar1 != 0xc) {
            pcVar2 = "HUBCLIENT_NVENC1";
          }
          return pcVar2;
        }
        if (uVar1 == 0x14) {
          return "HUBCLIENT_SCC";
        }
        if (0x14 < uVar1) {
          pcVar2 = "HUBCLIENT_SCC_NB";
          if (uVar1 != 0x15) {
            pcVar2 = "HUBCLIENT_SEC";
          }
          return pcVar2;
        }
        pcVar2 = "HUBCLIENT_PMU";
        if (uVar1 != 0x12) {
          pcVar2 = "HUBCLIENT_RASTERTWOD";
        }
        return pcVar2;
      }
      if (uVar1 == 5) {
        return "HUBCLIENT_FECS";
      }
      if (uVar1 < 6) {
        if (uVar1 == 2) {
          return "HUBCLIENT_CE1";
        }
        if (2 < uVar1) {
          pcVar2 = "HUBCLIENT_DNISO";
          if (uVar1 != 3) {
            pcVar2 = "HUBCLIENT_FE";
          }
          return pcVar2;
        }
        pcVar2 = "HUBCLIENT_VIP";
        if (uVar1 != 0) {
          pcVar2 = "HUBCLIENT_CE0";
        }
        return pcVar2;
      }
      if (uVar1 == 8) {
        return "HUBCLIENT_HOST_CPU_NB";
      }
      if (8 < uVar1) {
        pcVar2 = "HUBCLIENT_ISO";
        if (uVar1 != 9) {
          pcVar2 = "HUBCLIENT_MMU";
        }
        return pcVar2;
      }
      pcVar2 = "HUBCLIENT_HOST";
      if (uVar1 != 6) {
        pcVar2 = "HUBCLIENT_HOST_CPU";
      }
      return pcVar2;
    }
    if (uVar1 == 0x25) {
      return "HUBCLIENT_HSCE5";
    }
    if (0x25 < uVar1) {
      if (uVar1 == 0x2d) {
        return "HUBCLIENT_PTP_X2";
      }
      if (uVar1 < 0x2e) {
        if (uVar1 == 0x2a) {
          return "HUBCLIENT_HSHUB";
        }
        if (0x2a < uVar1) {
          pcVar2 = "HUBCLIENT_PTP_X0";
          if (uVar1 != 0x2b) {
            pcVar2 = "HUBCLIENT_PTP_X1";
          }
          return pcVar2;
        }
        if (uVar1 == 0x26) {
          return "HUBCLIENT_HSCE6";
        }
        pcVar2 = "HUBCLIENT_HSCE7";
        if (uVar1 != 0x27) goto LAB_0032309f;
      }
      else {
        pcVar2 = "HUBCLIENT_PTP_X5";
        if ((uVar1 != 0x30) && (pcVar2 = "HUBCLIENT_PTP_X6", uVar1 != 0x31)) {
          pcVar2 = "HUBCLIENT_PTP_X3";
          if (uVar1 != 0x2e) {
            pcVar2 = "HUBCLIENT_PTP_X4";
          }
          return pcVar2;
        }
      }
      return pcVar2;
    }
    if (uVar1 == 0x1f) {
      return "HUBCLIENT_DONT_CARE";
    }
    if (0x1f < uVar1) {
      if (uVar1 == 0x22) {
        return "HUBCLIENT_HSCE2";
      }
      if (0x22 < uVar1) {
        pcVar2 = "HUBCLIENT_HSCE3";
        if (uVar1 != 0x23) {
          pcVar2 = "HUBCLIENT_HSCE4";
        }
        return pcVar2;
      }
      pcVar2 = "HUBCLIENT_HSCE0";
      if (uVar1 != 0x20) {
        pcVar2 = "HUBCLIENT_HSCE1";
      }
      return pcVar2;
    }
    if (uVar1 == 0x1a) {
      return "HUBCLIENT_MMU_NB";
    }
    if (uVar1 < 0x1b) {
      pcVar2 = "HUBCLIENT_CE2";
      if (uVar1 != 0x18) {
        pcVar2 = "HUBCLIENT_XV";
      }
      return pcVar2;
    }
    if (uVar1 == 0x1c) {
      return "HUBCLIENT_DFALCON";
    }
    if (uVar1 == 0x1d) {
      return "HUBCLIENT_SKED";
    }
  }
  else {
    if (uVar1 == 0x58) {
      return "HUBCLIENT_FECS4";
    }
    if (uVar1 < 0x59) {
      if (uVar1 == 0x3f) {
        return "HUBCLIENT_OFA0";
      }
      if (uVar1 < 0x40) {
        if (uVar1 == 0x39) {
          return "HUBCLIENT_GSP";
        }
        if (0x39 < uVar1) {
          if (uVar1 == 0x3c) {
            return "HUBCLIENT_NVJPG0";
          }
          if (0x3c < uVar1) {
            pcVar2 = "HUBCLIENT_NVDEC3";
            if (uVar1 != 0x3d) {
              pcVar2 = "HUBCLIENT_NVDEC4";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_NVDEC1";
          if (uVar1 != 0x3a) {
            pcVar2 = "HUBCLIENT_NVDEC2";
          }
          return pcVar2;
        }
        if (uVar1 == 0x35) {
          return "HUBCLIENT_VPR_SCRUBBER1";
        }
        if (uVar1 < 0x36) {
          pcVar2 = "HUBCLIENT_NVENC2";
          if (uVar1 != 0x33) {
            pcVar2 = "HUBCLIENT_VPR_SCRUBBER0";
          }
          return pcVar2;
        }
        if (uVar1 == 0x37) {
          return "HUBCLIENT_FBFALCON";
        }
        if (uVar1 == 0x38) {
          return "HUBCLIENT_CE_SHIM";
        }
      }
      else {
        if (uVar1 == 0x53) {
          return "HUBCLIENT_FE6";
        }
        if (0x53 < uVar1) {
          if (uVar1 == 0x56) {
            return "HUBCLIENT_FECS2";
          }
          if (uVar1 == 0x57) {
            return "HUBCLIENT_FECS3";
          }
          pcVar2 = "HUBCLIENT_FE7";
          if (uVar1 != 0x54) {
            pcVar2 = "HUBCLIENT_FECS1";
          }
          return pcVar2;
        }
        if (uVar1 == 0x50) {
          return "HUBCLIENT_FE3";
        }
        if (0x50 < uVar1) {
          pcVar2 = "HUBCLIENT_FE4";
          if (uVar1 != 0x51) {
            pcVar2 = "HUBCLIENT_FE5";
          }
          return pcVar2;
        }
        if (uVar1 == 0x4e) {
          return "HUBCLIENT_FE1";
        }
        if (uVar1 == 0x4f) {
          return "HUBCLIENT_FE2";
        }
      }
    }
    else {
      if (uVar1 == 0x6f) {
        return "HUBCLIENT_NVDEC5";
      }
      if (uVar1 < 0x70) {
        if (uVar1 == 0x5e) {
          return "HUBCLIENT_SKED3";
        }
        if (uVar1 < 0x5f) {
          if (uVar1 == 0x5b) {
            return "HUBCLIENT_FECS7";
          }
          if (0x5b < uVar1) {
            pcVar2 = "HUBCLIENT_SKED1";
            if (uVar1 != 0x5c) {
              pcVar2 = "HUBCLIENT_SKED2";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_FECS5";
          if (uVar1 != 0x59) {
            pcVar2 = "HUBCLIENT_FECS6";
          }
          return pcVar2;
        }
        if (uVar1 == 0x61) {
          return "HUBCLIENT_SKED6";
        }
        if (uVar1 < 0x62) {
          pcVar2 = "HUBCLIENT_SKED4";
          if (uVar1 != 0x5f) {
            pcVar2 = "HUBCLIENT_SKED5";
          }
          return pcVar2;
        }
        if (uVar1 == 0x62) {
          return "HUBCLIENT_SKED7";
        }
        if (uVar1 == 99) {
          return "HUBCLIENT_ESC";
        }
      }
      else {
        if (uVar1 == 0x75) {
          return "HUBCLIENT_NVJPG4";
        }
        if (uVar1 < 0x76) {
          if (uVar1 == 0x72) {
            return "HUBCLIENT_NVJPG1";
          }
          if (0x72 < uVar1) {
            pcVar2 = "HUBCLIENT_NVJPG2";
            if (uVar1 != 0x73) {
              pcVar2 = "HUBCLIENT_NVJPG3";
            }
            return pcVar2;
          }
          pcVar2 = "HUBCLIENT_NVDEC6";
          if (uVar1 != 0x70) {
            pcVar2 = "HUBCLIENT_NVDEC7";
          }
          return pcVar2;
        }
        if (uVar1 == 0x78) {
          return "HUBCLIENT_NVJPG7";
        }
        if (uVar1 < 0x79) {
          pcVar2 = "HUBCLIENT_NVJPG5";
          if (uVar1 != 0x76) {
            pcVar2 = "HUBCLIENT_NVJPG6";
          }
          return pcVar2;
        }
        if (uVar1 == 0x79) {
          return "HUBCLIENT_FSP";
        }
      }
    }
  }
LAB_0032309f:
  pcVar2 = (char *)(**(code **)(param_2 + 0x350))();
  return pcVar2;
}


// ===== 003234e0 kfifoGetClientIdString_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoGetClientIdString_GH100(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  char *pcVar2;
  
  if (*(char *)(param_3 + 0x10) != '\0') goto LAB_00323518;
  uVar1 = *(uint *)(param_3 + 0xc);
  if (uVar1 == 0x41) {
    pcVar2 = "HUBCLIENT_HSCE11";
  }
  else if (uVar1 < 0x42) {
    if (uVar1 == 0x29) {
      pcVar2 = "HUBCLIENT_HSCE9";
    }
    else if (uVar1 < 0x2a) {
      if (uVar1 == 0x1e) {
        pcVar2 = "HUBCLIENT_AFALCON";
      }
      else {
        pcVar2 = "HUBCLIENT_HSCE8";
        if (uVar1 != 0x28) {
LAB_00323518:
          pcVar2 = (char *)(**(code **)(param_2 + 0x340))();
          return pcVar2;
        }
      }
    }
    else if (uVar1 == 0x36) {
      pcVar2 = "HUBCLIENT_DWBIF";
    }
    else {
      pcVar2 = "HUBCLIENT_HSCE10";
      if (uVar1 != 0x40) goto LAB_00323518;
    }
  }
  else if (uVar1 == 0x44) {
    pcVar2 = "HUBCLIENT_HSCE14";
  }
  else if (uVar1 < 0x45) {
    pcVar2 = "HUBCLIENT_HSCE12";
    if (uVar1 != 0x42) {
      pcVar2 = "HUBCLIENT_HSCE13";
    }
  }
  else {
    pcVar2 = "HUBCLIENT_HSCE15";
    if (uVar1 != 0x45) goto LAB_00323518;
  }
  return pcVar2;
}


// ===== 003235d0 kfifoRingChannelDoorBell_GH100 =====

void kfifoRingChannelDoorBell_GH100(void)

{
  kfifoRingChannelDoorBell_GV100();
  return;
}


// ===== 003235e0 kfifoWriteRamfcGpfifo_GH100 =====

void kfifoWriteRamfcGpfifo_GH100
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,ulong param_4,
               undefined4 param_5)

{
  uint uVar1;
  
  if ((param_4 & 7) != 0) {
    nvAssertFailedNoLog("FLD_TEST_DRF(_PBDMA, _GP_BASE, _RSVD, _ZERO, NvU64_LO32(gpFifoOffset))",
                        "src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x264);
  }
  param_3[0x12] = (int)param_4;
  param_3[0x13] = (uint)(param_4 >> 0x20) & 0x1ffffff;
  uVar1 = nvLogBase2(param_5);
  param_3[0x29] = uVar1 & 0x1f;
  *param_3 = 0;
  param_3[5] = 0;
  return;
}


// ===== 00323660 kfifoDisableChannelsForKeyRotation_GH100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoDisableChannelsForKeyRotation_GH100
              (long param_1,undefined8 param_2,undefined4 *param_3,undefined1 param_4,char param_5,
              long param_6)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  int *piVar6;
  ulong uVar7;
  long lVar8;
  uint local_234;
  int local_22c;
  int local_21c;
  undefined4 local_218;
  int local_214;
  undefined8 local_210;
  ulong local_208;
  int local_200 [116];
  
  local_210 = 0;
  if (*(char *)(param_1 + 0x909) == '\0') {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",
                        0x291);
    return 0x56;
  }
  local_22c = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,*param_3,param_3[1],param_3[2],
                         *(undefined8 *)(param_3 + 4),param_3[6]);
  if (*(int *)(param_6 + 4) != 0) {
    lVar8 = 0;
    lVar3 = *(long *)(param_1 + 0x1d18);
    local_234 = 0;
    do {
      while( true ) {
        local_208 = 0;
        uVar5 = serverGetClientUnderLock
                          (g_resServ,*(undefined4 *)(param_6 + 0x18 + lVar8 * 4),&local_208);
        iVar4 = (int)uVar5;
        if (iVar4 == 0) break;
        lVar2 = lVar8 * 4;
        lVar8 = lVar8 + 1;
        nvDbg_Printf("src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2a2,
                     "kfifoDisableChannelsForKeyRotation_GH100",4,
                     "NVRM: Failed to get client with hClient = 0x%x status = 0x%x\n",
                     *(undefined4 *)(param_6 + 0x18 + lVar2),uVar5);
        local_22c = iVar4;
        if (*(uint *)(param_6 + 4) <= (uint)lVar8) goto LAB_0032384d;
      }
      uVar5 = CliGetKernelChannel(local_208,*(undefined4 *)(param_6 + 0x118 + lVar8 * 4),&local_210)
      ;
      if ((int)uVar5 == 0) {
        kchannelDisableForKeyRotation(param_1,local_210,1);
        kchannelEnableAfterKeyRotation(param_1,local_210,param_4);
        if (*(char *)(param_1 + 0x909) != '\0') {
          iVar4 = (**(code **)(lVar3 + 0x210))(param_1,lVar3,local_210,&local_21c,&local_218);
          if (iVar4 != 0) {
            nvAssertOkFailedNoLog
                      (iVar4,
                       "confComputeGetKeyPairByChannel_HAL(pGpu, pConfCompute, pKernelChannel, &h2dKey, &d2hKey)"
                       ,"src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2b3);
            return iVar4;
          }
          if (param_5 == '\0') {
            iVar4 = confComputeGetKeyRotationStatus_IMPL(lVar3,local_21c,&local_214);
            if (iVar4 != 0) {
              nvAssertOkFailedNoLog
                        (iVar4,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &state)",
                         "src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2cd);
              return iVar4;
            }
            if (((local_214 == 1) || (local_214 == 6)) &&
               (iVar4 = confComputeCheckAndPerformKeyRotation_IMPL
                                  (param_1,lVar3,local_21c,local_218), iVar4 != 0)) {
              nvAssertOkFailedNoLog
                        (iVar4,
                         "confComputeCheckAndPerformKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey)"
                         ,"src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2d1);
              return iVar4;
            }
          }
          else {
            uVar7 = 0;
            if (local_234 != 0) {
              uVar7 = (ulong)local_234;
              piVar6 = local_200;
              piVar1 = piVar6 + uVar7;
              do {
                if (*piVar6 == local_21c) goto LAB_003237d0;
                piVar6 = piVar6 + 1;
              } while (piVar6 != piVar1);
              if (0x71 < local_234) {
                nvAssertFailedNoLog("keyIndex < CC_KEYSPACE_TOTAL_SIZE",
                                    "src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2c5);
                return 0x40;
              }
            }
            local_200[uVar7] = local_21c;
            local_234 = local_234 + 1;
          }
        }
      }
      else {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2aa,
                     "kfifoDisableChannelsForKeyRotation_GH100",4,
                     "NVRM: Failed to get channel with hclient = 0x%x hChannel = 0x%x status = 0x%x\n"
                     ,*(undefined4 *)(param_6 + 0x18 + lVar8 * 4),
                     *(undefined4 *)(param_6 + 0x118 + lVar8 * 4),uVar5);
        local_22c = (int)uVar5;
      }
LAB_003237d0:
      lVar8 = lVar8 + 1;
    } while ((uint)lVar8 < *(uint *)(param_6 + 4));
LAB_0032384d:
    if (((*(char *)(param_1 + 0x909) != '\0') && (param_5 != '\0')) && (local_234 != 0)) {
      piVar6 = local_200;
      piVar1 = piVar6 + local_234;
      do {
        confComputeGetKeyPairByKey_IMPL(lVar3,*piVar6,&local_214,&local_208);
        nvDbg_Printf("src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2dd,
                     "kfifoDisableChannelsForKeyRotation_GH100",1,
                     "NVRM: Forcing key rotation on h2dKey 0x%x\n",local_214);
        iVar4 = confComputeForceKeyRotation_IMPL(param_1,lVar3,local_214,local_208 & 0xffffffff);
        if (iVar4 != 0) {
          nvDbg_Printf("src/kernel/gpu/fifo/arch/hopper/kernel_fifo_gh100.c",0x2e1,
                       "kfifoDisableChannelsForKeyRotation_GH100",4,
                       "NVRM: Forced key rotation for key 0x%x failed\n",local_214);
          return iVar4;
        }
        piVar6 = piVar6 + 1;
        local_22c = 0;
      } while (piVar1 != piVar6);
    }
  }
  return local_22c;
}


// ===== 00323b10 kchannelGetClassEngineID_GM107 =====

int kchannelGetClassEngineID_GM107
              (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4,uint *param_5,
              undefined8 param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long local_40 [2];
  
  local_40[0] = 0;
  iVar1 = kchannelFindChildByHandle(param_2,param_3,local_40);
  if (iVar1 == 0) {
    if (local_40[0] == 0) {
      iVar1 = 0x57;
      nvAssertFailedNoLog("pObject != NULL",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x43);
    }
    else {
      uVar3 = *(uint *)(*(long *)(*(long *)(local_40[0] + 0x140) + 0x48) + 0x11c);
      *param_5 = uVar3;
      if (*(int *)(local_40[0] + 0x184) == -0x6a590b00) {
        uVar3 = (uint)*(ushort *)(local_40[0] + 0x188);
      }
      iVar1 = gpuXlateEngDescToClientEngineId_IMPL(param_1,*(int *)(local_40[0] + 0x184),param_6);
      if (iVar1 == 0) {
        uVar2 = uVar3 & 0xffff;
        *param_4 = uVar2;
      }
      else {
        uVar2 = *param_4;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x54,
                   "kchannelGetClassEngineID_GM107",1,
                   "NVRM: class ID: 0x%08x classEngine ID: 0x%08x\n",uVar3,uVar2);
    }
  }
  else {
    nvCheckOkFailedNoLog
              (1,iVar1,"kchannelFindChildByHandle(pKernelChannel, handle, &pObject)",
               "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x41);
  }
  return iVar1;
}


// ===== 00323c40 kchannelEnableVirtualContext_GM107 =====

undefined8 kchannelEnableVirtualContext_GM107(long param_1)

{
  *(undefined1 *)(param_1 + 0x408) = 1;
  return 0;
}


// ===== 00323c50 kchannelAllocMem_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelAllocMem_GM107(long param_1,long param_2,ulong param_3)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  ulong uVar14;
  char local_5d;
  undefined4 local_5c;
  undefined1 local_58 [4];
  int local_54;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 *local_40 [2];
  
  lVar9 = gpuGetKernelFifoShared_IMPL();
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0xbd);
    return 0x1f;
  }
  lVar1 = *(long *)(*(long *)(param_2 + 0x2b8) + 0x138);
  cVar3 = (**(code **)(lVar9 + 0x1a0))
                    (lVar9,(uint)(param_3 >> 0x1c) & 3,(uint)((param_3 & 0xffffffff) >> 4) & 1);
  if (cVar3 == '\0') {
    return 0x1f;
  }
  (**(code **)(lVar9 + 0x2a0))(lVar9,local_58,0);
  iVar5 = (**(code **)(lVar9 + 0x188))(lVar9,&local_50,&local_48,&local_5d,&local_5c,local_40);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0xcc,
                 "kchannelAllocMem_GM107",4,"NVRM: Unable to get instance memory info!\n");
    goto LAB_00323fe6;
  }
  if ((*(char *)(param_1 + 0x909) != '\0') && (*(char *)(*(long *)(param_1 + 0x4d8) + 0x80) == '\0')
     ) {
    local_40[0] = &ADDRLIST_FBMEM_ONLY;
    local_5c = 1;
  }
  lVar9 = *(long *)(lVar1 + 0x198);
  uVar14 = (-(ulong)(local_5d == '\0') & 0xffffffffffffff80) + 0x2000080;
  if (lVar9 != 0) {
    uVar14 = uVar14 | 0x1000000000;
  }
  uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  uVar10 = (ulong)uVar4;
  plVar2 = *(long **)(param_2 + 0x2d8 + uVar10 * 8);
  if (plVar2 == (long *)0x0) {
    plVar2 = *(long **)(*(long *)(param_2 + 0x140) + 0x48);
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0xe7,
                 "kchannelAllocMem_GM107",4,
                 "NVRM: Instance block is NULL for hClient 0x%x Channel 0x%x!\n",
                 *(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2]);
    return 0;
  }
  iVar5 = memdescCreate(plVar2,param_1,local_50,local_48,1,0,local_5c);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0xf3,
                 "kchannelAllocMem_GM107",4,"NVRM: Unable to allocate instance memory descriptor!\n"
                );
    goto LAB_00323fe6;
  }
  iVar5 = memdescGetAddressSpace(*plVar2,uVar14);
  if ((iVar5 == 1) && (*(char *)(param_1 + 0x4a25) != '\0')) {
    memdescSetGpuCacheAttrib(*plVar2,0);
  }
  if ((lVar9 != 0) && (iVar5 = memdescSetCtxBufPool(*plVar2,lVar9), iVar5 != 0)) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",
                        0x102);
    goto LAB_00323fe6;
  }
  *(undefined4 *)(*plVar2 + 0x9c) = 0x95;
  iVar5 = memdescAllocList(*plVar2,local_40[0]);
  if (iVar5 != 0) {
    plVar2 = *(long **)(*(long *)(param_2 + 0x140) + 0x48);
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x11c,
                 "kchannelAllocMem_GM107",4,
                 "NVRM: Instance block allocation for hClient 0x%x hChannel 0x%x failed\n",
                 *(undefined4 *)(*plVar2 + 0x48),(int)plVar2[2]);
    goto LAB_00323fe6;
  }
  iVar5 = memmgrMemDescMemSet_IMPL(*(undefined8 *)(param_1 + 0x1b78),*plVar2,0);
  if (iVar5 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",
                        0x114);
    goto LAB_00323fe6;
  }
  memdescSetName(param_1,*plVar2,"rm_instance_block_surface");
  iVar5 = memdescCreateSubMem(plVar2 + 1,*plVar2,param_1,0,0x200);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x128,
                 "kchannelAllocMem_GM107",4,"NVRM: Could not allocate memdesc for RAMFC\n");
    goto LAB_00323fe6;
  }
  if (*(char *)(param_2 + 0x398) == '\0') {
    if (*(long *)(param_2 + 0x358 + uVar10 * 8) != 0) {
      nvAssertFailedNoLog("pKernelChannel->pUserdSubDeviceMemDesc[subdevInst] == NULL",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x12f);
    }
    lVar9 = gpuGetKernelFifoShared_IMPL(param_1);
    uVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    uVar14 = (ulong)uVar6;
    if (*(long *)(lVar9 + 1000 + uVar14 * 8) == 0) {
      iVar5 = 0x40;
      nvAssertFailedNoLog("pUserdInfo != NULL && pUserdInfo->userdPhysDesc[subdevInst] != NULL",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x79);
    }
    else {
      (**(code **)(lVar9 + 0x2a0))(lVar9,&local_54,0);
      iVar5 = memdescCreateSubMem(param_2 + 0x358 + uVar14 * 8,
                                  *(undefined8 *)(lVar9 + 1000 + uVar14 * 8),param_1,
                                  local_54 * *(int *)(param_2 + 0x2b4),local_54);
      if (iVar5 == 0) goto LAB_00323eeb;
    }
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x134,
                 "kchannelAllocMem_GM107",4,"NVRM: Could not allocate sub memdesc for USERD\n");
  }
  else {
LAB_00323eeb:
    iVar5 = (**(code **)(param_2 + 0x1d8))(param_1,param_2);
    if (iVar5 == 0) {
      uVar11 = 0;
      lVar9 = *(long *)(param_2 + 0x358 + uVar10 * 8);
      if (lVar9 != 0) {
        uVar11 = memdescGetPhysAddr(lVar9,1,0);
      }
      uVar7 = memdescGetAddressSpace(*plVar2);
      uVar8 = memdescGetAddressSpace(*plVar2);
      uVar12 = memdescGetApertureString(uVar8);
      uVar13 = memdescGetPhysAddr(*plVar2,1,0);
      plVar2 = *(long **)(*(long *)(param_2 + 0x140) + 0x48);
      nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x140,
                   "kchannelAllocMem_GM107",1,
                   "NVRM: hChannel 0x%x hClient 0x%x, Class ID 0x%x Instance Block @ 0x%llx (%s %x) USERD @ 0x%llx for subdevice %d\n"
                   ,(int)plVar2[2],*(undefined4 *)(*plVar2 + 0x48),
                   *(undefined4 *)((long)plVar2 + 0x11c),uVar13,uVar12,uVar7,uVar11,uVar4);
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x13c,
                 "kchannelAllocMem_GM107",4,"NVRM: kchannelCreateUserMemDesc failed \n");
  }
LAB_00323fe6:
  nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x154,
               "kchannelAllocMem_GM107",4,"NVRM: Could not create Channel\n");
  return iVar5;
}


// ===== 00324240 kchannelDestroyMem_GM107 =====

void kchannelDestroyMem_GM107(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 != 0) {
    uVar3 = gpumgrGetSubDeviceInstanceFromGpu();
    if (*(char *)(param_2 + 0x398) == '\0') {
      uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
      lVar1 = param_2 + (ulong)uVar4 * 8;
      if (*(long *)(lVar1 + 0x358) != 0) {
        memdescFree();
        memdescDestroy(*(undefined8 *)(lVar1 + 0x358));
        *(undefined8 *)(lVar1 + 0x358) = 0;
      }
    }
    param_2 = param_2 + (ulong)uVar3 * 8;
    plVar2 = *(long **)(param_2 + 0x2d8);
    if (plVar2 != (long *)0x0) {
      if (plVar2[1] != 0) {
        memdescFree();
        memdescDestroy(plVar2[1]);
        plVar2[1] = 0;
      }
      if (*plVar2 != 0) {
        memdescFree();
        memdescDestroy(*plVar2);
        *plVar2 = 0;
      }
    }
    memdescDestroy(*(undefined8 *)(param_2 + 0x318));
    *(undefined8 *)(param_2 + 0x318) = 0;
    return;
  }
  nvAssertFailedNoLog("pKernelChannel != NULL",
                      "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x16e);
  return;
}


// ===== 00324350 kchannelAllocHwID_GM107 =====

undefined8
kchannelAllocHwID_GM107
          (long param_1,long param_2,undefined4 param_3,ulong param_4,undefined8 param_5,
          undefined4 param_6)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 local_3d;
  
  lVar1 = gpuGetKernelFifoShared_IMPL();
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
    uVar8 = (uint)param_4;
    uVar5 = uVar8 & 0x800;
    uVar7 = uVar8 & 0x200000;
    if ((param_4 & 0x200000) == 0) {
      if ((param_4 & 0x800) == 0) {
        local_3d = 0;
        uVar6 = 1;
        uVar2 = 0;
      }
      else {
        local_3d = 1;
        uVar6 = 1;
        uVar2 = 0;
        uVar5 = uVar8 >> 8 & 7;
      }
    }
    else {
      if ((param_4 & 0x800) != 0) {
        nvAssertFailedNoLog("FLD_TEST_DRF(OS04, _FLAGS, _CHANNEL_USERD_INDEX_FIXED, _FALSE, Flags)",
                            "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x1d1);
        return 0x40;
      }
      local_3d = 0;
      uVar6 = 1;
      uVar2 = 1;
      uVar7 = (uint)(param_4 >> 0xc) & 0x1ff;
      uVar5 = uVar8 >> 8 & 7;
    }
  }
  else {
    if (*(char *)(lVar1 + 0x4b0) != '\0') {
      nvCheckFailedNoLog(4,"!kfifoIsPerRunlistChramEnabled(pKernelFifo)",
                         "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x1bc);
      return 0x40;
    }
    uVar2 = kfifoGetChidMgr_IMPL(param_1,lVar1,0);
    lVar3 = kfifoChidMgrGetKernelChannel_IMPL(param_1,lVar1,uVar2);
    if (lVar3 != 0) {
      nvCheckFailedNoLog(1,"kfifoChidMgrGetKernelChannel(pGpu, pKernelFifo, pChidMgr, ChID) == NULL"
                         ,"src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x1c3);
      return 0;
    }
    uVar2 = 0;
    uVar6 = 2;
    uVar7 = 0;
    uVar5 = 0;
    local_3d = 0;
  }
  uVar4 = kfifoGetChidMgr_IMPL(param_1,lVar1,*(undefined4 *)(param_2 + 0x2b0));
  uVar2 = kfifoChidMgrAllocChid_IMPL
                    (param_1,lVar1,uVar4,param_3,uVar6,local_3d,uVar5,uVar2,uVar7,param_6,param_2);
  return uVar2;
}


// ===== 00324540 kchannelFreeHwID_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelFreeHwID_GM107(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  uVar2 = gpuGetKernelFifoShared_IMPL();
  lVar3 = kfifoGetChidMgr_IMPL(param_1,uVar2,*(undefined4 *)(param_2 + 0x2b0));
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pChidMgr != NULL","src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c"
                        ,0x207);
  }
  else {
    lVar4 = (**(code **)(*(long *)(lVar3 + 8) + 0x40))
                      (*(long *)(lVar3 + 8),*(undefined4 *)(param_2 + 0x2b4),0);
    if (lVar4 != 0) {
      if (*(long *)(lVar4 + 0x80) != param_2) {
        nvAssertFailedNoLog("pFifoDataBlock->pData == pKernelChannel",
                            "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x20d);
      }
      iVar1 = kfifoChidMgrFreeChid_IMPL(param_1,uVar2,lVar3,*(undefined4 *)(param_2 + 0x2b4));
      if (iVar1 == 0) {
        return 0;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x212,
                   "kchannelFreeHwID_GM107",4,"NVRM: Unable to Free Channel From Heap: %d\n",
                   *(undefined4 *)(param_2 + 0x2b4));
      return iVar1;
    }
    nvAssertFailedNoLog("pFifoDataBlock != NULL",
                        "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x20c);
  }
  return 0x57;
}


// ===== 00324680 kchannelCreateUserMemDesc_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelCreateUserMemDesc_GM107(long param_1,long param_2)

{
  long lVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 uVar8;
  long local_40 [2];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  lVar7 = gpuGetKernelFifoShared_IMPL();
  local_40[0] = 0;
  uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  iVar5 = (**(code **)(lVar7 + 0x1c0))(param_1,lVar7,param_2,1,local_40);
  if (iVar5 == 0) {
    if (local_40[0] == 0) {
      iVar5 = 0x57;
      nvAssertFailedNoLog("pSubDevInstMemDesc",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x235);
    }
    else {
      uVar6 = *(undefined4 *)(local_40[0] + 0x74);
      uVar4 = memdescGetAddressSpace();
      uVar2 = memdescGetContiguity(local_40[0],1);
      iVar5 = memdescCreate(param_2 + 0x318 + (ulong)uVar3 * 8,param_1,0x1000,0,uVar2,uVar4,uVar6,
                            0x2000000);
      if (iVar5 == 0) {
        param_2 = param_2 + (ulong)uVar3 * 8;
        if (*(long *)(param_2 + 0x318) == 0) {
          nvAssertFailedNoLog("*ppMemDesc","src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c"
                              ,0x240);
        }
        uVar8 = memdescGetPhysAddr(local_40[0],1,0);
        uVar6 = memdescGetAddressSpace(local_40[0]);
        memdescDescribe(*(undefined8 *)(param_2 + 0x318),uVar6,uVar8,0x1000);
        (**(code **)(lVar1 + 0x388))(param_1,lVar1,*(undefined8 *)(param_2 + 0x318),1,1);
        memdescSetPteKindForGpu
                  (*(undefined8 **)(param_2 + 0x318),**(undefined8 **)(param_2 + 0x318),0xcb);
      }
    }
  }
  return iVar5;
}


// ===== 00324820 kchannelGetEngine_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kchannelGetEngine_GM107(undefined8 param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  
  lVar2 = gpuGetKernelFifoShared_IMPL();
  if (param_3 == (undefined4 *)0x0) {
    return 0x1f;
  }
  if (param_2 == 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = *(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4);
  }
  nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x261,
               "kchannelGetEngine_GM107",1,"NVRM: channel 0x%08x\n",uVar4);
  uVar1 = *(undefined4 *)(param_2 + 0x2b0);
  *param_3 = uVar1;
  uVar3 = (**(code **)(lVar2 + 0x218))(param_1,lVar2,3,uVar1,0,param_3);
  if ((int)uVar3 != 0) {
    nvAssertOkFailedNoLog
              (uVar3 & 0xffffffff,
               "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RUNLIST, *pEngDesc, ENGINE_INFO_TYPE_ENG_DESC, pEngDesc)"
               ,"src/kernel/gpu/fifo/arch/maxwell/kernel_channel_gm107.c",0x268);
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}


// ===== 00324930 kfifoConstructHal_GM107 =====

undefined8 kfifoConstructHal_GM107(long param_1,long param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  
  if ((*(byte *)(param_1 + 0x4938) & 1) != 0) {
    *(undefined1 *)(param_2 + 0x4c4) = 1;
  }
  uVar1 = *(uint *)(param_1 + 0x4924) >> 4 & 3;
  if (uVar1 == 2) {
    puVar2 = (undefined1 *)&ADDRLIST_SYSMEM_ONLY;
    uVar1 = 1;
  }
  else if (uVar1 == 3) {
    puVar2 = (undefined1 *)&ADDRLIST_FBMEM_ONLY;
    uVar1 = 1;
  }
  else {
    puVar2 = (undefined1 *)&ADDRLIST_SYSMEM_ONLY;
    if (uVar1 != 1) {
      puVar2 = ADDRLIST_FBMEM_PREFERRED;
    }
    uVar1 = (uint)(uVar1 != 1);
  }
  *(undefined1 **)(param_2 + 0x4d0) = puVar2;
  *(uint *)(param_2 + 0x4c8) = uVar1;
  *(undefined8 *)(param_2 + 0x3e0) = 0x200000002;
  memdescOverrideInstLoc(*(ushort *)(param_1 + 0x4926) & 3,"USERD",param_2 + 0x3e0,param_2 + 0x3e4);
  return 0;
}


// ===== 003249e0 kfifoStatePostLoad_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoStatePostLoad_GM107(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  long lVar4;
  undefined8 extraout_RDX;
  ulong extraout_RDX_00;
  ulong extraout_RDX_01;
  undefined1 auVar5 [16];
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar3 = (ulong)(param_3 & 1);
  if ((param_3 & 1) == 0) {
    uVar1 = (**(code **)(param_2 + 0x280))();
    if (uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1,"kfifoPreAllocUserD_HAL(pGpu, pKernelFifo)",
                 "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0xae);
      return (ulong)uVar1;
    }
    auVar5 = gpumgrGetParentGPU(param_1);
    uVar3 = auVar5._8_8_;
    if ((param_1 == auVar5._0_8_) && (*(char *)(param_2 + 0x4b4) != '\0')) {
      uVar3 = (ulong)*(uint *)(param_2 + 0x4c8);
      uVar1 = memdescCreate(param_2 + 0x4d8,param_1,0x1000,0,0,0,uVar3,0);
      if (uVar1 == 0) {
        *(undefined4 *)(*(long *)(param_2 + 0x4d8) + 0x9c) = 0x71;
        uVar1 = memdescAllocList(*(undefined8 *)(param_2 + 0x4d8),*(undefined8 *)(param_2 + 0x4d0),
                                 extraout_RDX,uVar3);
        if (uVar1 == 0) {
          uVar3 = extraout_RDX_00;
          if (*(char *)(param_1 + 0x4913) != '\0') {
            lVar4 = *(long *)(param_2 + 0x4d8);
            portMemSet(&local_40,0,0x18);
            local_40 = memdescGetPhysAddr(lVar4,1,0);
            local_38 = *(undefined8 *)(lVar4 + 0x30);
            uVar2 = memdescGetAddressSpace(lVar4);
            local_30 = CONCAT44(*(undefined4 *)(lVar4 + 0x74),uVar2);
            uVar3 = 0x324b31;
            lVar4 = gpuGetRpc(param_1);
            if (lVar4 == 0) {
              nvAssertFailedNoLog("pRpc != NULL",
                                  "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0xcd);
              uVar1 = 0x1a;
            }
            else {
              if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x90a) == '\0')) {
                uVar1 = rpcDmaControl_wrapper
                                  (param_1,lVar4,*(undefined4 *)(param_1 + 0x3b18),
                                   *(undefined4 *)(param_1 + 0x3b20),0x20801118,&local_40,0x18);
              }
              else {
                uVar1 = (**(code **)(param_1 + 0x3b90))
                                  (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b18),
                                   *(undefined4 *)(param_1 + 0x3b20),0x20801118,&local_40,0x18);
                uVar3 = extraout_RDX_01;
              }
              if (uVar1 == 0) goto LAB_00324a20;
            }
            nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0xd6,
                         "kfifoStatePostLoad_GM107",4,
                         "NVRM: RM control call to setup zombie subctx failed, status 0x%x\n");
            return (ulong)uVar1;
          }
          goto LAB_00324a20;
        }
        nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x88,
                     "_kfifoAllocDummyPage",4,"NVRM: Could not allocate dummy page\n");
        memdescDestroy(*(undefined8 *)(param_2 + 0x4d8));
        *(undefined8 *)(param_2 + 0x4d8) = 0;
      }
      else {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x7f,
                     "_kfifoAllocDummyPage",4,"NVRM: Could not memdescCreate for dummy page\n");
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0xba,
                   "kfifoStatePostLoad_GM107",4,
                   "NVRM: Failed to allocate dummy page for zombie subcontexts\n");
      return (ulong)uVar1;
    }
  }
LAB_00324a20:
  if ((*(char *)(param_1 + 0x909) == '\0') && (*(char *)(param_1 + 0x908) == '\0')) {
    return 0;
  }
  uVar3 = kfifoTriggerPostSchedulingEnableCallback_IMPL(param_1,param_2,uVar3);
  return uVar3;
}


// ===== 00324cf0 kfifoStatePreUnload_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kfifoStatePreUnload_GM107(long param_1,long param_2,uint param_3)

{
  undefined4 uVar1;
  long lVar2;
  
  nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0xf7,
               "kfifoStatePreUnload_GM107",1,"NVRM: start\n");
  if ((param_3 & 1) != 0) {
    return 0;
  }
  lVar2 = gpumgrGetParentGPU(param_1);
  uVar1 = 0;
  if (param_1 == lVar2) {
    if (*(char *)(param_2 + 0x4b4) != '\0') {
      memdescFree(*(undefined8 *)(param_2 + 0x4d8));
      memdescDestroy(*(undefined8 *)(param_2 + 0x4d8));
      *(undefined8 *)(param_2 + 0x4d8) = 0;
    }
    uVar1 = kfifoTriggerPreSchedulingDisableCallback_IMPL(param_1,param_2);
  }
  (**(code **)(param_2 + 0x288))(param_1,param_2);
  return uVar1;
}


// ===== 00324dc0 kfifoGetInstMemInfo_GM107 =====

undefined8
kfifoGetInstMemInfo_GM107
          (long param_1,undefined8 *param_2,undefined8 *param_3,undefined1 *param_4,
          undefined4 *param_5,undefined8 *param_6)

{
  if (param_2 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pSize != NULL","src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x134
                       );
  }
  else {
    if (param_3 != (undefined8 *)0x0) {
      *param_2 = 0x1000;
      *param_3 = 0x1000;
      if (param_4 != (undefined1 *)0x0) {
        *param_4 = *(undefined1 *)(param_1 + 0x4c4);
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)(param_1 + 0x4c8);
      }
      if (param_6 != (undefined8 *)0x0) {
        *param_6 = *(undefined8 *)(param_1 + 0x4d0);
      }
      return 0;
    }
    nvAssertFailedNoLog("pAlignment != NULL","src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",
                        0x135);
  }
  return 0x1f;
}


// ===== 00324e50 kfifoGetInstBlkSizeAlign_GM107 =====

void kfifoGetInstBlkSizeAlign_GM107(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_2 = 0x1000;
  *param_3 = 0xc;
  return;
}


// ===== 00324e70 kfifoGetDefaultRunlist_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kfifoGetDefaultRunlist_GM107(undefined8 param_1,long param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0xffffffff;
  local_c = 0xd334df00;
  if ((param_3 - 1U < 0x53) &&
     (iVar1 = (**(code **)(param_2 + 0x218))(param_1,param_2,2,param_3,0,&local_c), iVar1 != 0)) {
    nvAssertOkFailedNoLog
              (iVar1,
               "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)rmEngineType, ENGINE_INFO_TYPE_ENG_DESC, &engDesc)"
               ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x16a);
  }
  iVar1 = (**(code **)(param_2 + 0x218))(param_1,param_2,0,local_c,3,&local_10);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = local_10;
  }
  return uVar2;
}


// ===== 00324f30 kfifoRunlistSetId_GM107 =====

undefined8 kfifoRunlistSetId_GM107(undefined8 param_1,undefined8 param_2,long param_3,int param_4)

{
  long lVar1;
  char cVar2;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x191);
    return 0x1f;
  }
  if ((param_4 != *(int *)(param_3 + 0x2b0)) && (cVar2 = kchannelIsRunlistSet(), cVar2 != '\0')) {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x196,
                 "kfifoRunlistSetId_GM107",4,
                 "NVRM: Channel has already been assigned a runlist incompatible with this engine (requested: 0x%x current: 0x%x).\n"
                 ,param_4,*(undefined4 *)(param_3 + 0x2b0));
    return 0x40;
  }
  if (*(long *)(param_3 + 0x2b8) != 0) {
    lVar1 = *(long *)(*(long *)(param_3 + 0x2b8) + 0x138);
    if ((*(int *)(lVar1 + 0xf8) == 1) || (*(char *)(lVar1 + 0x188) == '\0')) {
      *(int *)(lVar1 + 0xf4) = param_4;
      *(undefined1 *)(*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) + 0x188) = 1;
    }
    else if (*(int *)(lVar1 + 0xf4) != param_4) {
      nvAssertFailedNoLog("pKernelChannel->pKernelChannelGroupApi->pKernelChannelGroup->runlistId == runlistId"
                          ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x1a9);
      return 0x40;
    }
  }
  *(int *)(param_3 + 0x2b0) = param_4;
  kchannelSetRunlistSet(param_1,param_3,1);
  return 0;
}


// ===== 00325060 kfifoRunlistSetIdByEngine_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoRunlistSetIdByEngine_GM107(undefined8 param_1,long param_2,long param_3,int param_4)

{
  char cVar1;
  undefined8 uVar2;
  int local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_2c = 0;
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x1cc);
  }
  else {
    (**(code **)(param_2 + 0x220))();
    cVar1 = (**(code **)(param_2 + 0x1a8))(param_1,param_2,param_4,*(undefined4 *)(param_3 + 0x428))
    ;
    if ((cVar1 != '\0') &&
       (cVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,param_4,local_2c), cVar1 != '\0')) {
      if ((param_4 != -0x6a590b00) && (param_4 != -0x33b3cf00)) {
        local_3c = (**(code **)(param_2 + 0x218))(param_1,param_2,0,param_4,3,&local_30);
        if (local_3c == 0) {
          local_3c = (**(code **)(param_2 + 0x300))(param_1,param_2,param_3,local_30);
          if (local_3c == 0) {
            return 0;
          }
          uVar2 = (**(code **)(param_2 + 0x248))(param_2,0,param_4);
          nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x1e3,
                       "kfifoRunlistSetIdByEngine_GM107",4,
                       "NVRM: Unable to program runlist for %s\n",uVar2);
        }
        else {
          nvAssertOkFailedNoLog
                    (local_3c,
                     "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_ENG_DESC, engDesc, ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
                     ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x1dd);
        }
        return local_3c;
      }
      return 0;
    }
  }
  return 0x1f;
}


// ===== 00325250 kfifoChannelGetFifoContextMemDesc_GM107 =====

undefined8
kfifoChannelGetFifoContextMemDesc_GM107
          (long param_1,undefined8 param_2,long param_3,int param_4,long *param_5)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  
  if ((*(char *)(param_1 + 0x908) == '\0') || (*(char *)(param_1 + 0x4913) != '\0')) {
    if (param_3 == 0) {
      nvAssertFailedNoLog("pKernelChannel != NULL",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x1fd);
      return 0x21;
    }
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
    plVar1 = *(long **)(param_3 + 0x2d8 + (ulong)uVar2 * 8);
    if (plVar1 == (long *)0x0) {
      return 0x40;
    }
    if (param_4 == 0) {
      lVar3 = plVar1[1];
    }
    else {
      if (param_4 != 1) {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x20e,
                     "kfifoChannelGetFifoContextMemDesc_GM107",4,
                     "NVRM: bad engineState 0x%x on engine 0x%x\n",param_4,0xffffffffb0236500);
        return 0x1f;
      }
      lVar3 = *plVar1;
    }
    *param_5 = lVar3;
    if (1 < *(uint *)(lVar3 + 0x8c)) {
      nvAssertFailedNoLog("!memdescHasSubDeviceMemDescs(*ppMemDesc)",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x215);
      lVar3 = *param_5;
    }
    nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x217,
                 "kfifoChannelGetFifoContextMemDesc_GM107",1,
                 "NVRM: channel 0x%08x engine 0x%x engineState 0x%x *ppMemDesc %p\n",
                 *(int *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4),0xffffffffb0236500,
                 param_4,lVar3);
  }
  return 0;
}


// ===== 003253f0 kfifoConvertInstToKernelChannel_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4
kfifoConvertInstToKernelChannel_GM107
          (long param_1,undefined8 param_2,undefined8 *param_3,long *param_4)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long local_1e0;
  undefined1 local_1d8 [40];
  undefined1 local_1b0 [384];
  
  lVar1 = *(long *)(param_1 + 0x1b78);
  local_1e0 = 0;
  if (param_3 == (undefined8 *)0x0) {
    nvAssertFailedNoLog("pInst != NULL","src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x239
                       );
    return 0x1f;
  }
  if (param_4 != (long *)0x0) {
    *param_4 = 0;
    if (*(int *)(param_3 + 1) == 0) {
      uVar10 = 2;
    }
    else {
      uVar10 = 1;
      if (1 < *(int *)(param_3 + 1) - 2U) {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x249,
                     "kfifoConvertInstToKernelChannel_GM107",4,"NVRM: unknown inst target 0x%x\n");
        return 0x1e;
      }
    }
    memdescCreateExisting(local_1b0,param_1,0x1000,uVar10,1,0x2000000);
    memdescDescribe(local_1b0,uVar10,*param_3,0x1000);
    kfifoGetChannelIterator_IMPL(param_1,param_2,local_1d8,0xffffffff);
    do {
      do {
        while( true ) {
          iVar7 = kfifoGetNextKernelChannel_IMPL(param_1,param_2,local_1d8,&local_1e0);
          lVar3 = local_1e0;
          if (iVar7 != 0) {
            uVar4 = kgmmuGetHwPteApertureFromMemdesc_GM107
                              (*(undefined8 *)(param_1 + 0x1b98),local_1b0);
            uVar10 = memdescGetPhysAddr(local_1b0,1,0);
            nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x276,
                         "kfifoConvertInstToKernelChannel_GM107",1,
                         "NVRM: No channel found for instance 0x%016llx (target 0x%x)\n",uVar10,
                         uVar4);
            memdescDestroy(local_1b0);
            return 0x21;
          }
          if (local_1e0 != 0) break;
          nvAssertFailedNoLog("pKernelChannel != NULL",
                              "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x260);
        }
        uVar8 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
        plVar2 = *(long **)(lVar3 + 0x2d8 + (ulong)uVar8 * 8);
      } while (((plVar2 == (long *)0x0) || (*plVar2 == 0)) ||
              (iVar7 = kchannelGetGfid_IMPL(local_1e0), iVar7 != *(int *)((long)param_3 + 0xc)));
      uVar10 = memdescGetPhysAddr(local_1b0,1,0);
      uVar4 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),local_1b0);
      uVar9 = memdescGetPhysAddr(*plVar2,1,0);
      uVar5 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),*plVar2);
      cVar6 = (**(code **)(lVar1 + 0x238))(param_1,lVar1,uVar5,uVar9,uVar4,uVar10);
    } while (cVar6 == '\0');
    *param_4 = local_1e0;
    memdescDestroy(local_1b0);
    return 0;
  }
  nvAssertFailedNoLog("ppKernelChannel != NULL",
                      "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x23a);
  return 0x1f;
}


// ===== 00325740 kfifoEngineInfoXlate_GM107 =====

int kfifoEngineInfoXlate_GM107
              (undefined8 param_1,long param_2,uint param_3,uint param_4,uint param_5,
              undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  
  uVar6 = (ulong)param_3;
  if (*(long *)(param_2 + 0x3d8) == 0) {
    if (param_6 == (undefined4 *)0x0) goto LAB_003258f8;
    if (param_5 == 0x10) goto LAB_00325920;
    iVar2 = kfifoConstructEngineList_KERNEL();
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"kfifoConstructEngineList_HAL(pGpu, pKernelFifo)",
                 "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x2b6);
      return iVar2;
    }
    if (*(long *)(param_2 + 0x3d8) == 0) {
      nvAssertFailedNoLog("pEngineInfo != NULL",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x2b9);
      return 0x40;
    }
  }
  else {
    if (param_6 == (undefined4 *)0x0) {
LAB_003258f8:
      nvAssertFailedNoLog("pOutVal != NULL","src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",
                          0x2ae);
      return 0x1f;
    }
    if (param_5 == 0x10) {
LAB_00325920:
      nvAssertFailedNoLog("outType != ENGINE_INFO_TYPE_PBDMA_ID",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x2b1);
      return 0x1f;
    }
  }
  uVar1 = *(uint *)(param_2 + 0x3d0);
  if (param_3 == 0xf) {
    if (uVar1 <= param_4) {
      nvAssertFailedNoLog("inVal < pEngineInfo->engineInfoListSize",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x2bd);
      return 0x1f;
    }
    lVar3 = (ulong)param_4 * 0x60 + *(long *)(param_2 + 0x3d8);
    if (lVar3 == 0) {
      return 0x57;
    }
  }
  else {
    if (uVar1 == 0) {
      return 0x57;
    }
    lVar3 = *(long *)(param_2 + 0x3d8);
    lVar5 = (ulong)uVar1 * 0x60 + lVar3;
    if (param_3 == 0x10) {
      for (; (*(int *)(lVar3 + 0x4c) == 0 ||
             ((param_4 != *(uint *)(lVar3 + 0x3c) &&
              ((*(int *)(lVar3 + 0x4c) == 1 || (*(uint *)(lVar3 + 0x40) != param_4))))));
          lVar3 = lVar3 + 0x60) {
        if (lVar5 == lVar3 + 0x60) {
          return 0x57;
        }
      }
    }
    else {
      uVar1 = *(uint *)(lVar3 + uVar6 * 4);
      while (uVar1 != param_4) {
        lVar3 = lVar3 + 0x60;
        if (lVar5 == lVar3) {
          return 0x57;
        }
        uVar1 = *(uint *)(lVar3 + uVar6 * 4);
      }
    }
  }
  if (param_5 < 0x11) {
    uVar4 = 1L << ((byte)param_5 & 0x3f);
    if ((uVar4 & 0x97f5) != 0) goto LAB_00325804;
    if ((uVar4 & 0x1680a) != 0) {
      if (*(int *)(lVar3 + 0x30) == 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x2f0,
                     "kfifoEngineInfoXlate_GM107",4,
                     "NVRM: Asked for host-specific type(0x%x) for non-host engine type(0x%x),val(0x%08x)\n"
                     ,param_5,uVar6,(ulong)param_4);
      }
      goto LAB_00325804;
    }
  }
  nvAssertFailedNoLog("0 && \"check all ENGINE_INFO_TYPE are classified as host-driven or not\"",
                      "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x29a);
LAB_00325804:
  *param_6 = *(undefined4 *)(lVar3 + (ulong)param_5 * 4);
  return 0;
}


// ===== 003259e0 kfifoChannelGroupGetLocalMaxSubcontext_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoChannelGroupGetLocalMaxSubcontext_GM107
               (undefined8 param_1,long param_2,undefined8 param_3,undefined1 param_4)

{
  (**(code **)(param_2 + 0x1e8))(param_1,param_2,param_4);
  return;
}


// ===== 00325a00 kfifoSetupUserD_GM107 =====

void kfifoSetupUserD_GM107(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_20 = 0;
  local_18 = 0;
  local_10 = 0;
  local_28 = param_3;
  iVar1 = memmgrMemSet_IMPL(*(undefined8 *)(param_1 + 0x1b78),&local_28,0,0x200,0);
  if (iVar1 == 0) {
    return;
  }
  nvAssertOkFailedNoLog
            (iVar1,
             "memmgrMemSet(GPU_GET_MEMORY_MANAGER(pGpu), &tSurf, 0, NV_RAMUSERD_CHAN_SIZE, TRANSFER_FLAGS_NONE)"
             ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x313);
  return;
}


// ===== 00325a70 kfifoGetNumEngines_GM107 =====

int kfifoGetNumEngines_GM107(undefined8 param_1,long param_2)

{
  int iVar1;
  
  if (*(long *)(param_2 + 0x3d8) == 0) {
    iVar1 = kfifoConstructEngineList_KERNEL();
    if (iVar1 != 0) {
      nvAssertFailedNoLog("kfifoConstructEngineList_HAL(pGpu, pKernelFifo) == NV_OK",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x32d);
      return 0;
    }
    if (*(long *)(param_2 + 0x3d8) == 0) {
      nvAssertFailedNoLog("pEngineInfo != NULL",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x330);
      return 0;
    }
  }
  iVar1 = *(int *)(param_2 + 0x3d0);
  if (iVar1 == 0) {
    nvAssertFailedNoLog("pEngineInfo->engineInfoListSize",
                        "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x333);
    iVar1 = *(int *)(param_2 + 0x3d0);
  }
  return iVar1 + -1;
}


// ===== 00325b30 kfifoGetEngineName_GM107 =====

char * kfifoGetEngineName_GM107(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = 0;
  if (*(long *)(param_1 + 0x3d8) != 0) {
    lVar2 = param_1 + 0x380;
  }
  uVar1 = *(uint *)(lVar2 + 0x50);
  if (param_2 != 0xf) {
    if (uVar1 != 0) {
      lVar2 = *(long *)(lVar2 + 0x58);
      lVar3 = (ulong)uVar1 * 0x60 + lVar2;
      do {
        if (*(uint *)(lVar2 + (ulong)param_2 * 4) == param_3) {
          return (char *)(lVar2 + 0x50);
        }
        lVar2 = lVar2 + 0x60;
      } while (lVar2 != lVar3);
    }
    return "UNKNOWN";
  }
  if (param_3 < uVar1) {
    return (char *)((ulong)param_3 * 0x60 + *(long *)(lVar2 + 0x58) + 0x50);
  }
  nvAssertFailedNoLog("inVal < pEngineInfo->engineInfoListSize",
                      "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x34f);
  return (char *)0x0;
}


// ===== 00325bc5 kfifoGetMaxNumRunlists_GM107.cold =====

void kfifoGetMaxNumRunlists_GM107_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00325bd0 kfifoGetMaxNumRunlists_GM107 =====

undefined4 kfifoGetMaxNumRunlists_GM107(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  if (*(long *)(param_2 + 0x3d8) != 0) {
    return *(undefined4 *)(param_2 + 0x3c8);
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00325bf0 kfifoGetEnginePbdmaIds_GM107 =====

int kfifoGetEnginePbdmaIds_GM107
              (undefined8 param_1,long param_2,uint param_3,uint param_4,long *param_5,
              undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  if (*(long *)(param_2 + 0x3d8) == 0) {
    iVar2 = kfifoConstructEngineList_KERNEL();
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"kfifoConstructEngineList_HAL(pGpu, pKernelFifo)",
                 "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",900);
      return iVar2;
    }
    if (*(long *)(param_2 + 0x3d8) == 0) {
      nvAssertFailedNoLog("pEngineInfo != NULL",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x387);
      return 0x40;
    }
  }
  uVar1 = *(uint *)(param_2 + 0x3d0);
  if (param_3 == 0xf) {
    if (param_4 < uVar1) {
      *param_5 = *(long *)(param_2 + 0x3d8) + 0x3c + (ulong)param_4 * 0x60;
      *param_6 = *(undefined4 *)(*(long *)(param_2 + 0x3d8) + 0x4c + (ulong)param_4 * 0x60);
      return 0;
    }
    nvAssertFailedNoLog("val < pEngineInfo->engineInfoListSize",
                        "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x38c);
  }
  else if (uVar1 != 0) {
    lVar3 = 0;
    do {
      if (*(uint *)(*(long *)(param_2 + 0x3d8) + (ulong)param_3 * 4 + lVar3) == param_4) {
        *param_5 = *(long *)(param_2 + 0x3d8) + 0x3c + lVar3;
        *param_6 = *(undefined4 *)(*(long *)(param_2 + 0x3d8) + 0x4c + lVar3);
        return 0;
      }
      lVar3 = lVar3 + 0x60;
    } while (lVar3 != (ulong)uVar1 * 0x60);
  }
  return 0x1f;
}


// ===== 00325d40 kfifoGetEnginePartnerList_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGetEnginePartnerList_GM107(undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  long lVar9;
  int local_64;
  int local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  undefined4 local_50;
  int local_4c;
  long local_48;
  long local_40 [2];
  
  iVar2 = (**(code **)(param_2 + 0x240))();
  local_54 = 0;
  iVar3 = gpuGetRmEngineType_IMPL(*param_3);
  uVar1 = param_3[2];
  uVar4 = (**(code **)(param_2 + 0x200))(param_1,param_2);
  if (uVar1 < uVar4) {
    iVar5 = (**(code **)(param_2 + 0x218))(param_1,param_2,2,iVar3,3,&local_64);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)rmEngineType, ENGINE_INFO_TYPE_RUNLIST, &srcRunlist)"
                 ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3c2);
      return iVar5;
    }
    iVar5 = (**(code **)(param_2 + 600))(param_1,param_2,2,iVar3,&local_48,&local_5c);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,
                 "kfifoGetEnginePbdmaIds_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)rmEngineType, &pSrcPbdmaIds, &numSrcPbdmaIds)"
                 ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3c8);
      return iVar5;
    }
    param_3[3] = 0;
    if ((uint)param_3[2] < local_5c) {
      if (iVar2 == 0) {
        return 0;
      }
      iVar5 = *(int *)(local_48 + (ulong)(uint)param_3[2] * 4);
      iVar8 = 0;
      do {
        iVar6 = (**(code **)(param_2 + 0x218))(param_1,param_2,0xf,iVar8,0,&local_50);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,
                     "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, ENGINE_INFO_TYPE_ENG_DESC, &engDesc)"
                     ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3dd);
          return iVar6;
        }
        iVar6 = gpuGetClassList_IMPL(param_1,&local_54,0,local_50);
        if (iVar6 != 0) {
          nvAssertOkFailedNoLog
                    (iVar6,"gpuGetClassList(pGpu, &numClasses, NULL, engDesc)",
                     "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3e1);
          return iVar6;
        }
        if (local_54 == 0) {
          nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3e4,
                       "kfifoGetEnginePartnerList_GM107",1,
                       "NVRM: EngineID %x is not part classDB, skipping\n",local_50);
        }
        else {
          iVar6 = (**(code **)(param_2 + 0x218))(param_1,param_2,0xf,iVar8,3,&local_60);
          if (iVar6 != 0) {
            nvAssertOkFailedNoLog
                      (iVar6,
                       "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, ENGINE_INFO_TYPE_RUNLIST, &runlist)"
                       ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3ea);
            return iVar6;
          }
          if (local_60 == local_64) {
            iVar6 = (**(code **)(param_2 + 600))(param_1,param_2,0xf,iVar8,local_40,&local_58);
            if (iVar6 != 0) {
              nvAssertOkFailedNoLog
                        (iVar6,
                         "kfifoGetEnginePbdmaIds_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, &pPbdmaIds, &numPbdmaIds)"
                         ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3f3);
              return iVar6;
            }
            if (local_58 != 0) {
              lVar9 = 0;
              do {
                if (*(int *)(local_40[0] + lVar9 * 4) == iVar5) {
                  iVar6 = (**(code **)(param_2 + 0x218))(param_1,param_2,0xf,iVar8,2,&local_4c);
                  if (iVar6 != 0) {
                    nvAssertOkFailedNoLog
                              (iVar6,
                               "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_INVALID, i, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&localRmEngineType)"
                               ,"src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x3fb);
                    return iVar6;
                  }
                  if (local_4c != iVar3) {
                    uVar1 = param_3[3];
                    param_3[3] = uVar1 + 1;
                    uVar7 = gpuGetNv2080EngineType_IMPL();
                    param_3[(ulong)uVar1 + 4] = uVar7;
                    if (0x1f < (uint)param_3[3]) {
                      return 0x1f;
                    }
                  }
                }
                lVar9 = lVar9 + 1;
              } while ((uint)lVar9 < local_58);
            }
          }
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 != iVar2);
      return 0;
    }
  }
  return 0x1f;
}


// ===== 00326100 kfifoRunlistGetBaseShift_GM107 =====

undefined8 kfifoRunlistGetBaseShift_GM107(void)

{
  return 0xc;
}


// ===== 00326110 kfifoGetUserdSizeAlign_GM107 =====

void kfifoGetUserdSizeAlign_GM107(undefined8 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0x200;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 9;
  }
  return;
}


// ===== 00326130 kfifoCheckEngine_GM107 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kfifoCheckEngine_GM107(undefined8 param_1,long param_2,undefined4 param_3,undefined1 *param_4)

{
  int iVar1;
  int local_1c [3];
  
  local_1c[0] = 0;
  iVar1 = (**(code **)(param_2 + 0x218))(param_1,param_2,0,param_3,0xc,local_1c);
  if (iVar1 == 0) {
    *param_4 = local_1c[0] != 0;
    return 0;
  }
  *param_4 = 0;
  return 0;
}


// ===== 00326190 kfifoWriteRamfcGpfifo_GM107 =====

void kfifoWriteRamfcGpfifo_GM107
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,ulong param_4,
               undefined4 param_5)

{
  uint uVar1;
  
  if ((param_4 & 7) != 0) {
    nvAssertFailedNoLog("FLD_TEST_DRF(_PBDMA, _GP_BASE, _RSVD, _ZERO, NvU64_LO32(gpFifoOffset))",
                        "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm107.c",0x477);
  }
  param_3[0x12] = (int)param_4;
  uVar1 = nvLogBase2(param_5);
  param_3[0x13] = (uint)(param_4 >> 0x20) & 0xff | (uVar1 & 0x1f) << 0x10;
  *param_3 = 0;
  param_3[5] = 0;
  return;
}


// ===== 00326220 kfifoGetNumPBDMAs_GM200 =====

uint kfifoGetNumPBDMAs_GM200(long param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (*(long *)(param_2 + 0x3d8) == 0) {
    if ((*(char *)(param_1 + 0x908) == '\0') && (*(char *)(param_1 + 0x909) == '\0')) {
      bVar1 = regRead032(param_1 + 0x3a18,0,0,0x2004,0);
      if ((*(char *)(param_1 + 0x44c) == '\0') ||
         (uVar2 = (uint)bVar1, *(char *)(param_1 + 0x450) != '\0')) {
        uVar2 = 0;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm200.c",0x3d,
                   "kfifoGetNumPBDMAs_GM200",1,"NVRM: %d PBDMAs\n");
    }
    else {
      nvAssertFailedNoLog("!IS_VIRTUAL(pGpu) && !IS_GSP_CLIENT(pGpu)",
                          "src/kernel/gpu/fifo/arch/maxwell/kernel_fifo_gm200.c",0x34);
      uVar2 = 0;
    }
    return uVar2;
  }
  return *(uint *)(param_2 + 0x380);
}


// ===== 003262f0 _kfifoIsValidCETag_GP102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kfifoIsValidCETag_GP102(long param_1,long param_2,undefined4 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  long lVar6;
  undefined8 uVar7;
  uint uVar8;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  int *local_40;
  int *local_38;
  undefined8 local_30;
  
  local_50 = 0;
  local_48 = 0;
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar3 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar3 == '\0')) {
    uVar8 = 0xd334df00;
  }
  else {
    lVar6 = resservGetTlsCallContext();
    uVar2 = *(undefined8 *)(param_1 + 0x1bc0);
    iVar4 = refFindAncestorOfType(*(undefined8 *)(lVar6 + 0x10),&DAT_00e0ac20,&local_40);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "refFindAncestorOfType(pCallContext->pResourceRef, classId(Device), &pDeviceRef)",
                 "src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xd0);
      return 0;
    }
    uVar7 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 2),__nvoc_class_def_Device);
    iVar4 = kmigmgrGetInstanceRefFromDevice_IMPL(param_1,uVar2,uVar7,&local_38);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,"kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                 "src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xd5);
    }
    iVar4 = kmigmgrGetLocalToGlobalEngineType_IMPL(param_1,uVar2,local_38,local_30,1,&local_44);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog
                (iVar4,
                 "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, RM_ENGINE_TYPE_GR(0), &rmEngineType)"
                 ,"src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xd6);
    }
    uVar8 = local_44 - 1 | 0xd334df00;
  }
  iVar4 = (**(code **)(param_2 + 0x218))(param_1,param_2,0,param_3,3,&local_50);
  if (iVar4 == 0) {
    iVar4 = (**(code **)(param_2 + 600))(param_1,param_2,0,param_3,&local_40,&local_4c);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(param_2 + 0x218))(param_1,param_2,0,uVar8,3,&local_48);
      if (iVar4 == 0) {
        iVar4 = (**(code **)(param_2 + 600))(param_1,param_2,0,uVar8,&local_38,&local_44);
        if (iVar4 == 0) {
          if ((local_50 == local_48) && (local_4c != 0)) {
            piVar1 = local_40 + local_4c;
            if (local_44 == 0) {
              do {
                local_40 = local_40 + 1;
              } while (piVar1 != local_40);
            }
            else {
              do {
                piVar5 = local_38;
                do {
                  if (*local_40 == *piVar5) {
                    return 1;
                  }
                  piVar5 = piVar5 + 1;
                } while (local_38 + local_44 != piVar5);
                local_40 = local_40 + 1;
              } while (piVar1 != local_40);
            }
          }
        }
        else {
          nvAssertFailedNoLog("kfifoGetEnginePbdmaIds_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_ENG_DESC, grEngineTag, &pSrcPbdmaIds, &numSrcPbdmaIds) == NV_OK"
                              ,"src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xed);
        }
      }
      else {
        nvAssertFailedNoLog("kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_ENG_DESC, grEngineTag, ENGINE_INFO_TYPE_RUNLIST, &srcRunlist) == NV_OK"
                            ,"src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xe7);
      }
    }
    else {
      nvAssertFailedNoLog("kfifoGetEnginePbdmaIds_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_ENG_DESC, ceEngineTag, &pCePbdmaIds, &numCePbdmaIds) == NV_OK"
                          ,"src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xe1);
    }
  }
  return 0;
}


// ===== 003265b0 kfifoValidateSCGTypeAndRunqueue_GP102 =====

undefined1  [16]
kfifoValidateSCGTypeAndRunqueue_GP102(undefined8 param_1,int param_2,undefined8 param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  ulong uStack_10;
  
  if ((param_2 == 1) && ((int)param_3 == 0)) {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0x37,
                 "kfifoValidateSCGTypeAndRunqueue_GP102",1,
                 "NVRM: Invalid (SCG,runqueue) combination: (0x%x,0x%x)\n",1,0);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uStack_10;
    return auVar1 << 0x40;
  }
  auVar2._8_8_ = param_3;
  auVar2._0_8_ = 1;
  return auVar2;
}


// ===== 00326610 kfifoValidateEngineAndRunqueue_GP102 =====

uint kfifoValidateEngineAndRunqueue_GP102
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  
  if (param_4 == 0) {
    return 1;
  }
  if (param_4 == 1) {
    uVar1 = (uint)((ulong)param_3 >> 8) & 0xffffff;
    if (uVar1 == 0xd334df) {
      return 1;
    }
    if (uVar1 == 0x793ceb) {
      uVar1 = _kfifoIsValidCETag_GP102();
      if ((char)uVar1 != '\0') {
        return uVar1;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0x62,
                   "kfifoValidateEngineAndRunqueue_GP102",4,
                   "NVRM: Runqueue 1 only supports GR/GRCE\n");
      return uVar1 & 0xff;
    }
    if ((int)param_3 == -0x6a590b00) {
      return 1;
    }
    nvDbg_Printf("src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0x6c,
                 "kfifoValidateEngineAndRunqueue_GP102",4,"NVRM: Runqueue 1 only supports GR/GRCE\n"
                );
  }
  else {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0x71,
                 "kfifoValidateEngineAndRunqueue_GP102",4,"NVRM: Unsupported runqueue: 0x%x\n",
                 param_4);
    nvAssertFailedNoLog(&DAT_00d1807a,"src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0x72);
  }
  return 0;
}


// ===== 00326720 kfifoValidateEngineAndSubctxType_GP102 =====

uint kfifoValidateEngineAndSubctxType_GP102
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  uint uVar1;
  
  if (param_4 == 0) {
    return 1;
  }
  if (param_4 == 1) {
    uVar1 = (uint)((ulong)param_3 >> 8) & 0xffffff;
    if (uVar1 == 0xd334df) {
      return 1;
    }
    if (uVar1 == 0x793ceb) {
      uVar1 = _kfifoIsValidCETag_GP102();
      if ((char)uVar1 != '\0') {
        return uVar1;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0x9c,
                   "kfifoValidateEngineAndSubctxType_GP102",4,
                   "NVRM: ASYNC Subcontext only supported on GR/GRCE\n");
      return uVar1 & 0xff;
    }
    if ((int)param_3 == -0x6a590b00) {
      return 1;
    }
    nvDbg_Printf("src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xa6,
                 "kfifoValidateEngineAndSubctxType_GP102",4,
                 "NVRM: ASYNC Subcontext only supported on GR/GRCE\n");
  }
  else {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xac,
                 "kfifoValidateEngineAndSubctxType_GP102",4,
                 "NVRM: Unsupported Subcontext Type: 0x%x\n",param_4);
    nvAssertFailedNoLog(&DAT_00d1807a,"src/kernel/gpu/fifo/arch/pascal/kernel_fifo_gp102.c",0xae);
  }
  return 0;
}


// ===== 00326830 kchannelGetUserdInfo_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelGetUserdInfo_TU102
              (long param_1,long param_2,undefined8 *param_3,undefined8 *param_4,ulong *param_5)

{
  char cVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  uint local_54;
  undefined8 local_50;
  undefined1 local_44 [8];
  int local_3c;
  
  if (param_2 != 0) {
    lVar2 = *(long *)(param_1 + 0x1b70);
    cVar1 = *(char *)(param_1 + 0x454);
    CliGetChannelClassInfo
              (*(undefined4 *)(*(long *)(*(long *)(param_2 + 0x140) + 0x48) + 0x11c),local_44);
    if (local_3c == 1) {
      if (*(char *)(param_2 + 0x398) == '\0') {
        iVar4 = (**(code **)(param_2 + 0x1b8))(param_1,param_2,&local_50,&local_54);
        if (iVar4 == 0) {
          *param_4 = local_50;
          *param_5 = (ulong)local_54;
          if (param_3 != (undefined8 *)0x0) {
            if (cVar1 == '\0') {
              uVar5 = gpumgrGetGpuPhysFbAddr(param_1);
              *param_3 = uVar5;
            }
            else {
              if (*(char *)(param_1 + 0x45b) == '\0') {
                nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                                    "src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x50);
              }
              *param_3 = *(undefined8 *)(lVar2 + 0x478);
            }
          }
        }
      }
      else {
        iVar4 = 0x3f;
        nvAssertFailedNoLog("!pKernelChannel->bClientAllocatedUserD",
                            "src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x40);
      }
    }
    else {
      iVar4 = 0xffff;
      nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x5c,
                   "kchannelGetUserdInfo_TU102",4,
                   "NVRM: class = %x not supported for user base mapping\n",
                   *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x140) + 0x48) + 0x11c));
    }
    return iVar4;
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 003269b0 kchannelGetUserdBar1MapOffset_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kchannelGetUserdBar1MapOffset_TU102(undefined8 param_1,long param_2,long *param_3,uint *param_4)

{
  char cVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar2 = gpuGetKernelFifoShared_IMPL();
  if (param_2 != 0) {
    cVar1 = (**(code **)(lVar2 + 0x2f8))(lVar2);
    if (cVar1 == '\0') {
      nvAssertFailedNoLog("kfifoUserdNeedsIsolation(pKernelFifo)",
                          "src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x7d);
      uVar4 = 0x56;
    }
    else if (*(int *)(lVar2 + 0x430) == 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x82,
                   "kchannelGetUserdBar1MapOffset_TU102",4,
                   "NVRM: fifoGetUserdBar1Offset_GF100: BAR1 map of USERD has not been setup yet\n")
      ;
      nvAssertFailedNoLog(&DAT_00d1828d,"src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",
                          0x85);
      uVar4 = 0xffff;
    }
    else {
      (**(code **)(lVar2 + 0x2a0))(lVar2,param_4,0);
      lVar3 = (ulong)(*(int *)(param_2 + 0x2b4) * *param_4) + *(long *)(lVar2 + 0x428);
      *param_3 = lVar3;
      if ((ulong)*(uint *)(lVar2 + 0x430) + *(long *)(lVar2 + 0x428) < lVar3 + (ulong)*param_4) {
        nvAssertFailedNoLog("(*bar1MapOffset + *bar1MapSize) <= (pUserdInfo->userdBar1MapStartOffset + pUserdInfo->userdBar1MapSize)"
                            ,"src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x8e);
      }
      uVar4 = 0;
    }
    return uVar4;
  }
  nvAssertFailedNoLog("pKernelChannel != NULL",
                      "src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x7b);
  return 0x1f;
}


// ===== 00326b40 kchannelMap_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelMap_TU102(long param_1,long param_2,undefined8 param_3,ulong *param_4)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  long *plVar9;
  ulong uVar10;
  long local_40 [2];
  
  lVar1 = *(long *)(param_2 + 8);
  plVar9 = (long *)__nvoc_dynamicCast(lVar1,__nvoc_class_def_RmClient);
  if (*(char *)(param_1 + 0x398) != '\0') {
    nvAssertFailedNoLog("!pKernelChannel->bClientAllocatedUserD",
                        "src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0xbc);
    return 0x3f;
  }
  iVar6 = gpuresGetByDeviceOrSubdeviceHandle_IMPL(lVar1,*(undefined4 *)(param_4[4] + 0x10),local_40)
  ;
  if (iVar6 != 0) {
    return iVar6;
  }
  uVar2 = *(undefined8 *)(*(long *)(local_40[0] + 0xd0) + 0xe0);
  if ((*(byte *)((long)param_4 + 0x12) & 2) == 0) {
    uVar10 = *param_4;
    if (*(ulong *)(param_1 + 0x400) <= uVar10) {
      return 0x20;
    }
    if ((param_4[1] == 0) || (*(ulong *)(param_1 + 0x400) < param_4[1] + uVar10)) {
      return 0x2e;
    }
  }
  else {
    *param_4 = 0;
    uVar10 = 0;
    param_4[1] = *(ulong *)(param_1 + 0x400);
  }
  uVar3 = param_4[10];
  uVar8 = *(undefined4 *)(uVar3 + 0x20);
  uVar7 = (**(code **)(*plVar9 + 0xd8))(plVar9);
  iVar6 = (**(code **)(param_1 + 0x1f0))(uVar2,param_1,uVar7,uVar10,uVar8,param_4 + 3,uVar3 + 0x18);
  if (iVar6 != 0) {
    return iVar6;
  }
  uVar5 = param_4[2];
  uVar10 = param_4[1];
  uVar3 = param_4[3];
  uVar4 = *(undefined8 *)(param_4[10] + 0x18);
  iVar6 = *(int *)(lVar1 + 0x4c);
  *(undefined8 *)(param_4[10] + 0x10) = uVar2;
  *(bool *)(param_4[10] + 0x24) = iVar6 == 1;
  uVar8 = osGetCurrentProcess();
  *(undefined4 *)(param_4 + 9) = uVar8;
  param_4[3] = uVar3;
  *(undefined8 *)(param_4[10] + 0x18) = uVar4;
  param_4[1] = uVar10;
  *(int *)(param_4 + 2) = (int)uVar5;
  param_4[8] = (ulong)*(uint *)(param_1 + 0x2b4);
  return 0;
}


// ===== 00326d60 kchannelUnmap_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchannelUnmap_TU102(long param_1,long param_2,long param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  long *plVar4;
  
  plVar4 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 8),__nvoc_class_def_RmClient);
  if (*(char *)(param_1 + 0x398) == '\0') {
    lVar1 = *(long *)(param_3 + 0x50);
    uVar2 = *(undefined8 *)(lVar1 + 0x10);
    uVar3 = (**(code **)(*plVar4 + 0xd8))(plVar4);
    (**(code **)(param_1 + 0x1f8))(uVar2,param_1,uVar3,param_3 + 0x18,lVar1 + 0x18);
    return 0;
  }
  return 0x3f;
}


// ===== 00326e00 kchannelMapUserD_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelMapUserD_TU102
              (long param_1,long param_2,uint param_3,long param_4,undefined4 param_5,long *param_6,
              undefined8 param_7)

{
  int iVar1;
  long local_50;
  long local_48;
  ulong local_40 [2];
  
  if (*(char *)(param_2 + 0x398) != '\0') {
    return 0;
  }
  iVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,&local_50,&local_48,local_40);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(long *)(param_1 + 0x848) == local_50) {
    iVar1 = osMapGPU(param_1,param_3,(int)local_48 + (int)param_4,local_40[0] & 0xffffffff,param_5,
                     param_6,param_7);
  }
  else {
    param_4 = local_50 + local_48 + param_4;
    if (param_3 < 2) {
      iVar1 = osMapPciMemoryUser(*(undefined8 *)(param_1 + 0x4e0),param_4,local_40[0],param_5,
                                 param_6,param_7,*(char *)(param_1 + 0x454) == '\0');
    }
    else {
      iVar1 = osMapPciMemoryKernel64(param_1,param_4,local_40[0],param_5,param_6);
    }
    if ((iVar1 == 0) && (*param_6 != 0)) goto LAB_00326ead;
    nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x14b,
                 "kchannelMapUserD_TU102",4,
                 "NVRM: BAR1 offset 0x%llx for USERD of channel 0x%08x could not be cpu mapped\n",
                 local_48,*(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4));
  }
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_00326ead:
  kchannelSetCpuMapped(param_1,param_2,1);
  return 0;
}


// ===== 00326f90 kchannelUnmapUserD_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kchannelUnmapUserD_TU102
               (long param_1,long param_2,uint param_3,undefined8 *param_4,undefined8 *param_5)

{
  int iVar1;
  long local_50;
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 uStack_3c;
  
  if (*(char *)(param_2 + 0x398) == '\0') {
    iVar1 = (**(code **)(param_2 + 0x1b0))(param_1,param_2,&local_50,local_48,&local_40);
    if (iVar1 == 0) {
      if (*(long *)(param_1 + 0x848) == local_50) {
        osUnmapGPU(*(undefined8 *)(param_1 + 0x4e0),param_3,*param_4,local_40,*param_5);
      }
      else if (param_3 < 2) {
        osUnmapPciMemoryUser
                  (*(undefined8 *)(param_1 + 0x4e0),*param_4,CONCAT44(uStack_3c,local_40),*param_5);
      }
      else {
        osUnmapPciMemoryKernel64(param_1);
      }
      kchannelSetCpuMapped(param_1,param_2,0);
    }
    else {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c"
                          ,0x175);
    }
    return;
  }
  return;
}


// ===== 00327080 kchannelGetMapAddrSpace_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

ulong kchannelGetMapAddrSpace_TU102
                (long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  long lVar1;
  ulong uVar2;
  undefined4 local_20;
  undefined1 local_1c [12];
  
  lVar1 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  uVar2 = (**(code **)(lVar1 + 0x2a8))(lVar1,&local_20,local_1c,*(code **)(lVar1 + 0x2a8));
  if ((int)uVar2 == 0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_20;
    }
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,
             "kfifoGetUserdLocation_HAL(pKernelFifo, &userdAperture, &userdAttribute)",
             "src/kernel/gpu/fifo/arch/turing/kernel_channel_tu102.c",0x19e);
  return uVar2 & 0xffffffff;
}


// ===== 00327100 kfifoUpdateUsermodeDoorbell_TU102 =====

undefined8 kfifoUpdateUsermodeDoorbell_TU102(long param_1,undefined8 param_2,undefined4 param_3)

{
  nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x35,
               "kfifoUpdateUsermodeDoorbell_TU102",1,"NVRM: Poking workSubmitToken 0x%x\n",param_3);
  regWrite032(param_1 + 0x3a18,0,0,*(int *)(param_1 + 0x3a64) + 0x30090,param_3,0);
  return 0;
}


// ===== 00327170 kfifoGenerateWorkSubmitTokenHal_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGenerateWorkSubmitTokenHal_TU102
              (undefined8 param_1,long param_2,long param_3,uint *param_4,char param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_40;
  uint local_3c [3];
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x54);
    return 0x21;
  }
  if (param_4 == (uint *)0x0) {
    iVar2 = 0x1f;
    nvAssertFailedNoLog("pGeneratedToken != NULL",
                        "src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x56);
  }
  else {
    uVar4 = *(uint *)(param_3 + 0x2b4);
    iVar2 = vgpuGetCallingContextGfid(param_1,&local_40);
    if (iVar2 == 0) {
      if (((param_5 == '\0') && (local_40 != 0)) &&
         (iVar3 = (**(code **)(param_2 + 0x2c8))
                            (param_1,param_2,uVar4,local_40,*(undefined4 *)(param_3 + 0x42c),
                             local_3c), uVar4 = local_3c[0], iVar3 != 0)) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kfifoGetVChIdForSChId_HAL(pGpu, pKernelFifo, chId, gfid, kchannelGetEngineType(pKernelChannel), &vChId)"
                   ,"src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x66);
        return iVar3;
      }
      cVar1 = kchannelIsRunlistSet(param_1,param_3);
      if (cVar1 == '\0') {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x6f,
                     "kfifoGenerateWorkSubmitTokenHal_TU102",4,
                     "NVRM: FAILED channel 0x%08x is not assigned to runlist yet\n",
                     *(uint *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4));
        return 0x40;
      }
      uVar4 = (*(uint *)(param_3 + 0x2b0) & 0x7f) << 0x10 | uVar4 & 0xfff;
      *param_4 = uVar4;
      nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x7a,
                   "kfifoGenerateWorkSubmitTokenHal_TU102",1,
                   "NVRM: Generated workSubmitToken 0x%x for channel 0x%08x runlist 0x%x\n",uVar4,
                   *(int *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4),
                   *(int *)(param_3 + 0x2b0));
    }
    else {
      nvAssertOkFailedNoLog
                (iVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)",
                 "src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x5a);
    }
  }
  return iVar2;
}


// ===== 003273b0 kfifoPrintPbdmaId_TU102 =====

char * kfifoPrintPbdmaId_TU102(undefined8 param_1,undefined8 param_2,uint param_3)

{
  if (param_3 < 0xc) {
    return *(char **)(pbdmaIdString_3 + (ulong)param_3 * 8);
  }
  nvAssertFailedNoLog("pbdmaId < NV_HOST_NUM_PBDMA",
                      "src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x93);
  return "UNKNOWN";
}


// ===== 003273f0 kfifoPrintInternalEngine_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

char * kfifoPrintInternalEngine_TU102(long param_1,long param_2,uint param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  uint local_2c;
  
  lVar1 = *(long *)(param_1 + 0x1b98);
  cVar2 = kfifoIsMmuFaultEngineIdPbdma_IMPL();
  if (cVar2 == '\0') {
    cVar2 = (**(code **)(lVar1 + 0x378))(lVar1,param_3);
    if (cVar2 != '\0') {
      return "BAR1";
    }
    cVar2 = (**(code **)(lVar1 + 0x380))(lVar1,param_3);
    if (cVar2 != '\0') {
      return "BAR2";
    }
    if (param_3 == 0x11) {
      return "CE2";
    }
    if (param_3 < 0x12) {
      if (param_3 == 10) {
        return "NVDEC0";
      }
      if (param_3 < 0xb) {
        if (param_3 == 6) {
          return "PMU";
        }
        if (param_3 < 7) {
          if (param_3 == 1) {
            return "DISPLAY";
          }
          if (param_3 == 3) {
            return "PTP";
          }
        }
        else {
          if (param_3 == 8) {
            return "PERF";
          }
          if (param_3 == 9) {
            return "IFB";
          }
        }
      }
      else {
        if (param_3 == 0xe) {
          return "SEC";
        }
        if (0xe < param_3) {
          if (param_3 == 0xf) {
            return "CE0";
          }
          return "CE1";
        }
        if (param_3 == 0xb) {
          return "NVENC0";
        }
        if (param_3 == 0xc) {
          return "NVENC1";
        }
      }
    }
    else {
      if (param_3 == 0x17) {
        return "CE8";
      }
      if (param_3 < 0x18) {
        if (param_3 == 0x14) {
          return "CE5";
        }
        if (0x14 < param_3) {
          if (param_3 == 0x15) {
            return "CE6";
          }
          return "CE7";
        }
        if (param_3 == 0x12) {
          return "CE3";
        }
        return "CE4";
      }
      if (param_3 == 0x1a) {
        return "NVDEC2";
      }
      if (param_3 < 0x1b) {
        if (param_3 == 0x18) {
          return "NVJPG";
        }
        return "NVDEC1";
      }
      if (param_3 == 0x1f) {
        return "PHYSICAL";
      }
    }
    iVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,4,param_3,0,&local_2c);
    if ((iVar3 == 0) && (local_2c >> 8 == 0xd334df)) {
      return "GRAPHICS";
    }
  }
  else {
    iVar3 = kfifoGetPbdmaIdFromMmuFaultId_IMPL(param_1,param_2,param_3,&local_2c);
    if (iVar3 == 0) {
      pcVar4 = (char *)(**(code **)(param_2 + 0x328))(param_1,param_2,local_2c);
      return pcVar4;
    }
    nvAssertFailedNoLog("kfifoGetPbdmaIdFromMmuFaultId(pGpu, pKernelFifo, engineID, &pbdmaId) == NV_OK"
                        ,"src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0xbe);
  }
  return "UNKNOWN";
}


// ===== 003276e0 kfifoGetClientIdString_TU102 =====

char * kfifoGetClientIdString_TU102(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_3 + 0xc);
  if (*(char *)(param_3 + 0x10) == '\0') {
    if (uVar1 < 0x3d) {
      return *(char **)(CSWTCH_35 + (ulong)uVar1 * 8);
    }
  }
  else if (uVar1 < 0x34) {
    return *(char **)(CSWTCH_34 + (ulong)uVar1 * 8);
  }
  return "UNRECOGNIZED_CLIENT";
}


// ===== 00327720 kfifoPreAllocUserD_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoPreAllocUserD_TU102(long param_1,long param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  uint local_50;
  int local_48;
  byte local_44 [4];
  ulong local_40 [2];
  
  uVar10 = gpumgrGetParentGPU();
  lVar11 = gpuGetKernelFifoShared_IMPL(uVar10);
  local_40[0] = 0;
  lVar12 = *(long *)(&DAT_00001b90 + param_1);
  uVar7 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  uVar16 = (ulong)uVar7;
  uVar10 = kfifoGetChidMgr_IMPL(param_1,param_2,0);
  if (*(char *)(param_1 + 0x4913) != '\0') {
    return 0;
  }
  lVar15 = *(long *)(param_1 + 0x1b78);
  local_50 = 100;
  lVar3 = *(long *)(param_1 + 0x1bc0);
  cVar1 = *(char *)(param_1 + 0x454);
  bVar5 = false;
  if (*(long *)(lVar11 + 0x438) == 0) {
    *(undefined8 *)(lVar11 + 0x428) = 0;
    *(undefined4 *)(lVar11 + 0x430) = 0;
    if (*(int *)(lVar11 + 0x3e0) == 1) {
      *(undefined1 *)(param_2 + 0x4b9) = 1;
    }
    local_50 = 0x24;
    bVar5 = true;
  }
  (**(code **)(param_2 + 0x2a0))(param_2,&local_48,local_44,*(code **)(param_2 + 0x2a0));
  iVar8 = kfifoChidMgrGetNumChannels_IMPL(param_1,param_2,uVar10);
  iVar9 = memdescCreate(lVar11 + 1000 + uVar16 * 8,param_1,iVar8 * local_48,
                        1L << (local_44[0] & 0x3f),1,*(undefined4 *)(lVar11 + 0x3e0),
                        *(undefined4 *)(lVar11 + 0x3e4),0);
  if (iVar9 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x232,
                 "kfifoPreAllocUserD_TU102",4,
                 "NVRM: Could not memdescCreate for USERD for %x #channels\n",iVar8);
    goto LAB_00327b12;
  }
  lVar4 = *(long *)(lVar11 + 1000 + uVar16 * 8);
  local_40[0] = *(ulong *)(lVar4 + 0x30);
  if (*(char *)(param_1 + 0x908) == '\0') {
    *(undefined4 *)(lVar4 + 0x9c) = 0x72;
    iVar9 = memdescAlloc(*(undefined8 *)(lVar11 + 1000 + uVar16 * 8));
    if (iVar9 != 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x251,
                   "kfifoPreAllocUserD_TU102",4,"NVRM: Could not allocate USERD for %x #channels\n",
                   iVar8);
      goto LAB_00327b12;
    }
    (**(code **)(lVar15 + 0x388))(param_1,lVar15,*(undefined8 *)(lVar11 + 1000 + uVar16 * 8),1,1);
    iVar9 = 0;
    if (cVar1 == '\0') {
LAB_00327a02:
      if (lVar12 != 0) {
LAB_00327a09:
        if (*(char *)(lVar12 + 0xad45) != '\0') goto LAB_00327a16;
      }
      if ((lVar3 != 0) &&
         (cVar6 = kmigmgrIsMIGMemPartitioningEnabled_IMPL(param_1,lVar3), cVar6 != '\0')) {
        iVar9 = 0x40;
        nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x286,
                     "kfifoPreAllocUserD_TU102",4,
                     "NVRM: Pre-allocated USERD is not supported with MIG\n");
        goto LAB_00327b12;
      }
      uVar14 = (ulong)(local_50 | 0x480);
      iVar9 = kbusMapFbApertureSingle_IMPL
                        (param_1,lVar12,*(undefined8 *)(lVar11 + 1000 + uVar16 * 8),0,lVar11 + 0x428
                         ,local_40,uVar14,0);
      if (iVar9 != 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x291,
                     "kfifoPreAllocUserD_TU102",4,"NVRM: Could not map USERD to BAR1\n",uVar14);
        goto LAB_00327b12;
      }
      *(uint *)(lVar11 + 0x448) =
           *(uint *)(lVar11 + 0x448) | 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f);
      iVar9 = 0;
      if (!bVar5) goto LAB_0032790d;
LAB_00327898:
      *(int *)(lVar11 + 0x430) = (int)local_40[0];
      uVar14 = local_40[0] & 0xffffffff;
      if (cVar1 != '\0') goto LAB_00327c90;
LAB_003278b6:
      uVar7 = (uint)uVar14;
      if (lVar12 != 0) {
LAB_003278bd:
        uVar7 = (uint)uVar14;
        if (*(char *)(lVar12 + 0xad45) != '\0') {
LAB_00327b68:
          iVar9 = memdescMap(*(undefined8 *)(lVar11 + 1000 + uVar16 * 8),0,uVar14,1,3,lVar11 + 0x438
                             ,lVar11 + 0x440);
          goto LAB_003278ff;
        }
      }
      lVar12 = gpumgrGetGpuPhysFbAddr(param_1);
      uVar14 = (ulong)uVar7;
      lVar12 = lVar12 + *(long *)(lVar11 + 0x428);
      uVar10 = 1;
LAB_003278ec:
      iVar9 = osMapPciMemoryKernelOld(param_1,lVar12,uVar14,3,lVar11 + 0x438,uVar10);
    }
    else {
      iVar8 = memdescGetAddressSpace(*(undefined8 *)(lVar11 + 1000 + uVar16 * 8));
      if (iVar8 != 2) {
        iVar8 = memdescGetAddressSpace(*(undefined8 *)(lVar11 + 1000 + uVar16 * 8));
        if (iVar8 != 1) goto LAB_00327a02;
        if (*(char *)(lVar12 + 0xad0e) != '\0') goto LAB_00327a09;
LAB_00327a16:
        nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x278,
                     "kfifoPreAllocUserD_TU102",1,
                     "NVRM: Mapping USERD with coherent link (USERD in SYSMEM).\n");
        lVar15 = *(long *)(lVar11 + 1000 + uVar16 * 8);
        if (!bVar5) goto LAB_00327915;
        uVar10 = memdescGetPhysAddr(lVar15,0,0);
        *(undefined8 *)(lVar11 + 0x428) = uVar10;
        goto LAB_00327898;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x266,
                   "kfifoPreAllocUserD_TU102",1,
                   "NVRM: Mapping USERD with coherent link (USERD in FBMEM).\n");
      if (*(char *)(param_1 + 0x45b) == '\0') {
        nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                            "src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x267);
      }
      lVar15 = *(long *)(lVar11 + 1000 + uVar16 * 8);
      if ((*(byte *)(lVar15 + 9) & 4) == 0) {
        nvAssertFailedNoLog("pUserdInfo->userdPhysDesc[currentGpuInst]->_flags & MEMDESC_FLAGS_PHYSICALLY_CONTIGUOUS"
                            ,"src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x268);
        lVar15 = *(long *)(lVar11 + 1000 + uVar16 * 8);
      }
      if (!bVar5) goto LAB_00327915;
      *(ulong *)(lVar11 + 0x428) = (ulong)*(uint *)(lVar15 + 0x60) + *(long *)(lVar15 + 0x170);
      *(int *)(lVar11 + 0x430) = (int)local_40[0];
LAB_00327c90:
      iVar9 = memdescGetAddressSpace(*(undefined8 *)(lVar11 + 1000 + uVar16 * 8));
      uVar10 = *(undefined8 *)(lVar11 + 1000 + uVar16 * 8);
      if (iVar9 != 2) {
        iVar9 = memdescGetAddressSpace(uVar10);
        uVar14 = (ulong)*(uint *)(lVar11 + 0x430);
        if (iVar9 != 1) goto LAB_003278b6;
        if (*(char *)(lVar12 + 0xad0e) != '\0') goto LAB_003278bd;
        if (*(char *)(lVar12 + 0xad45) != '\0') goto LAB_00327b68;
        lVar12 = *(long *)(lVar11 + 0x428);
        uVar10 = 0;
        goto LAB_003278ec;
      }
      iVar9 = (**(code **)(lVar12 + 0x518))
                        (param_1,lVar12,uVar10,0,*(undefined4 *)(lVar11 + 0x430),3,lVar11 + 0x438,
                         lVar11 + 0x440);
    }
LAB_003278ff:
    if ((*(long *)(lVar11 + 0x438) == 0) && (iVar9 != 0)) {
      nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x2cd,
                   "kfifoPreAllocUserD_TU102",4,"NVRM: Could not cpu map BAR1 snoop range\n");
LAB_00327b12:
      (**(code **)(param_2 + 0x288))(param_1,param_2);
      return iVar9;
    }
  }
  else {
    (**(code **)(lVar15 + 0x388))(param_1,lVar15,lVar4,1,1);
    iVar9 = 0;
    if (bVar5) {
      uVar10 = (**(code **)(param_2 + 0x290))(param_1,param_2);
      *(undefined8 *)(lVar11 + 0x428) = uVar10;
      goto LAB_00327898;
    }
  }
LAB_0032790d:
  lVar15 = *(long *)(lVar11 + 1000 + uVar16 * 8);
LAB_00327915:
  uVar2 = *(undefined4 *)(lVar11 + 0x430);
  uVar10 = *(undefined8 *)(lVar11 + 0x428);
  uVar13 = memdescGetPhysAddr(lVar15,1,0);
  nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x2d3,
               "kfifoPreAllocUserD_TU102",1,
               "NVRM: USERD Preallocated phys @ 0x%llx bar1 offset @ 0x%llx of size 0x%x\n",uVar13,
               uVar10,uVar2);
  return iVar9;
}


// ===== 00327de0 kfifoFreePreAllocUserD_TU102 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoFreePreAllocUserD_TU102(long param_1)

{
  char cVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  
  uVar6 = gpumgrGetParentGPU();
  lVar2 = *(long *)(&DAT_00001b90 + param_1);
  uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  uVar8 = (ulong)uVar4;
  lVar7 = gpuGetKernelFifoShared_IMPL(uVar6);
  if (*(char *)(param_1 + 0x454) == '\0') {
    cVar1 = *(char *)(param_1 + 0x4913);
  }
  else {
    iVar5 = memdescGetAddressSpace(*(undefined8 *)(lVar7 + 1000 + uVar8 * 8));
    cVar1 = *(char *)(param_1 + 0x4913);
    if (iVar5 == 2) {
      if (cVar1 != '\0') {
        return;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x305,
                   "kfifoFreePreAllocUserD_TU102",1,"NVRM: Unmapping USERD from NVLINK.\n");
      if (*(char *)(param_1 + 0x45b) == '\0') {
        nvAssertFailedNoLog("pGpu->getProperty(pGpu, PDB_PROP_GPU_ATS_SUPPORTED)",
                            "src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x306);
        lVar3 = *(long *)(lVar7 + 0x438);
      }
      else {
        lVar3 = *(long *)(lVar7 + 0x438);
      }
      if (lVar3 != 0) {
        (**(code **)(lVar2 + 0x520))
                  (param_1,lVar2,*(undefined8 *)(lVar7 + 1000 + uVar8 * 8),lVar3,
                   *(undefined8 *)(lVar7 + 0x440));
        *(undefined8 *)(lVar7 + 0x438) = 0;
      }
      goto LAB_00327eca;
    }
  }
  if (cVar1 != '\0') {
    return;
  }
  if (*(long *)(lVar7 + 0x438) != 0) {
    if ((lVar2 == 0) || (*(char *)(lVar2 + 0xad45) == '\0')) {
      osUnmapPciMemoryKernelOld(param_1);
    }
    else {
      memdescUnmap(*(undefined8 *)(lVar7 + 1000 + uVar8 * 8),1,*(long *)(lVar7 + 0x438),
                   *(undefined8 *)(lVar7 + 0x440));
    }
    *(undefined8 *)(lVar7 + 0x438) = 0;
  }
  if (((*(int *)(lVar7 + 0x430) != 0) && (*(char *)(param_1 + 0x908) == '\0')) &&
     ((*(uint *)(lVar7 + 0x448) & 1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f)) != 0)) {
    kbusUnmapFbApertureSingle_IMPL
              (param_1,lVar2,*(undefined8 *)(lVar7 + 1000 + uVar8 * 8),
               *(undefined8 *)(lVar7 + 0x428),*(int *)(lVar7 + 0x430),0xa0);
    *(uint *)(lVar7 + 0x448) =
         *(uint *)(lVar7 + 0x448) & ~(1 << ((byte)*(undefined4 *)(param_1 + 0x7a4) & 0x1f));
  }
LAB_00327eca:
  memdescFree(*(undefined8 *)(lVar7 + 1000 + uVar8 * 8));
  memdescDestroy(*(undefined8 *)(lVar7 + 1000 + uVar8 * 8));
  *(undefined8 *)(lVar7 + 1000 + uVar8 * 8) = 0;
  nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x33a,
               "kfifoFreePreAllocUserD_TU102",1,
               "NVRM: Freeing preallocated USERD phys and bar1 range\n");
  return;
}


// ===== 00328030 kfifoGetUserdBar1MapInfo_TU102 =====

undefined8
kfifoGetUserdBar1MapInfo_TU102(long param_1,long param_2,undefined8 *param_3,undefined4 *param_4)

{
  if (*(char *)(param_1 + 0x4913) != '\0') {
    *param_3 = 0;
    *param_4 = 0;
    return 0;
  }
  if (*(int *)(param_2 + 0x430) != 0) {
    *param_3 = *(undefined8 *)(param_2 + 0x428);
    *param_4 = *(undefined4 *)(param_2 + 0x430);
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x356,
               "kfifoGetUserdBar1MapInfo_TU102",4,"NVRM: BAR1 map of USERD has not been setup yet\n"
              );
  nvAssertFailedNoLog(&DAT_00d18a40,"src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x357);
  return 0xffff;
}


// ===== 003280c0 kfifoGetUserdLocation_TU102 =====

undefined8 kfifoGetUserdLocation_TU102(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  if ((param_2 != (undefined4 *)0x0) && (param_3 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(param_1 + 0x3e0);
    *param_3 = *(undefined4 *)(param_1 + 0x3e4);
    return 0;
  }
  nvAssertFailedNoLog("pUserdAperture != NULL && pUserdAttribute != NULL",
                      "src/kernel/gpu/fifo/arch/turing/kernel_fifo_tu102.c",0x374);
  return 0x3d;
}


// ===== 00328110 kchangrpAllocFaultMethodBuffers_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchangrpAllocFaultMethodBuffers_GV100(long param_1,long param_2)

{
  char cVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  int local_64;
  int local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  local_64 = 0;
  lVar6 = gpuGetKernelFifoShared_IMPL();
  uVar2 = *(undefined8 *)(param_1 + 0x1b78);
  uVar4 = (**(code **)(lVar6 + 0x200))(param_1,lVar6,*(code **)(lVar6 + 0x200));
  local_60 = 1;
  local_5c = 0;
  local_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  if ((*(int *)(param_2 + 0x108) == 0) || (*(char *)(param_1 + 0x491e) != '\0')) {
    if (*(char *)(param_1 + 0x908) == '\0') {
      if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_003281c3;
    }
    else if (*(char *)(param_1 + 0x4913) == '\0') {
      return 0;
    }
    if (*(char *)(param_1 + 0x491e) == '\0') {
LAB_003281c3:
      if (*(long *)(param_2 + 0x160) == 0) {
        nvAssertFailedNoLog("(pKernelChannelGroup->pMthdBuffers != NULL)",
                            "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x4a);
        return 0x40;
      }
      cVar1 = *(char *)(param_1 + 0x4ba);
      iVar5 = gpuGetCeFaultMethodBufferSize_KERNEL(param_1,&local_64);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,"gpuGetCeFaultMethodBufferSize(pGpu, &bufSizeInBytes)",
                   "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x4d);
        return iVar5;
      }
      if (local_64 == 0) {
        nvAssertFailedNoLog("(bufSizeInBytes > 0)",
                            "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x4e);
      }
      cVar3 = hypervisorIsVgxHyper_IMPL();
      if ((cVar3 == '\0') || (*(char *)(param_1 + 0x491e) == '\0')) {
        local_60 = 1;
        local_5c = 0;
        memdescOverrideInstLoc
                  (*(uint *)(param_1 + 0x492c) >> 0x1c & 3,"fault method buffer",&local_60,&local_5c
                  );
      }
      else {
        local_60 = 2;
        local_5c = 0;
      }
      if (uVar4 == 0) {
        return 0;
      }
      lVar6 = 0;
LAB_00328277:
      puVar7 = (undefined8 *)(*(long *)(param_2 + 0x160) + lVar6);
      do {
        iVar5 = memdescCreate(puVar7 + 1,param_1,local_64,0,1,local_60,local_5c);
        if (iVar5 != 0) {
LAB_00328318:
          (**(code **)(param_2 + 0xa0))(param_1);
          return iVar5;
        }
        *(undefined4 *)(puVar7[1] + 0x9c) = 0x43;
        iVar5 = memdescAlloc(puVar7[1]);
        if (iVar5 == 0) goto LAB_00328388;
        memdescDestroy();
        puVar7[1] = 0;
        if ((cVar1 == '\0') || (local_60 != 1)) goto LAB_00328318;
        local_60 = 2;
      } while( true );
    }
  }
  return 0;
LAB_00328388:
  memdescSetName(param_1,puVar7[1],"rm_ce_fault_method_buffer_surface",0);
  local_58 = puVar7[1];
  local_50 = 0;
  iVar5 = memmgrMemSet_IMPL(uVar2,&local_58,0,local_64,0);
  if (iVar5 != 0) {
    nvAssertOkFailedNoLog
              (iVar5,"memmgrMemSet(pMemoryManager, &surf, 0, bufSizeInBytes, TRANSFER_FLAGS_NONE)",
               "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x8a);
    return iVar5;
  }
  *puVar7 = 0;
  lVar6 = lVar6 + 0x10;
  if ((ulong)uVar4 << 4 == lVar6) {
    return 0;
  }
  goto LAB_00328277;
}


// ===== 003284a0 kchangrpFreeFaultMethodBuffers_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong kchangrpFreeFaultMethodBuffers_GV100(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = gpuGetKernelFifoShared_IMPL();
  uVar2 = (**(code **)(lVar1 + 0x200))(param_1,lVar1,*(code **)(lVar1 + 0x200));
  if ((*(int *)(param_2 + 0x108) != 0) && (*(char *)(param_1 + 0x491e) == '\0')) {
    return 0;
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_003284f9;
  }
  else if (*(char *)(param_1 + 0x4913) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    return 0;
  }
LAB_003284f9:
  lVar1 = *(long *)(param_2 + 0x160);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("(pKernelChannelGroup->pMthdBuffers != NULL)",
                        "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0xbb);
    return 0x40;
  }
  if ((int)uVar2 != 0) {
    lVar3 = 0;
    while( true ) {
      if (*(long *)(lVar1 + 8) != 0) {
        memdescFree();
        memdescDestroy(*(undefined8 *)(lVar1 + 8));
        *(undefined8 *)(lVar1 + 8) = 0;
      }
      lVar3 = lVar3 + 0x10;
      if ((uVar2 & 0xffffffff) << 4 == lVar3) break;
      lVar1 = *(long *)(param_2 + 0x160) + lVar3;
    }
    return 0;
  }
  return uVar2;
}


// ===== 003285c0 kchangrpMapFaultMethodBuffers_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchangrpMapFaultMethodBuffers_GV100(long param_1,long param_2,uint param_3)

{
  ulong *puVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  
  iVar4 = *(int *)(param_2 + 0x108);
  lVar2 = *(long *)(param_1 + 0x1b78);
  lVar5 = gpuGetKernelFifoShared_IMPL();
  uVar3 = (**(code **)(lVar5 + 0x200))(param_1,lVar5,*(code **)(lVar5 + 0x200));
  if ((iVar4 != 0) && (*(char *)(param_1 + 0x491e) == '\0')) {
    return 0;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_0032863e;
  }
  else if (*(char *)(param_1 + 0x4913) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    return 0;
  }
LAB_0032863e:
  if (*(long *)(param_2 + 0x160) == 0) {
    nvAssertFailedNoLog("(pKernelChannelGroup->pMthdBuffers != NULL)",
                        "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0xf0);
  }
  else {
    if (param_3 < uVar3) {
      puVar1 = (ulong *)(*(long *)(param_2 + 0x160) + (ulong)param_3 * 0x10);
      if ((puVar1[1] != 0) && (*puVar1 == 0)) {
        lVar5 = *(long *)(&DAT_00001b90 + param_1);
        (**(code **)(lVar2 + 0x388))(param_1,lVar2,puVar1[1],1,1);
        iVar4 = (**(code **)(lVar5 + 0x218))
                          (param_1,lVar5,puVar1[1],puVar1,*(undefined8 *)(puVar1[1] + 0x30),0,iVar4)
        ;
        if (iVar4 != 0) {
          nvAssertOkFailedNoLog
                    (iVar4,
                     "kbusMapCpuInvisibleBar2Aperture_HAL(pGpu, pKernelBus, pFaultMthdBuf->pMemDesc, &(pFaultMthdBuf->bar2Addr), pFaultMthdBuf->pMemDesc->Size, 0, gfid)"
                     ,"src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x100);
          return iVar4;
        }
        nvDbg_Printf("src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x107,
                     "kchangrpMapFaultMethodBuffers_GV100",1,
                     "NVRM: Allocating Method buffer with Bar2Addr LO 0x%08x Bar2Addr HI 0x%08x runqueue 0x%0x\n"
                     ,*puVar1,*puVar1 >> 0x20,param_3);
        return 0;
      }
      return 0;
    }
    nvAssertFailedNoLog("(runqueue < runQueues)",
                        "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0xf1);
  }
  return 0x40;
}


// ===== 003287b0 kchangrpUnmapFaultMethodBuffers_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchangrpUnmapFaultMethodBuffers_GV100(long param_1,long param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  long *plVar5;
  
  iVar1 = *(int *)(param_2 + 0x108);
  lVar2 = *(long *)(&DAT_00001b90 + param_1);
  lVar4 = gpuGetKernelFifoShared_IMPL();
  uVar3 = (**(code **)(lVar4 + 0x200))(param_1,lVar4,*(code **)(lVar4 + 0x200));
  if ((iVar1 != 0) && (*(char *)(param_1 + 0x491e) == '\0')) {
    return 0;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x4913) == '\0') goto LAB_00328820;
  }
  else if (*(char *)(param_1 + 0x4913) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x491e) != '\0') {
    return 0;
  }
LAB_00328820:
  if (*(long *)(param_2 + 0x160) == 0) {
    nvAssertFailedNoLog("(pKernelChannelGroup->pMthdBuffers != NULL)",
                        "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x132);
    return 0x1f;
  }
  if (param_3 < uVar3) {
    plVar5 = (long *)((ulong)param_3 * 0x10 + *(long *)(param_2 + 0x160));
    if (plVar5[1] != 0) {
      if (*plVar5 != 0) {
        (**(code **)(lVar2 + 0x220))(param_1,lVar2,plVar5[1],*plVar5,iVar1);
        *plVar5 = 0;
      }
      return 0;
    }
    nvAssertFailedNoLog("(pFaultMthdBuf->pMemDesc != NULL)",
                        "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x13a);
  }
  else {
    nvAssertFailedNoLog("(runqueue < runQueues)",
                        "src/kernel/gpu/fifo/arch/volta/kernel_channel_group_gv100.c",0x133);
  }
  return 0x40;
}


// ===== 00328920 kchannelIsUserdAddrSizeValid_GV100 =====

uint kchannelIsUserdAddrSizeValid_GV100(undefined8 param_1,uint param_2,uint param_3)

{
  undefined8 in_RAX;
  
  return (uint)CONCAT71((int7)((ulong)in_RAX >> 8),param_2 < 0x800000) &
         CONCAT31((int3)(param_3 >> 8),param_3 < 0x100);
}


// ===== 00328940 kchannelCreateUserdMemDescBc_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Function: __x86_indirect_thunk_rdx replaced with injection: x86_indirect_thunk_rdx */

ulong kchannelCreateUserdMemDescBc_GV100
                (undefined8 param_1,long param_2,undefined8 param_3,int *param_4)

{
  ulong uVar1;
  undefined8 uStack_20;
  
  if (*param_4 == 0) {
    return 0;
  }
  uVar1 = (**(code **)(param_2 + 0x1c8))();
  if ((int)uVar1 != 0) {
    (**(code **)(param_2 + 0x1d0))(param_1,param_2,*(code **)(param_2 + 0x1d0),uStack_20);
    return uVar1 & 0xffffffff;
  }
  *(undefined1 *)(param_2 + 0x398) = 1;
  return uVar1;
}


// ===== 003289b0 kchannelCreateUserdMemDesc_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelCreateUserdMemDesc_GV100
              (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5,
              ulong *param_6,uint *param_7)

{
  ulong uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined4 local_50;
  byte local_4c [4];
  long local_48;
  undefined8 local_40 [2];
  
  lVar6 = gpuGetKernelFifoShared_IMPL();
  local_40[0] = 0;
  local_50 = 0;
  uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  *(undefined8 *)(param_2 + 0x358 + (ulong)uVar4 * 8) = 0;
  (**(code **)(lVar6 + 0x2a0))(lVar6,&local_50,local_4c);
  bVar3 = local_4c[0];
  iVar5 = serverutilGetResourceRefWithType(param_3,param_4,0x4789f2,&local_48);
  if (iVar5 == 0) {
    iVar5 = 0x29;
    lVar6 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_Memory);
    uVar7 = memdescGetMemDescFromGpu(*(undefined8 *)(lVar6 + 0x118),param_1);
    cVar2 = memdescGetFlag(uVar7,0x80);
    if (cVar2 == '\0') {
      uVar8 = memdescGetPhysAddr(uVar7,1,param_5);
      uVar4 = (uint)uVar8 >> (local_4c[0] & 0x1f);
      cVar2 = (**(code **)(param_2 + 0x1e0))(param_2,uVar4,uVar8 >> 0x20);
      if (cVar2 == '\0') {
        nvDbg_Printf("src/kernel/gpu/fifo/arch/volta/kernel_channel_gv100.c",0xd6,
                     "kchannelCreateUserdMemDesc_GV100",4,
                     "NVRM: physical addr size of userdAddrHi=0x%08x, userAddrLo=0x%08x is incorrect!\n"
                     ,uVar8 >> 0x20,uVar4);
        nvAssertFailedNoLog(&DAT_00d19841,"src/kernel/gpu/fifo/arch/volta/kernel_channel_gv100.c",
                            0xda);
      }
      else {
        uVar9 = memdescGetPageSize(uVar7,1);
        memdescSetPageSize(uVar7,1,0x1000);
        iVar5 = memdescCreateSubMem(local_40,uVar7,param_1,param_5,local_50);
        memdescSetPageSize(uVar7,1,uVar9);
        if (iVar5 != 0) {
          return iVar5;
        }
        lVar10 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_OsDescMemory);
        if (lVar10 != 0) {
          refAddDependant(local_48,*(undefined8 *)(*(long *)(param_2 + 0x140) + 0x48));
        }
        uVar1 = *(ulong *)(*(long *)(lVar6 + 0x118) + 0x28);
        if (((1L << (bVar3 & 0x3f) & 0xffffffffU) <= uVar1) || (uVar1 == 0)) {
          uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
          *(undefined8 *)(param_2 + 0x358 + (ulong)uVar4 * 8) = local_40[0];
          if (param_6 != (ulong *)0x0) {
            *param_6 = uVar8;
          }
          if (param_7 == (uint *)0x0) {
            return 0;
          }
          bVar3 = kgmmuGetHwPteApertureFromMemdesc_GM107(*(undefined8 *)(param_1 + 0x1b98),uVar7);
          *param_7 = (uint)bVar3;
          return 0;
        }
        memdescDestroy(local_40[0]);
      }
      iVar5 = 0x1e;
    }
  }
  else {
    if (local_48 == 0) {
      nvAssertFailedNoLog("pUserdMemoryRef","src/kernel/gpu/fifo/arch/volta/kernel_channel_gv100.c",
                          0xbd);
    }
    iVar5 = 0x57;
  }
  return iVar5;
}


// ===== 00328c70 kchannelDestroyUserdMemDesc_GV100 =====

void kchannelDestroyUserdMemDesc_GV100(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu();
  memdescDestroy(*(undefined8 *)(param_2 + 8 + ((ulong)uVar1 + 0x6a) * 8));
  *(undefined8 *)(param_2 + 8 + ((ulong)uVar1 + 0x6a) * 8) = 0;
  return;
}


// ===== 00328cb0 kfifoChannelGroupGetDefaultTimeslice_GV100 =====

undefined8 kfifoChannelGroupGetDefaultTimeslice_GV100(void)

{
  return 0x400;
}


// ===== 00328cc0 kfifoRmctrlGetWorkSubmitToken_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoRmctrlGetWorkSubmitToken_GV100
              (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  
  lVar2 = rmapiGetInterface(4);
  portMemSet(&local_2c,0,4);
  if (param_4 == (undefined4 *)0x0) {
    iVar1 = 0x1f;
    nvDbg_Printf("src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x52,
                 "kfifoRmctrlGetWorkSubmitToken_GV100",3,"NVRM: FAILED to get work submit token.\n")
    ;
  }
  else {
    iVar1 = (**(code **)(lVar2 + 0x38))(lVar2,param_2,param_3,0xc36f0108,&local_2c,4);
    if (iVar1 != 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x5b,
                   "kfifoRmctrlGetWorkSubmitToken_GV100",3,
                   "NVRM: Unable to get work submit token.\n");
      return iVar1;
    }
    *param_4 = local_2c;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== 00328db0 kfifoEngineInfoXlate_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoEngineInfoXlate_GV100
                (undefined8 param_1,long param_2,int param_3,uint param_4,undefined4 param_5,
                undefined8 param_6)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  uint local_2c [3];
  
  if (param_3 == 4) {
    iVar1 = (**(code **)(param_2 + 0x1e8))(param_1,param_2,0);
    uVar2 = kfifoEngineInfoXlate_GM107(param_1,param_2,0,0xd334df00,4,local_2c);
    if (uVar2 != 0) {
      nvAssertOkFailedNoLog
                (uVar2,
                 "kfifoEngineInfoXlate_GM107(pGpu, pKernelFifo, ENGINE_INFO_TYPE_ENG_DESC, ENG_GR(0), ENGINE_INFO_TYPE_MMU_FAULT_ID, &grFaultId)"
                 ,"src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x76);
      return (ulong)uVar2;
    }
    if ((local_2c[0] <= param_4) && (param_4 < iVar1 + local_2c[0])) {
      param_4 = local_2c[0];
    }
  }
  uVar3 = kfifoEngineInfoXlate_GM107(param_1,param_2,param_3,param_4,param_5,param_6);
  return uVar3;
}


// ===== 00328ea0 kfifoGetMaxChannelGroupSize_GV100 =====

undefined8 kfifoGetMaxChannelGroupSize_GV100(void)

{
  return 0x80;
}


// ===== 00328eb0 kfifoGetUsermodeMapInfo_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoGetUsermodeMapInfo_GV100
                (long param_1,undefined8 param_2,ulong *param_3,undefined4 *param_4)

{
  ulong uVar1;
  uint local_1c;
  
  uVar1 = (**(code **)(param_1 + 0x200))(param_1,4,&local_1c);
  if ((int)uVar1 == 0) {
    if (param_3 != (ulong *)0x0) {
      *param_3 = (ulong)local_1c;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0x10000;
    }
    return uVar1;
  }
  nvAssertOkFailedNoLog
            (uVar1 & 0xffffffff,"gpuGetRegBaseOffset_HAL(pGpu, NV_REG_BASE_USERMODE, &offset)",
             "src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0xa5);
  return uVar1 & 0xffffffff;
}


// ===== 00328f30 kfifoGetMaxSubcontext_GV100 =====

uint kfifoGetMaxSubcontext_GV100(long param_1,long param_2,char param_3)

{
  uint uVar1;
  
  if (((param_3 == '\0') && (*(char *)(param_2 + 0x4b3) != '\0')) && (param_1 != 0)) {
    if (*(uint *)(param_2 + 0x450) != 0) {
      return *(uint *)(param_2 + 0x450);
    }
    uVar1 = kfifoGetMaxSubcontextFromGr_KERNEL();
    if (uVar1 < 0x60) {
      *(uint *)(param_2 + 0x450) = uVar1;
    }
    else {
      nvAssertFailedNoLog("maxVeid / 32 <= SUBCTX_MASK_ARRAY_SIZE",
                          "src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0xcb);
      uVar1 = 0;
    }
    return uVar1;
  }
  return 2;
}


// ===== 00328fb0 kfifoGetSubctxType_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoGetSubctxType_GV100(undefined8 param_1,undefined8 param_2,long param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  
  if (param_3 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL",
                        "src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0xe7);
    return;
  }
  iVar1 = *(int *)(param_3 + 0x40c);
  if (iVar1 == -1) {
    nvAssertFailedNoLog("pKernelChannel->subctxId != FIFO_PDB_IDX_BASE",
                        "src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0xf0);
    iVar1 = *(int *)(param_3 + 0x40c);
  }
  lVar4 = *(long *)(*(long *)(*(long *)(param_3 + 0x2b8) + 0x138) + 0x110);
  lVar4 = (**(code **)(lVar4 + 0x40))(lVar4,iVar1,0);
  if (lVar4 != 0) {
    uVar2 = *(uint *)(*(long *)(lVar4 + 0x80) + 0xb0);
    uVar3 = uVar2 & 3;
    if ((uVar2 & 2) != 0) {
      uVar3 = 1;
    }
    if (param_4 != (uint *)0x0) {
      *param_4 = uVar3;
    }
    return;
  }
  nvDbg_Printf("src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0xfa,"kfifoGetSubctxType_GV100",
               4,"NVRM: subcontext not allocated for this TSG\n");
  nvAssertFailedNoLog("pBlock","src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0xfb);
  return;
}


// ===== 003290c0 kfifoRunlistGetEntrySize_GV100 =====

undefined8 kfifoRunlistGetEntrySize_GV100(void)

{
  return 0x10;
}


// ===== 003290d0 kfifoCalcTotalSizeOfFaultMethodBuffers_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoCalcTotalSizeOfFaultMethodBuffers_GV100(long param_1,long param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_2c;
  
  local_2c = 0;
  if ((*(char *)(param_1 + 0x908) == '\0') || (iVar3 = 0, *(char *)(param_1 + 0x4913) != '\0')) {
    iVar3 = (**(code **)(param_2 + 0x2b8))();
    iVar1 = (**(code **)(param_2 + 0x200))(param_1,param_2);
    iVar2 = gpuGetCeFaultMethodBufferSize_KERNEL(param_1,&local_2c);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,"gpuGetCeFaultMethodBufferSize(pGpu, &totalSize)",
                 "src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x139);
    }
    iVar3 = iVar1 * iVar3 * local_2c;
    if (param_3 == '\0') {
      return iVar3;
    }
    if ((~*(uint *)(param_1 + 0x492c) & 0x30000000) != 0) {
      iVar3 = 0;
    }
  }
  return iVar3;
}


// ===== 003291c0 kfifoGetMaxCeChannelGroups_GV100 =====

ulong kfifoGetMaxCeChannelGroups_GV100(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,0);
  if (*(char *)(param_2 + 0x4bc) != '\0') {
    uVar1 = (uint)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if (*(uint *)(param_2 + 0x4c0) < uVar1) {
      uVar2 = (ulong)*(uint *)(param_2 + 0x4c0);
    }
  }
  return uVar2;
}


// ===== 00329200 kfifoConstructUsermodeMemdescs_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoConstructUsermodeMemdescs_GV100(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined4 local_24;
  undefined8 local_20;
  
  local_20 = 0;
  local_24 = 0;
  iVar1 = (**(code **)(param_2 + 0x1e0))(param_1,param_2,&local_20,&local_24);
  if (iVar1 == 0) {
    iVar1 = memCreateMemDesc_IMPL(param_1,param_2 + 0x4f0,3,local_20,local_24,0x30000000,8);
    if (iVar1 == 0) {
      memdescSetFlag(*(undefined8 *)(param_2 + 0x4f0),0x2000000000,1);
    }
    else {
      nvAssertOkFailedNoLog
                (iVar1,
                 "memCreateMemDesc(pGpu, &(pKernelFifo->pRegVF), ADDR_REGMEM, offset, size, attr, attr2)"
                 ,"src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x173);
    }
    return iVar1;
  }
  nvAssertOkFailedNoLog
            (iVar1,"kfifoGetUsermodeMapInfo_HAL(pGpu, pKernelFifo, &offset, &size)",
             "src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x171);
  return iVar1;
}


// ===== 003292f0 kfifoGetFaultAccessTypeString_GV100 =====

char * kfifoGetFaultAccessTypeString_GV100(undefined8 param_1,undefined8 param_2,uint param_3)

{
  char *pcVar1;
  
  pcVar1 = "UNRECOGNIZED_ACCESS_TYPE";
  if (param_3 < 0xc) {
    pcVar1 = *(char **)(CSWTCH_28 + (ulong)param_3 * 8);
  }
  return pcVar1;
}


// ===== 00329310 kfifoRingChannelDoorBell_GV100 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoRingChannelDoorBell_GV100(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined4 local_c;
  
  uVar1 = kfifoGenerateWorkSubmitToken_IMPL();
  if (uVar1 != 0) {
    nvAssertOkFailedNoLog
              (uVar1,
               "kfifoGenerateWorkSubmitToken(pGpu, pKernelFifo, pKernelChannel, &workSubmitToken, NV_TRUE)"
               ,"src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x1b5);
    return (ulong)uVar1;
  }
  uVar2 = (**(code **)(param_2 + 0x238))(param_1,param_2,local_c);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,
             "kfifoUpdateUsermodeDoorbell_HAL(pGpu, pKernelFifo, workSubmitToken)",
             "src/kernel/gpu/fifo/arch/volta/kernel_fifo_gv100.c",0x1b8);
  return uVar2 & 0xffffffff;
}


// ===== 003293b0 chandesConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int chandesConstruct_IMPL(long param_1,long param_2,long param_3,code *param_4)

{
  long lVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong *puVar8;
  uint uVar9;
  bool bVar10;
  byte bVar11;
  uint local_d4;
  ulong *local_d0;
  ulong local_c8;
  undefined4 local_c0;
  int local_bc;
  undefined4 local_b8;
  
  bVar11 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar6 = *(long *)(*(long *)(param_2 + 0x10) + 0x18);
  lVar5 = gpuGetKernelFifoShared_IMPL(lVar1);
  if ((lVar1 == 0) || (*(long *)(lVar1 + 0x1bc0) == 0)) {
    bVar10 = false;
    lVar6 = *(long *)(lVar6 + 8);
  }
  else {
    cVar2 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    lVar6 = *(long *)(lVar6 + 8);
    bVar10 = cVar2 != '\0';
  }
  if (lVar6 == 0) {
    return 0x36;
  }
  lVar6 = __nvoc_dynamicCast(lVar6,__nvoc_class_def_KernelChannel);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/channel_descendant.c",0x3d);
    return 0x36;
  }
  if ((*(char *)(lVar1 + 0x908) == '\0') &&
     (cVar2 = gpuIsGpuFullPowerForPmResume_IMPL(lVar1), cVar2 == '\0')) {
    nvAssertFailedNoLog("IS_VIRTUAL(pGpu) || gpuIsGpuFullPowerForPmResume(pGpu)",
                        "src/kernel/gpu/fifo/channel_descendant.c",0x40);
  }
  cVar2 = rmapiLockIsOwner();
  if ((cVar2 == '\0') && (cVar2 = rmapiInRtd3PmPath(), cVar2 == '\0')) {
    nvAssertFailedNoLog("rmapiLockIsOwner() || rmapiInRtd3PmPath()",
                        "src/kernel/gpu/fifo/channel_descendant.c",0x42);
  }
  cVar2 = (**(code **)(lVar1 + 0x2d8))(lVar1);
  if (cVar2 != '\0') {
    return 3;
  }
  local_d0 = (ulong *)0x0;
  if (*(char *)(lVar5 + 0x4b0) == '\0') {
    if ((*(char *)(lVar5 + 0x4b2) == '\0') || (0x52 < *(int *)(lVar6 + 0x42c) - 1U))
    goto LAB_003294de;
LAB_00329602:
    cVar2 = gpuIsCCorApmFeatureEnabled_IMPL(lVar1);
    if ((cVar2 == '\0') && ((!bVar10 && (*(char *)(lVar5 + 0x4b0) == '\0')))) goto LAB_003294de;
    cVar2 = rmapiutilIsExternalClassIdInternalOnly(*(undefined4 *)(param_3 + 0xc));
    if (cVar2 != '\0') {
      iVar3 = (**(code **)(lVar5 + 0x218))(lVar1,lVar5,2,*(undefined4 *)(lVar6 + 0x42c),0,&local_d4)
      ;
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)kchannelGetEngineType(pKernelChannel), ENGINE_INFO_TYPE_ENG_DESC, &engDesc)"
                   ,"src/kernel/gpu/fifo/channel_descendant.c",0x73);
        return iVar3;
      }
      portMemSet(&local_c8,0,8);
      goto LAB_0032973a;
    }
    iVar3 = gpuGetClassByClassId_IMPL(lVar1,*(undefined4 *)(param_3 + 0xc),&local_d0);
    if (iVar3 != 0) {
      iVar3 = *(int *)(lVar6 + 0x42c);
LAB_003298b6:
      iVar3 = (**(code **)(lVar5 + 0x218))(lVar1,lVar5,2,iVar3,0,&local_c8);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)rmEngineType, ENGINE_INFO_TYPE_ENG_DESC, &engDesc)"
                   ,"src/kernel/gpu/fifo/channel_descendant.c",0x94);
        return iVar3;
      }
      iVar3 = gpuGetClassByEngineAndClassId_IMPL
                        (lVar1,*(undefined4 *)(param_3 + 0xc),local_c8 & 0xffffffff,&local_d0);
      goto LAB_00329547;
    }
    uVar9 = *(uint *)((long)local_d0 + 4);
    if (uVar9 != 0x95a6f500) {
      iVar3 = *(int *)(lVar6 + 0x42c);
      if ((uVar9 >> 8 == 0x793ceb) && (iVar3 - 1U < 8)) {
        puVar8 = &local_c8;
        for (lVar7 = 0x24; lVar7 != 0; lVar7 = lVar7 + -1) {
          *(undefined4 *)puVar8 = 0;
          puVar8 = (ulong *)((long)puVar8 + (ulong)bVar11 * -8 + 4);
        }
        uVar4 = gpuGetNv2080EngineType_IMPL(iVar3);
        local_c8 = CONCAT44(local_c8._4_4_,uVar4);
        local_c0 = *(undefined4 *)(lVar6 + 0x428);
        iVar3 = (**(code **)(lVar5 + 0x268))(lVar1,lVar5,&local_c8);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,"kfifoGetEnginePartnerList_HAL(pGpu, pKernelFifo, &partnerParams)",
                     "src/kernel/gpu/fifo/channel_descendant.c",0x8e);
          return iVar3;
        }
        if (local_bc != 1) {
          nvAssertFailedNoLog("partnerParams.numPartners == 1",
                              "src/kernel/gpu/fifo/channel_descendant.c",0x8f);
          return 0x40;
        }
        iVar3 = gpuGetRmEngineType_IMPL(local_b8);
      }
      goto LAB_003298b6;
    }
  }
  else {
    if (0x52 < *(int *)(lVar6 + 0x42c) - 1U) {
      nvDbg_Printf("src/kernel/gpu/fifo/channel_descendant.c",0x59,"chandesConstruct_IMPL",4,
                   "NVRM: Channel should have engineType associated with it\n");
      return 0x36;
    }
    if (*(char *)(lVar5 + 0x4b2) != '\0') goto LAB_00329602;
LAB_003294de:
    if ((param_4 == (code *)0x0) || (*(long *)(param_3 + 0x40) == 0)) {
      iVar3 = gpuGetClassByClassId_IMPL(lVar1,*(undefined4 *)(param_3 + 0xc),&local_d0);
LAB_00329547:
      if (iVar3 != 0) {
LAB_003297f0:
        nvDbg_Printf("src/kernel/gpu/fifo/channel_descendant.c",199,"chandesConstruct_IMPL",4,
                     "NVRM: bad class 0x%x\n",*(undefined4 *)(param_3 + 0xc));
        return 0x22;
      }
      uVar9 = *(uint *)((long)local_d0 + 4);
    }
    else {
      uVar9 = (*param_4)(lVar1);
      cVar2 = rmapiutilIsExternalClassIdInternalOnly(*(undefined4 *)(param_3 + 0xc));
      if (cVar2 == '\0') {
        if (uVar9 == 0xb33b1500) goto LAB_003297f0;
        iVar3 = gpuGetClassByEngineAndClassId_IMPL
                          (lVar1,*(undefined4 *)(param_3 + 0xc),uVar9,&local_d0);
        goto LAB_00329547;
      }
      portMemSet(&local_c8,0,8);
      local_d4 = uVar9;
LAB_0032973a:
      local_d0 = &local_c8;
      local_c8 = CONCAT44(local_d4,*(undefined4 *)(param_3 + 0xc));
      uVar9 = local_d4;
    }
    if (uVar9 >> 8 == 0xd334df) {
      uVar9 = uVar9 & 0xff | 0xea3fa900;
    }
    else if (uVar9 >> 8 == 0x793ceb) goto LAB_00329596;
  }
  lVar7 = gpuGetEngstate_IMPL(lVar1,uVar9);
  if ((lVar7 == 0) && (lVar7 = kflcnGetKernelFalconForEngine_IMPL(lVar1,uVar9), lVar7 == 0)) {
    nvDbg_Printf("src/kernel/gpu/fifo/channel_descendant.c",0xe7,"chandesConstruct_IMPL",4,
                 "NVRM: engine is missing for class 0x%x\n",*(undefined4 *)(param_3 + 0xc));
    return 0x22;
  }
LAB_00329596:
  *(long *)(param_1 + 0x178) = lVar6;
  *(int *)(param_1 + 0x180) = (int)*local_d0;
  *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)((long)local_d0 + 4);
  iVar3 = (**(code **)(lVar5 + 0x308))(lVar1,lVar5,lVar6);
  if (iVar3 == 0) {
    iVar3 = kchannelRegisterChild_IMPL(lVar6,param_1);
    return iVar3;
  }
  nvDbg_Printf("src/kernel/gpu/fifo/channel_descendant.c",0xf7,"chandesConstruct_IMPL",4,
               "NVRM: Invalid object allocation request on channel 0x%08x\n",
               *(int *)(lVar6 + 0x2b0) << 0x18 | *(uint *)(lVar6 + 0x2b4));
  return iVar3;
}


// ===== 00329a4a chandesDestruct_IMPL.cold =====

void chandesDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00329a60 chandesDestruct_IMPL =====

void chandesDestruct_IMPL(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  CliDelObjectEvents(*(undefined8 *)(*(long *)(param_1 + 0x140) + 0x48));
  iVar2 = kchannelDeregisterChild_IMPL(*(undefined8 *)(param_1 + 0x178));
  if (iVar2 == 0) {
    return;
  }
  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/channel_descendant.c",0x114);
  return;
}


// ===== 00329ac0 chandesGetSwMethods_IMPL =====

undefined8 chandesGetSwMethods_IMPL(void)

{
  return 0x56;
}


// ===== 00329ad0 mthdNoOperation =====

undefined8 mthdNoOperation(undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  nvDbg_Printf("src/kernel/gpu/fifo/channel_descendant.c",0x134,"mthdNoOperation",1,
               "NVRM: Method NoOperation: Class=0x%x Data=0x%x\n",*(undefined4 *)(param_2 + 0x180),
               param_4);
  return 0;
}


// ===== 00329b10 chandesIsSwMethodStalling_IMPL =====

undefined8 chandesIsSwMethodStalling_IMPL(void)

{
  return 1;
}


// ===== 00329b20 chandesCheckMemInterUnmap_IMPL =====

undefined8 chandesCheckMemInterUnmap_IMPL(undefined8 param_1,char param_2)

{
  if (param_2 == '\0') {
    return 0;
  }
  nvDbg_Printf("src/kernel/gpu/fifo/channel_descendant.c",0x14b,"chandesCheckMemInterUnmap_IMPL",4,
               "NVRM: Unicast DMA mappings of non-memory objects not supported.\n");
  return 0x56;
}


// ===== 00329b60 _kchannelSendChannelAllocRpc =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int _kchannelSendChannelAllocRpc(long param_1,undefined4 *param_2,long param_3,char param_4)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long lVar10;
  long lVar11;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  puVar7 = (undefined4 *)portMemAllocNonPaged(0x170);
  if (puVar7 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pRpcParams != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x9fd);
    return 0x51;
  }
  portMemSet(puVar7,0,0x170);
  uVar4 = *param_2;
  puVar7[1] = 0;
  *puVar7 = uVar4;
  *(undefined8 *)(puVar7 + 2) = *(undefined8 *)(param_2 + 2);
  puVar7[4] = param_2[4];
  puVar7[5] = param_2[5];
  puVar7[6] = param_2[6];
  puVar7[7] = param_2[7];
  puVar7[0x20] = param_2[0x20];
  puVar7[0x22] = param_2[0x22];
  puVar7[0x23] = param_2[0x23];
  puVar7[0x3c] = param_2[0x3c];
  puVar7[0x3d] = param_2[0x3d];
  portMemCopy(puVar7 + 8,0x20,param_2 + 8,0x20);
  portMemCopy(puVar7 + 0x10,0x40,param_2 + 0x10,0x40);
  if (*(char *)(param_1 + 0x4f8) != '\0') {
    portMemCopy(puVar7 + 0x4c,0xc,param_2 + 0x4c,0xc);
    portMemCopy(puVar7 + 0x4f,0xc,param_2 + 0x4f,0xc);
    portMemCopy(puVar7 + 0x52,0x20,param_2 + 0x52,0x20);
  }
  if (param_4 != '\0' || *(char *)(lVar1 + 0x909) != '\0') {
    uVar3 = gpumgrGetSubDeviceInstanceFromGpu(lVar1);
    lVar10 = param_1 + (ulong)uVar3 * 8;
    plVar2 = *(long **)(lVar10 + 0x2d8);
    if (plVar2 == (long *)0x0) {
      nvAssertOkFailedNoLog
                (0x40,"pInstanceBlock != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xa33);
      iVar6 = 0x40;
      goto LAB_00329fac;
    }
    uVar3 = param_2[5];
    portMemCopy(puVar7 + 0x3e,0x18,param_2 + 0x3e,0x18);
    portMemCopy(puVar7 + 0x44,0x18,param_2 + 0x44,0x18);
    uVar8 = memdescGetPhysAddr(*plVar2,1,0);
    *(undefined8 *)(puVar7 + 0x24) = uVar8;
    *(undefined8 *)(puVar7 + 0x26) = *(undefined8 *)(*plVar2 + 0x30);
    uVar4 = memdescGetAddressSpace(*plVar2);
    puVar7[0x28] = uVar4;
    puVar7[0x29] = *(undefined4 *)(*plVar2 + 0x74);
    uVar8 = memdescGetPhysAddr(plVar2[1],1,0);
    *(undefined8 *)(puVar7 + 0x30) = uVar8;
    *(undefined8 *)(puVar7 + 0x32) = *(undefined8 *)(plVar2[1] + 0x30);
    uVar4 = memdescGetAddressSpace(plVar2[1]);
    puVar7[0x34] = uVar4;
    puVar7[0x35] = *(undefined4 *)(plVar2[1] + 0x74);
    if (*(long *)(lVar10 + 0x358) != 0) {
      uVar8 = memdescGetPhysAddr(*(long *)(lVar10 + 0x358),1,0);
      *(undefined8 *)(puVar7 + 0x2a) = uVar8;
      *(undefined8 *)(puVar7 + 0x2c) = *(undefined8 *)(*(long *)(lVar10 + 0x358) + 0x30);
      uVar4 = memdescGetAddressSpace(*(undefined8 *)(lVar10 + 0x358));
      puVar7[0x2e] = uVar4;
      puVar7[0x2f] = *(undefined4 *)(*(long *)(lVar10 + 0x358) + 0x74);
    }
    if (*(long *)(param_3 + 0x160) != 0) {
      lVar11 = (ulong)(uVar3 >> 4 & 1) * 0x10;
      puVar9 = (undefined8 *)(*(long *)(param_3 + 0x160) + lVar11);
      lVar10 = puVar9[1];
      if (lVar10 != 0) {
        if (param_4 == '\0') {
          uVar8 = memdescGetPhysAddr(lVar10,1,0);
          *(undefined8 *)(puVar7 + 0x36) = uVar8;
          *(undefined8 *)(puVar7 + 0x38) =
               *(undefined8 *)(*(long *)(*(long *)(param_3 + 0x160) + 8 + lVar11) + 0x30);
          uVar4 = memdescGetAddressSpace(*(undefined8 *)(*(long *)(param_3 + 0x160) + 8 + lVar11));
          puVar7[0x3a] = uVar4;
          puVar7[0x3b] = *(undefined4 *)(*(long *)(*(long *)(param_3 + 0x160) + 8 + lVar11) + 0x74);
        }
        else {
          *(undefined8 *)(puVar7 + 0x36) = *puVar9;
          uVar8 = *(undefined8 *)(*(long *)(*(long *)(param_3 + 0x160) + 8 + lVar11) + 0x30);
          *(undefined8 *)(puVar7 + 0x3a) = 4;
          *(undefined8 *)(puVar7 + 0x38) = uVar8;
        }
      }
    }
    if (*(char *)(lVar1 + 0x909) != '\0') {
      uVar3 = puVar7[5];
      puVar7[5] = uVar3 & 0xfffff7ff | 0x200000;
      uVar5 = (*(uint *)(param_1 + 0x2b4) & 7) << 8;
      puVar7[5] = uVar5 | uVar3 & 0xfffff0ff | 0x200000;
      puVar7[5] = uVar5 | uVar3 & 0xffe000ff | (*(uint *)(param_1 + 0x2b4) & 0xff8) << 9 | 0x200000;
      uVar3 = puVar7[0x3d];
      uVar5 = uVar3 & 0xfffffffc | *(byte *)(param_1 + 0x2ac) & 3;
      puVar7[0x3d] = uVar5;
      if (*(char *)(param_1 + 0x2d5) != '\0') {
        puVar7[0x3d] = CONCAT31((int3)((uVar3 & 0xfffffffc) >> 8),(char)uVar5) | 0x80;
      }
      puVar7[0x4a] = *(undefined4 *)(param_1 + 0x3e4);
      puVar7[0x4b] = *(undefined4 *)(param_1 + 1000);
    }
  }
  lVar10 = gpuGetRpc(lVar1);
  if (lVar10 == 0) {
    iVar6 = 0x1a;
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xa9d);
  }
  else {
    plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
    if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
      iVar6 = (**(code **)(lVar10 + 0xc0))
                        (lVar1,lVar10,*(undefined4 *)(*plVar2 + 0x48),
                         *(undefined4 *)(plVar2[3] + 0x10),(int)plVar2[2],
                         *(undefined4 *)((long)plVar2 + 0x11c),puVar7,param_1 + 0x2b4);
    }
    else {
      iVar6 = (**(code **)(lVar1 + 0x3b60))(lVar1 + 0x3b58,*(undefined4 *)(*plVar2 + 0x48));
    }
    if (iVar6 == 0) {
      plVar2 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xaa7,"_kchannelSendChannelAllocRpc",1,
                   "NVRM: Alloc Channel chid %d, hClient:0x%x, hParent:0x%x, hObject:0x%x, hClass:0x%x\n"
                   ,*(undefined4 *)(param_1 + 0x2b4),*(undefined4 *)(*plVar2 + 0x48),
                   *(undefined4 *)(plVar2[3] + 0x10),(int)plVar2[2],
                   *(undefined4 *)((long)plVar2 + 0x11c));
      goto LAB_00329fac;
    }
  }
  nvAssertOkFailedNoLog(iVar6,"status","src/kernel/gpu/fifo/kernel_channel.c",0xaa5);
LAB_00329fac:
  portMemFree(puVar7);
  return iVar6;
}


// ===== 0032a190 _kchannelFreeHalData =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void _kchannelFreeHalData(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  (**(code **)(param_2 + 0x198))();
  (**(code **)(param_2 + 0x1d0))(param_1,param_2);
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  portMemFree(*(undefined8 *)(param_2 + 0x2d8 + (ulong)uVar1 * 8));
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  *(undefined8 *)(param_2 + 0x2d8 + (ulong)uVar1 * 8) = 0;
  return;
}


// ===== 0032a1ed kchannelDestruct_IMPL.cold =====

void kchannelDestruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0032a200 kchannelDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */

void kchannelDestruct_IMPL(long param_1)

{
  byte bVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  char local_55;
  undefined4 local_54;
  long local_50;
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 uStack_3c;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(long *)(param_1 + 0x2b8) == 0) {
    nvAssertFailedNoLog("pKernelChannel->pKernelChannelGroupApi != NULL",
                        "src/kernel/gpu/fifo/kernel_channel.c",0x480);
    lVar9 = *(long *)(*(long *)(param_1 + 0x2b8) + 0x138);
  }
  else {
    lVar9 = *(long *)(*(long *)(param_1 + 0x2b8) + 0x138);
  }
  if (lVar9 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroup != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x482);
  }
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x140),&local_50,local_48);
  uVar2 = *(undefined4 *)(*(long *)(local_50 + 8) + 0x48);
  cVar7 = rmapiLockIsOwner();
  if (cVar7 == '\0') {
    cVar7 = rmapiInRtd3PmPath();
    if (cVar7 == '\0') {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x491,"kchannelDestruct_IMPL",4,
                   "NVRM: Caller missing proper locks\n");
      return;
    }
    lVar9 = rmapiGetInterface(4);
    bVar1 = *(byte *)(param_1 + 0x2ac);
  }
  else {
    lVar9 = rmapiGetInterface(3);
    bVar1 = *(byte *)(param_1 + 0x2ac);
  }
  if (bVar1 < 2) {
    if (*(int *)(lVar3 + 0x4b4c) == 0) {
      nvAssertFailedNoLog("pGpu->numUserKernelChannel > 0","src/kernel/gpu/fifo/kernel_channel.c",
                          0x498);
    }
    else {
      iVar8 = *(int *)(lVar3 + 0x4b4c) + -1;
      *(int *)(lVar3 + 0x4b4c) = iVar8;
      if (iVar8 == 0) {
        gpuRusdRequestPermanentDataPoll_IMPL(lVar3);
      }
    }
  }
  lVar4 = *(long *)(lVar3 + 0x1d18);
  local_55 = '\0';
  if ((((lVar4 != 0) && (*(char *)(lVar4 + 0x2a9) != '\0')) && (*(char *)(lVar4 + 0x2b0) != '\0'))
     && ((*(char *)(param_1 + 0x4f8) != '\0' &&
         (iVar8 = (**(code **)(lVar4 + 0x1c0))(lVar3,lVar4,lVar9,uVar2,param_1,&local_55),
         iVar8 != 0)))) {
    nvAssertOkFailedNoLog
              (iVar8,
               "confComputeRotationNotifHandler_HAL(pGpu, pConfCompute, pRmApi, hClient, pKernelChannel, &bCheckKeyRotation, NV_FALSE)"
               ,"src/kernel/gpu/fifo/kernel_channel.c",0x4a7);
  }
  *(undefined8 *)(param_1 + 600) = 0;
  *(undefined8 *)(param_1 + 0x278) = 0;
  if ((*(char *)(lVar3 + 0x909) != '\0') || (*(char *)(lVar3 + 0x908) != '\0')) {
    lVar10 = gpuGetRpc(lVar3);
    if (lVar10 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x4c3);
    }
    else {
      lVar5 = *(long *)(*(long *)(param_1 + 0x140) + 0x48);
      if ((*(char *)(lVar3 + 0x909) != '\0') || (*(char *)(lVar3 + 0x90a) != '\0')) {
        (**(code **)(lVar3 + 0x3b70))(lVar3 + 0x3b58,uVar2);
        iVar8 = kgrctxFromKernelChannel_IMPL(param_1,&local_40);
        goto joined_r0x0032a47f;
      }
      (**(code **)(lVar10 + 0xf0))
                (lVar3,lVar10,uVar2,*(undefined4 *)(*(long *)(lVar5 + 0x18) + 0x10),
                 *(undefined4 *)(lVar5 + 0x10),*(code **)(lVar10 + 0xf0));
    }
  }
  iVar8 = kgrctxFromKernelChannel_IMPL(param_1,&local_40);
joined_r0x0032a47f:
  if ((iVar8 == 0) &&
     (cVar7 = kgrctxIsValid_IMPL(lVar3,CONCAT44(uStack_3c,local_40),param_1), cVar7 != '\0')) {
    shrkgrctxDetach_IMPL
              (lVar3,*(undefined8 *)(CONCAT44(uStack_3c,local_40) + 0x148),
               CONCAT44(uStack_3c,local_40),param_1);
  }
  _kchannelFreeHalData(lVar3,param_1);
  lVar10 = *(long *)(param_1 + 0x2b8);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pKernelChannel->pKernelChannelGroupApi != NULL",
                        "src/kernel/gpu/fifo/kernel_channel.c",0x4d7);
    lVar10 = *(long *)(param_1 + 0x2b8);
  }
  lVar10 = *(long *)(lVar10 + 0x138);
  if (lVar10 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroup != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x4db);
  }
  kchangrpRemoveChannel_IMPL(lVar3,lVar10,param_1);
  if (*(long *)(lVar10 + 0x198) != 0) {
    ctxBufPoolRelease();
  }
  if (*(char *)(lVar10 + 0x158) != '\0') {
    if (*(long *)(param_1 + 0x2b8) == 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)invalidInstructionException();
      (*pcVar6)();
    }
    (**(code **)(lVar9 + 0x18))
              (lVar9,uVar2,
               *(undefined4 *)
                (*(long *)(*(long *)(*(long *)(param_1 + 0x2b8) + 0x110) + 0x48) + 0x10),
               *(code **)(lVar9 + 0x18));
    *(undefined8 *)(param_1 + 0x2b8) = 0;
  }
  (**(code **)(param_1 + 0x1a8))(lVar3,param_1);
  portMemFree(*(undefined8 *)(param_1 + 0x248));
  *(undefined8 *)(param_1 + 0x248) = 0;
  if (*(int *)(param_1 + 0x2d0) != 1) {
    nvAssertFailedNoLog("pKernelChannel->refCount == 1","src/kernel/gpu/fifo/kernel_channel.c",0x4f2
                       );
  }
  if (local_55 != '\0') {
    iVar8 = (**(code **)(lVar4 + 0x210))(lVar3,lVar4,param_1,&local_54,&local_40);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,
                 "confComputeGetKeyPairByChannel(pGpu, pConfCompute, pKernelChannel, &h2dKey, &d2hKey)"
                 ,"src/kernel/gpu/fifo/kernel_channel.c",0x4fc);
    }
    iVar8 = confComputeCheckAndPerformKeyRotation_IMPL(lVar3,lVar4,local_54,local_40);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"confComputeCheckAndPerformKeyRotation(pGpu, pConfCompute, h2dKey, d2hKey)",
                 "src/kernel/gpu/fifo/kernel_channel.c",0x4fd);
    }
  }
  return;
}


// ===== 0032a730 kchannelGetMemInterMapParams_IMPL =====

undefined8 kchannelGetMemInterMapParams_IMPL(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  uint uVar3;
  long lVar4;
  
  uVar1 = *param_2;
  lVar4 = gpuGetKernelFifoShared_IMPL(uVar1);
  if (*(char *)(param_2 + 2) != '\0') {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x50f,"kchannelGetMemInterMapParams_IMPL",4,
                 "NVRM: Unicast DMA mappings of USERD not supported.\n");
    return 0x56;
  }
  if (*(char *)(lVar4 + 0x4ba) == '\0') {
    return 0x33;
  }
  if (param_1 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x1024);
  }
  else {
    uVar3 = gpumgrGetSubDeviceInstanceFromGpu(uVar1);
    puVar2 = *(undefined8 **)(param_1 + 0x318 + (ulong)uVar3 * 8);
    if (puVar2 != (undefined8 *)0x0) {
      param_2[4] = puVar2;
      param_2[3] = *puVar2;
      return 0;
    }
  }
  return 0x40;
}


// ===== 0032a810 kchannelCheckMemInterUnmap_IMPL =====

byte kchannelCheckMemInterUnmap_IMPL(long param_1,char param_2)

{
  long lVar1;
  
  lVar1 = gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (param_2 == '\0') {
    return -(*(char *)(lVar1 + 0x4ba) == '\0') & 0x33;
  }
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x52c,"kchannelCheckMemInterUnmap_IMPL",4,
               "NVRM: Unicast DMA mappings of channels not supported.\n");
  return 0x56;
}


// ===== 0032a890 kchannelGetIter =====

undefined8 kchannelGetIter(undefined8 param_1)

{
  clientRefOrderedIter();
  return param_1;
}


// ===== 0032a8b9 CliGetKernelChannelWithDevice.cold =====

void CliGetKernelChannelWithDevice_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0032a8d0 CliGetKernelChannelWithDevice =====

int CliGetKernelChannelWithDevice(undefined8 param_1,int param_2,undefined4 param_3,long *param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long local_30 [2];
  
  if (param_4 == (long *)0x0) {
    return 0x1f;
  }
  *param_4 = 0;
  iVar3 = clientGetResourceRef_IMPL(param_1,param_3,local_30);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"clientGetResourceRef(pClient, hKernelChannel, &pResourceRef)",
               "src/kernel/gpu/fifo/kernel_channel.c",0x56b);
    return iVar3;
  }
  lVar4 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_KernelChannel);
  if (lVar4 == 0) {
    nvCheckFailedNoLog(1,"pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x56e);
  }
  else {
    if (*(long *)(local_30[0] + 0x18) != 0) {
      if (*(int *)(*(long *)(local_30[0] + 0x18) + 0x10) != param_2) {
        lVar1 = *(long *)(*(long *)(lVar4 + 0x158) + 0xe8);
        if (lVar1 == 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)invalidInstructionException();
          (*pcVar2)();
        }
        if (*(int *)(*(long *)(*(long *)(lVar1 + 0x110) + 0x48) + 0x10) != param_2) {
          nvCheckFailedNoLog(1,
                             "(pParentRef->hResource == hParent) || (RES_GET_HANDLE(GPU_RES_GET_DEVICE(pKernelChannel)) == hParent)"
                             ,"src/kernel/gpu/fifo/kernel_channel.c",0x578);
          return 0x57;
        }
      }
      *param_4 = lVar4;
      return 0;
    }
    nvCheckFailedNoLog(1,"pParentRef != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x571);
  }
  return 0x57;
}


// ===== 0032aa40 CliGetChannelClassInfo =====

void CliGetChannelClassInfo(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 != 0xc46f) {
    if (param_1 < 0xc470) {
      if (param_1 != 0xb06f) {
        if (param_1 < 0xb070) {
          if ((param_1 & 0xfffffeff) == 0xa06f) {
            uVar2 = 8;
            uVar1 = 1;
          }
          else {
            uVar1 = (uint)(param_1 == 0x906f);
            uVar2 = (uint)(param_1 == 0x906f) << 3;
          }
          goto LAB_0032aada;
        }
        if (param_1 != 0xc06f) {
          uVar2 = (uint)(param_1 == 0xc36f) * 9;
          uVar1 = (uint)(param_1 == 0xc36f);
          goto LAB_0032aada;
        }
      }
    }
    else {
      if (param_1 == 0xc86f) {
        uVar2 = 10;
        uVar1 = 1;
        goto LAB_0032aada;
      }
      if (0xc86f < param_1) {
        param_2[1] = 0;
        uVar2 = param_1 - 0xc96f & 0xfffffeff;
        *param_2 = -(uint)(uVar2 == 0) & 10;
        param_2[2] = (uint)(uVar2 == 0);
        return;
      }
      if (param_1 != 0xc56f) {
        if (param_1 == 0xc572) {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x5e6,"CliGetChannelClassInfo",4,
                       "NVRM: Invalid class for CliGetChannelClassInfo\n");
          *param_2 = 0;
          param_2[1] = 0;
          param_2[2] = 0;
          return;
        }
        uVar2 = 0;
        uVar1 = 0;
        goto LAB_0032aada;
      }
    }
  }
  uVar2 = 9;
  uVar1 = 1;
LAB_0032aada:
  *param_2 = uVar2;
  param_2[1] = 0;
  param_2[2] = uVar1;
  return;
}


// ===== 0032abb0 kchannelGetNextKernelChannel =====

undefined8 kchannelGetNextKernelChannel(undefined8 param_1,uint *param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  uVar3 = gpuGetKernelFifoShared_IMPL();
  if (param_3 == (long *)0x0) {
    return 0x1f;
  }
  *param_3 = 0;
  if (param_2[3] < param_2[1]) {
    do {
      lVar4 = kfifoGetChidMgr_IMPL(param_1,uVar3);
      if (lVar4 == 0) {
        uVar1 = param_2[3] + 1;
        param_2[3] = uVar1;
      }
      else {
        uVar2 = kfifoChidMgrGetNumChannels_IMPL(param_1,uVar3,lVar4);
        uVar1 = param_2[2];
        *param_2 = uVar2;
        while (uVar1 < uVar2) {
          lVar5 = kfifoChidMgrGetKernelChannel_IMPL(param_1,uVar3,lVar4);
          uVar1 = param_2[2] + 1;
          param_2[2] = uVar1;
          if (lVar5 != 0) {
            *param_3 = lVar5;
            return 0;
          }
          uVar2 = *param_2;
        }
        param_2[2] = 0;
        uVar1 = param_2[3] + 1;
        param_2[3] = uVar1;
      }
    } while (uVar1 < param_2[1]);
  }
  return 0x57;
}


// ===== 0032acd0 CliGetKernelChannel =====

int CliGetKernelChannel(undefined8 param_1,undefined8 param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long local_20;
  
  *param_3 = 0;
  iVar1 = clientGetResourceRef_IMPL(param_1,param_2,&local_20);
  if (iVar1 == 0) {
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_KernelChannel);
    *param_3 = lVar2;
    if (lVar2 == 0) {
      iVar1 = 0x21;
      nvCheckFailedNoLog(1,"*ppKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x657);
    }
  }
  return iVar1;
}


// ===== 0032ad50 kchannelNotifyRc_IMPL =====

ulong kchannelNotifyRc_IMPL(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  
  if (*(int *)(*(long *)(*(long *)(param_1 + 0x2b8) + 0x138) + 0x108) != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x66e,"kchannelNotifyRc_IMPL",1,
                 "NVRM: Notification for channel 0x%08x stop is already performed on guest-RM\n",
                 *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4));
    return 0;
  }
  if ((*(int *)(param_1 + 0x250) == 0) && (*(int *)(param_1 + 0x270) == 0)) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x677,"kchannelNotifyRc_IMPL",3,
                 "NVRM: channel 0x%08x has no notifier set\n",
                 *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4));
    uVar4 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x42c);
    lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    if (0x52 < iVar1 - 1U) {
      iVar1 = 0;
    }
    uVar3 = krcErrorSetNotifier_IMPL(lVar2,*(undefined8 *)(lVar2 + 0x1c18),param_1,0x2d,iVar1,0);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x688,"kchannelNotifyRc_IMPL",4,
                   "NVRM: Failed to set error notifier for channel 0x%08x with error 0x%x.\n",
                   *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4),uVar3);
      return uVar3 & 0xffffffff;
    }
  }
  return uVar4;
}


// ===== 0032aec0 kchannelNotifyEvent_IMPL =====

undefined1  [16]
kchannelNotifyEvent_IMPL
          (long param_1,uint param_2,undefined4 param_3,undefined2 param_4,undefined8 param_5,
          uint param_6)

{
  undefined8 uVar1;
  long lVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  uint local_44 [5];
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0);
  CliGetChannelClassInfo
            (*(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x11c),local_44);
  if (local_44[0] <= param_2) {
    auVar4 = nvCheckFailedNoLog(1,"notifyIndex < classInfo.notifiersMaxCount",
                                "src/kernel/gpu/fifo/kernel_channel.c",0x6a9);
    return auVar4;
  }
  lVar2 = inotifyGetNotificationList_IMPL(*(undefined8 *)(param_1 + 0x160));
  uVar3 = *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4);
  if (lVar2 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x6af,"kchannelNotifyEvent_IMPL",1,
                 "NVRM: Posting event on channel 0x%08x with info16 = 0x%x\n",uVar3,param_4);
    osEventNotificationWithInfo(uVar1,lVar2,param_2,param_3,param_4,param_5);
    auVar4._4_4_ = 0;
    auVar4._0_4_ = param_6;
    auVar4._8_8_ = 0x32af27;
    return auVar4;
  }
  auVar4 = nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x6b9,"kchannelNotifyEvent_IMPL",1,
                        "NVRM: No event on channel 0x%08x\n",uVar3);
  return auVar4;
}


// ===== 0032b010 kchannelUpdateNotifierMem_IMPL =====

undefined8
kchannelUpdateNotifierMem_IMPL
          (long param_1,uint param_2,undefined4 param_3,undefined2 param_4,undefined4 param_5)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_60;
  long local_58;
  long local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar7 = *(long *)(param_1 + 600);
  local_58 = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  local_50 = 0;
  local_48 = 0;
  uVar2 = *(undefined8 *)(lVar1 + 0x1b78);
  local_40 = 0;
  uVar3 = *(undefined8 *)(lVar1 + 0x1b88);
  lVar4 = *(long *)(&DAT_00001b90 + lVar1);
  if (lVar7 != 0) {
    memdescGetAddressSpace(lVar7);
    if (*(ulong *)(lVar7 + 0x30) < (ulong)(param_2 + 1) << 4) {
      nvCheckFailedNoLog(1,
                         "memdescGetSize(pNotifierMemDesc) >= (notifyIndex + 1) * sizeof(NvNotification)"
                         ,"src/kernel/gpu/fifo/kernel_channel.c",0x6e9);
    }
    else {
      if (((*(long *)(lVar1 + 0x1d18) == 0) ||
          (*(char *)(*(long *)(lVar1 + 0x1d18) + 0x2b0) == '\0')) || (param_2 != 2)) {
        lVar6 = memdescGetKernelMapping(lVar7);
        if (lVar6 == 0) {
          local_50 = (ulong)param_2 << 4;
          local_58 = lVar7;
          lVar7 = memmgrMemBeginTransfer_IMPL(uVar2,&local_58,0x10,2);
          if (lVar7 != 0) {
            tmrGetCurrentTime_IMPL(uVar3,&local_60);
            notifyFillNvNotification(lVar1,lVar7,param_3,param_4,param_5,1,local_60);
            memmgrMemEndTransfer_IMPL(uVar2,&local_58,0x10,0);
            return 0;
          }
          nvAssertFailedNoLog("pNotifier != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x705);
          return 0x40;
        }
        iVar5 = memdescGetAddressSpace(lVar7);
        if ((iVar5 != 1) && (*(char *)(lVar4 + 0xad0c) != '\0')) {
          nvAssertFailedNoLog("memdescGetAddressSpace(pNotifierMemDesc) == ADDR_SYSMEM || !kbusIsBarAccessBlocked(pKernelBus)"
                              ,"src/kernel/gpu/fifo/kernel_channel.c",0x70f);
          return 0x1f;
        }
        lVar6 = (ulong)param_2 * 0x10 + lVar6;
      }
      else {
        lVar6 = *(long *)(param_1 + 0x4f0);
        if (lVar6 == 0) {
          nvAssertFailedNoLog("pNotifier != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x6f6);
          return 0x40;
        }
      }
      tmrGetCurrentTime_IMPL(uVar3,&local_60);
      notifyFillNvNotification(lVar1,lVar6,param_3,param_4,param_5,1,local_60);
    }
  }
  return 0;
}


// ===== 0032b290 kchannelCtrlCmdStopChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kchannelCtrlCmdStopChannel_IMPL(long param_1)

{
  long lVar1;
  undefined4 *puVar2;
  long lVar3;
  ulong uVar4;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar3 = resservGetTlsCallContext();
  if ((*(char *)(lVar1 + 0x908) != '\0') || (*(char *)(lVar1 + 0x909) != '\0')) {
    puVar2 = *(undefined4 **)(lVar3 + 0x48);
    lVar3 = gpuGetRpc(lVar1);
    if (lVar3 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x736);
      return 0x1a;
    }
    if ((*(char *)(lVar1 + 0x909) == '\0') && (*(char *)(lVar1 + 0x90a) == '\0')) {
      uVar4 = rpcDmaControl_wrapper
                        (lVar1,lVar3,*puVar2,
                         *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10),
                         puVar2[2],*(undefined8 *)(puVar2 + 4));
    }
    else {
      uVar4 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
    }
    if ((int)uVar4 != 0) {
      return uVar4;
    }
  }
  uVar4 = kchannelNotifyRc_IMPL(param_1);
  if ((int)uVar4 != 0) {
    nvAssertOkFailedNoLog
              (uVar4 & 0xffffffff,"kchannelNotifyRc_HAL(pKernelChannel)",
               "src/kernel/gpu/fifo/kernel_channel.c",0x749);
    uVar4 = uVar4 & 0xffffffff;
  }
  return uVar4;
}


// ===== 0032b3be kchannelGetNotifierInfo.cold =====

void kchannelGetNotifierInfo_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0032b3e0 kchannelGetNotifierInfo =====

undefined4
kchannelGetNotifierInfo
          (long param_1,long param_2,int param_3,long *param_4,undefined4 *param_5,long *param_6)

{
  long lVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  long local_50;
  long local_48;
  long *local_40 [2];
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)invalidInstructionException();
    (*pcVar2)();
  }
  uVar8 = **(undefined8 **)(*(long *)(param_2 + 0x110) + 0x48);
  local_50 = 0;
  local_48 = 0;
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("ppMemDesc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x760);
  }
  else {
    if (param_5 != (undefined4 *)0x0) {
      *param_4 = 0;
      *param_5 = 0;
      *param_6 = 0;
      if (param_3 == 0) {
        *param_5 = 1;
        return 0;
      }
      iVar4 = memGetByHandle_IMPL(uVar8,param_3,&local_48);
      if (iVar4 != 0) {
        iVar4 = ctxdmaGetByHandle_IMPL(uVar8,param_3,&local_50);
        if (iVar4 == 0) {
          *param_4 = *(long *)(local_50 + 0x210);
          *param_5 = 2;
          return 0;
        }
        return 0x57;
      }
      iVar4 = memdescGetAddressSpace(*(undefined8 *)(local_48 + 0x118));
      if (iVar4 != 4) {
        *param_4 = *(long *)(local_48 + 0x118);
        *param_5 = 3;
        return 0;
      }
      lVar7 = memdescGetPhysAddr(*(long *)(local_48 + 0x118),3,0);
      uVar5 = gpumgrGetDeviceGpuMask(*(undefined4 *)(param_1 + 0x7b4));
      if (local_48 != 0) {
        cVar3 = CliGetDmaMappingInfo
                          (uVar8,*(undefined4 *)
                                  (*(long *)(*(long *)(param_2 + 0x110) + 0x48) + 0x10),
                           *(undefined4 *)(*(long *)(*(long *)(local_48 + 0xb8) + 0x48) + 0x10),
                           lVar7,uVar5,local_40);
        if (cVar3 == '\0') {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x789,"kchannelGetNotifierInfo",4,
                       "NVRM: Cannot find DMA mapping for GPU_VA notifier\n");
        }
        else {
          lVar1 = *local_40[0];
          if (*(ulong *)(local_40[0][0x1a] + 0x30) < (lVar7 - lVar1) + 0x10U) {
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x791,"kchannelGetNotifierInfo",4,
                         "NVRM: Notifier does not fit within DMA mapping for GPU_VA\n");
          }
          else {
            uVar8 = gpumgrGetParentGPU(param_1);
            uVar6 = gpumgrGetSubDeviceInstanceFromGpu(uVar8);
            if (local_40[0][(ulong)uVar6 + 1] != 0) {
              *param_4 = local_40[0][0x1a];
              *param_5 = 2;
              *param_6 = lVar7 - lVar1;
              return 0;
            }
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x7a2,"kchannelGetNotifierInfo",4,
                         "NVRM: Kernel VA addr mapping not present for notifier\n");
          }
        }
        return 0x40;
      }
                    /* WARNING: Does not return */
      pcVar2 = (code *)invalidInstructionException();
      (*pcVar2)();
    }
    nvAssertFailedNoLog("pNotifierType != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x761);
  }
  return 0x3b;
}


// ===== 0032b6bb kchannelConstruct_IMPL.cold =====

void kchannelConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 0032b6e0 kchannelConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r9 replaced with injection: x86_indirect_thunk_r9 */
/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

int kchannelConstruct_IMPL(long param_1,long param_2,long param_3)

{
  int *piVar1;
  long lVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  int *piVar9;
  long lVar10;
  undefined8 *puVar11;
  long *plVar12;
  undefined8 *puVar13;
  code *pcVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  char cVar18;
  char cVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  int iVar26;
  int iVar27;
  long lVar28;
  undefined8 uVar29;
  long *plVar30;
  long lVar31;
  long lVar32;
  undefined8 uVar33;
  ulong uVar34;
  long lVar35;
  long lVar36;
  char *pcVar37;
  long lVar38;
  undefined8 uVar39;
  undefined8 uVar40;
  long lVar41;
  char *pcVar42;
  ulong *puVar43;
  ulong in_R10;
  ulong in_R11;
  long lVar44;
  bool bVar45;
  bool bVar46;
  long local_188;
  long local_178;
  long local_148;
  int local_130;
  char local_115;
  int local_f8;
  undefined1 local_f4 [4];
  long local_f0;
  long local_e8;
  long local_e0;
  long local_d8;
  long local_d0;
  uint local_c8;
  undefined4 uStack_c4;
  undefined8 local_c0;
  undefined8 local_b8;
  ulong local_b0;
  ulong local_a8;
  undefined8 local_a0;
  uint local_98;
  undefined4 uStack_94;
  undefined8 local_90;
  
  lVar44 = g_pSys;
  lVar8 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  uVar33 = *(undefined8 *)(lVar8 + 0x1bc0);
  lVar28 = gpuGetKernelFifoShared_IMPL(lVar8);
  lVar36 = *(long *)(param_2 + 0x10);
  piVar9 = *(int **)(param_3 + 0x40);
  local_f0 = 0;
  lVar10 = *(long *)(param_2 + 8);
  uVar5 = *(undefined4 *)(lVar10 + 0x48);
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  iVar6 = *(int *)(*(long *)(lVar36 + 0x18) + 0x10);
  local_d0 = 0;
  uVar23 = piVar9[6];
  local_f8 = 0;
  uVar22 = piVar9[5];
  local_115 = *(char *)(lVar8 + 0x4913);
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  bVar46 = false;
  if (local_115 != '\0') {
    local_115 = *(char *)(lVar8 + 0x491e) == '\0';
    bVar46 = (bool)local_115;
  }
  cVar18 = rmapiLockIsOwner();
  if (cVar18 == '\0') {
    cVar18 = rmapiInRtd3PmPath();
    if (cVar18 == '\0') {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xb4,"kchannelConstruct_IMPL",4,
                   "NVRM: Caller missing proper locks\n");
      return 0x2f;
    }
    local_148 = rmapiGetInterface(4);
  }
  else {
    local_148 = rmapiGetInterface(3);
  }
  if ((uVar22 & 3) != 0) {
    nvAssertFailedNoLog("FLD_TEST_DRF(OS04, _FLAGS, _CHANNEL_TYPE, _PHYSICAL, flags)",
                        "src/kernel/gpu/fifo/kernel_channel.c",0xb9);
    return 0x56;
  }
  *(undefined1 *)(param_1 + 0x2d6) = 0;
  *(undefined2 *)(param_1 + 0x238) = 0;
  *(undefined4 *)(param_1 + 0x2d0) = 1;
  *(undefined8 *)(param_1 + 0x40c) = 0;
  *(byte *)(param_1 + 0x408) = (byte)(uVar22 >> 0x1f);
  *(undefined4 *)(param_1 + 0x430) = 0;
  LOCK();
  piVar1 = (int *)(lVar44 + 0x178);
  iVar20 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *(undefined4 *)(param_1 + 0x42c) = 0;
  *(int *)(param_1 + 0x414) = iVar20 + 1;
  *(uint *)(param_1 + 0x428) = uVar22 >> 4 & 1;
  piVar9[0x21] = iVar20 + 1;
  iVar20 = refFindAncestorOfType(lVar36,&DAT_00e0ac20,&local_e0);
  if (iVar20 != 0) {
    nvAssertOkFailedNoLog
              (iVar20,"refFindAncestorOfType(pResourceRef, classId(Device), &pDeviceRef)",
               "src/kernel/gpu/fifo/kernel_channel.c",0xc9);
    return iVar20;
  }
  iVar20 = vgpuGetCallingContextGfid(lVar8,local_f4);
  if (iVar20 != 0) {
    nvAssertOkFailedNoLog
              (iVar20,"vgpuGetCallingContextGfid(pGpu, &callingContextGfid)",
               "src/kernel/gpu/fifo/kernel_channel.c",0xca);
    return iVar20;
  }
  uVar29 = __nvoc_dynamicCast(*(undefined8 *)(local_e0 + 8),__nvoc_class_def_Device);
  iVar20 = piVar9[0x3d];
  cVar18 = hypervisorIsVgxHyper_IMPL();
  if ((cVar18 == '\0') || (*(char *)(lVar8 + 0x909) != '\0')) {
    piVar9[0x3c] = 0;
  }
  piVar9[0x3d] = 0;
  portMemSet(piVar9 + 0x3e,0,0x18);
  portMemSet(piVar9 + 0x44,0,0x18);
  piVar1 = piVar9 + 0x4c;
  piVar9[0x4a] = 0;
  piVar9[0x4b] = 0;
  portMemSet(piVar1,0,0xc);
  piVar3 = piVar9 + 0x4f;
  portMemSet(piVar3,0,0xc);
  piVar4 = piVar9 + 0x52;
  portMemSet(piVar4,0,0x20);
  plVar30 = (long *)__nvoc_dynamicCast(lVar10,__nvoc_class_def_RmClient);
  if (plVar30 == (long *)0x0) {
    return 0x57;
  }
  *(long *)(param_1 + 0x290) = plVar30[0x49];
  uVar7 = piVar9[0x3d];
  *(char *)(param_1 + 0x2d4) = (char)((uVar7 & 0x40) >> 6);
  if ((uVar7 & 0x40) != 0) {
    nvAssertFailedNoLog("!pKernelChannel->bGspOwned || RMCFG_FEATURE_PLATFORM_GSP",
                        "src/kernel/gpu/fifo/kernel_channel.c",0xe8);
    return 0x1f;
  }
  if (*(uint *)(param_2 + 0x28) < 2) {
    cVar18 = (**(code **)(*plVar30 + 0xe0))();
    if ((cVar18 != '\0') || (cVar18 = hypervisorCheckForObjectAccess_IMPL(uVar5), cVar18 != '\0')) {
      *(undefined1 *)(param_1 + 0x2ac) = 1;
      piVar9[5] = piVar9[5] | 0x20;
      cVar18 = *(char *)(param_1 + 0x2ac);
      goto LAB_0032ba57;
    }
    *(undefined1 *)(param_1 + 0x2ac) = 0;
    *(int *)(param_1 + 0x3e4) = (int)plVar30[0x23];
    *(undefined4 *)(param_1 + 1000) = *(undefined4 *)((long)plVar30 + 0x11c);
  }
  else {
    *(undefined1 *)(param_1 + 0x2ac) = 2;
    piVar9[5] = piVar9[5] | 0x20;
    cVar18 = *(char *)(param_1 + 0x2ac);
LAB_0032ba57:
    *(int *)(param_1 + 0x3e4) = (int)plVar30[0x23];
    *(undefined4 *)(param_1 + 1000) = *(undefined4 *)((long)plVar30 + 0x11c);
    if (cVar18 == '\x02') {
      *(byte *)(param_1 + 0x2d5) = (byte)iVar20 >> 7;
    }
  }
  if ((uVar23 != 0) && (in_R11 = (ulong)(uint)piVar9[7], piVar9[7] != 0)) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x12d,"kchannelConstruct_IMPL",4,
                 "NVRM: Both context share and vaspace handles can\'t be valid at the same time\n");
    return 0x1f;
  }
  if (*(long *)(lVar8 + 0x1bc0) == 0) {
LAB_0032bb90:
    bVar45 = false;
  }
  else {
    cVar18 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar8);
    bVar45 = cVar18 != '\0';
    if ((*(long *)(lVar8 + 0x1bc0) != 0) &&
       (cVar19 = kmigmgrIsMIGEnabled_IMPL(lVar8), cVar19 != '\0')) {
      if (cVar18 == '\0') {
        if (*(char *)(*(long *)(lVar8 + 0x4d8) + 0x80) != '\0') goto LAB_0032bb90;
        if (*(char *)(*(long *)(lVar8 + 0x1b78) + 0x434) == '\0') {
LAB_0032bb15:
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x153,"kchannelConstruct_IMPL",4,
                       "NVRM: Channel allocation not allowed when MIG is enabled without GPU instancing\n"
                      );
          return 0x40;
        }
        local_a8 = CONCAT44(local_a8._4_4_,3);
        iVar20 = pmaQueryConfigs(*(undefined8 *)
                                  (*(long *)(*(long *)(lVar8 + 0x1b78) + 0x478) + 0x128),&local_a8);
        if (iVar20 != 0) {
          nvAssertOkFailedNoLog
                    (iVar20,"pmaQueryConfigs(pHeap->pPmaObject, &pmaConfigs)",
                     "src/kernel/gpu/fifo/kernel_channel.c",0x145);
        }
        if ((((~(uint)local_a8 | (uint)local_a8 >> 1) & 1) != 0) ||
           (bVar45 = false, *(char *)(param_1 + 0x2ac) != '\x02')) goto LAB_0032bb15;
      }
      else {
        bVar45 = true;
      }
    }
  }
  iVar20 = clientGetResourceRefByType_IMPL(lVar10,iVar6,0x2b5b80,&local_e8);
  if (iVar20 != 0) {
    in_R10 = (ulong)uVar23;
    local_a8 = 0;
    local_a0 = 0;
    local_98 = 0;
    if (uVar23 == 0) {
      local_a0 = CONCAT44(piVar9[0x20],piVar9[7]);
      if (*(char *)(lVar8 + 0x491d) != '\0') {
        local_98 = *(byte *)((long)piVar9 + 0x17) >> 2 & 0xffffff01;
      }
      iVar20 = (**(code **)(local_148 + 0x10))
                         (local_148,uVar5,iVar6,piVar9 + 0x3c,0xa06c,&local_a8,0x14,1,0,
                          local_148 + 0xb8);
      if (iVar20 == 0) {
        local_130 = piVar9[0x3c];
        iVar20 = clientGetResourceRefByType_IMPL(lVar10,local_130,0x2b5b80,&local_e8);
        if (iVar20 == 0) {
          local_188 = __nvoc_dynamicCast(*(undefined8 *)(local_e8 + 8),
                                         __nvoc_class_def_KernelChannelGroupApi);
          bVar15 = true;
          lVar44 = *(long *)(local_188 + 0x138);
          *(undefined1 *)(lVar44 + 0x158) = 1;
          goto LAB_0032bcd9;
        }
        nvAssertOkFailedNoLog
                  (iVar20,
                   "clientGetResourceRefByType(pRsClient, hChanGrp, classId(KernelChannelGroupApi), &pChanGrpRef)"
                   ,"src/kernel/gpu/fifo/kernel_channel.c",0x185);
        bVar15 = true;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar20,
                   "pRmApi->AllocWithSecInfo(pRmApi, hClient, hParent, &pChannelGpfifoParams->hPhysChannelGroup, KEPLER_CHANNEL_GROUP_A, NV_PTR_TO_NvP64(&tsgParams), sizeof(tsgParams), RMAPI_ALLOC_FLAGS_SKIP_RPC, NvP64_NULL, &pRmApi->defaultSecInfo)"
                   ,"src/kernel/gpu/fifo/kernel_channel.c",0x176);
        bVar15 = false;
        local_130 = 0;
      }
    }
    else {
      iVar20 = 0x1f;
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x164,"kchannelConstruct_IMPL",4,
                   "NVRM: Non-TSG channels can\'t use context share\n");
      bVar15 = false;
      local_130 = 0;
    }
    bVar46 = false;
    lVar44 = 0;
    bVar16 = false;
    local_178 = 0;
    bVar17 = false;
    goto LAB_0032c1e0;
  }
  local_188 = __nvoc_dynamicCast(*(undefined8 *)(local_e8 + 8),
                                 __nvoc_class_def_KernelChannelGroupApi);
  local_130 = iVar6;
  if ((local_188 == 0) || (lVar44 = *(long *)(local_188 + 0x138), lVar44 == 0)) {
    lVar44 = 0;
    iVar20 = 0x3d;
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x198,"kchannelConstruct_IMPL",4,
                 "NVRM: Invalid KernelChannelGroup* for channel 0x%x\n",
                 *(undefined4 *)(lVar36 + 0x10));
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel.c",0x19b);
    bVar46 = false;
    bVar16 = false;
    local_178 = 0;
    bVar17 = false;
    bVar15 = false;
    goto LAB_0032c1e0;
  }
  bVar15 = false;
  if (piVar9[7] != 0) {
    iVar20 = 0x1f;
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1a2,"kchannelConstruct_IMPL",4,
                 "NVRM: TSG channels can\'t use an explicit vaspace\n");
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel.c",0x1a5);
    bVar46 = false;
    bVar16 = false;
    local_178 = 0;
    bVar17 = false;
    goto LAB_0032c1e0;
  }
LAB_0032bcd9:
  *(long *)(param_1 + 0x2c0) = lVar44;
  *(long *)(param_1 + 0x2b8) = local_188;
  local_178 = *(long *)(lVar44 + 0x198);
  if (local_178 == 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1de,"kchannelConstruct_IMPL",1,
                 "NVRM: Not using ctx buf pool\n");
LAB_0032bdcf:
    iVar20 = rmDeviceGpuLocksAcquire(lVar8,0,0x80003);
    if (iVar20 == 0) {
      *(undefined8 *)(param_1 + 0x3f0) = 0x100000000;
      iVar26 = *piVar9;
      *(int *)(param_1 + 0x250) = iVar26;
      iVar20 = piVar9[0x23];
      *(int *)(param_1 + 0x270) = iVar20;
      if (iVar26 == 0) {
        iVar26 = *(int *)(*(long *)(param_1 + 0x2b8) + 0x140);
        *(int *)(param_1 + 0x250) = iVar26;
        if (iVar20 == 0) {
          *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x144);
        }
        if (iVar26 != 0) goto LAB_0032cf08;
        *(undefined4 *)(param_1 + 0x260) = 1;
      }
      else {
        if (iVar20 == 0) {
          *(undefined4 *)(param_1 + 0x270) = *(undefined4 *)(*(long *)(param_1 + 0x2b8) + 0x144);
        }
LAB_0032cf08:
        iVar20 = kchannelGetNotifierInfo
                           (lVar8,uVar29,iVar26,param_1 + 600,param_1 + 0x260,param_1 + 0x268);
        if (iVar20 != 0) {
          nvAssertOkFailedNoLog
                    (iVar20,
                     "kchannelGetNotifierInfo(pGpu, pDevice, pKernelChannel->hErrorContext, &pKernelChannel->pErrContextMemDesc, &pKernelChannel->errorContextType, &pKernelChannel->errorContextOffset)"
                     ,"src/kernel/gpu/fifo/kernel_channel.c",0x208);
        }
        if (*(int *)(param_1 + 0x260) == 1) {
          nvAssertFailedNoLog("pKernelChannel->errorContextType != ERROR_NOTIFIER_TYPE_NONE",
                              "src/kernel/gpu/fifo/kernel_channel.c",0x20d);
        }
      }
      if (*(int *)(param_1 + 0x270) == 0) {
        *(undefined4 *)(param_1 + 0x280) = 1;
      }
      else {
        iVar20 = kchannelGetNotifierInfo
                           (lVar8,uVar29,*(int *)(param_1 + 0x270),param_1 + 0x278,param_1 + 0x280,
                            param_1 + 0x288);
        if (iVar20 != 0) {
          nvAssertOkFailedNoLog
                    (iVar20,
                     "kchannelGetNotifierInfo(pGpu, pDevice, pKernelChannel->hEccErrorContext, &pKernelChannel->pEccErrContextMemDesc, &pKernelChannel->eccErrorContextType, &pKernelChannel->eccErrorContextOffset)"
                     ,"src/kernel/gpu/fifo/kernel_channel.c",0x216);
        }
        if (*(int *)(param_1 + 0x280) == 1) {
          nvAssertFailedNoLog("pKernelChannel->eccErrorContextType != ERROR_NOTIFIER_TYPE_NONE",
                              "src/kernel/gpu/fifo/kernel_channel.c",0x21b);
        }
      }
      if (local_115 != '\0' || *(char *)(lVar8 + 0x909) != '\0') {
        if (*(int *)(param_1 + 0x250) == 0) {
LAB_0032bef0:
          if (*(int *)(param_1 + 0x270) != 0) {
            if (*(long *)(param_1 + 0x278) == 0) {
              nvAssertOkFailedNoLog
                        (0x40,"pKernelChannel->pEccErrContextMemDesc",
                         "src/kernel/gpu/fifo/kernel_channel.c",0x236);
              goto LAB_0032d87e;
            }
            lVar31 = memdescGetPhysAddr(*(long *)(param_1 + 0x278),1,0);
            *(long *)(piVar9 + 0x44) = lVar31 + *(long *)(param_1 + 0x288);
            *(long *)(piVar9 + 0x46) =
                 *(long *)(*(long *)(param_1 + 0x278) + 0x30) - *(long *)(param_1 + 0x288);
            iVar20 = memdescGetAddressSpace(*(undefined8 *)(param_1 + 0x278));
            piVar9[0x48] = iVar20;
            piVar9[0x49] = *(int *)(*(long *)(param_1 + 0x278) + 0x74);
          }
          uVar7 = piVar9[0x3d];
          uVar21 = (*(uint *)(param_1 + 0x260) & 3) << 2;
          piVar9[0x3d] = uVar21 | uVar7 & 0xfffffff3;
          piVar9[0x3d] = uVar21 | uVar7 & 0xffffffc3 | (*(uint *)(param_1 + 0x280) & 3) << 4;
          goto LAB_0032bf38;
        }
        if (*(long *)(param_1 + 600) != 0) {
          lVar31 = memdescGetPhysAddr(*(long *)(param_1 + 600),1,0);
          *(long *)(piVar9 + 0x3e) = lVar31 + *(long *)(param_1 + 0x268);
          *(long *)(piVar9 + 0x40) =
               *(long *)(*(long *)(param_1 + 600) + 0x30) - *(long *)(param_1 + 0x268);
          iVar20 = memdescGetAddressSpace(*(undefined8 *)(param_1 + 600));
          piVar9[0x42] = iVar20;
          piVar9[0x43] = *(int *)(*(long *)(param_1 + 600) + 0x74);
          goto LAB_0032bef0;
        }
        nvAssertOkFailedNoLog
                  (0x40,"pKernelChannel->pErrContextMemDesc","src/kernel/gpu/fifo/kernel_channel.c",
                   0x223);
LAB_0032d87e:
        bVar46 = false;
        iVar20 = 0x40;
        bVar16 = false;
        bVar17 = false;
        goto LAB_0032ce04;
      }
LAB_0032bf38:
      if (*(int *)(param_1 + 0x260) == 0) {
        nvAssertFailedNoLog("pKernelChannel->errorContextType != ERROR_NOTIFIER_TYPE_UNKNOWN",
                            "src/kernel/gpu/fifo/kernel_channel.c",0x255);
      }
      if (*(int *)(param_1 + 0x280) == 0) {
        nvAssertFailedNoLog("pKernelChannel->eccErrorContextType != ERROR_NOTIFIER_TYPE_UNKNOWN",
                            "src/kernel/gpu/fifo/kernel_channel.c",0x256);
      }
      if (*(int *)(lVar44 + 0xf8) == 0) {
        if (uVar23 == 0) {
          if ((*(char *)(lVar44 + 0x159) != '\0') ||
             (iVar20 = kchangrpapiSetLegacyMode_IMPL(local_188,lVar8,lVar28,uVar5), iVar20 == 0))
          goto LAB_0032d0b9;
          nvAssertOkFailedNoLog
                    (iVar20,
                     "kchangrpapiSetLegacyMode(pKernelChannelGroupApi, pGpu, pKernelFifo, hClient)",
                     "src/kernel/gpu/fifo/kernel_channel.c",0x28e);
          bVar46 = false;
          bVar16 = false;
          bVar17 = false;
        }
        else {
LAB_0032c468:
          iVar20 = clientGetResourceRefByType_IMPL(lVar10,uVar23,0x1f9af1,&local_f0);
          uVar40 = 0x272;
          pcVar42 = 
          "clientGetResourceRefByType(pRsClient, hKernelCtxShare, classId(KernelCtxShareApi), &pKernelCtxShareRef)"
          ;
          if (iVar20 == 0) {
            if ((*(long *)(local_f0 + 0x18) != 0) &&
               (*(int *)(*(long *)(local_f0 + 0x18) + 0x10) == iVar6)) goto LAB_0032c4c7;
            nvAssertOkFailedNoLog
                      (0x36,
                       "pKernelCtxShareRef->pParentRef != NULL && pKernelCtxShareRef->pParentRef->hResource == hParent"
                       ,"src/kernel/gpu/fifo/kernel_channel.c",0x27d);
            iVar20 = 0x36;
            bVar46 = false;
            bVar16 = false;
            bVar17 = false;
          }
          else {
LAB_0032d5d9:
            nvAssertOkFailedNoLog(iVar20,pcVar42,"src/kernel/gpu/fifo/kernel_channel.c",uVar40);
LAB_0032d5e1:
            bVar46 = false;
            bVar16 = false;
            bVar17 = false;
          }
        }
        goto LAB_0032ce04;
      }
      if (*(char *)(lVar44 + 0x159) == '\0') {
        if (uVar23 != 0) goto LAB_0032c468;
LAB_0032bf7f:
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x268,"kchannelConstruct_IMPL",2,
                     "NVRM: All channels in a channel group must specify a CONTEXT_SHARE if any one of them specifies it\n"
                    );
LAB_0032bfa5:
        bVar46 = false;
        bVar16 = false;
        bVar17 = false;
        iVar20 = 0x1f;
      }
      else {
        if (uVar23 != 0) goto LAB_0032bf7f;
LAB_0032d0b9:
        uVar24 = *(undefined4 *)(local_188 + 0x150);
        if ((uVar22 & 0x30000000) == 0) {
          uVar24 = *(undefined4 *)(local_188 + 0x14c);
        }
        iVar20 = clientGetResourceRefByType_IMPL(lVar10,uVar24,0x1f9af1,&local_f0);
        if (iVar20 != 0) {
          uVar40 = 0x29a;
          pcVar42 = 
          "clientGetResourceRefByType(pRsClient, hLegacyKernelCtxShare, classId(KernelCtxShareApi), &pKernelCtxShareRef)"
          ;
          goto LAB_0032d5d9;
        }
LAB_0032c4c7:
        lVar31 = __nvoc_dynamicCast(*(undefined8 *)(local_f0 + 8),__nvoc_class_def_KernelCtxShareApi
                                   );
        *(long *)(param_1 + 0x2c8) = lVar31;
        if (lVar31 != 0) {
          uVar40 = 0x2a9;
          pcVar42 = "pKernelChannel->pKernelCtxShareApi->pShareData != NULL";
          if (*(long *)(lVar31 + 0x138) == 0) {
LAB_0032d1e8:
            nvAssertOkFailedNoLog(0x31,pcVar42,"src/kernel/gpu/fifo/kernel_channel.c",uVar40);
            goto LAB_0032d1f2;
          }
          lVar31 = *(long *)(*(long *)(lVar31 + 0x138) + 0x98);
          *(long *)(param_1 + 0x2a0) = lVar31;
          if (lVar31 == 0) {
            uVar40 = 0x2af;
            pcVar42 = "pKernelChannel->pVAS != NULL";
            goto LAB_0032d1e8;
          }
          if (*(char *)(lVar28 + 0x4b1) == '\0') {
            iVar20 = *(int *)(param_1 + 0x42c);
LAB_0032c53b:
            uVar24 = (**(code **)(lVar28 + 0x198))(lVar8,lVar28,iVar20);
            *(undefined4 *)(param_1 + 0x2b0) = uVar24;
            *(char *)(param_1 + 0x4f8) = (char)((uVar22 & 4) >> 2);
            *(byte *)(param_1 + 0x4f9) = *(byte *)((long)piVar9 + 0x16) >> 7;
            if ((uVar22 & 4) != 0) {
              lVar31 = *(long *)(lVar8 + 0x1d18);
              if (lVar31 != 0) {
                if ((*(byte *)(param_1 + 0x2ac) < 2) &&
                   (cVar18 = confComputeAcceptClientRequest_IMPL(lVar8,lVar31), cVar18 == '\0')) {
                  return 0x55;
                }
                if (*(char *)(lVar31 + 0x2b0) == '\0') goto LAB_0032c61e;
                iVar20 = (**(code **)(lVar31 + 0x210))(lVar8,lVar31,param_1,&local_a8,0);
                if (iVar20 == 0) {
                  iVar20 = confComputeGetKeyRotationStatus_IMPL
                                     (lVar31,local_a8 & 0xffffffff,&local_c8);
                  if (iVar20 == 0) {
                    in_R11 = (ulong)local_c8;
                    iVar20 = 0x7d;
                    if (local_c8 == 0) goto LAB_0032c61e;
                  }
                  else {
                    nvAssertOkFailedNoLog
                              (iVar20,
                               "confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &state)",
                               "src/kernel/gpu/fifo/kernel_channel.c",0x2fe);
                  }
                }
                else {
                  nvAssertOkFailedNoLog
                            (iVar20,
                             "confComputeGetKeyPairByChannel(pGpu, pConfCompute, pKernelChannel, &h2dKey, NULL)"
                             ,"src/kernel/gpu/fifo/kernel_channel.c",0x2fb);
                }
                goto LAB_0032d5e1;
              }
LAB_0032c61e:
              iVar20 = (**(code **)(lVar31 + 400))(lVar31,param_1,3,1);
              if (iVar20 != 0) {
                uVar40 = 0x30e;
                pcVar42 = 
                "confComputeKeyStoreRetrieveViaChannel_HAL(pConfCompute, pKernelChannel, ROTATE_IV_ALL_VALID, CHANNEL_IV_OPERATION_INCLUDE_ONLY, &pKernelChannel->clientKmb)"
                ;
                goto LAB_0032d5d9;
              }
              portMemCopy(piVar1,0xc,param_1 + 0x454,0xc);
              portMemCopy(piVar3,0xc,param_1 + 0x48c,0xc);
              portMemCopy(piVar4,0x20,param_1 + 0x48c,0x20);
            }
            if (((bVar45) && (*(int *)(param_1 + 0x42c) - 1U < 8)) &&
               (iVar20 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar8,uVar33,uVar29,param_1 + 0x418),
               iVar20 != 0)) {
              nvAssertOkFailedNoLog
                        (iVar20,
                         "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &pKernelChannel->partitionRef)"
                         ,"src/kernel/gpu/fifo/kernel_channel.c",0x327);
            }
            if ((*(char *)(lVar8 + 0x908) == '\0') || (*(char *)(lVar8 + 0x4913) != '\0')) {
              iVar20 = (**(code **)(param_1 + 0x1a0))(lVar8,param_1,uVar5,uVar22,0,0xffffffff);
              if (iVar20 != 0) {
                nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x333,"kchannelConstruct_IMPL",4
                             ,
                             "NVRM: Error in Allocating channel id 0x%x for hClient 0x%x hKernelChannel 0x%x \n"
                             ,0xffffffff,uVar5,*(undefined4 *)(lVar36 + 0x10));
                bVar46 = false;
                bVar16 = false;
                bVar17 = false;
                goto LAB_0032ce04;
              }
              cVar18 = *(char *)(lVar8 + 0x908);
              if ((cVar18 != '\0') && (!bVar46)) {
                bVar17 = true;
                goto LAB_0032dad3;
              }
              bVar17 = true;
              bVar16 = false;
LAB_0032d3ec:
              if ((cVar18 != '\0') && (*(char *)(lVar8 + 0x4913) == '\0')) goto LAB_0032c6fe;
            }
            else {
              bVar17 = false;
              bVar16 = false;
              if (!bVar46) {
LAB_0032dad3:
                iVar20 = _kchannelSendChannelAllocRpc(param_1,piVar9,lVar44,0);
                if (iVar20 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar20,
                             "_kchannelSendChannelAllocRpc(pKernelChannel, pChannelGpfifoParams, pKernelChannelGroup, bFullSriov)"
                             ,"src/kernel/gpu/fifo/kernel_channel.c",0x343);
                  bVar46 = false;
                  bVar16 = false;
                  goto LAB_0032ce04;
                }
                bVar16 = true;
                cVar18 = *(char *)(lVar8 + 0x908);
                goto LAB_0032d3ec;
              }
LAB_0032c6fe:
              uVar24 = *(undefined4 *)(param_1 + 0x2b4);
              iVar20 = (**(code **)(param_1 + 0x1a0))(lVar8,param_1,uVar5,uVar22,0);
              if (iVar20 != 0) {
                nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x356,"kchannelConstruct_IMPL",4
                             ,
                             "NVRM: Error in Allocating channel id 0x%x for hClient 0x%x hKernelChannel 0x%x \n"
                             ,uVar24,uVar5,*(undefined4 *)(lVar36 + 0x10));
                bVar46 = false;
                goto LAB_0032ce04;
              }
              bVar17 = true;
            }
            lVar31 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
            lVar32 = gpuGetKernelFifoShared_IMPL(lVar31);
            uVar23 = *(uint *)(*(long *)(*(long *)(param_1 + 0x2b8) + 0x138) + 0x108);
            uVar24 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
            portMemSet(param_1 + 0x2d8,0,0x40);
            uVar22 = gpumgrGetSubDeviceInstanceFromGpu(lVar31);
            uVar33 = portMemAllocNonPaged(0x18);
            *(undefined8 *)(param_1 + 0x2d8 + (ulong)uVar22 * 8) = uVar33;
            uVar22 = gpumgrGetSubDeviceInstanceFromGpu(lVar31);
            if (*(long *)(param_1 + 0x2d8 + (ulong)uVar22 * 8) == 0) {
              iVar20 = 0x51;
              nvAssertFailedNoLog("pKernelChannel->pFifoHalData[gpumgrGetSubDeviceInstanceFromGpu(pGpu)] != NULL"
                                  ,"src/kernel/gpu/fifo/kernel_channel.c",0x83f);
              _kchannelFreeHalData(lVar31,param_1);
              nvAssertOkFailedNoLog
                        (0x51,"_kchannelAllocHalData(pGpu, pKernelChannel)",
                         "src/kernel/gpu/fifo/kernel_channel.c",0x880);
LAB_0032d574:
              nvAssertOkFailedNoLog
                        (iVar20,
                         "_kchannelAllocOrDescribeInstMem(pKernelChannel, pChannelGpfifoParams)",
                         "src/kernel/gpu/fifo/kernel_channel.c",0x365);
              bVar46 = false;
            }
            else {
              uVar22 = gpumgrGetSubDeviceInstanceFromGpu(lVar31);
              portMemSet(*(undefined8 *)(param_1 + 0x2d8 + (ulong)uVar22 * 8),0,0x18);
              if ((uVar23 == 0) || (*(char *)(lVar31 + 0x491e) != '\0')) {
                *(undefined1 *)(param_1 + 0x398) = 0;
                iVar20 = (**(code **)(param_1 + 0x1c0))
                                   (lVar31,param_1,uVar24,piVar9 + 8,piVar9 + 0x10);
                if (iVar20 == 0) {
                  if (*(char *)(lVar31 + 0x490f) == '\0') goto LAB_0032d4cc;
LAB_0032d6a0:
                  if (*(char *)(lVar31 + 0x4913) == '\0') {
                    in_R10 = (ulong)uVar23;
                    if (uVar23 != 0) goto LAB_0032d4fb;
                    goto LAB_0032d50f;
                  }
LAB_0032c854:
                  if (*(char *)(lVar31 + 0x491e) == '\0') {
                    if (uVar23 != 0) goto LAB_0032c878;
                    goto LAB_0032d523;
                  }
                  lVar38 = *(long *)(*(long *)(param_1 + 0x158) + 0xe8);
                  uVar23 = gpumgrGetSubDeviceInstanceFromGpu(lVar31);
                  puVar11 = *(undefined8 **)(param_1 + 0x2d8 + (ulong)uVar23 * 8);
                  portMemSet(&local_a8,0,0x70);
                  puVar13 = *(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48);
                  local_a8 = CONCAT44(local_a8._4_4_,*(undefined4 *)(puVar13 + 2));
                  if (lVar38 == 0) {
                    /* WARNING: Does not return */
                    pcVar14 = (code *)invalidInstructionException();
                    (*pcVar14)();
                  }
                  iVar20 = subdeviceGetByInstance_IMPL
                                     (*puVar13,*(undefined4 *)
                                                (*(long *)(*(long *)(lVar38 + 0x110) + 0x48) + 0x10)
                                      ,uVar23,&local_c8);
                  if (iVar20 == 0) {
                    if (CONCAT44(uStack_c4,local_c8) == 0) {
                    /* WARNING: Does not return */
                      pcVar14 = (code *)invalidInstructionException();
                      (*pcVar14)();
                    }
                    uVar24 = *(undefined4 *)
                              (*(long *)(*(long *)(CONCAT44(uStack_c4,local_c8) + 0x140) + 0x48) +
                              0x10);
                    lVar38 = gpuGetRpc(lVar31);
                    if (lVar38 == 0) {
                      iVar20 = 0x1a;
                      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",
                                          0x9ac);
                    }
                    else {
                      uVar25 = *(undefined4 *)
                                (**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
                      if ((*(char *)(lVar31 + 0x909) == '\0') && (*(char *)(lVar31 + 0x90a) == '\0')
                         ) {
                        puVar43 = (ulong *)0x2080110c;
                        iVar20 = rpcDmaControl_wrapper
                                           (lVar31,lVar38,uVar25,uVar24,0x2080110c,&local_a8,0x70,
                                            in_R11);
                      }
                      else {
                        puVar43 = &local_a8;
                        iVar20 = (**(code **)(lVar31 + 0x3b90))
                                           (lVar31 + 0x3b58,uVar25,uVar24,0x2080110c,puVar43,0x70);
                      }
                      if (iVar20 == 0) {
                        if ((int)local_a0 == 1) {
                          uVar24 = 2;
                        }
                        else {
                          uVar24 = 1;
                          if (1 < (int)local_a0 - 2U) {
                            iVar20 = 0x1f;
                            plVar30 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
                            nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x9c8,
                                         "_kchannelDescribeMemDescsHeavySriov",4,
                                         "NVRM: Unknown aperture, hClient 0x%x, hKernelChannel 0x%x\n"
                                         ,*(undefined4 *)(*plVar30 + 0x48),(int)plVar30[2],puVar43);
                            goto LAB_0032e224;
                          }
                        }
                        iVar20 = memdescCreate(puVar11,lVar31,local_90,1,1,uVar24,1,0x2000000);
                        if (iVar20 != 0) {
                          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x9d7,
                                       "_kchannelDescribeMemDescsHeavySriov",4,
                                       "NVRM: Unable to allocate instance memory descriptor!\n");
                          goto LAB_0032e224;
                        }
                        memdescDescribe(*puVar11,uVar24,CONCAT44(uStack_94,local_98));
                        uVar33 = 0;
                        lVar38 = *(long *)(param_1 + 0x358 + (ulong)uVar23 * 8);
                        if (lVar38 != 0) {
                          uVar33 = memdescGetPhysAddr(lVar38,1,0);
                        }
                        uVar29 = uVar33;
                        uVar24 = memdescGetAddressSpace(*puVar11);
                        uVar25 = memdescGetAddressSpace(*puVar11);
                        uVar40 = memdescGetApertureString(uVar25);
                        uVar39 = memdescGetPhysAddr(*puVar11,1,0);
                        plVar12 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
                        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x9de,
                                     "_kchannelDescribeMemDescsHeavySriov",1,
                                     "NVRM: hChannel 0x%x hClient 0x%x, Class ID 0x%x Instance Block @ 0x%llx (%s %x) USERD @ 0x%llx for subdevice %d\n"
                                     ,(int)plVar12[2],*(undefined4 *)(*plVar12 + 0x48),
                                     *(undefined4 *)((long)plVar12 + 0x11c),uVar39,uVar40,uVar24,
                                     uVar33,uVar23,uVar29);
                        goto LAB_0032cb59;
                      }
                    }
                    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x9b5,
                                 "_kchannelDescribeMemDescsHeavySriov",4,
                                 "NVRM: RM Control call to fetch channel meminfo failed, hKernelChannel 0x%x\n"
                                 ,*(undefined4 *)
                                   (*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10));
                  }
                  else {
                    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x9a3,
                                 "_kchannelDescribeMemDescsHeavySriov",4,
                                 "NVRM: Unable to get subdevice object.\n");
                  }
LAB_0032e224:
                  nvAssertOkFailedNoLog
                            (iVar20,"_kchannelDescribeMemDescsHeavySriov(pGpu, pKernelChannel)",
                             "src/kernel/gpu/fifo/kernel_channel.c",0x8a9);
                }
                else {
                  nvAssertOkFailedNoLog
                            (iVar20,
                             "kchannelCreateUserdMemDescBc_HAL(pGpu, pKernelChannel, hClient, pChannelGpfifoParams->hUserdMemory, pChannelGpfifoParams->userdOffset)"
                             ,"src/kernel/gpu/fifo/kernel_channel.c",0x88e);
                }
LAB_0032d565:
                _kchannelFreeHalData(lVar31,param_1);
                goto LAB_0032d574;
              }
              *(undefined1 *)(param_1 + 0x398) = 1;
              if (*(char *)(lVar31 + 0x490f) == '\0') {
LAB_0032d4cc:
                if ((*(char *)(lVar31 + 0x908) == '\0') || (*(char *)(lVar31 + 0x4913) != '\0')) {
                  cVar18 = hypervisorIsVgxHyper_IMPL();
                  if (((cVar18 != '\0') && (*(char *)(lVar31 + 0x491d) == '\0')) ||
                     (*(char *)(param_1 + 0x398) != '\0')) goto LAB_0032d6a0;
                  iVar20 = 0x1f;
                  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x8a0,
                               "_kchannelAllocOrDescribeInstMem",4,
                               "NVRM: Client must allocate USERD\n");
                  goto LAB_0032d565;
                }
                if (uVar23 != 0) goto LAB_0032d4fb;
LAB_0032cb72:
                uVar23 = gpumgrGetSubDeviceInstanceFromGpu(lVar31);
                bVar46 = false;
                lVar38 = *(long *)(param_1 + 0x358 + (ulong)uVar23 * 8);
                if (*(char *)(lVar31 + 0x4913) != '\0') {
                  bVar46 = *(char *)(lVar31 + 0x491e) == '\0';
                }
                if ((lVar38 != 0) &&
                   ((iVar20 = memdescGetAddressSpace(lVar38), iVar20 == 1 ||
                    ((iVar20 = memdescGetAddressSpace(lVar38), iVar20 == 2 && (bVar46)))))) {
                  (**(code **)(lVar32 + 0x310))(lVar31,lVar32,lVar38);
                }
              }
              else {
                if (*(char *)(lVar31 + 0x4913) != '\0') goto LAB_0032c854;
LAB_0032d4fb:
                if (*(char *)(lVar31 + 0x491e) == '\0') {
LAB_0032c878:
                  lVar38 = *(long *)(param_1 + 0x2b8);
                  if (lVar38 == 0) {
                    nvAssertFailedNoLog("(pKernelChannelGroupApi != NULL)",
                                        "src/kernel/gpu/fifo/kernel_channel.c",0x8ef);
LAB_0032e11f:
                    iVar20 = 0x40;
                  }
                  else {
                    if (*(int *)(*(long *)(lVar38 + 0x138) + 0x108) == 0) {
                      nvAssertFailedNoLog("(RMCFG_FEATURE_PLATFORM_GSP && !pKernelChannel->bGspOwned) || (IS_GFID_VF(gfid) && !gpuIsWarBug200577889SriovHeavyEnabled(pGpu))"
                                          ,"src/kernel/gpu/fifo/kernel_channel.c",0x8f2);
                      goto LAB_0032e11f;
                    }
                    uVar23 = gpumgrGetSubDeviceInstanceFromGpu(lVar31);
                    lVar2 = param_1 + (ulong)uVar23 * 8;
                    puVar11 = *(undefined8 **)(lVar2 + 0x2d8);
                    uVar33 = 0x2000000;
                    iVar20 = memdescCreate(puVar11,lVar31,*(undefined8 *)(piVar9 + 0x26),1,1,
                                           piVar9[0x28],piVar9[0x29]);
                    if (iVar20 == 0) {
                      memdescDescribe(*puVar11,piVar9[0x28],*(undefined8 *)(piVar9 + 0x24),
                                      *(undefined8 *)(piVar9 + 0x26),uVar33);
                      iVar20 = memdescCreate(puVar11 + 1,lVar31,*(undefined8 *)(piVar9 + 0x32),1,1,
                                             piVar9[0x34],piVar9[0x35],0x2000000);
                      if (iVar20 == 0) {
                        memdescDescribe(puVar11[1],piVar9[0x34],*(undefined8 *)(piVar9 + 0x30),
                                        *(undefined8 *)(piVar9 + 0x32));
                        iVar20 = memdescCreate(param_1 + 0x358 + (ulong)uVar23 * 8,lVar31,
                                               *(undefined8 *)(piVar9 + 0x2c),1,1,piVar9[0x2e],
                                               piVar9[0x2f],0x2000000);
                        if (iVar20 == 0) {
                          memdescDescribe(*(undefined8 *)(lVar2 + 0x358),piVar9[0x2e],
                                          *(undefined8 *)(piVar9 + 0x2a),
                                          *(undefined8 *)(piVar9 + 0x2c));
                          if (*(char *)(lVar31 + 0x491e) == '\0') {
                            memdescSetFlag(*puVar11,0x100,1);
                            memdescSetFlag(puVar11[1],0x100,1);
                            memdescSetFlag(*(undefined8 *)(lVar2 + 0x358),0x100,1);
                            lVar41 = *(long *)(lVar38 + 0x138);
                            uVar34 = (ulong)((uint)piVar9[5] >> 4 & 1);
                            if (*(char *)(lVar31 + 0x491e) != '\0') goto LAB_0032ca62;
                            *(undefined8 *)(uVar34 * 0x10 + *(long *)(lVar41 + 0x160)) =
                                 *(undefined8 *)(piVar9 + 0x36);
                          }
                          else {
                            lVar41 = *(long *)(lVar38 + 0x138);
                            uVar34 = (ulong)((uint)piVar9[5] >> 4 & 1);
LAB_0032ca62:
                            lVar35 = uVar34 * 0x10;
                            if (*(long *)(*(long *)(lVar41 + 0x160) + 8 + lVar35) == 0) {
                              if (*(long *)(piVar9 + 0x38) == 0) {
                                nvAssertFailedNoLog("pChannelGpfifoParams->mthdbufMem.size > 0",
                                                    "src/kernel/gpu/fifo/kernel_channel.c",0x948);
                              }
                              if (*(long *)(piVar9 + 0x36) == 0) {
                                nvAssertFailedNoLog("pChannelGpfifoParams->mthdbufMem.base != 0",
                                                    "src/kernel/gpu/fifo/kernel_channel.c",0x949);
                              }
                              iVar20 = memdescCreate(lVar35 + *(long *)(*(long *)(lVar38 + 0x138) +
                                                                       0x160) + 8,lVar31,
                                                     *(undefined8 *)(piVar9 + 0x38),1,1,piVar9[0x3a]
                                                     ,piVar9[0x3b],0x2000000);
                              if (iVar20 != 0) {
                                nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x956,
                                             "_kchannelDescribeMemDescsFromParams",4,
                                             "NVRM: Unable to allocate instance memory descriptor!\n"
                                            );
                                goto LAB_0032e125;
                              }
                              memdescDescribe(*(undefined8 *)
                                               (*(long *)(*(long *)(lVar38 + 0x138) + 0x160) + 8 +
                                               lVar35),piVar9[0x3a],*(undefined8 *)(piVar9 + 0x36));
                            }
                          }
                          uVar33 = 0;
                          if (*(long *)(lVar2 + 0x358) != 0) {
                            uVar33 = memdescGetPhysAddr(*(long *)(lVar2 + 0x358),1,0);
                          }
                          uVar24 = memdescGetAddressSpace(*puVar11);
                          uVar25 = memdescGetAddressSpace(*puVar11);
                          uVar29 = memdescGetApertureString(uVar25);
                          uVar40 = memdescGetPhysAddr(*puVar11,1,0);
                          plVar12 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
                          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x961,
                                       "_kchannelDescribeMemDescsFromParams",1,
                                       "NVRM: hChannel 0x%x hClient 0x%x, Class ID 0x%x Instance Block @ 0x%llx (%s %x) USERD @ 0x%llx for subdevice %d\n"
                                       ,(int)plVar12[2],*(undefined4 *)(*plVar12 + 0x48),
                                       *(undefined4 *)((long)plVar12 + 0x11c),uVar40,uVar29,uVar24,
                                       uVar33,uVar23,in_R10);
                          goto LAB_0032cb59;
                        }
                        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x92a,
                                     "_kchannelDescribeMemDescsFromParams",4,
                                     "NVRM: Unable to allocate instance memory descriptor!\n");
                      }
                      else {
                        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x919,
                                     "_kchannelDescribeMemDescsFromParams",4,
                                     "NVRM: Unable to allocate instance memory descriptor!\n");
                      }
                    }
                    else {
                      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x907,
                                   "_kchannelDescribeMemDescsFromParams",4,
                                   "NVRM: Unable to allocate instance memory descriptor!\n");
                    }
                  }
LAB_0032e125:
                  nvAssertOkFailedNoLog
                            (iVar20,
                             "_kchannelDescribeMemDescsFromParams(pGpu, pKernelChannel, pChannelGpfifoParams)"
                             ,"src/kernel/gpu/fifo/kernel_channel.c",0x8b1);
                  goto LAB_0032d565;
                }
LAB_0032d50f:
                if (*(char *)(lVar31 + 0x908) != '\0') goto LAB_0032cb72;
LAB_0032d523:
                iVar20 = (**(code **)(param_1 + 400))(lVar31,param_1,piVar9[5],0);
                if (iVar20 != 0) {
                  nvAssertOkFailedNoLog
                            (iVar20,
                             "kchannelAllocMem_HAL(pGpu, pKernelChannel, pChannelGpfifoParams->flags, _kchannelgetVerifFlags(pGpu, pChannelGpfifoParams))"
                             ,"src/kernel/gpu/fifo/kernel_channel.c",0x8b8);
                  goto LAB_0032d565;
                }
LAB_0032cb59:
                if ((*(char *)(lVar31 + 0x908) != '\0') || (*(char *)(lVar31 + 0x909) != '\0'))
                goto LAB_0032cb72;
              }
              iVar20 = kchangrpAddChannel_IMPL(lVar8,lVar44,param_1);
              if (iVar20 != 0) {
                nvAssertOkFailedNoLog
                          (iVar20,"kchangrpAddChannel(pGpu, pKernelChannelGroup, pKernelChannel)",
                           "src/kernel/gpu/fifo/kernel_channel.c",0x36a);
                bVar46 = false;
                goto LAB_0032ce04;
              }
              if (*(char *)(lVar44 + 0x188) != '\0') {
                uVar24 = *(undefined4 *)(lVar44 + 0xf4);
                lVar31 = gpuGetKernelFifoShared_IMPL(lVar8);
                iVar26 = (**(code **)(lVar31 + 0x300))
                                   (lVar8,lVar31,param_1,uVar24,*(code **)(lVar31 + 0x300));
                uVar33 = 0x374;
                pcVar42 = 
                "kfifoRunlistSetId_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), pKernelChannel, pKernelChannelGroup->runlistId)"
                ;
                if (iVar26 == 0) goto LAB_0032cc07;
                goto LAB_0032d7b6;
              }
LAB_0032cc07:
              if (*(char *)(param_1 + 0x398) == '\0') {
                (**(code **)(param_1 + 0x1b0))(lVar8,param_1,0,&local_a8);
              }
              else {
                (**(code **)(lVar28 + 0x2a0))(lVar28,param_1 + 0x400,0);
              }
              if (*(char *)(lVar8 + 0x497) != '\0') {
                gpuacctSetProcType_IMPL
                          (*(undefined8 *)(g_pSys + 0x218),*(undefined4 *)(lVar8 + 0x7a4),
                           (int)plVar30[0x23],*(undefined4 *)((long)plVar30 + 0x11c),1);
              }
              if (local_115 != '\0' || *(char *)(lVar8 + 0x909) != '\0') {
                iVar26 = _kchannelSendChannelAllocRpc(param_1,piVar9,lVar44,local_115);
                uVar33 = 0x3a6;
                pcVar42 = 
                "_kchannelSendChannelAllocRpc(pKernelChannel, pChannelGpfifoParams, pKernelChannelGroup, bFullSriov)"
                ;
                if (iVar26 != 0) goto LAB_0032d7b6;
                bVar16 = true;
              }
              if (*(char *)(param_1 + 0x4f8) != '\0') {
                iVar26 = (**(code **)(*(long *)(lVar8 + 0x1d18) + 0x188))
                                   (*(long *)(lVar8 + 0x1d18),param_1,3);
                uVar33 = 0x3b3;
                pcVar42 = 
                "confComputeKeyStoreDeriveViaChannel_HAL(pConfCompute, pKernelChannel, ROTATE_IV_ALL_VALID)"
                ;
                if (iVar26 != 0) goto LAB_0032d7b6;
              }
              if ((*(char *)(lVar28 + 0x4b0) != '\0') ||
                 (cVar18 = gpuIsCCorApmFeatureEnabled_IMPL(lVar8), cVar18 != '\0' || bVar45)) {
                lVar28 = gpuGetKernelFifoShared_IMPL(lVar8);
                iVar26 = (**(code **)(lVar28 + 0x300))
                                   (lVar8,lVar28,param_1,*(undefined4 *)(param_1 + 0x2b0),
                                    *(code **)(lVar28 + 0x300));
                uVar33 = 0x3c4;
                pcVar42 = 
                "kfifoRunlistSetId_HAL(pGpu, pTempKernelFifo, pKernelChannel, pKernelChannel->runlistId)"
                ;
                if (iVar26 != 0) goto LAB_0032d7b6;
              }
              if ((bVar15) && (iVar26 = refAddDependant(local_e8,lVar36), iVar26 != 0)) {
                nvAssertOkFailedNoLog
                          (iVar26,"refAddDependant(pChanGrpRef, pResourceRef)",
                           "src/kernel/gpu/fifo/kernel_channel.c",0x3d1);
                bVar46 = true;
                iVar20 = iVar26;
              }
              else {
                if (piVar9[7] == 0) {
LAB_0032cd0f:
                  if (*(long *)(param_1 + 0x2c8) != 0) {
                    iVar26 = refAddDependant(*(undefined8 *)
                                              (*(long *)(*(long *)(param_1 + 0x2c8) + 0x110) + 0x48)
                                             ,lVar36);
                    uVar33 = 0x3eb;
                    pcVar42 = 
                    "refAddDependant(RES_GET_REF(pKernelChannel->pKernelCtxShareApi), pResourceRef)"
                    ;
                    if (iVar26 != 0) goto LAB_0032d7b6;
                  }
                  iVar26 = *(int *)(local_188 + 0x148);
                  *(int *)(param_1 + 0x2a8) = iVar26;
                  if (iVar26 != 0) {
                    iVar26 = kgrctxFromKernelChannel_IMPL(param_1,&local_d0);
                    if (iVar26 == 0) {
                      if (local_d0 == 0) {
                    /* WARNING: Does not return */
                        pcVar14 = (code *)invalidInstructionException();
                        (*pcVar14)();
                      }
                      iVar26 = refAddDependant(*(undefined8 *)(*(long *)(local_d0 + 0x110) + 0x48),
                                               lVar36);
                      uVar33 = 0x3f8;
                      pcVar42 = "refAddDependant(RES_GET_REF(pKernelGraphicsContext), pResourceRef)"
                      ;
                      if (iVar26 == 0) goto LAB_0032cd68;
                    }
                    else {
                      uVar33 = 0x3f4;
                      pcVar42 = "kgrctxFromKernelChannel(pKernelChannel, &pKernelGraphicsContext)";
                    }
                    goto LAB_0032d7b6;
                  }
LAB_0032cd68:
                  if ((*piVar9 != 0) &&
                     (iVar26 = ctxdmaGetByHandle_IMPL
                                         (lVar10,*(undefined4 *)(param_1 + 0x250),&local_a8),
                     iVar26 == 0)) {
                    if (*(ulong *)(local_a8 + 0x130) < 0xf) {
                      nvCheckFailedNoLog(1,"pContextDma->Limit >= sizeof(NvNotification) - 1",
                                         "src/kernel/gpu/fifo/kernel_channel.c",0xfab);
                      nvAssertOkFailedNoLog
                                (0x1f,"_kchannelNotifyOfChid(pGpu, pKernelChannel, pRsClient)",
                                 "src/kernel/gpu/fifo/kernel_channel.c",0x3ff);
                      bVar46 = true;
                      iVar20 = 0x1f;
                      goto LAB_0032ce04;
                    }
                    notifyFillNotifier(lVar8,local_a8,*(undefined4 *)(param_1 + 0x2b4),0,0);
                  }
                  local_a8 = local_a8 & 0xffffffffffffff00;
                  *(undefined4 *)(param_1 + 0x298) =
                       *(undefined4 *)(*(long *)(param_1 + 0x2c8) + 0x140);
                  lVar10 = *(long *)(lVar8 + 0x1d18);
                  if ((((lVar10 != 0) && (*(char *)(lVar10 + 0x2a9) != '\0')) &&
                      (*(char *)(lVar10 + 0x2b0) != '\0')) &&
                     ((*(char *)(param_1 + 0x4f8) != '\0' &&
                      (iVar26 = (**(code **)(lVar10 + 0x1c0))
                                          (lVar8,lVar10,local_148,uVar5,param_1,&local_a8,1),
                      iVar26 != 0)))) {
                    uVar33 = 0x410;
                    pcVar42 = 
                    "confComputeRotationNotifHandler_HAL(pGpu, pConfCompute, pRmApi, hClient, pKernelChannel, &bCheckKeyRotation, NV_TRUE)"
                    ;
                    goto LAB_0032d7b6;
                  }
                  bVar46 = true;
                  if (1 < *(byte *)(param_1 + 0x2ac)) goto LAB_0032ce04;
                  iVar27 = *(int *)(lVar8 + 0x4b4c) + 1;
                  *(int *)(lVar8 + 0x4b4c) = iVar27;
                  iVar26 = iVar20;
                  if (iVar27 == 1) {
                    gpuRusdRequestPermanentDataPoll_IMPL(lVar8);
                  }
                }
                else {
                  iVar26 = clientGetResourceRef_IMPL(lVar10,piVar9[7],&local_d8);
                  uVar33 = 0x3d7;
                  pcVar42 = 
                  "clientGetResourceRef(pRsClient, pChannelGpfifoParams->hVASpace, &pVASpaceRef)";
                  if (iVar26 == 0) {
                    if (local_d8 == 0) {
                      nvAssertOkFailedNoLog
                                (0x31,"pVASpaceRef != NULL","src/kernel/gpu/fifo/kernel_channel.c",
                                 0x3dc);
                      bVar46 = true;
                      iVar20 = 0x31;
                      goto LAB_0032ce04;
                    }
                    iVar26 = refAddDependant(local_d8,lVar36,"src/kernel/gpu/fifo/kernel_channel.c",
                                             0x3d7);
                    uVar33 = 0x3e0;
                    pcVar42 = "refAddDependant(pVASpaceRef, pResourceRef)";
                    if (iVar26 == 0) goto LAB_0032cd0f;
                  }
LAB_0032d7b6:
                  nvAssertOkFailedNoLog
                            (iVar26,pcVar42,"src/kernel/gpu/fifo/kernel_channel.c",uVar33);
                }
                bVar46 = true;
                iVar20 = iVar26;
              }
            }
            goto LAB_0032ce04;
          }
          iVar20 = *(int *)(lVar44 + 0xfc);
          if (0x52 < iVar20 - 1U) {
            nvAssertOkFailedNoLog
                      (0x40,"RM_ENGINE_TYPE_IS_VALID(pKernelChannelGroup->engineType)",
                       "src/kernel/gpu/fifo/kernel_channel.c",0x2b7);
            goto LAB_0032d87e;
          }
          if (0x52 < piVar9[0x20] - 1U) {
LAB_0032d437:
            *(int *)(param_1 + 0x42c) = iVar20;
            goto LAB_0032c53b;
          }
          local_f8 = gpuGetRmEngineType_IMPL();
          if (bVar45) {
            iVar20 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar8,uVar33,uVar29,&local_a8);
            if (iVar20 == 0) {
              iVar20 = kmigmgrGetLocalToGlobalEngineType_IMPL
                                 (lVar8,uVar33,local_a8,local_a0,local_f8,&local_f8);
              if (iVar20 == 0) goto LAB_0032d8b6;
              nvCheckOkFailedNoLog
                        (4,iVar20,
                         "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, globalRmEngineType, &globalRmEngineType)"
                         ,"src/kernel/gpu/fifo/kernel_channel.c",0x2cb);
            }
            else {
              nvCheckOkFailedNoLog
                        (4,iVar20,
                         "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)",
                         "src/kernel/gpu/fifo/kernel_channel.c",0x2c4);
            }
            goto LAB_0032d5e1;
          }
LAB_0032d8b6:
          iVar20 = *(int *)(lVar44 + 0xfc);
          if (local_f8 == iVar20) goto LAB_0032d437;
          uVar24 = gpuGetNv2080EngineType_IMPL(iVar20);
          iVar26 = piVar9[0x20];
          uVar25 = gpuGetNv2080EngineType_IMPL(iVar26);
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x2d7,"kchannelConstruct_IMPL",4,
                       "NVRM: Engine type of channel = 0x%x (0x%x) not compatible with engine type of TSG = 0x%x (0x%x)\n"
                       ,uVar25,iVar26,uVar24,iVar20);
          goto LAB_0032bfa5;
        }
        nvAssertOkFailedNoLog
                  (0x31,"pKernelChannel->pKernelCtxShareApi != NULL",
                   "src/kernel/gpu/fifo/kernel_channel.c",0x2a5);
LAB_0032d1f2:
        bVar46 = false;
        iVar20 = 0x31;
        bVar16 = false;
        bVar17 = false;
      }
LAB_0032ce04:
      rmDeviceGpuLocksRelease(lVar8,0,0);
      goto LAB_0032c1e0;
    }
    uVar40 = 0x1e6;
    pcVar42 = "rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_FIFO)";
  }
  else {
    if ((*(byte *)((long)piVar9 + 0x16) & 0x80) == 0) {
      cVar18 = ctxBufPoolIsScrubSkipped(local_178);
      if (cVar18 != '\0') {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1d1,"kchannelConstruct_IMPL",4,
                     "NVRM: Mismatch between channel and parent TSG\'s policy on skipping scrubber\n"
                    );
        pcVar37 = "is not";
        pcVar42 = "is";
LAB_0032c408:
        iVar20 = 0x1f;
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1d2,"kchannelConstruct_IMPL",4,
                     "NVRM: scrubbing %s skipped for TSG and %s for channel\n",pcVar42,pcVar37);
        bVar46 = false;
        bVar16 = false;
        bVar17 = false;
        goto LAB_0032c1e0;
      }
    }
    else {
      if (*(char *)(param_1 + 0x2ac) != '\x02') {
        iVar20 = 0x1f;
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1be,"kchannelConstruct_IMPL",4,
                     "NVRM: Only kernel priv clients can skip scrubber\n");
        bVar46 = false;
        bVar16 = false;
        bVar17 = false;
        goto LAB_0032c1e0;
      }
      if (*(int *)(lVar44 + 0xf8) == 0) {
        ctxBufPoolSetScrubSkip(local_178,1);
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1c9,"kchannelConstruct_IMPL",1,
                     "NVRM: Skipping scrubber for all allocations on this context\n");
      }
      cVar18 = ctxBufPoolIsScrubSkipped(local_178);
      if (cVar18 != '\x01') {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1d1,"kchannelConstruct_IMPL",4,
                     "NVRM: Mismatch between channel and parent TSG\'s policy on skipping scrubber\n"
                    );
        pcVar37 = "is";
        pcVar42 = pcVar37;
        if (cVar18 == '\0') {
          pcVar42 = "is not";
        }
        goto LAB_0032c408;
      }
    }
    iVar20 = (**(code **)(lVar28 + 0x188))(lVar28,&local_c0,&local_b8,0,0,0);
    uVar40 = 0x1d6;
    pcVar42 = 
    "kfifoGetInstMemInfo_HAL(pKernelFifo, &bufInfo.size, &bufInfo.align, NULL, NULL, NULL)";
    if (iVar20 == 0) {
      local_b0 = local_b0 & 0xffffffff00000000;
      iVar20 = ctxBufPoolReserve(lVar8,local_178,&local_c0,1);
      uVar40 = 0x1da;
      pcVar42 = "ctxBufPoolReserve(pGpu, pChannelBufPool, &bufInfo, 1)";
      if (iVar20 == 0) goto LAB_0032bdcf;
    }
  }
  nvAssertOkFailedNoLog(iVar20,pcVar42,"src/kernel/gpu/fifo/kernel_channel.c",uVar40);
  bVar46 = false;
  bVar16 = false;
  bVar17 = false;
LAB_0032c1e0:
  piVar9[0x3c] = 0;
  piVar9[0x3d] = 0;
  portMemSet(piVar9 + 0x3e,0,0x18);
  portMemSet(piVar9 + 0x44,0,0x18);
  piVar9[0x4a] = 0;
  piVar9[0x4b] = 0;
  portMemSet(piVar1,0,0xc);
  portMemSet(piVar3,0,0xc);
  portMemSet(piVar4,0,0x20);
  if (iVar20 == 0) {
    return 0;
  }
  if (local_d0 != 0) {
    refRemoveDependant(*(undefined8 *)(*(long *)(local_d0 + 0x110) + 0x48),lVar36);
  }
  if (*(long *)(param_1 + 0x2c8) != 0) {
    refRemoveDependant(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x2c8) + 0x110) + 0x48),lVar36)
    ;
  }
  if (local_d8 != 0) {
    refRemoveDependant(local_d8,lVar36);
  }
  if (bVar15) {
    refRemoveDependant(local_e8,lVar36);
  }
  if (bVar46) {
    kchangrpRemoveChannel_IMPL(lVar8,lVar44,param_1);
  }
  *(undefined8 *)(param_1 + 600) = 0;
  *(undefined8 *)(param_1 + 0x278) = 0;
  if (bVar16) {
    lVar36 = gpuGetRpc(lVar8);
    if (lVar36 == 0) {
      iVar20 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x45a);
    }
    else if ((*(char *)(lVar8 + 0x909) == '\0') && (*(char *)(lVar8 + 0x90a) == '\0')) {
      (**(code **)(lVar36 + 0xf0))
                (lVar8,lVar36,uVar5,iVar6,
                 *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10),
                 *(code **)(lVar36 + 0xf0));
    }
    else {
      (**(code **)(lVar8 + 0x3b70))(lVar8 + 0x3b58,uVar5);
    }
  }
  _kchannelFreeHalData(lVar8,param_1);
  if (local_178 != 0) {
    ctxBufPoolRelease(local_178);
  }
  if (bVar15) {
    (**(code **)(local_148 + 0x18))(local_148,uVar5,local_130);
  }
  if (bVar17) {
    (**(code **)(param_1 + 0x1a8))(lVar8,param_1);
    return iVar20;
  }
  return iVar20;
}


// ===== 0032e5e0 kchannelCheckIsUserMode_IMPL =====

bool kchannelCheckIsUserMode_IMPL(long param_1)

{
  return *(byte *)(param_1 + 0x2ac) < 2;
}


// ===== 0032e5f0 kchannelCheckIsKernel_IMPL =====

bool kchannelCheckIsKernel_IMPL(long param_1)

{
  return *(char *)(param_1 + 0x2ac) == '\x02';
}


// ===== 0032e600 kchannelCheckIsAdmin_IMPL =====

undefined4 kchannelCheckIsAdmin_IMPL(long param_1)

{
  int iVar1;
  
  iVar1 = *(byte *)(param_1 + 0x2ac) - 1;
  return CONCAT31((int3)((uint)iVar1 >> 8),(byte)iVar1 < 2);
}


// ===== 0032e620 kchannelIsSchedulable_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchannelIsSchedulable_IMPL(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long *plVar3;
  uint local_2c [3];
  
  local_2c[0] = 0;
  if (*(int *)(*(long *)(*(long *)(param_2 + 0x2b8) + 0x138) + 0x108) != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x815,"kchannelIsSchedulable_IMPL",1,
                 "NVRM: Check for channel schedulability for channel 0x%08x is already performed on guest-RM\n"
                 ,*(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4));
    return 1;
  }
  plVar3 = (long *)__nvoc_dynamicCast(*(undefined8 *)(param_2 + 0x2a0),__nvoc_class_def_OBJGVASPACE)
  ;
  if (plVar3 == (long *)0x0) {
    if (*(char *)(param_1 + 0x490f) == '\0') {
      nvAssertFailedNoLog("pGVAS != NULL || IS_MODS_AMODEL(pGpu)",
                          "src/kernel/gpu/fifo/kernel_channel.c",0x822);
      return 0;
    }
    iVar2 = (**(code **)(param_2 + 0x1e8))(param_1,param_2,local_2c);
    if (iVar2 == 0) {
      return 1;
    }
  }
  else {
    iVar2 = (**(code **)(param_2 + 0x1e8))(param_1,param_2,local_2c);
    if (iVar2 == 0) {
      cVar1 = (**(code **)(*plVar3 + 0x188))(plVar3);
      if (cVar1 == '\0') {
        return 1;
      }
      if (local_2c[0] >> 8 != 0xd334df) {
        return 1;
      }
      if (*(char *)(param_2 + 0x2d6) != '\0') {
        return 1;
      }
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x828,"kchannelIsSchedulable_IMPL",4,
                   "NVRM: Cannot schedule externally-owned channel 0x%08x with unbound allocations!\n"
                   ,*(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4));
      return 0;
    }
  }
  nvAssertFailedNoLog("kchannelGetEngine_HAL(pGpu, pKernelChannel, &engineDesc) == NV_OK",
                      "src/kernel/gpu/fifo/kernel_channel.c",0x824);
  return 0;
}


// ===== 0032e800 kchannelBindToRunlist_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int kchannelBindToRunlist_IMPL(long param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined4 local_3c [3];
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xac5);
    return 0x1f;
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar6 = gpuGetKernelFifoShared_IMPL(lVar3);
  if ((param_3 == -0x6a590b00) || (param_3 == -0x33b3cf00)) {
    return 0;
  }
  if ((*(char *)(lVar3 + 0x909) == '\0') &&
     ((*(char *)(lVar3 + 0x908) == '\0' ||
      (((*(char *)(lVar3 + 0x4913) != '\0' && (*(char *)(lVar3 + 0x491e) == '\0')) &&
       (*(char *)(lVar6 + 0x4b0) != '\0')))))) {
LAB_0032e877:
    iVar5 = (**(code **)(lVar6 + 0x308))(lVar3,lVar6,param_1,param_3);
    if (iVar5 != 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xae9,"kchannelBindToRunlist_IMPL",4,
                   "NVRM: Failed to set RunlistID 0x%08x for channel 0x%08x\n",param_3,
                   *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4));
    }
  }
  else {
    local_3c[0] = gpuGetNv2080EngineType_IMPL(param_2);
    lVar7 = gpuGetRpc(lVar3);
    if (lVar7 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xad8);
      iVar5 = 0x1a;
    }
    else {
      plVar4 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      uVar1 = (undefined4)plVar4[2];
      uVar2 = *(undefined4 *)(*plVar4 + 0x48);
      if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
        iVar5 = rpcDmaControl_wrapper(lVar3,lVar7,uVar2,uVar1,0xa06f0104,local_3c,4);
      }
      else {
        iVar5 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,uVar2,uVar1,0xa06f0104,local_3c,4);
      }
      if (iVar5 == 0) goto LAB_0032e877;
    }
    nvAssertOkFailedNoLog(iVar5,"status","src/kernel/gpu/fifo/kernel_channel.c",0xae0);
  }
  return iVar5;
}


// ===== 0032ea60 kchannelCtrlCmdGetContextId_IMPL =====

undefined8 kchannelCtrlCmdGetContextId_IMPL(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x414);
  return 0;
}


// ===== 0032ea70 kchannelCtrlCmdGetClassEngineid_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kchannelCtrlCmdGetClassEngineid_IMPL(long param_1,int *param_2)

{
  long lVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  char *pcVar10;
  ulong uVar11;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  
  iVar5 = *param_2;
  if (iVar5 == 0) {
    return 0x57;
  }
  if (iVar5 == *(int *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48)) {
    nvCheckFailedNoLog(4,"pParams->hObject != RES_GET_CLIENT_HANDLE(pKernelChannel)",
                       "src/kernel/gpu/fifo/kernel_channel.c",0xb1b);
    return 0x1f;
  }
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if (*(char *)(lVar1 + 0x908) == '\0') {
    if (*(char *)(lVar1 + 0x4913) != '\0') {
LAB_0032eb74:
      if (*(char *)(lVar1 + 0x491e) != '\0') goto LAB_0032eb83;
    }
    uVar8 = *(undefined8 *)(lVar1 + 0x1bc0);
    uVar6 = (**(code **)(param_1 + 0x228))(lVar1,param_1,iVar5,param_2 + 1,param_2 + 2,&local_50);
    uVar9 = 0xb2f;
    pcVar10 = 
    "kchannelGetClassEngineID_HAL(pGpu, pKernelChannel, pParams->hObject, &pParams->classEngineID, &pParams->classID, &rmEngineType)"
    ;
    uVar11 = (ulong)uVar6;
    if (uVar6 == 0) {
      iVar5 = gpuGetNv2080EngineType_IMPL
                        (local_50,
                         "kchannelGetClassEngineID_HAL(pGpu, pKernelChannel, pParams->hObject, &pParams->classEngineID, &pParams->classID, &rmEngineType)"
                         ,"src/kernel/gpu/fifo/kernel_channel.c",0xb2f);
      param_2[3] = iVar5;
      if (*(long *)(lVar1 + 0x1bc0) == 0) {
        return 0;
      }
      cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
      if (cVar4 == '\0') {
        return 0;
      }
      cVar4 = kmigmgrIsEnginePartitionable_IMPL(lVar1,uVar8,local_50);
      if (cVar4 == '\0') {
        return 0;
      }
      uVar6 = kmigmgrGetInstanceRefFromDevice_IMPL
                        (lVar1,uVar8,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),&local_48);
      uVar9 = 0xb3d;
      pcVar10 = 
      "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pKernelChannel), &ref)"
      ;
      uVar11 = (ulong)uVar6;
      if (uVar6 == 0) {
        uVar6 = kmigmgrGetGlobalToLocalEngineType_IMPL
                          (lVar1,uVar8,local_48,local_40,local_50,&local_4c);
        uVar3 = local_4c;
        uVar11 = (ulong)uVar6;
        if (uVar6 == 0) {
          uVar8 = gpuGetNv2080EngineType_IMPL(local_4c);
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xb47,
                       "kchannelCtrlCmdGetClassEngineid_IMPL",1,
                       "NVRM: Overriding global engine type 0x%x to local engine type 0x%x (0x%x) due to MIG\n"
                       ,param_2[3],uVar8,uVar3);
          iVar5 = gpuGetNv2080EngineType_IMPL(local_4c);
          param_2[3] = iVar5;
          return 0;
        }
        uVar9 = 0xb42;
        pcVar10 = 
        "kmigmgrGetGlobalToLocalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &localRmEngineType)"
        ;
      }
    }
    nvAssertOkFailedNoLog(uVar11,pcVar10,"src/kernel/gpu/fifo/kernel_channel.c",uVar9);
  }
  else {
    if (*(char *)(lVar1 + 0x4913) != '\0') goto LAB_0032eb74;
LAB_0032eb83:
    lVar7 = resservGetTlsCallContext();
    puVar2 = *(undefined4 **)(lVar7 + 0x48);
    lVar7 = gpuGetRpc(lVar1);
    if (lVar7 == 0) {
      uVar11 = 0x1a;
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xb25);
    }
    else {
      if ((*(char *)(lVar1 + 0x909) != '\0') || (*(char *)(lVar1 + 0x90a) != '\0')) {
        uVar11 = (**(code **)(lVar1 + 0x3b90))(lVar1 + 0x3b58);
        return uVar11;
      }
      uVar6 = rpcDmaControl_wrapper
                        (lVar1,lVar7,*puVar2,
                         *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10),
                         puVar2[2],*(undefined8 *)(puVar2 + 4),puVar2[6]);
      uVar11 = (ulong)uVar6;
    }
  }
  return uVar11;
}


// ===== 0032edc0 kchannelCtrlCmdResetIsolatedChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r13 replaced with injection: x86_indirect_thunk_r13 */

int kchannelCtrlCmdResetIsolatedChannel_IMPL(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  pcVar3 = *(code **)(lVar2 + 0x3b90);
  uVar1 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10);
  lVar6 = resservGetTlsCallContext();
  iVar4 = (*pcVar3)(lVar2 + 0x3b58,**(undefined4 **)(lVar6 + 0x48),uVar1,0x506f0106,param_2,8);
  if (iVar4 == 0) {
    uVar5 = gpumgrGetSubDeviceInstanceFromGpu(lVar2);
    *(undefined1 *)(param_1 + 0x3dc + (ulong)uVar5) = 0;
  }
  return iVar4;
}


// ===== 0032ee60 kchannelCtrlCmdResetChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchannelCtrlCmdResetChannel_IMPL(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 *puVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar5 = resservGetTlsCallContext();
  puVar3 = *(undefined4 **)(lVar5 + 0x48);
  if ((*(char *)(puVar3 + 0x1a) == '\0') && (3 < *(uint *)(param_2 + 8))) {
    return 0x3b;
  }
  uVar4 = gpumgrGetSubDeviceInstanceFromGpu(lVar2);
  *(undefined1 *)(param_2 + 0xc) = *(undefined1 *)(param_1 + 0x3dc + (ulong)uVar4);
  if ((*(char *)(lVar2 + 0x908) != '\0') || (uVar6 = 0, *(char *)(lVar2 + 0x909) != '\0')) {
    lVar5 = gpuGetRpc(lVar2);
    if (lVar5 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xb93);
      uVar6 = 0x1a;
    }
    else {
      uVar1 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10);
      if ((*(char *)(lVar2 + 0x909) != '\0') || (*(char *)(lVar2 + 0x90a) != '\0')) {
        uVar6 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58,*puVar3,uVar1,0x906f0102,param_2);
        return uVar6;
      }
      uVar6 = rpcDmaControl_wrapper(lVar2,lVar5,*puVar3,uVar1,0x906f0102,param_2,puVar3[6]);
    }
  }
  return uVar6;
}


// ===== 0032efb0 kchannelCtrlCmdGpFifoSchedule_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 kchannelCtrlCmdGpFifoSchedule_IMPL(long param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long *plVar5;
  char cVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar8 = resservGetTlsCallContext();
  lVar8 = *(long *)(lVar8 + 0x48);
  cVar6 = kchannelIsSchedulable_IMPL(lVar4,param_1);
  if (cVar6 != '\x01') {
    nvAssertFailedNoLog("kchannelIsSchedulable_HAL(pGpu, pKernelChannel)",
                        "src/kernel/gpu/fifo/kernel_channel.c",0xbbb);
    return 0x40;
  }
  uVar7 = gpumgrGetSubDeviceInstanceFromGpu(lVar4);
  puVar1 = (uint *)(param_1 + 0x39c + (ulong)uVar7 * 4);
  *puVar1 = *puVar1 | 2;
  if ((*(char *)(lVar4 + 0x908) != '\0') || (uVar10 = 0, *(char *)(lVar4 + 0x909) != '\0')) {
    lVar9 = gpuGetRpc(lVar4);
    if (lVar9 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xbcc);
      uVar10 = 0x1a;
    }
    else {
      plVar5 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      uVar2 = (undefined4)plVar5[2];
      uVar3 = *(undefined4 *)(*plVar5 + 0x48);
      if ((*(char *)(lVar4 + 0x909) != '\0') || (*(char *)(lVar4 + 0x90a) != '\0')) {
        uVar10 = (**(code **)(lVar4 + 0x3b90))(lVar4 + 0x3b58,uVar3,uVar2,0xa06f0103);
        return uVar10;
      }
      uVar10 = rpcDmaControl_wrapper
                         (lVar4,lVar9,uVar3,uVar2,0xa06f0103,*(undefined8 *)(lVar8 + 0x10),
                          *(undefined4 *)(lVar8 + 0x18));
    }
  }
  return uVar10;
}


// ===== 0032f110 kchannelCtrlCmdSetErrorNotifier_IMPL =====

void kchannelCtrlCmdSetErrorNotifier_IMPL(long param_1,char *param_2)

{
  long lVar1;
  char *pcVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  pcVar2 = "false";
  if (*param_2 != '\0') {
    pcVar2 = "true";
  }
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xbec,"kchannelCtrlCmdSetErrorNotifier_IMPL",1
               ,"NVRM: calling setErrorNotifier on channel 0x%08x, broadcast to TSG: %s\n",
               *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4),pcVar2);
  krcErrorSetNotifier_IMPL
            (lVar1,*(undefined8 *)(lVar1 + 0x1c18),param_1,0xd,*(undefined4 *)(param_1 + 0x42c),
             *param_2 != '\0');
  return;
}


// ===== 0032f1c0 kchannelCtrlCmdBind_IMPL =====

ulong kchannelCtrlCmdBind_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  ulong uVar7;
  char *pcVar8;
  undefined8 uVar9;
  bool bVar10;
  undefined8 uStack_60;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 local_30;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((lVar1 == 0) || (*(long *)(lVar1 + 0x1bc0) == 0)) {
    bVar10 = false;
  }
  else {
    cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    bVar10 = cVar4 != '\0';
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0x1f;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0x2b8) + 0x138);
  if (*(char *)(lVar2 + 0x158) == '\0') {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xc15,"kchannelCtrlCmdBind_IMPL",1,
                 "NVRM: Bind requested for channel 0x%08x belonging to TSG %d.\n",
                 *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4),
                 *(undefined4 *)(lVar2 + 0xf0));
  }
  uStack_60 = 0x32f24c;
  uVar5 = gpuGetRmEngineType_IMPL(*param_2);
  local_3c = uVar5;
  if (bVar10) {
    uVar3 = *(undefined8 *)(lVar1 + 0x1bc0);
    uVar6 = kmigmgrGetInstanceRefFromDevice_IMPL
                      (lVar1,uVar3,*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe8),&local_38);
    uVar9 = 0xc22;
    pcVar8 = 
    "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, GPU_RES_GET_DEVICE(pKernelChannel), &ref)"
    ;
    if (uVar6 == 0) {
      uStack_60 = 0x32f33b;
      uVar6 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (lVar1,uVar3,CONCAT44(uStack_34,local_38),local_30,uVar5,&local_3c);
      if (uVar6 == 0) goto LAB_0032f261;
      uVar9 = 0xc27;
      pcVar8 = 
      "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, localRmEngineType, &globalRmEngineType)"
      ;
    }
    nvCheckOkFailedNoLog(4,uVar6,pcVar8,"src/kernel/gpu/fifo/kernel_channel.c",uVar9);
    uVar7 = (ulong)uVar6;
  }
  else {
LAB_0032f261:
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xc2d,"kchannelCtrlCmdBind_IMPL",1,
                 "NVRM: Binding channel 0x%08x to Engine %d\n",
                 *(int *)(param_1 + 0x2b0) << 0x18 | *(uint *)(param_1 + 0x2b4),local_3c);
    uVar6 = gpuXlateClientEngineIdToEngDesc_IMPL(lVar1,local_3c,&local_38);
    if (uVar6 == 0) {
      uVar7 = kchannelBindToRunlist_IMPL(param_1,uVar5,local_38,uStack_60);
      if ((int)uVar7 != 0) {
        nvAssertOkFailedNoLog
                  (uVar7 & 0xffffffff,
                   "kchannelBindToRunlist(pKernelChannel, localRmEngineType, engineDesc)",
                   "src/kernel/gpu/fifo/kernel_channel.c",0xc38);
        uVar7 = uVar7 & 0xffffffff;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (uVar6,"gpuXlateClientEngineIdToEngDesc(pGpu, globalRmEngineType, &engineDesc)",
                 "src/kernel/gpu/fifo/kernel_channel.c",0xc33);
      uVar7 = (ulong)uVar6;
    }
  }
  return uVar7;
}


// ===== 0032f420 kchannelCtrlCmdSetInterleaveLevel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

undefined8 kchannelCtrlCmdSetInterleaveLevel_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  if ((*(char *)(lVar2 + 0x908) == '\0') && (*(char *)(lVar2 + 0x909) == '\0')) {
LAB_0032f4c6:
    uVar7 = kchangrpSetInterleaveLevel_IMPL
                      (lVar2,*(undefined8 *)(*(long *)(param_1 + 0x2b8) + 0x138),*param_2);
    return uVar7;
  }
  lVar5 = resservGetTlsCallContext();
  lVar5 = *(long *)(lVar5 + 0x48);
  lVar6 = gpuGetRpc(lVar2);
  if (lVar6 == 0) {
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xc4e);
  }
  else {
    plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
    uVar1 = *(undefined4 *)(*plVar3 + 0x48);
    if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')) {
      iVar4 = rpcDmaControl_wrapper
                        (lVar2,lVar6,uVar1,(int)plVar3[2],*(undefined4 *)(lVar5 + 8),
                         *(undefined8 *)(lVar5 + 0x10),*(undefined4 *)(lVar5 + 0x18));
    }
    else {
      iVar4 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58,uVar1);
    }
    if (iVar4 == 0) goto LAB_0032f4c6;
  }
  nvCheckFailedNoLog(1,"status == NV_OK","src/kernel/gpu/fifo/kernel_channel.c",0xc55);
  return 0x56;
}


// ===== 0032f570 kchannelCtrlCmdGpfifoGetWorkSubmitToken_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kchannelCtrlCmdGpfifoGetWorkSubmitToken_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 *puVar4;
  code *pcVar5;
  char cVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar8 = gpuGetKernelFifoShared_IMPL(lVar3);
  lVar9 = resservGetTlsCallContext();
  if (lVar3 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)invalidInstructionException();
    (*pcVar5)();
  }
  puVar4 = *(undefined4 **)(lVar9 + 0x48);
  if (*(long *)(lVar3 + 0x1bc0) == 0) {
    cVar1 = *(char *)(lVar3 + 0x908);
joined_r0x0032f667:
    if ((cVar1 == '\0') ||
       ((*(char *)(lVar3 + 0x4913) != '\0' && (*(char *)(lVar8 + 0x4b0) != '\0'))))
    goto LAB_0032f5f0;
  }
  else {
    cVar6 = kmigmgrIsMIGEnabled_IMPL(lVar3);
    cVar1 = *(char *)(lVar3 + 0x908);
    if (cVar6 == '\0') goto joined_r0x0032f667;
    if (cVar1 == '\0') goto LAB_0032f5f0;
  }
  if (*(char *)(lVar8 + 0x4b5) == '\0') {
    lVar9 = gpuGetRpc(lVar3);
    if (lVar9 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xc8a);
      return 0x1a;
    }
    uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10);
    if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
      uVar10 = rpcDmaControl_wrapper
                         (lVar3,lVar9,*puVar4,uVar2,puVar4[2],*(undefined8 *)(puVar4 + 4),puVar4[6])
      ;
    }
    else {
      uVar10 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,*puVar4,uVar2);
    }
    if ((int)uVar10 != 0) {
      return uVar10;
    }
    if (*(char *)(lVar3 + 0x908) != '\0') {
      return uVar10;
    }
  }
LAB_0032f5f0:
  if (*(long *)(param_1 + 0x2b8) == 0) {
    nvAssertFailedNoLog("pKernelChannel->pKernelChannelGroupApi != NULL",
                        "src/kernel/gpu/fifo/kernel_channel.c",0xca3);
  }
  else {
    lVar9 = *(long *)(*(long *)(param_1 + 0x2b8) + 0x138);
    if (lVar9 != 0) {
      uVar7 = kfifoGenerateWorkSubmitToken_IMPL
                        (lVar3,lVar8,param_1,param_2,*(undefined1 *)(lVar9 + 0x1f0));
      if (uVar7 != 0) {
        nvCheckOkFailedNoLog
                  (1,uVar7,
                   "kfifoGenerateWorkSubmitToken(pGpu, pKernelFifo, pKernelChannel, &pTokenParams->workSubmitToken, pKernelChannelGroup->bIsCallingContextVgpuPlugin)"
                   ,"src/kernel/gpu/fifo/kernel_channel.c",0xca8);
        return (ulong)uVar7;
      }
      uVar10 = kchannelUpdateNotifierMem_IMPL
                         (param_1,*(undefined4 *)(param_1 + 0x3f4),*param_2,0,0xffff);
      return uVar10;
    }
    nvAssertFailedNoLog("pKernelChannelGroup != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xca6);
  }
  return 0x40;
}


// ===== 0032f820 kchannelRegisterChild_IMPL =====

undefined8 kchannelRegisterChild_IMPL(long param_1,long param_2)

{
  short sVar1;
  undefined8 uVar2;
  long *plVar3;
  char cVar4;
  short sVar5;
  short sVar6;
  long lVar7;
  long lVar8;
  undefined1 local_258 [280];
  undefined1 local_140 [256];
  long local_40;
  
  gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  if (*(int *)(param_2 + 0x184) == -0x6a590b00) {
    lVar8 = *(long *)(param_1 + 0x140);
    sVar1 = *(short *)(param_1 + 0x238);
    uVar2 = **(undefined8 **)(lVar8 + 0x48);
    sVar5 = sVar1 + 1;
    *(short *)(param_1 + 0x238) = sVar5;
    sVar6 = 0;
    if (sVar5 != 0) {
      lVar7 = 0;
      while( true ) {
        clientRefOrderedIter(local_258,uVar2,*(undefined8 *)(lVar8 + 0x48),0x43d7c4,0);
        memcpy(local_140,local_258,0x108);
        while (cVar4 = clientRefOrderedIterNext(uVar2,local_140), cVar4 != '\0') {
          lVar7 = __nvoc_dynamicCast(*(undefined8 *)(local_40 + 8),
                                     __nvoc_class_def_ChannelDescendant);
          if (lVar7 == 0) {
            lVar7 = 0;
            nvAssertFailedNoLog("pMatchingObject != NULL","src/kernel/gpu/fifo/kernel_channel.c",
                                0xd0a);
          }
          else {
            if ((*(int *)(lVar7 + 0x184) == -0x6a590b00) &&
               (sVar6 = *(short *)(param_1 + 0x238), *(short *)(lVar7 + 0x188) == sVar6))
            goto LAB_0032f960;
            lVar7 = 0;
          }
        }
        sVar6 = *(short *)(param_1 + 0x238);
        if (lVar7 == 0) break;
LAB_0032f960:
        do {
          sVar5 = sVar6 + 1;
          *(short *)(param_1 + 0x238) = sVar5;
          if (sVar1 == sVar5) {
            plVar3 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xcfe,"kchannelRegisterChild_IMPL",4
                         ,"NVRM: channel %08x:%08x: out of handles!\n",
                         *(undefined4 *)(*plVar3 + 0x48),(int)plVar3[2]);
            return 0x1a;
          }
          sVar6 = 0;
        } while (sVar5 == 0);
        lVar8 = *(long *)(param_1 + 0x140);
      }
    }
    *(short *)(param_2 + 0x188) = sVar6;
  }
  return 0;
}


// ===== 0032fa30 kchannelDeregisterChild_IMPL =====

undefined8 kchannelDeregisterChild_IMPL(long param_1)

{
  gpuGetKernelFifoShared_IMPL(*(undefined8 *)(*(long *)(param_1 + 0x158) + 0xe0));
  return 0;
}


// ===== 0032fa50 kchannelFindChildByHandle =====

int kchannelFindChildByHandle(long param_1,undefined8 param_2,long *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long local_30 [2];
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)invalidInstructionException();
    (*pcVar1)();
  }
  local_30[0] = 0;
  iVar2 = clientGetResourceRef_IMPL
                    (**(undefined8 **)(*(long *)(param_1 + 0x140) + 0x48),param_2,local_30);
  if (iVar2 == 0) {
    if (*(int *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10) ==
        *(int *)(*(long *)(local_30[0] + 0x18) + 0x10)) {
      lVar3 = __nvoc_dynamicCast(*(undefined8 *)(local_30[0] + 8),__nvoc_class_def_ChannelDescendant
                                );
      *param_3 = lVar3;
      if (lVar3 != 0) {
        return 0;
      }
      nvCheckFailedNoLog(4,"*ppObject != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xdd6);
    }
    else {
      nvCheckFailedNoLog(4,"pResourceRef->pParentRef->hResource == RES_GET_HANDLE(pKernelChannel)",
                         "src/kernel/gpu/fifo/kernel_channel.c",0xdd3);
    }
    return 0x57;
  }
  nvCheckOkFailedNoLog
            (4,iVar2,"clientGetResourceRef(pClient, hResource, &pResourceRef)",
             "src/kernel/gpu/fifo/kernel_channel.c",0xdd1);
  return iVar2;
}


// ===== 0032fb80 kchannelCheckBcStateCurrent_IMPL =====

undefined8 kchannelCheckBcStateCurrent_IMPL(long param_1,long param_2)

{
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xe9e,"kchannelCheckBcStateCurrent_IMPL",1,
               "NVRM: GPU = %d, channel 0x%08x, bcStateCurrent = %d, channelBcStateEnum = %d\n",
               *(undefined4 *)(param_1 + 0x7a4),
               *(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4),
               *(undefined4 *)(param_2 + 0x3ec),1);
  if (*(int *)(param_2 + 0x3ec) == 0) {
    *(undefined4 *)(param_2 + 0x3ec) = 1;
    return 0;
  }
  if (*(int *)(param_2 + 0x3ec) == 1) {
    return 0;
  }
  nvAssertFailedNoLog("pKernelChannel->bcStateCurrent == channelBcStateEnum",
                      "src/kernel/gpu/fifo/kernel_channel.c",0xeaa);
  return 0x40;
}


// ===== 0032fc30 kchannelSetEngineContextMemDesc_IMPL =====

int kchannelSetEngineContextMemDesc_IMPL
              (undefined8 param_1,long param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  long *plVar6;
  
  lVar1 = *(long *)(*(long *)(param_2 + 0x2b8) + 0x138);
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xe12,"kchannelSetEngineContextMemDesc_IMPL",1
               ,"NVRM: channel 0x%08x engDesc 0x%x pMemDesc %p\n",
               *(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4),param_3);
  if ((int)param_3 == -0x4fdc9b00) {
    nvAssertFailedNoLog("engDesc != ENG_FIFO","src/kernel/gpu/fifo/kernel_channel.c",0xe16);
    return 0x3b;
  }
  if ((((uint)((ulong)param_3 >> 8) & 0xffffff) == 0xd334df) &&
     (iVar4 = kchannelCheckBcStateCurrent_IMPL(param_1,param_2,param_4), iVar4 != 0)) {
    nvAssertOkFailedNoLog
              (0x40,"kchannelCheckBcStateCurrent(pGpu, pKernelChannel)",
               "src/kernel/gpu/fifo/kernel_channel.c",0xe1a);
    return 0x40;
  }
  lVar2 = *(long *)(lVar1 + 0x150);
  uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  plVar6 = *(long **)(lVar2 + (ulong)uVar3 * 8);
  if (param_4 != 0 || plVar6 != (long *)0x0) {
    if (plVar6 == (long *)0x0) {
      iVar4 = kchangrpAllocEngineContextDescriptor_IMPL(param_1,lVar1);
      if (iVar4 != 0) {
        nvAssertOkFailedNoLog
                  (iVar4,"kchangrpAllocEngineContextDescriptor(pGpu, pKernelChannelGroup)",
                   "src/kernel/gpu/fifo/kernel_channel.c",0xe35);
        return iVar4;
      }
      lVar1 = *(long *)(lVar1 + 0x150);
      uVar3 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
      plVar6 = *(long **)(lVar1 + (ulong)uVar3 * 8);
      if (plVar6 == (long *)0x0) {
        nvAssertFailedNoLog("pEngCtxDesc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xe39);
        return 0x51;
      }
    }
    else if (*plVar6 != 0) {
      memdescFree();
      memdescDestroy(*plVar6);
    }
    if (param_4 != 0) {
      if (*(char *)(param_4 + 100) != '\0') {
        *(char *)(param_4 + 100) = *(char *)(param_4 + 100) + '\x01';
      }
      memdescAddRef(param_4);
      iVar4 = memdescGetAddressSpace(param_4);
      if (iVar4 == 4) {
        iVar4 = vaListSetManaged(plVar6 + 1,0);
        if (iVar4 != 0) {
          uVar5 = 0xe49;
LAB_0032fe6d:
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel.c",uVar5);
          return iVar4;
        }
        uVar5 = memdescGetPhysAddr(param_4,1,0);
        iVar4 = vaListAddVa(plVar6 + 1,*(undefined8 *)(param_2 + 0x2a0),uVar5);
        if (iVar4 != 0) {
          uVar5 = 0xe4e;
          goto LAB_0032fe6d;
        }
      }
    }
    *plVar6 = param_4;
    *(int *)(plVar6 + 9) = (int)param_3;
  }
  return 0;
}


// ===== 0032fed0 kchannelUnmapEngineCtxBuf_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchannelUnmapEngineCtxBuf_IMPL(long param_1,long param_2,uint param_3)

{
  long *plVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  long *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  if (param_2 == 0) {
    uVar9 = 0xffffffff;
  }
  else {
    uVar9 = *(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4);
  }
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xe70,"kchannelUnmapEngineCtxBuf_IMPL",1,
               "NVRM: channel 0x%08x engDesc 0x%x\n",uVar9);
  if (param_3 == 0xb0236500) {
    nvAssertFailedNoLog("engDesc != ENG_FIFO","src/kernel/gpu/fifo/kernel_channel.c",0xe75,
                        0xb0236500);
    return 0x3b;
  }
  if ((param_3 >> 8 == 0xd334df) &&
     (iVar3 = kchannelCheckBcStateCurrent_IMPL(param_1,param_2), iVar3 != 0)) {
    nvAssertOkFailedNoLog
              (0x40,"kchannelCheckBcStateCurrent(pGpu, pKernelChannel)",
               "src/kernel/gpu/fifo/kernel_channel.c",0xe79);
    uVar5 = 0x40;
  }
  else {
    lVar8 = *(long *)(*(long *)(*(long *)(param_2 + 0x2b8) + 0x138) + 0x150);
    uVar9 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    plVar1 = *(long **)(lVar8 + (ulong)uVar9 * 8);
    if ((plVar1 != (long *)0x0) && (*plVar1 != 0)) {
      cVar2 = vaListGetManaged(plVar1 + 1);
      if (cVar2 != '\0') {
        if ((int)plVar1[1] == 0) {
          if (plVar1[3] == 0) {
            lVar7 = plVar1[6];
            lVar8 = plVar1[7];
            goto LAB_0032ffe2;
          }
          lVar8 = plVar1[4];
          lVar4 = plVar1[3];
          do {
            while ((**(code **)(*(long *)(param_1 + 0x1bb8) + 0x1b0))
                             (param_1,*(long *)(param_1 + 0x1bb8),lVar4,lVar8), (int)plVar1[1] != 0)
            {
              cVar2 = mapIterNext_IMPL(&local_58);
              if ((cVar2 == '\0') || (local_58 == (long *)0x0)) goto LAB_00330040;
              lVar8 = *local_58;
              lVar4 = mapKey_IMPL(plVar1 + 2);
              if (lVar4 == 0) goto LAB_00330040;
            }
            lVar7 = plVar1[6];
            if (lVar4 == lVar7) break;
            lVar8 = plVar1[7];
LAB_0032ffe2:
            lVar4 = lVar7;
          } while (lVar7 != 0);
        }
        else {
          uVar5 = mapFindLEQ_IMPL(plVar1 + 2,0xffffffffffffffff);
          uVar6 = mapFindGEQ_IMPL(plVar1 + 2,0);
          mapIterRange_IMPL(&local_78,plVar1 + 2,uVar6,uVar5);
          local_58 = local_78;
          local_50 = local_70;
          local_48 = local_68;
          local_40 = local_60;
          cVar2 = mapIterNext_IMPL(&local_58);
          if (((cVar2 != '\0') && (cVar2 = mapIterNext_IMPL(&local_58), cVar2 != '\0')) &&
             (local_58 != (long *)0x0)) {
            lVar8 = *local_58;
            lVar7 = mapKey_IMPL(plVar1 + 2);
            goto LAB_0032ffe2;
          }
        }
      }
LAB_00330040:
      vaListClear(plVar1 + 1);
    }
    uVar5 = 0;
  }
  return uVar5;
}


// ===== 003301a0 kchannelMapEngineCtxBuf_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */
/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelMapEngineCtxBuf_IMPL(long param_1,long param_2,ulong param_3)

{
  undefined8 uVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined4 local_44;
  undefined8 local_40 [2];
  
  lVar5 = gpuGetKernelFifoShared_IMPL();
  if ((int)param_3 == -0x4fdc9b00) {
    nvAssertFailedNoLog("engDesc != ENG_FIFO","src/kernel/gpu/fifo/kernel_channel.c",0xec0);
    iVar4 = 0x1f;
  }
  else {
    if ((((uint)(param_3 >> 8) & 0xffffff) == 0xd334df) &&
       (iVar4 = kchannelCheckBcStateCurrent_IMPL(param_1,param_2), iVar4 != 0)) {
      nvAssertOkFailedNoLog
                (0x40,"kchannelCheckBcStateCurrent(pGpu, pKernelChannel)",
                 "src/kernel/gpu/fifo/kernel_channel.c",0xec4);
    }
    else {
      lVar6 = gpuGetKernelFifoShared_IMPL(param_1);
      uVar9 = (**(code **)(lVar6 + 0x248))(lVar6,0,param_3 & 0xffffffff,*(code **)(lVar6 + 0x248));
      if (param_2 == 0) {
        uVar8 = 0xffffffff;
      }
      else {
        uVar8 = *(int *)(param_2 + 0x2b0) << 0x18 | *(uint *)(param_2 + 0x2b4);
      }
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xec7,"kchannelMapEngineCtxBuf_IMPL",1,
                   "NVRM: channel 0x%08x engDesc %s (0x%x) \n",uVar8,uVar9,param_3 & 0xffffffff);
      uVar1 = *(undefined8 *)(param_2 + 0x2a0);
      plVar7 = (long *)__nvoc_dynamicCast(uVar1,__nvoc_class_def_OBJGVASPACE);
      if (plVar7 == (long *)0x0) {
        nvAssertFailedNoLog("pGVAS != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xed1);
      }
      else {
        lVar6 = *(long *)(*(long *)(*(long *)(param_2 + 0x2b8) + 0x138) + 0x150);
        uVar8 = gpumgrGetSubDeviceInstanceFromGpu(param_1,uVar9);
        plVar2 = *(long **)(lVar6 + (ulong)uVar8 * 8);
        if (plVar2 == (long *)0x0) {
          nvAssertFailedNoLog("pEngCtx != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xed6);
        }
        else {
          lVar6 = *plVar2;
          if (lVar6 != 0) {
            iVar4 = vaListFindVa(plVar2 + 1,uVar1,local_40);
            if (iVar4 == 0) {
              return 0;
            }
            if (iVar4 != 0x57) {
              nvAssertOkFailedNoLog
                        (iVar4,"vaListFindVa","src/kernel/gpu/fifo/kernel_channel.c",0xf06);
              return iVar4;
            }
            local_44 = 0;
            cVar3 = (**(code **)(*plVar7 + 0x188))(plVar7);
            if (cVar3 != '\0') {
              nvAssertFailedNoLog("Externally owned object not found",
                                  "src/kernel/gpu/fifo/kernel_channel.c",0xeed);
              return 0x38;
            }
            uVar9 = 0x33031c;
            (**(code **)(lVar5 + 0x210))(param_1,lVar5,param_3 & 0xffffffff,&local_44);
            iVar4 = (**(code **)(*(long *)(param_1 + 0x1bb8) + 0x1a8))
                              (param_1,*(long *)(param_1 + 0x1bb8),uVar1,lVar6,local_40,local_44,
                               *(undefined4 *)(param_2 + 0x430));
            if (iVar4 == 0) {
              iVar4 = vaListAddVa(plVar2 + 1,uVar1,local_40[0],uVar9);
              if (iVar4 == 0) {
                return 0;
              }
              nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel.c",0xf01);
              return iVar4;
            }
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0xef9,"kchannelMapEngineCtxBuf_IMPL"
                         ,4,"NVRM: Could not map context buffer for engDesc 0x%x\n",
                         param_3 & 0xffffffff);
            return iVar4;
          }
          nvAssertFailedNoLog("pTempMemDesc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xed9);
        }
      }
    }
    iVar4 = 0x40;
  }
  return iVar4;
}


// ===== 00330553 kchannelUpdateWorkSubmitTokenNotifIndex_IMPL.cold =====

void kchannelUpdateWorkSubmitTokenNotifIndex_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00330570 kchannelUpdateWorkSubmitTokenNotifIndex_IMPL =====

undefined8 kchannelUpdateWorkSubmitTokenNotifIndex_IMPL(long param_1,long param_2,int param_3)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  long local_48;
  long local_40 [2];
  
  if (param_2 != 0) {
    if (param_3 == 0) {
      nvCheckFailedNoLog(1,"index != NV_CHANNELGPFIFO_NOTIFICATION_TYPE_ERROR",
                         "src/kernel/gpu/fifo/kernel_channel.c",0xf32);
      return 0x1f;
    }
    if (((*(long *)(param_1 + 0x1d18) != 0) &&
        (*(char *)(*(long *)(param_1 + 0x1d18) + 0x2b0) != '\0')) && (param_3 == 2)) {
      nvCheckFailedNoLog(4,"index != NV_CHANNELGPFIFO_NOTIFICATION_TYPE_KEY_ROTATION_STATUS",
                         "src/kernel/gpu/fifo/kernel_channel.c",0xf3a);
      return 0x1f;
    }
    if (param_3 == -1) {
      return 0x5b;
    }
    uVar7 = *(undefined4 *)(param_2 + 0x250);
    uVar9 = (ulong)(param_3 + 1) * 0x10;
    uVar1 = **(undefined8 **)(*(long *)(param_2 + 0x140) + 0x48);
    lVar2 = *(long *)(*(long *)(param_2 + 0x158) + 0xe8);
    if (lVar2 != 0) {
      iVar5 = memGetByHandleAndDevice_IMPL
                        (uVar1,uVar7,
                         *(undefined4 *)(*(long *)(*(long *)(lVar2 + 0x110) + 0x48) + 0x10),
                         &local_48);
      if (iVar5 == 0) {
        uVar6 = memdescGetAddressSpace(*(undefined8 *)(local_48 + 0x118),uVar7);
        if (*(ulong *)(local_48 + 0x100) < uVar9) {
          nvCheckFailedNoLog(1,"pMemory->Length >= notificationBufferSize",
                             "src/kernel/gpu/fifo/kernel_channel.c",0xf4b);
          return 0x5b;
        }
        if (uVar6 < 3) {
          if (uVar6 == 0) {
            return 0x56;
          }
        }
        else {
          if (uVar6 != 4) {
            return 0x56;
          }
          uVar8 = memdescGetPhysAddr(*(undefined8 *)(local_48 + 0x118),3,0);
          uVar7 = gpumgrGetDeviceGpuMask(*(undefined4 *)(param_1 + 0x7b4));
          if (local_48 == 0) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)invalidInstructionException();
            (*pcVar3)();
          }
          cVar4 = CliGetDmaMappingInfo
                            (uVar1,*(undefined4 *)
                                    (*(long *)(*(long *)(lVar2 + 0x110) + 0x48) + 0x10),
                             *(undefined4 *)(*(long *)(*(long *)(local_48 + 0xb8) + 0x48) + 0x10),
                             uVar8,uVar7,local_40);
          if (cVar4 == '\0') {
            nvCheckFailedNoLog(1,
                               "CliGetDmaMappingInfo(pClient, RES_GET_HANDLE(pDevice), RES_GET_HANDLE(pMemory), physAddr, gpumgrGetDeviceGpuMask(pGpu->deviceInstance), &pDmaMappingInfo)"
                               ,"src/kernel/gpu/fifo/kernel_channel.c",0xf54);
            return 0xffff;
          }
          if (*(ulong *)(*(long *)(local_40[0] + 0xd0) + 0x30) < uVar9) {
            nvCheckFailedNoLog(1,"pDmaMappingInfo->pMemDesc->Size >= notificationBufferSize",
                               "src/kernel/gpu/fifo/kernel_channel.c",0xf5d);
            return 0x5b;
          }
        }
      }
      else {
        iVar5 = ctxdmaGetByHandle_IMPL(uVar1,uVar7,local_40);
        if (iVar5 != 0) {
          return 0x57;
        }
        if (*(ulong *)(local_40[0] + 0x130) < uVar9 - 1) {
          nvCheckFailedNoLog(1,"pContextDma->Limit >= (notificationBufferSize - 1)",
                             "src/kernel/gpu/fifo/kernel_channel.c",0xf6c);
          return 0x5b;
        }
      }
      *(int *)(param_2 + 0x3f4) = param_3;
      return 0;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)invalidInstructionException();
  (*pcVar3)();
}


// ===== 00330850 kchannelCtrlCmdGpfifoSetWorkSubmitTokenNotifIndex_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchannelCtrlCmdGpfifoSetWorkSubmitTokenNotifIndex_IMPL(long param_1,undefined4 *param_2)

{
  char cVar1;
  long lVar2;
  undefined4 *puVar3;
  code *pcVar4;
  char cVar5;
  long lVar6;
  undefined8 uVar7;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar6 = gpuGetKernelFifoShared_IMPL(lVar2);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)invalidInstructionException();
    (*pcVar4)();
  }
  if (*(long *)(lVar2 + 0x1bc0) == 0) {
    cVar1 = *(char *)(lVar2 + 0x908);
joined_r0x003308df:
    if ((cVar1 == '\0') ||
       ((*(char *)(lVar2 + 0x4913) != '\0' && (*(char *)(lVar6 + 0x4b0) != '\0'))))
    goto LAB_003308b9;
  }
  else {
    cVar5 = kmigmgrIsMIGEnabled_IMPL(lVar2);
    cVar1 = *(char *)(lVar2 + 0x908);
    if (cVar5 == '\0') goto joined_r0x003308df;
    if (cVar1 == '\0') goto LAB_003308b9;
  }
  if (*(char *)(lVar6 + 0x4b5) == '\0') {
    lVar6 = resservGetTlsCallContext();
    puVar3 = *(undefined4 **)(lVar6 + 0x48);
    lVar6 = gpuGetRpc(lVar2);
    if (lVar6 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0xcd1);
      uVar7 = 0x1a;
    }
    else {
      if ((*(char *)(lVar2 + 0x909) != '\0') || (*(char *)(lVar2 + 0x90a) != '\0')) {
        uVar7 = (**(code **)(lVar2 + 0x3b90))(lVar2 + 0x3b58);
        return uVar7;
      }
      uVar7 = rpcDmaControl_wrapper
                        (lVar2,lVar6,*puVar3,
                         *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x140) + 0x48) + 0x10),
                         puVar3[2],*(undefined8 *)(puVar3 + 4),puVar3[6]);
    }
    return uVar7;
  }
LAB_003308b9:
  uVar7 = kchannelUpdateWorkSubmitTokenNotifIndex_IMPL(lVar2,param_1,*param_2);
  return uVar7;
}


// ===== 003309c0 kchannelGetGfid_IMPL =====

undefined4 kchannelGetGfid_IMPL(long param_1)

{
  return *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x2b8) + 0x138) + 0x108);
}


// ===== 003309e0 kchannelIsCpuMapped =====

uint kchannelIsCpuMapped(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu();
  return *(uint *)(param_2 + 0x39c + (ulong)uVar1 * 4) & 1;
}


// ===== 00330a10 kchannelSetCpuMapped =====

void kchannelSetCpuMapped(undefined8 param_1,long param_2,char param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_3 != '\0') {
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
    puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
    *puVar1 = *puVar1 | 1;
    return;
  }
  uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
  puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
  *puVar1 = *puVar1 & 0xfffffffe;
  return;
}


// ===== 00330a60 kchannelIsRunlistSet =====

byte kchannelIsRunlistSet(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu();
  return *(byte *)(param_2 + 0x39c + (ulong)uVar1 * 4) >> 1 & 1;
}


// ===== 00330a90 kchannelSetRunlistSet =====

void kchannelSetRunlistSet(undefined8 param_1,long param_2,char param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_3 != '\0') {
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
    puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
    *puVar1 = *puVar1 | 2;
    return;
  }
  uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
  puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
  *puVar1 = *puVar1 & 0xfffffffd;
  return;
}


// ===== 00330ae0 kchannelGetChannelPhysicalState_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kchannelGetChannelPhysicalState_KERNEL(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  long lVar2;
  ulong uVar3;
  
  lVar2 = resservGetTlsCallContext();
  puVar1 = *(undefined4 **)(*(long *)(lVar2 + 0x48) + 0x70);
  uVar3 = (**(code **)(param_1 + 0x3b90))
                    (param_1 + 0x3b58,*puVar1,puVar1[1],0x208f0403,param_3,0x10);
  if ((int)uVar3 == 0) {
    return uVar3;
  }
  nvAssertOkFailedNoLog
            (uVar3 & 0xffffffff,
             "pRmApi->Control(pRmApi, pRmCtrlParams->hClient, pRmCtrlParams->hObject, NV208F_CTRL_CMD_FIFO_GET_CHANNEL_STATE, pChannelStateParams, sizeof(*pChannelStateParams))"
             ,"src/kernel/gpu/fifo/kernel_channel.c",0x100f);
  return uVar3 & 0xffffffff;
}


// ===== 00330b70 kchannelGetFromDualHandle_IMPL =====

undefined4 kchannelGetFromDualHandle_IMPL(long param_1,ulong param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  long local_28;
  long local_20;
  
  if (param_3 == (long *)0x0) {
    nvAssertFailedNoLog("ppKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x103e);
    return 0x1f;
  }
  *param_3 = 0;
  iVar1 = CliGetKernelChannel(param_1,param_2,&local_28);
  if (iVar1 != 0) {
    iVar1 = CliGetChannelGroup(*(undefined4 *)(param_1 + 0x48),param_2 & 0xffffffff,&local_20,0);
    if (iVar1 != 0) {
      return 0x57;
    }
    lVar2 = __nvoc_dynamicCast(*(undefined8 *)(local_20 + 8),__nvoc_class_def_KernelChannelGroupApi)
    ;
    if ((lVar2 == 0) || (lVar2 = *(long *)(lVar2 + 0x138), lVar2 == 0)) {
      nvAssertFailedNoLog("(pKernelChannelGroupApi != NULL) && (pKernelChannelGroupApi->pKernelChannelGroup != NULL)"
                          ,"src/kernel/gpu/fifo/kernel_channel.c",0x104e);
    }
    else if (*(int *)(lVar2 + 0xf8) != 0) {
      lVar2 = *(long *)**(undefined8 **)(lVar2 + 0x140);
      *param_3 = lVar2;
      if (lVar2 == 0) {
        nvAssertFailedNoLog("*ppKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x1058
                           );
        return 0x40;
      }
      return 0;
    }
    return 0x1f;
  }
  *param_3 = local_28;
  return 0;
}


// ===== 00330cda kchannelGetFromDualHandleRestricted_IMPL.cold =====

void kchannelGetFromDualHandleRestricted_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00330cf0 kchannelGetFromDualHandleRestricted_IMPL =====

ulong kchannelGetFromDualHandleRestricted_IMPL(undefined8 param_1,int param_2,long *param_3)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  
  uVar3 = kchannelGetFromDualHandle_IMPL();
  if ((int)uVar3 != 0) {
    nvCheckOkFailedNoLog
              (4,uVar3 & 0xffffffff,"kchannelGetFromDualHandle(pClient, hDual, ppKernelChannel)",
               "src/kernel/gpu/fifo/kernel_channel.c",0x1071);
    return uVar3 & 0xffffffff;
  }
  lVar1 = *param_3;
  if (lVar1 != 0) {
    if (((*(int *)(*(long *)(*(long *)(lVar1 + 0x140) + 0x48) + 0x10) == param_2) &&
        (lVar1 = *(long *)(*(long *)(lVar1 + 0x2b8) + 0x138), lVar1 != 0)) &&
       (*(char *)(lVar1 + 0x158) == '\0')) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1077,
                   "kchannelGetFromDualHandleRestricted_IMPL",4,
                   "NVRM: channel handle 0x%08x is part of a channel group, not allowed!\n",param_2)
      ;
      return 0x1f;
    }
    return uVar3;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)invalidInstructionException();
  (*pcVar2)();
}


// ===== 00330dd0 kchannelDeriveAndRetrieveKmb_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kchannelDeriveAndRetrieveKmb_KERNEL(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_1 + 0x1d18);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pCC != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x1086);
  }
  uVar2 = (**(code **)(lVar1 + 0x188))(lVar1,param_2,3);
  if (uVar2 == 0) {
    uVar3 = (**(code **)(lVar1 + 400))(lVar1,param_2,3,1,param_3);
    return uVar3;
  }
  nvAssertOkFailedNoLog
            (uVar2,
             "confComputeKeyStoreDeriveViaChannel_HAL(pCC, pKernelChannel, ROTATE_IV_ALL_VALID)",
             "src/kernel/gpu/fifo/kernel_channel.c",0x1087);
  return (ulong)uVar2;
}


// ===== 00330e8b kchannelCtrlCmdGetKmb_KERNEL.cold =====

void kchannelCtrlCmdGetKmb_KERNEL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00330ea0 kchannelCtrlCmdGetKmb_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelCtrlCmdGetKmb_KERNEL(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  char *pcVar10;
  undefined8 local_48;
  ulong local_40 [2];
  
  if (*(char *)(param_1 + 0x4f8) == '\0') {
    return 0x56;
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
  lVar8 = *(long *)(lVar3 + 0x1d18);
  if (lVar8 == 0) {
    portMemCopy(param_2,0x7c,param_1 + 0x454,0x7c);
    confComputeGetKeyRotationThreshold_IMPL(0,param_2 + 0x80,param_2 + 0x88);
  }
  else {
    if (*(char *)(lVar8 + 0x2b0) != '\0') {
      iVar5 = (**(code **)(lVar8 + 0x210))(lVar3,lVar8,param_1,local_40,0);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "confComputeGetKeyPairByChannel(pGpu, pConfCompute, pKernelChannel, &h2dKey, NULL)"
                   ,"src/kernel/gpu/fifo/kernel_channel.c",0x10a5);
        return iVar5;
      }
      iVar5 = confComputeGetKeyRotationStatus_IMPL(lVar8,local_40[0] & 0xffffffff,&local_48);
      if (iVar5 != 0) {
        nvAssertOkFailedNoLog
                  (iVar5,"confComputeGetKeyRotationStatus(pConfCompute, h2dKey, &state)",
                   "src/kernel/gpu/fifo/kernel_channel.c",0x10a6);
        return iVar5;
      }
      if (((int)local_48 != 0) ||
         (uVar6 = gpumgrGetSubDeviceInstanceFromGpu(lVar3),
         (*(byte *)(param_1 + 0x39c + (ulong)uVar6 * 4) & 4) != 0)) {
        return 0x7d;
      }
    }
    portMemCopy(param_2,0x7c,param_1 + 0x454,0x7c);
    confComputeGetKeyRotationThreshold_IMPL(lVar8,param_2 + 0x80,param_2 + 0x88);
    if (*(char *)(lVar8 + 0x2b0) != '\0') {
      lVar7 = rmapiGetInterface(4);
      local_48 = 0;
      local_40[0] = 0;
      uVar1 = *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x140) + 0x48) + 0x48);
      lVar8 = *(long *)(*(long *)(param_1 + 0x158) + 0xe8);
      if (lVar8 == 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)invalidInstructionException();
        (*pcVar4)();
      }
      uVar2 = *(undefined4 *)(*(long *)(*(long *)(lVar8 + 0x110) + 0x48) + 0x10);
      iVar5 = serverGetClientUnderLock(g_resServ,uVar1,&local_48);
      uVar9 = 0x10bc;
      pcVar10 = "serverGetClientUnderLock(&g_resServ, hClient, &pRsClient)";
      if (iVar5 == 0) {
        iVar5 = clientGetResourceRef_IMPL(local_48,*(undefined4 *)(param_2 + 0x7c),local_40,0x10bc);
        if (iVar5 != 0) {
LAB_003311d0:
          if (*(long *)(param_1 + 0x4e0) == 0) {
            return 0;
          }
          portMemSet(*(long *)(param_1 + 0x4e0),0,0x20);
          return 0;
        }
        if (*(long *)(param_1 + 0x4e0) != 0) {
          iVar5 = (**(code **)(param_1 + 0x210))(lVar3,param_1,0,0);
          if (iVar5 != 0) {
            uVar9 = 0x10c6;
            pcVar10 = "kchannelSetEncryptionStatsBuffer_HAL(pGpu, pKernelChannel, NULL, NV_FALSE)";
            goto LAB_0033121c;
          }
          (**(code **)(lVar7 + 0x18))(lVar7,uVar1,*(undefined4 *)(param_1 + 0x4d0));
        }
        iVar5 = (**(code **)(lVar7 + 0x50))
                          (lVar7,uVar1,uVar2,param_1 + 0x4d0,uVar1,*(undefined4 *)(param_2 + 0x7c),0
                          );
        pcVar10 = 
        "pRmApi->DupObject(pRmApi, hClient, hDevice, &pKernelChannel->hEncryptStatsBuf, hClient, pGetKmbParams->hMemory, 0)"
        ;
        uVar9 = 0x10cb;
        if (iVar5 == 0) {
          iVar5 = clientGetResourceRef_IMPL(local_48,*(undefined4 *)(param_1 + 0x4d0),local_40);
          if (iVar5 == 0) {
            lVar8 = __nvoc_dynamicCast(*(undefined8 *)(local_40[0] + 8),__nvoc_class_def_Memory);
            if ((lVar8 == 0) || (*(long *)(lVar8 + 0x118) == 0)) {
              nvAssertFailedNoLog("(pMemory != NULL) && (pMemory->pMemDesc != NULL)",
                                  "src/kernel/gpu/fifo/kernel_channel.c",0x10d2);
              iVar5 = 0x1f;
            }
            else {
              iVar5 = (**(code **)(param_1 + 0x210))(lVar3,param_1,*(long *)(lVar8 + 0x118),1);
              if (iVar5 == 0) goto LAB_003311d0;
              nvAssertOkFailedNoLog
                        (iVar5,
                         "kchannelSetEncryptionStatsBuffer_HAL(pGpu, pKernelChannel, pMemory->pMemDesc, NV_TRUE)"
                         ,"src/kernel/gpu/fifo/kernel_channel.c",0x10d5);
            }
          }
          else {
            nvAssertOkFailedNoLog
                      (iVar5,
                       "clientGetResourceRef(pRsClient, pKernelChannel->hEncryptStatsBuf, &pResourceRef)"
                       ,"src/kernel/gpu/fifo/kernel_channel.c",0x10ce);
          }
          (**(code **)(lVar7 + 0x18))(lVar7,uVar1,*(undefined4 *)(param_1 + 0x4d0));
          return iVar5;
        }
      }
LAB_0033121c:
      nvAssertOkFailedNoLog(iVar5,pcVar10,"src/kernel/gpu/fifo/kernel_channel.c",uVar9);
      return iVar5;
    }
  }
  return 0;
}


// ===== 003312d0 kchannelCtrlRotateSecureChannelIv_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchannelCtrlRotateSecureChannelIv_KERNEL(long param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  int iVar6;
  
  iVar6 = 0x56;
  if (*(char *)(param_1 + 0x4f8) != '\0') {
    uVar2 = *param_2;
    lVar3 = *(long *)(*(long *)(param_1 + 0x158) + 0xe0);
    lVar4 = *(long *)(lVar3 + 0x1d18);
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel.c",0x1109,
                 "kchannelCtrlRotateSecureChannelIv_KERNEL",1,"NVRM: Rotating IV in CPU-RM.\n");
    lVar1 = param_1 + 0x454;
    iVar6 = (**(code **)(lVar4 + 400))(lVar4,param_1,uVar2,3,lVar1);
    if (iVar6 == 0) {
      portMemSet(param_2,0,0x80);
      portMemCopy(param_2 + 1,0xc,lVar1,0xc);
      portMemCopy(param_2 + 0xf,0xc,param_1 + 0x48c,0xc);
      *param_2 = uVar2;
      plVar5 = *(long **)(*(long *)(param_1 + 0x140) + 0x48);
      iVar6 = (**(code **)(lVar3 + 0x3b90))
                        (lVar3 + 0x3b58,*(undefined4 *)(*plVar5 + 0x48),(int)plVar5[2],0xc56f010c,
                         param_2,0x80);
      if (iVar6 == 0) {
        if ((uVar2 == 3) || (uVar2 == 0)) {
          portMemCopy(param_2 + 1,0x38,lVar1,0x38);
        }
        if ((uVar2 & 0xfffffffd) == 1) {
          portMemCopy(param_2 + 0xf,0x38,param_1 + 0x48c,0x38);
        }
      }
    }
  }
  return iVar6;
}


// ===== 00331490 kchannelFillMmuExceptionInfo_IMPL =====

void kchannelFillMmuExceptionInfo_IMPL(long param_1,undefined8 param_2)

{
  long lVar1;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pKernelChannel","src/kernel/gpu/fifo/kernel_channel.c",0x116b);
    return;
  }
  if (*(long *)(param_1 + 0x248) != 0) {
    portMemCopy(*(long *)(param_1 + 0x248),0x58,param_2,0x58);
    return;
  }
  lVar1 = portMemAllocNonPaged(0x58,param_2,param_2);
  *(long *)(param_1 + 0x248) = lVar1;
  if (lVar1 != 0) {
    portMemCopy(lVar1,0x58,param_2,0x58);
    return;
  }
  return;
}


// ===== 00331530 kchannelIsDisabledForKeyRotation =====

byte kchannelIsDisabledForKeyRotation(undefined8 param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu();
  return *(byte *)(param_2 + 0x39c + (ulong)uVar1 * 4) >> 2 & 1;
}


// ===== 00331560 kchannelDisableForKeyRotation =====

void kchannelDisableForKeyRotation(undefined8 param_1,long param_2,char param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_3 != '\0') {
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
    puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
    *puVar1 = *puVar1 | 4;
    return;
  }
  uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
  puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
  *puVar1 = *puVar1 & 0xfffffffb;
  return;
}


// ===== 003315b0 kchannelEnableAfterKeyRotation =====

void kchannelEnableAfterKeyRotation(undefined8 param_1,long param_2,char param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_3 != '\0') {
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
    puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
    *puVar1 = *puVar1 | 8;
    return;
  }
  uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
  puVar1 = (uint *)(param_2 + 0x39c + (ulong)uVar2 * 4);
  *puVar1 = *puVar1 & 0xfffffff7;
  return;
}


// ===== 00331600 kchannelSetKeyRotationNotifier_KERNEL =====

int kchannelSetKeyRotationNotifier_KERNEL(long param_1,long param_2,char param_3)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 600);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pNotifierMemDesc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x11e0);
    return 0x40;
  }
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  iVar2 = memdescGetAddressSpace(lVar3);
  if (param_3 == '\0') {
    lVar3 = *(long *)(param_2 + 0x4e8);
    if (lVar3 != 0) {
      if (*(long *)(param_2 + 0x4f0) != 0) {
        memmgrMemDescEndTransfer_IMPL(uVar1,lVar3,2);
        lVar3 = *(long *)(param_2 + 0x4e8);
        *(undefined8 *)(param_2 + 0x4f0) = 0;
      }
      memdescDestroy(lVar3);
      *(undefined8 *)(param_2 + 0x4e8) = 0;
    }
  }
  else {
    if (*(ulong *)(lVar3 + 0x30) < 0x30) {
      nvAssertFailedNoLog("memdescGetSize(pNotifierMemDesc) >= ((notifyIndex + 1) * sizeof(NvNotification))"
                          ,"src/kernel/gpu/fifo/kernel_channel.c",0x11e5);
      return 0x1f;
    }
    if (iVar2 != 1) {
      nvAssertFailedNoLog("addressSpace == ADDR_SYSMEM","src/kernel/gpu/fifo/kernel_channel.c",
                          0x11e8);
      return 0x56;
    }
    if (*(long *)(param_2 + 0x4e8) == 0) {
      iVar2 = memdescCreateSubMem(param_2 + 0x4e8,lVar3,param_1,0x20,0x10);
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "memdescCreateSubMem(&pKernelChannel->pKeyRotationNotifierMemDesc, pNotifierMemDesc, pGpu, notifyIndex * sizeof(NvNotification), sizeof(NvNotification))"
                   ,"src/kernel/gpu/fifo/kernel_channel.c",0x11eb);
        return iVar2;
      }
      lVar3 = memmgrMemDescBeginTransfer_IMPL(uVar1,*(undefined8 *)(param_2 + 0x4e8),2);
      *(long *)(param_2 + 0x4f0) = lVar3;
      if (lVar3 != 0) {
        portMemSet(lVar3,0,0x10);
        return 0;
      }
      nvAssertFailedNoLog("pKernelChannel->pKeyRotationNotifier != NULL",
                          "src/kernel/gpu/fifo/kernel_channel.c",0x11f3);
      if (*(long *)(param_2 + 0x4e8) == 0) {
        return 0x40;
      }
      memdescDestroy();
      *(undefined8 *)(param_2 + 0x4e8) = 0;
      return 0x40;
    }
  }
  return 0;
}


// ===== 00331870 kchannelSetEncryptionStatsBuffer_KERNEL =====

int kchannelSetEncryptionStatsBuffer_KERNEL(long param_1,long param_2,long param_3,char param_4)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0x1b78);
  if (param_4 == '\0') {
    if (*(long *)(param_2 + 0x4d8) == 0) {
      nvAssertFailedNoLog("pKernelChannel->pEncStatsBufMemDesc != NULL",
                          "src/kernel/gpu/fifo/kernel_channel.c",0x1249);
      return 0x40;
    }
    memmgrMemDescEndTransfer_IMPL(uVar1,*(long *)(param_2 + 0x4d8),2);
    *(undefined8 *)(param_2 + 0x4e0) = 0;
    if (*(char *)(param_2 + 0x2ac) == '\x02') {
      lVar3 = *(long *)(param_2 + 0x4d8);
      if (*(long *)(lVar3 + 200) == 0) {
        nvAssertFailedNoLog("memdescIsSubMemoryMemDesc(pKernelChannel->pEncStatsBufMemDesc)",
                            "src/kernel/gpu/fifo/kernel_channel.c",0x124f);
        lVar3 = *(long *)(param_2 + 0x4d8);
      }
      memdescDestroy(lVar3);
    }
    *(undefined8 *)(param_2 + 0x4d8) = 0;
  }
  else {
    if (param_3 == 0) {
      nvAssertFailedNoLog("pMemDesc != NULL","src/kernel/gpu/fifo/kernel_channel.c",0x1223);
      return 0x1f;
    }
    if (*(long *)(param_2 + 0x4e0) != 0) {
      nvAssertFailedNoLog("pKernelChannel->pEncStatsBuf == NULL",
                          "src/kernel/gpu/fifo/kernel_channel.c",0x1224);
      return 0x40;
    }
    if (*(char *)(param_2 + 0x2ac) == '\x02') {
      iVar2 = memdescCreateSubMem(param_2 + 0x4d8,param_3,param_1,0,*(undefined8 *)(param_3 + 0x30))
      ;
      if (iVar2 != 0) {
        nvAssertOkFailedNoLog
                  (iVar2,
                   "memdescCreateSubMem(&pKernelChannel->pEncStatsBufMemDesc, pMemDesc, pGpu, 0, memdescGetSize(pMemDesc))"
                   ,"src/kernel/gpu/fifo/kernel_channel.c",0x122c);
        return iVar2;
      }
      param_3 = *(long *)(param_2 + 0x4d8);
    }
    else {
      *(long *)(param_2 + 0x4d8) = param_3;
    }
    lVar3 = memmgrMemDescBeginTransfer_IMPL(uVar1,param_3,2);
    *(long *)(param_2 + 0x4e0) = lVar3;
    if (lVar3 == 0) {
      if (*(char *)(param_2 + 0x2ac) == '\x02') {
        memdescDestroy(*(undefined8 *)(param_2 + 0x4d8));
      }
      *(undefined8 *)(param_2 + 0x4d8) = 0;
      return 0x40;
    }
    portMemSet(lVar3,0,0x20);
  }
  return 0;
}


// ===== 00331a80 _kchangrpFreeAllEngCtxDescs =====

void _kchangrpFreeAllEngCtxDescs(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = *(long *)(param_2 + 0x150);
  if (lVar1 != 0) {
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
    lVar1 = *(long *)(lVar1 + (ulong)uVar2 * 8);
    if (lVar1 != 0) {
      vaListDestroy(lVar1 + 8);
    }
    portMemFree(lVar1);
    lVar1 = *(long *)(param_2 + 0x150);
    uVar2 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
    *(undefined8 *)(lVar1 + (ulong)uVar2 * 8) = 0;
    portMemFree(*(undefined8 *)(param_2 + 0x150));
    *(undefined8 *)(param_2 + 0x150) = 0;
  }
  return;
}


// ===== 00331b10 kchangrpConstruct_IMPL =====

undefined8 kchangrpConstruct_IMPL(void)

{
  return 0;
}


// ===== 00331b20 kchangrpDestruct_IMPL =====

void kchangrpDestruct_IMPL(void)

{
  return;
}


// ===== 00331b30 kchangrpInit_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchangrpInit_IMPL(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  long local_58;
  int local_50;
  undefined4 local_40;
  undefined4 local_3c [3];
  
  lVar8 = gpuGetKernelFifoShared_IMPL();
  local_40 = 0;
  local_3c[0] = 0;
  uVar4 = gpumgrGetSubDeviceMaxValuePlus1(param_1);
  uVar5 = gpumgrGetSubDeviceMaxValuePlus1(param_1);
  uVar12 = (ulong)uVar5;
  lVar11 = uVar12 * 8;
  uVar9 = portMemAllocNonPaged(lVar11);
  *(undefined8 *)(param_2 + 0x168) = uVar9;
  uVar9 = portMemAllocNonPaged(lVar11);
  *(undefined8 *)(param_2 + 0x170) = uVar9;
  uVar9 = portMemAllocNonPaged(uVar12 * 4);
  *(undefined8 *)(param_2 + 0x178) = uVar9;
  lVar10 = portMemAllocNonPaged(uVar12 * 4);
  *(long *)(param_2 + 0x180) = lVar10;
  if ((((*(long *)(param_2 + 0x168) == 0) || (*(long *)(param_2 + 0x170) == 0)) ||
      (*(long *)(param_2 + 0x178) == 0)) || (lVar10 == 0)) {
    uVar5 = 0;
    bVar2 = false;
    nvAssertFailedNoLog("(pKernelChannelGroup->ppSubctxMask != NULL && pKernelChannelGroup->ppZombieSubctxMask != NULL && pKernelChannelGroup->pStateMask != NULL && pKernelChannelGroup->pInterleaveLevel != NULL)"
                        ,"src/kernel/gpu/fifo/kernel_channel_group.c",0x87);
    local_58 = 0;
    local_50 = 0x51;
  }
  else {
    portMemSet(*(long *)(param_2 + 0x168),0,lVar11);
    portMemSet(*(undefined8 *)(param_2 + 0x170),0,lVar11);
    portMemSet(*(undefined8 *)(param_2 + 0x178),0,uVar12 * 4);
    portMemSet(*(undefined8 *)(param_2 + 0x180),0,uVar12 * 4);
    uVar6 = (**(code **)(lVar8 + 0x198))(param_1,lVar8,*(undefined4 *)(param_2 + 0xfc));
    *(undefined4 *)(param_2 + 0xf4) = uVar6;
    if ((*(char *)(lVar8 + 0x4b0) != '\0') &&
       (iVar7 = (**(code **)(lVar8 + 0x218))
                          (param_1,lVar8,2,*(undefined4 *)(param_2 + 0xfc),3,local_3c), iVar7 != 0))
    {
      nvAssertOkFailedNoLog
                (iVar7,
                 "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, pKernelChannelGroup->engineType, ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
                 ,"src/kernel/gpu/fifo/kernel_channel_group.c",0xa3);
      return iVar7;
    }
    local_58 = kfifoGetChidMgr_IMPL(param_1,lVar8,local_3c[0]);
    iVar7 = kfifoChidMgrAllocChannelGroupHwID_IMPL(param_1,lVar8,local_58,&local_40);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,"kfifoChidMgrAllocChannelGroupHwID(pGpu, pKernelFifo, pChidMgr, &grpID)",
                 "src/kernel/gpu/fifo/kernel_channel_group.c",0xad);
      return iVar7;
    }
    *(undefined4 *)(param_2 + 0xf0) = local_40;
    uVar9 = (**(code **)(lVar8 + 0x180))(lVar8);
    *(undefined8 *)(param_2 + 0x148) = uVar9;
    local_50 = kfifoChannelGroupSetTimeslice_IMPL(param_1,lVar8,param_2,uVar9,1);
    if (local_50 == 0) {
      local_50 = kfifoChannelListCreate_IMPL(param_1,lVar8,param_2 + 0x140);
      if (local_50 == 0) {
        lVar11 = portMemAllocNonPaged((ulong)uVar4 * 8);
        *(long *)(param_2 + 0x150) = lVar11;
        uVar5 = 0;
        if (lVar11 == 0) {
          nvAssertFailedNoLog("pKernelChannelGroup->ppEngCtxDesc != NULL",
                              "src/kernel/gpu/fifo/kernel_channel_group.c",0xbd);
        }
        else {
          portMemSet(lVar11,0,(ulong)uVar4 * 8);
          lVar11 = portMemAllocNonPaged(0xd8);
          *(long *)(param_2 + 0x110) = lVar11;
          if (lVar11 == 0) {
            bVar2 = false;
            nvCheckFailedNoLog(4,"pKernelChannelGroup->pSubctxIdHeap != NULL",
                               "src/kernel/gpu/fifo/kernel_channel_group.c",0xc3);
            local_50 = 0x51;
            goto LAB_00331f2d;
          }
          uVar6 = (**(code **)(lVar8 + 0x1f0))(param_1,lVar8,param_2,0);
          constructObjEHeap(*(undefined8 *)(param_2 + 0x110),0,uVar6,0,0);
          lVar11 = portMemAllocNonPaged(0xd8);
          *(long *)(param_2 + 0x138) = lVar11;
          if (lVar11 != 0) {
            constructObjEHeap(lVar11,0,uVar6,0,0);
            uVar9 = portMemAllocatorGetGlobalNonPaged();
            mapInit_IMPL(param_2 + 0x118,uVar9,0x10);
            *(undefined1 *)(param_2 + 0x159) = 0;
            *(undefined8 *)(param_2 + 0x100) = param_3;
            *(undefined4 *)(param_2 + 0x108) = param_4;
            uVar5 = (**(code **)(lVar8 + 0x200))(param_1,lVar8);
            if (uVar5 == 0) {
              nvAssertFailedNoLog("(runQueues > 0)","src/kernel/gpu/fifo/kernel_channel_group.c",
                                  0xe5);
            }
            *(undefined8 *)(param_2 + 0x160) = 0;
            lVar11 = portMemAllocNonPaged((ulong)uVar5 << 4);
            *(long *)(param_2 + 0x160) = lVar11;
            if (lVar11 == 0) {
              bVar2 = false;
              nvCheckFailedNoLog(4,"pKernelChannelGroup->pMthdBuffers != NULL",
                                 "src/kernel/gpu/fifo/kernel_channel_group.c",0xed);
              local_50 = 0x51;
            }
            else {
              portMemSet(lVar11,0,(ulong)uVar5 << 4);
              local_50 = (**(code **)(param_2 + 0x98))(param_1,param_2);
              if (local_50 == 0) {
                uVar4 = 0;
                if (uVar5 != 0) {
                  do {
                    uVar9 = (**(code **)(param_2 + 0xa8))(param_1,param_2);
                    local_50 = (int)uVar9;
                    if (local_50 != 0) {
                      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0x10d,
                                   "kchangrpInit_IMPL",4,
                                   "NVRM:  Fault method buffer BAR2 mapping failed for group ID 0x%0x with status 0x%0x\n"
                                   ,local_40,uVar9);
                      bVar2 = true;
                      goto LAB_00331f2d;
                    }
                    uVar4 = uVar4 + 1;
                  } while (uVar4 != uVar5);
                }
                lVar11 = *(long *)(param_2 + 0x170);
                uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
                *(undefined4 *)(lVar11 + (ulong)uVar4 * 8) = 0;
                lVar11 = *(long *)(param_2 + 0x170);
                uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
                *(undefined4 *)(lVar11 + 4 + (ulong)uVar4 * 8) = 0;
                cVar3 = mapInsertExisting_IMPL(*(undefined8 *)(local_58 + 0x38),local_40,param_2);
                if (cVar3 == '\0') {
                  nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel_group.c"
                                      ,0x129);
                }
                LOCK();
                piVar1 = (int *)(g_pSys + 0x178);
                iVar7 = *piVar1;
                *piVar1 = *piVar1 + 1;
                UNLOCK();
                *(int *)(param_2 + 500) = iVar7 + 1;
                return 0;
              }
              bVar2 = false;
              nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0xf9,"kchangrpInit_IMPL",4,
                           "NVRM:  Fault method buffer allocation failed for group ID 0x%0x with status 0x%0x\n"
                           ,local_40,local_50);
            }
            goto LAB_00331f2d;
          }
          nvCheckFailedNoLog(4,"pKernelChannelGroup->pVaSpaceIdHeap != NULL",
                             "src/kernel/gpu/fifo/kernel_channel_group.c",0xd2);
        }
        local_50 = 0x51;
        bVar2 = false;
      }
      else {
        bVar2 = false;
        nvAssertOkFailedNoLog
                  (local_50,
                   "kfifoChannelListCreate(pGpu, pKernelFifo, &pKernelChannelGroup->pChanList)",
                   "src/kernel/gpu/fifo/kernel_channel_group.c",0xb7);
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0;
      bVar2 = false;
      nvAssertOkFailedNoLog
                (local_50,
                 "kfifoChannelGroupSetTimeslice(pGpu, pKernelFifo, pKernelChannelGroup, pKernelChannelGroup->timesliceUs, NV_TRUE)"
                 ,"src/kernel/gpu/fifo/kernel_channel_group.c",0xb2);
    }
  }
LAB_00331f2d:
  if (*(undefined8 **)(param_2 + 0x110) != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)(param_2 + 0x110))();
    portMemFree(*(undefined8 *)(param_2 + 0x110));
    *(undefined8 *)(param_2 + 0x110) = 0;
  }
  if (*(undefined8 **)(param_2 + 0x138) != (undefined8 *)0x0) {
    (*(code *)**(undefined8 **)(param_2 + 0x138))();
    portMemFree(*(undefined8 *)(param_2 + 0x138));
    *(undefined8 *)(param_2 + 0x138) = 0;
    mapDestroy_IMPL(param_2 + 0x118);
  }
  _kchangrpFreeAllEngCtxDescs(param_1,param_2);
  if (*(long *)(param_2 + 0x140) != 0) {
    kfifoChannelListDestroy_IMPL(param_1,lVar8);
    *(undefined8 *)(param_2 + 0x140) = 0;
  }
  if (*(long *)(param_2 + 0x160) != 0) {
    if ((bVar2) && (uVar5 != 0)) {
      uVar4 = 0;
      do {
        uVar13 = uVar4 + 1;
        (**(code **)(param_2 + 0xb0))(param_1,param_2,uVar4);
        uVar4 = uVar13;
      } while (uVar5 != uVar13);
    }
    (**(code **)(param_2 + 0xa0))(param_1,param_2);
    portMemFree(*(undefined8 *)(param_2 + 0x160));
    *(undefined8 *)(param_2 + 0x160) = 0;
  }
  if (local_58 != 0) {
    kfifoChidMgrFreeChannelGroupHwID_IMPL(param_1,lVar8,local_58,local_40);
  }
  portMemFree(*(undefined8 *)(param_2 + 0x168));
  *(undefined8 *)(param_2 + 0x168) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x170));
  *(undefined8 *)(param_2 + 0x170) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x178));
  *(undefined8 *)(param_2 + 0x178) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x180));
  *(undefined8 *)(param_2 + 0x180) = 0;
  return local_50;
}


// ===== 00332300 kchangrpDestroy_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchangrpDestroy_IMPL(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  undefined4 local_4c;
  ulong local_48;
  ulong local_40 [2];
  
  lVar4 = gpuGetKernelFifoShared_IMPL();
  local_4c = 0;
  iVar1 = (**(code **)(lVar4 + 0x200))(param_1,lVar4);
  if (*(char *)(lVar4 + 0x4b0) == '\0') {
    lVar5 = kfifoGetChidMgr_IMPL(param_1,lVar4,local_4c);
    if (param_2 == 0) {
      return 0;
    }
  }
  else {
    iVar2 = (**(code **)(lVar4 + 0x218))
                      (param_1,lVar4,2,*(undefined4 *)(param_2 + 0xfc),3,&local_4c);
    if (iVar2 != 0) {
      nvAssertOkFailedNoLog
                (iVar2,
                 "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, pKernelChannelGroup->engineType, ENGINE_INFO_TYPE_RUNLIST, &runlistId)"
                 ,"src/kernel/gpu/fifo/kernel_channel_group.c",0x18e);
      return iVar2;
    }
    lVar5 = kfifoGetChidMgr_IMPL(param_1,lVar4,local_4c);
  }
  if (*(int *)(param_2 + 0xf8) != 0) {
    nvAssertFailedNoLog("pKernelChannelGroup->chanCount == 0",
                        "src/kernel/gpu/fifo/kernel_channel_group.c",0x19d);
  }
  iVar2 = (**(code **)(*(long *)(param_2 + 0x110) + 0x28))(*(long *)(param_2 + 0x110),&local_48);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel_group.c",0x1a2);
  }
  iVar2 = (**(code **)(*(long *)(param_2 + 0x110) + 0x30))(*(long *)(param_2 + 0x110),local_40);
  if (iVar2 != 0) {
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel_group.c",0x1a7);
  }
  uVar3 = (**(code **)(lVar4 + 0x1f0))(param_1,lVar4,param_2,*(undefined1 *)(param_2 + 0x159));
  if (uVar3 != local_48) {
    nvAssertFailedNoLog("maxSubctx == kfifoChannelGroupGetLocalMaxSubcontext_HAL( pGpu, pKernelFifo, pKernelChannelGroup, pKernelChannelGroup->bLegacyMode)"
                        ,"src/kernel/gpu/fifo/kernel_channel_group.c",0x1ad);
  }
  if (local_48 != local_40[0]) {
    nvAssertFailedNoLog("maxSubctx == numFreeSubctx","src/kernel/gpu/fifo/kernel_channel_group.c",
                        0x1b2);
  }
  (*(code *)**(undefined8 **)(param_2 + 0x110))();
  portMemFree(*(undefined8 *)(param_2 + 0x110));
  *(undefined8 *)(param_2 + 0x110) = 0;
  (*(code *)**(undefined8 **)(param_2 + 0x138))();
  portMemFree(*(undefined8 *)(param_2 + 0x138));
  *(undefined8 *)(param_2 + 0x138) = 0;
  mapDestroy_IMPL(param_2 + 0x118);
  _kchangrpFreeAllEngCtxDescs(param_1,param_2);
  kfifoChannelListDestroy_IMPL(param_1,lVar4,*(undefined8 *)(param_2 + 0x140));
  *(undefined8 *)(param_2 + 0x140) = 0;
  if (lVar5 != 0) {
    lVar6 = mapFind_IMPL(*(undefined8 *)(lVar5 + 0x38),*(undefined4 *)(param_2 + 0xf0));
    if (lVar6 == 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0x1cb,"kchangrpDestroy_IMPL",4,
                   "NVRM: Could not find channel group %d\n",*(undefined4 *)(param_2 + 0xf0));
      return 0x57;
    }
    mapRemoveIntrusive_IMPL(*(undefined8 *)(lVar5 + 0x38),lVar6);
    kfifoChidMgrFreeChannelGroupHwID_IMPL(param_1,lVar4,lVar5,*(undefined4 *)(param_2 + 0xf0));
  }
  lVar4 = *(long *)(param_2 + 0x160);
  if (((*(int *)(param_2 + 0x108) == 0) || (*(char *)(param_1 + 0x491e) != '\0')) && (lVar4 != 0)) {
    if (iVar1 != 0) {
      iVar2 = 0;
      do {
        iVar7 = iVar2 + 1;
        (**(code **)(param_2 + 0xb0))(param_1,param_2,iVar2);
        iVar2 = iVar7;
      } while (iVar7 != iVar1);
    }
    (**(code **)(param_2 + 0xa0))(param_1,param_2);
    lVar4 = *(long *)(param_2 + 0x160);
  }
  portMemFree(lVar4);
  *(undefined8 *)(param_2 + 0x160) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x168));
  *(undefined8 *)(param_2 + 0x168) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x170));
  *(undefined8 *)(param_2 + 0x170) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x178));
  *(undefined8 *)(param_2 + 0x178) = 0;
  portMemFree(*(undefined8 *)(param_2 + 0x180));
  *(undefined8 *)(param_2 + 0x180) = 0;
  return 0;
}


// ===== 003326f0 kchangrpAddChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchangrpAddChannel_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar7 = gpuGetKernelFifoShared_IMPL();
  uVar4 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroup != NULL","src/kernel/gpu/fifo/kernel_channel_group.c",
                        0x216);
  }
  else {
    if (param_3 != 0) {
      iVar5 = (**(code **)(lVar7 + 0x208))(lVar7);
      if (*(int *)(param_2 + 0xf8) == iVar5) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0x21c,"kchangrpAddChannel_IMPL",4,
                     "NVRM: There are already max %d channels in this group\n",iVar5);
        return 0x1a;
      }
      if (*(long *)(param_3 + 0x2c8) == 0) {
        nvAssertFailedNoLog("pKernelChannel->pKernelCtxShareApi != NULL",
                            "src/kernel/gpu/fifo/kernel_channel_group.c",0x222);
      }
      else {
        lVar7 = *(long *)(*(long *)(param_3 + 0x2c8) + 0x138);
        if (lVar7 == 0) {
          nvAssertFailedNoLog("pKernelCtxShare != NULL","src/kernel/gpu/fifo/kernel_channel_group.c"
                              ,0x224);
        }
        else {
          cVar3 = kchannelIsRunlistSet(param_1,param_3);
          if ((cVar3 == '\0') || (*(int *)(param_3 + 0x2b0) == *(int *)(param_2 + 0xf4))) {
            uVar1 = *(undefined4 *)(lVar7 + 0xa8);
            *(undefined4 *)(param_3 + 0x40c) = uVar1;
            *(undefined4 *)(param_3 + 0x410) = *(undefined4 *)(lVar7 + 0xac);
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0x22f,
                         "kchangrpAddChannel_IMPL",1,
                         "NVRM: channel 0x%08x within TSG 0x%x is using subcontext 0x%x\n",
                         *(int *)(param_3 + 0x2b0) << 0x18 | *(uint *)(param_3 + 0x2b4),
                         *(undefined4 *)(param_2 + 0xf0),uVar1);
            uVar2 = *(undefined8 *)(param_2 + 0x140);
            uVar8 = gpuGetKernelFifoShared_IMPL(param_1);
            iVar5 = kfifoChannelListAppend_IMPL(param_1,uVar8,param_3,uVar2);
            if (iVar5 != 0) {
              nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0x23a,
                           "kchangrpAddChannel_IMPL",4,
                           "NVRM: Could not add channel to channel list\n");
              return iVar5;
            }
            *(int *)(param_2 + 0xf8) = *(int *)(param_2 + 0xf8) + 1;
            uVar4 = *(uint *)(*(long *)(param_2 + 0x180) + (ulong)uVar4 * 4);
            if (uVar4 < 3) {
              uVar6 = gpumgrGetSubDeviceInstanceFromGpu(param_1);
              *(uint *)(*(long *)(param_2 + 0x180) + (ulong)uVar6 * 4) = uVar4;
              return 0;
            }
            nvAssertOkFailedNoLog
                      (0x1f,
                       "kchangrpSetInterleaveLevel(pGpu, pKernelChannelGroup, pKernelChannelGroup->pInterleaveLevel[subdevInst])"
                       ,"src/kernel/gpu/fifo/kernel_channel_group.c",0x240);
            return 0x1f;
          }
          nvAssertFailedNoLog("pKernelChannelGroup->runlistId == kchannelGetRunlistId(pKernelChannel)"
                              ,"src/kernel/gpu/fifo/kernel_channel_group.c",0x228);
        }
      }
      return 0x40;
    }
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel_group.c",0x217)
    ;
  }
  return 0x3d;
}


// ===== 003329c0 kchangrpRemoveChannel_IMPL =====

int kchangrpRemoveChannel_IMPL(undefined8 param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroup != NULL","src/kernel/gpu/fifo/kernel_channel_group.c",
                        0x25e);
  }
  else {
    if (param_3 != 0) {
      uVar1 = *(undefined8 *)(param_2 + 0x140);
      uVar3 = gpuGetKernelFifoShared_IMPL();
      iVar2 = kfifoChannelListRemove_IMPL(param_1,uVar3,param_3,uVar1);
      if (iVar2 != 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0x266,"kchangrpRemoveChannel_IMPL"
                     ,4,"NVRM: Could not remove channel from channel list\n");
        return iVar2;
      }
      if (*(int *)(param_2 + 0xf8) == 0) {
        iVar2 = 0x40;
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group.c",0x26c,"kchangrpRemoveChannel_IMPL"
                     ,4,"NVRM: Channelcount in channel group not right!!!\n");
      }
      else {
        iVar2 = *(int *)(param_2 + 0xf8) + -1;
        *(int *)(param_2 + 0xf8) = iVar2;
        if (iVar2 == 0) {
          *(undefined1 *)(param_2 + 0x188) = 0;
          return 0;
        }
        iVar2 = 0;
      }
      return iVar2;
    }
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel_group.c",0x25f)
    ;
  }
  return 0x3d;
}


// ===== 00332b20 kchangrpSetInterleaveLevel_IMPL =====

undefined8 kchangrpSetInterleaveLevel_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  uint uVar1;
  
  if (2 < param_3) {
    return 0x1f;
  }
  uVar1 = gpumgrGetSubDeviceInstanceFromGpu();
  *(uint *)(*(long *)(param_2 + 0x180) + (ulong)uVar1 * 4) = param_3;
  return 0;
}


// ===== 00332b60 kchangrpAllocEngineContextDescriptor_IMPL =====

ulong kchangrpAllocEngineContextDescriptor_IMPL(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
  uVar5 = (ulong)uVar2;
  lVar1 = *(long *)(param_2 + 0x150);
  uVar3 = portMemAllocNonPaged(0x50);
  *(undefined8 *)(lVar1 + uVar5 * 8) = uVar3;
  lVar1 = *(long *)(*(long *)(param_2 + 0x150) + uVar5 * 8);
  if (lVar1 != 0) {
    portMemSet(lVar1,0,0x50);
    uVar4 = vaListInit(*(long *)(*(long *)(param_2 + 0x150) + uVar5 * 8) + 8);
    if ((int)uVar4 != 0) {
      nvAssertOkFailedNoLog
                (uVar4 & 0xffffffff,
                 "vaListInit(&pKernelChannelGroup->ppEngCtxDesc[subdeviceInstance]->vaList)",
                 "src/kernel/gpu/fifo/kernel_channel_group.c",0x2e8);
      portMemFree(*(undefined8 *)(*(long *)(param_2 + 0x150) + uVar5 * 8));
      uVar4 = uVar4 & 0xffffffff;
      *(undefined8 *)(*(long *)(param_2 + 0x150) + uVar5 * 8) = 0;
    }
    return uVar4;
  }
  nvAssertFailedNoLog("pKernelChannelGroup->ppEngCtxDesc[subdeviceInstance] != NULL",
                      "src/kernel/gpu/fifo/kernel_channel_group.c",0x2e5);
  return 0x51;
}


// ===== 00332c60 kchangrpGetEngineContextMemDesc_IMPL =====

undefined8 kchangrpGetEngineContextMemDesc_IMPL(undefined8 param_1,long param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = gpumgrGetSubDeviceInstanceFromGpu();
  puVar1 = *(undefined8 **)(*(long *)(param_2 + 0x150) + (ulong)uVar2 * 8);
  uVar3 = 0;
  if (puVar1 != (undefined8 *)0x0) {
    uVar3 = *puVar1;
  }
  *param_3 = uVar3;
  return 0;
}


// ===== 00332c96 kchangrpapiControl_IMPL.cold =====

void kchangrpapiControl_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00332ca0 kchangrpapiControl_IMPL =====

void kchangrpapiControl_IMPL(long param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x248,"kchangrpapiControl_IMPL",1,
                 "NVRM: grpID 0x%x handle 0x%x cmd 0x%x\n",
                 *(undefined4 *)(*(long *)(param_1 + 0x138) + 0xf0),
                 *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x110) + 0x48) + 0x10),
                 *(undefined4 *)(*(long *)(param_3 + 0x70) + 8));
    gpuresControl_IMPL(*(undefined8 *)(param_1 + 0x128),param_2,param_3);
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00332d30 kchangrpapiDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kchangrpapiDestruct_IMPL(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 local_278 [280];
  long local_160 [2];
  long local_150;
  long local_148;
  undefined1 local_140 [256];
  long local_40;
  
  uVar9 = 0;
  lVar1 = *(long *)(param_1 + 0x138);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  if (lVar1 != 0) {
    uVar9 = *(undefined8 *)(lVar1 + 0x88);
  }
  local_160[0] = param_1;
  lVar7 = rmapiGetInterface(4);
  uVar8 = 0;
  if (local_160[0] != 0) {
    uVar8 = *(undefined8 *)(local_160[0] + 0x110);
  }
  resGetFreeParams_IMPL(uVar8,&local_150,&local_148);
  uVar8 = *(undefined8 *)(local_150 + 0x10);
  lVar3 = *(long *)(local_150 + 8);
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x267,"kchangrpapiDestruct_IMPL",1,
               "NVRM: \n");
  iVar5 = serverGetShareRefCount(g_resServ,uVar9);
  if (iVar5 < 2) {
    kchannelGetIter(local_278,lVar3,uVar8);
    memcpy(local_140,local_278,0x108);
    iVar5 = 0;
    while (cVar4 = clientRefOrderedIterNext(lVar3,local_140), cVar4 != '\0') {
      iVar6 = (**(code **)(lVar7 + 0x18))
                        (lVar7,*(undefined4 *)(lVar3 + 0x48),*(undefined4 *)(local_40 + 0x10));
      if ((iVar6 != 0) && (iVar5 == 0)) {
        iVar5 = iVar6;
      }
    }
    if (iVar5 != 0) {
      nvAssertFailedNoLog("rmStatus == NV_OK","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x280
                         );
    }
    if (lVar1 != 0) {
      kchangrpDestroy_IMPL(uVar2,lVar1);
      if (*(long *)(lVar1 + 400) != 0) {
        ctxBufPoolRelease();
        ctxBufPoolDestroy(lVar1 + 400);
      }
      if (*(long *)(lVar1 + 0x198) != 0) {
        ctxBufPoolRelease();
        ctxBufPoolDestroy(lVar1 + 0x198);
      }
      listDestroy_IMPL(lVar1 + 0x1c8);
    }
  }
  else {
    iVar5 = 0;
    listRemoveFirstByValue_IMPL(*(long *)(local_160[0] + 0x138) + 0x1c8,local_160);
  }
  serverFreeShare(g_resServ,uVar9);
  *(int *)(local_148 + 0x30) = iVar5;
  return;
}


// ===== 00332f50 kchangrpapiCopyConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int kchangrpapiCopyConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  char cVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  char *pcVar14;
  undefined8 extraout_RDX;
  undefined8 uVar15;
  undefined8 uStack_110;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  long local_b0;
  undefined8 local_a8;
  long local_90 [2];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  local_90[0] = param_1;
  lVar9 = rmapiGetInterface(4);
  lVar13 = *(long *)(param_3 + 0x58);
  lVar4 = *(long *)(param_2 + 8);
  lVar5 = *(long *)(param_2 + 0x10);
  lVar10 = __nvoc_dynamicCast(*(undefined8 *)(lVar13 + 8),__nvoc_class_def_KernelChannelGroupApi);
  lVar6 = *(long *)(*(long *)(local_90[0] + 0x128) + 0xe0);
  *(undefined8 *)(local_90[0] + 0x148) = 0;
  *(undefined4 *)(local_90[0] + 0x150) = 0;
  lVar12 = *(long *)(lVar10 + 0x138);
  *(long *)(local_90[0] + 0x138) = lVar12;
  uVar15 = 0;
  if (lVar12 != 0) {
    uVar15 = *(undefined8 *)(lVar12 + 0x88);
  }
  serverRefShare(g_resServ,uVar15);
  serverutilRefIter(&local_e8,*(undefined4 *)(lVar4 + 0x48),
                    *(undefined4 *)(*(long *)(lVar5 + 0x18) + 0x10),"A RTXA6000-4C",1,1);
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
    cVar7 = clientRefIterNext(local_60,&local_80);
    lVar12 = local_48;
    if (cVar7 == '\0') goto LAB_0033311b;
    lVar11 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_VaSpaceApi);
    if (lVar11 == 0) {
      nvAssertFailedNoLog("pVaspaceApi != NULL","src/kernel/gpu/fifo/kernel_channel_group_api.c",
                          0x2bd);
      return 0x40;
    }
  } while (*(long *)(lVar11 + 0x138) != *(long *)(*(long *)(local_90[0] + 0x138) + 0x100));
  refAddDependant(lVar12,lVar5);
LAB_0033311b:
  if (*(int *)(lVar10 + 0x148) != 0) {
    iVar8 = (**(code **)(lVar9 + 0x50))
                      (lVar9,*(undefined4 *)(lVar4 + 0x48),*(undefined4 *)(lVar5 + 0x10),
                       local_90[0] + 0x148,*(undefined4 *)(*(long *)(param_3 + 0x50) + 0x48),
                       *(int *)(lVar10 + 0x148),0);
    uVar15 = 0x2c9;
    pcVar14 = 
    "pRmApi->DupObject(pRmApi, pDstClient->hClient, pDstRef->hResource, &pKernelChannelGroupApi->hKernelGraphicsContext, pParams->pSrcClient->hClient, pChanGrpSrc->hKernelGraphicsContext, 0)"
    ;
    if (iVar8 == 0) goto LAB_00333183;
LAB_00333473:
    nvCheckOkFailedNoLog(4,iVar8,pcVar14,"src/kernel/gpu/fifo/kernel_channel_group_api.c",uVar15);
    goto LAB_0033338d;
  }
LAB_00333183:
  if (*(char *)(*(long *)(lVar10 + 0x138) + 0x159) != '\0') {
    iVar8 = (**(code **)(lVar9 + 0x50))
                      (lVar9,*(undefined4 *)(lVar4 + 0x48),*(undefined4 *)(lVar5 + 0x10),
                       local_90[0] + 0x14c,*(undefined4 *)(*(long *)(param_3 + 0x50) + 0x48),
                       *(undefined4 *)(lVar10 + 0x14c),0);
    if (iVar8 != 0) {
      uVar15 = 0x2da;
      pcVar14 = 
      "pRmApi->DupObject(pRmApi, pDstClient->hClient, pDstRef->hResource, &pKernelChannelGroupApi->hLegacykCtxShareSync, pParams->pSrcClient->hClient, pChanGrpSrc->hLegacykCtxShareSync, 0)"
      ;
      goto LAB_00333473;
    }
    if (*(int *)(lVar10 + 0x150) != 0) {
      iVar8 = (**(code **)(lVar9 + 0x50))
                        (lVar9,*(undefined4 *)(lVar4 + 0x48),*(undefined4 *)(lVar5 + 0x10),
                         local_90[0] + 0x150,*(undefined4 *)(*(long *)(param_3 + 0x50) + 0x48),
                         *(int *)(lVar10 + 0x150),0);
      pcVar14 = 
      "pRmApi->DupObject(pRmApi, pDstClient->hClient, pDstRef->hResource, &pKernelChannelGroupApi->hLegacykCtxShareAsync, pParams->pSrcClient->hClient, pChanGrpSrc->hLegacykCtxShareAsync, 0)"
      ;
      uVar15 = 0x2e7;
      if (iVar8 != 0) goto LAB_00333473;
    }
  }
  if ((*(char *)(lVar6 + 0x908) == '\0') && (*(char *)(lVar6 + 0x909) == '\0')) {
LAB_003332f5:
    lVar13 = listAppendValue_IMPL(*(long *)(local_90[0] + 0x138) + 0x1c8,local_90);
    if (lVar13 != 0) {
      return 0;
    }
  }
  else {
    lVar12 = gpuGetRpc(lVar6);
    if (lVar12 != 0) {
      uVar1 = *(undefined4 *)(lVar13 + 0x10);
      uVar2 = *(undefined4 *)(*(long *)(param_3 + 0x50) + 0x48);
      uVar3 = *(undefined4 *)(*(long *)(lVar5 + 0x18) + 0x10);
      if ((*(char *)(lVar6 + 0x909) == '\0') && (*(char *)(lVar6 + 0x90a) == '\0')) {
        uStack_110 = 0;
        iVar8 = (**(code **)(lVar12 + 0x128))
                          (lVar6,lVar12,*(undefined4 *)(lVar4 + 0x48),uVar3,
                           *(undefined4 *)(lVar5 + 0x10),uVar2,uVar1);
      }
      else {
        iVar8 = (**(code **)(lVar6 + 0x3ba8))
                          (lVar6 + 0x3b58,*(undefined4 *)(lVar4 + 0x48),uVar3,lVar5 + 0x10,uVar2,
                           uVar1,0);
        uStack_110 = extraout_RDX;
      }
      if (iVar8 != 0) goto LAB_0033338d;
      lVar13 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 8),__nvoc_class_def_RmResource,uStack_110)
      ;
      *(undefined1 *)(lVar13 + 0xa4) = 1;
      goto LAB_003332f5;
    }
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x2f5);
  }
  iVar8 = 0x1a;
LAB_0033338d:
  if (*(int *)(local_90[0] + 0x150) != 0) {
    (**(code **)(lVar9 + 0x18))(lVar9,*(undefined4 *)(lVar4 + 0x48));
  }
  if (*(int *)(local_90[0] + 0x14c) != 0) {
    (**(code **)(lVar9 + 0x18))(lVar9,*(undefined4 *)(lVar4 + 0x48));
  }
  if (*(int *)(local_90[0] + 0x148) != 0) {
    (**(code **)(lVar9 + 0x18))(lVar9,*(undefined4 *)(lVar4 + 0x48));
  }
  uVar15 = 0;
  if (*(long *)(local_90[0] + 0x138) != 0) {
    uVar15 = *(undefined8 *)(*(long *)(local_90[0] + 0x138) + 0x88);
  }
  serverFreeShare(g_resServ,uVar15);
  return iVar8;
}


// ===== 00333491 kchangrpapiConstruct_IMPL.cold =====

void kchangrpapiConstruct_IMPL_cold(void)

{
  code *pcVar1;
  
  DAT_000000a4 = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 003334b0 kchangrpapiConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kchangrpapiConstruct_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  ulong *puVar1;
  long lVar2;
  undefined4 *puVar3;
  long lVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  ulong *puVar21;
  char *extraout_RDX;
  char *pcVar22;
  char *extraout_RDX_00;
  char *extraout_RDX_01;
  char *extraout_RDX_02;
  undefined8 *puVar23;
  undefined8 extraout_RDX_03;
  undefined8 extraout_RDX_04;
  char *pcVar24;
  undefined8 uVar25;
  ulong uVar26;
  undefined8 *puVar27;
  ulong uVar28;
  undefined8 uVar29;
  undefined8 local_e8;
  ulong *local_e0;
  long local_d0;
  undefined4 local_c8;
  int local_c4;
  long local_c0;
  long local_b8;
  long local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88 [9];
  uint local_40;
  ulong uVar20;
  
  lVar19 = *(long *)(param_2 + 0x10);
  local_c0 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  local_d0 = param_1;
  lVar15 = gpuGetKernelFifoShared_IMPL(lVar2);
  local_b8 = 0;
  local_c8 = 0;
  local_e8 = *(undefined8 *)(*(long *)(lVar2 + 0x1b78) + 0x478);
  local_b0 = 0;
  lVar16 = rmapiGetInterface(4);
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x51,"kchangrpapiConstruct_IMPL",1,
               "NVRM: hClient: 0x%x, hParent: 0x%x, hObject:0x%x, hClass: 0x%x\n",*param_3,
               param_3[1],param_3[2],param_3[3]);
  if (*(long *)(param_3 + 0x16) != 0) {
    iVar9 = rmDeviceGpuLocksAcquire(lVar2,0,0x80003);
    if (iVar9 == 0) {
      iVar9 = kchangrpapiCopyConstruct_IMPL(local_d0,param_2,param_3);
      rmDeviceGpuLocksRelease(lVar2,0,0);
      local_e0 = (ulong *)0x0;
    }
    else {
      nvAssertOkFailedNoLog
                (iVar9,"rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_FIFO)",
                 "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x58);
      local_e0 = (ulong *)0x0;
    }
    goto LAB_003335d5;
  }
  cVar8 = rmDeviceGpuLockIsOwner(*(undefined4 *)(lVar2 + 0x7a4));
  if (cVar8 != '\0') {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x69,"kchangrpapiConstruct_IMPL",4
                 ,"NVRM: TSG alloc should be called without acquiring GPU lock\n");
    nvAssertFailedNoLog(&DAT_00d1e911,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x6a);
    return 0x2f;
  }
  local_e0 = (ulong *)portMemAllocNonPaged(0xf0);
  if (local_e0 == (ulong *)0x0) {
    return 0x51;
  }
  iVar9 = rmDeviceGpuLocksAcquire(lVar2,0,0x80003);
  if (iVar9 != 0) {
    nvAssertOkFailedNoLog
              (iVar9,"rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_FIFO)",
               "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x74);
    goto LAB_003335d5;
  }
  puVar3 = *(undefined4 **)(param_3 + 0x10);
  iVar11 = puVar3[2];
  iVar9 = serverAllocShareWithHalspecParent
                    (g_resServ,__nvoc_class_def_KernelChannelGroup,&local_b0,
                     *(undefined8 *)(lVar2 + 0x78));
  if (iVar9 == 0) {
    lVar17 = __nvoc_dynamicCast(local_b0,__nvoc_class_def_KernelChannelGroup);
    *(long *)(local_d0 + 0x138) = lVar17;
    cVar8 = gpuIsClassSupported_IMPL(lVar2,*(undefined4 *)(lVar19 + 0x11c));
    if (cVar8 == '\0') {
      iVar9 = 0x56;
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x86,"kchangrpapiConstruct_IMPL"
                   ,4,"NVRM: class %x not supported\n",*(undefined4 *)(lVar19 + 0x11c));
      if (*(int *)(local_d0 + 0x148) != 0) goto LAB_00333e7a;
LAB_00333e8e:
      if (lVar17 == 0) goto LAB_00333d84;
    }
    else {
      *(int *)(local_d0 + 0x154) = iVar11;
      iVar9 = serverGetClientUnderLock(g_resServ,*param_3,&local_a8);
      if (iVar9 == 0) {
        iVar9 = deviceGetByHandle_IMPL(local_a8,param_3[1],&local_b8);
        if (iVar9 != 0) {
          pcVar22 = "NVRM: Invalid parent/device handle!\n";
          uVar25 = 4;
          uVar29 = 0x99;
          goto LAB_00333f48;
        }
        lVar4 = *(long *)(lVar2 + 0x1bc0);
        if (lVar4 != 0) {
          cVar8 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar2,lVar4);
          local_c4 = gpuGetRmEngineType_IMPL(puVar3[3]);
          if (*(char *)(lVar15 + 0x4b1) == '\0') {
            pcVar22 = extraout_RDX;
            if (cVar8 == '\0') goto LAB_003340e0;
            if (*(int *)(lVar17 + 0xfc) - 1U < 0x53) goto LAB_00333785;
            nvCheckFailedNoLog(2,"RM_ENGINE_TYPE_IS_VALID(pKernelChannelGroup->engineType)",
                               "src/kernel/gpu/fifo/kernel_channel_group_api.c",0xbe);
            if (*(int *)(local_d0 + 0x148) != 0) {
              iVar9 = 0x40;
              goto LAB_00334080;
            }
LAB_003344fb:
            iVar9 = 0x40;
          }
          else {
            pcVar22 = (char *)(ulong)(local_c4 - 1U);
            if (0x52 < local_c4 - 1U) goto LAB_003341f6;
            *(int *)(lVar17 + 0xfc) = local_c4;
            if (cVar8 == '\0') {
              if (local_c4 - 2U < 7) {
                if (*(int *)(local_d0 + 0x148) != 0) {
                  (**(code **)(lVar16 + 0x18))(lVar16,*param_3);
                }
                goto LAB_00333f7b;
              }
              goto LAB_00333f1a;
            }
LAB_00333785:
            iVar9 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar2,lVar4,local_b8,&local_a0);
            uVar25 = 0xc1;
            pcVar22 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
            if (iVar9 == 0) {
              iVar9 = kmigmgrGetLocalToGlobalEngineType_IMPL
                                (lVar2,lVar4,local_a0,local_98,local_c4,&local_c4);
              if (iVar9 == 0) {
                bVar6 = true;
                *(int *)(lVar17 + 0xfc) = local_c4;
                local_e8 = *(undefined8 *)(local_a0 + 0x980);
                pcVar22 = extraout_RDX_00;
                goto LAB_00333829;
              }
              uVar25 = 200;
              pcVar22 = 
              "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, rmEngineType, &rmEngineType)"
              ;
            }
            nvCheckOkFailedNoLog
                      (4,iVar9,pcVar22,"src/kernel/gpu/fifo/kernel_channel_group_api.c",uVar25);
            iVar11 = *(int *)(local_d0 + 0x148);
joined_r0x003344c7:
            if (iVar11 != 0) {
LAB_00334080:
              (**(code **)(lVar16 + 0x18))(lVar16,*param_3);
            }
          }
          goto LAB_00333d4a;
        }
        local_c4 = gpuGetRmEngineType_IMPL(puVar3[3]);
        pcVar22 = extraout_RDX_02;
        if (*(char *)(lVar15 + 0x4b1) != '\0') {
          pcVar22 = (char *)(ulong)(local_c4 - 1U);
          if (0x52 < local_c4 - 1U) {
LAB_003341f6:
            pcVar22 = 
            "NVRM: Valid engine Id must be specified while allocating TSGs or bare channels!\n";
            uVar25 = 2;
            uVar29 = 0xa7;
            goto LAB_00333f48;
          }
          *(int *)(lVar17 + 0xfc) = local_c4;
          if (6 < local_c4 - 2U) goto LAB_00333f1a;
          if (*(int *)(local_d0 + 0x148) == 0) goto LAB_00333f7b;
          goto LAB_00333fa0;
        }
LAB_003340e0:
        if (local_c4 - 2U < 7) goto LAB_00333f56;
LAB_00333f1a:
        bVar6 = false;
LAB_00333829:
        if ((*(int *)(local_b8 + 0x1d0) == 2) && (iVar11 == 0)) {
LAB_00333879:
          if (*(char *)(lVar2 + 0x491d) == '\0') {
            cVar8 = *(char *)(lVar17 + 0x1f0);
          }
          else {
            cVar8 = *(char *)(puVar3 + 4);
            *(char *)(lVar17 + 0x1f0) = cVar8;
          }
          if (cVar8 == '\0') {
            iVar9 = vgpuGetCallingContextGfid(lVar2,&local_c8);
            uVar25 = 0xf6;
            pcVar22 = "src/kernel/gpu/fifo/kernel_channel_group_api.c";
            pcVar24 = "vgpuGetCallingContextGfid(pGpu, &gfid)";
            if (iVar9 == 0) goto LAB_003338a6;
          }
          else {
            local_c8 = 0;
LAB_003338a6:
            lVar18 = __nvoc_dynamicCast(local_a8,__nvoc_class_def_RmClient,pcVar22);
            if ((lVar18 == 0) || (cVar8 = serverIsClientInternal(g_resServ,*param_3), cVar8 == '\0')
               ) {
              iVar9 = ctxBufPoolInit(lVar2,local_e8,lVar17 + 400);
              uVar25 = 0x103;
              pcVar24 = "ctxBufPoolInit(pGpu, pHeap, &pKernelChannelGroup->pCtxBufPool)";
              if (iVar9 == 0) {
                iVar9 = ctxBufPoolInit(lVar2,local_e8,lVar17 + 0x198,0x103);
                uVar25 = 0x107;
                pcVar24 = "ctxBufPoolInit(pGpu, pHeap, &pKernelChannelGroup->pChannelBufPool)";
                if (iVar9 == 0) goto LAB_0033394c;
              }
            }
            else {
              nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x10d,
                           "kchangrpapiConstruct_IMPL",1,
                           "NVRM: Skipping ctxBufPoolInit for RC watchdog\n");
LAB_0033394c:
              iVar9 = kchangrpInit_IMPL(lVar2,lVar17,local_c0,local_c8);
              if (iVar9 == 0) {
                *(undefined8 *)(local_d0 + 0x14c) = 0;
                if (iVar11 != 0) {
                  iVar9 = clientGetResourceRef_IMPL(*(undefined8 *)(param_2 + 8),iVar11,&local_90);
                  if (iVar9 == 0) {
                    refAddDependant(CONCAT44(local_90._4_4_,(undefined4)local_90),lVar19);
                  }
                  else {
                    nvAssertFailedNoLog("rmStatus == NV_OK",
                                        "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x11d);
                  }
                }
                *(undefined4 *)(local_d0 + 0x140) = *puVar3;
                *(undefined4 *)(local_d0 + 0x144) = puVar3[1];
                iVar9 = kchangrpSetInterleaveLevel_IMPL(lVar2,lVar17,1);
                if (iVar9 == 0) {
                  if ((((*(long *)(lVar2 + 0x1d18) == 0) ||
                       (*(char *)(*(long *)(lVar2 + 0x1d18) + 0x2a9) == '\0')) ||
                      (*(char *)(*(long *)(lVar2 + 0x1b78) + 0x445) == '\0')) ||
                     (*(long *)(lVar17 + 0x198) == 0)) {
LAB_00333a70:
                    if (*(long *)(lVar17 + 400) == 0) goto LAB_0033413a;
                    if ((bVar6) &&
                       (cVar8 = kmigmgrIsEngineInInstance_IMPL
                                          (lVar2,lVar4,*(undefined4 *)(lVar17 + 0xfc),local_a0,
                                           local_98), cVar8 == '\0')) {
                      bVar7 = false;
                      uVar28 = 0;
                      goto LAB_00333b7c;
                    }
                    iVar11 = *(int *)(lVar17 + 0xfc);
                    if (iVar11 - 1U < 8) {
                      uVar25 = *(undefined8 *)(lVar2 + 0x1bd0 + (ulong)(iVar11 - 1U) * 8);
                      iVar11 = 0;
                      portMemSet(local_e0,0,0xf0);
                      kgraphicsDiscoverMaxLocalCtxBufferSize_IMPL(lVar2,uVar25);
                      uVar29 = extraout_RDX_03;
                      uVar26 = 0;
                      do {
                        cVar8 = kgrmgrIsCtxBufSupported_IMPL(iVar11,0,uVar29);
                        uVar29 = extraout_RDX_04;
                        uVar28 = uVar26;
                        if (cVar8 != '\0') {
                          uVar29 = 0x3345a6;
                          puVar21 = (ulong *)kgraphicsGetCtxBufferInfo_IMPL(lVar2,uVar25,iVar11);
                          uVar20 = *puVar21;
                          uVar28 = (ulong)((int)uVar26 + 1);
                          puVar1 = local_e0 + uVar26 * 3;
                          *puVar1 = uVar20;
                          puVar1[1] = puVar21[1];
                          puVar1[2] = puVar21[2];
                          nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x162,
                                       "kchangrpapiConstruct_IMPL",1,
                                       "NVRM: Reserving 0x%llx bytes for GR ctx bufId = %d\n",uVar20
                                       ,iVar11);
                        }
                        iVar11 = iVar11 + 1;
                        uVar26 = uVar28;
                      } while (iVar11 != 10);
                      bVar7 = true;
                      goto LAB_00333b70;
                    }
                    if (*(char *)(lVar2 + 0x909) == '\0') {
LAB_003340ff:
                      uVar12 = gpuGetNv2080EngineType_IMPL(iVar11);
                      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x18e,
                                   "kchangrpapiConstruct_IMPL",1,
                                   "NVRM: No buffer reserved for engineType %d (%d) in ctx_buf_pool\n"
                                   ,uVar12,iVar11);
                      goto LAB_0033413a;
                    }
                    iVar10 = gpuXlateClientEngineIdToEngDesc_IMPL(lVar2,iVar11,&local_90);
                    if (iVar10 == 0) {
                      lVar19 = kflcnGetKernelFalconForEngine_IMPL(lVar2,(undefined4)local_90);
                      if (lVar19 != 0) {
                        *local_e0 = (ulong)*(uint *)(lVar19 + 0x63c);
                        local_e0[1] = 0x1000;
                        *(undefined4 *)(local_e0 + 2) = 1;
                        *(undefined1 *)((long)local_e0 + 0x14) = 1;
                        uVar25 = gpuGetNv2080EngineType_IMPL(*(undefined4 *)(lVar17 + 0xfc));
                        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x187,
                                     "kchangrpapiConstruct_IMPL",1,
                                     "NVRM: Reserving 0x%llx bytes for engineType %d (%d) flcn ctx buffer\n"
                                     ,*local_e0,uVar25);
                        bVar7 = true;
                        uVar28 = 1;
                        goto LAB_00333b70;
                      }
                      iVar11 = *(int *)(lVar17 + 0xfc);
                      goto LAB_003340ff;
                    }
                    nvAssertOkFailedNoLog
                              (iVar10,
                               "gpuXlateClientEngineIdToEngDesc(pGpu, pKernelChannelGroup->engineType, &engDesc)"
                               ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x173);
LAB_00334468:
                    iVar11 = *(int *)(local_d0 + 0x148);
                    iVar9 = iVar10;
                  }
                  else {
                    if (*(long *)(lVar17 + 400) != 0) {
                      if (*(uint *)(param_2 + 0x28) < 2) {
                        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x139,
                                     "kchangrpapiConstruct_IMPL",4,
                                     "NVRM: Only kernel priv clients can skip scrubber\n");
                        iVar11 = *(int *)(local_d0 + 0x148);
                        iVar9 = 0x1f;
                        goto joined_r0x003347f1;
                      }
                      ctxBufPoolSetScrubSkip(*(long *)(lVar17 + 0x198),1);
                      ctxBufPoolSetScrubSkip(*(undefined8 *)(lVar17 + 400),1);
                      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x13e,
                                   "kchangrpapiConstruct_IMPL",1,
                                   "NVRM: Skipping scrubber for all allocations on this context\n");
                      goto LAB_00333a70;
                    }
LAB_0033413a:
                    uVar28 = 0;
                    bVar7 = false;
LAB_00333b70:
                    if (bVar6) {
LAB_00333b7c:
                      if (*(int *)(lVar17 + 0xfc) - 1U < 8) goto LAB_00333b97;
                    }
                    else {
LAB_00333b97:
                      cVar8 = rmcfg_IsT234D(lVar2);
                      if (cVar8 == '\0') {
                        if (local_d0 == 0) goto LAB_0033349b;
                        iVar10 = (**(code **)(lVar16 + 0x10))
                                           (lVar16,*param_3,
                                            *(undefined4 *)
                                             (*(long *)(*(long *)(local_d0 + 0x110) + 0x48) + 0x10),
                                            local_d0 + 0x148,0x90,0,0,1,0);
                        if (iVar10 != 0) {
                          nvAssertOkFailedNoLog
                                    (iVar10,
                                     "pRmApi->AllocWithSecInfo(pRmApi, pParams->hClient, RES_GET_HANDLE(pKernelChannelGroupApi), &pKernelChannelGroupApi->hKernelGraphicsContext, KERNEL_GRAPHICS_CONTEXT, NvP64_NULL, 0, RMAPI_ALLOC_FLAGS_SKIP_RPC, NvP64_NULL, &pRmApi->defaultSecInfo)"
                                     ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x198);
                          iVar11 = *(int *)(local_d0 + 0x148);
                          iVar9 = iVar10;
                          goto joined_r0x003347f1;
                        }
                      }
                    }
                    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x1a6,
                                 "kchangrpapiConstruct_IMPL",1,
                                 "NVRM: Adding group Id: %d hClient:0x%x\n",
                                 *(undefined4 *)(lVar17 + 0xf0));
                    if (((*(char *)(lVar2 + 0x908) != '\0') || (*(char *)(lVar2 + 0x909) != '\0'))
                       && ((*(byte *)(param_3 + 0xc) & 1) == 0)) {
                      lVar19 = gpuGetRpc(lVar2);
                      if (lVar19 != 0) {
                        if ((*(char *)(lVar2 + 0x909) == '\0') && (*(char *)(lVar2 + 0x90a) == '\0')
                           ) {
                          iVar10 = (**(code **)(lVar19 + 0x348))
                                             (lVar2,lVar19,*param_3,param_3[1],param_3[2],param_3[3]
                                              ,puVar3,lVar19);
                        }
                        else {
                          iVar10 = (**(code **)(lVar2 + 0x3b60))(lVar2 + 0x3b58,*param_3);
                        }
                        if (local_d0 == 0) {
                          DAT_000000a4 = 0;
                    /* WARNING: Does not return */
                          pcVar5 = (code *)invalidInstructionException();
                          (*pcVar5)();
                        }
                        *(undefined1 *)(*(long *)(local_d0 + 0x120) + 0xa4) = 1;
                        if (iVar10 == 0) goto LAB_0033429d;
                        pcVar22 = "NVRM: KernelChannelGroupApi alloc RPC to vGpu Host failed\n";
                        uVar25 = 0x1bd;
LAB_0033445a:
                        nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",uVar25,
                                     "kchangrpapiConstruct_IMPL",4,pcVar22);
                        goto LAB_00334468;
                      }
                      nvAssertFailedNoLog("pRpc != NULL",
                                          "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x1ac);
                      if (local_d0 == 0) {
                        DAT_000000a4 = 0;
                    /* WARNING: Does not return */
                        pcVar5 = (code *)invalidInstructionException();
                        (*pcVar5)();
                      }
                      *(undefined1 *)(*(long *)(local_d0 + 0x120) + 0xa4) = 1;
LAB_0033429d:
                      if (((*(char *)(lVar2 + 0x4913) != '\0') &&
                          (*(char *)(lVar2 + 0x491e) == '\0')) || (*(char *)(lVar2 + 0x909) != '\0')
                         ) {
                        uVar26 = 0;
                        do {
                          uVar13 = (int)uVar26 + 0x20;
                          uVar20 = (ulong)uVar13;
                          *(undefined8 *)((long)&local_90 + uVar26) = 0;
                          *(undefined8 *)((long)local_88 + uVar26) = 0;
                          *(undefined8 *)((long)local_88 + uVar26 + 8) = 0;
                          *(undefined8 *)((long)local_88 + uVar26 + 0x10) = 0;
                          uVar26 = uVar20;
                        } while (uVar13 < 0x40);
                        *(undefined8 *)((long)&local_90 + uVar20) = 0;
                        *(undefined8 *)((long)local_88 + uVar20) = 0;
                        *(undefined8 *)((long)local_88 + uVar20 + 8) = 0;
                        uVar13 = (**(code **)(lVar15 + 0x200))(lVar2);
                        if (uVar13 != 0) {
                          uVar26 = 0;
                          puVar27 = &local_90;
                          do {
                            puVar23 = (undefined8 *)(uVar26 * 0x10 + *(long *)(lVar17 + 0x160));
                            lVar19 = puVar23[1];
                            puVar27[1] = *(undefined8 *)(lVar19 + 0x30);
                            uVar14 = memdescGetAddressSpace(lVar19);
                            uVar12 = *(undefined4 *)(lVar19 + 0x74);
                            puVar27[2] = 1;
                            puVar27[3] = CONCAT44(uVar12,uVar14);
                            if ((*(char *)(lVar2 + 0x4913) == '\0') ||
                               (*(char *)(lVar2 + 0x491e) != '\0')) {
                              uVar25 = memdescGetPhysAddr(lVar19,1,0);
                            }
                            else {
                              local_88[uVar26 + 7] = *puVar23;
                              uVar25 = memdescGetPhysAddr(lVar19,0,0);
                            }
                            *puVar27 = uVar25;
                            uVar26 = uVar26 + 1;
                            puVar27 = puVar27 + 4;
                          } while (uVar26 != uVar13);
                        }
                        local_40 = uVar13;
                        if (local_d0 == 0) {
LAB_0033349b:
                    /* WARNING: Does not return */
                          pcVar5 = (code *)invalidInstructionException();
                          (*pcVar5)();
                        }
                        iVar10 = (**(code **)(lVar16 + 0x38))
                                           (lVar16,*param_3,
                                            *(undefined4 *)
                                             (*(long *)(*(long *)(local_d0 + 0x110) + 0x48) + 0x10),
                                            0xa06c010a,&local_90,0x58);
                        if (iVar10 != 0) {
                          pcVar22 = "NVRM: Control call to update method buffer memdesc failed\n";
                          uVar25 = 500;
                          goto LAB_0033445a;
                        }
                      }
                    }
                    uVar25 = portMemAllocatorGetGlobalNonPaged();
                    lVar19 = lVar17 + 0x1c8;
                    listInit_IMPL(lVar19,uVar25,8);
                    lVar15 = listAppendValue_IMPL(lVar19,&local_d0);
                    if (lVar15 == 0) {
                      iVar9 = 0x1a;
                      listDestroy_IMPL(lVar19);
                      iVar11 = *(int *)(local_d0 + 0x148);
                    }
                    else {
                      rmDeviceGpuLocksRelease(lVar2,0,0);
                      if ((!bVar7) ||
                         (iVar9 = ctxBufPoolReserve(lVar2,*(undefined8 *)(lVar17 + 400),local_e0,
                                                    uVar28), iVar9 == 0)) goto LAB_003335d5;
                      nvCheckOkFailedNoLog
                                (4,iVar9,
                                 "ctxBufPoolReserve(pGpu, pKernelChannelGroup->pCtxBufPool, bufInfoList, bufCount)"
                                 ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x22d);
                      iVar11 = rmDeviceGpuLocksAcquire(lVar2,0,0x80003);
                      if (iVar11 != 0) {
                        nvAssertOkFailedNoLog
                                  (iVar11,
                                   "rmDeviceGpuLocksAcquire(pGpu, GPUS_LOCK_FLAGS_NONE, RM_LOCK_MODULES_FIFO)"
                                   ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x232);
                        return iVar11;
                      }
                      iVar11 = *(int *)(local_d0 + 0x148);
                    }
                  }
                }
                else {
                  nvAssertOkFailedNoLog
                            (iVar9,
                             "kchangrpSetInterleaveLevel(pGpu, pKernelChannelGroup, NVA06C_CTRL_INTERLEAVE_LEVEL_MEDIUM)"
                             ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x126);
                  iVar11 = *(int *)(local_d0 + 0x148);
                }
joined_r0x003347f1:
                if (iVar11 != 0) {
                  (**(code **)(lVar16 + 0x18))(lVar16,*param_3);
                }
                kchangrpDestroy_IMPL(lVar2,lVar17);
                goto LAB_00333d4a;
              }
              uVar25 = 0x111;
              pcVar24 = "kchangrpInit(pGpu, pKernelChannelGroup, pVAS, gfid)";
            }
          }
          nvAssertOkFailedNoLog
                    (iVar9,pcVar24,"src/kernel/gpu/fifo/kernel_channel_group_api.c",uVar25);
          iVar11 = *(int *)(local_d0 + 0x148);
          goto joined_r0x003344c7;
        }
        iVar9 = vaspaceGetByHandleOrDeviceDefault_IMPL(local_a8,param_3[1],iVar11,&local_c0);
        if (iVar9 == 0) {
          pcVar22 = extraout_RDX_01;
          if (local_c0 != 0) goto LAB_00333879;
          if (*(int *)(local_d0 + 0x148) == 0) {
            iVar9 = 0x40;
            if (lVar17 != 0) goto LAB_003344fb;
            goto LAB_00333d84;
          }
          iVar9 = 0x40;
        }
        else {
          nvAssertOkFailedNoLog
                    (iVar9,
                     "vaspaceGetByHandleOrDeviceDefault(pClient, pParams->hParent, hVASpace, &pVAS)"
                     ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0xe0);
          if (*(int *)(local_d0 + 0x148) == 0) goto LAB_00333e8e;
        }
LAB_00333e7a:
        (**(code **)(lVar16 + 0x18))(lVar16,*param_3);
        goto LAB_00333e8e;
      }
      pcVar22 = "NVRM: Invalid client handle!\n";
      uVar25 = 4;
      uVar29 = 0x91;
LAB_00333f48:
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",uVar29,
                   "kchangrpapiConstruct_IMPL",uVar25,pcVar22);
LAB_00333f56:
      if (*(int *)(local_d0 + 0x148) != 0) {
LAB_00333fa0:
        iVar9 = 0x1f;
        goto LAB_00333e7a;
      }
      iVar9 = 0x1f;
      if (lVar17 == 0) goto LAB_00333d84;
LAB_00333f7b:
      iVar9 = 0x1f;
    }
LAB_00333d4a:
    if (*(long *)(lVar17 + 400) != 0) {
      ctxBufPoolDestroy(lVar17 + 400);
    }
    if (*(long *)(lVar17 + 0x198) != 0) {
      ctxBufPoolDestroy(lVar17 + 0x198);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar9,
               "serverAllocShareWithHalspecParent(&g_resServ, classInfo(KernelChannelGroup), &pShared, staticCast(pGpu, Object))"
               ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x7c);
    if (*(int *)(local_d0 + 0x148) != 0) {
      (**(code **)(lVar16 + 0x18))(lVar16,*param_3);
    }
  }
LAB_00333d84:
  if (local_b0 == 0) {
    rmDeviceGpuLocksRelease(lVar2,0,0);
  }
  else {
    serverFreeShare(g_resServ);
    rmDeviceGpuLocksRelease(lVar2,0,0);
  }
LAB_003335d5:
  portMemFree(local_e0);
  return iVar9;
}


// ===== 003348a0 kchangrpapiCanCopy_IMPL =====

undefined8 kchangrpapiCanCopy_IMPL(void)

{
  return 1;
}


// ===== 003348b0 CliGetChannelGroup =====

ulong CliGetChannelGroup(undefined4 param_1,undefined4 param_2,long *param_3,undefined4 *param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined8 local_38;
  long local_30 [2];
  
  if (param_3 != (long *)0x0) {
    uVar1 = serverGetClientUnderLock(g_resServ,param_1,&local_38);
    if (uVar1 == 0) {
      uVar2 = clientGetResourceRefByType_IMPL(local_38,param_2,0x2b5b80,local_30);
      if ((int)uVar2 == 0) {
        *param_3 = local_30[0];
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = *(undefined4 *)(*(long *)(local_30[0] + 0x18) + 0x10);
        }
      }
    }
    else {
      nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x33a);
      uVar2 = (ulong)uVar1;
    }
    return uVar2;
  }
  return 0x1f;
}


// ===== 00334950 kchangrpapiSetLegacyMode_IMPL.cold =====

void kchangrpapiSetLegacyMode_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00334960 kchangrpapiSetLegacyMode_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */
/* WARNING: Type propagation algorithm not settling */

int kchangrpapiSetLegacyMode_IMPL(long param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  long **local_b8;
  long *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined4 local_7c;
  ulong local_78;
  ulong local_70 [2];
  int local_60;
  long *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  
  lVar3 = *(long *)(param_1 + 0x138);
  local_7c = 0;
  local_78 = 0;
  uVar2 = *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x110) + 0x48) + 0x10);
  local_70[0] = 0;
  lVar11 = rmapiGetInterface(4);
  local_60 = 0;
  local_70[1] = 0;
  iVar8 = (**(code **)(*(long *)(lVar3 + 0x110) + 0x28))(*(long *)(lVar3 + 0x110),&local_78);
  if (iVar8 != 0) {
    nvAssertOkFailedNoLog
              (iVar8,
               "pKernelChannelGroup->pSubctxIdHeap->eheapGetSize( pKernelChannelGroup->pSubctxIdHeap, &numMax)"
               ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",900);
  }
  iVar8 = (**(code **)(*(long *)(lVar3 + 0x110) + 0x30))(*(long *)(lVar3 + 0x110),local_70);
  if (iVar8 != 0) {
    nvAssertOkFailedNoLog
              (iVar8,
               "pKernelChannelGroup->pSubctxIdHeap->eheapGetFree( pKernelChannelGroup->pSubctxIdHeap, &numFree)"
               ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x388);
  }
  uVar9 = (**(code **)(param_3 + 0x1f0))(param_2,param_3,lVar3,0);
  if (uVar9 != local_78) {
    nvAssertFailedNoLog("numMax == kfifoChannelGroupGetLocalMaxSubcontext_HAL(pGpu, pKernelFifo, pKernelChannelGroup, NV_FALSE)"
                        ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x38c);
  }
  if ((local_70[0] != local_78) || (local_78 == 0)) {
    nvAssertFailedNoLog("numMax == numFree && numMax != 0",
                        "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x391);
    return 0x40;
  }
  (*(code *)**(undefined8 **)(lVar3 + 0x110))();
  (*(code *)**(undefined8 **)(lVar3 + 0x138))();
  iVar8 = (**(code **)(param_3 + 0x1f0))(param_2,param_3,lVar3,1);
  if (local_78 != local_70[0]) {
    nvAssertFailedNoLog("numMax == numFree","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x39e);
    return 0x40;
  }
  if (1 < iVar8 - 1U) {
    nvAssertFailedNoLog("maxSubctx == 1 || maxSubctx == 2",
                        "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x39f);
  }
  constructObjEHeap(*(undefined8 *)(lVar3 + 0x110),0,iVar8,8,0);
  constructObjEHeap(*(undefined8 *)(lVar3 + 0x138),0,iVar8,8,0);
  *(undefined1 *)(lVar3 + 0x159) = 1;
  local_7c = 0;
  local_70[1] = 0;
  local_60 = -1;
  iVar10 = (**(code **)(lVar11 + 0x10))
                     (lVar11,param_4,uVar2,&local_7c,0x9067,local_70 + 1,0xc,1,0,lVar11 + 0xb8);
  uVar13 = 0x3ae;
  lVar1 = lVar3 + 0x1c8;
  if (iVar10 == 0) {
    if (local_60 != 0) {
      nvAssertFailedNoLog("kctxshareParams.subctxId == NV_CTXSHARE_ALLOCATION_FLAGS_SUBCONTEXT_SYNC"
                          ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x3bb,0x3ae);
    }
    *(undefined4 *)(param_1 + 0x14c) = local_7c;
    if (iVar8 == 2) {
      local_7c = 0;
      local_60 = -1;
      local_70[1] = 0x100000000;
      iVar10 = (**(code **)(lVar11 + 0x10))
                         (lVar11,param_4,uVar2,&local_7c,0x9067,local_70 + 1,0xc,1,0,lVar11 + 0xb8);
      if (iVar10 != 0) {
        uVar13 = 0x3c7;
        goto LAB_00334f79;
      }
      if (local_60 != 1) {
        nvAssertFailedNoLog("kctxshareParams.subctxId == NV_CTXSHARE_ALLOCATION_FLAGS_SUBCONTEXT_ASYNC"
                            ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x3d4);
      }
      *(undefined4 *)(param_1 + 0x150) = local_7c;
    }
    iVar10 = (**(code **)(*(long *)(lVar3 + 0x110) + 0x30))(*(long *)(lVar3 + 0x110),local_70);
    if (iVar10 == 0) {
      if (local_70[0] == 0) {
        uVar13 = listTail_IMPL(lVar1);
        uVar12 = listHead_IMPL(lVar1);
        listIterRange_IMPL(&local_a8,lVar1,uVar12,uVar13);
        local_58 = local_a8;
        local_50 = local_a0;
        local_48 = local_98;
        local_40 = local_90;
        do {
          do {
            cVar7 = listIterNext_IMPL(&local_58);
            if (cVar7 == '\0') {
              return 0;
            }
            lVar4 = *local_58;
          } while (param_1 == lVar4);
          if (lVar4 == 0) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)invalidInstructionException();
            (*pcVar6)();
          }
          plVar5 = *(long **)(*(long *)(lVar4 + 0x110) + 0x48);
          iVar10 = (**(code **)(lVar11 + 0x50))
                             (lVar11,*(undefined4 *)(*plVar5 + 0x48),(int)plVar5[2],lVar4 + 0x14c,
                              *(undefined4 *)(**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48)
                              ,*(undefined4 *)(param_1 + 0x14c),0);
          if (iVar10 != 0) {
            nvCheckOkFailedNoLog
                      (4,iVar10,
                       "pRmApi->DupObject(pRmApi, RES_GET_CLIENT_HANDLE(pChanGrpDest), RES_GET_HANDLE(pChanGrpDest), &pChanGrpDest->hLegacykCtxShareSync, RES_GET_CLIENT_HANDLE(pKernelChannelGroupApi), pKernelChannelGroupApi->hLegacykCtxShareSync, 0)"
                       ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x3ee);
            goto LAB_00334dab;
          }
        } while ((iVar8 != 2) ||
                (plVar5 = *(long **)(*(long *)(lVar4 + 0x110) + 0x48),
                iVar10 = (**(code **)(lVar11 + 0x50))
                                   (lVar11,*(undefined4 *)(*plVar5 + 0x48),(int)plVar5[2],
                                    lVar4 + 0x150,
                                    *(undefined4 *)
                                     (**(long **)(*(long *)(param_1 + 0x110) + 0x48) + 0x48),
                                    *(undefined4 *)(param_1 + 0x150),0), iVar10 == 0));
        nvCheckOkFailedNoLog
                  (4,iVar10,
                   "pRmApi->DupObject(pRmApi, RES_GET_CLIENT_HANDLE(pChanGrpDest), RES_GET_HANDLE(pChanGrpDest), &pChanGrpDest->hLegacykCtxShareAsync, RES_GET_CLIENT_HANDLE(pKernelChannelGroupApi), pKernelChannelGroupApi->hLegacykCtxShareAsync, 0)"
                   ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x3fa);
      }
      else {
        nvAssertFailedNoLog("numFree == 0","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x3df);
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar10,
                 "pKernelChannelGroup->pSubctxIdHeap->eheapGetFree( pKernelChannelGroup->pSubctxIdHeap, &numFree)"
                 ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x3d9);
    }
  }
  else {
LAB_00334f79:
    nvAssertOkFailedNoLog
              (iVar10,
               "pRmApi->AllocWithSecInfo(pRmApi, hClient, hTsg, &hkCtxShare, FERMI_CONTEXT_SHARE_A, NV_PTR_TO_NvP64(&kctxshareParams), sizeof(kctxshareParams), RMAPI_ALLOC_FLAGS_SKIP_RPC, NvP64_NULL, &pRmApi->defaultSecInfo)"
               ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",uVar13);
  }
LAB_00334dab:
  local_b8 = &local_a8;
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x409,
               "kchangrpapiSetLegacyMode_IMPL",4,
               "NVRM: Failed to set channel group in legacy mode.\n");
  *(undefined1 *)(lVar3 + 0x159) = 0;
  uVar13 = listTail_IMPL(lVar1);
  uVar12 = listHead_IMPL(lVar1);
  listIterRange_IMPL(local_b8,lVar1,uVar12,uVar13);
  local_58 = local_a8;
  local_50 = local_a0;
  local_48 = local_98;
  local_40 = local_90;
  while (cVar7 = listIterNext_IMPL(&local_58), cVar7 != '\0') {
    lVar3 = *local_58;
    if (*(int *)(lVar3 + 0x14c) != 0) {
      (**(code **)(lVar11 + 0x18))
                (lVar11,*(undefined4 *)(**(long **)(*(long *)(lVar3 + 0x110) + 0x48) + 0x48));
      *(undefined4 *)(lVar3 + 0x14c) = 0;
    }
    if (*(int *)(lVar3 + 0x150) != 0) {
      (**(code **)(lVar11 + 0x18))
                (lVar11,*(undefined4 *)(**(long **)(*(long *)(lVar3 + 0x110) + 0x48) + 0x48));
      *(undefined4 *)(lVar3 + 0x150) = 0;
    }
  }
  if (iVar10 == 0) {
    return 0x40;
  }
  return iVar10;
}


// ===== 00335080 kchangrpapiCtrlCmdGpFifoSchedule_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchangrpapiCtrlCmdGpFifoSchedule_IMPL(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  long *plVar11;
  int iVar12;
  long local_40 [2];
  
  lVar9 = *(long *)(param_1 + 0x138);
  local_40[0] = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar8 = *(long *)(*(long *)(param_1 + 0x110) + 0x48);
  if (lVar9 == 0) {
    return 0x31;
  }
  iVar7 = gpuGetClassByClassId_IMPL(lVar3,*(undefined4 *)(lVar8 + 0x11c),local_40);
  if (iVar7 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x440,
                 "kchangrpapiCtrlCmdGpFifoSchedule_IMPL",4,"NVRM: class %x not supported\n",
                 *(undefined4 *)(lVar8 + 0x11c));
  }
  if (local_40[0] == 0) {
    nvAssertFailedNoLog("(pClass != NULL)","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x443);
    uVar10 = 0x56;
  }
  else {
    for (puVar4 = (undefined8 *)**(undefined8 **)(lVar9 + 0x140); puVar4 != (undefined8 *)0x0;
        puVar4 = (undefined8 *)puVar4[1]) {
      cVar6 = kchannelIsSchedulable_IMPL(lVar3,*puVar4);
      if (cVar6 == '\0') {
        nvCheckFailedNoLog(2,"kchannelIsSchedulable_HAL(pGpu, pChanNode->pKernelChannel)",
                           "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x453);
        return 0x40;
      }
    }
    lVar8 = gpuGetKernelFifoShared_IMPL(lVar3);
    puVar4 = *(undefined8 **)(lVar9 + 0x140);
    iVar7 = *(int *)(lVar9 + 0xf4);
    for (plVar11 = (long *)*puVar4; iVar12 = iVar7, plVar11 != (long *)0x0;
        plVar11 = (long *)plVar11[1]) {
      while (lVar5 = *plVar11, lVar5 != 0) {
        cVar6 = kchannelIsRunlistSet(lVar3,lVar5);
        if (cVar6 == '\0') goto LAB_003351f0;
        iVar7 = *(int *)(lVar5 + 0x2b0);
        if (iVar12 != -1) {
          if (iVar12 != iVar7) {
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x474,
                         "kchangrpapiCtrlCmdGpFifoSchedule_IMPL",4,
                         "NVRM: Channels in TSG %d have different runlist IDs this should never happen!\n"
                         ,*(undefined4 *)(lVar9 + 0xf0));
          }
          goto LAB_003351f0;
        }
        plVar11 = (long *)plVar11[1];
        iVar12 = iVar7;
        if (plVar11 == (long *)0x0) goto LAB_00335238;
      }
      nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_channel_group_api.c",
                          0x468);
LAB_003351f0:
      iVar7 = iVar12;
    }
LAB_00335238:
    if (iVar7 == -1) {
      iVar7 = (**(code **)(lVar8 + 0x198))(lVar3,lVar8,*(undefined4 *)(lVar9 + 0xfc));
    }
    *(int *)(lVar9 + 0xf4) = iVar7;
    for (plVar11 = (long *)*puVar4; plVar11 != (long *)0x0; plVar11 = (long *)plVar11[1]) {
      lVar9 = *plVar11;
      if (lVar9 == 0) {
        nvAssertFailedNoLog("pKernelChannel != NULL",
                            "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x48f);
      }
      else {
        cVar6 = kchannelIsRunlistSet(lVar3,lVar9);
        if (cVar6 == '\0') {
          (**(code **)(lVar8 + 0x300))(lVar3,lVar8,lVar9,iVar7);
        }
      }
    }
    if ((*(char *)(lVar3 + 0x908) == '\0') && (*(char *)(lVar3 + 0x909) == '\0')) {
      plVar11 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
      uVar10 = (**(code **)(lVar3 + 0x3b90))
                         (lVar3 + 0x3b58,*(undefined4 *)(*plVar11 + 0x48),(int)plVar11[2],0xa06c0201
                          ,param_2,3);
      return uVar10;
    }
    lVar9 = resservGetTlsCallContext();
    lVar9 = *(long *)(lVar9 + 0x48);
    plVar11 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
    uVar1 = (undefined4)plVar11[2];
    uVar2 = *(undefined4 *)(*plVar11 + 0x48);
    lVar8 = gpuGetRpc(lVar3);
    if (lVar8 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x49f);
      uVar10 = 0x1a;
    }
    else if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
      uVar10 = rpcDmaControl_wrapper
                         (lVar3,lVar8,uVar2,uVar1,*(undefined4 *)(lVar9 + 8),
                          *(undefined8 *)(lVar9 + 0x10),*(undefined4 *)(lVar9 + 0x18));
    }
    else {
      uVar10 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,uVar2,uVar1);
    }
  }
  return uVar10;
}


// ===== 003354d0 kchangrpapiCtrlCmdBind_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int kchangrpapiCtrlCmdBind_IMPL(long param_1,undefined4 *param_2)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  long lVar11;
  char *pcVar12;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x1bc0) != 0)) {
    uVar10 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe8);
    cVar6 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(lVar1);
    if (cVar6 != '\0') {
      if (param_2 == (undefined4 *)0x0) goto LAB_00335706;
      uVar9 = gpuGetRmEngineType_IMPL(*param_2);
      uVar4 = *(undefined8 *)(lVar1 + 0x1bc0);
      local_4c = uVar9;
      iVar7 = kmigmgrGetInstanceRefFromDevice_IMPL(lVar1,uVar4,uVar10,&local_48);
      if (iVar7 != 0) {
        uVar10 = 0x4d1;
        pcVar12 = "kmigmgrGetInstanceRefFromDevice(pGpu, pKernelMIGManager, pDevice, &ref)";
LAB_003356ef:
        nvCheckOkFailedNoLog
                  (4,iVar7,pcVar12,"src/kernel/gpu/fifo/kernel_channel_group_api.c",uVar10);
        return iVar7;
      }
      iVar7 = kmigmgrGetLocalToGlobalEngineType_IMPL
                        (lVar1,uVar4,CONCAT44(uStack_44,local_48),local_40,uVar9,&local_4c);
      if (iVar7 != 0) {
        uVar10 = 0x4d4;
        pcVar12 = 
        "kmigmgrGetLocalToGlobalEngineType(pGpu, pKernelMIGManager, ref, localEngineType, &globalEngineType)"
        ;
        goto LAB_003356ef;
      }
      goto LAB_00335544;
    }
  }
  if (param_2 == (undefined4 *)0x0) {
LAB_00335706:
    nvAssertFailedNoLog("pParams != NULL","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x4c8);
    return 0x1f;
  }
  local_4c = gpuGetRmEngineType_IMPL(*param_2);
  uVar9 = local_4c;
LAB_00335544:
  uVar10 = gpuGetNv2080EngineType_IMPL(local_4c);
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x4da,"kchangrpapiCtrlCmdBind_IMPL",
               1,"NVRM: Binding TSG %d to Engine %d (%d)\n",
               *(undefined4 *)(*(long *)(param_1 + 0x138) + 0xf0),uVar10);
  iVar7 = gpuXlateClientEngineIdToEngDesc_IMPL(lVar1,local_4c,&local_48);
  uVar5 = local_48;
  if (iVar7 == 0) {
    lVar2 = *(long *)(param_1 + 0x138);
    lVar11 = gpuGetKernelFifoShared_IMPL(lVar1);
    iVar7 = (**(code **)(lVar11 + 0x218))(lVar1,lVar11,0,uVar5,3,lVar2 + 0xf4);
    if (iVar7 != 0) {
      nvAssertOkFailedNoLog
                (iVar7,
                 "kfifoEngineInfoXlate_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), ENGINE_INFO_TYPE_ENG_DESC, engineDesc, ENGINE_INFO_TYPE_RUNLIST, &pKernelChannelGroupApi->pKernelChannelGroup->runlistId)"
                 ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x4e4);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar7,"gpuXlateClientEngineIdToEngDesc(pGpu, globalEngineType, &engineDesc)",
               "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x4e0);
    uVar5 = local_48;
    lVar2 = *(long *)(param_1 + 0x138);
    lVar11 = gpuGetKernelFifoShared_IMPL(lVar1);
    iVar8 = (**(code **)(lVar11 + 0x218))(lVar1,lVar11,0,uVar5,3,lVar2 + 0xf4);
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,
                 "kfifoEngineInfoXlate_HAL(pGpu, GPU_GET_KERNEL_FIFO(pGpu), ENGINE_INFO_TYPE_ENG_DESC, engineDesc, ENGINE_INFO_TYPE_RUNLIST, &pKernelChannelGroupApi->pKernelChannelGroup->runlistId)"
                 ,"src/kernel/gpu/fifo/kernel_channel_group_api.c",0x4e4);
    }
  }
  puVar3 = (undefined8 *)**(undefined8 **)(*(long *)(param_1 + 0x138) + 0x140);
  while( true ) {
    if (puVar3 == (undefined8 *)0x0) {
      return iVar7;
    }
    iVar8 = kchannelBindToRunlist_IMPL(*puVar3,uVar9,local_48);
    if (iVar8 != 0) break;
    if (iVar7 != 0) {
      return iVar7;
    }
    puVar3 = (undefined8 *)puVar3[1];
  }
  nvAssertOkFailedNoLog
            (iVar8,"kchannelBindToRunlist(pChanNode->pKernelChannel, localEngineType, engineDesc)",
             "src/kernel/gpu/fifo/kernel_channel_group_api.c",0x4f0);
  if (iVar7 == 0) {
    return iVar8;
  }
  return iVar7;
}


// ===== 003357f0 kchangrpapiCtrlCmdGetTimeslice_IMPL =====

undefined8 kchangrpapiCtrlCmdGetTimeslice_IMPL(long param_1,undefined8 *param_2)

{
  if (*(long *)(param_1 + 0x138) != 0) {
    *param_2 = *(undefined8 *)(*(long *)(param_1 + 0x138) + 0x148);
    return 0;
  }
  return 0x31;
}


// ===== 00335820 kchangrpapiCtrlCmdSetTimeslice_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchangrpapiCtrlCmdSetTimeslice_IMPL(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  undefined8 *puVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  long local_40 [2];
  
  lVar3 = *(long *)(param_1 + 0x138);
  local_40[0] = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar8 = *(long *)(*(long *)(param_1 + 0x110) + 0x48);
  if (lVar3 == 0) {
    return 0x31;
  }
  iVar7 = gpuGetClassByClassId_IMPL(lVar4,*(undefined4 *)(lVar8 + 0x11c),local_40);
  if (iVar7 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x523,
                 "kchangrpapiCtrlCmdSetTimeslice_IMPL",4,"NVRM: class %x not supported\n",
                 *(undefined4 *)(lVar8 + 0x11c));
  }
  if (local_40[0] == 0) {
    nvAssertFailedNoLog("(pClass != NULL)","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x526);
    uVar10 = 0x56;
  }
  else if ((*(char *)(lVar4 + 0x908) == '\0') && (*(char *)(lVar4 + 0x909) == '\0')) {
    plVar5 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
    uVar10 = (**(code **)(lVar4 + 0x3b90))
                       (lVar4 + 0x3b58,*(undefined4 *)(*plVar5 + 0x48),(int)plVar5[2],0xa06c0202,
                        param_2,8);
  }
  else {
    lVar8 = resservGetTlsCallContext();
    lVar8 = *(long *)(lVar8 + 0x48);
    plVar5 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
    puVar6 = *(undefined8 **)(lVar8 + 0x10);
    uVar1 = (undefined4)plVar5[2];
    uVar2 = *(undefined4 *)(*plVar5 + 0x48);
    lVar9 = gpuGetRpc(lVar4);
    if (lVar9 != 0) {
      if ((*(char *)(lVar4 + 0x909) == '\0') && (*(char *)(lVar4 + 0x90a) == '\0')) {
        uVar10 = rpcDmaControl_wrapper
                           (lVar4,lVar9,uVar2,uVar1,*(undefined4 *)(lVar8 + 8),
                            *(undefined8 *)(lVar8 + 0x10),*(undefined4 *)(lVar8 + 0x18));
      }
      else {
        uVar10 = (**(code **)(lVar4 + 0x3b90))(lVar4 + 0x3b58,uVar2,uVar1);
      }
      if ((int)uVar10 == 0) {
        *(undefined8 *)(lVar3 + 0x148) = *puVar6;
        return uVar10;
      }
      return uVar10;
    }
    nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x530);
    uVar10 = 0x1a;
  }
  return uVar10;
}


// ===== 00335aa0 kchangrpapiCtrlCmdGetInfo_IMPL =====

undefined8 kchangrpapiCtrlCmdGetInfo_IMPL(long param_1,undefined4 *param_2)

{
  if (*(long *)(param_1 + 0x138) != 0) {
    *param_2 = *(undefined4 *)(*(long *)(param_1 + 0x138) + 0xf0);
    return 0;
  }
  return 0x31;
}


// ===== 00335ad0 kchangrpapiCtrlCmdSetInterleaveLevel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kchangrpapiCtrlCmdSetInterleaveLevel_IMPL(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long local_40 [2];
  
  uVar8 = *(undefined8 *)(param_1 + 0x138);
  local_40[0] = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar6 = *(long *)(*(long *)(param_1 + 0x110) + 0x48);
  iVar5 = gpuGetClassByClassId_IMPL(lVar3,*(undefined4 *)(lVar6 + 0x11c),local_40);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_channel_group_api.c",0x571,
                 "kchangrpapiCtrlCmdSetInterleaveLevel_IMPL",4,"NVRM: class %x not supported\n",
                 *(undefined4 *)(lVar6 + 0x11c));
  }
  if (local_40[0] == 0) {
    nvAssertFailedNoLog("(pClass != NULL)","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x574);
  }
  else {
    if ((*(char *)(lVar3 + 0x908) == '\0') && (*(char *)(lVar3 + 0x909) == '\0')) {
LAB_00335bb4:
      uVar8 = kchangrpSetInterleaveLevel_IMPL(lVar3,uVar8,*param_2);
      return uVar8;
    }
    lVar6 = resservGetTlsCallContext();
    lVar6 = *(long *)(lVar6 + 0x48);
    plVar4 = *(long **)(*(long *)(param_1 + 0x110) + 0x48);
    uVar1 = (undefined4)plVar4[2];
    uVar2 = *(undefined4 *)(*plVar4 + 0x48);
    lVar7 = gpuGetRpc(lVar3);
    if (lVar7 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x57d);
    }
    else {
      if ((*(char *)(lVar3 + 0x909) == '\0') && (*(char *)(lVar3 + 0x90a) == '\0')) {
        iVar5 = rpcDmaControl_wrapper
                          (lVar3,lVar7,uVar2,uVar1,*(undefined4 *)(lVar6 + 8),
                           *(undefined8 *)(lVar6 + 0x10),*(undefined4 *)(lVar6 + 0x18));
      }
      else {
        iVar5 = (**(code **)(lVar3 + 0x3b90))(lVar3 + 0x3b58,uVar2,uVar1);
      }
      if (iVar5 == 0) goto LAB_00335bb4;
    }
    nvCheckFailedNoLog(1,"status == NV_OK","src/kernel/gpu/fifo/kernel_channel_group_api.c",0x584);
  }
  return 0x56;
}


// ===== 00335cb0 kctxshareapiCopyConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_r10 replaced with injection: x86_indirect_thunk_r10 */

int kctxshareapiCopyConstruct_IMPL(long param_1,long param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  char cVar8;
  int iVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  undefined8 extraout_RDX;
  undefined8 uVar14;
  undefined8 uStack_110;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40;
  
  lVar13 = *(long *)(param_3 + 0x58);
  lVar5 = *(long *)(param_2 + 8);
  lVar6 = *(long *)(param_2 + 0x10);
  lVar7 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  lVar10 = __nvoc_dynamicCast(*(undefined8 *)(lVar13 + 8),__nvoc_class_def_KernelCtxShareApi);
  lVar12 = *(long *)(lVar6 + 0x18);
  lVar10 = *(long *)(lVar10 + 0x138);
  *(long *)(param_1 + 0x138) = lVar10;
  uVar14 = 0;
  if (lVar10 != 0) {
    uVar14 = *(undefined8 *)(lVar10 + 0x88);
  }
  serverRefShare(g_resServ,uVar14);
  serverutilRefIter(&local_d8,*(undefined4 *)(lVar5 + 0x48),
                    *(undefined4 *)(*(long *)(*(long *)(lVar6 + 0x18) + 0x18) + 0x10),
                    "A RTXA6000-4C",1,1);
  local_80 = local_d8;
  local_78 = local_d0;
  local_70 = local_c8;
  local_68 = local_c0;
  local_60 = local_b8;
  local_58 = local_b0;
  local_50 = local_a8;
  local_48 = local_a0;
  local_40 = local_98;
  do {
    cVar8 = clientRefIterNext(local_60,&local_80);
    lVar10 = local_48;
    if (cVar8 == '\0') goto LAB_00335e7b;
    lVar11 = __nvoc_dynamicCast(*(undefined8 *)(local_48 + 8),__nvoc_class_def_VaSpaceApi);
    if (lVar11 == 0) {
      nvAssertFailedNoLog("pVaspaceApi != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",0x119);
      goto LAB_00335e39;
    }
  } while (*(long *)(lVar11 + 0x138) != *(long *)(*(long *)(param_1 + 0x138) + 0x98));
  refAddDependant(lVar10,lVar6);
LAB_00335e7b:
  lVar12 = __nvoc_dynamicCast(*(undefined8 *)(lVar12 + 8),__nvoc_class_def_KernelChannelGroupApi);
  if (lVar12 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroupApi != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",
                        0x124);
LAB_00335e39:
    iVar9 = 0x40;
  }
  else {
    if (*(int *)(lVar12 + 0x148) != 0) {
      iVar9 = clientGetResourceRef_IMPL
                        (*(undefined8 *)(param_2 + 8),*(int *)(lVar12 + 0x148),&local_88);
      if (iVar9 != 0) {
        nvAssertOkFailedNoLog
                  (iVar9,
                   "clientGetResourceRef(pCallContext->pClient, pKernelChannelGroupApi->hKernelGraphicsContext, &pKernelGraphicsContextRef)"
                   ,"src/kernel/gpu/fifo/kernel_ctxshare.c",0x12a);
        goto LAB_00335e3f;
      }
      refAddDependant(local_88,lVar6);
    }
    if (((*(char *)(lVar7 + 0x908) == '\0') && (*(char *)(lVar7 + 0x909) == '\0')) ||
       (*(char *)(*(long *)(*(long *)(param_1 + 0x138) + 0xa0) + 0x159) != '\0')) {
      return 0;
    }
    lVar12 = gpuGetRpc(lVar7);
    if (lVar12 == 0) {
      nvAssertFailedNoLog("pRpc != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",0x137);
      iVar9 = 0x1a;
    }
    else {
      uVar1 = *(undefined4 *)(lVar13 + 0x10);
      uVar2 = *(undefined4 *)(*(long *)(param_3 + 0x50) + 0x48);
      uVar3 = *(undefined4 *)(lVar5 + 0x48);
      uVar4 = *(undefined4 *)(*(long *)(lVar6 + 0x18) + 0x10);
      if ((*(char *)(lVar7 + 0x909) == '\0') && (*(char *)(lVar7 + 0x90a) == '\0')) {
        uStack_110 = 0;
        iVar9 = (**(code **)(lVar12 + 0x128))
                          (lVar7,lVar12,uVar3,uVar4,*(undefined4 *)(lVar6 + 0x10),uVar2,uVar1);
      }
      else {
        iVar9 = (**(code **)(lVar7 + 0x3ba8))(lVar7 + 0x3b58,uVar3,uVar4,lVar6 + 0x10,uVar2,uVar1,0)
        ;
        uStack_110 = extraout_RDX;
      }
      if (iVar9 == 0) {
        lVar13 = __nvoc_dynamicCast(*(undefined8 *)(lVar6 + 8),__nvoc_class_def_RmResource,
                                    uStack_110);
        *(undefined1 *)(lVar13 + 0xa4) = 1;
        return 0;
      }
    }
  }
LAB_00335e3f:
  serverFreeShare(g_resServ,uVar14);
  return iVar9;
}


// ===== 00336070 kctxshareapiCanCopy_IMPL =====

undefined8 kctxshareapiCanCopy_IMPL(void)

{
  return 1;
}


// ===== 00336080 kctxshareConstruct_IMPL =====

undefined8 kctxshareConstruct_IMPL(void)

{
  return 0;
}


// ===== 00336090 kctxshareInitCommon_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kctxshareInitCommon_IMPL
              (long param_1,undefined8 param_2,long param_3,long *param_4,int param_5,uint *param_6,
              long param_7)

{
  long lVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  uint uVar11;
  undefined8 *local_80;
  undefined4 local_68;
  undefined4 local_64;
  ulong local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  long local_40 [2];
  
  lVar7 = gpuGetKernelFifoShared_IMPL(param_3);
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 1;
  local_40[0] = 0;
  if (param_7 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroupApi != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",
                        0x181);
    return 0x40;
  }
  lVar1 = *(long *)(param_7 + 0x138);
  if (lVar1 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroup != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",0x183)
    ;
  }
  if (param_4 == (long *)0x0) {
    nvAssertFailedNoLog("pVAS != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",0x184);
  }
  cVar3 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_3 + 0x7a4));
  if (cVar3 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/fifo/kernel_ctxshare.c",0x187);
    return 0x2f;
  }
  cVar3 = (**(code **)(*param_4 + 0xb0))(param_4);
  if ((cVar3 != '\0') && (lVar8 = (**(code **)(*param_4 + 200))(param_4,param_3), lVar8 == 0)) {
    nvAssertFailedNoLog(&DAT_00d1f37a,"src/kernel/gpu/fifo/kernel_ctxshare.c",0x193);
    return 0x40;
  }
  if (param_5 == 0) {
    local_68 = 0x10;
    local_60 = 0;
LAB_00336176:
    iVar4 = (**(code **)(*(long *)(lVar1 + 0x110) + 8))
                      (*(long *)(lVar1 + 0x110),0x6e76726d,&local_68,&local_60,&local_50,1,1,
                       &local_48,0,0);
LAB_003361b4:
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  else {
    if (param_5 == 1) {
      local_68 = 4;
      goto LAB_00336176;
    }
    if (param_5 != 3) {
      if (param_5 != 2) {
        return 0x1f;
      }
      local_68 = 0x10;
      local_60 = (ulong)*param_6;
      goto LAB_00336176;
    }
    lVar8 = *(long *)(lVar1 + 0x110);
    local_68 = 2;
    if (*(long *)(lVar8 + 0x80) != 0) {
      nvAssertFailedNoLog("origSbctxRangeLo == 0","src/kernel/gpu/fifo/kernel_ctxshare.c",0x1af);
      return 0x40;
    }
    uVar2 = *(undefined8 *)(lVar8 + 0x88);
    iVar4 = (**(code **)(lVar8 + 0x48))(lVar8,1);
    if (iVar4 != 0) {
      nvAssertOkFailedNoLog(iVar4,"status","src/kernel/gpu/fifo/kernel_ctxshare.c",0x1b3);
      return iVar4;
    }
    iVar4 = (**(code **)(*(long *)(lVar1 + 0x110) + 8))
                      (*(long *)(lVar1 + 0x110),0x6e76726d,&local_68,&local_60,&local_50,1,1,
                       &local_48,0,0);
    iVar6 = (**(code **)(*(long *)(lVar1 + 0x110) + 0x48))(*(long *)(lVar1 + 0x110),0,uVar2);
    if (iVar6 != 0) {
      nvAssertOkFailedNoLog
                (iVar6,
                 "pKernelChannelGroup->pSubctxIdHeap->eheapSetAllocRange(pKernelChannelGroup->pSubctxIdHeap, origSbctxRangeLo, origSbctxRangeHi)"
                 ,"src/kernel/gpu/fifo/kernel_ctxshare.c",0x1cf);
      return iVar6;
    }
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*(long *)(lVar1 + 0x110) + 8))
                        (*(long *)(lVar1 + 0x110),0x6e76726d,&local_68,&local_60,&local_50,1,1,
                         &local_48,0,0);
      goto LAB_003361b4;
    }
  }
  local_80 = &local_50;
  puVar9 = (undefined8 *)mapFind_IMPL(lVar1 + 0x118,param_4);
  if (puVar9 == (undefined8 *)0x0) {
    local_64 = 2;
    iVar4 = (**(code **)(*(long *)(lVar1 + 0x138) + 8))
                      (*(long *)(lVar1 + 0x138),0x6e76726d,&local_64,&local_58,local_80,1,1,local_40
                       ,0,0);
    if (iVar4 == 0) {
      *(long **)(local_40[0] + 0x80) = param_4;
      puVar9 = (undefined8 *)mapInsertNew_IMPL(lVar1 + 0x118,param_4);
      if (puVar9 != (undefined8 *)0x0) {
        puVar9[1] = 1;
        *puVar9 = local_58;
        goto LAB_003361e9;
      }
      iVar4 = 0x51;
    }
    iVar6 = (**(code **)(*(long *)(lVar1 + 0x110) + 0x10))(*(long *)(lVar1 + 0x110),local_60);
    if (iVar6 != 0) {
      nvAssertFailedNoLog("tmpStatus == NV_OK","src/kernel/gpu/fifo/kernel_ctxshare.c",0x23d);
    }
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x24d,"kctxshareInitCommon_IMPL",1,
                 "NVRM: Context Share 0x%p allocation with id 0x%x failed, status is %x\n",param_1,
                 local_60,iVar4);
  }
  else {
    local_58 = *puVar9;
    puVar9[1] = puVar9[1] + 1;
LAB_003361e9:
    *(int *)(param_1 + 0xac) = (int)local_58;
    *(long **)(param_1 + 0x98) = param_4;
    *(int *)(param_1 + 0xa8) = (int)local_60;
    *(long *)(param_1 + 0xa0) = lVar1;
    *(int *)(param_1 + 0xb0) = param_5;
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x219,"kctxshareInitCommon_IMPL",1,
                 "NVRM: Allocated subctxId: 0x%02llx, vaSpaceId: 0x%02llx\n",local_60,local_58);
    *(long *)(local_48 + 0x80) = param_1;
    *param_6 = (uint)local_60;
    uVar10 = local_60 & 0xffffffff;
    if (param_5 == 3) {
      uVar5 = (**(code **)(lVar7 + 0x1f8))(param_3);
      uVar11 = *param_6 & 0x7fffffff;
      if (local_60 < uVar5) {
        uVar11 = *param_6 | 0x80000000;
      }
      *param_6 = uVar11;
      uVar10 = local_60;
    }
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x232,"kctxshareInitCommon_IMPL",1,
                 "NVRM: New Context Share 0x%p allocated with id 0x%x\n",param_1,uVar10);
    iVar4 = 0;
  }
  return iVar4;
}


// ===== 00336650 kctxshareapiConstruct_IMPL =====

int kctxshareapiConstruct_IMPL(long param_1,long param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined4 local_6c;
  long local_68;
  long local_60;
  long local_58;
  undefined8 local_50;
  long local_48;
  undefined8 local_40 [2];
  
  uVar1 = *param_3;
  piVar2 = *(int **)(param_3 + 0x10);
  lVar3 = *(long *)(*(long *)(param_1 + 0x128) + 0xe0);
  local_60 = 0;
  local_48 = 0;
  iVar5 = CliGetChannelGroup(uVar1,param_3[1],&local_58,&local_6c);
  if (iVar5 != 0) {
    return 0x33;
  }
  lVar7 = __nvoc_dynamicCast(*(undefined8 *)(local_58 + 8),__nvoc_class_def_KernelChannelGroupApi);
  if (lVar7 == 0) {
    nvAssertFailedNoLog("pKernelChannelGroupApi != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",
                        0x46);
    return 0x40;
  }
  if (*(long *)(param_3 + 0x16) != 0) {
    iVar5 = kctxshareapiCopyConstruct_IMPL(param_1,param_2,param_3);
    return iVar5;
  }
  lVar4 = *(long *)(lVar7 + 0x138);
  iVar5 = serverGetClientUnderLock(g_resServ,uVar1,&local_50);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x59,"kctxshareapiConstruct_IMPL",4,
                 "NVRM: Invalid client handle!\n");
    return 0x1f;
  }
  iVar5 = deviceGetByHandle_IMPL(local_50,local_6c,&local_60);
  if (iVar5 != 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x68,"kctxshareapiConstruct_IMPL",4,
                 "NVRM: Invalid parent/device handle!\n");
    return 0x1f;
  }
  iVar5 = *piVar2;
  if (iVar5 == 0) {
    if (*(char *)(lVar4 + 0x159) == '\0') goto LAB_00336880;
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x76,"kctxshareapiConstruct_IMPL",1,
                 "NVRM: Constructing Legacy Context Share\n");
LAB_0033679a:
    local_68 = *(long *)(lVar4 + 0x100);
    *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(lVar7 + 0x154);
  }
  else {
    if (*(int *)(local_60 + 0x1d0) == 1) {
      nvAssertFailedNoLog("(hVASpace == NV01_NULL_OBJECT) || (pDevice->vaMode != NV_DEVICE_ALLOCATION_VAMODE_SINGLE_VASPACE)"
                          ,"src/kernel/gpu/fifo/kernel_ctxshare.c",0x6d);
    }
    if (*(char *)(lVar4 + 0x159) != '\0') {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x76,"kctxshareapiConstruct_IMPL",1,
                   "NVRM: Constructing Legacy Context Share\n");
      nvAssertFailedNoLog("hVASpace == NV01_NULL_OBJECT","src/kernel/gpu/fifo/kernel_ctxshare.c",
                          0x77);
      goto LAB_0033679a;
    }
LAB_00336880:
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x7e,"kctxshareapiConstruct_IMPL",1,
                 "NVRM: Constructing Client Allocated Context Share\n");
    iVar6 = vaspaceGetByHandleOrDeviceDefault_IMPL(local_50,local_6c,iVar5,&local_68);
    *(int *)(param_1 + 0x140) = iVar5;
    if (iVar6 != 0) {
      nvAssertFailedNoLog("(rmStatus == NV_OK)","src/kernel/gpu/fifo/kernel_ctxshare.c",0x84);
      return iVar6;
    }
  }
  if (local_68 == 0) {
    nvAssertFailedNoLog("(pVAS != NULL)","src/kernel/gpu/fifo/kernel_ctxshare.c",0x85);
    return 0x40;
  }
  uVar8 = 0;
  if (lVar3 != 0) {
    uVar8 = *(undefined8 *)(lVar3 + 0x78);
  }
  iVar6 = serverAllocShareWithHalspecParent
                    (g_resServ,__nvoc_class_def_KernelCtxShare,&local_48,uVar8);
  lVar4 = local_68;
  if (iVar6 == 0) {
    iVar6 = piVar2[1];
    uVar8 = __nvoc_dynamicCast(local_48,__nvoc_class_def_KernelCtxShare);
    iVar6 = kctxshareInitCommon_IMPL(uVar8,param_1,lVar3,lVar4,iVar6,piVar2 + 2);
    if (iVar6 == 0) {
      uVar8 = __nvoc_dynamicCast(local_48,__nvoc_class_def_KernelCtxShare,lVar7,0x336810);
      *(undefined8 *)(param_1 + 0x138) = uVar8;
      if (iVar5 != 0) {
        iVar6 = clientGetResourceRef_IMPL(*(undefined8 *)(param_2 + 8),iVar5,local_40);
        if (iVar6 != 0) goto LAB_00336a21;
        refAddDependant(local_40[0],*(undefined8 *)(param_2 + 0x10));
      }
      if (*(int *)(lVar7 + 0x148) == 0) {
        return 0;
      }
      iVar6 = clientGetResourceRef_IMPL
                        (*(undefined8 *)(param_2 + 8),*(int *)(lVar7 + 0x148),local_40);
      if (iVar6 == 0) {
        refAddDependant(local_40[0],*(undefined8 *)(param_2 + 0x10));
        return 0;
      }
    }
    else {
      nvAssertOkFailedNoLog
                (iVar6,
                 "kctxshareInitCommon(dynamicCast(pShared, KernelCtxShare), pKernelCtxShareApi, pGpu, pVAS, pUserParams->flags, &pUserParams->subctxId, pKernelChannelGroupApi)"
                 ,"src/kernel/gpu/fifo/kernel_ctxshare.c",0x8b);
    }
  }
  else {
    nvAssertOkFailedNoLog
              (iVar6,
               "serverAllocShareWithHalspecParent(&g_resServ, classInfo(KernelCtxShare), &pShared, staticCast(pGpu, Object))"
               ,"src/kernel/gpu/fifo/kernel_ctxshare.c",0x87);
  }
LAB_00336a21:
  if (local_48 != 0) {
    serverFreeShare(g_resServ);
    return iVar6;
  }
  return iVar6;
}


// ===== 00336b30 kctxshareDestroyCommon_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kctxshareDestroyCommon_IMPL(long param_1,undefined8 param_2,long param_3,long param_4)

{
  long *plVar1;
  undefined4 uVar2;
  long lVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  char *pcVar9;
  
  if (param_1 == 0) {
    nvAssertFailedNoLog("pKernelCtxShare != NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",0x275);
    return 0x40;
  }
  iVar5 = serverGetShareRefCount(g_resServ,*(undefined8 *)(param_1 + 0x88));
  if (iVar5 != 1) {
    nvAssertFailedNoLog("refcnt == 1","src/kernel/gpu/fifo/kernel_ctxshare.c",0x27a);
    return 0x40;
  }
  cVar4 = rmDeviceGpuLockIsOwner(*(undefined4 *)(param_3 + 0x7a4));
  if (cVar4 == '\0') {
    nvAssertFailedNoLog("rmDeviceGpuLockIsOwner(pGpu->gpuInstance)",
                        "src/kernel/gpu/fifo/kernel_ctxshare.c",0x27d);
    return 0x2f;
  }
  lVar3 = *(long *)(param_1 + 0xa0);
  if (*(long *)(param_4 + 0x138) != lVar3) {
    nvAssertFailedNoLog("pKernelChannelGroup == pKernelChannelGroupApi->pKernelChannelGroup",
                        "src/kernel/gpu/fifo/kernel_ctxshare.c",0x280);
  }
  uVar2 = *(undefined4 *)(param_1 + 0xa8);
  puVar7 = (undefined8 *)mapFind_IMPL(lVar3 + 0x118,*(undefined8 *)(param_1 + 0x98));
  if ((puVar7 == (undefined8 *)0x0) || (puVar7[1] == 0)) {
    iVar5 = 0x40;
    nvAssertFailedNoLog("pVaSpaceEntry != NULL && pVaSpaceEntry->refCount != 0",
                        "src/kernel/gpu/fifo/kernel_ctxshare.c",0x284);
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x286,"kctxshareDestroyCommon_IMPL",4,
                 "NVRM: VASpace map entry not found.\n");
  }
  else {
    iVar5 = (**(code **)(*(long *)(lVar3 + 0x110) + 0x10))(*(long *)(lVar3 + 0x110),uVar2);
    if (iVar5 == 0) {
      plVar1 = puVar7 + 1;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        iVar6 = (**(code **)(*(long *)(lVar3 + 0x138) + 0x10))(*(long *)(lVar3 + 0x138),*puVar7);
        if (iVar6 != 0) {
          nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_ctxshare.c",0x2a4);
          uVar8 = nvstatusToString(iVar6);
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x2a5,"kctxshareDestroyCommon_IMPL",4
                       ,"NVRM: VASpace ID heap free failed with status = %s (0x%x)\n",uVar8,iVar6);
          iVar5 = iVar6;
          goto LAB_00336cc4;
        }
        mapRemove_IMPL(lVar3 + 0x118,puVar7);
      }
      pcVar9 = "NVRM: Freed Context Share 0x%p with id 0x%x\n";
      uVar8 = 0x2b0;
      goto LAB_00336c4d;
    }
    nvAssertFailedNoLog("status == NV_OK","src/kernel/gpu/fifo/kernel_ctxshare.c",0x298);
    uVar8 = nvstatusToString(iVar5);
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0x299,"kctxshareDestroyCommon_IMPL",4,
                 "NVRM: Subcontext ID heap free failed with status = %s (0x%x)\n",uVar8,iVar5);
  }
LAB_00336cc4:
  pcVar9 = "NVRM: Failed to free Context Share 0x%p with id 0x%x\n";
  uVar8 = 0x2b5;
LAB_00336c4d:
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",uVar8,"kctxshareDestroyCommon_IMPL",1,pcVar9,
               param_1,uVar2);
  return iVar5;
}


// ===== 00336e60 kctxshareapiDestruct_IMPL =====

void kctxshareapiDestruct_IMPL(long param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  long local_48;
  long local_40 [2];
  
  uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x128) + 0xe0);
  resGetFreeParams_IMPL(*(undefined8 *)(param_1 + 0x110),&local_48,local_40);
  lVar5 = *(long *)(*(long *)(local_48 + 0x10) + 0x18);
  lVar3 = 0;
  if (lVar5 != 0) {
    lVar3 = __nvoc_dynamicCast(*(undefined8 *)(lVar5 + 8),__nvoc_class_def_KernelChannelGroupApi);
    lVar5 = *(long *)(lVar3 + 0x138);
    if (lVar5 != 0) goto LAB_00336ed5;
  }
  nvAssertFailedNoLog("pKernelChannelGroup","src/kernel/gpu/fifo/kernel_ctxshare.c",0xcf);
  lVar5 = 0;
LAB_00336ed5:
  if (*(long *)(param_1 + 0x138) != 0) {
    if (*(long *)(*(long *)(param_1 + 0x138) + 0xa0) != lVar5) {
      nvAssertFailedNoLog("pKernelCtxShareApi->pShareData->pKernelChannelGroup == pKernelChannelGroup"
                          ,"src/kernel/gpu/fifo/kernel_ctxshare.c",0xd3);
    }
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0xd7,"kctxshareapiDestruct_IMPL",1,
                 "NVRM: KernelCtxShareApi Ptr: %p   ChanGrp: %p  !\n",param_1);
    uVar7 = 0;
    if (*(long *)(param_1 + 0x138) != 0) {
      uVar7 = *(undefined8 *)(*(long *)(param_1 + 0x138) + 0x88);
    }
    uVar4 = serverGetShareRefCount(g_resServ,uVar7);
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0xdd,"kctxshareapiDestruct_IMPL",1,
                 "NVRM: kctxshareapiDestruct_IMPL called on KernelCtxShare %p with refcnt %d\n",
                 uVar7,uVar4);
    iVar6 = (int)uVar4;
    if (iVar6 < 1) {
      nvAssertFailedNoLog("refcnt >= 1","src/kernel/gpu/fifo/kernel_ctxshare.c",0xe0);
    }
    else {
      if (iVar6 == 1) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0xf0,"kctxshareapiDestruct_IMPL",1,
                     "NVRM: kctxshareapiDestruct_IMPL: KernelCtxShare %p has no more references, destroying...\n"
                     ,uVar7);
        lVar5 = local_40[0];
        uVar2 = kctxshareDestroyCommon_IMPL(*(undefined8 *)(param_1 + 0x138),param_1,uVar1,lVar3);
        *(undefined4 *)(lVar5 + 0x30) = uVar2;
        if (*(int *)(local_40[0] + 0x30) != 0) {
          nvAssertFailedNoLog("pParams->status == NV_OK","src/kernel/gpu/fifo/kernel_ctxshare.c",
                              0xf4);
        }
        serverFreeShare(g_resServ,uVar7);
        return;
      }
      serverFreeShare(g_resServ,uVar7);
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_ctxshare.c",0xeb,"kctxshareapiDestruct_IMPL",1,
                   "NVRM: kctxshareapiDestruct_IMPL: KernelCtxShare %p has %d references left\n",
                   uVar7,iVar6 + -1);
    }
  }
  return;
}


// ===== 00337110 kctxshareDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

void kctxshareDestruct_IMPL(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0xa0) == 0) {
    return;
  }
  lVar2 = *(long *)(*(long *)(param_1 + 0xa0) + 0x110);
  pcVar1 = *(code **)(lVar2 + 0x40);
  lVar2 = (*pcVar1)(lVar2,*(undefined4 *)(param_1 + 0xa8),0,pcVar1);
  if (lVar2 == 0) {
    return;
  }
  nvAssertFailedNoLog("pBlock == NULL","src/kernel/gpu/fifo/kernel_ctxshare.c",0x2cf);
  return;
}


// ===== 00337180 _kfifoUserdOwnerComparator =====

undefined8 _kfifoUserdOwnerComparator(int *param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 1;
  }
  if ((*param_1 == *param_2) && (*(long *)(param_1 + 2) == *(long *)(param_2 + 2))) {
    return CONCAT71((int7)((ulong)*(long *)(param_2 + 4) >> 8),
                    *(long *)(param_1 + 4) == *(long *)(param_2 + 4));
  }
  return 0;
}


// ===== 003371c0 _kfifoChidMgrFreeIsolationId.isra.0 =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 _kfifoChidMgrFreeIsolationId_isra_0(long param_1,undefined4 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = (**(code **)(param_1 + 0x40))(param_1,param_2,0);
  if (lVar1 != 0) {
    if (*(int *)(lVar1 + 0x1c) == 0) {
      nvAssertFailedNoLog("pIsolationIdBlock->refCount > 0","src/kernel/gpu/fifo/kernel_fifo.c",
                          0x1d7);
    }
    lVar2 = *(long *)(lVar1 + 0x80);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pIsolationIdBlock->pData != NULL","src/kernel/gpu/fifo/kernel_fifo.c",
                          0x1d8);
      lVar2 = *(long *)(lVar1 + 0x80);
    }
    portMemFree(lVar2);
    *(undefined8 *)(lVar1 + 0x80) = 0;
    return 0;
  }
  nvAssertFailedNoLog("pIsolationIdBlock","src/kernel/gpu/fifo/kernel_fifo.c",0x1d6);
  return 0x57;
}


// ===== 00337271 kfifoGetNumEschedDrivenEngines_IMPL.cold =====

void kfifoGetNumEschedDrivenEngines_IMPL_cold(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00337280 kfifoGetNumEschedDrivenEngines_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined4 kfifoGetNumEschedDrivenEngines_IMPL(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x150);
  }
  uVar3 = gpuEngineGetGpu(uVar3);
  iVar2 = (**(code **)(param_1 + 0x240))(uVar3,param_1);
  if (iVar2 == 0) {
    nvAssertFailedNoLog("kfifoGetNumEngines_HAL(ENG_GET_GPU(pKernelFifo), pKernelFifo) > 0",
                        "src/kernel/gpu/fifo/kernel_fifo.c",0x57);
  }
  if (*(long *)(param_1 + 0x3d8) != 0) {
    return *(undefined4 *)(param_1 + 0x3cc);
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00337300 kfifoChidMgrDestruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void kfifoChidMgrDestruct_IMPL(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x368);
  if (*(int *)(param_1 + 0x370) != 0) {
    lVar3 = 0;
    do {
      lVar2 = *(long *)(lVar4 + lVar3 * 8);
      lVar1 = lVar3 * 8;
      if (lVar2 != 0) {
        mapDestroyIntrusive_IMPL(*(undefined8 *)(lVar2 + 0x38));
        portMemFree(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x368) + lVar3 * 8) + 0x38));
        lVar4 = *(long *)(*(long *)(param_1 + 0x368) + lVar3 * 8);
        if (*(undefined8 **)(lVar4 + 8) != (undefined8 *)0x0) {
          (*(code *)**(undefined8 **)(lVar4 + 8))();
          portMemFree(*(undefined8 *)(lVar4 + 8));
          *(undefined8 *)(lVar4 + 8) = 0;
        }
        if (*(undefined8 **)(lVar4 + 0x10) != (undefined8 *)0x0) {
          (*(code *)**(undefined8 **)(lVar4 + 0x10))();
          portMemFree(*(undefined8 *)(lVar4 + 0x10));
          *(undefined8 *)(lVar4 + 0x10) = 0;
        }
        portMemFree(*(undefined8 *)(lVar4 + 0x18));
        *(undefined8 *)(lVar4 + 0x18) = 0;
        lVar4 = *(long *)(*(long *)(param_1 + 0x368) + lVar1);
        if (*(long *)(lVar4 + 0x28) != 0) {
          portMemFree();
          *(undefined8 *)(lVar4 + 0x28) = 0;
          *(undefined4 *)(lVar4 + 0x30) = 0;
          lVar4 = *(long *)(*(long *)(param_1 + 0x368) + lVar1);
        }
        portMemFree(lVar4);
        *(undefined8 *)(*(long *)(param_1 + 0x368) + lVar1) = 0;
        lVar4 = *(long *)(param_1 + 0x368);
      }
      lVar3 = lVar3 + 1;
    } while ((uint)lVar3 < *(uint *)(param_1 + 0x370));
  }
  portMemFree();
  *(undefined8 *)(param_1 + 0x368) = 0;
  bitVectorClrAll_IMPL(param_1 + 0x378,0x40);
  *(undefined4 *)(param_1 + 0x370) = 0;
  return;
}


// ===== 00337480 kfifoChidMgrRetainChid_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoChidMgrRetainChid_IMPL
              (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  int iVar1;
  long lVar2;
  uint local_2c [3];
  
  iVar1 = vgpuGetCallingContextGfid(param_1,local_2c);
  if (iVar1 != 0) {
    nvAssertOkFailedNoLog
              (iVar1,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/fifo/kernel_fifo.c",
               0x397);
    return iVar1;
  }
  if (local_2c[0] == 0) {
    lVar2 = *(long *)(param_3 + 0x10);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pChidMgr->pGlobalChIDHeap != NULL","src/kernel/gpu/fifo/kernel_fifo.c",
                          0x3a7);
      return 0x40;
    }
    lVar2 = (**(code **)(lVar2 + 0x40))(lVar2,param_4,0);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pChIdBlock != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x3ac);
      return 0x57;
    }
    iVar1 = *(int *)(lVar2 + 0x1c);
    if (iVar1 == 0) {
      nvAssertFailedNoLog("pChIdBlock->refCount > 0","src/kernel/gpu/fifo/kernel_fifo.c",0x3ad);
      iVar1 = *(int *)(lVar2 + 0x1c);
    }
  }
  else {
    lVar2 = *(long *)(*(long *)(param_3 + 0x18) + (ulong)local_2c[0] * 8);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pChidMgr->ppVirtualChIDHeap[gfid] != NULL",
                          "src/kernel/gpu/fifo/kernel_fifo.c",0x39b);
      return 0x40;
    }
    lVar2 = (**(code **)(lVar2 + 0x40))(lVar2,param_4,0);
    if (lVar2 == 0) {
      nvAssertFailedNoLog("pVirtChIdBlock != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x3a1);
      return 0x57;
    }
    iVar1 = *(int *)(lVar2 + 0x1c);
    if (iVar1 == 0) {
      nvAssertFailedNoLog("pVirtChIdBlock->refCount > 0","src/kernel/gpu/fifo/kernel_fifo.c",0x3a2);
      iVar1 = *(int *)(lVar2 + 0x1c);
    }
  }
  *(int *)(lVar2 + 0x1c) = iVar1 + 1;
  lVar2 = *(long *)(param_3 + 8);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pChidMgr->pFifoDataHeap != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x3b1)
    ;
    return 0x40;
  }
  lVar2 = (**(code **)(lVar2 + 0x40))(lVar2,param_4,0);
  if (lVar2 == 0) {
    nvAssertFailedNoLog("pFifoDataBlock != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x3b6);
    return 0x57;
  }
  iVar1 = *(int *)(lVar2 + 0x1c);
  if (iVar1 == 0) {
    nvAssertFailedNoLog("pFifoDataBlock->refCount > 0","src/kernel/gpu/fifo/kernel_fifo.c",0x3b7);
    iVar1 = *(int *)(lVar2 + 0x1c);
  }
  *(int *)(lVar2 + 0x1c) = iVar1 + 1;
  return 0;
}


// ===== 003376f0 kfifoChidMgrReleaseChid_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoChidMgrReleaseChid_IMPL
                (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  uint local_1c;
  
  uVar2 = vgpuGetCallingContextGfid(param_1,&local_1c);
  if (uVar2 == 0) {
    if (local_1c == 0) {
      lVar1 = *(long *)(param_3 + 0x10);
      if (lVar1 == 0) {
        nvAssertFailedNoLog("pChidMgr->pGlobalChIDHeap != NULL","src/kernel/gpu/fifo/kernel_fifo.c",
                            0x3e2);
      }
      else {
        iVar3 = (**(code **)(lVar1 + 0x10))(lVar1,param_4);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,"pChidMgr->pGlobalChIDHeap->eheapFree(pChidMgr->pGlobalChIDHeap, ChID)",
                     "src/kernel/gpu/fifo/kernel_fifo.c",0x3de);
        }
      }
    }
    else {
      lVar1 = *(long *)(*(long *)(param_3 + 0x18) + (ulong)local_1c * 8);
      if (lVar1 != 0) {
        iVar3 = (**(code **)(lVar1 + 0x10))(lVar1,param_4);
        if (iVar3 != 0) {
          nvAssertOkFailedNoLog
                    (iVar3,
                     "pChidMgr->ppVirtualChIDHeap[gfid]->eheapFree(pChidMgr->ppVirtualChIDHeap[gfid], ChID)"
                     ,"src/kernel/gpu/fifo/kernel_fifo.c",0x3d7);
        }
      }
    }
    lVar1 = *(long *)(param_3 + 8);
    if (lVar1 == 0) {
      nvAssertFailedNoLog("pChidMgr->pFifoDataHeap != NULL","src/kernel/gpu/fifo/kernel_fifo.c",
                          0x3e6);
      uVar4 = 0x40;
    }
    else {
      uVar4 = (**(code **)(lVar1 + 0x10))(lVar1,param_4);
      if ((int)uVar4 != 0) {
        nvAssertOkFailedNoLog
                  (uVar4 & 0xffffffff,
                   "pChidMgr->pFifoDataHeap->eheapFree(pChidMgr->pFifoDataHeap, ChID)",
                   "src/kernel/gpu/fifo/kernel_fifo.c",999);
        uVar4 = uVar4 & 0xffffffff;
      }
    }
    return uVar4;
  }
  nvAssertOkFailedNoLog
            (uVar2,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/fifo/kernel_fifo.c",
             0x3cc);
  return (ulong)uVar2;
}


// ===== 00337870 kfifoChidMgrFreeChid_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoChidMgrFreeChid_IMPL
                (undefined8 param_1,undefined8 param_2,long param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  int local_2c;
  
  lVar3 = (**(code **)(*(long *)(param_3 + 8) + 0x40))(*(long *)(param_3 + 8),param_4,0);
  if (lVar3 == 0) {
    nvAssertFailedNoLog("pFifoDataBlock != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x406);
    return 0x57;
  }
  if (*(int *)(lVar3 + 0x1c) == 0) {
    nvAssertFailedNoLog("pFifoDataBlock->refCount > 0","src/kernel/gpu/fifo/kernel_fifo.c",0x407);
  }
  *(undefined8 *)(lVar3 + 0x80) = 0;
  uVar1 = vgpuGetCallingContextGfid(param_1,&local_2c);
  if (uVar1 == 0) {
    if ((local_2c == 0) &&
       (iVar2 = _kfifoChidMgrFreeIsolationId_isra_0(*(undefined8 *)(param_3 + 0x10),param_4),
       iVar2 != 0)) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x416,"kfifoChidMgrFreeChid_IMPL",4,
                   "NVRM: Failed to free IsolationId. Status = 0x%x\n",0x57);
      return 0x57;
    }
    uVar4 = kfifoChidMgrReleaseChid_IMPL(param_1,param_2,param_3,param_4);
  }
  else {
    nvAssertOkFailedNoLog
              (uVar1,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/fifo/kernel_fifo.c",
               0x40a);
    uVar4 = (ulong)uVar1;
  }
  return uVar4;
}


// ===== 003379c0 kfifoRunlistQueryNumChannels_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoRunlistQueryNumChannels_KERNEL(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined4 local_10;
  int local_c;
  
  if (*(char *)(param_1 + 0x908) == '\0') {
    if (*(char *)(param_1 + 0x909) == '\0') goto LAB_00337a20;
LAB_003379de:
    local_c = 0;
    local_10 = param_3;
    iVar2 = (**(code **)(param_1 + 0x3b90))
                      (param_1 + 0x3b58,*(undefined4 *)(param_1 + 0x3b34),
                       *(undefined4 *)(param_1 + 0x3b3c),0x20800a61,&local_10,8);
    iVar1 = local_c;
    if (iVar2 != 0) {
      return 0;
    }
  }
  else {
    lVar3 = gpuGetStaticInfo();
    if (lVar3 == 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x909) != '\0') goto LAB_003379de;
    iVar1 = *(int *)(lVar3 + 0xa7b0);
  }
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_00337a20:
  nvAssertFailedNoLog("numChannels > 0","src/kernel/gpu/fifo/kernel_fifo.c",0x53f);
  return 0;
}


// ===== 00337a70 kfifoChidMgrGetNumChannels_IMPL =====

int kfifoChidMgrGetNumChannels_IMPL(undefined8 param_1,long param_2,undefined4 *param_3)

{
  uint uVar1;
  
  if (param_3[8] != 0) {
    return param_3[8];
  }
  uVar1 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*param_3);
  if (*(char *)(param_2 + 0x4bc) != '\0') {
    if (*(uint *)(param_2 + 0x4c0) < uVar1) {
      uVar1 = *(uint *)(param_2 + 0x4c0);
    }
  }
  param_3[8] = uVar1;
  *(undefined1 *)(param_2 + 0x4bc) = 0;
  return param_3[8];
}


// ===== 00337ad0 _kfifoChidMgrGetNextKernelChannel =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
_kfifoChidMgrGetNextKernelChannel
          (undefined8 param_1,long param_2,undefined4 *param_3,uint *param_4,long *param_5)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  
  uVar2 = param_3[8];
  if (uVar2 == 0) {
    uVar2 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*param_3);
    if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar2)) {
      uVar2 = *(uint *)(param_2 + 0x4c0);
    }
    param_3[8] = uVar2;
    *(undefined1 *)(param_2 + 0x4bc) = 0;
    uVar2 = param_3[8];
    *param_4 = uVar2;
    lVar3 = *(long *)(param_4 + 4);
  }
  else {
    *param_4 = uVar2;
    lVar3 = *(long *)(param_4 + 4);
  }
  if (lVar3 == 0) {
    uVar4 = (**(code **)(*(long *)(param_3 + 2) + 0x40))(*(long *)(param_3 + 2),param_4[2],1);
    *(undefined8 *)(param_4 + 4) = uVar4;
    uVar2 = *param_4;
  }
  uVar5 = param_4[2];
  if (uVar5 < uVar2) {
    lVar3 = *(long *)(param_4 + 4);
    do {
      while (*(int *)(lVar3 + 0x20) != -1) {
        uVar5 = uVar5 + 1;
        param_4[2] = uVar5;
        lVar1 = *(long *)(lVar3 + 0x80);
        if (lVar1 != 0) {
          *(undefined8 *)(param_4 + 4) = *(undefined8 *)(lVar3 + 0x78);
          *param_5 = lVar1;
          return 0;
        }
        lVar3 = *(long *)(lVar3 + 0x78);
        *(long *)(param_4 + 4) = lVar3;
        if (uVar2 <= uVar5) {
          return 0x57;
        }
      }
      uVar5 = *(int *)(lVar3 + 8) + 1;
      param_4[2] = uVar5;
      lVar3 = *(long *)(lVar3 + 0x78);
      *(long *)(param_4 + 4) = lVar3;
    } while (uVar5 < uVar2);
  }
  return 0x57;
}


// ===== 00337be0 kfifoChidMgrAllocChid_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoChidMgrAllocChid_IMPL
              (long param_1,long param_2,undefined4 *param_3,undefined4 param_4,uint param_5,
              char param_6,uint param_7,char param_8,uint param_9,uint param_10,long param_11)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  uint *puVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  uint local_60;
  uint local_5c;
  undefined8 local_58;
  ulong local_50;
  ulong local_48;
  ulong local_40 [2];
  
  local_50 = 0;
  local_60 = param_5;
  if (param_11 == 0) {
    nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x255);
    return 0x1f;
  }
  uVar4 = param_3[8];
  if (uVar4 == 0) {
    uVar4 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*param_3);
    if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar4)) {
      uVar4 = *(uint *)(param_2 + 0x4c0);
    }
    param_3[8] = uVar4;
    *(undefined1 *)(param_2 + 0x4bc) = 0;
    uVar4 = param_3[8];
    if (param_5 != 1) goto LAB_00337c3d;
LAB_00337f55:
    local_60 = 2;
  }
  else {
    if (param_5 == 1) goto LAB_00337f55;
LAB_00337c3d:
    if (param_5 == 2) {
      local_50 = (ulong)param_10;
      local_60 = 0x10;
    }
    else {
      if (param_5 != 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x266,"kfifoChidMgrAllocChid_IMPL",4,
                     "NVRM: Invalid channel ID alloc mode %d\n",local_60);
        return 0x1f;
      }
      local_60 = 4;
    }
  }
  local_58 = 1;
  lVar5 = serverutilGetClientUnderLock(param_4);
  if (lVar5 == 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x272,"kfifoChidMgrAllocChid_IMPL",4,
                 "NVRM: Invalid client handle %ux\n",param_4);
    return 0x23;
  }
  iVar3 = vgpuGetCallingContextGfid(param_1,&local_5c);
  if (iVar3 != 0) {
    nvAssertOkFailedNoLog
              (iVar3,"vgpuGetCallingContextGfid(pGpu, &gfid)","src/kernel/gpu/fifo/kernel_fifo.c",
               0x277);
    return iVar3;
  }
  if (local_5c == 0) {
    puVar7 = (uint *)portMemAllocNonPaged(0x18);
    if (puVar7 == (uint *)0x0) {
      nvAssertFailedNoLog("(pIsolationID != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0x2d5);
      return 0x51;
    }
    portMemSet(puVar7,0,0x18);
    uVar9 = *(uint *)(lVar5 + 0x118);
    uVar8 = (ulong)*(uint *)(lVar5 + 0x11c);
    cVar1 = *(char *)(lVar5 + 0x184);
    cVar2 = kchannelCheckIsKernel_IMPL(param_11);
    if (cVar2 == '\0') {
      uVar10 = (ulong)uVar9;
      if (uVar8 != 0) {
        uVar9 = (uint)(uVar8 == 0xffffffff);
        goto LAB_00338032;
      }
      *puVar7 = 3;
      *(ulong *)(puVar7 + 2) = uVar10;
      puVar7[4] = 0;
      puVar7[5] = 0;
    }
    else {
      uVar9 = 4;
      uVar10 = 0xffffffff;
LAB_00338032:
      *puVar7 = uVar9;
      *(ulong *)(puVar7 + 2) = uVar10;
      *(ulong *)(puVar7 + 4) = uVar8;
      if ((uVar8 != 0) && (cVar1 != '\0')) {
        *puVar7 = 2;
        puVar7[4] = 0xffffffff;
        puVar7[5] = 0;
      }
    }
    if (param_8 == '\0') {
      lVar5 = *(long *)(param_3 + 4);
      if (param_6 == '\0') {
        param_7 = 1;
      }
      else {
        local_60 = local_60 | 0x100000;
      }
    }
    else {
      if (param_6 != '\0') {
        nvAssertOkFailedNoLog(0x40,"!bForceInternalIdx","src/kernel/gpu/fifo/kernel_fifo.c",0x30e);
        iVar3 = 0x40;
        goto LAB_00338255;
      }
      lVar5 = *(long *)(param_3 + 4);
      local_60 = local_60 | 0x10;
      local_50 = (ulong)param_7;
      param_7 = 1;
      local_50 = (ulong)param_9 * (ulong)*(uint *)(lVar5 + 0x94) + local_50;
    }
    (**(code **)(lVar5 + 0x38))(lVar5,&local_48);
    (**(code **)(*(long *)(param_3 + 4) + 0x28))(*(long *)(param_3 + 4),local_40);
    uVar8 = (local_40[0] - 1) + local_48;
    uVar10 = uVar8;
    if ((*(char *)(param_1 + 0x4a4e) == '\0') &&
       (uVar10 = local_48, *(char *)(param_11 + 0x2d4) == '\0')) {
      local_48 = (local_48 + 1) - (ulong)(*(char *)(param_1 + 0x909) == '\0');
      uVar10 = uVar8;
    }
    iVar3 = (**(code **)(*(long *)(param_3 + 4) + 0x48))(*(long *)(param_3 + 4),local_48,uVar10);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,
                 "pChidMgr->pGlobalChIDHeap->eheapSetAllocRange(pChidMgr->pGlobalChIDHeap, rangeLo, rangeHi)"
                 ,"src/kernel/gpu/fifo/kernel_fifo.c",0x32f);
      goto LAB_00338255;
    }
    iVar3 = (**(code **)(*(long *)(param_3 + 4) + 8))
                      (*(long *)(param_3 + 4),0x6669666f,&local_60,&local_50,&local_58,param_7,1,0,
                       puVar7,_kfifoUserdOwnerComparator);
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x342,"kfifoChidMgrAllocChid_IMPL",4,
                   "NVRM: Failed to allocate Channel ID on heap\n");
      goto LAB_00338255;
    }
  }
  else {
    if (*(long *)(*(long *)(param_3 + 6) + (ulong)local_5c * 8) == 0) {
      nvAssertFailedNoLog("pChidMgr->ppVirtualChIDHeap[gfid]","src/kernel/gpu/fifo/kernel_fifo.c",
                          0x280);
      return 0x40;
    }
    local_40[0] = 0;
    iVar3 = vgpuGetCallingContextKernelHostVgpuDevice(param_1,local_40);
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog
                (iVar3,"vgpuGetCallingContextKernelHostVgpuDevice(pGpu, &pKernelHostVgpuDevice)",
                 "src/kernel/gpu/fifo/kernel_fifo.c",0x21c);
LAB_00338369:
      nvAssertOkFailedNoLog
                (iVar3,"_kfifoGetVgpuPluginChannelsCount(pGpu, &numPluginChannels)",
                 "src/kernel/gpu/fifo/kernel_fifo.c",0x283);
      return iVar3;
    }
    if (local_40[0] == 0) {
      nvAssertFailedNoLog("pKernelHostVgpuDevice != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x21d)
      ;
      iVar3 = 0x57;
      goto LAB_00338369;
    }
    uVar9 = *(uint *)(local_40[0] + 0x28);
    lVar5 = *(long *)(*(long *)(param_3 + 6) + (ulong)local_5c * 8);
    (**(code **)(lVar5 + 0x38))(lVar5,&local_48);
    lVar5 = *(long *)(*(long *)(param_3 + 6) + (ulong)local_5c * 8);
    (**(code **)(lVar5 + 0x28))(lVar5,local_40);
    uVar8 = (ulong)uVar9;
    if (local_40[0] <= uVar8) {
      nvAssertFailedNoLog("numPluginChannels < size","src/kernel/gpu/fifo/kernel_fifo.c",0x290);
      return 0x3b;
    }
    uVar10 = (local_40[0] + local_48) - 1;
    if ((*(char *)(*(long *)(*(long *)(param_11 + 0x2b8) + 0x138) + 0x1f0) == '\0') || (uVar9 == 0))
    {
      uVar10 = uVar10 - uVar8;
      uVar8 = local_48;
    }
    else {
      uVar8 = (local_40[0] + local_48) - uVar8;
    }
    lVar5 = *(long *)(*(long *)(param_3 + 6) + (ulong)local_5c * 8);
    iVar3 = (**(code **)(lVar5 + 0x48))(lVar5,uVar8,uVar10);
    uVar9 = local_60;
    if (iVar3 != 0) {
      nvAssertOkFailedNoLog(iVar3,"status","src/kernel/gpu/fifo/kernel_fifo.c",0x2a1);
      return iVar3;
    }
    if (param_8 == '\0') {
      if (param_6 == '\0') {
        param_7 = 1;
      }
      else {
        local_60 = local_60 | 0x100000;
      }
      if ((uVar9 & 0x10) != 0) goto LAB_00337dfa;
    }
    else {
      if (param_6 != '\0') {
        nvAssertFailedNoLog("!bForceInternalIdx","src/kernel/gpu/fifo/kernel_fifo.c",0x2a5);
        return 0x40;
      }
      local_60 = local_60 | 0x10;
      local_50 = (ulong)param_7;
      param_7 = 1;
      local_50 = (ulong)*(uint *)(*(long *)(*(long *)(param_3 + 6) + (ulong)local_5c * 8) + 0x94) *
                 (ulong)param_9 + local_50;
LAB_00337dfa:
      if ((uVar10 < local_50) || (local_50 < uVar8)) {
        nvAssertFailedNoLog("(ChID64 <= rangeHi) && (ChID64 >= rangeLo)",
                            "src/kernel/gpu/fifo/kernel_fifo.c",0x2b2);
        return 0x3b;
      }
    }
    puVar7 = (uint *)0x0;
    lVar5 = *(long *)(*(long *)(param_3 + 6) + (ulong)local_5c * 8);
    iVar3 = (**(code **)(lVar5 + 8))(lVar5,0x6669666f,&local_60,&local_50,&local_58,param_7,1,0,0,0)
    ;
    if (iVar3 != 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x2c4,"kfifoChidMgrAllocChid_IMPL",4,
                   "NVRM: Failed to allocate Channel ID 0x%llx %d on heap \n",local_50,param_5);
      goto LAB_00338255;
    }
  }
  local_60 = 0x10;
  iVar3 = (**(code **)(*(long *)(param_3 + 2) + 8))
                    (*(long *)(param_3 + 2),0x6669666f,&local_60,&local_50,&local_58,1,1,0,0,0);
  uVar8 = local_50;
  if (iVar3 == 0) {
    uVar9 = (uint)local_50;
    if (uVar9 < uVar4) {
      lVar5 = (**(code **)(*(long *)(param_3 + 2) + 0x40))
                        (*(long *)(param_3 + 2),local_50 & 0xffffffff,0);
      lVar6 = (**(code **)(*(long *)(param_3 + 4) + 0x40))
                        (*(long *)(param_3 + 4),uVar8 & 0xffffffff,0);
      if (local_5c == 0) {
        *(uint **)(lVar6 + 0x80) = puVar7;
      }
      *(long *)(lVar5 + 0x80) = param_11;
      *(uint *)(param_11 + 0x2b4) = uVar9;
      return 0;
    }
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x37a,"kfifoChidMgrAllocChid_IMPL",3,
                 "NVRM: No allocatable FIFO available.\n");
    iVar3 = 0x4f;
  }
  else {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x361,"kfifoChidMgrAllocChid_IMPL",4,
                 "NVRM: Failed to allocate Channel on fifo data heap\n");
  }
LAB_00338255:
  portMemFree(puVar7);
  return iVar3;
}


// ===== 003384c0 kfifoChidMgrAllocChannelGroupHwID_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_r8 replaced with injection: x86_indirect_thunk_r8 */

undefined8
kfifoChidMgrAllocChannelGroupHwID_IMPL(long param_1,long param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_128 [32];
  
  uVar1 = 0;
  do {
    uVar4 = (ulong)uVar1;
    uVar1 = uVar1 + 0x20;
    *(undefined8 *)((long)local_128 + uVar4) = 0;
    *(undefined8 *)((long)local_128 + uVar4 + 8) = 0;
    *(undefined8 *)((long)local_128 + uVar4 + 0x10) = 0;
    *(undefined8 *)((long)local_128 + uVar4 + 0x18) = 0;
  } while (uVar1 < 0x100);
  if (param_4 != (uint *)0x0) {
    uVar1 = param_3[8];
    if (uVar1 == 0) {
      uVar1 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*param_3);
      if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar1)) {
        uVar1 = *(uint *)(param_2 + 0x4c0);
      }
      param_3[8] = uVar1;
      *(undefined1 *)(param_2 + 0x4bc) = 0;
      uVar1 = param_3[8];
      if (uVar1 == 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x563,
                     "kfifoChidMgrAllocChannelGroupHwID_IMPL",4,"NVRM: Zero max channel groups!!!\n"
                    );
        return 0x1f;
      }
    }
    uVar2 = nvBitFieldLSZero(*(undefined8 *)(param_3 + 10),param_3[0xc]);
    *param_4 = uVar2;
    if (uVar1 <= uVar2) {
      *param_4 = uVar1;
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x573,
                   "kfifoChidMgrAllocChannelGroupHwID_IMPL",4,
                   "NVRM: No allocatable FIFO available.\n");
      if (*(char *)(param_1 + 0x908) != '\0') {
        nvDbgSnprintf(local_128,0x100,
                      "Guest attempted to allocate channel above its max per engine channel limit 0x%x"
                      ,uVar1);
        lVar3 = gpuGetRpc(param_1);
        if (lVar3 != 0) {
          (**(code **)(lVar3 + 0x458))(param_1,lVar3,local_128,1,*(code **)(lVar3 + 0x458));
        }
      }
      return 0x4f;
    }
    nvBitFieldSet(*(undefined8 *)(param_3 + 10),param_3[0xc],uVar2,1);
    return 0;
  }
  return 0x1f;
}


// ===== 00338690 kfifoChidMgrFreeChannelGroupHwID_IMPL =====

undefined8
kfifoChidMgrFreeChannelGroupHwID_IMPL
          (undefined8 param_1,long param_2,undefined4 *param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = param_3[8];
  if (uVar2 == 0) {
    uVar2 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*param_3);
    if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar2)) {
      uVar2 = *(uint *)(param_2 + 0x4c0);
    }
    param_3[8] = uVar2;
    *(undefined1 *)(param_2 + 0x4bc) = 0;
    uVar2 = param_3[8];
    if (uVar2 == 0) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x59b,"kfifoChidMgrFreeChannelGroupHwID_IMPL"
                   ,4,"NVRM: Zero max channel groups!!!\n");
      return 0x1f;
    }
  }
  if (uVar2 <= param_4) {
    nvAssertFailedNoLog("chGrpID < maxChannelGroups","src/kernel/gpu/fifo/kernel_fifo.c",0x59e);
    return 0x1f;
  }
  cVar1 = nvBitFieldTest(*(undefined8 *)(param_3 + 10),param_3[0xc],param_4);
  if (cVar1 == '\0') {
    nvAssertFailedNoLog("nvBitFieldTest(pChidMgr->channelGrpMgr.pHwIdInUse, pChidMgr->channelGrpMgr.hwIdInUseSz, chGrpID)"
                        ,"src/kernel/gpu/fifo/kernel_fifo.c",0x5a4);
  }
  nvBitFieldSet(*(undefined8 *)(param_3 + 10),param_3[0xc],param_4,0);
  return 0;
}


// ===== 003387a0 kfifoGetChidMgr_IMPL =====

undefined8 kfifoGetChidMgr_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  char cVar1;
  
  if (*(char *)(param_2 + 0x4b0) == '\0') {
    if ((*(uint *)(param_2 + 0x370) == 1) && (*(long *)(param_2 + 0x368) != 0)) {
      cVar1 = bitVectorTest_IMPL(param_2 + 0x378,0x40,0);
      if (cVar1 == '\0') {
        return 0;
      }
      return **(undefined8 **)(param_2 + 0x368);
    }
  }
  else if (param_3 < *(uint *)(param_2 + 0x370)) {
    return *(undefined8 *)(*(long *)(param_2 + 0x368) + (ulong)param_3 * 8);
  }
  return 0;
}


// ===== 00338830 kfifoGetChidMgrFromType_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGetChidMgrFromType_IMPL
              (undefined8 param_1,long param_2,undefined8 param_3,undefined8 param_4,
              undefined8 *param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_1c;
  
  if (param_5 != (undefined8 *)0x0) {
    *param_5 = 0;
    iVar1 = (**(code **)(param_2 + 0x218))();
    if (iVar1 == 0) {
      uVar2 = kfifoGetChidMgr_IMPL(param_1,param_2,local_1c);
      *param_5 = uVar2;
    }
    else {
      nvCheckFailedNoLog(1,"NV_OK == status","src/kernel/gpu/fifo/kernel_fifo.c",0x5e5);
    }
    return iVar1;
  }
  nvCheckFailedNoLog(1,"ppChidMgr != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x5dd);
  return 0x1f;
}


// ===== 00338900 kfifoChidMgrGetKernelChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8
kfifoChidMgrGetKernelChannel_IMPL(undefined8 param_1,long param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (param_3 == (undefined4 *)0x0) {
    nvAssertFailedNoLog("pChidMgr != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x605);
    return 0;
  }
  uVar1 = param_3[8];
  if (uVar1 == 0) {
    uVar1 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*param_3);
    if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar1)) {
      uVar1 = *(uint *)(param_2 + 0x4c0);
    }
    param_3[8] = uVar1;
    *(undefined1 *)(param_2 + 0x4bc) = 0;
    uVar1 = param_3[8];
  }
  if (uVar1 <= param_4) {
    return 0;
  }
  lVar2 = (**(code **)(*(long *)(param_3 + 2) + 0x40))(*(long *)(param_3 + 2),param_4,0);
  uVar3 = 0;
  if (lVar2 != 0) {
    uVar3 = *(undefined8 *)(lVar2 + 0x80);
  }
  return uVar3;
}


// ===== 003389c0 kfifoGetChannelGroupsInUse_IMPL =====

int kfifoGetChannelGroupsInUse_IMPL(undefined8 param_1,long param_2)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  int local_3c;
  
  iVar5 = 0;
  if (*(int *)(param_2 + 0x370) != 0) {
    iVar5 = 0;
    lVar6 = 0;
    do {
      while( true ) {
        lVar4 = *(long *)(param_2 + 0x368);
        puVar1 = *(undefined4 **)(lVar4 + lVar6 * 8);
        if (puVar1 == (undefined4 *)0x0) break;
        local_3c = puVar1[8];
        if (local_3c == 0) {
          uVar3 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar1);
          if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar3)) {
            uVar3 = *(uint *)(param_2 + 0x4c0);
          }
          puVar1[8] = uVar3;
          *(undefined1 *)(param_2 + 0x4bc) = 0;
          local_3c = puVar1[8];
          if (local_3c == 0) break;
          lVar4 = *(long *)(param_2 + 0x368);
        }
        iVar7 = 0;
        while( true ) {
          lVar4 = *(long *)(lVar4 + lVar6 * 8);
          cVar2 = nvBitFieldTest(*(undefined8 *)(lVar4 + 0x28),*(undefined4 *)(lVar4 + 0x30),iVar7);
          iVar5 = (iVar5 + 1) - (uint)(cVar2 == '\0');
          iVar7 = iVar7 + 1;
          if (iVar7 == local_3c) break;
          lVar4 = *(long *)(param_2 + 0x368);
        }
        lVar6 = lVar6 + 1;
        if (*(uint *)(param_2 + 0x370) <= (uint)lVar6) {
          return iVar5;
        }
      }
      lVar6 = lVar6 + 1;
    } while ((uint)lVar6 < *(uint *)(param_2 + 0x370));
  }
  return iVar5;
}


// ===== 00338ae0 kfifoGetRunlistChannelGroupsInUse_IMPL =====

int kfifoGetRunlistChannelGroupsInUse_IMPL(undefined8 param_1,long param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  puVar3 = (undefined4 *)kfifoGetChidMgr_IMPL();
  iVar6 = puVar3[8];
  if (iVar6 == 0) {
    uVar2 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar3);
    if (*(char *)(param_2 + 0x4bc) != '\0') {
      if (*(uint *)(param_2 + 0x4c0) < uVar2) {
        uVar2 = *(uint *)(param_2 + 0x4c0);
      }
    }
    puVar3[8] = uVar2;
    *(undefined1 *)(param_2 + 0x4bc) = 0;
    iVar6 = puVar3[8];
    if (iVar6 == 0) {
      return 0;
    }
  }
  iVar4 = 0;
  iVar5 = 0;
  do {
    cVar1 = nvBitFieldTest(*(undefined8 *)(puVar3 + 10),puVar3[0xc],iVar4);
    iVar5 = (iVar5 + 1) - (uint)(cVar1 == '\0');
    iVar4 = iVar4 + 1;
  } while (iVar6 != iVar4);
  return iVar5;
}


// ===== 00338b90 kfifoChannelGroupSetTimeslice_IMPL =====

undefined8
kfifoChannelGroupSetTimeslice_IMPL
          (undefined8 param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x698,"kfifoChannelGroupSetTimeslice_IMPL",1,
               "NVRM: Setting TSG %d Timeslice to %lldus\n",*(undefined4 *)(param_3 + 0xf0),param_4)
  ;
  *(undefined8 *)(param_3 + 0x148) = param_4;
  return 0;
}


// ===== 00338bf0 kfifoFillMemInfo_IMPL =====

void kfifoFillMemInfo_IMPL(undefined8 param_1,long param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 != 0) {
    iVar1 = memdescGetAddressSpace(param_2);
    if (iVar1 == 2) {
      *param_3 = 1;
    }
    else {
      iVar1 = memdescGetAddressSpace(param_2);
      if (iVar1 == 1) {
        if (*(int *)(param_2 + 0x74) == 0) {
          *param_3 = 2;
        }
        else if (*(int *)(param_2 + 0x74) == 1) {
          *param_3 = 3;
        }
        else {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x6c5,"kfifoFillMemInfo_IMPL",4,
                       "NVRM: kfifoFillMemInfo: Unknown cache attribute for sysmem aperture\n");
          nvAssertFailedNoLog("NV_FALSE","src/kernel/gpu/fifo/kernel_fifo.c",0x6c7);
        }
      }
    }
    uVar2 = memdescGetPhysAddr(param_2,1,0);
    *(undefined8 *)(param_3 + 2) = uVar2;
    *(undefined8 *)(param_3 + 4) = *(undefined8 *)(param_2 + 0x30);
    return;
  }
  *param_3 = 0;
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x6b1,"kfifoFillMemInfo_IMPL",4,
               "NVRM: kfifoFillMemInfo: pMemDesc = NULL\n");
  return;
}


// ===== 00338cf0 kfifoGetChannelIterator_IMPL =====

void kfifoGetChannelIterator_IMPL(undefined8 param_1,long param_2,long param_3,int param_4)

{
  long lVar1;
  
  portMemSet(param_3,0,0x28);
  if (param_4 == -1) {
    *(undefined4 *)(param_3 + 0xc) = 0;
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 0x370);
    return;
  }
  *(int *)(param_3 + 0xc) = param_4;
  lVar1 = kfifoGetChidMgr_IMPL(param_1,param_2,param_4);
  *(uint *)(param_3 + 4) = (uint)(lVar1 != 0);
  return;
}


// ===== 00338d70 kfifoGetNextKernelChannel_IMPL =====

undefined8
kfifoGetNextKernelChannel_IMPL(undefined8 param_1,long param_2,long param_3,undefined8 *param_4)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  
  if (param_4 == (undefined8 *)0x0) {
    return 0x1f;
  }
  *param_4 = 0;
  uVar5 = (ulong)*(uint *)(param_3 + 0xc);
  if (*(uint *)(param_3 + 4) == 1) {
    lVar4 = kfifoGetChidMgr_IMPL();
    if (lVar4 != 0) {
      uVar3 = _kfifoChidMgrGetNextKernelChannel(param_1,param_2,lVar4,param_3,param_4);
      return uVar3;
    }
    nvAssertFailedNoLog("pChidMgr != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x748);
    uVar3 = 0x1f;
  }
  else {
    if (*(uint *)(param_3 + 0xc) < *(uint *)(param_3 + 4)) {
LAB_00338e33:
      do {
        if (*(char *)(param_2 + 0x4b0) == '\0') {
          if (((*(uint *)(param_2 + 0x370) == 1) && (*(long *)(param_2 + 0x368) != 0)) &&
             (cVar2 = bitVectorTest_IMPL(param_2 + 0x378,0x40,0), cVar2 != '\0')) {
            lVar4 = **(long **)(param_2 + 0x368);
            goto LAB_00338df8;
          }
        }
        else if ((uint)uVar5 < *(uint *)(param_2 + 0x370)) {
          lVar4 = *(long *)(*(long *)(param_2 + 0x368) + uVar5 * 8);
LAB_00338df8:
          if (lVar4 != 0) {
            uVar3 = _kfifoChidMgrGetNextKernelChannel(param_1,param_2,lVar4,param_3,param_4);
            if ((int)uVar3 == 0) {
              return uVar3;
            }
            *(undefined4 *)(param_3 + 8) = 0;
            *(undefined8 *)(param_3 + 0x10) = 0;
            uVar1 = *(int *)(param_3 + 0xc) + 1;
            uVar5 = (ulong)uVar1;
            *(uint *)(param_3 + 0xc) = uVar1;
            if (*(uint *)(param_3 + 4) <= uVar1) break;
            goto LAB_00338e33;
          }
        }
        uVar1 = *(int *)(param_3 + 0xc) + 1;
        uVar5 = (ulong)uVar1;
        *(uint *)(param_3 + 0xc) = uVar1;
      } while (uVar1 < *(uint *)(param_3 + 4));
    }
    uVar3 = 0x57;
  }
  return uVar3;
}


// ===== 00338ee6 kfifoGetHostDeviceInfoTable_KERNEL.cold =====

void kfifoGetHostDeviceInfoTable_KERNEL_cold(void)

{
  code *pcVar1;
  long unaff_RBP;
  undefined8 unaff_R13;
  undefined8 unaff_R14;
  
  *(undefined8 *)(unaff_RBP + -0x18) = unaff_R13;
  *(undefined8 *)(unaff_RBP + -0x10) = unaff_R14;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00338f10 __pfx_kfifoGetHostDeviceInfoTable_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int __pfx_kfifoGetHostDeviceInfoTable_KERNEL(long param_1,long param_2,int *param_3,long param_4)

{
  int *piVar1;
  long *plVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  long lVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  int iStack_68;
  uint uStack_4c;
  long alStack_40 [2];
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar4 == '\0')) {
    uVar6 = *(undefined4 *)(param_1 + 0x3b34);
    uStack_4c = *(undefined4 *)(param_1 + 0x3b3c);
  }
  else {
    if (param_4 == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    plVar2 = *(long **)(*(long *)(param_4 + 0x110) + 0x48);
    lVar11 = *plVar2;
    iVar5 = subdeviceGetByInstance_IMPL(lVar11,(int)plVar2[2],0,alStack_40);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"subdeviceGetByInstance(pClient, RES_GET_HANDLE(pMigDevice), 0, &pSubdevice)"
                 ,"src/kernel/gpu/fifo/kernel_fifo.c",0x7e9);
      return iVar5;
    }
    uVar6 = *(undefined4 *)(lVar11 + 0x48);
    if (alStack_40[0] == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    uStack_4c = *(undefined4 *)(*(long *)(*(long *)(alStack_40[0] + 0x140) + 0x48) + 0x10);
  }
  piVar7 = (int *)portMemAllocNonPaged(0x708c);
  if (piVar7 == (int *)0x0) {
    iVar5 = 0x51;
    nvAssertFailedNoLog("(pLocals != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0x7f4);
  }
  else {
    piVar10 = piVar7 + 0x323;
    iVar9 = 0;
    uVar8 = 0;
    do {
      portMemSet(piVar7,0,0xc8c);
      *piVar7 = iVar9;
      iVar5 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,uVar6,uStack_4c,0x20801112,piVar7,0xc8c);
      if (iVar5 != 0) goto LAB_003391e1;
      if (0x20 < (uint)piVar7[1]) goto LAB_00339229;
      lVar11 = (ulong)(uint)piVar7[1] * 100;
      portMemCopy(piVar10,lVar11,piVar7 + 3,lVar11);
      uVar8 = piVar7[1] + uVar8;
      if ((char)piVar7[2] == '\0') break;
      iVar9 = iVar9 + 0x20;
      piVar10 = piVar10 + 800;
    } while (iVar9 != 0x100);
    param_3[0x14] = uVar8;
    lVar11 = portMemAllocNonPaged((ulong)uVar8 * 0x60);
    *(long *)(param_3 + 0x16) = lVar11;
    if (lVar11 == 0) {
      iVar5 = 0x51;
      nvCheckFailedNoLog(4,"pEngineInfo->engineInfoList != NULL","src/kernel/gpu/fifo/kernel_fifo.c"
                         ,0x82a);
    }
    else {
      if (uVar8 != 0) {
        uVar12 = 0;
        lVar15 = 0;
        uStack_4c = 0;
        piVar10 = piVar7 + 0x333;
        iStack_68 = 0;
LAB_003390b0:
        piVar1 = (int *)(lVar11 + lVar15);
        portMemCopy(piVar1,0x3c,piVar10 + -0x10,0x3c);
        uVar13 = piVar10[4];
        piVar1[0x13] = uVar13;
        if (uVar13 < 3) goto code_r0x003390da;
        nvAssertOkFailedNoLog
                  (0x40,
                   "pLocalEntry->numPbdmas <= NV_ARRAY_ELEMENTS(pLocalEntry->pbdmaIds) && pLocalEntry->numPbdmas <= NV_ARRAY_ELEMENTS(pLocalEntry->pbdmaFaultIds)"
                   ,"src/kernel/gpu/fifo/kernel_fifo.c",0x841);
LAB_00339229:
        iVar5 = 0x40;
        goto LAB_003391e1;
      }
      iStack_68 = 0;
      uVar12 = 0;
      uVar13 = 0;
LAB_00339192:
      iVar5 = (**(code **)(param_2 + 0x260))(param_1,param_2,lVar11,param_3[0x14]);
      if (iVar5 == 0) {
        if (*(char *)(param_1 + 0x908) != '\0') {
          uVar8 = 0;
          if (param_3[0x14] != 0) {
            uVar8 = 0;
            lVar11 = 0;
            do {
              lVar15 = 0;
              lVar14 = *(long *)(param_3 + 0x16) + lVar11 * 0x60;
              do {
                if (*(int *)(lVar14 + 8) == (&guestEngineLookupTable_1)[lVar15 * 2]) {
                  *(undefined4 *)(lVar14 + 0x20) = (&DAT_00d218a4)[lVar15 * 2];
                  uVar6 = gpuGetRmEngineType_IMPL();
                  *(undefined4 *)(lVar14 + 8) = uVar6;
                  if (uVar8 != (uint)lVar11) {
                    portMemCopy(*(long *)(param_3 + 0x16) + (ulong)uVar8 * 0x60,0x60,
                                *(long *)(param_3 + 0x16) + lVar11 * 0x60,0x60);
                  }
                  uVar8 = uVar8 + 1;
                  break;
                }
                lVar15 = lVar15 + 1;
              } while (lVar15 != 0x48);
              lVar11 = lVar11 + 1;
            } while ((uint)lVar11 < (uint)param_3[0x14]);
          }
          param_3[0x14] = uVar8;
        }
        param_3[0x13] = iStack_68;
        param_3[0x12] = uVar13 + 1;
        *param_3 = uVar12 + 1;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kfifoReservePbdmaFaultIds_HAL(pGpu, pKernelFifo, pEngineInfo->engineInfoList, pEngineInfo->engineInfoListSize)"
                   ,"src/kernel/gpu/fifo/kernel_fifo.c",0x86e);
      }
    }
LAB_003391e1:
    portMemFree(piVar7);
  }
  return iVar5;
code_r0x003390da:
  portMemCopy(piVar1 + 0xf,(ulong)uVar13 << 2,piVar10,(ulong)uVar13 << 2);
  portMemCopy(piVar1 + 0x11,(ulong)(uint)piVar1[0x13] << 2,piVar10 + 2,
              (ulong)(uint)piVar1[0x13] << 2);
  portStringCopy(piVar1 + 0x14,0x10,piVar10 + 5,0x10);
  iStack_68 = (iStack_68 + 1) - (uint)(piVar1[0xc] == 0);
  uVar13 = piVar10[-0xd];
  if ((uint)piVar10[-0xd] <= uStack_4c) {
    uVar13 = uStack_4c;
  }
  lVar11 = 0;
  if (piVar1[0x13] != 0) {
    do {
      if (uVar12 < (uint)piVar1[lVar11 + 0xf]) {
        uVar12 = piVar1[lVar11 + 0xf];
      }
      if (*piVar1 != -0x6a590b00) {
        bitVectorSet_IMPL(param_3 + 2,0x200,piVar1[lVar11 + 0x11]);
      }
      lVar11 = lVar11 + 1;
    } while ((uint)lVar11 < (uint)piVar1[0x13]);
  }
  lVar15 = lVar15 + 0x60;
  piVar10 = piVar10 + 0x19;
  lVar11 = *(long *)(param_3 + 0x16);
  uStack_4c = uVar13;
  if ((ulong)uVar8 * 0x60 == lVar15) goto LAB_00339192;
  goto LAB_003390b0;
}


// ===== 00338f20 kfifoGetHostDeviceInfoTable_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGetHostDeviceInfoTable_KERNEL(long param_1,long param_2,int *param_3,long param_4)

{
  int *piVar1;
  long *plVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  long lVar11;
  uint uVar12;
  uint uVar13;
  long lVar14;
  long lVar15;
  int local_68;
  uint local_4c;
  long local_40 [2];
  
  if (((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
     (cVar4 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(), cVar4 == '\0')) {
    uVar6 = *(undefined4 *)(param_1 + 0x3b34);
    local_4c = *(undefined4 *)(param_1 + 0x3b3c);
  }
  else {
    if (param_4 == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    plVar2 = *(long **)(*(long *)(param_4 + 0x110) + 0x48);
    lVar11 = *plVar2;
    iVar5 = subdeviceGetByInstance_IMPL(lVar11,(int)plVar2[2],0,local_40);
    if (iVar5 != 0) {
      nvAssertOkFailedNoLog
                (iVar5,"subdeviceGetByInstance(pClient, RES_GET_HANDLE(pMigDevice), 0, &pSubdevice)"
                 ,"src/kernel/gpu/fifo/kernel_fifo.c",0x7e9);
      return iVar5;
    }
    uVar6 = *(undefined4 *)(lVar11 + 0x48);
    if (local_40[0] == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)invalidInstructionException();
      (*pcVar3)();
    }
    local_4c = *(undefined4 *)(*(long *)(*(long *)(local_40[0] + 0x140) + 0x48) + 0x10);
  }
  piVar7 = (int *)portMemAllocNonPaged(0x708c);
  if (piVar7 == (int *)0x0) {
    iVar5 = 0x51;
    nvAssertFailedNoLog("(pLocals != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0x7f4);
  }
  else {
    piVar10 = piVar7 + 0x323;
    iVar9 = 0;
    uVar8 = 0;
    do {
      portMemSet(piVar7,0,0xc8c);
      *piVar7 = iVar9;
      iVar5 = (**(code **)(param_1 + 0x3b90))
                        (param_1 + 0x3b58,uVar6,local_4c,0x20801112,piVar7,0xc8c);
      if (iVar5 != 0) goto LAB_003391e1;
      if (0x20 < (uint)piVar7[1]) goto LAB_00339229;
      lVar11 = (ulong)(uint)piVar7[1] * 100;
      portMemCopy(piVar10,lVar11,piVar7 + 3,lVar11);
      uVar8 = piVar7[1] + uVar8;
      if ((char)piVar7[2] == '\0') break;
      iVar9 = iVar9 + 0x20;
      piVar10 = piVar10 + 800;
    } while (iVar9 != 0x100);
    param_3[0x14] = uVar8;
    lVar11 = portMemAllocNonPaged((ulong)uVar8 * 0x60);
    *(long *)(param_3 + 0x16) = lVar11;
    if (lVar11 == 0) {
      iVar5 = 0x51;
      nvCheckFailedNoLog(4,"pEngineInfo->engineInfoList != NULL","src/kernel/gpu/fifo/kernel_fifo.c"
                         ,0x82a);
    }
    else {
      if (uVar8 != 0) {
        uVar12 = 0;
        lVar15 = 0;
        local_4c = 0;
        piVar10 = piVar7 + 0x333;
        local_68 = 0;
LAB_003390b0:
        piVar1 = (int *)(lVar11 + lVar15);
        portMemCopy(piVar1,0x3c,piVar10 + -0x10,0x3c);
        uVar13 = piVar10[4];
        piVar1[0x13] = uVar13;
        if (uVar13 < 3) goto code_r0x003390da;
        nvAssertOkFailedNoLog
                  (0x40,
                   "pLocalEntry->numPbdmas <= NV_ARRAY_ELEMENTS(pLocalEntry->pbdmaIds) && pLocalEntry->numPbdmas <= NV_ARRAY_ELEMENTS(pLocalEntry->pbdmaFaultIds)"
                   ,"src/kernel/gpu/fifo/kernel_fifo.c",0x841);
LAB_00339229:
        iVar5 = 0x40;
        goto LAB_003391e1;
      }
      local_68 = 0;
      uVar12 = 0;
      uVar13 = 0;
LAB_00339192:
      iVar5 = (**(code **)(param_2 + 0x260))(param_1,param_2,lVar11,param_3[0x14]);
      if (iVar5 == 0) {
        if (*(char *)(param_1 + 0x908) != '\0') {
          uVar8 = 0;
          if (param_3[0x14] != 0) {
            uVar8 = 0;
            lVar11 = 0;
            do {
              lVar15 = 0;
              lVar14 = *(long *)(param_3 + 0x16) + lVar11 * 0x60;
              do {
                if (*(int *)(lVar14 + 8) == (&guestEngineLookupTable_1)[lVar15 * 2]) {
                  *(undefined4 *)(lVar14 + 0x20) = (&DAT_00d218a4)[lVar15 * 2];
                  uVar6 = gpuGetRmEngineType_IMPL();
                  *(undefined4 *)(lVar14 + 8) = uVar6;
                  if (uVar8 != (uint)lVar11) {
                    portMemCopy(*(long *)(param_3 + 0x16) + (ulong)uVar8 * 0x60,0x60,
                                *(long *)(param_3 + 0x16) + lVar11 * 0x60,0x60);
                  }
                  uVar8 = uVar8 + 1;
                  break;
                }
                lVar15 = lVar15 + 1;
              } while (lVar15 != 0x48);
              lVar11 = lVar11 + 1;
            } while ((uint)lVar11 < (uint)param_3[0x14]);
          }
          param_3[0x14] = uVar8;
        }
        param_3[0x13] = local_68;
        param_3[0x12] = uVar13 + 1;
        *param_3 = uVar12 + 1;
      }
      else {
        nvAssertOkFailedNoLog
                  (iVar5,
                   "kfifoReservePbdmaFaultIds_HAL(pGpu, pKernelFifo, pEngineInfo->engineInfoList, pEngineInfo->engineInfoListSize)"
                   ,"src/kernel/gpu/fifo/kernel_fifo.c",0x86e);
      }
    }
LAB_003391e1:
    portMemFree(piVar7);
  }
  return iVar5;
code_r0x003390da:
  portMemCopy(piVar1 + 0xf,(ulong)uVar13 << 2,piVar10,(ulong)uVar13 << 2);
  portMemCopy(piVar1 + 0x11,(ulong)(uint)piVar1[0x13] << 2,piVar10 + 2,
              (ulong)(uint)piVar1[0x13] << 2);
  portStringCopy(piVar1 + 0x14,0x10,piVar10 + 5,0x10);
  local_68 = (local_68 + 1) - (uint)(piVar1[0xc] == 0);
  uVar13 = piVar10[-0xd];
  if ((uint)piVar10[-0xd] <= local_4c) {
    uVar13 = local_4c;
  }
  lVar11 = 0;
  if (piVar1[0x13] != 0) {
    do {
      if (uVar12 < (uint)piVar1[lVar11 + 0xf]) {
        uVar12 = piVar1[lVar11 + 0xf];
      }
      if (*piVar1 != -0x6a590b00) {
        bitVectorSet_IMPL(param_3 + 2,0x200,piVar1[lVar11 + 0x11]);
      }
      lVar11 = lVar11 + 1;
    } while ((uint)lVar11 < (uint)piVar1[0x13]);
  }
  lVar15 = lVar15 + 0x60;
  piVar10 = piVar10 + 0x19;
  lVar11 = *(long *)(param_3 + 0x16);
  local_4c = uVar13;
  if ((ulong)uVar8 * 0x60 == lVar15) goto LAB_00339192;
  goto LAB_003390b0;
}


// ===== 00339410 kfifoConstructEngineList_KERNEL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

ulong kfifoConstructEngineList_KERNEL(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (*(long *)(param_2 + 0x3d8) != 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x909) != '\0') {
    uVar1 = (**(code **)(param_1 + 0xa0))();
    if (uVar1 != 0) {
      nvAssertOkFailedNoLog
                (uVar1,"gpuConstructDeviceInfoTable_HAL(pGpu)","src/kernel/gpu/fifo/kernel_fifo.c",
                 0x89b);
      return (ulong)uVar1;
    }
  }
  uVar2 = kfifoGetHostDeviceInfoTable_KERNEL(param_1,param_2,param_2 + 0x380,0);
  if ((int)uVar2 == 0) {
    return uVar2;
  }
  nvAssertOkFailedNoLog
            (uVar2 & 0xffffffff,"kfifoGetHostDeviceInfoTable_HAL(pGpu, pKernelFifo, pEngineInfo, 0)"
             ,"src/kernel/gpu/fifo/kernel_fifo.c",0x89e);
  return uVar2 & 0xffffffff;
}


// ===== 003394c0 kfifoChidMgrConstruct_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */
/* WARNING: Function: __x86_indirect_thunk_rcx replaced with injection: x86_indirect_thunk_rcx */

int kfifoChidMgrConstruct_IMPL(long param_1,long param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  code *pcVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  uint uVar11;
  long lVar12;
  int iVar13;
  ulong uVar14;
  uint local_3c [3];
  
  if (*(char *)(param_2 + 0x4b0) == '\0') {
    *(undefined4 *)(param_2 + 0x370) = 1;
    lVar12 = 8;
  }
  else {
    iVar8 = kfifoConstructEngineList_KERNEL();
    if (iVar8 != 0) {
      nvAssertOkFailedNoLog
                (iVar8,"kfifoConstructEngineList_HAL(pGpu, pKernelFifo)",
                 "src/kernel/gpu/fifo/kernel_fifo.c",0x74);
      return iVar8;
    }
    uVar7 = (**(code **)(param_2 + 0x250))(param_1,param_2);
    *(uint *)(param_2 + 0x370) = uVar7;
    if (0x40 < uVar7) {
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x81,"kfifoChidMgrConstruct_IMPL",4,
                   "NVRM: numChidMgrs 0x%x exceeds MAX_NUM_RUNLISTS\n",uVar7);
      return 2;
    }
    lVar12 = (ulong)uVar7 * 8;
  }
  lVar12 = portMemAllocNonPaged(lVar12);
  *(long *)(param_2 + 0x368) = lVar12;
  if (lVar12 == 0) {
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x8c,"kfifoChidMgrConstruct_IMPL",4,
                 "NVRM: Failed to allocate pFifo->pChidMgr\n");
    iVar8 = 0x51;
  }
  else {
    portMemSet(lVar12,0,(ulong)*(uint *)(param_2 + 0x370) << 3);
    if (*(char *)(param_2 + 0x4b0) == '\0') {
      bitVectorSet_IMPL(param_2 + 0x378,0x40,0);
    }
    else {
      iVar6 = (**(code **)(param_2 + 0x240))(param_1,param_2);
      if (iVar6 != 0) {
        iVar13 = 0;
        do {
          iVar8 = (**(code **)(param_2 + 0x218))(param_1,param_2,0xf,iVar13,3,local_3c);
          if (iVar8 != 0) {
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0xa0,"kfifoChidMgrConstruct_IMPL",4,
                         "NVRM: Translation to runlistId failed for engine %d\n",iVar13);
            goto LAB_003395d9;
          }
          iVar13 = iVar13 + 1;
          bitVectorSet_IMPL(param_2 + 0x378,0x40,local_3c[0]);
        } while (iVar13 != iVar6);
      }
    }
    if (*(int *)(param_2 + 0x370) == 0) {
      iVar8 = 0;
    }
    else {
      uVar14 = 0;
LAB_003396c1:
      while( true ) {
        cVar4 = bitVectorTest_IMPL(param_2 + 0x378,0x40,uVar14 & 0xffffffff);
        if (cVar4 != '\0') break;
LAB_003396b0:
        uVar14 = uVar14 + 1;
        if (*(uint *)(param_2 + 0x370) <= (uint)uVar14) {
          return 0;
        }
      }
      lVar12 = *(long *)(param_2 + 0x368);
      uVar9 = portMemAllocNonPaged(0x40);
      *(undefined8 *)(lVar12 + uVar14 * 8) = uVar9;
      lVar12 = *(long *)(*(long *)(param_2 + 0x368) + uVar14 * 8);
      if (lVar12 == 0) {
        nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0xb5,"kfifoChidMgrConstruct_IMPL",4,
                     "NVRM: Failed to allocate pFifo->pChidMgr[%d]\n",uVar14 & 0xffffffff);
LAB_00339a26:
        iVar8 = 0x51;
        goto LAB_003395d9;
      }
      portMemSet(lVar12,0,0x40);
      **(undefined4 **)(*(long *)(param_2 + 0x368) + uVar14 * 8) = (int)uVar14;
      lVar12 = *(long *)(*(long *)(param_2 + 0x368) + uVar14 * 8);
      uVar9 = portMemAllocNonPaged(0x10);
      *(undefined8 *)(lVar12 + 0x38) = uVar9;
      mapInitIntrusive_IMPL
                (*(undefined8 *)(*(long *)(*(long *)(param_2 + 0x368) + uVar14 * 8) + 0x38),0x1a0);
      puVar2 = *(undefined4 **)(*(long *)(param_2 + 0x368) + uVar14 * 8);
      if (puVar2[8] != 0) {
LAB_003397a3:
        lVar12 = portMemAllocNonPaged(0xd8);
        *(long *)(puVar2 + 2) = lVar12;
        if (lVar12 == 0) {
          uVar9 = nvstatusToString(0x51);
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x13a,"_kfifoChidMgrAllocChidHeaps",4,
                       "NVRM: Error in Allocating memory for pFifoDataHeap! Status = %s (0x%x)\n",
                       uVar9,0x51);
LAB_00339add:
          iVar8 = 0x51;
          goto LAB_00339ae3;
        }
        constructObjEHeap(lVar12,0,puVar2[8],8,0);
        iVar8 = puVar2[8];
        if (iVar8 == 0) {
          uVar7 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar2);
          if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar7)) {
            uVar7 = *(uint *)(param_2 + 0x4c0);
          }
          puVar2[8] = uVar7;
          *(undefined1 *)(param_2 + 0x4bc) = 0;
          iVar8 = puVar2[8];
        }
        lVar12 = portMemAllocNonPaged(0xd8);
        *(long *)(puVar2 + 4) = lVar12;
        if (lVar12 == 0) {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x147,"_kfifoChidMgrAllocChidHeaps",4,
                       "NVRM: Error in Allocating memory for global ChID heap!\n");
          goto LAB_00339add;
        }
        constructObjEHeap(lVar12,0,iVar8,8,0);
        (**(code **)(param_2 + 0x2a0))(param_2,local_3c,0);
        uVar5 = (**(code **)(param_2 + 0x2f8))(param_2);
        pcVar3 = *(code **)(*(long *)(puVar2 + 4) + 0x60);
        (*pcVar3)(*(long *)(puVar2 + 4),uVar5,0x1000 / (ulong)local_3c[0],pcVar3);
        if (*(char *)(param_1 + 0x908) == '\0') {
          if (*(char *)(param_1 + 0x909) != '\0') {
LAB_00339863:
            pcVar3 = *(code **)(*(long *)(puVar2 + 4) + 0x60);
            (*pcVar3)(*(long *)(puVar2 + 4),0,0x1000 / (ulong)local_3c[0],pcVar3);
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x170,"_kfifoChidMgrAllocChidHeaps",1,
                         "NVRM: Sub Process channel isolation disabled by vGPU plugin\n");
            goto LAB_003398a4;
          }
LAB_003398ae:
          if (*(char *)(param_1 + 0x491d) != '\0') {
            puVar10 = (undefined8 *)portMemAllocNonPaged(0x200);
            *(undefined8 **)(puVar2 + 6) = puVar10;
            if (puVar10 == (undefined8 *)0x0) {
              nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x10d,
                           "_kfifoChidMgrAllocVChidHeapPointers",4,
                           "NVRM: Error allocating memory for virtual channel heap pointers\n");
              goto LAB_00339add;
            }
            *puVar10 = 0;
            lVar12 = 8;
            do {
              *(undefined8 *)(*(long *)(puVar2 + 6) + lVar12) = 0;
              lVar12 = lVar12 + 8;
            } while (lVar12 != 0x200);
          }
        }
        else {
          lVar12 = gpuGetStaticInfo(param_1);
          if ((lVar12 != 0) && (*(int *)(lVar12 + 0xa7a4) == 0)) goto LAB_00339863;
LAB_003398a4:
          if (*(char *)(param_1 + 0x908) == '\0') goto LAB_003398ae;
        }
        puVar2 = *(undefined4 **)(*(long *)(param_2 + 0x368) + uVar14 * 8);
        lVar12 = gpuGetKernelFifoShared_IMPL(param_1);
        uVar7 = puVar2[8];
        if (uVar7 != 0) {
LAB_00339640:
          uVar11 = uVar7 + 0x1f >> 3 & 0x1ffffffc;
          lVar12 = portMemAllocNonPaged(uVar11);
          *(long *)(puVar2 + 10) = lVar12;
          if (lVar12 != 0) {
            puVar2[0xc] = uVar7 + 0x1f >> 5;
            portMemSet(lVar12,0,uVar11);
            if ((uVar7 & 0x1f) != 0) {
              puVar1 = (uint *)(*(long *)(puVar2 + 10) + (ulong)(uVar7 >> 5) * 4);
              *puVar1 = *puVar1 | -1 << (sbyte)(uVar7 & 0x1f);
            }
            goto LAB_003396b0;
          }
          goto LAB_00339a26;
        }
        uVar7 = kfifoRunlistQueryNumChannels_KERNEL(param_1,lVar12,*puVar2);
        if ((*(char *)(lVar12 + 0x4bc) != '\0') && (*(uint *)(lVar12 + 0x4c0) < uVar7)) {
          uVar7 = *(uint *)(lVar12 + 0x4c0);
        }
        puVar2[8] = uVar7;
        *(undefined1 *)(lVar12 + 0x4bc) = 0;
        uVar7 = puVar2[8];
        if (uVar7 != 0) goto LAB_00339640;
        uVar14 = uVar14 + 1;
        if (*(uint *)(param_2 + 0x370) <= (uint)uVar14) {
          return 0;
        }
        goto LAB_003396c1;
      }
      uVar7 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar2);
      if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar7)) {
        uVar7 = *(uint *)(param_2 + 0x4c0);
      }
      puVar2[8] = uVar7;
      *(undefined1 *)(param_2 + 0x4bc) = 0;
      if (puVar2[8] != 0) goto LAB_003397a3;
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x130,"_kfifoChidMgrAllocChidHeaps",4,
                   "NVRM: pChidMgr->numChannels is 0\n");
      iVar8 = 0x40;
LAB_00339ae3:
      uVar9 = nvstatusToString(iVar8);
      nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0xc3,"kfifoChidMgrConstruct_IMPL",4,
                   "NVRM: Error allocating FifoDataHeap in pChidMgr. Status = %s (0x%x)\n",uVar9,
                   iVar8);
LAB_003395d9:
      kfifoChidMgrDestruct_IMPL(param_2);
    }
  }
  return iVar8;
}


// ===== 00339c30 kfifoChannelListCreate_IMPL =====

undefined8 kfifoChannelListCreate_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_3 != (long *)0x0) {
    puVar1 = (undefined8 *)portMemAllocNonPaged(0x10);
    *param_3 = (long)puVar1;
    if (puVar1 == (undefined8 *)0x0) {
      nvAssertFailedNoLog("(*ppList != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0x8b6);
      uVar2 = 0x51;
    }
    else {
      *puVar1 = 0;
      *(undefined8 *)(*param_3 + 8) = 0;
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x1f;
}


// ===== 00339ca0 kfifoChannelListAppend_IMPL =====

undefined8
kfifoChannelListAppend_IMPL(undefined8 param_1,undefined8 param_2,long param_3,long *param_4)

{
  long *plVar1;
  
  if ((param_3 != 0) && (param_4 != (long *)0x0)) {
    plVar1 = (long *)portMemAllocNonPaged(0x10);
    if (plVar1 != (long *)0x0) {
      *plVar1 = param_3;
      *(int *)(param_3 + 0x2d0) = *(int *)(param_3 + 0x2d0) + 1;
      plVar1[1] = 0;
      if (param_4[1] == 0) {
        *param_4 = (long)plVar1;
        param_4[1] = (long)plVar1;
      }
      else {
        *(long **)(param_4[1] + 8) = plVar1;
        param_4[1] = (long)plVar1;
      }
      return 0;
    }
    nvAssertFailedNoLog("(pNewNode != NULL)","src/kernel/gpu/fifo/kernel_fifo.c",0x8d6);
    return 0x51;
  }
  return 0x1f;
}


// ===== 00339d40 kfifoChannelListRemove_IMPL =====

undefined8
kfifoChannelListRemove_IMPL(undefined8 param_1,undefined8 param_2,long param_3,long *param_4)

{
  long *plVar1;
  bool bVar2;
  bool bVar3;
  long *plVar4;
  long *plVar5;
  
  if ((param_4 == (long *)0x0) || (param_3 == 0)) {
    return 0x1f;
  }
  if ((long *)*param_4 != (long *)0x0) {
    plVar1 = (long *)*param_4;
    plVar5 = (long *)0x0;
    bVar3 = false;
    do {
      while (bVar2 = bVar3, plVar4 = plVar1, *plVar4 == param_3) {
        if ((long *)*param_4 == plVar4) {
          *param_4 = plVar4[1];
        }
        if ((long *)param_4[1] == plVar4) {
          param_4[1] = (long)plVar5;
        }
        if (plVar5 != (long *)0x0) {
          plVar5[1] = plVar4[1];
        }
        plVar1 = (long *)plVar4[1];
        portMemFree();
        if (*(int *)(param_3 + 0x2d0) == 0) {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x931,"kfifoChannelListRemove_IMPL",4,
                       "NVRM: RefCount for channel is not right!!!\n");
          return 0xffff;
        }
        *(int *)(param_3 + 0x2d0) = *(int *)(param_3 + 0x2d0) + -1;
        bVar2 = true;
        bVar3 = true;
        if (plVar1 == (long *)0x0) goto LAB_00339df3;
      }
      plVar1 = (long *)plVar4[1];
      plVar5 = plVar4;
      bVar3 = bVar2;
    } while ((long *)plVar4[1] != (long *)0x0);
LAB_00339df3:
    if (bVar2) {
      return 0;
    }
  }
  nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x93d,"kfifoChannelListRemove_IMPL",1,
               "NVRM: Can\'t find channel in channelGroupList (Normal during RC Recovery on GK110+ or if software scheduling is enabled).\n"
              );
  return 0x21;
}


// ===== 00339ec0 kfifoChannelListDestroy_IMPL =====

undefined8 kfifoChannelListDestroy_IMPL(undefined8 param_1,undefined8 param_2,long *param_3)

{
  long *plVar1;
  long lVar2;
  
  if (param_3 == (long *)0x0) {
    return 0;
  }
  plVar1 = (long *)*param_3;
  while( true ) {
    if (plVar1 == (long *)0x0) {
      portMemFree(param_3);
      return 0;
    }
    lVar2 = *plVar1;
    if ((lVar2 == 0) || (*(int *)(lVar2 + 0x2d0) == 0)) break;
    *(int *)(lVar2 + 0x2d0) = *(int *)(lVar2 + 0x2d0) + -1;
    *param_3 = plVar1[1];
    portMemFree();
    plVar1 = (long *)*param_3;
  }
  nvAssertFailedNoLog("pTempNode->pKernelChannel && pTempNode->pKernelChannel->refCount",
                      "src/kernel/gpu/fifo/kernel_fifo.c",0x95f);
  return 0x40;
}


// ===== 00339f4b kfifoEngineListHasChannel_IMPL.cold =====

void kfifoEngineListHasChannel_IMPL_cold(void)

{
  code *pcVar1;
  undefined8 unaff_RBX;
  long unaff_RBP;
  
  *(undefined8 *)(unaff_RBP + -0x28) = unaff_RBX;
                    /* WARNING: Does not return */
  pcVar1 = (code *)invalidInstructionException();
  (*pcVar1)();
}


// ===== 00339f60 kfifoEngineListHasChannel_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

undefined8 kfifoEngineListHasChannel_IMPL(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  int local_6c;
  long local_68;
  undefined1 local_60 [4];
  undefined4 local_5c;
  undefined4 local_54;
  
  if ((param_3 == 0) || (param_4 == 0)) {
    nvAssertFailedNoLog("(pEngines != NULL) && (engineCount > 0)",
                        "src/kernel/gpu/fifo/kernel_fifo.c",0x983);
  }
  else {
    portMemSet(local_60,0,0x28);
    local_5c = *(undefined4 *)(param_2 + 0x370);
    local_54 = 0;
    while( true ) {
      while( true ) {
        while( true ) {
          iVar3 = kchannelGetNextKernelChannel(param_1,local_60,&local_68);
          if (iVar3 != 0) {
            return 0;
          }
          if (local_68 != 0) break;
          nvAssertFailedNoLog("pKernelChannel != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x989);
        }
        iVar3 = *(int *)(local_68 + 0x42c);
        if (0x52 < iVar3 - 1U) break;
        lVar4 = 0;
        do {
          if (*(int *)(param_3 + lVar4 * 4) == iVar3) {
            nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x992,"kfifoEngineListHasChannel_IMPL",
                         4,"NVRM: Found channel on engine 0x%x owned by 0x%x\n",iVar3,
                         *(undefined4 *)(**(long **)(*(long *)(local_68 + 0x140) + 0x48) + 0x48));
            return 1;
          }
          lVar4 = lVar4 + 1;
        } while ((uint)lVar4 < param_4);
      }
      if (*(char *)(param_2 + 0x4b0) != '\0') {
        nvAssertFailedNoLog("!kfifoIsPerRunlistChramEnabled(pKernelFifo)",
                            "src/kernel/gpu/fifo/kernel_fifo.c",0x99f);
        return 1;
      }
      cVar2 = kchannelIsRunlistSet(param_1);
      if (cVar2 == '\0') break;
      lVar4 = 0;
      do {
        iVar3 = (**(code **)(param_2 + 0x218))
                          (param_1,param_2,2,*(undefined4 *)(param_3 + lVar4 * 4),3,&local_6c);
        if (iVar3 != 0) {
          nvAssertFailedNoLog("(kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32)pEngines[i], ENGINE_INFO_TYPE_RUNLIST, &runlistId) == NV_OK)"
                              ,"src/kernel/gpu/fifo/kernel_fifo.c",0x9aa);
          return 1;
        }
        if (local_6c == *(int *)(local_68 + 0x2b0)) {
          nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x9af,"kfifoEngineListHasChannel_IMPL",4,
                       "NVRM: Found channel on runlistId 0x%x owned by 0x%x\n",
                       *(int *)(local_68 + 0x2b0),
                       *(undefined4 *)(**(long **)(*(long *)(local_68 + 0x140) + 0x48) + 0x48));
          return 1;
        }
        lVar4 = lVar4 + 1;
      } while ((uint)lVar4 < param_4);
    }
    if (local_68 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)invalidInstructionException();
      (*pcVar1)();
    }
    nvDbg_Printf("src/kernel/gpu/fifo/kernel_fifo.c",0x9b9,"kfifoEngineListHasChannel_IMPL",4,
                 "NVRM: Found channel owned by 0x%x that can be associated to any engine\n",
                 *(undefined4 *)(**(long **)(*(long *)(local_68 + 0x140) + 0x48) + 0x48));
  }
  return 1;
}


// ===== 0033a260 kfifoGetRunlistBufPool_IMPL =====

undefined8 kfifoGetRunlistBufPool_IMPL(undefined8 param_1,long param_2,uint param_3)

{
  return *(undefined8 *)(param_2 + 0x4f8 + (ulong)param_3 * 8);
}


// ===== 0033a270 kfifoGetMaxChannelsInSystem_IMPL =====

int kfifoGetMaxChannelsInSystem_IMPL(undefined8 param_1,long param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)(param_2 + 0x370) != 0) {
    iVar5 = 0;
    lVar4 = 0;
    do {
      puVar1 = *(undefined4 **)(*(long *)(param_2 + 0x368) + lVar4 * 8);
      if (puVar1 != (undefined4 *)0x0) {
        iVar2 = puVar1[8];
        if (iVar2 == 0) {
          uVar3 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar1);
          if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar3)) {
            uVar3 = *(uint *)(param_2 + 0x4c0);
          }
          puVar1[8] = uVar3;
          *(undefined1 *)(param_2 + 0x4bc) = 0;
          iVar2 = puVar1[8];
        }
        iVar5 = iVar5 + iVar2;
      }
      lVar4 = lVar4 + 1;
    } while ((uint)lVar4 < *(uint *)(param_2 + 0x370));
  }
  return iVar5;
}


// ===== 0033a340 kfifoGetRunlistBufInfo_IMPL =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

int kfifoGetRunlistBufInfo_IMPL
              (long param_1,long param_2,undefined4 param_3,uint param_4,long *param_5,long *param_6
              )

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  ulong uVar8;
  undefined4 local_3c [3];
  
  puVar7 = (undefined4 *)kfifoGetChidMgr_IMPL();
  if (param_5 == (long *)0x0) {
    nvAssertFailedNoLog("pSize != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x9ee);
  }
  else if (param_6 == (long *)0x0) {
    nvAssertFailedNoLog("pAlignment != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x9ef);
  }
  else {
    if (*(char *)(param_2 + 0x4b0) == '\0') {
      iVar3 = kfifoGetMaxChannelsInSystem_IMPL(param_1,param_2);
      iVar4 = kfifoGetMaxChannelsInSystem_IMPL(param_1,param_2);
      uVar6 = iVar3 + iVar4;
    }
    else {
      if (puVar7 == (undefined4 *)0x0) {
        nvAssertFailedNoLog("pChidMgr != NULL","src/kernel/gpu/fifo/kernel_fifo.c",0x9f3);
        return 0x1f;
      }
      iVar3 = puVar7[8];
      if (iVar3 == 0) {
        uVar6 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar7);
        if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar6)) {
          uVar6 = *(uint *)(param_2 + 0x4c0);
        }
        puVar7[8] = uVar6;
        *(undefined1 *)(param_2 + 0x4bc) = 0;
        iVar3 = puVar7[8];
      }
      uVar6 = iVar3 * 2;
    }
    if (param_4 <= uVar6) {
      if (param_4 != 0) {
        uVar6 = param_4;
      }
      iVar3 = (**(code **)(param_2 + 0x218))(param_1,param_2,3,param_3,2,local_3c);
      if (iVar3 != 0) {
        nvAssertOkFailedNoLog
                  (iVar3,
                   "kfifoEngineInfoXlate_HAL(pGpu, pKernelFifo, ENGINE_INFO_TYPE_RUNLIST, runlistId, ENGINE_INFO_TYPE_RM_ENGINE_TYPE, (NvU32 *)&rmEngineType)"
                   ,"src/kernel/gpu/fifo/kernel_fifo.c",0xa08);
        return iVar3;
      }
      if ((((param_1 == 0) || (*(long *)(param_1 + 0x1bc0) == 0)) ||
          (cVar1 = kmigmgrIsMIGGpuInstancingEnabled_IMPL(param_1), cVar1 == '\0')) ||
         (*(char *)(param_1 + 0x909) == '\0')) {
        uVar8 = 1;
      }
      else {
        uVar5 = vgpuMgrGetVmsetCountToAllocate(param_1,local_3c[0]);
        uVar8 = (ulong)uVar5;
      }
      uVar5 = (**(code **)(param_2 + 0x270))(param_2);
      *param_5 = uVar6 * uVar8 * (ulong)uVar5;
      bVar2 = (**(code **)(param_2 + 0x278))(param_2);
      *param_6 = 1L << (bVar2 & 0x3f);
      return 0;
    }
    nvAssertFailedNoLog("maxRunlistEntries <= maxRunlistEntriesSupported",
                        "src/kernel/gpu/fifo/kernel_fifo.c",0xa01);
  }
  return 0x1f;
}


// ===== 0033a5d0 kfifoGetMaxChannelGroupsInSystem_IMPL =====

int kfifoGetMaxChannelGroupsInSystem_IMPL(undefined8 param_1,long param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)(param_2 + 0x370) != 0) {
    iVar5 = 0;
    lVar4 = 0;
    do {
      puVar1 = *(undefined4 **)(*(long *)(param_2 + 0x368) + lVar4 * 8);
      if (puVar1 != (undefined4 *)0x0) {
        iVar2 = puVar1[8];
        if (iVar2 == 0) {
          uVar3 = kfifoRunlistQueryNumChannels_KERNEL(param_1,param_2,*puVar1);
          if ((*(char *)(param_2 + 0x4bc) != '\0') && (*(uint *)(param_2 + 0x4c0) < uVar3)) {
            uVar3 = *(uint *)(param_2 + 0x4c0);
          }
          puVar1[8] = uVar3;
          *(undefined1 *)(param_2 + 0x4bc) = 0;
          iVar2 = puVar1[8];
        }
        iVar5 = iVar5 + iVar2;
      }
      lVar4 = lVar4 + 1;
    } while ((uint)lVar4 < *(uint *)(param_2 + 0x370));
  }
  return iVar5;
}


// ===== 0033a6a0 kfifoRunlistGetBufAllocParams_IMPL =====

void kfifoRunlistGetBufAllocParams_IMPL
               (long param_1,undefined4 *param_2,undefined4 *param_3,ulong *param_4)

{
  *param_2 = 2;
  *param_3 = 2;
  memdescOverrideInstLoc(*(uint *)(param_1 + 0x4924) >> 0xc & 3,"runlist",param_2,param_3);
  *param_4 = (ulong)((*(uint *)(param_1 + 0x4938) & 4) << 5);
  return;
}


