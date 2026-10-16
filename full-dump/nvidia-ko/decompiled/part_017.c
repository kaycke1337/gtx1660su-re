// ===== 00198970 __nvoc_objCreateDynamic_SemaphoreSurface =====

void __nvoc_objCreateDynamic_SemaphoreSurface
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0019899e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0019899e:
  __nvoc_objCreate_SemaphoreSurface(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 001989d0 spdmStatePostLoad_ac1694 =====

undefined8 spdmStatePostLoad_ac1694(void)

{
  return 0;
}


// ===== 001989e0 spdmGetCertChains_395e98 =====

undefined8 spdmGetCertChains_395e98(void)

{
  return 0x56;
}


// ===== 001989f0 spdmGetAttestationReport_395e98 =====

undefined8 spdmGetAttestationReport_395e98(void)

{
  return 0x56;
}


// ===== 00198a00 spdmCheckAndExecuteKeyUpdate_395e98 =====

undefined8 spdmCheckAndExecuteKeyUpdate_395e98(void)

{
  return 0x56;
}


// ===== 00198a10 spdmSendInitRmDataCommand_395e98 =====

undefined8 spdmSendInitRmDataCommand_395e98(void)

{
  return 0x56;
}


// ===== 00198a20 spdmMutualAuthSupported_e661f0 =====

undefined8 spdmMutualAuthSupported_e661f0(void)

{
  return 1;
}


// ===== 00198a30 spdmMutualAuthSupported_d69453 =====

undefined8 spdmMutualAuthSupported_d69453(void)

{
  return 0;
}


// ===== 00198a40 spdmSendCtrlCall_395e98 =====

undefined8 spdmSendCtrlCall_395e98(void)

{
  return 0x56;
}


// ===== 00198a50 spdmDeviceDeinit_395e98 =====

undefined8 spdmDeviceDeinit_395e98(void)

{
  return 0x56;
}


// ===== 00198a60 spdmMessageProcess_395e98 =====

undefined8 spdmMessageProcess_395e98(void)

{
  return 0x56;
}


// ===== 00198a70 spdmGetReqEncapCertificates_395e98 =====

undefined8 spdmGetReqEncapCertificates_395e98(void)

{
  return 0x56;
}


// ===== 00198a80 spdmGetBinArchiveIndividualL2Certificate_9e2234 =====

undefined8 spdmGetBinArchiveIndividualL2Certificate_9e2234(void)

{
  return 0;
}


// ===== 00198a90 spdmGetIndividualCertificate_395e98 =====

undefined8 spdmGetIndividualCertificate_395e98(void)

{
  return 0x56;
}


// ===== 00198aa0 spdmConvertCertificateToDer_395e98 =====

undefined8 spdmConvertCertificateToDer_395e98(void)

{
  return 0x56;
}


// ===== 00198ab0 __nvoc_down_thunk_Spdm_engstateConstructEngine =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Spdm_engstateConstructEngine(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + -8) + 0xb8))(param_1,param_2 + -8);
  return;
}


// ===== 00198ad0 __nvoc_down_thunk_Spdm_engstateStatePostLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Spdm_engstateStatePostLoad(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x160))(param_1,param_2 + -8);
  return;
}


// ===== 00198af0 __nvoc_down_thunk_Spdm_engstateStatePreUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Spdm_engstateStatePreUnload(undefined8 param_1,long param_2)

{
  (**(code **)(param_2 + 0x168))(param_1,param_2 + -8);
  return;
}


// ===== 00198b10 __nvoc_up_thunk_OBJENGSTATE_spdmInitMissing =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmInitMissing(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x38))(param_1,param_2 + 8);
  return;
}


// ===== 00198b30 __nvoc_up_thunk_OBJENGSTATE_spdmStatePreInitLocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStatePreInitLocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x40))(param_1,param_2 + 8);
  return;
}


// ===== 00198b50 __nvoc_up_thunk_OBJENGSTATE_spdmStatePreInitUnlocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStatePreInitUnlocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x48))(param_1,param_2 + 8);
  return;
}


// ===== 00198b70 __nvoc_up_thunk_OBJENGSTATE_spdmStateInitLocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStateInitLocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x50))(param_1,param_2 + 8);
  return;
}


// ===== 00198b90 __nvoc_up_thunk_OBJENGSTATE_spdmStateInitUnlocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStateInitUnlocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x58))(param_1,param_2 + 8);
  return;
}


// ===== 00198bb0 __nvoc_up_thunk_OBJENGSTATE_spdmStatePreLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStatePreLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x60))(param_1,param_2 + 8);
  return;
}


// ===== 00198bd0 __nvoc_up_thunk_OBJENGSTATE_spdmStateLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStateLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x68))(param_1,param_2 + 8);
  return;
}


// ===== 00198bf0 __nvoc_up_thunk_OBJENGSTATE_spdmStateUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStateUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x80))(param_1,param_2 + 8);
  return;
}


// ===== 00198c10 __nvoc_up_thunk_OBJENGSTATE_spdmStatePostUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStatePostUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x88))(param_1,param_2 + 8);
  return;
}


// ===== 00198c30 __nvoc_up_thunk_OBJENGSTATE_spdmStateDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmStateDestroy(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x90))(param_1,param_2 + 8);
  return;
}


// ===== 00198c50 __nvoc_up_thunk_OBJENGSTATE_spdmIsPresent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_spdmIsPresent(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x98))(param_1,param_2 + 8);
  return;
}


// ===== 00198c70 __nvoc_init_funcTable_Spdm_1 =====

void __nvoc_init_funcTable_Spdm_1(long param_1,long param_2,long param_3)

{
  ulong uVar1;
  ushort uVar2;
  ushort uVar3;
  code *pcVar4;
  code *pcVar5;
  
  pcVar5 = spdmStatePostLoad_ac1694;
  uVar3 = *(ushort *)(param_3 + 0x10);
  pcVar4 = spdmStatePreUnload_ac1694;
  if (*(short *)(param_2 + 0x10) == 1) {
    pcVar5 = spdmStatePostLoad_KERNEL;
    pcVar4 = spdmStatePreUnload_KERNEL;
  }
  *(code **)(param_1 + 0x168) = pcVar5;
  *(code **)(param_1 + 0x170) = pcVar4;
  if (uVar3 >> 5 == 1) {
    uVar2 = uVar3 & 0x1f;
    uVar3 = uVar3 & 0x1f;
    if ((0xbc000000UL >> uVar2 & 1) == 0) {
      *(code **)(param_1 + 0x178) = spdmGetCertChains_395e98;
      *(code **)(param_1 + 0x180) = spdmGetAttestationReport_395e98;
      *(code **)(param_1 + 0x188) = spdmCheckAndExecuteKeyUpdate_395e98;
      *(code **)(param_1 + 400) = spdmSendInitRmDataCommand_395e98;
      *(code **)(param_1 + 0x198) = spdmRegisterForHeartbeats_395e98;
      *(code **)(param_1 + 0x1a0) = spdmUnregisterFromHeartbeats_395e98;
      if (uVar3 == 0x1a) {
        pcVar5 = spdmMutualAuthSupported_e661f0;
        goto LAB_00198f32;
      }
      *(code **)(param_1 + 0x1a8) = spdmMutualAuthSupported_d69453;
      *(code **)(param_1 + 0x1b0) = spdmSendCtrlCall_395e98;
      *(code **)(param_1 + 0x1b8) = spdmDeviceInit_395e98;
      *(code **)(param_1 + 0x1c0) = spdmDeviceDeinit_395e98;
      *(code **)(param_1 + 0x1c8) = spdmDeviceSecuredSessionSupported_395e98;
      *(code **)(param_1 + 0x1d0) = spdmCheckConnection_395e98;
      *(code **)(param_1 + 0x1d8) = spdmMessageProcess_395e98;
      *(code **)(param_1 + 0x1e0) = spdmGetCertificates_395e98;
      *(code **)(param_1 + 0x1e8) = spdmGetReqEncapCertificates_395e98;
      if ((0xb8000000UL >> uVar2 & 1) == 0) {
LAB_001992d0:
        *(code **)(param_1 + 0x1f0) = spdmGetRequesterCertificateCount_395e98;
        *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_9e2234;
        if (uVar3 == 0x1b) goto LAB_00199210;
        if (uVar3 != 0x1c) {
          if (uVar3 != 0x1f) {
            pcVar5 = spdmGetIndividualCertificate_395e98;
LAB_00199307:
            *(code **)(param_1 + 0x208) = pcVar5;
            *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_9e2234;
            pcVar5 = spdmConvertCertificateToDer_GH100;
            if ((0xbc000000UL >> uVar2 & 1) == 0) {
              pcVar5 = spdmConvertCertificateToDer_395e98;
            }
            *(code **)(param_1 + 0x210) = pcVar5;
            return;
          }
          *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB110;
          *(code **)(param_1 + 0x208) = spdmGetIndividualCertificate_GB100;
          goto LAB_00198eb2;
        }
        pcVar4 = spdmGetBinArchiveIndividualL3Certificate_GB102;
        pcVar5 = spdmGetIndividualCertificate_395e98;
      }
      else {
        *(code **)(param_1 + 0x1f0) = spdmGetRequesterCertificateCount_GB100;
        *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_GB100;
        if (uVar3 == 0x1b) {
          *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB100;
          *(code **)(param_1 + 0x208) = spdmGetIndividualCertificate_GB100;
          goto LAB_00198eb2;
        }
LAB_00198fca:
        if (uVar3 == 0x1c) {
          pcVar4 = spdmGetBinArchiveIndividualL3Certificate_GB102;
          pcVar5 = spdmGetIndividualCertificate_GB100;
        }
        else {
          if (uVar3 != 0x1f) {
            pcVar5 = spdmGetIndividualCertificate_GB100;
            goto LAB_00199307;
          }
          pcVar4 = spdmGetBinArchiveIndividualL3Certificate_GB110;
          pcVar5 = spdmGetIndividualCertificate_GB100;
        }
      }
LAB_0019921e:
      *(code **)(param_1 + 0x200) = pcVar4;
      *(code **)(param_1 + 0x208) = pcVar5;
    }
    else {
      *(code **)(param_1 + 0x178) = spdmGetCertChains_GH100;
      pcVar5 = spdmMutualAuthSupported_d69453;
      *(code **)(param_1 + 0x180) = spdmGetAttestationReport_GH100;
      *(code **)(param_1 + 0x188) = spdmCheckAndExecuteKeyUpdate_GH100;
      *(code **)(param_1 + 400) = spdmSendInitRmDataCommand_GH100;
      *(code **)(param_1 + 0x198) = spdmRegisterForHeartbeats_GH100;
      *(code **)(param_1 + 0x1a0) = spdmUnregisterFromHeartbeats_GH100;
      if (uVar3 == 0x1a) {
        *(code **)(param_1 + 0x1a8) = spdmMutualAuthSupported_e661f0;
        *(code **)(param_1 + 0x1b0) = spdmSendCtrlCall_GH100;
        *(code **)(param_1 + 0x1b8) = spdmDeviceInit_GH100;
        *(code **)(param_1 + 0x1c0) = spdmDeviceDeinit_GH100;
        *(code **)(param_1 + 0x1c8) = spdmDeviceSecuredSessionSupported_GH100;
        *(code **)(param_1 + 0x1d0) = spdmCheckConnection_GH100;
        *(code **)(param_1 + 0x1d8) = spdmMessageProcess_GH100;
        *(code **)(param_1 + 0x1e0) = spdmGetCertificates_GH100;
        *(code **)(param_1 + 0x1e8) = spdmGetReqEncapCertificates_GH100;
      }
      else {
LAB_00198f32:
        *(code **)(param_1 + 0x1a8) = pcVar5;
        *(code **)(param_1 + 0x1b0) = spdmSendCtrlCall_GH100;
        *(code **)(param_1 + 0x1b8) = spdmDeviceInit_GH100;
        *(code **)(param_1 + 0x1c0) = spdmDeviceDeinit_GH100;
        *(code **)(param_1 + 0x1c8) = spdmDeviceSecuredSessionSupported_GH100;
        *(code **)(param_1 + 0x1d0) = spdmCheckConnection_GH100;
        *(code **)(param_1 + 0x1d8) = spdmMessageProcess_GH100;
        *(code **)(param_1 + 0x1e0) = spdmGetCertificates_GH100;
        *(code **)(param_1 + 0x1e8) = spdmGetReqEncapCertificates_GH100;
        if (uVar3 != 0x1a) {
          if ((0xb8000000UL >> uVar2 & 1) == 0) goto LAB_001992d0;
          *(code **)(param_1 + 0x1f0) = spdmGetRequesterCertificateCount_GB100;
          *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_GB100;
          if (uVar3 != 0x1b) goto LAB_00198fca;
LAB_00199210:
          pcVar4 = spdmGetBinArchiveIndividualL3Certificate_GB100;
          pcVar5 = spdmGetIndividualCertificate_GB100;
          goto LAB_0019921e;
        }
      }
      *(code **)(param_1 + 0x1f0) = spdmGetRequesterCertificateCount_GH100;
      *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_GH100;
      *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GH100;
      *(code **)(param_1 + 0x208) = spdmGetIndividualCertificate_GH100;
    }
    goto LAB_00198eb2;
  }
  if (uVar3 >> 5 != 2) {
    *(code **)(param_1 + 0x178) = spdmGetCertChains_395e98;
    *(code **)(param_1 + 0x180) = spdmGetAttestationReport_395e98;
    *(code **)(param_1 + 0x188) = spdmCheckAndExecuteKeyUpdate_395e98;
    *(code **)(param_1 + 400) = spdmSendInitRmDataCommand_395e98;
    *(code **)(param_1 + 0x198) = spdmRegisterForHeartbeats_395e98;
    *(code **)(param_1 + 0x1a0) = spdmUnregisterFromHeartbeats_395e98;
    *(code **)(param_1 + 0x1a8) = spdmMutualAuthSupported_d69453;
    *(code **)(param_1 + 0x1b0) = spdmSendCtrlCall_395e98;
    *(code **)(param_1 + 0x1b8) = spdmDeviceInit_395e98;
    *(code **)(param_1 + 0x1c0) = spdmDeviceDeinit_395e98;
    *(code **)(param_1 + 0x1c8) = spdmDeviceSecuredSessionSupported_395e98;
    *(code **)(param_1 + 0x1d0) = spdmCheckConnection_395e98;
    *(code **)(param_1 + 0x1d8) = spdmMessageProcess_395e98;
    *(code **)(param_1 + 0x1e0) = spdmGetCertificates_395e98;
    *(code **)(param_1 + 0x1e8) = spdmGetReqEncapCertificates_395e98;
    *(code **)(param_1 + 0x1f0) = spdmGetRequesterCertificateCount_395e98;
    *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_9e2234;
    *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_9e2234;
    goto LAB_00198d90;
  }
  uVar2 = uVar3 & 0x1f;
  uVar1 = 0x3f9L >> (sbyte)uVar2;
  uVar3 = uVar3 & 0x1f;
  if ((uVar1 & 1) == 0) {
    *(code **)(param_1 + 0x178) = spdmGetCertChains_395e98;
    *(code **)(param_1 + 0x180) = spdmGetAttestationReport_395e98;
    *(code **)(param_1 + 0x188) = spdmCheckAndExecuteKeyUpdate_395e98;
    *(code **)(param_1 + 400) = spdmSendInitRmDataCommand_395e98;
    *(code **)(param_1 + 0x198) = spdmRegisterForHeartbeats_395e98;
    *(code **)(param_1 + 0x1a0) = spdmUnregisterFromHeartbeats_395e98;
    *(code **)(param_1 + 0x1a8) = spdmMutualAuthSupported_d69453;
    *(code **)(param_1 + 0x1b0) = spdmSendCtrlCall_395e98;
    *(code **)(param_1 + 0x1b8) = spdmDeviceInit_395e98;
    *(code **)(param_1 + 0x1c0) = spdmDeviceDeinit_395e98;
    *(code **)(param_1 + 0x1c8) = spdmDeviceSecuredSessionSupported_395e98;
    *(code **)(param_1 + 0x1d0) = spdmCheckConnection_395e98;
    *(code **)(param_1 + 0x1d8) = spdmMessageProcess_395e98;
    *(code **)(param_1 + 0x1e0) = spdmGetCertificates_395e98;
    *(code **)(param_1 + 0x1e8) = spdmGetReqEncapCertificates_395e98;
    *(code **)(param_1 + 0x1f0) = spdmGetRequesterCertificateCount_395e98;
    if ((0x3f8UL >> uVar2 & 1) == 0) goto LAB_001991af;
LAB_00198e88:
    *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_GB20X;
    if (uVar3 == 0) {
      *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB112;
    }
    else {
LAB_001991c3:
      if (uVar3 == 3) {
        *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB202;
      }
      else if (uVar3 == 4) {
        *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB203;
      }
      else if (uVar3 == 5) {
        *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB205;
      }
      else if (uVar3 == 6) {
        *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB206;
      }
      else if (uVar3 == 7) {
        *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB207;
      }
      else {
        *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_9e2234;
        if ((uVar1 & 1) == 0) {
LAB_00198d90:
          *(code **)(param_1 + 0x208) = spdmGetIndividualCertificate_395e98;
          *(code **)(param_1 + 0x210) = spdmConvertCertificateToDer_395e98;
          return;
        }
      }
    }
  }
  else {
    *(code **)(param_1 + 0x178) = spdmGetCertChains_GH100;
    *(code **)(param_1 + 0x180) = spdmGetAttestationReport_GH100;
    *(code **)(param_1 + 0x188) = spdmCheckAndExecuteKeyUpdate_GH100;
    *(code **)(param_1 + 400) = spdmSendInitRmDataCommand_GH100;
    *(code **)(param_1 + 0x198) = spdmRegisterForHeartbeats_GH100;
    *(code **)(param_1 + 0x1a0) = spdmUnregisterFromHeartbeats_GH100;
    *(code **)(param_1 + 0x1a8) = spdmMutualAuthSupported_d69453;
    *(code **)(param_1 + 0x1b0) = spdmSendCtrlCall_GH100;
    *(code **)(param_1 + 0x1b8) = spdmDeviceInit_GH100;
    *(code **)(param_1 + 0x1c0) = spdmDeviceDeinit_GH100;
    *(code **)(param_1 + 0x1c8) = spdmDeviceSecuredSessionSupported_GH100;
    *(code **)(param_1 + 0x1d0) = spdmCheckConnection_GH100;
    *(code **)(param_1 + 0x1d8) = spdmMessageProcess_GH100;
    *(code **)(param_1 + 0x1e0) = spdmGetCertificates_GH100;
    *(code **)(param_1 + 0x1e8) = spdmGetReqEncapCertificates_GH100;
    *(code **)(param_1 + 0x1f0) = spdmGetRequesterCertificateCount_GB100;
    if ((0x3f8UL >> uVar2 & 1) != 0) goto LAB_00198e88;
LAB_001991af:
    if (uVar3 != 0) {
      *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_9e2234;
      goto LAB_001991c3;
    }
    *(code **)(param_1 + 0x1f8) = spdmGetBinArchiveIndividualL2Certificate_GB100;
    *(code **)(param_1 + 0x200) = spdmGetBinArchiveIndividualL3Certificate_GB112;
  }
  *(code **)(param_1 + 0x208) = spdmGetIndividualCertificate_GB100;
LAB_00198eb2:
  *(code **)(param_1 + 0x210) = spdmConvertCertificateToDer_GH100;
  return;
}


// ===== 00199430 __nvoc_dtor_Spdm =====

void __nvoc_dtor_Spdm(long param_1)

{
  spdmDestruct_IMPL();
  __nvoc_dtor_OBJENGSTATE(param_1 + 8);
  return;
}


// ===== 00199460 spdmStatePreUnload_ac1694 =====

undefined8 spdmStatePreUnload_ac1694(void)

{
  return 0;
}


// ===== 00199470 spdmRegisterForHeartbeats_395e98 =====

undefined8 spdmRegisterForHeartbeats_395e98(void)

{
  return 0x56;
}


// ===== 00199480 spdmGetRequesterCertificateCount_395e98 =====

undefined8 spdmGetRequesterCertificateCount_395e98(void)

{
  return 0x56;
}


// ===== 00199490 spdmUnregisterFromHeartbeats_395e98 =====

undefined8 spdmUnregisterFromHeartbeats_395e98(void)

{
  return 0x56;
}


// ===== 001994a0 spdmDeviceInit_395e98 =====

undefined8 spdmDeviceInit_395e98(void)

{
  return 0x56;
}


// ===== 001994b0 spdmDeviceSecuredSessionSupported_395e98 =====

undefined8 spdmDeviceSecuredSessionSupported_395e98(void)

{
  return 0x56;
}


// ===== 001994c0 spdmCheckConnection_395e98 =====

undefined8 spdmCheckConnection_395e98(void)

{
  return 0x56;
}


// ===== 001994d0 spdmGetCertificates_395e98 =====

undefined8 spdmGetCertificates_395e98(void)

{
  return 0x56;
}


// ===== 001994e0 spdmGetBinArchiveIndividualL3Certificate_9e2234 =====

undefined8 spdmGetBinArchiveIndividualL3Certificate_9e2234(void)

{
  return 0;
}


// ===== 001994f0 __nvoc_objCreate_Spdm =====

int __nvoc_objCreate_Spdm(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 uVar7;
  
  if ((param_3 & 2) == 0) {
    puVar5 = (undefined8 *)portMemAllocNonPaged(0x2c8);
    if (puVar5 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_spdm_nvoc.c",0x273);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar5 = (undefined8 *)*param_1, puVar5 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL","generated/g_spdm_nvoc.c"
                       ,0x26b);
    return 0x3b;
  }
  portMemSet(puVar5,0,0x2c8);
  *(uint *)((long)puVar5 + 0x3c) = param_3;
  if (param_2 == 0) {
    iVar2 = 0x1f;
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_spdm_nvoc.c",0x27c);
    goto LAB_00199617;
  }
  if ((param_3 & 1) == 0) {
    lVar6 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar6,puVar5 + 2);
  }
  else {
    puVar5[4] = 0;
    lVar6 = 0;
  }
  lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmHalspecOwner);
  if (lVar3 == 0) {
    lVar3 = objFindAncestor_IMPL(param_2,0x34a6d6);
    uVar7 = 0;
    if (lVar3 != 0) {
      uVar7 = objFindAncestor_IMPL(param_2,0x34a6d6);
    }
    lVar3 = __nvoc_dynamicCast(uVar7,__nvoc_class_def_RmHalspecOwner);
    if (lVar3 != 0) goto LAB_00199586;
    nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_spdm_nvoc.c",0x28c);
LAB_0019973d:
    iVar2 = 0x1f;
  }
  else {
LAB_00199586:
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_GpuHalspecOwner);
    if (lVar4 == 0) {
      lVar4 = objFindAncestor_IMPL(param_2,0x74bc71);
      uVar7 = 0;
      if (lVar4 != 0) {
        uVar7 = objFindAncestor_IMPL(param_2,0x74bc71);
      }
      lVar4 = __nvoc_dynamicCast(uVar7,__nvoc_class_def_GpuHalspecOwner);
      if (lVar4 == 0) {
        nvCheckOkFailedNoLog(4,0x1f,"pGpuhalspecowner != NULL","generated/g_spdm_nvoc.c",0x28f);
        goto LAB_0019973d;
      }
    }
    puVar1 = puVar5 + 1;
    puVar5[0x2c] = puVar5;
    puVar5[0x2a] = puVar5 + 2;
    puVar5[0x2b] = puVar1;
    __nvoc_init__OBJENGSTATE(puVar1);
    puVar5[2] = 0xc65390;
    puVar5[1] = 0xc65378;
    *puVar5 = __nvoc_metadata__Spdm;
    __nvoc_init_funcTable_Spdm_1(puVar5,lVar3,lVar4);
    iVar2 = __nvoc_ctor_OBJENGSTATE(puVar1);
    if (iVar2 == 0) {
      *(undefined1 *)(puVar5 + 0x43) = 0;
      *param_1 = (long)puVar5;
      return 0;
    }
  }
  if (lVar6 != 0) {
    objRemoveChild_IMPL(lVar6,puVar5 + 2);
  }
LAB_00199617:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar5);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar5,0,0x2c8);
  }
  return iVar2;
}


// ===== 00199820 __nvoc_objCreateDynamic_Spdm =====

void __nvoc_objCreateDynamic_Spdm(void)

{
  __nvoc_objCreate_Spdm();
  return;
}


// ===== 00199830 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00199840 memCheckMemInterUnmap_ac1694 =====

undefined8 memCheckMemInterUnmap_ac1694(void)

{
  return 0;
}


// ===== 00199850 memCheckCopyPermissions_ac1694 =====

undefined8 memCheckCopyPermissions_ac1694(void)

{
  return 0;
}


// ===== 00199860 memIsGpuMapAllowed_e661f0 =====

undefined8 memIsGpuMapAllowed_e661f0(void)

{
  return 1;
}


// ===== 00199870 memIsExportAllowed_e661f0 =====

undefined8 memIsExportAllowed_e661f0(void)

{
  return 1;
}


// ===== 00199880 __nvoc_down_thunk_StandardMemory_resCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_StandardMemory_resCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x18) + 0x298))(param_1 + -0x18);
  return;
}


// ===== 001998a0 __nvoc_up_thunk_Memory_stdmemIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 001998c0 __nvoc_up_thunk_Memory_stdmemGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 001998e0 __nvoc_up_thunk_Memory_stdmemControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 00199900 __nvoc_up_thunk_Memory_stdmemMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 00199920 __nvoc_up_thunk_Memory_stdmemUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 00199940 __nvoc_up_thunk_Memory_stdmemGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 00199960 __nvoc_up_thunk_Memory_stdmemCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8,param_2);
  return;
}


// ===== 00199980 __nvoc_up_thunk_Memory_stdmemGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 001999a0 __nvoc_up_thunk_Memory_stdmemCheckCopyPermissions =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemCheckCopyPermissions(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1f0))(param_1 + 8);
  return;
}


// ===== 001999c0 __nvoc_up_thunk_Memory_stdmemIsReady =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemIsReady(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1f8))(param_1 + 8,param_2);
  return;
}


// ===== 001999e0 __nvoc_up_thunk_Memory_stdmemIsGpuMapAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemIsGpuMapAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x200))(param_1 + 8);
  return;
}


// ===== 00199a00 __nvoc_up_thunk_Memory_stdmemIsExportAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_stdmemIsExportAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x208))(param_1 + 8);
  return;
}


// ===== 00199a20 __nvoc_up_thunk_RmResource_stdmemAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_stdmemAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 00199a40 __nvoc_up_thunk_RmResource_stdmemShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_stdmemShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf8))(param_1 + 0x10);
  return;
}


// ===== 00199a60 __nvoc_up_thunk_RmResource_stdmemControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_stdmemControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 00199a80 __nvoc_up_thunk_RmResource_stdmemControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_stdmemControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 00199aa0 __nvoc_up_thunk_RmResource_stdmemControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_stdmemControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 00199ac0 __nvoc_up_thunk_RmResource_stdmemControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_stdmemControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 00199ae0 __nvoc_up_thunk_RsResource_stdmemPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_stdmemPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 00199b00 __nvoc_up_thunk_RsResource_stdmemControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_stdmemControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 00199b20 __nvoc_up_thunk_RsResource_stdmemIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_stdmemIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 00199b40 __nvoc_up_thunk_RsResource_stdmemMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_stdmemMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 00199b60 __nvoc_up_thunk_RsResource_stdmemUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_stdmemUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 00199b80 __nvoc_up_thunk_RsResource_stdmemGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_stdmemGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 00199ba0 __nvoc_up_thunk_RsResource_stdmemAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_stdmemAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 00199bc0 __nvoc_dtor_StandardMemory =====

void __nvoc_dtor_StandardMemory(long param_1)

{
  __nvoc_dtor_Memory(param_1 + 8);
  return;
}


// ===== 00199bd0 __nvoc_ctor_StandardMemory =====

ulong __nvoc_ctor_StandardMemory(long param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  
  uVar1 = __nvoc_ctor_Memory(param_1 + 8);
  if ((int)uVar1 == 0) {
    uVar1 = stdmemConstruct_IMPL(param_1,param_2,param_3);
    if ((int)uVar1 != 0) {
      __nvoc_dtor_Memory(param_1 + 8);
      return uVar1 & 0xffffffff;
    }
  }
  return uVar1;
}


// ===== 00199c40 __nvoc_init__StandardMemory =====

void __nvoc_init__StandardMemory(undefined8 *param_1)

{
  param_1[0x3e] = param_1 + 4;
  param_1[0x3f] = param_1 + 3;
  param_1[0x40] = param_1 + 0x10;
  param_1[0x41] = param_1 + 2;
  param_1[0x42] = param_1 + 1;
  param_1[0x43] = param_1;
  __nvoc_init__Memory();
  param_1[4] = 0xc655e0;
  param_1[3] = 0xc655c8;
  param_1[0x10] = 0xc65688;
  param_1[2] = 0xc655b0;
  param_1[1] = 0xc65598;
  *param_1 = __nvoc_metadata__StandardMemory;
  return;
}


// ===== 00199cd0 __nvoc_objCreate_StandardMemory =====

int __nvoc_objCreate_StandardMemory
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x220);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_standard_mem_nvoc.c",0x1e9);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_standard_mem_nvoc.c",0x1e1);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x220);
  puVar1 = puVar4 + 4;
  *(uint *)((long)puVar4 + 0x4c) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[6] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x3e] = puVar1;
  puVar4[0x3f] = puVar4 + 3;
  puVar4[0x40] = puVar4 + 0x10;
  puVar4[0x41] = puVar4 + 2;
  puVar4[0x42] = puVar2;
  puVar4[0x43] = puVar4;
  __nvoc_init__Memory(puVar2);
  puVar4[4] = 0xc655e0;
  puVar4[3] = 0xc655c8;
  puVar4[0x10] = 0xc65688;
  puVar4[2] = 0xc655b0;
  puVar4[1] = 0xc65598;
  *puVar4 = __nvoc_metadata__StandardMemory;
  iVar3 = __nvoc_ctor_Memory(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = stdmemConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_Memory(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x220);
  }
  return iVar3;
}


// ===== 00199f50 __nvoc_objCreateDynamic_StandardMemory =====

void __nvoc_objCreateDynamic_StandardMemory
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_00199f7e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_00199f7e:
  __nvoc_objCreate_StandardMemory(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 00199fb0 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 00199fc0 diagapiCtrlCmdFifoGetChannelState_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void diagapiCtrlCmdFifoGetChannelState_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x178))();
  return;
}


// ===== 00199fd0 diagapiCtrlCmdFifoGetChannelState_395e98 =====

undefined8 diagapiCtrlCmdFifoGetChannelState_395e98(void)

{
  return 0x56;
}


// ===== 00199fe0 __nvoc_down_thunk_DiagApi_gpuresControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_DiagApi_gpuresControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x310))(param_1 + -8);
  return;
}


// ===== 0019a000 __nvoc_down_thunk_DiagApi_resControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_DiagApi_resControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x18) + 0x318))(param_1 + -0x18);
  return;
}


// ===== 0019a020 __nvoc_up_thunk_GpuResource_diagapiMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_diagapiMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 0019a040 __nvoc_up_thunk_GpuResource_diagapiUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_diagapiUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 0019a060 __nvoc_up_thunk_GpuResource_diagapiShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_diagapiShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 0019a080 __nvoc_up_thunk_GpuResource_diagapiGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_diagapiGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 0019a0a0 __nvoc_up_thunk_GpuResource_diagapiGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_diagapiGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 0019a0c0 __nvoc_up_thunk_GpuResource_diagapiInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_diagapiInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8);
  return;
}


// ===== 0019a0e0 __nvoc_up_thunk_GpuResource_diagapiGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_diagapiGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 0019a100 __nvoc_up_thunk_RmResource_diagapiAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 0019a120 __nvoc_up_thunk_RmResource_diagapiGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 0019a140 __nvoc_up_thunk_RmResource_diagapiCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 0019a160 __nvoc_up_thunk_RmResource_diagapiGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 0019a180 __nvoc_up_thunk_RmResource_diagapiControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 0019a1a0 __nvoc_up_thunk_RmResource_diagapiControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 0019a1c0 __nvoc_up_thunk_RmResource_diagapiControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 0019a1e0 __nvoc_up_thunk_RmResource_diagapiControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_diagapiControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 0019a200 __nvoc_up_thunk_RsResource_diagapiCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 0019a220 __nvoc_up_thunk_RsResource_diagapiIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 0019a240 __nvoc_up_thunk_RsResource_diagapiPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 0019a260 __nvoc_up_thunk_RsResource_diagapiIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 0019a280 __nvoc_up_thunk_RsResource_diagapiMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 0019a2a0 __nvoc_up_thunk_RsResource_diagapiUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 0019a2c0 __nvoc_up_thunk_RsResource_diagapiGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 0019a2e0 __nvoc_up_thunk_RsResource_diagapiAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_diagapiAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 0019a300 __nvoc_up_thunk_Notifier_diagapiGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_diagapiGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x58))(param_1 + 0x108);
  return;
}


// ===== 0019a320 __nvoc_up_thunk_Notifier_diagapiGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_diagapiGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x60))(param_1 + 0x108);
  return;
}


// ===== 0019a340 __nvoc_up_thunk_Notifier_diagapiSetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_diagapiSetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x68))(param_1 + 0x108);
  return;
}


// ===== 0019a360 __nvoc_up_thunk_Notifier_diagapiUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_diagapiUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x70))(param_1 + 0x108);
  return;
}


// ===== 0019a380 __nvoc_up_thunk_Notifier_diagapiGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_diagapiGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x78))(param_1 + 0x108);
  return;
}


// ===== 0019a3a0 __nvoc_dtor_DiagApi =====

void __nvoc_dtor_DiagApi(long param_1)

{
  __nvoc_dtor_GpuResource(param_1 + 8);
  __nvoc_dtor_Notifier(param_1 + 0x108);
  return;
}


// ===== 0019a3d0 __nvoc_ctor_DiagApi =====

ulong __nvoc_ctor_DiagApi(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = __nvoc_ctor_GpuResource(param_1 + 8,param_3,param_4);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar1 = __nvoc_ctor_Notifier(param_1 + 0x108,param_3);
  if (uVar1 == 0) {
    uVar2 = diagapiConstruct_IMPL(param_1,param_3,param_4);
    uVar1 = (uint)uVar2;
    if (uVar1 == 0) {
      return uVar2;
    }
    __nvoc_dtor_Notifier(param_1 + 0x108);
  }
  __nvoc_dtor_GpuResource(param_1 + 8);
  return (ulong)uVar1;
}


// ===== 0019a470 __nvoc_init__DiagApi =====

void __nvoc_init__DiagApi(undefined8 *param_1,long param_2)

{
  code *pcVar1;
  
  param_1[0x27] = param_1 + 4;
  param_1[0x28] = param_1 + 3;
  param_1[0x29] = param_1 + 0x10;
  param_1[0x2a] = param_1 + 2;
  param_1[0x2c] = param_1 + 0x22;
  param_1[0x2b] = param_1 + 1;
  param_1[0x2d] = param_1 + 0x21;
  param_1[0x2e] = param_1;
  __nvoc_init__GpuResource();
  __nvoc_init__Notifier(param_1 + 0x21);
  param_1[4] = 0xc65aa0;
  pcVar1 = diagapiCtrlCmdFifoGetChannelState_IMPL;
  param_1[3] = 0xc65a88;
  param_1[0x10] = 0xc65b48;
  param_1[2] = 0xc65a70;
  param_1[1] = 0xc65a58;
  param_1[0x22] = 0xc65ce8;
  param_1[0x21] = 0xc65cd0;
  *param_1 = __nvoc_metadata__DiagApi;
  if (*(short *)(param_2 + 0x10) == 0) {
    pcVar1 = diagapiCtrlCmdFifoGetChannelState_395e98;
  }
  param_1[0x2f] = pcVar1;
  return;
}


// ===== 0019a570 __nvoc_objCreate_DiagApi =====

int __nvoc_objCreate_DiagApi
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  if ((param_3 & 2) == 0) {
    lVar4 = portMemAllocNonPaged(0x180);
    if (lVar4 == 0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_subdevice_diag_nvoc.c",0x368);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) || (lVar4 = *param_1, lVar4 == 0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_subdevice_diag_nvoc.c",0x360);
    return 0x3b;
  }
  portMemSet(lVar4,0,0x180);
  *(uint *)(lVar4 + 0x4c) = param_3;
  if (param_2 == 0) {
    iVar1 = 0x1f;
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_subdevice_diag_nvoc.c",0x371);
    goto LAB_0019a6b1;
  }
  if ((param_3 & 1) == 0) {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,lVar4 + 0x20);
  }
  else {
    *(undefined8 *)(lVar4 + 0x30) = 0;
    lVar5 = 0;
  }
  lVar2 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmHalspecOwner);
  if (lVar2 == 0) {
    lVar2 = objFindAncestor_IMPL(param_2,0x34a6d6);
    uVar3 = 0;
    if (lVar2 != 0) {
      uVar3 = objFindAncestor_IMPL(param_2,0x34a6d6);
    }
    lVar2 = __nvoc_dynamicCast(uVar3,__nvoc_class_def_RmHalspecOwner);
    if (lVar2 != 0) goto LAB_0019a600;
    iVar1 = 0x1f;
    nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_subdevice_diag_nvoc.c",0x381)
    ;
  }
  else {
LAB_0019a600:
    __nvoc_init__DiagApi(lVar4);
    iVar1 = __nvoc_ctor_DiagApi(lVar4,lVar2,param_4,param_5);
    if (iVar1 == 0) {
      *param_1 = lVar4;
      return 0;
    }
  }
  if (lVar5 != 0) {
    objRemoveChild_IMPL(lVar5,lVar4 + 0x20);
  }
LAB_0019a6b1:
  if ((param_3 & 2) == 0) {
    portMemFree(lVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(lVar4,0,0x180);
  }
  return iVar1;
}


// ===== 0019a7b0 __nvoc_objCreateDynamic_DiagApi =====

void __nvoc_objCreateDynamic_DiagApi
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0019a7de;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0019a7de:
  __nvoc_objCreate_DiagApi(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019a810 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019a820 subdeviceCtrlCmdBiosGetInfoV2_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBiosGetInfoV2_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x178))();
  return;
}


// ===== 0019a830 subdeviceCtrlCmdBiosGetSKUInfo_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBiosGetSKUInfo_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x180))();
  return;
}


// ===== 0019a840 subdeviceCtrlCmdBiosGetPostTime_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBiosGetPostTime_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x188))();
  return;
}


// ===== 0019a850 subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 400))();
  return;
}


// ===== 0019a860 subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x198))();
  return;
}


// ===== 0019a870 subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1a0))();
  return;
}


// ===== 0019a880 subdeviceCtrlCmdBusGetC2CInfo_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusGetC2CInfo_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1a8))();
  return;
}


// ===== 0019a890 subdeviceCtrlCmdBusGetC2CLpwrStats_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusGetC2CLpwrStats_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1b0))();
  return;
}


// ===== 0019a8a0 subdeviceCtrlCmdBusSetC2CLpwrStateVote_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusSetC2CLpwrStateVote_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1b8))();
  return;
}


// ===== 0019a8b0 subdeviceCtrlCmdBusSetC2CIdleThreshold_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusSetC2CIdleThreshold_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1c0))();
  return;
}


// ===== 0019a8c0 subdeviceCtrlCmdBusSetP2pMapping_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusSetP2pMapping_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1c8))();
  return;
}


// ===== 0019a8d0 subdeviceCtrlCmdBusUnsetP2pMapping_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusUnsetP2pMapping_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1d0))();
  return;
}


// ===== 0019a8e0 subdeviceCtrlCmdBusGetNvlinkCaps_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBusGetNvlinkCaps_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1d8))();
  return;
}


// ===== 0019a8f0 subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1e0))();
  return;
}


// ===== 0019a900 subdeviceCtrlCmdPerfReservePerfmonHw_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdPerfReservePerfmonHw_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1e8))();
  return;
}


// ===== 0019a910 subdeviceCtrlCmdPerfGetLevelInfo_V2_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdPerfGetLevelInfo_V2_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1f0))();
  return;
}


// ===== 0019a920 subdeviceCtrlCmdPerfGetCurrentPstate_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdPerfGetCurrentPstate_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x1f8))();
  return;
}


// ===== 0019a930 subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x200))();
  return;
}


// ===== 0019a940 subdeviceCtrlCmdPerfGetPowerstate_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdPerfGetPowerstate_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x208))();
  return;
}


// ===== 0019a950 subdeviceCtrlCmdPerfNotifyVideoevent_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdPerfNotifyVideoevent_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x210))();
  return;
}


// ===== 0019a960 subdeviceCtrlCmdFbGetOfflinedPages_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFbGetOfflinedPages_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x218))();
  return;
}


// ===== 0019a970 subdeviceCtrlCmdFbGetLTCInfoForFBP_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFbGetLTCInfoForFBP_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x220))();
  return;
}


// ===== 0019a980 subdeviceCtrlCmdFbGetDynamicOfflinedPages_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFbGetDynamicOfflinedPages_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x228))();
  return;
}


// ===== 0019a990 subdeviceCtrlCmdMemSysGetStaticConfig_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdMemSysGetStaticConfig_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x230))();
  return;
}


// ===== 0019a9a0 subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x240))();
  return;
}


// ===== 0019a9b0 subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x248))();
  return;
}


// ===== 0019a9c0 subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x250))();
  return;
}


// ===== 0019a9d0 subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 600))();
  return;
}


// ===== 0019a9e0 subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x260))();
  return;
}


// ===== 0019a9f0 subdeviceCtrlCmdFifoRotateKeys_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoRotateKeys_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x268))();
  return;
}


// ===== 0019aa00 subdeviceCtrlCmdFifoDisableUsermodeChannels_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoDisableUsermodeChannels_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x270))();
  return;
}


// ===== 0019aa10 subdeviceCtrlCmdFifoGetUserdLocation_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoGetUserdLocation_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x278))();
  return;
}


// ===== 0019aa20 subdeviceCtrlCmdFifoObjschedGetCaps_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoObjschedGetCaps_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x280))();
  return;
}


// ===== 0019aa30 subdeviceCtrlCmdFifoGetDeviceInfoTable_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoGetDeviceInfoTable_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x290))();
  return;
}


// ===== 0019aa40 subdeviceCtrlCmdFifoUpdateChannelInfo_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdFifoUpdateChannelInfo_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x298))();
  return;
}


// ===== 0019aa50 subdeviceCtrlCmdKGrCtxswPmMode_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdKGrCtxswPmMode_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2a0))();
  return;
}


// ===== 0019aa60 subdeviceCtrlCmdGpuQueryEccStatus_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGpuQueryEccStatus_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2a8))();
  return;
}


// ===== 0019aa70 subdeviceCtrlCmdGpuQueryIllumSupport_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGpuQueryIllumSupport_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2b0))();
  return;
}


// ===== 0019aa80 subdeviceCtrlCmdGpuQueryScrubberStatus_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGpuQueryScrubberStatus_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2b8))();
  return;
}


// ===== 0019aa90 subdeviceCtrlCmdGetP2pCaps_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGetP2pCaps_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2c0))();
  return;
}


// ===== 0019aaa0 subdeviceCtrlCmdSetRcRecovery_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdSetRcRecovery_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2c8))();
  return;
}


// ===== 0019aab0 subdeviceCtrlCmdGetRcRecovery_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGetRcRecovery_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2d0))();
  return;
}


// ===== 0019aac0 subdeviceCtrlCmdCeGetCaps_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdCeGetCaps_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2d8))();
  return;
}


// ===== 0019aad0 subdeviceCtrlCmdCeGetCapsV2_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdCeGetCapsV2_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2e0))();
  return;
}


// ===== 0019aae0 subdeviceCtrlCmdCeGetAllCaps_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdCeGetAllCaps_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2e8))();
  return;
}


// ===== 0019aaf0 subdeviceCtrlCmdGpuQueryEccConfiguration_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGpuQueryEccConfiguration_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2f0))();
  return;
}


// ===== 0019ab00 subdeviceCtrlCmdGpuSetEccConfiguration_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGpuSetEccConfiguration_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x2f8))();
  return;
}


// ===== 0019ab10 subdeviceCtrlCmdGpuResetEccErrorStatus_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGpuResetEccErrorStatus_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x300))();
  return;
}


// ===== 0019ab20 subdeviceCtrlCmdGspGetFeatures_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdGspGetFeatures_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x308))();
  return;
}


// ===== 0019ab30 subdeviceCtrlCmdBifGetStaticInfo_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdBifGetStaticInfo_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x310))();
  return;
}


// ===== 0019ab40 subdeviceCtrlCmdCcuGetSampleInfo_DISPATCH =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void subdeviceCtrlCmdCcuGetSampleInfo_DISPATCH(long param_1)

{
  (**(code **)(param_1 + 0x328))();
  return;
}


// ===== 0019ab50 subdeviceCtrlCmdPerfReservePerfmonHw_395e98 =====

undefined8 subdeviceCtrlCmdPerfReservePerfmonHw_395e98(void)

{
  return 0x56;
}


// ===== 0019ab60 subdeviceCtrlCmdPerfNotifyVideoevent_ac1694 =====

undefined8 subdeviceCtrlCmdPerfNotifyVideoevent_ac1694(void)

{
  return 0;
}


// ===== 0019ab70 __nvoc_down_thunk_Subdevice_resPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Subdevice_resPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x18) + 0x310))(param_1 + -0x18);
  return;
}


// ===== 0019ab90 __nvoc_down_thunk_Subdevice_gpuresInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_Subdevice_gpuresInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x318))(param_1 + -8);
  return;
}


// ===== 0019abb0 __nvoc_up_thunk_GpuResource_subdeviceControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_subdeviceControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 0019abd0 __nvoc_up_thunk_GpuResource_subdeviceMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_subdeviceMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 0019abf0 __nvoc_up_thunk_GpuResource_subdeviceUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_subdeviceUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 0019ac10 __nvoc_up_thunk_GpuResource_subdeviceShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_subdeviceShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 0019ac30 __nvoc_up_thunk_GpuResource_subdeviceGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_subdeviceGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 0019ac50 __nvoc_up_thunk_GpuResource_subdeviceGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_subdeviceGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 0019ac70 __nvoc_up_thunk_GpuResource_subdeviceGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_subdeviceGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 0019ac90 __nvoc_up_thunk_RmResource_subdeviceAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 0019acb0 __nvoc_up_thunk_RmResource_subdeviceGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x100))(param_1 + 0x10);
  return;
}


// ===== 0019acd0 __nvoc_up_thunk_RmResource_subdeviceCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x108))(param_1 + 0x10,param_2);
  return;
}


// ===== 0019acf0 __nvoc_up_thunk_RmResource_subdeviceGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x110))(param_1 + 0x10);
  return;
}


// ===== 0019ad10 __nvoc_up_thunk_RmResource_subdeviceControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 0019ad30 __nvoc_up_thunk_RmResource_subdeviceControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 0019ad50 __nvoc_up_thunk_RmResource_subdeviceControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 0019ad70 __nvoc_up_thunk_RmResource_subdeviceControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_subdeviceControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 0019ad90 __nvoc_up_thunk_RsResource_subdeviceCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x30))(param_1 + 0x18);
  return;
}


// ===== 0019adb0 __nvoc_up_thunk_RsResource_subdeviceIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x38))(param_1 + 0x18);
  return;
}


// ===== 0019add0 __nvoc_up_thunk_RsResource_subdeviceControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 0019adf0 __nvoc_up_thunk_RsResource_subdeviceIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 0019ae10 __nvoc_up_thunk_RsResource_subdeviceMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 0019ae30 __nvoc_up_thunk_RsResource_subdeviceUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 0019ae50 __nvoc_up_thunk_RsResource_subdeviceGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 0019ae70 __nvoc_up_thunk_RsResource_subdeviceAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_subdeviceAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 0019ae90 __nvoc_up_thunk_Notifier_subdeviceGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_subdeviceGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x58))(param_1 + 0x108);
  return;
}


// ===== 0019aeb0 __nvoc_up_thunk_Notifier_subdeviceGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_subdeviceGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x60))(param_1 + 0x108);
  return;
}


// ===== 0019aed0 __nvoc_up_thunk_Notifier_subdeviceSetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_subdeviceSetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x68))(param_1 + 0x108);
  return;
}


// ===== 0019aef0 __nvoc_up_thunk_Notifier_subdeviceUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_subdeviceUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x70))(param_1 + 0x108);
  return;
}


// ===== 0019af10 __nvoc_up_thunk_Notifier_subdeviceGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_subdeviceGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x108) + 0x78))(param_1 + 0x108);
  return;
}


// ===== 0019af30 __nvoc_init_funcTable_Subdevice_1 =====

void __nvoc_init_funcTable_Subdevice_1(long param_1,long param_2,long param_3)

{
  ushort uVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  code *pcVar5;
  code *pcVar6;
  code *pcVar7;
  code *pcVar8;
  code *pcVar9;
  code *pcVar10;
  code *pcVar11;
  code *pcVar12;
  code *pcVar13;
  code *pcVar14;
  code *local_180;
  code *local_178;
  code *local_170;
  code *local_168;
  code *local_160;
  code *local_158;
  code *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  code *local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  code *local_60;
  code *local_58;
  code *local_50;
  code *local_48;
  code *local_40;
  code *local_38;
  
  uVar1 = *(ushort *)(param_3 + 0x10);
  if (*(short *)(param_2 + 0x10) == 0) {
    if ((uVar1 >> 5 == 1) && ((0x3e0UL >> (uVar1 & 0x1f) & 1) != 0)) {
      local_168 = subdeviceCtrlCmdFifoGetUserdLocation_IMPL;
    }
    else {
      local_168 = subdeviceCtrlCmdFifoGetUserdLocation_395e98;
    }
    local_38 = subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_395e98;
    local_40 = subdeviceCtrlCmdBiosGetSKUInfo_VF;
    local_48 = subdeviceCtrlCmdBiosGetPostTime_VF;
    local_50 = subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_VF;
    local_58 = subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_VF;
    local_60 = subdeviceCtrlCmdBusSetC2CIdleThreshold_VF;
    local_68 = subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_395e98;
    local_70 = subdeviceCtrlCmdFifoRotateKeys_395e98;
    local_78 = subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_VF;
    local_80 = subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_VF;
    local_88 = subdeviceCtrlCmdMemSysGetMIGMemoryPartitionTable_395e98;
    local_90 = subdeviceCtrlCmdMemSysGetStaticConfig_VF;
    local_98 = subdeviceCtrlCmdFbGetDynamicOfflinedPages_VF;
    local_a0 = subdeviceCtrlCmdFbGetLTCInfoForFBP_VF;
    local_a8 = subdeviceCtrlCmdFbGetOfflinedPages_VF;
    local_b0 = subdeviceCtrlCmdPerfNotifyVideoevent_ac1694;
    local_b8 = subdeviceCtrlCmdPerfGetPowerstate_VF;
    local_c0 = subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_VF;
    local_c8 = subdeviceCtrlCmdPerfGetCurrentPstate_VF;
    local_d0 = subdeviceCtrlCmdPerfGetLevelInfo_V2_VF;
    local_d8 = subdeviceCtrlCmdPerfReservePerfmonHw_395e98;
    local_e0 = subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_VF;
    local_e8 = subdeviceCtrlCmdBusGetNvlinkCaps_VF;
    local_f0 = subdeviceCtrlCmdBusUnsetP2pMapping_VF;
    local_f8 = subdeviceCtrlCmdBusSetP2pMapping_VF;
    local_100 = subdeviceCtrlCmdBusGetC2CInfo_VF;
    local_108 = subdeviceCtrlCmdBusGetC2CLpwrStats_VF;
    local_110 = subdeviceCtrlCmdBusSetC2CLpwrStateVote_VF;
    local_160 = subdeviceCtrlCmdFifoDisableUsermodeChannels_ac1694;
    local_170 = subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_VF;
    local_178 = subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_VF;
    pcVar2 = subdeviceCtrlCmdBiosGetInfoV2_VF;
    local_118 = subdeviceCtrlCmdFifoObjschedGetCaps_ac1694;
    pcVar14 = subdeviceCtrlCmdSetRcRecovery_ac1694;
    pcVar13 = subdeviceCtrlCmdGetRcRecovery_VF;
    pcVar12 = subdeviceCtrlCmdCeGetCaps_VF;
    local_120 = subdeviceCtrlCmdFifoConfigCtxswTimeout_ac1694;
    pcVar11 = subdeviceCtrlCmdCeGetCapsV2_VF;
    pcVar5 = subdeviceCtrlCmdCeGetAllCaps_VF;
    pcVar10 = subdeviceCtrlCmdGpuQueryEccConfiguration_VF;
    local_128 = subdeviceCtrlCmdFifoGetDeviceInfoTable_VF;
    pcVar9 = subdeviceCtrlCmdGpuSetEccConfiguration_VF;
    pcVar8 = subdeviceCtrlCmdGpuResetEccErrorStatus_VF;
    pcVar7 = subdeviceCtrlCmdGspGetFeatures_KERNEL;
    local_130 = subdeviceCtrlCmdFifoUpdateChannelInfo_395e98;
    pcVar6 = subdeviceCtrlCmdBifGetStaticInfo_VF;
    pcVar3 = subdeviceCtrlCmdInternalGetLocalAtsConfig_395e98;
    pcVar4 = subdeviceCtrlCmdInternalSetPeerAtsConfig_395e98;
    local_138 = subdeviceCtrlCmdKGrCtxswPmMode_395e98;
    local_140 = subdeviceCtrlCmdGpuQueryEccStatus_VF;
    local_148 = subdeviceCtrlCmdGpuQueryIllumSupport_VF;
    local_150 = subdeviceCtrlCmdGpuQueryScrubberStatus_VF;
    local_158 = subdeviceCtrlCmdGetP2pCaps_VF;
    local_180 = subdeviceCtrlCmdCcuGetSampleInfo_VF;
  }
  else {
    if ((uVar1 >> 5 == 1) && ((0x3e0UL >> (uVar1 & 0x1f) & 1) != 0)) {
      local_168 = subdeviceCtrlCmdFifoGetUserdLocation_IMPL;
    }
    else {
      local_168 = subdeviceCtrlCmdFifoGetUserdLocation_395e98;
    }
    local_38 = subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_IMPL;
    local_40 = subdeviceCtrlCmdBiosGetSKUInfo_KERNEL;
    local_48 = subdeviceCtrlCmdBiosGetPostTime_92bfc3;
    local_50 = subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_92bfc3;
    local_58 = subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_92bfc3;
    local_60 = subdeviceCtrlCmdBusSetC2CIdleThreshold_92bfc3;
    local_68 = subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_IMPL;
    local_70 = subdeviceCtrlCmdFifoRotateKeys_IMPL;
    local_78 = subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_92bfc3;
    local_80 = subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_92bfc3;
    local_88 = subdeviceCtrlCmdMemSysGetMIGMemoryPartitionTable_92bfc3;
    local_90 = subdeviceCtrlCmdMemSysGetStaticConfig_92bfc3;
    local_98 = subdeviceCtrlCmdFbGetDynamicOfflinedPages_92bfc3;
    local_a0 = subdeviceCtrlCmdFbGetLTCInfoForFBP_92bfc3;
    local_a8 = subdeviceCtrlCmdFbGetOfflinedPages_92bfc3;
    local_b0 = subdeviceCtrlCmdPerfNotifyVideoevent_92bfc3;
    local_b8 = subdeviceCtrlCmdPerfGetPowerstate_92bfc3;
    local_c0 = subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_92bfc3;
    local_c8 = subdeviceCtrlCmdPerfGetCurrentPstate_92bfc3;
    local_d0 = subdeviceCtrlCmdPerfGetLevelInfo_V2_92bfc3;
    local_d8 = subdeviceCtrlCmdPerfReservePerfmonHw_KERNEL;
    local_e0 = subdeviceCtrlCmdPerfGetGpumonPerfmonUtilSamplesV2_KERNEL;
    local_e8 = subdeviceCtrlCmdBusGetNvlinkCaps_IMPL;
    local_f0 = subdeviceCtrlCmdBusUnsetP2pMapping_5baef9;
    local_f8 = subdeviceCtrlCmdBusSetP2pMapping_5baef9;
    local_100 = subdeviceCtrlCmdBusGetC2CInfo_92bfc3;
    local_108 = subdeviceCtrlCmdBusGetC2CLpwrStats_92bfc3;
    local_110 = subdeviceCtrlCmdBusSetC2CLpwrStateVote_92bfc3;
    local_160 = subdeviceCtrlCmdFifoDisableUsermodeChannels_5baef9;
    local_170 = subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_92bfc3;
    local_178 = subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_92bfc3;
    pcVar2 = subdeviceCtrlCmdBiosGetInfoV2_92bfc3;
    local_118 = subdeviceCtrlCmdFifoObjschedGetCaps_5baef9;
    pcVar14 = subdeviceCtrlCmdSetRcRecovery_5baef9;
    pcVar13 = subdeviceCtrlCmdGetRcRecovery_5baef9;
    pcVar12 = subdeviceCtrlCmdCeGetCaps_IMPL;
    local_120 = subdeviceCtrlCmdFifoConfigCtxswTimeout_5baef9;
    pcVar11 = subdeviceCtrlCmdCeGetCapsV2_IMPL;
    pcVar5 = subdeviceCtrlCmdCeGetAllCaps_IMPL;
    pcVar10 = subdeviceCtrlCmdGpuQueryEccConfiguration_92bfc3;
    local_128 = subdeviceCtrlCmdFifoGetDeviceInfoTable_92bfc3;
    pcVar9 = subdeviceCtrlCmdGpuSetEccConfiguration_92bfc3;
    pcVar8 = subdeviceCtrlCmdGpuResetEccErrorStatus_92bfc3;
    pcVar7 = subdeviceCtrlCmdGspGetFeatures_92bfc3;
    local_130 = subdeviceCtrlCmdFifoUpdateChannelInfo_IMPL;
    pcVar6 = subdeviceCtrlCmdBifGetStaticInfo_92bfc3;
    pcVar3 = subdeviceCtrlCmdInternalGetLocalAtsConfig_92bfc3;
    pcVar4 = subdeviceCtrlCmdInternalSetPeerAtsConfig_92bfc3;
    local_138 = subdeviceCtrlCmdKGrCtxswPmMode_IMPL;
    local_140 = subdeviceCtrlCmdGpuQueryEccStatus_92bfc3;
    local_148 = subdeviceCtrlCmdGpuQueryIllumSupport_5baef9;
    local_150 = subdeviceCtrlCmdGpuQueryScrubberStatus_92bfc3;
    local_158 = subdeviceCtrlCmdGetP2pCaps_92bfc3;
    local_180 = subdeviceCtrlCmdCcuGetSampleInfo_5baef9;
  }
  *(code **)(param_1 + 0x178) = pcVar2;
  *(code **)(param_1 + 0x180) = local_40;
  *(code **)(param_1 + 0x188) = local_48;
  *(code **)(param_1 + 400) = local_50;
  *(code **)(param_1 + 0x198) = local_58;
  *(code **)(param_1 + 0x1a0) = local_170;
  *(code **)(param_1 + 0x1a8) = local_100;
  *(code **)(param_1 + 0x1b0) = local_108;
  *(code **)(param_1 + 0x1b8) = local_110;
  *(code **)(param_1 + 0x1c0) = local_60;
  *(code **)(param_1 + 0x1c8) = local_f8;
  *(code **)(param_1 + 0x1d0) = local_f0;
  *(code **)(param_1 + 0x1d8) = local_e8;
  *(code **)(param_1 + 0x1e0) = local_e0;
  *(code **)(param_1 + 0x1e8) = local_d8;
  *(code **)(param_1 + 0x1f0) = local_d0;
  *(code **)(param_1 + 0x1f8) = local_c8;
  *(code **)(param_1 + 0x200) = local_c0;
  *(code **)(param_1 + 0x208) = local_b8;
  *(code **)(param_1 + 0x210) = local_b0;
  *(code **)(param_1 + 0x218) = local_a8;
  *(code **)(param_1 + 0x220) = local_a0;
  *(code **)(param_1 + 0x228) = local_98;
  *(code **)(param_1 + 0x230) = local_90;
  *(code **)(param_1 + 0x238) = local_88;
  *(code **)(param_1 + 0x240) = local_80;
  *(code **)(param_1 + 0x248) = local_78;
  *(code **)(param_1 + 0x250) = local_178;
  *(code **)(param_1 + 600) = local_68;
  *(code **)(param_1 + 0x260) = local_38;
  *(code **)(param_1 + 0x268) = local_70;
  *(code **)(param_1 + 0x270) = local_160;
  *(code **)(param_1 + 0x278) = local_168;
  *(code **)(param_1 + 0x2c8) = pcVar14;
  *(code **)(param_1 + 0x280) = local_118;
  *(code **)(param_1 + 0x2d0) = pcVar13;
  *(code **)(param_1 + 0x288) = local_120;
  *(code **)(param_1 + 0x2d8) = pcVar12;
  *(code **)(param_1 + 0x290) = local_128;
  *(code **)(param_1 + 0x2e0) = pcVar11;
  *(code **)(param_1 + 0x298) = local_130;
  *(code **)(param_1 + 0x2e8) = pcVar5;
  *(code **)(param_1 + 0x2a0) = local_138;
  *(code **)(param_1 + 0x2f0) = pcVar10;
  *(code **)(param_1 + 0x2a8) = local_140;
  *(code **)(param_1 + 0x2f8) = pcVar9;
  *(code **)(param_1 + 0x2b0) = local_148;
  *(code **)(param_1 + 0x300) = pcVar8;
  *(code **)(param_1 + 0x2b8) = local_150;
  *(code **)(param_1 + 0x308) = pcVar7;
  *(code **)(param_1 + 0x2c0) = local_158;
  *(code **)(param_1 + 0x310) = pcVar6;
  *(code **)(param_1 + 0x318) = pcVar3;
  *(code **)(param_1 + 800) = pcVar4;
  *(code **)(param_1 + 0x328) = local_180;
  return;
}


// ===== 0019b8e0 __nvoc_dtor_Subdevice =====

void __nvoc_dtor_Subdevice(long param_1)

{
  subdeviceDestruct_IMPL();
  __nvoc_dtor_GpuResource(param_1 + 8);
  __nvoc_dtor_Notifier(param_1 + 0x108);
  return;
}


// ===== 0019b910 subdeviceCtrlCmdCcuGetSampleInfo_5baef9 =====

undefined8 subdeviceCtrlCmdCcuGetSampleInfo_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1fb1);
  return 0x56;
}


// ===== 0019b940 subdeviceCtrlCmdInternalSetPeerAtsConfig_92bfc3 =====

undefined8 subdeviceCtrlCmdInternalSetPeerAtsConfig_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1fac);
  return 0x56;
}


// ===== 0019b970 subdeviceCtrlCmdInternalGetLocalAtsConfig_92bfc3 =====

undefined8 subdeviceCtrlCmdInternalGetLocalAtsConfig_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1fa3);
  return 0x56;
}


// ===== 0019b9a0 subdeviceCtrlCmdBifGetStaticInfo_92bfc3 =====

undefined8 subdeviceCtrlCmdBifGetStaticInfo_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f9a);
  return 0x56;
}


// ===== 0019b9d0 subdeviceCtrlCmdGspGetFeatures_92bfc3 =====

undefined8 subdeviceCtrlCmdGspGetFeatures_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f95);
  return 0x56;
}


// ===== 0019ba00 subdeviceCtrlCmdGpuResetEccErrorStatus_92bfc3 =====

undefined8 subdeviceCtrlCmdGpuResetEccErrorStatus_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f90);
  return 0x56;
}


// ===== 0019ba30 subdeviceCtrlCmdGpuSetEccConfiguration_92bfc3 =====

undefined8 subdeviceCtrlCmdGpuSetEccConfiguration_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f8b);
  return 0x56;
}


// ===== 0019ba60 subdeviceCtrlCmdGpuQueryEccConfiguration_92bfc3 =====

undefined8 subdeviceCtrlCmdGpuQueryEccConfiguration_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f86);
  return 0x56;
}


// ===== 0019ba90 subdeviceCtrlCmdGetRcRecovery_5baef9 =====

undefined8 subdeviceCtrlCmdGetRcRecovery_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f82);
  return 0x56;
}


// ===== 0019bac0 subdeviceCtrlCmdSetRcRecovery_5baef9 =====

undefined8 subdeviceCtrlCmdSetRcRecovery_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f7e);
  return 0x56;
}


// ===== 0019baf0 subdeviceCtrlCmdGetP2pCaps_92bfc3 =====

undefined8 subdeviceCtrlCmdGetP2pCaps_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f75);
  return 0x56;
}


// ===== 0019bb20 subdeviceCtrlCmdGpuQueryScrubberStatus_92bfc3 =====

undefined8 subdeviceCtrlCmdGpuQueryScrubberStatus_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f70);
  return 0x56;
}


// ===== 0019bb50 subdeviceCtrlCmdGpuQueryIllumSupport_5baef9 =====

undefined8 subdeviceCtrlCmdGpuQueryIllumSupport_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f6c);
  return 0x56;
}


// ===== 0019bb80 subdeviceCtrlCmdGpuQueryEccStatus_92bfc3 =====

undefined8 subdeviceCtrlCmdGpuQueryEccStatus_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f67);
  return 0x56;
}


// ===== 0019bbb0 subdeviceCtrlCmdFifoGetDeviceInfoTable_92bfc3 =====

undefined8 subdeviceCtrlCmdFifoGetDeviceInfoTable_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f5a);
  return 0x56;
}


// ===== 0019bbe0 subdeviceCtrlCmdFifoConfigCtxswTimeout_5baef9 =====

undefined8 subdeviceCtrlCmdFifoConfigCtxswTimeout_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f56);
  return 0x56;
}


// ===== 0019bc10 subdeviceCtrlCmdFifoObjschedGetCaps_5baef9 =====

undefined8 subdeviceCtrlCmdFifoObjschedGetCaps_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f4e);
  return 0x56;
}


// ===== 0019bc40 subdeviceCtrlCmdFifoDisableUsermodeChannels_5baef9 =====

undefined8 subdeviceCtrlCmdFifoDisableUsermodeChannels_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f42);
  return 0x56;
}


// ===== 0019bc70 subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_92bfc3 =====

undefined8 subdeviceCtrlCmdMemSysQueryDramEncryptionStatus_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f2d);
  return 0x56;
}


// ===== 0019bca0 subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_92bfc3 =====

undefined8 subdeviceCtrlCmdMemSysSetDramEncryptionConfiguration_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f28);
  return 0x56;
}


// ===== 0019bcd0 subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_92bfc3 =====

undefined8 subdeviceCtrlCmdMemSysQueryDramEncryptionPendingConfiguration_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f23);
  return 0x56;
}


// ===== 0019bd00 subdeviceCtrlCmdMemSysGetMIGMemoryPartitionTable_92bfc3 =====

undefined8 subdeviceCtrlCmdMemSysGetMIGMemoryPartitionTable_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f1e);
  return 0x56;
}


// ===== 0019bd30 subdeviceCtrlCmdMemSysGetStaticConfig_92bfc3 =====

undefined8 subdeviceCtrlCmdMemSysGetStaticConfig_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f15);
  return 0x56;
}


// ===== 0019bd60 subdeviceCtrlCmdFbGetDynamicOfflinedPages_92bfc3 =====

undefined8 subdeviceCtrlCmdFbGetDynamicOfflinedPages_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f10);
  return 0x56;
}


// ===== 0019bd90 subdeviceCtrlCmdFbGetLTCInfoForFBP_92bfc3 =====

undefined8 subdeviceCtrlCmdFbGetLTCInfoForFBP_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f0b);
  return 0x56;
}


// ===== 0019bdc0 subdeviceCtrlCmdFbGetOfflinedPages_92bfc3 =====

undefined8 subdeviceCtrlCmdFbGetOfflinedPages_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1f06);
  return 0x56;
}


// ===== 0019bdf0 subdeviceCtrlCmdPerfNotifyVideoevent_92bfc3 =====

undefined8 subdeviceCtrlCmdPerfNotifyVideoevent_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1efd);
  return 0x56;
}


// ===== 0019be20 subdeviceCtrlCmdPerfGetPowerstate_92bfc3 =====

undefined8 subdeviceCtrlCmdPerfGetPowerstate_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ef4);
  return 0x56;
}


// ===== 0019be50 subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_92bfc3 =====

undefined8 subdeviceCtrlCmdPerfGetVideoEnginePerfmonSample_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1eef);
  return 0x56;
}


// ===== 0019be80 subdeviceCtrlCmdPerfGetCurrentPstate_92bfc3 =====

undefined8 subdeviceCtrlCmdPerfGetCurrentPstate_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1eea);
  return 0x56;
}


// ===== 0019beb0 subdeviceCtrlCmdPerfGetLevelInfo_V2_92bfc3 =====

undefined8 subdeviceCtrlCmdPerfGetLevelInfo_V2_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ee5);
  return 0x56;
}


// ===== 0019bee0 subdeviceCtrlCmdBusUnsetP2pMapping_5baef9 =====

undefined8 subdeviceCtrlCmdBusUnsetP2pMapping_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1edd);
  return 0x56;
}


// ===== 0019bf10 subdeviceCtrlCmdBusSetP2pMapping_5baef9 =====

undefined8 subdeviceCtrlCmdBusSetP2pMapping_5baef9(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ed9);
  return 0x56;
}


// ===== 0019bf40 subdeviceCtrlCmdBusSetC2CIdleThreshold_92bfc3 =====

undefined8 subdeviceCtrlCmdBusSetC2CIdleThreshold_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ed4);
  return 0x56;
}


// ===== 0019bf70 subdeviceCtrlCmdBusSetC2CLpwrStateVote_92bfc3 =====

undefined8 subdeviceCtrlCmdBusSetC2CLpwrStateVote_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ecf);
  return 0x56;
}


// ===== 0019bfa0 subdeviceCtrlCmdBusGetC2CLpwrStats_92bfc3 =====

undefined8 subdeviceCtrlCmdBusGetC2CLpwrStats_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1eca);
  return 0x56;
}


// ===== 0019bfd0 subdeviceCtrlCmdBusGetC2CInfo_92bfc3 =====

undefined8 subdeviceCtrlCmdBusGetC2CInfo_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ec5);
  return 0x56;
}


// ===== 0019c000 subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_92bfc3 =====

undefined8 subdeviceCtrlCmdBusGetPcieCplAtomicsCaps_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ec0);
  return 0x56;
}


// ===== 0019c030 subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_92bfc3 =====

undefined8 subdeviceCtrlCmdBusGetPcieSupportedGpuAtomics_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1ebb);
  return 0x56;
}


// ===== 0019c060 subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_92bfc3 =====

undefined8 subdeviceCtrlCmdBusGetPcieReqAtomicsCaps_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1eb6);
  return 0x56;
}


// ===== 0019c090 subdeviceCtrlCmdBiosGetPostTime_92bfc3 =====

undefined8 subdeviceCtrlCmdBiosGetPostTime_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1eb1);
  return 0x56;
}


// ===== 0019c0c0 subdeviceCtrlCmdBiosGetInfoV2_92bfc3 =====

undefined8 subdeviceCtrlCmdBiosGetInfoV2_92bfc3(void)

{
  nvAssertFailed(&DAT_00c6646d,"generated/g_subdevice_nvoc.h",0x1eac);
  return 0x56;
}


// ===== 0019c0f0 subdeviceCtrlCmdMemSysGetMIGMemoryPartitionTable_395e98 =====

undefined8 subdeviceCtrlCmdMemSysGetMIGMemoryPartitionTable_395e98(void)

{
  return 0x56;
}


// ===== 0019c100 subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_395e98 =====

undefined8 subdeviceCtrlCmdFifoDisableChannelsForKeyRotation_395e98(void)

{
  return 0x56;
}


// ===== 0019c110 subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_395e98 =====

undefined8 subdeviceCtrlCmdFifoDisableChannelsForKeyRotationV2_395e98(void)

{
  return 0x56;
}


// ===== 0019c120 subdeviceCtrlCmdFifoRotateKeys_395e98 =====

undefined8 subdeviceCtrlCmdFifoRotateKeys_395e98(void)

{
  return 0x56;
}


// ===== 0019c130 subdeviceCtrlCmdFifoGetUserdLocation_395e98 =====

undefined8 subdeviceCtrlCmdFifoGetUserdLocation_395e98(void)

{
  return 0x56;
}


// ===== 0019c140 subdeviceCtrlCmdFifoUpdateChannelInfo_395e98 =====

undefined8 subdeviceCtrlCmdFifoUpdateChannelInfo_395e98(void)

{
  return 0x56;
}


// ===== 0019c150 subdeviceCtrlCmdKGrCtxswPmMode_395e98 =====

undefined8 subdeviceCtrlCmdKGrCtxswPmMode_395e98(void)

{
  return 0x56;
}


// ===== 0019c160 subdeviceCtrlCmdInternalGetLocalAtsConfig_395e98 =====

undefined8 subdeviceCtrlCmdInternalGetLocalAtsConfig_395e98(void)

{
  return 0x56;
}


// ===== 0019c170 subdeviceCtrlCmdInternalSetPeerAtsConfig_395e98 =====

undefined8 subdeviceCtrlCmdInternalSetPeerAtsConfig_395e98(void)

{
  return 0x56;
}


// ===== 0019c180 subdeviceCtrlCmdFifoDisableUsermodeChannels_ac1694 =====

undefined8 subdeviceCtrlCmdFifoDisableUsermodeChannels_ac1694(void)

{
  return 0;
}


// ===== 0019c190 subdeviceCtrlCmdFifoObjschedGetCaps_ac1694 =====

undefined8 subdeviceCtrlCmdFifoObjschedGetCaps_ac1694(void)

{
  return 0;
}


// ===== 0019c1a0 subdeviceCtrlCmdFifoConfigCtxswTimeout_ac1694 =====

undefined8 subdeviceCtrlCmdFifoConfigCtxswTimeout_ac1694(void)

{
  return 0;
}


// ===== 0019c1b0 subdeviceCtrlCmdSetRcRecovery_ac1694 =====

undefined8 subdeviceCtrlCmdSetRcRecovery_ac1694(void)

{
  return 0;
}


// ===== 0019c1c0 __nvoc_ctor_Subdevice =====

ulong __nvoc_ctor_Subdevice
                (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = __nvoc_ctor_GpuResource(param_1 + 8,param_4,param_5);
  if ((int)uVar2 != 0) {
    return uVar2;
  }
  uVar1 = __nvoc_ctor_Notifier(param_1 + 0x108,param_4);
  if (uVar1 == 0) {
    uVar2 = subdeviceConstruct_IMPL(param_1,param_4,param_5);
    uVar1 = (uint)uVar2;
    if (uVar1 == 0) {
      return uVar2;
    }
    __nvoc_dtor_Notifier(param_1 + 0x108);
  }
  __nvoc_dtor_GpuResource(param_1 + 8);
  return (ulong)uVar1;
}


// ===== 0019c260 __nvoc_objCreate_Subdevice =====

int __nvoc_objCreate_Subdevice(long *param_1,long param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x6c0);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_subdevice_nvoc.c",0x28f8);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_subdevice_nvoc.c",0x28f0);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x6c0);
  *(uint *)((long)puVar4 + 0x4c) = param_3;
  if (param_2 == 0) {
    iVar1 = 0x1f;
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_subdevice_nvoc.c",0x2901);
    goto LAB_0019c42e;
  }
  if ((param_3 & 1) == 0) {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar4 + 4);
  }
  else {
    puVar4[6] = 0;
    local_58 = 0;
  }
  lVar2 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmHalspecOwner);
  if (lVar2 == 0) {
    lVar2 = objFindAncestor_IMPL(param_2,0x34a6d6);
    uVar5 = 0;
    if (lVar2 != 0) {
      uVar5 = objFindAncestor_IMPL(param_2,0x34a6d6);
    }
    lVar2 = __nvoc_dynamicCast(uVar5,__nvoc_class_def_RmHalspecOwner);
    if (lVar2 != 0) goto LAB_0019c2ff;
    nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_subdevice_nvoc.c",0x2911);
LAB_0019c515:
    iVar1 = 0x1f;
  }
  else {
LAB_0019c2ff:
    lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_GpuHalspecOwner);
    if (lVar3 == 0) {
      lVar3 = objFindAncestor_IMPL(param_2,0x74bc71);
      uVar5 = 0;
      if (lVar3 != 0) {
        uVar5 = objFindAncestor_IMPL(param_2,0x74bc71);
      }
      lVar3 = __nvoc_dynamicCast(uVar5,__nvoc_class_def_GpuHalspecOwner);
      if (lVar3 == 0) {
        nvCheckOkFailedNoLog
                  (4,0x1f,"pGpuhalspecowner != NULL","generated/g_subdevice_nvoc.c",0x2914);
        goto LAB_0019c515;
      }
    }
    puVar4[0x2e] = puVar4;
    puVar4[0x27] = puVar4 + 4;
    puVar4[0x28] = puVar4 + 3;
    puVar4[0x29] = puVar4 + 0x10;
    puVar4[0x2a] = puVar4 + 2;
    puVar4[0x2c] = puVar4 + 0x22;
    puVar4[0x2b] = puVar4 + 1;
    puVar4[0x2d] = puVar4 + 0x21;
    __nvoc_init__GpuResource();
    __nvoc_init__Notifier(puVar4 + 0x21);
    puVar4[4] = 0xc665e0;
    puVar4[3] = 0xc665c8;
    puVar4[0x10] = 0xc66688;
    puVar4[2] = 0xc665b0;
    puVar4[1] = 0xc66598;
    puVar4[0x22] = 0xc66828;
    puVar4[0x21] = 0xc66810;
    *puVar4 = __nvoc_metadata__Subdevice;
    __nvoc_init_funcTable_Subdevice_1(puVar4,lVar2,lVar3);
    iVar1 = __nvoc_ctor_Subdevice();
    if (iVar1 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar4 + 4);
  }
LAB_0019c42e:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x6c0);
  }
  return iVar1;
}


// ===== 0019c600 __nvoc_objCreateDynamic_Subdevice =====

void __nvoc_objCreateDynamic_Subdevice
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0019c62e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0019c62e:
  __nvoc_objCreate_Subdevice(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019c660 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019c670 __nvoc_down_thunk_SoftwareMethodTest_chandesGetSwMethods =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_SoftwareMethodTest_chandesGetSwMethods(long param_1)

{
  (**(code **)(*(long *)(param_1 + -8) + 0x428))(param_1 + -8);
  return;
}


// ===== 0019c690 __nvoc_up_thunk_ChannelDescendant_swtestIsSwMethodStalling =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_ChannelDescendant_swtestIsSwMethodStalling(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x318))(param_1 + 8);
  return;
}


// ===== 0019c6b0 __nvoc_up_thunk_ChannelDescendant_swtestCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_ChannelDescendant_swtestCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 800))(param_1 + 8,param_2);
  return;
}


// ===== 0019c6d0 __nvoc_up_thunk_GpuResource_swtestControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b0))(param_1 + 0x10);
  return;
}


// ===== 0019c6f0 __nvoc_up_thunk_GpuResource_swtestMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b8))(param_1 + 0x10);
  return;
}


// ===== 0019c710 __nvoc_up_thunk_GpuResource_swtestUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c0))(param_1 + 0x10);
  return;
}


// ===== 0019c730 __nvoc_up_thunk_GpuResource_swtestShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c8))(param_1 + 0x10);
  return;
}


// ===== 0019c750 __nvoc_up_thunk_GpuResource_swtestGetRegBaseOffsetAndSize =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestGetRegBaseOffsetAndSize(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d0))(param_1 + 0x10);
  return;
}


// ===== 0019c770 __nvoc_up_thunk_GpuResource_swtestGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d8))(param_1 + 0x10);
  return;
}


// ===== 0019c790 __nvoc_up_thunk_GpuResource_swtestInternalControlForward =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestInternalControlForward(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e0))(param_1 + 0x10);
  return;
}


// ===== 0019c7b0 __nvoc_up_thunk_GpuResource_swtestGetInternalObjectHandle =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_GpuResource_swtestGetInternalObjectHandle(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e8))(param_1 + 0x10);
  return;
}


// ===== 0019c7d0 __nvoc_up_thunk_RmResource_swtestAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_swtestAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xf0))(param_1 + 0x18,param_2,param_3,param_4);
  return;
}


// ===== 0019c7f0 __nvoc_up_thunk_RmResource_swtestGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_swtestGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x100))(param_1 + 0x18);
  return;
}


// ===== 0019c810 __nvoc_up_thunk_RmResource_swtestGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_swtestGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x110))(param_1 + 0x18);
  return;
}


// ===== 0019c830 __nvoc_up_thunk_RmResource_swtestControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_swtestControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x118))(param_1 + 0x18);
  return;
}


// ===== 0019c850 __nvoc_up_thunk_RmResource_swtestControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_swtestControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x120))(param_1 + 0x18);
  return;
}


// ===== 0019c870 __nvoc_up_thunk_RmResource_swtestControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_swtestControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x128))(param_1 + 0x18);
  return;
}


// ===== 0019c890 __nvoc_up_thunk_RmResource_swtestControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_swtestControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x130))(param_1 + 0x18);
  return;
}


// ===== 0019c8b0 __nvoc_up_thunk_RsResource_swtestCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x30))(param_1 + 0x20);
  return;
}


// ===== 0019c8d0 __nvoc_up_thunk_RsResource_swtestIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x38))(param_1 + 0x20);
  return;
}


// ===== 0019c8f0 __nvoc_up_thunk_RsResource_swtestPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x40))(param_1 + 0x20);
  return;
}


// ===== 0019c910 __nvoc_up_thunk_RsResource_swtestControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x50))(param_1 + 0x20);
  return;
}


// ===== 0019c930 __nvoc_up_thunk_RsResource_swtestIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x88))(param_1 + 0x20);
  return;
}


// ===== 0019c950 __nvoc_up_thunk_RsResource_swtestMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x90))(param_1 + 0x20);
  return;
}


// ===== 0019c970 __nvoc_up_thunk_RsResource_swtestUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0x98))(param_1 + 0x20);
  return;
}


// ===== 0019c990 __nvoc_up_thunk_RsResource_swtestGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x20) + 0xa0))(param_1 + 0x20);
  return;
}


// ===== 0019c9b0 __nvoc_up_thunk_RsResource_swtestAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_swtestAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x20) + 0xb8))(param_1,param_2 + 0x20);
  return;
}


// ===== 0019c9d0 __nvoc_up_thunk_Notifier_swtestGetNotificationListPtr =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_swtestGetNotificationListPtr(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x58))(param_1 + 0x110);
  return;
}


// ===== 0019c9f0 __nvoc_up_thunk_Notifier_swtestGetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_swtestGetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x60))(param_1 + 0x110);
  return;
}


// ===== 0019ca10 __nvoc_up_thunk_Notifier_swtestSetNotificationShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_swtestSetNotificationShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x68))(param_1 + 0x110);
  return;
}


// ===== 0019ca30 __nvoc_up_thunk_Notifier_swtestUnregisterEvent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_swtestUnregisterEvent(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x70))(param_1 + 0x110);
  return;
}


// ===== 0019ca50 __nvoc_up_thunk_Notifier_swtestGetOrAllocNotifShare =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Notifier_swtestGetOrAllocNotifShare(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x110) + 0x78))(param_1 + 0x110);
  return;
}


// ===== 0019ca70 __nvoc_dtor_SoftwareMethodTest =====

void __nvoc_dtor_SoftwareMethodTest(long param_1)

{
  swtestDestruct_IMPL();
  __nvoc_dtor_ChannelDescendant(param_1 + 8);
  return;
}


// ===== 0019caa0 __nvoc_objCreate_SoftwareMethodTest =====

int __nvoc_objCreate_SoftwareMethodTest
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x1e8);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_sw_test_nvoc.c",0x279);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_sw_test_nvoc.c",0x271);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x1e8);
  *(uint *)((long)puVar4 + 0x54) = param_3;
  if (param_2 == 0) {
    nvCheckOkFailedNoLog(4,0x1f,"__nvoc_pParent != NULL","generated/g_sw_test_nvoc.c",0x282);
    iVar2 = 0x1f;
    goto LAB_0019cc2c;
  }
  if ((param_3 & 1) == 0) {
    lVar5 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar5,puVar4 + 5);
  }
  else {
    puVar4[7] = 0;
    lVar5 = 0;
  }
  lVar3 = __nvoc_dynamicCast(param_2,__nvoc_class_def_RmHalspecOwner);
  if (lVar3 == 0) {
    lVar3 = objFindAncestor_IMPL(param_2,0x34a6d6);
    uVar6 = 0;
    if (lVar3 != 0) {
      uVar6 = objFindAncestor_IMPL(param_2,0x34a6d6);
    }
    lVar3 = __nvoc_dynamicCast(uVar6,__nvoc_class_def_RmHalspecOwner);
    if (lVar3 != 0) goto LAB_0019cb34;
    nvCheckOkFailedNoLog(4,0x1f,"pRmhalspecowner != NULL","generated/g_sw_test_nvoc.c",0x292);
    iVar2 = 0x1f;
  }
  else {
LAB_0019cb34:
    puVar1 = puVar4 + 1;
    puVar4[0x3c] = puVar4;
    puVar4[0x34] = puVar4 + 5;
    puVar4[0x35] = puVar4 + 4;
    puVar4[0x36] = puVar4 + 0x11;
    puVar4[0x37] = puVar4 + 3;
    puVar4[0x38] = puVar4 + 2;
    puVar4[0x39] = puVar4 + 0x23;
    puVar4[0x3a] = puVar4 + 0x22;
    puVar4[0x3b] = puVar1;
    __nvoc_init__ChannelDescendant(puVar1);
    puVar4[5] = 0xc73638;
    puVar4[4] = 0xc73620;
    puVar4[0x11] = 0xc736e0;
    puVar4[3] = 0xc73608;
    puVar4[2] = 0xc735f0;
    puVar4[0x23] = 0xc73880;
    puVar4[0x22] = 0xc73868;
    puVar4[1] = 0xc735d8;
    *puVar4 = __nvoc_metadata__SoftwareMethodTest;
    iVar2 = __nvoc_ctor_ChannelDescendant(puVar1,lVar3,param_4,param_5,0);
    if (iVar2 == 0) {
      iVar2 = swtestConstruct_IMPL(puVar4,param_4,param_5);
      if (iVar2 == 0) {
        *param_1 = (long)puVar4;
        return 0;
      }
      __nvoc_dtor_ChannelDescendant(puVar1);
    }
  }
  if (lVar5 != 0) {
    objRemoveChild_IMPL(lVar5,puVar4 + 5);
  }
LAB_0019cc2c:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x1e8);
  }
  return iVar2;
}


// ===== 0019cdf0 __nvoc_objCreateDynamic_SoftwareMethodTest =====

void __nvoc_objCreateDynamic_SoftwareMethodTest
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0019ce1e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0019ce1e:
  __nvoc_objCreate_SoftwareMethodTest(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019ce50 __nvoc_down_thunk_SwIntr_intrservRegisterIntrService =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_SwIntr_intrservRegisterIntrService(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + -0x150) + 0xf0))(param_1,param_2 + -0x150);
  return;
}


// ===== 0019ce70 __nvoc_down_thunk_SwIntr_intrservServiceInterrupt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_SwIntr_intrservServiceInterrupt(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + -0x150) + 0xf8))(param_1,param_2 + -0x150);
  return;
}


// ===== 0019ce90 __nvoc_up_thunk_OBJENGSTATE_swintrConstructEngine =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrConstructEngine(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x30))(param_1,param_2 + 8);
  return;
}


// ===== 0019ceb0 __nvoc_up_thunk_OBJENGSTATE_swintrInitMissing =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrInitMissing(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x38))(param_1,param_2 + 8);
  return;
}


// ===== 0019ced0 __nvoc_up_thunk_OBJENGSTATE_swintrStatePreInitLocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStatePreInitLocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x40))(param_1,param_2 + 8);
  return;
}


// ===== 0019cef0 __nvoc_up_thunk_OBJENGSTATE_swintrStatePreInitUnlocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStatePreInitUnlocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x48))(param_1,param_2 + 8);
  return;
}


// ===== 0019cf10 __nvoc_up_thunk_OBJENGSTATE_swintrStateInitLocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStateInitLocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x50))(param_1,param_2 + 8);
  return;
}


// ===== 0019cf30 __nvoc_up_thunk_OBJENGSTATE_swintrStateInitUnlocked =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStateInitUnlocked(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x58))(param_1,param_2 + 8);
  return;
}


// ===== 0019cf50 __nvoc_up_thunk_OBJENGSTATE_swintrStatePreLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStatePreLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x60))(param_1,param_2 + 8);
  return;
}


// ===== 0019cf70 __nvoc_up_thunk_OBJENGSTATE_swintrStateLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStateLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x68))(param_1,param_2 + 8);
  return;
}


// ===== 0019cf90 __nvoc_up_thunk_OBJENGSTATE_swintrStatePostLoad =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStatePostLoad(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x70))(param_1,param_2 + 8);
  return;
}


// ===== 0019cfb0 __nvoc_up_thunk_OBJENGSTATE_swintrStatePreUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStatePreUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x78))(param_1,param_2 + 8);
  return;
}


// ===== 0019cfd0 __nvoc_up_thunk_OBJENGSTATE_swintrStateUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStateUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x80))(param_1,param_2 + 8);
  return;
}


// ===== 0019cff0 __nvoc_up_thunk_OBJENGSTATE_swintrStatePostUnload =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStatePostUnload(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x88))(param_1,param_2 + 8);
  return;
}


// ===== 0019d010 __nvoc_up_thunk_OBJENGSTATE_swintrStateDestroy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrStateDestroy(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x90))(param_1,param_2 + 8);
  return;
}


// ===== 0019d030 __nvoc_up_thunk_OBJENGSTATE_swintrIsPresent =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_OBJENGSTATE_swintrIsPresent(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 8) + 0x98))(param_1,param_2 + 8);
  return;
}


// ===== 0019d050 __nvoc_up_thunk_IntrService_swintrClearInterrupt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_IntrService_swintrClearInterrupt(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x150) + 0x20))(param_1,param_2 + 0x150);
  return;
}


// ===== 0019d070 __nvoc_up_thunk_IntrService_swintrServiceNotificationInterrupt =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_IntrService_swintrServiceNotificationInterrupt(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x150) + 0x30))(param_1,param_2 + 0x150);
  return;
}


// ===== 0019d090 __nvoc_dtor_SwIntr =====

void __nvoc_dtor_SwIntr(long param_1)

{
  __nvoc_dtor_OBJENGSTATE(param_1 + 8);
  __nvoc_dtor_IntrService(param_1 + 0x150);
  return;
}


// ===== 0019d0c0 __nvoc_objCreate_SwIntr =====

int __nvoc_objCreate_SwIntr(long *param_1,long param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  
  if ((param_3 & 2) == 0) {
    puVar5 = (undefined8 *)portMemAllocNonPaged(0x180);
    if (puVar5 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_swintr_nvoc.c",0x150);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar5 = (undefined8 *)*param_1, puVar5 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_swintr_nvoc.c",0x148);
    return 0x3b;
  }
  portMemSet(puVar5,0,0x180);
  puVar1 = puVar5 + 2;
  *(uint *)((long)puVar5 + 0x3c) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar2 = puVar5 + 1;
    puVar3 = puVar5 + 0x2a;
    puVar5[4] = 0;
    puVar5[0x2c] = puVar1;
    puVar5[0x2d] = puVar2;
    puVar5[0x2e] = puVar3;
    puVar5[0x2f] = puVar5;
    __nvoc_init__OBJENGSTATE(puVar2);
    __nvoc_init__IntrService(puVar3);
    *puVar5 = __nvoc_metadata__SwIntr;
    puVar5[2] = 0xc73c10;
    puVar5[1] = 0xc73bf8;
    puVar5[0x2a] = 0xc73c98;
    iVar4 = __nvoc_ctor_OBJENGSTATE(puVar2);
    if (iVar4 == 0) {
      iVar4 = __nvoc_ctor_IntrService(puVar3);
      if (iVar4 == 0) goto LAB_0019d1c2;
      __nvoc_dtor_OBJENGSTATE(puVar2);
    }
  }
  else {
    puVar2 = puVar5 + 1;
    lVar6 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    puVar3 = puVar5 + 0x2a;
    objAddChild_IMPL(lVar6,puVar1);
    puVar5[0x2c] = puVar1;
    puVar5[0x2d] = puVar2;
    puVar5[0x2e] = puVar3;
    puVar5[0x2f] = puVar5;
    __nvoc_init__OBJENGSTATE(puVar2);
    __nvoc_init__IntrService(puVar3);
    *puVar5 = __nvoc_metadata__SwIntr;
    puVar5[2] = 0xc73c10;
    puVar5[1] = 0xc73bf8;
    puVar5[0x2a] = 0xc73c98;
    iVar4 = __nvoc_ctor_OBJENGSTATE(puVar2);
    if (iVar4 == 0) {
      iVar4 = __nvoc_ctor_IntrService(puVar3);
      if (iVar4 == 0) {
LAB_0019d1c2:
        *param_1 = (long)puVar5;
        return 0;
      }
      __nvoc_dtor_OBJENGSTATE(puVar2);
    }
    if (lVar6 != 0) {
      objRemoveChild_IMPL(lVar6,puVar1);
    }
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar5);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar5,0,0x180);
  }
  return iVar4;
}


// ===== 0019d380 __nvoc_objCreateDynamic_SwIntr =====

void __nvoc_objCreateDynamic_SwIntr(void)

{
  __nvoc_objCreate_SwIntr();
  return;
}


// ===== 0019d390 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019d3a0 __nvoc_up_thunk_RmResource_syncgpuboostAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf0))(param_1 + 8,param_2,param_3,param_4);
  return;
}


// ===== 0019d3c0 __nvoc_up_thunk_RmResource_syncgpuboostShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0xf8))(param_1 + 8);
  return;
}


// ===== 0019d3e0 __nvoc_up_thunk_RmResource_syncgpuboostGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x100))(param_1 + 8);
  return;
}


// ===== 0019d400 __nvoc_up_thunk_RmResource_syncgpuboostCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x108))(param_1 + 8,param_2);
  return;
}


// ===== 0019d420 __nvoc_up_thunk_RmResource_syncgpuboostGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x110))(param_1 + 8);
  return;
}


// ===== 0019d440 __nvoc_up_thunk_RmResource_syncgpuboostControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x118))(param_1 + 8);
  return;
}


// ===== 0019d460 __nvoc_up_thunk_RmResource_syncgpuboostControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x120))(param_1 + 8);
  return;
}


// ===== 0019d480 __nvoc_up_thunk_RmResource_syncgpuboostControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x128))(param_1 + 8);
  return;
}


// ===== 0019d4a0 __nvoc_up_thunk_RmResource_syncgpuboostControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncgpuboostControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x130))(param_1 + 8);
  return;
}


// ===== 0019d4c0 __nvoc_up_thunk_RsResource_syncgpuboostCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x30))(param_1 + 0x10);
  return;
}


// ===== 0019d4e0 __nvoc_up_thunk_RsResource_syncgpuboostIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x38))(param_1 + 0x10);
  return;
}


// ===== 0019d500 __nvoc_up_thunk_RsResource_syncgpuboostPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x40))(param_1 + 0x10);
  return;
}


// ===== 0019d520 __nvoc_up_thunk_RsResource_syncgpuboostControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x48))(param_1 + 0x10);
  return;
}


// ===== 0019d540 __nvoc_up_thunk_RsResource_syncgpuboostControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x50))(param_1 + 0x10);
  return;
}


// ===== 0019d560 __nvoc_up_thunk_RsResource_syncgpuboostMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x78))(param_1 + 0x10);
  return;
}


// ===== 0019d580 __nvoc_up_thunk_RsResource_syncgpuboostUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x80))(param_1 + 0x10);
  return;
}


// ===== 0019d5a0 __nvoc_up_thunk_RsResource_syncgpuboostIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x88))(param_1 + 0x10);
  return;
}


// ===== 0019d5c0 __nvoc_up_thunk_RsResource_syncgpuboostMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x90))(param_1 + 0x10);
  return;
}


// ===== 0019d5e0 __nvoc_up_thunk_RsResource_syncgpuboostUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x98))(param_1 + 0x10);
  return;
}


// ===== 0019d600 __nvoc_up_thunk_RsResource_syncgpuboostGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xa0))(param_1 + 0x10);
  return;
}


// ===== 0019d620 __nvoc_up_thunk_RsResource_syncgpuboostAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncgpuboostAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x10) + 0xb8))(param_1,param_2 + 0x10);
  return;
}


// ===== 0019d640 __nvoc_dtor_SyncGpuBoost =====

void __nvoc_dtor_SyncGpuBoost(long param_1)

{
  syncgpuboostDestruct_IMPL();
  __nvoc_dtor_RmResource(param_1 + 8);
  return;
}


// ===== 0019d670 __nvoc_objCreate_SyncGpuBoost =====

int __nvoc_objCreate_SyncGpuBoost
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0xe0);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_syncgpuboost_nvoc.c",0x191);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_syncgpuboost_nvoc.c",0x189);
    return 0x3b;
  }
  portMemSet(puVar4,0,0xe0);
  puVar1 = puVar4 + 3;
  *(uint *)((long)puVar4 + 0x44) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[5] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x16] = puVar1;
  puVar4[0x17] = puVar4 + 2;
  puVar4[0x18] = puVar4 + 0xf;
  puVar4[0x19] = puVar2;
  puVar4[0x1a] = puVar4;
  __nvoc_init__RmResource(puVar2);
  puVar4[3] = 0xc73ea8;
  puVar4[2] = 0xc73e90;
  puVar4[0xf] = 0xc73f50;
  puVar4[1] = 0xc73e78;
  *puVar4 = __nvoc_metadata__SyncGpuBoost;
  iVar3 = __nvoc_ctor_RmResource(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = syncgpuboostConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_RmResource(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0xe0);
  }
  return iVar3;
}


// ===== 0019d8d0 __nvoc_objCreateDynamic_SyncGpuBoost =====

void __nvoc_objCreateDynamic_SyncGpuBoost
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0019d8fe;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0019d8fe:
  __nvoc_objCreate_SyncGpuBoost(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019d930 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019d940 memCheckMemInterUnmap_ac1694 =====

undefined8 memCheckMemInterUnmap_ac1694(void)

{
  return 0;
}


// ===== 0019d950 memCheckCopyPermissions_ac1694 =====

undefined8 memCheckCopyPermissions_ac1694(void)

{
  return 0;
}


// ===== 0019d960 memIsGpuMapAllowed_e661f0 =====

undefined8 memIsGpuMapAllowed_e661f0(void)

{
  return 1;
}


// ===== 0019d970 memIsExportAllowed_e661f0 =====

undefined8 memIsExportAllowed_e661f0(void)

{
  return 1;
}


// ===== 0019d980 __nvoc_down_thunk_SyncpointMemory_resCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_down_thunk_SyncpointMemory_resCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + -0x18) + 0x298))(param_1 + -0x18);
  return;
}


// ===== 0019d9a0 __nvoc_up_thunk_Memory_syncpointIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b0))(param_1 + 8);
  return;
}


// ===== 0019d9c0 __nvoc_up_thunk_Memory_syncpointGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1b8))(param_1 + 8);
  return;
}


// ===== 0019d9e0 __nvoc_up_thunk_Memory_syncpointControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c0))(param_1 + 8);
  return;
}


// ===== 0019da00 __nvoc_up_thunk_Memory_syncpointMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1c8))(param_1 + 8);
  return;
}


// ===== 0019da20 __nvoc_up_thunk_Memory_syncpointUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d0))(param_1 + 8);
  return;
}


// ===== 0019da40 __nvoc_up_thunk_Memory_syncpointGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1d8))(param_1 + 8);
  return;
}


// ===== 0019da60 __nvoc_up_thunk_Memory_syncpointCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e0))(param_1 + 8,param_2);
  return;
}


// ===== 0019da80 __nvoc_up_thunk_Memory_syncpointGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1e8))(param_1 + 8);
  return;
}


// ===== 0019daa0 __nvoc_up_thunk_Memory_syncpointCheckCopyPermissions =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointCheckCopyPermissions(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1f0))(param_1 + 8);
  return;
}


// ===== 0019dac0 __nvoc_up_thunk_Memory_syncpointIsReady =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointIsReady(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x1f8))(param_1 + 8,param_2);
  return;
}


// ===== 0019dae0 __nvoc_up_thunk_Memory_syncpointIsGpuMapAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointIsGpuMapAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x200))(param_1 + 8);
  return;
}


// ===== 0019db00 __nvoc_up_thunk_Memory_syncpointIsExportAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_syncpointIsExportAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x208))(param_1 + 8);
  return;
}


// ===== 0019db20 __nvoc_up_thunk_RmResource_syncpointAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncpointAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf0))(param_1 + 0x10,param_2,param_3,param_4);
  return;
}


// ===== 0019db40 __nvoc_up_thunk_RmResource_syncpointShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncpointShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0xf8))(param_1 + 0x10);
  return;
}


// ===== 0019db60 __nvoc_up_thunk_RmResource_syncpointControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncpointControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x118))(param_1 + 0x10);
  return;
}


// ===== 0019db80 __nvoc_up_thunk_RmResource_syncpointControlSerialization_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncpointControlSerialization_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x120))(param_1 + 0x10);
  return;
}


// ===== 0019dba0 __nvoc_up_thunk_RmResource_syncpointControl_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncpointControl_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x128))(param_1 + 0x10);
  return;
}


// ===== 0019dbc0 __nvoc_up_thunk_RmResource_syncpointControl_Epilogue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_syncpointControl_Epilogue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x130))(param_1 + 0x10);
  return;
}


// ===== 0019dbe0 __nvoc_up_thunk_RsResource_syncpointPreDestruct =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncpointPreDestruct(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x40))(param_1 + 0x18);
  return;
}


// ===== 0019dc00 __nvoc_up_thunk_RsResource_syncpointControlFilter =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncpointControlFilter(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x50))(param_1 + 0x18);
  return;
}


// ===== 0019dc20 __nvoc_up_thunk_RsResource_syncpointIsPartialUnmapSupported =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncpointIsPartialUnmapSupported(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x88))(param_1 + 0x18);
  return;
}


// ===== 0019dc40 __nvoc_up_thunk_RsResource_syncpointMapTo =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncpointMapTo(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x90))(param_1 + 0x18);
  return;
}


// ===== 0019dc60 __nvoc_up_thunk_RsResource_syncpointUnmapFrom =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncpointUnmapFrom(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x98))(param_1 + 0x18);
  return;
}


// ===== 0019dc80 __nvoc_up_thunk_RsResource_syncpointGetRefCount =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncpointGetRefCount(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xa0))(param_1 + 0x18);
  return;
}


// ===== 0019dca0 __nvoc_up_thunk_RsResource_syncpointAddAdditionalDependants =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RsResource_syncpointAddAdditionalDependants(undefined8 param_1,long param_2)

{
  (**(code **)(*(long *)(param_2 + 0x18) + 0xb8))(param_1,param_2 + 0x18);
  return;
}


// ===== 0019dcc0 __nvoc_dtor_SyncpointMemory =====

void __nvoc_dtor_SyncpointMemory(long param_1)

{
  __nvoc_dtor_Memory(param_1 + 8);
  return;
}


// ===== 0019dcd0 __nvoc_objCreate_SyncpointMemory =====

int __nvoc_objCreate_SyncpointMemory
              (long *param_1,long param_2,uint param_3,undefined8 param_4,undefined8 param_5)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  long local_58;
  
  if ((param_3 & 2) == 0) {
    puVar4 = (undefined8 *)portMemAllocNonPaged(0x220);
    if (puVar4 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_syncpoint_mem_nvoc.c",0x1e9);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar4 = (undefined8 *)*param_1, puVar4 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_syncpoint_mem_nvoc.c",0x1e1);
    return 0x3b;
  }
  portMemSet(puVar4,0,0x220);
  puVar1 = puVar4 + 4;
  *(uint *)((long)puVar4 + 0x4c) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar4[6] = 0;
    local_58 = 0;
  }
  else {
    local_58 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(local_58,puVar1);
  }
  puVar2 = puVar4 + 1;
  puVar4[0x3e] = puVar1;
  puVar4[0x3f] = puVar4 + 3;
  puVar4[0x40] = puVar4 + 0x10;
  puVar4[0x41] = puVar4 + 2;
  puVar4[0x42] = puVar2;
  puVar4[0x43] = puVar4;
  __nvoc_init__Memory(puVar2);
  puVar4[4] = 0xc74240;
  puVar4[3] = 0xc74228;
  puVar4[0x10] = 0xc742e8;
  puVar4[2] = 0xc74210;
  puVar4[1] = 0xc741f8;
  *puVar4 = __nvoc_metadata__SyncpointMemory;
  iVar3 = __nvoc_ctor_Memory(puVar2,param_4,param_5);
  if (iVar3 == 0) {
    iVar3 = syncpointConstruct_IMPL(puVar4,param_4,param_5);
    if (iVar3 == 0) {
      *param_1 = (long)puVar4;
      return 0;
    }
    __nvoc_dtor_Memory(puVar2);
  }
  if (local_58 != 0) {
    objRemoveChild_IMPL(local_58,puVar1);
  }
  if ((param_3 & 2) == 0) {
    portMemFree(puVar4);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar4,0,0x220);
  }
  return iVar3;
}


// ===== 0019df50 __nvoc_objCreateDynamic_SyncpointMemory =====

void __nvoc_objCreateDynamic_SyncpointMemory
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  uVar2 = *param_4;
  if (uVar2 < 0x30) {
    uVar1 = uVar2 + 8;
    *param_4 = uVar1;
    uVar5 = *(undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar2);
    if (uVar1 < 0x30) {
      puVar4 = (undefined8 *)(*(long *)(param_4 + 4) + (ulong)uVar1);
      *param_4 = uVar2 + 0x10;
      goto LAB_0019df7e;
    }
    puVar4 = *(undefined8 **)(param_4 + 2);
  }
  else {
    puVar3 = *(undefined8 **)(param_4 + 2);
    puVar4 = puVar3 + 1;
    *(undefined8 **)(param_4 + 2) = puVar4;
    uVar5 = *puVar3;
  }
  *(undefined8 **)(param_4 + 2) = puVar4 + 1;
LAB_0019df7e:
  __nvoc_objCreate_SyncpointMemory(param_1,param_2,param_3,uVar5,*puVar4);
  return;
}


// ===== 0019dfb0 __nvoc_dtor_SysmemScrubber =====

void __nvoc_dtor_SysmemScrubber(long param_1)

{
  sysmemscrubDestruct_IMPL();
  __nvoc_dtor_Object(param_1 + 8);
  return;
}


// ===== 0019dfe0 __nvoc_objCreate_SysmemScrubber =====

int __nvoc_objCreate_SysmemScrubber(long *param_1,long param_2,uint param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 & 2) == 0) {
    puVar3 = (undefined8 *)portMemAllocNonPaged(0x90);
    if (puVar3 == (undefined8 *)0x0) {
      nvCheckFailedNoLog(4,"__nvoc_pThis != NULL","generated/g_sysmem_scrub_nvoc.c",0xac);
      return 0x51;
    }
  }
  else if ((param_1 == (long *)0x0) ||
          (puVar3 = (undefined8 *)*param_1, puVar3 == (undefined8 *)0x0)) {
    nvCheckFailedNoLog(4,"__nvoc_ppThis != NULL && *__nvoc_ppThis != NULL",
                       "generated/g_sysmem_scrub_nvoc.c",0xa4);
    return 0x3b;
  }
  portMemSet(puVar3,0,0x90);
  puVar1 = puVar3 + 1;
  *(uint *)((long)puVar3 + 0x34) = param_3;
  if ((param_2 == 0) || ((param_3 & 1) != 0)) {
    puVar3[3] = 0;
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc74658;
    *puVar3 = __nvoc_metadata__SysmemScrubber;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 != 0) goto LAB_0019e16f;
    lVar4 = 0;
LAB_0019e093:
    iVar2 = sysmemscrubConstruct_IMPL(puVar3,param_4);
    if (iVar2 == 0) {
      *param_1 = (long)puVar3;
      return 0;
    }
    __nvoc_dtor_Object(puVar1);
  }
  else {
    lVar4 = __nvoc_dynamicCast(param_2,__nvoc_class_def_Object);
    objAddChild_IMPL(lVar4,puVar1);
    puVar3[7] = puVar1;
    puVar3[8] = puVar3;
    __nvoc_init__Object(puVar1);
    puVar3[1] = 0xc74658;
    *puVar3 = __nvoc_metadata__SysmemScrubber;
    iVar2 = __nvoc_ctor_Object(puVar1);
    if (iVar2 == 0) goto LAB_0019e093;
  }
  if (lVar4 != 0) {
    objRemoveChild_IMPL(lVar4,puVar1);
  }
LAB_0019e16f:
  if ((param_3 & 2) == 0) {
    portMemFree(puVar3);
    *param_1 = 0;
  }
  else {
    portMemSet(puVar3,0,0x90);
  }
  return iVar2;
}


// ===== 0019e1f0 __nvoc_objCreateDynamic_SysmemScrubber =====

void __nvoc_objCreateDynamic_SysmemScrubber
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  undefined8 *puVar2;
  
  uVar1 = *param_4;
  if (uVar1 < 0x30) {
    *param_4 = uVar1 + 8;
    __nvoc_objCreate_SysmemScrubber
              (param_1,param_2,param_3,*(undefined8 *)((ulong)uVar1 + *(long *)(param_4 + 4)));
    return;
  }
  puVar2 = *(undefined8 **)(param_4 + 2);
  *(undefined8 **)(param_4 + 2) = puVar2 + 1;
  __nvoc_objCreate_SysmemScrubber(param_1,param_2,param_3,*puVar2);
  return;
}


// ===== 0019e230 resIsPartialUnmapSupported_d69453 =====

undefined8 resIsPartialUnmapSupported_d69453(void)

{
  return 0;
}


// ===== 0019e240 memCheckMemInterUnmap_ac1694 =====

undefined8 memCheckMemInterUnmap_ac1694(void)

{
  return 0;
}


// ===== 0019e250 memCheckCopyPermissions_ac1694 =====

undefined8 memCheckCopyPermissions_ac1694(void)

{
  return 0;
}


// ===== 0019e260 memIsGpuMapAllowed_e661f0 =====

undefined8 memIsGpuMapAllowed_e661f0(void)

{
  return 1;
}


// ===== 0019e270 memIsExportAllowed_e661f0 =====

undefined8 memIsExportAllowed_e661f0(void)

{
  return 1;
}


// ===== 0019e280 __nvoc_up_thunk_StandardMemory_sysmemCanCopy =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_StandardMemory_sysmemCanCopy(long param_1)

{
  (**(code **)(*(long *)(param_1 + 8) + 0x298))(param_1 + 8);
  return;
}


// ===== 0019e2a0 __nvoc_up_thunk_Memory_sysmemIsDuplicate =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemIsDuplicate(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b0))(param_1 + 0x10);
  return;
}


// ===== 0019e2c0 __nvoc_up_thunk_Memory_sysmemGetMapAddrSpace =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemGetMapAddrSpace(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1b8))(param_1 + 0x10);
  return;
}


// ===== 0019e2e0 __nvoc_up_thunk_Memory_sysmemControl =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemControl(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c0))(param_1 + 0x10);
  return;
}


// ===== 0019e300 __nvoc_up_thunk_Memory_sysmemMap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemMap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1c8))(param_1 + 0x10);
  return;
}


// ===== 0019e320 __nvoc_up_thunk_Memory_sysmemUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemUnmap(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d0))(param_1 + 0x10);
  return;
}


// ===== 0019e340 __nvoc_up_thunk_Memory_sysmemGetMemInterMapParams =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemGetMemInterMapParams(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1d8))(param_1 + 0x10);
  return;
}


// ===== 0019e360 __nvoc_up_thunk_Memory_sysmemCheckMemInterUnmap =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemCheckMemInterUnmap(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e0))(param_1 + 0x10,param_2);
  return;
}


// ===== 0019e380 __nvoc_up_thunk_Memory_sysmemGetMemoryMappingDescriptor =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemGetMemoryMappingDescriptor(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1e8))(param_1 + 0x10);
  return;
}


// ===== 0019e3a0 __nvoc_up_thunk_Memory_sysmemCheckCopyPermissions =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemCheckCopyPermissions(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1f0))(param_1 + 0x10);
  return;
}


// ===== 0019e3c0 __nvoc_up_thunk_Memory_sysmemIsReady =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemIsReady(long param_1,undefined1 param_2)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x1f8))(param_1 + 0x10,param_2);
  return;
}


// ===== 0019e3e0 __nvoc_up_thunk_Memory_sysmemIsGpuMapAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemIsGpuMapAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x200))(param_1 + 0x10);
  return;
}


// ===== 0019e400 __nvoc_up_thunk_Memory_sysmemIsExportAllowed =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_Memory_sysmemIsExportAllowed(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x10) + 0x208))(param_1 + 0x10);
  return;
}


// ===== 0019e420 __nvoc_up_thunk_RmResource_sysmemAccessCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_sysmemAccessCallback
               (long param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xf0))(param_1 + 0x18,param_2,param_3,param_4);
  return;
}


// ===== 0019e440 __nvoc_up_thunk_RmResource_sysmemShareCallback =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_sysmemShareCallback(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0xf8))(param_1 + 0x18);
  return;
}


// ===== 0019e460 __nvoc_up_thunk_RmResource_sysmemControlSerialization_Prologue =====

/* WARNING: Function: __x86_indirect_thunk_rax replaced with injection: x86_indirect_thunk_rax */

void __nvoc_up_thunk_RmResource_sysmemControlSerialization_Prologue(long param_1)

{
  (**(code **)(*(long *)(param_1 + 0x18) + 0x118))(param_1 + 0x18);
  return;
}


